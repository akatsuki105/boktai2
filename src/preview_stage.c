#include "preview_stage.h"

#include "entity.h"
#include "global.h"
#include "random.h"
#include "sprite.h"

// ファイル名, 及び PreviewStage という構造体名はまだ暫定

// 多関節のモデルの5枚のスプライトの並べ方
typedef struct {
  s8 offset[5][2];  // 0x00, [i][0] を pos.x に、[i][1] を pos.y に足して i 番目の器の座標にする
  u16 pose[5];      // 0x0A, i 番目の器に渡す SpriteHolder_SetAnim の第2引数, i == 0 だけ direction 由来の向きを伴う
} PreviewSegments;
static_assert(sizeof(PreviewSegments) == 20);

// 多関節の魔物の節の並べ方, PreviewModel の 9 / 19 / 20 番の onLoad / onUpdate がそれぞれ [0] / [1] / [2] を名指しする
static const PreviewSegments sPreviewSegments[3] = {
    {{{0, -12}, {6, -10}, {12, -2}, {8, 6}, {0, 15}},    {0, 2, 2, 2, 1}},
    {{{-12, 0}, {0, -10}, {10, -1}, {16, 12}, {16, 27}}, {5, 6, 6, 6, 6}},
    {{{-12, 0}, {0, -10}, {10, 0}, {16, 15}, {16, 29}},  {8, 9, 9, 9, 9}},
};  // 0x085AF0B0

// PreviewModel.flags
typedef u8 PreviewModelFlags;
#define DEXFLAG_NO_PLTT (1 << 0)     // 0x01, plttID を SpriteHolder_SetPlttID に渡さない, 立っている件は plttID も 0
#define DEXFLAG_SWAY (1 << 1)        // 0x02, swayAmplitude / swaySpeed で上下にゆれる
#define DEXFLAG_NO_REFRESH (1 << 2)  // 0x04, PreviewStage_Update が毎フレームの向き・ポーズ更新をしない

typedef struct PreviewModel {
  SpriteID16 id;                    // 0x00
  u16 animFileID;                   // 0x02, FUN_08055dac の第3引数, kind == 2 では常に 0 (MainSprite は 自身にアニメーションを持つので、animFileID は不要)
  u16 kind;                         // 0x04, 1: AuxSprite+AuxAnimState, 2: MainSprite
  u16 poseBase;                     // 0x06, PreviewStage.poseBase に控え、SpriteHolder_SetAnim の第2引数になる
  u16 plttID;                       // 0x08, SpriteHolder_SetPlttID に渡すパレットID
  u8 direction;                     // 0x0A, FUN_0820efc4 が (コマ番号, 左右反転) に展開する向き
  PreviewModelFlags flags;          // 0x0B, see PreviewModelFlags
  void (*onLoad)(PreviewStage*);    // 0x0C, 非0なら既定のロード (FUN_0820f9dc) の代わりに呼ぶ
  void (*onUpdate)(PreviewStage*);  // 0x10
  s8 x;                             // 0x14, 表示位置, +64 して pos.x に入る
  s8 y;                             // 0x15, 表示位置, +88 して pos.y に入る
  u8 swayAmplitude;                 // 0x16, ゆれの振幅, sin テーブルとの積を >>13 して y に足す
  u8 swaySpeed;                     // 0x17, ゆれの角速度, 毎フレーム swayAngle に積算し >>5 して角度にする
  s8 subX;                          // 0x18, 追加スプライトの x ずらし, FUN_0820fa80 のみ読む
  s8 subY;                          // 0x19, 追加スプライトの y ずらし, 同上
  u2_6 scaleX;                      // 0x1A, 2.6 固定小数 (64 が等倍)
  u2_6 scaleY;                      // 0x1B, 同上, 全70件で scaleX と同値
  u8 subSprite;                     // 0x1C, 0: 追加スプライトなし, 1/2/3 でメタスプライト 5/6/7 を重ねる
  u8 unused[3];                     // 0x1D, padding?
} PreviewModel;
static_assert(sizeof(PreviewModel) == 32);

static const PreviewModel sPreviewModels[70];

void FUN_08055d7c(SpriteHolder* p);
s32 FUN_08055dac(SpriteHolder* p, u32 spriteID, u32 animFileID, u32 param_4, Vec3* pos);
s32 FUN_08055e34(SpriteHolder* p, u32 spriteID, u32 param_3, Vec3* pos);
void FUN_08055f5c(SpriteHolder* p, u32 param_2);
void FUN_08055f1c(SpriteHolder* p, u32 param_2);
s32 FUN_08055c04(SpriteHolder* p);
s32 FUN_08055d20(SpriteHolder* p);
void FUN_08055ef8(SpriteHolder* p, u32 param_2);

s32 FUN_0820f9dc(PreviewStage* p, s32 modelID);

// 向きの番号を (コマ番号, 左右反転) に展開する, 1..4 は2コマ, 5..13 は5コマのスプライト用の割り当て
void FUN_0820efc4(u8 direction, u8* frameIdx, u8* hFlip) {
  if (direction > 4) {
    u8 dir = direction - 5;

    if (dir > 4) {
      *frameIdx = 8 - dir;
      *hFlip = 1;
    } else {
      *frameIdx = dir;
      *hFlip = 0;
    }
  } else if (direction != 0) {
    u8 dir = direction - 1;

    if (dir == 1 || dir == 2) {
      *frameIdx = 1;
    } else {
      *frameIdx = 0;
    }
    if (dir > 1) {
      *hFlip = 1;
    } else {
      *hFlip = 0;
    }
  } else {
    *frameIdx = 0;
    *hFlip = 0;
  }
}

