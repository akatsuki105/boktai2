#include "entity.h"
#include "file.h"
#include "global.h"
#include "sprite_aux.h"
#include "vec3.h"
#include "vm.h"

// 不使用?
// スプライト8枚を数珠つなぎに追従させる蛇, 先頭を下げながら 51 フレームだけ動く
typedef struct {
  Entity e;               // 0x000, ENTITY_UNK_8
  u32 frameCounter;       // 0x018, 51 に達すると _Update が何もしなくなる
  AuxSpriteGfx gfx;       // 0x01C, SPRITE_WORM
  AuxSprite sprites[8];   // 0x038, [0] が先頭, 後続は前の節へ一定距離まで引き寄せられる
  AuxAnimState anim;      // 0x198, 8枚で共有する再生状態
  AuxAnimFile* animFile;  // 0x1A8, ANIM_WORM
  u8 unk_1ac[64];         // 0x1AC, この型の Create/Init/Update/Destroy からは触られていない
  u16 unk_1ec;            // 0x1EC, _Init が 0 を入れる
  u16 unk_1ee;            // 0x1EE, _Init が 0 を入れる
  u16 unk_1f0;            // 0x1F0, _Init が 0 を入れる
  u16 unk_1f2;            // 0x1F2, _Init が 0 を入れる
} Entity3FFD;
static_assert(sizeof(Entity3FFD) == 500);

s32 FUN_081fa26c(Vec3* _) { return 0; }

// 先頭の節を下げ, 後続の節を前の節から一定距離以内へ引き寄せる
s32 Entity3FFD_Update(Entity3FFD* p) {
  if (p->frameCounter <= 50) {
    AuxSprite* prev = &p->sprites[0];
    AuxSprite* sprite = &p->sprites[1];
    s32 i;

    prev->pos.y += 40;
    for (i = 0; i < 7; prev++, sprite++, i++) {
      Vec3 d;
      s32 distSq;

      Vec3_Diff(&d, &sprite->pos, &prev->pos);
      distSq = d.x * d.x + d.y * d.y + d.z * d.z;
      if (distSq > 0x4000) {
        u16 len = Sqrt(distSq);

        if (len != 0) {
          d.x = Div(d.x << 7, len);
          d.y = Div(d.y << 7, len);
          d.z = Div(d.z << 7, len);
        }
        Vec3_Sum(&sprite->pos, &prev->pos, &d);
      }
    }
    p->frameCounter++;
  }
  return 0;
}

s32 Entity3FFD_Destroy(Entity3FFD* p) {
  s32 i;

  for (i = 0; i < 8; i++) {
    AuxSprite_Remove(&p->sprites[i]);
  }
}

s32 Entity3FFD_Init(Entity3FFD* p, u32 id) {
  AuxSpriteGfx* gfx = &p->gfx;
  AuxSprite* sprite = p->sprites;
  AuxAnimState* anim = &p->anim;
  WorldPos pos;
  s32 i;

  if (VM_SeekToNamedArg('p')) {
    VEC3_SET(pos, VM_GetValue(), VM_GetValue(), VM_GetValue());
  } else {
    VEC3_SET(pos, 0, 0, 0);
  }
  p->animFile = GetFile(DIR_ANIMATION, ANIM_WORM);
  Video_GetAuxSprite(gfx, SPRITE_WORM);
  AuxAnim_SetAnim(anim, p->animFile, 6, 0, 0);
  for (i = 0; i < 8; i++) {
    AuxSprite_Add(sprite, gfx, 0);
    sprite->pos = pos;
    AuxSprite_AdvanceAnim(sprite, anim);
    sprite++;
  }
  p->frameCounter = 0;
  p->unk_1f2 = 0;
  p->unk_1f0 = 0;
  p->unk_1ee = 0;
  p->unk_1ec = 0;
  return 0;
}

// 0x3FFD
Entity3FFD* Entity3FFD_Create(u32 id, u32 _) {
  Entity3FFD* p = CreateEntity(ENTITY_UNK_8, sizeof(Entity3FFD));

  if (p != NULL) {
    SetEntityRoutine(p, Entity3FFD_Update, Entity3FFD_Destroy);
    if (Entity3FFD_Init(p, id) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}
