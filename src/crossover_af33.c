#include "bg_pltt.h"
#include "boss.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "input.h"
#include "menu.h"
#include "player.h"
#include "random.h"
#include "save.h"
#include "sound.h"
#include "sprite_main.h"
#include "text.h"
#include "video.h"
#include "vm.h"

// 0x3C から 0xC 刻みで3件, _Init が各回 +4 に {100, 100, 0, 0} と +8 に u32 0 を入れる
typedef struct {
  u8 unk_00[4];  // 0x00, [1] が 0 以外なら FUN_0804e514 に渡す, FUN_0804fb04 が4バイトまとめて 0 にする
  u8 unk_04[4];  // 0x04, _Init が {100, 100, 0, 0} を入れる
  u32 unk_08;    // 0x08, _Init が 0 を入れる
} EntityAF33Slot;
static_assert(sizeof(EntityAF33Slot) == 12);

// 通信で届いた EntityAF33Slot の読み方, data の中身は kind で決まる
typedef struct {
  u8 unk_00;     // 0x00
  u8 kind;       // 0x01, FUN_0804fa44 の kind
  u8 unk_02[2];  // 0x02
  union {
    u32 word;
    u16 half[2];
  } data;      // 0x04
  u32 unk_08;  // 0x08
} EntityAF33Msg;
static_assert(sizeof(EntityAF33Msg) == 12);

// クロスオーバーバトルに関係
typedef struct {
  Entity e;                 // 0x000, ENTITY_UNK_2
  u32 unk_18;               // 0x018, _Init が 0 を入れる
  u16 unk_1c;               // 0x01C, _Init が 0 を入れる
  u16 unk_1e;               // 0x01E, _Init が 0 を入れる
  u32 unk_20;               // 0x020, _Init が 0 を入れる
  u32 stateTimer;           // 0x024, state に入ってからのフレーム数
  u8 state;                 // 0x028, PTR_ARRAY_085ab6a4 の添字
  bool8 stateBegun;         // 0x029, 立っていると次の更新で state の初期化をする
  u8 unk_2a[0x2D - 0x2A];   // 0x02A, _Init が 0x2B と 0x2C に 0 を入れる
  u8 unk_2d;                // 0x02D, _Init が 0 を入れる
  u8 unk_2e;                // 0x02E
  u8 unk_2f;                // 0x02F
  u8 unk_30;                // 0x030, FUN_08050d40 が立っていれば 0 に落として 1 を返す
  u8 unk_31;                // 0x031
  u8 unk_32;                // 0x032, _Init が 1 を入れる, FUN_0804fa04 が 0 でなければ減らす
  u8 unk_33;                // 0x033, _Init が 0、FUN_0804fb24 が 1 を入れる
  u8 unk_34;                // 0x034, FUN_0804fbf0 が 1 を入れる
  u8 retryCount;            // 0x035, セーブに失敗してやり直した回数
  bool8 saveResult;         // 0x036, Save_WriteSystemData の戻り値
  u8 unk_37;                // 0x037, 対戦中 1
  u8 unk_38[4];             // 0x038, _Init が 4バイト 0 クリアする
  EntityAF33Slot slots[3];  // 0x03C, _Init は先頭2件だけ埋める
  void* unk_60;             // 0x060, _Init が CrossoverMC_Create() の戻り値を入れる
  void* unk_64;             // 0x064, _Init が Entity08052ffc_Create() の戻り値を入れる
  u32 count78;              // 0x068, unk_78 に積んだ '.w' の件数
  u32 count98;              // 0x06C, unk_98 に積んだ '.m' の件数
  u32 mask70;               // 0x070, unk_78 を配るときに使用済みスロットのビットを立てる
  u32 mask74;               // 0x074, unk_98 を配るときに使用済みスロットのビットを立てる
  u16 unk_78[16];           // 0x078, '.w' の値を最大16個
  u16 unk_98[16];           // 0x098, '.m' の値を最大16個
  u8* script;               // 0x0B8, '.s' の後の VM_GetPC_Proxy() の戻り値, NULL なら _Init が失敗する
  s32 windowID;             // 0x0BC, _Destroy が TextPanel_Destroy に渡す
  u32 unk_c0;               // 0x0C0, 読み手も書き手も見つかっていない
  u32 unk_c4;               // 0x0C4, '.e'
  s32 unk_c8;               // 0x0C8, _Init が 0 を入れる, 対戦後に crossoverPoint へ足される
  MainSpriteGfx iconGfx;    // 0x0CC, SPRITE_INVENTORY_ICONS
  MainSprite sprites[2];    // 0x0EC, _Destroy が MainSprite_Remove に渡す2枚
  u16 unk_1ac;              // 0x1AC, '.M=11'
  u16 unk_1ae[4];           // 0x1AE, '.p'
  u8 unk_1b6[2];            // 0x1B6
  u32 unk_1b8;              // 0x1B8, START を押すと 1
} EntityAF33;
static_assert(sizeof(EntityAF33) == 444);

IWRAM_DATA EntityAF33* gEntityAF33 = NULL;  // 0x030000F0
IWRAM_DATA u8 u8_030000f4[4] = {};
IWRAM_DATA u8 gCrossoverPlayerNames[2][16] = {};  // 0x030000F8, 通信対戦の待合画面で決まった双方のプレイヤー名

struct CrossoverMC;

s32 FUN_0804e514(void* param_1);  // src/entity_0804e2c0.c
void FUN_0804e5e8(void);          // src/entity_0804e2c0.c

