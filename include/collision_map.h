#ifndef __INCLUDE_COLLISION_MAP_H__
#define __INCLUDE_COLLISION_MAP_H__

#include "gba/gba.h"
#include "types.h"

// マップの 高さ情報、衝突判定データ、イベントトリガーなど をまとめたファイル, タイルセット、タイルマップ、パレットなどのグラフィックデータは含まない

typedef struct {
  char magic[4];      // 0x00, "HP\0\0", DIR_COLLISION_MAP が BOKHASH("hpk")
  AssetRef tileData;  // 0x04, CollisionMapTileData, 床の属性や高さ、階段やプレイヤーが奥側にいるときに手前に何を描画するかなどの情報を持つ
  AssetRef zones;     // 0x08, ZoneData, イベントのトリガー範囲を管理する
  AssetRef paths;     // 0x0C, PathData, 敵やエレベーターがたどる経路
  AssetRef navMesh;   // 0x10, NavMesh, NPCをマップ上の任意の2点間で移動させるためのデータ, 0 なら無し
  // これ以降は上の4つが指す可変長のデータが並ぶ
} CollisionMapFile;
static_assert(sizeof(CollisionMapFile) == 20);

// --------------------------------------------

// (heightStairs >> 4) & 0xF
#define STAIRS_NONE 0
#define STAIRS_VERTICAL 1
#define STAIRS_HORIZONTAL 2

// 例:
//   変異域炎の溶岩: 0x0482 (TATTR_WALL, TATTR_SPECIAL, TATTR_WALLISH)
//   変異域氷のすべる床: 0x0080 (TATTR_SPECIAL)
//   地下水路で水に落ちた: 0x0041 (TATTR_UNK_0, TATTR_FALLDEATH)
//   暗黒街のワープ前の壁渡り: 0x082A (TATTR_WALL, TATTR_UNK_3, TATTR_UNK_5, TATTR_UNK_11)
//   宿屋, 暗黒街のワープ先, 暗黒街のダクト: 0x040A (TATTR_WALL, TATTR_UNK_3, TATTR_WALLISH)
typedef u16 TileAttr;             // CollisionMapTile.attr
#define TATTR_UNK_0 (1 << 0)      // 0x0001, 未検証
#define TATTR_WALL (1 << 1)       // 0x0002, 壁(常に侵入不可)
#define TATTR_UNK_2 (1 << 2)      // 0x0004, 未検証, 移動床に乗っている時 (変異域の上下昇降床, 地下水路の移動床)
#define TATTR_UNK_3 (1 << 3)      // 0x0008, 未検証
#define TATTR_UNK_4 (1 << 4)      // 0x0010, 未検証
#define TATTR_UNK_5 (1 << 5)      // 0x0020, 未検証, 太陽床に乗っている間セット (消すと0になった?)
#define TATTR_FALLDEATH (1 << 6)  // 0x0040, 地下水路で水に落ちたり、落下死する場所にいくとセットされた
#define TATTR_SPECIAL (1 << 7)    // 0x0080, MPF_COLD: すべり床, MPF_HOT: 溶岩, それ以外: 鳴り床
#define TATTR_FRAGILE (1 << 8)    // 0x0100, ダイナマイトで壊せる傷んだ壁?
#define TATTR_UNK_9 (1 << 9)      // 0x0200, 未検証, 属性ブロックが止まっている間に立てる
#define TATTR_WALLISH (1 << 10)   // 0x0400, TATTR_WALL との違いは不明 (敵キャラ専用?)
#define TATTR_UNK_11 (1 << 11)    // 0x0800
#define TATTR_UNK_12 (1 << 12)    // 0x1000

// コリジョンマップの1タイル
typedef struct {
  u8 heightStairs;  // 0x00, 下位4bit が高さ (同じ高さのタイル か 高さが合う階段タイル から侵入可能), 上位4bit が階段 (0: なし, 1: 縦, 2: 横)
  u8 occluder;      // 0x01, タイルで隠されるべき場合に使用されるスプライト, 0xFF でなし
  TileAttr attr;    // 0x02, see TileAttr
} CollisionMapTile;
static_assert(sizeof(CollisionMapTile) == 4);

