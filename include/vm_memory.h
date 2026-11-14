#ifndef __INCLUDE_VM_MEMORY_H__
#define __INCLUDE_VM_MEMORY_H__

#include "gba/gba.h"
#include "types.h"

// スクリプトの world 領域, セーブデータに入る, スクリプトだけが使う
typedef struct {
  s16 storyProgress;               // 0x000, ストーリー進行度
  s16 crossoverProgress;           // 0x002, ロックマンエグゼ連動 (クロスオーバー) の進行度
  s16 lastDateYear;                // 0x004, 前回日付を確認した年
  s16 lastDateMonth;               // 0x006, 前回日付を確認した月
  s16 lastDateDay;                 // 0x008, 前回日付を確認した日
  s16 savedPlayerKind;             // 0x00A, 一時的な切り替えやワープの後に戻す PLAYER_KIND
  u8 flags_00c;                    // 0x00C, 棺桶とワープのフラグ
  u8 sensorGuideStep;              // 0x00D, 太陽センサーのガイドの表の読み位置, 項目 × 5 + 項目の中の何ページ目か
  u8 sensorGuidePage;              // 0x00E, 太陽センサーのガイドで表示中のページ (SensorGuide の '.i')
  u8 sensorGuideMode;              // 0x00F, 太陽センサーのガイドの入り方, 0: 起動時の導入, 1: タイトルで放置して自動再生, 2: OPTION の解説から選択
  u8 sensorGuideSelectedTopic;     // 0x010, OPTION の解説で選んだ太陽センサーのガイドの項目
  u8 unk_011;                      // 0x011
  u8 normalDropRate;               // 0x012, 敵の通常ドロップ率 (%), 盗人の服で +20
  u8 rareDropRate;                 // 0x013, 敵のレアドロップ率 (%), 狩人の服で +20
  s32 sensorGuideAutoCount;        // 0x014, タイトルで放置して太陽センサーのガイドを流した回数, 4 で割った余りで次に流す項目を選ぶ
  u8 dungeonChestOpened[5];        // 0x018, ダンジョン内の宝箱を開けたか, 添字は宝箱番号
  u8 lockedDoorOpened[4];          // 0x01D, 鍵付き扉を開けたか, 添字は鍵フラグ番号
  u8 coffinDir;                    // 0x021, 置いてある棺桶の向き
  u8 coffinHoldsDarkDjango;        // 0x022, 1 なら棺桶の中身が黒ジャンゴ (サバタで運ぶ, 時間制限あり)
  u8 coffinTimeMonth;              // 0x023, 棺桶の逃走時間の起点の月
  s16 coffinTimeYear;              // 0x024, 棺桶の逃走時間の起点の年
  u8 coffinTimeDay;                // 0x026, 棺桶の逃走時間の起点の日
  u8 coffinTimeHour;               // 0x027, 棺桶の逃走時間の起点の時
  u8 coffinTimeMinute;             // 0x028, 棺桶の逃走時間の起点の分
  u8 coffinCheckpoint;             // 0x029, 棺桶運搬のチェックポイント番号, 時間経過で減る
  s16 coffinDestX;                 // 0x02A, 棺桶が自力で逃げる目的地の x (チェックポイントのゾーン中心)
  s16 coffinDestZ;                 // 0x02C, 棺桶が自力で逃げる目的地の z
  s16 unk_02e;                     // 0x02E
  s16 unk_030;                     // 0x030
  u8 dungeonFlags[4];              // 0x032, ダンジョン内の仕掛けの進行フラグ, 添字はダンジョンごとに決まる
  u8 dungeonSwitchOn[4];           // 0x036, ダンジョン内のスイッチの状態, 添字はスイッチ番号
  u8 stageVisited[2];              // 0x03A, ステージを調査したか, 添字は StageID (ST_XXX)
  u8 stageCleared[2];              // 0x03C, ステージの調査を完了したか, 添字は StageID (ST_XXX)
  u8 flags_03e[3];                 // 0x03E, bit0 から 5 ビットは不明, bit5 から 12 ビットは称号のフラグ
  u8 exitPosRatio;                 // 0x041, 出口ゾーンでのプレイヤーの位置の割合 (0〜255)
  s16 continueCost;                // 0x042, コンティニュー時に暗黒ローンから払う額
  u8 arenaBossIndex;               // 0x044, 闘技場で次に戦うボスの番号, 14 なら挑戦中でない
  u8 bossAdviceCount;              // 0x045, ボス戦でコンティニューしたときの助言を出した回数
  s16 curseCount;                  // 0x046, 呪われた回数 (総合記録, 最大 9999)
  s16 berserkCount;                // 0x048, 暴走した回数 (総合記録, 最大 9999)
  s16 retryCount;                  // 0x04A, やり直した回数 (総合記録, 最大 9999)
  u8 flags_04c;                    // 0x04C
  u8 rareEnemyKillThreshold;       // 0x04D, レア敵が出るのに必要なその系統の撃破数
  u8 rareEnemyRate;                // 0x04E, レア敵の出現率 (千分率), パレードアーマーで +200
  u8 loanState;                    // 0x04F, 暗黒ローンの返済状態, 0: 借りていない, 5: 返済済み, 6: 督促
  u8 sunCountdownState;            // 0x050, 日の出/日の入りのカウントダウンの表示段階
  u8 flags_051;                    // 0x051
  s16 countdownRemaining;          // 0x052, マップをまたいで引き継ぐカウントダウンの残りフレーム
  s16 prevRoom;                    // 0x054, 1つ前にいた部屋の番号 (ROOM の控え)
  s16 prevPrevRoom;                // 0x056, 2つ前にいた部屋の番号
  u8 unk_058;                      // 0x058
  u8 warehouseLevel;               // 0x059, 倉庫の開放段階, 0: 未開放
  u8 sumireFlags;                  // 0x05A, スミレの会話とイベントのフラグ
  u8 kuroEventStep;                // 0x05B, クロ負傷イベントの段階
  u8 flags_05c;                    // 0x05C
  u8 blackPantherPrize;            // 0x05D, ブラックパンサーの景品のアイテム ID, 0 なら無し
  u8 flags_05e;                    // 0x05E
  u8 flags_05f;                    // 0x05F
  s16 clockFixYear;                // 0x060, エンニオの時計を直した年
  s16 clockFixMonth;               // 0x062, エンニオの時計を直した月
  s16 clockFixDay;                 // 0x064, エンニオの時計を直した日
  s16 clockFixHour;                // 0x066, エンニオの時計を直した時
  s16 clockFixMinute;              // 0x068, エンニオの時計を直した分
  u8 forgeSpecial;                 // 0x06A, 直前の太陽鍛冶の特殊 (special)
  u8 flags_06b;                    // 0x06B
  s16 forgeQuality;                // 0x06C, 直前の太陽鍛冶の品質 (quality)
  s16 forgeGreatCount;             // 0x06E, 直前の太陽鍛冶の大成功 (great) の数
  s16 forgeType;                   // 0x070, 直前の太陽鍛冶でできた武器の種類 (type)
  s16 forgeSkill;                  // 0x072, 直前の太陽鍛冶の腕前 (skill)
  u8 flags_074;                    // 0x074
  u8 flags_075;                    // 0x075
  u8 currentQuest;                 // 0x076, 受けている依頼の番号 (0〜11, 依頼の組 * 3 + 選択)
  u8 flags_077;                    // 0x077
  u8 flags_078;                    // 0x078
  u8 pileDriverState;              // 0x079, パイルドライバー戦の段階
  u8 flags_07a;                    // 0x07A
  u8 blindBoxSpot;                 // 0x07B, ブラインドボックスを置いた位置
  u8 hatenaGiftArea;               // 0x07C, ハテナが持ち物を置いていったエリア
  u8 flags_07d;                    // 0x07D
  u8 blindBoxLevel;                // 0x07E, ブラインドボックスの中身のレベル
  u8 zajiGiftItem;                 // 0x07F, ザジがくれる宝箱のアイテム ID, 0 なら無し
  u8 flags_080;                    // 0x080
  u8 crossoverArmorCount;          // 0x081, クロスオーバーポイントで防具を交換した回数
  u8 valentineFlags[2];            // 0x082, バレンタインのフラグ, 添字は好感度の相手
  u8 catacombsRoom;                // 0x084, 地下墓地で訪ねる部屋, 1: 僕, 2: 岩, 3: 犬, 4: 骨, 5: 鳥
  u8 roomClearedFlags[2];          // 0x085, 地下墓地と宝物庫の部屋をクリアしたか
  u8 crossoverArmorCandidates[6];  // 0x087, 防具交換で渡す防具 ID の候補
  u8 keyDataReceived[4];           // 0x08D, ロックマンエグゼ連動のキーデータ1〜4を受け取ったか
  u8 mugenFloor;                   // 0x091, 夢幻街の現在の階 (1 始まり, 13 以上で最終階)
  u8 mugenBlock;                   // 0x092, 夢幻街で今いる区画 (3x3 の 0〜8)
  u8 mugenSide;                    // 0x093, 区画の中で今いる小部屋の方向, 4 なら区画の通り
  u8 mugenLevel;                   // 0x094, 夢幻街のレベル (クリア回数)
  u8 mugenEntranceBlock;           // 0x095, 夢幻街の入口 (小部屋 7) がある区画
  u8 mugenExitBlock;               // 0x096, 夢幻街の出口 (小部屋 8, 鍵付き扉) がある区画
  u8 mugenBlockMap[9];             // 0x097, 区画ごとの地形, 0: 区画なし, 1〜10: マップの種類
  u8 mugenBlockEvent[9];           // 0x0A0, 区画ごとの仕掛けの種類
  u8 mugenSideRoom[36];            // 0x0A9, 区画の辺ごとの小部屋, 0: なし, 7: 入口, 8: 出口
  u8 mugenSideRoomCount[9];        // 0x0CD, 区画ごとの小部屋の数
  u8 mugenEnemyKind[27];           // 0x0D6, 夢幻街の敵の種類, 添字は区画 * 3 + 枠
  u8 mugenEnemySpawn[27];          // 0x0F1, 夢幻街の敵の出現位置の番号
  u8 mugenEnemyAltParam[27];       // 0x10C, 夢幻街の敵の切り替え先の値
  u8 flags_127;                    // 0x127, 夢幻街の敵の切り替えと番街のフラグ
  u8 mugenRewardArmors[4];         // 0x128, 夢幻街の報酬部屋で出す防具 ID
  u8 mugenRoomContent[36];         // 0x12C, 夢幻街の小部屋の中身, 0: 敵, 1: ソーラースタンド, 3 以降: 宝箱
  u8 questFlags[3];                // 0x150, 依頼を達成したか (bit0〜11) と受注中か (bit12〜23)
  u8 avenueFlags0;                 // 0x153, 番街 (6〜12番街) のイベントフラグ
  u8 avenueFlags1;                 // 0x154, 番街のイベントフラグ
  u8 arenaFlags;                   // 0x155, 闘技場のランク制覇と渓谷のフラグ
  u8 arenaRank;                    // 0x156, 闘技場で選んだランク, 0: 未選択, 1〜4: ブロンズ〜プラチナ
  u8 cathedralFlags0;              // 0x157, 大聖堂のイベントフラグ, bit0 だけ渓谷
  u8 cathedralFlags1;              // 0x158, 大聖堂のイベントフラグ
  u8 cathedralFlags2;              // 0x159, 大聖堂のイベントフラグ
  u8 cathedralFlags3;              // 0x15A, 大聖堂のイベントフラグ
  u8 cathedralFlags4;              // 0x15B, 大聖堂のイベントフラグ
  u8 cathedralFlags5;              // 0x15C, 大聖堂のイベントフラグ
  u8 isekiFlags0;                  // 0x15D, 遺跡のイベントフラグ, bit0〜2 だけ大聖堂
  s16 tastyWaterTimer;             // 0x15E, おいしい水の残りフレーム数
  u8 isekiFlags1;                  // 0x160, 遺跡のイベントフラグ
  u8 isekiFlags2;                  // 0x161, 遺跡のイベントフラグ
  u8 isekiFlags3;                  // 0x162, 遺跡のイベントフラグ
  u8 isekiSlabPieces;              // 0x163, 砂漠のくぼみにはめ込んだ石版のかけらの数, 3 で完成
  u8 isekiFlags4;                  // 0x164, 遺跡のイベントフラグ
  u8 isekiDesertCell;              // 0x165, 砂漠の今の区画, 5x5 の 0〜24
  u8 isekiDesertCellEdge;          // 0x166, 今の区画が砂漠の端のどこか, 3x3 の 0〜8 (4 が中央)
  u8 isekiFragmentFlags[3];        // 0x167, 石版のかけらのフラグと暗黒街のフラグ
  u8 isekiFragmentSpot[4];         // 0x16A, 石版のかけら3つの隠し場所番号
  u8 darkCityFlags1;               // 0x16E, 暗黒街のイベントフラグ
  u8 darkCityFlags2;               // 0x16F, 暗黒街のイベントフラグ
  u8 darkCityFlags3;               // 0x170, 暗黒街のイベントフラグ
  u8 aqueductFlags;                // 0x171, 地下水路のイベントフラグ, bit1〜2 だけ暗黒街
  u8 rasenFlags0;                  // 0x172, 螺旋の塔のイベントフラグ, bit0〜1 だけ約束の丘
  u8 rasenFlags1;                  // 0x173, 螺旋の塔のイベントフラグ
  u8 rasenFlags2;                  // 0x174, 螺旋の塔のイベントフラグ
  u8 rasenBlockDistNS;             // 0x175, 螺旋の塔の壁の暗号が示すブロックの位置の南北の距離 (マス)
  u8 rasenBlockDistEW;             // 0x176, 壁の暗号が示すブロックの位置の東西の距離 (マス)
  u8 rasenBlockDirNS;              // 0x177, 壁の暗号が示す南北の向き, 0: 北, 1: 南
  u8 rasenBlockDirEW;              // 0x178, 壁の暗号が示す東西の向き, 0: 東, 1: 西
  u8 rasenFlags3;                  // 0x179, 螺旋の塔のイベントフラグ
  u8 rasenFlags4;                  // 0x17A, 螺旋の塔のイベントフラグ
  u8 unk_17b;                      // 0x17B
  u8 rasenWarpPosA;                // 0x17C, 螺旋の塔のワープ床の行き来先 A (ワープ先番号, 奇数)
  u8 rasenWarpPosB;                // 0x17D, 螺旋の塔のワープ床の行き来先 B (ワープ先番号, 偶数)
  u8 henFlags0;                    // 0x17E, 変異域のイベントフラグ, bit0 だけ約束の丘
  u8 henFlags1;                    // 0x17F, 変異域のイベントフラグ
  u8 henFlags2;                    // 0x180, 変異域のイベントフラグ
  u8 henFlags3[2];                 // 0x181, 変異域と12番街などのフラグ
  u8 coffinState;                  // 0x183, 棺桶の運搬状態, 0: 運んでいない, 1/2: 運搬中
  s16 unk_184;                     // 0x184
  s16 unk_186;                     // 0x186
  u8 unk_188[2];                   // 0x188
  s16 coffinX;                     // 0x18A, 棺桶が置かれている x
  s16 coffinZ;                     // 0x18C, 棺桶が置かれている z
  s16 coffinRoom;                  // 0x18E, 棺桶が置かれている部屋 (ROOM の値)
  u8 coffinDungeon;                // 0x190, 棺桶のイモータルダンジョン番号 (ステージ ID - 1)
  u8 pileDriverGenStates[4];       // 0x191, パイルドライバーのジェネレーター4基の状態
  u8 unk_195;                      // 0x195
  u8 unk_196;                      // 0x196
  u8 dungeonEventFlags[4];         // 0x197, ダンジョン内の仕掛けとイベントのフラグ
  u8 candleLit[4];                 // 0x19B, 燭台の点灯フラグ, 添字は燭台フラグ番号
  u8 tortureCount;                 // 0x19F, 暗黒ローンのおしおきを受けた回数, 100 で頭打ち
  s32 unk_1a0;                     // 0x1A0
  s32 unk_1a4;                     // 0x1A4
  u8 chestOpened[14];              // 0x1A8, 宝箱を開けたか (bit0〜99) と通信対戦のアイテム配置点のフラグ
  s16 prevBgm;                     // 0x1B6, 直前に流れていた BGM, イベント後に戻す曲
  s16 currentBgm;                  // 0x1B8, 今流れている BGM
  s16 loanYear;                    // 0x1BA, 暗黒ローンを借りた日の年
  s16 loanMonth;                   // 0x1BC, 暗黒ローンを借りた日の月
  s16 loanDay;                     // 0x1BE, 暗黒ローンを借りた日の日
  u8 questEnemyDefeated[5];        // 0x1C0, 依頼の討伐対象を倒したか, 添字は敵番号
  u8 unk_1c5;                      // 0x1C5
  s16 unk_1c6;                     // 0x1C6
  s16 unk_1c8;                     // 0x1C8
  s16 unk_1ca;                     // 0x1CA
  s16 unk_1cc;                     // 0x1CC
  s16 unk_1ce;                     // 0x1CE
  s16 unk_1d0;                     // 0x1D0
  s16 unk_1d2;                     // 0x1D2
  s16 unk_1d4;                     // 0x1D4
  s16 unk_1d6;                     // 0x1D6
  s16 unk_1d8;                     // 0x1D8
  s16 linkPlayerCount;             // 0x1DA, 通信対戦の参加人数
  u8 linkItemWeights[11];          // 0x1DC, 通信対戦でアイテム配置点に出すアイテム 11 種の抽選の重み
  u8 unk_1e7;                      // 0x1E7
  s16 unk_1e8;                     // 0x1E8
  s16 unk_1ea;                     // 0x1EA
  s16 unk_1ec;                     // 0x1EC
  s16 unk_1ee;                     // 0x1EE
  s16 unk_1f0;                     // 0x1F0
  u8 flags_1f2;                    // 0x1F2
  u8 hatenaSmallTalkCount;         // 0x1F3, ハテナの雑談の回数, 偶奇で2種類を交互に話す
  u8 hatenaTitleTalkCount;         // 0x1F4, ハテナの称号会話のカウンタ
  u8 blindBoxArea;                 // 0x1F5, ブラインドボックス (ハテナ) の今のエリア
  u8 timeHousePin[4];              // 0x1F6, 時の家の暗証番号の4桁, 255 なら未設定
  u8 treasurySwitchOn[2];          // 0x1FA, 宝物庫の切り替えスイッチの状態, 添字はスイッチ番号
  s16 unk_1fc;                     // 0x1FC
  u8 sensorGuideState;             // 0x1FE, 太陽センサーのガイド (Scr_SensorGuide) の進行状態 0〜2
  u8 sensorGuideTopic;             // 0x1FF, 再生中の太陽センサーのガイドの項目 (太陽センサーとは / 効果 / 使用上の注意 …), 表の読み位置はこの5倍から
  s16 unk_200;                     // 0x200
  s16 unk_202;                     // 0x202
  s16 linkStage;                   // 0x204, 通信対戦のステージ番号 0〜2
  s16 forgeGood;                   // 0x206, 直前の太陽鍛冶の成功 (good) の回数
  s16 forgeBad;                    // 0x208, 直前の太陽鍛冶の失敗 (bad) の回数
  u8 mugenRewardCount;             // 0x20A, 夢幻街の報酬部屋で報酬を受け取った回数
  u8 flags_20b;                    // 0x20B
  s16 forgeRank;                   // 0x20C, 直前の太陽鍛冶でできた武器のランク
  s16 forgeName;                   // 0x20E, 直前の太陽鍛冶でできた武器の名前 ID
  u8 isekiCoffinCell;              // 0x210, 砂漠で棺桶を置いてきた区画
  u8 unk_211[495];                 // 0x211
} World;
static_assert(sizeof(World) == 1024);

