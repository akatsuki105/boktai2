#include "camera.h"
#include "coffin.h"
#include "collision_map.h"
#include "dust.h"
#include "entity.h"
#include "global.h"
#include "input.h"
#include "malloc.h"
#include "map_inline.h"
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
  u16 id;                    // 0x34, 扉のID, DoorManager_DisableByID が一致する扉に unk_36 の bit0 を立てる
  u8 unk_36;                 // 0x36, bit0: 自動の開閉判定を止める (DoorManager_DisableByID / EnableByID)
  u8 phase;                  // 0x37, 0=開ききった 1=閉じきった 2=開いている途中 3=閉じている途中
  u8 dir;                    // 0x38, 扉の向き, step と組で絵の優先度と facing の表を引く, bit0 で閉じたときの煙がずれる軸が決まる, 0x38 から 0x40 にかけては 32bit の ldr とバイト単位の strb が重なっていて境界が決まらない (u32 と u8[4] の union?)
  u8 step;                   // 0x39, 絵のコマ (0〜2), dir と組で表を引く
  u8 stepTimer;              // 0x3A, コマ送りの待ちフレーム, 8 で次のコマへ進んで 0 に戻る
  u8 tileHeight;             // 0x3B, tile.heightStairs の下位4bit に入る高さ, 閉じているときは +1 した値が入る
  u16 tileIdx;               // 0x3C, 扉が塞ぐタイルの索引, タイルの上書きを置く
  u16 frontTileIdx;          // 0x3E, 扉の手前のタイルの索引
  u8 kind;                   // 0x40, '.v', 扉の種類 (0〜16), 種類ごとに絵の作り方が分かれる, 2 のとき tileIdx で引かれる
  u8 unk_41;                 // 0x41, '.k' の2つ目, DoorManager_OpenByID が 1 を入れる
  u16 zoneID;                // 0x42, 置いた位置のゾーン
  u8 unk_44;                 // 0x44, '.m'
  u8 lockedSpriteIdx;        // 0x45, 鍵付き扉の絵の番号 (0〜7), kind から決まる
  u8 unk_46[2];              // 0x46
  s32 unk_48;                // 0x48, '.k' の1つ目, 0 でなければ unk_50 に '.k' の残りを持つ
  u32 gfxIdx;                // 0x4C, '.d', 種類ごとの絵一式 (AuxSpriteGfx[5]) の何枚目を使うか
  s32 unk_50[4];             // 0x50, '.k' の3つ目以降
  s32 openScriptID;          // 0x60, '.p', 開き終わったときに VM_ExecByID する
  s32 closeScriptID;         // 0x64, '.p', 閉じ終わったときに VM_ExecByID する
  Vec3 pos_68;               // 0x68, 置いた位置
  Vec3 pos_70;               // 0x70, 扉の絵の基準位置, Door_UpdateBarsSprite が種類ごとに下駄を履かせて sprite.pos へ入れる
  Vec3 basePos;              // 0x78, 置いた位置, y に openOffset を足した値が pos_70.y に入る
  u16 openOffset;            // 0x80, 開き具合, 1フレームに 15 ずつ 0 と openMax の間を動く
  s16 timer;                 // 0x82, 開閉し終わってからスクリプトを実行するまでの残りフレーム, 30 から減る
  s32 closedStep;            // 0x84, 閉じているときの絵のコマ (0〜2), 向きから決まる
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
  u16 mesgID;                   // 0x18, ドア管理宛てのメッセージの id, DoorManager_Create の引数
  u16 unk_1a;                   // 0x1A, DoorManager_Destroy が doors を走査する件数
  u8 nearCount;                 // 0x1C, このフレームに nearIDs に積んだ数
  u8 prevNearCount;             // 0x1D, 前フレームの nearCount
  u16 nearIDs[4];               // 0x1E, このフレームにプレイヤーか棺桶が近くにいた扉のID, 新しく入った ID の扉を開ける
  u16 prevNearIDs[4];           // 0x26, 前フレームの nearIDs, ここから外れた ID の扉を閉める
  u16 heldID;                   // 0x2E, 毎フレーム nearIDs に積んで開けたままにする扉のID, 0 なら無し
  s32 doorMax;                  // 0x30, '.m=16', doors の要素数
  s32 useLockedVariants;        // 0x34, '.e=1', 0 でなければ鍵付き扉の色違いの絵一式 (lockedSet1〜7) を作る
  ScriptMesg* mesgs;            // 0x38, ScriptMesg_Find で引いた mesgID 宛てのメッセージの先頭, _Update が values[0] を命令として分岐する
  AuxSpriteGfx sprites_3c[5];   // 0x3C, '.d=SPRITE_DOOR_WOOD'
  AuxSpriteGfx sprites_c8[5];   // 0xC8, '.S=SPRITE_IRON_BARS_7AD2'
  AuxSpriteGfx sprites_154[5];  // 0x154, '.k=SPRITE_DOOR_LOCKED'
  AuxSpriteGfx sprites_1e0[5];  // 0x1E0, '.b=SPRITE_DOOR_LOCKED', sprites_26c と対で埋める, 鍵で開けた後と開ける前で2つあるのかも？
  AuxSpriteGfx sprites_26c[5];  // 0x26C, '.b=SPRITE_DOOR_LOAN_0'
  AuxSpriteGfx sprites_2f8[5];  // 0x2F8, '.s=SPRITE_DOOR_7AF3'
  AuxSpriteGfx sprites_384[5];  // 0x384, '.u=SPRITE_DOOR_7AF3'
  DoorSpriteSet* lockedSet1;    // 0x410, '.k' の絵の複製, lockedSpriteIdx が 1 の鍵付き扉が使う
  DoorSpriteSet* lockedSet2;    // 0x414
  DoorSpriteSet* lockedSet3;    // 0x418
  DoorSpriteSet* lockedSet4;    // 0x41C
  DoorSpriteSet* lockedSet5;    // 0x420
  DoorSpriteSet* lockedSet6;    // 0x424
  DoorSpriteSet* lockedSet7;    // 0x428
  Door* doors;                  // 0x42C
  u8 unk_430[4];                // 0x430, 読み手も書き手も見つかっていない
} DoorManager;
static_assert(sizeof(DoorManager) == 1076);

void Door_IdleClosed(Door* door);
void Door_BarsStartOpen(Door* door);
void Door_BarsStartClose(Door* door);
void Door_AnimateBarsClose(Door* door);
void Door_BarsOpenedWait(Door* door);
void Door_BarsClosedWait(Door* door);
void Door_AnimateWoodClose(Door* door);
void Door_AnimateWoodOpen(Door* door);
void Door_IdleOpen(Door* door);