// --------------------------------------------

// 地形の上書き情報を管理する構造体
typedef struct MapTileOverride {
  u16 flags;                     // 0x00, Map_FindTileOverride が引数のマスクと AND を取って弾く, Map_InitTileOverride は 0 を書く
  u16 tileIdx;                   // 0x02, Map_InitTileOverride の第2引数, 呼び出し側はコリジョンマップのタイル索引を渡す
  CollisionMapTile tile;         // 0x04, このタイルの代わりに使われる値, Map_InitTileOverride の第3引数以降が入る
  struct MapTileOverride* prev;  // 0x08, Map_AddTileOverride が挿入時に NULL を書く
  struct MapTileOverride* next;  // 0x0C, Map_AddTileOverride が挿入時に旧 head を書く
} MapTileOverride;
static_assert(sizeof(MapTileOverride) == 16);

typedef struct {
  u32 unk_0;                  // 0x00, 読むコードは見つかっていない
  s16 width;                  // 0x04, マップの幅 (タイル数), gMapBlockW に写される
  s16 height;                 // 0x06, マップの奥行き (タイル数), gMapBlockH に写される
  s16 tilemapOffsetX;         // 0x08, pixel position of tilemap on the collision map (for camera)
  s16 tilemapOffsetY;         // 0x0A, pixel position of tilemap on the collision map (for camera)
  CollisionMapTile tiles[1];  // 0x0C, CollisionMapTile[width * height]
} CollisionMapTileData;

// --------------------------------------------

// ID付きの範囲情報 (イベント（カットシーン、ロードゾーンなど）のトリガー に使われる？)
typedef struct {
  s16 x1;       // 0x00, X/Y coordinates: 1 tile = 256 units
  s16 y1;       // 0x02, pos.z と比べる範囲の始端
  s16 x2;       // 0x04, pos.x と比べる範囲の終端, この値は範囲に含まない
  s16 y2;       // 0x06, pos.z と比べる範囲の終端, この値は範囲に含まない
  u8 z1;        // 0x08, Z coordinate: 1 tile = 16 units
  u8 z2;        // 0x09, 高さの終端, 範囲判定には使われず Cmd_GetZoneBounds などが取り出すだけ
  ZoneID16 id;  // 0x0A
} Zone;
static_assert(sizeof(Zone) == 12);

typedef struct {
  u8 count;       // 0x00, number of Zone
  u8 unk_1;       // 0x01, 読むコードは見つかっていない, padding?
  u16 unk_2;      // 0x02, 読むコードは見つかっていない, padding?
  Zone zones[1];  // 0x04, Zone[count]
} ZoneData;

// --------------------------------------------

typedef struct {
  u16 x;       // 0x00, X/Y coordinates: 1 tile = 256 units
  u16 y;       // 0x02, pos.z に対応する
  u16 delay;   // 0x04, 下位12bit がコマンド後の待ちフレーム数, 上位4bit は用途不明
  u8 command;  // 0x06, 上位4bit を FUN_080f2864 が u8_ARRAY_085ad468 の添字にする (ldrb), 0x00: x/y座標へ移動, 0x10: 方向転換, 0x30: 眠りにつく, 0x90/0xB0/0xE0: ?マークを表示, 0xA0/0xE0: Go to space, 0xD0: Start searching
  u8 unk_7;    // 0x07, 読むコードは見つかっていない, padding?
} PathNode;

typedef struct {
  u8 nodeCount;    // 0x00, PathNode の数, 読み手はすべて ldrb
  u8 unk_1;        // 0x01, 読むコードは見つかっていない, padding?
  u16 nodeOffset;  // 0x02, Byte offset from start of PathData to first node
} Path;

