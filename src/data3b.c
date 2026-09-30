#include "global.h"
#include "sprite.h"

const u16 u16_ARRAY_085aaff4[270] = {
    0x103, 0x0,   0x103, 0x5,   0x103, 0x0,   0x103, 0x5,   0x103, 0x19E, 0x103, 0x1A3, 0x103, 0x19E, 0x103, 0x1A3, 0x103, 0x0,   0x103, 0x1,   0x103, 0x0,   0x103, 0x1,   0x102, 0x0,   0x102, 0x6,   0x102, 0x1E,  0x102, 0x6,   0x2, 0x7,   0x2, 0x8,   0x2, 0x9,   0x2, 0x8,   0x3, 0x0,   0x3, 0x0,   0x3,  0x0,   0x3,  0x0,   0x0,  0x1,   0x0,  0xA,   0x0,  0x3,   0x0,  0x13,  0x0,  0x0,   0x103, 0x0,   0x102, 0x5,   0x103, 0x0,   0x102, 0x7,   0x1, 0x9,   0x1, 0xA,   0x1, 0xB,   0x1, 0xC,   0x1, 0xD,   0x1, 0xE,   0x1, 0xF,   0x103, 0x7,   0x102, 0xE,   0x103, 0x7,   0x102, 0xE,   0x103, 0x7,   0x102, 0xC,   0x101, 0x28,  0x101, 0x29,  0x100, 0x0,   0x103, 0x0,   0x102, 0x5,   0x103, 0x0,   0x102, 0x5,   0x202, 0x7,   0x202, 0xB,   0x202, 0xC,   0x101, 0xF,   0x302, 0x11,  0x302, 0x12,  0x302, 0x13,  0x103, 0x0,   0x102, 0x5,   0x103, 0x0,   0x102, 0x5,   0x202, 0xA,   0x1, 0xE,   0x100, 0x7,   0x100,
    0x8,   0x100, 0x9,   0x100, 0x11,  0x100, 0x10,  0x103, 0x0,   0x102, 0x5,   0x103, 0x0,   0x102, 0x5,   0x100, 0x7,   0x100, 0x8,   0x100, 0xA,   0x100, 0x9,   0x103, 0x0,   0x102, 0x5,   0x101, 0x9,   0x102, 0x7,   0x101, 0xA, 0x101, 0xB, 0x101, 0xC, 0x101, 0xD, 0x101, 0xE, 0x101, 0xF, 0x103, 0x10, 0x102, 0x15, 0x101, 0x19, 0x102, 0x17, 0x101, 0x1A, 0x101, 0x1B, 0x101, 0x1C, 0x101, 0x1D,  0x101, 0x1E,  0x101, 0x1F,  0x100, 0x20,  0x103, 0x0, 0x102, 0x5, 0x103, 0x0, 0x102, 0x7, 0x103, 0x0, 0x102, 0x5, 0x103, 0x0, 0x102, 0x7,   0x103, 0x0,   0x103, 0x0,   0x103, 0x0,   0x103, 0x0,   0x103, 0x0,   0x103, 0x0,   0x103, 0x0,   0x103, 0x0,   0x102, 0x0,   0x102, 0x0,   0x102, 0x0,   0x102, 0x0,   0x101, 0x3,   0x101, 0x2,   0x103, 0x10,  0x102, 0x15,  0x103, 0x10,  0x102, 0x17,  0x103, 0x5,   0x102, 0xA,   0x103, 0x5,   0x102, 0xC,   0x103, 0x7,   0x102, 0xC,   0x103, 0x7, 0x102, 0xE,   0x100, 0x0,
};  // 0x085AAFF4

typedef struct {
  SpriteID16 id;      // 0x0, NPCのスプライトIDばっかり
  u8 idx;             // 0x2, 1つのグラフィックにn人分のグラフィックデータが入っているときにどのキャラクターかを示すインデックス?
  const void* unk_4;  // 0x4, u16_ARRAY_085aaff4 のどの要素を指しているか
} Unk085ab210;

