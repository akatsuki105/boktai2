#include "entity.h"
#include "global.h"
#include "random.h"
#include "vm.h"

// gWindAngle に風向きを書き続けるシングルトン
typedef struct {
  Entity e;         // 0x00, ENTITY_UNK_9
  u16 id;           // 0x18, WindManager_Init の第2引数
  u16 mode;         // 0x1A, '.m=1', 0/1/2 で初期化の内容が変わる
  u16 angleBase;    // 0x1C, '.p[0]=3'
  u16 angleRange;   // 0x1E, '.p[1]', 0 以外なら乱数で angleBase に足す幅
  u16 holdBase;     // 0x20, '.t[0]=0x78'
  u16 holdRange;    // 0x22, '.t[1]', 0 以外なら乱数で holdBase に足す幅
  u16 angleMin;     // 0x24, angleBase << 4
  u16 angleTarget;  // 0x26, (angleBase + 乱数 % angleRange) << 4
  u16 angle;        // 0x28, 12bit で回る値, >> 4 したものを gWindAngle に入れる
  u16 speed;        // 0x2A, 乱数表から入る1バイト, *0x10 して angle に足す
  u16 timer;        // 0x2C, 0 まで減ると speed と angleTarget を引き直す
} WindManager;
static_assert(sizeof(WindManager) == 48);

IWRAM_DATA WindManager* gWindManager = NULL;  // 0x03000148

extern u16 gWindPushThreshold;
extern u16 gWindAngle;
extern u16 gWindStrength;

void Cmd_StopWind(void) {
  if (gWindManager != NULL) {
    gWindManager->mode = 0;
    gWindManager->speed = 0;
    gWindManager->angleTarget = 0;
    gWindManager->timer = 0;
  }
}

void Cmd_8459(void) {
  if (gWindManager != NULL) {
    gWindManager->mode = 1;
    if (VM_SeekToNamedArg('p')) {
      gWindManager->angleBase = VM_GetValue();
      gWindManager->angleRange = VM_GetValue();
    } else {
      gWindManager->angleBase = 3;
      gWindManager->angleRange = 3;
    }
    if (VM_SeekToNamedArg('t')) {
      gWindManager->holdBase = VM_GetValue();
      gWindManager->holdRange = VM_GetValue();
    } else {
      gWindManager->holdBase = 0x78;
      gWindManager->holdRange = 0x78;
    }
    gWindManager->timer = 0;
  }
}

void Cmd_274E(void) {
  if (gWindManager != NULL) {
    gWindManager->mode = 2;
    if (VM_SeekToNamedArg('d')) {
      gWindManager->speed = VM_GetValue();
    } else {
      gWindManager->speed = 0;
    }
    if (VM_SeekToNamedArg('p')) {
      gWindManager->angleBase = VM_GetValue();
      gWindManager->angleRange = VM_GetValue();
    } else {
      gWindManager->angleBase = 3;
      gWindManager->angleRange = 3;
    }
    if (VM_SeekToNamedArg('t')) {
      gWindManager->holdBase = VM_GetValue();
      gWindManager->holdRange = VM_GetValue();
    } else {
      gWindManager->holdBase = 0x78;
      gWindManager->holdRange = 0x78;
    }
    gWindManager->timer = 0;
  }
}

void Cmd_B005(void) {
  if (gWindManager != NULL && VM_SeekToNamedArg('H')) {
    gWindPushThreshold = VM_GetValue();
  }
}

// 風向きを angleTarget へ近づけて gWindAngle に書き、保持時間が切れたら次の向きと速さを乱数で引き直す
// 残差は d の計算で 0x1000 がどちら側に付くかだけ (147 対 151)
// 原典は angle に -0x1000 (プール定数) を足してから speed*16 から引くが、agbcc は 0x1000 を speed*16 側に寄せて movs/lsls で作る
// Tier A-B 試済: 括弧でのグループ化 / angle-0x1000 をローカルに / speed*16 をローカルに / 0xFFFFF000 の直書き (いずれも寄せ直される)
NON_MATCH s32 WindManager_Update(WindManager* p) {
#ifdef NONMATCHING_C
  s32 d;

  p->angleMin = (p->angleMin * 15 + p->angleTarget) >> 4;
  d = (p->speed * 16 - (p->angle - 0x1000)) & 0xFFF;
  if (d > 0x800) {
    p->angle = (p->angle + 0x1000 - ((0x1000 - d) >> 4)) & 0xFFF;
  } else {
    p->angle = (p->angle + (d >> 4)) & 0xFFF;
  }
  gWindStrength = p->angleMin >> 4;
  gWindAngle = p->angle >> 4;

  switch (p->mode) {
    case 1: {
      if (p->timer != 0) {
        p->timer--;
      } else {
        if (p->angleRange == 0) {
          p->angleTarget = p->angleBase << 4;
        } else {
          gRandTableIdx = (gRandTableIdx + 1) & 0x3FF;
          p->angleTarget = (p->angleBase + Mod(*(gRandomTable + gRandTableIdx), p->angleRange)) << 4;
        }
        gRandTableIdx = (gRandTableIdx + 1) & 0x3FF;
        p->speed = *(u8*)(gRandomTable + gRandTableIdx);
        if (p->holdRange == 0) {
          p->timer = p->holdBase;
        } else {
          gRandTableIdx = (gRandTableIdx + 1) & 0x3FF;
          p->timer = p->holdBase + Mod(*(gRandomTable + gRandTableIdx), p->holdRange);
        }
      }
      break;
    }
    case 2: {
      if (p->timer != 0) {
        p->timer--;
      } else {
        if (p->angleRange == 0) {
          p->angleTarget = p->angleBase << 4;
        } else {
          gRandTableIdx = (gRandTableIdx + 1) & 0x3FF;
          p->angleTarget = (p->angleBase + Mod(*(gRandomTable + gRandTableIdx), p->angleRange)) << 4;
        }
        if (p->holdRange == 0) {
          p->timer = p->holdBase;
        } else {
          gRandTableIdx = (gRandTableIdx + 1) & 0x3FF;
          p->timer = p->holdBase + Mod(*(gRandomTable + gRandTableIdx), p->holdRange);
        }
      }
      break;
    }
  }
  return 0;
#else
  INCFUNC("asm/func/WindManager_Update.inc");
#endif
}