// 経路を1ノードずつたどるカーソル, Map_InitPathWalker が初期化し Map_AdvancePathWalker が進める
// サイズは +8 まで使うことしか分かっていないので 12 は暫定
typedef struct {
  u8 pathIdx;      // 0x00, Map_InitPathWalker の第2引数
  u8 unk_1;        // 0x01, Map_InitPathWalker の第3引数, 読むコードは見つかっていない
  u8 nodeIdx;      // 0x02, いま指しているノード番号, nodeCount に達すると 0 に戻る
  u8 waitTimer;    // 0x03, ノードの delay まで数える待ち時間, 初期化と前進のたびに 0
  Path* path;      // 0x04, gCollisionMap->paths 内の pathIdx 番の経路
  PathNode* node;  // 0x08, nodes[nodeIdx]
} PathWalker;
static_assert(sizeof(PathWalker) == 12);

Path* Map_GetPath(u8 idx);
PathNode* Map_GetPathNodes(Path* path);
s32 Map_GetPathNodePos(Vec3* dst, u8 pathIdx, u8 nodeIdx);
s32 Map_PickRandomPathNode(Vec3* dst, s32 pathIdx);
bool8 Map_InitPathWalker(PathWalker* p, u32 pathIdx, u32 param_3, u32 nodeIdx);
bool8 Map_AdvancePathWalker(PathWalker* p);
bool8 Map_IsPosOutsidePathNode(PathWalker* w, Vec3* pos, u32 rx, u32 rz);

typedef u16 NavAgentFlags;
#define NAVFLAG_VIA_PORTAL (1 << 0)        // 0x0001, ポータルを経由する途中, 最後の区間に入ると落ちる
#define NAVFLAG_WAYPOINT_CHANGED (1 << 1)  // 0x0002, 通過点 waypoint が変わった, Map_ConsumeNavWaypointChanged が読んで落とす
#define NAVFLAG_DIRECT (1 << 2)            // 0x0004, 目的地へ直行する最後の区間, 読むコードは見つかっていない

// ナビメッシュ上を移動する主体の状態, Map_StepNavPath と Map_UpdateNavAgentRect / Map_AdvanceNavPortal が読み書きする
// Enemy は実体を持たず Enemy.navAgent (0x4A4) にポインタで持つので, 確保元が見つかるまで全体サイズは未確定
// 触っていることが分かっている +0x23 までだけ書いてある
typedef struct NavAgent {
  NavAgentFlags flags;  // 0x00, see NavAgentFlags
  u16 unk_02;           // 0x02, 読み書きするコードは見つかっていない
  u16 islandIdx;        // 0x04, NavMesh.islandOffsets[] の添字
  u16 rectIdx;          // 0x06, islandIdx の島の中のナビ矩形番号
  u16 goalPortal;       // 0x08, 目標のポータル番号, Map_AdvanceNavPortal が nextPortal と一致したら到着扱いにする
  u16 nextPortal;       // 0x0A, いま向かっているポータル番号
  Vec3 dest;            // 0x0C, 目的地
  Vec3 routeStart;      // 0x14, 経路を引いたときの位置, dest と両方同じなら Map_FindNavRoute は引き直さない
  Vec3 waypoint;        // 0x1C, 次の通過点, nextPortal の座標か dest
} NavAgent;

typedef struct {
  u16 pathCount;      // 0x00, number of Path
  u16 unk_02;         // 0x02, 読むコードは見つかっていない
  Path paths[1];      // 0x04, Path[pathCount]
  PathNode nodes[1];  // 要素数は Path[Path.nodeCount] の合計?
} PathData;

// --------------------------------------------

typedef struct {
  u16 countRects;           // 0x00, rects の要素数
  u16 countPortals;         // 0x02, portals の要素数
  u16 countDistanceMap;     // 0x04, distanceMap の要素数
  u32 offsetToRects;        // 0x08, Byte offset from start of NavIsland to rects
  u32 offsetToPortals;      // 0x0C, Byte offset from start of NavIsland to portals
  u32 offsetToDistanceMap;  // 0x10, Byte offset from start of NavIsland to distance map

  struct NavRect {
    u8 minX;         // 0x00, 1 tile = 1
    u8 minY;         // 0x01, pos.z と比べる
    u8 maxX;         // 0x02, この値は範囲に含まない
    u8 maxY;         // 0x03, pos.z と比べる, この値は範囲に含まない
    u8 portals[12];  // 0x04, Indices into NavMesh.portals. At most 12 portals per rect, unused elements in this array must be at the end of the array, and set to 0xFF.
  } rects[1];        // NavRect[countRects]

  struct NavPortal {
    u16 x;        // 0x00, 1 tile = 0x100
    u16 y;        // 0x02, pos.z に対応する
    u16 unk_4;    // 0x04, 読むコードは見つかっていない
    u8 rects[6];  // 0x06, Indices into NavMesh.rects. At most 6 rects per portal, unused elements in this array must be at the end of the array, and set to 0xFF.
  } portals[1];   // NavPortal[countPortals]

  u16 distanceMap[1];  // u16[countDistanceMap]
} NavIsland;

