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
#include "vm.h"

// 蜂の巣が落ちて砕け散った時の破片1つ
typedef struct BeeNestFragment {
  AuxSprite sprite;          // 0x000
  AuxAnimState anim;         // 0x02C, ANIM_74C9
  AuxSpriteGfx gfx;          // 0x03C, SPRITE_BEE_NEST_BROKEN
  HitboxData hitbox;         // 0x058
  AuxShadow shadow;          // 0x0A8, shadowId で管理
  Vec3 basePos;              // 0x114, 揺れの基準位置, sprite.pos へ複写する
  s16 unk_11c;               // 0x11C, 揺れの角速度, 折り返すたびに符号を反転して半分になる
  s16 unk_11e;               // 0x11E, 落下速度, 毎フレーム +2
  u8 unk_120[4];             // 0x120
  s16 unk_124;               // 0x124, basePos からの半径 (X 成分)
  u8 unk_126[2];             // 0x126
  s16 unk_128;               // 0x128, basePos からの半径 (Z 成分)
  u8 unk_12a[2];             // 0x12A
  s32 unk_12c;               // 0x12C, 1フレーム前の距離の2乗
  s32 unk_130;               // 0x130, プレイヤーとの距離の2乗
  s32 unk_134;               // 0x134, この距離まで近づかれると反応する
  u16 scriptID;              // 0x138, 破片1個ごとに VM_ExecByID へ渡す
  u16 unk_13a;               // 0x13A, 1マスぶんの距離
  u8 unk_13c;                // 0x13C, 現在のマス番号, FUN_081d6ae8 が1つずつ進める
  u8 unk_13d;                // 0x13D, '.b', 全体のマス数
  u16 groundY;               // 0x13E, 足元のタイルの高さ, 落下がここに届くと state 4 へ移る
  s16 hp;                    // 0x140, '.A=100', 0 以下になると state 4 (または 3) へ移る
  s16 maxHp;                 // 0x142, hp の初期値, FUN_0809c344 へ渡す
  u8 unk_144[2];             // 0x144
  u8 unk_146;                // 0x146, '.A' の3番目
  u8 unk_147;                // 0x147, FUN_0809c344 の第4引数
  u16 state;                 // 0x148, PTR_ARRAY_085ae104 の添字
  s16 idx;                   // 0x14A, fragments の中での自分の添字, FUN_081d5864 が入れる
  u16 flags;                 // 0x14C, FUN_081d5820 が立て、FUN_081d5834 が落とし、FUN_081d5848 が読む
  s8 shadowId;               // 0x14E, -1 なら影なし
  u8 unk_14f;                // 0x14F
  u16 unk_150;               // 0x150, HitboxData の unk_4 に入れる
  AuxAnimPlayFlags unk_152;  // 0x152
  u8 unk_153;                // 0x153, 0 でない間はパレット 306 を強制して減らす
  u16 unk_154;               // 0x154, FUN_081d5d18 が毎フレーム 1 足すカウンタ
  u8 unk_156;                // 0x156, 立っていると FUN_081d5d18 が状態を初期化して落とす
  u8 unk_157;                // 0x157, 0 でない間はスプライトを ±10 揺らして減らす
} BeeNestFragment;
static_assert(sizeof(BeeNestFragment) == 344);

// HashName("蜂の巣")
// 中からビー系の敵が出てくる
// プレイヤーが近づいたり、攻撃を受けたりすると落ちて砕け散る (その際に ビー系の敵 が一気に出現する)
typedef struct {
  Entity e;                      // 0x000, ENTITY_UNK_10
  AuxAnimFile* anim;             // 0x018, ANIM_74C9
  BeeNestFragment fragments[4];  // 0x01C, 蜂の巣の破片4つ
  u32 activeMask;                // 0x57C, bit i が立っていれば fragments[i] が使用中, _Init が 0 にする
} BeeNest;
static_assert(sizeof(BeeNest) == 1408);

IWRAM_DATA BeeNest* gBeeNest = NULL;  // 0x03000198

static inline bool8 BeeNest_IsActive(u32* mask, s32 i) {
  if (TEST_FLAGS(*mask, 1 << i)) return TRUE;
  return FALSE;
}

