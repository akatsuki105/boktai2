#include "enemy.h"

#include "collision_map.h"
#include "eff_082473e0.h"
#include "enemy_manager.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "inventory.h"
#include "item.h"
#include "player.h"
#include "random.h"
#include "video.h"
#include "vm.h"

// 原典のファイル名は enemy.c, 根拠: FUN_080e6794 / FUN_080e6834 / FUN_080e68d8 が、抜き取られた assert の引数として文字列 "enemy.c" (0x08251F60) と行番号をレジスタに積んでから Enemy_ClearPendingState を呼ぶ
// 引数の個数と void/値返しはアセンブリから機械的に出したもの, 型は第1引数が Enemy だと言えるものだけ Enemy*, 残りは未解析の unknown*

const s16 s16_ARRAY_085ad3c4[4] = {8, 4, 2};  // 0x085AD3C4

const s16 s16_ARRAY_085ad3cc[4] = {1600, 0, 1600};  // 0x085AD3CC

extern const char s_enemy_c_08251f60[];  // "enemy.c"

s32 FUN_08240b98(u8* param_1, s8 param_2);
void EnemyTargetManager_Release(EnemyTarget* node);
EnemyTarget* EnemyTargetManager_FindByKind(u32 kindMask);

NAKED s32 FUN_080e191c(Enemy* p) { INCFUNC("asm/func/FUN_080e191c.inc"); }

NAKED s32 FUN_080e1f48(Enemy* p) { INCFUNC("asm/func/FUN_080e1f48.inc"); }

NAKED s32 FUN_080e35b4(Enemy* p) { INCFUNC("asm/func/FUN_080e35b4.inc"); }

// 状態ハンドラに渡す引数と、スプライトの種類を差し替える
void FUN_080e37e8(Enemy* p, void* arg, u8 spriteKind) {
  p->unk_1cc = arg;
  p->spriteKind = spriteKind;
}

// AuxSprite 系のエネミーにアニメーションファイルを読み込ませて先頭から再生する
void FUN_080e3804(EnemyAuxSpriteData* p, s32 animID) {
  FileID id = animID;
  AuxAnimFile* f = GetFile(DIR_ANIMATION, id);

  p->animFile = f;
  AuxAnim_SetAnim(&p->anim, f, 0, 0, 0);
}

// 自前の Hitbox を固定フラグで組んで登録する
void FUN_080e3834(Enemy* p, Vec3* halfSize, Vec3* offset, void* handler, void* owner) {
  Hitbox_Init(&p->hitbox, p->mover.id, (HBFLAG_UNK_14 | HBFLAG_UNK_12 | HBFLAG_UNK_8 | HBFLAG_UNK_3 | HBFLAG_UNK_0), 0, 0x10, halfSize, offset);
  Hitbox_SetPowerAndAttributes(&p->hitbox, p->power, p->attrs, p->weakness);
  Hitbox_SetPos(&p->hitbox, &p->mover.pos, 0);
  Hitbox_SetHandler(&p->hitbox, handler, owner);
  Hitbox_Register(&p->hitbox);
}

// 自前の Hitbox をフラグ指定で組んで登録する
void Enemy_RegisterOwnHitbox(Enemy* p, Vec3* halfSize, Vec3* offset, void* handler, void* owner, HitboxFlags32 flags) {
  Hitbox_Init(&p->hitbox, p->mover.id, (u16)flags, 0, 0x10, halfSize, offset);
  Hitbox_SetPowerAndAttributes(&p->hitbox, p->power, p->attrs, p->weakness);
  Hitbox_SetPos(&p->hitbox, &p->mover.pos, 0);
  Hitbox_SetHandler(&p->hitbox, handler, owner);
  Hitbox_Register(&p->hitbox);
}

// 敵の攻撃力と属性を載せた Hitbox を組んで登録する
void Enemy_RegisterHitbox(Enemy* p, HitboxData* hitbox, Vec3* halfSize, Vec3* offset, void* handler, void* owner, HitboxFlags32 flags) {
  Hitbox_Init(hitbox, p->mover.id, (u16)flags, 0, 0x10, halfSize, offset);
  Hitbox_SetPowerAndAttributes(hitbox, p->power, p->attrs, p->weakness);
  Hitbox_SetPos(hitbox, &p->mover.pos, 0);
  Hitbox_SetHandler(hitbox, handler, owner);
  Hitbox_Register(hitbox);
}

// 攻撃判定を組む, 攻撃パラメータは idx 番目の atk テーブルから取る (登録はしない)
void Enemy_InitAtkHitbox(Enemy* p, Vec3* halfSize, Vec3* offset, void* handler, s32 idx, void* owner) {
  HitboxFlags32 flags = HBFLAG_UNK_13 | HBFLAG_UNK_10 | HBFLAG_UNK_0;

  Hitbox_Init(&p->atkHitbox, p->mover.id, flags, 0, 0x10, halfSize, offset);
  Hitbox_SetAttack(&p->atkHitbox, p->atkPower[idx], p->atkUnk40[idx], 0, p->atkAttrs[idx], p->atkUnk44[idx]);
  Hitbox_SetPos(&p->atkHitbox, &p->mover.pos, 0);
  Hitbox_SetHandler(&p->atkHitbox, handler, owner);
}

