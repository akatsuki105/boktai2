#include "vm.h"

#include "entity.h"
#include "file.h"
#include "global.h"
#include "malloc.h"

static void FUN_08231c80(void);
void FUN_082324b0(void);
void VM_ClearScratchpad(void);
u32 VM_ParseParameter(u32 idx);
u32 VM_GetVariable(u32 varidx);
char* Textbox_LookupString(s32 stringID);
u8* VM_ReadMemory(u8* pc, s32* op, void* out);
u32 VM_RunExpression(u8* pc);
s32 Script_Exec(u8* pc, ScriptArgs* args, s32 varIdx);
u8* FUN_0823201c(u8* pc, u8* dst);

extern u32 gScriptDirectoryBuildTime;  // 0x03004594

static const ScriptArgs sEmptyArgs = {0, 0, NULL};  // 引数無しでスクリプトを呼ぶときに束縛されるデフォルトの引数記述子

// https://boktaihacking.net/wiki/Bytecode#Container_lengths
u8* VM_ReadContainerLength(u8* pc, u32* length) {
  s32 nibble = pc[0] & 0xF;
  switch (nibble) {
    case 0xD: {
      *length = pc[1];
      return pc + 2;
    }
    case 0xE: {
      u32 hi = pc[2] << 8;
      *length = pc[1] | hi;
      return pc + 3;
    }
    case 0xF: {
      u8* p = pc + 1;
      u32 hi = (p[2] << 16) | (p[1] << 8);
      *length = hi | pc[1];
      return pc + 4;
    }
    default: {
      *length = nibble;
      return pc + 1;
    }
  }
}

// 次のキーワード命令または終了命令（いずれか先に出現する方）までのバイト数 を取得
// https://boktaihacking.net/wiki/Bytecode#Opcode_0x60_(control)
u8* VM_ReadCtrlNextKeyword(u8* pc, u32* length) {
  if (pc[0] & 0x80) {
    u32 hi = pc[1] << 8;
    *length = (pc[0] | hi) & 0x7FFF;
    return pc + 2;
  }
  *length = pc[0];
  return pc + 1;
}

/**
 * @brief pcの内容を見て、型(どの命令由来か) と 値 を取得する
 * @param pc デコードするバイト列の先頭アドレス
 * @param type valの型(どの命令由来か)をここに格納する
 * @param val デコードした値を格納するバッファ
 * @return デコード後の次の命令のアドレス
 */
NON_MATCH u8* VM_DecodeValue(u8* pc, s32* type, void* val) {
#ifdef NONMATCHING_C
  u32 length;
  u8* p = pc;
  s32 cmd = *p;
  s32 nibble = cmd & 0xF0;

  if ((nibble & 0xC0) == 0xC0) {
    *type = OP_S32;
    *(s32*)val = (*p & ~0xC0) - 1;
    p += 1;
  } else if (nibble == 0) {
    *type = cmd;
    p += 1;
    switch (cmd) {
      case OP_END: {
        p = NULL;
        break;
      }
      case OP_S16:
      case OP_U24: {
        *(s32*)val = (s16)((p[1] << 8) | p[0]);
        p += 2;
        break;
      }
      case OP_S32:
      case OP_S32_0x0A:
      case OP_S32_0x0D: {
        *(s32*)val = (p[3] << 24) | (p[2] << 16) | (p[1] << 8) | p[0];
        p += 4;
        break;
      }
      case OP_U16: {
        *(s32*)val = (p[1] << 8) | p[0];
        p += 2;
        break;
      }
      case OP_U8:
      case OP_U8_0x03:
      case OP_BOOL8: {
        *(s32*)val = p[0];
        p += 1;
        break;
      }
      case OP_STRING: {
        *(s32*)val = (s32)(p + 1);
        p += p[0] + 1;
        break;
      }
      case OP_STRING_REF: {
        s32 stringID = (p[1] << 8) | p[0];
        *(s32*)val = (s32)Textbox_LookupString(stringID);
        *type = OP_STRING;
        p += 2;
        break;
      }
    }
  } else {
    *type = nibble;
    switch (nibble) {
      case OP_MEMORY:
      case OP_MEMORY_INDEXED: {
        return VM_ReadMemory(pc, type, val);
      }
      case OP_PARAMETER: {
        u8 idx = p[0] & 0xF;
        if (idx == 0xF) {
          *(u32*)val = VM_ParseParameter(p[1] + 0xF);
          p += 1;
        } else {
          *(u32*)val = VM_ParseParameter(idx);
        }
        *type = OP_S32;
        p += 1;
        break;
      }
      case OP_VARIABLE: {
        *(u32*)val = VM_GetVariable(p[0] & 0xF);
        *type = OP_S32;
        p += 1;
        break;
      }
      case OP_BLOCK: {
        p = VM_ReadContainerLength(p, &length);
        *(s32*)val = (s32)p;
        p += length;
        break;
      }
      case OP_EXPRESSION: {
        p = VM_ReadContainerLength(p, &length);
        *(s32*)val = VM_RunExpression(p);
        p += length;
        break;
      }
      case OP_KEYWORD: {
        p = VM_ReadContainerLength(p, &length);
        *type |= *p << 16;
        *(s32*)val = (s32)(p + 1);
        p += length;
        break;
      }
    }
  }
  return p;
#else
  INCFUNC("asm/func/VM_DecodeValue.inc");
#endif
}

