#include "entity.h"
#include "file.h"
#include "gba/macro.h"
#include "global.h"
#include "sprite_animation.h"
#include "sprite_aux.h"
#include "sprite_main.h"
#include "vm.h"

typedef struct Entity0FC5 {
  Entity e;                                    // 0x0, ENTITY_UNK_8
  MainSpriteGfx gfx_18;                        // 0x018, SPRITE_DJANGO_SABATA
  MainSprite sprite_38;                        // 0x38, 根拠: Entity0FC5_RemoveSprites が unk_f4 == 0 のとき MainSprite_Remove に渡す
  AuxSprite sprite_98;                         // 0x98, 根拠: Entity0FC5_RemoveSprites が unk_f4 != 0 のとき AuxSprite_Remove に渡す
  AuxSpriteGfx gfx_c4;                         // 0x0C4, SPRITE_OTENKO_00
  AuxAnimState anim_e0;                        // 0x0E0
  AuxAnimFile* animFile;                       // 0x0F0, ANIM_OTENKO
  s32 unk_f4;                                  // 0xF4, gEntity0FC5s での自分の添字, '.k' の値
  u32 pauseFlags;                              // 0x0F8, bit0/bit1 が立っている間 timer_100 / timer_108 を止める
  u32 unk_fc;                                  // 0x0FC, まだ未解析
  u32 timer_100;                               // 0x100
  u32 unk_104;                                 // 0x104, まだ未解析
  u32 timer_108;                               // 0x108
  s32 unk_10c;                                 // 0x10C, '.p[0]' を16ビット左シフトした値 (16.16 固定小数)
  s32 unk_110;                                 // 0x110, '.p[1]' を同様に入れる
  u8 unk_114[0x124 - 0x114];                   // 0x114, まだ未解析
  s16 unk_124;                                 // 0x124, '.s'
  u8 unk_126[2];                               // 0x126, まだ未解析
  s16 unk_128;                                 // 0x128, 64 で初期化, unk_130 と対
  s16 unk_12a;                                 // 0x12A, 64 で初期化, unk_132 と対
  s16 unk_12c;                                 // 0x12C
  s16 unk_12e;                                 // 0x12E
  s16 unk_130;                                 // 0x130, '.S=64'
  s16 unk_132;                                 // 0x132, '.S=64' (unk_130 と同じ値)
  s16 unk_134;                                 // 0x134
  s16 unk_136;                                 // 0x136
  u8 unk_138[0x13C - 0x138];                   // 0x138, まだ未解析
  AuxSprite sprite_13c;                        // 0x13C, 根拠: Entity0FC5_RemoveSprites が AuxSprite_Remove に渡す
  AuxSpriteGfx gfx_168;                        // 0x168, SPRITE_EFF_1C1B
  void (*updateCallback)(struct Entity0FC5*);  // 0x184
  u8 unk_188[392 - 0x188];                     // 0x188, まだ未解析
} Entity0FC5;
static_assert(sizeof(Entity0FC5) == 392);

COMMON_DATA Entity0FC5* gEntity0FC5s[2] = {};  // 0x03002C98, '.k' の値を添字にして Entity0FC5 が自分を登録する

NAKED void FUN_0821a87c(void) { INCFUNC("asm/func/FUN_0821a87c.inc"); }

NAKED void FUN_0821a974(void) { INCFUNC("asm/func/FUN_0821a974.inc"); }

NAKED void FUN_0821a9d8(void) { INCFUNC("asm/func/FUN_0821a9d8.inc"); }

NAKED void FUN_0821aa3c(Entity0FC5* p) { INCFUNC("asm/func/FUN_0821aa3c.inc"); }

NAKED s32 FUN_0821aac0(Entity0FC5* p) { INCFUNC("asm/func/FUN_0821aac0.inc"); }

NAKED void FUN_0821abfc(Entity0FC5* p) { INCFUNC("asm/func/FUN_0821abfc.inc"); }

void (*const PTR_ARRAY_085affa4[1])(Entity0FC5*) = {
    FUN_0821abfc,
};

static inline void Entity0FC5_SetPauseFlags(Entity0FC5* p, u32 bits) { p->pauseFlags |= bits; }

// val 番の処理へ切り替えて2本のタイマーを止める
void FUN_0821ae64(Entity0FC5* p, s32 val) {
  p->unk_fc = val;
  p->timer_100 = 0;
  p->updateCallback = PTR_ARRAY_085affa4[val];
  Entity0FC5_SetPauseFlags(p, 1);
  p->unk_104 = 0;
  p->timer_108 = 0;
  Entity0FC5_SetPauseFlags(p, 2);
}