s32 CrossoverMC_SetState(struct CrossoverMC* p, u32 state);
void CrossoverMC_RequestExit(struct CrossoverMC* p);
void Entity08052ffc_Spawn(void* p, u32 idx, u32 mode, Vec3* pos);
s32 FUN_08051d18(Vec3* pos, s32 idx, s32 count);
void FUN_08050e50(u32 param_1, u32 param_2);
void FUN_0823ce68(s32 param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5, u32 param_6, s32 param_7);
s32 MainMenu_SetHudMode(s32 mode);
void FUN_0804e604(void);
void* FUN_0804ba3c(void);
void FUN_0803cc70(void);
bool32 FUN_0804e59c(void);
void MosaicFader_Stop(void);
void Player_Lock(Player* p, s32 val);
void FUN_0804fe24(EntityAF33* p);
void FUN_0804fe68(EntityAF33* p);
void FUN_0804f97c(EntityAF33* p);
void FUN_0804fb24(void);
s32 FUN_08051c50(void (*onFinish)(void), u8* counts0, u8* counts1, u8* out);
s32 FUN_08051bb0(void (*onFinish)(void), u8* counts);
void FUN_0808e420(void);
void FUN_0808e4f4(void);
s32 FUN_0804fa04(EntityAF33* p);
s32 FUN_0804fa44(EntityAF33* p, u32 kind, u32* src, s32 wordCount);
void FUN_0804fb04(EntityAF33* p, s32 idx);
void FUN_0804fbd0(EntityAF33* p, u32 state);
void FUN_0804fbe0(EntityAF33* p);
void FUN_0804fc08(EntityAF33* p);
void FUN_0804fd3c(EntityAF33* p);
s32 FUN_0804e458(void);
s32 Entity723E_Setup(u32 param_1, u32 result, s32 framesA, s32 framesB, s32 remain, s32 total, Procedure exitCallback);
bool8 Save_WriteSystemData(void);
void FUN_0804fbf0(void);
void FUN_0803ca14(void);
void FUN_080501c8(EntityAF33* p);
void FUN_0804feb0(EntityAF33* p);
void* Entity08051b70_Create(u32 id, u32 unused);
void* CrossoverMC_Create();
void* Entity08052ffc_Create(void);
void SignalStrengthIcon_CreateAt(s32 x, s32 y);
const WeaponData* FUN_0823d414(s32 idx);
void SetWeaponData(slot32_t n, const WeaponData* data);
void FUN_0804e4dc(void* param_1, void* param_2, void* param_3, void* param_4);
void FUN_0804f82c(EntityAF33Msg* msg);
void FUN_0804f8ec(EntityAF33Slot* slot);
void FUN_0804f950(void);
void FUN_0804f970(void);

// クロスオーバーポイントの今の値
static inline s32 GetCrossoverPoint(void) { return gSystemSaveData->crossoverPoint; }

// state を切り替え, 次の更新で初期化させる
static inline void EntityAF33_SetState(EntityAF33* p, u8 state) {
  p->state = state;
  p->stateBegun = TRUE;
  p->stateTimer = 0;
}

EntityAF33* FUN_0804f820(void) { return gEntityAF33; }

// 相手から届いた枠を種別ごとに相手側の枠 slots[1] へ写し, 届いた印を unk_20 に立てる
void FUN_0804f82c(EntityAF33Msg* msg) {
  EntityAF33* p = FUN_0804f820();
  EntityAF33Slot* b;

  if (p == NULL) {
    return;
  }
  b = &p->slots[1];
  switch (msg->kind) {
    case 0: {
      b->unk_04[0] = msg->data.word;
      b->unk_04[1] = msg->data.word >> 8;
      return;
    }
    case 1: {
      SET_FLAGS(p->unk_20, 2);
      break;
    }
    case 2: {
      s32 shift = 0;
      u16 counts;
      s32 i;

      b->unk_04[2] = msg->data.half[1] % 2;
      counts = msg->data.half[0];
      for (i = 0; i < 4; i++, shift += 4) {
        b->unk_00[i] = (counts >> shift) & 0xF;
      }
      SET_FLAGS(p->unk_20, 8);
      break;
    }
    case 3: {
      SET_FLAGS(p->unk_20, 0x20);
      break;
    }
    case 4: {
      b->unk_08 = msg->data.half[0];
      b->unk_04[3] = msg->data.half[1] % 4;
      if (b->unk_04[3] == 1) {
        b->unk_04[1] = 0;
      } else if (b->unk_04[3] == 2) {
        b->unk_04[0] = 0;
      }
      SET_FLAGS(p->unk_20, 0x80);
      break;
    }
    case 5: {
      if (FUN_0804e458() == 0) {
        p->unk_2f = msg->data.word & 3;
      }
      SET_FLAGS(p->unk_20, 0x200);
      break;
    }
  }
}

// 受け取った枠の種別に応じて unk_20 のビットを立てる
void FUN_0804f8ec(EntityAF33Slot* slot) {
  EntityAF33* p = FUN_0804f820();

  if (p == NULL) {
    return;
  }
  switch (slot->unk_00[1]) {
    case 0: {
      break;
    }
    case 1: {
      SET_FLAGS(p->unk_20, 1);
      break;
    }
    case 2: {
      SET_FLAGS(p->unk_20, 4);
      break;
    }
    case 3: {
      SET_FLAGS(p->unk_20, 0x10);
      break;
    }
    case 4: {
      SET_FLAGS(p->unk_20, 0x40);
      break;
    }
    case 5: {
      SET_FLAGS(p->unk_20, 0x100);
      break;
    }
  }
  p->unk_2a[1] = 1;
}