void FUN_08231438(void) { gVM.framePointer = &gVM.frameStack[0]; }

void* VM_BindFrameBuffer(ScriptArgs* args, s32 idx) {
  u32* base;
  u32* p;

  if (args == NULL) {
    return NULL;
  }
  base = (u32*)gVM.framePointer;
  p = base + idx;
  *p = (u32)args;
  gVM.framePointer = (u8*)(p + 1);
  return (void*)base;
}

void VM_UnbindFrameBuffer(void* ptr) {
  if (ptr != NULL) {
    gVM.framePointer = ptr;
  }
}

// idx==0 は呼び出し元の結果(r)、idx>=1 は呼び出し元フレームの idx-1 番目の引数(p0, p1, ...)を返す
u32 VM_ParseParameter(u32 idx) {
  ScriptArgs* args;
  if (idx == 0) {
    return (u32)gVM.result;
  }
  args = *(ScriptArgs**)((u32*)gVM.framePointer - 1);
  return args->argv[idx - 1];
}

// パラメータスタックの framePointer を先頭として、varidx 番目の変数を読む
u32 VM_GetVariable(u32 varidx) { return *((u32*)gVM.framePointer - (varidx + 1)); }

// パラメータスタックの framePointer を先頭として、varidx 番目の変数に書き込む
void VM_StoreVariable(u32 varidx, u32 val) { *((u32*)gVM.framePointer - (varidx + 1)) = val; }

void FUN_082314d4(void) { gVM.keywordSeekStackTop = (u8*)gVM.keywordSeekStack; }

// FUN_082314f4(unk_08を4バイト戻す)と対になっており、push相当の操作と思われる
void FUN_082314e4(u8* pc) {
  u8** p = (u8**)gVM.keywordSeekStackTop;
  *p++ = pc;
  gVM.keywordSeekStackTop = (u8*)p;
}

void FUN_082314f4(void) { gVM.keywordSeekStackTop -= 4; }

void VM_SetPC(u8* addr) { gVM.pc = addr; }

// FUN_082314e4 でpushされた keywordSeekStackTop スタック最上位の pc から探索を始める
bool32 VM_SeekToKeyword(u8 keyword) {
  u8* pc = *(u8**)(gVM.keywordSeekStackTop - 4);
  s32 type;
  u8* val;

  while (TRUE) {
    pc = VM_DecodeValue(pc, &type, &val);
    if (type == 0) {
      return 0;
    }
    if ((type & 0xF0) == OP_KEYWORD && (type >> 16) == keyword) {
      gVM.pc = val;
      return (bool32)val;
    }
  }
}

// 現在位置から次のキーワード(case/default等)まで読み進め、そのキーワード種別を返す。見つからなければ0
s32 VM_Ctrl_Switch_Internal(void) {
  u8* pc = gVM.pc;
  if ((pc == NULL) || (*pc == 0)) return 0;

  while (TRUE) {
    s32 type;
    u8* val;
    pc = VM_DecodeValue(pc, &type, &val);
    if (type == 0) {
      return 0;
    }
    if ((type & 0xF0) == OP_KEYWORD) {
      gVM.pc = val;
      return type >> 16;
    }
  }
}