const u32 u32_ARRAY_085aa9cc[12] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};  // 0x085AA9CC

const u32 u32_ARRAY_085aa9fc[24] = {3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2};  // 0x085AA9FC

const u32 u32_ARRAY_085aaa5c[12] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};  // 0x085AAA5C

const u32 u32_ARRAY_085aaa8c[12] = {0, 6, 7, 0, 1, 2, 2, 3, 4, 4, 5, 6};  // 0x085AAA8C

static inline void Door_SetPhase(Door* door, u32 phase) { door->phase = phase; }

static inline void Door_SetFn(Door* door, void (*fn)(Door*)) { door->fn = fn; }

static inline void Door_SetStep(Door* door, u8 step) {
  door->step = step;
  door->stepTimer = 0;
}

// 扉の絵の優先度と表示位置を決める (開き方向ごとに下駄を履かせる形)
void Door_UpdateStepSprite(Door* door) {
  const u32* priorities = u32_ARRAY_085aa9cc;
  u8* step = &door->step;
  u8* dir = &door->dir;

  door->sprite.priority = priorities[*dir * 3 + *step];
  if (*step == 2) {
    door->sprite.pos.x = door->pos_70.x - 40;
    door->sprite.pos.y = door->pos_70.y - 90;
    door->sprite.pos.z = door->pos_70.z - 40;
  } else if (*step == 0 && (*dir == 2 || *dir == 3)) {
    door->sprite.pos.x = door->pos_70.x + 80;
    door->sprite.pos.y = door->pos_70.y + 180;
    door->sprite.pos.z = door->pos_70.z + 80;
  } else {
    door->sprite.pos = door->pos_70;
  }
}

// 扉の絵の優先度と表示位置を種類ごとに決める
// 残差1命令 (49/48): 原典は &step を ip に退避して低位レジスタを使い切るが, こちらは1本余るぶん組み立てが短い
// Door_UpdateStepSprite で一致した形 (表をローカルに取り &step / &dir をポインタで持つ) は, ここでは door が ip に回って 49/48 のまま
NON_MATCH void Door_UpdateBarsSprite(Door* door) {
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
  INCFUNC("asm/func/Door_UpdateBarsSprite.inc");
#endif
}

// Door_UpdateStepSprite と同じ処理で, 優先度の表だけ別のものを引く
void Door_UpdateLockedStepSprite(Door* door) {
  const u32* priorities = u32_ARRAY_085aaa5c;
  u8* step = &door->step;
  u8* dir = &door->dir;

  door->sprite.priority = priorities[*dir * 3 + *step];
  if (*step == 2) {
    door->sprite.pos.x = door->pos_70.x - 40;
    door->sprite.pos.y = door->pos_70.y - 90;
    door->sprite.pos.z = door->pos_70.z - 40;
  } else if (*step == 0 && (*dir == 2 || *dir == 3)) {
    door->sprite.pos.x = door->pos_70.x + 80;
    door->sprite.pos.y = door->pos_70.y + 180;
    door->sprite.pos.z = door->pos_70.z + 80;
  } else {
    door->sprite.pos = door->pos_70;
  }
}

void Map_GetZoneMin(u16 id, u16* out);

void Door_SetupStepAnim(DoorManager* p, Door* door);
void Door_SetupBars(DoorManager* p, Door* door);
void Door_SetupLocked(DoorManager* p, Door* door);

// 空いている枠に扉を1つ置き, 種類に合わせて絵とタイルの上書きを作る
s32 DoorManager_AddDoor(DoorManager* p, u16 id, Vec3* pos, u32 d, u8 f, u8 phase, u8 dir, s32 kind, s32 openMax, u32 k0, s32 k1, s32* keys, u8 m) {
  Door* door;

  if (p->unk_1a >= p->doorMax) {
    return -1;
  }

  door = &p->doors[p->unk_1a];
  door->id = id;
  door->pos_68 = *pos;
  door->basePos = *pos;
  door->unk_36 = f;
  door->phase = phase;
  door->dir = dir;
  door->stepTimer = 0;
  door->kind = kind;
  door->openMax = openMax;
  door->unk_48 = k0;
  door->unk_41 = k1;
  door->gfxIdx = d;
  door->openOffset = 0;
  door->zoneID = GetZoneAt(pos);
  door->unk_44 = m;
  door->ov = Malloc(16);
  if (door->ov == NULL) {
    return -1;
  }
  ClearMemory(door->ov, 16);

  switch (door->kind) {
    case 1: {
      Door_SetupBars(p, door);
      break;
    }
    case 2: {
      door->lockedSpriteIdx = 0;
      Door_SetupLocked(p, door);
      break;
    }
    case 8: {
      door->lockedSpriteIdx = 1;
      Door_SetupLocked(p, door);
      break;
    }
    case 9: {
      door->lockedSpriteIdx = 2;
      Door_SetupLocked(p, door);
      break;
    }
    case 10: {
      door->lockedSpriteIdx = 3;
      Door_SetupLocked(p, door);
      break;
    }
    case 11: {
      door->lockedSpriteIdx = 4;
      Door_SetupLocked(p, door);
      break;
    }
    case 12: {
      door->lockedSpriteIdx = 5;
      Door_SetupLocked(p, door);
      break;
    }
    case 13: {
      door->lockedSpriteIdx = 6;
      Door_SetupLocked(p, door);
      break;
    }
    case 14: {
      door->lockedSpriteIdx = 7;
      Door_SetupLocked(p, door);
      break;
    }
    case 0:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 15: {
      Door_SetupStepAnim(p, door);
      break;
    }
    case 16: {
      Door_SetupLocked(p, door);
      break;
    }
  }

  if (door->unk_48 != 0) {
    s32 i;

    for (i = 0; i < 4; i++) {
      door->unk_50[i] = keys[i];
    }
  } else {
    door->unk_50[0] = 0;
  }
  p->unk_1a++;
}

// このフレームに届いた扉のIDに含まれているか
bool32 DoorManager_IsNearID(DoorManager* p, u16 id) {
  s32 i;

  for (i = 0; i < p->nearCount; i++) {
    if (p->nearIDs[i] == id) {
      return TRUE;
    }
  }
  return FALSE;
}

// 前フレームに届いた扉のIDに含まれているか
bool32 DoorManager_WasNearID(DoorManager* p, u16 id) {
  s32 i;

  for (i = 0; i < p->prevNearCount; i++) {
    if (p->prevNearIDs[i] == id) {
      return TRUE;
    }
  }
  return FALSE;
}

