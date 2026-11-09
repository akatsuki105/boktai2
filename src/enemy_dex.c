#include "bg_pltt.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "input.h"
#include "preview_stage.h"
#include "sound.h"
#include "sprite.h"
#include "text.h"
#include "video.h"
#include "vm.h"

// EnemyDexMenu.flags
typedef u16 EnemyDexFlags16;
#define EDEXFLAG_UNK_0 (1 << 0)  // 0x1, 立っていると unk_1 系, 落ちていると unk_3 系の処理に進む
#define EDEXFLAG_UNK_1 (1 << 1)  // 0x2
#define EDEXFLAG_UNK_2 (1 << 2)  // 0x4
#define EDEXFLAG_UNK_3 (1 << 3)  // 0x8

// _Init が '.t' から4バイトずつ57件読む
typedef struct {
  u8 unk_0;  // 0x00
  u8 unk_1;  // 0x01
  u8 unk_2;  // 0x02
  u8 unk_3;  // 0x03
} EnemyDexEntry;
static_assert(sizeof(EnemyDexEntry) == 4);

// 魔物図鑑
typedef struct {
  Entity e;                      // 0x0000, ENTITY_UNK_8
  Tilemaps* tilemap;             // 0x0018, TILEMAP_4F8F
  rgb555* pltt;                  // 0x001C, BGP_A41A
  u32 unk_20;                    // 0x0020, _Init が 0
  u8 unk_24;                     // 0x0024, _Init が 0
  u8 page;                       // 0x0025, 選択中のページ (0..8), EnemyDexMenu_SetPageFromEntry が entryIdx から決める
  u8 entryIdx;                   // 0x0026, 選択中のエントリ番号 (0..56)
  u8 unk_27;                     // 0x0027
  s32 panels[8];                 // 0x0028, TextPanel_Create の戻り値 (ID), TextPanel_Hide などに渡す
  u8 row;                        // 0x0048, ページ内の行 (entryIdx - ページ先頭), カーソルの Y 位置になる
  u8 unk_49;                     // 0x0049, _Init が 0x20
  u8 unk_4a;                     // 0x004A, _Init が 0
  u8 unk_4b;                     // 0x004B
  MainSpriteGfx gfx;             // 0x004C, MainSprite_SetNumber に渡す数字のスプライト
  MainSprite sprites_6c[3];      // 0x006C
  MainSprite sprites_18c[5];     // 0x018C, 根拠: FUN_0820d6e4 が5枚ぶん登録し FUN_0820ee7c が5枚ぶん隠す
  MainSprite sprites_36c[3];     // 0x036C, 根拠: FUN_0820ee7c が3枚ぶん隠す
  MainSprite sprites_48c[3];     // 0x048C, 根拠: EnemyDexMenu_Destroy が3枚ぶん外す
  MainSprite sprites_5ac[7];     // 0x05AC, 根拠: FUN_0820eb38 が7枚ぶん flags を触る
  MainSprite sprites_84c[7][2];  // 0x084C, 根拠: 同上, ページ7つ×2枚
  MainSprite sprites_d8c[9];     // 0x0D8C, 根拠: EnemyDexMenu_HideSprites が 0xD94 と 0xE54 から 0x60 刻みで flags を触り, FUN_0820d138 が [7]/[8] の pos を書く
  u8 unk_10ec[0x1104 - 0x10EC];  // 0x10EC
  u16 unk_1104;                  // 0x1104, timer_110c の位置から決まる値 (31/27/18/10)
  u8 unk_1106[0x110C - 0x1106];  // 0x1106
  s16 timer_110c;                // 0x110C, FUN_0820d690 が 0..49 で回す
  EnemyDexFlags16 flags;         // 0x110E, see EnemyDexFlags16, _Init が 5
  void* scriptN;                 // 0x1110, '.n', TextPanel_SetScript に渡す
  u8 unk_1114[57];               // 0x1114, '.d' の VM_GetValue を57バイト
  u8 unk_114d[3];                // 0x114D
  EnemyDexEntry entries[57];     // 0x1150, '.t'
  void* scriptI;                 // 0x1234, '.i'
  void* scriptP;                 // 0x1238, '.p'
  void* scriptS;                 // 0x123C, '.s'
  void* scriptW;                 // 0x1240, '.w'
  void* scriptA_upper;           // 0x1244, '.A'
  void* scriptA;                 // 0x1248, '.a'
  void* scriptM;                 // 0x124C, '.m'
  void* scriptU;                 // 0x1250, '.u'
  void* scriptT_upper;           // 0x1254, '.T'
  u32 unk_1258;                  // 0x1258, '.e=0'
  PreviewStage* sub;             // 0x125C, PreviewStage_Create(0, 0) の戻り値
} EnemyDexMenu;
static_assert(sizeof(EnemyDexMenu) == 4704);

static inline void EnemyDexMenu_HidePageSprites(EnemyDexMenu* p) {
  s32 i;
  s32 j;

  for (i = 0; i < 7; i++) {
    for (j = 0; j < 2; j++) {
      p->sprites_84c[i][j].flags |= SPRFLAG_HIDDEN;
    }
    p->sprites_5ac[i].flags |= SPRFLAG_HIDDEN;
  }
}

// UIスプライトを全部隠す
static inline void EnemyDexMenu_HideCursorSprites(EnemyDexMenu* p) {
  s32 i;

  for (i = 0; i < 5; i++) {
    p->sprites_18c[i].flags |= SPRFLAG_HIDDEN;
  }
  for (i = 0; i < 3; i++) {
    p->sprites_36c[i].flags |= SPRFLAG_HIDDEN;
  }
}

s32 EnemyDex_GetPageStart(u32 page) {
  // ページの先頭エントリ番号 (sEnemyDexPageEntryCounts の累積和)
  static const s32 sEnemyDexPageStarts[9] = {0, 7, 14, 21, 27, 34, 41, 48, 50};  // 0x085AF034
  return sEnemyDexPageStarts[page];
}

s32 EnemyDex_GetPageEntryCount(u32 page) {
  // ページごとのエントリ数(ビースト1,ビースト2,ビースト3,アンデット,シング1,シング2,ファントム1,ファントム2,イモータル), 合計57
  static const s32 sEnemyDexPageEntryCounts[9] = {7, 7, 7, 6, 7, 7, 7, 2, 7};  // 0x085AF058
  return sEnemyDexPageEntryCounts[page];
}

s32 EnemyDex_GetCategoryEntryCount(u32 category) {
  // 種族ごとのエントリ数 (ビースト,アンデット,シング,ファントム,イモータル)
  static const s32 sEnemyDexCategoryCounts[5] = {21, 6, 14, 9, 7};  // 0x085AF07C
  return sEnemyDexCategoryCounts[category];
}

// 種族 category の先頭エントリ番号 (それより前の種族のエントリ数の合計)
s32 EnemyDex_GetCategoryStart(s32 category) {
  s32 start = 0;
  s32 i;

  for (i = 0; i < category; i++) {
    start += EnemyDex_GetCategoryEntryCount(i);
  }
  return start;
}

void EnemyDexMenu_SetPageFromEntry(EnemyDexMenu* p) {
  s32 i;

  for (i = 0; i < 9; i++) {
    if (p->entryIdx < EnemyDex_GetPageStart(i)) {
      p->page = i - 1;
      p->row = p->entryIdx - EnemyDex_GetPageStart(p->page);
      return;
    }
  }

  p->page = 8;
  p->row = p->entryIdx - EnemyDex_GetPageStart(p->page);
}

