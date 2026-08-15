#ifndef __INCLUDE_VM_H__
#define __INCLUDE_VM_H__

#include "gba/gba.h"
#include "types.h"

typedef struct {
  u8* pc;             // 0x00
  void* result;       // 0x04
  void* unk_08;       // 0x08
  void* unk_0c;       // 0x0C
  u8 unk_10[28];      // 0x10
  u32 variables[16];  // 0x2C
  void* unk_6c;       // 0x6C, パラメータスタックへのポインタ?
  void* unk_70[32];   // 0x70, ポインタが入るっぽい
} VM;
static_assert(sizeof(VM) == 240);

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
  s32 script_entries[11539 + 1];   // 0x00004, ScriptDirectory.bytecode[ScriptDirectory.script_entries[i]]
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
  s32* entries;                     // 0x00, = ScriptDirectory.script_entries
  s32 scriptCount;                  // 0x04, = 11539, length of ScriptDirectory.script_entries
  u8* bytecode;                     // 0x08, 0x08D13428, ScriptDirectory.bytecode, ここにアクセスする際に 0x03000748 からのオフセットでアクセスしている
  u8* special_script_data;          // 0x0C, 0x08DA9E60, ScriptDirectory.special_script_data
  ScriptDirectoryOffsets* offsets;  // 0x10, = &ScriptDirectory.offsets
  u32* stringIndex;                 // 0x14, 0x08CCA6AC, ScriptDirectory.string_index
  u8* stringData;                   // 0x18, 0x08CD1640, ScriptDirectory.string_data
  u8* unknown;                      // 0x1C, 0x08D13420, ScriptDirectory.unknown
} ScriptTable;

extern ScriptTable gScriptTable;  // 0x03000748

// --------------------------------------------

// 0x085a9208
// https://boktaihacking.net/wiki/Engine_calls_(Boktai_2)
// VMのシステムコールみたいなもん
typedef struct Subroutine {
  u32 id;  // サブルーチンID
  void* (*fn)(u32 subroutineID, void* unk);
} Subroutine;

extern Subroutine gSubroutineTable1[643];

// 制御命令の処理も Subroutine で行う, なんで 2つのテーブルに分かれてるのかは不明
extern Subroutine gCtrlHandlers1_ROM[6];
extern Subroutine gCtrlHandlers2_ROM[8];

// --------------------------------------------

// RAM に gCtrlHandlerTableN_ROM を読みこんだもの
typedef struct SubroutineTable {
  struct SubroutineTable* next;  // 0x00, ?
  u32 len;                       // = 8, length of gSubroutineTableN
  Subroutine* arr;               // gSubroutineTableN
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
bool32 prepare_08231510(u8 val);
u32 Script_GetValue(void);

#endif  // __INCLUDE_VM_H__
