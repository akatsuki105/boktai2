#include "entity.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "random.h"
#include "sound.h"
#include "sprite.h"
#include "vm.h"

typedef u16 Entity081d16ecItemFlags;  // Entity081d16ecItem.flags
#define E081D16EC_FLAG_0 (1 << 0)     // まだ不明
#define E081D16EC_FLAG_1 (1 << 1)     // まだ不明
#define E081D16EC_FLAG_2 (1 << 2)     // まだ不明
#define E081D16EC_FLAG_3 (1 << 3)     // まだ不明
#define E081D16EC_FLAG_4 (1 << 4)     // まだ不明

// スプライトとヒットボックスを1つずつ持つ
typedef struct Entity081d16ecItem {
  AuxSprite sprite;               // 0x00
  AuxAnimState anim;              // 0x2C
  AuxSpriteGfx gfx;               // 0x3C, SPRITE_LEVER_SWITCH
  Vec3 basePos;                   // 0x58, 揺れの基準位置, sprite.pos へ複写する
  HitboxData hurtbox;             // 0x60, _Destroy が Hitbox_Unregister に渡す
  u16 state;                      // 0xB0, _Update が PTR_ARRAY_085AE0B8[state](p, item) を呼ぶ
  u16 unk_b2;                     // 0xB2
  u16 slotIndex;                  // 0xB4, FUN_081d0eac が確保時に自分のスロット番号を入れる
  Entity081d16ecItemFlags flags;  // 0xB6, see Entity081d16ecItemFlags
  u8 unk_b8[2];                   // 0xB8
  s16 unk_ba;                     // 0xBA, 0 か 1 でパレットを切り替える
  u8 unk_bc;                      // 0xBC
  u8 unk_bd;                      // 0xBD, 0 でない間はパレット 0x132 を強制して減らす
  u16 id;                         // 0xBE
  u16 unk_c0;                     // 0xC0, bit0 で判定に使うフラグを切り替える
  u16 unk_c2;                     // 0xC2
  u16 unk_c4;                     // 0xC4, unk_c2 がこれ以下なら反応する
  u8 unk_c6;                      // 0xC6
  u8 unk_c7;                      // 0xC7, 0 でない間はスプライトを ±10 揺らして減らす
} Entity081d16ecItem;
static_assert(sizeof(Entity081d16ecItem) == 200);

// 最大12個の Entity081d16ecItem をビットマスクで管理するシングルトン
typedef struct {
  Entity e;                      // 0x000, ENTITY_UNK_9
  AuxAnimFile* anim;             // 0x018, ANIM_B952
  Entity081d16ecItem items[12];  // 0x01C
  u32 activeMask;                // 0x97C, bit i が立っていれば items[i] が使用中, _Init が 0 にする
} Entity081d16ec;
static_assert(sizeof(Entity081d16ec) == 2432);

IWRAM_DATA Entity081d16ec* gEntity081d16ec = NULL;  // 0x0300018C

Entity081d16ec* Entity081d16ec_Create(void);
s32 FUN_08014730(s32 count, s32 kind, Vec3* pos, Vec3* vel, Vec3* velRange, s32 lifeBase, s32 lifeRandMask);
void FUN_081d1924(Entity081d16ecItem* item);

static inline bool8 Entity081d16ec_IsActive(u32* mask, s32 i) {
  if (TEST_FLAGS(*mask, 1 << i)) return TRUE;
  return FALSE;
}

void FUN_081d0e74(Entity081d16ecItem* item, Entity081d16ecItemFlags n) { item->flags |= n; }

void FUN_081d0e84(Entity081d16ecItem* item, Entity081d16ecItemFlags n) { item->flags &= ~n; }

bool8 FUN_081d0e94(Entity081d16ecItem* item, Entity081d16ecItemFlags n) {
  if (item->flags & n) {
    return TRUE;
  }
  return FALSE;
}

