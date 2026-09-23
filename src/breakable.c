#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "malloc.h"
#include "random.h"
#include "sound.h"
#include "sprite_aux.h"
#include "vm.h"

struct Breakable;
struct BreakableManager;
typedef void (*BreakableUpdate)(struct BreakableManager*, struct Breakable*);

// マップに置かれた壊せるオブジェクト1個。スクリプトコマンド 0x2D8F (Breakable_Spawn) が1個ずつ置く
// 大聖堂の狛犬(壊すと宝箱が出現するやつ)で使っているが、他の壊せるオブジェクトでも流用可能っぽい(実際に流用されているかは不明)
typedef struct Breakable {
  u16 id;                  // 0x00, kw: '.n', hitbox の ID になり、壊れたときのスクリプトの argv[0] にもなる
  bool8 active;            // 0x02, BreakableManager_FindFreeSlot が 0 のスロットを空きとして返す。Update は 0 のものを飛ばす
  bool8 stateChanged;      // 0x03, Breakable_SetUpdate が 1 にし、Breakable_TakeStateChanged が読んで 0 に戻す
  s16 hp;                  // 0x04, kw: '.l' (default: 10), Breakable_OnHit が相手の HitboxData.damage を引き、1 未満で Breakable_UpdateAlive が破壊処理へ進む
  u16 unk_6;               // 0x06, Breakable_Spawn が 0 を書くだけ
  u8 unk_8;                // 0x08, kw: '.k', 読み手が見つかっていない
  u8 flashTimer;           // 0x09, 被弾で 4, 0 になったら Video_SetAuxSpritePltt でパレットを戻す
  u8 brokenPose;           // 0x0A, kw: '.P' + 1。壊れたときに sprite.metaspriteIdx へ入る
  u8 shakeTimer;           // 0x0B, 被弾で 10。0 でない間は hitbox.flags の bit2 を立てて当たらなくし、sprite.pos を乱数で揺らす
  u16 scriptOnBreak;       // 0x0C, kw: '.d', 壊れたとき Script_ExecById に渡す
  u16 unk_e;               // 0x0E, padding?
  Vec3 pos;                // 0x10, kw: '.p', Hitbox_SetPos で hitbox の座標として登録され、sprite.pos の基準にもなる
  u32 unk_18;              // 0x18, Breakable_SetUpdate が 0 にする。読み手が見つかっていない
  BreakableUpdate update;  // 0x1C, BreakableManager_Update が毎フレーム呼ぶ
  AuxSpriteGfx gfx;        // 0x20, kw: '.t' (default: SPRITE_KOMAINU)
  AuxSprite sprite;        // 0x3C
  HitboxData hitbox;       // 0x68, Hitbox_SetHandler が Breakable_OnHit を被弾コールバックに設定する
} Breakable;
static_assert(sizeof(Breakable) == 184);

// 壊せるオブジェクトのプールを持ち、毎フレーム各オブジェクトの update を呼ぶ
typedef struct BreakableManager {
  Entity e;          // 0x00, ENTITY_UNK_8
  s32 count;         // 0x18, kw: '.n' (default: 4)
  Breakable* items;  // 0x1C, BreakableManager_Init が Malloc(count * sizeof(Breakable)) したもの
} BreakableManager;
static_assert(sizeof(BreakableManager) == 32);

void exit(int code);  // libc.a:exit.o
s32 FUN_08015ce0(s32 param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5, s32 param_6, s32 param_7, s32 param_8, s32 param_9, s32 param_10, Vec3* pos);
s32 FUN_08014da0(s32 param_1, s32 param_2, Vec3* pos, s32 param_4, s32 param_5, s32 param_6, s32 param_7, s32 param_8, s32 param_9, s32 param_10, s32 param_11, s32 param_12);
s32 Entity080146e0_SpawnAtAngle(s32 count, s32 kind, Vec3* pos, s32 angle, s32 angleRange, s32 speed, s32 speedRange, s32 velY, s32 velYRange, s32 lifeBase, s32 lifeRandMask);

void Breakable_UpdateIdle(BreakableManager* p, Breakable* item);

IWRAM_DATA BreakableManager* gBreakableManager = NULL;  // 0x03000030

// update を差し替え、切り替わったことを stateChanged で知らせる
void Breakable_SetUpdate(Breakable* item, BreakableUpdate update) {
  item->update = update;
  item->unk_18 = 0;
  item->stateChanged = TRUE;
}

// update が切り替わった直後かどうかを返し、フラグを下ろす
bool32 Breakable_TakeStateChanged(Breakable* item) {
  if (item->stateChanged) {
    item->stateChanged = FALSE;
    return TRUE;
  }
  return FALSE;
}

