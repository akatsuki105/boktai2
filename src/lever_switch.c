#include "eff_scatter.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "random.h"
#include "sound.h"
#include "sprite.h"
#include "vm.h"

#define LEVER_NORMAL 0  // 通常のレバースイッチ
#define LEVER_RUSTY 1   // 錆びたレバースイッチ (WK_HAMMER でしか反応しない)

typedef u16 LeverSwitchFlags;       // LeverSwitch.flags
#define LEVER_FLAG_POS0 (1 << 0)    // 片側 (アニメ 0) に倒れている
#define LEVER_FLAG_POS1 (1 << 1)    // 反対側 (アニメ 2) に倒れている
#define LEVER_FLAG_AUTO (1 << 2)    // autoToggleDelay フレーム経つと自動で切り替わる, '.t' があれば立つ
#define LEVER_FLAG_ONCE (1 << 3)    // 叩いて1回切り替えたら LEVER_FLAG_LOCKED になる, 自動の切り替えもしない
#define LEVER_FLAG_LOCKED (1 << 4)  // 固定されていて叩いても揺れるだけ

// レバースイッチ1本, 叩くか自動で左右に倒れ, 倒れ終わると scriptID のスクリプトを呼ぶ
typedef struct LeverSwitch {
  AuxSprite sprite;        // 0x00
  AuxAnimState anim;       // 0x2C
  AuxSpriteGfx gfx;        // 0x3C, SPRITE_LEVER_SWITCH
  Vec3 basePos;            // 0x58, 揺れの基準位置, sprite.pos へ複写する
  HitboxData hurtbox;      // 0x60
  u16 state;               // 0xB0, 0: なし, 1: 待機, 2: 切り替え中, sLeverSwitchStates の添字
  u16 scriptID;            // 0xB2, '.C', 倒れ終わるたびに id と flags を引数にして実行するスクリプト ID
  u16 slotIndex;           // 0xB4, LeverSwitchManager.items の添字
  LeverSwitchFlags flags;  // 0xB6, see LeverSwitchFlags
  u8 unk_b8[2];            // 0xB8
  s16 kind;                // 0xBA, 0: LEVER_NORMAL, 1: LEVER_RUSTY
  u8 animFlags;            // 0xBC, '.r', 向き, AuxAnim_SetAnim にアニメのフラグとして渡す
  u8 flashTimer;           // 0xBD, 叩かれて白く光る残りフレーム, 0 でない間はパレット 306 にする
  u16 id;                  // 0xBE, '.n', スクリプトから LeverSwitch_FindByID で引く ID
  u16 initFlags;           // 0xC0, 置いたときの flags, bit0 が立っていれば自動の切り替えは LEVER_FLAG_POS0 に向かう
  u16 autoToggleDelay;     // 0xC2, '.t', 待機してから自動で切り替わるまでのフレーム数
  u16 idleFrames;          // 0xC4, 待機に入ってからのフレーム数
  u8 stateBegun;           // 0xC6, 待機に入った直後だけ立つ
  u8 shakeTimer;           // 0xC7, 切り替わらずに揺れる残りフレーム, 0 でない間はスプライトを ±10 揺らす
} LeverSwitch;
static_assert(sizeof(LeverSwitch) == 200);

// マップ上のレバースイッチを最大12本まとめて動かすシングルトン, 最初のレバーを置くときに作られる
typedef struct {
  Entity e;               // 0x000, ENTITY_UNK_9
  AuxAnimFile* anim;      // 0x018, ANIM_B952
  LeverSwitch items[12];  // 0x01C
  u32 activeMask;         // 0x97C, bit i が立っていれば items[i] が使用中
} LeverSwitchManager;
static_assert(sizeof(LeverSwitchManager) == 2432);

IWRAM_DATA LeverSwitchManager* gLeverSwitchManager = NULL;  // 0x0300018C

LeverSwitchManager* LeverSwitchManager_Create(void);
void LeverSwitch_InitHurtbox(LeverSwitch* item);

static inline bool8 LeverSwitchManager_IsActive(u32* mask, s32 i) {
  if (TEST_FLAGS(*mask, 1 << i)) return TRUE;
  return FALSE;
}

void LeverSwitch_SetFlags(LeverSwitch* item, LeverSwitchFlags n) { item->flags |= n; }

void LeverSwitch_ClearFlags(LeverSwitch* item, LeverSwitchFlags n) { item->flags &= ~n; }

