#include "global.h"

// ---------------- entity_081d16ec.c -----------------

struct Entity081d16ec;
struct Entity081d16ecItem;

void FUN_081d146c(struct Entity081d16ec* p, struct Entity081d16ecItem* item);
void FUN_081d14e0(struct Entity081d16ec* p, struct Entity081d16ecItem* item);
void FUN_081d12e0(struct Entity081d16ec* p, struct Entity081d16ecItem* item);
void FUN_081d15f8(struct Entity081d16ec* p, struct Entity081d16ecItem* item);

// Entity081d16ecItem.state (0xB0) で引く
void (*const PTR_ARRAY_085ae0b8[4])(struct Entity081d16ec*, struct Entity081d16ecItem*) = {
    FUN_081d146c,
    FUN_081d14e0,
    FUN_081d12e0,
    FUN_081d15f8,
};  // 0x085AE0B8

// ---------------- entity_081d2180.c -----------------

struct Entity081d2180Item;

void FUN_081d1ae8(struct Entity081d2180Item* item);
void FUN_081d1cdc(struct Entity081d2180Item* item);

// Entity081d2180Item.state (0x7E) で引く
void (*const PTR_ARRAY_085ae0c8[2])(struct Entity081d2180Item*) = {
    FUN_081d1ae8,
    FUN_081d1cdc,
};  // 0x085AE0C8

// ---------------- elevator.c -----------------

struct ElevatorUnkData;

void FUN_081d280c(struct ElevatorUnkData* p);
void FUN_081d2a14(struct ElevatorUnkData* p);
void FUN_081d2810(struct ElevatorUnkData* p);
void FUN_081d2fd0(struct ElevatorUnkData* p);
void FUN_081d2cf8(struct ElevatorUnkData* p);
void FUN_081d3110(struct ElevatorUnkData* p);
void FUN_081d3114(struct ElevatorUnkData* p);

// エレベータが乗り手との距離を測るときの許容範囲 (±), Elevator_FindAtPos ほかが引く
const Vec3 gElevatorRanges[3] = {
    {128, 32, 128},
    {128, 32, 128},
    {98,  32, 98 }
};  // 0x085AE0D0

// ElevatorUnkData.state (0xB2) で引く, 6 はスキップされる
void (*const PTR_ARRAY_085ae0e8[7])(struct ElevatorUnkData*) = {
    FUN_081d280c,
    FUN_081d2a14,
    FUN_081d2810,
    FUN_081d2fd0,
    FUN_081d2cf8,
    FUN_081d3110,
    FUN_081d3114,
};  // 0x085AE0E8

// ---------------- entity_f1f9.c -----------------

struct EntityF1F9;
struct EntityF1F9Item;

void FUN_081d5d14(struct EntityF1F9* p, struct EntityF1F9Item* item);
void FUN_081d5d18(struct EntityF1F9* p, struct EntityF1F9Item* item);
void FUN_081d5d70(struct EntityF1F9* p, struct EntityF1F9Item* item);
void FUN_081d60c8(struct EntityF1F9* p, struct EntityF1F9Item* item);
void FUN_081d6200(struct EntityF1F9* p, struct EntityF1F9Item* item);

// EntityF1F9Item.state (0x148) で引く
void (*const PTR_ARRAY_085ae104[5])(struct EntityF1F9*, struct EntityF1F9Item*) = {
    FUN_081d5d14,
    FUN_081d5d18,
    FUN_081d5d70,
    FUN_081d60c8,
    FUN_081d6200,
};  // 0x085AE104

// ---------------- entity_c60f.c -----------------

struct EntityC60FItem;

void FUN_081d6f60(struct EntityC60FItem* p);
void FUN_081d7358(struct EntityC60FItem* p);
void FUN_081d76bc(struct EntityC60FItem* p);
void FUN_081d785c(struct EntityC60FItem* p);
void FUN_081d7a60(struct EntityC60FItem* p);

// EntityC60FItem.state (0xFE) で引く
void (*const PTR_ARRAY_085ae118[5])(struct EntityC60FItem*) = {
    FUN_081d6f60,
    FUN_081d7358,
    FUN_081d76bc,
    FUN_081d785c,
    FUN_081d7a60,
};  // 0x085AE118

// ---------------- entity_8cc7.c -----------------

struct Entity8CC7;
struct Entity8CC7Elem;

void nop_081d8dc0(void);
void FUN_081d919c(struct Entity8CC7* p, struct Entity8CC7Elem* e);
void FUN_081d8dc4(struct Entity8CC7* p, struct Entity8CC7Elem* e);
void FUN_081d93b0(struct Entity8CC7* p, struct Entity8CC7Elem* e);
void FUN_081d96b8(struct Entity8CC7* p, struct Entity8CC7Elem* e);
void FUN_081d98a0(struct Entity8CC7* p, struct Entity8CC7Elem* e);

// Entity8CC7_Update が引く状態関数表
void (*const PTR_ARRAY_085ae12c[6])(struct Entity8CC7*, struct Entity8CC7Elem*) = {
    (void*)nop_081d8dc0,
    FUN_081d919c,
    FUN_081d8dc4,
    FUN_081d93b0,
    FUN_081d96b8,
    FUN_081d98a0,
};  // 0x085AE12C

// ---------------- entity_7999.c -----------------

// FUN_081da038 が引く
const u32 u32_ARRAY_085ae144[7] = {0, 2, 3, 4, 5, 11, 13};  // 0x085AE144

// FUN_081d9da4 / FUN_081d9e50 / FUN_081da14c が引く
const u32 u32_ARRAY_085ae160[3] = {1, 16, 8};  // 0x085AE160

// FUN_081d9e50 / FUN_081da468 が引く
// 推測: s32[18], 6要素3組 = {0, 0, 0, 32, 0, 64} / {0, 0, 0, 32, -16, 64} / {0, 0, 0, 32, 0, 64}
const s32 s32_ARRAY_085ae16c[18] = {0, 0, 0, 32, 0, 64, 0, 0, 0, 32, -16, 64, 0, 0, 0, 32, 0, 64};  // 0x085AE16C

// ---------------- entity_08f4.c -----------------

const s32 s32_ARRAY_085ae1b4[6] = {0, 0, 0, 32, 0, 64};  // 0x085AE1B4

const s32 s32_ARRAY_085ae1cc[6] = {32, 0, 32, 32, 16, 64};  // 0x085AE1CC

const s32 s32_ARRAY_085ae1e4[6] = {0, 0, 0, 32, 0, 64};  // 0x085AE1E4

const u16 u16_ARRAY_085ae1fc[4] = {60, 90, 120, 0};  // 0x085AE1FC

// ---------------- link_battle_lobby.c -----------------

