#include "collision_map.h"
#include "emote.h"
#include "enemy_target.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "input.h"
#include "item.h"
#include "map_inline.h"
#include "mover.h"
#include "player.h"
#include "random.h"
#include "shadow.h"
#include "sound.h"
#include "vm.h"

// サバタ
// このEntityはリンゴやダーイン戦での共闘NPCとしてのサバタで、プレイヤーとしてのサバタは player.c で扱う
// またそれ以外のNPCサバタはこれとは別のEntityっぽい 例えば、螺旋の塔のボス戦の入り口で立っているサバタは別扱いだった(戦闘が始まると、このEntityを使う)
// 通信対戦のサバタはこのEntityを使わない(自キャラでも対戦相手でも)

void AllySabata_OnHurt(HitboxData* a, HitboxData* b, Player* p);
bool32 FUN_0809e138(Player* p);
bool32 FUN_08235fd8(u16* p);
void Map_StepNavPath(NavAgent* agent, Vec3* pos);
bool32 FUN_080298dc(void);
extern u16 gRisingSunCount;
void* Entity080abd14_Create(void* owner, WorldPos* pos1, WorldPos* pos2, u32 param_4, u32 param_5);
WorldPos* FUN_080230c4(void);
void FUN_08084734(WorldPos* out);
void FUN_08084754(void);
void FUN_08084798(s32 val);
void* Entity080cbabc_Create(WorldPos* pos, s32 poseIdx, s32 angle, s32 speed, s32 plttID, s32 param_6, s32 param_7, s32 param_8, u32 param_9);

static inline bool8 TestMapFlag(u32 mapflag) {
  if (TEST_FLAGS(gStat->mapFlags, mapflag)) return TRUE;
  return FALSE;
}

// facing から animIDOffset と xflip を決める
void AllySabata_SetAnimFacing(Player* p) {
  u8 v = p->facing;
  if (v > 4) {
    p->animIDOffset = 8 - v;
    p->xflip = TRUE;
  } else {
    p->animIDOffset = v;
    p->xflip = FALSE;
  }
}

// human に animIdx のアニメを設定して1フレーム進める, 前回と同じIDならコマ番号を引き継ぐ
// 残差は animIdx + animIDOffset の adds のオペランド順だけ (57対57), 原典は adds r2, r1, r2
// src/player.c の Player_PlayAnim が同じ1命令で止まっているので、この2つは同じ問題
// Tier A-B 試済: オペランド入れ替え / u32 と u16 のキャスト / 複合代入 (加算位置が動いて悪化)
NON_MATCH bool32 AllySabata_PlayAnim(Player* p, u32 animIdx, s32 animSpeed) {
#ifdef NONMATCHING_C
  MainAnimPlayFlags16 flags = 0;

  if (p->animID == animIdx) {
    flags = MAIN_ANIM_KEEP_FRAME;
  }
  p->animID = animIdx;

  MainSprite_SetAnim(&p->human, &p->humanGfx, animIdx + p->animIDOffset, PLAYMODE_LOOP, flags);
  if (p->xflip) {
    p->human.flags |= SPRFLAG_XFLIP;
  } else {
    p->human.flags &= ~SPRFLAG_XFLIP;
  }

  MainSprite_SetAnimSpeed(&p->human, (u16)animSpeed);
  return MainSprite_AdvanceAnim(&p->human, &p->humanGfx);
#else
  INCFUNC("asm/func/AllySabata_PlayAnim.inc");
#endif
}

// 向きと速さから mover.delta を作る, 階段タイルの上では上りで 52/64, 下りで 40/64 に変える
// 残差10命令 (96/106): 原典は p を ip に置いたまま回すのでレジスタ圧が高く, こちらは低位レジスタで足りてしまう
// src/player.c の Player_SetMoveDelta が同じコードで同じ所で止まっているので、この2つは同じ問題
// Tier A-C 試済: stairs のローカル化 / ローカルの宣言順の入れ替え (どちらも割当は動かない)
NON_MATCH void FUN_08080d2c(Player* p, s32 val) {
#ifdef NONMATCHING_C
  s32 v;
  s32 angle = ((p->facing + 5) & 7) * 32;
  p->mover.delta.x = POLAR_X(val, angle);
  p->mover.delta.z = POLAR_Z(val, angle);

  if (p->tile.stairs[1] == 1) {
    if (p->mover.delta.z < 0) {
      v = p->mover.delta.z * 40;
    } else {
      v = p->mover.delta.z * 52;
    }
    p->mover.delta.z = FixToInt(6, v);
  } else if (p->tile.stairs[1] == 2) {
    if (p->mover.delta.x < 0) {
      v = p->mover.delta.x * 40;
    } else {
      v = p->mover.delta.x * 52;
    }
    p->mover.delta.x = FixToInt(6, v);
  }
#else
  INCFUNC("asm/func/FUN_08080d2c.inc");
#endif
}

// action と state を切り替えて状態タイマーを 0 に戻す
void AllySabata_SetAction(Player* p, u8 action, u8 state) {
  p->action = action;
  p->state = state;
  p->stateTimer = 0;
}

// 毎フレームの行動開始前の初期化, フラグと影のオフセットを戻す
void FUN_08080e34(Player* p) {
  p->flag20 = PFLAG20_UNK_0;
  if (KAAMOS(p->isSabata) == 0 && FUN_0809e138(p)) {
    Player_SetFlag20(p, PFLAG20_SUNBATHING);
  }
  if (Player_TestEquipBuff(p, EBUFF_SKULLSUIT)) {
    Player_SetFlag20(p, PFLAG20_SNEAKING);
  }

  VEC3_SET(p->shadowOffset, 0, 0, 0);
  p->flag35a = 0;
  p->hurtbox.hitState &= ~HBHITSTATE_UNK_1;
}

void AllySabata_SetFlag35a(Player* p, u32 bits) { p->flag35a |= bits; }

u32 AllySabata_TestFlag35a(Player* p, u32 bits) { return p->flag35a & bits; }

// サバタのときだけ3つの音を鳴らす
void FUN_08080ee8(Player* p) {
  if (p->kind != PLAYER_SABATA) {
    sound_08240740(NOISE_SOLAR_CHARGE);
  } else {
    sound_08240740(SONG_569);
    sound_08240740(SONG_514);
    sound_08240740(SONG_870);
  }
}

// a から b を見た方向の象限を 1/3/5/7 で返す, a に HBFLAG_ANGLE が立っていれば a の angle をそのまま使う
// 残差は 43 対 47 でこちらが短い, 原典は angle + 0xE0 の5命令を両分岐に重複して置くが、こちらは cross-jumping で共有してしまう
// Tier A-B 試済: ネスト形 / dx,dz の関数スコープ化 (どちらも共有される)
NON_MATCH s32 FUN_08080f20(HitboxData* a, HitboxData* b) {
#ifdef NONMATCHING_C
  s32 dir;
  s32 dx;
  s32 dz;

  if (a->flags & HBFLAG_ANGLE) {
    dir = a->angle + 0xE0;
  } else {
    dx = a->center.x - b->center.x;
    dz = a->center.z - b->center.z;
    if (dx == 0 && dz == 0) {
      dir = b->angle + 0xE0;
    } else {
      dir = ArcTan2_8(dx, dz) + 0x60;
    }
  }
  return (((dir & 0xFF) >> 6) * 2) + 1;
#else
  INCFUNC("asm/func/FUN_08080f20.inc");
#endif
}

// 被弾した向きを決める, PFLAG20_UNK_15 が立っているときは facing でなく unk_3e8 に入れて相手の unk_40 を退避する
void FUN_08080f80(Player* p, HitboxData* a, HitboxData* b) {
  b->knockbackPower = a->knockbackPower;
  if (a->knockbackPower > 200) {
    b->knockbackPower = 200;
  }

  if (Hitbox_TestAttr(a, HBATTR_18)) {
    p->unk_3d2 = 1;
    p->facing = FUN_08080f20(a, b);
    return;
  }

  if (p->action == PACT_UNK_5) {
    b->flags |= HBFLAG_HIDDEN;
    b->knockbackPower = 0;
    return;
  }

  if (Player_TestFlag20(p, PFLAG20_UNK_15)) {
    if (a->flags & HBFLAG_ANGLE) {
      p->knockbackDir = ((((a->angle + 0x10) & 0xFF) >> 5) + 3) & 7;
    } else {
      s32 dx = a->center.x - b->center.x;
      s32 dz = a->center.z - b->center.z;

      if (dx == 0 && dz == 0) {
        p->knockbackDir = p->facing;
      } else {
        p->knockbackDir = (((((((u16)ArcTan2_8(dx, dz) + 0x10) & 0xFF) >> 5) + 3) & 7) + 4) & 7;
      }
    }

    p->knockbackSpeed = b->knockbackPower;
    b->knockbackPower = 0;
    b->flags |= HBFLAG_HIDDEN;
    return;
  }

  p->unk_3d2 = 0;
  p->facing = FUN_08080f20(a, b);
}