bool8 LeverSwitch_TestFlags(LeverSwitch* item, LeverSwitchFlags n) {
  if (item->flags & n) {
    return TRUE;
  }
  return FALSE;
}

// 空いているスロットを1つ確保する
LeverSwitch* LeverSwitchManager_Alloc(LeverSwitchManager* p) {
  s32 i;

  for (i = 0; i < 12; i++) {
    if (!LeverSwitchManager_IsActive(&p->activeMask, i)) {
      LeverSwitch* item = &p->items[i];

      p->activeMask |= 1 << i;
      ClearMemory(item, sizeof(LeverSwitch));
      item->slotIndex = i;
      return item;
    }
  }
  return NULL;
}

// id の一致する使用中のスロットを探す, なければ NULL
// 残差: 40/39 命令, 原典は p のレジスタをそのまま items[0] からの誘導変数にして, 見つかったときの return をループの前に置くが, こちらは別のレジスタで i から組む (item のローカル変数は試済)
NON_MATCH LeverSwitch* LeverSwitch_FindByID(s32 id) {
#ifdef NONMATCHING_C
  LeverSwitchManager* p = gLeverSwitchManager;
  s32 i;

  if (p == NULL) {
    return NULL;
  }
  for (i = 0; i < 12; i++) {
    LeverSwitch* item = &p->items[i];

    if (LeverSwitchManager_IsActive(&p->activeMask, i) && item->id == id) {
      return item;
    }
  }
  return NULL;
#else
  INCFUNC("asm/func/LeverSwitch_FindByID.inc");
#endif
}

// 0xF04B, レバースイッチを1つ置く, '.p' 位置, '.R' 優先度, '.r' 向き, '.n' ID, '.s' 初期フラグ, '.k' 種類, '.t' 反応までの回数
// 残差: 261/266 命令, 原典は sprite を r8 に, &kind を r7 に置くが, こちらは逆になって高位レジスタ経由の mov が減る (宣言順, sprite の代入位置は試済)
NON_MATCH void Cmd_F04B(void) {
#ifdef NONMATCHING_C
  LeverSwitchManager* e = gLeverSwitchManager;
  LeverSwitch* item;
  AuxSprite* sprite;

  if (e == NULL) {
    e = LeverSwitchManager_Create();
    if (e == NULL) {
      return;
    }
  }
  item = LeverSwitchManager_Alloc(e);
  if (item == NULL) {
    return;
  }
  sprite = &item->sprite;
  Video_GetAuxSprite(&item->gfx, SPRITE_LEVER_SWITCH);
  AuxSprite_Add(&item->sprite, &item->gfx, 0);
  item->state = 1;
  item->stateBegun = 1;
  if (VM_SeekToNamedArg('p')) {
    item->sprite.pos.x = VM_GetValue();
    item->sprite.pos.y = VM_GetValue();
    item->sprite.pos.z = VM_GetValue();
  }
  item->basePos = item->sprite.pos;
  item->sprite.priority = VM_GetNamedArgValue('R', 2);
  item->animFlags = VM_GetNamedArgValue('r', 0);
  item->id = VM_GetNamedArgValue('n', 0);
  item->scriptID = VM_GetNamedArgValue('C', 0);
  item->flags = VM_GetNamedArgValue('s', 1);
  item->kind = VM_GetNamedArgValue('k', 0);
  item->autoToggleDelay = VM_GetNamedArgValue('t', 0);
  if (item->autoToggleDelay) {
    LeverSwitch_SetFlags(item, LEVER_FLAG_AUTO);
  }
  switch (item->kind) {
    case LEVER_NORMAL: {
      Video_SetAuxSpritePltt(item->sprite.gfx, OBP_LEVER_SWITCH);
      break;
    }
    case LEVER_RUSTY: {
      Video_SetAuxSpritePltt(item->sprite.gfx, OBP_LEVER_SWITCH_RUSTY);
      break;
    }
  }
  if (LeverSwitch_TestFlags(item, LEVER_FLAG_POS0)) {
    AuxAnim_SetAnim(&item->anim, e->anim, 0, 0, item->animFlags);
  } else {
    AuxAnim_SetAnim(&item->anim, e->anim, 2, 0, item->animFlags);
  }
  item->initFlags = item->flags;
  AuxSprite_AdvanceAnim(sprite, &item->anim);
  LeverSwitch_InitHurtbox(item);
#else
  INCFUNC("asm/func/Cmd_F04B.inc");
#endif
}