// FUN_081dbea0 がバイト単位で引く
// 推測: u16[228]
// clang-format off
const u8 u8_ARRAY_085ae204[456] = {
    0x00, 0x04, 0x00, 0x04, 0x20, 0x00, 0x21, 0x00, 0x22, 0x00, 0x20, 0x00, 0x30, 0x00, 0x31, 0x00,
    0x32, 0x00, 0x30, 0x00, 0x23, 0x00, 0x24, 0x00, 0x25, 0x00, 0x23, 0x00, 0x33, 0x00, 0x34, 0x00,
    0x35, 0x00, 0x33, 0x00, 0x26, 0x00, 0x27, 0x00, 0x28, 0x00, 0x26, 0x00, 0x36, 0x00, 0x37, 0x00,
    0x38, 0x00, 0x36, 0x00, 0x29, 0x00, 0x2A, 0x00, 0x2B, 0x00, 0x29, 0x00, 0x39, 0x00, 0x3A, 0x00,
    0x3B, 0x00, 0x39, 0x00, 0x07, 0x00, 0x04, 0x00, 0x08, 0x00, 0x04, 0x00, 0x09, 0x00, 0x04, 0x00,
    0x0A, 0x00, 0x04, 0x00, 0x07, 0x00, 0x05, 0x00, 0x08, 0x00, 0x05, 0x00, 0x09, 0x00, 0x05, 0x00,
    0x0A, 0x00, 0x05, 0x00, 0x07, 0x00, 0x08, 0x00, 0x08, 0x00, 0x08, 0x00, 0x09, 0x00, 0x08, 0x00,
    0x0A, 0x00, 0x08, 0x00, 0x07, 0x00, 0x09, 0x00, 0x08, 0x00, 0x09, 0x00, 0x09, 0x00, 0x09, 0x00,
    0x0A, 0x00, 0x09, 0x00, 0x07, 0x00, 0x0C, 0x00, 0x08, 0x00, 0x0C, 0x00, 0x09, 0x00, 0x0C, 0x00,
    0x0A, 0x00, 0x0C, 0x00, 0x07, 0x00, 0x0D, 0x00, 0x08, 0x00, 0x0D, 0x00, 0x09, 0x00, 0x0D, 0x00,
    0x0A, 0x00, 0x0D, 0x00, 0x07, 0x00, 0x10, 0x00, 0x08, 0x00, 0x10, 0x00, 0x09, 0x00, 0x10, 0x00,
    0x0A, 0x00, 0x10, 0x00, 0x07, 0x00, 0x11, 0x00, 0x08, 0x00, 0x11, 0x00, 0x09, 0x00, 0x11, 0x00,
    0x0A, 0x00, 0x11, 0x00, 0x0E, 0x00, 0x2C, 0x00, 0x2D, 0x00, 0x2E, 0x00, 0x0E, 0x00, 0x0E, 0x00,
    0x3C, 0x00, 0x3D, 0x00, 0x3E, 0x00, 0x0E, 0x00, 0x01, 0x00, 0x40, 0x00, 0x41, 0x00, 0x42, 0x00,
    0x01, 0x00, 0x01, 0x00, 0x50, 0x00, 0x51, 0x00, 0x52, 0x00, 0x01, 0x00, 0x01, 0x00, 0x43, 0x00,
    0x44, 0x00, 0x42, 0x00, 0x01, 0x00, 0x01, 0x00, 0x53, 0x00, 0x54, 0x00, 0x52, 0x00, 0x01, 0x00,
    0x01, 0x00, 0x45, 0x00, 0x46, 0x00, 0x47, 0x00, 0x01, 0x00, 0x01, 0x00, 0x55, 0x00, 0x56, 0x00,
    0x57, 0x00, 0x01, 0x00, 0x01, 0x00, 0x2F, 0x00, 0x2F, 0x00, 0x2F, 0x00, 0x01, 0x00, 0x01, 0x00,
    0x3F, 0x00, 0x3F, 0x00, 0x3F, 0x00, 0x01, 0x00, 0x01, 0x00, 0x04, 0x00, 0x02, 0x00, 0x04, 0x00,
    0x03, 0x00, 0x04, 0x00, 0x04, 0x00, 0x04, 0x00, 0x05, 0x00, 0x04, 0x00, 0x01, 0x00, 0x05, 0x00,
    0x02, 0x00, 0x05, 0x00, 0x03, 0x00, 0x05, 0x00, 0x04, 0x00, 0x05, 0x00, 0x05, 0x00, 0x05, 0x00,
    0x01, 0x00, 0x08, 0x00, 0x02, 0x00, 0x08, 0x00, 0x03, 0x00, 0x08, 0x00, 0x04, 0x00, 0x08, 0x00,
    0x05, 0x00, 0x08, 0x00, 0x01, 0x00, 0x09, 0x00, 0x02, 0x00, 0x09, 0x00, 0x03, 0x00, 0x09, 0x00,
    0x04, 0x00, 0x09, 0x00, 0x05, 0x00, 0x09, 0x00, 0x01, 0x00, 0x0C, 0x00, 0x02, 0x00, 0x0C, 0x00,
    0x03, 0x00, 0x0C, 0x00, 0x04, 0x00, 0x0C, 0x00, 0x05, 0x00, 0x0C, 0x00, 0x01, 0x00, 0x0D, 0x00,
    0x02, 0x00, 0x0D, 0x00, 0x03, 0x00, 0x0D, 0x00, 0x04, 0x00, 0x0D, 0x00, 0x05, 0x00, 0x0D, 0x00,
    0x01, 0x00, 0x10, 0x00, 0x02, 0x00, 0x10, 0x00, 0x03, 0x00, 0x10, 0x00, 0x04, 0x00, 0x10, 0x00,
    0x05, 0x00, 0x10, 0x00, 0x01, 0x00, 0x11, 0x00, 0x02, 0x00, 0x11, 0x00, 0x03, 0x00, 0x11, 0x00,
    0x04, 0x00, 0x11, 0x00, 0x05, 0x00, 0x11, 0x00,
};  // 0x085AE204
// clang-format on

// ---------------- link_battle_result.c -----------------

// FUN_081dd124 が引く
// 推測: 先頭4要素は u16 = {100, 100, 40, 1}
const u8 u8_ARRAY_085ae3cc[28] = {0x64, 0x00, 0x64, 0x00, 0x28, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0xC0, 0x00, 0x00, 0x30, 0x10, 0xC0, 0x00, 0x30, 0x10, 0xF0, 0xD0};  // 0x085AE3CC

// ---------------- entity_9a9f.c -----------------

// FUN_081ddf84 が unk_2cc[i] の上限として引く
const s32 sEntity9A9FLimits[3] = {2, 3, 4};  // 0x085AE3E8

// 推測: u8[8][2]
const u8 u8_ARRAY_085ae3f4[16] = {0x10, 0x0E, 0x18, 0x15, 0x20, 0x1C, 0x32, 0x1E, 0x0A, 0x28, 0x5A, 0x3C, 0x3C, 0x3C, 0x00, 0x00};  // 0x085AE3F4

// 推測: u8[18][4]
const u8 u8_ARRAY_085ae404[72] = {0x0C, 0x04, 0x10, 0x01, 0x0D, 0x05, 0x00, 0x02, 0x0E, 0x06, 0x01, 0x03, 0x0F, 0x07, 0x02, 0x10, 0x00, 0x08, 0x10, 0x05, 0x01, 0x09, 0x04, 0x06, 0x02, 0x0A, 0x05, 0x07, 0x03, 0x0B, 0x06, 0x10, 0x04, 0x0C, 0x10, 0x09,
                                  0x05, 0x0D, 0x08, 0x0A, 0x06, 0x0E, 0x09, 0x0B, 0x07, 0x0F, 0x0A, 0x10, 0x08, 0x00, 0x11, 0x0D, 0x09, 0x01, 0x0C, 0x0E, 0x0A, 0x02, 0x0D, 0x0F, 0x0B, 0x03, 0x0E, 0x11, 0x11, 0x11, 0x03, 0x00, 0x10, 0x10, 0x0F, 0x0C};  // 0x085AE404

// ---------------- code_081e0c14.s -----------------

// FUN_081e8664 が Mod の除数として引く
const u8 u8_ARRAY_085ae44c[4] = {0x08, 0x04, 0x02, 0x01};  // 0x085AE44C

void FUN_081e8660(unknown*, unknown*);
void FUN_081e86ec(unknown*, unknown*);
void FUN_081e8710(unknown*, unknown*);

// Entity081e8d0c_Update が (p, item) で呼ぶ
void (*const PTR_ARRAY_085ae450[3])(unknown*, unknown*) = {
    FUN_081e8660,
    FUN_081e8710,
    FUN_081e86ec,
};  // 0x085AE450

// ---------------- entity_081ea120.c -----------------

struct Entity081ea120;

void FUN_081e9dc4(struct Entity081ea120* p, unknown* item);
void FUN_081e9dc8(struct Entity081ea120* p, unknown* item);
void FUN_081e9ee8(struct Entity081ea120* p, unknown* item);

// Entity081ea120_Update が (p, item) で呼ぶ
void (*const PTR_ARRAY_085ae45c[3])(struct Entity081ea120*, unknown*) = {
    FUN_081e9dc4,
    FUN_081e9dc8,
    FUN_081e9ee8,
};  // 0x085AE45C

// FUN_081ea44c が Mod の除数として引く
const u8 u8_ARRAY_085ae468[4] = {0x08, 0x04, 0x02, 0x01};  // 0x085AE468

// ---------------- entity_081ea820.c -----------------

struct Entity081ea820;

void FUN_081ea17c(struct Entity081ea820* p, unknown* item);
void FUN_081ea268(struct Entity081ea820* p, unknown* item);
void FUN_081ea44c(struct Entity081ea820* p, unknown* item);

// Entity081ea820_Update が (p, item) で呼ぶ
void (*const PTR_ARRAY_085ae46c[3])(struct Entity081ea820*, unknown*) = {
    FUN_081ea17c,
    FUN_081ea268,
    FUN_081ea44c,
};  // 0x085AE46C

const u8 u8_ARRAY_085ae478[18] = {0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10, 0x11, 0x12, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09};  // 0x085AE478

// ---------------- flamethrower.c -----------------

