#include "collision_map.h"
#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "malloc.h"
#include "player.h"
#include "sound.h"
#include "sprite.h"
#include "sprite_aux.h"
#include "vm.h"

// HazardManager がまとめて管理する、触れるとダメージを受ける破壊可能な設置物
// スクリプトコマンド 0x2306 (HazardManager_SpawnScripted) が1個ずつ生成する
typedef struct {
  u16 id;             // 0x00, hitbox の id になる, script keyword 'n'
  s16 hp;             // 0x02, script keyword 'l' (既定 100), Hazard_OnHit が HitboxData.damage の分だけ減らし 0 以下で破壊される
  s32 areaId;         // 0x04, script keyword 'm' が 0 以外のときだけ FUN_08241574(pos) の戻り値が入る。負なら生成を中止する。書くだけで読み手はいない
  u16 scriptId;       // 0x08, script keyword 'b', 破壊時に Script_ExecById へ渡してから 0 に戻す
  u8 damageTimer;     // 0x0A, 被弾時に 10 がセットされ毎フレーム減る。0 でない間だけ hitbox.flags に HBFLAG_UNK_2 が立つ
  u8 unk_0b;          // 0x0B
  s16 scriptArgs[4];  // 0x0C, script keyword 'a' の4要素, 破壊時の Script_ExecById の argv[4..7] になる

  Vec3 pos;  // 0x14, HazardManager_Spawn の第1引数のコピー
  Vec3 min;  // 0x1C, pos - (0xA4, 0x80, 0xA4)
  Vec3 max;  // 0x24, pos + (0xA4, 0x80, 0xA4), プレイヤーが min..max に入ると HazardManager.hitbox が攻撃側として登録される

  HitboxData hitbox;             // 0x2C, 被弾用 (flags 0x4001), fn は Hazard_OnHit で owner はこの Hazard
  MapTileOverride tileOverride;  // 0x7C, 足元のタイルの高さを +1 して通れなくする
  AuxSprite node;                // 0x8C
  AuxSpriteGfx sprite;           // 0xB8, Video_GetAuxSprite(&sprite, 0x4B3)
} Hazard;
static_assert(sizeof(Hazard) == 212);

// 触れるとダメージを受ける破壊可能な設置物をまとめて管理する
// 攻撃判定は Hazard ごとには持たず、プレイヤーが近付いた Hazard の位置へ hitbox を移して1フレームだけ登録する
typedef struct {
  Entity e;           // 0x00, ENTITY_UNK_8
  u8 count;           // 0x18, script keyword 'm' (既定 8)
  u8 unk_19[3];       // 0x19
  u32 activeMask;     // 0x1C, bit i が hazards[i] 使用中
  Hazard* hazards;    // 0x20, Malloc(count * sizeof(Hazard))
  HitboxData hitbox;  // 0x24, プレイヤーへの攻撃判定 (flags 0x2001), 威力は script keyword 'p'/'f'/'i'
} HazardManager;
static_assert(sizeof(HazardManager) == 116);

COMMON_DATA HazardManager* gHazardManager = NULL;  // 0x03002B34

static inline bool32 Hitbox_HasWeakness(HitboxData* p, u32 mask) { return p->weakness & mask; }

// 被弾時に呼ばれる。hp を削り、0 以下になったら破壊待ちにし、そうでなければ点滅させる
void Hazard_OnHit(HitboxData* a, HitboxData* b, void* owner) {
  Hazard* p = owner;

  Hitbox_ApplyDamage(a, b);
  if (b->damage != 0) {
    p->hp -= b->damage;
    if (p->hp <= 0) {
      p->hp = 0;
    } else {
      p->damageTimer = 10;
      Video_SetAuxSpritePltt(&p->sprite, 0x132);
      if (!Hitbox_HasWeakness(a, 4)) {
        PlaySound_082406e0(0x13E);
      }
    }
    b->damage = 0;
  }
}

// Hazard 1個を当たり判定・描画・地形の各リストから外し、スロットを空きに戻す
s32 Hazard_Remove(HazardManager* p, Hazard* hazard, u32 idx) {
  Hitbox_Unregister(&hazard->hitbox);
  AuxSprite_Remove(&hazard->node);
  FUN_082342a8(&hazard->tileOverride);
  p->activeMask &= ~(1 << idx);
}

s32 FUN_08014da0(s32 param_1, s32 param_2, Vec3* pos, s32 param_4, s32 param_5, s32 param_6, s32 param_7, s32 param_8, s32 param_9, s32 param_10, s32 param_11, s32 param_12);