// エントリ番号が属する種族 (0:ビースト 1:アンデット 2:シング 3:ファントム 4:イモータル)
s32 EnemyDex_GetCategoryOfEntry(s32 entryIdx) {
  if (entryIdx < EnemyDex_GetPageStart(3)) {
    return 0;
  }
  if (entryIdx < EnemyDex_GetPageStart(4)) {
    return 1;
  }
  if (entryIdx < EnemyDex_GetPageStart(6)) {
    return 2;
  }
  if (entryIdx < EnemyDex_GetPageStart(8)) {
    return 3;
  } else {
    return 4;
  }
}

/**
 * @brief 敵の種別と変種から魔物図鑑のエントリ番号を返す, 該当するものが無ければ -1
 * @param kind 敵の種別 (Enemy.kind)
 * @param variant 敵の変種 (Enemy.variant)
 */
s32 EnemyDex_GetEntryIdx(u32 kind, s32 variant) {
  switch (kind) {
    case ENEK_MUMMY: {
      switch (variant) {
        case EV_MUMMY:
          return ENEID_MUMMY;
        case EV_GAST:
          return ENEID_GAST;
        case EV_MUMMY_P:
          return ENEID_MUMMY_P;
      }
      break;
    }
    case ENEK_SPIDER: {
      switch (variant) {
        case EV_SPIDER:
          return ENEID_SPIDER;
        case EV_PSPIDER:
          return ENEID_PSPIDER;
        case 2:
          return ENEID_SPIDER;
      }
      break;
    }
    case ENEK_GOLEM: {
      switch (variant) {
        case EV_GOLEM_C:
          return ENEID_GOLEM_C;
        case EV_GOLEM_S:
          return ENEID_GOLEM_S;
        case EV_GOLEM_P:
          return ENEID_GOLEM_P;
      }
      break;
    }
    case ENEK_BOKU: {
      switch (variant) {
        case EV_GHOUL:
          return ENEID_GHOUL;
        case EV_ZOMBIE:
          return ENEID_ZOMBIE;
        case EV_GHOUL_P:
          return ENEID_GHOUL_P;
      }
      break;
    }
    case ENEK_SKELETON: {
      switch (variant) {
        case EV_SKELETON:
          return ENEID_SKELETON;
        case EV_SKELETON_P:
          return ENEID_SKELETON_P;
      }
      break;
    }
    case ENEK_SKELETON_F: {
      return ENEID_SKELETON_F;
    }
    case ENEK_SKELETON_A: {
      return ENEID_SKELETON_A;
    }
    case ENEK_LICH: {
      switch (variant) {
        case EV_LICH:
          return ENEID_LICH;
        case EV_LICH_P:
          return ENEID_LICH_P;
      }
      break;
    }
    case ENEK_CENTIPEDE: {
      return ENEID_CENTIPEDE;
    }
    case ENEK_COCKA: {
      switch (variant) {
        case EV_COCKA:
          return ENEID_COCKA;
        case EV_COCKA_P:
          return ENEID_COCKA_P;
      }
      break;
    }
    case ENEK_MIMIC: {
      return ENEID_MIMIC;
    }
    case ENEK_SWORD: {
      switch (variant) {
        case EV_WEAPON:
          return ENEID_SWORD;
        case EV_WEAPON_P:
          return ENEID_SWORD_P;
      }
      break;
    }
    case ENEK_AX: {
      switch (variant) {
        case EV_WEAPON:
          return ENEID_AX;
        case EV_WEAPON_P:
          return ENEID_AX_P;
      }
      break;
    }
    case ENEK_OCTOPUS: {
      return ENEID_OCTOPUS;
    }
    case ENEK_CURORO: {
      switch (variant) {
        case EV_CURORO:
          return ENEID_CURORO;
        case EV_CURORO_F:
          return ENEID_CURORO_F;
        case EV_CURORO_I:
          return ENEID_CURORO_I;
      }
      break;
    }
    case ENEK_BAT: {
      switch (variant) {
        case EV_BAT:
          return ENEID_BAT;
        case EV_VBAT:
          return ENEID_VBAT;
        case 2:
          return ENEID_BAT;
      }
      break;
    }
    case ENEK_CROW: {
      switch (variant) {
        case EV_CROW:
          return ENEID_CROW;
        case EV_GARGOYLE:
          return ENEID_GARGOYLE;
        case 2:
          return ENEID_CROW;
      }
      break;
    }
    case ENEK_BEE: {
      switch (variant) {
        case EV_BEE:
          return ENEID_BEE;
        case EV_KBEE:
          return ENEID_KBEE;
        case EV_PBEE:
          return ENEID_PBEE;
      }
      break;
    }
    case ENEK_DOG: {
      switch (variant) {
        case EV_BANDIT:
          return ENEID_BANDIT;
        case EV_GRAVEKEEPER:
          return ENEID_GRAVEKEEPER;
        case EV_HELLHOUND:
          return ENEID_HELLHOUND;
        case EV_BANDIT_P:
          return ENEID_BANDIT_P;
      }
      break;
    }
    case ENEK_SLIME: {
      switch (variant) {
        case EV_SLIME_Y:
          return ENEID_SLIME_Y;
        case EV_SLIME_G:
          return ENEID_SLIME_G;
        case EV_SLIME_P:
          return ENEID_SLIME_P;
        case EV_SLIME_B:
          return ENEID_SLIME_B;
      }
      break;
    }
    case ENEK_GHOST: {
      switch (variant) {
        case EV_GHOST:
          return ENEID_GHOST;
        case EV_WRAITH:
          return ENEID_WRAITH;
      }
      break;
    }
    case ENEK_DARKROOT: {
      return ENEID_DARKROOT;
    }
    case ENEK_SANDWORM: {
      return ENEID_SANDWORM;
    }
    case ENEK_SERPENT: {
      return ENEID_SERPENT;
    }
    case ENEK_SHAIAN: {
      return ENEID_SHAIAN;
    }
    case ENEK_0:
    case ENEK_15:
    case ENEK_16:
    case ENEK_28:
    case ENEK_29:
    case ENEK_30:
    case ENEK_31: {
      break;
    }
  }
  return -1;
}

// 魔物 id の種別 kind のフラグを立てる
// 残差はレジスタ番号の入れ替えのみ (18対18): 原典は gStat を r2, 0x390 を r3 に置き, 語索引に死んだ kind の r1 を使い回すが, agbcc は r3/r2 を逆に取り語索引も r2 に置く
// 兄弟の FUN_0820d04c と同じ壁. flags ローカルを無くす / 宣言順を入れ替える は試済 (どちらも gStat の読みと bit 計算の順が入れ替わって悪化)
NON_MATCH void EnemyDex_SetDropItemFlag(u32 id, u32 isRareDrop) {
#ifdef NONMATCHING_C
  u32* flags = gStat->enemyDexDrop;
  u32 bit = (id * 2) + isRareDrop;

  flags[bit >> 5] |= 1 << (bit & 31);
#else
  INCFUNC("asm/func/EnemyDex_SetDropItemFlag.inc");
#endif
}

// 0xA76D, '.k' と '.c' が指す魔物のドロップアイテムフラグ '.i' を立てる
void Cmd_SetEnemyDexDropItemFlag(void) {
  s32 kind = VM_SeekToNamedArg('k') ? VM_GetValue() : 0;
  s32 variant = VM_SeekToNamedArg('c') ? VM_GetValue() : 0;
  s32 idx = VM_SeekToNamedArg('i') ? VM_GetValue() : 0;  // 0: 通常ドロップ, 1: レアドロップ
  EnemyDex_SetDropItemFlag(EnemyDex_GetEntryIdx(kind, variant), idx);
}

// 0xD1C0, '.k' の魔物に出会ったことにする
void Cmd_SetEnemyDexSeenFlag(void) {
  s32 bit = VM_GetNamedArgValue('k', -1);

  if ((u32)bit <= 56) {
    if (bit <= 31) {
      gStat->enemyDexSeen[0] |= 1 << bit;
    } else {
      gStat->enemyDexSeen[1] |= 1 << (bit - 32);
    }
  }
}

