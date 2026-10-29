#include "camera_inline.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "player.h"
#include "random.h"
#include "sound.h"
#include "sprite.h"

// アイテムアイコン1枚, ワールド座標を持ちアイソメトリック投影でスプライトに落とす
typedef struct {
  u32 unk_00;         // 0x00
  u8 state;           // 0x04, PTR_ARRAY_085aa92c の添字 (0..6)
  bool8 justEntered;  // 0x05, state が変わると 1, ハンドラが落として sprite の SPRFLAG_HIDDEN も落とす
  u8 category;        // 0x06, ItemIconPopupManager_AddIcon の category (0..3), ポーズ番号の基準と入手音を決める
  u8 kind;            // 0x07, 0/1/3 で次に移る state が変わる
  item32_t itemID;    // 0x08, IsValuable に渡す
  u32 stateTimer;     // 0x0C, state に入ってからのフレーム数
  u16 duration;       // 0x10, stateTimer がここに達すると次の state へ
  u8 playerIdx;       // 0x12, gPlayerPtr の添字
  u8 unk_13[5];       // 0x13
  Vec3 pos;           // 0x18, ワールド座標, ItemIconPopup_ProjectPos が sprite.pos に投影する
  Vec3* destPos;      // 0x20, kind が 0 以外のとき state 6 で飛んでいく先のワールド座標
  MainSprite sprite;  // 0x24
} ItemIconPopup;
static_assert(sizeof(ItemIconPopup) == 132);

// アイテムアイコンを8枚まで同時に飛ばすシングルトン (アイテムを入手した時に、そのアイコンを画面に表示する)
typedef struct {
  Entity e;                // 0x000, ENTITY_UNK_9
  u32 usedMask;            // 0x018, elems のどのスロットが使用中かのビットマスク
  MainSpriteGfx gfx;       // 0x01C, SPRITE_INVENTORY_ICONS
  ItemIconPopup elems[8];  // 0x03C
} ItemIconPopupManager;
static_assert(sizeof(ItemIconPopupManager) == 1116);

static ItemIconPopupManager* sItemIconPopupManager;  // 0x0300006C

bool32 IsValuable(item32_t id);

static inline Player* GetPlayer(s32 idx) { return gPlayerPtr[idx]; }

// state を切り替え, 入場フラグを立てて経過フレームを 0 に戻す
static inline void ItemIconPopup_SetState(ItemIconPopup* elem, u8 state) {
  elem->state = state;
  elem->justEntered = TRUE;
  elem->stateTimer = 0;
}

void ItemIconPopupManager_ClearGlobal(void) { sItemIconPopupManager = NULL; }

// 枠を空きの状態 (state 1, スプライト非表示) に戻す
void ItemIconPopup_Reset(ItemIconPopup* elem) {
  elem->unk_00 = 0;
  elem->state = 1;
  elem->justEntered = FALSE;
  elem->category = 0;
  elem->stateTimer = 0;
  elem->sprite.flags |= SPRFLAG_HIDDEN;
  elem->sprite.flags &= ~SPRFLAG_AFFINE;
}

void ItemIconPopup_ProjectPos(ItemIconPopup* elem) {
  MainSprite* sprite = &elem->sprite;

  WorldToScreen(&sprite->pos, &elem->pos);
  sprite->pos.x -= 8;
  sprite->pos.y -= 8;
}

// state 0, アイコンを数フレーム跳ね上げてから state 1 へ移る
void FUN_08017098(ItemIconPopupManager* p, ItemIconPopup* elem, s32 idx) {
  if (elem->justEntered) {
    elem->justEntered = FALSE;
    elem->sprite.flags &= ~SPRFLAG_HIDDEN;
  }
  if (elem->stateTimer <= 2) {
    elem->pos.y += 16;
  } else {
    elem->pos.y -= 16;
  }
  ItemIconPopup_ProjectPos(elem);
  if (elem->stateTimer > 3) {
    ItemIconPopup_SetState(elem, 1);
  } else {
    elem->stateTimer++;
  }
}

