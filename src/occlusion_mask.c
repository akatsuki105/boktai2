#include "collision_map.h"
#include "entity.h"
#include "global.h"
#include "map_inline.h"
#include "mover.h"
#include "registry.h"
#include "sprite_aux.h"
#include "sprite_main.h"
#include "video.h"
#include "vm.h"

// slots の1要素, OcclusionMask_AddTarget が Mover の id を種別付きで登録する
typedef struct {
  u16 kind;  // 0x00, FUN_08002a48 なら 0、FUN_08002a58 なら 1、Cmd_AddOcclusionMaskTarget なら '.m' の値
  u16 id;    // 0x02, Mover.id
} OcclusionMaskSlot;
static_assert(sizeof(OcclusionMaskSlot) == 4);

// entries の1要素, マスクをかける Mover を1つ持つ
typedef struct {
  u16 active;    // 0x00, mover を結びつけている間 1
  u16 moverId;   // 0x02, mover の Mover.id, 外すときの検索キー
  Mover* mover;  // 0x04, Mover_FindByID_Proxy(moverId) の戻り値
} OcclusionMaskEntry;
static_assert(sizeof(OcclusionMaskEntry) == 8);

// 壁の裏に入ったキャラを壁の形に隠すマスクの管理役
// entries の Mover ごとに黒塗りの AuxSprite (SPR_MASK_*) を3枚まで重ね, BLDALPHA 0:16 の半透明で背景を透かして見せる
// マップ初期化 (Scr_CreateOcclusionMask) が '.m' でマップごとの壁の形を選ぶ, "mask_test_00" は '.m' が無いときの仮のスプライト
// サイズが可変で、'.n' の値 count に対して 152 * count + 144 バイトで確保される
// 144バイトのヘッダの後ろに entries[count] (8 * count) / sprites[spriteCount] (44 * 3count) / usedTiles[spriteCount] (4 * 3count) が並ぶ
typedef struct {
  Entity e;                       // 0x00, ENTITY_UNK_9
  u16 unk_18;                     // 0x18, OcclusionMask_Create の第1引数
  u16 unk_1a;                     // 0x1A, OcclusionMask_Create の第2引数
  bool32 spritesAdded;            // 0x1C, 最初の Update で sprites を描画リストに入れたら 1
  s32 count;                      // 0x20, '.n' の値, 引数が無ければ 8
  s32 spriteCount;                // 0x24, count * 3
  u32 slotCount;                  // 0x28, _Init が 0 を書く, slots の使用件数
  OcclusionMaskSlot slots[16];    // 0x2C, OcclusionMask_AddTarget が末尾に積む, 上限 16 件 (slotCount > 15 を弾く)
  AuxSpriteGfx gfx;               // 0x6C, '.m'、無ければ HashName("mask_test_00") の ID
  AuxSprite* sprites;             // 0x88, &entries[count] を指す
  u32* usedTiles;                 // 0x8C, sprites の後ろを指す, そのフレームにマスクを出したタイルの索引 | 高さ << 16 の控え, 同じタイルに2枚出さない
  OcclusionMaskEntry entries[1];  // 0x90, 実際は count 個 (可変長)
} OcclusionMask;

const ALIGNED(4) char s_mask_test_00[] = "mask_test_00";  // 0x08251B2C

// 空いている entries の要素に id の Mover を結びつける
void OcclusionMask_AddEntry(OcclusionMask* p, u16 id) {
  OcclusionMaskEntry* e = p->entries;
  s32 i;

  for (i = 0; i < p->count; i++) {
    if (e->active == 0) {
      break;
    }
    e++;
  }

  if (i == p->count) {
    return;
  }

  e->mover = Mover_FindByID_Proxy(id);
  if (e->mover == NULL) {
    return;
  }

  e->active = 1;
  e->moverId = id;
}

// id が一致する entries の要素を丸ごと 0 に戻す
void OcclusionMask_RemoveEntry(OcclusionMask* p, u16 id) {
  OcclusionMaskEntry* e = p->entries;
  s32 i;

  for (i = 0; i < p->count; i++) {
    if (e->moverId == id) {
      e->active = 0;
      e->mover = NULL;
      e->moverId = 0;
      return;
    }
    e++;
  }
}

// 種別付きで Mover の id を slots の末尾に積む, 満杯か未生成なら -1
// 残差4命令, 原典は store ごとに (p + 0x2C) / (p + 0x2E) を作ってから添字を足すが
// agbcc は (p + 添字*4) に畳んでメンバのオフセットを strh の即値に入れる (MainMenu1P_RemoveParticles と同じ加算順の問題)
NON_MATCH s32 OcclusionMask_AddTarget(s32 kind, s32 id) {
#ifdef NONMATCHING_C
  OcclusionMask* p = Registry_Find(0x7BE3);

  if (p == NULL) {
    return -1;
  }

  if (p->slotCount > 15) {
    return -1;
  }

  p->slots[p->slotCount].kind = kind;
  p->slots[p->slotCount].id = id;
  p->slotCount++;
  return 0;
#else
  INCFUNC("asm/func/OcclusionMask_AddTarget.inc");
#endif
}

