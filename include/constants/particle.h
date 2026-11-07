#ifndef __INCLUDE_CONSTANTS_PARTICLE_H__
#define __INCLUDE_CONSTANTS_PARTICLE_H__

// Particle_SetPose の idx

// PTCL_GROUP_0 (16x16px)
#define PTCL0_0 0
#define PTCL0_1 1
#define PTCL0_2 2
#define PTCL0_3 3
#define PTCL0_4 4
#define PTCL0_5 5
#define PTCL0_BAMBOO_SHOOTS(step) (6 + (step))  // 太陽タケノコ(bamboo_shoots.c), step は アニメーションの段階 で 0..3
#define PTCL0_ICE 10                            // 氷の礫 (魔法"フリーズ", 氷結)
#define PTCL0_STONE 11                          // 石の礫 (石化)
#define PTCL_FIRE(step) (12 + (step))           // 火のエフェクト, step: 0..7
#define PTCL0_SOLARBUG(step) (20 + (step))      // 太陽虫 (SOLARBUG), step: 0..3
#define PTCL0_MOONBUG(step) (24 + (step))       // 月光虫 (MOONBUG), step: 0..3
#define PTCL0_DARKBUG(step) (28 + (step))       // 暗黒虫 (DARKBUG), step: 0..3
#define PTCL0_32 32
#define PTCL0_33 33
#define PTCL0_34 34
#define PTCL0_35 35
#define PTCL0_36 36
#define PTCL0_37 37
#define PTCL0_38 38
#define PTCL0_39 39
#define PTCL0_40 40
#define PTCL0_41 41
#define PTCL0_42 42
#define PTCL0_43 43
#define PTCL0_44 44
#define PTCL0_45 45
#define PTCL0_46 46
#define PTCL0_47 47
#define PTCL0_48 48
#define PTCL0_49 49
#define PTCL0_50 50
#define PTCL0_ARROW 51        // エリア移動場所に置かれる矢印マーカー, デフォルトのオレンジ
#define PTCL0_WARNING 52      // 警告マーク
#define PTCL0_ARROW_RED 53    // PTCL0_ARROW の 赤色
#define PTCL0_ARROW_GREEN 54  // PTCL0_ARROW の 緑色
#define PTCL0_ARROW_WHITE 55  // PTCL0_ARROW の 白色

// PTCL_GROUP_1 (8x8px)
#define PTCL1_0 0
#define PTCL1_1 1
#define PTCL1_2 2
#define PTCL1_3 3
#define PTCL1_4 4
#define PTCL1_5 5
#define PTCL1_6 6
#define PTCL1_7 7
#define PTCL1_8 8
#define PTCL1_9 9
#define PTCL1_10 10
#define PTCL1_11 11
#define PTCL1_12 12
#define PTCL1_13 13
#define PTCL1_14 14
#define PTCL1_15 15
#define PTCL1_CONFUSE 16  // 混乱(BAD_CONFUSE)したときにプレイヤーの頭上に出るエフェクト
#define PTCL1_17 17
#define PTCL1_18 18
#define PTCL1_19 19
#define PTCL1_20 20
#define PTCL1_21 21
#define PTCL1_22 22
#define PTCL1_23 23
#define PTCL1_24 24
#define PTCL1_25 25
#define PTCL1_26 26
#define PTCL1_27 27
#define PTCL1_28 28
#define PTCL1_29 29
#define PTCL1_30 30
#define PTCL1_31 31
#define PTCL1_NUM_WHITE(num) (32 + (num))      // 0..9, 内側白, 外側黒
#define PTCL1_NUM_GREEN(num) (42 + (num))      // 0..9, 内側緑, 外側黒
#define PTCL1_NUM_WHITE_INV(num) (52 + (num))  // 0..9, 内側黒, 外側白
#define PTCL1_NUM_GREEN_INV(num) (62 + (num))  // 0..9, 内側黒, 外側緑
#define PTCL1_72 72                            // 不明(大)
#define PTCL1_73 73                            // 不明(小)

// PTCL_GROUP_2 (8x8px), エレメントのパーティクル
#define PTCL2_0 0         // 不明A(大)
#define PTCL2_1 1         // 不明A(小)
#define PTCL2_SOL_L 2     // ソル(大)
#define PTCL2_SOL_S 3     // ソル(小)
#define PTCL2_DARK_L 4    // ダーク(大)
#define PTCL2_DARK_S 5    // ダーク(小)
#define PTCL2_FLAME_L 6   // フレイム(大)
#define PTCL2_FLAME_S 7   // フレイム(小)
#define PTCL2_FROST_L 8   // フロスト(大)
#define PTCL2_FROST_S 9   // フロスト(小)
#define PTCL2_CLOUD_L 10  // クラウド(大)
#define PTCL2_CLOUD_S 11  // クラウド(小)
#define PTCL2_EARTH_L 12  // アース(大)
#define PTCL2_EARTH_S 13  // アース(小)
#define PTCL2_14 14       // 不明B(大)
#define PTCL2_15 15       // 不明B(小)
#define PTCL2_16 16       // 不明C(大)
#define PTCL2_17 17       // 不明C(中)
#define PTCL2_18 18       // 不明C(小)

#endif  // __INCLUDE_CONSTANTS_PARTICLE_H__
