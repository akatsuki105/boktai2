#include "boss/dvalinn.h"
#include "camera.h"
#include "camera_inline.h"
#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "map_inline.h"
#include "mover.h"
#include "player.h"
#include "random.h"
#include "sound.h"
#include "sprite_aux.h"
#include "trig.h"
#include "vec3.h"

void FUN_081fa608(void);
void FUN_08204d04(Vec3* pos, s32 param_2);
void* Entity081f26bc_Spawn(Vec3* pos, Vec3* vel, u32 sprID, u32 animFID, u32 animIdx, SpriteFlags sprFlags, u32 flags, s32 plttID, u32 prio, u32 animVariant, u32 animFlags, u32 life, s32 power, s32 knockback, HitboxAttributes attrs, s32 invincibleTime, s32 ofsX, s32 ofsY);
void FUN_081ee53c(Vec3* pos, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, s32 a8, s32 a9, s32 a10, s32 a11, s32 a12, s32 a13, s32 a14, s32 a15, s32 a16, s32 a17);
void FUN_081ea540(Mover* a, Mover* b, s32 param_3, s32 param_4, s32 param_5, s32 param_6);

const u16 u16_ARRAY_085ae7b8[8] = {64, 64, 64, 64, 64, 128, 128, 128};  // 0x085AE7B8

const u16 u16_ARRAY_085ae7c8[8] = {4096, 4096, 4096, 4096, 4096, 16384, 16384, 16384};  // 0x085AE7C8

const s32 s32_ARRAY_085ae7d8[8] = {-100, -60, -40, -30, -20, 10, 45, 0};  // 0x085AE7D8

// pos の y を足元のタイルの高さにして返す
s32 FUN_08200ab4(Vec3* pos) {
  CollisionMapTile* tile = GetTileAt(pos);
  s32 height = (tile->heightStairs & 0xF) << 8;

  pos->y = height;
  return height;
}

void FUN_08200b2c(Entity08202cd8* p, u8 val) { p->unk_6db = val; }

void FUN_08200b38(AuxSprite* spr) { Video_SetAuxSpritePltt(spr->gfx, 306); }

void FUN_08200b48(AuxSprite* spr, Entity08202cd8* p) { Video_SetAuxSpritePltt(spr->gfx, 561); }

// 1枚目のスプライトの位置から自機へ向けて何かを飛ばす
void FUN_08200b5c(Entity08202cd8* p) {
  Mover* q = &gPlayerPtr[0]->mover;
  Mover m;

  m.pos = p->sprites[0].pos;
  FUN_081ea540(&m, q, 10, 30, 0, 10);
}

// 被弾の点滅を戻し、溜まったダメージを両端の中点にまとめて出す
NON_MATCH void FUN_08200b8c(Entity08202cd8* p) {
#ifdef NONMATCHING_C
  s32 i;

  if (p->unk_24 != 0) {
    p->unk_24--;
    if (p->unk_24 == 0) {
      for (i = 0; i < 8; i++) {
        FUN_08200b48(&p->sprites[i], p);
      }
    }
  }
  if (p->unk_25 != 0) {
    p->unk_25--;
  } else if (p->unk_6ec > 0) {
    Vec3 pos, size;

    FUN_081fa608();
    pos.x = p->sprites[7].pos.x - p->sprites[0].pos.x;
    pos.y = p->sprites[7].pos.y - p->sprites[0].pos.y;
    pos.z = p->sprites[7].pos.z - p->sprites[0].pos.z;
    pos.x >>= 1;
    pos.y >>= 1;
    pos.z >>= 1;
    pos.x += p->sprites[0].pos.x;
    pos.y += p->sprites[0].pos.y;
    pos.z += p->sprites[0].pos.z;
    size.x = 0x10, size.y = 0, size.z = 0x10;
    CreateDamageNumber(&p->hitboxB[0], p->unk_6ec, 0, &pos, &size, 1);
    p->unk_6ec = 0;
  }
#else
  INCFUNC("asm/func/FUN_08200b8c.inc");
#endif
}