// 開閉アニメーションを折り返す, まだ再生していなければ頭から始める
void LeverSwitch_Toggle(LeverSwitch* item) {
  LeverSwitchManager* p = gLeverSwitchManager;

  PlaySound_082406e0(SE_LEVER_TOGGLE);
  if (item->state == 2) {
    if (item->anim.flags & ANIM_PLAY_REVERSE) {
      item->anim.flags &= ~ANIM_PLAY_REVERSE;
    } else {
      item->anim.flags |= ANIM_PLAY_REVERSE;
    }
    item->anim.tick = item->anim.wait - item->anim.tick;
  } else {
    if (LeverSwitch_TestFlags(item, LEVER_FLAG_POS0)) {
      AuxAnim_SetAnim(&item->anim, p->anim, 1, 0, item->animFlags);
      LeverSwitch_ClearFlags(item, LEVER_FLAG_POS0);
    } else {
      AuxAnim_SetAnim(&item->anim, p->anim, 1, 0, item->animFlags | ANIM_PLAY_REVERSE);
      LeverSwitch_ClearFlags(item, LEVER_FLAG_POS1);
    }
    item->state = 2;
  }
}

// 無敵時間を数えつつ、点滅用のパレットを選ぶ
NON_MATCH void LeverSwitch_UpdateFlash(LeverSwitch* item) {
#ifdef NONMATCHING_C
  if (item->hurtbox.iframes != 0) {
    item->hurtbox.flags |= HBFLAG_HIDDEN;
    item->hurtbox.iframes--;
  } else {
    item->hurtbox.flags &= ~HBFLAG_HIDDEN;
  }
  if (item->flashTimer != 0) {
    Video_SetAuxSpritePltt(item->sprite.gfx, OBP_WHITE_306);
    item->flashTimer--;
  } else {
    switch (item->kind) {
      case LEVER_NORMAL: {
        Video_SetAuxSpritePltt(item->sprite.gfx, OBP_LEVER_SWITCH);
        break;
      }
      case LEVER_RUSTY: {
        Video_SetAuxSpritePltt(item->sprite.gfx, OBP_LEVER_SWITCH_RUSTY);
        break;
      }
    }
  }
#else
  INCFUNC("asm/func/LeverSwitch_UpdateFlash.inc");
#endif
}

// state 2 のハンドラ, 開閉アニメが終わったら止めた側の絵にして, scriptID のスクリプトに id とフラグを渡して呼ぶ
void LeverSwitch_StateToggling(LeverSwitchManager* p, LeverSwitch* item) {
  LeverSwitch_UpdateFlash(item);
  if (AuxSprite_AdvanceAnim(&item->sprite, &item->anim)) {
    u32 argv[2];
    ScriptArgs args;

    if (item->anim.flags & ANIM_PLAY_REVERSE) {
      AuxAnim_SetAnim(&item->anim, p->anim, 0, 0, item->animFlags);
      LeverSwitch_SetFlags(item, LEVER_FLAG_POS0);
    } else {
      AuxAnim_SetAnim(&item->anim, p->anim, 2, 0, item->animFlags);
      LeverSwitch_SetFlags(item, LEVER_FLAG_POS1);
    }
    item->state = 1;
    item->stateBegun = 1;
    argv[0] = item->id;
    argv[1] = item->flags;
    args.argv = argv;
    args.argc = 2;
    VM_ExecByID(item->scriptID, &args);
  }
}

// state 0 のハンドラ, 何もしない
void LeverSwitch_StateNone(LeverSwitchManager* p, LeverSwitch* item) {}

// 条件が揃っていれば無敵時間を置いて開閉を始める
void LeverSwitch_TryAutoToggle(LeverSwitch* item) {
  if (LeverSwitch_TestFlags(item, LEVER_FLAG_AUTO)) {
    if (!(item->initFlags & 1 ? LeverSwitch_TestFlags(item, LEVER_FLAG_POS0) : LeverSwitch_TestFlags(item, LEVER_FLAG_POS1))) {
      item->hurtbox.flags |= HBFLAG_HIDDEN;
      if (!LeverSwitch_TestFlags(item, LEVER_FLAG_ONCE)) {
        if (item->autoToggleDelay <= item->idleFrames) {
          item->hurtbox.iframes = 24;
          LeverSwitch_Toggle(item);
        }
      }
    }
  }
}

