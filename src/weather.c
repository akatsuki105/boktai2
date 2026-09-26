#include "entity.h"
#include "game.h"
#include "global.h"
#include "particle.h"
#include "random.h"
#include "types.h"
#include "video.h"
#include "vm.h"

// 雨粒1つ, ptcl を1個ずつ持ち、pos[2] を毎フレーム入れ替えながら ptcl.pos へ写す
typedef struct {
  bool8 active;   // 0x00, WeatherManager_UpdateParticles と WeatherManager_RemoveParticles が 0 以外の要素だけ処理する, WeatherManager_SpawnParticles が空きスロットを探すのにも使う
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
  u8 state;                   // 0x19, PTR_ARRAY_085aa948[5] の添字, 2 以上で WeatherManager_ScrollClouds (BGスクロール) が回り、3 で gStat の 0x946 が 0x7FFF になる
  u8 unk_1a[2];               // 0x1A
  u32 stateTimer;             // 0x1C, WeatherManager_SetState が state を変えるときに 0 に戻す
  u16 timer;                  // 0x20, FUN_08018324 が 0 になるまで毎フレーム減らし、0 で WeatherManager_ResetTimer が詰め直す
  u8 unk_22;                  // 0x22, '.a=1'
  u8 unk_23;                  // 0x23
  u16 sunAccum;               // 0x24, 状態に入るとき 0 にし、以降 gStat->sunGauge を毎フレーム足す, 60 以上で天候を切り上げる
  u16 unk_26;                 // 0x26
  u16 unk_28;                 // 0x28, '.i[0]=7200', s32_03000080 の下限に使う
  u16 unk_2a;                 // 0x2A, '.i[1]=3600', 0 でなければ rand % これを s32_03000080 に足す
  u16 timerBase;              // 0x2C, '.t[0]=300', WeatherManager_ResetTimer が timer に入れる基準値
  u16 timerRand;              // 0x2E, '.t[1]', timer に足す乱数の範囲, 合計が 10 未満なら 10 にする
  s16 unk_30;                 // 0x30, '.r[0]=0x40', WeatherManager_GetChance が unk_32 * unk_30 >> 6 を作る
  s16 unk_32;                 // 0x32, '.r[1]'
  s32 scrollX[2];             // 0x34, WeatherManager_ScrollClouds が [0] に 3 + drift、[1] に 6 + drift を毎フレーム足す, Video_GenerateBGMap の X オフセット
  s32 scrollY[2];             // 0x3C, WeatherManager_ScrollClouds が [0] から 8 + drift、[1] から 0x10 + drift を毎フレーム引く
  s32 drift;                  // 0x44, 16フレームごとに driftTarget へ1ずつ寄せる, スクロール速度の揺らぎ
  s32 driftTarget;            // 0x48, 乱数 -4..3 (Init) / -1..6 (WeatherManager_ScrollClouds)
  s32 driftTimer;             // 0x4C, 0 になったら driftTarget を引き直す, 乱数 0x80..0xFF
  s32 layer;                  // 0x50, scrollX / scrollY のどちらの組を Video_GenerateBGMap に渡すかの添字
  s32 unk_54;                 // 0x54, '.C=0'
  s32 unk_58;                 // 0x58, '.O=0'
  s32 frameCounter;           // 0x5C, WeatherManager_Update が毎フレーム +1, WeatherManager_ScrollClouds が下位4bitと下位1bitで分岐する
  s16 unk_60;                 // 0x60, WeatherManager_InitParticles が 0 にする, WeatherManager_SpawnParticles は 0 のときだけ要素を作る
  s16 unk_62;                 // 0x62, WeatherManager_InitParticles が 0 にする
  u8 unk_64[0x164 - 0x64];    // 0x64, この 256 バイトに触る関数が見つかっていない
  ParticleGroup* group;       // 0x164, PTCL_GROUP_1
  WeatherParticle ptcls[32];  // 0x168
} WeatherManager;
static_assert(sizeof(WeatherManager) == 2280);

IWRAM_DATA s32 s32_03000074 = 0;                    // 0x03000074
IWRAM_DATA s32 s32_03000078 = 0;                    // 0x03000078
IWRAM_DATA u32 u32_0300007c = 0;                    // 0x0300007C
IWRAM_DATA s32 s32_03000080 = 0;                    // 0x03000080
IWRAM_DATA WeatherManager* gWeatherManager = NULL;  // 0x03000084

void FUN_080026fc(s32 n);
void WeatherManager_ScrollClouds(WeatherManager* p);
s32 WeatherManager_UpdateParticles(WeatherManager* p);
extern s32 s32_03002b48;
s32 WeatherManager_SpawnParticles(WeatherManager* p, s32 a, s32 b, s32 c);
u32 FUN_0823e1b0(void);