// プレイヤーの向きが扉の種類ごとに許された3方向のどれかなら FALSE
bool32 Door_IsPlayerFacingAway(DoorManager* p, Door* door) {
  s32 i = 0;
  u8 facing = gPlayerPtr[0]->facing;

  for (; i < 3; i++) {
    if (facing == u32_ARRAY_085aaa8c[door->dir * 3 + i]) {
      return FALSE;
    }
  }

  return TRUE;
}

// 0xD4E3, 名前付き引数で扉を1つ置く, 位置は '.t' のゾーンの角か '.p' の座標
s32 Cmd_AddDoor(void) {
  DoorManager* p = Registry_Find(0x85E6);
  u16 id;
  s32 d;
  u8 f, s, r;
  s32 v, h;
  u8 m;
  s32 k0, k1;
  s32 keys[4];
  Vec3 pos;

  if (p == NULL) {
    return -1;
  }

  id = VM_GetNamedArgValue('n', 0);
  d = VM_GetNamedArgValue('d', 0);
  f = VM_GetNamedArgValue('f', 0);
  s = VM_GetNamedArgValue('s', 0);
  r = VM_GetNamedArgValue('r', 0);
  v = VM_GetNamedArgValue('v', 0);
  h = VM_GetNamedArgValue('h', 400);
  m = VM_GetNamedArgValue('m', 0);
  if (VM_SeekToNamedArg('k')) {
    s32 i;

    k0 = VM_GetValue();
    k1 = VM_GetValue();
    for (i = 0; i < 4; i++) {
      keys[i] = VM_GetValue();
    }
  } else {
    k0 = 0;
    k1 = 0;
  }

  if (VM_SeekToNamedArg('t')) {
    Map_GetZoneMin(VM_GetValue(), (u16*)&pos);
  } else if (VM_SeekToNamedArg('p')) {
    pos.x = VM_GetValue();
    pos.y = VM_GetValue();
    pos.z = VM_GetValue();
  } else {
    pos.x = 0;
    pos.y = 0;
    pos.z = 0;
  }

  return DoorManager_AddDoor(p, id, &pos, d, f, s, r, v, h, k0, k1, keys, m);
}

// そのIDの閉じている扉を開き始めさせる
NON_MATCH void DoorManager_OpenByID(DoorManager* p, u16 id) {
#ifdef NONMATCHING_C
  s32 i;

  for (i = 0; i < p->unk_1a; i++) {
    Door* door = &p->doors[i];

    if (door->id == id && (door->phase == 0 || door->phase == 3) && !(door->unk_36 & 1)) {
      door->unk_41 = 1;
      Door_SetPhase(door, 2);
      door->fn = Door_AnimateWoodOpen;
      Door_SetStep(door, 0);
    }
  }
#else
  INCFUNC("asm/func/DoorManager_OpenByID.inc");
#endif
}

// 開閉中のそのIDの扉を逆方向に折り返させる
void DoorManager_CloseByID(DoorManager* p, u16 id) {
  s32 i;

  for (i = 0; i < p->unk_1a; i++) {
    Door* door = &p->doors[i];

    if (door->id == id && (door->phase == 1 || door->phase == 2)) {
      Door_SetPhase(door, 3);
      door->fn = Door_AnimateWoodClose;
      Door_SetStep(door, 2);
    }
  }
}

// そのIDの扉を動かさずに開いた状態にする
void DoorManager_SetOpenByID(DoorManager* p, u16 id) {
  s32 i;

  for (i = 0; i < p->unk_1a; i++) {
    Door* door = &p->doors[i];

    if (door->id == id) {
      Door_SetPhase(door, 1);
      door->fn = Door_IdleOpen;
      door->step = 0;
      door->stepTimer = 0;
    }
  }
}

// そのIDの扉を動かさずに閉じた状態にする
void DoorManager_SetClosedByID(DoorManager* p, u16 id) {
  s32 i;

  for (i = 0; i < p->unk_1a; i++) {
    Door* door = &p->doors[i];

    if (door->id == id) {
      Door_SetPhase(door, 0);
      Door_SetFn(door, Door_IdleClosed);
      Door_SetStep(door, 2);
    }
  }
}

// そのIDの扉に印を付ける
void DoorManager_DisableByID(DoorManager* p, u16 id) {
  s32 i;

  for (i = 0; i < p->unk_1a; i++) {
    Door* door = &p->doors[i];
    if (door->id == id) {
      door->unk_36 |= 1;
    }
  }
}

// そのIDの扉の印を外す
void DoorManager_EnableByID(DoorManager* p, u16 id) {
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
        door->fn = Door_BarsStartOpen;
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
        door->fn = Door_BarsStartClose;
      }
      found = 1;
    }
  }
  return found;
}

// '.n' が指す扉を開いた状態に戻す, 1体でも見つかれば 1 を返す
s32 Cmd_SetDoorOpen(void) {
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
      door->fn = Door_BarsOpenedWait;
      door->step = 0;
      door->stepTimer = 0;
      door->ov->tile.attr &= ~(TATTR_UNK_0 | TATTR_WALL);
      door->ov->tile.attr |= TATTR_WALL;
      door->ov->tile.heightStairs = (door->ov->tile.heightStairs & 0xF0) | door->tileHeight;
      door->openOffset = door->openMax;
      door->sprite.pos.y = door->pos_70.y + door->openMax;
      found = 1;
    }
  }

  return found;
}

// '.n' が指す扉を閉じた状態に戻す, 1体でも見つかれば 1 を返す
// 残差はプール定数の巻き上げ先1組のみ (97/97): 原典は ~TATTR_WALL (0xFFFD) を r10 に巻き上げて Door_BarsClosedWait を毎回 ldr するが, agbcc は逆を選ぶ
// Door_SetPhase / Door_SetStep 経由にすると定数 1 が巻き上がる (直書きだと 98命令), 文の順序と found の形は Cmd_D6F7 と同じで原典どおり
// Tier A-C 試済 (早期 return は 85命令で原典と別物), 未: per-TU フラグ
NON_MATCH s32 Cmd_SetDoorClosed(void) {
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
      door->fn = Door_BarsClosedWait;
      Door_SetStep(door, door->closedStep);
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
  INCFUNC("asm/func/Cmd_SetDoorClosed.inc");
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
        p->nearIDs[p->nearCount] = door->id;
        p->nearCount++;
        Door_SetPhase(door, 2);
        door->fn = Door_AnimateWoodOpen;
        Door_SetStep(door, 0);
      }
    }
  }
}