// 夜扱いかどうか, 闇のガーブを着ていれば時刻を問わず夜になる
bool32 AllySabata_IsNight(Player* p) {
  u32 span;

  if (KAAMOS(p->isSabata) > 0) {
    return TRUE;
  }
  if (Player_TestEquipBuff(p, EBUFF_ALLNIGHT)) {
    return TRUE;
  }

  span = Time_GetSpanOfTime();
  if (span == TIME_UNK4 || span == TIME_UNK5 || span == TIME_NIGHT) {
    return TRUE;
  }
  return FALSE;
}

// 貴重品から最初に見つかった棺桶の Coffin ID を返す, 無ければ COFFIN_OAK
s32 FUN_080810f8(void) {
  s32 i;

  for (i = 0; i < 16; i++) {
    u32 coffin = GetValuableItemID(i) - ITEM_OAK_COFFIN;
    if (coffin < COFFIN_NUM) {
      return coffin;
    }
  }
  return COFFIN_OAK;
}

// kind を引数にして scriptID_9c4 のスクリプトを起動する
void FUN_08081118(Player* p, u32 kind) {
  ScriptArgs args;
  u32 argv[1];

  if (p->scriptID_9c4 != 0) {
    args.argc = 1;
    argv[0] = kind;
    args.argv = argv;
    VM_ExecByID(p->scriptID_9c4, &args);
  }
}

void FUN_08081150(Player* p, u32 bits) { p->unk_9bc |= bits; }

u32 FUN_08081160(Player* p, u16 bits) { return p->unk_9bc & bits; }

void FUN_08081170(Player* p) {
  if (p->scriptID_9c0 != 0) {
    VM_ExecByID(p->scriptID_9c0, NULL);
  }
}

// unk_94c のパレットを pltt_2a4 に取り込む, unk_94e のぶんだけ各成分を明るくする
void FUN_08081188(Player* p) {
  rgb555* src = &gObjPlttData[p->unk_94c * 16];
  s32 i;

  if (p->unk_94e == 0) {
    for (i = 0; i < 16; i++) {
      if (i != 5 && i != 6 && i != 13) {
        p->pltt_2a4[i] = *src;
      }
      src++;
    }
  } else {
    for (i = 0; i < 16; i++) {
      if (i != 5 && i != 6 && i != 13) {
        s32 r = (*src & 0x1F) + p->unk_94e;
        s32 g;
        s32 b;

        if (r > 0x1F) {
          r = 0x1F;
        }
        g = ((*src >> 5) & 0x1F) + p->unk_94e;
        if (g > 0x1F) {
          g = 0x1F;
        }
        b = ((*src >> 10) & 0x1F) + p->unk_94e;
        if (b > 0x1F) {
          b = 0x1F;
        }
        p->pltt_2a4[i] = (b << 10) | (g << 5) | r;
      }
      src++;
    }
  }
}

// 日光が当たっているとき、屋外なら 4、屋内なら 8 を返す
s32 FUN_08081240(Player* p) {
  s32 ret = 0;

  if (!TestMapFlag(MPF_OUTDOOR)) {
    if (p->flag20 & PFLAG20_SUNBATHING) {
      ret = 8;
    }
  } else {
    if (p->flag20 & PFLAG20_SUNBATHING) {
      ret = 4;
    }
  }
  return ret;
}

// unk_950 で選んだ3色をパレットの 5/6/13 番に差し込む
void FUN_0808128c(Player* p) {
  rgb555* src = &gObjPlttData[40 * 16];

  src += p->unk_950 * 3;
  p->pltt_2a4[5] = *src++;
  p->pltt_2a4[6] = *src++;
  p->pltt_2a4[13] = *src++;
}

// pltt_2a4 と src を wSrc : wBase で混ぜて pltt_2a4[16] 以降に書き、そちらを表示に使う
// 命令数は一致 (123/123), 残差は割当と前処理の並びだけ: 原典は wBase を sp+4 に退避して src を sl に置くが, こちらは wBase を r9 に置いて退避を1つ減らす
// src/player.c の Player_BlendPltt が同じコードなので、この2つは同じ問題
// Tier A-C 試済: c / d をローカルにせず src[0] / base[0] を直接3回書くと lsls #16 の CSE が出る (これで 128→123), base の for 初期化への移動, ローカルの宣言順
NON_MATCH void FUN_080812d4(Player* p, rgb555* src, s32 wSrc, s32 wBase, u32 shift) {
#ifdef NONMATCHING_C
  rgb555* base;
  s32 i;

  if (wSrc == 0) {
    p->human.pltt = p->pltt_2a4;
    return;
  }

  for (i = 0, base = p->pltt_2a4; i < 16; i++) {
    if (i == 5 || i == 6 || i == 13) {
      base[16] = base[0];
    } else {
      s32 r = (src[0] & 0x1F) + p->unk_94e;
      s32 g;
      s32 b;
      s32 dr;
      s32 dg;
      s32 db;

      if (r > 0x1F) {
        r = 0x1F;
      }
      g = ((src[0] >> 5) & 0x1F) + p->unk_94e;
      if (g > 0x1F) {
        g = 0x1F;
      }
      b = ((src[0] >> 10) & 0x1F) + p->unk_94e;
      if (b > 0x1F) {
        b = 0x1F;
      }

      dr = base[0] & 0x1F;
      dg = (base[0] >> 5) & 0x1F;
      db = (base[0] >> 10) & 0x1F;
      base[16] = ((((b * wSrc) + (db * wBase)) >> shift) << 10) | ((((g * wSrc) + (dg * wBase)) >> shift) << 5) | (((r * wSrc) + (dr * wBase)) >> shift);
    }

    src++;
    base++;
  }
  p->human.pltt = &p->pltt_2a4[16];
#else
  INCFUNC("asm/func/FUN_080812d4.inc");
#endif
}

// 毎フレームのパレット更新, 被弾直後は白く飛ばし、それ以外はエンチャント色とのクロスフェードを進める
// 残差1命令 (207/206): p と n のレジスタが入れ替わっているだけ (原典は p が r4), そのあおりで最初のループだけ &pltt_2a4[0] を 0x2C4 から subs #0x20 で作れない
// src/player.c の Player_UpdatePltt が同じ現象 (向きは逆) で止まっている
// Tier A-C 試済: n の s32 / u32, ローカルをスコープ最小に移す
NON_MATCH void FUN_080813d0(Player* p, u32 n) {
#ifdef NONMATCHING_C
  u32 bright;

  if (p->unk_951 != p->unk_950) {
    p->unk_950 = p->unk_951;
    FUN_0808128c(p);
  }

  bright = FUN_08081240(p);
  if (p->unk_94c != n || p->unk_94e != bright) {
    p->unk_94c = n;
    p->unk_94e = bright;
    FUN_08081188(p);
  }

  if (p->unk_476 != 0) {
    rgb555* src = &gObjPlttData[306 * 16];
    s32 i;

    for (i = 0; i < 16; i++) {
      if (i == 5 || i == 6 || i == 13) {
        p->pltt_2a4[16 + i] = p->pltt_2a4[i];
      } else {
        p->pltt_2a4[16 + i] = src[i];
      }
    }

    p->human.pltt = &p->pltt_2a4[16];
    p->unk_476--;
    return;
  }

  if (p->plttFlashTimer == 0) {
    if (p->enchantPlttTimer >= 1 && p->enchantPlttTimer <= 0x4F) {
      rgb555* src = &gObjPlttData[p->enchantPlttID * 16];
      s32 w;

      if (p->enchantPlttTimer >= 0x21 && p->enchantPlttTimer <= 0x2F) {
        p->enchantPlttTimer = 0x30;
      }

      if (p->enchantPlttTimer <= 0x1F) {
        w = p->enchantPlttTimer;
        p->enchantPlttTimer = w - 1;
      } else {
        w = 0x50 - p->enchantPlttTimer;
        p->enchantPlttTimer++;
        if (p->enchantPlttTimer > 0x4F) {
          p->enchantPlttTimer = 0;
        }
      }

      FUN_080812d4(p, src, w, 0x20 - w, 5);
    } else {
      p->enchantPlttTimer = 0;
      p->human.pltt = p->pltt_2a4;
    }
    return;
  }

  p->enchantPlttTimer = 0;
  if (p->plttFlashTimer > 31) {
    rgb555* src = &gObjPlttData[p->plttID_95e * 16];
    s32 i;

    for (i = 0; i < 16; i++) {
      if (i == 5 || i == 6 || i == 13) {
        p->pltt_2a4[16 + i] = p->pltt_2a4[i];
      } else {
        p->pltt_2a4[16 + i] = src[i];
      }
    }
    p->human.pltt = &p->pltt_2a4[16];
  } else {
    rgb555* src = &gObjPlttData[p->plttID_95e * 16];
    s32 w = p->plttFlashTimer;

    FUN_080812d4(p, src, w, 0x20 - w, 5);
  }

  p->plttFlashTimer--;
#else
  INCFUNC("asm/func/FUN_080813d0.inc");
#endif
}

// サバタ用のパレットIDを入れ直す
void FUN_080815ac(Player* p) {
  p->plttID_94a = 39;
  p->unk_94c = 0;
  p->unk_950 = 0xFF;
  p->human.plttID = 289;
  p->human.pltt = p->pltt_2a4;
  FUN_080813d0(p, p->plttID_94a);
}

