SpriteSetFile36: @ 0x08CB04B0
	.2byte 750 @ palStart
	.2byte 3 @ metaspriteCount
	.2byte 1 @ unk1Count
	.2byte 9 @ subspriteCount
	.2byte 3 @ unk2Count
	.2byte 256 @ tileCount
	.4byte 0x00000020, 0x0000005C, 0x00000064, 0x000000AC, 0x000000B8
	@ Metasprites
		.2byte 0x3229, 0x0003, 0x0000, 0x0000, 0xFFE8, 0xFFC7, 0x0008, 0x0007
		.4byte 0x0 @ subspriteOffset
		.2byte 0x322A, 0x0003, 0x0000, 0x0000, 0xFFE8, 0xFFC7, 0x0008, 0x0007
		.4byte 0x18 @ subspriteOffset
		.2byte 0x322B, 0x0003, 0x0000, 0x0000, 0xFFE8, 0xFFC7, 0x0008, 0x0007
		.4byte 0x30 @ subspriteOffset
	@ Unk1
		.byte 0x29, 0x32, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00
	@ Subsprites
		.byte 0x00, 0x04 @ flip, shape
		.2byte -8, -41, (0 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x04 @ flip, shape
		.2byte -8, -25, (32 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x01 @ flip, shape
		.2byte -8, -9, (64 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x04 @ flip, shape
		.2byte -8, -41, (2 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x04 @ flip, shape
		.2byte -8, -25, (34 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x01 @ flip, shape
		.2byte -8, -9, (64 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x04 @ flip, shape
		.2byte -8, -41, (4 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x04 @ flip, shape
		.2byte -8, -25, (36 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x01 @ flip, shape
		.2byte -8, -9, (64 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
	@ Unk2
		.byte 0x00, 0x00, 0x08, 0x00
		.byte 0x01, 0x00, 0x08, 0x00
		.byte 0x02, 0x00, 0x08, 0x00
	@ Tiles
		.incbin "data/spriteset/carmilla.4bpp"