// 空いているスロットを1つ確保する
Entity081d16ecItem* FUN_081d0eac(Entity081d16ec* p) {
  s32 i;

  for (i = 0; i < 12; i++) {
    if (!Entity081d16ec_IsActive(&p->activeMask, i)) {
      Entity081d16ecItem* item = &p->items[i];

      p->activeMask |= 1 << i;
      ClearMemory(item, sizeof(Entity081d16ecItem));
      item->slotIndex = i;
      return item;
    }
  }
  return NULL;
}

// id の一致する使用中のスロットを探す, なければ NULL
// 残差: 40/39 命令, 原典は p のレジスタをそのまま items[0] からの誘導変数にして, 見つかったときの return をループの前に置くが, こちらは別のレジスタで i から組む (item のローカル変数は試済)
NON_MATCH Entity081d16ecItem* FUN_081d0f08(s32 id) {
#ifdef NONMATCHING_C
  Entity081d16ec* p = gEntity081d16ec;
  s32 i;

  if (p == NULL) {
    return NULL;
  }
  for (i = 0; i < 12; i++) {
    Entity081d16ecItem* item = &p->items[i];

    if (Entity081d16ec_IsActive(&p->activeMask, i) && item->id == id) {
      return item;
    }
  }
  return NULL;
#else
  INCFUNC("asm/func/FUN_081d0f08.inc");
#endif
}

// 0xF04B
// 0xF04B, レバースイッチを1つ置く, '.p' 位置, '.R' 優先度, '.r' 向き, '.n' ID, '.s' 初期フラグ, '.k' 色, '.t' 反応までの回数
// 残差: 261/266 命令, 原典は sprite を r8 に, &unk_ba を r7 に置くが, こちらは逆になって高位レジスタ経由の mov が減る (宣言順, sprite の代入位置は試済)
NON_MATCH void Cmd_F04B(unknown* p) {
#ifdef NONMATCHING_C
  Entity081d16ec* e = gEntity081d16ec;
  Entity081d16ecItem* item;
  AuxSprite* sprite;

  if (e == NULL) {
    e = Entity081d16ec_Create();
    if (e == NULL) {
      return;
    }
  }
  item = FUN_081d0eac(e);
  if (item == NULL) {
    return;
  }
  sprite = &item->sprite;
  Video_GetAuxSprite(&item->gfx, SPRITE_LEVER_SWITCH);
  AuxSprite_Add(&item->sprite, &item->gfx, 0);
  item->state = 1;
  item->unk_c6 = 1;
  if (VM_SeekToNamedArg('p')) {
    item->sprite.pos.x = VM_GetValue();
    item->sprite.pos.y = VM_GetValue();
    item->sprite.pos.z = VM_GetValue();
  }
  item->basePos = item->sprite.pos;
  item->sprite.priority = VM_GetNamedArgValue('R', 2);
  item->unk_bc = VM_GetNamedArgValue('r', 0);
  item->id = VM_GetNamedArgValue('n', 0);
  item->unk_b2 = VM_GetNamedArgValue('C', 0);
  item->flags = VM_GetNamedArgValue('s', 1);
  item->unk_ba = VM_GetNamedArgValue('k', 0);
  item->unk_c2 = VM_GetNamedArgValue('t', 0);
  if (item->unk_c2) {
    FUN_081d0e74(item, E081D16EC_FLAG_2);
  }
  switch (item->unk_ba) {
    case 0: {
      Video_SetAuxSpritePltt(item->sprite.gfx, OBP_LEVER_SWITCH);
      break;
    }
    case 1: {
      Video_SetAuxSpritePltt(item->sprite.gfx, OBP_LEVER_SWITCH_RUSTY);
      break;
    }
  }
  if (FUN_081d0e94(item, E081D16EC_FLAG_0)) {
    AuxAnim_SetAnim(&item->anim, e->anim, 0, 0, item->unk_bc);
  } else {
    AuxAnim_SetAnim(&item->anim, e->anim, 2, 0, item->unk_bc);
  }
  item->unk_c0 = item->flags;
  AuxSprite_AdvanceAnim(sprite, &item->anim);
  FUN_081d1924(item);
#else
  INCFUNC("asm/func/Cmd_F04B.inc");
#endif
}

