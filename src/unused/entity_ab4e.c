#include "collision_map.h"
#include "emote.h"
#include "entity.h"
#include "file.h"
#include "game.h"
#include "global.h"
#include "input.h"
#include "map_inline.h"
#include "player.h"
#include "sprite.h"
#include "vec3.h"
#include "vm.h"

bool32 FUN_08018a08(void);
void Map_StepNavPath(NavAgent* agent, Vec3* pos);
void Map_ReadPathNodePos(Vec3* dst, PathNode* nodes, u8 idx);
bool8 Map_GetStepToPathNode(PathWalker* w, Vec3* pos, Vec3* out, u8* outAngle, u32 rx, u32 rz, s32 speed);

// 不使用 (Cからもスクリプトからも使用されていない)

typedef struct {
  u16 id;                 // 0x000, '.n', Mover の id, 話しかけたときのスクリプトの argv[0]
  s16 unk_2;              // 0x002, '.e'
  u8 state;               // 0x004, sEntityAB4EStateFuncs の添字
  bool8 stateEntered;     // 0x005, state を変えたときに立ち, state 関数が最初のフレームで 0 に戻す
  u8 unk_6;               // 0x006, まだ未解析
  u8 gfxIndex;            // 0x007, EntityAB4E.gfx の添字
  u8 unk_8;               // 0x008, state に入るときに 0/1 を入れる, 読むコードは見つかっていない
  bool8 active;           // 0x009, _Update / _Destroy がこれを見て処理する
  u8 unk_a;               // 0x00A, 雨で退避するとき 0, 時間帯の終わりで退避するとき 1, 読むコードは見つかっていない
  u8 baseAngle;           // 0x00B, プレイヤーに気付いたときの向き
  u8 prevState;           // 0x00C, プレイヤーに気付く前の state, 離れたらここへ戻る
  u8 unk_d[3];            // 0x00D, まだ未解析
  u32 timer;              // 0x010, state に入ってからのフレーム数
  s32 playerDistSq;       // 0x014, プレイヤーとの xz 距離の2乗
  u8 unk_18;              // 0x018, まだ未解析
  u8 dir8;                // 0x019, 向きの8方向 (Angle_ToDir8)
  u8 dir4;                // 0x01A, 向きの4方向 (Angle_ToDir4)
  u8 unk_1b;              // 0x01B, Cmd_AddEntityAB4EElem が 0 を入れる
  u16 hideTimer;          // 0x01C, 隠れてから時刻を見るまでの待ちフレーム数
  u8 unk_1e;              // 0x01E, 時間帯の終わりで退避するとき 0 を入れる
  bool8 hasSchedule;      // 0x01F, '.t' があれば 1, 時間帯を見る
  u16 pathDelay;          // 0x020, 経路の今のノードの待ちフレーム数 (PathNode.delay の下位12bit)
  u8 targetAngle;         // 0x022, 向き直る先の角度
  u8 pathDir;             // 0x023, 経路の方向転換ノードの向き (8方向, PathNode.delay の上位4bit)
  u8 startHour;           // 0x024, '.t[0]', 時間帯の始まり (時), 既定 9
  u8 startMinute;         // 0x025, '.t[1]', 同じく (分)
  u8 endHour;             // 0x026, '.t[2]', 時間帯の終わり (時), 既定 21
  u8 endMinute;           // 0x027, '.t[3]', 同じく (分)
  s8 pathIdx;             // 0x028, '.r[0]', 負なら経路なし
  s8 hidePointIdx;        // 0x029, '.E[0]', 雨や時間帯の終わりで退避する EntityAB4E.hidePoints の添字, 負なら雨では退避しない
  s8 unk_2a;              // 0x02A, '.E[1]'
  s8 unk_2b;              // 0x02B, '.E[2]'
  u8 animDir;             // 0x02C, アニメ番号に足す向き
  bool8 animXFlip;        // 0x02D, 左右反転するか
  u16 animID;             // 0x02E, MainSprite_SetAnim に渡したアニメ番号
  u16 pathParam;          // 0x030, '.r[1]', Map_InitPathWalker の第3引数
  u16 pathNodeIdx;        // 0x032, '.r[2]', 最初に向かうノード番号
  u16 unk_34;             // 0x034, '.r[3]'
  bool8 pathArrived;      // 0x036, 経路の今のノードに着いたら立つ
  bool8 talkable;         // 0x037, プレイヤーと向かい合っていれば立つ, _Update が毎フレーム 0 に戻す
  u32 arriveRange;        // 0x038, '.r[4]', 経路のノードとの x/z の差がこれ以下なら着いたとみなす
  u32 nearRange;          // 0x03C, '.P[0]', プレイヤーがこの距離 (x, z) まで近づいたら気付く
  u32 keepRange;          // 0x040, '.P[1]', 気付いたあとこの距離の外に出たら元の state へ戻る
  u32 talkDistSq;         // 0x044, talkable のときのプレイヤーとの xz 距離の2乗
  u32 talkArgs[4];        // 0x048, '.a', 話しかけたときのスクリプトの argv[4..7]
  u8 unk_58[8];           // 0x058, まだ未解析
  Mover mover;            // 0x060
  MainSprite sprite;      // 0x0A4
  ParticleShadow shadow;  // 0x104
  PathWalker pathWalker;  // 0x144, Mover_SetPath に渡す
  NavAgent navAgent;      // 0x150, 退避先や経路の先頭へナビメッシュで歩く
  bool16 emoteShown;      // 0x174, 吹き出しを出しているか
  u8 emoteKind;           // 0x176, Emote_Show の kind
  u8 emoteVariant;        // 0x177, Emote_Show の variant
  s16 emoteTimer;         // 0x178, 毎フレーム減らし, 0 になると emotePeriod に戻す
  s16 emotePeriod;        // 0x17A, emoteTimer の初期値
  Emote* emote;           // 0x17C, Emote_Show の戻り値
} EntityAB4EElem;
static_assert(sizeof(EntityAB4EElem) == 384);

