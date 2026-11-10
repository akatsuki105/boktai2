#include "entity.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "player.h"
#include "random.h"
#include "sprite_aux.h"

// 花粉や鱗粉攻撃1つ分の情報
typedef struct {
  u16 delay;          // 0x00, 0 でなければ毎フレーム減る, 0 になるまでアニメが終わっても次へ進まない
  u8 state;           // 0x02, sSporeStates の添字
  u8 angle;           // 0x03, vel の向き
  u8 speed;           // 0x04, vel の大きさ
  u8 power;           // 0x05, プレイヤーに触れたとき SporeManager.power に足す
  u16 timer;          // 0x06, 毎フレーム +1
  u8 kind;            // 0x08, 0..3, SporeManager.attrKind に写される, 0 のときだけ sprite.pos が範囲内に丸められる
  u8 unk_09[3];       // 0x09
  Vec3 vel;           // 0x0C, 毎フレーム sprite.pos に足される
  AuxSpriteGfx gfx;   // 0x14, SPRITE_DUNEYRR_AUX, パレット行 0x224
  AuxSprite sprite;   // 0x30, pose 0xC, priority 2
  AuxAnimState anim;  // 0x5C, animFile のアニメ3番から始まる
} Spore;
static_assert(sizeof(Spore) == 108);

// 花粉や鱗粉攻撃の管理構造体
typedef struct {
  Entity e;               // 0x000, ENTITY_UNK_8
  AuxAnimFile* animFile;  // 0x018, ANIM_31F4
  u32 usedMask;           // 0x01C, elems のどのスロットが使用中かのビットマスク
  u32 frameCount;         // 0x020, 毎フレーム +1, 下位2bitを添字 & 3 と比べる
  u16 hitCount;           // 0x024, 毎フレーム 0 に戻してから, プレイヤーに触れた鱗粉の数を積む
  u16 unk_26;             // 0x026, hitCount * 12 を足して 0x40 に達すると player に power のダメージを与えるカウンタ
  u16 power;              // 0x028, 毎フレーム 0 に戻してから elems が積む, player に与えるダメージ
  u8 attrKind;            // 0x02A, ダメージの属性, 0 と 3 は風, 1 は地, 2 はダーク, 1 のとき player を見る分岐に入る
  u8 unk_2b;              // 0x02B
  Spore spores[32];       // 0x02C
  Player* player;         // 0xDAC, gPlayerPtr[0]
} SporeManager;
static_assert(sizeof(SporeManager) == 3504);

static SporeManager* gSporeManager;  // 0x03000128

void Spore_StateSpread(SporeManager*, Spore*, s32);
void Spore_StateDrift(SporeManager*, Spore*, s32);
void Spore_StateFade(SporeManager*, Spore*, s32);

const u16 sSporeHitLimits[4] = {4, 1, 2, 4};  // 0x085AB990

void (*const sSporeStates[3])(SporeManager*, Spore*, s32) = {
    Spore_StateSpread,
    Spore_StateDrift,
    Spore_StateFade,
};  // 0x085AB998

// 生まれて 16 フレーム経ったらプレイヤーとの当たりを数えつつ, 動かしてアニメを進め, 一巡したら次の状態へ移す
// 残差は前半のプレイヤー判定のレジスタ割当 (230/226), 原典は attrKind を r5, power を sb に置くが, こちらは attrKind が r8 に回り callee-saved が1本増える
// 手動送りは AuxSprite_AdvanceAnim で原典と同形, attrKind / power の型, 宣言位置, pos / vel を頭で取る形, anim のローカル有無は試済
NON_MATCH void Spore_StateSpread(SporeManager* p, Spore* elem, s32 idx) {
#ifdef NONMATCHING_C
  AuxSprite* sprite = &elem->sprite;
  Vec3* pos;
  Vec3* vel;

  if (elem->timer > 15) {
    u8 power;
    s32 attrKind;
    WorldPos* playerPos;

    power = elem->power;
    attrKind = elem->kind;
    pos = &elem->sprite.pos;
    playerPos = &p->player->mover.pos;
    if (p->hitCount < sSporeHitLimits[attrKind] && (p->frameCount & 3) == (idx & 3)) {
      s32 dx = abs(playerPos->x - pos->x);
      if (dx < Q8(0.5)) {
        s32 dz = abs(playerPos->z - pos->z);
        if (dz < Q8(0.5)) {
          p->attrKind = attrKind;
          p->hitCount++;
          p->power += power;
        }
      }
    }
  }
  pos = &sprite->pos;
  vel = &elem->vel;
  pos->x += vel->x;
  pos->y += vel->y;
  pos->z += vel->z;
  if (AuxSprite_AdvanceAnim(sprite, &elem->anim)) {
    elem->state++;
    elem->timer = 0;
    AuxAnim_SetAnim(&elem->anim, p->animFile, elem->state + 3, 0, 0);
  }
#else
  INCFUNC("asm/func/Spore_StateSpread.inc");
#endif
}