// 残差は CpuFill32 の引数準備順の2命令だけ (188/188), 原典は dest の add r4,sp,#0x14 が tmp の0代入より前
// enemy_dex.c の同じ残差と同種, Tier A-C 試済
NON_MATCH void Entity0FC5_AddSprites(Entity0FC5* p) {
#ifdef NONMATCHING_C
  s32 x = FixToInt(16, p->unk_10c);
  s32 y = FixToInt(16, p->unk_110);
  s32 scale = p->unk_130;
  s32 idx = p->unk_f4;
  s32 subScale;

  if (idx == 0) {
    MainSpriteGfxFile* f = GetFile(DIR_MAIN_SPRITE, SPRITE_DJANGO_SABATA);
    Vec3 pos;

    p->gfx_18 = *f;
    OpenMainSpriteFile(&p->gfx_18, f);
    CpuFill32(0, &pos, sizeof(pos));
    pos.x = x;
    pos.y = y;
    MainSprite_Add(&p->sprite_38, &p->gfx_18, 7, SPRFLAG_UNK_15 | SPRFLAG_SCREEN_COORD | SPRFLAG_AFFINE, 1, 0, 60, &pos);
    MainSprite_SetAnim(&p->sprite_38, &p->gfx_18, 5, 1, 0);
    p->sprite_38.scaleX = scale;
    p->sprite_38.scaleY = scale;
  } else {
    AuxAnimFile* files;

    Video_GetAuxSprite(&p->gfx_c4, SPRITE_OTENKO_00);
    AuxSprite_Add(&p->sprite_98, &p->gfx_c4, SPRFLAG_UNK_15 | SPRFLAG_SCREEN_COORD | SPRFLAG_AFFINE);
    p->sprite_98.pos.x = x;
    p->sprite_98.pos.y = y;
    p->sprite_98.scaleX = scale;
    p->sprite_98.scaleY = scale;
    p->sprite_98.priority = 0;
    files = GetFile(DIR_ANIMATION, ANIM_OTENKO);
    p->animFile = files;
    AuxAnim_SetAnim(&p->anim_e0, files, 0, 0, 0);
  }

  Video_GetAuxSprite(&p->gfx_168, SPRITE_EFF_1C1B);
  AuxSprite_Add(&p->sprite_13c, &p->gfx_168, SPRFLAG_SCREEN_COORD | SPRFLAG_AFFINE);
  AuxSprite_SetPoseIdx(&p->sprite_13c, 5);
  p->sprite_13c.pos.x = x;
  p->sprite_13c.pos.y = y;
  subScale = Div(scale * 3, 4);
  p->sprite_13c.scaleX = subScale;
  p->sprite_13c.scaleY = subScale;
  p->sprite_13c.priority = 2;
#else
  INCFUNC("asm/func/Entity0FC5_AddSprites.inc");
#endif
}

// スプライトを描画リストから外す
void Entity0FC5_RemoveSprites(Entity0FC5* p) {
  if (p->unk_f4 == 0) {
    MainSprite_Remove(&p->sprite_38);
  } else {
    AuxSprite_Remove(&p->sprite_98);
  }

  AuxSprite_Remove(&p->sprite_13c);
}

s32 Entity0FC5_Update(Entity0FC5* p) {
  if (!(p->pauseFlags & 1)) {
    p->timer_100++;
  }
  if (!(p->pauseFlags & 2)) {
    p->timer_108++;
  }
  p->updateCallback(p);
  return 0;
}

// 描画を畳んで gEntity0FC5s の登録枠を空ける
s32 Entity0FC5_Destroy(Entity0FC5* p) {
  Entity0FC5_RemoveSprites(p);
  gEntity0FC5s[p->unk_f4] = NULL;
  return 0;
}

s32 Entity0FC5_Init(Entity0FC5* p) {
  s32 scale;

  p->pauseFlags = 0;
  p->unk_f4 = VM_GetNamedArgValue('k', -1);
  if (VM_SeekToNamedArg('p')) {
    p->unk_10c = VM_GetValue() << 16;
    p->unk_110 = VM_GetValue() << 16;
  }
  if (VM_SeekToNamedArg('s')) {
    p->unk_124 = VM_GetValue();
  }
  scale = VM_GetNamedArgValue('S', 64);
  p->unk_fc = 0;
  p->timer_100 = 0;
  p->unk_104 = 0;
  p->timer_108 = 0;
  p->unk_128 = 64;
  p->unk_12a = 64;
  p->unk_12c = 0;
  p->unk_12e = 0;
  p->unk_130 = scale;
  p->unk_132 = scale;
  p->unk_134 = 0;
  p->unk_136 = 0;
  Entity0FC5_AddSprites(p);
  FUN_0821ae64(p, 0);
  gEntity0FC5s[p->unk_f4] = p;
  return 0;
}

Entity0FC5* Entity0FC5_Create(void) {
  Entity0FC5* p = CreateEntity(ENTITY_UNK_8, sizeof(Entity0FC5));

  if (p != NULL) {
    SetEntityRoutine(p, Entity0FC5_Update, Entity0FC5_Destroy);
    if (Entity0FC5_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}