// flashTimer が動いている間, 4フレームごとに pose を flashPose と入れ替える (点滅)
// 残差は23/23命令で共有された return pose のブロック位置だけ (player.c の Player_ApplyFlashPose と同じ), 分岐形の反転は試済
NON_MATCH u32 LinkPlayer_ApplyFlashPose(Player* p, u32 pose) {
#ifdef NONMATCHING_C
  if (p->flashTimer != 0) {
    p->flashTimer--;
    if ((p->flashTimer >> 2) & 1) {
      return p->flashPose;
    }
  }

  return pose;
#else
  INCFUNC("asm/func/LinkPlayer_ApplyFlashPose.inc");
#endif
}

// 点滅ポーズを反映してから、影の位置をスプライト位置+オフセットで作り直す
void FUN_08081628(Player* p) {
  FUN_080813d0(p, LinkPlayer_ApplyFlashPose(p, p->plttID_94a));
  p->shadowPos.x = p->human.pos.x + p->shadowOffset.x;
  p->shadowPos.y = p->human.pos.y + p->shadowOffset.y;
  p->shadowPos.z = p->human.pos.z + p->shadowOffset.z;
}

void FUN_0808168c(Player* p) { ParticleShadow_Remove(&p->shadow); }

// 影とモザイクフェードの初期値をまとめて入れる
void FUN_080816a0(Player* p) {
  p->shadowPos = p->human.pos;
  VEC3_SET(p->shadowOffset, 0, 0, 0);
  ParticleShadow_Init(&p->shadow, &p->shadowPos, 0);
  FUN_080815ac(p);

  p->mosaicFrom[0] = 4;
  p->mosaicFrom[1] = 4;
  p->mosaicFrom[2] = 4;
  p->mosaicFrom[3] = 4;
  p->unk_980[0] = 0;
  p->unk_980[1] = 0;
  p->unk_980[2] = 0;
  p->unk_980[3] = 0;
  p->mosaicInterval[0] = 4;
  p->mosaicInterval[1] = 4;
  p->mosaicInterval[2] = 4;
  p->mosaicInterval[3] = 4;
  VEC3_SET(p->pos_970, 0, 0, 0);
  p->unk_3ff = 0xFF;
}

// サバタの被弾判定を組む, ダーク属性で受けてソル属性に弱い
void AllySabata_SetupHurtbox(Player* p) {
  HitboxData* hurtbox = &p->hurtbox;
  Vec3 halfSize, offset;

  VEC3_SET(halfSize, Q8(0.196), Q8(0.497), Q8(0.196));
  VEC3_SET(offset, 0, Q8(0.497), 0);
  Hitbox_Init(hurtbox, p->mover.id, HBFLAG_HURTBOX | HBFLAG_UNK_0, 0, 1, &halfSize, &offset);
  Hitbox_SetPowerAndAttributes(hurtbox, 20, HBATTR_DARK, HBATTR_SOL);
  Hitbox_SetHandler(hurtbox, AllySabata_OnHurt, p);
  Hitbox_SetPos(hurtbox, &p->beast.pos, 0);
  Hitbox_Register(hurtbox);
}

void FUN_08084330(Player* p);

s32 FUN_080817ec(Player* p) {
  p->mode = PMODE_ACTIVE;
  p->updateCallback = FUN_08084330;
  p->action = PACT_IDLE;
  p->state = 0;
  p->stateTimer = 0;
  gPlayerMoverIDs[p->mover.unk_4] = p->mover.id;
  return 0;
}

// サバタのスプライトと巡回地点を用意し、VM の名前付き引数で行動パラメータを決める
void FUN_08081830(Player* p) {
  WorldPos base;
  MainSpriteGfxFile* f = GetFile(DIR_MAIN_SPRITE, SPRITE_DJANGO_SABATA);
  s32 i;

  if (f == NULL) {
    return;
  }

  p->humanGfx = *(MainSpriteGfx*)f;
  OpenMainSpriteFile(&p->humanGfx, f);
  MainSprite_Add(&p->human, &p->humanGfx, 0, SPRFLAG_UNK_15, 2, PLAYMODE_PAUSE, 60, &p->mover.pos);

  if (VM_SeekToNamedArg('d')) {
    p->facing = VM_GetValue();
  } else {
    p->facing = FACE_UP;
  }

  if (p->facing > 4) {
    p->animIDOffset = 8 - p->facing;
    p->xflip = 1;
  } else {
    p->animIDOffset = p->facing;
    p->xflip = 0;
  }

  p->animID = 0;
  MainSprite_SetAnim(&p->human, &p->humanGfx, p->animIDOffset, PLAYMODE_LOOP, 0);
  if (p->xflip) {
    p->human.flags |= SPRFLAG_XFLIP;
  } else {
    p->human.flags &= ~SPRFLAG_XFLIP;
  }

  FUN_08084734(&base);
  for (i = 0; i < 4; i++) {
    s32 dx;
    s32 dz;
    s32 dir;

    p->waypoints[i] = base;
    switch (i) {
      case 0: {
        dx = 0x2C, dz = -0xA0, dir = 5;
        break;
      }
      case 1: {
        dx = 0x2C, dz = 0xFC, dir = 1;
        break;
      }
      case 2: {
        dx = -0xA0, dz = 0x2C, dir = 3;
        break;
      }
      case 3: {
        dx = 0xFC, dz = 0x2C, dir = 7;
        break;
      }
      default: {
        dx = 0, dz = 0, dir = 0;
        break;
      }
    }

    p->waypoints[i].x += dx;
    p->waypoints[i].z += dz;
    p->waypoints[i].val = dir;
  }

  p->unk_4a6 = 0;
  p->approachUsed = 0;
  if (VM_SeekToNamedArg('r')) {
    p->unk_467 = VM_GetValue();
  } else {
    p->unk_467 = 0x32;
  }

  p->blockCount = 0;
  if (VM_SeekToNamedArg('b')) {
    p->blockLimit = VM_GetValue();
  } else {
    p->blockLimit = 3;
  }

  p->unk_46d = 0;
  p->unk_474 = 0;
  if (VM_SeekToNamedArg('G')) {
    p->unk_46c = VM_GetValue();
    p->unk_472 = VM_GetValue();
  } else {
    p->unk_46c = 4;
    p->unk_472 = 0xB4;
  }

  p->namakuraCount = 0;
  if (VM_SeekToNamedArg('s')) {
    p->namakuraLimit = VM_GetValue();
  } else {
    p->namakuraLimit = 5;
  }
}

// '.p' の座標 (なければ原点) に立たせて mover / タイル / 経路エージェントを初期化する
s32 FUN_08081ab0(Player* p, u32 id) {
  WorldPos pos;

  p->inputIdx = 1;
  if (VM_SeekToNamedArg('p')) {
    VEC3_SET(pos, VM_GetValue(), VM_GetValue(), VM_GetValue());
  } else {
    VEC3_SET(pos, 0, 0, 0);
  }

  pos.y = TileHeightAt(&pos);
  Mover_Init(&p->mover, id, &pos, 0, (u8)p->inputIdx, p);
  FUN_08081830(p);
  Mover_SetMainSprite(&p->mover, &p->human);
  Map_InitMoverTile(&p->tile, &pos);
  Mover_SetCollision(&p->mover, &p->tile, 30, 30);
  Map_InitNavAgent(&p->navAgent, &pos);
  p->unk_464 = 1;
  return FUN_08002a48(&p->mover);
}

// サバタの攻撃判定とそのスプライトを作る, 威力は VM の '.a' で上書きできる
// 残差2命令 (112/110): p->knockbackPower と p->atkInvincibleTime のアドレスを原典は spr (p+0x9C8) から add #0xb4 / add #2 で作るが, こちらは p からプール定数で作る
// そのせいで p+0xA7E が CSE で生き残って低位レジスタを1本余計に使い, power と定数 2 が高位レジスタに追い出される
// Tier A-C 試済: spr / gfx / hitbox のローカル化の有無, ローカルの宣言順, hitbox の代入位置
NON_MATCH void FUN_08081c04(Player* p) {
#ifdef NONMATCHING_C
  s32 power;
  AuxSprite* spr = &p->wpn.sprite;
  Vec3 halfSize;
  Vec3 offset;

  if (VM_SeekToNamedArg('a')) {
    p->wpn.atkPower = VM_GetValue();
    power = VM_GetValue();
  } else {
    p->wpn.atkPower = 10;
    power = 30;
  }

  p->wpn.knockbackPower = 32;
  p->wpn.atkInvincibleTime = 20;
  Video_GetAuxSprite(&p->wpn.gfx, SPRITE_GUN_SPREAD);
  AuxSprite_Add(spr, &p->wpn.gfx, SPRFLAG_NO_CLIP | SPRFLAG_AFFINE | SPRFLAG_HIDDEN);
  spr->poseIdx = 4;
  Video_SetAuxSpritePltt(&p->wpn.gfx, 50);
  spr->priority = 2;
  spr->scaleY = 0x7F;
  spr->scaleX = 0x7F;
  spr->pos = p->mover.pos;

  halfSize.x = 170, halfSize.y = 50, halfSize.z = 170;
  offset.x = 0, offset.y = -20, offset.z = 0;
  Hitbox_Init(&p->wpn.hitbox, 0, HBFLAG_HITBOX | HBFLAG_ANGLE | HBFLAG_UNK_0, 0, 1, &halfSize, &offset);
  Hitbox_SetAttack(&p->wpn.hitbox, power, 50, 0x10, 2, p->wpn.atkInvincibleTime);
  Hitbox_SetHandler(&p->wpn.hitbox, NULL, p);
#else
  INCFUNC("asm/func/FUN_08081c04.inc");
#endif
}