u32 VM_GetValueAt(u8* addr) {
  s32 type, val;
  gVM.pc = VM_DecodeValue(addr, &type, &val);
  return val;
}

s32 FUN_082315c0(u8* pc, s32* out) {
  s32 type;
  s32 val;
  s32 i;

  for (i = 0; i < 3; i++) {
    pc = VM_DecodeValue(pc, &type, &val);
    out[i] = val;
  }
  gVM.pc = pc;
  return 0;
}

NAKED s32 FUN_082315f4(u8* pc, unknown* r1) { INCFUNC("asm/func/FUN_082315f4.inc"); }

void* VM_GetValueAtSafe(u8* addr) {
  s32 type;
  void* val;

  if (addr == NULL) {
    return NULL;
  }
  gVM.pc = VM_DecodeValue(addr, &type, &val);
  if (gVM.pc == NULL) {
    return NULL;
  }
  return val;
}

void* VM_GetValueAtSafe_Proxy(u8* addr) { return VM_GetValueAtSafe(addr); }

// string-ref (opcode: 0x0E)
s32 VM_ParseStringRef(u8* pc) {
  s32 val = (s16)((pc[2] << 8) | pc[1]);
  gVM.pc = pc + 3;
  return val;
}

void FUN_0823167c(u8* dst) { gVM.pc = FUN_0823201c(VM_GetPC(), dst); }

NAKED u8* FUN_08231698(u8* pc) { INCFUNC("asm/func/FUN_08231698.inc"); }

u8* VM_GetPC(void) {
  u8* pc = gVM.pc;
  if (pc == NULL || *pc == OP_END || (*pc & 0xF0) == OP_KEYWORD) {
    return NULL;
  }
  return pc;
}

// 現在のスクリプトPC位置の値を読む
u32 Script_GetValue(void) { return VM_GetValueAt(VM_GetPC()); }

s32 FUN_082316f4(s32* out) { return FUN_082315c0(VM_GetPC(), out); }

s32 FUN_08231708(s32* out) { return FUN_082315f4(VM_GetPC(), out); }

// VM_GetValueSafe2 と全く同じ
void* VM_GetValueSafe1(void) { return VM_GetValueAtSafe(VM_GetPC()); }

// VM_GetValueSafe1 と全く同じ
void* VM_GetValueSafe2(void) { return VM_GetValueAtSafe(VM_GetPC()); }

static s32 UNUSED FUN_0823173c(void) { return VM_ParseStringRef(VM_GetPC()); }

// 指定キーワード(例: case/default)が見つかればその値を、見つからなければ fallback を返す
s32 VM_GetKeywordValue(u8 val, s32 fallback) {
  if (VM_SeekToKeyword(val) != 0) {
    return (s32)VM_GetValueAt(VM_GetPC());
  }
  return fallback;
}

void FUN_08231770(void) {
  FUN_08231438();
  FUN_082314d4();
}

void FUN_08231780(void) { gCtrlHandlers = NULL; }

s32 VM_AddCtrlHandlers(SubroutineTable* p) {
  p->next = gCtrlHandlers;
  gCtrlHandlers = p;
  return 0;
}

// gCtrlHandlers リストから p を取り除く
s32 VM_RemoveCtrlHandlers(SubroutineTable* p) {
  SubroutineTable* cur;
  SubroutineTable* prev;

  if (gCtrlHandlers == p) {
    gCtrlHandlers = p->next;
  }

  cur = gCtrlHandlers;
  prev = cur;
  if (cur != NULL) {
    do {
      if (cur == p) {
        prev->next = cur->next;
        return 0;
      }
      prev = cur;
      cur = cur->next;
    } while (cur != NULL);
  }
  return -1;
}

// gCtrlHandlers から subID に対応するハンドラを探す
Subroutine* VM_GetControlHandler(u32 subID) {
  SubroutineTable* t = gCtrlHandlers;
  const Subroutine* arr;
  s32 i;

  while (t != NULL) {
    arr = t->arr;
    i = t->len;
    if (i > 0) {
      do {
        if (arr->id == subID) {
          return (Subroutine*)arr;
        }
        arr++;
        i--;
      } while (i > 0);
    }
    t = t->next;
  }
  return NULL;
}