// ドヴァリンの開帳, アニメが終わるたび poseBase を次の段へ送り、12番まで行ったら state を 1 にして止める
void FUN_0820f020(PreviewStage* p) {
  if (p->state == 0) {
    if (FUN_08055d20(&p->parts[0]) != 0) {
      switch (p->poseBase) {
        case 0: {
          p->poseBase = 1;
          break;
        }
        case 1: {
          p->poseBase = 2;
          break;
        }
        case 2: {
          p->poseBase = 3;
          break;
        }
        case 3: {
          p->poseBase = 4;
          break;
        }
        case 4: {
          p->poseBase = 5;
          break;
        }
        case 5: {
          p->poseBase = 6;
          break;
        }
        case 6: {
          p->poseBase = 12;
          break;
        }
        case 12: {
          p->state = 1;
          break;
        }
      }
    }
    FUN_0820efc4(p->model->direction, &p->frameIdx, &p->hFlip);
    SpriteHolder_SetAnim(&p->parts[0], p->poseBase, p->frameIdx, p->hFlip, 1, 0, 5);
    FUN_08055c04(&p->parts[0]);
  }
}

// スライムの待機, 一定フレームごとに1コマだけ跳ねさせ、次の間隔を乱数で決める
void FUN_0820f130(PreviewStage* p) {
  if (p->swayAngle == 0) {
    p->poseBase = 1;
    FUN_0820efc4(p->model->direction, &p->frameIdx, &p->hFlip);
    SpriteHolder_SetAnim(&p->parts[0], p->poseBase, p->frameIdx, p->hFlip, 1, 0, 5);
    FUN_08055c04(&p->parts[0]);
    if (FUN_08055d20(&p->parts[0]) != 0) {
      p->swayAngle = Mod(Random(), 32) + 60;
    }
  } else {
    p->swayAngle--;
  }
}

// 多関節の節を sPreviewSegments[0] の並びで5つ分作り、節ごとのポーズまで入れる
// 残差はレジスタ割り当てのみ (126 対 132), 原典は ローカルをスタックに多くこぼしている
// Tier A-C 試済: const s8* off / SpriteHolder* の送り / Vec3* 経由のストア / int の一時変数 / 除算の明示 if/else 展開 / 宣言と代入の分離
NON_MATCH void FUN_0820f1e0(PreviewStage* p) {
#ifdef NONMATCHING_C
  const PreviewModel* model;
  SpriteHolder* holder;
  Vec3 buf;
  Vec3* pos = &buf;
  s32 i;

  p->swayAngle = 0;
  model = p->model;
  holder = &p->parts[0];
  for (i = 0; i < 5; i++) {
    const s8* off = sPreviewSegments[0].offset[i];
    s32 x = p->pos.x + off[0];
    s32 y = p->pos.y + off[1];
    s32 z = p->pos.z;

    pos->x = x, pos->y = y, pos->z = z;
    if (FUN_08055dac(holder, model->id, model->animFileID, 16, pos) < 0) {
      break;
    }
    FUN_08055f1c(holder, 1);
    if ((model->flags & DEXFLAG_NO_PLTT) == 0) {
      SpriteHolder_SetPlttID(holder, model->plttID);
    }
    FUN_08055f5c(holder, 2);
    FUN_0820efc4(model->direction, &p->frameIdx, &p->hFlip);
    if (i == 0) {
      SpriteHolder_SetAnim(holder, sPreviewSegments[0].pose[0], p->frameIdx, p->hFlip, 2, 0, 5);
    } else {
      SpriteHolder_SetAnim(holder, sPreviewSegments[0].pose[i], 1, 0, 2, 0, 5);
    }
    FUN_08055c04(holder);
    holder++;
  }
#else
  INCFUNC("asm/func/FUN_0820f1e0.inc");
#endif
}

// 多関節の節を並べ直し、節ごとに振幅を変えて左右にうねらせる
// 残差はレジスタ割り当てのみ (91 対 98, こちらが7命令短い), 原典は &p->pos.x と &p->pos.y をスタックにこぼしている
// Tier A-C 試済: 除算の明示 if/else 展開 (これで /32 と /8192 が一致) / angle += i*32 を独立文に / 乗算の被演算子順 / const s8* off と SpriteHolder* の送り / 加算の遅延 (悪化)
NON_MATCH void FUN_0820f310(PreviewStage* p) {
#ifdef NONMATCHING_C
  SpriteHolder* holder;
  s32 i;

  p->swayAngle += 32;
  holder = &p->parts[0];
  for (i = 0; i < 5; i++) {
    const s8* off = sPreviewSegments[0].offset[i];
    s32 x = p->pos.x + off[0];
    s32 y = p->pos.y + off[1];
    s32 z = p->pos.z;
    Vec3* pos = holder->pos;
    s32 angle;
    s32 sin;

    pos->x = x, pos->y = y, pos->z = z;
    if (p->swayAngle >= 0) {
      angle = p->swayAngle >> 5;
    } else {
      angle = -((-p->swayAngle) >> 5);
    }
    angle += i * 32;
    sin = (8 - i) * gSineTable[angle & 0xFF];
    if (sin >= 0) {
      sin >>= 13;
    } else {
      sin = -((-sin) >> 13);
    }
    holder->pos->x += sin;
    holder++;
  }
#else
  INCFUNC("asm/func/FUN_0820f310.inc");
#endif
}