typedef struct {
  Entity e;                  // 0x0000, ENTITY_UNK_5
  Vec3* playerPos;           // 0x0018, &gPlayerPtr[0]->mover.pos
  u16 talkScriptID;          // 0x001C, '.t', 話しかけたとき VM_ExecByID で実行する
  bool8 minuteChanged;       // 0x001E, 分が変わったフレームだけ立つ
  u8 prevMinute;             // 0x001F, 前フレームの Time_GetMinute
  u8 hour;                   // 0x0020, Time_GetHour
  u8 minute;                 // 0x0021, Time_GetMinute
  u8 unk_22;                 // 0x0022, まだ未解析
  u8 hidePointCount;         // 0x0023, hidePoints の要素数
  u8 count2;                 // 0x0024, points2 の要素数
  bool8 raining;             // 0x0025, FUN_08018a08 (雨が降っているか)
  u8 unk_26[2];              // 0x0026, まだ未解析
  u32 frameCount;            // 0x0028, _Update が毎フレーム +1, 下位4bit が要素の添字と一致するフレームだけ要素が時刻と雨を見る
  Vec3 hidePoints[16];       // 0x002C, '.h', 要素が退避して隠れる場所
  Vec3 points2[16];          // 0x00AC, '.s'
  EntityAB4EElem elems[16];  // 0x012C
  MainSpriteGfx gfx[8];      // 0x192C, '.d' の1つ目の ID から8個とも作る
  Player* player;            // 0x1A2C, gPlayerPtr[0]
} EntityAB4E;
static_assert(sizeof(EntityAB4E) == 6704);

static EntityAB4E* gEntityAB4E;  // 0x030000C0

// state を差し替えて, 次の呼び出しを初回扱いにする
static inline void EntityAB4EElem_SetState(EntityAB4EElem* elem, u32 state) {
  elem->state = state;
  elem->stateEntered = TRUE;
  elem->timer = 0;
}

// 立っているときの8方向のアニメの先頭, gfxIndex で引く
const u16 sEntityAB4EStandAnims[8] = {0, 16, 0, 0, 0, 0, 0, 0};  // 0x085AB404

// 歩くときの4方向のアニメの先頭, gfxIndex で引く
const u16 sEntityAB4EWalkAnims[8] = {5, 21, 0, 0, 0, 0, 0, 0};  // 0x085AB414

// 走るときの4方向のアニメの先頭, gfxIndex で引く
const u16 sEntityAB4ERunAnims[8] = {7, 23, 0, 0, 0, 0, 0, 0};  // 0x085AB424

// 2点が x/z は range 未満, y は 0xFF 以内に収まっているかを返す
static inline bool32 EntityAB4E_IsNear(Vec3* a, Vec3* b, s32 range) {
  if (abs(b->x - a->x) < range) {
    if (abs(b->y - a->y) <= 0xFF) {
      if (abs(b->z - a->z) < range) {
        return TRUE;
      }
    }
  }
  return FALSE;
}

// 向きの4方向から向きの番号と左右反転を決めてアニメを設定する
static inline void EntityAB4EElem_PlayDir4Anim(EntityAB4EElem* elem, MainSprite* sprite, MainSpriteGfx* gfx, u32 base, u32 playMode, u32 flags) {
  elem->dir4 = Angle_ToDir4(elem->mover.angle);
  if (elem->dir4 == 1 || elem->dir4 == 2) {
    elem->animDir = 1;
  } else {
    elem->animDir = 0;
  }
  if (elem->dir4 > 1) {
    elem->animXFlip = TRUE;
  } else {
    elem->animXFlip = FALSE;
  }
  elem->animID = elem->animDir + base;
  MainSprite_SetAnim(sprite, gfx, elem->animID, playMode, flags);
  if (elem->animXFlip) {
    sprite->flags |= SPRFLAG_XFLIP;
  } else {
    sprite->flags &= ~SPRFLAG_XFLIP;
  }
}

// 向きの8方向から anims の向きの番号と左右反転を決めてアニメを設定する
static inline void EntityAB4EElem_PlayDir8Anim(EntityAB4EElem* elem, MainSprite* sprite, MainSpriteGfx* gfx, u32 base, u32 playMode, u32 flags) {
  elem->dir8 = Angle_ToDir8(elem->mover.angle);
  if (elem->dir8 == 5 || elem->dir8 == 6 || elem->dir8 == 7) {
    elem->animDir = 8 - elem->dir8;
    elem->animXFlip = TRUE;
  } else {
    elem->animDir = elem->dir8;
    elem->animXFlip = FALSE;
  }
  elem->animID = base + elem->animDir;
  MainSprite_SetAnim(sprite, gfx, elem->animID, playMode, flags);
  if (elem->animXFlip) {
    sprite->flags |= SPRFLAG_XFLIP;
  } else {
    sprite->flags &= ~SPRFLAG_XFLIP;
  }
}

// 未使用の要素を先頭から探す
EntityAB4EElem* EntityAB4E_FindFreeElem(EntityAB4E* p) {
  EntityAB4EElem* elem = p->elems;
  s32 i;

  for (i = 0; i < 16; i++, elem++) {
    if (!elem->active) {
      return elem;
    }
  }

  return NULL;
}

// 要素の Mover / 影 / スプライトを外して非アクティブにする
s32 FUN_080452f4(EntityAB4E* p, EntityAB4EElem* elem, s32 index) {
  Mover* mover;

  if (!elem->active) {
    return -1;
  }

  mover = &elem->mover;
  FUN_08002a58(mover);
  Mover_Unlink(mover);
  ParticleShadow_Remove(&elem->shadow);
  MainSprite_Remove(&elem->sprite);
  elem->active = FALSE;
}