const u8 u8_ARRAY_085ae48a[2] = {0x00, 0x00};  // 0x085AE48A

void FUN_081ea878(unknown* p);
void FUN_081eaa10(unknown* p);
void FUN_081eaa54(unknown* p);

// Entity081eaf6c_Update が引く
void (*const PTR_ARRAY_085ae48c[3])(unknown*) = {
    FUN_081ea878,
    FUN_081eaa10,
    FUN_081eaa54,
};  // 0x085AE48C

const Vec3 vec3_ARRAY_085ae498[3] = {
    {48, 32, 220},
    {48, 32, 276},
    {48, 32, 384}
};  // 0x085AE498

// ---------------- entity_081eb2f0.c -----------------

struct Entity081eb2f0;
struct Particle;

void FUN_081eafbc(struct Entity081eb2f0* p, struct Particle* ptcl);
void FUN_081eafc0(struct Entity081eb2f0* p, struct Particle* ptcl);
void FUN_081eb0ec(struct Entity081eb2f0* p, struct Particle* ptcl);

// Entity081eb2f0_Update が (p, ptcl) で呼ぶ
void (*const PTR_ARRAY_085ae4b0[3])(struct Entity081eb2f0*, struct Particle*) = {
    FUN_081eafbc,
    FUN_081eafc0,
    FUN_081eb0ec,
};  // 0x085AE4B0

// ---------------- code_081eafbc.s -----------------

void FUN_081ed6d8(unknown*, unknown*);
void FUN_081ed6dc(unknown*, unknown*);
void FUN_081eda54(unknown*, unknown*);
void FUN_081edd1c(unknown*, unknown*);
void FUN_081eddb0(unknown*, unknown*);
void FUN_081ee02c(unknown*, unknown*);
void FUN_081ee800(unknown*, unknown*);
void FUN_081ee858(unknown*, unknown*);
void FUN_081ee974(unknown*, unknown*);
void FUN_081eeb80(unknown*, unknown*);
void FUN_081eeb84(unknown*, unknown*);
void FUN_081eec1c(unknown*, unknown*);
void FUN_081eeed8(unknown*, unknown*);
void FUN_081eef2c(unknown*, unknown*);
void FUN_081ef3fc(unknown*, unknown*);
void FUN_081ef5ec(unknown*, unknown*);
void FUN_081efb94(unknown*, unknown*);
void FUN_081efc20(unknown*, unknown*);
void FUN_081efd78(unknown*, unknown*);
void FUN_081f03a0(unknown*, unknown*);
void FUN_081f03a4(unknown*, unknown*);
void FUN_081f0604(unknown*, unknown*);
void FUN_081f0678(unknown*, unknown*);
void FUN_081f0be8(unknown*, unknown*);
void FUN_081f0c3c(unknown*, unknown*);
void FUN_081f12cc(unknown*, unknown*);
void FUN_081f1428(unknown*, unknown*);
void FUN_081f1940(unknown*, unknown*);
void FUN_081f1994(unknown*, unknown*);
void FUN_081f1cc8(unknown*, unknown*);
void FUN_081f1ffc(unknown*, unknown*);
void FUN_081f27d0(unknown*, unknown*);
void FUN_081f28c0(unknown*, unknown*);
void FUN_081f29b4(unknown*, unknown*);
void FUN_081f2af8(unknown*, unknown*);
void FUN_081f2e68(unknown*, unknown*);
void FUN_081f3394(unknown*, unknown*);
void FUN_081f3398(unknown*, unknown*);
void FUN_081f3508(unknown*, unknown*);
void FUN_081f3aa0(unknown*, unknown*);
void FUN_081f3e64(unknown*, unknown*);
void FUN_081f4010(unknown*, unknown*);
void FUN_081f48ac(unknown*, unknown*);
void FUN_081f48b0(unknown*, unknown*);
void FUN_081f4af4(unknown*, unknown*);
void FUN_081f4d80(unknown*, unknown*);
void FUN_081f6314(unknown*, unknown*);
void FUN_081f6318(unknown*, unknown*);
void FUN_081f6368(unknown*, unknown*);
void FUN_081f6afc(unknown*, unknown*);
void FUN_081f6c78(unknown*, unknown*);
void FUN_081f6d14(unknown*, unknown*);
void FUN_081f710c(unknown*, unknown*);
void FUN_081f74f0(unknown*, unknown*);
void FUN_081f74f4(unknown*, unknown*);
void FUN_081f75f0(unknown*, unknown*);
void FUN_081f7624(unknown*, unknown*);
void FUN_081f7a14(unknown*, unknown*);
void FUN_081f7a18(unknown*, unknown*);
void FUN_081f7b5c(unknown*, unknown*);
void FUN_081f8120(unknown*, unknown*);
void FUN_081f8124(unknown*, unknown*);
void FUN_081f82cc(unknown*, unknown*);
void FUN_081f8620(unknown*, unknown*);
void FUN_081f8d0c(unknown*, unknown*);
void FUN_081f8d10(unknown*, unknown*);
void FUN_081f8eb0(unknown*, unknown*);
void FUN_081f90e0(unknown*, unknown*);
void FUN_081f9924(unknown*, unknown*);
void FUN_081f9928(unknown*, unknown*);
void FUN_081f9980(unknown*, unknown*);
void FUN_081f9adc(unknown*, unknown*);
void FUN_081f9dfc(unknown*, unknown*);
void FUN_081f9e94(unknown*, unknown*);
void FUN_081f9ee8(unknown*, unknown*);

void FUN_081ee2f8(unknown* p);
void FUN_081ee328(unknown* p);
void FUN_081ee4d0(unknown* p);

void (*const PTR_ARRAY_085ae4bc[3])(unknown*, unknown*) = {
    FUN_081ed6d8,
    FUN_081ed6dc,
    FUN_081eda54,
};  // 0x085AE4BC

void (*const PTR_ARRAY_085ae4c8[3])(unknown*, unknown*) = {
    FUN_081edd1c,
    FUN_081eddb0,
    FUN_081ee02c,
};  // 0x085AE4C8

// 引数1つで呼ばれる (FUN_081ee70c)
void (*const PTR_ARRAY_085ae4d4[3])(unknown*) = {
    FUN_081ee2f8,
    FUN_081ee328,
    FUN_081ee4d0,
};  // 0x085AE4D4

void (*const PTR_ARRAY_085ae4e0[3])(unknown*, unknown*) = {
    FUN_081ee800,
    FUN_081ee858,
    FUN_081ee974,
};  // 0x085AE4E0

void (*const PTR_ARRAY_085ae4ec[3])(unknown*, unknown*) = {
    FUN_081eeb80,
    FUN_081eeb84,
    FUN_081eec1c,
};  // 0x085AE4EC

void (*const PTR_ARRAY_085ae4f8[4])(unknown*, unknown*) = {
    FUN_081eeed8,
    FUN_081eef2c,
    FUN_081ef3fc,
    FUN_081ef5ec,
};  // 0x085AE4F8

const u8 u8_ARRAY_085ae508[4] = {0x08, 0x04, 0x02, 0x01};  // 0x085AE508

void (*const PTR_ARRAY_085ae50c[3])(unknown*, unknown*) = {
    FUN_081efb94,
    FUN_081efd78,
    FUN_081efc20,
};  // 0x085AE50C

void (*const PTR_ARRAY_085ae518[4])(unknown*, unknown*) = {
    FUN_081f03a0,
    FUN_081f0678,
    FUN_081f03a4,
    FUN_081f0604,
};  // 0x085AE518

void (*const PTR_ARRAY_085ae528[4])(unknown*, unknown*) = {
    FUN_081f0be8,
    FUN_081f0c3c,
    FUN_081f12cc,
    FUN_081f1428,
};  // 0x085AE528

void (*const PTR_ARRAY_085ae538[4])(unknown*, unknown*) = {
    FUN_081f1940,
    FUN_081f1994,
    FUN_081f1cc8,
    FUN_081f1ffc,
};  // 0x085AE538

const u8 u8_ARRAY_085ae548[4] = {0x08, 0x04, 0x02, 0x01};  // 0x085AE548

void (*const PTR_ARRAY_085ae54c[5])(unknown*, unknown*) = {
    FUN_081f27d0,
    FUN_081f2af8,
    FUN_081f2e68,
    FUN_081f29b4,
    FUN_081f28c0,
};  // 0x085AE54C

