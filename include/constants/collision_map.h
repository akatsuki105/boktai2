#ifndef __INCLUDE_CONSTANTS_COLLISION_MAP_H__
#define __INCLUDE_CONSTANTS_COLLISION_MAP_H__

// Collision map file IDs (prefix の HP_ は CollisionMapFile の magic が HP だったので)
#define HP_050F BOKHASH("st00_00_hpk")      // 0x050F, 渓谷
#define HP_051F BOKHASH("st00_01_hpk")      // 0x051F, 渓谷, "st02_00_hpk" とハッシュが衝突するが、利用箇所を確かめたところ、渓谷("st00")だったのでこれで正しいと思われる
#define HP_052F BOKHASH("st00_02_hpk")      // 0x052F, 渓谷, "st04_00_hpk" 〃
#define HP_053F BOKHASH("st00_03_hpk")      // 0x053F, 街門, 変異域が "st06_00_hpk" でなく "st06_enter_hpk" なのはこれとハッシュが衝突しているから
#define HP_054F BOKHASH("st00_04_hpk")      // 0x054F
#define HP_072C BOKHASH("random_room_hpk")  // 0x072C
#define HP_082E 0x082E
#define HP_08AE 0x08AE
#define HP_092E 0x092E
#define HP_09AE 0x09AE
#define HP_0A2E 0x0A2E
#define HP_0AAE 0x0AAE
#define HP_0BAE 0x0BAE
#define HP_0C2E 0x0C2E
#define HP_0CAE 0x0CAE
#define HP_0F0C BOKHASH("random_boss_hpk")  // 0x0F0C
#define HP_0F63 0x0F63
#define HP_11B6 BOKHASH("f00_hpk")  // 0x11B6, 6番街
#define HP_11C6 BOKHASH("f01_hpk")  // 0x11C6, 10番街
#define HP_11D6 BOKHASH("f02_hpk")  // 0x11D6, 4番街
#define HP_11E6 BOKHASH("f03_hpk")  // 0x11E6, 2番街
#define HP_11F6 BOKHASH("f04_hpk")  // 0x11F6, 8番街
#define HP_1206 BOKHASH("f05_hpk")  // 0x1206, 12番街
#define HP_1313 0x1313
#define HP_164C 0x164C
#define HP_17CE 0x17CE
#define HP_17D2 0x17D2
#define HP_17D6 0x17D6
#define HP_182E 0x182E
#define HP_1A97 0x1A97
#define HP_2EF8 BOKHASH("st06_last_00_hpk")  // 0x2EF8
#define HP_2F08 BOKHASH("st06_last_01_hpk")  // 0x2F08
#define HP_2F18 BOKHASH("st06_last_02_hpk")  // 0x2F18
#define HP_2F28 BOKHASH("st06_last_03_hpk")  // 0x2F28
#define HP_2F38 BOKHASH("st06_last_04_hpk")  // 0x2F38
#define HP_2F48 BOKHASH("st06_last_05_hpk")  // 0x2F48
#define HP_2F58 BOKHASH("st06_last_06_hpk")  // 0x2F58
#define HP_2F63 0x2F63
#define HP_2F68 BOKHASH("st06_last_07_hpk")  // 0x2F68
#define HP_3313 0x3313
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
#define HP_37CE 0x37CE
#define HP_37D2 0x37D2
#define HP_37D6 0x37D6
#define HP_3A97 0x3A97
#define HP_3D33 0x3D33
#define HP_3DB3 0x3DB3
#define HP_3E33 0x3E33
#define HP_3EB3 0x3EB3
#define HP_3F33 0x3F33
#define HP_3FB3 0x3FB3
#define HP_4033 0x4033
#define HP_40B3 0x40B3
#define HP_4133 0x4133
#define HP_41B3 0x41B3
#define HP_43B7 0x43B7
#define HP_4D33 0x4D33
#define HP_4DB3 0x4DB3
#define HP_4E33 0x4E33
#define HP_4EB3 0x4EB3
#define HP_4F33 0x4F33
#define HP_5313 0x5313
#define HP_57CE 0x57CE
#define HP_57D2 0x57D2
#define HP_57D6 0x57D6
#define HP_5A97 0x5A97
#define HP_5F34 0x5F34
#define HP_677F 0x677F
#define HP_6A7F 0x6A7F
#define HP_6AB0 BOKHASH("random_enter_hpk")  // 0x6AB0
#define HP_77CE 0x77CE
#define HP_77D2 0x77D2
#define HP_77D6 0x77D6
#define HP_78F6 0x78F6
#define HP_7976 0x7976
#define HP_79F6 0x79F6
#define HP_79FB BOKHASH("st06_cloud_00_hpk")  // 0x79FB
#define HP_7A0B BOKHASH("st06_cloud_01_hpk")  // 0x7A0B
#define HP_7A13 BOKHASH("st06_frost_00_hpk")  // 0x7A13
#define HP_7A1B BOKHASH("st06_cloud_02_hpk")  // 0x7A1B
#define HP_7A23 BOKHASH("st06_frost_01_hpk")  // 0x7A23
#define HP_7A2B BOKHASH("st06_cloud_03_hpk")  // 0x7A2B
#define HP_7A33 BOKHASH("st06_frost_02_hpk")  // 0x7A33
#define HP_7A3B BOKHASH("st06_cloud_04_hpk")  // 0x7A3B
#define HP_7A43 BOKHASH("st06_frost_03_hpk")  // 0x7A43
#define HP_7A4B BOKHASH("st06_cloud_05_hpk")  // 0x7A4B
#define HP_7A53 BOKHASH("st06_frost_04_hpk")  // 0x7A53
#define HP_7A63 BOKHASH("st06_frost_05_hpk")  // 0x7A63
#define HP_7A76 0x7A76
#define HP_7A97 0x7A97
#define HP_7AF6 0x7AF6
#define HP_7B76 0x7B76
#define HP_7BBA 0x7BBA
#define HP_7BF6 0x7BF6
#define HP_7C76 0x7C76
#define HP_7CF6 0x7CF6
#define HP_7D2E BOKHASH("wedge_hpk")  // 0x7D2E, 各ダンジョンのボス部屋の奥の封印の楔のある部屋
#define HP_7D76 0x7D76
#define HP_7E9E 0x7E9E
#define HP_7F34 0x7F34
#define HP_7FC6 BOKHASH("rockman_hpk")  // 0x7FC6, シェードマンと戦う部屋
#define HP_88F6 0x88F6
#define HP_8976 0x8976
#define HP_89F6 0x89F6
#define HP_8A76 0x8A76
#define HP_8AF6 0x8AF6
#define HP_8B76 0x8B76
#define HP_8BF6 0x8BF6
#define HP_8C76 0x8C76
#define HP_8CF6 0x8CF6
#define HP_8F62 0x8F62  // サンミゲル (b00_00)
#define HP_97CD 0x97CD
#define HP_97CE 0x97CE
#define HP_97D1 0x97D1
#define HP_97D2 0x97D2
#define HP_97D5 0x97D5
#define HP_97D6 0x97D6
#define HP_97D9 0x97D9
#define HP_9A97 0x9A97
#define HP_9F34 0x9F34
#define HP_A21B BOKHASH("st06_enter_hpk")  // 0xA21B, 変異域1F
#define HP_AF62 0xAF62
#define HP_B088 BOKHASH("torture_hpk")  // 0xB088, おしおき部屋
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
#define HP_B7CD 0xB7CD
#define HP_B7CE 0xB7CE
#define HP_B7D1 0xB7D1
#define HP_B7D2 0xB7D2
#define HP_B7D5 0xB7D5
#define HP_B7D6 0xB7D6
#define HP_B889 0xB889
#define HP_B909 0xB909
#define HP_B989 0xB989
#define HP_BA09 0xBA09
#define HP_BA89 0xBA89
#define HP_BA97 0xBA97
#define HP_BB09 0xBB09
#define HP_BB2F 0xBB2F
#define HP_BB89 0xBB89
#define HP_BC09 0xBC09
#define HP_BC89 0xBC89
#define HP_BD09 0xBD09
#define HP_BFB9 0xBFB9
#define HP_C039 0xC039
#define HP_C12F 0xC12F
#define HP_C4C4 0xC4C4
#define HP_C4C8 0xC4C8
#define HP_C4CC 0xC4CC
#define HP_C4D0 0xC4D0
#define HP_C4D4 0xC4D4
#define HP_C4D8 0xC4D8
#define HP_C4DC 0xC4DC
#define HP_C4E0 0xC4E0
#define HP_C4E4 0xC4E4
#define HP_C889 0xC889
#define HP_C909 0xC909
#define HP_C989 0xC989
#define HP_CA09 0xCA09
#define HP_CA89 0xCA89
#define HP_CB09 0xCB09
#define HP_CB89 0xCB89
#define HP_CD05 0xCD05
#define HP_CD09 0xCD09
#define HP_CD0D 0xCD0D
#define HP_CD11 0xCD11
#define HP_CD15 0xCD15
#define HP_CD19 0xCD19
#define HP_CD1D 0xCD1D
#define HP_CD21 0xCD21
#define HP_CD25 0xCD25
#define HP_CD29 0xCD29
#define HP_CD85 0xCD85
#define HP_CD89 0xCD89
#define HP_CD8D 0xCD8D
#define HP_CD91 0xCD91
#define HP_CD95 0xCD95
#define HP_CD99 0xCD99
#define HP_CD9D 0xCD9D
#define HP_CDA1 0xCDA1
#define HP_CDA5 0xCDA5
#define HP_CDA9 0xCDA9
#define HP_CE05 0xCE05
#define HP_CE09 0xCE09
#define HP_CE0D 0xCE0D
#define HP_CE11 0xCE11
#define HP_CE15 0xCE15
#define HP_CE19 0xCE19
#define HP_CE1D 0xCE1D
#define HP_CF62 0xCF62
#define HP_D312 0xD312
#define HP_D461 0xD461
#define HP_D7CD 0xD7CD
#define HP_D7D1 0xD7D1
#define HP_D7D5 0xD7D5
#define HP_D909 0xD909
#define HP_D9EF BOKHASH("st06_earth_00_hpk")  // 0xD9EF, 変異域B1
#define HP_D9FF BOKHASH("st06_earth_01_hpk")  // 0xD9FF, 変異域B1
#define HP_DA0F BOKHASH("st06_earth_02_hpk")  // 0xDA0F, 変異域B1
#define HP_DA1F BOKHASH("st06_earth_03_hpk")  // 0xDA1F, 変異域B1
#define HP_DA2F BOKHASH("st06_earth_04_hpk")  // 0xDA2F, 変異域B1
#define HP_DA3F BOKHASH("st06_earth_05_hpk")  // 0xDA3F, 変異域B1, ボス部屋(サンドウォーム)
#define HP_DA97 0xDA97
#define HP_EAC3 BOKHASH("random_goal_hpk")  // 0xEAC3, 夢幻街の報酬部屋
#define HP_F312 0xF312
#define HP_F38C 0xF38C
#define HP_F7CD 0xF7CD
#define HP_F7D1 0xF7D1
#define HP_F7D5 0xF7D5
#define HP_F82D 0xF82D  // st02_00
#define HP_F8AD 0xF8AD  // st02_01
#define HP_F92D 0xF92D  // st02_02
#define HP_F9AD 0xF9AD
#define HP_FA2D 0xFA2D
#define HP_FA96 0xFA96
#define HP_FA97 0xFA97
#define HP_FAAD 0xFAAD
#define HP_FB2D 0xFB2D
#define HP_FBAD 0xFBAD
#define HP_FC2D 0xFC2D
#define HP_FCAD 0xFCAD

#endif  // __INCLUDE_CONSTANTS_COLLISION_MAP_H__