// 魔物 bit に出会っているか
// 残差はレジスタ番号の入れ替えのみ (r2/r3 が逆, 命令列は 29 対 29)
NON_MATCH bool32 FUN_0820d00c(s32 bit) {
#ifdef NONMATCHING_C
  u32* seen = gStat->enemyDexSeen;

  if (seen[FixToInt(5, bit)] & (1 << (bit & 0x1F))) {
    return TRUE;
  }
  return FALSE;
#else
  INCFUNC("asm/func/FUN_0820d00c.inc");
#endif
}

// 魔物 id の種別 kind のフラグが立っているか
// 残差はレジスタ番号の入れ替えのみ (r2/r3 と r1/r2, 命令列は 24 対 24)
NON_MATCH bool32 FUN_0820d04c(u32 id, u32 kind) {
#ifdef NONMATCHING_C
  u32* flags = gStat->enemyDexDrop;
  u32 bit = id * 2 + kind;

  if (flags[bit >> 5] & (1 << (bit & 31))) {
    return TRUE;
  }
  return FALSE;
#else
  INCFUNC("asm/func/FUN_0820d04c.inc");
#endif
}

bool32 FUN_0820d084(u32 param_1) {
  s32 n = EnemyDex_GetCategoryEntryCount(param_1);
  s32 base = EnemyDex_GetCategoryStart(param_1);
  s32 i;

  for (i = 0; i < n; i++) {
    if (!FUN_0820d00c(base + i)) {
      return FALSE;
    }
  }
  return TRUE;
}

s32 FUN_0820d0b8(u32 param_1) {
  s32 n = EnemyDex_GetCategoryEntryCount(param_1);
  s32 base = EnemyDex_GetCategoryStart(param_1);
  s32 count = 0;
  s32 i;

  for (i = 0; i < n; i++) {
    if (FUN_0820d00c(base + i) == 1) {
      count++;
    }
  }
  return count;
}

// 57体すべてに出会っているか
// 残差はレジスタ番号の入れ替えのみ (大きいオフセットの一時値と加算先が r0/r1 で逆, 命令列は 23 対 23)
NON_MATCH bool32 FUN_0820d0ec(void) {
#ifdef NONMATCHING_C
  if (gStat->enemyDexSeen[0] == -1 && gStat->enemyDexSeen[1] == 0x01FFFFFF) {
    return TRUE;
  }
  return FALSE;
#else
  INCFUNC("asm/func/FUN_0820d0ec.inc");
#endif
}

void Cmd_A7CE(void) {
  if (VM_SeekToNamedArg('k')) {
    VM_GetValue();
  }
}

// スプライト [7]/[8] の表示位置を切り替える, unk_24 が 0 なら高さ 19, それ以外は原点
// 残差は CpuFill32 の引数を置く順の2命令だけ (33 対 33), 原典は add r1,sp,#4 が tmp の0代入より前で mov r0,sp が ldr r2,=0x05000002 より前
// Vec3 の3代入自体は static inline 経由にすれば一致する (直接代入すると x/y が1ワードに畳まれる) が, CpuFill32 側が動かないので見送り
NON_MATCH void FUN_0820d138(EnemyDexMenu* p) {
#ifdef NONMATCHING_C
  Vec3 pos;

  if (p->unk_24 == 0) {
    pos.x = 0, pos.y = 19, pos.z = 0;
  } else {
    CpuFill32(0, &pos, sizeof(pos));
  }

  p->sprites_d8c[7].pos = pos;
  p->sprites_d8c[8].pos = pos;
#else
  INCFUNC("asm/func/FUN_0820d138.inc");
#endif
}

// 全踏破フラグと現在のカテゴリの踏破状況でアイコン3枚の表示を切り替える
void FUN_0820d188(EnemyDexMenu* p) {
  if (FUN_0820d0ec()) {
    p->sprites_d8c[4].flags &= ~SPRFLAG_HIDDEN;
    p->sprites_d8c[5].flags &= ~SPRFLAG_HIDDEN;
  } else {
    p->sprites_d8c[4].flags |= SPRFLAG_HIDDEN;
    p->sprites_d8c[5].flags |= SPRFLAG_HIDDEN;
  }

  if (p->unk_24 == 2) {
    return;
  }

  if (p->unk_24 == 0 && FUN_0820d084(EnemyDex_GetCategoryOfEntry(p->entryIdx))) {
    p->sprites_d8c[6].flags &= ~SPRFLAG_HIDDEN;
  } else {
    p->sprites_d8c[6].flags |= SPRFLAG_HIDDEN;
  }
}

void FUN_0820d21c(EnemyDexMenu* p) {
  s32 i;

  for (i = 0; i < 8; i++) {
    TextPanel_Hide(p->panels[i]);
  }
  p->flags |= EDEXFLAG_UNK_0;
  ClearBGTilemapBuffer(0);
}

