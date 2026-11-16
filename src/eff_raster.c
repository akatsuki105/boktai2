#include "entity.h"
#include "global.h"
#include "video.h"
#include "vm.h"

// HBlank で BG の横スクロールを走査線ごとに正弦波でずらし, 画面を波打たせる (HashName("ラスターエフェクト"))
// スクリプトが渡すインスタンスIDは場所ごとに "水面ラスター" = 0xDB53, "水中ラスター" = 0xD552, "砂漠ラスター" = 0x4533, "溶岩ラスター" = 0xF9F8
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
} RasterEffect;
static_assert(sizeof(RasterEffect) == 628);

extern u32 gHBlankEffectBG;

IWRAM_DATA RasterEffect* gRasterEffect = NULL;  // 0x03000070

void FUN_080179ac(void) { gRasterEffect = NULL; }

s32 RasterEffect_Update(RasterEffect* p) {
  if (p->enabled) {
    Video_SetHBlankEffect(p->unk_1a, p->unk_1c, &p->waveTable[p->tableIdx * 288] + (((s16)gBgStates[gHBlankEffectBG].vofs + p->phase) & 0x7F));
    if (++p->tickTimer >= p->tickInterval) {
      p->tickTimer = 0;
      p->phase += p->phaseStep;
    }
  }

  return 0;
}

s32 RasterEffect_Destroy(RasterEffect* p) {
  FUN_0822f0d8();
  gRasterEffect = NULL;
  return 0;
}

// 振幅が r7 に載らずレジスタ割当だけがずれる, 91/91 命令, 角度は SIN(j & 0x7F) を局所に受けて 0xFF のマスクが残る形
NON_MATCH s32 RasterEffect_Init(RasterEffect* p, u16 id) {
#ifdef NONMATCHING_C
  s32 i;
  s32 j;
  s32 amp;

  gRasterEffect = p;
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
  INCFUNC("asm/func/RasterEffect_Init.inc");
#endif
}

// 0xE435, HashName("ラスターエフェクト")
RasterEffect* RasterEffect_Create(u32 id) {
  if (gRasterEffect == NULL) {
    RasterEffect* p;

    if (VM_GetNamedArgValue('a', 0)) {
      p = CreateEntity(ENTITY_UNK_11, sizeof(RasterEffect));
    } else {
      p = CreateEntity(ENTITY_UNK_9, sizeof(RasterEffect));
    }

    if (p != NULL) {
      SetEntityRoutine(p, RasterEffect_Update, RasterEffect_Destroy);
      if (RasterEffect_Init(p, id) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gRasterEffect;
}