void (*const PTR_ARRAY_085ae560[6])(unknown*, unknown*) = {
    FUN_081f3394,
    FUN_081f3508,
    FUN_081f3aa0,
    FUN_081f3e64,
    FUN_081f4010,
    FUN_081f3398,
};  // 0x085AE560

void (*const PTR_ARRAY_085ae578[4])(unknown*, unknown*) = {
    FUN_081f48ac,
    FUN_081f4af4,
    FUN_081f4d80,
    FUN_081f48b0,
};  // 0x085AE578

void (*const PTR_ARRAY_085ae588[7])(unknown*, unknown*) = {
    FUN_081f6314,
    FUN_081f6d14,
    FUN_081f710c,
    FUN_081f6afc,
    FUN_081f6c78,
    FUN_081f6368,
    FUN_081f6318,
};  // 0x085AE588

void (*const PTR_ARRAY_085ae5a4[4])(unknown*, unknown*) = {
    FUN_081f74f0,
    FUN_081f74f4,
    FUN_081f75f0,
    FUN_081f7624,
};  // 0x085AE5A4

void (*const PTR_ARRAY_085ae5b4[3])(unknown*, unknown*) = {
    FUN_081f7a14,
    FUN_081f7a18,
    FUN_081f7b5c,
};  // 0x085AE5B4

void (*const PTR_ARRAY_085ae5c0[4])(unknown*, unknown*) = {
    FUN_081f8120,
    FUN_081f8124,
    FUN_081f82cc,
    FUN_081f8620,
};  // 0x085AE5C0

void (*const PTR_ARRAY_085ae5d0[4])(unknown*, unknown*) = {
    FUN_081f8d0c,
    FUN_081f8d10,
    FUN_081f8eb0,
    FUN_081f90e0,
};  // 0x085AE5D0

void (*const PTR_ARRAY_085ae5e0[4])(unknown*, unknown*) = {
    FUN_081f9924,
    FUN_081f9928,
    FUN_081f9980,
    FUN_081f9adc,
};  // 0x085AE5E0

void (*const PTR_ARRAY_085ae5f0[3])(unknown*, unknown*) = {
    FUN_081f9dfc,
    FUN_081f9e94,
    FUN_081f9ee8,
};  // 0x085AE5F0

// ---------------- boss/dvalinn.c -----------------

struct Dvalinn;

void FUN_081fb2d4(struct Dvalinn* p);
void FUN_081fb518(struct Dvalinn* p);
void FUN_081fb664(struct Dvalinn* p);
void FUN_081fbb08(struct Dvalinn* p);
void FUN_081fc0a0(struct Dvalinn* p);
void FUN_081fc1e4(struct Dvalinn* p);
void FUN_081fc294(struct Dvalinn* p);
void FUN_081fc298(struct Dvalinn* p);
void FUN_081fc394(struct Dvalinn* p);
void FUN_081fc5b8(struct Dvalinn* p);
void FUN_081fc5d4(struct Dvalinn* p);
void FUN_081fc600(struct Dvalinn* p);
void FUN_081fc62c(struct Dvalinn* p);
void FUN_081fc658(struct Dvalinn* p);
void FUN_081fc69c(struct Dvalinn* p);
void FUN_081fc6e0(struct Dvalinn* p);
void FUN_081fc724(struct Dvalinn* p);
void FUN_081fc790(struct Dvalinn* p);
void FUN_081fc808(struct Dvalinn* p);
void FUN_081fc834(struct Dvalinn* p);
void FUN_081fc850(struct Dvalinn* p);
void FUN_081fca00(struct Dvalinn* p);
void FUN_081fcb1c(struct Dvalinn* p);
void FUN_081fcf54(struct Dvalinn* p);
void FUN_081fcfb4(struct Dvalinn* p);
void FUN_081fd000(struct Dvalinn* p);
void FUN_081fd20c(struct Dvalinn* p);
void FUN_081fd7fc(struct Dvalinn* p);
void FUN_081fdd18(struct Dvalinn* p);
void FUN_081fe2e0(struct Dvalinn* p);
void FUN_081fea80(struct Dvalinn* p);
void FUN_081febb8(struct Dvalinn* p);
void FUN_081febe4(struct Dvalinn* p);
void FUN_081fec60(struct Dvalinn* p);
void FUN_081fed08(struct Dvalinn* p);
void FUN_081fef30(struct Dvalinn* p);
void FUN_081ff148(struct Dvalinn* p);
void FUN_081ff34c(struct Dvalinn* p);
void FUN_081ff5cc(struct Dvalinn* p);
void FUN_081ff658(struct Dvalinn* p);

const u16 u16_ARRAY_085ae5fc[8] = {1536, 1536, 1536, 2304, 2304, 2304, 2304, 1536};  // 0x085AE5FC

// Dvalinn + 0xA6 で引く (FUN_081fc394)
void (*const PTR_ARRAY_085ae60c[8])(struct Dvalinn*) = {
    FUN_081fb2d4,
    FUN_081fb518,
    FUN_081fb664,
    FUN_081fbb08,
    FUN_081fc0a0,
    FUN_081fc1e4,
    FUN_081fc294,
    FUN_081fc298,
};  // 0x085AE60C

// Dvalinn + 0xA5 で引く (FUN_081fc5b8)
void (*const PTR_ARRAY_085ae62c[1])(struct Dvalinn*) = {
    FUN_081fc394,
};  // 0x085AE62C

// Dvalinn + 0xA6 で引く (FUN_081fc834)
void (*const PTR_ARRAY_085ae630[9])(struct Dvalinn*) = {
    FUN_081fc5d4,
    FUN_081fc600,
    FUN_081fc62c,
    FUN_081fc658,
    FUN_081fc69c,
    FUN_081fc6e0,
    FUN_081fc724,
    FUN_081fc790,
    FUN_081fc808,
};  // 0x085AE630

// Dvalinn + 0xA5 で引く (FUN_081fc850)
void (*const PTR_ARRAY_085ae654[1])(struct Dvalinn*) = {
    FUN_081fc834,
};  // 0x085AE654

// Dvalinn + 0xA4 で引く (FUN_081fc86c)
void (*const PTR_ARRAY_085ae658[2])(struct Dvalinn*) = {
    FUN_081fc5b8,
    FUN_081fc850,
};  // 0x085AE658

// 推測: {u32, s16, s16} の33組
// clang-format off
const u8 u8_ARRAY_085ae660[264] = {
    0x02, 0x00, 0x00, 0x00, 0xFD, 0xFF, 0x13, 0x00, 0x03, 0x00, 0x00, 0x00, 0xFA, 0xFF, 0x10, 0x00,
    0x04, 0x00, 0x00, 0x00, 0xF2, 0xFF, 0x04, 0x00, 0x06, 0x00, 0x00, 0x00, 0xF2, 0xFF, 0xEC, 0xFF,
    0x06, 0x00, 0x00, 0x00, 0xFA, 0xFF, 0xCC, 0xFF, 0x04, 0x00, 0x00, 0x00, 0xFC, 0xFF, 0xBA, 0xFF,
    0x04, 0x00, 0x00, 0x00, 0x01, 0x00, 0xBA, 0xFF, 0x04, 0x00, 0x00, 0x00, 0x07, 0x00, 0xBA, 0xFF,
    0x04, 0x00, 0x00, 0x00, 0x0C, 0x00, 0xBE, 0xFF, 0x04, 0x00, 0x00, 0x00, 0x14, 0x00, 0xB5, 0xFF,
    0x04, 0x00, 0x00, 0x00, 0x1D, 0x00, 0xCB, 0xFF, 0x04, 0x00, 0x00, 0x00, 0x21, 0x00, 0xD0, 0xFF,
    0x04, 0x00, 0x00, 0x00, 0x21, 0x00, 0xD8, 0xFF, 0x04, 0x00, 0x00, 0x00, 0x1F, 0x00, 0xDD, 0xFF,
    0x04, 0x00, 0x00, 0x00, 0x13, 0x00, 0xDF, 0xFF, 0x04, 0x00, 0x00, 0x00, 0x08, 0x00, 0xDC, 0xFF,
    0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0xDA, 0xFF, 0x04, 0x00, 0x00, 0x00, 0xF6, 0xFF, 0xD6, 0xFF,
    0x04, 0x00, 0x00, 0x00, 0xF3, 0xFF, 0xD1, 0xFF, 0x04, 0x00, 0x00, 0x00, 0xEE, 0xFF, 0xCB, 0xFF,
    0x04, 0x00, 0x00, 0x00, 0xF3, 0xFF, 0xC0, 0xFF, 0x02, 0x00, 0x00, 0x00, 0x2A, 0x00, 0x15, 0x00,
    0x01, 0x00, 0x00, 0x00, 0x22, 0x00, 0x29, 0x00, 0x01, 0x00, 0x00, 0x00, 0x12, 0x00, 0x31, 0x00,
    0x01, 0x00, 0x00, 0x00, 0x06, 0x00, 0x2D, 0x00, 0x01, 0x00, 0x00, 0x00, 0xFA, 0xFF, 0x29, 0x00,
    0x01, 0x00, 0x00, 0x00, 0xF2, 0xFF, 0x1C, 0x00, 0x02, 0x00, 0x00, 0x00, 0xEC, 0xFF, 0x0C, 0x00,
    0x02, 0x00, 0x00, 0x00, 0xE5, 0xFF, 0xF9, 0xFF, 0x02, 0x00, 0x00, 0x00, 0xE2, 0xFF, 0xE5, 0xFF,
    0x02, 0x00, 0x00, 0x00, 0xE2, 0xFF, 0xD5, 0xFF, 0x02, 0x00, 0x00, 0x00, 0xEE, 0xFF, 0xC6, 0xFF,
    0x02, 0x00, 0x00, 0x00, 0xF8, 0xFF, 0xC1, 0xFF,
};  // 0x085AE660
// clang-format on

