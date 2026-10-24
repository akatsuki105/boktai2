#include "collision_map.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "player.h"
#include "random.h"
#include "shadow.h"
#include "sound.h"
#include "sprite_aux.h"
#include "trig.h"
#include "vm.h"

// スプライト・ヒットボックス・影を1つずつ持つ
typedef struct EntityF1F9Item {
  AuxSprite sprite;   // 0x000
  u8 unk_2c[44];      // 0x02C
  HitboxData hitbox;  // 0x058
  AuxShadow shadow;   // 0x0A8, shadowId で管理
  Vec3 basePos;       // 0x114, 揺れの基準位置, sprite.pos へ複写する
  s16 unk_11c;        // 0x11C, 揺れの角速度, 折り返すたびに符号を反転して半分になる
  s16 unk_11e;        // 0x11E, 落下速度, 毎フレーム +2
  u8 unk_120[4];      // 0x120
  s16 unk_124;        // 0x124, basePos からの半径 (X 成分)
  u8 unk_126[2];      // 0x126
  s16 unk_128;        // 0x128, basePos からの半径 (Z 成分)
  u8 unk_12a[2];      // 0x12A
  s32 unk_12c;        // 0x12C, 1フレーム前の距離の2乗
  s32 unk_130;        // 0x130, プレイヤーとの距離の2乗
  s32 unk_134;        // 0x134, この距離まで近づかれると反応する
  u16 scriptID;       // 0x138, 破片1個ごとに VM_ExecByID へ渡す
  u16 unk_13a;        // 0x13A, 1マスぶんの距離
  u8 unk_13c;         // 0x13C, 全体のマス数
  u8 unk_13d;         // 0x13D, 現在のマス番号
  u16 groundY;        // 0x13E, 足元のタイルの高さ, 落下がここに届くと state 4 へ移る
  s16 unk_140;        // 0x140, 移動の始点
  s16 unk_142;        // 0x142, 現在位置
  u8 unk_144[3];      // 0x144
  u8 unk_147;         // 0x147, FUN_0809c344 の第4引数
  u16 state;          // 0x148, PTR_ARRAY_085ae104 の添字
  s16 idx;            // 0x14A, items の中での自分の添字, FUN_081d5864 が入れる
  u16 flags;          // 0x14C, FUN_081d5820 が立て、FUN_081d5834 が落とし、FUN_081d5848 が読む
  s8 shadowId;        // 0x14E, -1 なら影なし
  u8 unk_14f;         // 0x14F
  u16 unk_150;        // 0x150, HitboxData の unk_4 に入れる
  u8 unk_152;         // 0x152
  u8 unk_153;         // 0x153, 0 でない間はパレット 306 を強制して減らす
  u16 unk_154;        // 0x154, FUN_081d5d18 が毎フレーム 1 足すカウンタ
  u8 unk_156;         // 0x156, 立っていると FUN_081d5d18 が状態を初期化して落とす
  u8 unk_157;         // 0x157, 0 でない間はスプライトを ±10 揺らして減らす
} EntityF1F9Item;
static_assert(sizeof(EntityF1F9Item) == 344);

// 最大4個の EntityF1F9Item をビットマスクで管理するシングルトン
typedef struct {
  Entity e;                 // 0x000, ENTITY_UNK_10
  AuxAnimFile* anim;        // 0x018, ANIM_74C9
  EntityF1F9Item items[4];  // 0x01C
  u32 activeMask;           // 0x57C, bit i が立っていれば items[i] が使用中, _Init が 0 にする
} EntityF1F9;
static_assert(sizeof(EntityF1F9) == 1408);

IWRAM_DATA EntityF1F9* gEntityF1F9 = NULL;  // 0x03000198

s32 FUN_08014730(s32 count, s32 kind, Vec3* pos, Vec3* vel, Vec3* velRange, s32 lifeBase, s32 lifeRandMask);

void FUN_081ee584(Vec3* pos, s32 param_2, s32 param_3, s32 param_4, s32 param_5, s32 param_6, s32 param_7, s32 param_8, s32 param_9, s32 param_10, s32 param_11, s32 param_12);

