#include "malloc.h"

#include "global.h"

#define MEMBLOCK_FLAG 0x80000000  // unk_08の最上位ビット、立っていれば未使用(空き)ブロック
#define HEAP_SIZE 0x20400

// gHeap を構成するメモリブロックの構造体
typedef struct MemBlock {
  struct MemBlock* prev;  // 0x00
  struct MemBlock* next;  // 0x04
  u32 unk_08;             // 0x08, サイズ | FREEフラグ(MEMBLOCK_FLAG)
  u32 unk_0c;             // 0x0C
  u8 data[0];             // 0x10, Data in the memory block. (Arrays of length 0 are a GNU extension.)
} MemBlock;
static_assert(sizeof(MemBlock) == 16);

EWRAM_DATA u8 gHeap[HEAP_SIZE] = {};  // EWRAM(0x02000000), Malloc用のヒープ領域

void FUN_082308a8(void) {
  MemBlock* block = (void*)EWRAM;  // gHeap
  block->prev = NULL;
  block->next = NULL;
  block->unk_08 = MEMBLOCK_FLAG | HEAP_SIZE;
}

// gHeap上のMemBlock連結リストをfirst-fitで探索し、確保したブロックのdata部分へのポインタを返す
NON_MATCH void* Malloc(size_t bytesize) {
#ifdef NONMATCHING_C
  MemBlock* block = (void*)EWRAM;
  s32 need = ((bytesize + 0xF) & ~0xF) + sizeof(MemBlock);
  do {
    if (block->unk_08 & MEMBLOCK_FLAG) {
      s32 remain = block->unk_08 & 0x000FFFFF;
      if (remain >= need) {
        remain -= need;
        if (remain > sizeof(MemBlock)) {
          MemBlock* newBlock = (MemBlock*)((u8*)block + need);
          MemBlock* oldNext;
          newBlock->unk_08 = remain | MEMBLOCK_FLAG;
          newBlock->prev = block;
          oldNext = block->next;
          newBlock->next = oldNext;
          if (oldNext != NULL) {
            oldNext->prev = newBlock;
          }
          block->unk_08 = need;
          block->next = newBlock;
        } else {
          block->unk_08 &= ~MEMBLOCK_FLAG;
        }
        block->unk_0c = 0;
        return block->data;
      }
    }
    block = block->next;
  } while (block != NULL);
  return NULL;
#else
  INCFUNC("asm/func/Malloc.inc");
#endif
}

// Malloc で確保したメモリを解放し、隣接する空きブロックと結合する
NON_MATCH void Free(void* p) {
#ifdef NONMATCHING_C
  MemBlock* block;
  MemBlock* prev;
  MemBlock* next;
  u32 header;

  if (p == NULL) {
    return;
  }
  block = (MemBlock*)((u8*)p - sizeof(MemBlock));
  prev = block->prev;
  next = block->next;
  header = block->unk_08;
  if (header & MEMBLOCK_FLAG) {
    return;
  }
  block->unk_08 = header | MEMBLOCK_FLAG;
  block->unk_0c = 0;
  if (prev != NULL) {
    if (prev->unk_08 & MEMBLOCK_FLAG) {
      prev->unk_08 = ((prev->unk_08 & 0x000FFFFF) + (block->unk_08 & 0x000FFFFF)) | MEMBLOCK_FLAG;
      prev->next = next;
      if (next != NULL) {
        next->prev = prev;
      }
      block = prev;
    }
  }
  if (next != NULL) {
    if ((s32)next->unk_08 < 0) {
      block->unk_08 = ((block->unk_08 & 0x000FFFFF) + (next->unk_08 & 0x000FFFFF)) | MEMBLOCK_FLAG;
      block->next = next->next;
      if (next->next != NULL) {
        next->next->prev = block;
      }
    }
  }
#else
  INCFUNC("asm/func/Free.inc");
#endif
}

// ここからは、メモリ操作系の関数群?

void FillMemory32(u32* dst, u32 fillval, s32 len) {
  while (len > 3) {
    dst[0] = fillval;
    dst[1] = fillval;
    dst[2] = fillval;
    dst[3] = fillval;
    dst += 4;
    len -= 4;
  }
  while (len > 0) {
    *dst = fillval;
    dst += 1;
    len -= 1;
  }
}

NAKED void ClearMemory(void* dst, s32 bytesize) { INCFUNC("asm/func/ClearMemory.inc"); }

// dst を fillval << 24 | fillval << 16 | fillval << 8 | fillval で埋める
NAKED void FillMemory8(u32* dst, u8 fillval, s32 len) { INCFUNC("asm/func/FillMemory8.inc"); }

void FUN_08230ab0(u8* dst, u8* src, s32 bytesize) {
  while (bytesize > 7) {
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    dst[3] = src[3];
    dst[4] = src[4];
    dst[5] = src[5];
    dst[6] = src[6];
    dst[7] = src[7];
    dst += 8;
    src += 8;
    bytesize -= 8;
  }
  while (bytesize > 0) {
    *dst = *src;
    src += 1;
    dst += 1;
    bytesize -= 1;
  }
}

NAKED void FUN_08230af8(void* dst, void* src, s32 bytesize) { INCFUNC("asm/func/FUN_08230af8.inc"); }
