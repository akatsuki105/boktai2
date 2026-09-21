#ifndef __INCLUDE_COLLISION_MAP_H__
#define __INCLUDE_COLLISION_MAP_H__

#include "gba/gba.h"
#include "types.h"

// マップの 高さ情報、衝突判定データ、イベントトリガーなど をまとめたファイル, タイルセット、タイルマップ、パレットなどのグラフィックデータは含まない
// このソースコードではゲームのマップ単位をブロック(block)と呼ぶようにする(具体的には 木箱とかの立方体の大きさが1ブロック)
// https://boktaihacking.net/wiki/Collision_map_file

typedef struct {
  char magic[4];         // 0x00, "HP\0\0"
  u32 offsetToTileData;  // 0x04, この構造体の先頭から CollisionMapTileData 構造体までのバイトオフセット
  u32 offsetToZones;     // 0x08, この構造体の先頭から ZoneData 構造体までのバイトオフセット
  u32 offsetToPaths;     // 0x0C, この構造体の先頭から PathData 構造体までのバイトオフセット
  u32 offsetToNavmesh;   // 0x10, この構造体の先頭から NavMesh 構造体までのバイトオフセット
  // これ以降はそれぞれサイズが可変
  // CollisionMapTileData tileData;  // 床の属性や高さ、階段やプレイヤーが奥側にいるときに手前に何を描画するかなどの情報を持つ
  // ZoneData zoneData;   // イベントのトリガー範囲を管理する
  // PathData pathData;   // ???
  // NavMesh navMesh;     // NPCをマップ上の任意の2点間で移動させるためのデータ
} CollisionMapFile;

extern u8 gDecompressedCollisionMapHeader[4];    // 0x02031400, 展開先の先頭4バイト, 用途不明
extern u8 gDecompressedCollisionMapFile[16380];  // 0x02031404, 展開された CollisionMapFile 本体

// --------------------------------------------

// 地形の上書き情報を管理する構造体
// 根拠: FUN_08234270 (挿入) / FUN_082342a8 (除去) / FUN_08234208 (各フィールドの初期化)
typedef struct MapTileOverride {
  u16 unk_0;                     // 0x00, FUN_08234208 が 0 を書く
  u16 tileIdx;                   // 0x02, FUN_08234208 の第2引数, 呼び出し側はコリジョンマップのタイル索引を渡す
  u8 height;                     // 0x04, FUN_08234208 が param_3 << 4 | param_4 を書く, 呼び出し側はタイルの高さを渡す
  u8 unk_5;                      // 0x05, EntityEC96_Init は 0xFF を渡す
  u16 unk_6;                     // 0x06, EntityEC96_Init は 0 を渡す
  struct MapTileOverride* prev;  // 0x08, FUN_08234270 が挿入時に NULL を書く
  struct MapTileOverride* next;  // 0x0C, FUN_08234270 が挿入時に旧 head を書く
} MapTileOverride;
static_assert(sizeof(MapTileOverride) == 16);

// --------------------------------------------

typedef u16 TileAttr;             // CollisionMapTile.attr
#define TATTR_WALL (1 << 1)       // 0x0001, 壁(常に侵入不可)
#define TATTR_UNK_2 (1 << 2)      // 0x0004, sometimes used directly on loading zone tiles
#define TATTR_NOISE (1 << 5)      // 0x0020, alerts enemies when stepping onto the tile
#define TATTR_ICE (1 << 6)        // 0x0040
#define TATTR_LAVA (1 << 7)       // 0x0080
#define TATTR_FALLDEATH (1 << 8)  // 0x0100, 落下死する
#define TATTR_WALLISH (1 << 10)   // 0x0400, TATTR_WALL との違いは不明
#define TATTR_UNK_11 (1 << 11)    // 0x0800, sometimes used near loading zones pointing NW
#define TATTR_UNK_12 (1 << 12)    // 0x1000, sometimes used near loading zones pointing NE

typedef struct {
  TileAttr attr;  // 0x00, see TileAttr
  u8 obj;         // 0x02, タイルで隠されるべき場合に使用されるスプライト
  u8 height : 4;  // 同じ高さのタイル か (高さが適切な)階段タイル から侵入可能
  u8 stairs : 4;  // 0: none, 1: vertical, 2: horizontal
} CollisionMapTile;
static_assert(sizeof(CollisionMapTile) == 4);

typedef struct {
  u32 unk_0;                  // 0x00
  s16 width;                  // 0x04
  s16 height;                 // 0x06
  s16 tilemap_offset_x;       // 0x08, pixel position of tilemap on the collision map (for camera)
  s16 tilemap_offset_y;       // 0x0A, pixel position of tilemap on the collision map (for camera)
  CollisionMapTile tiles[1];  // 0x0C, CollisionMapTile[width * height]
} CollisionMapTileData;

// --------------------------------------------

// イベント（カットシーン、ロードゾーンなど）のトリガー
typedef struct {
  s16 x1;  // 0x00, X/Y coordinates: 1 tile = 256 units
  s16 y1;  // 0x02
  s16 x2;  // 0x04
  s16 y2;  // 0x06
  s8 z1;   // 0x08, Z coordinate: 1 tile = 16 units
  s8 z2;   // 0x09
  u16 id;  // 0x0A, Used by scripts to link behaviour to a specific zone using its ID
} Zone;
static_assert(sizeof(Zone) == 12);

typedef struct {
  u8 count;       // 0x00, number of Zone
  u8 unk_1;       // 0x01
  u16 unk_2;      // 0x02
  Zone zones[1];  // 0x04, Zone[count]
} ZoneData;