// state 1 と 4, duration フレーム留まってから kind に応じた次の state へ移る
void FUN_080170e4(ItemIconPopupManager* p, ItemIconPopup* elem, s32 idx) {
  if (elem->justEntered) {
    elem->justEntered = FALSE;
    elem->sprite.flags &= ~SPRFLAG_HIDDEN;
  }
  ItemIconPopup_ProjectPos(elem);
  if (elem->stateTimer >= elem->duration) {
    if (elem->kind == 0) {
      if (GetPlayer(elem->playerIdx) != NULL) {
        ItemIconPopup_SetState(elem, 6);
      } else {
        ItemIconPopup_SetState(elem, 5);
      }
    } else if (elem->kind == 1) {
      ItemIconPopup_SetState(elem, 2);
    } else if (elem->kind == 3) {
      ItemIconPopup_SetState(elem, 6);
    }
  } else {
    elem->stateTimer++;
  }
}

// state 2, 回転しながら縮んで手前へ流れ, 8 フレームで枠を空ける
void FUN_08017160(ItemIconPopupManager* p, ItemIconPopup* elem, s32 idx) {
  MainSprite* sprite = &elem->sprite;

  if (elem->justEntered) {
    elem->justEntered = FALSE;
    sprite->flags |= SPRFLAG_AFFINE;
    sprite->rotation = 0;
    elem->sprite.scaleX = Q6(1);
    elem->sprite.scaleY = Q6(1);
  }
  if (elem->sprite.scaleX > 8) {
    elem->sprite.scaleX -= 8;
  }
  elem->sprite.scaleY = elem->sprite.scaleX;
  sprite->rotation += 16;
  elem->pos.x += 8;
  elem->pos.z += 8;
  ItemIconPopup_ProjectPos(elem);
  sprite->pos.x += (Q6(1) - elem->sprite.scaleX) >> 3;
  if (elem->stateTimer > 7) {
    ItemIconPopup_Reset(elem);
    p->usedMask &= ~(1 << idx);
  } else {
    elem->stateTimer++;
  }
}

// state 3, 上へ跳ねてから落ちる, kind 3 のときは途中から小刻みに揺れる, 終わったら state 4 へ
// 残差 96/99 命令: 揺らす処理で原典は乱数の値を先に読んでから座標を ldrh で読み (こちらは座標を先に ldrsh), 0x3 の定数を kind の値と使い回さず別に作る
// Tier A-B は試済 (_Random(table) を u16* table で受ける, x - 1 + 乱数 の順, 乱数をローカルに受ける, 末尾の条件を && / || にまとめる)
NON_MATCH void FUN_080171f4(ItemIconPopupManager* p, ItemIconPopup* elem, s32 idx) {
#ifdef NONMATCHING_C
  if (elem->justEntered) {
    elem->justEntered = FALSE;
    elem->sprite.flags &= ~SPRFLAG_HIDDEN;
  }
  if (elem->kind == 3) {
    if (elem->stateTimer <= 3) {
      elem->pos.y += 64;
    } else {
      elem->pos.y -= 4;
    }
  } else {
    if (elem->stateTimer <= 4) {
      elem->pos.y += 64;
    } else {
      elem->pos.y -= 8;
    }
  }
  ItemIconPopup_ProjectPos(elem);
  if (elem->kind == 3) {
    if (elem->stateTimer > 3) {
      u16* table = gRandomTable;

      elem->sprite.pos.x += (_Random(table) & 3) - 1;
      elem->sprite.pos.y += (_Random(table) & 3) - 1;
    }
  }
  if ((elem->kind == 3 && elem->stateTimer > 8) || (elem->kind != 3 && elem->stateTimer > 7)) {
    ItemIconPopup_SetState(elem, 4);
  } else {
    elem->stateTimer++;
  }
#else
  INCFUNC("asm/func/FUN_080171f4.inc");
#endif
}

// state 5, 縮みながら上へ飛んで, 4 フレームで枠を空ける
void FUN_080172cc(ItemIconPopupManager* p, ItemIconPopup* elem, s32 idx) {
  MainSprite* sprite = &elem->sprite;

  if (elem->justEntered) {
    elem->justEntered = FALSE;
    elem->sprite.flags &= ~SPRFLAG_HIDDEN;
    sprite->flags |= SPRFLAG_AFFINE;
    sprite->rotation = 0;
    elem->sprite.scaleX = Q6(1);
    elem->sprite.scaleY = Q6(1);
  }
  if (elem->sprite.scaleX > 16) {
    elem->sprite.scaleX -= 16;
  }
  elem->pos.y += 64;
  ItemIconPopup_ProjectPos(elem);
  sprite->pos.x += (Q6(1) - elem->sprite.scaleX) >> 3;
  if (elem->stateTimer > 3) {
    ItemIconPopup_Reset(elem);
    p->usedMask &= ~(1 << idx);
  } else {
    elem->stateTimer++;
  }
}

