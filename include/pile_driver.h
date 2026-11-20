#ifndef __INCLUDE_PILE_DRIVER_H__
#define __INCLUDE_PILE_DRIVER_H__

#include "eff_elemcond.h"
#include "entity.h"
#include "gba/gba.h"
#include "hitbox.h"
#include "msgbus.h"
#include "particle.h"
#include "sprite_animation.h"
#include "sprite_aux.h"
#include "tilemap.h"
#include "types.h"

struct Generator;
struct Player;
struct Coffin;

struct PileDriver;
typedef void(PileDriverFunc)(struct PileDriver* p);

// Ectoplasm.state, sEctoplasmStates の添字
#define ECTOPLASM_STATE_HIDDEN 0           // 出ていない, 15 枚とも隠す
#define ECTOPLASM_STATE_APPEAR 1           // home (棺桶) から浮かび上がる
#define ECTOPLASM_STATE_IN_COFFIN 2        // 棺桶の中で太陽を浴び, ライフの減りが 4 倍になる
#define ECTOPLASM_STATE_ORBIT 3            // home の周りを漂う
#define ECTOPLASM_STATE_GO_TO_GENERATOR 4  // targetGenerator へ向かう
#define ECTOPLASM_STATE_DRAIN_GENERATOR 5  // 取りついたジェネレーターを 90 フレームで止める
#define ECTOPLASM_STATE_RETURN_HOME 6      // home へ吸い込まれて消える
#define ECTOPLASM_STATE_KNOCKBACK 7        // 攻撃を受けて吹き飛ぶ
#define ECTOPLASM_STATE_RECOVER 8          // 吹き飛んだあと duration フレーム止まる
#define ECTOPLASM_STATE_VANISH 9           // 煙を出して消える

// PileDriver.subState, sSubStates の添字
#define PILEDRIVER_SUB_WAIT_COFFIN 0         // 棺桶が魔方陣の中心へ引かれてくるのを待つ
#define PILEDRIVER_SUB_PLACE_COFFIN 1        // 棺桶を置く
#define PILEDRIVER_SUB_WAIT_GENERATORS 2     // ジェネレーターが全部 state 2 になるのを待つ
#define PILEDRIVER_SUB_WAIT_GENERATOR_LIT 3  // ジェネレーターのどれかが稼働するのを待つ
#define PILEDRIVER_SUB_WAIT_ACTIVATION 4     // 1P がパイルドライバーを起動するのを待つ
#define PILEDRIVER_SUB_ACTIVATE 5            // 起動の演出, 7 か 6 へ進む
#define PILEDRIVER_SUB_SHUTDOWN 6            // ジェネレーターを止めて 3 に戻る
#define PILEDRIVER_SUB_POWER_UP 7            // スクリプト 3 を起動して画面を揺らす
#define PILEDRIVER_SUB_OPEN_COFFIN 8         // 棺桶を開ける
#define PILEDRIVER_SUB_WAIT_COFFIN_OPEN 9    // 棺桶が開ききるのを待ってエクトプラズムを出す
#define PILEDRIVER_SUB_BATTLE_DRIVE 10       // バトルドライブ中
#define PILEDRIVER_SUB_CLOSE_COFFIN 11       // エクトプラズムが消えたら棺桶を閉じる
#define PILEDRIVER_SUB_WAIT_RETRY 12         // 棺桶を魔方陣の中心へ引き直せば 1 からやり直し, 遠くへ運び出すと 13
#define PILEDRIVER_SUB_LEAVE 13              // 棺桶を運び出したあとの演出
#define PILEDRIVER_SUB_END 14                // 何もしない

// AuxSprite と専用の AuxSpriteGfx に, 色を混ぜるためのパレットと 130 フレーム周期のポーズ用カウンタを足した一式
typedef struct {
  AuxSprite sprite;  // 0x00
  AuxSpriteGfx gfx;  // 0x2C
  rgb555 pltt[16];   // 0x48, 時間帯の切り替え中に gfx.pltt をここへ向けて, 2つの時間帯の色を混ぜたものを入れる
  bool16 active;     // 0x68, 0 なら sprite を使っていない
  u16 pose;          // 0x6A, animTimer から決まる 0〜3
  u16 unk_6c;        // 0x6C
  u16 animTimer;     // 0x6E, 129 を越えると 0 に戻る
} PileDriverAnimSprite;
static_assert(sizeof(PileDriverAnimSprite) == 112);