// 残差は p を受けるレジスタ (原典 r2, こちら r3) から始まる割り当ての違いと, unk_6da の番地を 0x6DC の定数から作るかどうか (103/106)
// 添字で書く形 (102) と sprite / hitboxA / hitboxB の歩きポインタを持つ形は試済
// 4フレームに1回ずつ, 各スプライトのヒットボックスを位置合わせして登録する
NON_MATCH void FUN_08200c8c(Entity08202cd8* p) {
#ifdef NONMATCHING_C
  s32 i;

  if (p->unk_6dc == 7) {
    return;
  }
  if (p->unk_6da != 0 || p->unk_25 != 0) {
    for (i = 0; i < 8; i++) {
      p->hitboxB[i].flags |= HBFLAG_HIDDEN;
    }
  } else {
    s32 start = gFrameCounter & 3;
    AuxSprite* spr = &p->sprites[start];
    HitboxData* a = &p->hitboxA[start];
    HitboxData* b = &p->hitboxB[start];

    for (i = start; i < 8; i += 4) {
      Hitbox_SetPos(b, &spr->pos, 0);
      b->flags &= ~HBFLAG_HIDDEN;
      if (i + 1 < 8) {
        b[1].flags |= HBFLAG_HIDDEN;
      }
      Hitbox_SetPos(a, &spr->pos, 0);
      if (p->unk_25 == 0) {
        Hitbox_Register(a);
      }
      spr += 4;
      a += 4;
      b += 4;
    }
  }
#else
  INCFUNC("asm/func/FUN_08200c8c.inc");
#endif
}

// b を a から規定の距離より離れないように引き寄せる
void FUN_08200d70(AuxSprite* a, AuxSprite* b, s32 idx) {
  Vec3 d;
  s32 dist;

  Vec3_Diff(&d, &b->pos, &a->pos);
  dist = d.x * d.x + d.y * d.y + d.z * d.z;
  if (dist > u16_ARRAY_085ae7c8[idx]) {
    s32 len = u16_ARRAY_085ae7b8[idx];
    u32 r = Sqrt(dist);

    if (r != 0) {
      d.x = Div(len * d.x, r);
      d.y = Div(len * d.y, r);
      d.z = Div(len * d.z, r);
    }
    Vec3_Sum(&b->pos, &a->pos, &d);
  }
}

// 残差は退避枠 4 バイトと高位レジスタの割り当て (249/248), 原典は p->sprites の先頭を sp+0x48 に退避して2つ目のループで使う
// sprites の歩きポインタ / unk_188 の歩きポインタを持つ形は試済 (命令が増える)
// 足の各関節をスクリーンに投影し, 隣どうしの向きから各スプライトのポーズを決める
NON_MATCH void FUN_08200e54(Entity08202cd8* p) {
#ifdef NONMATCHING_C
  Vec3 pts[9];
  s32 i;

  if (p->unk_6da != 0) {
    return;
  }
  for (i = 0; i < 8; i++) {
    WorldToScreen(&pts[i], &p->sprites[i].pos);
  }
  pts[8] = p->sprites[7].pos;
  pts[8].y -= 64;
  WorldToScreen(&pts[8], &pts[8]);

  for (i = 0; i < 8; i++) {
    if (i == 0) {
      p->unk_188[0] = Angle_ToDir8(ArcTan2_8(pts[0].x - pts[1].x, pts[0].y - pts[1].y) - 31);
    } else {
      p->unk_188[i] = Angle_ToDir8(ArcTan2_8(pts[i - 1].x - pts[i + 1].x, pts[i - 1].y - pts[i + 1].y) - 31);
    }
    if (i < 3 || i > 4) {
      p->sprites[i].poseIdx = p->unk_188[i];
    } else {
      p->sprites[i].poseIdx = p->unk_188[i] + 8;
    }
  }
#else
  INCFUNC("asm/func/FUN_08200e54.inc");
#endif
}

// 全スプライトとヒットボックスを同じ位置に置く
void FUN_08201054(Entity08202cd8* p, Vec3* pos) {
  s32 i;

  p->pos = *pos;
  for (i = 0; i < 8; i++) {
    p->sprites[i].pos = *pos;
    Hitbox_SetPos(&p->hitboxA[i], pos, 0);
    Hitbox_SetPos(&p->hitboxB[i], pos, 0);
  }
}

// 8枚のスプライトをすべて隠す
void FUN_082010b4(Entity08202cd8* p) {
  AuxSprite* spr = p->sprites;
  s32 i;

  for (i = 0; i < 8; i++) {
    spr->flags |= SPRFLAG_HIDDEN;
    spr++;
  }
}

// 8枚のスプライトをすべて表示する
void FUN_082010d0(Entity08202cd8* p) {
  AuxSprite* spr = p->sprites;
  s32 i;

  for (i = 0; i < 8; i++) {
    spr->flags &= ~SPRFLAG_HIDDEN;
    spr++;
  }
}