// 開閉アニメーションを折り返す, まだ再生していなければ頭から始める
void FUN_081d11b8(Entity081d16ecItem* item) {
  Entity081d16ec* p = gEntity081d16ec;

  PlaySound_082406e0(SE_LEVER_TOGGLE);
  if (item->state == 2) {
    if (item->anim.flags & ANIM_PLAY_REVERSE) {
      item->anim.flags &= ~ANIM_PLAY_REVERSE;
    } else {
      item->anim.flags |= ANIM_PLAY_REVERSE;
    }
    item->anim.tick = item->anim.wait - item->anim.tick;
  } else {
    if (FUN_081d0e94(item, E081D16EC_FLAG_0)) {
      AuxAnim_SetAnim(&item->anim, p->anim, 1, 0, item->unk_bc);
      FUN_081d0e84(item, E081D16EC_FLAG_0);
    } else {
      AuxAnim_SetAnim(&item->anim, p->anim, 1, 0, item->unk_bc | ANIM_PLAY_REVERSE);
      FUN_081d0e84(item, E081D16EC_FLAG_1);
    }
    item->state = 2;
  }
}

// 無敵時間を数えつつ、点滅用のパレットを選ぶ
NON_MATCH void FUN_081d1260(Entity081d16ecItem* item) {
#ifdef NONMATCHING_C
  if (item->hurtbox.invincibleTime != 0) {
    item->hurtbox.flags |= HBFLAG_HIDDEN;
    item->hurtbox.invincibleTime--;
  } else {
    item->hurtbox.flags &= ~HBFLAG_HIDDEN;
  }
  if (item->unk_bd != 0) {
    Video_SetAuxSpritePltt(item->sprite.gfx, OBP_WHITE_306);
    item->unk_bd--;
  } else {
    switch (item->unk_ba) {
      case 0: {
        Video_SetAuxSpritePltt(item->sprite.gfx, OBP_LEVER_SWITCH);
        break;
      }
      case 1: {
        Video_SetAuxSpritePltt(item->sprite.gfx, OBP_LEVER_SWITCH_RUSTY);
        break;
      }
    }
  }
#else
  INCFUNC("asm/func/FUN_081d1260.inc");
#endif
}

// state 2 のハンドラ, 開閉アニメが終わったら止めた側の絵にして, unk_b2 のスクリプトに id とフラグを渡して呼ぶ
void FUN_081d12e0(Entity081d16ec* p, Entity081d16ecItem* item) {
  FUN_081d1260(item);
  if (AuxSprite_AdvanceAnim(&item->sprite, &item->anim)) {
    u32 argv[2];
    ScriptArgs args;

    if (item->anim.flags & ANIM_PLAY_REVERSE) {
      AuxAnim_SetAnim(&item->anim, p->anim, 0, 0, item->unk_bc);
      FUN_081d0e74(item, E081D16EC_FLAG_0);
    } else {
      AuxAnim_SetAnim(&item->anim, p->anim, 2, 0, item->unk_bc);
      FUN_081d0e74(item, E081D16EC_FLAG_1);
    }
    item->state = 1;
    item->unk_c6 = 1;
    argv[0] = item->id;
    argv[1] = item->flags;
    args.argv = argv;
    args.argc = 2;
    VM_ExecByID(item->unk_b2, &args);
  }
}

// state 0 のハンドラ, 何もしない
void FUN_081d146c(Entity081d16ec* p, Entity081d16ecItem* item) {}

// 条件が揃っていれば無敵時間を置いて開閉を始める
void FUN_081d1470(Entity081d16ecItem* item) {
  if (FUN_081d0e94(item, E081D16EC_FLAG_2)) {
    if (!(item->unk_c0 & 1 ? FUN_081d0e94(item, E081D16EC_FLAG_0) : FUN_081d0e94(item, E081D16EC_FLAG_1))) {
      item->hurtbox.flags |= HBFLAG_HIDDEN;
      if (!FUN_081d0e94(item, E081D16EC_FLAG_3)) {
        if (item->unk_c2 <= item->unk_c4) {
          item->hurtbox.invincibleTime = 24;
          FUN_081d11b8(item);
        }
      }
    }
  }
}

