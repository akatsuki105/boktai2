#include "camera.h"
#include "collision_map.h"
#include "entity.h"
#include "global.h"
#include "malloc.h"
#include "sound.h"
#include "sprite.h"
#include "vm.h"

void* FUN_08230e70(u16 id);

struct Door;
typedef void (*DoorFunc)(struct Door* p);

// 扉1体。DoorManager.doors が doorMax 体ぶん並べて持つ
typedef struct Door {
  AuxSprite sprite;         // 0x00, DoorManager_Destroy が AuxSprite_Remove に渡す
  MapTileOverride* unk_2c;  // 0x2C, DoorManager_Destroy が NULL でなければ Free する
  DoorFunc fn;              // 0x30, FUN_08020AF8 が FUN_08020B88 を、FUN_08020B24 が別のハンドラを入れる
  u16 unk_34;               // 0x34, 扉のID。FUN_0801fe58 が一致する扉に unk_36 の bit0 を立てる
  u8 unk_36;                // 0x36
  u8 unk_37;                // 0x37, FUN_08020af8 が 2 を入れる
  u8 unk_38;                // 0x38, ここから 0x40 にかけては 32bit の ldr とバイト単位の strb が重なっていて境界が決まらない
  u8 unk_39;                // 0x39, FUN_08020af8 が 0 を入れる
  u8 unk_3a;                // 0x3A, FUN_08020af8 が 0 を入れる
  u8 unk_3b;                // 0x3B
  u16 unk_3c;               // 0x3C, 扉のID (FUN_08020358 が unk_40 == 2 の扉と突き合わせる)
  u8 unk_3e;                // 0x3E
  u8 unk_3f;                // 0x3F
  u8 unk_40;                // 0x40, 2 のとき unk_3c が有効
  u8 unk_41;                // 0x41, FUN_0801fc88 が 1 を入れる
  u8 unk_42[30];            // 0x42
  s32 unk_60;               // 0x60, FUN_08020CD8 / FUN_08020D10 が読み書きする
  s32 scriptID;             // 0x64, FUN_08020D10 が Script_ExecById に渡してから 0 を入れる
  u8 unk_68[24];            // 0x68, 0x72 の strh と 0x7A の ldrh がある
  u16 unk_80;               // 0x80, FUN_08020B88 が +0xF、FUN_08020C1C が -0xF する
  s16 unk_82;               // 0x82, FUN_08020D10 が ldrsh で読んで減らす
  u8 unk_84[8];             // 0x84, 0x84 の ldrb と 0x88 の ldrh がある
} Door;
static_assert(sizeof(Door) == 140);

// '.k' の扉の絵一式を複製して入れる置き場。DoorManager_Init が Malloc(140) で7個作る
typedef struct {
  AuxSpriteGfx gfx[5];
} DoorSpriteSet;
static_assert(sizeof(DoorSpriteSet) == 140);