// PileDriverParticleSet が 32 個持つ粒子の枠, PileDriver_SpawnParticle が空きを順に使い, PileDriver_UpdateParticles が vel で動かす
typedef struct {
  Particle ptcl;  // 0x00, PTCL_GROUP_2
  Vec3 vel;       // 0x28, 毎フレーム ptcl.pos に足す
  bool8 active;   // 0x30
  u8 timer;       // 0x31, 出してからのフレーム数, 6 でポーズを変える
  u8 lifetime;    // 0x32, timer がこれに達すると隠して空ける
  u8 unk_33;      // 0x33, padding?
} PileDriverParticle;
static_assert(sizeof(PileDriverParticle) == 52);

// PileDriver の 0x0560 にある粒子 32 個, 3つの関数がここを起点に触る
typedef struct {
  ParticleGroup* group;          // 0x000, PTCL_GROUP_2
  PileDriverParticle ptcls[32];  // 0x004
  bool8 active;                  // 0x684, ptcls のどれかが動いていれば 1
  u8 next;                       // 0x685, 次に使う ptcls の添字, 0..31 を巡回する
  u8 unk_686[2];                 // 0x686
} PileDriverParticleSet;
static_assert(sizeof(PileDriverParticleSet) == 1672);

// Ectoplasm (エクトプラズム) の体を作る 15 枚のスプライト, [0] / [1..8] / [9..14] をそれぞれ別の関数が動かす
typedef struct {
  AuxSprite sprite;       // 0x00
  AuxSpriteGfx gfx;       // 0x2C, "ect"
  AuxAnimState anim;      // 0x48
  AuxAnimFile* animFile;  // 0x58, "ect_anm"
  u8 unk_5c[8];           // 0x5C
  u16 pulsePhase;         // 0x64, 作るときに乱数で 0..255, 中心からの距離を脈打たせる位相
  u16 angle;              // 0x66, 中心から見た向き (0..255), 作るときに添字 × 32
} EctoplasmPart;
static_assert(sizeof(EctoplasmPart) == 104);

