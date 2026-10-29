#include "entity.h"
#include "file.h"
#include "global.h"
#include "malloc.h"
#include "shadow.h"
#include "sprite_animation.h"
#include "sprite_aux.h"
#include "sprite_pltt.h"
#include "vm.h"

// スクリプトから操る表示要素1個, 位置・パレット・スケールを frames かけて線形補間する
typedef struct {
  u16 id;                      // 0x00, '.n' で要素を引くときの識別子, gfx.plttID = id + 600
  u8 flags;                    // 0x02, bit0 位置補間中, bit1 パレット補間中, bit2 スケール補間中, bit3 アニメ再生中
  AuxAnimPlayFlags animFlags;  // 0x03, '.r', AddEntryScripted では '.f' が入り, 0 以外なら sprite に SPRFLAG_XFLIP を立てる
  u8 optionFlags;              // 0x04, '.A', bit0/bit1 をアニメコマンドの反転ビットと比べて sprite の XFLIP/YFLIP を決める
  u8 unk_05[3];                // 0x05
  rgb555 pltt[16];             // 0x08, パレット補間の書き込み先, gfx.pltt がここを指すように差し替えられる
  AuxSprite sprite;            // 0x28
  AuxSpriteGfx gfx;            // 0x54, ID は固定ではない ('.t')
  Vec3 srcPos;                 // 0x70, 位置補間の始点, 補間開始時の sprite.pos の写し
  Vec3 destPos;                // 0x78, '.p', 位置補間の終点
  u16 moveFrames;              // 0x80, '.f'
  u16 moveTick;                // 0x82, moveFrames に達すると flags bit0 が落ちる
  u16 plttBase;                // 0x84, gObjPlttData のパレット行の基準, gfx.plttID の写し
  u16 plttFrom;                // 0x86, '.s', plttBase からの相対行
  u16 plttTo;                  // 0x88, '.e', plttBase からの相対行
  u16 plttTick;                // 0x8A
  u16 plttFrames;              // 0x8C, '.f', 2未満なら補間せず plttTo の行をそのまま使う
  u16 unk_8e;                  // 0x8E
  u16 scaleFrom;               // 0x90, '.s', 0x40 が等倍の 6.6 固定小数
  u16 scaleTo;                 // 0x92, '.e', 等倍に戻ると sprite の SPRFLAG_AFFINE が落ちる
  u16 scaleTick;               // 0x94
  u16 scaleFrames;             // 0x96, '.f'
  u8 animIdx;                  // 0x98, '.m', animFile 内のアニメーション番号
  u8 animPlayMode;             // 0x99, '.d'
  bool8 runScriptOnAnimEnd;    // 0x9A, '.o', 0 以外ならアニメ終端で flags bit3 を落として scriptID を実行する
  u8 unk_9b;                   // 0x9B
  AuxAnimState anim;           // 0x9C
  AuxAnimFile* animFile;       // 0xAC, ID は固定ではない ('.m')
  u32 scriptID;                // 0xB0, '.e', アニメ終端で VM_ExecByID に渡す
  ParticleShadow* shadow;      // 0xB4, '.s' が 0 以外のときだけ Malloc して付ける影
} Entity3117Entry;
static_assert(sizeof(Entity3117Entry) == 184);

typedef struct Entity3117 {
  Entity e;                    // 0x00, ENTITY_UNK_9
  u8 capacity;                 // 0x18, entries の確保数, '.m=8' (0 なら 8)
  u8 count;                    // 0x19, 使用済みの entries 数, AddEntryScripted が capacity を上限に足す
  u8 unk_1a[2];                // 0x1A
  Entity3117Entry entries[1];  // 0x1C, 実際は capacity 個 (可変長)
} Entity3117;

COMMON_DATA Entity3117* gEntity3117 = NULL;  // 0x03002C48

// '.n' と id が一致する要素を返す, 無ければ NULL
Entity3117Entry* Entity3117_FindEntry(void) {
  u32 id;
  s32 i;

  if (gEntity3117 == NULL) {
    return NULL;
  }

  if (!VM_SeekToNamedArg('n')) {
    return NULL;
  }

  id = VM_GetValue();
  for (i = 0; i < gEntity3117->count; i++) {
    if (gEntity3117->entries[i].id == id) {
      return &gEntity3117->entries[i];
    }
  }
  return NULL;
}