// state 6, 回転しながら縮んで 1P (kind 0) か destPos へ 16 フレームで飛び, 着いたら入手音を鳴らして枠を空ける
void FUN_08017358(ItemIconPopupManager* p, ItemIconPopup* elem, s32 idx) {
  MainSprite* sprite = &elem->sprite;
  Vec3 dst, src;
  s32 t, rest;

  if (elem->justEntered) {
    elem->justEntered = FALSE;
    elem->sprite.flags &= ~SPRFLAG_HIDDEN;
    sprite->flags |= SPRFLAG_AFFINE;
    sprite->rotation = 0;
    elem->sprite.scaleX = Q6(1);
    elem->sprite.scaleY = Q6(1);
  }
  t = elem->stateTimer;
  rest = 16 - t;
  if (elem->kind == 0) {
    WorldToScreen(&dst, &GetPlayer(elem->playerIdx)->mover.pos);
  } else {
    WorldToScreen(&dst, elem->destPos);
  }
  WorldToScreen(&src, &elem->pos);
  dst.y -= 4;
  sprite->pos.x = FixToInt(4, src.x * rest + dst.x * t);
  sprite->pos.y = FixToInt(4, src.y * rest + dst.y * t);
  if (sprite->scaleX > 32) {
    sprite->scaleX -= 2;
  }
  sprite->scaleY = sprite->scaleX;
  sprite->rotation += 8;
  sprite->pos.x += ((Q6(1) - sprite->scaleX) >> 3) - 8;
  sprite->pos.y -= 8;
  if (elem->stateTimer > 15) {
    if (elem->category == 0) {
      if (elem->itemID >= 0x40 && elem->itemID <= 0x43) {
        PlaySound_0824078c(SONG_387);
      } else if (IsValuable(elem->itemID) == TRUE) {
        PlaySound_0824078c(SE_UNK_291);
      } else {
        PlaySound_0824078c(SE_EQUIP);
      }
    } else if (elem->category != 3) {
      PlaySound_0824078c(SE_UNK_291);
    }
    ItemIconPopup_Reset(elem);
    p->usedMask &= ~(1 << idx);
  } else {
    elem->stateTimer++;
  }
}

static void (*const PTR_ARRAY_085aa92c[7])(ItemIconPopupManager*, ItemIconPopup*, s32) = {
    FUN_08017098,
    FUN_080170e4,
    FUN_08017160,
    FUN_080171f4,
    FUN_080170e4,
    FUN_080172cc,
    FUN_08017358,
};  // 0x085AA92C

// 残差3箇所 (38/38 命令): 原典は &elems[i].state と &elems[i] を別の誘導変数で持ち, elem の初期化をループ表のアドレスの後に置く
// Tier A-C は試済 (elem をポインタで回す, state を elem-> 経由にする, for の初期化に入れる)
NON_MATCH s32 ItemIconPopupManager_Update(ItemIconPopupManager* p) {
#ifdef NONMATCHING_C
  ItemIconPopup* elem;
  s32 i;

  for (i = 0, elem = p->elems; i < 8; i++, elem++) {
    if (p->usedMask & (1 << i)) {
      if (p->elems[i].state <= 6) {
        PTR_ARRAY_085aa92c[p->elems[i].state](p, elem, i);
      }
    }
  }
#else
  INCFUNC("asm/func/ItemIconPopupManager_Update.inc");
#endif
}

s32 ItemIconPopupManager_Destroy(ItemIconPopupManager* p) {
  s32 i;

  for (i = 0; i < 8; i++) {
    MainSprite_Remove(&p->elems[i].sprite);
  }
  sItemIconPopupManager = NULL;
}