void FUN_082010f0(Entity08202cd8* p, u16 a, u16 b) {
  p->unk_20 = a;
  p->unk_22 = b;
}

// 下書き1回で止めた (344/333), 足を1本ずつ前の関節へ引き寄せる処理は FUN_08200d70 の本体と同じ形を手で展開している
// 退避枠 (原典 0x64, こちら 0x6C) と, 関節の歩きポインタを -0x2C ずつ減らす形の違いが主な残差
// 足を水面から突き上げる, 地上に出た関節から表示し, 4回出し終えたら終了の印を立てる
NON_MATCH void FUN_082010f8(Entity08202cd8* p, s32 val) {
#ifdef NONMATCHING_C
  Vec3 d;
  Vec3 vel;
  Vec3 spawnPos;
  s32 done;
  s32 i;

  if (val == 0) {
    VEC3_SET(d, p->pos.x, p->pos.y - 100, p->pos.z);
    for (i = 0; i < 8; i++) {
      p->sprites[i].pos = d;
    }
    p->unk_1c = 0;
    Vec3_Clear(&vel);
    spawnPos.x = p->pos.x + 64;
    spawnPos.y = p->pos.y - 32;
    spawnPos.z = p->pos.z + 64;
    Entity081f26bc_Spawn(&spawnPos, &vel, 0xF422, 0x121B, 6, 0, 9, 0x237, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    PlaySound_082406e0(SONG_438);
  }

  done = 0;
  for (i = 0; i < 7; i++) {
    p->sprites[i].pos.y += 28 - i;
  }
  for (i = 0; i < 7; i++) {
    AuxSprite* a = &p->sprites[7 - i];
    AuxSprite* b = &p->sprites[6 - i];
    s32 dist;

    Vec3_Diff(&d, &b->pos, &a->pos);
    dist = d.x * d.x + d.y * d.y + d.z * d.z;
    if (dist > u16_ARRAY_085ae7c8[7 - i]) {
      s32 len = u16_ARRAY_085ae7b8[7 - i];
      u32 r = Sqrt(dist);

      if (r != 0) {
        d.x = Div(len * d.x, r);
        d.y = Div(len * d.y, r);
        d.z = Div(len * d.z, r);
      }
      Vec3_Sum(&b->pos, &a->pos, &d);
    }
    if (b->pos.y >= p->pos.y) {
      b->flags &= ~SPRFLAG_HIDDEN;
      a->flags &= ~SPRFLAG_HIDDEN;
      done++;
    }
  }

  if (done > 6) {
    p->sprites[7].flags &= ~SPRFLAG_HIDDEN;
    p->sprites[7].pos = p->pos;
    p->unk_1c++;
  }
  if (p->unk_1c > 3) {
    p->unk_6d9 = 1;
  }
  if (Mod(val, 8) == 0) {
    FUN_081ee53c(&p->pos, 12, 8, 6, 12, 4, Random() & 0x7F, 8, 32, 1, 2, 0x200, 0, 0xF422, 0x121B, 0, 0, 0xDA);
  }
#else
  INCFUNC("asm/func/FUN_082010f8.inc");
#endif
}

// 下書き1回で止めた (437/441), 原典は Random を3回続けて引く箇所で gRandTableIdx への書き込みを最後の1回にまとめている
// 足のうねりと関節の引き寄せ, 32 フレームごとの落下物 / 破片の出し分けは Ghidra の形どおり
// 足をうねらせながら持ち上げ, 32 フレームごとに周りへ落下物か破片を出す
NON_MATCH void FUN_082013d4(Entity08202cd8* p, s32 val) {
#ifdef NONMATCHING_C
  Vec3 d;
  s32 i;

  if (val == 0) {
    FUN_082010d0(p);
    p->unk_1c = (u8)Random();
  }
  p->unk_1c++;
  for (i = 0; i < 7; i++) {
    s32 radius = (8 - i) * 6 + 10;
    u8 angle = i * 16 + p->unk_1c;

    p->sprites[i].pos.y += 9;
    p->sprites[i].pos.x += FixToInt(15, radius * SIN(angle));
    p->sprites[i].pos.z += FixToInt(15, radius * COS(angle));
  }

  for (i = 0; i < 7; i++) {
    AuxSprite* a = &p->sprites[7 - i];
    AuxSprite* b = &p->sprites[6 - i];
    s32 dist;

    Vec3_Diff(&d, &b->pos, &a->pos);
    dist = d.x * d.x + d.y * d.y + d.z * d.z;
    if (dist > u16_ARRAY_085ae7c8[7 - i]) {
      s32 len = u16_ARRAY_085ae7b8[7 - i];
      u32 r = Sqrt(dist);

      if (r != 0) {
        d.x = Div(len * d.x, r);
        d.y = Div(len * d.y, r);
        d.z = Div(len * d.z, r);
      }
      Vec3_Sum(&b->pos, &a->pos, &d);
    }
  }

  if (Mod(p->unk_1c, 32) == 0) {
    Vec3 pos;

    if ((u8)Random() < 0x40) {
      u8 angle = Random();
      s32 radius = Random() & 0x7F;

      pos = p->pos;
      pos.x += FixToInt(12, radius * SIN(angle));
      pos.z += FixToInt(12, radius * COS(angle));
      FUN_08204d04(&pos, 0);
    } else {
      Vec3 vel;
      u8 angle = Random();

      pos = p->pos;
      pos.x += FixToInt(12, SIN(angle) * 120);
      pos.z += FixToInt(12, COS(angle) * 120);
      Vec3_Clear(&vel);
      if (!(p->unk_6dd & 1)) {
        Entity081f26bc_Spawn(&pos, &vel, SPRITE_DVALIN_2E78, 0x38E2, 3, SPRFLAG_BLINK_ODD, 9, 0x232, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      } else {
        Entity081f26bc_Spawn(&pos, &vel, SPRITE_DVALIN_2E78, 0x38E2, 3, SPRFLAG_BLINK_EVEN, 9, 0x232, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      }
      p->unk_6dd++;
    }
  }
  p->unk_6d9 = 1;
#else
  INCFUNC("asm/func/FUN_082013d4.inc");
#endif
}

// 下書き1回で止めた (777/878), 原典は switch の後の関節の引き寄せループを2本持ち, 1番の段階を通ったかどうかで同じ中身のどちらかへ分かれる (約 100 命令の差はこれ)
// 各段階の中身は asm と Ghidra を突き合わせて書いた, Ghidra は case の break を見落として素通りに見せる
// 足をうねらせてからプレイヤーへ向けて伸ばし, 地面に叩きつけてから引き戻す
NON_MATCH void FUN_082017cc(Entity08202cd8* p, s32 val) {
#ifdef NONMATCHING_C
  Vec3 d;
  s32 i;

  if (val == 0) {
    p->unk_692 = 0;
    p->unk_693 = 0;
    p->unk_690 = 1;
    p->unk_691 = 0;
  }

  switch (p->unk_690) {
    case 0: {
      p->unk_1c++;
      for (i = 0; i < 7; i++) {
        s32 radius = (8 - i) * 6 + 10;
        u8 angle = i * 16 + p->unk_1c;

        p->sprites[i].pos.y += 9;
        p->sprites[i].pos.x += FixToInt(15, radius * SIN(angle));
        p->sprites[i].pos.z += FixToInt(15, radius * COS(angle));
      }
      if (++p->unk_692 > 20) {
        p->unk_692 = 0;
        p->unk_690 = 1;
      }
      break;
    }
    case 1: {
      if (p->unk_692 == 0) {
        p->target = gPlayerPtr[0]->mover.pos;
      }
      for (i = 0; i < 7; i++) {
        Vec3 v;
        s32 len = (7 - i) * 10;
        u32 r;

        Vec3_Diff(&v, &p->sprites[i].pos, &p->target);
        r = Sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
        if (r != 0) {
          v.x = Div(len * v.x, r);
          v.y = Div(len * v.y, r);
          v.z = Div(len * v.z, r);
        }
        Vec3_Add(&p->sprites[i].pos, &v);
        p->sprites[i].pos.y += s32_ARRAY_085ae7d8[i];
      }
      if (++p->unk_692 > 30) {
        p->unk_692 = 0;
        p->unk_690 = 2;
      }
      break;
    }
    case 2: {
      Vec3 v;
      u32 r;
      s32 n = 0;

      v.x = p->target.x - p->pos.x;
      v.y = 0;
      v.z = p->target.z - p->pos.z;
      r = Sqrt(v.x * v.x + v.z * v.z);
      if (r != 0) {
        v.x = Div(v.x * 150, r);
        v.y = Div(v.y * 150, r);
        v.z = Div(v.z * 150, r);
      }
      for (i = 0; i < 7; i++) {
        s32 height;

        p->sprites[i].pos.x += v.x;
        p->sprites[i].pos.z += v.z;
        height = (GetTileAt(&p->sprites[i].pos)->heightStairs & 0xF) << 8;
        if (p->sprites[i].pos.y <= height) {
          p->sprites[i].pos.y = height;
          n++;
        }
      }
      if (n > 6) {
        FUN_082010f0(p, 20, 20);
        p->unk_690 = 3;
      }
      if (n > 0 && p->unk_693 == 0) {
        PlaySound_082406e0(SONG_443);
        p->unk_693 = 1;
      }
      break;
    }
    case 3: {
      p->unk_1c += 16;
      for (i = 0; i < 7; i++) {
        Vec3 v;
        u32 r;
        s32 height;

        Vec3_Diff(&v, &p->sprites[i].pos, &p->pos);
        r = Sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
        if (r != 0) {
          v.x = Div(v.x << 3, r);
          v.y = Div(v.y << 3, r);
          v.z = Div(v.z << 3, r);
        }
        Vec3_Add(&p->sprites[i].pos, &v);
        p->sprites[i].pos.y += FixToInt(15, (60 - p->unk_692) * (9 - i) * SIN(i * 16 + p->unk_1c));
        height = (GetTileAt(&p->sprites[i].pos)->heightStairs & 0xF) << 8;
        if (p->sprites[i].pos.y <= height) {
          p->sprites[i].pos.y = height;
        }
      }
      if (++p->unk_692 > 40) {
        p->unk_692 = 0;
        p->unk_690 = 4;
      }
      break;
    }
    case 4: {
      p->unk_6d9 = 1;
      break;
    }
  }

  for (i = 0; i < 7; i++) {
    AuxSprite* a = &p->sprites[7 - i];
    AuxSprite* b = &p->sprites[6 - i];
    s32 dist;

    Vec3_Diff(&d, &b->pos, &a->pos);
    dist = d.x * d.x + d.y * d.y + d.z * d.z;
    if (dist > u16_ARRAY_085ae7c8[7 - i]) {
      s32 len = u16_ARRAY_085ae7b8[7 - i];
      u32 r = Sqrt(dist);

      if (r != 0) {
        d.x = Div(len * d.x, r);
        d.y = Div(len * d.y, r);
        d.z = Div(len * d.z, r);
      }
      Vec3_Sum(&b->pos, &a->pos, &d);
    }
  }
#else
  INCFUNC("asm/func/FUN_082017cc.inc");
#endif
}

// 残差は sprites[i] の番地の作り方 (原典は p + i * 44 に +0x28 を足してフィールドを引く) と, それに伴うレジスタ割り当て (203/197)
// sprites[i] を直接書く形 / i と done の宣言順 / HIDDEN 判定の向きは試済
// 見えている足を pos へ 20 ずつ引き戻し, 全部戻ったら終了の印を立てる
NON_MATCH void FUN_08201f74(Entity08202cd8* p, s32 val) {
#ifdef NONMATCHING_C
  s32 i;
  s32 done = 0;

  if (val == 0) {
    PlaySound_082406e0(SONG_414);
  }
  for (i = 0; i < 8; i++) {
    AuxSprite* spr = &p->sprites[i];

    if (spr->flags & SPRFLAG_HIDDEN) {
      done++;
    } else {
      Vec3 d;
      s32 dist;

      Vec3_Diff(&d, &p->pos, &spr->pos);
      dist = d.x * d.x + d.y * d.y + d.z * d.z;
      if (dist < 400) {
        spr->flags |= SPRFLAG_HIDDEN;
      } else {
        u32 r = Sqrt(dist);

        if (r != 0) {
          d.x = Div(d.x * 20, r);
          d.y = Div(d.y * 20, r);
          d.z = Div(d.z * 20, r);
        }
        Vec3_Sum(&spr->pos, &spr->pos, &d);
      }
    }
  }

  if (done < 8) {
    if (Mod(val, 8) == 0) {
      FUN_081ee53c(&p->pos, 12, 8, 6, 12, 4, Random() & 0x7F, 8, 32, 1, 2, 0x200, 0, 0xF422, 0x121B, 0, 0, 0x237);
    }
  } else {
    p->unk_6d9 = 1;
    p->unk_6da = 1;
    p->unk_6db = 7;
  }
#else
  INCFUNC("asm/func/FUN_08201f74.inc");
#endif
}

// 下書き2回で止めた (426/423 前後), 関節の引き寄せはこの関数だけ Vec3 を介さずスカラーで書くと退避枠が原典 (8 バイト) に近づく
// 原典は狙いの段階で sprites[1..6] の y も読み書きしている (y に 0 を足す Vec3 加算の名残とみる)
// プレイヤーへ向けて足を伸ばし, 角度を回しながら足を薙ぎ払う
NON_MATCH void FUN_08202140(Entity08202cd8* p, s32 val) {
#ifdef NONMATCHING_C
  s32 i;

  if (val == 0) {
    p->unk_1c = 0;
    p->unk_692 = 0;
    p->unk_693 = 0;
    p->unk_690 = 0;
    p->unk_691 = 0;
  }

  switch (p->unk_690) {
    case 0: {
      s32 dx, dz;

      if (p->unk_692 == 0) {
        p->target = gPlayerPtr[0]->mover.pos;
        p->unk_1c = ArcTan2_8(p->pos.x - p->target.x, p->pos.z - p->target.z) + 0x20;
      }
      dx = FixToInt(12, COS(p->unk_1c) * 100);
      dz = FixToInt(12, SIN(p->unk_1c) * 100);
      for (i = 0; i < 6; i++) {
        p->sprites[1 + i].pos.x += dx;
        p->sprites[1 + i].pos.z += dz;
      }
      if (++p->unk_692 > 60) {
        p->unk_692 = 0;
        p->unk_690 = 1;
      }
      break;
    }
    case 1: {
      p->unk_1c = (p->unk_1c + 1) & 0xFF;
      for (i = 0; i < 7; i++) {
        u32 angle = ((p->unk_1c * (7 - i)) >> 3) + p->unk_1c;
        s32 height;

        p->sprites[i].pos.x += FixToInt(12, COS(angle) * 100);
        p->sprites[i].pos.z += FixToInt(12, SIN(angle) * 100);
        height = (GetTileAt(&p->sprites[i].pos)->heightStairs & 0xF) << 8;
        if (p->sprites[i].pos.y <= height) {
          p->sprites[i].pos.y = height;
        }
      }
      if (p->unk_692 > 209) {
        p->unk_690 = 2;
        p->unk_692 = 0;
      }
      p->unk_692++;
      break;
    }
    case 2: {
      p->unk_6d9 = 1;
      break;
    }
  }

  for (i = 0; i < 7; i++) {
    AuxSprite* a = &p->sprites[7 - i];
    AuxSprite* b = &p->sprites[6 - i];
    s16 dx = b->pos.x - a->pos.x;
    s16 dy = b->pos.y - a->pos.y;
    s16 dz = b->pos.z - a->pos.z;
    s32 dist = dx * dx + dy * dy + dz * dz;

    if (dist > u16_ARRAY_085ae7c8[7 - i]) {
      s32 len = u16_ARRAY_085ae7b8[7 - i];
      u32 r = Sqrt(dist);

      if (r != 0) {
        dx = Div(len * dx, r);
        dy = Div(len * dy, r);
        dz = Div(len * dz, r);
      }
      b->pos.x = dx + a->pos.x;
      b->pos.y = dy + a->pos.y;
      b->pos.z = dz + a->pos.z;
    }
  }
#else
  INCFUNC("asm/func/FUN_08202140.inc");
#endif
}

// 下書き1回で止めた (409/415), 狙い / 振り下ろし / 関節の引き寄せは Ghidra と asm の形どおり
// 振り下ろしで y 成分 0 の Div を捨てずに呼ぶのは Vec3 を3成分とも正規化している名残とみた
// プレイヤーを狙って足を振り上げ, 叩きつけて地面に当たったら何かを飛ばす
NON_MATCH void FUN_082024e8(Entity08202cd8* p, s32 val) {
#ifdef NONMATCHING_C
  Vec3 d;
  s32 hit;
  s32 i;

  if (val == 0) {
    p->unk_692 = 0;
    p->unk_693 = 0;
    p->unk_690 = 0;
    p->unk_691 = 0;
  }

  hit = 0;
  switch (p->unk_690) {
    case 0: {
      if (p->unk_692 == 0) {
        p->target = gPlayerPtr[0]->mover.pos;
      }
      p->sprites[0].pos.y += 4;
      for (i = 0; i < 4; i++) {
        s32 sign = -1;

        if (p->sprites[i].pos.z - p->target.z > 0) {
          sign = 1;
        }
        p->sprites[i].pos.z += (7 - i) * sign * 5;
      }
      if (++p->unk_692 > 30) {
        p->unk_692 = 0;
        p->unk_690 = 1;
      }
      break;
    }
    case 1: {
      Vec3 v;
      u32 r;
      s32 n = 0;

      v.x = p->target.x - p->pos.x;
      v.y = 0;
      v.z = p->target.z - p->pos.z;
      r = Sqrt(v.x * v.x + v.z * v.z);
      if (r != 0) {
        v.x = Div(v.x * 150, r);
        v.y = Div(v.y * 150, r);
        v.z = Div(v.z * 150, r);
      }
      for (i = 0; i < 4; i++) {
        s32 height;

        p->sprites[i].pos.x += v.x;
        p->sprites[i].pos.z += v.z;
        height = (GetTileAt(&p->sprites[i].pos)->heightStairs & 0xF) << 8;
        if (p->sprites[i].pos.y <= height) {
          p->sprites[i].pos.y = height;
          n++;
        }
      }
      if (n > 6) {
        hit = 1;
        p->unk_690 = 2;
      }
      break;
    }
    case 3: {
      p->unk_6d9 = 1;
      break;
    }
  }

  for (i = 0; i < 7; i++) {
    AuxSprite* a = &p->sprites[7 - i];
    AuxSprite* b = &p->sprites[6 - i];
    s32 dist;

    Vec3_Diff(&d, &b->pos, &a->pos);
    dist = d.x * d.x + d.y * d.y + d.z * d.z;
    if (dist > u16_ARRAY_085ae7c8[7 - i]) {
      s32 len = u16_ARRAY_085ae7b8[7 - i];
      u32 r = Sqrt(dist);

      if (r != 0) {
        d.x = Div(len * d.x, r);
        d.y = Div(len * d.y, r);
        d.z = Div(len * d.z, r);
      }
      Vec3_Sum(&b->pos, &a->pos, &d);
    }
  }

  if (hit == 1) {
    FUN_08200b5c(p);
  }
#else
  INCFUNC("asm/func/FUN_082024e8.inc");
#endif
}

void FUN_0820287c(Entity08202cd8* p, s32 keep) {
  if (keep == 0) {
    HitboxData* hb = p->hitboxB;
    s32 i;

    for (i = 0; i < 8; i++) {
      hb->flags |= HBFLAG_HIDDEN;
      hb++;
    }
  }
  p->unk_6da = 1;
  p->unk_6d9 = 1;
}

// unk_6db で指定された状態関数を fn に移す
s32 FUN_082028b8(Entity08202cd8* p) {
  static void (*const PTR_ARRAY_085ae7f8[8])(Entity08202cd8*, s32) = {
      NULL,
      FUN_082010f8,
      FUN_082013d4,
      FUN_082017cc,
      FUN_08202140,
      FUN_08201f74,
      FUN_082024e8,
      FUN_0820287c,
  };  // 0x085AE7F8

  if (p->unk_6db == 0 || p->unk_6db > 8) {
    return 0;
  }

  p->fn = PTR_ARRAY_085ae7f8[p->unk_6db];
  p->unk_6dc = p->unk_6db;
  p->unk_6db = 0;
  p->unk_18 = 0;
  p->unk_6d8 = 1;
  return 1;
}

void FUN_08202910(Entity08202cd8* p) {
  s32 n;

  p->unk_6d9 = 0;
  n = p->unk_18++;
  if (p->fn != NULL) {
    p->fn(p, n);
  }
}

// ゲームが止まっていなければ各パートを更新し、カメラ揺れの残り時間を減らす
s32 Entity08202cd8_Update(Entity08202cd8* p) {
  u32 mask;

  p->unk_6da = 0;
  mask = FLAG03002BC0_UNK_2;
  if (!(gPlayerStates[0] & mask)) {
    FUN_08200b8c(p);
    FUN_082028b8(p);
    FUN_08202910(p);
    FUN_08200e54(p);
    FUN_08200c8c(p);
    if (p->unk_20 != 0) {
      Camera_Shake(p->unk_22);
      p->unk_20--;
    }
  }
  return 0;
}

s32 Entity08202cd8_Destroy(Entity08202cd8* p) {
  s32 i;

  for (i = 0; i < 8; i++) {
    AuxSprite_Remove(&p->sprites[i]);
  }
  return 0;
}

// hitboxA の被弾コールバック, 何もしない
void FUN_082029b8(HitboxData* a, HitboxData* b, Entity08202cd8* p) {}

// 被弾時のハンドラ, 全スプライトを赤くしてダメージを適用する
void FUN_082029bc(HitboxData* a, HitboxData* b, Entity08202cd8* p) {
  s32 i;

  p->unk_24 = 4;
  p->unk_25 = 15;
  for (i = 0; i < 8; i++) {
    FUN_08200b38(&p->sprites[i]);
  }
  Hitbox_ApplyDamage(a, b);
  p->unk_6ec = b->damage;
  PlaySound_082406e0(SE_ENEMY_DAMAGED);
}

// 残差は base (足元の高さを入れた pos) の置き方 (300/299), 原典は x / y / z を先にレジスタへ読んでから sp 上の Vec3 に3回の strh で置き, 退避枠も 0x40 と大きい
// x を先にローカルへ読んで VEC3_SET で置く形 (297) は試済
// 8本の足のスプライトと攻撃 / 食らいのヒットボックスを pos の足元に用意する
NON_MATCH s32 Entity08202cd8_Init(Entity08202cd8* p, Vec3* pos, s32 param_3, s32 param_4) {
#ifdef NONMATCHING_C
  Vec3 base;
  Vec3 halfSize, offset;
  s32 i;

  base.x = pos->x;
  base.y = (GetTileAt(pos)->heightStairs & 0xF) << 8;
  base.z = pos->z;
  Video_GetAuxSprite(&p->gfx0, SPRITE_DVALIN_2E78);
  Video_GetAuxSprite(&p->gfx1, SPRITE_DVALIN_2E7B);
  p->plttID = p->gfx0.plttID;
  p->unk_6e2 = param_3;
  p->unk_6e0 = param_4;
  for (i = 0; i < 8; i++) {
    AuxSprite* spr = &p->sprites[i];
    HitboxData* hb;

    if (i < 3) {
      AuxSprite_Add(spr, &p->gfx1, 0);
      spr->poseIdx = 0;
    } else if (i < 5) {
      AuxSprite_Add(spr, &p->gfx0, 0);
      spr->poseIdx = 8;
    } else {
      AuxSprite_Add(spr, &p->gfx0, 0);
      spr->poseIdx = 0;
    }
    spr->flags |= SPRFLAG_HIDDEN;
    spr->pos = base;

    hb = &p->hitboxA[i];
    halfSize.x = 50, halfSize.y = 50, halfSize.z = 50;
    offset.x = 0, offset.y = 0, offset.z = 0;
    Hitbox_Init(hb, 0, HBFLAG_HITBOX | HBFLAG_ACTOR | HBFLAG_UNK_0, 0, 0x10, &halfSize, &offset);
    Hitbox_SetPos(hb, &spr->pos, 0);
    Hitbox_SetHandler(hb, FUN_082029b8, p);
    Hitbox_SetAttack(hb, p->unk_6e0, 100, 0, 0, 30);

    hb = &p->hitboxB[i];
    halfSize.x = 100, halfSize.y = 100, halfSize.z = 100;
    offset.x = 0, offset.y = 0, offset.z = 0;
    Hitbox_Init(hb, 0, HBFLAG_HURTBOX | HBFLAG_ACTOR | HBFLAG_UNK_0, 0, 0x10, &halfSize, &offset);
    Hitbox_SetPos(hb, &spr->pos, 0);
    Hitbox_SetHandler(hb, FUN_082029bc, p);
    Hitbox_SetPowerAndAttributes(hb, p->unk_6e2, 8, 4);
    Hitbox_Register(hb);
  }

  p->pos = base;
  p->unk_1c = 0;
  p->unk_24 = 0;
  p->unk_25 = 0;
  p->unk_20 = 0;
  p->unk_22 = 0;
  p->unk_6db = 0;
  p->unk_6dc = 0;
  p->fn = NULL;
  p->unk_18 = 0;
  p->unk_6d8 = 1;
  p->unk_6ec = 0;
  p->unk_6dd = 0;
  return 0;
#else
  INCFUNC("asm/func/Entity08202cd8_Init.inc");
#endif
}

Entity08202cd8* Entity08202cd8_Create(Vec3* pos, s32 param_2, s32 param_3) {
  Entity08202cd8* p = CreateEntity(ENTITY_UNK_9, sizeof(Entity08202cd8));

  if (p != NULL) {
    SetEntityRoutine(p, Entity08202cd8_Update, Entity08202cd8_Destroy);
    if (Entity08202cd8_Init(p, pos, param_2, param_3) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
