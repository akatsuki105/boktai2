#ifndef __INCLUDE_CONSTANTS_ENEMY_H__
#define __INCLUDE_CONSTANTS_ENEMY_H__

// Enemy Family
// 敵を意味的に分類したもの (EnemyKind はグラフィックが異なるものは別の kind として扱っていた)
// kind との対応は Enemy_GetFamily を参照
#define ENEF_BOKU 0        // ボク系
#define ENEF_MUMMY 1       // マミー系(マミー, ガスト)
#define ENEF_SPIDER 2      // スパイダー系(スパイダー, ポイズンスパイダー)
#define ENEF_GOLEM 3       // ゴーレム系
#define ENEF_SKELETON 4    // スケルトン系
#define ENEF_LICH 5        // リッチ系
#define ENEF_CENTIPEDE 6   // センチピード
#define ENEF_COCKATRICE 7  // コカトリス系
#define ENEF_MIMIC 8       // ミミック
#define ENEF_SWORD 9       // ソード系
#define ENEF_AX 10         // アックス系
#define ENEF_OCTOPUS 11    // オクトパス系
#define EKEF_12 12         // ???
#define ENEF_CURORO 13     // クロロホルルン系
#define ENEF_BAT 14        // バット系
#define ENEF_CROW 15       // クロウ系
#define ENEF_DOG 16        // 犬系
#define ENEF_SLIME 17      // スライム系
#define ENEF_BEE 18        // ビー系
#define ENEF_GHOST 19      // ゴースト系
#define ENEF_SANDWORM 20   // サンドウォーム
#define ENEF_SERPENT 21    // サーペント
#define ENEF_SHAIAN 22     // シャイアン
#define ENEF_DARKROOT 23   // 暗黒の根

// EnemyKind (Enemy.kind)
// 同じ kind に属するものはグラフィックが全く同じで Enemy.variant で色が変わる
#define ENEK_0 0           // ???, エネミーにデータを送るときのブロードキャスト用IDとして利用している
#define ENEK_MUMMY 1       // マミー系
#define ENEK_SPIDER 2      // スパイダー系
#define ENEK_GOLEM 3       // ゴーレム系
#define ENEK_BOKU 4        // ボク系
#define ENEK_SKELETON 5    // スケルトン系
#define ENEK_SKELETON_F 6  // スケルトンフェンサー, スケルトンの一種だがグラフィックが違うので別のkind
#define ENEK_SKELETON_A 7  // スケルトンアーチャー, スケルトンの一種だがグラフィックが違うので別のkind
#define ENEK_LICH 8        // リッチ系
#define ENEK_CENTIPEDE 9   // センチピード
#define ENEK_COCKA 10      // コカトリス系
#define ENEK_MIMIC 11      // ミミック
#define ENEK_SWORD 12      // ソード系
#define ENEK_AX 13         // アックス系
#define ENEK_OCTOPUS 14    // オクトパス
#define ENEK_15 15         // ???
#define ENEK_16 16         // ???
#define ENEK_CURORO 17     // クロロホルルン系
#define ENEK_BAT 18        // バット系
#define ENEK_CROW 19       // クロウ系
#define ENEK_BEE 20        // ビー系
#define ENEK_DOG 21        // 犬系
#define ENEK_SLIME 22      // スライム系
#define ENEK_GHOST 23      // ゴースト系
#define ENEK_DARKROOT 24   // 暗黒の根
#define ENEK_SANDWORM 25   // サンドウォーム
#define ENEK_SERPENT 26    // サーペント
#define ENEK_SHAIAN 27     // シャイアン
#define ENEK_28 28         // 未検証: 通信用のボク?
#define ENEK_29 29         // ???
#define ENEK_30 30         // 未検証: 通信用のゴーレム?
#define ENEK_31 31         // ???