// 残差 (80/80 命令): CpuFill32 の前に原典は &pos を先に作る, ループのポインタは sprite 側を elem 側より先に作る (どちらも並びだけ)
// Tier A-C は試済 (添字で回す, elem で回す, sprite だけ添字にする, elem の初期化を for の外へ出す)
NON_MATCH s32 ItemIconPopupManager_Init(ItemIconPopupManager* p) {
#ifdef NONMATCHING_C
  MainSpriteGfxFile* f;
  ItemIconPopup* elem;
  Vec3 pos;
  s32 i;

  sItemIconPopupManager = p;
  f = GetFile(DIR_MAIN_SPRITE, SPRITE_INVENTORY_ICONS);
  if (f == NULL) {
    return -1;
  }
  p->gfx = *f;
  OpenMainSpriteFile(&p->gfx, f);
  p->usedMask = 0;
  CpuFill32(0, &pos, sizeof(pos));
  for (i = 0, elem = p->elems; i < 8; i++, elem++) {
    elem->unk_00 = 0;
    elem->state = 1;
    elem->category = 0;
    elem->stateTimer = 0;
    MainSprite_Add(&p->elems[i].sprite, &p->gfx, 0, SPRFLAG_HIDDEN | SPRFLAG_SCREEN_COORD, 1, PLAYMODE_PAUSE, 60, &pos);
  }
#else
  INCFUNC("asm/func/ItemIconPopupManager_Init.inc");
#endif
}

ItemIconPopupManager* ItemIconPopupManager_Create(void) {
  if (sItemIconPopupManager == NULL) {
    ItemIconPopupManager* p = CreateEntity(ENTITY_UNK_9, sizeof(ItemIconPopupManager));

    if (p != NULL) {
      SetEntityRoutine(p, ItemIconPopupManager_Update, ItemIconPopupManager_Destroy);
      if (ItemIconPopupManager_Init(p) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return sItemIconPopupManager;
}

ItemIconPopupManager* ItemIconPopupManager_GetOrCreate(void) {
  ItemIconPopupManager* p = sItemIconPopupManager;

  if (p == NULL) {
    p = ItemIconPopupManager_Create();
  }
  return p;
}

// 空き枠にアイテムのアイコンを出す, key が同じ枠が空いていればそれを使い直す, 空きが無ければ -1
s32 ItemIconPopupManager_AddIcon(s32 category, item32_t itemID, u32 kind, u32 playerIdx, Vec3* pos, Vec3* destPos, u32 duration, u32 key) {
  ItemIconPopupManager* p = ItemIconPopupManager_GetOrCreate();
  u32 tag = (key & 0xFFFFFF) | (category << 28);
  ItemIconPopup* elem = NULL;
  s32 slot = -1;
  s32 i;
  u32 poseIdx;

  for (i = 0; i < 8; i++) {
    if (!(p->usedMask & (1 << i))) {
      elem = &p->elems[i];
      slot = i;
      if (key != 0 && elem->unk_00 == tag) {
        goto found;
      }
    }
  }
check:
  if (elem == NULL) {
    return -1;
  }
  goto add;
found:
  ItemIconPopup_Reset(elem);
  p->usedMask &= ~(1 << itemID);  // 枠番号ではなく itemID でビットを落としている (原典のまま)
  goto check;
add:
  elem->unk_00 = tag;
  elem->playerIdx = playerIdx;
  if (GetPlayer(elem->playerIdx) == NULL) {
    elem->playerIdx = 0;
  }
  elem->duration = duration;
  elem->kind = kind;
  switch (elem->kind) {
    case 0: {
      ItemIconPopup_SetState(elem, 3);
      break;
    }
    case 1: {
      ItemIconPopup_SetState(elem, 0);
      break;
    }
    case 2: {
      ItemIconPopup_SetState(elem, 3);
      break;
    }
    case 3: {
      ItemIconPopup_SetState(elem, 3);
      break;
    }
  }
  elem->category = category;
  elem->itemID = itemID;
  switch (elem->category) {
    case 0: {
      poseIdx = itemID + 104;
      break;
    }
    case 1: {
      poseIdx = itemID;
      break;
    }
    case 2: {
      poseIdx = itemID + 67;
      break;
    }
    case 3: {
      poseIdx = itemID + 182;
      break;
    }
    default: {
      poseIdx = 104;
      break;
    }
  }
  MainSprite_SetPose(&elem->sprite, &p->gfx, poseIdx, PLAYMODE_PAUSE);
  elem->sprite.flags &= ~SPRFLAG_HIDDEN;
  elem->pos = *pos;
  elem->destPos = destPos;
  WorldToScreen(&elem->sprite.pos, pos);
  elem->sprite.pos.x -= 8;
  elem->sprite.pos.y -= 8;
  if (slot >= 0) {
    p->usedMask |= 1 << slot;
  }
  return 0;
}
