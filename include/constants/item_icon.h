#ifndef __INCLUDE_CONSTANTS_ITEM_ICON_H__
#define __INCLUDE_CONSTANTS_ITEM_ICON_H__

// SPRITE_INVENTORY_ICONS の poseIdx に対応するアイテムアイコンの内容

#define ICON_WEAPON(weaponID) (0 + (weaponID))  // 0..65: 武器ID と同じ
#define ICON_QUESTION1 66                       // 66: ハテナマーク1 (ICON_QUESTION2 との使い分けは不明)
#define ICON_ARMOR(armorID) (67 + (armorID))    // 67..103: 67 + 防具ID
#define ICON_ITEM(itemID) (104 + (itemID))      // 104..181: 104 + アイテムID
#define ICON_MAGIC(magicID) (182 + (magicID))   // 182..199: 182 + 魔法ID
#define ICON_MAGIC_UA 200                       // 魔法が使えないときのバツ印(例えば、赤ジャンゴの時、マップ上で暗黒魔法のアイコンはこれと交互に点滅する)
#define ICON_NONE 201                           // 空白用
#define ICON_TRASH 202                          // ゴミ箱アイコン
#define ICON_SORT 203                           // 整頓のアイコン
#define ICON_SELL 204                           // 売るのアイコン
#define ICON_QUESTION2 205                      // ハテナマーク2
#define ICON_ATEG 206                           // ひっくり返ったおてんきゲタ
#define ICON_TIMER_NONE 207                     // 耐久値のないアイコン
#define ICON_TIMER_100 208                      // 耐久値100%のアイコン
#define ICON_TIMER_75 209                       // 耐久値75%のアイコン
#define ICON_TIMER_50 210                       // 耐久値50%のアイコン
#define ICON_TIMER_25 211                       // 耐久値25%のアイコン
#define ICON_MEGAMAN(idx) (212 + (idx))         // クロスオーバーバトルで使うロックマンの顔アイコン(残りHPが少ないほど険しそうな表情になる)
#define ICON_SHADEMAN(idx) (215 + (idx))        // クロスオーバーバトルで使うシェードマンの顔アイコン(残りHPが少ないほど険しそうな表情になる)

#endif  // __INCLUDE_CONSTANTS_ITEM_ICON_H__
