#include "entity.h"
#include "global.h"
#include "random.h"
#include "sprite.h"

// 破片の1グループ, Entity08015220_Init が 4 グループぶんまとめて初期化する
typedef struct {
  bool8 active;          // 0x000, 0 以外なら _Update が Entity08015220_UpdateGroup を呼び、_Destroy がスプライトを外す
  u8 aliveCount;         // 0x001, まだ生きている破片の数, 0 になると active を落とす
  u8 kind;               // 0x002, u16_ARRAY_085aa902 / u16_ARRAY_085aa8f0 の添字
  u8 unk_003;            // 0x003
  AuxSpriteGfx gfx;      // 0x004, u16_ARRAY_085aa902[kind]
  bool8 unk_020[6];      // 0x020, 破片を作るときに 1 が入る
  u8 lifetime[6];        // 0x026, 毎フレーム -1, 0xFF まで回り込んだ破片を外す
  bool8 used[6];         // 0x02C, sprites の各要素が登録済みか, _Init が 0 で埋める
  u16 speed[6];          // 0x032, vel の x と z にかける倍率 (12bit 固定小数)
  u8 unk_03e[2];         // 0x03E
  Vec3 vel[6];           // 0x040, y は重力で毎フレーム -2 される
  AuxSprite sprites[6];  // 0x070, _Destroy が使用済みのものを AuxSprite_Remove に渡す
} Entity08015220Group;
static_assert(sizeof(Entity08015220Group) == 376);

typedef struct {
  Entity e;                       // 0x000, ENTITY_UNK_10
  s32 timer;                      // 0x018, _Update が毎フレーム +1 する
  u8 unk_01c[4];                  // 0x01C
  Entity08015220Group groups[4];  // 0x020
} Entity08015220;
static_assert(sizeof(Entity08015220) == 1536);

IWRAM_DATA Entity08015220* gEntity08015220 = NULL;  // 0x0300005C

const u16 u16_ARRAY_085aa8f0[9] = {0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};  // 0x085AA8F0

const SpriteID16 u16_ARRAY_085aa902[9] = {
    SPRITE_CUBE_ICE,
    SPRITE_CUBE_WOOD_DEBRIS_L,
    SPRITE_CUBE_ROCK_DEBRIS_L,
    SPRITE_DEBRIS_C42D,
    SPRITE_DF0E,
    SPRITE_CUBE_WOOD_DEBRIS_S,
    SPRITE_CUBE_ROCK_DEBRIS_S,
    SPRITE_DEBRIS_0334,
    SPRITE_1E15,
};  // 0x085AA902

Entity08015220* Entity08015220_Create(u32 val, u32 _);

void FUN_08014d94(void) { gEntity08015220 = NULL; }

