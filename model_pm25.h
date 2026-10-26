/*
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

static float predict_tree_0(const float inputs[]) {
  if (inputs[2] <= 15.5000f) {
    if (inputs[2] <= 10.5000f) {
      if (inputs[2] <= 8.5000f) {
        if (inputs[2] <= 6.5000f) {
          if (inputs[3] <= 728.5000f) {
            return 18.0000f;
          } else {
            return 19.0000f;
          }
        } else {
          if (inputs[0] <= 30.5000f) {
            return 20.3200f;
          } else {
            return 19.4286f;
          }
        }
      } else {
        if (inputs[0] <= 30.5000f) {
          if (inputs[2] <= 9.5000f) {
            return 21.7206f;
          } else {
            return 22.7111f;
          }
        } else {
          if (inputs[3] <= 782.5000f) {
            return 20.9048f;
          } else {
            return 20.2857f;
          }
        }
      }
    } else {
      if (inputs[2] <= 13.5000f) {
        if (inputs[1] <= 74.5000f) {
          if (inputs[3] <= 759.5000f) {
            return 22.5263f;
          } else {
            return 23.9184f;
          }
        } else {
          if (inputs[3] <= 724.0000f) {
            return 24.6429f;
          } else {
            return 26.0000f;
          }
        }
      } else {
        if (inputs[3] <= 754.5000f) {
          if (inputs[0] <= 28.5000f) {
            return 26.8043f;
          } else {
            return 24.7500f;
          }
        } else {
          if (inputs[3] <= 790.0000f) {
            return 25.2581f;
          } else {
            return 23.7059f;
          }
        }
      }
    }
  } else {
    if (inputs[2] <= 18.5000f) {
      if (inputs[4] <= 1010.5000f) {
        if (inputs[1] <= 73.5000f) {
          if (inputs[3] <= 728.5000f) {
            return 27.0000f;
          } else {
            return 30.1515f;
          }
        } else {
          if (inputs[0] <= 28.5000f) {
            return 26.2222f;
          } else {
            return 28.3902f;
          }
        }
      } else {
        if (inputs[2] <= 17.5000f) {
          if (inputs[1] <= 73.0000f) {
            return 25.9710f;
          } else {
            return 27.1351f;
          }
        } else {
          if (inputs[1] <= 65.5000f) {
            return 25.0000f;
          } else {
            return 28.2778f;
          }
        }
      }
    } else {
      if (inputs[2] <= 22.5000f) {
        if (inputs[2] <= 20.5000f) {
          if (inputs[2] <= 19.5000f) {
            return 30.5033f;
          } else {
            return 31.3038f;
          }
        } else {
          if (inputs[1] <= 73.5000f) {
            return 32.5000f;
          } else {
            return 34.0000f;
          }
        }
      } else {
        if (inputs[2] <= 24.5000f) {
          if (inputs[1] <= 73.5000f) {
            return 36.3333f;
          } else {
            return 37.6471f;
          }
        } else {
          if (inputs[2] <= 26.5000f) {
            return 39.2000f;
          } else {
            return 43.0000f;
          }
        }
      }
    }
  }
}

static float predict_tree_1(const float inputs[]) {
  if (inputs[2] <= 16.5000f) {
    if (inputs[2] <= 10.5000f) {
      if (inputs[2] <= 8.5000f) {
        if (inputs[3] <= 821.5000f) {
          if (inputs[2] <= 7.5000f) {
            return 19.9783f;
          } else {
            return 20.5205f;
          }
        } else {
          if (inputs[3] <= 822.5000f) {
            return 17.0000f;
          } else {
            return 18.0000f;
          }
        }
      } else {
        if (inputs[0] <= 30.5000f) {
          if (inputs[2] <= 9.5000f) {
            return 21.5077f;
          } else {
            return 22.4000f;
          }
        } else {
          if (inputs[3] <= 748.0000f) {
            return 21.1000f;
          } else {
            return 20.1000f;
          }
        }
      }
    } else {
      if (inputs[2] <= 13.5000f) {
        if (inputs[3] <= 765.5000f) {
          if (inputs[3] <= 763.5000f) {
            return 24.0513f;
          } else {
            return 25.7143f;
          }
        } else {
          if (inputs[2] <= 11.5000f) {
            return 22.2727f;
          } else {
            return 23.9412f;
          }
        }
      } else {
        if (inputs[1] <= 69.0000f) {
          if (inputs[2] <= 15.5000f) {
            return 23.9630f;
          } else {
            return 25.5000f;
          }
        } else {
          if (inputs[1] <= 73.5000f) {
            return 26.9667f;
          } else {
            return 26.1463f;
          }
        }
      }
    }
  } else {
    if (inputs[2] <= 22.5000f) {
      if (inputs[2] <= 18.5000f) {
        if (inputs[4] <= 1010.5000f) {
          if (inputs[3] <= 728.5000f) {
            return 26.0714f;
          } else {
            return 29.6884f;
          }
        } else {
          if (inputs[2] <= 17.5000f) {
            return 26.4930f;
          } else {
            return 27.9851f;
          }
        }
      } else {
        if (inputs[2] <= 19.5000f) {
          if (inputs[1] <= 70.5000f) {
            return 29.0000f;
          } else {
            return 30.7312f;
          }
        } else {
          if (inputs[2] <= 20.5000f) {
            return 31.3161f;
          } else {
            return 32.2195f;
          }
        }
      }
    } else {
      if (inputs[2] <= 24.5000f) {
        if (inputs[3] <= 731.0000f) {
          return 35.0000f;
        } else {
          if (inputs[3] <= 739.5000f) {
            return 38.3571f;
          } else {
            return 36.6842f;
          }
        }
      } else {
        if (inputs[2] <= 26.5000f) {
          if (inputs[4] <= 1011.5000f) {
            return 39.7273f;
          } else {
            return 38.6667f;
          }
        } else {
          return 43.0000f;
        }
      }
    }
  }
}

static float predict_tree_2(const float inputs[]) {
  if (inputs[2] <= 16.5000f) {
    if (inputs[2] <= 10.5000f) {
      if (inputs[2] <= 8.5000f) {
        if (inputs[3] <= 680.5000f) {
          if (inputs[2] <= 7.5000f) {
            return 21.7500f;
          } else {
            return 21.8333f;
          }
        } else {
          if (inputs[2] <= 7.5000f) {
            return 19.7045f;
          } else {
            return 20.5422f;
          }
        }
      } else {
        if (inputs[2] <= 9.5000f) {
          if (inputs[0] <= 30.5000f) {
            return 21.4262f;
          } else {
            return 20.5455f;
          }
        } else {
          if (inputs[3] <= 807.0000f) {
            return 22.0000f;
          } else {
            return 25.0000f;
          }
        }
      }
    } else {
      if (inputs[2] <= 13.5000f) {
        if (inputs[2] <= 12.5000f) {
          if (inputs[3] <= 808.0000f) {
            return 23.6429f;
          } else {
            return 22.1250f;
          }
        } else {
          if (inputs[1] <= 65.0000f) {
            return 22.0000f;
          } else {
            return 24.7083f;
          }
        }
      } else {
        if (inputs[4] <= 1011.5000f) {
          if (inputs[1] <= 73.5000f) {
            return 28.5455f;
          } else {
            return 26.0000f;
          }
        } else {
          if (inputs[2] <= 15.5000f) {
            return 24.2188f;
          } else {
            return 25.8077f;
          }
        }
      }
    }
  } else {
    if (inputs[2] <= 22.5000f) {
      if (inputs[2] <= 18.5000f) {
        if (inputs[4] <= 1010.5000f) {
          if (inputs[1] <= 73.5000f) {
            return 29.9821f;
          } else {
            return 28.0698f;
          }
        } else {
          if (inputs[1] <= 65.5000f) {
            return 25.8889f;
          } else {
            return 27.7130f;
          }
        }
      } else {
        if (inputs[2] <= 19.5000f) {
          if (inputs[1] <= 69.5000f) {
            return 29.2500f;
          } else {
            return 30.8428f;
          }
        } else {
          if (inputs[1] <= 73.5000f) {
            return 31.5588f;
          } else {
            return 33.0000f;
          }
        }
      }
    } else {
      if (inputs[2] <= 24.5000f) {
        if (inputs[3] <= 732.5000f) {
          if (inputs[3] <= 730.5000f) {
            return 35.0000f;
          } else {
            return 34.0000f;
          }
        } else {
          if (inputs[3] <= 743.0000f) {
            return 38.2778f;
          } else {
            return 36.3636f;
          }
        }
      } else {
        if (inputs[3] <= 734.0000f) {
          if (inputs[3] <= 731.5000f) {
            return 39.6250f;
          } else {
            return 40.2500f;
          }
        } else {
          if (inputs[1] <= 73.5000f) {
            return 39.0000f;
          } else {
            return 38.6667f;
          }
        }
      }
    }
  }
}

static float predict_tree_3(const float inputs[]) {
  if (inputs[2] <= 16.5000f) {
    if (inputs[2] <= 12.5000f) {
      if (inputs[2] <= 9.5000f) {
        if (inputs[2] <= 8.5000f) {
          if (inputs[3] <= 821.5000f) {
            return 20.2109f;
          } else {
            return 17.3333f;
          }
        } else {
          if (inputs[0] <= 30.5000f) {
            return 21.5472f;
          } else {
            return 20.6667f;
          }
        }
      } else {
        if (inputs[0] <= 30.5000f) {
          if (inputs[3] <= 718.5000f) {
            return 22.1818f;
          } else {
            return 23.2532f;
          }
        } else {
          if (inputs[3] <= 745.5000f) {
            return 22.3333f;
          } else {
            return 20.6250f;
          }
        }
      }
    } else {
      if (inputs[1] <= 69.0000f) {
        if (inputs[2] <= 13.5000f) {
          if (inputs[1] <= 65.0000f) {
            return 22.0000f;
          } else {
            return 23.5714f;
          }
        } else {
          if (inputs[3] <= 789.5000f) {
            return 25.5000f;
          } else {
            return 24.2069f;
          }
        }
      } else {
        if (inputs[0] <= 28.5000f) {
          if (inputs[3] <= 760.0000f) {
            return 26.0098f;
          } else {
            return 24.8696f;
          }
        } else {
          if (inputs[3] <= 732.0000f) {
            return 31.0000f;
          } else {
            return 26.7843f;
          }
        }
      }
    }
  } else {
    if (inputs[2] <= 22.5000f) {
      if (inputs[2] <= 18.5000f) {
        if (inputs[4] <= 1010.5000f) {
          if (inputs[1] <= 73.5000f) {
            return 30.1800f;
          } else {
            return 27.8158f;
          }
        } else {
          if (inputs[2] <= 17.5000f) {
            return 26.6667f;
          } else {
            return 28.2941f;
          }
        }
      } else {
        if (inputs[2] <= 20.5000f) {
          if (inputs[4] <= 1011.5000f) {
            return 31.1577f;
          } else {
            return 29.9722f;
          }
        } else {
          if (inputs[1] <= 71.5000f) {
            return 31.7143f;
          } else {
            return 32.7742f;
          }
        }
      }
    } else {
      if (inputs[2] <= 24.5000f) {
        if (inputs[3] <= 732.5000f) {
          if (inputs[3] <= 730.5000f) {
            return 35.0000f;
          } else {
            return 34.0000f;
          }
        } else {
          if (inputs[3] <= 739.5000f) {
            return 37.4211f;
          } else {
            return 36.3125f;
          }
        }
      } else {
        if (inputs[3] <= 734.0000f) {
          if (inputs[3] <= 731.5000f) {
            return 39.6667f;
          } else {
            return 40.5000f;
          }
        } else {
          return 39.0000f;
        }
      }
    }
  }
}

static float predict_tree_4(const float inputs[]) {
  if (inputs[2] <= 16.5000f) {
    if (inputs[2] <= 10.5000f) {
      if (inputs[2] <= 8.5000f) {
        if (inputs[3] <= 818.5000f) {
          if (inputs[2] <= 7.5000f) {
            return 19.7719f;
          } else {
            return 20.5696f;
          }
        } else {
          if (inputs[3] <= 822.5000f) {
            return 17.0000f;
          } else {
            return 18.0000f;
          }
        }
      } else {
        if (inputs[2] <= 9.5000f) {
          if (inputs[3] <= 744.5000f) {
            return 21.1628f;
          } else {
            return 21.7241f;
          }
        } else {
          if (inputs[0] <= 30.5000f) {
            return 22.7188f;
          } else {
            return 20.0000f;
          }
        }
      }
    } else {
      if (inputs[2] <= 13.5000f) {
        if (inputs[1] <= 74.5000f) {
          if (inputs[1] <= 66.5000f) {
            return 24.1379f;
          } else {
            return 23.3095f;
          }
        } else {
          if (inputs[3] <= 718.0000f) {
            return 25.5000f;
          } else {
            return 24.4000f;
          }
        }
      } else {
        if (inputs[4] <= 1011.5000f) {
          if (inputs[3] <= 761.5000f) {
            return 26.6262f;
          } else {
            return 25.5366f;
          }
        } else {
          if (inputs[3] <= 789.5000f) {
            return 25.6296f;
          } else {
            return 24.1333f;
          }
        }
      }
    }
  } else {
    if (inputs[2] <= 22.5000f) {
      if (inputs[2] <= 18.5000f) {
        if (inputs[4] <= 1010.5000f) {
          if (inputs[3] <= 728.5000f) {
            return 26.5294f;
          } else {
            return 29.4846f;
          }
        } else {
          if (inputs[2] <= 17.5000f) {
            return 26.8333f;
          } else {
            return 27.6444f;
          }
        }
      } else {
        if (inputs[2] <= 19.5000f) {
          if (inputs[4] <= 1011.5000f) {
            return 30.8593f;
          } else {
            return 29.4118f;
          }
        } else {
          if (inputs[2] <= 20.5000f) {
            return 31.3373f;
          } else {
            return 32.2812f;
          }
        }
      }
    } else {
      if (inputs[3] <= 743.0000f) {
        if (inputs[3] <= 730.5000f) {
          return 35.0000f;
        } else {
          if (inputs[3] <= 733.5000f) {
            return 40.0000f;
          } else {
            return 38.3636f;
          }
        }
      } else {
        if (inputs[2] <= 24.5000f) {
          if (inputs[3] <= 763.5000f) {
            return 36.5455f;
          } else {
            return 36.0000f;
          }
        } else {
          return 38.0000f;
        }
      }
    }
  }
}

static float predict_tree_5(const float inputs[]) {
  if (inputs[2] <= 16.5000f) {
    if (inputs[2] <= 11.5000f) {
      if (inputs[2] <= 9.5000f) {
        if (inputs[2] <= 8.5000f) {
          if (inputs[3] <= 821.5000f) {
            return 20.3739f;
          } else {
            return 17.6000f;
          }
        } else {
          if (inputs[1] <= 74.5000f) {
            return 21.2121f;
          } else {
            return 22.2500f;
          }
        }
      } else {
        if (inputs[2] <= 10.5000f) {
          if (inputs[3] <= 809.5000f) {
            return 21.9074f;
          } else {
            return 24.5000f;
          }
        } else {
          if (inputs[3] <= 718.5000f) {
            return 21.4286f;
          } else {
            return 23.5714f;
          }
        }
      }
    } else {
      if (inputs[2] <= 13.5000f) {
        if (inputs[1] <= 65.0000f) {
          if (inputs[3] <= 741.0000f) {
            return 23.5000f;
          } else {
            return 22.0000f;
          }
        } else {
          if (inputs[3] <= 806.0000f) {
            return 24.8537f;
          } else {
            return 23.0000f;
          }
        }
      } else {
        if (inputs[4] <= 1011.5000f) {
          if (inputs[1] <= 73.5000f) {
            return 28.1429f;
          } else {
            return 26.0611f;
          }
        } else {
          if (inputs[3] <= 787.5000f) {
            return 25.6977f;
          } else {
            return 23.9474f;
          }
        }
      }
    }
  } else {
    if (inputs[2] <= 22.5000f) {
      if (inputs[2] <= 18.5000f) {
        if (inputs[4] <= 1010.5000f) {
          if (inputs[3] <= 728.5000f) {
            return 26.5000f;
          } else {
            return 29.7103f;
          }
        } else {
          if (inputs[2] <= 17.5000f) {
            return 26.6351f;
          } else {
            return 28.1136f;
          }
        }
      } else {
        if (inputs[2] <= 20.5000f) {
          if (inputs[4] <= 1011.5000f) {
            return 31.2787f;
          } else {
            return 30.1951f;
          }
        } else {
          if (inputs[1] <= 73.5000f) {
            return 32.2727f;
          } else {
            return 34.0000f;
          }
        }
      }
    } else {
      if (inputs[2] <= 24.5000f) {
        if (inputs[3] <= 731.5000f) {
          if (inputs[3] <= 730.5000f) {
            return 35.0000f;
          } else {
            return 34.0000f;
          }
        } else {
          if (inputs[1] <= 73.5000f) {
            return 36.2400f;
          } else {
            return 37.6842f;
          }
        }
      } else {
        if (inputs[3] <= 732.5000f) {
          if (inputs[2] <= 25.5000f) {
            return 39.0000f;
          } else {
            return 39.4000f;
          }
        } else {
          if (inputs[1] <= 73.5000f) {
            return 39.0000f;
          } else {
            return 40.6667f;
          }
        }
      }
    }
  }
}

static float predict_tree_6(const float inputs[]) {
  if (inputs[2] <= 16.5000f) {
    if (inputs[2] <= 11.5000f) {
      if (inputs[2] <= 8.5000f) {
        if (inputs[3] <= 818.5000f) {
          if (inputs[2] <= 7.5000f) {
            return 20.0652f;
          } else {
            return 20.6951f;
          }
        } else {
          if (inputs[3] <= 822.5000f) {
            return 17.0000f;
          } else {
            return 18.0000f;
          }
        }
      } else {
        if (inputs[2] <= 10.5000f) {
          if (inputs[3] <= 807.0000f) {
            return 21.5372f;
          } else {
            return 25.0000f;
          }
        } else {
          if (inputs[1] <= 74.5000f) {
            return 22.9130f;
          } else {
            return 24.0000f;
          }
        }
      }
    } else {
      if (inputs[4] <= 1011.5000f) {
        if (inputs[2] <= 13.5000f) {
          if (inputs[2] <= 12.5000f) {
            return 23.5000f;
          } else {
            return 24.8824f;
          }
        } else {
          if (inputs[1] <= 73.5000f) {
            return 28.2000f;
          } else {
            return 26.2314f;
          }
        }
      } else {
        if (inputs[2] <= 15.5000f) {
          if (inputs[1] <= 65.0000f) {
            return 22.8667f;
          } else {
            return 24.3125f;
          }
        } else {
          if (inputs[1] <= 66.5000f) {
            return 26.5000f;
          } else {
            return 25.1429f;
          }
        }
      }
    }
  } else {
    if (inputs[2] <= 22.5000f) {
      if (inputs[2] <= 18.5000f) {
        if (inputs[4] <= 1010.5000f) {
          if (inputs[1] <= 73.5000f) {
            return 30.1837f;
          } else {
            return 27.8947f;
          }
        } else {
          if (inputs[2] <= 17.5000f) {
            return 26.5192f;
          } else {
            return 28.3636f;
          }
        }
      } else {
        if (inputs[2] <= 20.5000f) {
          if (inputs[2] <= 19.5000f) {
            return 30.6667f;
          } else {
            return 31.2907f;
          }
        } else {
          if (inputs[1] <= 73.5000f) {
            return 32.3750f;
          } else {
            return 34.0000f;
          }
        }
      }
    } else {
      if (inputs[2] <= 24.5000f) {
        if (inputs[3] <= 731.5000f) {
          if (inputs[3] <= 730.5000f) {
            return 35.0000f;
          } else {
            return 34.0000f;
          }
        } else {
          if (inputs[3] <= 742.0000f) {
            return 38.1304f;
          } else {
            return 36.5455f;
          }
        }
      } else {
        if (inputs[2] <= 26.5000f) {
          if (inputs[4] <= 1011.5000f) {
            return 39.8750f;
          } else {
            return 38.5000f;
          }
        } else {
          return 43.0000f;
        }
      }
    }
  }
}

static float predict_tree_7(const float inputs[]) {
  if (inputs[2] <= 16.5000f) {
    if (inputs[2] <= 11.5000f) {
      if (inputs[2] <= 9.5000f) {
        if (inputs[2] <= 8.5000f) {
          if (inputs[3] <= 811.0000f) {
            return 20.2951f;
          } else {
            return 18.0000f;
          }
        } else {
          if (inputs[0] <= 30.5000f) {
            return 21.4583f;
          } else {
            return 20.5333f;
          }
        }
      } else {
        if (inputs[3] <= 718.5000f) {
          if (inputs[1] <= 74.5000f) {
            return 21.0000f;
          } else {
            return 22.5000f;
          }
        } else {
          if (inputs[2] <= 10.5000f) {
            return 22.2500f;
          } else {
            return 23.1220f;
          }
        }
      }
    } else {
      if (inputs[1] <= 69.0000f) {
        if (inputs[2] <= 15.5000f) {
          if (inputs[3] <= 791.5000f) {
            return 24.5000f;
          } else {
            return 23.2857f;
          }
        } else {
          if (inputs[3] <= 733.5000f) {
            return 24.4286f;
          } else {
            return 26.1667f;
          }
        }
      } else {
        if (inputs[2] <= 13.5000f) {
          if (inputs[1] <= 72.0000f) {
            return 26.0000f;
          } else {
            return 24.6000f;
          }
        } else {
          if (inputs[3] <= 760.5000f) {
            return 26.6121f;
          } else {
            return 25.7708f;
          }
        }
      }
    }
  } else {
    if (inputs[2] <= 22.5000f) {
      if (inputs[2] <= 18.5000f) {
        if (inputs[4] <= 1010.5000f) {
          if (inputs[1] <= 73.5000f) {
            return 30.0991f;
          } else {
            return 28.0444f;
          }
        } else {
          if (inputs[1] <= 65.5000f) {
            return 25.6154f;
          } else {
            return 27.3304f;
          }
        }
      } else {
        if (inputs[2] <= 20.5000f) {
          if (inputs[4] <= 1011.5000f) {
            return 31.3008f;
          } else {
            return 30.2326f;
          }
        } else {
          if (inputs[1] <= 73.5000f) {
            return 32.2059f;
          } else {
            return 34.0000f;
          }
        }
      }
    } else {
      if (inputs[2] <= 24.5000f) {
        if (inputs[3] <= 731.5000f) {
          if (inputs[3] <= 730.5000f) {
            return 35.0000f;
          } else {
            return 34.0000f;
          }
        } else {
          if (inputs[3] <= 743.0000f) {
            return 38.3043f;
          } else {
            return 36.2667f;
          }
        }
      } else {
        if (inputs[2] <= 26.5000f) {
          if (inputs[2] <= 25.5000f) {
            return 39.5714f;
          } else {
            return 39.8750f;
          }
        } else {
          return 43.0000f;
        }
      }
    }
  }
}

static float predict_tree_8(const float inputs[]) {
  if (inputs[2] <= 16.5000f) {
    if (inputs[2] <= 11.5000f) {
      if (inputs[2] <= 9.5000f) {
        if (inputs[2] <= 8.5000f) {
          if (inputs[0] <= 30.5000f) {
            return 20.3964f;
          } else {
            return 19.2857f;
          }
        } else {
          if (inputs[0] <= 30.5000f) {
            return 21.5510f;
          } else {
            return 20.4375f;
          }
        }
      } else {
        if (inputs[3] <= 758.5000f) {
          if (inputs[1] <= 74.5000f) {
            return 21.4348f;
          } else {
            return 22.9000f;
          }
        } else {
          if (inputs[0] <= 30.5000f) {
            return 23.3846f;
          } else {
            return 20.6000f;
          }
        }
      }
    } else {
      if (inputs[2] <= 15.5000f) {
        if (inputs[1] <= 69.0000f) {
          if (inputs[3] <= 770.0000f) {
            return 23.0000f;
          } else {
            return 24.1961f;
          }
        } else {
          if (inputs[1] <= 74.5000f) {
            return 25.0517f;
          } else {
            return 25.8868f;
          }
        }
      } else {
        if (inputs[1] <= 71.5000f) {
          if (inputs[3] <= 746.0000f) {
            return 24.8000f;
          } else {
            return 26.1579f;
          }
        } else {
          if (inputs[1] <= 73.5000f) {
            return 28.3000f;
          } else {
            return 26.4038f;
          }
        }
      }
    }
  } else {
    if (inputs[2] <= 22.5000f) {
      if (inputs[2] <= 18.5000f) {
        if (inputs[4] <= 1010.5000f) {
          if (inputs[1] <= 73.5000f) {
            return 30.0541f;
          } else {
            return 27.8636f;
          }
        } else {
          if (inputs[3] <= 731.0000f) {
            return 25.1667f;
          } else {
            return 27.3784f;
          }
        }
      } else {
        if (inputs[2] <= 20.5000f) {
          if (inputs[4] <= 1011.5000f) {
            return 31.1226f;
          } else {
            return 30.2222f;
          }
        } else {
          if (inputs[1] <= 70.5000f) {
            return 31.1667f;
          } else {
            return 32.5667f;
          }
        }
      }
    } else {
      if (inputs[2] <= 23.5000f) {
        if (inputs[3] <= 731.5000f) {
          if (inputs[3] <= 730.5000f) {
            return 35.0000f;
          } else {
            return 34.0000f;
          }
        } else {
          if (inputs[4] <= 1011.5000f) {
            return 38.2500f;
          } else {
            return 36.6667f;
          }
        }
      } else {
        if (inputs[3] <= 733.0000f) {
          if (inputs[3] <= 731.5000f) {
            return 39.3333f;
          } else {
            return 40.5000f;
          }
        } else {
          if (inputs[3] <= 734.5000f) {
            return 37.0000f;
          } else {
            return 38.0667f;
          }
        }
      }
    }
  }
}

static float predict_tree_9(const float inputs[]) {
  if (inputs[2] <= 16.5000f) {
    if (inputs[2] <= 10.5000f) {
      if (inputs[2] <= 8.5000f) {
        if (inputs[2] <= 7.5000f) {
          if (inputs[3] <= 819.0000f) {
            return 19.6667f;
          } else {
            return 18.0000f;
          }
        } else {
          if (inputs[3] <= 698.5000f) {
            return 20.0400f;
          } else {
            return 20.7292f;
          }
        }
      } else {
        if (inputs[0] <= 30.5000f) {
          if (inputs[3] <= 762.0000f) {
            return 21.5135f;
          } else {
            return 22.4091f;
          }
        } else {
          if (inputs[3] <= 781.0000f) {
            return 21.2778f;
          } else {
            return 20.2500f;
          }
        }
      }
    } else {
      if (inputs[2] <= 13.5000f) {
        if (inputs[1] <= 74.5000f) {
          if (inputs[3] <= 758.0000f) {
            return 22.5882f;
          } else {
            return 23.7660f;
          }
        } else {
          if (inputs[3] <= 716.0000f) {
            return 25.0000f;
          } else {
            return 24.2222f;
          }
        }
      } else {
        if (inputs[1] <= 69.0000f) {
          if (inputs[3] <= 787.5000f) {
            return 25.2381f;
          } else {
            return 23.8966f;
          }
        } else {
          if (inputs[0] <= 28.5000f) {
            return 25.9706f;
          } else {
            return 26.5952f;
          }
        }
      }
    }
  } else {
    if (inputs[2] <= 22.5000f) {
      if (inputs[2] <= 18.5000f) {
        if (inputs[4] <= 1010.5000f) {
          if (inputs[0] <= 28.5000f) {
            return 26.0000f;
          } else {
            return 29.8451f;
          }
        } else {
          if (inputs[1] <= 68.5000f) {
            return 25.9048f;
          } else {
            return 27.4800f;
          }
        }
      } else {
        if (inputs[2] <= 20.5000f) {
          if (inputs[1] <= 71.5000f) {
            return 30.4714f;
          } else {
            return 31.2146f;
          }
        } else {
          if (inputs[1] <= 73.5000f) {
            return 32.2105f;
          } else {
            return 34.0000f;
          }
        }
      }
    } else {
      if (inputs[3] <= 736.0000f) {
        if (inputs[3] <= 730.5000f) {
          return 35.0000f;
        } else {
          if (inputs[3] <= 733.5000f) {
            return 39.8824f;
          } else {
            return 38.2857f;
          }
        }
      } else {
        if (inputs[2] <= 24.5000f) {
          if (inputs[1] <= 73.5000f) {
            return 36.1818f;
          } else {
            return 37.3750f;
          }
        } else {
          if (inputs[3] <= 755.5000f) {
            return 39.0000f;
          } else {
            return 38.0000f;
          }
        }
      }
    }
  }
}

static inline float predict_pm25(const float inputs[]) {
    float sum = 0.0f;
    sum += predict_tree_0(inputs);
    sum += predict_tree_1(inputs);
    sum += predict_tree_2(inputs);
    sum += predict_tree_3(inputs);
    sum += predict_tree_4(inputs);
    sum += predict_tree_5(inputs);
    sum += predict_tree_6(inputs);
    sum += predict_tree_7(inputs);
    sum += predict_tree_8(inputs);
    sum += predict_tree_9(inputs);
    return sum / 10.0f;
}

#ifdef __cplusplus
}
#endif

#endif // MODEL_PM25_H