// index 番目の攻撃データを載せた Hitbox を組む (登録はしない)
void FUN_080e3a14(Enemy* p, HitboxData* hitbox, Vec3* halfSize, Vec3* offset, void* handler, s32 index, void* owner) {
  HitboxFlags32 flags = HBFLAG_UNK_13 | HBFLAG_UNK_0;

  Hitbox_Init(hitbox, p->mover.id, flags, 0, 0x10, halfSize, offset);
  Hitbox_SetAttack(hitbox, p->atkPower[index], p->atkUnk40[index], 0, p->atkAttrs[index], p->atkUnk44[index]);
  Hitbox_SetPos(hitbox, &p->mover.pos, 0);
  Hitbox_SetHandler(hitbox, handler, owner);
}

// 3つの距離しきい値を二乗つきで設定する, 第2引数は読まれない
void Enemy_SetRanges(Enemy* p, s32 unused, u16 range0, u16 range1, u16 range2, u8 param_6) {
  p->playerMover = NULL;
  p->range0 = range0;
  p->range1 = range1;
  p->range2 = range2;
  p->range0Sq = range0 * range0;
  p->range1Sq = range1 * range1;
  p->range2Sq = p->range2 * p->range2;
  p->unk_1fd = param_6;
}

NAKED s32 FUN_080e3afc(s32 param_1, s32 param_2, unknown* param_3) { INCFUNC("asm/func/FUN_080e3afc.inc"); }

NAKED s32 FUN_080e3cc8(unknown* param_1, s32 param_2, s32 param_3) { INCFUNC("asm/func/FUN_080e3cc8.inc"); }

// a と b の距離をブロック数に直して FUN_080e3cc8 に渡し, 結果が expected と違うかどうかを返す
bool32 FUN_080e3ed8(Vec3* a, Vec3* b, s32 kind, s32 expected) {
  s32 d;
  s32 n;

  switch (kind) {
    case 0:
    case 2: {
      d = a->x - b->x;
      if (d < 0) {
        d = -d;
      }
      n = Div256(d + 0x80) + 1;
      break;
    }
    case 1:
    case 3: {
      d = a->z - b->z;
      if (d < 0) {
        d = -d;
      }
      n = Div256(d + 0x80) + 1;
      break;
    }
    default: {
      n = 0;
      break;
    }
  }

  if (FUN_080e3cc8(a, kind, n) != expected) {
    return TRUE;
  }
  return FALSE;
}

NAKED s32 FUN_080e3f50(Enemy* p, unknown* param_2, unknown* param_3) { INCFUNC("asm/func/FUN_080e3f50.inc"); }

// pos が unk_256 のタイルの上にあり, かつ自分の向きから ±0x30 以内の方角にいるか
// 残差は84/85命令, 原典は差分バッファの sp のコピーを2本持つ
// Tier A-C 試済 (s16[3]/Vec3, mover.pos のローカル化と位置)
NON_MATCH bool32 FUN_080e4384(Enemy* p, Vec3* pos) {
#ifdef NONMATCHING_C
  Vec3* mpos = &p->mover.pos;
  s16 d[3];
  s32 bx = (s8)(pos->x >> 8);
  s32 bz = (s8)(pos->z >> 8);
  u32 idx;
  s32 diff;

  if (bx < 0 || bz < 0 || (u32)bx >= (u32)gMapBlockW || (u32)bz >= (u32)gMapBlockH) {
    idx = 0;
  } else {
    idx = gCollisionMap->rowOffsets[bz] + bx;
  }

  if (p->unk_256 != idx) {
    return FALSE;
  }

  d[0] = pos->x - p->mover.pos.x;
  d[1] = pos->y - mpos->y;
  d[2] = pos->z - mpos->z;

  diff = ArcTan2_8(d[0], d[2]) - p->mover.angle;
  if (diff > 0x80) {
    diff -= 0x100;
  } else if (diff < -0x80) {
    diff += 0x100;
  }
  if (diff < 0) {
    diff = -diff;
  }
  if (diff > 0x30) {
    return FALSE;
  }
  return TRUE;
#else
  INCFUNC("asm/func/FUN_080e4384.inc");
#endif
}

NAKED s32 FUN_080e4444(Enemy* p) { INCFUNC("asm/func/FUN_080e4444.inc"); }

// 入場フラグを食うだけの状態ハンドラ, 入場処理は何もしない
void Enemy_ClearStateBegun(Enemy* p) {
  if (p->stateBegun) {
    p->stateBegun = FALSE;
  }
}

// HP と状態を初期化して入場フラグだけ立てたハンドラに差し替える
void FUN_080e48e8(Enemy* p, s32 hp, s32 param_3, s32 param_4) {
  p->flags3 = 0;
  p->handlerState = Enemy_ClearStateBegun;
  p->stateBegun = TRUE;
  p->unk_46b = 0;
  p->hp = hp;
  p->unk_192 = 0;

  if (param_4 <= 0) {
    param_4 = param_3;
  }

  p->unk_18e = param_3;
  p->unk_190 = param_4;
  p->unk_21c[0] = 0;
  p->unk_454 = NULL;
  p->unk_490 = 0;
}

void FUN_080e4964(Enemy* p) {
  u16 prev;

  p->unk_46b = 0;
  prev = p->unk_1c8++;
  if (p->handlerState != NULL) {
    ((void (*)(Enemy*, u16))p->handlerState)(p, prev);
  }
}

void FUN_080e499c(Enemy* p) {
  p->hitbox.damage = 0;
  p->unk_48a = 0;
  p->unk_48c = 0;
}

