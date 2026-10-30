FileE89F_Header:
  .2byte 746 @ palStart
  .2byte 39 @ metaspriteCount
  .2byte 0 @ animationCount
  .2byte 144 @ subspriteCount
  .2byte 0 @ cmdCount
  .2byte 256 @ tileCount
  .4byte 32 @ offsetToPoses
  .4byte 812 @ offsetToAnims
  .4byte 812 @ offsetToSubsprites
  .4byte 1964 @ offsetToCmds
  .4byte 1964 @ offsetToTiles

FileE89F_Poses:
@ pose unk_0,  obj,               objcount,   bb
  pose 0xEF1B, FileE89F_Obj_0,    4,            0,    0,  184,   88
  pose 0xB6C1, FileE89F_Obj_4,    2,            0,    0,  152,  136
  pose 0x2B78, FileE89F_Obj_6,    1,            0,    0,  120,  112
  pose 0x2B79, FileE89F_Obj_7,    1,            0,    0,  120,  112
  pose 0x2B7A, FileE89F_Obj_8,    1,            0,    0,  120,  112
  pose 0x2B7B, FileE89F_Obj_9,    1,            0,    0,  120,  112
  pose 0x2B7C, FileE89F_Obj_10,   1,            0,    0,  120,  112
  pose 0x2B7D, FileE89F_Obj_11,   1,            0,    0,  120,  112
  pose 0x2B7E, FileE89F_Obj_12,   1,            0,    0,  120,  112
  pose 0x2B7F, FileE89F_Obj_13,   1,            0,    0,  120,  112
  pose 0x2B80, FileE89F_Obj_14,   1,            0,    0,  120,  112
  pose 0x2B81, FileE89F_Obj_15,   1,            0,    0,  120,  112
  pose 0x2F78, FileE89F_Obj_16,   1,            0,    0,  112,  112
  pose 0x2F79, FileE89F_Obj_17,   1,            0,    0,  112,  112
  pose 0x2F7A, FileE89F_Obj_18,   1,            0,    0,  112,  112
  pose 0x2F7B, FileE89F_Obj_19,   1,            0,    0,  112,  112
  pose 0x2F7C, FileE89F_Obj_20,   1,            0,    0,  112,  112
  pose 0x2F7D, FileE89F_Obj_21,   1,            0,    0,  112,  112
  pose 0x2F7E, FileE89F_Obj_22,   1,            0,    0,  112,  112
  pose 0x2F7F, FileE89F_Obj_23,   1,            0,    0,  112,  112
  pose 0x2F80, FileE89F_Obj_24,   1,            0,    0,  112,  112
  pose 0x2F81, FileE89F_Obj_25,   1,            0,    0,  112,  112
  pose 0x25FE, FileE89F_Obj_26,   3,            0,    0,  152,  136
  pose 0xF90A, FileE89F_Obj_29,   6,            0,    0,  168,   88
  pose 0xF90B, FileE89F_Obj_35,   8,            0,    0,  184,   88
  pose 0xF92A, FileE89F_Obj_43,   4,            0,    0,  152,   88
  pose 0xF94A, FileE89F_Obj_47,   6,            0,    0,  168,   88
  pose 0xF96A, FileE89F_Obj_53,   7,            0,    0,  176,   88
  pose 0xF98A, FileE89F_Obj_60,   7,            0,    0,  176,   88
  pose 0xF9AA, FileE89F_Obj_67,   9,            0,    0,  176,   88
  pose 0x0D0B, FileE89F_Obj_76,   8,            0,    0,  184,   88
  pose 0x0D0C, FileE89F_Obj_84,   9,            0,    0,  192,   88
  pose 0x0D0D, FileE89F_Obj_93,   7,            0,    0,  176,   88
  pose 0x0D0E, FileE89F_Obj_100,  7,            0,    0,  176,   88
  pose 0x0D0F, FileE89F_Obj_107,  8,            0,    0,  184,   88
  pose 0x0D10, FileE89F_Obj_115,  10,           0,    0,  200,   88
  pose 0x0D11, FileE89F_Obj_125,  9,            0,    0,  192,   88
  pose 0x460B, FileE89F_Obj_134,  8,            0,    0,  184,   88
  pose 0x4764, FileE89F_Obj_142,  2,            0,    0,  152,  136

