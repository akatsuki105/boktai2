#include "entity.h"
#include "global.h"
#include "sound.h"
#include "sprite.h"
#include "text.h"
#include "video.h"
#include "vm.h"
#include "weapon.h"

s32 FUN_08049e5c(void);
s32 FUN_08049fa8(void);
bool32 FUN_081dfa04(void);
void FUN_080b9a0c(unknown* p);
bool32 FUN_080b9adc(unknown* p);
void FUN_080b9fc4(unknown* p, unknown* q);
void FUN_080b9ff8(unknown* p, s32 a, s32 b, s32 c, s32 d);

// 通信販売(相手と武器の売り買いをする, 実質的なアイテム交換機能) or 通信対戦の武器選択 の画面
// gEntity9A9F の記録から相手の武器を読み、36枚のスプライトで並べる
// 相手の武器を詳細にみているので、多分 通信販売 の画面
typedef struct {
  Entity e;                // 0x000, ENTITY_UNK_8
  u8* record;              // 0x018, &gEntity9A9F->unk_15c, セッションが無ければ NULL で _Init は失敗する
  void* tilemapFile;       // 0x01C, GetFile(DIR_TILE_MAP, 0xCD91), BG2 に敷く
  rgb555* bgPltt;          // 0x020, GetFile(DIR_BGPLTT, "bg_link_col_arr") + 0x14
  void* unk_24;            // 0x024, ワードとして読まれるが用途不明
  MainSpriteGfx gfx[4];    // 0x028, OpenMainSpriteFile(&gfx[i], file) を 0x28 / 0x48 / 0x68 / 0x88 で行う
  MainSprite sprites[36];  // 0x0A8, Entity1B24_Destroy がまとめて外す
  u8 unk_e28[48];          // 0xE28
  u8 unk_e58[244];         // 0xE58, _Init が FUN_080b99a0(&unk_e58), _Destroy が FUN_080b9a0c(&unk_e58) に渡す
  WeaponData weaponData;   // 0xF4C, record[0x40] が 2 なら GUN_DEL_HELL を直接書き、そうでなければ FUN_08242b14(slot, &weaponData)
  s8 slot;                 // 0xF70, record[0x17]。負なら武器を読まない
  u8 weaponKindMask;       // 0xF71, GetWeaponKind(slot) を16スロット分見て bit0..3 を立てる, record[0x40] が 2 なら 0xF
  u16 unk_f72;             // 0xF72, FUN_0809ce90 が状態遷移のたびに 0 を入れる
  u32 unk_f74;             // 0xF74, _Init が 0x1E を入れる
  u8 unk_f78[12];          // 0xF78
  void* unk_f84;           // 0xF84, FUN_0809ce90 が GetFile の戻り値か 0 を入れる
  void* unk_f88;           // 0xF88, 同上
  EntityFunc fn;           // 0xF8C, _Update が毎フレーム呼ぶ。_Init が 0x0809D3D0 を入れる
} Entity1B24;
static_assert(sizeof(Entity1B24) == 3984);

// 状態関数を差し替える
void FUN_0809ce90(Entity1B24* p, EntityFunc fn) {
  p->fn = fn;
  p->unk_f72 = 0;
}

NAKED void FUN_0809cea8(Entity1B24* p) { INCFUNC("asm/func/FUN_0809cea8.inc"); }

// そのスロットの武器が一覧に並べられるものかを返す
bool32 FUN_0809cf98(s32 slot) {
  weapon32_t id = GetWeaponID(slot);

  if (id == WEAPON_NONE || id == WEAPON_BROKEN_GUN || id == WEAPON_STAR_PIECE || id == WEAPON_ASTRO_SWORD || id == WEAPON_ASTRO_SPEAR || id == WEAPON_ASTRO_HAMMER) {
    return FALSE;
  }
  return TRUE;
}

NAKED s32 FUN_0809cfc0(Entity1B24* p) { INCFUNC("asm/func/FUN_0809cfc0.inc"); }

NAKED void FUN_0809d00c(Entity1B24* p) { INCFUNC("asm/func/FUN_0809d00c.inc"); }

void FUN_0809d230(Entity1B24* p) {
  TextBox_Close();
  FUN_08049e5c();
}

