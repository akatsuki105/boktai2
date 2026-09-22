#include "entity.h"
#include "file.h"
#include "global.h"
#include "sprite_main.h"

// ワイヤレス通信(RFU)の電波強度インジケータ。 gRfuLinkStatus->strength を見てアイコンを差し替える
typedef struct SignalStrengthIcon {
  Entity e;           // 0x00, ENTITY_UNK_11
  u32 updateCounter;  // 0x18, SignalStrengthIcon_Update が毎フレーム +1 するだけ。読み手は見つかっていない
  u32 animCounter;    // 0x1C, SignalStrengthIcon_SetStrength が呼ばれるたびに +1。& 0x1F の値で同じ強度内の点滅段を選ぶ
  s32 spriteIdx;      // 0x20, 現在表示しているアイコン番号 (0x3E..0x42)。変化したときだけ MainSprite_SetPose を呼ぶ
  MainSpriteGfx gfx;  // 0x24, Init が OpenMainSpriteFile(&gfx, GetFile(DIR_MAIN_SPRITE, SPRITE_UI_LINK)) で作る
  MainSprite sprite;  // 0x44, Init が MainSprite_Add(&sprite, &gfx, 0x3F, 0x11, 0, 0, 0x3C, NULL) で登録する
} SignalStrengthIcon;
static_assert(sizeof(SignalStrengthIcon) == 164);

extern SignalStrengthIcon* gSignalStrengthIcon;  // 0x030000E4

u32 FUN_0804e59c(void);
bool32 FUN_0804e3ec(void);
s32 FUN_0804e3c0(void);

SignalStrengthIcon* SignalStrengthIcon_Get(void) { return gSignalStrengthIcon; }

// 電波強度からアイコンのコマを決めて、変わったときだけ差し替える
NON_MATCH void SignalStrengthIcon_SetStrength(SignalStrengthIcon* p, s32 strength) {
#ifdef NONMATCHING_C
  s32 counter;
  s32 phase;
  s32 idx;

  if (strength > RFU_LINK_ICON_LEVEL3_MAX) {
    counter = p->animCounter;
    phase = counter & 0x1F;
    if (phase <= 7) {
      idx = 0x3F;
    } else if (phase <= 0xF) {
      idx = 0x40;
    } else if (phase <= 0x17) {
      idx = 0x41;
    } else {
      idx = 0x42;
    }
  } else if (strength > RFU_LINK_ICON_LEVEL2_MAX) {
    counter = p->animCounter;
    phase = counter & 0x1F;
    if (phase <= 9) {
      idx = 0x3F;
    } else if (phase <= 0x13) {
      idx = 0x40;
    } else {
      idx = 0x41;
    }
  } else if (strength > RFU_LINK_ICON_LEVEL1_MAX) {
    counter = p->animCounter;
    phase = counter & 0x1F;
    if (phase <= 9) {
      idx = 0x3E;
    } else if (phase <= 0x13) {
      idx = 0x3F;
    } else {
      idx = 0x40;
    }
  } else {
    counter = p->animCounter;
    phase = counter & 0x1F;
    if (phase > 0xF) {
      idx = 0x3E;
    } else {
      idx = 0x3F;
    }
  }
  p->animCounter = counter + 1;
  if (p->spriteIdx != idx) {
    p->spriteIdx = idx;
    MainSprite_SetPose(&p->sprite, &p->gfx, idx, 0);
  }
#else
  INCFUNC("asm/func/SignalStrengthIcon_SetStrength.inc");
#endif
}

// 未使用. 子機のときだけ親との強度を表示する (SignalStrengthIcon_Refresh の子機側だけを取り出した形)
void FUN_0804e84c(SignalStrengthIcon* p) {
  if (gRfuLinkStatus->parent_child == MODE_CHILD) {
    SignalStrengthIcon_SetStrength(p, gRfuLinkStatus->strength[0]);
    p->sprite.flags &= ~SPRFLAG_HIDDEN;
  } else {
    p->sprite.flags |= SPRFLAG_HIDDEN;
  }
}

NON_MATCH void SignalStrengthIcon_Refresh(SignalStrengthIcon* p) {
#ifdef NONMATCHING_C
  s32 strength;
  s32 i;

  if (FUN_0804e59c() != 0) {
    return;
  }
  strength = 0xFF;
  if (FUN_0804e3ec()) {
    if (gRfuLinkStatus->parent_child == MODE_CHILD) {
      i = FUN_0804e3c0();  // 元は添字に直接書かれていて、この一時変数のぶん adds r1, r0, #0 が余計に出る
      strength = gRfuLinkStatus->strength[i];
      SignalStrengthIcon_SetStrength(p, strength);
    } else {
      for (i = 0; i < 4; i++) {
        if ((gRfuLinkStatus->connectSlot_flag >> i) & 1) {
          if (strength > gRfuLinkStatus->strength[i]) {
            strength = gRfuLinkStatus->strength[i];
          }
        }
      }
      if (gRfuLinkStatus->connectSlot_flag == 0) {
        SignalStrengthIcon_SetStrength(p, 0);
      } else {
        SignalStrengthIcon_SetStrength(p, strength);
      }
    }
    p->sprite.flags &= ~SPRFLAG_HIDDEN;
  } else {
    p->sprite.flags |= SPRFLAG_HIDDEN;
  }
#else
  INCFUNC("asm/func/SignalStrengthIcon_Refresh.inc");
#endif
}

s32 SignalStrengthIcon_Update(SignalStrengthIcon* p) {
  SignalStrengthIcon_Refresh(p);
  p->updateCounter++;
  return 0;
}

s32 SignalStrengthIcon_Destroy(SignalStrengthIcon* p) {
  MainSprite_Remove(&p->sprite);
  gSignalStrengthIcon = NULL;
  return 0;
}

// アイコンのスプライトファイルを読み込み、非表示のまま描画リストに繋ぐ
s32 SignalStrengthIcon_Init(SignalStrengthIcon* p) {
  MainSpriteFile* f;

  gSignalStrengthIcon = p;
  f = GetFile(DIR_MAIN_SPRITE, SPRITE_UI_LINK);
  if (f == NULL) {
    return -1;
  }
  p->gfx = *(MainSpriteGfx*)f;
  OpenMainSpriteFile(&p->gfx, f);
  MainSprite_Add(&p->sprite, &p->gfx, 0x3F, SPRFLAG_HIDDEN | SPRFLAG_SCREEN_COORD, 0, 0, 0x3C, NULL);
  return 0;
}

SignalStrengthIcon* SignalStrengthIcon_Create(void) {
  SignalStrengthIcon* p = SignalStrengthIcon_Get();

  if (p != NULL) {
    return p;
  }
  p = CreateEntity(ENTITY_UNK_11, sizeof(SignalStrengthIcon));
  if (p != NULL) {
    SetEntityRoutine(p, SignalStrengthIcon_Update, SignalStrengthIcon_Destroy);
    if (SignalStrengthIcon_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
