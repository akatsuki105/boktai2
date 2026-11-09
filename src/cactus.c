#include "collision_map.h"
#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "malloc.h"
#include "map_inline.h"
#include "player.h"
#include "sound.h"
#include "sprite.h"
#include "vm.h"

// サボテン1つ (破壊可能, 触れるとダメージ)
typedef struct {
  u16 id;                        // 0x00, '.n', hurtbox の id になる
  s16 hp;                        // 0x02, '.l=100', Cactus_OnHurt が HitboxData.damage の分だけ減らし 0 以下で破壊される
  ZoneID32 zoneID;               // 0x04, '.m' が 0 以外のときだけ GetZoneAt(pos) の戻り値が入る,負なら生成を中止する,書くだけで読み手はいない
  u16 scriptId;                  // 0x08, '.b', 破壊時に VM_ExecByID へ渡してから 0 に戻す
  u8 damageTimer;                // 0x0A, 被弾時に 10 がセットされ毎フレーム減る,0 でない間だけ hurtbox.flags に HBFLAG_HIDDEN が立つ
  u8 unk_0b;                     // 0x0B, padding?
  s16 scriptArgs[4];             // 0x0C, '.a' の4要素, 破壊時の VM_ExecByID の argv[4..7] になる
  Vec3 pos;                      // 0x14, SpawnCactus の第1引数のコピー
  Vec3 min;                      // 0x1C, pos - (0xA4, 0x80, 0xA4)
  Vec3 max;                      // 0x24, pos + (0xA4, 0x80, 0xA4), プレイヤーが min..max に入ると CactusManager.hitbox が攻撃側として登録される
  HitboxData hurtbox;            // 0x2C, 被弾用 (flags 0x4001), fn は Cactus_OnHurt で owner はこの Cactus
  MapTileOverride tileOverride;  // 0x7C, 足元のタイルの高さを +1 して通れなくする
  AuxSprite sprite;              // 0x8C
  AuxSpriteGfx gfx;              // 0xB8, SPRITE_CACTUS
} Cactus;
static_assert(sizeof(Cactus) == 212);

// サボテンの管理構造体
// 攻撃判定は Cactus ごとには持たず、プレイヤーが近付いた Cactus の位置へ hitbox を移して1フレームだけ登録する
typedef struct {
  Entity e;           // 0x00, ENTITY_UNK_8
  u8 count;           // 0x18, '.m=8'
  u8 unk_19[3];       // 0x19, padding?
  u32 activeMask;     // 0x1C, bit i が list[i] 使用中
  Cactus* list;       // 0x20, Malloc(count * sizeof(Cactus))
  HitboxData hitbox;  // 0x24, プレイヤーへの攻撃判定 (flags 0x2001), 威力は '.p'/'.f'/'.i'
} CactusManager;
static_assert(sizeof(CactusManager) == 116);

COMMON_DATA CactusManager* gCactusManager = NULL;  // 0x03002B34

static inline bool8 IsInBox(Vec3* pos, Vec3* min, Vec3* max) {
  if (pos->x >= min->x && pos->x <= max->x && pos->y >= min->y && pos->y <= max->y && pos->z >= min->z && pos->z <= max->z) {
    return TRUE;
  }
  return FALSE;
}

s32 FUN_08014da0(s32 count, s32 kind, Vec3* pos, s32 speed, s32 lifetimeBase, s32 lifetimeRand, s32 speedBase, s32 speedRand, s32 angleBase, s32 angleRand, s32 velYBase, s32 velYRand);

// 被弾時に呼ばれる,hp を削り、0 以下になったら破壊待ちにし、そうでなければ点滅させる
void Cactus_OnHurt(HitboxData* a, HitboxData* b, Cactus* owner) {
  Cactus* p = owner;  // これを入れないと一致しない, でも不自然なので後で自然な書き方に直せるか試す
  Hitbox_ApplyDamage(a, b);
  if (b->damage != 0) {
    p->hp -= b->damage;
    if (p->hp <= 0) {
      p->hp = 0;
    } else {
      p->damageTimer = 10;
      Video_SetAuxSpritePltt(&p->gfx, OBP_WHITE_306);
      if (!Hitbox_HasWeakness(a, HBATTR_FLAME)) PlaySound_082406e0(SE_ENEMY_DAMAGED);
    }
    b->damage = 0;
  }
}

// Cactus 1個を当たり判定・描画・地形の各リストから外し、スロットを空きに戻す
s32 Cactus_Remove(CactusManager* p, Cactus* cactus, u32 idx) {
  Hitbox_Unregister(&cactus->hurtbox);
  AuxSprite_Remove(&cactus->sprite);
  Map_RemoveTileOverride(&cactus->tileOverride);
  p->activeMask &= ~(1 << idx);
}

// 破壊音を鳴らし、破片のパーティクルを2種類まき散らす
void Cactus_EmitBreakEffect(Cactus* p) {
  PlaySound_082406e0(SE_330);
  FUN_08014da0(3, 3, &p->pos, 0x3C, 0x1E, 0x10, 8, 8, 0, 0x100, 0x18, 0x10);
  FUN_08014da0(8, 7, &p->pos, 0x3C, 0x1E, 0x16, 8, 8, 0, 0x100, 0x18, 0x10);
}