// 太陽ゲージから sunburn を貯め、100 たまるごとに足元の判定を1つ出す
void FUN_08081d18(Player* p, s32 sunGauge) {
  if (!(p->human.flags & SPRFLAG_HIDDEN)) {
    p->sunburn += sunGauge + 2;
    if (p->sunburn > 99) {
      Vec3 size;
      WorldPos pos;

      pos = p->mover.pos;
      pos.y += Q8(0.313);
      VEC3_SET(size, Q8(0.25), Q8(0.235), Q8(0.25));
      EmitSmoke(&pos, 1, &size, 0, 0, 0xC, 2, 2);
      p->sunburn -= 100;
    }
  }
}

// 乱数が確率 (%) を下回ったかどうか
bool32 FUN_08081da4(s32 percent) {
  if (Mod(Random() / 16, 100) < percent) {
    return TRUE;
  }
  return FALSE;
}

// gPlayerPtr[0] の周り8方向のうち、高さが p と同じになる地点を乱数で1つ選ぶ
// 命令数は一致 (184/184), 残差は angle (i * 32) の2回目の使用だけ: 原典は & 0xFF で angle のレジスタを潰すが, こちらは退避してから潰す
// GetTileHeightAt の端数取りを (u8) でなく & 0xFF と書くのが鍵で, そうしないと展開時に ldrb に畳まれて定数 0xFF がループ外に巻き上げられない (179 対 184 になる)
// Tier A-C 試済: angle の宣言位置, angle をやめて i * 32 を2回書く (186 命令に増える)
NON_MATCH s32 FUN_08081de0(Player* p, WorldPos* outPos, s32* outDir) {
#ifdef NONMATCHING_C
  WorldPos cand[8];
  s32 count = 0;
  s32 i;

  for (i = 0; i < 8; i++) {
    s32 angle;

    cand[i] = gPlayerPtr[0]->mover.pos;
    angle = i * 32;
    cand[i].x += FixToInt(12, COS(angle) * 512);
    cand[i].z += FixToInt(12, SIN(angle) * 512);
    if (TileHeightAt(&cand[i]) == p->mover.pos.y) {
      cand[i].val = 1;
      count++;
    } else {
      cand[i].val = 0;
    }
  }

  if (count != 0) {
    s32 n;

    gRandTableIdx = (gRandTableIdx + 1) & 0x3FF;
    n = Mod(*(gRandomTable + gRandTableIdx) >> 3, count);
    for (i = 0; i < 8; i++) {
      if (cand[i].val != 0) {
        if (n == 0) {
          *outPos = cand[i];
          *outDir = (i + 7) & 7;
          return 1;
        }
        n--;
      }
    }
  }

  return 0;
#else
  INCFUNC("asm/func/FUN_08081de0.inc");
#endif
}

// 行動中なら行動を止めてから AllySabata_PlayAnim を呼ぶ
void FUN_08081f80(Player* p) {
  if (p->action) {
    AllySabata_SetAction(p, PACT_IDLE, 0);
    AllySabata_SetAnimFacing(p);
  }

  AllySabata_PlayAnim(p, 414, Q6(1));
}

// 経路の次の点へ向かって歩く, 終点に着いたら unk_470 / unk_471 の action と向きに移る
// 残差1命令 (159/160): 原典は定数 12 を分岐前に r7 へ置いて2つの muls で使い回すが, こちらは else 側で都度作るので r7 の退避も要らない
// Tier A-C 試済: 12 をローカル化 (関数先頭 / else ブロック内, どちらも 156 命令に縮んで遠ざかる), 乗算のオペランド順
NON_MATCH void FUN_08081fb4(Player* p) {
#ifdef NONMATCHING_C
  s32 dx;
  s32 dz;

  if (p->action != PACT_WALK) {
    AllySabata_SetAction(p, PACT_WALK, 0);
  }
  AllySabata_SetFlag35a(p, PFLAG35A_NO_TILE);

  dx = p->navAgent.unk_0c.x - p->mover.pos.x;
  dz = p->navAgent.unk_0c.z - p->mover.pos.z;
  if (dx * dx + dz * dz <= 144) {
    u8 dir;

    p->mover.pos = p->navAgent.unk_0c;
    dir = p->pathEndFacing;
    p->facing = dir;
    if (dir > 4) {
      p->animIDOffset = 8 - dir;
      p->xflip = 1;
    } else {
      p->animIDOffset = dir;
      p->xflip = 0;
    }

    AllySabata_PlayAnim(p, 414, Q6(1));
    AllySabata_SetAction(p, p->pathEndAction, 0);
  } else {
    s32 angle = ArcTan2_8(p->navAgent.unk_1c.x - p->mover.pos.x, p->navAgent.unk_1c.z - p->mover.pos.z);

    p->mover.delta.x = FixToInt(12, COS(angle) * 12);
    p->mover.delta.z = FixToInt(12, SIN(angle) * 12);
    if (FUN_08235fd8(&p->navAgent.flags)) {
      p->facing = (((((u16)angle + 0x10) & 0xFF) >> 5) + 3) & 7;
      AllySabata_SetAnimFacing(p);
    }
    AllySabata_PlayAnim(p, 419, Q6(1));
  }
#else
  INCFUNC("asm/func/FUN_08081fb4.inc");
#endif
}

// 日光が当たっていなくて EN に余裕があるか
s32 FUN_08082124(Player* p) {
  if (!Player_TestFlag20(p, PFLAG20_SUNBATHING) && p->ene < p->maxEne) {
    return 1;
  }

  return 0;
}

// サバタの行動7, A を押している間ためを続け、離したら構えを解く
void FUN_08082154(Player* p) {
  if (p->action != PACT_UNK_7) {
    AllySabata_SetAction(p, PACT_UNK_7, 0);
  }

  switch (p->state) {
    case 0: {
      AllySabata_PlayAnim(p, 414, Q6(1));
      AllySabata_SetAction(p, PACT_UNK_7, 1);
      break;
    }
    case 1: {
      if (p->stateTimer == 0) {
        if (p->facing >= 2 && p->facing <= 6) {
          p->facing = FACE_DOWN;
          p->animIDOffset = 1;
          p->xflip = 0;
          p->pos_930 = p->mover.pos;
          p->pos_930.x -= 0x14;
          p->pos_930.y += 0x14A;
          p->pos_930.z += 0x3C;
        } else {
          p->facing = FACE_UP;
          p->animIDOffset = 0;
          p->xflip = 0;
          p->pos_930 = p->mover.pos;
          p->pos_930.x += 0x14;
          p->pos_930.y += 0x14A;
          p->pos_930.z -= 0x1E;
        }

        p->stateTimer++;
      }

      p->shadowOffset.z = 0xF;
      if (AllySabata_PlayAnim(p, 466, Q6(1))) {
        PlaySound_082406e0(SONG_203);
        if (!(p->input->down & A_BUTTON)) {
          AllySabata_SetAction(p, PACT_UNK_7, 4);
        } else if (FUN_08082124(p)) {
          PlaySound_082406e0(NOISE_SOLAR_CHARGE);
          p->unk_409 = 1;
          p->unk_404 = 0;
          AllySabata_SetAction(p, PACT_UNK_7, 2);
        } else {
          p->unk_404 = 0;
          AllySabata_SetAction(p, PACT_UNK_7, 3);
        }
      }
      break;
    }
    case 2: {
      Player_SetFlag20(p, PFLAG20_UNK_7 | PFLAG20_QC);
      if (p->unk_404 <= 4) {
        p->unk_404++;
        if (p->unk_404 == 5) {
          PlaySound_082406e0(VO_RDJANGO_TAIYO_296);
        }
      }

      AllySabata_PlayAnim(p, 468, Q6(1));
      p->shadowOffset.z = 0x1E;
      p->plttID_95e = 290;
      if (p->stateTimer <= 0x1F) {
        p->plttFlashTimer = p->stateTimer;
      } else {
        p->plttFlashTimer = 64 - p->stateTimer;
      }

      p->stateTimer++;
      if (p->stateTimer > 0x40) {
        p->stateTimer = 0;
      }

      if (!(p->input->down & A_BUTTON)) {
        sound_08240740(NOISE_SOLAR_CHARGE);
        p->unk_409 = 0;
        AllySabata_SetAction(p, PACT_UNK_7, 4);
      } else if (!FUN_08082124(p)) {
        sound_08240740(NOISE_SOLAR_CHARGE);
        p->unk_409 = 0;
        AllySabata_SetAction(p, PACT_UNK_7, 3);
      }
      break;
    }
    case 3: {
      Player_SetFlag20(p, PFLAG20_UNK_7);
      AllySabata_PlayAnim(p, 470, Q6(1));
      p->shadowOffset.z = 0x1E;
      if (!(p->input->down & A_BUTTON)) {
        AllySabata_SetAction(p, PACT_UNK_7, 4);
      } else if (FUN_08082124(p)) {
        PlaySound_082406e0(NOISE_SOLAR_CHARGE);
        p->unk_409 = 1;
        p->unk_404 = 0;
        AllySabata_SetAction(p, PACT_UNK_7, 2);
      }
      break;
    }
    case 4: {
      p->shadowOffset.z = 0xF;
      if (AllySabata_PlayAnim(p, 472, Q6(1))) {
        p->animIDOffset = p->facing;
        p->xflip = 0;
        AllySabata_SetAction(p, PACT_IDLE, 0);
      }
      break;
    }
  }
}