// 選んだエントリの名前を出し, unk_27 のタブに応じて説明, 分類, 落とすアイテムなどの欄を埋める
// 残差: 389 対 369 命令, 原典は欄ごとの SetScript/SetRect/SetMessage/Start の並びを末尾で共有して短くなっている, inline 化などは未試行
NON_MATCH void FUN_0820d250(EnemyDexMenu* p) {
#ifdef NONMATCHING_C
  bool32 seen = FUN_0820d00c(p->entryIdx);

  FUN_0820d21c(p);
  TextPanel_SetScript(p->panels[0], p->scriptN);
  TextPanel_SetRect(p->panels[0], 8, 3, 20, 2);
  if (FUN_0820d00c(p->entryIdx)) {
    TextPanel_SetMessage(p->panels[0], p->entryIdx);
  } else {
    TextPanel_SetMessage(p->panels[0], 57);
  }
  TextPanel_Start(p->panels[0]);
  switch (p->unk_27) {
    case 0: {
      if (seen) {
        s32 category = EnemyDex_GetCategoryOfEntry(p->entryIdx);

        TextPanel_SetScript(p->panels[1], p->scriptT_upper);
        TextPanel_SetRect(p->panels[1], 1, 16, 30, 4);
        TextPanel_SetMessage(p->panels[1], category);
        TextPanel_Start(p->panels[1]);
      }
      break;
    }
    case 1: {
      if (seen) {
        TextPanel_SetScript(p->panels[2], p->scriptA);
        TextPanel_SetRect(p->panels[2], 1, 16, 30, 4);
        TextPanel_SetMessage(p->panels[2], p->unk_1114[p->entryIdx]);
        TextPanel_Start(p->panels[2]);
      }
      break;
    }
    case 2: {
      if (seen) {
        p->flags = (p->flags & ~EDEXFLAG_UNK_0) | EDEXFLAG_UNK_3;
      } else {
        p->flags &= ~EDEXFLAG_UNK_0;
        Marquee_Clear();
      }
      break;
    }
    case 3: {
      EnemyDexEntry* entry;

      if (!seen) {
        break;
      }
      entry = &p->entries[p->entryIdx];
      TextPanel_SetScript(p->panels[6], p->scriptP);
      TextPanel_SetRect(p->panels[6], 1, 16, 6, 2);
      TextPanel_SetMessage(p->panels[6], 0);
      TextPanel_Start(p->panels[6]);
      if (entry->unk_1 == 0xFF) {
        TextPanel_SetScript(p->panels[4], p->scriptS);
        TextPanel_SetRect(p->panels[4], 6, 16, 20, 2);
        TextPanel_SetMessage(p->panels[4], 0);
        TextPanel_Start(p->panels[4]);
      } else if (!FUN_0820d04c(p->entryIdx, 0)) {
        TextPanel_SetScript(p->panels[4], p->scriptN);
        TextPanel_SetRect(p->panels[4], 6, 16, 20, 2);
        TextPanel_SetMessage(p->panels[4], 57);
        TextPanel_Start(p->panels[4]);
      } else if (entry->unk_1 != 0xFF) {
        switch (entry->unk_0) {
          case 0: {
            TextPanel_SetScript(p->panels[4], p->scriptI);
            TextPanel_SetRect(p->panels[4], 6, 16, 20, 2);
            TextPanel_SetMessage(p->panels[4], entry->unk_1);
            TextPanel_Start(p->panels[4]);
            break;
          }
          case 1: {
            TextPanel_SetScript(p->panels[4], p->scriptW);
            TextPanel_SetRect(p->panels[4], 6, 16, 20, 2);
            TextPanel_SetMessage(p->panels[4], entry->unk_1);
            FUN_0804a40c(p->panels[4], 0, (char*)&p->unk_49);
            TextPanel_Start(p->panels[4]);
            break;
          }
          case 2: {
            TextPanel_SetScript(p->panels[4], p->scriptA_upper);
            TextPanel_SetRect(p->panels[4], 6, 16, 20, 2);
            TextPanel_SetMessage(p->panels[4], entry->unk_1);
            TextPanel_Start(p->panels[4]);
            break;
          }
        }
      }
      TextPanel_SetScript(p->panels[7], p->scriptP);
      TextPanel_SetRect(p->panels[7], 1, 18, 6, 2);
      TextPanel_SetMessage(p->panels[7], 1);
      TextPanel_Start(p->panels[7]);
      if (entry->unk_3 == 0xFF) {
        TextPanel_SetScript(p->panels[5], p->scriptS);
        TextPanel_SetRect(p->panels[5], 6, 18, 30, 2);
        TextPanel_SetMessage(p->panels[5], 0);
        TextPanel_Start(p->panels[5]);
      } else if (!FUN_0820d04c(p->entryIdx, 1)) {
        TextPanel_SetScript(p->panels[5], p->scriptN);
        TextPanel_SetRect(p->panels[5], 6, 18, 30, 2);
        TextPanel_SetMessage(p->panels[5], 57);
        TextPanel_Start(p->panels[5]);
      } else if (entry->unk_3 != 0xFF) {
        switch (entry->unk_2) {
          case 0: {
            TextPanel_SetScript(p->panels[5], p->scriptI);
            TextPanel_SetRect(p->panels[5], 6, 18, 30, 2);
            TextPanel_SetMessage(p->panels[5], entry->unk_3);
            TextPanel_Start(p->panels[5]);
            break;
          }
          case 1: {
            TextPanel_SetScript(p->panels[5], p->scriptW);
            TextPanel_SetRect(p->panels[5], 6, 18, 30, 2);
            TextPanel_SetMessage(p->panels[5], entry->unk_3);
            FUN_0804a40c(p->panels[5], 0, (char*)&p->unk_49);
            TextPanel_Start(p->panels[5]);
            break;
          }
          case 2: {
            TextPanel_SetScript(p->panels[5], p->scriptA_upper);
            TextPanel_SetRect(p->panels[5], 6, 18, 30, 2);
            TextPanel_SetMessage(p->panels[5], entry->unk_3);
            TextPanel_Start(p->panels[5]);
            break;
          }
        }
      }
      break;
    }
  }
#else
  INCFUNC("asm/func/FUN_0820d250.inc");
#endif
}

// メッセージ表示の開始と終了を flags の状態に応じて進める
void FUN_0820d5f8(EnemyDexMenu* p) {
  if (p->flags & EDEXFLAG_UNK_0) {
    if (p->flags & EDEXFLAG_UNK_1) {
      Marquee_Clear();
      Marquee_CloseGlobal();
      p->flags = (p->flags & ~EDEXFLAG_UNK_1) | EDEXFLAG_UNK_2;
    }
  } else if (p->flags & EDEXFLAG_UNK_3) {
    if (p->flags & EDEXFLAG_UNK_2) {
      Marquee_Clear();
      FUN_08049f5c();
      p->flags &= ~EDEXFLAG_UNK_2;
    }

    Marquee_Clear();
    Marquee_SetText(GetStringByID(VM_ParseStringRef(p->scriptM) + p->entryIdx));
    p->flags &= ~EDEXFLAG_UNK_3;
    p->flags |= EDEXFLAG_UNK_1;
    p->flags &= ~EDEXFLAG_UNK_2;
  }
}

// 点滅用のタイマーを 0..49 で回し, 位置に応じた値を unk_1104 に入れる
void FUN_0820d690(EnemyDexMenu* p) {
  s32 v;

  if (p->timer_110c <= 9) {
    v = 31;
  } else if (p->timer_110c <= 17) {
    v = 27;
  } else if (p->timer_110c <= 25) {
    v = 18;
  } else if (p->timer_110c <= 33) {
    v = 10;
  } else if (p->timer_110c <= 41) {
    v = 18;
  } else {
    v = 27;
  }

  if (++p->timer_110c > 49) {
    p->timer_110c = 0;
  }
  p->unk_1104 = v;
}

void FUN_0820fe98(PreviewStage* p, u32 modelID);

// 魔物図鑑メニューの UI スプライトのポーズ番号, FUN_0820d6e4 が EnemyDexMenu+0x18C から5枚を登録するループで引く
static const u32 sEnemyDexUIPoses1[5] = {17, 18, 19, 20, 21};  // 0x085AF090

// 同上, EnemyDexMenu+0x36C から3枚
static const u32 sEnemyDexUIPoses2[3] = {1, 2, 3};  // 0x085AF0A4