// 破壊音を鳴らし、破片のパーティクルを2種類まき散らす
void Hazard_EmitBreakEffect(Hazard* p) {
  PlaySound_082406e0(0x14A);
  FUN_08014da0(3, 3, &p->pos, 0x3C, 0x1E, 0x10, 8, 8, 0, 0x100, 0x18, 0x10);
  FUN_08014da0(8, 7, &p->pos, 0x3C, 0x1E, 0x16, 8, 8, 0, 0x100, 0x18, 0x10);
}

static inline void SetHitboxFlags(HitboxData* p, HitboxFlags flags) { p->flags |= flags; }

static inline void ClearHitboxFlags(HitboxData* p, HitboxFlags flags) { p->flags &= ~flags; }

static inline bool32 Hazard_ContainsPoint(Hazard* p, Vec3* pos) { return pos->x >= p->min.x && pos->x <= p->max.x && pos->y >= p->min.y && pos->y <= p->max.y && pos->z >= p->min.z && pos->z <= p->max.z; }

// hp が尽きた Hazard を片付け、生きているものは点滅を進めつつ、プレイヤーが範囲に入った最初の1個に攻撃判定を置く
NON_MATCH s32 HazardManager_Update(HazardManager* p) {
#ifdef NONMATCHING_C
  Hazard* hazard;
  s32 slot;
  Player* player;
  Vec3* playerPos;
  bool32 registered;
  s32 i;
  u32 argv[8];
  ScriptArgs sa;

  player = gPlayerPtr[0];
  playerPos = NULL;
  if (player != NULL) {
    playerPos = &player->unk_24.pos;
  }
  registered = FALSE;
  hazard = p->hazards;
  for (i = 0; i < p->count; i++, hazard++) {
    if (p->activeMask & (1 << i)) {
      if (hazard->hp <= 0) {
        if (hazard->scriptId != 0) {
          argv[0] = hazard->id;
          argv[1] = hazard->pos.x;
          argv[2] = hazard->pos.y;
          argv[3] = hazard->pos.z;
          argv[4] = hazard->scriptArgs[0];
          argv[5] = hazard->scriptArgs[1];
          argv[6] = hazard->scriptArgs[2];
          argv[7] = hazard->scriptArgs[3];
          sa.argc = 8;
          sa.argv = argv;
          Script_ExecById(hazard->scriptId, &sa);
          hazard->scriptId = 0;
        }
        Hazard_EmitBreakEffect(hazard);
        Hazard_Remove(p, hazard, i);
      } else {
        if (hazard->damageTimer != 0) {
          SetHitboxFlags(&hazard->hitbox, HBFLAG_UNK_2);
          if (--hazard->damageTimer == 0) {
            Video_SetAuxSpritePltt(&hazard->sprite, 0x11B);
          }
        } else {
          ClearHitboxFlags(&hazard->hitbox, HBFLAG_UNK_2);
        }
        if (playerPos != NULL && !registered) {
          if (Hazard_ContainsPoint(hazard, playerPos)) {
            Hitbox_SetPos(&p->hitbox, &hazard->pos, 0);
            Hitbox_Register(&p->hitbox);
            registered = TRUE;
          }
        }
      }
    }
  }
  return 0;
#else
  INCFUNC("asm/func/HazardManager_Update.inc");
#endif
}

s32 HazardManager_Destroy(HazardManager* p) {
  Hazard* hazard;
  s32 i;

  if (p->hazards != NULL) {
    hazard = p->hazards;
    for (i = 0; i < p->count; i++, hazard++) {
      if (p->activeMask & (1 << i)) {
        Hazard_Remove(p, hazard, i);
      }
    }
    Free(p->hazards);
    p->hazards = NULL;
  }
  gHazardManager = NULL;
  return 0;
}

// プレイヤーへの攻撃判定を1個だけ用意し、Hazard の配列を確保する
s32 HazardManager_Init(HazardManager* p) {
  HitboxData* hitbox;
  Hazard* hazards;
  s32 power;
  s32 unk_40;
  s32 unk_44;
  Vec3 halfSize, offset;

  gHazardManager = p;
  p->count = VM_GetKeywordValue('m', 8);
  p->activeMask = 0;
  power = VM_GetKeywordValue('p', 5);
  unk_40 = VM_GetKeywordValue('f', 10);
  unk_44 = VM_GetKeywordValue('i', 10);
  hitbox = &p->hitbox;
  halfSize.x = 0xA4, halfSize.y = 0x80, halfSize.z = 0xA4;
  offset.x = 0, offset.y = 0x80, offset.z = 0;
  Hitbox_Init(hitbox, 0, HBFLAG_UNK_13 | HBFLAG_UNK_0, 0, 0x10, &halfSize, &offset);
  Hitbox_SetHandler(hitbox, NULL, p);
  Hitbox_SetAttack(hitbox, power, unk_40, 0, 0, unk_44);
  hazards = Malloc(p->count * sizeof(Hazard));
  p->hazards = hazards;
  if (hazards == NULL) {
    return -1;
  }
  ClearMemory(hazards, p->count * sizeof(Hazard));
  return 0;
}