typedef struct NavRect NavRect;
typedef struct NavPortal NavPortal;

typedef struct {
  u16 countIslands;      // 0x00, islandOffsets の要素数
  u16 unk_02;            // 0x02, padding?
  u32 islandOffsets[1];  // 0x04, islandOffsets[countIslands]
  NavIsland islands[1];  // NavIsland[countIslands]
} NavMesh;

// --------------------------------------------

// ゾーンイベントを起こした側の情報, Map_RunZoneEventScript がスクリプトの引数に積む
typedef struct {
  u16 id;                // 0x00, Mover.id の複写
  u8 unk_2;              // 0x02, 読むコードは見つかっていない
  u8 activeCount;        // 0x03, activeEvents の件数
  Vec3* pos;             // 0x04, Mover.pos を指す
  u32 activeEvents[10];  // 0x08, いま範囲内にいる CollisionMapEvent.id, 要素数は ActorManager の空き領域ちょうど (暫定)
} ZoneEventSource;
static_assert(sizeof(ZoneEventSource) == 48);

typedef u16 ZoneEventFlags;
#define ZEVFLAG_NEED_KEYS (1 << 4)  // 0x0010, '.b', keys と gInput[0].pressed が重なったときだけ発火する
#define ZEVFLAG_SCRIPT_ID (1 << 5)  // 0x0020, '.p', scriptPC はポインタではなくスクリプトID, VM_ExecByID で起動する

// スクリプトから登録されるイベント, VM_Ctrl_SetZoneCallback が 44バイトを組み立てる
// Map_InsertEvent は同じ zoneID が連続するように挿し込む: 末尾から同じ zoneID を探し、見つかればその次へ (後続を1つずつずらす)、無ければ末尾に追加する
typedef struct CollisionMapEvent {
  u32 id;                // 0x00, Map_InsertEvent が gNextMapEventID の連番を書く
  u16 trigger;           // 0x04, '.m=0x0DD2', 0x0DD2: 入った時, 0xA5BF: 中にいる間, 0xD5CC: 出た時, 0x14C9 ('?'): 入った時と出た時, 0x1516 ('*'): 全部, 0x1517: 入った時と中にいる間
  u16 sourceID;          // 0x06, 反応する ZoneEventSource.id, 0x14C9 ('?') なら誰にでも反応する
  ZoneID16 zoneID;       // 0x08, 発火させるゾーンのID, FindZonesByID に渡す, 挿入時のソートキーでもある (Map_InsertEvent)
  s16 unk_a;             // 0x0A, '.t=0', 読むコードは見つかっていない
  ZoneEventFlags flags;  // 0x0C, see ZoneEventFlags
  u16 zoneCount;         // 0x0E, FindZonesByID が zones の件数を書き込む
  u16 args1[4];          // 0x10, '.w', Map_RunZoneEventScript がスクリプトの引数に積む
  u16 args2[4];          // 0x18, '.s', 同上
  u32 keys;              // 0x20, '.b', ZEVFLAG_NEED_KEYS が立っているとき, gInput[0].pressed と重なったときだけ発火する
  u8* scriptPC;          // 0x24, Map_RunZoneEventScript がスクリプトの PC として実行する
  Zone* zones;           // 0x28, FindZonesByID が返す Zone の先頭, NULL なら登録しない
} CollisionMapEvent;
static_assert(sizeof(CollisionMapEvent) == 44);

