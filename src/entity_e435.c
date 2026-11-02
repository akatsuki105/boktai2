#include "entity.h"
#include "global.h"
#include "video.h"
#include "vm.h"

typedef struct {
  Entity e;            // 0x0, ENTITY_UNK_9 or ENTITY_UNK_11
  u16 id;              // 0x018
  u16 unk_1a;          // 0x01A, '.t=0', Video_SetHBlankEffect の第1引数
  u16 unk_1c;          // 0x01C, '.m=0', Video_SetHBlankEffect の第2引数
  u8 unk_1e;           // 0x01E, '.r[0]' の1番目
  u8 unk_1f;           // 0x01F, '.r[1]=160' の2番目
  s16 phaseStep;       // 0x020, '.o=2', 1tick ごとに phase へ加える
  u16 phase;           // 0x022, _Update が (BG の vofs + phase) & 0x7F で waveTable を引く
  u16 tickInterval;    // 0x024, '.i=5', tickTimer と比べる
  u16 tickTimer;       // 0x026, _Update が数え上げ、tickInterval で 0 に戻る
  bool32 enabled;      // 0x028, _Init が 1 を入れる, 0 の間 _Update は何もしない
  u16 tableIdx;        // 0x02C, waveTable を tableIdx * 0x240 だけずらす, _Init が 0 を入れるが書き手が見つかっていない
  s16 waveTable[288];  // 0x02E, '.s' * gSineTable[i & 0x7F] >> 12  を288個
  u8 unk_26e[6];       // 0x26E, 読み書きとも無し
} EntityE435;
static_assert(sizeof(EntityE435) == 628);

extern u32 gHBlankEffectBG;

IWRAM_DATA EntityE435* gEntityE435 = NULL;  // 0x03000070

void FUN_080179ac(void) { gEntityE435 = NULL; }

s32 EntityE435_Update(EntityE435* p) {
  if (p->enabled) {
    Video_SetHBlankEffect(p->unk_1a, p->unk_1c, &p->waveTable[p->tableIdx * 288] + (((s16)gBgStates[gHBlankEffectBG].vofs + p->phase) & 0x7F));
    if (++p->tickTimer >= p->tickInterval) {
      p->tickTimer = 0;
      p->phase += p->phaseStep;
    }
  }

  return 0;
}

s32 EntityE435_Destroy(EntityE435* p) {
  FUN_0822f0d8();
  gEntityE435 = NULL;
  return 0;
}

// 振幅が r7 に載らずレジスタ割当だけがずれる, 91/91 命令, 角度は SIN(j & 0x7F) を局所に受けて 0xFF のマスクが残る形
NON_MATCH s32 EntityE435_Init(EntityE435* p, u16 id) {
#ifdef NONMATCHING_C
  s32 i;
  s32 j;
  s32 amp;

  gEntityE435 = p;
  p->id = id;
  p->unk_1a = VM_GetNamedArgValue('t', 0);
  p->unk_1c = VM_GetNamedArgValue('m', 0);
  if (VM_SeekToNamedArg('r')) {
    p->unk_1e = VM_GetValue();
    p->unk_1f = VM_GetValue();
  } else {
    p->unk_1e = 0;
    p->unk_1f = 160;
  }
  amp = VM_GetNamedArgValue('s', 8);
  p->tickTimer = 0;
  p->phaseStep = VM_GetNamedArgValue('o', 2);
  p->phase = 0;
  p->tickInterval = VM_GetNamedArgValue('i', 5);
  p->tableIdx = 0;
  p->enabled = TRUE;
  for (i = 0; i < 1; i++) {
    for (j = 0; j < 288; j++) {
      s32 angle = j & 0x7F;

      p->waveTable[i * 288 + j] = (amp * SIN(angle)) >> 12;
    }
  }

#else
  INCFUNC("asm/func/EntityE435_Init.inc");
#endif
}

EntityE435* EntityE435_Create(u32 id) {
  if (gEntityE435 == NULL) {
    EntityE435* p;

    if (VM_GetNamedArgValue('a', 0)) {
      p = CreateEntity(ENTITY_UNK_11, sizeof(EntityE435));
    } else {
      p = CreateEntity(ENTITY_UNK_9, sizeof(EntityE435));
    }

    if (p != NULL) {
      SetEntityRoutine(p, EntityE435_Update, EntityE435_Destroy);
      if (EntityE435_Init(p, id) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gEntityE435;
}