FileE89F_Anims:

1:
FileE89F_Subsprites:
@   subsprite size,            x,    y,   tile,  pal
  FileE89F_Obj_0:
    subsprite OAM_SIZE_32x16,   56,   56,    0,    0
    subsprite OAM_SIZE_32x16,   88,   56,    4,    0
    subsprite OAM_SIZE_32x16,  120,   56,    8,    0
    subsprite OAM_SIZE_32x16,  152,   56,   12,    0
  FileE89F_Obj_4:
    subsprite OAM_SIZE_16x16,   88,  104,  172,    0
    subsprite OAM_SIZE_32x16,  120,  104,  140,    0
  FileE89F_Obj_6:
    subsprite OAM_SIZE_8x16,   112,  104,  225,    0
  FileE89F_Obj_7:
    subsprite OAM_SIZE_8x16,   112,  104,  226,    0
  FileE89F_Obj_8:
    subsprite OAM_SIZE_8x16,   112,  104,  227,    0
  FileE89F_Obj_9:
    subsprite OAM_SIZE_8x16,   112,  104,  228,    0
  FileE89F_Obj_10:
    subsprite OAM_SIZE_8x16,   112,  104,  229,    0
  FileE89F_Obj_11:
    subsprite OAM_SIZE_8x16,   112,  104,  230,    0
  FileE89F_Obj_12:
    subsprite OAM_SIZE_8x16,   112,  104,  231,    0
  FileE89F_Obj_13:
    subsprite OAM_SIZE_8x16,   112,  104,  232,    0
  FileE89F_Obj_14:
    subsprite OAM_SIZE_8x16,   112,  104,  233,    0
  FileE89F_Obj_15:
    subsprite OAM_SIZE_8x16,   112,  104,  234,    0
  FileE89F_Obj_16:
    subsprite OAM_SIZE_8x16,   104,  104,  225,    0
  FileE89F_Obj_17:
    subsprite OAM_SIZE_8x16,   104,  104,  226,    0
  FileE89F_Obj_18:
    subsprite OAM_SIZE_8x16,   104,  104,  227,    0
  FileE89F_Obj_19:
    subsprite OAM_SIZE_8x16,   104,  104,  228,    0
  FileE89F_Obj_20:
    subsprite OAM_SIZE_8x16,   104,  104,  229,    0
  FileE89F_Obj_21:
    subsprite OAM_SIZE_8x16,   104,  104,  230,    0
  FileE89F_Obj_22:
    subsprite OAM_SIZE_8x16,   104,  104,  231,    0
  FileE89F_Obj_23:
    subsprite OAM_SIZE_8x16,   104,  104,  232,    0
  FileE89F_Obj_24:
    subsprite OAM_SIZE_8x16,   104,  104,  233,    0
  FileE89F_Obj_25:
    subsprite OAM_SIZE_8x16,   104,  104,  234,    0
  FileE89F_Obj_26:
    subsprite OAM_SIZE_32x16,   96,  104,  192,    1
    subsprite OAM_SIZE_16x16,  128,  104,  196,    1
    subsprite OAM_SIZE_8x16,   144,  104,  198,    1
  FileE89F_Obj_29:
    subsprite OAM_SIZE_16x16,   88,   72,  100,    0
    subsprite OAM_SIZE_16x16,  104,   72,   32,    0
    subsprite OAM_SIZE_16x16,  120,   72,   42,    0
    subsprite OAM_SIZE_16x16,  136,   72,  132,    0
    subsprite OAM_SIZE_16x16,  152,   72,  134,    0
    subsprite OAM_SIZE_16x16,   72,   72,  134,    0
  FileE89F_Obj_35:
    subsprite OAM_SIZE_16x16,  168,   72,  134,    0
    subsprite OAM_SIZE_16x16,   56,   72,  134,    0
    subsprite OAM_SIZE_16x16,   72,   72,   74,    0
    subsprite OAM_SIZE_16x16,   88,   72,   34,    0
    subsprite OAM_SIZE_16x16,  104,   72,  162,    0
    subsprite OAM_SIZE_16x16,  120,   72,  166,    0
    subsprite OAM_SIZE_16x16,  136,   72,  132,    0
    subsprite OAM_SIZE_16x16,  152,   72,   34,    0
  FileE89F_Obj_43:
    subsprite OAM_SIZE_16x16,  136,   72,  134,    0
    subsprite OAM_SIZE_16x16,   88,   72,  134,    0
    subsprite OAM_SIZE_16x16,  104,   72,   98,    0
    subsprite OAM_SIZE_16x16,  120,   72,  104,    0
  FileE89F_Obj_47:
    subsprite OAM_SIZE_16x16,  152,   72,  134,    0
    subsprite OAM_SIZE_16x16,   72,   72,  134,    0
    subsprite OAM_SIZE_16x16,   88,   72,   70,    0
    subsprite OAM_SIZE_16x16,  104,   72,   40,    0
    subsprite OAM_SIZE_16x16,  136,   72,   70,    0
    subsprite OAM_SIZE_16x16,  120,   72,  170,    0
  FileE89F_Obj_53:
    subsprite OAM_SIZE_16x16,  160,   72,  134,    0
    subsprite OAM_SIZE_16x16,   64,   72,  134,    0
    subsprite OAM_SIZE_16x16,  144,   72,   36,    0
    subsprite OAM_SIZE_16x16,   80,   72,   74,    0
    subsprite OAM_SIZE_16x16,   96,   72,   42,    0
    subsprite OAM_SIZE_16x16,  112,   72,   78,    0
    subsprite OAM_SIZE_16x16,  128,   72,   32,    0
  FileE89F_Obj_60:
    subsprite OAM_SIZE_16x16,  160,   72,  134,    0
    subsprite OAM_SIZE_16x16,   64,   72,  134,    0
    subsprite OAM_SIZE_16x16,  144,   72,   46,    0
    subsprite OAM_SIZE_16x16,   80,   72,  102,    0
    subsprite OAM_SIZE_16x16,   96,   72,   34,    0
    subsprite OAM_SIZE_16x16,  112,   72,   98,    0
    subsprite OAM_SIZE_16x16,  128,   72,   72,    0
  FileE89F_Obj_67:
    subsprite OAM_SIZE_16x16,  160,   72,  134,    0
    subsprite OAM_SIZE_16x16,   64,   72,  134,    0
    subsprite OAM_SIZE_16x16,  112,   72,  128,    0
    subsprite OAM_SIZE_16x16,  144,   72,   32,    0
    subsprite OAM_SIZE_16x16,  128,   72,  160,    0
    subsprite OAM_SIZE_16x16,   96,   72,  164,    0
    subsprite OAM_SIZE_16x16,   80,   72,   96,    0
    subsprite OAM_SIZE_32x16,   96,   56,  204,    0
    subsprite OAM_SIZE_16x16,  128,   56,  174,    0
  FileE89F_Obj_76:
    subsprite OAM_SIZE_16x16,  168,   72,  134,    0
    subsprite OAM_SIZE_16x16,   56,   72,  134,    0
    subsprite OAM_SIZE_16x16,  152,   72,   32,    0
    subsprite OAM_SIZE_16x16,   72,   72,  106,    0
    subsprite OAM_SIZE_16x16,   88,   72,   44,    0
    subsprite OAM_SIZE_16x16,  104,   72,  168,    0
    subsprite OAM_SIZE_16x16,  120,   72,  128,    0
    subsprite OAM_SIZE_16x16,  136,   72,  160,    0
  FileE89F_Obj_84:
    subsprite OAM_SIZE_16x16,  176,   72,  134,    0
    subsprite OAM_SIZE_16x16,   48,   72,  134,    0
    subsprite OAM_SIZE_16x16,  112,   72,  168,    0
    subsprite OAM_SIZE_16x16,  128,   72,  128,    0
    subsprite OAM_SIZE_16x16,  144,   72,  160,    0
    subsprite OAM_SIZE_16x16,  160,   72,   32,    0
    subsprite OAM_SIZE_16x16,   64,   72,  166,    0
    subsprite OAM_SIZE_16x16,   80,   72,  130,    0
    subsprite OAM_SIZE_16x16,   96,   72,   34,    0
  FileE89F_Obj_93:
    subsprite OAM_SIZE_16x16,  160,   72,  134,    0
    subsprite OAM_SIZE_16x16,   64,   72,  134,    0
    subsprite OAM_SIZE_16x16,   96,   72,  168,    0
    subsprite OAM_SIZE_16x16,  112,   72,  128,    0
    subsprite OAM_SIZE_16x16,  128,   72,  160,    0
    subsprite OAM_SIZE_16x16,  144,   72,   32,    0
    subsprite OAM_SIZE_16x16,   80,   72,   64,    0
  FileE89F_Obj_100:
    subsprite OAM_SIZE_16x16,  160,   72,  134,    0
    subsprite OAM_SIZE_16x16,   64,   72,  134,    0
    subsprite OAM_SIZE_16x16,   96,   72,  168,    0
    subsprite OAM_SIZE_16x16,  112,   72,  128,    0
    subsprite OAM_SIZE_16x16,  128,   72,  160,    0
    subsprite OAM_SIZE_16x16,  144,   72,   32,    0
    subsprite OAM_SIZE_16x16,   80,   72,   76,    0
  FileE89F_Obj_107:
    subsprite OAM_SIZE_16x16,  168,   72,  134,    0
    subsprite OAM_SIZE_16x16,   56,   72,  134,    0
    subsprite OAM_SIZE_16x16,  104,   72,  168,    0
    subsprite OAM_SIZE_16x16,  120,   72,  128,    0
    subsprite OAM_SIZE_16x16,  136,   72,  160,    0
    subsprite OAM_SIZE_16x16,  152,   72,   32,    0
    subsprite OAM_SIZE_16x16,   72,   72,  100,    0
    subsprite OAM_SIZE_16x16,   88,   72,   70,    0
  FileE89F_Obj_115:
    subsprite OAM_SIZE_16x16,  184,   72,  134,    0
    subsprite OAM_SIZE_16x16,   40,   72,  134,    0
    subsprite OAM_SIZE_16x16,  120,   72,  168,    0
    subsprite OAM_SIZE_16x16,  136,   72,  128,    0
    subsprite OAM_SIZE_16x16,  152,   72,  160,    0
    subsprite OAM_SIZE_16x16,  168,   72,   32,    0
    subsprite OAM_SIZE_16x16,   56,   72,  166,    0
    subsprite OAM_SIZE_16x16,   72,   72,  130,    0
    subsprite OAM_SIZE_16x16,   88,   72,   34,    0
    subsprite OAM_SIZE_16x16,  104,   72,   76,    0
  FileE89F_Obj_125:
    subsprite OAM_SIZE_16x16,  176,   72,  134,    0
    subsprite OAM_SIZE_16x16,   48,   72,  134,    0
    subsprite OAM_SIZE_16x16,   64,   72,  108,    0
    subsprite OAM_SIZE_16x16,   80,   72,   44,    0
    subsprite OAM_SIZE_16x16,   96,   72,   66,    0
    subsprite OAM_SIZE_16x16,  112,   72,   44,    0
    subsprite OAM_SIZE_16x16,  128,   72,   78,    0
    subsprite OAM_SIZE_16x16,  144,   72,   38,    0
    subsprite OAM_SIZE_16x16,  160,   72,   40,    0
  FileE89F_Obj_134:
    subsprite OAM_SIZE_16x16,  168,   72,  134,    0
    subsprite OAM_SIZE_16x16,   56,   72,  134,    0
    subsprite OAM_SIZE_16x16,  136,   72,  160,    0
    subsprite OAM_SIZE_16x16,  152,   72,   32,    0
    subsprite OAM_SIZE_16x16,   72,   72,   68,    0
    subsprite OAM_SIZE_16x16,   88,   72,   32,    0
    subsprite OAM_SIZE_16x16,  104,   72,  110,    0
    subsprite OAM_SIZE_16x16,  120,   72,   34,    0
  FileE89F_Obj_142:
    subsprite OAM_SIZE_32x16,   88,  104,  136,    0
    subsprite OAM_SIZE_32x16,  120,  104,  140,    0

FileE89F_Cmds:

FileE89F_Tiles:
  .incbin "data/sprite_main/E89F.4bpp"
