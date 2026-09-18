#include "camera.h"
#include "entity.h"
#include "global.h"
#include "item.h"
#include "msgbus.h"
#include "random.h"
#include "sound.h"
#include "sprite.h"
#include "vm.h"

// (運搬中の)棺桶?
typedef struct {
  Entity e;             // ENTITY_UNK_8
  EntityMsgBox unk_18;  // 0x18
  u16 q_linked;         // 0x4C, 0 以外なら Init で unk_18 を EntityMsgBus に登録し、Destroy で外す (script keyword 0x4F)
  u16 state;            // 0x4E, PTR_ARRAY_085ac044 の添字, 変更時に stateTimer を 0 に戻す
  u16 coffinID;         // 0x50, GetOwnedCoffinID() の結果, metasprite 番号 (x*7) とパレット行 (x+0x207) を選ぶ
  u16 q_scale;          // 0x52, Init で 0x7F0, >>4 して nodes[0] の拡縮に使う
  u32 q_scriptDelay;    // 0x54, stateTimer がこの値になったら scriptID を実行する (FUN_08089ff0)
  u16 q_height;         // 0x58, script keyword 0x68 (既定 0x400), nodes[0].q_pos.y に加算
  u16 q_heightInit;     // 0x5A, Init で q_height と同じ値, 書き込みのみ
  s16 q_spread;         // 0x5C, script keyword 0x6D (既定 0x200), nodes[1..4] の x/z に ± する
  s16 q_spreadInit;     // 0x5E, Init で q_spread と同じ値, 書き込みのみ
  u16 shakeX;           // 0x60, 棺桶の中の敵が暴れたときの揺れ, (rand & 0x1F) - 0x10, q_pos.x に加算
  u16 shakeZ;           // 0x62, 同上, q_pos.z に加算
  u32 stateTimer;       // 0x64
  u32 scriptID;         // 0x68, Script_ExecById に渡す (script keyword 0x65)
  Vec3 pos;             // 0x6C, 既定は gStat->playerPos (script keyword 0x70), 各ノードの q_pos にコピーされる
  AuxSprite nodes[5];   // 0x74
  AuxSpriteGfx sprite;  // 0x150, Video_GetAuxSprite(&sprite, 0x2499), nodes が共有
  rgb555* pltt;         // 0x16C, plttBuf か gObjPlttData のパレット行を指す (FUN_08089b48)
  rgb555 plttBuf[16];   // 0x170, FUN_08089b48 で2つのパレットをブレンドした結果
} Entity28CB;
static_assert(sizeof(Entity28CB) == 400);

// パレット行 from と to を t/64 の割合でブレンドして pltt にする (t が 0 か 64 ならブレンドせずにそのパレットを指す)
void FUN_08089b48(Entity28CB* p, s32 from, s32 to, s32 t) {
  rgb555* src1 = &gObjPlttData[(from + 0x207) * 16];
  rgb555* src2 = &gObjPlttData[(to + 0x207) * 16];
  rgb555* dst;
  s32 r1, g1, b1, r2, g2, b2;
  s32 i;
  if (t == 0) {
    p->pltt = src1;
  } else if (t == 64) {
    p->pltt = src2;
  } else {
    dst = p->plttBuf;
    for (i = 0; i < 16; i++) {
      r1 = *src1 & (0x1F << 0);
      g1 = *src1 & (0x1F << 5);
      b1 = *src1 & (0x1F << 10);
      r2 = *src2 & (0x1F << 0);
      g2 = *src2 & (0x1F << 5);
      b2 = *src2 & (0x1F << 10);
      r1 = ((64 - t) * r1 + r2 * t) >> 6;
      g1 = ((64 - t) * g1 + g2 * t) >> 6;
      b1 = ((64 - t) * b1 + b2 * t) >> 6;
      r1 &= (0x1F << 0);
      g1 &= (0x1F << 5);
      b1 &= (0x1F << 10);
      *dst = r1 | g1 | b1;
      src1++;
      src2++;
      dst++;
    }
    p->pltt = p->plttBuf;
  }
}