extern World* gWorldBackup;  // 0x03004694, ハード起動時は 0x0203DE00, 特定のタイミング(トランジションや死亡時)で、 gWorld の内容をこっちに反映する, ゲームをセーブする際にはこのデータを EEPROM に書き込む
extern World* gWorld;        // 0x03004698, ハード起動時は 0x0203DA00, ゲームプレイ中はこのデータを参照・更新する

World* FUN_08232260(void);

// スクリプトの scratch 領域, マップを読み込むたびに消える, セーブデータには含まない, スクリプトだけが使う
typedef struct {
  s16 hour;                      // 0x000, 現在の時
  s16 minute;                    // 0x002, 現在の分
  s16 second;                    // 0x004, 現在の秒
  s16 roomBattleBgm;             // 0x006, 閉じ込め戦闘のミッション文を閉じたあとに鳴らす曲, 既定 13
  s32 prevDebts;                 // 0x008, 前回確認したときの暗黒ローンの借金額
  s16 year;                      // 0x00C, 今日の年
  s16 month;                     // 0x00E, 今日の月
  s16 day;                       // 0x010, 今日の日
  s16 elapsedDays;               // 0x012, 前回日付を確認した日からの経過日数
  u8 mapSysFlags;                // 0x014, マップ単位のシステムフラグ
  u8 exitArrowColor;             // 0x015, 出口の矢印の色, 4 以上なら矢印を出さない
  u8 mapFadeColor;               // 0x016, マップの出入りでフェードする色, 0: 黒, 1: 白
  u8 mapSysFlags2;               // 0x017, マップ単位のシステムフラグ2
  s16 mapFadeFrames;             // 0x018, マップの出入りのフェードのフレーム数, 既定 16
  s16 tileAttr;                  // 0x01A, (x, z) のタイル属性, 一時値
  s16 tmpPosY;                   // 0x01C, 汎用の一時座標の y (高さ), 並びは y, x, z
  s16 tmpPosX;                   // 0x01E, 汎用の一時座標の x
  s16 tmpPosZ;                   // 0x020, 汎用の一時座標の z
  s16 zoneCenterX;               // 0x022, Cmd_GetZoneBounds で得たゾーン中心の x
  s16 zoneCenterZ;               // 0x024, ゾーン中心の z
  s16 zoneMinX;                  // 0x026, ゾーンの x の最小
  s16 zoneMaxX;                  // 0x028, ゾーンの x の最大
  s16 zoneMinZ;                  // 0x02A, ゾーンの z の最小
  s16 zoneMaxZ;                  // 0x02C, ゾーンの z の最大
  u8 eventStep;                  // 0x02E, イベント (Cmd_Delay の連鎖) の段階カウンタ
  u8 cutsceneStep;               // 0x02F, 演出 (Scr_Cutscene* など) の段階カウンタ
  s16 currentBgm;                // 0x030, 今鳴らしている BGM の曲番号
  s16 walkTargetX;               // 0x032, 出入口でプレイヤーを自動で歩かせる先の x
  s32 entranceCallback;          // 0x034, 入口からの登場が終わったら呼ぶスクリプト, 0 なら無し
  s16 walkTargetZ;               // 0x038, 出入口でプレイヤーを自動で歩かせる先の z
  s16 exitDir;                   // 0x03A, 出口ゾーンから出ていく向き (1/3/5/7)
  u16 unk_03c;                   // 0x03C
  u8 unk_03e;                    // 0x03E
  u8 unk_03f;                    // 0x03F
  s16 zoneOffsetX;               // 0x040, ゾーンの左端からのプレイヤーの x のずれ
  s16 zoneOffsetZ;               // 0x042, ゾーンの手前端からのプレイヤーの z のずれ
  u8 tileStairs;                 // 0x044, プレイヤー位置のタイルの階段の種類
  u8 spanOfTime;                 // 0x045, 時間帯 (TIMESPAN_*)
  s16 zoneMinY;                  // 0x046, ゾーンの高さの最小 (ゾーンの z1 * 16)
  s16 zoneMaxY;                  // 0x048, ゾーンの高さの最大 (ゾーンの z2 * 16)
  s16 zoneCenterY;               // 0x04A, ゾーンの高さの中心
  s16 mapBgFlags;                // 0x04C, マップの BG の BgMapScrollerFlags
  u8 flags_04e;                  // 0x04E
  u8 unk_04f;                    // 0x04F
  u16 unk_050;                   // 0x050
  u8 fadeSpeed;                  // 0x052, フェード速度, フレーム数の log2
  u8 fadeR;                      // 0x053, フェード色の R (0〜31)
  u8 fadeG;                      // 0x054, フェード色の G (0〜31)
  u8 fadeB;                      // 0x055, フェード色の B (0〜31)
  u8 fadeKind;                   // 0x056, Entity6978 に渡すフェードの種類 (1〜4)
  u8 emblemShutterCount;         // 0x057, 紋章ブロックの仕掛けで開く扉の数 (0〜2)
  u8 emblemLitCount;             // 0x058, 光っている紋章ブロックの数
  u8 emblemRequired;             // 0x059, 扉が開くのに必要な紋章ブロックの数
  u8 emblemOpenStep;             // 0x05A, 紋章ブロックの仕掛けが解けたときの扉を開く演出の段階
  u8 pitfallCount;               // 0x05B, 置いた落とし穴の数, 次の落とし穴の番号になる
  u8 skylightCount;              // 0x05C, 置いたオブジェ天窓の数 (最大 11)
  u8 unk_05d;                    // 0x05D
  s16 enemyDropA;                // 0x05E, 敵が落とす物1, 下位8bit: ID
  s16 enemyDropB;                // 0x060, 敵が落とす物2, 下位8bit: ID
  s16 rolledDrop;                // 0x062, 抽選で決まった落とし物, 外れなら -1
  u8 chestDir;                   // 0x064, 置く宝箱の向き
  u8 chestAutoDir;               // 0x065, 地形から決めた宝箱の向き (0/1)
  s16 chestPosX;                 // 0x066, 地形に合わせて補正した宝箱の x
  s16 chestPosZ;                 // 0x068, 地形に合わせて補正した宝箱の z
  s16 chestSideHeight;           // 0x06A, 宝箱の隣のタイルの高さ, 補正判定用の一時値
  u8 roomLightCount;             // 0x06C, 部屋を照らしている明かりの数, 0 になると部屋を暗くする
  u8 roomLightState;             // 0x06D, 部屋の明るさの状態, 1: 暗い, 2: 明るい
  u8 unk_06e;                    // 0x06E
  u8 unk_06f;                    // 0x06F
  u8 unk_070;                    // 0x070
  u8 flags_071;                  // 0x071
  u8 unk_072;                    // 0x072
  u8 unk_073;                    // 0x073
  u8 unk_074;                    // 0x074
  u8 unk_075;                    // 0x075
  u8 roomBattleKills;            // 0x076, 閉じ込め戦闘で倒した数
  u8 roomBattleTarget;           // 0x077, 閉じ込め戦闘で倒すべき数
  u8 roomBattleShutterCount;     // 0x078, 閉じ込め戦闘用に置いた扉の数 (最大 4)
  u8 roomMissionLine;            // 0x079, 閉じ込め戦闘のミッション文の行
  u16 roomBattleShutterZone[4];  // 0x07A, 閉じ込め戦闘の扉を置いたゾーン ID
  u8 roomBattleClearStep;        // 0x082, 閉じ込め戦闘を終えて扉を開ける演出の段階
  u8 unk_083;                    // 0x083
  s16 bgmBeforeRoomBattle;       // 0x084, 閉じ込め戦闘の前に鳴っていた BGM, 戦闘後に戻す
  u8 unk_086;                    // 0x086
  u8 unk_087;                    // 0x087
  u8 spiritBugWeight0;           // 0x088, 精霊虫の種類0の重み
  u8 spiritBugWeight1;           // 0x089, 精霊虫の種類1の重み
  u8 spiritBugKind;              // 0x08A, 抽選で決まった精霊虫の種類
  u8 unk_08b;                    // 0x08B
  u8 sunGauge;                   // 0x08C, 太陽ゲージの現在値 (変化の検出用)
  u8 prevSunGauge;               // 0x08D, 前のフレームの太陽ゲージ
  u8 unk_08e;                    // 0x08E
  u8 unk_08f;                    // 0x08F
  s16 unk_090;                   // 0x090
  s16 unk_092;                   // 0x092
  s16 unk_094;                   // 0x094
  s16 unk_096;                   // 0x096
  s16 dayDiff;                   // 0x098, Cmd_GetDayDiff の出力, 一時値
  s16 sunriseHour;               // 0x09A, 日の出の時
  s16 sunriseMinute;             // 0x09C, 日の出の分
  s16 untilSunriseHour;          // 0x09E, 日の出までの残り時間 (時)
  s16 untilSunriseMinute;        // 0x0A0, 日の出までの残り時間 (分)
  s16 sunsetHour;                // 0x0A2, 日の入りの時
  s16 sunsetMinute;              // 0x0A4, 日の入りの分
  s16 untilSunsetHour;           // 0x0A6, 日の入りまでの残り時間 (時)
  s16 untilSunsetMinute;         // 0x0A8, 日の入りまでの残り時間 (分)
  u8 clearedRequestCount;        // 0x0AA, 済ませた依頼の数
  u8 requestIdx;                 // 0x0AB, 依頼番号のループ添字
  u8 unk_0ac;                    // 0x0AC
  u8 unk_0ad;                    // 0x0AD
  u8 armorDexCount;              // 0x0AE, 取得済みの防具の数
  u8 armorDexIdx;                // 0x0AF, armorDexCount を数えるループ添字
  u8 weaponDexCount;             // 0x0B0, 取得済みの武器の数
  u8 weaponDexIdx;               // 0x0B1, weaponDexCount を数えるループ添字
  u8 enemyDexCount;              // 0x0B2, 魔物図鑑で出会った敵の数
  u8 enemyDexIdx;                // 0x0B3, enemyDexCount を数えるループ添字
  u8 photoCount;                 // 0x0B4, 取得済みのブロマイドの数
  u8 photoIdx;                   // 0x0B5, photoCount を数えるループ添字
  u8 immortalResearched;         // 0x0B6, 調査済みのイモータルダンジョンの数 (/6)
  u8 undeadResearched;           // 0x0B7, 調査済みのアンデッドダンジョンの数 (/7)
  u8 titleCount;                 // 0x0B8, 獲得した称号の数 (/12)
  u8 enemyArgFlags;              // 0x0B9, 敵を作るときのフラグ
  s16 enemyAtk0Power;            // 0x0BA, 敵の攻撃0の威力
  s16 enemyAtk1Power;            // 0x0BC, 敵の攻撃1の威力
  s16 enemyAtk2Power;            // 0x0BE, 敵の攻撃2の威力
  s16 enemyAtk3Power;            // 0x0C0, 敵の攻撃3の威力
  s16 enemyRange0;               // 0x0C2, 敵の索敵距離
  s16 enemyRange3;               // 0x0C4, 敵の Enemy_SetRanges の第6引数
  s16 unk_0c6;                   // 0x0C6
  s16 enemySleepTime;            // 0x0C8, 敵の眠り時間
  s16 enemyFlags5;               // 0x0CA, 敵の EnemyFlags5 ('.M')
  s16 unk_0cc;                   // 0x0CC
  s16 enemyAtk0Knockback;        // 0x0CE, 敵の攻撃0のふっとばし
  s16 enemyAtkKnockback;         // 0x0D0, 敵の攻撃1以降に共通のふっとばし
  s16 enemyAtk1Iframes;          // 0x0D2, 敵の攻撃1の無敵フレーム
  s32 enemyAtk1Attrs;            // 0x0D4, 敵の攻撃1の HitboxAttributes
  s16 enemyAtk0Attrs;            // 0x0D8, 敵の攻撃0の HitboxAttributes
  s16 enemyAtk0Iframes;          // 0x0DA, 敵の攻撃0の無敵フレーム
  s16 enemyMaxHp;                // 0x0DC, 敵の最大 HP ('.A[0]')
  s16 enemyPower;                // 0x0DE, 敵の体当たりの力 (Enemy.power, '.A[1]')
  s16 unk_0e0;                   // 0x0E0
  s16 enemyAttrs;                // 0x0E2, 敵の食らい判定の属性
  s16 enemyWeakness;             // 0x0E4, 敵の弱点 (Enemy.weakness, '.A[5]')
  s16 enemyChaseTimeMax;         // 0x0E6, 敵の追跡時間の上限
  s16 enemyRange2;               // 0x0E8, 敵の range2 ('.n[0]')
  s16 enemyExp;                  // 0x0EA, 倒したときの経験値 (Enemy.exp, '.X[0]')
  s16 enemyWeaponExp;            // 0x0EC, 倒したときの武器経験値
  u8 unk_0ee;                    // 0x0EE
  u8 enemyVariant;               // 0x0EF, 敵の変種 (Enemy.variant, '.C')
  s16 unk_0f0;                   // 0x0F0
  s16 unk_0f2;                   // 0x0F2
  s16 unk_0f4;                   // 0x0F4
  s16 unk_0f6;                   // 0x0F6
  s16 unk_0f8;                   // 0x0F8
  s16 enemyAtk2Iframes;          // 0x0FA, 敵の攻撃2の無敵フレーム
  s32 enemyAtk2Attrs;            // 0x0FC, 敵の攻撃2の HitboxAttributes
  s32 enemyAtk3Attrs;            // 0x100, 敵の攻撃3の HitboxAttributes
  s16 enemyAtk3Iframes;          // 0x104, 敵の攻撃3の無敵フレーム
  s16 unk_106;                   // 0x106
  s16 unk_108;                   // 0x108
  s16 unk_10a;                   // 0x10A
  u16 unk_10c;                   // 0x10C
  s16 enemyAtk4Power;            // 0x10E, 敵の攻撃4の威力
  s32 enemyAtk4Attrs;            // 0x110, 敵の攻撃4の HitboxAttributes
  s16 enemyAtk4Iframes;          // 0x114, 敵の攻撃4の無敵フレーム
  s16 unk_116;                   // 0x116
  s16 unk_118;                   // 0x118
  s16 tileHeight;                // 0x11A, Cmd_0CD4 で取った (x, z) のタイルの足元の高さ
  u8 unk_11c;                    // 0x11C
  u8 lotteryRoll;                // 0x11D, 抽選用の乱数 0〜99
  s16 nodePosX;                  // 0x11E, Cmd_GetPathNodePos で取った経路ノードの x
  s16 nodePosY;                  // 0x120, 経路ノードの y
  s16 nodePosZ;                  // 0x122, 経路ノードの z
  u8 lotteryWeightSum;           // 0x124, 抽選の重みの累計
  u8 unk_125;                    // 0x125
  u8 mapEventStep;               // 0x126, マップ固有のイベントの段階番号
  u8 pushBackDir;                // 0x127, プレイヤーを押し戻す方向 (8方向 0〜7, 255 で無し)
  u8 sabataTalkToggle;           // 0x128, サバタの2種類の台詞を交互に出すトグル
  u8 lichSummonCycle[3];         // 0x129, リッチのスケルトン召喚枠ごとの召喚する種類
  u8 tortureStep;                // 0x12C, 暗黒ローンのおしおき (発電) の進行段階
  u8 flags_12d;                  // 0x12D
  u8 torturePattern;             // 0x12E, おしおきの発電パターン 0〜3
  u8 unk_12f;                    // 0x12F
  s16 unk_130;                   // 0x130
  s16 spawnAreaMinX;             // 0x132, 敵を湧かせる範囲 (ゾーン) の x の最小
  s16 spawnAreaMinZ;             // 0x134, 敵を湧かせる範囲の z の最小
  s16 spawnAreaMaxX;             // 0x136, 敵を湧かせる範囲の x の最大
  s16 spawnAreaMaxZ;             // 0x138, 敵を湧かせる範囲の z の最大
  u8 unk_13a;                    // 0x13A
  u8 flags_13b;                  // 0x13B
  u16 mapTileMapId;              // 0x13C, 今のマップで読み込んだタイルマップのファイル ID
  u8 bookshelfNo;                // 0x13E, 最後に調べた本棚の番号 1〜10
  u8 flags_13f;                  // 0x13F
  u8 unk_140;                    // 0x140
  u8 unk_141;                    // 0x141
  u8 flags_142;                  // 0x142
  u8 unk_143;                    // 0x143
  s16 unk_144;                   // 0x144
  u8 unk_146;                    // 0x146
  u8 spanOfTime2;                // 0x147, 時間帯, spanOfTime の別の置き場
  u8 unk_148;                    // 0x148
  u8 mapEventStep2;              // 0x149, マップ固有のイベントの段階番号2
  u8 fragmentHintIdx;            // 0x14A, 石版のかけらのヒントの番号
  u8 candleHintLevel;            // 0x14B, 燭台パズルのメッセージの段階 0〜4
  u8 candleMemoReads;            // 0x14C, 燭台パズルのメッセージを読んだ回数
  u8 candleLitCount;             // 0x14D, 灯した燭台の数 0〜4
  u8 candleOrder[4];             // 0x14E, 燭台を灯した順番 (燭台番号 1〜4)
  s16 darkCityBgm;               // 0x152, 暗黒街で鳴らす BGM 番号 29〜33
  u8 unk_154;                    // 0x154
  u8 unk_155;                    // 0x155
  u8 unk_156;                    // 0x156
  u8 unk_157;                    // 0x157
  u8 flags_158;                  // 0x158
  u8 unk_159;                    // 0x159
  u8 unk_15a;                    // 0x15A
  u8 unk_15b;                    // 0x15B
  s16 actorPosX;                 // 0x15C, NPC (Actor) を置く位置 x
  s16 actorPosY;                 // 0x15E, NPC を置く位置 y
  s16 actorPosZ;                 // 0x160, NPC を置く位置 z
  s16 actorAngle;                // 0x162, NPC の向き (角度 0〜255)
  s16 actorInitMode;             // 0x164, NPC の初期状態, 0: 立ち, 1: 非表示, 2: 経路を歩く
  u8 unk_166;                    // 0x166
  u8 unk_167;                    // 0x167
  u8 flags_168;                  // 0x168
  u8 unk_169;                    // 0x169
  u8 unk_16a;                    // 0x16A
  u8 flags_16b;                  // 0x16B
  s16 unk_16c;                   // 0x16C
  s16 unk_16e;                   // 0x16E
  s16 unk_170;                   // 0x170
  u8 unk_172;                    // 0x172
  u8 unk_173;                    // 0x173
  u8 unk_174;                    // 0x174
  u8 unk_175;                    // 0x175
  s16 unk_176;                   // 0x176
  s16 unk_178;                   // 0x178
  u8 zajiSmallTalkCount;         // 0x17A, ザジの雑談2種類を交互に出すカウンタ
  u8 prefectureNo;               // 0x17B, 登録した都道府県の番号
  u8 smithInjuredTalkToggle;     // 0x17C, 負傷中のスミスの台詞を交互に出すトグル
  u8 sumireTownTalkCount;        // 0x17D, 太陽街のスミレの台詞を交互に出すカウンタ
  u8 kuroOutsideTalkToggle;      // 0x17E, 屋外のクロの台詞を交互に出すトグル
  u8 luisTalkCount;              // 0x17F, ルイスの雑談を交互に出すカウンタ
  u8 marcelloTalkCount;          // 0x180, マルチェロの雑談を交互に出すカウンタ
  u8 unk_181;                    // 0x181
  s16 nowMinutes;                // 0x182, 現在時刻を分で表した値 (時 * 60 + 分)
  s16 sunriseMinutes;            // 0x184, 日の出時刻を分で表した値
  s16 sunsetMinutes;             // 0x186, 日の入り時刻を分で表した値
  u8 armorCandidateCount;        // 0x188, クロスオーバー交換の防具候補の数
  u8 ownedArmorPick;             // 0x189, 取得済み防具から1つ選ぶための乱数 (何番目か)
  u8 armorCandidatePick;         // 0x18A, 防具候補 0〜5 から選んだ添字
  u8 ownedArmorIdx;              // 0x18B, 取得済み防具を数えながら走査するカウンタ
  u8 pickedOwnedArmor;           // 0x18C, ownedArmorPick 番目の取得済み防具の ID
  u8 exchangeArmor;              // 0x18D, クロスオーバーポイントと交換で渡す防具の ID
  u8 kuroHouseTalkToggle;        // 0x18E, 家の中のクロの台詞を交互に出すトグル
  u8 sunCityTalkFlags;           // 0x18F, 太陽街の会話用フラグ
  s16 savedPlayerDir;            // 0x190, 会話の前に保存したプレイヤーの向き, 会話のあとで向きを戻す
  u8 unk_192;                    // 0x192
  u8 ritaTalkLoopLen;            // 0x193, リタの台詞ループの長さ (進行度で決まる)
  u8 ritaTalkCount;              // 0x194, リタとの会話の回数
  u8 sumireSmallTalkCount;       // 0x195, スミレの雑談を交互に出すカウンタ
  u8 smithSmallTalkCount;        // 0x196, スミスの雑談を交互に出すカウンタ
  u8 astroWeaponId;              // 0x197, もらうアストロ武器の武器 ID
  u8 licenseEligibleCount;       // 0x198, 熟練度 5000 以上で紋章を持っていない武器タイプの数
  u8 smithLicenseType;           // 0x199, 限定解除の対象の武器タイプ
  u8 licenseTalkCount;           // 0x19A, 限定解除の会話を巡回させるカウンタ
  u8 foundArmorCount;            // 0x19B, 見つけた防具の数
  s16 uptimeDays;                // 0x19C, 総合記録の稼働時間の日
  s16 uptimeMinTens;             // 0x19E, 稼働時間の分の十の位
  s16 uptimeMinOnes;             // 0x1A0, 稼働時間の分の一の位
  s16 playTimeHours;             // 0x1A2, プレイタイムの時 (99 まで)
  s16 playTimeMinutes;           // 0x1A4, プレイタイムの分
  s16 playTimeHourTens;          // 0x1A6, プレイタイムの時の十の位
  s16 playTimeHourOnes;          // 0x1A8, プレイタイムの時の一の位
  s16 playTimeMinTens;           // 0x1AA, プレイタイムの分の十の位
  s16 playTimeMinOnes;           // 0x1AC, プレイタイムの分の一の位
  s16 crossoverPoint;            // 0x1AE, クロスオーバーポイント (記録の表示用)
  s16 crossoverBattleCount;      // 0x1B0, クロスオーバーバトルの対戦数
  s16 crossoverBattleWins;       // 0x1B2, クロスオーバーバトルの勝利数
  s32 clampResult;               // 0x1B4, Scr_ClampValue の作業値, 0..p1 に丸めた値
  s32 msgVarValue;               // 0x1B8, 丸めてからメッセージ変数に入れる値
  u8 treasureRequestPlace;       // 0x1BC, 財宝探しの依頼場所
  u8 treasureRequestNo;          // 0x1BD, 財宝探しの依頼番号 0〜2
  u8 ladyRumorCount;             // 0x1BE, レディの噂話7種類を順に出すカウンタ
  u8 ladySmallTalkCount;         // 0x1BF, レディの世間話を交互に出すカウンタ
  s32 unk_1c0;                   // 0x1C0
  s32 unk_1c4;                   // 0x1C4
  u8 unk_1c8;                    // 0x1C8
  u8 sunTreeStage;               // 0x1C9, 太陽樹の成長段階 0〜6
  s16 ennioClockDays;            // 0x1CA, エンニオの時計合わせから経った日数
  s16 unk_1cc;                   // 0x1CC
  s16 unk_1ce;                   // 0x1CE
  u8 unk_1d0;                    // 0x1D0
  u8 ritaTreeTalkCount;          // 0x1D1, 太陽樹の前でのリタとの会話の回数
  u8 zajiSabataTalkCount;        // 0x1D2, サバタ操作中のザジの台詞を交互に出すカウンタ
  u8 ritaSabataTalkCount;        // 0x1D3, サバタ操作中のリタの台詞を交互に出すカウンタ
  u8 zajiTalkCount2;             // 0x1D4, 別の太陽街マップのザジの台詞を巡回させるカウンタ
  u8 tarotCardCount;             // 0x1D5, 持っているタロットカード (魔術師/教皇/隠者) の枚数
  s16 unk_1d6;                   // 0x1D6
  u8 flags_1d8;                  // 0x1D8, 0x1D8 の bit6 から 2 ビットのビット配列
  u8 residentTalkCount2;         // 0x1D9, ルイスとマルチェロの雑談2を交互に出す共有カウンタ
  s16 unk_1da;                   // 0x1DA
  s16 unk_1dc;                   // 0x1DC
  s16 unk_1de;                   // 0x1DE
  s16 unk_1e0;                   // 0x1E0
  s16 blindBoxPosX;              // 0x1E2, ブラインドボックスを置く位置 x
  s16 blindBoxPosZ;              // 0x1E4, ブラインドボックスを置く位置 z
  u8 blindBoxContent;            // 0x1E6, ブラインドボックスの中身の ID
  u8 unk_1e7;                    // 0x1E7
  u8 unk_1e8;                    // 0x1E8
  u8 unk_1e9;                    // 0x1E9
  u8 unk_1ea;                    // 0x1EA
  u8 unk_1eb;                    // 0x1EB
  u8 unk_1ec;                    // 0x1EC
  u8 unk_1ed;                    // 0x1ED
  u8 flags_1ee;                  // 0x1EE, 2 ビットのビット配列
  u8 pinMatched;                 // 0x1EF, 時の家の暗証番号が一致したか (1: 一致)
  s16 unk_1f0;                   // 0x1F0
  u8 pinDigitIdx;                // 0x1F2, 入力中の暗証番号の桁 0〜3
  u8 pinInput[4];                // 0x1F3, 入力した暗証番号の4桁
  u8 flags_1f7;                  // 0x1F7
  u8 panelMoveLimit;             // 0x1F8, パネル反転パズルの手数の上限
  u8 panelGridWidth;             // 0x1F9, パネル反転パズルの盤面の幅 (3)
  u8 panelMoveCount;             // 0x1FA, パネル反転パズルで押した回数
  u8 unk_1fb;                    // 0x1FB
  u8 unk_1fc;                    // 0x1FC
  u8 unk_1fd;                    // 0x1FD
  s16 unk_1fe;                   // 0x1FE
  s16 unk_200;                   // 0x200
  u8 unk_202;                    // 0x202
  u8 crossoverHelpItem;          // 0x203, クロスオーバーバトルの説明メニューで選んだ項目
  u8 flags_204;                  // 0x204
  u8 unk_205;                    // 0x205
  s16 maxFriendship;             // 0x206, 最も高い FRIENDSHIP の値 (候補を探す途中の最大値)
  u8 unk_208[504];               // 0x208
} Scratch;
static_assert(sizeof(Scratch) == 1024);

extern Scratch* gScratch;  // 0x03004690

#endif  // __INCLUDE_VM_MEMORY_H__