// '.n' が1体だけ該当するとき、その扉の座標を '.p' の変数へ返す
void Cmd_GetDoorPos(void) {
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
    if (count == 0) {
      return;
    }
    if (count > 1) {
      return;
    }
    if (VM_SeekToNamedArg('p')) {
      VM_GetMemoryRef(out);
      VM_StoreMemoryRef(out, 0, p->doors[found].sprite.pos.x);
      VM_GetMemoryRef(out);
      VM_StoreMemoryRef(out, 0, p->doors[found].sprite.pos.y);
      VM_GetMemoryRef(out);
      VM_StoreMemoryRef(out, 0, p->doors[found].sprite.pos.z);
    }
  }
}

void FUN_08020314(void) {
  DoorManager* p = Registry_Find(0x85E6);
  if (p != NULL && VM_SeekToNamedArg('n')) {
    p->heldID = VM_GetValue();
  }
}

void FUN_0802033c(void) {
  DoorManager* p = Registry_Find(0x85E6);
  if (p != NULL) {
    p->heldID = 0;
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

    if (door->kind == 2 && door->tileIdx == id) {
      return 1;
    }
  }
  return 0;
}

// 開き戸 (kind 0 系) の絵とタイルの上書きを作り, 開閉の状態に合わせて手順とタイル属性を決める
void Door_SetupStepAnim(DoorManager* p, Door* door) {
  s32 idx = GetCollisionTileIdx(&door->pos_68);
  CollisionMapTile* tile;
  AuxSprite* sprite;

  switch (door->dir) {
    case 0: {
      door->tileIdx = idx - 1;
      door->frontTileIdx = idx;
      door->pos_68.z += 128;
      break;
    }
    case 1: {
      door->tileIdx = idx - gCollisionMap->tiledata->width;
      door->frontTileIdx = idx;
      door->pos_68.x += 128;
      break;
    }
    case 2: {
      door->tileIdx = idx;
      door->frontTileIdx = idx - 1;
      door->pos_68.z += 128;
      break;
    }
    case 3: {
      door->tileIdx = idx;
      door->frontTileIdx = idx - gCollisionMap->tiledata->width;
      door->pos_68.x += 128;
      break;
    }
  }

  tile = TileAtIndex(door->tileIdx);
  door->tileHeight = tile->heightStairs & 0xF;
  Map_AddTileOverride(door->ov, door->tileIdx, 0, door->tileHeight, 0xFF, 0);

  sprite = &door->sprite;
  switch (door->kind) {
    case 0:
    case 3: {
      AuxSprite_Add(sprite, &p->sprites_3c[door->gfxIdx], 0);
      break;
    }
    case 4: {
      AuxSprite_Add(sprite, &p->sprites_1e0[door->gfxIdx], 0);
      break;
    }
    case 5: {
      AuxSprite_Add(sprite, &p->sprites_26c[door->gfxIdx], 0);
      Video_SetAuxSpritePltt(&p->sprites_26c[door->gfxIdx], 43);
      break;
    }
    case 6:
    case 7: {
      AuxSprite_Add(sprite, &p->sprites_2f8[door->gfxIdx], 0);
      break;
    }
    case 15: {
      AuxSprite_Add(sprite, &p->sprites_384[door->gfxIdx], 0);
      break;
    }
  }

  sprite->pos = door->basePos;
  if (!(door->dir & 1)) {
    sprite->pos.x -= 32;
    sprite->pos.z += 32;
  } else {
    sprite->pos.x += 32;
    sprite->pos.z -= 32;
    sprite->flags |= SPRFLAG_XFLIP;
  }
  door->pos_70 = sprite->pos;

  if (door->phase == 0) {
    door->fn = Door_IdleClosed;
    Door_SetStep(door, 0);
  } else if (door->phase == 1) {
    door->fn = Door_IdleOpen;
    Door_SetStep(door, 2);
  } else {
    door->fn = Door_IdleClosed;
    door->step = 0;
    door->stepTimer = 0;
  }

  if (door->phase == 0) {
    door->ov->tile.attr &= ~TATTR_WALL;
    door->ov->tile.attr |= TATTR_UNK_0 | TATTR_WALL;
    door->ov->tile.heightStairs = (door->ov->tile.heightStairs & 0xF0) | (door->tileHeight + 1);
  } else if (door->phase == 1) {
    door->ov->tile.attr &= ~(TATTR_UNK_0 | TATTR_WALL);
    door->ov->tile.attr |= TATTR_WALL;
    door->ov->tile.heightStairs = (door->ov->tile.heightStairs & 0xF0) | door->tileHeight;
  }
}

// このフレームの扉IDをまだ積んでいなければ積む
void DoorManager_PushHeldID(DoorManager* p, Door* door) {
  if (p->heldID != 0 && !DoorManager_IsNearID(p, p->heldID)) {
    p->nearIDs[p->nearCount] = p->heldID;
    p->nearCount++;
  }
}

void Door_IdleClosed(Door* door) {}

void Door_IdleOpen(Door* door) {}

// 木の扉が閉まるコマ送りを進め, 閉じきったらタイルを壁に戻して高さを 1 段上げる
void Door_AnimateWoodClose(Door* door) {
  if (door->step == 2 && door->stepTimer == 0) {
    PlaySound_0824078c(SE_WOOD_DOOR_CLOSE);
  }

  door->stepTimer++;
  if (door->stepTimer > 7) {
    door->step--;
    door->stepTimer = 0;
    if (door->step == 0) {
      door->phase = 0;
      door->ov->tile.attr |= TATTR_WALL;
      door->ov->tile.attr |= TATTR_UNK_0 | TATTR_WALL;
      door->ov->tile.heightStairs = (door->ov->tile.heightStairs & 0xF0) | (door->tileHeight + 1);
      door->fn = Door_IdleClosed;
    }
  }
}

// 木の扉が開くコマ送りを進める, 開き始めにタイルの壁属性を外して高さを戻す
void Door_AnimateWoodOpen(Door* door) {
  if (door->step == 0 && door->stepTimer == 0) {
    PlaySound_0824078c(SE_WOOD_DOOR_OPEN);
    door->ov->tile.attr &= ~(TATTR_UNK_0 | TATTR_WALL);
    door->ov->tile.attr |= TATTR_WALL;
    door->ov->tile.heightStairs = (door->ov->tile.heightStairs & 0xF0) | door->tileHeight;
  }

  door->stepTimer++;
  if (door->stepTimer > 7) {
    door->step++;
    door->stepTimer = 0;
    if (door->step > 1) {
      Door_SetPhase(door, 1);
      door->fn = Door_IdleOpen;
    }
  }
}

void Door_BarsOpenedWait(Door* door);
void Door_BarsClosedWait(Door* door);