s32 FUN_08002a48(Mover* p) { return OcclusionMask_AddTarget(0, p->id); }

s32 FUN_08002a58(Mover* p) { return OcclusionMask_AddTarget(1, p->id); }

// entries の Mover ごとに, +x / +z 側で隣り合う自分より高いタイルの occluder でマスクのスプライトを重ねる
// 残差は 485 対 494 命令 (ハンク62), 処理の流れは一致, 原典は slots の kind を添字で毎回計算し id だけ歩きポインタにする, 重複検索のループは入口で条件を複製する形, ループ変数とスプライトの割当も違う
// 重複検索を while / 添字 / k++ を本体で / 宣言を関数頭に, 奥のタイルの比較の向きは試済
NON_MATCH s32 OcclusionMask_Update(OcclusionMask* p) {
#ifdef NONMATCHING_C
  s32 heights[4];
  s32 occluders[4];
  s32 xs[3];
  s32 zs[3];
  s32 idxs[3];
  s32 quadrant;
  s32 y;
  s32 h;
  s32 used;
  AuxSprite* sprite;
  OcclusionMaskEntry* e;
  s32 i;

  // 最初の1回だけ, 全スプライトを描画リストに入れる
  if (p->spritesAdded == 0) {
    p->spritesAdded = 1;
    for (i = 0; i < p->spriteCount; i++) {
      if (!p->sprites[i].active) {
        Video_AddAuxSpriteIntoDrawList(&p->sprites[i], 0);
      }
    }
  }
  // 積まれた登録 (kind 0) と解除 (kind 1) を entries に反映して空にする
  for (i = 0; i < p->slotCount; i++) {
    switch (p->slots[i].kind) {
      case 0: {
        OcclusionMask_AddEntry(p, p->slots[i].id);
        break;
      }
      case 1: {
        OcclusionMask_RemoveEntry(p, p->slots[i].id);
        break;
      }
    }
  }
  p->slotCount = 0;
  // スプライトは前から詰めて使い, used 枚目までがこのフレームに出したもの
  used = 0;
  sprite = p->sprites;
  e = p->entries;
  for (i = 0; i < p->count; i++, e++) {
    Mover* m = e->mover;
    s32 tx;
    s32 tz;
    s32 j;

    // 空き枠と, スプライトが隠れている Mover は飛ばす
    if (e->active == 0) {
      continue;
    }
    if (m->mainSprite != NULL && (m->mainSprite->flags & SPRFLAG_HIDDEN)) {
      continue;
    }
    if (m->auxSprite != NULL && (m->auxSprite->flags & SPRFLAG_HIDDEN)) {
      continue;
    }
    if (m->flags & 1) {
      continue;
    }
    // 足元のタイル座標と高さ (タイル単位), heights[0] / occluders[0] は自分の分
    y = m->pos.y & 0xFF00;
    tx = m->pos.x >> 8;
    tz = m->pos.z >> 8;
    h = y >> 8;
    heights[0] = h;
    occluders[0] = 0xFF;
    // タイル内の位置で調べる3枚を選ぶ, x と z の端数が両方 64 未満か両方 64 以上なら +x, +z の隣と斜め, x だけ 64 未満なら z+1 の一列, z だけ 64 未満なら x+1 の一列
    if ((m->pos.x & 0xFF) < 64) {
      if ((m->pos.z & 0xFF) < 64) {
        xs[0] = tx + 1;
        zs[0] = tz;
        xs[1] = tx + 1;
        zs[1] = tz + 1;
        xs[2] = tx;
        zs[2] = tz + 1;
        quadrant = 0;
      } else {
        xs[0] = tx - 1;
        zs[0] = tz + 1;
        xs[1] = tx;
        zs[1] = tz + 1;
        xs[2] = tx + 1;
        zs[2] = tz + 1;
        quadrant = 1;
      }
    } else {
      if ((m->pos.z & 0xFF) < 64) {
        xs[0] = tx + 1;
        zs[0] = tz - 1;
        xs[1] = tx + 1;
        zs[1] = tz;
        xs[2] = tx + 1;
        zs[2] = tz + 1;
        quadrant = 2;
      } else {
        xs[0] = tx + 1;
        zs[0] = tz;
        xs[1] = tx + 1;
        zs[1] = tz + 1;
        xs[2] = tx;
        zs[2] = tz + 1;
        quadrant = 3;
      }
    }
    for (j = 0; j < 3; j++) {
      CollisionMapTile* tile;

      idxs[j] = gCollisionMap->rowOffsets[zs[j]] + xs[j];
      tile = TileAtIndex(idxs[j]);
      // TATTR_UNK_4 のタイルは隠さない
      if (tile == NULL || (tile->attr & TATTR_UNK_4)) {
        heights[j + 1] = 0;
        occluders[j + 1] = 0xFF;
      } else {
        heights[j + 1] = tile->heightStairs & 0xF;
        // 高さが2以上違うときは上書きされていない元のタイルを見て, 元のほうが高ければその occluder を使う
        if (abs(heights[j + 1] - heights[0]) > 1) {
          CollisionMapTile* raw = gCollisionMap->tiledata != NULL ? &gCollisionMap->tiledata->tiles[idxs[j]] : NULL;

          if (raw == NULL || (raw->attr & TATTR_UNK_4)) {
            occluders[j + 1] = 0xFF;
          } else if ((raw->heightStairs & 0xF) <= heights[0]) {
            occluders[j + 1] = tile->occluder;
          } else {
            occluders[j + 1] = raw->occluder;
          }
        } else {
          occluders[j + 1] = tile->occluder;
        }
      }
    }
    // 自分より高く occluder のあるタイルにマスクを出す, 一列の並び (quadrant 1, 2) は真ん中のタイルも高いときだけ
    for (j = 0; j < 3; j++) {
      if (heights[0] < heights[j + 1] && occluders[j + 1] != 0xFF && (quadrant != 1 || heights[0] < heights[2]) && (quadrant != 2 || heights[0] < heights[2])) {
        u32 key = idxs[j] | (h << 16);
        u32* k = p->usedTiles;
        s32 n;

        // 同じタイルと高さに出したマスクがあれば重ねない
        for (n = 0; n < used; n++, k++) {
          if (*k == key) {
            break;
          }
        }
        if (n == used) {
          sprite->poseIdx = occluders[j + 1];
          sprite->pos.x = xs[j] * 256 + 128;
          sprite->pos.y = y;
          sprite->pos.z = zs[j] * 256 + 128;
          sprite->flags &= ~SPRFLAG_HIDDEN;
          *k = key;
          used++;
          sprite++;
        }
      }
    }
  }
  // 使わなかったスプライトは隠す
  for (; used < p->spriteCount; used++) {
    sprite->flags |= SPRFLAG_HIDDEN;
    sprite++;
  }
  return 0;
#else
  INCFUNC("asm/func/OcclusionMask_Update.inc");
#endif
}

