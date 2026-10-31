#include "camera.h"
#include "collision_map.h"
#include "entity.h"
#include "global.h"
#include "malloc.h"
#include "player.h"
#include "registry.h"
#include "sound.h"
#include "sprite.h"
#include "vm.h"

// 扉1体, DoorManager.doors が doorMax 体ぶん並べて持つ
typedef struct Door {
  AuxSprite sprite;          // 0x00, DoorManager_Destroy が AuxSprite_Remove に渡す
  MapTileOverride* ov;       // 0x2C, DoorManager_Destroy が NULL でなければ Free する
  void (*fn)(struct Door*);  // 0x30, FUN_08020AF8 が FUN_08020B88 を、FUN_08020B24 が別のハンドラを入れる
  u16 id;                    // 0x34, 扉のID, FUN_0801fe58 が一致する扉に unk_36 の bit0 を立てる
  u8 unk_36;                 // 0x36, bitfield
  u8 phase;                  // 0x37, 0=開ききった 1=閉じきった 2=開いている途中 3=閉じている途中
  u8 dir;                    // 0x38, 扉の向き, step と組で絵の優先度と facing の表を引く, bit0 で閉じたときの煙がずれる軸が決まる, 0x38 から 0x40 にかけては 32bit の ldr とバイト単位の strb が重なっていて境界が決まらない (u32 と u8[4] の union?)
  u8 step;                   // 0x39, 絵のコマ (0〜2), dir と組で表を引く
  u8 unk_3a;                 // 0x3A, step を変えるたびに 0 に戻る, 読み手は asm 側だけ
  u8 tileHeight;             // 0x3B, tile.heightStairs の下位4bit に入る高さ, 閉じているときは +1 した値が入る
  u16 unk_3c;                // 0x3C, 扉のID (FUN_08020358 が unk_40 == 2 の扉と突き合わせる)
  u8 unk_3e;                 // 0x3E
  u8 unk_3f;                 // 0x3F
  u8 unk_40;                 // 0x40, 2 のとき unk_3c が有効
  u8 unk_41;                 // 0x41, FUN_0801fc88 が 1 を入れる
  u8 unk_42[30];             // 0x42
  s32 openScriptID;          // 0x60, '.p', 開き終わったときに VM_ExecByID する
  s32 closeScriptID;         // 0x64, '.p', 閉じ終わったときに VM_ExecByID する
  u8 unk_68[0x70 - 0x68];    // 0x68
  Vec3 pos_70;               // 0x70, 扉の絵の基準位置, FUN_0801f7f4 が種類ごとに下駄を履かせて sprite.pos へ入れる
  u8 unk_78[0x7A - 0x78];    // 0x78
  u16 baseY;                 // 0x7A, pos_70.y の基準, openOffset を足した値が pos_70.y に入る
  u8 unk_7c[0x80 - 0x7C];    // 0x7C
  u16 openOffset;            // 0x80, 開き具合, 1フレームに 15 ずつ 0 と openMax の間を動く
  s16 timer;                 // 0x82, 開閉し終わってからスクリプトを実行するまでの残りフレーム, 30 から減る
  u8 unk_84[0x88 - 0x84];    // 0x84
  s16 openMax;               // 0x88, openOffset の上限
  u8 unk_8a[0x8C - 0x8A];    // 0x8A
} Door;
static_assert(sizeof(Door) == 140);

// '.k' の扉の絵一式を複製して入れる置き場, DoorManager_Init が Malloc(140) で7個作る
typedef struct {
  AuxSpriteGfx gfx[5];
} DoorSpriteSet;
static_assert(sizeof(DoorSpriteSet) == 140);