// '.n' の要素を '.p' へ '.f' フレームかけて動かし始める
void Entity3117_StartMoveScripted(void) {
  Entity3117Entry* e = Entity3117_FindEntry();

  if (e != NULL && VM_SeekToNamedArg('p')) {
    VEC3_SET(e->destPos, VM_GetValue(), VM_GetValue(), VM_GetValue());
    if (VM_SeekToNamedArg('f')) {
      e->moveFrames = VM_GetValue();
      if (e->moveFrames != 0) {
        e->flags |= 1;
        e->srcPos = e->sprite.pos;
        e->moveTick = 0;
      }
    }
  }
}

void Entity3117_SetPoseScripted(void) {
  Entity3117Entry* e = Entity3117_FindEntry();

  if (e != NULL && VM_SeekToNamedArg('p')) {
    e->sprite.poseIdx = VM_GetValue();
  }
}

void Entity3117_HideScripted(void) {
  Entity3117Entry* e = Entity3117_FindEntry();

  if (e != NULL) {
    e->sprite.flags |= SPRFLAG_HIDDEN;
  }
}

void Entity3117_ShowScripted(void) {
  Entity3117Entry* e = Entity3117_FindEntry();

  if (e != NULL) {
    e->sprite.flags &= ~SPRFLAG_HIDDEN;
  }
}

void Entity3117_SetPriorityScripted(void) {
  Entity3117Entry* e = Entity3117_FindEntry();

  if (e != NULL && VM_SeekToNamedArg('p')) {
    e->sprite.priority = VM_GetValue();
  }
}

// '.n' の要素のパレットを '.s' 行から '.e' 行へ '.f' フレームかけて変え始める, 2 フレーム未満なら '.e' 行をすぐに当てる
void Entity3117_StartPlttFadeScripted(void) {
  Entity3117Entry* e = Entity3117_FindEntry();

  if (e != NULL && VM_SeekToNamedArg('s')) {
    e->plttFrom = VM_GetValue();
    if (VM_SeekToNamedArg('e')) {
      e->plttTo = VM_GetValue();
      if (VM_SeekToNamedArg('f')) {
        e->plttFrames = VM_GetValue();
        if (e->plttFrames < 2) {
          Video_SetAuxSpritePltt(&e->gfx, e->plttBase + e->plttTo);
        } else {
          e->plttTick = 0;
          e->flags |= 2;
        }
      }
    }
  }
}

// '.n' の要素を '.s' から '.e' の拡大率へ '.f' フレームかけて変え始める
void Entity3117_StartScaleScripted(void) {
  Entity3117Entry* e = Entity3117_FindEntry();

  if (e != NULL && VM_SeekToNamedArg('s')) {
    e->scaleFrom = VM_GetValue();
    if (VM_SeekToNamedArg('e')) {
      e->scaleTo = VM_GetValue();
      if (VM_SeekToNamedArg('f')) {
        e->scaleFrames = VM_GetValue();
        e->sprite.scaleY = e->sprite.scaleX = e->scaleTo;
        if (e->scaleFrames < 2) {
          if (e->sprite.scaleX != Q6(1)) {
            e->sprite.flags |= SPRFLAG_AFFINE;
          }
        } else {
          e->sprite.flags |= SPRFLAG_AFFINE;
          e->scaleTick = 0;
          e->flags |= 4;
        }
      }
    }
  }
}

// '.n' の要素に '.m' のアニメを '.d' / '.r' で流し始める ('.E' なら頭から), '.o' ならアニメ終端で '.e' のスクリプトを実行する
void Entity3117_SetAnimScripted(void) {
  Entity3117Entry* e = Entity3117_FindEntry();

  if (e != NULL && VM_SeekToNamedArg('m')) {
    e->animIdx = VM_GetValue();
    if (VM_SeekToNamedArg('d')) {
      e->animPlayMode = VM_GetValue();
      if (VM_SeekToNamedArg('r')) {
        s32 restart;

        e->animFlags = VM_GetValue();
        restart = 0;
        if (VM_SeekToNamedArg('E')) {
          restart = VM_GetValue();
        }
        if (restart) {
          AuxAnim_RestartAnim(&e->anim, e->animFile, e->animIdx, e->animPlayMode, e->animFlags);
        } else {
          AuxAnim_SetAnim(&e->anim, e->animFile, e->animIdx, e->animPlayMode, e->animFlags);
        }
        if (VM_SeekToNamedArg('P')) {
          AuxAnim_SetAnimSpeed(&e->anim, VM_GetValue());
        }
        if (VM_SeekToNamedArg('o')) {
          e->runScriptOnAnimEnd = VM_GetValue();
        } else {
          e->runScriptOnAnimEnd = FALSE;
        }
        if (e->runScriptOnAnimEnd) {
          if (VM_SeekToNamedArg('e')) {
            e->scriptID = VM_GetValue();
          } else {
            e->scriptID = 0;
          }
        } else {
          e->scriptID = 0;
        }
        e->flags |= 8;
      }
    }
  }
}