// control命令(id)をIDで解決し、その範囲末尾をunk_08スタックにpushした状態でハンドラを実行する
bool32 VM_RunControl(u8* pc) {
  Subroutine* h;
  u8* newPc;
  u32 length;
  bool32 result;
  bool32 (*fn)(u8*);
  u32 id;

  id = (pc[1] << 8) | pc[0];
  pc += 2;
  h = VM_GetControlHandler(id);
  newPc = VM_ReadCtrlNextKeyword(pc, &length);
  FUN_082314e4(newPc + length);
  VM_SetPC(newPc);
  fn = (bool32 (*)(u8*))h->fn;
  result = fn(newPc);
  FUN_082314f4();
  return result;
}

/**
 * @brief ScriptDirectory.script_entries をパースするだけ
 * @param offsets ScriptDirectory.script_entries (= 0x08cbf24c)
 * @param length ここにスクリプトの数を書き込む
 * @return &ScriptDirectory.offsets (= 0x08cca69c)
 */
void* VM_Parse_ScriptDirectory_ScriptEntries(s32* offsets, s32* length) {
  s32 count = 0;
  s32* p = offsets;

  while (*p != -1) {
    p++;
    count++;
  }
  *length = count;
  return p + 1;
}

/**
 * @param scriptID スクリプトID, gScriptTable.entries のインデックスに変換する際に -1 することに注意
 * @param unk ScriptDirectory.script_entries のエントリの bit24..31 をここに書き込む (用途不明)
 */
u8* Script_LookupById(u32 scriptID, u32* unk) {
  u32 idx = (scriptID & 0x7FFFFFFF) - 1;
  u8* ptr = (u8*)&gScriptTable.entries[idx];
  *unk = ptr[3];
  return &gScriptTable.bytecode[(*(s32*)ptr) & 0x00FFFFFF];
}

s32 Script_ExecById(u32 scriptID, ScriptArgs* args) {
  u32 unk, length;
  u8* pc = Script_LookupById(scriptID, &unk);
  pc = VM_ReadContainerLength(pc, &length);
  return Script_Exec(pc, args, unk);
}

// 呼び出し先スクリプトIDと引数列を読み取り、引数記述子を組み立ててそのスクリプトを実行する
s32 VM_CallScript(u8* pc) {
  u32 argv[16];
  s32 type;
  s32 val;
  ScriptArgs args;
  s32 scriptID;
  u32 count;

  scriptID = (s16)((pc[1] << 8) | pc[0]);
  pc += 2;
  count = 0;
  while (TRUE) {
    pc = VM_DecodeValue(pc, &type, &val);
    if (type == 0) {
      break;
    }
    argv[count] = val;
    count++;
  }

  args.argc = count;
  args.argv = argv;
  return Script_ExecById(scriptID, &args);
}

NAKED void* UNUSED FUN_0823193c(void* p, u32 param_2, s32 param_3) { INCFUNC("asm/func/FUN_0823193c.inc"); }

char* Textbox_LookupString(s32 stringID) {
  void** base = (void**)&gStringTable;
  s32 byteOffset = stringID * 4;
  u32 stringIndex = (u32)base[1];
  u8* p = (u8*)(byteOffset + stringIndex);
  u32 offset = ((p[3] << 24) | (p[2] << 16) | (p[1] << 8) | p[0]) & 0x7FFFFFFF;
  return (char*)base[2] + offset;
}

/**
 * @param d &gScriptDirectory (0x08CBF248)
 * @note 0x082319A8
 */
NON_MATCH static s32 VM_MountScriptDirectory(ScriptDirectory* d) {
#ifdef NONMATCHING_C
  s32 count;
  s32* entries;
  u8* offsets;
  u8* special;
  u32 val;
  u8* q;
  u8* p = (u8*)d;
  ScriptTable* t = &gScriptTable;

  gScriptDirectoryBuildTime = (p[3] << 24) | (p[2] << 16) | (p[1] << 8) | p[0];

  entries = (s32*)(p + 4);
  offsets = (u8*)VM_Parse_ScriptDirectory_ScriptEntries(entries, &count);
  t->entries = (u32*)entries;
  t->scriptCount = count;
  gStringTable.offsets = (ScriptDirectoryOffsets*)offsets;

  q = offsets + 4;
  val = (q[3] << 24) | (q[2] << 16) | (q[1] << 8) | q[0];
  gStringTable.stringIndex = (u32*)(offsets + val);

  q += 4;
  val = (q[3] << 24) | (q[2] << 16) | (q[1] << 8) | offsets[8];
  gStringTable.stringData = offsets + val;

  q += 4;
  val = (q[3] << 24) | (q[2] << 16) | (q[1] << 8) | offsets[12];
  gStringTable.unknown = offsets + val;

  val = (offsets[3] << 24) | (offsets[2] << 16) | (offsets[1] << 8) | offsets[0];
  special = offsets + val;
  t->bytecode = special + 4;

  val = (special[3] << 24) | (special[2] << 16) | (special[1] << 8) | special[0];
  t->special_script_data = val + special + 8;

  return 0;
#else
  INCFUNC("asm/func/VM_MountScriptDirectory.inc");
#endif
}