const Unk085ab210 Unk085ab210_ARRAY_085ab210[21] = {
    {id : SPRITE_DJANGO_SABATA,        idx : 0, unk_4 : &u16_ARRAY_085aaff4[0]  },
    {id : SPRITE_MOUSE,                idx : 0, unk_4 : &u16_ARRAY_085aaff4[16] },
    {id : SPRITE_SKELETONS,            idx : 0, unk_4 : &u16_ARRAY_085aaff4[24] },
    {id : SPRITE_BOKU,                 idx : 0, unk_4 : &u16_ARRAY_085aaff4[32] },
    {id : SPRITE_OTNK,                 idx : 0, unk_4 : &u16_ARRAY_085aaff4[40] },
    {id : SPRITE_SMITH_MARCELLO,       idx : 0, unk_4 : &u16_ARRAY_085aaff4[58] },
    {id : SPRITE_SHAIAN,               idx : 0, unk_4 : &u16_ARRAY_085aaff4[80] },
    {id : SPRITE_RITA,                 idx : 0, unk_4 : &u16_ARRAY_085aaff4[98] },
    {id : SPRITE_ZAJI,                 idx : 0, unk_4 : &u16_ARRAY_085aaff4[120]},
    {id : SPRITE_SUMIRE,               idx : 0, unk_4 : &u16_ARRAY_085aaff4[142]},
    {id : SPRITE_KURO,                 idx : 0, unk_4 : &u16_ARRAY_085aaff4[158]},
    {id : SPRITE_KID,                  idx : 0, unk_4 : &u16_ARRAY_085aaff4[200]},
    {id : SPRITE_LADY,                 idx : 0, unk_4 : &u16_ARRAY_085aaff4[208]},
    {id : SPRITE_COFFINSELLER_UNKNOWN, idx : 0, unk_4 : &u16_ARRAY_085aaff4[216]},
    {id : SPRITE_ENNIO_LUIS,           idx : 0, unk_4 : &u16_ARRAY_085aaff4[224]},
    {id : SPRITE_DAINN,                idx : 0, unk_4 : &u16_ARRAY_085aaff4[232]},
    {id : SPRITE_DJANGO_SABATA,        idx : 1, unk_4 : &u16_ARRAY_085aaff4[8]  },
    {id : SPRITE_SMITH_MARCELLO,       idx : 1, unk_4 : &u16_ARRAY_085aaff4[244]},
    {id : SPRITE_COFFINSELLER_UNKNOWN, idx : 1, unk_4 : &u16_ARRAY_085aaff4[252]},
    {id : SPRITE_ENNIO_LUIS,           idx : 1, unk_4 : &u16_ARRAY_085aaff4[260]},
    {id : SPRITE_MEGAMAN,              idx : 0, unk_4 : &u16_ARRAY_085aaff4[268]}
};  // 0x085AB210

typedef struct {
  SpriteID16 id;  // 0x0, NPCのスプライトIDばっかり
  u8 idx;         // 0x2, 1つのグラフィックにn人分のグラフィックデータが入っているときにどのキャラクターかを示すインデックス?
  u8 unk_3;       // 0x3, 不明
  u8 unk_4[4];    // 0x4, 不明, 型も不明
} Unk085ab2b8;

const Unk085ab2b8 Unk085ab2b8_ARRAY_085ab2b8[21] = {
    {id : SPRITE_DJANGO_SABATA,        idx : 0, unk_3 : 0, unk_4 : {0xFF, 0xFF, 0xFF, 0xFF}},
    {id : SPRITE_MOUSE,                idx : 0, unk_3 : 0, unk_4 : {0xFF, 0xFF, 0xFF, 0xFF}},
    {id : SPRITE_SKELETONS,            idx : 0, unk_3 : 0, unk_4 : {0xFF, 0xFF, 0xFF, 0xFF}},
    {id : SPRITE_BOKU,                 idx : 0, unk_3 : 0, unk_4 : {0xFF, 0xFF, 0xFF, 0xFF}},
    {id : SPRITE_OTNK,                 idx : 0, unk_3 : 0, unk_4 : {0xFF, 0xFF, 0xFF, 0xFF}},
    {id : SPRITE_SMITH_MARCELLO,       idx : 0, unk_3 : 0, unk_4 : {0x2, 0x0, 0x2, 0x0}    },
    {id : SPRITE_SHAIAN,               idx : 0, unk_3 : 0, unk_4 : {0x4, 0x0, 0x4, 0x0}    },
    {id : SPRITE_RITA,                 idx : 0, unk_3 : 1, unk_4 : {0x2, 0x0, 0x2, 0x0}    },
    {id : SPRITE_ZAJI,                 idx : 0, unk_3 : 1, unk_4 : {0x2, 0x0, 0x2, 0x0}    },
    {id : SPRITE_SUMIRE,               idx : 0, unk_3 : 2, unk_4 : {0x2, 0x0, 0x2, 0x0}    },
    {id : SPRITE_KURO,                 idx : 0, unk_3 : 0, unk_4 : {0xFF, 0xFF, 0xFF, 0xFF}},
    {id : SPRITE_KID,                  idx : 0, unk_3 : 0, unk_4 : {0x2, 0x0, 0x2, 0x0}    },
    {id : SPRITE_LADY,                 idx : 0, unk_3 : 1, unk_4 : {0x2, 0x0, 0x2, 0x0}    },
    {id : SPRITE_COFFINSELLER_UNKNOWN, idx : 0, unk_3 : 0, unk_4 : {0xFF, 0xFF, 0xFF, 0xFF}},
    {id : SPRITE_ENNIO_LUIS,           idx : 0, unk_3 : 0, unk_4 : {0xFF, 0xFF, 0xFF, 0xFF}},
    {id : SPRITE_DAINN,                idx : 0, unk_3 : 0, unk_4 : {0xFF, 0xFF, 0xFF, 0xFF}},
    {id : SPRITE_DJANGO_SABATA,        idx : 1, unk_3 : 0, unk_4 : {0xFF, 0xFF, 0xFF, 0xFF}},
    {id : SPRITE_SMITH_MARCELLO,       idx : 1, unk_3 : 0, unk_4 : {0x2, 0x0, 0x2, 0x0}    },
    {id : SPRITE_COFFINSELLER_UNKNOWN, idx : 1, unk_3 : 0, unk_4 : {0x2, 0x0, 0x2, 0x0}    },
    {id : SPRITE_ENNIO_LUIS,           idx : 1, unk_3 : 0, unk_4 : {0x2, 0x0, 0x2, 0x0}    },
    {id : SPRITE_MEGAMAN,              idx : 0, unk_3 : 0, unk_4 : {0x2, 0x0, 0x2, 0x0}    }
};  // 0x085AB2B8

