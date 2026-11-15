#ifndef __INCLUDE_CONSTANTS_COLLISION_MAP_H__
#define __INCLUDE_CONSTANTS_COLLISION_MAP_H__

// Collision map file IDs (prefix の HP_ は CollisionMapFile の magic が HP だったので)
#define HP_050F BOKHASH("st00_00_hpk")         // 0x050F, 渓谷
#define HP_051F BOKHASH("st00_01_hpk")         // 0x051F, 渓谷, "st02_00_hpk" とハッシュが衝突するが、利用箇所を確かめたところ、渓谷("st00")だったのでこれで正しいと思われる
#define HP_052F BOKHASH("st00_02_hpk")         // 0x052F, 渓谷, "st04_00_hpk" 〃
#define HP_053F BOKHASH("st00_03_hpk")         // 0x053F, 街門, 変異域が "st06_00_hpk" でなく "st06_enter_hpk" なのはこれとハッシュが衝突しているから
#define HP_054F BOKHASH("st00_04_hpk")         // 0x054F
#define HP_072C BOKHASH("random_room_hpk")     // 0x072C
#define HP_082E BOKHASH("st02_10_desert_hpk")  // 0x082E, 遺跡
#define HP_08AE BOKHASH("st02_11_desert_hpk")  // 0x08AE, 遺跡
#define HP_092E BOKHASH("st02_12_desert_hpk")  // 0x092E, 遺跡
#define HP_09AE BOKHASH("st02_13_desert_hpk")  // 0x09AE, 遺跡
#define HP_0A2E BOKHASH("st02_14_desert_hpk")  // 0x0A2E, 遺跡
#define HP_0AAE BOKHASH("st02_15_desert_hpk")  // 0x0AAE, 遺跡
#define HP_0BAE BOKHASH("st02_17_desert_hpk")  // 0x0BAE, 遺跡
#define HP_0C2E BOKHASH("st02_18_desert_hpk")  // 0x0C2E, 遺跡
#define HP_0CAE BOKHASH("st02_19_desert_hpk")  // 0x0CAE, 遺跡
#define HP_0F0C BOKHASH("random_boss_hpk")     // 0x0F0C
#define HP_0F63 BOKHASH("b00_04_town_hpk")     // 0x0F63, サンミゲル
#define HP_11B6 BOKHASH("f00_hpk")             // 0x11B6, 6番街
#define HP_11C6 BOKHASH("f01_hpk")             // 0x11C6, 10番街
#define HP_11D6 BOKHASH("f02_hpk")             // 0x11D6, 4番街
#define HP_11E6 BOKHASH("f03_hpk")             // 0x11E6, 2番街
#define HP_11F6 BOKHASH("f04_hpk")             // 0x11F6, 8番街
#define HP_1206 BOKHASH("f05_hpk")             // 0x1206, 12番街
#define HP_1313 BOKHASH("st04_02_lake_hpk")    // 0x1313, 地下水路
#define HP_164C 0x164C
#define HP_17CE BOKHASH("st03_04_slum_hpk")    // 0x17CE, 暗黒街
#define HP_17D2 BOKHASH("st03_14_slum_hpk")    // 0x17D2, 暗黒街
#define HP_17D6 BOKHASH("st03_24_slum_hpk")    // 0x17D6, "暗黒街B [4F]"
#define HP_182E BOKHASH("st02_20_desert_hpk")  // 0x182E, 遺跡
#define HP_1A97 BOKHASH("a30_01_time_hpk")     // 0x1A97, 時の家
#define HP_2EF8 BOKHASH("st06_last_00_hpk")    // 0x2EF8
#define HP_2F08 BOKHASH("st06_last_01_hpk")    // 0x2F08
#define HP_2F18 BOKHASH("st06_last_02_hpk")    // 0x2F18
#define HP_2F28 BOKHASH("st06_last_03_hpk")    // 0x2F28
#define HP_2F38 BOKHASH("st06_last_04_hpk")    // 0x2F38
#define HP_2F48 BOKHASH("st06_last_05_hpk")    // 0x2F48
#define HP_2F58 BOKHASH("st06_last_06_hpk")    // 0x2F58
#define HP_2F63 BOKHASH("b00_05_town_hpk")     // 0x2F63, サンミゲル
#define HP_2F68 BOKHASH("st06_last_07_hpk")    // 0x2F68
#define HP_3313 BOKHASH("st04_03_lake_hpk")    // 0x3313, 地下水路
#define HP_33C2 0x33C2
#define HP_33D2 0x33D2
#define HP_33E2 0x33E2
#define HP_33F2 0x33F2
#define HP_3402 0x3402
#define HP_3412 0x3412
#define HP_3422 0x3422
#define HP_3432 0x3432
#define HP_3442 0x3442
#define HP_3452 0x3452
#define HP_35C2 0x35C2
#define HP_35D2 0x35D2
#define HP_35E2 0x35E2
#define HP_37CE BOKHASH("st03_05_slum_hpk")   // 0x37CE, 暗黒街
#define HP_37D2 BOKHASH("st03_15_slum_hpk")   // 0x37D2, 暗黒街
#define HP_37D6 BOKHASH("st03_25_slum_hpk")   // 0x37D6, 暗黒街
#define HP_3A97 BOKHASH("a30_02_time_hpk")    // 0x3A97, 時の家
#define HP_3D33 BOKHASH("a10_00_forest_hpk")  // 0x3D33, 森
#define HP_3DB3 BOKHASH("a10_01_forest_hpk")  // 0x3DB3, 森
#define HP_3E33 BOKHASH("a10_02_forest_hpk")  // 0x3E33, 森
#define HP_3EB3 BOKHASH("a10_03_forest_hpk")  // 0x3EB3, 森
#define HP_3F33 BOKHASH("a10_04_forest_hpk")  // 0x3F33, 森
#define HP_3FB3 BOKHASH("a10_05_forest_hpk")  // 0x3FB3, 森
#define HP_4033 BOKHASH("a10_06_forest_hpk")  // 0x4033, 森
#define HP_40B3 BOKHASH("a10_07_forest_hpk")  // 0x40B3, 森
#define HP_4133 BOKHASH("a10_08_forest_hpk")  // 0x4133, 森
#define HP_41B3 BOKHASH("a10_09_forest_hpk")  // 0x41B3, 森
#define HP_43B7 0x43B7
#define HP_4D33 BOKHASH("a10_10_forest_hpk")  // 0x4D33, 森
#define HP_4DB3 BOKHASH("a10_11_forest_hpk")  // 0x4DB3, 森
#define HP_4E33 BOKHASH("a10_12_forest_hpk")  // 0x4E33, 森
#define HP_4EB3 BOKHASH("a10_13_forest_hpk")  // 0x4EB3, 森
#define HP_4F33 BOKHASH("a10_14_forest_hpk")  // 0x4F33, 森
#define HP_5313 BOKHASH("st04_04_lake_hpk")   // 0x5313, 地下水路
#define HP_57CE BOKHASH("st03_06_slum_hpk")   // 0x57CE, 暗黒街
#define HP_57D2 BOKHASH("st03_16_slum_hpk")   // 0x57D2, 暗黒街
#define HP_57D6 BOKHASH("st03_26_slum_hpk")   // 0x57D6, 暗黒街
#define HP_5A97 BOKHASH("a30_03_time_hpk")    // 0x5A97, 時の家
#define HP_5F34 0x5F34
#define HP_677F BOKHASH("st03_19_veranda_slum_hpk")  // 0x677F, 暗黒街, st03_19 のベランダ
#define HP_6A7F BOKHASH("st03_21_veranda_slum_hpk")  // 0x6A7F, 暗黒街, st03_21 のベランダ
#define HP_6AB0 BOKHASH("random_enter_hpk")          // 0x6AB0
#define HP_77CE BOKHASH("st03_07_slum_hpk")          // 0x77CE, 暗黒街
#define HP_77D2 BOKHASH("st03_17_slum_hpk")          // 0x77D2, 暗黒街
#define HP_77D6 BOKHASH("st03_27_slum_hpk")          // 0x77D6, 暗黒街
#define HP_78F6 BOKHASH("st01_00_cathed_hpk")        // 0x78F6, 大聖堂
#define HP_7976 BOKHASH("st01_01_cathed_hpk")        // 0x7976, 大聖堂
#define HP_79F6 BOKHASH("st01_02_cathed_hpk")        // 0x79F6, 大聖堂
#define HP_79FB BOKHASH("st06_cloud_00_hpk")         // 0x79FB
#define HP_7A0B BOKHASH("st06_cloud_01_hpk")         // 0x7A0B
#define HP_7A13 BOKHASH("st06_frost_00_hpk")         // 0x7A13
#define HP_7A1B BOKHASH("st06_cloud_02_hpk")         // 0x7A1B
#define HP_7A23 BOKHASH("st06_frost_01_hpk")         // 0x7A23
#define HP_7A2B BOKHASH("st06_cloud_03_hpk")         // 0x7A2B
#define HP_7A33 BOKHASH("st06_frost_02_hpk")         // 0x7A33
#define HP_7A3B BOKHASH("st06_cloud_04_hpk")         // 0x7A3B
#define HP_7A43 BOKHASH("st06_frost_03_hpk")         // 0x7A43
#define HP_7A4B BOKHASH("st06_cloud_05_hpk")         // 0x7A4B
#define HP_7A53 BOKHASH("st06_frost_04_hpk")         // 0x7A53
#define HP_7A63 BOKHASH("st06_frost_05_hpk")         // 0x7A63
#define HP_7A76 BOKHASH("st01_03_cathed_hpk")        // 0x7A76, 大聖堂
#define HP_7A97 BOKHASH("a30_04_time_hpk")           // 0x7A97, 時の家
#define HP_7AF6 BOKHASH("st01_04_cathed_hpk")        // 0x7AF6, 大聖堂
#define HP_7B76 BOKHASH("st01_05_cathed_hpk")        // 0x7B76, 大聖堂
#define HP_7BBA 0x7BBA
#define HP_7BF6 BOKHASH("st01_06_cathed_hpk")  // 0x7BF6, 大聖堂
#define HP_7C76 BOKHASH("st01_07_cathed_hpk")  // 0x7C76, 大聖堂
#define HP_7CF6 BOKHASH("st01_08_cathed_hpk")  // 0x7CF6, 大聖堂
#define HP_7D2E BOKHASH("wedge_hpk")           // 0x7D2E, 各ダンジョンのボス部屋の奥の封印の楔のある部屋
#define HP_7D76 BOKHASH("st01_09_cathed_hpk")  // 0x7D76, 大聖堂
#define HP_7E9E 0x7E9E
#define HP_7F34 0x7F34
#define HP_7FC6 BOKHASH("rockman_hpk")         // 0x7FC6, シェードマンと戦う部屋
#define HP_88F6 BOKHASH("st01_10_cathed_hpk")  // 0x88F6, 大聖堂
#define HP_8976 BOKHASH("st01_11_cathed_hpk")  // 0x8976, 大聖堂
#define HP_89F6 BOKHASH("st01_12_cathed_hpk")  // 0x89F6, 大聖堂
#define HP_8A76 BOKHASH("st01_13_cathed_hpk")  // 0x8A76, 大聖堂
#define HP_8AF6 BOKHASH("st01_14_cathed_hpk")  // 0x8AF6, 大聖堂
#define HP_8B76 BOKHASH("st01_15_cathed_hpk")  // 0x8B76, 大聖堂
#define HP_8BF6 BOKHASH("st01_16_cathed_hpk")  // 0x8BF6, 大聖堂
#define HP_8C76 BOKHASH("st01_17_cathed_hpk")  // 0x8C76, 大聖堂
#define HP_8CF6 BOKHASH("st01_18_cathed_hpk")  // 0x8CF6, 大聖堂
#define HP_8F62 BOKHASH("b00_00_town_hpk")     // 0x8F62, サンミゲル
#define HP_97CD BOKHASH("st03_00_slum_hpk")    // 0x97CD, 暗黒街 (暗黒街をスラム街と呼ぶことはゲーム中で一度もないが、見た目や扱いはどーみてもスラム街だし st03_0n_xxxx_hpk の形で nとステージの深度が一致するのは slum しかない)
#define HP_97CE BOKHASH("st03_08_slum_hpk")    // 0x97CE, 暗黒街
#define HP_97D1 BOKHASH("st03_10_slum_hpk")    // 0x97D1, 暗黒街
#define HP_97D2 BOKHASH("st03_18_slum_hpk")    // 0x97D2, 暗黒街
#define HP_97D5 BOKHASH("st03_20_slum_hpk")    // 0x97D5, 暗黒街
#define HP_97D6 BOKHASH("st03_28_slum_hpk")    // 0x97D6, 暗黒街
#define HP_97D9 BOKHASH("st03_30_slum_hpk")    // 0x97D9, 暗黒街
#define HP_9A97 BOKHASH("a30_05_time_hpk")     // 0x9A97, 時の家
#define HP_9F34 0x9F34
#define HP_A21B BOKHASH("st06_enter_hpk")   // 0xA21B, 変異域1F
#define HP_AF62 BOKHASH("b00_01_town_hpk")  // 0xAF62, サンミゲル
#define HP_B088 BOKHASH("torture_hpk")      // 0xB088, おしおき部屋
#define HP_B26B 0xB26B
#define HP_B381 BOKHASH("st06_flame_00_hpk")  // 0xB381
#define HP_B391 BOKHASH("st06_flame_01_hpk")  // 0xB391
#define HP_B3A1 BOKHASH("st06_flame_02_hpk")  // 0xB3A1
#define HP_B3B1 BOKHASH("st06_flame_03_hpk")  // 0xB3B1
#define HP_B3C1 BOKHASH("st06_flame_04_hpk")  // 0xB3C1
#define HP_B3D1 BOKHASH("st06_flame_05_hpk")  // 0xB3D1
#define HP_B4F1 0xB4F1
#define HP_B66F 0xB66F
#define HP_B673 0xB673
#define HP_B677 0xB677
#define HP_B67B 0xB67B
#define HP_B67F 0xB67F
#define HP_B683 0xB683
#define HP_B687 0xB687
#define HP_B7CD BOKHASH("st03_01_slum_hpk")  // 0xB7CD, 暗黒街, 入り口(00)の次の部屋が含まれるので 01 なのは妥当
#define HP_B7CE BOKHASH("st03_09_slum_hpk")  // 0xB7CE, 暗黒街
#define HP_B7D1 BOKHASH("st03_11_slum_hpk")  // 0xB7D1, 暗黒街
#define HP_B7D2 BOKHASH("st03_19_slum_hpk")  // 0xB7D2, 暗黒街
#define HP_B7D5 BOKHASH("st03_21_slum_hpk")  // 0xB7D5, 暗黒街
#define HP_B7D6 BOKHASH("st03_29_slum_hpk")  // 0xB7D6, 暗黒街
#define HP_B889 0xB889
#define HP_B909 0xB909
#define HP_B989 0xB989
#define HP_BA09 0xBA09
#define HP_BA89 0xBA89
#define HP_BA97 BOKHASH("a30_06_time_hpk")  // 0xBA97, 時の家
#define HP_BB09 0xBB09
#define HP_BB2F 0xBB2F
#define HP_BB89 0xBB89
#define HP_BC09 0xBC09
#define HP_BC89 0xBC89
#define HP_BD09 0xBD09
#define HP_BFB9 BOKHASH("st02_16_a_desert_hpk")  // 0xBFB9, 砂漠 (石版はめる前)
#define HP_C039 BOKHASH("st02_16_b_desert_hpk")  // 0xC039, 砂漠 (石版はめた後)
#define HP_C12F 0xC12F
#define HP_C4C4 BOKHASH("a00_00_ruins_hpk")  // 0xC4C4, 廃墟
#define HP_C4C8 BOKHASH("a00_01_ruins_hpk")  // 0xC4C8, 廃墟
#define HP_C4CC BOKHASH("a00_02_ruins_hpk")  // 0xC4CC, 廃墟
#define HP_C4D0 BOKHASH("a00_03_ruins_hpk")  // 0xC4D0, 廃墟
#define HP_C4D4 BOKHASH("a00_04_ruins_hpk")  // 0xC4D4, 廃墟
#define HP_C4D8 BOKHASH("a00_05_ruins_hpk")  // 0xC4D8, 廃墟
#define HP_C4DC BOKHASH("a00_06_ruins_hpk")  // 0xC4DC, 廃墟
#define HP_C4E0 BOKHASH("a00_07_ruins_hpk")  // 0xC4E0, 廃墟
#define HP_C4E4 BOKHASH("a00_08_ruins_hpk")  // 0xC4E4, 廃墟
#define HP_C889 0xC889
#define HP_C909 0xC909
#define HP_C989 0xC989
#define HP_CA09 0xCA09
#define HP_CA89 0xCA89
#define HP_CB09 0xCB09
#define HP_CB89 0xCB89
#define HP_CD05 BOKHASH("st05_00_tower_hpk")  // 0xCD05, 約束の丘 (螺旋の塔の入り口)
#define HP_CD09 BOKHASH("st05_01_tower_hpk")  // 0xCD09, 螺旋の塔
#define HP_CD0D BOKHASH("st05_02_tower_hpk")  // 0xCD0D, 螺旋の塔
#define HP_CD11 BOKHASH("st05_03_tower_hpk")  // 0xCD11, 螺旋の塔
#define HP_CD15 BOKHASH("st05_04_tower_hpk")  // 0xCD15, 螺旋の塔
#define HP_CD19 BOKHASH("st05_05_tower_hpk")  // 0xCD19, 螺旋の塔
#define HP_CD1D BOKHASH("st05_06_tower_hpk")  // 0xCD1D, 螺旋の塔
#define HP_CD21 BOKHASH("st05_07_tower_hpk")  // 0xCD21, 螺旋の塔
#define HP_CD25 BOKHASH("st05_08_tower_hpk")  // 0xCD25, 螺旋の塔
#define HP_CD29 BOKHASH("st05_09_tower_hpk")  // 0xCD29, 螺旋の塔
#define HP_CD85 BOKHASH("st05_10_tower_hpk")  // 0xCD85, 螺旋の塔
#define HP_CD89 BOKHASH("st05_11_tower_hpk")  // 0xCD89, 螺旋の塔
#define HP_CD8D BOKHASH("st05_12_tower_hpk")  // 0xCD8D, 螺旋の塔
#define HP_CD91 BOKHASH("st05_13_tower_hpk")  // 0xCD91, 螺旋の塔
#define HP_CD95 BOKHASH("st05_14_tower_hpk")  // 0xCD95, 螺旋の塔
#define HP_CD99 BOKHASH("st05_15_tower_hpk")  // 0xCD99, 螺旋の塔
#define HP_CD9D BOKHASH("st05_16_tower_hpk")  // 0xCD9D, 螺旋の塔
#define HP_CDA1 BOKHASH("st05_17_tower_hpk")  // 0xCDA1, 螺旋の塔
#define HP_CDA5 BOKHASH("st05_18_tower_hpk")  // 0xCDA5, 螺旋の塔
#define HP_CDA9 BOKHASH("st05_19_tower_hpk")  // 0xCDA9, 螺旋の塔
#define HP_CE05 BOKHASH("st05_20_tower_hpk")  // 0xCE05, 螺旋の塔
#define HP_CE09 BOKHASH("st05_21_tower_hpk")  // 0xCE09, 螺旋の塔
#define HP_CE0D BOKHASH("st05_22_tower_hpk")  // 0xCE0D, 螺旋の塔
#define HP_CE11 BOKHASH("st05_23_tower_hpk")  // 0xCE11, 螺旋の塔
#define HP_CE15 BOKHASH("st05_24_tower_hpk")  // 0xCE15, 螺旋の塔
#define HP_CE19 BOKHASH("st05_25_tower_hpk")  // 0xCE19, 螺旋の塔
#define HP_CE1D BOKHASH("st05_26_tower_hpk")  // 0xCE1D, 螺旋の塔
#define HP_CF62 BOKHASH("b00_02_town_hpk")    // 0xCF62, サンミゲル
#define HP_D312 BOKHASH("st04_00_lake_hpk")   // 0xD312, 地下水路, (湖と呼ぶことはゲーム中ないが、水源とは呼んでいる, st04_0n_lake_hpk の n が 0, 1, ... の順にステージの奥に行くので合っているだろう)
#define HP_D461 0xD461
#define HP_D7CD BOKHASH("st03_02_slum_hpk")  // 0xD7CD, 暗黒街
#define HP_D7D1 BOKHASH("st03_12_slum_hpk")  // 0xD7D1, 暗黒街
#define HP_D7D5 BOKHASH("st03_22_slum_hpk")  // 0xD7D5, 暗黒街
#define HP_D909 0xD909
#define HP_D9EF BOKHASH("st06_earth_00_hpk")  // 0xD9EF, 変異域B1
#define HP_D9FF BOKHASH("st06_earth_01_hpk")  // 0xD9FF, 変異域B1
#define HP_DA0F BOKHASH("st06_earth_02_hpk")  // 0xDA0F, 変異域B1
#define HP_DA1F BOKHASH("st06_earth_03_hpk")  // 0xDA1F, 変異域B1
#define HP_DA2F BOKHASH("st06_earth_04_hpk")  // 0xDA2F, 変異域B1
#define HP_DA3F BOKHASH("st06_earth_05_hpk")  // 0xDA3F, 変異域B1, ボス部屋(サンドウォーム)
#define HP_DA97 BOKHASH("a30_07_time_hpk")    // 0xDA97, 時の家
#define HP_EAC3 BOKHASH("random_goal_hpk")    // 0xEAC3, 夢幻街の報酬部屋
#define HP_F312 BOKHASH("st04_01_lake_hpk")   // 0xF312, 地下水路
#define HP_F38C 0xF38C
#define HP_F7CD BOKHASH("st03_03_slum_hpk")    // 0xF7CD, 暗黒街
#define HP_F7D1 BOKHASH("st03_13_slum_hpk")    // 0xF7D1, 暗黒街
#define HP_F7D5 BOKHASH("st03_23_slum_hpk")    // 0xF7D5, 暗黒街
#define HP_F82D BOKHASH("st02_00_desert_hpk")  // 0xF82D, 遺跡
#define HP_F8AD BOKHASH("st02_01_desert_hpk")  // 0xF8AD, 遺跡
#define HP_F92D BOKHASH("st02_02_desert_hpk")  // 0xF92D, 遺跡
#define HP_F9AD BOKHASH("st02_03_desert_hpk")  // 0xF9AD, 遺跡
#define HP_FA2D BOKHASH("st02_04_desert_hpk")  // 0xFA2D, 遺跡
#define HP_FA96 BOKHASH("a30_00_time_hpk")     // 0xFA96, 時の家
#define HP_FA97 BOKHASH("a30_08_time_hpk")     // 0xFA97, 時の家
#define HP_FAAD BOKHASH("st02_05_desert_hpk")  // 0xFAAD, 遺跡
#define HP_FB2D BOKHASH("st02_06_desert_hpk")  // 0xFB2D, 遺跡
#define HP_FBAD BOKHASH("st02_07_desert_hpk")  // 0xFBAD, 遺跡
#define HP_FC2D BOKHASH("st02_08_desert_hpk")  // 0xFC2D, 遺跡
#define HP_FCAD BOKHASH("st02_09_desert_hpk")  // 0xFCAD, 遺跡

#endif  // __INCLUDE_CONSTANTS_COLLISION_MAP_H__