void FUN_081d1744(Entity081d16ecItem* item);

// 待機中, アニメを1コマ進め, 点滅・開閉の判定・揺れを更新して経過フレームを数える
void FUN_081d14e0(Entity081d16ec* p, Entity081d16ecItem* item) {
  if (item->unk_c6) {
    item->unk_c4 = 0;
    item->sprite.flags &= ~SPRFLAG_HIDDEN;
    item->unk_c6 = 0;
  }
  AuxSprite_AdvanceAnim(&item->sprite, &item->anim);
  FUN_081d1260(item);
  FUN_081d1470(item);
  FUN_081d1744(item);
  item->unk_c4++;
}

// state 3 のハンドラ, 何もしない
void FUN_081d15f8(Entity081d16ec* p, Entity081d16ecItem* item) {}

void (*const PTR_ARRAY_085ae0b8[4])(Entity081d16ec*, Entity081d16ecItem*) = {
    FUN_081d146c,
    FUN_081d14e0,
    FUN_081d12e0,
    FUN_081d15f8,
};  // 0x085AE0B8

// 使用中のスロットごとに state のハンドラを呼ぶ
s32 Entity081d16ec_Update(Entity081d16ec* p) {
  Entity081d16ecItem* items = p->items;
  s32 i;

  if (p->activeMask == 0) {
    return 0;
  }
  for (i = 0; i < 12; i++) {
    if (Entity081d16ec_IsActive(&p->activeMask, i)) {
      PTR_ARRAY_085ae0b8[items[i].state](p, &items[i]);
    }
  }
  return 0;
}

s32 Entity081d16ec_Destroy(Entity081d16ec* p) {
  s32 i;

  for (i = 0; i < 12; i++) {
    if (Entity081d16ec_IsActive(&p->activeMask, i)) {
      AuxSprite_Remove(&p->items[i].sprite);
      Hitbox_Unregister(&p->items[i].hurtbox);
    }
  }
  gEntity081d16ec = NULL;
  return 0;
}

s32 Entity081d16ec_Init(Entity081d16ec* p) {
  p->anim = GetFile(DIR_ANIMATION, ANIM_B952);
  gEntity081d16ec = p;
  p->activeMask = 0;
  return 0;
}