void FUN_08089c44(Entity28CB* p) {
  s32 i;
  for (i = 1; i < 5; i++) {
    p->nodes[i].flags |= SPRFLAG_HIDDEN;
  }
}

void FUN_08089c60(Entity28CB* p) {
  s32 i;
  for (i = 1; i < 5; i++) {
    p->nodes[i].flags |= SPRFLAG_HIDDEN;
  }
}

NAKED bool32 FUN_08089c7c(Entity28CB* p) { INCFUNC("asm/func/FUN_08089c7c.inc"); }

static inline void Entity28CB_SetState(Entity28CB* p, u16 state) {
  p->state = state;
  p->stateTimer = 0;
}

// EntityMsgBus から種類3のコマンドが届くのを待ち、届いたら状態1に進めて効果音を鳴らす
void FUN_08089ce0(Entity28CB* p) {
  s32 i;
  if (FUN_08089c7c(p)) {
    for (i = 1; i < 5; i++) {
      p->nodes[i].flags &= ~SPRFLAG_HIDDEN;
    }
    Entity28CB_SetState(p, 1);
    PlaySound_082406e0(0x1C6);
  }
}

// q_spread を毎フレーム縮め、0 になったら状態2へ進む
void FUN_08089d24(Entity28CB* p) {
  p->q_spread -= 70;
  if (p->q_spread <= 0) {
    p->q_spread = 0;
    Entity28CB_SetState(p, 2);
  } else {
    p->stateTimer++;
  }
}

// 最初の4フレームで揺れ幅を乱数で決め、16フレーム揺らしてから状態3へ進む
void FUN_08089d50(Entity28CB* p) {
  u16* table;
  u32 idx;
  u16 r;
  if (p->stateTimer < 4) {
    table = gRandomTable;
    idx = (gRandTableIdx + 1) & 0x3FF;
    r = table[idx];
    p->shakeX = (r & 0x1F) - 16;
    gRandTableIdx = (idx + 1) & 0x3FF;
    r = table[gRandTableIdx];
    p->shakeZ = (r & 0x1F) - 16;
  }
  if ((p->stateTimer & 3) == 0) {
    FUN_08089c60(p);
  } else if ((p->stateTimer & 3) == 2) {
    FUN_08089c44(p);
  }
  if (p->stateTimer >= 16) {
    p->nodes[0].flags &= ~SPRFLAG_HIDDEN;
    Entity28CB_SetState(p, 3);
  } else {
    p->stateTimer++;
  }
}

NAKED void FUN_08089ddc(Entity28CB* p) { INCFUNC("asm/func/FUN_08089ddc.inc"); }

// 揺らしながらパレットを8番の色へ寄せてから戻し、状態5へ進む
void FUN_08089e98(Entity28CB* p) {
  u16* table;
  u32 idx;
  u16 r;
  table = gRandomTable;
  idx = (gRandTableIdx + 1) & 0x3FF;
  r = table[idx];
  p->shakeX = (r & 0x1F) - 16;
  gRandTableIdx = (idx + 1) & 0x3FF;
  r = table[gRandTableIdx];
  p->shakeZ = (r & 0x1F) - 16;
  if (p->stateTimer < 4) {
    FUN_0823b9cc(40);
    FUN_08089b48(p, p->coffinID, 8, p->stateTimer * 16);
  } else {
    FUN_08089b48(p, 8, p->coffinID, (p->stateTimer - 4) * 16);
  }
  if (p->stateTimer >= 8) {
    p->shakeX = 0;
    p->shakeZ = 0;
    Entity28CB_SetState(p, 5);
  } else {
    p->stateTimer++;
  }
}

// 90フレーム待ってから状態6へ進む
void FUN_08089f38(Entity28CB* p) {
  if (p->stateTimer >= 90) {
    Entity28CB_SetState(p, 6);
  } else {
    p->stateTimer++;
  }
}