void LeverSwitch_UpdateShake(LeverSwitch* item);

// 待機中, アニメを1コマ進め, 点滅・開閉の判定・揺れを更新して経過フレームを数える
void LeverSwitch_StateIdle(LeverSwitchManager* p, LeverSwitch* item) {
  if (item->stateBegun) {
    item->idleFrames = 0;
    item->sprite.flags &= ~SPRFLAG_HIDDEN;
    item->stateBegun = 0;
  }
  AuxSprite_AdvanceAnim(&item->sprite, &item->anim);
  LeverSwitch_UpdateFlash(item);
  LeverSwitch_TryAutoToggle(item);
  LeverSwitch_UpdateShake(item);
  item->idleFrames++;
}

// state 3 のハンドラ, 何もしない
void FUN_081d15f8(LeverSwitchManager* p, LeverSwitch* item) {}

void (*const sLeverSwitchStates[4])(LeverSwitchManager*, LeverSwitch*) = {
    LeverSwitch_StateNone,
    LeverSwitch_StateIdle,
    LeverSwitch_StateToggling,
    FUN_081d15f8,
};  // 0x085AE0B8

// 使用中のスロットごとに state のハンドラを呼ぶ
s32 LeverSwitchManager_Update(LeverSwitchManager* p) {
  LeverSwitch* items = p->items;
  s32 i;

  if (p->activeMask == 0) {
    return 0;
  }
  for (i = 0; i < 12; i++) {
    if (LeverSwitchManager_IsActive(&p->activeMask, i)) {
      sLeverSwitchStates[items[i].state](p, &items[i]);
    }
  }
  return 0;
}

s32 LeverSwitchManager_Destroy(LeverSwitchManager* p) {
  s32 i;

  for (i = 0; i < 12; i++) {
    if (LeverSwitchManager_IsActive(&p->activeMask, i)) {
      AuxSprite_Remove(&p->items[i].sprite);
      Hitbox_Unregister(&p->items[i].hurtbox);
    }
  }
  gLeverSwitchManager = NULL;
  return 0;
}

s32 LeverSwitchManager_Init(LeverSwitchManager* p) {
  p->anim = GetFile(DIR_ANIMATION, ANIM_B952);
  gLeverSwitchManager = p;
  p->activeMask = 0;
  return 0;
}