// 多関節の節を sPreviewSegments[1] の並びで5つ分作る
// 残差はレジスタ割り当てのみ (85 対 93, こちらが8命令短い), 原典は 6つの値を r5-r10 に散らして high レジスタ用の mov を多く挟む
// Tier A-C 試済: Vec3* 経由のストア (bitfield insert が消えた) / int の一時変数 (ldrsh になる) / const s8* off で offset[i] を1本の giv に / SpriteHolder* の送り / 宣言と代入の分離
NON_MATCH void FUN_0820f3e4(PreviewStage* p) {
#ifdef NONMATCHING_C
  const PreviewModel* model;
  SpriteHolder* holder;
  Vec3 buf;
  Vec3* pos = &buf;
  s32 i;

  p->swayAngle = 0;
  model = p->model;
  holder = &p->parts[0];
  for (i = 0; i < 5; i++) {
    const s8* off = sPreviewSegments[1].offset[i];
    s32 x = p->pos.x + off[0];
    s32 y = p->pos.y + off[1];
    s32 z = p->pos.z;

    pos->x = x, pos->y = y, pos->z = z;
    if (FUN_08055dac(holder, model->id, model->animFileID, 16, pos) < 0) {
      break;
    }
    FUN_08055f1c(holder, 1);
    if ((model->flags & DEXFLAG_NO_PLTT) == 0) {
      SpriteHolder_SetPlttID(holder, model->plttID);
    }
    FUN_08055f5c(holder, 2);
    FUN_0820efc4(model->direction, &p->frameIdx, &p->hFlip);
    holder++;
  }
#else
  INCFUNC("asm/func/FUN_0820f3e4.inc");
#endif
}

// 多関節の節を並べ直し、節ごとに振幅を変えて上下にうねらせる (sPreviewSegments[1])
// 残差は 163 対 172, 原典は offset[i][0] と [i][1] を別々のプール定数から引く (こちらは const s8* off の1本にまとまる)
// Tier A-C 試済: const s8* off / SpriteHolder* の送り / Vec3* 経由のストア / int の一時変数 / 除算の明示 if/else 展開 / 宣言と代入の分離
NON_MATCH void FUN_0820f4b4(PreviewStage* p) {
#ifdef NONMATCHING_C
  SpriteHolder* holder;
  s32 i;

  p->swayAngle += 32;
  holder = &p->parts[0];
  for (i = 0; i < 5; i++) {
    const s8* off = sPreviewSegments[1].offset[i];
    Vec3* pos;
    s32 angle;
    s32 sin;

    if (i == 0) {
      SpriteHolder_SetAnim(holder, sPreviewSegments[1].pose[i], p->frameIdx, p->hFlip, 1, 0, 5);
    } else if (i < 2) {
      SpriteHolder_SetAnim(holder, sPreviewSegments[1].pose[i], 0, 0, 1, 0, 5);
    } else if (i < 3) {
      SpriteHolder_SetAnim(holder, sPreviewSegments[1].pose[i], 1, 0, 1, 0, 5);
    } else {
      SpriteHolder_SetAnim(holder, sPreviewSegments[1].pose[i], 2, 0, 1, 0, 5);
    }
    FUN_08055c04(holder);
    pos = p->parts[i].pos;
    pos->x = p->pos.x + off[0], pos->y = p->pos.y + off[1], pos->z = p->pos.z;
    if (p->swayAngle >= 0) {
      angle = p->swayAngle >> 5;
    } else {
      angle = -((-p->swayAngle) >> 5);
    }
    angle += i * 32;
    sin = (8 - i) * gSineTable[angle & 0xFF];
    if (sin >= 0) {
      sin >>= 13;
    } else {
      sin = -((-sin) >> 13);
    }
    p->parts[i].pos->y += sin;
    holder++;
  }
#else
  INCFUNC("asm/func/FUN_0820f4b4.inc");
#endif
}

// 多関節の節を sPreviewSegments[2] の並びで5つ分作る
// 残差はレジスタ割り当てのみ (85 対 93, こちらが8命令短い), 原典は 6つの値を r5-r10 に散らして high レジスタ用の mov を多く挟む
// Tier A-C 試済: Vec3* 経由のストア (bitfield insert が消えた) / int の一時変数 (ldrsh になる) / const s8* off で offset[i] を1本の giv に / SpriteHolder* の送り / 宣言と代入の分離
NON_MATCH void FUN_0820f630(PreviewStage* p) {
#ifdef NONMATCHING_C
  const PreviewModel* model;
  SpriteHolder* holder;
  Vec3 buf;
  Vec3* pos = &buf;
  s32 i;

  p->swayAngle = 0;
  model = p->model;
  holder = &p->parts[0];
  for (i = 0; i < 5; i++) {
    const s8* off = sPreviewSegments[2].offset[i];
    s32 x = p->pos.x + off[0];
    s32 y = p->pos.y + off[1];
    s32 z = p->pos.z;

    pos->x = x, pos->y = y, pos->z = z;
    if (FUN_08055dac(holder, model->id, model->animFileID, 16, pos) < 0) {
      break;
    }
    FUN_08055f1c(holder, 1);
    if ((model->flags & DEXFLAG_NO_PLTT) == 0) {
      SpriteHolder_SetPlttID(holder, model->plttID);
    }
    FUN_08055f5c(holder, 2);
    FUN_0820efc4(model->direction, &p->frameIdx, &p->hFlip);
    holder++;
  }
#else
  INCFUNC("asm/func/FUN_0820f630.inc");
#endif
}