// 10〜29 と 60〜79 フレームのあいだ揺らして効果音を鳴らし、90フレームで状態7へ進む
void FUN_08089f58(Entity28CB* p) {
  u16* table;
  u32 idx;
  u16 r;
  if ((10 <= p->stateTimer && p->stateTimer < 30) || (60 <= p->stateTimer && p->stateTimer < 80)) {
    table = gRandomTable;
    idx = (gRandTableIdx + 1) & 0x3FF;
    r = table[idx];
    p->shakeX = (r & 0x1F) - 16;
    gRandTableIdx = (idx + 1) & 0x3FF;
    r = table[gRandTableIdx];
    p->shakeZ = (r & 0x1F) - 16;
  } else {
    p->shakeX = 0;
    p->shakeZ = 0;
  }
  if (p->stateTimer == 10 || p->stateTimer == 20 || p->stateTimer == 60 || p->stateTimer == 70) {
    PlaySound_082406e0(0xD3);
  }
  if (p->stateTimer >= 90) {
    Entity28CB_SetState(p, 7);
  } else {
    p->stateTimer++;
  }
}

// stateTimer が q_scriptDelay に達したら scriptID のスクリプトを1回だけ実行する
void FUN_08089ff0(Entity28CB* p) {
  if (p->stateTimer == p->q_scriptDelay && p->scriptID != 0) {
    Script_ExecById(p->scriptID, NULL);
    p->scriptID = 0;
  }
  p->stateTimer++;
}

void (*const PTR_ARRAY_085ac044[8])(Entity28CB*) = {
    FUN_08089ce0, FUN_08089d24, FUN_08089d50, FUN_08089ddc, FUN_08089e98, FUN_08089f38, FUN_08089f58, FUN_08089ff0,
};

s32 Entity28CB_Update(Entity28CB* p) {
  AuxSprite* node;
  s32 spread;
  s32 i;
  PTR_ARRAY_085ac044[p->state](p);
  if (p->state != 0) {
    for (i = 0; i < 5; i++) {
      node = &p->nodes[i];
      node->q_pos = p->pos;
      spread = p->q_spread;
      switch (i) {
        case 0: {
          node->q_pos.y += p->q_height;
          node->scaleY = node->scaleX = p->q_scale >> 4;
          break;
        }
        case 1: {
          node->q_pos.x -= spread;
          node->q_pos.z -= spread;
          break;
        }
        case 2: {
          node->q_pos.x += spread;
          node->q_pos.z += spread;
          break;
        }
        case 3: {
          node->q_pos.x -= spread;
          node->q_pos.z += spread;
          break;
        }
        case 4: {
          node->q_pos.x += spread;
          node->q_pos.z -= spread;
          break;
        }
      }
      node->q_pos.x += p->shakeX;
      node->q_pos.z += p->shakeZ;
    }
  }
  return 0;
}

s32 Entity28CB_Destroy(Entity28CB* p) {
  s32 i;
  for (i = 0; i < 5; i++) {
    FUN_0822a4e0(&p->nodes[i]);
  }
  if (p->q_linked != 0) {
    EntityMsgBus_Unregister(&p->unk_18);
  }
  return 0;
}

// 貴重品から最初に見つかった棺桶の Coffin ID を返す, 無ければ COFFIN_OAK
u32 GetOwnedCoffinID(void) {
  s32 i;
  for (i = 0; i < 16; i++) {
    u32 coffin = GetValuableItemID(i) - ITEM_OAK_COFFIN;
    if (coffin < COFFIN_NUM) {
      return coffin;
    }
  }
  return COFFIN_OAK;
}

NAKED s32 Entity28CB_Init(Entity28CB* p, u32 id) { INCFUNC("asm/func/Entity28CB_Init.inc"); }

Entity28CB* Entity28CB_Create(u32 id) {
  Entity28CB* p = CreateEntity(ENTITY_UNK_8, sizeof(Entity28CB));
  if (p != NULL) {
    SetEntityRoutine(p, Entity28CB_Update, Entity28CB_Destroy);
    if (Entity28CB_Init(p, id) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