s32 FUN_08014730(s32 count, s32 kind, Vec3* pos, Vec3* vel, Vec3* velRange, s32 lifeBase, s32 lifeRandMask);

void FUN_081ee584(Vec3* pos, s32 param_2, s32 param_3, s32 param_4, s32 param_5, s32 param_6, s32 param_7, s32 param_8, s32 param_9, s32 param_10, s32 param_11, s32 param_12);

void FUN_081d5f54(BeeNestFragment* frag);
bool8 FUN_081d6cb0(BeeNestFragment* frag);
s32 Entity081efa9c_Spawn(Vec3* pos, Vec3* vel, u32 spriteID, u32 animID, s32 param_5, s32 param_6, s32 param_7, s32 param_8, s32 param_9, s32 param_10, s32 param_11, s32 param_12, s32 param_13, s32 param_14, s32 param_15);

BeeNest* BeeNest_Create(void);
BeeNestFragment* FUN_081d5864(BeeNest* p);
void BeeNestFragment_InitHurtbox(BeeNestFragment* frag, u32 power, HitboxAttributes attributes, u32 weakness);

void FUN_081d6444(BeeNestFragment* frag);
void FUN_081d65e8(BeeNestFragment* frag);
void FUN_081d6bc0(BeeNestFragment* frag);
void FUN_0809c344(s32 param_1, s32 param_2, u16 param_3, u16 param_4, s32 param_5);
void FUN_081d6764(BeeNestFragment* frag);
void FUN_081d6ae8(BeeNestFragment* frag, s32 n);
void FUN_081d6c24(BeeNestFragment* frag);

void FUN_081d5820(BeeNestFragment* frag, u16 n) { frag->flags |= n; }

void FUN_081d5834(BeeNestFragment* frag, u16 n) { frag->flags &= ~n; }

bool8 FUN_081d5848(BeeNestFragment* frag, u16 n) {
  if (frag->flags & n) {
    return TRUE;
  }
  return FALSE;
}

// 空いているアイテムを確保して返す, 無ければ NULL
BeeNestFragment* FUN_081d5864(BeeNest* p) {
  s32 i;

  for (i = 0; i < 4; i++) {
    if (!BeeNest_IsActive(&p->activeMask, i)) {
      BeeNestFragment* frag = &p->fragments[i];

      p->activeMask |= 1 << i;
      ClearMemory(frag, sizeof(BeeNestFragment));
      frag->idx = i;
      return frag;
    }
  }
  return NULL;
}

// unk_150 が id の使用中アイテムを探す
// 残差5命令 (36/41), 使用中判定の 0/1 の作り置き1ブロックだけが足りない
// bool8 を返す static inline (BeeNest_IsActive(&p->activeMask, i)) にすると 0/1 の作り置きは出るが, 原典は activeMask をループ外で1回読んでレジスタに持つ
NON_MATCH BeeNestFragment* FUN_081d58c4(s32 id) {
#ifdef NONMATCHING_C
  BeeNest* p = gBeeNest;
  BeeNestFragment* frag;
  u32 mask;
  s32 i;

  if (p == NULL) {
    return NULL;
  }

  mask = p->activeMask;
  frag = p->fragments;
  for (i = 0; i < 4; i++, frag++) {
    if (mask & (1 << i)) {
      if (frag->unk_150 == id) {
        return frag;
      }
    }
  }
  return NULL;
#else
  INCFUNC("asm/func/FUN_081d58c4.inc");
#endif
}