// 図鑑画面の UI スプライトを全部登録し, カーソルの2枚に専用のパレットを持たせる
// 残差: 450 対 454 命令, 原典は各スプライトのアドレスと &p->gfx をスタックへ逃がして使い回す割当, 形はほぼ一致
NON_MATCH s32 FUN_0820d6e4(EnemyDexMenu* p) {
#ifdef NONMATCHING_C
  MainSpriteGfxFile* f = GetFile(DIR_MAIN_SPRITE, SPRITE_UI_GALLERY);
  Vec3 pos;
  rgb555* src;
  s32 i;

  p->gfx = *f;
  OpenMainSpriteFile(&p->gfx, f);
  pos.x = 0;
  pos.y = 0;
  pos.z = 0;
  pos.val = 0;
  for (i = 0; i < 7; i++) {
    s32 j;

    for (j = 0; j < 2; j++) {
      MainSprite_Add(&p->sprites_84c[i][j], &p->gfx, 0, SPRFLAG_SCREEN_COORD, 0, 2, 60, &pos);
    }
    MainSprite_Add(&p->sprites_5ac[i], &p->gfx, 10, SPRFLAG_SCREEN_COORD, 0, 2, 60, &pos);
  }
  pos.x = 0;
  pos.y = 0;
  pos.z = 0;
  pos.val = 0;
  for (i = 0; i < 2; i++) {
    MainSprite_Add(&p->sprites_d8c[i], &p->gfx, 0, SPRFLAG_SCREEN_COORD, 0, 2, 60, &pos);
    MainSprite_Add(&p->sprites_d8c[2 + i], &p->gfx, 0, SPRFLAG_SCREEN_COORD, 0, 2, 60, &pos);
  }
  pos.x = 0;
  pos.y = 0;
  pos.z = 0;
  pos.val = 0;
  MainSprite_Add(&p->sprites_d8c[7], &p->gfx, 34, SPRFLAG_SCREEN_COORD, 0, 2, 60, &pos);
  MainSprite_Add(&p->sprites_d8c[8], &p->gfx, 35, SPRFLAG_SCREEN_COORD, 0, 2, 60, &pos);
  for (i = 0; i < 2; i++) {
    pos.x = 32 + i * 96;
    pos.y = 0;
    pos.z = 0;
    pos.val = 0;
    MainSprite_Add(&p->sprites_d8c[4 + i], &p->gfx, 13, SPRFLAG_SCREEN_COORD, 0, 2, 60, &pos);
    p->sprites_d8c[4 + i].flags |= SPRFLAG_HIDDEN;
  }
  pos.x = 0;
  pos.y = 0;
  pos.z = 0;
  pos.val = 0;
  MainSprite_Add(&p->sprites_d8c[6], &p->gfx, 14, SPRFLAG_SCREEN_COORD, 0, 2, 60, &pos);
  p->sprites_d8c[6].flags |= SPRFLAG_HIDDEN;
  pos.x = 0;
  pos.y = 0;
  pos.z = 0;
  pos.val = 0;
  MainSprite_Add(&p->sprites_48c[0], &p->gfx, 15, SPRFLAG_SCREEN_COORD, 0, 2, 60, &pos);
  pos.x = 0;
  pos.y = 0;
  pos.z = 0;
  pos.val = 0;
  MainSprite_Add(&p->sprites_48c[1], &p->gfx, 16, SPRFLAG_SCREEN_COORD, 0, 2, 60, &pos);
  pos.x = 0;
  pos.y = 0;
  pos.z = 0;
  pos.val = 0;
  MainSprite_Add(&p->sprites_6c[2], &p->gfx, 24, SPRFLAG_SCREEN_COORD, 0, 2, 60, &pos);
  pos.x = 0;
  pos.y = 0;
  pos.z = 0;
  pos.val = 0;
  for (i = 0; i < 5; i++) {
    MainSprite_Add(&p->sprites_18c[i], &p->gfx, sEnemyDexUIPoses1[i], SPRFLAG_SCREEN_COORD, 0, 2, 60, &pos);
  }
  pos.x = 0;
  pos.y = 0;
  pos.z = 0;
  pos.val = 0;
  for (i = 0; i < 3; i++) {
    MainSprite_Add(&p->sprites_36c[i], &p->gfx, sEnemyDexUIPoses2[i], SPRFLAG_SCREEN_COORD, 0, 2, 60, &pos);
  }
  pos.x = 0;
  pos.y = 0;
  pos.z = 0;
  pos.val = 0;
  MainSprite_Add(&p->sprites_48c[2], &p->gfx, 12, SPRFLAG_SCREEN_COORD, 0, 2, 60, &pos);
  pos.x = 0;
  pos.y = 0;
  pos.z = 0;
  pos.val = 0;
  MainSprite_Add(&p->sprites_6c[0], &p->gfx, 22, SPRFLAG_SCREEN_COORD, 0, 2, 60, &pos);
  p->sprites_6c[0].pos.y = p->row * 16 + 8;
  pos.x = 0;
  pos.y = 0;
  pos.z = 0;
  pos.val = 0;
  MainSprite_Add(&p->sprites_6c[1], &p->gfx, 23, SPRFLAG_SCREEN_COORD, 0, 2, 60, &pos);
  src = p->sprites_6c[0].pltt;
  CpuCopy32(src, p->unk_10ec, 16 * sizeof(rgb555));
  p->sprites_6c[0].pltt = (rgb555*)p->unk_10ec;
  p->sprites_6c[1].pltt = (rgb555*)p->unk_10ec;
  return (s32)src;
#else
  INCFUNC("asm/func/FUN_0820d6e4.inc");
#endif
}

// 図鑑画面の BG とパレットを用意する
s32 FUN_0820dae4(EnemyDexMenu* p, u32 param_2) {
  s32 bgIndex = param_2;
  BgPlttFile* f;
  BgState* bg;

  p->tilemap = GetFile(DIR_TILE_MAP, TILEMAP_4F8F);
  Video_SetupBGLayout(1, 0, p->tilemap, 0, 0, 1, &bgIndex);
  SetBGPrioDirect(2, 0);
  Video_GenerateBGMap(2, 0, 0, 0, 0);

  f = GetBgPlttFile(BGP_A41A);
  p->pltt = f->body;
  CpuCopy16(&f->body[208], &gBgPlttBuffer[208], 48 * sizeof(rgb555));

  bg = &gBgStates[3];
  bg->width16 = 16;
  bg->hofs = 0;
  bg->vofs = 0;
  SetBGPrioDirect(3, 3);
  SET_FLAGS(gStagedDISPCNT, DISPCNT_BG3_ON);
  Video_FillBGRect(3, 4, 6, 8, 9, 1, 0, 0);
  return 0;
}