// バトルドライブで棺桶から出てくるイモータルのエクトプラズム (攻略本の呼び名), PileDriver の 0x0C6C に載り mode が 1 のときに使う
// 棺桶 (home) の周りを漂ってジェネレーターに取りつき, 攻撃を受けると吹き飛び, 棺桶に押し戻されると太陽パイルでイモータルのライフ (gStat->bossHP) が大きく減る
// state は Ectoplasm_SetState が切り替え, PileDriver_UpdateEctoplasm が sEctoplasmStates[state] を呼ぶ
typedef struct {
  EctoplasmPart parts[15];   // 0x000
  Vec3 pos;                  // 0x618
  Hitbox hurtbox;            // 0x620, 攻撃を受けると Ectoplasm_OnHurt が knockbackAngle / knockbackSpeed を入れる
  Vec3 home;                 // 0x670, 棺桶の位置で漂う中心, PileDriver.coffinPos から x と z を -0x20 ずらした位置
  u16 state;                 // 0x678, sEctoplasmStates の添字, 2 は棺桶の中にいる状態でライフの減りが 4 倍になる
  u16 timer;                 // 0x67A, state 8 で毎フレーム +1 して duration と比べる
  u16 orbitAngle;            // 0x67C, home から見た向き, 下位4ビットが小数で 0xFFF で折り返す
  s16 orbitSpeed;            // 0x67E, orbitAngle に毎フレーム足す, orbitSpeedTarget へ 1 ずつ近づく
  s16 orbitSpeedTarget;      // 0x680, ±(12..19) を乱数で選ぶ
  u16 orbitSpeedTimer;       // 0x682, 0 になると orbitSpeedTarget を選び直す
  u16 orbitRadius;           // 0x684, home からの距離, 毎フレーム orbitRadiusTarget へ 1/16 ずつ近づく
  u16 orbitRadiusTarget;     // 0x686, 0xC0..0x1BF を乱数で選ぶ
  u16 orbitRadiusTimer;      // 0x688, 0 になると orbitRadiusTarget を選び直す
  u16 hurtboxDelay;          // 0x68A, 0 でない間 hurtbox に HBF_HIDDEN を立てて毎フレーム減らす
  u8 wobblePhase;            // 0x68C, 周回の位置に足す揺れ (振れ幅 32) の位相
  u8 knockbackAngle;         // 0x68D, 攻撃を受けた向き
  u16 knockbackSpeed;        // 0x68E, 吹き飛ぶ速さ, 攻撃の種類と攻撃力の差で決まり 200 で頭打ち
  u16 duration;              // 0x690, timer の上限, 攻撃の種類で決まる
  s8 targetGenerator;        // 0x692, 取りつきに行くジェネレーターの添字, Ectoplasm_PickTargetGenerator が稼働中 (state 4) のものから選ぶ, いなければ -1
  u8 unk_693[3];             // 0x693
  u16 drainFrac;             // 0x696, ライフを削る量の端数, 40 たまるごとに gStat->bossHP (イモータルのライフ) を 1 減らす
  u16 targetTimer;           // 0x698, 600 から 2 ずつ減らし, 3 を切ると targetGenerator を選び直す
  u8 unk_69a[2];             // 0x69A
  Vec3 smokeSize;            // 0x69C, state 2 と 5 で pos に出す煙の大きさ, 3成分とも 0xA0
  Vec3 homeSmokeSize;        // 0x6A4, state 3〜5 と 7 で home に出す煙の大きさ {0x40, 0x20, 0x40}
  struct PileDriver* owner;  // 0x6AC
} Ectoplasm;
static_assert(sizeof(Ectoplasm) == 1712);