// 経路のノードの指示を読んで待ち時間を入れ, 待つ / 向き直る / 歩くの state へ移る
void EntityAB4EElem_ApplyPathNode(EntityAB4EElem* elem, PathNode* node) {
  s32 kind = node->command >> 4;

  elem->pathDelay = node->delay & 0xFFF;
  switch (kind) {
    case 0: {
      EntityAB4EElem_SetState(elem, 0);
      break;
    }
    case 1: {
      elem->pathDir = node->delay >> 12;
      if (Angle_ToDir8(elem->mover.angle) == elem->pathDir) {
        EntityAB4EElem_SetState(elem, 0);
      } else {
        EntityAB4EElem_SetState(elem, 1);
      }
      break;
    }
    case 2: {
      EntityAB4EElem_SetState(elem, 2);
      break;
    }
    default: {
      EntityAB4EElem_SetState(elem, 0);
      break;
    }
  }
}

// 経路の今のノードに着いていればノードの指示に従い, 着いていなければ歩く state 2 へ移る
void EntityAB4EElem_CheckPathNode(EntityAB4EElem* elem) {
  PathWalker* walker = &elem->pathWalker;
  PathNode* node = walker->node;

  if (abs(node->x - elem->mover.pos.x) <= elem->arriveRange && abs(node->y - elem->mover.pos.z) <= elem->arriveRange) {
    EntityAB4EElem_ApplyPathNode(elem, node);
  } else {
    EntityAB4EElem_SetState(elem, 2);
  }
}

// 向かい合っている要素のうち一番近いものに話しかける, 全員の吹き出しを閉じて talkScriptID を実行し 1 を返す
s32 EntityAB4E_Talk(EntityAB4E* p) {
  u32 minDist = 1000000;
  EntityAB4EElem* elem = p->elems;
  EntityAB4EElem* nearest = NULL;
  s32 i;

  for (i = 0; i < 16; i++, elem++) {
    if (elem->active && elem->talkable && elem->talkDistSq < minDist) {
      minDist = elem->talkDistSq;
      nearest = elem;
    }
  }

  if (nearest != NULL && p->talkScriptID != 0) {
    u32 argv[8];
    ScriptArgs args;

    elem = p->elems;
    for (i = 0; i < 16; i++, elem++) {
      if (elem->active) {
        elem->emote = Emote_Show(elem->emote, &elem->mover, elem->emoteKind, 0x7F, (u16*)&elem->emoteTimer, elem->emotePeriod, 0, 100);
        elem->emoteShown = 0;
      }
    }

    argv[0] = nearest->id;
    argv[1] = nearest->sprite.pos.x;
    argv[2] = nearest->sprite.pos.y;
    argv[3] = nearest->sprite.pos.z;
    for (i = 0; i < 4; i++) {
      argv[4 + i] = nearest->talkArgs[i];
    }
    args.argc = 8;
    args.argv = argv;
    VM_ExecByID(p->talkScriptID, &args);
    return 1;
  }
  return 0;
}

// kind (NPC_ShowEmote と同じ番号) から, 頭上に出し続ける吹き出しの種類を決める
void EntityAB4E_SetEmote(EntityAB4E* p, EntityAB4EElem* elem, s32 kind) {
  switch (kind) {
    case 0: {
      elem->emoteKind = 0;
      elem->emoteVariant = 1;
      break;
    }
    case 2: {
      elem->emoteKind = 0;
      elem->emoteVariant = 0;
      break;
    }
    case 3: {
      elem->emoteKind = 0;
      elem->emoteVariant = 2;
      break;
    }
    case 4: {
      elem->emoteKind = 1;
      elem->emoteVariant = 0;
      break;
    }
    case 5: {
      elem->emoteKind = 3;
      elem->emoteVariant = 0;
      break;
    }
    case 6: {
      elem->emoteKind = 5;
      elem->emoteVariant = 0;
      break;
    }
    case 7: {
      elem->emoteKind = 4;
      elem->emoteVariant = 0;
      break;
    }
    case 8: {
      elem->emoteVariant = 0x7F;
      break;
    }
  }
}

// 経路のノードで待つ, 雨や時間帯の終わりで退避へ, プレイヤーが近づいたら state 3 へ, 待ち時間が切れたら次のノードへ進む
// 残差2か所, 雨で state 5 にするときの timer の 0 を原典は r0 で作る (こちらは r1 を先に作る), nearRange の ldr が原典は playerPos の後
// Tier A-C は試済 (IsNear の bool8/bool32/&&/入れ子, ラッパー inline は効かず), 未: SetState と hideTimer の書き順
NON_MATCH s32 EntityAB4E_StateWait(EntityAB4E* p, EntityAB4EElem* elem, s32 index) {
#ifdef NONMATCHING_C
  PathWalker* walker = &elem->pathWalker;
  Vec3* pos = &elem->sprite.pos;

  if (elem->stateEntered) {
    elem->stateEntered = FALSE;
    EntityAB4EElem_PlayDir8Anim(elem, &elem->sprite, &p->gfx[elem->gfxIndex], sEntityAB4EStandAnims[elem->gfxIndex], PLAYMODE_LOOP, MAIN_ANIM_FORCE_POSE);
    elem->unk_8 = 0;
  } else {
    EntityAB4EElem_PlayDir8Anim(elem, &elem->sprite, &p->gfx[elem->gfxIndex], sEntityAB4EStandAnims[elem->gfxIndex], PLAYMODE_LOOP, MAIN_ANIM_KEEP_FRAME);
  }

  if ((p->frameCount & 0xF) == index) {
    if (elem->hidePointIdx >= 0 && p->raining) {
      EntityAB4EElem_SetState(elem, 5);
      elem->hideTimer = 300;
      return 0;
    }
    if (elem->hasSchedule && p->minuteChanged) {
      if ((p->hour == elem->endHour && p->minute >= elem->endMinute) || (p->hour - 1 == elem->endHour && p->minute <= elem->endMinute)) {
        elem->unk_1e = 0;
        EntityAB4EElem_SetState(elem, 6);
        return 0;
      }
    }
  }

  if (EntityAB4E_IsNear(pos, p->playerPos, elem->nearRange)) {
    elem->prevState = elem->state;
    EntityAB4EElem_SetState(elem, 3);
    return 0;
  }
  if (elem->pathIdx >= 0) {
    if (elem->pathDelay == 0) {
      Map_AdvancePathWalker(walker);
      EntityAB4EElem_CheckPathNode(elem);
    } else {
      elem->pathDelay--;
    }
  }
#else
  INCFUNC("asm/func/EntityAB4E_StateWait.inc");
#endif
}

