#include "camera.h"
#include "entity.h"
#include "global.h"
#include "map_inline.h"
#include "particle.h"
#include "player.h"
#include "random.h"
#include "sound.h"
#include "tilemap.h"
#include "time.h"
#include "video.h"
#include "vm.h"

// 雨粒1つ, ptcl を1個ずつ持ち、pos[2] を毎フレーム入れ替えながら ptcl.pos へ写す
typedef struct {
  bool8 active;   // 0x00, WeatherManager_UpdateParticles と WeatherManager_RemoveParticles が 0 以外の要素だけ処理する, WeatherManager_SpawnParticles が空きスロットを探すのにも使う
  u8 timer;       // 0x01, WeatherManager_UpdateParticles が毎フレーム +1 し、3 以上で phase を進める
  u8 phase;       // 0x02, 0 で出現待ち、1 で消滅待ち
  u8 posIdx;      // 0x03, 0 と 1 を毎フレーム反転させ、pos[posIdx] を ptcl.pos へ写す
  Vec3 pos[2];    // 0x04, WeatherManager_SpawnParticles がプレイヤー位置 ±0x800 の乱数で埋める
  Particle ptcl;  // 0x14, Particle_Setup / Particle_SetOffset / Particle_Remove に渡す
} WeatherParticle;
static_assert(sizeof(WeatherParticle) == 60);

