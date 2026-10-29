#include "entity.h"
#include "file.h"
#include "global.h"
#include "sprite.h"
#include "vm.h"

// スクリプトから足せる飾りのスプライト1枚, 位置の補間とマーカー設定への追従を持つ
typedef struct {
  u8 unk_0[24];           // 0x00, どの関数も触っていない
  MainSpriteGfx gfx;      // 0x18, '.d' で指定したスプライトファイル (e.g. SPRITE_DJANGO_LARGE, SPRITE_E89F, SPRITE_UI_SOLARBANK)
  MainSprite sprite;      // 0x38
  u16 id;                 // 0x98, '.n', スクリプトから枠を引くときの番号
  bool16 moving;          // 0x9A, 0 以外なら pos を fromPos から toPos へ補間する
  bool16 markerGated;     // 0x9C, 0 以外なら gStat->markerEnabled に従って表示を切り替える
  bool16 hiddenByScript;  // 0x9E, スクリプトから隠されているか
  u16 elapsed;            // 0xA0, 補間の経過フレーム
  u16 duration;           // 0xA2, 補間の全体フレーム数
  Vec3 pos;               // 0xA4, 現在位置
  Vec3 fromPos;           // 0xAC, 補間の始点
  Vec3 toPos;             // 0xB4, 補間の終点
} Entity8AF6Entry;
static_assert(sizeof(Entity8AF6Entry) == 188);

typedef struct {
  Entity e;                    // 0x00, ENTITY_UNK_8
  u8 count;                    // 0x18, '.m=1', 確保した枠数
  u8 used;                     // 0x19, 使用中の枠数, Update と Destroy はここまでしか回さない
  Entity8AF6Entry entries[1];  // 0x1C, 実際は count 個 (可変長)
} Entity8AF6;                  // Entity8AF6 はサイズが可変
static_assert(sizeof(Entity8AF6) == 216);

COMMON_DATA Entity8AF6* gEntity8AF6 = NULL;  // 0x03002C4C

// '.n' と id が一致する枠を返す, 無ければ NULL
Entity8AF6Entry* Entity8AF6_FindEntry(void) {
  u32 id;
  s32 i;

  if (gEntity8AF6 == NULL) {
    return NULL;
  }

  if (!VM_SeekToNamedArg('n')) {
    return NULL;
  }

  id = VM_GetValue();
  for (i = 0; i < gEntity8AF6->used; i++) {
    if (gEntity8AF6->entries[i].id == id) {
      return &gEntity8AF6->entries[i];
    }
  }
  return NULL;
}

// 0x44CD
void Entity8AF6_SetPoseScripted(void) {
  Entity8AF6Entry* e = Entity8AF6_FindEntry();

  if (e != NULL && VM_SeekToNamedArg('p')) {
    MainSprite_SetPose(&e->sprite, &e->gfx, VM_GetValue(), PLAYMODE_PAUSE);
  }
}

// 0xED1F, '.f' で左右反転を切り替える
void Cmd_ED1F(void) {
  Entity8AF6Entry* e = Entity8AF6_FindEntry();

  if (e != NULL && VM_SeekToNamedArg('f')) {
    if (VM_GetValue()) {
      e->sprite.flags |= SPRFLAG_XFLIP;
    } else {
      e->sprite.flags &= ~SPRFLAG_XFLIP;
    }
  }
}

// 0xEBFF
void Entity8AF6_HideScripted(void) {
  Entity8AF6Entry* e = Entity8AF6_FindEntry();

  if (e != NULL) {
    e->sprite.flags |= SPRFLAG_HIDDEN;
    if (e->markerGated != 0) {
      e->hiddenByScript = 1;
    }
  }
}

// 0x9C3F
void Entity8AF6_ShowScripted(void) {
  Entity8AF6Entry* e = Entity8AF6_FindEntry();

  if (e != NULL) {
    e->sprite.flags &= ~SPRFLAG_HIDDEN;
    if (e->markerGated != 0) {
      e->hiddenByScript = 0;
    }
  }
}

// 0x65E1
void Cmd_65E1(void) {
  Entity8AF6Entry* e = Entity8AF6_FindEntry();

  if (e != NULL && VM_SeekToNamedArg('p')) {
    e->sprite.priority = VM_GetValue();
  }
}

// 0x997B, 現在位置から '.p' の位置へ '.f' フレームかけて移動させる
void Entity8AF6_MoveToScripted(void) {
  Entity8AF6Entry* e = Entity8AF6_FindEntry();

  if (e != NULL) {
    if (VM_SeekToNamedArg('p')) {
      e->toPos.x = VM_GetValue();
      e->toPos.y = VM_GetValue();
      e->toPos.z = VM_GetValue();
    }
    if (VM_SeekToNamedArg('f')) {
      e->duration = VM_GetValue();
    }
    e->fromPos = e->pos;
    e->elapsed = 0;
    e->moving = 1;
  }
}