LeverSwitchManager* LeverSwitchManager_Create(void) {
  LeverSwitchManager* p;

  if (gLeverSwitchManager != NULL) {
    return gLeverSwitchManager;
  }
  p = CreateEntity(ENTITY_UNK_9, sizeof(LeverSwitchManager));
  if (p != NULL) {
    SetEntityRoutine(p, LeverSwitchManager_Update, LeverSwitchManager_Destroy);
    if (LeverSwitchManager_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

void LeverSwitchManager_ClearGlobal(void) { gLeverSwitchManager = NULL; }

// 被弾中はスプライトを基準位置から ±10 の範囲で揺らす
void LeverSwitch_UpdateShake(LeverSwitch* item) {
  if (item->shakeTimer == 0) {
    item->sprite.pos = item->basePos;
  } else {
    u16* table = gRandomTable;
    item->sprite.pos.x = item->basePos.x + Mod(_Random(table), 20) - 10;
    item->sprite.pos.z = item->basePos.z + Mod(_Random(table), 20) - 10;
    item->shakeTimer--;
  }
}

// レバーへの攻撃を受けたとき, 色に合う武器で叩かれていなければ揺らすだけ, 合っていれば向きを切り替える
// 残差: 155/152 命令, 原典は色ごとの武器マスクを r1 に作って1つの判定に合流させ, その他の色は判定を飛ばすが, こちらは判定が色ごとに残る (マスクの static inline にすると前半は一致するが, flashTimer の 3 が後半の & 3 と共有されて残差が残る)
NON_MATCH void LeverSwitch_OnHurt(HitboxData* a, HitboxData* b, LeverSwitch* item) {
#ifdef NONMATCHING_C
  if (LeverSwitch_TestFlags(item, LEVER_FLAG_LOCKED) || (item->kind == LEVER_RUSTY && !(a->weakness & (1 << WK_HAMMER))) || (item->kind == LEVER_NORMAL && !(a->weakness & ((1 << WK_SWORD) | (1 << WK_SPEAR) | (1 << WK_HAMMER) | (1 << WK_GUN))))) {
    if (item->shakeTimer == 0) {
      PlaySound_082406e0(SE_LEVER_NO_TOGGLE);
    }
    item->shakeTimer = 10;
    return;
  }
  if (item->hurtbox.iframes == 0) {
    item->flashTimer = 3;
    item->hurtbox.iframes = 24;
    LeverSwitch_Toggle(item);
    if (item->kind == LEVER_RUSTY) {
      Vec3 vel;
      Vec3 velRange;
      u16* table;

      CpuFill32(0, &vel, sizeof(vel));
      vel.y = 16;
      table = gRandomTable;
      velRange.x = (_Random(table) & 3) + 15;
      velRange.y = (_Random(table) & 7) + 15;
      velRange.z = (_Random(table) & 3) + 15;
      ScatterEffect_Spawn((_Random(table) & 3) + 2, SCATTER_KIND_17, &item->sprite.pos, &vel, &velRange, 12, 15);
    }
    if (LeverSwitch_TestFlags(item, LEVER_FLAG_ONCE)) {
      LeverSwitch_SetFlags(item, LEVER_FLAG_LOCKED);
    }
  }
#else
  INCFUNC("asm/func/LeverSwitch_OnHurt.inc");
#endif
}

void LeverSwitch_InitHurtbox(LeverSwitch* item) {
  HitboxData* hurtbox = &item->hurtbox;
  Vec3 offset, halfSize;

  VEC3_SET(offset, 0, Q8(0.5), 0);
  VEC3_SET(halfSize, Q8(0.25), Q8(0.5), Q8(0.25));
  hurtbox->id = item->id;
  Hitbox_Init(hurtbox, 0, HBFLAG_HURTBOX | HBFLAG_UNK_0, 0, HIM_4, &halfSize, &offset);
  Hitbox_SetPos(hurtbox, &item->sprite.pos, 0);
  Hitbox_SetHandler(hurtbox, LeverSwitch_OnHurt, item);
  Hitbox_Register(hurtbox);
}

// 0xDFAB, '.n' のレバーの flags を返す, 無ければ -1
s32 Cmd_DFAB(void) {
  s32 id = VM_GetNamedArgValue('n', 0);

  if (id != 0) {
    LeverSwitch* item = LeverSwitch_FindByID(id);
    if (item != NULL) {
      return item->flags;
    }
  }
  return -1;
}

// 0x2207, '.n' のレバーを固定し, 自動の切り替えも止める
void Cmd_2207(void) {
  s32 id = VM_GetNamedArgValue('n', 0);

  if (id != 0) {
    LeverSwitch* item = LeverSwitch_FindByID(id);

    if (item != NULL) {
      LeverSwitch_SetFlags(item, LEVER_FLAG_LOCKED | LEVER_FLAG_ONCE);
      LeverSwitch_ClearFlags(item, LEVER_FLAG_AUTO);
    }
  }
}

// 0x820B, '.n' のレバーを '.c' の bit0 なら LEVER_FLAG_POS0 側, bit1 なら LEVER_FLAG_POS1 側へ倒して固定する
void Cmd_820B(void) {
  s32 id = VM_GetNamedArgValue('n', 0);

  if (id != 0) {
    LeverSwitch* item = LeverSwitch_FindByID(id);

    if (item != NULL) {
      s32 mode = VM_GetNamedArgValue('c', 0);

      if (mode & 1) {
        if (!LeverSwitch_TestFlags(item, LEVER_FLAG_POS0)) {
          item->hurtbox.iframes = 24;
          LeverSwitch_Toggle(item);
          LeverSwitch_SetFlags(item, LEVER_FLAG_LOCKED);
        }
      } else if (mode & 2) {
        if (!LeverSwitch_TestFlags(item, LEVER_FLAG_POS1)) {
          item->hurtbox.iframes = 24;
          LeverSwitch_Toggle(item);
          LeverSwitch_SetFlags(item, LEVER_FLAG_LOCKED);
        }
      }
    }
  }
}

// 0x0101, '.n' のレバーの固定を解く
void Cmd_0101(void) {
  s32 id = VM_GetNamedArgValue('n', 0);

  if (id != 0) {
    LeverSwitch* item = LeverSwitch_FindByID(id);

    if (item != NULL) {
      LeverSwitch_ClearFlags(item, LEVER_FLAG_LOCKED);
    }
  }
}