// 経路の方向転換ノードの向き pathDir へ向き直り, 向いたら待つ state 0 へ, プレイヤーが近づいたら state 3 へ
// 残差1か所, 雨で state 5 にするときの timer の 0 を原典は r0 で直前に作る (EntityAB4E_StateWait と同じ残差)
// Tier A-C は一部試済 (SetState を展開して書く, angle をポインタ/直接, IsNear を直接), 未: 退避判定の inline 化
NON_MATCH s32 EntityAB4E_StateTurn(EntityAB4E* p, EntityAB4EElem* elem, s32 index) {
#ifdef NONMATCHING_C
  Vec3* pos = &elem->sprite.pos;
  s8 diff;

  if (elem->stateEntered) {
    elem->stateEntered = FALSE;
    EntityAB4EElem_PlayDir8Anim(elem, &elem->sprite, &p->gfx[elem->gfxIndex], sEntityAB4EStandAnims[elem->gfxIndex], PLAYMODE_LOOP, MAIN_ANIM_FORCE_POSE);
    elem->unk_8 = 0;
    elem->targetAngle = Angle_FromDir8(elem->pathDir);
  } else {
    EntityAB4EElem_PlayDir8Anim(elem, &elem->sprite, &p->gfx[elem->gfxIndex], sEntityAB4EStandAnims[elem->gfxIndex], PLAYMODE_LOOP, MAIN_ANIM_KEEP_FRAME);
  }

  diff = elem->targetAngle - elem->mover.angle;
  if (diff > 8) {
    elem->mover.angle += 8;
  } else if (diff < -8) {
    elem->mover.angle -= 8;
  } else {
    elem->mover.angle += diff;
  }

  if ((p->frameCount & 0xF) == index) {
    if (elem->hidePointIdx >= 0 && p->raining) {
      EntityAB4EElem_SetState(elem, 5);
      elem->hideTimer = 300;
      return 0;
    }
    if (elem->hasSchedule && p->minuteChanged) {
      if ((p->hour == elem->endHour && p->minute >= elem->endMinute) || (p->hour - 1 == elem->endHour && p->minute <= elem->endMinute)) {
        elem->unk_1e = 0;
        EntityAB4EElem_SetState(elem, 6);
        return 0;
      }
    }
  }

  if (EntityAB4E_IsNear(pos, p->playerPos, elem->nearRange)) {
    elem->prevState = 0;
    EntityAB4EElem_SetState(elem, 3);
    return 0;
  }
  if (Angle_ToDir8(elem->mover.angle) == elem->pathDir) {
    EntityAB4EElem_SetState(elem, 0);
    return 0;
  }
#else
  INCFUNC("asm/func/EntityAB4E_StateTurn.inc");
#endif
}

// 経路の今のノードへ歩き, 着いてアニメが終わったら待つ state 0 へ, プレイヤーが近づいたら state 3 へ
// 残差はレジスタ割当, 原典は p を r8 に置き sprite のポインタを sp に退避する
// 早めに打ち切り, 試済: 2回目の PlayDir4Anim に &elem->sprite を渡す
NON_MATCH s32 EntityAB4E_StateWalk(EntityAB4E* p, EntityAB4EElem* elem, s32 index) {
#ifdef NONMATCHING_C
  Mover* mover = &elem->mover;
  PathWalker* walker = &elem->pathWalker;
  Vec3* pos = &elem->mover.pos;
  MainSprite* sprite = &elem->sprite;

  if (elem->stateEntered) {
    elem->stateEntered = FALSE;
    mover->angle = ArcTan2_8(walker->node->x - pos->x, walker->node->y - pos->z);
    EntityAB4EElem_PlayDir4Anim(elem, sprite, &p->gfx[elem->gfxIndex], sEntityAB4EWalkAnims[elem->gfxIndex], PLAYMODE_LOOP, MAIN_ANIM_FORCE_POSE);
    elem->unk_8 = 0;
    elem->pathArrived = FALSE;
  }

  if ((p->frameCount & 0xF) == index) {
    if (elem->hidePointIdx >= 0 && p->raining) {
      EntityAB4EElem_SetState(elem, 5);
      elem->hideTimer = 300;
      return 0;
    }
    if (elem->hasSchedule && p->minuteChanged) {
      if ((p->hour == elem->endHour && p->minute >= elem->endMinute) || (p->hour - 1 == elem->endHour && p->minute <= elem->endMinute)) {
        elem->unk_1e = 0;
        EntityAB4EElem_SetState(elem, 6);
        return 0;
      }
    }
  }

  if (EntityAB4E_IsNear(pos, p->playerPos, elem->nearRange)) {
    elem->prevState = elem->state;
    EntityAB4EElem_SetState(elem, 3);
    return 0;
  }

  if (!elem->pathArrived) {
    if (sprite->animEvents & MAIN_ANIM_EVENT_ADVANCED) {
      s32 speed = (sprite->animCmdIdx & 1) ? 16 : 32;

      elem->pathArrived = Map_GetStepToPathNode(walker, &mover->pos, &mover->delta, &mover->angle, 40, 40, speed);
    }
  }
  if (elem->pathArrived && (sprite->animEvents & MAIN_ANIM_EVENT_ENDED)) {
    EntityAB4EElem_SetState(elem, 0);
    return 0;
  }
  EntityAB4EElem_PlayDir4Anim(elem, &elem->sprite, &p->gfx[elem->gfxIndex], sEntityAB4EWalkAnims[elem->gfxIndex], PLAYMODE_LOOP, MAIN_ANIM_KEEP_FRAME);
#else
  INCFUNC("asm/func/EntityAB4E_StateWalk.inc");
#endif
}