// unk_3fe で flag35a に立てるビットを選ぶ
void FUN_08082464(Player* p) {
  if (p->unk_3fe) {
    AllySabata_SetFlag35a(p, PFLAG35A_HIDE_SHADOW | PFLAG35A_NO_HURTBOX | PFLAG35A_NO_TILE | PFLAG35A_UNK_5);
  } else {
    AllySabata_SetFlag35a(p, PFLAG35A_HIDE_BODY | PFLAG35A_HIDE_SHADOW | PFLAG35A_NO_HURTBOX | PFLAG35A_NO_TILE | PFLAG35A_UNK_5);
  }

  Player_SetFlag20(p, PFLAG20_UNK_12);
}

// サバタの行動 0x18, 吹き飛ばされている間の移動と, 止まったあとの復帰
void FUN_08082498(Player* p) {
  if (p->action != PACT_UNK_24) {
    AllySabata_SetAction(p, PACT_UNK_24, 0);
    if (p->facing > 4) {
      p->animIDOffset = (8 - p->facing) >> 1;
      p->xflip = 1;
    } else {
      p->animIDOffset = p->facing >> 1;
      p->xflip = 0;
    }

    AllySabata_PlayAnim(p, 446, Q6(1));
    sound_08240740(SONG_870);
    PlaySound_082406e0(SONG_874);
    return;
  }

  if (p->hurtbox.knockbackPower != 0) {
    if (p->originKnockback != 0) {
      s32 dx = p->mover.pos.x - p->knockbackOrigin->x;
      s32 dz = p->mover.pos.z - p->knockbackOrigin->z;

      p->mover.delta.x = FixToInt(3, -dx);
      p->mover.delta.z = FixToInt(3, -dz);
      if (p->knockbackTimer > 0x55 && !(p->knockbackTimer & 1)) {
        PlaySound_082406e0(SE_401);
      }
    } else {
      s32 angle = ((p->facing + 5) & 7) * 32;

      p->mover.delta.x = -FixToInt(12, COS(angle) * p->hurtbox.knockbackPower);
      p->mover.delta.z = -FixToInt(12, SIN(angle) * p->hurtbox.knockbackPower);
    }

    p->hurtbox.knockbackPower = (p->hurtbox.knockbackPower * 3) >> 2;
    return;
  }

  if (p->emitter.kind == 3 && p->emitter.unk_3 != 0) {
    AllySabata_SetAction(p, PACT_UNK_19, 0);
    return;
  }

  if (AllySabata_PlayAnim(p, 448, Q6(1))) {
    p->hurtbox.knockbackPower = 0;
    p->originKnockback = FALSE;
    AllySabata_SetAnimFacing(p);
    AllySabata_SetAction(p, PACT_IDLE, 0);
  }
}

// サバタの行動 0x19, 吹き飛ばされて浮き上がり、落ちて起き上がるまでの一連
void FUN_08082670(Player* p) {
  if (p->action != PACT_UNK_25) {
    AllySabata_SetAction(p, PACT_UNK_25, 0);
    if (p->facing > 4) {
      p->animIDOffset = (8 - p->facing) >> 1;
      p->xflip = 1;
    } else {
      p->animIDOffset = p->facing >> 1;
      p->xflip = 0;
    }

    sound_08240740(SONG_870);
    PlaySound_082406e0(SONG_875);
  }

  switch (p->state) {
    case 0: {
      AllySabata_PlayAnim(p, 446, Q6(1));
      p->stateTimer++;
      if (p->stateTimer > 2) {
        AllySabata_SetAction(p, PACT_UNK_25, 1);
      }
      break;
    }
    case 1: {
      s32 angle;

      if (p->stateTimer == 0) {
        p->floatHeight = 0x12C;
      }

      AllySabata_PlayAnim(p, 452, Q6(1));
      angle = ((p->facing + 5) & 7) * 32;
      p->mover.delta.x = -FixToInt(12, COS(angle) * p->hurtbox.knockbackPower);
      p->mover.delta.z = -FixToInt(12, SIN(angle) * p->hurtbox.knockbackPower);
      p->hurtbox.knockbackPower = (p->hurtbox.knockbackPower * 3) >> 2;
      if (p->stateTimer > 3) {
        if (p->floatHeight >= p->stateTimer * 8) {
          p->floatHeight -= p->stateTimer * 8;
        } else {
          p->floatHeight = 0;
        }
      }

      p->stateTimer++;
      if (p->hurtbox.knockbackPower <= 19 && p->floatHeight == 0) {
        p->floatHeight = 0;
        PlaySound_082406e0(SE_826);
        AllySabata_SetAction(p, PACT_UNK_25, 2);
      }
      break;
    }
    case 2: {
      s32 angle = ((p->facing + 5) & 7) * 32;

      p->mover.delta.x = -FixToInt(12, COS(angle) * p->hurtbox.knockbackPower);
      p->mover.delta.z = -FixToInt(12, SIN(angle) * p->hurtbox.knockbackPower);
      if (AllySabata_PlayAnim(p, 454, Q6(1))) {
        p->hurtbox.knockbackPower = 0;
        AllySabata_SetAction(p, PACT_UNK_25, 3);
      }
      break;
    }
    case 3: {
      p->stateTimer++;
      if (p->stateTimer > 0x13) {
        AllySabata_SetAction(p, PACT_UNK_25, 4);
      }
      break;
    }
    case 4: {
      if (AllySabata_PlayAnim(p, 456, Q6(1))) {
        p->unk_3d2 = 0;
        AllySabata_SetAnimFacing(p);
        p->unk_46d++;
        if (p->unk_46d >= p->unk_46c) {
          p->unk_46d = 0;
          p->unk_474 = p->unk_472;
        }
        AllySabata_SetAction(p, PACT_IDLE, 0);
      }
      break;
    }
  }
}

// サバタの行動 0x12, 構えて unk_474 フレーム数えてから Emote_Show を呼び直し、アニメが終わったら行動 0 に戻す
void FUN_08082970(Player* p) {
  if (p->action != PACT_UNK_18) {
    sound_08240740(SONG_870);
    PlaySound_082406e0(SONG_879);
    AllySabata_SetAction(p, PACT_UNK_18, 0);
  }

  switch (p->state) {
    case 0: {
      if (AllySabata_PlayAnim(p, 498, Q6(1))) {
        p->emoteKind = EMOTE_1;
        p->emote = Emote_Show(p->emote, &p->mover, EMOTE_1, 0, &p->unk_474, p->unk_472, 300, 380);
        AllySabata_SetAction(p, PACT_UNK_18, 1);
      }
      break;
    }
    case 1: {
      p->unk_474--;
      if (p->unk_474 == 0) {
        p->emote = Emote_Show(p->emote, &p->mover, p->emoteKind, 0x7F, NULL, 0, 300, 380);
        AllySabata_SetAction(p, PACT_UNK_18, 2);
      }
      break;
    }
    case 2: {
      if (AllySabata_PlayAnim(p, 503, Q6(1))) {
        AllySabata_SetAction(p, PACT_IDLE, 0);
      }
      break;
    }
  }
}