// 要素を1フレーム進める, 位置・パレット・拡大率を線形補間し, アニメを1コマ進めて終端で '.e' のスクリプトを実行する
// 残差は 437/442, パレット補間のループの並び (原典はループ本体を後ろに置く) と, 後半の AuxAnim 手動送りの壁 (PlayerShockwave_UpdateAnim と同じ)
// Tier A は未着手 (ループの書き方), 初稿のみ
NON_MATCH void Entity3117_UpdateEntry(Entity3117Entry* e) {
#ifdef NONMATCHING_C
  if (e->flags == 0) {
    return;
  }

  if (e->flags & 1) {
    s32 rest;

    e->moveTick++;
    rest = e->moveFrames - e->moveTick;
    e->sprite.pos.x = Div(rest * e->srcPos.x + e->moveTick * e->destPos.x, e->moveFrames);
    e->sprite.pos.y = Div(rest * e->srcPos.y + e->destPos.y * e->moveTick, e->moveFrames);
    e->sprite.pos.z = Div(rest * e->srcPos.z + e->destPos.z * e->moveTick, e->moveFrames);
    if (e->moveTick >= e->moveFrames) {
      e->flags &= ~1;
    }
  }

  if (e->flags & 2) {
    if (++e->plttTick < e->plttFrames) {
      rgb555* from = &gObjPlttData[(e->plttBase + e->plttFrom) * 16];
      rgb555* to = &gObjPlttData[(e->plttBase + e->plttTo) * 16];
      s32 rest = e->plttFrames - e->plttTick;
      rgb555* dst = e->pltt;
      s32 i;

      for (i = 15; i >= 0; i--) {
        u32 c0 = *from;
        u32 c1 = *to;
        s32 r = Div(rest * (c0 & 0x1F) + (c1 & 0x1F) * e->plttTick, e->plttFrames);
        s32 g = Div(rest * ((c0 >> 5) & 0x1F) + ((c1 >> 5) & 0x1F) * e->plttTick, e->plttFrames);
        s32 b = Div(rest * ((c0 >> 10) & 0x1F) + ((c1 >> 10) & 0x1F) * e->plttTick, e->plttFrames);
        *dst = (b << 10) | (g << 5) | r;
        from++;
        to++;
        dst++;
      }
      e->gfx.pltt = e->pltt;
      e->gfx.plttID = e->id + 600;
    } else {
      Video_SetAuxSpritePltt(&e->gfx, e->plttBase + e->plttTo);
      e->flags &= ~2;
    }
  }

  if (e->flags & 4) {
    if (++e->scaleTick < e->scaleFrames) {
      s32 scale;

      e->sprite.flags |= SPRFLAG_AFFINE;
      scale = Div(e->scaleFrom * (e->scaleFrames - e->scaleTick) + e->scaleTick * e->scaleTo, e->scaleFrames);
      e->sprite.scaleY = e->sprite.scaleX = scale;
    } else {
      e->sprite.scaleY = e->sprite.scaleX = e->scaleTo;
      if (e->sprite.scaleX == Q6(1)) {
        e->sprite.flags &= ~SPRFLAG_AFFINE;
      }
      e->flags &= ~4;
    }
  }

  if (e->flags & 8) {
    AuxAnimState* anim = &e->anim;
    AuxSprite* sprite = &e->sprite;
    AuxAnimCmd* cmd;
    bool32 done;

    cmd = &anim->cmds[anim->cmdIdx];
    e->sprite.poseIdx = *cmd >> 6;
    if ((anim->flags & ANIM_PLAY_XFLIP) != (((*cmd & 0x30) >> 4) & ANIM_PLAY_XFLIP)) {
      e->sprite.flags |= SPRFLAG_XFLIP;
    } else {
      e->sprite.flags &= ~SPRFLAG_XFLIP;
    }
    if ((u8)(anim->flags & ANIM_PLAY_YFLIP) != (((*cmd & 0x30) >> 4) & ANIM_PLAY_YFLIP)) {
      sprite->flags |= SPRFLAG_YFLIP;
    } else {
      sprite->flags &= ~SPRFLAG_YFLIP;
    }
    anim->tick++;
    if (anim->tick < anim->wait) {
      done = FALSE;
    } else {
      anim->tick = 0;
      if (anim->flags & ANIM_PLAY_REVERSE) {
        if (anim->cmdIdx == 0) {
          anim->cmdIdx = anim->cmdCount - 1;
          done = TRUE;
        } else {
          anim->cmdIdx--;
          done = FALSE;
        }
      } else {
        anim->cmdIdx++;
        if (anim->cmdIdx >= anim->cmdCount) {
          anim->cmdIdx = 0;
          done = TRUE;
        } else {
          done = FALSE;
        }
      }
      cmd = &anim->cmds[anim->cmdIdx];
      anim->duration = *cmd & 0xF;
      anim->wait = anim->duration * anim->speed >> 6;
      if (anim->wait == 0) {
        anim->wait = 1;
      }
    }
    if (done && e->runScriptOnAnimEnd) {
      e->flags &= ~8;
      if (e->scriptID != 0) {
        VM_ExecByID(e->scriptID, NULL);
      }
    }
  }
#else
  INCFUNC("asm/func/Entity3117_UpdateEntry.inc");
#endif
}