void* UNUSED FUN_08231a74(void) { return gStringTable.unknown + 4; }

void VM_SaveScriptTable(u8* dst) {
  *((ScriptTable*)dst) = gScriptTable;
  dst += sizeof(ScriptTable);
  *((StringTable*)dst) = gStringTable;
}

void VM_RestoreScriptTable(u8* src) {
  gScriptTable = *((ScriptTable*)src);
  src += sizeof(ScriptTable);
  gStringTable = *((StringTable*)src);
}

// ブロック内の文(式/control/呼び出し)を順に実行する。controlがreturnを表す場合(戻り値1)そこで打ち切る
bool32 Script_ExecBlock(u8* pc, ScriptArgs* args, s32 idx) {
  void* frame;
  u32 length;
  s32 nibble;
  bool32 result;

  frame = VM_BindFrameBuffer(args, idx);
  while (pc != NULL) {
    nibble = *pc & 0xF0;
    switch (nibble) {
      case OP_CONTROL: {
        pc = VM_ReadContainerLength(pc, &length);
        if (VM_RunControl(pc) == 1) {
          result = 1;
          goto done;
        }
        pc = pc + length;
        continue;
      }
      case OP_CALL: {
        pc = VM_ReadContainerLength(pc, &length);
        gVM.result = (void*)VM_CallScript(pc);
        pc = pc + length;
        continue;
      }
      case OP_END: {
        goto fail;
      }
      case OP_EXPRESSION: {
        pc = VM_ReadContainerLength(pc, &length);
        gVM.result = (void*)VM_RunExpression(pc);
        pc = pc + length;
        continue;
      }
      default: {
        continue;
      }
    }
  }
fail:
  result = 0;
done:
  VM_UnbindFrameBuffer(frame);
  return result;
}

s32 Script_ExecByPointer(u8* pc, ScriptArgs* args) {
  if (Script_ExecBlock(pc, args, 0) == 1) {
    return (s32)gVM.result;
  }
  gVM.result = NULL;
  return 0;
}

/**
 * @param pc 実行するブロックの先頭アドレス
 * @param args ブロック内から変数varIdxとして読める値。NULLなら引数無しを表す sEmptyArgs がデフォルト値として束縛される
 * @param varIdx valを束縛する変数スロット番号(VM_GetVariableのvaridxに対応)
 */
s32 Script_Exec(u8* pc, ScriptArgs* args, s32 varIdx) {
  if (args == NULL) {
    args = (ScriptArgs*)&sEmptyArgs;
  }
  if (Script_ExecBlock(pc, args, varIdx) == 1) {
    return (s32)gVM.result;
  }
  gVM.result = NULL;
  return 0;
}

void VM_ExecSpecial(void) {
  u32 length;
  u8* pc = VM_ReadContainerLength(gScriptTable.special_script_data, &length);
  Script_ExecByPointer(pc, (ScriptArgs*)&sEmptyArgs);
}

s32 FUN_08231bcc(void) {
  if (Script_GetValue() == 0) {
    VM_GetValueSafe1();
  }
  return 0;
}

void SetMapInitScriptID(u32 scriptID) { gMapInitScriptID = scriptID; }

void FUN_08231bec(void) {
  FUN_08231770();
  FUN_08231c80();
  FUN_08231780();
  FUN_082324b0();
  VM_MountScriptDirectory(GetFile(DIR_SCRIPT, 0xA41E));
  SetMapInitScriptID(0);
}