// プレイヤーの方へ向き直り, 向かい合っていれば話しかけられる印を立てる, プレイヤーが離れたら元の state へ戻る
// 484/486命令, 流れは一致, 残差は雨で state 5 にする所の 0 (StateWait と同じ) とレジスタ割当
// 早めに打ち切り, 試済: 最後の距離判定を分岐ごとに書く, 話しかけ判定の値を先に作る (65 → 27 hunk)
NON_MATCH s32 EntityAB4E_StateNotice(EntityAB4E* p, EntityAB4EElem* elem, s32 index) {
#ifdef NONMATCHING_C
  Vec3* pos = &elem->sprite.pos;
  u8 playerAngle = p->player->mover.angle;
  s32 dx = p->playerPos->x - pos->x;
  s32 dz = p->playerPos->z - pos->z;
  s8 diff;

  elem->playerDistSq = dx * dx + dz * dz;
  diff = ArcTan2_8(p->playerPos->x - pos->x, p->playerPos->z - pos->z) - elem->mover.angle;
  if (diff > 8) {
    elem->mover.angle += 8;
  } else if (diff < -8) {
    elem->mover.angle -= 8;
  } else {
    elem->mover.angle += diff;
  }

  if (elem->stateEntered) {
    elem->stateEntered = FALSE;
    EntityAB4EElem_PlayDir8Anim(elem, &elem->sprite, &p->gfx[elem->gfxIndex], sEntityAB4EStandAnims[elem->gfxIndex], PLAYMODE_LOOP, MAIN_ANIM_FORCE_POSE);
    elem->unk_8 = 1;
    elem->baseAngle = elem->mover.angle;
  } else {
    EntityAB4EElem_PlayDir8Anim(elem, &elem->sprite, &p->gfx[elem->gfxIndex], sEntityAB4EStandAnims[elem->gfxIndex], PLAYMODE_LOOP, MAIN_ANIM_KEEP_FRAME);
  }

  if ((p->frameCount & 0xF) == index) {
    if (elem->hidePointIdx >= 0 && p->raining) {
      EntityAB4EElem_SetState(elem, 5);
      elem->hideTimer = 300;
      return 0;
    }
    if (elem->hasSchedule && p->minuteChanged) {
      if ((p->hour == elem->endHour && p->minute >= elem->endMinute) || (p->hour - 1 == elem->endHour && p->minute <= elem->endMinute)) {
        elem->unk_1e = 0;
        EntityAB4EElem_SetState(elem, 6);
        return 0;
      }
    }
  }

  if (EntityAB4E_IsNear(pos, p->playerPos, elem->nearRange)) {
    s32 tx = p->playerPos->x - pos->x;
    s32 tz = p->playerPos->z - pos->z;
    u32 distSq = tx * tx + tz * tz;
    s8 toElem = playerAngle - ArcTan2_8(pos->x - p->playerPos->x, pos->z - p->playerPos->z);
    u8 faceDiff = playerAngle - (elem->mover.angle + 0x80);

    if (abs(toElem) < 0x40 && abs((s8)faceDiff) < 0x20) {
      elem->talkable = TRUE;
      elem->talkDistSq = distSq;
    }
  }

  if (abs(elem->baseAngle - elem->mover.angle) < 0x40) {
    if (!EntityAB4E_IsNear(pos, p->playerPos, elem->keepRange)) {
      EntityAB4EElem_SetState(elem, elem->prevState);
    }
  } else {
    if (!EntityAB4E_IsNear(pos, p->playerPos, elem->keepRange / 2)) {
      EntityAB4EElem_SetState(elem, elem->prevState);
    }
  }
#else
  INCFUNC("asm/func/EntityAB4E_StateNotice.inc");
#endif
}

// 驚いた吹き出しを出し, 8 フレーム経ったら退避先へ走る state 5 へ移る
s32 EntityAB4E_StateSurprised(EntityAB4E* p, EntityAB4EElem* elem, s32 index) {
  if (elem->stateEntered) {
    elem->stateEntered = FALSE;
    EntityAB4EElem_PlayDir8Anim(elem, &elem->sprite, &p->gfx[elem->gfxIndex], sEntityAB4EStandAnims[elem->gfxIndex], PLAYMODE_LOOP, MAIN_ANIM_FORCE_POSE);
    elem->unk_8 = 1;
    elem->emote = Emote_Show(elem->emote, &elem->mover, 0, 1, NULL, 0, 0, 100);
  }

  if (elem->timer > 7) {
    EntityAB4EElem_SetState(elem, 5);
  }
}

// 退避先の hidePoints[hidePointIdx] へナビメッシュで走り, 着いたら隠れる state 8 へ移る
s32 EntityAB4E_StateRunToHide(EntityAB4E* p, EntityAB4EElem* elem, s32 index) {
  Mover* mover = &elem->mover;
  NavAgent* nav = &elem->navAgent;

  if (elem->stateEntered) {
    elem->stateEntered = FALSE;
    EntityAB4EElem_PlayDir4Anim(elem, &elem->sprite, &p->gfx[elem->gfxIndex], sEntityAB4ERunAnims[elem->gfxIndex], PLAYMODE_LOOP, MAIN_ANIM_FORCE_POSE);
    elem->unk_8 = 1;
    Map_InitNavAgent(nav, &mover->pos);
    Map_TryFindNavRoute(nav, &mover->pos, &p->hidePoints[elem->hidePointIdx]);
    elem->unk_a = 0;
  }

  {
    Vec3* pos = &mover->pos;
    s32 dx = nav->waypoint.x - mover->pos.x;
    s32 dz = nav->waypoint.z - pos->z;

    if (dx * dx + dz * dz < 0x400) {
      mover->pos.x = elem->navAgent.waypoint.x;
      mover->pos.z = elem->navAgent.waypoint.z;
      EntityAB4EElem_SetState(elem, 8);
      return 0;
    } else {
      Vec3 step;

      mover->angle = ArcTan2_8(dx, dz);
      Vec3_SetPolar(&step, mover->angle, 32);
      mover->pos.x += step.x;
      mover->pos.z += step.z;
      Map_StepNavPath(nav, &mover->pos);
      EntityAB4EElem_PlayDir4Anim(elem, &elem->sprite, &p->gfx[elem->gfxIndex], sEntityAB4ERunAnims[elem->gfxIndex], PLAYMODE_LOOP, MAIN_ANIM_KEEP_FRAME);
    }
  }
}