void FUN_081d6444(EntityF1F9Item* item);
void FUN_081d65e8(EntityF1F9Item* item);
void FUN_081d6bc0(EntityF1F9Item* item);
s32 FUN_0805fe7c(HitboxData* hitbox, s32 param_2, s32 param_3, Vec3* pos, Vec3* param_5, s32 param_6);
void FUN_0809c344(s32 param_1, s32 param_2, u16 param_3, u8 param_4, s32 param_5);
void FUN_081d6764(EntityF1F9Item* item);
void FUN_081d6ae8(EntityF1F9Item* item, s32 n);
void FUN_081d6c24(EntityF1F9Item* item);

void FUN_081d5820(EntityF1F9Item* item, u16 n) { item->flags |= n; }

void FUN_081d5834(EntityF1F9Item* item, u16 n) { item->flags &= ~n; }

bool8 FUN_081d5848(EntityF1F9Item* item, u16 n) {
  if (item->flags & n) {
    return TRUE;
  }
  return FALSE;
}

// 空いているアイテムを確保して返す, 無ければ NULL
// 残差8命令 (37/45). 5命令は使用中判定の 0/1 の作り置き, 残りは原典がビットマスクの定数 1 をループ外のレジスタに持つ点
NON_MATCH EntityF1F9Item* FUN_081d5864(EntityF1F9* p) {
#ifdef NONMATCHING_C
  s32 i;

  for (i = 0; i < 4; i++) {
    if (!(p->activeMask & (1 << i))) {
      EntityF1F9Item* item = &p->items[i];

      p->activeMask |= 1 << i;
      ClearMemory(item, sizeof(EntityF1F9Item));
      item->idx = i;
      return item;
    }
  }
  return NULL;
#else
  INCFUNC("asm/func/FUN_081d5864.inc");
#endif
}

// unk_150 が id の使用中アイテムを探す
// 残差5命令 (36/41), 使用中判定の 0/1 の作り置き1ブロックだけが足りない
NON_MATCH EntityF1F9Item* FUN_081d58c4(s32 id) {
#ifdef NONMATCHING_C
  EntityF1F9* p = gEntityF1F9;
  EntityF1F9Item* item;
  u32 mask;
  s32 i;

  if (p == NULL) {
    return NULL;
  }

  mask = p->activeMask;
  item = p->items;
  for (i = 0; i < 4; i++, item++) {
    if (mask & (1 << i)) {
      if (item->unk_150 == id) {
        return item;
      }
    }
  }
  return NULL;
#else
  INCFUNC("asm/func/FUN_081d58c4.inc");
#endif
}

NAKED void FUN_081d5924(unknown* p) { INCFUNC("asm/func/FUN_081d5924.inc"); }

// 無敵時間を数えつつ、点滅用のパレットを選ぶ
NON_MATCH void FUN_081d5cac(EntityF1F9Item* item) {
#ifdef NONMATCHING_C
  if (item->hitbox.unk_44 != 0) {
    item->hitbox.flags |= HBFLAG_UNK_2;
    item->hitbox.unk_44--;
  } else {
    item->hitbox.flags &= ~HBFLAG_UNK_2;
  }
  if (item->unk_153 != 0) {
    Video_SetAuxSpritePltt(item->sprite.gfx, 306);
    item->unk_153--;
  } else {
    Video_SetAuxSpritePltt(item->sprite.gfx, 380);
  }
#else
  INCFUNC("asm/func/FUN_081d5cac.inc");
#endif
}

// state 0 のハンドラ, 何もしない
void FUN_081d5d14(EntityF1F9* p, EntityF1F9Item* item) {}

// state 1 のハンドラ
void FUN_081d5d18(EntityF1F9* p, EntityF1F9Item* item) {
  if (item->unk_156 != 0) {
    item->unk_154 = 0;
    AuxSprite_Show(&item->sprite);
    item->unk_156 = 0;
  }
  FUN_081d5cac(item);
  FUN_081d6444(item);
  if (item->unk_154 & 1) {
    FUN_081d6c24(item);
  }
  item->unk_154++;
}