// 攻撃が当たったときの処理。耐久値を削り、当たった向きへ火花を飛ばして少しのけぞらせる
void Breakable_OnHit(HitboxData* a, HitboxData* b, Breakable* item) {
  Vec3 pos;
  s32 angle;
  s32 sin;
  s32 offset;

  Hitbox_ApplyDamage(a, b);
  item->hp -= b->damage;
  if (item->hp <= 0) {
    item->hp = 0;
    PlaySound_082406e0(0x14F);
  } else {
    PlaySound_082406e0(0x14E);
  }
  item->flashTimer = 4;
  Video_SetAuxSpritePltt(&item->gfx, 306);
  pos = item->pos;
  pos.x -= 0x80;
  pos.y += 0x80;
  pos.z += 0x80;
  angle = a->angle + 0x80;
  sin = gSineTable[(a->angle + 0xC0) & 0xFF] << 5;
  if (sin >= 0) {
    offset = sin >> 12;
  } else {
    offset = -((-sin) >> 12);
  }
  pos.x += offset;
  sin = gSineTable[angle & 0xFF] << 5;
  if (sin >= 0) {
    offset = sin >> 12;
  } else {
    offset = -((-sin) >> 12);
  }
  pos.z += offset;
  Entity080146e0_SpawnAtAngle(4, 3, &pos, angle, 0xA4, 16, 4, 8, 3, 30, 0xF);
  item->shakeTimer = 10;
}

// スロット1つ分のスプライトを確保し、非表示の空きスロットとして寝かせておく
s32 Breakable_Setup(BreakableManager* p, Breakable* item) {
  if (!Video_GetAuxSprite(&item->gfx, SPRITE_KOMAINU)) return -1;
  AuxSprite_Add(&item->sprite, &item->gfx, SPRFLAG_HIDDEN);
  Breakable_SetUpdate(item, Breakable_UpdateIdle);
  item->active = FALSE;
  return 0;
}

// スロットを用意した直後と壊れたあとに入る、何もしない update
void Breakable_UpdateIdle(BreakableManager* p, Breakable* item) { Breakable_TakeStateChanged(item); }

// 立っている間の update。耐久値が尽きたら壊れた姿に変え、当たり判定を切って破片を撒く
NON_MATCH void Breakable_UpdateAlive(BreakableManager* p, Breakable* item) {
#ifdef NONMATCHING_C
  Vec3 pos;
  ScriptArgs sa;
  u32 arg;
  u16* table;
  u16 r;

  Breakable_TakeStateChanged(item);
  if (item->hp <= 0) {
    if (item->scriptOnBreak != 0) {
      arg = item->id;
      sa.argc = 1;
      sa.argv = &arg;
      Script_ExecById(item->scriptOnBreak, &sa);
    }
    item->sprite.metaspriteIdx = item->brokenPose;
    item->hitbox.flags |= HBFLAG_UNK_2;
    Breakable_SetUpdate(item, Breakable_UpdateIdle);
    Video_SetAuxSpritePltt(&item->gfx, 6);
    pos = item->pos;
    pos.x -= 0x80;
    pos.y = pos.y;
    pos.z += 0x80;
    FUN_08015ce0(4, 1, 0x2000, 0x40, 0, 0x100, 2, 3, 0xC, 6, &pos);
    FUN_08015ce0(6, 1, 0x2000, 0x40, 0, 0x100, 4, 4, 0xA, 4, &pos);
    Entity080146e0_SpawnAtAngle(4, 3, &pos, 0, 0x100, 0x10, 4, 0xC, 3, 0x1E, 0xF);
    FUN_08014da0(4, 6, &pos, 0, 0x14, 4, 0xA, 6, 0, 0x100, 0x14, 4);
  } else {
    if (item->flashTimer != 0) {
      item->flashTimer--;
      if (item->flashTimer == 0) {
        Video_SetAuxSpritePltt(&item->gfx, 6);
      }
    }
    if (item->shakeTimer != 0) {
      item->shakeTimer--;
      if (item->shakeTimer == 0) {
        item->hitbox.flags &= ~HBFLAG_UNK_2;
      } else {
        item->hitbox.flags |= HBFLAG_UNK_2;
      }
      item->sprite.pos = item->pos;
      table = gRandomTable;
      gRandTableIdx = (gRandTableIdx + 1) & 0x3FF;
      r = table[gRandTableIdx];
      item->sprite.pos.x += (r & 0xF) - 8;
      gRandTableIdx = (gRandTableIdx + 1) & 0x3FF;
      r = table[gRandTableIdx];
      item->sprite.pos.z += (r & 0xF) - 8;
    }
  }
#else
  INCFUNC("asm/func/Breakable_UpdateAlive.inc");
#endif
}