// AuxSpriteGfx 5枚 x 7 種類の扉グラフィックを持ち、doorMax 体ぶんの扉の実体を管理するシングルトン
// スクリプトの引数ごとに種類が対応する: 'd'=木の扉 / 'S'=鉄格子 / 'k'=鍵付き青扉1 / 'b'=鍵付き青扉2 / 's' / 'u'
typedef struct {
  Entity e;                     // 0x00, ENTITY_UNK_9
  u16 subroutineID;             // 0x18, DoorManager_Update が FUN_08230F94 の検索キーに使う
  u16 unk_1a;                   // 0x1A, DoorManager_Destroy が doors を走査する件数
  u8 unk_1c;                    // 0x1C, DoorManager_Update が unk_1e を走査する件数, 走査後 unk_1d へ移して 0 に戻す
  u8 unk_1d;                    // 0x1D, 前フレームの unk_1c
  u16 unk_1e[4];                // 0x1E, _Init が 0x24 から 0x1E へ順に 0 で埋める, _Update が unk_1c 件ぶん走査する
  u16 unk_26[4];                // 0x26, 前フレームぶんの unk_1e, FUN_0801fad8 が unk_1d 件ぶん走査する
  u16 unk_2e;                   // 0x2E, _Init が 0 を入れる
  s32 doorMax;                  // 0x30, '.m=16', doors の要素数
  s32 unk_34;                   // 0x34, '.e=1', 0 でなければ 0x410..0x428 も確保する
  ScriptRecord* records;        // 0x38, FUN_08230F94(subroutineID, &records) の出力, _Update が values[0] を命令として分岐する
  AuxSpriteGfx sprites_3c[5];   // 0x3C, '.d=SPRITE_DOOR_WOOD'
  AuxSpriteGfx sprites_c8[5];   // 0xC8, '.S=SPRITE_DOOR_IRON'
  AuxSpriteGfx sprites_154[5];  // 0x154, '.k=SPRITE_DOOR_LOCKED'
  AuxSpriteGfx sprites_1e0[5];  // 0x1E0, '.b=SPRITE_DOOR_LOCKED', sprites_26c と対で埋める, 鍵で開けた後と開ける前で2つあるのかも？
  AuxSpriteGfx sprites_26c[5];  // 0x26C, '.b=SPRITE_DOOR_7AEE'
  AuxSpriteGfx sprites_2f8[5];  // 0x2F8, '.s=SPRITE_DOOR_7AF3'
  AuxSpriteGfx sprites_384[5];  // 0x384, '.u=SPRITE_DOOR_7AF3'
  DoorSpriteSet* unk_410;       // 0x410, unk_34 が 0 でなければ Malloc(140), '.k' の絵を複製して入れる
  DoorSpriteSet* unk_414;       // 0x414
  DoorSpriteSet* unk_418;       // 0x418
  DoorSpriteSet* unk_41c;       // 0x41C
  DoorSpriteSet* unk_420;       // 0x420
  DoorSpriteSet* unk_424;       // 0x424
  DoorSpriteSet* unk_428;       // 0x428
  Door* doors;                  // 0x42C
  u8 unk_430[4];                // 0x430, 読み手も書き手も見つかっていない
} DoorManager;
static_assert(sizeof(DoorManager) == 1076);

void FUN_080206b0(Door* door);
void FUN_08020af8(Door* door);
void FUN_08020b24(Door* door);
void FUN_08020c1c(Door* door);
void FUN_08020cd8(Door* door);
void FUN_08020d10(Door* door);
s32 FUN_080dbd08(Vec3* pos, Vec3* param_2, Vec3* param_3, u32 param_4, u32 param_5, u32 param_6);
void FUN_080206b8(Door* door);
void FUN_08020734(Door* door);
void FUN_080206b4(Door* door);

const u32 u32_ARRAY_085aa9cc[12] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};  // 0x085AA9CC

const u32 u32_ARRAY_085aa9fc[24] = {3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2};  // 0x085AA9FC

const u32 u32_ARRAY_085aaa5c[12] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};  // 0x085AAA5C

const u32 u32_ARRAY_085aaa8c[12] = {0, 6, 7, 0, 1, 2, 2, 3, 4, 4, 5, 6};  // 0x085AAA8C

static inline void Door_SetPhase(Door* door, u32 phase) { door->phase = phase; }

static inline void Door_SetStep(Door* door, u32 step) {
  door->step = step;
  door->unk_3a = 0;
}

