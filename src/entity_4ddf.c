#include "entity.h"
#include "global.h"

struct EntityC946;

// スライド1枚ぶん, '.t' が holdTime / fadeInTime / fadeOutTime を、'.c' が x / y / previewID を同じ添字に書き込む
typedef struct {
  s16 holdTime;     // 0x0, 絵を出したまま待つフレーム数, Init で -1 ならリストの終端
  u16 fadeInTime;   // 0x2, 明るさを 0 から 64 まで上げるフレーム数
  u16 fadeOutTime;  // 0x4, 明るさを 64 から 0 まで下げるフレーム数
  u16 x;            // 0x6, 絵の表示位置
  u16 y;            // 0x8, 同上
  s16 previewID;    // 0xA, sEnemyDexModels の添字, 0x46 なら絵を出さずに待つだけ、-1 でスライドショー終了
} Entity4DDFData;
static_assert(sizeof(Entity4DDFData) == 12);  // 0x08211db8

// スクリプトから貰った絵を1枚ずつ、画面の明るさをフェードさせながら順に見せる, スタッフロールの右下で行われるキャラクターのスライドショーを担当すると思われるがまだ未確定
typedef struct Entity4DDF {
  Entity e;                    // 0x000, ENTITY_UNK_8
  Entity4DDFData slides[64];   // 0x018, _Init が '.t' と '.c' から読む
  struct EntityC946* preview;  // 0x318, 絵を出す担当, _Init が EntityC946_Create(arg, 0) で作る
  s32 lastSlide;               // 0x31C, 最後のスライドの添字 (件数 - 1), _Update はここを超えたら何もしない
  s16 curSlide;                // 0x320, 再生中のスライドの添字
  u16 timer;                   // 0x322, step に入ってからのフレーム数, FUN_08211bac が 0 に戻す
  u8 step;                     // 0x324, 0: フェードイン, 1: 表示待ち, 2: フェードアウト, 3: 絵なしで待つ, 4: 終了
  u8 unk_325[3];               // 0x325, 読み手も書き手も見つかっていない, padding?
} Entity4DDF;
static_assert(sizeof(Entity4DDF) == 808);

INCASM("asm/entity_4ddf.inc");

NAKED void FUN_08211d7c(Entity4DDF* p, Entity4DDFData* q) { INCFUNC("asm/func/FUN_08211d7c.inc"); }

NAKED s32 Entity4DDF_Update(Entity4DDF* p) { INCFUNC("asm/func/Entity4DDF_Update.inc"); }

s32 Entity4DDF_Destroy(Entity4DDF* _) { return 0; }

NAKED s32 Entity4DDF_Init(Entity4DDF* p, void* _) { INCFUNC("asm/func/Entity4DDF_Init.inc"); }

Entity4DDF* Entity4DDF_Create(void* _) {
  Entity4DDF* p = CreateEntity(ENTITY_UNK_8, sizeof(Entity4DDF));
  if (p != NULL) {
    SetEntityRoutine(p, Entity4DDF_Update, Entity4DDF_Destroy);
    if (Entity4DDF_Init(p, _) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