// 0xF1F9, HashName("蜂の巣")
// スクリプトから1体ぶんのパラメータを受け取って空きアイテムに仕込む
// 残差12命令 (415/403) でこちらが長い. agbcc は p の生死範囲を分けて FUN_081d5864 の呼び出しを NULL 分岐側にも複製するが, 原典は合流後に1つだけ持つ. ガードを平坦化しても変わらない
// unk_2c[44] は AuxAnimState anim (0x2C) + AuxSpriteGfx gfx (0x3C) に分解, unk_140/unk_142 は hp/maxHp に改名
NON_MATCH void Cmd_CreateBeeNest(void) {
#ifdef NONMATCHING_C
  BeeNest* p = gBeeNest;
  BeeNestFragment* frag;
  s32 power;
  s32 attributes;
  s32 weakness;
  AuxAnimCmd* cmd;

  if (p == NULL) {
    p = BeeNest_Create();
    if (p == NULL) {
      return;
    }
  }

  frag = FUN_081d5864(p);
  if (frag == NULL) {
    return;
  }

  Video_GetAuxSprite(&frag->gfx, SPRITE_BEE_NEST_BROKEN);
  AuxSprite_Add(&frag->sprite, &frag->gfx, 0);
  frag->unk_156 = 1;
  frag->unk_13c = 0;
  frag->flags = VM_GetNamedArgValue('m', 0);

  if (FUN_081d5848(frag, 2)) {
    frag->state = 2;
  } else {
    frag->state = 1;
  }

  if (VM_SeekToNamedArg('p')) {
    frag->sprite.pos.x = VM_GetValue();
    frag->sprite.pos.y = VM_GetValue();
    frag->sprite.pos.z = VM_GetValue();
  }
  frag->basePos = frag->sprite.pos;

  frag->unk_152 = VM_GetNamedArgValue('r', 0);
  frag->unk_150 = VM_GetNamedArgValue('n', 0);
  frag->unk_134 = VM_GetNamedArgValue('a', 0x100) * VM_GetNamedArgValue('a', 0x100);
  frag->unk_13d = VM_GetNamedArgValue('b', 0);

  if (VM_SeekToNamedArg('A')) {
    frag->hp = VM_GetPC() != NULL ? VM_GetValue() : 0;
    frag->unk_147 = VM_GetPC() != NULL ? VM_GetValue() : 0;
    frag->unk_146 = VM_GetPC() != NULL ? VM_GetValue() : 0;
    power = VM_GetPC() != NULL ? VM_GetValue() : 0;
    attributes = VM_GetPC() != NULL ? VM_GetValue() : 0;
    weakness = VM_GetPC() != NULL ? VM_GetValue() : 0;
  } else {
    frag->hp = 100;
    frag->unk_147 = 3;
    frag->unk_146 = 0;
    power = 0;
    attributes = 0;
    weakness = 0;
  }

  frag->maxHp = frag->hp;
  frag->unk_13a = Div(frag->hp, frag->unk_13d - 1);

  if (VM_SeekToNamedArg('P')) {
    frag->scriptID = VM_GetPC() != NULL ? VM_GetValue() : 0;
  }

  if (FUN_081d5848(frag, 2)) {
    frag->shadowId = AuxShadow_Init(&frag->shadow, &frag->sprite.pos, 0x40, 0x10, 0x60, 100, 0xA00, 1, 5, 1, 0);
  } else {
    frag->shadowId = AuxShadow_Init(&frag->shadow, &frag->sprite.pos, 0x40, 0x10, 0x80, 100, 0xA00, 1, 5, 1, 0);
  }

  AuxAnim_SetAnim(&frag->anim, p->anim, 0, 0, frag->unk_152);

  cmd = &frag->anim.cmds[frag->anim.cmdIdx];
  frag->sprite.poseIdx = *cmd >> 6;
  if ((frag->anim.flags & ANIM_PLAY_XFLIP) != (((*cmd & 0x30) >> 4) & ANIM_PLAY_XFLIP)) {
    frag->sprite.flags |= SPRFLAG_XFLIP;
  } else {
    frag->sprite.flags &= ~SPRFLAG_XFLIP;
  }
  if ((frag->anim.flags & ANIM_PLAY_YFLIP) != (((*cmd & 0x30) >> 4) & ANIM_PLAY_YFLIP)) {
    frag->sprite.flags |= SPRFLAG_YFLIP;
  } else {
    frag->sprite.flags &= ~SPRFLAG_YFLIP;
  }

  frag->anim.tick++;
  if (frag->anim.tick >= frag->anim.wait) {
    frag->anim.tick = 0;
    if (frag->anim.flags & ANIM_PLAY_REVERSE) {
      if (frag->anim.cmdIdx == 0) {
        frag->anim.cmdIdx = frag->anim.cmdCount;
      }
      frag->anim.cmdIdx--;
    } else {
      frag->anim.cmdIdx++;
      if (frag->anim.cmdIdx >= frag->anim.cmdCount) {
        frag->anim.cmdIdx = 0;
      }
    }
    frag->anim.duration = frag->anim.cmds[frag->anim.cmdIdx] & 0xF;
    frag->anim.wait = (frag->anim.duration * frag->anim.speed) >> 6;
    if (frag->anim.wait == 0) {
      frag->anim.wait = 1;
    }
  }

  BeeNestFragment_InitHurtbox(frag, power, attributes, weakness);
#else
  INCFUNC("asm/func/Cmd_CreateBeeNest.inc");
#endif
}

