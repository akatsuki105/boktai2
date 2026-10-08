#include "entity.h"
#include "global.h"
#include "vm.h"

// 一定時間経過したらスクリプトを実行するタイマー (スクリプトは IDとポインタ どちらかで指定)
// スクリプト側の返り値(result) に応じて一度きり(oneshot)か定期実行(periodically)かが決まる
typedef struct TimerEntity {
  Entity e;           // 0x00, ENTITY_UNK_5
  u32 recordID;       // 0x18, FUN_08230f94 に渡すスクリプトレコードのID
  ScriptArgs args;    // 0x1C, argv は下の argv を指す
  u32 script;         // 0x24, TIMERFLAG_SCRIPT_ID が立っていればスクリプトID、立っていなければバイトコードへのポインタ
  s32 frames;         // 0x28, 毎フレーム減る残りフレーム数
  u16 unk_2c;         // 0x2C, frames に負の値が渡されたときだけ 1
  u16 flags;          // 0x2E, bit0: TIMERFLAG_SCRIPT_ID, bit1..7: not used
  u32 argv[8];        // 0x30, 呼び出し元から写した引数
  ScriptRecord* rec;  // 0x50, FUN_08230f94 が引いてくるレコード
} TimerEntity;
static_assert(sizeof(TimerEntity) == 84);  // CreateEntity(ENTITY_UNK_5, 0x54)

#define TIMERFLAG_SCRIPT_ID (1 << 0)

void TimerEntity_Update(TimerEntity* p) {
  s32 i = FUN_08230f94(p->recordID, &p->rec);
  ScriptRecord* rec = p->rec;
  s32 result;

  while (i-- > 0) {
    if (*rec->values == 0xFFFF) {
      KillEntity(&p->e);
      return;
    }
  }

  p->frames--;
  if (p->frames > 0) {
    return;
  }

  if (p->flags & TIMERFLAG_SCRIPT_ID) {
    result = VM_ExecByID(p->script, &p->args);
  } else {
    result = VM_ExecByPointer((u8*)p->script, &p->args);
  }
  if (result == 0) {
    KillEntity(&p->e);  // oneshot
  } else {
    p->frames = result;  // periodically
  }
}

void TimerEntity_Destroy(TimerEntity* p) {}

TimerEntity* TimerEntity_Create(u32 script, ScriptArgs* args, s32 frames) {
  TimerEntity* p = CreateEntity(ENTITY_UNK_5, sizeof(TimerEntity));

  if (p != NULL) {
    if (args == NULL) {
      p->args.argc = 0;
    } else {
      u32* src = args->argv;
      u32* dst;
      u16 i;

      p->args.argv = p->argv;
      dst = p->argv;
      p->args.argc = args->argc;
      i = args->argc;
      while (i != 0) {
        *dst++ = *src++;
        i--;
      }
    }

    if (frames < 0) {
      p->unk_2c = 1;
      frames = -frames;
    } else {
      p->unk_2c = 0;
    }
    p->frames = frames;
    p->script = script;
    SetEntityRoutine(p, TimerEntity_Update, TimerEntity_Destroy);
  }
  return p;
}

TimerEntity* TimerEntity_CreateFromScript(u32 recordID) {
  s32 frames = 0;
  u32 script = 0;
  bool32 isScriptID;
  TimerEntity* p;

  if (VM_SeekToNamedArg('t')) {
    frames = VM_GetValue();
  }

  isScriptID = FALSE;
  if (VM_SeekToNamedArg('e')) {
    s32 type, val;

    VM_DecodeValue(VM_GetPC(), &type, &val);
    script = val;
  } else if (VM_SeekToNamedArg('p')) {
    isScriptID = TRUE;
    script = VM_GetValue();
  }

  p = TimerEntity_Create(script, NULL, frames);
  if (p != NULL) {
    p->recordID = recordID;
    p->flags = isScriptID;
    if (VM_SeekToNamedArg('a')) {
      s32 i;

      p->args.argv = p->argv;
      i = 0;
      while (i < 8 && VM_GetPC() != NULL) {
        p->args.argv[i] = VM_GetValue();
        i++;
      }
      p->args.argc = i;
    }
  }
  return p;
}