// パイルドライバー という 複数の 太陽ジェネレータ (struct Generator) の照射でイモータルを浄化するゲームのギミック のシーンEntity
typedef struct PileDriver {
  Entity e;                           // 0x0000, ENTITY_UNK_9
  u16 id;                             // 0x0018, 0xCBB0 (PileDriver_Create)
  u16 mode;                           // 0x001A, '.m=0', 1 なら棺桶を浄化する場面で ectoplasm とタイルマップを使う
  u8 unk_1c[2];                       // 0x001C
  u8 generatorCount;                  // 0x001E, '.n=4', generators の使う数
  u8 activeGeneratorCount;            // 0x001F, state 4 (稼働中) のジェネレーターの数, PileDriver_Update が毎フレーム数え直す
  rgb555 bgPltts[16][16];             // 0x0020, 時間帯の色を混ぜた BG パレット, bgPlttIdx で選んで gBgPlttBuffer へ送る
  rgb555* timePltts[3];               // 0x0220, 昼 / 夕 / 夜の BG パレット ('.A' か "pile_driver_*_col_arr")
  u8 plttFadeFrom;                    // 0x022C, 時間帯が変わったときに混ぜる元の timePltts の添字
  u8 plttFadeTo;                      // 0x022D, 同じく先の添字
  u16 stateTimer;                     // 0x022E, PileDriver_SetState が updateCallback の差し替えのたびに 0 に戻す
  u16 bgPlttIdx[16];                  // 0x0230, BG パレットの行ごとに送る bgPltts の添字
  PileDriverFunc* updateCallback;     // 0x0250
  PileDriverAnimSprite centerSprite;  // 0x0254, SPR_C039, 魔方陣の中心, sunOverride が立っていると出さない
  u8 unk_2c4[0x4D4 - 0x2C4];          // 0x02C4
  TilemapFile* immortalTilemap;       // 0x04D4, sImmortalTilemaps[immortalIdx], BG1 に半透明で重ねるイモータルの姿
  rgb555* immortalPltt;               // 0x04D8, BGP_F308 の body[192] から 16 色, immortalTilemap のパレット
  TilemapFile* unk_4dc;               // 0x04DC, MP_AD57
  rgb555* plttSrc;                    // 0x04E0, 点滅用のパレット4組の先頭
  u8 beamKinds[4];                    // 0x04E4, ジェネレーターごとの光の柱の描き方, 0 は光っている (MP_AD57 のレイヤ 1), 5 は消す, PileDriver_InitTilemap が 5 を入れる
  u8 drawnBeamKinds[4];               // 0x04E8, 最後に BG3 へ描いた beamKinds, 変わったときだけ描き直す
  u16 plttTimer;                      // 0x04EC, 奇数フレームごとに plttSrc の組を差し替える
  u8 unk_4ee[6];                      // 0x04EE
  struct Player* player;              // 0x04F4, gPlayerPtr[0]
  struct Coffin* coffin;              // 0x04F8, gCoffin
  u16 subState;                       // 0x04FC, PileDriver_Update が sSubStates[subState](p) として引く
  u16 subStateTimer;                  // 0x04FE, PileDriver_SetSubState が subState の差し替えのたびに 0 に戻す
  Vec3 center;                        // 0x0500, '.c', 魔方陣の中心
  Vec3 unk_508;                       // 0x0508, center から x と z を 0x144 ずらした位置, FUN_080b10f8 がプレイヤーとの距離を見る
  WorldPos coffinPos;                 // 0x0510, center から x と z を -0x14 ずらした位置, 棺桶を置く場所 (魔方陣の中心)
  AuxSprite blackhole;                // 0x0518, 棺桶の上 (coffinPos から y を 72 上げた位置) で点滅するブラックホール
  AuxSpriteGfx blackholeGfx;          // 0x0544, SPR_BLACKHOLE
  PileDriverParticleSet ptclSet;      // 0x0560
  struct Generator* generators[4];    // 0x0BE8
  u16 damageRate;                     // 0x0BF8, 太陽パイルの攻撃力 (イモータルのライフを削る量) の倍率 (%), 棺桶の種類で決まりヴァンパイアの棺 80 / アイアンメイデン 120 / それ以外 100
  u8 unk_bfa[0xC0B - 0xBFA];          // 0x0BFA
  u8 timeSpan;                        // 0x0C0B, Time_GetSpanOfTime の値, 変わると plttFadeFrom / plttFadeTo を決め直す
  u8 unk_c0c[3];                      // 0x0C0C
  bool8 sunOverride;                  // 0x0C0F, '.d=0', 立っていると sunGauge に gStat->sunGauge でなく sunOverrideValue を使う
  u8 sunGauge;                        // 0x0C10, 今の太陽ゲージ
  u8 sunOverrideValue;                // 0x0C11
  bool8 unk_c12;                      // 0x0C12, Cmd_F993 / Cmd_44BF が 1 / 0 を入れ, FUN_080b176c が見る
  u8 unk_c13[3];                      // 0x0C13
  u16 placeKind;                      // 0x0C16, 棺桶をどこから置いたか, 0 最初 (subState 0) / 1 置き直し (subState 3) / 2 やり直し (subState 12), PileDriver_PlaceCoffin が置き終えたあとの進み先を決める
  u8 unk_c18[0xC6C - 0xC18];          // 0x0C18
  Ectoplasm ectoplasm;                // 0x0C6C
  u8 unk_131c[8];                     // 0x131C
  u16 immortalBgTimer;                // 0x1324, BG1 のイモータルの姿の演出のフレーム数, ライフがある間は光らせる残り (PileDriver_FlashImmortal が 48), 0 のあとは 0..63 で巡回, immortalVanishing の間は消えるまでの残り (Cmd_054A が 64)
  s16 immortalBgShakeY;               // 0x1326, BG1 のイモータルの姿の縦の揺れ (vofs に足す), 0..7
  u8 unk_1328[2];                     // 0x1328
  u8 unk_132a;                        // 0x132A, PileDriver_DrawBeams が 0 に戻す
  u8 unk_132b[7];                     // 0x132B
  u8 unk_1332;                        // 0x1332, FUN_080b165c が 0 に戻す
  bool8 unk_1333;                     // 0x1333, Cmd_29F1 が立て, FUN_080b1718 が見る
  u16 unk_1334;                       // 0x1334, Cmd_29F1 が 0 に戻す
  u8 immortalIdx;  // 0x1336, '.b[0]=0', どのイモータルか, タイルマップ (sImmortalTilemaps) と声 (voices) とバトルドライブの攻撃を選ぶ, 0 ドゥネイル (燐粉) / 1 黒ジャンゴ (攻撃なし) / 2 ドゥラスロール (棘) / 3 ドヴァリン (バブルブレス) / 4 ダーイン (クロロホルルン+) / 5 シェードマン (クラッシュノイズ)
  u8 unk_1337[7];  // 0x1337
  bool8 voicePending;              // 0x133E, エクトプラズムが棺桶に入ったときと消え始めたときに立ち, 次の PileDriver_Update でイモータルの声と SE_667 を鳴らして下ろす
  u8 voiceIdx;                     // 0x133F, voicePending で鳴らす voices の添字 (ライフが 0 なら [2])
  SoundID16 voices[4];             // 0x1340, イモータルの声, [0] 棺桶に入ったとき (熱い!) / [1] ライフが 1/4 を切ったあとの [0] の代わり / [2] ライフが 0 のとき / [3] 棺桶を運び出したあと (笑い声)
  u16 attackTimer;                 // 0x1348, バトルドライブの攻撃の合間の経過フレーム, attackDuration に達するまで毎フレーム +1 し, 達すると fireTimer で撃ち始める
  u16 attackDuration;              // 0x134A, 攻撃の合間のフレーム数
  u16 fireTimer;                   // 0x134C, 撃ち始めてからのフレーム数, 終わると attackTimer を 0 に戻す
  u16 attackPower;                 // 0x134E, '.T=10', バトルドライブでイモータルが撃つ弾の攻撃力
  u8 unk_1350[2];                  // 0x1350
  u16 attackAngle;                 // 0x1352, 弾を撃つ向き, center から 1P への向きで決める
  u8 unk_1354[8];                  // 0x1354
  PileDriverFunc* attackCallback;  // 0x135C, バトルドライブでのイモータルの攻撃, immortalIdx で決まり PileDriver_RunAttack が毎フレーム呼ぶ
  void* attackManager;             // 0x1360, 攻撃の弾をまとめるエンティティ, immortalIdx が 2 ならドゥラスロールの棘 (Entity0805d79c), 4 なら CuroroShotManager, 5 なら CrashNoiseRingManager
  u8 unk_1364[0x10];               // 0x1364
  bool16 immortalVanishing;        // 0x1374, Cmd_054A が立て, BG1 のイモータルの姿が粒子を撒いて消えていく
  u8 unk_1376[0x1420 - 0x1376];    // 0x1376
  u32 unk_1420;                    // 0x1420, FUN_080adb5c が 0 に戻す
  u16 plttFadeTimer;               // 0x1424, 時間帯の色を混ぜ始めてからのフレーム数, 0x40 で混ぜ終わる
  bool16 plttFading;               // 0x1426, 時間帯が変わると立てて混ぜ始める
  bool16 bgPlttDirty;              // 0x1428, 立っていると PileDriver_UpdateBgPltt が bgPltts を gBgPlttBuffer へ送って下ろす
  u8 unk_142a[0x17A4 - 0x142A];    // 0x142A
  u32 eventScriptID;               // 0x17A4, '.p', 段階 (kind) を引数に起動するスクリプト
  MsgQueue mq;                     // 0x17A8
} PileDriver;
static_assert(sizeof(PileDriver) == 6108);

