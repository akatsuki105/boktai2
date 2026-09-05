#include "global.h"
#include "vm.h"

s32 VM_Ctrl_Switch_Internal(void);

/**
 * @param src EUC-JP文字列
 * @param dst Shift-JIS文字列
 */
NON_MATCH void VM_ConvertEucJpToSjis(u8* dst, u8* src) {
#ifdef NONMATCHING_C
  u8* s = src;
  u8* d = dst;
  s32 lead;
  s32 trail;
  s32 cell;
  s32 out;

  while (s[0] != 0) {
    if (s[0] & 0x80) {
      lead = s[0] - 0x80;
      trail = s[1];
      s += 1;
      if (lead & 1) {
        cell = trail - 0x61;
        if (cell > 0x7E) {
          cell += 1;
        }
      } else {
        cell = trail - 2;
      }
      out = Div(lead - 0x21, 2) + 0x81;
      if (out > 0x9F) {
        out += 0x40;
      }
      d[0] = (u8)out;
      d[1] = (s8)cell;
      d += 1;
    } else {
      d[0] = s[0];
    }
    if (s[0] == 0xD && s[1] == 0xA) {
      s += 1;
    }
    s += 1;
    d += 1;
  }
  d[0] = 0;
#else
  INCFUNC("asm/func/VM_ConvertEucJpToSjis.inc");
#endif
}

// if/elseif チェーンを辿り、条件が真になった最初の分岐のブロック先頭を返す(見つからなければNULL)
u8* VM_Ctrl_If_Internal(u8* pc) {
  s32 type;
  u32 valA;
  u32 valB;
  s32 shifted;

loop1:
  pc = VM_DecodeValue(pc, &type, &valA);
  do {
    pc = VM_DecodeValue(pc, &type, &valB);
    if (valA != 0) {
      return (u8*)valB;
    }
    pc = VM_DecodeValue(pc, &type, &valA);
    if (pc == NULL) {
      return NULL;
    }
    shifted = type >> 16;
    type = shifted;
    pc = (u8*)valA;
    if (shifted == KW_ELSE) {
      valA = 1;
    }
  } while (shifted == KW_ELSE);
  if (shifted != KW_ELIF) {
    return NULL;
  }
  goto loop1;
}

// 0x0D86
bool32 VM_Ctrl_If(u8* pc) {
  u8* block = VM_Ctrl_If_Internal(pc);
  if (block != NULL) {
    return Script_ExecBlock(block, NULL, 0);
  }
  return FALSE;
}

// 0x4A6F
NON_MATCH bool32 VM_Ctrl_Switch(u8* pc) {
#ifdef NONMATCHING_C
  u8* blockPc = NULL;
  s32 type;
  s32 switchVal;
  s32 kw;

  VM_SetPC(VM_DecodeValue(pc, &type, &switchVal));

  while (TRUE) {
    kw = VM_Ctrl_Switch_Internal();
    if (kw == 0) {
      return 0;
    } else if (kw == KW_CASE) {
      if (Script_GetValue() == switchVal) {
        VM_DecodeValue(VM_GetPC(), &type, &blockPc);
        break;
      }
    } else if (kw == KW_DEFAULT) {
      VM_DecodeValue(VM_GetPC(), &type, &blockPc);
      break;
    }
  }
  return Script_ExecBlock(blockPc, 0, 0);
#else
  INCFUNC("asm/func/VM_Ctrl_Switch.inc");
#endif
}

NAKED bool32 VM_Ctrl_Unused_64C0(u8* pc) { INCFUNC("asm/func/VM_Ctrl_Unused_64C0.inc"); }

// 0xCD3A: 現在実行中のスクリプトを終了(オプションで戻り値を返す)
bool32 VM_Ctrl_Return(u8* _) {
  if (VM_GetPC() != NULL) {
    gVM.result = (void*)Script_GetValue();
  } else {
    gVM.result = NULL;
  }
  return TRUE;
}

// https://boktaihacking.net/wiki/Bytecode#Control_0xb96e_(TODO)
bool32 VM_Ctrl_B96E(u8* pc) {
  s32 type;
  u8* val;
  u8* p;
  u8 buf[512];

  while (pc != NULL) {
    pc = VM_DecodeValue(pc, &type, &val);
    if (type == 0) break;

    if (type == OP_STRING) {  // opcode7: string
      VM_ConvertEucJpToSjis(buf, val);
    } else if (type == 0xE) {
      p = val;
      while (*p != 0) p++;
    }
  }
  return 0;
}

// https://boktaihacking.net/wiki/Bytecode#Control_0x121f_(call_indirect)
bool32 VM_Ctrl_CallIndirect(u8* _) {
  u32 argv[16];
  s32 type, val;
  ScriptArgs args;

  u32 scriptID = Script_GetValue();
  u8* pc = VM_GetPC();
  u32 count = 0;

  while (pc != NULL) {
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

// clang-format off
static const Subroutine sCtrlHandlers1[6] = {
    {.id = 0x0D86, .fn = (void*)VM_Ctrl_If},
    {.id = 0x4A6F, .fn = (void*)VM_Ctrl_Switch},
    {.id = 0x64C0, .fn = (void*)VM_Ctrl_Unused_64C0},
    {.id = 0x121F, .fn = (void*)VM_Ctrl_CallIndirect},
    {.id = 0xCD3A, .fn = (void*)VM_Ctrl_Return},
    {.id = 0xB96E, .fn = (void*)VM_Ctrl_B96E},
}; // 0x085B01D0
// clang-format on

void FUN_082324b0(void) {
  gCtrlHandlers1.next = NULL;
  gCtrlHandlers1.len = Div(sizeof(sCtrlHandlers1), sizeof(Subroutine));
  gCtrlHandlers1.arr = sCtrlHandlers1;
  VM_AddCtrlHandlers(&gCtrlHandlers1);
}