// 扉の絵の優先度と表示位置を決める (開き方向ごとに下駄を履かせる形)
// 残差4命令 (65/69): FUN_0801f7f4 と同じく, 原典は &step を ip に退避して2回そこから読むが agbcc は都度組み立てる
NON_MATCH void FUN_0801f764(Door* door) {
#ifdef NONMATCHING_C
  door->sprite.priority = u32_ARRAY_085aa9cc[door->dir * 3 + door->step];
  if (door->step == 2) {
    door->sprite.pos.x = door->pos_70.x - 40;
    door->sprite.pos.y = door->pos_70.y - 90;
    door->sprite.pos.z = door->pos_70.z - 40;
  } else if (door->step == 0 && (u8)(door->dir - 2) <= 1) {
    door->sprite.pos.x = door->pos_70.x + 80;
    door->sprite.pos.y = door->pos_70.y + 180;
    door->sprite.pos.z = door->pos_70.z + 80;
  } else {
    door->sprite.pos = door->pos_70;
  }
#else
  INCFUNC("asm/func/FUN_0801f764.inc");
#endif
}

// 扉の絵の優先度と表示位置を種類ごとに決める
// 残差1命令 (49/48): 原典は &step を ip に退避して低位レジスタを使い切るが, こちらは1本余るぶん組み立てが短い
NON_MATCH void FUN_0801f7f4(Door* door) {
#ifdef NONMATCHING_C
  door->sprite.priority = u32_ARRAY_085aa9fc[door->dir * 3 + door->step];
  if (door->dir <= 1 || door->dir == 4 || door->dir == 5) {
    door->sprite.pos = door->pos_70;
  } else {
    door->sprite.pos.x = door->pos_70.x + 40;
    door->sprite.pos.y = door->pos_70.y + 90;
    door->sprite.pos.z = door->pos_70.z + 40;
  }
#else
  INCFUNC("asm/func/FUN_0801f7f4.inc");
#endif
}

// FUN_0801f764 と同じ処理で, 優先度の表だけ別のものを引く
// 残差4命令 (65/69): FUN_0801f764 と同じ残差クラス
NON_MATCH void FUN_0801f858(Door* door) {
#ifdef NONMATCHING_C
  door->sprite.priority = u32_ARRAY_085aaa5c[door->dir * 3 + door->step];
  if (door->step == 2) {
    door->sprite.pos.x = door->pos_70.x - 40;
    door->sprite.pos.y = door->pos_70.y - 90;
    door->sprite.pos.z = door->pos_70.z - 40;
  } else if (door->step == 0 && (u8)(door->dir - 2) <= 1) {
    door->sprite.pos.x = door->pos_70.x + 80;
    door->sprite.pos.y = door->pos_70.y + 180;
    door->sprite.pos.z = door->pos_70.z + 80;
  } else {
    door->sprite.pos = door->pos_70;
  }
#else
  INCFUNC("asm/func/FUN_0801f858.inc");
#endif
}

NAKED s32 FUN_0801f8e8(DoorManager* p, u16 param_2, Vec3* param_3, u32 param_4, u8 param_5, u8 param_6, u8 param_7, u8 param_8, u16 param_9, u32 param_10, u8 param_11, unknown* param_12, u8 param_13) { INCFUNC("asm/func/FUN_0801f8e8.inc"); }

// このフレームに届いた扉のIDに含まれているか
bool32 FUN_0801faa8(DoorManager* p, u16 id) {
  s32 i;

  for (i = 0; i < p->unk_1c; i++) {
    if (p->unk_1e[i] == id) {
      return TRUE;
    }
  }
  return FALSE;
}

// 前フレームに届いた扉のIDに含まれているか
bool32 FUN_0801fad8(DoorManager* p, u16 id) {
  s32 i;

  for (i = 0; i < p->unk_1d; i++) {
    if (p->unk_26[i] == id) {
      return TRUE;
    }
  }
  return FALSE;
}

// プレイヤーの向きが扉の種類ごとに許された3方向のどれかなら FALSE
// 残差0命令 (28/28), レジスタ名だけ違う: 原典は i を r3 に置くが, こちらは r2 を取る
NON_MATCH bool32 FUN_0801fb08(Door* door, s32 param_2) {
#ifdef NONMATCHING_C
  s32 i;

  for (i = 0; i < 3; i++) {
    if (gPlayerPtr[0]->facing == u32_ARRAY_085aaa8c[door->dir * 3 + i]) {
      return FALSE;
    }
  }

  return TRUE;
#else
  INCFUNC("asm/func/FUN_0801fb08.inc");
#endif
}