// 敵を活動停止させる, 種族が特定の10種なら破棄対象の印も立てる
// 残差は74/77命令, 原典は通信判定の真偽値を 0/1 に起こしてから改めて cmp する (bool diamond, 未解決の残差クラス)
// Tier A-C 試済 (static inline + ? TRUE : FALSE, bool32 ローカル, 三項演算子)
NON_MATCH void FUN_080e49c4(Enemy* p) {
#ifdef NONMATCHING_C
  Enemy_SetFlag(p, ENEFLAG_UNK_0 | ENEFLAG_UNK_1);
  p->hitbox.flags |= HBFLAG_UNK_2;
  FUN_080eeee0(p);
  if (Enemy_GetFlag2(p, ENEFLAG2_UNK_11)) {
    bool32 isLink = (gFlag030047a4 & (FLAG030047A4_LINK | FLAG030047A4_UNK_14)) ? TRUE : FALSE;
    bool32 ok = isLink ? FALSE : ((p->kind == 2 || p->kind == 0x12 || p->kind == 0x13 || p->kind == 9 || p->kind == 0x11 || p->kind == 0x14 || p->kind == 0xE || p->kind == 0xB || p->kind == 0x17 || p->kind == 0x16) ? TRUE : FALSE);

    if (ok) {
      Enemy_SetFlag4(p, ENEFLAG4_UNK_12);
    }
  }
#else
  INCFUNC("asm/func/FUN_080e49c4.inc");
#endif
}

// 姿を見せて「数えない敵」の印を落とす
void FUN_080e4a68(Enemy* p) {
  Enemy_ClearFlag(p, ENEFLAG_UNK_0 | ENEFLAG_UNK_1);
  Enemy_ClearSpriteFlags(p, SPRFLAG_HIDDEN);
}

// a から b へ向かう速度ベクトルと向きを出す, 両軸の距離がどちらも範囲内なら TRUE
bool32 FUN_080e4aac(Vec3* a, Vec3* b, Vec3* out, u8* outAngle, u32 rangeX, u32 rangeZ, s32 speed) {
  s16 dx = b->x - a->x;
  s16 dz = b->z - a->z;
  s32 angle = (u8)ArcTan2_8(dx, dz);
  s32 d;

  out->x = (speed * gSineTable[(angle + 0x40) & 0xFF]) >> 16;
  out->z = (speed * gSineTable[angle]) >> 16;
  *outAngle = angle;

  d = a->x - b->x;
  if (d < 0) {
    d = -d;
  }
  if ((u32)d > rangeX) {
    return FALSE;
  }

  d = a->z - b->z;
  if (d < 0) {
    d = -d;
  }
  if ((u32)d > rangeZ) {
    return FALSE;
  }
  return TRUE;
}

NAKED s32 FUN_080e4b3c(Enemy* p) { INCFUNC("asm/func/FUN_080e4b3c.inc"); }

NAKED void FUN_080e4e20(Enemy* p) { INCFUNC("asm/func/FUN_080e4e20.inc"); }

NAKED s32 FUN_080e4f90(Enemy* p, unknown* param_2) { INCFUNC("asm/func/FUN_080e4f90.inc"); }

// angle 方向へ伸ばした点を unk_20c に, 現在位置の控えを unk_214 に入れる
void FUN_080e5098(Enemy* p, s32 dx, s32 dz) {
  s32 ax = dx << 2;
  s32 az = dz << 2;

  p->unk_20c.x = ((ax * gSineTable[(p->angle + 0x40) & 0xFF]) >> 12) + p->mover.pos.x;
  p->unk_20c.y = p->mover.pos.y;
  p->unk_20c.z = ((az * gSineTable[p->angle]) >> 12) + p->mover.pos.z;
  p->unk_214 = p->mover.pos;
}

NAKED void FUN_080e510c(s32 param_1, s32 param_2, s32 param_3) { INCFUNC("asm/func/FUN_080e510c.inc"); }

void FUN_080e5388(u8 param_1, u8 param_2, u8 param_3, u8 param_4) {
  if (param_1 == 0) {
    FUN_080e510c(param_2, param_3, param_4);
  }
}

void FUN_080e53a8(u8 dir, s32* outX, s32* outY) {
  switch (dir) {
    case 0: {
      *outX = 400;
      *outY = 320;
      break;
    }
    case 1: {
      *outX = 0;
      *outY = 340;
      break;
    }
    case 2: {
      *outX = 0;
      *outY = 260;
      break;
    }
    case 3: {
      *outX = 0;
      *outY = 260;
      break;
    }
  }
}

void FUN_080e53ec(u8 dir, s32* outX, s32* outY) {
  switch (dir) {
    case 0: {
      *outX = 470;
      *outY = 390;
      break;
    }
    case 1: {
      *outX = 0;
      *outY = 310;
      break;
    }
    case 2: {
      *outX = 0;
      *outY = 260;
      break;
    }
    case 3: {
      *outX = 0;
      *outY = 240;
      break;
    }
  }
}

void FUN_080e5438(u8 dir, s32* outX, s32* outY) {
  switch (dir) {
    case 0: {
      *outX = 400;
      *outY = 320;
      break;
    }
    case 1: {
      *outX = 0;
      *outY = 340;
      break;
    }
    case 2: {
      *outX = 0;
      *outY = 260;
      break;
    }
    case 3: {
      *outX = 0;
      *outY = 260;
      break;
    }
  }
}

void FUN_080e547c(u8 dir, s32* outX, s32* outY) {
  switch (dir) {
    case 0: {
      *outX = 400;
      *outY = 320;
      break;
    }
    case 1: {
      *outX = 0;
      *outY = 340;
      break;
    }
    case 2: {
      *outX = 0;
      *outY = 260;
      break;
    }
    case 3: {
      *outX = 0;
      *outY = 390;
      break;
    }
  }
}