// 枠の補間移動を1フレーム進め, markerGated なら gStat->markerEnabled と hiddenByScript に合わせて表示を切り替える
void Entity8AF6Entry_Update(Entity8AF6Entry* p) {
  if (p->moving != 0) {
    p->elapsed++;
    if (p->elapsed >= p->duration) {
      p->pos = p->toPos;
      p->moving = 0;
    } else {
      s32 rest = p->duration - p->elapsed;

      p->pos.x = Div(p->toPos.x * p->elapsed + p->fromPos.x * rest, p->duration);
      p->pos.y = Div(p->toPos.y * p->elapsed + p->fromPos.y * rest, p->duration);
      p->pos.z = Div(p->toPos.z * p->elapsed + p->fromPos.z * rest, p->duration);
    }
    p->sprite.pos = p->pos;
  }
  if (p->markerGated != 0) {
    if (p->hiddenByScript == 0 && gStat->markerEnabled != 0) {
      p->sprite.flags &= ~SPRFLAG_HIDDEN;
    } else {
      p->sprite.flags |= SPRFLAG_HIDDEN;
    }
  }
}

// 0xEAB4, 空き枠に '.d' のスプライトを '.p' の位置へ置く, '.n' で番号, '.A' でマーカー連動を指定する
void Entity8AF6_AddEntryScripted(void) {
  Entity8AF6Entry* e;
  MainSpriteGfxFile* f;
  u32 poseIdx;
  SpriteFlags flags;
  u32 prio;
  u32 mode;
  u32 spriteID;

  if (gEntity8AF6 == NULL || gEntity8AF6->used >= gEntity8AF6->count) {
    return;
  }

  e = &gEntity8AF6->entries[gEntity8AF6->used];
  if (VM_SeekToNamedArg('n')) {
    e->id = VM_GetValue();
  } else {
    e->id = 0;
  }
  if (!VM_SeekToNamedArg('d')) {
    return;
  }

  spriteID = VM_GetValue();
  f = GetFile(DIR_MAIN_SPRITE, spriteID);
  e->gfx = *f;
  OpenMainSpriteFile(&e->gfx, f);
  poseIdx = VM_SeekToNamedArg('i') ? VM_GetValue() : 0;
  mode = VM_SeekToNamedArg('m') ? VM_GetValue() : 0;
  flags = 0;
  if (mode == 1) {
    flags = SPRFLAG_SCREEN_COORD;
  }
  prio = VM_SeekToNamedArg('R') ? VM_GetValue() : 2;
  if (VM_SeekToNamedArg('p')) {
    VEC3_SET(e->pos, VM_GetValue(), VM_GetValue(), VM_GetValue());
  } else {
    VEC3_SET(e->pos, 0, 0, 0);
  }
  MainSprite_Add(&e->sprite, &e->gfx, poseIdx, flags, prio, PLAYMODE_PAUSE, 60, &e->pos);
  if (VM_SeekToNamedArg('A')) {
    e->markerGated = VM_GetValue();
  } else {
    e->markerGated = 0;
  }
  e->hiddenByScript = 0;
  gEntity8AF6->used++;
}

s32 Entity8AF6_Update(Entity8AF6* p) {
  s32 i;

  for (i = 0; i < p->used; i++) {
    Entity8AF6Entry_Update(&p->entries[i]);
  }
  return 0;
}

s32 Entity8AF6_Destroy(Entity8AF6* p) {
  s32 i;

  for (i = 0; i < p->used; i++) {
    MainSprite_Remove(&p->entries[i].sprite);
  }
  gEntity8AF6 = NULL;
  return 0;
}

s32 Entity8AF6_Init(Entity8AF6* p, u32 id, u32 _, u32 count) {
  p->count = count;
  p->used = 0;
  gEntity8AF6 = p;
  return 0;
}

// 0x8AF6
Entity8AF6* Entity8AF6_Create(u32 id, u32 _) {
  if (gEntity8AF6 == NULL) {
    u32 count = VM_SeekToNamedArg('m') ? VM_GetValue() : 1;
    Entity8AF6* p = CreateEntity(ENTITY_UNK_8, offsetof(Entity8AF6, entries) + count * sizeof(Entity8AF6Entry));

    if (p != NULL) {
      SetEntityRoutine(p, Entity8AF6_Update, Entity8AF6_Destroy);
      if (Entity8AF6_Init(p, id, _, count) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gEntity8AF6;
}