// 多関節の節を並べ直し、節ごとに振幅を変えて上下にうねらせる (sPreviewSegments[2])
// 残差はレジスタ割り当てのみ (123 対 140), 原典は pose の添字を [sp,#0xc] にこぼして誘導変数を3本持つが、こちらは畳んでしまう
// Tier A-C 試済: const s8* off / SpriteHolder* の送り / Vec3* 経由のストア / int の一時変数 / 除算の明示 if/else 展開 / 宣言と代入の分離
NON_MATCH void FUN_0820f700(PreviewStage* p) {
#ifdef NONMATCHING_C
  SpriteHolder* holder;
  s32 i;

  p->swayAngle += 32;
  holder = &p->parts[0];
  for (i = 0; i < 5; i++) {
    const s8* off = sPreviewSegments[2].offset[i];
    Vec3* pos;
    s32 angle;
    s32 sin;

    if (i == 0) {
      SpriteHolder_SetAnim(holder, sPreviewSegments[2].pose[0], p->frameIdx, p->hFlip, 1, 0, 5);
    } else {
      SpriteHolder_SetAnim(holder, sPreviewSegments[2].pose[i], 1, 0, 1, 0, 5);
    }
    FUN_08055c04(holder);
    pos = p->parts[i].pos;
    pos->x = p->pos.x + off[0], pos->y = p->pos.y + off[1], pos->z = p->pos.z;
    if (p->swayAngle >= 0) {
      angle = p->swayAngle >> 5;
    } else {
      angle = -((-p->swayAngle) >> 5);
    }
    angle += i * 32;
    sin = (8 - i) * gSineTable[angle & 0xFF];
    if (sin >= 0) {
      sin >>= 13;
    } else {
      sin = -((-sin) >> 13);
    }
    p->parts[i].pos->y += sin;
    holder++;
  }
#else
  INCFUNC("asm/func/FUN_0820f700.inc");
#endif
}

void FUN_0820f840(PreviewStage* p) { FUN_0820f9dc(p, p->modelID); }

// 宝箱のふたが開く演出, ふたを持ち上げて中身を見せ、30フレーム待って閉じ直す
void FUN_0820f84c(PreviewStage* p) {
  const PreviewModel* model;
  u32 timer = p->stateTimer;
  bool32 first = timer == 0;
  bool32 done;

  p->stateTimer = timer + 1;
  model = p->model;
  switch (p->state) {
    case 0: {
      if (first) {
        FUN_0820efc4(model->direction, &p->frameIdx, &p->hFlip);
        SpriteHolder_SetAnim(&p->parts[0], 1, p->frameIdx, p->hFlip, 2, 0, 4);
      }
      done = FUN_08055c04(&p->parts[0]);
      if (done) {
        p->stateTimer = 0;
        p->state = 1;
      }
      break;
    }
    case 1: {
      if (first) {
        FUN_0820efc4(model->direction, &p->frameIdx, &p->hFlip);
        SpriteHolder_SetAnim(&p->parts[0], 2, p->frameIdx, p->hFlip, 2, 0, 4);
      }
      done = FUN_08055c04(&p->parts[0]);
      if (p->stateTimer <= 11) {
        p->parts[0].pos->y--;
      } else {
        p->parts[0].pos->y++;
      }
      if (done) {
        p->stateTimer = 0;
        p->state = 2;
      }
      break;
    }
    case 2: {
      if (first) {
        FUN_0820efc4(model->direction, &p->frameIdx, &p->hFlip);
        SpriteHolder_SetAnim(&p->parts[0], 3, p->frameIdx, p->hFlip, 2, 0, 4);
        *p->parts[0].pos = p->pos;
      }
      done = FUN_08055c04(&p->parts[0]);
      if (done) {
        p->stateTimer = 0;
        p->state = 3;
      }
      break;
    }
    case 3: {
      if (p->stateTimer > 30) {
        p->stateTimer = 0;
        p->state = 0;
      }
      break;
    }
  }
}

// 既定のロード, 器を1つだけ作って位置・パレット・向きを入れる
s32 FUN_0820f9dc(PreviewStage* p, s32 modelID) {
  SpriteHolder* holder = &p->parts[0];
  const PreviewModel* model = &sPreviewModels[modelID];
  s32 ret;

  if (p->posOverridden == 0) {
    s32 x = model->x;
    s32 y = model->y;
    Vec3* pos = &p->pos;

    x += 64, y += 84;
    pos->x = x, pos->y = y, pos->z = 0, pos->val = 0;
  }
  if (model->kind == 2) {
    ret = FUN_08055e34(holder, model->id, 16, &p->pos);
  } else {
    ret = FUN_08055dac(holder, model->id, model->animFileID, 16, &p->pos);
  }
  if (ret < 0) {
    return -1;
  }
  if ((model->flags & DEXFLAG_NO_PLTT) == 0) {
    SpriteHolder_SetPlttID(holder, model->plttID);
  }
  FUN_08055f5c(holder, 2);
  FUN_0820efc4(model->direction, &p->frameIdx, &p->hFlip);
  return 0;
}

// 重ね絵のメタスプライト・座標・拡大率を本体に合わせる
void FUN_0820fa80(PreviewStage* p, s32 subSprite) {
  switch (subSprite) {
    case 1: {
      AuxSprite_SetPoseIdx(&p->subSprite, 5);
      break;
    }
    case 2: {
      AuxSprite_SetPoseIdx(&p->subSprite, 6);
      break;
    }
    case 3: {
      AuxSprite_SetPoseIdx(&p->subSprite, 7);
      break;
    }
  }
  p->subSprite.pos.x = p->parts[0].pos->x + p->model->subX;
  p->subSprite.pos.y = p->pos.y + p->model->subY;
  p->subSprite.pos.z = p->parts[0].pos->z;
  p->subSprite.scaleX = p->model->scaleX;
  p->subSprite.scaleY = p->model->scaleY;
}

// modelID から model を引き直し、器を全部捨てて位置と poseBase を入れ直してからロードし直す
void PreviewStage_Update_Helper_0820fb20(PreviewStage* p) {
  const PreviewModel* model = &sPreviewModels[p->modelID];
  s32 i;

  p->model = model;
  for (i = 0; i < 5; i++) {
    if (p->parts[i].kind != 0) {
      FUN_08055d7c(&p->parts[i]);
    }
  }
  p->poseBase = model->poseBase;
  if (p->posOverridden == 0) {
    s32 x = model->x;
    s32 y = model->y;
    Vec3* pos = &p->pos;

    x += 64, y += 84;
    pos->x = x, pos->y = y, pos->z = 0, pos->val = 0;
  }
  if (model->onLoad == NULL) {
    FUN_0820f9dc(p, p->modelID);
  } else {
    model->onLoad(p);
  }
}