NAKED void FUN_081d5d70(EntityF1F9* p, EntityF1F9Item* item) { INCFUNC("asm/func/FUN_081d5d70.inc"); }

// basePos を中心に (unk_124, unk_128) を rotation ぶん回した位置へ置き, 揺れを減衰させる
// 残差1命令 (179/180). 原典は符号付きに直した角度を r1 (スクラッチ) に置いて r7 まで使うが, agbcc は r5 に収めて1本節約する
// basePos を中心に (unk_124, unk_128) を rotation ぶん回す 2D 回転, unk_11c は折り返すたびに符号反転して半分になる減衰
NON_MATCH void FUN_081d5f54(EntityF1F9Item* item) {
#ifdef NONMATCHING_C
  s32 angle = item->sprite.rotation;

  if (angle > 0x80) {
    angle -= 0x100;
  } else if (angle < -0x80) {
    angle += 0x100;
  }

  if (angle == 0 && item->unk_11c == 0) {
    return;
  }

  item->sprite.pos.x = item->basePos.x + (COS(item->sprite.rotation, item->unk_124) + SIN(item->sprite.rotation, item->unk_128));
  item->sprite.pos.z = (-SIN(item->sprite.rotation, item->unk_124) + COS(item->sprite.rotation, item->unk_128)) + item->basePos.z;

  if (item->unk_11c == 0) {
    if (angle > 0) {
      item->sprite.rotation--;
    } else {
      item->sprite.rotation++;
    }
    return;
  }

  item->sprite.rotation += item->unk_11c;
  if (item->unk_11c > 0) {
    if (angle > item->unk_11c) {
      item->unk_11c = -item->unk_11c;
    }
  } else {
    if (angle < item->unk_11c) {
      item->unk_11c = -item->unk_11c;
      item->unk_11c = FixToInt(1, item->unk_11c);
    }
  }
#else
  INCFUNC("asm/func/FUN_081d5f54.inc");
#endif
}

// 足元の高さを測ってから落下させ, 着地したら state 4 へ移してエフェクトを撒く
// 残差1命令 (139/140) でこちらが短い. &item->sprite.pos を原典は r0 で作って r6 へ複写するがこちらは直接 r6 に作る, CpuSet の第1引数 (sp+0x20) の作り位置も1つずれる
// タイル高さの算出は collision_map.c の TileHeightAt と同形, あちらは static inline なので展開形を直書きした
NON_MATCH void FUN_081d60c8(EntityF1F9* p, EntityF1F9Item* item) {
#ifdef NONMATCHING_C
  if (item->unk_156) {
    Vec3* pos = &item->sprite.pos;
    MapTileOverride* ov;
    CollisionMapTile* tile;
    s32 stairs;
    s32 height;
    s32 bx;
    s32 bz;
    s32 idx;

    bx = (s8)(pos->x >> 8);
    bz = (s8)(pos->z >> 8);
    if (bx < 0 || bz < 0 || (u32)bx >= (u32)gMapBlockW || (u32)bz >= (u32)gMapBlockH) {
      idx = 0;
    } else {
      idx = gCollisionMap->rowOffsets[bz] + bx;
    }

    ov = Map_FindTileOverride(idx, 1);
    tile = (ov != NULL) ? &ov->tile : &gCollisionMap->tiledata->tiles[idx];

    stairs = tile->heightStairs >> 4;
    height = (tile->heightStairs & 0xF) << 8;
    switch (stairs) {
      case STAIRS_VERTICAL: {
        height -= (u8)pos->z;
        break;
      }
      case STAIRS_HORIZONTAL: {
        height -= (u8)pos->x;
        break;
      }
    }

    item->groundY = height;
    item->unk_156 = 0;
    CpuFill32(0, &item->unk_11c, 8);
  } else {
    item->sprite.pos.y -= item->unk_11e;
    item->unk_11e += 2;
    if (item->groundY >= item->sprite.pos.y) {
      s32 i;

      item->sprite.pos.y = item->groundY;
      item->state = 4;
      item->unk_156 = 1;
      for (i = 0; i < 8; i++) {
        FUN_081ee584(&item->sprite.pos, 8, 0x10, 4, 12, 0x12, i * 32, 8, 0x40, 1, 1, 0);
      }
    }
  }
#else
  INCFUNC("asm/func/FUN_081d60c8.inc");
#endif
}

