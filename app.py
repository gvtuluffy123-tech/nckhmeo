import os
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import seaborn as sns
import streamlit as st
from sklearn.ensemble import RandomForestRegressor
from sklearn.metrics import mean_squared_error, r2_score
from sklearn.model_selection import train_test_split

# ------------------------------------------------------------------------------
# 1. CẤU HÌNH TRANG WEB APP
# ------------------------------------------------------------------------------
st.set_page_config(
    page_title="IoT Environmental Web Dashboard",
    layout="wide",
    initial_sidebar_state="expanded",
)

st.title("🌐 IoT Data Analysis & PM2.5 Prediction Dashboard")
st.write(
    "Bảng điều khiển trực quan hóa dữ liệu môi trường và dự đoán nồng độ bụi"
    " mịn PM2.5."
)

# ------------------------------------------------------------------------------
# 2. BƯỚC 1 & 2: NHẬP, LÀM SẠCH VÀ TIỀN XỬ LÝ DỮ LIỆU (SMOOTHING)
# ------------------------------------------------------------------------------
base_dir = os.path.dirname(os.path.abspath(__file__))
csv_path = os.path.join(base_dir, "data.csv")


@st.cache_data
def load_and_preprocess_data(path):
  if not os.path.exists(path):
    return None, None

  try:
    df_raw = pd.read_csv(path, sep=None, engine="python", encoding="utf-8-sig")
  except Exception:
    df_raw = pd.read_csv(path)

  # [BƯỚC 1] Chuẩn hóa tiêu đề & ánh xạ tên cột
  df_raw.columns = df_raw.columns.str.strip()
  if "field1" not in df_raw.columns:
    if "Unnamed: 2" in df_raw.columns:
      df_raw.rename(columns={"Unnamed: 2": "field1"}, inplace=True)
    elif len(df_raw.columns) >= 3:
      df_raw.rename(columns={df_raw.columns[2]: "field1"}, inplace=True)

  column_name_map = {
      "field1": "air_temperature",
      "field2": "humidity",
      "field3": "pm1_0",
      "field4": "CO2",
      "field5": "pm2_5",
      "field6": "pressure",
  }
  df_raw.rename(columns=column_name_map, inplace=True)

  if "created_at" in df_raw.columns:
    df_raw["created_at"] = pd.to_datetime(df_raw["created_at"])
    df_raw = df_raw.sort_values("created_at")

  features_all = [
      "air_temperature",
      "humidity",
      "pm1_0",
      "CO2",
      "pm2_5",
      "pressure",
  ]
  df_clean = df_raw.dropna(subset=features_all).copy()

  # [BƯỚC 2] Xử lý làm mượt dữ liệu (Moving Average window=25)
  df_processed = df_clean.copy()
  for col in features_all:
    df_processed[col] = (
        df_processed[col].rolling(window=25, min_periods=1, center=True).mean()
    )

  return df_clean, df_processed


df_raw, df_proc = load_and_preprocess_data(csv_path)

if df_raw is None:
  st.error(
      f"Không tìm thấy file `{csv_path}`. Vui lòng kiểm tra lại đường dẫn!"
  )
  st.stop()

# Hiển thị thông tin dữ liệu ở Sidebar
st.sidebar.header("⚙️ Thông Tin Dữ Liệu")
st.sidebar.success(f"Tổng số mẫu hợp lệ: **{len(df_raw)}**")

# Hiển thị số liệu tổng quan (Metrics) - Đủ 6 thông số
col_m1, col_m2, col_m3, col_m4, col_m5, col_m6 = st.columns(6)
col_m1.metric("Nhiệt độ", f"{df_raw['air_temperature'].mean():.1f} °C")
col_m2.metric("Độ ẩm", f"{df_raw['humidity'].mean():.1f} %")
col_m3.metric("PM1.0", f"{df_raw['pm1_0'].mean():.1f} µg/m³")
col_m4.metric("CO2", f"{df_raw['CO2'].mean():.0f} ppm")
col_m5.metric("PM2.5", f"{df_raw['pm2_5'].mean():.1f} µg/m³")
col_m6.metric("Áp suất", f"{df_raw['pressure'].mean():.0f} hPa")

st.divider()

# ------------------------------------------------------------------------------
# 3. BƯỚC 3: TRỰC QUAN HÓA VÀ SO SÁNH DỮ LIỆU THÔ VS ĐÃ XỬ LÝ
# ------------------------------------------------------------------------------
st.subheader("📊 Phân Tích & Biểu Đồ Phân Bố Dữ Liệu")

group_features = [
    "air_temperature",
    "humidity",
    "pm1_0",
    "CO2",
    "pressure",
    "pm2_5",
]

# Hàng 1: Ma trận tương quan 6 biến & Phân bố PM2.5
col_corr, col_hist = st.columns(2)