// 無敵時間を数えつつ、点滅用のパレットを選ぶ
NON_MATCH void FUN_081d5cac(BeeNestFragment* frag) {
#ifdef NONMATCHING_C
  if (frag->hitbox.invincibleTime != 0) {
    frag->hitbox.flags |= HBFLAG_HIDDEN;
    frag->hitbox.invincibleTime--;
  } else {
    frag->hitbox.flags &= ~HBFLAG_HIDDEN;
  }
  if (frag->unk_153 != 0) {
    Video_SetAuxSpritePltt(frag->sprite.gfx, 306);
    frag->unk_153--;
  } else {
    Video_SetAuxSpritePltt(frag->sprite.gfx, 380);
  }
#else
  INCFUNC("asm/func/FUN_081d5cac.inc");
#endif
}

// state 0 のハンドラ, 何もしない
void FUN_081d5d14(BeeNest* p, BeeNestFragment* frag) {}

// state 1 のハンドラ
void FUN_081d5d18(BeeNest* p, BeeNestFragment* frag) {
  if (frag->unk_156 != 0) {
    frag->unk_154 = 0;
    AuxSprite_Show(&frag->sprite);
    frag->unk_156 = 0;
  }
  FUN_081d5cac(frag);
  FUN_081d6444(frag);
  if (frag->unk_154 & 1) {
    FUN_081d6c24(frag);
  }
  frag->unk_154++;
}

// state 2 の更新, 入場時に揺れの半径を仕込み, 条件が揃うと揺らして回数を減らす
// 残差4命令 (219/223). 原典は &frag->unk_124 を CpuSet のプール定数より先に作るが, agbcc は後回しにする (定数の作り位置のずれ)
// 呼び出し側が lsls #24 で丸めているので FUN_081d6cb0 の戻り値を bool8 にした (あちらの残差 69/57 は変わらない)
NON_MATCH void FUN_081d5d70(BeeNest* p, BeeNestFragment* frag) {
#ifdef NONMATCHING_C
  if (frag->unk_156) {
    frag->unk_154 = 0;
    frag->sprite.flags &= ~SPRFLAG_HIDDEN;
    frag->sprite.flags |= SPRFLAG_AFFINE;
    frag->unk_156 = 0;
    CpuFill32(0, &frag->unk_124, 8);
    frag->unk_124 = 0x29;
    frag->unk_128 = 0x94;
    frag->sprite.pos.x = frag->basePos.x + (POLAR_X(frag->unk_124, frag->sprite.rotation) + POLAR_Z(frag->unk_128, frag->sprite.rotation));
    frag->sprite.pos.z = (-POLAR_Z(frag->unk_124, frag->sprite.rotation) + POLAR_X(frag->unk_128, frag->sprite.rotation)) + frag->basePos.z;
  }

  if ((frag->unk_154 & 1) && FUN_081d6cb0(frag) && !(gPlayerPtr[0]->flag20 & PFLAG20_UNK_3) && !(gGoodCondTimer != 0 && gGoodCondID == 0) && gPlayerPtr[0]->kind != PLAYER_BAT && frag->unk_12c != frag->unk_130 && frag->unk_11c == 0) {
    frag->unk_11c = 4;
    frag->hp--;
    if (frag->hp > 0) {
      PlaySound_082406e0(SONG_969);
    } else {
      frag->state = 3;
      frag->unk_156 = 1;
      return;
    }
  }

  FUN_081d5f54(frag);
  frag->unk_154++;
#else
  INCFUNC("asm/func/FUN_081d5d70.inc");
#endif
}

