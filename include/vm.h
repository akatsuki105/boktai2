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
#define OP_KEYWORD 0x50
#define OP_CONTROL 0x60
#define OP_CALL 0x70  // 別のスクリプト呼び出し
#define OP_BLOCK 0x80
#define OP_VARIABLE 0x90
#define OP_END_EXPRESSION 0xA0

// OP_KEYWORD
#define KW_CASE 0x63
#define KW_DEFAULT 0x64
#define KW_ELSE 0x65
#define KW_ELIF 0x69
#define KW_UNK6D 0x6D

typedef struct {
  u8* pc;                    // 0x00
  void* result;              // 0x04, 直前に実行したブロック/式の結果値
  u8* keywordSeekStackTop;   // 0x08
  u8* keywordSeekStack[24];  // 0x0C
  void* framePointer;        // 0x6C, ブロックのフレームスタックのトップポインタ(ブロックがネストするたびに更新される)
  void* frameStack[32];      // 0x70, ブロックのフレームを保持するスタック
} VM;
static_assert(sizeof(VM) == 240);

// スクリプト呼び出し時に呼び出し元が積む引数の記述子(VM_CallScript が組み立て、VM_ParseParameter が読む)
typedef struct {
  u32 argc : 16;    // 0x00, 引数の個数
  u32 unk_02 : 16;  // 0x02
  u32* argv;        // 0x04, 引数配列の先頭
} ScriptArgs;

// --------------------------------------------

typedef struct {
  u32 script_data;   // 0x00, &ScriptDirectory.special_script_offset = &ScriptDirectory.offsets + ScriptDirectory.offsets.script_data
  u32 string_index;  // 0x04, ScriptDirectory.string_index = &ScriptDirectory.offsets + ScriptDirectory.offsets.string_index
  u32 string_data;   // 0x08, ScriptDirectory.string_data = &ScriptDirectory.offsets + ScriptDirectory.offsets.string_data
  u32 unknown;       // 0x0C, ScriptDirectory.unknown = &ScriptDirectory.offsets + ScriptDirectory.offsets.unknown
} ScriptDirectoryOffsets;

// 0x08CBF248
typedef struct {
  u32 build_data;                  // 0x00000, seconds since unix epoch
  s32 script_entries[11539 + 1];   // 0x00004, bytecode[script_entries[idx]], 各エントリの上位8bit は用途不明, Script_ExecById で渡すスクリプトID から -1 することに注意
  ScriptDirectoryOffsets offsets;  // 0x0B454
  u32 string_index[7141];          // 0x0B464
  u8 string_data[269792];          // 0x123F8
  u8 unknown[4];                   // 0x541D8
  u32 special_script_offset;       // 0x541DC, or bytecode length?
  u8 bytecode[617012];             // 0x541E0
  u32 special_script_size;         // 0xEAC14
  u8 special_script_data[6];       // 0xEAC18
} ScriptDirectory;
static_assert(sizeof(ScriptDirectory) == 961568);

// RAM に ScriptDirectory を読み込む際に相対オフセットを絶対アドレスに変換したもの
// レイアウトがちょっと違うかも(根拠: VM_RestoreScriptTable)
typedef struct {
  u32* entries;             // 0x00, = ScriptDirectory.script_entries
  s32 scriptCount;          // 0x04, = 11539, length of ScriptDirectory.script_entries
  u8* bytecode;             // 0x08, 0x08D13428, ScriptDirectory.bytecode, ここにアクセスする際に 0x03000748 からのオフセットでアクセスしている
  u8* special_script_data;  // 0x0C, 0x08DA9E60, ScriptDirectory.special_script_data
} ScriptTable;

extern ScriptTable gScriptTable;  // 0x03000748

// ScriptTable と StringTable として別々の構造体の可能性が高い
typedef struct {
  ScriptDirectoryOffsets* offsets;  // 0x10, = &ScriptDirectory.offsets
  u32* stringIndex;                 // 0x14, 0x08CCA6AC, ScriptDirectory.string_index
  u8* stringData;                   // 0x18, 0x08CD1640, ScriptDirectory.string_data
  u8* unknown;                      // 0x1C, 0x08D13420, ScriptDirectory.unknown
} StringTable;                      // 0x10

extern StringTable gStringTable;  // 0x03000758

// --------------------------------------------

// 0x085a9208
// https://boktaihacking.net/wiki/Engine_calls_(Boktai_2)
// VMのシステムコールみたいなもん
typedef struct Subroutine {
  u32 id;  // サブルーチンID
  void* (*fn)(u32 subroutineID, void* unk);
} Subroutine;

// 制御命令の処理も Subroutine で行う, なんで 2つのテーブルに分かれてるのかは不明
extern Subroutine gCtrlHandlers2_ROM[8];

// --------------------------------------------

// RAM に gCtrlHandlerTableN_ROM を読みこんだもの
typedef struct SubroutineTable {
  struct SubroutineTable* next;  // 0x00, ?
  u32 len;                       // = 8, length of gSubroutineTableN
  const Subroutine* arr;         // gSubroutineTableN
} SubroutineTable;

extern SubroutineTable gCtrlHandlers1;
extern SubroutineTable gCtrlHandlers2;
extern SubroutineTable* gCtrlHandlers;  // SubroutineTable のリンクリスト, これが制御命令のハンドラ, なんでこんな構造にしてるのか全くわからん

s32 VM_AddCtrlHandlers(SubroutineTable*);  // gCtrlHandlers に gCtrlHandlers1 or gCtrlHandlers2 を追加する

// --------------------------------------------

extern u16 gMapInitScriptID;  // 0x03002B28
extern VM gVM;                // 0x030045A0

u8* VM_GetPC(void);
void VM_SetPC(u8* addr);
u8* VM_ReadContainerLength(u8* pc, u32* length);
bool32 VM_SeekToKeyword(u8 val);
u32 Script_GetValue(void);
u8* VM_DecodeValue(u8* pc, s32* type, void* val);

s32 Script_ExecById(u32 scriptID, ScriptArgs* args);
bool32 Script_ExecBlock(u8* pc, ScriptArgs* args, s32 varidx);

#endif  // __INCLUDE_VM_H__
