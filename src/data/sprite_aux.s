.include "asm/macros.inc"

.balign 4, 0
.section .rodata

.macro entry id:req, metasprite:req, w:req, h:req, x:req, y:req
  .2byte (\id), 0 @ id, unk_02(always 0)
  .byte (\w), (\h) @ w, h (pixel size)
  .byte (\x), (\y) @ x, y (pixel offset)
  .4byte (\metasprite) - Metaprite_0
.endm

.macro metasprite subsprite:req, subspritecount:req, tilecount:req, plttID:req, tiles:req
  .byte (\subspritecount), (\tilecount) @ subspriteCount, tilecount
  .2byte (\plttID) @ plttID
  .4byte (\tiles) << 5, ((\subsprite) - Subsprite_0)
.endm

.macro subsprite size:req, x:req, y:req
  .byte (\size), 0 @ shape, unk_01(always 0)
  .byte (\x), (\y) @ x, y (pixel offset)
.endm

.global gAuxSpritesDirectory
gAuxSpritesDirectory: @ 0x08A22900
  .4byte 1, 0x10, 0x14, 0x1C
  .2byte 0xFF54, 0
  .4byte 0x1C, 0
AuxSpritesFile0: @ 0x08A2291C
	.4byte 0 @ unk0
	.4byte 253 @ entryCount
	.4byte 0 @ unk8
	.4byte Tiles -      AuxSpritesFile0 @ offsetToTiles
	.4byte Metaprites - AuxSpritesFile0 @ offsetToMetasprites
	.4byte Subsprites - AuxSpritesFile0 @ offsetToSubsprites

Entries:
  entry 0xB306, Metaprite_0, 64, 64, 20, 44 @ 0
  entry 0xF680, Metaprite_4, 64, 64, 44, 51 @ 1
  entry 0xA5B3, Metaprite_6, 16, 16, 8, 8 @ 2
  entry 0xA5B4, Metaprite_7, 32, 32, 0, 0 @ 3
  entry 0x5AFD, Metaprite_11, 64, 64, 32, 32 @ 4
  entry 0x5AFE, Metaprite_14, 64, 64, 32, 32 @ 5
  entry 0x48DE, Metaprite_18, 32, 64, 14, 50 @ 6
  entry 0xD4EE, Metaprite_43, 32, 64, 14, 50 @ 7
  entry 0x924B, Metaprite_55, 64, 64, 32, 50 @ 8
  entry 0x2C12, Metaprite_63, 64, 64, 24, 24 @ 9
  entry 0x8F5D, Metaprite_67, 64, 64, 32, 32 @ 10
  entry 0x7AEE, Metaprite_82, 64, 128, 32, 64 @ 11
  entry 0x7AEF, Metaprite_85, 64, 128, 32, 64 @ 12
  entry 0x7AF0, Metaprite_88, 64, 128, 32, 64 @ 13
  entry 0x7AF1, Metaprite_91, 64, 128, 32, 64 @ 14
  entry 0x7AF2, Metaprite_94, 64, 128, 32, 64 @ 15
  entry 0xA20C, Metaprite_97, 8, 8, 4, 4 @ 16
  entry 0x9D2D, Metaprite_101, 64, 64, 24, 40 @ 17
  entry 0x048A, Metaprite_102, 64, 64, 24, 40 @ 18
  entry 0xE1D2, Metaprite_103, 64, 64, 24, 48 @ 19
  entry 0xB0E2, Metaprite_104, 32, 32, 13, 25 @ 20
  entry 0xC060, Metaprite_106, 32, 32, 16, 16 @ 21
  entry 0xDD5C, Metaprite_107, 64, 64, 33, 48 @ 22
  entry 0x4AEE, Metaprite_108, 64, 64, 24, 48 @ 23
  entry 0xA0D5, Metaprite_109, 32, 32, 16, 16 @ 24
  entry 0x2AF0, Metaprite_127, 64, 64, 24, 51 @ 25
  entry 0xA680, Metaprite_131, 64, 64, 24, 24 @ 26
  entry 0xA6A0, Metaprite_143, 16, 32, 0, 32 @ 27
  entry 0x2D41, Metaprite_147, 64, 64, 32, 32 @ 28
  entry 0xA850, Metaprite_180, 16, 32, 8, 16 @ 29
  entry 0x9D43, Metaprite_182, 64, 64, 24, 46 @ 30
  entry 0x008A, Metaprite_183, 64, 64, 24, 64 @ 31
  entry 0x76DB, Metaprite_185, 64, 64, 24, 48 @ 32
  entry 0x2712, Metaprite_188, 16, 16, 7, 14 @ 33
  entry 0x5DC0, Metaprite_196, 32, 32, 12, 20 @ 34
  entry 0x6AF6, Metaprite_212, 32, 32, 16, 16 @ 35
  entry 0x4AAE, Metaprite_220, 32, 32, 0, 0 @ 36
  entry 0x1C1B, Metaprite_221, 32, 32, 16, 16 @ 37
  entry 0x9FF5, Metaprite_229, 8, 8, 4, 4 @ 38
  entry 0xA606, Metaprite_240, 64, 64, 24, 48 @ 39
  entry 0xD28E, Metaprite_249, 16, 16, 8, 8 @ 40
  entry 0xD166, Metaprite_291, 64, 64, 21, 20 @ 41
  entry 0x0BA8, Metaprite_294, 32, 32, 16, 16 @ 42
  entry 0x0BA9, Metaprite_319, 64, 64, 32, 32 @ 43
  entry 0x363C, Metaprite_320, 8, 16, 4, 8 @ 44
  entry 0x363D, Metaprite_330, 32, 16, 16, 8 @ 45
  entry 0x1FBD, Metaprite_337, 32, 64, 0, 48 @ 46
  entry 0x6AF7, Metaprite_338, 32, 64, 16, 32 @ 47
  entry 0x1B59, Metaprite_339, 32, 64, 16, 52 @ 48
  entry 0x7E82, Metaprite_342, 32, 64, 16, 64 @ 49
  entry 0xBCA8, Metaprite_343, 64, 64, 20, 44 @ 50
  entry 0x4384, Metaprite_345, 32, 32, 16, 16 @ 51
  entry 0x4385, Metaprite_354, 8, 8, 4, 4 @ 52
  entry 0x05A2, Metaprite_360, 64, 64, 24, 40 @ 53
  entry 0x34C0, Metaprite_361, 32, 64, 16, 32 @ 54
  entry 0x528F, Metaprite_362, 32, 32, 16, 16 @ 55
  entry 0x7AD2, Metaprite_378, 32, 64, 16, 52 @ 56
  entry 0xB96C, Metaprite_381, 32, 32, 16, 18 @ 57
  entry 0x7031, Metaprite_397, 16, 16, 8, 8 @ 58
  entry 0x7032, Metaprite_398, 8, 8, 4, 4 @ 59
  entry 0xE857, Metaprite_401, 64, 64, 24, 48 @ 60
  entry 0x3641, Metaprite_409, 32, 32, 16, 16 @ 61
  entry 0xF070, Metaprite_411, 64, 64, 6, 49 @ 62
  entry 0xC3C3, Metaprite_415, 64, 64, 24, 48 @ 63
  entry 0x1C84, Metaprite_418, 64, 64, 32, 32 @ 64
  entry 0xE505, Metaprite_419, 64, 64, 24, 48 @ 65
  entry 0xFDC5, Metaprite_429, 32, 64, 16, 48 @ 66
  entry 0x96F7, Metaprite_436, 16, 32, 9, 29 @ 67
  entry 0xA5BD, Metaprite_437, 32, 8, 0, 0 @ 68
  entry 0x7AD3, Metaprite_439, 64, 128, 32, 64 @ 69
  entry 0x7AD4, Metaprite_442, 64, 128, 32, 64 @ 70
  entry 0x7AD5, Metaprite_445, 64, 128, 32, 64 @ 71
  entry 0x7AD6, Metaprite_448, 64, 128, 32, 64 @ 72
  entry 0x7AED, Metaprite_451, 64, 128, 32, 64 @ 73
  entry 0x7AF3, Metaprite_454, 64, 128, 32, 64 @ 74
  entry 0x7AF4, Metaprite_457, 64, 128, 32, 64 @ 75
  entry 0x7AF5, Metaprite_460, 64, 128, 32, 64 @ 76
  entry 0x7AF6, Metaprite_463, 64, 128, 32, 64 @ 77
  entry 0x7B0D, Metaprite_466, 64, 128, 32, 64 @ 78
  entry 0x9506, Metaprite_469, 32, 32, 17, 17 @ 79
  entry 0x22E7, Metaprite_498, 64, 64, 24, 48 @ 80
  entry 0x41B1, Metaprite_510, 32, 32, 16, 16 @ 81
  entry 0xDC8E, Metaprite_518, 64, 64, 33, 54 @ 82
  entry 0xCDAB, Metaprite_519, 64, 64, 20, 20 @ 83
  entry 0xD962, Metaprite_520, 32, 64, 16, 52 @ 84
  entry 0xB044, Metaprite_528, 64, 64, 24, 0 @ 85
  entry 0x3668, Metaprite_529, 16, 16, 8, 8 @ 86
  entry 0x18A8, Metaprite_555, 16, 16, 8, 8 @ 87
  entry 0x18A9, Metaprite_559, 8, 16, 4, 8 @ 88
  entry 0x2769, Metaprite_570, 32, 32, 12, 28 @ 89
  entry 0x5B78, Metaprite_572, 64, 64, 24, 24 @ 90
  entry 0x16F5, Metaprite_573, 64, 64, 20, 44 @ 91
  entry 0xF422, Metaprite_577, 32, 32, 16, 16 @ 92
  entry 0x848F, Metaprite_603, 16, 16, 8, 8 @ 93
  entry 0x8490, Metaprite_616, 64, 64, 32, 40 @ 94
  entry 0xD638, Metaprite_622, 64, 64, 30, 40 @ 95
  entry 0xEF69, Metaprite_659, 64, 64, 27, 29 @ 96
  entry 0x5BA7, Metaprite_660, 64, 64, 24, 24 @ 97
  entry 0x5BB7, Metaprite_661, 64, 64, 24, 24 @ 98
  entry 0xE74B, Metaprite_662, 16, 16, 8, 8 @ 99
  entry 0x9A1F, Metaprite_686, 16, 16, 8, 8 @ 100
  entry 0xC459, Metaprite_697, 64, 64, 21, 21 @ 101
  entry 0xDC07, Metaprite_698, 64, 64, 24, 24 @ 102
  entry 0xD45E, Metaprite_699, 32, 32, 16, 16 @ 103
  entry 0xD85E, Metaprite_763, 32, 32, 16, 16 @ 104
  entry 0x2817, Metaprite_785, 16, 32, 0, 0 @ 105
  entry 0xEFD8, Metaprite_786, 32, 32, 16, 0 @ 106
  entry 0x8639, Metaprite_797, 32, 32, 16, 16 @ 107
  entry 0x97D3, Metaprite_813, 16, 32, 8, 19 @ 108
  entry 0x97D4, Metaprite_850, 32, 32, 16, 19 @ 109
  entry 0xC42D, Metaprite_864, 32, 32, 16, 16 @ 110
  entry 0x0334, Metaprite_865, 8, 8, 4, 4 @ 111
  entry 0x9DFF, Metaprite_866, 64, 64, 24, 48 @ 112
  entry 0xA152, Metaprite_868, 64, 64, 24, 24 @ 113
  entry 0x17C7, Metaprite_869, 64, 64, 24, 0 @ 114
  entry 0x210E, Metaprite_871, 16, 16, 8, 8 @ 115
  entry 0x210F, Metaprite_875, 32, 32, 16, 16 @ 116
  entry 0x1FE0, Metaprite_880, 64, 64, 24, 48 @ 117
  entry 0x2C1A, Metaprite_891, 64, 64, 24, 0 @ 118
  entry 0x5291, Metaprite_892, 32, 64, 11, 32 @ 119
  entry 0x5292, Metaprite_894, 16, 32, 7, 18 @ 120
  entry 0x9247, Metaprite_898, 32, 64, 16, 50 @ 121
  entry 0xD4EA, Metaprite_910, 32, 64, 16, 50 @ 122
  entry 0x47DE, Metaprite_920, 32, 64, 16, 50 @ 123
  entry 0xC046, Metaprite_945, 64, 64, 24, 48 @ 124
  entry 0x2097, Metaprite_948, 64, 64, 24, 46 @ 125
  entry 0x17C8, Metaprite_960, 64, 64, 24, 0 @ 126
  entry 0xBB68, Metaprite_962, 64, 64, 32, 48 @ 127
  entry 0xEED8, Metaprite_966, 64, 64, 20, 40 @ 128
  entry 0x505C, Metaprite_968, 16, 16, 8, 8 @ 129
  entry 0xA47C, Metaprite_977, 32, 64, 16, 37 @ 130
  entry 0xDDE7, Metaprite_978, 64, 64, 24, 24 @ 131
  entry 0x9E08, Metaprite_979, 64, 64, 24, 24 @ 132
  entry 0xA8E7, Metaprite_980, 8, 8, 0, 0 @ 133
  entry 0x5A6E, Metaprite_991, 32, 32, 16, 16 @ 134
  entry 0x5A6F, Metaprite_1014, 32, 32, 16, 20 @ 135
  entry 0x44EE, Metaprite_1030, 64, 64, 24, 48 @ 136
  entry 0x5D7C, Metaprite_1031, 64, 64, 24, 48 @ 137
  entry 0xB837, Metaprite_1032, 32, 32, 16, 32 @ 138
  entry 0xE0C9, Metaprite_1042, 64, 64, 24, 46 @ 139
  entry 0x8203, Metaprite_1043, 64, 64, 32, 32 @ 140
  entry 0x8204, Metaprite_1047, 32, 32, 16, 16 @ 141
  entry 0x8205, Metaprite_1049, 16, 16, 8, 6 @ 142
  entry 0x8202, Metaprite_1053, 16, 16, 8, 8 @ 143
  entry 0x8206, Metaprite_1066, 16, 16, 8, 8 @ 144
  entry 0x8207, Metaprite_1072, 8, 8, 4, 4 @ 145
  entry 0xDC38, Metaprite_1079, 64, 64, 24, 48 @ 146
  entry 0x8393, Metaprite_1090, 64, 64, 24, 48 @ 147
  entry 0x066A, Metaprite_1106, 16, 32, 8, 31 @ 148
  entry 0x17C9, Metaprite_1110, 64, 64, 24, 0 @ 149
  entry 0xDB6C, Metaprite_1112, 64, 64, 24, 40 @ 150
  entry 0xD0A3, Metaprite_1113, 16, 32, 3, 13 @ 151
  entry 0x9385, Metaprite_1116, 32, 32, 16, 16 @ 152
  entry 0xB626, Metaprite_1119, 64, 64, 32, 36 @ 153
  entry 0xD637, Metaprite_1120, 32, 32, 16, 16 @ 154
  entry 0xE7EA, Metaprite_1149, 8, 8, 4, 4 @ 155
  entry 0xDFCF, Metaprite_1154, 64, 64, 27, 30 @ 156
  entry 0x0E48, Metaprite_1158, 32, 32, 16, 16 @ 157
  entry 0xDC72, Metaprite_1159, 64, 64, 16, 29 @ 158
  entry 0xC039, Metaprite_1160, 64, 64, 32, 32 @ 159
  entry 0x9803, Metaprite_1161, 64, 64, 24, 48 @ 160
  entry 0xD56D, Metaprite_1175, 64, 64, 24, 24 @ 161
  entry 0x17CA, Metaprite_1177, 64, 64, 24, 0 @ 162
  entry 0x3640, Metaprite_1179, 32, 32, 16, 16 @ 163
  entry 0x9B09, Metaprite_1195, 64, 64, 24, 48 @ 164
  entry 0xD454, Metaprite_1204, 64, 64, 24, 48 @ 165
  entry 0xD636, Metaprite_1213, 32, 32, 16, 16 @ 166
  entry 0xE769, Metaprite_1257, 64, 64, 32, 32 @ 167
  entry 0xE76A, Metaprite_1282, 16, 16, 8, 8 @ 168
  entry 0xE76B, Metaprite_1294, 32, 32, 16, 16 @ 169
  entry 0xD495, Metaprite_1309, 32, 32, 16, 19 @ 170
  entry 0x35C7, Metaprite_1331, 64, 64, 24, 48 @ 171
  entry 0x3B53, Metaprite_1343, 64, 64, 24, 48 @ 172
  entry 0x3C13, Metaprite_1356, 64, 64, 22, 29 @ 173
  entry 0x9D3F, Metaprite_1358, 64, 32, 20, 20 @ 174
  entry 0x7C99, Metaprite_1360, 32, 32, 28, 4 @ 175
  entry 0xB019, Metaprite_1367, 64, 64, 0, 0 @ 176
  entry 0xDA09, Metaprite_1368, 64, 64, 0, 0 @ 177
  entry 0xC3BD, Metaprite_1369, 64, 64, 0, 0 @ 178
  entry 0x9462, Metaprite_1370, 64, 64, 0, 0 @ 179
  entry 0x75D6, Metaprite_1371, 64, 64, 0, 0 @ 180
  entry 0x7605, Metaprite_1372, 64, 64, 0, 0 @ 181
  entry 0xD291, Metaprite_1373, 64, 64, 30, 40 @ 182
  entry 0xD292, Metaprite_1408, 64, 64, 24, 24 @ 183
  entry 0x7C07, Metaprite_1409, 64, 64, 24, 48 @ 184
  entry 0xFC07, Metaprite_1415, 64, 64, 24, 48 @ 185
  entry 0xBC08, Metaprite_1428, 64, 64, 24, 48 @ 186
  entry 0xC038, Metaprite_1437, 64, 64, 33, 49 @ 187
  entry 0x1D78, Metaprite_1454, 64, 64, 32, 32 @ 188
  entry 0x6154, Metaprite_1456, 32, 32, 7, 5 @ 189
  entry 0x17CB, Metaprite_1460, 64, 64, 24, 0 @ 190
  entry 0xBE6D, Metaprite_1462, 64, 64, 24, 48 @ 191
  entry 0xCC88, Metaprite_1473, 8, 8, 4, 4 @ 192
  entry 0x96B5, Metaprite_1477, 64, 64, 24, 33 @ 193
  entry 0x2C3D, Metaprite_1478, 64, 64, 24, 32 @ 194
  entry 0x7BE7, Metaprite_1479, 64, 64, 24, 48 @ 195
  entry 0xD635, Metaprite_1493, 64, 64, 32, 32 @ 196
  entry 0xE369, Metaprite_1557, 64, 64, 32, 32 @ 197
  entry 0x41CF, Metaprite_1575, 64, 64, 32, 43 @ 198
  entry 0x43CF, Metaprite_1628, 64, 64, 32, 43 @ 199
  entry 0x9D40, Metaprite_1672, 64, 64, 24, 46 @ 200
  entry 0xA874, Metaprite_1673, 32, 32, 16, 16 @ 201
  entry 0xA875, Metaprite_1674, 8, 8, 4, 4 @ 202
  entry 0x5290, Metaprite_1675, 64, 64, 28, 44 @ 203
  entry 0x2110, Metaprite_1722, 32, 32, 16, 32 @ 204
  entry 0x2111, Metaprite_1734, 16, 16, 8, 24 @ 205
  entry 0x2499, Metaprite_1737, 64, 64, 32, 36 @ 206
  entry 0x249A, Metaprite_1793, 64, 64, 32, 36 @ 207
  entry 0x5B54, Metaprite_1803, 64, 64, 24, 48 @ 208
  entry 0x04B3, Metaprite_1805, 64, 64, 24, 56 @ 209
  entry 0x4FDA, Metaprite_1807, 32, 32, 16, 16 @ 210
  entry 0x863A, Metaprite_1815, 32, 32, 12, 24 @ 211
  entry 0x8638, Metaprite_1821, 64, 64, 32, 45 @ 212
  entry 0x61F9, Metaprite_1835, 32, 32, 16, 16 @ 213
  entry 0x2058, Metaprite_1893, 32, 32, 16, 16 @ 214
  entry 0x7ACD, Metaprite_1904, 64, 128, 32, 64 @ 215
  entry 0x7ACE, Metaprite_1907, 64, 128, 32, 64 @ 216
  entry 0x7ACF, Metaprite_1910, 64, 128, 32, 64 @ 217
  entry 0x7AD0, Metaprite_1913, 64, 128, 32, 64 @ 218
  entry 0x7AD1, Metaprite_1916, 64, 128, 32, 64 @ 219
  entry 0x2E78, Metaprite_1919, 32, 32, 16, 16 @ 220
  entry 0x2E79, Metaprite_1957, 64, 64, 36, 44 @ 221
  entry 0x2E7A, Metaprite_1970, 64, 64, 32, 32 @ 222
  entry 0x2E7B, Metaprite_1976, 16, 16, 8, 8 @ 223
  entry 0x2E7C, Metaprite_1997, 8, 8, 4, 4 @ 224
  entry 0x9D41, Metaprite_2011, 64, 64, 24, 46 @ 225
  entry 0xA894, Metaprite_2012, 32, 32, 16, 16 @ 226
  entry 0xA895, Metaprite_2013, 8, 8, 4, 4 @ 227
  entry 0x7AC6, Metaprite_2014, 64, 64, 24, 48 @ 228
  entry 0x84EE, Metaprite_2030, 64, 64, 24, 46 @ 229
  entry 0x494E, Metaprite_2034, 64, 64, 24, 48 @ 230
  entry 0x7BE2, Metaprite_2035, 64, 64, 24, 48 @ 231
  entry 0x2EC0, Metaprite_2048, 64, 64, 24, 24 @ 232
  entry 0xDA6D, Metaprite_2049, 32, 32, 16, 16 @ 233
  entry 0x354D, Metaprite_2065, 64, 64, 63, 55 @ 234
  entry 0x39A3, Metaprite_2066, 32, 32, 16, 16 @ 235
  entry 0x1C1D, Metaprite_2067, 32, 16, 16, 8 @ 236
  entry 0x654B, Metaprite_2072, 16, 16, 8, 8 @ 237
  entry 0xB0BC, Metaprite_2088, 64, 64, 24, 0 @ 238
  entry 0x24BA, Metaprite_2090, 64, 64, 32, 32 @ 239
  entry 0xA945, Metaprite_2093, 64, 64, 0, 0 @ 240
  entry 0x70EE, Metaprite_2095, 64, 64, 0, 0 @ 241
  entry 0x6F57, Metaprite_2097, 32, 32, 16, 0 @ 242
  entry 0x0C0A, Metaprite_2110, 32, 64, 19, 28 @ 243
  entry 0x2567, Metaprite_2114, 64, 64, 32, 40 @ 244
  entry 0xDF0E, Metaprite_2115, 32, 32, 16, 16 @ 245
  entry 0x1E15, Metaprite_2116, 8, 8, 4, 4 @ 246
  entry 0x0DDE, Metaprite_2117, 32, 64, 16, 43 @ 247
  entry 0x84B4, Metaprite_2122, 128, 128, 32, 32 @ 248
  entry 0x96C1, Metaprite_2132, 128, 128, 32, 96 @ 249
  entry 0x96C2, Metaprite_2142, 32, 32, 16, 16 @ 250
  entry 0x0D44, Metaprite_2148, 64, 64, 24, 48 @ 251
  entry 0x3876, Metaprite_2156, 32, 64, 17, 51 @ 252

@ TODO: タイルをメタスプライトごとに分けた方が見やすいので後で頑張る
Tiles:
  .incbin "data/actor_sprites/emblem_block_0.4bpp"       @ 0x08A23510, SpriteID: 0xB306, PlttID: 2, 紋章ブロック(炎氷地風)
  .incbin "data/actor_sprites/komainu.4bpp"              @ 0x08A24910, SpriteID: 0xF680, PlttID: 6, 大聖堂の狛犬
  .incbin "data/actor_sprites/A5B3.4bpp"                 @ 0x08A25190, SpriteID: 0xA5B3, PlttID: 0, 大聖堂の水晶?
  .incbin "data/actor_sprites/ghoul_liquid.4bpp"         @ 0x08A25210, SpriteID: 0xA5B4, PlttID: 1, グール系が出すホルルン液
  .incbin "data/actor_sprites/5AFD.4bpp"                 @ 0x08A25A10, SpriteID: 0x5AFD, PlttID: 7, シェードマンのスピーカー?
  .incbin "data/actor_sprites/5AFE.4bpp"                 @ 0x08A25E90, SpriteID: 0x5AFE, PlttID: 7, 輪っかのエフェクト(シェードマン関連?)
  .incbin "data/actor_sprites/mummy_0.4bpp"              @ 0x08A26B10, SpriteID: 0x48DE, PlttID: 23, マミー
  .incbin "data/actor_sprites/mummy_1.4bpp"              @ 0x08A29710, SpriteID: 0xD4EE, PlttID: 23, マミー
  .incbin "data/actor_sprites/mummy_2.4bpp"              @ 0x08A2AE30, SpriteID: 0x924B, PlttID: 23, マミー
  .incbin "data/actor_sprites/grating.4bpp"              @ 0x08A2C2F0, SpriteID: 0x2C12, PlttID: 28, 鳴り床(上を歩くと音が鳴る床)
  .incbin "data/actor_sprites/melee_shockwave.4bpp"      @ 0x08A2CE70, SpriteID: 0x8F5D, PlttID: 29, 斬撃っぽいエフェクト と 太陽鍛治で使う水桶
  .incbin "data/actor_sprites/7AEE.4bpp"                 @ 0x08A2DE70, SpriteID: 0x7AEE, PlttID: 42, 扉
  .incbin "data/actor_sprites/7AEF.4bpp"                 @ 0x08A2EB70, SpriteID: 0x7AEF, PlttID: 42, 扉
  .incbin "data/actor_sprites/7AF0.4bpp"                 @ 0x08A2F430, SpriteID: 0x7AF0, PlttID: 42, 扉
  .incbin "data/actor_sprites/7AF1.4bpp"                 @ 0x08A2FCF0, SpriteID: 0x7AF1, PlttID: 42, 扉
  .incbin "data/actor_sprites/7AF2.4bpp"                 @ 0x08A309F0, SpriteID: 0x7AF2, PlttID: 42, 扉
  .incbin "data/actor_sprites/A20C.4bpp"                 @ 0x08A316F0, SpriteID: 0xA20C, PlttID: 44, キラキラエフェクト?(太陽虫ではない)
  .incbin "data/actor_sprites/9D2D.4bpp"                 @ 0x08A31770, SpriteID: 0x9D2D, PlttID: 51, 壁?
  .incbin "data/actor_sprites/048A.4bpp"                 @ 0x08A31BF0, SpriteID: 0x048A, PlttID: 52, 柱?
  .incbin "data/actor_sprites/E1D2.4bpp"                 @ 0x08A320F0, SpriteID: 0xE1D2, PlttID: 53, 黒塗り
  .incbin "data/actor_sprites/light_bulb.4bpp"           @ 0x08A32570, SpriteID: 0xB0E2, PlttID: 54, 電球
  .incbin "data/actor_sprites/C060.4bpp"                 @ 0x08A32770, SpriteID: 0xC060, PlttID: 56, 謎の球
  .incbin "data/actor_sprites/DD5C.4bpp"                 @ 0x08A32970, SpriteID: 0xDD5C, PlttID: 60, 壁?
  .incbin "data/actor_sprites/4AEE.4bpp"                 @ 0x08A33170, SpriteID: 0x4AEE, PlttID: 61, 壁? 
  .incbin "data/actor_sprites/ect.4bpp"                  @ 0x08A33970, SpriteID: 0xA0D5, PlttID: 62, エクトプラズム
  .incbin "data/actor_sprites/chandelier.4bpp"           @ 0x08A354B0, SpriteID: 0x2AF0, PlttID: 64, シャンデリア(スプライトセットの方との使い分けは不明)
  .incbin "data/actor_sprites/A680.4bpp"                 @ 0x08A36CB0, SpriteID: 0xA680, PlttID: 66, 水たまり, 鳴り床, センサー床
  .incbin "data/actor_sprites/bok1_garden_lever_num.4bpp" @ 0x08A39930, SpriteID: 0xA6A0, PlttID: 71, ボクタイ1の血錆の館の中庭の数字が答えになる4つのレバーの上に書いてある数字(不使用?)
  .incbin "data/actor_sprites/2D41.4bpp"                 @ 0x08A39CD0, SpriteID: 0x2D41, PlttID: 72, エフェクト群
  .incbin "data/actor_sprites/hint_panel.4bpp"           @ 0x08A3BFD0, SpriteID: 0xA850, PlttID: 76, ヒントパネル
  .incbin "data/actor_sprites/9D43.4bpp"                 @ 0x08A3C1D0, SpriteID: 0x9D43, PlttID: 79, なんかのブロック
  .incbin "data/actor_sprites/008A.4bpp"                 @ 0x08A3C7D0, SpriteID: 0x008A, PlttID: 80, 瓦礫?
  .incbin "data/actor_sprites/76DB.4bpp"                 @ 0x08A3D3D0, SpriteID: 0x76DB, PlttID: 83, 黒塗り
  .incbin "data/actor_sprites/coin.4bpp"                 @ 0x08A3E010, SpriteID: 0x2712, PlttID: 86, コイン
  .incbin "data/actor_sprites/5DC0.4bpp"                 @ 0x08A3E410, SpriteID: 0x5DC0, PlttID: 87, なんかの物体
  .incbin "data/actor_sprites/shop_armors.4bpp"          @ 0x08A3FC10, SpriteID: 0x6AF6, PlttID: 89, キッドの店の内装
  .incbin "data/actor_sprites/4AAE.4bpp"                 @ 0x08A403F0, SpriteID: 0x4AAE, PlttID: 91, おっさん
  .incbin "data/actor_sprites/1C1B.4bpp"                 @ 0x08A405F0, SpriteID: 0x1C1B, PlttID: 0, エフェクト群(煙、蜘蛛の巣,???)
  .incbin "data/actor_sprites/9FF5.4bpp"                 @ 0x08A412B0, SpriteID: 0x9FF5, PlttID: 0, エフェクト群
  .incbin "data/actor_sprites/A606.4bpp"                 @ 0x08A41410, SpriteID: 0xA606, PlttID: 83, 黒塗り
  .incbin "data/actor_sprites/curoro.4bpp"               @ 0x08A43BD0, SpriteID: 0xD28E, PlttID: 92, クロロホルルン
  .incbin "data/actor_sprites/lilypad.4bpp"              @ 0x08A450D0, SpriteID: 0xD166, PlttID: 95, ハスの葉
  .incbin "data/actor_sprites/magic_circle.4bpp"         @ 0x08A45810, SpriteID: 0x0BA8, PlttID: 97, 魔方陣
  .incbin "data/actor_sprites/0BA9.4bpp"                 @ 0x08A48A10, SpriteID: 0x0BA9, PlttID: 97, 魔方陣(大)
  .incbin "data/actor_sprites/363C.4bpp"                 @ 0x08A49210, SpriteID: 0x363C, PlttID: 0, "!"
  .incbin "data/actor_sprites/363D.4bpp"                 @ 0x08A49430, SpriteID: 0x363D, PlttID: 0, emotion bubbles
  .incbin "data/actor_sprites/1FBD.4bpp"                 @ 0x08A49B30, SpriteID: 0x1FBD, PlttID: 112, なんかの壁
  .incbin "data/actor_sprites/shop_samurai_armor.4bpp"   @ 0x08A49E30, SpriteID: 0x6AF7, PlttID: 89, キッドの店の内装(武者鎧)
  .incbin "data/actor_sprites/1B59.4bpp"                 @ 0x08A4A0B0, SpriteID: 0x1B59, PlttID: 115, 扉(鉄格子)
  .incbin "data/actor_sprites/sunflower.4bpp"            @ 0x08A4ACB0, SpriteID: 0x7E82, PlttID: 116, ひまわり
  .incbin "data/actor_sprites/BCA8.4bpp"                 @ 0x08A4B0B0, SpriteID: 0xBCA8, PlttID: 120, 属性キューブ
  .incbin "data/actor_sprites/4384.4bpp"                 @ 0x08A4B970, SpriteID: 0x4384, PlttID: 125, エフェクト(地下水路の滝とかの水飛沫?)
  .incbin "data/actor_sprites/4385.4bpp"                 @ 0x08A4C7D0, SpriteID: 0x4385, PlttID: 130, エフェクト?
  .incbin "data/actor_sprites/tomb.4bpp"                 @ 0x08A4C890, SpriteID: 0x05A2, PlttID: 139, 大聖堂の(偽物の)墓
  .incbin "data/actor_sprites/34C0.4bpp"                 @ 0x08A4CD90, SpriteID: 0x34C0, PlttID: 142, 大聖堂の水晶をはめる穴あたりの壁?
  .incbin "data/actor_sprites/spider.4bpp"               @ 0x08A4D090, SpriteID: 0x528F, PlttID: 143, スパイダー
  .incbin "data/actor_sprites/door_iron.4bpp"            @ 0x08A4EF50, SpriteID: 0x7AD2, PlttID: 146, 鉄格子の扉
  .incbin "data/actor_sprites/slime.4bpp"                @ 0x08A4FB50, SpriteID: 0xB96C, PlttID: 147, スライム
  .incbin "data/actor_sprites/slime_debris_l.4bpp"       @ 0x08A51590, SpriteID: 0x7031, PlttID: 147, スライムの破片(大)
  .incbin "data/actor_sprites/slime_debris_s.4bpp"       @ 0x08A51610, SpriteID: 0x7032, PlttID: 147, スライムの破片(小)
  .incbin "data/actor_sprites/E857.4bpp"                 @ 0x08A51670, SpriteID: 0xE857, PlttID: 83, 黒塗り
  .incbin "data/actor_sprites/3641.4bpp"                 @ 0x08A54670, SpriteID: 0x3641, PlttID: 44, 丸い光のエフェクト
  .incbin "data/actor_sprites/wedge.4bpp"                @ 0x08A54A70, SpriteID: 0xF070, PlttID: 151, 封印の楔
  .incbin "data/actor_sprites/healing_plant.4bpp"        @ 0x08A557B0, SpriteID: 0xC3C3, PlttID: 95, 太陽の根(ヒーリングで成長させられるもじゃもじゃ)
  .incbin "data/actor_sprites/bed.4bpp"                 @ 0x08A56A30, SpriteID: 0x1C84, PlttID: 153, ベッド
  .incbin "data/actor_sprites/E505.4bpp"                 @ 0x08A57230, SpriteID: 0xE505, PlttID: 83, 黒塗り
  .incbin "data/actor_sprites/FDC5.4bpp"                 @ 0x08A5A9B0, SpriteID: 0xFDC5, PlttID: 165, なんか浮いている岩
  .incbin "data/actor_sprites/signboard.4bpp"            @ 0x08A5C170, SpriteID: 0x96F7, PlttID: 166, サンミゲルのまだ利用できない施設の入り口にある看板
  .incbin "data/actor_sprites/combo_score.4bpp"          @ 0x08A5C270, SpriteID: 0xA5BD, PlttID: 0, ブラックパンサー(ミニゲーム)の "COMBO:", "SCORE:"
  .incbin "data/actor_sprites/7AD3.4bpp"                 @ 0x08A5C370, SpriteID: 0x7AD3, PlttID: 167, 鍵のかかった青い扉
  .incbin "data/actor_sprites/7AD4.4bpp"                 @ 0x08A5D070, SpriteID: 0x7AD4, PlttID: 167, 鍵のかかった青い扉
  .incbin "data/actor_sprites/7AD5.4bpp"                 @ 0x08A5D930, SpriteID: 0x7AD5, PlttID: 167, 鍵のかかった青い扉
  .incbin "data/actor_sprites/7AD6.4bpp"                 @ 0x08A5E1F0, SpriteID: 0x7AD6, PlttID: 167, 鍵のかかった青い扉
  .incbin "data/actor_sprites/7AED.4bpp"                 @ 0x08A5EEF0, SpriteID: 0x7AED, PlttID: 167, 鍵のかかった青い扉
  .incbin "data/actor_sprites/7AF3.4bpp"                 @ 0x08A5FBF0, SpriteID: 0x7AF3, PlttID: 175, 鉄の扉(どこで使ってたか忘れた)
  .incbin "data/actor_sprites/7AF4.4bpp"                 @ 0x08A608F0, SpriteID: 0x7AF4, PlttID: 175, 鉄の扉(どこで使ってたか忘れた)
  .incbin "data/actor_sprites/7AF5.4bpp"                 @ 0x08A611B0, SpriteID: 0x7AF5, PlttID: 175, 鉄の扉(どこで使ってたか忘れた)
  .incbin "data/actor_sprites/7AF6.4bpp"                 @ 0x08A61A70, SpriteID: 0x7AF6, PlttID: 175, 鉄の扉(どこで使ってたか忘れた)
  .incbin "data/actor_sprites/7B0D.4bpp"                 @ 0x08A62770, SpriteID: 0x7B0D, PlttID: 175, 鉄の扉(どこで使ってたか忘れた)
  .incbin "data/actor_sprites/bee.4bpp"                  @ 0x08A63470, SpriteID: 0x9506, PlttID: 176, ビー
  .incbin "data/actor_sprites/22E7.4bpp"                 @ 0x08A64ED0, SpriteID: 0x22E7, PlttID: 83, 黒塗り
  .incbin "data/actor_sprites/fruit_shop_interior.4bpp"  @ 0x08A69550, SpriteID: 0x41B1, PlttID: 179, 果物屋の内装
  .incbin "data/actor_sprites/DC8E.4bpp"                 @ 0x08A69DB0, SpriteID: 0xDC8E, PlttID: 181, 木(太陽樹?, 森?)
  .incbin "data/actor_sprites/CDAB.4bpp"                 @ 0x08A6A5B0, SpriteID: 0xCDAB, PlttID: 187, チェンジ・マウスで渡れる木片
  .incbin "data/actor_sprites/dungeon_door.4bpp"         @ 0x08A6A8B0, SpriteID: 0xD962, PlttID: 188, タレット封印の扉(地下水路の入り口), 螺旋の塔の入り口, etc
  .incbin "data/actor_sprites/B044.4bpp"                 @ 0x08A6C8B0, SpriteID: 0xB044, PlttID: 42, 絨毯
  .incbin "data/actor_sprites/3668.4bpp"                 @ 0x08A6CBB0, SpriteID: 0x3668, PlttID: 195, なんかのエフェクト群
  .incbin "data/actor_sprites/ojama_bat.4bpp"            @ 0x08A6D7D0, SpriteID: 0x18A8, PlttID: 207, オジャマバット
  .incbin "data/actor_sprites/ojama_bat_counter.4bpp"    @ 0x08A6D9D0, SpriteID: 0x18A9, PlttID: 207, オジャマバットのカウンター?
  .incbin "data/actor_sprites/contact_switch.4bpp"       @ 0x08A6DC90, SpriteID: 0x2769, PlttID: 208, 接触スイッチ(+電球?)
  .incbin "data/actor_sprites/5B78.4bpp"                 @ 0x08A6DF30, SpriteID: 0x5B78, PlttID: 213, 天窓の光
  .incbin "data/actor_sprites/16F5.4bpp"                 @ 0x08A6E3B0, SpriteID: 0x16F5, PlttID: 97, 紋章ブロック
  .incbin "data/actor_sprites/F422.4bpp"                 @ 0x08A6F7B0, SpriteID: 0xF422, PlttID: 216, 砂のエフェクト?
  .incbin "data/actor_sprites/848F.4bpp"                 @ 0x08A72470, SpriteID: 0x848F, PlttID: 216, なんかのトゲ飛ばし？
  .incbin "data/actor_sprites/8490.4bpp"                 @ 0x08A72AF0, SpriteID: 0x8490, PlttID: 216, 砂に潜るエフェクト?
  .incbin "data/actor_sprites/D638.4bpp"                 @ 0x08A743B0, SpriteID: 0xD638, PlttID: 220, 暗黒の根
  .incbin "data/actor_sprites/EF69.4bpp"                 @ 0x08A7D5F0, SpriteID: 0xEF69, PlttID: 220, 暗黒の根
  .incbin "data/actor_sprites/5BA7.4bpp"                 @ 0x08A7D770, SpriteID: 0x5BA7, PlttID: 236, 天窓の光
  .incbin "data/actor_sprites/5BB7.4bpp"                 @ 0x08A7DBF0, SpriteID: 0x5BB7, PlttID: 239, 天窓の光
  .incbin "data/actor_sprites/bomb.4bpp"                 @ 0x08A7DF70, SpriteID: 0xE74B, PlttID: 0, (ガストの吐き出す)爆弾, ???, ダイナマイト
  .incbin "data/actor_sprites/start.4bpp"                @ 0x08A7EB70, SpriteID: 0x9A1F, PlttID: 242, "PUSH START BUTTON"
  .incbin "data/actor_sprites/C459.4bpp"                 @ 0x08A7F0F0, SpriteID: 0xC459, PlttID: 243, 太陽床
  .incbin "data/actor_sprites/DC07.4bpp"                 @ 0x08A7F4F0, SpriteID: 0xDC07, PlttID: 244, 天窓の光
  .incbin "data/actor_sprites/D45E.4bpp"                 @ 0x08A7F970, SpriteID: 0xD45E, PlttID: 247, 水たまり, スケルトン
  .incbin "data/actor_sprites/D85E.4bpp"                 @ 0x08A84930, SpriteID: 0xD85E, PlttID: 247, エフェクト群(電気っぽい)
  .incbin "data/actor_sprites/2817.4bpp"                 @ 0x08A86970, SpriteID: 0x2817, PlttID: 263, 大聖堂の水晶?
  .incbin "data/actor_sprites/EFD8.4bpp"                 @ 0x08A869B0, SpriteID: 0xEFD8, PlttID: 268, 0..9の数字とまだ何も数字が書かれていないパネルの絵
  .incbin "data/actor_sprites/8639.4bpp"                 @ 0x08A87A30, SpriteID: 0x8639, PlttID: 275, 爆発エフェクト
  .incbin "data/actor_sprites/otenko_00.4bpp"            @ 0x08A89A30, SpriteID: 0x97D3, PlttID: 279, おてんこさま(よく使うやつ)
  .incbin "data/actor_sprites/otenko_01.4bpp"            @ 0x08A8B4F0, SpriteID: 0x97D4, PlttID: 279, おてんこさま(あまり使わないやつ)
  .incbin "data/actor_sprites/C42D.4bpp"                 @ 0x08A8C330, SpriteID: 0xC42D, PlttID: 283, なんかの破片?
  .incbin "data/actor_sprites/0334.4bpp"                 @ 0x08A8C530, SpriteID: 0x0334, PlttID: 283, C42Dの破片の小さいやつ?
  .incbin "data/actor_sprites/9DFF.4bpp"                 @ 0x08A8C550, SpriteID: 0x9DFF, PlttID: 83, 黒塗り
  .incbin "data/actor_sprites/A152.4bpp"                 @ 0x08A8D150, SpriteID: 0xA152, PlttID: 284, なんかの魔方陣
  .incbin "data/actor_sprites/17C7.4bpp"                 @ 0x08A8D5D0, SpriteID: 0x17C7, PlttID: 287, 重量スイッチ
  .incbin "data/actor_sprites/210E.4bpp"                 @ 0x08A8DBD0, SpriteID: 0x210E, PlttID: 44, エフェクト
  .incbin "data/actor_sprites/210F.4bpp"                 @ 0x08A8DDD0, SpriteID: 0x210F, PlttID: 289, エフェクト(火花?)
  .incbin "data/actor_sprites/1FE0.4bpp"                 @ 0x08A8E490, SpriteID: 0x1FE0, PlttID: 83, 黒塗り
  .incbin "data/actor_sprites/2C1A.4bpp"                 @ 0x08A92690, SpriteID: 0x2C1A, PlttID: 300, 岩の角みたいな何か
  .incbin "data/actor_sprites/sword_axe.4bpp"            @ 0x08A92990, SpriteID: 0x5291, PlttID: 301, ソード,アックス
  .incbin "data/actor_sprites/weapon_funnel.4bpp"        @ 0x08A93190, SpriteID: 0x5292, PlttID: 301, スレイブソード, リンゴ(ダーイン)の出す剣
  .incbin "data/actor_sprites/boku_0.4bpp"               @ 0x08A93550, SpriteID: 0x9247, PlttID: 307, ボク
  .incbin "data/actor_sprites/boku_1.4bpp"               @ 0x08A94C10, SpriteID: 0xD4EA, PlttID: 307, ボク
  .incbin "data/actor_sprites/boku_2.4bpp"               @ 0x08A95C10, SpriteID: 0x47DE, PlttID: 307, ボク
  .incbin "data/actor_sprites/treadmill.4bpp"            @ 0x08A981D0, SpriteID: 0xC046, PlttID: 311, 暗黒ローンのお仕置き部屋の発電ベルドコンベア
  .incbin "data/actor_sprites/2097.4bpp"                 @ 0x08A993D0, SpriteID: 0x2097, PlttID: 312, 四則演算ブロック
  .incbin "data/actor_sprites/17C8.4bpp"                 @ 0x08A9DBD0, SpriteID: 0x17C8, PlttID: 287, 重量スイッチ
  .incbin "data/actor_sprites/lever_switch.4bpp"         @ 0x08A9E1D0, SpriteID: 0xBB68, PlttID: 313, レバースイッチ
  .incbin "data/actor_sprites/water_station.4bpp"        @ 0x08A9F050, SpriteID: 0xEED8, PlttID: 315, 砂漠の水汲み場
  .incbin "data/actor_sprites/505C.4bpp"                 @ 0x08A9FA50, SpriteID: 0x505C, PlttID: 316, 料理
  .incbin "data/actor_sprites/solar_station.4bpp"        @ 0x08A9FDD0, SpriteID: 0xA47C, PlttID: 317, 太陽スタンド
  .incbin "data/actor_sprites/DDE7.4bpp"                 @ 0x08AA0090, SpriteID: 0xDDE7, PlttID: 326, 天窓の光
  .incbin "data/actor_sprites/9E08.4bpp"                 @ 0x08AA0510, SpriteID: 0x9E08, PlttID: 329, 天窓の光
  .incbin "data/actor_sprites/panther_bonus.4bpp"        @ 0x08AA0990, SpriteID: 0xA8E7, PlttID: 0, ブラックパンサー(ミニゲーム)の "25", "10", "BONUS!"
  .incbin "data/actor_sprites/crow_0.4bpp"               @ 0x08AA0AF0, SpriteID: 0x5A6E, PlttID: 332, クロウ
  .incbin "data/actor_sprites/crow_1.4bpp"               @ 0x08AA25B0, SpriteID: 0x5A6F, PlttID: 332, クロウ
  .incbin "data/actor_sprites/44EE.4bpp"                 @ 0x08AA32D0, SpriteID: 0x44EE, PlttID: 337, なんかのブロックor柱
  .incbin "data/actor_sprites/5D7C.4bpp"                 @ 0x08AA38D0, SpriteID: 0x5D7C, PlttID: 338, 瓦礫
  .incbin "data/actor_sprites/B837.4bpp"                 @ 0x08AA40D0, SpriteID: 0xB837, PlttID: 339, わからん(ふしぎのぼうしのチュチュみたいな形)
  .incbin "data/actor_sprites/cube_iron.4bpp"            @ 0x08AA4C10, SpriteID: 0xE0C9, PlttID: 340, 鉄ブロック
  .incbin "data/actor_sprites/jormungandr_8203.4bpp"     @ 0x08AA5210, SpriteID: 0x8203, PlttID: 341, ヨルムンガンド
  .incbin "data/actor_sprites/jormungandr_8204.4bpp"     @ 0x08AA6B10, SpriteID: 0x8204, PlttID: 341, ヨルムンガンド
  .incbin "data/actor_sprites/wedge_8205.4bpp"           @ 0x08AA6DD0, SpriteID: 0x8205, PlttID: 350, ヨルムンガンドの楔
  .incbin "data/actor_sprites/wedge_8202.4bpp"           @ 0x08AA6FD0, SpriteID: 0x8202, PlttID: 350, ヨルムンガンドの楔
  .incbin "data/actor_sprites/jormungandr_8206.4bpp"     @ 0x08AA7650, SpriteID: 0x8206, PlttID: 341, ヨルムンガンドのタコ足
  .incbin "data/actor_sprites/jormungandr_8207.4bpp"     @ 0x08AA7950, SpriteID: 0x8207, PlttID: 341, ヨルムンガンドのタコ足
  .incbin "data/actor_sprites/DC38.4bpp"                 @ 0x08AA7A30, SpriteID: 0xDC38, PlttID: 83, 黒塗り
  .incbin "data/actor_sprites/8393.4bpp"                 @ 0x08AAB1D0, SpriteID: 0x8393, PlttID: 83, 黒塗り
  .incbin "data/actor_sprites/solar_bamboo.4bpp"         @ 0x08AB09D0, SpriteID: 0x066A, PlttID: 361, 太陽ダケ
  .incbin "data/actor_sprites/17C9.4bpp"                 @ 0x08AB0DD0, SpriteID: 0x17C9, PlttID: 287, 重量スイッチ
  .incbin "data/actor_sprites/DB6C.4bpp"                 @ 0x08AB0FD0, SpriteID: 0xDB6C, PlttID: 363, 壁?
  .incbin "data/actor_sprites/D0A3.4bpp"                 @ 0x08AB17D0, SpriteID: 0xD0A3, PlttID: 379, カンテラ
  .incbin "data/actor_sprites/beenest_broken.4bpp"       @ 0x08AB1A10, SpriteID: 0x9385, PlttID: 380
  .incbin "data/actor_sprites/bee_nest.4bpp"             @ 0x08AB1E90, SpriteID: 0xB626, PlttID: 380
  .incbin "data/actor_sprites/ghost.4bpp"                @ 0x08AB20F0, SpriteID: 0xD637, PlttID: 381, ゴースト, レイス
  .incbin "data/actor_sprites/E7EA.4bpp"                 @ 0x08AB49B0, SpriteID: 0xE7EA, PlttID: 386, エフェクト
  .incbin "data/actor_sprites/DFCF.4bpp"                 @ 0x08AB4A50, SpriteID: 0xDFCF, PlttID: 387, 棘付き根っこ
  .incbin "data/actor_sprites/0E48.4bpp"                 @ 0x08AB60D0, SpriteID: 0x0E48, PlttID: 388, 螺旋の塔の管理コンソール
  .incbin "data/actor_sprites/DC72.4bpp"                 @ 0x08AB6210, SpriteID: 0xDC72, PlttID: 181, 木の枝
  .incbin "data/actor_sprites/piledriver_center.4bpp"    @ 0x08AB6330, SpriteID: 0xC039, PlttID: 392, パイルドライバーの方陣の中心
  .incbin "data/actor_sprites/9803.4bpp"                 @ 0x08AB6B30, SpriteID: 0x9803, PlttID: 83, 黒塗り
  .incbin "data/actor_sprites/D56D.4bpp"                 @ 0x08ABC330, SpriteID: 0xD56D, PlttID: 404
  .incbin "data/actor_sprites/17CA.4bpp"                 @ 0x08ABC850, SpriteID: 0x17CA, PlttID: 287, 重量スイッチ
  .incbin "data/actor_sprites/spotlight.4bpp"            @ 0x08ABCF50, SpriteID: 0x3640, PlttID: 410, 天窓の光(汎用?)
  .incbin "data/actor_sprites/9B09.4bpp"                 @ 0x08ABEF50, SpriteID: 0x9B09, PlttID: 83, 黒塗り
  .incbin "data/actor_sprites/D454.4bpp"                 @ 0x08AC23D0, SpriteID: 0xD454, PlttID: 83, 黒塗り
  .incbin "data/actor_sprites/D636.4bpp"                 @ 0x08AC4D70, SpriteID: 0xD636, PlttID: 417, centipede & sandworm & serpent
  .incbin "data/actor_sprites/E769.4bpp"                 @ 0x08AC9850, SpriteID: 0xE769, PlttID: 418, sandworm & serpent
  .incbin "data/actor_sprites/E76A.4bpp"                 @ 0x08ACE9F0, SpriteID: 0xE76A, PlttID: 421, リッチ+の出す炎の蛇
  .incbin "data/actor_sprites/E76B.4bpp"                 @ 0x08ACEFF0, SpriteID: 0xE76B, PlttID: 421, リッチ+の出す炎の蛇
  .incbin "data/actor_sprites/rat.4bpp"                  @ 0x08AD07B0, SpriteID: 0xD495, PlttID: 29, チェンジマウスで変身するネズミ
  .incbin "data/actor_sprites/35C7.4bpp"                 @ 0x08AD15B0, SpriteID: 0x35C7, PlttID: 83, 黒塗り
  .incbin "data/actor_sprites/3B53.4bpp"                 @ 0x08AD5270, SpriteID: 0x3B53, PlttID: 83, 黒塗り
  .incbin "data/actor_sprites/pinpad.4bpp"               @ 0x08AD9DF0, SpriteID: 0x3C13, PlttID: 433, 時の家の暗証番号設定端末
  .incbin "data/actor_sprites/9D3F.4bpp"                 @ 0x08ADA9F0, SpriteID: 0x9D3F, PlttID: 435, "オフセット"(=offset), "20・20"(=32x32) というデバッグ用の文字列がある
  .incbin "data/actor_sprites/emblem_element.4bpp"       @ 0x08ADADB0, SpriteID: 0x7C99, PlttID: 438, 各属性のエンブレム(パズルの床に使うデカール?)
  .incbin "data/actor_sprites/B019.4bpp"                 @ 0x08ADB9D0, SpriteID: 0xB019, PlttID: 439, elevator lift
  .incbin "data/actor_sprites/DA09.4bpp"                 @ 0x08ADBE50, SpriteID: 0xDA09, PlttID: 439, elevator lift
  .incbin "data/actor_sprites/C3BD.4bpp"                 @ 0x08ADC450, SpriteID: 0xC3BD, PlttID: 439, elevator lift
  .incbin "data/actor_sprites/9462.4bpp"                 @ 0x08ADCA50, SpriteID: 0x9462, PlttID: 439, elevator lift
  .incbin "data/actor_sprites/75D6.4bpp"                 @ 0x08ADD050, SpriteID: 0x75D6, PlttID: 439, elevator lift
  .incbin "data/actor_sprites/7605.4bpp"                 @ 0x08ADD4D0, SpriteID: 0x7605, PlttID: 439, elevator lift
  .incbin "data/actor_sprites/octopus.4bpp"              @ 0x08ADD950, SpriteID: 0xD291, PlttID: 447
  .incbin "data/actor_sprites/water_silhouette.4bpp"     @ 0x08AE3F50, SpriteID: 0xD292, PlttID: 447, 多分オクトパスが水中にいるときのシルエット
  .incbin "data/actor_sprites/7C07.4bpp"                 @ 0x08AE4110, SpriteID: 0x7C07, PlttID: 83, 黒塗り
  .incbin "data/actor_sprites/FC07.4bpp"                 @ 0x08AE6510, SpriteID: 0xFC07, PlttID: 83, 黒塗り
  .incbin "data/actor_sprites/BC08.4bpp"                 @ 0x08AEB310, SpriteID: 0xBC08, PlttID: 83, 黒塗り
  .incbin "data/actor_sprites/generator.4bpp"            @ 0x08AEE910, SpriteID: 0xC038, PlttID: 451, パイルドライバーのジェネレータ
  .incbin "data/actor_sprites/1D78.4bpp"                 @ 0x08AF4590, SpriteID: 0x1D78, PlttID: 460, 天窓の光と、あと砂っぽい地面?
  .incbin "data/actor_sprites/6154.4bpp"                 @ 0x08AF5210, SpriteID: 0x6154, PlttID: 466, トーチ?
  .incbin "data/actor_sprites/weight_switch_17CB.4bpp"   @ 0x08AF5790, SpriteID: 0x17CB, PlttID: 287, 重量スイッチ
  .incbin "data/actor_sprites/BE6D.4bpp"                 @ 0x08AF5E90, SpriteID: 0xBE6D, PlttID: 83, 黒塗り
  .incbin "data/actor_sprites/CC88.4bpp"                 @ 0x08AF9E50, SpriteID: 0xCC88, PlttID: 467, 散った花びらのように見えるなにか
  .incbin "data/actor_sprites/desert_monolith.4bpp"      @ 0x08AF9ED0, SpriteID: 0x96B5, PlttID: 482, 砂漠の(3つの石版のことが書いてある)石碑
  .incbin "data/actor_sprites/dried_oasis.4bpp"          @ 0x08AFA4D0, SpriteID: 0x2C3D, PlttID: 498, 3つの石版を探す砂漠で砂漠入り口から1つ上のマップにある干上がったオアシス
  .incbin "data/actor_sprites/7BE7.4bpp"                 @ 0x08AFACD0, SpriteID: 0x7BE7, PlttID: 83, 黒塗り
  .incbin "data/actor_sprites/dog_0.4bpp"                @ 0x08AFFF50, SpriteID: 0xD635, PlttID: 501, 犬
  .incbin "data/actor_sprites/dog_1.4bpp"                @ 0x08B0DA50, SpriteID: 0xE369, PlttID: 501, 犬
  .incbin "data/actor_sprites/cockatrice_0.4bpp"         @ 0x08B10F50, SpriteID: 0x41CF, PlttID: 506, コカトリス
  .incbin "data/actor_sprites/cockatrice_1.4bpp"         @ 0x08B1B230, SpriteID: 0x43CF, PlttID: 506, コカトリス
  .incbin "data/actor_sprites/cube_wood.4bpp"            @ 0x08B23030, SpriteID: 0x9D40, PlttID: 509, 木ブロック
  .incbin "data/actor_sprites/cube_wood_debris_l.4bpp"   @ 0x08B23630, SpriteID: 0xA874, PlttID: 509, 木ブロックの破片(大)
  .incbin "data/actor_sprites/cube_wood_debris_s.4bpp"   @ 0x08B23830, SpriteID: 0xA875, PlttID: 509, 木ブロックの破片(小)
  .incbin "data/actor_sprites/golem.4bpp"                @ 0x08B23850, SpriteID: 0x5290, PlttID: 513, ゴーレム
  .incbin "data/actor_sprites/gun_spread.4bpp"           @ 0x08B2A1B0, SpriteID: 0x2110, PlttID: 44, ガンデルヘルのスプレッド
  .incbin "data/actor_sprites/2111.4bpp"                 @ 0x08B2B9B0, SpriteID: 0x2111, PlttID: 44, ガンデルソルのエフェクト?
  .incbin "data/actor_sprites/coffin.4bpp"               @ 0x08B2BB30, SpriteID: 0x2499, PlttID: 519, 全ての棺桶(エレファン含む), TODO: 画像を棺桶ごとに分けてパレットをちゃんと適用する
  .incbin "data/actor_sprites/elefan.4bpp"               @ 0x08B358F0, SpriteID: 0x249A, PlttID: 524, 棺桶獣エレファン(自走時?)
  .incbin "data/actor_sprites/5B54.4bpp"                 @ 0x08B37650, SpriteID: 0x5B54, PlttID: 529, ダイナマイトで壊せる壁
  .incbin "data/actor_sprites/cactus.4bpp"               @ 0x08B38250, SpriteID: 0x04B3, PlttID: 283, サボテン
  .incbin "data/actor_sprites/4FDA.4bpp"                 @ 0x08B38E50, SpriteID: 0x4FDA, PlttID: 531
  .incbin "data/actor_sprites/863A.4bpp"                 @ 0x08B39E50, SpriteID: 0x863A, PlttID: 275, 燃える(爆発?)エフェクト
  .incbin "data/actor_sprites/8638.4bpp"                 @ 0x08B3A670, SpriteID: 0x8638, PlttID: 275
  .incbin "data/actor_sprites/duneyrr.4bpp"              @ 0x08B3D110, SpriteID: 0x61F9, PlttID: 547, ドゥネイルの出すエフェクトや芋虫(ドゥネイル本体は別)
  .incbin "data/actor_sprites/2058.4bpp"                 @ 0x08B43130, SpriteID: 0x2058, PlttID: 558, 武器屋(シャイアンの店)の内装?
  .incbin "data/actor_sprites/7ACD.4bpp"                 @ 0x08B44370, SpriteID: 0x7ACD, PlttID: 559, ドア(木)
  .incbin "data/actor_sprites/7ACE.4bpp"                 @ 0x08B45070, SpriteID: 0x7ACE, PlttID: 559, ドア(木)
  .incbin "data/actor_sprites/7ACF.4bpp"                 @ 0x08B45930, SpriteID: 0x7ACF, PlttID: 559, ドア(木)
  .incbin "data/actor_sprites/7AD0.4bpp"                 @ 0x08B461F0, SpriteID: 0x7AD0, PlttID: 559, ドア(木)
  .incbin "data/actor_sprites/7AD1.4bpp"                 @ 0x08B46EF0, SpriteID: 0x7AD1, PlttID: 559, ドア(木)
  .incbin "data/actor_sprites/2E78.4bpp"                 @ 0x08B47BF0, SpriteID: 0x2E78, PlttID: 561, ドヴァリン
  .incbin "data/actor_sprites/2E79.4bpp"                 @ 0x08B4BED0, SpriteID: 0x2E79, PlttID: 561, ドヴァリン
  .incbin "data/actor_sprites/2E7A.4bpp"                 @ 0x08B4F2F0, SpriteID: 0x2E7A, PlttID: 561, ドヴァリン
  .incbin "data/actor_sprites/2E7B.4bpp"                 @ 0x08B50AF0, SpriteID: 0x2E7B, PlttID: 561, ドヴァリン
  .incbin "data/actor_sprites/2E7C.4bpp"                 @ 0x08B51570, SpriteID: 0x2E7C, PlttID: 561, ドヴァリン
  .incbin "data/actor_sprites/cube_rock.4bpp"            @ 0x08B51730, SpriteID: 0x9D41, PlttID: 573, 岩ブロック
  .incbin "data/actor_sprites/cube_rock_debris_l.4bpp"   @ 0x08B51D30, SpriteID: 0xA894, PlttID: 573, 岩ブロックの破片(大)
  .incbin "data/actor_sprites/cube_rock_debris_s.4bpp"   @ 0x08B51EB0, SpriteID: 0xA895, PlttID: 573, 岩ブロックの破片(小)
  .incbin "data/actor_sprites/7AC6.4bpp"                 @ 0x08B51ED0, SpriteID: 0x7AC6, PlttID: 83, 黒塗り
  .incbin "data/actor_sprites/cube_ice.4bpp"             @ 0x08B57470, SpriteID: 0x84EE, PlttID: 577, 氷ブロック
  .incbin "data/actor_sprites/ruins_pillar.4bpp"         @ 0x08B58670, SpriteID: 0x494E, PlttID: 593, 遺跡ステージ前半の柱
  .incbin "data/actor_sprites/7BE2.4bpp"                 @ 0x08B58C70, SpriteID: 0x7BE2, PlttID: 83, 黒塗り
  .incbin "data/actor_sprites/2EC0.4bpp"                 @ 0x08B5D490, SpriteID: 0x2EC0, PlttID: 594, 遺跡ステージの4人の燭台の床パネル?
  .incbin "data/actor_sprites/bat.4bpp"                  @ 0x08B5D910, SpriteID: 0xDA6D, PlttID: 610, バット
  .incbin "data/actor_sprites/shaian_spin_attack.4bpp"   @ 0x08B5E330, SpriteID: 0x354D, PlttID: 627, シャイアンの回転斬りのエフェクト
  .incbin "data/actor_sprites/shaian_ax.4bpp"            @ 0x08B5E830, SpriteID: 0x39A3, PlttID: 626, シャイアンが投げる斧
  .incbin "data/actor_sprites/level_up_indicator.4bpp"   @ 0x08B5E950, SpriteID: 0x1C1D, PlttID: 44
  .incbin "data/actor_sprites/over.4bpp"                 @ 0x08B5EE50, SpriteID: 0x654B, PlttID: 634, "GAMEOVER"
  .incbin "data/actor_sprites/weight_switch.4bpp"        @ 0x08B5F650, SpriteID: 0xB0BC, PlttID: 287, 重量スイッチ
  .incbin "data/actor_sprites/spike_ball.4bpp"           @ 0x08B5FF50, SpriteID: 0x24BA, PlttID: 637
  .incbin "data/actor_sprites/A945.4bpp"                 @ 0x08B60750, SpriteID: 0xA945, PlttID: 642, 落とし穴
  .incbin "data/actor_sprites/70EE.4bpp"                 @ 0x08B61050, SpriteID: 0x70EE, PlttID: 642, 落とし穴
  .incbin "data/actor_sprites/6F57.4bpp"                 @ 0x08B61950, SpriteID: 0x6F57, PlttID: 645, 1..12 までの数字パネル(boktai1のアセットが残ってるだけ？)
  .incbin "data/actor_sprites/tower_clock.4bpp"          @ 0x08B62CD0, SpriteID: 0x0C0A, PlttID: 646, 時計塔の時計
  .incbin "data/actor_sprites/2567.4bpp"                 @ 0x08B63CD0, SpriteID: 0x2567, PlttID: 647, 暗黒樹のもじゃもじゃ?
  .incbin "data/actor_sprites/DF0E.4bpp"                 @ 0x08B641D0, SpriteID: 0xDF0E, PlttID: 647, 暗黒樹の蔓
  .incbin "data/actor_sprites/1E15.4bpp"                 @ 0x08B643D0, SpriteID: 0x1E15, PlttID: 647, 暗黒樹の芽?
  .incbin "data/actor_sprites/0DDE.4bpp"                 @ 0x08B643F0, SpriteID: 0x0DDE, PlttID: 649
  .incbin "data/actor_sprites/84B4.4bpp"                 @ 0x08B64C50, SpriteID: 0x84B4, PlttID: 501, 火炎放射?
  .incbin "data/actor_sprites/96C1.4bpp"                 @ 0x08B678F0, SpriteID: 0x96C1, PlttID: 501
  .incbin "data/actor_sprites/96C2.4bpp"                 @ 0x08B6A050, SpriteID: 0x96C2, PlttID: 501
  .incbin "data/actor_sprites/0D44.4bpp"                 @ 0x08B6AB90, SpriteID: 0x0D44, PlttID: 83
  .incbin "data/actor_sprites/mimic.4bpp"                @ 0x08B6D8D0, SpriteID: 0x3876, PlttID: 650, 宝箱も兼ねる
  

Metaprites:
  Metaprite_0:
    metasprite Subsprite_0, 3, 40, 2, 0 @ 0
    metasprite Subsprite_3, 3, 40, 2, 40 @ 1
    metasprite Subsprite_6, 3, 40, 2, 80 @ 2
    metasprite Subsprite_9, 3, 40, 2, 120 @ 3
  Metaprite_4:
    metasprite Subsprite_12, 3, 48, 6, 160 @ 4
    metasprite Subsprite_15, 2, 20, 6, 208 @ 5
  Metaprite_6:
    metasprite Subsprite_17, 1, 4, 0, 228 @ 6
  Metaprite_7:
    metasprite Subsprite_18, 1, 16, 0, 232 @ 7
    metasprite Subsprite_19, 1, 16, 0, 248 @ 8
    metasprite Subsprite_20, 1, 16, 0, 264 @ 9
    metasprite Subsprite_21, 1, 16, 0, 280 @ 10
  Metaprite_11:
    metasprite Subsprite_22, 3, 12, 7, 296 @ 11
    metasprite Subsprite_25, 3, 12, 7, 308 @ 12
    metasprite Subsprite_28, 3, 12, 7, 320 @ 13
  Metaprite_14:
    metasprite Subsprite_31, 4, 36, 7, 332 @ 14
    metasprite Subsprite_35, 1, 16, 7, 368 @ 15
    metasprite Subsprite_36, 3, 12, 7, 384 @ 16
    metasprite Subsprite_39, 4, 36, 7, 396 @ 17
  Metaprite_18:
    metasprite Subsprite_43, 3, 11, 23, 432 @ 18
    metasprite Subsprite_46, 4, 18, 23, 443 @ 19
    metasprite Subsprite_50, 2, 10, 23, 461 @ 20
    metasprite Subsprite_52, 2, 12, 23, 471 @ 21
    metasprite Subsprite_54, 3, 13, 23, 483 @ 22
    metasprite Subsprite_57, 4, 15, 23, 496 @ 23
    metasprite Subsprite_61, 4, 15, 23, 511 @ 24
    metasprite Subsprite_65, 3, 14, 23, 526 @ 25
    metasprite Subsprite_68, 2, 12, 23, 540 @ 26
    metasprite Subsprite_70, 2, 10, 23, 552 @ 27
    metasprite Subsprite_72, 4, 15, 23, 562 @ 28
    metasprite Subsprite_76, 4, 18, 23, 577 @ 29
    metasprite Subsprite_80, 2, 12, 23, 595 @ 30
    metasprite Subsprite_82, 2, 10, 23, 607 @ 31
    metasprite Subsprite_84, 2, 10, 23, 617 @ 32
    metasprite Subsprite_86, 2, 12, 23, 627 @ 33
    metasprite Subsprite_88, 3, 14, 23, 639 @ 34
    metasprite Subsprite_91, 4, 15, 23, 653 @ 35
    metasprite Subsprite_95, 3, 11, 23, 668 @ 36
    metasprite Subsprite_98, 2, 24, 23, 679 @ 37
    metasprite Subsprite_100, 3, 11, 23, 703 @ 38
    metasprite Subsprite_103, 3, 10, 23, 714 @ 39
    metasprite Subsprite_106, 4, 18, 23, 724 @ 40
    metasprite Subsprite_110, 4, 18, 23, 742 @ 41
    metasprite Subsprite_114, 2, 24, 23, 760 @ 42
  Metaprite_43:
    metasprite Subsprite_116, 2, 24, 23, 784 @ 43
    metasprite Subsprite_118, 3, 14, 23, 808 @ 44
    metasprite Subsprite_121, 4, 18, 23, 822 @ 45
    metasprite Subsprite_125, 3, 12, 23, 840 @ 46
    metasprite Subsprite_128, 2, 10, 23, 852 @ 47
    metasprite Subsprite_130, 3, 14, 23, 862 @ 48
    metasprite Subsprite_133, 2, 24, 23, 876 @ 49
    metasprite Subsprite_135, 3, 16, 23, 900 @ 50
    metasprite Subsprite_138, 3, 16, 23, 916 @ 51
    metasprite Subsprite_141, 4, 15, 23, 932 @ 52
    metasprite Subsprite_145, 3, 11, 23, 947 @ 53
    metasprite Subsprite_148, 3, 11, 23, 958 @ 54
  Metaprite_55:
    metasprite Subsprite_151, 3, 14, 23, 969 @ 55
    metasprite Subsprite_154, 3, 14, 23, 983 @ 56
    metasprite Subsprite_157, 3, 28, 23, 997 @ 57
    metasprite Subsprite_160, 3, 24, 23, 1025 @ 58
    metasprite Subsprite_163, 2, 12, 23, 1049 @ 59
    metasprite Subsprite_165, 4, 18, 23, 1061 @ 60
    metasprite Subsprite_169, 3, 28, 23, 1079 @ 61
    metasprite Subsprite_172, 3, 28, 23, 1107 @ 62
  Metaprite_63:
    metasprite Subsprite_175, 4, 36, 28, 1135 @ 63
    metasprite Subsprite_179, 3, 24, 28, 1171 @ 64
    metasprite Subsprite_182, 3, 24, 28, 1195 @ 65
    metasprite Subsprite_185, 3, 8, 28, 1219 @ 66
  Metaprite_67:
    metasprite Subsprite_188, 3, 8, 29, 1227 @ 67
    metasprite Subsprite_191, 2, 6, 29, 1235 @ 68
    metasprite Subsprite_193, 3, 8, 29, 1241 @ 69
    metasprite Subsprite_196, 3, 6, 29, 1249 @ 70
    metasprite Subsprite_199, 3, 8, 29, 1255 @ 71
    metasprite Subsprite_202, 2, 6, 29, 1263 @ 72
    metasprite Subsprite_204, 1, 4, 29, 1269 @ 73
    metasprite Subsprite_205, 1, 4, 29, 1273 @ 74
    metasprite Subsprite_206, 1, 4, 29, 1277 @ 75
    metasprite Subsprite_207, 1, 4, 29, 1281 @ 76
    metasprite Subsprite_208, 1, 4, 29, 1285 @ 77
    metasprite Subsprite_209, 1, 4, 29, 1289 @ 78
    metasprite Subsprite_210, 1, 16, 29, 1293 @ 79
    metasprite Subsprite_211, 1, 16, 29, 1309 @ 80
    metasprite Subsprite_212, 4, 30, 29, 1325 @ 81
  Metaprite_82:
    metasprite Subsprite_216, 1, 32, 42, 1355 @ 82
    metasprite Subsprite_217, 3, 40, 42, 1387 @ 83
    metasprite Subsprite_220, 1, 32, 42, 1427 @ 84
  Metaprite_85:
    metasprite Subsprite_221, 1, 32, 42, 1459 @ 85
    metasprite Subsprite_222, 2, 20, 42, 1491 @ 86
    metasprite Subsprite_224, 4, 18, 42, 1511 @ 87
  Metaprite_88:
    metasprite Subsprite_228, 1, 32, 42, 1529 @ 88
    metasprite Subsprite_229, 2, 20, 42, 1561 @ 89
    metasprite Subsprite_231, 4, 18, 42, 1581 @ 90
  Metaprite_91:
    metasprite Subsprite_235, 1, 32, 42, 1599 @ 91
    metasprite Subsprite_236, 3, 40, 42, 1631 @ 92
    metasprite Subsprite_239, 1, 32, 42, 1671 @ 93
  Metaprite_94:
    metasprite Subsprite_240, 1, 32, 42, 1703 @ 94
    metasprite Subsprite_241, 3, 40, 42, 1735 @ 95
    metasprite Subsprite_244, 1, 32, 42, 1775 @ 96
  Metaprite_97:
    metasprite Subsprite_245, 1, 1, 44, 1807 @ 97
    metasprite Subsprite_246, 1, 1, 44, 1808 @ 98
    metasprite Subsprite_247, 1, 1, 44, 1809 @ 99
    metasprite Subsprite_248, 1, 1, 44, 1810 @ 100
  Metaprite_101:
    metasprite Subsprite_249, 2, 36, 51, 1811 @ 101
  Metaprite_102:
    metasprite Subsprite_251, 3, 40, 52, 1847 @ 102
  Metaprite_103:
    metasprite Subsprite_254, 4, 36, 53, 1887 @ 103
  Metaprite_104:
    metasprite Subsprite_258, 3, 8, 54, 1923 @ 104
    metasprite Subsprite_261, 3, 8, 54, 1931 @ 105
  Metaprite_106:
    metasprite Subsprite_264, 1, 16, 56, 1939 @ 106
  Metaprite_107:
    metasprite Subsprite_265, 1, 64, 60, 1955 @ 107
  Metaprite_108:
    metasprite Subsprite_266, 1, 64, 61, 2019 @ 108
  Metaprite_109:
    metasprite Subsprite_267, 1, 4, 62, 2083 @ 109
    metasprite Subsprite_268, 1, 4, 62, 2087 @ 110
    metasprite Subsprite_269, 2, 6, 62, 2091 @ 111
    metasprite Subsprite_271, 3, 8, 62, 2097 @ 112
    metasprite Subsprite_274, 3, 8, 62, 2105 @ 113
    metasprite Subsprite_277, 3, 8, 62, 2113 @ 114
    metasprite Subsprite_280, 3, 12, 62, 2121 @ 115
    metasprite Subsprite_283, 3, 12, 62, 2133 @ 116
    metasprite Subsprite_286, 3, 12, 62, 2145 @ 117
    metasprite Subsprite_289, 1, 16, 62, 2157 @ 118
    metasprite Subsprite_290, 1, 16, 62, 2173 @ 119
    metasprite Subsprite_291, 1, 16, 62, 2189 @ 120
    metasprite Subsprite_292, 1, 16, 62, 2205 @ 121
    metasprite Subsprite_293, 1, 16, 62, 2221 @ 122
    metasprite Subsprite_294, 1, 16, 62, 2237 @ 123
    metasprite Subsprite_295, 1, 16, 62, 2253 @ 124
    metasprite Subsprite_296, 1, 16, 62, 2269 @ 125
    metasprite Subsprite_297, 1, 16, 62, 2285 @ 126
  Metaprite_127:
    metasprite Subsprite_298, 3, 48, 64, 2301 @ 127
    metasprite Subsprite_301, 3, 48, 64, 2349 @ 128
    metasprite Subsprite_304, 3, 48, 64, 2397 @ 129
    metasprite Subsprite_307, 3, 48, 64, 2445 @ 130
  Metaprite_131:
    metasprite Subsprite_310, 3, 28, 66, 2493 @ 131
    metasprite Subsprite_313, 3, 28, 66, 2521 @ 132
    metasprite Subsprite_316, 3, 28, 66, 2549 @ 133
    metasprite Subsprite_319, 3, 28, 66, 2577 @ 134
    metasprite Subsprite_322, 3, 28, 66, 2605 @ 135
    metasprite Subsprite_325, 3, 28, 66, 2633 @ 136
    metasprite Subsprite_328, 3, 28, 66, 2661 @ 137
    metasprite Subsprite_331, 3, 28, 66, 2689 @ 138
    metasprite Subsprite_334, 3, 28, 66, 2717 @ 139
    metasprite Subsprite_337, 4, 36, 66, 2745 @ 140
    metasprite Subsprite_341, 4, 36, 66, 2781 @ 141
    metasprite Subsprite_345, 1, 32, 66, 2817 @ 142
  Metaprite_143:
    metasprite Subsprite_346, 3, 7, 71, 2849 @ 143
    metasprite Subsprite_349, 3, 7, 71, 2856 @ 144
    metasprite Subsprite_352, 1, 8, 71, 2863 @ 145
    metasprite Subsprite_353, 3, 7, 71, 2871 @ 146
  Metaprite_147:
    metasprite Subsprite_356, 1, 16, 72, 2878 @ 147
    metasprite Subsprite_357, 1, 16, 72, 2894 @ 148
    metasprite Subsprite_358, 3, 4, 72, 2910 @ 149
    metasprite Subsprite_361, 1, 16, 72, 2914 @ 150
    metasprite Subsprite_362, 1, 16, 72, 2930 @ 151
    metasprite Subsprite_363, 3, 4, 72, 2946 @ 152
    metasprite Subsprite_366, 3, 7, 72, 2950 @ 153
    metasprite Subsprite_369, 2, 10, 72, 2957 @ 154
    metasprite Subsprite_371, 2, 5, 72, 2967 @ 155
    metasprite Subsprite_373, 1, 16, 72, 2972 @ 156
    metasprite Subsprite_374, 1, 16, 72, 2988 @ 157
    metasprite Subsprite_375, 3, 4, 72, 3004 @ 158
    metasprite Subsprite_378, 1, 16, 72, 3008 @ 159
    metasprite Subsprite_379, 2, 20, 72, 3024 @ 160
    metasprite Subsprite_381, 3, 14, 72, 3044 @ 161
    metasprite Subsprite_384, 1, 4, 72, 3058 @ 162
    metasprite Subsprite_385, 3, 6, 72, 3062 @ 163
    metasprite Subsprite_388, 1, 4, 72, 3068 @ 164
    metasprite Subsprite_389, 3, 6, 72, 3072 @ 165
    metasprite Subsprite_392, 2, 6, 72, 3078 @ 166
    metasprite Subsprite_394, 1, 1, 72, 3084 @ 167
    metasprite Subsprite_395, 1, 1, 72, 3085 @ 168
    metasprite Subsprite_396, 1, 4, 72, 3086 @ 169
    metasprite Subsprite_397, 1, 2, 72, 3090 @ 170
    metasprite Subsprite_398, 1, 4, 72, 3092 @ 171
    metasprite Subsprite_399, 1, 2, 72, 3096 @ 172
    metasprite Subsprite_400, 1, 4, 72, 3098 @ 173
    metasprite Subsprite_401, 1, 4, 72, 3102 @ 174
    metasprite Subsprite_402, 1, 2, 72, 3106 @ 175
    metasprite Subsprite_403, 1, 2, 72, 3108 @ 176
    metasprite Subsprite_404, 1, 16, 72, 3110 @ 177
    metasprite Subsprite_405, 1, 16, 72, 3126 @ 178
    metasprite Subsprite_406, 1, 16, 72, 3142 @ 179
  Metaprite_180:
    metasprite Subsprite_407, 1, 8, 73, 3158 @ 180
    metasprite Subsprite_408, 1, 8, 73, 3166 @ 181
  Metaprite_182:
    metasprite Subsprite_409, 3, 48, 79, 3174 @ 182
  Metaprite_183:
    metasprite Subsprite_412, 3, 48, 80, 3222 @ 183
    metasprite Subsprite_415, 3, 48, 80, 3270 @ 184
  Metaprite_185:
    metasprite Subsprite_418, 4, 36, 83, 3318 @ 185
    metasprite Subsprite_422, 4, 36, 83, 3354 @ 186
    metasprite Subsprite_426, 3, 26, 83, 3390 @ 187
  Metaprite_188:
    metasprite Subsprite_429, 1, 4, 86, 3416 @ 188
    metasprite Subsprite_430, 1, 4, 86, 3420 @ 189
    metasprite Subsprite_431, 1, 4, 86, 3424 @ 190
    metasprite Subsprite_432, 1, 4, 86, 3428 @ 191
    metasprite Subsprite_433, 1, 4, 86, 3432 @ 192
    metasprite Subsprite_434, 1, 4, 86, 3436 @ 193
    metasprite Subsprite_435, 1, 4, 86, 3440 @ 194
    metasprite Subsprite_436, 1, 4, 86, 3444 @ 195
  Metaprite_196:
    metasprite Subsprite_437, 2, 12, 87, 3448 @ 196
    metasprite Subsprite_439, 2, 12, 87, 3460 @ 197
    metasprite Subsprite_441, 2, 12, 87, 3472 @ 198
    metasprite Subsprite_443, 2, 12, 87, 3484 @ 199
    metasprite Subsprite_445, 2, 12, 87, 3496 @ 200
    metasprite Subsprite_447, 2, 12, 87, 3508 @ 201
    metasprite Subsprite_449, 2, 12, 87, 3520 @ 202
    metasprite Subsprite_451, 2, 12, 87, 3532 @ 203
    metasprite Subsprite_453, 2, 12, 87, 3544 @ 204
    metasprite Subsprite_455, 2, 12, 87, 3556 @ 205
    metasprite Subsprite_457, 2, 12, 87, 3568 @ 206
    metasprite Subsprite_459, 2, 12, 87, 3580 @ 207
    metasprite Subsprite_461, 2, 12, 87, 3592 @ 208
    metasprite Subsprite_463, 2, 12, 87, 3604 @ 209
    metasprite Subsprite_465, 2, 12, 87, 3616 @ 210
    metasprite Subsprite_467, 2, 12, 87, 3628 @ 211
  Metaprite_212:
    metasprite Subsprite_469, 1, 8, 89, 3640 @ 212
    metasprite Subsprite_470, 1, 8, 89, 3648 @ 213
    metasprite Subsprite_471, 1, 8, 89, 3656 @ 214
    metasprite Subsprite_472, 1, 8, 89, 3664 @ 215
    metasprite Subsprite_473, 1, 8, 89, 3672 @ 216
    metasprite Subsprite_474, 1, 8, 89, 3680 @ 217
    metasprite Subsprite_475, 1, 8, 89, 3688 @ 218
    metasprite Subsprite_476, 3, 7, 89, 3696 @ 219
  Metaprite_220:
    metasprite Subsprite_479, 1, 16, 91, 3703 @ 220
  Metaprite_221:
    metasprite Subsprite_480, 3, 10, 0, 3719 @ 221
    metasprite Subsprite_483, 1, 16, 0, 3729 @ 222
    metasprite Subsprite_484, 1, 16, 0, 3745 @ 223
    metasprite Subsprite_485, 2, 12, 0, 3761 @ 224
    metasprite Subsprite_487, 1, 16, 0, 3773 @ 225
    metasprite Subsprite_488, 1, 4, 0, 3789 @ 226
    metasprite Subsprite_489, 3, 12, 0, 3793 @ 227
    metasprite Subsprite_492, 1, 16, 0, 3805 @ 228
  Metaprite_229:
    metasprite Subsprite_493, 1, 1, 0, 3821 @ 229
    metasprite Subsprite_494, 1, 1, 0, 3822 @ 230
    metasprite Subsprite_495, 1, 1, 0, 3823 @ 231
    metasprite Subsprite_496, 1, 1, 0, 3824 @ 232
    metasprite Subsprite_497, 1, 1, 0, 3825 @ 233
    metasprite Subsprite_498, 1, 1, 0, 3826 @ 234
    metasprite Subsprite_499, 1, 1, 0, 3827 @ 235
    metasprite Subsprite_500, 1, 1, 0, 3828 @ 236
    metasprite Subsprite_501, 1, 1, 0, 3829 @ 237
    metasprite Subsprite_502, 1, 1, 0, 3830 @ 238
    metasprite Subsprite_503, 1, 1, 0, 3831 @ 239
  Metaprite_240:
    metasprite Subsprite_504, 4, 36, 83, 3832 @ 240
    metasprite Subsprite_508, 4, 36, 83, 3868 @ 241
    metasprite Subsprite_512, 4, 30, 83, 3904 @ 242
    metasprite Subsprite_516, 4, 36, 83, 3934 @ 243
    metasprite Subsprite_520, 4, 36, 83, 3970 @ 244
    metasprite Subsprite_524, 4, 36, 83, 4006 @ 245
    metasprite Subsprite_528, 4, 36, 83, 4042 @ 246
    metasprite Subsprite_532, 4, 36, 83, 4078 @ 247
    metasprite Subsprite_536, 4, 36, 83, 4114 @ 248
  Metaprite_249:
    metasprite Subsprite_540, 1, 4, 92, 4150 @ 249
    metasprite Subsprite_541, 1, 4, 92, 4154 @ 250
    metasprite Subsprite_542, 1, 4, 92, 4158 @ 251
    metasprite Subsprite_543, 1, 4, 92, 4162 @ 252
    metasprite Subsprite_544, 1, 4, 92, 4166 @ 253
    metasprite Subsprite_545, 1, 4, 92, 4170 @ 254
    metasprite Subsprite_546, 1, 4, 92, 4174 @ 255
    metasprite Subsprite_547, 1, 4, 92, 4178 @ 256
    metasprite Subsprite_548, 1, 4, 92, 4182 @ 257
    metasprite Subsprite_549, 1, 4, 92, 4186 @ 258
    metasprite Subsprite_550, 1, 4, 92, 4190 @ 259
    metasprite Subsprite_551, 1, 4, 92, 4194 @ 260
    metasprite Subsprite_552, 1, 4, 92, 4198 @ 261
    metasprite Subsprite_553, 1, 4, 92, 4202 @ 262
    metasprite Subsprite_554, 1, 4, 92, 4206 @ 263
    metasprite Subsprite_555, 1, 4, 92, 4210 @ 264
    metasprite Subsprite_556, 1, 4, 92, 4214 @ 265
    metasprite Subsprite_557, 1, 4, 92, 4218 @ 266
    metasprite Subsprite_558, 1, 4, 92, 4222 @ 267
    metasprite Subsprite_559, 1, 4, 92, 4226 @ 268
    metasprite Subsprite_560, 1, 4, 92, 4230 @ 269
    metasprite Subsprite_561, 1, 4, 92, 4234 @ 270
    metasprite Subsprite_562, 1, 4, 92, 4238 @ 271
    metasprite Subsprite_563, 1, 4, 92, 4242 @ 272
    metasprite Subsprite_564, 1, 4, 92, 4246 @ 273
    metasprite Subsprite_565, 1, 4, 92, 4250 @ 274
    metasprite Subsprite_566, 1, 4, 92, 4254 @ 275
    metasprite Subsprite_567, 1, 4, 92, 4258 @ 276
    metasprite Subsprite_568, 1, 4, 92, 4262 @ 277
    metasprite Subsprite_569, 1, 4, 92, 4266 @ 278
    metasprite Subsprite_570, 1, 4, 92, 4270 @ 279
    metasprite Subsprite_571, 1, 4, 92, 4274 @ 280
    metasprite Subsprite_572, 1, 4, 92, 4278 @ 281
    metasprite Subsprite_573, 1, 4, 92, 4282 @ 282
    metasprite Subsprite_574, 1, 4, 92, 4286 @ 283
    metasprite Subsprite_575, 1, 4, 92, 4290 @ 284
    metasprite Subsprite_576, 1, 4, 92, 4294 @ 285
    metasprite Subsprite_577, 1, 4, 92, 4298 @ 286
    metasprite Subsprite_578, 1, 4, 92, 4302 @ 287
    metasprite Subsprite_579, 1, 4, 92, 4306 @ 288
    metasprite Subsprite_580, 1, 4, 92, 4310 @ 289
    metasprite Subsprite_581, 1, 4, 92, 4314 @ 290
  Metaprite_291:
    metasprite Subsprite_582, 3, 8, 95, 4318 @ 291
    metasprite Subsprite_585, 2, 20, 95, 4326 @ 292
    metasprite Subsprite_587, 4, 30, 95, 4346 @ 293
  Metaprite_294:
    metasprite Subsprite_591, 1, 16, 97, 4376 @ 294
    metasprite Subsprite_592, 1, 16, 97, 4392 @ 295
    metasprite Subsprite_593, 1, 16, 97, 4408 @ 296
    metasprite Subsprite_594, 1, 16, 97, 4424 @ 297
    metasprite Subsprite_595, 1, 16, 97, 4440 @ 298
    metasprite Subsprite_596, 1, 16, 97, 4456 @ 299
    metasprite Subsprite_597, 1, 16, 97, 4472 @ 300
    metasprite Subsprite_598, 1, 16, 97, 4488 @ 301
    metasprite Subsprite_599, 1, 16, 97, 4504 @ 302
    metasprite Subsprite_600, 1, 16, 97, 4520 @ 303
    metasprite Subsprite_601, 1, 16, 97, 4536 @ 304
    metasprite Subsprite_602, 1, 16, 97, 4552 @ 305
    metasprite Subsprite_603, 1, 16, 97, 4568 @ 306
    metasprite Subsprite_604, 1, 16, 97, 4584 @ 307
    metasprite Subsprite_605, 1, 16, 97, 4600 @ 308
    metasprite Subsprite_606, 1, 16, 97, 4616 @ 309
    metasprite Subsprite_607, 1, 16, 97, 4632 @ 310
    metasprite Subsprite_608, 1, 16, 97, 4648 @ 311
    metasprite Subsprite_609, 1, 16, 97, 4664 @ 312
    metasprite Subsprite_610, 1, 16, 97, 4680 @ 313
    metasprite Subsprite_611, 1, 16, 97, 4696 @ 314
    metasprite Subsprite_612, 1, 16, 97, 4712 @ 315
    metasprite Subsprite_613, 1, 16, 97, 4728 @ 316
    metasprite Subsprite_614, 1, 16, 97, 4744 @ 317
    metasprite Subsprite_615, 1, 16, 97, 4760 @ 318
  Metaprite_319:
    metasprite Subsprite_616, 1, 64, 97, 4776 @ 319
  Metaprite_320:
    metasprite Subsprite_617, 1, 2, 0, 4840 @ 320
    metasprite Subsprite_618, 1, 2, 0, 4842 @ 321
    metasprite Subsprite_619, 1, 2, 0, 4844 @ 322
    metasprite Subsprite_620, 1, 2, 0, 4846 @ 323
    metasprite Subsprite_621, 1, 1, 0, 4848 @ 324
    metasprite Subsprite_622, 1, 2, 0, 4849 @ 325
    metasprite Subsprite_623, 1, 1, 0, 4851 @ 326
    metasprite Subsprite_624, 1, 2, 0, 4852 @ 327
    metasprite Subsprite_625, 1, 2, 0, 4854 @ 328
    metasprite Subsprite_626, 1, 1, 0, 4856 @ 329
  Metaprite_330:
    metasprite Subsprite_627, 1, 8, 0, 4857 @ 330
    metasprite Subsprite_628, 1, 8, 0, 4865 @ 331
    metasprite Subsprite_629, 1, 8, 0, 4873 @ 332
    metasprite Subsprite_630, 1, 8, 0, 4881 @ 333
    metasprite Subsprite_631, 1, 8, 0, 4889 @ 334
    metasprite Subsprite_632, 1, 8, 0, 4897 @ 335
    metasprite Subsprite_633, 1, 8, 0, 4905 @ 336
  Metaprite_337:
    metasprite Subsprite_634, 4, 24, 112, 4913 @ 337
  Metaprite_338:
    metasprite Subsprite_638, 2, 20, 89, 4937 @ 338
  Metaprite_339:
    metasprite Subsprite_640, 1, 32, 115, 4957 @ 339
    metasprite Subsprite_641, 1, 32, 115, 4989 @ 340
    metasprite Subsprite_642, 1, 32, 115, 5021 @ 341
  Metaprite_342:
    metasprite Subsprite_643, 1, 32, 116, 5053 @ 342
  Metaprite_343:
    metasprite Subsprite_644, 3, 40, 120, 5085 @ 343
    metasprite Subsprite_647, 4, 30, 120, 5125 @ 344
  Metaprite_345:
    metasprite Subsprite_651, 1, 4, 125, 5155 @ 345
    metasprite Subsprite_652, 3, 8, 125, 5159 @ 346
    metasprite Subsprite_655, 3, 12, 125, 5167 @ 347
    metasprite Subsprite_658, 1, 16, 125, 5179 @ 348
    metasprite Subsprite_659, 1, 16, 125, 5195 @ 349
    metasprite Subsprite_660, 1, 16, 125, 5211 @ 350
    metasprite Subsprite_661, 1, 16, 125, 5227 @ 351
    metasprite Subsprite_662, 1, 16, 125, 5243 @ 352
    metasprite Subsprite_663, 3, 11, 125, 5259 @ 353
  Metaprite_354:
    metasprite Subsprite_666, 1, 1, 130, 5270 @ 354
    metasprite Subsprite_667, 1, 1, 130, 5271 @ 355
    metasprite Subsprite_668, 1, 1, 130, 5272 @ 356
    metasprite Subsprite_669, 1, 1, 130, 5273 @ 357
    metasprite Subsprite_670, 1, 1, 130, 5274 @ 358
    metasprite Subsprite_671, 1, 1, 130, 5275 @ 359
  Metaprite_360:
    metasprite Subsprite_672, 3, 40, 139, 5276 @ 360
  Metaprite_361:
    metasprite Subsprite_675, 4, 24, 142, 5316 @ 361
  Metaprite_362:
    metasprite Subsprite_679, 1, 16, 143, 5340 @ 362
    metasprite Subsprite_680, 1, 16, 143, 5356 @ 363
    metasprite Subsprite_681, 1, 16, 143, 5372 @ 364
    metasprite Subsprite_682, 1, 16, 143, 5388 @ 365
    metasprite Subsprite_683, 1, 16, 143, 5404 @ 366
    metasprite Subsprite_684, 1, 16, 143, 5420 @ 367
    metasprite Subsprite_685, 3, 14, 143, 5436 @ 368
    metasprite Subsprite_688, 1, 16, 143, 5450 @ 369
    metasprite Subsprite_689, 1, 16, 143, 5466 @ 370
    metasprite Subsprite_690, 3, 13, 143, 5482 @ 371
    metasprite Subsprite_693, 3, 11, 143, 5495 @ 372
    metasprite Subsprite_696, 1, 16, 143, 5506 @ 373
    metasprite Subsprite_697, 1, 16, 143, 5522 @ 374
    metasprite Subsprite_698, 1, 16, 143, 5538 @ 375
    metasprite Subsprite_699, 1, 16, 143, 5554 @ 376
    metasprite Subsprite_700, 1, 16, 143, 5570 @ 377
  Metaprite_378:
    metasprite Subsprite_701, 1, 32, 146, 5586 @ 378
    metasprite Subsprite_702, 1, 32, 146, 5618 @ 379
    metasprite Subsprite_703, 1, 32, 146, 5650 @ 380
  Metaprite_381:
    metasprite Subsprite_704, 3, 12, 147, 5682 @ 381
    metasprite Subsprite_707, 3, 12, 147, 5694 @ 382
    metasprite Subsprite_710, 3, 12, 147, 5706 @ 383
    metasprite Subsprite_713, 1, 16, 147, 5718 @ 384
    metasprite Subsprite_714, 1, 16, 147, 5734 @ 385
    metasprite Subsprite_715, 3, 14, 147, 5750 @ 386
    metasprite Subsprite_718, 3, 12, 147, 5764 @ 387
    metasprite Subsprite_721, 3, 14, 147, 5776 @ 388
    metasprite Subsprite_724, 3, 14, 147, 5790 @ 389
    metasprite Subsprite_727, 3, 12, 147, 5804 @ 390
    metasprite Subsprite_730, 2, 12, 147, 5816 @ 391
    metasprite Subsprite_732, 2, 10, 147, 5828 @ 392
    metasprite Subsprite_734, 1, 16, 147, 5838 @ 393
    metasprite Subsprite_735, 3, 12, 147, 5854 @ 394
    metasprite Subsprite_738, 3, 12, 147, 5866 @ 395
    metasprite Subsprite_741, 3, 14, 147, 5878 @ 396
  Metaprite_397:
    metasprite Subsprite_744, 1, 4, 147, 5892 @ 397
  Metaprite_398:
    metasprite Subsprite_745, 1, 1, 147, 5896 @ 398
    metasprite Subsprite_746, 1, 1, 147, 5897 @ 399
    metasprite Subsprite_747, 1, 1, 147, 5898 @ 400
  Metaprite_401:
    metasprite Subsprite_748, 3, 48, 83, 5899 @ 401
    metasprite Subsprite_751, 3, 48, 83, 5947 @ 402
    metasprite Subsprite_754, 3, 48, 83, 5995 @ 403
    metasprite Subsprite_757, 3, 48, 83, 6043 @ 404
    metasprite Subsprite_760, 3, 48, 83, 6091 @ 405
    metasprite Subsprite_763, 3, 48, 83, 6139 @ 406
    metasprite Subsprite_766, 3, 48, 83, 6187 @ 407
    metasprite Subsprite_769, 3, 48, 83, 6235 @ 408
  Metaprite_409:
    metasprite Subsprite_772, 1, 16, 44, 6283 @ 409
    metasprite Subsprite_773, 1, 16, 44, 6299 @ 410
  Metaprite_411:
    metasprite Subsprite_774, 4, 36, 151, 6315 @ 411
    metasprite Subsprite_778, 2, 24, 151, 6351 @ 412
    metasprite Subsprite_780, 3, 32, 151, 6375 @ 413
    metasprite Subsprite_783, 3, 14, 151, 6407 @ 414
  Metaprite_415:
    metasprite Subsprite_786, 4, 36, 95, 6421 @ 415
    metasprite Subsprite_790, 3, 48, 95, 6457 @ 416
    metasprite Subsprite_793, 1, 64, 95, 6505 @ 417
  Metaprite_418:
    metasprite Subsprite_794, 1, 64, 153, 6569 @ 418
  Metaprite_419:
    metasprite Subsprite_795, 3, 48, 83, 6633 @ 419
    metasprite Subsprite_798, 3, 48, 83, 6681 @ 420
    metasprite Subsprite_801, 3, 48, 83, 6729 @ 421
    metasprite Subsprite_804, 4, 30, 83, 6777 @ 422
    metasprite Subsprite_808, 4, 30, 83, 6807 @ 423
    metasprite Subsprite_812, 3, 48, 83, 6837 @ 424
    metasprite Subsprite_815, 3, 48, 83, 6885 @ 425
    metasprite Subsprite_818, 3, 48, 83, 6933 @ 426
    metasprite Subsprite_821, 3, 48, 83, 6981 @ 427
    metasprite Subsprite_824, 3, 48, 83, 7029 @ 428
  Metaprite_429:
    metasprite Subsprite_827, 2, 6, 165, 7077 @ 429
    metasprite Subsprite_829, 2, 24, 165, 7083 @ 430
    metasprite Subsprite_831, 1, 32, 165, 7107 @ 431
    metasprite Subsprite_832, 1, 32, 165, 7139 @ 432
    metasprite Subsprite_833, 1, 32, 165, 7171 @ 433
    metasprite Subsprite_834, 1, 32, 165, 7203 @ 434
    metasprite Subsprite_835, 1, 32, 165, 7235 @ 435
  Metaprite_436:
    metasprite Subsprite_836, 1, 8, 166, 7267 @ 436
  Metaprite_437:
    metasprite Subsprite_837, 1, 4, 0, 7275 @ 437
    metasprite Subsprite_838, 1, 4, 0, 7279 @ 438
  Metaprite_439:
    metasprite Subsprite_839, 1, 32, 167, 7283 @ 439
    metasprite Subsprite_840, 3, 40, 167, 7315 @ 440
    metasprite Subsprite_843, 1, 32, 167, 7355 @ 441
  Metaprite_442:
    metasprite Subsprite_844, 1, 32, 167, 7387 @ 442
    metasprite Subsprite_845, 2, 20, 167, 7419 @ 443
    metasprite Subsprite_847, 4, 18, 167, 7439 @ 444
  Metaprite_445:
    metasprite Subsprite_851, 1, 32, 167, 7457 @ 445
    metasprite Subsprite_852, 2, 20, 167, 7489 @ 446
    metasprite Subsprite_854, 4, 18, 167, 7509 @ 447
  Metaprite_448:
    metasprite Subsprite_858, 1, 32, 167, 7527 @ 448
    metasprite Subsprite_859, 3, 40, 167, 7559 @ 449
    metasprite Subsprite_862, 1, 32, 167, 7599 @ 450
  Metaprite_451:
    metasprite Subsprite_863, 1, 32, 167, 7631 @ 451
    metasprite Subsprite_864, 3, 40, 167, 7663 @ 452
    metasprite Subsprite_867, 1, 32, 167, 7703 @ 453
  Metaprite_454:
    metasprite Subsprite_868, 1, 32, 175, 7735 @ 454
    metasprite Subsprite_869, 3, 40, 175, 7767 @ 455
    metasprite Subsprite_872, 1, 32, 175, 7807 @ 456
  Metaprite_457:
    metasprite Subsprite_873, 1, 32, 175, 7839 @ 457
    metasprite Subsprite_874, 2, 20, 175, 7871 @ 458
    metasprite Subsprite_876, 4, 18, 175, 7891 @ 459
  Metaprite_460:
    metasprite Subsprite_880, 1, 32, 175, 7909 @ 460
    metasprite Subsprite_881, 2, 20, 175, 7941 @ 461
    metasprite Subsprite_883, 4, 18, 175, 7961 @ 462
  Metaprite_463:
    metasprite Subsprite_887, 1, 32, 175, 7979 @ 463
    metasprite Subsprite_888, 3, 40, 175, 8011 @ 464
    metasprite Subsprite_891, 1, 32, 175, 8051 @ 465
  Metaprite_466:
    metasprite Subsprite_892, 1, 32, 175, 8083 @ 466
    metasprite Subsprite_893, 3, 40, 175, 8115 @ 467
    metasprite Subsprite_896, 1, 32, 175, 8155 @ 468
  Metaprite_469:
    metasprite Subsprite_897, 2, 10, 176, 8187 @ 469
    metasprite Subsprite_899, 3, 11, 176, 8197 @ 470
    metasprite Subsprite_902, 1, 8, 176, 8208 @ 471
    metasprite Subsprite_903, 4, 9, 176, 8216 @ 472
    metasprite Subsprite_907, 3, 7, 176, 8225 @ 473
    metasprite Subsprite_910, 2, 6, 176, 8232 @ 474
    metasprite Subsprite_912, 4, 9, 176, 8238 @ 475
    metasprite Subsprite_916, 3, 7, 176, 8247 @ 476
    metasprite Subsprite_919, 2, 5, 176, 8254 @ 477
    metasprite Subsprite_921, 2, 6, 176, 8259 @ 478
    metasprite Subsprite_923, 3, 7, 176, 8265 @ 479
    metasprite Subsprite_926, 3, 7, 176, 8272 @ 480
    metasprite Subsprite_929, 1, 8, 176, 8279 @ 481
    metasprite Subsprite_930, 1, 8, 176, 8287 @ 482
    metasprite Subsprite_931, 2, 10, 176, 8295 @ 483
    metasprite Subsprite_933, 3, 7, 176, 8305 @ 484
    metasprite Subsprite_936, 3, 7, 176, 8312 @ 485
    metasprite Subsprite_939, 2, 6, 176, 8319 @ 486
    metasprite Subsprite_941, 3, 8, 176, 8325 @ 487
    metasprite Subsprite_944, 3, 8, 176, 8333 @ 488
    metasprite Subsprite_947, 3, 7, 176, 8341 @ 489
    metasprite Subsprite_950, 3, 6, 176, 8348 @ 490
    metasprite Subsprite_953, 3, 6, 176, 8354 @ 491
    metasprite Subsprite_956, 2, 6, 176, 8360 @ 492
    metasprite Subsprite_958, 2, 8, 176, 8366 @ 493
    metasprite Subsprite_960, 2, 8, 176, 8374 @ 494
    metasprite Subsprite_962, 3, 7, 176, 8382 @ 495
    metasprite Subsprite_965, 2, 5, 176, 8389 @ 496
    metasprite Subsprite_967, 1, 4, 176, 8394 @ 497
  Metaprite_498:
    metasprite Subsprite_968, 3, 48, 83, 8398 @ 498
    metasprite Subsprite_971, 3, 48, 83, 8446 @ 499
    metasprite Subsprite_974, 3, 48, 83, 8494 @ 500
    metasprite Subsprite_977, 3, 48, 83, 8542 @ 501
    metasprite Subsprite_980, 3, 48, 83, 8590 @ 502
    metasprite Subsprite_983, 3, 48, 83, 8638 @ 503
    metasprite Subsprite_986, 3, 48, 83, 8686 @ 504
    metasprite Subsprite_989, 3, 48, 83, 8734 @ 505
    metasprite Subsprite_992, 3, 48, 83, 8782 @ 506
    metasprite Subsprite_995, 2, 36, 83, 8830 @ 507
    metasprite Subsprite_997, 3, 48, 83, 8866 @ 508
    metasprite Subsprite_1000, 3, 48, 83, 8914 @ 509
  Metaprite_510:
    metasprite Subsprite_1003, 1, 4, 179, 8962 @ 510
    metasprite Subsprite_1004, 1, 16, 179, 8966 @ 511
    metasprite Subsprite_1005, 3, 7, 179, 8982 @ 512
    metasprite Subsprite_1008, 3, 7, 179, 8989 @ 513
    metasprite Subsprite_1011, 3, 8, 179, 8996 @ 514
    metasprite Subsprite_1014, 3, 8, 179, 9004 @ 515
    metasprite Subsprite_1017, 1, 16, 179, 9012 @ 516
    metasprite Subsprite_1018, 1, 1, 179, 9028 @ 517
  Metaprite_518:
    metasprite Subsprite_1019, 1, 64, 181, 9029 @ 518
  Metaprite_519:
    metasprite Subsprite_1020, 3, 24, 187, 9093 @ 519
  Metaprite_520:
    metasprite Subsprite_1023, 1, 32, 188, 9117 @ 520
    metasprite Subsprite_1024, 1, 32, 188, 9149 @ 521
    metasprite Subsprite_1025, 1, 32, 188, 9181 @ 522
    metasprite Subsprite_1026, 1, 32, 188, 9213 @ 523
    metasprite Subsprite_1027, 1, 32, 188, 9245 @ 524
    metasprite Subsprite_1028, 1, 32, 188, 9277 @ 525
    metasprite Subsprite_1029, 1, 32, 188, 9309 @ 526
    metasprite Subsprite_1030, 1, 32, 188, 9341 @ 527
  Metaprite_528:
    metasprite Subsprite_1031, 3, 24, 42, 9373 @ 528
  Metaprite_529:
    metasprite Subsprite_1034, 1, 4, 195, 9397 @ 529
    metasprite Subsprite_1035, 1, 4, 195, 9401 @ 530
    metasprite Subsprite_1036, 1, 4, 195, 9405 @ 531
    metasprite Subsprite_1037, 1, 4, 195, 9409 @ 532
    metasprite Subsprite_1038, 1, 4, 195, 9413 @ 533
    metasprite Subsprite_1039, 1, 4, 195, 9417 @ 534
    metasprite Subsprite_1040, 1, 4, 195, 9421 @ 535
    metasprite Subsprite_1041, 1, 4, 195, 9425 @ 536
    metasprite Subsprite_1042, 1, 4, 195, 9429 @ 537
    metasprite Subsprite_1043, 1, 4, 195, 9433 @ 538
    metasprite Subsprite_1044, 1, 4, 195, 9437 @ 539
    metasprite Subsprite_1045, 1, 4, 195, 9441 @ 540
    metasprite Subsprite_1046, 1, 4, 195, 9445 @ 541
    metasprite Subsprite_1047, 1, 4, 195, 9449 @ 542
    metasprite Subsprite_1048, 1, 4, 195, 9453 @ 543
    metasprite Subsprite_1049, 1, 2, 195, 9457 @ 544
    metasprite Subsprite_1050, 1, 1, 195, 9459 @ 545
    metasprite Subsprite_1051, 2, 3, 195, 9460 @ 546
    metasprite Subsprite_1053, 2, 3, 195, 9463 @ 547
    metasprite Subsprite_1055, 1, 4, 195, 9466 @ 548
    metasprite Subsprite_1056, 1, 4, 195, 9470 @ 549
    metasprite Subsprite_1057, 1, 4, 195, 9474 @ 550
    metasprite Subsprite_1058, 1, 4, 195, 9478 @ 551
    metasprite Subsprite_1059, 1, 4, 195, 9482 @ 552
    metasprite Subsprite_1060, 1, 4, 195, 9486 @ 553
    metasprite Subsprite_1061, 1, 4, 195, 9490 @ 554
  Metaprite_555:
    metasprite Subsprite_1062, 1, 4, 207, 9494 @ 555
    metasprite Subsprite_1063, 1, 4, 207, 9498 @ 556
    metasprite Subsprite_1064, 1, 4, 207, 9502 @ 557
    metasprite Subsprite_1065, 1, 4, 207, 9506 @ 558
  Metaprite_559:
    metasprite Subsprite_1066, 1, 2, 207, 9510 @ 559
    metasprite Subsprite_1067, 1, 2, 207, 9512 @ 560
    metasprite Subsprite_1068, 1, 2, 207, 9514 @ 561
    metasprite Subsprite_1069, 1, 2, 207, 9516 @ 562
    metasprite Subsprite_1070, 1, 2, 207, 9518 @ 563
    metasprite Subsprite_1071, 1, 2, 207, 9520 @ 564
    metasprite Subsprite_1072, 1, 2, 207, 9522 @ 565
    metasprite Subsprite_1073, 1, 2, 207, 9524 @ 566
    metasprite Subsprite_1074, 1, 2, 207, 9526 @ 567
    metasprite Subsprite_1075, 1, 2, 207, 9528 @ 568
    metasprite Subsprite_1076, 1, 2, 207, 9530 @ 569
  Metaprite_570:
    metasprite Subsprite_1077, 2, 12, 208, 9532 @ 570
    metasprite Subsprite_1079, 4, 9, 208, 9544 @ 571
  Metaprite_572:
    metasprite Subsprite_1083, 4, 36, 213, 9553 @ 572
  Metaprite_573:
    metasprite Subsprite_1087, 3, 40, 97, 9589 @ 573
    metasprite Subsprite_1090, 3, 40, 97, 9629 @ 574
    metasprite Subsprite_1093, 3, 40, 97, 9669 @ 575
    metasprite Subsprite_1096, 3, 40, 97, 9709 @ 576
  Metaprite_577:
    metasprite Subsprite_1099, 3, 7, 216, 9749 @ 577
    metasprite Subsprite_1102, 1, 16, 216, 9756 @ 578
    metasprite Subsprite_1103, 3, 14, 216, 9772 @ 579
    metasprite Subsprite_1106, 1, 16, 216, 9786 @ 580
    metasprite Subsprite_1107, 1, 16, 216, 9802 @ 581
    metasprite Subsprite_1108, 1, 16, 216, 9818 @ 582
    metasprite Subsprite_1109, 1, 16, 216, 9834 @ 583
    metasprite Subsprite_1110, 3, 14, 216, 9850 @ 584
    metasprite Subsprite_1113, 1, 16, 216, 9864 @ 585
    metasprite Subsprite_1114, 1, 16, 216, 9880 @ 586
    metasprite Subsprite_1115, 1, 16, 216, 9896 @ 587
    metasprite Subsprite_1116, 1, 16, 216, 9912 @ 588
    metasprite Subsprite_1117, 1, 16, 216, 9928 @ 589
    metasprite Subsprite_1118, 1, 16, 216, 9944 @ 590
    metasprite Subsprite_1119, 1, 16, 216, 9960 @ 591
    metasprite Subsprite_1120, 1, 16, 216, 9976 @ 592
    metasprite Subsprite_1121, 1, 16, 216, 9992 @ 593
    metasprite Subsprite_1122, 3, 12, 216, 10008 @ 594
    metasprite Subsprite_1125, 3, 12, 216, 10020 @ 595
    metasprite Subsprite_1128, 3, 11, 216, 10032 @ 596
    metasprite Subsprite_1131, 3, 12, 216, 10043 @ 597
    metasprite Subsprite_1134, 3, 12, 216, 10055 @ 598
    metasprite Subsprite_1137, 3, 12, 216, 10067 @ 599
    metasprite Subsprite_1140, 1, 4, 216, 10079 @ 600
    metasprite Subsprite_1141, 3, 12, 216, 10083 @ 601
    metasprite Subsprite_1144, 3, 12, 216, 10095 @ 602
  Metaprite_603:
    metasprite Subsprite_1147, 1, 4, 216, 10107 @ 603
    metasprite Subsprite_1148, 1, 4, 216, 10111 @ 604
    metasprite Subsprite_1149, 1, 4, 216, 10115 @ 605
    metasprite Subsprite_1150, 1, 4, 216, 10119 @ 606
    metasprite Subsprite_1151, 1, 4, 216, 10123 @ 607
    metasprite Subsprite_1152, 1, 4, 216, 10127 @ 608
    metasprite Subsprite_1153, 1, 4, 216, 10131 @ 609
    metasprite Subsprite_1154, 1, 4, 216, 10135 @ 610
    metasprite Subsprite_1155, 1, 4, 216, 10139 @ 611
    metasprite Subsprite_1156, 1, 4, 216, 10143 @ 612
    metasprite Subsprite_1157, 1, 4, 216, 10147 @ 613
    metasprite Subsprite_1158, 1, 4, 216, 10151 @ 614
    metasprite Subsprite_1159, 1, 4, 216, 10155 @ 615
  Metaprite_616:
    metasprite Subsprite_1160, 4, 30, 216, 10159 @ 616
    metasprite Subsprite_1164, 2, 24, 216, 10189 @ 617
    metasprite Subsprite_1166, 4, 36, 216, 10213 @ 618
    metasprite Subsprite_1170, 3, 48, 216, 10249 @ 619
    metasprite Subsprite_1173, 4, 30, 216, 10297 @ 620
    metasprite Subsprite_1177, 4, 30, 216, 10327 @ 621
  Metaprite_622:
    metasprite Subsprite_1181, 4, 30, 220, 10357 @ 622
    metasprite Subsprite_1185, 4, 30, 220, 10387 @ 623
    metasprite Subsprite_1189, 4, 30, 220, 10417 @ 624
    metasprite Subsprite_1193, 4, 30, 220, 10447 @ 625
    metasprite Subsprite_1197, 4, 30, 220, 10477 @ 626
    metasprite Subsprite_1201, 4, 30, 220, 10507 @ 627
    metasprite Subsprite_1205, 4, 30, 220, 10537 @ 628
    metasprite Subsprite_1209, 2, 20, 220, 10567 @ 629
    metasprite Subsprite_1211, 2, 20, 220, 10587 @ 630
    metasprite Subsprite_1213, 4, 30, 220, 10607 @ 631
    metasprite Subsprite_1217, 4, 30, 220, 10637 @ 632
    metasprite Subsprite_1221, 2, 20, 220, 10667 @ 633
    metasprite Subsprite_1223, 2, 20, 220, 10687 @ 634
    metasprite Subsprite_1225, 3, 40, 220, 10707 @ 635
    metasprite Subsprite_1228, 3, 24, 220, 10747 @ 636
    metasprite Subsprite_1231, 3, 24, 220, 10771 @ 637
    metasprite Subsprite_1234, 4, 30, 220, 10795 @ 638
    metasprite Subsprite_1238, 1, 64, 220, 10825 @ 639
    metasprite Subsprite_1239, 4, 36, 220, 10889 @ 640
    metasprite Subsprite_1243, 3, 40, 220, 10925 @ 641
    metasprite Subsprite_1246, 4, 30, 220, 10965 @ 642
    metasprite Subsprite_1250, 4, 30, 220, 10995 @ 643
    metasprite Subsprite_1254, 4, 30, 220, 11025 @ 644
    metasprite Subsprite_1258, 3, 40, 220, 11055 @ 645
    metasprite Subsprite_1261, 3, 48, 220, 11095 @ 646
    metasprite Subsprite_1264, 3, 28, 220, 11143 @ 647
    metasprite Subsprite_1267, 3, 28, 220, 11171 @ 648
    metasprite Subsprite_1270, 4, 30, 220, 11199 @ 649
    metasprite Subsprite_1274, 3, 40, 220, 11229 @ 650
    metasprite Subsprite_1277, 3, 40, 220, 11269 @ 651
    metasprite Subsprite_1280, 3, 40, 220, 11309 @ 652
    metasprite Subsprite_1283, 3, 48, 220, 11349 @ 653
    metasprite Subsprite_1286, 3, 40, 220, 11397 @ 654
    metasprite Subsprite_1289, 4, 30, 220, 11437 @ 655
    metasprite Subsprite_1293, 2, 20, 220, 11467 @ 656
    metasprite Subsprite_1295, 2, 20, 220, 11487 @ 657
    metasprite Subsprite_1297, 2, 20, 220, 11507 @ 658
  Metaprite_659:
    metasprite Subsprite_1299, 3, 12, 220, 11527 @ 659
  Metaprite_660:
    metasprite Subsprite_1302, 4, 36, 236, 11539 @ 660
  Metaprite_661:
    metasprite Subsprite_1306, 3, 28, 239, 11575 @ 661
  Metaprite_662:
    metasprite Subsprite_1309, 1, 4, 0, 11603 @ 662
    metasprite Subsprite_1310, 1, 4, 0, 11607 @ 663
    metasprite Subsprite_1311, 1, 4, 0, 11611 @ 664
    metasprite Subsprite_1312, 1, 4, 0, 11615 @ 665
    metasprite Subsprite_1313, 1, 4, 0, 11619 @ 666
    metasprite Subsprite_1314, 1, 4, 0, 11623 @ 667
    metasprite Subsprite_1315, 1, 4, 0, 11627 @ 668
    metasprite Subsprite_1316, 1, 4, 0, 11631 @ 669
    metasprite Subsprite_1317, 1, 4, 0, 11635 @ 670
    metasprite Subsprite_1318, 1, 4, 0, 11639 @ 671
    metasprite Subsprite_1319, 1, 4, 0, 11643 @ 672
    metasprite Subsprite_1320, 1, 4, 0, 11647 @ 673
    metasprite Subsprite_1321, 1, 4, 0, 11651 @ 674
    metasprite Subsprite_1322, 1, 4, 0, 11655 @ 675
    metasprite Subsprite_1323, 1, 4, 0, 11659 @ 676
    metasprite Subsprite_1324, 1, 4, 0, 11663 @ 677
    metasprite Subsprite_1325, 1, 4, 0, 11667 @ 678
    metasprite Subsprite_1326, 1, 4, 0, 11671 @ 679
    metasprite Subsprite_1327, 1, 4, 0, 11675 @ 680
    metasprite Subsprite_1328, 1, 4, 0, 11679 @ 681
    metasprite Subsprite_1329, 1, 4, 0, 11683 @ 682
    metasprite Subsprite_1330, 1, 4, 0, 11687 @ 683
    metasprite Subsprite_1331, 1, 4, 0, 11691 @ 684
    metasprite Subsprite_1332, 1, 4, 0, 11695 @ 685
  Metaprite_686:
    metasprite Subsprite_1333, 1, 4, 242, 11699 @ 686
    metasprite Subsprite_1334, 1, 4, 242, 11703 @ 687
    metasprite Subsprite_1335, 1, 4, 242, 11707 @ 688
    metasprite Subsprite_1336, 1, 4, 242, 11711 @ 689
    metasprite Subsprite_1337, 1, 4, 242, 11715 @ 690
    metasprite Subsprite_1338, 1, 4, 242, 11719 @ 691
    metasprite Subsprite_1339, 1, 4, 242, 11723 @ 692
    metasprite Subsprite_1340, 1, 4, 242, 11727 @ 693
    metasprite Subsprite_1341, 1, 4, 242, 11731 @ 694
    metasprite Subsprite_1342, 1, 4, 242, 11735 @ 695
    metasprite Subsprite_1343, 1, 4, 242, 11739 @ 696
  Metaprite_697:
    metasprite Subsprite_1344, 3, 32, 243, 11743 @ 697
  Metaprite_698:
    metasprite Subsprite_1347, 4, 36, 244, 11775 @ 698
  Metaprite_699:
    metasprite Subsprite_1351, 1, 16, 247, 11811 @ 699
    metasprite Subsprite_1352, 2, 5, 247, 11827 @ 700
    metasprite Subsprite_1354, 2, 5, 247, 11832 @ 701
    metasprite Subsprite_1356, 2, 5, 247, 11837 @ 702
    metasprite Subsprite_1358, 1, 16, 247, 11842 @ 703
    metasprite Subsprite_1359, 3, 6, 247, 11858 @ 704
    metasprite Subsprite_1362, 1, 16, 247, 11864 @ 705
    metasprite Subsprite_1363, 1, 4, 247, 11880 @ 706
    metasprite Subsprite_1364, 1, 4, 247, 11884 @ 707
    metasprite Subsprite_1365, 1, 4, 247, 11888 @ 708
    metasprite Subsprite_1366, 1, 4, 247, 11892 @ 709
    metasprite Subsprite_1367, 1, 4, 247, 11896 @ 710
    metasprite Subsprite_1368, 1, 2, 247, 11900 @ 711
    metasprite Subsprite_1369, 1, 4, 247, 11902 @ 712
    metasprite Subsprite_1370, 2, 6, 247, 11906 @ 713
    metasprite Subsprite_1372, 3, 7, 247, 11912 @ 714
    metasprite Subsprite_1375, 4, 9, 247, 11919 @ 715
    metasprite Subsprite_1379, 2, 12, 247, 11928 @ 716
    metasprite Subsprite_1381, 3, 4, 247, 11940 @ 717
    metasprite Subsprite_1384, 1, 2, 247, 11944 @ 718
    metasprite Subsprite_1385, 1, 4, 247, 11946 @ 719
    metasprite Subsprite_1386, 1, 4, 247, 11950 @ 720
    metasprite Subsprite_1387, 1, 4, 247, 11954 @ 721
    metasprite Subsprite_1388, 1, 4, 247, 11958 @ 722
    metasprite Subsprite_1389, 1, 2, 247, 11962 @ 723
    metasprite Subsprite_1390, 1, 16, 247, 11964 @ 724
    metasprite Subsprite_1391, 3, 14, 247, 11980 @ 725
    metasprite Subsprite_1394, 1, 16, 247, 11994 @ 726
    metasprite Subsprite_1395, 1, 16, 247, 12010 @ 727
    metasprite Subsprite_1396, 1, 16, 247, 12026 @ 728
    metasprite Subsprite_1397, 1, 16, 247, 12042 @ 729
    metasprite Subsprite_1398, 1, 16, 247, 12058 @ 730
    metasprite Subsprite_1399, 1, 16, 247, 12074 @ 731
    metasprite Subsprite_1400, 1, 16, 247, 12090 @ 732
    metasprite Subsprite_1401, 3, 12, 247, 12106 @ 733
    metasprite Subsprite_1404, 1, 16, 247, 12118 @ 734
    metasprite Subsprite_1405, 1, 16, 247, 12134 @ 735
    metasprite Subsprite_1406, 3, 14, 247, 12150 @ 736
    metasprite Subsprite_1409, 3, 14, 247, 12164 @ 737
    metasprite Subsprite_1412, 3, 14, 247, 12178 @ 738
    metasprite Subsprite_1415, 1, 16, 247, 12192 @ 739
    metasprite Subsprite_1416, 1, 16, 247, 12208 @ 740
    metasprite Subsprite_1417, 3, 12, 247, 12224 @ 741
    metasprite Subsprite_1420, 3, 12, 247, 12236 @ 742
    metasprite Subsprite_1423, 1, 8, 247, 12248 @ 743
    metasprite Subsprite_1424, 3, 7, 247, 12256 @ 744
    metasprite Subsprite_1427, 1, 8, 247, 12263 @ 745
    metasprite Subsprite_1428, 1, 8, 247, 12271 @ 746
    metasprite Subsprite_1429, 3, 6, 247, 12279 @ 747
    metasprite Subsprite_1432, 2, 12, 247, 12285 @ 748
    metasprite Subsprite_1434, 3, 6, 247, 12297 @ 749
    metasprite Subsprite_1437, 3, 6, 247, 12303 @ 750
    metasprite Subsprite_1440, 2, 12, 247, 12309 @ 751
    metasprite Subsprite_1442, 3, 6, 247, 12321 @ 752
    metasprite Subsprite_1445, 3, 8, 247, 12327 @ 753
    metasprite Subsprite_1448, 3, 13, 247, 12335 @ 754
    metasprite Subsprite_1451, 3, 14, 247, 12348 @ 755
    metasprite Subsprite_1454, 1, 16, 247, 12362 @ 756
    metasprite Subsprite_1455, 1, 16, 247, 12378 @ 757
    metasprite Subsprite_1456, 1, 16, 247, 12394 @ 758
    metasprite Subsprite_1457, 3, 11, 247, 12410 @ 759
    metasprite Subsprite_1460, 1, 16, 247, 12421 @ 760
    metasprite Subsprite_1461, 3, 7, 247, 12437 @ 761
    metasprite Subsprite_1464, 3, 5, 247, 12444 @ 762
  Metaprite_763:
    metasprite Subsprite_1467, 1, 16, 247, 12449 @ 763
    metasprite Subsprite_1468, 1, 16, 247, 12465 @ 764
    metasprite Subsprite_1469, 1, 16, 247, 12481 @ 765
    metasprite Subsprite_1470, 1, 4, 247, 12497 @ 766
    metasprite Subsprite_1471, 1, 16, 247, 12501 @ 767
    metasprite Subsprite_1472, 1, 16, 247, 12517 @ 768
    metasprite Subsprite_1473, 1, 16, 247, 12533 @ 769
    metasprite Subsprite_1474, 2, 12, 247, 12549 @ 770
    metasprite Subsprite_1476, 1, 16, 247, 12561 @ 771
    metasprite Subsprite_1477, 1, 16, 247, 12577 @ 772
    metasprite Subsprite_1478, 1, 16, 247, 12593 @ 773
    metasprite Subsprite_1479, 2, 12, 247, 12609 @ 774
    metasprite Subsprite_1481, 2, 5, 247, 12621 @ 775
    metasprite Subsprite_1483, 2, 5, 247, 12626 @ 776
    metasprite Subsprite_1485, 2, 5, 247, 12631 @ 777
    metasprite Subsprite_1487, 2, 5, 247, 12636 @ 778
    metasprite Subsprite_1489, 3, 12, 247, 12641 @ 779
    metasprite Subsprite_1492, 2, 6, 247, 12653 @ 780
    metasprite Subsprite_1494, 1, 4, 247, 12659 @ 781
    metasprite Subsprite_1495, 1, 16, 247, 12663 @ 782
    metasprite Subsprite_1496, 2, 12, 247, 12679 @ 783
    metasprite Subsprite_1498, 1, 16, 247, 12691 @ 784
  Metaprite_785:
    metasprite Subsprite_1499, 1, 2, 263, 12707 @ 785
  Metaprite_786:
    metasprite Subsprite_1500, 3, 12, 268, 12709 @ 786
    metasprite Subsprite_1503, 3, 12, 268, 12721 @ 787
    metasprite Subsprite_1506, 3, 12, 268, 12733 @ 788
    metasprite Subsprite_1509, 3, 12, 268, 12745 @ 789
    metasprite Subsprite_1512, 3, 12, 268, 12757 @ 790
    metasprite Subsprite_1515, 3, 12, 268, 12769 @ 791
    metasprite Subsprite_1518, 3, 12, 268, 12781 @ 792
    metasprite Subsprite_1521, 3, 12, 268, 12793 @ 793
    metasprite Subsprite_1524, 3, 12, 268, 12805 @ 794
    metasprite Subsprite_1527, 3, 12, 268, 12817 @ 795
    metasprite Subsprite_1530, 3, 12, 268, 12829 @ 796
  Metaprite_797:
    metasprite Subsprite_1533, 1, 16, 275, 12841 @ 797
    metasprite Subsprite_1534, 1, 16, 275, 12857 @ 798
    metasprite Subsprite_1535, 1, 16, 275, 12873 @ 799
    metasprite Subsprite_1536, 1, 16, 275, 12889 @ 800
    metasprite Subsprite_1537, 1, 16, 275, 12905 @ 801
    metasprite Subsprite_1538, 1, 16, 275, 12921 @ 802
    metasprite Subsprite_1539, 1, 16, 275, 12937 @ 803
    metasprite Subsprite_1540, 1, 16, 275, 12953 @ 804
    metasprite Subsprite_1541, 1, 16, 275, 12969 @ 805
    metasprite Subsprite_1542, 1, 16, 275, 12985 @ 806
    metasprite Subsprite_1543, 1, 16, 275, 13001 @ 807
    metasprite Subsprite_1544, 1, 16, 275, 13017 @ 808
    metasprite Subsprite_1545, 1, 16, 275, 13033 @ 809
    metasprite Subsprite_1546, 1, 16, 275, 13049 @ 810
    metasprite Subsprite_1547, 1, 16, 275, 13065 @ 811
    metasprite Subsprite_1548, 1, 16, 275, 13081 @ 812
  Metaprite_813:
    metasprite Subsprite_1549, 2, 6, 279, 13097 @ 813
    metasprite Subsprite_1551, 2, 6, 279, 13103 @ 814
    metasprite Subsprite_1553, 1, 8, 279, 13109 @ 815
    metasprite Subsprite_1554, 2, 5, 279, 13117 @ 816
    metasprite Subsprite_1556, 2, 6, 279, 13122 @ 817
    metasprite Subsprite_1558, 3, 7, 279, 13128 @ 818
    metasprite Subsprite_1561, 2, 5, 279, 13135 @ 819
    metasprite Subsprite_1563, 2, 5, 279, 13140 @ 820
    metasprite Subsprite_1565, 2, 5, 279, 13145 @ 821
    metasprite Subsprite_1567, 2, 5, 279, 13150 @ 822
    metasprite Subsprite_1569, 2, 5, 279, 13155 @ 823
    metasprite Subsprite_1571, 2, 5, 279, 13160 @ 824
    metasprite Subsprite_1573, 2, 6, 279, 13165 @ 825
    metasprite Subsprite_1575, 2, 6, 279, 13171 @ 826
    metasprite Subsprite_1577, 2, 6, 279, 13177 @ 827
    metasprite Subsprite_1579, 1, 4, 279, 13183 @ 828
    metasprite Subsprite_1580, 1, 4, 279, 13187 @ 829
    metasprite Subsprite_1581, 2, 6, 279, 13191 @ 830
    metasprite Subsprite_1583, 2, 6, 279, 13197 @ 831
    metasprite Subsprite_1585, 2, 6, 279, 13203 @ 832
    metasprite Subsprite_1587, 2, 6, 279, 13209 @ 833
    metasprite Subsprite_1589, 2, 6, 279, 13215 @ 834
    metasprite Subsprite_1591, 2, 6, 279, 13221 @ 835
    metasprite Subsprite_1593, 2, 6, 279, 13227 @ 836
    metasprite Subsprite_1595, 2, 6, 279, 13233 @ 837
    metasprite Subsprite_1597, 2, 6, 279, 13239 @ 838
    metasprite Subsprite_1599, 2, 6, 279, 13245 @ 839
    metasprite Subsprite_1601, 2, 6, 279, 13251 @ 840
    metasprite Subsprite_1603, 2, 6, 279, 13257 @ 841
    metasprite Subsprite_1605, 2, 6, 279, 13263 @ 842
    metasprite Subsprite_1607, 2, 6, 279, 13269 @ 843
    metasprite Subsprite_1609, 2, 6, 279, 13275 @ 844
    metasprite Subsprite_1611, 2, 6, 279, 13281 @ 845
    metasprite Subsprite_1613, 2, 6, 279, 13287 @ 846
    metasprite Subsprite_1615, 2, 6, 279, 13293 @ 847
    metasprite Subsprite_1617, 2, 6, 279, 13299 @ 848
    metasprite Subsprite_1619, 2, 6, 279, 13305 @ 849
  Metaprite_850:
    metasprite Subsprite_1621, 2, 6, 279, 13311 @ 850
    metasprite Subsprite_1623, 3, 8, 279, 13317 @ 851
    metasprite Subsprite_1626, 3, 7, 279, 13325 @ 852
    metasprite Subsprite_1629, 3, 7, 279, 13332 @ 853
    metasprite Subsprite_1632, 2, 6, 279, 13339 @ 854
    metasprite Subsprite_1634, 2, 12, 279, 13345 @ 855
    metasprite Subsprite_1636, 3, 9, 279, 13357 @ 856
    metasprite Subsprite_1639, 4, 9, 279, 13366 @ 857
    metasprite Subsprite_1643, 2, 6, 279, 13375 @ 858
    metasprite Subsprite_1645, 2, 6, 279, 13381 @ 859
    metasprite Subsprite_1647, 3, 8, 279, 13387 @ 860
    metasprite Subsprite_1650, 2, 12, 279, 13395 @ 861
    metasprite Subsprite_1652, 2, 12, 279, 13407 @ 862
    metasprite Subsprite_1654, 2, 6, 279, 13419 @ 863
  Metaprite_864:
    metasprite Subsprite_1656, 1, 16, 283, 13425 @ 864
  Metaprite_865:
    metasprite Subsprite_1657, 1, 1, 283, 13441 @ 865
  Metaprite_866:
    metasprite Subsprite_1658, 3, 48, 83, 13442 @ 866
    metasprite Subsprite_1661, 3, 48, 83, 13490 @ 867
  Metaprite_868:
    metasprite Subsprite_1664, 4, 36, 284, 13538 @ 868
  Metaprite_869:
    metasprite Subsprite_1668, 3, 24, 287, 13574 @ 869
    metasprite Subsprite_1671, 3, 24, 287, 13598 @ 870
  Metaprite_871:
    metasprite Subsprite_1674, 1, 4, 44, 13622 @ 871
    metasprite Subsprite_1675, 1, 4, 44, 13626 @ 872
    metasprite Subsprite_1676, 1, 4, 44, 13630 @ 873
    metasprite Subsprite_1677, 1, 4, 44, 13634 @ 874
  Metaprite_875:
    metasprite Subsprite_1678, 1, 4, 289, 13638 @ 875
    metasprite Subsprite_1679, 1, 16, 289, 13642 @ 876
    metasprite Subsprite_1680, 3, 11, 289, 13658 @ 877
    metasprite Subsprite_1683, 2, 12, 289, 13669 @ 878
    metasprite Subsprite_1685, 3, 11, 289, 13681 @ 879
  Metaprite_880:
    metasprite Subsprite_1688, 3, 48, 83, 13692 @ 880
    metasprite Subsprite_1691, 3, 48, 83, 13740 @ 881
    metasprite Subsprite_1694, 3, 48, 83, 13788 @ 882
    metasprite Subsprite_1697, 3, 48, 83, 13836 @ 883
    metasprite Subsprite_1700, 3, 48, 83, 13884 @ 884
    metasprite Subsprite_1703, 3, 48, 83, 13932 @ 885
    metasprite Subsprite_1706, 3, 48, 83, 13980 @ 886
    metasprite Subsprite_1709, 3, 48, 83, 14028 @ 887
    metasprite Subsprite_1712, 3, 48, 83, 14076 @ 888
    metasprite Subsprite_1715, 3, 48, 83, 14124 @ 889
    metasprite Subsprite_1718, 3, 48, 83, 14172 @ 890
  Metaprite_891:
    metasprite Subsprite_1721, 4, 24, 300, 14220 @ 891
  Metaprite_892:
    metasprite Subsprite_1725, 1, 32, 301, 14244 @ 892
    metasprite Subsprite_1726, 1, 32, 301, 14276 @ 893
  Metaprite_894:
    metasprite Subsprite_1727, 1, 8, 301, 14308 @ 894
    metasprite Subsprite_1728, 2, 6, 301, 14316 @ 895
    metasprite Subsprite_1730, 1, 8, 301, 14322 @ 896
    metasprite Subsprite_1731, 1, 8, 301, 14330 @ 897
  Metaprite_898:
    metasprite Subsprite_1732, 3, 11, 306, 14338 @ 898
    metasprite Subsprite_1735, 2, 20, 306, 14349 @ 899
    metasprite Subsprite_1737, 3, 11, 306, 14369 @ 900
    metasprite Subsprite_1740, 2, 20, 306, 14380 @ 901
    metasprite Subsprite_1742, 3, 12, 306, 14400 @ 902
    metasprite Subsprite_1745, 3, 14, 306, 14412 @ 903
    metasprite Subsprite_1748, 2, 20, 306, 14426 @ 904
    metasprite Subsprite_1750, 3, 11, 306, 14446 @ 905
    metasprite Subsprite_1753, 3, 12, 306, 14457 @ 906
    metasprite Subsprite_1756, 2, 20, 306, 14469 @ 907
    metasprite Subsprite_1758, 2, 20, 306, 14489 @ 908
    metasprite Subsprite_1760, 3, 11, 306, 14509 @ 909
  Metaprite_910:
    metasprite Subsprite_1763, 3, 14, 306, 14520 @ 910
    metasprite Subsprite_1766, 3, 12, 306, 14534 @ 911
    metasprite Subsprite_1769, 3, 12, 306, 14546 @ 912
    metasprite Subsprite_1772, 3, 11, 306, 14558 @ 913
    metasprite Subsprite_1775, 2, 12, 306, 14569 @ 914
    metasprite Subsprite_1777, 2, 20, 306, 14581 @ 915
    metasprite Subsprite_1779, 3, 11, 306, 14601 @ 916
    metasprite Subsprite_1782, 3, 12, 306, 14612 @ 917
    metasprite Subsprite_1785, 2, 12, 306, 14624 @ 918
    metasprite Subsprite_1787, 2, 12, 306, 14636 @ 919
  Metaprite_920:
    metasprite Subsprite_1789, 3, 12, 306, 14648 @ 920
    metasprite Subsprite_1792, 3, 12, 306, 14660 @ 921
    metasprite Subsprite_1795, 3, 12, 306, 14672 @ 922
    metasprite Subsprite_1798, 3, 12, 306, 14684 @ 923
    metasprite Subsprite_1801, 3, 12, 306, 14696 @ 924
    metasprite Subsprite_1804, 3, 12, 306, 14708 @ 925
    metasprite Subsprite_1807, 3, 12, 306, 14720 @ 926
    metasprite Subsprite_1810, 3, 12, 306, 14732 @ 927
    metasprite Subsprite_1813, 3, 12, 306, 14744 @ 928
    metasprite Subsprite_1816, 3, 12, 306, 14756 @ 929
    metasprite Subsprite_1819, 3, 12, 306, 14768 @ 930
    metasprite Subsprite_1822, 3, 11, 306, 14780 @ 931
    metasprite Subsprite_1825, 3, 11, 306, 14791 @ 932
    metasprite Subsprite_1828, 3, 12, 306, 14802 @ 933
    metasprite Subsprite_1831, 3, 12, 306, 14814 @ 934
    metasprite Subsprite_1834, 3, 11, 306, 14826 @ 935
    metasprite Subsprite_1837, 3, 11, 306, 14837 @ 936
    metasprite Subsprite_1840, 3, 12, 306, 14848 @ 937
    metasprite Subsprite_1843, 3, 10, 306, 14860 @ 938
    metasprite Subsprite_1846, 2, 20, 306, 14870 @ 939
    metasprite Subsprite_1848, 3, 12, 306, 14890 @ 940
    metasprite Subsprite_1851, 3, 11, 306, 14902 @ 941
    metasprite Subsprite_1854, 3, 11, 306, 14913 @ 942
    metasprite Subsprite_1857, 3, 12, 306, 14924 @ 943
    metasprite Subsprite_1860, 3, 14, 306, 14936 @ 944
  Metaprite_945:
    metasprite Subsprite_1863, 3, 48, 311, 14950 @ 945
    metasprite Subsprite_1866, 3, 48, 311, 14998 @ 946
    metasprite Subsprite_1869, 3, 48, 311, 15046 @ 947
  Metaprite_948:
    metasprite Subsprite_1872, 3, 48, 312, 15094 @ 948
    metasprite Subsprite_1875, 3, 48, 312, 15142 @ 949
    metasprite Subsprite_1878, 3, 48, 312, 15190 @ 950
    metasprite Subsprite_1881, 3, 48, 312, 15238 @ 951
    metasprite Subsprite_1884, 3, 48, 312, 15286 @ 952
    metasprite Subsprite_1887, 3, 48, 312, 15334 @ 953
    metasprite Subsprite_1890, 3, 48, 312, 15382 @ 954
    metasprite Subsprite_1893, 3, 48, 312, 15430 @ 955
    metasprite Subsprite_1896, 3, 48, 312, 15478 @ 956
    metasprite Subsprite_1899, 3, 48, 312, 15526 @ 957
    metasprite Subsprite_1902, 3, 48, 312, 15574 @ 958
    metasprite Subsprite_1905, 3, 48, 312, 15622 @ 959
  Metaprite_960:
    metasprite Subsprite_1908, 3, 24, 287, 15670 @ 960
    metasprite Subsprite_1911, 3, 24, 287, 15694 @ 961
  Metaprite_962:
    metasprite Subsprite_1914, 1, 32, 313, 15718 @ 962
    metasprite Subsprite_1915, 3, 24, 313, 15750 @ 963
    metasprite Subsprite_1918, 4, 30, 313, 15774 @ 964
    metasprite Subsprite_1922, 4, 30, 313, 15804 @ 965
  Metaprite_966:
    metasprite Subsprite_1926, 3, 40, 315, 15834 @ 966
    metasprite Subsprite_1929, 3, 40, 315, 15874 @ 967
  Metaprite_968:
    metasprite Subsprite_1932, 1, 4, 316, 15914 @ 968
    metasprite Subsprite_1933, 1, 4, 316, 15918 @ 969
    metasprite Subsprite_1934, 1, 4, 316, 15922 @ 970
    metasprite Subsprite_1935, 1, 2, 316, 15926 @ 971
    metasprite Subsprite_1936, 1, 2, 316, 15928 @ 972
    metasprite Subsprite_1937, 1, 2, 316, 15930 @ 973
    metasprite Subsprite_1938, 1, 2, 316, 15932 @ 974
    metasprite Subsprite_1939, 1, 4, 316, 15934 @ 975
    metasprite Subsprite_1940, 1, 4, 316, 15938 @ 976
  Metaprite_977:
    metasprite Subsprite_1941, 3, 22, 317, 15942 @ 977
  Metaprite_978:
    metasprite Subsprite_1944, 4, 36, 326, 15964 @ 978
  Metaprite_979:
    metasprite Subsprite_1948, 4, 36, 329, 16000 @ 979
  Metaprite_980:
    metasprite Subsprite_1952, 1, 1, 0, 16036 @ 980
    metasprite Subsprite_1953, 1, 1, 0, 16037 @ 981
    metasprite Subsprite_1954, 1, 1, 0, 16038 @ 982
    metasprite Subsprite_1955, 1, 1, 0, 16039 @ 983
    metasprite Subsprite_1956, 1, 1, 0, 16040 @ 984
    metasprite Subsprite_1957, 1, 1, 0, 16041 @ 985
    metasprite Subsprite_1958, 1, 1, 0, 16042 @ 986
    metasprite Subsprite_1959, 1, 1, 0, 16043 @ 987
    metasprite Subsprite_1960, 1, 1, 0, 16044 @ 988
    metasprite Subsprite_1961, 1, 1, 0, 16045 @ 989
    metasprite Subsprite_1962, 1, 1, 0, 16046 @ 990
  Metaprite_991:
    metasprite Subsprite_1963, 3, 6, 332, 16047 @ 991
    metasprite Subsprite_1966, 2, 5, 332, 16053 @ 992
    metasprite Subsprite_1968, 1, 16, 332, 16058 @ 993
    metasprite Subsprite_1969, 2, 5, 332, 16074 @ 994
    metasprite Subsprite_1971, 2, 12, 332, 16079 @ 995
    metasprite Subsprite_1973, 2, 6, 332, 16091 @ 996
    metasprite Subsprite_1975, 1, 16, 332, 16097 @ 997
    metasprite Subsprite_1976, 2, 5, 332, 16113 @ 998
    metasprite Subsprite_1978, 3, 6, 332, 16118 @ 999
    metasprite Subsprite_1981, 2, 5, 332, 16124 @ 1000
    metasprite Subsprite_1983, 1, 16, 332, 16129 @ 1001
    metasprite Subsprite_1984, 2, 5, 332, 16145 @ 1002
    metasprite Subsprite_1986, 2, 12, 332, 16150 @ 1003
    metasprite Subsprite_1988, 2, 5, 332, 16162 @ 1004
    metasprite Subsprite_1990, 1, 16, 332, 16167 @ 1005
    metasprite Subsprite_1991, 2, 5, 332, 16183 @ 1006
    metasprite Subsprite_1993, 1, 8, 332, 16188 @ 1007
    metasprite Subsprite_1994, 1, 16, 332, 16196 @ 1008
    metasprite Subsprite_1995, 1, 8, 332, 16212 @ 1009
    metasprite Subsprite_1996, 1, 16, 332, 16220 @ 1010
    metasprite Subsprite_1997, 1, 8, 332, 16236 @ 1011
    metasprite Subsprite_1998, 3, 8, 332, 16244 @ 1012
    metasprite Subsprite_2001, 4, 9, 332, 16252 @ 1013
  Metaprite_1014:
    metasprite Subsprite_2005, 1, 4, 332, 16261 @ 1014
    metasprite Subsprite_2006, 2, 5, 332, 16265 @ 1015
    metasprite Subsprite_2008, 3, 7, 332, 16270 @ 1016
    metasprite Subsprite_2011, 1, 16, 332, 16277 @ 1017
    metasprite Subsprite_2012, 3, 7, 332, 16293 @ 1018
    metasprite Subsprite_2015, 1, 4, 332, 16300 @ 1019
    metasprite Subsprite_2016, 2, 5, 332, 16304 @ 1020
    metasprite Subsprite_2018, 2, 12, 332, 16309 @ 1021
    metasprite Subsprite_2020, 1, 16, 332, 16321 @ 1022
    metasprite Subsprite_2021, 2, 5, 332, 16337 @ 1023
    metasprite Subsprite_2023, 1, 4, 332, 16342 @ 1024
    metasprite Subsprite_2024, 1, 4, 332, 16346 @ 1025
    metasprite Subsprite_2025, 1, 4, 332, 16350 @ 1026
    metasprite Subsprite_2026, 1, 4, 332, 16354 @ 1027
    metasprite Subsprite_2027, 1, 4, 332, 16358 @ 1028
    metasprite Subsprite_2028, 1, 4, 332, 16362 @ 1029
  Metaprite_1030:
    metasprite Subsprite_2029, 3, 48, 337, 16366 @ 1030
  Metaprite_1031:
    metasprite Subsprite_2032, 1, 64, 338, 16414 @ 1031
  Metaprite_1032:
    metasprite Subsprite_2033, 3, 8, 339, 16478 @ 1032
    metasprite Subsprite_2036, 3, 8, 339, 16486 @ 1033
    metasprite Subsprite_2039, 3, 8, 339, 16494 @ 1034
    metasprite Subsprite_2042, 3, 8, 339, 16502 @ 1035
    metasprite Subsprite_2045, 3, 8, 339, 16510 @ 1036
    metasprite Subsprite_2048, 2, 10, 339, 16518 @ 1037
    metasprite Subsprite_2050, 2, 10, 339, 16528 @ 1038
    metasprite Subsprite_2052, 2, 10, 339, 16538 @ 1039
    metasprite Subsprite_2054, 2, 10, 339, 16548 @ 1040
    metasprite Subsprite_2056, 2, 10, 339, 16558 @ 1041
  Metaprite_1042:
    metasprite Subsprite_2058, 3, 48, 340, 16568 @ 1042
  Metaprite_1043:
    metasprite Subsprite_2061, 4, 36, 341, 16616 @ 1043
    metasprite Subsprite_2065, 4, 36, 341, 16652 @ 1044
    metasprite Subsprite_2069, 1, 64, 341, 16688 @ 1045
    metasprite Subsprite_2070, 1, 64, 341, 16752 @ 1046
  Metaprite_1047:
    metasprite Subsprite_2071, 3, 12, 341, 16816 @ 1047
    metasprite Subsprite_2074, 2, 10, 341, 16828 @ 1048
  Metaprite_1049:
    metasprite Subsprite_2076, 1, 4, 350, 16838 @ 1049
    metasprite Subsprite_2077, 1, 4, 350, 16842 @ 1050
    metasprite Subsprite_2078, 1, 4, 350, 16846 @ 1051
    metasprite Subsprite_2079, 1, 4, 350, 16850 @ 1052
  Metaprite_1053:
    metasprite Subsprite_2080, 1, 4, 350, 16854 @ 1053
    metasprite Subsprite_2081, 1, 4, 350, 16858 @ 1054
    metasprite Subsprite_2082, 1, 4, 350, 16862 @ 1055
    metasprite Subsprite_2083, 1, 4, 350, 16866 @ 1056
    metasprite Subsprite_2084, 1, 4, 350, 16870 @ 1057
    metasprite Subsprite_2085, 1, 4, 350, 16874 @ 1058
    metasprite Subsprite_2086, 1, 4, 350, 16878 @ 1059
    metasprite Subsprite_2087, 1, 4, 350, 16882 @ 1060
    metasprite Subsprite_2088, 1, 4, 350, 16886 @ 1061
    metasprite Subsprite_2089, 1, 4, 350, 16890 @ 1062
    metasprite Subsprite_2090, 1, 4, 350, 16894 @ 1063
    metasprite Subsprite_2091, 1, 4, 350, 16898 @ 1064
    metasprite Subsprite_2092, 1, 4, 350, 16902 @ 1065
  Metaprite_1066:
    metasprite Subsprite_2093, 1, 4, 341, 16906 @ 1066
    metasprite Subsprite_2094, 1, 4, 341, 16910 @ 1067
    metasprite Subsprite_2095, 1, 4, 341, 16914 @ 1068
    metasprite Subsprite_2096, 1, 4, 341, 16918 @ 1069
    metasprite Subsprite_2097, 1, 4, 341, 16922 @ 1070
    metasprite Subsprite_2098, 1, 4, 341, 16926 @ 1071
  Metaprite_1072:
    metasprite Subsprite_2099, 1, 1, 341, 16930 @ 1072
    metasprite Subsprite_2100, 1, 1, 341, 16931 @ 1073
    metasprite Subsprite_2101, 1, 1, 341, 16932 @ 1074
    metasprite Subsprite_2102, 1, 1, 341, 16933 @ 1075
    metasprite Subsprite_2103, 1, 1, 341, 16934 @ 1076
    metasprite Subsprite_2104, 1, 1, 341, 16935 @ 1077
    metasprite Subsprite_2105, 1, 1, 341, 16936 @ 1078
  Metaprite_1079:
    metasprite Subsprite_2106, 3, 48, 83, 16937 @ 1079
    metasprite Subsprite_2109, 3, 48, 83, 16985 @ 1080
    metasprite Subsprite_2112, 3, 48, 83, 17033 @ 1081
    metasprite Subsprite_2115, 4, 30, 83, 17081 @ 1082
    metasprite Subsprite_2119, 4, 30, 83, 17111 @ 1083
    metasprite Subsprite_2123, 3, 48, 83, 17141 @ 1084
    metasprite Subsprite_2126, 3, 48, 83, 17189 @ 1085
    metasprite Subsprite_2129, 3, 48, 83, 17237 @ 1086
    metasprite Subsprite_2132, 3, 48, 83, 17285 @ 1087
    metasprite Subsprite_2135, 1, 1, 83, 17333 @ 1088
    metasprite Subsprite_2136, 3, 48, 83, 17334 @ 1089
  Metaprite_1090:
    metasprite Subsprite_2139, 3, 48, 83, 17382 @ 1090
    metasprite Subsprite_2142, 2, 2, 83, 17430 @ 1091
    metasprite Subsprite_2144, 3, 48, 83, 17432 @ 1092
    metasprite Subsprite_2147, 3, 48, 83, 17480 @ 1093
    metasprite Subsprite_2150, 4, 30, 83, 17528 @ 1094
    metasprite Subsprite_2154, 3, 48, 83, 17558 @ 1095
    metasprite Subsprite_2157, 3, 48, 83, 17606 @ 1096
    metasprite Subsprite_2160, 3, 48, 83, 17654 @ 1097
    metasprite Subsprite_2163, 3, 48, 83, 17702 @ 1098
    metasprite Subsprite_2166, 3, 48, 83, 17750 @ 1099
    metasprite Subsprite_2169, 3, 48, 83, 17798 @ 1100
    metasprite Subsprite_2172, 3, 48, 83, 17846 @ 1101
    metasprite Subsprite_2175, 3, 48, 83, 17894 @ 1102
    metasprite Subsprite_2178, 3, 48, 83, 17942 @ 1103
    metasprite Subsprite_2181, 3, 48, 83, 17990 @ 1104
    metasprite Subsprite_2184, 3, 48, 83, 18038 @ 1105
  Metaprite_1106:
    metasprite Subsprite_2187, 1, 8, 361, 18086 @ 1106
    metasprite Subsprite_2188, 1, 8, 361, 18094 @ 1107
    metasprite Subsprite_2189, 1, 8, 361, 18102 @ 1108
    metasprite Subsprite_2190, 1, 8, 361, 18110 @ 1109
  Metaprite_1110:
    metasprite Subsprite_2191, 3, 8, 287, 18118 @ 1110
    metasprite Subsprite_2194, 3, 8, 287, 18126 @ 1111
  Metaprite_1112:
    metasprite Subsprite_2197, 1, 64, 363, 18134 @ 1112
  Metaprite_1113:
    metasprite Subsprite_2198, 2, 6, 379, 18198 @ 1113
    metasprite Subsprite_2200, 2, 6, 379, 18204 @ 1114
    metasprite Subsprite_2202, 2, 6, 379, 18210 @ 1115
  Metaprite_1116:
    metasprite Subsprite_2204, 1, 4, 380, 18216 @ 1116
    metasprite Subsprite_2205, 1, 16, 380, 18220 @ 1117
    metasprite Subsprite_2206, 1, 16, 380, 18236 @ 1118
  Metaprite_1119:
    metasprite Subsprite_2207, 3, 19, 380, 18252 @ 1119
  Metaprite_1120:
    metasprite Subsprite_2210, 3, 10, 381, 18271 @ 1120
    metasprite Subsprite_2213, 3, 10, 381, 18281 @ 1121
    metasprite Subsprite_2216, 3, 10, 381, 18291 @ 1122
    metasprite Subsprite_2219, 1, 16, 381, 18301 @ 1123
    metasprite Subsprite_2220, 1, 16, 381, 18317 @ 1124
    metasprite Subsprite_2221, 1, 16, 381, 18333 @ 1125
    metasprite Subsprite_2222, 3, 12, 381, 18349 @ 1126
    metasprite Subsprite_2225, 3, 12, 381, 18361 @ 1127
    metasprite Subsprite_2228, 3, 12, 381, 18373 @ 1128
    metasprite Subsprite_2231, 3, 10, 381, 18385 @ 1129
    metasprite Subsprite_2234, 3, 11, 381, 18395 @ 1130
    metasprite Subsprite_2237, 3, 11, 381, 18406 @ 1131
    metasprite Subsprite_2240, 3, 12, 381, 18417 @ 1132
    metasprite Subsprite_2243, 3, 12, 381, 18429 @ 1133
    metasprite Subsprite_2246, 3, 12, 381, 18441 @ 1134
    metasprite Subsprite_2249, 1, 16, 381, 18453 @ 1135
    metasprite Subsprite_2250, 1, 16, 381, 18469 @ 1136
    metasprite Subsprite_2251, 1, 16, 381, 18485 @ 1137
    metasprite Subsprite_2252, 3, 14, 381, 18501 @ 1138
    metasprite Subsprite_2255, 2, 10, 381, 18515 @ 1139
    metasprite Subsprite_2257, 2, 10, 381, 18525 @ 1140
    metasprite Subsprite_2259, 2, 9, 381, 18535 @ 1141
    metasprite Subsprite_2261, 3, 7, 381, 18544 @ 1142
    metasprite Subsprite_2264, 3, 6, 381, 18551 @ 1143
    metasprite Subsprite_2267, 2, 9, 381, 18557 @ 1144
    metasprite Subsprite_2269, 2, 9, 381, 18566 @ 1145
    metasprite Subsprite_2271, 2, 9, 381, 18575 @ 1146
    metasprite Subsprite_2273, 3, 7, 381, 18584 @ 1147
    metasprite Subsprite_2276, 3, 6, 381, 18591 @ 1148
  Metaprite_1149:
    metasprite Subsprite_2279, 1, 1, 386, 18597 @ 1149
    metasprite Subsprite_2280, 1, 1, 386, 18598 @ 1150
    metasprite Subsprite_2281, 1, 1, 386, 18599 @ 1151
    metasprite Subsprite_2282, 1, 1, 386, 18600 @ 1152
    metasprite Subsprite_2283, 1, 1, 386, 18601 @ 1153
  Metaprite_1154:
    metasprite Subsprite_2284, 3, 48, 387, 18602 @ 1154
    metasprite Subsprite_2287, 3, 32, 387, 18650 @ 1155
    metasprite Subsprite_2290, 4, 36, 387, 18682 @ 1156
    metasprite Subsprite_2294, 1, 64, 387, 18718 @ 1157
  Metaprite_1158:
    metasprite Subsprite_2295, 3, 10, 388, 18782 @ 1158
  Metaprite_1159:
    metasprite Subsprite_2298, 2, 9, 181, 18792 @ 1159
  Metaprite_1160:
    metasprite Subsprite_2300, 1, 64, 392, 18801 @ 1160
  Metaprite_1161:
    metasprite Subsprite_2301, 3, 48, 83, 18865 @ 1161
    metasprite Subsprite_2304, 3, 48, 83, 18913 @ 1162
    metasprite Subsprite_2307, 3, 48, 83, 18961 @ 1163
    metasprite Subsprite_2310, 3, 48, 83, 19009 @ 1164
    metasprite Subsprite_2313, 3, 48, 83, 19057 @ 1165
    metasprite Subsprite_2316, 3, 48, 83, 19105 @ 1166
    metasprite Subsprite_2319, 3, 48, 83, 19153 @ 1167
    metasprite Subsprite_2322, 3, 48, 83, 19201 @ 1168
    metasprite Subsprite_2325, 3, 48, 83, 19249 @ 1169
    metasprite Subsprite_2328, 3, 48, 83, 19297 @ 1170
    metasprite Subsprite_2331, 3, 48, 83, 19345 @ 1171
    metasprite Subsprite_2334, 3, 48, 83, 19393 @ 1172
    metasprite Subsprite_2337, 1, 64, 83, 19441 @ 1173
    metasprite Subsprite_2338, 1, 64, 83, 19505 @ 1174
  Metaprite_1175:
    metasprite Subsprite_2339, 2, 17, 404, 19569 @ 1175
    metasprite Subsprite_2341, 3, 24, 404, 19586 @ 1176
  Metaprite_1177:
    metasprite Subsprite_2344, 3, 28, 287, 19610 @ 1177
    metasprite Subsprite_2347, 3, 28, 287, 19638 @ 1178
  Metaprite_1179:
    metasprite Subsprite_2350, 1, 16, 410, 19666 @ 1179
    metasprite Subsprite_2351, 1, 16, 410, 19682 @ 1180
    metasprite Subsprite_2352, 1, 16, 410, 19698 @ 1181
    metasprite Subsprite_2353, 1, 16, 410, 19714 @ 1182
    metasprite Subsprite_2354, 1, 16, 410, 19730 @ 1183
    metasprite Subsprite_2355, 1, 16, 410, 19746 @ 1184
    metasprite Subsprite_2356, 1, 16, 410, 19762 @ 1185
    metasprite Subsprite_2357, 1, 16, 410, 19778 @ 1186
    metasprite Subsprite_2358, 1, 16, 410, 19794 @ 1187
    metasprite Subsprite_2359, 1, 16, 410, 19810 @ 1188
    metasprite Subsprite_2360, 1, 16, 410, 19826 @ 1189
    metasprite Subsprite_2361, 1, 16, 410, 19842 @ 1190
    metasprite Subsprite_2362, 1, 16, 410, 19858 @ 1191
    metasprite Subsprite_2363, 1, 16, 410, 19874 @ 1192
    metasprite Subsprite_2364, 1, 16, 410, 19890 @ 1193
    metasprite Subsprite_2365, 1, 16, 410, 19906 @ 1194
  Metaprite_1195:
    metasprite Subsprite_2366, 3, 48, 83, 19922 @ 1195
    metasprite Subsprite_2369, 3, 48, 83, 19970 @ 1196
    metasprite Subsprite_2372, 3, 48, 83, 20018 @ 1197
    metasprite Subsprite_2375, 3, 48, 83, 20066 @ 1198
    metasprite Subsprite_2378, 3, 48, 83, 20114 @ 1199
    metasprite Subsprite_2381, 3, 48, 83, 20162 @ 1200
    metasprite Subsprite_2384, 3, 48, 83, 20210 @ 1201
    metasprite Subsprite_2387, 3, 48, 83, 20258 @ 1202
    metasprite Subsprite_2390, 4, 36, 83, 20306 @ 1203
  Metaprite_1204:
    metasprite Subsprite_2394, 3, 48, 83, 20342 @ 1204
    metasprite Subsprite_2397, 4, 36, 83, 20390 @ 1205
    metasprite Subsprite_2401, 2, 40, 83, 20426 @ 1206
    metasprite Subsprite_2403, 2, 36, 83, 20466 @ 1207
    metasprite Subsprite_2405, 1, 1, 83, 20502 @ 1208
    metasprite Subsprite_2406, 3, 48, 83, 20503 @ 1209
    metasprite Subsprite_2409, 2, 40, 83, 20551 @ 1210
    metasprite Subsprite_2411, 2, 36, 83, 20591 @ 1211
    metasprite Subsprite_2413, 3, 48, 83, 20627 @ 1212
  Metaprite_1213:
    metasprite Subsprite_2416, 3, 14, 417, 20675 @ 1213
    metasprite Subsprite_2419, 3, 14, 417, 20689 @ 1214
    metasprite Subsprite_2422, 1, 16, 417, 20703 @ 1215
    metasprite Subsprite_2423, 1, 16, 417, 20719 @ 1216
    metasprite Subsprite_2424, 1, 16, 417, 20735 @ 1217
    metasprite Subsprite_2425, 1, 16, 417, 20751 @ 1218
    metasprite Subsprite_2426, 1, 16, 417, 20767 @ 1219
    metasprite Subsprite_2427, 1, 16, 417, 20783 @ 1220
    metasprite Subsprite_2428, 3, 14, 417, 20799 @ 1221
    metasprite Subsprite_2431, 1, 16, 417, 20813 @ 1222
    metasprite Subsprite_2432, 1, 16, 417, 20829 @ 1223
    metasprite Subsprite_2433, 1, 16, 417, 20845 @ 1224
    metasprite Subsprite_2434, 3, 14, 417, 20861 @ 1225
    metasprite Subsprite_2437, 3, 14, 417, 20875 @ 1226
    metasprite Subsprite_2440, 1, 16, 417, 20889 @ 1227
    metasprite Subsprite_2441, 1, 16, 417, 20905 @ 1228
    metasprite Subsprite_2442, 3, 12, 417, 20921 @ 1229
    metasprite Subsprite_2445, 1, 16, 417, 20933 @ 1230
    metasprite Subsprite_2446, 3, 12, 417, 20949 @ 1231
    metasprite Subsprite_2449, 1, 16, 417, 20961 @ 1232
    metasprite Subsprite_2450, 1, 16, 417, 20977 @ 1233
    metasprite Subsprite_2451, 1, 16, 417, 20993 @ 1234
    metasprite Subsprite_2452, 3, 12, 417, 21009 @ 1235
    metasprite Subsprite_2455, 1, 16, 417, 21021 @ 1236
    metasprite Subsprite_2456, 2, 6, 417, 21037 @ 1237
    metasprite Subsprite_2458, 3, 7, 417, 21043 @ 1238
    metasprite Subsprite_2461, 2, 6, 417, 21050 @ 1239
    metasprite Subsprite_2463, 3, 8, 417, 21056 @ 1240
    metasprite Subsprite_2466, 2, 6, 417, 21064 @ 1241
    metasprite Subsprite_2468, 1, 16, 417, 21070 @ 1242
    metasprite Subsprite_2469, 1, 16, 417, 21086 @ 1243
    metasprite Subsprite_2470, 1, 16, 417, 21102 @ 1244
    metasprite Subsprite_2471, 1, 16, 417, 21118 @ 1245
    metasprite Subsprite_2472, 1, 16, 417, 21134 @ 1246
    metasprite Subsprite_2473, 1, 16, 417, 21150 @ 1247
    metasprite Subsprite_2474, 3, 14, 417, 21166 @ 1248
    metasprite Subsprite_2477, 3, 14, 417, 21180 @ 1249
    metasprite Subsprite_2480, 3, 14, 417, 21194 @ 1250
    metasprite Subsprite_2483, 3, 8, 417, 21208 @ 1251
    metasprite Subsprite_2486, 3, 8, 417, 21216 @ 1252
    metasprite Subsprite_2489, 3, 8, 417, 21224 @ 1253
    metasprite Subsprite_2492, 3, 12, 417, 21232 @ 1254
    metasprite Subsprite_2495, 1, 16, 417, 21244 @ 1255
    metasprite Subsprite_2496, 3, 14, 417, 21260 @ 1256
  Metaprite_1257:
    metasprite Subsprite_2499, 3, 22, 417, 21274 @ 1257
    metasprite Subsprite_2502, 3, 22, 417, 21296 @ 1258
    metasprite Subsprite_2505, 3, 21, 417, 21318 @ 1259
    metasprite Subsprite_2508, 3, 19, 417, 21339 @ 1260
    metasprite Subsprite_2511, 2, 18, 417, 21358 @ 1261
    metasprite Subsprite_2513, 3, 48, 417, 21376 @ 1262
    metasprite Subsprite_2516, 4, 30, 417, 21424 @ 1263
    metasprite Subsprite_2520, 4, 36, 417, 21454 @ 1264
    metasprite Subsprite_2524, 3, 19, 417, 21490 @ 1265
    metasprite Subsprite_2527, 2, 24, 417, 21509 @ 1266
    metasprite Subsprite_2529, 2, 24, 417, 21533 @ 1267
    metasprite Subsprite_2531, 3, 24, 417, 21557 @ 1268
    metasprite Subsprite_2534, 2, 24, 417, 21581 @ 1269
    metasprite Subsprite_2536, 3, 24, 417, 21605 @ 1270
    metasprite Subsprite_2539, 2, 24, 417, 21629 @ 1271
    metasprite Subsprite_2541, 3, 22, 417, 21653 @ 1272
    metasprite Subsprite_2544, 3, 22, 417, 21675 @ 1273
    metasprite Subsprite_2547, 3, 22, 417, 21697 @ 1274
    metasprite Subsprite_2550, 2, 18, 417, 21719 @ 1275
    metasprite Subsprite_2552, 2, 18, 417, 21737 @ 1276
    metasprite Subsprite_2554, 3, 48, 417, 21755 @ 1277
    metasprite Subsprite_2557, 3, 40, 417, 21803 @ 1278
    metasprite Subsprite_2560, 4, 36, 417, 21843 @ 1279
    metasprite Subsprite_2564, 2, 24, 417, 21879 @ 1280
    metasprite Subsprite_2566, 2, 24, 417, 21903 @ 1281
  Metaprite_1282:
    metasprite Subsprite_2568, 1, 4, 417, 21927 @ 1282
    metasprite Subsprite_2569, 1, 4, 417, 21931 @ 1283
    metasprite Subsprite_2570, 1, 4, 417, 21935 @ 1284
    metasprite Subsprite_2571, 1, 4, 417, 21939 @ 1285
    metasprite Subsprite_2572, 1, 4, 417, 21943 @ 1286
    metasprite Subsprite_2573, 1, 4, 417, 21947 @ 1287
    metasprite Subsprite_2574, 1, 4, 417, 21951 @ 1288
    metasprite Subsprite_2575, 1, 4, 417, 21955 @ 1289
    metasprite Subsprite_2576, 1, 4, 417, 21959 @ 1290
    metasprite Subsprite_2577, 1, 4, 417, 21963 @ 1291
    metasprite Subsprite_2578, 1, 4, 417, 21967 @ 1292
    metasprite Subsprite_2579, 1, 4, 417, 21971 @ 1293
  Metaprite_1294:
    metasprite Subsprite_2580, 2, 10, 417, 21975 @ 1294
    metasprite Subsprite_2582, 2, 10, 417, 21985 @ 1295
    metasprite Subsprite_2584, 2, 9, 417, 21995 @ 1296
    metasprite Subsprite_2586, 1, 16, 417, 22004 @ 1297
    metasprite Subsprite_2587, 1, 16, 417, 22020 @ 1298
    metasprite Subsprite_2588, 3, 12, 417, 22036 @ 1299
    metasprite Subsprite_2591, 3, 12, 417, 22048 @ 1300
    metasprite Subsprite_2594, 3, 12, 417, 22060 @ 1301
    metasprite Subsprite_2597, 1, 16, 417, 22072 @ 1302
    metasprite Subsprite_2598, 3, 12, 417, 22088 @ 1303
    metasprite Subsprite_2601, 1, 16, 417, 22100 @ 1304
    metasprite Subsprite_2602, 3, 11, 417, 22116 @ 1305
    metasprite Subsprite_2605, 3, 11, 417, 22127 @ 1306
    metasprite Subsprite_2608, 3, 11, 417, 22138 @ 1307
    metasprite Subsprite_2611, 1, 16, 417, 22149 @ 1308
  Metaprite_1309:
    metasprite Subsprite_2612, 2, 6, 29, 22165 @ 1309
    metasprite Subsprite_2614, 2, 5, 29, 22171 @ 1310
    metasprite Subsprite_2616, 2, 5, 29, 22176 @ 1311
    metasprite Subsprite_2618, 1, 4, 29, 22181 @ 1312
    metasprite Subsprite_2619, 1, 4, 29, 22185 @ 1313
    metasprite Subsprite_2620, 1, 4, 29, 22189 @ 1314
    metasprite Subsprite_2621, 2, 5, 29, 22193 @ 1315
    metasprite Subsprite_2623, 2, 6, 29, 22198 @ 1316
    metasprite Subsprite_2625, 2, 5, 29, 22204 @ 1317
    metasprite Subsprite_2627, 1, 4, 29, 22209 @ 1318
    metasprite Subsprite_2628, 2, 5, 29, 22213 @ 1319
    metasprite Subsprite_2630, 1, 4, 29, 22218 @ 1320
    metasprite Subsprite_2631, 2, 6, 29, 22222 @ 1321
    metasprite Subsprite_2633, 2, 6, 29, 22228 @ 1322
    metasprite Subsprite_2635, 2, 6, 29, 22234 @ 1323
    metasprite Subsprite_2637, 1, 8, 29, 22240 @ 1324
    metasprite Subsprite_2638, 2, 5, 29, 22248 @ 1325
    metasprite Subsprite_2640, 3, 6, 29, 22253 @ 1326
    metasprite Subsprite_2643, 2, 5, 29, 22259 @ 1327
    metasprite Subsprite_2645, 1, 4, 29, 22264 @ 1328
    metasprite Subsprite_2646, 1, 4, 29, 22268 @ 1329
    metasprite Subsprite_2647, 2, 5, 29, 22272 @ 1330
  Metaprite_1331:
    metasprite Subsprite_2649, 3, 48, 83, 22277 @ 1331
    metasprite Subsprite_2652, 3, 48, 83, 22325 @ 1332
    metasprite Subsprite_2655, 3, 48, 83, 22373 @ 1333
    metasprite Subsprite_2658, 3, 48, 83, 22421 @ 1334
    metasprite Subsprite_2661, 1, 2, 83, 22469 @ 1335
    metasprite Subsprite_2662, 3, 48, 83, 22471 @ 1336
    metasprite Subsprite_2665, 1, 32, 83, 22519 @ 1337
    metasprite Subsprite_2666, 3, 48, 83, 22551 @ 1338
    metasprite Subsprite_2669, 1, 32, 83, 22599 @ 1339
    metasprite Subsprite_2670, 4, 36, 83, 22631 @ 1340
    metasprite Subsprite_2674, 3, 48, 83, 22667 @ 1341
    metasprite Subsprite_2677, 3, 48, 83, 22715 @ 1342
  Metaprite_1343:
    metasprite Subsprite_2680, 3, 48, 83, 22763 @ 1343
    metasprite Subsprite_2683, 3, 48, 83, 22811 @ 1344
    metasprite Subsprite_2686, 3, 48, 83, 22859 @ 1345
    metasprite Subsprite_2689, 3, 48, 83, 22907 @ 1346
    metasprite Subsprite_2692, 4, 36, 83, 22955 @ 1347
    metasprite Subsprite_2696, 2, 40, 83, 22991 @ 1348
    metasprite Subsprite_2698, 3, 48, 83, 23031 @ 1349
    metasprite Subsprite_2701, 3, 48, 83, 23079 @ 1350
    metasprite Subsprite_2704, 3, 48, 83, 23127 @ 1351
    metasprite Subsprite_2707, 3, 48, 83, 23175 @ 1352
    metasprite Subsprite_2710, 3, 48, 83, 23223 @ 1353
    metasprite Subsprite_2713, 3, 48, 83, 23271 @ 1354
    metasprite Subsprite_2716, 3, 48, 83, 23319 @ 1355
  Metaprite_1356:
    metasprite Subsprite_2719, 3, 48, 433, 23367 @ 1356
    metasprite Subsprite_2722, 3, 48, 433, 23415 @ 1357
  Metaprite_1358:
    metasprite Subsprite_2725, 2, 20, 435, 23463 @ 1358
    metasprite Subsprite_2727, 2, 10, 435, 23483 @ 1359
  Metaprite_1360:
    metasprite Subsprite_2729, 3, 14, 438, 23493 @ 1360
    metasprite Subsprite_2732, 3, 14, 438, 23507 @ 1361
    metasprite Subsprite_2735, 1, 16, 438, 23521 @ 1362
    metasprite Subsprite_2736, 1, 16, 438, 23537 @ 1363
    metasprite Subsprite_2737, 2, 12, 438, 23553 @ 1364
    metasprite Subsprite_2739, 1, 16, 438, 23565 @ 1365
    metasprite Subsprite_2740, 3, 9, 438, 23581 @ 1366
  Metaprite_1367:
    metasprite Subsprite_2743, 4, 36, 439, 23590 @ 1367
  Metaprite_1368:
    metasprite Subsprite_2747, 3, 48, 439, 23626 @ 1368
  Metaprite_1369:
    metasprite Subsprite_2750, 3, 48, 439, 23674 @ 1369
  Metaprite_1370:
    metasprite Subsprite_2753, 3, 48, 439, 23722 @ 1370
  Metaprite_1371:
    metasprite Subsprite_2756, 4, 36, 439, 23770 @ 1371
  Metaprite_1372:
    metasprite Subsprite_2760, 4, 36, 439, 23806 @ 1372
  Metaprite_1373:
    metasprite Subsprite_2764, 2, 24, 447, 23842 @ 1373
    metasprite Subsprite_2766, 2, 20, 447, 23866 @ 1374
    metasprite Subsprite_2768, 2, 20, 447, 23886 @ 1375
    metasprite Subsprite_2770, 2, 24, 447, 23906 @ 1376
    metasprite Subsprite_2772, 3, 14, 447, 23930 @ 1377
    metasprite Subsprite_2775, 2, 24, 447, 23944 @ 1378
    metasprite Subsprite_2777, 2, 24, 447, 23968 @ 1379
    metasprite Subsprite_2779, 2, 5, 447, 23992 @ 1380
    metasprite Subsprite_2781, 1, 16, 447, 23997 @ 1381
    metasprite Subsprite_2782, 2, 20, 447, 24013 @ 1382
    metasprite Subsprite_2784, 3, 14, 447, 24033 @ 1383
    metasprite Subsprite_2787, 4, 9, 447, 24047 @ 1384
    metasprite Subsprite_2791, 3, 7, 447, 24056 @ 1385
    metasprite Subsprite_2794, 4, 15, 447, 24063 @ 1386
    metasprite Subsprite_2798, 1, 16, 447, 24078 @ 1387
    metasprite Subsprite_2799, 3, 24, 447, 24094 @ 1388
    metasprite Subsprite_2802, 2, 20, 447, 24118 @ 1389
    metasprite Subsprite_2804, 1, 64, 447, 24138 @ 1390
    metasprite Subsprite_2805, 3, 28, 447, 24202 @ 1391
    metasprite Subsprite_2808, 1, 32, 447, 24230 @ 1392
    metasprite Subsprite_2809, 2, 24, 447, 24262 @ 1393
    metasprite Subsprite_2811, 3, 16, 447, 24286 @ 1394
    metasprite Subsprite_2814, 2, 24, 447, 24302 @ 1395
    metasprite Subsprite_2816, 2, 24, 447, 24326 @ 1396
    metasprite Subsprite_2818, 2, 40, 447, 24350 @ 1397
    metasprite Subsprite_2820, 2, 24, 447, 24390 @ 1398
    metasprite Subsprite_2822, 3, 24, 447, 24414 @ 1399
    metasprite Subsprite_2825, 2, 24, 447, 24438 @ 1400
    metasprite Subsprite_2827, 1, 32, 447, 24462 @ 1401
    metasprite Subsprite_2828, 1, 32, 447, 24494 @ 1402
    metasprite Subsprite_2829, 1, 32, 447, 24526 @ 1403
    metasprite Subsprite_2830, 1, 32, 447, 24558 @ 1404
    metasprite Subsprite_2831, 1, 32, 447, 24590 @ 1405
    metasprite Subsprite_2832, 2, 20, 447, 24622 @ 1406
    metasprite Subsprite_2834, 1, 16, 447, 24642 @ 1407
  Metaprite_1408:
    metasprite Subsprite_2835, 3, 14, 447, 24658 @ 1408
  Metaprite_1409:
    metasprite Subsprite_2838, 3, 48, 83, 24672 @ 1409
    metasprite Subsprite_2841, 3, 48, 83, 24720 @ 1410
    metasprite Subsprite_2844, 3, 48, 83, 24768 @ 1411
    metasprite Subsprite_2847, 3, 48, 83, 24816 @ 1412
    metasprite Subsprite_2850, 3, 48, 83, 24864 @ 1413
    metasprite Subsprite_2853, 3, 48, 83, 24912 @ 1414
  Metaprite_1415:
    metasprite Subsprite_2856, 3, 48, 83, 24960 @ 1415
    metasprite Subsprite_2859, 3, 48, 83, 25008 @ 1416
    metasprite Subsprite_2862, 3, 48, 83, 25056 @ 1417
    metasprite Subsprite_2865, 3, 48, 83, 25104 @ 1418
    metasprite Subsprite_2868, 3, 48, 83, 25152 @ 1419
    metasprite Subsprite_2871, 3, 48, 83, 25200 @ 1420
    metasprite Subsprite_2874, 3, 48, 83, 25248 @ 1421
    metasprite Subsprite_2877, 3, 48, 83, 25296 @ 1422
    metasprite Subsprite_2880, 3, 48, 83, 25344 @ 1423
    metasprite Subsprite_2883, 3, 48, 83, 25392 @ 1424
    metasprite Subsprite_2886, 3, 48, 83, 25440 @ 1425
    metasprite Subsprite_2889, 3, 48, 83, 25488 @ 1426
    metasprite Subsprite_2892, 3, 48, 83, 25536 @ 1427
  Metaprite_1428:
    metasprite Subsprite_2895, 3, 48, 83, 25584 @ 1428
    metasprite Subsprite_2898, 3, 48, 83, 25632 @ 1429
    metasprite Subsprite_2901, 3, 48, 83, 25680 @ 1430
    metasprite Subsprite_2904, 3, 48, 83, 25728 @ 1431
    metasprite Subsprite_2907, 3, 48, 83, 25776 @ 1432
    metasprite Subsprite_2910, 3, 48, 83, 25824 @ 1433
    metasprite Subsprite_2913, 3, 48, 83, 25872 @ 1434
    metasprite Subsprite_2916, 3, 48, 83, 25920 @ 1435
    metasprite Subsprite_2919, 3, 48, 83, 25968 @ 1436
  Metaprite_1437:
    metasprite Subsprite_2922, 3, 20, 451, 26016 @ 1437
    metasprite Subsprite_2925, 4, 30, 451, 26036 @ 1438
    metasprite Subsprite_2929, 3, 48, 451, 26066 @ 1439
    metasprite Subsprite_2932, 3, 48, 451, 26114 @ 1440
    metasprite Subsprite_2935, 3, 48, 451, 26162 @ 1441
    metasprite Subsprite_2938, 3, 48, 451, 26210 @ 1442
    metasprite Subsprite_2941, 3, 48, 451, 26258 @ 1443
    metasprite Subsprite_2944, 3, 48, 451, 26306 @ 1444
    metasprite Subsprite_2947, 3, 48, 451, 26354 @ 1445
    metasprite Subsprite_2950, 4, 30, 451, 26402 @ 1446
    metasprite Subsprite_2954, 3, 48, 451, 26432 @ 1447
    metasprite Subsprite_2957, 3, 48, 451, 26480 @ 1448
    metasprite Subsprite_2960, 3, 48, 451, 26528 @ 1449
    metasprite Subsprite_2963, 3, 48, 451, 26576 @ 1450
    metasprite Subsprite_2966, 3, 48, 451, 26624 @ 1451
    metasprite Subsprite_2969, 3, 48, 451, 26672 @ 1452
    metasprite Subsprite_2972, 4, 36, 451, 26720 @ 1453
  Metaprite_1454:
    metasprite Subsprite_2976, 4, 36, 460, 26756 @ 1454
    metasprite Subsprite_2980, 1, 64, 460, 26792 @ 1455
  Metaprite_1456:
    metasprite Subsprite_2981, 3, 11, 466, 26856 @ 1456
    metasprite Subsprite_2984, 3, 11, 466, 26867 @ 1457
    metasprite Subsprite_2987, 3, 11, 466, 26878 @ 1458
    metasprite Subsprite_2990, 3, 11, 466, 26889 @ 1459
  Metaprite_1460:
    metasprite Subsprite_2993, 3, 28, 287, 26900 @ 1460
    metasprite Subsprite_2996, 3, 28, 287, 26928 @ 1461
  Metaprite_1462:
    metasprite Subsprite_2999, 3, 48, 83, 26956 @ 1462
    metasprite Subsprite_3002, 3, 48, 83, 27004 @ 1463
    metasprite Subsprite_3005, 3, 48, 83, 27052 @ 1464
    metasprite Subsprite_3008, 3, 48, 83, 27100 @ 1465
    metasprite Subsprite_3011, 3, 48, 83, 27148 @ 1466
    metasprite Subsprite_3014, 3, 48, 83, 27196 @ 1467
    metasprite Subsprite_3017, 3, 48, 83, 27244 @ 1468
    metasprite Subsprite_3020, 3, 48, 83, 27292 @ 1469
    metasprite Subsprite_3023, 3, 48, 83, 27340 @ 1470
    metasprite Subsprite_3026, 4, 30, 83, 27388 @ 1471
    metasprite Subsprite_3030, 3, 48, 83, 27418 @ 1472
  Metaprite_1473:
    metasprite Subsprite_3033, 1, 1, 467, 27466 @ 1473
    metasprite Subsprite_3034, 1, 1, 467, 27467 @ 1474
    metasprite Subsprite_3035, 1, 1, 467, 27468 @ 1475
    metasprite Subsprite_3036, 1, 1, 467, 27469 @ 1476
  Metaprite_1477:
    metasprite Subsprite_3037, 3, 48, 482, 27470 @ 1477
  Metaprite_1478:
    metasprite Subsprite_3040, 1, 64, 498, 27518 @ 1478
  Metaprite_1479:
    metasprite Subsprite_3041, 3, 48, 83, 27582 @ 1479
    metasprite Subsprite_3044, 3, 48, 83, 27630 @ 1480
    metasprite Subsprite_3047, 3, 48, 83, 27678 @ 1481
    metasprite Subsprite_3050, 3, 48, 83, 27726 @ 1482
    metasprite Subsprite_3053, 3, 48, 83, 27774 @ 1483
    metasprite Subsprite_3056, 3, 48, 83, 27822 @ 1484
    metasprite Subsprite_3059, 3, 48, 83, 27870 @ 1485
    metasprite Subsprite_3062, 3, 48, 83, 27918 @ 1486
    metasprite Subsprite_3065, 3, 48, 83, 27966 @ 1487
    metasprite Subsprite_3068, 3, 48, 83, 28014 @ 1488
    metasprite Subsprite_3071, 3, 48, 83, 28062 @ 1489
    metasprite Subsprite_3074, 3, 48, 83, 28110 @ 1490
    metasprite Subsprite_3077, 3, 48, 83, 28158 @ 1491
    metasprite Subsprite_3080, 4, 36, 83, 28206 @ 1492
  Metaprite_1493:
    metasprite Subsprite_3084, 4, 25, 501, 28242 @ 1493
    metasprite Subsprite_3088, 3, 18, 501, 28267 @ 1494
    metasprite Subsprite_3091, 4, 30, 501, 28285 @ 1495
    metasprite Subsprite_3095, 4, 30, 501, 28315 @ 1496
    metasprite Subsprite_3099, 4, 30, 501, 28345 @ 1497
    metasprite Subsprite_3103, 4, 30, 501, 28375 @ 1498
    metasprite Subsprite_3107, 3, 18, 501, 28405 @ 1499
    metasprite Subsprite_3110, 3, 18, 501, 28423 @ 1500
    metasprite Subsprite_3113, 3, 18, 501, 28441 @ 1501
    metasprite Subsprite_3116, 3, 24, 501, 28459 @ 1502
    metasprite Subsprite_3119, 3, 24, 501, 28483 @ 1503
    metasprite Subsprite_3122, 3, 24, 501, 28507 @ 1504
    metasprite Subsprite_3125, 3, 24, 501, 28531 @ 1505
    metasprite Subsprite_3128, 3, 24, 501, 28555 @ 1506
    metasprite Subsprite_3131, 3, 24, 501, 28579 @ 1507
    metasprite Subsprite_3134, 3, 28, 501, 28603 @ 1508
    metasprite Subsprite_3137, 3, 40, 501, 28631 @ 1509
    metasprite Subsprite_3140, 3, 40, 501, 28671 @ 1510
    metasprite Subsprite_3143, 3, 40, 501, 28711 @ 1511
    metasprite Subsprite_3146, 3, 28, 501, 28751 @ 1512
    metasprite Subsprite_3149, 3, 28, 501, 28779 @ 1513
    metasprite Subsprite_3152, 3, 28, 501, 28807 @ 1514
    metasprite Subsprite_3155, 4, 30, 501, 28835 @ 1515
    metasprite Subsprite_3159, 4, 30, 501, 28865 @ 1516
    metasprite Subsprite_3163, 4, 30, 501, 28895 @ 1517
    metasprite Subsprite_3167, 4, 25, 501, 28925 @ 1518
    metasprite Subsprite_3171, 4, 25, 501, 28950 @ 1519
    metasprite Subsprite_3175, 4, 25, 501, 28975 @ 1520
    metasprite Subsprite_3179, 4, 25, 501, 29000 @ 1521
    metasprite Subsprite_3183, 4, 25, 501, 29025 @ 1522
    metasprite Subsprite_3187, 3, 28, 501, 29050 @ 1523
    metasprite Subsprite_3190, 3, 18, 501, 29078 @ 1524
    metasprite Subsprite_3193, 3, 18, 501, 29096 @ 1525
    metasprite Subsprite_3196, 3, 18, 501, 29114 @ 1526
    metasprite Subsprite_3199, 3, 24, 501, 29132 @ 1527
    metasprite Subsprite_3202, 3, 28, 501, 29156 @ 1528
    metasprite Subsprite_3205, 3, 24, 501, 29184 @ 1529
    metasprite Subsprite_3208, 3, 24, 501, 29208 @ 1530
    metasprite Subsprite_3211, 4, 30, 501, 29232 @ 1531
    metasprite Subsprite_3215, 4, 36, 501, 29262 @ 1532
    metasprite Subsprite_3219, 4, 36, 501, 29298 @ 1533
    metasprite Subsprite_3223, 3, 24, 501, 29334 @ 1534
    metasprite Subsprite_3226, 2, 40, 501, 29358 @ 1535
    metasprite Subsprite_3228, 2, 40, 501, 29398 @ 1536
    metasprite Subsprite_3230, 3, 48, 501, 29438 @ 1537
    metasprite Subsprite_3233, 3, 48, 501, 29486 @ 1538
    metasprite Subsprite_3236, 3, 28, 501, 29534 @ 1539
    metasprite Subsprite_3239, 3, 28, 501, 29562 @ 1540
    metasprite Subsprite_3242, 3, 24, 501, 29590 @ 1541
    metasprite Subsprite_3245, 4, 25, 501, 29614 @ 1542
    metasprite Subsprite_3249, 4, 30, 501, 29639 @ 1543
    metasprite Subsprite_3253, 3, 26, 501, 29669 @ 1544
    metasprite Subsprite_3256, 4, 25, 501, 29695 @ 1545
    metasprite Subsprite_3260, 4, 25, 501, 29720 @ 1546
    metasprite Subsprite_3264, 4, 25, 501, 29745 @ 1547
    metasprite Subsprite_3268, 3, 24, 501, 29770 @ 1548
    metasprite Subsprite_3271, 3, 28, 501, 29794 @ 1549
    metasprite Subsprite_3274, 2, 40, 501, 29822 @ 1550
    metasprite Subsprite_3276, 3, 28, 501, 29862 @ 1551
    metasprite Subsprite_3279, 3, 28, 501, 29890 @ 1552
    metasprite Subsprite_3282, 3, 24, 501, 29918 @ 1553
    metasprite Subsprite_3285, 2, 16, 501, 29942 @ 1554
    metasprite Subsprite_3287, 2, 20, 501, 29958 @ 1555
    metasprite Subsprite_3289, 2, 16, 501, 29978 @ 1556
  Metaprite_1557:
    metasprite Subsprite_3291, 2, 20, 501, 29994 @ 1557
    metasprite Subsprite_3293, 3, 24, 501, 30014 @ 1558
    metasprite Subsprite_3296, 1, 16, 501, 30038 @ 1559
    metasprite Subsprite_3297, 3, 20, 501, 30054 @ 1560
    metasprite Subsprite_3300, 2, 20, 501, 30074 @ 1561
    metasprite Subsprite_3302, 3, 28, 501, 30094 @ 1562
    metasprite Subsprite_3305, 2, 20, 501, 30122 @ 1563
    metasprite Subsprite_3307, 3, 28, 501, 30142 @ 1564
    metasprite Subsprite_3310, 2, 20, 501, 30170 @ 1565
    metasprite Subsprite_3312, 3, 28, 501, 30190 @ 1566
    metasprite Subsprite_3315, 2, 24, 501, 30218 @ 1567
    metasprite Subsprite_3317, 3, 28, 501, 30242 @ 1568
    metasprite Subsprite_3320, 2, 24, 501, 30270 @ 1569
    metasprite Subsprite_3322, 2, 24, 501, 30294 @ 1570
    metasprite Subsprite_3324, 2, 20, 501, 30318 @ 1571
    metasprite Subsprite_3326, 3, 24, 501, 30338 @ 1572
    metasprite Subsprite_3329, 3, 28, 501, 30362 @ 1573
    metasprite Subsprite_3332, 3, 28, 501, 30390 @ 1574
  Metaprite_1575:
    metasprite Subsprite_3335, 4, 30, 506, 30418 @ 1575
    metasprite Subsprite_3339, 3, 22, 506, 30448 @ 1576
    metasprite Subsprite_3342, 2, 20, 506, 30470 @ 1577
    metasprite Subsprite_3344, 2, 24, 506, 30490 @ 1578
    metasprite Subsprite_3346, 1, 32, 506, 30514 @ 1579
    metasprite Subsprite_3347, 2, 36, 506, 30546 @ 1580
    metasprite Subsprite_3349, 3, 22, 506, 30582 @ 1581
    metasprite Subsprite_3352, 2, 24, 506, 30604 @ 1582
    metasprite Subsprite_3354, 3, 28, 506, 30628 @ 1583
    metasprite Subsprite_3357, 3, 40, 506, 30656 @ 1584
    metasprite Subsprite_3360, 2, 24, 506, 30696 @ 1585
    metasprite Subsprite_3362, 2, 24, 506, 30720 @ 1586
    metasprite Subsprite_3364, 3, 19, 506, 30744 @ 1587
    metasprite Subsprite_3367, 4, 30, 506, 30763 @ 1588
    metasprite Subsprite_3371, 2, 20, 506, 30793 @ 1589
    metasprite Subsprite_3373, 2, 20, 506, 30813 @ 1590
    metasprite Subsprite_3375, 2, 24, 506, 30833 @ 1591
    metasprite Subsprite_3377, 3, 19, 506, 30857 @ 1592
    metasprite Subsprite_3380, 3, 28, 506, 30876 @ 1593
    metasprite Subsprite_3383, 3, 20, 506, 30904 @ 1594
    metasprite Subsprite_3386, 3, 20, 506, 30924 @ 1595
    metasprite Subsprite_3389, 3, 20, 506, 30944 @ 1596
    metasprite Subsprite_3392, 3, 20, 506, 30964 @ 1597
    metasprite Subsprite_3395, 3, 20, 506, 30984 @ 1598
    metasprite Subsprite_3398, 3, 19, 506, 31004 @ 1599
    metasprite Subsprite_3401, 2, 20, 506, 31023 @ 1600
    metasprite Subsprite_3403, 3, 19, 506, 31043 @ 1601
    metasprite Subsprite_3406, 2, 17, 506, 31062 @ 1602
    metasprite Subsprite_3408, 1, 16, 506, 31079 @ 1603
    metasprite Subsprite_3409, 1, 16, 506, 31095 @ 1604
    metasprite Subsprite_3410, 1, 16, 506, 31111 @ 1605
    metasprite Subsprite_3411, 1, 16, 506, 31127 @ 1606
    metasprite Subsprite_3412, 4, 30, 506, 31143 @ 1607
    metasprite Subsprite_3416, 4, 36, 506, 31173 @ 1608
    metasprite Subsprite_3420, 4, 36, 506, 31209 @ 1609
    metasprite Subsprite_3424, 4, 36, 506, 31245 @ 1610
    metasprite Subsprite_3428, 3, 48, 506, 31281 @ 1611
    metasprite Subsprite_3431, 4, 30, 506, 31329 @ 1612
    metasprite Subsprite_3435, 4, 36, 506, 31359 @ 1613
    metasprite Subsprite_3439, 4, 36, 506, 31395 @ 1614
    metasprite Subsprite_3443, 2, 24, 506, 31431 @ 1615
    metasprite Subsprite_3445, 2, 24, 506, 31455 @ 1616
    metasprite Subsprite_3447, 3, 21, 506, 31479 @ 1617
    metasprite Subsprite_3450, 2, 24, 506, 31500 @ 1618
    metasprite Subsprite_3452, 4, 15, 506, 31524 @ 1619
    metasprite Subsprite_3456, 3, 28, 506, 31539 @ 1620
    metasprite Subsprite_3459, 4, 18, 506, 31567 @ 1621
    metasprite Subsprite_3463, 3, 19, 506, 31585 @ 1622
    metasprite Subsprite_3466, 2, 20, 506, 31604 @ 1623
    metasprite Subsprite_3468, 4, 30, 506, 31624 @ 1624
    metasprite Subsprite_3472, 2, 24, 506, 31654 @ 1625
    metasprite Subsprite_3474, 2, 24, 506, 31678 @ 1626
    metasprite Subsprite_3476, 3, 19, 506, 31702 @ 1627
  Metaprite_1628:
    metasprite Subsprite_3479, 2, 24, 506, 31721 @ 1628
    metasprite Subsprite_3481, 2, 24, 506, 31745 @ 1629
    metasprite Subsprite_3483, 2, 24, 506, 31769 @ 1630
    metasprite Subsprite_3485, 2, 24, 506, 31793 @ 1631
    metasprite Subsprite_3487, 2, 24, 506, 31817 @ 1632
    metasprite Subsprite_3489, 2, 24, 506, 31841 @ 1633
    metasprite Subsprite_3491, 2, 24, 506, 31865 @ 1634
    metasprite Subsprite_3493, 2, 24, 506, 31889 @ 1635
    metasprite Subsprite_3495, 2, 24, 506, 31913 @ 1636
    metasprite Subsprite_3497, 2, 24, 506, 31937 @ 1637
    metasprite Subsprite_3499, 2, 24, 506, 31961 @ 1638
    metasprite Subsprite_3501, 2, 24, 506, 31985 @ 1639
    metasprite Subsprite_3503, 2, 24, 506, 32009 @ 1640
    metasprite Subsprite_3505, 2, 24, 506, 32033 @ 1641
    metasprite Subsprite_3507, 2, 24, 506, 32057 @ 1642
    metasprite Subsprite_3509, 2, 24, 506, 32081 @ 1643
    metasprite Subsprite_3511, 2, 24, 506, 32105 @ 1644
    metasprite Subsprite_3513, 2, 24, 506, 32129 @ 1645
    metasprite Subsprite_3515, 2, 24, 506, 32153 @ 1646
    metasprite Subsprite_3517, 2, 24, 506, 32177 @ 1647
    metasprite Subsprite_3519, 2, 24, 506, 32201 @ 1648
    metasprite Subsprite_3521, 2, 24, 506, 32225 @ 1649
    metasprite Subsprite_3523, 3, 22, 506, 32249 @ 1650
    metasprite Subsprite_3526, 3, 22, 506, 32271 @ 1651
    metasprite Subsprite_3529, 2, 24, 506, 32293 @ 1652
    metasprite Subsprite_3531, 3, 22, 506, 32317 @ 1653
    metasprite Subsprite_3534, 3, 22, 506, 32339 @ 1654
    metasprite Subsprite_3537, 3, 22, 506, 32361 @ 1655
    metasprite Subsprite_3540, 3, 22, 506, 32383 @ 1656
    metasprite Subsprite_3543, 2, 24, 506, 32405 @ 1657
    metasprite Subsprite_3545, 2, 24, 506, 32429 @ 1658
    metasprite Subsprite_3547, 3, 20, 506, 32453 @ 1659
    metasprite Subsprite_3550, 2, 24, 506, 32473 @ 1660
    metasprite Subsprite_3552, 2, 24, 506, 32497 @ 1661
    metasprite Subsprite_3554, 2, 24, 506, 32521 @ 1662
    metasprite Subsprite_3556, 2, 24, 506, 32545 @ 1663
    metasprite Subsprite_3558, 3, 20, 506, 32569 @ 1664
    metasprite Subsprite_3561, 3, 20, 506, 32589 @ 1665
    metasprite Subsprite_3564, 3, 20, 506, 32609 @ 1666
    metasprite Subsprite_3567, 3, 20, 506, 32629 @ 1667
    metasprite Subsprite_3570, 3, 20, 506, 32649 @ 1668
    metasprite Subsprite_3573, 3, 20, 506, 32669 @ 1669
    metasprite Subsprite_3576, 3, 20, 506, 32689 @ 1670
    metasprite Subsprite_3579, 3, 20, 506, 32709 @ 1671
  Metaprite_1672:
    metasprite Subsprite_3582, 3, 48, 509, 32729 @ 1672
  Metaprite_1673:
    metasprite Subsprite_3585, 1, 16, 509, 32777 @ 1673
  Metaprite_1674:
    metasprite Subsprite_3586, 1, 1, 509, 32793 @ 1674
  Metaprite_1675:
    metasprite Subsprite_3587, 2, 24, 513, 32794 @ 1675
    metasprite Subsprite_3589, 2, 20, 513, 32818 @ 1676
    metasprite Subsprite_3591, 3, 24, 513, 32838 @ 1677
    metasprite Subsprite_3594, 3, 24, 513, 32862 @ 1678
    metasprite Subsprite_3597, 3, 24, 513, 32886 @ 1679
    metasprite Subsprite_3600, 3, 24, 513, 32910 @ 1680
    metasprite Subsprite_3603, 3, 14, 513, 32934 @ 1681
    metasprite Subsprite_3606, 3, 14, 513, 32948 @ 1682
    metasprite Subsprite_3609, 3, 14, 513, 32962 @ 1683
    metasprite Subsprite_3612, 3, 24, 513, 32976 @ 1684
    metasprite Subsprite_3615, 3, 14, 513, 33000 @ 1685
    metasprite Subsprite_3618, 3, 14, 513, 33014 @ 1686
    metasprite Subsprite_3621, 3, 14, 513, 33028 @ 1687
    metasprite Subsprite_3624, 3, 24, 513, 33042 @ 1688
    metasprite Subsprite_3627, 3, 24, 513, 33066 @ 1689
    metasprite Subsprite_3630, 3, 24, 513, 33090 @ 1690
    metasprite Subsprite_3633, 3, 24, 513, 33114 @ 1691
    metasprite Subsprite_3636, 3, 24, 513, 33138 @ 1692
    metasprite Subsprite_3639, 3, 26, 513, 33162 @ 1693
    metasprite Subsprite_3642, 3, 18, 513, 33188 @ 1694
    metasprite Subsprite_3645, 2, 20, 513, 33206 @ 1695
    metasprite Subsprite_3647, 2, 20, 513, 33226 @ 1696
    metasprite Subsprite_3649, 3, 28, 513, 33246 @ 1697
    metasprite Subsprite_3652, 3, 18, 513, 33274 @ 1698
    metasprite Subsprite_3655, 2, 20, 513, 33292 @ 1699
    metasprite Subsprite_3657, 2, 20, 513, 33312 @ 1700
    metasprite Subsprite_3659, 2, 20, 513, 33332 @ 1701
    metasprite Subsprite_3661, 2, 20, 513, 33352 @ 1702
    metasprite Subsprite_3663, 4, 9, 513, 33372 @ 1703
    metasprite Subsprite_3667, 4, 9, 513, 33381 @ 1704
    metasprite Subsprite_3671, 4, 9, 513, 33390 @ 1705
    metasprite Subsprite_3675, 4, 9, 513, 33399 @ 1706
    metasprite Subsprite_3679, 4, 9, 513, 33408 @ 1707
    metasprite Subsprite_3683, 4, 9, 513, 33417 @ 1708
    metasprite Subsprite_3687, 4, 9, 513, 33426 @ 1709
    metasprite Subsprite_3691, 4, 9, 513, 33435 @ 1710
    metasprite Subsprite_3695, 4, 9, 513, 33444 @ 1711
    metasprite Subsprite_3699, 4, 9, 513, 33453 @ 1712
    metasprite Subsprite_3703, 4, 9, 513, 33462 @ 1713
    metasprite Subsprite_3707, 4, 9, 513, 33471 @ 1714
    metasprite Subsprite_3711, 3, 24, 513, 33480 @ 1715
    metasprite Subsprite_3714, 3, 24, 513, 33504 @ 1716
    metasprite Subsprite_3717, 2, 20, 513, 33528 @ 1717
    metasprite Subsprite_3719, 2, 24, 513, 33548 @ 1718
    metasprite Subsprite_3721, 3, 24, 513, 33572 @ 1719
    metasprite Subsprite_3724, 3, 17, 513, 33596 @ 1720
    metasprite Subsprite_3727, 3, 24, 513, 33613 @ 1721
  Metaprite_1722:
    metasprite Subsprite_3730, 1, 16, 44, 33637 @ 1722
    metasprite Subsprite_3731, 1, 16, 44, 33653 @ 1723
    metasprite Subsprite_3732, 1, 16, 44, 33669 @ 1724
    metasprite Subsprite_3733, 1, 16, 44, 33685 @ 1725
    metasprite Subsprite_3734, 1, 16, 44, 33701 @ 1726
    metasprite Subsprite_3735, 1, 16, 44, 33717 @ 1727
    metasprite Subsprite_3736, 1, 16, 44, 33733 @ 1728
    metasprite Subsprite_3737, 1, 16, 44, 33749 @ 1729
    metasprite Subsprite_3738, 1, 16, 44, 33765 @ 1730
    metasprite Subsprite_3739, 1, 16, 44, 33781 @ 1731
    metasprite Subsprite_3740, 1, 16, 44, 33797 @ 1732
    metasprite Subsprite_3741, 1, 16, 44, 33813 @ 1733
  Metaprite_1734:
    metasprite Subsprite_3742, 1, 4, 44, 33829 @ 1734
    metasprite Subsprite_3743, 1, 4, 44, 33833 @ 1735
    metasprite Subsprite_3744, 1, 4, 44, 33837 @ 1736
  Metaprite_1737:
    metasprite Subsprite_3745, 2, 20, 519, 33841 @ 1737
    metasprite Subsprite_3747, 2, 20, 519, 33861 @ 1738
    metasprite Subsprite_3749, 1, 16, 519, 33881 @ 1739
    metasprite Subsprite_3750, 2, 20, 519, 33897 @ 1740
    metasprite Subsprite_3752, 2, 20, 519, 33917 @ 1741
    metasprite Subsprite_3754, 3, 24, 519, 33937 @ 1742
    metasprite Subsprite_3757, 4, 30, 519, 33961 @ 1743
    metasprite Subsprite_3761, 2, 20, 519, 33991 @ 1744
    metasprite Subsprite_3763, 2, 20, 519, 34011 @ 1745
    metasprite Subsprite_3765, 1, 16, 519, 34031 @ 1746
    metasprite Subsprite_3766, 2, 20, 519, 34047 @ 1747
    metasprite Subsprite_3768, 2, 20, 519, 34067 @ 1748
    metasprite Subsprite_3770, 3, 24, 519, 34087 @ 1749
    metasprite Subsprite_3773, 4, 30, 519, 34111 @ 1750
    metasprite Subsprite_3777, 2, 20, 519, 34141 @ 1751
    metasprite Subsprite_3779, 2, 20, 519, 34161 @ 1752
    metasprite Subsprite_3781, 1, 16, 519, 34181 @ 1753
    metasprite Subsprite_3782, 2, 20, 519, 34197 @ 1754
    metasprite Subsprite_3784, 2, 20, 519, 34217 @ 1755
    metasprite Subsprite_3786, 4, 30, 519, 34237 @ 1756
    metasprite Subsprite_3790, 4, 30, 519, 34267 @ 1757
    metasprite Subsprite_3794, 2, 18, 519, 34297 @ 1758
    metasprite Subsprite_3796, 2, 20, 519, 34315 @ 1759
    metasprite Subsprite_3798, 2, 20, 519, 34335 @ 1760
    metasprite Subsprite_3800, 2, 20, 519, 34355 @ 1761
    metasprite Subsprite_3802, 2, 18, 519, 34375 @ 1762
    metasprite Subsprite_3804, 3, 24, 519, 34393 @ 1763
    metasprite Subsprite_3807, 4, 36, 519, 34417 @ 1764
    metasprite Subsprite_3811, 2, 18, 519, 34453 @ 1765
    metasprite Subsprite_3813, 2, 20, 519, 34471 @ 1766
    metasprite Subsprite_3815, 2, 20, 519, 34491 @ 1767
    metasprite Subsprite_3817, 2, 20, 519, 34511 @ 1768
    metasprite Subsprite_3819, 2, 18, 519, 34531 @ 1769
    metasprite Subsprite_3821, 3, 24, 519, 34549 @ 1770
    metasprite Subsprite_3824, 4, 36, 519, 34573 @ 1771
    metasprite Subsprite_3828, 3, 22, 519, 34609 @ 1772
    metasprite Subsprite_3831, 3, 20, 519, 34631 @ 1773
    metasprite Subsprite_3834, 4, 30, 519, 34651 @ 1774
    metasprite Subsprite_3838, 3, 19, 519, 34681 @ 1775
    metasprite Subsprite_3841, 3, 22, 519, 34700 @ 1776
    metasprite Subsprite_3844, 4, 30, 519, 34722 @ 1777
    metasprite Subsprite_3848, 4, 36, 519, 34752 @ 1778
    metasprite Subsprite_3852, 2, 18, 519, 34788 @ 1779
    metasprite Subsprite_3854, 2, 20, 519, 34806 @ 1780
    metasprite Subsprite_3856, 2, 20, 519, 34826 @ 1781
    metasprite Subsprite_3858, 2, 20, 519, 34846 @ 1782
    metasprite Subsprite_3860, 2, 18, 519, 34866 @ 1783
    metasprite Subsprite_3862, 3, 24, 519, 34884 @ 1784
    metasprite Subsprite_3865, 4, 36, 519, 34908 @ 1785
    metasprite Subsprite_3869, 2, 20, 519, 34944 @ 1786
    metasprite Subsprite_3871, 3, 24, 519, 34964 @ 1787
    metasprite Subsprite_3874, 4, 18, 519, 34988 @ 1788
    metasprite Subsprite_3878, 4, 25, 519, 35006 @ 1789
    metasprite Subsprite_3882, 3, 16, 519, 35031 @ 1790
    metasprite Subsprite_3885, 2, 20, 519, 35047 @ 1791
    metasprite Subsprite_3887, 4, 36, 519, 35067 @ 1792
  Metaprite_1793:
    metasprite Subsprite_3891, 2, 24, 519, 35103 @ 1793
    metasprite Subsprite_3893, 3, 20, 519, 35127 @ 1794
    metasprite Subsprite_3896, 4, 30, 519, 35147 @ 1795
    metasprite Subsprite_3900, 3, 19, 519, 35177 @ 1796
    metasprite Subsprite_3903, 3, 22, 519, 35196 @ 1797
    metasprite Subsprite_3906, 2, 24, 519, 35218 @ 1798
    metasprite Subsprite_3908, 3, 20, 519, 35242 @ 1799
    metasprite Subsprite_3911, 4, 30, 519, 35262 @ 1800
    metasprite Subsprite_3915, 2, 24, 519, 35292 @ 1801
    metasprite Subsprite_3917, 3, 22, 519, 35316 @ 1802
  Metaprite_1803:
    metasprite Subsprite_3920, 3, 48, 529, 35338 @ 1803
    metasprite Subsprite_3923, 3, 48, 529, 35386 @ 1804
  Metaprite_1805:
    metasprite Subsprite_3926, 3, 48, 283, 35434 @ 1805
    metasprite Subsprite_3929, 3, 48, 283, 35482 @ 1806
  Metaprite_1807:
    metasprite Subsprite_3932, 1, 16, 531, 35530 @ 1807
    metasprite Subsprite_3933, 1, 16, 531, 35546 @ 1808
    metasprite Subsprite_3934, 1, 16, 531, 35562 @ 1809
    metasprite Subsprite_3935, 1, 16, 531, 35578 @ 1810
    metasprite Subsprite_3936, 1, 16, 531, 35594 @ 1811
    metasprite Subsprite_3937, 1, 16, 531, 35610 @ 1812
    metasprite Subsprite_3938, 1, 16, 531, 35626 @ 1813
    metasprite Subsprite_3939, 1, 16, 531, 35642 @ 1814
  Metaprite_1815:
    metasprite Subsprite_3940, 4, 9, 275, 35658 @ 1815
    metasprite Subsprite_3944, 2, 12, 275, 35667 @ 1816
    metasprite Subsprite_3946, 2, 12, 275, 35679 @ 1817
    metasprite Subsprite_3948, 2, 12, 275, 35691 @ 1818
    metasprite Subsprite_3950, 3, 11, 275, 35703 @ 1819
    metasprite Subsprite_3953, 3, 9, 275, 35714 @ 1820
  Metaprite_1821:
    metasprite Subsprite_3956, 3, 22, 275, 35723 @ 1821
    metasprite Subsprite_3959, 2, 24, 275, 35745 @ 1822
    metasprite Subsprite_3961, 2, 24, 275, 35769 @ 1823
    metasprite Subsprite_3963, 2, 24, 275, 35793 @ 1824
    metasprite Subsprite_3965, 2, 24, 275, 35817 @ 1825
    metasprite Subsprite_3967, 2, 20, 275, 35841 @ 1826
    metasprite Subsprite_3969, 1, 8, 275, 35861 @ 1827
    metasprite Subsprite_3970, 2, 9, 275, 35869 @ 1828
    metasprite Subsprite_3972, 3, 24, 275, 35878 @ 1829
    metasprite Subsprite_3975, 2, 24, 275, 35902 @ 1830
    metasprite Subsprite_3977, 4, 36, 275, 35926 @ 1831
    metasprite Subsprite_3981, 4, 36, 275, 35962 @ 1832
    metasprite Subsprite_3985, 4, 36, 275, 35998 @ 1833
    metasprite Subsprite_3989, 4, 30, 275, 36034 @ 1834
  Metaprite_1835:
    metasprite Subsprite_3993, 1, 16, 547, 36064 @ 1835
    metasprite Subsprite_3994, 3, 7, 547, 36080 @ 1836
    metasprite Subsprite_3997, 3, 6, 547, 36087 @ 1837
    metasprite Subsprite_4000, 1, 16, 547, 36093 @ 1838
    metasprite Subsprite_4001, 1, 16, 547, 36109 @ 1839
    metasprite Subsprite_4002, 3, 7, 547, 36125 @ 1840
    metasprite Subsprite_4005, 3, 7, 547, 36132 @ 1841
    metasprite Subsprite_4008, 1, 16, 547, 36139 @ 1842
    metasprite Subsprite_4009, 2, 12, 547, 36155 @ 1843
    metasprite Subsprite_4011, 2, 12, 547, 36167 @ 1844
    metasprite Subsprite_4013, 3, 7, 547, 36179 @ 1845
    metasprite Subsprite_4016, 2, 12, 547, 36186 @ 1846
    metasprite Subsprite_4018, 2, 12, 547, 36198 @ 1847
    metasprite Subsprite_4020, 2, 12, 547, 36210 @ 1848
    metasprite Subsprite_4022, 4, 9, 547, 36222 @ 1849
    metasprite Subsprite_4026, 4, 9, 547, 36231 @ 1850
    metasprite Subsprite_4030, 1, 16, 547, 36240 @ 1851
    metasprite Subsprite_4031, 2, 12, 547, 36256 @ 1852
    metasprite Subsprite_4033, 1, 16, 547, 36268 @ 1853
    metasprite Subsprite_4034, 1, 16, 547, 36284 @ 1854
    metasprite Subsprite_4035, 1, 16, 547, 36300 @ 1855
    metasprite Subsprite_4036, 1, 16, 547, 36316 @ 1856
    metasprite Subsprite_4037, 1, 16, 547, 36332 @ 1857
    metasprite Subsprite_4038, 1, 16, 547, 36348 @ 1858
    metasprite Subsprite_4039, 1, 16, 547, 36364 @ 1859
    metasprite Subsprite_4040, 1, 16, 547, 36380 @ 1860
    metasprite Subsprite_4041, 1, 16, 547, 36396 @ 1861
    metasprite Subsprite_4042, 1, 16, 547, 36412 @ 1862
    metasprite Subsprite_4043, 1, 16, 547, 36428 @ 1863
    metasprite Subsprite_4044, 1, 16, 547, 36444 @ 1864
    metasprite Subsprite_4045, 1, 16, 547, 36460 @ 1865
    metasprite Subsprite_4046, 2, 12, 547, 36476 @ 1866
    metasprite Subsprite_4048, 2, 12, 547, 36488 @ 1867
    metasprite Subsprite_4050, 1, 16, 547, 36500 @ 1868
    metasprite Subsprite_4051, 1, 16, 547, 36516 @ 1869
    metasprite Subsprite_4052, 1, 16, 547, 36532 @ 1870
    metasprite Subsprite_4053, 1, 16, 547, 36548 @ 1871
    metasprite Subsprite_4054, 1, 16, 547, 36564 @ 1872
    metasprite Subsprite_4055, 1, 16, 547, 36580 @ 1873
    metasprite Subsprite_4056, 3, 14, 547, 36596 @ 1874
    metasprite Subsprite_4059, 3, 11, 547, 36610 @ 1875
    metasprite Subsprite_4062, 1, 4, 547, 36621 @ 1876
    metasprite Subsprite_4063, 3, 12, 547, 36625 @ 1877
    metasprite Subsprite_4066, 3, 12, 547, 36637 @ 1878
    metasprite Subsprite_4069, 1, 4, 547, 36649 @ 1879
    metasprite Subsprite_4070, 1, 4, 547, 36653 @ 1880
    metasprite Subsprite_4071, 2, 12, 547, 36657 @ 1881
    metasprite Subsprite_4073, 1, 16, 547, 36669 @ 1882
    metasprite Subsprite_4074, 1, 16, 547, 36685 @ 1883
    metasprite Subsprite_4075, 1, 16, 547, 36701 @ 1884
    metasprite Subsprite_4076, 1, 16, 547, 36717 @ 1885
    metasprite Subsprite_4077, 1, 16, 547, 36733 @ 1886
    metasprite Subsprite_4078, 1, 16, 547, 36749 @ 1887
    metasprite Subsprite_4079, 1, 16, 547, 36765 @ 1888
    metasprite Subsprite_4080, 1, 16, 547, 36781 @ 1889
    metasprite Subsprite_4081, 1, 8, 547, 36797 @ 1890
    metasprite Subsprite_4082, 1, 16, 547, 36805 @ 1891
    metasprite Subsprite_4083, 3, 12, 547, 36821 @ 1892
  Metaprite_1893:
    metasprite Subsprite_4086, 2, 12, 558, 36833 @ 1893
    metasprite Subsprite_4088, 2, 12, 558, 36845 @ 1894
    metasprite Subsprite_4090, 1, 16, 558, 36857 @ 1895
    metasprite Subsprite_4091, 3, 11, 558, 36873 @ 1896
    metasprite Subsprite_4094, 1, 16, 558, 36884 @ 1897
    metasprite Subsprite_4095, 3, 11, 558, 36900 @ 1898
    metasprite Subsprite_4098, 1, 16, 558, 36911 @ 1899
    metasprite Subsprite_4099, 1, 16, 558, 36927 @ 1900
    metasprite Subsprite_4100, 2, 12, 558, 36943 @ 1901
    metasprite Subsprite_4102, 2, 12, 558, 36955 @ 1902
    metasprite Subsprite_4104, 2, 12, 558, 36967 @ 1903
  Metaprite_1904:
    metasprite Subsprite_4106, 1, 32, 559, 36979 @ 1904
    metasprite Subsprite_4107, 3, 40, 559, 37011 @ 1905
    metasprite Subsprite_4110, 1, 32, 559, 37051 @ 1906
  Metaprite_1907:
    metasprite Subsprite_4111, 1, 32, 559, 37083 @ 1907
    metasprite Subsprite_4112, 2, 20, 559, 37115 @ 1908
    metasprite Subsprite_4114, 4, 18, 559, 37135 @ 1909
  Metaprite_1910:
    metasprite Subsprite_4118, 1, 32, 559, 37153 @ 1910
    metasprite Subsprite_4119, 2, 20, 559, 37185 @ 1911
    metasprite Subsprite_4121, 4, 18, 559, 37205 @ 1912
  Metaprite_1913:
    metasprite Subsprite_4125, 1, 32, 559, 37223 @ 1913
    metasprite Subsprite_4126, 3, 40, 559, 37255 @ 1914
    metasprite Subsprite_4129, 1, 32, 559, 37295 @ 1915
  Metaprite_1916:
    metasprite Subsprite_4130, 1, 32, 559, 37327 @ 1916
    metasprite Subsprite_4131, 3, 40, 559, 37359 @ 1917
    metasprite Subsprite_4134, 1, 32, 559, 37399 @ 1918
  Metaprite_1919:
    metasprite Subsprite_4135, 1, 16, 561, 37431 @ 1919
    metasprite Subsprite_4136, 1, 16, 561, 37447 @ 1920
    metasprite Subsprite_4137, 1, 16, 561, 37463 @ 1921
    metasprite Subsprite_4138, 1, 16, 561, 37479 @ 1922
    metasprite Subsprite_4139, 1, 16, 561, 37495 @ 1923
    metasprite Subsprite_4140, 1, 16, 561, 37511 @ 1924
    metasprite Subsprite_4141, 1, 16, 561, 37527 @ 1925
    metasprite Subsprite_4142, 1, 16, 561, 37543 @ 1926
    metasprite Subsprite_4143, 3, 12, 561, 37559 @ 1927
    metasprite Subsprite_4146, 1, 16, 561, 37571 @ 1928
    metasprite Subsprite_4147, 3, 14, 561, 37587 @ 1929
    metasprite Subsprite_4150, 1, 16, 561, 37601 @ 1930
    metasprite Subsprite_4151, 1, 16, 561, 37617 @ 1931
    metasprite Subsprite_4152, 1, 16, 561, 37633 @ 1932
    metasprite Subsprite_4153, 3, 14, 561, 37649 @ 1933
    metasprite Subsprite_4156, 1, 16, 561, 37663 @ 1934
    metasprite Subsprite_4157, 1, 16, 561, 37679 @ 1935
    metasprite Subsprite_4158, 1, 16, 561, 37695 @ 1936
    metasprite Subsprite_4159, 1, 16, 561, 37711 @ 1937
    metasprite Subsprite_4160, 1, 16, 561, 37727 @ 1938
    metasprite Subsprite_4161, 1, 16, 561, 37743 @ 1939
    metasprite Subsprite_4162, 1, 16, 561, 37759 @ 1940
    metasprite Subsprite_4163, 1, 16, 561, 37775 @ 1941
    metasprite Subsprite_4164, 1, 16, 561, 37791 @ 1942
    metasprite Subsprite_4165, 1, 16, 561, 37807 @ 1943
    metasprite Subsprite_4166, 1, 16, 561, 37823 @ 1944
    metasprite Subsprite_4167, 1, 16, 561, 37839 @ 1945
    metasprite Subsprite_4168, 3, 12, 561, 37855 @ 1946
    metasprite Subsprite_4171, 3, 12, 561, 37867 @ 1947
    metasprite Subsprite_4174, 3, 12, 561, 37879 @ 1948
    metasprite Subsprite_4177, 3, 11, 561, 37891 @ 1949
    metasprite Subsprite_4180, 3, 12, 561, 37902 @ 1950
    metasprite Subsprite_4183, 1, 4, 561, 37914 @ 1951
    metasprite Subsprite_4184, 3, 11, 561, 37918 @ 1952
    metasprite Subsprite_4187, 3, 11, 561, 37929 @ 1953
    metasprite Subsprite_4190, 2, 10, 561, 37940 @ 1954
    metasprite Subsprite_4192, 2, 10, 561, 37950 @ 1955
    metasprite Subsprite_4194, 3, 6, 561, 37960 @ 1956
  Metaprite_1957:
    metasprite Subsprite_4197, 2, 6, 561, 37966 @ 1957
    metasprite Subsprite_4199, 2, 20, 561, 37972 @ 1958
    metasprite Subsprite_4201, 3, 32, 561, 37992 @ 1959
    metasprite Subsprite_4204, 4, 36, 561, 38024 @ 1960
    metasprite Subsprite_4208, 3, 48, 561, 38060 @ 1961
    metasprite Subsprite_4211, 3, 48, 561, 38108 @ 1962
    metasprite Subsprite_4214, 3, 7, 561, 38156 @ 1963
    metasprite Subsprite_4217, 3, 19, 561, 38163 @ 1964
    metasprite Subsprite_4220, 3, 28, 561, 38182 @ 1965
    metasprite Subsprite_4223, 3, 48, 561, 38210 @ 1966
    metasprite Subsprite_4226, 3, 48, 561, 38258 @ 1967
    metasprite Subsprite_4229, 1, 64, 561, 38306 @ 1968
    metasprite Subsprite_4230, 3, 13, 561, 38370 @ 1969
  Metaprite_1970:
    metasprite Subsprite_4233, 4, 30, 561, 38383 @ 1970
    metasprite Subsprite_4237, 4, 30, 561, 38413 @ 1971
    metasprite Subsprite_4241, 4, 36, 561, 38443 @ 1972
    metasprite Subsprite_4245, 4, 30, 561, 38479 @ 1973
    metasprite Subsprite_4249, 4, 30, 561, 38509 @ 1974
    metasprite Subsprite_4253, 4, 36, 561, 38539 @ 1975
  Metaprite_1976:
    metasprite Subsprite_4257, 1, 4, 561, 38575 @ 1976
    metasprite Subsprite_4258, 1, 4, 561, 38579 @ 1977
    metasprite Subsprite_4259, 1, 4, 561, 38583 @ 1978
    metasprite Subsprite_4260, 1, 4, 561, 38587 @ 1979
    metasprite Subsprite_4261, 1, 4, 561, 38591 @ 1980
    metasprite Subsprite_4262, 1, 4, 561, 38595 @ 1981
    metasprite Subsprite_4263, 1, 4, 561, 38599 @ 1982
    metasprite Subsprite_4264, 1, 4, 561, 38603 @ 1983
    metasprite Subsprite_4265, 1, 4, 561, 38607 @ 1984
    metasprite Subsprite_4266, 1, 4, 561, 38611 @ 1985
    metasprite Subsprite_4267, 1, 4, 561, 38615 @ 1986
    metasprite Subsprite_4268, 1, 4, 561, 38619 @ 1987
    metasprite Subsprite_4269, 1, 4, 561, 38623 @ 1988
    metasprite Subsprite_4270, 1, 4, 561, 38627 @ 1989
    metasprite Subsprite_4271, 1, 4, 561, 38631 @ 1990
    metasprite Subsprite_4272, 1, 4, 561, 38635 @ 1991
    metasprite Subsprite_4273, 1, 4, 561, 38639 @ 1992
    metasprite Subsprite_4274, 1, 4, 561, 38643 @ 1993
    metasprite Subsprite_4275, 1, 4, 561, 38647 @ 1994
    metasprite Subsprite_4276, 1, 4, 561, 38651 @ 1995
    metasprite Subsprite_4277, 1, 4, 561, 38655 @ 1996
  Metaprite_1997:
    metasprite Subsprite_4278, 1, 1, 561, 38659 @ 1997
    metasprite Subsprite_4279, 1, 1, 561, 38660 @ 1998
    metasprite Subsprite_4280, 1, 1, 561, 38661 @ 1999
    metasprite Subsprite_4281, 1, 1, 561, 38662 @ 2000
    metasprite Subsprite_4282, 1, 1, 561, 38663 @ 2001
    metasprite Subsprite_4283, 1, 1, 561, 38664 @ 2002
    metasprite Subsprite_4284, 1, 1, 561, 38665 @ 2003
    metasprite Subsprite_4285, 1, 1, 561, 38666 @ 2004
    metasprite Subsprite_4286, 1, 1, 561, 38667 @ 2005
    metasprite Subsprite_4287, 1, 1, 561, 38668 @ 2006
    metasprite Subsprite_4288, 1, 1, 561, 38669 @ 2007
    metasprite Subsprite_4289, 1, 1, 561, 38670 @ 2008
    metasprite Subsprite_4290, 1, 1, 561, 38671 @ 2009
    metasprite Subsprite_4291, 1, 1, 561, 38672 @ 2010
  Metaprite_2011:
    metasprite Subsprite_4292, 3, 48, 573, 38673 @ 2011
  Metaprite_2012:
    metasprite Subsprite_4295, 3, 12, 573, 38721 @ 2012
  Metaprite_2013:
    metasprite Subsprite_4298, 1, 1, 573, 38733 @ 2013
  Metaprite_2014:
    metasprite Subsprite_4299, 3, 48, 83, 38734 @ 2014
    metasprite Subsprite_4302, 1, 1, 83, 38782 @ 2015
    metasprite Subsprite_4303, 3, 48, 83, 38783 @ 2016
    metasprite Subsprite_4306, 4, 30, 83, 38831 @ 2017
    metasprite Subsprite_4310, 4, 30, 83, 38861 @ 2018
    metasprite Subsprite_4314, 3, 48, 83, 38891 @ 2019
    metasprite Subsprite_4317, 3, 48, 83, 38939 @ 2020
    metasprite Subsprite_4320, 3, 48, 83, 38987 @ 2021
    metasprite Subsprite_4323, 3, 48, 83, 39035 @ 2022
    metasprite Subsprite_4326, 3, 48, 83, 39083 @ 2023
    metasprite Subsprite_4329, 3, 48, 83, 39131 @ 2024
    metasprite Subsprite_4332, 3, 48, 83, 39179 @ 2025
    metasprite Subsprite_4335, 3, 48, 83, 39227 @ 2026
    metasprite Subsprite_4338, 3, 48, 83, 39275 @ 2027
    metasprite Subsprite_4341, 3, 48, 83, 39323 @ 2028
    metasprite Subsprite_4344, 3, 48, 83, 39371 @ 2029
  Metaprite_2030:
    metasprite Subsprite_4347, 3, 48, 577, 39419 @ 2030
    metasprite Subsprite_4350, 3, 48, 577, 39467 @ 2031
    metasprite Subsprite_4353, 4, 36, 577, 39515 @ 2032
    metasprite Subsprite_4357, 3, 12, 577, 39551 @ 2033
  Metaprite_2034:
    metasprite Subsprite_4360, 3, 48, 593, 39563 @ 2034
  Metaprite_2035:
    metasprite Subsprite_4363, 3, 48, 83, 39611 @ 2035
    metasprite Subsprite_4366, 3, 48, 83, 39659 @ 2036
    metasprite Subsprite_4369, 3, 48, 83, 39707 @ 2037
    metasprite Subsprite_4372, 3, 48, 83, 39755 @ 2038
    metasprite Subsprite_4375, 3, 48, 83, 39803 @ 2039
    metasprite Subsprite_4378, 3, 48, 83, 39851 @ 2040
    metasprite Subsprite_4381, 3, 48, 83, 39899 @ 2041
    metasprite Subsprite_4384, 3, 48, 83, 39947 @ 2042
    metasprite Subsprite_4387, 3, 48, 83, 39995 @ 2043
    metasprite Subsprite_4390, 3, 48, 83, 40043 @ 2044
    metasprite Subsprite_4393, 3, 48, 83, 40091 @ 2045
    metasprite Subsprite_4396, 1, 1, 83, 40139 @ 2046
    metasprite Subsprite_4397, 3, 48, 83, 40140 @ 2047
  Metaprite_2048:
    metasprite Subsprite_4400, 4, 36, 594, 40188 @ 2048
  Metaprite_2049:
    metasprite Subsprite_4404, 2, 5, 610, 40224 @ 2049
    metasprite Subsprite_4406, 2, 5, 610, 40229 @ 2050
    metasprite Subsprite_4408, 1, 4, 610, 40234 @ 2051
    metasprite Subsprite_4409, 2, 5, 610, 40238 @ 2052
    metasprite Subsprite_4411, 2, 5, 610, 40243 @ 2053
    metasprite Subsprite_4413, 2, 5, 610, 40248 @ 2054
    metasprite Subsprite_4415, 3, 6, 610, 40253 @ 2055
    metasprite Subsprite_4418, 2, 5, 610, 40259 @ 2056
    metasprite Subsprite_4420, 2, 5, 610, 40264 @ 2057
    metasprite Subsprite_4422, 2, 6, 610, 40269 @ 2058
    metasprite Subsprite_4424, 2, 5, 610, 40275 @ 2059
    metasprite Subsprite_4426, 2, 5, 610, 40280 @ 2060
    metasprite Subsprite_4428, 2, 5, 610, 40285 @ 2061
    metasprite Subsprite_4430, 2, 5, 610, 40290 @ 2062
    metasprite Subsprite_4432, 2, 5, 610, 40295 @ 2063
    metasprite Subsprite_4434, 2, 5, 610, 40300 @ 2064
  Metaprite_2065:
    metasprite Subsprite_4436, 2, 40, 626, 40305 @ 2065
  Metaprite_2066:
    metasprite Subsprite_4438, 2, 9, 626, 40345 @ 2066
  Metaprite_2067:
    metasprite Subsprite_4440, 1, 8, 44, 40354 @ 2067
    metasprite Subsprite_4441, 1, 8, 44, 40362 @ 2068
    metasprite Subsprite_4442, 1, 8, 44, 40370 @ 2069
    metasprite Subsprite_4443, 1, 8, 44, 40378 @ 2070
    metasprite Subsprite_4444, 1, 8, 44, 40386 @ 2071
  Metaprite_2072:
    metasprite Subsprite_4445, 1, 4, 634, 40394 @ 2072
    metasprite Subsprite_4446, 1, 4, 634, 40398 @ 2073
    metasprite Subsprite_4447, 1, 4, 634, 40402 @ 2074
    metasprite Subsprite_4448, 1, 4, 634, 40406 @ 2075
    metasprite Subsprite_4449, 1, 4, 634, 40410 @ 2076
    metasprite Subsprite_4450, 1, 4, 634, 40414 @ 2077
    metasprite Subsprite_4451, 1, 4, 634, 40418 @ 2078
    metasprite Subsprite_4452, 1, 4, 634, 40422 @ 2079
    metasprite Subsprite_4453, 1, 4, 634, 40426 @ 2080
    metasprite Subsprite_4454, 1, 4, 634, 40430 @ 2081
    metasprite Subsprite_4455, 1, 4, 634, 40434 @ 2082
    metasprite Subsprite_4456, 1, 4, 634, 40438 @ 2083
    metasprite Subsprite_4457, 1, 4, 634, 40442 @ 2084
    metasprite Subsprite_4458, 1, 4, 634, 40446 @ 2085
    metasprite Subsprite_4459, 1, 4, 634, 40450 @ 2086
    metasprite Subsprite_4460, 1, 4, 634, 40454 @ 2087
  Metaprite_2088:
    metasprite Subsprite_4461, 4, 36, 287, 40458 @ 2088
    metasprite Subsprite_4465, 4, 36, 287, 40494 @ 2089
  Metaprite_2090:
    metasprite Subsprite_4469, 1, 16, 635, 40530 @ 2090
    metasprite Subsprite_4470, 2, 24, 635, 40546 @ 2091
    metasprite Subsprite_4472, 2, 24, 635, 40570 @ 2092
  Metaprite_2093:
    metasprite Subsprite_4474, 4, 36, 642, 40594 @ 2093
    metasprite Subsprite_4478, 4, 36, 642, 40630 @ 2094
  Metaprite_2095:
    metasprite Subsprite_4482, 4, 36, 642, 40666 @ 2095
    metasprite Subsprite_4486, 4, 36, 642, 40702 @ 2096
  Metaprite_2097:
    metasprite Subsprite_4490, 3, 12, 645, 40738 @ 2097
    metasprite Subsprite_4493, 3, 12, 645, 40750 @ 2098
    metasprite Subsprite_4496, 3, 12, 645, 40762 @ 2099
    metasprite Subsprite_4499, 3, 12, 645, 40774 @ 2100
    metasprite Subsprite_4502, 3, 12, 645, 40786 @ 2101
    metasprite Subsprite_4505, 3, 12, 645, 40798 @ 2102
    metasprite Subsprite_4508, 3, 12, 645, 40810 @ 2103
    metasprite Subsprite_4511, 3, 12, 645, 40822 @ 2104
    metasprite Subsprite_4514, 3, 12, 645, 40834 @ 2105
    metasprite Subsprite_4517, 3, 12, 645, 40846 @ 2106
    metasprite Subsprite_4520, 3, 12, 645, 40858 @ 2107
    metasprite Subsprite_4523, 3, 12, 645, 40870 @ 2108
    metasprite Subsprite_4526, 3, 12, 645, 40882 @ 2109
  Metaprite_2110:
    metasprite Subsprite_4529, 1, 32, 646, 40894 @ 2110
    metasprite Subsprite_4530, 1, 32, 646, 40926 @ 2111
    metasprite Subsprite_4531, 1, 32, 646, 40958 @ 2112
    metasprite Subsprite_4532, 1, 32, 646, 40990 @ 2113
  Metaprite_2114:
    metasprite Subsprite_4533, 3, 40, 647, 41022 @ 2114
  Metaprite_2115:
    metasprite Subsprite_4536, 1, 16, 647, 41062 @ 2115
  Metaprite_2116:
    metasprite Subsprite_4537, 1, 1, 647, 41078 @ 2116
  Metaprite_2117:
    metasprite Subsprite_4538, 3, 14, 649, 41079 @ 2117
    metasprite Subsprite_4541, 3, 14, 649, 41093 @ 2118
    metasprite Subsprite_4544, 3, 12, 649, 41107 @ 2119
    metasprite Subsprite_4547, 4, 15, 649, 41119 @ 2120
    metasprite Subsprite_4551, 3, 12, 649, 41134 @ 2121
  Metaprite_2122:
    metasprite Subsprite_4554, 1, 2, 501, 41146 @ 2122
    metasprite Subsprite_4555, 1, 4, 501, 41148 @ 2123
    metasprite Subsprite_4556, 1, 1, 501, 41152 @ 2124
    metasprite Subsprite_4557, 2, 12, 501, 41153 @ 2125
    metasprite Subsprite_4559, 4, 30, 501, 41165 @ 2126
    metasprite Subsprite_4563, 3, 48, 501, 41195 @ 2127
    metasprite Subsprite_4566, 1, 64, 501, 41243 @ 2128
    metasprite Subsprite_4567, 1, 64, 501, 41307 @ 2129
    metasprite Subsprite_4568, 1, 64, 501, 41371 @ 2130
    metasprite Subsprite_4569, 2, 68, 501, 41435 @ 2131
  Metaprite_2132:
    metasprite Subsprite_4571, 2, 4, 501, 41503 @ 2132
    metasprite Subsprite_4573, 1, 2, 501, 41507 @ 2133
    metasprite Subsprite_4574, 1, 1, 501, 41509 @ 2134
    metasprite Subsprite_4575, 1, 16, 501, 41510 @ 2135
    metasprite Subsprite_4576, 3, 28, 501, 41526 @ 2136
    metasprite Subsprite_4579, 3, 32, 501, 41554 @ 2137
    metasprite Subsprite_4582, 3, 48, 501, 41586 @ 2138
    metasprite Subsprite_4585, 3, 48, 501, 41634 @ 2139
    metasprite Subsprite_4588, 2, 68, 501, 41682 @ 2140
    metasprite Subsprite_4590, 2, 68, 501, 41750 @ 2141
  Metaprite_2142:
    metasprite Subsprite_4592, 2, 12, 501, 41818 @ 2142
    metasprite Subsprite_4594, 1, 16, 501, 41830 @ 2143
    metasprite Subsprite_4595, 1, 16, 501, 41846 @ 2144
    metasprite Subsprite_4596, 1, 16, 501, 41862 @ 2145
    metasprite Subsprite_4597, 3, 14, 501, 41878 @ 2146
    metasprite Subsprite_4600, 1, 16, 501, 41892 @ 2147
  Metaprite_2148:
    metasprite Subsprite_4601, 3, 48, 83, 41908 @ 2148
    metasprite Subsprite_4604, 3, 48, 83, 41956 @ 2149
    metasprite Subsprite_4607, 3, 48, 83, 42004 @ 2150
    metasprite Subsprite_4610, 3, 48, 83, 42052 @ 2151
    metasprite Subsprite_4613, 3, 26, 83, 42100 @ 2152
    metasprite Subsprite_4616, 3, 48, 83, 42126 @ 2153
    metasprite Subsprite_4619, 3, 48, 83, 42174 @ 2154
    metasprite Subsprite_4622, 3, 48, 83, 42222 @ 2155
  Metaprite_2156:
    metasprite Subsprite_4625, 1, 16, 650, 42270 @ 2156
    metasprite Subsprite_4626, 2, 20, 650, 42286 @ 2157
    metasprite Subsprite_4628, 2, 24, 650, 42306 @ 2158
    metasprite Subsprite_4630, 2, 20, 650, 42330 @ 2159
    metasprite Subsprite_4632, 1, 16, 650, 42350 @ 2160
    metasprite Subsprite_4633, 3, 12, 650, 42366 @ 2161
    metasprite Subsprite_4636, 2, 20, 650, 42378 @ 2162
    metasprite Subsprite_4638, 2, 20, 650, 42398 @ 2163

Subsprites:
  Subsprite_0:
    subsprite OAM_SIZE_32x64, -20, -44
    subsprite OAM_SIZE_8x32, 12, -44
    subsprite OAM_SIZE_8x32, 12, -12
  Subsprite_3:
    subsprite OAM_SIZE_32x64, -20, -44
    subsprite OAM_SIZE_8x32, 12, -44
    subsprite OAM_SIZE_8x32, 12, -12
  Subsprite_6:
    subsprite OAM_SIZE_32x64, -20, -44
    subsprite OAM_SIZE_8x32, 12, -44
    subsprite OAM_SIZE_8x32, 12, -12
  Subsprite_9:
    subsprite OAM_SIZE_32x64, -20, -44
    subsprite OAM_SIZE_8x32, 12, -44
    subsprite OAM_SIZE_8x32, 12, -12
  Subsprite_12:
    subsprite OAM_SIZE_32x64, -44, -51
    subsprite OAM_SIZE_16x32, -12, -51
    subsprite OAM_SIZE_16x32, -12, -19
  Subsprite_15:
    subsprite OAM_SIZE_32x32, -44, -19
    subsprite OAM_SIZE_8x32, -12, -19
  Subsprite_17:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_18:
    subsprite OAM_SIZE_32x32, 0, 0
  Subsprite_19:
    subsprite OAM_SIZE_32x32, 0, 0
  Subsprite_20:
    subsprite OAM_SIZE_32x32, 0, 0
  Subsprite_21:
    subsprite OAM_SIZE_32x32, 0, 0
  Subsprite_22:
    subsprite OAM_SIZE_32x16, -16, -8
    subsprite OAM_SIZE_16x8, -8, -16
    subsprite OAM_SIZE_16x8, -8, 8
  Subsprite_25:
    subsprite OAM_SIZE_32x16, -16, -8
    subsprite OAM_SIZE_16x8, -8, -16
    subsprite OAM_SIZE_16x8, -8, 8
  Subsprite_28:
    subsprite OAM_SIZE_32x16, -16, -8
    subsprite OAM_SIZE_16x8, -8, -16
    subsprite OAM_SIZE_16x8, -8, 8
  Subsprite_31:
    subsprite OAM_SIZE_32x32, -24, -24
    subsprite OAM_SIZE_32x16, -24, 8
    subsprite OAM_SIZE_16x32, 8, -24
    subsprite OAM_SIZE_16x16, 8, 8
  Subsprite_35:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_36:
    subsprite OAM_SIZE_32x16, -16, -8
    subsprite OAM_SIZE_16x8, -8, -16
    subsprite OAM_SIZE_16x8, -8, 8
  Subsprite_39:
    subsprite OAM_SIZE_32x32, -24, -24
    subsprite OAM_SIZE_32x16, -24, 8
    subsprite OAM_SIZE_16x32, 8, -24
    subsprite OAM_SIZE_16x16, 8, 8
  Subsprite_43:
    subsprite OAM_SIZE_16x32, -6, -34
    subsprite OAM_SIZE_16x8, -6, -2
    subsprite OAM_SIZE_8x8, -6, -42
  Subsprite_46:
    subsprite OAM_SIZE_16x32, -14, -42
    subsprite OAM_SIZE_8x32, 2, -42
    subsprite OAM_SIZE_16x16, -14, -10
    subsprite OAM_SIZE_8x16, 2, -10
  Subsprite_50:
    subsprite OAM_SIZE_16x32, -6, -34
    subsprite OAM_SIZE_16x8, -6, -2
  Subsprite_52:
    subsprite OAM_SIZE_16x32, -6, -42
    subsprite OAM_SIZE_16x16, -6, -10
  Subsprite_54:
    subsprite OAM_SIZE_16x32, -6, -42
    subsprite OAM_SIZE_16x16, -6, -10
    subsprite OAM_SIZE_8x8, -14, -18
  Subsprite_57:
    subsprite OAM_SIZE_16x32, -14, -34
    subsprite OAM_SIZE_8x32, 2, -34
    subsprite OAM_SIZE_16x8, -14, -2
    subsprite OAM_SIZE_8x8, 2, -2
  Subsprite_61:
    subsprite OAM_SIZE_16x32, -14, -34
    subsprite OAM_SIZE_8x32, 2, -34
    subsprite OAM_SIZE_16x8, -14, -2
    subsprite OAM_SIZE_8x8, 2, -2
  Subsprite_65:
    subsprite OAM_SIZE_16x32, -6, -42
    subsprite OAM_SIZE_16x16, -6, -10
    subsprite OAM_SIZE_8x16, -14, -18
  Subsprite_68:
    subsprite OAM_SIZE_16x32, -6, -42
    subsprite OAM_SIZE_16x16, -6, -10
  Subsprite_70:
    subsprite OAM_SIZE_16x32, -6, -34
    subsprite OAM_SIZE_16x8, -6, -2
  Subsprite_72:
    subsprite OAM_SIZE_16x32, -14, -34
    subsprite OAM_SIZE_8x32, 2, -34
    subsprite OAM_SIZE_16x8, -14, -2
    subsprite OAM_SIZE_8x8, 2, -2
  Subsprite_76:
    subsprite OAM_SIZE_16x32, -14, -42
    subsprite OAM_SIZE_8x32, 2, -42
    subsprite OAM_SIZE_16x16, -14, -10
    subsprite OAM_SIZE_8x16, 2, -10
  Subsprite_80:
    subsprite OAM_SIZE_16x32, -6, -42
    subsprite OAM_SIZE_16x16, -6, -10
  Subsprite_82:
    subsprite OAM_SIZE_16x32, -6, -34
    subsprite OAM_SIZE_16x8, -6, -2
  Subsprite_84:
    subsprite OAM_SIZE_16x32, -6, -34
    subsprite OAM_SIZE_16x8, -6, -2
  Subsprite_86:
    subsprite OAM_SIZE_16x32, -6, -42
    subsprite OAM_SIZE_16x16, -6, -10
  Subsprite_88:
    subsprite OAM_SIZE_16x32, -6, -42
    subsprite OAM_SIZE_16x16, -6, -10
    subsprite OAM_SIZE_8x16, -14, -18
  Subsprite_91:
    subsprite OAM_SIZE_16x32, -14, -34
    subsprite OAM_SIZE_8x32, 2, -34
    subsprite OAM_SIZE_16x8, -14, -2
    subsprite OAM_SIZE_8x8, 2, -2
  Subsprite_95:
    subsprite OAM_SIZE_16x32, -6, -34
    subsprite OAM_SIZE_16x8, -6, -2
    subsprite OAM_SIZE_8x8, -6, -42
  Subsprite_98:
    subsprite OAM_SIZE_32x32, -14, -42
    subsprite OAM_SIZE_32x16, -14, -10
  Subsprite_100:
    subsprite OAM_SIZE_16x32, -6, -34
    subsprite OAM_SIZE_16x8, -6, -2
    subsprite OAM_SIZE_8x8, -6, -42
  Subsprite_103:
    subsprite OAM_SIZE_16x32, -6, -34
    subsprite OAM_SIZE_8x8, -6, -42
    subsprite OAM_SIZE_8x8, -6, -2
  Subsprite_106:
    subsprite OAM_SIZE_16x32, -14, -42
    subsprite OAM_SIZE_8x32, 2, -42
    subsprite OAM_SIZE_16x16, -14, -10
    subsprite OAM_SIZE_8x16, 2, -10
  Subsprite_110:
    subsprite OAM_SIZE_16x32, -14, -42
    subsprite OAM_SIZE_8x32, 2, -42
    subsprite OAM_SIZE_16x16, -14, -10
    subsprite OAM_SIZE_8x16, 2, -10
  Subsprite_114:
    subsprite OAM_SIZE_32x32, -14, -42
    subsprite OAM_SIZE_32x16, -14, -10
  Subsprite_116:
    subsprite OAM_SIZE_32x32, -14, -42
    subsprite OAM_SIZE_32x16, -14, -10
  Subsprite_118:
    subsprite OAM_SIZE_16x32, -6, -42
    subsprite OAM_SIZE_16x16, -6, -10
    subsprite OAM_SIZE_8x16, -14, -26
  Subsprite_121:
    subsprite OAM_SIZE_16x32, -14, -42
    subsprite OAM_SIZE_8x32, 2, -42
    subsprite OAM_SIZE_16x16, -14, -10
    subsprite OAM_SIZE_8x16, 2, -10
  Subsprite_125:
    subsprite OAM_SIZE_16x32, -6, -34
    subsprite OAM_SIZE_16x8, -6, -2
    subsprite OAM_SIZE_8x16, -14, -26
  Subsprite_128:
    subsprite OAM_SIZE_16x32, -6, -26
    subsprite OAM_SIZE_8x16, -14, -18
  Subsprite_130:
    subsprite OAM_SIZE_16x32, -14, -26
    subsprite OAM_SIZE_8x32, 2, -26
    subsprite OAM_SIZE_16x8, -14, 6
  Subsprite_133:
    subsprite OAM_SIZE_32x32, -14, -42
    subsprite OAM_SIZE_32x16, -14, -10
  Subsprite_135:
    subsprite OAM_SIZE_16x32, -6, -42
    subsprite OAM_SIZE_8x32, -14, -34
    subsprite OAM_SIZE_16x16, -6, -10
  Subsprite_138:
    subsprite OAM_SIZE_16x32, -6, -42
    subsprite OAM_SIZE_8x32, -14, -26
    subsprite OAM_SIZE_16x16, -6, -10
  Subsprite_141:
    subsprite OAM_SIZE_16x32, -14, -34
    subsprite OAM_SIZE_8x32, 2, -34
    subsprite OAM_SIZE_16x8, -14, -2
    subsprite OAM_SIZE_8x8, 2, -2
  Subsprite_145:
    subsprite OAM_SIZE_16x32, -6, -26
    subsprite OAM_SIZE_8x16, -14, -18
    subsprite OAM_SIZE_8x8, -14, -2
  Subsprite_148:
    subsprite OAM_SIZE_16x32, -6, -26
    subsprite OAM_SIZE_8x16, -14, -18
    subsprite OAM_SIZE_8x8, -14, -2
  Subsprite_151:
    subsprite OAM_SIZE_16x32, -8, -42
    subsprite OAM_SIZE_16x16, -8, -10
    subsprite OAM_SIZE_8x16, 8, -10
  Subsprite_154:
    subsprite OAM_SIZE_16x32, -8, -42
    subsprite OAM_SIZE_16x16, -8, -10
    subsprite OAM_SIZE_8x16, -16, -34
  Subsprite_157:
    subsprite OAM_SIZE_32x32, -24, -42
    subsprite OAM_SIZE_32x16, -24, -10
    subsprite OAM_SIZE_8x32, 8, -42
  Subsprite_160:
    subsprite OAM_SIZE_32x32, -16, -34
    subsprite OAM_SIZE_32x8, -16, -2
    subsprite OAM_SIZE_8x32, 16, -34
  Subsprite_163:
    subsprite OAM_SIZE_16x32, -8, -42
    subsprite OAM_SIZE_16x16, -8, -10
  Subsprite_165:
    subsprite OAM_SIZE_16x32, -16, -42
    subsprite OAM_SIZE_8x32, 0, -42
    subsprite OAM_SIZE_16x16, -16, -10
    subsprite OAM_SIZE_8x16, 0, -10
  Subsprite_169:
    subsprite OAM_SIZE_32x32, -24, -42
    subsprite OAM_SIZE_32x16, -24, -10
    subsprite OAM_SIZE_8x32, 8, -42
  Subsprite_172:
    subsprite OAM_SIZE_32x32, -24, -34
    subsprite OAM_SIZE_16x32, 8, -34
    subsprite OAM_SIZE_32x8, -24, -2
  Subsprite_175:
    subsprite OAM_SIZE_32x32, -24, -24
    subsprite OAM_SIZE_32x16, -24, 8
    subsprite OAM_SIZE_16x32, 8, -24
    subsprite OAM_SIZE_16x16, 8, 8
  Subsprite_179:
    subsprite OAM_SIZE_32x32, -24, -24
    subsprite OAM_SIZE_32x8, -24, 8
    subsprite OAM_SIZE_8x32, 8, -24
  Subsprite_182:
    subsprite OAM_SIZE_32x32, -16, -24
    subsprite OAM_SIZE_32x8, -16, 8
    subsprite OAM_SIZE_8x32, 16, -24
  Subsprite_185:
    subsprite OAM_SIZE_32x8, -16, -16
    subsprite OAM_SIZE_16x8, -8, -24
    subsprite OAM_SIZE_16x8, -8, -8
  Subsprite_188:
    subsprite OAM_SIZE_32x8, -24, 0
    subsprite OAM_SIZE_16x8, -8, -8
    subsprite OAM_SIZE_16x8, 8, 0
  Subsprite_191:
    subsprite OAM_SIZE_32x8, -16, 0
    subsprite OAM_SIZE_16x8, -8, -8
  Subsprite_193:
    subsprite OAM_SIZE_16x16, -8, -8
    subsprite OAM_SIZE_16x8, 0, 8
    subsprite OAM_SIZE_8x16, -16, -16
  Subsprite_196:
    subsprite OAM_SIZE_16x16, -8, -8
    subsprite OAM_SIZE_8x8, -16, -8
    subsprite OAM_SIZE_8x8, 0, 8
  Subsprite_199:
    subsprite OAM_SIZE_8x32, -8, -24
    subsprite OAM_SIZE_8x16, 0, -8
    subsprite OAM_SIZE_8x16, -8, 8
  Subsprite_202:
    subsprite OAM_SIZE_8x32, -8, -16
    subsprite OAM_SIZE_8x16, 0, -8
  Subsprite_204:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_205:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_206:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_207:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_208:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_209:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_210:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_211:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_212:
    subsprite OAM_SIZE_32x32, -24, -16
    subsprite OAM_SIZE_16x32, 8, -16
    subsprite OAM_SIZE_32x8, -24, 16
    subsprite OAM_SIZE_16x8, 8, 16
  Subsprite_216:
    subsprite OAM_SIZE_32x64, -24, -40
  Subsprite_217:
    subsprite OAM_SIZE_32x64, -32, -48
    subsprite OAM_SIZE_8x32, 0, -48
    subsprite OAM_SIZE_8x32, 0, -16
  Subsprite_220:
    subsprite OAM_SIZE_32x64, -24, -64
  Subsprite_221:
    subsprite OAM_SIZE_32x64, -24, -40
  Subsprite_222:
    subsprite OAM_SIZE_32x32, -24, -40
    subsprite OAM_SIZE_32x8, -24, -8
  Subsprite_224:
    subsprite OAM_SIZE_16x32, -16, -48
    subsprite OAM_SIZE_8x32, 0, -48
    subsprite OAM_SIZE_16x16, -16, -16
    subsprite OAM_SIZE_8x16, 0, -16
  Subsprite_228:
    subsprite OAM_SIZE_32x64, -24, -40
  Subsprite_229:
    subsprite OAM_SIZE_32x32, -24, -40
    subsprite OAM_SIZE_32x8, -24, -8
  Subsprite_231:
    subsprite OAM_SIZE_16x32, -16, -48
    subsprite OAM_SIZE_8x32, 0, -48
    subsprite OAM_SIZE_16x16, -16, -16
    subsprite OAM_SIZE_8x16, 0, -16
  Subsprite_235:
    subsprite OAM_SIZE_32x64, -24, -40
  Subsprite_236:
    subsprite OAM_SIZE_32x64, -32, -48
    subsprite OAM_SIZE_8x32, 0, -48
    subsprite OAM_SIZE_8x32, 0, -16
  Subsprite_239:
    subsprite OAM_SIZE_32x64, -24, -64
  Subsprite_240:
    subsprite OAM_SIZE_32x64, -24, -40
  Subsprite_241:
    subsprite OAM_SIZE_32x64, -32, -48
    subsprite OAM_SIZE_8x32, 0, -48
    subsprite OAM_SIZE_8x32, 0, -16
  Subsprite_244:
    subsprite OAM_SIZE_32x64, -24, -64
  Subsprite_245:
    subsprite OAM_SIZE_8x8, -4, -4
  Subsprite_246:
    subsprite OAM_SIZE_8x8, -4, -4
  Subsprite_247:
    subsprite OAM_SIZE_8x8, -4, -4
  Subsprite_248:
    subsprite OAM_SIZE_8x8, -4, -4
  Subsprite_249:
    subsprite OAM_SIZE_32x64, -24, -40
    subsprite OAM_SIZE_8x32, 8, -40
  Subsprite_251:
    subsprite OAM_SIZE_32x64, -16, -40
    subsprite OAM_SIZE_8x32, 16, -40
    subsprite OAM_SIZE_8x32, 16, -8
  Subsprite_254:
    subsprite OAM_SIZE_32x32, -24, -48
    subsprite OAM_SIZE_32x16, -24, -16
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x16, 8, -16
  Subsprite_258:
    subsprite OAM_SIZE_16x16, -13, -25
    subsprite OAM_SIZE_16x8, -5, -9
    subsprite OAM_SIZE_8x16, 3, -25
  Subsprite_261:
    subsprite OAM_SIZE_16x16, -13, -25
    subsprite OAM_SIZE_16x8, -5, -9
    subsprite OAM_SIZE_8x16, 3, -25
  Subsprite_264:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_265:
    subsprite OAM_SIZE_64x64, -33, -48
  Subsprite_266:
    subsprite OAM_SIZE_64x64, -24, -48
  Subsprite_267:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_268:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_269:
    subsprite OAM_SIZE_16x16, -8, -8
    subsprite OAM_SIZE_16x8, -8, 8
  Subsprite_271:
    subsprite OAM_SIZE_16x16, -8, -8
    subsprite OAM_SIZE_16x8, -8, 8
    subsprite OAM_SIZE_8x16, 8, -8
  Subsprite_274:
    subsprite OAM_SIZE_16x16, -8, -8
    subsprite OAM_SIZE_16x8, -8, 8
    subsprite OAM_SIZE_8x16, 8, -8
  Subsprite_277:
    subsprite OAM_SIZE_16x16, -8, -8
    subsprite OAM_SIZE_16x8, -8, 8
    subsprite OAM_SIZE_8x16, 8, -8
  Subsprite_280:
    subsprite OAM_SIZE_32x16, -16, -8
    subsprite OAM_SIZE_16x8, -8, -16
    subsprite OAM_SIZE_16x8, -8, 8
  Subsprite_283:
    subsprite OAM_SIZE_32x16, -16, -8
    subsprite OAM_SIZE_16x8, -8, -16
    subsprite OAM_SIZE_16x8, -8, 8
  Subsprite_286:
    subsprite OAM_SIZE_32x16, -16, -8
    subsprite OAM_SIZE_16x8, -8, -16
    subsprite OAM_SIZE_16x8, -8, 8
  Subsprite_289:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_290:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_291:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_292:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_293:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_294:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_295:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_296:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_297:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_298:
    subsprite OAM_SIZE_32x64, -24, -51
    subsprite OAM_SIZE_16x32, 8, -51
    subsprite OAM_SIZE_16x32, 8, -19
  Subsprite_301:
    subsprite OAM_SIZE_32x64, -24, -51
    subsprite OAM_SIZE_16x32, 8, -51
    subsprite OAM_SIZE_16x32, 8, -19
  Subsprite_304:
    subsprite OAM_SIZE_32x64, -24, -51
    subsprite OAM_SIZE_16x32, 8, -51
    subsprite OAM_SIZE_16x32, 8, -19
  Subsprite_307:
    subsprite OAM_SIZE_32x64, -24, -51
    subsprite OAM_SIZE_16x32, 8, -51
    subsprite OAM_SIZE_16x32, 8, -19
  Subsprite_310:
    subsprite OAM_SIZE_32x32, -24, -16
    subsprite OAM_SIZE_16x32, 8, -16
    subsprite OAM_SIZE_32x8, -24, 16
  Subsprite_313:
    subsprite OAM_SIZE_32x32, -24, -16
    subsprite OAM_SIZE_16x32, 8, -16
    subsprite OAM_SIZE_32x8, -24, 16
  Subsprite_316:
    subsprite OAM_SIZE_32x32, -24, -16
    subsprite OAM_SIZE_16x32, 8, -16
    subsprite OAM_SIZE_32x8, -24, 16
  Subsprite_319:
    subsprite OAM_SIZE_32x32, -24, -16
    subsprite OAM_SIZE_16x32, 8, -16
    subsprite OAM_SIZE_32x8, -24, 16
  Subsprite_322:
    subsprite OAM_SIZE_32x32, -24, -16
    subsprite OAM_SIZE_16x32, 8, -16
    subsprite OAM_SIZE_32x8, -24, 16
  Subsprite_325:
    subsprite OAM_SIZE_32x32, -24, -16
    subsprite OAM_SIZE_16x32, 8, -16
    subsprite OAM_SIZE_32x8, -24, 16
  Subsprite_328:
    subsprite OAM_SIZE_32x32, -24, -16
    subsprite OAM_SIZE_16x32, 8, -16
    subsprite OAM_SIZE_32x8, -24, 16
  Subsprite_331:
    subsprite OAM_SIZE_32x32, -24, -16
    subsprite OAM_SIZE_16x32, 8, -16
    subsprite OAM_SIZE_32x8, -24, 16
  Subsprite_334:
    subsprite OAM_SIZE_32x32, -24, -16
    subsprite OAM_SIZE_16x32, 8, -16
    subsprite OAM_SIZE_32x8, -24, 16
  Subsprite_337:
    subsprite OAM_SIZE_32x32, -24, -24
    subsprite OAM_SIZE_32x16, -24, 8
    subsprite OAM_SIZE_16x32, 8, -24
    subsprite OAM_SIZE_16x16, 8, 8
  Subsprite_341:
    subsprite OAM_SIZE_32x32, -24, -24
    subsprite OAM_SIZE_32x16, -24, 8
    subsprite OAM_SIZE_16x32, 8, -24
    subsprite OAM_SIZE_16x16, 8, 8
  Subsprite_345:
    subsprite OAM_SIZE_32x64, -16, -24
  Subsprite_346:
    subsprite OAM_SIZE_8x32, 8, -32
    subsprite OAM_SIZE_8x16, 0, -32
    subsprite OAM_SIZE_8x8, 0, -16
  Subsprite_349:
    subsprite OAM_SIZE_8x32, 8, -32
    subsprite OAM_SIZE_8x16, 0, -32
    subsprite OAM_SIZE_8x8, 0, -16
  Subsprite_352:
    subsprite OAM_SIZE_16x32, 0, -32
  Subsprite_353:
    subsprite OAM_SIZE_8x32, 8, -32
    subsprite OAM_SIZE_8x16, 0, -24
    subsprite OAM_SIZE_8x8, 0, -8
  Subsprite_356:
    subsprite OAM_SIZE_32x32, -16, -32
  Subsprite_357:
    subsprite OAM_SIZE_32x32, -16, -32
  Subsprite_358:
    subsprite OAM_SIZE_16x8, -8, -8
    subsprite OAM_SIZE_8x8, 0, -32
    subsprite OAM_SIZE_8x8, 8, -8
  Subsprite_361:
    subsprite OAM_SIZE_32x32, -8, -32
  Subsprite_362:
    subsprite OAM_SIZE_32x32, -8, -32
  Subsprite_363:
    subsprite OAM_SIZE_16x8, -8, -8
    subsprite OAM_SIZE_8x8, 16, -32
    subsprite OAM_SIZE_8x8, -8, -16
  Subsprite_366:
    subsprite OAM_SIZE_8x32, 16, -24
    subsprite OAM_SIZE_8x16, 24, -24
    subsprite OAM_SIZE_8x8, 24, -8
  Subsprite_369:
    subsprite OAM_SIZE_16x32, 8, -24
    subsprite OAM_SIZE_8x16, 24, -16
  Subsprite_371:
    subsprite OAM_SIZE_8x32, 8, -24
    subsprite OAM_SIZE_8x8, 24, -16
  Subsprite_373:
    subsprite OAM_SIZE_32x32, -8, -16
  Subsprite_374:
    subsprite OAM_SIZE_32x32, -8, -16
  Subsprite_375:
    subsprite OAM_SIZE_16x8, -8, -16
    subsprite OAM_SIZE_8x8, -8, -8
    subsprite OAM_SIZE_8x8, 16, 8
  Subsprite_378:
    subsprite OAM_SIZE_32x32, -16, -8
  Subsprite_379:
    subsprite OAM_SIZE_32x32, -16, -16
    subsprite OAM_SIZE_32x8, -16, 16
  Subsprite_381:
    subsprite OAM_SIZE_16x32, -8, -16
    subsprite OAM_SIZE_8x32, 8, -16
    subsprite OAM_SIZE_16x8, -8, 16
  Subsprite_384:
    subsprite OAM_SIZE_16x16, -8, -32
  Subsprite_385:
    subsprite OAM_SIZE_16x16, 8, -32
    subsprite OAM_SIZE_8x8, 0, -24
    subsprite OAM_SIZE_8x8, 8, -16
  Subsprite_388:
    subsprite OAM_SIZE_16x16, 16, -16
  Subsprite_389:
    subsprite OAM_SIZE_16x16, 8, 0
    subsprite OAM_SIZE_8x8, 8, -8
    subsprite OAM_SIZE_8x8, 0, 0
  Subsprite_392:
    subsprite OAM_SIZE_16x16, -8, 0
    subsprite OAM_SIZE_16x8, -8, 16
  Subsprite_394:
    subsprite OAM_SIZE_8x8, 0, -32
  Subsprite_395:
    subsprite OAM_SIZE_8x8, 0, -32
  Subsprite_396:
    subsprite OAM_SIZE_16x16, 8, -32
  Subsprite_397:
    subsprite OAM_SIZE_8x16, 8, -32
  Subsprite_398:
    subsprite OAM_SIZE_16x16, 16, -16
  Subsprite_399:
    subsprite OAM_SIZE_16x8, 16, -16
  Subsprite_400:
    subsprite OAM_SIZE_16x16, 8, 0
  Subsprite_401:
    subsprite OAM_SIZE_16x16, 8, 0
  Subsprite_402:
    subsprite OAM_SIZE_8x16, 0, 8
  Subsprite_403:
    subsprite OAM_SIZE_8x16, 0, 8
  Subsprite_404:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_405:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_406:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_407:
    subsprite OAM_SIZE_16x32, -8, -16
  Subsprite_408:
    subsprite OAM_SIZE_16x32, -8, -16
  Subsprite_409:
    subsprite OAM_SIZE_32x64, -24, -46
    subsprite OAM_SIZE_16x32, 8, -46
    subsprite OAM_SIZE_16x32, 8, -14
  Subsprite_412:
    subsprite OAM_SIZE_32x64, -24, -64
    subsprite OAM_SIZE_16x32, 8, -64
    subsprite OAM_SIZE_16x32, 8, -32
  Subsprite_415:
    subsprite OAM_SIZE_32x64, -24, -64
    subsprite OAM_SIZE_16x32, 8, -64
    subsprite OAM_SIZE_16x32, 8, -32
  Subsprite_418:
    subsprite OAM_SIZE_32x32, -24, -48
    subsprite OAM_SIZE_32x16, -24, -16
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x16, 8, -16
  Subsprite_422:
    subsprite OAM_SIZE_32x32, -24, -48
    subsprite OAM_SIZE_32x16, -24, -16
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x16, 8, -16
  Subsprite_426:
    subsprite OAM_SIZE_32x32, -24, -48
    subsprite OAM_SIZE_32x16, -24, -16
    subsprite OAM_SIZE_8x16, 8, -16
  Subsprite_429:
    subsprite OAM_SIZE_16x16, -7, -14
  Subsprite_430:
    subsprite OAM_SIZE_16x16, -7, -14
  Subsprite_431:
    subsprite OAM_SIZE_16x16, -7, -14
  Subsprite_432:
    subsprite OAM_SIZE_16x16, -7, -14
  Subsprite_433:
    subsprite OAM_SIZE_16x16, -7, -14
  Subsprite_434:
    subsprite OAM_SIZE_16x16, -7, -14
  Subsprite_435:
    subsprite OAM_SIZE_16x16, -7, -14
  Subsprite_436:
    subsprite OAM_SIZE_16x16, -7, -14
  Subsprite_437:
    subsprite OAM_SIZE_16x32, -12, -20
    subsprite OAM_SIZE_8x32, 4, -20
  Subsprite_439:
    subsprite OAM_SIZE_16x32, -12, -20
    subsprite OAM_SIZE_8x32, 4, -20
  Subsprite_441:
    subsprite OAM_SIZE_16x32, -12, -20
    subsprite OAM_SIZE_8x32, 4, -20
  Subsprite_443:
    subsprite OAM_SIZE_16x32, -12, -20
    subsprite OAM_SIZE_8x32, 4, -20
  Subsprite_445:
    subsprite OAM_SIZE_16x32, -12, -20
    subsprite OAM_SIZE_8x32, 4, -20
  Subsprite_447:
    subsprite OAM_SIZE_16x32, -12, -20
    subsprite OAM_SIZE_8x32, 4, -20
  Subsprite_449:
    subsprite OAM_SIZE_16x32, -12, -20
    subsprite OAM_SIZE_8x32, 4, -20
  Subsprite_451:
    subsprite OAM_SIZE_16x32, -12, -20
    subsprite OAM_SIZE_8x32, 4, -20
  Subsprite_453:
    subsprite OAM_SIZE_16x32, -12, -20
    subsprite OAM_SIZE_8x32, 4, -20
  Subsprite_455:
    subsprite OAM_SIZE_16x32, -12, -20
    subsprite OAM_SIZE_8x32, 4, -20
  Subsprite_457:
    subsprite OAM_SIZE_16x32, -12, -20
    subsprite OAM_SIZE_8x32, 4, -20
  Subsprite_459:
    subsprite OAM_SIZE_16x32, -12, -20
    subsprite OAM_SIZE_8x32, 4, -20
  Subsprite_461:
    subsprite OAM_SIZE_16x32, -12, -20
    subsprite OAM_SIZE_8x32, 4, -20
  Subsprite_463:
    subsprite OAM_SIZE_16x32, -12, -20
    subsprite OAM_SIZE_8x32, 4, -20
  Subsprite_465:
    subsprite OAM_SIZE_16x32, -12, -20
    subsprite OAM_SIZE_8x32, 4, -20
  Subsprite_467:
    subsprite OAM_SIZE_16x32, -12, -20
    subsprite OAM_SIZE_8x32, 4, -20
  Subsprite_469:
    subsprite OAM_SIZE_16x32, -8, -16
  Subsprite_470:
    subsprite OAM_SIZE_16x32, -8, -16
  Subsprite_471:
    subsprite OAM_SIZE_16x32, -8, -16
  Subsprite_472:
    subsprite OAM_SIZE_16x32, -8, -16
  Subsprite_473:
    subsprite OAM_SIZE_16x32, -8, -16
  Subsprite_474:
    subsprite OAM_SIZE_16x32, -8, -16
  Subsprite_475:
    subsprite OAM_SIZE_16x32, -8, -16
  Subsprite_476:
    subsprite OAM_SIZE_16x16, -16, -16
    subsprite OAM_SIZE_16x8, -8, 0
    subsprite OAM_SIZE_8x8, 0, -8
  Subsprite_479:
    subsprite OAM_SIZE_32x32, 0, 0
  Subsprite_480:
    subsprite OAM_SIZE_16x32, -8, -16
    subsprite OAM_SIZE_8x8, -16, 0
    subsprite OAM_SIZE_8x8, 8, 0
  Subsprite_483:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_484:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_485:
    subsprite OAM_SIZE_32x16, -16, -8
    subsprite OAM_SIZE_32x8, -16, 8
  Subsprite_487:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_488:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_489:
    subsprite OAM_SIZE_32x16, -16, -8
    subsprite OAM_SIZE_16x8, -8, -16
    subsprite OAM_SIZE_16x8, -8, 8
  Subsprite_492:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_493:
    subsprite OAM_SIZE_8x8, -4, -4
  Subsprite_494:
    subsprite OAM_SIZE_8x8, -4, -4
  Subsprite_495:
    subsprite OAM_SIZE_8x8, -4, -4
  Subsprite_496:
    subsprite OAM_SIZE_8x8, -4, -4
  Subsprite_497:
    subsprite OAM_SIZE_8x8, -4, -4
  Subsprite_498:
    subsprite OAM_SIZE_8x8, -4, -4
  Subsprite_499:
    subsprite OAM_SIZE_8x8, -4, -4
  Subsprite_500:
    subsprite OAM_SIZE_8x8, -4, -4
  Subsprite_501:
    subsprite OAM_SIZE_8x8, -4, -4
  Subsprite_502:
    subsprite OAM_SIZE_8x8, -4, -4
  Subsprite_503:
    subsprite OAM_SIZE_8x8, -4, -4
  Subsprite_504:
    subsprite OAM_SIZE_32x32, -24, -48
    subsprite OAM_SIZE_32x16, -24, -16
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x16, 8, -16
  Subsprite_508:
    subsprite OAM_SIZE_32x32, -24, -48
    subsprite OAM_SIZE_32x16, -24, -16
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x16, 8, -16
  Subsprite_512:
    subsprite OAM_SIZE_32x32, -24, -40
    subsprite OAM_SIZE_16x32, 8, -40
    subsprite OAM_SIZE_32x8, -24, -8
    subsprite OAM_SIZE_16x8, 8, -8
  Subsprite_516:
    subsprite OAM_SIZE_32x32, -24, -48
    subsprite OAM_SIZE_32x16, -24, -16
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x16, 8, -16
  Subsprite_520:
    subsprite OAM_SIZE_32x32, -24, -48
    subsprite OAM_SIZE_32x16, -24, -16
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x16, 8, -16
  Subsprite_524:
    subsprite OAM_SIZE_32x32, -24, -48
    subsprite OAM_SIZE_32x16, -24, -16
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x16, 8, -16
  Subsprite_528:
    subsprite OAM_SIZE_32x32, -24, -48
    subsprite OAM_SIZE_32x16, -24, -16
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x16, 8, -16
  Subsprite_532:
    subsprite OAM_SIZE_32x32, -24, -48
    subsprite OAM_SIZE_32x16, -24, -16
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x16, 8, -16
  Subsprite_536:
    subsprite OAM_SIZE_32x32, -24, -48
    subsprite OAM_SIZE_32x16, -24, -16
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x16, 8, -16
  Subsprite_540:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_541:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_542:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_543:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_544:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_545:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_546:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_547:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_548:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_549:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_550:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_551:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_552:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_553:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_554:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_555:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_556:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_557:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_558:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_559:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_560:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_561:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_562:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_563:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_564:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_565:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_566:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_567:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_568:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_569:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_570:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_571:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_572:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_573:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_574:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_575:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_576:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_577:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_578:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_579:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_580:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_581:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_582:
    subsprite OAM_SIZE_16x16, -13, -12
    subsprite OAM_SIZE_16x8, -5, 4
    subsprite OAM_SIZE_8x16, 3, -12
  Subsprite_585:
    subsprite OAM_SIZE_32x32, -21, -12
    subsprite OAM_SIZE_8x32, 11, -12
  Subsprite_587:
    subsprite OAM_SIZE_32x32, -21, -20
    subsprite OAM_SIZE_32x16, -21, 12
    subsprite OAM_SIZE_8x32, 11, -20
    subsprite OAM_SIZE_8x16, 11, 12
  Subsprite_591:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_592:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_593:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_594:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_595:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_596:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_597:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_598:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_599:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_600:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_601:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_602:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_603:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_604:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_605:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_606:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_607:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_608:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_609:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_610:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_611:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_612:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_613:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_614:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_615:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_616:
    subsprite OAM_SIZE_64x64, -32, -32
  Subsprite_617:
    subsprite OAM_SIZE_8x16, -4, -8
  Subsprite_618:
    subsprite OAM_SIZE_8x16, -4, -8
  Subsprite_619:
    subsprite OAM_SIZE_8x16, -4, -8
  Subsprite_620:
    subsprite OAM_SIZE_8x16, -4, -8
  Subsprite_621:
    subsprite OAM_SIZE_8x8, -4, 0
  Subsprite_622:
    subsprite OAM_SIZE_8x16, -4, -8
  Subsprite_623:
    subsprite OAM_SIZE_8x8, -4, 0
  Subsprite_624:
    subsprite OAM_SIZE_8x16, -4, -8
  Subsprite_625:
    subsprite OAM_SIZE_8x16, -4, -8
  Subsprite_626:
    subsprite OAM_SIZE_8x8, -4, 0
  Subsprite_627:
    subsprite OAM_SIZE_32x16, -16, -8
  Subsprite_628:
    subsprite OAM_SIZE_32x16, -16, -8
  Subsprite_629:
    subsprite OAM_SIZE_32x16, -16, -8
  Subsprite_630:
    subsprite OAM_SIZE_32x16, -16, -8
  Subsprite_631:
    subsprite OAM_SIZE_32x16, -16, -8
  Subsprite_632:
    subsprite OAM_SIZE_32x16, -16, -8
  Subsprite_633:
    subsprite OAM_SIZE_32x16, -16, -8
  Subsprite_634:
    subsprite OAM_SIZE_16x32, 0, -48
    subsprite OAM_SIZE_16x32, 0, -16
    subsprite OAM_SIZE_8x32, 16, -48
    subsprite OAM_SIZE_8x32, 16, -16
  Subsprite_638:
    subsprite OAM_SIZE_32x32, -16, -32
    subsprite OAM_SIZE_32x8, -16, 0
  Subsprite_640:
    subsprite OAM_SIZE_32x64, -16, -52
  Subsprite_641:
    subsprite OAM_SIZE_32x64, -16, -52
  Subsprite_642:
    subsprite OAM_SIZE_32x64, -16, -52
  Subsprite_643:
    subsprite OAM_SIZE_32x64, -16, -64
  Subsprite_644:
    subsprite OAM_SIZE_32x64, -20, -44
    subsprite OAM_SIZE_8x32, 12, -44
    subsprite OAM_SIZE_8x32, 12, -12
  Subsprite_647:
    subsprite OAM_SIZE_32x32, -20, -28
    subsprite OAM_SIZE_32x16, -20, 4
    subsprite OAM_SIZE_8x32, 12, -28
    subsprite OAM_SIZE_8x16, 12, 4
  Subsprite_651:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_652:
    subsprite OAM_SIZE_16x16, -8, -8
    subsprite OAM_SIZE_16x8, -8, 8
    subsprite OAM_SIZE_8x16, 8, -8
  Subsprite_655:
    subsprite OAM_SIZE_32x16, -16, -8
    subsprite OAM_SIZE_16x8, -8, -16
    subsprite OAM_SIZE_16x8, -8, 8
  Subsprite_658:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_659:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_660:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_661:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_662:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_663:
    subsprite OAM_SIZE_32x16, -16, -8
    subsprite OAM_SIZE_16x8, -8, -16
    subsprite OAM_SIZE_8x8, 0, 8
  Subsprite_666:
    subsprite OAM_SIZE_8x8, -4, -4
  Subsprite_667:
    subsprite OAM_SIZE_8x8, -4, -4
  Subsprite_668:
    subsprite OAM_SIZE_8x8, -4, -4
  Subsprite_669:
    subsprite OAM_SIZE_8x8, -4, -4
  Subsprite_670:
    subsprite OAM_SIZE_8x8, -4, -4
  Subsprite_671:
    subsprite OAM_SIZE_8x8, -4, -4
  Subsprite_672:
    subsprite OAM_SIZE_32x64, -16, -40
    subsprite OAM_SIZE_8x32, 16, -40
    subsprite OAM_SIZE_8x32, 16, -8
  Subsprite_675:
    subsprite OAM_SIZE_16x32, -16, -32
    subsprite OAM_SIZE_16x32, -16, 0
    subsprite OAM_SIZE_8x32, 0, -32
    subsprite OAM_SIZE_8x32, 0, 0
  Subsprite_679:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_680:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_681:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_682:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_683:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_684:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_685:
    subsprite OAM_SIZE_32x16, -16, -16
    subsprite OAM_SIZE_32x8, -16, 0
    subsprite OAM_SIZE_16x8, 0, 8
  Subsprite_688:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_689:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_690:
    subsprite OAM_SIZE_32x16, -16, -16
    subsprite OAM_SIZE_32x8, -16, 0
    subsprite OAM_SIZE_8x8, 0, 8
  Subsprite_693:
    subsprite OAM_SIZE_32x16, -16, -8
    subsprite OAM_SIZE_16x8, 0, -16
    subsprite OAM_SIZE_8x8, -8, 8
  Subsprite_696:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_697:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_698:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_699:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_700:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_701:
    subsprite OAM_SIZE_32x64, -16, -52
  Subsprite_702:
    subsprite OAM_SIZE_32x64, -16, -52
  Subsprite_703:
    subsprite OAM_SIZE_32x64, -16, -52
  Subsprite_704:
    subsprite OAM_SIZE_32x16, -16, -10
    subsprite OAM_SIZE_16x8, -8, -18
    subsprite OAM_SIZE_16x8, -8, 6
  Subsprite_707:
    subsprite OAM_SIZE_32x16, -16, -10
    subsprite OAM_SIZE_16x8, -8, -18
    subsprite OAM_SIZE_16x8, -8, 6
  Subsprite_710:
    subsprite OAM_SIZE_32x16, -16, -10
    subsprite OAM_SIZE_16x8, -8, -18
    subsprite OAM_SIZE_16x8, -8, 6
  Subsprite_713:
    subsprite OAM_SIZE_32x32, -16, -18
  Subsprite_714:
    subsprite OAM_SIZE_32x32, -16, -18
  Subsprite_715:
    subsprite OAM_SIZE_32x16, -16, -10
    subsprite OAM_SIZE_32x8, -16, 6
    subsprite OAM_SIZE_16x8, -8, -18
  Subsprite_718:
    subsprite OAM_SIZE_32x16, -16, -10
    subsprite OAM_SIZE_16x8, -8, -18
    subsprite OAM_SIZE_16x8, -8, 6
  Subsprite_721:
    subsprite OAM_SIZE_32x16, -16, -10
    subsprite OAM_SIZE_32x8, -16, 6
    subsprite OAM_SIZE_16x8, -8, -18
  Subsprite_724:
    subsprite OAM_SIZE_32x16, -16, -10
    subsprite OAM_SIZE_32x8, -16, 6
    subsprite OAM_SIZE_16x8, -8, -18
  Subsprite_727:
    subsprite OAM_SIZE_32x16, -16, -10
    subsprite OAM_SIZE_16x8, -8, -18
    subsprite OAM_SIZE_16x8, -8, 6
  Subsprite_730:
    subsprite OAM_SIZE_32x16, -16, -18
    subsprite OAM_SIZE_32x8, -16, -2
  Subsprite_732:
    subsprite OAM_SIZE_32x16, -16, -18
    subsprite OAM_SIZE_16x8, -8, -2
  Subsprite_734:
    subsprite OAM_SIZE_32x32, -16, -18
  Subsprite_735:
    subsprite OAM_SIZE_32x16, -16, -10
    subsprite OAM_SIZE_16x8, -8, -18
    subsprite OAM_SIZE_16x8, -8, 6
  Subsprite_738:
    subsprite OAM_SIZE_32x16, -16, -10
    subsprite OAM_SIZE_16x8, -8, -18
    subsprite OAM_SIZE_16x8, -8, 6
  Subsprite_741:
    subsprite OAM_SIZE_32x16, -16, -18
    subsprite OAM_SIZE_32x8, -16, -2
    subsprite OAM_SIZE_16x8, -8, 6
  Subsprite_744:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_745:
    subsprite OAM_SIZE_8x8, -4, -4
  Subsprite_746:
    subsprite OAM_SIZE_8x8, -4, -4
  Subsprite_747:
    subsprite OAM_SIZE_8x8, -4, -4
  Subsprite_748:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_751:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_754:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_757:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_760:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_763:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_766:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_769:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_772:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_773:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_774:
    subsprite OAM_SIZE_32x32, -6, -49
    subsprite OAM_SIZE_32x16, -6, -17
    subsprite OAM_SIZE_16x32, 26, -49
    subsprite OAM_SIZE_16x16, 26, -17
  Subsprite_778:
    subsprite OAM_SIZE_32x32, -6, -49
    subsprite OAM_SIZE_16x32, 26, -49
  Subsprite_780:
    subsprite OAM_SIZE_32x32, -6, -49
    subsprite OAM_SIZE_32x16, -6, -17
    subsprite OAM_SIZE_16x32, 26, -49
  Subsprite_783:
    subsprite OAM_SIZE_16x32, -6, -49
    subsprite OAM_SIZE_16x16, -6, -17
    subsprite OAM_SIZE_16x8, -6, -1
  Subsprite_786:
    subsprite OAM_SIZE_32x32, -24, -32
    subsprite OAM_SIZE_32x16, -24, 0
    subsprite OAM_SIZE_16x32, 8, -32
    subsprite OAM_SIZE_16x16, 8, 0
  Subsprite_790:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_793:
    subsprite OAM_SIZE_64x64, -24, -48
  Subsprite_794:
    subsprite OAM_SIZE_64x64, -32, -32
  Subsprite_795:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_798:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_801:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_804:
    subsprite OAM_SIZE_32x32, -24, -32
    subsprite OAM_SIZE_32x16, -24, 0
    subsprite OAM_SIZE_8x32, 8, -32
    subsprite OAM_SIZE_8x16, 8, 0
  Subsprite_808:
    subsprite OAM_SIZE_32x32, -16, -32
    subsprite OAM_SIZE_32x16, -16, 0
    subsprite OAM_SIZE_8x32, 16, -32
    subsprite OAM_SIZE_8x16, 16, 0
  Subsprite_812:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_815:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_818:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_821:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_824:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_827:
    subsprite OAM_SIZE_16x16, -8, -16
    subsprite OAM_SIZE_16x8, -8, 0
  Subsprite_829:
    subsprite OAM_SIZE_32x32, -16, -32
    subsprite OAM_SIZE_32x16, -16, 0
  Subsprite_831:
    subsprite OAM_SIZE_32x64, -16, -48
  Subsprite_832:
    subsprite OAM_SIZE_32x64, -16, -48
  Subsprite_833:
    subsprite OAM_SIZE_32x64, -16, -48
  Subsprite_834:
    subsprite OAM_SIZE_32x64, -16, -48
  Subsprite_835:
    subsprite OAM_SIZE_32x64, -16, -48
  Subsprite_836:
    subsprite OAM_SIZE_16x32, -9, -29
  Subsprite_837:
    subsprite OAM_SIZE_32x8, 0, 0
  Subsprite_838:
    subsprite OAM_SIZE_32x8, 0, 0
  Subsprite_839:
    subsprite OAM_SIZE_32x64, -24, -40
  Subsprite_840:
    subsprite OAM_SIZE_32x64, -32, -48
    subsprite OAM_SIZE_8x32, 0, -48
    subsprite OAM_SIZE_8x32, 0, -16
  Subsprite_843:
    subsprite OAM_SIZE_32x64, -24, -64
  Subsprite_844:
    subsprite OAM_SIZE_32x64, -24, -40
  Subsprite_845:
    subsprite OAM_SIZE_32x32, -24, -40
    subsprite OAM_SIZE_32x8, -24, -8
  Subsprite_847:
    subsprite OAM_SIZE_16x32, -16, -48
    subsprite OAM_SIZE_8x32, 0, -48
    subsprite OAM_SIZE_16x16, -16, -16
    subsprite OAM_SIZE_8x16, 0, -16
  Subsprite_851:
    subsprite OAM_SIZE_32x64, -24, -40
  Subsprite_852:
    subsprite OAM_SIZE_32x32, -24, -40
    subsprite OAM_SIZE_32x8, -24, -8
  Subsprite_854:
    subsprite OAM_SIZE_16x32, -16, -48
    subsprite OAM_SIZE_8x32, 0, -48
    subsprite OAM_SIZE_16x16, -16, -16
    subsprite OAM_SIZE_8x16, 0, -16
  Subsprite_858:
    subsprite OAM_SIZE_32x64, -24, -40
  Subsprite_859:
    subsprite OAM_SIZE_32x64, -32, -48
    subsprite OAM_SIZE_8x32, 0, -48
    subsprite OAM_SIZE_8x32, 0, -16
  Subsprite_862:
    subsprite OAM_SIZE_32x64, -24, -64
  Subsprite_863:
    subsprite OAM_SIZE_32x64, -24, -40
  Subsprite_864:
    subsprite OAM_SIZE_32x64, -32, -48
    subsprite OAM_SIZE_8x32, 0, -48
    subsprite OAM_SIZE_8x32, 0, -16
  Subsprite_867:
    subsprite OAM_SIZE_32x64, -24, -64
  Subsprite_868:
    subsprite OAM_SIZE_32x64, -24, -40
  Subsprite_869:
    subsprite OAM_SIZE_32x64, -32, -48
    subsprite OAM_SIZE_8x32, 0, -48
    subsprite OAM_SIZE_8x32, 0, -16
  Subsprite_872:
    subsprite OAM_SIZE_32x64, -24, -64
  Subsprite_873:
    subsprite OAM_SIZE_32x64, -24, -40
  Subsprite_874:
    subsprite OAM_SIZE_32x32, -24, -40
    subsprite OAM_SIZE_32x8, -24, -8
  Subsprite_876:
    subsprite OAM_SIZE_16x32, -16, -48
    subsprite OAM_SIZE_8x32, 0, -48
    subsprite OAM_SIZE_16x16, -16, -16
    subsprite OAM_SIZE_8x16, 0, -16
  Subsprite_880:
    subsprite OAM_SIZE_32x64, -24, -40
  Subsprite_881:
    subsprite OAM_SIZE_32x32, -24, -40
    subsprite OAM_SIZE_32x8, -24, -8
  Subsprite_883:
    subsprite OAM_SIZE_16x32, -16, -48
    subsprite OAM_SIZE_8x32, 0, -48
    subsprite OAM_SIZE_16x16, -16, -16
    subsprite OAM_SIZE_8x16, 0, -16
  Subsprite_887:
    subsprite OAM_SIZE_32x64, -24, -40
  Subsprite_888:
    subsprite OAM_SIZE_32x64, -32, -48
    subsprite OAM_SIZE_8x32, 0, -48
    subsprite OAM_SIZE_8x32, 0, -16
  Subsprite_891:
    subsprite OAM_SIZE_32x64, -24, -64
  Subsprite_892:
    subsprite OAM_SIZE_32x64, -24, -40
  Subsprite_893:
    subsprite OAM_SIZE_32x64, -32, -48
    subsprite OAM_SIZE_8x32, 0, -48
    subsprite OAM_SIZE_8x32, 0, -16
  Subsprite_896:
    subsprite OAM_SIZE_32x64, -24, -64
  Subsprite_897:
    subsprite OAM_SIZE_32x16, -17, -17
    subsprite OAM_SIZE_16x8, -9, -1
  Subsprite_899:
    subsprite OAM_SIZE_32x16, -17, -9
    subsprite OAM_SIZE_16x8, -17, -17
    subsprite OAM_SIZE_8x8, 7, -17
  Subsprite_902:
    subsprite OAM_SIZE_32x16, -17, -9
  Subsprite_903:
    subsprite OAM_SIZE_16x16, -9, -17
    subsprite OAM_SIZE_16x8, -9, -1
    subsprite OAM_SIZE_8x16, 7, -17
    subsprite OAM_SIZE_8x8, 7, -1
  Subsprite_907:
    subsprite OAM_SIZE_16x16, -9, -9
    subsprite OAM_SIZE_8x16, 7, -9
    subsprite OAM_SIZE_8x8, -9, -17
  Subsprite_910:
    subsprite OAM_SIZE_16x16, -9, -9
    subsprite OAM_SIZE_8x16, 7, -9
  Subsprite_912:
    subsprite OAM_SIZE_16x16, -9, -17
    subsprite OAM_SIZE_16x8, -9, -1
    subsprite OAM_SIZE_8x16, 7, -17
    subsprite OAM_SIZE_8x8, 7, -1
  Subsprite_916:
    subsprite OAM_SIZE_16x16, -9, -9
    subsprite OAM_SIZE_8x16, 7, -9
    subsprite OAM_SIZE_8x8, -1, -17
  Subsprite_919:
    subsprite OAM_SIZE_16x16, -9, -9
    subsprite OAM_SIZE_8x8, -1, 7
  Subsprite_921:
    subsprite OAM_SIZE_16x16, -9, -9
    subsprite OAM_SIZE_8x16, 7, -9
  Subsprite_923:
    subsprite OAM_SIZE_16x16, -9, -9
    subsprite OAM_SIZE_8x16, 7, -9
    subsprite OAM_SIZE_8x8, -9, 7
  Subsprite_926:
    subsprite OAM_SIZE_16x16, -9, -9
    subsprite OAM_SIZE_8x16, 7, -9
    subsprite OAM_SIZE_8x8, -9, 7
  Subsprite_929:
    subsprite OAM_SIZE_32x16, -17, -9
  Subsprite_930:
    subsprite OAM_SIZE_32x16, -17, -9
  Subsprite_931:
    subsprite OAM_SIZE_32x16, -17, -9
    subsprite OAM_SIZE_16x8, -9, 7
  Subsprite_933:
    subsprite OAM_SIZE_16x16, -9, -9
    subsprite OAM_SIZE_8x16, 7, -17
    subsprite OAM_SIZE_8x8, -9, -17
  Subsprite_936:
    subsprite OAM_SIZE_16x16, -9, -9
    subsprite OAM_SIZE_8x16, 7, -9
    subsprite OAM_SIZE_8x8, -9, -17
  Subsprite_939:
    subsprite OAM_SIZE_16x16, -9, -9
    subsprite OAM_SIZE_8x16, 7, -9
  Subsprite_941:
    subsprite OAM_SIZE_32x8, -17, -9
    subsprite OAM_SIZE_16x8, -17, -17
    subsprite OAM_SIZE_16x8, -9, -1
  Subsprite_944:
    subsprite OAM_SIZE_32x8, -17, -9
    subsprite OAM_SIZE_16x8, -17, -17
    subsprite OAM_SIZE_16x8, -9, -1
  Subsprite_947:
    subsprite OAM_SIZE_32x8, -17, -9
    subsprite OAM_SIZE_16x8, -17, -1
    subsprite OAM_SIZE_8x8, -1, -1
  Subsprite_950:
    subsprite OAM_SIZE_16x16, -9, -9
    subsprite OAM_SIZE_8x8, -1, -17
    subsprite OAM_SIZE_8x8, 7, -9
  Subsprite_953:
    subsprite OAM_SIZE_16x16, -9, -9
    subsprite OAM_SIZE_8x8, -1, -17
    subsprite OAM_SIZE_8x8, 7, -9
  Subsprite_956:
    subsprite OAM_SIZE_16x16, -9, -9
    subsprite OAM_SIZE_8x16, 7, -9
  Subsprite_958:
    subsprite OAM_SIZE_8x32, -1, -17
    subsprite OAM_SIZE_16x16, -17, -9
  Subsprite_960:
    subsprite OAM_SIZE_8x32, -1, -17
    subsprite OAM_SIZE_16x16, -17, -9
  Subsprite_962:
    subsprite OAM_SIZE_16x16, -17, -9
    subsprite OAM_SIZE_8x16, -1, -9
    subsprite OAM_SIZE_8x8, -1, 7
  Subsprite_965:
    subsprite OAM_SIZE_16x16, -9, -9
    subsprite OAM_SIZE_8x8, -9, -17
  Subsprite_967:
    subsprite OAM_SIZE_16x16, -9, -9
  Subsprite_968:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_971:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_974:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_977:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_980:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_983:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_986:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_989:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_992:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_995:
    subsprite OAM_SIZE_32x64, -16, -48
    subsprite OAM_SIZE_8x32, 16, -48
  Subsprite_997:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_1000:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_1003:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1004:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_1005:
    subsprite OAM_SIZE_16x16, -16, -8
    subsprite OAM_SIZE_16x8, -8, 8
    subsprite OAM_SIZE_8x8, 0, 0
  Subsprite_1008:
    subsprite OAM_SIZE_16x16, -8, -16
    subsprite OAM_SIZE_8x16, 8, -16
    subsprite OAM_SIZE_8x8, 8, 0
  Subsprite_1011:
    subsprite OAM_SIZE_16x16, -8, -16
    subsprite OAM_SIZE_16x8, 0, 0
    subsprite OAM_SIZE_8x16, 8, -16
  Subsprite_1014:
    subsprite OAM_SIZE_16x16, -16, -8
    subsprite OAM_SIZE_16x8, -16, 8
    subsprite OAM_SIZE_8x16, 0, 0
  Subsprite_1017:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_1018:
    subsprite OAM_SIZE_8x8, -16, 8
  Subsprite_1019:
    subsprite OAM_SIZE_64x64, -33, -54
  Subsprite_1020:
    subsprite OAM_SIZE_32x32, -20, -20
    subsprite OAM_SIZE_32x8, -20, 12
    subsprite OAM_SIZE_8x32, 12, -20
  Subsprite_1023:
    subsprite OAM_SIZE_32x64, -16, -52
  Subsprite_1024:
    subsprite OAM_SIZE_32x64, -16, -52
  Subsprite_1025:
    subsprite OAM_SIZE_32x64, -16, -52
  Subsprite_1026:
    subsprite OAM_SIZE_32x64, -16, -52
  Subsprite_1027:
    subsprite OAM_SIZE_32x64, -16, -52
  Subsprite_1028:
    subsprite OAM_SIZE_32x64, -16, -52
  Subsprite_1029:
    subsprite OAM_SIZE_32x64, -16, -52
  Subsprite_1030:
    subsprite OAM_SIZE_32x64, -16, -52
  Subsprite_1031:
    subsprite OAM_SIZE_32x32, -24, 0
    subsprite OAM_SIZE_32x8, -24, 32
    subsprite OAM_SIZE_8x32, 8, 0
  Subsprite_1034:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1035:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1036:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1037:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1038:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1039:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1040:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1041:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1042:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1043:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1044:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1045:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1046:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1047:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1048:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1049:
    subsprite OAM_SIZE_8x16, -8, -8
  Subsprite_1050:
    subsprite OAM_SIZE_8x8, -8, -8
  Subsprite_1051:
    subsprite OAM_SIZE_16x8, -8, -8
    subsprite OAM_SIZE_8x8, -8, 0
  Subsprite_1053:
    subsprite OAM_SIZE_16x8, -8, -8
    subsprite OAM_SIZE_8x8, -8, 0
  Subsprite_1055:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1056:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1057:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1058:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1059:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1060:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1061:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1062:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1063:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1064:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1065:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1066:
    subsprite OAM_SIZE_8x16, -4, -8
  Subsprite_1067:
    subsprite OAM_SIZE_8x16, -4, -8
  Subsprite_1068:
    subsprite OAM_SIZE_8x16, -4, -8
  Subsprite_1069:
    subsprite OAM_SIZE_8x16, -4, -8
  Subsprite_1070:
    subsprite OAM_SIZE_8x16, -4, -8
  Subsprite_1071:
    subsprite OAM_SIZE_8x16, -4, -8
  Subsprite_1072:
    subsprite OAM_SIZE_8x16, -4, -8
  Subsprite_1073:
    subsprite OAM_SIZE_8x16, -4, -8
  Subsprite_1074:
    subsprite OAM_SIZE_8x16, -4, -8
  Subsprite_1075:
    subsprite OAM_SIZE_8x16, -4, -8
  Subsprite_1076:
    subsprite OAM_SIZE_8x16, -4, -8
  Subsprite_1077:
    subsprite OAM_SIZE_16x32, -12, -28
    subsprite OAM_SIZE_8x32, 4, -28
  Subsprite_1079:
    subsprite OAM_SIZE_16x16, -12, -20
    subsprite OAM_SIZE_16x8, -12, -4
    subsprite OAM_SIZE_8x16, 4, -20
    subsprite OAM_SIZE_8x8, 4, -4
  Subsprite_1083:
    subsprite OAM_SIZE_32x32, -24, -24
    subsprite OAM_SIZE_32x16, -24, 8
    subsprite OAM_SIZE_16x32, 8, -24
    subsprite OAM_SIZE_16x16, 8, 8
  Subsprite_1087:
    subsprite OAM_SIZE_32x64, -20, -44
    subsprite OAM_SIZE_8x32, 12, -44
    subsprite OAM_SIZE_8x32, 12, -12
  Subsprite_1090:
    subsprite OAM_SIZE_32x64, -20, -44
    subsprite OAM_SIZE_8x32, 12, -44
    subsprite OAM_SIZE_8x32, 12, -12
  Subsprite_1093:
    subsprite OAM_SIZE_32x64, -20, -44
    subsprite OAM_SIZE_8x32, 12, -44
    subsprite OAM_SIZE_8x32, 12, -12
  Subsprite_1096:
    subsprite OAM_SIZE_32x64, -20, -44
    subsprite OAM_SIZE_8x32, 12, -44
    subsprite OAM_SIZE_8x32, 12, -12
  Subsprite_1099:
    subsprite OAM_SIZE_8x32, -8, -16
    subsprite OAM_SIZE_16x8, 0, -8
    subsprite OAM_SIZE_8x8, 0, 0
  Subsprite_1102:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_1103:
    subsprite OAM_SIZE_32x16, -16, -16
    subsprite OAM_SIZE_32x8, -16, 0
    subsprite OAM_SIZE_16x8, -8, 8
  Subsprite_1106:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_1107:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_1108:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_1109:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_1110:
    subsprite OAM_SIZE_32x16, -16, -16
    subsprite OAM_SIZE_32x8, -16, 0
    subsprite OAM_SIZE_16x8, -8, 8
  Subsprite_1113:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_1114:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_1115:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_1116:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_1117:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_1118:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_1119:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_1120:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_1121:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_1122:
    subsprite OAM_SIZE_32x16, -16, -8
    subsprite OAM_SIZE_16x8, -8, -16
    subsprite OAM_SIZE_16x8, -8, 8
  Subsprite_1125:
    subsprite OAM_SIZE_32x16, -16, -8
    subsprite OAM_SIZE_16x8, -8, -16
    subsprite OAM_SIZE_16x8, -8, 8
  Subsprite_1128:
    subsprite OAM_SIZE_16x32, -8, -16
    subsprite OAM_SIZE_8x16, 8, -8
    subsprite OAM_SIZE_8x8, -16, 0
  Subsprite_1131:
    subsprite OAM_SIZE_32x16, -16, -8
    subsprite OAM_SIZE_16x8, -8, -16
    subsprite OAM_SIZE_16x8, -8, 8
  Subsprite_1134:
    subsprite OAM_SIZE_32x16, -16, -8
    subsprite OAM_SIZE_16x8, -8, -16
    subsprite OAM_SIZE_16x8, -8, 8
  Subsprite_1137:
    subsprite OAM_SIZE_32x16, -16, -8
    subsprite OAM_SIZE_16x8, -8, -16
    subsprite OAM_SIZE_16x8, -8, 8
  Subsprite_1140:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1141:
    subsprite OAM_SIZE_32x16, -16, -8
    subsprite OAM_SIZE_16x8, -8, -16
    subsprite OAM_SIZE_16x8, -8, 8
  Subsprite_1144:
    subsprite OAM_SIZE_32x16, -16, -8
    subsprite OAM_SIZE_16x8, -8, -16
    subsprite OAM_SIZE_16x8, -8, 8
  Subsprite_1147:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1148:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1149:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1150:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1151:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1152:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1153:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1154:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1155:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1156:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1157:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1158:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1159:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1160:
    subsprite OAM_SIZE_32x32, -24, -32
    subsprite OAM_SIZE_16x32, 8, -32
    subsprite OAM_SIZE_32x8, -24, 0
    subsprite OAM_SIZE_16x8, 8, 0
  Subsprite_1164:
    subsprite OAM_SIZE_32x32, -16, -40
    subsprite OAM_SIZE_32x16, -16, -8
  Subsprite_1166:
    subsprite OAM_SIZE_32x32, -24, -40
    subsprite OAM_SIZE_32x16, -24, -8
    subsprite OAM_SIZE_16x32, 8, -40
    subsprite OAM_SIZE_16x16, 8, -8
  Subsprite_1170:
    subsprite OAM_SIZE_32x64, -24, -40
    subsprite OAM_SIZE_16x32, 8, -40
    subsprite OAM_SIZE_16x32, 8, -8
  Subsprite_1173:
    subsprite OAM_SIZE_32x32, -24, -40
    subsprite OAM_SIZE_32x16, -24, -8
    subsprite OAM_SIZE_8x32, 8, -40
    subsprite OAM_SIZE_8x16, 8, -8
  Subsprite_1177:
    subsprite OAM_SIZE_32x32, -24, -40
    subsprite OAM_SIZE_32x16, -24, -8
    subsprite OAM_SIZE_8x32, 8, -40
    subsprite OAM_SIZE_8x16, 8, -8
  Subsprite_1181:
    subsprite OAM_SIZE_32x32, -22, -32
    subsprite OAM_SIZE_32x16, -22, 0
    subsprite OAM_SIZE_8x32, 10, -32
    subsprite OAM_SIZE_8x16, 10, 0
  Subsprite_1185:
    subsprite OAM_SIZE_32x32, -22, -32
    subsprite OAM_SIZE_32x16, -22, 0
    subsprite OAM_SIZE_8x32, 10, -32
    subsprite OAM_SIZE_8x16, 10, 0
  Subsprite_1189:
    subsprite OAM_SIZE_32x32, -22, -32
    subsprite OAM_SIZE_32x16, -22, 0
    subsprite OAM_SIZE_8x32, 10, -32
    subsprite OAM_SIZE_8x16, 10, 0
  Subsprite_1193:
    subsprite OAM_SIZE_32x32, -22, -32
    subsprite OAM_SIZE_32x16, -22, 0
    subsprite OAM_SIZE_8x32, 10, -32
    subsprite OAM_SIZE_8x16, 10, 0
  Subsprite_1197:
    subsprite OAM_SIZE_32x32, -22, -32
    subsprite OAM_SIZE_32x16, -22, 0
    subsprite OAM_SIZE_8x32, 10, -32
    subsprite OAM_SIZE_8x16, 10, 0
  Subsprite_1201:
    subsprite OAM_SIZE_32x32, -22, -32
    subsprite OAM_SIZE_32x16, -22, 0
    subsprite OAM_SIZE_8x32, 10, -32
    subsprite OAM_SIZE_8x16, 10, 0
  Subsprite_1205:
    subsprite OAM_SIZE_32x32, -22, -32
    subsprite OAM_SIZE_32x16, -22, 0
    subsprite OAM_SIZE_8x32, 10, -32
    subsprite OAM_SIZE_8x16, 10, 0
  Subsprite_1209:
    subsprite OAM_SIZE_32x32, -22, -16
    subsprite OAM_SIZE_8x32, 10, -16
  Subsprite_1211:
    subsprite OAM_SIZE_32x32, -22, -16
    subsprite OAM_SIZE_8x32, 10, -16
  Subsprite_1213:
    subsprite OAM_SIZE_32x32, -22, -32
    subsprite OAM_SIZE_32x16, -22, 0
    subsprite OAM_SIZE_8x32, 10, -32
    subsprite OAM_SIZE_8x16, 10, 0
  Subsprite_1217:
    subsprite OAM_SIZE_32x32, -22, -32
    subsprite OAM_SIZE_32x16, -22, 0
    subsprite OAM_SIZE_8x32, 10, -32
    subsprite OAM_SIZE_8x16, 10, 0
  Subsprite_1221:
    subsprite OAM_SIZE_32x32, -22, -16
    subsprite OAM_SIZE_8x32, 10, -16
  Subsprite_1223:
    subsprite OAM_SIZE_32x32, -22, -16
    subsprite OAM_SIZE_8x32, 10, -16
  Subsprite_1225:
    subsprite OAM_SIZE_32x64, -22, -40
    subsprite OAM_SIZE_8x32, 10, -40
    subsprite OAM_SIZE_8x32, 10, -8
  Subsprite_1228:
    subsprite OAM_SIZE_32x32, -22, -24
    subsprite OAM_SIZE_32x8, -22, 8
    subsprite OAM_SIZE_8x32, 10, -24
  Subsprite_1231:
    subsprite OAM_SIZE_32x32, -22, -24
    subsprite OAM_SIZE_32x8, -22, 8
    subsprite OAM_SIZE_8x32, 10, -24
  Subsprite_1234:
    subsprite OAM_SIZE_32x32, -22, -32
    subsprite OAM_SIZE_32x16, -22, 0
    subsprite OAM_SIZE_8x32, 10, -32
    subsprite OAM_SIZE_8x16, 10, 0
  Subsprite_1238:
    subsprite OAM_SIZE_64x64, -30, -40
  Subsprite_1239:
    subsprite OAM_SIZE_32x32, -22, -32
    subsprite OAM_SIZE_32x16, -22, 0
    subsprite OAM_SIZE_16x32, 10, -32
    subsprite OAM_SIZE_16x16, 10, 0
  Subsprite_1243:
    subsprite OAM_SIZE_32x64, -22, -40
    subsprite OAM_SIZE_8x32, 10, -40
    subsprite OAM_SIZE_8x32, 10, -8
  Subsprite_1246:
    subsprite OAM_SIZE_32x32, -22, -32
    subsprite OAM_SIZE_32x16, -22, 0
    subsprite OAM_SIZE_8x32, 10, -32
    subsprite OAM_SIZE_8x16, 10, 0
  Subsprite_1250:
    subsprite OAM_SIZE_32x32, -22, -32
    subsprite OAM_SIZE_32x16, -22, 0
    subsprite OAM_SIZE_8x32, 10, -32
    subsprite OAM_SIZE_8x16, 10, 0
  Subsprite_1254:
    subsprite OAM_SIZE_32x32, -30, -24
    subsprite OAM_SIZE_16x32, 2, -24
    subsprite OAM_SIZE_32x8, -30, 8
    subsprite OAM_SIZE_16x8, 2, 8
  Subsprite_1258:
    subsprite OAM_SIZE_32x64, -22, -40
    subsprite OAM_SIZE_8x32, 10, -40
    subsprite OAM_SIZE_8x32, 10, -8
  Subsprite_1261:
    subsprite OAM_SIZE_64x32, -30, -24
    subsprite OAM_SIZE_32x16, -30, 8
    subsprite OAM_SIZE_32x16, 2, 8
  Subsprite_1264:
    subsprite OAM_SIZE_32x32, -22, -24
    subsprite OAM_SIZE_16x32, 10, -24
    subsprite OAM_SIZE_32x8, -22, 8
  Subsprite_1267:
    subsprite OAM_SIZE_32x32, -22, -24
    subsprite OAM_SIZE_16x32, 10, -24
    subsprite OAM_SIZE_32x8, -22, 8
  Subsprite_1270:
    subsprite OAM_SIZE_32x32, -22, -32
    subsprite OAM_SIZE_32x16, -22, 0
    subsprite OAM_SIZE_8x32, 10, -32
    subsprite OAM_SIZE_8x16, 10, 0
  Subsprite_1274:
    subsprite OAM_SIZE_32x64, -22, -40
    subsprite OAM_SIZE_8x32, 10, -40
    subsprite OAM_SIZE_8x32, 10, -8
  Subsprite_1277:
    subsprite OAM_SIZE_32x64, -22, -40
    subsprite OAM_SIZE_8x32, 10, -40
    subsprite OAM_SIZE_8x32, 10, -8
  Subsprite_1280:
    subsprite OAM_SIZE_32x64, -22, -40
    subsprite OAM_SIZE_8x32, 10, -40
    subsprite OAM_SIZE_8x32, 10, -8
  Subsprite_1283:
    subsprite OAM_SIZE_32x64, -22, -40
    subsprite OAM_SIZE_16x32, 10, -40
    subsprite OAM_SIZE_16x32, 10, -8
  Subsprite_1286:
    subsprite OAM_SIZE_32x64, -22, -40
    subsprite OAM_SIZE_8x32, 10, -40
    subsprite OAM_SIZE_8x32, 10, -8
  Subsprite_1289:
    subsprite OAM_SIZE_32x32, -22, -32
    subsprite OAM_SIZE_32x16, -22, 0
    subsprite OAM_SIZE_8x32, 10, -32
    subsprite OAM_SIZE_8x16, 10, 0
  Subsprite_1293:
    subsprite OAM_SIZE_32x32, -22, -16
    subsprite OAM_SIZE_8x32, 10, -16
  Subsprite_1295:
    subsprite OAM_SIZE_32x32, -22, -16
    subsprite OAM_SIZE_8x32, 10, -16
  Subsprite_1297:
    subsprite OAM_SIZE_32x32, -22, -16
    subsprite OAM_SIZE_8x32, 10, -16
  Subsprite_1299:
    subsprite OAM_SIZE_16x32, -3, -13
    subsprite OAM_SIZE_8x16, -3, -29
    subsprite OAM_SIZE_8x16, -11, -5
  Subsprite_1302:
    subsprite OAM_SIZE_32x32, -24, -24
    subsprite OAM_SIZE_32x16, -24, 8
    subsprite OAM_SIZE_16x32, 8, -24
    subsprite OAM_SIZE_16x16, 8, 8
  Subsprite_1306:
    subsprite OAM_SIZE_32x32, -16, -24
    subsprite OAM_SIZE_32x16, -16, 8
    subsprite OAM_SIZE_8x32, 16, -24
  Subsprite_1309:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1310:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1311:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1312:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1313:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1314:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1315:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1316:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1317:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1318:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1319:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1320:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1321:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1322:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1323:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1324:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1325:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1326:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1327:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1328:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1329:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1330:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1331:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1332:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1333:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1334:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1335:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1336:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1337:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1338:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1339:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1340:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1341:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1342:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1343:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1344:
    subsprite OAM_SIZE_32x32, -21, -21
    subsprite OAM_SIZE_32x16, -21, 11
    subsprite OAM_SIZE_16x32, 11, -21
  Subsprite_1347:
    subsprite OAM_SIZE_32x32, -24, -24
    subsprite OAM_SIZE_32x16, -24, 8
    subsprite OAM_SIZE_16x32, 8, -24
    subsprite OAM_SIZE_16x16, 8, 8
  Subsprite_1351:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_1352:
    subsprite OAM_SIZE_16x16, -16, -8
    subsprite OAM_SIZE_8x8, 0, -8
  Subsprite_1354:
    subsprite OAM_SIZE_16x16, -8, -8
    subsprite OAM_SIZE_8x8, -8, -16
  Subsprite_1356:
    subsprite OAM_SIZE_16x16, -8, -8
    subsprite OAM_SIZE_8x8, -8, 8
  Subsprite_1358:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_1359:
    subsprite OAM_SIZE_16x16, -8, -8
    subsprite OAM_SIZE_8x8, 0, -16
    subsprite OAM_SIZE_8x8, -8, 8
  Subsprite_1362:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_1363:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1364:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1365:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1366:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1367:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1368:
    subsprite OAM_SIZE_8x16, -16, 0
  Subsprite_1369:
    subsprite OAM_SIZE_16x16, -16, 0
  Subsprite_1370:
    subsprite OAM_SIZE_16x16, -16, 0
    subsprite OAM_SIZE_8x16, 0, -8
  Subsprite_1372:
    subsprite OAM_SIZE_16x16, -8, -16
    subsprite OAM_SIZE_16x8, -8, 0
    subsprite OAM_SIZE_8x8, 8, 0
  Subsprite_1375:
    subsprite OAM_SIZE_16x16, -8, -16
    subsprite OAM_SIZE_16x8, -8, 0
    subsprite OAM_SIZE_8x16, 8, -16
    subsprite OAM_SIZE_8x8, 8, 0
  Subsprite_1379:
    subsprite OAM_SIZE_16x32, -8, -16
    subsprite OAM_SIZE_8x32, 8, -16
  Subsprite_1381:
    subsprite OAM_SIZE_16x8, 0, -16
    subsprite OAM_SIZE_8x8, 0, -8
    subsprite OAM_SIZE_8x8, 8, 0
  Subsprite_1384:
    subsprite OAM_SIZE_16x8, -8, 0
  Subsprite_1385:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1386:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1387:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1388:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1389:
    subsprite OAM_SIZE_16x8, -8, -8
  Subsprite_1390:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_1391:
    subsprite OAM_SIZE_32x16, -16, -8
    subsprite OAM_SIZE_32x8, -16, 8
    subsprite OAM_SIZE_16x8, -8, -16
  Subsprite_1394:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_1395:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_1396:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_1397:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_1398:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_1399:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_1400:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_1401:
    subsprite OAM_SIZE_32x16, -16, -8
    subsprite OAM_SIZE_16x8, -8, -16
    subsprite OAM_SIZE_16x8, -8, 8
  Subsprite_1404:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_1405:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_1406:
    subsprite OAM_SIZE_32x16, -16, -16
    subsprite OAM_SIZE_32x8, -16, 0
    subsprite OAM_SIZE_16x8, -8, 8
  Subsprite_1409:
    subsprite OAM_SIZE_32x16, -16, -16
    subsprite OAM_SIZE_32x8, -16, 0
    subsprite OAM_SIZE_16x8, -8, 8
  Subsprite_1412:
    subsprite OAM_SIZE_32x16, -16, -16
    subsprite OAM_SIZE_32x8, -16, 0
    subsprite OAM_SIZE_16x8, -8, 8
  Subsprite_1415:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_1416:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_1417:
    subsprite OAM_SIZE_32x16, -16, -8
    subsprite OAM_SIZE_16x8, -8, -16
    subsprite OAM_SIZE_16x8, -8, 8
  Subsprite_1420:
    subsprite OAM_SIZE_32x16, -16, -8
    subsprite OAM_SIZE_16x8, -8, -16
    subsprite OAM_SIZE_16x8, -8, 8
  Subsprite_1423:
    subsprite OAM_SIZE_16x32, -8, -16
  Subsprite_1424:
    subsprite OAM_SIZE_8x32, -8, -16
    subsprite OAM_SIZE_8x16, 0, -16
    subsprite OAM_SIZE_8x8, 0, 0
  Subsprite_1427:
    subsprite OAM_SIZE_16x32, -8, -16
  Subsprite_1428:
    subsprite OAM_SIZE_16x32, -8, -16
  Subsprite_1429:
    subsprite OAM_SIZE_16x16, -8, -8
    subsprite OAM_SIZE_8x8, 0, -16
    subsprite OAM_SIZE_8x8, -8, 8
  Subsprite_1432:
    subsprite OAM_SIZE_16x32, -16, -16
    subsprite OAM_SIZE_8x32, 0, -16
  Subsprite_1434:
    subsprite OAM_SIZE_16x16, -8, -8
    subsprite OAM_SIZE_8x8, -16, 0
    subsprite OAM_SIZE_8x8, -8, 8
  Subsprite_1437:
    subsprite OAM_SIZE_16x16, -8, -8
    subsprite OAM_SIZE_8x8, -16, -8
    subsprite OAM_SIZE_8x8, 8, 0
  Subsprite_1440:
    subsprite OAM_SIZE_32x16, -16, -16
    subsprite OAM_SIZE_32x8, -16, 0
  Subsprite_1442:
    subsprite OAM_SIZE_16x16, -8, -8
    subsprite OAM_SIZE_8x8, -8, -16
    subsprite OAM_SIZE_8x8, -16, -8
  Subsprite_1445:
    subsprite OAM_SIZE_16x16, -16, -8
    subsprite OAM_SIZE_16x8, -16, 8
    subsprite OAM_SIZE_8x16, 0, 0
  Subsprite_1448:
    subsprite OAM_SIZE_32x16, -16, 0
    subsprite OAM_SIZE_16x16, -16, -16
    subsprite OAM_SIZE_8x8, 0, -8
  Subsprite_1451:
    subsprite OAM_SIZE_32x16, -16, -8
    subsprite OAM_SIZE_32x8, -16, 8
    subsprite OAM_SIZE_16x8, -16, -16
  Subsprite_1454:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_1455:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_1456:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_1457:
    subsprite OAM_SIZE_16x32, 0, -16
    subsprite OAM_SIZE_16x8, -16, -16
    subsprite OAM_SIZE_8x8, -8, -8
  Subsprite_1460:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_1461:
    subsprite OAM_SIZE_32x8, -16, -16
    subsprite OAM_SIZE_8x16, 8, -8
    subsprite OAM_SIZE_8x8, 8, 8
  Subsprite_1464:
    subsprite OAM_SIZE_16x8, 0, -16
    subsprite OAM_SIZE_8x16, 8, -8
    subsprite OAM_SIZE_8x8, -16, -16
  Subsprite_1467:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_1468:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_1469:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_1470:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1471:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_1472:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_1473:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_1474:
    subsprite OAM_SIZE_16x32, -16, -16
    subsprite OAM_SIZE_8x32, 0, -16
  Subsprite_1476:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_1477:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_1478:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_1479:
    subsprite OAM_SIZE_32x16, -16, -16
    subsprite OAM_SIZE_32x8, -16, 0
  Subsprite_1481:
    subsprite OAM_SIZE_16x16, -8, -8
    subsprite OAM_SIZE_8x8, -16, 0
  Subsprite_1483:
    subsprite OAM_SIZE_16x16, -8, -8
    subsprite OAM_SIZE_8x8, -8, 8
  Subsprite_1485:
    subsprite OAM_SIZE_16x16, -8, -8
    subsprite OAM_SIZE_8x8, -8, -16
  Subsprite_1487:
    subsprite OAM_SIZE_16x16, -8, -8
    subsprite OAM_SIZE_8x8, -16, -8
  Subsprite_1489:
    subsprite OAM_SIZE_32x16, -16, -8
    subsprite OAM_SIZE_16x8, -8, -16
    subsprite OAM_SIZE_16x8, -8, 8
  Subsprite_1492:
    subsprite OAM_SIZE_16x16, -16, -8
    subsprite OAM_SIZE_8x16, 0, -8
  Subsprite_1494:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1495:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_1496:
    subsprite OAM_SIZE_32x16, -16, -16
    subsprite OAM_SIZE_32x8, -16, 0
  Subsprite_1498:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_1499:
    subsprite OAM_SIZE_8x16, 0, 0
  Subsprite_1500:
    subsprite OAM_SIZE_32x16, -16, 8
    subsprite OAM_SIZE_16x8, -8, 0
    subsprite OAM_SIZE_16x8, -8, 24
  Subsprite_1503:
    subsprite OAM_SIZE_32x16, -16, 8
    subsprite OAM_SIZE_16x8, -8, 0
    subsprite OAM_SIZE_16x8, -8, 24
  Subsprite_1506:
    subsprite OAM_SIZE_32x16, -16, 8
    subsprite OAM_SIZE_16x8, -8, 0
    subsprite OAM_SIZE_16x8, -8, 24
  Subsprite_1509:
    subsprite OAM_SIZE_32x16, -16, 8
    subsprite OAM_SIZE_16x8, -8, 0
    subsprite OAM_SIZE_16x8, -8, 24
  Subsprite_1512:
    subsprite OAM_SIZE_32x16, -16, 8
    subsprite OAM_SIZE_16x8, -8, 0
    subsprite OAM_SIZE_16x8, -8, 24
  Subsprite_1515:
    subsprite OAM_SIZE_32x16, -16, 8
    subsprite OAM_SIZE_16x8, -8, 0
    subsprite OAM_SIZE_16x8, -8, 24
  Subsprite_1518:
    subsprite OAM_SIZE_32x16, -16, 8
    subsprite OAM_SIZE_16x8, -8, 0
    subsprite OAM_SIZE_16x8, -8, 24
  Subsprite_1521:
    subsprite OAM_SIZE_32x16, -16, 8
    subsprite OAM_SIZE_16x8, -8, 0
    subsprite OAM_SIZE_16x8, -8, 24
  Subsprite_1524:
    subsprite OAM_SIZE_32x16, -16, 8
    subsprite OAM_SIZE_16x8, -8, 0
    subsprite OAM_SIZE_16x8, -8, 24
  Subsprite_1527:
    subsprite OAM_SIZE_32x16, -16, 8
    subsprite OAM_SIZE_16x8, -8, 0
    subsprite OAM_SIZE_16x8, -8, 24
  Subsprite_1530:
    subsprite OAM_SIZE_32x16, -16, 8
    subsprite OAM_SIZE_16x8, -8, 0
    subsprite OAM_SIZE_16x8, -8, 24
  Subsprite_1533:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_1534:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_1535:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_1536:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_1537:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_1538:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_1539:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_1540:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_1541:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_1542:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_1543:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_1544:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_1545:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_1546:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_1547:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_1548:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_1549:
    subsprite OAM_SIZE_16x16, -8, -19
    subsprite OAM_SIZE_16x8, -8, -3
  Subsprite_1551:
    subsprite OAM_SIZE_16x16, -8, -19
    subsprite OAM_SIZE_16x8, -8, -3
  Subsprite_1553:
    subsprite OAM_SIZE_16x32, -8, -19
  Subsprite_1554:
    subsprite OAM_SIZE_16x16, -8, -19
    subsprite OAM_SIZE_8x8, -8, -3
  Subsprite_1556:
    subsprite OAM_SIZE_16x16, -8, -19
    subsprite OAM_SIZE_16x8, -8, -3
  Subsprite_1558:
    subsprite OAM_SIZE_8x32, -8, -19
    subsprite OAM_SIZE_8x16, 0, -19
    subsprite OAM_SIZE_8x8, 0, -3
  Subsprite_1561:
    subsprite OAM_SIZE_16x16, -8, -19
    subsprite OAM_SIZE_8x8, -8, -3
  Subsprite_1563:
    subsprite OAM_SIZE_16x16, -8, -19
    subsprite OAM_SIZE_8x8, -8, -3
  Subsprite_1565:
    subsprite OAM_SIZE_16x16, -8, -19
    subsprite OAM_SIZE_8x8, -8, -3
  Subsprite_1567:
    subsprite OAM_SIZE_16x16, -8, -19
    subsprite OAM_SIZE_8x8, -8, -3
  Subsprite_1569:
    subsprite OAM_SIZE_16x16, -8, -19
    subsprite OAM_SIZE_8x8, -8, -3
  Subsprite_1571:
    subsprite OAM_SIZE_16x16, -8, -19
    subsprite OAM_SIZE_8x8, -8, -3
  Subsprite_1573:
    subsprite OAM_SIZE_16x16, -8, -19
    subsprite OAM_SIZE_16x8, -8, -3
  Subsprite_1575:
    subsprite OAM_SIZE_16x16, -8, -19
    subsprite OAM_SIZE_16x8, -8, -3
  Subsprite_1577:
    subsprite OAM_SIZE_16x16, -8, -19
    subsprite OAM_SIZE_16x8, -8, -3
  Subsprite_1579:
    subsprite OAM_SIZE_16x16, -8, -19
  Subsprite_1580:
    subsprite OAM_SIZE_16x16, -8, -19
  Subsprite_1581:
    subsprite OAM_SIZE_16x16, -8, -19
    subsprite OAM_SIZE_16x8, -8, -3
  Subsprite_1583:
    subsprite OAM_SIZE_16x16, -8, -19
    subsprite OAM_SIZE_16x8, -8, -3
  Subsprite_1585:
    subsprite OAM_SIZE_16x16, -8, -19
    subsprite OAM_SIZE_16x8, -8, -3
  Subsprite_1587:
    subsprite OAM_SIZE_16x16, -8, -19
    subsprite OAM_SIZE_16x8, -8, -3
  Subsprite_1589:
    subsprite OAM_SIZE_16x16, -8, -19
    subsprite OAM_SIZE_16x8, -8, -3
  Subsprite_1591:
    subsprite OAM_SIZE_16x16, -8, -19
    subsprite OAM_SIZE_16x8, -8, -3
  Subsprite_1593:
    subsprite OAM_SIZE_16x16, -8, -19
    subsprite OAM_SIZE_16x8, -8, -3
  Subsprite_1595:
    subsprite OAM_SIZE_16x16, -8, -19
    subsprite OAM_SIZE_16x8, -8, -3
  Subsprite_1597:
    subsprite OAM_SIZE_16x16, -8, -19
    subsprite OAM_SIZE_16x8, -8, -3
  Subsprite_1599:
    subsprite OAM_SIZE_16x16, -8, -19
    subsprite OAM_SIZE_16x8, -8, -3
  Subsprite_1601:
    subsprite OAM_SIZE_16x16, -8, -19
    subsprite OAM_SIZE_16x8, -8, -3
  Subsprite_1603:
    subsprite OAM_SIZE_16x16, -8, -19
    subsprite OAM_SIZE_16x8, -8, -3
  Subsprite_1605:
    subsprite OAM_SIZE_16x16, -8, -19
    subsprite OAM_SIZE_16x8, -8, -3
  Subsprite_1607:
    subsprite OAM_SIZE_16x16, -8, -19
    subsprite OAM_SIZE_16x8, -8, -3
  Subsprite_1609:
    subsprite OAM_SIZE_16x16, -8, -19
    subsprite OAM_SIZE_16x8, -8, -3
  Subsprite_1611:
    subsprite OAM_SIZE_16x16, -8, -19
    subsprite OAM_SIZE_16x8, -8, -3
  Subsprite_1613:
    subsprite OAM_SIZE_16x16, -8, -19
    subsprite OAM_SIZE_16x8, -8, -3
  Subsprite_1615:
    subsprite OAM_SIZE_16x16, -8, -19
    subsprite OAM_SIZE_16x8, -8, -3
  Subsprite_1617:
    subsprite OAM_SIZE_16x16, -8, -19
    subsprite OAM_SIZE_16x8, -8, -3
  Subsprite_1619:
    subsprite OAM_SIZE_16x16, -8, -19
    subsprite OAM_SIZE_16x8, -8, -3
  Subsprite_1621:
    subsprite OAM_SIZE_16x16, -8, -19
    subsprite OAM_SIZE_16x8, -8, -3
  Subsprite_1623:
    subsprite OAM_SIZE_16x16, -8, -19
    subsprite OAM_SIZE_16x8, -8, -3
    subsprite OAM_SIZE_8x16, 8, -19
  Subsprite_1626:
    subsprite OAM_SIZE_32x8, -16, -3
    subsprite OAM_SIZE_16x8, -8, -11
    subsprite OAM_SIZE_8x8, 8, -11
  Subsprite_1629:
    subsprite OAM_SIZE_32x8, -16, -3
    subsprite OAM_SIZE_16x8, -8, -11
    subsprite OAM_SIZE_8x8, 8, -11
  Subsprite_1632:
    subsprite OAM_SIZE_16x16, -8, -19
    subsprite OAM_SIZE_16x8, -8, -3
  Subsprite_1634:
    subsprite OAM_SIZE_32x16, -16, -11
    subsprite OAM_SIZE_32x8, -16, 5
  Subsprite_1636:
    subsprite OAM_SIZE_32x8, -16, -11
    subsprite OAM_SIZE_16x16, -8, -3
    subsprite OAM_SIZE_8x8, -16, -3
  Subsprite_1639:
    subsprite OAM_SIZE_16x16, -16, -11
    subsprite OAM_SIZE_16x8, -16, 5
    subsprite OAM_SIZE_8x16, 0, -11
    subsprite OAM_SIZE_8x8, 0, 5
  Subsprite_1643:
    subsprite OAM_SIZE_16x16, -8, -19
    subsprite OAM_SIZE_16x8, -8, -3
  Subsprite_1645:
    subsprite OAM_SIZE_16x16, -8, -19
    subsprite OAM_SIZE_16x8, -8, -3
  Subsprite_1647:
    subsprite OAM_SIZE_16x16, -16, -11
    subsprite OAM_SIZE_16x8, 0, 5
    subsprite OAM_SIZE_8x16, 0, -11
  Subsprite_1650:
    subsprite OAM_SIZE_16x32, -16, -19
    subsprite OAM_SIZE_8x32, 0, -19
  Subsprite_1652:
    subsprite OAM_SIZE_32x16, -16, -11
    subsprite OAM_SIZE_32x8, -16, 5
  Subsprite_1654:
    subsprite OAM_SIZE_16x16, -8, -19
    subsprite OAM_SIZE_16x8, -8, -3
  Subsprite_1656:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_1657:
    subsprite OAM_SIZE_8x8, -4, -4
  Subsprite_1658:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_1661:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_1664:
    subsprite OAM_SIZE_32x32, -24, -24
    subsprite OAM_SIZE_32x16, -24, 8
    subsprite OAM_SIZE_16x32, 8, -24
    subsprite OAM_SIZE_16x16, 8, 8
  Subsprite_1668:
    subsprite OAM_SIZE_32x32, -24, 0
    subsprite OAM_SIZE_32x8, -24, 32
    subsprite OAM_SIZE_8x32, 8, 0
  Subsprite_1671:
    subsprite OAM_SIZE_32x32, -24, 0
    subsprite OAM_SIZE_32x8, -24, 32
    subsprite OAM_SIZE_8x32, 8, 0
  Subsprite_1674:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1675:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1676:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1677:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1678:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1679:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_1680:
    subsprite OAM_SIZE_32x16, -16, 0
    subsprite OAM_SIZE_16x8, -16, -8
    subsprite OAM_SIZE_8x8, 0, -8
  Subsprite_1683:
    subsprite OAM_SIZE_16x32, -16, -16
    subsprite OAM_SIZE_8x32, 0, -16
  Subsprite_1685:
    subsprite OAM_SIZE_16x32, -16, -16
    subsprite OAM_SIZE_8x16, 0, -16
    subsprite OAM_SIZE_8x8, 0, 0
  Subsprite_1688:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_1691:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_1694:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_1697:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_1700:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_1703:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_1706:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_1709:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_1712:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_1715:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_1718:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_1721:
    subsprite OAM_SIZE_16x32, -24, 0
    subsprite OAM_SIZE_16x32, -24, 32
    subsprite OAM_SIZE_8x32, -8, 0
    subsprite OAM_SIZE_8x32, -8, 32
  Subsprite_1725:
    subsprite OAM_SIZE_32x64, -11, -32
  Subsprite_1726:
    subsprite OAM_SIZE_32x64, -11, -32
  Subsprite_1727:
    subsprite OAM_SIZE_16x32, -7, -18
  Subsprite_1728:
    subsprite OAM_SIZE_8x32, -7, -18
    subsprite OAM_SIZE_8x16, 1, -18
  Subsprite_1730:
    subsprite OAM_SIZE_16x32, -7, -18
  Subsprite_1731:
    subsprite OAM_SIZE_16x32, -7, -18
  Subsprite_1732:
    subsprite OAM_SIZE_16x32, -8, -34
    subsprite OAM_SIZE_16x8, -8, -2
    subsprite OAM_SIZE_8x8, 8, -18
  Subsprite_1735:
    subsprite OAM_SIZE_32x32, -16, -34
    subsprite OAM_SIZE_32x8, -16, -2
  Subsprite_1737:
    subsprite OAM_SIZE_16x32, -8, -34
    subsprite OAM_SIZE_16x8, -8, -2
    subsprite OAM_SIZE_8x8, 8, -18
  Subsprite_1740:
    subsprite OAM_SIZE_32x32, -16, -34
    subsprite OAM_SIZE_32x8, -16, -2
  Subsprite_1742:
    subsprite OAM_SIZE_16x32, -8, -34
    subsprite OAM_SIZE_16x8, -8, -2
    subsprite OAM_SIZE_8x16, 8, -18
  Subsprite_1745:
    subsprite OAM_SIZE_16x32, -8, -34
    subsprite OAM_SIZE_8x32, 8, -34
    subsprite OAM_SIZE_16x8, -8, -2
  Subsprite_1748:
    subsprite OAM_SIZE_32x32, -16, -34
    subsprite OAM_SIZE_32x8, -16, -2
  Subsprite_1750:
    subsprite OAM_SIZE_16x32, -8, -34
    subsprite OAM_SIZE_16x8, -8, -2
    subsprite OAM_SIZE_8x8, 8, -18
  Subsprite_1753:
    subsprite OAM_SIZE_16x32, -8, -34
    subsprite OAM_SIZE_16x8, -8, -2
    subsprite OAM_SIZE_8x16, 8, -18
  Subsprite_1756:
    subsprite OAM_SIZE_32x32, -16, -34
    subsprite OAM_SIZE_32x8, -16, -2
  Subsprite_1758:
    subsprite OAM_SIZE_32x32, -16, -34
    subsprite OAM_SIZE_32x8, -16, -2
  Subsprite_1760:
    subsprite OAM_SIZE_16x32, -8, -34
    subsprite OAM_SIZE_16x8, -8, -2
    subsprite OAM_SIZE_8x8, 8, -18
  Subsprite_1763:
    subsprite OAM_SIZE_16x32, -8, -34
    subsprite OAM_SIZE_8x32, 8, -34
    subsprite OAM_SIZE_16x8, -8, -2
  Subsprite_1766:
    subsprite OAM_SIZE_16x32, -8, -34
    subsprite OAM_SIZE_16x8, -8, -2
    subsprite OAM_SIZE_8x16, 8, -18
  Subsprite_1769:
    subsprite OAM_SIZE_16x32, -8, -34
    subsprite OAM_SIZE_16x8, -8, -2
    subsprite OAM_SIZE_8x16, 8, -18
  Subsprite_1772:
    subsprite OAM_SIZE_16x32, -8, -26
    subsprite OAM_SIZE_8x16, 8, -26
    subsprite OAM_SIZE_8x8, 8, -10
  Subsprite_1775:
    subsprite OAM_SIZE_16x32, -8, -26
    subsprite OAM_SIZE_8x32, 8, -26
  Subsprite_1777:
    subsprite OAM_SIZE_32x32, -16, -34
    subsprite OAM_SIZE_32x8, -16, -2
  Subsprite_1779:
    subsprite OAM_SIZE_16x32, -8, -34
    subsprite OAM_SIZE_16x8, -8, -2
    subsprite OAM_SIZE_8x8, 8, -18
  Subsprite_1782:
    subsprite OAM_SIZE_16x32, -8, -34
    subsprite OAM_SIZE_16x8, -8, -2
    subsprite OAM_SIZE_8x16, 8, -18
  Subsprite_1785:
    subsprite OAM_SIZE_16x32, -8, -26
    subsprite OAM_SIZE_8x32, 8, -26
  Subsprite_1787:
    subsprite OAM_SIZE_16x32, -8, -26
    subsprite OAM_SIZE_8x32, 8, -26
  Subsprite_1789:
    subsprite OAM_SIZE_16x32, -8, -34
    subsprite OAM_SIZE_16x8, -8, -2
    subsprite OAM_SIZE_8x16, 8, -18
  Subsprite_1792:
    subsprite OAM_SIZE_16x32, -8, -34
    subsprite OAM_SIZE_16x8, -8, -2
    subsprite OAM_SIZE_8x16, 8, -18
  Subsprite_1795:
    subsprite OAM_SIZE_16x32, -8, -34
    subsprite OAM_SIZE_16x8, -8, -2
    subsprite OAM_SIZE_8x16, 8, -18
  Subsprite_1798:
    subsprite OAM_SIZE_16x32, -8, -34
    subsprite OAM_SIZE_16x8, -8, -2
    subsprite OAM_SIZE_8x16, 8, -18
  Subsprite_1801:
    subsprite OAM_SIZE_16x32, -8, -34
    subsprite OAM_SIZE_16x8, -8, -2
    subsprite OAM_SIZE_8x16, 8, -18
  Subsprite_1804:
    subsprite OAM_SIZE_16x32, -8, -34
    subsprite OAM_SIZE_16x8, -8, -2
    subsprite OAM_SIZE_8x16, 8, -18
  Subsprite_1807:
    subsprite OAM_SIZE_16x32, -8, -34
    subsprite OAM_SIZE_16x8, -8, -2
    subsprite OAM_SIZE_8x16, 8, -18
  Subsprite_1810:
    subsprite OAM_SIZE_16x32, -8, -34
    subsprite OAM_SIZE_16x8, -8, -2
    subsprite OAM_SIZE_8x16, 8, -18
  Subsprite_1813:
    subsprite OAM_SIZE_16x32, -8, -34
    subsprite OAM_SIZE_16x8, -8, -2
    subsprite OAM_SIZE_8x16, 8, -18
  Subsprite_1816:
    subsprite OAM_SIZE_16x32, -8, -34
    subsprite OAM_SIZE_16x8, -8, -2
    subsprite OAM_SIZE_8x16, 8, -18
  Subsprite_1819:
    subsprite OAM_SIZE_16x32, -8, -34
    subsprite OAM_SIZE_16x8, -8, -2
    subsprite OAM_SIZE_8x16, 8, -18
  Subsprite_1822:
    subsprite OAM_SIZE_16x32, -8, -34
    subsprite OAM_SIZE_8x16, 8, -18
    subsprite OAM_SIZE_8x8, -8, -2
  Subsprite_1825:
    subsprite OAM_SIZE_16x32, -8, -34
    subsprite OAM_SIZE_16x8, -8, -2
    subsprite OAM_SIZE_8x8, 8, -18
  Subsprite_1828:
    subsprite OAM_SIZE_16x32, -8, -34
    subsprite OAM_SIZE_16x8, -8, -2
    subsprite OAM_SIZE_8x16, 8, -18
  Subsprite_1831:
    subsprite OAM_SIZE_16x32, -8, -34
    subsprite OAM_SIZE_16x8, -8, -2
    subsprite OAM_SIZE_8x16, 8, -18
  Subsprite_1834:
    subsprite OAM_SIZE_16x32, -8, -34
    subsprite OAM_SIZE_8x16, 8, -18
    subsprite OAM_SIZE_8x8, -8, -2
  Subsprite_1837:
    subsprite OAM_SIZE_16x32, -8, -34
    subsprite OAM_SIZE_16x8, -8, -2
    subsprite OAM_SIZE_8x8, 8, -18
  Subsprite_1840:
    subsprite OAM_SIZE_16x32, -8, -34
    subsprite OAM_SIZE_16x8, -8, -2
    subsprite OAM_SIZE_8x16, 8, -18
  Subsprite_1843:
    subsprite OAM_SIZE_16x32, -8, -34
    subsprite OAM_SIZE_8x8, 8, -18
    subsprite OAM_SIZE_8x8, 0, -2
  Subsprite_1846:
    subsprite OAM_SIZE_32x32, -16, -34
    subsprite OAM_SIZE_32x8, -16, -2
  Subsprite_1848:
    subsprite OAM_SIZE_16x32, -8, -34
    subsprite OAM_SIZE_16x8, -8, -2
    subsprite OAM_SIZE_8x16, 8, -18
  Subsprite_1851:
    subsprite OAM_SIZE_16x32, -8, -34
    subsprite OAM_SIZE_16x8, -8, -2
    subsprite OAM_SIZE_8x8, -16, -34
  Subsprite_1854:
    subsprite OAM_SIZE_16x32, -8, -34
    subsprite OAM_SIZE_16x8, -8, -2
    subsprite OAM_SIZE_8x8, 8, -18
  Subsprite_1857:
    subsprite OAM_SIZE_16x32, -8, -34
    subsprite OAM_SIZE_16x8, -8, -2
    subsprite OAM_SIZE_8x16, 8, -18
  Subsprite_1860:
    subsprite OAM_SIZE_32x16, -16, -18
    subsprite OAM_SIZE_16x16, -8, -34
    subsprite OAM_SIZE_16x8, -8, -2
  Subsprite_1863:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_1866:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_1869:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_1872:
    subsprite OAM_SIZE_32x64, -24, -46
    subsprite OAM_SIZE_16x32, 8, -46
    subsprite OAM_SIZE_16x32, 8, -14
  Subsprite_1875:
    subsprite OAM_SIZE_32x64, -24, -46
    subsprite OAM_SIZE_16x32, 8, -46
    subsprite OAM_SIZE_16x32, 8, -14
  Subsprite_1878:
    subsprite OAM_SIZE_32x64, -24, -46
    subsprite OAM_SIZE_16x32, 8, -46
    subsprite OAM_SIZE_16x32, 8, -14
  Subsprite_1881:
    subsprite OAM_SIZE_32x64, -24, -46
    subsprite OAM_SIZE_16x32, 8, -46
    subsprite OAM_SIZE_16x32, 8, -14
  Subsprite_1884:
    subsprite OAM_SIZE_32x64, -24, -46
    subsprite OAM_SIZE_16x32, 8, -46
    subsprite OAM_SIZE_16x32, 8, -14
  Subsprite_1887:
    subsprite OAM_SIZE_32x64, -24, -46
    subsprite OAM_SIZE_16x32, 8, -46
    subsprite OAM_SIZE_16x32, 8, -14
  Subsprite_1890:
    subsprite OAM_SIZE_32x64, -24, -46
    subsprite OAM_SIZE_16x32, 8, -46
    subsprite OAM_SIZE_16x32, 8, -14
  Subsprite_1893:
    subsprite OAM_SIZE_32x64, -24, -46
    subsprite OAM_SIZE_16x32, 8, -46
    subsprite OAM_SIZE_16x32, 8, -14
  Subsprite_1896:
    subsprite OAM_SIZE_32x64, -24, -46
    subsprite OAM_SIZE_16x32, 8, -46
    subsprite OAM_SIZE_16x32, 8, -14
  Subsprite_1899:
    subsprite OAM_SIZE_32x64, -24, -46
    subsprite OAM_SIZE_16x32, 8, -46
    subsprite OAM_SIZE_16x32, 8, -14
  Subsprite_1902:
    subsprite OAM_SIZE_32x64, -24, -46
    subsprite OAM_SIZE_16x32, 8, -46
    subsprite OAM_SIZE_16x32, 8, -14
  Subsprite_1905:
    subsprite OAM_SIZE_32x64, -24, -46
    subsprite OAM_SIZE_16x32, 8, -46
    subsprite OAM_SIZE_16x32, 8, -14
  Subsprite_1908:
    subsprite OAM_SIZE_32x32, -16, 0
    subsprite OAM_SIZE_32x8, -16, 32
    subsprite OAM_SIZE_8x32, 16, 0
  Subsprite_1911:
    subsprite OAM_SIZE_32x32, -16, 0
    subsprite OAM_SIZE_32x8, -16, 32
    subsprite OAM_SIZE_8x32, 16, 0
  Subsprite_1914:
    subsprite OAM_SIZE_32x64, -16, -48
  Subsprite_1915:
    subsprite OAM_SIZE_32x32, -24, -32
    subsprite OAM_SIZE_32x8, -24, 0
    subsprite OAM_SIZE_8x32, 8, -32
  Subsprite_1918:
    subsprite OAM_SIZE_32x32, -24, -32
    subsprite OAM_SIZE_32x16, -24, 0
    subsprite OAM_SIZE_8x32, 8, -32
    subsprite OAM_SIZE_8x16, 8, 0
  Subsprite_1922:
    subsprite OAM_SIZE_32x32, -24, -32
    subsprite OAM_SIZE_32x16, -24, 0
    subsprite OAM_SIZE_8x32, 8, -32
    subsprite OAM_SIZE_8x16, 8, 0
  Subsprite_1926:
    subsprite OAM_SIZE_32x64, -20, -40
    subsprite OAM_SIZE_8x32, 12, -40
    subsprite OAM_SIZE_8x32, 12, -8
  Subsprite_1929:
    subsprite OAM_SIZE_32x64, -20, -40
    subsprite OAM_SIZE_8x32, 12, -40
    subsprite OAM_SIZE_8x32, 12, -8
  Subsprite_1932:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1933:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1934:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1935:
    subsprite OAM_SIZE_8x16, -8, -8
  Subsprite_1936:
    subsprite OAM_SIZE_8x16, -8, -8
  Subsprite_1937:
    subsprite OAM_SIZE_8x16, -8, -8
  Subsprite_1938:
    subsprite OAM_SIZE_8x16, -8, -8
  Subsprite_1939:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1940:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_1941:
    subsprite OAM_SIZE_32x32, -16, -29
    subsprite OAM_SIZE_32x8, -16, 3
    subsprite OAM_SIZE_16x8, -8, -37
  Subsprite_1944:
    subsprite OAM_SIZE_32x32, -24, -24
    subsprite OAM_SIZE_32x16, -24, 8
    subsprite OAM_SIZE_16x32, 8, -24
    subsprite OAM_SIZE_16x16, 8, 8
  Subsprite_1948:
    subsprite OAM_SIZE_32x32, -24, -24
    subsprite OAM_SIZE_32x16, -24, 8
    subsprite OAM_SIZE_16x32, 8, -24
    subsprite OAM_SIZE_16x16, 8, 8
  Subsprite_1952:
    subsprite OAM_SIZE_8x8, 0, 0
  Subsprite_1953:
    subsprite OAM_SIZE_8x8, 0, 0
  Subsprite_1954:
    subsprite OAM_SIZE_8x8, 0, 0
  Subsprite_1955:
    subsprite OAM_SIZE_8x8, 0, 0
  Subsprite_1956:
    subsprite OAM_SIZE_8x8, 0, 0
  Subsprite_1957:
    subsprite OAM_SIZE_8x8, 0, 0
  Subsprite_1958:
    subsprite OAM_SIZE_8x8, 0, 0
  Subsprite_1959:
    subsprite OAM_SIZE_8x8, 0, 0
  Subsprite_1960:
    subsprite OAM_SIZE_8x8, 0, 0
  Subsprite_1961:
    subsprite OAM_SIZE_8x8, 0, 0
  Subsprite_1962:
    subsprite OAM_SIZE_8x8, 0, 0
  Subsprite_1963:
    subsprite OAM_SIZE_16x16, -8, -8
    subsprite OAM_SIZE_8x8, -16, -8
    subsprite OAM_SIZE_8x8, 0, 8
  Subsprite_1966:
    subsprite OAM_SIZE_16x16, -8, -8
    subsprite OAM_SIZE_8x8, 0, 8
  Subsprite_1968:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_1969:
    subsprite OAM_SIZE_16x16, -8, -8
    subsprite OAM_SIZE_8x8, -8, -16
  Subsprite_1971:
    subsprite OAM_SIZE_32x16, -16, -8
    subsprite OAM_SIZE_32x8, -16, 8
  Subsprite_1973:
    subsprite OAM_SIZE_8x32, -8, -16
    subsprite OAM_SIZE_8x16, 0, -8
  Subsprite_1975:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_1976:
    subsprite OAM_SIZE_16x16, -8, -8
    subsprite OAM_SIZE_8x8, 0, -16
  Subsprite_1978:
    subsprite OAM_SIZE_16x16, -8, -8
    subsprite OAM_SIZE_8x8, -16, -8
    subsprite OAM_SIZE_8x8, 0, 8
  Subsprite_1981:
    subsprite OAM_SIZE_16x16, -8, -8
    subsprite OAM_SIZE_8x8, 0, 8
  Subsprite_1983:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_1984:
    subsprite OAM_SIZE_16x16, -8, -8
    subsprite OAM_SIZE_8x8, -8, -16
  Subsprite_1986:
    subsprite OAM_SIZE_32x16, -16, -8
    subsprite OAM_SIZE_32x8, -16, 8
  Subsprite_1988:
    subsprite OAM_SIZE_16x16, -8, -8
    subsprite OAM_SIZE_8x8, -8, 8
  Subsprite_1990:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_1991:
    subsprite OAM_SIZE_16x16, -8, -8
    subsprite OAM_SIZE_8x8, 0, -16
  Subsprite_1993:
    subsprite OAM_SIZE_32x16, -16, -8
  Subsprite_1994:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_1995:
    subsprite OAM_SIZE_16x32, -8, -16
  Subsprite_1996:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_1997:
    subsprite OAM_SIZE_32x16, -16, -8
  Subsprite_1998:
    subsprite OAM_SIZE_16x16, -16, -8
    subsprite OAM_SIZE_16x8, -8, 8
    subsprite OAM_SIZE_8x16, 0, -8
  Subsprite_2001:
    subsprite OAM_SIZE_16x16, -16, -16
    subsprite OAM_SIZE_16x8, -16, 0
    subsprite OAM_SIZE_8x16, 0, -16
    subsprite OAM_SIZE_8x8, 0, 0
  Subsprite_2005:
    subsprite OAM_SIZE_16x16, -8, -12
  Subsprite_2006:
    subsprite OAM_SIZE_16x16, -8, -12
    subsprite OAM_SIZE_8x8, -8, 4
  Subsprite_2008:
    subsprite OAM_SIZE_16x16, -8, -12
    subsprite OAM_SIZE_16x8, -8, 4
    subsprite OAM_SIZE_8x8, -16, -12
  Subsprite_2011:
    subsprite OAM_SIZE_32x32, -16, -20
  Subsprite_2012:
    subsprite OAM_SIZE_8x32, -8, -20
    subsprite OAM_SIZE_8x16, 0, -20
    subsprite OAM_SIZE_8x8, 0, -4
  Subsprite_2015:
    subsprite OAM_SIZE_16x16, -8, -12
  Subsprite_2016:
    subsprite OAM_SIZE_16x16, -8, -12
    subsprite OAM_SIZE_8x8, -8, -20
  Subsprite_2018:
    subsprite OAM_SIZE_32x16, -16, -12
    subsprite OAM_SIZE_32x8, -16, 4
  Subsprite_2020:
    subsprite OAM_SIZE_32x32, -16, -20
  Subsprite_2021:
    subsprite OAM_SIZE_16x16, -8, -12
    subsprite OAM_SIZE_8x8, 0, -20
  Subsprite_2023:
    subsprite OAM_SIZE_16x16, -8, -12
  Subsprite_2024:
    subsprite OAM_SIZE_16x16, -8, -12
  Subsprite_2025:
    subsprite OAM_SIZE_16x16, -8, -12
  Subsprite_2026:
    subsprite OAM_SIZE_16x16, -8, -12
  Subsprite_2027:
    subsprite OAM_SIZE_16x16, -8, -12
  Subsprite_2028:
    subsprite OAM_SIZE_16x16, -8, -12
  Subsprite_2029:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2032:
    subsprite OAM_SIZE_64x64, -24, -48
  Subsprite_2033:
    subsprite OAM_SIZE_16x16, -8, -32
    subsprite OAM_SIZE_16x8, -8, -16
    subsprite OAM_SIZE_8x16, 8, -24
  Subsprite_2036:
    subsprite OAM_SIZE_16x16, -8, -32
    subsprite OAM_SIZE_16x8, -8, -16
    subsprite OAM_SIZE_8x16, 8, -24
  Subsprite_2039:
    subsprite OAM_SIZE_16x16, -8, -32
    subsprite OAM_SIZE_16x8, -8, -16
    subsprite OAM_SIZE_8x16, 8, -24
  Subsprite_2042:
    subsprite OAM_SIZE_16x16, -8, -32
    subsprite OAM_SIZE_16x8, -8, -16
    subsprite OAM_SIZE_8x16, 8, -24
  Subsprite_2045:
    subsprite OAM_SIZE_16x16, -8, -32
    subsprite OAM_SIZE_16x8, -8, -16
    subsprite OAM_SIZE_8x16, 8, -24
  Subsprite_2048:
    subsprite OAM_SIZE_16x32, -8, -32
    subsprite OAM_SIZE_8x16, 8, -24
  Subsprite_2050:
    subsprite OAM_SIZE_16x32, -8, -32
    subsprite OAM_SIZE_8x16, 8, -24
  Subsprite_2052:
    subsprite OAM_SIZE_16x32, -8, -32
    subsprite OAM_SIZE_8x16, 8, -24
  Subsprite_2054:
    subsprite OAM_SIZE_16x32, -8, -32
    subsprite OAM_SIZE_8x16, 8, -24
  Subsprite_2056:
    subsprite OAM_SIZE_16x32, -8, -32
    subsprite OAM_SIZE_8x16, 8, -24
  Subsprite_2058:
    subsprite OAM_SIZE_32x64, -24, -46
    subsprite OAM_SIZE_16x32, 8, -46
    subsprite OAM_SIZE_16x32, 8, -14
  Subsprite_2061:
    subsprite OAM_SIZE_32x32, -24, -24
    subsprite OAM_SIZE_32x16, -24, 8
    subsprite OAM_SIZE_16x32, 8, -24
    subsprite OAM_SIZE_16x16, 8, 8
  Subsprite_2065:
    subsprite OAM_SIZE_32x32, -24, -24
    subsprite OAM_SIZE_32x16, -24, 8
    subsprite OAM_SIZE_16x32, 8, -24
    subsprite OAM_SIZE_16x16, 8, 8
  Subsprite_2069:
    subsprite OAM_SIZE_64x64, -32, -32
  Subsprite_2070:
    subsprite OAM_SIZE_64x64, -32, -32
  Subsprite_2071:
    subsprite OAM_SIZE_32x16, -16, -8
    subsprite OAM_SIZE_16x8, -8, -16
    subsprite OAM_SIZE_16x8, -8, 8
  Subsprite_2074:
    subsprite OAM_SIZE_32x16, -16, -8
    subsprite OAM_SIZE_16x8, -8, 8
  Subsprite_2076:
    subsprite OAM_SIZE_16x16, -8, -6
  Subsprite_2077:
    subsprite OAM_SIZE_16x16, -8, -6
  Subsprite_2078:
    subsprite OAM_SIZE_16x16, -8, -6
  Subsprite_2079:
    subsprite OAM_SIZE_16x16, -8, -6
  Subsprite_2080:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_2081:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_2082:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_2083:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_2084:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_2085:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_2086:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_2087:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_2088:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_2089:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_2090:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_2091:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_2092:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_2093:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_2094:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_2095:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_2096:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_2097:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_2098:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_2099:
    subsprite OAM_SIZE_8x8, -4, -4
  Subsprite_2100:
    subsprite OAM_SIZE_8x8, -4, -4
  Subsprite_2101:
    subsprite OAM_SIZE_8x8, -4, -4
  Subsprite_2102:
    subsprite OAM_SIZE_8x8, -4, -4
  Subsprite_2103:
    subsprite OAM_SIZE_8x8, -4, -4
  Subsprite_2104:
    subsprite OAM_SIZE_8x8, -4, -4
  Subsprite_2105:
    subsprite OAM_SIZE_8x8, -4, -4
  Subsprite_2106:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2109:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2112:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2115:
    subsprite OAM_SIZE_32x32, -24, -32
    subsprite OAM_SIZE_32x16, -24, 0
    subsprite OAM_SIZE_8x32, 8, -32
    subsprite OAM_SIZE_8x16, 8, 0
  Subsprite_2119:
    subsprite OAM_SIZE_32x32, -16, -32
    subsprite OAM_SIZE_32x16, -16, 0
    subsprite OAM_SIZE_8x32, 16, -32
    subsprite OAM_SIZE_8x16, 16, 0
  Subsprite_2123:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2126:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2129:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2132:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2135:
    subsprite OAM_SIZE_8x8, -24, 8
  Subsprite_2136:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2139:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2142:
    subsprite OAM_SIZE_8x8, 0, -40
    subsprite OAM_SIZE_8x8, 0, -24
  Subsprite_2144:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2147:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2150:
    subsprite OAM_SIZE_32x32, -16, -32
    subsprite OAM_SIZE_32x16, -16, 0
    subsprite OAM_SIZE_8x32, 16, -32
    subsprite OAM_SIZE_8x16, 16, 0
  Subsprite_2154:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2157:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2160:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2163:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2166:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2169:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2172:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2175:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2178:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2181:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2184:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2187:
    subsprite OAM_SIZE_16x32, -8, -31
  Subsprite_2188:
    subsprite OAM_SIZE_16x32, -8, -31
  Subsprite_2189:
    subsprite OAM_SIZE_16x32, -8, -31
  Subsprite_2190:
    subsprite OAM_SIZE_16x32, -8, -31
  Subsprite_2191:
    subsprite OAM_SIZE_32x8, -16, 8
    subsprite OAM_SIZE_16x8, -8, 0
    subsprite OAM_SIZE_16x8, -8, 16
  Subsprite_2194:
    subsprite OAM_SIZE_32x8, -16, 8
    subsprite OAM_SIZE_16x8, -8, 0
    subsprite OAM_SIZE_16x8, -8, 16
  Subsprite_2197:
    subsprite OAM_SIZE_64x64, -24, -40
  Subsprite_2198:
    subsprite OAM_SIZE_16x16, -3, -13
    subsprite OAM_SIZE_16x8, -3, 3
  Subsprite_2200:
    subsprite OAM_SIZE_16x16, -3, -13
    subsprite OAM_SIZE_16x8, -3, 3
  Subsprite_2202:
    subsprite OAM_SIZE_16x16, -3, -13
    subsprite OAM_SIZE_16x8, -3, 3
  Subsprite_2204:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_2205:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_2206:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_2207:
    subsprite OAM_SIZE_32x32, -16, -20
    subsprite OAM_SIZE_16x8, -8, 12
    subsprite OAM_SIZE_8x8, 8, -28
  Subsprite_2210:
    subsprite OAM_SIZE_16x32, -8, -16
    subsprite OAM_SIZE_8x8, -16, 0
    subsprite OAM_SIZE_8x8, 8, 0
  Subsprite_2213:
    subsprite OAM_SIZE_16x32, -8, -16
    subsprite OAM_SIZE_8x8, -16, 0
    subsprite OAM_SIZE_8x8, 8, 0
  Subsprite_2216:
    subsprite OAM_SIZE_16x32, -8, -16
    subsprite OAM_SIZE_8x8, -16, 0
    subsprite OAM_SIZE_8x8, 8, 0
  Subsprite_2219:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_2220:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_2221:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_2222:
    subsprite OAM_SIZE_16x32, -8, -16
    subsprite OAM_SIZE_8x16, -16, -16
    subsprite OAM_SIZE_8x16, 8, -8
  Subsprite_2225:
    subsprite OAM_SIZE_16x32, -8, -16
    subsprite OAM_SIZE_8x16, -16, -16
    subsprite OAM_SIZE_8x16, 8, -8
  Subsprite_2228:
    subsprite OAM_SIZE_16x32, -8, -16
    subsprite OAM_SIZE_8x16, -16, -16
    subsprite OAM_SIZE_8x16, 8, -8
  Subsprite_2231:
    subsprite OAM_SIZE_16x32, -8, -16
    subsprite OAM_SIZE_8x8, -16, -8
    subsprite OAM_SIZE_8x8, 8, -8
  Subsprite_2234:
    subsprite OAM_SIZE_16x32, -8, -16
    subsprite OAM_SIZE_8x16, -16, -16
    subsprite OAM_SIZE_8x8, 8, -8
  Subsprite_2237:
    subsprite OAM_SIZE_16x32, -8, -16
    subsprite OAM_SIZE_8x16, -16, -16
    subsprite OAM_SIZE_8x8, 8, -8
  Subsprite_2240:
    subsprite OAM_SIZE_32x16, -16, -8
    subsprite OAM_SIZE_16x8, -8, -16
    subsprite OAM_SIZE_16x8, -8, 8
  Subsprite_2243:
    subsprite OAM_SIZE_32x16, -16, -8
    subsprite OAM_SIZE_16x8, -8, -16
    subsprite OAM_SIZE_16x8, -8, 8
  Subsprite_2246:
    subsprite OAM_SIZE_32x16, -16, -8
    subsprite OAM_SIZE_16x8, -8, -16
    subsprite OAM_SIZE_16x8, -8, 8
  Subsprite_2249:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_2250:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_2251:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_2252:
    subsprite OAM_SIZE_32x16, -16, -16
    subsprite OAM_SIZE_32x8, -16, 0
    subsprite OAM_SIZE_16x8, -8, 8
  Subsprite_2255:
    subsprite OAM_SIZE_16x32, -8, -16
    subsprite OAM_SIZE_8x16, -16, -8
  Subsprite_2257:
    subsprite OAM_SIZE_16x32, -8, -16
    subsprite OAM_SIZE_8x16, -16, -8
  Subsprite_2259:
    subsprite OAM_SIZE_16x32, -8, -16
    subsprite OAM_SIZE_8x8, -16, -8
  Subsprite_2261:
    subsprite OAM_SIZE_16x16, -8, -16
    subsprite OAM_SIZE_16x8, -8, 0
    subsprite OAM_SIZE_8x8, -16, -8
  Subsprite_2264:
    subsprite OAM_SIZE_16x16, -8, -16
    subsprite OAM_SIZE_8x8, -16, -8
    subsprite OAM_SIZE_8x8, 0, 0
  Subsprite_2267:
    subsprite OAM_SIZE_16x32, -8, -16
    subsprite OAM_SIZE_8x8, -16, -8
  Subsprite_2269:
    subsprite OAM_SIZE_16x32, -8, -16
    subsprite OAM_SIZE_8x8, -16, -8
  Subsprite_2271:
    subsprite OAM_SIZE_16x32, -8, -16
    subsprite OAM_SIZE_8x8, -16, -8
  Subsprite_2273:
    subsprite OAM_SIZE_16x16, -8, -16
    subsprite OAM_SIZE_16x8, -8, 0
    subsprite OAM_SIZE_8x8, -16, -8
  Subsprite_2276:
    subsprite OAM_SIZE_16x16, -8, -16
    subsprite OAM_SIZE_8x8, -16, -8
    subsprite OAM_SIZE_8x8, -8, 0
  Subsprite_2279:
    subsprite OAM_SIZE_8x8, -4, -4
  Subsprite_2280:
    subsprite OAM_SIZE_8x8, -4, -4
  Subsprite_2281:
    subsprite OAM_SIZE_8x8, -4, -4
  Subsprite_2282:
    subsprite OAM_SIZE_8x8, -4, -4
  Subsprite_2283:
    subsprite OAM_SIZE_8x8, -4, -4
  Subsprite_2284:
    subsprite OAM_SIZE_64x32, -27, -30
    subsprite OAM_SIZE_32x16, -27, 2
    subsprite OAM_SIZE_32x16, 5, 2
  Subsprite_2287:
    subsprite OAM_SIZE_32x32, -27, -30
    subsprite OAM_SIZE_32x16, -27, 2
    subsprite OAM_SIZE_16x32, 5, -30
  Subsprite_2290:
    subsprite OAM_SIZE_32x32, -19, -30
    subsprite OAM_SIZE_32x16, -19, 2
    subsprite OAM_SIZE_16x32, 13, -30
    subsprite OAM_SIZE_16x16, 13, 2
  Subsprite_2294:
    subsprite OAM_SIZE_64x64, -27, -30
  Subsprite_2295:
    subsprite OAM_SIZE_16x32, -8, -16
    subsprite OAM_SIZE_8x8, 8, -8
    subsprite OAM_SIZE_8x8, -16, 0
  Subsprite_2298:
    subsprite OAM_SIZE_16x32, -8, -29
    subsprite OAM_SIZE_8x8, -16, -29
  Subsprite_2300:
    subsprite OAM_SIZE_64x64, -32, -32
  Subsprite_2301:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2304:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2307:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2310:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2313:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2316:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2319:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2322:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2325:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2328:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2331:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2334:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2337:
    subsprite OAM_SIZE_64x64, -24, -48
  Subsprite_2338:
    subsprite OAM_SIZE_64x64, -24, -48
  Subsprite_2339:
    subsprite OAM_SIZE_32x32, -16, -16
    subsprite OAM_SIZE_8x8, 0, 16
  Subsprite_2341:
    subsprite OAM_SIZE_32x32, -24, -16
    subsprite OAM_SIZE_32x8, -24, 16
    subsprite OAM_SIZE_8x32, 8, -16
  Subsprite_2344:
    subsprite OAM_SIZE_32x32, -24, 0
    subsprite OAM_SIZE_32x16, -24, 32
    subsprite OAM_SIZE_8x32, 8, 0
  Subsprite_2347:
    subsprite OAM_SIZE_32x32, -24, 0
    subsprite OAM_SIZE_32x16, -24, 32
    subsprite OAM_SIZE_8x32, 8, 0
  Subsprite_2350:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_2351:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_2352:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_2353:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_2354:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_2355:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_2356:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_2357:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_2358:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_2359:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_2360:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_2361:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_2362:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_2363:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_2364:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_2365:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_2366:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2369:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2372:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2375:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2378:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2381:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2384:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2387:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2390:
    subsprite OAM_SIZE_32x32, -24, -48
    subsprite OAM_SIZE_32x16, -24, -16
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x16, 8, -16
  Subsprite_2394:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2397:
    subsprite OAM_SIZE_32x32, -24, -32
    subsprite OAM_SIZE_32x16, -24, 0
    subsprite OAM_SIZE_16x32, 8, -32
    subsprite OAM_SIZE_16x16, 8, 0
  Subsprite_2401:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
  Subsprite_2403:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_8x32, 8, -48
  Subsprite_2405:
    subsprite OAM_SIZE_8x8, 16, 8
  Subsprite_2406:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2409:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
  Subsprite_2411:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_8x32, 8, -48
  Subsprite_2413:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2416:
    subsprite OAM_SIZE_32x16, -16, -8
    subsprite OAM_SIZE_32x8, -16, 8
    subsprite OAM_SIZE_16x8, -8, -16
  Subsprite_2419:
    subsprite OAM_SIZE_32x16, -16, -8
    subsprite OAM_SIZE_32x8, -16, 8
    subsprite OAM_SIZE_16x8, -8, -16
  Subsprite_2422:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_2423:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_2424:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_2425:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_2426:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_2427:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_2428:
    subsprite OAM_SIZE_32x16, -16, -8
    subsprite OAM_SIZE_32x8, -16, 8
    subsprite OAM_SIZE_16x8, -8, -16
  Subsprite_2431:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_2432:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_2433:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_2434:
    subsprite OAM_SIZE_32x16, -16, -16
    subsprite OAM_SIZE_32x8, -16, 0
    subsprite OAM_SIZE_16x8, -8, 8
  Subsprite_2437:
    subsprite OAM_SIZE_32x16, -16, -16
    subsprite OAM_SIZE_32x8, -16, 0
    subsprite OAM_SIZE_16x8, -8, 8
  Subsprite_2440:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_2441:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_2442:
    subsprite OAM_SIZE_32x16, -16, -8
    subsprite OAM_SIZE_16x8, -8, -16
    subsprite OAM_SIZE_16x8, -8, 8
  Subsprite_2445:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_2446:
    subsprite OAM_SIZE_32x16, -16, -8
    subsprite OAM_SIZE_16x8, -8, -16
    subsprite OAM_SIZE_16x8, -8, 8
  Subsprite_2449:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_2450:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_2451:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_2452:
    subsprite OAM_SIZE_32x16, -16, -8
    subsprite OAM_SIZE_16x8, -8, -16
    subsprite OAM_SIZE_16x8, -8, 8
  Subsprite_2455:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_2456:
    subsprite OAM_SIZE_16x16, -8, -16
    subsprite OAM_SIZE_16x8, -8, 0
  Subsprite_2458:
    subsprite OAM_SIZE_16x16, -16, -16
    subsprite OAM_SIZE_16x8, -8, 0
    subsprite OAM_SIZE_8x8, 0, -8
  Subsprite_2461:
    subsprite OAM_SIZE_16x16, -16, -8
    subsprite OAM_SIZE_8x16, 0, -8
  Subsprite_2463:
    subsprite OAM_SIZE_16x16, -16, -8
    subsprite OAM_SIZE_16x8, -16, 8
    subsprite OAM_SIZE_8x16, 0, -8
  Subsprite_2466:
    subsprite OAM_SIZE_16x16, -8, -8
    subsprite OAM_SIZE_16x8, -8, 8
  Subsprite_2468:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_2469:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_2470:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_2471:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_2472:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_2473:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_2474:
    subsprite OAM_SIZE_32x16, -16, -8
    subsprite OAM_SIZE_32x8, -16, 8
    subsprite OAM_SIZE_16x8, -8, -16
  Subsprite_2477:
    subsprite OAM_SIZE_32x16, -16, -8
    subsprite OAM_SIZE_32x8, -16, 8
    subsprite OAM_SIZE_16x8, -8, -16
  Subsprite_2480:
    subsprite OAM_SIZE_32x16, -16, -8
    subsprite OAM_SIZE_32x8, -16, 8
    subsprite OAM_SIZE_16x8, -8, -16
  Subsprite_2483:
    subsprite OAM_SIZE_16x16, -16, -8
    subsprite OAM_SIZE_16x8, -8, 8
    subsprite OAM_SIZE_8x16, 0, -8
  Subsprite_2486:
    subsprite OAM_SIZE_16x16, -16, -8
    subsprite OAM_SIZE_16x8, -8, 8
    subsprite OAM_SIZE_8x16, 0, -8
  Subsprite_2489:
    subsprite OAM_SIZE_16x16, -16, -8
    subsprite OAM_SIZE_16x8, -8, 8
    subsprite OAM_SIZE_8x16, 0, -8
  Subsprite_2492:
    subsprite OAM_SIZE_32x16, -16, -8
    subsprite OAM_SIZE_16x8, -8, -16
    subsprite OAM_SIZE_16x8, -8, 8
  Subsprite_2495:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_2496:
    subsprite OAM_SIZE_32x16, -16, -16
    subsprite OAM_SIZE_32x8, -16, 0
    subsprite OAM_SIZE_16x8, -8, 8
  Subsprite_2499:
    subsprite OAM_SIZE_32x32, -16, -16
    subsprite OAM_SIZE_32x8, -16, 16
    subsprite OAM_SIZE_16x8, -8, 24
  Subsprite_2502:
    subsprite OAM_SIZE_32x32, -16, -16
    subsprite OAM_SIZE_32x8, -8, 16
    subsprite OAM_SIZE_8x16, 16, 0
  Subsprite_2505:
    subsprite OAM_SIZE_32x32, -16, -16
    subsprite OAM_SIZE_16x16, 16, -8
    subsprite OAM_SIZE_8x8, 16, 8
  Subsprite_2508:
    subsprite OAM_SIZE_32x32, -16, -16
    subsprite OAM_SIZE_8x16, 16, -16
    subsprite OAM_SIZE_8x8, 16, 0
  Subsprite_2511:
    subsprite OAM_SIZE_32x32, -16, -16
    subsprite OAM_SIZE_16x8, -8, -24
  Subsprite_2513:
    subsprite OAM_SIZE_32x64, -24, -32
    subsprite OAM_SIZE_16x32, 8, -32
    subsprite OAM_SIZE_16x32, 8, 0
  Subsprite_2516:
    subsprite OAM_SIZE_32x32, -24, -32
    subsprite OAM_SIZE_32x16, -24, 0
    subsprite OAM_SIZE_8x32, 8, -32
    subsprite OAM_SIZE_8x16, 8, 0
  Subsprite_2520:
    subsprite OAM_SIZE_32x32, -24, -24
    subsprite OAM_SIZE_32x16, -24, 8
    subsprite OAM_SIZE_16x32, 8, -24
    subsprite OAM_SIZE_16x16, 8, 8
  Subsprite_2524:
    subsprite OAM_SIZE_32x32, -16, -16
    subsprite OAM_SIZE_8x16, -24, -16
    subsprite OAM_SIZE_8x8, -24, 0
  Subsprite_2527:
    subsprite OAM_SIZE_32x32, -24, -16
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2529:
    subsprite OAM_SIZE_32x32, -16, -32
    subsprite OAM_SIZE_32x16, -16, 0
  Subsprite_2531:
    subsprite OAM_SIZE_32x32, -24, -24
    subsprite OAM_SIZE_32x8, -24, 8
    subsprite OAM_SIZE_8x32, 8, -24
  Subsprite_2534:
    subsprite OAM_SIZE_32x32, -32, -16
    subsprite OAM_SIZE_16x32, 0, -16
  Subsprite_2536:
    subsprite OAM_SIZE_32x32, -24, -16
    subsprite OAM_SIZE_32x8, -24, 16
    subsprite OAM_SIZE_8x32, 8, -16
  Subsprite_2539:
    subsprite OAM_SIZE_32x32, -16, -16
    subsprite OAM_SIZE_32x16, -16, 16
  Subsprite_2541:
    subsprite OAM_SIZE_32x32, -16, -16
    subsprite OAM_SIZE_32x8, -16, 16
    subsprite OAM_SIZE_16x8, -8, 24
  Subsprite_2544:
    subsprite OAM_SIZE_32x32, -16, -16
    subsprite OAM_SIZE_32x8, -16, 16
    subsprite OAM_SIZE_16x8, 0, 24
  Subsprite_2547:
    subsprite OAM_SIZE_32x32, -16, -16
    subsprite OAM_SIZE_32x8, -8, 16
    subsprite OAM_SIZE_8x16, 16, 0
  Subsprite_2550:
    subsprite OAM_SIZE_32x32, -16, -16
    subsprite OAM_SIZE_8x16, 16, -8
  Subsprite_2552:
    subsprite OAM_SIZE_32x32, -16, -16
    subsprite OAM_SIZE_16x8, -8, 16
  Subsprite_2554:
    subsprite OAM_SIZE_32x64, -24, -32
    subsprite OAM_SIZE_16x32, 8, -32
    subsprite OAM_SIZE_16x32, 8, 0
  Subsprite_2557:
    subsprite OAM_SIZE_32x64, -24, -32
    subsprite OAM_SIZE_8x32, 8, -32
    subsprite OAM_SIZE_8x32, 8, 0
  Subsprite_2560:
    subsprite OAM_SIZE_32x32, -24, -24
    subsprite OAM_SIZE_32x16, -24, 8
    subsprite OAM_SIZE_16x32, 8, -24
    subsprite OAM_SIZE_16x16, 8, 8
  Subsprite_2564:
    subsprite OAM_SIZE_32x32, -24, -16
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2566:
    subsprite OAM_SIZE_32x32, -24, -16
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2568:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_2569:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_2570:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_2571:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_2572:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_2573:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_2574:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_2575:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_2576:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_2577:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_2578:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_2579:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_2580:
    subsprite OAM_SIZE_16x32, -8, -16
    subsprite OAM_SIZE_8x16, -16, -16
  Subsprite_2582:
    subsprite OAM_SIZE_16x32, -8, -16
    subsprite OAM_SIZE_8x16, -16, -16
  Subsprite_2584:
    subsprite OAM_SIZE_16x32, -8, -16
    subsprite OAM_SIZE_8x8, -16, -8
  Subsprite_2586:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_2587:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_2588:
    subsprite OAM_SIZE_16x32, -8, -16
    subsprite OAM_SIZE_8x16, -16, -8
    subsprite OAM_SIZE_8x16, 8, 0
  Subsprite_2591:
    subsprite OAM_SIZE_32x16, -16, -8
    subsprite OAM_SIZE_16x8, -8, -16
    subsprite OAM_SIZE_16x8, -8, 8
  Subsprite_2594:
    subsprite OAM_SIZE_32x16, -16, -8
    subsprite OAM_SIZE_16x8, -16, -16
    subsprite OAM_SIZE_16x8, -8, 8
  Subsprite_2597:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_2598:
    subsprite OAM_SIZE_32x16, -16, -8
    subsprite OAM_SIZE_16x8, 0, -16
    subsprite OAM_SIZE_16x8, -8, 8
  Subsprite_2601:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_2602:
    subsprite OAM_SIZE_32x16, -16, -8
    subsprite OAM_SIZE_16x8, -8, 8
    subsprite OAM_SIZE_8x8, 0, -16
  Subsprite_2605:
    subsprite OAM_SIZE_16x32, -8, -16
    subsprite OAM_SIZE_8x16, 8, 0
    subsprite OAM_SIZE_8x8, -16, 0
  Subsprite_2608:
    subsprite OAM_SIZE_16x32, -8, -16
    subsprite OAM_SIZE_8x16, 8, 0
    subsprite OAM_SIZE_8x8, -16, 0
  Subsprite_2611:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_2612:
    subsprite OAM_SIZE_16x16, -8, -11
    subsprite OAM_SIZE_16x8, -8, 5
  Subsprite_2614:
    subsprite OAM_SIZE_16x16, -8, -11
    subsprite OAM_SIZE_8x8, 0, 5
  Subsprite_2616:
    subsprite OAM_SIZE_16x16, -8, -11
    subsprite OAM_SIZE_8x8, 0, 5
  Subsprite_2618:
    subsprite OAM_SIZE_16x16, -8, -11
  Subsprite_2619:
    subsprite OAM_SIZE_16x16, -8, -11
  Subsprite_2620:
    subsprite OAM_SIZE_16x16, -8, -11
  Subsprite_2621:
    subsprite OAM_SIZE_16x16, -8, -11
    subsprite OAM_SIZE_8x8, -16, -3
  Subsprite_2623:
    subsprite OAM_SIZE_16x16, -16, -11
    subsprite OAM_SIZE_8x16, 0, -11
  Subsprite_2625:
    subsprite OAM_SIZE_16x16, -8, -11
    subsprite OAM_SIZE_8x8, -16, -3
  Subsprite_2627:
    subsprite OAM_SIZE_16x16, -8, -11
  Subsprite_2628:
    subsprite OAM_SIZE_16x16, -8, -11
    subsprite OAM_SIZE_8x8, -16, -19
  Subsprite_2630:
    subsprite OAM_SIZE_16x16, -8, -11
  Subsprite_2631:
    subsprite OAM_SIZE_16x16, -8, -19
    subsprite OAM_SIZE_16x8, -8, -3
  Subsprite_2633:
    subsprite OAM_SIZE_16x16, -8, -19
    subsprite OAM_SIZE_16x8, -8, -3
  Subsprite_2635:
    subsprite OAM_SIZE_16x16, -8, -19
    subsprite OAM_SIZE_16x8, -8, -3
  Subsprite_2637:
    subsprite OAM_SIZE_16x32, -8, -19
  Subsprite_2638:
    subsprite OAM_SIZE_16x16, -8, -11
    subsprite OAM_SIZE_8x8, -8, -19
  Subsprite_2640:
    subsprite OAM_SIZE_16x16, -8, -11
    subsprite OAM_SIZE_8x8, 0, -19
    subsprite OAM_SIZE_8x8, -16, -3
  Subsprite_2643:
    subsprite OAM_SIZE_16x16, -8, -11
    subsprite OAM_SIZE_8x8, -16, -11
  Subsprite_2645:
    subsprite OAM_SIZE_16x16, -8, -11
  Subsprite_2646:
    subsprite OAM_SIZE_16x16, -8, -11
  Subsprite_2647:
    subsprite OAM_SIZE_16x16, -8, -11
    subsprite OAM_SIZE_8x8, -16, -11
  Subsprite_2649:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2652:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2655:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2658:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2661:
    subsprite OAM_SIZE_16x8, -8, -8
  Subsprite_2662:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2665:
    subsprite OAM_SIZE_32x64, -8, -48
  Subsprite_2666:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2669:
    subsprite OAM_SIZE_32x64, -24, -48
  Subsprite_2670:
    subsprite OAM_SIZE_32x32, -24, -48
    subsprite OAM_SIZE_32x16, -24, -16
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x16, 8, -16
  Subsprite_2674:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2677:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2680:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2683:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2686:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2689:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2692:
    subsprite OAM_SIZE_32x32, -24, -32
    subsprite OAM_SIZE_32x16, -24, 0
    subsprite OAM_SIZE_16x32, 8, -32
    subsprite OAM_SIZE_16x16, 8, 0
  Subsprite_2696:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2698:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2701:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2704:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2707:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2710:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2713:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2716:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2719:
    subsprite OAM_SIZE_32x64, -22, -29
    subsprite OAM_SIZE_16x32, 10, -29
    subsprite OAM_SIZE_16x32, 10, 3
  Subsprite_2722:
    subsprite OAM_SIZE_32x64, -22, -29
    subsprite OAM_SIZE_16x32, 10, -29
    subsprite OAM_SIZE_16x32, 10, 3
  Subsprite_2725:
    subsprite OAM_SIZE_32x32, -20, -20
    subsprite OAM_SIZE_8x32, 12, -20
  Subsprite_2727:
    subsprite OAM_SIZE_32x16, 4, -20
    subsprite OAM_SIZE_8x16, 36, -20
  Subsprite_2729:
    subsprite OAM_SIZE_32x16, -28, 4
    subsprite OAM_SIZE_32x8, -28, 20
    subsprite OAM_SIZE_16x8, -12, -4
  Subsprite_2732:
    subsprite OAM_SIZE_32x16, -28, 4
    subsprite OAM_SIZE_32x8, -28, 20
    subsprite OAM_SIZE_16x8, -20, -4
  Subsprite_2735:
    subsprite OAM_SIZE_32x32, -28, -4
  Subsprite_2736:
    subsprite OAM_SIZE_32x32, -28, -4
  Subsprite_2737:
    subsprite OAM_SIZE_32x16, -28, 4
    subsprite OAM_SIZE_32x8, -28, 20
  Subsprite_2739:
    subsprite OAM_SIZE_32x32, -28, -4
  Subsprite_2740:
    subsprite OAM_SIZE_32x8, -28, 4
    subsprite OAM_SIZE_16x16, -20, 12
    subsprite OAM_SIZE_8x8, -28, 12
  Subsprite_2743:
    subsprite OAM_SIZE_32x32, 0, 0
    subsprite OAM_SIZE_32x16, 0, 32
    subsprite OAM_SIZE_16x32, 32, 0
    subsprite OAM_SIZE_16x16, 32, 32
  Subsprite_2747:
    subsprite OAM_SIZE_32x64, 0, 0
    subsprite OAM_SIZE_16x32, 32, 0
    subsprite OAM_SIZE_16x32, 32, 32
  Subsprite_2750:
    subsprite OAM_SIZE_32x64, 0, 0
    subsprite OAM_SIZE_16x32, 32, 0
    subsprite OAM_SIZE_16x32, 32, 32
  Subsprite_2753:
    subsprite OAM_SIZE_32x64, 0, 0
    subsprite OAM_SIZE_16x32, 32, 0
    subsprite OAM_SIZE_16x32, 32, 32
  Subsprite_2756:
    subsprite OAM_SIZE_32x32, 0, 0
    subsprite OAM_SIZE_32x16, 0, 32
    subsprite OAM_SIZE_16x32, 32, 0
    subsprite OAM_SIZE_16x16, 32, 32
  Subsprite_2760:
    subsprite OAM_SIZE_32x32, 0, 0
    subsprite OAM_SIZE_32x16, 0, 32
    subsprite OAM_SIZE_16x32, 32, 0
    subsprite OAM_SIZE_16x16, 32, 32
  Subsprite_2764:
    subsprite OAM_SIZE_32x32, -14, -32
    subsprite OAM_SIZE_32x16, -14, 0
  Subsprite_2766:
    subsprite OAM_SIZE_32x32, -14, -32
    subsprite OAM_SIZE_32x8, -14, 0
  Subsprite_2768:
    subsprite OAM_SIZE_32x32, -14, -32
    subsprite OAM_SIZE_32x8, -14, 0
  Subsprite_2770:
    subsprite OAM_SIZE_32x32, -14, -32
    subsprite OAM_SIZE_32x16, -14, 0
  Subsprite_2772:
    subsprite OAM_SIZE_16x32, -14, -32
    subsprite OAM_SIZE_8x32, 2, -24
    subsprite OAM_SIZE_16x8, -14, 0
  Subsprite_2775:
    subsprite OAM_SIZE_32x32, -14, -32
    subsprite OAM_SIZE_32x16, -14, 0
  Subsprite_2777:
    subsprite OAM_SIZE_32x32, -14, -32
    subsprite OAM_SIZE_32x16, -14, 0
  Subsprite_2779:
    subsprite OAM_SIZE_16x16, -6, -8
    subsprite OAM_SIZE_8x8, -14, -8
  Subsprite_2781:
    subsprite OAM_SIZE_32x32, -14, -16
  Subsprite_2782:
    subsprite OAM_SIZE_32x32, -14, -24
    subsprite OAM_SIZE_32x8, -14, 8
  Subsprite_2784:
    subsprite OAM_SIZE_16x32, -6, -32
    subsprite OAM_SIZE_8x32, -14, -24
    subsprite OAM_SIZE_16x8, -6, 0
  Subsprite_2787:
    subsprite OAM_SIZE_16x16, -14, -16
    subsprite OAM_SIZE_16x8, -14, 0
    subsprite OAM_SIZE_8x16, 2, -16
    subsprite OAM_SIZE_8x8, 2, 0
  Subsprite_2791:
    subsprite OAM_SIZE_32x8, -14, -8
    subsprite OAM_SIZE_16x8, -14, 0
    subsprite OAM_SIZE_8x8, 2, 0
  Subsprite_2794:
    subsprite OAM_SIZE_16x32, -14, -32
    subsprite OAM_SIZE_8x32, 2, -32
    subsprite OAM_SIZE_16x8, -14, 0
    subsprite OAM_SIZE_8x8, 2, 0
  Subsprite_2798:
    subsprite OAM_SIZE_32x32, -14, -24
  Subsprite_2799:
    subsprite OAM_SIZE_32x32, -22, -24
    subsprite OAM_SIZE_32x8, -22, 8
    subsprite OAM_SIZE_8x32, 10, -24
  Subsprite_2802:
    subsprite OAM_SIZE_32x32, -14, -32
    subsprite OAM_SIZE_32x8, -14, 0
  Subsprite_2804:
    subsprite OAM_SIZE_64x64, -30, -40
  Subsprite_2805:
    subsprite OAM_SIZE_32x32, -22, -32
    subsprite OAM_SIZE_16x32, 10, -32
    subsprite OAM_SIZE_32x8, -22, 0
  Subsprite_2808:
    subsprite OAM_SIZE_32x64, -14, -40
  Subsprite_2809:
    subsprite OAM_SIZE_32x32, -14, -32
    subsprite OAM_SIZE_32x16, -14, 0
  Subsprite_2811:
    subsprite OAM_SIZE_32x16, -14, -16
    subsprite OAM_SIZE_32x8, -14, 0
    subsprite OAM_SIZE_16x16, -14, -32
  Subsprite_2814:
    subsprite OAM_SIZE_32x32, -30, -24
    subsprite OAM_SIZE_16x32, 2, -24
  Subsprite_2816:
    subsprite OAM_SIZE_32x32, -22, -40
    subsprite OAM_SIZE_32x16, -22, -8
  Subsprite_2818:
    subsprite OAM_SIZE_64x32, -30, -24
    subsprite OAM_SIZE_32x16, 2, 8
  Subsprite_2820:
    subsprite OAM_SIZE_32x32, -22, -24
    subsprite OAM_SIZE_16x32, 10, -24
  Subsprite_2822:
    subsprite OAM_SIZE_32x32, -14, -24
    subsprite OAM_SIZE_32x8, -14, 8
    subsprite OAM_SIZE_8x32, 18, -24
  Subsprite_2825:
    subsprite OAM_SIZE_32x32, -14, -32
    subsprite OAM_SIZE_32x16, -14, 0
  Subsprite_2827:
    subsprite OAM_SIZE_32x64, -14, -40
  Subsprite_2828:
    subsprite OAM_SIZE_32x64, -14, -40
  Subsprite_2829:
    subsprite OAM_SIZE_32x64, -14, -40
  Subsprite_2830:
    subsprite OAM_SIZE_32x64, -14, -40
  Subsprite_2831:
    subsprite OAM_SIZE_32x64, -14, -40
  Subsprite_2832:
    subsprite OAM_SIZE_32x32, -14, -32
    subsprite OAM_SIZE_32x8, -14, 0
  Subsprite_2834:
    subsprite OAM_SIZE_32x32, -14, -16
  Subsprite_2835:
    subsprite OAM_SIZE_32x16, -16, -8
    subsprite OAM_SIZE_32x8, -16, 8
    subsprite OAM_SIZE_16x8, -8, -16
  Subsprite_2838:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2841:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2844:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2847:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2850:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2853:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2856:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2859:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2862:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2865:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2868:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2871:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2874:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2877:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2880:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2883:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2886:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2889:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2892:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2895:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2898:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2901:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2904:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2907:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2910:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2913:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2916:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2919:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_2922:
    subsprite OAM_SIZE_32x32, -17, -17
    subsprite OAM_SIZE_8x16, -25, -9
    subsprite OAM_SIZE_8x16, 15, -9
  Subsprite_2925:
    subsprite OAM_SIZE_32x32, -25, -25
    subsprite OAM_SIZE_16x32, 7, -25
    subsprite OAM_SIZE_32x8, -25, 7
    subsprite OAM_SIZE_16x8, 7, 7
  Subsprite_2929:
    subsprite OAM_SIZE_32x64, -25, -49
    subsprite OAM_SIZE_16x32, 7, -49
    subsprite OAM_SIZE_16x32, 7, -17
  Subsprite_2932:
    subsprite OAM_SIZE_32x64, -25, -49
    subsprite OAM_SIZE_16x32, 7, -49
    subsprite OAM_SIZE_16x32, 7, -17
  Subsprite_2935:
    subsprite OAM_SIZE_32x64, -25, -49
    subsprite OAM_SIZE_16x32, 7, -49
    subsprite OAM_SIZE_16x32, 7, -17
  Subsprite_2938:
    subsprite OAM_SIZE_32x64, -25, -49
    subsprite OAM_SIZE_16x32, 7, -49
    subsprite OAM_SIZE_16x32, 7, -17
  Subsprite_2941:
    subsprite OAM_SIZE_32x64, -25, -49
    subsprite OAM_SIZE_16x32, 7, -49
    subsprite OAM_SIZE_16x32, 7, -17
  Subsprite_2944:
    subsprite OAM_SIZE_32x64, -25, -49
    subsprite OAM_SIZE_16x32, 7, -49
    subsprite OAM_SIZE_16x32, 7, -17
  Subsprite_2947:
    subsprite OAM_SIZE_32x64, -25, -49
    subsprite OAM_SIZE_16x32, 7, -49
    subsprite OAM_SIZE_16x32, 7, -17
  Subsprite_2950:
    subsprite OAM_SIZE_32x32, -25, -25
    subsprite OAM_SIZE_16x32, 7, -25
    subsprite OAM_SIZE_32x8, -25, 7
    subsprite OAM_SIZE_16x8, 7, 7
  Subsprite_2954:
    subsprite OAM_SIZE_32x64, -25, -49
    subsprite OAM_SIZE_16x32, 7, -49
    subsprite OAM_SIZE_16x32, 7, -17
  Subsprite_2957:
    subsprite OAM_SIZE_32x64, -25, -49
    subsprite OAM_SIZE_16x32, 7, -49
    subsprite OAM_SIZE_16x32, 7, -17
  Subsprite_2960:
    subsprite OAM_SIZE_32x64, -25, -49
    subsprite OAM_SIZE_16x32, 7, -49
    subsprite OAM_SIZE_16x32, 7, -17
  Subsprite_2963:
    subsprite OAM_SIZE_32x64, -25, -49
    subsprite OAM_SIZE_16x32, 7, -49
    subsprite OAM_SIZE_16x32, 7, -17
  Subsprite_2966:
    subsprite OAM_SIZE_32x64, -25, -49
    subsprite OAM_SIZE_16x32, 7, -49
    subsprite OAM_SIZE_16x32, 7, -17
  Subsprite_2969:
    subsprite OAM_SIZE_32x64, -25, -49
    subsprite OAM_SIZE_16x32, 7, -49
    subsprite OAM_SIZE_16x32, 7, -17
  Subsprite_2972:
    subsprite OAM_SIZE_32x32, -25, -33
    subsprite OAM_SIZE_32x16, -25, -1
    subsprite OAM_SIZE_16x32, 7, -33
    subsprite OAM_SIZE_16x16, 7, -1
  Subsprite_2976:
    subsprite OAM_SIZE_32x32, -24, -24
    subsprite OAM_SIZE_32x16, -24, 8
    subsprite OAM_SIZE_16x32, 8, -24
    subsprite OAM_SIZE_16x16, 8, 8
  Subsprite_2980:
    subsprite OAM_SIZE_64x64, -32, -32
  Subsprite_2981:
    subsprite OAM_SIZE_16x32, -7, -5
    subsprite OAM_SIZE_8x16, 9, 3
    subsprite OAM_SIZE_8x8, 9, 19
  Subsprite_2984:
    subsprite OAM_SIZE_16x32, -7, -5
    subsprite OAM_SIZE_8x16, 9, 3
    subsprite OAM_SIZE_8x8, 9, 19
  Subsprite_2987:
    subsprite OAM_SIZE_16x32, -7, -5
    subsprite OAM_SIZE_8x16, 9, 3
    subsprite OAM_SIZE_8x8, 9, 19
  Subsprite_2990:
    subsprite OAM_SIZE_16x32, -7, -5
    subsprite OAM_SIZE_8x16, 9, 3
    subsprite OAM_SIZE_8x8, 9, 19
  Subsprite_2993:
    subsprite OAM_SIZE_32x32, -16, 0
    subsprite OAM_SIZE_32x16, -16, 32
    subsprite OAM_SIZE_8x32, 16, 0
  Subsprite_2996:
    subsprite OAM_SIZE_32x32, -16, 0
    subsprite OAM_SIZE_32x16, -16, 32
    subsprite OAM_SIZE_8x32, 16, 0
  Subsprite_2999:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_3002:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_3005:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_3008:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_3011:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_3014:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_3017:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_3020:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_3023:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_3026:
    subsprite OAM_SIZE_32x32, -24, -40
    subsprite OAM_SIZE_16x32, 8, -40
    subsprite OAM_SIZE_32x8, -24, -8
    subsprite OAM_SIZE_16x8, 8, -8
  Subsprite_3030:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_3033:
    subsprite OAM_SIZE_8x8, -4, -4
  Subsprite_3034:
    subsprite OAM_SIZE_8x8, -4, -4
  Subsprite_3035:
    subsprite OAM_SIZE_8x8, -4, -4
  Subsprite_3036:
    subsprite OAM_SIZE_8x8, -4, -4
  Subsprite_3037:
    subsprite OAM_SIZE_32x64, -24, -33
    subsprite OAM_SIZE_16x32, 8, -33
    subsprite OAM_SIZE_16x32, 8, -1
  Subsprite_3040:
    subsprite OAM_SIZE_64x64, -24, -32
  Subsprite_3041:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_3044:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_3047:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_3050:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_3053:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_3056:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_3059:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_3062:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_3065:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_3068:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_3071:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_3074:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_3077:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_3080:
    subsprite OAM_SIZE_32x32, -24, -48
    subsprite OAM_SIZE_32x16, -24, -16
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x16, 8, -16
  Subsprite_3084:
    subsprite OAM_SIZE_32x32, -16, -24
    subsprite OAM_SIZE_32x8, -16, 8
    subsprite OAM_SIZE_8x32, 16, -24
    subsprite OAM_SIZE_8x8, 16, 8
  Subsprite_3088:
    subsprite OAM_SIZE_32x16, -16, -16
    subsprite OAM_SIZE_32x16, -8, 0
    subsprite OAM_SIZE_16x8, -16, -24
  Subsprite_3091:
    subsprite OAM_SIZE_32x32, -16, -24
    subsprite OAM_SIZE_32x16, -16, 8
    subsprite OAM_SIZE_8x32, 16, -24
    subsprite OAM_SIZE_8x16, 16, 8
  Subsprite_3095:
    subsprite OAM_SIZE_32x32, -16, -24
    subsprite OAM_SIZE_32x16, -16, 8
    subsprite OAM_SIZE_8x32, 16, -24
    subsprite OAM_SIZE_8x16, 16, 8
  Subsprite_3099:
    subsprite OAM_SIZE_32x32, -16, -24
    subsprite OAM_SIZE_32x16, -16, 8
    subsprite OAM_SIZE_8x32, 16, -24
    subsprite OAM_SIZE_8x16, 16, 8
  Subsprite_3103:
    subsprite OAM_SIZE_32x32, -16, -24
    subsprite OAM_SIZE_32x16, -16, 8
    subsprite OAM_SIZE_8x32, 16, -24
    subsprite OAM_SIZE_8x16, 16, 8
  Subsprite_3107:
    subsprite OAM_SIZE_32x16, -16, -16
    subsprite OAM_SIZE_32x16, -8, 0
    subsprite OAM_SIZE_16x8, -16, -24
  Subsprite_3110:
    subsprite OAM_SIZE_32x16, -16, -16
    subsprite OAM_SIZE_32x16, -8, 0
    subsprite OAM_SIZE_16x8, -16, -24
  Subsprite_3113:
    subsprite OAM_SIZE_32x16, -8, -24
    subsprite OAM_SIZE_32x16, -16, -8
    subsprite OAM_SIZE_16x8, -16, 8
  Subsprite_3116:
    subsprite OAM_SIZE_32x32, -16, -24
    subsprite OAM_SIZE_32x8, -16, 8
    subsprite OAM_SIZE_8x32, 16, -24
  Subsprite_3119:
    subsprite OAM_SIZE_32x32, -16, -24
    subsprite OAM_SIZE_32x8, -16, 8
    subsprite OAM_SIZE_8x32, 16, -24
  Subsprite_3122:
    subsprite OAM_SIZE_32x32, -16, -24
    subsprite OAM_SIZE_32x8, -16, 8
    subsprite OAM_SIZE_8x32, 16, -24
  Subsprite_3125:
    subsprite OAM_SIZE_32x32, -16, -24
    subsprite OAM_SIZE_32x8, -16, 8
    subsprite OAM_SIZE_8x32, 16, -24
  Subsprite_3128:
    subsprite OAM_SIZE_32x32, -16, -24
    subsprite OAM_SIZE_32x8, -16, 8
    subsprite OAM_SIZE_8x32, 16, -24
  Subsprite_3131:
    subsprite OAM_SIZE_32x32, -16, -24
    subsprite OAM_SIZE_32x8, -16, 8
    subsprite OAM_SIZE_8x32, 16, -24
  Subsprite_3134:
    subsprite OAM_SIZE_32x32, -16, -24
    subsprite OAM_SIZE_16x32, 16, -24
    subsprite OAM_SIZE_32x8, -16, 8
  Subsprite_3137:
    subsprite OAM_SIZE_32x64, -16, -32
    subsprite OAM_SIZE_8x32, 16, -32
    subsprite OAM_SIZE_8x32, 16, 0
  Subsprite_3140:
    subsprite OAM_SIZE_32x64, -16, -32
    subsprite OAM_SIZE_8x32, 16, -32
    subsprite OAM_SIZE_8x32, 16, 0
  Subsprite_3143:
    subsprite OAM_SIZE_32x64, -16, -32
    subsprite OAM_SIZE_8x32, 16, -32
    subsprite OAM_SIZE_8x32, 16, 0
  Subsprite_3146:
    subsprite OAM_SIZE_32x32, -24, -24
    subsprite OAM_SIZE_16x32, 8, -24
    subsprite OAM_SIZE_32x8, -24, 8
  Subsprite_3149:
    subsprite OAM_SIZE_32x32, -24, -24
    subsprite OAM_SIZE_16x32, 8, -24
    subsprite OAM_SIZE_32x8, -24, 8
  Subsprite_3152:
    subsprite OAM_SIZE_32x32, -24, -24
    subsprite OAM_SIZE_16x32, 8, -24
    subsprite OAM_SIZE_32x8, -24, 8
  Subsprite_3155:
    subsprite OAM_SIZE_32x32, -24, -24
    subsprite OAM_SIZE_16x32, 8, -24
    subsprite OAM_SIZE_32x8, -24, 8
    subsprite OAM_SIZE_16x8, 8, 8
  Subsprite_3159:
    subsprite OAM_SIZE_32x32, -24, -24
    subsprite OAM_SIZE_16x32, 8, -24
    subsprite OAM_SIZE_32x8, -24, 8
    subsprite OAM_SIZE_16x8, 8, 8
  Subsprite_3163:
    subsprite OAM_SIZE_32x32, -24, -24
    subsprite OAM_SIZE_16x32, 8, -24
    subsprite OAM_SIZE_32x8, -24, 8
    subsprite OAM_SIZE_16x8, 8, 8
  Subsprite_3167:
    subsprite OAM_SIZE_32x32, -16, -24
    subsprite OAM_SIZE_32x8, -16, 8
    subsprite OAM_SIZE_8x32, 16, -24
    subsprite OAM_SIZE_8x8, 16, 8
  Subsprite_3171:
    subsprite OAM_SIZE_32x32, -16, -24
    subsprite OAM_SIZE_32x8, -16, 8
    subsprite OAM_SIZE_8x32, 16, -24
    subsprite OAM_SIZE_8x8, 16, 8
  Subsprite_3175:
    subsprite OAM_SIZE_32x32, -16, -24
    subsprite OAM_SIZE_32x8, -16, 8
    subsprite OAM_SIZE_8x32, 16, -24
    subsprite OAM_SIZE_8x8, 16, 8
  Subsprite_3179:
    subsprite OAM_SIZE_32x32, -16, -24
    subsprite OAM_SIZE_32x8, -16, 8
    subsprite OAM_SIZE_8x32, 16, -24
    subsprite OAM_SIZE_8x8, 16, 8
  Subsprite_3183:
    subsprite OAM_SIZE_32x32, -16, -24
    subsprite OAM_SIZE_32x8, -16, 8
    subsprite OAM_SIZE_8x32, 16, -24
    subsprite OAM_SIZE_8x8, 16, 8
  Subsprite_3187:
    subsprite OAM_SIZE_32x32, -16, -24
    subsprite OAM_SIZE_32x16, -16, 8
    subsprite OAM_SIZE_8x32, 16, -24
  Subsprite_3190:
    subsprite OAM_SIZE_32x16, -8, -24
    subsprite OAM_SIZE_32x16, -16, -8
    subsprite OAM_SIZE_16x8, -16, 8
  Subsprite_3193:
    subsprite OAM_SIZE_32x16, -8, -24
    subsprite OAM_SIZE_32x16, -16, -8
    subsprite OAM_SIZE_16x8, -16, 8
  Subsprite_3196:
    subsprite OAM_SIZE_32x16, -8, -24
    subsprite OAM_SIZE_32x16, -16, -8
    subsprite OAM_SIZE_16x8, -16, 8
  Subsprite_3199:
    subsprite OAM_SIZE_32x32, -16, -24
    subsprite OAM_SIZE_32x8, -16, 8
    subsprite OAM_SIZE_8x32, 16, -24
  Subsprite_3202:
    subsprite OAM_SIZE_32x32, -24, -24
    subsprite OAM_SIZE_16x32, 8, -24
    subsprite OAM_SIZE_32x8, -24, 8
  Subsprite_3205:
    subsprite OAM_SIZE_32x32, -16, -24
    subsprite OAM_SIZE_32x8, -16, 8
    subsprite OAM_SIZE_8x32, 16, -24
  Subsprite_3208:
    subsprite OAM_SIZE_32x32, -16, -24
    subsprite OAM_SIZE_32x8, -16, 8
    subsprite OAM_SIZE_8x32, 16, -24
  Subsprite_3211:
    subsprite OAM_SIZE_32x32, -16, -24
    subsprite OAM_SIZE_32x16, -16, 8
    subsprite OAM_SIZE_8x32, 16, -24
    subsprite OAM_SIZE_8x16, 16, 8
  Subsprite_3215:
    subsprite OAM_SIZE_32x32, -24, -24
    subsprite OAM_SIZE_32x16, -24, 8
    subsprite OAM_SIZE_16x32, 8, -24
    subsprite OAM_SIZE_16x16, 8, 8
  Subsprite_3219:
    subsprite OAM_SIZE_32x32, -24, -24
    subsprite OAM_SIZE_32x16, -24, 8
    subsprite OAM_SIZE_16x32, 8, -24
    subsprite OAM_SIZE_16x16, 8, 8
  Subsprite_3223:
    subsprite OAM_SIZE_32x32, -16, -24
    subsprite OAM_SIZE_32x8, -16, 8
    subsprite OAM_SIZE_8x32, 16, -24
  Subsprite_3226:
    subsprite OAM_SIZE_64x32, -32, -24
    subsprite OAM_SIZE_32x16, -32, 8
  Subsprite_3228:
    subsprite OAM_SIZE_64x32, -32, -24
    subsprite OAM_SIZE_32x16, -32, 8
  Subsprite_3230:
    subsprite OAM_SIZE_32x64, -16, -32
    subsprite OAM_SIZE_16x32, 16, -32
    subsprite OAM_SIZE_16x32, 16, 0
  Subsprite_3233:
    subsprite OAM_SIZE_32x64, -16, -32
    subsprite OAM_SIZE_16x32, 16, -32
    subsprite OAM_SIZE_16x32, 16, 0
  Subsprite_3236:
    subsprite OAM_SIZE_32x32, -16, -32
    subsprite OAM_SIZE_32x16, -16, 0
    subsprite OAM_SIZE_8x32, 16, -32
  Subsprite_3239:
    subsprite OAM_SIZE_32x32, -16, -32
    subsprite OAM_SIZE_32x16, -16, 0
    subsprite OAM_SIZE_8x32, 16, -32
  Subsprite_3242:
    subsprite OAM_SIZE_32x32, -16, -24
    subsprite OAM_SIZE_32x8, -16, 8
    subsprite OAM_SIZE_8x32, 16, -24
  Subsprite_3245:
    subsprite OAM_SIZE_32x32, -16, -24
    subsprite OAM_SIZE_32x8, -16, 8
    subsprite OAM_SIZE_8x32, 16, -24
    subsprite OAM_SIZE_8x8, 16, 8
  Subsprite_3249:
    subsprite OAM_SIZE_32x32, -24, -24
    subsprite OAM_SIZE_16x32, 8, -24
    subsprite OAM_SIZE_32x8, -24, 8
    subsprite OAM_SIZE_16x8, 8, 8
  Subsprite_3253:
    subsprite OAM_SIZE_32x32, -24, -24
    subsprite OAM_SIZE_16x32, 8, -24
    subsprite OAM_SIZE_16x8, 8, 8
  Subsprite_3256:
    subsprite OAM_SIZE_32x32, -16, -24
    subsprite OAM_SIZE_32x8, -16, 8
    subsprite OAM_SIZE_8x32, 16, -24
    subsprite OAM_SIZE_8x8, 16, 8
  Subsprite_3260:
    subsprite OAM_SIZE_32x32, -16, -24
    subsprite OAM_SIZE_32x8, -16, 8
    subsprite OAM_SIZE_8x32, 16, -24
    subsprite OAM_SIZE_8x8, 16, 8
  Subsprite_3264:
    subsprite OAM_SIZE_32x32, -16, -24
    subsprite OAM_SIZE_32x8, -16, 8
    subsprite OAM_SIZE_8x32, 16, -24
    subsprite OAM_SIZE_8x8, 16, 8
  Subsprite_3268:
    subsprite OAM_SIZE_32x32, -16, -24
    subsprite OAM_SIZE_32x8, -16, 8
    subsprite OAM_SIZE_8x32, 16, -24
  Subsprite_3271:
    subsprite OAM_SIZE_32x32, -24, -24
    subsprite OAM_SIZE_16x32, 8, -24
    subsprite OAM_SIZE_32x8, -24, 8
  Subsprite_3274:
    subsprite OAM_SIZE_32x64, -24, -32
    subsprite OAM_SIZE_16x32, 8, -32
  Subsprite_3276:
    subsprite OAM_SIZE_32x32, -24, -24
    subsprite OAM_SIZE_16x32, 8, -24
    subsprite OAM_SIZE_32x8, -24, 8
  Subsprite_3279:
    subsprite OAM_SIZE_32x32, -24, -24
    subsprite OAM_SIZE_16x32, 8, -24
    subsprite OAM_SIZE_32x8, -24, 8
  Subsprite_3282:
    subsprite OAM_SIZE_32x32, -16, -24
    subsprite OAM_SIZE_32x8, -16, 8
    subsprite OAM_SIZE_8x32, 16, -24
  Subsprite_3285:
    subsprite OAM_SIZE_32x16, -8, -24
    subsprite OAM_SIZE_32x16, -16, -8
  Subsprite_3287:
    subsprite OAM_SIZE_32x32, -16, -24
    subsprite OAM_SIZE_8x32, 16, -24
  Subsprite_3289:
    subsprite OAM_SIZE_32x16, -8, -24
    subsprite OAM_SIZE_32x16, -16, -8
  Subsprite_3291:
    subsprite OAM_SIZE_32x32, -16, -24
    subsprite OAM_SIZE_32x8, -16, 8
  Subsprite_3293:
    subsprite OAM_SIZE_32x32, -24, -24
    subsprite OAM_SIZE_32x8, -24, 8
    subsprite OAM_SIZE_8x32, 8, -24
  Subsprite_3296:
    subsprite OAM_SIZE_32x32, -16, -24
  Subsprite_3297:
    subsprite OAM_SIZE_32x32, -16, -16
    subsprite OAM_SIZE_8x16, 16, -16
    subsprite OAM_SIZE_8x16, -24, -8
  Subsprite_3300:
    subsprite OAM_SIZE_32x32, -24, -16
    subsprite OAM_SIZE_8x32, 8, -16
  Subsprite_3302:
    subsprite OAM_SIZE_32x32, -24, -24
    subsprite OAM_SIZE_16x32, 8, -24
    subsprite OAM_SIZE_32x8, -24, 8
  Subsprite_3305:
    subsprite OAM_SIZE_32x32, -24, -24
    subsprite OAM_SIZE_8x32, 8, -24
  Subsprite_3307:
    subsprite OAM_SIZE_32x32, -24, -24
    subsprite OAM_SIZE_16x32, 8, -24
    subsprite OAM_SIZE_32x8, -24, 8
  Subsprite_3310:
    subsprite OAM_SIZE_32x32, -24, -16
    subsprite OAM_SIZE_8x32, 8, -16
  Subsprite_3312:
    subsprite OAM_SIZE_32x32, -24, -16
    subsprite OAM_SIZE_16x32, 8, -16
    subsprite OAM_SIZE_32x8, -24, 16
  Subsprite_3315:
    subsprite OAM_SIZE_32x32, -16, -32
    subsprite OAM_SIZE_32x16, -16, 0
  Subsprite_3317:
    subsprite OAM_SIZE_32x32, -16, -32
    subsprite OAM_SIZE_32x16, -16, 0
    subsprite OAM_SIZE_8x32, 16, -32
  Subsprite_3320:
    subsprite OAM_SIZE_32x32, -16, -16
    subsprite OAM_SIZE_16x32, 16, -16
  Subsprite_3322:
    subsprite OAM_SIZE_32x32, -24, -16
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_3324:
    subsprite OAM_SIZE_32x32, -16, -24
    subsprite OAM_SIZE_32x8, -16, 8
  Subsprite_3326:
    subsprite OAM_SIZE_32x32, -24, -24
    subsprite OAM_SIZE_32x8, -24, 8
    subsprite OAM_SIZE_8x32, 8, -24
  Subsprite_3329:
    subsprite OAM_SIZE_32x32, -24, -24
    subsprite OAM_SIZE_16x32, 8, -24
    subsprite OAM_SIZE_32x8, -24, 8
  Subsprite_3332:
    subsprite OAM_SIZE_32x32, -24, -24
    subsprite OAM_SIZE_16x32, 8, -24
    subsprite OAM_SIZE_32x8, -24, 8
  Subsprite_3335:
    subsprite OAM_SIZE_32x32, -16, -43
    subsprite OAM_SIZE_32x16, -16, -11
    subsprite OAM_SIZE_8x32, 16, -43
    subsprite OAM_SIZE_8x16, 16, -11
  Subsprite_3339:
    subsprite OAM_SIZE_32x32, -16, -27
    subsprite OAM_SIZE_16x16, 0, -43
    subsprite OAM_SIZE_8x16, 16, -19
  Subsprite_3342:
    subsprite OAM_SIZE_32x32, -16, -27
    subsprite OAM_SIZE_16x16, 0, -43
  Subsprite_3344:
    subsprite OAM_SIZE_32x32, -16, -43
    subsprite OAM_SIZE_32x16, -16, -11
  Subsprite_3346:
    subsprite OAM_SIZE_32x64, -16, -43
  Subsprite_3347:
    subsprite OAM_SIZE_32x64, -16, -43
    subsprite OAM_SIZE_8x32, 16, -43
  Subsprite_3349:
    subsprite OAM_SIZE_32x32, -16, -27
    subsprite OAM_SIZE_16x16, 0, -43
    subsprite OAM_SIZE_16x8, -16, 5
  Subsprite_3352:
    subsprite OAM_SIZE_32x32, -16, -43
    subsprite OAM_SIZE_32x16, -16, -11
  Subsprite_3354:
    subsprite OAM_SIZE_32x32, -16, -35
    subsprite OAM_SIZE_32x16, -16, -3
    subsprite OAM_SIZE_8x32, 16, -35
  Subsprite_3357:
    subsprite OAM_SIZE_32x64, -16, -43
    subsprite OAM_SIZE_8x32, 16, -43
    subsprite OAM_SIZE_8x32, 16, -11
  Subsprite_3360:
    subsprite OAM_SIZE_32x32, -16, -35
    subsprite OAM_SIZE_32x16, -16, -3
  Subsprite_3362:
    subsprite OAM_SIZE_32x32, -16, -35
    subsprite OAM_SIZE_32x16, -16, -3
  Subsprite_3364:
    subsprite OAM_SIZE_32x32, -16, -27
    subsprite OAM_SIZE_8x16, 16, -19
    subsprite OAM_SIZE_8x8, -16, -35
  Subsprite_3367:
    subsprite OAM_SIZE_32x32, -16, -35
    subsprite OAM_SIZE_32x16, -16, -3
    subsprite OAM_SIZE_8x32, 16, -35
    subsprite OAM_SIZE_8x16, 16, -3
  Subsprite_3371:
    subsprite OAM_SIZE_32x32, -16, -35
    subsprite OAM_SIZE_32x8, -16, -3
  Subsprite_3373:
    subsprite OAM_SIZE_32x32, -16, -35
    subsprite OAM_SIZE_32x8, -16, -3
  Subsprite_3375:
    subsprite OAM_SIZE_32x32, -16, -35
    subsprite OAM_SIZE_32x16, -16, -3
  Subsprite_3377:
    subsprite OAM_SIZE_32x32, -16, -27
    subsprite OAM_SIZE_16x8, -8, -35
    subsprite OAM_SIZE_8x8, 8, -35
  Subsprite_3380:
    subsprite OAM_SIZE_32x32, -16, -35
    subsprite OAM_SIZE_32x16, -16, -3
    subsprite OAM_SIZE_8x32, 16, -35
  Subsprite_3383:
    subsprite OAM_SIZE_32x32, -16, -19
    subsprite OAM_SIZE_16x8, 8, -27
    subsprite OAM_SIZE_8x16, 16, -19
  Subsprite_3386:
    subsprite OAM_SIZE_32x32, -16, -19
    subsprite OAM_SIZE_16x8, 8, -27
    subsprite OAM_SIZE_8x16, 16, -19
  Subsprite_3389:
    subsprite OAM_SIZE_32x32, -16, -19
    subsprite OAM_SIZE_16x8, 8, -27
    subsprite OAM_SIZE_8x16, 16, -19
  Subsprite_3392:
    subsprite OAM_SIZE_32x32, -16, -19
    subsprite OAM_SIZE_16x8, 8, -27
    subsprite OAM_SIZE_8x16, 16, -19
  Subsprite_3395:
    subsprite OAM_SIZE_32x32, -16, -19
    subsprite OAM_SIZE_16x8, 8, -27
    subsprite OAM_SIZE_8x16, 16, -19
  Subsprite_3398:
    subsprite OAM_SIZE_32x32, -16, -27
    subsprite OAM_SIZE_16x8, -16, -35
    subsprite OAM_SIZE_8x8, 0, -35
  Subsprite_3401:
    subsprite OAM_SIZE_32x32, -16, -35
    subsprite OAM_SIZE_32x8, -16, -3
  Subsprite_3403:
    subsprite OAM_SIZE_32x32, -16, -27
    subsprite OAM_SIZE_8x16, -24, -27
    subsprite OAM_SIZE_8x8, -8, 5
  Subsprite_3406:
    subsprite OAM_SIZE_32x32, -16, -19
    subsprite OAM_SIZE_8x8, -24, -3
  Subsprite_3408:
    subsprite OAM_SIZE_32x32, -16, -19
  Subsprite_3409:
    subsprite OAM_SIZE_32x32, -16, -19
  Subsprite_3410:
    subsprite OAM_SIZE_32x32, -16, -19
  Subsprite_3411:
    subsprite OAM_SIZE_32x32, -16, -19
  Subsprite_3412:
    subsprite OAM_SIZE_32x32, -24, -35
    subsprite OAM_SIZE_16x32, 8, -35
    subsprite OAM_SIZE_32x8, -24, -3
    subsprite OAM_SIZE_16x8, 8, -3
  Subsprite_3416:
    subsprite OAM_SIZE_32x32, -24, -35
    subsprite OAM_SIZE_32x16, -24, -3
    subsprite OAM_SIZE_16x32, 8, -35
    subsprite OAM_SIZE_16x16, 8, -3
  Subsprite_3420:
    subsprite OAM_SIZE_32x32, -24, -35
    subsprite OAM_SIZE_32x16, -24, -3
    subsprite OAM_SIZE_16x32, 8, -35
    subsprite OAM_SIZE_16x16, 8, -3
  Subsprite_3424:
    subsprite OAM_SIZE_32x32, -24, -35
    subsprite OAM_SIZE_32x16, -24, -3
    subsprite OAM_SIZE_16x32, 8, -35
    subsprite OAM_SIZE_16x16, 8, -3
  Subsprite_3428:
    subsprite OAM_SIZE_64x32, -32, -35
    subsprite OAM_SIZE_32x16, -32, -3
    subsprite OAM_SIZE_32x16, 0, -3
  Subsprite_3431:
    subsprite OAM_SIZE_32x32, -16, -35
    subsprite OAM_SIZE_32x16, -16, -3
    subsprite OAM_SIZE_8x32, 16, -35
    subsprite OAM_SIZE_8x16, 16, -3
  Subsprite_3435:
    subsprite OAM_SIZE_32x32, -24, -35
    subsprite OAM_SIZE_32x16, -24, -3
    subsprite OAM_SIZE_16x32, 8, -35
    subsprite OAM_SIZE_16x16, 8, -3
  Subsprite_3439:
    subsprite OAM_SIZE_32x32, -24, -35
    subsprite OAM_SIZE_32x16, -24, -3
    subsprite OAM_SIZE_16x32, 8, -35
    subsprite OAM_SIZE_16x16, 8, -3
  Subsprite_3443:
    subsprite OAM_SIZE_32x32, -16, -35
    subsprite OAM_SIZE_32x16, -16, -3
  Subsprite_3445:
    subsprite OAM_SIZE_32x32, -16, -35
    subsprite OAM_SIZE_32x16, -16, -3
  Subsprite_3447:
    subsprite OAM_SIZE_32x32, -16, -19
    subsprite OAM_SIZE_16x16, -8, -35
    subsprite OAM_SIZE_8x8, 8, -27
  Subsprite_3450:
    subsprite OAM_SIZE_32x32, -16, -35
    subsprite OAM_SIZE_32x16, -16, -3
  Subsprite_3452:
    subsprite OAM_SIZE_16x32, -16, -35
    subsprite OAM_SIZE_8x32, 0, -35
    subsprite OAM_SIZE_16x8, -16, -3
    subsprite OAM_SIZE_8x8, 0, -3
  Subsprite_3456:
    subsprite OAM_SIZE_32x32, -24, -35
    subsprite OAM_SIZE_32x16, -24, -3
    subsprite OAM_SIZE_8x32, 8, -35
  Subsprite_3459:
    subsprite OAM_SIZE_16x32, -16, -35
    subsprite OAM_SIZE_8x32, 0, -35
    subsprite OAM_SIZE_16x16, -16, -3
    subsprite OAM_SIZE_8x16, 0, -3
  Subsprite_3463:
    subsprite OAM_SIZE_32x32, -16, -27
    subsprite OAM_SIZE_16x8, -16, -35
    subsprite OAM_SIZE_8x8, 0, -35
  Subsprite_3466:
    subsprite OAM_SIZE_32x32, -16, -27
    subsprite OAM_SIZE_16x16, -8, -43
  Subsprite_3468:
    subsprite OAM_SIZE_32x32, -24, -35
    subsprite OAM_SIZE_32x16, -24, -3
    subsprite OAM_SIZE_8x32, 8, -35
    subsprite OAM_SIZE_8x16, 8, -3
  Subsprite_3472:
    subsprite OAM_SIZE_32x32, -16, -35
    subsprite OAM_SIZE_32x16, -16, -3
  Subsprite_3474:
    subsprite OAM_SIZE_32x32, -16, -35
    subsprite OAM_SIZE_32x16, -16, -3
  Subsprite_3476:
    subsprite OAM_SIZE_32x32, -16, -27
    subsprite OAM_SIZE_16x8, -8, 5
    subsprite OAM_SIZE_8x8, -8, -35
  Subsprite_3479:
    subsprite OAM_SIZE_32x32, -16, -35
    subsprite OAM_SIZE_32x16, -16, -3
  Subsprite_3481:
    subsprite OAM_SIZE_32x32, -16, -35
    subsprite OAM_SIZE_32x16, -16, -3
  Subsprite_3483:
    subsprite OAM_SIZE_32x32, -16, -35
    subsprite OAM_SIZE_32x16, -16, -3
  Subsprite_3485:
    subsprite OAM_SIZE_32x32, -16, -35
    subsprite OAM_SIZE_32x16, -16, -3
  Subsprite_3487:
    subsprite OAM_SIZE_32x32, -16, -35
    subsprite OAM_SIZE_32x16, -16, -3
  Subsprite_3489:
    subsprite OAM_SIZE_32x32, -16, -35
    subsprite OAM_SIZE_32x16, -16, -3
  Subsprite_3491:
    subsprite OAM_SIZE_32x32, -16, -35
    subsprite OAM_SIZE_32x16, -16, -3
  Subsprite_3493:
    subsprite OAM_SIZE_32x32, -16, -35
    subsprite OAM_SIZE_32x16, -16, -3
  Subsprite_3495:
    subsprite OAM_SIZE_32x32, -16, -35
    subsprite OAM_SIZE_32x16, -16, -3
  Subsprite_3497:
    subsprite OAM_SIZE_32x32, -16, -35
    subsprite OAM_SIZE_32x16, -16, -3
  Subsprite_3499:
    subsprite OAM_SIZE_32x32, -16, -35
    subsprite OAM_SIZE_32x16, -16, -3
  Subsprite_3501:
    subsprite OAM_SIZE_32x32, -16, -35
    subsprite OAM_SIZE_32x16, -16, -3
  Subsprite_3503:
    subsprite OAM_SIZE_32x32, -16, -35
    subsprite OAM_SIZE_32x16, -16, -3
  Subsprite_3505:
    subsprite OAM_SIZE_32x32, -16, -35
    subsprite OAM_SIZE_32x16, -16, -3
  Subsprite_3507:
    subsprite OAM_SIZE_32x32, -16, -35
    subsprite OAM_SIZE_32x16, -16, -3
  Subsprite_3509:
    subsprite OAM_SIZE_32x32, -16, -35
    subsprite OAM_SIZE_32x16, -16, -3
  Subsprite_3511:
    subsprite OAM_SIZE_32x32, -16, -35
    subsprite OAM_SIZE_32x16, -16, -3
  Subsprite_3513:
    subsprite OAM_SIZE_32x32, -16, -35
    subsprite OAM_SIZE_32x16, -16, -3
  Subsprite_3515:
    subsprite OAM_SIZE_32x32, -16, -35
    subsprite OAM_SIZE_32x16, -16, -3
  Subsprite_3517:
    subsprite OAM_SIZE_32x32, -16, -35
    subsprite OAM_SIZE_32x16, -16, -3
  Subsprite_3519:
    subsprite OAM_SIZE_32x32, -16, -35
    subsprite OAM_SIZE_32x16, -16, -3
  Subsprite_3521:
    subsprite OAM_SIZE_32x32, -16, -35
    subsprite OAM_SIZE_32x16, -16, -3
  Subsprite_3523:
    subsprite OAM_SIZE_32x32, -16, -35
    subsprite OAM_SIZE_32x8, -16, -3
    subsprite OAM_SIZE_16x8, -8, 5
  Subsprite_3526:
    subsprite OAM_SIZE_32x32, -16, -35
    subsprite OAM_SIZE_32x8, -16, -3
    subsprite OAM_SIZE_16x8, -8, 5
  Subsprite_3529:
    subsprite OAM_SIZE_32x32, -16, -35
    subsprite OAM_SIZE_32x16, -16, -3
  Subsprite_3531:
    subsprite OAM_SIZE_32x32, -16, -35
    subsprite OAM_SIZE_32x8, -16, -3
    subsprite OAM_SIZE_16x8, -8, 5
  Subsprite_3534:
    subsprite OAM_SIZE_32x32, -16, -35
    subsprite OAM_SIZE_32x8, -16, -3
    subsprite OAM_SIZE_16x8, -8, 5
  Subsprite_3537:
    subsprite OAM_SIZE_32x32, -16, -35
    subsprite OAM_SIZE_32x8, -16, -3
    subsprite OAM_SIZE_16x8, -8, 5
  Subsprite_3540:
    subsprite OAM_SIZE_32x32, -16, -35
    subsprite OAM_SIZE_32x8, -16, -3
    subsprite OAM_SIZE_16x8, -8, 5
  Subsprite_3543:
    subsprite OAM_SIZE_32x32, -16, -35
    subsprite OAM_SIZE_32x16, -16, -3
  Subsprite_3545:
    subsprite OAM_SIZE_32x32, -16, -35
    subsprite OAM_SIZE_32x16, -16, -3
  Subsprite_3547:
    subsprite OAM_SIZE_32x32, -16, -27
    subsprite OAM_SIZE_16x8, -16, -35
    subsprite OAM_SIZE_16x8, -8, 5
  Subsprite_3550:
    subsprite OAM_SIZE_32x32, -16, -35
    subsprite OAM_SIZE_32x16, -16, -3
  Subsprite_3552:
    subsprite OAM_SIZE_32x32, -16, -35
    subsprite OAM_SIZE_32x16, -16, -3
  Subsprite_3554:
    subsprite OAM_SIZE_32x32, -16, -35
    subsprite OAM_SIZE_32x16, -16, -3
  Subsprite_3556:
    subsprite OAM_SIZE_32x32, -16, -35
    subsprite OAM_SIZE_32x16, -16, -3
  Subsprite_3558:
    subsprite OAM_SIZE_32x32, -16, -27
    subsprite OAM_SIZE_16x8, -16, -35
    subsprite OAM_SIZE_16x8, -8, 5
  Subsprite_3561:
    subsprite OAM_SIZE_32x32, -16, -27
    subsprite OAM_SIZE_16x8, -16, -35
    subsprite OAM_SIZE_16x8, -8, 5
  Subsprite_3564:
    subsprite OAM_SIZE_32x32, -16, -27
    subsprite OAM_SIZE_16x8, -16, -35
    subsprite OAM_SIZE_16x8, -8, 5
  Subsprite_3567:
    subsprite OAM_SIZE_32x32, -16, -27
    subsprite OAM_SIZE_16x8, -16, -35
    subsprite OAM_SIZE_16x8, -8, 5
  Subsprite_3570:
    subsprite OAM_SIZE_32x32, -16, -27
    subsprite OAM_SIZE_16x8, -16, -35
    subsprite OAM_SIZE_16x8, -8, 5
  Subsprite_3573:
    subsprite OAM_SIZE_32x32, -16, -27
    subsprite OAM_SIZE_16x8, -16, -35
    subsprite OAM_SIZE_16x8, -8, 5
  Subsprite_3576:
    subsprite OAM_SIZE_32x32, -16, -27
    subsprite OAM_SIZE_16x8, -16, -35
    subsprite OAM_SIZE_16x8, -8, 5
  Subsprite_3579:
    subsprite OAM_SIZE_32x32, -16, -27
    subsprite OAM_SIZE_16x8, -16, -35
    subsprite OAM_SIZE_16x8, -8, 5
  Subsprite_3582:
    subsprite OAM_SIZE_32x64, -24, -46
    subsprite OAM_SIZE_16x32, 8, -46
    subsprite OAM_SIZE_16x32, 8, -14
  Subsprite_3585:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_3586:
    subsprite OAM_SIZE_8x8, -4, -4
  Subsprite_3587:
    subsprite OAM_SIZE_32x32, -12, -36
    subsprite OAM_SIZE_32x16, -12, -4
  Subsprite_3589:
    subsprite OAM_SIZE_32x32, -12, -28
    subsprite OAM_SIZE_32x8, -12, 4
  Subsprite_3591:
    subsprite OAM_SIZE_32x32, -20, -28
    subsprite OAM_SIZE_32x8, -20, 4
    subsprite OAM_SIZE_8x32, 12, -28
  Subsprite_3594:
    subsprite OAM_SIZE_32x32, -20, -28
    subsprite OAM_SIZE_32x8, -20, 4
    subsprite OAM_SIZE_8x32, 12, -28
  Subsprite_3597:
    subsprite OAM_SIZE_32x32, -20, -28
    subsprite OAM_SIZE_32x8, -20, 4
    subsprite OAM_SIZE_8x32, 12, -28
  Subsprite_3600:
    subsprite OAM_SIZE_32x32, -20, -28
    subsprite OAM_SIZE_32x8, -20, 4
    subsprite OAM_SIZE_8x32, 12, -28
  Subsprite_3603:
    subsprite OAM_SIZE_16x32, -12, -28
    subsprite OAM_SIZE_8x32, 4, -28
    subsprite OAM_SIZE_16x8, -4, 4
  Subsprite_3606:
    subsprite OAM_SIZE_16x32, -12, -28
    subsprite OAM_SIZE_8x32, 4, -28
    subsprite OAM_SIZE_16x8, -4, 4
  Subsprite_3609:
    subsprite OAM_SIZE_16x32, -12, -28
    subsprite OAM_SIZE_8x32, 4, -28
    subsprite OAM_SIZE_16x8, -4, 4
  Subsprite_3612:
    subsprite OAM_SIZE_32x32, -20, -28
    subsprite OAM_SIZE_32x8, -20, 4
    subsprite OAM_SIZE_8x32, 12, -28
  Subsprite_3615:
    subsprite OAM_SIZE_16x32, -12, -28
    subsprite OAM_SIZE_8x32, 4, -28
    subsprite OAM_SIZE_16x8, -12, 4
  Subsprite_3618:
    subsprite OAM_SIZE_16x32, -12, -28
    subsprite OAM_SIZE_8x32, 4, -28
    subsprite OAM_SIZE_16x8, -12, 4
  Subsprite_3621:
    subsprite OAM_SIZE_16x32, -12, -28
    subsprite OAM_SIZE_8x32, 4, -28
    subsprite OAM_SIZE_16x8, -12, 4
  Subsprite_3624:
    subsprite OAM_SIZE_32x32, -20, -28
    subsprite OAM_SIZE_32x8, -20, 4
    subsprite OAM_SIZE_8x32, 12, -28
  Subsprite_3627:
    subsprite OAM_SIZE_32x32, -20, -28
    subsprite OAM_SIZE_32x8, -20, 4
    subsprite OAM_SIZE_8x32, 12, -28
  Subsprite_3630:
    subsprite OAM_SIZE_32x32, -20, -28
    subsprite OAM_SIZE_32x8, -20, 4
    subsprite OAM_SIZE_8x32, 12, -28
  Subsprite_3633:
    subsprite OAM_SIZE_32x32, -20, -28
    subsprite OAM_SIZE_32x8, -20, 4
    subsprite OAM_SIZE_8x32, 12, -28
  Subsprite_3636:
    subsprite OAM_SIZE_32x32, -20, -28
    subsprite OAM_SIZE_32x8, -20, 4
    subsprite OAM_SIZE_8x32, 12, -28
  Subsprite_3639:
    subsprite OAM_SIZE_32x32, -20, -36
    subsprite OAM_SIZE_32x16, -20, -4
    subsprite OAM_SIZE_8x16, 12, -4
  Subsprite_3642:
    subsprite OAM_SIZE_32x16, -20, -28
    subsprite OAM_SIZE_32x16, -12, -12
    subsprite OAM_SIZE_16x8, -4, 4
  Subsprite_3645:
    subsprite OAM_SIZE_32x32, -20, -20
    subsprite OAM_SIZE_8x32, 12, -20
  Subsprite_3647:
    subsprite OAM_SIZE_32x32, -20, -20
    subsprite OAM_SIZE_8x32, 12, -20
  Subsprite_3649:
    subsprite OAM_SIZE_32x32, -20, -36
    subsprite OAM_SIZE_32x16, -20, -4
    subsprite OAM_SIZE_8x32, 12, -36
  Subsprite_3652:
    subsprite OAM_SIZE_32x16, -12, -28
    subsprite OAM_SIZE_32x16, -20, -12
    subsprite OAM_SIZE_16x8, -12, 4
  Subsprite_3655:
    subsprite OAM_SIZE_32x32, -20, -20
    subsprite OAM_SIZE_8x32, 12, -20
  Subsprite_3657:
    subsprite OAM_SIZE_32x32, -20, -20
    subsprite OAM_SIZE_8x32, 12, -20
  Subsprite_3659:
    subsprite OAM_SIZE_32x32, -12, -28
    subsprite OAM_SIZE_32x8, -12, 4
  Subsprite_3661:
    subsprite OAM_SIZE_32x32, -12, -28
    subsprite OAM_SIZE_32x8, -12, 4
  Subsprite_3663:
    subsprite OAM_SIZE_16x16, -12, -20
    subsprite OAM_SIZE_16x8, -12, -4
    subsprite OAM_SIZE_8x16, 4, -20
    subsprite OAM_SIZE_8x8, 4, -4
  Subsprite_3667:
    subsprite OAM_SIZE_16x16, -12, -20
    subsprite OAM_SIZE_16x8, -12, -4
    subsprite OAM_SIZE_8x16, 4, -20
    subsprite OAM_SIZE_8x8, 4, -4
  Subsprite_3671:
    subsprite OAM_SIZE_16x16, -12, -20
    subsprite OAM_SIZE_16x8, -12, -4
    subsprite OAM_SIZE_8x16, 4, -20
    subsprite OAM_SIZE_8x8, 4, -4
  Subsprite_3675:
    subsprite OAM_SIZE_16x16, -12, -20
    subsprite OAM_SIZE_16x8, -12, -4
    subsprite OAM_SIZE_8x16, 4, -20
    subsprite OAM_SIZE_8x8, 4, -4
  Subsprite_3679:
    subsprite OAM_SIZE_16x16, -12, -20
    subsprite OAM_SIZE_16x8, -12, -4
    subsprite OAM_SIZE_8x16, 4, -20
    subsprite OAM_SIZE_8x8, 4, -4
  Subsprite_3683:
    subsprite OAM_SIZE_16x16, -12, -20
    subsprite OAM_SIZE_16x8, -12, -4
    subsprite OAM_SIZE_8x16, 4, -20
    subsprite OAM_SIZE_8x8, 4, -4
  Subsprite_3687:
    subsprite OAM_SIZE_16x16, -12, -20
    subsprite OAM_SIZE_16x8, -12, -4
    subsprite OAM_SIZE_8x16, 4, -20
    subsprite OAM_SIZE_8x8, 4, -4
  Subsprite_3691:
    subsprite OAM_SIZE_16x16, -12, -20
    subsprite OAM_SIZE_16x8, -12, -4
    subsprite OAM_SIZE_8x16, 4, -20
    subsprite OAM_SIZE_8x8, 4, -4
  Subsprite_3695:
    subsprite OAM_SIZE_16x16, -12, -20
    subsprite OAM_SIZE_16x8, -12, -4
    subsprite OAM_SIZE_8x16, 4, -20
    subsprite OAM_SIZE_8x8, 4, -4
  Subsprite_3699:
    subsprite OAM_SIZE_16x16, -12, -20
    subsprite OAM_SIZE_16x8, -12, -4
    subsprite OAM_SIZE_8x16, 4, -20
    subsprite OAM_SIZE_8x8, 4, -4
  Subsprite_3703:
    subsprite OAM_SIZE_16x16, -12, -20
    subsprite OAM_SIZE_16x8, -12, -4
    subsprite OAM_SIZE_8x16, 4, -20
    subsprite OAM_SIZE_8x8, 4, -4
  Subsprite_3707:
    subsprite OAM_SIZE_16x16, -12, -20
    subsprite OAM_SIZE_16x8, -12, -4
    subsprite OAM_SIZE_8x16, 4, -20
    subsprite OAM_SIZE_8x8, 4, -4
  Subsprite_3711:
    subsprite OAM_SIZE_32x32, -20, -28
    subsprite OAM_SIZE_32x8, -20, 4
    subsprite OAM_SIZE_8x32, 12, -28
  Subsprite_3714:
    subsprite OAM_SIZE_32x32, -20, -28
    subsprite OAM_SIZE_32x8, -20, 4
    subsprite OAM_SIZE_8x32, 12, -28
  Subsprite_3717:
    subsprite OAM_SIZE_32x32, -20, -36
    subsprite OAM_SIZE_32x8, -20, -4
  Subsprite_3719:
    subsprite OAM_SIZE_32x32, -20, -36
    subsprite OAM_SIZE_32x16, -20, -4
  Subsprite_3721:
    subsprite OAM_SIZE_32x32, -20, -28
    subsprite OAM_SIZE_32x8, -20, 4
    subsprite OAM_SIZE_8x32, 12, -28
  Subsprite_3724:
    subsprite OAM_SIZE_32x16, -12, -28
    subsprite OAM_SIZE_32x16, -20, -12
    subsprite OAM_SIZE_8x8, 12, -12
  Subsprite_3727:
    subsprite OAM_SIZE_32x32, -20, -36
    subsprite OAM_SIZE_32x8, -20, -4
    subsprite OAM_SIZE_8x32, 12, -36
  Subsprite_3730:
    subsprite OAM_SIZE_32x32, -16, -32
  Subsprite_3731:
    subsprite OAM_SIZE_32x32, -16, -32
  Subsprite_3732:
    subsprite OAM_SIZE_32x32, -16, -32
  Subsprite_3733:
    subsprite OAM_SIZE_32x32, -16, -32
  Subsprite_3734:
    subsprite OAM_SIZE_32x32, -16, -32
  Subsprite_3735:
    subsprite OAM_SIZE_32x32, -16, -32
  Subsprite_3736:
    subsprite OAM_SIZE_32x32, -16, -32
  Subsprite_3737:
    subsprite OAM_SIZE_32x32, -16, -32
  Subsprite_3738:
    subsprite OAM_SIZE_32x32, -16, -32
  Subsprite_3739:
    subsprite OAM_SIZE_32x32, -16, -32
  Subsprite_3740:
    subsprite OAM_SIZE_32x32, -16, -32
  Subsprite_3741:
    subsprite OAM_SIZE_32x32, -16, -32
  Subsprite_3742:
    subsprite OAM_SIZE_16x16, -8, -24
  Subsprite_3743:
    subsprite OAM_SIZE_16x16, -8, -24
  Subsprite_3744:
    subsprite OAM_SIZE_16x16, -8, -24
  Subsprite_3745:
    subsprite OAM_SIZE_32x32, -16, -20
    subsprite OAM_SIZE_32x8, -16, 12
  Subsprite_3747:
    subsprite OAM_SIZE_32x32, -16, -20
    subsprite OAM_SIZE_32x8, -16, 12
  Subsprite_3749:
    subsprite OAM_SIZE_32x32, -16, -20
  Subsprite_3750:
    subsprite OAM_SIZE_32x32, -16, -20
    subsprite OAM_SIZE_32x8, -16, 12
  Subsprite_3752:
    subsprite OAM_SIZE_32x32, -16, -20
    subsprite OAM_SIZE_32x8, -16, 12
  Subsprite_3754:
    subsprite OAM_SIZE_32x32, -24, -20
    subsprite OAM_SIZE_32x8, -16, 12
    subsprite OAM_SIZE_8x32, 8, -20
  Subsprite_3757:
    subsprite OAM_SIZE_32x32, -24, -20
    subsprite OAM_SIZE_32x16, -24, 12
    subsprite OAM_SIZE_8x32, 8, -20
    subsprite OAM_SIZE_8x16, 8, 12
  Subsprite_3761:
    subsprite OAM_SIZE_32x32, -16, -20
    subsprite OAM_SIZE_32x8, -16, 12
  Subsprite_3763:
    subsprite OAM_SIZE_32x32, -16, -20
    subsprite OAM_SIZE_32x8, -16, 12
  Subsprite_3765:
    subsprite OAM_SIZE_32x32, -16, -20
  Subsprite_3766:
    subsprite OAM_SIZE_32x32, -16, -20
    subsprite OAM_SIZE_32x8, -16, 12
  Subsprite_3768:
    subsprite OAM_SIZE_32x32, -16, -20
    subsprite OAM_SIZE_32x8, -16, 12
  Subsprite_3770:
    subsprite OAM_SIZE_32x32, -24, -20
    subsprite OAM_SIZE_32x8, -16, 12
    subsprite OAM_SIZE_8x32, 8, -20
  Subsprite_3773:
    subsprite OAM_SIZE_32x32, -24, -20
    subsprite OAM_SIZE_32x16, -24, 12
    subsprite OAM_SIZE_8x32, 8, -20
    subsprite OAM_SIZE_8x16, 8, 12
  Subsprite_3777:
    subsprite OAM_SIZE_32x32, -16, -20
    subsprite OAM_SIZE_32x8, -16, 12
  Subsprite_3779:
    subsprite OAM_SIZE_32x32, -16, -20
    subsprite OAM_SIZE_32x8, -16, 12
  Subsprite_3781:
    subsprite OAM_SIZE_32x32, -16, -20
  Subsprite_3782:
    subsprite OAM_SIZE_32x32, -16, -20
    subsprite OAM_SIZE_32x8, -16, 12
  Subsprite_3784:
    subsprite OAM_SIZE_32x32, -16, -20
    subsprite OAM_SIZE_32x8, -16, 12
  Subsprite_3786:
    subsprite OAM_SIZE_32x32, -24, -28
    subsprite OAM_SIZE_32x16, -24, 4
    subsprite OAM_SIZE_8x32, 8, -28
    subsprite OAM_SIZE_8x16, 8, 4
  Subsprite_3790:
    subsprite OAM_SIZE_32x32, -32, -20
    subsprite OAM_SIZE_16x32, 0, -20
    subsprite OAM_SIZE_32x8, -32, 12
    subsprite OAM_SIZE_16x8, 0, 12
  Subsprite_3794:
    subsprite OAM_SIZE_32x32, -16, -20
    subsprite OAM_SIZE_16x8, -8, 12
  Subsprite_3796:
    subsprite OAM_SIZE_32x32, -16, -20
    subsprite OAM_SIZE_32x8, -16, 12
  Subsprite_3798:
    subsprite OAM_SIZE_32x32, -16, -20
    subsprite OAM_SIZE_32x8, -16, 12
  Subsprite_3800:
    subsprite OAM_SIZE_32x32, -16, -20
    subsprite OAM_SIZE_32x8, -16, 12
  Subsprite_3802:
    subsprite OAM_SIZE_32x32, -16, -12
    subsprite OAM_SIZE_16x8, -8, -20
  Subsprite_3804:
    subsprite OAM_SIZE_32x32, -24, -20
    subsprite OAM_SIZE_32x8, -24, 12
    subsprite OAM_SIZE_8x32, 8, -20
  Subsprite_3807:
    subsprite OAM_SIZE_32x32, -32, -20
    subsprite OAM_SIZE_32x16, -32, 12
    subsprite OAM_SIZE_16x32, 0, -20
    subsprite OAM_SIZE_16x16, 0, 12
  Subsprite_3811:
    subsprite OAM_SIZE_32x32, -16, -20
    subsprite OAM_SIZE_16x8, -8, 12
  Subsprite_3813:
    subsprite OAM_SIZE_32x32, -16, -20
    subsprite OAM_SIZE_32x8, -16, 12
  Subsprite_3815:
    subsprite OAM_SIZE_32x32, -16, -20
    subsprite OAM_SIZE_32x8, -16, 12
  Subsprite_3817:
    subsprite OAM_SIZE_32x32, -16, -20
    subsprite OAM_SIZE_32x8, -16, 12
  Subsprite_3819:
    subsprite OAM_SIZE_32x32, -16, -12
    subsprite OAM_SIZE_16x8, -8, -20
  Subsprite_3821:
    subsprite OAM_SIZE_32x32, -24, -20
    subsprite OAM_SIZE_32x8, -24, 12
    subsprite OAM_SIZE_8x32, 8, -20
  Subsprite_3824:
    subsprite OAM_SIZE_32x32, -32, -20
    subsprite OAM_SIZE_32x16, -32, 12
    subsprite OAM_SIZE_16x32, 0, -20
    subsprite OAM_SIZE_16x16, 0, 12
  Subsprite_3828:
    subsprite OAM_SIZE_32x32, -16, -20
    subsprite OAM_SIZE_32x8, -16, 12
    subsprite OAM_SIZE_16x8, -8, -28
  Subsprite_3831:
    subsprite OAM_SIZE_32x32, -16, -20
    subsprite OAM_SIZE_16x8, -8, -28
    subsprite OAM_SIZE_16x8, -8, 12
  Subsprite_3834:
    subsprite OAM_SIZE_32x32, -24, -20
    subsprite OAM_SIZE_16x32, 8, -20
    subsprite OAM_SIZE_32x8, -24, 12
    subsprite OAM_SIZE_16x8, 8, 12
  Subsprite_3838:
    subsprite OAM_SIZE_32x32, -16, -12
    subsprite OAM_SIZE_16x8, -16, -20
    subsprite OAM_SIZE_8x8, 0, -20
  Subsprite_3841:
    subsprite OAM_SIZE_32x32, -16, -20
    subsprite OAM_SIZE_32x8, -16, 12
    subsprite OAM_SIZE_16x8, -8, -28
  Subsprite_3844:
    subsprite OAM_SIZE_32x32, -24, -28
    subsprite OAM_SIZE_32x16, -24, 4
    subsprite OAM_SIZE_8x32, 8, -28
    subsprite OAM_SIZE_8x16, 8, 4
  Subsprite_3848:
    subsprite OAM_SIZE_32x32, -32, -28
    subsprite OAM_SIZE_32x16, -32, 4
    subsprite OAM_SIZE_16x32, 0, -28
    subsprite OAM_SIZE_16x16, 0, 4
  Subsprite_3852:
    subsprite OAM_SIZE_32x32, -16, -20
    subsprite OAM_SIZE_16x8, -8, 12
  Subsprite_3854:
    subsprite OAM_SIZE_32x32, -16, -20
    subsprite OAM_SIZE_32x8, -16, 12
  Subsprite_3856:
    subsprite OAM_SIZE_32x32, -16, -20
    subsprite OAM_SIZE_32x8, -16, 12
  Subsprite_3858:
    subsprite OAM_SIZE_32x32, -16, -20
    subsprite OAM_SIZE_32x8, -16, 12
  Subsprite_3860:
    subsprite OAM_SIZE_32x32, -16, -12
    subsprite OAM_SIZE_16x8, -8, -20
  Subsprite_3862:
    subsprite OAM_SIZE_32x32, -24, -20
    subsprite OAM_SIZE_32x8, -24, 12
    subsprite OAM_SIZE_8x32, 8, -20
  Subsprite_3865:
    subsprite OAM_SIZE_32x32, -32, -20
    subsprite OAM_SIZE_32x16, -32, 12
    subsprite OAM_SIZE_16x32, 0, -20
    subsprite OAM_SIZE_16x16, 0, 12
  Subsprite_3869:
    subsprite OAM_SIZE_32x32, -16, -20
    subsprite OAM_SIZE_32x8, -16, 12
  Subsprite_3871:
    subsprite OAM_SIZE_32x32, -16, -20
    subsprite OAM_SIZE_32x8, -16, 12
    subsprite OAM_SIZE_8x32, 16, -20
  Subsprite_3874:
    subsprite OAM_SIZE_32x16, -24, -12
    subsprite OAM_SIZE_32x8, -24, 4
    subsprite OAM_SIZE_16x16, 8, -12
    subsprite OAM_SIZE_16x8, 8, 4
  Subsprite_3878:
    subsprite OAM_SIZE_32x32, -16, -20
    subsprite OAM_SIZE_32x8, -16, 12
    subsprite OAM_SIZE_8x32, 16, -20
    subsprite OAM_SIZE_8x8, 16, 12
  Subsprite_3882:
    subsprite OAM_SIZE_32x16, -16, -4
    subsprite OAM_SIZE_16x16, -8, -20
    subsprite OAM_SIZE_16x16, -8, 12
  Subsprite_3885:
    subsprite OAM_SIZE_32x32, -16, -12
    subsprite OAM_SIZE_16x16, -8, -28
  Subsprite_3887:
    subsprite OAM_SIZE_32x32, -24, -28
    subsprite OAM_SIZE_32x16, -24, 4
    subsprite OAM_SIZE_16x32, 8, -28
    subsprite OAM_SIZE_16x16, 8, 4
  Subsprite_3891:
    subsprite OAM_SIZE_32x32, -16, -28
    subsprite OAM_SIZE_32x16, -16, 4
  Subsprite_3893:
    subsprite OAM_SIZE_32x32, -16, -20
    subsprite OAM_SIZE_16x8, -8, -28
    subsprite OAM_SIZE_16x8, -8, 12
  Subsprite_3896:
    subsprite OAM_SIZE_32x32, -24, -20
    subsprite OAM_SIZE_16x32, 8, -20
    subsprite OAM_SIZE_32x8, -24, 12
    subsprite OAM_SIZE_16x8, 8, 12
  Subsprite_3900:
    subsprite OAM_SIZE_32x32, -16, -12
    subsprite OAM_SIZE_16x8, -16, -20
    subsprite OAM_SIZE_8x8, 0, -20
  Subsprite_3903:
    subsprite OAM_SIZE_32x32, -16, -20
    subsprite OAM_SIZE_32x8, -16, 12
    subsprite OAM_SIZE_16x8, -8, -28
  Subsprite_3906:
    subsprite OAM_SIZE_32x32, -16, -28
    subsprite OAM_SIZE_32x16, -16, 4
  Subsprite_3908:
    subsprite OAM_SIZE_32x32, -16, -20
    subsprite OAM_SIZE_16x8, -8, -28
    subsprite OAM_SIZE_16x8, -16, 12
  Subsprite_3911:
    subsprite OAM_SIZE_32x32, -24, -20
    subsprite OAM_SIZE_16x32, 8, -20
    subsprite OAM_SIZE_32x8, -24, 12
    subsprite OAM_SIZE_16x8, 8, 12
  Subsprite_3915:
    subsprite OAM_SIZE_32x32, -16, -20
    subsprite OAM_SIZE_32x16, -16, 12
  Subsprite_3917:
    subsprite OAM_SIZE_32x32, -16, -20
    subsprite OAM_SIZE_32x8, -16, 12
    subsprite OAM_SIZE_16x8, -8, -28
  Subsprite_3920:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_3923:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_3926:
    subsprite OAM_SIZE_32x64, -24, -56
    subsprite OAM_SIZE_16x32, 8, -56
    subsprite OAM_SIZE_16x32, 8, -24
  Subsprite_3929:
    subsprite OAM_SIZE_32x64, -24, -56
    subsprite OAM_SIZE_16x32, 8, -56
    subsprite OAM_SIZE_16x32, 8, -24
  Subsprite_3932:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_3933:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_3934:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_3935:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_3936:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_3937:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_3938:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_3939:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_3940:
    subsprite OAM_SIZE_16x16, -12, -16
    subsprite OAM_SIZE_16x8, -12, 0
    subsprite OAM_SIZE_8x16, 4, -16
    subsprite OAM_SIZE_8x8, 4, 0
  Subsprite_3944:
    subsprite OAM_SIZE_16x32, -12, -24
    subsprite OAM_SIZE_8x32, 4, -24
  Subsprite_3946:
    subsprite OAM_SIZE_16x32, -12, -24
    subsprite OAM_SIZE_8x32, 4, -24
  Subsprite_3948:
    subsprite OAM_SIZE_16x32, -12, -24
    subsprite OAM_SIZE_8x32, 4, -24
  Subsprite_3950:
    subsprite OAM_SIZE_16x32, -4, -24
    subsprite OAM_SIZE_8x16, -12, -16
    subsprite OAM_SIZE_8x8, -12, 0
  Subsprite_3953:
    subsprite OAM_SIZE_8x32, 4, -24
    subsprite OAM_SIZE_16x16, -12, -8
    subsprite OAM_SIZE_8x8, -12, -24
  Subsprite_3956:
    subsprite OAM_SIZE_32x32, -16, -21
    subsprite OAM_SIZE_16x16, -8, -37
    subsprite OAM_SIZE_8x16, 8, -37
  Subsprite_3959:
    subsprite OAM_SIZE_32x32, -16, -37
    subsprite OAM_SIZE_32x16, -16, -5
  Subsprite_3961:
    subsprite OAM_SIZE_32x32, -16, -37
    subsprite OAM_SIZE_32x16, -16, -5
  Subsprite_3963:
    subsprite OAM_SIZE_32x32, -16, -37
    subsprite OAM_SIZE_32x16, -16, -5
  Subsprite_3965:
    subsprite OAM_SIZE_32x32, -16, -37
    subsprite OAM_SIZE_32x16, -16, -5
  Subsprite_3967:
    subsprite OAM_SIZE_32x32, -16, -29
    subsprite OAM_SIZE_32x8, -16, 3
  Subsprite_3969:
    subsprite OAM_SIZE_16x32, -8, -29
  Subsprite_3970:
    subsprite OAM_SIZE_16x32, -8, -29
    subsprite OAM_SIZE_8x8, 0, -37
  Subsprite_3972:
    subsprite OAM_SIZE_32x32, -16, -29
    subsprite OAM_SIZE_32x8, -16, 3
    subsprite OAM_SIZE_8x32, 16, -29
  Subsprite_3975:
    subsprite OAM_SIZE_32x32, -16, -37
    subsprite OAM_SIZE_32x16, -16, -5
  Subsprite_3977:
    subsprite OAM_SIZE_32x32, -24, -37
    subsprite OAM_SIZE_32x16, -24, -5
    subsprite OAM_SIZE_16x32, 8, -37
    subsprite OAM_SIZE_16x16, 8, -5
  Subsprite_3981:
    subsprite OAM_SIZE_32x32, -24, -37
    subsprite OAM_SIZE_32x16, -24, -5
    subsprite OAM_SIZE_16x32, 8, -37
    subsprite OAM_SIZE_16x16, 8, -5
  Subsprite_3985:
    subsprite OAM_SIZE_32x32, -24, -37
    subsprite OAM_SIZE_32x16, -24, -5
    subsprite OAM_SIZE_16x32, 8, -37
    subsprite OAM_SIZE_16x16, 8, -5
  Subsprite_3989:
    subsprite OAM_SIZE_32x32, -24, -37
    subsprite OAM_SIZE_32x16, -24, -5
    subsprite OAM_SIZE_8x32, 8, -37
    subsprite OAM_SIZE_8x16, 8, -5
  Subsprite_3993:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_3994:
    subsprite OAM_SIZE_16x16, 0, -16
    subsprite OAM_SIZE_16x8, -8, 0
    subsprite OAM_SIZE_8x8, -8, -8
  Subsprite_3997:
    subsprite OAM_SIZE_16x16, -8, -8
    subsprite OAM_SIZE_8x8, 0, -16
    subsprite OAM_SIZE_8x8, 8, -8
  Subsprite_4000:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_4001:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_4002:
    subsprite OAM_SIZE_16x16, -8, -8
    subsprite OAM_SIZE_16x8, 0, 8
    subsprite OAM_SIZE_8x8, 8, 0
  Subsprite_4005:
    subsprite OAM_SIZE_16x16, -8, -8
    subsprite OAM_SIZE_16x8, 0, 8
    subsprite OAM_SIZE_8x8, 8, 0
  Subsprite_4008:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_4009:
    subsprite OAM_SIZE_32x16, -16, -16
    subsprite OAM_SIZE_32x8, -16, 0
  Subsprite_4011:
    subsprite OAM_SIZE_32x16, -16, -16
    subsprite OAM_SIZE_32x8, -16, 0
  Subsprite_4013:
    subsprite OAM_SIZE_16x16, -8, -16
    subsprite OAM_SIZE_16x8, -8, 0
    subsprite OAM_SIZE_8x8, 8, -8
  Subsprite_4016:
    subsprite OAM_SIZE_32x16, -16, -16
    subsprite OAM_SIZE_32x8, -16, 0
  Subsprite_4018:
    subsprite OAM_SIZE_32x16, -16, -16
    subsprite OAM_SIZE_32x8, -16, 0
  Subsprite_4020:
    subsprite OAM_SIZE_32x16, -16, -16
    subsprite OAM_SIZE_32x8, -16, 0
  Subsprite_4022:
    subsprite OAM_SIZE_16x16, -16, -16
    subsprite OAM_SIZE_16x8, -16, 0
    subsprite OAM_SIZE_8x16, 0, -16
    subsprite OAM_SIZE_8x8, 0, 0
  Subsprite_4026:
    subsprite OAM_SIZE_16x16, -16, -16
    subsprite OAM_SIZE_16x8, -16, 0
    subsprite OAM_SIZE_8x16, 0, -16
    subsprite OAM_SIZE_8x8, 0, 0
  Subsprite_4030:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_4031:
    subsprite OAM_SIZE_16x32, -8, -16
    subsprite OAM_SIZE_8x32, 8, -16
  Subsprite_4033:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_4034:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_4035:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_4036:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_4037:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_4038:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_4039:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_4040:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_4041:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_4042:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_4043:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_4044:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_4045:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_4046:
    subsprite OAM_SIZE_16x32, -16, -16
    subsprite OAM_SIZE_8x32, 0, -16
  Subsprite_4048:
    subsprite OAM_SIZE_16x32, -16, -16
    subsprite OAM_SIZE_8x32, 0, -16
  Subsprite_4050:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_4051:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_4052:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_4053:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_4054:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_4055:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_4056:
    subsprite OAM_SIZE_32x16, -16, -8
    subsprite OAM_SIZE_32x8, -16, 8
    subsprite OAM_SIZE_16x8, -8, -16
  Subsprite_4059:
    subsprite OAM_SIZE_32x16, -16, -8
    subsprite OAM_SIZE_16x8, -8, -16
    subsprite OAM_SIZE_8x8, 0, 8
  Subsprite_4062:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_4063:
    subsprite OAM_SIZE_32x16, -16, -8
    subsprite OAM_SIZE_16x8, -8, -16
    subsprite OAM_SIZE_16x8, -8, 8
  Subsprite_4066:
    subsprite OAM_SIZE_32x16, -16, -8
    subsprite OAM_SIZE_16x8, -8, -16
    subsprite OAM_SIZE_16x8, -8, 8
  Subsprite_4069:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_4070:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_4071:
    subsprite OAM_SIZE_32x16, -16, -8
    subsprite OAM_SIZE_32x8, -16, 8
  Subsprite_4073:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_4074:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_4075:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_4076:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_4077:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_4078:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_4079:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_4080:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_4081:
    subsprite OAM_SIZE_16x32, -8, -16
  Subsprite_4082:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_4083:
    subsprite OAM_SIZE_32x16, -16, -8
    subsprite OAM_SIZE_16x8, -8, -16
    subsprite OAM_SIZE_16x8, 0, 8
  Subsprite_4086:
    subsprite OAM_SIZE_16x32, -16, -16
    subsprite OAM_SIZE_8x32, 0, -16
  Subsprite_4088:
    subsprite OAM_SIZE_32x16, -16, 0
    subsprite OAM_SIZE_16x16, 0, -16
  Subsprite_4090:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_4091:
    subsprite OAM_SIZE_16x32, -8, -16
    subsprite OAM_SIZE_8x16, 8, -16
    subsprite OAM_SIZE_8x8, 8, 0
  Subsprite_4094:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_4095:
    subsprite OAM_SIZE_16x32, -8, -16
    subsprite OAM_SIZE_8x16, 8, -16
    subsprite OAM_SIZE_8x8, 8, 0
  Subsprite_4098:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_4099:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_4100:
    subsprite OAM_SIZE_16x32, -16, -16
    subsprite OAM_SIZE_8x32, 0, -16
  Subsprite_4102:
    subsprite OAM_SIZE_16x32, -16, -16
    subsprite OAM_SIZE_8x32, 0, -16
  Subsprite_4104:
    subsprite OAM_SIZE_16x32, -16, -16
    subsprite OAM_SIZE_8x32, 0, -16
  Subsprite_4106:
    subsprite OAM_SIZE_32x64, -24, -40
  Subsprite_4107:
    subsprite OAM_SIZE_32x64, -32, -48
    subsprite OAM_SIZE_8x32, 0, -48
    subsprite OAM_SIZE_8x32, 0, -16
  Subsprite_4110:
    subsprite OAM_SIZE_32x64, -24, -64
  Subsprite_4111:
    subsprite OAM_SIZE_32x64, -24, -40
  Subsprite_4112:
    subsprite OAM_SIZE_32x32, -24, -40
    subsprite OAM_SIZE_32x8, -24, -8
  Subsprite_4114:
    subsprite OAM_SIZE_16x32, -16, -48
    subsprite OAM_SIZE_8x32, 0, -48
    subsprite OAM_SIZE_16x16, -16, -16
    subsprite OAM_SIZE_8x16, 0, -16
  Subsprite_4118:
    subsprite OAM_SIZE_32x64, -24, -40
  Subsprite_4119:
    subsprite OAM_SIZE_32x32, -24, -40
    subsprite OAM_SIZE_32x8, -24, -8
  Subsprite_4121:
    subsprite OAM_SIZE_16x32, -16, -48
    subsprite OAM_SIZE_8x32, 0, -48
    subsprite OAM_SIZE_16x16, -16, -16
    subsprite OAM_SIZE_8x16, 0, -16
  Subsprite_4125:
    subsprite OAM_SIZE_32x64, -24, -40
  Subsprite_4126:
    subsprite OAM_SIZE_32x64, -32, -48
    subsprite OAM_SIZE_8x32, 0, -48
    subsprite OAM_SIZE_8x32, 0, -16
  Subsprite_4129:
    subsprite OAM_SIZE_32x64, -24, -64
  Subsprite_4130:
    subsprite OAM_SIZE_32x64, -24, -40
  Subsprite_4131:
    subsprite OAM_SIZE_32x64, -32, -48
    subsprite OAM_SIZE_8x32, 0, -48
    subsprite OAM_SIZE_8x32, 0, -16
  Subsprite_4134:
    subsprite OAM_SIZE_32x64, -24, -64
  Subsprite_4135:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_4136:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_4137:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_4138:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_4139:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_4140:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_4141:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_4142:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_4143:
    subsprite OAM_SIZE_32x16, -16, -8
    subsprite OAM_SIZE_16x8, -8, -16
    subsprite OAM_SIZE_16x8, -8, 8
  Subsprite_4146:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_4147:
    subsprite OAM_SIZE_32x16, -16, -8
    subsprite OAM_SIZE_32x8, -16, 8
    subsprite OAM_SIZE_16x8, -8, -16
  Subsprite_4150:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_4151:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_4152:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_4153:
    subsprite OAM_SIZE_32x16, -16, -8
    subsprite OAM_SIZE_32x8, -16, 8
    subsprite OAM_SIZE_16x8, -8, -16
  Subsprite_4156:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_4157:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_4158:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_4159:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_4160:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_4161:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_4162:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_4163:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_4164:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_4165:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_4166:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_4167:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_4168:
    subsprite OAM_SIZE_32x16, -16, -8
    subsprite OAM_SIZE_16x8, -8, -16
    subsprite OAM_SIZE_16x8, -8, 8
  Subsprite_4171:
    subsprite OAM_SIZE_32x16, -16, -8
    subsprite OAM_SIZE_16x8, -8, -16
    subsprite OAM_SIZE_16x8, -8, 8
  Subsprite_4174:
    subsprite OAM_SIZE_32x16, -16, -8
    subsprite OAM_SIZE_16x8, -8, -16
    subsprite OAM_SIZE_16x8, -8, 8
  Subsprite_4177:
    subsprite OAM_SIZE_16x32, -8, -16
    subsprite OAM_SIZE_8x16, -16, -8
    subsprite OAM_SIZE_8x8, 8, 0
  Subsprite_4180:
    subsprite OAM_SIZE_32x16, -16, -8
    subsprite OAM_SIZE_16x8, -8, -16
    subsprite OAM_SIZE_16x8, -8, 8
  Subsprite_4183:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_4184:
    subsprite OAM_SIZE_32x16, -16, 0
    subsprite OAM_SIZE_16x8, -8, -8
    subsprite OAM_SIZE_8x8, 0, -16
  Subsprite_4187:
    subsprite OAM_SIZE_32x16, -16, 0
    subsprite OAM_SIZE_16x8, -8, -8
    subsprite OAM_SIZE_8x8, -8, -16
  Subsprite_4190:
    subsprite OAM_SIZE_32x16, -16, 0
    subsprite OAM_SIZE_16x8, -8, -8
  Subsprite_4192:
    subsprite OAM_SIZE_32x16, -16, 0
    subsprite OAM_SIZE_16x8, -8, -8
  Subsprite_4194:
    subsprite OAM_SIZE_16x16, -8, 0
    subsprite OAM_SIZE_8x8, -8, -8
    subsprite OAM_SIZE_8x8, 8, 8
  Subsprite_4197:
    subsprite OAM_SIZE_16x16, -12, -12
    subsprite OAM_SIZE_8x16, 4, -12
  Subsprite_4199:
    subsprite OAM_SIZE_32x32, -20, -28
    subsprite OAM_SIZE_32x8, -20, 4
  Subsprite_4201:
    subsprite OAM_SIZE_32x32, -20, -36
    subsprite OAM_SIZE_32x16, -20, -4
    subsprite OAM_SIZE_16x32, 12, -36
  Subsprite_4204:
    subsprite OAM_SIZE_32x32, -36, -36
    subsprite OAM_SIZE_32x16, -36, -4
    subsprite OAM_SIZE_16x32, -4, -36
    subsprite OAM_SIZE_16x16, -4, -4
  Subsprite_4208:
    subsprite OAM_SIZE_32x64, -36, -44
    subsprite OAM_SIZE_16x32, -4, -44
    subsprite OAM_SIZE_16x32, -4, -12
  Subsprite_4211:
    subsprite OAM_SIZE_32x64, -20, -44
    subsprite OAM_SIZE_16x32, 12, -44
    subsprite OAM_SIZE_16x32, 12, -12
  Subsprite_4214:
    subsprite OAM_SIZE_16x16, -12, -12
    subsprite OAM_SIZE_8x16, 4, -12
    subsprite OAM_SIZE_8x8, -4, 4
  Subsprite_4217:
    subsprite OAM_SIZE_32x32, -20, -28
    subsprite OAM_SIZE_16x8, -12, 4
    subsprite OAM_SIZE_8x8, 4, 4
  Subsprite_4220:
    subsprite OAM_SIZE_32x32, -12, -36
    subsprite OAM_SIZE_32x16, -12, -4
    subsprite OAM_SIZE_8x32, 20, -36
  Subsprite_4223:
    subsprite OAM_SIZE_32x64, -20, -44
    subsprite OAM_SIZE_16x32, 12, -44
    subsprite OAM_SIZE_16x32, 12, -12
  Subsprite_4226:
    subsprite OAM_SIZE_32x64, -28, -44
    subsprite OAM_SIZE_16x32, 4, -44
    subsprite OAM_SIZE_16x32, 4, -12
  Subsprite_4229:
    subsprite OAM_SIZE_64x64, -36, -44
  Subsprite_4230:
    subsprite OAM_SIZE_32x16, -28, -4
    subsprite OAM_SIZE_32x8, -28, 12
    subsprite OAM_SIZE_8x8, 4, 12
  Subsprite_4233:
    subsprite OAM_SIZE_32x32, -16, -24
    subsprite OAM_SIZE_16x32, 16, -24
    subsprite OAM_SIZE_32x8, -16, 8
    subsprite OAM_SIZE_16x8, 16, 8
  Subsprite_4237:
    subsprite OAM_SIZE_32x32, -16, -24
    subsprite OAM_SIZE_16x32, 16, -24
    subsprite OAM_SIZE_32x8, -16, 8
    subsprite OAM_SIZE_16x8, 16, 8
  Subsprite_4241:
    subsprite OAM_SIZE_32x32, -16, -24
    subsprite OAM_SIZE_32x16, -16, 8
    subsprite OAM_SIZE_16x32, 16, -24
    subsprite OAM_SIZE_16x16, 16, 8
  Subsprite_4245:
    subsprite OAM_SIZE_32x32, -16, -24
    subsprite OAM_SIZE_16x32, 16, -24
    subsprite OAM_SIZE_32x8, -16, 8
    subsprite OAM_SIZE_16x8, 16, 8
  Subsprite_4249:
    subsprite OAM_SIZE_32x32, -16, -24
    subsprite OAM_SIZE_16x32, 16, -24
    subsprite OAM_SIZE_32x8, -16, 8
    subsprite OAM_SIZE_16x8, 16, 8
  Subsprite_4253:
    subsprite OAM_SIZE_32x32, -16, -24
    subsprite OAM_SIZE_32x16, -16, 8
    subsprite OAM_SIZE_16x32, 16, -24
    subsprite OAM_SIZE_16x16, 16, 8
  Subsprite_4257:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_4258:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_4259:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_4260:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_4261:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_4262:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_4263:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_4264:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_4265:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_4266:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_4267:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_4268:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_4269:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_4270:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_4271:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_4272:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_4273:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_4274:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_4275:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_4276:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_4277:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_4278:
    subsprite OAM_SIZE_8x8, -4, -4
  Subsprite_4279:
    subsprite OAM_SIZE_8x8, -4, -4
  Subsprite_4280:
    subsprite OAM_SIZE_8x8, -4, -4
  Subsprite_4281:
    subsprite OAM_SIZE_8x8, -4, -4
  Subsprite_4282:
    subsprite OAM_SIZE_8x8, -4, -4
  Subsprite_4283:
    subsprite OAM_SIZE_8x8, -4, -4
  Subsprite_4284:
    subsprite OAM_SIZE_8x8, -4, -4
  Subsprite_4285:
    subsprite OAM_SIZE_8x8, -4, -4
  Subsprite_4286:
    subsprite OAM_SIZE_8x8, -4, -4
  Subsprite_4287:
    subsprite OAM_SIZE_8x8, -4, -4
  Subsprite_4288:
    subsprite OAM_SIZE_8x8, -4, -4
  Subsprite_4289:
    subsprite OAM_SIZE_8x8, -4, -4
  Subsprite_4290:
    subsprite OAM_SIZE_8x8, -4, -4
  Subsprite_4291:
    subsprite OAM_SIZE_8x8, -4, -4
  Subsprite_4292:
    subsprite OAM_SIZE_32x64, -24, -46
    subsprite OAM_SIZE_16x32, 8, -46
    subsprite OAM_SIZE_16x32, 8, -14
  Subsprite_4295:
    subsprite OAM_SIZE_32x16, -16, -8
    subsprite OAM_SIZE_16x8, -8, -16
    subsprite OAM_SIZE_16x8, -8, 8
  Subsprite_4298:
    subsprite OAM_SIZE_8x8, -4, -4
  Subsprite_4299:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_4302:
    subsprite OAM_SIZE_8x8, -24, -8
  Subsprite_4303:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_4306:
    subsprite OAM_SIZE_32x32, -24, -32
    subsprite OAM_SIZE_32x16, -24, 0
    subsprite OAM_SIZE_8x32, 8, -32
    subsprite OAM_SIZE_8x16, 8, 0
  Subsprite_4310:
    subsprite OAM_SIZE_32x32, -16, -32
    subsprite OAM_SIZE_32x16, -16, 0
    subsprite OAM_SIZE_8x32, 16, -32
    subsprite OAM_SIZE_8x16, 16, 0
  Subsprite_4314:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_4317:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_4320:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_4323:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_4326:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_4329:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_4332:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_4335:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_4338:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_4341:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_4344:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_4347:
    subsprite OAM_SIZE_32x64, -24, -46
    subsprite OAM_SIZE_16x32, 8, -46
    subsprite OAM_SIZE_16x32, 8, -14
  Subsprite_4350:
    subsprite OAM_SIZE_32x64, -24, -46
    subsprite OAM_SIZE_16x32, 8, -46
    subsprite OAM_SIZE_16x32, 8, -14
  Subsprite_4353:
    subsprite OAM_SIZE_32x32, -24, -38
    subsprite OAM_SIZE_32x16, -24, -6
    subsprite OAM_SIZE_16x32, 8, -38
    subsprite OAM_SIZE_16x16, 8, -6
  Subsprite_4357:
    subsprite OAM_SIZE_32x16, -16, -22
    subsprite OAM_SIZE_16x8, -8, -30
    subsprite OAM_SIZE_16x8, -8, -6
  Subsprite_4360:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_4363:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_4366:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_4369:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_4372:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_4375:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_4378:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_4381:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_4384:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_4387:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_4390:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_4393:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_4396:
    subsprite OAM_SIZE_8x8, 0, 8
  Subsprite_4397:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_4400:
    subsprite OAM_SIZE_32x32, -24, -24
    subsprite OAM_SIZE_32x16, -24, 8
    subsprite OAM_SIZE_16x32, 8, -24
    subsprite OAM_SIZE_16x16, 8, 8
  Subsprite_4404:
    subsprite OAM_SIZE_16x16, -8, -8
    subsprite OAM_SIZE_8x8, -8, -16
  Subsprite_4406:
    subsprite OAM_SIZE_16x16, -8, -8
    subsprite OAM_SIZE_8x8, 0, -16
  Subsprite_4408:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_4409:
    subsprite OAM_SIZE_16x16, -8, -8
    subsprite OAM_SIZE_8x8, 8, 0
  Subsprite_4411:
    subsprite OAM_SIZE_16x16, -8, -8
    subsprite OAM_SIZE_8x8, 0, -16
  Subsprite_4413:
    subsprite OAM_SIZE_16x16, -8, -8
    subsprite OAM_SIZE_8x8, 0, 8
  Subsprite_4415:
    subsprite OAM_SIZE_16x16, -8, -8
    subsprite OAM_SIZE_8x8, 8, 0
    subsprite OAM_SIZE_8x8, -8, 8
  Subsprite_4418:
    subsprite OAM_SIZE_16x16, -8, -8
    subsprite OAM_SIZE_8x8, 8, -8
  Subsprite_4420:
    subsprite OAM_SIZE_16x16, -8, -8
    subsprite OAM_SIZE_8x8, -8, -16
  Subsprite_4422:
    subsprite OAM_SIZE_16x16, -8, -16
    subsprite OAM_SIZE_16x8, -8, 0
  Subsprite_4424:
    subsprite OAM_SIZE_16x16, -8, 0
    subsprite OAM_SIZE_8x8, 0, -8
  Subsprite_4426:
    subsprite OAM_SIZE_16x16, -8, 0
    subsprite OAM_SIZE_8x8, 0, -8
  Subsprite_4428:
    subsprite OAM_SIZE_16x16, -8, 0
    subsprite OAM_SIZE_8x8, 0, -8
  Subsprite_4430:
    subsprite OAM_SIZE_16x16, -8, 0
    subsprite OAM_SIZE_8x8, 0, -8
  Subsprite_4432:
    subsprite OAM_SIZE_16x16, -8, 0
    subsprite OAM_SIZE_8x8, 0, -8
  Subsprite_4434:
    subsprite OAM_SIZE_16x16, -8, 0
    subsprite OAM_SIZE_8x8, 0, -8
  Subsprite_4436:
    subsprite OAM_SIZE_32x64, -47, -55
    subsprite OAM_SIZE_16x32, -15, -55
  Subsprite_4438:
    subsprite OAM_SIZE_16x32, -8, -16
    subsprite OAM_SIZE_8x8, -16, -8
  Subsprite_4440:
    subsprite OAM_SIZE_32x16, -16, -8
  Subsprite_4441:
    subsprite OAM_SIZE_32x16, -16, -8
  Subsprite_4442:
    subsprite OAM_SIZE_32x16, -16, -8
  Subsprite_4443:
    subsprite OAM_SIZE_32x16, -16, -8
  Subsprite_4444:
    subsprite OAM_SIZE_32x16, -16, -8
  Subsprite_4445:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_4446:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_4447:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_4448:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_4449:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_4450:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_4451:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_4452:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_4453:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_4454:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_4455:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_4456:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_4457:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_4458:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_4459:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_4460:
    subsprite OAM_SIZE_16x16, -8, -8
  Subsprite_4461:
    subsprite OAM_SIZE_32x32, -24, 0
    subsprite OAM_SIZE_32x16, -24, 32
    subsprite OAM_SIZE_16x32, 8, 0
    subsprite OAM_SIZE_16x16, 8, 32
  Subsprite_4465:
    subsprite OAM_SIZE_32x32, -24, 0
    subsprite OAM_SIZE_32x16, -24, 32
    subsprite OAM_SIZE_16x32, 8, 0
    subsprite OAM_SIZE_16x16, 8, 32
  Subsprite_4469:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_4470:
    subsprite OAM_SIZE_32x32, -24, -16
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_4472:
    subsprite OAM_SIZE_32x32, -24, -16
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_4474:
    subsprite OAM_SIZE_32x32, 0, 0
    subsprite OAM_SIZE_32x16, 0, 32
    subsprite OAM_SIZE_16x32, 32, 0
    subsprite OAM_SIZE_16x16, 32, 32
  Subsprite_4478:
    subsprite OAM_SIZE_32x32, 0, 0
    subsprite OAM_SIZE_32x16, 0, 32
    subsprite OAM_SIZE_16x32, 32, 0
    subsprite OAM_SIZE_16x16, 32, 32
  Subsprite_4482:
    subsprite OAM_SIZE_32x32, 0, 0
    subsprite OAM_SIZE_32x16, 0, 32
    subsprite OAM_SIZE_16x32, 32, 0
    subsprite OAM_SIZE_16x16, 32, 32
  Subsprite_4486:
    subsprite OAM_SIZE_32x32, 0, 0
    subsprite OAM_SIZE_32x16, 0, 32
    subsprite OAM_SIZE_16x32, 32, 0
    subsprite OAM_SIZE_16x16, 32, 32
  Subsprite_4490:
    subsprite OAM_SIZE_32x16, -16, 8
    subsprite OAM_SIZE_16x8, -8, 0
    subsprite OAM_SIZE_16x8, -8, 24
  Subsprite_4493:
    subsprite OAM_SIZE_32x16, -16, 8
    subsprite OAM_SIZE_16x8, -8, 0
    subsprite OAM_SIZE_16x8, -8, 24
  Subsprite_4496:
    subsprite OAM_SIZE_32x16, -16, 8
    subsprite OAM_SIZE_16x8, -8, 0
    subsprite OAM_SIZE_16x8, -8, 24
  Subsprite_4499:
    subsprite OAM_SIZE_32x16, -16, 8
    subsprite OAM_SIZE_16x8, -8, 0
    subsprite OAM_SIZE_16x8, -8, 24
  Subsprite_4502:
    subsprite OAM_SIZE_32x16, -16, 8
    subsprite OAM_SIZE_16x8, -8, 0
    subsprite OAM_SIZE_16x8, -8, 24
  Subsprite_4505:
    subsprite OAM_SIZE_32x16, -16, 8
    subsprite OAM_SIZE_16x8, -8, 0
    subsprite OAM_SIZE_16x8, -8, 24
  Subsprite_4508:
    subsprite OAM_SIZE_32x16, -16, 8
    subsprite OAM_SIZE_16x8, -8, 0
    subsprite OAM_SIZE_16x8, -8, 24
  Subsprite_4511:
    subsprite OAM_SIZE_32x16, -16, 8
    subsprite OAM_SIZE_16x8, -8, 0
    subsprite OAM_SIZE_16x8, -8, 24
  Subsprite_4514:
    subsprite OAM_SIZE_32x16, -16, 8
    subsprite OAM_SIZE_16x8, -8, 0
    subsprite OAM_SIZE_16x8, -8, 24
  Subsprite_4517:
    subsprite OAM_SIZE_32x16, -16, 8
    subsprite OAM_SIZE_16x8, -8, 0
    subsprite OAM_SIZE_16x8, -8, 24
  Subsprite_4520:
    subsprite OAM_SIZE_32x16, -16, 8
    subsprite OAM_SIZE_16x8, -8, 0
    subsprite OAM_SIZE_16x8, -8, 24
  Subsprite_4523:
    subsprite OAM_SIZE_32x16, -16, 8
    subsprite OAM_SIZE_16x8, -8, 0
    subsprite OAM_SIZE_16x8, -8, 24
  Subsprite_4526:
    subsprite OAM_SIZE_32x16, -16, 8
    subsprite OAM_SIZE_16x8, -8, 0
    subsprite OAM_SIZE_16x8, -8, 24
  Subsprite_4529:
    subsprite OAM_SIZE_32x64, -19, -28
  Subsprite_4530:
    subsprite OAM_SIZE_32x64, -19, -28
  Subsprite_4531:
    subsprite OAM_SIZE_32x64, -19, -28
  Subsprite_4532:
    subsprite OAM_SIZE_32x64, -19, -28
  Subsprite_4533:
    subsprite OAM_SIZE_32x64, -32, -40
    subsprite OAM_SIZE_8x32, 0, -40
    subsprite OAM_SIZE_8x32, 0, -8
  Subsprite_4536:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_4537:
    subsprite OAM_SIZE_8x8, -4, -4
  Subsprite_4538:
    subsprite OAM_SIZE_32x16, -16, -19
    subsprite OAM_SIZE_16x16, -8, -35
    subsprite OAM_SIZE_16x8, -8, -3
  Subsprite_4541:
    subsprite OAM_SIZE_32x16, -16, -19
    subsprite OAM_SIZE_16x16, -8, -35
    subsprite OAM_SIZE_16x8, -8, -3
  Subsprite_4544:
    subsprite OAM_SIZE_16x32, -8, -35
    subsprite OAM_SIZE_16x8, -8, -3
    subsprite OAM_SIZE_8x16, 8, -19
  Subsprite_4547:
    subsprite OAM_SIZE_16x32, -16, -35
    subsprite OAM_SIZE_8x32, 0, -35
    subsprite OAM_SIZE_16x8, -16, -3
    subsprite OAM_SIZE_8x8, 0, -3
  Subsprite_4551:
    subsprite OAM_SIZE_16x32, -8, -35
    subsprite OAM_SIZE_16x8, -8, -3
    subsprite OAM_SIZE_8x16, -16, -19
  Subsprite_4554:
    subsprite OAM_SIZE_8x16, 16, 0
  Subsprite_4555:
    subsprite OAM_SIZE_16x16, 16, 0
  Subsprite_4556:
    subsprite OAM_SIZE_8x8, 24, 0
  Subsprite_4557:
    subsprite OAM_SIZE_16x32, 24, 8
    subsprite OAM_SIZE_8x32, 40, 8
  Subsprite_4559:
    subsprite OAM_SIZE_32x32, 24, 8
    subsprite OAM_SIZE_32x16, 24, 40
    subsprite OAM_SIZE_8x32, 56, 8
    subsprite OAM_SIZE_8x16, 56, 40
  Subsprite_4563:
    subsprite OAM_SIZE_64x32, 24, 8
    subsprite OAM_SIZE_32x16, 24, 40
    subsprite OAM_SIZE_32x16, 56, 40
  Subsprite_4566:
    subsprite OAM_SIZE_64x64, 24, 8
  Subsprite_4567:
    subsprite OAM_SIZE_64x64, 24, 0
  Subsprite_4568:
    subsprite OAM_SIZE_64x64, 24, 0
  Subsprite_4569:
    subsprite OAM_SIZE_64x64, 32, -8
    subsprite OAM_SIZE_32x8, 64, 56
  Subsprite_4571:
    subsprite OAM_SIZE_16x8, 16, -24
    subsprite OAM_SIZE_8x16, 24, -40
  Subsprite_4573:
    subsprite OAM_SIZE_8x16, 24, -40
  Subsprite_4574:
    subsprite OAM_SIZE_8x8, 16, -24
  Subsprite_4575:
    subsprite OAM_SIZE_32x32, 16, -48
  Subsprite_4576:
    subsprite OAM_SIZE_32x32, 24, -64
    subsprite OAM_SIZE_32x16, 24, -32
    subsprite OAM_SIZE_8x32, 56, -64
  Subsprite_4579:
    subsprite OAM_SIZE_32x32, 24, -72
    subsprite OAM_SIZE_32x16, 24, -40
    subsprite OAM_SIZE_16x32, 56, -72
  Subsprite_4582:
    subsprite OAM_SIZE_32x64, 24, -88
    subsprite OAM_SIZE_16x32, 56, -88
    subsprite OAM_SIZE_16x32, 56, -56
  Subsprite_4585:
    subsprite OAM_SIZE_32x64, 24, -88
    subsprite OAM_SIZE_16x32, 56, -88
    subsprite OAM_SIZE_16x32, 56, -56
  Subsprite_4588:
    subsprite OAM_SIZE_64x64, 24, -96
    subsprite OAM_SIZE_32x8, 24, -32
  Subsprite_4590:
    subsprite OAM_SIZE_64x64, 24, -96
    subsprite OAM_SIZE_32x8, 24, -32
  Subsprite_4592:
    subsprite OAM_SIZE_32x16, -16, -8
    subsprite OAM_SIZE_32x8, -16, 8
  Subsprite_4594:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_4595:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_4596:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_4597:
    subsprite OAM_SIZE_32x16, -16, -16
    subsprite OAM_SIZE_32x8, -16, 0
    subsprite OAM_SIZE_16x8, -8, 8
  Subsprite_4600:
    subsprite OAM_SIZE_32x32, -16, -16
  Subsprite_4601:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_4604:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_4607:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_4610:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_4613:
    subsprite OAM_SIZE_32x32, -24, -48
    subsprite OAM_SIZE_32x16, -24, -16
    subsprite OAM_SIZE_8x16, 8, -16
  Subsprite_4616:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_4619:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_4622:
    subsprite OAM_SIZE_32x64, -24, -48
    subsprite OAM_SIZE_16x32, 8, -48
    subsprite OAM_SIZE_16x32, 8, -16
  Subsprite_4625:
    subsprite OAM_SIZE_32x32, -17, -19
  Subsprite_4626:
    subsprite OAM_SIZE_32x32, -17, -27
    subsprite OAM_SIZE_32x8, -17, 5
  Subsprite_4628:
    subsprite OAM_SIZE_32x32, -17, -35
    subsprite OAM_SIZE_32x16, -17, -3
  Subsprite_4630:
    subsprite OAM_SIZE_32x32, -17, -27
    subsprite OAM_SIZE_32x8, -17, 5
  Subsprite_4632:
    subsprite OAM_SIZE_32x32, -17, -19
  Subsprite_4633:
    subsprite OAM_SIZE_32x16, -17, -11
    subsprite OAM_SIZE_16x8, -9, -19
    subsprite OAM_SIZE_16x8, -9, 5
  Subsprite_4636:
    subsprite OAM_SIZE_32x32, -17, -27
    subsprite OAM_SIZE_32x8, -17, 5
  Subsprite_4638:
    subsprite OAM_SIZE_32x32, -17, -27
    subsprite OAM_SIZE_32x8, -17, 5
    subsprite OAM_SIZE_8x8, 0, 0