// FUN_081ff740 が Dvalinn + 0xA2 で引いて 0xF8 のフィールドに入れる
// clang-format off
void (*const PTR_ARRAY_085ae768[20])(struct Dvalinn*) = {
    NULL,
    FUN_081fcb1c,
    FUN_081fca00,
    FUN_081fcf54,
    FUN_081fcfb4,
    FUN_081fd000,
    FUN_081fd20c,
    FUN_081fd7fc,
    FUN_081fdd18,
    FUN_081fe2e0,
    FUN_081fea80,
    FUN_081febb8,
    FUN_081febe4,
    FUN_081fec60,
    FUN_081fed08,
    FUN_081fef30,
    FUN_081ff148,
    FUN_081ff34c,
    FUN_081ff5cc,
    FUN_081ff658,
};  // 0x085AE768
// clang-format on

// ---------------- entity_08202cd8.c -----------------

const u16 u16_ARRAY_085ae7b8[8] = {64, 64, 64, 64, 64, 128, 128, 128};  // 0x085AE7B8

const u16 u16_ARRAY_085ae7c8[8] = {4096, 4096, 4096, 4096, 4096, 16384, 16384, 16384};  // 0x085AE7C8

const s32 s32_ARRAY_085ae7d8[8] = {-100, -60, -40, -30, -20, 10, 45, 0};  // 0x085AE7D8

void FUN_082010f8(unknown* p);
void FUN_082013d4(unknown* p);
void FUN_082017cc(unknown* p);
void FUN_08201f74(unknown* p);
void FUN_08202140(unknown* p);
void FUN_082024e8(unknown* p);
void FUN_0820287c(unknown* p);

// FUN_082028b8 が 0x6DB で引いて 0x6D4 のフィールドに入れる
void (*const PTR_ARRAY_085ae7f8[8])(unknown*) = {
    NULL,
    FUN_082010f8,
    FUN_082013d4,
    FUN_082017cc,
    FUN_08202140,
    FUN_08201f74,
    FUN_082024e8,
    FUN_0820287c,
};  // 0x085AE7F8

// ---------------- entity_082034c0.c -----------------

void FUN_08203034(unknown*, unknown*);
void FUN_082032a0(unknown*, unknown*);
void FUN_082032dc(unknown*, unknown*);

// Entity082034c0_Update が (p, item) で呼ぶ
void (*const PTR_ARRAY_085ae818[3])(unknown*, unknown*) = {
    FUN_08203034,
    FUN_082032a0,
    FUN_082032dc,
};  // 0x085AE818

// ---------------- entity_082047f0.c -----------------

unknown* FUN_08203d40(unknown*, unknown*, unknown*);
unknown* FUN_08203d44(unknown*, unknown*, unknown*);
unknown* FUN_082040d0(unknown*, unknown*, unknown*);
unknown* FUN_08204390(unknown*, unknown*, unknown*);

// Entity082047f0_Update が引数3つで呼んで戻り値を使う
unknown* (*const PTR_ARRAY_085ae824[4])(unknown*, unknown*, unknown*) = {
    FUN_08203d40,
    FUN_08203d44,
    FUN_082040d0,
    FUN_08204390,
};  // 0x085AE824

// ---------------- entity_08204cb8.c -----------------

void FUN_0820492c(unknown*, unknown*);
void FUN_08204a64(unknown*, unknown*);

// Entity08204cb8_Update が (p, item) で呼ぶ
void (*const PTR_ARRAY_085ae834[2])(unknown*, unknown*) = {
    FUN_0820492c,
    FUN_08204a64,
};  // 0x085AE834

// ---------------- code_08204d2c.s -----------------

struct Entity286F;
struct Entity286FNode;