void VM_ClearScratchpad_Proxy(void) { VM_ClearScratchpad(); }

NAKED void RandomizeGameStateAddr(void) { INCFUNC("asm/func/RandomizeGameStateAddr.inc"); }

static void FUN_08231c80(void) {
  ClearMemory(gWorld, sizeof(World));
  ClearMemory(gStat, sizeof(GameInfo));
}

NAKED void FUN_08231ca8(void) { INCFUNC("asm/func/FUN_08231ca8.inc"); }

void Save_BackupStatAndWorld(void) {
  CopyMemory((void*)gStatBackup, (void*)gStat, sizeof(GameInfo));
  CopyMemory((void*)gWorldBackup, (void*)gWorld, sizeof(World));
}

void RestoreGameState(void) {
  CopyMemory((void*)gStat, (void*)gStatBackup, sizeof(GameInfo));
  CopyMemory((void*)gWorld, (void*)gWorldBackup, sizeof(World));
}

// gStat を フィールド単位でバックアップするための関数
void FUN_08231d5c(void* statFieldPtr, s32 bytesize) {
  s32 offset = (s32)statFieldPtr - (s32)gStat;
  CopyMemory((u8*)gStatBackup + offset, (u8*)statFieldPtr, bytesize);
}

// gStatのフィールドのアドレスを受け取り、gStatBackupの対応するフィールドのアドレスを返す
void* FUN_08231d80(void* statFieldPtr) {
  s32 offset = (s32)statFieldPtr - (s32)gStat;
  return (u8*)gStatBackup + offset;
}

void VM_ClearScratchpad(void) { ClearMemory(gScratch, sizeof(UnkGameStruct)); }

void Script_LoadPointer(u8* src, s32 cmdAndArgs, s32 offset, u32* out) {
  switch ((cmdAndArgs >> 0x18) & 0xF) {
    case OP_S32: {
      src += offset * 4;
      *out = (src[3] << 24) | (src[2] << 16) | (src[1] << 8) | src[0];
      break;
    }
    case OP_U24: {
      src += offset * 4;
      *out = (src[1] << 8) | src[0];
      break;
    }
    case OP_S16:
    case OP_U16: {
      *out = *(s16*)(src + (offset << 1));
      break;
    }
    case OP_U8:
    case OP_U8_0x03: {
      src += offset;
      *out = *src;
      break;
    }
    case OP_BOOL8: {
      u8* p;
      s32 mask;
      offset += (cmdAndArgs >> 0x10) & 0xF;
      p = src + (offset >> 3);
      mask = 1 << (offset & 7);
      *out = (*p & mask) != 0;
      break;
    }
    default: {
      break;
    }
  }
}

NAKED u8* VM_ReadMemory(u8* pc, s32* op, void* out) { INCFUNC("asm/func/VM_ReadMemory.inc"); }

void Script_StorePointerCore(u8* dst, s32 cmdAndArgs, s32 offset, u32 val) {
  switch (((cmdAndArgs >> 0x18) & 0xF)) {
    case OP_S32: {
      u32* q = (u32*)(dst + offset * 4);
      *q = val;
      break;
    }
    case OP_U24: {
      u8* q = dst + offset * 4;
      q[2] = (u8)((s32)val >> 16);
      q[1] = (u8)((s32)val >> 8);
      q[0] = (u8)val;
      break;
    }
    case OP_S16:
    case OP_U16: {
      *(s16*)(dst + (offset << 1)) = (u16)val;
      break;
    }
    case OP_U8:
    case OP_U8_0x03: {
      dst[offset] = (u8)val;
      break;
    }
    case OP_BOOL8: {
      s32 mask;
      offset += (cmdAndArgs >> 0x10) & 0xF;
      dst += offset >> 3;
      mask = 1 << (offset & 7);
      if (val != 0) {
        *dst |= mask;
      } else {
        *dst &= ~mask;
      }
      break;
    }
    default: {
      break;
    }
  }
}

NAKED u8* Script_StorePointer(u8* pc, u32 val) { INCFUNC("asm/func/Script_StorePointer.inc"); }

