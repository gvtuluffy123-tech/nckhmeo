import os
import matplotlib.dates as mdates
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
from sklearn.ensemble import RandomForestRegressor
from sklearn.metrics import mean_squared_error, r2_score
from sklearn.model_selection import train_test_split

# ==============================================================================
# BUOC 1: NHAP VA CHUAN HOA DU LIEU
# ==============================================================================
print("--- [BUOC 1] NHAP VA LAM SACH DU LIEU ---")

base_dir = os.path.dirname(os.path.abspath(__file__))
csv_path = os.path.join(base_dir, "data.csv")

try:
  df_raw = pd.read_csv(csv_path, sep=None, engine="python", encoding="utf-8-sig")
except Exception:
  df_raw = pd.read_csv(csv_path)

df_raw.columns = df_raw.columns.str.strip()

# Khac phuc neu thieu cot field1
if "field1" not in df_raw.columns:
  if "Unnamed: 2" in df_raw.columns:
    df_raw.rename(columns={"Unnamed: 2": "field1"}, inplace=True)
  elif len(df_raw.columns) >= 3:
    df_raw.rename(columns={df_raw.columns[2]: "field1"}, inplace=True)

column_name_map = {
    "field1": "air_temperature",  # Nhiet do (oC)
    "field2": "humidity",  # Do am (%)
    "field3": "pm1_0",  # Bui min PM1.0 (ug/m3)
    "field4": "CO2",  # Nong do CO2 (ppm)
    "field5": "pm2_5",  # Bui min PM2.5 (ug/m3)
    "field6": "pressure",  # Ap suat (hPa)
}
df_raw.rename(columns=column_name_map, inplace=True)

df_raw["created_at"] = pd.to_datetime(df_raw["created_at"])
df_raw = df_raw.sort_values("created_at")

features_in = ["air_temperature", "humidity", "pm1_0", "CO2", "pressure"]
target_col = "pm2_5"
group_features = features_in + [target_col]

df = df_raw.dropna(subset=group_features).copy()
print(f"-> Hoan thanh Buoc 1: Co {len(df)} dong du lieu hop le.")

# ==============================================================================
# BUOC 2: XU LY LAM MUOT DU LIEU (MOVING AVERAGE)
# ==============================================================================
print("\n--- [BUOC 2] XU LY LAM MUOT DU LIEU ---")

df_processed = df.copy()
for col in group_features:
  df_processed[col] = (
      df_processed[col].rolling(window=25, min_periods=1, center=True).mean()
  )

print("-> Hoan thanh Buoc 2: Da xu ly muot du lieu (Window=25).")

# ==============================================================================
# BUOC 3: VE BIEU DO SO SANH SONG DOI (RAW VS PROCESSED)
# ==============================================================================
print("\n--- [BUOC 3] VE BIEU DO SO SANH DU LIEU THO VS DA XU LY ---")

info_dict = {
    "air_temperature": ("Nhiet do khong khi (field1)", "oC", "coral", "red"),
    "humidity": ("Do am (field2)", "%", "lightskyblue", "blue"),
    "pm1_0": ("Bui min PM1.0 (field3)", "ug/m3", "thistle", "purple"),
    "CO2": ("Nong do CO2 (field4)", "ppm", "lightgreen", "darkgreen"),
    "pm2_5": ("Bui min PM2.5 (field5)", "ug/m3", "salmon", "darkred"),
    "pressure": ("Ap suat khi quyen (field6)", "hPa", "wheat", "darkorange"),
}