s32 OcclusionMask_Destroy(OcclusionMask* p) {
  s32 i;

  for (i = 0; i < p->spriteCount; i++) {
    if (p->sprites[i].active) {
      AuxSprite_Remove(&p->sprites[i]);
    }
  }

  return 0;
}

NON_MATCH s32 OcclusionMask_Init(OcclusionMask* p, u16 param_2, u16 param_3) {
#ifdef NONMATCHING_C
  s32 spriteID;
  s32 i;

  p->unk_18 = param_2;
  p->unk_1a = param_3;
  p->spritesAdded = 0;
  p->slotCount = 0;

  if (VM_SeekToNamedArg('m')) {
    spriteID = VM_GetValue();
  } else {
    spriteID = HashName(s_mask_test_00);
  }

  if (!Video_GetAuxSprite(&p->gfx, spriteID)) {
    return -1;
  }

  for (i = 0; i < p->spriteCount; i++) {
    AuxSprite_Setup(&p->sprites[i], &p->gfx, SPRFLAG_HIDDEN);
    p->sprites[i].oamAttr |= OAM0_SEMI_TRANSPARENT;
  }

  Video_SetBLDCNTDirect(2, 0xC, 0x2C);
  Video_SetBLDALPHADirect(0, 0x10);
  Registry_Add(0x7BE3, p, 0);
  return 0;
#else
  INCFUNC("asm/func/OcclusionMask_Init.inc");
#endif
}

OcclusionMask* OcclusionMask_Create(u16 param_1, u16 param_2) {
  s32 count = VM_SeekToNamedArg('n') ? VM_GetValue() : 8;
  s32 spritesSize = count * 132;
  s32 spritesOffset = count * 8 + 0x90;
  s32 size = spritesSize + spritesOffset;
  s32 spriteCount = count * 3;
  OcclusionMask* p = CreateEntity(ENTITY_UNK_9, size + spriteCount * 4);

  if (p != NULL) {
    SetEntityRoutine(p, OcclusionMask_Update, OcclusionMask_Destroy);
    p->sprites = (AuxSprite*)((u8*)p + spritesOffset);
    p->usedTiles = (u32*)((u8*)p->sprites + spritesSize);
    p->count = count;
    p->spriteCount = spriteCount;
    if (OcclusionMask_Init(p, param_1, param_2) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}

// 0x0AD8, マスクをかけるキャラを登録する, '.m' の種別で '.n' の Mover を slots に積む
s32 Cmd_AddOcclusionMaskTarget(void) {
  s32 kind = VM_GetNamedArgValue('m', 0);
  s32 id = VM_GetNamedArgValue('n', 0);

  if (id == 0) {
    return -1;
  }

  return OcclusionMask_AddTarget(kind, id);
}
