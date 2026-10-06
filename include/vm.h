#ifndef __INCLUDE_VM_H__
#define __INCLUDE_VM_H__

#include "gba/gba.h"
#include "types.h"

#define OP_END 0
#define OP_S16 1
#define OP_U8 2
#define OP_U8_0x03 3  // u8 と同じ扱いだが不使用
#define OP_BOOL8 4    // 8ビットのブール値
#define OP_U16 6
#define OP_STRING 7
#define OP_U24 8
#define OP_S32 9
#define OP_S32_0x0A 10  // s32 と同じ扱いだが不使用
#define OP_S32_0x0D 13  // 不使用
#define OP_STRING_REF 14

#define OP_MEMORY 0x10          // Pointer
#define OP_MEMORY_INDEXED 0x20  // Indexed Pointer
#define OP_EXPRESSION 0x30
#define OP_PARAMETER 0x40
#define OP_LABEL 0x50
#define OP_CONTROL 0x60
#define OP_CALL 0x70  // 別のスクリプト呼び出し
#define OP_BLOCK 0x80
#define OP_VARIABLE 0x90
#define OP_END_EXPRESSION 0xA0

// OP_LABEL のうち if / switch の節のラベルとして使われる文字, 'c' / 'd' / 'e' / 'i'
#define CLAUSE_CASE 0x63
#define CLAUSE_DEFAULT 0x64
#define CLAUSE_ELSE 0x65
#define CLAUSE_ELIF 0x69

typedef struct {
  u8* pc;        // 0x00
  void* result;  // 0x04, 直前に実行したブロック/式の結果値

  // 制御命令 (0x60) を実行している間, その命令の最初のラベル命令を指す u8* が1語積まれる (積むのは VM_RunControl, 捨てるのはハンドラから戻った時)
  // 制御命令も内部的にはサブルーチンと同じ扱いなので, subroutineStack というメンバ名にした
  // ラベルは名前付き引数 (.n = 16 など) と if / switch の節 (case, else) の総称で, 1文字の名前を持つ 0x50 の命令
  // switch の case の中で NativeCall_B745((u16)0x305A, .i = 22, .p = 0) を実行している間は, リセット位置を base として
  //
  //   アドレス大 (scriptStack と同じく, 積むほどアドレスが大きくなる)
  //                    base[2]  <- 現在の subroutineStackTop, 次の制御命令はここに積む
  //   NativeCall_B745  base[1]  -> .i の命令の先頭, 続けて .p の命令と終端が並ぶ
  //   switch           base[0]  -> 最初の case の命令の先頭
  //   アドレス小
  //
  // base[1] が指すバイト列は 52 69 D7 52 70 C1 00 で, 52 がラベル命令 (内容2バイト), 69 が 'i', D7 が 22, 70 が 'p', C1 が 0, 00 が終端
  // 読むのは VM_SeekToNamedArg だけで, *(subroutineStackTop - 1) から VM_DecodeValue で1命令ずつ読み進めて目的の1文字を探す
  // 毎回この位置から読み直すので, 同じ名前を何度でも, どの順番でも読める
  u8** subroutineStackTop;  // 0x08, subroutineStack の次の空き位置
  u8* subroutineStack[24];  // 0x0C, サブルーチン1回につき1語

  // スクリプトを呼び出すと、ここに ローカル変数用の領域 と スクリプトの引数(のポインタ、 ScriptArgs*) が積まれる
  // 以下の p0 p1 ... と v1 v2 ... は .bokc 側の表記で, 前者が引数 (VM_ParseParameter が読む), 後者がローカル変数 (VM_GetVariable が読む)
  // ローカル変数を2個使うスクリプトを引数3個で呼んだ直後は, 呼び出し前の scriptStackTop を base として
  //
  //   アドレス大 (ARM のスタックとは逆, 積むほどアドレスが大きくなる(0から遠くなる))
  //                base[3]  <- 呼び出し中の scriptStackTop, 次のフレームはここから
  //   ScriptArgs*  base[2]  -> {argc: 3, argv: [p0, p1, p2]}
  //   v1           base[1]
  //   v2           base[0]  <- 呼び出し前の scriptStackTop, 外側のフレームはこれより下
  //   アドレス小
  //
  // 読み出しは scriptStackTop から手前に数える
  //   p0 は *(ScriptArgs**)(scriptStackTop - 1) の argv[0]
  //   v1 は *(scriptStackTop - 2)
  //   v2 は *(scriptStackTop - 3)
  u32* scriptStackTop;  // 0x6C, scriptStack の次の空き位置
  u32 scriptStack[32];  // 0x70
} VM;
static_assert(sizeof(VM) == 240);

// スクリプト呼び出し時に呼び出し元が積む引数の記述子(VM_CallScript が組み立て、VM_ParseParameter が読む)
typedef struct {
  u16 argc;   // 0x00, 引数の個数
  u32* argv;  // 0x04, 引数配列の先頭 (.bokc で p0, p1, ... に対応 (pN が argv[N] に対応))
} ScriptArgs;

// スクリプトが VM_Ctrl_22FF で登録するレコード, FUN_08230eec が u32_ARRAY_0203f400 のテーブルへ積み、FUN_08230f94 が id で引く
// テーブルは 0x03000740 の深さで選ぶ 392 バイトのブロック単位 (先頭 word が件数、続けて 8 バイトのレコードが最大 48 件)
typedef struct {
  u16 id;
  u8 unk_02;
  u8 count;
  u16* values;
} ScriptRecord;
static_assert(sizeof(ScriptRecord) == 8);