// サバタの行動 0x13, 2フレームに1回 gPlayerPtr[0] の方へ向きを1段ずつ回し、16フレーム経ったら行動 2 に移る
// 残差2命令 (134/136) でこちらが短い: 定数 7 を r3 に残して向き差の & 7 でも使い回すが, 原典は movs を打ち直す
// Tier A-C 試済: 向き差の書き方 (dir - facing + 8 / dir - (facing - 8)), facing のローカル化
NON_MATCH void FUN_08082a94(Player* p) {
#ifdef NONMATCHING_C
  if (p->action != PACT_UNK_19) {
    sound_08240740(SONG_870);
    PlaySound_082406e0(SONG_873);
    p->emoteKind = EMOTE_0;
    p->emote = Emote_Show(p->emote, &p->mover, EMOTE_0, 3, &p->unk_474, p->unk_472, 300, 380);
    AllySabata_SetAction(p, PACT_UNK_19, 0);
  }

  if (!(p->stateTimer & 1)) {
    s32 dx = gPlayerPtr[0]->mover.pos.x - p->mover.pos.x;
    s32 dz = gPlayerPtr[0]->mover.pos.z - p->mover.pos.z;
    s32 dir = (((((u16)ArcTan2_8(dx, dz) + 0x10) & 0xFF) >> 5) + 3) & 7;

    if (dir != p->facing) {
      if (((dir - p->facing + 8) & 7) > 4) {
        p->facing = (p->facing + 7) & 7;
      } else {
        p->facing = (p->facing + 1) & 7;
      }
    }

    AllySabata_SetAnimFacing(p);
    AllySabata_PlayAnim(p, 414, Q6(1));
  }

  p->stateTimer++;
  if (p->stateTimer > 15) {
    p->emote = Emote_Show(p->emote, &p->mover, p->emoteKind, 0x7F, NULL, 0, 300, 380);
    AllySabata_SetAction(p, PACT_DASH, 0);
  }
#else
  INCFUNC("asm/func/FUN_08082a94.inc");
#endif
}

// サバタの行動2, 経路の次の点へ歩く, 遠いほど unk_3f2 が上がって姿が薄くなる
// 残差2命令 (195/197) でこちらが短い: 原典は abs の結果を別レジスタで作ってから dx / dz に移すが, こちらは行き先で直接作る
// src/sabata.c の FUN_0808301c が同じ現象で止まっている
// Tier A-C 試済: abs() / 手書きの符号反転 / static inline の Abs (どれも同じ出力)
NON_MATCH void FUN_08082bdc(Player* p) {
#ifdef NONMATCHING_C
  s32 dx;
  s32 dz;

  if (p->action != PACT_DASH) {
    AllySabata_SetAction(p, PACT_DASH, 0);
  }
  AllySabata_SetFlag35a(p, PFLAG35A_HIDE_SHADOW | PFLAG35A_NO_HURTBOX | PFLAG35A_NO_TILE);

  dx = abs(p->navAgent.unk_0c.x - p->mover.pos.x);
  dz = abs(p->navAgent.unk_0c.z - p->mover.pos.z);
  if (dx <= 0x1F && dz <= 0x1F) {
    p->unk_3f2 = 0;
    p->mover.pos.x = p->navAgent.unk_0c.x;
    p->mover.pos.z = p->navAgent.unk_0c.z;
    AllySabata_PlayAnim(p, 419, Q6(0.5));
    p->facing = p->pathEndFacing;
    AllySabata_SetAnimFacing(p);
    AllySabata_SetAction(p, p->pathEndAction, 0);
  } else {
    s32 angle;

    p->plttID_95e = 295;
    p->plttFlashTimer = 24;
    if (dx > 0xBF || dz > 0xBF) {
      if (p->unk_3f2 <= 4) {
        p->unk_3f2++;
      }
    } else if (p->unk_3f2 != 0) {
      p->unk_3f2--;
    }

    if (p->unk_3f2 == 5) {
      AllySabata_SetFlag35a(p, PFLAG35A_HIDE_BODY | PFLAG35A_BLINK);
    } else if (p->unk_3f2 != 0) {
      AllySabata_SetFlag35a(p, PFLAG35A_BLINK);
    }

    dx = p->navAgent.unk_1c.x - p->mover.pos.x;
    dz = p->navAgent.unk_1c.z - p->mover.pos.z;
    angle = ArcTan2_8(dx, dz);
    p->mover.delta.x = FixToInt(12, COS(angle) * 32);
    p->mover.delta.z = FixToInt(12, SIN(angle) * 32);
    if (FUN_08235fd8(&p->navAgent.flags)) {
      p->facing = (((((u16)ArcTan2_8(dx, dz) + 0x10) & 0xFF) >> 5) + 3) & 7;
      AllySabata_SetAnimFacing(p);
    }
    AllySabata_PlayAnim(p, 419, Q6(0.5));
  }
#else
  INCFUNC("asm/func/FUN_08082bdc.inc");
#endif
}

// サバタの行動9, 真横を向いて Entity080abd14 を出し、終わったら行動0 に戻る
// 残差1命令 (256/257) でこちらが短い: state 2 の stateTimer の 16bit 切り詰めを, 原典は 0xFFFF をレジスタに置いて ands するが, こちらは lsls/lsrs で済ませる
NON_MATCH void FUN_08082dac(Player* p) {
#ifdef NONMATCHING_C
  if (p->action != PACT_SUN_MAGIC) {
    AllySabata_SetAction(p, PACT_SUN_MAGIC, 0);
    p->unk_951 = 0;
  }

  switch (p->state) {
    case 0: {
      if (p->facing >= 2 && p->facing <= 6) {
        p->facing = FACE_DOWN;
        p->animIDOffset = 4;
        p->xflip = 0;
        p->pos_930 = p->mover.pos;
        p->pos_930.x -= 0x14;
        p->pos_930.y += 0x14A;
        p->pos_930.z += 0x3C;
      } else {
        p->facing = FACE_UP;
        p->animIDOffset = 0;
        p->xflip = 0;
        p->pos_930 = p->mover.pos;
        p->pos_930.x += 0x14;
        p->pos_930.y += 0x14A;
        p->pos_930.z -= 0x14;
      }

      AllySabata_PlayAnim(p, 414, Q6(1));
      if (p->facing == FACE_DOWN) {
        p->animIDOffset = 1;
      } else {
        p->animIDOffset = 0;
      }

      AllySabata_SetAction(p, PACT_SUN_MAGIC, 1);
      p->plttID_95e = 290;
      p->plttFlashTimer = 2;
      PlaySound_082406e0(SONG_878);
      Entity080abd14_Create(p, &p->mover.pos, &p->pos_930, 1, p->unk_3ba);
      p->unk_477 = 0x3C;
      break;
    }
    case 1: {
      p->plttID_95e = 290;
      p->plttFlashTimer += 3;
      if (p->plttFlashTimer > 32) {
        p->plttFlashTimer = 32;
      }

      p->shadowOffset.z = 0xF;
      if (AllySabata_PlayAnim(p, 466, Q6(1))) {
        PlaySound_082406e0(SONG_203);
        AllySabata_SetAction(p, PACT_SUN_MAGIC, 2);
      }
      break;
    }
    case 2: {
      AllySabata_PlayAnim(p, 470, Q6(1));
      p->plttID_95e = 290;
      p->plttFlashTimer += 3;
      if (p->plttFlashTimer > 32) {
        p->plttFlashTimer = 32;
      }

      p->shadowOffset.z = 0x1E;
      p->stateTimer++;
      if (p->stateTimer > 0x17) {
        AllySabata_SetAction(p, PACT_SUN_MAGIC, 3);
      }
      break;
    }
    case 3: {
      p->shadowOffset.z = 0xF;
      if (AllySabata_PlayAnim(p, 472, Q6(1))) {
        AllySabata_SetAnimFacing(p);
        AllySabata_SetAction(p, PACT_IDLE, 0);
      }
      break;
    }
  }
#else
  INCFUNC("asm/func/FUN_08082dac.inc");
#endif
}

// サバタの行動8, 構えたまま点滅し、カメラ注視点との位置関係から次の巡回地点を選んで行動2 に移る
// 残差3命令 (194/197) でこちらが短い: 原典は abs の結果と ArcTan2_8 の2引数をそれぞれ別レジスタで作ってから移し替えるが, こちらは行き先のレジスタで直接作る
// Tier A-C 試済: abs() と手書きの符号反転, 差分を一旦ローカルに取る形, idx = 0 の位置
NON_MATCH void FUN_0808301c(Player* p) {
#ifdef NONMATCHING_C
  if (p->action != PACT_UNK_8) {
    AllySabata_SetAction(p, PACT_UNK_8, 0);
  }
  p->unk_951 = 9;

  switch (p->state) {
    case 0: {
      if (AllySabata_PlayAnim(p, 478, Q6(1))) {
        AllySabata_SetAction(p, PACT_UNK_8, 1);
      }
      break;
    }
    case 1: {
      WorldPos* target;
      s32 dx;
      s32 dz;

      FUN_08084754();
      p->plttID_95e = 290;
      if (p->stateTimer <= 0x1F) {
        p->plttFlashTimer = p->stateTimer;
      } else {
        p->plttFlashTimer = 64 - p->stateTimer;
      }

      p->stateTimer++;
      if (p->stateTimer > 0x40) {
        p->stateTimer = 0;
      }

      AllySabata_PlayAnim(p, 483, Q6(1));
      target = FUN_080230c4();
      dx = abs(target->x - p->mover.pos.x);
      dz = abs(target->z - p->mover.pos.z);

      p->eneAccum++;
      if ((dx <= 0xBF && dz <= 0xBF) || p->eneAccum > 0x59) {
        WorldPos pos;
        s32 ax;
        s32 az;
        s32 angle;
        s32 idx;

        FUN_08084734(&pos);
        ax = pos.x - target->x;
        az = pos.z - target->z;
        angle = ArcTan2_8(ax, az);
        idx = 0;
        switch (((angle + 0x20) & 0xFF) >> 6) {
          case 0: {
            idx = 3;
            break;
          }
          case 1: {
            idx = 1;
            break;
          }
          case 2: {
            idx = 2;
            break;
          }
        }

        if (((p->unk_4a6 + 3) & 3) != idx && FUN_08235f40(&p->navAgent, &p->mover.pos, &p->waypoints[idx])) {
          p->pathEndAction = PACT_UNK_8;
          p->pathEndFacing = p->waypoints[idx].val;
          p->unk_4a6 = (idx + 1) & 3;
          FUN_08084798(0x1E);
          AllySabata_SetAction(p, PACT_DASH, 0);
        }

        p->eneAccum = 0;
      }
      break;
    }
  }
#else
  INCFUNC("asm/func/FUN_0808301c.inc");
#endif
}

