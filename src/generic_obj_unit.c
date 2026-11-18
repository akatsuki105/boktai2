#include "entity.h"
#include "file.h"
#include "global.h"
#include "sprite.h"
#include "vm.h"

// generic_obj.c の MainSprite (oud, Obj Unit Data) バージョン

// スクリプトから足せる飾りのスプライト1枚, 位置の補間とマーカー設定への追従を持つ
typedef struct {
  u8 unk_0[24];           // 0x00, どの関数も触っていない
  MainSpriteGfx gfx;      // 0x18, '.d' で指定したスプライトファイル (e.g. SPR_DJANGO_LARGE, SPR_DUNGEON_TITLE, SPR_UI_BANK)
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
} GenericObjUnit;
static_assert(sizeof(GenericObjUnit) == 188);

// スクリプトが MainSprite の大きな絵を画面に重ねて出し入れする入れ物, AuxSprite を使う GenericObjManager (汎用オブジェ) と対になる兄弟
// 使い道: ソル・デ・バイスを受け取るときのジャンゴの1枚絵 (SPR_DJANGO_LARGE), 暗黒ローンの取り立てなどの太陽バンクの UI (SPR_UI_BANK), ダンジョンタイトルの特殊フォント (SPR_DUNGEON_TITLE), スミレ (SPR_SUMIRE)
// インスタンスIDは 0x2FA0 (ソル・デ・バイス), 0x11C1 / 0x2BCF (太陽バンク UI), 0xBF95 (スミレ), 0xC4F1 (ダンジョンタイトル)
// ハッシュ元は「汎用オブジェユニット」に マネージャ / 登録 / 表示 / 非表示 / 移動 / パターン切替 / 反転設定 / 優先設定 を付けたもの, 汎用オブジェ (AuxSprite) に対して MainSprite をオブジェユニットと呼んでいたらしい
typedef struct {
  Entity e;                   // 0x00, ENTITY_UNK_8
  u8 count;                   // 0x18, '.m=1', 確保した枠数
  u8 used;                    // 0x19, 使用中の枠数, Update と Destroy はここまでしか回さない
  GenericObjUnit entries[1];  // 0x1C, 実際は count 個 (可変長)
} GenericObjUnitManager;      // GenericObjUnitManager はサイズが可変
static_assert(sizeof(GenericObjUnitManager) == 216);

COMMON_DATA GenericObjUnitManager* gGenericObjUnitManager = NULL;  // 0x03002C4C

// '.n' と id が一致する枠を返す, 無ければ NULL
GenericObjUnit* GenericObjUnitManager_FindUnit(void) {
  u32 id;
  s32 i;

  if (gGenericObjUnitManager == NULL) {
    return NULL;
  }

  if (!VM_SeekToNamedArg('n')) {
    return NULL;
  }

  id = VM_GetValue();
  for (i = 0; i < gGenericObjUnitManager->used; i++) {
    if (gGenericObjUnitManager->entries[i].id == id) {
      return &gGenericObjUnitManager->entries[i];
    }
  }
  return NULL;
}

// 0x44CD, HashName("汎用オブジェユニットパターン切替")
void Cmd_SetGenericObjUnitPose(void) {
  GenericObjUnit* e = GenericObjUnitManager_FindUnit();

  if (e != NULL && VM_SeekToNamedArg('p')) {
    MainSprite_SetPose(&e->sprite, &e->gfx, VM_GetValue(), PLAYMODE_PAUSE);
  }
}

// 0xED1F, HashName("汎用オブジェユニット反転設定"), '.f' で左右反転を切り替える
void Cmd_SetGenericObjUnitFlip(void) {
  GenericObjUnit* e = GenericObjUnitManager_FindUnit();

  if (e != NULL && VM_SeekToNamedArg('f')) {
    if (VM_GetValue()) {
      e->sprite.flags |= SPRFLAG_XFLIP;
    } else {
      e->sprite.flags &= ~SPRFLAG_XFLIP;
    }
  }
}

// 0xEBFF, HashName("汎用オブジェユニット非表示")
void Cmd_HideGenericObjUnit(void) {
  GenericObjUnit* e = GenericObjUnitManager_FindUnit();

  if (e != NULL) {
    e->sprite.flags |= SPRFLAG_HIDDEN;
    if (e->markerGated != 0) {
      e->hiddenByScript = 1;
    }
  }
}

// 0x9C3F, HashName("汎用オブジェユニット表示")
void Cmd_ShowGenericObjUnit(void) {
  GenericObjUnit* e = GenericObjUnitManager_FindUnit();

  if (e != NULL) {
    e->sprite.flags &= ~SPRFLAG_HIDDEN;
    if (e->markerGated != 0) {
      e->hiddenByScript = 0;
    }
  }
}

// 0x65E1, HashName("汎用オブジェユニット優先設定")
void Cmd_SetGenericObjUnitPriority(void) {
  GenericObjUnit* e = GenericObjUnitManager_FindUnit();

  if (e != NULL && VM_SeekToNamedArg('p')) {
    e->sprite.priority = VM_GetValue();
  }
}

// 0x997B, HashName("汎用オブジェユニット移動"), 現在位置から '.p' の位置へ '.f' フレームかけて移動させる
void Cmd_MoveGenericObjUnit(void) {
  GenericObjUnit* e = GenericObjUnitManager_FindUnit();

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
void GenericObjUnit_Update(GenericObjUnit* p) {
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

// 0xEAB4, HashName("汎用オブジェユニット登録"), 空き枠に '.d' のスプライトを '.p' の位置へ置く, '.n' で番号, '.A' でマーカー連動を指定する
void Cmd_AddGenericObjUnit(void) {
  GenericObjUnit* e;
  MainSpriteGfxFile* f;
  u32 poseIdx;
  SpriteFlags flags;
  u32 prio;
  u32 mode;
  u32 spriteID;

  if (gGenericObjUnitManager == NULL || gGenericObjUnitManager->used >= gGenericObjUnitManager->count) {
    return;
  }

  e = &gGenericObjUnitManager->entries[gGenericObjUnitManager->used];
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
  gGenericObjUnitManager->used++;
}

s32 GenericObjUnitManager_Update(GenericObjUnitManager* p) {
  s32 i;

  for (i = 0; i < p->used; i++) {
    GenericObjUnit_Update(&p->entries[i]);
  }
  return 0;
}

s32 GenericObjUnitManager_Destroy(GenericObjUnitManager* p) {
  s32 i;

  for (i = 0; i < p->used; i++) {
    MainSprite_Remove(&p->entries[i].sprite);
  }
  gGenericObjUnitManager = NULL;
  return 0;
}

s32 GenericObjUnitManager_Init(GenericObjUnitManager* p, u32 id, u32 _, u32 count) {
  p->count = count;
  p->used = 0;
  gGenericObjUnitManager = p;
  return 0;
}

// 0x8AF6, HashName("汎用オブジェユニットマネージャ")
GenericObjUnitManager* GenericObjUnitManager_Create(u32 id, u32 _) {
  if (gGenericObjUnitManager == NULL) {
    u32 count = VM_SeekToNamedArg('m') ? VM_GetValue() : 1;
    GenericObjUnitManager* p = CreateEntity(ENTITY_UNK_8, offsetof(GenericObjUnitManager, entries) + count * sizeof(GenericObjUnit));

    if (p != NULL) {
      SetEntityRoutine(p, GenericObjUnitManager_Update, GenericObjUnitManager_Destroy);
      if (GenericObjUnitManager_Init(p, id, _, count) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gGenericObjUnitManager;
}