// EnemyID, 魔物図鑑のエントリ番号に対応 (ただしゲーム内では 1 から始まる (EnemyID+1))
#define ENEID_SPIDER 0        // No.01 スパイダー
#define ENEID_PSPIDER 1       // No.02 ポイズンスパイダー
#define ENEID_BEE 2           // No.03 ビー
#define ENEID_PBEE 3          // No.04 ポイズンビー
#define ENEID_KBEE 4          // No.05 キラービー
#define ENEID_BAT 5           // No.06 バット
#define ENEID_VBAT 6          // No.07 ヴァンパイアバット
#define ENEID_CROW 7          // No.08 クロウ
#define ENEID_GARGOYLE 8      // No.09 ガーゴイル
#define ENEID_CENTIPEDE 9     // No.10 センチピード
#define ENEID_BANDIT 10       // No.11 バンデット
#define ENEID_HELLHOUND 11    // No.12 ヘルハウンド
#define ENEID_GRAVEKEEPER 12  // No.13 グレイブキーパー
#define ENEID_BANDIT_P 13     // No.14 バンデット+
#define ENEID_DARKROOT 14     // No.15 暗黒の根
#define ENEID_SHAIAN 15       // No.16 シャイアン
#define ENEID_OCTOPUS 16      // No.17 オクトパス
#define ENEID_COCKA 17        // No.18 コカトリス
#define ENEID_COCKA_P 18      // No.19 コカトリス+
#define ENEID_SANDWORM 19     // No.20 サンドウォーム
#define ENEID_SERPENT 20      // No.21 サーペント
#define ENEID_GHOUL 21        // No.22 グール
#define ENEID_ZOMBIE 22       // No.23 ゾンビ
#define ENEID_GHOUL_P 23      // No.24 グール+
#define ENEID_MUMMY 24        // No.25 マミー
#define ENEID_GAST 25         // No.26 ガスト
#define ENEID_MUMMY_P 26      // No.27 マミー+
#define ENEID_SKELETON 27     // No.28 スケルトン
#define ENEID_SKELETON_F 28   // No.29 スケルトンフェンサー (スケルトンF)
#define ENEID_SKELETON_A 29   // No.30 スケルトンアーチャー (スケルトンA)
#define ENEID_SKELETON_P 30   // No.31 スケルトン+
#define ENEID_LICH 31         // No.32 リッチ
#define ENEID_LICH_P 32       // No.33 リッチ+
#define ENEID_GOLEM_C 33      // No.34 クレイゴーレム
#define ENEID_GOLEM_S 34      // No.35 ストーンゴーレム
#define ENEID_GOLEM_P 35      // No.36 ゴーレム+
#define ENEID_MIMIC 36        // No.37 ミミック
#define ENEID_SWORD 37        // No.38 ソード
#define ENEID_SWORD_P 38      // No.39 ソード+
#define ENEID_AX 39           // No.40 アックス
#define ENEID_AX_P 40         // No.41 アックス+
#define ENEID_CURORO 41       // No.42 クロロホルルン
#define ENEID_CURORO_F 42     // No.43 モエルルン
#define ENEID_CURORO_I 43     // No.44 ヒエルルン
#define ENEID_SLIME_Y 44      // No.45 イエロースライム
#define ENEID_SLIME_G 45      // No.46 グリーンスライム
#define ENEID_SLIME_P 46      // No.47 パープルスライム
#define ENEID_SLIME_B 47      // No.48 ブラックスライム
#define ENEID_GHOST 48        // No.49 ゴースト
#define ENEID_WRAITH 49       // No.50 レイス
#define ENEID_DUNEYRR 50      // No.51 ドゥネイル
#define ENEID_RINGO 51        // No.52 ヴァンパイア
#define ENEID_DURATHROR 52    // No.53 ドゥラスロール
#define ENEID_DVALINN 53      // No.54 ドヴァリン
#define ENEID_DAINN 54        // No.55 ダーイン
#define ENEID_JORMUNGANDR 55  // No.56 ヨルムンガンド
#define ENEID_SHADEMAN 56     // No.57 シェードマン

#endif  // __INCLUDE_CONSTANTS_ENEMY_H__
