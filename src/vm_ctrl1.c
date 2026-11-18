#include "global.h"
#include "vm.h"
#include "vm_subroutine.h"

IWRAM_DATA CtrlHandlerTable gCtrlHandlers1 = {};  // 0x03000770, 制御命令ではこのハンドラ自体を直接みるのではなく、初期化時に gCtrlHandlers に登録してそれを制御命令が参照する

s32 VM_Ctrl_Switch_Internal(void);

/**
 * @param dst Shift-JIS文字列
 * @param src EUC-JP文字列
 */
// 残差は lead/trail の r1/r2 入れ替えのみ (55/55 命令), Tier B-C は試済 (宣言順, u8/u32, s++ の位置, ++ と += 1, for 化, *++s, 引数直使用, 2バイト構造体経由の読み, 配列化), trail を sjisTrail に畳むと lead は r1 に入るが1命令減る
NON_MATCH void VM_ConvertEucJpToSjis(u8* dst, u8* src) {
#ifdef NONMATCHING_C
  u8* s = src;
  u8* d = dst;
  s32 lead;
  s32 trail;
  s32 sjisTrail;
  s32 sjisLead;

  while (s[0] != 0) {
    if (s[0] & 0x80) {
      // 全角文字(1文字=2バイト)
      lead = s[0] - 0x80;  // EUC-JP は JIS の区点の各バイトに 0x80 を足したもの, 1バイト目から 0x80 を引いて JIS の1バイト目 (0x21..0x7E) に戻す
      trail = s[1];
      s++;
      // Shift-JIS の2バイト目は JIS の1バイト目の奇偶で範囲が変わる, 奇数なら 0x40..0x9E (0x7F は使わないので飛ばす), 偶数なら 0x9F..0xFC
      if (lead & 1) {
        sjisTrail = trail - 0x61;
        if (sjisTrail > 0x7E) {
          sjisTrail++;
        }
      } else {
        sjisTrail = trail - 2;
      }
      // Shift-JIS の1バイト目は JIS の2区ぶんを1つにまとめて 0x81 から振る, 半角カナの 0xA0..0xDF は避けて 0xE0 から続ける
      sjisLead = Div(lead - 0x21, 2) + 0x81;
      if (sjisLead > 0x9F) {
        sjisLead += 0x40;
      }
      d[0] = sjisLead, d[1] = sjisTrail;
      d++;
    } else {
      // ASCII
      d[0] = s[0];
    }

    if (s[0] == '\r' && s[1] == '\n') {  // 改行の CR LF は CR だけを残して LF を読み飛ばす
      s++;
    }
    s++;
    d++;
  }
  d[0] = '\0';
#else
  INCFUNC("asm/func/VM_ConvertEucJpToSjis.inc");
#endif
}

// if/elseif チェーンを辿り、条件が真になった最初の分岐のブロック先頭を返す(見つからなければNULL)
u8* VM_Ctrl_If_Internal(u8* pc) {
  s32 type;
  u32 cond;
  u32 block;

  do {
    pc = VM_DecodeValue(pc, &type, &cond);
    do {
      pc = VM_DecodeValue(pc, &type, &block);
      if (cond != 0) {
        return (u8*)block;
      }
      pc = VM_DecodeValue(pc, &type, &cond);
      if (pc == NULL) {
        return NULL;
      }
      type >>= 16;
      pc = (u8*)cond;
      if (type == CLAUSE_ELSE) {
        cond = 1;
      }
    } while (type == CLAUSE_ELSE);
  } while (type == CLAUSE_ELIF);
  return NULL;
}

// 0x0D86
bool32 VM_Ctrl_If(u8* pc) {
  u8* block = VM_Ctrl_If_Internal(pc);
  if (block != NULL) {
    return VM_ExecBlock(block, NULL, 0);
  }
  return FALSE;
}

// 0x4A6F: switch 文, case/default の節を順に辿り, 値が一致した case か default のブロックを実行する
bool32 VM_Ctrl_Switch(u8* pc) {
  u8* blockPc = NULL;
  s32 type;
  s32 switchVal;
  s32 kw;

  VM_SetPC(VM_DecodeValue(pc, &type, &switchVal));

  for (;;) {
    kw = VM_Ctrl_Switch_Internal();
    if (kw == 0) {
      return FALSE;
    } else if (kw == CLAUSE_CASE) {
      if (VM_GetValue() == switchVal) {
        VM_DecodeValue(VM_GetPC(), &type, &blockPc);
        break;
      }
    } else if (kw == CLAUSE_DEFAULT) {
      VM_DecodeValue(VM_GetPC(), &type, &blockPc);
      break;
    }
  }
  return VM_ExecBlock(blockPc, NULL, 0);
}

bool32 VM_Ctrl_Unused_64C0(u8* pc) {
  s32 type;
  void* val;

  VM_DecodeValue(pc, &type, &val);
  gVM.result = val;
  return FALSE;
}

// 0xCD3A: 現在実行中のスクリプトを終了(オプションで戻り値を返す)
bool32 VM_Ctrl_Return(u8* _) {
  if (VM_GetPC() != NULL) {
    gVM.result = (void*)VM_GetValue();
  } else {
    gVM.result = NULL;
  }
  return TRUE;
}

// 0xB96E: デバッグ用, EUC-JP 文字列 を受け取る
bool32 VM_Ctrl_DebugPrint(u8* pc) {
  u8 buf[512];

  while (pc != NULL) {
    s32 type;
    u8* val;
    pc = VM_DecodeValue(pc, &type, &val);
    if (type == 0) break;

    if (type == OP_STRING) {  // opcode7: string
      VM_ConvertEucJpToSjis(buf, val);
    } else if (type == OP_STRING_REF) {
      u8* p = val;
      while (*p != 0) p++;
    }
  }
  return 0;
}

// VM_CallScript と同じくスクリプトを ScriptArgs 付きで実行するが, スクリプトIDを VM_GetValue で読むため
// OP_MEMORY や OP_VARIABLE を書けば呼び先を実行時に決められる
bool32 VM_Ctrl_CallScriptIndirect(u8* _) {
  u32 argv[16];
  ScriptArgs args;

  u32 scriptID = VM_GetValue();
  u8* pc = VM_GetPC();
  u32 count = 0;

  while (pc != NULL) {
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

// こっちは制御構文に相当するランタイムに必要不可欠なものが集まっている
static const Subroutine sCtrlHandlers1[6] = {
    {id : BOKHASH("if"),     fn : VM_Ctrl_If                },
    {id : BOKHASH("switch"), fn : VM_Ctrl_Switch            },
    {id : BOKHASH("eval"),   fn : VM_Ctrl_Unused_64C0       },
    {id : BOKHASH("call"),   fn : VM_Ctrl_CallScriptIndirect},
    {id : BOKHASH("return"), fn : VM_Ctrl_Return            },
    {id : BOKHASH("print"),  fn : VM_Ctrl_DebugPrint        },
};  // 0x085B01D0

void FUN_082324b0(void) {
  gCtrlHandlers1.next = NULL;
  gCtrlHandlers1.len = Div(sizeof(sCtrlHandlers1), sizeof(Subroutine));
  gCtrlHandlers1.arr = sCtrlHandlers1;
  VM_AddCtrlHandlers(&gCtrlHandlers1);
}
