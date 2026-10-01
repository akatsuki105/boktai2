#ifndef __INCLUDE_REGISTRY_H__
#define __INCLUDE_REGISTRY_H__

#include "gba/gba.h"
#include "types.h"

// RegistryEntry.flags
typedef u8 RegistryFlags;
#define REG_PERSISTENT (1 << 0)  // 0x01, Registry_Sweep(FALSE) では消されない, 立てているのは 0x56C2 (CollisionMapData) だけ
#define REG_OWNED (1 << 1)       // 0x02, スロットを消すとき ptr を Free する, 立てている呼び出し元はまだない
#define REG_ACTIVE (1 << 7)      // 0x80, スロット使用中, 落ちているスロットは空きとして再利用される

// ID を付けてポインタを預けておく表の1スロット, どこからでも参照したいものが _Init で Registry_Add し、他は Registry_Find(id) で引く
// 預かるのは Entity でも素の Malloc ブロックでもよく、共通ヘッダも種類タグもない (型は呼び出し側が id から知っている)
typedef struct {
  u16 id;               // 0x00, 検索キー, ファイルIDやスクリプトIDと同じ16bitの名前ハッシュ空間
  RegistryFlags flags;  // 0x02, see RegistryFlags
  u8 pad_03;            // 0x03, 読み書きするコードが見つかっていない
  void* ptr;            // 0x04, 預かったポインタ, Registry_Find がそのまま返す
} RegistryEntry;
static_assert(sizeof(RegistryEntry) == 8);

// アドレス上は 0x0203B000 から 0x0203B400 の手前までの128スロットだが、Registry_AllocEntry が 31 を超えたところで NULL を返すので実際に使われるのは32スロットまで
extern RegistryEntry gRegistry[128];
extern s32 gRegistryCount;

RegistryEntry* Registry_AllocEntry(void);
RegistryEntry* Registry_FindEntry(u16 id);

// 件数を 0 に戻す全消去, InitSystemManager が InitHeap / ResetEntityManager と並べて呼ぶ
void Registry_Reset(void);

// マップ切り替えで走る掃除, clearAll が FALSE なら REG_PERSISTENT のスロットだけ残す
void Registry_Sweep(bool32 clearAll);

void Registry_Add(u16 id, void* ptr, s32 flags);
void Registry_Remove(u16 id);

// 預けたポインタを返す, 見つからなければ NULL
void* Registry_Find(u16 id);

#endif  // __INCLUDE_REGISTRY_H__