void FUN_08042178(struct Entity286F* p, struct Entity286FNode* node);
void FUN_080421bc(struct Entity286F* p, struct Entity286FNode* node);
void FUN_08042200(struct Entity286F* p, struct Entity286FNode* node);
void FUN_0804234c(struct Entity286F* p, struct Entity286FNode* node);
void FUN_08042868(struct Entity286F* p, struct Entity286FNode* node);
void FUN_080428b8(struct Entity286F* p, struct Entity286FNode* node);
void FUN_08042a48(struct Entity286F* p, struct Entity286FNode* node);
void FUN_08042d50(struct Entity286F* p, struct Entity286FNode* node);
void FUN_08042f34(struct Entity286F* p, struct Entity286FNode* node);
void FUN_08043108(struct Entity286F* p, struct Entity286FNode* node);
void FUN_08043360(struct Entity286F* p, struct Entity286FNode* node);
void FUN_0804355c(struct Entity286F* p, struct Entity286FNode* node);
void FUN_08043588(struct Entity286F* p, struct Entity286FNode* node);
void FUN_080435b4(struct Entity286F* p, struct Entity286FNode* node);
void FUN_080435f0(struct Entity286F* p, struct Entity286FNode* node);
void FUN_0804364c(struct Entity286F* p, struct Entity286FNode* node);
void FUN_08043688(struct Entity286F* p, struct Entity286FNode* node);
void FUN_080436c4(struct Entity286F* p, struct Entity286FNode* node);
void FUN_08043774(struct Entity286F* p, struct Entity286FNode* node);
void FUN_08043960(struct Entity286F* p, struct Entity286FNode* node);
void FUN_08043a24(struct Entity286F* p, struct Entity286FNode* node);
void FUN_08043bcc(struct Entity286F* p, struct Entity286FNode* node);
void FUN_08043c94(struct Entity286F* p, struct Entity286FNode* node);
void FUN_08043cc4(struct Entity286F* p, struct Entity286FNode* node);
void FUN_08043cf4(struct Entity286F* p, struct Entity286FNode* node);
void FUN_08043da8(struct Entity286F* p, struct Entity286FNode* node);
void FUN_08043e54(struct Entity286F* p, struct Entity286FNode* node);
void FUN_08204d2c(struct Entity286F* p, struct Entity286FNode* node);
void FUN_08204d60(struct Entity286F* p, struct Entity286FNode* node);
void FUN_08204d94(struct Entity286F* p, struct Entity286FNode* node);
void FUN_08204dd8(struct Entity286F* p, struct Entity286FNode* node);
void FUN_08204e0c(struct Entity286F* p, struct Entity286FNode* node);
void FUN_08204e64(struct Entity286F* p, struct Entity286FNode* node);
void FUN_08204f94(struct Entity286F* p, struct Entity286FNode* node);
void FUN_08205018(struct Entity286F* p, struct Entity286FNode* node);
void FUN_082050fc(struct Entity286F* p, struct Entity286FNode* node);
void FUN_08205178(struct Entity286F* p, struct Entity286FNode* node);
void FUN_08205438(struct Entity286F* p, struct Entity286FNode* node);
void FUN_0820556c(struct Entity286F* p, struct Entity286FNode* node);
void FUN_08205efc(struct Entity286F* p, struct Entity286FNode* node);
void FUN_08205f38(struct Entity286F* p, struct Entity286FNode* node);
void FUN_08205f74(struct Entity286F* p, struct Entity286FNode* node);
void FUN_08205fe0(struct Entity286F* p, struct Entity286FNode* node);
void FUN_0820602c(struct Entity286F* p, struct Entity286FNode* node);
void FUN_08206084(struct Entity286F* p, struct Entity286FNode* node);
void FUN_082066c8(struct Entity286F* p, struct Entity286FNode* node);
void FUN_082066f0(struct Entity286F* p, struct Entity286FNode* node);
void FUN_08206718(struct Entity286F* p, struct Entity286FNode* node);
void FUN_0820673c(struct Entity286F* p, struct Entity286FNode* node);
void FUN_08206764(struct Entity286F* p, struct Entity286FNode* node);
void FUN_0820678c(struct Entity286F* p, struct Entity286FNode* node);
void FUN_082067c0(struct Entity286F* p, struct Entity286FNode* node);
void FUN_082068c8(struct Entity286F* p, struct Entity286FNode* node);
void FUN_08206918(struct Entity286F* p, struct Entity286FNode* node);
void FUN_08206968(struct Entity286F* p, struct Entity286FNode* node);
void FUN_082069b8(struct Entity286F* p, struct Entity286FNode* node);
void FUN_08206a08(struct Entity286F* p, struct Entity286FNode* node);
void FUN_08206a7c(struct Entity286F* p, struct Entity286FNode* node);
void FUN_08206ad4(struct Entity286F* p, struct Entity286FNode* node);
void FUN_08207120(struct Entity286F* p, struct Entity286FNode* node);
void FUN_08207170(struct Entity286F* p, struct Entity286FNode* node);
void FUN_082071c0(struct Entity286F* p, struct Entity286FNode* node);
void FUN_08207210(struct Entity286F* p, struct Entity286FNode* node);
void FUN_08207298(struct Entity286F* p, struct Entity286FNode* node);
void FUN_082072f0(struct Entity286F* p, struct Entity286FNode* node);
void FUN_0820738c(struct Entity286F* p, struct Entity286FNode* node);
void FUN_0820744c(struct Entity286F* p, struct Entity286FNode* node);
void FUN_08207474(struct Entity286F* p, struct Entity286FNode* node);
void FUN_082074a8(struct Entity286F* p, struct Entity286FNode* node);
void FUN_082074d0(struct Entity286F* p, struct Entity286FNode* node);
void FUN_082074f8(struct Entity286F* p, struct Entity286FNode* node);
void FUN_0820752c(struct Entity286F* p, struct Entity286FNode* node);
void FUN_08207550(struct Entity286F* p, struct Entity286FNode* node);
void FUN_08207ac4(struct Entity286F* p, struct Entity286FNode* node);
void FUN_08207af0(struct Entity286F* p, struct Entity286FNode* node);
void FUN_08207b1c(struct Entity286F* p, struct Entity286FNode* node);
void FUN_08207b78(struct Entity286F* p, struct Entity286FNode* node);
void FUN_08207bbc(struct Entity286F* p, struct Entity286FNode* node);
void FUN_08207c00(struct Entity286F* p, struct Entity286FNode* node);
void FUN_08208160(struct Entity286F* p, struct Entity286FNode* node);
void FUN_08208194(struct Entity286F* p, struct Entity286FNode* node);
void FUN_082081c0(struct Entity286F* p, struct Entity286FNode* node);
void FUN_082081ec(struct Entity286F* p, struct Entity286FNode* node);
void FUN_08208214(struct Entity286F* p, struct Entity286FNode* node);
void FUN_08208240(struct Entity286F* p, struct Entity286FNode* node);
void FUN_08208274(struct Entity286F* p, struct Entity286FNode* node);
void FUN_0820829c(struct Entity286F* p, struct Entity286FNode* node);
void FUN_082082c0(struct Entity286F* p, struct Entity286FNode* node);
void FUN_082082f4(struct Entity286F* p, struct Entity286FNode* node);
void FUN_0820848c(struct Entity286F* p, struct Entity286FNode* node);
void FUN_082084ec(struct Entity286F* p, struct Entity286FNode* node);
void FUN_08208628(struct Entity286F* p, struct Entity286FNode* node);
void FUN_082086d8(struct Entity286F* p, struct Entity286FNode* node);
void FUN_08208808(struct Entity286F* p, struct Entity286FNode* node);
void FUN_08208858(struct Entity286F* p, struct Entity286FNode* node);
void FUN_082088a8(struct Entity286F* p, struct Entity286FNode* node);
void FUN_082088f8(struct Entity286F* p, struct Entity286FNode* node);
void FUN_08208990(struct Entity286F* p, struct Entity286FNode* node);
void FUN_08208b50(struct Entity286F* p, struct Entity286FNode* node);
void FUN_08208c64(struct Entity286F* p, struct Entity286FNode* node);
void FUN_08208ce8(struct Entity286F* p, struct Entity286FNode* node);
void FUN_08208e18(struct Entity286F* p, struct Entity286FNode* node);
void FUN_08208ec8(struct Entity286F* p, struct Entity286FNode* node);
void FUN_08209838(struct Entity286F* p, struct Entity286FNode* node);
void FUN_0820abc8(struct Entity286F* p, struct Entity286FNode* node);
void FUN_0820abec(struct Entity286F* p, struct Entity286FNode* node);
void FUN_0820ac10(struct Entity286F* p, struct Entity286FNode* node);
void FUN_0820ac44(struct Entity286F* p, struct Entity286FNode* node);
void FUN_0820acb0(struct Entity286F* p, struct Entity286FNode* node);
void FUN_0820afb0(struct Entity286F* p, struct Entity286FNode* node);
void FUN_0820aff0(struct Entity286F* p, struct Entity286FNode* node);
void FUN_0820b5c4(struct Entity286F* p, struct Entity286FNode* node);
void FUN_0820b5f8(struct Entity286F* p, struct Entity286FNode* node);
void FUN_0820b62c(struct Entity286F* p, struct Entity286FNode* node);
void FUN_0820b650(struct Entity286F* p, struct Entity286FNode* node);
void FUN_0820b678(struct Entity286F* p, struct Entity286FNode* node);
void FUN_0820b6e4(struct Entity286F* p, struct Entity286FNode* node);
void FUN_0820b7c4(struct Entity286F* p, struct Entity286FNode* node);
void FUN_0820b8a0(struct Entity286F* p, struct Entity286FNode* node);
void FUN_0820b934(struct Entity286F* p, struct Entity286FNode* node);
void FUN_0820b9e8(struct Entity286F* p, struct Entity286FNode* node);
void FUN_0820bf5c(struct Entity286F* p, struct Entity286FNode* node);
void FUN_0820bfb8(struct Entity286F* p, struct Entity286FNode* node);
void FUN_0820c054(struct Entity286F* p, struct Entity286FNode* node);
void FUN_0820c6c8(struct Entity286F* p, struct Entity286FNode* node);

void FUN_08042414(struct Entity286F* p, struct Entity286FNode* node, s32 param_3);
void FUN_08042638(struct Entity286F* p, struct Entity286FNode* node, s32 param_3);
void FUN_08042cf0(struct Entity286F* p, struct Entity286FNode* node, s32 param_3);

// clang-format off
void (*const PTR_ARRAY_085ae83c[21])(struct Entity286F*, struct Entity286FNode*) = {
    FUN_0804355c,
    FUN_08043588,
    FUN_080435b4,
    FUN_080435f0,
    FUN_0804364c,
    FUN_08043688,
    FUN_080436c4,
    FUN_08043774,
    FUN_08043960,
    FUN_08043a24,
    FUN_08043bcc,
    FUN_08043c94,
    FUN_08043cc4,
    FUN_08043cf4,
    FUN_08043da8,
    FUN_08043e54,
    FUN_08204d2c,
    FUN_08204d60,
    FUN_08204d94,
    FUN_08204dd8,
    FUN_08204e0c,
};  // 0x085AE83C
// clang-format on

// clang-format off
void (*const PTR_ARRAY_085ae890[19])(struct Entity286F*, struct Entity286FNode*) = {
    NULL,
    FUN_08042178,
    FUN_080421bc,
    FUN_08204e64,
    FUN_08204f94,
    (void*)FUN_08042414,
    (void*)FUN_08042638,
    FUN_08042868,
    FUN_080428b8,
    FUN_08042a48,
    (void*)FUN_08042cf0,
    FUN_08042d50,
    FUN_08042f34,
    FUN_08043108,
    FUN_08205018,
    FUN_082050fc,
    FUN_08205178,
    FUN_08205438,
    FUN_0820556c,
};  // 0x085AE890
// clang-format on