// basePos を中心に (unk_124, unk_128) を rotation ぶん回した位置へ置き, 揺れを減衰させる
// 残差1命令 (179/180). 原典は符号付きに直した角度を r1 (スクラッチ) に置いて r7 まで使うが, agbcc は r5 に収めて1本節約する
// basePos を中心に (unk_124, unk_128) を rotation ぶん回す 2D 回転, unk_11c は折り返すたびに符号反転して半分になる減衰
NON_MATCH void FUN_081d5f54(BeeNestFragment* frag) {
#ifdef NONMATCHING_C
  s32 angle = frag->sprite.rotation;

  if (angle > 0x80) {
    angle -= 0x100;
  } else if (angle < -0x80) {
    angle += 0x100;
  }

  if (angle == 0 && frag->unk_11c == 0) {
    return;
  }

  frag->sprite.pos.x = frag->basePos.x + (POLAR_X(frag->unk_124, frag->sprite.rotation) + POLAR_Z(frag->unk_128, frag->sprite.rotation));
  frag->sprite.pos.z = (-POLAR_Z(frag->unk_124, frag->sprite.rotation) + POLAR_X(frag->unk_128, frag->sprite.rotation)) + frag->basePos.z;

  if (frag->unk_11c == 0) {
    if (angle > 0) {
      frag->sprite.rotation--;
    } else {
      frag->sprite.rotation++;
    }
    return;
  }

  frag->sprite.rotation += frag->unk_11c;
  if (frag->unk_11c > 0) {
    if (angle > frag->unk_11c) {
      frag->unk_11c = -frag->unk_11c;
    }
  } else {
    if (angle < frag->unk_11c) {
      frag->unk_11c = -frag->unk_11c;
      frag->unk_11c = FixToInt(1, frag->unk_11c);
    }
  }
#else
  INCFUNC("asm/func/FUN_081d5f54.inc");
#endif
}

// 足元の高さを測ってから落下させ, 着地したら state 4 へ移してエフェクトを撒く
// 残差1命令 (139/140) でこちらが短い. &frag->sprite.pos を原典は r0 で作って r6 へ複写するがこちらは直接 r6 に作る, CpuSet の第1引数 (sp+0x20) の作り位置も1つずれる
// タイル高さの算出は collision_map.c の TileHeightAt と同形, あちらは static inline なので展開形を直書きした
NON_MATCH void FUN_081d60c8(BeeNest* p, BeeNestFragment* frag) {
#ifdef NONMATCHING_C
  if (frag->unk_156) {
    Vec3* pos = &frag->sprite.pos;
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

    frag->groundY = height;
    frag->unk_156 = 0;
    CpuFill32(0, &frag->unk_11c, 8);
  } else {
    frag->sprite.pos.y -= frag->unk_11e;
    frag->unk_11e += 2;
    if (frag->groundY >= frag->sprite.pos.y) {
      s32 i;

      frag->sprite.pos.y = frag->groundY;
      frag->state = 4;
      frag->unk_156 = 1;
      for (i = 0; i < 8; i++) {
        FUN_081ee584(&frag->sprite.pos, 8, 0x10, 4, 12, 0x12, i * 32, 8, 0x40, 1, 1, 0);
      }
    }
  }
#else
  INCFUNC("asm/func/FUN_081d60c8.inc");
#endif
}

// 残差1命令 (81/82). 原典は &frag->idx の定数 0x14A を独立に作るが, agbcc は直前の frag->state の 0x148 を +2 して使い回す (定数再利用のピープホール, ソース側から向きを変えられない)
NON_MATCH void FUN_081d6200(BeeNest* p, BeeNestFragment* frag) {
#ifdef NONMATCHING_C
  if (frag->unk_156) {
    FUN_081d6764(frag);
    if (frag->unk_13d - frag->unk_13c >= 0) {
      PlaySound_082406e0(SONG_967);
    }
    FUN_081d6ae8(frag, frag->unk_13d - frag->unk_13c);
    if (frag->shadowId != -1) {
      AuxShadow_Remove(&frag->shadow);
      frag->shadowId = -1;
    }
    PlaySound_082406e0(SONG_966);
    frag->unk_156 = 0;
  } else {
    frag->sprite.flags |= SPRFLAG_HIDDEN;
    AuxSprite_Remove(&frag->sprite);
    Hitbox_Unregister(&frag->hitbox);
    frag->state = 0;
    p->activeMask &= ~(1 << frag->idx);
    frag->idx = -1;
  }
#else
  INCFUNC("asm/func/FUN_081d6200.inc");
#endif
}

