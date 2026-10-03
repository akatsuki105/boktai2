#ifndef __INCLUDE_MOVER_H__
#define __INCLUDE_MOVER_H__

#include "gba/gba.h"
#include "types.h"

struct AuxSprite;
struct MainSprite;

// Mover が踏んでいるタイルの控え, どの配列も [0] が前、[1] が今
// タイルが変わったときだけ FUN_082332f8 が今の値を [0] へ押し出してから [1] を新しいタイルで更新する
typedef struct {
  u8 unk_0[4];     // 0x00, Map_InitMoverTile も FUN_082332f8 も触らない
  u16 tileIdx[2];  // 0x04, gCollisionMap->rowOffsets[z >> 8] + (x >> 8)
  u8 attrLo[2];    // 0x08, TileAttr の bit0-3 (TATTR_WALL / TATTR_UNK_2)
  u8 attrHi[2];    // 0x0A, TileAttr の bit4-7 (TATTR_NOISE / TATTR_ICE / TATTR_LAVA) を 4bit 右にずらした値
  u16 obj[2];      // 0x0C, CollisionMapTile の obj と height をまとめた2バイト
} MoverTile;
static_assert(sizeof(MoverTile) == 16);

// ワールド上を移動する本体, プレイヤー・エネミー・多くのオブジェクトが自分の中に1個持つ
// 動かす側は delta に移動量を積むだけで、Mover_ApplyMove が衝突と経路を見て pos を進め、スプライトへ書き戻してから delta を捨てる
// 生成時に Mover_Link でひとつのリストに繋がれ、id で引ける (gMoverList が head/tail を持つ)
typedef struct Mover {
  u16 id;                         // 0x00, Mover_FindByID の検索キー
  u16 unk_2;                      // 0x02, フラグっぽい
  u8 unk_4;                       // 0x04, 衝突解決 FUN_0823349c の第6引数
  u8 angle;                       // 0x05, 8bit の向き, gSineTable の添字
  u8 unk_6[2];                    // 0x06, 読み手も書き手も未発見, padding?
  Vec3 pos;                       // 0x08, ワールド座標, 1タイル = 256
  Vec3 delta;                     // 0x10, そのフレームの移動要求, Mover_ApplyMove が pos に適用してから 0 に戻す
  MoverTile* tile;                // 0x18, 踏んでいるタイルの控え, 非NULLなら Mover_ApplyMove が衝突解決を通す
  u16 sizeX;                      // 0x1C, 衝突判定の X 方向の広がり, FUN_0823349c が pos.x に足して角を見る
  u16 sizeZ;                      // 0x1E, 衝突判定の Z 方向の広がり, FUN_0823349c が pos.z に足して角を見る
  u32 unk_20;                     // 0x20, FUN_0823b464 が書くだけで読み手は未発見
  void* path;                     // 0x24, 経路追従の状態, Mover_SetPath が Path と節点のポインタを書き込む
  struct AuxSprite* auxSprite;    // 0x28, 非NULLなら Mover_ApplyMove が毎フレーム pos を書き戻す
  struct MainSprite* mainSprite;  // 0x2C, 読み手は未発見
  Vec3 unk_30;                    // 0x30, FUN_0823b47c が引数から8バイトまとめて書き、unk_2 に bit2 を立てる, 読み手は未発見
  void* owner;                    // 0x38, この Mover を持っている側のポインタ, Mover_Init の第6引数
  struct Mover* prev;             // 0x3C
  struct Mover* next;             // 0x40
} Mover;
static_assert(sizeof(Mover) == 68);

// MoverTile を pos の足元のタイルで埋める (実体は衝突マップ側の code_082326a0.c)
void Map_InitMoverTile(MoverTile* p, Vec3* pos);

// delta の分だけ衝突を見ながら pos を進める (同上)
void FUN_0823349c(MoverTile* p, Vec3* pos, Vec3* delta, u16 sizeX, u16 sizeZ, u8 unk_4);

// pos と向きを入れてリストに繋ぐ
s32 Mover_Init(Mover* p, u16 id, Vec3* pos, u32 angle, u32 unk_4, void* owner);

// delta の分だけ pos を進めて delta をクリアする, 毎フレーム呼ぶ
void Mover_ApplyMove(Mover* p);

bool32 Mover_SetCollision(Mover* p, MoverTile* tile, u16 sizeX, u16 sizeZ);
bool32 Mover_SetPath(Mover* p, void* path, u8 param_3, u8 param_4, u8 param_5);
bool32 Mover_SetAuxSprite(Mover* p, struct AuxSprite* auxSprite);
bool32 Mover_SetMainSprite(Mover* p, struct MainSprite* data);

void Mover_Link(Mover* p);
bool32 Mover_Unlink(Mover* p);
Mover* Mover_FindByID(u16 id);

void MoverList_ClearPtr(void);

// Mover_FindByID を呼ぶだけのラッパ, 他モジュールが使っているのはこちら (11箇所)
Mover* Mover_FindByID_Proxy(u16 id);

#endif  // __INCLUDE_MOVER_H__