const SoundID16 sound16_t_ARRAY_085ab360[6] = {0xC9, 0xCA, 0x25B, 0x25C, 0x25B, 0x25C};  // 0x085AB360

void FUN_080440ac(unknown*, unknown*);
void FUN_080440d0(unknown*, unknown*);
void FUN_08044104(unknown*, unknown*);

void (*const PTR_ARRAY_085ab36c[3])(unknown*, unknown*) = {
    FUN_080440ac,
    FUN_080440d0,
    FUN_08044104,
};  // 0x085AB36C

void FUN_08042178(unknown*, unknown*);
void FUN_080421bc(unknown*, unknown*);
void FUN_08042200(unknown*, unknown*);
void FUN_0804234c(unknown*, unknown*);
void FUN_08042414(unknown*, unknown*);
void FUN_08042638(unknown*, unknown*);

void (*const PTR_ARRAY_085ab378[14])(unknown*, unknown*) = {
    NULL, FUN_08042178, FUN_080421bc, FUN_08042200, FUN_0804234c, FUN_08042414, FUN_08042638, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
};  // 0x085AB378

void FUN_0804454c(unknown*, unknown*);
void FUN_08044570(unknown*, unknown*);
void FUN_080445a4(unknown*, unknown*);
void FUN_080445d8(unknown*, unknown*);
void FUN_080445fc(unknown*, unknown*);
void FUN_08044634(unknown*, unknown*);
void FUN_08044658(unknown*, unknown*);
void FUN_08044690(unknown*, unknown*);
void FUN_080446b4(unknown*, unknown*);
void FUN_080446d8(unknown*, unknown*);

void (*const PTR_ARRAY_085ab3b0[10])(unknown*, unknown*) = {
    FUN_0804454c, FUN_08044570, FUN_080445a4, FUN_080445d8, FUN_080445fc, FUN_08044634, FUN_08044658, FUN_08044690, FUN_080446b4, FUN_080446d8,
};  // 0x085AB3B0

void FUN_0804473c(unknown*, unknown*);
void FUN_0804478c(unknown*, unknown*);
void FUN_080448c8(unknown*, unknown*);
void FUN_0804494c(unknown*, unknown*);
void FUN_080449c0(unknown*, unknown*);
void FUN_08044a54(unknown*, unknown*);
void FUN_08044a90(unknown*, unknown*);
void FUN_08044d9c(unknown*, unknown*);
void FUN_08044dd8(unknown*, unknown*);
void FUN_08044e6c(unknown*, unknown*);

void (*const PTR_ARRAY_085ab3d8[11])(unknown*, unknown*) = {
    NULL, FUN_0804473c, FUN_0804478c, FUN_080448c8, FUN_0804494c, FUN_080449c0, FUN_08044a54, FUN_08044a90, FUN_08044d9c, FUN_08044dd8, FUN_08044e6c,
};  // 0x085AB3D8

const u16 u16_ARRAY_085ab404[8] = {0, 16, 0, 0, 0, 0, 0, 0};  // 0x085AB404

const u16 u16_ARRAY_085ab414[8] = {5, 21, 0, 0, 0, 0, 0, 0};  // 0x085AB414

const u16 u16_ARRAY_085ab424[8] = {7, 23, 0, 0, 0, 0, 0, 0};  // 0x085AB424