// 残差6命令 (311/317). 原典は &groups[0].active / .gfx / .lifetime[0] / .speed[0] の4本を外側ループの前で作って 0x178 刻みで歩かせるが, agbcc は &p->groups[i] から都度導く
// ソース側でそれぞれポインタローカルにするのは自然な C とは言えないので採らない
NON_MATCH s32 FUN_08014da0(s32 count, s32 kind, Vec3* pos, s32 speed, s32 lifetimeBase, s32 lifetimeRand, s32 speedBase, s32 speedRand, s32 angleBase, s32 angleRand, s32 velYBase, s32 velYRand) {
#ifdef NONMATCHING_C
  Entity08015220* p;
  s32 i;

  if (gEntity08015220 == NULL) {
    if (Entity08015220_Create(0, 0) == NULL) {
      return -1;
    }
  }

  p = gEntity08015220;
  if (count > 6) {
    count = 6;
  }

  for (i = 0; i < 4; i++) {
    Entity08015220Group* g = &p->groups[i];

    if (!g->active) {
      s32 j;

      g->kind = kind;
      g->aliveCount = count;
      if (!Video_GetAuxSprite(&g->gfx, u16_ARRAY_085aa902[g->kind])) {
        return -1;
      }
      if (g->kind == 4 || g->kind == 8) {
        Video_SetAuxSpritePltt(&g->gfx, g->gfx.plttID + 1);
      }

      for (j = 0; j < count; j++) {
        AuxSprite* spr = &g->sprites[j];
        s32 angle;

        g->unk_020[j] = TRUE;
        g->lifetime[j] = lifetimeRand != 0 ? lifetimeBase + Mod(Random(), lifetimeRand) : lifetimeBase;
        g->speed[j] = speedRand != 0 ? speedBase + Mod(Random(), speedRand) : speedBase;
        angle = angleRand != 0 ? angleBase + Mod(Random(), angleRand) : angleBase;
        g->vel[j].x = COS(angle);
        g->vel[j].z = SIN(angle);
        g->vel[j].y = velYRand != 0 ? velYBase + Mod(Random(), velYRand) : velYBase;

        spr->flags &= ~SPRFLAG_HIDDEN;
        spr->pos = *pos;
        spr->pos.x += FixToInt(12, g->vel[j].x * speed);
        spr->pos.z += FixToInt(12, g->vel[j].z * speed);
        AuxSprite_Add(spr, &g->gfx, SPRFLAG_BLINK_ODD);
        spr->poseIdx = u16_ARRAY_085aa8f0[g->kind];
        if ((Random() & 0xFF) <= 0x80) {
          spr->flags |= SPRFLAG_XFLIP;
        } else {
          spr->flags &= ~SPRFLAG_XFLIP;
        }
        g->used[j] = TRUE;
      }

      g->active = TRUE;
      return 0;
    }
  }

  return 0;
#else
  INCFUNC("asm/func/FUN_08014da0.inc");
#endif
}

// 破片をそれぞれ速度ぶん動かし, 寿命が切れたものを外す. 全部切れたらグループを閉じる
void Entity08015220_UpdateGroup(Entity08015220* p, Entity08015220Group* g) {
  s32 i;

  g->aliveCount = 0;

  for (i = 0; i < 6; i++) {
    AuxSprite* spr = &g->sprites[i];

    if (g->used[i]) {
      spr->pos.x += FixToInt(12, g->vel[i].x * g->speed[i]);
      spr->pos.y += g->vel[i].y;
      spr->pos.z += FixToInt(12, g->vel[i].z * g->speed[i]);
      g->vel[i].y -= 2;
      g->lifetime[i]--;
      if (g->lifetime[i] == 0xFF) {
        g->used[i] = FALSE;
        AuxSprite_Remove(spr);
      } else {
        g->aliveCount++;
      }
    }
  }

  if (g->aliveCount == 0) {
    g->active = FALSE;
  }
}

s32 Entity08015220_Update(Entity08015220* p) {
  Entity08015220Group* g = p->groups;
  s32 i;

  for (i = 0; i < 4; g++, i++) {
    if (g->active) {
      Entity08015220_UpdateGroup(p, g);
    }
  }
  p->timer++;
  return 0;
}

s32 Entity08015220_Destroy(Entity08015220* p) {
  Entity08015220Group* g;
  s32 i;
  s32 j;

  for (i = 0; i < 4; i++) {
    g = &p->groups[i];
    if (g->active) {
      for (j = 0; j < 6; j++) {
        if (g->used[j]) {
          AuxSprite_Remove(&g->sprites[j]);
        }
      }
    }
  }
  gEntity08015220 = NULL;
  return 0;
}

s32 Entity08015220_Init(Entity08015220* p, u32 _) {
  Entity08015220Group* g;
  s32 i;
  s32 j;

  for (i = 0; i < 4; i++) {
    g = &p->groups[i];
    g->active = FALSE;
    for (j = 0; j < 6; j++) {
      g->used[j] = FALSE;
    }
  }
  p->timer = 0;
  gEntity08015220 = p;
  return 0;
}

Entity08015220* Entity08015220_Create(u32 val, u32 _) {
  Entity08015220* p = CreateEntity(ENTITY_UNK_10, sizeof(Entity08015220));
  if (p != NULL) {
    SetEntityRoutine(p, Entity08015220_Update, Entity08015220_Destroy);
    if (Entity08015220_Init(p, val) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