// 残差1命令 (81/82). 原典は &item->idx の定数 0x14A を独立に作るが, agbcc は直前の item->state の 0x148 を +2 して使い回す (定数再利用のピープホール, ソース側から向きを変えられない)
NON_MATCH void FUN_081d6200(EntityF1F9* p, EntityF1F9Item* item) {
#ifdef NONMATCHING_C
  if (item->unk_156) {
    FUN_081d6764(item);
    if (item->unk_13d - item->unk_13c >= 0) {
      PlaySound_082406e0(SONG_967);
    }
    FUN_081d6ae8(item, item->unk_13d - item->unk_13c);
    if (item->shadowId != -1) {
      AuxShadow_Remove(&item->shadow);
      item->shadowId = -1;
    }
    PlaySound_082406e0(SONG_966);
    item->unk_156 = 0;
  } else {
    item->sprite.flags |= SPRFLAG_HIDDEN;
    AuxSprite_Remove(&item->sprite);
    Hitbox_Unregister(&item->hitbox);
    item->state = 0;
    p->activeMask &= ~(1 << item->idx);
    item->idx = -1;
  }
#else
  INCFUNC("asm/func/FUN_081d6200.inc");
#endif
}

void (*const PTR_ARRAY_085ae104[5])(EntityF1F9*, EntityF1F9Item*) = {
    FUN_081d5d14,
    FUN_081d5d18,
    FUN_081d5d70,
    FUN_081d60c8,
    FUN_081d6200,
};  // 0x085AE104

// 使用中のアイテムについて state ごとの更新関数を呼ぶ
// 残差6命令 (44/50). 5命令は使用中判定の 0/1 の作り置き, 残り1命令は &activeMask の作り方の違い
NON_MATCH s32 EntityF1F9_Update(EntityF1F9* p) {
#ifdef NONMATCHING_C
  EntityF1F9Item* items = p->items;

  if (p->activeMask != 0) {
    s32 i;

    for (i = 0; i < 4; i++) {
      if (p->activeMask & (1 << i)) {
        EntityF1F9Item* item = &items[i];

        PTR_ARRAY_085ae104[item->state](p, item);
      }
    }
  }

  return 0;
#else
  INCFUNC("asm/func/EntityF1F9_Update.inc");
#endif
}

// 使用中のアイテムのスプライト・判定・影をまとめて外す
// 残差5命令 (53/58), 使用中判定の 0/1 の作り置き1ブロックだけが足りない. 他は完全に一致
NON_MATCH s32 EntityF1F9_Destroy(EntityF1F9* p) {
#ifdef NONMATCHING_C
  s32 i;

  for (i = 0; i < 4; i++) {
    if (p->activeMask & (1 << i)) {
      EntityF1F9Item* item = &p->items[i];

      AuxSprite_Remove(&item->sprite);
      Hitbox_Unregister(&item->hitbox);
      if (item->shadowId != -1) {
        AuxShadow_Remove(&item->shadow);
        item->shadowId = -1;
      }
    }
  }

  gEntityF1F9 = NULL;
  return 0;
#else
  INCFUNC("asm/func/EntityF1F9_Destroy.inc");
#endif
}

s32 EntityF1F9_Init(EntityF1F9* p) {
  p->anim = GetFile(DIR_ANIMATION, ANIM_74C9);
  gEntityF1F9 = p;
  p->activeMask = 0;
  return 0;
}

