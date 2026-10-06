#include "vm.h"

#include "entity.h"
#include "file.h"
#include "global.h"
#include "malloc.h"
#include "vm_subroutine.h"

static void ClearStatAndWorld(void);
void FUN_082324b0(void);
void VM_ClearScratchpad(void);
void Save_BackupStatAndWorld(void);
u32 VM_ParseParameter(u32 idx);
u32 VM_GetVariable(u32 varidx);
u8* VM_ReadMemory(u8* pc, s32* op, void* out);
u32 VM_RunExpression(u8* pc);
s32 VM_Exec(u8* pc, ScriptArgs* args, s32 varIdx);
u8* FUN_0823201c(u8* pc, u8* dst);

static const ScriptArgs sEmptyArgs = {0, NULL};  // 引数無しでスクリプトを呼ぶときに束縛されるデフォルトの引数記述子

IWRAM_DATA ScriptTable gScriptTable = {};  // 0x03000748
IWRAM_DATA StringTable gStringTable = {};  // 0x03000758

// 0x03000768, CtrlHandlerTable のリンクリスト, これが制御命令のハンドラ, なんでこんな構造にしてるのか全くわからん
IWRAM_DATA CtrlHandlerTable* gCtrlHandlers = NULL;

IWRAM_DATA u8 u8_0300076c[4] = {};  // padding?

#define READ_U32LE(u8ptr) (((u8ptr)[3] << 24) | ((u8ptr)[2] << 16) | ((u8ptr)[1] << 8) | (u8ptr)[0])

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