u8* FUN_0823201c(u8* pc, u8* dst) {
  s32 type;
  s32 valA;
  s32 valB;
  u8* newPc;
  s32 zero;

  CopyMemory(dst, pc, 4);
  if ((dst[0] & 0xF0) == OP_MEMORY_INDEXED) {
    newPc = VM_DecodeValue(pc + 4, &type, &valA);
    newPc = VM_DecodeValue(newPc, &type, &valB);
    *(s16*)(dst + 4) = valA;
    *(s16*)(dst + 6) = valB;
  } else {
    newPc = pc + 4;
    zero = 0;
    *(s16*)(dst + 4) = 1;
    *(s16*)(dst + 6) = zero;
  }
  return newPc;
}

// pc上の4バイトのPointer/Indexed Pointer記述子を読み、対象領域(gStat/gScratch/gWorld)内のアドレスを解決してvalを書き込む
void FUN_0823206c(u8* pc, s32 offset, u32 val) {
  u8* dst;
  u32 cmd = (pc[0] << 24) | (pc[1] << 16) | (pc[2] << 8) | pc[3];

  if ((cmd & 0xF00000) == 0x800000) {
    dst = (u8*)gStat;
  } else if ((cmd & 0xF00000) == 0x100000) {
    dst = (u8*)gScratch;
  } else {
    dst = (u8*)gWorld;
  }
  dst += cmd & 0xFFFF;

  if (((cmd >> 24) & 0xF0) == OP_MEMORY_INDEXED) {
    offset += *(u16*)(pc + 6);
  }

  Script_StorePointerCore(dst, cmd, offset, val);
}

// pc上の4バイトのPointer/Indexed Pointer記述子を読み、対象領域(gStat/gScratch/gWorld)内のアドレスを解決してその値を読む
u32 FUN_082320e4(u8* pc, s32 offset) {
  u8* src;
  u32 out;
  u32 cmd = (pc[0] << 24) | (pc[1] << 16) | (pc[2] << 8) | pc[3];

  if ((cmd & 0xF00000) == 0x800000) {
    src = (u8*)gStat;
  } else if ((cmd & 0xF00000) == 0x100000) {
    src = (u8*)gScratch;
  } else {
    src = (u8*)gWorld;
  }
  src += cmd & 0xFFFF;

  if (((cmd >> 24) & 0xF0) == OP_MEMORY_INDEXED) {
    offset += *(u16*)(pc + 6);
  }

  Script_LoadPointer(src, cmd, offset, &out);
  return out;
}

// pc上のPointer/Indexed Pointer記述子が指す現在値を読み、対応するBackup領域(gStatBackup/gWorldBackup)へ書き込む
u8* FUN_08232160(u8* pc) {
  u8 buf[8];
  u8* p = buf;
  s32 offset = 0;
  u8* newPc;
  u32 val;
  u8* dst;
  u32 cmd;

  newPc = FUN_0823201c(pc, buf);
  val = FUN_082320e4(buf, 0);
  cmd = (buf[0] << 24) | (p[1] << 16) | (p[2] << 8) | p[3];

  if ((cmd & 0xF00000) == 0x800000) {
    dst = (u8*)gStatBackup;
  } else {
    dst = (u8*)gWorldBackup;
  }
  dst += cmd & 0xFFFF;

  if (((cmd >> 24) & 0xF0) == OP_MEMORY_INDEXED) {
    offset += *(u16*)(p + 6);
  }

  Script_StorePointerCore(dst, cmd, offset, val);
  return newPc;
}

// pc上のPointer/Indexed Pointer記述子が指すBackup領域(gStatBackup/gWorldBackup)内の値を読む
u32 FUN_082321e0(u8* pc) {
  u8 buf[8];
  u8* p = buf;
  s32 offset = 0;
  u8* src;
  u32 cmd;
  u32 out;

  FUN_0823201c(pc, buf);
  cmd = (buf[0] << 24) | (p[1] << 16) | (p[2] << 8) | p[3];

  if ((cmd & 0xF00000) == 0x800000) {
    src = (u8*)gStatBackup;
  } else {
    src = (u8*)gWorldBackup;
  }
  src += cmd & 0xFFFF;

  if (((cmd >> 24) & 0xF0) == OP_MEMORY_INDEXED) {
    offset += *(u16*)(p + 6);
  }

  Script_LoadPointer(src, cmd, offset, &out);
  return out;
}

GameInfo* FUN_08232254(void) { return gStatBackup; }

World* FUN_08232260(void) { return gWorldBackup; }