// --------------------------------------------

typedef struct {
  u16 x;        // 0x00, X/Y coordinates: 1 tile = 256 units
  u16 y;        // 0x02
  u8 delay;     // 0x04, In frames, after performing the command
  u8 param;     // 0x05, Command-specific parameter
  u16 command;  // 0x06, 0x00: x/y座標へ移動, 0x10: 方向転換, 0x30: 眠りにつく, 0x90/0xB0/0xE0: ?マークを表示, 0xA0/0xE0: Go to space, 0xD0: Start searching
} PathNode;

typedef struct {
  u16 nodeCount;   // 0x00, number of PathNode
  u16 nodeOffset;  // 0x02, Byte offset from start of PathData to first node
} Path;

typedef struct {
  u32 pathCount;      // 0x00, number of Path
  Path paths[1];      // 0x04, Path[pathCount]
  PathNode nodes[1];  // 要素数は Path[Path.nodeCount] の合計?
} PathData;

// --------------------------------------------

typedef struct {
  u16 countRects;           // 0x00
  u16 countPortals;         // 0x02
  u16 countDistanceMap;     // 0x04
  u32 offsetToRects;        // 0x08, Byte offset from start of NavIsland to rects
  u32 offsetToPortals;      // 0x0C, Byte offset from start of NavIsland to portals
  u32 offsetToDistanceMap;  // 0x10, Byte offset from start of NavIsland to distance map

  struct NavRect {
    u8 minX;         // 0x00, 1 tile = 1
    u8 minY;         // 0x01
    u8 maxX;         // 0x02
    u8 maxY;         // 0x03
    u8 portals[12];  // 0x04, Indices into NavMesh.portals. At most 12 portals per rect, unused elements in this array must be at the end of the array, and set to 0xFF.
  } rects[1];        // NavRect[countRects]

  struct NavPortal {
    u16 x;       // 0x00, 1 tile = 0x100
    u16 y;       // 0x02
    u16 unk_4;   // 0x04
  } portals[1];  // NavPortal[countPortals]

  u16 distanceMap[1];  // u16[countDistanceMap]
} NavIsland;

typedef struct {
  u32 countIslands;      // 0x00
  u32 islandOffsets[1];  // 0x04, islandOffsets[countIslands]
  NavIsland islands[1];  // NavIsland[countIslands]
} NavMesh;

// --------------------------------------------

// スクリプトから登録されるイベント, VM_Ctrl_D4CB が 44バイトを組み立て FUN_082349b8 が unk_8 をキーに挿入する
typedef struct CollisionMapEvent {
  u32 id;        // 0x00, FUN_082349b8 が u32_030046b0 の連番を書く
  u16 unk_4;     // 0x04, FUN_08234660 が 0xDD2/0x14C9/0x1516/0x1517/0xA5BF と比較する (VM のキーワード 'm', 既定 0xDD2)
  s16 unk_6;     // 0x06, VM_Ctrl_D4CB の Script_GetValue 2番目
  s16 unk_8;     // 0x08, 挿入時のソートキー, 根拠: FUN_082349b8
  s16 unk_a;     // 0x0A
  u16 unk_c;     // 0x0C
  s16 unk_e;     // 0x0E
  u16 args1[4];  // 0x10, FUN_08234868 が ScriptArgs にコピーする4語
  u16 args2[4];  // 0x18, 同上、もう4語
  u8* unk_20;    // 0x20
  u8* scriptPC;  // 0x24, FUN_08234868 がスクリプトの PC として実行する
  s32 unk_28;    // 0x28
} CollisionMapEvent;
static_assert(sizeof(CollisionMapEvent) == 44);

// --------------------------------------------

// 読み込み中のコリジョンマップ, gCollisionMap が指す, Malloc(3620) で確保される (FUN_082326a0)
typedef struct CollisionMapData {
  u16 eventCount;                  // 0x000, events の件数, 根拠: FUN_082326d8 が 0 を書き FUN_082349b8 が +1 する
  u8 unk_2[2];                     // 0x002, 読み書きするコードが見つかっていない, padding?
  CollisionMapTileData* tiledata;  // 0x004
  u32 unk_8;                       // 0x008, FUN_082326d8 が 0 を書くだけで読み手がいない
  ZoneData* zones;                 // 0x00C
  PathData* paths;                 // 0x010
  NavMesh* navMesh;                // 0x014
  MapTileOverride* tileOverrides;  // 0x018, FUN_08234270 がここを先頭とする双方向リストにノードを繋ぐ
  s16 neighborOffsets[4];          // 0x01C, 隣接タイルへの索引差分 -w/1/w/-1, 根拠: FUN_0823273c。読み手は (dir & 3) で引く
  u16 rowOffsets[256];             // 0x024, 行ごとのタイル索引オフセット表, rowOffsets[blockZ] + blockX がタイル索引
  CollisionMapEvent events[64];    // 0x224, 根拠: FUN_082326d8 が i=0..63 で 44バイトずつクリアする
  u32 unk_d24[64];                 // 0xD24, events と同じ添字の並列配列, FUN_082349b8 の第2引数が入る
} CollisionMapData;
static_assert(sizeof(CollisionMapData) == 3620);

extern CollisionMapData* gCollisionMap;

MapTileOverride* FUN_08234224(u32 tileIdx, u32 mask);
void FUN_082342a8(MapTileOverride* p);

#endif  // __INCLUDE_COLLISION_MAP_H__