// BG1 に TILEMAP_EA77 を敷いて2段階の速度でスクロールさせ、同時に雨粒のパーティクルを32個ばら撒く
// gStat->sunGauge と gStat->unk_2d0 を見て継続と終了を決める
typedef struct {
  Entity e;                   // 0x00, ENTITY_UNK_9
  u8 unk_18;                  // 0x18, WeatherManager_SetState が state を変えるときに 1 にする
  u8 state;                   // 0x19, gWeatherStateFuncs[5] の添字, 2 以上で WeatherManager_ScrollClouds (BGスクロール) が回り、3 で gStat の 0x946 が 0x7FFF になる
  u8 unk_1a[2];               // 0x1A
  u32 stateTimer;             // 0x1C, WeatherManager_SetState が state を変えるときに 0 に戻す
  u16 timer;                  // 0x20, WeatherManager_UpdateRaining が 0 になるまで毎フレーム減らし、0 で WeatherManager_ResetTimer が詰め直す
  u8 unk_22;                  // 0x22, '.a=1'
  u8 unk_23;                  // 0x23
  u16 sunAccum;               // 0x24, 状態に入るとき 0 にし、以降 gStat->sunGauge を毎フレーム足す, 60 以上で天候を切り上げる
  u16 unk_26;                 // 0x26
  u16 unk_28;                 // 0x28, '.i[0]=7200', sRainDuration の下限に使う
  u16 unk_2a;                 // 0x2A, '.i[1]=3600', 0 でなければ rand % これを sRainDuration に足す
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

static s32 sRainIntervalBase;            // 0x03000074
static s32 sRainIntervalRand;            // 0x03000078
static bool32 sRainFalling;              // 0x0300007C, 雨が降っているかどうかを返す (雨の時に屋内に入っても TRUE のまま)
static s32 sRainDuration;                // 0x03000080
static WeatherManager* sWeatherManager;  // 0x03000084

COMMON_DATA s32 gLightningTimer = 0;  // 0x03002B48

extern s32 gGrayscaleTimer;
s32 Video_AddParticleIntoDrawList(Particle* p, s32 idx);
void WeatherManager_ResetTimer(WeatherManager* p);

void FUN_080026fc(s32 n);
void WeatherManager_ScrollClouds(WeatherManager* p);
s32 WeatherManager_UpdateParticles(WeatherManager* p);
s32 WeatherManager_SpawnParticles(WeatherManager* p, s32 count, s32 interval, s32 intervalRand);

// いまの太陽ゲージ
static inline s32 GetSunGauge(void) { return gStat->sunGauge; }

bool32 WeatherManager_IsActive(void) {
  if (sWeatherManager != NULL) {
    return TRUE;
  }
  return FALSE;
}

// 次に天候が変わるまでのフレーム数を詰め直す
void WeatherManager_ResetTimer(WeatherManager* p) {
  p->timer = p->timerBase;
  if (p->timerRand != 0) {
    p->timer += Mod(Random(), p->timerRand);
  }
  if (p->timer < 10) {
    p->timer = 10;
  }
}

void WeatherManager_SetState(WeatherManager* p, u8 state) {
  p->state = state;
  p->stateTimer = 0;
  p->unk_18 = 1;
}

// 天候が発生する確率, ゲーム内時間によっては半減する
s32 WeatherManager_GetChance(WeatherManager* p) {
  s32 chance;
  u32 span;

  if (gStat->unk_2b0[1] != 0) {
    chance = p->unk_32;
  } else {
    chance = p->unk_30 * p->unk_32 >> 6;
  }
  span = Time_GetSpanOfTime();
  if ((span >= TIME_UNK4 && span <= TIME_UNK5) || span == TIME_NIGHT) {
    chance >>= 1;
  }
  return chance;
}

// 雲の BG1 を揺らぎを付けながら斜めに流し, カメラに合わせて BG マップを組む
void WeatherManager_ScrollClouds(WeatherManager* p) {
  s32 ofsX = gCameraVpCoords.x + gCameraCoords.tilemapX;
  s32 ofsY = gCameraVpCoords.y + gCameraCoords.tilemapY;

  if (p->driftTimer == 0) {
    p->driftTimer = (RandomNext() & 127) + 128;
    p->driftTarget = (RandomNext() & 7) - 1;
  } else {
    p->driftTimer--;
  }
  if ((p->frameCounter & 15) == 0) {
    if (p->drift < p->driftTarget) {
      p->drift++;
    } else if (p->drift > p->driftTarget) {
      p->drift--;
    }
  }
  if (p->frameCounter & 1) {
    p->scrollX[0] += 3 + p->drift;
    p->scrollY[0] -= 8 + p->drift;
  } else {
    p->scrollX[1] += 6 + p->drift;
    p->scrollY[1] -= 16 + p->drift;
  }
  {
    s32 hofs = (ofsX + p->scrollX[p->layer]) & 0xFF;
    s32 vofs = (ofsY + p->scrollY[p->layer]) & 0xFF;

    Video_GenerateBGMap(1, Div(ofsX - 128, 8), Div(ofsY - 128, 8) & ~1, hofs, vofs);
  }
}

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
    Particle_Setup(q, p->group, SPRFLAG_HIDDEN);
    Particle_SetOffset(q, -4, -4);
    Particle_SetPose(q, p->group, 30);
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
            Particle_SetPose(q, p->group, 0x1F);
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

// プレイヤーの周り ±0x800 のランダムな床の上に雨粒を count 個出し, 次に出すまでの間隔を決める
// 残差: 313 対 296 命令, 原典は要素のポインタを2本持ち TileHeightAt の展開が短い, 形の詰めは未着手
NON_MATCH s32 WeatherManager_SpawnParticles(WeatherManager* p, s32 count, s32 interval, s32 intervalRand) {
#ifdef NONMATCHING_C
  Player* player = gPlayerPtr[0];

  if (p->unk_60 == 0) {
    s32 n;

    for (n = 0; n < count; n++) {
      s32 i;

      for (i = 0; i < 32; i++) {
        WeatherParticle* e = &p->ptcls[i];

        if (!e->active) {
          e->phase = 0;
          e->timer = 0;
          e->posIdx = 0;
          e->pos[0].x = (Random() & 0xFFF) + player->mover.pos.x - 0x800;
          e->pos[0].z = (Random() & 0xFFF) + player->mover.pos.z - 0x800;
          e->pos[0].y = TileHeightAt(&e->pos[0]);
          e->pos[1].x = (Random() & 0xFFF) + player->mover.pos.x - 0x800;
          e->pos[1].z = (Random() & 0xFFF) + player->mover.pos.z - 0x800;
          e->pos[1].y = TileHeightAt(&e->pos[1]);
          e->ptcl.pos = e->pos[e->posIdx];
          Particle_SetPose(&e->ptcl, p->group, 30);
          e->ptcl.priority = 1;
          e->ptcl.flags &= ~SPRFLAG_HIDDEN;
          Video_AddParticleIntoDrawList(&e->ptcl, 0);
          e->active = TRUE;
          break;
        }
      }
    }
    p->unk_60 = interval;
    if (intervalRand != 0) {
      p->unk_60 += Mod(Random(), intervalRand);
    }
  } else {
    p->unk_60--;
  }
#else
  INCFUNC("asm/func/WeatherManager_SpawnParticles.inc");
#endif
}

// 晴れの待機, 太陽ゲージで次の雨を遅らせ, 時間が来たら確率で雨を降らせ始める
// 残差: 原典は gStat のアドレスを r6 に置き r4-r7 だけで済ませるが, こちらは r8/r9 まで使う, rainTimer に足したあと gStat を読み直す形も違う
NON_MATCH bool32 WeatherManager_UpdateClear(WeatherManager* p) {
#ifdef NONMATCHING_C
  s32 chance;
  s32 sun;

  if (p->unk_18) {
    p->unk_18 = 0;
    CLEAR_FLAGS(gStat->mapFlags, MPF_RAIN);
    FUN_080026fc(0);
    CLEAR_FLAGS(gStagedDISPCNT, DISPCNT_BG1_ON);
  }
  chance = WeatherManager_GetChance(p);
  sun = gStat->sunGauge;
  if (!TEST_FLAGS(gGameFlags | gDebugGameFlags, GAMEFLAG_GAMEOVER) && p->unk_22 != 0) {
    if (sun > 0) {
      gStat->rainTimer += sun >> 2;
      if (gStat->rainTimer >= sRainIntervalBase) {
        gStat->rainTimer = sRainIntervalBase;
      }
    } else if (gStat->rainTimer == 0) {
      if ((RandomNext() & 63) >= chance) {
        gStat->rainTimer = sRainIntervalBase;
        if (sRainIntervalRand > 0) {
          gStat->rainTimer += Mod(RandomNext(), sRainIntervalRand);
        }
      } else {
        WeatherManager_SetState(p, 1);
        return TRUE;
      }
    } else {
      gStat->rainTimer--;
    }
  }
  p->stateTimer++;
  return FALSE;
#else
  INCFUNC("asm/func/WeatherManager_UpdateClear.inc");
#endif
}

// 降り始めの100フレームを待ってから本降りへ移る
bool32 WeatherManager_UpdateRainStart(WeatherManager* p) {
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
bool32 WeatherManager_UpdateDownpour(WeatherManager* p) {
  if (p->unk_18 != 0) {
    p->unk_18 = 0;
    SET_FLAGS(gStat->mapFlags, MPF_RAIN);
    if (p->unk_54 != 0) {
      VM_ExecByID(p->unk_54, NULL);
    }
  }
  SET_FLAGS(gStagedDISPCNT, DISPCNT_BG1_ON);
  if (p->stateTimer <= 14) {
    if ((p->stateTimer & 3) <= 2) {
      CLEAR_FLAGS(gStagedDISPCNT, DISPCNT_BG1_ON);
    }
  } else if (p->stateTimer <= 29) {
    if ((p->stateTimer & 3) <= 1) {
      CLEAR_FLAGS(gStagedDISPCNT, DISPCNT_BG1_ON);
    }
  } else if ((p->stateTimer & 3) == 0) {
    CLEAR_FLAGS(gStagedDISPCNT, DISPCNT_BG1_ON);
  }
  WeatherManager_SpawnParticles(p, 3, 10, 10);
  if (p->stateTimer > 44) {
    WeatherManager_SetState(p, 3);
    return TRUE;
  }
  p->layer = 0;
  p->stateTimer++;
  return FALSE;
}

// 雨の最中, 雷を鳴らしながら雨粒を撒き, 太陽を浴びるか降る時間が尽きたら止ませる
bool32 WeatherManager_UpdateRaining(WeatherManager* p) {
  if (p->unk_18) {
    p->unk_18 = 0;
    if (sRainDuration == 0) {
      sRainDuration = p->unk_28;
      if (p->unk_2a != 0) {
        sRainDuration += Mod(Random(), p->unk_2a);
      }
    }
    p->sunAccum = 0;
    SET_FLAGS(gStagedDISPCNT, DISPCNT_BG1_ON);
    SET_FLAGS(gStat->mapFlags, MPF_RAIN);
    FUN_080026fc(2);
  }
  if (p->timer == 0) {
    if (!(gGameFlags & GAMEFLAG_GAMEOVER) && gLightningTimer > 0) {
      gGrayscaleTimer = 5;
      PlaySound_082406e0(SE_THE_TOWER);
    }
    WeatherManager_ResetTimer(p);
  } else {
    if (gClock.spanOfTime > TIME_DAYTIME) {
      if (p->timer == 5) {
        StartBgObjPlttFade(0, 2, 31, 31, 31, 0x1FFF, 0);
      } else if (p->timer == 3) {
        gLightningTimer = 6;
      }
    }
    p->timer--;
  }
  if (p->stateTimer >= 30) {
    p->sunAccum += GetSunGauge();
    if (p->sunAccum >= 60 || TEST_FLAGS(gGameFlags | gDebugGameFlags, GAMEFLAG_GAMEOVER)) {
      sRainDuration = 0;
      WeatherManager_SetState(p, 4);
      return TRUE;
    }
  }
  if (sRainDuration <= 0) {
    WeatherManager_SetState(p, 4);
    sRainDuration = 0;
    return TRUE;
  }
  sRainDuration--;
  WeatherManager_SpawnParticles(p, (Random() & 3) + 4, 1, 0);
  p->layer = 1 - p->layer;
  p->stateTimer++;
  return FALSE;
}

// 雨の終わり, BG1 を数フレーム点滅させて雨粒を撒き終え, 次に降るまでのフレーム数を決めて待機へ戻る
bool32 WeatherManager_UpdateRainEnd(WeatherManager* p) {
  if (p->unk_18) {
    p->unk_18 = 0;
    FUN_080026fc(3);
    CLEAR_FLAGS(gStat->mapFlags, MPF_RAIN);
    if (p->unk_58 != 0) {
      VM_ExecByID(p->unk_58, NULL);
    }
  }
  SET_FLAGS(gStagedDISPCNT, DISPCNT_BG1_ON);
  if (p->stateTimer <= 9 && (p->stateTimer & 1) == 0) {
    CLEAR_FLAGS(gStagedDISPCNT, DISPCNT_BG1_ON);
  }
  if (p->stateTimer <= 7) {
    WeatherManager_SpawnParticles(p, 3, 10, 10);
  }
  if (p->stateTimer > 9) {
    WeatherManager_SetState(p, 0);
    CLEAR_FLAGS(gStagedDISPCNT, DISPCNT_BG1_ON);
    gStat->rainTimer = sRainIntervalBase;
    if (sRainIntervalRand > 0) {
      gStat->rainTimer += Mod(Random(), sRainIntervalRand);
    }
    return TRUE;
  }
  p->layer = 0;
  p->stateTimer++;
  return FALSE;
}

bool32 (*const gWeatherStateFuncs[5])(WeatherManager*) = {
    WeatherManager_UpdateClear,
    WeatherManager_UpdateRainStart,
    WeatherManager_UpdateDownpour,
    WeatherManager_UpdateRaining,
    WeatherManager_UpdateRainEnd,
};  // 0x085AA948

// 天候の状態関数を呼んで雲と粒を動かす, 雨の間は unk_946 を 0x7FFF に張り, 止んだら 0 まで減らす
s32 WeatherManager_Update(WeatherManager* p) {
  bool32 (*fn)(WeatherManager*) = gWeatherStateFuncs[p->state];

  if (fn != NULL) {
    fn(p);
  }
  if (p->state > 1) {
    WeatherManager_ScrollClouds(p);
  }
  if (p->state == 3) {
    UNK_946 = 0x7FFF;
    sRainFalling = TRUE;
  } else {
    if (UNK_946 > 0) {
      UNK_946--;
    }
    sRainFalling = FALSE;
  }
  if (gLightningTimer > 0) {
    gLightningTimer--;
  }
  WeatherManager_UpdateParticles(p);
  p->frameCounter++;
  return 0;
}

s32 WeatherManager_Destroy(WeatherManager* p) {
  WeatherManager_RemoveParticles(p);
  sWeatherManager = NULL;
  return 0;
}

// 残差: 235 対 239 命令, 'M' と 'P' の比較を agbcc が halfword 1回にまとめてしまう, 乱数と WeatherManager_GetChance の評価順も逆
NON_MATCH s32 WeatherManager_Init(WeatherManager* p) {
#ifdef NONMATCHING_C
  TilemapFile* f;
  BgMapEntry* tilemap;
  s32 state;

  sWeatherManager = p;
  f = GetTilemapFile(TILEMAP_EA77);
  tilemap = GetTilemapBuffer(1);
  p->scrollX[0] = 0;
  p->scrollY[0] = 0;
  p->scrollX[1] = 0;
  p->scrollY[1] = 0;
  p->layer = 0;
  if (f->magic[0] == 'M' && f->magic[1] == 'P') {
    s32 index = 0;

    SetBGPrioDirect(1, 1);
    Video_SetupBGLayout(3, 1, f, 0, 0, 1, &index);
  } else {
    Video_SetupBG(1, 1, f, 0, 0, 0, 1, tilemap);
  }
  if (VM_SeekToNamedArg('r')) {
    p->unk_30 = VM_GetValue();
    p->unk_32 = VM_GetValue();
  } else {
    p->unk_30 = 0x40;
    p->unk_32 = 0x40;
  }
  if (VM_SeekToNamedArg('i')) {
    p->unk_28 = VM_GetValue();
    p->unk_2a = VM_GetValue();
  } else {
    p->unk_28 = 7200;
    p->unk_2a = 3600;
  }
  if (sRainDuration > p->unk_28) {
    sRainDuration = p->unk_28;
    if (p->unk_2a != 0) {
      sRainDuration += Mod(Random(), p->unk_2a);
    }
  }
  if (VM_SeekToNamedArg('c')) {
    gStat->rainTimer = VM_GetValue();
  }
  if (VM_SeekToNamedArg('t')) {
    p->timerBase = VM_GetValue();
    p->timerRand = VM_GetValue();
  } else {
    p->timerBase = 300;
    p->timerRand = 300;
  }
  WeatherManager_ResetTimer(p);
  p->unk_22 = VM_GetNamedArgValue('a', 1);
  gStat->rainTimer += GetSunGauge() >> 2;
  if (gStat->rainTimer >= sRainIntervalBase) {
    gStat->rainTimer = sRainIntervalBase;
  }
  state = 0;
  if (gStat->sunGauge == 0) {
    if (sRainDuration > 0) {
      if (sRainDuration < 100) {
        sRainDuration = 100;
      }
      state = 3;
    } else if (gStat->rainTimer == 0 && (Random() & 63) < WeatherManager_GetChance(p)) {
      state = 3;
    }
  }
  WeatherManager_SetState(p, VM_GetNamedArgValue('m', state));
  p->unk_54 = VM_GetNamedArgValue('C', 0);
  p->unk_58 = VM_GetNamedArgValue('O', 0);
  {
    p->driftTimer = (RandomNext() & 127) + 128;
    p->drift = (RandomNext() & 7) - 4;
    p->driftTarget = (RandomNext() & 7) - 4;
  }
  WeatherManager_InitParticles(p);
  return 0;
#else
  INCFUNC("asm/func/WeatherManager_Init.inc");
#endif
}

WeatherManager* WeatherManager_Create(void) {
  WeatherManager* p;

  if (sWeatherManager != NULL) {
    return sWeatherManager;
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
  WeatherManager* p = sWeatherManager;

  if (p == NULL) {
    return -1;
  }
  WeatherManager_SetState(p, 1);
  p->unk_22 = 1;
}

// スクリプトから天候を止める
s32 WeatherManager_StopScripted(void) {
  WeatherManager* p = sWeatherManager;

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
s32 Cmd_164D(void) {
  s32 a;
  s32 b;

  if (VM_SeekToNamedArg('c')) {
    a = VM_GetValue();
    b = VM_GetValue();
  } else {
    b = 1200;
    a = b;
  }
  if (VM_SeekToNamedArg('i')) {
    VM_GetValue();
  } else if (sRainIntervalRand > 0) {
    Mod(Random(), sRainIntervalRand);
  }
  sRainIntervalBase = a;
  sRainIntervalRand = b;
}

// 雨が降っているかどうかを返す
bool32 FUN_08018a08(void) { return sRainFalling; }

// 0x7A82
bool32 Cmd_7A82(void) { return FUN_08018a08(); }