// hp が尽きた Cactus を片付け、生きているものは点滅を進めつつ、プレイヤーが範囲に入った最初の1個に攻撃判定を置く
s32 CactusManager_Update(CactusManager* p) {
  Player* player = gPlayerPtr[0];
  Vec3* playerPos = NULL;
  bool32 attacked;
  Cactus* cactus;
  s32 i;

  if (player != NULL) {
    playerPos = &player->mover.pos;
  }

  attacked = FALSE;
  cactus = p->list;
  for (i = 0; i < p->count; i++, cactus++) {
    if (!(p->activeMask & (1 << i))) {
      continue;
    }

    if (cactus->hp <= 0) {
      if (cactus->scriptId != 0) {
        u32 argv[8];
        ScriptArgs args;

        argv[0] = cactus->id;
        argv[1] = cactus->pos.x;
        argv[2] = cactus->pos.y;
        argv[3] = cactus->pos.z;
        argv[4] = cactus->scriptArgs[0];
        argv[5] = cactus->scriptArgs[1];
        argv[6] = cactus->scriptArgs[2];
        argv[7] = cactus->scriptArgs[3];
        args.argc = 8;
        args.argv = argv;
        VM_ExecByID(cactus->scriptId, &args);
        cactus->scriptId = 0;
      }
      Cactus_EmitBreakEffect(cactus);
      Cactus_Remove(p, cactus, i);
      continue;
    }

    if (cactus->damageTimer != 0) {
      cactus->hurtbox.flags |= HBFLAG_HIDDEN;
      if (--cactus->damageTimer == 0) {
        Video_SetAuxSpritePltt(&cactus->gfx, 283);
      }
    } else {
      Hitbox_ClearFlags(&cactus->hurtbox, HBFLAG_HIDDEN);
    }

    if (playerPos != NULL && !attacked && IsInBox(playerPos, &cactus->min, &cactus->max)) {
      Hitbox_SetPos(&p->hitbox, &cactus->pos, 0);
      Hitbox_Register(&p->hitbox);
      attacked = TRUE;
    }
  }

  return 0;
}

s32 CactusManager_Destroy(CactusManager* p) {
  Cactus* cactus;
  s32 i;

  if (p->list != NULL) {
    cactus = p->list;
    for (i = 0; i < p->count; i++, cactus++) {
      if (p->activeMask & (1 << i)) {
        Cactus_Remove(p, cactus, i);
      }
    }
    Free(p->list);
    p->list = NULL;
  }
  gCactusManager = NULL;
  return 0;
}

// プレイヤーへの攻撃判定を1個だけ用意し、 Cactus の配列を確保する
s32 CactusManager_Init(CactusManager* p) {
  HitboxData* hitbox;
  Cactus* list;
  s32 power;
  s32 knockback;
  s32 iframes;
  Vec3 halfSize, offset;

  gCactusManager = p;
  p->count = VM_GetNamedArgValue('m', 8);
  p->activeMask = 0;
  power = VM_GetNamedArgValue('p', 5);
  knockback = VM_GetNamedArgValue('f', 10);
  iframes = VM_GetNamedArgValue('i', 10);
  hitbox = &p->hitbox;
  VEC3_SET(halfSize, Q8(0.641), Q8(0.5), Q8(0.641));
  VEC3_SET(offset, 0, Q8(0.5), 0);
  Hitbox_Init(hitbox, 0, HBFLAG_HITBOX | HBFLAG_UNK_0, 0, 0x10, &halfSize, &offset);
  Hitbox_SetHandler(hitbox, NULL, p);
  Hitbox_SetAttack(hitbox, power, knockback, 0, 0, iframes);
  list = Malloc(p->count * sizeof(Cactus));
  p->list = list;
  if (list == NULL) {
    return -1;
  }
  ClearMemory(list, p->count * sizeof(Cactus));
  return 0;
}

