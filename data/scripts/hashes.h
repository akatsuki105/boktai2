#ifndef __DATA_SCRIPTS_HASHES_H__
#define __DATA_SCRIPTS_HASHES_H__

// data/scripts/scripts.bokc で include する用
// HashName (C 側では BOKHASH) の値に名前を付ける, 行末コメントは元の文字列
// ダンパー (--hashes) は値が一致する u16 の定数をこの名前で出す, commands.h などに名前のある値はそちらを優先する

#define MAP000 0xA679                // BOKHASH("map000")
#define MAP001 0xA67A                // BOKHASH("map001")
#define MAP002 0xA67B                // BOKHASH("map002")
#define MAP003 0xA67C                // BOKHASH("map003")
#define MAP004 0xA67D                // BOKHASH("map004")
#define MAP005 0xA67E                // BOKHASH("map005")
#define MAP006 0xA67F                // BOKHASH("map006")
#define MAP007 0xA680                // BOKHASH("map007")
#define MAP008 0xA681                // BOKHASH("map008")
#define LD000 0xCD22                 // BOKHASH("ld000")
#define LD001 0xCD23                 // BOKHASH("ld001")
#define LD002 0xCD24                 // BOKHASH("ld002")
#define LD003 0xCD25                 // BOKHASH("ld003")
#define LD004 0xCD26                 // BOKHASH("ld004")
#define LD005 0xCD27                 // BOKHASH("ld005")
#define LD006 0xCD28                 // BOKHASH("ld006")
#define LD007 0xCD29                 // BOKHASH("ld007")
#define LD008 0xCD2A                 // BOKHASH("ld008")
#define LD009 0xCD2B                 // BOKHASH("ld009")

#define CAMERA1 0xD23E               // BOKHASH("カメラ1")
#define CAMERA1_FULLWIDTH 0x56CB     // BOKHASH("カメラ１")
#define SOLAR_FLOOR 0x94DD           // BOKHASH("太陽床")

#define WATER_SURFACE_RASTER 0xDB53  // BOKHASH("水面ラスター")
#define UNDERWATER_RASTER 0xD552     // BOKHASH("水中ラスター")
#define DESERT_RASTER 0x4533         // BOKHASH("砂漠ラスター")
#define LAVA_RASTER 0xF9F8           // BOKHASH("溶岩ラスター")

#define FLAMETHROWER0 0xECFA // BOKHASH("火炎0")
#define FLAMETHROWER1 0xECFB // BOKHASH("火炎1")
#define FLAMETHROWER2 0xECFC // BOKHASH("火炎2")
#define FLAMETHROWER3 0xECFD // BOKHASH("火炎3")
#define FLAMETHROWER4 0xECFE // BOKHASH("火炎4")

#define NPC_MANAGER 0x901B                // BOKHASH("NPCマネージャ"), NPCが半角

#define CHR_DJANGO 0xBF31          // BOKHASH("ジャンゴ")
#define CHR_OTENKO 0xBB34          // BOKHASH("おてんこ")
#define CHR_SABATA 0x2B06          // BOKHASH("サバタ")
#define CHR_RINGO 0xBA4B          // BOKHASH("リンゴ")
#define CHR_RITA 0x3DB5                // BOKHASH("リタ")
#define CHR_DUNEYRR 0x2B18                // BOKHASH("ドゥネイル")

// tilemap.h
#define MP_TREE 0x9D28               // 太陽樹 のタイルマップ

// collision_map.h, Scr_LoadCollisionMap
#define ST00_00_HPK 0x050F           // BOKHASH("st00_00_hpk")
#define ST00_01_HPK 0x051F           // BOKHASH("st00_01_hpk")
#define ST00_02_HPK 0x052F           // BOKHASH("st00_02_hpk")
#define ST00_03_HPK 0x053F           // BOKHASH("st00_03_hpk")
#define ST00_04_HPK 0x054F           // BOKHASH("st00_04_hpk")
#define ST01_00_CATHED_HPK 0x78F6    // BOKHASH("st01_00_cathed_hpk")
#define ST01_01_CATHED_HPK 0x7976    // BOKHASH("st01_01_cathed_hpk")
#define ST01_02_CATHED_HPK 0x79F6    // BOKHASH("st01_02_cathed_hpk")
#define ST01_03_CATHED_HPK 0x7A76    // BOKHASH("st01_03_cathed_hpk")
#define ST01_04_CATHED_HPK 0x7AF6    // BOKHASH("st01_04_cathed_hpk")
#define ST01_05_CATHED_HPK 0x7B76    // BOKHASH("st01_05_cathed_hpk")
#define ST01_06_CATHED_HPK 0x7BF6    // BOKHASH("st01_06_cathed_hpk")
#define ST01_07_CATHED_HPK 0x7C76    // BOKHASH("st01_07_cathed_hpk")
#define ST01_08_CATHED_HPK 0x7CF6    // BOKHASH("st01_08_cathed_hpk")
#define ST01_09_CATHED_HPK 0x7D76    // BOKHASH("st01_09_cathed_hpk")
#define ST01_10_CATHED_HPK 0x88F6    // BOKHASH("st01_10_cathed_hpk")
#define ST01_11_CATHED_HPK 0x8976    // BOKHASH("st01_11_cathed_hpk")
#define ST01_12_CATHED_HPK 0x89F6    // BOKHASH("st01_12_cathed_hpk")
#define ST01_13_CATHED_HPK 0x8A76    // BOKHASH("st01_13_cathed_hpk")
#define ST01_14_CATHED_HPK 0x8AF6    // BOKHASH("st01_14_cathed_hpk")
#define ST01_15_CATHED_HPK 0x8B76    // BOKHASH("st01_15_cathed_hpk")
#define ST01_16_CATHED_HPK 0x8BF6    // BOKHASH("st01_16_cathed_hpk")
#define ST01_17_CATHED_HPK 0x8C76    // BOKHASH("st01_17_cathed_hpk")
#define ST01_18_CATHED_HPK 0x8CF6    // BOKHASH("st01_18_cathed_hpk")
#define F00_HPK 0x11B6               // BOKHASH("f00_hpk")
#define F01_HPK 0x11C6               // BOKHASH("f01_hpk")
#define F02_HPK 0x11D6               // BOKHASH("f02_hpk")
#define F03_HPK 0x11E6               // BOKHASH("f03_hpk")
#define F04_HPK 0x11F6               // BOKHASH("f04_hpk")
#define F05_HPK 0x1206               // BOKHASH("f05_hpk")
#define ST02_09_DESERT_HPK 0xFCAD    // BOKHASH("st02_09_desert_hpk")

#endif  // __DATA_SCRIPTS_HASHES_H__