void FUN_0804f950(void) {
  EntityAF33* p = FUN_0804f820();

  if (p != NULL && p->slots[2].unk_00[1] != 0) {
    FUN_0804e514(&p->slots[2]);
  }
}

void FUN_0804f970(void) { FUN_0804f820(); }

// 双方の枠の数を unk_38 にまとめる
void FUN_0804f97c(EntityAF33* p) {
  EntityAF33Slot* a = &p->slots[0];
  EntityAF33Slot* b = &p->slots[1];
  s32 sum = 0;
  s32 i;

  if (a->unk_04[2] != 0) {
    for (i = 0; i < 4; i++) {
      p->unk_38[i] = 0;
      sum += b->unk_00[i];
    }
    if (sum > 0) {
      FUN_08050e50(3, 1);
    }
  } else {
    for (i = 0; i < 4; i++) {
      p->unk_38[i] = b->unk_00[i];
    }
  }
  if (b->unk_04[2] != 0) {
    for (i = 0; i < 4; i++) {
      p->unk_38[i] += a->unk_00[i];
    }
  } else {
    for (i = 0; i < 4; i++) {
    }
  }
  for (i = 0; i < 4; i++) {
  }
}

s32 FUN_0804fa04(EntityAF33* p) {
  EntityAF33Slot* a = &p->slots[0];
  EntityAF33Slot* b = &p->slots[1];

  if (a->unk_04[2] || b->unk_04[2] || *(u32*)a->unk_00 != 0 || *(u32*)b->unk_00 != 0) {
    if (a->unk_04[2] && p->unk_32 != 0) {
      p->unk_32--;
    }
    return 1;
  }

  return 0;
}

// 3件目の枠に種別と本体を詰めて送信を頼む, 送れなければ保留フラグを立てて -1
s32 FUN_0804fa44(EntityAF33* p, u32 kind, u32* src, s32 wordCount) {
  EntityAF33Slot* slot = &p->slots[2];
  s32 result;

  if (p->unk_2a[0] != 0 && slot->unk_00[1] != 0) {
    return -1;
  }

  slot->unk_00[1] = kind;
  if (wordCount > 0) {
    u32* dst = (u32*)slot->unk_04;

    do {
      *dst++ = *src++;
      wordCount--;
    } while (wordCount != 0);
  }

  result = FUN_0804e514((u8*)slot);
  if (result < 0 && slot->unk_00[1] != 0) {
    p->unk_2a[0] = 1;
  }
  return result;
}

// 双方の枠の unk_04[3] と unk_08 を比べて勝敗を決める (0: 負け, 1: 勝ち, 2: 引き分け)
// 残差: 原典は FUN_08050e50(1, 1) からの return 0 の塊を2か所で共有して4命令短い, if 連鎖と switch のどちらでも共有されない
NON_MATCH u32 FUN_0804fa94(EntityAF33* p) {
#ifdef NONMATCHING_C
  EntityAF33Slot* a = &p->slots[0];
  EntityAF33Slot* b = &p->slots[1];

  switch (a->unk_04[3]) {
    case 0: {
      if (b->unk_04[3] == 1) {
        return 1;
      } else if (b->unk_04[3] == 2) {
        FUN_08050e50(1, 1);
        return 0;
      }
      return 2;
    }
    case 1: {
      if (b->unk_04[3] == 1) {
        if (a->unk_08 < b->unk_08) {
          return 0;
        } else if (a->unk_08 > b->unk_08) {
          return 1;
        }
        return 2;
      } else if (b->unk_04[3] == 2) {
        FUN_08050e50(1, 1);
      }
      return 0;
    }
    default: {
      if (b->unk_04[3] == 1) {
        return 1;
      } else if (b->unk_04[3] == 2) {
        FUN_08050e50(1, 1);
        if (a->unk_08 < b->unk_08) {
          return 1;
        } else if (a->unk_08 > b->unk_08) {
          return 0;
        }
        return 2;
      }
      return 1;
    }
  }
#else
  INCFUNC("asm/func/FUN_0804fa94.inc");
#endif
}

void FUN_0804fb04(EntityAF33* p, s32 idx) {
  EntityAF33Slot* slot = &p->slots[idx];
  s32 i;

  slot->unk_04[2] = 0;
  for (i = 0; i < 4; i++) {
    slot->unk_00[i] = 0;
  }
}

void FUN_0804fb24(void) {
  EntityAF33* p = FUN_0804f820();

  if (p != NULL) {
    p->unk_33 = 1;
  }
}

void FUN_0804fb3c(EntityAF33* p) {
  EntityAF33Slot* slot = &p->slots[0];

  if (p->unk_2d != 0) {
    slot->unk_04[3] = 2;
  } else if (p->unk_2e != 0) {
    slot->unk_04[3] = 1;
  } else {
    slot->unk_04[3] = 0;
  }

  slot->unk_08 = 0x2D0 - p->unk_1c;
}

// 背景 TILEMAP_A413 を index の1枚だけで組み, BG パレットを BGP_EFDA にする
void FUN_0804fb6c(EntityAF33* p, s32 index) {
  Video_SetupBGLayout(0, 0, GetFile(DIR_TILE_MAP, TILEMAP_A413), 0, 0, 1, &index);
  Video_GenerateBGMap(0, 0, 0, 0, 0);
  CpuCopy16(GetBgPlttFile(BGP_EFDA)->body, gBgPlttBuffer, 256 * sizeof(rgb555));
}