// 姿と影を出し, 経路の先頭のノードへナビメッシュで歩いて戻る, 着いたらノードの指示に従う
// 455/456命令, 流れは一致, 残差は p と退避ローカルのレジスタ割当
// 早めに打ち切り, 試済: mover を先頭のローカルにする (55 → 36 hunk)
NON_MATCH s32 EntityAB4E_StateReappear(EntityAB4E* p, EntityAB4EElem* elem, s32 index) {
#ifdef NONMATCHING_C
  Mover* mover = &elem->mover;
  PathWalker* walker = &elem->pathWalker;
  NavAgent* nav = &elem->navAgent;
  Vec3* pos = &elem->mover.pos;

  if (elem->stateEntered) {
    Vec3 start;

    elem->stateEntered = FALSE;
    EntityAB4EElem_PlayDir4Anim(elem, &elem->sprite, &p->gfx[elem->gfxIndex], sEntityAB4EWalkAnims[elem->gfxIndex], PLAYMODE_LOOP, MAIN_ANIM_FORCE_POSE);
    elem->unk_8 = 0;
    MainSprite_Show(&elem->sprite);
    ParticleShadow_Show(&elem->shadow);
    Map_InitNavAgent(nav, &elem->mover.pos);
    Map_InitPathWalker(walker, elem->pathIdx, elem->pathParam, elem->pathNodeIdx);
    Map_ReadPathNodePos(&start, walker->node, 0);
    Map_TryFindNavRoute(nav, &elem->mover.pos, &start);
  }

  if (elem->timer > 119 && (p->frameCount & 0xF) == index) {
    if (elem->hidePointIdx >= 0 && p->raining) {
      EntityAB4EElem_SetState(elem, 5);
      elem->hideTimer = 300;
      return 0;
    }
    if (elem->hasSchedule && p->minuteChanged) {
      if ((p->hour == elem->endHour && p->minute >= elem->endMinute) || (p->hour - 1 == elem->endHour && p->minute <= elem->endMinute)) {
        elem->unk_1e = 0;
        EntityAB4EElem_SetState(elem, 6);
        return 0;
      }
    }
  }

  if (EntityAB4E_IsNear(pos, p->playerPos, elem->nearRange)) {
    elem->prevState = elem->state;
    EntityAB4EElem_SetState(elem, 3);
    return 0;
  } else {
    s32 dx = nav->waypoint.x - mover->pos.x;
    s32 dz = nav->waypoint.z - pos->z;

    if (dx * dx + dz * dz < 0x400) {
      mover->pos.x = elem->navAgent.waypoint.x;
      mover->pos.z = elem->navAgent.waypoint.z;
      EntityAB4EElem_CheckPathNode(elem);
      return 0;
    } else {
      if (elem->sprite.animEvents & MAIN_ANIM_EVENT_ADVANCED) {
        s32 speed = (elem->sprite.animCmdIdx & 1) ? 16 : 32;
        Vec3 step;

        mover->angle = ArcTan2_8(dx, dz);
        Vec3_SetPolar(&step, mover->angle, speed);
        mover->pos.x += step.x;
        mover->pos.z += step.z;
      }
      Map_StepNavPath(nav, &mover->pos);
      EntityAB4EElem_PlayDir4Anim(elem, &elem->sprite, &p->gfx[elem->gfxIndex], sEntityAB4EWalkAnims[elem->gfxIndex], PLAYMODE_LOOP, MAIN_ANIM_KEEP_FRAME);
    }
  }
#else
  INCFUNC("asm/func/EntityAB4E_StateReappear.inc");
#endif
}

// 時間帯の終わりに退避先の hidePoints[hidePointIdx] へナビメッシュで歩き, 着いたら隠れる state 8 へ移る
// 383/382命令, 原典は &mover.pos を先頭で r8 に取り, 定数 1 の共有と雨で state 5 にする所の 0 のレジスタが違う
// 早めに打ち切り, 試済: pos を先頭のローカルにする (悪化)
NON_MATCH s32 EntityAB4E_StateWalkToHide(EntityAB4E* p, EntityAB4EElem* elem, s32 index) {
#ifdef NONMATCHING_C
  Mover* mover = &elem->mover;
  NavAgent* nav = &elem->navAgent;

  if (elem->stateEntered) {
    elem->stateEntered = FALSE;
    EntityAB4EElem_PlayDir4Anim(elem, &elem->sprite, &p->gfx[elem->gfxIndex], sEntityAB4EWalkAnims[elem->gfxIndex], PLAYMODE_LOOP, MAIN_ANIM_FORCE_POSE);
    elem->unk_8 = 0;
    Map_InitNavAgent(nav, &mover->pos);
    Map_TryFindNavRoute(nav, &mover->pos, &p->hidePoints[elem->hidePointIdx]);
    elem->unk_a = 1;
  }

  if ((p->frameCount & 0xF) == index && elem->hidePointIdx >= 0 && p->raining) {
    EntityAB4EElem_SetState(elem, 5);
    elem->hideTimer = 300;
    return 0;
  }

  if (EntityAB4E_IsNear(&mover->pos, p->playerPos, elem->nearRange)) {
    elem->prevState = elem->state;
    EntityAB4EElem_SetState(elem, 3);
    return 0;
  }

  {
    Vec3* pos = &mover->pos;
    s32 dx = nav->waypoint.x - mover->pos.x;
    s32 dz = nav->waypoint.z - pos->z;

    if (dx * dx + dz * dz < 0x400) {
      mover->pos.x = elem->navAgent.waypoint.x;
      mover->pos.z = elem->navAgent.waypoint.z;
      EntityAB4EElem_SetState(elem, 8);
      return 0;
    } else {
      if (elem->sprite.animEvents & MAIN_ANIM_EVENT_ADVANCED) {
        s32 speed = (elem->sprite.animCmdIdx & 1) ? 16 : 32;
        Vec3 step;

        mover->angle = ArcTan2_8(dx, dz);
        Vec3_SetPolar(&step, mover->angle, speed);
        mover->pos.x += step.x;
        mover->pos.z += step.z;
      }
      Map_StepNavPath(nav, &mover->pos);
      EntityAB4EElem_PlayDir4Anim(elem, &elem->sprite, &p->gfx[elem->gfxIndex], sEntityAB4EWalkAnims[elem->gfxIndex], PLAYMODE_LOOP, MAIN_ANIM_KEEP_FRAME);
    }
  }
#else
  INCFUNC("asm/func/EntityAB4E_StateWalkToHide.inc");
#endif
}

