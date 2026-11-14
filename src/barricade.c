#include "collision_map.h"
#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "map_inline.h"
#include "puff.h"
#include "random.h"
#include "sprite_aux.h"
#include "vm.h"

// 魔法"ダイナマイト"で壊せるブロック, 壁叩き時の音が SE_WALL_KNOCK_FRAGILE
typedef struct {
  Entity e;                      // 0x00, ENTITY_UNK_8
  AuxSprite sprite;              // 0x18
  AuxSpriteGfx gfx;              // 0x44, `.t=SPRITE_BLOCK_ROCK`, SPRITE_WALL_DB6C, SPRITE_WALL_4AEE
  HitboxData hurtbox;            // 0x60
  MapTileOverride tileOverride;  // 0xB0, tileIdx のタイルの高さを height で上書きする
  u8 unk_c0;                     // 0xC0
  u8 height;                     // 0xC1, Map_AddTileOverride に渡す上書き後の高さ
  u16 tileIdx;                   // 0xC2, '.p' の位置から引いた当たり判定マップのタイル番号
  bool8 triggered;               // 0xC4, Barricade_OnHurt が立て, _Update が見て自壊する
  u32 scriptID;                  // 0xC8, '.R', 壊れたときに VM_ExecByID へ渡す
} Barricade;
static_assert(sizeof(Barricade) == 204);

void Barricade_OnHurt(HitboxData* a, HitboxData* b, Barricade* p) {
  if (Hitbox_HasWeakness(a, HBATTR_ALL)) {
    p->triggered = TRUE;
  }
}

void Barricade_SpawnBurstPtcl(Barricade* p) {
  PuffParam param;
  WorldPos pos;
  s32 i;

  param.kind = 2;
  param.flags = 0;
  param.animSpeed = Q6(1);
  param.speedY = 3;
  param.speedYRand = 6;
  param.speedXZ = 2;
  param.speedXZRand = 2;
  param.angleY = 0x3C;
  param.angleYRand = 8;
  param.angleXZ = 0;
  param.angleXZRand = 0xFF;
  param.decayStartY = 0xFF;
  param.decayStartYRand = 0;
  param.decayY = 0xFF;
  param.decayYRand = 0;
  param.decayStartXZ = 0xFF;
  param.decayStartXZRand = 0;
  param.decayXZ = 0xFF;
  param.decayXZRand = 0;
  for (i = 0; i < 6; i++) {
    pos = p->sprite.pos;
    pos.x += Mod(RandomNext(), 300) - 150;
    pos.y += Mod(RandomNext(), 300);
    pos.z += Mod(RandomNext(), 300) - 150;
    Puff_Spawn(1, &pos, &param);
  }
}

s32 Barricade_Update(Barricade* p) {
  if (p->triggered) {
    p->sprite.flags |= SPRFLAG_HIDDEN;
    Barricade_SpawnBurstPtcl(p);
    if (p->scriptID != 0) {
      u32 scriptID = p->scriptID;

      p->scriptID = 0;
      VM_ExecByID(scriptID, NULL);
    }
    KillEntity((Entity*)p);
  }
  return 0;
}

s32 Barricade_Destroy(Barricade* p) {
  AuxSprite_Remove(&p->sprite);
  Hitbox_Unregister(&p->hurtbox);
  Map_RemoveTileOverride(&p->tileOverride);
  // 戻り値のある宣言だが return なし
}

// 残差2命令 (48/46): 原典は poseIdx の三項演算子の else 側に movs r0, #0 を出さず VM_SeekToNamedArg の戻り値0をそのまま落とすが, agbcc は b + movs r0, #0 の else ブロックを作る
// Tier A-C は試済: sprite/gfx のローカル化で 50→48 に改善, s32 ローカルに受ける形 (リポジトリの一致済み6箇所と同じ綴り) は無影響
NON_MATCH void Barricade_InitSprite(Barricade* p, Vec3* pos) {
#ifdef NONMATCHING_C
  AuxSprite* spr = &p->sprite;
  AuxSpriteGfx* gfx = &p->gfx;

  if (VM_SeekToNamedArg('t')) {
    Video_GetAuxSprite(gfx, VM_GetValue());
  } else {
    Video_GetAuxSprite(gfx, SPRITE_BLOCK_ROCK);
  }
  AuxSprite_Add(spr, gfx, 0);
  spr->poseIdx = VM_SeekToNamedArg('i') ? VM_GetValue() : 0;
  spr->pos = *pos;
  if (VM_SeekToNamedArg('r') && VM_GetValue()) {
    spr->flags |= SPRFLAG_XFLIP;
  }
#else
  INCFUNC("asm/func/Barricade_InitSprite.inc");
#endif
}

void Barricade_InitHurtbox(Barricade* p, u32 id, Vec3* pos) {
  HitboxData* hurtbox = &p->hurtbox;
  Vec3 halfSize, offset;
  VEC3_SET(halfSize, Q8(0.5), Q8(0.5), Q8(0.5));
  VEC3_SET(offset, 0, Q8(0.5), 0);
  Hitbox_Init(hurtbox, id, HBFLAG_HURTBOX | HBFLAG_UNK_0, 0, HIM_5, &halfSize, &offset);
  Hitbox_SetHandler(hurtbox, Barricade_OnHurt, p);
  Hitbox_SetPos(hurtbox, pos, 0);
  Hitbox_Register(hurtbox);
}

// 残差はレジスタ順列のみ (174/174, 同数同順, hunk 12件): 原典は p を r5 / &pos を r6 に置くが agbcc は逆, 他は全部この派生
// Tier A-C は試済: (s32) キャストで >> 8 の asrs 化, scriptID を if/else にして命令数一致まで到達
NON_MATCH s32 Barricade_Init(Barricade* p, u32 id, u32 _) {
#ifdef NONMATCHING_C
  WorldPos pos;

  if (VM_SeekToNamedArg('p')) {
    pos.x = (((s32)VM_GetValue() >> 8) << 8) + Q8(0.5);
    pos.y = VM_GetValue();
    pos.z = (((s32)VM_GetValue() >> 8) << 8) + Q8(0.5);
  } else {
    VEC3_SET(pos, 0, 0, 0);
  }

  pos.y = TileHeightAt(&pos);
  p->tileIdx = GetCollisionTileIdx(&pos);
  p->height = (s8)(pos.y >> 8) + 1;
  Map_AddTileOverride(&p->tileOverride, p->tileIdx, STAIRS_NONE, p->height, 0xFF, TATTR_UNK_0 | TATTR_WALL | TATTR_FRAGILE);
  Barricade_InitSprite(p, &pos);
  Barricade_InitHurtbox(p, id, &pos);
  if (VM_SeekToNamedArg('R')) {
    p->scriptID = VM_GetValue();
  } else {
    p->scriptID = 0;
  }
  return 0;
#else
  INCFUNC("asm/func/Barricade_Init.inc");
#endif
}

// 0x3DB0
Barricade* Barricade_Create(u32 id, u32 _) {
  Barricade* p = CreateEntity(ENTITY_UNK_8, sizeof(Barricade));

  if (p != NULL) {
    SetEntityRoutine(p, Barricade_Update, Barricade_Destroy);
    if (Barricade_Init(p, id, _) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