NAKED s32 Cmd_D4E3(void) { INCFUNC("asm/func/Cmd_D4E3.inc"); }

// そのIDの閉じている扉を開き始めさせる
NON_MATCH void FUN_0801fc88(DoorManager* p, u16 id) {
#ifdef NONMATCHING_C
  s32 i;

  for (i = 0; i < p->unk_1a; i++) {
    Door* door = &p->doors[i];

    if (door->id == id && (door->phase == 0 || door->phase == 3) && !(door->unk_36 & 1)) {
      door->unk_41 = 1;
      Door_SetPhase(door, 2);
      door->fn = FUN_08020734;
      Door_SetStep(door, 0);
    }
  }
#else
  INCFUNC("asm/func/FUN_0801fc88.inc");
#endif
}

// 開閉中のそのIDの扉を逆方向に折り返させる
void FUN_0801fd10(DoorManager* p, u16 id) {
  s32 i;

  for (i = 0; i < p->unk_1a; i++) {
    Door* door = &p->doors[i];

    if (door->id == id && (door->phase == 1 || door->phase == 2)) {
      Door_SetPhase(door, 3);
      door->fn = FUN_080206b8;
      Door_SetStep(door, 2);
    }
  }
}

// そのIDの扉を待機状態に戻す
void FUN_0801fd88(DoorManager* p, u16 id) {
  s32 i;

  for (i = 0; i < p->unk_1a; i++) {
    Door* door = &p->doors[i];

    if (door->id == id) {
      Door_SetPhase(door, 1);
      door->fn = FUN_080206b4;
      door->step = 0;
      door->unk_3a = 0;
    }
  }
}

// そのIDの扉を開いた状態で止める
NON_MATCH void FUN_0801fdf0(DoorManager* p, u16 id) {
#ifdef NONMATCHING_C
  s32 i;

  for (i = 0; i < p->unk_1a; i++) {
    Door* door = &p->doors[i];

    if (door->id == id) {
      Door_SetPhase(door, 0);
      door->fn = FUN_080206b0;
      Door_SetStep(door, 2);
    }
  }
#else
  INCFUNC("asm/func/FUN_0801fdf0.inc");
#endif
}

// そのIDの扉に印を付ける
void FUN_0801fe58(DoorManager* p, u16 id) {
  s32 i;

  for (i = 0; i < p->unk_1a; i++) {
    Door* door = &p->doors[i];
    if (door->id == id) {
      door->unk_36 |= 1;
    }
  }
}

// そのIDの扉の印を外す
void FUN_0801fe98(DoorManager* p, u16 id) {
  s32 i;

  for (i = 0; i < p->unk_1a; i++) {
    Door* door = &p->doors[i];
    if (door->id == id) {
      door->unk_36 &= ~1;
    }
  }
}

// 0x8B67, '.n' が指す扉を開かせる, 1体でも見つかれば 1 を返す
s32 Cmd_8B67(void) {
  DoorManager* p = Registry_Find(0x85E6);
  s32 found;
  s32 id;
  s32 i;

  if (p == NULL) {
    return -1;
  }
  found = 0;
  if (!VM_SeekToNamedArg('n')) {
    return 0;
  }
  id = VM_GetValue();
  for (i = 0; i < p->unk_1a; i++) {
    Door* door = &p->doors[i];

    if (door->id == id) {
      if (VM_SeekToNamedArg('p')) {
        door->openScriptID = VM_GetValue();
      }
      if (door->phase == 1 || door->phase == 3) {
        door->phase = 2;
        door->fn = FUN_08020af8;
      }
      found = 1;
    }
  }
  return found;
}

// 0xD6F7, '.n' が指す扉を閉じさせる, 1体でも見つかれば 1 を返す
s32 Cmd_D6F7(void) {
  DoorManager* p = Registry_Find(0x85E6);
  s32 found;
  s32 id;
  s32 i;

  if (p == NULL) {
    return -1;
  }
  found = 0;
  if (!VM_SeekToNamedArg('n')) {
    return -1;
  }
  id = VM_GetValue();
  for (i = 0; i < p->unk_1a; i++) {
    Door* door = &p->doors[i];

    if (door->id == id) {
      if (VM_SeekToNamedArg('p')) {
        door->closeScriptID = VM_GetValue();
      }
      if (door->phase == 0 || door->phase == 2) {
        door->phase = 3;
        door->fn = FUN_08020b24;
      }
      found = 1;
    }
  }
  return found;
}