// スクリプトから要素を1個足す, '.t' のスプライトを '.p' に置き, '.m' があればアニメを1コマ目まで進め, '.s' なら影を付ける
// 残差は 334/324, sprite / gfx のアドレスをレジスタに置く順と退避レジスタの割り当て, 後半の AuxAnim 手動送りは Player 側 (FUN_080772ec など) と同じ壁
// Tier A-C 試済 (sprite / gfx ポインタのローカル, '.n' / '.A' を if/else で 0 にする), 未: 割り当ての順
NON_MATCH void Entity3117_AddEntryScripted(void) {
#ifdef NONMATCHING_C
  Entity3117Entry* e;
  AuxSprite* sprite;
  AuxSpriteGfx* gfx;
  s32 hasShadow;

  if (gEntity3117 == NULL || gEntity3117->count >= gEntity3117->capacity) {
    return;
  }

  e = &gEntity3117->entries[gEntity3117->count];
  if (VM_SeekToNamedArg('n')) {
    e->id = VM_GetValue();
  } else {
    e->id = 0;
  }
  sprite = &e->sprite;
  gfx = &e->gfx;
  if (VM_SeekToNamedArg('t')) {
    SpriteID32 id = VM_GetValue();
    s32 pose = VM_SeekToNamedArg('i') ? VM_GetValue() : 0;

    Video_GetAuxSprite(gfx, id);
    AuxSprite_Add(sprite, gfx, 0);
    sprite->poseIdx = pose;
    e->plttBase = gfx->plttID;
    e->animFlags = 0;
    if (VM_SeekToNamedArg('f')) {
      e->animFlags = VM_GetValue();
    }
    if (e->animFlags) {
      sprite->flags |= SPRFLAG_XFLIP;
    }
    if (VM_SeekToNamedArg('p')) {
      VEC3_SET(sprite->pos, VM_GetValue(), VM_GetValue(), VM_GetValue());
    } else {
      VEC3_SET(sprite->pos, 0, 0, 0);
    }
    if (VM_SeekToNamedArg('A')) {
      e->optionFlags = VM_GetValue();
    } else {
      e->optionFlags = 0;
    }
    if (VM_SeekToNamedArg('R')) {
      sprite->priority = VM_GetValue();
    }
    if (VM_SeekToNamedArg('m')) {
      AuxAnimState* anim;
      AuxAnimCmd* cmd;

      e->animFile = GetFile(DIR_ANIMATION, VM_GetValue());
      e->animIdx = VM_GetValue();
      e->animPlayMode = VM_GetValue();
      if (VM_SeekToNamedArg('o')) {
        e->runScriptOnAnimEnd = VM_GetValue();
      } else {
        e->runScriptOnAnimEnd = FALSE;
      }
      if (e->runScriptOnAnimEnd) {
        if (VM_SeekToNamedArg('e')) {
          e->scriptID = VM_GetValue();
        } else {
          e->scriptID = 0;
        }
      } else {
        e->scriptID = 0;
      }
      anim = &e->anim;
      AuxAnim_SetAnim(anim, e->animFile, e->animIdx, e->animPlayMode, e->animFlags);
      if (VM_SeekToNamedArg('P')) {
        AuxAnim_SetAnimSpeed(anim, VM_GetValue());
      }

      cmd = &anim->cmds[anim->cmdIdx];
      e->sprite.poseIdx = *cmd >> 6;
      if ((anim->flags & ANIM_PLAY_XFLIP) != (((*cmd & 0x30) >> 4) & ANIM_PLAY_XFLIP)) {
        e->sprite.flags |= SPRFLAG_XFLIP;
      } else {
        e->sprite.flags &= ~SPRFLAG_XFLIP;
      }
      if ((u8)(anim->flags & ANIM_PLAY_YFLIP) != (((*cmd & 0x30) >> 4) & ANIM_PLAY_YFLIP)) {
        sprite->flags |= SPRFLAG_YFLIP;
      } else {
        sprite->flags &= ~SPRFLAG_YFLIP;
      }
      anim->tick++;
      if (anim->tick >= anim->wait) {
        anim->tick = 0;
        if (anim->flags & ANIM_PLAY_REVERSE) {
          s32 idx = anim->cmdIdx;

          if (idx == 0) {
            idx = anim->cmdCount;
          }
          anim->cmdIdx = idx - 1;
        } else {
          anim->cmdIdx++;
          if (anim->cmdIdx >= anim->cmdCount) {
            anim->cmdIdx = 0;
          }
        }
        cmd = &anim->cmds[anim->cmdIdx];
        anim->duration = *cmd & 0xF;
        anim->wait = anim->duration * anim->speed >> 6;
        if (anim->wait == 0) {
          anim->wait = 1;
        }
      }
      e->flags = 8;
    } else {
      e->animFile = NULL;
      e->runScriptOnAnimEnd = FALSE;
      e->scriptID = 0;
      e->flags = 0;
    }
    hasShadow = 0;
    if (VM_SeekToNamedArg('s')) {
      hasShadow = VM_GetValue();
    }
    e->shadow = NULL;
    if (hasShadow) {
      e->shadow = Malloc(sizeof(ParticleShadow));
      if (e->shadow != NULL) {
        ClearMemory(e->shadow, sizeof(ParticleShadow));
        ParticleShadow_Init(e->shadow, &e->sprite.pos, 0);
      }
    }
    gEntity3117->count++;
  }
#else
  INCFUNC("asm/func/Entity3117_AddEntryScripted.inc");
#endif
}

