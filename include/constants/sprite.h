#ifndef __INCLUDE_CONSTANTS_SPRITE_H__
#define __INCLUDE_CONSTANTS_SPRITE_H__

#define SPRITE_UI_MAP 0x0312                   // スタートメニューのマップ画面で使うスプライト
#define SPRITE_EVENT_SUN_RAY 0x0C23            // ラスボス戦のイベントで使う太陽光のエフェクト
#define SPRITE_DJANGO_LARGE 0x1774             // ソルデバイスやラスボス戦のイベントで使う、ジャンゴの大きな1枚絵
#define SPRITE_FLAMETHROWER 0x1BC7             // 火炎放射
#define SPRITE_UI_MISC 0x414C                  // 太陽鍛治, ショップ名, "時の家"の暗証番号入力端末 など、メニューUIのうち、用途が限定的でサイズの小さいものをここにまとめている
#define SPRITE_42E2 0x42E2                     // 太陽センサーのヘルプの手や住んでる地域のフォント
#define SPRITE_INVENTORY_ICONS 0x5D04          // アイテムアイコン, poseIdx は "include/constants/item_icon.h"
#define SPRITE_SHADEMAN 0x5D36                 // シェードマン(EXE)
#define SPRITE_UI_GALLERY 0x5EBF               // 図書館で見れる魔物図鑑,武器図鑑,アルバムのUI
#define SPRITE_UI_SOLARBANK 0x6893             // 太陽バンクのUI
#define SPRITE_MARKERS 0x82F1                  // "Undead", "Immortal", "TRAP" といった画面上に表示されるマーカー
#define SPRITE_UI_DARKLOAN 0x92F0              // 暗黒ローンのUI
#define SPRITE_JORMUNGANDR 0x9524              // ヨルムンガンド
#define SPRITE_SKELETONS 0xAE52                // スケルトン
#define SPRITE_MEGAMAN 0xAF82                  // ロックマン(EXE)
#define SPRITE_UI_START_MENU 0xB343            // スタート画面で表示されるUI(の大半)
#define SPRITE_CANDLE_BOX 0xB991               // ろうそくが乗ってる箱
#define SPRITE_PORTRAITS 0xD27A                // 会話などで使う顔アイコン
#define SPRITE_TITLE 0xD353                    // タイトル画面のUI
#define SPRITE_DUNEYRR 0xD3CA                  // ドゥネイル
#define SPRITE_RINGO 0xD3DA                    // 紅のリンゴ (キャラクター)
#define SPRITE_SHAIAN 0xD3EA                   // シャイアン
#define SPRITE_DURATHROR 0xD3FA                // ドゥラスロール
#define SPRITE_DVALINN 0xD40A                  // ドヴァリン
#define SPRITE_UI_LINK 0xDCC1                  // 通信画面で使うUI
#define SPRITE_DJANGO_SABATA 0xDE23            // 主人公
#define SPRITE_UI_SOLAR_SENSOR_HELP 0xDF11     // 太陽センサーのヘルプ画面で使うUI
#define SPRITE_SMITH_MARCELLO 0xDFCE           // スミス, マルチェロ
#define SPRITE_RITA 0xDFDE                     // リタ
#define SPRITE_ZAJI 0xDFEE                     // ザジ
#define SPRITE_SUMIRE 0xDFFE                   // スミレ
#define SPRITE_KURO 0xE00E                     // クロ
#define SPRITE_KID 0xE01E                      // キッド
#define SPRITE_LADY 0xE02E                     // レディ
#define SPRITE_COFFINSELLER_UNKNOWN 0xE03E     // 棺桶屋, "???"(ゲーム内での名前)
#define SPRITE_ENNIO_LUIS 0xE04E               // エンニオ, ルイス
#define SPRITE_CARMILLA 0xE2DE                 // カーミラ(恋人のカード のエフェクト)
#define SPRITE_DAINN 0xE349                    // ダーイン
#define SPRITE_E89F 0xE89F                     // 無幻街の最終階層とかで使うフォント
#define SPRITE_CHANDELIER 0xF099               // 0x2AF0 にもシャンデリアがある
#define SPRITE_WORM 0xD636                     // ワーム系
#define SPRITE_ROD 0xD638                      // Root of Darkness (暗黒の根)
#define SPRITE_SPIDER 0x528F                   // スパイダー
#define SPRITE_BEE BOKHASH("bee")              // 0x9506, ビー
#define SPRITE_CROW 0x5A6E                     // クロウ
#define SPRITE_MUMMY 0x48DE                    // マミー
#define SPRITE_CURORO 0xD28E                   // クロロホルルン
#define SPRITE_PLANT_2567 0x2567               // 多分、ドゥラスロール倒すまで奥の楔の部屋への入り口を塞いでる植物
#define SPRITE_DEBRIS_C42D 0xC42D              // なんかの破片?
#define SPRITE_DEBRIS_0334 0x0334              // C42Dの破片の小さいやつ?
#define SPRITE_EFF_1C1B 0x1C1B                 // エフェクト群(煙、蜘蛛の巣,影)
#define SPRITE_KOMAINU 0xF680                  // 大聖堂の狛犬
#define SPRITE_EXPLOSION 0x8639                // ExplosionManager が使う爆発
#define SPRITE_BOMB 0xE74B                     // 丸い爆弾, エフェクト(煙?), ダイナマイト
#define SPRITE_DOOR_IRON 0x7AD2                // ドア(鉄格子)
#define SPRITE_SLIME BOKHASH("slime")          // 0xB96C, スライム
#define SPRITE_DOOR_LOCKED 0x7AD3              // 鍵のかかった青い扉
#define SPRITE_DOOR_7AEE 0x7AEE                // 扉, どこの扉か忘れた
#define SPRITE_DOOR_7AED 0x7AED                // 鍵のかかった青い扉
#define SPRITE_DOOR_7AF3 0x7AF3                // 扉, どこの扉か忘れた
#define SPRITE_MELEE_SHOCKWAVE 0x8F5D          // 近接攻撃の衝撃波(黒ジャンゴの追加の衝撃波のエフェクト, 武器自体は SPRITE_DJANGO_SABATA が担う), あと太陽鍛治の水桶も一緒に入っている
#define SPRITE_OTENKO_00 BOKHASH("otenko_00")  // 0x97D3, おてんこさま
#define SPRITE_OTENKO_01 BOKHASH("otenko_01")  // 0x97D4, おてんこさま
#define SPRITE_EFF_F422 0xF422                 // エフェクト
#define SPRITE_B306 0xB306                     // 紋章ブロック(炎氷地風)
#define SPRITE_A5B3 0xA5B3                     // 大聖堂の水晶?
#define SPRITE_SPEAKER 0x5AFD                  // シェードマンがクラッシュノイズのときに出すスピーカー
#define SPRITE_5AFE 0x5AFE                     // 輪っかのエフェクト(シェードマン関連?)
#define SPRITE_D4EE 0xD4EE                     // マミー
#define SPRITE_924B 0x924B                     // マミー
#define SPRITE_2C12 0x2C12                     // 鳴り床(上を歩くと音が鳴る床)
#define SPRITE_A20C 0xA20C                     // キラキラエフェクト?
#define SPRITE_9D2D 0x9D2D                     // 壁?
#define SPRITE_048A 0x048A                     // 柱?
#define SPRITE_E1D2 0xE1D2                     // 黒塗り
#define SPRITE_B0E2 0xB0E2                     // 電球
#define SPRITE_C060 0xC060                     // 謎の球
#define SPRITE_DD5C 0xDD5C                     // 壁?
#define SPRITE_4AEE 0x4AEE                     // 壁?
#define SPRITE_ECT BOKHASH("ect")              // 0xA0D5, エクトプラズム
#define SPRITE_CHANDELIER_2AF0 0x2AF0          // シャンデリア
#define SPRITE_TRAP_FLOOR 0xA680               // トラップ床, 水たまり(PLAYER_DARK_DJANGO, PLAYER_MOUSE のときに踏むとダメージ), 鳴り床(踏むと音が鳴る床), 太陽警報機(太陽ゲージが1以上の時に、踏むと音が鳴る床)
#define SPRITE_A6A0 0xA6A0                     // ボクタイ1の血錆の館の中庭の数字が答えになる4つのレバーの上に書いてある数字(不使用?)
#define SPRITE_2D41 0x2D41                     // エフェクト群
#define SPRITE_HINT_PANEL 0xA850               // ヒントパネル
#define SPRITE_9D43 0x9D43                     // なんかのブロック
#define SPRITE_008A 0x008A                     // 瓦礫?
#define SPRITE_76DB 0x76DB                     // 黒塗り
#define SPRITE_COIN 0x2712                     // コイン
#define SPRITE_5DC0 0x5DC0                     // なんかの物体
#define SPRITE_6AF6 0x6AF6                     // キッドの店の内装
#define SPRITE_4AAE 0x4AAE                     // おっさん
#define SPRITE_9FF5 0x9FF5                     // エフェクト群
#define SPRITE_A606 0xA606                     // 黒塗り
#define SPRITE_LILYPAD 0xD166                  // ハスの葉
#define SPRITE_MAGIC_CIRCLE 0x0BA8             // 魔法陣
#define SPRITE_EMOTION_ICONS_0 0x363C          // "!"
#define SPRITE_EMOTION_ICONS_1 0x363D          // EmoteManager が SPRITE_EMOTION_ICONS_0 と一緒に読む
#define SPRITE_1FBD 0x1FBD                     // なんかの壁
#define SPRITE_SAMURAI_ARMOR 0x6AF7            // キッドの店の内装(武者鎧)
#define SPRITE_1B59 0x1B59                     // 扉(鉄格子)
#define SPRITE_7E82 0x7E82                     // ひまわり
#define SPRITE_BCA8 0xBCA8                     // 属性キューブ
#define SPRITE_4384 0x4384                     // エフェクト(地下水路の滝とかの水飛沫?)
#define SPRITE_05A2 0x05A2                     // 大聖堂の(偽物の)墓
#define SPRITE_34C0 0x34C0                     // 大聖堂の水晶をはめる穴あたりの壁?
#define SPRITE_7031 0x7031                     // スライムの破片
#define SPRITE_E857 0xE857                     // 黒塗り
#define SPRITE_BLACKHOLE 0x3641                // ブラックホール(その他の暗黒エフェクトでも流用?)
#define SPRITE_WEDGE 0xF070                    // 封印の楔
#define SPRITE_SOLAR_PLANT 0xC3C3              // 太陽の根(ヒーリングで成長させられるもじゃもじゃ)
#define SPRITE_BED 0x1C84                      // ベッド
#define SPRITE_E505 0xE505                     // 黒塗り
#define SPRITE_FDC5 0xFDC5                     // なんか浮いている岩
#define SPRITE_SIGNBOARD 0x96F7                // サンミゲルのまだ利用できない施設の入り口にある看板
#define SPRITE_COMBO_SCORE 0xA5BD              // ブラックパンサー(ミニゲーム)の"COMBO:", "SCORE:" の文字
#define SPRITE_DOOR_7B0D 0x7B0D                // 鉄の扉(どこで使ってたか忘れた)
#define SPRITE_22E7 0x22E7                     // 黒塗り
#define SPRITE_41B1 0x41B1                     // 果物屋の内装
#define SPRITE_DC8E 0xDC8E                     // 木(太陽樹?, 森?)
#define SPRITE_CDAB 0xCDAB                     // チェンジ・マウスで渡れる木片
#define SPRITE_D962 0xD962                     // タレット封印の扉(地下水路の入り口), 螺旋の塔の入り口, etc
#define SPRITE_B044 0xB044                     // 絨毯
#define SPRITE_3668 0x3668                     // なんかのエフェクト群
#define SPRITE_OJAMA_BAT 0x18A8                // オジャマバット
#define SPRITE_2769 0x2769                     // 接触スイッチ(+電球?)
#define SPRITE_5B78 0x5B78                     // 天窓の光
#define SPRITE_16F5 0x16F5                     // 紋章ブロック
#define SPRITE_848F 0x848F                     // なんかのトゲ飛ばし？
#define SPRITE_8490 0x8490                     // 砂に潜るエフェクト?
#define SPRITE_EF69 0xEF69                     // 暗黒の根
#define SPRITE_5BA7 0x5BA7                     // 天窓の光
#define SPRITE_5BB7 0x5BB7                     // 天窓の光
#define SPRITE_9A1F BOKHASH("start")           // 0x9A1F, "PUSH START BUTTON"の文字(どこで使ってるか不明)
#define SPRITE_C459 0xC459                     // 太陽床
#define SPRITE_DC07 0xDC07                     // 天窓の光
#define SPRITE_SKELETON_MISC 0xD45E            // スケルトン (リッチやアーチャといったスケルトンの派生タイプのスプライト?)
#define SPRITE_D85E 0xD85E                     // エフェクト群(電気っぽい)
#define SPRITE_2817 0x2817                     // 大聖堂の水晶?
#define SPRITE_EFD8 0xEFD8                     // 0..9の数字とまだ何も数字が書かれていないパネルの絵
#define SPRITE_9DFF 0x9DFF                     // 黒塗り
#define SPRITE_TIME_MCIRCLE 0xA152             // タイム魔方陣
#define SPRITE_17C7 0x17C7                     // 重量スイッチ
#define SPRITE_210E 0x210E                     // 弾に見えるが、エフェクトかもしれない
#define SPRITE_1FE0 0x1FE0                     // 黒塗り
#define SPRITE_2C1A 0x2C1A                     // 岩の角みたいな何か
#define SPRITE_SWORD_AX 0x5291                 // ソード(敵)、アックス(敵)
#define SPRITE_5292 0x5292                     // スレイブソード, リンゴ(ダーイン)の出す剣
#define SPRITE_BOKU 0x9247                     // ボク(今作では グール)
#define SPRITE_D4EA 0xD4EA                     // ボク
#define SPRITE_47DE 0x47DE                     // ボク
#define SPRITE_TREADMILL 0xC046                // 暗黒発電機(人が走ることで発電するベルドコンベア)
#define SPRITE_2097 0x2097                     // 四則演算ブロック
#define SPRITE_17C8 0x17C8                     // 重量スイッチ
#define SPRITE_BB68 0xBB68                     // レバースイッチ
#define SPRITE_EED8 0xEED8                     // 砂漠の水汲み場
#define SPRITE_505C 0x505C                     // 料理
#define SPRITE_SOLAR_STATION 0xA47C            // 太陽スタンド
#define SPRITE_DDE7 0xDDE7                     // 天窓の光
#define SPRITE_9E08 0x9E08                     // 天窓の光
#define SPRITE_PANTHER_BONUS 0xA8E7            // ブラックパンサー(ミニゲーム)のボーナス表示
#define SPRITE_44EE 0x44EE                     // なんかのブロックor柱
#define SPRITE_5D7C 0x5D7C                     // 瓦礫
#define SPRITE_B837 0xB837                     // ??
#define SPRITE_E0C9 0xE0C9                     // 鉄ブロック
#define SPRITE_JORMUNGANDR_8203 0x8203         // ヨルムンガンド
#define SPRITE_JORMUNGANDR_8204 0x8204         // ヨルムンガンド
#define SPRITE_WEDGE_8205 0x8205               // ヨルムンガンドの楔
#define SPRITE_JORMUNGANDR_8202 0x8202         // ヨルムンガンドの怪光線 + ヨルムンガンドの楔?
#define SPRITE_JORMUNGANDR_LEG 0x8206          // ヨルムンガンドのタコ足
#define SPRITE_DC38 0xDC38                     // 黒塗り
#define SPRITE_8393 0x8393                     // 黒塗り
#define SPRITE_SOLAR_BAMBOO 0x066A             // 太陽ダケ
#define SPRITE_17C9 0x17C9                     // 重量スイッチ
#define SPRITE_DB6C 0xDB6C                     // 壁?
#define SPRITE_D0A3 0xD0A3                     // カンテラ
#define SPRITE_BEE_NEST_BROKEN 0x9385          // 壊れた蜂の巣
#define SPRITE_BEE_NEST BOKHASH("bee_nest")    // 0xB626, 蜂の巣
#define SPRITE_GHOST 0xD637                    // ゴースト, レイス
#define SPRITE_E7EA 0xE7EA                     // エフェクト
#define SPRITE_DFCF 0xDFCF                     // 棘付き根っこ
#define SPRITE_0E48 0x0E48                     // 螺旋の塔の管理コンソール
#define SPRITE_DC72 0xDC72                     // 木の枝
#define SPRITE_C039 0xC039                     // パイルドライバーの方陣の中心
#define SPRITE_9803 0x9803                     // 黒塗り
#define SPRITE_D56D 0xD56D                     // ??
#define SPRITE_17CA 0x17CA                     // 重量スイッチ
#define SPRITE_SPOTLIGHT 0x3640                // 天窓の光(汎用?, 魔方陣などのエフェクトもこれかも？)
#define SPRITE_9B09 0x9B09                     // 黒塗り
#define SPRITE_D454 0xD454                     // 黒塗り
#define SPRITE_E769 0xE769                     // ワーム系(センチピード, サンドウォーム, サーペント)
#define SPRITE_E76A 0xE76A                     // リッチ+の出す炎の蛇
#define SPRITE_E76B 0xE76B                     // リッチ+の出す炎の蛇
#define SPRITE_MOUSE BOKHASH("rat")            // 0xD495, チェンジマウスで変身するネズミ
#define SPRITE_35C7 0x35C7                     // 黒塗り
#define SPRITE_3B53 0x3B53                     // 黒塗り
#define SPRITE_PINPAD 0x3C13                   // "時の家"の暗証番号設定端末
#define SPRITE_9D3F 0x9D3F                     // "オフセット"(=offset), "20・20"(=32x32) というデバッグ用の文字列がある
#define SPRITE_7C99 0x7C99                     // 各属性のエンブレム(パズルの床に使うデカール?)
#define SPRITE_B019 0xB019                     // elevator lift
#define SPRITE_DA09 0xDA09                     // elevator lift
#define SPRITE_C3BD 0xC3BD                     // elevator lift
#define SPRITE_9462 0x9462                     // elevator lift
#define SPRITE_75D6 0x75D6                     // elevator lift
#define SPRITE_7605 0x7605                     // elevator lift
#define SPRITE_OCTOPUS 0xD291                  // オクトパス
#define SPRITE_D292 0xD292                     // 多分オクトパスが水中にいるときのシルエット
#define SPRITE_7C07 0x7C07                     // 黒塗り
#define SPRITE_FC07 0xFC07                     // 黒塗り
#define SPRITE_BC08 0xBC08                     // 黒塗り
#define SPRITE_GENERATOR 0xC038                // パイルドライバーのジェネレータ
#define SPRITE_1D78 0x1D78                     // 天窓の光と、あと砂っぽい地面?
#define SPRITE_6154 0x6154                     // トーチ?
#define SPRITE_17CB 0x17CB                     // 重量スイッチ
#define SPRITE_BE6D 0xBE6D                     // 黒塗り
#define SPRITE_CC88 0xCC88                     // 散った花びらのように見えるなにか
#define SPRITE_96B5 0x96B5                     // 砂漠の(3つの石版のことが書いてある)石碑
#define SPRITE_2C3D 0x2C3D                     // 3つの石版を探す砂漠で砂漠入り口から1つ上のマップにある干上がったオアシス
#define SPRITE_7BE7 0x7BE7                     // 黒塗り
#define SPRITE_DOG 0xD635                      // 犬
#define SPRITE_E369 0xE369                     // 犬
#define SPRITE_COCKATRICE 0x41CF               // コカトリス
#define SPRITE_43CF 0x43CF                     // コカトリス
#define SPRITE_9D40 0x9D40                     // 木ブロック
#define SPRITE_CUBE_WOOD_DEBRIS_L 0xA874       // 木ブロックの破片(大)
#define SPRITE_CUBE_WOOD_DEBRIS_S 0xA875       // 木ブロックの破片(小)
#define SPRITE_GOLEM 0x5290                    // ゴーレム
#define SPRITE_GUN_SPREAD 0x2110               // ガンデルヘルのスプレッド攻撃
#define SPRITE_COFFIN 0x2499                   // 全ての棺桶(エレファン含む)
#define SPRITE_249A 0x249A                     // 棺桶獣エレファン(自走時?)
#define SPRITE_5B54 0x5B54                     // ダイナマイトで壊せる壁
#define SPRITE_CACTUS 0x04B3                   // サボテン(攻撃で破壊できる小物オブジェ)
#define SPRITE_4FDA 0x4FDA                     // ??
#define SPRITE_863A 0x863A                     // 燃える(爆発?)エフェクト
#define SPRITE_8638 0x8638                     // ??
#define SPRITE_DUNEYRR_AUX 0x61F9              // ドゥネイルの出すエフェクトや芋虫(ドゥネイル本体は別)
#define SPRITE_2058 0x2058                     // 武器屋(シャイアンの店)の内装?
#define SPRITE_DOOR_WOOD 0x7ACD                // ドア(木)
#define SPRITE_DVALIN_2E78 0x2E78              // ドヴァリン
#define SPRITE_2E79 0x2E79                     // ドヴァリン
#define SPRITE_2E7A 0x2E7A                     // ドヴァリン
#define SPRITE_DVALIN_2E7B 0x2E7B              // ドヴァリン
#define SPRITE_2E7C 0x2E7C                     // ドヴァリン
#define SPRITE_CUBE_ROCK 0x9D41                // 岩ブロック
#define SPRITE_CUBE_ROCK_DEBRIS_L 0xA894       // 岩ブロックの破片(大)
#define SPRITE_CUBE_ROCK_DEBRIS_S 0xA895       // 岩ブロックの破片(小)
#define SPRITE_7AC6 0x7AC6                     // 黒塗り
#define SPRITE_CUBE_ICE 0x84EE                 // 氷ブロック
#define SPRITE_494E 0x494E                     // 遺跡ステージ前半の柱
#define SPRITE_7BE2 0x7BE2                     // 黒塗り
#define SPRITE_2EC0 0x2EC0                     // 遺跡ステージの4人の燭台の床パネル?
#define SPRITE_BAT 0xDA6D                      // バット
#define SPRITE_EFF_SHAIAN_SPIN 0x354D          // シャイアンの回転斬りのエフェクト
#define SPRITE_SHAIAN_AX 0x39A3                // シャイアンが投げる斧
#define SPRITE_LVUP_INDICATOR 0x1C1D           // レベルアップのインジケータ
#define SPRITE_GAMEOVER BOKHASH("over")        // 0x654B, "GAMEOVER"
#define SPRITE_B0BC 0xB0BC                     // 重量スイッチ
#define SPRITE_SPIKEBALL 0x24BA                // 棘鉄球
#define SPRITE_PITFALL_A945 0xA945             // 落とし穴
#define SPRITE_70EE 0x70EE                     // 落とし穴
#define SPRITE_6F57 0x6F57                     // 1..12 までの数字パネル(boktai1のアセットが残ってるだけ？)
#define SPRITE_TOWERCLOCK 0x0C0A               // 時計塔の時計
#define SPRITE_DF0E 0xDF0E                     // 暗黒樹の蔓
#define SPRITE_1E15 0x1E15                     // 暗黒樹の芽
#define SPRITE_0DDE 0x0DDE                     // ??
#define SPRITE_84B4 0x84B4                     // 火炎放射?
#define SPRITE_96C1 0x96C1                     // 火炎放射?
#define SPRITE_96C2 0x96C2                     // 炎のエフェクト?
#define SPRITE_0D44 0x0D44                     // 黒塗り
#define SPRITE_MIMIC 0x3876                    // 普通の宝箱も兼ねる

// データが存在しないスプライトのID
#define SPRITE_2117 0x2117  // 多分デバッグ用
#define SPRITE_NODATA_9DA7 0x9DA7

#endif  // __INCLUDE_CONSTANTS_SPRITE_H__