void FUN_0804fbd0(EntityAF33* p, u32 state) {
  if (p->unk_60 != NULL) {
    CrossoverMC_SetState(p->unk_60, state);
  }
}

void FUN_0804fbe0(EntityAF33* p) {
  if (p->unk_60 != NULL) {
    CrossoverMC_RequestExit(p->unk_60);
  }
}

void FUN_0804fbf0(void) {
  EntityAF33* p = FUN_0804f820();

  if (p != NULL) {
    p->unk_34 = 1;
  }
}

s32 FUN_08050d64(void);
s32 FUN_08050d7c(void);

// 受け取った武器を, 乱数で選んだ位置から順に登録枠へ配る
void FUN_0804fc08(EntityAF33* p) {
  if (p->count78 != 0) {
    s32 start = Mod(gFrameCounter, p->count78);
    bool32 hasEmpty = FALSE;
    u32 mask = p->mask70;
    s32 i;

    for (i = 0; i < 4; i++) {
      s32 j;

      REGISTERED_WEAPON(i) = -1;
      for (j = start; j < start + 16; j++) {
        s32 k = j & 15;

        if (mask & (1 << k)) {
          REGISTERED_WEAPON(i) = k;
          mask &= ~(1 << k);
          start = j;
          break;
        }
      }
      if (REGISTERED_WEAPON(i) < 0) {
        hasEmpty = TRUE;
      }
      start += Random() & 15;
    }
    if (hasEmpty) {
      for (i = 0; i < 4; i++) {
        if (REGISTERED_WEAPON(i) >= 0 && GetWeaponID(REGISTERED_WEAPON(i)) == WEAPON_NONE) {
          REGISTERED_WEAPON(i) = -1;
        }
      }
    }
    gStat->equippedWeaponIdx = 0;
  }
}

// 受け取った魔法を, 乱数で選んだ位置から順に登録枠へ配る
void FUN_0804fd3c(EntityAF33* p) {
  if (p->count98 != 0) {
    s32 start = Mod(gFrameCounter, p->count98);
    u32 mask = p->mask74;
    s32 i;

    for (i = 0; i < 4; i++) {
      s32 j;

      *(gStat->registeredMagic + i) = -1;
      for (j = start; j < start + 16; j++) {
        s32 k = j & 15;

        if (mask & (1 << k)) {
          *(gStat->registeredMagic + i) = p->unk_98[k];
          mask &= ~(1 << k);
          start = j;
          break;
        }
      }
      start += Random() & 15;
    }
  }
}

// 装備中の武器が登録されていればそのスロットの使用済みビットを外す
// 間の空ループは原典のまま, agbcc は -O2 でも体が無いループを消さない
void FUN_0804fe24(EntityAF33* p) {
  s32 slot = REGISTERED_WEAPON(gStat->equippedWeaponIdx);
  s32 i;

  if (slot < 0) {
    return;
  }

  for (i = 0; i < 4; i++) {
  }

  if (GetWeaponID(slot) != WEAPON_NONE) {
    p->mask70 &= ~(1 << slot);
  }
}

// 装備中の魔法と同じIDの枠を使用済みビットから外す
void FUN_0804fe68(EntityAF33* p) {
  s32 id = *(gStat->registeredMagic + gStat->equippedMagicIdx);
  s32 i;

  if (id < 0) {
    return;
  }
  for (i = 0; i < 16; i++) {
    if (p->unk_98[i] == id) {
      p->mask74 &= ~(1 << i);
    }
  }
}

void FUN_0803cb24(void);
void FUN_0803cb4c(u32 val);
void FUN_0803cb6c(u32 val);
void FUN_0803cbb4(u32 val);
void FUN_0803cc54(u32 val);

// 溜めてあった4つの値をそれぞれの受け取り手に流してから捨てる
void FUN_0804feb0(EntityAF33* p) {
  s32 i;

  FUN_0803cb24();

  for (i = 0; i < 4; i++) {
  }

  if (p->unk_38[0] != 0) {
    FUN_0803cb4c(p->unk_38[0]);
    p->unk_38[0] = 0;
  }

  if (p->unk_38[1] != 0) {
    FUN_0803cb6c(p->unk_38[1]);
    p->unk_38[1] = 0;
  }

  if (p->unk_38[2] != 0) {
    FUN_0803cbb4(p->unk_38[2]);
    p->unk_38[2] = 0;
  }

  if (p->unk_38[3] != 0) {
    FUN_0803cc54(p->unk_38[3]);
    p->unk_38[3] = 0;
  }
}

void FUN_0804ff10(EntityAF33* p) {
  if (p->stateBegun) {
    u32 data;

    p->stateBegun = FALSE;
    MosaicFader_Stop();
    FUN_0804fb04(p, 1);
    data = 0;
    FUN_0804fa44(p, 1, &data, 1);
    SET_FLAGS(gEntityDisableFlags, ENTITY_DISABLE_2);
    FUN_0804fbd0(p, 1);
  }
  if (TEST_FLAGS(p->unk_20, 0x80)) {
    HUD_RemoveCountdown();
    EntityAF33_SetState(p, 6);
    FUN_0804fbe0(p);
  } else if (TEST_FLAGS(p->unk_20, 3) == 3) {
    p->unk_20 &= ~3;
    EntityAF33_SetState(p, 1);
    FUN_0804fbe0(p);
  } else {
    p->stateTimer++;
  }
}

