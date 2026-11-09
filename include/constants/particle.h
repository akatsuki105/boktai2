#ifndef __INCLUDE_CONSTANTS_PARTICLE_H__
#define __INCLUDE_CONSTANTS_PARTICLE_H__

// Particle_SetPose の idx

// PTCL_GROUP_0 (16x16px)
#define PTCL0_SMOKE_A(step) (0 + (step))        // 煙のエフェクト (A), step 0..2
#define PTCL0_BLOOD(step) (3 + (step))          // 出血エフェクト, step 0..2 = 傷口, 血しぶき大, 血しぶき小
#define PTCL0_BAMBOO_SHOOTS(step) (6 + (step))  // 太陽タケノコ(bamboo_shoots.c), step は アニメーションの段階 で 0..3
#define PTCL0_ICE 10                            // 氷の礫 (魔法"フリーズ", 氷結)
#define PTCL0_STONE 11                          // 石の礫 (石化)
#define PTCL_FIRE(step) (12 + (step))           // 火のエフェクト, step: 0..7
#define PTCL0_SOLARBUG(step) (20 + (step))      // 太陽虫 (SOLARBUG), step: 0..3
#define PTCL0_MOONBUG(step) (24 + (step))       // 月光虫 (MOONBUG), step: 0..3
#define PTCL0_DARKBUG(step) (28 + (step))       // 暗黒虫 (DARKBUG), step: 0..3
#define PTCL0_32 32                             // アイテム袋
#define PTCL0_33 33                             // ???, 白塗りの丸
#define PTCL0_SHADOW 34                         // 影 (ParticleShadow)
#define PTCL0_35 35                             // ???, 白塗りの何か
#define PTCL0_SMOKE_B(step) (36 + (step))       // 煙のエフェクト (B), PTCL0_SMOKE_A の色違い, step 0..2
#define PTCL0_SMOKE_C(step) (39 + (step))       // 煙のエフェクト (C), step 0..3
#define PTCL0_SMOKE_D(step) (43 + (step))       // 煙のエフェクト (D), PTCL0_SMOKE_C の色違い, step 0..3
#define PTCL0_SMOKE_E(step) (47 + (step))       // 煙のエフェクト (E), step 0..3
#define PTCL0_ARROW 51                          // エリア移動場所に置かれる矢印マーカー, デフォルトのオレンジ
#define PTCL0_WARNING 52                        // 警告マーク
#define PTCL0_ARROW_RED 53                      // PTCL0_ARROW の 赤色
#define PTCL0_ARROW_GREEN 54                    // PTCL0_ARROW の 緑色
#define PTCL0_ARROW_WHITE 55                    // PTCL0_ARROW の 白色

// PTCL_GROUP_1 (8x8px)
#define PTCL1_0 0
#define PTCL1_1 1
#define PTCL1_2 2
#define PTCL1_3 3
#define PTCL1_NOISE_S 4                   // 物音を表す漫符(小), 壁叩き, 鳴り床の上を歩いたときなど、 物音を出したときに表示
#define PTCL1_NOISE_L 5                   // 物音を表す漫符(大)
#define PTCL1_SPARKLE(size) (6 + (size))  // キラキラのエフェクト, size: 0=大, 1=小
#define PTCL1_ICE 8                       // 氷の小さい粒
#define PTCL1_STONE 9                     // 石の小さい粒
#define PTCL1_10 10                       // 用途不明, PTCL1_ICE と PTCL1_STONE の影用?
#define PTCL1_STAR 11                     // 気絶したときに頭上を回る星
#define PTCL1_12 12
#define PTCL1_13 13
#define PTCL1_14 14
#define PTCL1_CLAY 15     // クレイゴーレムが死んだ時に出る土の破片
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
#define PTCL1_27 27  // 小さい点 (ただの点なので画像だけでは用途がわからん)
#define PTCL1_28 28  // 小さい点 (ただの点なので画像だけでは用途がわからん)
#define PTCL1_29 29
#define PTCL1_30 30
#define PTCL1_31 31
#define PTCL1_NUM_WHITE(num) (32 + (num))      // 0..9, 内側白, 外側黒
#define PTCL1_NUM_GREEN(num) (42 + (num))      // 0..9, 内側緑, 外側黒
#define PTCL1_NUM_WHITE_INV(num) (52 + (num))  // 0..9, 内側黒, 外側白
#define PTCL1_NUM_GREEN_INV(num) (62 + (num))  // 0..9, 内側黒, 外側緑
#define PTCL1_FRAGILE_KNOCK_S 72               // 傷んだ壁の壁叩き(小), 多分それ以外の用途はなかったはず
#define PTCL1_FRAGILE_KNOCK_L 73               // 傷んだ壁の壁叩き(大)

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
