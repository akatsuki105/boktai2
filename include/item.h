#ifndef __INCLUDE_ITEM_H__
#define __INCLUDE_ITEM_H__

#include "global.h"

#define VALUABLE_CAP 16  // 貴重品インベントリのスロット数

typedef u16 ItemEffectType;  // see "include/constants/item.h", gItemEffectHandlers の idx

typedef u16 ItemUsageFlags;             // ItemData.usage
#define IUF_FORM_MASK 0x000F            // 使える姿, 0: 赤ジャンゴのみ, 1: 黒ジャンゴ (と変身中) のみ, 2: 両方
#define IUF_CHECK_MASK 0x00F0           // 今使って意味があるかの判定方法, 0: 使えない, 1: 常に可, 2: HP が減っている, 3: ENE が減っている, 4: 状態異常がある, 5: 装備武器が傷んでいる
#define IUF_FORM_RED 0x0000             // IUF_FORM_MASK の値, 赤ジャンゴのみ
#define IUF_FORM_DARK 0x0001            // IUF_FORM_MASK の値, 黒ジャンゴ (と変身中) のみ
#define IUF_FORM_BOTH 0x0002            // IUF_FORM_MASK の値, 両方
#define IUF_CHECK_NEVER 0x0000          // IUF_CHECK_MASK の値, 使えない
#define IUF_CHECK_ALWAYS 0x0010         // IUF_CHECK_MASK の値, 常に可
#define IUF_CHECK_HP 0x0020             // IUF_CHECK_MASK の値, HP が減っている
#define IUF_CHECK_ENE 0x0030            // IUF_CHECK_MASK の値, ENE が減っている
#define IUF_CHECK_BADCOND 0x0040        // IUF_CHECK_MASK の値, 状態異常がある
#define IUF_CHECK_WEAPON_REPAIR 0x0050  // IUF_CHECK_MASK の値, 装備武器が傷んでいる
#define IUF_DISCARDABLE 0x0100          // 捨てられる
#define IUF_9 0x0200                    // 読み手なし, バフ・ワープ・IET_BUGS・ダークカード・PET で立っている

typedef struct {
  ItemUsageFlags usage;       // 0x00, see IUF_*
  ItemEffectType effectType;  // 0x02, see ItemEffectType
  u16 durability;             // 0x04, 腐りにくさ (0: 腐らない, 大きいほど腐りにくい)
  u16 value1;                 // 0x06, パラメータ1, ItemEffectType に依存 e.g. 回復アイテム(IET_HP)の場合は回復するHPの割合, gItemEffectHandlers の 第2引数
  u16 value2;                 // 0x08, パラメータ2 e.g. IET_GOOD は value1 がバフ種類で, value2 がバフの効果時間, gItemEffectHandlers の 第3引数
  u32 price;                  // 0x0C
} ItemData;
static_assert(sizeof(ItemData) == 16);

extern const ItemData gItemDB[ITEM_NUM];

item32_t GetItemID(bool32 isValuable, s32 slot);
item32_t GetNormalItemID(s32 slot);
item32_t GetValuableItemID(s32 slot);
bool32 CheckItemOwn(item32_t id);
bool32 RemoveSpecifiedItem(item32_t id);
void RotItem(s32 rotDelta);

#endif  // __INCLUDE_ITEM_H__