// レコードの置き場, 0x03000740 の深さで 2 面を切り替えて使う
typedef struct {
  u32 count;              // 0x00, recs の件数
  u32 valueCount;         // 0x04, values に積んだ u16 の個数
  ScriptRecord recs[32];  // 0x08
  u16 values[64];         // 0x108, recs[].values が指す先
} ScriptRecordBlock;
static_assert(sizeof(ScriptRecordBlock) == 392);

ScriptRecordBlock* ScriptRecord_GetBlocks(void);

// id で引いたレコードの先頭を *out に入れ、件数を返す
s32 FUN_08230f94(u32 id, ScriptRecord** out);

// --------------------------------------------

// bit0..23: ScriptTable.bytecode からのオフセット
// bit24..31: スクリプトが必要とするローカル変数の数 (スタックフレームの構築に必要)
typedef u32 ScriptOffset;

typedef struct {
  u32 script_data;   // 0x00, &ScriptDirectory.bytecodeSize = &ScriptDirectory.offsets + ScriptDirectory.offsets.script_data
  u32 string_index;  // 0x04, ScriptDirectory.string_index = &ScriptDirectory.offsets + ScriptDirectory.offsets.string_index
  u32 string_data;   // 0x08, ScriptDirectory.string_data = &ScriptDirectory.offsets + ScriptDirectory.offsets.string_data
  u32 unknown;       // 0x0C, ScriptDirectory.unknown = &ScriptDirectory.offsets + ScriptDirectory.offsets.unknown
} ScriptDirectoryOffsets;

// 0x08CBF248
typedef struct {
  u32 buildDate;                           // 0x00000, seconds since unix epoch
  ScriptOffset script_entries[11539 + 1];  // 0x00004, VM_ExecByID で渡すスクリプトID から -1 した値が idx

  ScriptDirectoryOffsets offsets;  // 0x0B454
  u32 string_index[7141];          // 0x0B464, bit31 が 1 なら 文字列, 0 ならバイナリデータ (ゲーム内ではこのbitは見ない)
  u8 string_data[269792];          // 0x123F8
  u8 unknown[4];                   // 0x541D8

  u32 bytecodeSize;     // 0x541DC
  u8 bytecode[617012];  // 0x541E0, bytecode[bytecodeSize]

  u32 specialScriptSize;    // 0xEAC14
  u8 specialScriptData[6];  // 0xEAC18

} ScriptDirectory;
static_assert(sizeof(ScriptDirectory) == 961568);

// RAM に ScriptDirectory を読み込む際に相対オフセットを絶対アドレスに変換したもの
// レイアウトがちょっと違うかも(根拠: VM_RestoreScriptTable)
typedef struct {
  ScriptOffset* entries;  // 0x00, = ScriptDirectory.script_entries
  s32 scriptCount;        // 0x04, = 11539, length of ScriptDirectory.script_entries
  u8* bytecode;           // 0x08, 0x08D13428, ScriptDirectory.bytecode, ここにアクセスする際に 0x03000748 からのオフセットでアクセスしている
  u8* specialScriptData;  // 0x0C, 0x08DA9E60, ScriptDirectory.specialScriptData
} ScriptTable;

typedef struct {
  ScriptDirectoryOffsets* offsets;  // 0x0, = &ScriptDirectory.offsets
  u32* header;                      // 0x4, gStringHeader
  u8* body;                         // 0x8, String_0000
  u8* unknown;                      // 0xC, unk08D13420
} StringTable;

// --------------------------------------------

extern u16 gMapInitScriptID;  // 0x03002B28
extern VM gVM;                // 0x030045A0

u8* VM_GetPC(void);
void VM_SetPC(u8* addr);
u8* VM_ReadContainerLength(u8* pc, u32* length);
u32 VM_GetValueAt(u8* addr);
u32 VM_GetValue(void);
u8* VM_DecodeValue(u8* pc, s32* type, void* val);
void* VM_GetValueSafe2(void);
s32 VM_ParseStringRef(u8* pc);
char* Textbox_LookupString(s32 stringID);

s32 VM_ExecByID(u32 scriptID, ScriptArgs* args);
void VM_ExecSpecial(void);
void VM_ClearScratchpad_Proxy(void);
bool32 VM_ExecBlock(u8* pc, ScriptArgs* args, s32 localVarCount);
s32 VM_ExecByPointer(u8* pc, ScriptArgs* args);

void FUN_0823167c(u8* dst);
void FUN_0823206c(u8* pc, s32 offset, u32 val);
u32 FUN_082320e4(u8* pc, s32 offset);

u8* FUN_08232160(u8* pc);
u8* FUN_0823d340(void);
void* FUN_0823d34c(void);

void SetMapInitScriptID(u32 scriptID);

// name は ASCII 文字で書いてください, 例えば  VM_SeekToNamedArg(0x70)  は  VM_SeekToNamedArg('p') と書いてください
bool32 VM_SeekToNamedArg(u8 name);
s32 VM_GetNamedArgValue(u8 name, s32 fallback);

#endif  // __INCLUDE_VM_H__