// '.n' が指す扉を開いた状態に戻す, 1体でも見つかれば 1 を返す
// 残差1命令 (100/101): FUN_08020c1c と同じく, 原典は末尾で &pos_70.y を作り直すが agbcc は直前の &openOffset から引いて作る
NON_MATCH s32 Cmd_612E(void) {
#ifdef NONMATCHING_C
  DoorManager* p = Registry_Find(0x85E6);
  s32 found;
  s32 id;
  s32 i;

  if (p == NULL) {
    return -1;
  }
  found = 0;
  if (!VM_SeekToNamedArg('n')) {
    return 0;
  }
  id = VM_GetValue();
  for (i = 0; i < p->unk_1a; i++) {
    Door* door = &p->doors[i];

    if (door->id == id) {
      door->timer = 0;
      door->phase = 0;
      door->fn = FUN_08020cd8;
      door->step = 0;
      door->unk_3a = 0;
      door->ov->tile.attr &= ~(TATTR_UNK_0 | TATTR_WALL);
      door->ov->tile.attr |= TATTR_WALL;
      door->ov->tile.heightStairs = (door->ov->tile.heightStairs & 0xF0) | door->tileHeight;
      door->openOffset = door->openMax;
      door->sprite.pos.y = door->openMax + door->pos_70.y;
      found = 1;
    }
  }

  return found;
#else
  INCFUNC("asm/func/Cmd_612E.inc");
#endif
}

// '.n' が指す扉を閉じた状態に戻す, 1体でも見つかれば 1 を返す
// 残差はプール定数の巻き上げ先1組のみ (97/97): 原典は ~TATTR_WALL (0xFFFD) を r10 に巻き上げて FUN_08020d10 を毎回 ldr するが, agbcc は逆を選ぶ
// Door_SetPhase / Door_SetStep 経由にすると定数 1 が巻き上がる (直書きだと 98命令), 文の順序と found の形は Cmd_D6F7 と同じで原典どおり
// Tier A-C 試済 (早期 return は 85命令で原典と別物), 未: per-TU フラグ
NON_MATCH s32 Cmd_5A36(void) {
#ifdef NONMATCHING_C
  DoorManager* p = Registry_Find(0x85E6);
  s32 found;
  s32 id;
  s32 i;

  if (p == NULL) {
    return -1;
  }
  found = 0;
  if (!VM_SeekToNamedArg('n')) {
    return -1;
  }
  id = VM_GetValue();
  for (i = 0; i < p->unk_1a; i++) {
    Door* door = &p->doors[i];

    if (door->id == id) {
      door->timer = 0;
      Door_SetPhase(door, 1);
      door->fn = FUN_08020d10;
      Door_SetStep(door, door->unk_84[0]);
      door->ov->tile.attr &= ~TATTR_WALL;
      door->ov->tile.attr |= TATTR_UNK_0 | TATTR_WALL;
      door->ov->tile.heightStairs = (door->ov->tile.heightStairs & 0xF0) | (door->tileHeight + 1);
      door->openOffset = 0;
      door->sprite.pos.y = door->pos_70.y;
      found = 1;
    }
  }

  return found;
#else
  INCFUNC("asm/func/Cmd_5A36.inc");
#endif
}

// 0xCB30, '.n' が指す扉を開き始めさせる
void Cmd_CB30(void) {
  DoorManager* p = Registry_Find(0x85E6);

  if (p != NULL && VM_SeekToNamedArg('n')) {
    s32 id = VM_GetValue();
    s32 i;

    for (i = 0; i < p->unk_1a; i++) {
      Door* door = &p->doors[i];

      if (door->id == id) {
        door->unk_41 = 1;
        p->unk_1e[p->unk_1c] = door->id;
        p->unk_1c++;
        Door_SetPhase(door, 2);
        door->fn = FUN_08020734;
        Door_SetStep(door, 0);
      }
    }
  }
}