// clang-format off
void (*const PTR_ARRAY_085ae8dc[19])(struct Entity286F*, struct Entity286FNode*) = {
    FUN_0804355c,
    FUN_08043588,
    FUN_080435b4,
    FUN_080435f0,
    FUN_0804364c,
    FUN_08043688,
    FUN_080436c4,
    FUN_08043774,
    FUN_08043960,
    FUN_08043a24,
    FUN_08043bcc,
    FUN_08043c94,
    FUN_08043cc4,
    FUN_08043cf4,
    FUN_08043da8,
    FUN_08043e54,
    FUN_08205efc,
    FUN_08205f38,
    FUN_08205f74,
};  // 0x085AE8DC
// clang-format on

void (*const PTR_ARRAY_085ae928[17])(struct Entity286F*, struct Entity286FNode*) = {
    NULL,
    FUN_08042178,
    FUN_080421bc,
    FUN_08042200,
    FUN_0804234c,
    (void*)FUN_08042414,
    (void*)FUN_08042638,
    FUN_08042868,
    FUN_080428b8,
    FUN_08042a48,
    (void*)FUN_08042cf0,
    FUN_08042d50,
    FUN_08042f34,
    FUN_08043108,
    FUN_08205fe0,
    FUN_0820602c,
    FUN_08206084,
};  // 0x085AE928

// clang-format off
void (*const PTR_ARRAY_085ae96c[23])(struct Entity286F*, struct Entity286FNode*) = {
    FUN_0804355c,
    FUN_08043588,
    FUN_080435b4,
    FUN_080435f0,
    FUN_0804364c,
    FUN_08043688,
    FUN_080436c4,
    FUN_08043774,
    FUN_08043960,
    FUN_08043a24,
    FUN_08043bcc,
    FUN_08043c94,
    FUN_08043cc4,
    FUN_08043cf4,
    FUN_08043da8,
    FUN_08043e54,
    FUN_082066c8,
    FUN_082066f0,
    FUN_08206718,
    FUN_0820673c,
    FUN_08206764,
    FUN_0820678c,
    FUN_082067c0,
};  // 0x085AE96C
// clang-format on

// clang-format off
void (*const PTR_ARRAY_085ae9c8[21])(struct Entity286F*, struct Entity286FNode*) = {
    NULL,
    FUN_08042178,
    FUN_080421bc,
    FUN_08042200,
    FUN_0804234c,
    (void*)FUN_08042414,
    (void*)FUN_08042638,
    FUN_08042868,
    FUN_080428b8,
    FUN_08042a48,
    (void*)FUN_08042cf0,
    FUN_08042d50,
    FUN_08042f34,
    FUN_08043108,
    FUN_082068c8,
    FUN_08206918,
    FUN_08206968,
    FUN_08206ad4,
    FUN_082069b8,
    FUN_08206a08,
    FUN_08206a7c,
};  // 0x085AE9C8
// clang-format on

// clang-format off
void (*const PTR_ARRAY_085aea1c[21])(struct Entity286F*, struct Entity286FNode*) = {
    NULL,
    FUN_08042178,
    FUN_080421bc,
    FUN_08042200,
    FUN_0804234c,
    (void*)FUN_08042414,
    (void*)FUN_08042638,
    FUN_08042868,
    FUN_080428b8,
    FUN_08042a48,
    (void*)FUN_08042cf0,
    FUN_08042d50,
    FUN_08042f34,
    FUN_08043108,
    FUN_08207120,
    FUN_08207170,
    FUN_082071c0,
    FUN_08207210,
    FUN_08207298,
    FUN_082072f0,
    FUN_0820738c,
};  // 0x085AEA1C
// clang-format on

// clang-format off
void (*const PTR_ARRAY_085aea70[23])(struct Entity286F*, struct Entity286FNode*) = {
    FUN_0804355c,
    FUN_08043588,
    FUN_080435b4,
    FUN_080435f0,
    FUN_0804364c,
    FUN_08043688,
    FUN_080436c4,
    FUN_08043774,
    FUN_08043960,
    FUN_08043a24,
    FUN_08043bcc,
    FUN_08043c94,
    FUN_08043cc4,
    FUN_08043cf4,
    FUN_08043da8,
    FUN_08043e54,
    FUN_0820744c,
    FUN_08207474,
    FUN_082074a8,
    FUN_082074d0,
    FUN_082074f8,
    FUN_0820752c,
    FUN_08207550,
};  // 0x085AEA70
// clang-format on

// clang-format off
void (*const PTR_ARRAY_085aeacc[19])(struct Entity286F*, struct Entity286FNode*) = {
    FUN_0804355c,
    FUN_08043588,
    FUN_080435b4,
    FUN_080435f0,
    FUN_0804364c,
    FUN_08043688,
    FUN_080436c4,
    FUN_08043774,
    FUN_08043960,
    FUN_08043a24,
    FUN_08043bcc,
    FUN_08043c94,
    FUN_08043cc4,
    FUN_08043cf4,
    FUN_08043da8,
    FUN_08043e54,
    FUN_08207ac4,
    FUN_08207af0,
    FUN_08207b1c,
};  // 0x085AEACC
// clang-format on

void (*const PTR_ARRAY_085aeb18[17])(struct Entity286F*, struct Entity286FNode*) = {
    NULL,
    FUN_08042178,
    FUN_080421bc,
    FUN_08042200,
    FUN_0804234c,
    (void*)FUN_08042414,
    (void*)FUN_08042638,
    FUN_08042868,
    FUN_080428b8,
    FUN_08042a48,
    (void*)FUN_08042cf0,
    FUN_08042d50,
    FUN_08042f34,
    FUN_08043108,
    FUN_08207b78,
    FUN_08207bbc,
    FUN_08207c00,
};  // 0x085AEB18

// clang-format off
void (*const PTR_ARRAY_085aeb5c[26])(struct Entity286F*, struct Entity286FNode*) = {
    FUN_0804355c,
    FUN_08043588,
    FUN_080435b4,
    FUN_080435f0,
    FUN_0804364c,
    FUN_08043688,
    FUN_080436c4,
    FUN_08043774,
    FUN_08043960,
    FUN_08043a24,
    FUN_08043bcc,
    FUN_08043c94,
    FUN_08043cc4,
    FUN_08043cf4,
    FUN_08043da8,
    FUN_08043e54,
    FUN_08208160,
    FUN_08208194,
    FUN_082081c0,
    FUN_082081ec,
    FUN_08208214,
    FUN_08208240,
    FUN_08208274,
    FUN_0820829c,
    FUN_082082c0,
    FUN_082082f4,
};  // 0x085AEB5C
// clang-format on

// clang-format off
void (*const PTR_ARRAY_085aebc4[24])(struct Entity286F*, struct Entity286FNode*) = {
    NULL,
    FUN_08042178,
    FUN_0820848c,
    FUN_082084ec,
    FUN_08208628,
    (void*)FUN_08042414,
    (void*)FUN_08042638,
    FUN_08042868,
    FUN_080428b8,
    FUN_08208ec8,
    (void*)FUN_08042cf0,
    FUN_08042d50,
    FUN_08042f34,
    FUN_08043108,
    FUN_082086d8,
    FUN_08208808,
    FUN_08208858,
    FUN_082088a8,
    FUN_082088f8,
    FUN_08208990,
    FUN_08208b50,
    FUN_08208c64,
    FUN_08208ce8,
    FUN_08208e18,
};  // 0x085AEBC4
// clang-format on

void (*const PTR_ARRAY_085aec24[17])(struct Entity286F*, struct Entity286FNode*) = {
    FUN_0804355c,
    FUN_08043588,
    FUN_080435b4,
    FUN_080435f0,
    FUN_0804364c,
    FUN_08043688,
    FUN_080436c4,
    FUN_08043774,
    FUN_08043960,
    FUN_08043a24,
    FUN_08043bcc,
    FUN_08043c94,
    FUN_08043cc4,
    FUN_08043cf4,
    FUN_08043da8,
    FUN_08043e54,
    FUN_08209838,
};  // 0x085AEC24

void (*const PTR_ARRAY_085aec68[15])(struct Entity286F*, struct Entity286FNode*) = {
    NULL,
    FUN_08042178,
    FUN_080421bc,
    FUN_08042200,
    FUN_0804234c,
    (void*)FUN_08042414,
    (void*)FUN_08042638,
    FUN_08042868,
    FUN_080428b8,
    FUN_08042a48,
    (void*)FUN_08042cf0,
    FUN_08042d50,
    FUN_08042f34,
    FUN_08043108,
    FUN_08043360,
};  // 0x085AEC68