void FUN_0804ffa8(EntityAF33* p) {
  if (p->stateBegun) {
    p->stateBegun = FALSE;
    FUN_0804fc08(p);
    FUN_0804fd3c(p);
    p->unk_1b8 = 0;
    FUN_0808e420();
    FUN_08051bb0(FUN_0804fb24, p->slots[0].unk_00);
    p->unk_33 = 0;
    p->unk_31 = 8;
    FUN_0804fbd0(p, 2);
  }
  if (gInput[0].pressed & START_BUTTON) {
    p->unk_1b8 = 1;
    p->unk_31 = 8;
  }
  if (p->unk_33 != 0 && p->stateTimer > 16 && p->unk_1b8 != 0) {
    if (p->unk_31 == 0) {
      PlaySound_082406e0(SE_SELECT);
      EntityAF33_SetState(p, 2);
      FUN_0808e4f4();
      FUN_0804fbe0(p);
      return;
    }
    p->unk_31--;
  }
  p->stateTimer++;
}

// 残差: unk_20 の 0xC を落とすところで, 原典は ~0xC を作ってから unk_20 を読み直す (CLEAR_FLAGS だと判定の 0xC と共有されて bics になる)
NON_MATCH void FUN_08050070(EntityAF33* p) {
#ifdef NONMATCHING_C
  if (p->stateBegun) {
    EntityAF33Slot* a;
    u32 data;
    s32 shift;
    s32 i;

    p->stateBegun = FALSE;
    a = &p->slots[0];
    shift = 0;
    data = a->unk_04[2] << 16;
    for (i = 0; i < 4; i++, shift += 4) {
      data |= a->unk_00[i] << shift;
    }
    FUN_0804fa44(p, 2, &data, 1);
    FUN_0804fbd0(p, 1);
    FUN_0804fe24(p);
    FUN_0804fe68(p);
  }
  if (TEST_FLAGS(p->unk_20, 0xC) == 0xC) {
    FUN_0804f97c(p);
    p->unk_20 &= ~0xC;
    EntityAF33_SetState(p, 3);
    FUN_0804fbe0(p);
  } else {
    p->stateTimer++;
  }
#else
  INCFUNC("asm/func/FUN_08050070.inc");
#endif
}

void FUN_0805010c(EntityAF33* p) {
  if (p->stateBegun) {
    s32 result;

    p->stateBegun = FALSE;
    result = FUN_0804fa04(p);
    if (result != 0) {
      p->unk_2a[2] = 1;
      p->unk_33 = 0;
      if (FUN_08051c50(FUN_0804fb24, p->slots[0].unk_00, p->slots[1].unk_00, p->unk_38)) {
        p->unk_33 = 1;
      }
    } else {
      u32 data;

      p->unk_2a[2] = result;
      data = result;
      FUN_0804fa44(p, 3, &data, 1);
    }
  }
  if (p->unk_2a[2] != 0 && p->unk_33 != 0) {
    u32 data = 0;

    FUN_0804fa44(p, 3, &data, 1);
    p->unk_33 = 0;
  }
  if (TEST_FLAGS(p->unk_20, 0x30) == 0x30) {
    p->unk_20 &= ~0x30;
    EntityAF33_SetState(p, 4);
  } else {
    p->stateTimer++;
  }
}

// クロスオーバーバトルで、 自分（ロックマン) と 相手（シェードマン) のアイコンをHPに応じて切り替える
void FUN_080501c8(EntityAF33* p) {
  s32 n = FUN_08050d64();
  s32 idx = 0;

  if (n <= 60) {
    idx = 2;
    if (n > 25) {
      idx = 1;
    }
  }
  MainSprite_SetPose(&p->sprites[0], &p->iconGfx, ICON_MEGAMAN(idx), PLAYMODE_PAUSE);

  n = FUN_08050d7c();
  idx = 0;
  if (n <= 60) {
    idx = 2;
    if (n > 25) {
      idx = 1;
    }
  }
  MainSprite_SetPose(&p->sprites[1], &p->iconGfx, ICON_SHADEMAN(idx), PLAYMODE_PAUSE);
}

void FUN_08050218(EntityAF33* p) {
  if (p->stateBegun) {
    p->stateBegun = FALSE;
    if (++p->unk_1e > 98) {
      p->unk_1e = 99;
    }
    if (p->unk_1e == 11) {
      FUN_0803cc70();
    }
    FUN_0804fb04(p, 0);
    FUN_0804fbd0(p, 3);
  }
  if (p->unk_1e == 11 && p->stateTimer == 20) {
    Sound_FadeOutBGM(4);
  }
  if (p->stateTimer > 89) {
    EntityAF33_SetState(p, 5);
    CLEAR_FLAGS(gEntityDisableFlags, ENTITY_DISABLE_2);
    FUN_0804fbe0(p);
  } else {
    p->stateTimer++;
  }
}