// '.n' が1体だけ該当するとき、その扉の座標を '.p' の変数へ返す
NON_MATCH void Cmd_EAAF(void) {
#ifdef NONMATCHING_C
  DoorManager* p = Registry_Find(0x85E6);

  if (p != NULL && VM_SeekToNamedArg('n')) {
    s32 id = VM_GetValue();
    s32 i = 0;
    s32 count = 0;
    s32 found = 0;
    u8 out[8];

    for (; i < p->unk_1a; i++) {
      if (p->doors[i].id == id) {
        count++;
        found = i;
      }
    }
    if (count == 1 && VM_SeekToNamedArg('p')) {
      VM_GetMemoryRef(out);
      VM_StoreMemoryRef(out, 0, p->doors[found].sprite.pos.x);
      VM_GetMemoryRef(out);
      VM_StoreMemoryRef(out, 0, p->doors[found].sprite.pos.y);
      VM_GetMemoryRef(out);
      VM_StoreMemoryRef(out, 0, p->doors[found].sprite.pos.z);
    }
  }
#else
  INCFUNC("asm/func/Cmd_EAAF.inc");
#endif
}

void FUN_08020314(void) {
  DoorManager* p = Registry_Find(0x85E6);
  if (p != NULL && VM_SeekToNamedArg('n')) {
    p->unk_2e = VM_GetValue();
  }
}

void FUN_0802033c(void) {
  DoorManager* p = Registry_Find(0x85E6);
  if (p != NULL) {
    p->unk_2e = 0;
  }
}

// そのIDの扉が開いているか
s32 FUN_08020358(u32 id) {
  DoorManager* p = Registry_Find(0x85E6);

  s32 i;

  if (p == NULL) {
    return 0;
  }
  for (i = 0; i < p->unk_1a; i++) {
    Door* door = &p->doors[i];

    if (door->unk_40 == 2 && door->unk_3c == id) {
      return 1;
    }
  }
  return 0;
}

NAKED void FUN_080203a4(DoorManager* p, AuxSprite* sprite) { INCFUNC("asm/func/FUN_080203a4.inc"); }

// このフレームの扉IDをまだ積んでいなければ積む
void FUN_08020680(DoorManager* p) {
  if (p->unk_2e != 0 && !FUN_0801faa8(p, p->unk_2e)) {
    p->unk_1e[p->unk_1c] = p->unk_2e;
    p->unk_1c++;
  }
}

void FUN_080206b0(Door* door) {}

void FUN_080206b4(Door* door) {}

NAKED void FUN_080206b8(Door* door) { INCFUNC("asm/func/FUN_080206b8.inc"); }

NAKED void FUN_08020734(Door* door) { INCFUNC("asm/func/FUN_08020734.inc"); }

NAKED void FUN_080207b0(DoorManager* p, AuxSprite* sprite) { INCFUNC("asm/func/FUN_080207b0.inc"); }

void FUN_08020b88(Door* door);

// 扉が開き始めるときの処理
void FUN_08020af8(Door* door) {
  PlaySound_082406e0(SONG_338);
  door->step = 0;
  door->unk_3a = 0;
  Door_SetPhase(door, 2);
  door->fn = FUN_08020b88;
}

// 扉を閉める, タイルを壁に戻して高さを 1 段上げ, 閉じるアニメのハンドラへ移す
void FUN_08020b24(Door* door) {
  PlaySound_082406e0(SONG_338);
  door->step = 0;
  door->unk_3a = 0;
  door->ov->tile.attr |= TATTR_WALL;
  door->ov->tile.attr |= TATTR_UNK_0 | TATTR_WALL;
  door->phase = 3;
  door->ov->tile.heightStairs = (door->ov->tile.heightStairs & 0xF0) | (door->tileHeight + 1);
  door->ov->flags &= ~1;
  door->fn = FUN_08020c1c;
}