with col_corr:
  st.write("#### Ma Trận Tương Quan (6 Thống Số)")
  fig1, ax1 = plt.subplots(figsize=(6, 4.2))
  corr = df_raw[group_features].corr()
  sns.heatmap(
      corr, annot=True, fmt=".2f", cmap="coolwarm", vmin=-1, vmax=1, ax=ax1
  )
  ax1.set_title("Ma Tran Tuong Quan 6 Thong So")
  plt.tight_layout()
  st.pyplot(fig1)

with col_hist:
  st.write("#### Phân Bố Bụi Mịn PM2.5")
  fig2, ax2 = plt.subplots(figsize=(6, 4.2))
  sns.histplot(df_raw["pm2_5"], kde=True, color="purple", bins=30, ax=ax2)
  ax2.set_title("Phan Bo Bui Min PM2.5 (Tho)")
  ax2.set_xlabel("PM2.5 (ug/m3)")
  ax2.set_ylabel("So Luong Mau")
  ax2.grid(True, alpha=0.3)
  plt.tight_layout()
  st.pyplot(fig2)

# Hàng 2: Trực quan biểu đồ so sánh THÔ vs ĐÃ XỬ LÝ
st.write("#### 📈 So Sánh Dữ Liệu Thô (Raw) vs Đã Xử Lý (Processed)")
selected_feature = st.selectbox(
    "Chọn thông số muốn so sánh:",
    group_features,
    index=5,
    format_func=lambda x: {
        "air_temperature": "Nhiệt độ (°C)",
        "humidity": "Độ ẩm (%)",
        "pm1_0": "Bụi mịn PM1.0 (µg/m³)",
        "CO2": "Nồng độ CO2 (ppm)",
        "pressure": "Áp suất (hPa)",
        "pm2_5": "Bụi mịn PM2.5 (µg/m³)",
    }[x],
)

fig_comp, axes = plt.subplots(1, 2, figsize=(14, 4))
axes[0].plot(
    df_raw["created_at"],
    df_raw[selected_feature],
    color="coral",
    linewidth=1.0,
    marker="o",
    markersize=2,
)
axes[0].set_title(
    f"1. Dữ liệu THÔ (Raw): {selected_feature}",
    fontweight="bold",
    color="darkred",
)
axes[0].set_ylabel("Giá trị")
axes[0].grid(True, linestyle="--", alpha=0.5)

axes[1].plot(
    df_proc["created_at"],
    df_proc[selected_feature],
    color="darkgreen",
    linewidth=2.0,
)
axes[1].set_title(
    f"2. Dữ liệu ĐÃ XỬ LÝ (Processed): {selected_feature}",
    fontweight="bold",
    color="darkgreen",
)
axes[1].set_ylabel("Giá trị")
axes[1].grid(True, linestyle="--", alpha=0.5)

plt.tight_layout()
st.pyplot(fig_comp)

st.divider()

# ------------------------------------------------------------------------------
# 4. BƯỚC 4: HUẤN LUYỆN MÔ HÌNH RANDOM FOREST (5 ĐẦU VÀO) & DỰ ĐOÁN
# ------------------------------------------------------------------------------
st.subheader("🤖 Dự Đoán PM2.5 Trực Tiếp (Random Forest - 5 Đầu Vào)")

features_in = ["air_temperature", "humidity", "pm1_0", "CO2", "pressure"]
target_col = "pm2_5"

X = df_raw[features_in]
y = df_raw[target_col]

X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.2, random_state=42
)

model = RandomForestRegressor(n_estimators=10, max_depth=5, random_state=42)
model.fit(X_train, y_train)

y_pred = model.predict(X_test)
rmse = np.sqrt(mean_squared_error(y_test, y_pred))
r2 = r2_score(y_test, y_pred)

st.info(f"Đánh giá mô hình: **RMSE** = `{rmse:.2f}` | **R² Score** = `{r2:.4f}`")

# Nhập 5 tham số đầu vào để thử nghiệm
st.write("##### Thử nghiệm nhập thông số môi trường:")
col_in1, col_in2, col_in3, col_in4, col_in5 = st.columns(5)

temp_input = col_in1.number_input(
    "Nhiệt độ (°C)", value=float(df_raw["air_temperature"].mean())
)
hum_input = col_in2.number_input(
    "Độ ẩm (%)", value=float(df_raw["humidity"].mean())
)
pm1_input = col_in3.number_input(
    "PM1.0 (µg/m³)", value=float(df_raw["pm1_0"].mean())
)
co2_input = col_in4.number_input(
    "CO2 (ppm)", value=float(df_raw["CO2"].mean())
)
press_input = col_in5.number_input(
    "Áp suất (hPa)", value=float(df_raw["pressure"].mean())
)

if st.button("🔮 Dự đoán PM2.5"):
  input_data = np.array(
      [[temp_input, hum_input, pm1_input, co2_input, press_input]]
  )
  pred_val = model.predict(input_data)[0]
  st.success(f"Giá trị PM2.5 dự đoán: **{pred_val:.2f} µg/m³**")