// 対戦中, 1 秒ごとに双方の体力の割合を送り, 決着か時間切れで次の state へ移る
void FUN_080502a8(EntityAF33* p) {
  if (p->stateBegun) {
    p->stateBegun = FALSE;
    p->unk_1c = 720;
    HUD_StartCountdown(&p->unk_1c);
    FUN_0804fbd0(p, 4);
    FUN_0804feb0(p);
    if (p->unk_1e == 11) {
      sound_08240264(BGM_MMBN5);
    } else if (p->unk_1e == 1) {
      sound_08240264(BGM_SHADEMAN);
    }
    p->unk_37 = 1;
  }
  FUN_080501c8(p);
  if (p->stateTimer == 30) {
    FUN_0804fbe0(p);
  }
  if (Mod(p->stateTimer, 60) == 0) {
    Player* player = gPlayerPtr[0];
    Boss* boss = Boss_Get(BOSS_SHADEMAN_CROSSOVER);
    s32 playerRate;
    s32 bossRate;
    u32 data;

    playerRate = (player != NULL && player->maxHP != 0) ? Div(player->hp * 100, player->maxHP) : 0;
    if (playerRate == 0 && player->hp != 0) {
      playerRate = 1;
    }
    bossRate = (boss != NULL && boss->maxHP > 0) ? Div(boss->hp * 100, boss->maxHP) : 0;
    if (bossRate == 0 && boss->hp > 0) {
      bossRate = 1;
    }
    data = (bossRate << 8) | playerRate;
    FUN_0804fa44(p, 0, &data, 1);
  }
  if ((*(u32*)&p->unk_2a[2] & 0xFFFF00) != 0 || TEST_FLAGS(p->unk_20, 0x80)) {
    HUD_RemoveCountdown();
    EntityAF33_SetState(p, 6);
  } else if (--p->unk_1c == 0) {
    FUN_0803ca14();
    HUD_RemoveCountdown();
    PlaySound_082406e0(SE_882);
    EntityAF33_SetState(p, 0);
    SET_FLAGS(gEntityDisableFlags, ENTITY_DISABLE_2);
    p->unk_37 = 0;
  } else {
    p->stateTimer++;
  }
}

void FUN_0805043c(EntityAF33* p) {
  if (p->stateBegun) {
    EntityAF33Slot* a;
    u32 data;

    p->stateBegun = FALSE;
    MosaicFader_Stop();
    FUN_0804fb3c(p);
    a = &p->slots[0];
    data = (u16)a->unk_08 | ((a->unk_04[3] & 3) << 16);
    FUN_0804fa44(p, 4, &data, 1);
    FUN_0804fbd0(p, 5);
    Sound_FadeOutBGM(4);
    if (!TEST_FLAGS(gPlayerStates[0], FLAG03002BC0_UNK_2)) {
      Player_Lock(gPlayerPtr[0], -1);
    }
  }
  if (p->stateTimer > 29 && TEST_FLAGS(p->unk_20, 0xC0) == 0xC0) {
    p->unk_20 &= ~0xC0;
    EntityAF33_SetState(p, 7);
  } else {
    p->stateTimer++;
  }
}

void FUN_080504e0(EntityAF33* p) {
  if (p->stateBegun) {
    u32 result;

    p->stateBegun = FALSE;
    p->unk_2f = FUN_0804fa94(p);
    result = p->unk_2f;
    FUN_0804fa44(p, 5, &result, 1);
    SET_FLAGS(gEntityDisableFlags, ENTITY_DISABLE_2);
  }
  if (TEST_FLAGS(p->unk_20, 0x300) == 0x300) {
    p->unk_20 &= ~0x300;
    EntityAF33_SetState(p, 8);
  } else {
    p->stateTimer++;
  }
}

// 120フレームごとに state を 9 にして FUN_0804fbe0 を呼ぶ
// 120 フレーム待ってから state 9 へ移り, FUN_0804fbe0 を呼ぶ
void FUN_08050558(EntityAF33* p) {
  if (p->stateBegun) {
    p->stateBegun = FALSE;
  }
  if (p->stateTimer > 119) {
    FUN_0804e5e8();
    EntityAF33_SetState(p, 9);
    FUN_0804fbe0(p);
  } else {
    p->stateTimer++;
  }
}

void FUN_08050598(EntityAF33* p) {
  if (p->stateBegun) {
    s32 base;
    s32 framesA;
    s32 framesB;
    s32 i;

    p->stateBegun = FALSE;
    p->unk_34 = 0;
    base = (p->unk_1e - 1) * 720;
    framesA = base + p->slots[0].unk_08;
    framesB = base + p->slots[1].unk_08;
    Entity723E_Setup(FUN_0804e458(), p->unk_2f, framesA, framesB, p->unk_c8, GetCrossoverPoint(), FUN_0804fbf0);
    for (i = 0; i < 2; i++) {
      p->sprites[i].flags |= SPRFLAG_HIDDEN;
    }
  }
  if (p->unk_34 != 0) {
    s32* windowID = &p->windowID;

    EntityAF33_SetState(p, 10);
    p->retryCount = 0;
    FUN_0804fb6c(p, 3);
    *windowID = TextPanel_Create(1, 7, 28, 6);
    if (*windowID >= 0) {
      TextPanel_SetScript(*windowID, p->script);
      TextPanel_SetMessage(*windowID, 11);
      TextPanel_Start(*windowID);
    }
  }
}

// 獲得ポイントを足してセーブし, 結果のメッセージを出す, 失敗したら2回までやり直す
void FUN_08050674(EntityAF33* p) {
  s32* windowID = &p->windowID;

  if (p->stateBegun) {
    s32 point;

    p->stateBegun = FALSE;
    point = GetCrossoverPoint() + p->unk_c8;
    if (point > 9999) {
      point = 9999;
    } else if (point < 0) {
      point = 0;
    }
    gSystemSaveData->crossoverPoint = point;
  }
  if (p->stateTimer == 60) {
    p->saveResult = Save_WriteSystemData();
    if (p->saveResult == TRUE) {
      TextPanel_SetMessage(*windowID, 14);
      PlaySound_082406e0(SE_SAVE_SUCCESS);
    } else {
      TextPanel_SetMessage(*windowID, 15);
      PlaySound_082406e0(SE_NG);
    }
  }
  if (p->stateTimer == 180) {
    if (p->saveResult == TRUE || ++p->retryCount > 2) {
      EntityAF33_SetState(p, 11);
    } else {
      TextPanel_SetMessage(*windowID, 11);
      EntityAF33_SetState(p, 10);
    }
  } else {
    p->stateTimer++;
  }
}