void FUN_080e54c8(u8 dir, s32* outX, s32* outY) {
  switch (dir) {
    case 0: {
      *outX = 360;
      *outY = 280;
      break;
    }
    case 1: {
      *outX = 0;
      *outY = 260;
      break;
    }
    case 2: {
      *outX = 0;
      *outY = 210;
      break;
    }
    case 3: {
      *outX = 0;
      *outY = 260;
      break;
    }
  }
}

void FUN_080e5508(u8 dir, s32* outX, s32* outY) {
  switch (dir) {
    case 0: {
      *outX = 390;
      *outY = 310;
      break;
    }
    case 1: {
      *outX = 0;
      *outY = 320;
      break;
    }
    case 2: {
      *outX = 0;
      *outY = 260;
      break;
    }
    case 3: {
      *outX = 0;
      *outY = 260;
      break;
    }
  }
}

void FUN_080e554c(u8 dir, s32* outX, s32* outY) {
  switch (dir) {
    case 0: {
      *outX = 390;
      *outY = 310;
      break;
    }
    case 1: {
      *outX = 0;
      *outY = 320;
      break;
    }
    case 2: {
      *outX = 0;
      *outY = 260;
      break;
    }
    case 3: {
      *outX = 0;
      *outY = 260;
      break;
    }
  }
}

void FUN_080e5590(u8 dir, s32* outX, s32* outY) {
  switch (dir) {
    case 0: {
      *outX = 250;
      *outY = 200;
      break;
    }
    case 1: {
      *outX = 0;
      *outY = 340;
      break;
    }
    case 2: {
      *outX = 0;
      *outY = 260;
      break;
    }
    case 3: {
      *outX = 0;
      *outY = 260;
      break;
    }
  }
}

void FUN_080e55d0(u8 dir, s32* outX, s32* outY) {
  switch (dir) {
    case 0: {
      *outX = 190;
      *outY = 120;
      break;
    }
    case 1: {
      *outX = 0;
      *outY = 340;
      break;
    }
    case 2: {
      *outX = 0;
      *outY = 260;
      break;
    }
    case 3: {
      *outX = 0;
      *outY = 260;
      break;
    }
  }
}