bool32 FUN_08018118(WeatherManager*);
bool32 FUN_08018250(WeatherManager*);
bool32 FUN_08018284(WeatherManager*);
bool32 FUN_08018324(WeatherManager*);
bool32 FUN_080184ec(WeatherManager*);

bool32 (*const PTR_ARRAY_085aa948[5])(WeatherManager*) = {
    FUN_08018118, FUN_08018250, FUN_08018284, FUN_08018324, FUN_080184ec,
};  // 0x085AA948

bool32 WeatherManager_IsActive(void) {
  if (gWeatherManager != NULL) {
    return TRUE;
  }
  return FALSE;
}

// 次に天候が変わるまでのフレーム数を詰め直す
NON_MATCH void WeatherManager_ResetTimer(WeatherManager* p) {
#ifdef NONMATCHING_C
  p->timer = p->timerBase;
  if (p->timerRand != 0) {
    gRandTableIdx = (gRandTableIdx + 1) & 0x3FF;
    p->timer += Mod(gRandomTable[gRandTableIdx], p->timerRand);
  }
  if (p->timer < 10) p->timer = 10;
#else
  INCFUNC("asm/func/WeatherManager_ResetTimer.inc");
#endif
}

void WeatherManager_SetState(WeatherManager* p, u8 state) {
  p->state = state;
  p->stateTimer = 0;
  p->unk_18 = 1;
}

// 天候が発生する確率, ゲーム内時間によっては半減する
s32 WeatherManager_GetChance(WeatherManager* p) {
  s32 chance;
  u32 hour;

  if (gStat->unk_2b0[1] != 0) {
    chance = p->unk_32;
  } else {
    chance = p->unk_30 * p->unk_32 >> FRACBITS_6;
  }
  hour = FUN_0823e1b0();
  if ((hour >= 4 && hour <= 5) || hour == 0) {
    chance >>= 1;
  }
  return chance;
}

NAKED void WeatherManager_ScrollClouds(WeatherManager* p) { INCFUNC("asm/func/WeatherManager_ScrollClouds.inc"); }

// 雨粒32個ぶんのパーティクルを用意する
s32 WeatherManager_InitParticles(WeatherManager* p) {
  WeatherParticle* ptcl;
  s32 i;

  p->group = GetParticleGroup(PTCL_GROUP_1);
  p->unk_60 = 0;
  p->unk_62 = 0;
  ptcl = p->ptcls;
  for (i = 0; i < 32; i++, ptcl++) {
    Particle* q = &ptcl->ptcl;

    ptcl->active = FALSE;
    ptcl->timer = 0;
    ptcl->phase = 0;
    FUN_0822da70(q, p->group, 1);
    Particle_SetOffset(q, -4, -4);
    FUN_0822dafc(q, p->group, 30);
  }
  return 0;
}

s32 WeatherManager_RemoveParticles(WeatherManager* p) {
  WeatherParticle* ptcl = p->ptcls;
  s32 i;

  for (i = 0; i < 32; i++, ptcl++) {
    Particle* q = &ptcl->ptcl;

    if (ptcl->active) {
      Particle_Remove(q);
      ptcl->active = FALSE;
    }
  }
}

// 雨粒を1フレーム進める, pos[2] を交互に使って残像のように見せる
NON_MATCH s32 WeatherManager_UpdateParticles(WeatherManager* p) {
#ifdef NONMATCHING_C
  WeatherParticle* ptcl = p->ptcls;
  s32 i;

  for (i = 0; i < 32; i++, ptcl++) {
    Particle* q = &ptcl->ptcl;

    if (ptcl->active) {
      q->pos = ptcl->pos[ptcl->posIdx];
      ptcl->posIdx = 1 - ptcl->posIdx;
      switch (ptcl->phase) {
        case 0: {
          if (ptcl->timer > 2) {
            ptcl->phase = 1;
            FUN_0822dafc(q, p->group, 0x1F);
            ptcl->timer = 0;
          }
          break;
        }
        case 1: {
          if (ptcl->timer > 2) {
            Particle_Remove(q);
            ptcl->active = FALSE;
          }
          break;
        }
      }
      ptcl->timer++;
    }
  }
#else
  INCFUNC("asm/func/WeatherManager_UpdateParticles.inc");
#endif
}

NAKED s32 WeatherManager_SpawnParticles(WeatherManager* p, s32 count, s32 param_3, s32 param_4) { INCFUNC("asm/func/WeatherManager_SpawnParticles.inc"); }

NAKED bool32 FUN_08018118(WeatherManager* p) { INCFUNC("asm/func/FUN_08018118.inc"); }

// 降り始めの100フレームを待ってから本降りへ移る
bool32 FUN_08018250(WeatherManager* p) {
  if (p->unk_18 != 0) {
    p->unk_18 = 0;
    FUN_080026fc(1);
  }
  if (p->stateTimer > 99) {
    WeatherManager_SetState(p, 2);
    return TRUE;
  }
  p->stateTimer++;
  return FALSE;
}