// スロットが握っている当たり判定とスプライトを外す
s32 Breakable_Cleanup(BreakableManager* p, Breakable* item) {
  Hitbox_Unregister(&item->hitbox);
  AuxSprite_Remove(&item->sprite);
}

// 各スロットの update を毎フレーム呼ぶ
s32 BreakableManager_Update(BreakableManager* p) {
  if (p->items != NULL) {
    Breakable* item = p->items;
    s32 i;
    for (i = 0; i < p->count; i++, item++) {
      if (item->active && item->update != NULL) {
        item->update(p, item);
      }
    }
  }
  return 0;
}

// 全スロットの当たり判定とスプライトを外してからプールを解放する
s32 BreakableManager_Destroy(BreakableManager* p) {
  if (p->items != NULL) {
    Breakable* item = p->items;
    s32 i;
    for (i = 0; i < p->count; i++, item++) {
      Breakable_Cleanup(p, item);
    }
    Free(p->items);
    p->items = NULL;
  }
  gBreakableManager = NULL;
  return 0;
}

// スクリプトが指定した個数だけスロットを確保し、1つずつ寝かせた状態にする
s32 BreakableManager_Init(BreakableManager* p) {
  Breakable* item;
  s32 i;
  s32 size;

  gBreakableManager = p;

  p->count = VM_GetKeywordValue('n', 4);
  size = p->count * sizeof(Breakable);
  p->items = Malloc(size);
  if (p->items == NULL) {
    // デバッグ用の処理の消し忘れ?, 内部的には svc 0xAB が行われるが、 GBAのBIOSでは不正なシステムコール
    // この1つの exit のせいで、 結構なライブラリがリンクされている
    exit(-1);
  }
  ClearMemory(p->items, size);

  item = p->items;
  for (i = 0; i < p->count; i++, item++) {
    Breakable_Setup(p, item);
  }
  return 0;
}

BreakableManager* BreakableManager_Create(void) {
  if (gBreakableManager == NULL) {
    BreakableManager* p = CreateEntity(ENTITY_UNK_8, sizeof(BreakableManager));
    if (p != NULL) {
      SetEntityRoutine(p, BreakableManager_Update, BreakableManager_Destroy);
      if (BreakableManager_Init(p) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gBreakableManager;
}

// まだ使われていないスロットを1つ返す。空きがなければ NULL
Breakable* BreakableManager_FindFreeSlot(BreakableManager* p) {
  Breakable* item = p->items;
  s32 i;
  for (i = 0; i < p->count; i++, item++) {
    if (!item->active) {
      return item;
    }
  }
  return NULL;
}

// スクリプトコマンド 0x2D8F。空きスロットに壊せるオブジェクトを1つ置く
s32 Breakable_Spawn(void) {
  Breakable* item;
  AuxSprite* sprite;
  HitboxData* hitbox;
  SpriteID32 spriteID;
  s32 pose;
  Vec3 size;
  Vec3 offset;

  if (gBreakableManager == NULL) {
    return -1;
  }
  item = BreakableManager_FindFreeSlot(gBreakableManager);
  item->id = VM_GetKeywordValue('n', 0);
  item->flashTimer = 0;
  item->hp = VM_GetKeywordValue('l', 10);
  item->unk_6 = 0;
  if (VM_SeekToKeyword('p')) {
    item->pos.x = Script_GetValue();
    item->pos.y = Script_GetValue();
    item->pos.z = Script_GetValue();
  }
  spriteID = VM_GetKeywordValue('t', SPRITE_KOMAINU);
  pose = VM_GetKeywordValue('P', 0);
  item->unk_8 = VM_GetKeywordValue('k', 0);
  item->scriptOnBreak = VM_GetKeywordValue('d', 0);
  sprite = &item->sprite;
  sprite->flags &= ~SPRFLAG_HIDDEN;
  sprite->pos = item->pos;
  if (!Video_GetAuxSprite(&item->gfx, spriteID)) {
    return -1;
  }
  FUN_0822a4fc(sprite, &item->gfx);
  sprite->metaspriteIdx = pose;
  sprite->priority = 2;
  Breakable_SetUpdate(item, Breakable_UpdateAlive);
  item->brokenPose = pose + 1;
  item->flashTimer = 0;
  hitbox = &item->hitbox;
  size.x = 0x80, size.y = 0x100, size.z = 0x80;
  offset.x = -0x80, offset.y = 0x80, offset.z = 0x80;
  Hitbox_Init(hitbox, item->id, 0x4001, 0, 0x10, &size, &offset);
  Hitbox_SetHandler(hitbox, Breakable_OnHit, item);
  Hitbox_SetPos(hitbox, &item->pos, 0);
  Hitbox_Register(hitbox);
  item->active = TRUE;
}