NAKED void FUN_080e5610(s32 param_1, s32 param_2, s32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_080e5610.inc"); }

NAKED void FUN_080e5718(Enemy* p, s32 param_2, s32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_080e5718.inc"); }

// pathWalker を初期化する
void FUN_080e59c4(Enemy* p, u32 pathIdx, u32 param_3, u32 nodeIdx) { Map_InitPathWalker(&p->pathWalker, pathIdx, param_3, nodeIdx); }

NAKED void FUN_080e59d0(Enemy* p, u16* param_2) { INCFUNC("asm/func/FUN_080e59d0.inc"); }

NAKED void FUN_080e5b2c(Enemy* p, s32 param_2, s32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_080e5b2c.inc"); }

// mover.angle を 4方向に丸めて, 左右反転とコマ番号に振り分ける
// 残差1命令, 原典は dir を別レジスタへ複写してから比較に使うが agbcc は複写せず同じレジスタで済ませる (命令列は 29 対 30)
NON_MATCH void Enemy_SetAnimFacing(Enemy* p, u8* variant, AuxAnimPlayFlags* flags) {
#ifdef NONMATCHING_C
  u32 dir = ((((p->mover.angle + 0x20) & 0xFF) >> 6) + 1) & 3;

  p->facing = dir;
  if (dir > 1) {
    *flags = ANIM_PLAY_XFLIP;
    *variant = 3 - dir;
  } else {
    *flags = 0;
    *variant = dir;
  }
#else
  INCFUNC("asm/func/Enemy_SetAnimFacing.inc");
#endif
}

// (dx, dz) の長さを dx / cos から出す, 真横は cos が 0 になるので |dz| で代用する
s16 VectorLength(s16 dx, s16 dz) {
  s32 angle = (u8)ArcTan2_8(dx, dz);
  s32 z;
  s32 d;

  if (angle == 0x40 || angle == 0xC0) {
    z = dz;
    if (z < 0) {
      z = -z;
    }
    return z;
  }

  d = Div(dx << 12, gSineTable[(angle + 0x40) & 0xFF]);
  if (d < 0) {
    d = -d;
  }
  return d;
}

// 種族によって影とパーティクルを持たせるかどうかを決める
void Enemy_Init_080e5dd4(Enemy* p) {
  if (p->kind == 0x11 || p->kind == 0x17 || p->kind == 9 || p->kind == 0x19 || p->kind == 0x1A || p->kind == 0xE || p->kind == 0x1B || p->kind == 0x18 || p->kind == 0x1F) {
    p->unk_44c = 1;
  } else {
    p->unk_44c = ParticleShadow_Init(&p->shadow, &p->mover.pos, 0);
  }

  if (p->kind == 4 || p->kind == 0x1C || p->kind == 5 || p->kind == 6 || p->kind == 7 || p->kind == 1 || p->kind == 3 || p->kind == 0x1E || p->kind == 0xA) {
    Eff082473e0Emitter_Init(&p->emitter, &p->mover.pos, 0, 0, 0);
    p->unk_44d = 0;
  } else {
    p->unk_44d = 1;
  }
}

// pos が自分の位置を中心とした rx × rz の矩形に入っているか
// 残差は29/31命令, 原典は dz を一度 u16 に丸めてから使う箇所で s16 へ広げ直す (dx は s16 一回だけ)
// Tier A-B 試済: s16 ローカル (40命令) / u16 dz + (s16) キャスト (34命令)
NON_MATCH bool32 FUN_080e5e94(Enemy* p, Vec3* pos, u32 rx, u32 rz) {
#ifdef NONMATCHING_C
  s32 dx = (s16)(pos->x - p->mover.pos.x);
  s32 dz = (s16)(pos->z - p->mover.pos.z);

  if (dx < 0) {
    dx = -dx;
  }
  if (dx > rx) {
    return FALSE;
  }

  if (dz < 0) {
    dz = -dz;
  }
  if (dz > rz) {
    return FALSE;
  }
  return TRUE;
#else
  INCFUNC("asm/func/FUN_080e5e94.inc");
#endif
}

NAKED s32 FUN_080e5ed4(unknown* param_1, unknown* param_2, s32 param_3, s32 param_4, s32 param_5) { INCFUNC("asm/func/FUN_080e5ed4.inc"); }

// 目標点に着いていれば TRUE, まだなら unk_1c の方角へ speed 分だけ delta を積む
bool32 FUN_080e5fe4(Enemy* p, NavAgent* agent, u32 rangeX, u32 rangeZ, s32 speed) {
  s16 dx = agent->unk_1c.x - p->mover.pos.x;
  s16 dz = agent->unk_1c.z - p->mover.pos.z;
  s32 d;

  d = agent->unk_0c.x - p->mover.pos.x;
  if (d < 0) {
    d = -d;
  }
  if ((u32)d <= rangeX) {
    d = agent->unk_0c.z - p->mover.pos.z;
    if (d < 0) {
      d = -d;
    }
    if ((u32)d <= rangeZ) {
      return TRUE;
    }
  }

  if (dx != 0 || dz != 0) {
    u32 angle = (u8)ArcTan2_8(dx, dz);

    p->mover.delta.x = p->unk_20c.x + Div65536(speed * gSineTable[(angle + 0x40) & 0xFF]) + p->mover.delta.x;
    p->mover.delta.z = p->unk_20c.z + Div65536(speed * gSineTable[angle]) + p->mover.delta.z;
    p->mover.angle = angle;
  }
  return FALSE;
}

// 目標点が範囲外で今の向きとも象限が違うとき, unk_1dc を目標のほうの8方向に更新して TRUE を返す
// 残差は70/71命令で1命令, 原典は quad * 64 を8bitに切り詰める (quad <= 3 と分かっていないので and が残る)
// Tier A-C 試済 (quad を u32/u8, (u8) キャスト / & 3 / u8 の中間変数)
NON_MATCH bool32 FUN_080e60b8(Enemy* p, NavAgent* agent, u32 rangeX, u32 rangeZ) {
#ifdef NONMATCHING_C
  s16 dx = agent->unk_1c.x - p->mover.pos.x;
  s16 dz = agent->unk_1c.z - p->mover.pos.z;
  s32 d;

  d = dx;
  if (d < 0) {
    d = -d;
  }
  if ((u32)d <= rangeX) {
    d = dz;
    if (d < 0) {
      d = -d;
    }
    if ((u32)d <= rangeZ) {
      return FALSE;
    }
  }

  if (dx != 0 || dz != 0) {
    u32 angle = ArcTan2_8(dx, dz);
    u8 quad = ((angle + 0x20) & 0xFF) >> 6;

    d = quad - (((p->mover.angle + 0x20) & 0xFF) >> 6);
    if (d < 0) {
      d = -d;
    }
    if (d != 0) {
      p->unk_1dc = (Div32((u8)(quad * 64)) + 3) & 7;
      return TRUE;
    }
  }
  return FALSE;
#else
  INCFUNC("asm/func/FUN_080e60b8.inc");
#endif
}

// 経路上の次のノードのほうが近ければ dst をそこへ差し替え, そこまで歩けるかを確かめる
void FUN_080e6148(NavAgent* agent, Enemy* p, Vec3* dst) {
  PathNode* node = p->mover.path->node;
  s32 dx = node->x - p->mover.pos.x;
  s32 dz = node->y - p->mover.pos.z;
  s32 toNode = VectorLength(dx, dz);
  s32 toDst;

  dx = dst->x - p->mover.pos.x;
  dz = dst->z - p->mover.pos.z;
  toDst = VectorLength(dx, dz);

  if (toNode <= toDst) {
    dst->x = p->mover.path->node->x;
    dst->y = 0;
    dst->z = p->mover.path->node->y;
  }

  if (!Map_IsPosInAgentIsland(agent, &p->mover.pos, dst)) {
    Enemy_ClearFlag3(p, ENEFLAG3_UNK_9);
  } else {
    s32 r = FUN_08235f40(agent, &p->mover.pos, dst);

    if (r != 0) {
      if (r != 2) {
        ClearMemory(&p->mover.delta, 8);
      }
    } else {
      Enemy_ClearFlag3(p, ENEFLAG3_UNK_9);
    }
  }
}

NAKED void FUN_080e6204(Enemy* p) { INCFUNC("asm/func/FUN_080e6204.inc"); }

// (x, z) の方を向かせる
void FUN_080e6304(Enemy* p, s16 x, s16 z) {
  s16 dx = x - p->mover.pos.x;
  s16 dz = z - p->mover.pos.z;

  p->mover.angle = ArcTan2_8(dx, dz);
}

// 残り n に応じた間隔でスプライトを点滅させる, 60 を超えていれば点滅をやめて TRUE
// 残差は95/100命令, 原典は spriteKind の分岐の両腕で判定値を別々に 0/1 へ起こす (bool diamond, 未解決の残差クラス)
// Tier A-C 試済 (Enemy_TestSpriteFlags 相当の inline, AuxSprite/MainSprite_TestFlags の二段 inline, bool32 ローカル)
NON_MATCH bool32 FUN_080e6330(Enemy* p, s32 n) {
#ifdef NONMATCHING_C
  s32 idx = 0;

  if (n <= 30) {
    idx = (n > 10) ? 1 : 2;
  }

  if (Mod(n, s16_ARRAY_085ad3c4[idx]) == 0) {
    bool32 hidden;

    if (p->spriteKind == 0) {
      hidden = (((AuxSprite*)p->sprite)->flags & SPRFLAG_HIDDEN) != 0;
    } else {
      hidden = (p->sprite->s.flags & SPRFLAG_HIDDEN) != 0;
    }

    if (hidden) {
      Enemy_ClearSpriteFlags(p, SPRFLAG_HIDDEN);
    } else {
      Enemy_SetSpriteFlags(p, SPRFLAG_HIDDEN);
    }
  }

  if (n > 60) {
    Enemy_ClearSpriteFlags(p, SPRFLAG_HIDDEN);
    return TRUE;
  }
  return FALSE;
#else
  INCFUNC("asm/func/FUN_080e6330.inc");
#endif
}

// 散らばり位置を乱数で振りながらパーティクルを count 個撒く
void FUN_080e6408(Enemy* p, s32 count, u32 kind, s32 rangeX, s32 rangeY, u32 param_6) {
  Vec3 spread;
  s32 i;

  spread.z = 0;
  spread.val = 0;
  for (i = 0; i < count; i++) {
    u16* table = gRandomTable;
    s32 r;

    gRandTableIdx = (gRandTableIdx + 1) & 0x3FF;
    r = table[gRandTableIdx];
    spread.x = Mod(r >> 4, rangeX) - (rangeX >> 1);
    gRandTableIdx = (gRandTableIdx + 1) & 0x3FF;
    r = table[gRandTableIdx];
    spread.y = -Mod(r >> 3, rangeY) - 6;
    FUN_082467d0(&p->emitter, kind, param_6, &spread);
  }
}

// パーティクルを count 個フェードさせる
void FUN_080e64b4(Enemy* p, s32 count) {
  s32 i;

  if (p->unk_44d == 0) {
    for (i = 0; i < count; i++) {
      Eff082473e0Emitter_FadeParticle(&p->emitter);
    }
  }
}

NAKED void FUN_080e64e4(s32 param_1) { INCFUNC("asm/func/FUN_080e64e4.inc"); }

// 生きている敵なら param_2[1..3] で pathWalker を初期化する
void FUN_080e6624(Enemy* p, u16* param_2) {
  if (p->hp > 0) {
    FUN_080e59c4(p, param_2[1], param_2[2], param_2[3]);
  }
}

// FUN_080e59d0 を1語進めた位置から呼ぶ
void FUN_080e664c(Enemy* p, u16* param_2) { FUN_080e59d0(p, param_2 + 1); }

NAKED void FUN_080e6658(Enemy* p) { INCFUNC("asm/func/FUN_080e6658.inc"); }

// scriptID が入っていればスクリプトを実行する
void FUN_080e6750(Enemy* p) {
  if (p->scriptID != 0) {
    VM_ExecByID(p->scriptID, NULL);
  }
}

/**
 * @brief 状態遷移の要求をクリアする
 * @param filename 使われていないデバッグ用の引数, "enemy.c", "slimecom.c" などの呼び出し元のファイル名が文字列で渡される
 * @param val 使われていないデバッグ用の引数, 呼び出し元のファイルの行番号?
 */
void Enemy_ClearPendingState(Enemy* p, const char* filename, s32 val) {
  p->unk_550 = 0;
  p->unk_551 = 0;
  p->unk_552 = 0;
  p->unk_554 = 0;
  p->unk_558 = NULL;
}

static inline void Enemy_EnterState(Enemy* p, void* handlerState, s32 state) {
  p->stateBegun = TRUE;
  p->unk_46b = 0;
  p->state = state;
  p->handlerState = handlerState;
  p->unk_1c8 = 0;
}

static inline void Enemy_SetHandlerIdx(Enemy* p, u8 idx0, u8 idx1, u8 idx2) {
  p->unk_468 = idx0;
  p->unk_469 = idx1;
  p->unk_46a = idx2;
}

// 優先度が足りていれば状態14へ遷移させる
void FUN_080e6794(Enemy* p, s32 priority) {
  if (p->unk_554 <= priority) {
    Enemy_EnterState(p, p->unk_558, 14);
    Enemy_SetHandlerIdx(p, p->unk_550, p->unk_551, p->unk_552);
    p->unk_484 = 0;
    p->unk_46c = 1;
    Enemy_ClearPendingState(p, s_enemy_c_08251f60, 2306);
  }
}

// 優先度が足りていれば状態14へ遷移させる, アニメは頭から再生し直させる
void FUN_080e6834(Enemy* p, s32 priority) {
  p->animForceRestart = FALSE;
  if (p->unk_554 <= priority) {
    Enemy_EnterState(p, p->unk_558, 14);
    Enemy_SetHandlerIdx(p, p->unk_550, p->unk_551, p->unk_552);
    p->unk_484 = 0;
    p->unk_46c = 1;
    Enemy_ClearPendingState(p, s_enemy_c_08251f60, 2322);
  }
}

// 優先度が足りていれば状態14へ遷移させる
void FUN_080e68d8(Enemy* p, s32 priority) {
  if (p->unk_554 <= priority) {
    Enemy_EnterState(p, p->unk_558, 14);
    Enemy_SetHandlerIdx(p, p->unk_550, p->unk_551, p->unk_552);
    p->unk_484 = 0;
    p->unk_46c = 1;
    Enemy_ClearPendingState(p, s_enemy_c_08251f60, 2337);
  }
}

NAKED void FUN_080e6978(Enemy* p, unknown* param_2, unknown* param_3, s32 param_4, s32 param_5) { INCFUNC("asm/func/FUN_080e6978.inc"); }

// プレイヤーか kindMask 4 の標的が XZ 両軸とも 1ブロック以内にいるか
bool32 FUN_080e7078(Enemy* p) {
  Vec3 d;
  EnemyTarget* t;
  s32 v;
  s32 i;

  for (i = 0; i <= gPlayerCount; i++) {
    if (gPlayerPtr[i] != NULL) {
      d.x = p->mover.pos.x - gPlayerPtr[i]->mover.pos.x;
      v = d.x;
      if (v < 0) {
        v = -v;
      }
      if (v <= 0xFF) {
        d.z = p->mover.pos.z - gPlayerPtr[i]->mover.pos.z;
        v = d.z;
        if (v < 0) {
          v = -v;
        }
        if (v <= 0xFF) {
          return TRUE;
        }
      }
    }
  }

  t = EnemyTargetManager_FindByKind(4);
  if (t == NULL) {
    return FALSE;
  }

  d.x = p->mover.pos.x - t->owner->pos.x;
  v = d.x;
  if (v < 0) {
    v = -v;
  }
  if (v > 0xFF) {
    return FALSE;
  }

  d.z = p->mover.pos.z - t->owner->pos.z;
  v = d.z;
  if (v < 0) {
    v = -v;
  }
  if (v > 0xFF) {
    return FALSE;
  }
  return TRUE;
}

// pos に一番近いプレイヤーを狙う相手にする (距離はXZ平面で見る)
void Enemy_TargetNearestPlayer(Enemy* p, Vec3* pos) {
  Mover* best = NULL;
  s32 bestDistSq = 0x7FFFFFFF;
  s16 d[3];
  s32 i;

  for (i = 0; i < 4; i++) {
    if (gPlayerPtr[i] != NULL) {
      Vec3* ppos = &gPlayerPtr[i]->mover.pos;
      s32 distSq;

      d[0] = ppos->x - pos->x;
      d[1] = ppos->y - pos->y;
      d[2] = ppos->z - pos->z;
      distSq = d[0] * d[0] + d[2] * d[2];
      if (bestDistSq > distSq) {
        bestDistSq = distSq;
        best = &gPlayerPtr[i]->mover;
      }
    }
  }

  if (best != NULL) {
    if (Enemy_GetFlag3(p, ENEFLAG3_UNK_12)) {
      EnemyTargetManager_Release(p->target);
      Enemy_ClearFlag3(p, ENEFLAG3_UNK_12);
      p->target = NULL;
    }
    p->playerMover = best;
  }
}

// 今いるノードと直前のノードを避けて, 次の経路ノードを乱数で選ぶ (4回外したら順送り)
// 残差は78/78命令で gRandomTable のプール定数の位置のみ, 原典は添字のスケールを先に出してから gRandomTable を読む
NON_MATCH void FUN_080e7204(Enemy* p) {
#ifdef NONMATCHING_C
  u8 cur = p->pathWalker.nodeIdx;
  s32 next;
  s32 i;

  for (i = 0; i < 4; i++) {
    gRandTableIdx = (gRandTableIdx + 1) & 0x3FF;
    next = Mod(gRandomTable[gRandTableIdx], (u8)p->pathWalker.path->nodeCount);
    if (next != cur && next != p->prevPathNode) {
      break;
    }
  }

  if (next == cur || next == p->prevPathNode) {
    next = cur + 1;
    if (next >= (u8)p->pathWalker.path->nodeCount) {
      next = 0;
    }
  }

  p->prevPathNode = cur;
  p->pathWalker.nodeIdx = next;
  p->pathWalker.unk_3 = 0;
  p->pathWalker.node = Map_GetPathNodes(p->pathWalker.path);
  p->pathWalker.node += p->pathWalker.nodeIdx;
#else
  INCFUNC("asm/func/FUN_080e7204.inc");
#endif
}

NAKED void FUN_080e72b0(Enemy* p, s32 param_2) { INCFUNC("asm/func/FUN_080e72b0.inc"); }

NAKED void FUN_080e73c8(Enemy* p) { INCFUNC("asm/func/FUN_080e73c8.inc"); }

NAKED void FUN_080e7b6c(Enemy* p) { INCFUNC("asm/func/FUN_080e7b6c.inc"); }

NAKED void FUN_080e7f30(Enemy* p) { INCFUNC("asm/func/FUN_080e7f30.inc"); }

NAKED s32 FUN_080e8038(s32 param_1, s32 param_2, s32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_080e8038.inc"); }

NAKED void FUN_080e81dc(Enemy* p, s32 param_2) { INCFUNC("asm/func/FUN_080e81dc.inc"); }

NAKED void FUN_080e8360(Enemy* p) { INCFUNC("asm/func/FUN_080e8360.inc"); }

NAKED void FUN_080e850c(Enemy* p) { INCFUNC("asm/func/FUN_080e850c.inc"); }

NAKED void FUN_080e8614(Enemy* p) { INCFUNC("asm/func/FUN_080e8614.inc"); }

bool8 Enemy_IsDead(Enemy* p) {
  if (p == NULL) {
    return FALSE;
  }

  if (Enemy_TestFlag3(p, ENEFLAG3_UNK_6) || Enemy_TestFlag2(p, ENEFLAG2_UNK_17) || p->hp <= 0) {
    return TRUE;
  }
  return FALSE;
}

// 8バイト2語の要素を先頭ワードの昇順に並べ替える (バブルソート)
// 残差は31/33命令, 原典は count-1 を引数レジスタ上で潰してから番兵チェック後に退避するが agbcc は別レジスタに作る
// Tier A-B 試済: count-1 を2回書く (34命令) / ローカル n に退避 / count-- 文
NON_MATCH void FUN_080e8aa0(s32* p, s32 count) {
#ifdef NONMATCHING_C
  s32 i;
  s32 j;

  count--;
  for (i = 0; i < count; i++) {
    s32* q = p;

    for (j = 0; j < count; j++) {
      if (q[0] > q[2]) {
        s32 key = q[0];
        s32 val = q[1];

        q[0] = q[2];
        q[1] = q[3];
        q[2] = key;
        q[3] = val;
      }
      q += 2;
    }
  }
#else
  INCFUNC("asm/func/FUN_080e8aa0.inc");
#endif
}

NAKED void FUN_080e8ae4(Enemy* p, u8* param_2, u8* param_3) { INCFUNC("asm/func/FUN_080e8ae4.inc"); }

void FUN_080e8f20(Enemy* p, s32 param_2) {
  p->unk_21e = FUN_08240b98(p->unk_204, param_2);

  if (p->unk_21e == 0xB546) {
    FUN_080e8ae4(p, p->unk_204, p->unk_204);
  }
}

NAKED s32 FUN_080e8f5c(unknown* param_1) { INCFUNC("asm/func/FUN_080e8f5c.inc"); }

NAKED s32 FUN_080e907c(Enemy* p) { INCFUNC("asm/func/FUN_080e907c.inc"); }

NAKED void FUN_080e9178(Enemy* p) { INCFUNC("asm/func/FUN_080e9178.inc"); }

NAKED s32 FUN_080eafdc(Enemy* p) { INCFUNC("asm/func/FUN_080eafdc.inc"); }

NAKED s32 FUN_080eb168(Enemy* p) { INCFUNC("asm/func/FUN_080eb168.inc"); }

NAKED s32 FUN_080eb2a0(Enemy* p) { INCFUNC("asm/func/FUN_080eb2a0.inc"); }

// 犬(プレイヤーに攻撃したときにアイテムを奪う)の処理
// 道具欄をランダムな位置から16スロット分走査して, 持っている道具を1つ選ぶ (チョコまみれは除く)
// 残差は62/62命令でブロック配置のみ, 原典は見つかった側のブロックをループの外 (return FALSE の後ろ) に置く
// Tier A-C 試済 (for/while(TRUE), break+i==16, s16 ローカル経由)
NON_MATCH bool32 FUN_080ec438(s16* outSlot, s16* outItem, s16* outRot) {
#ifdef NONMATCHING_C
  s16 slot;
  s16 i;

  gRandTableIdx = (gRandTableIdx + 1) & 0x3FF;
  slot = Mod(gRandomTable[gRandTableIdx], 16);

  for (i = 0; i < 16; i++) {
    *outItem = GetNormalItemID(slot);
    if (*outItem >= 0 && *outItem != ITEM_CHOCOLATE_COVERED) {
      *outSlot = slot;
      *outRot = GetRotCount(*outSlot);
      return TRUE;
    }
    slot = Mod(slot + 1, 16);
  }
  return FALSE;
#else
  INCFUNC("asm/func/FUN_080ec438.inc");
#endif
}

void nop_080ec4c8(void) {}

void nop_080ec4cc(void) {}

// gStat->unk_308 を丸ごと 0 にする
void FUN_080ec4d0(void) { ClearMemory(gStat->unk_308, sizeof(gStat->unk_308)); }

// 0x308 の表の空き (3語目の [1] が 0) を先頭から探す, 無ければ NULL
u16* FUN_080ec4ec(void) {
  u16* r;
  s32 i;

  for (i = 0, r = gStat->unk_308; i < 20; r += 3, i++) {
    if (r[1] == 0) {
      return r;
    }
  }
  return NULL;
}

// 0x308 の表から先頭2語が (a, b) の行を探す, 無ければ NULL
u16* FUN_080ec518(u32 a, u32 b) {
  u16* t;
  s32 i;

  for (i = 0, t = gStat->unk_308; i < 20; i++) {
    if (t[i * 3] == a && t[i * 3 + 1] == b) {
      return &t[i * 3];
    }
  }
  return NULL;
}

NAKED void FUN_080ec554(void) { INCFUNC("asm/func/FUN_080ec554.inc"); }

// 0x308 の表に (a, b) を登録する, 既にあるか空きが無ければ何もしない
void FUN_080ec5b4(u16 a, u16 b) {
  u16* r = FUN_080ec518(a, b);
  EnemyManager* m;

  if (r != NULL) {
    return;
  }

  r = FUN_080ec4ec();
  if (r == NULL) {
    return;
  }

  m = GetEnemyManager();
  if (m == NULL) {
    return;
  }

  r[0] = a;
  r[1] = b;
  r[2] = m->unk_30;
}

bool32 FUN_080ec5f0(u16 param_1, u16 param_2) {
  if (FUN_080ec518(param_1, param_2) == 0 && FUN_080ec4ec() != 0) {
    return TRUE;
  }

  return FALSE;
}
