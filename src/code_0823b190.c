#include "global.h"

void FUN_08231780(void);
bool32 FUN_0823a8b0(void);
void FUN_08231be0(u32 n);
void* FUN_0823178c(struct Unk_030016e8*);
TaskFn FUN_0823b1d0(u32 n);
void* FUN_082316bc(void);

void* FUN_0823ae50(void) { return NULL; }

void* FUN_0823ae54(void) {
  void* bVar2;
  u16 n = (u16)fetch_082316e4();
  u32_03004798 = 0x01;
  if ((prepare_08231510(0x6E) == 0) || ((FUN_082316bc() != NULL) && (fetch_082316e4() == 0))) {
    u32_03004798 |= 0x10;
  }
  FUN_08231be0((s16)n);
  GAME->unk_24c = n;
  return NULL;
}

s32 FUN_0823aeac(void) {
  u16 n = (u16)fetch_082316e4();
  TaskFn fn = FUN_0823b1d0(n);
  if (fn == NULL) {
    return -1;
  }
  n = (u16)fetch_082316e4();
  fn(n, NULL);
  return 0;
}

s32 FUN_0823aedc(void) {
  u16 n = (u16)fetch_082316e4();
  TaskFnNoArg fn = (TaskFnNoArg)FUN_0823b1d0(n);
  if (fn == NULL) {
    return -1;
  }
  gVM.result = fn();
  return 0;
}

NAKED void* FUN_0823af08(void) { INCCODE("asm/todo/FUN_0823af08.inc"); }

void* FUN_0823af6c(void* _) { return _; }

NAKED s32 FUN_0823af70(void* r0) { INCCODE("asm/todo/FUN_0823af70.inc"); }

void* FUN_0823b0ec(void) {
  bool32 bVar1 = FUN_0823a8b0();
  if (!bVar1) {
    u32_03004798 = 0x40;
    if (prepare_08231510(0x73) != 0) {
      u32_03004798 |= 0x10;
    } else if (prepare_08231510(0x72) != 0) {
      u32_03004798 |= 0x100;
    }
  }
  return NULL;
}

static void FUN_0823b12c(void) { return; }

void* FUN_0823b130(void) {
  FUN_0823b12c();
  FUN_08231780();
  gUnk030016e8.unk = 0;
  gUnk030016e8.len = ARRAY_COUNT(gUnk08dbd758);
  gUnk030016e8.arr = gUnk08dbd758;
  return FUN_0823178c(&gUnk030016e8);
}

void FUN_0823b158(void) {
  struct Unk_085a9208* cur;
  gUnk085a9208Counter = 0;
  for (cur = &gUnk085a9208[0]; cur->fn != NULL; cur++) {
    gUnk085a9208Counter++;
  }
}

void FUN_0823b180(void) {
  gUnk085a9208[0].fn = NULL;  // why???
  return;
}

void FUN_0823b18c(void) { return; }

TaskFn FUN_0823b190(u32 n, struct Unk_085a9208* arr, s32 start, s32 len) {
  s32 i;
  // Binary search
  while (start < len) {
    i = Div(start + len, 2);
    if (arr[i].unk < n) {
      start = i + 1;
    } else {
      len = i;
    }
  }

  if (arr[start].unk == n) {
    return (TaskFn)arr[start].fn;
  }
  return NULL;
}

TaskFn FUN_0823b1d0(u32 n) {
  TaskFn fn = FUN_0823b190(n, gUnk085a9208, 0, gUnk085a9208Counter);
  return fn;
}

void FUN_0823b1ec(void) {
  PTR_030016f8 = NULL;
  return;
}

void FUN_0823b1f8(struct Unk_0200865c* p) {
  if (PTR_030016f8 != NULL) {
    if (PTR_030016f8->unk_18 == NULL) {
      PTR_030016f8->unk_18 = p;
      PTR_030016f8->unk_1c = p;
      p->prev = NULL;
      p->next = NULL;
    } else {
      struct Unk_0200865c* tmp = PTR_030016f8->unk_1c;
      tmp->next = p;
      p->prev = tmp;
      p->next = NULL;
      PTR_030016f8->unk_1c = p;
    }
  }
}

struct Unk_0200865c* FindUnk0200865c(u16 id) {
  struct Unk_0200865c* p;
  if (PTR_030016f8 == NULL) {
    return NULL;
  } else {
    for (p = PTR_030016f8->unk_18; p != NULL; p = p->next) {
      if (p->id == id) {
        return p;
      }
    }
    return NULL;
  }
}