// 姿と影を隠して待ち, 待ち時間が切れて雨が降っておらず時間帯の中なら現れる state 7 へ移る
s32 EntityAB4E_StateHidden(EntityAB4E* p, EntityAB4EElem* elem, s32 index) {
  if (elem->stateEntered) {
    elem->stateEntered = FALSE;
    elem->unk_8 = 0;
    MainSprite_Hide(&elem->sprite);
    ParticleShadow_Hide(&elem->shadow);
  }

  if (elem->hideTimer == 0) {
    if (!p->raining) {
      if ((p->minuteChanged && elem->hidePointIdx >= 0 && ((p->hour == elem->startHour && p->minute >= elem->startMinute) || (p->hour - 1 == elem->startHour && p->minute <= elem->startMinute))) || (p->hour == elem->startHour && p->minute >= elem->startMinute) ||
          (p->hour > elem->startHour && p->hour < elem->endHour) || (p->hour == elem->endHour && p->minute < elem->endMinute)) {
        EntityAB4EElem_SetState(elem, 7);
        return 0;
      }
    }
  } else {
    elem->hideTimer--;
  }
}

s32 (*const sEntityAB4EStateFuncs[9])(EntityAB4E*, EntityAB4EElem*, s32) = {
    EntityAB4E_StateWait,
    EntityAB4E_StateTurn,
    EntityAB4E_StateWalk,
    EntityAB4E_StateNotice,
    EntityAB4E_StateSurprised,
    EntityAB4E_StateRunToHide,
    EntityAB4E_StateWalkToHide,
    EntityAB4E_StateReappear,
    EntityAB4E_StateHidden,
};  // 0x085AB434

s32 EntityAB4E_Update(EntityAB4E* p) {
  EntityAB4EElem* elem;
  s32 i;

  p->raining = FUN_08018a08();
  p->hour = Time_GetHour();
  p->minute = Time_GetMinute();
  if (p->prevMinute != p->minute) {
    p->minuteChanged = TRUE;
  } else {
    p->minuteChanged = FALSE;
  }
  p->prevMinute = p->minute;

  if (gGameFlags & GAMEFLAG_CUTSCENE) {
    return 0;
  }

  elem = p->elems;
  for (i = 0; i < 16; i++, elem++) {
    if (elem->active) {
      Mover* mover = &elem->mover;
      MainSprite* sprite = &elem->sprite;

      elem->talkable = FALSE;
      sEntityAB4EStateFuncs[elem->state](p, elem, i);
      if (elem->state != 8) {
        Mover_ApplyMove(mover);
        mover->pos.y = TileHeightAt(&elem->mover.pos);
        sprite->pos = mover->pos;
        MainSprite_AdvanceAnim(sprite, &p->gfx[elem->gfxIndex]);
        if (!(gGameFlags & GAMEFLAG_CUTSCENE)) {
          if (elem->talkable) {
            if (elem->emoteShown == 0) {
              elem->emoteTimer = elem->emotePeriod;
              elem->emote = Emote_Show(elem->emote, &elem->mover, elem->emoteKind, elem->emoteVariant, (u16*)&elem->emoteTimer, elem->emotePeriod, 0, 100);
              elem->emoteShown = 1;
            } else if (--elem->emoteTimer == 0) {
              elem->emoteTimer = elem->emotePeriod;
            }
          } else if (elem->emoteShown != 0) {
            elem->emote = Emote_Show(elem->emote, &elem->mover, elem->emoteKind, 0x7F, (u16*)&elem->emoteTimer, elem->emotePeriod, 0, 100);
            elem->emoteShown = 0;
          }
        }
      }
      elem->timer++;
    }
  }

  if (gInput[0].pressed & A_BUTTON) {
    EntityAB4E_Talk(p);
  }
  p->frameCount++;
  return 0;
}

s32 EntityAB4E_Destroy(EntityAB4E* p) {
  EntityAB4EElem* elem = p->elems;
  s32 i;

  for (i = 0; i < 16; i++, elem++) {
    if (elem->active) {
      FUN_080452f4(p, elem, i);
    }
  }

  gEntityAB4E = NULL;
  return 0;
}

s32 EntityAB4E_Init(EntityAB4E* p) {
  u16 ids[8];
  Player* player;
  s32 i;

  gEntityAB4E = p;
  if (VM_SeekToNamedArg('d')) {
    for (i = 0; i < 8; i++) {
      if (VM_GetPC() != NULL) {
        ids[i] = VM_GetValue();
      } else {
        ids[i] = 0xFFFF;
      }
    }
  } else {
    for (i = 0; i < 8; i++) {
      ids[i] = 0xFFFF;
    }
  }

  p->hidePointCount = 0;
  if (VM_SeekToNamedArg('h')) {
    for (i = 0; i < 16; i++) {
      if (VM_GetPC() != NULL) {
        p->hidePoints[i].x = VM_GetValue();
        p->hidePoints[i].z = VM_GetValue();
        p->hidePoints[i].y = TileHeightAt(&p->hidePoints[i]);
        p->hidePointCount++;
      } else {
        p->hidePoints[i].x = 0;
        p->hidePoints[i].y = 0;
        p->hidePoints[i].z = 0;
      }
    }
  } else {
    for (i = 0; i < 16; i++) {
      p->hidePoints[i].x = 0;
      p->hidePoints[i].y = 0;
      p->hidePoints[i].z = 0;
    }
  }

  p->count2 = 0;
  if (VM_SeekToNamedArg('s')) {
    for (i = 0; i < 16; i++) {
      if (VM_GetPC() != NULL) {
        p->points2[i].x = VM_GetValue();
        p->points2[i].z = VM_GetValue();
        p->points2[i].y = TileHeightAt(&p->points2[i]);
        p->count2++;
      } else {
        p->points2[i].x = 0;
        p->points2[i].y = 0;
        p->points2[i].z = 0;
      }
    }
  } else {
    for (i = 0; i < 16; i++) {
      p->points2[i].x = 0;
      p->points2[i].y = 0;
      p->points2[i].z = 0;
    }
  }

  p->minuteChanged = FALSE;
  p->hour = Time_GetHour();
  p->prevMinute = p->minute = Time_GetMinute();
  p->talkScriptID = VM_GetNamedArgValue('t', 0);
  p->frameCount = 0;

  for (i = 0; i < 8; i++) {
    // 原典は 8 個とも ids[0] のファイルを開く
    MainSpriteGfxFile* f = GetFile(DIR_MAIN_SPRITE, ids[0]);

    if (f == NULL) {
      return -1;
    }
    p->gfx[i] = *f;
    OpenMainSpriteFile(&p->gfx[i], f);
  }

  player = gPlayerPtr[0];
  p->player = player;
  p->playerPos = &player->mover.pos;
  return 0;
}