// 隠されていれば器を全部隠して抜け、そうでなければ model を引き直してロード・向き・ゆれ・重ね絵を更新する
// 原典は通常経路で return を書き忘れていて r0 を設定しないまま戻る (hidden の経路だけ 0 を返す)
// 残差はレジスタ割り当てのみ (202 対 202, 命令列は完全一致), 原典は 0xC3<<2 等のスクラッチに r1/r0/r3 を使うがこちらは r4 を使う
// Tier A-C 試済: 除算の明示 if/else 展開 / angle のその場シフト (悪化) / 乗算の被演算子順 (悪化) / angle・d の関数スコープ化 / AuxSprite_Show,Hide 経由 / 宣言順の入れ替え / arg6 に noRefresh を明示
NON_MATCH s32 PreviewStage_Update(PreviewStage* p) {
#ifdef NONMATCHING_C
  const PreviewModel* model;
  PreviewModelFlags noRefresh;
  s32 angle;
  s32 d;
  s32 i;

  if (p->hidden) {
    for (i = 0; i < 5; i++) {
      if (p->parts[i].kind != 0) {
        FUN_08055ef8(&p->parts[i], 1);
      }
    }
    p->subSprite.flags |= SPRFLAG_HIDDEN;
    return 0;
  }
  for (i = 0; i < 5; i++) {
    if (p->parts[i].kind != 0) {
      FUN_08055f1c(&p->parts[i], 1);
    }
  }
  p->subSprite.flags &= ~SPRFLAG_HIDDEN;
  model = &sPreviewModels[p->modelID];
  p->model = model;
  if (p->reloadRequested) {
    p->swayAngle = 0;
    p->stateTimer = 0;
    p->state = 0;
    PreviewStage_Update_Helper_0820fb20(p);
  }
  if (model->onUpdate != NULL) {
    model->onUpdate(p);
  }
  noRefresh = model->flags & DEXFLAG_NO_REFRESH;
  if (noRefresh == 0) {
    FUN_0820efc4(model->direction, &p->frameIdx, &p->hFlip);
    SpriteHolder_SetAnim(&p->parts[0], p->poseBase, p->frameIdx, p->hFlip, 1, 0, 5);
    FUN_08055c04(&p->parts[0]);
  }
  if (model->flags & DEXFLAG_SWAY) {
    p->swayAngle += model->swaySpeed;
    if (p->swayAngle >= 0) {
      angle = p->swayAngle >> 5;
    } else {
      angle = -((-p->swayAngle) >> 5);
    }
    angle += 128;
    d = model->swayAmplitude * gSineTable[angle & 0xFF];
    if (d >= 0) {
      d >>= 13;
    } else {
      d = -((-d) >> 13);
    }
    p->parts[0].pos->y = p->pos.y + d;
  }
  if (model->subSprite == 0) {
    p->subSprite.flags |= SPRFLAG_HIDDEN;
  } else {
    p->subSprite.flags &= ~SPRFLAG_HIDDEN;
    FUN_0820fa80(p, model->subSprite);
  }
  p->reloadRequested = 0;
#else
  INCFUNC("asm/func/PreviewStage_Update.inc");
#endif
}

s32 PreviewStage_Destroy(PreviewStage* p) {
  s32 i;

  for (i = 0; i < 5; i++) {
    if (p->parts[i].kind != 0) {
      FUN_08055d7c(&p->parts[i]);
    }
  }
  AuxSprite_Remove(&p->subSprite);
  return 0;
}

// 第2引数は読まれず, modelID は 0 固定で始まる (直後の > 56 の判定も死んでいる)
// 残差は CpuFill32 の引数を置く順の1命令だけ (75 対 75), 原典は mov r0,sp が ldr r2,=0x05000002 より前
// 引数の綴り (マクロ / 手書き CpuSet / 定数リテラル / vu32 と u32) では動かず, 一致済みの FUN_0823a76c も同じ順なので原典だけが逆
NON_MATCH s32 PreviewStage_Init(PreviewStage* p, u32 _) {
#ifdef NONMATCHING_C
  p->modelID = 0;
  p->reloadRequested = 0;
  p->hidden = 0;
  if (p->modelID > 56) {
    p->modelID = 0;
  }
  FUN_0820f9dc(p, p->modelID);
  Video_GetAuxSprite(&p->subSpriteGfx, SPRITE_EFF_1C1B);
  AuxSprite_Add(&p->subSprite, &p->subSpriteGfx, SPRFLAG_AFFINE | SPRFLAG_SCREEN_COORD | SPRFLAG_BLINK_ODD);
  AuxSprite_SetPoseIdx(&p->subSprite, 5);
  p->subSprite.priority = 3;
  p->subSprite.pos.x = p->pos.x;
  p->subSprite.pos.y = p->pos.y;
  p->subSprite.pos.z = p->pos.y;
  p->subSprite.scaleX = 128;
  p->subSprite.scaleY = 64;
  p->swayAngle = 0;
  p->posOverridden = 0;
  CpuFill32(0, &p->pos, sizeof(Vec3));
  return 0;
#else
  INCFUNC("asm/func/PreviewStage_Init.inc");
#endif
}