EntityF1F9* EntityF1F9_Create(void) {
  EntityF1F9* p;

  if (gEntityF1F9 != NULL) {
    return gEntityF1F9;
  }
  p = CreateEntity(ENTITY_UNK_10, sizeof(EntityF1F9));
  if (p != NULL) {
    SetEntityRoutine(p, EntityF1F9_Update, EntityF1F9_Destroy);
    if (EntityF1F9_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

void FUN_081d6438(void) { gEntityF1F9 = NULL; }

// 被弾中はスプライトを基準位置から ±10 の範囲で揺らす
void FUN_081d6444(EntityF1F9Item* item) {
  if (item->unk_157 == 0) {
    item->sprite.pos = item->basePos;
  } else {
    u16* table = gRandomTable;
    item->sprite.pos.x = item->basePos.x + Mod(_Random(table), 20) - 10;
    item->sprite.pos.z = item->basePos.z + Mod(_Random(table), 20) - 10;
    item->unk_157--;
  }
}

// 被弾ハンドラ, 体力を削って演出を出し, 0 になったら state 4 へ移す
// 残差7命令 (115/122). 原典は高位レジスタを1本多く使い &item->hitbox.unk_44 を参照のたびに作り直すが, agbcc は CSE して1本に収めてしまう
// dealt は min(unk_140, damage) だが, 原典の形 (差を取ってから符号で分岐) に合わせて if/else で書いた
NON_MATCH void FUN_081d64d4(HitboxData* a, HitboxData* b, EntityF1F9Item* item) {
#ifdef NONMATCHING_C
  s32 dealt;
  Vec3 v;

  if (item->hitbox.unk_44 != 0) {
    return;
  }

  Hitbox_ApplyDamage(a, b);
  b->unk_44 = a->unk_44;
  dealt = item->unk_140 - item->hitbox.damage;
  if (dealt >= 0) {
    dealt = item->hitbox.damage;
  } else {
    dealt += item->hitbox.damage;
  }

  item->unk_140 -= item->hitbox.damage;
  if (item->unk_140 < 0) {
    item->unk_140 = 0;
  }

  FUN_0809c344(item->unk_150, item->unk_140, item->unk_142, item->unk_147, 0);
  CpuFill32(0, &v, sizeof(v));
  FUN_0805fe7c(b, dealt, 0, &item->sprite.pos, &v, 1);
  item->unk_153 = 3;
  item->unk_157 = 10;
  item->hitbox.unk_44 = 0x18;
  FUN_081d65e8(item);
  FUN_081d6bc0(item);
  PlaySound_082406e0(SE_ENEMY_DAMAGED);

  if (item->unk_140 <= 0) {
    item->state = 4;
    item->unk_156 = 1;
  }
#else
  INCFUNC("asm/func/FUN_081d64d4.inc");
#endif
}

// 破片を 2〜5 個, スプライト位置からばらまく
// 残差2命令 (92/94). 原典は item を低位レジスタに置いて &vel を先に作るが, agbcc は item を r9 へ追い出して &vel を後回しにする. table の代入位置を下げても変わらない
NON_MATCH void FUN_081d65e8(EntityF1F9Item* item) {
#ifdef NONMATCHING_C
  Vec3 vel;
  Vec3 velRange;
  u16* table = gRandomTable;

  CpuFill32(0, &vel, sizeof(vel));
  vel.y = 0x10;
  velRange.x = (_Random(table) & 3) + 15;
  velRange.y = (_Random(table) & 7) + 15;
  velRange.z = (_Random(table) & 3) + 15;
  FUN_08014730((_Random(table) & 3) + 2, 0x11, &item->sprite.pos, &vel, &velRange, 12, 15);
#else
  INCFUNC("asm/func/FUN_081d65e8.inc");
#endif
}

void FUN_081d66c0(EntityF1F9Item* item, u32 power, HitboxAttributes attributes, u32 weakness) {
  HitboxData* hitbox = &item->hitbox;
  Vec3 offset, halfSize;

  offset.x = 0, offset.y = 0x50, offset.z = 0;
  halfSize.x = 0x40, halfSize.y = 0x50, halfSize.z = 0x40;
  hitbox->id = item->unk_150;
  Hitbox_Init(hitbox, 0, HBFLAG_HURTBOX | HBFLAG_UNK_12 | HBFLAG_UNK_0, 0, 0x10, &halfSize, &offset);
  Hitbox_SetPowerAndAttributes(hitbox, power, attributes, weakness);
  Hitbox_SetPos(hitbox, &item->sprite.pos, 0);
  Hitbox_SetHandler(hitbox, FUN_081d64d4, item);
  Hitbox_Register(hitbox);
}

NAKED void FUN_081d6764(EntityF1F9Item* item) { INCFUNC("asm/func/FUN_081d6764.inc"); }

// スプライト位置の周りにばらつかせた座標でスクリプトを n 回呼ぶ
// 残差3命令 (96/99). 原典は while の入口判定 (cmp n,#0) を冒頭のガードと別に残すが agbcc は消す, また n を低位の呼び出し保存レジスタに置いてしまう
// table の代入をガードの後ろに下げるとプール読みの位置は合う
NON_MATCH void FUN_081d6ae8(EntityF1F9Item* item, s32 n) {
#ifdef NONMATCHING_C
  s32 argv[4];
  ScriptArgs sa;
  u16* table;

  if (n <= 0) {
    return;
  }
  if (item->scriptID == 0) {
    return;
  }

  sa.argc = 4;
  sa.argv = argv;
  table = gRandomTable;

  while (n > 0) {
    argv[0] = item->sprite.pos.x - 0x40 + (_Random(table) & 0x7F);
    argv[1] = item->sprite.pos.y - 0x40 + (_Random(table) & 0x7F);
    argv[2] = item->sprite.pos.z - 0x40 + (_Random(table) & 0x7F);
    argv[3] = item->unk_13c;
    VM_ExecByID(item->scriptID, &sa);
    item->unk_13c++;
    n--;
  }
#else
  INCFUNC("asm/func/FUN_081d6ae8.inc");
#endif
}

// 終端まで動いたら状態を切り替える
void FUN_081d6bc0(EntityF1F9Item* item) {
  if (item->unk_13d > item->unk_13c) {
    s32 d = item->unk_142 - item->unk_140;

    if (!FUN_081d5848(item, 1)) {
      FUN_081d6ae8(item, 2);
    }
    if (d >= item->unk_13a * (item->unk_13c - 1)) {
      FUN_081d6ae8(item, 1);
    }
  }
}

// プレイヤーが一定距離まで近づいたら起動する
NON_MATCH void FUN_081d6c24(EntityF1F9Item* item) {
#ifdef NONMATCHING_C
  if (!FUN_081d5848(item, 1)) {
    Vec3 d;
    d.x = gPlayerPtr[0]->mover.pos.x - item->sprite.pos.x;
    d.y = gPlayerPtr[0]->mover.pos.y - item->sprite.pos.y;
    d.z = gPlayerPtr[0]->mover.pos.z - item->sprite.pos.z;

    item->unk_130 = d.x * d.x + d.z * d.z;
    if (item->unk_130 < item->unk_134) {
      FUN_081d6ae8(item, 2);
      FUN_081d5820(item, 1);
      PlaySound_082406e0(SONG_967);
    }
  }
#else
  INCFUNC("asm/func/FUN_081d6c24.inc");
#endif
}

// プレイヤーとの距離を測り直し、反応する距離まで近づいていれば 1 を返す
NON_MATCH s32 FUN_081d6cb0(EntityF1F9Item* item) {
#ifdef NONMATCHING_C
  Vec3 d;
  d.x = gPlayerPtr[0]->mover.pos.x - item->basePos.x;
  d.y = gPlayerPtr[0]->mover.pos.y - item->basePos.y;
  d.z = gPlayerPtr[0]->mover.pos.z - item->basePos.z;

  item->unk_12c = item->unk_130;

  item->unk_130 = d.x * d.x + d.z * d.z;
  if (item->unk_130 < item->unk_134) {
    return 1;
  }
  return 0;
#else
  INCFUNC("asm/func/FUN_081d6cb0.inc");
#endif
}