// 0xAA65
CactusManager* CactusManager_Create(u32 _) {
  CactusManager* p;

  if (gCactusManager != NULL) {
    return gCactusManager;
  }
  p = CreateEntity(ENTITY_UNK_8, sizeof(CactusManager));
  if (p != NULL) {
    SetEntityRoutine(p, CactusManager_Update, CactusManager_Destroy);
    if (CactusManager_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

// 空いている list の添字を返す,空きがなければ -1
s32 CactusManager_FindFreeSlot(CactusManager* p) {
  s32 i;

  for (i = 0; i < p->count; i++) {
    if (!(p->activeMask & (1 << i))) {
      return i;
    }
  }
  return -1;
}

// 空きスロットに Cactus を1個置く,当たり判定・地形の高さ・スプライトを用意して使用中にする
// 残差は r4/r5 の入れ替えのみ (248/247), 原典は &offset をポインタ群と一緒にループ前で r4 に作るため cactus が r5 に回る
// Vec3* ofs = &offset をポインタ群に足すと r4/r5 は揃うが p が退避されて悪化, 宣言順でスタック位置は一致済み
NON_MATCH s32 SpawnCactus(Vec3* pos, s32 id, s32 hp, s32 poseIdx, s32 requireArea, s32 scriptId, s32* args) {
#ifdef NONMATCHING_C
  CactusManager* p = gCactusManager;
  s32 slot;
  Cactus* cactus;
  Vec3* cactusPos;
  HitboxData* hurtbox;
  Vec3* min;
  Vec3* max;
  MapTileOverride* tileOverride;
  AuxSpriteGfx* gfx;
  MapTileOverride* ov;
  CollisionMapTile* tile;
  s32 idx;
  s32 height;
  s32 i;
  Vec3 size, offset;

  if (p == NULL) {
    return -1;
  }
  slot = CactusManager_FindFreeSlot(p);
  if (slot < 0) {
    return -1;
  }

  cactus = &p->list[slot];
  cactus->id = id;
  cactus->hp = hp;
  cactus->zoneID = requireArea != 0 ? GetZoneAt(pos) : 0;
  if (cactus->zoneID < 0) {
    return -1;
  }
  cactus->scriptId = scriptId;

  cactusPos = &cactus->pos;
  hurtbox = &cactus->hurtbox;
  min = &cactus->min;
  max = &cactus->max;
  tileOverride = &cactus->tileOverride;
  gfx = &cactus->gfx;

  for (i = 0; i < 4; i++) {
    cactus->scriptArgs[i] = args[i];
  }
  cactus->pos = *pos;

  VEC3_SET(size, 0x82, Q8(0.5), 0x82);
  VEC3_SET(offset, 0, Q8(0.5), 0);
  Hitbox_Init(hurtbox, cactus->id, HBFLAG_HURTBOX | HBFLAG_UNK_0, 0, HIM_4, &size, &offset);
  Hitbox_SetPos(hurtbox, cactusPos, 0);
  Hitbox_SetPowerAndAttributes(hurtbox, 0, 0, 0);
  Hitbox_SetHandler(hurtbox, Cactus_OnHurt, cactus);
  Hitbox_Register(hurtbox);

  VEC3_SET(cactus->min, -0xA4, -Q8(0.5), -0xA4);
  cactus->min.x += cactus->pos.x;
  min->y += cactusPos->y;
  min->z += cactusPos->z;
  VEC3_SET(cactus->max, 0xA4, Q8(0.5), 0xA4);
  cactus->max.x += cactus->pos.x;
  max->y += cactusPos->y;
  max->z += cactusPos->z;

  // 足元のタイルを1段高くして通れなくする
  idx = GetCollisionTileIdx(cactusPos);
  ov = Map_FindTileOverride(idx, 1);
  tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[idx];
  height = tile->heightStairs & 0xF;
  if (height < 15) {
    height++;
  }
  Map_AddTileOverride(tileOverride, idx, STAIRS_NONE, height, 0xFF, TATTR_WALL);

  if (!Video_GetAuxSprite(gfx, SPRITE_CACTUS)) {
    return -1;
  }
  AuxSprite_Add(&cactus->sprite, gfx, 0);
  cactus->sprite.poseIdx = poseIdx;
  cactus->sprite.pos = cactus->pos;
  p->activeMask |= 1 << slot;
#else
  INCFUNC("asm/func/SpawnCactus.inc");
#endif
}

// 0x2306
// 残差1命令 (119/118), '.a' 読み込みループの終了判定を原典は &args[3] とのポインタ比較で行うが, こちらは i を数え下げのカウンタとして残す
// 空なら pc をそのまま 0 として使う形でループ本体は一致, u32 i や ポインタで回す形は試済
NON_MATCH s32 Cmd_SpawnCactus(void) {
#ifdef NONMATCHING_C
  s32 id = VM_GetNamedArgValue('n', 0);
  s32 hp = VM_GetNamedArgValue('l', 100);
  s32 poseIdx = VM_GetNamedArgValue('t', 1);
  s32 requireArea = VM_GetNamedArgValue('m', 0);
  s32 scriptId = VM_GetNamedArgValue('b', 0);
  s32 args[4];
  Vec3 pos;
  s32 i;

  if (VM_SeekToNamedArg('a')) {
    for (i = 0; i < 4; i++) {
      u8* pc = VM_GetPC();

      args[i] = pc != NULL ? VM_GetValue() : (u32)pc;
    }
  } else {
    for (i = 0; i < 4; i++) {
      args[i] = 0;
    }
  }
  if (VM_SeekToNamedArg('p')) {
    pos.x = VM_GetValue();
    pos.y = VM_GetValue();
    pos.z = VM_GetValue();
  } else {
    VEC3_SET(pos, 0, 0, 0);
  }
  pos.x = (pos.x & ~0xFF) | 0x80;
  pos.z = (pos.z & ~0xFF) | 0x80;
  return SpawnCactus(&pos, id, hp, poseIdx, requireArea, scriptId, args);
#else
  INCFUNC("asm/func/Cmd_SpawnCactus.inc");
#endif
}