// 鉄格子 (kind 1) の絵とタイルの上書きを作り, 開閉の状態を入れ替えて開き具合と手順を決める
void Door_SetupBars(DoorManager* p, Door* door) {
  s32 idx = GetCollisionTileIdx(&door->pos_68);
  CollisionMapTile* tile;
  AuxSprite* sprite;

  switch (door->dir) {
    case 0: {
      door->tileIdx = idx - 1;
      door->frontTileIdx = idx;
      door->pos_68.z += 128;
      door->closedStep = 1;
      break;
    }
    case 1: {
      door->tileIdx = idx - gCollisionMap->tiledata->width;
      door->frontTileIdx = idx;
      door->pos_68.x += 128;
      door->closedStep = 1;
      break;
    }
    case 2: {
      door->tileIdx = idx;
      door->frontTileIdx = idx - 1;
      door->pos_68.z += 128;
      door->closedStep = 2;
      break;
    }
    case 3: {
      door->tileIdx = idx;
      door->frontTileIdx = idx - gCollisionMap->tiledata->width;
      door->pos_68.x += 128;
      door->closedStep = 2;
      break;
    }
    case 4: {
      door->tileIdx = idx - 1;
      door->frontTileIdx = idx;
      door->pos_68.z += 128;
      door->closedStep = 0;
      break;
    }
    case 5: {
      door->tileIdx = idx - gCollisionMap->tiledata->width;
      door->frontTileIdx = idx;
      door->pos_68.x += 128;
      door->closedStep = 0;
      break;
    }
    case 6: {
      door->tileIdx = idx;
      door->frontTileIdx = idx - 1;
      door->pos_68.z += 128;
      door->closedStep = 1;
      break;
    }
    case 7: {
      door->tileIdx = idx;
      door->frontTileIdx = idx - gCollisionMap->tiledata->width;
      door->pos_68.x += 128;
      door->closedStep = 1;
      break;
    }
    case 8: {
      door->tileIdx = idx;
      door->frontTileIdx = idx - 1;
      door->pos_68.z += 128;
      door->closedStep = 0;
      break;
    }
    case 9: {
      door->tileIdx = idx;
      door->frontTileIdx = idx - gCollisionMap->tiledata->width;
      door->pos_68.x += 128;
      door->closedStep = 0;
      break;
    }
  }

  tile = TileAtIndex(door->tileIdx);
  door->tileHeight = tile->heightStairs & 0xF;
  Map_AddTileOverride(door->ov, door->tileIdx, 0, door->tileHeight, 0xFF, 0);
  Door_SetStep(door, door->closedStep);

  sprite = &door->sprite;
  AuxSprite_Add(sprite, &p->sprites_c8[door->gfxIdx], 0);
  sprite->pos = door->basePos;
  if (!(door->dir & 1)) {
    sprite->pos.z += 128;
  } else {
    sprite->pos.x += 128;
    sprite->flags |= SPRFLAG_XFLIP;
  }
  door->pos_70 = sprite->pos;

  if (door->phase == 0) {
    door->fn = Door_BarsClosedWait;
  } else if (door->phase == 1) {
    door->fn = Door_BarsOpenedWait;
  } else {
    door->fn = Door_BarsClosedWait;
  }

  if (door->phase == 0) {
    door->timer = 0;
    door->phase = 1;
    door->fn = Door_BarsClosedWait;
    Door_SetStep(door, door->closedStep);
    door->ov->tile.attr &= ~TATTR_WALL;
    door->ov->tile.attr |= TATTR_UNK_0 | TATTR_WALL;
    door->ov->flags &= ~1;
    door->ov->tile.heightStairs = (door->ov->tile.heightStairs & 0xF0) | (door->tileHeight + 1);
    door->openOffset = 0;
    door->pos_70.y = door->basePos.y + door->openOffset;
  } else if (door->phase == 1) {
    door->timer = 0;
    door->phase = 0;
    door->fn = Door_BarsOpenedWait;
    Door_SetStep(door, 0);
    door->ov->tile.attr &= ~(TATTR_UNK_0 | TATTR_WALL);
    door->ov->tile.attr |= TATTR_WALL;
    door->ov->flags |= 1;
    door->ov->tile.heightStairs = (door->ov->tile.heightStairs & 0xF0) | door->tileHeight;
    door->openOffset = door->openMax;
    door->pos_70.y = door->basePos.y + door->openMax;
  }

  door->openScriptID = 0;
  door->closeScriptID = 0;
  DustManager_Create(0, 0);
}

void Door_AnimateBarsOpen(Door* door);

// 扉が開き始めるときの処理
void Door_BarsStartOpen(Door* door) {
  PlaySound_082406e0(SONG_338);
  door->step = 0;
  door->stepTimer = 0;
  Door_SetPhase(door, 2);
  door->fn = Door_AnimateBarsOpen;
}

// 扉を閉める, タイルを壁に戻して高さを 1 段上げ, 閉じるアニメのハンドラへ移す
void Door_BarsStartClose(Door* door) {
  PlaySound_082406e0(SONG_338);
  door->step = 0;
  door->stepTimer = 0;
  door->ov->tile.attr |= TATTR_WALL;
  door->ov->tile.attr |= TATTR_UNK_0 | TATTR_WALL;
  door->phase = 3;
  door->ov->tile.heightStairs = (door->ov->tile.heightStairs & 0xF0) | (door->tileHeight + 1);
  door->ov->flags &= ~1;
  door->fn = Door_AnimateBarsClose;
}

// 扉を開けていく, 上限まで開いたら効果音を鳴らしてタイルの壁属性を外す
void Door_AnimateBarsOpen(Door* door) {
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
    door->fn = Door_BarsOpenedWait;
  }

  door->pos_70.y = door->openOffset + door->basePos.y;
}

// 扉を閉めていく, 閉まり切ったら効果音と煙のエフェクトを出して待機状態へ移す
void Door_AnimateBarsClose(Door* door) {
  Vec3 v;

  door->openOffset -= 15;
  if ((s16)door->openOffset < 0) {
    door->openOffset = 0;
    sound_08240740(SONG_338);
    PlaySound_082406e0(SONG_339);
    door->timer = 30;
    Door_SetPhase(door, 1);
    Door_SetStep(door, door->closedStep);
    door->fn = Door_BarsClosedWait;
    v.z = 0, v.x = 0, v.y = 0;
    if (door->dir & 1) {
      v.x = Q8(0.5);
      DustManager_SpawnNoPause(&door->pos_70, NULL, &v, 5, 2, 0);
    } else {
      v.z = Q8(0.5);
      DustManager_SpawnNoPause(&door->pos_70, NULL, &v, 5, 2, 0);
    }
  }

  door->pos_70.y = door->openOffset + door->basePos.y;
}