PreviewStage* PreviewStage_Create(u32 arg, u32 _) {
  PreviewStage* p = CreateEntity(ENTITY_UNK_8, sizeof(PreviewStage));
  if (p != NULL) {
    SetEntityRoutine(p, PreviewStage_Update, PreviewStage_Destroy);
    if (PreviewStage_Init(p, arg) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

void FUN_0820fe94(PreviewStage* p, u32 val) { p->posOverridden = val; }

void FUN_0820fe98(PreviewStage* p, u32 modelID) {
  p->modelID = modelID;
  p->reloadRequested = 1;
}

void FUN_0820fea8(PreviewStage* p) { p->hidden = 1; }

void FUN_0820feb0(PreviewStage* p) { p->hidden = 0; }

void FUN_0820feb8(PreviewStage* p, s32 x, s32 y) {
  p->pos.x = x;
  p->pos.y = y;
  p->pos.z = 0;
}

// エンディングのスタッフロールでは クレジットと一緒にゲーム中に登場したキャラクター(主人公,NPC,ボス,雑魚)が表示されるが、ここに魔物図鑑での魔物表示と同じ処理を使っているのかもしれない
// それならば、0..56 までは魔物図鑑とスタッフロール共用で、 57以降はスタッフロールのためのものかも
static const PreviewModel sPreviewModels[70] = {
    {SPRITE_SPIDER,         ANIM_SPIDER,     1, 3,   143, 3,  0,                                    NULL,         NULL,         0,  0,   0,  0,  0,  4,  50, 50, 0}, // 0
    {SPRITE_SPIDER,         ANIM_SPIDER,     1, 3,   144, 3,  0,                                    NULL,         NULL,         0,  0,   0,  0,  0,  4,  50, 50, 0}, // 1
    {SPRITE_BEE,            ANIM_BEE,        1, 1,   176, 3,  DEXFLAG_SWAY,                         NULL,         NULL,         0,  0,   10, 32, 0,  16, 32, 32, 1}, // 2
    {SPRITE_BEE,            ANIM_BEE,        1, 1,   178, 3,  DEXFLAG_SWAY,                         NULL,         NULL,         0,  0,   10, 32, 0,  16, 32, 32, 1}, // 3
    {SPRITE_BEE,            ANIM_BEE,        1, 1,   177, 3,  DEXFLAG_SWAY,                         NULL,         NULL,         0,  0,   10, 32, 0,  16, 32, 32, 1}, // 4
    {SPRITE_BAT,            ANIM_BAT,        1, 0,   610, 3,  DEXFLAG_SWAY,                         NULL,         NULL,         0,  0,   10, 32, 0,  16, 32, 32, 1}, // 5
    {SPRITE_BAT,            ANIM_BAT,        1, 0,   611, 3,  DEXFLAG_SWAY,                         NULL,         NULL,         0,  0,   10, 32, 0,  16, 32, 32, 1}, // 6
    {SPRITE_CROW,           ANIM_CROW,       1, 0,   332, 3,  DEXFLAG_SWAY,                         NULL,         NULL,         0,  0,   10, 32, 0,  16, 32, 32, 1}, // 7
    {SPRITE_CROW,           ANIM_CROW,       1, 0,   333, 3,  DEXFLAG_SWAY,                         NULL,         NULL,         0,  0,   10, 32, 0,  16, 32, 32, 1}, // 8
    {SPRITE_WORM,           ANIM_WORM,       1, 0,   417, 10, DEXFLAG_NO_REFRESH,                   FUN_0820f1e0, FUN_0820f310, 0,  0,   0,  0,  0,  16, 64, 64, 0}, // 9
    {SPRITE_DOG,            ANIM_DOG,        1, 3,   501, 3,  0,                                    NULL,         NULL,         0,  8,   0,  0,  0,  0,  64, 64, 1}, // 10
    {SPRITE_DOG,            ANIM_DOG,        1, 3,   503, 3,  0,                                    NULL,         NULL,         0,  8,   0,  0,  0,  0,  64, 64, 1}, // 11
    {SPRITE_DOG,            ANIM_DOG,        1, 3,   502, 3,  0,                                    NULL,         NULL,         0,  8,   0,  0,  0,  0,  64, 64, 1}, // 12
    {SPRITE_DOG,            ANIM_DOG,        1, 3,   505, 3,  0,                                    NULL,         NULL,         0,  8,   0,  0,  0,  0,  64, 64, 1}, // 13
    {SPRITE_ROD,            ANIM_DARKROOT,   1, 0,   220, 0,  0,                                    NULL,         NULL,         0,  16,  0,  0,  0,  0,  0,  0,  0}, // 14
    {SPRITE_SHAIAN,         0x0000,          2, 12,  626, 3,  0,                                    NULL,         NULL,         8,  24,  0,  0,  -2, -3, 64, 64, 2}, // 15
    {SPRITE_OCTOPUS,        ANIM_OCTOPUS,    1, 0,   447, 0,  0,                                    NULL,         NULL,         0,  16,  0,  0,  0,  0,  0,  0,  0}, // 16
    {SPRITE_COCKATRICE,     ANIM_COCKATRICE, 1, 2,   506, 3,  0,                                    NULL,         NULL,         0,  8,   0,  0,  0,  6,  64, 64, 1}, // 17
    {SPRITE_COCKATRICE,     ANIM_COCKATRICE, 1, 8,   507, 3,  DEXFLAG_SWAY,                         NULL,         NULL,         4,  0,   10, 64, 0,  16, 64, 64, 1}, // 18
    {SPRITE_WORM,           ANIM_WORM,       1, 5,   418, 10, 0,                                    FUN_0820f3e4, FUN_0820f4b4, 0,  0,   0,  0,  0,  32, 64, 64, 0}, // 19
    {SPRITE_WORM,           ANIM_WORM,       1, 8,   419, 10, 0,                                    FUN_0820f630, FUN_0820f700, 0,  0,   0,  0,  0,  0,  0,  0,  0}, // 20
    {SPRITE_BOKU,           ANIM_1DF8,       1, 8,   307, 3,  0,                                    NULL,         NULL,         0,  16,  0,  0,  0,  0,  64, 64, 1}, // 21
    {SPRITE_BOKU,           ANIM_1DF8,       1, 8,   308, 3,  0,                                    NULL,         NULL,         0,  16,  0,  0,  0,  0,  64, 64, 1}, // 22
    {SPRITE_BOKU,           ANIM_1DF8,       1, 8,   309, 3,  0,                                    NULL,         NULL,         0,  16,  0,  0,  0,  0,  64, 64, 1}, // 23
    {SPRITE_MUMMY,          ANIM_MUMMY,      1, 1,   23,  3,  0,                                    NULL,         NULL,         0,  16,  0,  0,  0,  0,  64, 64, 1}, // 24
    {SPRITE_MUMMY,          ANIM_MUMMY,      1, 1,   24,  3,  0,                                    NULL,         NULL,         0,  16,  0,  0,  0,  0,  64, 64, 1}, // 25
    {SPRITE_MUMMY,          ANIM_MUMMY,      1, 1,   25,  3,  0,                                    NULL,         NULL,         0,  16,  0,  0,  0,  0,  64, 64, 1}, // 26
    {SPRITE_SKELETONS,      0x0000,          2, 6,   247, 3,  0,                                    NULL,         NULL,         0,  16,  0,  0,  0,  1,  64, 64, 1}, // 27
    {SPRITE_SKELETONS,      0x0000,          2, 8,   247, 3,  0,                                    NULL,         NULL,         0,  16,  0,  0,  0,  1,  64, 64, 1}, // 28
    {SPRITE_SKELETONS,      0x0000,          2, 10,  247, 3,  0,                                    NULL,         NULL,         0,  16,  0,  0,  0,  1,  64, 64, 1}, // 29
    {SPRITE_SKELETONS,      0x0000,          2, 6,   252, 3,  0,                                    NULL,         NULL,         0,  16,  0,  0,  0,  1,  64, 64, 1}, // 30
    {SPRITE_SKELETONS,      0x0000,          2, 26,  249, 3,  0,                                    NULL,         NULL,         8,  16,  0,  0,  0,  1,  64, 64, 1}, // 31
    {SPRITE_SKELETONS,      0x0000,          2, 26,  255, 3,  0,                                    NULL,         NULL,         8,  16,  0,  0,  0,  1,  64, 64, 1}, // 32
    {SPRITE_GOLEM,          ANIM_1E38,       1, 1,   513, 3,  0,                                    NULL,         NULL,         0,  8,   0,  0,  0,  4,  64, 64, 1}, // 33
    {SPRITE_GOLEM,          ANIM_1E38,       1, 1,   514, 3,  0,                                    NULL,         NULL,         0,  8,   0,  0,  0,  4,  64, 64, 1}, // 34
    {SPRITE_GOLEM,          ANIM_1E38,       1, 1,   516, 3,  0,                                    NULL,         NULL,         0,  8,   0,  0,  0,  4,  64, 64, 1}, // 35
    {SPRITE_MIMIC,          ANIM_MIMIC,      1, 1,   650, 4,  DEXFLAG_NO_REFRESH,                   FUN_0820f840, FUN_0820f84c, 0,  16,  0,  0,  0,  4,  64, 64, 1}, // 36
    {SPRITE_SWORD_AX,       ANIM_SWORDAX,    1, 0,   301, 0,  DEXFLAG_SWAY | DEXFLAG_NO_REFRESH,    NULL,         NULL,         0,  2,   8,  40, 0,  28, 32, 32, 1}, // 37
    {SPRITE_SWORD_AX,       ANIM_SWORDAX,    1, 0,   302, 0,  DEXFLAG_SWAY | DEXFLAG_NO_REFRESH,    NULL,         NULL,         0,  2,   8,  40, 0,  28, 32, 32, 1}, // 38
    {SPRITE_SWORD_AX,       ANIM_SWORDAX,    1, 1,   301, 0,  DEXFLAG_SWAY,                         NULL,         NULL,         0,  8,   10, 40, 0,  24, 32, 32, 1}, // 39
    {SPRITE_SWORD_AX,       ANIM_SWORDAX,    1, 1,   302, 0,  DEXFLAG_SWAY,                         NULL,         NULL,         0,  8,   10, 40, 0,  24, 32, 32, 1}, // 40
    {SPRITE_CURORO,         ANIM_CURORO,     1, 0,   92,  10, DEXFLAG_SWAY,                         NULL,         NULL,         0,  -8,  20, 32, 0,  24, 32, 32, 1}, // 41
    {SPRITE_CURORO,         ANIM_CURORO,     1, 0,   93,  10, DEXFLAG_SWAY,                         NULL,         NULL,         0,  -8,  20, 32, 0,  24, 32, 32, 1}, // 42
    {SPRITE_CURORO,         ANIM_CURORO,     1, 0,   94,  10, DEXFLAG_SWAY,                         NULL,         NULL,         0,  -8,  20, 32, 0,  24, 32, 32, 1}, // 43
    {SPRITE_SLIME,          ANM_SLIME,       1, 1,   147, 3,  DEXFLAG_NO_REFRESH,                   NULL,         FUN_0820f130, 0,  8,   0,  0,  0,  8,  32, 32, 0}, // 44
    {SPRITE_SLIME,          ANM_SLIME,       1, 1,   148, 3,  DEXFLAG_NO_REFRESH,                   NULL,         FUN_0820f130, 0,  8,   0,  0,  0,  8,  32, 32, 0}, // 45
    {SPRITE_SLIME,          ANM_SLIME,       1, 1,   149, 3,  DEXFLAG_NO_REFRESH,                   NULL,         FUN_0820f130, 0,  8,   0,  0,  0,  8,  32, 32, 0}, // 46
    {SPRITE_SLIME,          ANM_SLIME,       1, 1,   150, 3,  DEXFLAG_NO_REFRESH,                   NULL,         FUN_0820f130, 0,  8,   0,  0,  0,  8,  32, 32, 0}, // 47
    {SPRITE_GHOST,          ANIM_GHOST,      1, 0,   381, 10, DEXFLAG_SWAY,                         NULL,         NULL,         0,  0,   20, 32, 0,  24, 64, 64, 1}, // 48
    {SPRITE_GHOST,          ANIM_GHOST,      1, 0,   382, 10, DEXFLAG_SWAY,                         NULL,         NULL,         0,  0,   20, 32, 0,  24, 64, 64, 1}, // 49
    {SPRITE_DUNEYRR,        0x0000,          2, 0,   0,   0,  DEXFLAG_NO_PLTT | DEXFLAG_SWAY,       NULL,         NULL,         0,  0,   8,  32, 0,  0,  0,  0,  0}, // 50
    {SPRITE_RINGO,          0x0000,          2, 3,   0,   4,  DEXFLAG_NO_PLTT | DEXFLAG_SWAY,       NULL,         NULL,         4,  16,  8,  32, 0,  8,  64, 64, 2}, // 51
    {SPRITE_DURATHROR,      0x0000,          2, 0,   0,   0,  DEXFLAG_NO_PLTT | DEXFLAG_NO_REFRESH, NULL,         FUN_0820f020, 0,  16,  0,  0,  0,  0,  0,  0,  0}, // 52
    {SPRITE_DVALINN,        0x0000,          2, 0,   0,   3,  DEXFLAG_NO_PLTT | DEXFLAG_SWAY,       NULL,         NULL,         0,  15,  8,  32, 0,  0,  0,  0,  0}, // 53
    {SPRITE_RINGO,          0x0000,          2, 8,   0,   4,  DEXFLAG_NO_PLTT | DEXFLAG_SWAY,       NULL,         NULL,         4,  16,  8,  32, 0,  8,  64, 64, 2}, // 54
    {SPRITE_JORMUNGANDR,    0x0000,          2, 0,   0,   0,  DEXFLAG_NO_PLTT | DEXFLAG_SWAY,       NULL,         NULL,         24, -24, 8,  32, 0,  0,  0,  0,  0}, // 55
    {SPRITE_SHADEMAN,       0x0000,          2, 0,   0,   10, DEXFLAG_NO_PLTT | DEXFLAG_SWAY,       NULL,         NULL,         0,  16,  8,  32, 0,  8,  64, 64, 2}, // 56
    {SPRITE_DJANGO_SABATA,  0x0000,          2, 5,   29,  10, 0,                                    NULL,         NULL,         0,  0,   0,  0,  0,  2,  64, 64, 1}, // 57
    {SPRITE_OTENKO_00,      ANIM_OTENKO,     1, 0,   0,   10, DEXFLAG_NO_PLTT | DEXFLAG_SWAY,       NULL,         NULL,         0,  0,   8,  32, 0,  8,  64, 64, 1}, // 58
    {SPRITE_DJANGO_SABATA,  0x0000,          2, 419, 39,  10, 0,                                    NULL,         NULL,         0,  0,   0,  0,  0,  2,  64, 64, 1}, // 59
    {SPRITE_RITA,           0x0000,          2, 5,   0,   3,  DEXFLAG_NO_PLTT,                      NULL,         NULL,         0,  0,   0,  0,  0,  2,  64, 64, 1}, // 60
    {SPRITE_ZAJI,           0x0000,          2, 5,   0,   3,  DEXFLAG_NO_PLTT,                      NULL,         NULL,         0,  0,   0,  0,  0,  2,  64, 64, 1}, // 61
    {SPRITE_SHAIAN,         0x0000,          2, 14,  0,   3,  DEXFLAG_NO_PLTT,                      NULL,         NULL,         8,  24,  0,  0,  -2, -3, 64, 64, 2}, // 62
    {SPRITE_LADY,           0x0000,          2, 7,   0,   3,  DEXFLAG_NO_PLTT,                      NULL,         NULL,         0,  0,   0,  0,  0,  2,  64, 64, 1}, // 63
    {SPRITE_COFFIN,         ANIM_COFFIN,     1, 32,  524, 10, 0,                                    NULL,         NULL,         0,  0,   0,  0,  0,  2,  64, 64, 1}, // 64
    {SPRITE_SHADEMAN,       0x0000,          2, 0,   15,  10, DEXFLAG_SWAY,                         NULL,         NULL,         0,  0,   8,  32, 0,  8,  64, 64, 2}, // 65
    {SPRITE_KID,            0x0000,          2, 7,   0,   3,  DEXFLAG_NO_PLTT,                      NULL,         NULL,         0,  0,   0,  0,  0,  2,  64, 64, 1}, // 66
    {SPRITE_SUMIRE,         0x0000,          2, 5,   0,   3,  DEXFLAG_NO_PLTT,                      NULL,         NULL,         0,  0,   0,  0,  0,  2,  64, 64, 1}, // 67
    {SPRITE_SMITH_MARCELLO, 0x0000,          2, 7,   0,   3,  DEXFLAG_NO_PLTT,                      NULL,         NULL,         0,  0,   0,  0,  0,  2,  64, 64, 1}, // 68
    {SPRITE_DJANGO_SABATA,  0x0000,          2, 204, 38,  10, 0,                                    NULL,         NULL,         0,  0,   0,  0,  0,  2,  64, 64, 1}, // 69
};  // 0x085AF0EC