s32 WindManager_Destroy(WindManager* p) {
  gWindPushThreshold = 0;
  gWindStrength = 0;
  gWindAngle = 0;
  gWindManager = NULL;
  return 0;
}

// mode ごとに風向きの初期値と次の切り替えまでの時間を決める, 原典は通常経路で return を書き忘れている
// 残差は 176 対 177 でこちらが1命令短い, 原典は gRandomTable のプール定数を2回ロードするがこちらは CSE で使い回す
// 他は r4/r6 の入れ替えだけ, Tier A-B 試済: 添字形とポインタ形, (u8*)& と (u8*)( の書き分け
NON_MATCH s32 WindManager_Init(WindManager* p, u32 id) {
#ifdef NONMATCHING_C
  p->id = id;
  if (VM_SeekToNamedArg('m')) {
    p->mode = VM_GetValue();
  } else {
    p->mode = 1;
  }
  if (VM_SeekToNamedArg('H')) {
    gWindPushThreshold = VM_GetValue();
  } else {
    gWindPushThreshold = 0;
  }

  switch (p->mode) {
    case 0: {
      p->speed = 0;
      p->angleTarget = 0;
      break;
    }
    case 1: {
      if (VM_SeekToNamedArg('p')) {
        p->angleBase = VM_GetValue();
        p->angleRange = VM_GetValue();
      } else {
        p->angleBase = 3;
        p->angleRange = 3;
      }
      if (VM_SeekToNamedArg('t')) {
        p->holdBase = VM_GetValue();
        p->holdRange = VM_GetValue();
      } else {
        p->holdBase = 0x78;
        p->holdRange = 0x78;
      }
      gRandTableIdx = (gRandTableIdx + 1) & 0x3FF;
      p->speed = *(u8*)(gRandomTable + gRandTableIdx);
      if (p->angleRange == 0) {
        p->angleTarget = p->angleBase << 4;
      } else {
        gRandTableIdx = (gRandTableIdx + 1) & 0x3FF;
        p->angleTarget = (p->angleBase + Mod(*(gRandomTable + gRandTableIdx), p->angleRange)) << 4;
      }
      p->angleMin = p->angleBase << 4;
      if (p->holdRange == 0) {
        p->timer = p->holdBase;
      } else {
        gRandTableIdx = (gRandTableIdx + 1) & 0x3FF;
        p->timer = p->holdBase + Mod(*(gRandomTable + gRandTableIdx), p->holdRange);
      }
      break;
    }
    case 2: {
      if (VM_SeekToNamedArg('d')) {
        p->speed = VM_GetValue();
      } else {
        p->speed = 0;
      }
      if (VM_SeekToNamedArg('p')) {
        p->angleBase = VM_GetValue();
        p->angleRange = VM_GetValue();
      } else {
        p->angleBase = 3;
        p->angleRange = 3;
      }
      if (VM_SeekToNamedArg('t')) {
        p->holdBase = VM_GetValue();
        p->holdRange = VM_GetValue();
      } else {
        p->holdBase = 0x78;
        p->holdRange = 0x78;
      }
      if (p->angleRange == 0) {
        p->angleTarget = p->angleBase << 4;
      } else {
        gRandTableIdx = (gRandTableIdx + 1) & 0x3FF;
        p->angleTarget = (p->angleBase + Mod(*(gRandomTable + gRandTableIdx), p->angleRange)) << 4;
      }
      if (p->holdRange == 0) {
        p->timer = p->holdBase;
      } else {
        gRandTableIdx = (gRandTableIdx + 1) & 0x3FF;
        p->timer = p->holdBase + Mod(*(gRandomTable + gRandTableIdx), p->holdRange);
      }
      break;
    }
  }
  gWindManager = p;
#else
  INCFUNC("asm/func/WindManager_Init.inc");
#endif
}

// 0xEF66, HashName("風マネージャ")
WindManager* WindManager_Create(u32 id, u32 _) {
  if (gWindManager == NULL) {
    WindManager* p = CreateEntity(ENTITY_UNK_9, sizeof(WindManager));

    if (p != NULL) {
      SetEntityRoutine(p, WindManager_Update, WindManager_Destroy);
      if (WindManager_Init(p, id) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gWindManager;
}
