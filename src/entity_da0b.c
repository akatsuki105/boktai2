#include "entity.h"
#include "global.h"
#include "sprite_main.h"
#include "sprite_pltt.h"
#include "struct.h"
#include "weapon.h"

typedef struct EntityDA0B EntityDA0B;
typedef void(EntityDA0BFunc)(EntityDA0B* p);

// 武器一覧の1枠, 武器データとその絵を1組で持つ
typedef struct {
  WeaponData data;    // 0x00, FUN_0801bf88 が (WeaponData*)(p + slot * 0x84 + 0x138) として引く
  MainSprite sprite;  // 0x24, FUN_0801c4bc が追加し FUN_0801c4b0 が消す
} EntityDA0BElem;
static_assert(sizeof(EntityDA0BElem) == 132);

// 武器の付け替えメニュー
struct EntityDA0B {
  Entity e;                      // 0x0000, ENTITY_UNK_11
  Vec3 pos;                      // 0x0018, '.p' の x, y, z, FUN_0823b8ac に渡す
  Vec3 pos2;                     // 0x0020, pos の写し
  u8 unk_28[0x3C - 0x28];        // 0x0028, まだ未解析
  u8 unk_3c;                     // 0x003C, FUN_0801b8d0 が 1 を入れる
  u8 cursor;                     // 0x003D, 選択中の weapons の添字
  u8 unk_3e;                     // 0x003E, FUN_0801c910 が 0 を入れる
  u8 unk_3f[0x44 - 0x3F];        // 0x003F, まだ未解析
  u32 unk_44;                    // 0x0044, FUN_0801b8d0 が 0 を入れる
  u32* tilemap;                  // 0x0048, GetFile(DIR_TILE_MAP, 0x9F57)
  rgb555* bgPltt;                // 0x004C, GetFile(DIR_BGPLTT, 0xA41A) + 0x14
  u32 selectable;                // 0x0050, 選べる武器スロットのビットマスク, FUN_0801c910 が作る
  u8 unk_54[0x6C - 0x54];        // 0x0054, まだ未解析
  s32 unk_6c;                    // 0x006C, _Update が毎フレーム FUN_0824175c の戻り値を入れる
  u8 unk_70[0x95 - 0x70];        // 0x0070, まだ未解析
  u8 unk_95;                     // 0x0095, FUN_0801c910 が 0 を入れる
  u8 unk_96[0xB8 - 0x96];        // 0x0096, まだ未解析
  s16 unk_b8;                    // 0x00B8, '.c' の値
  s16 unk_ba;                    // 0x00BA, '.e' の値
  char statText[4];              // 0x00BC, FUN_08094c6c が武器の補正値を "+12" / "SP" の形で書く
  u8 unk_c0[0xD8 - 0xC0];        // 0x00C0, まだ未解析
  MainSpriteGfx gfx0;            // 0x00D8, SPRITE_UI_MISC
  MainSpriteGfx gfx1;            // 0x00F8, SPRITE_UI_START_MENU
  MainSpriteGfx gfx2;            // 0x0118, SPRITE_INVENTORY_ICONS
  EntityDA0BElem weapons[19];    // 0x0138, FUN_0801c5d0 が stride 0x84 で19個まわす, 前の16個が武器スロット
  MainSprite sprites0[3];        // 0x0B04, [0] がカーソル
  MainSprite sprites1[4];        // 0x0C24, FUN_0801c3a8 が gStat->registeredWeapon の位置に置く
  MainSprite iconSprite;         // 0x0DA4, 選択中の武器の絵
  MainSprite sprites2[13];       // 0x0E04, FUN_0801d084 が追加し FUN_0801d6a0 が消す
  u8 unk_12e4[0x1304 - 0x12E4];  // 0x12E4, まだ未解析
  EntityDA0BFunc* fn;            // 0x1304, _Update が毎フレーム呼ぶ, FUN_0801b8d0 が差し替える
  u8* unk_1308;                  // 0x1308, '.w' の FUN_0823d340 の戻り値, TextBox_Start に渡す
  u8* unk_130c;                  // 0x130C, '.k' の FUN_0823d340 の戻り値, VM_ParseStringRef に渡す
  u8 unk_1310[0x131C - 0x1310];  // 0x1310, まだ未解析
  s16 unk_131c;                  // 0x131C, '.n' の値 (既定 0xB156)
  u16 unk_131e;                  // 0x131E, _Init が 5 を入れる
  u8 unk_1320[0x1364 - 0x1320];  // 0x1320, まだ未解析
};
static_assert(sizeof(EntityDA0B) == 4964);

IWRAM_DATA EntityDA0B* gEntityDA0B = NULL;  // 0x03000098

INCASM("asm/entity_da0b.inc");