for col in group_features:
  title, unit, color_raw, color_proc = info_dict[col]
  fig, axes = plt.subplots(1, 2, figsize=(14, 4.5))

  # 1. Bieu do BEN TRAI: Du lieu THO (Raw)
  axes[0].plot(
      df["created_at"],
      df[col],
      color=color_raw,
      linewidth=1.0,
      marker="o",
      markersize=2,
  )
  axes[0].set_title(
      f"1. Du lieu THO (Raw): {title}",
      fontsize=11,
      fontweight="bold",
      color="darkred",
  )
  axes[0].set_ylabel(f"Gia tri ({unit})", fontsize=9)
  axes[0].grid(True, linestyle="--", alpha=0.5)

  # 2. Bieu do BEN PHAI: Du lieu DA XU LY (Processed)
  axes[1].plot(
      df_processed["created_at"], df_processed[col], color=color_proc, linewidth=2.0
  )
  axes[1].set_title(
      f"2. Du lieu DA XU LY (Processed): {title}",
      fontsize=11,
      fontweight="bold",
      color="darkgreen",
  )
  axes[1].set_ylabel(f"Gia tri ({unit})", fontsize=9)
  axes[1].grid(True, linestyle="--", alpha=0.5)

  # Dinh dang truc X: Gio/Phut tren, Ngay/Thang duoi, chia vach 1h/lan
  for ax in axes:
    ax.xaxis.set_major_formatter(mdates.DateFormatter("%H:%M\n%d/%m"))
    ax.xaxis.set_major_locator(mdates.HourLocator(interval=1))
    ax.tick_params(axis="x", labelsize=9)

  plt.tight_layout()
  filename = f"compare_{col}.png"
  plt.savefig(filename, dpi=300)
  plt.close()

print("-> Hoan thanh Buoc 3: Da xuat xong 6 file anh so sanh!")

# ==============================================================================
# BUOC 4: HUAN LUYEN MO HINH RANDOM FOREST VA XUAT CODE C/C++ MODEL_PM25.H
# ==============================================================================
print("\n--- [BUOC 4] HUAN LUYEN MO HINH VA XUAT CODE C/C++ ---")

X = df[features_in]
y = df[target_col]

X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.2, random_state=42
)
model = RandomForestRegressor(n_estimators=10, max_depth=5, random_state=42)
model.fit(X_train, y_train)

y_pred = model.predict(X_test)
rmse = np.sqrt(mean_squared_error(y_test, y_pred))
r2 = r2_score(y_test, y_pred)
print(f"-> Danh gia mo hinh: RMSE = {rmse:.2f}, R2 Score = {r2:.4f}")


def tree_to_c(tree, feature_names):
  tree_ = tree.tree_
  feature_name = [
      feature_names[i] if i >= 0 else "undefined!" for i in tree_.feature
  ]

  def recurse(node, depth):
    indent = "  " * depth
    if tree_.feature[node] != -2:
      name = feature_name[node]
      threshold = tree_.threshold[node]
      code = (
          f"{indent}if (inputs[{features_in.index(name)}] <="
          f" {threshold:.4f}f) {{\n"
      )
      code += recurse(tree_.children_left[node], depth + 1)
      code += f"{indent}}} else {{\n"
      code += recurse(tree_.children_right[node], depth + 1)
      code += f"{indent}}}\n"
      return code
    else:
      return f"{indent}return {tree_.value[node][0][0]:.4f}f;\n"

  return recurse(0, 1)


c_header = """/*
 * Generated C Model for PM2.5 Prediction (Random Forest)
 * Inputs Order (5 features):
 * [0] air_temperature (Nhiet do - oC)
 * [1] humidity (Do am - %)
 * [2] pm1_0 (Bui min PM1.0 - ug/m3)
 * [3] CO2 (Nong do CO2 - ppm)
 * [4] pressure (Ap suat - hPa)
 */

#ifndef MODEL_PM25_H
#define MODEL_PM25_H

#ifdef __cplusplus
extern "C" {
#endif

"""

for i, tree in enumerate(model.estimators_):
  c_header += f"static float predict_tree_{i}(const float inputs[]) {{\n"
  c_header += tree_to_c(tree, features_in)
  c_header += "}\n\n"

c_header += "static inline float predict_pm25(const float inputs[]) {\n"
c_header += "    float sum = 0.0f;\n"
for i in range(len(model.estimators_)):
  c_header += f"    sum += predict_tree_{i}(inputs);\n"
c_header += f"    return sum / {len(model.estimators_)}.0f;\n"
c_header += "}\n\n"
c_header += """#ifdef __cplusplus
}
#endif

#endif // MODEL_PM25_H
"""

with open("model_pm25.h", "w", encoding="utf-8") as f:
  f.write(c_header)

print("-> Hoan thanh Buoc 4: Da xuat xong file model_pm25.h!")