// 本降り, BG1 の表示を周期的に間引きながら雨粒を撒く
NON_MATCH bool32 FUN_08018284(WeatherManager* p) {
#ifdef NONMATCHING_C
  if (p->unk_18 != 0) {
    p->unk_18 = 0;
    gStat->unk_934 |= 0x800;
    if (p->unk_54 != 0) {
      Script_ExecById(p->unk_54, NULL);
    }
  }
  gStagedDISPCNT |= 0x200;
  if (p->stateTimer <= 14) {
    if ((p->stateTimer & 3) <= 2) {
      gStagedDISPCNT &= ~0x200;
    }
  } else if (p->stateTimer <= 29) {
    if ((p->stateTimer & 3) <= 1) {
      gStagedDISPCNT &= ~0x200;
    }
  } else if ((p->stateTimer & 3) == 0) {
    gStagedDISPCNT &= ~0x200;
  }
  WeatherManager_SpawnParticles(p, 3, 10, 10);
  if (p->stateTimer <= 44) {
    p->layer = 0;
    p->stateTimer++;
    return FALSE;
  }
  WeatherManager_SetState(p, 3);
  return TRUE;
#else
  INCFUNC("asm/func/FUN_08018284.inc");
#endif
}

NAKED bool32 FUN_08018324(WeatherManager* p) { INCFUNC("asm/func/FUN_08018324.inc"); }

NAKED bool32 FUN_080184ec(WeatherManager* p) { INCFUNC("asm/func/FUN_080184ec.inc"); }

NON_MATCH s32 WeatherManager_Update(WeatherManager* p) {
#ifdef NONMATCHING_C
  bool32 (*fn)(WeatherManager*) = PTR_ARRAY_085aa948[p->state];

  if (fn != NULL) {
    fn(p);
  }
  if (p->state > 1) {
    WeatherManager_ScrollClouds(p);
  }
  if (p->state == 3) {
    gStat->unk_946 = 0x7FFF;
    u32_0300007c = 1;
  } else {
    if (gStat->unk_946 > 0) {
      gStat->unk_946--;
    }
    u32_0300007c = 0;
  }
  if (s32_03002b48 > 0) {
    s32_03002b48--;
  }
  WeatherManager_UpdateParticles(p);
  p->frameCounter++;
  return 0;
#else
  INCFUNC("asm/func/WeatherManager_Update.inc");
#endif
}

s32 WeatherManager_Destroy(WeatherManager* p) {
  WeatherManager_RemoveParticles(p);
  gWeatherManager = NULL;
  return 0;
}

NAKED s32 WeatherManager_Init(WeatherManager* p) { INCFUNC("asm/func/WeatherManager_Init.inc"); }

WeatherManager* WeatherManager_Create(void) {
  WeatherManager* p;

  if (gWeatherManager != NULL) {
    return gWeatherManager;
  }
  p = CreateEntity(ENTITY_UNK_9, sizeof(WeatherManager));
  if (p != NULL) {
    SetEntityRoutine(p, WeatherManager_Update, WeatherManager_Destroy);
    if (WeatherManager_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

// スクリプトから天候を降らせ始める
s32 WeatherManager_StartScripted(void) {
  WeatherManager* p = gWeatherManager;

  if (p == NULL) {
    return -1;
  }
  WeatherManager_SetState(p, 1);
  p->unk_22 = 1;
}

// スクリプトから天候を止める
s32 WeatherManager_StopScripted(void) {
  WeatherManager* p = gWeatherManager;

  if (p == NULL) {
    return -1;
  }
  switch (p->state) {
    case 1:
    case 2:
    case 3: {
      WeatherManager_SetState(p, 4);
      break;
    }
  }
  p->unk_22 = 0;
}

// スクリプトから天候の周期を設定する
NON_MATCH s32 FUN_08018990(void) {
#ifdef NONMATCHING_C
  s32 a;
  s32 b;

  if (VM_SeekToKeyword('c')) {
    a = Script_GetValue();
    b = Script_GetValue();
  } else {
    b = 1200;
    a = b;
  }
  if (VM_SeekToKeyword('i')) {
    Script_GetValue();
  } else if (s32_03000078 > 0) {
    gRandTableIdx = (gRandTableIdx + 1) & 0x3FF;
    Mod(gRandomTable[gRandTableIdx], s32_03000078);
  }
  s32_03000074 = a;
  s32_03000078 = b;
#else
  INCFUNC("asm/func/FUN_08018990.inc");
#endif
}

u32 FUN_08018a08(void) { return u32_0300007c; }

s32 FUN_08018a14(void) { return FUN_08018a08(); }