// 開閉の残りフレームを数え、終わったら予約してあったスクリプトを実行する
void Door_BarsOpenedWait(Door* door) {
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
void Door_BarsClosedWait(Door* door) {
  if (door->timer != 0) {
    Camera_Shake(door->timer);
    door->timer--;
  } else if (door->closeScriptID != 0) {
    VM_ExecByID(door->closeScriptID, NULL);
    door->closeScriptID = 0;
  }
}

void Door_IdleLockedClosed(Door* door);
void Door_IdleLockedOpen(Door* door);

// 鍵付き扉 (kind 2, 8〜16) の絵とタイルの上書きを作り, 開閉の状態に合わせて手順とタイル属性を決める
void Door_SetupLocked(DoorManager* p, Door* door) {
  s32 idx = GetCollisionTileIdx(&door->pos_68);
  CollisionMapTile* tile;
  AuxSprite* sprite;

  switch (door->dir) {
    case 0: {
      door->tileIdx = idx - 1;
      door->frontTileIdx = idx;
      door->pos_68.z += 128;
      break;
    }
    case 1: {
      door->tileIdx = idx - gCollisionMap->tiledata->width;
      door->frontTileIdx = idx;
      door->pos_68.x += 128;
      break;
    }
    case 2: {
      door->tileIdx = idx;
      door->frontTileIdx = idx - 1;
      door->pos_68.z += 128;
      break;
    }
    case 3: {
      door->tileIdx = idx;
      door->frontTileIdx = idx - gCollisionMap->tiledata->width;
      door->pos_68.x += 128;
      break;
    }
  }

  tile = TileAtIndex(door->tileIdx);
  door->tileHeight = tile->heightStairs & 0xF;
  Map_AddTileOverride(door->ov, door->tileIdx, 0, door->tileHeight, 0xFF, 0);

  sprite = &door->sprite;
  if (p->useLockedVariants == 0) {
    switch (door->kind) {
      case 2: {
        Video_SetAuxSpritePltt(&p->sprites_154[door->gfxIdx], 167);
        AuxSprite_Add(sprite, &p->sprites_154[door->gfxIdx], 0);
        break;
      }
      case 16: {
        AuxSprite_Add(sprite, &p->sprites_1e0[door->gfxIdx], 0);
        break;
      }
    }
  } else {
    switch (door->lockedSpriteIdx) {
      case 0: {
        Video_SetAuxSpritePltt(&p->sprites_154[door->gfxIdx], door->lockedSpriteIdx + 167);
        AuxSprite_Add(sprite, &p->sprites_154[door->gfxIdx], 0);
        break;
      }
      case 1: {
        Video_SetAuxSpritePltt(&p->lockedSet1->gfx[door->gfxIdx], door->lockedSpriteIdx + 167);
        AuxSprite_Add(sprite, &p->lockedSet1->gfx[door->gfxIdx], 0);
        break;
      }
      case 2: {
        Video_SetAuxSpritePltt(&p->lockedSet2->gfx[door->gfxIdx], door->lockedSpriteIdx + 167);
        AuxSprite_Add(sprite, &p->lockedSet2->gfx[door->gfxIdx], 0);
        break;
      }
      case 3: {
        Video_SetAuxSpritePltt(&p->lockedSet3->gfx[door->gfxIdx], door->lockedSpriteIdx + 167);
        AuxSprite_Add(sprite, &p->lockedSet3->gfx[door->gfxIdx], 0);
        break;
      }
      case 4: {
        Video_SetAuxSpritePltt(&p->lockedSet4->gfx[door->gfxIdx], door->lockedSpriteIdx + 167);
        AuxSprite_Add(sprite, &p->lockedSet4->gfx[door->gfxIdx], 0);
        break;
      }
      case 5: {
        Video_SetAuxSpritePltt(&p->lockedSet5->gfx[door->gfxIdx], door->lockedSpriteIdx + 167);
        AuxSprite_Add(sprite, &p->lockedSet5->gfx[door->gfxIdx], 0);
        break;
      }
      case 6: {
        Video_SetAuxSpritePltt(&p->lockedSet6->gfx[door->gfxIdx], door->lockedSpriteIdx + 167);
        AuxSprite_Add(sprite, &p->lockedSet6->gfx[door->gfxIdx], 0);
        break;
      }
      case 7: {
        Video_SetAuxSpritePltt(&p->lockedSet7->gfx[door->gfxIdx], door->lockedSpriteIdx + 167);
        AuxSprite_Add(sprite, &p->lockedSet7->gfx[door->gfxIdx], 0);
        break;
      }
    }
  }

  sprite->pos = door->basePos;
  if (!(door->dir & 1)) {
    sprite->pos.x -= 32;
    sprite->pos.z += 32;
  } else {
    sprite->pos.x += 32;
    sprite->pos.z -= 32;
    sprite->flags |= SPRFLAG_XFLIP;
  }
  door->pos_70 = sprite->pos;

  if (door->phase == 0) {
    door->fn = Door_IdleLockedClosed;
    Door_SetStep(door, 0);
  } else if (door->phase == 1) {
    door->fn = Door_IdleLockedOpen;
    Door_SetStep(door, 2);
  } else {
    door->fn = Door_IdleLockedClosed;
    door->step = 0;
    door->stepTimer = 0;
  }

  if (door->phase == 0) {
    door->ov->tile.attr &= ~TATTR_WALL;
    door->ov->tile.attr |= TATTR_UNK_0 | TATTR_WALL;
    door->ov->tile.heightStairs = (door->ov->tile.heightStairs & 0xF0) | (door->tileHeight + 1);
  } else if (door->phase == 1) {
    door->ov->tile.attr &= ~(TATTR_UNK_0 | TATTR_WALL);
    door->ov->tile.attr |= TATTR_WALL;
    door->ov->tile.heightStairs = (door->ov->tile.heightStairs & 0xF0) | door->tileHeight;
  }
}

void Door_IdleLockedClosed(Door* door) {}

void Door_IdleLockedOpen(Door* door) {}

static inline bool8 IsCurrentZone(u32 zoneID) {
  if (gStat->zoneID == zoneID) return TRUE;
  return FALSE;
}

// 自動で開く扉, プレイヤーか棺桶が近くにいればIDを積む
static inline void Door_UpdateAuto(DoorManager* p, Door* door) {
  WorldPos v;

  if (door->unk_36 & 1) {
    return;
  }
  Door_UpdateStepSprite(door);
  {
    Vec3 d = door->pos_68;

    d.x -= gStat->playerX;
    d.y -= gStat->playerY;
    d.z -= gStat->playerZ;
    if (d.x * d.x + d.z * d.z < 77000 && abs(d.y) < 255 && !DoorManager_IsNearID(p, door->id)) {
      p->nearIDs[p->nearCount] = door->id;
      p->nearCount++;
    }
  }
  DoorManager_PushHeldID(p, door);
  if (!Coffin_CopyPos(&v)) {
    return;
  }
  {
    Vec3 d = door->pos_68;

    d.x -= v.x;
    d.y -= v.y;
    d.z -= v.z;
    if (d.x * d.x + d.z * d.z < 77000 && abs(d.y) < 255 && !DoorManager_IsNearID(p, door->id)) {
      p->nearIDs[p->nearCount] = door->id;
      p->nearCount++;
    }
  }
}

// 鍵付きの扉, 開いていなければ A で '.k' のスクリプトを呼ぶ
static inline void Door_UpdateLocked(DoorManager* p, Door* door) {
  WorldPos v;

  if (door->unk_36 & 1) {
    return;
  }
  Door_UpdateLockedStepSprite(door);
  {
    Vec3 d = door->pos_68;

    d.x -= gStat->playerX;
    d.y -= gStat->playerY;
    d.z -= gStat->playerZ;
    if (d.x * d.x + d.z * d.z < 77000 && abs(d.y) < 255 && !DoorManager_IsNearID(p, door->id)) {
      if (door->unk_41 == 0) {
        if ((gInput[0].pressed & A_BUTTON) && !Door_IsPlayerFacingAway(p, door) && door->unk_48 != 0) {
          ScriptArgs args;

          args.argc = 4;
          args.argv = (u32*)door->unk_50;
          VM_ExecByID(door->unk_48, &args);
        }
      } else {
        p->nearIDs[p->nearCount] = door->id;
        p->nearCount++;
      }
    }
  }
  if (!Coffin_CopyPos(&v)) {
    return;
  }
  {
    Vec3 d = door->pos_68;

    d.x -= v.x;
    d.y -= v.y;
    d.z -= v.z;
    if (d.x * d.x + d.z * d.z < 77000 && abs(d.y) < 255 && !DoorManager_IsNearID(p, door->id) && door->unk_41 != 0) {
      p->nearIDs[p->nearCount] = door->id;
      p->nearCount++;
    }
  }
}

s32 DoorManager_Update(DoorManager* p) {
  s32 i;
  s32 n;
  ScriptMesg* mesg;

  if (p->unk_1a == 0) {
    return 0;
  }

  for (i = 0; i < p->nearCount; i++) {
    p->prevNearIDs[i] = p->nearIDs[i];
  }
  p->prevNearCount = p->nearCount;
  p->nearCount = 0;

  n = ScriptMesg_Find(p->mesgID, &p->mesgs);
  mesg = p->mesgs;
  while (n-- > 0) {
    switch (mesg->values[0]) {
      case 0: {
        DoorManager_OpenByID(p, mesg->values[1]);
        break;
      }
      case 1: {
        DoorManager_CloseByID(p, mesg->values[1]);
        break;
      }
      case 2: {
        DoorManager_SetOpenByID(p, mesg->values[1]);
        break;
      }
      case 3: {
        DoorManager_SetClosedByID(p, mesg->values[1]);
        break;
      }
      case 4: {
        DoorManager_DisableByID(p, mesg->values[1]);
        break;
      }
      case 5: {
        DoorManager_EnableByID(p, mesg->values[1]);
        break;
      }
    }
    mesg++;
  }

  {
    WorldPos pos;

    pos.x = PLAYER_X;
    pos.y = 0;
    pos.z = PLAYER_Z;
    GetCollisionTileIdx(&pos);
  }

  for (i = 0; i < p->unk_1a; i++) {
    Door* door = &p->doors[i];

    door->sprite.poseIdx = door->step;
    if (door->unk_44 != 0) {
      if (IsCurrentZone(door->zoneID)) {
        door->sprite.flags &= ~SPRFLAG_HIDDEN;
      } else {
        door->sprite.flags |= SPRFLAG_HIDDEN;
      }
    }

    switch (door->kind) {
      case 0: {
        Door_UpdateAuto(p, door);
        break;
      }
      case 1: {
        Door_UpdateBarsSprite(door);
        break;
      }
      case 2:
      case 8:
      case 9:
      case 10:
      case 11:
      case 12:
      case 13:
      case 14: {
        Door_UpdateLocked(p, door);
        break;
      }
      case 4: {
        Door_UpdateAuto(p, door);
        break;
      }
      case 5: {
        Door_UpdateAuto(p, door);
        break;
      }
      case 6: {
        Door_UpdateAuto(p, door);
        // break が無く, case 3 / 7 の処理に続く
      }
      case 3:
      case 7: {
        if (!(door->unk_36 & 1)) {
          Door_UpdateStepSprite(door);
        }
        break;
      }
      case 15: {
        Door_UpdateStepSprite(door);
        if (gStat->sunGauge > 2) {
          Vec3 d = door->pos_68;

          d.x -= gStat->playerX;
          d.y -= gStat->playerY;
          d.z -= gStat->playerZ;
          if (d.x * d.x + d.z * d.z < 77000 && abs(d.y) < 255 && !DoorManager_IsNearID(p, door->id)) {
            p->nearIDs[p->nearCount] = door->id;
            p->nearCount++;
          }
        }
        break;
      }
      case 16: {
        Door_UpdateLocked(p, door);
        break;
      }
    }
  }

  for (i = 0; i < p->prevNearCount; i++) {
    if (!DoorManager_IsNearID(p, p->prevNearIDs[i])) {
      DoorManager_CloseByID(p, p->prevNearIDs[i]);
    }
  }
  for (i = 0; i < p->nearCount; i++) {
    if (!DoorManager_WasNearID(p, p->nearIDs[i])) {
      DoorManager_OpenByID(p, p->nearIDs[i]);
    }
  }
  for (i = 0; i < p->unk_1a; i++) {
    Door* door = &p->doors[i];

    if (door->fn != NULL) {
      door->fn(door);
    }
  }
  return 0;
}

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
  if (p->useLockedVariants != 0) {
    Free(p->lockedSet1);
    Free(p->lockedSet2);
    Free(p->lockedSet3);
    Free(p->lockedSet4);
    Free(p->lockedSet5);
    Free(p->lockedSet6);
    Free(p->lockedSet7);
  }
  Free(p->doors);
  Registry_Remove(0x85E6);
  return 0;
}

