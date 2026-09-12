#include "entity.h"
#include "global.h"
#include "vm.h"

typedef struct UnkStruct08daadb8 {
  u16 unk_0;  // 0x0
  u8 unk_2;   // 0x2, 根拠: FUN_08022128 の ldrb
  u8 unk_3;   // 0x3
  u8 unk_4[2];
  u8 unk_6;   // 0x6, FUN_08022210 で処理の種類 (0: FUN_080221b8, 1: FUN_080221e0, 2: FUN_080221fc) として switch される
  u8 unk_7;
  s16 unk_8;  // 0x8, FUN_080221e0 の ldrsh
} UnkStruct08daadb8;  // サイズ不明 (少なくとも 10バイト)

typedef struct Entity4E69 {
  Entity e;         // ENTITY_UNK_2
  u16 unk_18;       // 0x18
  s16 unk_1a;       // 0x1A
  u16 unk_1c;       // 0x1C
  u8 unk_1e;        // 0x1E
  u8 unk_1f;        // 0x1F
  u16 scriptID_20;  // 0x20, 0x08022308
  u8 unk_22;        // 0x22
  u8 unk_23;        // 0x23
  u8 unk_24;        // 0x24
  u8 unk_25[0x28 - 0x25];
  u16 unk_28[16];       // 0x28, FUN_080224a8 で検索されるキー, 件数は unk_22
  u16 unk_48[16];       // 0x48, unk_28 に対応する値 (スクリプトID)
  s32 unk_68;           // 0x68, FUN_080221e0
  u32 unk_6c;           // 0x6C
  u32 unk_70;           // 0x70
  UnkStruct52* unk_74;  // 0x74
  UnkStruct52 unk_78;   // 0x78
} Entity4E69;
static_assert(sizeof(Entity4E69) == 172);

extern Entity4E69* gEntity4E69;  // 0x03002B4C

bool32 FUN_08022474(UnkStruct52* p, UnkStruct08daadb8* data);
bool32 FUN_08022488(UnkStruct52* p, u32 val);
u16 FUN_080224a8(u32 id);
UnkStruct08daadb8* FUN_0823a840(s32 idx1, s32 idx2, s32 idx3);

// p->unk_74 のリストから unk_0 と unk_2 が一致するノードを探す
UnkStruct52* FUN_080220bc(Entity4E69* p, u32 val1, u32 val2) {
  UnkStruct52* data;
  UnkStruct52* next;
  for (data = p->unk_74; data != NULL; data = next) {
    next = data->next;
    if (data->unk_0 == val1 && data->unk_2 == val2) {
      return data;
    }
  }
  return NULL;
}

s32 FUN_080220e8(Entity4E69* p, UnkStruct52* data) {
  if (p->unk_74 != NULL) {
    (p->unk_74)->prev = data;
  }
  data->prev = NULL;
  data->next = p->unk_74;
  p->unk_74 = data;
  return 0;
}

// data を p->unk_74 のリストから外す
s32 FUN_08022104(Entity4E69* p, UnkStruct52* data) {
  if (data->prev != NULL) {
    data->prev->next = data->next;
  } else {
    p->unk_74 = data->next;
  }
  if (data->next != NULL) {
    data->next->prev = data->prev;
  }
  return 0;
}

// data の unk_0/unk_2 に一致するノードを探し、その現在と逆側の面に data を追加する (1面あたり最大4件)
s32 FUN_08022128(Entity4E69* p, UnkStruct08daadb8* data) {
  UnkStruct52* node;
  s32 side;
  node = FUN_080220bc(p, data->unk_0, data->unk_2);
  side = 1 - p->unk_24;
  if (node != NULL && node->unk_6[side] < 4) {
    node->unk_8[side][node->unk_6[side]] = data;
    node->unk_6[side]++;
  }
}

// リストの全ノードについて現在の面(unk_24)のデータをクリアし、面を切り替える
void FUN_0802216c(Entity4E69* p) {
  UnkStruct52* data;
  UnkStruct52* next;
  s32 i;
  for (data = p->unk_74; data != NULL; data = next) {
    next = data->next;
    data->unk_6[p->unk_24] = 0;
    for (i = 0; i < 4; i++) {
      data->unk_8[p->unk_24][i] = NULL;
    }
  }
  p->unk_24 = 1 - p->unk_24;
}

