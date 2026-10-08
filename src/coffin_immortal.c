#include "coffin_immortal.h"

#include "entity.h"
#include "global.h"

void FUN_08084c58(unknown* p);
void FUN_08084c9c(unknown* p);
void FUN_08084ce8(unknown* p);
void FUN_08084d44(unknown* p);
void FUN_08084dc8(unknown* p);
void FUN_08084e54(unknown* p);
void FUN_08084ecc(unknown* p);
void FUN_08084f7c(unknown* p);

void (*const PTR_ARRAY_085abfc8[8])(unknown*) = {
    FUN_08084c58,
    FUN_08084c9c,
    FUN_08084ce8,
    FUN_08084d44,
    FUN_08084dc8,
    FUN_08084e54,
    FUN_08084ecc,
    FUN_08084f7c,
};  // 0x085abfc8

// --------------------------------------------

// ImmortalCoffin.weight, 棺桶の重さ, 運搬時のプレイヤーの移動速度に影響する
const u16 sCoffinWeights[8] = {
    [COFFIN_OAK] = 50,
    [COFFIN_BRONZE] = 70,
    [COFFIN_IRON] = 90,
    [COFFIN_SILVER] = 60,
    [COFFIN_SOLAR] = 80,
    [COFFIN_ELEFAN] = 90,
    [COFFIN_VAMPIRE] = 60,
    [COFFIN_IRON_MAIDEN] = 90,
};  // 0x085abfe8

// 棺桶の封印力, 高いほど棺桶が逃げにくくなる
const u8 sCoffinPowers[8] = {
    [COFFIN_OAK] = 10,
    [COFFIN_BRONZE] = 15,
    [COFFIN_IRON] = 20,
    [COFFIN_SILVER] = 25,
    [COFFIN_SOLAR] = 15,
    [COFFIN_ELEFAN] = 10,
    [COFFIN_VAMPIRE] = 10,
    [COFFIN_IRON_MAIDEN] = 30,
};  // 0x085abff8

// --------------------------------------------

void FUN_08087c04(ImmortalCoffin* p);
void FUN_08088148(ImmortalCoffin* p);
void FUN_0808890c(ImmortalCoffin* p);
void FUN_08088514(ImmortalCoffin* p);
void FUN_08088718(ImmortalCoffin* p);
void FUN_08088d44(ImmortalCoffin* p);
void FUN_08088fbc(ImmortalCoffin* p);
void FUN_08089088(ImmortalCoffin* p);
void FUN_08089144(ImmortalCoffin* p);
void FUN_08088bbc(ImmortalCoffin* p);
void FUN_08088c54(ImmortalCoffin* p);
void FUN_080892a8(ImmortalCoffin* p);
void FUN_08089344(ImmortalCoffin* p);
void FUN_080892f8(ImmortalCoffin* p);
void FUN_080893c0(ImmortalCoffin* p);
void FUN_08089548(ImmortalCoffin* p);
void FUN_08089720(ImmortalCoffin* p);

void (*const PTR_ARRAY_085ac000[17])(ImmortalCoffin*) = {
    FUN_08087c04,
    FUN_08088148,
    FUN_0808890c,
    FUN_08088514,
    FUN_08088718,
    FUN_08088d44,
    FUN_08088fbc,
    FUN_08089088,
    FUN_08089144,
    FUN_08088bbc,
    FUN_08088c54,
    FUN_080892a8,
    FUN_08089344,
    FUN_080892f8,
    FUN_080893c0,
    FUN_08089548,
    FUN_08089720,
};  // 0x085ac000

INCASM("asm/coffin_immortal.inc");