// 一覧 (unk_24 = 0) と詳細 (unk_24 = 1) の画面を組み直す
// 残差: 500 対 529 命令, 初稿, 原典はページの switch を tab/arrow の表引きでなく分岐で持ち, スプライトの flags をポインタ歩きで触る
NON_MATCH void FUN_0820db9c(EnemyDexMenu* p) {
#ifdef NONMATCHING_C
  s32 i;

  if (p->unk_24 == 0) {
    s32 start;
    s32 count;
    s32 tab;
    s32 arrow;
    s16 arrowX = 0;
    s16 arrowY = 0;
    u32 category;

    p->sprites_6c[0].flags &= ~SPRFLAG_HIDDEN;
    p->sprites_6c[1].flags |= SPRFLAG_HIDDEN;
    p->sprites_6c[2].flags |= SPRFLAG_HIDDEN;
    p->sprites_48c[0].flags &= ~SPRFLAG_HIDDEN;
    p->sprites_48c[1].flags |= SPRFLAG_HIDDEN;
    p->sprites_48c[2].flags |= SPRFLAG_HIDDEN;
    FUN_0820d21c(p);
    start = EnemyDex_GetPageStart(p->page);
    count = EnemyDex_GetPageEntryCount(p->page);
    for (i = 0; i < count; i++) {
      TextPanel_SetScript(p->panels[i], p->scriptN);
      TextPanel_SetRect(p->panels[i], 6, 5 + i * 2, 20, 2);
      if (FUN_0820d00c(start + i)) {
        TextPanel_SetMessage(p->panels[i], start + i);
      } else {
        TextPanel_SetMessage(p->panels[i], 57);
      }
      TextPanel_Start(p->panels[i]);
    }
    for (i = 0; i < 5; i++) {
      p->sprites_18c[i].flags |= SPRFLAG_HIDDEN;
    }
    for (i = 0; i < 3; i++) {
      p->sprites_36c[i].flags |= SPRFLAG_HIDDEN;
    }
    switch (p->page) {
      case 0:
      case 1:
      case 2: {
        arrow = p->page;
        tab = 0;
        arrowX = 112;
        arrowY = 19;
        break;
      }
      case 3: {
        tab = 1;
        arrow = -1;
        break;
      }
      case 4:
      case 5: {
        arrow = p->page - 4;
        tab = 2;
        arrowX = 96;
        arrowY = 19;
        break;
      }
      case 6:
      case 7: {
        arrow = p->page - 6;
        tab = 3;
        arrowX = 128;
        arrowY = 19;
        break;
      }
      case 8: {
        tab = 4;
        arrow = -1;
        break;
      }
      default: {
        tab = 0;
        arrow = 1;
        break;
      }
    }
    p->sprites_18c[tab].flags &= ~SPRFLAG_HIDDEN;
    if (arrow >= 0) {
      p->sprites_36c[arrow].flags &= ~SPRFLAG_HIDDEN;
      p->sprites_36c[arrow].pos.x = arrowX;
      p->sprites_36c[arrow].pos.y = arrowY;
    }
    for (i = 0; i < 7; i++) {
      s32 j;

      for (j = 0; j < 2; j++) {
        p->sprites_84c[i][j].flags |= SPRFLAG_HIDDEN;
      }
      p->sprites_5ac[i].flags |= SPRFLAG_HIDDEN;
    }
    count = EnemyDex_GetPageEntryCount(p->page);
    start = EnemyDex_GetPageStart(p->page);
    for (i = 0; i < count; i++) {
      MainSprite_SetNumber(&p->sprites_84c[i][0], &p->gfx, start + 1 + i, 2, 0, 24, i * 16 + 40, 8, 0);
      p->sprites_5ac[i].flags &= ~SPRFLAG_HIDDEN;
      p->sprites_5ac[i].pos.x = 40;
      p->sprites_5ac[i].pos.y = i * 16 + 40;
    }
    for (i = 0; i < 2; i++) {
      p->sprites_d8c[i].flags |= SPRFLAG_HIDDEN;
      p->sprites_d8c[2 + i].flags |= SPRFLAG_HIDDEN;
    }
    category = EnemyDex_GetCategoryOfEntry(p->entryIdx);
    MainSprite_SetNumber(&p->sprites_d8c[0], &p->gfx, FUN_0820d0b8(category), 2, 0, 152, 19, 8, 0);
    MainSprite_SetNumber(&p->sprites_d8c[2], &p->gfx, EnemyDex_GetCategoryEntryCount(category), 2, 0, 176, 19, 8, 0);
    FUN_0820fea8(p->sub);
    FUN_0820d138(p);
  } else if (p->unk_24 == 1) {
    p->sprites_6c[0].flags |= SPRFLAG_HIDDEN;
    p->sprites_6c[1].flags &= ~SPRFLAG_HIDDEN;
    p->sprites_6c[2].flags &= ~SPRFLAG_HIDDEN;
    p->sprites_48c[0].flags |= SPRFLAG_HIDDEN;
    p->sprites_48c[1].flags &= ~SPRFLAG_HIDDEN;
    p->sprites_48c[2].flags &= ~SPRFLAG_HIDDEN;
    FUN_0820d21c(p);
    for (i = 0; i < 5; i++) {
      p->sprites_18c[i].flags |= SPRFLAG_HIDDEN;
    }
    for (i = 0; i < 3; i++) {
      p->sprites_36c[i].flags |= SPRFLAG_HIDDEN;
    }
    FUN_0820d250(p);
    for (i = 0; i < 7; i++) {
      s32 j;

      for (j = 0; j < 2; j++) {
        p->sprites_84c[i][j].flags |= SPRFLAG_HIDDEN;
      }
      p->sprites_5ac[i].flags |= SPRFLAG_HIDDEN;
    }
    MainSprite_SetNumber(&p->sprites_84c[0][0], &p->gfx, p->entryIdx + 1, 2, 0, 40, 24, 8, 0);
    for (i = 0; i < 2; i++) {
      p->sprites_d8c[i].flags |= SPRFLAG_HIDDEN;
      p->sprites_d8c[2 + i].flags |= SPRFLAG_HIDDEN;
    }
    FUN_0820fe98(p->sub, p->entryIdx);
    if (FUN_0820d00c(p->entryIdx)) {
      FUN_0820feb0(p->sub);
    } else {
      FUN_0820fea8(p->sub);
    }
    FUN_0820d188(p);
    FUN_0820d138(p);
  }
#else
  INCFUNC("asm/func/FUN_0820db9c.inc");
#endif
}

void FUN_0820e080(EnemyDexMenu* p, u8 param_2) {
  p->unk_24 = param_2;
  p->unk_114d[0] = 0;
  FUN_0820dae4(p, p->unk_24);
  FUN_0820db9c(p);
}