void (*const PTR_ARRAY_085ae104[5])(BeeNest*, BeeNestFragment*) = {
    FUN_081d5d14,
    FUN_081d5d18,
    FUN_081d5d70,
    FUN_081d60c8,
    FUN_081d6200,
};  // 0x085AE104

// 使用中のアイテムについて state ごとの更新関数を呼ぶ
s32 BeeNest_Update(BeeNest* p) {
  BeeNestFragment* fragments = p->fragments;
  s32 i;

  if (p->activeMask == 0) {
    return 0;
  }

  for (i = 0; i < 4; i++) {
    if (BeeNest_IsActive(&p->activeMask, i)) {
      PTR_ARRAY_085ae104[fragments[i].state](p, &fragments[i]);
    }
  }

  return 0;
}

// 使用中のアイテムのスプライト・判定・影をまとめて外す
s32 BeeNest_Destroy(BeeNest* p) {
  s32 i;

  for (i = 0; i < 4; i++) {
    if (BeeNest_IsActive(&p->activeMask, i)) {
      BeeNestFragment* frag = &p->fragments[i];

      AuxSprite_Remove(&frag->sprite);
      Hitbox_Unregister(&frag->hitbox);
      if (frag->shadowId != -1) {
        AuxShadow_Remove(&frag->shadow);
        frag->shadowId = -1;
      }
    }
  }

  gBeeNest = NULL;
  return 0;
}

s32 BeeNest_Init(BeeNest* p) {
  p->anim = GetFile(DIR_ANIMATION, ANIM_74C9);
  gBeeNest = p;
  p->activeMask = 0;
  return 0;
}