// data->unk_8 に対応するスクリプトがあれば実行する
void FUN_080221b8(Entity4E69* p, UnkStruct52* q, UnkStruct08daadb8* data) {
  u16 scriptID = FUN_080224a8((u16)data->unk_8);
  if (scriptID != 0) {
    Script_ExecById(scriptID, NULL);
  }
  FUN_08022488(q, 1);
}

void FUN_080221e0(Entity4E69* p, UnkStruct52* q, UnkStruct08daadb8* data) {
  p->unk_68 = data->unk_8;
  if (p->unk_68 == 0) {
    FUN_08022488(q, 1);
  }
}

void FUN_080221fc(Entity4E69* p, UnkStruct52* q, UnkStruct08daadb8* _) {
  p->unk_70 = 1;
  FUN_08022488(q, 1);
}

// 現在の面に溜まった data を種類 (unk_6) ごとのハンドラで処理する
NON_MATCH s32 FUN_08022210(Entity4E69* p) {
#ifdef NONMATCHING_C
  UnkStruct52* node = &p->unk_78;
  UnkStruct08daadb8* data;
  s32 i = 0;
  while (i < node->unk_6[gEntity4E69->unk_24]) {
    data = node->unk_8[gEntity4E69->unk_24][i];
    FUN_08022474(node, data);
    switch (data->unk_6) {
      case 0: {
        FUN_080221b8(p, node, data);
        break;
      }
      case 1: {
        FUN_080221e0(p, node, data);
        break;
      }
      case 2: {
        FUN_080221fc(p, node, data);
        break;
      }
    }
    i++;
  }
  return 0;
#else
  INCFUNC("asm/func/FUN_08022210.inc");
#endif
}

s32 Entity4E69_Update(Entity4E69* p) {
  bool32 exec = FALSE;
  UnkStruct08daadb8* data;
  if (p->unk_23 == 1) {
    p->unk_1f = 0;
    if (p->unk_1e != 0) {
      p->unk_1a++;
      p->unk_1c = 0;
      p->unk_1e = 0;
      p->unk_1f = 1;
    }
    if (p->unk_1f != 0) {
      p->unk_1c = 0;
      while ((data = FUN_0823a840((s16)p->unk_18, p->unk_1a, p->unk_1c)) != NULL) {
        FUN_08022128(p, data);
        p->unk_1c++;
      }
      if (p->unk_1c == 0) {
        if (p->scriptID_20 != 0) {
          Script_ExecById(p->scriptID_20, NULL);
        }
        p->unk_23 = 0;
        return 0;
      }
      exec = TRUE;
    }
    if (p->unk_68 != 0) {
      p->unk_68--;
      if (p->unk_68 == 0) {
        FUN_08022488(&p->unk_78, 1);
      }
    }
  }
  FUN_0802216c(p);
  if (exec) {
    FUN_08022210(p);
  }
  return 0;
}

s32 Entity4E69_Destroy(Entity4E69* p) {
  FUN_08022428(&p->unk_78);
  gEntity4E69 = NULL;
  return 0;
}

s32 Entity4E69_Init(Entity4E69* p, u32 subroutineID) {
  gEntity4E69 = p;
  p->unk_23 = 0;
  p->unk_18 = 0xFFFF;
  p->unk_1a = -1;
  p->unk_1c = 0;
  p->unk_1e = 0;
  p->unk_1f = 0;
  p->scriptID_20 = 0;
  p->unk_22 = 0;
  p->unk_6c = 0;
  p->unk_74 = NULL;
  FUN_080223f4(&p->unk_78, subroutineID, 1);
  return 0;
}