// 残差: 720 対 725 命令, p が r7 でなく r9 に入りページ切り替え時の各スプライト配列の基底アドレスの退避が足りない, 一覧の描き直し (FUN_0820d21c から分類の数字まで) を static inline に括ると基底アドレスが全部ブロック先頭に揃い 723 命令になるので, FUN_0820db9c と共有の inline だった可能性が高い
NON_MATCH s32 EnemyDexMenu_Update(EnemyDexMenu* p) {
#ifdef NONMATCHING_C
  bool32 cursorMoved = FALSE;
  bool32 pageChanged = FALSE;

  switch (p->unk_24) {
    case 0: {
      if (gInput[0].pressed & L_BUTTON) {
        p->page = (p->page == 0) ? 8 : p->page - 1;
        PlaySound_082406e0(SE_MENU_PAGE);
        pageChanged = TRUE;
      } else if (gInput[0].pressed & R_BUTTON) {
        if (p->page < 8) {
          p->page++;
        } else {
          p->page = 0;
        }
        PlaySound_082406e0(SE_MENU_PAGE);
        pageChanged = TRUE;
      }
      if (pageChanged) {
        s32 i;
        s32 start;
        s32 count;
        s32 tab;
        s32 arrow;
        s16 arrowX;
        s16 arrowY;
        u32 category;

        p->entryIdx = EnemyDex_GetPageStart(p->page);
        p->row = 0;
        cursorMoved = TRUE;
        FUN_0820d21c(p);
        start = EnemyDex_GetPageStart(p->page);
        count = EnemyDex_GetPageEntryCount(p->page);
        for (i = 0; i < count; i++) {
          TextPanel_SetScript(p->panels[i], p->scriptN);
          TextPanel_SetRect(p->panels[i], 6, 5 + i * 2, 20, 2);
          if (FUN_0820d00c(start + i)) {
            TextPanel_SetMessage(p->panels[i], start + i);
          } else {
            TextPanel_SetMessage(p->panels[i], 57);
          }
          TextPanel_Start(p->panels[i]);
        }
        EnemyDexMenu_HideCursorSprites(p);
        arrowX = 0;
        arrowY = 0;
        switch (p->page) {
          case 0: {
            tab = 0;
            arrow = 0;
            arrowX = 112;
            arrowY = 19;
            break;
          }
          case 1: {
            tab = 0;
            arrow = 1;
            arrowX = 112;
            arrowY = 19;
            break;
          }
          case 2: {
            tab = 0;
            arrow = 2;
            arrowX = 112;
            arrowY = 19;
            break;
          }
          case 3: {
            tab = 1;
            arrow = -1;
            break;
          }
          case 4: {
            tab = 2;
            arrow = 0;
            arrowX = 96;
            arrowY = 19;
            break;
          }
          case 5: {
            tab = 2;
            arrow = 1;
            arrowX = 96;
            arrowY = 19;
            break;
          }
          case 6: {
            tab = 3;
            arrow = 0;
            arrowX = 128;
            arrowY = 19;
            break;
          }
          case 7: {
            tab = 3;
            arrow = 1;
            arrowX = 128;
            arrowY = 19;
            break;
          }
          case 8: {
            tab = 4;
            arrow = -1;
            break;
          }
          default: {
            tab = 0;
            arrow = 1;
            break;
          }
        }
        p->sprites_18c[tab].flags &= ~SPRFLAG_HIDDEN;
        if (arrow >= 0) {
          p->sprites_36c[arrow].flags &= ~SPRFLAG_HIDDEN;
          p->sprites_36c[arrow].pos.x = arrowX;
          p->sprites_36c[arrow].pos.y = arrowY;
        }
        EnemyDexMenu_HidePageSprites(p);
        count = EnemyDex_GetPageEntryCount(p->page);
        start = EnemyDex_GetPageStart(p->page);
        for (i = 0; i < count; i++) {
          MainSprite_SetNumber(&p->sprites_84c[i][0], &p->gfx, start + 1 + i, 2, 0, 24, i * 16 + 40, 8, 0);
          p->sprites_5ac[i].flags &= ~SPRFLAG_HIDDEN;
          p->sprites_5ac[i].pos.x = 40;
          p->sprites_5ac[i].pos.y = i * 16 + 40;
        }
        for (i = 0; i < 2; i++) {
          p->sprites_d8c[i].flags |= SPRFLAG_HIDDEN;
          p->sprites_d8c[2 + i].flags |= SPRFLAG_HIDDEN;
        }
        category = EnemyDex_GetCategoryOfEntry(p->entryIdx);
        MainSprite_SetNumber(&p->sprites_d8c[0], &p->gfx, FUN_0820d0b8(category), 2, 0, 152, 19, 8, 0);
        MainSprite_SetNumber(&p->sprites_d8c[2], &p->gfx, EnemyDex_GetCategoryEntryCount(category), 2, 0, 176, 19, 8, 0);
        FUN_0820d188(p);
      }

      if ((gInput[0].pressed & DPAD_UP) && p->entryIdx != 0) {
        if (p->row != 0) {
          p->entryIdx--;
          p->row--;
        } else {
          p->row = EnemyDex_GetPageEntryCount(p->page) - 1;
          p->entryIdx = p->row + EnemyDex_GetPageStart(p->page);
        }
        PlaySound_082406e0(SE_CURSOR_MOVE);
        cursorMoved = TRUE;
      } else if ((gInput[0].pressed & DPAD_DOWN) && p->entryIdx < 56) {
        if (p->row < EnemyDex_GetPageEntryCount(p->page) - 1) {
          p->entryIdx++;
          p->row++;
        } else {
          p->entryIdx = EnemyDex_GetPageStart(p->page);
          p->row = 0;
        }
        PlaySound_082406e0(SE_CURSOR_MOVE);
        cursorMoved = TRUE;
      }
      if (cursorMoved) {
        p->sprites_6c[0].pos.y = p->row * 16 + 8;
      }

      if (gInput[0].pressed & A_BUTTON) {
        FUN_0820e080(p, 1);
        FUN_0820d188(p);
        PlaySound_082406e0(SE_SELECT);
      }
      if (gInput[0].pressed & B_BUTTON) {
        if (p->unk_1258 != 0) {
          VM_ExecByID(p->unk_1258, NULL);
        }
        PlaySound_082406e0(SE_CLOSE_MENU);
        p->unk_24 = 2;
      }
      break;
    }
    case 1: {
      if (gInput[0].pressed & DPAD_UP) {
        p->unk_27 = (p->unk_27 == 0) ? 3 : p->unk_27 - 1;
        PlaySound_082406e0(SE_CURSOR_MOVE);
        cursorMoved = TRUE;
      } else if (gInput[0].pressed & DPAD_DOWN) {
        if (p->unk_27 < 3) {
          p->unk_27++;
        } else {
          p->unk_27 = 0;
        }
        PlaySound_082406e0(SE_CURSOR_MOVE);
        cursorMoved = TRUE;
      }
      if (cursorMoved) {
        p->sprites_6c[1].pos.y = p->unk_27 << 4;
        FUN_0820d250(p);
      }

      if (gInput[0].pressed & R_BUTTON) {
        p->entryIdx = (p->entryIdx < 56) ? p->entryIdx + 1 : 0;
        PlaySound_082406e0(SE_MENU_PAGE);
        pageChanged = TRUE;
      } else if (gInput[0].pressed & L_BUTTON) {
        if (p->entryIdx != 0) {
          p->entryIdx--;
        } else {
          p->entryIdx = 56;
        }
        PlaySound_082406e0(SE_MENU_PAGE);
        pageChanged = TRUE;
      }
      if (pageChanged) {
        FUN_0820d250(p);
        EnemyDexMenu_HidePageSprites(p);
        MainSprite_SetNumber(&p->sprites_84c[0][0], &p->gfx, p->entryIdx + 1, 2, 0, 40, 24, 8, 0);
        if (FUN_0820d00c(p->entryIdx)) {
          FUN_0820feb0(p->sub);
          FUN_0820fe98(p->sub, p->entryIdx);
        } else {
          FUN_0820fea8(p->sub);
        }
        FUN_0820d188(p);
      }

      if (!p->unk_114d[0]) {
        if (gInput[0].pressed & B_BUTTON) {
          p->flags |= EDEXFLAG_UNK_0;
          EnemyDexMenu_SetPageFromEntry(p);
          p->sprites_6c[0].pos.y = p->row * 16 + 8;
          p->unk_114d[0] = 1;
        }
      } else {
        FUN_0820e080(p, 0);
        FUN_0820d188(p);
        PlaySound_082406e0(SE_CANCEL);
      }
      break;
    }
    case 2: {
      return 0;
    }
  }
  FUN_0820d188(p);
  FUN_0820d690(p);
  FUN_0820d5f8(p);
  p->unk_20++;
  return 0;
#else
  INCFUNC("asm/func/EnemyDexMenu_Update.inc");
#endif
}

void FUN_0820e75c(MainSprite* spr) {
  if (spr->active) {
    MainSprite_Remove(spr);
  }
}

s32 EnemyDexMenu_Destroy(EnemyDexMenu* p) {
  s32 i;

  FUN_0820e75c(&p->sprites_6c[1]);
  FUN_0820e75c(&p->sprites_6c[0]);
  FUN_0820e75c(&p->sprites_6c[1]);
  FUN_0820e75c(&p->sprites_6c[2]);

  for (i = 0; i < 5; i++) {
    FUN_0820e75c(&p->sprites_18c[i]);
  }
  for (i = 0; i < 3; i++) {
    FUN_0820e75c(&p->sprites_36c[i]);
  }

  FUN_0820e75c(&p->sprites_48c[0]);
  FUN_0820e75c(&p->sprites_48c[1]);
  FUN_0820e75c(&p->sprites_48c[2]);

  for (i = 0; i < 7; i++) {
    FUN_0820e75c(&p->sprites_5ac[i]);
    FUN_0820e75c(&p->sprites_84c[i][0]);
    FUN_0820e75c(&p->sprites_84c[i][1]);
  }
  for (i = 0; i < 2; i++) {
    FUN_0820e75c(&p->sprites_d8c[i]);
    FUN_0820e75c(&p->sprites_d8c[i + 2]);
  }
  for (i = 0; i < 2; i++) {
    FUN_0820e75c(&p->sprites_d8c[i + 4]);
  }
  FUN_0820e75c(&p->sprites_d8c[6]);
  MainSprite_Remove(&p->sprites_d8c[7]);
  MainSprite_Remove(&p->sprites_d8c[8]);
  return 0;
}

