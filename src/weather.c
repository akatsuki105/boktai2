#include "entity.h"
#include "global.h"
#include "particle.h"
#include "types.h"

// 雨粒1つ。ptcl を1個ずつ持ち、pos[2] を毎フレーム入れ替えながら ptcl.pos へ写す
typedef struct {
  bool8 active;   // 0x00, WeatherManager_UpdateParticles と WeatherManager_RemoveParticles が 0 以外の要素だけ処理する。WeatherManager_SpawnParticles が空きスロットを探すのにも使う
  u8 timer;       // 0x01, WeatherManager_UpdateParticles が毎フレーム +1 し、3 以上で phase を進める
  u8 phase;       // 0x02, 0 で出現待ち、1 で消滅待ち
  u8 posIdx;      // 0x03, 0 と 1 を毎フレーム反転させ、pos[posIdx] を ptcl.pos へ写す
  Vec3 pos[2];    // 0x04, WeatherManager_SpawnParticles がプレイヤー位置 ±0x800 の乱数で埋める
  Particle ptcl;  // 0x14, FUN_0822da70 / Particle_SetOffset / Particle_Remove に渡す
} WeatherParticle;
static_assert(sizeof(WeatherParticle) == 60);

// BG1 にタイルマップ 0xEA77 を敷いて2段階の速度でスクロールさせ、同時に雨粒のパーティクルを32個ばら撒く
// gStat->sunGauge と gStat->unk_2d0 を見て継続と終了を決める
typedef struct {
  Entity e;                   // 0x00, ENTITY_UNK_9
  u8 unk_18;                  // 0x18, WeatherManager_SetState が state を変えるときに 1 にする
  u8 state;                   // 0x19, PTR_ARRAY_085aa948[5] の添字。2 以上で WeatherManager_ScrollClouds (BGスクロール) が回り、3 で gStat の 0x946 が 0x7FFF になる
  u8 unk_1a[2];               // 0x1A
  s32 stateTimer;             // 0x1C, WeatherManager_SetState が state を変えるときに 0 に戻す
  u16 timer;                  // 0x20, FUN_08018324 が 0 になるまで毎フレーム減らし、0 で WeatherManager_ResetTimer が詰め直す
  u8 unk_22;                  // 0x22, VM '.a' (既定 1)
  u8 unk_23;                  // 0x23
  u16 sunAccum;               // 0x24, 状態に入るとき 0 にし、以降 gStat->sunGauge を毎フレーム足す。0x3C 以上で天候を切り上げる
  u16 unk_26;                 // 0x26
  u16 unk_28;                 // 0x28, VM '.i' の1つ目 (既定 0x1C20 = 7200フレーム)。s32_03000080 の下限に使う
  u16 unk_2a;                 // 0x2A, VM '.i' の2つ目 (既定 0xE10 = 3600)。0 でなければ rand % これを s32_03000080 に足す
  u16 timerBase;              // 0x2C, VM '.t' の1つ目 (既定 300)。WeatherManager_ResetTimer が timer に入れる基準値
  u16 timerRand;              // 0x2E, VM '.t' の2つ目。timer に足す乱数の範囲。合計が 10 未満なら 10 にする
  s16 unk_30;                 // 0x30, VM '.r' の1つ目 (既定 0x40)。WeatherManager_GetChance が unk_32 * unk_30 >> 6 を作る
  s16 unk_32;                 // 0x32, VM '.r' の2つ目
  s32 scrollX[2];             // 0x34, WeatherManager_ScrollClouds が [0] に 3 + drift、[1] に 6 + drift を毎フレーム足す。Video_GenerateBGMap の X オフセット
  s32 scrollY[2];             // 0x3C, WeatherManager_ScrollClouds が [0] から 8 + drift、[1] から 0x10 + drift を毎フレーム引く
  s32 drift;                  // 0x44, 16フレームごとに driftTarget へ1ずつ寄せる。スクロール速度の揺らぎ
  s32 driftTarget;            // 0x48, 乱数 -4..3 (Init) / -1..6 (WeatherManager_ScrollClouds)
  s32 driftTimer;             // 0x4C, 0 になったら driftTarget を引き直す。乱数 0x80..0xFF
  s32 layer;                  // 0x50, scrollX / scrollY のどちらの組を Video_GenerateBGMap に渡すかの添字
  s32 unk_54;                 // 0x54, VM '.C' (既定 0)
  s32 unk_58;                 // 0x58, VM '.O' (既定 0)
  s32 frameCounter;           // 0x5C, WeatherManager_Update が毎フレーム +1。WeatherManager_ScrollClouds が下位4bitと下位1bitで分岐する
  s16 unk_60;                 // 0x60, WeatherManager_InitParticles が 0 にする。WeatherManager_SpawnParticles は 0 のときだけ要素を作る
  s16 unk_62;                 // 0x62, WeatherManager_InitParticles が 0 にする
  u8 unk_64[0x164 - 0x64];    // 0x64, この 256 バイトに触る関数が見つかっていない
  ParticleGroup* group;       // 0x164, GetParticleGroup(GROUP_1)
  WeatherParticle ptcls[32];  // 0x168
} WeatherManager;
static_assert(sizeof(WeatherManager) == 2280);

