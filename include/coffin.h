#ifndef __INCLUDE_IMMORTAL_COFFIN_H__
#define __INCLUDE_IMMORTAL_COFFIN_H__

#include "enemy_target.h"
#include "entity.h"
#include "hitbox.h"
#include "mover.h"
#include "particle.h"
#include "player.h"
#include "sprite.h"
#include "types.h"

struct Emote;

// 運搬中の棺桶
typedef struct Coffin {
  Entity e;                   // 0x000, ENTITY_UNK_9
  u16 subroutineID;           // 0x018, mover.id と両 hurtbox の id になる
  coffin8_t coffinID;         // 0x01A, gStat->coffin の写し, 棺桶ごとのパラメータ表の添字
  u8 unk_1b;                  // 0x01B
  u16 unk_1c;                 // 0x01C, '.c', 0 以外だと EnemyTargetManager への登録種別と hurtbox の ignoreMask が変わる
  u16 weight;                 // 0x01E, 棺桶ごとの重さ, Player の移動速度から引かれる
  rgb555 pltt[16];            // 0x020, gfx.pltt の複写先, gfx.pltt はここを指すように差し替えられる
  Mover mover;                // 0x040, angle は (facing + 5) * 32
  AuxSprite sprite;           // 0x084, ->gfx
  AuxSpriteGfx gfx;           // 0x0B0, SPRITE_COFFIN, パレット行は coffinID + 519
  u8 unk_cc[0xDC - 0xCC];     // 0x0CC
  HitboxData hurtbox;         // 0x0DC, mover.pos に追従する被弾判定, これだけ Init で登録される
  HitboxData hitbox;          // 0x12C, 威力50の攻撃判定 (多分棺桶が暴れ出した時の攻撃判定)
  NavAgent navAgent;          // 0x17C, mover.pos から destPos への経路を見るのに使う
  ZoneEventSource zoneEvent;  // 0x1A0, id は mover.id の写し, pos は &mover.pos
  AuxAnimState animState;     // 0x1D0, anim の再生状態
  AuxAnimFile* anim;          // 0x1E0, ANIM_COFFIN
  EnemyTarget target;         // 0x1E4, 敵から狙われる側としての登録, coffinID が COFFIN_SILVER のときは登録しない
  bool8 unk_1f4;              // 0x1F4, target を登録済みなら 1
  u8 state;                   // 0x1F5, 1 / 0x10 / 12 / 13 などを取る, Player は 1 か 0x10 のときだけ掴める
  u16 stateTimer;             // 0x1F6, state が変わるたびに 0 に戻る
  Vec3 pos_1f8;               // 0x1F8, '.p', y はタイルの高さ属性から決まる, mover / sprite.pos / unk_388 / unk_3c4 の初期値
  DirU8 facing;               // 0x200, '.d', 8方向の向き, mover.angle は (facing + 5) * 32
  u8 unk_201[3];              // 0x201, padding?
  Particle ptcls[7];          // 0x204, PTCL_GROUP_1, 最初は非表示
  u16 unk_31c;                // 0x31C, coffinID の写し
  u16 unk_31e;                // 0x31E
  u16 unk_320;                // 0x320
  u16 unk_322;                // 0x322
  u16 unk_324;                // 0x324, 0 でない間 FUN_08086034 が unk_414 の処理を回す
  u16 unk_326;                // 0x326
  u16 unk_328;                // 0x328, 毎フレーム +1 し, 下位7bitが 0x60 を超える間だけ unk_31e/unk_322 を揺らす
  u16 unk_32a;                // 0x32A
  u16 unk_32c;                // 0x32C
  u16 unk_32e;                // 0x32E, unk_31c の写し (つまり coffinID の写し), これに 519 を足したものがパレット行
  u16 unk_330;                // 0x330, 0 でない間は unk_32e を 9 に固定して毎フレーム減る
  u16 unk_332;                // 0x332
  u16 unk_334;                // 0x334, 0x40 を上限に増減するカウンタ
  u8 unk_336[4];              // 0x336
  u8 unk_33a;                 // 0x33A
  bool8 effSpriteAdded;       // 0x33B, effSprite を AuxSprite_Add 済みなら 1
  AuxSprite effSprite;        // 0x33C
  AuxSpriteGfx effGfx;        // 0x368, SPRITE_EFF_1C1B
  u8 unk_384;                 // 0x384, Player.unk_390 と同じビット構成, bit2 が立つとエレベータに乗っている
  u8 unk_385;                 // 0x385
  u16 elevatorID;             // 0x386, 搭乗中のエレベータのID
  Vec3 unk_388;               // 0x388, pos_1f8 の写し
  u16 unk_390;                // 0x390, 棺桶ごとの値 × 60, unk_392 と対
  u16 unk_392;                // 0x392
  u16 unk_394;                // 0x394, unk_390 が 0 になると 1 になる
  u16 unk_396;                // 0x396
  u16 unk_398;                // 0x398
  u16 unk_39a;                // 0x39A, 初期値 300
  u8 unk_39c[0x3A0 - 0x39C];  // 0x39C
  s16 unk_3a0;                // 0x3A0, 初期値 -1, FUN_08086878 が符号付きで読んで -1 を「無し」として扱う
  u16 canSelfMove;            // 0x3A2, 棺桶が自力で動けるか, COFFIN_IRON だけ 0
  u16 selfMoveTimer;          // 0x3A4, (canSelfMove が TRUE のとき) 0 まで毎フレーム減り, 尽きると destPos へ向かって自力で動き出す
  u16 selfMoveTimerInit;      // 0x3A6, selfMoveTimer の初期値, 棺桶ごとの値 × 120
  Vec3 destPos;               // 0x3A8, '.r', 自力で動くときの目的地
  u32 unk_3b0;                // 0x3B0, '.O'
  u16 unk_3b4;                // 0x3B4
  u16 unk_3b6;                // 0x3B6, state が 1 のときは毎回 2, それ以外は 1 ずつ減るカウンタ
  u8 unk_3b8[4];              // 0x3B8
  Vec3 unk_3bc;               // 0x3BC, FUN_08086b18 が受け取る位置, プレイヤーとの角度を出すのに使う
  Vec3 unk_3c4;               // 0x3C4, pos_1f8 の写し
  u8 unk_3cc[0x3D4 - 0x3CC];  // 0x3CC
  // 0x3D4 から 0x3FA までは FUN_08087310 がそれぞれ別の定数で初期化する一群
  u16 unk_3d4;          // 0x3D4, 初期値 2
  u16 unk_3d6;          // 0x3D6, 初期値 0
  u8 unk_3d8[2];        // 0x3D8
  u16 unk_3da;          // 0x3DA, 初期値 0x40
  u16 unk_3dc;          // 0x3DC, 初期値 3
  u16 unk_3de;          // 0x3DE, 初期値 6
  u16 unk_3e0;          // 0x3E0, 初期値 2
  u16 unk_3e2;          // 0x3E2, 初期値 2
  u16 unk_3e4;          // 0x3E4, 初期値 60
  u16 unk_3e6;          // 0x3E6, 初期値 8
  u16 unk_3e8;          // 0x3E8, 初期値 0
  u16 unk_3ea;          // 0x3EA, 初期値 0xFF
  u16 unk_3ec;          // 0x3EC, 初期値 0xFF
  u16 unk_3ee;          // 0x3EE, 初期値 0
  u16 unk_3f0;          // 0x3F0, 初期値 0xFF
  u16 unk_3f2;          // 0x3F2, 初期値 0
  u16 unk_3f4;          // 0x3F4, 初期値 0xFF
  u16 unk_3f6;          // 0x3F6, 初期値 0
  u16 unk_3f8;          // 0x3F8, 初期値 0xFF
  u16 unk_3fa;          // 0x3FA, 初期値 0
  u8 unk_3fc[6];        // 0x3FC
  u16 unk_402;          // 0x402
  u16 unk_404;          // 0x404, 8方向の向き
  u16 unk_406;          // 0x406, _Update が毎フレーム 0 に戻す
  u16 unk_408;          // 0x408, FUN_080893c0 が Coffin_SetState に渡す遷移先の state
  bool8 inSolarCircle;  // 0x40A, 棺桶が太陽結界内にいるかどうか (太陽結界内にいると棺桶は自力で動けなくなる)
  bool8 killRequested;  // 0x40B, 0 以外になると _Update が KillEntity する
  Vec3 unk_40c;         // 0x40C, FUN_080865dc が丸ごと返す
  struct Emote* emote;  // 0x414, 棺桶の中のイモータルがおとなしくなったときの "..." アイコン用?
  u16 unk_418;          // 0x418, Emote_Show に渡す進捗の入れ物, 自力移動を始めるときに 0 に戻す
  u8 unk_41a[2];        // 0x41A
} Coffin;
static_assert(sizeof(Coffin) == 1052);

extern Coffin* gCoffin;  // 0x03002C00

void Coffin_SetInsideSolarCircle(bool32 n);
WorldPos* Coffin_GetPos(void);
bool32 Coffin_CopyPos(WorldPos* out);
bool32 Coffin_IsIdle(void);
s32 FUN_08086878(void);
void FUN_0808689c(s32 val);
void FUN_08086a4c(Vec3* pos);
bool32 FUN_0808626c(u32 playerEleveterID, u32 param_2, u32 coffinEleveterID, u32 param_4);

#endif  // __INCLUDE_IMMORTAL_COFFIN_H__