s32 EnemyDexMenu_Init(EnemyDexMenu* p, u32 val) {
  s32 i;
  s32 j;

  p->unk_20 = 0;
  p->unk_24 = 0;
  p->page = 0;
  p->entryIdx = 0;
  p->row = 0;
  p->timer_110c = 0;
  p->unk_49 = 0x20;
  p->unk_4a = 0;

  if (!VM_SeekToNamedArg('n')) {
    return -1;
  }
  p->scriptN = VM_GetPC_Proxy();
  if (p->scriptN == NULL) {
    return -1;
  }

  for (j = 0; j < 8; j++) {
    p->panels[j] = TextPanel_Create(3, j * 2 + 5, 23, 2);
    TextPanel_SetScript(p->panels[j], p->scriptN);
    TextPanel_SetMessage(p->panels[j], j);
    TextPanel_Hide(p->panels[j]);
  }

  if (VM_SeekToNamedArg('d')) {
    VM_SetPC(VM_GetValueSafe2_Proxy());
    for (i = 0; i < 57; i++) {
      p->unk_1114[i] = VM_GetValue();
    }
  }

  if (VM_SeekToNamedArg('t')) {
    u8* src = VM_GetValueSafe2_Proxy();

    for (i = 0; i < 57; i++) {
      p->entries[i].unk_0 = *src++;
      p->entries[i].unk_1 = *src++;
      p->entries[i].unk_2 = *src++;
      p->entries[i].unk_3 = *src++;
    }
  }

  if (VM_SeekToNamedArg('i')) {
    p->scriptI = VM_GetPC_Proxy();
  }
  if (VM_SeekToNamedArg('s')) {
    p->scriptS = VM_GetPC_Proxy();
  }
  if (VM_SeekToNamedArg('p')) {
    p->scriptP = VM_GetPC_Proxy();
  }
  if (VM_SeekToNamedArg('w')) {
    p->scriptW = VM_GetPC_Proxy();
  }
  if (VM_SeekToNamedArg('A')) {
    p->scriptA_upper = VM_GetPC_Proxy();
  }
  if (VM_SeekToNamedArg('a')) {
    p->scriptA = VM_GetPC_Proxy();
  }
  if (VM_SeekToNamedArg('m')) {
    p->scriptM = VM_GetPC_Proxy();
  }
  if (VM_SeekToNamedArg('u')) {
    p->scriptU = VM_GetPC_Proxy();
  }
  if (VM_SeekToNamedArg('T')) {
    p->scriptT_upper = VM_GetPC_Proxy();
  }
  p->unk_1258 = VM_GetNamedArgValue('e', 0);

  p->flags = 5;
  Marquee_Clear();
  p->sub = PreviewStage_Create(0, 0);
  FUN_0820fea8(p->sub);
  FUN_0820d6e4(p);
  FUN_0820e080(p, 0);
  StartBgObjPlttFade(0, 4, 4, 4, 4, 0xFFFF, 0);
  PlaySound_082406e0(SE_OPEN_MENU);
  return 0;
}

EnemyDexMenu* EnemyDexMenu_Create(u32 val) {
  EnemyDexMenu* p = CreateEntity(ENTITY_UNK_8, sizeof(EnemyDexMenu));

  if (p != NULL) {
    SetEntityRoutine(p, EnemyDexMenu_Update, EnemyDexMenu_Destroy);
    if (EnemyDexMenu_Init(p, val) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

// ページ用スプライトを全部隠す
void FUN_0820eb38(EnemyDexMenu* p) {
  s32 i;
  s32 j;

  for (i = 0; i < 7; i++) {
    for (j = 0; j < 2; j++) {
      p->sprites_84c[i][j].flags |= SPRFLAG_HIDDEN;
    }
    p->sprites_5ac[i].flags |= SPRFLAG_HIDDEN;
  }
}

// 選択中ページのエントリ番号を縦に並べて描く
void FUN_0820eb84(EnemyDexMenu* p) {
  s32 count;
  s32 base;
  s32 i;

  EnemyDexMenu_HidePageSprites(p);

  count = EnemyDex_GetPageEntryCount(p->page);
  base = EnemyDex_GetPageStart(p->page) + 1;
  for (i = 0; i < count; i++) {
    MainSprite_SetNumber(&p->sprites_84c[i][0], &p->gfx, base + i, 2, 0, 24, i * 16 + 40, 8, 0);
    p->sprites_5ac[i].flags &= ~SPRFLAG_HIDDEN;
    p->sprites_5ac[i].pos.x = 40;
    p->sprites_5ac[i].pos.y = i * 16 + 40;
  }
}

// ページ用スプライトを全部隠し, 選択中ページの番号を描き直す
void FUN_0820ec6c(EnemyDexMenu* p) {
  EnemyDexMenu_HidePageSprites(p);
  MainSprite_SetNumber(&p->sprites_84c[0][0], &p->gfx, p->entryIdx + 1, 2, 0, 40, 24, 8, 0);
}

// sprites_d8c を全部隠す
void EnemyDexMenu_HideSprites(EnemyDexMenu* p) {
  s32 i;

  for (i = 0; i < 2; i++) {
    p->sprites_d8c[i].flags |= SPRFLAG_HIDDEN;
    p->sprites_d8c[i + 2].flags |= SPRFLAG_HIDDEN;
  }
}

void FUN_0820ed38(EnemyDexMenu* p) { p->sprites_6c[0].pos.y = p->row * 16 + 8; }

// 図鑑の発見数と総数を描き直す
void FUN_0820ed48(EnemyDexMenu* p) {
  s32 cat;
  s32 i;

  for (i = 0; i < 2; i++) {
    p->sprites_d8c[i].flags |= SPRFLAG_HIDDEN;
    p->sprites_d8c[i + 2].flags |= SPRFLAG_HIDDEN;
  }

  cat = EnemyDex_GetCategoryOfEntry(p->entryIdx);
  MainSprite_SetNumber(&p->sprites_d8c[0], &p->gfx, FUN_0820d0b8(cat), 2, 0, 152, 19, 8, 0);
  MainSprite_SetNumber(&p->sprites_d8c[2], &p->gfx, EnemyDex_GetCategoryEntryCount(cat), 2, 0, 176, 19, 8, 0);
}

// 選択中ページのエントリ名を上から順にパネルへ流す, 未発見なら 57 番のメッセージ
void FUN_0820ede8(EnemyDexMenu* p) {
  s32 base;
  s32 count;
  s32 i;

  FUN_0820d21c(p);
  base = EnemyDex_GetPageStart(p->page);
  count = EnemyDex_GetPageEntryCount(p->page);
  for (i = 0; i < count; i++) {
    TextPanel_SetScript(p->panels[i], p->scriptN);
    TextPanel_SetRect(p->panels[i], 6, i * 2 + 5, 20, 2);
    if (FUN_0820d00c(base + i)) {
      TextPanel_SetMessage(p->panels[i], base + i);
    } else {
      TextPanel_SetMessage(p->panels[i], 57);
    }
    TextPanel_Start(p->panels[i]);
  }
}

void FUN_0820ee7c(EnemyDexMenu* p) {
  s32 i;

  for (i = 0; i < 5; i++) {
    p->sprites_18c[i].flags |= SPRFLAG_HIDDEN;
  }
  for (i = 0; i < 3; i++) {
    p->sprites_36c[i].flags |= SPRFLAG_HIDDEN;
  }
}

// page の値に応じて, 出すカーソルとタブのスプライトを1枚ずつだけ選ぶ
void FUN_0820eeb8(EnemyDexMenu* p) {
  s32 cursor;
  s32 tab;
  s32 x;
  s32 y;

  EnemyDexMenu_HideCursorSprites(p);

  x = 0;
  y = 0;
  switch (p->page) {
    case 0: {
      cursor = 0;
      tab = 0;
      x = 112;
      y = 19;
      break;
    }
    case 1: {
      cursor = 0;
      tab = 1;
      x = 112;
      y = 19;
      break;
    }
    case 2: {
      cursor = 0;
      tab = 2;
      x = 112;
      y = 19;
      break;
    }
    case 3: {
      cursor = 1;
      tab = -1;
      break;
    }
    case 4: {
      cursor = 2;
      tab = 0;
      x = 96;
      y = 19;
      break;
    }
    case 5: {
      cursor = 2;
      tab = 1;
      x = 96;
      y = 19;
      break;
    }
    case 6: {
      cursor = 3;
      tab = 0;
      x = 128;
      y = 19;
      break;
    }
    case 7: {
      cursor = 3;
      tab = 1;
      x = 128;
      y = 19;
      break;
    }
    case 8: {
      cursor = 4;
      tab = -1;
      break;
    }
    default: {
      cursor = 0;
      tab = 1;
      break;
    }
  }

  p->sprites_18c[cursor].flags &= ~SPRFLAG_HIDDEN;
  if (tab >= 0) {
    p->sprites_36c[tab].flags &= ~SPRFLAG_HIDDEN;
    p->sprites_36c[tab].pos.x = x;
    p->sprites_36c[tab].pos.y = y;
  }
}