IWRAM_DATA s32 s32_03000074 = 0;                    // 0x03000074
IWRAM_DATA s32 s32_03000078 = 0;                    // 0x03000078
IWRAM_DATA u32 u32_0300007c = 0;                    // 0x0300007C
IWRAM_DATA s32 s32_03000080 = 0;                    // 0x03000080
IWRAM_DATA WeatherManager* gWeatherManager = NULL;  // 0x03000084

bool32 FUN_08018118(WeatherManager*);
bool32 FUN_08018250(WeatherManager*);
bool32 FUN_08018284(WeatherManager*);
bool32 FUN_08018324(WeatherManager*);
bool32 FUN_080184ec(WeatherManager*);

bool32 (*const PTR_ARRAY_085aa948[5])(WeatherManager*) = {
    FUN_08018118, FUN_08018250, FUN_08018284, FUN_08018324, FUN_080184ec,
};  // 0x085AA948

NAKED bool32 WeatherManager_IsActive(void) { INCFUNC("asm/func/WeatherManager_IsActive.inc"); }

NAKED void WeatherManager_ResetTimer(WeatherManager* p) { INCFUNC("asm/func/WeatherManager_ResetTimer.inc"); }

NAKED void WeatherManager_SetState(WeatherManager* p, u8 state) { INCFUNC("asm/func/WeatherManager_SetState.inc"); }

NAKED s32 WeatherManager_GetChance(WeatherManager* p) { INCFUNC("asm/func/WeatherManager_GetChance.inc"); }

NAKED void WeatherManager_ScrollClouds(WeatherManager* p) { INCFUNC("asm/func/WeatherManager_ScrollClouds.inc"); }

NAKED s32 WeatherManager_InitParticles(WeatherManager* p) { INCFUNC("asm/func/WeatherManager_InitParticles.inc"); }

NAKED s32 WeatherManager_RemoveParticles(WeatherManager* p) { INCFUNC("asm/func/WeatherManager_RemoveParticles.inc"); }

NAKED s32 WeatherManager_UpdateParticles(WeatherManager* p) { INCFUNC("asm/func/WeatherManager_UpdateParticles.inc"); }

NAKED s32 WeatherManager_SpawnParticles(WeatherManager* p, s32 count, s32 param_3, s32 param_4) { INCFUNC("asm/func/WeatherManager_SpawnParticles.inc"); }

NAKED bool32 FUN_08018118(WeatherManager* p) { INCFUNC("asm/func/FUN_08018118.inc"); }

NAKED bool32 FUN_08018250(WeatherManager* p) { INCFUNC("asm/func/FUN_08018250.inc"); }

NAKED bool32 FUN_08018284(WeatherManager* p) { INCFUNC("asm/func/FUN_08018284.inc"); }

NAKED bool32 FUN_08018324(WeatherManager* p) { INCFUNC("asm/func/FUN_08018324.inc"); }

NAKED bool32 FUN_080184ec(WeatherManager* p) { INCFUNC("asm/func/FUN_080184ec.inc"); }

NAKED s32 WeatherManager_Update(WeatherManager* p) { INCFUNC("asm/func/WeatherManager_Update.inc"); }

NAKED s32 WeatherManager_Destroy(WeatherManager* p) { INCFUNC("asm/func/WeatherManager_Destroy.inc"); }

NAKED s32 WeatherManager_Init(WeatherManager* p) { INCFUNC("asm/func/WeatherManager_Init.inc"); }

NAKED WeatherManager* WeatherManager_Create(void) { INCFUNC("asm/func/WeatherManager_Create.inc"); }

NAKED s32 WeatherManager_StartScripted(void) { INCFUNC("asm/func/WeatherManager_StartScripted.inc"); }

NAKED s32 WeatherManager_StopScripted(void) { INCFUNC("asm/func/WeatherManager_StopScripted.inc"); }

NAKED s32 FUN_08018990(void) { INCFUNC("asm/func/FUN_08018990.inc"); }

NAKED u32 FUN_08018a08(void) { INCFUNC("asm/func/FUN_08018a08.inc"); }

NAKED s32 FUN_08018a14(void) { INCFUNC("asm/func/FUN_08018a14.inc"); }