// 0xAB4E
EntityAB4E* EntityAB4E_Create(void) {
  if (gEntityAB4E == NULL) {
    EntityAB4E* p = CreateEntity(ENTITY_UNK_5, sizeof(EntityAB4E));

    if (p != NULL) {
      SetEntityRoutine(p, EntityAB4E_Update, EntityAB4E_Destroy);
      if (EntityAB4E_Init(p) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gEntityAB4E;
}

// 0x8A21, 名前付き引数から要素を1つ足す
s32 Cmd_AddEntityAB4EElem(void) {
  EntityAB4E* p = gEntityAB4E;
  EntityAB4EElem* elem;
  Vec3 pos;
  Vec3 size;
  s32 angle;
  s32 i;

  if (p == NULL) {
    return -1;
  }
  elem = EntityAB4E_FindFreeElem(p);
  if (elem == NULL) {
    return -1;
  }

  elem->id = VM_GetNamedArgValue('n', 0);
  elem->unk_2 = VM_GetNamedArgValue('e', 0);
  elem->state = VM_GetNamedArgValue('m', 2);
  elem->stateEntered = TRUE;
  elem->timer = 0;
  elem->gfxIndex = VM_GetNamedArgValue('k', 0);
  EntityAB4E_SetEmote(p, elem, VM_GetNamedArgValue('h', 4));
  elem->emotePeriod = 180;
  elem->emoteTimer = 180;

  if (VM_SeekToNamedArg('p')) {
    pos.x = VM_GetValue();
    pos.y = VM_GetValue();
    pos.z = VM_GetValue();
    angle = VM_GetValue();
  } else {
    pos.x = gStat->playerX;
    pos.y = gStat->playerY;
    pos.z = gStat->playerZ;
    angle = 0;
  }

  if (VM_SeekToNamedArg('t')) {
    elem->hasSchedule = TRUE;
    elem->startHour = VM_GetValue();
    elem->startMinute = VM_GetValue();
    elem->endHour = VM_GetValue();
    elem->endMinute = VM_GetValue();
  } else {
    elem->hasSchedule = FALSE;
    elem->startHour = 9;
    elem->startMinute = 0;
    elem->endHour = 21;
    elem->endMinute = 0;
  }

  if (VM_SeekToNamedArg('P')) {
    elem->nearRange = VM_GetValue();
    elem->keepRange = VM_GetValue();
  } else {
    elem->nearRange = 256;
    elem->keepRange = 512;
  }

  if (VM_SeekToNamedArg('r')) {
    elem->pathIdx = VM_GetValue();
    elem->pathParam = VM_GetValue();
    elem->pathNodeIdx = VM_GetValue();
    elem->unk_34 = VM_GetValue();
    elem->arriveRange = VM_GetValue();
  } else {
    elem->pathIdx = -1;
    elem->pathParam = 0;
    elem->pathNodeIdx = 0;
    elem->unk_34 = 8;
    elem->arriveRange = 12;
  }

  if (VM_SeekToNamedArg('E')) {
    elem->hidePointIdx = VM_GetValue();
    elem->unk_2a = VM_GetValue();
    elem->unk_2b = VM_GetValue();
  } else {
    elem->hidePointIdx = -1;
    elem->unk_2a = -1;
    elem->unk_2b = -1;
  }

  if (VM_SeekToNamedArg('a')) {
    for (i = 0; i < 4; i++) {
      if (VM_GetPC() == NULL) {
        break;
      }
      elem->talkArgs[i] = VM_GetValue();
    }
  } else {
    i = 0;
  }
  for (; i < 4; i++) {
    elem->talkArgs[i] = 0;
  }

  Mover_Init(&elem->mover, elem->id, &pos, angle, 7, elem);
  size.x = 0, size.y = 0x200, size.z = 0;
  FUN_0823b47c(&elem->mover, &size);
  if (elem->pathIdx >= 0) {
    Mover_SetPath(&elem->mover, &elem->pathWalker, elem->pathIdx, elem->pathParam, elem->pathNodeIdx);
    Map_ReadPathNodePos(&elem->mover.pos, elem->pathWalker.node, 0);
    EntityAB4EElem_CheckPathNode(elem);
  }
  elem->prevState = 0;
  elem->mover.pos.y = TileHeightAt(&elem->mover.pos);
  elem->unk_1b = 0;
  MainSprite_Add(&elem->sprite, p->gfx, 0, 0, 2, 0, 60, &elem->mover.pos);
  MainSprite_SetAnim(&elem->sprite, p->gfx, sEntityAB4EStandAnims[elem->gfxIndex], PLAYMODE_LOOP, 0);
  FUN_08002a48(&elem->mover);
  ParticleShadow_Init(&elem->shadow, &elem->mover.pos, 1);
  ParticleShadow_Show(&elem->shadow);
  elem->unk_8 = 0;
  elem->active = TRUE;
}