void FUN_08050754(EntityAF33* p) {
  if (p->stateBegun) {
    p->stateBegun = FALSE;
    FUN_0823ce68(3, 3, 0, 0, 0, 0xFFFF, 0);
  }
  if (p->stateTimer == 10) {
    MainMenu_SetHudMode(7);
  } else if (p->stateTimer > 20) {
    if (p->stateTimer == 40) {
      FUN_0804e604();
    }
    if (FUN_0804ba3c() == NULL) {
      p->unk_c0 = 1;
      return;
    }
  }
  p->stateTimer++;
}

void (*const PTR_ARRAY_085ab6a4[12])(EntityAF33*) = {
    FUN_0804ff10,
    FUN_0804ffa8,
    FUN_08050070,
    FUN_0805010c,
    FUN_08050218,
    FUN_080502a8,
    FUN_0805043c,
    FUN_080504e0,
    FUN_08050558,
    FUN_08050598,
    FUN_08050674,
    FUN_08050754,
};  // 0x085AB6A4

s32 EntityAF33_Update(EntityAF33* p) {
  if (p->unk_c0 != 0) {
    p->unk_c0 = 0;
    MainMenu_SetHudMode(7);
    Video_SetDrawPasses(0, Particle_DrawList, AuxSprite_DrawList, MainSprite_DrawList);
    if (p->unk_c4 != 0) {
      VM_ExecByID(p->unk_c4, NULL);
    }
    KillEntity(&p->e);
  } else {
    s32 busy = FUN_0804e59c();

    if (busy == 0) {
      PTR_ARRAY_085ab6a4[p->state](p);
      if (p->unk_2a[0] != 0 && FUN_0804e514(&p->slots[2]) >= 0) {
        p->unk_2a[0] = busy;
      }
    }
  }
  return 0;
}

s32 EntityAF33_Destroy(EntityAF33* p) {
  s32 i;

  for (i = 0; i < 2; i++) {
    MainSprite_Remove(&p->sprites[i]);
  }

  TextPanel_Destroy(p->windowID);
  gEntityAF33 = NULL;
  return 0;
}

// 残差: 471 対 446 命令, 原典は後半で0を書くフィールドのアドレスを最初のループの前に作ってスタックへ逃がす, ループの形も未調整
NON_MATCH s32 EntityAF33_Init(EntityAF33* p) {
#ifdef NONMATCHING_C
  u8 magic[16];
  Vec3 pos;
  MainSpriteGfxFile* f;
  s32 i;

  gEntityAF33 = p;
  p->unk_c4 = VM_GetNamedArgValue('e', 0);
  p->count78 = 0;
  p->mask70 = 0;
  if (VM_SeekToNamedArg('w')) {
    for (i = 0; i < 16; i++) {
      if (VM_GetPC() != NULL) {
        p->unk_78[i] = VM_GetValue();
        p->count78++;
      } else {
        p->unk_78[i] = 0;
      }
    }
  } else {
    for (i = 15; i >= 0; i--) {
      p->unk_78[i] = 0;
    }
  }
  if (p->count78 != 0) {
    u8 r = gFrameCounter;
    u32 n;

    for (n = 0; n < p->count78; n++) {
      s32 k = r & 15;

      while (p->mask70 & (1 << k)) {
        k = r & 15;
        r++;
      }
      p->mask70 |= 1 << k;
      SetWeaponData(k, FUN_0823d414(p->unk_78[n]));
      r += Random() & 0xFF;
    }
  }
  p->count98 = 0;
  p->mask74 = 0;
  if (VM_SeekToNamedArg('m')) {
    for (i = 0; i < 16; i++) {
      if (VM_GetPC() != NULL) {
        magic[i] = VM_GetValue();
        p->count98++;
      } else {
        magic[i] = 0;
      }
    }
  } else {
    for (i = 15; i >= 0; i--) {
      magic[i] = 0;
    }
  }
  if (p->count98 != 0) {
    u8 r = gFrameCounter;
    u32 n;

    for (n = 0; n < p->count98; n++) {
      s32 k = r & 15;

      while (p->mask74 & (1 << k)) {
        k = r & 15;
        r++;
      }
      p->mask74 |= 1 << k;
      p->unk_98[k] = magic[n];
      r += Random() & 0xFF;
    }
  }
  p->unk_18 = 0;
  p->unk_1c = 0;
  p->unk_1e = 0;
  p->unk_20 = 0;
  p->unk_2a[1] = 0;
  p->unk_2a[2] = 0;
  p->unk_2d = 0;
  p->unk_33 = 0;
  p->unk_32 = 1;
  p->state = 0;
  p->stateBegun = TRUE;
  p->stateTimer = 0;
  FUN_0804e4dc(FUN_0804f8ec, FUN_0804f82c, FUN_0804f950, FUN_0804f970);
  for (i = 0; i < 2; i++) {
    s32 j;

    for (j = 3; j >= 0; j--) {
      p->slots[i].unk_00[j] = 0;
    }
    p->slots[i].unk_04[0] = 100;
    p->slots[i].unk_04[1] = 100;
    p->slots[i].unk_04[2] = 0;
    p->slots[i].unk_04[3] = 0;
    p->slots[i].unk_08 = 0;
  }
  for (i = 3; i >= 0; i--) {
    p->unk_38[i] = 0;
  }
  FUN_0804fb04(p, 0);
  FUN_0804fb04(p, 1);
  Entity08051b70_Create(0, 0);
  p->unk_60 = CrossoverMC_Create();
  p->unk_64 = Entity08052ffc_Create();
  SignalStrengthIcon_CreateAt(4, 24);
  if (!VM_SeekToNamedArg('s')) {
    return -1;
  }
  p->script = VM_GetPC_Proxy();
  if (p->script == NULL) {
    return -1;
  }
  p->unk_c8 = 0;
  p->unk_1ac = VM_GetNamedArgValue('M', 11);
  if (!VM_SeekToNamedArg('p')) {
    return -1;
  }
  for (i = 0; i < 4; i++) {
    p->unk_1ae[i] = VM_GetValue();
  }
  f = GetFile(DIR_MAIN_SPRITE, SPRITE_INVENTORY_ICONS);
  if (f == NULL) {
    return -1;
  }
  p->iconGfx = *f;
  OpenMainSpriteFile(&p->iconGfx, f);
  for (i = 0; i < 2; i++) {
    u16 pose;

    if (i == 0) {
      pos.x = 132;
      pose = 0xD4;
    } else {
      pos.x = 220;
      pose = 0xD7;
    }
    pos.y = 24;
    pos.z = 0;
    MainSprite_Add(&p->sprites[i], &p->iconGfx, pose, SPRFLAG_UNK_16 | SPRFLAG_SCREEN_COORD, 0, 0, 60, &pos);
  }
  return 0;
#else
  INCFUNC("asm/func/EntityAF33_Init.inc");
#endif
}