// 動かしながらプレイヤーとの当たりを数えてアニメを進め, delay が切れた後に一巡したら次の状態へ移るか枠を空ける
void Spore_StateDrift(SporeManager* p, Spore* elem, s32 idx) {
  AuxSprite* sprite = &elem->sprite;
  Vec3* pos = &sprite->pos;
  Vec3* vel = &elem->vel;
  bool32 ended;
  u8 power;
  s32 attrKind;
  WorldPos* playerPos;

  pos->x += vel->x;
  pos->y += vel->y;
  pos->z += vel->z;
  power = elem->power;
  attrKind = elem->kind;
  playerPos = &p->player->mover.pos;
  if (p->hitCount < sSporeHitLimits[attrKind] && (p->frameCount & 3) == (idx & 3)) {
    s32 dx = abs(playerPos->x - pos->x);
    if (dx < 0x80) {
      s32 dz = abs(playerPos->z - pos->z);
      if (dz < 0x80) {
        p->attrKind = attrKind;
        p->hitCount++;
        p->power += power;
      }
    }
  }

  if (elem->delay != 0) {
    elem->delay--;
  }
  ended = AuxSprite_AdvanceAnim(sprite, &elem->anim);
  if (ended && elem->delay == 0) {
    if (elem->kind == 0 || elem->kind == 3) {
      elem->state++;
      elem->timer = 0;
      AuxAnim_SetAnim(&elem->anim, p->animFile, elem->state + 3, 0, 0);
    } else {
      CLEAR_BIT(p->usedMask, idx);
      AuxSprite_Remove(sprite);
    }
  }
}

// 速度ぶん動かしてアニメを1コマ進め, 一巡したら枠を空けてスプライトを外す
void Spore_StateFade(SporeManager* p, Spore* elem, s32 idx) {
  AuxSprite* sprite = &elem->sprite;
  Vec3* pos = &sprite->pos;
  Vec3* vel = &elem->vel;

  pos->x += vel->x;
  pos->y += vel->y;
  pos->z += vel->z;
  if (AuxSprite_AdvanceAnim(sprite, &elem->anim)) {
    CLEAR_BIT(p->usedMask, idx);
    AuxSprite_Remove(sprite);
  }
}

s32 SporeManager_Update(SporeManager* p) {
  Spore* spore;
  s32 i;

  p->hitCount = 0;
  p->power = 0;
  spore = p->spores;
  for (i = 0; i < 32; i++, spore++) {
    if (p->usedMask & (1 << i)) {
      sSporeStates[spore->state](p, spore, i);
      if (spore->kind == 0) {
        Vec3* pos = &spore->sprite.pos;

        if (pos->x < 0x120) {
          pos->x = 0x120;
        } else if (pos->x > 0xBE0) {
          pos->x = 0xBE0;
        }
        if (pos->z < 0x220) {
          pos->z = 0x220;
        } else if (pos->z > 0xC80) {
          pos->z = 0xC80;
        }
      }
      spore->timer++;
    }
  }
  if (p->hitCount != 0) {
    p->unk_26 += p->hitCount * 12;
    if (p->unk_26 >= 0x40) {
      p->unk_26 = 0;
      switch (p->attrKind) {
        case 0:
        case 3: {
          Player_TakeInstantHit(p->player, p->power, 0, 0, 8, HBATTR_CLOUD);
          break;
        }
        case 1: {
          Player_TakeInstantHit(p->player, p->power, 0, 0, 8, HBATTR_EARTH);
          break;
        }
        case 2: {
          Player_TakeInstantHit(p->player, p->power, 0, 0, 8, HBATTR_DARK);
          break;
        }
      }
    }
  } else {
    p->unk_26--;
  }
  p->frameCount++;
  return 0;
}

static inline Player* GetPlayer(s32 idx) { return gPlayerPtr[idx]; }

s32 SporeManager_Destroy(SporeManager* p) {
  Spore* spore = p->spores;
  s32 i;

  for (i = 0; i < 32; i++, spore++) {
    if (p->usedMask & (1 << i)) {
      AuxSprite_Remove(&spore->sprite);
    }
  }
  gSporeManager = NULL;
  return 0;
}