// AuxSpriteGfx 5枚 x 7 種類の扉グラフィックを持ち、doorMax 体ぶんの扉の実体を管理するシングルトン
// スクリプトのキーワードごとに種類が対応する: 'd'=木の扉 / 'S'=鉄格子 / 'k'=鍵付き青扉1 / 'b'=鍵付き青扉2 / 's' / 'u'
typedef struct {
  Entity e;                     // 0x00, ENTITY_UNK_9
  u16 subroutineID;             // 0x18, DoorManager_Update が FUN_08230F94 の検索キーに使う
  u16 unk_1a;                   // 0x1A, DoorManager_Destroy が doors を走査する件数
  u8 unk_1c;                    // 0x1C, DoorManager_Update が unk_1e を走査する件数。走査後 unk_1d へ移して 0 に戻す
  u8 unk_1d;                    // 0x1D, 前フレームの unk_1c
  u16 unk_1e[4];                // 0x1E, _Init が 0x24 から 0x1E へ順に 0 で埋める。_Update が unk_1c 件ぶん走査する
  u16 unk_26[4];                // 0x26, 前フレームぶんの unk_1e。FUN_0801fad8 が unk_1d 件ぶん走査する
  u16 unk_2e;                   // 0x2E, _Init が 0 を入れる
  s32 doorMax;                  // 0x30, '.m=16', doors の要素数
  s32 unk_34;                   // 0x34, '.e=1', 0 でなければ 0x410..0x428 も確保する
  ScriptRecord* records;        // 0x38, FUN_08230F94(subroutineID, &records) の出力。_Update が values[0] を命令として分岐する
  AuxSpriteGfx sprites_3c[5];   // 0x3C, '.d=SPRITE_DOOR_7ACD'
  AuxSpriteGfx sprites_c8[5];   // 0xC8, '.S=SPRITE_DOOR_IRON'
  AuxSpriteGfx sprites_154[5];  // 0x154, '.k=SPRITE_DOOR_LOCKED'
  AuxSpriteGfx sprites_1e0[5];  // 0x1E0, '.b=SPRITE_DOOR_LOCKED', sprites_26c と対で埋める, 鍵で開けた後と開ける前で2つあるのかも？
  AuxSpriteGfx sprites_26c[5];  // 0x26C, '.b=SPRITE_DOOR_7AEE'
  AuxSpriteGfx sprites_2f8[5];  // 0x2F8, '.s=SPRITE_DOOR_7AF3'
  AuxSpriteGfx sprites_384[5];  // 0x384, '.u=SPRITE_DOOR_7AF3'
  DoorSpriteSet* unk_410;       // 0x410, unk_34 が 0 でなければ Malloc(0x8C)。script 'k' の絵を複製して入れる
  DoorSpriteSet* unk_414;       // 0x414
  DoorSpriteSet* unk_418;       // 0x418
  DoorSpriteSet* unk_41c;       // 0x41C
  DoorSpriteSet* unk_420;       // 0x420
  DoorSpriteSet* unk_424;       // 0x424
  DoorSpriteSet* unk_428;       // 0x428
  Door* doors;                  // 0x42C, Malloc(doorMax * 140)
  u8 unk_430[4];                // 0x430, 読み手も書き手も見つかっていない
} DoorManager;
static_assert(sizeof(DoorManager) == 1076);

void FUN_080206b0(Door* door);
void FUN_08020af8(Door* door);
void FUN_08230e58(u16 id);
void FUN_08020b24(Door* door);
void FUN_080206b8(Door* door);
void FUN_08020734(Door* door);
void FUN_080206b4(Door* door);

static inline void Door_SetPhase(Door* door, u32 phase) { door->unk_37 = phase; }

static inline void Door_SetStep(Door* door, u32 step) {
  door->unk_39 = step;
  door->unk_3a = 0;
}

NAKED void FUN_0801f764(DoorManager* p) { INCFUNC("asm/func/FUN_0801f764.inc"); }

NAKED void FUN_0801f7f4(DoorManager* p) { INCFUNC("asm/func/FUN_0801f7f4.inc"); }

NAKED void FUN_0801f858(DoorManager* p) { INCFUNC("asm/func/FUN_0801f858.inc"); }

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

NAKED bool32 FUN_0801fb08(unknown* param_1, s32 param_2) { INCFUNC("asm/func/FUN_0801fb08.inc"); }

NAKED s32 FUN_0801fb48(void) { INCFUNC("asm/func/FUN_0801fb48.inc"); }