Entity4E69* Entity4E69_Create(u32 subroutineID) {
  Entity4E69* p;
  if (gEntity4E69 != NULL) {
    return NULL;
  }
  p = CreateEntity(ENTITY_UNK_2, sizeof(Entity4E69));
  if (p != NULL) {
    SetEntityRoutine(p, Entity4E69_Update, Entity4E69_Destroy);
    if (Entity4E69_Init(p, subroutineID) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

// p を初期化して gEntity4E69 のリストに登録する
s32 FUN_080223f4(UnkStruct52* p, u32 val1, s32 val2) {
  if (gEntity4E69 == NULL) {
    return -1;
  }
  p->unk_0 = val1;
  p->unk_2 = val2;
  p->unk_6[0] = 0;
  p->unk_6[1] = 0;
  p->unk_3 = 0;
  return FUN_080220e8(gEntity4E69, p);
}

// p を gEntity4E69 のリストから外す
s32 FUN_08022428(UnkStruct52* p) {
  if (gEntity4E69 == NULL) {
    return -1;
  }
  return FUN_08022104(gEntity4E69, p);
}

s32 FUN_08022448(void) {
  if (gEntity4E69 == NULL) {
    return -1;
  }
  if (gEntity4E69->unk_1e != 0) {
    return -2;
  }
  gEntity4E69->unk_1e = 1;
  return 0;
}

bool32 FUN_08022474(UnkStruct52* p, UnkStruct08daadb8* data) {
  if (data->unk_3 != 0) {
    p->unk_3 = data->unk_3;
    return TRUE;
  }
  return FALSE;
}

bool32 FUN_08022488(UnkStruct52* p, u32 val) {
  if (p->unk_3 == val) {
    FUN_08022448();
    p->unk_3 = 0;
    return TRUE;
  }
  return FALSE;
}

// id に対応するスクリプトIDを unk_28/unk_48 のテーブルから引く (見つからなければ 0)
u16 FUN_080224a8(u32 id) {
  Entity4E69* p = gEntity4E69;
  s32 i;
  if (p == NULL) {
    return 0;
  }
  for (i = 0; i < p->unk_22; i++) {
    if (p->unk_28[i] == id) {
      return p->unk_48[i];
    }
  }
  return 0;
}

// p の unk_0/unk_2 に一致するノードを探し、その現在と逆側の面に p を追加する
s32 FUN_080224f0(UnkStruct08daadb8* p) {
  if (gEntity4E69 == NULL) {
    return -1;
  }
  return FUN_08022128(gEntity4E69, p);
}

// スクリプトのキーワード引数から設定を読み込み、unk_28/unk_48 のテーブルを作る
s32 FUN_08022510(void) {
  Entity4E69* p = gEntity4E69;
  UnkStruct52* node;
  s32 i;
  if (p == NULL || p->unk_23 == 1) {
    return -1;
  }
  p->unk_23 = 1;
  p->unk_18 = VM_GetKeywordValue(0x64, -1);
  p->unk_1a = VM_GetKeywordValue(0x63, -1) - 1;
  p->unk_1c = 0;
  p->unk_1e = 1;
  p->unk_1f = 0;
  p->scriptID_20 = VM_GetKeywordValue(0x65, 0);
  p->unk_22 = 0;
  if (VM_SeekToKeyword(0x70)) {
    for (i = 0; i < 16; i++) {
      if (VM_GetPC() == NULL) {
        break;
      }
      p->unk_28[p->unk_22] = Script_GetValue();
      if (VM_GetPC() == NULL) {
        break;
      }
      p->unk_48[p->unk_22] = Script_GetValue();
      p->unk_22++;
    }
  }
  p->unk_6c = 0;
  node = &p->unk_78;
  node->unk_6[0] = 0;
  node->unk_6[1] = 0;
  node->unk_3 = 0;
  return 0;
}

s32 FUN_080225d4(void) {
  Entity4E69* p = gEntity4E69;
  if (p == NULL) {
    return -1;
  }
  p->unk_23 = 0;
  p->unk_18 = 0xFFFF;
  p->unk_1a = -1;
  p->unk_1c = 0;
  p->unk_1e = 0;
  p->unk_1f = 0;
  p->scriptID_20 = 0;
  p->unk_22 = 0;
  p->unk_6c = 0;
  return 0;
}

s32 FUN_08022618(void) {
  if (gEntity4E69 == NULL || gEntity4E69->unk_70 == 0) {
    return -1;
  }
  gEntity4E69->unk_70 = 0;
  FUN_08022448();
  return 0;
}

bool32 FUN_08022644(void) {
  if (gEntity4E69 == NULL || gEntity4E69->unk_23 != 1) {
    return FALSE;
  }
  return TRUE;
}