// 向いている方向の少し前に Entity080cbabc を出して効果音を鳴らす
void FUN_080831e0(Player* p, s32 param_2, s32 param_3, s32 param_4) {
  s32 angle = ((p->facing + 5) & 7) * 32;
  WorldPos pos = p->mover.pos;

  pos.x = p->mover.pos.x + POLAR_X(150, angle);
  pos.y = p->mover.pos.y + Q8(0.9);
  pos.z = p->mover.pos.z + POLAR_Z(150, angle);
  Entity080cbabc_Create(&pos, angle, 0x20, param_2, param_3, p->wpn.atkPower, p->wpn.knockbackPower, param_4, p->wpn.atkInvincibleTime);
  PlaySound_082406e0(SONG_871);
}

// サバタの行動3, 2〜3回斬りつけてから間合いを取り直す
void FUN_080832b8(Player* p) {
  if (p->action != PACT_ATTACK) {
    AllySabata_SetAction(p, PACT_ATTACK, 0);
  }
  p->unk_951 = 9;

  switch (p->state) {
    case 0: {
      if (AllySabata_PlayAnim(p, 478, Q6(1))) {
        AllySabata_SetAction(p, PACT_ATTACK, 1);
        p->unk_46e = 0;
        p->slashCount = (Random() & 1) + 2;
      }
      break;
    }
    case 1: {
      if (p->stateTimer == 0) {
        PlaySound_082406e0(SE_GUN_AIM);
      }

      AllySabata_PlayAnim(p, 483, Q6(1));
      p->stateTimer++;
      if (p->stateTimer > 4) {
        if (FUN_080298dc()) {
          AllySabata_SetAction(p, PACT_ATTACK, 2);
        } else {
          FUN_080831e0(p, 1, 6, 2);
          AllySabata_SetAction(p, PACT_ATTACK, 5);
        }
      }
      break;
    }
    case 2: {
      AllySabata_PlayAnim(p, 483, Q6(1));
      p->stateTimer++;
      if (p->stateTimer > 0x20) {
        WorldPos pos;
        s32 dir;

        if (FUN_08081de0(p, &pos, &dir) && FUN_08235f40(&p->navAgent, &p->mover.pos, &pos)) {
          p->pathEndAction = PACT_ATTACK;
          p->pathEndFacing = dir;
          AllySabata_SetAction(p, PACT_DASH, 6);
        }
      } else if (gPlayerPtr[0]->action != PACT_GRABBED) {
        AllySabata_SetAction(p, PACT_ATTACK, 6);
      }
      break;
    }
    case 5: {
      AllySabata_PlayAnim(p, 488, Q6(1));
      p->stateTimer++;
      if (p->stateTimer > 4) {
        p->unk_46e++;
        if (p->unk_46e < p->slashCount) {
          AllySabata_SetAction(p, PACT_ATTACK, 1);
        } else if (gPlayerPtr[0]->action == PACT_GRABBED) {
          WorldPos pos;
          s32 dir;

          if (FUN_08081de0(p, &pos, &dir) && FUN_08235f40(&p->navAgent, &p->mover.pos, &pos)) {
            p->pathEndAction = PACT_ATTACK;
            p->pathEndFacing = dir;
            AllySabata_SetAction(p, PACT_DASH, 6);
          }
        } else {
          AllySabata_SetAction(p, PACT_ATTACK, 6);
        }
      }
      break;
    }
    case 6: {
      AllySabata_PlayAnim(p, 483, Q6(1));
      p->stateTimer++;
      if (p->stateTimer > 9) {
        AllySabata_SetAction(p, PACT_ATTACK, 7);
      }
      break;
    }
    case 7: {
      AllySabata_PlayAnim(p, 478, Q6(1));
      p->stateTimer++;
      if (p->stateTimer > 4) {
        if (FUN_08235f40(&p->navAgent, &p->mover.pos, &p->waypoints[p->unk_4a6])) {
          p->pathEndAction = PACT_UNK_8;
          p->pathEndFacing = p->waypoints[p->unk_4a6].val;
          AllySabata_SetAction(p, PACT_DASH, 0);
          p->unk_4a6 = (p->unk_4a6 + 1) & 3;
        } else {
          AllySabata_SetAction(p, PACT_IDLE, 0);
        }
      }
      break;
    }
  }
}

NAKED void FUN_080835d8(Player* p) { INCFUNC("asm/func/FUN_080835d8.inc"); }

// 次に移る action を決める, 被弾・停止中・巡回・1P への接近の順に見ていく
s32 FUN_08083eac(Player* p) {
  s32 action;

  if (gRisingSunCount != 0) {
    PlaySound_082406e0(SONG_874);
    p->unk_474 = p->unk_472;
  }

  if (p->hurtbox.knockbackPower != 0) {
    if (p->unk_3d2 != 0) {
      return PACT_UNK_25;
    }
    return PACT_UNK_24;
  }

  action = p->action;
  if (action == PACT_UNK_24 || action == PACT_UNK_25 || action == PACT_GRABBED) {
    return action;
  }

  if (gRisingSunCount != 0) {
    p->human.flags &= ~(SPRFLAG_HIDDEN | SPRFLAG_BLINK_ODD | SPRFLAG_BLINK_EVEN);
    p->hurtbox.knockbackPower = 50;
    p->unk_3d2 = 0;
    p->facing |= 1;
    return PACT_UNK_24;
  }

  if (action == PACT_UNK_18 || p->unk_474 != 0) {
    return PACT_UNK_18;
  }
  if (action == PACT_DASH || action == PACT_ATTACK) {
    return action;
  }
  if (action == PACT_UNK_19) {
    return PACT_UNK_19;
  }

  if (gPlayerPtr[0]->action == PACT_GRABBED) {
    if (!p->approachUsed) {
      WorldPos pos;
      s32 dir;

      if (FUN_08081da4(p->unk_467) && FUN_08081de0(p, &pos, &dir) && FUN_08235f40(&p->navAgent, &p->mover.pos, &pos)) {
        p->pathEndAction = PACT_ATTACK;
        p->pathEndFacing = dir;
        return PACT_UNK_19;
      }
      p->approachUsed = 1;
    }
  } else {
    p->approachUsed = 0;
  }

  if (action == PACT_WALK) {
    return PACT_WALK;
  }
  if (action == PACT_UNK_20) {
    return PACT_UNK_20;
  }
  if (action == PACT_UNK_8) {
    return PACT_UNK_8;
  }

  if (FUN_08235f40(&p->navAgent, &p->mover.pos, &p->waypoints[p->unk_4a6])) {
    p->pathEndAction = PACT_UNK_8;
    p->pathEndFacing = p->waypoints[p->unk_4a6].val;
    p->unk_4a6 = (p->unk_4a6 + 1) & 3;
    return PACT_DASH;
  }

  return PACT_IDLE;
}

// 毎フレームの移動反映, 壁に当たる向きの移動を捨ててから mover を進め、flag35a に応じて影やスプライトを切り替える
void FUN_08084078(Player* p) {
  WorldPos next;

  next.x = p->mover.pos.x + p->mover.delta.x;
  next.z = p->mover.pos.z + p->mover.delta.z;
  if (GetTileAttrAt(&next) & TATTR_WALL) {
    p->mover.delta.x = 0;
    p->mover.delta.z = 0;
  }

  if (AllySabata_TestFlag35a(p, PFLAG35A_NO_TILE)) {
    p->mover.tile = NULL;
    Mover_ApplyMove(&p->mover);
    p->mover.pos.y = TileHeightAt(&p->mover.pos);
  } else {
    if (p->mover.tile == NULL) {
      Map_InitMoverTile(&p->tile, &p->mover.pos);
      p->mover.tile = &p->tile;
    }
    Mover_ApplyMove(&p->mover);
  }

  if (AllySabata_TestFlag35a(p, PFLAG35A_NO_HURTBOX)) {
    p->hurtbox.flags |= HBFLAG_HIDDEN;
  } else {
    p->hurtbox.flags &= ~HBFLAG_HIDDEN;
    Hitbox_SetPos(&p->hurtbox, &p->mover.pos, 0);
  }

  if (AllySabata_TestFlag35a(p, PFLAG35A_UNK_5)) {
    p->unk_464 = 0;
  } else {
    if (p->unk_464 == 0) {
      Map_InitNavAgent(&p->navAgent, &p->mover.pos);
      p->unk_464 = 1;
    }
    Map_StepNavPath(&p->navAgent, &p->mover.pos);
  }

  p->human.pos = p->mover.pos;
  p->human.pos.y += p->floatHeight;

  if (AllySabata_TestFlag35a(p, PFLAG35A_HIDE_BODY)) {
    p->human.flags |= SPRFLAG_HIDDEN;
  } else {
    p->human.flags &= ~SPRFLAG_HIDDEN;
  }

  if (AllySabata_TestFlag35a(p, PFLAG35A_BLINK)) {
    p->human.flags |= SPRFLAG_BLINK_ODD;
  } else {
    p->human.flags &= ~SPRFLAG_BLINK_ODD;
  }

  if (AllySabata_TestFlag35a(p, PFLAG35A_HIDE_SHADOW)) {
    ParticleShadow_Hide(&p->shadow);
  } else {
    ParticleShadow_Show(&p->shadow);
  }

  if (AllySabata_TestFlag35a(p, PFLAG35A_UNK_7)) {
    p->wpn.sprite.flags &= ~SPRFLAG_HIDDEN;
  } else {
    p->wpn.sprite.flags |= SPRFLAG_HIDDEN;
  }
}