s32 DoorManager_Init(DoorManager* p, u32 mesgID, unknown* param_3) {
  s32 i;

  p->mesgID = mesgID;
  p->heldID = 0;
  p->unk_1a = 0;
  p->useLockedVariants = VM_GetNamedArgValue('e', 1);
  if (p->useLockedVariants != 0) {
    p->lockedSet1 = Malloc(sizeof(DoorSpriteSet));
    p->lockedSet2 = Malloc(sizeof(DoorSpriteSet));
    p->lockedSet3 = Malloc(sizeof(DoorSpriteSet));
    p->lockedSet4 = Malloc(sizeof(DoorSpriteSet));
    p->lockedSet5 = Malloc(sizeof(DoorSpriteSet));
    p->lockedSet6 = Malloc(sizeof(DoorSpriteSet));
    p->lockedSet7 = Malloc(sizeof(DoorSpriteSet));
    if (p->lockedSet1 == NULL || p->lockedSet2 == NULL || p->lockedSet3 == NULL || p->lockedSet4 == NULL || p->lockedSet5 == NULL || p->lockedSet6 == NULL || p->lockedSet7 == NULL) {
      KillEntity((Entity*)p);
      return -1;
    }
    ClearMemory(p->lockedSet1, sizeof(DoorSpriteSet));
    ClearMemory(p->lockedSet2, sizeof(DoorSpriteSet));
    ClearMemory(p->lockedSet4, sizeof(DoorSpriteSet));
    ClearMemory(p->lockedSet5, sizeof(DoorSpriteSet));
    ClearMemory(p->lockedSet6, sizeof(DoorSpriteSet));
    ClearMemory(p->lockedSet7, sizeof(DoorSpriteSet));
  } else {
    p->lockedSet1 = NULL;
    p->lockedSet2 = NULL;
    p->lockedSet3 = NULL;
    p->lockedSet4 = NULL;
    p->lockedSet5 = NULL;
    p->lockedSet6 = NULL;
    p->lockedSet7 = NULL;
  }

  if (VM_SeekToNamedArg('d')) {
    for (i = 0; i < 5; i++) {
      if (!Video_GetAuxSprite(&p->sprites_3c[i], VM_GetPC() != NULL ? (u16)VM_GetValue() : SPRITE_DOOR_WOOD)) {
        return -1;
      }
    }
  } else {
    for (i = 0; i < 5; i++) {
      if (!Video_GetAuxSprite(&p->sprites_3c[i], SPRITE_DOOR_WOOD)) {
        return -1;
      }
    }
  }

  if (VM_SeekToNamedArg('k')) {
    for (i = 0; i < 5; i++) {
      u16 id = VM_GetPC() != NULL ? (u16)VM_GetValue() : SPRITE_DOOR_LOCKED;

      if (!Video_GetAuxSprite(&p->sprites_154[i], id)) {
        return -1;
      }
      if (p->useLockedVariants != 0) {
        Video_GetAuxSprite(&p->lockedSet1->gfx[i], id);
        Video_GetAuxSprite(&p->lockedSet2->gfx[i], id);
        Video_GetAuxSprite(&p->lockedSet3->gfx[i], id);
        Video_GetAuxSprite(&p->lockedSet4->gfx[i], id);
        Video_GetAuxSprite(&p->lockedSet5->gfx[i], id);
        Video_GetAuxSprite(&p->lockedSet6->gfx[i], id);
        Video_GetAuxSprite(&p->lockedSet7->gfx[i], id);
      }
    }
  } else {
    for (i = 0; i < 5; i++) {
      if (!Video_GetAuxSprite(&p->sprites_154[i], SPRITE_DOOR_LOCKED)) {
        return -1;
      }
    }
  }

  if (VM_SeekToNamedArg('S')) {
    u16 id;

    if (VM_GetPC() != NULL) {
      id = VM_GetValue();
    } else {
      id = SPRITE_IRON_BARS_7AD2;
    }
    for (i = 0; i < 5; i++) {
      if (!Video_GetAuxSprite(&p->sprites_c8[i], id)) {
        return -1;
      }
    }
  } else {
    for (i = 0; i < 5; i++) {
      if (!Video_GetAuxSprite(&p->sprites_c8[i], SPRITE_IRON_BARS_7AD2)) {
        return -1;
      }
    }
  }

  if (VM_SeekToNamedArg('b')) {
    for (i = 0; i < 5; i++) {
      u16 id = VM_GetPC() != NULL ? (u16)VM_GetValue() : SPRITE_DOOR_LOAN_0;

      if (!Video_GetAuxSprite(&p->sprites_1e0[i], id)) {
        return -1;
      }
      if (!Video_GetAuxSprite(&p->sprites_26c[i], id)) {
        return -1;
      }
    }
  } else {
    for (i = 0; i < 5; i++) {
      if (!Video_GetAuxSprite(&p->sprites_1e0[i], SPRITE_DOOR_LOCKED)) {
        return -1;
      }
      if (!Video_GetAuxSprite(&p->sprites_26c[i], SPRITE_DOOR_LOCKED)) {
        return -1;
      }
    }
  }

  if (VM_SeekToNamedArg('s')) {
    for (i = 0; i < 5; i++) {
      if (!Video_GetAuxSprite(&p->sprites_2f8[i], VM_GetPC() != NULL ? (u16)VM_GetValue() : SPRITE_DOOR_7AF3)) {
        return -1;
      }
    }
  } else {
    for (i = 0; i < 5; i++) {
      if (!Video_GetAuxSprite(&p->sprites_2f8[i], SPRITE_DOOR_7AF3)) {
        return -1;
      }
    }
  }

  if (VM_SeekToNamedArg('u')) {
    for (i = 0; i < 5; i++) {
      if (!Video_GetAuxSprite(&p->sprites_384[i], VM_GetPC() != NULL ? (u16)VM_GetValue() : SPRITE_DOOR_7AF3)) {
        return -1;
      }
    }
  } else {
    for (i = 0; i < 5; i++) {
      if (!Video_GetAuxSprite(&p->sprites_384[i], SPRITE_DOOR_7AF3)) {
        return -1;
      }
    }
  }

  p->doorMax = VM_GetNamedArgValue('m', 16);
  p->doors = Malloc(p->doorMax * sizeof(Door));
  ClearMemory(p->doors, p->doorMax * sizeof(Door));
  for (i = 0; i < 4; i++) {
    p->nearIDs[i] = 0;
  }
  Registry_Add(0x85E6, p, 0);
  return 0;
}

// 0x6D69
DoorManager* DoorManager_Create(u32 mesgID, unknown* param_2) {
  DoorManager* p = CreateEntity(ENTITY_UNK_9, sizeof(DoorManager));

  if (p != NULL) {
    SetEntityRoutine(p, DoorManager_Update, DoorManager_Destroy);
    if (DoorManager_Init(p, mesgID, param_2) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