// 一覧の n 番目のセルの画面座標を求める
void FUN_0809d240(u16* pos, s32 n) {
  if (n <= 15) {
    pos[0] = (n & 3) * 24 + 144;
    pos[1] = (n >> 2) * 24 + 32;
  } else {
    pos[0] = 64;
    pos[1] = 76;
  }
}

NAKED void FUN_0809d270(Entity1B24* p) { INCFUNC("asm/func/FUN_0809d270.inc"); }

NAKED void FUN_0809d300(Entity1B24* p) { INCFUNC("asm/func/FUN_0809d300.inc"); }

NAKED void FUN_0809d3d0(Entity1B24* p) { INCFUNC("asm/func/FUN_0809d3d0.inc"); }

void FUN_0809d7a4(Entity1B24* p) {
  if (FUN_080b9adc(p->unk_e58)) {
    PlaySound_082406e0(0x111);
    FUN_0809d300(p);
    FUN_0809d00c(p);
    FUN_0809ce90(p, (EntityFunc)FUN_0809d3d0);
  }
}

s32 Entity1B24_Update(Entity1B24* p) {
  if (!FUN_081dfa04()) {
    s32 i;

    FUN_08049fa8();
    for (i = 0; i < 36; i++) {
      p->sprites[i].flags |= SPRFLAG_HIDDEN;
    }
    KillEntity((Entity*)p);
    return -1;
  }
  p->fn((Entity*)p);
  return 0;
}

s32 Entity1B24_Destroy(Entity1B24* p) {
  s32 i;

  for (i = 0; i < 36; i++) {
    MainSprite_Remove(&p->sprites[i]);
  }
  FUN_080b9a0c(p->unk_e58);
  return 0;
}

// タイルマップ上の (x, y) のセルを指す
u16* FUN_0809d858(s32 bg, s32 x, s32 y) {
  BgState* state = &gBgStates[bg];
  u16* tilemap = state->tilemap;

  return tilemap + (x & 31) + (y & 31) * 32;
}

NAKED void FUN_0809d878(Entity1B24* p) { INCFUNC("asm/func/FUN_0809d878.inc"); }

NAKED void FUN_0809d934(Entity1B24* p) { INCFUNC("asm/func/FUN_0809d934.inc"); }

void FUN_0809dd34(Entity1B24* p) {
  FUN_080b9ff8(p->unk_e28, 0, 0, 0, 30);
  FUN_080b9fc4(p->unk_e28, &p->sprites[18]);
}

void FUN_0809dd68(Entity1B24* p) {
  if (VM_SeekToKeyword('w')) {
    p->unk_24 = FUN_0823d340();
  }
  FUN_0809cea8(p);
}

void FUN_0809dd88(Entity1B24* p) {
  if (VM_SeekToKeyword('p')) {
    p->unk_f84 = (void*)Script_GetValue();
  } else {
    p->unk_f84 = NULL;
  }
  if (VM_SeekToKeyword('n')) {
    p->unk_f88 = (void*)Script_GetValue();
  } else {
    p->unk_f88 = NULL;
  }
}

// 相手が持っている武器の種別ビットを集める
void FUN_0809dde0(Entity1B24* p) {
  if (p->record[0x40] == 2) {
    p->weaponKindMask = 0xF;
  } else {
    s32 i;

    p->weaponKindMask = 0;
    for (i = 0; i < 16; i++) {
      s32 kind = GetWeaponKind(i);

      if (kind == WK_SWORD) {
        p->weaponKindMask |= 1;
      } else if (kind == WK_SPEAR) {
        p->weaponKindMask |= 2;
      } else if (kind == WK_HAMMER) {
        p->weaponKindMask |= 4;
      } else if (kind == WK_GUN) {
        p->weaponKindMask |= 8;
      }
    }
  }
}

NAKED s32 Entity1B24_Init(Entity1B24* p) { INCFUNC("asm/func/Entity1B24_Init.inc"); }

Entity1B24* Entity1B24_Create(u32 subroutineID) {
  Entity1B24* p = CreateEntity(ENTITY_UNK_8, sizeof(Entity1B24));

  if (p != NULL) {
    SetEntityRoutine(p, Entity1B24_Update, Entity1B24_Destroy);
    if (Entity1B24_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