HazardManager* HazardManager_Create(u32 _) {
  HazardManager* p;

  if (gHazardManager != NULL) {
    return gHazardManager;
  }
  p = CreateEntity(ENTITY_UNK_8, sizeof(HazardManager));
  if (p != NULL) {
    SetEntityRoutine(p, HazardManager_Update, HazardManager_Destroy);
    if (HazardManager_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

// 空いている hazards の添字を返す。空きがなければ -1
s32 HazardManager_FindFreeSlot(HazardManager* p) {
  s32 i;

  for (i = 0; i < p->count; i++) {
    if (!(p->activeMask & (1 << i))) {
      return i;
    }
  }
  return -1;
}

s32 FUN_08241574(Vec3* pos);
void FUN_08234270(MapTileOverride* p, s32 tileIdx, s32 param_3, s32 height, s32 param_5, s32 param_6);

// 空きスロットに Hazard を1個置く。当たり判定・地形の高さ・スプライトを用意して使用中にする
NON_MATCH s32 HazardManager_Spawn(Vec3* pos, s32 id, s32 hp, s32 metaspriteIdx, s32 requireArea, s32 scriptId, s32* args) {
#ifdef NONMATCHING_C
  HazardManager* p = gHazardManager;
  Hazard* hazard;
  HitboxData* hitbox;
  AuxSpriteGfx* sprite;
  Vec3* hazardPos;
  Vec3* min;
  Vec3* max;
  MapTileOverride* tileOverride;
  u8* tile;
  s32 bx, bz, idx;
  s32 h;
  s32 i;
  Vec3 size, offset;

  if (p == NULL) {
    return -1;
  }
  slot = HazardManager_FindFreeSlot(p);
  if (slot < 0) {
    return -1;
  }
  hazard = &p->hazards[slot];
  hazard->id = id;
  hazard->hp = hp;
  if (requireArea != 0) {
    hazard->areaId = FUN_08241574(pos);
  } else {
    hazard->areaId = 0;
  }
  if (hazard->areaId < 0) {
    return -1;
  }
  hazard->scriptId = scriptId;
  hazardPos = &hazard->pos;
  hitbox = &hazard->hitbox;
  min = &hazard->min;
  max = &hazard->max;
  tileOverride = &hazard->tileOverride;
  sprite = &hazard->sprite;
  for (i = 0; i < 4; i++) {
    hazard->scriptArgs[i] = args[i];
  }
  hazard->pos = *pos;
  size.x = 0x82, size.y = 0x80, size.z = 0x82;
  offset.x = 0, offset.y = 0x80, offset.z = 0;
  Hitbox_Init(hitbox, hazard->id, HBFLAG_UNK_14 | HBFLAG_UNK_0, 0, 0x10, &size, &offset);
  Hitbox_SetPos(hitbox, hazardPos, 0);
  Hitbox_SetPowerAndAttributes(hitbox, 0, 0, 0);
  Hitbox_SetHandler(hitbox, Hazard_OnHit, hazard);
  Hitbox_Register(hitbox);
  hazard->min.x = -0xA4;
  hazard->min.y = -0x80;
  hazard->min.z = -0xA4;
  hazard->min.x += hazard->pos.x;
  min->y += hazardPos->y;
  min->z += hazardPos->z;
  hazard->max.x = 0xA4;
  hazard->max.y = 0x80;
  hazard->max.z = 0xA4;
  hazard->max.x += hazard->pos.x;
  max->y += hazardPos->y;
  max->z += hazardPos->z;
  bx = hazard->pos.x >> 8;
  bz = hazardPos->z >> 8;
  if (bx < 0 || bz < 0 || (u32)bx >= (u32)gMapBlockW || (u32)bz >= (u32)gMapBlockH) {
    idx = 0;
  } else {
    idx = gCollisionMap->rowOffsets[bz] + bx;
  }
  tile = (u8*)FUN_08234224(idx, 1);
  if (tile != NULL) {
    tile += 4;
  } else {
    tile = (u8*)&gCollisionMap->tiledata->tiles[idx];
  }
  h = *tile & 0xF;
  if (h < 0xF) {
    h++;
  }
  FUN_08234270(tileOverride, idx, 0, h, 0xFF, 2);
  if (!Video_GetAuxSprite(sprite, 0x4B3)) {
    return -1;
  }
  AuxSprite_Add(&hazard->node, sprite, 0);
  hazard->node.metaspriteIdx = metaspriteIdx;
  hazard->node.pos = hazard->pos;
  p->activeMask |= 1 << slot;
#else
  INCFUNC("asm/func/HazardManager_Spawn.inc");
#endif
}
