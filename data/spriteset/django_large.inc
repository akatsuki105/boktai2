SpriteSetFile2: @ 0x08B7DDF0
	.2byte 719 @ palStart
	.2byte 1 @ metaspriteCount
	.2byte 0 @ unk1Count
	.2byte 20 @ subspriteCount
	.2byte 0 @ unk2Count
	.2byte 512 @ tileCount
	.4byte 0x00000020, 0x00000034, 0x00000034, 0x000000D4, 0x000000D4
	@ Metasprites
		.2byte 0x0001, 0x0014, 0x0000, 0x0000, 0xFFF8, 0xFFC8, 0x00E0, 0x00A0
		.4byte 0x0 @ subspriteOffset
	@ Unk1
	@ Subsprites
		.byte 0x00, 0x0C @ flip, shape
		.2byte 64, 8, (0 | 1 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x00 @ flip, shape
		.2byte 72, 72, (129 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x05 @ flip, shape
		.2byte 80, 72, (130 | 1 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x0E @ flip, shape
		.2byte 128, 16, (24 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x0D @ flip, shape
		.2byte 80, 80, (146 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x01 @ flip, shape
		.2byte 112, 72, (134 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x01 @ flip, shape
		.2byte 64, 88, (160 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x08 @ flip, shape
		.2byte 144, 80, (154 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x0A @ flip, shape
		.2byte 176, 56, (110 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x09 @ flip, shape
		.2byte 80, 112, (210 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x09 @ flip, shape
		.2byte 112, 112, (214 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x02 @ flip, shape
		.2byte 144, 112, (218 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x09 @ flip, shape
		.2byte 88, 128, (257 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x00 @ flip, shape
		.2byte 80, 128, (256 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x09 @ flip, shape
		.2byte 120, 128, (261 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x08 @ flip, shape
		.2byte 192, 48, (293 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x08 @ flip, shape
		.2byte 32, 64, (321 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x09 @ flip, shape
		.2byte 24, 48, (288 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x01 @ flip, shape
		.2byte 152, 112, (219 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
		.byte 0x00, 0x0A @ flip, shape
		.2byte 160, 48, (92 | 0 << 12) @ x, y, (tileIdx | (palID << 12))
	@ Unk2
	@ Tiles
		.incbin "data/spriteset/django_large.4bpp"