// そのIDの閉じている扉を開き始めさせる
NON_MATCH void FUN_0801fc88(DoorManager* p, u16 id) {
#ifdef NONMATCHING_C
  s32 i;

  for (i = 0; i < p->unk_1a; i++) {
    Door* door = &p->doors[i];

    if (door->unk_34 == id && (door->unk_37 == 0 || door->unk_37 == 3) && !(door->unk_36 & 1)) {
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

    if (door->unk_34 == id && (door->unk_37 == 1 || door->unk_37 == 2)) {
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

    if (door->unk_34 == id) {
      Door_SetPhase(door, 1);
      door->fn = FUN_080206b4;
      door->unk_39 = 0;
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

    if (door->unk_34 == id) {
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
    if (door->unk_34 == id) {
      door->unk_36 |= 1;
    }
  }
}

// そのIDの扉の印を外す
void FUN_0801fe98(DoorManager* p, u16 id) {
  s32 i;

  for (i = 0; i < p->unk_1a; i++) {
    Door* door = &p->doors[i];
    if (door->unk_34 == id) {
      door->unk_36 &= ~1;
    }
  }
}

// スクリプトの 'n' が指す扉を開かせる。1体でも見つかれば 1 を返す
s32 FUN_0801fedc(void) {
  DoorManager* p = FUN_08230e70(0x85E6);
  s32 found;
  s32 id;
  s32 i;

  if (p == NULL) {
    return -1;
  }
  found = 0;
  if (!VM_SeekToKeyword('n')) {
    return 0;
  }
  id = Script_GetValue();
  for (i = 0; i < p->unk_1a; i++) {
    Door* door = &p->doors[i];

    if (door->unk_34 == id) {
      if (VM_SeekToKeyword('p')) {
        door->unk_60 = Script_GetValue();
      }
      if (door->unk_37 == 1 || door->unk_37 == 3) {
        door->unk_37 = 2;
        door->fn = FUN_08020af8;
      }
      found = 1;
    }
  }
  return found;
}

// スクリプトの 'n' が指す扉を閉じさせる。1体でも見つかれば 1 を返す
s32 FUN_0801ff78(void) {
  DoorManager* p = FUN_08230e70(0x85E6);
  s32 found;
  s32 id;
  s32 i;

  if (p == NULL) {
    return -1;
  }
  found = 0;
  if (!VM_SeekToKeyword('n')) {
    return -1;
  }
  id = Script_GetValue();
  for (i = 0; i < p->unk_1a; i++) {
    Door* door = &p->doors[i];

    if (door->unk_34 == id) {
      if (VM_SeekToKeyword('p')) {
        door->scriptID = Script_GetValue();
      }
      if (door->unk_37 == 0 || door->unk_37 == 2) {
        door->unk_37 = 3;
        door->fn = FUN_08020b24;
      }
      found = 1;
    }
  }
  return found;
}

NAKED s32 FUN_08020010(void) { INCFUNC("asm/func/FUN_08020010.inc"); }

NAKED s32 FUN_080200f0(void) { INCFUNC("asm/func/FUN_080200f0.inc"); }

// スクリプトの 'n' が指す扉を開き始めさせる
void FUN_080201c8(void) {
  DoorManager* p = FUN_08230e70(0x85E6);

  if (p != NULL && VM_SeekToKeyword('n')) {
    s32 id = Script_GetValue();
    s32 i;

    for (i = 0; i < p->unk_1a; i++) {
      Door* door = &p->doors[i];

      if (door->unk_34 == id) {
        door->unk_41 = 1;
        p->unk_1e[p->unk_1c] = door->unk_34;
        p->unk_1c++;
        Door_SetPhase(door, 2);
        door->fn = FUN_08020734;
        Door_SetStep(door, 0);
      }
    }
  }
}

// スクリプトの 'n' が1体だけ該当するとき、その扉の座標を 'p' の変数へ返す
NON_MATCH void FUN_08020260(void) {
#ifdef NONMATCHING_C
  DoorManager* p = FUN_08230e70(0x85E6);

  if (p != NULL && VM_SeekToKeyword('n')) {
    s32 id = Script_GetValue();
    s32 i = 0;
    s32 count = 0;
    s32 found = 0;
    u8 out[8];

    for (; i < p->unk_1a; i++) {
      if (p->doors[i].unk_34 == id) {
        count++;
        found = i;
      }
    }
    if (count == 1 && VM_SeekToKeyword('p')) {
      FUN_0823167c(out);
      FUN_0823206c(out, 0, p->doors[found].sprite.pos.x);
      FUN_0823167c(out);
      FUN_0823206c(out, 0, p->doors[found].sprite.pos.y);
      FUN_0823167c(out);
      FUN_0823206c(out, 0, p->doors[found].sprite.pos.z);
    }
  }
#else
  INCFUNC("asm/func/FUN_08020260.inc");
#endif
}

void FUN_08020314(void) {
  DoorManager* p = FUN_08230e70(0x85E6);
  if (p != NULL && VM_SeekToKeyword('n')) {
    p->unk_2e = Script_GetValue();
  }
}

void FUN_0802033c(void) {
  DoorManager* p = FUN_08230e70(0x85E6);
  if (p != NULL) {
    p->unk_2e = 0;
  }
}

// そのIDの扉が開いているか
s32 FUN_08020358(u32 id) {
  DoorManager* p = FUN_08230e70(0x85E6);

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

// 何もしないハンドラ
void FUN_080206b0(Door* door) {}

// 何もしないハンドラ
void FUN_080206b4(Door* door) {}

NAKED void FUN_080206b8(Door* door) { INCFUNC("asm/func/FUN_080206b8.inc"); }

NAKED void FUN_08020734(Door* door) { INCFUNC("asm/func/FUN_08020734.inc"); }

NAKED void FUN_080207b0(DoorManager* p, AuxSprite* sprite) { INCFUNC("asm/func/FUN_080207b0.inc"); }

void FUN_08020b88(Door* door);

// 扉が開き始めるときの処理
void FUN_08020af8(Door* door) {
  PlaySound_082406e0(0x152);
  door->unk_39 = 0;
  door->unk_3a = 0;
  Door_SetPhase(door, 2);
  door->fn = FUN_08020b88;
}

NAKED void FUN_08020b24(Door* door) { INCFUNC("asm/func/FUN_08020b24.inc"); }

NAKED void FUN_08020b88(Door* door) { INCFUNC("asm/func/FUN_08020b88.inc"); }

NAKED void FUN_08020c1c(Door* door) { INCFUNC("asm/func/FUN_08020c1c.inc"); }

// 開閉の残りフレームを数え、終わったら予約してあったスクリプトを実行する
NON_MATCH void FUN_08020cd8(Door* door) {
#ifdef NONMATCHING_C
  s32 remain = door->unk_82;

  if (remain != 0) {
    FUN_0823b9cc(remain);
    door->unk_82--;
  } else if (door->unk_60 != 0) {
    Script_ExecById(door->unk_60, NULL);
    door->unk_60 = remain;
  }
  door->sprite.priority = 2;
#else
  INCFUNC("asm/func/FUN_08020cd8.inc");
#endif
}

// 開閉の残りフレームを数え、終わったら予約してあったスクリプトを実行する
NON_MATCH void FUN_08020d10(Door* door) {
#ifdef NONMATCHING_C
  s32 remain = door->unk_82;

  if (remain != 0) {
    FUN_0823b9cc(remain);
    door->unk_82--;
  } else if (door->scriptID != 0) {
    Script_ExecById(door->scriptID, NULL);
    door->scriptID = remain;
  }
#else
  INCFUNC("asm/func/FUN_08020d10.inc");
#endif
}

NAKED void FUN_08020d44(DoorManager* p, AuxSprite* sprite) { INCFUNC("asm/func/FUN_08020d44.inc"); }

void FUN_0802108c(void) {}

void FUN_08021090(void) {}

NAKED s32 DoorManager_Update(DoorManager* p) { INCFUNC("asm/func/DoorManager_Update.inc"); }

s32 DoorManager_Destroy(DoorManager* p) {
  s32 i;

  for (i = 0; i < p->unk_1a; i++) {
    Door* door = &p->doors[i];

    if (door->unk_2c != NULL) {
      FUN_082342a8(door->unk_2c);
      Free(door->unk_2c);
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
  FUN_08230e58(0x85E6);
  return 0;
}

NAKED s32 DoorManager_Init(DoorManager* p, u32 subroutineID, unknown* param_3) { INCFUNC("asm/func/DoorManager_Init.inc"); }

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
