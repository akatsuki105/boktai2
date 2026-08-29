SpriteSetFile14: @ 0x08BEDF74
	.2byte 695 @ palStart
	.2byte 1 @ metaspriteCount
	.2byte 1 @ unk1Count
	.2byte 4 @ subspriteCount
	.2byte 1 @ unk2Count
	.2byte 256 @ tileCount
	.4byte 0x00000020, 0x00000034, 0x0000003C, 0x0000005C, 0x00000060
	@ Metasprites
		.2byte 0x698B, 0x0004, 0x0000, 0x0000, 0xFFE8, 0xFFE7, 0x0010, 0x0027
		.4byte 0x0 @ subspriteOffset
	@ Unk1
		.byte 0x4E, 0xB3, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00
	@ Subsprites
		.byte 0x00, 0x0A @ flip, shape
		.2byte -8, -9, (0 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x01 @ flip, shape
		.2byte -8, 23, (64 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x02 @ flip, shape
		.2byte -16, 7, (2 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x02 @ flip, shape
		.2byte 8, 7, (34 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
	@ Unk2
		.byte 0x00, 0x00, 0x01, 0x00
	@ Tiles
		.incbin "data/spriteset/megaman.4bpp"