void FUN_08081f80(Player* p);
void FUN_08081fb4(Player* p);
void FUN_08082bdc(Player* p);
void FUN_080832b8(Player* p);
void FUN_08082154(Player* p);
void FUN_0808301c(Player* p);
void FUN_08082dac(Player* p);
void FUN_08082970(Player* p);
void FUN_08082a94(Player* p);
void FUN_080835d8(Player* p);
void FUN_08082464(Player* p);
void FUN_08082498(Player* p);
void FUN_08082670(Player* p);

const PlayerFunc PTR_ARRAY_085abf54[29] = {
    [PACT_IDLE] = FUN_08081f80,
    [PACT_WALK] = FUN_08081fb4,
    [PACT_DASH] = FUN_08082bdc,
    [PACT_ATTACK] = FUN_080832b8,
    [PACT_UNK_7] = FUN_08082154,
    [PACT_UNK_8] = FUN_0808301c,
    [PACT_SUN_MAGIC] = FUN_08082dac,
    [PACT_UNK_18] = FUN_08082970,
    [PACT_UNK_19] = FUN_08082a94,
    [PACT_UNK_20] = FUN_080835d8,
    [PACT_GRABBED] = FUN_08082464,
    [PACT_UNK_24] = FUN_08082498,
    [PACT_UNK_25] = FUN_08082670,
};  // 0x085ABF54

// state 1 なら太陽ゲージの半分を渡してから行動関数表を引いて呼び、state 2 なら fn_498 を呼ぶ
// 残差は p が r4 か r5 かだけ (47対47, 命令列は一致), こちらは callee-saved を1本多く使って push {r4,r5,lr} になる
// Tier A-C 試済: switch 形にして分岐は一致, FUN_08081d18 の第2引数を s32 に, ゲージをローカルに受けて ldrsh 化
NON_MATCH void FUN_08084330(Player* p) {
#ifdef NONMATCHING_C
  switch (p->mode) {
    case PMODE_ACTIVE: {
      if (p->flag20 & PFLAG20_SUNBATHING) {
        s32 gauge = gStat->sunGauge;

        FUN_08081d18(p, gauge >> 1);
      }
      PTR_ARRAY_085abf54[FUN_08083eac(p)](p);
      FUN_08084078(p);
      break;
    }
    case PMODE_LOCKED: {
      AllySabata_SetFlag35a(p, PFLAG35A_NO_HURTBOX);
      p->fn_498(p);
      FUN_08084078(p);
      break;
    }
  }
#else
  INCFUNC("asm/func/FUN_08084330.inc");
#endif
}

// サバタの被弾処理, 行動8 の間は規定回数まで弾き, 超えたら弾き返すか行動 0x14 に移る
// 命令数は一致 (181/181), 残差は a->flags の扱いだけ: こちらは最初の判定で r7 に退避して最後の HBFLAG_ANGLE 判定で使い回すが, 原典は読み直す
// そのぶん原典は r7 が空いていて 0x46A のアドレスを 0x37C から add #0xee で作れている
// Tier A-C 試済: Hitbox_TestFlags / 直接 & の書き分け (最初はヘルパ形, 最後は直接形で原典のオペランド順になる), 判定順の入れ替え
NON_MATCH void AllySabata_OnHurt(HitboxData* a, HitboxData* b, Player* p) {
#ifdef NONMATCHING_C
  if (p->mode != PMODE_ACTIVE) {
    return;
  }

  if (Hitbox_TestFlags(a, HBFLAG_UNK_9)) {
    if (!(b->hitState & HBHITSTATE_UNK_0)) {
      return;
    }
    b->hitState &= ~HBHITSTATE_UNK_0;
  }

  b->invincibleTime = a->invincibleTime;

  if (p->action == PACT_UNK_8 && p->state != 0) {
    p->unk_476 = 4;
    if (Hitbox_HasWeakness(a, HBATTR_NAMAKURA)) {
      p->namakuraCount++;
      if (p->namakuraCount >= p->namakuraLimit) {
        p->namakuraCount = 0;
        AllySabata_SetAction(p, PACT_UNK_20, 0);
        return;
      }
    } else {
      p->blockCount++;
      if (p->blockCount >= p->blockLimit) {
        p->blockCount = 0;
        p->facing = FUN_08080f20(a, b);
        p->unk_3d2 = 1;
        b->knockbackPower = 100;
        return;
      }
    }

    PlaySound_082406e0(SONG_874);
    return;
  }

  p->blockCount = 0;
  if (Hitbox_TestAttr(a, HBATTR_18) || !Player_TestFlag20(p, PFLAG20_UNK_15)) {
    FUN_08080f80(p, a, b);
    return;
  }

  p->knockbackSpeed = a->knockbackPower;
  if (a->flags & HBFLAG_ANGLE) {
    p->knockbackDir = ((((a->angle + 0x10) & 0xFF) >> 5) + 3) & 7;
  } else {
    s32 dx = a->center.x - b->center.x;
    s32 dz = a->center.z - b->center.z;

    p->knockbackDir = (((((((u16)ArcTan2_8(dx, dz) + 0x10) & 0xFF) >> 5) + 3) & 7) + 4) & 7;
  }
#else
  INCFUNC("asm/func/AllySabata_OnHurt.inc");
#endif
}

// 被弾後の無敵時間を1フレーム減らし、4フレームおきにスプライトと影を消して点滅させる
// 残差は r4 と r5 の入れ替えのみ (40対40, 命令列は完全一致), 原典は p=r4 / 残り時間=r5
// Tier A-C 試済: 宣言と代入の分離 / 早期 return 形 / ネスト形 (いずれも割り当てが裏返らない)
NON_MATCH void FUN_08084540(Player* p) {
#ifdef NONMATCHING_C
  s32 v = p->hurtbox.invincibleTime;

  if (v > 0) {
    AllySabata_SetFlag35a(p, PFLAG35A_NO_HURTBOX);
    if (p->hurtbox.knockbackPower == 0) {
      v--;
      if (v != 0 && p->unk_476 == 0 && ((v >> 2) & 1) != 0) {
        AllySabata_SetFlag35a(p, PFLAG35A_HIDE_BODY | PFLAG35A_HIDE_SHADOW);
      }
      p->hurtbox.invincibleTime = v;
    }
  }
#else
  INCFUNC("asm/func/FUN_08084540.inc");
#endif
}

s32 AllySabata_Update(Player* p) {
  if (!(gPlayerPtr[0]->mode & PMODE_DEAD)) {
    FUN_08080e34(p);
    FUN_08084540(p);
    p->updateCallback(p);
    FUN_08081628(p);
  }
  return 0;
}

s32 AllySabata_Destroy(Player* p) {
  MainSprite_Remove(&p->human);
  Hitbox_Unregister(&p->hurtbox);
  Mover_Unlink(&p->mover);
  FUN_0808168c(p);
  AuxSprite_Remove(&p->wpn.sprite);
  gPlayerPtr[p->mover.unk_4] = NULL;
  gPlayerCount--;
  return 0;
}

s32 AllySabata_Init(Player* p, u32 id, unknown* param_3) {
  FUN_08081ab0(p, id);
  AllySabata_SetupHurtbox(p);
  FUN_080817ec(p);
  FUN_08081c04(p);
  FUN_080816a0(p);
  gPlayerPtr[p->mover.unk_4] = p;
  gPlayerCount++;
  return 0;
}

// 0x2B06, HashName("サバタ"), リンゴやダーイン戦での共闘NPCとしてのサバタ
Player* AllySabata_Create(u32 id, unknown* param_2) {
  if (gPlayerPtr[1] == NULL) {
    Player* p = CreateEntity(ENTITY_PLAYER, sizeof(Player));

    if (p != NULL) {
      SetEntityRoutine(p, AllySabata_Update, AllySabata_Destroy);
      if (AllySabata_Init(p, id, param_2) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gPlayerPtr[1];
}