// --------------------------------------------

// 読み込み中のコリジョンマップ, gCollisionMap が指す, Malloc(3620) で確保される (Map_InitCollisionMap)
typedef struct CollisionMapData {
  u16 eventCount;                  // 0x000, events の件数
  u8 unk_2[2];                     // 0x002, padding
  CollisionMapTileData* tiledata;  // 0x004, マップファイルのタイルデータ
  u32 unk_8;                       // 0x008, Map_ResetCollisionMap が 0 を書くだけで読み手がいない
  ZoneData* zones;                 // 0x00C, マップファイルのゾーン
  PathData* paths;                 // 0x010, マップファイルの経路データ
  NavMesh* navMesh;                // 0x014, マップファイルのナビメッシュ
  MapTileOverride* tileOverrides;  // 0x018, Map_AddTileOverride がここを先頭とする双方向リストにノードを繋ぐ
  s16 neighborOffsets[4];          // 0x01C, 隣接タイルへの索引差分 -w/1/w/-1
  u16 rowOffsets[256];             // 0x024, 行ごとのタイル索引オフセット表, rowOffsets[blockZ] + blockX がタイル索引
  CollisionMapEvent events[64];    // 0x224
  u32 ctrlBodies[64];              // 0xD24, events と同じ添字の並列配列, イベントを登録した trap 命令の本体の PC, 読むコードはなく挿入と削除で events と一緒にずらすだけ
} CollisionMapData;
static_assert(sizeof(CollisionMapData) == 3620);

extern CollisionMapData* gCollisionMap;

MapTileOverride* Map_FindTileOverride(u32 tileIdx, u32 mask);
void Map_InitTileOverride(MapTileOverride* p, s32 tileIdx, s32 stairs, s32 height, s32 occluder, s32 attr);
s32 Map_AddTileOverride(MapTileOverride* p, s32 tileIdx, s32 stairs, s32 height, s32 occluder, s32 attr);
void Map_RemoveTileOverride(MapTileOverride* p);
u16 Map_GetTileHeightAt(Vec3* pos);
Zone* FindZonesByID(ZoneID16 id, u16* count);
bool8 Map_IsPosInZoneByID(ZoneID16 id, Vec3* pos);
void Map_InsertEvent(CollisionMapEvent* ev, u32 ctrlBody);
bool32 Map_IsPosInAgentIsland(NavAgent* agent, WorldPos* pos, WorldPos* dst);
s32 Map_TryFindNavRoute(NavAgent* agent, WorldPos* pos, WorldPos* dst);
bool32 Map_ConsumeNavWaypointChanged(NavAgent* agent);
s32 Map_FindNavRectAt(Vec3* pos);
s32 Map_InitNavAgent(NavAgent* agent, WorldPos* pos);
void Map_UpdateZoneEvents(ZoneEventSource* src);
s32 Map_FindNavRoute(NavAgent* agent, WorldPos* pos, WorldPos* dst);
bool32 Map_ResetCollisionMap(void);
ZoneID32 GetZoneAt(Vec3* pos);
s32 Map_FindDirToTile(s32 from, s32 to, s32 unused);
s32 Map_PickPathNode(Vec3* dst, Vec3* pos, u32 kind, s32 pathIdx, s32 minDist, Vec3* min, Vec3* max);
s32 Map_IsBehindHigherTile(Vec3* pos, s32 threshold);
s32 Map_FindPathNodeBeyond(Vec3* dst, Vec3* pos, s32 pathIdx, u32 minDistSq);
s32 Map_FindNearestPathNode(Vec3* dst, Vec3* pos, s32 pathIdx);
s32 Map_FindNearestPathNodeBeyond(Vec3* dst, Vec3* pos, s32 pathIdx, u32 minDistSq);

#define IsOutsideMap(tileX, tileZ) ((tileX) < 0 || (tileZ) < 0 || ((u32)(tileX)) >= (u32)gMapBlockW || ((u32)(tileZ)) >= (u32)gMapBlockH)

#endif  // __INCLUDE_COLLISION_MAP_H__