// 扉を開けていく, 上限まで開いたら効果音を鳴らしてタイルの壁属性を外す
void FUN_08020b88(Door* door) {
  door->openOffset += 15;
  if ((s16)door->openOffset > door->openMax) {
    door->openOffset = door->openMax;
    sound_08240740(SONG_338);
    PlaySound_082406e0(SONG_340);
    door->timer = 30;
    door->phase = 0;
    door->ov->tile.attr &= ~(TATTR_UNK_0 | TATTR_WALL);
    door->ov->tile.attr |= TATTR_WALL;
    door->ov->tile.heightStairs = (door->ov->tile.heightStairs & 0xF0) | door->tileHeight;
    door->ov->flags |= 1;
    door->fn = FUN_08020cd8;
  }

  door->pos_70.y = door->openOffset + door->baseY;
}

// 扉を閉めていく, 閉まり切ったら効果音と煙のエフェクトを出して待機状態へ移す
// 残差0命令 (84/84), 組み立て順だけ違う: 原典は末尾で &openOffset と door を作り直すが, agbcc は冒頭で作ったアドレスを使い回す
NON_MATCH void FUN_08020c1c(Door* door) {
#ifdef NONMATCHING_C
  Vec3 v;

  door->openOffset -= 15;
  if ((s16)door->openOffset < 0) {
    door->openOffset = 0;
    sound_08240740(SONG_338);
    PlaySound_082406e0(SONG_339);
    door->timer = 30;
    door->phase = 1;
    door->step = door->unk_84[0];
    door->unk_3a = 0;
    door->fn = FUN_08020d10;
    VEC3_SET(v, 0, 0, 0);
    if (door->dir & 1) {
      v.x = Q8(0.5);
      FUN_080dbd08(&door->pos_70, NULL, &v, 5, 2, 0);
    } else {
      v.z = Q8(0.5);
      FUN_080dbd08(&door->pos_70, NULL, &v, 5, 2, 0);
    }
  }

  door->pos_70.y = door->baseY + door->openOffset;
#else
  INCFUNC("asm/func/FUN_08020c1c.inc");
#endif
}

// 開閉の残りフレームを数え、終わったら予約してあったスクリプトを実行する
void FUN_08020cd8(Door* door) {
  if (door->timer != 0) {
    Camera_Shake(door->timer);
    door->timer--;
  } else if (door->openScriptID != 0) {
    VM_ExecByID(door->openScriptID, NULL);
    door->openScriptID = 0;
  }
  door->sprite.priority = 2;
}

// 開閉の残りフレームを数え、終わったら予約してあったスクリプトを実行する
void FUN_08020d10(Door* door) {
  if (door->timer != 0) {
    Camera_Shake(door->timer);
    door->timer--;
  } else if (door->closeScriptID != 0) {
    VM_ExecByID(door->closeScriptID, NULL);
    door->closeScriptID = 0;
  }
}

NAKED void FUN_08020d44(DoorManager* p, AuxSprite* sprite) { INCFUNC("asm/func/FUN_08020d44.inc"); }

void FUN_0802108c(void) {}

void FUN_08021090(void) {}

NAKED s32 DoorManager_Update(DoorManager* p) { INCFUNC("asm/func/DoorManager_Update.inc"); }

s32 DoorManager_Destroy(DoorManager* p) {
  s32 i;

  for (i = 0; i < p->unk_1a; i++) {
    Door* door = &p->doors[i];

    if (door->ov != NULL) {
      Map_RemoveTileOverride(door->ov);
      Free(door->ov);
    }
    AuxSprite_Remove(&door->sprite);
  }
  if (p->unk_34 != 0) {
    Free(p->unk_410);
    Free(p->unk_414);
    Free(p->unk_418);
    Free(p->unk_41c);
    Free(p->unk_420);
    Free(p->unk_424);
    Free(p->unk_428);
  }
  Free(p->doors);
  Registry_Remove(0x85E6);
  return 0;
}

NAKED s32 DoorManager_Init(DoorManager* p, u32 subroutineID, unknown* param_3) { INCFUNC("asm/func/DoorManager_Init.inc"); }

// 0x6D69
DoorManager* DoorManager_Create(u32 subroutineID, unknown* param_2) {
  DoorManager* p = CreateEntity(ENTITY_UNK_9, sizeof(DoorManager));

  if (p != NULL) {
    SetEntityRoutine(p, DoorManager_Update, DoorManager_Destroy);
    if (DoorManager_Init(p, subroutineID, param_2) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