s32 SporeManager_Init(SporeManager* p) {
  Spore* spore;
  s32 i;

  gSporeManager = p;
  p->animFile = GetFile(DIR_ANIMATION, ANIM_31F4);
  p->usedMask = 0;
  spore = p->spores;
  for (i = 0; i < 32; i++, spore++) {
    Vec3* pos;

    spore->speed = 0;
    spore->angle = 0;
    if (!Video_GetAuxSprite(&spore->gfx, SPRITE_DUNEYRR_AUX)) {
      return -1;
    }
    Video_SetAuxSpritePltt(&spore->gfx, 548);
    AuxSprite_Setup(&spore->sprite, &spore->gfx, 0);
    spore->sprite.poseIdx = 12;
    AuxAnim_SetAnim(&spore->anim, p->animFile, 3, 0, 0);
    spore->sprite.priority = 2;
    pos = &spore->sprite.pos;
    CpuFill32(0, pos, sizeof(Vec3));
  }
  p->player = GetPlayer(0);
  return 0;
}

SporeManager* SporeManager_Create(void) {
  if (gSporeManager == NULL) {
    SporeManager* p = CreateEntity(ENTITY_UNK_8, sizeof(SporeManager));

    if (p != NULL) {
      SetEntityRoutine(p, SporeManager_Update, SporeManager_Destroy);
      if (SporeManager_Init(p) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gSporeManager;
}

// 残差は switch の case 0/3 と default (同じ中身) が cross jump で1つに畳まれる点と, ループ内の gfx / pos のポインタの持ち方, 原典は2つの塊でレジスタが違うので畳まれない
// 引数はすべて 32bit, 3つのローカルは s32 で書いて byte / halfword で読む形までは合わせた, Tier A-C は試済
NON_MATCH s32 SporeManager_Emit(s32 count, u32 angle, s32 angleRange, u32 speed, s32 speedRange, u32 delay, u32 power, s32 kind, Vec3* pos) {
#ifdef NONMATCHING_C
  SporeManager* p = gSporeManager;
  Spore* spore;
  s32 i;
  s32 added;
  s32 halfAngleRange;
  s32 halfSpeedRange;
  s32 animIdx;
  s32 plttID;
  s32 priority;

  if (p == NULL) {
    p = SporeManager_Create();
    if (p == NULL) {
      return -1;
    }
  }
  switch (kind) {
    case 0:
    case 3: {
      animIdx = 3;
      plttID = 0x224;
      priority = 2;
      break;
    }
    case 1: {
      animIdx = 6;
      plttID = 0x22C;
      priority = 1;
      break;
    }
    case 2: {
      animIdx = 8;
      plttID = 0x23A;
      priority = 2;
      break;
    }
    default: {
      animIdx = 3;
      plttID = 0x224;
      priority = 2;
      break;
    }
  }
  halfAngleRange = angleRange >> 1;
  halfSpeedRange = speedRange >> 1;
  added = 0;
  spore = p->spores;
  for (i = 0; i < 32; i++, spore++) {
    if (!(p->usedMask & (1 << i))) {
      AuxSprite* sprite = &spore->sprite;

      spore->kind = kind;
      spore->delay = delay;
      if ((u8)kind == 0 || (u8)kind == 3) {
        spore->state = 0;
      } else {
        spore->state = 1;
      }
      spore->timer = 0;
      spore->power = power;
      if (angleRange == 0) {
        spore->angle = angle;
      } else {
        spore->angle = angle + Mod(Random(), angleRange) - halfAngleRange;
      }
      if (speedRange == 0) {
        spore->speed = speed;
      } else {
        spore->speed = speed + Mod(Random(), speedRange) - halfSpeedRange;
      }
      spore->vel.x = POLAR_X(spore->speed, spore->angle);
      spore->vel.y = 0;
      spore->vel.z = POLAR_Z(spore->speed, spore->angle);
      spore->vel.y = 0;
      sprite->pos = *pos;
      AuxAnim_SetAnim(&spore->anim, p->animFile, animIdx, 0, 0);
      sprite->poseIdx = 18;
      sprite->priority = priority;
      Video_AddAuxSpriteIntoDrawList(sprite, 0);
      Video_SetAuxSpritePltt(&spore->gfx, plttID);
      if (spore->kind == 0) {
        Vec3* spritePos = &spore->sprite.pos;

        if (spritePos->x < 0x120) {
          spritePos->x = 0x120;
        } else if (spritePos->x > 0xBE0) {
          spritePos->x = 0xBE0;
        }
        if (spritePos->z < 0x220) {
          spritePos->z = 0x220;
        } else if (spritePos->z > 0xC80) {
          spritePos->z = 0xC80;
        }
      }
      SET_BIT(p->usedMask, i);
      added++;
      if (added >= count) {
        break;
      }
    }
  }
#else
  INCFUNC("asm/func/SporeManager_Emit.inc");
#endif
}
