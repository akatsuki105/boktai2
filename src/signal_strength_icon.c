#include "entity.h"
#include "file.h"
#include "global.h"
#include "sprite_main.h"

// ワイヤレス通信(RFU)の電波強度インジケータ。 gRfuLinkStatus->strength を見てアイコンを差し替える
typedef struct SignalStrengthIcon {
  Entity e;           // 0x00, ENTITY_UNK_11
  u32 updateCounter;  // 0x18, SignalStrengthIcon_Update が毎フレーム +1 するだけ。読み手は見つかっていない
  u32 animCounter;    // 0x1C, SignalStrengthIcon_SetStrength が呼ばれるたびに +1。& 0x1F の値で同じ強度内の点滅段を選ぶ
  s32 poseIdx;        // 0x20, 現在表示しているアイコン番号 (62..66)。変化したときだけ MainSprite_SetPose を呼ぶ
  MainSpriteGfx gfx;  // 0x24, SPRITE_UI_LINK
  MainSprite sprite;  // 0x44
} SignalStrengthIcon;
static_assert(sizeof(SignalStrengthIcon) == 164);

extern SignalStrengthIcon* gSignalStrengthIcon;  // 0x030000E4

u32 FUN_0804e59c(void);
bool32 FUN_0804e3ec(void);
s32 FUN_0804e3c0(void);

static SignalStrengthIcon* SignalStrengthIcon_Get(void) { return gSignalStrengthIcon; }

// 電波強度からアイコンのコマを決めて、変わったときだけ差し替える
NON_MATCH void SignalStrengthIcon_SetStrength(SignalStrengthIcon* p, s32 strength) {
#ifdef NONMATCHING_C
  s32 idx;

  if (strength > RFU_LINK_ICON_LEVEL3_MAX) {
    s32 phase = p->animCounter & 0x1F;
    if (phase <= 7) {
      idx = 63;
    } else if (phase <= 15) {
      idx = 64;
    } else if (phase <= 23) {
      idx = 65;
    } else {
      idx = 66;
    }
  } else if (strength > RFU_LINK_ICON_LEVEL2_MAX) {
    s32 phase = p->animCounter & 0x1F;
    if (phase <= 9) {
      idx = 63;
    } else if (phase <= 19) {
      idx = 64;
    } else {
      idx = 65;
    }
  } else if (strength > RFU_LINK_ICON_LEVEL1_MAX) {
    s32 phase = p->animCounter & 0x1F;
    if (phase <= 9) {
      idx = 62;
    } else if (phase <= 19) {
      idx = 63;
    } else {
      idx = 64;
    }
  } else {
    s32 phase = p->animCounter & 0x1F;
    if (phase > 15) {
      idx = 62;
    } else {
      idx = 63;
    }
  }
  p->animCounter++;
  if (idx != p->poseIdx) {
    p->poseIdx = idx;
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

// 電波強度を取り直してアイコンに反映する。 リンクしていないときはアイコンを隠す
void SignalStrengthIcon_Refresh(SignalStrengthIcon* p) {
  if (FUN_0804e59c() == 0) {
    s32 strength = 0xFF;
    if (FUN_0804e3ec()) {
      if (gRfuLinkStatus->parent_child == MODE_CHILD) {
        s32 i = FUN_0804e3c0();
        strength = gRfuLinkStatus->strength[i];
        SignalStrengthIcon_SetStrength(p, strength);
      } else {
        s32 i;
        for (i = 0; i < 4; i++) {
          if (gRfuLinkStatus->connectSlot_flag & (1 << i)) {
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
  }
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
  MainSprite_Add(&p->sprite, &p->gfx, 63, SPRFLAG_HIDDEN | SPRFLAG_SCREEN_COORD, 0, 0, 60, NULL);
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