// 残差2命令 (24/26): 原典はループ条件を先頭と末尾の2箇所に持つ (agbcc の loop rotation) が, こちらは末尾だけになる
NON_MATCH s32 Entity3117_Update(Entity3117* p) {
#ifdef NONMATCHING_C
  Entity3117Entry* e;
  s32 i;

  for (i = 0, e = p->entries; i < p->count; i++, e++) {
    if (gEntityDisableFlags == 0 || e->optionFlags != 0) {
      Entity3117_UpdateEntry(e);
    }
  }
  return 0;
#else
  INCFUNC("asm/func/Entity3117_Update.inc");
#endif
}

s32 Entity3117_Destroy(Entity3117* p) {
  s32 i;

  for (i = 0; i < p->count; i++) {
    AuxSprite_Remove(&p->entries[i].sprite);
    if (p->entries[i].shadow != NULL) {
      ParticleShadow_Remove(p->entries[i].shadow);
      Free(p->entries[i].shadow);
    }
  }
  gEntity3117 = NULL;
  return 0;
}

s32 Entity3117_Init(Entity3117* p, u32 param_2, u32 param_3, s32 capacity) {
  p->capacity = capacity;
  p->count = 0;
  gEntity3117 = p;
  return 0;
}

Entity3117* Entity3117_Create(u32 param_1, u32 param_2) {
  Entity3117* p;
  s32 capacity;

  if (gEntity3117 != NULL) {
    return gEntity3117;
  }

  if (VM_SeekToNamedArg('m')) {
    capacity = VM_GetValue();
  } else {
    capacity = 1;
  }

  p = CreateEntity(ENTITY_UNK_9, sizeof(Entity3117Entry) * capacity + 0x1C);
  if (p != NULL) {
    SetEntityRoutine(p, Entity3117_Update, Entity3117_Destroy);
    if (Entity3117_Init(p, param_1, param_2, capacity) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}
