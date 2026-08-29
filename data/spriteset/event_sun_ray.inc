SpriteSetFile1: @ 0x08B7BD7C
	.2byte 734 @ palStart
	.2byte 3 @ metaspriteCount
	.2byte 0 @ unk1Count
	.2byte 3 @ subspriteCount
	.2byte 0 @ unk2Count
	.2byte 256 @ tileCount
	.4byte 0x00000020, 0x0000005C, 0x0000005C, 0x00000074, 0x00000074
	@ Metasprites
		.2byte 0xB2E8, 0x0001, 0x0000, 0x0000, 0xFFA0, 0xFFA0, 0x0020, 0x0020
		.4byte 0x0 @ subspriteOffset
		.2byte 0xB2E9, 0x0001, 0x0000, 0x0000, 0xFFA0, 0xFFA0, 0x0020, 0x0020
		.4byte 0x8 @ subspriteOffset
		.2byte 0xB2EA, 0x0001, 0x0000, 0x0000, 0xFFA0, 0xFFC0, 0x0020, 0x0040
		.4byte 0x10 @ subspriteOffset
	@ Unk1
	@ Subsprites
		.byte 0x00, 0x0C @ flip, shape
		.2byte -32, -32, (0 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x0C @ flip, shape
		.2byte -32, -32, (8 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x0D @ flip, shape
		.2byte -32, 0, (136 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
	@ Unk2
	@ Tiles
		.incbin "data/spriteset/event_sun_ray.4bpp"
