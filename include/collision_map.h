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
  // TODO
} NavIsland;

typedef struct {
  u32 countIslands;      // 0x00
  u32 islandOffsets[1];  // 0x04, islandOffsets[countIslands]
  NavIsland islands[1];  // NavIsland[countIslands]
} NavMesh;

#endif  // __INCLUDE_COLLISION_MAP_H__
