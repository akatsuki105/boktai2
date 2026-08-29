SpriteSetFile30: @ 0x08C9AA0C
	.2byte 741 @ palStart
	.2byte 18 @ metaspriteCount
	.2byte 11 @ unk1Count
	.2byte 136 @ subspriteCount
	.2byte 19 @ unk2Count
	.2byte 256 @ tileCount
	.4byte 0x00000020, 0x00000188, 0x000001E0, 0x00000620, 0x0000066C
	@ Metasprites
		.2byte 0xF551, 0x0006, 0x0000, 0x0000, 0xFFE4, 0xFFD6, 0x000C, 0x0006
		.4byte 0x0 @ subspriteOffset
		.2byte 0xF571, 0x0007, 0x0000, 0x0000, 0xFFE8, 0xFFD6, 0x0008, 0x0006
		.4byte 0x30 @ subspriteOffset
		.2byte 0xF591, 0x0007, 0x0000, 0x0000, 0xFFE5, 0xFFD6, 0x0008, 0x0000
		.4byte 0x68 @ subspriteOffset
		.2byte 0xF5B1, 0x0008, 0x0000, 0x0000, 0xFFE8, 0xFFD5, 0x0009, 0x0006
		.4byte 0xA0 @ subspriteOffset
		.2byte 0xF5D1, 0x0009, 0x0000, 0x0000, 0xFFE0, 0xFFD5, 0x0010, 0x0000
		.4byte 0xE0 @ subspriteOffset
		.2byte 0xF381, 0x0009, 0x0000, 0x0000, 0xFFE7, 0xFFD4, 0x0011, 0x000C
		.4byte 0x128 @ subspriteOffset
		.2byte 0xF382, 0x0008, 0x0000, 0x0000, 0xFFE7, 0xFFD6, 0x000F, 0x000D
		.4byte 0x170 @ subspriteOffset
		.2byte 0xF383, 0x0009, 0x0000, 0x0000, 0xFFE7, 0xFFD4, 0x000F, 0x000C
		.4byte 0x1B0 @ subspriteOffset
		.2byte 0xF384, 0x0007, 0x0000, 0x0000, 0xFFE7, 0xFFD6, 0x000F, 0x0006
		.4byte 0x1F8 @ subspriteOffset
		.2byte 0xF3C1, 0x0008, 0x0000, 0x0000, 0xFFE7, 0xFFD5, 0x000F, 0x0000
		.4byte 0x230 @ subspriteOffset
		.2byte 0xF3C2, 0x0008, 0x0000, 0x0000, 0xFFE6, 0xFFD6, 0x0010, 0x0005
		.4byte 0x270 @ subspriteOffset
		.2byte 0xF3C3, 0x0008, 0x0000, 0x0000, 0xFFE7, 0xFFD5, 0x000F, 0x0005
		.4byte 0x2B0 @ subspriteOffset
		.2byte 0xF3C4, 0x0009, 0x0000, 0x0000, 0xFFE8, 0xFFD6, 0x0010, 0x0004
		.4byte 0x2F0 @ subspriteOffset
		.2byte 0xDF61, 0x0008, 0x0000, 0x0000, 0xFFE8, 0xFFD5, 0x0009, 0x0006
		.4byte 0x338 @ subspriteOffset
		.2byte 0xDF81, 0x0007, 0x0000, 0x0000, 0xFFE6, 0xFFD6, 0x000A, 0x0006
		.4byte 0x378 @ subspriteOffset
		.2byte 0xDFA1, 0x0008, 0x0000, 0x0000, 0xFFE8, 0xFFD6, 0x000A, 0x0006
		.4byte 0x3B0 @ subspriteOffset
		.2byte 0xD5B5, 0x0002, 0x0000, 0x0000, 0xFFE8, 0xFFDE, 0x0008, 0x000E
		.4byte 0x3F0 @ subspriteOffset
		.2byte 0xD502, 0x0008, 0x0000, 0x0000, 0xFFE8, 0xFFD5, 0x0009, 0x0006
		.4byte 0x400 @ subspriteOffset
	@ Unk1
		.byte 0x52, 0xB1, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00
		.byte 0x72, 0xB1, 0x01, 0x00, 0x04, 0x00, 0x00, 0x00
		.byte 0x92, 0xB1, 0x01, 0x00, 0x08, 0x00, 0x00, 0x00
		.byte 0xB2, 0xB1, 0x01, 0x00, 0x0C, 0x00, 0x00, 0x00
		.byte 0xD2, 0xB1, 0x01, 0x00, 0x10, 0x00, 0x00, 0x00
		.byte 0x89, 0x2F, 0x04, 0x00, 0x14, 0x00, 0x00, 0x00
		.byte 0xC9, 0x2F, 0x04, 0x00, 0x24, 0x00, 0x00, 0x00
		.byte 0x56, 0x87, 0x03, 0x00, 0x34, 0x00, 0x00, 0x00
		.byte 0x36, 0x87, 0x01, 0x00, 0x40, 0x00, 0x00, 0x00
		.byte 0x09, 0x27, 0x01, 0x00, 0x44, 0x00, 0x00, 0x00
		.byte 0x03, 0x8F, 0x01, 0x00, 0x48, 0x00, 0x00, 0x00
	@ Subsprites
		.byte 0x00, 0x02 @ flip, shape
		.2byte -4, -12, (48 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x04 @ flip, shape
		.2byte -8, -16, (58 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x04 @ flip, shape
		.2byte -12, -26, (0 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x02 @ flip, shape
		.2byte 4, -26, (2 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x01 @ flip, shape
		.2byte -12, -10, (32 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x00 @ flip, shape
		.2byte 4, -10, (34 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x02 @ flip, shape
		.2byte -4, -12, (52 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x00 @ flip, shape
		.2byte -8, -17, (15 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x04 @ flip, shape
		.2byte -8, -16, (60 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x02 @ flip, shape
		.2byte 0, -17, (85 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x04 @ flip, shape
		.2byte -8, -26, (4 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x01 @ flip, shape
		.2byte -8, -10, (36 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x02 @ flip, shape
		.2byte -16, -18, (19 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x02 @ flip, shape
		.2byte -4, -12, (51 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x04 @ flip, shape
		.2byte -8, -16, (62 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x04 @ flip, shape
		.2byte -11, -26, (6 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x00 @ flip, shape
		.2byte -3, -10, (39 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x00 @ flip, shape
		.2byte -11, -10, (38 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x02 @ flip, shape
		.2byte -1, -25, (53 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x02 @ flip, shape
		.2byte -4, -16, (84 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x02 @ flip, shape
		.2byte -4, -12, (50 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x00 @ flip, shape
		.2byte -1, -14, (15 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x04 @ flip, shape
		.2byte -8, -26, (9 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x02 @ flip, shape
		.2byte -16, -18, (24 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x01 @ flip, shape
		.2byte -8, -10, (41 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x04 @ flip, shape
		.2byte -8, -16, (80 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x04 @ flip, shape
		.2byte -7, -27, (56 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x02 @ flip, shape
		.2byte -8, -18, (31 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x04, 0x04 @ flip, shape
		.2byte 0, -26, (12 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x04 @ flip, shape
		.2byte -16, -26, (12 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x04, 0x00 @ flip, shape
		.2byte 0, -10, (45 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x00 @ flip, shape
		.2byte -8, -10, (45 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x02 @ flip, shape
		.2byte -4, -12, (49 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x04 @ flip, shape
		.2byte -8, -16, (82 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x02 @ flip, shape
		.2byte -10, -17, (87 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x02 @ flip, shape
		.2byte 1, -17, (86 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x04 @ flip, shape
		.2byte -8, -27, (54 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x00 @ flip, shape
		.2byte -9, -16, (112 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x04 @ flip, shape
		.2byte -8, -10, (88 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x04 @ flip, shape
		.2byte -7, -20, (196 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x01 @ flip, shape
		.2byte 1, -15, (153 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x01 @ flip, shape
		.2byte -7, -4, (170 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x04 @ flip, shape
		.2byte -9, -28, (116 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x02 @ flip, shape
		.2byte 7, -28, (118 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x01 @ flip, shape
		.2byte -9, -12, (148 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x00 @ flip, shape
		.2byte 7, -12, (150 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x04 @ flip, shape
		.2byte -8, -10, (90 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x00 @ flip, shape
		.2byte -7, -16, (113 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x04 @ flip, shape
		.2byte -7, -19, (198 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x01 @ flip, shape
		.2byte -7, -3, (172 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x00 @ flip, shape
		.2byte 3, -13, (155 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x04 @ flip, shape
		.2byte -9, -26, (119 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x02 @ flip, shape
		.2byte 7, -26, (121 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x01 @ flip, shape
		.2byte -9, -10, (151 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x04 @ flip, shape
		.2byte -8, -10, (92 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x00 @ flip, shape
		.2byte -5, -18, (114 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x04 @ flip, shape
		.2byte -6, -20, (200 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x01 @ flip, shape
		.2byte -6, -4, (174 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x00 @ flip, shape
		.2byte 0, -11, (156 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x04 @ flip, shape
		.2byte -9, -28, (116 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x02 @ flip, shape
		.2byte 7, -28, (118 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x01 @ flip, shape
		.2byte -9, -12, (148 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x00 @ flip, shape
		.2byte 7, -12, (150 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x04 @ flip, shape
		.2byte -8, -10, (94 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x00 @ flip, shape
		.2byte -6, -16, (115 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x04 @ flip, shape
		.2byte -7, -16, (232 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x00 @ flip, shape
		.2byte 2, -13, (131 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x04 @ flip, shape
		.2byte -9, -26, (119 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x02 @ flip, shape
		.2byte 7, -26, (121 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x01 @ flip, shape
		.2byte -9, -10, (151 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x02 @ flip, shape
		.2byte -3, -9, (122 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x00 @ flip, shape
		.2byte 3, -15, (144 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x04 @ flip, shape
		.2byte -9, -26, (167 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x00 @ flip, shape
		.2byte -9, -10, (182 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x02 @ flip, shape
		.2byte 7, -26, (169 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x04 @ flip, shape
		.2byte -8, -16, (224 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x00 @ flip, shape
		.2byte -6, -13, (234 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x04 @ flip, shape
		.2byte -4, -27, (56 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x04 @ flip, shape
		.2byte -8, -26, (164 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x04 @ flip, shape
		.2byte -10, -11, (123 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x00 @ flip, shape
		.2byte 2, -15, (145 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x04 @ flip, shape
		.2byte -7, -16, (226 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x02 @ flip, shape
		.2byte 0, -24, (194 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x00 @ flip, shape
		.2byte 8, -24, (195 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x00 @ flip, shape
		.2byte -6, -12, (235 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x00 @ flip, shape
		.2byte -4, -4, (206 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x04 @ flip, shape
		.2byte -9, -26, (167 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x00 @ flip, shape
		.2byte -9, -10, (182 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x00 @ flip, shape
		.2byte 7, -26, (169 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x04 @ flip, shape
		.2byte -8, -11, (125 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x00 @ flip, shape
		.2byte 0, -16, (146 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x04 @ flip, shape
		.2byte -6, -17, (228 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x04 @ flip, shape
		.2byte -4, -27, (56 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x00 @ flip, shape
		.2byte -3, -13, (250 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x04 @ flip, shape
		.2byte -8, -26, (164 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x00 @ flip, shape
		.2byte 8, -26, (166 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x02 @ flip, shape
		.2byte -3, -11, (127 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x00 @ flip, shape
		.2byte 2, -15, (147 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x04 @ flip, shape
		.2byte -7, -16, (230 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x02 @ flip, shape
		.2byte 0, -24, (194 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x00 @ flip, shape
		.2byte 8, -24, (195 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x00 @ flip, shape
		.2byte -5, -12, (251 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x00 @ flip, shape
		.2byte -4, -4, (206 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x02 @ flip, shape
		.2byte -4, -12, (50 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x04 @ flip, shape
		.2byte -8, -26, (9 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x00 @ flip, shape
		.2byte -1, -14, (15 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x02 @ flip, shape
		.2byte -16, -18, (24 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x01 @ flip, shape
		.2byte -8, -10, (41 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x04 @ flip, shape
		.2byte -8, -16, (80 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x04 @ flip, shape
		.2byte -7, -27, (56 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x02 @ flip, shape
		.2byte -8, -16, (84 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x00 @ flip, shape
		.2byte -1, -14, (11 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x04 @ flip, shape
		.2byte -10, -26, (220 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x01 @ flip, shape
		.2byte -10, -10, (252 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x02 @ flip, shape
		.2byte -4, -12, (50 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x04 @ flip, shape
		.2byte -8, -15, (80 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x04 @ flip, shape
		.2byte -6, -25, (222 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x02 @ flip, shape
		.2byte -8, -15, (30 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x02 @ flip, shape
		.2byte -4, -12, (50 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x04 @ flip, shape
		.2byte -8, -26, (9 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x01 @ flip, shape
		.2byte -8, -10, (41 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x02 @ flip, shape
		.2byte -16, -18, (24 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x00 @ flip, shape
		.2byte 0, -17, (8 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x04 @ flip, shape
		.2byte -8, -16, (80 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x00 @ flip, shape
		.2byte -8, -15, (3 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x04 @ flip, shape
		.2byte -6, -26, (192 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x01 @ flip, shape
		.2byte -8, -2, (218 | 1 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x04 @ flip, shape
		.2byte -8, -18, (186 | 1 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x02 @ flip, shape
		.2byte -4, -12, (50 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x00 @ flip, shape
		.2byte 0, -16, (190 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x04 @ flip, shape
		.2byte -8, -26, (9 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x01 @ flip, shape
		.2byte -8, -10, (41 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x04 @ flip, shape
		.2byte -8, -16, (80 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x02 @ flip, shape
		.2byte -8, -16, (191 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x04 @ flip, shape
		.2byte -7, -27, (188 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x02 @ flip, shape
		.2byte -16, -18, (24 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
	@ Unk2
		.byte 0x00, 0x00, 0x01, 0x00
		.byte 0x01, 0x00, 0x01, 0x00
		.byte 0x02, 0x00, 0x01, 0x00
		.byte 0x03, 0x00, 0x01, 0x00
		.byte 0x04, 0x00, 0x01, 0x00
		.byte 0x05, 0x00, 0x09, 0x00
		.byte 0x06, 0x00, 0x0B, 0x00
		.byte 0x07, 0x00, 0x09, 0x00
		.byte 0x08, 0x00, 0x0B, 0x00
		.byte 0x09, 0x00, 0x09, 0x00
		.byte 0x0A, 0x00, 0x0B, 0x00
		.byte 0x0B, 0x00, 0x09, 0x00
		.byte 0x0C, 0x00, 0x0B, 0x00
		.byte 0x03, 0x00, 0x0B, 0x00
		.byte 0x0E, 0x00, 0x09, 0x00
		.byte 0x0F, 0x00, 0x01, 0x00
		.byte 0x0F, 0x00, 0x01, 0x00
		.byte 0x10, 0x00, 0x01, 0x00
		.byte 0x11, 0x00, 0x01, 0x00
	@ Tiles
		.incbin "data/spriteset/sumire.4bpp"