void (*const PTR_ARRAY_085aeca4[16])(struct Entity286F*, struct Entity286FNode*) = {
    FUN_0804355c,
    FUN_08043588,
    FUN_080435b4,
    FUN_080435f0,
    FUN_0804364c,
    FUN_08043688,
    FUN_080436c4,
    FUN_08043774,
    FUN_08043960,
    FUN_08043a24,
    FUN_08043bcc,
    FUN_08043c94,
    FUN_08043cc4,
    FUN_08043cf4,
    FUN_08043da8,
    FUN_08043e54,
};  // 0x085AECA4

void (*const PTR_ARRAY_085aece4[14])(struct Entity286F*, struct Entity286FNode*) = {
    NULL,
    FUN_08042178,
    FUN_080421bc,
    FUN_08042200,
    FUN_0804234c,
    (void*)FUN_08042414,
    (void*)FUN_08042638,
    FUN_08042868,
    FUN_080428b8,
    FUN_08042a48,
    (void*)FUN_08042cf0,
    FUN_08042d50,
    FUN_08042f34,
    FUN_08043108,
};  // 0x085AECE4

void (*const PTR_ARRAY_085aed1c[16])(struct Entity286F*, struct Entity286FNode*) = {
    FUN_0804355c,
    FUN_08043588,
    FUN_080435b4,
    FUN_080435f0,
    FUN_0804364c,
    FUN_08043688,
    FUN_080436c4,
    FUN_08043774,
    FUN_08043960,
    FUN_08043a24,
    FUN_08043bcc,
    FUN_08043c94,
    FUN_08043cc4,
    FUN_08043cf4,
    FUN_08043da8,
    FUN_08043e54,
};  // 0x085AED1C

void (*const PTR_ARRAY_085aed5c[14])(struct Entity286F*, struct Entity286FNode*) = {
    NULL,
    FUN_08042178,
    FUN_080421bc,
    FUN_08042200,
    FUN_0804234c,
    (void*)FUN_08042414,
    (void*)FUN_08042638,
    FUN_08042868,
    FUN_080428b8,
    FUN_08042a48,
    (void*)FUN_08042cf0,
    FUN_08042d50,
    FUN_08042f34,
    FUN_08043108,
};  // 0x085AED5C

void (*const PTR_ARRAY_085aed94[16])(struct Entity286F*, struct Entity286FNode*) = {
    FUN_0804355c,
    FUN_08043588,
    FUN_080435b4,
    FUN_080435f0,
    FUN_0804364c,
    FUN_08043688,
    FUN_080436c4,
    FUN_08043774,
    FUN_08043960,
    FUN_08043a24,
    FUN_08043bcc,
    FUN_08043c94,
    FUN_08043cc4,
    FUN_08043cf4,
    FUN_08043da8,
    FUN_08043e54,
};  // 0x085AED94

void (*const PTR_ARRAY_085aedd4[14])(struct Entity286F*, struct Entity286FNode*) = {
    NULL,
    FUN_08042178,
    FUN_080421bc,
    FUN_08042200,
    FUN_0804234c,
    (void*)FUN_08042414,
    (void*)FUN_08042638,
    FUN_08042868,
    FUN_080428b8,
    FUN_08042a48,
    (void*)FUN_08042cf0,
    FUN_08042d50,
    FUN_08042f34,
    FUN_08043108,
};  // 0x085AEDD4

// clang-format off
void (*const PTR_ARRAY_085aee0c[20])(struct Entity286F*, struct Entity286FNode*) = {
    FUN_0804355c,
    FUN_08043588,
    FUN_080435b4,
    FUN_080435f0,
    FUN_0804364c,
    FUN_08043688,
    FUN_080436c4,
    FUN_08043774,
    FUN_08043960,
    FUN_08043a24,
    FUN_08043bcc,
    FUN_08043c94,
    FUN_08043cc4,
    FUN_08043cf4,
    FUN_08043da8,
    FUN_08043e54,
    FUN_0820abc8,
    FUN_0820abec,
    FUN_0820ac10,
    FUN_0820ac44,
};  // 0x085AEE0C
// clang-format on

void (*const PTR_ARRAY_085aee5c[18])(struct Entity286F*, struct Entity286FNode*) = {
    NULL,
    FUN_08042178,
    FUN_080421bc,
    FUN_08042200,
    FUN_0804234c,
    (void*)FUN_08042414,
    (void*)FUN_08042638,
    FUN_08042868,
    FUN_080428b8,
    FUN_08042a48,
    (void*)FUN_08042cf0,
    FUN_08042d50,
    FUN_08042f34,
    FUN_08043108,
    FUN_0820acb0,
    FUN_0820afb0,
    FUN_0820aff0,
    FUN_08043360,
};  // 0x085AEE5C

// clang-format off
void (*const PTR_ARRAY_085aeea4[19])(struct Entity286F*, struct Entity286FNode*) = {
    FUN_0804355c,
    FUN_08043588,
    FUN_080435b4,
    FUN_080435f0,
    FUN_0820b5c4,
    FUN_0820b5f8,
    FUN_080436c4,
    FUN_08043774,
    FUN_08043960,
    FUN_08043a24,
    FUN_08043bcc,
    FUN_08043c94,
    FUN_08043cc4,
    FUN_08043cf4,
    FUN_08043da8,
    FUN_08043e54,
    FUN_0820b62c,
    FUN_0820b650,
    FUN_0820b678,
};  // 0x085AEEA4
// clang-format on

void (*const PTR_ARRAY_085aeef0[17])(struct Entity286F*, struct Entity286FNode*) = {
    NULL,
    FUN_08042178,
    FUN_080421bc,
    FUN_08042200,
    FUN_0804234c,
    FUN_0820b6e4,
    FUN_0820b7c4,
    FUN_08042868,
    FUN_080428b8,
    FUN_08042a48,
    (void*)FUN_08042cf0,
    FUN_08042d50,
    FUN_08042f34,
    FUN_08043108,
    FUN_0820b8a0,
    FUN_0820b934,
    FUN_0820b9e8,
};  // 0x085AEEF0

void (*const PTR_ARRAY_085aef34[17])(struct Entity286F*, struct Entity286FNode*) = {
    FUN_0804355c,
    FUN_08043588,
    FUN_080435b4,
    FUN_080435f0,
    FUN_0804364c,
    FUN_08043688,
    FUN_080436c4,
    FUN_08043774,
    FUN_08043960,
    FUN_08043a24,
    FUN_08043bcc,
    FUN_08043c94,
    FUN_08043cc4,
    FUN_08043cf4,
    FUN_08043da8,
    FUN_08043e54,
    FUN_0820bf5c,
};  // 0x085AEF34

void (*const PTR_ARRAY_085aef78[15])(struct Entity286F*, struct Entity286FNode*) = {
    NULL,
    FUN_08042178,
    FUN_0820bfb8,
    FUN_08042200,
    FUN_0804234c,
    (void*)FUN_08042414,
    (void*)FUN_08042638,
    FUN_08042868,
    FUN_080428b8,
    FUN_08042a48,
    (void*)FUN_08042cf0,
    FUN_08042d50,
    FUN_08042f34,
    FUN_08043108,
    FUN_0820c054,
};  // 0x085AEF78

void (*const PTR_ARRAY_085aefb4[15])(struct Entity286F*, struct Entity286FNode*) = {
    NULL,
    FUN_08042178,
    FUN_080421bc,
    FUN_08042200,
    FUN_0804234c,
    (void*)FUN_08042414,
    (void*)FUN_08042638,
    FUN_08042868,
    FUN_080428b8,
    FUN_08042a48,
    (void*)FUN_08042cf0,
    FUN_08042d50,
    FUN_08042f34,
    FUN_08043108,
    FUN_08043360,
};  // 0x085AEFB4

void (*const PTR_ARRAY_085aeff0[17])(struct Entity286F*, struct Entity286FNode*) = {
    FUN_0804355c,
    FUN_08043588,
    FUN_080435b4,
    FUN_080435f0,
    FUN_0804364c,
    FUN_08043688,
    FUN_080436c4,
    FUN_08043774,
    FUN_08043960,
    FUN_08043a24,
    FUN_08043bcc,
    FUN_08043c94,
    FUN_08043cc4,
    FUN_08043cf4,
    FUN_08043da8,
    FUN_08043e54,
    FUN_0820c6c8,
};  // 0x085AEFF0