extern PileDriver* gPileDriver;  // 0x03002C58

// --------------------------------------------

// 太陽ジェネレーター
// パイルドライバーで使う装置で、太陽の光をビームとして出してイモータルを攻撃する装置, イモータルに攻撃されるとオフになるが、プレイヤーがエンチャント攻撃を当てると再びオンになる
// 太陽ジェネレーターから出るビームは太陽パイルとも呼ばれる
typedef struct Generator {
  Entity e;                                   // 0x000, ENTITY_UNK_8
  AuxSprite sprite;                           // 0x018, ->gfx
  AuxSpriteGfx gfx;                           // 0x044, SPR_GENERATOR
  Vec3 pos;                                   // 0x060, Generator_Create の第1引数を8バイト複写したもの,Hitbox_SetPos に渡す
  Hitbox hurtbox;                             // 0x068, Generator_InitHurtbox が Hitbox_Init / _SetPowerAndAttributes / _SetPos / _SetHandler する
  AuxAnimState anim;                          // 0x0B8, ANIM_PILE, animIdx は 1 or 3
  AuxAnimFile* animFile;                      // 0x0C8, ANIM_PILE
  u8 animVariant;                             // 0x0CC
  AuxAnimPlayFlags animFlags;                 // 0x0CD
  u8 unk_ce;                                  // 0x0CE, Generator_Init の第6引数,読み手が見つかっていない
  u8 state;                                   // 0x0CF, Generator_SetState が書き、 sGeneratorUpdates[state] を updateCallback に入れる,3 で GENERATOR_ENABLED, 5 で GENERATOR_DISABLED を鳴らす
  u16 stateTimer;                             // 0x0D0, Generator_SetState が状態遷移のたびに 0 に戻す
  u16 unk_d2;                                 // 0x0D2, Init が 0、state が 4 のときは anim の先頭ハーフワードを入れる
  u16 unk_d4;                                 // 0x0D4, Generator_Init の第7引数
  u8 unk_d6[2];                               // 0x0D6
  s16 unk_d8;                                 // 0x0D8, Div(unk_d4, 6)
  u16 unk_da;                                 // 0x0DA, Init が 0,_Update が 0 まで減らす
  u16 unk_dc;                                 // 0x0DC, Generator_Init の第9引数,読み手が見つかっていない
  s16 unk_de;                                 // 0x0DE, state 6 (FUN_080b31b4) が 0 まで減らし, 0 になると state 2 に戻る
  u16 unk_e0;                                 // 0x0E0, _Update が 0 まで減らす
  u16 unk_e2;                                 // 0x0E2, 0 でない間 Generator_UpdateFlash が flashTimer を増やし、その後 0 に戻す
  u16 flashTimer;                             // 0x0E4, 12 でパレット 455, 1〜11 で 454, 0 で plttID に戻る
  u8 unk_e6[2];                               // 0x0E6
  u16 unk_e8;                                 // 0x0E8, gPileDriver->sunGauge が 0 でなく、かつ state が 4 のときだけ減る
  u8 unk_ea;                                  // 0x0EA, Init が 0,読み手が見つかっていない
  u8 unk_eb;                                  // 0x0EB, 0 でない間 Generator_UpdateFlash がパレット 0x132 を強制して減らす
  bool8 justStarted;                          // 0x0EC, 起動が終わって state 4 に入ると 1, PileDriver_WaitActivation が音と BG パレットの演出を出して 0 に戻す
  u8 unk_ed;                                  // 0x0ED
  u16 plttID;                                 // 0x0EE, 451 or 452
  u16 unk_f0;                                 // 0x0F0, 点灯時のパレットID
  bool16 unk_f2;                              // 0x0F2, 0 でない間は稼働中
  u16 unk_f4;                                 // 0x0F4, 次に音を鳴らす残り時間
  u8 unk_f6[3];                               // 0x0F6
  u8 unk_f9;                                  // 0x0F9, 0 まで減らすだけのカウンタ
  u8 unk_fa[6];                               // 0x0FA
  ElementalCondEmitter condEmitter;           // 0x100
  void (*updateCallback)(struct Generator*);  // 0x238
} Generator;
static_assert(sizeof(Generator) == 572);

void Generator_SetState(Generator* p, s32 state);
Generator* Generator_Create(Vec3* pos, s32 param_2, s32 param_3, s32 state, s32 param_5, s32 param_6, u32 power, s32 param_8);

#endif  // __INCLUDE_PILE_DRIVER_H__