Entity081d16ec* Entity081d16ec_Create(void) {
  Entity081d16ec* p;

  if (gEntity081d16ec != NULL) {
    return gEntity081d16ec;
  }
  p = CreateEntity(ENTITY_UNK_9, sizeof(Entity081d16ec));
  if (p != NULL) {
    SetEntityRoutine(p, Entity081d16ec_Update, Entity081d16ec_Destroy);
    if (Entity081d16ec_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

void FUN_081d1738(void) { gEntity081d16ec = NULL; }

// 被弾中はスプライトを基準位置から ±10 の範囲で揺らす
void FUN_081d1744(Entity081d16ecItem* item) {
  if (item->unk_c7 == 0) {
    item->sprite.pos = item->basePos;
  } else {
    u16* table = gRandomTable;
    item->sprite.pos.x = item->basePos.x + Mod(_Random(table), 20) - 10;
    item->sprite.pos.z = item->basePos.z + Mod(_Random(table), 20) - 10;
    item->unk_c7--;
  }
}

// レバーへの攻撃を受けたとき, 色に合う武器で叩かれていなければ揺らすだけ, 合っていれば向きを切り替える
// 残差: 155/152 命令, 原典は色ごとの武器マスクを r1 に作って1つの判定に合流させ, その他の色は判定を飛ばすが, こちらは判定が色ごとに残る (マスクの static inline にすると前半は一致するが, unk_bd の 3 が後半の & 3 と共有されて残差が残る)
NON_MATCH void FUN_081d17c8(HitboxData* a, HitboxData* b, Entity081d16ecItem* item) {
#ifdef NONMATCHING_C
  if (FUN_081d0e94(item, E081D16EC_FLAG_4) || (item->unk_ba == 1 && !(a->weakness & (1 << WK_HAMMER))) || (item->unk_ba == 0 && !(a->weakness & ((1 << WK_SWORD) | (1 << WK_SPEAR) | (1 << WK_HAMMER) | (1 << WK_GUN))))) {
    if (item->unk_c7 == 0) {
      PlaySound_082406e0(SE_LEVER_NO_TOGGLE);
    }
    item->unk_c7 = 10;
    return;
  }
  if (item->hurtbox.invincibleTime == 0) {
    item->unk_bd = 3;
    item->hurtbox.invincibleTime = 24;
    FUN_081d11b8(item);
    if (item->unk_ba == 1) {
      Vec3 vel;
      Vec3 velRange;
      u16* table;

      CpuFill32(0, &vel, sizeof(vel));
      vel.y = 16;
      table = gRandomTable;
      velRange.x = (_Random(table) & 3) + 15;
      velRange.y = (_Random(table) & 7) + 15;
      velRange.z = (_Random(table) & 3) + 15;
      FUN_08014730((_Random(table) & 3) + 2, 0x11, &item->sprite.pos, &vel, &velRange, 12, 15);
    }
    if (FUN_081d0e94(item, E081D16EC_FLAG_3)) {
      FUN_081d0e74(item, E081D16EC_FLAG_4);
    }
  }
#else
  INCFUNC("asm/func/FUN_081d17c8.inc");
#endif
}

void FUN_081d1924(Entity081d16ecItem* item) {
  HitboxData* hurtbox = &item->hurtbox;
  Vec3 offset, halfSize;

  VEC3_SET(offset, 0, Q8(0.5), 0);
  VEC3_SET(halfSize, Q8(0.25), Q8(0.5), Q8(0.25));
  hurtbox->id = item->id;
  Hitbox_Init(hurtbox, 0, HBFLAG_HURTBOX | HBFLAG_UNK_0, 0, HIM_4, &halfSize, &offset);
  Hitbox_SetPos(hurtbox, &item->sprite.pos, 0);
  Hitbox_SetHandler(hurtbox, FUN_081d17c8, item);
  Hitbox_Register(hurtbox);
}

// 0xDFAB, '.n' が指す要素のフラグを返す
s32 Cmd_DFAB(void) {
  s32 id = VM_GetNamedArgValue('n', 0);

  if (id != 0) {
    Entity081d16ecItem* item = FUN_081d0f08(id);
    if (item != NULL) {
      return item->flags;
    }
  }
  return -1;
}

// 0x2207
void Cmd_2207(void) {
  s32 id = VM_GetNamedArgValue('n', 0);

  if (id != 0) {
    Entity081d16ecItem* item = FUN_081d0f08(id);

    if (item != NULL) {
      FUN_081d0e74(item, E081D16EC_FLAG_4 | E081D16EC_FLAG_3);
      FUN_081d0e84(item, E081D16EC_FLAG_2);
    }
  }
}

// 0x820B, '.n' が指す要素を '.c' のビットに応じて開閉させる
void Cmd_820B(void) {
  s32 id = VM_GetNamedArgValue('n', 0);

  if (id != 0) {
    Entity081d16ecItem* item = FUN_081d0f08(id);

    if (item != NULL) {
      s32 mode = VM_GetNamedArgValue('c', 0);

      if (mode & 1) {
        if (!FUN_081d0e94(item, E081D16EC_FLAG_0)) {
          item->hurtbox.invincibleTime = 24;
          FUN_081d11b8(item);
          FUN_081d0e74(item, E081D16EC_FLAG_4);
        }
      } else if (mode & 2) {
        if (!FUN_081d0e94(item, E081D16EC_FLAG_1)) {
          item->hurtbox.invincibleTime = 24;
          FUN_081d11b8(item);
          FUN_081d0e74(item, E081D16EC_FLAG_4);
        }
      }
    }
  }
}

// 0x0101
void Cmd_0101(void) {
  s32 id = VM_GetNamedArgValue('n', 0);

  if (id != 0) {
    Entity081d16ecItem* item = FUN_081d0f08(id);

    if (item != NULL) {
      FUN_081d0e84(item, E081D16EC_FLAG_4);
    }
  }
}