BeeNest* BeeNest_Create(void) {
  BeeNest* p;

  if (gBeeNest != NULL) {
    return gBeeNest;
  }
  p = CreateEntity(ENTITY_UNK_10, sizeof(BeeNest));
  if (p != NULL) {
    SetEntityRoutine(p, BeeNest_Update, BeeNest_Destroy);
    if (BeeNest_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

void FUN_081d6438(void) { gBeeNest = NULL; }

// 被弾中はスプライトを基準位置から ±10 の範囲で揺らす
void FUN_081d6444(BeeNestFragment* frag) {
  if (frag->unk_157 == 0) {
    frag->sprite.pos = frag->basePos;
  } else {
    u16* table = gRandomTable;
    frag->sprite.pos.x = frag->basePos.x + Mod(_Random(table), 20) - 10;
    frag->sprite.pos.z = frag->basePos.z + Mod(_Random(table), 20) - 10;
    frag->unk_157--;
  }
}

// 被弾ハンドラ, 体力を削って演出を出し, 0 になったら state 4 へ移す
// 残差7命令 (115/122). 原典は高位レジスタを1本多く使い &frag->hitbox.invincibleTime を参照のたびに作り直すが, agbcc は CSE して1本に収めてしまう
// dealt は min(unk_140, damage) だが, 原典の形 (差を取ってから符号で分岐) に合わせて if/else で書いた
NON_MATCH void FUN_081d64d4(HitboxData* a, HitboxData* b, BeeNestFragment* frag) {
#ifdef NONMATCHING_C
  s32 dealt;
  Vec3 v;

  if (frag->hitbox.invincibleTime != 0) {
    return;
  }

  Hitbox_ApplyDamage(a, b);
  b->invincibleTime = a->invincibleTime;
  dealt = frag->hp - frag->hitbox.damage;
  if (dealt >= 0) {
    dealt = frag->hitbox.damage;
  } else {
    dealt += frag->hitbox.damage;
  }

  frag->hp -= frag->hitbox.damage;
  if (frag->hp < 0) {
    frag->hp = 0;
  }

  FUN_0809c344(frag->unk_150, frag->hp, frag->maxHp, frag->unk_147, 0);
  CpuFill32(0, &v, sizeof(v));
  CreateDamageNumber(b, dealt, 0, &frag->sprite.pos, &v, 1);
  frag->unk_153 = 3;
  frag->unk_157 = 10;
  frag->hitbox.invincibleTime = 0x18;
  FUN_081d65e8(frag);
  FUN_081d6bc0(frag);
  PlaySound_082406e0(SE_ENEMY_DAMAGED);

  if (frag->hp <= 0) {
    frag->state = 4;
    frag->unk_156 = 1;
  }
#else
  INCFUNC("asm/func/FUN_081d64d4.inc");
#endif
}

// 破片を 2〜5 個, スプライト位置からばらまく
// 残差2命令 (92/94). 原典は frag を低位レジスタに置いて &vel を先に作るが, agbcc は frag を r9 へ追い出して &vel を後回しにする. table の代入位置を下げても変わらない
NON_MATCH void FUN_081d65e8(BeeNestFragment* frag) {
#ifdef NONMATCHING_C
  Vec3 vel;
  Vec3 velRange;
  u16* table = gRandomTable;

  CpuFill32(0, &vel, sizeof(vel));
  vel.y = 0x10;
  velRange.x = (_Random(table) & 3) + 15;
  velRange.y = (_Random(table) & 7) + 15;
  velRange.z = (_Random(table) & 3) + 15;
  FUN_08014730((_Random(table) & 3) + 2, 0x11, &frag->sprite.pos, &vel, &velRange, 12, 15);
#else
  INCFUNC("asm/func/FUN_081d65e8.inc");
#endif
}

void BeeNestFragment_InitHurtbox(BeeNestFragment* frag, u32 power, HitboxAttributes attributes, u32 weakness) {
  HitboxData* hitbox = &frag->hitbox;
  Vec3 offset, halfSize;

  VEC3_SET(offset, 0, Q8(0.313), 0);
  VEC3_SET(halfSize, Q8(0.25), Q8(0.313), Q8(0.25));
  hitbox->id = frag->unk_150;
  Hitbox_Init(hitbox, 0, HBFLAG_HURTBOX | HBFLAG_ACTOR | HBFLAG_UNK_0, 0, 0x10, &halfSize, &offset);
  Hitbox_SetPowerAndAttributes(hitbox, power, attributes, weakness);
  Hitbox_SetPos(hitbox, &frag->sprite.pos, 0);
  Hitbox_SetHandler(hitbox, FUN_081d64d4, frag);
  Hitbox_Register(hitbox);
}

// 壊れた蜂の巣の破片を5個, ランダムな向きへ飛ばす
// 残差20命令 (391/371) でこちらが長い. 原典は各ブロックで 0xff / &vel / 振幅10 / gSineTable をブロック先頭に作って POLAR_X と POLAR_Z で共有するが, agbcc は使用箇所ごとに作り直す (1ブロックあたり4命令)
// static inline void SetVelFromAngle(Vec3*, u8) を通すと 382/371 まで寄るが一致しないので外した
NON_MATCH void FUN_081d6764(BeeNestFragment* frag) {
#ifdef NONMATCHING_C
  Vec3 vel;
  u8 angle;

  angle = Random();
  vel.x = POLAR_X(10, angle), vel.y = 0, vel.z = POLAR_Z(10, angle);
  vel.y = 0x40;
  Entity081efa9c_Spawn(&frag->sprite.pos, &vel, SPRITE_BEE_NEST_BROKEN, ANIM_74C9, 1, 30, 2, 0, 380, 0, 0, 0, 0, 0, 0);

  angle = Random();
  vel.x = POLAR_X(10, angle), vel.y = 0, vel.z = POLAR_Z(10, angle);
  vel.y = 0x22;
  Entity081efa9c_Spawn(&frag->sprite.pos, &vel, SPRITE_BEE_NEST_BROKEN, ANIM_74C9, 1, 30, 2, 0, 380, 0, 0, 0, 0, 0, 0);

  angle = Random();
  vel.x = POLAR_X(10, angle), vel.y = 0, vel.z = POLAR_Z(10, angle);
  vel.y = 0x22;
  Entity081efa9c_Spawn(&frag->sprite.pos, &vel, SPRITE_BEE_NEST_BROKEN, ANIM_74C9, 1, 30, 2, 0, 380, 0, 1, 0, 0, 0, 0);

  angle = Random();
  vel.x = POLAR_X(10, angle), vel.y = 0, vel.z = POLAR_Z(10, angle);
  vel.y = 0x22;
  Entity081efa9c_Spawn(&frag->sprite.pos, &vel, SPRITE_BEE_NEST_BROKEN, ANIM_74C9, 1, 30, 2, 0, 380, 1, 0, 0, 0, 0, 0);

  angle = Random();
  vel.x = POLAR_X(10, angle), vel.y = 0, vel.z = POLAR_Z(10, angle);
  vel.y = 0x22;
  Entity081efa9c_Spawn(&frag->sprite.pos, &vel, SPRITE_BEE_NEST_BROKEN, ANIM_74C9, 1, 30, 2, 0, 380, 2, 0, 0, 0, 0, 0);

  FUN_081d65e8(frag);
#else
  INCFUNC("asm/func/FUN_081d6764.inc");
#endif
}

// スプライト位置の周りにばらつかせた座標でスクリプトを n 回呼ぶ
// 残差3命令 (96/99). 原典は while の入口判定 (cmp n,#0) を冒頭のガードと別に残すが agbcc は消す, また n を低位の呼び出し保存レジスタに置いてしまう
// table の代入をガードの後ろに下げるとプール読みの位置は合う
NON_MATCH void FUN_081d6ae8(BeeNestFragment* frag, s32 n) {
#ifdef NONMATCHING_C
  s32 argv[4];
  ScriptArgs sa;
  u16* table;

  if (n <= 0) {
    return;
  }
  if (frag->scriptID == 0) {
    return;
  }

  sa.argc = 4;
  sa.argv = argv;
  table = gRandomTable;

  while (n > 0) {
    argv[0] = frag->sprite.pos.x - 0x40 + (_Random(table) & 0x7F);
    argv[1] = frag->sprite.pos.y - 0x40 + (_Random(table) & 0x7F);
    argv[2] = frag->sprite.pos.z - 0x40 + (_Random(table) & 0x7F);
    argv[3] = frag->unk_13c;
    VM_ExecByID(frag->scriptID, &sa);
    frag->unk_13c++;
    n--;
  }
#else
  INCFUNC("asm/func/FUN_081d6ae8.inc");
#endif
}

// 終端まで動いたら状態を切り替える
void FUN_081d6bc0(BeeNestFragment* frag) {
  if (frag->unk_13d > frag->unk_13c) {
    s32 d = frag->maxHp - frag->hp;

    if (!FUN_081d5848(frag, 1)) {
      FUN_081d6ae8(frag, 2);
    }
    if (d >= frag->unk_13a * (frag->unk_13c - 1)) {
      FUN_081d6ae8(frag, 1);
    }
  }
}

// プレイヤーが一定距離まで近づいたら起動する
NON_MATCH void FUN_081d6c24(BeeNestFragment* frag) {
#ifdef NONMATCHING_C
  if (!FUN_081d5848(frag, 1)) {
    Vec3 d;
    d.x = gPlayerPtr[0]->mover.pos.x - frag->sprite.pos.x;
    d.y = gPlayerPtr[0]->mover.pos.y - frag->sprite.pos.y;
    d.z = gPlayerPtr[0]->mover.pos.z - frag->sprite.pos.z;

    frag->unk_130 = d.x * d.x + d.z * d.z;
    if (frag->unk_130 < frag->unk_134) {
      FUN_081d6ae8(frag, 2);
      FUN_081d5820(frag, 1);
      PlaySound_082406e0(SONG_967);
    }
  }
#else
  INCFUNC("asm/func/FUN_081d6c24.inc");
#endif
}

// プレイヤーとの距離を測り直し、反応する距離まで近づいていれば 1 を返す
NON_MATCH bool8 FUN_081d6cb0(BeeNestFragment* frag) {
#ifdef NONMATCHING_C
  Vec3 d;
  d.x = gPlayerPtr[0]->mover.pos.x - frag->basePos.x;
  d.y = gPlayerPtr[0]->mover.pos.y - frag->basePos.y;
  d.z = gPlayerPtr[0]->mover.pos.z - frag->basePos.z;

  frag->unk_12c = frag->unk_130;

  frag->unk_130 = d.x * d.x + d.z * d.z;
  if (frag->unk_130 < frag->unk_134) {
    return 1;
  }
  return 0;
#else
  INCFUNC("asm/func/FUN_081d6cb0.inc");
#endif
}