EntityAF33* EntityAF33_Create(void) {
  EntityAF33* p = CreateEntity(ENTITY_UNK_2, sizeof(EntityAF33));
  if (p != NULL) {
    SetEntityRoutine(p, EntityAF33_Update, EntityAF33_Destroy);
    if (EntityAF33_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

// kind の持ち数が 4 以下で合計が 9 以下なら1つ増やして pos に出す
void FUN_08050cb8(Vec3* pos, u32 kind) {
  EntityAF33* p = FUN_0804f820();
  u8* counts;
  s32 sum;
  s32 i;

  if (p == NULL) {
    return;
  }
  counts = p->slots[0].unk_00;
  if (counts[kind] > 4) {
    return;
  }
  sum = 0;
  for (i = 0; i < 4; i++) {
    sum += counts[i];
  }
  if (sum > 9) {
    return;
  }
  FUN_08051d18(pos, kind, 1);
  counts[kind]++;
  FUN_08050e50(2, 1);
  PlaySound_082406e0(SONG_885);
}

void FUN_08050d10(void) {
  EntityAF33* p = FUN_0804f820();

  if (p != NULL) {
    p->unk_2d = 1;
  }
}

void FUN_08050d28(void) {
  EntityAF33* p = FUN_0804f820();

  if (p != NULL) {
    p->unk_2e = 1;
  }
}

s32 FUN_08050d40(void) {
  EntityAF33* p = FUN_0804f820();

  if (p == NULL || p->unk_30 == 0) {
    return FALSE;
  }
  p->unk_30 = 0;
  return TRUE;
}

s32 FUN_08050d64(void) {
  EntityAF33* p = FUN_0804f820();
  EntityAF33Slot* slot;

  if (p == NULL) {
    return 0;
  }
  slot = &p->slots[1];
  return slot->unk_04[0];
}

s32 FUN_08050d7c(void) {
  EntityAF33* p = FUN_0804f820();
  EntityAF33Slot* slot;

  if (p == NULL) {
    return 0;
  }
  slot = &p->slots[1];
  return slot->unk_04[1];
}

s32 FUN_08050d94(void) {
  EntityAF33* p = FUN_0804f820();

  if (p == NULL) {
    return 0;
  }
  return p->unk_32;
}

s32 FUN_08050dac(void) {
  EntityAF33* p = FUN_0804f820();

  if (p != NULL && p->unk_1e != 0 && p->unk_32 != 0) {
    EntityAF33Slot* slot = &p->slots[0];

    slot->unk_04[2] = 1 - slot->unk_04[2];
    PlaySound_082406e0(SE_QUICK_CHANGE);
    return slot->unk_04[2];
  }
  return 0;
}

s32 FUN_08050de8(void) {
  EntityAF33* p = FUN_0804f820();

  if (p == NULL) {
    return 0;
  }
  return p->unk_1e;
}

s32 FUN_08050dfc(void) {
  EntityAF33* p = FUN_0804f820();

  if (p == NULL || p->unk_1e <= 10) {
    return FALSE;
  }
  return TRUE;
}

// 0x877F
void Cmd_877F(void) { gGameFlags |= FLAG030047A4_UNK_12; }

void FUN_08050e2c(u32 idx, u32 mode, Vec3* pos) {
  EntityAF33* p = FUN_0804f820();

  if (p != NULL) {
    Entity08052ffc_Spawn(p->unk_64, idx, mode, pos);
  }
}

void FUN_08050e50(u32 param_1, u32 param_2) {
  EntityAF33* p = FUN_0804f820();

  if (p != NULL) {
    p->unk_c8 += p->unk_1ae[param_1] * param_2;
  }
}

s32 FUN_08050e80(void) {
  EntityAF33* p = FUN_0804f820();

  if (p == NULL || p->state != 5) {
    return FALSE;
  }
  return TRUE;
}