// 最初のラベル命令, 無ければ終端命令までのバイト数を取得
// https://boktaihacking.net/wiki/Bytecode#Opcode_0x60_(control)
u8* VM_ReadCtrlLabelOffset(u8* pc, u32* offset) {
  if (pc[0] & 0x80) {
    u32 hi = pc[1] << 8;
    *offset = (pc[0] | hi) & 0x7FFF;
    return pc + 2;
  }
  *offset = pc[0];
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
      case OP_LABEL: {
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

void VM_ResetScriptStack(void) { gVM.scriptStackTop = &gVM.scriptStack[0]; }

/**
 * @brief スクリプトのスタックフレームを作る
 * @param args スクリプトの引数
 * @param localVarCount このスクリプトが使うローカル変数の数
 * @return u32* 呼び出し元のスタックフレームのベースアドレス(スクリプト終了時に積んだ分を戻すため)
 */
u32* VM_PushScriptFrame(ScriptArgs* args, s32 localVarCount) {
  u32* base;
  u32* sp;

  if (args == NULL) {
    return NULL;
  }

  base = gVM.scriptStackTop;
  sp = base + localVarCount;  // ローカル変数 (v1, v2, ...)
  *sp = (u32)args;

  gVM.scriptStackTop = sp + 1;
  return base;
}

void VM_PopScriptFrame(u32* ptr) {
  if (ptr != NULL) {
    gVM.scriptStackTop = ptr;
  }
}

// idx==0 は呼び出し元の結果(r)、idx>=1 は呼び出し元フレームの idx-1 番目の引数(p0, p1, ...)を返す
u32 VM_ParseParameter(u32 idx) {
  ScriptArgs* args;
  if (idx == 0) {
    return (u32)gVM.result;
  }
  args = *(ScriptArgs**)(gVM.scriptStackTop - 1);
  return args->argv[idx - 1];
}

// スクリプトのローカル変数を取得する (.bokc では v1, v2, ... に対応)
u32 VM_GetVariable(u32 scriptLocalVarIdx) {
  // スタックフレーム(スクリプトの引数が3個 で ローカル変数2個 の場合)
  // アドレスが大きくなる方に伸びることに注意
  //               base[3]  <- 現在の scriptStackTop
  //  ScriptArgs*  base[2]  -> {argc: 3, argv: [p0, p1, p2]}
  //  v1           base[1]  v1: ローカル変数1, VM_GetVariable(1) はこの値を返す
  //  v2           base[0]  v2: ローカル変数2, VM_GetVariable(2) はこの値を返す
  return *(gVM.scriptStackTop - (1 + scriptLocalVarIdx));
}

// スクリプトのローカル変数を更新する (.bokc では v1, v2, ... に対応)
// スタックのメモリレイアウトは VM_GetVariable を参照
void VM_StoreVariable(u32 scriptLocalVarIdx, u32 val) { *(gVM.scriptStackTop - (1 + scriptLocalVarIdx)) = val; }

void VM_ResetSubroutineStack(void) { gVM.subroutineStackTop = gVM.subroutineStack; }

void VM_PushSubroutineStack(u8* pc) {
  u8** p = gVM.subroutineStackTop;
  *p++ = pc;
  gVM.subroutineStackTop = p;
}

void VM_PopSubroutineStack(void) { gVM.subroutineStackTop -= 1; }

void VM_SetPC(u8* addr) { gVM.pc = addr; }

// subroutineStack の最上位に積まれた位置から探索を始める
bool32 VM_SeekToNamedArg(u8 name) {
  u8* pc = *(gVM.subroutineStackTop - 1);

  while (TRUE) {
    s32 type, val;
    pc = VM_DecodeValue(pc, &type, &val);
    if (type == 0) {
      return 0;
    }
    if ((type & 0xF0) == OP_LABEL && (type >> 16) == name) {
      gVM.pc = (u8*)val;
      return val;
    }
  }
}

// 現在位置から次のラベルまで読み進め、その文字を返す, 見つからなければ0
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
    if ((type & 0xF0) == OP_LABEL) {
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

s32 VM_GetThreeValuesAt(u8* pc, s32* out) {
  s32 i;

  for (i = 0; i < 3; i++) {
    s32 type, val;
    pc = VM_DecodeValue(pc, &type, &val);
    out[i] = val;
  }
  gVM.pc = pc;
  return 0;
}

// VM_GetThreeValuesAt と同じだが, 値を s16 に切り詰めて格納する
s32 VM_GetThreeValues16At(u8* pc, s16* out) {
  s32 i;

  for (i = 0; i < 3; i++) {
    s32 type, val;
    pc = VM_DecodeValue(pc, &type, &val);
    out[i] = val;
  }
  gVM.pc = pc;
  return 0;
}

void* VM_GetValueAtSafe(u8* addr) {
  if (addr != NULL) {
    s32 type, val;
    gVM.pc = VM_DecodeValue(addr, &type, &val);
    if (gVM.pc == NULL) {
      return NULL;
    }
    return (void*)val;
  }
  return NULL;
}

void* VM_GetValueAtSafe_Proxy(u8* addr) { return VM_GetValueAtSafe(addr); }

// string-ref (opcode: 0x0E)
s32 VM_ParseStringRef(u8* pc) {
  s32 val = (s16)((pc[2] << 8) | pc[1]);
  gVM.pc = pc + 3;
  return val;
}

void FUN_0823167c(u8* dst) { gVM.pc = FUN_0823201c(VM_GetPC(), dst); }

NON_MATCH u8* FUN_08231698(u8* pc) {
#ifdef NONMATCHING_C
  VM* vm = &gVM;
  s32 type;
  s32 val;

  do {
    pc = VM_DecodeValue(pc, &type, &val);
  } while (type != 0);

  vm->pc = NULL;
  return pc;
#else
  INCFUNC("asm/func/FUN_08231698.inc");
#endif
}

u8* VM_GetPC(void) {
  u8* pc = gVM.pc;
  if (pc == NULL || *pc == OP_END || (*pc & 0xF0) == OP_LABEL) {
    return NULL;
  }
  return pc;
}

// 現在のスクリプトPC位置の値を読む
u32 VM_GetValue(void) { return VM_GetValueAt(VM_GetPC()); }

s32 VM_GetThreeValues(s32* out) { return VM_GetThreeValuesAt(VM_GetPC(), out); }

s32 VM_GetThreeValues16(s16* out) { return VM_GetThreeValues16At(VM_GetPC(), out); }

// VM_GetValueSafe2 と全く同じ
void* VM_GetValueSafe1(void) { return VM_GetValueAtSafe(VM_GetPC()); }

// VM_GetValueSafe1 と全く同じ
void* VM_GetValueSafe2(void) { return VM_GetValueAtSafe(VM_GetPC()); }

static s32 UNUSED FUN_0823173c(void) { return VM_ParseStringRef(VM_GetPC()); }

// 指定した名前付き引数が書かれていればその値を, 無ければ fallback を返す
s32 VM_GetNamedArgValue(u8 name, s32 fallback) {
  if (VM_SeekToNamedArg(name) != 0) {
    return (s32)VM_GetValueAt(VM_GetPC());
  }
  return fallback;
}

void VM_ResetStacks(void) {
  VM_ResetScriptStack();
  VM_ResetSubroutineStack();
}

void VM_ClearCtrlHandlers(void) { gCtrlHandlers = NULL; }

s32 VM_AddCtrlHandlers(CtrlHandlerTable* p) {
  p->next = gCtrlHandlers;
  gCtrlHandlers = p;
  return 0;
}

// gCtrlHandlers リストから p を取り除く
s32 VM_RemoveCtrlHandlers(CtrlHandlerTable* p) {
  CtrlHandlerTable* cur;
  CtrlHandlerTable* prev;

  if (gCtrlHandlers == p) {
    gCtrlHandlers = p->next;
  }

  cur = gCtrlHandlers;
  prev = cur;
  while (cur != NULL) {
    if (cur == p) {
      prev->next = cur->next;
      return 0;
    }
    prev = cur;
    cur = cur->next;
  }
  return -1;
}

// gCtrlHandlers から subID に対応するハンドラを探す
Subroutine* VM_GetControlHandler(u32 subID) {
  CtrlHandlerTable* t = gCtrlHandlers;

  while (t != NULL) {
    const Subroutine* arr = t->arr;
    s32 i = t->len;
    while (i > 0) {
      if (arr->id == subID) {
        return (Subroutine*)arr;
      }
      arr++, i--;
    }
    t = t->next;
  }
  return NULL;
}

// 制御命令をIDで解決し、ラベルの開始位置を subroutineStack にpushした状態でハンドラを実行する
bool32 VM_RunControl(u8* pc) {
  Subroutine* handler;
  u8* body;
  u32 labelOffset;
  bool32 result;
  u32 id = (pc[1] << 8) | pc[0];

  pc += 2;
  handler = VM_GetControlHandler(id);
  body = VM_ReadCtrlLabelOffset(pc, &labelOffset);
  VM_PushSubroutineStack(body + labelOffset);  // 最初のラベル命令
  VM_SetPC(body);

  result = (handler->fn.ctrl)(body);

  VM_PopSubroutineStack();
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
 * @param localVarCount スクリプトが必要とするローカル変数の数 (gScriptTable.entries に格納されている)
 */
u8* VM_LookupByID(u32 scriptID, u32* localVarCount) {
  // Entity0823acbc_Update で gMapInitScriptID
  //   0 なら VM_ExecSpecial
  //   0 以外なら VM_ExecByID
  // を呼ぶので、実質的に VM_ExecSpecial が scriptID 0 で、 これらが 1.. に相当するのかもしれない
  u32 idx = (scriptID & 0x7FFFFFFF) - 1;
  u8* ptr = (u8*)&gScriptTable.entries[idx];
  *localVarCount = ptr[3];
  return &gScriptTable.bytecode[(*(u32*)ptr) & 0x00FFFFFF];
}

s32 VM_ExecByID(u32 scriptID, ScriptArgs* args) {
  u32 localVarCount, length;
  u8* pc = VM_LookupByID(scriptID, &localVarCount);
  pc = VM_ReadContainerLength(pc, &length);
  return VM_Exec(pc, args, localVarCount);
}

// 呼び出し先スクリプトIDと引数列を読み取り、 ScriptArgs を組み立ててそのスクリプトを実行する
// スクリプトIDは pc から即値で読むので呼び先はコンパイル時に固定される, 実行時に選びたい場合は VM_Ctrl_CallScriptIndirect を使う
s32 VM_CallScript(u8* pc) {
  u32 argv[16];
  ScriptArgs args;
  u32 count;

  s32 scriptID = (s16)((pc[1] << 8) | pc[0]);
  pc += 2;

  count = 0;
  while (TRUE) {
    s32 type, val;
    pc = VM_DecodeValue(pc, &type, &val);
    if (type == 0) {
      break;
    }
    argv[count] = val;
    count++;
  }

  args.argc = count, args.argv = argv;
  return VM_ExecByID(scriptID, &args);
}

NAKED void* UNUSED FUN_0823193c(void* p, u32 param_2, s32 param_3) { INCFUNC("asm/func/FUN_0823193c.inc"); }

// stringID で指定した文字列を返す
char* Textbox_LookupString(s32 stringID) {
  StringTable* tbl = &gStringTable;

  // header = &gStringHeader[stringID]
  s32 byteOffset = stringID * 4;
  u8* header = (u8*)(byteOffset + (u32)tbl->header);

  return &tbl->body[(READ_U32LE(header) & 0x7FFFFFFF)];
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
  gStringTable.header = (u32*)(offsets + val);

  q += 4;
  val = (q[3] << 24) | (q[2] << 16) | (q[1] << 8) | offsets[8];
  gStringTable.body = offsets + val;

  q += 4;
  val = (q[3] << 24) | (q[2] << 16) | (q[1] << 8) | offsets[12];
  gStringTable.unknown = offsets + val;

  val = (offsets[3] << 24) | (offsets[2] << 16) | (offsets[1] << 8) | offsets[0];
  special = offsets + val;
  t->bytecode = special + 4;

  val = (special[3] << 24) | (special[2] << 16) | (special[1] << 8) | special[0];
  t->specialScriptData = val + special + 8;

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

/**
 * @brief ブロック内の文(式 / control / 別スクリプトの呼び出し)を先頭から順に実行する
 * @param pc 実行するブロックの先頭アドレス
 * @param args スクリプトに渡す引数, NULL ならスタックフレームを積まず呼び出し元のフレームのまま実行する
 * @param localVarCount スクリプトが必要とするローカル変数の数
 * @return control が return を表していた場合は TRUE (返す値は gVM.result に入っている), ブロックの終端まで実行し切った場合は FALSE
 */
bool32 VM_ExecBlock(u8* pc, ScriptArgs* args, s32 localVarCount) {
  bool32 result;

  u32* frame = VM_PushScriptFrame(args, localVarCount);
  while (pc != NULL) {
    u32 length;
    switch (*pc & 0xF0) {  // 上位ニブルがどれにも当たらない場合は pc が進まないので、不正なバイトコードを渡すとここで止まる
      case OP_CONTROL: {
        pc = VM_ReadContainerLength(pc, &length);
        if (VM_RunControl(pc) == 1) {
          result = TRUE;
          goto done;
        }
        pc += length;
        break;
      }
      case OP_CALL: {
        pc = VM_ReadContainerLength(pc, &length);
        gVM.result = (void*)VM_CallScript(pc);
        pc += length;
        break;
      }
      case OP_END: {
        pc = NULL;  // ブロックの終端なので次の文はない
        break;
      }
      case OP_EXPRESSION: {
        pc = VM_ReadContainerLength(pc, &length);
        gVM.result = (void*)VM_RunExpression(pc);
        pc += length;
        break;
      }
    }
  }
  result = FALSE;
done:
  VM_PopScriptFrame(frame);
  return result;
}

s32 VM_ExecByPointer(u8* pc, ScriptArgs* args) {
  if (VM_ExecBlock(pc, args, 0) == 1) {
    return (s32)gVM.result;
  }
  gVM.result = NULL;
  return 0;
}

/**
 * @param pc 実行するブロックの先頭アドレス
 * @param args スクリプトに渡す引数, NULLなら引数無しを表す sEmptyArgs がデフォルト値として使用される
 * @param localVarCount スクリプトが必要とするローカル変数の数
 */
s32 VM_Exec(u8* pc, ScriptArgs* args, s32 localVarCount) {
  if (args == NULL) {
    args = (ScriptArgs*)&sEmptyArgs;
  }
  if (VM_ExecBlock(pc, args, localVarCount) == 1) {
    return (s32)gVM.result;
  }
  gVM.result = NULL;
  return 0;
}

// Entity0823acbc_Update で gMapInitScriptID が 0のときに呼ばれる, ゲームの起動時に1回呼ばれるのは確認
// これがVMスクリプトのエントリポイントかも？
void VM_ExecSpecial(void) {
  u32 length;
  u8* pc = VM_ReadContainerLength(gScriptTable.specialScriptData, &length);
  VM_ExecByPointer(pc, (ScriptArgs*)&sEmptyArgs);
}

// デバッグ用の assert, SubroutineID: 0xEC1F
s32 VM_DebugAssert(void) {
  if (!VM_GetValue()) {
    VM_GetValueSafe1();  // 何もせず握り潰す, 開発環境では何かしらのエラー表示や停止処理が行われていたと思われる
  }
  return 0;
}

void SetMapInitScriptID(u32 scriptID) { gMapInitScriptID = scriptID; }

void FUN_08231bec(void) {
  VM_ResetStacks();
  ClearStatAndWorld();
  VM_ClearCtrlHandlers();
  FUN_082324b0();
  VM_MountScriptDirectory(GetFile(DIR_SCRIPT, 0xA41E));
  SetMapInitScriptID(0);
}

void VM_ClearScratchpad_Proxy(void) { VM_ClearScratchpad(); }

NAKED void RandomizeGameStateAddr(void) { INCFUNC("asm/func/RandomizeGameStateAddr.inc"); }

static void ClearStatAndWorld(void) {
  ClearMemory(gWorld, sizeof(World));
  ClearMemory(gStat, sizeof(GameInfo));
}

// ゲーム状態を初期化してバックアップを取る (gStat の先頭 0x30 バイトと unk_246 は保持する)
void FUN_08231ca8(void) {
  u16 tmp = gStat->unk_246;
  ClearMemory(gWorld, sizeof(World));
  ClearMemory(&gStat->playerX, 0x38A);
  gStat->unk_246 = tmp;
  Save_BackupStatAndWorld();
}

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

void VM_LoadPointer(u8* src, s32 cmdAndArgs, s32 offset, u32* out) {
  switch ((cmdAndArgs >> 0x18) & 0xF) {
    case OP_S32: {
      src += offset * 4;
      *out = READ_U32LE(src);
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

// pc上の4バイトのPointer/Indexed Pointer記述子を読み, 対象領域(gStat/gScratch/gWorld)内の値を out に取り出す, 命令種別は op に返す
u8* VM_ReadMemory(u8* pc, s32* op, void* out) {
  u8* src;
  u8* newPc;
  s32 type;
  s32 scale;
  s32 offset;
  u32 cmd = (pc[0] << 24) | (pc[1] << 16) | (pc[2] << 8) | pc[3];

  *op = (cmd >> 24) & 0xF;

  if ((cmd & 0xF00000) == 0x800000) {
    src = (u8*)gStat;
  } else if ((cmd & 0xF00000) == 0x100000) {
    src = (u8*)gScratch;
  } else {
    src = (u8*)gWorld;
  }
  src += cmd & 0xFFFF;

  if (((cmd >> 24) & 0xF0) == OP_MEMORY_INDEXED) {
    newPc = VM_DecodeValue(pc + 4, &type, &scale);
    newPc = VM_DecodeValue(newPc, &type, &offset);
  } else {
    offset = 0;
    newPc = pc + 4;
  }

  VM_LoadPointer(src, cmd, offset, out);
  return newPc;
}

void VM_StorePointerCore(u8* dst, s32 cmdAndArgs, s32 offset, u32 val) {
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

// pc上の4バイトのPointer/Indexed Pointer記述子を読み, 対象領域(gStat/gScratch/gWorld)内の指す先に val を書き込む
u8* VM_StorePointer(u8* pc, u32 val) {
  u8* dst;
  u8* newPc;
  s32 type;
  s32 scale;
  s32 offset;
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
    newPc = VM_DecodeValue(pc + 4, &type, &scale);
    newPc = VM_DecodeValue(newPc, &type, &offset);
  } else {
    offset = 0;
    newPc = pc + 4;
  }

  VM_StorePointerCore(dst, cmd, offset, val);
  return newPc;
}

u8* FUN_0823201c(u8* pc, u8* dst) {
  u8* newPc;
  s32 zero;

  CopyMemory(dst, pc, 4);
  if ((dst[0] & 0xF0) == OP_MEMORY_INDEXED) {
    s32 type, valA, valB;
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
  u32 cmd = (pc[0] << 24) | (pc[1] << 16) | (pc[2] << 8) | pc[3];  // BE

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

  VM_StorePointerCore(dst, cmd, offset, val);
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

  VM_LoadPointer(src, cmd, offset, &out);
  return out;
}

// pc上のPointer/Indexed Pointer記述子が指す現在値を読み、対応するBackup領域(gStatBackup/gWorldBackup)へ書き込む
u8* FUN_08232160(u8* pc) {
  u8 buf[8];
  u8* p = buf;
  s32 offset = 0;
  u8* dst;

  u8* newPc = FUN_0823201c(pc, buf);
  u32 val = FUN_082320e4(buf, 0);
  u32 cmd = (buf[0] << 24) | (p[1] << 16) | (p[2] << 8) | p[3];

  if ((cmd & 0xF00000) == 0x800000) {
    dst = (u8*)gStatBackup;
  } else {
    dst = (u8*)gWorldBackup;
  }
  dst += cmd & 0xFFFF;

  if (((cmd >> 24) & 0xF0) == OP_MEMORY_INDEXED) {
    offset += *(u16*)(p + 6);
  }

  VM_StorePointerCore(dst, cmd, offset, val);
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

  VM_LoadPointer(src, cmd, offset, &out);
  return out;
}

GameInfo* FUN_08232254(void) { return gStatBackup; }

World* FUN_08232260(void) { return gWorldBackup; }
