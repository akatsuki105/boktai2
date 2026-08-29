ActorSpriteFile0: @ 0x08A2291C
	.4byte 0 @ unk0
	.4byte 253 @ actorCount
	.4byte 0 @ unk8
	.4byte ActorSpriteFile0_Tiles      - ActorSpriteFile0 @ offsetToTiles
	.4byte ActorSpriteFile0_Metaprites - ActorSpriteFile0 @ offsetToMetasprites
	.4byte ActorSpriteFile0_Subsprites - ActorSpriteFile0 @ offsetToSubsprites
	ActorSpriteFile0_Actors:
		Actor_B306: @ Idx: 0
			.2byte 0xB306, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 20, 44 @ x, y (pixel offset)
			.4byte 0 * 12 @ .metasprite[0]
		Actor_F680: @ Idx: 1
			.2byte 0xF680, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 44, 51 @ x, y (pixel offset)
			.4byte 4 * 12 @ .metasprite[4]
		Actor_A5B3: @ Idx: 2
			.2byte 0xA5B3, 0 @ id, unk_02(always 0)
			.byte 16, 16 @ w, h (pixel size)
			.byte 8, 8 @ x, y (pixel offset)
			.4byte 6 * 12 @ .metasprite[6]
		Actor_A5B4: @ Idx: 3
			.2byte 0xA5B4, 0 @ id, unk_02(always 0)
			.byte 32, 32 @ w, h (pixel size)
			.byte 0, 0 @ x, y (pixel offset)
			.4byte 7 * 12 @ .metasprite[7]
		Actor_5AFD: @ Idx: 4
			.2byte 0x5AFD, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 32, 32 @ x, y (pixel offset)
			.4byte 11 * 12 @ .metasprite[11]
		Actor_5AFE: @ Idx: 5
			.2byte 0x5AFE, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 32, 32 @ x, y (pixel offset)
			.4byte 14 * 12 @ .metasprite[14]
		Actor_48DE: @ Idx: 6
			.2byte 0x48DE, 0 @ id, unk_02(always 0)
			.byte 32, 64 @ w, h (pixel size)
			.byte 14, 50 @ x, y (pixel offset)
			.4byte 18 * 12 @ .metasprite[18]
		Actor_D4EE: @ Idx: 7
			.2byte 0xD4EE, 0 @ id, unk_02(always 0)
			.byte 32, 64 @ w, h (pixel size)
			.byte 14, 50 @ x, y (pixel offset)
			.4byte 43 * 12 @ .metasprite[43]
		Actor_924B: @ Idx: 8
			.2byte 0x924B, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 32, 50 @ x, y (pixel offset)
			.4byte 55 * 12 @ .metasprite[55]
		Actor_2C12: @ Idx: 9
			.2byte 0x2C12, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 24, 24 @ x, y (pixel offset)
			.4byte 63 * 12 @ .metasprite[63]
		Actor_8F5D: @ Idx: 10
			.2byte 0x8F5D, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 32, 32 @ x, y (pixel offset)
			.4byte 67 * 12 @ .metasprite[67]
		Actor_7AEE: @ Idx: 11
			.2byte 0x7AEE, 0 @ id, unk_02(always 0)
			.byte 64, 128 @ w, h (pixel size)
			.byte 32, 64 @ x, y (pixel offset)
			.4byte 82 * 12 @ .metasprite[82]
		Actor_7AEF: @ Idx: 12
			.2byte 0x7AEF, 0 @ id, unk_02(always 0)
			.byte 64, 128 @ w, h (pixel size)
			.byte 32, 64 @ x, y (pixel offset)
			.4byte 85 * 12 @ .metasprite[85]
		Actor_7AF0: @ Idx: 13
			.2byte 0x7AF0, 0 @ id, unk_02(always 0)
			.byte 64, 128 @ w, h (pixel size)
			.byte 32, 64 @ x, y (pixel offset)
			.4byte 88 * 12 @ .metasprite[88]
		Actor_7AF1: @ Idx: 14
			.2byte 0x7AF1, 0 @ id, unk_02(always 0)
			.byte 64, 128 @ w, h (pixel size)
			.byte 32, 64 @ x, y (pixel offset)
			.4byte 91 * 12 @ .metasprite[91]
		Actor_7AF2: @ Idx: 15
			.2byte 0x7AF2, 0 @ id, unk_02(always 0)
			.byte 64, 128 @ w, h (pixel size)
			.byte 32, 64 @ x, y (pixel offset)
			.4byte 94 * 12 @ .metasprite[94]
		Actor_A20C: @ Idx: 16
			.2byte 0xA20C, 0 @ id, unk_02(always 0)
			.byte 8, 8 @ w, h (pixel size)
			.byte 4, 4 @ x, y (pixel offset)
			.4byte 97 * 12 @ .metasprite[97]
		Actor_9D2D: @ Idx: 17
			.2byte 0x9D2D, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 24, 40 @ x, y (pixel offset)
			.4byte 101 * 12 @ .metasprite[101]
		Actor_048A: @ Idx: 18
			.2byte 0x048A, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 24, 40 @ x, y (pixel offset)
			.4byte 102 * 12 @ .metasprite[102]
		Actor_E1D2: @ Idx: 19
			.2byte 0xE1D2, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 24, 48 @ x, y (pixel offset)
			.4byte 103 * 12 @ .metasprite[103]
		Actor_B0E2: @ Idx: 20
			.2byte 0xB0E2, 0 @ id, unk_02(always 0)
			.byte 32, 32 @ w, h (pixel size)
			.byte 13, 25 @ x, y (pixel offset)
			.4byte 104 * 12 @ .metasprite[104]
		Actor_C060: @ Idx: 21
			.2byte 0xC060, 0 @ id, unk_02(always 0)
			.byte 32, 32 @ w, h (pixel size)
			.byte 16, 16 @ x, y (pixel offset)
			.4byte 106 * 12 @ .metasprite[106]
		Actor_DD5C: @ Idx: 22
			.2byte 0xDD5C, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 33, 48 @ x, y (pixel offset)
			.4byte 107 * 12 @ .metasprite[107]
		Actor_4AEE: @ Idx: 23
			.2byte 0x4AEE, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 24, 48 @ x, y (pixel offset)
			.4byte 108 * 12 @ .metasprite[108]
		Actor_A0D5: @ Idx: 24
			.2byte 0xA0D5, 0 @ id, unk_02(always 0)
			.byte 32, 32 @ w, h (pixel size)
			.byte 16, 16 @ x, y (pixel offset)
			.4byte 109 * 12 @ .metasprite[109]
		Actor_2AF0: @ Idx: 25
			.2byte 0x2AF0, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 24, 51 @ x, y (pixel offset)
			.4byte 127 * 12 @ .metasprite[127]
		Actor_A680: @ Idx: 26
			.2byte 0xA680, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 24, 24 @ x, y (pixel offset)
			.4byte 131 * 12 @ .metasprite[131]
		Actor_A6A0: @ Idx: 27
			.2byte 0xA6A0, 0 @ id, unk_02(always 0)
			.byte 16, 32 @ w, h (pixel size)
			.byte 0, 32 @ x, y (pixel offset)
			.4byte 143 * 12 @ .metasprite[143]
		Actor_2D41: @ Idx: 28
			.2byte 0x2D41, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 32, 32 @ x, y (pixel offset)
			.4byte 147 * 12 @ .metasprite[147]
		Actor_A850: @ Idx: 29
			.2byte 0xA850, 0 @ id, unk_02(always 0)
			.byte 16, 32 @ w, h (pixel size)
			.byte 8, 16 @ x, y (pixel offset)
			.4byte 180 * 12 @ .metasprite[180]
		Actor_9D43: @ Idx: 30
			.2byte 0x9D43, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 24, 46 @ x, y (pixel offset)
			.4byte 182 * 12 @ .metasprite[182]
		Actor_008A: @ Idx: 31
			.2byte 0x008A, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 24, 64 @ x, y (pixel offset)
			.4byte 183 * 12 @ .metasprite[183]
		Actor_76DB: @ Idx: 32
			.2byte 0x76DB, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 24, 48 @ x, y (pixel offset)
			.4byte 185 * 12 @ .metasprite[185]
		Actor_2712: @ Idx: 33
			.2byte 0x2712, 0 @ id, unk_02(always 0)
			.byte 16, 16 @ w, h (pixel size)
			.byte 7, 14 @ x, y (pixel offset)
			.4byte 188 * 12 @ .metasprite[188]
		Actor_5DC0: @ Idx: 34
			.2byte 0x5DC0, 0 @ id, unk_02(always 0)
			.byte 32, 32 @ w, h (pixel size)
			.byte 12, 20 @ x, y (pixel offset)
			.4byte 196 * 12 @ .metasprite[196]
		Actor_6AF6: @ Idx: 35
			.2byte 0x6AF6, 0 @ id, unk_02(always 0)
			.byte 32, 32 @ w, h (pixel size)
			.byte 16, 16 @ x, y (pixel offset)
			.4byte 212 * 12 @ .metasprite[212]
		Actor_4AAE: @ Idx: 36
			.2byte 0x4AAE, 0 @ id, unk_02(always 0)
			.byte 32, 32 @ w, h (pixel size)
			.byte 0, 0 @ x, y (pixel offset)
			.4byte 220 * 12 @ .metasprite[220]
		Actor_1C1B: @ Idx: 37
			.2byte 0x1C1B, 0 @ id, unk_02(always 0)
			.byte 32, 32 @ w, h (pixel size)
			.byte 16, 16 @ x, y (pixel offset)
			.4byte 221 * 12 @ .metasprite[221]
		Actor_9FF5: @ Idx: 38
			.2byte 0x9FF5, 0 @ id, unk_02(always 0)
			.byte 8, 8 @ w, h (pixel size)
			.byte 4, 4 @ x, y (pixel offset)
			.4byte 229 * 12 @ .metasprite[229]
		Actor_A606: @ Idx: 39
			.2byte 0xA606, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 24, 48 @ x, y (pixel offset)
			.4byte 240 * 12 @ .metasprite[240]
		Actor_D28E: @ Idx: 40
			.2byte 0xD28E, 0 @ id, unk_02(always 0)
			.byte 16, 16 @ w, h (pixel size)
			.byte 8, 8 @ x, y (pixel offset)
			.4byte 249 * 12 @ .metasprite[249]
		Actor_D166: @ Idx: 41
			.2byte 0xD166, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 21, 20 @ x, y (pixel offset)
			.4byte 291 * 12 @ .metasprite[291]
		Actor_0BA8: @ Idx: 42
			.2byte 0x0BA8, 0 @ id, unk_02(always 0)
			.byte 32, 32 @ w, h (pixel size)
			.byte 16, 16 @ x, y (pixel offset)
			.4byte 294 * 12 @ .metasprite[294]
		Actor_0BA9: @ Idx: 43
			.2byte 0x0BA9, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 32, 32 @ x, y (pixel offset)
			.4byte 319 * 12 @ .metasprite[319]
		Actor_363C: @ Idx: 44
			.2byte 0x363C, 0 @ id, unk_02(always 0)
			.byte 8, 16 @ w, h (pixel size)
			.byte 4, 8 @ x, y (pixel offset)
			.4byte 320 * 12 @ .metasprite[320]
		Actor_363D: @ Idx: 45
			.2byte 0x363D, 0 @ id, unk_02(always 0)
			.byte 32, 16 @ w, h (pixel size)
			.byte 16, 8 @ x, y (pixel offset)
			.4byte 330 * 12 @ .metasprite[330]
		Actor_1FBD: @ Idx: 46
			.2byte 0x1FBD, 0 @ id, unk_02(always 0)
			.byte 32, 64 @ w, h (pixel size)
			.byte 0, 48 @ x, y (pixel offset)
			.4byte 337 * 12 @ .metasprite[337]
		Actor_6AF7: @ Idx: 47
			.2byte 0x6AF7, 0 @ id, unk_02(always 0)
			.byte 32, 64 @ w, h (pixel size)
			.byte 16, 32 @ x, y (pixel offset)
			.4byte 338 * 12 @ .metasprite[338]
		Actor_1B59: @ Idx: 48
			.2byte 0x1B59, 0 @ id, unk_02(always 0)
			.byte 32, 64 @ w, h (pixel size)
			.byte 16, 52 @ x, y (pixel offset)
			.4byte 339 * 12 @ .metasprite[339]
		Actor_7E82: @ Idx: 49
			.2byte 0x7E82, 0 @ id, unk_02(always 0)
			.byte 32, 64 @ w, h (pixel size)
			.byte 16, 64 @ x, y (pixel offset)
			.4byte 342 * 12 @ .metasprite[342]
		Actor_BCA8: @ Idx: 50
			.2byte 0xBCA8, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 20, 44 @ x, y (pixel offset)
			.4byte 343 * 12 @ .metasprite[343]
		Actor_4384: @ Idx: 51
			.2byte 0x4384, 0 @ id, unk_02(always 0)
			.byte 32, 32 @ w, h (pixel size)
			.byte 16, 16 @ x, y (pixel offset)
			.4byte 345 * 12 @ .metasprite[345]
		Actor_4385: @ Idx: 52
			.2byte 0x4385, 0 @ id, unk_02(always 0)
			.byte 8, 8 @ w, h (pixel size)
			.byte 4, 4 @ x, y (pixel offset)
			.4byte 354 * 12 @ .metasprite[354]
		Actor_05A2: @ Idx: 53
			.2byte 0x05A2, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 24, 40 @ x, y (pixel offset)
			.4byte 360 * 12 @ .metasprite[360]
		Actor_34C0: @ Idx: 54
			.2byte 0x34C0, 0 @ id, unk_02(always 0)
			.byte 32, 64 @ w, h (pixel size)
			.byte 16, 32 @ x, y (pixel offset)
			.4byte 361 * 12 @ .metasprite[361]
		Actor_528F: @ Idx: 55
			.2byte 0x528F, 0 @ id, unk_02(always 0)
			.byte 32, 32 @ w, h (pixel size)
			.byte 16, 16 @ x, y (pixel offset)
			.4byte 362 * 12 @ .metasprite[362]
		Actor_7AD2: @ Idx: 56
			.2byte 0x7AD2, 0 @ id, unk_02(always 0)
			.byte 32, 64 @ w, h (pixel size)
			.byte 16, 52 @ x, y (pixel offset)
			.4byte 378 * 12 @ .metasprite[378]
		Actor_B96C: @ Idx: 57
			.2byte 0xB96C, 0 @ id, unk_02(always 0)
			.byte 32, 32 @ w, h (pixel size)
			.byte 16, 18 @ x, y (pixel offset)
			.4byte 381 * 12 @ .metasprite[381]
		Actor_7031: @ Idx: 58
			.2byte 0x7031, 0 @ id, unk_02(always 0)
			.byte 16, 16 @ w, h (pixel size)
			.byte 8, 8 @ x, y (pixel offset)
			.4byte 397 * 12 @ .metasprite[397]
		Actor_7032: @ Idx: 59
			.2byte 0x7032, 0 @ id, unk_02(always 0)
			.byte 8, 8 @ w, h (pixel size)
			.byte 4, 4 @ x, y (pixel offset)
			.4byte 398 * 12 @ .metasprite[398]
		Actor_E857: @ Idx: 60
			.2byte 0xE857, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 24, 48 @ x, y (pixel offset)
			.4byte 401 * 12 @ .metasprite[401]
		Actor_3641: @ Idx: 61
			.2byte 0x3641, 0 @ id, unk_02(always 0)
			.byte 32, 32 @ w, h (pixel size)
			.byte 16, 16 @ x, y (pixel offset)
			.4byte 409 * 12 @ .metasprite[409]
		Actor_F070: @ Idx: 62
			.2byte 0xF070, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 6, 49 @ x, y (pixel offset)
			.4byte 411 * 12 @ .metasprite[411]
		Actor_C3C3: @ Idx: 63
			.2byte 0xC3C3, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 24, 48 @ x, y (pixel offset)
			.4byte 415 * 12 @ .metasprite[415]
		Actor_1C84: @ Idx: 64
			.2byte 0x1C84, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 32, 32 @ x, y (pixel offset)
			.4byte 418 * 12 @ .metasprite[418]
		Actor_E505: @ Idx: 65
			.2byte 0xE505, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 24, 48 @ x, y (pixel offset)
			.4byte 419 * 12 @ .metasprite[419]
		Actor_FDC5: @ Idx: 66
			.2byte 0xFDC5, 0 @ id, unk_02(always 0)
			.byte 32, 64 @ w, h (pixel size)
			.byte 16, 48 @ x, y (pixel offset)
			.4byte 429 * 12 @ .metasprite[429]
		Actor_96F7: @ Idx: 67
			.2byte 0x96F7, 0 @ id, unk_02(always 0)
			.byte 16, 32 @ w, h (pixel size)
			.byte 9, 29 @ x, y (pixel offset)
			.4byte 436 * 12 @ .metasprite[436]
		Actor_A5BD: @ Idx: 68
			.2byte 0xA5BD, 0 @ id, unk_02(always 0)
			.byte 32, 8 @ w, h (pixel size)
			.byte 0, 0 @ x, y (pixel offset)
			.4byte 437 * 12 @ .metasprite[437]
		Actor_7AD3: @ Idx: 69
			.2byte 0x7AD3, 0 @ id, unk_02(always 0)
			.byte 64, 128 @ w, h (pixel size)
			.byte 32, 64 @ x, y (pixel offset)
			.4byte 439 * 12 @ .metasprite[439]
		Actor_7AD4: @ Idx: 70
			.2byte 0x7AD4, 0 @ id, unk_02(always 0)
			.byte 64, 128 @ w, h (pixel size)
			.byte 32, 64 @ x, y (pixel offset)
			.4byte 442 * 12 @ .metasprite[442]
		Actor_7AD5: @ Idx: 71
			.2byte 0x7AD5, 0 @ id, unk_02(always 0)
			.byte 64, 128 @ w, h (pixel size)
			.byte 32, 64 @ x, y (pixel offset)
			.4byte 445 * 12 @ .metasprite[445]
		Actor_7AD6: @ Idx: 72
			.2byte 0x7AD6, 0 @ id, unk_02(always 0)
			.byte 64, 128 @ w, h (pixel size)
			.byte 32, 64 @ x, y (pixel offset)
			.4byte 448 * 12 @ .metasprite[448]
		Actor_7AED: @ Idx: 73
			.2byte 0x7AED, 0 @ id, unk_02(always 0)
			.byte 64, 128 @ w, h (pixel size)
			.byte 32, 64 @ x, y (pixel offset)
			.4byte 451 * 12 @ .metasprite[451]
		Actor_7AF3: @ Idx: 74
			.2byte 0x7AF3, 0 @ id, unk_02(always 0)
			.byte 64, 128 @ w, h (pixel size)
			.byte 32, 64 @ x, y (pixel offset)
			.4byte 454 * 12 @ .metasprite[454]
		Actor_7AF4: @ Idx: 75
			.2byte 0x7AF4, 0 @ id, unk_02(always 0)
			.byte 64, 128 @ w, h (pixel size)
			.byte 32, 64 @ x, y (pixel offset)
			.4byte 457 * 12 @ .metasprite[457]
		Actor_7AF5: @ Idx: 76
			.2byte 0x7AF5, 0 @ id, unk_02(always 0)
			.byte 64, 128 @ w, h (pixel size)
			.byte 32, 64 @ x, y (pixel offset)
			.4byte 460 * 12 @ .metasprite[460]
		Actor_7AF6: @ Idx: 77
			.2byte 0x7AF6, 0 @ id, unk_02(always 0)
			.byte 64, 128 @ w, h (pixel size)
			.byte 32, 64 @ x, y (pixel offset)
			.4byte 463 * 12 @ .metasprite[463]
		Actor_7B0D: @ Idx: 78
			.2byte 0x7B0D, 0 @ id, unk_02(always 0)
			.byte 64, 128 @ w, h (pixel size)
			.byte 32, 64 @ x, y (pixel offset)
			.4byte 466 * 12 @ .metasprite[466]
		Actor_9506: @ Idx: 79
			.2byte 0x9506, 0 @ id, unk_02(always 0)
			.byte 32, 32 @ w, h (pixel size)
			.byte 17, 17 @ x, y (pixel offset)
			.4byte 469 * 12 @ .metasprite[469]
		Actor_22E7: @ Idx: 80
			.2byte 0x22E7, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 24, 48 @ x, y (pixel offset)
			.4byte 498 * 12 @ .metasprite[498]
		Actor_41B1: @ Idx: 81
			.2byte 0x41B1, 0 @ id, unk_02(always 0)
			.byte 32, 32 @ w, h (pixel size)
			.byte 16, 16 @ x, y (pixel offset)
			.4byte 510 * 12 @ .metasprite[510]
		Actor_DC8E: @ Idx: 82
			.2byte 0xDC8E, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 33, 54 @ x, y (pixel offset)
			.4byte 518 * 12 @ .metasprite[518]
		Actor_CDAB: @ Idx: 83
			.2byte 0xCDAB, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 20, 20 @ x, y (pixel offset)
			.4byte 519 * 12 @ .metasprite[519]
		Actor_D962: @ Idx: 84
			.2byte 0xD962, 0 @ id, unk_02(always 0)
			.byte 32, 64 @ w, h (pixel size)
			.byte 16, 52 @ x, y (pixel offset)
			.4byte 520 * 12 @ .metasprite[520]
		Actor_B044: @ Idx: 85
			.2byte 0xB044, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 24, 0 @ x, y (pixel offset)
			.4byte 528 * 12 @ .metasprite[528]
		Actor_3668: @ Idx: 86
			.2byte 0x3668, 0 @ id, unk_02(always 0)
			.byte 16, 16 @ w, h (pixel size)
			.byte 8, 8 @ x, y (pixel offset)
			.4byte 529 * 12 @ .metasprite[529]
		Actor_18A8: @ Idx: 87
			.2byte 0x18A8, 0 @ id, unk_02(always 0)
			.byte 16, 16 @ w, h (pixel size)
			.byte 8, 8 @ x, y (pixel offset)
			.4byte 555 * 12 @ .metasprite[555]
		Actor_18A9: @ Idx: 88
			.2byte 0x18A9, 0 @ id, unk_02(always 0)
			.byte 8, 16 @ w, h (pixel size)
			.byte 4, 8 @ x, y (pixel offset)
			.4byte 559 * 12 @ .metasprite[559]
		Actor_2769: @ Idx: 89
			.2byte 0x2769, 0 @ id, unk_02(always 0)
			.byte 32, 32 @ w, h (pixel size)
			.byte 12, 28 @ x, y (pixel offset)
			.4byte 570 * 12 @ .metasprite[570]
		Actor_5B78: @ Idx: 90
			.2byte 0x5B78, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 24, 24 @ x, y (pixel offset)
			.4byte 572 * 12 @ .metasprite[572]
		Actor_16F5: @ Idx: 91
			.2byte 0x16F5, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 20, 44 @ x, y (pixel offset)
			.4byte 573 * 12 @ .metasprite[573]
		Actor_F422: @ Idx: 92
			.2byte 0xF422, 0 @ id, unk_02(always 0)
			.byte 32, 32 @ w, h (pixel size)
			.byte 16, 16 @ x, y (pixel offset)
			.4byte 577 * 12 @ .metasprite[577]
		Actor_848F: @ Idx: 93
			.2byte 0x848F, 0 @ id, unk_02(always 0)
			.byte 16, 16 @ w, h (pixel size)
			.byte 8, 8 @ x, y (pixel offset)
			.4byte 603 * 12 @ .metasprite[603]
		Actor_8490: @ Idx: 94
			.2byte 0x8490, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 32, 40 @ x, y (pixel offset)
			.4byte 616 * 12 @ .metasprite[616]
		Actor_D638: @ Idx: 95
			.2byte 0xD638, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 30, 40 @ x, y (pixel offset)
			.4byte 622 * 12 @ .metasprite[622]
		Actor_EF69: @ Idx: 96
			.2byte 0xEF69, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 27, 29 @ x, y (pixel offset)
			.4byte 659 * 12 @ .metasprite[659]
		Actor_5BA7: @ Idx: 97
			.2byte 0x5BA7, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 24, 24 @ x, y (pixel offset)
			.4byte 660 * 12 @ .metasprite[660]
		Actor_5BB7: @ Idx: 98
			.2byte 0x5BB7, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 24, 24 @ x, y (pixel offset)
			.4byte 661 * 12 @ .metasprite[661]
		Actor_E74B: @ Idx: 99
			.2byte 0xE74B, 0 @ id, unk_02(always 0)
			.byte 16, 16 @ w, h (pixel size)
			.byte 8, 8 @ x, y (pixel offset)
			.4byte 662 * 12 @ .metasprite[662]
		Actor_9A1F: @ Idx: 100
			.2byte 0x9A1F, 0 @ id, unk_02(always 0)
			.byte 16, 16 @ w, h (pixel size)
			.byte 8, 8 @ x, y (pixel offset)
			.4byte 686 * 12 @ .metasprite[686]
		Actor_C459: @ Idx: 101
			.2byte 0xC459, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 21, 21 @ x, y (pixel offset)
			.4byte 697 * 12 @ .metasprite[697]
		Actor_DC07: @ Idx: 102
			.2byte 0xDC07, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 24, 24 @ x, y (pixel offset)
			.4byte 698 * 12 @ .metasprite[698]
		Actor_D45E: @ Idx: 103
			.2byte 0xD45E, 0 @ id, unk_02(always 0)
			.byte 32, 32 @ w, h (pixel size)
			.byte 16, 16 @ x, y (pixel offset)
			.4byte 699 * 12 @ .metasprite[699]
		Actor_D85E: @ Idx: 104
			.2byte 0xD85E, 0 @ id, unk_02(always 0)
			.byte 32, 32 @ w, h (pixel size)
			.byte 16, 16 @ x, y (pixel offset)
			.4byte 763 * 12 @ .metasprite[763]
		Actor_2817: @ Idx: 105
			.2byte 0x2817, 0 @ id, unk_02(always 0)
			.byte 16, 32 @ w, h (pixel size)
			.byte 0, 0 @ x, y (pixel offset)
			.4byte 785 * 12 @ .metasprite[785]
		Actor_EFD8: @ Idx: 106
			.2byte 0xEFD8, 0 @ id, unk_02(always 0)
			.byte 32, 32 @ w, h (pixel size)
			.byte 16, 0 @ x, y (pixel offset)
			.4byte 786 * 12 @ .metasprite[786]
		Actor_8639: @ Idx: 107
			.2byte 0x8639, 0 @ id, unk_02(always 0)
			.byte 32, 32 @ w, h (pixel size)
			.byte 16, 16 @ x, y (pixel offset)
			.4byte 797 * 12 @ .metasprite[797]
		Actor_97D3: @ Idx: 108
			.2byte 0x97D3, 0 @ id, unk_02(always 0)
			.byte 16, 32 @ w, h (pixel size)
			.byte 8, 19 @ x, y (pixel offset)
			.4byte 813 * 12 @ .metasprite[813]
		Actor_97D4: @ Idx: 109
			.2byte 0x97D4, 0 @ id, unk_02(always 0)
			.byte 32, 32 @ w, h (pixel size)
			.byte 16, 19 @ x, y (pixel offset)
			.4byte 850 * 12 @ .metasprite[850]
		Actor_C42D: @ Idx: 110
			.2byte 0xC42D, 0 @ id, unk_02(always 0)
			.byte 32, 32 @ w, h (pixel size)
			.byte 16, 16 @ x, y (pixel offset)
			.4byte 864 * 12 @ .metasprite[864]
		Actor_0334: @ Idx: 111
			.2byte 0x0334, 0 @ id, unk_02(always 0)
			.byte 8, 8 @ w, h (pixel size)
			.byte 4, 4 @ x, y (pixel offset)
			.4byte 865 * 12 @ .metasprite[865]
		Actor_9DFF: @ Idx: 112
			.2byte 0x9DFF, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 24, 48 @ x, y (pixel offset)
			.4byte 866 * 12 @ .metasprite[866]
		Actor_A152: @ Idx: 113
			.2byte 0xA152, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 24, 24 @ x, y (pixel offset)
			.4byte 868 * 12 @ .metasprite[868]
		Actor_17C7: @ Idx: 114
			.2byte 0x17C7, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 24, 0 @ x, y (pixel offset)
			.4byte 869 * 12 @ .metasprite[869]
		Actor_210E: @ Idx: 115
			.2byte 0x210E, 0 @ id, unk_02(always 0)
			.byte 16, 16 @ w, h (pixel size)
			.byte 8, 8 @ x, y (pixel offset)
			.4byte 871 * 12 @ .metasprite[871]
		Actor_210F: @ Idx: 116
			.2byte 0x210F, 0 @ id, unk_02(always 0)
			.byte 32, 32 @ w, h (pixel size)
			.byte 16, 16 @ x, y (pixel offset)
			.4byte 875 * 12 @ .metasprite[875]
		Actor_1FE0: @ Idx: 117
			.2byte 0x1FE0, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 24, 48 @ x, y (pixel offset)
			.4byte 880 * 12 @ .metasprite[880]
		Actor_2C1A: @ Idx: 118
			.2byte 0x2C1A, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 24, 0 @ x, y (pixel offset)
			.4byte 891 * 12 @ .metasprite[891]
		Actor_5291: @ Idx: 119
			.2byte 0x5291, 0 @ id, unk_02(always 0)
			.byte 32, 64 @ w, h (pixel size)
			.byte 11, 32 @ x, y (pixel offset)
			.4byte 892 * 12 @ .metasprite[892]
		Actor_5292: @ Idx: 120
			.2byte 0x5292, 0 @ id, unk_02(always 0)
			.byte 16, 32 @ w, h (pixel size)
			.byte 7, 18 @ x, y (pixel offset)
			.4byte 894 * 12 @ .metasprite[894]
		Actor_9247: @ Idx: 121
			.2byte 0x9247, 0 @ id, unk_02(always 0)
			.byte 32, 64 @ w, h (pixel size)
			.byte 16, 50 @ x, y (pixel offset)
			.4byte 898 * 12 @ .metasprite[898]
		Actor_D4EA: @ Idx: 122
			.2byte 0xD4EA, 0 @ id, unk_02(always 0)
			.byte 32, 64 @ w, h (pixel size)
			.byte 16, 50 @ x, y (pixel offset)
			.4byte 910 * 12 @ .metasprite[910]
		Actor_47DE: @ Idx: 123
			.2byte 0x47DE, 0 @ id, unk_02(always 0)
			.byte 32, 64 @ w, h (pixel size)
			.byte 16, 50 @ x, y (pixel offset)
			.4byte 920 * 12 @ .metasprite[920]
		Actor_C046: @ Idx: 124
			.2byte 0xC046, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 24, 48 @ x, y (pixel offset)
			.4byte 945 * 12 @ .metasprite[945]
		Actor_2097: @ Idx: 125
			.2byte 0x2097, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 24, 46 @ x, y (pixel offset)
			.4byte 948 * 12 @ .metasprite[948]
		Actor_17C8: @ Idx: 126
			.2byte 0x17C8, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 24, 0 @ x, y (pixel offset)
			.4byte 960 * 12 @ .metasprite[960]
		Actor_BB68: @ Idx: 127
			.2byte 0xBB68, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 32, 48 @ x, y (pixel offset)
			.4byte 962 * 12 @ .metasprite[962]
		Actor_EED8: @ Idx: 128
			.2byte 0xEED8, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 20, 40 @ x, y (pixel offset)
			.4byte 966 * 12 @ .metasprite[966]
		Actor_505C: @ Idx: 129
			.2byte 0x505C, 0 @ id, unk_02(always 0)
			.byte 16, 16 @ w, h (pixel size)
			.byte 8, 8 @ x, y (pixel offset)
			.4byte 968 * 12 @ .metasprite[968]
		Actor_A47C: @ Idx: 130
			.2byte 0xA47C, 0 @ id, unk_02(always 0)
			.byte 32, 64 @ w, h (pixel size)
			.byte 16, 37 @ x, y (pixel offset)
			.4byte 977 * 12 @ .metasprite[977]
		Actor_DDE7: @ Idx: 131
			.2byte 0xDDE7, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 24, 24 @ x, y (pixel offset)
			.4byte 978 * 12 @ .metasprite[978]
		Actor_9E08: @ Idx: 132
			.2byte 0x9E08, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 24, 24 @ x, y (pixel offset)
			.4byte 979 * 12 @ .metasprite[979]
		Actor_A8E7: @ Idx: 133
			.2byte 0xA8E7, 0 @ id, unk_02(always 0)
			.byte 8, 8 @ w, h (pixel size)
			.byte 0, 0 @ x, y (pixel offset)
			.4byte 980 * 12 @ .metasprite[980]
		Actor_5A6E: @ Idx: 134
			.2byte 0x5A6E, 0 @ id, unk_02(always 0)
			.byte 32, 32 @ w, h (pixel size)
			.byte 16, 16 @ x, y (pixel offset)
			.4byte 991 * 12 @ .metasprite[991]
		Actor_5A6F: @ Idx: 135
			.2byte 0x5A6F, 0 @ id, unk_02(always 0)
			.byte 32, 32 @ w, h (pixel size)
			.byte 16, 20 @ x, y (pixel offset)
			.4byte 1014 * 12 @ .metasprite[1014]
		Actor_44EE: @ Idx: 136
			.2byte 0x44EE, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 24, 48 @ x, y (pixel offset)
			.4byte 1030 * 12 @ .metasprite[1030]
		Actor_5D7C: @ Idx: 137
			.2byte 0x5D7C, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 24, 48 @ x, y (pixel offset)
			.4byte 1031 * 12 @ .metasprite[1031]
		Actor_B837: @ Idx: 138
			.2byte 0xB837, 0 @ id, unk_02(always 0)
			.byte 32, 32 @ w, h (pixel size)
			.byte 16, 32 @ x, y (pixel offset)
			.4byte 1032 * 12 @ .metasprite[1032]
		Actor_E0C9: @ Idx: 139
			.2byte 0xE0C9, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 24, 46 @ x, y (pixel offset)
			.4byte 1042 * 12 @ .metasprite[1042]
		Actor_8203: @ Idx: 140
			.2byte 0x8203, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 32, 32 @ x, y (pixel offset)
			.4byte 1043 * 12 @ .metasprite[1043]
		Actor_8204: @ Idx: 141
			.2byte 0x8204, 0 @ id, unk_02(always 0)
			.byte 32, 32 @ w, h (pixel size)
			.byte 16, 16 @ x, y (pixel offset)
			.4byte 1047 * 12 @ .metasprite[1047]
		Actor_8205: @ Idx: 142
			.2byte 0x8205, 0 @ id, unk_02(always 0)
			.byte 16, 16 @ w, h (pixel size)
			.byte 8, 6 @ x, y (pixel offset)
			.4byte 1049 * 12 @ .metasprite[1049]
		Actor_8202: @ Idx: 143
			.2byte 0x8202, 0 @ id, unk_02(always 0)
			.byte 16, 16 @ w, h (pixel size)
			.byte 8, 8 @ x, y (pixel offset)
			.4byte 1053 * 12 @ .metasprite[1053]
		Actor_8206: @ Idx: 144
			.2byte 0x8206, 0 @ id, unk_02(always 0)
			.byte 16, 16 @ w, h (pixel size)
			.byte 8, 8 @ x, y (pixel offset)
			.4byte 1066 * 12 @ .metasprite[1066]
		Actor_8207: @ Idx: 145
			.2byte 0x8207, 0 @ id, unk_02(always 0)
			.byte 8, 8 @ w, h (pixel size)
			.byte 4, 4 @ x, y (pixel offset)
			.4byte 1072 * 12 @ .metasprite[1072]
		Actor_DC38: @ Idx: 146
			.2byte 0xDC38, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 24, 48 @ x, y (pixel offset)
			.4byte 1079 * 12 @ .metasprite[1079]
		Actor_8393: @ Idx: 147
			.2byte 0x8393, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 24, 48 @ x, y (pixel offset)
			.4byte 1090 * 12 @ .metasprite[1090]
		Actor_066A: @ Idx: 148
			.2byte 0x066A, 0 @ id, unk_02(always 0)
			.byte 16, 32 @ w, h (pixel size)
			.byte 8, 31 @ x, y (pixel offset)
			.4byte 1106 * 12 @ .metasprite[1106]
		Actor_17C9: @ Idx: 149
			.2byte 0x17C9, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 24, 0 @ x, y (pixel offset)
			.4byte 1110 * 12 @ .metasprite[1110]
		Actor_DB6C: @ Idx: 150
			.2byte 0xDB6C, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 24, 40 @ x, y (pixel offset)
			.4byte 1112 * 12 @ .metasprite[1112]
		Actor_D0A3: @ Idx: 151
			.2byte 0xD0A3, 0 @ id, unk_02(always 0)
			.byte 16, 32 @ w, h (pixel size)
			.byte 3, 13 @ x, y (pixel offset)
			.4byte 1113 * 12 @ .metasprite[1113]
		Actor_9385: @ Idx: 152
			.2byte 0x9385, 0 @ id, unk_02(always 0)
			.byte 32, 32 @ w, h (pixel size)
			.byte 16, 16 @ x, y (pixel offset)
			.4byte 1116 * 12 @ .metasprite[1116]
		Actor_B626: @ Idx: 153
			.2byte 0xB626, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 32, 36 @ x, y (pixel offset)
			.4byte 1119 * 12 @ .metasprite[1119]
		Actor_D637: @ Idx: 154
			.2byte 0xD637, 0 @ id, unk_02(always 0)
			.byte 32, 32 @ w, h (pixel size)
			.byte 16, 16 @ x, y (pixel offset)
			.4byte 1120 * 12 @ .metasprite[1120]
		Actor_E7EA: @ Idx: 155
			.2byte 0xE7EA, 0 @ id, unk_02(always 0)
			.byte 8, 8 @ w, h (pixel size)
			.byte 4, 4 @ x, y (pixel offset)
			.4byte 1149 * 12 @ .metasprite[1149]
		Actor_DFCF: @ Idx: 156
			.2byte 0xDFCF, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 27, 30 @ x, y (pixel offset)
			.4byte 1154 * 12 @ .metasprite[1154]
		Actor_0E48: @ Idx: 157
			.2byte 0x0E48, 0 @ id, unk_02(always 0)
			.byte 32, 32 @ w, h (pixel size)
			.byte 16, 16 @ x, y (pixel offset)
			.4byte 1158 * 12 @ .metasprite[1158]
		Actor_DC72: @ Idx: 158
			.2byte 0xDC72, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 16, 29 @ x, y (pixel offset)
			.4byte 1159 * 12 @ .metasprite[1159]
		Actor_C039: @ Idx: 159
			.2byte 0xC039, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 32, 32 @ x, y (pixel offset)
			.4byte 1160 * 12 @ .metasprite[1160]
		Actor_9803: @ Idx: 160
			.2byte 0x9803, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 24, 48 @ x, y (pixel offset)
			.4byte 1161 * 12 @ .metasprite[1161]
		Actor_D56D: @ Idx: 161
			.2byte 0xD56D, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 24, 24 @ x, y (pixel offset)
			.4byte 1175 * 12 @ .metasprite[1175]
		Actor_17CA: @ Idx: 162
			.2byte 0x17CA, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 24, 0 @ x, y (pixel offset)
			.4byte 1177 * 12 @ .metasprite[1177]
		Actor_3640: @ Idx: 163
			.2byte 0x3640, 0 @ id, unk_02(always 0)
			.byte 32, 32 @ w, h (pixel size)
			.byte 16, 16 @ x, y (pixel offset)
			.4byte 1179 * 12 @ .metasprite[1179]
		Actor_9B09: @ Idx: 164
			.2byte 0x9B09, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 24, 48 @ x, y (pixel offset)
			.4byte 1195 * 12 @ .metasprite[1195]
		Actor_D454: @ Idx: 165
			.2byte 0xD454, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 24, 48 @ x, y (pixel offset)
			.4byte 1204 * 12 @ .metasprite[1204]
		Actor_D636: @ Idx: 166
			.2byte 0xD636, 0 @ id, unk_02(always 0)
			.byte 32, 32 @ w, h (pixel size)
			.byte 16, 16 @ x, y (pixel offset)
			.4byte 1213 * 12 @ .metasprite[1213]
		Actor_E769: @ Idx: 167
			.2byte 0xE769, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 32, 32 @ x, y (pixel offset)
			.4byte 1257 * 12 @ .metasprite[1257]
		Actor_E76A: @ Idx: 168
			.2byte 0xE76A, 0 @ id, unk_02(always 0)
			.byte 16, 16 @ w, h (pixel size)
			.byte 8, 8 @ x, y (pixel offset)
			.4byte 1282 * 12 @ .metasprite[1282]
		Actor_E76B: @ Idx: 169
			.2byte 0xE76B, 0 @ id, unk_02(always 0)
			.byte 32, 32 @ w, h (pixel size)
			.byte 16, 16 @ x, y (pixel offset)
			.4byte 1294 * 12 @ .metasprite[1294]
		Actor_D495: @ Idx: 170
			.2byte 0xD495, 0 @ id, unk_02(always 0)
			.byte 32, 32 @ w, h (pixel size)
			.byte 16, 19 @ x, y (pixel offset)
			.4byte 1309 * 12 @ .metasprite[1309]
		Actor_35C7: @ Idx: 171
			.2byte 0x35C7, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 24, 48 @ x, y (pixel offset)
			.4byte 1331 * 12 @ .metasprite[1331]
		Actor_3B53: @ Idx: 172
			.2byte 0x3B53, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 24, 48 @ x, y (pixel offset)
			.4byte 1343 * 12 @ .metasprite[1343]
		Actor_3C13: @ Idx: 173
			.2byte 0x3C13, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 22, 29 @ x, y (pixel offset)
			.4byte 1356 * 12 @ .metasprite[1356]
		Actor_9D3F: @ Idx: 174
			.2byte 0x9D3F, 0 @ id, unk_02(always 0)
			.byte 64, 32 @ w, h (pixel size)
			.byte 20, 20 @ x, y (pixel offset)
			.4byte 1358 * 12 @ .metasprite[1358]
		Actor_7C99: @ Idx: 175
			.2byte 0x7C99, 0 @ id, unk_02(always 0)
			.byte 32, 32 @ w, h (pixel size)
			.byte 28, 4 @ x, y (pixel offset)
			.4byte 1360 * 12 @ .metasprite[1360]
		Actor_B019: @ Idx: 176
			.2byte 0xB019, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 0, 0 @ x, y (pixel offset)
			.4byte 1367 * 12 @ .metasprite[1367]
		Actor_DA09: @ Idx: 177
			.2byte 0xDA09, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 0, 0 @ x, y (pixel offset)
			.4byte 1368 * 12 @ .metasprite[1368]
		Actor_C3BD: @ Idx: 178
			.2byte 0xC3BD, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 0, 0 @ x, y (pixel offset)
			.4byte 1369 * 12 @ .metasprite[1369]
		Actor_9462: @ Idx: 179
			.2byte 0x9462, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 0, 0 @ x, y (pixel offset)
			.4byte 1370 * 12 @ .metasprite[1370]
		Actor_75D6: @ Idx: 180
			.2byte 0x75D6, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 0, 0 @ x, y (pixel offset)
			.4byte 1371 * 12 @ .metasprite[1371]
		Actor_7605: @ Idx: 181
			.2byte 0x7605, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 0, 0 @ x, y (pixel offset)
			.4byte 1372 * 12 @ .metasprite[1372]
		Actor_D291: @ Idx: 182
			.2byte 0xD291, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 30, 40 @ x, y (pixel offset)
			.4byte 1373 * 12 @ .metasprite[1373]
		Actor_D292: @ Idx: 183
			.2byte 0xD292, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 24, 24 @ x, y (pixel offset)
			.4byte 1408 * 12 @ .metasprite[1408]
		Actor_7C07: @ Idx: 184
			.2byte 0x7C07, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 24, 48 @ x, y (pixel offset)
			.4byte 1409 * 12 @ .metasprite[1409]
		Actor_FC07: @ Idx: 185
			.2byte 0xFC07, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 24, 48 @ x, y (pixel offset)
			.4byte 1415 * 12 @ .metasprite[1415]
		Actor_BC08: @ Idx: 186
			.2byte 0xBC08, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 24, 48 @ x, y (pixel offset)
			.4byte 1428 * 12 @ .metasprite[1428]
		Actor_C038: @ Idx: 187
			.2byte 0xC038, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 33, 49 @ x, y (pixel offset)
			.4byte 1437 * 12 @ .metasprite[1437]
		Actor_1D78: @ Idx: 188
			.2byte 0x1D78, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 32, 32 @ x, y (pixel offset)
			.4byte 1454 * 12 @ .metasprite[1454]
		Actor_6154: @ Idx: 189
			.2byte 0x6154, 0 @ id, unk_02(always 0)
			.byte 32, 32 @ w, h (pixel size)
			.byte 7, 5 @ x, y (pixel offset)
			.4byte 1456 * 12 @ .metasprite[1456]
		Actor_17CB: @ Idx: 190
			.2byte 0x17CB, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 24, 0 @ x, y (pixel offset)
			.4byte 1460 * 12 @ .metasprite[1460]
		Actor_BE6D: @ Idx: 191
			.2byte 0xBE6D, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 24, 48 @ x, y (pixel offset)
			.4byte 1462 * 12 @ .metasprite[1462]
		Actor_CC88: @ Idx: 192
			.2byte 0xCC88, 0 @ id, unk_02(always 0)
			.byte 8, 8 @ w, h (pixel size)
			.byte 4, 4 @ x, y (pixel offset)
			.4byte 1473 * 12 @ .metasprite[1473]
		Actor_96B5: @ Idx: 193
			.2byte 0x96B5, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 24, 33 @ x, y (pixel offset)
			.4byte 1477 * 12 @ .metasprite[1477]
		Actor_2C3D: @ Idx: 194
			.2byte 0x2C3D, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 24, 32 @ x, y (pixel offset)
			.4byte 1478 * 12 @ .metasprite[1478]
		Actor_7BE7: @ Idx: 195
			.2byte 0x7BE7, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 24, 48 @ x, y (pixel offset)
			.4byte 1479 * 12 @ .metasprite[1479]
		Actor_D635: @ Idx: 196
			.2byte 0xD635, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 32, 32 @ x, y (pixel offset)
			.4byte 1493 * 12 @ .metasprite[1493]
		Actor_E369: @ Idx: 197
			.2byte 0xE369, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 32, 32 @ x, y (pixel offset)
			.4byte 1557 * 12 @ .metasprite[1557]
		Actor_41CF: @ Idx: 198
			.2byte 0x41CF, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 32, 43 @ x, y (pixel offset)
			.4byte 1575 * 12 @ .metasprite[1575]
		Actor_43CF: @ Idx: 199
			.2byte 0x43CF, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 32, 43 @ x, y (pixel offset)
			.4byte 1628 * 12 @ .metasprite[1628]
		Actor_9D40: @ Idx: 200
			.2byte 0x9D40, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 24, 46 @ x, y (pixel offset)
			.4byte 1672 * 12 @ .metasprite[1672]
		Actor_A874: @ Idx: 201
			.2byte 0xA874, 0 @ id, unk_02(always 0)
			.byte 32, 32 @ w, h (pixel size)
			.byte 16, 16 @ x, y (pixel offset)
			.4byte 1673 * 12 @ .metasprite[1673]
		Actor_A875: @ Idx: 202
			.2byte 0xA875, 0 @ id, unk_02(always 0)
			.byte 8, 8 @ w, h (pixel size)
			.byte 4, 4 @ x, y (pixel offset)
			.4byte 1674 * 12 @ .metasprite[1674]
		Actor_5290: @ Idx: 203
			.2byte 0x5290, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 28, 44 @ x, y (pixel offset)
			.4byte 1675 * 12 @ .metasprite[1675]
		Actor_2110: @ Idx: 204
			.2byte 0x2110, 0 @ id, unk_02(always 0)
			.byte 32, 32 @ w, h (pixel size)
			.byte 16, 32 @ x, y (pixel offset)
			.4byte 1722 * 12 @ .metasprite[1722]
		Actor_2111: @ Idx: 205
			.2byte 0x2111, 0 @ id, unk_02(always 0)
			.byte 16, 16 @ w, h (pixel size)
			.byte 8, 24 @ x, y (pixel offset)
			.4byte 1734 * 12 @ .metasprite[1734]
		Actor_2499: @ Idx: 206
			.2byte 0x2499, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 32, 36 @ x, y (pixel offset)
			.4byte 1737 * 12 @ .metasprite[1737]
		Actor_249A: @ Idx: 207
			.2byte 0x249A, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 32, 36 @ x, y (pixel offset)
			.4byte 1793 * 12 @ .metasprite[1793]
		Actor_5B54: @ Idx: 208
			.2byte 0x5B54, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 24, 48 @ x, y (pixel offset)
			.4byte 1803 * 12 @ .metasprite[1803]
		Actor_04B3: @ Idx: 209
			.2byte 0x04B3, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 24, 56 @ x, y (pixel offset)
			.4byte 1805 * 12 @ .metasprite[1805]
		Actor_4FDA: @ Idx: 210
			.2byte 0x4FDA, 0 @ id, unk_02(always 0)
			.byte 32, 32 @ w, h (pixel size)
			.byte 16, 16 @ x, y (pixel offset)
			.4byte 1807 * 12 @ .metasprite[1807]
		Actor_863A: @ Idx: 211
			.2byte 0x863A, 0 @ id, unk_02(always 0)
			.byte 32, 32 @ w, h (pixel size)
			.byte 12, 24 @ x, y (pixel offset)
			.4byte 1815 * 12 @ .metasprite[1815]
		Actor_8638: @ Idx: 212
			.2byte 0x8638, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 32, 45 @ x, y (pixel offset)
			.4byte 1821 * 12 @ .metasprite[1821]
		Actor_61F9: @ Idx: 213
			.2byte 0x61F9, 0 @ id, unk_02(always 0)
			.byte 32, 32 @ w, h (pixel size)
			.byte 16, 16 @ x, y (pixel offset)
			.4byte 1835 * 12 @ .metasprite[1835]
		Actor_2058: @ Idx: 214
			.2byte 0x2058, 0 @ id, unk_02(always 0)
			.byte 32, 32 @ w, h (pixel size)
			.byte 16, 16 @ x, y (pixel offset)
			.4byte 1893 * 12 @ .metasprite[1893]
		Actor_7ACD: @ Idx: 215
			.2byte 0x7ACD, 0 @ id, unk_02(always 0)
			.byte 64, 128 @ w, h (pixel size)
			.byte 32, 64 @ x, y (pixel offset)
			.4byte 1904 * 12 @ .metasprite[1904]
		Actor_7ACE: @ Idx: 216
			.2byte 0x7ACE, 0 @ id, unk_02(always 0)
			.byte 64, 128 @ w, h (pixel size)
			.byte 32, 64 @ x, y (pixel offset)
			.4byte 1907 * 12 @ .metasprite[1907]
		Actor_7ACF: @ Idx: 217
			.2byte 0x7ACF, 0 @ id, unk_02(always 0)
			.byte 64, 128 @ w, h (pixel size)
			.byte 32, 64 @ x, y (pixel offset)
			.4byte 1910 * 12 @ .metasprite[1910]
		Actor_7AD0: @ Idx: 218
			.2byte 0x7AD0, 0 @ id, unk_02(always 0)
			.byte 64, 128 @ w, h (pixel size)
			.byte 32, 64 @ x, y (pixel offset)
			.4byte 1913 * 12 @ .metasprite[1913]
		Actor_7AD1: @ Idx: 219
			.2byte 0x7AD1, 0 @ id, unk_02(always 0)
			.byte 64, 128 @ w, h (pixel size)
			.byte 32, 64 @ x, y (pixel offset)
			.4byte 1916 * 12 @ .metasprite[1916]
		Actor_2E78: @ Idx: 220
			.2byte 0x2E78, 0 @ id, unk_02(always 0)
			.byte 32, 32 @ w, h (pixel size)
			.byte 16, 16 @ x, y (pixel offset)
			.4byte 1919 * 12 @ .metasprite[1919]
		Actor_2E79: @ Idx: 221
			.2byte 0x2E79, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 36, 44 @ x, y (pixel offset)
			.4byte 1957 * 12 @ .metasprite[1957]
		Actor_2E7A: @ Idx: 222
			.2byte 0x2E7A, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 32, 32 @ x, y (pixel offset)
			.4byte 1970 * 12 @ .metasprite[1970]
		Actor_2E7B: @ Idx: 223
			.2byte 0x2E7B, 0 @ id, unk_02(always 0)
			.byte 16, 16 @ w, h (pixel size)
			.byte 8, 8 @ x, y (pixel offset)
			.4byte 1976 * 12 @ .metasprite[1976]
		Actor_2E7C: @ Idx: 224
			.2byte 0x2E7C, 0 @ id, unk_02(always 0)
			.byte 8, 8 @ w, h (pixel size)
			.byte 4, 4 @ x, y (pixel offset)
			.4byte 1997 * 12 @ .metasprite[1997]
		Actor_9D41: @ Idx: 225
			.2byte 0x9D41, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 24, 46 @ x, y (pixel offset)
			.4byte 2011 * 12 @ .metasprite[2011]
		Actor_A894: @ Idx: 226
			.2byte 0xA894, 0 @ id, unk_02(always 0)
			.byte 32, 32 @ w, h (pixel size)
			.byte 16, 16 @ x, y (pixel offset)
			.4byte 2012 * 12 @ .metasprite[2012]
		Actor_A895: @ Idx: 227
			.2byte 0xA895, 0 @ id, unk_02(always 0)
			.byte 8, 8 @ w, h (pixel size)
			.byte 4, 4 @ x, y (pixel offset)
			.4byte 2013 * 12 @ .metasprite[2013]
		Actor_7AC6: @ Idx: 228
			.2byte 0x7AC6, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 24, 48 @ x, y (pixel offset)
			.4byte 2014 * 12 @ .metasprite[2014]
		Actor_84EE: @ Idx: 229
			.2byte 0x84EE, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 24, 46 @ x, y (pixel offset)
			.4byte 2030 * 12 @ .metasprite[2030]
		Actor_494E: @ Idx: 230
			.2byte 0x494E, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 24, 48 @ x, y (pixel offset)
			.4byte 2034 * 12 @ .metasprite[2034]
		Actor_7BE2: @ Idx: 231
			.2byte 0x7BE2, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 24, 48 @ x, y (pixel offset)
			.4byte 2035 * 12 @ .metasprite[2035]
		Actor_2EC0: @ Idx: 232
			.2byte 0x2EC0, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 24, 24 @ x, y (pixel offset)
			.4byte 2048 * 12 @ .metasprite[2048]
		Actor_DA6D: @ Idx: 233
			.2byte 0xDA6D, 0 @ id, unk_02(always 0)
			.byte 32, 32 @ w, h (pixel size)
			.byte 16, 16 @ x, y (pixel offset)
			.4byte 2049 * 12 @ .metasprite[2049]
		Actor_354D: @ Idx: 234
			.2byte 0x354D, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 63, 55 @ x, y (pixel offset)
			.4byte 2065 * 12 @ .metasprite[2065]
		Actor_39A3: @ Idx: 235
			.2byte 0x39A3, 0 @ id, unk_02(always 0)
			.byte 32, 32 @ w, h (pixel size)
			.byte 16, 16 @ x, y (pixel offset)
			.4byte 2066 * 12 @ .metasprite[2066]
		Actor_1C1D: @ Idx: 236
			.2byte 0x1C1D, 0 @ id, unk_02(always 0)
			.byte 32, 16 @ w, h (pixel size)
			.byte 16, 8 @ x, y (pixel offset)
			.4byte 2067 * 12 @ .metasprite[2067]
		Actor_654B: @ Idx: 237
			.2byte 0x654B, 0 @ id, unk_02(always 0)
			.byte 16, 16 @ w, h (pixel size)
			.byte 8, 8 @ x, y (pixel offset)
			.4byte 2072 * 12 @ .metasprite[2072]
		Actor_B0BC: @ Idx: 238
			.2byte 0xB0BC, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 24, 0 @ x, y (pixel offset)
			.4byte 2088 * 12 @ .metasprite[2088]
		Actor_24BA: @ Idx: 239
			.2byte 0x24BA, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 32, 32 @ x, y (pixel offset)
			.4byte 2090 * 12 @ .metasprite[2090]
		Actor_A945: @ Idx: 240
			.2byte 0xA945, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 0, 0 @ x, y (pixel offset)
			.4byte 2093 * 12 @ .metasprite[2093]
		Actor_70EE: @ Idx: 241
			.2byte 0x70EE, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 0, 0 @ x, y (pixel offset)
			.4byte 2095 * 12 @ .metasprite[2095]
		Actor_6F57: @ Idx: 242
			.2byte 0x6F57, 0 @ id, unk_02(always 0)
			.byte 32, 32 @ w, h (pixel size)
			.byte 16, 0 @ x, y (pixel offset)
			.4byte 2097 * 12 @ .metasprite[2097]
		Actor_0C0A: @ Idx: 243
			.2byte 0x0C0A, 0 @ id, unk_02(always 0)
			.byte 32, 64 @ w, h (pixel size)
			.byte 19, 28 @ x, y (pixel offset)
			.4byte 2110 * 12 @ .metasprite[2110]
		Actor_2567: @ Idx: 244
			.2byte 0x2567, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 32, 40 @ x, y (pixel offset)
			.4byte 2114 * 12 @ .metasprite[2114]
		Actor_DF0E: @ Idx: 245
			.2byte 0xDF0E, 0 @ id, unk_02(always 0)
			.byte 32, 32 @ w, h (pixel size)
			.byte 16, 16 @ x, y (pixel offset)
			.4byte 2115 * 12 @ .metasprite[2115]
		Actor_1E15: @ Idx: 246
			.2byte 0x1E15, 0 @ id, unk_02(always 0)
			.byte 8, 8 @ w, h (pixel size)
			.byte 4, 4 @ x, y (pixel offset)
			.4byte 2116 * 12 @ .metasprite[2116]
		Actor_0DDE: @ Idx: 247
			.2byte 0x0DDE, 0 @ id, unk_02(always 0)
			.byte 32, 64 @ w, h (pixel size)
			.byte 16, 43 @ x, y (pixel offset)
			.4byte 2117 * 12 @ .metasprite[2117]
		Actor_84B4: @ Idx: 248
			.2byte 0x84B4, 0 @ id, unk_02(always 0)
			.byte 128, 128 @ w, h (pixel size)
			.byte 32, 32 @ x, y (pixel offset)
			.4byte 2122 * 12 @ .metasprite[2122]
		Actor_96C1: @ Idx: 249
			.2byte 0x96C1, 0 @ id, unk_02(always 0)
			.byte 128, 128 @ w, h (pixel size)
			.byte 32, 96 @ x, y (pixel offset)
			.4byte 2132 * 12 @ .metasprite[2132]
		Actor_96C2: @ Idx: 250
			.2byte 0x96C2, 0 @ id, unk_02(always 0)
			.byte 32, 32 @ w, h (pixel size)
			.byte 16, 16 @ x, y (pixel offset)
			.4byte 2142 * 12 @ .metasprite[2142]
		Actor_0D44: @ Idx: 251
			.2byte 0x0D44, 0 @ id, unk_02(always 0)
			.byte 64, 64 @ w, h (pixel size)
			.byte 24, 48 @ x, y (pixel offset)
			.4byte 2148 * 12 @ .metasprite[2148]
		Actor_3876: @ Idx: 252
			.2byte 0x3876, 0 @ id, unk_02(always 0)
			.byte 32, 64 @ w, h (pixel size)
			.byte 17, 51 @ x, y (pixel offset)
			.4byte 2156 * 12 @ .metasprite[2156]
	ActorSpriteFile0_Tiles:
    .incbin "data/actor_sprites/B306.4bpp"                 @ 0x08A23510, ActorID: 0xB306, PlttID: 2
    .incbin "data/actor_sprites/F680.4bpp"                 @ 0x08A24910, ActorID: 0xF680, PlttID: 6
    .incbin "data/actor_sprites/A5B3.4bpp"                 @ 0x08A25190, ActorID: 0xA5B3, PlttID: 0
    .incbin "data/actor_sprites/A5B4.4bpp"                 @ 0x08A25210, ActorID: 0xA5B4, PlttID: 0
    .incbin "data/actor_sprites/5AFD.4bpp"                 @ 0x08A25A10, ActorID: 0x5AFD, PlttID: 7
    .incbin "data/actor_sprites/5AFE.4bpp"                 @ 0x08A25E90, ActorID: 0x5AFE, PlttID: 7
    .incbin "data/actor_sprites/48DE.4bpp"                 @ 0x08A26B10, ActorID: 0x48DE, PlttID: 23
    .incbin "data/actor_sprites/D4EE.4bpp"                 @ 0x08A29710, ActorID: 0xD4EE, PlttID: 23
    .incbin "data/actor_sprites/924B.4bpp"                 @ 0x08A2AE30, ActorID: 0x924B, PlttID: 23
    .incbin "data/actor_sprites/2C12.4bpp"                 @ 0x08A2C2F0, ActorID: 0x2C12, PlttID: 28
    .incbin "data/actor_sprites/8F5D.4bpp"                 @ 0x08A2CE70, ActorID: 0x8F5D, PlttID: 29
    .incbin "data/actor_sprites/7AEE.4bpp"                 @ 0x08A2DE70, ActorID: 0x7AEE, PlttID: 42
    .incbin "data/actor_sprites/7AEF.4bpp"                 @ 0x08A2EB70, ActorID: 0x7AEF, PlttID: 42
    .incbin "data/actor_sprites/7AF0.4bpp"                 @ 0x08A2F430, ActorID: 0x7AF0, PlttID: 42
    .incbin "data/actor_sprites/7AF1.4bpp"                 @ 0x08A2FCF0, ActorID: 0x7AF1, PlttID: 42
    .incbin "data/actor_sprites/7AF2.4bpp"                 @ 0x08A309F0, ActorID: 0x7AF2, PlttID: 42
    .incbin "data/actor_sprites/A20C.4bpp"                 @ 0x08A316F0, ActorID: 0xA20C, PlttID: 44
    .incbin "data/actor_sprites/9D2D.4bpp"                 @ 0x08A31770, ActorID: 0x9D2D, PlttID: 51
    .incbin "data/actor_sprites/048A.4bpp"                 @ 0x08A31BF0, ActorID: 0x048A, PlttID: 52
    .incbin "data/actor_sprites/E1D2.4bpp"                 @ 0x08A320F0, ActorID: 0xE1D2, PlttID: 53
    .incbin "data/actor_sprites/B0E2.4bpp"                 @ 0x08A32570, ActorID: 0xB0E2, PlttID: 54
    .incbin "data/actor_sprites/C060.4bpp"                 @ 0x08A32770, ActorID: 0xC060, PlttID: 56
    .incbin "data/actor_sprites/DD5C.4bpp"                 @ 0x08A32970, ActorID: 0xDD5C, PlttID: 60
    .incbin "data/actor_sprites/4AEE.4bpp"                 @ 0x08A33170, ActorID: 0x4AEE, PlttID: 61
    .incbin "data/actor_sprites/A0D5.4bpp"                 @ 0x08A33970, ActorID: 0xA0D5, PlttID: 62
    .incbin "data/actor_sprites/2AF0.4bpp"                 @ 0x08A354B0, ActorID: 0x2AF0, PlttID: 64
    .incbin "data/actor_sprites/A680.4bpp"                 @ 0x08A36CB0, ActorID: 0xA680, PlttID: 66
    .incbin "data/actor_sprites/A6A0.4bpp"                 @ 0x08A39930, ActorID: 0xA6A0, PlttID: 71
    .incbin "data/actor_sprites/2D41.4bpp"                 @ 0x08A39CD0, ActorID: 0x2D41, PlttID: 72
    .incbin "data/actor_sprites/A850.4bpp"                 @ 0x08A3BFD0, ActorID: 0xA850, PlttID: 73
    .incbin "data/actor_sprites/9D43.4bpp"                 @ 0x08A3C1D0, ActorID: 0x9D43, PlttID: 79
    .incbin "data/actor_sprites/008A.4bpp"                 @ 0x08A3C7D0, ActorID: 0x008A, PlttID: 80
    .incbin "data/actor_sprites/76DB.4bpp"                 @ 0x08A3D3D0, ActorID: 0x76DB, PlttID: 83
    .incbin "data/actor_sprites/2712.4bpp"                 @ 0x08A3E010, ActorID: 0x2712, PlttID: 86
    .incbin "data/actor_sprites/5DC0.4bpp"                 @ 0x08A3E410, ActorID: 0x5DC0, PlttID: 87
    .incbin "data/actor_sprites/6AF6.4bpp"                 @ 0x08A3FC10, ActorID: 0x6AF6, PlttID: 89
    .incbin "data/actor_sprites/4AAE.4bpp"                 @ 0x08A403F0, ActorID: 0x4AAE, PlttID: 91
    .incbin "data/actor_sprites/1C1B.4bpp"                 @ 0x08A405F0, ActorID: 0x1C1B, PlttID: 0
    .incbin "data/actor_sprites/9FF5.4bpp"                 @ 0x08A412B0, ActorID: 0x9FF5, PlttID: 0
    .incbin "data/actor_sprites/A606.4bpp"                 @ 0x08A41410, ActorID: 0xA606, PlttID: 83
    .incbin "data/actor_sprites/D28E.4bpp"                 @ 0x08A43BD0, ActorID: 0xD28E, PlttID: 92
    .incbin "data/actor_sprites/D166.4bpp"                 @ 0x08A450D0, ActorID: 0xD166, PlttID: 95
    .incbin "data/actor_sprites/0BA8.4bpp"                 @ 0x08A45810, ActorID: 0x0BA8, PlttID: 97
    .incbin "data/actor_sprites/0BA9.4bpp"                 @ 0x08A48A10, ActorID: 0x0BA9, PlttID: 97
    .incbin "data/actor_sprites/363C.4bpp"                 @ 0x08A49210, ActorID: 0x363C, PlttID: 0
    .incbin "data/actor_sprites/363D.4bpp"                 @ 0x08A49430, ActorID: 0x363D, PlttID: 0
    .incbin "data/actor_sprites/1FBD.4bpp"                 @ 0x08A49B30, ActorID: 0x1FBD, PlttID: 112
    .incbin "data/actor_sprites/6AF7.4bpp"                 @ 0x08A49E30, ActorID: 0x6AF7, PlttID: 89
    .incbin "data/actor_sprites/1B59.4bpp"                 @ 0x08A4A0B0, ActorID: 0x1B59, PlttID: 115
    .incbin "data/actor_sprites/7E82.4bpp"                 @ 0x08A4ACB0, ActorID: 0x7E82, PlttID: 116
    .incbin "data/actor_sprites/BCA8.4bpp"                 @ 0x08A4B0B0, ActorID: 0xBCA8, PlttID: 120
    .incbin "data/actor_sprites/4384.4bpp"                 @ 0x08A4B970, ActorID: 0x4384, PlttID: 125
    .incbin "data/actor_sprites/4385.4bpp"                 @ 0x08A4C7D0, ActorID: 0x4385, PlttID: 130
    .incbin "data/actor_sprites/05A2.4bpp"                 @ 0x08A4C890, ActorID: 0x05A2, PlttID: 139
    .incbin "data/actor_sprites/34C0.4bpp"                 @ 0x08A4CD90, ActorID: 0x34C0, PlttID: 142
    .incbin "data/actor_sprites/spider.4bpp"               @ 0x08A4D090, ActorID: 0x528F, PlttID: 143
    .incbin "data/actor_sprites/7AD2.4bpp"                 @ 0x08A4EF50, ActorID: 0x7AD2, PlttID: 146
    .incbin "data/actor_sprites/B96C.4bpp"                 @ 0x08A4FB50, ActorID: 0xB96C, PlttID: 147
    .incbin "data/actor_sprites/7031.4bpp"                 @ 0x08A51590, ActorID: 0x7031, PlttID: 147
    .incbin "data/actor_sprites/7032.4bpp"                 @ 0x08A51610, ActorID: 0x7032, PlttID: 147
    .incbin "data/actor_sprites/E857.4bpp"                 @ 0x08A51670, ActorID: 0xE857, PlttID: 83
    .incbin "data/actor_sprites/3641.4bpp"                 @ 0x08A54670, ActorID: 0x3641, PlttID: 44
    .incbin "data/actor_sprites/F070.4bpp"                 @ 0x08A54A70, ActorID: 0xF070, PlttID: 151
    .incbin "data/actor_sprites/C3C3.4bpp"                 @ 0x08A557B0, ActorID: 0xC3C3, PlttID: 95
    .incbin "data/actor_sprites/1C84.4bpp"                 @ 0x08A56A30, ActorID: 0x1C84, PlttID: 153
    .incbin "data/actor_sprites/E505.4bpp"                 @ 0x08A57230, ActorID: 0xE505, PlttID: 83
    .incbin "data/actor_sprites/FDC5.4bpp"                 @ 0x08A5A9B0, ActorID: 0xFDC5, PlttID: 165
    .incbin "data/actor_sprites/96F7.4bpp"                 @ 0x08A5C170, ActorID: 0x96F7, PlttID: 166
    .incbin "data/actor_sprites/A5BD.4bpp"                 @ 0x08A5C270, ActorID: 0xA5BD, PlttID: 0
    .incbin "data/actor_sprites/7AD3.4bpp"                 @ 0x08A5C370, ActorID: 0x7AD3, PlttID: 167
    .incbin "data/actor_sprites/7AD4.4bpp"                 @ 0x08A5D070, ActorID: 0x7AD4, PlttID: 167
    .incbin "data/actor_sprites/7AD5.4bpp"                 @ 0x08A5D930, ActorID: 0x7AD5, PlttID: 167
    .incbin "data/actor_sprites/7AD6.4bpp"                 @ 0x08A5E1F0, ActorID: 0x7AD6, PlttID: 167
    .incbin "data/actor_sprites/7AED.4bpp"                 @ 0x08A5EEF0, ActorID: 0x7AED, PlttID: 167
    .incbin "data/actor_sprites/7AF3.4bpp"                 @ 0x08A5FBF0, ActorID: 0x7AF3, PlttID: 175
    .incbin "data/actor_sprites/7AF4.4bpp"                 @ 0x08A608F0, ActorID: 0x7AF4, PlttID: 175
    .incbin "data/actor_sprites/7AF5.4bpp"                 @ 0x08A611B0, ActorID: 0x7AF5, PlttID: 175
    .incbin "data/actor_sprites/7AF6.4bpp"                 @ 0x08A61A70, ActorID: 0x7AF6, PlttID: 175
    .incbin "data/actor_sprites/7B0D.4bpp"                 @ 0x08A62770, ActorID: 0x7B0D, PlttID: 175
    .incbin "data/actor_sprites/9506.4bpp"                 @ 0x08A63470, ActorID: 0x9506, PlttID: 176
    .incbin "data/actor_sprites/22E7.4bpp"                 @ 0x08A64ED0, ActorID: 0x22E7, PlttID: 83
    .incbin "data/actor_sprites/41B1.4bpp"                 @ 0x08A69550, ActorID: 0x41B1, PlttID: 179
    .incbin "data/actor_sprites/DC8E.4bpp"                 @ 0x08A69DB0, ActorID: 0xDC8E, PlttID: 181
    .incbin "data/actor_sprites/CDAB.4bpp"                 @ 0x08A6A5B0, ActorID: 0xCDAB, PlttID: 187
    .incbin "data/actor_sprites/D962.4bpp"                 @ 0x08A6A8B0, ActorID: 0xD962, PlttID: 188
    .incbin "data/actor_sprites/B044.4bpp"                 @ 0x08A6C8B0, ActorID: 0xB044, PlttID: 42
    .incbin "data/actor_sprites/3668.4bpp"                 @ 0x08A6CBB0, ActorID: 0x3668, PlttID: 195
    .incbin "data/actor_sprites/18A8.4bpp"                 @ 0x08A6D7D0, ActorID: 0x18A8, PlttID: 207
    .incbin "data/actor_sprites/18A9.4bpp"                 @ 0x08A6D9D0, ActorID: 0x18A9, PlttID: 207
    .incbin "data/actor_sprites/2769.4bpp"                 @ 0x08A6DC90, ActorID: 0x2769, PlttID: 208
    .incbin "data/actor_sprites/5B78.4bpp"                 @ 0x08A6DF30, ActorID: 0x5B78, PlttID: 213
    .incbin "data/actor_sprites/16F5.4bpp"                 @ 0x08A6E3B0, ActorID: 0x16F5, PlttID: 97
    .incbin "data/actor_sprites/F422.4bpp"                 @ 0x08A6F7B0, ActorID: 0xF422, PlttID: 216
    .incbin "data/actor_sprites/848F.4bpp"                 @ 0x08A72470, ActorID: 0x848F, PlttID: 216
    .incbin "data/actor_sprites/8490.4bpp"                 @ 0x08A72AF0, ActorID: 0x8490, PlttID: 216
    .incbin "data/actor_sprites/D638.4bpp"                 @ 0x08A743B0, ActorID: 0xD638, PlttID: 220
    .incbin "data/actor_sprites/EF69.4bpp"                 @ 0x08A7D5F0, ActorID: 0xEF69, PlttID: 220
    .incbin "data/actor_sprites/5BA7.4bpp"                 @ 0x08A7D770, ActorID: 0x5BA7, PlttID: 236
    .incbin "data/actor_sprites/5BB7.4bpp"                 @ 0x08A7DBF0, ActorID: 0x5BB7, PlttID: 239
    .incbin "data/actor_sprites/E74B.4bpp"                 @ 0x08A7DF70, ActorID: 0xE74B, PlttID: 0
    .incbin "data/actor_sprites/9A1F.4bpp"                 @ 0x08A7EB70, ActorID: 0x9A1F, PlttID: 242
    .incbin "data/actor_sprites/C459.4bpp"                 @ 0x08A7F0F0, ActorID: 0xC459, PlttID: 243
    .incbin "data/actor_sprites/DC07.4bpp"                 @ 0x08A7F4F0, ActorID: 0xDC07, PlttID: 244
    .incbin "data/actor_sprites/D45E.4bpp"                 @ 0x08A7F970, ActorID: 0xD45E, PlttID: 247
    .incbin "data/actor_sprites/D85E.4bpp"                 @ 0x08A84930, ActorID: 0xD85E, PlttID: 247
    .incbin "data/actor_sprites/2817.4bpp"                 @ 0x08A86970, ActorID: 0x2817, PlttID: 263
    .incbin "data/actor_sprites/EFD8.4bpp"                 @ 0x08A869B0, ActorID: 0xEFD8, PlttID: 268
    .incbin "data/actor_sprites/8639.4bpp"                 @ 0x08A87A30, ActorID: 0x8639, PlttID: 275
    .incbin "data/actor_sprites/otnk_0.4bpp"               @ 0x08A89A30, ActorID: 0x97D3, PlttID: 279
    .incbin "data/actor_sprites/otnk_1.4bpp"               @ 0x08A8B4F0, ActorID: 0x97D4, PlttID: 279
    .incbin "data/actor_sprites/C42D.4bpp"                 @ 0x08A8C330, ActorID: 0xC42D, PlttID: 283
    .incbin "data/actor_sprites/0334.4bpp"                 @ 0x08A8C530, ActorID: 0x0334, PlttID: 283
    .incbin "data/actor_sprites/9DFF.4bpp"                 @ 0x08A8C550, ActorID: 0x9DFF, PlttID: 83
    .incbin "data/actor_sprites/A152.4bpp"                 @ 0x08A8D150, ActorID: 0xA152, PlttID: 284
    .incbin "data/actor_sprites/17C7.4bpp"                 @ 0x08A8D5D0, ActorID: 0x17C7, PlttID: 287
    .incbin "data/actor_sprites/210E.4bpp"                 @ 0x08A8DBD0, ActorID: 0x210E, PlttID: 44
    .incbin "data/actor_sprites/210F.4bpp"                 @ 0x08A8DDD0, ActorID: 0x210F, PlttID: 289
    .incbin "data/actor_sprites/1FE0.4bpp"                 @ 0x08A8E490, ActorID: 0x1FE0, PlttID: 83
    .incbin "data/actor_sprites/2C1A.4bpp"                 @ 0x08A92690, ActorID: 0x2C1A, PlttID: 300
    .incbin "data/actor_sprites/5291.4bpp"                 @ 0x08A92990, ActorID: 0x5291, PlttID: 301
    .incbin "data/actor_sprites/5292.4bpp"                 @ 0x08A93190, ActorID: 0x5292, PlttID: 301
    .incbin "data/actor_sprites/9247.4bpp"                 @ 0x08A93550, ActorID: 0x9247, PlttID: 306
    .incbin "data/actor_sprites/D4EA.4bpp"                 @ 0x08A94C10, ActorID: 0xD4EA, PlttID: 306
    .incbin "data/actor_sprites/47DE.4bpp"                 @ 0x08A95C10, ActorID: 0x47DE, PlttID: 306
    .incbin "data/actor_sprites/C046.4bpp"                 @ 0x08A981D0, ActorID: 0xC046, PlttID: 311
    .incbin "data/actor_sprites/2097.4bpp"                 @ 0x08A993D0, ActorID: 0x2097, PlttID: 312
    .incbin "data/actor_sprites/17C8.4bpp"                 @ 0x08A9DBD0, ActorID: 0x17C8, PlttID: 287
    .incbin "data/actor_sprites/BB68.4bpp"                 @ 0x08A9E1D0, ActorID: 0xBB68, PlttID: 313
    .incbin "data/actor_sprites/EED8.4bpp"                 @ 0x08A9F050, ActorID: 0xEED8, PlttID: 315
    .incbin "data/actor_sprites/505C.4bpp"                 @ 0x08A9FA50, ActorID: 0x505C, PlttID: 316
    .incbin "data/actor_sprites/A47C.4bpp"                 @ 0x08A9FDD0, ActorID: 0xA47C, PlttID: 317
    .incbin "data/actor_sprites/DDE7.4bpp"                 @ 0x08AA0090, ActorID: 0xDDE7, PlttID: 326
    .incbin "data/actor_sprites/9E08.4bpp"                 @ 0x08AA0510, ActorID: 0x9E08, PlttID: 329
    .incbin "data/actor_sprites/A8E7.4bpp"                 @ 0x08AA0990, ActorID: 0xA8E7, PlttID: 0
    .incbin "data/actor_sprites/5A6E.4bpp"                 @ 0x08AA0AF0, ActorID: 0x5A6E, PlttID: 332
    .incbin "data/actor_sprites/5A6F.4bpp"                 @ 0x08AA25B0, ActorID: 0x5A6F, PlttID: 332
    .incbin "data/actor_sprites/44EE.4bpp"                 @ 0x08AA32D0, ActorID: 0x44EE, PlttID: 337
    .incbin "data/actor_sprites/5D7C.4bpp"                 @ 0x08AA38D0, ActorID: 0x5D7C, PlttID: 338
    .incbin "data/actor_sprites/B837.4bpp"                 @ 0x08AA40D0, ActorID: 0xB837, PlttID: 339
    .incbin "data/actor_sprites/E0C9.4bpp"                 @ 0x08AA4C10, ActorID: 0xE0C9, PlttID: 340
    .incbin "data/actor_sprites/8203.4bpp"                 @ 0x08AA5210, ActorID: 0x8203, PlttID: 341
    .incbin "data/actor_sprites/8204.4bpp"                 @ 0x08AA6B10, ActorID: 0x8204, PlttID: 341
    .incbin "data/actor_sprites/8205.4bpp"                 @ 0x08AA6DD0, ActorID: 0x8205, PlttID: 350
    .incbin "data/actor_sprites/8202.4bpp"                 @ 0x08AA6FD0, ActorID: 0x8202, PlttID: 350
    .incbin "data/actor_sprites/8206.4bpp"                 @ 0x08AA7650, ActorID: 0x8206, PlttID: 341
    .incbin "data/actor_sprites/8207.4bpp"                 @ 0x08AA7950, ActorID: 0x8207, PlttID: 341
    .incbin "data/actor_sprites/DC38.4bpp"                 @ 0x08AA7A30, ActorID: 0xDC38, PlttID: 83
    .incbin "data/actor_sprites/8393.4bpp"                 @ 0x08AAB1D0, ActorID: 0x8393, PlttID: 83
    .incbin "data/actor_sprites/066A.4bpp"                 @ 0x08AB09D0, ActorID: 0x066A, PlttID: 361
    .incbin "data/actor_sprites/17C9.4bpp"                 @ 0x08AB0DD0, ActorID: 0x17C9, PlttID: 287
    .incbin "data/actor_sprites/DB6C.4bpp"                 @ 0x08AB0FD0, ActorID: 0xDB6C, PlttID: 363
    .incbin "data/actor_sprites/D0A3.4bpp"                 @ 0x08AB17D0, ActorID: 0xD0A3, PlttID: 379
    .incbin "data/actor_sprites/9385.4bpp"                 @ 0x08AB1A10, ActorID: 0x9385, PlttID: 380
    .incbin "data/actor_sprites/B626.4bpp"                 @ 0x08AB1E90, ActorID: 0xB626, PlttID: 380
    .incbin "data/actor_sprites/D637.4bpp"                 @ 0x08AB20F0, ActorID: 0xD637, PlttID: 381
    .incbin "data/actor_sprites/E7EA.4bpp"                 @ 0x08AB49B0, ActorID: 0xE7EA, PlttID: 386
    .incbin "data/actor_sprites/DFCF.4bpp"                 @ 0x08AB4A50, ActorID: 0xDFCF, PlttID: 387
    .incbin "data/actor_sprites/0E48.4bpp"                 @ 0x08AB60D0, ActorID: 0x0E48, PlttID: 388
    .incbin "data/actor_sprites/DC72.4bpp"                 @ 0x08AB6210, ActorID: 0xDC72, PlttID: 181
    .incbin "data/actor_sprites/C039.4bpp"                 @ 0x08AB6330, ActorID: 0xC039, PlttID: 392
    .incbin "data/actor_sprites/9803.4bpp"                 @ 0x08AB6B30, ActorID: 0x9803, PlttID: 83
    .incbin "data/actor_sprites/D56D.4bpp"                 @ 0x08ABC330, ActorID: 0xD56D, PlttID: 404
    .incbin "data/actor_sprites/17CA.4bpp"                 @ 0x08ABC850, ActorID: 0x17CA, PlttID: 287
    .incbin "data/actor_sprites/3640.4bpp"                 @ 0x08ABCF50, ActorID: 0x3640, PlttID: 410
    .incbin "data/actor_sprites/9B09.4bpp"                 @ 0x08ABEF50, ActorID: 0x9B09, PlttID: 83
    .incbin "data/actor_sprites/D454.4bpp"                 @ 0x08AC23D0, ActorID: 0xD454, PlttID: 83
		.incbin "data/actor_sprites/D636.4bpp"                 @ 0x08AC4D70, ActorID: 0xD636, PlttID: 417, centipede & sandworm & serpent
		.incbin "data/actor_sprites/E769.4bpp"                 @ 0x08AC9850, ActorID: 0xE769, PlttID: 418, sandworm & serpent
		.incbin "data/actor_sprites/E76A.4bpp"                 @ 0x08ACE9F0, ActorID: 0xE76A, PlttID: 421, unk_flame_snake?
		.incbin "data/actor_sprites/E76B.4bpp"                 @ 0x08ACEFF0, ActorID: 0xE76B, PlttID: 421, unk_flame_snake?
		.incbin "data/actor_sprites/mouse.4bpp"                @ 0x08AD07B0, ActorID: 0xD495, PlttID: 29
		.incbin "data/actor_sprites/35C7.4bpp"                 @ 0x08AD15B0, ActorID: 0x35C7, PlttID: 83
		.incbin "data/actor_sprites/3B53.4bpp"                 @ 0x08AD5270, ActorID: 0x3B53, PlttID: 83
		.incbin "data/actor_sprites/pinpad.4bpp"               @ 0x08AD9DF0, ActorID: 0x3C13, PlttID: 433, 時の家の暗証番号設定端末
		.incbin "data/actor_sprites/9D3F.4bpp"                 @ 0x08ADA9F0, ActorID: 0x9D3F, PlttID: 435, "オフセット"(=offset), "20・20"(=32x32) というデバッグ用の文字列がある
		.incbin "data/actor_sprites/emblem_element.4bpp"       @ 0x08ADADB0, ActorID: 0x7C99, PlttID: 438, 各属性のエンブレム(パズルの床に使うデカール?)
		.incbin "data/actor_sprites/B019.4bpp"                 @ 0x08ADB9D0, ActorID: 0xB019, PlttID: 439, elevator lift
		.incbin "data/actor_sprites/DA09.4bpp"                 @ 0x08ADBE50, ActorID: 0xDA09, PlttID: 439, elevator lift
		.incbin "data/actor_sprites/C3BD.4bpp"                 @ 0x08ADC450, ActorID: 0xC3BD, PlttID: 439, elevator lift
		.incbin "data/actor_sprites/9462.4bpp"                 @ 0x08ADCA50, ActorID: 0x9462, PlttID: 439, elevator lift
		.incbin "data/actor_sprites/75D6.4bpp"                 @ 0x08ADD050, ActorID: 0x75D6, PlttID: 439, elevator lift
		.incbin "data/actor_sprites/7605.4bpp"                 @ 0x08ADD4D0, ActorID: 0x7605, PlttID: 439, elevator lift
		.incbin "data/actor_sprites/octopus.4bpp"              @ 0x08ADD950, ActorID: 0xD291, PlttID: 447
		.incbin "data/actor_sprites/water_silhouette.4bpp"     @ 0x08AE3F50, ActorID: 0xD292, PlttID: 447, 多分オクトパスが水中にいるときのシルエット
		.incbin "data/actor_sprites/7C07.4bpp"                 @ 0x08AE4110, ActorID: 0x7C07, PlttID: 83
		.incbin "data/actor_sprites/FC07.4bpp"                 @ 0x08AE6510, ActorID: 0xFC07, PlttID: 83
		.incbin "data/actor_sprites/BC08.4bpp"                 @ 0x08AEB310, ActorID: 0xBC08, PlttID: 83
		.incbin "data/actor_sprites/generator.4bpp"            @ 0x08AEE910, ActorID: 0xC038, PlttID: 451, パイルドライバーのジェネレータ
		.incbin "data/actor_sprites/1D78.4bpp"                 @ 0x08AF4590, ActorID: 0x1D78, PlttID: 460
		.incbin "data/actor_sprites/6154.4bpp"                 @ 0x08AF5210, ActorID: 0x6154, PlttID: 466, トーチ?
		.incbin "data/actor_sprites/weight_switch_17CB.4bpp"   @ 0x08AF5790, ActorID: 0x17CB, PlttID: 287
		.incbin "data/actor_sprites/BE6D.4bpp"                 @ 0x08AF5E90, ActorID: 0xBE6D, PlttID: 83
		.incbin "data/actor_sprites/CC88.4bpp"                 @ 0x08AF9E50, ActorID: 0xCC88, PlttID: 467
		.incbin "data/actor_sprites/desert_monolith.4bpp"      @ 0x08AF9ED0, ActorID: 0x96B5, PlttID: 482, 砂漠の(3つの石板のことが書いてある)石碑
		.incbin "data/actor_sprites/dried_oasis.4bpp"          @ 0x08AFA4D0, ActorID: 0x2C3D, PlttID: 498, 3つの石板を探す砂漠で砂漠入り口から1つ上のマップにある干上がったオアシス
		.incbin "data/actor_sprites/7BE7.4bpp"                 @ 0x08AFACD0, ActorID: 0x7BE7, PlttID: 83
		.incbin "data/actor_sprites/dog_0.4bpp"                @ 0x08AFFF50, ActorID: 0xD635, PlttID: 501
		.incbin "data/actor_sprites/dog_1.4bpp"                @ 0x08B0DA50, ActorID: 0xE369, PlttID: 501
		.incbin "data/actor_sprites/cockatrice_0.4bpp"         @ 0x08B10F50, ActorID: 0x41CF, PlttID: 506
		.incbin "data/actor_sprites/cockatrice_1.4bpp"         @ 0x08B1B230, ActorID: 0x43CF, PlttID: 506
		.incbin "data/actor_sprites/cube_wood.4bpp"            @ 0x08B23030, ActorID: 0x9D40, PlttID: 509, 木ブロック
		.incbin "data/actor_sprites/cube_wood_debris_l.4bpp"   @ 0x08B23630, ActorID: 0xA874, PlttID: 509, 木ブロックの破片(大)
		.incbin "data/actor_sprites/cube_wood_debris_s.4bpp"   @ 0x08B23830, ActorID: 0xA875, PlttID: 509, 木ブロックの破片(小)
		.incbin "data/actor_sprites/golem.4bpp"                @ 0x08B23850, ActorID: 0x5290, PlttID: 513
		.incbin "data/actor_sprites/2110.4bpp"                 @ 0x08B2A1B0, ActorID: 0x2110, PlttID: 44
		.incbin "data/actor_sprites/2111.4bpp"                 @ 0x08B2B9B0, ActorID: 0x2111, PlttID: 44
		.incbin "data/actor_sprites/coffin.4bpp"               @ 0x08B2BB30, ActorID: 0x2499, PlttID: 519, 全ての棺桶(エレファン含む), TODO: 画像を棺桶ごとに分けてパレットをちゃんと適用する
		.incbin "data/actor_sprites/elefan.4bpp"               @ 0x08B358F0, ActorID: 0x249A, PlttID: 524, 棺桶獣エレファン(自走時?)
		.incbin "data/actor_sprites/5B54.4bpp"                 @ 0x08B37650, ActorID: 0x5B54, PlttID: 529, ダイナマイトで壊せる壁
		.incbin "data/actor_sprites/cactus.4bpp"               @ 0x08B38250, ActorID: 0x04B3, PlttID: 283
		.incbin "data/actor_sprites/4FDA.4bpp"                 @ 0x08B38E50, ActorID: 0x4FDA, PlttID: 531
		.incbin "data/actor_sprites/863A.4bpp"                 @ 0x08B39E50, ActorID: 0x863A, PlttID: 275
		.incbin "data/actor_sprites/8638.4bpp"                 @ 0x08B3A670, ActorID: 0x8638, PlttID: 275
		.incbin "data/actor_sprites/duneyrr.4bpp"              @ 0x08B3D110, ActorID: 0x61F9, PlttID: 547, ドゥネイルの出すエフェクトや芋虫(ドゥネイル本体は spriteset)
		.incbin "data/actor_sprites/2058.4bpp"                 @ 0x08B43130, ActorID: 0x2058, PlttID: 558, 武器屋(シャイアンの店)の内装?
		.incbin "data/actor_sprites/7ACD.4bpp"                 @ 0x08B44370, ActorID: 0x7ACD, PlttID: 559, ドア(木)
		.incbin "data/actor_sprites/7ACE.4bpp"                 @ 0x08B45070, ActorID: 0x7ACE, PlttID: 559, ドア(木)
		.incbin "data/actor_sprites/7ACF.4bpp"                 @ 0x08B45930, ActorID: 0x7ACF, PlttID: 559, ドア(木)
		.incbin "data/actor_sprites/7AD0.4bpp"                 @ 0x08B461F0, ActorID: 0x7AD0, PlttID: 559, ドア(木)
		.incbin "data/actor_sprites/7AD1.4bpp"                 @ 0x08B46EF0, ActorID: 0x7AD1, PlttID: 559, ドア(木)
		.incbin "data/actor_sprites/2E78.4bpp"                 @ 0x08B47BF0, ActorID: 0x2E78, PlttID: 561, ドヴァリン
		.incbin "data/actor_sprites/2E79.4bpp"                 @ 0x08B4BED0, ActorID: 0x2E79, PlttID: 561, ドヴァリン
		.incbin "data/actor_sprites/2E7A.4bpp"                 @ 0x08B4F2F0, ActorID: 0x2E7A, PlttID: 561, ドヴァリン
		.incbin "data/actor_sprites/2E7B.4bpp"                 @ 0x08B50AF0, ActorID: 0x2E7B, PlttID: 561, ドヴァリン
		.incbin "data/actor_sprites/2E7C.4bpp"                 @ 0x08B51570, ActorID: 0x2E7C, PlttID: 561, ドヴァリン
		.incbin "data/actor_sprites/cube_rock.4bpp"            @ 0x08B51730, ActorID: 0x9D41, PlttID: 573, 岩ブロック
		.incbin "data/actor_sprites/cube_rock_debris_l.4bpp"   @ 0x08B51D30, ActorID: 0xA894, PlttID: 573, 岩ブロックの破片(大)
		.incbin "data/actor_sprites/cube_rock_debris_s.4bpp"   @ 0x08B51EB0, ActorID: 0xA895, PlttID: 573, 岩ブロックの破片(小)
		.incbin "data/actor_sprites/7AC6.4bpp"                 @ 0x08B51ED0, ActorID: 0x7AC6, PlttID: 83
		.incbin "data/actor_sprites/cube_ice.4bpp"             @ 0x08B57470, ActorID: 0x84EE, PlttID: 577
		.incbin "data/actor_sprites/ruins_pillar.4bpp"         @ 0x08B58670, ActorID: 0x494E, PlttID: 593, 遺跡ステージ前半の柱
		.incbin "data/actor_sprites/7BE2.4bpp"                 @ 0x08B58C70, ActorID: 0x7BE2, PlttID: 83
		.incbin "data/actor_sprites/2EC0.4bpp"                 @ 0x08B5D490, ActorID: 0x2EC0, PlttID: 594, 遺跡ステージの4人の燭台の床パネル?
		.incbin "data/actor_sprites/bat.4bpp"                  @ 0x08B5D910, ActorID: 0xDA6D, PlttID: 610
		.incbin "data/actor_sprites/354D.4bpp"                 @ 0x08B5E330, ActorID: 0x354D, PlttID: 627
		.incbin "data/actor_sprites/shaian_ax.4bpp"            @ 0x08B5E830, ActorID: 0x39A3, PlttID: 626
		.incbin "data/actor_sprites/level_up_indicator.4bpp"   @ 0x08B5E950, ActorID: 0x1C1D, PlttID: 44
		.incbin "data/actor_sprites/gameover.4bpp"             @ 0x08B5EE50, ActorID: 0x654B, PlttID: 634
		.incbin "data/actor_sprites/weight_switch.4bpp"        @ 0x08B5F650, ActorID: 0xB0BC, PlttID: 287
		.incbin "data/actor_sprites/spike_ball.4bpp"           @ 0x08B5FF50, ActorID: 0x24BA, PlttID: 637
		.incbin "data/actor_sprites/A945.4bpp"                 @ 0x08B60750, ActorID: 0xA945, PlttID: 642, 落とし穴
		.incbin "data/actor_sprites/70EE.4bpp"                 @ 0x08B61050, ActorID: 0x70EE, PlttID: 642, 落とし穴
		.incbin "data/actor_sprites/6F57.4bpp"                 @ 0x08B61950, ActorID: 0x6F57, PlttID: 645
		.incbin "data/actor_sprites/tower_clock.4bpp"          @ 0x08B62CD0, ActorID: 0x0C0A, PlttID: 646
		.incbin "data/actor_sprites/2567.4bpp"                 @ 0x08B63CD0, ActorID: 0x2567, PlttID: 647, 暗黒樹のもじゃもじゃ?
		.incbin "data/actor_sprites/DF0E.4bpp"                 @ 0x08B641D0, ActorID: 0xDF0E, PlttID: 647, 暗黒樹の蔓?
		.incbin "data/actor_sprites/1E15.4bpp"                 @ 0x08B643D0, ActorID: 0x1E15, PlttID: 647, 暗黒樹の芽?
		.incbin "data/actor_sprites/0DDE.4bpp"                 @ 0x08B643F0, ActorID: 0x0DDE, PlttID: 649
		.incbin "data/actor_sprites/84B4.4bpp"                 @ 0x08B64C50, ActorID: 0x84B4, PlttID: 501
		.incbin "data/actor_sprites/96C1.4bpp"                 @ 0x08B678F0, ActorID: 0x96C1, PlttID: 501
		.incbin "data/actor_sprites/96C2.4bpp"                 @ 0x08B6A050, ActorID: 0x96C2, PlttID: 501
		.incbin "data/actor_sprites/0D44.4bpp"                 @ 0x08B6AB90, ActorID: 0x0D44, PlttID: 83
		.incbin "data/actor_sprites/mimic.4bpp"                @ 0x08B6D8D0, ActorID: 0x3876, PlttID: 650
	ActorSpriteFile0_Metaprites:
		Metaprite_0:
			.byte 3, 40 @ subspriteCount, unk_01
			.2byte 2 @ plttID
			.4byte 0 << 5, 0 << 2 @ .tiles[0], .subsprites[0]
		Metaprite_1:
			.byte 3, 40 @ subspriteCount, unk_01
			.2byte 2 @ plttID
			.4byte 40 << 5, 3 << 2 @ .tiles[40], .subsprites[3]
		Metaprite_2:
			.byte 3, 40 @ subspriteCount, unk_01
			.2byte 2 @ plttID
			.4byte 80 << 5, 6 << 2 @ .tiles[80], .subsprites[6]
		Metaprite_3:
			.byte 3, 40 @ subspriteCount, unk_01
			.2byte 2 @ plttID
			.4byte 120 << 5, 9 << 2 @ .tiles[120], .subsprites[9]
		Metaprite_4:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 6 @ plttID
			.4byte 160 << 5, 12 << 2 @ .tiles[160], .subsprites[12]
		Metaprite_5:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 6 @ plttID
			.4byte 208 << 5, 15 << 2 @ .tiles[208], .subsprites[15]
		Metaprite_6:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 228 << 5, 17 << 2 @ .tiles[228], .subsprites[17]
		Metaprite_7:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 232 << 5, 18 << 2 @ .tiles[232], .subsprites[18]
		Metaprite_8:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 248 << 5, 19 << 2 @ .tiles[248], .subsprites[19]
		Metaprite_9:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 264 << 5, 20 << 2 @ .tiles[264], .subsprites[20]
		Metaprite_10:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 280 << 5, 21 << 2 @ .tiles[280], .subsprites[21]
		Metaprite_11:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 7 @ plttID
			.4byte 296 << 5, 22 << 2 @ .tiles[296], .subsprites[22]
		Metaprite_12:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 7 @ plttID
			.4byte 308 << 5, 25 << 2 @ .tiles[308], .subsprites[25]
		Metaprite_13:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 7 @ plttID
			.4byte 320 << 5, 28 << 2 @ .tiles[320], .subsprites[28]
		Metaprite_14:
			.byte 4, 36 @ subspriteCount, unk_01
			.2byte 7 @ plttID
			.4byte 332 << 5, 31 << 2 @ .tiles[332], .subsprites[31]
		Metaprite_15:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 7 @ plttID
			.4byte 368 << 5, 35 << 2 @ .tiles[368], .subsprites[35]
		Metaprite_16:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 7 @ plttID
			.4byte 384 << 5, 36 << 2 @ .tiles[384], .subsprites[36]
		Metaprite_17:
			.byte 4, 36 @ subspriteCount, unk_01
			.2byte 7 @ plttID
			.4byte 396 << 5, 39 << 2 @ .tiles[396], .subsprites[39]
		Metaprite_18:
			.byte 3, 11 @ subspriteCount, unk_01
			.2byte 23 @ plttID
			.4byte 432 << 5, 43 << 2 @ .tiles[432], .subsprites[43]
		Metaprite_19:
			.byte 4, 18 @ subspriteCount, unk_01
			.2byte 23 @ plttID
			.4byte 443 << 5, 46 << 2 @ .tiles[443], .subsprites[46]
		Metaprite_20:
			.byte 2, 10 @ subspriteCount, unk_01
			.2byte 23 @ plttID
			.4byte 461 << 5, 50 << 2 @ .tiles[461], .subsprites[50]
		Metaprite_21:
			.byte 2, 12 @ subspriteCount, unk_01
			.2byte 23 @ plttID
			.4byte 471 << 5, 52 << 2 @ .tiles[471], .subsprites[52]
		Metaprite_22:
			.byte 3, 13 @ subspriteCount, unk_01
			.2byte 23 @ plttID
			.4byte 483 << 5, 54 << 2 @ .tiles[483], .subsprites[54]
		Metaprite_23:
			.byte 4, 15 @ subspriteCount, unk_01
			.2byte 23 @ plttID
			.4byte 496 << 5, 57 << 2 @ .tiles[496], .subsprites[57]
		Metaprite_24:
			.byte 4, 15 @ subspriteCount, unk_01
			.2byte 23 @ plttID
			.4byte 511 << 5, 61 << 2 @ .tiles[511], .subsprites[61]
		Metaprite_25:
			.byte 3, 14 @ subspriteCount, unk_01
			.2byte 23 @ plttID
			.4byte 526 << 5, 65 << 2 @ .tiles[526], .subsprites[65]
		Metaprite_26:
			.byte 2, 12 @ subspriteCount, unk_01
			.2byte 23 @ plttID
			.4byte 540 << 5, 68 << 2 @ .tiles[540], .subsprites[68]
		Metaprite_27:
			.byte 2, 10 @ subspriteCount, unk_01
			.2byte 23 @ plttID
			.4byte 552 << 5, 70 << 2 @ .tiles[552], .subsprites[70]
		Metaprite_28:
			.byte 4, 15 @ subspriteCount, unk_01
			.2byte 23 @ plttID
			.4byte 562 << 5, 72 << 2 @ .tiles[562], .subsprites[72]
		Metaprite_29:
			.byte 4, 18 @ subspriteCount, unk_01
			.2byte 23 @ plttID
			.4byte 577 << 5, 76 << 2 @ .tiles[577], .subsprites[76]
		Metaprite_30:
			.byte 2, 12 @ subspriteCount, unk_01
			.2byte 23 @ plttID
			.4byte 595 << 5, 80 << 2 @ .tiles[595], .subsprites[80]
		Metaprite_31:
			.byte 2, 10 @ subspriteCount, unk_01
			.2byte 23 @ plttID
			.4byte 607 << 5, 82 << 2 @ .tiles[607], .subsprites[82]
		Metaprite_32:
			.byte 2, 10 @ subspriteCount, unk_01
			.2byte 23 @ plttID
			.4byte 617 << 5, 84 << 2 @ .tiles[617], .subsprites[84]
		Metaprite_33:
			.byte 2, 12 @ subspriteCount, unk_01
			.2byte 23 @ plttID
			.4byte 627 << 5, 86 << 2 @ .tiles[627], .subsprites[86]
		Metaprite_34:
			.byte 3, 14 @ subspriteCount, unk_01
			.2byte 23 @ plttID
			.4byte 639 << 5, 88 << 2 @ .tiles[639], .subsprites[88]
		Metaprite_35:
			.byte 4, 15 @ subspriteCount, unk_01
			.2byte 23 @ plttID
			.4byte 653 << 5, 91 << 2 @ .tiles[653], .subsprites[91]
		Metaprite_36:
			.byte 3, 11 @ subspriteCount, unk_01
			.2byte 23 @ plttID
			.4byte 668 << 5, 95 << 2 @ .tiles[668], .subsprites[95]
		Metaprite_37:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 23 @ plttID
			.4byte 679 << 5, 98 << 2 @ .tiles[679], .subsprites[98]
		Metaprite_38:
			.byte 3, 11 @ subspriteCount, unk_01
			.2byte 23 @ plttID
			.4byte 703 << 5, 100 << 2 @ .tiles[703], .subsprites[100]
		Metaprite_39:
			.byte 3, 10 @ subspriteCount, unk_01
			.2byte 23 @ plttID
			.4byte 714 << 5, 103 << 2 @ .tiles[714], .subsprites[103]
		Metaprite_40:
			.byte 4, 18 @ subspriteCount, unk_01
			.2byte 23 @ plttID
			.4byte 724 << 5, 106 << 2 @ .tiles[724], .subsprites[106]
		Metaprite_41:
			.byte 4, 18 @ subspriteCount, unk_01
			.2byte 23 @ plttID
			.4byte 742 << 5, 110 << 2 @ .tiles[742], .subsprites[110]
		Metaprite_42:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 23 @ plttID
			.4byte 760 << 5, 114 << 2 @ .tiles[760], .subsprites[114]
		Metaprite_43:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 23 @ plttID
			.4byte 784 << 5, 116 << 2 @ .tiles[784], .subsprites[116]
		Metaprite_44:
			.byte 3, 14 @ subspriteCount, unk_01
			.2byte 23 @ plttID
			.4byte 808 << 5, 118 << 2 @ .tiles[808], .subsprites[118]
		Metaprite_45:
			.byte 4, 18 @ subspriteCount, unk_01
			.2byte 23 @ plttID
			.4byte 822 << 5, 121 << 2 @ .tiles[822], .subsprites[121]
		Metaprite_46:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 23 @ plttID
			.4byte 840 << 5, 125 << 2 @ .tiles[840], .subsprites[125]
		Metaprite_47:
			.byte 2, 10 @ subspriteCount, unk_01
			.2byte 23 @ plttID
			.4byte 852 << 5, 128 << 2 @ .tiles[852], .subsprites[128]
		Metaprite_48:
			.byte 3, 14 @ subspriteCount, unk_01
			.2byte 23 @ plttID
			.4byte 862 << 5, 130 << 2 @ .tiles[862], .subsprites[130]
		Metaprite_49:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 23 @ plttID
			.4byte 876 << 5, 133 << 2 @ .tiles[876], .subsprites[133]
		Metaprite_50:
			.byte 3, 16 @ subspriteCount, unk_01
			.2byte 23 @ plttID
			.4byte 900 << 5, 135 << 2 @ .tiles[900], .subsprites[135]
		Metaprite_51:
			.byte 3, 16 @ subspriteCount, unk_01
			.2byte 23 @ plttID
			.4byte 916 << 5, 138 << 2 @ .tiles[916], .subsprites[138]
		Metaprite_52:
			.byte 4, 15 @ subspriteCount, unk_01
			.2byte 23 @ plttID
			.4byte 932 << 5, 141 << 2 @ .tiles[932], .subsprites[141]
		Metaprite_53:
			.byte 3, 11 @ subspriteCount, unk_01
			.2byte 23 @ plttID
			.4byte 947 << 5, 145 << 2 @ .tiles[947], .subsprites[145]
		Metaprite_54:
			.byte 3, 11 @ subspriteCount, unk_01
			.2byte 23 @ plttID
			.4byte 958 << 5, 148 << 2 @ .tiles[958], .subsprites[148]
		Metaprite_55:
			.byte 3, 14 @ subspriteCount, unk_01
			.2byte 23 @ plttID
			.4byte 969 << 5, 151 << 2 @ .tiles[969], .subsprites[151]
		Metaprite_56:
			.byte 3, 14 @ subspriteCount, unk_01
			.2byte 23 @ plttID
			.4byte 983 << 5, 154 << 2 @ .tiles[983], .subsprites[154]
		Metaprite_57:
			.byte 3, 28 @ subspriteCount, unk_01
			.2byte 23 @ plttID
			.4byte 997 << 5, 157 << 2 @ .tiles[997], .subsprites[157]
		Metaprite_58:
			.byte 3, 24 @ subspriteCount, unk_01
			.2byte 23 @ plttID
			.4byte 1025 << 5, 160 << 2 @ .tiles[1025], .subsprites[160]
		Metaprite_59:
			.byte 2, 12 @ subspriteCount, unk_01
			.2byte 23 @ plttID
			.4byte 1049 << 5, 163 << 2 @ .tiles[1049], .subsprites[163]
		Metaprite_60:
			.byte 4, 18 @ subspriteCount, unk_01
			.2byte 23 @ plttID
			.4byte 1061 << 5, 165 << 2 @ .tiles[1061], .subsprites[165]
		Metaprite_61:
			.byte 3, 28 @ subspriteCount, unk_01
			.2byte 23 @ plttID
			.4byte 1079 << 5, 169 << 2 @ .tiles[1079], .subsprites[169]
		Metaprite_62:
			.byte 3, 28 @ subspriteCount, unk_01
			.2byte 23 @ plttID
			.4byte 1107 << 5, 172 << 2 @ .tiles[1107], .subsprites[172]
		Metaprite_63:
			.byte 4, 36 @ subspriteCount, unk_01
			.2byte 28 @ plttID
			.4byte 1135 << 5, 175 << 2 @ .tiles[1135], .subsprites[175]
		Metaprite_64:
			.byte 3, 24 @ subspriteCount, unk_01
			.2byte 28 @ plttID
			.4byte 1171 << 5, 179 << 2 @ .tiles[1171], .subsprites[179]
		Metaprite_65:
			.byte 3, 24 @ subspriteCount, unk_01
			.2byte 28 @ plttID
			.4byte 1195 << 5, 182 << 2 @ .tiles[1195], .subsprites[182]
		Metaprite_66:
			.byte 3, 8 @ subspriteCount, unk_01
			.2byte 28 @ plttID
			.4byte 1219 << 5, 185 << 2 @ .tiles[1219], .subsprites[185]
		Metaprite_67:
			.byte 3, 8 @ subspriteCount, unk_01
			.2byte 29 @ plttID
			.4byte 1227 << 5, 188 << 2 @ .tiles[1227], .subsprites[188]
		Metaprite_68:
			.byte 2, 6 @ subspriteCount, unk_01
			.2byte 29 @ plttID
			.4byte 1235 << 5, 191 << 2 @ .tiles[1235], .subsprites[191]
		Metaprite_69:
			.byte 3, 8 @ subspriteCount, unk_01
			.2byte 29 @ plttID
			.4byte 1241 << 5, 193 << 2 @ .tiles[1241], .subsprites[193]
		Metaprite_70:
			.byte 3, 6 @ subspriteCount, unk_01
			.2byte 29 @ plttID
			.4byte 1249 << 5, 196 << 2 @ .tiles[1249], .subsprites[196]
		Metaprite_71:
			.byte 3, 8 @ subspriteCount, unk_01
			.2byte 29 @ plttID
			.4byte 1255 << 5, 199 << 2 @ .tiles[1255], .subsprites[199]
		Metaprite_72:
			.byte 2, 6 @ subspriteCount, unk_01
			.2byte 29 @ plttID
			.4byte 1263 << 5, 202 << 2 @ .tiles[1263], .subsprites[202]
		Metaprite_73:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 29 @ plttID
			.4byte 1269 << 5, 204 << 2 @ .tiles[1269], .subsprites[204]
		Metaprite_74:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 29 @ plttID
			.4byte 1273 << 5, 205 << 2 @ .tiles[1273], .subsprites[205]
		Metaprite_75:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 29 @ plttID
			.4byte 1277 << 5, 206 << 2 @ .tiles[1277], .subsprites[206]
		Metaprite_76:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 29 @ plttID
			.4byte 1281 << 5, 207 << 2 @ .tiles[1281], .subsprites[207]
		Metaprite_77:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 29 @ plttID
			.4byte 1285 << 5, 208 << 2 @ .tiles[1285], .subsprites[208]
		Metaprite_78:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 29 @ plttID
			.4byte 1289 << 5, 209 << 2 @ .tiles[1289], .subsprites[209]
		Metaprite_79:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 29 @ plttID
			.4byte 1293 << 5, 210 << 2 @ .tiles[1293], .subsprites[210]
		Metaprite_80:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 29 @ plttID
			.4byte 1309 << 5, 211 << 2 @ .tiles[1309], .subsprites[211]
		Metaprite_81:
			.byte 4, 30 @ subspriteCount, unk_01
			.2byte 29 @ plttID
			.4byte 1325 << 5, 212 << 2 @ .tiles[1325], .subsprites[212]
		Metaprite_82:
			.byte 1, 32 @ subspriteCount, unk_01
			.2byte 42 @ plttID
			.4byte 1355 << 5, 216 << 2 @ .tiles[1355], .subsprites[216]
		Metaprite_83:
			.byte 3, 40 @ subspriteCount, unk_01
			.2byte 42 @ plttID
			.4byte 1387 << 5, 217 << 2 @ .tiles[1387], .subsprites[217]
		Metaprite_84:
			.byte 1, 32 @ subspriteCount, unk_01
			.2byte 42 @ plttID
			.4byte 1427 << 5, 220 << 2 @ .tiles[1427], .subsprites[220]
		Metaprite_85:
			.byte 1, 32 @ subspriteCount, unk_01
			.2byte 42 @ plttID
			.4byte 1459 << 5, 221 << 2 @ .tiles[1459], .subsprites[221]
		Metaprite_86:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 42 @ plttID
			.4byte 1491 << 5, 222 << 2 @ .tiles[1491], .subsprites[222]
		Metaprite_87:
			.byte 4, 18 @ subspriteCount, unk_01
			.2byte 42 @ plttID
			.4byte 1511 << 5, 224 << 2 @ .tiles[1511], .subsprites[224]
		Metaprite_88:
			.byte 1, 32 @ subspriteCount, unk_01
			.2byte 42 @ plttID
			.4byte 1529 << 5, 228 << 2 @ .tiles[1529], .subsprites[228]
		Metaprite_89:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 42 @ plttID
			.4byte 1561 << 5, 229 << 2 @ .tiles[1561], .subsprites[229]
		Metaprite_90:
			.byte 4, 18 @ subspriteCount, unk_01
			.2byte 42 @ plttID
			.4byte 1581 << 5, 231 << 2 @ .tiles[1581], .subsprites[231]
		Metaprite_91:
			.byte 1, 32 @ subspriteCount, unk_01
			.2byte 42 @ plttID
			.4byte 1599 << 5, 235 << 2 @ .tiles[1599], .subsprites[235]
		Metaprite_92:
			.byte 3, 40 @ subspriteCount, unk_01
			.2byte 42 @ plttID
			.4byte 1631 << 5, 236 << 2 @ .tiles[1631], .subsprites[236]
		Metaprite_93:
			.byte 1, 32 @ subspriteCount, unk_01
			.2byte 42 @ plttID
			.4byte 1671 << 5, 239 << 2 @ .tiles[1671], .subsprites[239]
		Metaprite_94:
			.byte 1, 32 @ subspriteCount, unk_01
			.2byte 42 @ plttID
			.4byte 1703 << 5, 240 << 2 @ .tiles[1703], .subsprites[240]
		Metaprite_95:
			.byte 3, 40 @ subspriteCount, unk_01
			.2byte 42 @ plttID
			.4byte 1735 << 5, 241 << 2 @ .tiles[1735], .subsprites[241]
		Metaprite_96:
			.byte 1, 32 @ subspriteCount, unk_01
			.2byte 42 @ plttID
			.4byte 1775 << 5, 244 << 2 @ .tiles[1775], .subsprites[244]
		Metaprite_97:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 44 @ plttID
			.4byte 1807 << 5, 245 << 2 @ .tiles[1807], .subsprites[245]
		Metaprite_98:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 44 @ plttID
			.4byte 1808 << 5, 246 << 2 @ .tiles[1808], .subsprites[246]
		Metaprite_99:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 44 @ plttID
			.4byte 1809 << 5, 247 << 2 @ .tiles[1809], .subsprites[247]
		Metaprite_100:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 44 @ plttID
			.4byte 1810 << 5, 248 << 2 @ .tiles[1810], .subsprites[248]
		Metaprite_101:
			.byte 2, 36 @ subspriteCount, unk_01
			.2byte 51 @ plttID
			.4byte 1811 << 5, 249 << 2 @ .tiles[1811], .subsprites[249]
		Metaprite_102:
			.byte 3, 40 @ subspriteCount, unk_01
			.2byte 52 @ plttID
			.4byte 1847 << 5, 251 << 2 @ .tiles[1847], .subsprites[251]
		Metaprite_103:
			.byte 4, 36 @ subspriteCount, unk_01
			.2byte 53 @ plttID
			.4byte 1887 << 5, 254 << 2 @ .tiles[1887], .subsprites[254]
		Metaprite_104:
			.byte 3, 8 @ subspriteCount, unk_01
			.2byte 54 @ plttID
			.4byte 1923 << 5, 258 << 2 @ .tiles[1923], .subsprites[258]
		Metaprite_105:
			.byte 3, 8 @ subspriteCount, unk_01
			.2byte 54 @ plttID
			.4byte 1931 << 5, 261 << 2 @ .tiles[1931], .subsprites[261]
		Metaprite_106:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 56 @ plttID
			.4byte 1939 << 5, 264 << 2 @ .tiles[1939], .subsprites[264]
		Metaprite_107:
			.byte 1, 64 @ subspriteCount, unk_01
			.2byte 60 @ plttID
			.4byte 1955 << 5, 265 << 2 @ .tiles[1955], .subsprites[265]
		Metaprite_108:
			.byte 1, 64 @ subspriteCount, unk_01
			.2byte 61 @ plttID
			.4byte 2019 << 5, 266 << 2 @ .tiles[2019], .subsprites[266]
		Metaprite_109:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 62 @ plttID
			.4byte 2083 << 5, 267 << 2 @ .tiles[2083], .subsprites[267]
		Metaprite_110:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 62 @ plttID
			.4byte 2087 << 5, 268 << 2 @ .tiles[2087], .subsprites[268]
		Metaprite_111:
			.byte 2, 6 @ subspriteCount, unk_01
			.2byte 62 @ plttID
			.4byte 2091 << 5, 269 << 2 @ .tiles[2091], .subsprites[269]
		Metaprite_112:
			.byte 3, 8 @ subspriteCount, unk_01
			.2byte 62 @ plttID
			.4byte 2097 << 5, 271 << 2 @ .tiles[2097], .subsprites[271]
		Metaprite_113:
			.byte 3, 8 @ subspriteCount, unk_01
			.2byte 62 @ plttID
			.4byte 2105 << 5, 274 << 2 @ .tiles[2105], .subsprites[274]
		Metaprite_114:
			.byte 3, 8 @ subspriteCount, unk_01
			.2byte 62 @ plttID
			.4byte 2113 << 5, 277 << 2 @ .tiles[2113], .subsprites[277]
		Metaprite_115:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 62 @ plttID
			.4byte 2121 << 5, 280 << 2 @ .tiles[2121], .subsprites[280]
		Metaprite_116:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 62 @ plttID
			.4byte 2133 << 5, 283 << 2 @ .tiles[2133], .subsprites[283]
		Metaprite_117:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 62 @ plttID
			.4byte 2145 << 5, 286 << 2 @ .tiles[2145], .subsprites[286]
		Metaprite_118:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 62 @ plttID
			.4byte 2157 << 5, 289 << 2 @ .tiles[2157], .subsprites[289]
		Metaprite_119:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 62 @ plttID
			.4byte 2173 << 5, 290 << 2 @ .tiles[2173], .subsprites[290]
		Metaprite_120:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 62 @ plttID
			.4byte 2189 << 5, 291 << 2 @ .tiles[2189], .subsprites[291]
		Metaprite_121:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 62 @ plttID
			.4byte 2205 << 5, 292 << 2 @ .tiles[2205], .subsprites[292]
		Metaprite_122:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 62 @ plttID
			.4byte 2221 << 5, 293 << 2 @ .tiles[2221], .subsprites[293]
		Metaprite_123:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 62 @ plttID
			.4byte 2237 << 5, 294 << 2 @ .tiles[2237], .subsprites[294]
		Metaprite_124:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 62 @ plttID
			.4byte 2253 << 5, 295 << 2 @ .tiles[2253], .subsprites[295]
		Metaprite_125:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 62 @ plttID
			.4byte 2269 << 5, 296 << 2 @ .tiles[2269], .subsprites[296]
		Metaprite_126:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 62 @ plttID
			.4byte 2285 << 5, 297 << 2 @ .tiles[2285], .subsprites[297]
		Metaprite_127:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 64 @ plttID
			.4byte 2301 << 5, 298 << 2 @ .tiles[2301], .subsprites[298]
		Metaprite_128:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 64 @ plttID
			.4byte 2349 << 5, 301 << 2 @ .tiles[2349], .subsprites[301]
		Metaprite_129:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 64 @ plttID
			.4byte 2397 << 5, 304 << 2 @ .tiles[2397], .subsprites[304]
		Metaprite_130:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 64 @ plttID
			.4byte 2445 << 5, 307 << 2 @ .tiles[2445], .subsprites[307]
		Metaprite_131:
			.byte 3, 28 @ subspriteCount, unk_01
			.2byte 66 @ plttID
			.4byte 2493 << 5, 310 << 2 @ .tiles[2493], .subsprites[310]
		Metaprite_132:
			.byte 3, 28 @ subspriteCount, unk_01
			.2byte 66 @ plttID
			.4byte 2521 << 5, 313 << 2 @ .tiles[2521], .subsprites[313]
		Metaprite_133:
			.byte 3, 28 @ subspriteCount, unk_01
			.2byte 66 @ plttID
			.4byte 2549 << 5, 316 << 2 @ .tiles[2549], .subsprites[316]
		Metaprite_134:
			.byte 3, 28 @ subspriteCount, unk_01
			.2byte 66 @ plttID
			.4byte 2577 << 5, 319 << 2 @ .tiles[2577], .subsprites[319]
		Metaprite_135:
			.byte 3, 28 @ subspriteCount, unk_01
			.2byte 66 @ plttID
			.4byte 2605 << 5, 322 << 2 @ .tiles[2605], .subsprites[322]
		Metaprite_136:
			.byte 3, 28 @ subspriteCount, unk_01
			.2byte 66 @ plttID
			.4byte 2633 << 5, 325 << 2 @ .tiles[2633], .subsprites[325]
		Metaprite_137:
			.byte 3, 28 @ subspriteCount, unk_01
			.2byte 66 @ plttID
			.4byte 2661 << 5, 328 << 2 @ .tiles[2661], .subsprites[328]
		Metaprite_138:
			.byte 3, 28 @ subspriteCount, unk_01
			.2byte 66 @ plttID
			.4byte 2689 << 5, 331 << 2 @ .tiles[2689], .subsprites[331]
		Metaprite_139:
			.byte 3, 28 @ subspriteCount, unk_01
			.2byte 66 @ plttID
			.4byte 2717 << 5, 334 << 2 @ .tiles[2717], .subsprites[334]
		Metaprite_140:
			.byte 4, 36 @ subspriteCount, unk_01
			.2byte 66 @ plttID
			.4byte 2745 << 5, 337 << 2 @ .tiles[2745], .subsprites[337]
		Metaprite_141:
			.byte 4, 36 @ subspriteCount, unk_01
			.2byte 66 @ plttID
			.4byte 2781 << 5, 341 << 2 @ .tiles[2781], .subsprites[341]
		Metaprite_142:
			.byte 1, 32 @ subspriteCount, unk_01
			.2byte 66 @ plttID
			.4byte 2817 << 5, 345 << 2 @ .tiles[2817], .subsprites[345]
		Metaprite_143:
			.byte 3, 7 @ subspriteCount, unk_01
			.2byte 71 @ plttID
			.4byte 2849 << 5, 346 << 2 @ .tiles[2849], .subsprites[346]
		Metaprite_144:
			.byte 3, 7 @ subspriteCount, unk_01
			.2byte 71 @ plttID
			.4byte 2856 << 5, 349 << 2 @ .tiles[2856], .subsprites[349]
		Metaprite_145:
			.byte 1, 8 @ subspriteCount, unk_01
			.2byte 71 @ plttID
			.4byte 2863 << 5, 352 << 2 @ .tiles[2863], .subsprites[352]
		Metaprite_146:
			.byte 3, 7 @ subspriteCount, unk_01
			.2byte 71 @ plttID
			.4byte 2871 << 5, 353 << 2 @ .tiles[2871], .subsprites[353]
		Metaprite_147:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 72 @ plttID
			.4byte 2878 << 5, 356 << 2 @ .tiles[2878], .subsprites[356]
		Metaprite_148:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 72 @ plttID
			.4byte 2894 << 5, 357 << 2 @ .tiles[2894], .subsprites[357]
		Metaprite_149:
			.byte 3, 4 @ subspriteCount, unk_01
			.2byte 72 @ plttID
			.4byte 2910 << 5, 358 << 2 @ .tiles[2910], .subsprites[358]
		Metaprite_150:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 72 @ plttID
			.4byte 2914 << 5, 361 << 2 @ .tiles[2914], .subsprites[361]
		Metaprite_151:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 72 @ plttID
			.4byte 2930 << 5, 362 << 2 @ .tiles[2930], .subsprites[362]
		Metaprite_152:
			.byte 3, 4 @ subspriteCount, unk_01
			.2byte 72 @ plttID
			.4byte 2946 << 5, 363 << 2 @ .tiles[2946], .subsprites[363]
		Metaprite_153:
			.byte 3, 7 @ subspriteCount, unk_01
			.2byte 72 @ plttID
			.4byte 2950 << 5, 366 << 2 @ .tiles[2950], .subsprites[366]
		Metaprite_154:
			.byte 2, 10 @ subspriteCount, unk_01
			.2byte 72 @ plttID
			.4byte 2957 << 5, 369 << 2 @ .tiles[2957], .subsprites[369]
		Metaprite_155:
			.byte 2, 5 @ subspriteCount, unk_01
			.2byte 72 @ plttID
			.4byte 2967 << 5, 371 << 2 @ .tiles[2967], .subsprites[371]
		Metaprite_156:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 72 @ plttID
			.4byte 2972 << 5, 373 << 2 @ .tiles[2972], .subsprites[373]
		Metaprite_157:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 72 @ plttID
			.4byte 2988 << 5, 374 << 2 @ .tiles[2988], .subsprites[374]
		Metaprite_158:
			.byte 3, 4 @ subspriteCount, unk_01
			.2byte 72 @ plttID
			.4byte 3004 << 5, 375 << 2 @ .tiles[3004], .subsprites[375]
		Metaprite_159:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 72 @ plttID
			.4byte 3008 << 5, 378 << 2 @ .tiles[3008], .subsprites[378]
		Metaprite_160:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 72 @ plttID
			.4byte 3024 << 5, 379 << 2 @ .tiles[3024], .subsprites[379]
		Metaprite_161:
			.byte 3, 14 @ subspriteCount, unk_01
			.2byte 72 @ plttID
			.4byte 3044 << 5, 381 << 2 @ .tiles[3044], .subsprites[381]
		Metaprite_162:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 72 @ plttID
			.4byte 3058 << 5, 384 << 2 @ .tiles[3058], .subsprites[384]
		Metaprite_163:
			.byte 3, 6 @ subspriteCount, unk_01
			.2byte 72 @ plttID
			.4byte 3062 << 5, 385 << 2 @ .tiles[3062], .subsprites[385]
		Metaprite_164:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 72 @ plttID
			.4byte 3068 << 5, 388 << 2 @ .tiles[3068], .subsprites[388]
		Metaprite_165:
			.byte 3, 6 @ subspriteCount, unk_01
			.2byte 72 @ plttID
			.4byte 3072 << 5, 389 << 2 @ .tiles[3072], .subsprites[389]
		Metaprite_166:
			.byte 2, 6 @ subspriteCount, unk_01
			.2byte 72 @ plttID
			.4byte 3078 << 5, 392 << 2 @ .tiles[3078], .subsprites[392]
		Metaprite_167:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 72 @ plttID
			.4byte 3084 << 5, 394 << 2 @ .tiles[3084], .subsprites[394]
		Metaprite_168:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 72 @ plttID
			.4byte 3085 << 5, 395 << 2 @ .tiles[3085], .subsprites[395]
		Metaprite_169:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 72 @ plttID
			.4byte 3086 << 5, 396 << 2 @ .tiles[3086], .subsprites[396]
		Metaprite_170:
			.byte 1, 2 @ subspriteCount, unk_01
			.2byte 72 @ plttID
			.4byte 3090 << 5, 397 << 2 @ .tiles[3090], .subsprites[397]
		Metaprite_171:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 72 @ plttID
			.4byte 3092 << 5, 398 << 2 @ .tiles[3092], .subsprites[398]
		Metaprite_172:
			.byte 1, 2 @ subspriteCount, unk_01
			.2byte 72 @ plttID
			.4byte 3096 << 5, 399 << 2 @ .tiles[3096], .subsprites[399]
		Metaprite_173:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 72 @ plttID
			.4byte 3098 << 5, 400 << 2 @ .tiles[3098], .subsprites[400]
		Metaprite_174:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 72 @ plttID
			.4byte 3102 << 5, 401 << 2 @ .tiles[3102], .subsprites[401]
		Metaprite_175:
			.byte 1, 2 @ subspriteCount, unk_01
			.2byte 72 @ plttID
			.4byte 3106 << 5, 402 << 2 @ .tiles[3106], .subsprites[402]
		Metaprite_176:
			.byte 1, 2 @ subspriteCount, unk_01
			.2byte 72 @ plttID
			.4byte 3108 << 5, 403 << 2 @ .tiles[3108], .subsprites[403]
		Metaprite_177:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 72 @ plttID
			.4byte 3110 << 5, 404 << 2 @ .tiles[3110], .subsprites[404]
		Metaprite_178:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 72 @ plttID
			.4byte 3126 << 5, 405 << 2 @ .tiles[3126], .subsprites[405]
		Metaprite_179:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 72 @ plttID
			.4byte 3142 << 5, 406 << 2 @ .tiles[3142], .subsprites[406]
		Metaprite_180:
			.byte 1, 8 @ subspriteCount, unk_01
			.2byte 73 @ plttID
			.4byte 3158 << 5, 407 << 2 @ .tiles[3158], .subsprites[407]
		Metaprite_181:
			.byte 1, 8 @ subspriteCount, unk_01
			.2byte 73 @ plttID
			.4byte 3166 << 5, 408 << 2 @ .tiles[3166], .subsprites[408]
		Metaprite_182:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 79 @ plttID
			.4byte 3174 << 5, 409 << 2 @ .tiles[3174], .subsprites[409]
		Metaprite_183:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 80 @ plttID
			.4byte 3222 << 5, 412 << 2 @ .tiles[3222], .subsprites[412]
		Metaprite_184:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 80 @ plttID
			.4byte 3270 << 5, 415 << 2 @ .tiles[3270], .subsprites[415]
		Metaprite_185:
			.byte 4, 36 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 3318 << 5, 418 << 2 @ .tiles[3318], .subsprites[418]
		Metaprite_186:
			.byte 4, 36 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 3354 << 5, 422 << 2 @ .tiles[3354], .subsprites[422]
		Metaprite_187:
			.byte 3, 26 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 3390 << 5, 426 << 2 @ .tiles[3390], .subsprites[426]
		Metaprite_188:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 86 @ plttID
			.4byte 3416 << 5, 429 << 2 @ .tiles[3416], .subsprites[429]
		Metaprite_189:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 86 @ plttID
			.4byte 3420 << 5, 430 << 2 @ .tiles[3420], .subsprites[430]
		Metaprite_190:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 86 @ plttID
			.4byte 3424 << 5, 431 << 2 @ .tiles[3424], .subsprites[431]
		Metaprite_191:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 86 @ plttID
			.4byte 3428 << 5, 432 << 2 @ .tiles[3428], .subsprites[432]
		Metaprite_192:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 86 @ plttID
			.4byte 3432 << 5, 433 << 2 @ .tiles[3432], .subsprites[433]
		Metaprite_193:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 86 @ plttID
			.4byte 3436 << 5, 434 << 2 @ .tiles[3436], .subsprites[434]
		Metaprite_194:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 86 @ plttID
			.4byte 3440 << 5, 435 << 2 @ .tiles[3440], .subsprites[435]
		Metaprite_195:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 86 @ plttID
			.4byte 3444 << 5, 436 << 2 @ .tiles[3444], .subsprites[436]
		Metaprite_196:
			.byte 2, 12 @ subspriteCount, unk_01
			.2byte 87 @ plttID
			.4byte 3448 << 5, 437 << 2 @ .tiles[3448], .subsprites[437]
		Metaprite_197:
			.byte 2, 12 @ subspriteCount, unk_01
			.2byte 87 @ plttID
			.4byte 3460 << 5, 439 << 2 @ .tiles[3460], .subsprites[439]
		Metaprite_198:
			.byte 2, 12 @ subspriteCount, unk_01
			.2byte 87 @ plttID
			.4byte 3472 << 5, 441 << 2 @ .tiles[3472], .subsprites[441]
		Metaprite_199:
			.byte 2, 12 @ subspriteCount, unk_01
			.2byte 87 @ plttID
			.4byte 3484 << 5, 443 << 2 @ .tiles[3484], .subsprites[443]
		Metaprite_200:
			.byte 2, 12 @ subspriteCount, unk_01
			.2byte 87 @ plttID
			.4byte 3496 << 5, 445 << 2 @ .tiles[3496], .subsprites[445]
		Metaprite_201:
			.byte 2, 12 @ subspriteCount, unk_01
			.2byte 87 @ plttID
			.4byte 3508 << 5, 447 << 2 @ .tiles[3508], .subsprites[447]
		Metaprite_202:
			.byte 2, 12 @ subspriteCount, unk_01
			.2byte 87 @ plttID
			.4byte 3520 << 5, 449 << 2 @ .tiles[3520], .subsprites[449]
		Metaprite_203:
			.byte 2, 12 @ subspriteCount, unk_01
			.2byte 87 @ plttID
			.4byte 3532 << 5, 451 << 2 @ .tiles[3532], .subsprites[451]
		Metaprite_204:
			.byte 2, 12 @ subspriteCount, unk_01
			.2byte 87 @ plttID
			.4byte 3544 << 5, 453 << 2 @ .tiles[3544], .subsprites[453]
		Metaprite_205:
			.byte 2, 12 @ subspriteCount, unk_01
			.2byte 87 @ plttID
			.4byte 3556 << 5, 455 << 2 @ .tiles[3556], .subsprites[455]
		Metaprite_206:
			.byte 2, 12 @ subspriteCount, unk_01
			.2byte 87 @ plttID
			.4byte 3568 << 5, 457 << 2 @ .tiles[3568], .subsprites[457]
		Metaprite_207:
			.byte 2, 12 @ subspriteCount, unk_01
			.2byte 87 @ plttID
			.4byte 3580 << 5, 459 << 2 @ .tiles[3580], .subsprites[459]
		Metaprite_208:
			.byte 2, 12 @ subspriteCount, unk_01
			.2byte 87 @ plttID
			.4byte 3592 << 5, 461 << 2 @ .tiles[3592], .subsprites[461]
		Metaprite_209:
			.byte 2, 12 @ subspriteCount, unk_01
			.2byte 87 @ plttID
			.4byte 3604 << 5, 463 << 2 @ .tiles[3604], .subsprites[463]
		Metaprite_210:
			.byte 2, 12 @ subspriteCount, unk_01
			.2byte 87 @ plttID
			.4byte 3616 << 5, 465 << 2 @ .tiles[3616], .subsprites[465]
		Metaprite_211:
			.byte 2, 12 @ subspriteCount, unk_01
			.2byte 87 @ plttID
			.4byte 3628 << 5, 467 << 2 @ .tiles[3628], .subsprites[467]
		Metaprite_212:
			.byte 1, 8 @ subspriteCount, unk_01
			.2byte 89 @ plttID
			.4byte 3640 << 5, 469 << 2 @ .tiles[3640], .subsprites[469]
		Metaprite_213:
			.byte 1, 8 @ subspriteCount, unk_01
			.2byte 89 @ plttID
			.4byte 3648 << 5, 470 << 2 @ .tiles[3648], .subsprites[470]
		Metaprite_214:
			.byte 1, 8 @ subspriteCount, unk_01
			.2byte 89 @ plttID
			.4byte 3656 << 5, 471 << 2 @ .tiles[3656], .subsprites[471]
		Metaprite_215:
			.byte 1, 8 @ subspriteCount, unk_01
			.2byte 89 @ plttID
			.4byte 3664 << 5, 472 << 2 @ .tiles[3664], .subsprites[472]
		Metaprite_216:
			.byte 1, 8 @ subspriteCount, unk_01
			.2byte 89 @ plttID
			.4byte 3672 << 5, 473 << 2 @ .tiles[3672], .subsprites[473]
		Metaprite_217:
			.byte 1, 8 @ subspriteCount, unk_01
			.2byte 89 @ plttID
			.4byte 3680 << 5, 474 << 2 @ .tiles[3680], .subsprites[474]
		Metaprite_218:
			.byte 1, 8 @ subspriteCount, unk_01
			.2byte 89 @ plttID
			.4byte 3688 << 5, 475 << 2 @ .tiles[3688], .subsprites[475]
		Metaprite_219:
			.byte 3, 7 @ subspriteCount, unk_01
			.2byte 89 @ plttID
			.4byte 3696 << 5, 476 << 2 @ .tiles[3696], .subsprites[476]
		Metaprite_220:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 91 @ plttID
			.4byte 3703 << 5, 479 << 2 @ .tiles[3703], .subsprites[479]
		Metaprite_221:
			.byte 3, 10 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 3719 << 5, 480 << 2 @ .tiles[3719], .subsprites[480]
		Metaprite_222:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 3729 << 5, 483 << 2 @ .tiles[3729], .subsprites[483]
		Metaprite_223:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 3745 << 5, 484 << 2 @ .tiles[3745], .subsprites[484]
		Metaprite_224:
			.byte 2, 12 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 3761 << 5, 485 << 2 @ .tiles[3761], .subsprites[485]
		Metaprite_225:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 3773 << 5, 487 << 2 @ .tiles[3773], .subsprites[487]
		Metaprite_226:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 3789 << 5, 488 << 2 @ .tiles[3789], .subsprites[488]
		Metaprite_227:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 3793 << 5, 489 << 2 @ .tiles[3793], .subsprites[489]
		Metaprite_228:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 3805 << 5, 492 << 2 @ .tiles[3805], .subsprites[492]
		Metaprite_229:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 3821 << 5, 493 << 2 @ .tiles[3821], .subsprites[493]
		Metaprite_230:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 3822 << 5, 494 << 2 @ .tiles[3822], .subsprites[494]
		Metaprite_231:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 3823 << 5, 495 << 2 @ .tiles[3823], .subsprites[495]
		Metaprite_232:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 3824 << 5, 496 << 2 @ .tiles[3824], .subsprites[496]
		Metaprite_233:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 3825 << 5, 497 << 2 @ .tiles[3825], .subsprites[497]
		Metaprite_234:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 3826 << 5, 498 << 2 @ .tiles[3826], .subsprites[498]
		Metaprite_235:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 3827 << 5, 499 << 2 @ .tiles[3827], .subsprites[499]
		Metaprite_236:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 3828 << 5, 500 << 2 @ .tiles[3828], .subsprites[500]
		Metaprite_237:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 3829 << 5, 501 << 2 @ .tiles[3829], .subsprites[501]
		Metaprite_238:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 3830 << 5, 502 << 2 @ .tiles[3830], .subsprites[502]
		Metaprite_239:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 3831 << 5, 503 << 2 @ .tiles[3831], .subsprites[503]
		Metaprite_240:
			.byte 4, 36 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 3832 << 5, 504 << 2 @ .tiles[3832], .subsprites[504]
		Metaprite_241:
			.byte 4, 36 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 3868 << 5, 508 << 2 @ .tiles[3868], .subsprites[508]
		Metaprite_242:
			.byte 4, 30 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 3904 << 5, 512 << 2 @ .tiles[3904], .subsprites[512]
		Metaprite_243:
			.byte 4, 36 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 3934 << 5, 516 << 2 @ .tiles[3934], .subsprites[516]
		Metaprite_244:
			.byte 4, 36 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 3970 << 5, 520 << 2 @ .tiles[3970], .subsprites[520]
		Metaprite_245:
			.byte 4, 36 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 4006 << 5, 524 << 2 @ .tiles[4006], .subsprites[524]
		Metaprite_246:
			.byte 4, 36 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 4042 << 5, 528 << 2 @ .tiles[4042], .subsprites[528]
		Metaprite_247:
			.byte 4, 36 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 4078 << 5, 532 << 2 @ .tiles[4078], .subsprites[532]
		Metaprite_248:
			.byte 4, 36 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 4114 << 5, 536 << 2 @ .tiles[4114], .subsprites[536]
		Metaprite_249:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 92 @ plttID
			.4byte 4150 << 5, 540 << 2 @ .tiles[4150], .subsprites[540]
		Metaprite_250:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 92 @ plttID
			.4byte 4154 << 5, 541 << 2 @ .tiles[4154], .subsprites[541]
		Metaprite_251:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 92 @ plttID
			.4byte 4158 << 5, 542 << 2 @ .tiles[4158], .subsprites[542]
		Metaprite_252:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 92 @ plttID
			.4byte 4162 << 5, 543 << 2 @ .tiles[4162], .subsprites[543]
		Metaprite_253:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 92 @ plttID
			.4byte 4166 << 5, 544 << 2 @ .tiles[4166], .subsprites[544]
		Metaprite_254:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 92 @ plttID
			.4byte 4170 << 5, 545 << 2 @ .tiles[4170], .subsprites[545]
		Metaprite_255:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 92 @ plttID
			.4byte 4174 << 5, 546 << 2 @ .tiles[4174], .subsprites[546]
		Metaprite_256:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 92 @ plttID
			.4byte 4178 << 5, 547 << 2 @ .tiles[4178], .subsprites[547]
		Metaprite_257:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 92 @ plttID
			.4byte 4182 << 5, 548 << 2 @ .tiles[4182], .subsprites[548]
		Metaprite_258:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 92 @ plttID
			.4byte 4186 << 5, 549 << 2 @ .tiles[4186], .subsprites[549]
		Metaprite_259:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 92 @ plttID
			.4byte 4190 << 5, 550 << 2 @ .tiles[4190], .subsprites[550]
		Metaprite_260:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 92 @ plttID
			.4byte 4194 << 5, 551 << 2 @ .tiles[4194], .subsprites[551]
		Metaprite_261:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 92 @ plttID
			.4byte 4198 << 5, 552 << 2 @ .tiles[4198], .subsprites[552]
		Metaprite_262:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 92 @ plttID
			.4byte 4202 << 5, 553 << 2 @ .tiles[4202], .subsprites[553]
		Metaprite_263:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 92 @ plttID
			.4byte 4206 << 5, 554 << 2 @ .tiles[4206], .subsprites[554]
		Metaprite_264:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 92 @ plttID
			.4byte 4210 << 5, 555 << 2 @ .tiles[4210], .subsprites[555]
		Metaprite_265:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 92 @ plttID
			.4byte 4214 << 5, 556 << 2 @ .tiles[4214], .subsprites[556]
		Metaprite_266:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 92 @ plttID
			.4byte 4218 << 5, 557 << 2 @ .tiles[4218], .subsprites[557]
		Metaprite_267:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 92 @ plttID
			.4byte 4222 << 5, 558 << 2 @ .tiles[4222], .subsprites[558]
		Metaprite_268:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 92 @ plttID
			.4byte 4226 << 5, 559 << 2 @ .tiles[4226], .subsprites[559]
		Metaprite_269:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 92 @ plttID
			.4byte 4230 << 5, 560 << 2 @ .tiles[4230], .subsprites[560]
		Metaprite_270:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 92 @ plttID
			.4byte 4234 << 5, 561 << 2 @ .tiles[4234], .subsprites[561]
		Metaprite_271:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 92 @ plttID
			.4byte 4238 << 5, 562 << 2 @ .tiles[4238], .subsprites[562]
		Metaprite_272:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 92 @ plttID
			.4byte 4242 << 5, 563 << 2 @ .tiles[4242], .subsprites[563]
		Metaprite_273:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 92 @ plttID
			.4byte 4246 << 5, 564 << 2 @ .tiles[4246], .subsprites[564]
		Metaprite_274:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 92 @ plttID
			.4byte 4250 << 5, 565 << 2 @ .tiles[4250], .subsprites[565]
		Metaprite_275:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 92 @ plttID
			.4byte 4254 << 5, 566 << 2 @ .tiles[4254], .subsprites[566]
		Metaprite_276:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 92 @ plttID
			.4byte 4258 << 5, 567 << 2 @ .tiles[4258], .subsprites[567]
		Metaprite_277:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 92 @ plttID
			.4byte 4262 << 5, 568 << 2 @ .tiles[4262], .subsprites[568]
		Metaprite_278:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 92 @ plttID
			.4byte 4266 << 5, 569 << 2 @ .tiles[4266], .subsprites[569]
		Metaprite_279:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 92 @ plttID
			.4byte 4270 << 5, 570 << 2 @ .tiles[4270], .subsprites[570]
		Metaprite_280:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 92 @ plttID
			.4byte 4274 << 5, 571 << 2 @ .tiles[4274], .subsprites[571]
		Metaprite_281:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 92 @ plttID
			.4byte 4278 << 5, 572 << 2 @ .tiles[4278], .subsprites[572]
		Metaprite_282:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 92 @ plttID
			.4byte 4282 << 5, 573 << 2 @ .tiles[4282], .subsprites[573]
		Metaprite_283:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 92 @ plttID
			.4byte 4286 << 5, 574 << 2 @ .tiles[4286], .subsprites[574]
		Metaprite_284:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 92 @ plttID
			.4byte 4290 << 5, 575 << 2 @ .tiles[4290], .subsprites[575]
		Metaprite_285:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 92 @ plttID
			.4byte 4294 << 5, 576 << 2 @ .tiles[4294], .subsprites[576]
		Metaprite_286:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 92 @ plttID
			.4byte 4298 << 5, 577 << 2 @ .tiles[4298], .subsprites[577]
		Metaprite_287:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 92 @ plttID
			.4byte 4302 << 5, 578 << 2 @ .tiles[4302], .subsprites[578]
		Metaprite_288:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 92 @ plttID
			.4byte 4306 << 5, 579 << 2 @ .tiles[4306], .subsprites[579]
		Metaprite_289:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 92 @ plttID
			.4byte 4310 << 5, 580 << 2 @ .tiles[4310], .subsprites[580]
		Metaprite_290:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 92 @ plttID
			.4byte 4314 << 5, 581 << 2 @ .tiles[4314], .subsprites[581]
		Metaprite_291:
			.byte 3, 8 @ subspriteCount, unk_01
			.2byte 95 @ plttID
			.4byte 4318 << 5, 582 << 2 @ .tiles[4318], .subsprites[582]
		Metaprite_292:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 95 @ plttID
			.4byte 4326 << 5, 585 << 2 @ .tiles[4326], .subsprites[585]
		Metaprite_293:
			.byte 4, 30 @ subspriteCount, unk_01
			.2byte 95 @ plttID
			.4byte 4346 << 5, 587 << 2 @ .tiles[4346], .subsprites[587]
		Metaprite_294:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 97 @ plttID
			.4byte 4376 << 5, 591 << 2 @ .tiles[4376], .subsprites[591]
		Metaprite_295:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 97 @ plttID
			.4byte 4392 << 5, 592 << 2 @ .tiles[4392], .subsprites[592]
		Metaprite_296:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 97 @ plttID
			.4byte 4408 << 5, 593 << 2 @ .tiles[4408], .subsprites[593]
		Metaprite_297:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 97 @ plttID
			.4byte 4424 << 5, 594 << 2 @ .tiles[4424], .subsprites[594]
		Metaprite_298:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 97 @ plttID
			.4byte 4440 << 5, 595 << 2 @ .tiles[4440], .subsprites[595]
		Metaprite_299:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 97 @ plttID
			.4byte 4456 << 5, 596 << 2 @ .tiles[4456], .subsprites[596]
		Metaprite_300:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 97 @ plttID
			.4byte 4472 << 5, 597 << 2 @ .tiles[4472], .subsprites[597]
		Metaprite_301:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 97 @ plttID
			.4byte 4488 << 5, 598 << 2 @ .tiles[4488], .subsprites[598]
		Metaprite_302:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 97 @ plttID
			.4byte 4504 << 5, 599 << 2 @ .tiles[4504], .subsprites[599]
		Metaprite_303:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 97 @ plttID
			.4byte 4520 << 5, 600 << 2 @ .tiles[4520], .subsprites[600]
		Metaprite_304:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 97 @ plttID
			.4byte 4536 << 5, 601 << 2 @ .tiles[4536], .subsprites[601]
		Metaprite_305:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 97 @ plttID
			.4byte 4552 << 5, 602 << 2 @ .tiles[4552], .subsprites[602]
		Metaprite_306:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 97 @ plttID
			.4byte 4568 << 5, 603 << 2 @ .tiles[4568], .subsprites[603]
		Metaprite_307:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 97 @ plttID
			.4byte 4584 << 5, 604 << 2 @ .tiles[4584], .subsprites[604]
		Metaprite_308:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 97 @ plttID
			.4byte 4600 << 5, 605 << 2 @ .tiles[4600], .subsprites[605]
		Metaprite_309:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 97 @ plttID
			.4byte 4616 << 5, 606 << 2 @ .tiles[4616], .subsprites[606]
		Metaprite_310:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 97 @ plttID
			.4byte 4632 << 5, 607 << 2 @ .tiles[4632], .subsprites[607]
		Metaprite_311:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 97 @ plttID
			.4byte 4648 << 5, 608 << 2 @ .tiles[4648], .subsprites[608]
		Metaprite_312:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 97 @ plttID
			.4byte 4664 << 5, 609 << 2 @ .tiles[4664], .subsprites[609]
		Metaprite_313:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 97 @ plttID
			.4byte 4680 << 5, 610 << 2 @ .tiles[4680], .subsprites[610]
		Metaprite_314:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 97 @ plttID
			.4byte 4696 << 5, 611 << 2 @ .tiles[4696], .subsprites[611]
		Metaprite_315:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 97 @ plttID
			.4byte 4712 << 5, 612 << 2 @ .tiles[4712], .subsprites[612]
		Metaprite_316:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 97 @ plttID
			.4byte 4728 << 5, 613 << 2 @ .tiles[4728], .subsprites[613]
		Metaprite_317:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 97 @ plttID
			.4byte 4744 << 5, 614 << 2 @ .tiles[4744], .subsprites[614]
		Metaprite_318:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 97 @ plttID
			.4byte 4760 << 5, 615 << 2 @ .tiles[4760], .subsprites[615]
		Metaprite_319:
			.byte 1, 64 @ subspriteCount, unk_01
			.2byte 97 @ plttID
			.4byte 4776 << 5, 616 << 2 @ .tiles[4776], .subsprites[616]
		Metaprite_320:
			.byte 1, 2 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 4840 << 5, 617 << 2 @ .tiles[4840], .subsprites[617]
		Metaprite_321:
			.byte 1, 2 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 4842 << 5, 618 << 2 @ .tiles[4842], .subsprites[618]
		Metaprite_322:
			.byte 1, 2 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 4844 << 5, 619 << 2 @ .tiles[4844], .subsprites[619]
		Metaprite_323:
			.byte 1, 2 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 4846 << 5, 620 << 2 @ .tiles[4846], .subsprites[620]
		Metaprite_324:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 4848 << 5, 621 << 2 @ .tiles[4848], .subsprites[621]
		Metaprite_325:
			.byte 1, 2 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 4849 << 5, 622 << 2 @ .tiles[4849], .subsprites[622]
		Metaprite_326:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 4851 << 5, 623 << 2 @ .tiles[4851], .subsprites[623]
		Metaprite_327:
			.byte 1, 2 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 4852 << 5, 624 << 2 @ .tiles[4852], .subsprites[624]
		Metaprite_328:
			.byte 1, 2 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 4854 << 5, 625 << 2 @ .tiles[4854], .subsprites[625]
		Metaprite_329:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 4856 << 5, 626 << 2 @ .tiles[4856], .subsprites[626]
		Metaprite_330:
			.byte 1, 8 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 4857 << 5, 627 << 2 @ .tiles[4857], .subsprites[627]
		Metaprite_331:
			.byte 1, 8 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 4865 << 5, 628 << 2 @ .tiles[4865], .subsprites[628]
		Metaprite_332:
			.byte 1, 8 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 4873 << 5, 629 << 2 @ .tiles[4873], .subsprites[629]
		Metaprite_333:
			.byte 1, 8 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 4881 << 5, 630 << 2 @ .tiles[4881], .subsprites[630]
		Metaprite_334:
			.byte 1, 8 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 4889 << 5, 631 << 2 @ .tiles[4889], .subsprites[631]
		Metaprite_335:
			.byte 1, 8 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 4897 << 5, 632 << 2 @ .tiles[4897], .subsprites[632]
		Metaprite_336:
			.byte 1, 8 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 4905 << 5, 633 << 2 @ .tiles[4905], .subsprites[633]
		Metaprite_337:
			.byte 4, 24 @ subspriteCount, unk_01
			.2byte 112 @ plttID
			.4byte 4913 << 5, 634 << 2 @ .tiles[4913], .subsprites[634]
		Metaprite_338:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 89 @ plttID
			.4byte 4937 << 5, 638 << 2 @ .tiles[4937], .subsprites[638]
		Metaprite_339:
			.byte 1, 32 @ subspriteCount, unk_01
			.2byte 115 @ plttID
			.4byte 4957 << 5, 640 << 2 @ .tiles[4957], .subsprites[640]
		Metaprite_340:
			.byte 1, 32 @ subspriteCount, unk_01
			.2byte 115 @ plttID
			.4byte 4989 << 5, 641 << 2 @ .tiles[4989], .subsprites[641]
		Metaprite_341:
			.byte 1, 32 @ subspriteCount, unk_01
			.2byte 115 @ plttID
			.4byte 5021 << 5, 642 << 2 @ .tiles[5021], .subsprites[642]
		Metaprite_342:
			.byte 1, 32 @ subspriteCount, unk_01
			.2byte 116 @ plttID
			.4byte 5053 << 5, 643 << 2 @ .tiles[5053], .subsprites[643]
		Metaprite_343:
			.byte 3, 40 @ subspriteCount, unk_01
			.2byte 120 @ plttID
			.4byte 5085 << 5, 644 << 2 @ .tiles[5085], .subsprites[644]
		Metaprite_344:
			.byte 4, 30 @ subspriteCount, unk_01
			.2byte 120 @ plttID
			.4byte 5125 << 5, 647 << 2 @ .tiles[5125], .subsprites[647]
		Metaprite_345:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 125 @ plttID
			.4byte 5155 << 5, 651 << 2 @ .tiles[5155], .subsprites[651]
		Metaprite_346:
			.byte 3, 8 @ subspriteCount, unk_01
			.2byte 125 @ plttID
			.4byte 5159 << 5, 652 << 2 @ .tiles[5159], .subsprites[652]
		Metaprite_347:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 125 @ plttID
			.4byte 5167 << 5, 655 << 2 @ .tiles[5167], .subsprites[655]
		Metaprite_348:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 125 @ plttID
			.4byte 5179 << 5, 658 << 2 @ .tiles[5179], .subsprites[658]
		Metaprite_349:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 125 @ plttID
			.4byte 5195 << 5, 659 << 2 @ .tiles[5195], .subsprites[659]
		Metaprite_350:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 125 @ plttID
			.4byte 5211 << 5, 660 << 2 @ .tiles[5211], .subsprites[660]
		Metaprite_351:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 125 @ plttID
			.4byte 5227 << 5, 661 << 2 @ .tiles[5227], .subsprites[661]
		Metaprite_352:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 125 @ plttID
			.4byte 5243 << 5, 662 << 2 @ .tiles[5243], .subsprites[662]
		Metaprite_353:
			.byte 3, 11 @ subspriteCount, unk_01
			.2byte 125 @ plttID
			.4byte 5259 << 5, 663 << 2 @ .tiles[5259], .subsprites[663]
		Metaprite_354:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 130 @ plttID
			.4byte 5270 << 5, 666 << 2 @ .tiles[5270], .subsprites[666]
		Metaprite_355:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 130 @ plttID
			.4byte 5271 << 5, 667 << 2 @ .tiles[5271], .subsprites[667]
		Metaprite_356:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 130 @ plttID
			.4byte 5272 << 5, 668 << 2 @ .tiles[5272], .subsprites[668]
		Metaprite_357:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 130 @ plttID
			.4byte 5273 << 5, 669 << 2 @ .tiles[5273], .subsprites[669]
		Metaprite_358:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 130 @ plttID
			.4byte 5274 << 5, 670 << 2 @ .tiles[5274], .subsprites[670]
		Metaprite_359:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 130 @ plttID
			.4byte 5275 << 5, 671 << 2 @ .tiles[5275], .subsprites[671]
		Metaprite_360:
			.byte 3, 40 @ subspriteCount, unk_01
			.2byte 139 @ plttID
			.4byte 5276 << 5, 672 << 2 @ .tiles[5276], .subsprites[672]
		Metaprite_361:
			.byte 4, 24 @ subspriteCount, unk_01
			.2byte 142 @ plttID
			.4byte 5316 << 5, 675 << 2 @ .tiles[5316], .subsprites[675]
		Metaprite_362:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 143 @ plttID
			.4byte 5340 << 5, 679 << 2 @ .tiles[5340], .subsprites[679]
		Metaprite_363:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 143 @ plttID
			.4byte 5356 << 5, 680 << 2 @ .tiles[5356], .subsprites[680]
		Metaprite_364:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 143 @ plttID
			.4byte 5372 << 5, 681 << 2 @ .tiles[5372], .subsprites[681]
		Metaprite_365:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 143 @ plttID
			.4byte 5388 << 5, 682 << 2 @ .tiles[5388], .subsprites[682]
		Metaprite_366:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 143 @ plttID
			.4byte 5404 << 5, 683 << 2 @ .tiles[5404], .subsprites[683]
		Metaprite_367:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 143 @ plttID
			.4byte 5420 << 5, 684 << 2 @ .tiles[5420], .subsprites[684]
		Metaprite_368:
			.byte 3, 14 @ subspriteCount, unk_01
			.2byte 143 @ plttID
			.4byte 5436 << 5, 685 << 2 @ .tiles[5436], .subsprites[685]
		Metaprite_369:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 143 @ plttID
			.4byte 5450 << 5, 688 << 2 @ .tiles[5450], .subsprites[688]
		Metaprite_370:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 143 @ plttID
			.4byte 5466 << 5, 689 << 2 @ .tiles[5466], .subsprites[689]
		Metaprite_371:
			.byte 3, 13 @ subspriteCount, unk_01
			.2byte 143 @ plttID
			.4byte 5482 << 5, 690 << 2 @ .tiles[5482], .subsprites[690]
		Metaprite_372:
			.byte 3, 11 @ subspriteCount, unk_01
			.2byte 143 @ plttID
			.4byte 5495 << 5, 693 << 2 @ .tiles[5495], .subsprites[693]
		Metaprite_373:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 143 @ plttID
			.4byte 5506 << 5, 696 << 2 @ .tiles[5506], .subsprites[696]
		Metaprite_374:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 143 @ plttID
			.4byte 5522 << 5, 697 << 2 @ .tiles[5522], .subsprites[697]
		Metaprite_375:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 143 @ plttID
			.4byte 5538 << 5, 698 << 2 @ .tiles[5538], .subsprites[698]
		Metaprite_376:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 143 @ plttID
			.4byte 5554 << 5, 699 << 2 @ .tiles[5554], .subsprites[699]
		Metaprite_377:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 143 @ plttID
			.4byte 5570 << 5, 700 << 2 @ .tiles[5570], .subsprites[700]
		Metaprite_378:
			.byte 1, 32 @ subspriteCount, unk_01
			.2byte 146 @ plttID
			.4byte 5586 << 5, 701 << 2 @ .tiles[5586], .subsprites[701]
		Metaprite_379:
			.byte 1, 32 @ subspriteCount, unk_01
			.2byte 146 @ plttID
			.4byte 5618 << 5, 702 << 2 @ .tiles[5618], .subsprites[702]
		Metaprite_380:
			.byte 1, 32 @ subspriteCount, unk_01
			.2byte 146 @ plttID
			.4byte 5650 << 5, 703 << 2 @ .tiles[5650], .subsprites[703]
		Metaprite_381:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 147 @ plttID
			.4byte 5682 << 5, 704 << 2 @ .tiles[5682], .subsprites[704]
		Metaprite_382:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 147 @ plttID
			.4byte 5694 << 5, 707 << 2 @ .tiles[5694], .subsprites[707]
		Metaprite_383:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 147 @ plttID
			.4byte 5706 << 5, 710 << 2 @ .tiles[5706], .subsprites[710]
		Metaprite_384:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 147 @ plttID
			.4byte 5718 << 5, 713 << 2 @ .tiles[5718], .subsprites[713]
		Metaprite_385:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 147 @ plttID
			.4byte 5734 << 5, 714 << 2 @ .tiles[5734], .subsprites[714]
		Metaprite_386:
			.byte 3, 14 @ subspriteCount, unk_01
			.2byte 147 @ plttID
			.4byte 5750 << 5, 715 << 2 @ .tiles[5750], .subsprites[715]
		Metaprite_387:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 147 @ plttID
			.4byte 5764 << 5, 718 << 2 @ .tiles[5764], .subsprites[718]
		Metaprite_388:
			.byte 3, 14 @ subspriteCount, unk_01
			.2byte 147 @ plttID
			.4byte 5776 << 5, 721 << 2 @ .tiles[5776], .subsprites[721]
		Metaprite_389:
			.byte 3, 14 @ subspriteCount, unk_01
			.2byte 147 @ plttID
			.4byte 5790 << 5, 724 << 2 @ .tiles[5790], .subsprites[724]
		Metaprite_390:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 147 @ plttID
			.4byte 5804 << 5, 727 << 2 @ .tiles[5804], .subsprites[727]
		Metaprite_391:
			.byte 2, 12 @ subspriteCount, unk_01
			.2byte 147 @ plttID
			.4byte 5816 << 5, 730 << 2 @ .tiles[5816], .subsprites[730]
		Metaprite_392:
			.byte 2, 10 @ subspriteCount, unk_01
			.2byte 147 @ plttID
			.4byte 5828 << 5, 732 << 2 @ .tiles[5828], .subsprites[732]
		Metaprite_393:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 147 @ plttID
			.4byte 5838 << 5, 734 << 2 @ .tiles[5838], .subsprites[734]
		Metaprite_394:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 147 @ plttID
			.4byte 5854 << 5, 735 << 2 @ .tiles[5854], .subsprites[735]
		Metaprite_395:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 147 @ plttID
			.4byte 5866 << 5, 738 << 2 @ .tiles[5866], .subsprites[738]
		Metaprite_396:
			.byte 3, 14 @ subspriteCount, unk_01
			.2byte 147 @ plttID
			.4byte 5878 << 5, 741 << 2 @ .tiles[5878], .subsprites[741]
		Metaprite_397:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 147 @ plttID
			.4byte 5892 << 5, 744 << 2 @ .tiles[5892], .subsprites[744]
		Metaprite_398:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 147 @ plttID
			.4byte 5896 << 5, 745 << 2 @ .tiles[5896], .subsprites[745]
		Metaprite_399:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 147 @ plttID
			.4byte 5897 << 5, 746 << 2 @ .tiles[5897], .subsprites[746]
		Metaprite_400:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 147 @ plttID
			.4byte 5898 << 5, 747 << 2 @ .tiles[5898], .subsprites[747]
		Metaprite_401:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 5899 << 5, 748 << 2 @ .tiles[5899], .subsprites[748]
		Metaprite_402:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 5947 << 5, 751 << 2 @ .tiles[5947], .subsprites[751]
		Metaprite_403:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 5995 << 5, 754 << 2 @ .tiles[5995], .subsprites[754]
		Metaprite_404:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 6043 << 5, 757 << 2 @ .tiles[6043], .subsprites[757]
		Metaprite_405:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 6091 << 5, 760 << 2 @ .tiles[6091], .subsprites[760]
		Metaprite_406:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 6139 << 5, 763 << 2 @ .tiles[6139], .subsprites[763]
		Metaprite_407:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 6187 << 5, 766 << 2 @ .tiles[6187], .subsprites[766]
		Metaprite_408:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 6235 << 5, 769 << 2 @ .tiles[6235], .subsprites[769]
		Metaprite_409:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 44 @ plttID
			.4byte 6283 << 5, 772 << 2 @ .tiles[6283], .subsprites[772]
		Metaprite_410:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 44 @ plttID
			.4byte 6299 << 5, 773 << 2 @ .tiles[6299], .subsprites[773]
		Metaprite_411:
			.byte 4, 36 @ subspriteCount, unk_01
			.2byte 151 @ plttID
			.4byte 6315 << 5, 774 << 2 @ .tiles[6315], .subsprites[774]
		Metaprite_412:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 151 @ plttID
			.4byte 6351 << 5, 778 << 2 @ .tiles[6351], .subsprites[778]
		Metaprite_413:
			.byte 3, 32 @ subspriteCount, unk_01
			.2byte 151 @ plttID
			.4byte 6375 << 5, 780 << 2 @ .tiles[6375], .subsprites[780]
		Metaprite_414:
			.byte 3, 14 @ subspriteCount, unk_01
			.2byte 151 @ plttID
			.4byte 6407 << 5, 783 << 2 @ .tiles[6407], .subsprites[783]
		Metaprite_415:
			.byte 4, 36 @ subspriteCount, unk_01
			.2byte 95 @ plttID
			.4byte 6421 << 5, 786 << 2 @ .tiles[6421], .subsprites[786]
		Metaprite_416:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 95 @ plttID
			.4byte 6457 << 5, 790 << 2 @ .tiles[6457], .subsprites[790]
		Metaprite_417:
			.byte 1, 64 @ subspriteCount, unk_01
			.2byte 95 @ plttID
			.4byte 6505 << 5, 793 << 2 @ .tiles[6505], .subsprites[793]
		Metaprite_418:
			.byte 1, 64 @ subspriteCount, unk_01
			.2byte 153 @ plttID
			.4byte 6569 << 5, 794 << 2 @ .tiles[6569], .subsprites[794]
		Metaprite_419:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 6633 << 5, 795 << 2 @ .tiles[6633], .subsprites[795]
		Metaprite_420:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 6681 << 5, 798 << 2 @ .tiles[6681], .subsprites[798]
		Metaprite_421:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 6729 << 5, 801 << 2 @ .tiles[6729], .subsprites[801]
		Metaprite_422:
			.byte 4, 30 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 6777 << 5, 804 << 2 @ .tiles[6777], .subsprites[804]
		Metaprite_423:
			.byte 4, 30 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 6807 << 5, 808 << 2 @ .tiles[6807], .subsprites[808]
		Metaprite_424:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 6837 << 5, 812 << 2 @ .tiles[6837], .subsprites[812]
		Metaprite_425:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 6885 << 5, 815 << 2 @ .tiles[6885], .subsprites[815]
		Metaprite_426:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 6933 << 5, 818 << 2 @ .tiles[6933], .subsprites[818]
		Metaprite_427:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 6981 << 5, 821 << 2 @ .tiles[6981], .subsprites[821]
		Metaprite_428:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 7029 << 5, 824 << 2 @ .tiles[7029], .subsprites[824]
		Metaprite_429:
			.byte 2, 6 @ subspriteCount, unk_01
			.2byte 165 @ plttID
			.4byte 7077 << 5, 827 << 2 @ .tiles[7077], .subsprites[827]
		Metaprite_430:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 165 @ plttID
			.4byte 7083 << 5, 829 << 2 @ .tiles[7083], .subsprites[829]
		Metaprite_431:
			.byte 1, 32 @ subspriteCount, unk_01
			.2byte 165 @ plttID
			.4byte 7107 << 5, 831 << 2 @ .tiles[7107], .subsprites[831]
		Metaprite_432:
			.byte 1, 32 @ subspriteCount, unk_01
			.2byte 165 @ plttID
			.4byte 7139 << 5, 832 << 2 @ .tiles[7139], .subsprites[832]
		Metaprite_433:
			.byte 1, 32 @ subspriteCount, unk_01
			.2byte 165 @ plttID
			.4byte 7171 << 5, 833 << 2 @ .tiles[7171], .subsprites[833]
		Metaprite_434:
			.byte 1, 32 @ subspriteCount, unk_01
			.2byte 165 @ plttID
			.4byte 7203 << 5, 834 << 2 @ .tiles[7203], .subsprites[834]
		Metaprite_435:
			.byte 1, 32 @ subspriteCount, unk_01
			.2byte 165 @ plttID
			.4byte 7235 << 5, 835 << 2 @ .tiles[7235], .subsprites[835]
		Metaprite_436:
			.byte 1, 8 @ subspriteCount, unk_01
			.2byte 166 @ plttID
			.4byte 7267 << 5, 836 << 2 @ .tiles[7267], .subsprites[836]
		Metaprite_437:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 7275 << 5, 837 << 2 @ .tiles[7275], .subsprites[837]
		Metaprite_438:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 7279 << 5, 838 << 2 @ .tiles[7279], .subsprites[838]
		Metaprite_439:
			.byte 1, 32 @ subspriteCount, unk_01
			.2byte 167 @ plttID
			.4byte 7283 << 5, 839 << 2 @ .tiles[7283], .subsprites[839]
		Metaprite_440:
			.byte 3, 40 @ subspriteCount, unk_01
			.2byte 167 @ plttID
			.4byte 7315 << 5, 840 << 2 @ .tiles[7315], .subsprites[840]
		Metaprite_441:
			.byte 1, 32 @ subspriteCount, unk_01
			.2byte 167 @ plttID
			.4byte 7355 << 5, 843 << 2 @ .tiles[7355], .subsprites[843]
		Metaprite_442:
			.byte 1, 32 @ subspriteCount, unk_01
			.2byte 167 @ plttID
			.4byte 7387 << 5, 844 << 2 @ .tiles[7387], .subsprites[844]
		Metaprite_443:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 167 @ plttID
			.4byte 7419 << 5, 845 << 2 @ .tiles[7419], .subsprites[845]
		Metaprite_444:
			.byte 4, 18 @ subspriteCount, unk_01
			.2byte 167 @ plttID
			.4byte 7439 << 5, 847 << 2 @ .tiles[7439], .subsprites[847]
		Metaprite_445:
			.byte 1, 32 @ subspriteCount, unk_01
			.2byte 167 @ plttID
			.4byte 7457 << 5, 851 << 2 @ .tiles[7457], .subsprites[851]
		Metaprite_446:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 167 @ plttID
			.4byte 7489 << 5, 852 << 2 @ .tiles[7489], .subsprites[852]
		Metaprite_447:
			.byte 4, 18 @ subspriteCount, unk_01
			.2byte 167 @ plttID
			.4byte 7509 << 5, 854 << 2 @ .tiles[7509], .subsprites[854]
		Metaprite_448:
			.byte 1, 32 @ subspriteCount, unk_01
			.2byte 167 @ plttID
			.4byte 7527 << 5, 858 << 2 @ .tiles[7527], .subsprites[858]
		Metaprite_449:
			.byte 3, 40 @ subspriteCount, unk_01
			.2byte 167 @ plttID
			.4byte 7559 << 5, 859 << 2 @ .tiles[7559], .subsprites[859]
		Metaprite_450:
			.byte 1, 32 @ subspriteCount, unk_01
			.2byte 167 @ plttID
			.4byte 7599 << 5, 862 << 2 @ .tiles[7599], .subsprites[862]
		Metaprite_451:
			.byte 1, 32 @ subspriteCount, unk_01
			.2byte 167 @ plttID
			.4byte 7631 << 5, 863 << 2 @ .tiles[7631], .subsprites[863]
		Metaprite_452:
			.byte 3, 40 @ subspriteCount, unk_01
			.2byte 167 @ plttID
			.4byte 7663 << 5, 864 << 2 @ .tiles[7663], .subsprites[864]
		Metaprite_453:
			.byte 1, 32 @ subspriteCount, unk_01
			.2byte 167 @ plttID
			.4byte 7703 << 5, 867 << 2 @ .tiles[7703], .subsprites[867]
		Metaprite_454:
			.byte 1, 32 @ subspriteCount, unk_01
			.2byte 175 @ plttID
			.4byte 7735 << 5, 868 << 2 @ .tiles[7735], .subsprites[868]
		Metaprite_455:
			.byte 3, 40 @ subspriteCount, unk_01
			.2byte 175 @ plttID
			.4byte 7767 << 5, 869 << 2 @ .tiles[7767], .subsprites[869]
		Metaprite_456:
			.byte 1, 32 @ subspriteCount, unk_01
			.2byte 175 @ plttID
			.4byte 7807 << 5, 872 << 2 @ .tiles[7807], .subsprites[872]
		Metaprite_457:
			.byte 1, 32 @ subspriteCount, unk_01
			.2byte 175 @ plttID
			.4byte 7839 << 5, 873 << 2 @ .tiles[7839], .subsprites[873]
		Metaprite_458:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 175 @ plttID
			.4byte 7871 << 5, 874 << 2 @ .tiles[7871], .subsprites[874]
		Metaprite_459:
			.byte 4, 18 @ subspriteCount, unk_01
			.2byte 175 @ plttID
			.4byte 7891 << 5, 876 << 2 @ .tiles[7891], .subsprites[876]
		Metaprite_460:
			.byte 1, 32 @ subspriteCount, unk_01
			.2byte 175 @ plttID
			.4byte 7909 << 5, 880 << 2 @ .tiles[7909], .subsprites[880]
		Metaprite_461:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 175 @ plttID
			.4byte 7941 << 5, 881 << 2 @ .tiles[7941], .subsprites[881]
		Metaprite_462:
			.byte 4, 18 @ subspriteCount, unk_01
			.2byte 175 @ plttID
			.4byte 7961 << 5, 883 << 2 @ .tiles[7961], .subsprites[883]
		Metaprite_463:
			.byte 1, 32 @ subspriteCount, unk_01
			.2byte 175 @ plttID
			.4byte 7979 << 5, 887 << 2 @ .tiles[7979], .subsprites[887]
		Metaprite_464:
			.byte 3, 40 @ subspriteCount, unk_01
			.2byte 175 @ plttID
			.4byte 8011 << 5, 888 << 2 @ .tiles[8011], .subsprites[888]
		Metaprite_465:
			.byte 1, 32 @ subspriteCount, unk_01
			.2byte 175 @ plttID
			.4byte 8051 << 5, 891 << 2 @ .tiles[8051], .subsprites[891]
		Metaprite_466:
			.byte 1, 32 @ subspriteCount, unk_01
			.2byte 175 @ plttID
			.4byte 8083 << 5, 892 << 2 @ .tiles[8083], .subsprites[892]
		Metaprite_467:
			.byte 3, 40 @ subspriteCount, unk_01
			.2byte 175 @ plttID
			.4byte 8115 << 5, 893 << 2 @ .tiles[8115], .subsprites[893]
		Metaprite_468:
			.byte 1, 32 @ subspriteCount, unk_01
			.2byte 175 @ plttID
			.4byte 8155 << 5, 896 << 2 @ .tiles[8155], .subsprites[896]
		Metaprite_469:
			.byte 2, 10 @ subspriteCount, unk_01
			.2byte 176 @ plttID
			.4byte 8187 << 5, 897 << 2 @ .tiles[8187], .subsprites[897]
		Metaprite_470:
			.byte 3, 11 @ subspriteCount, unk_01
			.2byte 176 @ plttID
			.4byte 8197 << 5, 899 << 2 @ .tiles[8197], .subsprites[899]
		Metaprite_471:
			.byte 1, 8 @ subspriteCount, unk_01
			.2byte 176 @ plttID
			.4byte 8208 << 5, 902 << 2 @ .tiles[8208], .subsprites[902]
		Metaprite_472:
			.byte 4, 9 @ subspriteCount, unk_01
			.2byte 176 @ plttID
			.4byte 8216 << 5, 903 << 2 @ .tiles[8216], .subsprites[903]
		Metaprite_473:
			.byte 3, 7 @ subspriteCount, unk_01
			.2byte 176 @ plttID
			.4byte 8225 << 5, 907 << 2 @ .tiles[8225], .subsprites[907]
		Metaprite_474:
			.byte 2, 6 @ subspriteCount, unk_01
			.2byte 176 @ plttID
			.4byte 8232 << 5, 910 << 2 @ .tiles[8232], .subsprites[910]
		Metaprite_475:
			.byte 4, 9 @ subspriteCount, unk_01
			.2byte 176 @ plttID
			.4byte 8238 << 5, 912 << 2 @ .tiles[8238], .subsprites[912]
		Metaprite_476:
			.byte 3, 7 @ subspriteCount, unk_01
			.2byte 176 @ plttID
			.4byte 8247 << 5, 916 << 2 @ .tiles[8247], .subsprites[916]
		Metaprite_477:
			.byte 2, 5 @ subspriteCount, unk_01
			.2byte 176 @ plttID
			.4byte 8254 << 5, 919 << 2 @ .tiles[8254], .subsprites[919]
		Metaprite_478:
			.byte 2, 6 @ subspriteCount, unk_01
			.2byte 176 @ plttID
			.4byte 8259 << 5, 921 << 2 @ .tiles[8259], .subsprites[921]
		Metaprite_479:
			.byte 3, 7 @ subspriteCount, unk_01
			.2byte 176 @ plttID
			.4byte 8265 << 5, 923 << 2 @ .tiles[8265], .subsprites[923]
		Metaprite_480:
			.byte 3, 7 @ subspriteCount, unk_01
			.2byte 176 @ plttID
			.4byte 8272 << 5, 926 << 2 @ .tiles[8272], .subsprites[926]
		Metaprite_481:
			.byte 1, 8 @ subspriteCount, unk_01
			.2byte 176 @ plttID
			.4byte 8279 << 5, 929 << 2 @ .tiles[8279], .subsprites[929]
		Metaprite_482:
			.byte 1, 8 @ subspriteCount, unk_01
			.2byte 176 @ plttID
			.4byte 8287 << 5, 930 << 2 @ .tiles[8287], .subsprites[930]
		Metaprite_483:
			.byte 2, 10 @ subspriteCount, unk_01
			.2byte 176 @ plttID
			.4byte 8295 << 5, 931 << 2 @ .tiles[8295], .subsprites[931]
		Metaprite_484:
			.byte 3, 7 @ subspriteCount, unk_01
			.2byte 176 @ plttID
			.4byte 8305 << 5, 933 << 2 @ .tiles[8305], .subsprites[933]
		Metaprite_485:
			.byte 3, 7 @ subspriteCount, unk_01
			.2byte 176 @ plttID
			.4byte 8312 << 5, 936 << 2 @ .tiles[8312], .subsprites[936]
		Metaprite_486:
			.byte 2, 6 @ subspriteCount, unk_01
			.2byte 176 @ plttID
			.4byte 8319 << 5, 939 << 2 @ .tiles[8319], .subsprites[939]
		Metaprite_487:
			.byte 3, 8 @ subspriteCount, unk_01
			.2byte 176 @ plttID
			.4byte 8325 << 5, 941 << 2 @ .tiles[8325], .subsprites[941]
		Metaprite_488:
			.byte 3, 8 @ subspriteCount, unk_01
			.2byte 176 @ plttID
			.4byte 8333 << 5, 944 << 2 @ .tiles[8333], .subsprites[944]
		Metaprite_489:
			.byte 3, 7 @ subspriteCount, unk_01
			.2byte 176 @ plttID
			.4byte 8341 << 5, 947 << 2 @ .tiles[8341], .subsprites[947]
		Metaprite_490:
			.byte 3, 6 @ subspriteCount, unk_01
			.2byte 176 @ plttID
			.4byte 8348 << 5, 950 << 2 @ .tiles[8348], .subsprites[950]
		Metaprite_491:
			.byte 3, 6 @ subspriteCount, unk_01
			.2byte 176 @ plttID
			.4byte 8354 << 5, 953 << 2 @ .tiles[8354], .subsprites[953]
		Metaprite_492:
			.byte 2, 6 @ subspriteCount, unk_01
			.2byte 176 @ plttID
			.4byte 8360 << 5, 956 << 2 @ .tiles[8360], .subsprites[956]
		Metaprite_493:
			.byte 2, 8 @ subspriteCount, unk_01
			.2byte 176 @ plttID
			.4byte 8366 << 5, 958 << 2 @ .tiles[8366], .subsprites[958]
		Metaprite_494:
			.byte 2, 8 @ subspriteCount, unk_01
			.2byte 176 @ plttID
			.4byte 8374 << 5, 960 << 2 @ .tiles[8374], .subsprites[960]
		Metaprite_495:
			.byte 3, 7 @ subspriteCount, unk_01
			.2byte 176 @ plttID
			.4byte 8382 << 5, 962 << 2 @ .tiles[8382], .subsprites[962]
		Metaprite_496:
			.byte 2, 5 @ subspriteCount, unk_01
			.2byte 176 @ plttID
			.4byte 8389 << 5, 965 << 2 @ .tiles[8389], .subsprites[965]
		Metaprite_497:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 176 @ plttID
			.4byte 8394 << 5, 967 << 2 @ .tiles[8394], .subsprites[967]
		Metaprite_498:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 8398 << 5, 968 << 2 @ .tiles[8398], .subsprites[968]
		Metaprite_499:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 8446 << 5, 971 << 2 @ .tiles[8446], .subsprites[971]
		Metaprite_500:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 8494 << 5, 974 << 2 @ .tiles[8494], .subsprites[974]
		Metaprite_501:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 8542 << 5, 977 << 2 @ .tiles[8542], .subsprites[977]
		Metaprite_502:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 8590 << 5, 980 << 2 @ .tiles[8590], .subsprites[980]
		Metaprite_503:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 8638 << 5, 983 << 2 @ .tiles[8638], .subsprites[983]
		Metaprite_504:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 8686 << 5, 986 << 2 @ .tiles[8686], .subsprites[986]
		Metaprite_505:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 8734 << 5, 989 << 2 @ .tiles[8734], .subsprites[989]
		Metaprite_506:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 8782 << 5, 992 << 2 @ .tiles[8782], .subsprites[992]
		Metaprite_507:
			.byte 2, 36 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 8830 << 5, 995 << 2 @ .tiles[8830], .subsprites[995]
		Metaprite_508:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 8866 << 5, 997 << 2 @ .tiles[8866], .subsprites[997]
		Metaprite_509:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 8914 << 5, 1000 << 2 @ .tiles[8914], .subsprites[1000]
		Metaprite_510:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 179 @ plttID
			.4byte 8962 << 5, 1003 << 2 @ .tiles[8962], .subsprites[1003]
		Metaprite_511:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 179 @ plttID
			.4byte 8966 << 5, 1004 << 2 @ .tiles[8966], .subsprites[1004]
		Metaprite_512:
			.byte 3, 7 @ subspriteCount, unk_01
			.2byte 179 @ plttID
			.4byte 8982 << 5, 1005 << 2 @ .tiles[8982], .subsprites[1005]
		Metaprite_513:
			.byte 3, 7 @ subspriteCount, unk_01
			.2byte 179 @ plttID
			.4byte 8989 << 5, 1008 << 2 @ .tiles[8989], .subsprites[1008]
		Metaprite_514:
			.byte 3, 8 @ subspriteCount, unk_01
			.2byte 179 @ plttID
			.4byte 8996 << 5, 1011 << 2 @ .tiles[8996], .subsprites[1011]
		Metaprite_515:
			.byte 3, 8 @ subspriteCount, unk_01
			.2byte 179 @ plttID
			.4byte 9004 << 5, 1014 << 2 @ .tiles[9004], .subsprites[1014]
		Metaprite_516:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 179 @ plttID
			.4byte 9012 << 5, 1017 << 2 @ .tiles[9012], .subsprites[1017]
		Metaprite_517:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 179 @ plttID
			.4byte 9028 << 5, 1018 << 2 @ .tiles[9028], .subsprites[1018]
		Metaprite_518:
			.byte 1, 64 @ subspriteCount, unk_01
			.2byte 181 @ plttID
			.4byte 9029 << 5, 1019 << 2 @ .tiles[9029], .subsprites[1019]
		Metaprite_519:
			.byte 3, 24 @ subspriteCount, unk_01
			.2byte 187 @ plttID
			.4byte 9093 << 5, 1020 << 2 @ .tiles[9093], .subsprites[1020]
		Metaprite_520:
			.byte 1, 32 @ subspriteCount, unk_01
			.2byte 188 @ plttID
			.4byte 9117 << 5, 1023 << 2 @ .tiles[9117], .subsprites[1023]
		Metaprite_521:
			.byte 1, 32 @ subspriteCount, unk_01
			.2byte 188 @ plttID
			.4byte 9149 << 5, 1024 << 2 @ .tiles[9149], .subsprites[1024]
		Metaprite_522:
			.byte 1, 32 @ subspriteCount, unk_01
			.2byte 188 @ plttID
			.4byte 9181 << 5, 1025 << 2 @ .tiles[9181], .subsprites[1025]
		Metaprite_523:
			.byte 1, 32 @ subspriteCount, unk_01
			.2byte 188 @ plttID
			.4byte 9213 << 5, 1026 << 2 @ .tiles[9213], .subsprites[1026]
		Metaprite_524:
			.byte 1, 32 @ subspriteCount, unk_01
			.2byte 188 @ plttID
			.4byte 9245 << 5, 1027 << 2 @ .tiles[9245], .subsprites[1027]
		Metaprite_525:
			.byte 1, 32 @ subspriteCount, unk_01
			.2byte 188 @ plttID
			.4byte 9277 << 5, 1028 << 2 @ .tiles[9277], .subsprites[1028]
		Metaprite_526:
			.byte 1, 32 @ subspriteCount, unk_01
			.2byte 188 @ plttID
			.4byte 9309 << 5, 1029 << 2 @ .tiles[9309], .subsprites[1029]
		Metaprite_527:
			.byte 1, 32 @ subspriteCount, unk_01
			.2byte 188 @ plttID
			.4byte 9341 << 5, 1030 << 2 @ .tiles[9341], .subsprites[1030]
		Metaprite_528:
			.byte 3, 24 @ subspriteCount, unk_01
			.2byte 42 @ plttID
			.4byte 9373 << 5, 1031 << 2 @ .tiles[9373], .subsprites[1031]
		Metaprite_529:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 195 @ plttID
			.4byte 9397 << 5, 1034 << 2 @ .tiles[9397], .subsprites[1034]
		Metaprite_530:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 195 @ plttID
			.4byte 9401 << 5, 1035 << 2 @ .tiles[9401], .subsprites[1035]
		Metaprite_531:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 195 @ plttID
			.4byte 9405 << 5, 1036 << 2 @ .tiles[9405], .subsprites[1036]
		Metaprite_532:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 195 @ plttID
			.4byte 9409 << 5, 1037 << 2 @ .tiles[9409], .subsprites[1037]
		Metaprite_533:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 195 @ plttID
			.4byte 9413 << 5, 1038 << 2 @ .tiles[9413], .subsprites[1038]
		Metaprite_534:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 195 @ plttID
			.4byte 9417 << 5, 1039 << 2 @ .tiles[9417], .subsprites[1039]
		Metaprite_535:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 195 @ plttID
			.4byte 9421 << 5, 1040 << 2 @ .tiles[9421], .subsprites[1040]
		Metaprite_536:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 195 @ plttID
			.4byte 9425 << 5, 1041 << 2 @ .tiles[9425], .subsprites[1041]
		Metaprite_537:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 195 @ plttID
			.4byte 9429 << 5, 1042 << 2 @ .tiles[9429], .subsprites[1042]
		Metaprite_538:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 195 @ plttID
			.4byte 9433 << 5, 1043 << 2 @ .tiles[9433], .subsprites[1043]
		Metaprite_539:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 195 @ plttID
			.4byte 9437 << 5, 1044 << 2 @ .tiles[9437], .subsprites[1044]
		Metaprite_540:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 195 @ plttID
			.4byte 9441 << 5, 1045 << 2 @ .tiles[9441], .subsprites[1045]
		Metaprite_541:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 195 @ plttID
			.4byte 9445 << 5, 1046 << 2 @ .tiles[9445], .subsprites[1046]
		Metaprite_542:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 195 @ plttID
			.4byte 9449 << 5, 1047 << 2 @ .tiles[9449], .subsprites[1047]
		Metaprite_543:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 195 @ plttID
			.4byte 9453 << 5, 1048 << 2 @ .tiles[9453], .subsprites[1048]
		Metaprite_544:
			.byte 1, 2 @ subspriteCount, unk_01
			.2byte 195 @ plttID
			.4byte 9457 << 5, 1049 << 2 @ .tiles[9457], .subsprites[1049]
		Metaprite_545:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 195 @ plttID
			.4byte 9459 << 5, 1050 << 2 @ .tiles[9459], .subsprites[1050]
		Metaprite_546:
			.byte 2, 3 @ subspriteCount, unk_01
			.2byte 195 @ plttID
			.4byte 9460 << 5, 1051 << 2 @ .tiles[9460], .subsprites[1051]
		Metaprite_547:
			.byte 2, 3 @ subspriteCount, unk_01
			.2byte 195 @ plttID
			.4byte 9463 << 5, 1053 << 2 @ .tiles[9463], .subsprites[1053]
		Metaprite_548:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 195 @ plttID
			.4byte 9466 << 5, 1055 << 2 @ .tiles[9466], .subsprites[1055]
		Metaprite_549:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 195 @ plttID
			.4byte 9470 << 5, 1056 << 2 @ .tiles[9470], .subsprites[1056]
		Metaprite_550:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 195 @ plttID
			.4byte 9474 << 5, 1057 << 2 @ .tiles[9474], .subsprites[1057]
		Metaprite_551:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 195 @ plttID
			.4byte 9478 << 5, 1058 << 2 @ .tiles[9478], .subsprites[1058]
		Metaprite_552:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 195 @ plttID
			.4byte 9482 << 5, 1059 << 2 @ .tiles[9482], .subsprites[1059]
		Metaprite_553:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 195 @ plttID
			.4byte 9486 << 5, 1060 << 2 @ .tiles[9486], .subsprites[1060]
		Metaprite_554:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 195 @ plttID
			.4byte 9490 << 5, 1061 << 2 @ .tiles[9490], .subsprites[1061]
		Metaprite_555:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 207 @ plttID
			.4byte 9494 << 5, 1062 << 2 @ .tiles[9494], .subsprites[1062]
		Metaprite_556:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 207 @ plttID
			.4byte 9498 << 5, 1063 << 2 @ .tiles[9498], .subsprites[1063]
		Metaprite_557:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 207 @ plttID
			.4byte 9502 << 5, 1064 << 2 @ .tiles[9502], .subsprites[1064]
		Metaprite_558:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 207 @ plttID
			.4byte 9506 << 5, 1065 << 2 @ .tiles[9506], .subsprites[1065]
		Metaprite_559:
			.byte 1, 2 @ subspriteCount, unk_01
			.2byte 207 @ plttID
			.4byte 9510 << 5, 1066 << 2 @ .tiles[9510], .subsprites[1066]
		Metaprite_560:
			.byte 1, 2 @ subspriteCount, unk_01
			.2byte 207 @ plttID
			.4byte 9512 << 5, 1067 << 2 @ .tiles[9512], .subsprites[1067]
		Metaprite_561:
			.byte 1, 2 @ subspriteCount, unk_01
			.2byte 207 @ plttID
			.4byte 9514 << 5, 1068 << 2 @ .tiles[9514], .subsprites[1068]
		Metaprite_562:
			.byte 1, 2 @ subspriteCount, unk_01
			.2byte 207 @ plttID
			.4byte 9516 << 5, 1069 << 2 @ .tiles[9516], .subsprites[1069]
		Metaprite_563:
			.byte 1, 2 @ subspriteCount, unk_01
			.2byte 207 @ plttID
			.4byte 9518 << 5, 1070 << 2 @ .tiles[9518], .subsprites[1070]
		Metaprite_564:
			.byte 1, 2 @ subspriteCount, unk_01
			.2byte 207 @ plttID
			.4byte 9520 << 5, 1071 << 2 @ .tiles[9520], .subsprites[1071]
		Metaprite_565:
			.byte 1, 2 @ subspriteCount, unk_01
			.2byte 207 @ plttID
			.4byte 9522 << 5, 1072 << 2 @ .tiles[9522], .subsprites[1072]
		Metaprite_566:
			.byte 1, 2 @ subspriteCount, unk_01
			.2byte 207 @ plttID
			.4byte 9524 << 5, 1073 << 2 @ .tiles[9524], .subsprites[1073]
		Metaprite_567:
			.byte 1, 2 @ subspriteCount, unk_01
			.2byte 207 @ plttID
			.4byte 9526 << 5, 1074 << 2 @ .tiles[9526], .subsprites[1074]
		Metaprite_568:
			.byte 1, 2 @ subspriteCount, unk_01
			.2byte 207 @ plttID
			.4byte 9528 << 5, 1075 << 2 @ .tiles[9528], .subsprites[1075]
		Metaprite_569:
			.byte 1, 2 @ subspriteCount, unk_01
			.2byte 207 @ plttID
			.4byte 9530 << 5, 1076 << 2 @ .tiles[9530], .subsprites[1076]
		Metaprite_570:
			.byte 2, 12 @ subspriteCount, unk_01
			.2byte 208 @ plttID
			.4byte 9532 << 5, 1077 << 2 @ .tiles[9532], .subsprites[1077]
		Metaprite_571:
			.byte 4, 9 @ subspriteCount, unk_01
			.2byte 208 @ plttID
			.4byte 9544 << 5, 1079 << 2 @ .tiles[9544], .subsprites[1079]
		Metaprite_572:
			.byte 4, 36 @ subspriteCount, unk_01
			.2byte 213 @ plttID
			.4byte 9553 << 5, 1083 << 2 @ .tiles[9553], .subsprites[1083]
		Metaprite_573:
			.byte 3, 40 @ subspriteCount, unk_01
			.2byte 97 @ plttID
			.4byte 9589 << 5, 1087 << 2 @ .tiles[9589], .subsprites[1087]
		Metaprite_574:
			.byte 3, 40 @ subspriteCount, unk_01
			.2byte 97 @ plttID
			.4byte 9629 << 5, 1090 << 2 @ .tiles[9629], .subsprites[1090]
		Metaprite_575:
			.byte 3, 40 @ subspriteCount, unk_01
			.2byte 97 @ plttID
			.4byte 9669 << 5, 1093 << 2 @ .tiles[9669], .subsprites[1093]
		Metaprite_576:
			.byte 3, 40 @ subspriteCount, unk_01
			.2byte 97 @ plttID
			.4byte 9709 << 5, 1096 << 2 @ .tiles[9709], .subsprites[1096]
		Metaprite_577:
			.byte 3, 7 @ subspriteCount, unk_01
			.2byte 216 @ plttID
			.4byte 9749 << 5, 1099 << 2 @ .tiles[9749], .subsprites[1099]
		Metaprite_578:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 216 @ plttID
			.4byte 9756 << 5, 1102 << 2 @ .tiles[9756], .subsprites[1102]
		Metaprite_579:
			.byte 3, 14 @ subspriteCount, unk_01
			.2byte 216 @ plttID
			.4byte 9772 << 5, 1103 << 2 @ .tiles[9772], .subsprites[1103]
		Metaprite_580:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 216 @ plttID
			.4byte 9786 << 5, 1106 << 2 @ .tiles[9786], .subsprites[1106]
		Metaprite_581:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 216 @ plttID
			.4byte 9802 << 5, 1107 << 2 @ .tiles[9802], .subsprites[1107]
		Metaprite_582:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 216 @ plttID
			.4byte 9818 << 5, 1108 << 2 @ .tiles[9818], .subsprites[1108]
		Metaprite_583:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 216 @ plttID
			.4byte 9834 << 5, 1109 << 2 @ .tiles[9834], .subsprites[1109]
		Metaprite_584:
			.byte 3, 14 @ subspriteCount, unk_01
			.2byte 216 @ plttID
			.4byte 9850 << 5, 1110 << 2 @ .tiles[9850], .subsprites[1110]
		Metaprite_585:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 216 @ plttID
			.4byte 9864 << 5, 1113 << 2 @ .tiles[9864], .subsprites[1113]
		Metaprite_586:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 216 @ plttID
			.4byte 9880 << 5, 1114 << 2 @ .tiles[9880], .subsprites[1114]
		Metaprite_587:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 216 @ plttID
			.4byte 9896 << 5, 1115 << 2 @ .tiles[9896], .subsprites[1115]
		Metaprite_588:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 216 @ plttID
			.4byte 9912 << 5, 1116 << 2 @ .tiles[9912], .subsprites[1116]
		Metaprite_589:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 216 @ plttID
			.4byte 9928 << 5, 1117 << 2 @ .tiles[9928], .subsprites[1117]
		Metaprite_590:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 216 @ plttID
			.4byte 9944 << 5, 1118 << 2 @ .tiles[9944], .subsprites[1118]
		Metaprite_591:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 216 @ plttID
			.4byte 9960 << 5, 1119 << 2 @ .tiles[9960], .subsprites[1119]
		Metaprite_592:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 216 @ plttID
			.4byte 9976 << 5, 1120 << 2 @ .tiles[9976], .subsprites[1120]
		Metaprite_593:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 216 @ plttID
			.4byte 9992 << 5, 1121 << 2 @ .tiles[9992], .subsprites[1121]
		Metaprite_594:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 216 @ plttID
			.4byte 10008 << 5, 1122 << 2 @ .tiles[10008], .subsprites[1122]
		Metaprite_595:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 216 @ plttID
			.4byte 10020 << 5, 1125 << 2 @ .tiles[10020], .subsprites[1125]
		Metaprite_596:
			.byte 3, 11 @ subspriteCount, unk_01
			.2byte 216 @ plttID
			.4byte 10032 << 5, 1128 << 2 @ .tiles[10032], .subsprites[1128]
		Metaprite_597:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 216 @ plttID
			.4byte 10043 << 5, 1131 << 2 @ .tiles[10043], .subsprites[1131]
		Metaprite_598:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 216 @ plttID
			.4byte 10055 << 5, 1134 << 2 @ .tiles[10055], .subsprites[1134]
		Metaprite_599:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 216 @ plttID
			.4byte 10067 << 5, 1137 << 2 @ .tiles[10067], .subsprites[1137]
		Metaprite_600:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 216 @ plttID
			.4byte 10079 << 5, 1140 << 2 @ .tiles[10079], .subsprites[1140]
		Metaprite_601:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 216 @ plttID
			.4byte 10083 << 5, 1141 << 2 @ .tiles[10083], .subsprites[1141]
		Metaprite_602:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 216 @ plttID
			.4byte 10095 << 5, 1144 << 2 @ .tiles[10095], .subsprites[1144]
		Metaprite_603:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 216 @ plttID
			.4byte 10107 << 5, 1147 << 2 @ .tiles[10107], .subsprites[1147]
		Metaprite_604:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 216 @ plttID
			.4byte 10111 << 5, 1148 << 2 @ .tiles[10111], .subsprites[1148]
		Metaprite_605:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 216 @ plttID
			.4byte 10115 << 5, 1149 << 2 @ .tiles[10115], .subsprites[1149]
		Metaprite_606:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 216 @ plttID
			.4byte 10119 << 5, 1150 << 2 @ .tiles[10119], .subsprites[1150]
		Metaprite_607:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 216 @ plttID
			.4byte 10123 << 5, 1151 << 2 @ .tiles[10123], .subsprites[1151]
		Metaprite_608:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 216 @ plttID
			.4byte 10127 << 5, 1152 << 2 @ .tiles[10127], .subsprites[1152]
		Metaprite_609:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 216 @ plttID
			.4byte 10131 << 5, 1153 << 2 @ .tiles[10131], .subsprites[1153]
		Metaprite_610:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 216 @ plttID
			.4byte 10135 << 5, 1154 << 2 @ .tiles[10135], .subsprites[1154]
		Metaprite_611:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 216 @ plttID
			.4byte 10139 << 5, 1155 << 2 @ .tiles[10139], .subsprites[1155]
		Metaprite_612:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 216 @ plttID
			.4byte 10143 << 5, 1156 << 2 @ .tiles[10143], .subsprites[1156]
		Metaprite_613:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 216 @ plttID
			.4byte 10147 << 5, 1157 << 2 @ .tiles[10147], .subsprites[1157]
		Metaprite_614:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 216 @ plttID
			.4byte 10151 << 5, 1158 << 2 @ .tiles[10151], .subsprites[1158]
		Metaprite_615:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 216 @ plttID
			.4byte 10155 << 5, 1159 << 2 @ .tiles[10155], .subsprites[1159]
		Metaprite_616:
			.byte 4, 30 @ subspriteCount, unk_01
			.2byte 216 @ plttID
			.4byte 10159 << 5, 1160 << 2 @ .tiles[10159], .subsprites[1160]
		Metaprite_617:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 216 @ plttID
			.4byte 10189 << 5, 1164 << 2 @ .tiles[10189], .subsprites[1164]
		Metaprite_618:
			.byte 4, 36 @ subspriteCount, unk_01
			.2byte 216 @ plttID
			.4byte 10213 << 5, 1166 << 2 @ .tiles[10213], .subsprites[1166]
		Metaprite_619:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 216 @ plttID
			.4byte 10249 << 5, 1170 << 2 @ .tiles[10249], .subsprites[1170]
		Metaprite_620:
			.byte 4, 30 @ subspriteCount, unk_01
			.2byte 216 @ plttID
			.4byte 10297 << 5, 1173 << 2 @ .tiles[10297], .subsprites[1173]
		Metaprite_621:
			.byte 4, 30 @ subspriteCount, unk_01
			.2byte 216 @ plttID
			.4byte 10327 << 5, 1177 << 2 @ .tiles[10327], .subsprites[1177]
		Metaprite_622:
			.byte 4, 30 @ subspriteCount, unk_01
			.2byte 220 @ plttID
			.4byte 10357 << 5, 1181 << 2 @ .tiles[10357], .subsprites[1181]
		Metaprite_623:
			.byte 4, 30 @ subspriteCount, unk_01
			.2byte 220 @ plttID
			.4byte 10387 << 5, 1185 << 2 @ .tiles[10387], .subsprites[1185]
		Metaprite_624:
			.byte 4, 30 @ subspriteCount, unk_01
			.2byte 220 @ plttID
			.4byte 10417 << 5, 1189 << 2 @ .tiles[10417], .subsprites[1189]
		Metaprite_625:
			.byte 4, 30 @ subspriteCount, unk_01
			.2byte 220 @ plttID
			.4byte 10447 << 5, 1193 << 2 @ .tiles[10447], .subsprites[1193]
		Metaprite_626:
			.byte 4, 30 @ subspriteCount, unk_01
			.2byte 220 @ plttID
			.4byte 10477 << 5, 1197 << 2 @ .tiles[10477], .subsprites[1197]
		Metaprite_627:
			.byte 4, 30 @ subspriteCount, unk_01
			.2byte 220 @ plttID
			.4byte 10507 << 5, 1201 << 2 @ .tiles[10507], .subsprites[1201]
		Metaprite_628:
			.byte 4, 30 @ subspriteCount, unk_01
			.2byte 220 @ plttID
			.4byte 10537 << 5, 1205 << 2 @ .tiles[10537], .subsprites[1205]
		Metaprite_629:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 220 @ plttID
			.4byte 10567 << 5, 1209 << 2 @ .tiles[10567], .subsprites[1209]
		Metaprite_630:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 220 @ plttID
			.4byte 10587 << 5, 1211 << 2 @ .tiles[10587], .subsprites[1211]
		Metaprite_631:
			.byte 4, 30 @ subspriteCount, unk_01
			.2byte 220 @ plttID
			.4byte 10607 << 5, 1213 << 2 @ .tiles[10607], .subsprites[1213]
		Metaprite_632:
			.byte 4, 30 @ subspriteCount, unk_01
			.2byte 220 @ plttID
			.4byte 10637 << 5, 1217 << 2 @ .tiles[10637], .subsprites[1217]
		Metaprite_633:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 220 @ plttID
			.4byte 10667 << 5, 1221 << 2 @ .tiles[10667], .subsprites[1221]
		Metaprite_634:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 220 @ plttID
			.4byte 10687 << 5, 1223 << 2 @ .tiles[10687], .subsprites[1223]
		Metaprite_635:
			.byte 3, 40 @ subspriteCount, unk_01
			.2byte 220 @ plttID
			.4byte 10707 << 5, 1225 << 2 @ .tiles[10707], .subsprites[1225]
		Metaprite_636:
			.byte 3, 24 @ subspriteCount, unk_01
			.2byte 220 @ plttID
			.4byte 10747 << 5, 1228 << 2 @ .tiles[10747], .subsprites[1228]
		Metaprite_637:
			.byte 3, 24 @ subspriteCount, unk_01
			.2byte 220 @ plttID
			.4byte 10771 << 5, 1231 << 2 @ .tiles[10771], .subsprites[1231]
		Metaprite_638:
			.byte 4, 30 @ subspriteCount, unk_01
			.2byte 220 @ plttID
			.4byte 10795 << 5, 1234 << 2 @ .tiles[10795], .subsprites[1234]
		Metaprite_639:
			.byte 1, 64 @ subspriteCount, unk_01
			.2byte 220 @ plttID
			.4byte 10825 << 5, 1238 << 2 @ .tiles[10825], .subsprites[1238]
		Metaprite_640:
			.byte 4, 36 @ subspriteCount, unk_01
			.2byte 220 @ plttID
			.4byte 10889 << 5, 1239 << 2 @ .tiles[10889], .subsprites[1239]
		Metaprite_641:
			.byte 3, 40 @ subspriteCount, unk_01
			.2byte 220 @ plttID
			.4byte 10925 << 5, 1243 << 2 @ .tiles[10925], .subsprites[1243]
		Metaprite_642:
			.byte 4, 30 @ subspriteCount, unk_01
			.2byte 220 @ plttID
			.4byte 10965 << 5, 1246 << 2 @ .tiles[10965], .subsprites[1246]
		Metaprite_643:
			.byte 4, 30 @ subspriteCount, unk_01
			.2byte 220 @ plttID
			.4byte 10995 << 5, 1250 << 2 @ .tiles[10995], .subsprites[1250]
		Metaprite_644:
			.byte 4, 30 @ subspriteCount, unk_01
			.2byte 220 @ plttID
			.4byte 11025 << 5, 1254 << 2 @ .tiles[11025], .subsprites[1254]
		Metaprite_645:
			.byte 3, 40 @ subspriteCount, unk_01
			.2byte 220 @ plttID
			.4byte 11055 << 5, 1258 << 2 @ .tiles[11055], .subsprites[1258]
		Metaprite_646:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 220 @ plttID
			.4byte 11095 << 5, 1261 << 2 @ .tiles[11095], .subsprites[1261]
		Metaprite_647:
			.byte 3, 28 @ subspriteCount, unk_01
			.2byte 220 @ plttID
			.4byte 11143 << 5, 1264 << 2 @ .tiles[11143], .subsprites[1264]
		Metaprite_648:
			.byte 3, 28 @ subspriteCount, unk_01
			.2byte 220 @ plttID
			.4byte 11171 << 5, 1267 << 2 @ .tiles[11171], .subsprites[1267]
		Metaprite_649:
			.byte 4, 30 @ subspriteCount, unk_01
			.2byte 220 @ plttID
			.4byte 11199 << 5, 1270 << 2 @ .tiles[11199], .subsprites[1270]
		Metaprite_650:
			.byte 3, 40 @ subspriteCount, unk_01
			.2byte 220 @ plttID
			.4byte 11229 << 5, 1274 << 2 @ .tiles[11229], .subsprites[1274]
		Metaprite_651:
			.byte 3, 40 @ subspriteCount, unk_01
			.2byte 220 @ plttID
			.4byte 11269 << 5, 1277 << 2 @ .tiles[11269], .subsprites[1277]
		Metaprite_652:
			.byte 3, 40 @ subspriteCount, unk_01
			.2byte 220 @ plttID
			.4byte 11309 << 5, 1280 << 2 @ .tiles[11309], .subsprites[1280]
		Metaprite_653:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 220 @ plttID
			.4byte 11349 << 5, 1283 << 2 @ .tiles[11349], .subsprites[1283]
		Metaprite_654:
			.byte 3, 40 @ subspriteCount, unk_01
			.2byte 220 @ plttID
			.4byte 11397 << 5, 1286 << 2 @ .tiles[11397], .subsprites[1286]
		Metaprite_655:
			.byte 4, 30 @ subspriteCount, unk_01
			.2byte 220 @ plttID
			.4byte 11437 << 5, 1289 << 2 @ .tiles[11437], .subsprites[1289]
		Metaprite_656:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 220 @ plttID
			.4byte 11467 << 5, 1293 << 2 @ .tiles[11467], .subsprites[1293]
		Metaprite_657:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 220 @ plttID
			.4byte 11487 << 5, 1295 << 2 @ .tiles[11487], .subsprites[1295]
		Metaprite_658:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 220 @ plttID
			.4byte 11507 << 5, 1297 << 2 @ .tiles[11507], .subsprites[1297]
		Metaprite_659:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 220 @ plttID
			.4byte 11527 << 5, 1299 << 2 @ .tiles[11527], .subsprites[1299]
		Metaprite_660:
			.byte 4, 36 @ subspriteCount, unk_01
			.2byte 236 @ plttID
			.4byte 11539 << 5, 1302 << 2 @ .tiles[11539], .subsprites[1302]
		Metaprite_661:
			.byte 3, 28 @ subspriteCount, unk_01
			.2byte 239 @ plttID
			.4byte 11575 << 5, 1306 << 2 @ .tiles[11575], .subsprites[1306]
		Metaprite_662:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 11603 << 5, 1309 << 2 @ .tiles[11603], .subsprites[1309]
		Metaprite_663:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 11607 << 5, 1310 << 2 @ .tiles[11607], .subsprites[1310]
		Metaprite_664:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 11611 << 5, 1311 << 2 @ .tiles[11611], .subsprites[1311]
		Metaprite_665:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 11615 << 5, 1312 << 2 @ .tiles[11615], .subsprites[1312]
		Metaprite_666:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 11619 << 5, 1313 << 2 @ .tiles[11619], .subsprites[1313]
		Metaprite_667:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 11623 << 5, 1314 << 2 @ .tiles[11623], .subsprites[1314]
		Metaprite_668:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 11627 << 5, 1315 << 2 @ .tiles[11627], .subsprites[1315]
		Metaprite_669:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 11631 << 5, 1316 << 2 @ .tiles[11631], .subsprites[1316]
		Metaprite_670:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 11635 << 5, 1317 << 2 @ .tiles[11635], .subsprites[1317]
		Metaprite_671:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 11639 << 5, 1318 << 2 @ .tiles[11639], .subsprites[1318]
		Metaprite_672:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 11643 << 5, 1319 << 2 @ .tiles[11643], .subsprites[1319]
		Metaprite_673:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 11647 << 5, 1320 << 2 @ .tiles[11647], .subsprites[1320]
		Metaprite_674:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 11651 << 5, 1321 << 2 @ .tiles[11651], .subsprites[1321]
		Metaprite_675:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 11655 << 5, 1322 << 2 @ .tiles[11655], .subsprites[1322]
		Metaprite_676:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 11659 << 5, 1323 << 2 @ .tiles[11659], .subsprites[1323]
		Metaprite_677:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 11663 << 5, 1324 << 2 @ .tiles[11663], .subsprites[1324]
		Metaprite_678:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 11667 << 5, 1325 << 2 @ .tiles[11667], .subsprites[1325]
		Metaprite_679:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 11671 << 5, 1326 << 2 @ .tiles[11671], .subsprites[1326]
		Metaprite_680:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 11675 << 5, 1327 << 2 @ .tiles[11675], .subsprites[1327]
		Metaprite_681:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 11679 << 5, 1328 << 2 @ .tiles[11679], .subsprites[1328]
		Metaprite_682:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 11683 << 5, 1329 << 2 @ .tiles[11683], .subsprites[1329]
		Metaprite_683:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 11687 << 5, 1330 << 2 @ .tiles[11687], .subsprites[1330]
		Metaprite_684:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 11691 << 5, 1331 << 2 @ .tiles[11691], .subsprites[1331]
		Metaprite_685:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 11695 << 5, 1332 << 2 @ .tiles[11695], .subsprites[1332]
		Metaprite_686:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 242 @ plttID
			.4byte 11699 << 5, 1333 << 2 @ .tiles[11699], .subsprites[1333]
		Metaprite_687:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 242 @ plttID
			.4byte 11703 << 5, 1334 << 2 @ .tiles[11703], .subsprites[1334]
		Metaprite_688:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 242 @ plttID
			.4byte 11707 << 5, 1335 << 2 @ .tiles[11707], .subsprites[1335]
		Metaprite_689:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 242 @ plttID
			.4byte 11711 << 5, 1336 << 2 @ .tiles[11711], .subsprites[1336]
		Metaprite_690:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 242 @ plttID
			.4byte 11715 << 5, 1337 << 2 @ .tiles[11715], .subsprites[1337]
		Metaprite_691:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 242 @ plttID
			.4byte 11719 << 5, 1338 << 2 @ .tiles[11719], .subsprites[1338]
		Metaprite_692:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 242 @ plttID
			.4byte 11723 << 5, 1339 << 2 @ .tiles[11723], .subsprites[1339]
		Metaprite_693:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 242 @ plttID
			.4byte 11727 << 5, 1340 << 2 @ .tiles[11727], .subsprites[1340]
		Metaprite_694:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 242 @ plttID
			.4byte 11731 << 5, 1341 << 2 @ .tiles[11731], .subsprites[1341]
		Metaprite_695:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 242 @ plttID
			.4byte 11735 << 5, 1342 << 2 @ .tiles[11735], .subsprites[1342]
		Metaprite_696:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 242 @ plttID
			.4byte 11739 << 5, 1343 << 2 @ .tiles[11739], .subsprites[1343]
		Metaprite_697:
			.byte 3, 32 @ subspriteCount, unk_01
			.2byte 243 @ plttID
			.4byte 11743 << 5, 1344 << 2 @ .tiles[11743], .subsprites[1344]
		Metaprite_698:
			.byte 4, 36 @ subspriteCount, unk_01
			.2byte 244 @ plttID
			.4byte 11775 << 5, 1347 << 2 @ .tiles[11775], .subsprites[1347]
		Metaprite_699:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 11811 << 5, 1351 << 2 @ .tiles[11811], .subsprites[1351]
		Metaprite_700:
			.byte 2, 5 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 11827 << 5, 1352 << 2 @ .tiles[11827], .subsprites[1352]
		Metaprite_701:
			.byte 2, 5 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 11832 << 5, 1354 << 2 @ .tiles[11832], .subsprites[1354]
		Metaprite_702:
			.byte 2, 5 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 11837 << 5, 1356 << 2 @ .tiles[11837], .subsprites[1356]
		Metaprite_703:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 11842 << 5, 1358 << 2 @ .tiles[11842], .subsprites[1358]
		Metaprite_704:
			.byte 3, 6 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 11858 << 5, 1359 << 2 @ .tiles[11858], .subsprites[1359]
		Metaprite_705:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 11864 << 5, 1362 << 2 @ .tiles[11864], .subsprites[1362]
		Metaprite_706:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 11880 << 5, 1363 << 2 @ .tiles[11880], .subsprites[1363]
		Metaprite_707:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 11884 << 5, 1364 << 2 @ .tiles[11884], .subsprites[1364]
		Metaprite_708:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 11888 << 5, 1365 << 2 @ .tiles[11888], .subsprites[1365]
		Metaprite_709:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 11892 << 5, 1366 << 2 @ .tiles[11892], .subsprites[1366]
		Metaprite_710:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 11896 << 5, 1367 << 2 @ .tiles[11896], .subsprites[1367]
		Metaprite_711:
			.byte 1, 2 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 11900 << 5, 1368 << 2 @ .tiles[11900], .subsprites[1368]
		Metaprite_712:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 11902 << 5, 1369 << 2 @ .tiles[11902], .subsprites[1369]
		Metaprite_713:
			.byte 2, 6 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 11906 << 5, 1370 << 2 @ .tiles[11906], .subsprites[1370]
		Metaprite_714:
			.byte 3, 7 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 11912 << 5, 1372 << 2 @ .tiles[11912], .subsprites[1372]
		Metaprite_715:
			.byte 4, 9 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 11919 << 5, 1375 << 2 @ .tiles[11919], .subsprites[1375]
		Metaprite_716:
			.byte 2, 12 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 11928 << 5, 1379 << 2 @ .tiles[11928], .subsprites[1379]
		Metaprite_717:
			.byte 3, 4 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 11940 << 5, 1381 << 2 @ .tiles[11940], .subsprites[1381]
		Metaprite_718:
			.byte 1, 2 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 11944 << 5, 1384 << 2 @ .tiles[11944], .subsprites[1384]
		Metaprite_719:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 11946 << 5, 1385 << 2 @ .tiles[11946], .subsprites[1385]
		Metaprite_720:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 11950 << 5, 1386 << 2 @ .tiles[11950], .subsprites[1386]
		Metaprite_721:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 11954 << 5, 1387 << 2 @ .tiles[11954], .subsprites[1387]
		Metaprite_722:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 11958 << 5, 1388 << 2 @ .tiles[11958], .subsprites[1388]
		Metaprite_723:
			.byte 1, 2 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 11962 << 5, 1389 << 2 @ .tiles[11962], .subsprites[1389]
		Metaprite_724:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 11964 << 5, 1390 << 2 @ .tiles[11964], .subsprites[1390]
		Metaprite_725:
			.byte 3, 14 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 11980 << 5, 1391 << 2 @ .tiles[11980], .subsprites[1391]
		Metaprite_726:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 11994 << 5, 1394 << 2 @ .tiles[11994], .subsprites[1394]
		Metaprite_727:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 12010 << 5, 1395 << 2 @ .tiles[12010], .subsprites[1395]
		Metaprite_728:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 12026 << 5, 1396 << 2 @ .tiles[12026], .subsprites[1396]
		Metaprite_729:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 12042 << 5, 1397 << 2 @ .tiles[12042], .subsprites[1397]
		Metaprite_730:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 12058 << 5, 1398 << 2 @ .tiles[12058], .subsprites[1398]
		Metaprite_731:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 12074 << 5, 1399 << 2 @ .tiles[12074], .subsprites[1399]
		Metaprite_732:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 12090 << 5, 1400 << 2 @ .tiles[12090], .subsprites[1400]
		Metaprite_733:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 12106 << 5, 1401 << 2 @ .tiles[12106], .subsprites[1401]
		Metaprite_734:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 12118 << 5, 1404 << 2 @ .tiles[12118], .subsprites[1404]
		Metaprite_735:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 12134 << 5, 1405 << 2 @ .tiles[12134], .subsprites[1405]
		Metaprite_736:
			.byte 3, 14 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 12150 << 5, 1406 << 2 @ .tiles[12150], .subsprites[1406]
		Metaprite_737:
			.byte 3, 14 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 12164 << 5, 1409 << 2 @ .tiles[12164], .subsprites[1409]
		Metaprite_738:
			.byte 3, 14 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 12178 << 5, 1412 << 2 @ .tiles[12178], .subsprites[1412]
		Metaprite_739:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 12192 << 5, 1415 << 2 @ .tiles[12192], .subsprites[1415]
		Metaprite_740:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 12208 << 5, 1416 << 2 @ .tiles[12208], .subsprites[1416]
		Metaprite_741:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 12224 << 5, 1417 << 2 @ .tiles[12224], .subsprites[1417]
		Metaprite_742:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 12236 << 5, 1420 << 2 @ .tiles[12236], .subsprites[1420]
		Metaprite_743:
			.byte 1, 8 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 12248 << 5, 1423 << 2 @ .tiles[12248], .subsprites[1423]
		Metaprite_744:
			.byte 3, 7 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 12256 << 5, 1424 << 2 @ .tiles[12256], .subsprites[1424]
		Metaprite_745:
			.byte 1, 8 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 12263 << 5, 1427 << 2 @ .tiles[12263], .subsprites[1427]
		Metaprite_746:
			.byte 1, 8 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 12271 << 5, 1428 << 2 @ .tiles[12271], .subsprites[1428]
		Metaprite_747:
			.byte 3, 6 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 12279 << 5, 1429 << 2 @ .tiles[12279], .subsprites[1429]
		Metaprite_748:
			.byte 2, 12 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 12285 << 5, 1432 << 2 @ .tiles[12285], .subsprites[1432]
		Metaprite_749:
			.byte 3, 6 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 12297 << 5, 1434 << 2 @ .tiles[12297], .subsprites[1434]
		Metaprite_750:
			.byte 3, 6 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 12303 << 5, 1437 << 2 @ .tiles[12303], .subsprites[1437]
		Metaprite_751:
			.byte 2, 12 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 12309 << 5, 1440 << 2 @ .tiles[12309], .subsprites[1440]
		Metaprite_752:
			.byte 3, 6 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 12321 << 5, 1442 << 2 @ .tiles[12321], .subsprites[1442]
		Metaprite_753:
			.byte 3, 8 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 12327 << 5, 1445 << 2 @ .tiles[12327], .subsprites[1445]
		Metaprite_754:
			.byte 3, 13 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 12335 << 5, 1448 << 2 @ .tiles[12335], .subsprites[1448]
		Metaprite_755:
			.byte 3, 14 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 12348 << 5, 1451 << 2 @ .tiles[12348], .subsprites[1451]
		Metaprite_756:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 12362 << 5, 1454 << 2 @ .tiles[12362], .subsprites[1454]
		Metaprite_757:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 12378 << 5, 1455 << 2 @ .tiles[12378], .subsprites[1455]
		Metaprite_758:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 12394 << 5, 1456 << 2 @ .tiles[12394], .subsprites[1456]
		Metaprite_759:
			.byte 3, 11 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 12410 << 5, 1457 << 2 @ .tiles[12410], .subsprites[1457]
		Metaprite_760:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 12421 << 5, 1460 << 2 @ .tiles[12421], .subsprites[1460]
		Metaprite_761:
			.byte 3, 7 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 12437 << 5, 1461 << 2 @ .tiles[12437], .subsprites[1461]
		Metaprite_762:
			.byte 3, 5 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 12444 << 5, 1464 << 2 @ .tiles[12444], .subsprites[1464]
		Metaprite_763:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 12449 << 5, 1467 << 2 @ .tiles[12449], .subsprites[1467]
		Metaprite_764:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 12465 << 5, 1468 << 2 @ .tiles[12465], .subsprites[1468]
		Metaprite_765:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 12481 << 5, 1469 << 2 @ .tiles[12481], .subsprites[1469]
		Metaprite_766:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 12497 << 5, 1470 << 2 @ .tiles[12497], .subsprites[1470]
		Metaprite_767:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 12501 << 5, 1471 << 2 @ .tiles[12501], .subsprites[1471]
		Metaprite_768:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 12517 << 5, 1472 << 2 @ .tiles[12517], .subsprites[1472]
		Metaprite_769:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 12533 << 5, 1473 << 2 @ .tiles[12533], .subsprites[1473]
		Metaprite_770:
			.byte 2, 12 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 12549 << 5, 1474 << 2 @ .tiles[12549], .subsprites[1474]
		Metaprite_771:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 12561 << 5, 1476 << 2 @ .tiles[12561], .subsprites[1476]
		Metaprite_772:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 12577 << 5, 1477 << 2 @ .tiles[12577], .subsprites[1477]
		Metaprite_773:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 12593 << 5, 1478 << 2 @ .tiles[12593], .subsprites[1478]
		Metaprite_774:
			.byte 2, 12 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 12609 << 5, 1479 << 2 @ .tiles[12609], .subsprites[1479]
		Metaprite_775:
			.byte 2, 5 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 12621 << 5, 1481 << 2 @ .tiles[12621], .subsprites[1481]
		Metaprite_776:
			.byte 2, 5 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 12626 << 5, 1483 << 2 @ .tiles[12626], .subsprites[1483]
		Metaprite_777:
			.byte 2, 5 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 12631 << 5, 1485 << 2 @ .tiles[12631], .subsprites[1485]
		Metaprite_778:
			.byte 2, 5 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 12636 << 5, 1487 << 2 @ .tiles[12636], .subsprites[1487]
		Metaprite_779:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 12641 << 5, 1489 << 2 @ .tiles[12641], .subsprites[1489]
		Metaprite_780:
			.byte 2, 6 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 12653 << 5, 1492 << 2 @ .tiles[12653], .subsprites[1492]
		Metaprite_781:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 12659 << 5, 1494 << 2 @ .tiles[12659], .subsprites[1494]
		Metaprite_782:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 12663 << 5, 1495 << 2 @ .tiles[12663], .subsprites[1495]
		Metaprite_783:
			.byte 2, 12 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 12679 << 5, 1496 << 2 @ .tiles[12679], .subsprites[1496]
		Metaprite_784:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 247 @ plttID
			.4byte 12691 << 5, 1498 << 2 @ .tiles[12691], .subsprites[1498]
		Metaprite_785:
			.byte 1, 2 @ subspriteCount, unk_01
			.2byte 263 @ plttID
			.4byte 12707 << 5, 1499 << 2 @ .tiles[12707], .subsprites[1499]
		Metaprite_786:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 268 @ plttID
			.4byte 12709 << 5, 1500 << 2 @ .tiles[12709], .subsprites[1500]
		Metaprite_787:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 268 @ plttID
			.4byte 12721 << 5, 1503 << 2 @ .tiles[12721], .subsprites[1503]
		Metaprite_788:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 268 @ plttID
			.4byte 12733 << 5, 1506 << 2 @ .tiles[12733], .subsprites[1506]
		Metaprite_789:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 268 @ plttID
			.4byte 12745 << 5, 1509 << 2 @ .tiles[12745], .subsprites[1509]
		Metaprite_790:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 268 @ plttID
			.4byte 12757 << 5, 1512 << 2 @ .tiles[12757], .subsprites[1512]
		Metaprite_791:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 268 @ plttID
			.4byte 12769 << 5, 1515 << 2 @ .tiles[12769], .subsprites[1515]
		Metaprite_792:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 268 @ plttID
			.4byte 12781 << 5, 1518 << 2 @ .tiles[12781], .subsprites[1518]
		Metaprite_793:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 268 @ plttID
			.4byte 12793 << 5, 1521 << 2 @ .tiles[12793], .subsprites[1521]
		Metaprite_794:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 268 @ plttID
			.4byte 12805 << 5, 1524 << 2 @ .tiles[12805], .subsprites[1524]
		Metaprite_795:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 268 @ plttID
			.4byte 12817 << 5, 1527 << 2 @ .tiles[12817], .subsprites[1527]
		Metaprite_796:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 268 @ plttID
			.4byte 12829 << 5, 1530 << 2 @ .tiles[12829], .subsprites[1530]
		Metaprite_797:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 275 @ plttID
			.4byte 12841 << 5, 1533 << 2 @ .tiles[12841], .subsprites[1533]
		Metaprite_798:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 275 @ plttID
			.4byte 12857 << 5, 1534 << 2 @ .tiles[12857], .subsprites[1534]
		Metaprite_799:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 275 @ plttID
			.4byte 12873 << 5, 1535 << 2 @ .tiles[12873], .subsprites[1535]
		Metaprite_800:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 275 @ plttID
			.4byte 12889 << 5, 1536 << 2 @ .tiles[12889], .subsprites[1536]
		Metaprite_801:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 275 @ plttID
			.4byte 12905 << 5, 1537 << 2 @ .tiles[12905], .subsprites[1537]
		Metaprite_802:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 275 @ plttID
			.4byte 12921 << 5, 1538 << 2 @ .tiles[12921], .subsprites[1538]
		Metaprite_803:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 275 @ plttID
			.4byte 12937 << 5, 1539 << 2 @ .tiles[12937], .subsprites[1539]
		Metaprite_804:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 275 @ plttID
			.4byte 12953 << 5, 1540 << 2 @ .tiles[12953], .subsprites[1540]
		Metaprite_805:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 275 @ plttID
			.4byte 12969 << 5, 1541 << 2 @ .tiles[12969], .subsprites[1541]
		Metaprite_806:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 275 @ plttID
			.4byte 12985 << 5, 1542 << 2 @ .tiles[12985], .subsprites[1542]
		Metaprite_807:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 275 @ plttID
			.4byte 13001 << 5, 1543 << 2 @ .tiles[13001], .subsprites[1543]
		Metaprite_808:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 275 @ plttID
			.4byte 13017 << 5, 1544 << 2 @ .tiles[13017], .subsprites[1544]
		Metaprite_809:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 275 @ plttID
			.4byte 13033 << 5, 1545 << 2 @ .tiles[13033], .subsprites[1545]
		Metaprite_810:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 275 @ plttID
			.4byte 13049 << 5, 1546 << 2 @ .tiles[13049], .subsprites[1546]
		Metaprite_811:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 275 @ plttID
			.4byte 13065 << 5, 1547 << 2 @ .tiles[13065], .subsprites[1547]
		Metaprite_812:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 275 @ plttID
			.4byte 13081 << 5, 1548 << 2 @ .tiles[13081], .subsprites[1548]
		Metaprite_813:
			.byte 2, 6 @ subspriteCount, unk_01
			.2byte 279 @ plttID
			.4byte 13097 << 5, 1549 << 2 @ .tiles[13097], .subsprites[1549]
		Metaprite_814:
			.byte 2, 6 @ subspriteCount, unk_01
			.2byte 279 @ plttID
			.4byte 13103 << 5, 1551 << 2 @ .tiles[13103], .subsprites[1551]
		Metaprite_815:
			.byte 1, 8 @ subspriteCount, unk_01
			.2byte 279 @ plttID
			.4byte 13109 << 5, 1553 << 2 @ .tiles[13109], .subsprites[1553]
		Metaprite_816:
			.byte 2, 5 @ subspriteCount, unk_01
			.2byte 279 @ plttID
			.4byte 13117 << 5, 1554 << 2 @ .tiles[13117], .subsprites[1554]
		Metaprite_817:
			.byte 2, 6 @ subspriteCount, unk_01
			.2byte 279 @ plttID
			.4byte 13122 << 5, 1556 << 2 @ .tiles[13122], .subsprites[1556]
		Metaprite_818:
			.byte 3, 7 @ subspriteCount, unk_01
			.2byte 279 @ plttID
			.4byte 13128 << 5, 1558 << 2 @ .tiles[13128], .subsprites[1558]
		Metaprite_819:
			.byte 2, 5 @ subspriteCount, unk_01
			.2byte 279 @ plttID
			.4byte 13135 << 5, 1561 << 2 @ .tiles[13135], .subsprites[1561]
		Metaprite_820:
			.byte 2, 5 @ subspriteCount, unk_01
			.2byte 279 @ plttID
			.4byte 13140 << 5, 1563 << 2 @ .tiles[13140], .subsprites[1563]
		Metaprite_821:
			.byte 2, 5 @ subspriteCount, unk_01
			.2byte 279 @ plttID
			.4byte 13145 << 5, 1565 << 2 @ .tiles[13145], .subsprites[1565]
		Metaprite_822:
			.byte 2, 5 @ subspriteCount, unk_01
			.2byte 279 @ plttID
			.4byte 13150 << 5, 1567 << 2 @ .tiles[13150], .subsprites[1567]
		Metaprite_823:
			.byte 2, 5 @ subspriteCount, unk_01
			.2byte 279 @ plttID
			.4byte 13155 << 5, 1569 << 2 @ .tiles[13155], .subsprites[1569]
		Metaprite_824:
			.byte 2, 5 @ subspriteCount, unk_01
			.2byte 279 @ plttID
			.4byte 13160 << 5, 1571 << 2 @ .tiles[13160], .subsprites[1571]
		Metaprite_825:
			.byte 2, 6 @ subspriteCount, unk_01
			.2byte 279 @ plttID
			.4byte 13165 << 5, 1573 << 2 @ .tiles[13165], .subsprites[1573]
		Metaprite_826:
			.byte 2, 6 @ subspriteCount, unk_01
			.2byte 279 @ plttID
			.4byte 13171 << 5, 1575 << 2 @ .tiles[13171], .subsprites[1575]
		Metaprite_827:
			.byte 2, 6 @ subspriteCount, unk_01
			.2byte 279 @ plttID
			.4byte 13177 << 5, 1577 << 2 @ .tiles[13177], .subsprites[1577]
		Metaprite_828:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 279 @ plttID
			.4byte 13183 << 5, 1579 << 2 @ .tiles[13183], .subsprites[1579]
		Metaprite_829:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 279 @ plttID
			.4byte 13187 << 5, 1580 << 2 @ .tiles[13187], .subsprites[1580]
		Metaprite_830:
			.byte 2, 6 @ subspriteCount, unk_01
			.2byte 279 @ plttID
			.4byte 13191 << 5, 1581 << 2 @ .tiles[13191], .subsprites[1581]
		Metaprite_831:
			.byte 2, 6 @ subspriteCount, unk_01
			.2byte 279 @ plttID
			.4byte 13197 << 5, 1583 << 2 @ .tiles[13197], .subsprites[1583]
		Metaprite_832:
			.byte 2, 6 @ subspriteCount, unk_01
			.2byte 279 @ plttID
			.4byte 13203 << 5, 1585 << 2 @ .tiles[13203], .subsprites[1585]
		Metaprite_833:
			.byte 2, 6 @ subspriteCount, unk_01
			.2byte 279 @ plttID
			.4byte 13209 << 5, 1587 << 2 @ .tiles[13209], .subsprites[1587]
		Metaprite_834:
			.byte 2, 6 @ subspriteCount, unk_01
			.2byte 279 @ plttID
			.4byte 13215 << 5, 1589 << 2 @ .tiles[13215], .subsprites[1589]
		Metaprite_835:
			.byte 2, 6 @ subspriteCount, unk_01
			.2byte 279 @ plttID
			.4byte 13221 << 5, 1591 << 2 @ .tiles[13221], .subsprites[1591]
		Metaprite_836:
			.byte 2, 6 @ subspriteCount, unk_01
			.2byte 279 @ plttID
			.4byte 13227 << 5, 1593 << 2 @ .tiles[13227], .subsprites[1593]
		Metaprite_837:
			.byte 2, 6 @ subspriteCount, unk_01
			.2byte 279 @ plttID
			.4byte 13233 << 5, 1595 << 2 @ .tiles[13233], .subsprites[1595]
		Metaprite_838:
			.byte 2, 6 @ subspriteCount, unk_01
			.2byte 279 @ plttID
			.4byte 13239 << 5, 1597 << 2 @ .tiles[13239], .subsprites[1597]
		Metaprite_839:
			.byte 2, 6 @ subspriteCount, unk_01
			.2byte 279 @ plttID
			.4byte 13245 << 5, 1599 << 2 @ .tiles[13245], .subsprites[1599]
		Metaprite_840:
			.byte 2, 6 @ subspriteCount, unk_01
			.2byte 279 @ plttID
			.4byte 13251 << 5, 1601 << 2 @ .tiles[13251], .subsprites[1601]
		Metaprite_841:
			.byte 2, 6 @ subspriteCount, unk_01
			.2byte 279 @ plttID
			.4byte 13257 << 5, 1603 << 2 @ .tiles[13257], .subsprites[1603]
		Metaprite_842:
			.byte 2, 6 @ subspriteCount, unk_01
			.2byte 279 @ plttID
			.4byte 13263 << 5, 1605 << 2 @ .tiles[13263], .subsprites[1605]
		Metaprite_843:
			.byte 2, 6 @ subspriteCount, unk_01
			.2byte 279 @ plttID
			.4byte 13269 << 5, 1607 << 2 @ .tiles[13269], .subsprites[1607]
		Metaprite_844:
			.byte 2, 6 @ subspriteCount, unk_01
			.2byte 279 @ plttID
			.4byte 13275 << 5, 1609 << 2 @ .tiles[13275], .subsprites[1609]
		Metaprite_845:
			.byte 2, 6 @ subspriteCount, unk_01
			.2byte 279 @ plttID
			.4byte 13281 << 5, 1611 << 2 @ .tiles[13281], .subsprites[1611]
		Metaprite_846:
			.byte 2, 6 @ subspriteCount, unk_01
			.2byte 279 @ plttID
			.4byte 13287 << 5, 1613 << 2 @ .tiles[13287], .subsprites[1613]
		Metaprite_847:
			.byte 2, 6 @ subspriteCount, unk_01
			.2byte 279 @ plttID
			.4byte 13293 << 5, 1615 << 2 @ .tiles[13293], .subsprites[1615]
		Metaprite_848:
			.byte 2, 6 @ subspriteCount, unk_01
			.2byte 279 @ plttID
			.4byte 13299 << 5, 1617 << 2 @ .tiles[13299], .subsprites[1617]
		Metaprite_849:
			.byte 2, 6 @ subspriteCount, unk_01
			.2byte 279 @ plttID
			.4byte 13305 << 5, 1619 << 2 @ .tiles[13305], .subsprites[1619]
		Metaprite_850:
			.byte 2, 6 @ subspriteCount, unk_01
			.2byte 279 @ plttID
			.4byte 13311 << 5, 1621 << 2 @ .tiles[13311], .subsprites[1621]
		Metaprite_851:
			.byte 3, 8 @ subspriteCount, unk_01
			.2byte 279 @ plttID
			.4byte 13317 << 5, 1623 << 2 @ .tiles[13317], .subsprites[1623]
		Metaprite_852:
			.byte 3, 7 @ subspriteCount, unk_01
			.2byte 279 @ plttID
			.4byte 13325 << 5, 1626 << 2 @ .tiles[13325], .subsprites[1626]
		Metaprite_853:
			.byte 3, 7 @ subspriteCount, unk_01
			.2byte 279 @ plttID
			.4byte 13332 << 5, 1629 << 2 @ .tiles[13332], .subsprites[1629]
		Metaprite_854:
			.byte 2, 6 @ subspriteCount, unk_01
			.2byte 279 @ plttID
			.4byte 13339 << 5, 1632 << 2 @ .tiles[13339], .subsprites[1632]
		Metaprite_855:
			.byte 2, 12 @ subspriteCount, unk_01
			.2byte 279 @ plttID
			.4byte 13345 << 5, 1634 << 2 @ .tiles[13345], .subsprites[1634]
		Metaprite_856:
			.byte 3, 9 @ subspriteCount, unk_01
			.2byte 279 @ plttID
			.4byte 13357 << 5, 1636 << 2 @ .tiles[13357], .subsprites[1636]
		Metaprite_857:
			.byte 4, 9 @ subspriteCount, unk_01
			.2byte 279 @ plttID
			.4byte 13366 << 5, 1639 << 2 @ .tiles[13366], .subsprites[1639]
		Metaprite_858:
			.byte 2, 6 @ subspriteCount, unk_01
			.2byte 279 @ plttID
			.4byte 13375 << 5, 1643 << 2 @ .tiles[13375], .subsprites[1643]
		Metaprite_859:
			.byte 2, 6 @ subspriteCount, unk_01
			.2byte 279 @ plttID
			.4byte 13381 << 5, 1645 << 2 @ .tiles[13381], .subsprites[1645]
		Metaprite_860:
			.byte 3, 8 @ subspriteCount, unk_01
			.2byte 279 @ plttID
			.4byte 13387 << 5, 1647 << 2 @ .tiles[13387], .subsprites[1647]
		Metaprite_861:
			.byte 2, 12 @ subspriteCount, unk_01
			.2byte 279 @ plttID
			.4byte 13395 << 5, 1650 << 2 @ .tiles[13395], .subsprites[1650]
		Metaprite_862:
			.byte 2, 12 @ subspriteCount, unk_01
			.2byte 279 @ plttID
			.4byte 13407 << 5, 1652 << 2 @ .tiles[13407], .subsprites[1652]
		Metaprite_863:
			.byte 2, 6 @ subspriteCount, unk_01
			.2byte 279 @ plttID
			.4byte 13419 << 5, 1654 << 2 @ .tiles[13419], .subsprites[1654]
		Metaprite_864:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 283 @ plttID
			.4byte 13425 << 5, 1656 << 2 @ .tiles[13425], .subsprites[1656]
		Metaprite_865:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 283 @ plttID
			.4byte 13441 << 5, 1657 << 2 @ .tiles[13441], .subsprites[1657]
		Metaprite_866:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 13442 << 5, 1658 << 2 @ .tiles[13442], .subsprites[1658]
		Metaprite_867:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 13490 << 5, 1661 << 2 @ .tiles[13490], .subsprites[1661]
		Metaprite_868:
			.byte 4, 36 @ subspriteCount, unk_01
			.2byte 284 @ plttID
			.4byte 13538 << 5, 1664 << 2 @ .tiles[13538], .subsprites[1664]
		Metaprite_869:
			.byte 3, 24 @ subspriteCount, unk_01
			.2byte 287 @ plttID
			.4byte 13574 << 5, 1668 << 2 @ .tiles[13574], .subsprites[1668]
		Metaprite_870:
			.byte 3, 24 @ subspriteCount, unk_01
			.2byte 287 @ plttID
			.4byte 13598 << 5, 1671 << 2 @ .tiles[13598], .subsprites[1671]
		Metaprite_871:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 44 @ plttID
			.4byte 13622 << 5, 1674 << 2 @ .tiles[13622], .subsprites[1674]
		Metaprite_872:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 44 @ plttID
			.4byte 13626 << 5, 1675 << 2 @ .tiles[13626], .subsprites[1675]
		Metaprite_873:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 44 @ plttID
			.4byte 13630 << 5, 1676 << 2 @ .tiles[13630], .subsprites[1676]
		Metaprite_874:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 44 @ plttID
			.4byte 13634 << 5, 1677 << 2 @ .tiles[13634], .subsprites[1677]
		Metaprite_875:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 289 @ plttID
			.4byte 13638 << 5, 1678 << 2 @ .tiles[13638], .subsprites[1678]
		Metaprite_876:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 289 @ plttID
			.4byte 13642 << 5, 1679 << 2 @ .tiles[13642], .subsprites[1679]
		Metaprite_877:
			.byte 3, 11 @ subspriteCount, unk_01
			.2byte 289 @ plttID
			.4byte 13658 << 5, 1680 << 2 @ .tiles[13658], .subsprites[1680]
		Metaprite_878:
			.byte 2, 12 @ subspriteCount, unk_01
			.2byte 289 @ plttID
			.4byte 13669 << 5, 1683 << 2 @ .tiles[13669], .subsprites[1683]
		Metaprite_879:
			.byte 3, 11 @ subspriteCount, unk_01
			.2byte 289 @ plttID
			.4byte 13681 << 5, 1685 << 2 @ .tiles[13681], .subsprites[1685]
		Metaprite_880:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 13692 << 5, 1688 << 2 @ .tiles[13692], .subsprites[1688]
		Metaprite_881:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 13740 << 5, 1691 << 2 @ .tiles[13740], .subsprites[1691]
		Metaprite_882:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 13788 << 5, 1694 << 2 @ .tiles[13788], .subsprites[1694]
		Metaprite_883:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 13836 << 5, 1697 << 2 @ .tiles[13836], .subsprites[1697]
		Metaprite_884:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 13884 << 5, 1700 << 2 @ .tiles[13884], .subsprites[1700]
		Metaprite_885:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 13932 << 5, 1703 << 2 @ .tiles[13932], .subsprites[1703]
		Metaprite_886:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 13980 << 5, 1706 << 2 @ .tiles[13980], .subsprites[1706]
		Metaprite_887:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 14028 << 5, 1709 << 2 @ .tiles[14028], .subsprites[1709]
		Metaprite_888:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 14076 << 5, 1712 << 2 @ .tiles[14076], .subsprites[1712]
		Metaprite_889:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 14124 << 5, 1715 << 2 @ .tiles[14124], .subsprites[1715]
		Metaprite_890:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 14172 << 5, 1718 << 2 @ .tiles[14172], .subsprites[1718]
		Metaprite_891:
			.byte 4, 24 @ subspriteCount, unk_01
			.2byte 300 @ plttID
			.4byte 14220 << 5, 1721 << 2 @ .tiles[14220], .subsprites[1721]
		Metaprite_892:
			.byte 1, 32 @ subspriteCount, unk_01
			.2byte 301 @ plttID
			.4byte 14244 << 5, 1725 << 2 @ .tiles[14244], .subsprites[1725]
		Metaprite_893:
			.byte 1, 32 @ subspriteCount, unk_01
			.2byte 301 @ plttID
			.4byte 14276 << 5, 1726 << 2 @ .tiles[14276], .subsprites[1726]
		Metaprite_894:
			.byte 1, 8 @ subspriteCount, unk_01
			.2byte 301 @ plttID
			.4byte 14308 << 5, 1727 << 2 @ .tiles[14308], .subsprites[1727]
		Metaprite_895:
			.byte 2, 6 @ subspriteCount, unk_01
			.2byte 301 @ plttID
			.4byte 14316 << 5, 1728 << 2 @ .tiles[14316], .subsprites[1728]
		Metaprite_896:
			.byte 1, 8 @ subspriteCount, unk_01
			.2byte 301 @ plttID
			.4byte 14322 << 5, 1730 << 2 @ .tiles[14322], .subsprites[1730]
		Metaprite_897:
			.byte 1, 8 @ subspriteCount, unk_01
			.2byte 301 @ plttID
			.4byte 14330 << 5, 1731 << 2 @ .tiles[14330], .subsprites[1731]
		Metaprite_898:
			.byte 3, 11 @ subspriteCount, unk_01
			.2byte 306 @ plttID
			.4byte 14338 << 5, 1732 << 2 @ .tiles[14338], .subsprites[1732]
		Metaprite_899:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 306 @ plttID
			.4byte 14349 << 5, 1735 << 2 @ .tiles[14349], .subsprites[1735]
		Metaprite_900:
			.byte 3, 11 @ subspriteCount, unk_01
			.2byte 306 @ plttID
			.4byte 14369 << 5, 1737 << 2 @ .tiles[14369], .subsprites[1737]
		Metaprite_901:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 306 @ plttID
			.4byte 14380 << 5, 1740 << 2 @ .tiles[14380], .subsprites[1740]
		Metaprite_902:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 306 @ plttID
			.4byte 14400 << 5, 1742 << 2 @ .tiles[14400], .subsprites[1742]
		Metaprite_903:
			.byte 3, 14 @ subspriteCount, unk_01
			.2byte 306 @ plttID
			.4byte 14412 << 5, 1745 << 2 @ .tiles[14412], .subsprites[1745]
		Metaprite_904:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 306 @ plttID
			.4byte 14426 << 5, 1748 << 2 @ .tiles[14426], .subsprites[1748]
		Metaprite_905:
			.byte 3, 11 @ subspriteCount, unk_01
			.2byte 306 @ plttID
			.4byte 14446 << 5, 1750 << 2 @ .tiles[14446], .subsprites[1750]
		Metaprite_906:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 306 @ plttID
			.4byte 14457 << 5, 1753 << 2 @ .tiles[14457], .subsprites[1753]
		Metaprite_907:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 306 @ plttID
			.4byte 14469 << 5, 1756 << 2 @ .tiles[14469], .subsprites[1756]
		Metaprite_908:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 306 @ plttID
			.4byte 14489 << 5, 1758 << 2 @ .tiles[14489], .subsprites[1758]
		Metaprite_909:
			.byte 3, 11 @ subspriteCount, unk_01
			.2byte 306 @ plttID
			.4byte 14509 << 5, 1760 << 2 @ .tiles[14509], .subsprites[1760]
		Metaprite_910:
			.byte 3, 14 @ subspriteCount, unk_01
			.2byte 306 @ plttID
			.4byte 14520 << 5, 1763 << 2 @ .tiles[14520], .subsprites[1763]
		Metaprite_911:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 306 @ plttID
			.4byte 14534 << 5, 1766 << 2 @ .tiles[14534], .subsprites[1766]
		Metaprite_912:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 306 @ plttID
			.4byte 14546 << 5, 1769 << 2 @ .tiles[14546], .subsprites[1769]
		Metaprite_913:
			.byte 3, 11 @ subspriteCount, unk_01
			.2byte 306 @ plttID
			.4byte 14558 << 5, 1772 << 2 @ .tiles[14558], .subsprites[1772]
		Metaprite_914:
			.byte 2, 12 @ subspriteCount, unk_01
			.2byte 306 @ plttID
			.4byte 14569 << 5, 1775 << 2 @ .tiles[14569], .subsprites[1775]
		Metaprite_915:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 306 @ plttID
			.4byte 14581 << 5, 1777 << 2 @ .tiles[14581], .subsprites[1777]
		Metaprite_916:
			.byte 3, 11 @ subspriteCount, unk_01
			.2byte 306 @ plttID
			.4byte 14601 << 5, 1779 << 2 @ .tiles[14601], .subsprites[1779]
		Metaprite_917:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 306 @ plttID
			.4byte 14612 << 5, 1782 << 2 @ .tiles[14612], .subsprites[1782]
		Metaprite_918:
			.byte 2, 12 @ subspriteCount, unk_01
			.2byte 306 @ plttID
			.4byte 14624 << 5, 1785 << 2 @ .tiles[14624], .subsprites[1785]
		Metaprite_919:
			.byte 2, 12 @ subspriteCount, unk_01
			.2byte 306 @ plttID
			.4byte 14636 << 5, 1787 << 2 @ .tiles[14636], .subsprites[1787]
		Metaprite_920:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 306 @ plttID
			.4byte 14648 << 5, 1789 << 2 @ .tiles[14648], .subsprites[1789]
		Metaprite_921:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 306 @ plttID
			.4byte 14660 << 5, 1792 << 2 @ .tiles[14660], .subsprites[1792]
		Metaprite_922:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 306 @ plttID
			.4byte 14672 << 5, 1795 << 2 @ .tiles[14672], .subsprites[1795]
		Metaprite_923:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 306 @ plttID
			.4byte 14684 << 5, 1798 << 2 @ .tiles[14684], .subsprites[1798]
		Metaprite_924:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 306 @ plttID
			.4byte 14696 << 5, 1801 << 2 @ .tiles[14696], .subsprites[1801]
		Metaprite_925:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 306 @ plttID
			.4byte 14708 << 5, 1804 << 2 @ .tiles[14708], .subsprites[1804]
		Metaprite_926:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 306 @ plttID
			.4byte 14720 << 5, 1807 << 2 @ .tiles[14720], .subsprites[1807]
		Metaprite_927:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 306 @ plttID
			.4byte 14732 << 5, 1810 << 2 @ .tiles[14732], .subsprites[1810]
		Metaprite_928:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 306 @ plttID
			.4byte 14744 << 5, 1813 << 2 @ .tiles[14744], .subsprites[1813]
		Metaprite_929:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 306 @ plttID
			.4byte 14756 << 5, 1816 << 2 @ .tiles[14756], .subsprites[1816]
		Metaprite_930:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 306 @ plttID
			.4byte 14768 << 5, 1819 << 2 @ .tiles[14768], .subsprites[1819]
		Metaprite_931:
			.byte 3, 11 @ subspriteCount, unk_01
			.2byte 306 @ plttID
			.4byte 14780 << 5, 1822 << 2 @ .tiles[14780], .subsprites[1822]
		Metaprite_932:
			.byte 3, 11 @ subspriteCount, unk_01
			.2byte 306 @ plttID
			.4byte 14791 << 5, 1825 << 2 @ .tiles[14791], .subsprites[1825]
		Metaprite_933:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 306 @ plttID
			.4byte 14802 << 5, 1828 << 2 @ .tiles[14802], .subsprites[1828]
		Metaprite_934:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 306 @ plttID
			.4byte 14814 << 5, 1831 << 2 @ .tiles[14814], .subsprites[1831]
		Metaprite_935:
			.byte 3, 11 @ subspriteCount, unk_01
			.2byte 306 @ plttID
			.4byte 14826 << 5, 1834 << 2 @ .tiles[14826], .subsprites[1834]
		Metaprite_936:
			.byte 3, 11 @ subspriteCount, unk_01
			.2byte 306 @ plttID
			.4byte 14837 << 5, 1837 << 2 @ .tiles[14837], .subsprites[1837]
		Metaprite_937:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 306 @ plttID
			.4byte 14848 << 5, 1840 << 2 @ .tiles[14848], .subsprites[1840]
		Metaprite_938:
			.byte 3, 10 @ subspriteCount, unk_01
			.2byte 306 @ plttID
			.4byte 14860 << 5, 1843 << 2 @ .tiles[14860], .subsprites[1843]
		Metaprite_939:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 306 @ plttID
			.4byte 14870 << 5, 1846 << 2 @ .tiles[14870], .subsprites[1846]
		Metaprite_940:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 306 @ plttID
			.4byte 14890 << 5, 1848 << 2 @ .tiles[14890], .subsprites[1848]
		Metaprite_941:
			.byte 3, 11 @ subspriteCount, unk_01
			.2byte 306 @ plttID
			.4byte 14902 << 5, 1851 << 2 @ .tiles[14902], .subsprites[1851]
		Metaprite_942:
			.byte 3, 11 @ subspriteCount, unk_01
			.2byte 306 @ plttID
			.4byte 14913 << 5, 1854 << 2 @ .tiles[14913], .subsprites[1854]
		Metaprite_943:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 306 @ plttID
			.4byte 14924 << 5, 1857 << 2 @ .tiles[14924], .subsprites[1857]
		Metaprite_944:
			.byte 3, 14 @ subspriteCount, unk_01
			.2byte 306 @ plttID
			.4byte 14936 << 5, 1860 << 2 @ .tiles[14936], .subsprites[1860]
		Metaprite_945:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 311 @ plttID
			.4byte 14950 << 5, 1863 << 2 @ .tiles[14950], .subsprites[1863]
		Metaprite_946:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 311 @ plttID
			.4byte 14998 << 5, 1866 << 2 @ .tiles[14998], .subsprites[1866]
		Metaprite_947:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 311 @ plttID
			.4byte 15046 << 5, 1869 << 2 @ .tiles[15046], .subsprites[1869]
		Metaprite_948:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 312 @ plttID
			.4byte 15094 << 5, 1872 << 2 @ .tiles[15094], .subsprites[1872]
		Metaprite_949:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 312 @ plttID
			.4byte 15142 << 5, 1875 << 2 @ .tiles[15142], .subsprites[1875]
		Metaprite_950:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 312 @ plttID
			.4byte 15190 << 5, 1878 << 2 @ .tiles[15190], .subsprites[1878]
		Metaprite_951:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 312 @ plttID
			.4byte 15238 << 5, 1881 << 2 @ .tiles[15238], .subsprites[1881]
		Metaprite_952:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 312 @ plttID
			.4byte 15286 << 5, 1884 << 2 @ .tiles[15286], .subsprites[1884]
		Metaprite_953:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 312 @ plttID
			.4byte 15334 << 5, 1887 << 2 @ .tiles[15334], .subsprites[1887]
		Metaprite_954:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 312 @ plttID
			.4byte 15382 << 5, 1890 << 2 @ .tiles[15382], .subsprites[1890]
		Metaprite_955:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 312 @ plttID
			.4byte 15430 << 5, 1893 << 2 @ .tiles[15430], .subsprites[1893]
		Metaprite_956:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 312 @ plttID
			.4byte 15478 << 5, 1896 << 2 @ .tiles[15478], .subsprites[1896]
		Metaprite_957:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 312 @ plttID
			.4byte 15526 << 5, 1899 << 2 @ .tiles[15526], .subsprites[1899]
		Metaprite_958:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 312 @ plttID
			.4byte 15574 << 5, 1902 << 2 @ .tiles[15574], .subsprites[1902]
		Metaprite_959:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 312 @ plttID
			.4byte 15622 << 5, 1905 << 2 @ .tiles[15622], .subsprites[1905]
		Metaprite_960:
			.byte 3, 24 @ subspriteCount, unk_01
			.2byte 287 @ plttID
			.4byte 15670 << 5, 1908 << 2 @ .tiles[15670], .subsprites[1908]
		Metaprite_961:
			.byte 3, 24 @ subspriteCount, unk_01
			.2byte 287 @ plttID
			.4byte 15694 << 5, 1911 << 2 @ .tiles[15694], .subsprites[1911]
		Metaprite_962:
			.byte 1, 32 @ subspriteCount, unk_01
			.2byte 313 @ plttID
			.4byte 15718 << 5, 1914 << 2 @ .tiles[15718], .subsprites[1914]
		Metaprite_963:
			.byte 3, 24 @ subspriteCount, unk_01
			.2byte 313 @ plttID
			.4byte 15750 << 5, 1915 << 2 @ .tiles[15750], .subsprites[1915]
		Metaprite_964:
			.byte 4, 30 @ subspriteCount, unk_01
			.2byte 313 @ plttID
			.4byte 15774 << 5, 1918 << 2 @ .tiles[15774], .subsprites[1918]
		Metaprite_965:
			.byte 4, 30 @ subspriteCount, unk_01
			.2byte 313 @ plttID
			.4byte 15804 << 5, 1922 << 2 @ .tiles[15804], .subsprites[1922]
		Metaprite_966:
			.byte 3, 40 @ subspriteCount, unk_01
			.2byte 315 @ plttID
			.4byte 15834 << 5, 1926 << 2 @ .tiles[15834], .subsprites[1926]
		Metaprite_967:
			.byte 3, 40 @ subspriteCount, unk_01
			.2byte 315 @ plttID
			.4byte 15874 << 5, 1929 << 2 @ .tiles[15874], .subsprites[1929]
		Metaprite_968:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 316 @ plttID
			.4byte 15914 << 5, 1932 << 2 @ .tiles[15914], .subsprites[1932]
		Metaprite_969:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 316 @ plttID
			.4byte 15918 << 5, 1933 << 2 @ .tiles[15918], .subsprites[1933]
		Metaprite_970:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 316 @ plttID
			.4byte 15922 << 5, 1934 << 2 @ .tiles[15922], .subsprites[1934]
		Metaprite_971:
			.byte 1, 2 @ subspriteCount, unk_01
			.2byte 316 @ plttID
			.4byte 15926 << 5, 1935 << 2 @ .tiles[15926], .subsprites[1935]
		Metaprite_972:
			.byte 1, 2 @ subspriteCount, unk_01
			.2byte 316 @ plttID
			.4byte 15928 << 5, 1936 << 2 @ .tiles[15928], .subsprites[1936]
		Metaprite_973:
			.byte 1, 2 @ subspriteCount, unk_01
			.2byte 316 @ plttID
			.4byte 15930 << 5, 1937 << 2 @ .tiles[15930], .subsprites[1937]
		Metaprite_974:
			.byte 1, 2 @ subspriteCount, unk_01
			.2byte 316 @ plttID
			.4byte 15932 << 5, 1938 << 2 @ .tiles[15932], .subsprites[1938]
		Metaprite_975:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 316 @ plttID
			.4byte 15934 << 5, 1939 << 2 @ .tiles[15934], .subsprites[1939]
		Metaprite_976:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 316 @ plttID
			.4byte 15938 << 5, 1940 << 2 @ .tiles[15938], .subsprites[1940]
		Metaprite_977:
			.byte 3, 22 @ subspriteCount, unk_01
			.2byte 317 @ plttID
			.4byte 15942 << 5, 1941 << 2 @ .tiles[15942], .subsprites[1941]
		Metaprite_978:
			.byte 4, 36 @ subspriteCount, unk_01
			.2byte 326 @ plttID
			.4byte 15964 << 5, 1944 << 2 @ .tiles[15964], .subsprites[1944]
		Metaprite_979:
			.byte 4, 36 @ subspriteCount, unk_01
			.2byte 329 @ plttID
			.4byte 16000 << 5, 1948 << 2 @ .tiles[16000], .subsprites[1948]
		Metaprite_980:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 16036 << 5, 1952 << 2 @ .tiles[16036], .subsprites[1952]
		Metaprite_981:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 16037 << 5, 1953 << 2 @ .tiles[16037], .subsprites[1953]
		Metaprite_982:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 16038 << 5, 1954 << 2 @ .tiles[16038], .subsprites[1954]
		Metaprite_983:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 16039 << 5, 1955 << 2 @ .tiles[16039], .subsprites[1955]
		Metaprite_984:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 16040 << 5, 1956 << 2 @ .tiles[16040], .subsprites[1956]
		Metaprite_985:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 16041 << 5, 1957 << 2 @ .tiles[16041], .subsprites[1957]
		Metaprite_986:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 16042 << 5, 1958 << 2 @ .tiles[16042], .subsprites[1958]
		Metaprite_987:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 16043 << 5, 1959 << 2 @ .tiles[16043], .subsprites[1959]
		Metaprite_988:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 16044 << 5, 1960 << 2 @ .tiles[16044], .subsprites[1960]
		Metaprite_989:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 16045 << 5, 1961 << 2 @ .tiles[16045], .subsprites[1961]
		Metaprite_990:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 0 @ plttID
			.4byte 16046 << 5, 1962 << 2 @ .tiles[16046], .subsprites[1962]
		Metaprite_991:
			.byte 3, 6 @ subspriteCount, unk_01
			.2byte 332 @ plttID
			.4byte 16047 << 5, 1963 << 2 @ .tiles[16047], .subsprites[1963]
		Metaprite_992:
			.byte 2, 5 @ subspriteCount, unk_01
			.2byte 332 @ plttID
			.4byte 16053 << 5, 1966 << 2 @ .tiles[16053], .subsprites[1966]
		Metaprite_993:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 332 @ plttID
			.4byte 16058 << 5, 1968 << 2 @ .tiles[16058], .subsprites[1968]
		Metaprite_994:
			.byte 2, 5 @ subspriteCount, unk_01
			.2byte 332 @ plttID
			.4byte 16074 << 5, 1969 << 2 @ .tiles[16074], .subsprites[1969]
		Metaprite_995:
			.byte 2, 12 @ subspriteCount, unk_01
			.2byte 332 @ plttID
			.4byte 16079 << 5, 1971 << 2 @ .tiles[16079], .subsprites[1971]
		Metaprite_996:
			.byte 2, 6 @ subspriteCount, unk_01
			.2byte 332 @ plttID
			.4byte 16091 << 5, 1973 << 2 @ .tiles[16091], .subsprites[1973]
		Metaprite_997:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 332 @ plttID
			.4byte 16097 << 5, 1975 << 2 @ .tiles[16097], .subsprites[1975]
		Metaprite_998:
			.byte 2, 5 @ subspriteCount, unk_01
			.2byte 332 @ plttID
			.4byte 16113 << 5, 1976 << 2 @ .tiles[16113], .subsprites[1976]
		Metaprite_999:
			.byte 3, 6 @ subspriteCount, unk_01
			.2byte 332 @ plttID
			.4byte 16118 << 5, 1978 << 2 @ .tiles[16118], .subsprites[1978]
		Metaprite_1000:
			.byte 2, 5 @ subspriteCount, unk_01
			.2byte 332 @ plttID
			.4byte 16124 << 5, 1981 << 2 @ .tiles[16124], .subsprites[1981]
		Metaprite_1001:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 332 @ plttID
			.4byte 16129 << 5, 1983 << 2 @ .tiles[16129], .subsprites[1983]
		Metaprite_1002:
			.byte 2, 5 @ subspriteCount, unk_01
			.2byte 332 @ plttID
			.4byte 16145 << 5, 1984 << 2 @ .tiles[16145], .subsprites[1984]
		Metaprite_1003:
			.byte 2, 12 @ subspriteCount, unk_01
			.2byte 332 @ plttID
			.4byte 16150 << 5, 1986 << 2 @ .tiles[16150], .subsprites[1986]
		Metaprite_1004:
			.byte 2, 5 @ subspriteCount, unk_01
			.2byte 332 @ plttID
			.4byte 16162 << 5, 1988 << 2 @ .tiles[16162], .subsprites[1988]
		Metaprite_1005:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 332 @ plttID
			.4byte 16167 << 5, 1990 << 2 @ .tiles[16167], .subsprites[1990]
		Metaprite_1006:
			.byte 2, 5 @ subspriteCount, unk_01
			.2byte 332 @ plttID
			.4byte 16183 << 5, 1991 << 2 @ .tiles[16183], .subsprites[1991]
		Metaprite_1007:
			.byte 1, 8 @ subspriteCount, unk_01
			.2byte 332 @ plttID
			.4byte 16188 << 5, 1993 << 2 @ .tiles[16188], .subsprites[1993]
		Metaprite_1008:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 332 @ plttID
			.4byte 16196 << 5, 1994 << 2 @ .tiles[16196], .subsprites[1994]
		Metaprite_1009:
			.byte 1, 8 @ subspriteCount, unk_01
			.2byte 332 @ plttID
			.4byte 16212 << 5, 1995 << 2 @ .tiles[16212], .subsprites[1995]
		Metaprite_1010:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 332 @ plttID
			.4byte 16220 << 5, 1996 << 2 @ .tiles[16220], .subsprites[1996]
		Metaprite_1011:
			.byte 1, 8 @ subspriteCount, unk_01
			.2byte 332 @ plttID
			.4byte 16236 << 5, 1997 << 2 @ .tiles[16236], .subsprites[1997]
		Metaprite_1012:
			.byte 3, 8 @ subspriteCount, unk_01
			.2byte 332 @ plttID
			.4byte 16244 << 5, 1998 << 2 @ .tiles[16244], .subsprites[1998]
		Metaprite_1013:
			.byte 4, 9 @ subspriteCount, unk_01
			.2byte 332 @ plttID
			.4byte 16252 << 5, 2001 << 2 @ .tiles[16252], .subsprites[2001]
		Metaprite_1014:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 332 @ plttID
			.4byte 16261 << 5, 2005 << 2 @ .tiles[16261], .subsprites[2005]
		Metaprite_1015:
			.byte 2, 5 @ subspriteCount, unk_01
			.2byte 332 @ plttID
			.4byte 16265 << 5, 2006 << 2 @ .tiles[16265], .subsprites[2006]
		Metaprite_1016:
			.byte 3, 7 @ subspriteCount, unk_01
			.2byte 332 @ plttID
			.4byte 16270 << 5, 2008 << 2 @ .tiles[16270], .subsprites[2008]
		Metaprite_1017:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 332 @ plttID
			.4byte 16277 << 5, 2011 << 2 @ .tiles[16277], .subsprites[2011]
		Metaprite_1018:
			.byte 3, 7 @ subspriteCount, unk_01
			.2byte 332 @ plttID
			.4byte 16293 << 5, 2012 << 2 @ .tiles[16293], .subsprites[2012]
		Metaprite_1019:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 332 @ plttID
			.4byte 16300 << 5, 2015 << 2 @ .tiles[16300], .subsprites[2015]
		Metaprite_1020:
			.byte 2, 5 @ subspriteCount, unk_01
			.2byte 332 @ plttID
			.4byte 16304 << 5, 2016 << 2 @ .tiles[16304], .subsprites[2016]
		Metaprite_1021:
			.byte 2, 12 @ subspriteCount, unk_01
			.2byte 332 @ plttID
			.4byte 16309 << 5, 2018 << 2 @ .tiles[16309], .subsprites[2018]
		Metaprite_1022:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 332 @ plttID
			.4byte 16321 << 5, 2020 << 2 @ .tiles[16321], .subsprites[2020]
		Metaprite_1023:
			.byte 2, 5 @ subspriteCount, unk_01
			.2byte 332 @ plttID
			.4byte 16337 << 5, 2021 << 2 @ .tiles[16337], .subsprites[2021]
		Metaprite_1024:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 332 @ plttID
			.4byte 16342 << 5, 2023 << 2 @ .tiles[16342], .subsprites[2023]
		Metaprite_1025:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 332 @ plttID
			.4byte 16346 << 5, 2024 << 2 @ .tiles[16346], .subsprites[2024]
		Metaprite_1026:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 332 @ plttID
			.4byte 16350 << 5, 2025 << 2 @ .tiles[16350], .subsprites[2025]
		Metaprite_1027:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 332 @ plttID
			.4byte 16354 << 5, 2026 << 2 @ .tiles[16354], .subsprites[2026]
		Metaprite_1028:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 332 @ plttID
			.4byte 16358 << 5, 2027 << 2 @ .tiles[16358], .subsprites[2027]
		Metaprite_1029:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 332 @ plttID
			.4byte 16362 << 5, 2028 << 2 @ .tiles[16362], .subsprites[2028]
		Metaprite_1030:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 337 @ plttID
			.4byte 16366 << 5, 2029 << 2 @ .tiles[16366], .subsprites[2029]
		Metaprite_1031:
			.byte 1, 64 @ subspriteCount, unk_01
			.2byte 338 @ plttID
			.4byte 16414 << 5, 2032 << 2 @ .tiles[16414], .subsprites[2032]
		Metaprite_1032:
			.byte 3, 8 @ subspriteCount, unk_01
			.2byte 339 @ plttID
			.4byte 16478 << 5, 2033 << 2 @ .tiles[16478], .subsprites[2033]
		Metaprite_1033:
			.byte 3, 8 @ subspriteCount, unk_01
			.2byte 339 @ plttID
			.4byte 16486 << 5, 2036 << 2 @ .tiles[16486], .subsprites[2036]
		Metaprite_1034:
			.byte 3, 8 @ subspriteCount, unk_01
			.2byte 339 @ plttID
			.4byte 16494 << 5, 2039 << 2 @ .tiles[16494], .subsprites[2039]
		Metaprite_1035:
			.byte 3, 8 @ subspriteCount, unk_01
			.2byte 339 @ plttID
			.4byte 16502 << 5, 2042 << 2 @ .tiles[16502], .subsprites[2042]
		Metaprite_1036:
			.byte 3, 8 @ subspriteCount, unk_01
			.2byte 339 @ plttID
			.4byte 16510 << 5, 2045 << 2 @ .tiles[16510], .subsprites[2045]
		Metaprite_1037:
			.byte 2, 10 @ subspriteCount, unk_01
			.2byte 339 @ plttID
			.4byte 16518 << 5, 2048 << 2 @ .tiles[16518], .subsprites[2048]
		Metaprite_1038:
			.byte 2, 10 @ subspriteCount, unk_01
			.2byte 339 @ plttID
			.4byte 16528 << 5, 2050 << 2 @ .tiles[16528], .subsprites[2050]
		Metaprite_1039:
			.byte 2, 10 @ subspriteCount, unk_01
			.2byte 339 @ plttID
			.4byte 16538 << 5, 2052 << 2 @ .tiles[16538], .subsprites[2052]
		Metaprite_1040:
			.byte 2, 10 @ subspriteCount, unk_01
			.2byte 339 @ plttID
			.4byte 16548 << 5, 2054 << 2 @ .tiles[16548], .subsprites[2054]
		Metaprite_1041:
			.byte 2, 10 @ subspriteCount, unk_01
			.2byte 339 @ plttID
			.4byte 16558 << 5, 2056 << 2 @ .tiles[16558], .subsprites[2056]
		Metaprite_1042:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 340 @ plttID
			.4byte 16568 << 5, 2058 << 2 @ .tiles[16568], .subsprites[2058]
		Metaprite_1043:
			.byte 4, 36 @ subspriteCount, unk_01
			.2byte 341 @ plttID
			.4byte 16616 << 5, 2061 << 2 @ .tiles[16616], .subsprites[2061]
		Metaprite_1044:
			.byte 4, 36 @ subspriteCount, unk_01
			.2byte 341 @ plttID
			.4byte 16652 << 5, 2065 << 2 @ .tiles[16652], .subsprites[2065]
		Metaprite_1045:
			.byte 1, 64 @ subspriteCount, unk_01
			.2byte 341 @ plttID
			.4byte 16688 << 5, 2069 << 2 @ .tiles[16688], .subsprites[2069]
		Metaprite_1046:
			.byte 1, 64 @ subspriteCount, unk_01
			.2byte 341 @ plttID
			.4byte 16752 << 5, 2070 << 2 @ .tiles[16752], .subsprites[2070]
		Metaprite_1047:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 341 @ plttID
			.4byte 16816 << 5, 2071 << 2 @ .tiles[16816], .subsprites[2071]
		Metaprite_1048:
			.byte 2, 10 @ subspriteCount, unk_01
			.2byte 341 @ plttID
			.4byte 16828 << 5, 2074 << 2 @ .tiles[16828], .subsprites[2074]
		Metaprite_1049:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 350 @ plttID
			.4byte 16838 << 5, 2076 << 2 @ .tiles[16838], .subsprites[2076]
		Metaprite_1050:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 350 @ plttID
			.4byte 16842 << 5, 2077 << 2 @ .tiles[16842], .subsprites[2077]
		Metaprite_1051:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 350 @ plttID
			.4byte 16846 << 5, 2078 << 2 @ .tiles[16846], .subsprites[2078]
		Metaprite_1052:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 350 @ plttID
			.4byte 16850 << 5, 2079 << 2 @ .tiles[16850], .subsprites[2079]
		Metaprite_1053:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 350 @ plttID
			.4byte 16854 << 5, 2080 << 2 @ .tiles[16854], .subsprites[2080]
		Metaprite_1054:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 350 @ plttID
			.4byte 16858 << 5, 2081 << 2 @ .tiles[16858], .subsprites[2081]
		Metaprite_1055:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 350 @ plttID
			.4byte 16862 << 5, 2082 << 2 @ .tiles[16862], .subsprites[2082]
		Metaprite_1056:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 350 @ plttID
			.4byte 16866 << 5, 2083 << 2 @ .tiles[16866], .subsprites[2083]
		Metaprite_1057:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 350 @ plttID
			.4byte 16870 << 5, 2084 << 2 @ .tiles[16870], .subsprites[2084]
		Metaprite_1058:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 350 @ plttID
			.4byte 16874 << 5, 2085 << 2 @ .tiles[16874], .subsprites[2085]
		Metaprite_1059:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 350 @ plttID
			.4byte 16878 << 5, 2086 << 2 @ .tiles[16878], .subsprites[2086]
		Metaprite_1060:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 350 @ plttID
			.4byte 16882 << 5, 2087 << 2 @ .tiles[16882], .subsprites[2087]
		Metaprite_1061:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 350 @ plttID
			.4byte 16886 << 5, 2088 << 2 @ .tiles[16886], .subsprites[2088]
		Metaprite_1062:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 350 @ plttID
			.4byte 16890 << 5, 2089 << 2 @ .tiles[16890], .subsprites[2089]
		Metaprite_1063:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 350 @ plttID
			.4byte 16894 << 5, 2090 << 2 @ .tiles[16894], .subsprites[2090]
		Metaprite_1064:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 350 @ plttID
			.4byte 16898 << 5, 2091 << 2 @ .tiles[16898], .subsprites[2091]
		Metaprite_1065:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 350 @ plttID
			.4byte 16902 << 5, 2092 << 2 @ .tiles[16902], .subsprites[2092]
		Metaprite_1066:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 341 @ plttID
			.4byte 16906 << 5, 2093 << 2 @ .tiles[16906], .subsprites[2093]
		Metaprite_1067:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 341 @ plttID
			.4byte 16910 << 5, 2094 << 2 @ .tiles[16910], .subsprites[2094]
		Metaprite_1068:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 341 @ plttID
			.4byte 16914 << 5, 2095 << 2 @ .tiles[16914], .subsprites[2095]
		Metaprite_1069:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 341 @ plttID
			.4byte 16918 << 5, 2096 << 2 @ .tiles[16918], .subsprites[2096]
		Metaprite_1070:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 341 @ plttID
			.4byte 16922 << 5, 2097 << 2 @ .tiles[16922], .subsprites[2097]
		Metaprite_1071:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 341 @ plttID
			.4byte 16926 << 5, 2098 << 2 @ .tiles[16926], .subsprites[2098]
		Metaprite_1072:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 341 @ plttID
			.4byte 16930 << 5, 2099 << 2 @ .tiles[16930], .subsprites[2099]
		Metaprite_1073:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 341 @ plttID
			.4byte 16931 << 5, 2100 << 2 @ .tiles[16931], .subsprites[2100]
		Metaprite_1074:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 341 @ plttID
			.4byte 16932 << 5, 2101 << 2 @ .tiles[16932], .subsprites[2101]
		Metaprite_1075:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 341 @ plttID
			.4byte 16933 << 5, 2102 << 2 @ .tiles[16933], .subsprites[2102]
		Metaprite_1076:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 341 @ plttID
			.4byte 16934 << 5, 2103 << 2 @ .tiles[16934], .subsprites[2103]
		Metaprite_1077:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 341 @ plttID
			.4byte 16935 << 5, 2104 << 2 @ .tiles[16935], .subsprites[2104]
		Metaprite_1078:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 341 @ plttID
			.4byte 16936 << 5, 2105 << 2 @ .tiles[16936], .subsprites[2105]
		Metaprite_1079:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 16937 << 5, 2106 << 2 @ .tiles[16937], .subsprites[2106]
		Metaprite_1080:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 16985 << 5, 2109 << 2 @ .tiles[16985], .subsprites[2109]
		Metaprite_1081:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 17033 << 5, 2112 << 2 @ .tiles[17033], .subsprites[2112]
		Metaprite_1082:
			.byte 4, 30 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 17081 << 5, 2115 << 2 @ .tiles[17081], .subsprites[2115]
		Metaprite_1083:
			.byte 4, 30 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 17111 << 5, 2119 << 2 @ .tiles[17111], .subsprites[2119]
		Metaprite_1084:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 17141 << 5, 2123 << 2 @ .tiles[17141], .subsprites[2123]
		Metaprite_1085:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 17189 << 5, 2126 << 2 @ .tiles[17189], .subsprites[2126]
		Metaprite_1086:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 17237 << 5, 2129 << 2 @ .tiles[17237], .subsprites[2129]
		Metaprite_1087:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 17285 << 5, 2132 << 2 @ .tiles[17285], .subsprites[2132]
		Metaprite_1088:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 17333 << 5, 2135 << 2 @ .tiles[17333], .subsprites[2135]
		Metaprite_1089:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 17334 << 5, 2136 << 2 @ .tiles[17334], .subsprites[2136]
		Metaprite_1090:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 17382 << 5, 2139 << 2 @ .tiles[17382], .subsprites[2139]
		Metaprite_1091:
			.byte 2, 2 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 17430 << 5, 2142 << 2 @ .tiles[17430], .subsprites[2142]
		Metaprite_1092:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 17432 << 5, 2144 << 2 @ .tiles[17432], .subsprites[2144]
		Metaprite_1093:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 17480 << 5, 2147 << 2 @ .tiles[17480], .subsprites[2147]
		Metaprite_1094:
			.byte 4, 30 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 17528 << 5, 2150 << 2 @ .tiles[17528], .subsprites[2150]
		Metaprite_1095:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 17558 << 5, 2154 << 2 @ .tiles[17558], .subsprites[2154]
		Metaprite_1096:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 17606 << 5, 2157 << 2 @ .tiles[17606], .subsprites[2157]
		Metaprite_1097:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 17654 << 5, 2160 << 2 @ .tiles[17654], .subsprites[2160]
		Metaprite_1098:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 17702 << 5, 2163 << 2 @ .tiles[17702], .subsprites[2163]
		Metaprite_1099:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 17750 << 5, 2166 << 2 @ .tiles[17750], .subsprites[2166]
		Metaprite_1100:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 17798 << 5, 2169 << 2 @ .tiles[17798], .subsprites[2169]
		Metaprite_1101:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 17846 << 5, 2172 << 2 @ .tiles[17846], .subsprites[2172]
		Metaprite_1102:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 17894 << 5, 2175 << 2 @ .tiles[17894], .subsprites[2175]
		Metaprite_1103:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 17942 << 5, 2178 << 2 @ .tiles[17942], .subsprites[2178]
		Metaprite_1104:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 17990 << 5, 2181 << 2 @ .tiles[17990], .subsprites[2181]
		Metaprite_1105:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 18038 << 5, 2184 << 2 @ .tiles[18038], .subsprites[2184]
		Metaprite_1106:
			.byte 1, 8 @ subspriteCount, unk_01
			.2byte 361 @ plttID
			.4byte 18086 << 5, 2187 << 2 @ .tiles[18086], .subsprites[2187]
		Metaprite_1107:
			.byte 1, 8 @ subspriteCount, unk_01
			.2byte 361 @ plttID
			.4byte 18094 << 5, 2188 << 2 @ .tiles[18094], .subsprites[2188]
		Metaprite_1108:
			.byte 1, 8 @ subspriteCount, unk_01
			.2byte 361 @ plttID
			.4byte 18102 << 5, 2189 << 2 @ .tiles[18102], .subsprites[2189]
		Metaprite_1109:
			.byte 1, 8 @ subspriteCount, unk_01
			.2byte 361 @ plttID
			.4byte 18110 << 5, 2190 << 2 @ .tiles[18110], .subsprites[2190]
		Metaprite_1110:
			.byte 3, 8 @ subspriteCount, unk_01
			.2byte 287 @ plttID
			.4byte 18118 << 5, 2191 << 2 @ .tiles[18118], .subsprites[2191]
		Metaprite_1111:
			.byte 3, 8 @ subspriteCount, unk_01
			.2byte 287 @ plttID
			.4byte 18126 << 5, 2194 << 2 @ .tiles[18126], .subsprites[2194]
		Metaprite_1112:
			.byte 1, 64 @ subspriteCount, unk_01
			.2byte 363 @ plttID
			.4byte 18134 << 5, 2197 << 2 @ .tiles[18134], .subsprites[2197]
		Metaprite_1113:
			.byte 2, 6 @ subspriteCount, unk_01
			.2byte 379 @ plttID
			.4byte 18198 << 5, 2198 << 2 @ .tiles[18198], .subsprites[2198]
		Metaprite_1114:
			.byte 2, 6 @ subspriteCount, unk_01
			.2byte 379 @ plttID
			.4byte 18204 << 5, 2200 << 2 @ .tiles[18204], .subsprites[2200]
		Metaprite_1115:
			.byte 2, 6 @ subspriteCount, unk_01
			.2byte 379 @ plttID
			.4byte 18210 << 5, 2202 << 2 @ .tiles[18210], .subsprites[2202]
		Metaprite_1116:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 380 @ plttID
			.4byte 18216 << 5, 2204 << 2 @ .tiles[18216], .subsprites[2204]
		Metaprite_1117:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 380 @ plttID
			.4byte 18220 << 5, 2205 << 2 @ .tiles[18220], .subsprites[2205]
		Metaprite_1118:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 380 @ plttID
			.4byte 18236 << 5, 2206 << 2 @ .tiles[18236], .subsprites[2206]
		Metaprite_1119:
			.byte 3, 19 @ subspriteCount, unk_01
			.2byte 380 @ plttID
			.4byte 18252 << 5, 2207 << 2 @ .tiles[18252], .subsprites[2207]
		Metaprite_1120:
			.byte 3, 10 @ subspriteCount, unk_01
			.2byte 381 @ plttID
			.4byte 18271 << 5, 2210 << 2 @ .tiles[18271], .subsprites[2210]
		Metaprite_1121:
			.byte 3, 10 @ subspriteCount, unk_01
			.2byte 381 @ plttID
			.4byte 18281 << 5, 2213 << 2 @ .tiles[18281], .subsprites[2213]
		Metaprite_1122:
			.byte 3, 10 @ subspriteCount, unk_01
			.2byte 381 @ plttID
			.4byte 18291 << 5, 2216 << 2 @ .tiles[18291], .subsprites[2216]
		Metaprite_1123:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 381 @ plttID
			.4byte 18301 << 5, 2219 << 2 @ .tiles[18301], .subsprites[2219]
		Metaprite_1124:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 381 @ plttID
			.4byte 18317 << 5, 2220 << 2 @ .tiles[18317], .subsprites[2220]
		Metaprite_1125:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 381 @ plttID
			.4byte 18333 << 5, 2221 << 2 @ .tiles[18333], .subsprites[2221]
		Metaprite_1126:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 381 @ plttID
			.4byte 18349 << 5, 2222 << 2 @ .tiles[18349], .subsprites[2222]
		Metaprite_1127:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 381 @ plttID
			.4byte 18361 << 5, 2225 << 2 @ .tiles[18361], .subsprites[2225]
		Metaprite_1128:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 381 @ plttID
			.4byte 18373 << 5, 2228 << 2 @ .tiles[18373], .subsprites[2228]
		Metaprite_1129:
			.byte 3, 10 @ subspriteCount, unk_01
			.2byte 381 @ plttID
			.4byte 18385 << 5, 2231 << 2 @ .tiles[18385], .subsprites[2231]
		Metaprite_1130:
			.byte 3, 11 @ subspriteCount, unk_01
			.2byte 381 @ plttID
			.4byte 18395 << 5, 2234 << 2 @ .tiles[18395], .subsprites[2234]
		Metaprite_1131:
			.byte 3, 11 @ subspriteCount, unk_01
			.2byte 381 @ plttID
			.4byte 18406 << 5, 2237 << 2 @ .tiles[18406], .subsprites[2237]
		Metaprite_1132:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 381 @ plttID
			.4byte 18417 << 5, 2240 << 2 @ .tiles[18417], .subsprites[2240]
		Metaprite_1133:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 381 @ plttID
			.4byte 18429 << 5, 2243 << 2 @ .tiles[18429], .subsprites[2243]
		Metaprite_1134:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 381 @ plttID
			.4byte 18441 << 5, 2246 << 2 @ .tiles[18441], .subsprites[2246]
		Metaprite_1135:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 381 @ plttID
			.4byte 18453 << 5, 2249 << 2 @ .tiles[18453], .subsprites[2249]
		Metaprite_1136:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 381 @ plttID
			.4byte 18469 << 5, 2250 << 2 @ .tiles[18469], .subsprites[2250]
		Metaprite_1137:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 381 @ plttID
			.4byte 18485 << 5, 2251 << 2 @ .tiles[18485], .subsprites[2251]
		Metaprite_1138:
			.byte 3, 14 @ subspriteCount, unk_01
			.2byte 381 @ plttID
			.4byte 18501 << 5, 2252 << 2 @ .tiles[18501], .subsprites[2252]
		Metaprite_1139:
			.byte 2, 10 @ subspriteCount, unk_01
			.2byte 381 @ plttID
			.4byte 18515 << 5, 2255 << 2 @ .tiles[18515], .subsprites[2255]
		Metaprite_1140:
			.byte 2, 10 @ subspriteCount, unk_01
			.2byte 381 @ plttID
			.4byte 18525 << 5, 2257 << 2 @ .tiles[18525], .subsprites[2257]
		Metaprite_1141:
			.byte 2, 9 @ subspriteCount, unk_01
			.2byte 381 @ plttID
			.4byte 18535 << 5, 2259 << 2 @ .tiles[18535], .subsprites[2259]
		Metaprite_1142:
			.byte 3, 7 @ subspriteCount, unk_01
			.2byte 381 @ plttID
			.4byte 18544 << 5, 2261 << 2 @ .tiles[18544], .subsprites[2261]
		Metaprite_1143:
			.byte 3, 6 @ subspriteCount, unk_01
			.2byte 381 @ plttID
			.4byte 18551 << 5, 2264 << 2 @ .tiles[18551], .subsprites[2264]
		Metaprite_1144:
			.byte 2, 9 @ subspriteCount, unk_01
			.2byte 381 @ plttID
			.4byte 18557 << 5, 2267 << 2 @ .tiles[18557], .subsprites[2267]
		Metaprite_1145:
			.byte 2, 9 @ subspriteCount, unk_01
			.2byte 381 @ plttID
			.4byte 18566 << 5, 2269 << 2 @ .tiles[18566], .subsprites[2269]
		Metaprite_1146:
			.byte 2, 9 @ subspriteCount, unk_01
			.2byte 381 @ plttID
			.4byte 18575 << 5, 2271 << 2 @ .tiles[18575], .subsprites[2271]
		Metaprite_1147:
			.byte 3, 7 @ subspriteCount, unk_01
			.2byte 381 @ plttID
			.4byte 18584 << 5, 2273 << 2 @ .tiles[18584], .subsprites[2273]
		Metaprite_1148:
			.byte 3, 6 @ subspriteCount, unk_01
			.2byte 381 @ plttID
			.4byte 18591 << 5, 2276 << 2 @ .tiles[18591], .subsprites[2276]
		Metaprite_1149:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 386 @ plttID
			.4byte 18597 << 5, 2279 << 2 @ .tiles[18597], .subsprites[2279]
		Metaprite_1150:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 386 @ plttID
			.4byte 18598 << 5, 2280 << 2 @ .tiles[18598], .subsprites[2280]
		Metaprite_1151:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 386 @ plttID
			.4byte 18599 << 5, 2281 << 2 @ .tiles[18599], .subsprites[2281]
		Metaprite_1152:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 386 @ plttID
			.4byte 18600 << 5, 2282 << 2 @ .tiles[18600], .subsprites[2282]
		Metaprite_1153:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 386 @ plttID
			.4byte 18601 << 5, 2283 << 2 @ .tiles[18601], .subsprites[2283]
		Metaprite_1154:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 387 @ plttID
			.4byte 18602 << 5, 2284 << 2 @ .tiles[18602], .subsprites[2284]
		Metaprite_1155:
			.byte 3, 32 @ subspriteCount, unk_01
			.2byte 387 @ plttID
			.4byte 18650 << 5, 2287 << 2 @ .tiles[18650], .subsprites[2287]
		Metaprite_1156:
			.byte 4, 36 @ subspriteCount, unk_01
			.2byte 387 @ plttID
			.4byte 18682 << 5, 2290 << 2 @ .tiles[18682], .subsprites[2290]
		Metaprite_1157:
			.byte 1, 64 @ subspriteCount, unk_01
			.2byte 387 @ plttID
			.4byte 18718 << 5, 2294 << 2 @ .tiles[18718], .subsprites[2294]
		Metaprite_1158:
			.byte 3, 10 @ subspriteCount, unk_01
			.2byte 388 @ plttID
			.4byte 18782 << 5, 2295 << 2 @ .tiles[18782], .subsprites[2295]
		Metaprite_1159:
			.byte 2, 9 @ subspriteCount, unk_01
			.2byte 181 @ plttID
			.4byte 18792 << 5, 2298 << 2 @ .tiles[18792], .subsprites[2298]
		Metaprite_1160:
			.byte 1, 64 @ subspriteCount, unk_01
			.2byte 392 @ plttID
			.4byte 18801 << 5, 2300 << 2 @ .tiles[18801], .subsprites[2300]
		Metaprite_1161:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 18865 << 5, 2301 << 2 @ .tiles[18865], .subsprites[2301]
		Metaprite_1162:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 18913 << 5, 2304 << 2 @ .tiles[18913], .subsprites[2304]
		Metaprite_1163:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 18961 << 5, 2307 << 2 @ .tiles[18961], .subsprites[2307]
		Metaprite_1164:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 19009 << 5, 2310 << 2 @ .tiles[19009], .subsprites[2310]
		Metaprite_1165:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 19057 << 5, 2313 << 2 @ .tiles[19057], .subsprites[2313]
		Metaprite_1166:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 19105 << 5, 2316 << 2 @ .tiles[19105], .subsprites[2316]
		Metaprite_1167:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 19153 << 5, 2319 << 2 @ .tiles[19153], .subsprites[2319]
		Metaprite_1168:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 19201 << 5, 2322 << 2 @ .tiles[19201], .subsprites[2322]
		Metaprite_1169:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 19249 << 5, 2325 << 2 @ .tiles[19249], .subsprites[2325]
		Metaprite_1170:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 19297 << 5, 2328 << 2 @ .tiles[19297], .subsprites[2328]
		Metaprite_1171:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 19345 << 5, 2331 << 2 @ .tiles[19345], .subsprites[2331]
		Metaprite_1172:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 19393 << 5, 2334 << 2 @ .tiles[19393], .subsprites[2334]
		Metaprite_1173:
			.byte 1, 64 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 19441 << 5, 2337 << 2 @ .tiles[19441], .subsprites[2337]
		Metaprite_1174:
			.byte 1, 64 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 19505 << 5, 2338 << 2 @ .tiles[19505], .subsprites[2338]
		Metaprite_1175:
			.byte 2, 17 @ subspriteCount, unk_01
			.2byte 404 @ plttID
			.4byte 19569 << 5, 2339 << 2 @ .tiles[19569], .subsprites[2339]
		Metaprite_1176:
			.byte 3, 24 @ subspriteCount, unk_01
			.2byte 404 @ plttID
			.4byte 19586 << 5, 2341 << 2 @ .tiles[19586], .subsprites[2341]
		Metaprite_1177:
			.byte 3, 28 @ subspriteCount, unk_01
			.2byte 287 @ plttID
			.4byte 19610 << 5, 2344 << 2 @ .tiles[19610], .subsprites[2344]
		Metaprite_1178:
			.byte 3, 28 @ subspriteCount, unk_01
			.2byte 287 @ plttID
			.4byte 19638 << 5, 2347 << 2 @ .tiles[19638], .subsprites[2347]
		Metaprite_1179:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 410 @ plttID
			.4byte 19666 << 5, 2350 << 2 @ .tiles[19666], .subsprites[2350]
		Metaprite_1180:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 410 @ plttID
			.4byte 19682 << 5, 2351 << 2 @ .tiles[19682], .subsprites[2351]
		Metaprite_1181:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 410 @ plttID
			.4byte 19698 << 5, 2352 << 2 @ .tiles[19698], .subsprites[2352]
		Metaprite_1182:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 410 @ plttID
			.4byte 19714 << 5, 2353 << 2 @ .tiles[19714], .subsprites[2353]
		Metaprite_1183:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 410 @ plttID
			.4byte 19730 << 5, 2354 << 2 @ .tiles[19730], .subsprites[2354]
		Metaprite_1184:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 410 @ plttID
			.4byte 19746 << 5, 2355 << 2 @ .tiles[19746], .subsprites[2355]
		Metaprite_1185:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 410 @ plttID
			.4byte 19762 << 5, 2356 << 2 @ .tiles[19762], .subsprites[2356]
		Metaprite_1186:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 410 @ plttID
			.4byte 19778 << 5, 2357 << 2 @ .tiles[19778], .subsprites[2357]
		Metaprite_1187:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 410 @ plttID
			.4byte 19794 << 5, 2358 << 2 @ .tiles[19794], .subsprites[2358]
		Metaprite_1188:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 410 @ plttID
			.4byte 19810 << 5, 2359 << 2 @ .tiles[19810], .subsprites[2359]
		Metaprite_1189:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 410 @ plttID
			.4byte 19826 << 5, 2360 << 2 @ .tiles[19826], .subsprites[2360]
		Metaprite_1190:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 410 @ plttID
			.4byte 19842 << 5, 2361 << 2 @ .tiles[19842], .subsprites[2361]
		Metaprite_1191:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 410 @ plttID
			.4byte 19858 << 5, 2362 << 2 @ .tiles[19858], .subsprites[2362]
		Metaprite_1192:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 410 @ plttID
			.4byte 19874 << 5, 2363 << 2 @ .tiles[19874], .subsprites[2363]
		Metaprite_1193:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 410 @ plttID
			.4byte 19890 << 5, 2364 << 2 @ .tiles[19890], .subsprites[2364]
		Metaprite_1194:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 410 @ plttID
			.4byte 19906 << 5, 2365 << 2 @ .tiles[19906], .subsprites[2365]
		Metaprite_1195:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 19922 << 5, 2366 << 2 @ .tiles[19922], .subsprites[2366]
		Metaprite_1196:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 19970 << 5, 2369 << 2 @ .tiles[19970], .subsprites[2369]
		Metaprite_1197:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 20018 << 5, 2372 << 2 @ .tiles[20018], .subsprites[2372]
		Metaprite_1198:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 20066 << 5, 2375 << 2 @ .tiles[20066], .subsprites[2375]
		Metaprite_1199:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 20114 << 5, 2378 << 2 @ .tiles[20114], .subsprites[2378]
		Metaprite_1200:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 20162 << 5, 2381 << 2 @ .tiles[20162], .subsprites[2381]
		Metaprite_1201:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 20210 << 5, 2384 << 2 @ .tiles[20210], .subsprites[2384]
		Metaprite_1202:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 20258 << 5, 2387 << 2 @ .tiles[20258], .subsprites[2387]
		Metaprite_1203:
			.byte 4, 36 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 20306 << 5, 2390 << 2 @ .tiles[20306], .subsprites[2390]
		Metaprite_1204:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 20342 << 5, 2394 << 2 @ .tiles[20342], .subsprites[2394]
		Metaprite_1205:
			.byte 4, 36 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 20390 << 5, 2397 << 2 @ .tiles[20390], .subsprites[2397]
		Metaprite_1206:
			.byte 2, 40 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 20426 << 5, 2401 << 2 @ .tiles[20426], .subsprites[2401]
		Metaprite_1207:
			.byte 2, 36 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 20466 << 5, 2403 << 2 @ .tiles[20466], .subsprites[2403]
		Metaprite_1208:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 20502 << 5, 2405 << 2 @ .tiles[20502], .subsprites[2405]
		Metaprite_1209:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 20503 << 5, 2406 << 2 @ .tiles[20503], .subsprites[2406]
		Metaprite_1210:
			.byte 2, 40 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 20551 << 5, 2409 << 2 @ .tiles[20551], .subsprites[2409]
		Metaprite_1211:
			.byte 2, 36 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 20591 << 5, 2411 << 2 @ .tiles[20591], .subsprites[2411]
		Metaprite_1212:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 20627 << 5, 2413 << 2 @ .tiles[20627], .subsprites[2413]
		Metaprite_1213:
			.byte 3, 14 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 20675 << 5, 2416 << 2 @ .tiles[20675], .subsprites[2416]
		Metaprite_1214:
			.byte 3, 14 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 20689 << 5, 2419 << 2 @ .tiles[20689], .subsprites[2419]
		Metaprite_1215:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 20703 << 5, 2422 << 2 @ .tiles[20703], .subsprites[2422]
		Metaprite_1216:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 20719 << 5, 2423 << 2 @ .tiles[20719], .subsprites[2423]
		Metaprite_1217:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 20735 << 5, 2424 << 2 @ .tiles[20735], .subsprites[2424]
		Metaprite_1218:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 20751 << 5, 2425 << 2 @ .tiles[20751], .subsprites[2425]
		Metaprite_1219:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 20767 << 5, 2426 << 2 @ .tiles[20767], .subsprites[2426]
		Metaprite_1220:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 20783 << 5, 2427 << 2 @ .tiles[20783], .subsprites[2427]
		Metaprite_1221:
			.byte 3, 14 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 20799 << 5, 2428 << 2 @ .tiles[20799], .subsprites[2428]
		Metaprite_1222:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 20813 << 5, 2431 << 2 @ .tiles[20813], .subsprites[2431]
		Metaprite_1223:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 20829 << 5, 2432 << 2 @ .tiles[20829], .subsprites[2432]
		Metaprite_1224:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 20845 << 5, 2433 << 2 @ .tiles[20845], .subsprites[2433]
		Metaprite_1225:
			.byte 3, 14 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 20861 << 5, 2434 << 2 @ .tiles[20861], .subsprites[2434]
		Metaprite_1226:
			.byte 3, 14 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 20875 << 5, 2437 << 2 @ .tiles[20875], .subsprites[2437]
		Metaprite_1227:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 20889 << 5, 2440 << 2 @ .tiles[20889], .subsprites[2440]
		Metaprite_1228:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 20905 << 5, 2441 << 2 @ .tiles[20905], .subsprites[2441]
		Metaprite_1229:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 20921 << 5, 2442 << 2 @ .tiles[20921], .subsprites[2442]
		Metaprite_1230:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 20933 << 5, 2445 << 2 @ .tiles[20933], .subsprites[2445]
		Metaprite_1231:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 20949 << 5, 2446 << 2 @ .tiles[20949], .subsprites[2446]
		Metaprite_1232:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 20961 << 5, 2449 << 2 @ .tiles[20961], .subsprites[2449]
		Metaprite_1233:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 20977 << 5, 2450 << 2 @ .tiles[20977], .subsprites[2450]
		Metaprite_1234:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 20993 << 5, 2451 << 2 @ .tiles[20993], .subsprites[2451]
		Metaprite_1235:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 21009 << 5, 2452 << 2 @ .tiles[21009], .subsprites[2452]
		Metaprite_1236:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 21021 << 5, 2455 << 2 @ .tiles[21021], .subsprites[2455]
		Metaprite_1237:
			.byte 2, 6 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 21037 << 5, 2456 << 2 @ .tiles[21037], .subsprites[2456]
		Metaprite_1238:
			.byte 3, 7 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 21043 << 5, 2458 << 2 @ .tiles[21043], .subsprites[2458]
		Metaprite_1239:
			.byte 2, 6 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 21050 << 5, 2461 << 2 @ .tiles[21050], .subsprites[2461]
		Metaprite_1240:
			.byte 3, 8 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 21056 << 5, 2463 << 2 @ .tiles[21056], .subsprites[2463]
		Metaprite_1241:
			.byte 2, 6 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 21064 << 5, 2466 << 2 @ .tiles[21064], .subsprites[2466]
		Metaprite_1242:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 21070 << 5, 2468 << 2 @ .tiles[21070], .subsprites[2468]
		Metaprite_1243:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 21086 << 5, 2469 << 2 @ .tiles[21086], .subsprites[2469]
		Metaprite_1244:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 21102 << 5, 2470 << 2 @ .tiles[21102], .subsprites[2470]
		Metaprite_1245:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 21118 << 5, 2471 << 2 @ .tiles[21118], .subsprites[2471]
		Metaprite_1246:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 21134 << 5, 2472 << 2 @ .tiles[21134], .subsprites[2472]
		Metaprite_1247:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 21150 << 5, 2473 << 2 @ .tiles[21150], .subsprites[2473]
		Metaprite_1248:
			.byte 3, 14 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 21166 << 5, 2474 << 2 @ .tiles[21166], .subsprites[2474]
		Metaprite_1249:
			.byte 3, 14 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 21180 << 5, 2477 << 2 @ .tiles[21180], .subsprites[2477]
		Metaprite_1250:
			.byte 3, 14 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 21194 << 5, 2480 << 2 @ .tiles[21194], .subsprites[2480]
		Metaprite_1251:
			.byte 3, 8 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 21208 << 5, 2483 << 2 @ .tiles[21208], .subsprites[2483]
		Metaprite_1252:
			.byte 3, 8 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 21216 << 5, 2486 << 2 @ .tiles[21216], .subsprites[2486]
		Metaprite_1253:
			.byte 3, 8 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 21224 << 5, 2489 << 2 @ .tiles[21224], .subsprites[2489]
		Metaprite_1254:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 21232 << 5, 2492 << 2 @ .tiles[21232], .subsprites[2492]
		Metaprite_1255:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 21244 << 5, 2495 << 2 @ .tiles[21244], .subsprites[2495]
		Metaprite_1256:
			.byte 3, 14 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 21260 << 5, 2496 << 2 @ .tiles[21260], .subsprites[2496]
		Metaprite_1257:
			.byte 3, 22 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 21274 << 5, 2499 << 2 @ .tiles[21274], .subsprites[2499]
		Metaprite_1258:
			.byte 3, 22 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 21296 << 5, 2502 << 2 @ .tiles[21296], .subsprites[2502]
		Metaprite_1259:
			.byte 3, 21 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 21318 << 5, 2505 << 2 @ .tiles[21318], .subsprites[2505]
		Metaprite_1260:
			.byte 3, 19 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 21339 << 5, 2508 << 2 @ .tiles[21339], .subsprites[2508]
		Metaprite_1261:
			.byte 2, 18 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 21358 << 5, 2511 << 2 @ .tiles[21358], .subsprites[2511]
		Metaprite_1262:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 21376 << 5, 2513 << 2 @ .tiles[21376], .subsprites[2513]
		Metaprite_1263:
			.byte 4, 30 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 21424 << 5, 2516 << 2 @ .tiles[21424], .subsprites[2516]
		Metaprite_1264:
			.byte 4, 36 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 21454 << 5, 2520 << 2 @ .tiles[21454], .subsprites[2520]
		Metaprite_1265:
			.byte 3, 19 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 21490 << 5, 2524 << 2 @ .tiles[21490], .subsprites[2524]
		Metaprite_1266:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 21509 << 5, 2527 << 2 @ .tiles[21509], .subsprites[2527]
		Metaprite_1267:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 21533 << 5, 2529 << 2 @ .tiles[21533], .subsprites[2529]
		Metaprite_1268:
			.byte 3, 24 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 21557 << 5, 2531 << 2 @ .tiles[21557], .subsprites[2531]
		Metaprite_1269:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 21581 << 5, 2534 << 2 @ .tiles[21581], .subsprites[2534]
		Metaprite_1270:
			.byte 3, 24 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 21605 << 5, 2536 << 2 @ .tiles[21605], .subsprites[2536]
		Metaprite_1271:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 21629 << 5, 2539 << 2 @ .tiles[21629], .subsprites[2539]
		Metaprite_1272:
			.byte 3, 22 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 21653 << 5, 2541 << 2 @ .tiles[21653], .subsprites[2541]
		Metaprite_1273:
			.byte 3, 22 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 21675 << 5, 2544 << 2 @ .tiles[21675], .subsprites[2544]
		Metaprite_1274:
			.byte 3, 22 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 21697 << 5, 2547 << 2 @ .tiles[21697], .subsprites[2547]
		Metaprite_1275:
			.byte 2, 18 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 21719 << 5, 2550 << 2 @ .tiles[21719], .subsprites[2550]
		Metaprite_1276:
			.byte 2, 18 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 21737 << 5, 2552 << 2 @ .tiles[21737], .subsprites[2552]
		Metaprite_1277:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 21755 << 5, 2554 << 2 @ .tiles[21755], .subsprites[2554]
		Metaprite_1278:
			.byte 3, 40 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 21803 << 5, 2557 << 2 @ .tiles[21803], .subsprites[2557]
		Metaprite_1279:
			.byte 4, 36 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 21843 << 5, 2560 << 2 @ .tiles[21843], .subsprites[2560]
		Metaprite_1280:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 21879 << 5, 2564 << 2 @ .tiles[21879], .subsprites[2564]
		Metaprite_1281:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 21903 << 5, 2566 << 2 @ .tiles[21903], .subsprites[2566]
		Metaprite_1282:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 21927 << 5, 2568 << 2 @ .tiles[21927], .subsprites[2568]
		Metaprite_1283:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 21931 << 5, 2569 << 2 @ .tiles[21931], .subsprites[2569]
		Metaprite_1284:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 21935 << 5, 2570 << 2 @ .tiles[21935], .subsprites[2570]
		Metaprite_1285:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 21939 << 5, 2571 << 2 @ .tiles[21939], .subsprites[2571]
		Metaprite_1286:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 21943 << 5, 2572 << 2 @ .tiles[21943], .subsprites[2572]
		Metaprite_1287:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 21947 << 5, 2573 << 2 @ .tiles[21947], .subsprites[2573]
		Metaprite_1288:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 21951 << 5, 2574 << 2 @ .tiles[21951], .subsprites[2574]
		Metaprite_1289:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 21955 << 5, 2575 << 2 @ .tiles[21955], .subsprites[2575]
		Metaprite_1290:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 21959 << 5, 2576 << 2 @ .tiles[21959], .subsprites[2576]
		Metaprite_1291:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 21963 << 5, 2577 << 2 @ .tiles[21963], .subsprites[2577]
		Metaprite_1292:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 21967 << 5, 2578 << 2 @ .tiles[21967], .subsprites[2578]
		Metaprite_1293:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 21971 << 5, 2579 << 2 @ .tiles[21971], .subsprites[2579]
		Metaprite_1294:
			.byte 2, 10 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 21975 << 5, 2580 << 2 @ .tiles[21975], .subsprites[2580]
		Metaprite_1295:
			.byte 2, 10 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 21985 << 5, 2582 << 2 @ .tiles[21985], .subsprites[2582]
		Metaprite_1296:
			.byte 2, 9 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 21995 << 5, 2584 << 2 @ .tiles[21995], .subsprites[2584]
		Metaprite_1297:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 22004 << 5, 2586 << 2 @ .tiles[22004], .subsprites[2586]
		Metaprite_1298:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 22020 << 5, 2587 << 2 @ .tiles[22020], .subsprites[2587]
		Metaprite_1299:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 22036 << 5, 2588 << 2 @ .tiles[22036], .subsprites[2588]
		Metaprite_1300:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 22048 << 5, 2591 << 2 @ .tiles[22048], .subsprites[2591]
		Metaprite_1301:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 22060 << 5, 2594 << 2 @ .tiles[22060], .subsprites[2594]
		Metaprite_1302:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 22072 << 5, 2597 << 2 @ .tiles[22072], .subsprites[2597]
		Metaprite_1303:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 22088 << 5, 2598 << 2 @ .tiles[22088], .subsprites[2598]
		Metaprite_1304:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 22100 << 5, 2601 << 2 @ .tiles[22100], .subsprites[2601]
		Metaprite_1305:
			.byte 3, 11 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 22116 << 5, 2602 << 2 @ .tiles[22116], .subsprites[2602]
		Metaprite_1306:
			.byte 3, 11 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 22127 << 5, 2605 << 2 @ .tiles[22127], .subsprites[2605]
		Metaprite_1307:
			.byte 3, 11 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 22138 << 5, 2608 << 2 @ .tiles[22138], .subsprites[2608]
		Metaprite_1308:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 417 @ plttID
			.4byte 22149 << 5, 2611 << 2 @ .tiles[22149], .subsprites[2611]
		Metaprite_1309:
			.byte 2, 6 @ subspriteCount, unk_01
			.2byte 29 @ plttID
			.4byte 22165 << 5, 2612 << 2 @ .tiles[22165], .subsprites[2612]
		Metaprite_1310:
			.byte 2, 5 @ subspriteCount, unk_01
			.2byte 29 @ plttID
			.4byte 22171 << 5, 2614 << 2 @ .tiles[22171], .subsprites[2614]
		Metaprite_1311:
			.byte 2, 5 @ subspriteCount, unk_01
			.2byte 29 @ plttID
			.4byte 22176 << 5, 2616 << 2 @ .tiles[22176], .subsprites[2616]
		Metaprite_1312:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 29 @ plttID
			.4byte 22181 << 5, 2618 << 2 @ .tiles[22181], .subsprites[2618]
		Metaprite_1313:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 29 @ plttID
			.4byte 22185 << 5, 2619 << 2 @ .tiles[22185], .subsprites[2619]
		Metaprite_1314:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 29 @ plttID
			.4byte 22189 << 5, 2620 << 2 @ .tiles[22189], .subsprites[2620]
		Metaprite_1315:
			.byte 2, 5 @ subspriteCount, unk_01
			.2byte 29 @ plttID
			.4byte 22193 << 5, 2621 << 2 @ .tiles[22193], .subsprites[2621]
		Metaprite_1316:
			.byte 2, 6 @ subspriteCount, unk_01
			.2byte 29 @ plttID
			.4byte 22198 << 5, 2623 << 2 @ .tiles[22198], .subsprites[2623]
		Metaprite_1317:
			.byte 2, 5 @ subspriteCount, unk_01
			.2byte 29 @ plttID
			.4byte 22204 << 5, 2625 << 2 @ .tiles[22204], .subsprites[2625]
		Metaprite_1318:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 29 @ plttID
			.4byte 22209 << 5, 2627 << 2 @ .tiles[22209], .subsprites[2627]
		Metaprite_1319:
			.byte 2, 5 @ subspriteCount, unk_01
			.2byte 29 @ plttID
			.4byte 22213 << 5, 2628 << 2 @ .tiles[22213], .subsprites[2628]
		Metaprite_1320:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 29 @ plttID
			.4byte 22218 << 5, 2630 << 2 @ .tiles[22218], .subsprites[2630]
		Metaprite_1321:
			.byte 2, 6 @ subspriteCount, unk_01
			.2byte 29 @ plttID
			.4byte 22222 << 5, 2631 << 2 @ .tiles[22222], .subsprites[2631]
		Metaprite_1322:
			.byte 2, 6 @ subspriteCount, unk_01
			.2byte 29 @ plttID
			.4byte 22228 << 5, 2633 << 2 @ .tiles[22228], .subsprites[2633]
		Metaprite_1323:
			.byte 2, 6 @ subspriteCount, unk_01
			.2byte 29 @ plttID
			.4byte 22234 << 5, 2635 << 2 @ .tiles[22234], .subsprites[2635]
		Metaprite_1324:
			.byte 1, 8 @ subspriteCount, unk_01
			.2byte 29 @ plttID
			.4byte 22240 << 5, 2637 << 2 @ .tiles[22240], .subsprites[2637]
		Metaprite_1325:
			.byte 2, 5 @ subspriteCount, unk_01
			.2byte 29 @ plttID
			.4byte 22248 << 5, 2638 << 2 @ .tiles[22248], .subsprites[2638]
		Metaprite_1326:
			.byte 3, 6 @ subspriteCount, unk_01
			.2byte 29 @ plttID
			.4byte 22253 << 5, 2640 << 2 @ .tiles[22253], .subsprites[2640]
		Metaprite_1327:
			.byte 2, 5 @ subspriteCount, unk_01
			.2byte 29 @ plttID
			.4byte 22259 << 5, 2643 << 2 @ .tiles[22259], .subsprites[2643]
		Metaprite_1328:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 29 @ plttID
			.4byte 22264 << 5, 2645 << 2 @ .tiles[22264], .subsprites[2645]
		Metaprite_1329:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 29 @ plttID
			.4byte 22268 << 5, 2646 << 2 @ .tiles[22268], .subsprites[2646]
		Metaprite_1330:
			.byte 2, 5 @ subspriteCount, unk_01
			.2byte 29 @ plttID
			.4byte 22272 << 5, 2647 << 2 @ .tiles[22272], .subsprites[2647]
		Metaprite_1331:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 22277 << 5, 2649 << 2 @ .tiles[22277], .subsprites[2649]
		Metaprite_1332:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 22325 << 5, 2652 << 2 @ .tiles[22325], .subsprites[2652]
		Metaprite_1333:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 22373 << 5, 2655 << 2 @ .tiles[22373], .subsprites[2655]
		Metaprite_1334:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 22421 << 5, 2658 << 2 @ .tiles[22421], .subsprites[2658]
		Metaprite_1335:
			.byte 1, 2 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 22469 << 5, 2661 << 2 @ .tiles[22469], .subsprites[2661]
		Metaprite_1336:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 22471 << 5, 2662 << 2 @ .tiles[22471], .subsprites[2662]
		Metaprite_1337:
			.byte 1, 32 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 22519 << 5, 2665 << 2 @ .tiles[22519], .subsprites[2665]
		Metaprite_1338:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 22551 << 5, 2666 << 2 @ .tiles[22551], .subsprites[2666]
		Metaprite_1339:
			.byte 1, 32 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 22599 << 5, 2669 << 2 @ .tiles[22599], .subsprites[2669]
		Metaprite_1340:
			.byte 4, 36 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 22631 << 5, 2670 << 2 @ .tiles[22631], .subsprites[2670]
		Metaprite_1341:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 22667 << 5, 2674 << 2 @ .tiles[22667], .subsprites[2674]
		Metaprite_1342:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 22715 << 5, 2677 << 2 @ .tiles[22715], .subsprites[2677]
		Metaprite_1343:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 22763 << 5, 2680 << 2 @ .tiles[22763], .subsprites[2680]
		Metaprite_1344:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 22811 << 5, 2683 << 2 @ .tiles[22811], .subsprites[2683]
		Metaprite_1345:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 22859 << 5, 2686 << 2 @ .tiles[22859], .subsprites[2686]
		Metaprite_1346:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 22907 << 5, 2689 << 2 @ .tiles[22907], .subsprites[2689]
		Metaprite_1347:
			.byte 4, 36 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 22955 << 5, 2692 << 2 @ .tiles[22955], .subsprites[2692]
		Metaprite_1348:
			.byte 2, 40 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 22991 << 5, 2696 << 2 @ .tiles[22991], .subsprites[2696]
		Metaprite_1349:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 23031 << 5, 2698 << 2 @ .tiles[23031], .subsprites[2698]
		Metaprite_1350:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 23079 << 5, 2701 << 2 @ .tiles[23079], .subsprites[2701]
		Metaprite_1351:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 23127 << 5, 2704 << 2 @ .tiles[23127], .subsprites[2704]
		Metaprite_1352:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 23175 << 5, 2707 << 2 @ .tiles[23175], .subsprites[2707]
		Metaprite_1353:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 23223 << 5, 2710 << 2 @ .tiles[23223], .subsprites[2710]
		Metaprite_1354:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 23271 << 5, 2713 << 2 @ .tiles[23271], .subsprites[2713]
		Metaprite_1355:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 23319 << 5, 2716 << 2 @ .tiles[23319], .subsprites[2716]
		Metaprite_1356:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 433 @ plttID
			.4byte 23367 << 5, 2719 << 2 @ .tiles[23367], .subsprites[2719]
		Metaprite_1357:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 433 @ plttID
			.4byte 23415 << 5, 2722 << 2 @ .tiles[23415], .subsprites[2722]
		Metaprite_1358:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 435 @ plttID
			.4byte 23463 << 5, 2725 << 2 @ .tiles[23463], .subsprites[2725]
		Metaprite_1359:
			.byte 2, 10 @ subspriteCount, unk_01
			.2byte 435 @ plttID
			.4byte 23483 << 5, 2727 << 2 @ .tiles[23483], .subsprites[2727]
		Metaprite_1360:
			.byte 3, 14 @ subspriteCount, unk_01
			.2byte 438 @ plttID
			.4byte 23493 << 5, 2729 << 2 @ .tiles[23493], .subsprites[2729]
		Metaprite_1361:
			.byte 3, 14 @ subspriteCount, unk_01
			.2byte 438 @ plttID
			.4byte 23507 << 5, 2732 << 2 @ .tiles[23507], .subsprites[2732]
		Metaprite_1362:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 438 @ plttID
			.4byte 23521 << 5, 2735 << 2 @ .tiles[23521], .subsprites[2735]
		Metaprite_1363:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 438 @ plttID
			.4byte 23537 << 5, 2736 << 2 @ .tiles[23537], .subsprites[2736]
		Metaprite_1364:
			.byte 2, 12 @ subspriteCount, unk_01
			.2byte 438 @ plttID
			.4byte 23553 << 5, 2737 << 2 @ .tiles[23553], .subsprites[2737]
		Metaprite_1365:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 438 @ plttID
			.4byte 23565 << 5, 2739 << 2 @ .tiles[23565], .subsprites[2739]
		Metaprite_1366:
			.byte 3, 9 @ subspriteCount, unk_01
			.2byte 438 @ plttID
			.4byte 23581 << 5, 2740 << 2 @ .tiles[23581], .subsprites[2740]
		Metaprite_1367:
			.byte 4, 36 @ subspriteCount, unk_01
			.2byte 439 @ plttID
			.4byte 23590 << 5, 2743 << 2 @ .tiles[23590], .subsprites[2743]
		Metaprite_1368:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 439 @ plttID
			.4byte 23626 << 5, 2747 << 2 @ .tiles[23626], .subsprites[2747]
		Metaprite_1369:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 439 @ plttID
			.4byte 23674 << 5, 2750 << 2 @ .tiles[23674], .subsprites[2750]
		Metaprite_1370:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 439 @ plttID
			.4byte 23722 << 5, 2753 << 2 @ .tiles[23722], .subsprites[2753]
		Metaprite_1371:
			.byte 4, 36 @ subspriteCount, unk_01
			.2byte 439 @ plttID
			.4byte 23770 << 5, 2756 << 2 @ .tiles[23770], .subsprites[2756]
		Metaprite_1372:
			.byte 4, 36 @ subspriteCount, unk_01
			.2byte 439 @ plttID
			.4byte 23806 << 5, 2760 << 2 @ .tiles[23806], .subsprites[2760]
		Metaprite_1373:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 447 @ plttID
			.4byte 23842 << 5, 2764 << 2 @ .tiles[23842], .subsprites[2764]
		Metaprite_1374:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 447 @ plttID
			.4byte 23866 << 5, 2766 << 2 @ .tiles[23866], .subsprites[2766]
		Metaprite_1375:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 447 @ plttID
			.4byte 23886 << 5, 2768 << 2 @ .tiles[23886], .subsprites[2768]
		Metaprite_1376:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 447 @ plttID
			.4byte 23906 << 5, 2770 << 2 @ .tiles[23906], .subsprites[2770]
		Metaprite_1377:
			.byte 3, 14 @ subspriteCount, unk_01
			.2byte 447 @ plttID
			.4byte 23930 << 5, 2772 << 2 @ .tiles[23930], .subsprites[2772]
		Metaprite_1378:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 447 @ plttID
			.4byte 23944 << 5, 2775 << 2 @ .tiles[23944], .subsprites[2775]
		Metaprite_1379:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 447 @ plttID
			.4byte 23968 << 5, 2777 << 2 @ .tiles[23968], .subsprites[2777]
		Metaprite_1380:
			.byte 2, 5 @ subspriteCount, unk_01
			.2byte 447 @ plttID
			.4byte 23992 << 5, 2779 << 2 @ .tiles[23992], .subsprites[2779]
		Metaprite_1381:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 447 @ plttID
			.4byte 23997 << 5, 2781 << 2 @ .tiles[23997], .subsprites[2781]
		Metaprite_1382:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 447 @ plttID
			.4byte 24013 << 5, 2782 << 2 @ .tiles[24013], .subsprites[2782]
		Metaprite_1383:
			.byte 3, 14 @ subspriteCount, unk_01
			.2byte 447 @ plttID
			.4byte 24033 << 5, 2784 << 2 @ .tiles[24033], .subsprites[2784]
		Metaprite_1384:
			.byte 4, 9 @ subspriteCount, unk_01
			.2byte 447 @ plttID
			.4byte 24047 << 5, 2787 << 2 @ .tiles[24047], .subsprites[2787]
		Metaprite_1385:
			.byte 3, 7 @ subspriteCount, unk_01
			.2byte 447 @ plttID
			.4byte 24056 << 5, 2791 << 2 @ .tiles[24056], .subsprites[2791]
		Metaprite_1386:
			.byte 4, 15 @ subspriteCount, unk_01
			.2byte 447 @ plttID
			.4byte 24063 << 5, 2794 << 2 @ .tiles[24063], .subsprites[2794]
		Metaprite_1387:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 447 @ plttID
			.4byte 24078 << 5, 2798 << 2 @ .tiles[24078], .subsprites[2798]
		Metaprite_1388:
			.byte 3, 24 @ subspriteCount, unk_01
			.2byte 447 @ plttID
			.4byte 24094 << 5, 2799 << 2 @ .tiles[24094], .subsprites[2799]
		Metaprite_1389:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 447 @ plttID
			.4byte 24118 << 5, 2802 << 2 @ .tiles[24118], .subsprites[2802]
		Metaprite_1390:
			.byte 1, 64 @ subspriteCount, unk_01
			.2byte 447 @ plttID
			.4byte 24138 << 5, 2804 << 2 @ .tiles[24138], .subsprites[2804]
		Metaprite_1391:
			.byte 3, 28 @ subspriteCount, unk_01
			.2byte 447 @ plttID
			.4byte 24202 << 5, 2805 << 2 @ .tiles[24202], .subsprites[2805]
		Metaprite_1392:
			.byte 1, 32 @ subspriteCount, unk_01
			.2byte 447 @ plttID
			.4byte 24230 << 5, 2808 << 2 @ .tiles[24230], .subsprites[2808]
		Metaprite_1393:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 447 @ plttID
			.4byte 24262 << 5, 2809 << 2 @ .tiles[24262], .subsprites[2809]
		Metaprite_1394:
			.byte 3, 16 @ subspriteCount, unk_01
			.2byte 447 @ plttID
			.4byte 24286 << 5, 2811 << 2 @ .tiles[24286], .subsprites[2811]
		Metaprite_1395:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 447 @ plttID
			.4byte 24302 << 5, 2814 << 2 @ .tiles[24302], .subsprites[2814]
		Metaprite_1396:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 447 @ plttID
			.4byte 24326 << 5, 2816 << 2 @ .tiles[24326], .subsprites[2816]
		Metaprite_1397:
			.byte 2, 40 @ subspriteCount, unk_01
			.2byte 447 @ plttID
			.4byte 24350 << 5, 2818 << 2 @ .tiles[24350], .subsprites[2818]
		Metaprite_1398:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 447 @ plttID
			.4byte 24390 << 5, 2820 << 2 @ .tiles[24390], .subsprites[2820]
		Metaprite_1399:
			.byte 3, 24 @ subspriteCount, unk_01
			.2byte 447 @ plttID
			.4byte 24414 << 5, 2822 << 2 @ .tiles[24414], .subsprites[2822]
		Metaprite_1400:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 447 @ plttID
			.4byte 24438 << 5, 2825 << 2 @ .tiles[24438], .subsprites[2825]
		Metaprite_1401:
			.byte 1, 32 @ subspriteCount, unk_01
			.2byte 447 @ plttID
			.4byte 24462 << 5, 2827 << 2 @ .tiles[24462], .subsprites[2827]
		Metaprite_1402:
			.byte 1, 32 @ subspriteCount, unk_01
			.2byte 447 @ plttID
			.4byte 24494 << 5, 2828 << 2 @ .tiles[24494], .subsprites[2828]
		Metaprite_1403:
			.byte 1, 32 @ subspriteCount, unk_01
			.2byte 447 @ plttID
			.4byte 24526 << 5, 2829 << 2 @ .tiles[24526], .subsprites[2829]
		Metaprite_1404:
			.byte 1, 32 @ subspriteCount, unk_01
			.2byte 447 @ plttID
			.4byte 24558 << 5, 2830 << 2 @ .tiles[24558], .subsprites[2830]
		Metaprite_1405:
			.byte 1, 32 @ subspriteCount, unk_01
			.2byte 447 @ plttID
			.4byte 24590 << 5, 2831 << 2 @ .tiles[24590], .subsprites[2831]
		Metaprite_1406:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 447 @ plttID
			.4byte 24622 << 5, 2832 << 2 @ .tiles[24622], .subsprites[2832]
		Metaprite_1407:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 447 @ plttID
			.4byte 24642 << 5, 2834 << 2 @ .tiles[24642], .subsprites[2834]
		Metaprite_1408:
			.byte 3, 14 @ subspriteCount, unk_01
			.2byte 447 @ plttID
			.4byte 24658 << 5, 2835 << 2 @ .tiles[24658], .subsprites[2835]
		Metaprite_1409:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 24672 << 5, 2838 << 2 @ .tiles[24672], .subsprites[2838]
		Metaprite_1410:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 24720 << 5, 2841 << 2 @ .tiles[24720], .subsprites[2841]
		Metaprite_1411:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 24768 << 5, 2844 << 2 @ .tiles[24768], .subsprites[2844]
		Metaprite_1412:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 24816 << 5, 2847 << 2 @ .tiles[24816], .subsprites[2847]
		Metaprite_1413:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 24864 << 5, 2850 << 2 @ .tiles[24864], .subsprites[2850]
		Metaprite_1414:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 24912 << 5, 2853 << 2 @ .tiles[24912], .subsprites[2853]
		Metaprite_1415:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 24960 << 5, 2856 << 2 @ .tiles[24960], .subsprites[2856]
		Metaprite_1416:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 25008 << 5, 2859 << 2 @ .tiles[25008], .subsprites[2859]
		Metaprite_1417:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 25056 << 5, 2862 << 2 @ .tiles[25056], .subsprites[2862]
		Metaprite_1418:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 25104 << 5, 2865 << 2 @ .tiles[25104], .subsprites[2865]
		Metaprite_1419:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 25152 << 5, 2868 << 2 @ .tiles[25152], .subsprites[2868]
		Metaprite_1420:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 25200 << 5, 2871 << 2 @ .tiles[25200], .subsprites[2871]
		Metaprite_1421:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 25248 << 5, 2874 << 2 @ .tiles[25248], .subsprites[2874]
		Metaprite_1422:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 25296 << 5, 2877 << 2 @ .tiles[25296], .subsprites[2877]
		Metaprite_1423:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 25344 << 5, 2880 << 2 @ .tiles[25344], .subsprites[2880]
		Metaprite_1424:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 25392 << 5, 2883 << 2 @ .tiles[25392], .subsprites[2883]
		Metaprite_1425:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 25440 << 5, 2886 << 2 @ .tiles[25440], .subsprites[2886]
		Metaprite_1426:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 25488 << 5, 2889 << 2 @ .tiles[25488], .subsprites[2889]
		Metaprite_1427:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 25536 << 5, 2892 << 2 @ .tiles[25536], .subsprites[2892]
		Metaprite_1428:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 25584 << 5, 2895 << 2 @ .tiles[25584], .subsprites[2895]
		Metaprite_1429:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 25632 << 5, 2898 << 2 @ .tiles[25632], .subsprites[2898]
		Metaprite_1430:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 25680 << 5, 2901 << 2 @ .tiles[25680], .subsprites[2901]
		Metaprite_1431:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 25728 << 5, 2904 << 2 @ .tiles[25728], .subsprites[2904]
		Metaprite_1432:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 25776 << 5, 2907 << 2 @ .tiles[25776], .subsprites[2907]
		Metaprite_1433:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 25824 << 5, 2910 << 2 @ .tiles[25824], .subsprites[2910]
		Metaprite_1434:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 25872 << 5, 2913 << 2 @ .tiles[25872], .subsprites[2913]
		Metaprite_1435:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 25920 << 5, 2916 << 2 @ .tiles[25920], .subsprites[2916]
		Metaprite_1436:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 25968 << 5, 2919 << 2 @ .tiles[25968], .subsprites[2919]
		Metaprite_1437:
			.byte 3, 20 @ subspriteCount, unk_01
			.2byte 451 @ plttID
			.4byte 26016 << 5, 2922 << 2 @ .tiles[26016], .subsprites[2922]
		Metaprite_1438:
			.byte 4, 30 @ subspriteCount, unk_01
			.2byte 451 @ plttID
			.4byte 26036 << 5, 2925 << 2 @ .tiles[26036], .subsprites[2925]
		Metaprite_1439:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 451 @ plttID
			.4byte 26066 << 5, 2929 << 2 @ .tiles[26066], .subsprites[2929]
		Metaprite_1440:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 451 @ plttID
			.4byte 26114 << 5, 2932 << 2 @ .tiles[26114], .subsprites[2932]
		Metaprite_1441:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 451 @ plttID
			.4byte 26162 << 5, 2935 << 2 @ .tiles[26162], .subsprites[2935]
		Metaprite_1442:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 451 @ plttID
			.4byte 26210 << 5, 2938 << 2 @ .tiles[26210], .subsprites[2938]
		Metaprite_1443:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 451 @ plttID
			.4byte 26258 << 5, 2941 << 2 @ .tiles[26258], .subsprites[2941]
		Metaprite_1444:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 451 @ plttID
			.4byte 26306 << 5, 2944 << 2 @ .tiles[26306], .subsprites[2944]
		Metaprite_1445:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 451 @ plttID
			.4byte 26354 << 5, 2947 << 2 @ .tiles[26354], .subsprites[2947]
		Metaprite_1446:
			.byte 4, 30 @ subspriteCount, unk_01
			.2byte 451 @ plttID
			.4byte 26402 << 5, 2950 << 2 @ .tiles[26402], .subsprites[2950]
		Metaprite_1447:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 451 @ plttID
			.4byte 26432 << 5, 2954 << 2 @ .tiles[26432], .subsprites[2954]
		Metaprite_1448:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 451 @ plttID
			.4byte 26480 << 5, 2957 << 2 @ .tiles[26480], .subsprites[2957]
		Metaprite_1449:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 451 @ plttID
			.4byte 26528 << 5, 2960 << 2 @ .tiles[26528], .subsprites[2960]
		Metaprite_1450:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 451 @ plttID
			.4byte 26576 << 5, 2963 << 2 @ .tiles[26576], .subsprites[2963]
		Metaprite_1451:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 451 @ plttID
			.4byte 26624 << 5, 2966 << 2 @ .tiles[26624], .subsprites[2966]
		Metaprite_1452:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 451 @ plttID
			.4byte 26672 << 5, 2969 << 2 @ .tiles[26672], .subsprites[2969]
		Metaprite_1453:
			.byte 4, 36 @ subspriteCount, unk_01
			.2byte 451 @ plttID
			.4byte 26720 << 5, 2972 << 2 @ .tiles[26720], .subsprites[2972]
		Metaprite_1454:
			.byte 4, 36 @ subspriteCount, unk_01
			.2byte 460 @ plttID
			.4byte 26756 << 5, 2976 << 2 @ .tiles[26756], .subsprites[2976]
		Metaprite_1455:
			.byte 1, 64 @ subspriteCount, unk_01
			.2byte 460 @ plttID
			.4byte 26792 << 5, 2980 << 2 @ .tiles[26792], .subsprites[2980]
		Metaprite_1456:
			.byte 3, 11 @ subspriteCount, unk_01
			.2byte 466 @ plttID
			.4byte 26856 << 5, 2981 << 2 @ .tiles[26856], .subsprites[2981]
		Metaprite_1457:
			.byte 3, 11 @ subspriteCount, unk_01
			.2byte 466 @ plttID
			.4byte 26867 << 5, 2984 << 2 @ .tiles[26867], .subsprites[2984]
		Metaprite_1458:
			.byte 3, 11 @ subspriteCount, unk_01
			.2byte 466 @ plttID
			.4byte 26878 << 5, 2987 << 2 @ .tiles[26878], .subsprites[2987]
		Metaprite_1459:
			.byte 3, 11 @ subspriteCount, unk_01
			.2byte 466 @ plttID
			.4byte 26889 << 5, 2990 << 2 @ .tiles[26889], .subsprites[2990]
		Metaprite_1460:
			.byte 3, 28 @ subspriteCount, unk_01
			.2byte 287 @ plttID
			.4byte 26900 << 5, 2993 << 2 @ .tiles[26900], .subsprites[2993]
		Metaprite_1461:
			.byte 3, 28 @ subspriteCount, unk_01
			.2byte 287 @ plttID
			.4byte 26928 << 5, 2996 << 2 @ .tiles[26928], .subsprites[2996]
		Metaprite_1462:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 26956 << 5, 2999 << 2 @ .tiles[26956], .subsprites[2999]
		Metaprite_1463:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 27004 << 5, 3002 << 2 @ .tiles[27004], .subsprites[3002]
		Metaprite_1464:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 27052 << 5, 3005 << 2 @ .tiles[27052], .subsprites[3005]
		Metaprite_1465:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 27100 << 5, 3008 << 2 @ .tiles[27100], .subsprites[3008]
		Metaprite_1466:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 27148 << 5, 3011 << 2 @ .tiles[27148], .subsprites[3011]
		Metaprite_1467:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 27196 << 5, 3014 << 2 @ .tiles[27196], .subsprites[3014]
		Metaprite_1468:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 27244 << 5, 3017 << 2 @ .tiles[27244], .subsprites[3017]
		Metaprite_1469:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 27292 << 5, 3020 << 2 @ .tiles[27292], .subsprites[3020]
		Metaprite_1470:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 27340 << 5, 3023 << 2 @ .tiles[27340], .subsprites[3023]
		Metaprite_1471:
			.byte 4, 30 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 27388 << 5, 3026 << 2 @ .tiles[27388], .subsprites[3026]
		Metaprite_1472:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 27418 << 5, 3030 << 2 @ .tiles[27418], .subsprites[3030]
		Metaprite_1473:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 467 @ plttID
			.4byte 27466 << 5, 3033 << 2 @ .tiles[27466], .subsprites[3033]
		Metaprite_1474:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 467 @ plttID
			.4byte 27467 << 5, 3034 << 2 @ .tiles[27467], .subsprites[3034]
		Metaprite_1475:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 467 @ plttID
			.4byte 27468 << 5, 3035 << 2 @ .tiles[27468], .subsprites[3035]
		Metaprite_1476:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 467 @ plttID
			.4byte 27469 << 5, 3036 << 2 @ .tiles[27469], .subsprites[3036]
		Metaprite_1477:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 482 @ plttID
			.4byte 27470 << 5, 3037 << 2 @ .tiles[27470], .subsprites[3037]
		Metaprite_1478:
			.byte 1, 64 @ subspriteCount, unk_01
			.2byte 498 @ plttID
			.4byte 27518 << 5, 3040 << 2 @ .tiles[27518], .subsprites[3040]
		Metaprite_1479:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 27582 << 5, 3041 << 2 @ .tiles[27582], .subsprites[3041]
		Metaprite_1480:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 27630 << 5, 3044 << 2 @ .tiles[27630], .subsprites[3044]
		Metaprite_1481:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 27678 << 5, 3047 << 2 @ .tiles[27678], .subsprites[3047]
		Metaprite_1482:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 27726 << 5, 3050 << 2 @ .tiles[27726], .subsprites[3050]
		Metaprite_1483:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 27774 << 5, 3053 << 2 @ .tiles[27774], .subsprites[3053]
		Metaprite_1484:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 27822 << 5, 3056 << 2 @ .tiles[27822], .subsprites[3056]
		Metaprite_1485:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 27870 << 5, 3059 << 2 @ .tiles[27870], .subsprites[3059]
		Metaprite_1486:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 27918 << 5, 3062 << 2 @ .tiles[27918], .subsprites[3062]
		Metaprite_1487:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 27966 << 5, 3065 << 2 @ .tiles[27966], .subsprites[3065]
		Metaprite_1488:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 28014 << 5, 3068 << 2 @ .tiles[28014], .subsprites[3068]
		Metaprite_1489:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 28062 << 5, 3071 << 2 @ .tiles[28062], .subsprites[3071]
		Metaprite_1490:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 28110 << 5, 3074 << 2 @ .tiles[28110], .subsprites[3074]
		Metaprite_1491:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 28158 << 5, 3077 << 2 @ .tiles[28158], .subsprites[3077]
		Metaprite_1492:
			.byte 4, 36 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 28206 << 5, 3080 << 2 @ .tiles[28206], .subsprites[3080]
		Metaprite_1493:
			.byte 4, 25 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 28242 << 5, 3084 << 2 @ .tiles[28242], .subsprites[3084]
		Metaprite_1494:
			.byte 3, 18 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 28267 << 5, 3088 << 2 @ .tiles[28267], .subsprites[3088]
		Metaprite_1495:
			.byte 4, 30 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 28285 << 5, 3091 << 2 @ .tiles[28285], .subsprites[3091]
		Metaprite_1496:
			.byte 4, 30 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 28315 << 5, 3095 << 2 @ .tiles[28315], .subsprites[3095]
		Metaprite_1497:
			.byte 4, 30 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 28345 << 5, 3099 << 2 @ .tiles[28345], .subsprites[3099]
		Metaprite_1498:
			.byte 4, 30 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 28375 << 5, 3103 << 2 @ .tiles[28375], .subsprites[3103]
		Metaprite_1499:
			.byte 3, 18 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 28405 << 5, 3107 << 2 @ .tiles[28405], .subsprites[3107]
		Metaprite_1500:
			.byte 3, 18 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 28423 << 5, 3110 << 2 @ .tiles[28423], .subsprites[3110]
		Metaprite_1501:
			.byte 3, 18 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 28441 << 5, 3113 << 2 @ .tiles[28441], .subsprites[3113]
		Metaprite_1502:
			.byte 3, 24 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 28459 << 5, 3116 << 2 @ .tiles[28459], .subsprites[3116]
		Metaprite_1503:
			.byte 3, 24 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 28483 << 5, 3119 << 2 @ .tiles[28483], .subsprites[3119]
		Metaprite_1504:
			.byte 3, 24 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 28507 << 5, 3122 << 2 @ .tiles[28507], .subsprites[3122]
		Metaprite_1505:
			.byte 3, 24 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 28531 << 5, 3125 << 2 @ .tiles[28531], .subsprites[3125]
		Metaprite_1506:
			.byte 3, 24 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 28555 << 5, 3128 << 2 @ .tiles[28555], .subsprites[3128]
		Metaprite_1507:
			.byte 3, 24 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 28579 << 5, 3131 << 2 @ .tiles[28579], .subsprites[3131]
		Metaprite_1508:
			.byte 3, 28 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 28603 << 5, 3134 << 2 @ .tiles[28603], .subsprites[3134]
		Metaprite_1509:
			.byte 3, 40 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 28631 << 5, 3137 << 2 @ .tiles[28631], .subsprites[3137]
		Metaprite_1510:
			.byte 3, 40 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 28671 << 5, 3140 << 2 @ .tiles[28671], .subsprites[3140]
		Metaprite_1511:
			.byte 3, 40 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 28711 << 5, 3143 << 2 @ .tiles[28711], .subsprites[3143]
		Metaprite_1512:
			.byte 3, 28 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 28751 << 5, 3146 << 2 @ .tiles[28751], .subsprites[3146]
		Metaprite_1513:
			.byte 3, 28 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 28779 << 5, 3149 << 2 @ .tiles[28779], .subsprites[3149]
		Metaprite_1514:
			.byte 3, 28 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 28807 << 5, 3152 << 2 @ .tiles[28807], .subsprites[3152]
		Metaprite_1515:
			.byte 4, 30 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 28835 << 5, 3155 << 2 @ .tiles[28835], .subsprites[3155]
		Metaprite_1516:
			.byte 4, 30 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 28865 << 5, 3159 << 2 @ .tiles[28865], .subsprites[3159]
		Metaprite_1517:
			.byte 4, 30 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 28895 << 5, 3163 << 2 @ .tiles[28895], .subsprites[3163]
		Metaprite_1518:
			.byte 4, 25 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 28925 << 5, 3167 << 2 @ .tiles[28925], .subsprites[3167]
		Metaprite_1519:
			.byte 4, 25 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 28950 << 5, 3171 << 2 @ .tiles[28950], .subsprites[3171]
		Metaprite_1520:
			.byte 4, 25 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 28975 << 5, 3175 << 2 @ .tiles[28975], .subsprites[3175]
		Metaprite_1521:
			.byte 4, 25 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 29000 << 5, 3179 << 2 @ .tiles[29000], .subsprites[3179]
		Metaprite_1522:
			.byte 4, 25 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 29025 << 5, 3183 << 2 @ .tiles[29025], .subsprites[3183]
		Metaprite_1523:
			.byte 3, 28 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 29050 << 5, 3187 << 2 @ .tiles[29050], .subsprites[3187]
		Metaprite_1524:
			.byte 3, 18 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 29078 << 5, 3190 << 2 @ .tiles[29078], .subsprites[3190]
		Metaprite_1525:
			.byte 3, 18 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 29096 << 5, 3193 << 2 @ .tiles[29096], .subsprites[3193]
		Metaprite_1526:
			.byte 3, 18 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 29114 << 5, 3196 << 2 @ .tiles[29114], .subsprites[3196]
		Metaprite_1527:
			.byte 3, 24 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 29132 << 5, 3199 << 2 @ .tiles[29132], .subsprites[3199]
		Metaprite_1528:
			.byte 3, 28 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 29156 << 5, 3202 << 2 @ .tiles[29156], .subsprites[3202]
		Metaprite_1529:
			.byte 3, 24 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 29184 << 5, 3205 << 2 @ .tiles[29184], .subsprites[3205]
		Metaprite_1530:
			.byte 3, 24 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 29208 << 5, 3208 << 2 @ .tiles[29208], .subsprites[3208]
		Metaprite_1531:
			.byte 4, 30 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 29232 << 5, 3211 << 2 @ .tiles[29232], .subsprites[3211]
		Metaprite_1532:
			.byte 4, 36 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 29262 << 5, 3215 << 2 @ .tiles[29262], .subsprites[3215]
		Metaprite_1533:
			.byte 4, 36 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 29298 << 5, 3219 << 2 @ .tiles[29298], .subsprites[3219]
		Metaprite_1534:
			.byte 3, 24 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 29334 << 5, 3223 << 2 @ .tiles[29334], .subsprites[3223]
		Metaprite_1535:
			.byte 2, 40 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 29358 << 5, 3226 << 2 @ .tiles[29358], .subsprites[3226]
		Metaprite_1536:
			.byte 2, 40 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 29398 << 5, 3228 << 2 @ .tiles[29398], .subsprites[3228]
		Metaprite_1537:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 29438 << 5, 3230 << 2 @ .tiles[29438], .subsprites[3230]
		Metaprite_1538:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 29486 << 5, 3233 << 2 @ .tiles[29486], .subsprites[3233]
		Metaprite_1539:
			.byte 3, 28 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 29534 << 5, 3236 << 2 @ .tiles[29534], .subsprites[3236]
		Metaprite_1540:
			.byte 3, 28 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 29562 << 5, 3239 << 2 @ .tiles[29562], .subsprites[3239]
		Metaprite_1541:
			.byte 3, 24 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 29590 << 5, 3242 << 2 @ .tiles[29590], .subsprites[3242]
		Metaprite_1542:
			.byte 4, 25 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 29614 << 5, 3245 << 2 @ .tiles[29614], .subsprites[3245]
		Metaprite_1543:
			.byte 4, 30 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 29639 << 5, 3249 << 2 @ .tiles[29639], .subsprites[3249]
		Metaprite_1544:
			.byte 3, 26 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 29669 << 5, 3253 << 2 @ .tiles[29669], .subsprites[3253]
		Metaprite_1545:
			.byte 4, 25 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 29695 << 5, 3256 << 2 @ .tiles[29695], .subsprites[3256]
		Metaprite_1546:
			.byte 4, 25 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 29720 << 5, 3260 << 2 @ .tiles[29720], .subsprites[3260]
		Metaprite_1547:
			.byte 4, 25 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 29745 << 5, 3264 << 2 @ .tiles[29745], .subsprites[3264]
		Metaprite_1548:
			.byte 3, 24 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 29770 << 5, 3268 << 2 @ .tiles[29770], .subsprites[3268]
		Metaprite_1549:
			.byte 3, 28 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 29794 << 5, 3271 << 2 @ .tiles[29794], .subsprites[3271]
		Metaprite_1550:
			.byte 2, 40 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 29822 << 5, 3274 << 2 @ .tiles[29822], .subsprites[3274]
		Metaprite_1551:
			.byte 3, 28 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 29862 << 5, 3276 << 2 @ .tiles[29862], .subsprites[3276]
		Metaprite_1552:
			.byte 3, 28 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 29890 << 5, 3279 << 2 @ .tiles[29890], .subsprites[3279]
		Metaprite_1553:
			.byte 3, 24 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 29918 << 5, 3282 << 2 @ .tiles[29918], .subsprites[3282]
		Metaprite_1554:
			.byte 2, 16 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 29942 << 5, 3285 << 2 @ .tiles[29942], .subsprites[3285]
		Metaprite_1555:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 29958 << 5, 3287 << 2 @ .tiles[29958], .subsprites[3287]
		Metaprite_1556:
			.byte 2, 16 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 29978 << 5, 3289 << 2 @ .tiles[29978], .subsprites[3289]
		Metaprite_1557:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 29994 << 5, 3291 << 2 @ .tiles[29994], .subsprites[3291]
		Metaprite_1558:
			.byte 3, 24 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 30014 << 5, 3293 << 2 @ .tiles[30014], .subsprites[3293]
		Metaprite_1559:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 30038 << 5, 3296 << 2 @ .tiles[30038], .subsprites[3296]
		Metaprite_1560:
			.byte 3, 20 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 30054 << 5, 3297 << 2 @ .tiles[30054], .subsprites[3297]
		Metaprite_1561:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 30074 << 5, 3300 << 2 @ .tiles[30074], .subsprites[3300]
		Metaprite_1562:
			.byte 3, 28 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 30094 << 5, 3302 << 2 @ .tiles[30094], .subsprites[3302]
		Metaprite_1563:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 30122 << 5, 3305 << 2 @ .tiles[30122], .subsprites[3305]
		Metaprite_1564:
			.byte 3, 28 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 30142 << 5, 3307 << 2 @ .tiles[30142], .subsprites[3307]
		Metaprite_1565:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 30170 << 5, 3310 << 2 @ .tiles[30170], .subsprites[3310]
		Metaprite_1566:
			.byte 3, 28 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 30190 << 5, 3312 << 2 @ .tiles[30190], .subsprites[3312]
		Metaprite_1567:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 30218 << 5, 3315 << 2 @ .tiles[30218], .subsprites[3315]
		Metaprite_1568:
			.byte 3, 28 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 30242 << 5, 3317 << 2 @ .tiles[30242], .subsprites[3317]
		Metaprite_1569:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 30270 << 5, 3320 << 2 @ .tiles[30270], .subsprites[3320]
		Metaprite_1570:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 30294 << 5, 3322 << 2 @ .tiles[30294], .subsprites[3322]
		Metaprite_1571:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 30318 << 5, 3324 << 2 @ .tiles[30318], .subsprites[3324]
		Metaprite_1572:
			.byte 3, 24 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 30338 << 5, 3326 << 2 @ .tiles[30338], .subsprites[3326]
		Metaprite_1573:
			.byte 3, 28 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 30362 << 5, 3329 << 2 @ .tiles[30362], .subsprites[3329]
		Metaprite_1574:
			.byte 3, 28 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 30390 << 5, 3332 << 2 @ .tiles[30390], .subsprites[3332]
		Metaprite_1575:
			.byte 4, 30 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 30418 << 5, 3335 << 2 @ .tiles[30418], .subsprites[3335]
		Metaprite_1576:
			.byte 3, 22 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 30448 << 5, 3339 << 2 @ .tiles[30448], .subsprites[3339]
		Metaprite_1577:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 30470 << 5, 3342 << 2 @ .tiles[30470], .subsprites[3342]
		Metaprite_1578:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 30490 << 5, 3344 << 2 @ .tiles[30490], .subsprites[3344]
		Metaprite_1579:
			.byte 1, 32 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 30514 << 5, 3346 << 2 @ .tiles[30514], .subsprites[3346]
		Metaprite_1580:
			.byte 2, 36 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 30546 << 5, 3347 << 2 @ .tiles[30546], .subsprites[3347]
		Metaprite_1581:
			.byte 3, 22 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 30582 << 5, 3349 << 2 @ .tiles[30582], .subsprites[3349]
		Metaprite_1582:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 30604 << 5, 3352 << 2 @ .tiles[30604], .subsprites[3352]
		Metaprite_1583:
			.byte 3, 28 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 30628 << 5, 3354 << 2 @ .tiles[30628], .subsprites[3354]
		Metaprite_1584:
			.byte 3, 40 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 30656 << 5, 3357 << 2 @ .tiles[30656], .subsprites[3357]
		Metaprite_1585:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 30696 << 5, 3360 << 2 @ .tiles[30696], .subsprites[3360]
		Metaprite_1586:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 30720 << 5, 3362 << 2 @ .tiles[30720], .subsprites[3362]
		Metaprite_1587:
			.byte 3, 19 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 30744 << 5, 3364 << 2 @ .tiles[30744], .subsprites[3364]
		Metaprite_1588:
			.byte 4, 30 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 30763 << 5, 3367 << 2 @ .tiles[30763], .subsprites[3367]
		Metaprite_1589:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 30793 << 5, 3371 << 2 @ .tiles[30793], .subsprites[3371]
		Metaprite_1590:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 30813 << 5, 3373 << 2 @ .tiles[30813], .subsprites[3373]
		Metaprite_1591:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 30833 << 5, 3375 << 2 @ .tiles[30833], .subsprites[3375]
		Metaprite_1592:
			.byte 3, 19 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 30857 << 5, 3377 << 2 @ .tiles[30857], .subsprites[3377]
		Metaprite_1593:
			.byte 3, 28 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 30876 << 5, 3380 << 2 @ .tiles[30876], .subsprites[3380]
		Metaprite_1594:
			.byte 3, 20 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 30904 << 5, 3383 << 2 @ .tiles[30904], .subsprites[3383]
		Metaprite_1595:
			.byte 3, 20 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 30924 << 5, 3386 << 2 @ .tiles[30924], .subsprites[3386]
		Metaprite_1596:
			.byte 3, 20 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 30944 << 5, 3389 << 2 @ .tiles[30944], .subsprites[3389]
		Metaprite_1597:
			.byte 3, 20 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 30964 << 5, 3392 << 2 @ .tiles[30964], .subsprites[3392]
		Metaprite_1598:
			.byte 3, 20 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 30984 << 5, 3395 << 2 @ .tiles[30984], .subsprites[3395]
		Metaprite_1599:
			.byte 3, 19 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 31004 << 5, 3398 << 2 @ .tiles[31004], .subsprites[3398]
		Metaprite_1600:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 31023 << 5, 3401 << 2 @ .tiles[31023], .subsprites[3401]
		Metaprite_1601:
			.byte 3, 19 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 31043 << 5, 3403 << 2 @ .tiles[31043], .subsprites[3403]
		Metaprite_1602:
			.byte 2, 17 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 31062 << 5, 3406 << 2 @ .tiles[31062], .subsprites[3406]
		Metaprite_1603:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 31079 << 5, 3408 << 2 @ .tiles[31079], .subsprites[3408]
		Metaprite_1604:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 31095 << 5, 3409 << 2 @ .tiles[31095], .subsprites[3409]
		Metaprite_1605:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 31111 << 5, 3410 << 2 @ .tiles[31111], .subsprites[3410]
		Metaprite_1606:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 31127 << 5, 3411 << 2 @ .tiles[31127], .subsprites[3411]
		Metaprite_1607:
			.byte 4, 30 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 31143 << 5, 3412 << 2 @ .tiles[31143], .subsprites[3412]
		Metaprite_1608:
			.byte 4, 36 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 31173 << 5, 3416 << 2 @ .tiles[31173], .subsprites[3416]
		Metaprite_1609:
			.byte 4, 36 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 31209 << 5, 3420 << 2 @ .tiles[31209], .subsprites[3420]
		Metaprite_1610:
			.byte 4, 36 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 31245 << 5, 3424 << 2 @ .tiles[31245], .subsprites[3424]
		Metaprite_1611:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 31281 << 5, 3428 << 2 @ .tiles[31281], .subsprites[3428]
		Metaprite_1612:
			.byte 4, 30 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 31329 << 5, 3431 << 2 @ .tiles[31329], .subsprites[3431]
		Metaprite_1613:
			.byte 4, 36 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 31359 << 5, 3435 << 2 @ .tiles[31359], .subsprites[3435]
		Metaprite_1614:
			.byte 4, 36 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 31395 << 5, 3439 << 2 @ .tiles[31395], .subsprites[3439]
		Metaprite_1615:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 31431 << 5, 3443 << 2 @ .tiles[31431], .subsprites[3443]
		Metaprite_1616:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 31455 << 5, 3445 << 2 @ .tiles[31455], .subsprites[3445]
		Metaprite_1617:
			.byte 3, 21 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 31479 << 5, 3447 << 2 @ .tiles[31479], .subsprites[3447]
		Metaprite_1618:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 31500 << 5, 3450 << 2 @ .tiles[31500], .subsprites[3450]
		Metaprite_1619:
			.byte 4, 15 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 31524 << 5, 3452 << 2 @ .tiles[31524], .subsprites[3452]
		Metaprite_1620:
			.byte 3, 28 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 31539 << 5, 3456 << 2 @ .tiles[31539], .subsprites[3456]
		Metaprite_1621:
			.byte 4, 18 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 31567 << 5, 3459 << 2 @ .tiles[31567], .subsprites[3459]
		Metaprite_1622:
			.byte 3, 19 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 31585 << 5, 3463 << 2 @ .tiles[31585], .subsprites[3463]
		Metaprite_1623:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 31604 << 5, 3466 << 2 @ .tiles[31604], .subsprites[3466]
		Metaprite_1624:
			.byte 4, 30 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 31624 << 5, 3468 << 2 @ .tiles[31624], .subsprites[3468]
		Metaprite_1625:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 31654 << 5, 3472 << 2 @ .tiles[31654], .subsprites[3472]
		Metaprite_1626:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 31678 << 5, 3474 << 2 @ .tiles[31678], .subsprites[3474]
		Metaprite_1627:
			.byte 3, 19 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 31702 << 5, 3476 << 2 @ .tiles[31702], .subsprites[3476]
		Metaprite_1628:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 31721 << 5, 3479 << 2 @ .tiles[31721], .subsprites[3479]
		Metaprite_1629:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 31745 << 5, 3481 << 2 @ .tiles[31745], .subsprites[3481]
		Metaprite_1630:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 31769 << 5, 3483 << 2 @ .tiles[31769], .subsprites[3483]
		Metaprite_1631:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 31793 << 5, 3485 << 2 @ .tiles[31793], .subsprites[3485]
		Metaprite_1632:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 31817 << 5, 3487 << 2 @ .tiles[31817], .subsprites[3487]
		Metaprite_1633:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 31841 << 5, 3489 << 2 @ .tiles[31841], .subsprites[3489]
		Metaprite_1634:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 31865 << 5, 3491 << 2 @ .tiles[31865], .subsprites[3491]
		Metaprite_1635:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 31889 << 5, 3493 << 2 @ .tiles[31889], .subsprites[3493]
		Metaprite_1636:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 31913 << 5, 3495 << 2 @ .tiles[31913], .subsprites[3495]
		Metaprite_1637:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 31937 << 5, 3497 << 2 @ .tiles[31937], .subsprites[3497]
		Metaprite_1638:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 31961 << 5, 3499 << 2 @ .tiles[31961], .subsprites[3499]
		Metaprite_1639:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 31985 << 5, 3501 << 2 @ .tiles[31985], .subsprites[3501]
		Metaprite_1640:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 32009 << 5, 3503 << 2 @ .tiles[32009], .subsprites[3503]
		Metaprite_1641:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 32033 << 5, 3505 << 2 @ .tiles[32033], .subsprites[3505]
		Metaprite_1642:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 32057 << 5, 3507 << 2 @ .tiles[32057], .subsprites[3507]
		Metaprite_1643:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 32081 << 5, 3509 << 2 @ .tiles[32081], .subsprites[3509]
		Metaprite_1644:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 32105 << 5, 3511 << 2 @ .tiles[32105], .subsprites[3511]
		Metaprite_1645:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 32129 << 5, 3513 << 2 @ .tiles[32129], .subsprites[3513]
		Metaprite_1646:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 32153 << 5, 3515 << 2 @ .tiles[32153], .subsprites[3515]
		Metaprite_1647:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 32177 << 5, 3517 << 2 @ .tiles[32177], .subsprites[3517]
		Metaprite_1648:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 32201 << 5, 3519 << 2 @ .tiles[32201], .subsprites[3519]
		Metaprite_1649:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 32225 << 5, 3521 << 2 @ .tiles[32225], .subsprites[3521]
		Metaprite_1650:
			.byte 3, 22 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 32249 << 5, 3523 << 2 @ .tiles[32249], .subsprites[3523]
		Metaprite_1651:
			.byte 3, 22 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 32271 << 5, 3526 << 2 @ .tiles[32271], .subsprites[3526]
		Metaprite_1652:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 32293 << 5, 3529 << 2 @ .tiles[32293], .subsprites[3529]
		Metaprite_1653:
			.byte 3, 22 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 32317 << 5, 3531 << 2 @ .tiles[32317], .subsprites[3531]
		Metaprite_1654:
			.byte 3, 22 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 32339 << 5, 3534 << 2 @ .tiles[32339], .subsprites[3534]
		Metaprite_1655:
			.byte 3, 22 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 32361 << 5, 3537 << 2 @ .tiles[32361], .subsprites[3537]
		Metaprite_1656:
			.byte 3, 22 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 32383 << 5, 3540 << 2 @ .tiles[32383], .subsprites[3540]
		Metaprite_1657:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 32405 << 5, 3543 << 2 @ .tiles[32405], .subsprites[3543]
		Metaprite_1658:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 32429 << 5, 3545 << 2 @ .tiles[32429], .subsprites[3545]
		Metaprite_1659:
			.byte 3, 20 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 32453 << 5, 3547 << 2 @ .tiles[32453], .subsprites[3547]
		Metaprite_1660:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 32473 << 5, 3550 << 2 @ .tiles[32473], .subsprites[3550]
		Metaprite_1661:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 32497 << 5, 3552 << 2 @ .tiles[32497], .subsprites[3552]
		Metaprite_1662:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 32521 << 5, 3554 << 2 @ .tiles[32521], .subsprites[3554]
		Metaprite_1663:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 32545 << 5, 3556 << 2 @ .tiles[32545], .subsprites[3556]
		Metaprite_1664:
			.byte 3, 20 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 32569 << 5, 3558 << 2 @ .tiles[32569], .subsprites[3558]
		Metaprite_1665:
			.byte 3, 20 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 32589 << 5, 3561 << 2 @ .tiles[32589], .subsprites[3561]
		Metaprite_1666:
			.byte 3, 20 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 32609 << 5, 3564 << 2 @ .tiles[32609], .subsprites[3564]
		Metaprite_1667:
			.byte 3, 20 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 32629 << 5, 3567 << 2 @ .tiles[32629], .subsprites[3567]
		Metaprite_1668:
			.byte 3, 20 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 32649 << 5, 3570 << 2 @ .tiles[32649], .subsprites[3570]
		Metaprite_1669:
			.byte 3, 20 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 32669 << 5, 3573 << 2 @ .tiles[32669], .subsprites[3573]
		Metaprite_1670:
			.byte 3, 20 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 32689 << 5, 3576 << 2 @ .tiles[32689], .subsprites[3576]
		Metaprite_1671:
			.byte 3, 20 @ subspriteCount, unk_01
			.2byte 506 @ plttID
			.4byte 32709 << 5, 3579 << 2 @ .tiles[32709], .subsprites[3579]
		Metaprite_1672:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 509 @ plttID
			.4byte 32729 << 5, 3582 << 2 @ .tiles[32729], .subsprites[3582]
		Metaprite_1673:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 509 @ plttID
			.4byte 32777 << 5, 3585 << 2 @ .tiles[32777], .subsprites[3585]
		Metaprite_1674:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 509 @ plttID
			.4byte 32793 << 5, 3586 << 2 @ .tiles[32793], .subsprites[3586]
		Metaprite_1675:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 513 @ plttID
			.4byte 32794 << 5, 3587 << 2 @ .tiles[32794], .subsprites[3587]
		Metaprite_1676:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 513 @ plttID
			.4byte 32818 << 5, 3589 << 2 @ .tiles[32818], .subsprites[3589]
		Metaprite_1677:
			.byte 3, 24 @ subspriteCount, unk_01
			.2byte 513 @ plttID
			.4byte 32838 << 5, 3591 << 2 @ .tiles[32838], .subsprites[3591]
		Metaprite_1678:
			.byte 3, 24 @ subspriteCount, unk_01
			.2byte 513 @ plttID
			.4byte 32862 << 5, 3594 << 2 @ .tiles[32862], .subsprites[3594]
		Metaprite_1679:
			.byte 3, 24 @ subspriteCount, unk_01
			.2byte 513 @ plttID
			.4byte 32886 << 5, 3597 << 2 @ .tiles[32886], .subsprites[3597]
		Metaprite_1680:
			.byte 3, 24 @ subspriteCount, unk_01
			.2byte 513 @ plttID
			.4byte 32910 << 5, 3600 << 2 @ .tiles[32910], .subsprites[3600]
		Metaprite_1681:
			.byte 3, 14 @ subspriteCount, unk_01
			.2byte 513 @ plttID
			.4byte 32934 << 5, 3603 << 2 @ .tiles[32934], .subsprites[3603]
		Metaprite_1682:
			.byte 3, 14 @ subspriteCount, unk_01
			.2byte 513 @ plttID
			.4byte 32948 << 5, 3606 << 2 @ .tiles[32948], .subsprites[3606]
		Metaprite_1683:
			.byte 3, 14 @ subspriteCount, unk_01
			.2byte 513 @ plttID
			.4byte 32962 << 5, 3609 << 2 @ .tiles[32962], .subsprites[3609]
		Metaprite_1684:
			.byte 3, 24 @ subspriteCount, unk_01
			.2byte 513 @ plttID
			.4byte 32976 << 5, 3612 << 2 @ .tiles[32976], .subsprites[3612]
		Metaprite_1685:
			.byte 3, 14 @ subspriteCount, unk_01
			.2byte 513 @ plttID
			.4byte 33000 << 5, 3615 << 2 @ .tiles[33000], .subsprites[3615]
		Metaprite_1686:
			.byte 3, 14 @ subspriteCount, unk_01
			.2byte 513 @ plttID
			.4byte 33014 << 5, 3618 << 2 @ .tiles[33014], .subsprites[3618]
		Metaprite_1687:
			.byte 3, 14 @ subspriteCount, unk_01
			.2byte 513 @ plttID
			.4byte 33028 << 5, 3621 << 2 @ .tiles[33028], .subsprites[3621]
		Metaprite_1688:
			.byte 3, 24 @ subspriteCount, unk_01
			.2byte 513 @ plttID
			.4byte 33042 << 5, 3624 << 2 @ .tiles[33042], .subsprites[3624]
		Metaprite_1689:
			.byte 3, 24 @ subspriteCount, unk_01
			.2byte 513 @ plttID
			.4byte 33066 << 5, 3627 << 2 @ .tiles[33066], .subsprites[3627]
		Metaprite_1690:
			.byte 3, 24 @ subspriteCount, unk_01
			.2byte 513 @ plttID
			.4byte 33090 << 5, 3630 << 2 @ .tiles[33090], .subsprites[3630]
		Metaprite_1691:
			.byte 3, 24 @ subspriteCount, unk_01
			.2byte 513 @ plttID
			.4byte 33114 << 5, 3633 << 2 @ .tiles[33114], .subsprites[3633]
		Metaprite_1692:
			.byte 3, 24 @ subspriteCount, unk_01
			.2byte 513 @ plttID
			.4byte 33138 << 5, 3636 << 2 @ .tiles[33138], .subsprites[3636]
		Metaprite_1693:
			.byte 3, 26 @ subspriteCount, unk_01
			.2byte 513 @ plttID
			.4byte 33162 << 5, 3639 << 2 @ .tiles[33162], .subsprites[3639]
		Metaprite_1694:
			.byte 3, 18 @ subspriteCount, unk_01
			.2byte 513 @ plttID
			.4byte 33188 << 5, 3642 << 2 @ .tiles[33188], .subsprites[3642]
		Metaprite_1695:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 513 @ plttID
			.4byte 33206 << 5, 3645 << 2 @ .tiles[33206], .subsprites[3645]
		Metaprite_1696:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 513 @ plttID
			.4byte 33226 << 5, 3647 << 2 @ .tiles[33226], .subsprites[3647]
		Metaprite_1697:
			.byte 3, 28 @ subspriteCount, unk_01
			.2byte 513 @ plttID
			.4byte 33246 << 5, 3649 << 2 @ .tiles[33246], .subsprites[3649]
		Metaprite_1698:
			.byte 3, 18 @ subspriteCount, unk_01
			.2byte 513 @ plttID
			.4byte 33274 << 5, 3652 << 2 @ .tiles[33274], .subsprites[3652]
		Metaprite_1699:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 513 @ plttID
			.4byte 33292 << 5, 3655 << 2 @ .tiles[33292], .subsprites[3655]
		Metaprite_1700:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 513 @ plttID
			.4byte 33312 << 5, 3657 << 2 @ .tiles[33312], .subsprites[3657]
		Metaprite_1701:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 513 @ plttID
			.4byte 33332 << 5, 3659 << 2 @ .tiles[33332], .subsprites[3659]
		Metaprite_1702:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 513 @ plttID
			.4byte 33352 << 5, 3661 << 2 @ .tiles[33352], .subsprites[3661]
		Metaprite_1703:
			.byte 4, 9 @ subspriteCount, unk_01
			.2byte 513 @ plttID
			.4byte 33372 << 5, 3663 << 2 @ .tiles[33372], .subsprites[3663]
		Metaprite_1704:
			.byte 4, 9 @ subspriteCount, unk_01
			.2byte 513 @ plttID
			.4byte 33381 << 5, 3667 << 2 @ .tiles[33381], .subsprites[3667]
		Metaprite_1705:
			.byte 4, 9 @ subspriteCount, unk_01
			.2byte 513 @ plttID
			.4byte 33390 << 5, 3671 << 2 @ .tiles[33390], .subsprites[3671]
		Metaprite_1706:
			.byte 4, 9 @ subspriteCount, unk_01
			.2byte 513 @ plttID
			.4byte 33399 << 5, 3675 << 2 @ .tiles[33399], .subsprites[3675]
		Metaprite_1707:
			.byte 4, 9 @ subspriteCount, unk_01
			.2byte 513 @ plttID
			.4byte 33408 << 5, 3679 << 2 @ .tiles[33408], .subsprites[3679]
		Metaprite_1708:
			.byte 4, 9 @ subspriteCount, unk_01
			.2byte 513 @ plttID
			.4byte 33417 << 5, 3683 << 2 @ .tiles[33417], .subsprites[3683]
		Metaprite_1709:
			.byte 4, 9 @ subspriteCount, unk_01
			.2byte 513 @ plttID
			.4byte 33426 << 5, 3687 << 2 @ .tiles[33426], .subsprites[3687]
		Metaprite_1710:
			.byte 4, 9 @ subspriteCount, unk_01
			.2byte 513 @ plttID
			.4byte 33435 << 5, 3691 << 2 @ .tiles[33435], .subsprites[3691]
		Metaprite_1711:
			.byte 4, 9 @ subspriteCount, unk_01
			.2byte 513 @ plttID
			.4byte 33444 << 5, 3695 << 2 @ .tiles[33444], .subsprites[3695]
		Metaprite_1712:
			.byte 4, 9 @ subspriteCount, unk_01
			.2byte 513 @ plttID
			.4byte 33453 << 5, 3699 << 2 @ .tiles[33453], .subsprites[3699]
		Metaprite_1713:
			.byte 4, 9 @ subspriteCount, unk_01
			.2byte 513 @ plttID
			.4byte 33462 << 5, 3703 << 2 @ .tiles[33462], .subsprites[3703]
		Metaprite_1714:
			.byte 4, 9 @ subspriteCount, unk_01
			.2byte 513 @ plttID
			.4byte 33471 << 5, 3707 << 2 @ .tiles[33471], .subsprites[3707]
		Metaprite_1715:
			.byte 3, 24 @ subspriteCount, unk_01
			.2byte 513 @ plttID
			.4byte 33480 << 5, 3711 << 2 @ .tiles[33480], .subsprites[3711]
		Metaprite_1716:
			.byte 3, 24 @ subspriteCount, unk_01
			.2byte 513 @ plttID
			.4byte 33504 << 5, 3714 << 2 @ .tiles[33504], .subsprites[3714]
		Metaprite_1717:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 513 @ plttID
			.4byte 33528 << 5, 3717 << 2 @ .tiles[33528], .subsprites[3717]
		Metaprite_1718:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 513 @ plttID
			.4byte 33548 << 5, 3719 << 2 @ .tiles[33548], .subsprites[3719]
		Metaprite_1719:
			.byte 3, 24 @ subspriteCount, unk_01
			.2byte 513 @ plttID
			.4byte 33572 << 5, 3721 << 2 @ .tiles[33572], .subsprites[3721]
		Metaprite_1720:
			.byte 3, 17 @ subspriteCount, unk_01
			.2byte 513 @ plttID
			.4byte 33596 << 5, 3724 << 2 @ .tiles[33596], .subsprites[3724]
		Metaprite_1721:
			.byte 3, 24 @ subspriteCount, unk_01
			.2byte 513 @ plttID
			.4byte 33613 << 5, 3727 << 2 @ .tiles[33613], .subsprites[3727]
		Metaprite_1722:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 44 @ plttID
			.4byte 33637 << 5, 3730 << 2 @ .tiles[33637], .subsprites[3730]
		Metaprite_1723:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 44 @ plttID
			.4byte 33653 << 5, 3731 << 2 @ .tiles[33653], .subsprites[3731]
		Metaprite_1724:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 44 @ plttID
			.4byte 33669 << 5, 3732 << 2 @ .tiles[33669], .subsprites[3732]
		Metaprite_1725:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 44 @ plttID
			.4byte 33685 << 5, 3733 << 2 @ .tiles[33685], .subsprites[3733]
		Metaprite_1726:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 44 @ plttID
			.4byte 33701 << 5, 3734 << 2 @ .tiles[33701], .subsprites[3734]
		Metaprite_1727:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 44 @ plttID
			.4byte 33717 << 5, 3735 << 2 @ .tiles[33717], .subsprites[3735]
		Metaprite_1728:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 44 @ plttID
			.4byte 33733 << 5, 3736 << 2 @ .tiles[33733], .subsprites[3736]
		Metaprite_1729:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 44 @ plttID
			.4byte 33749 << 5, 3737 << 2 @ .tiles[33749], .subsprites[3737]
		Metaprite_1730:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 44 @ plttID
			.4byte 33765 << 5, 3738 << 2 @ .tiles[33765], .subsprites[3738]
		Metaprite_1731:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 44 @ plttID
			.4byte 33781 << 5, 3739 << 2 @ .tiles[33781], .subsprites[3739]
		Metaprite_1732:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 44 @ plttID
			.4byte 33797 << 5, 3740 << 2 @ .tiles[33797], .subsprites[3740]
		Metaprite_1733:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 44 @ plttID
			.4byte 33813 << 5, 3741 << 2 @ .tiles[33813], .subsprites[3741]
		Metaprite_1734:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 44 @ plttID
			.4byte 33829 << 5, 3742 << 2 @ .tiles[33829], .subsprites[3742]
		Metaprite_1735:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 44 @ plttID
			.4byte 33833 << 5, 3743 << 2 @ .tiles[33833], .subsprites[3743]
		Metaprite_1736:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 44 @ plttID
			.4byte 33837 << 5, 3744 << 2 @ .tiles[33837], .subsprites[3744]
		Metaprite_1737:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 519 @ plttID
			.4byte 33841 << 5, 3745 << 2 @ .tiles[33841], .subsprites[3745]
		Metaprite_1738:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 519 @ plttID
			.4byte 33861 << 5, 3747 << 2 @ .tiles[33861], .subsprites[3747]
		Metaprite_1739:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 519 @ plttID
			.4byte 33881 << 5, 3749 << 2 @ .tiles[33881], .subsprites[3749]
		Metaprite_1740:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 519 @ plttID
			.4byte 33897 << 5, 3750 << 2 @ .tiles[33897], .subsprites[3750]
		Metaprite_1741:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 519 @ plttID
			.4byte 33917 << 5, 3752 << 2 @ .tiles[33917], .subsprites[3752]
		Metaprite_1742:
			.byte 3, 24 @ subspriteCount, unk_01
			.2byte 519 @ plttID
			.4byte 33937 << 5, 3754 << 2 @ .tiles[33937], .subsprites[3754]
		Metaprite_1743:
			.byte 4, 30 @ subspriteCount, unk_01
			.2byte 519 @ plttID
			.4byte 33961 << 5, 3757 << 2 @ .tiles[33961], .subsprites[3757]
		Metaprite_1744:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 519 @ plttID
			.4byte 33991 << 5, 3761 << 2 @ .tiles[33991], .subsprites[3761]
		Metaprite_1745:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 519 @ plttID
			.4byte 34011 << 5, 3763 << 2 @ .tiles[34011], .subsprites[3763]
		Metaprite_1746:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 519 @ plttID
			.4byte 34031 << 5, 3765 << 2 @ .tiles[34031], .subsprites[3765]
		Metaprite_1747:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 519 @ plttID
			.4byte 34047 << 5, 3766 << 2 @ .tiles[34047], .subsprites[3766]
		Metaprite_1748:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 519 @ plttID
			.4byte 34067 << 5, 3768 << 2 @ .tiles[34067], .subsprites[3768]
		Metaprite_1749:
			.byte 3, 24 @ subspriteCount, unk_01
			.2byte 519 @ plttID
			.4byte 34087 << 5, 3770 << 2 @ .tiles[34087], .subsprites[3770]
		Metaprite_1750:
			.byte 4, 30 @ subspriteCount, unk_01
			.2byte 519 @ plttID
			.4byte 34111 << 5, 3773 << 2 @ .tiles[34111], .subsprites[3773]
		Metaprite_1751:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 519 @ plttID
			.4byte 34141 << 5, 3777 << 2 @ .tiles[34141], .subsprites[3777]
		Metaprite_1752:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 519 @ plttID
			.4byte 34161 << 5, 3779 << 2 @ .tiles[34161], .subsprites[3779]
		Metaprite_1753:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 519 @ plttID
			.4byte 34181 << 5, 3781 << 2 @ .tiles[34181], .subsprites[3781]
		Metaprite_1754:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 519 @ plttID
			.4byte 34197 << 5, 3782 << 2 @ .tiles[34197], .subsprites[3782]
		Metaprite_1755:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 519 @ plttID
			.4byte 34217 << 5, 3784 << 2 @ .tiles[34217], .subsprites[3784]
		Metaprite_1756:
			.byte 4, 30 @ subspriteCount, unk_01
			.2byte 519 @ plttID
			.4byte 34237 << 5, 3786 << 2 @ .tiles[34237], .subsprites[3786]
		Metaprite_1757:
			.byte 4, 30 @ subspriteCount, unk_01
			.2byte 519 @ plttID
			.4byte 34267 << 5, 3790 << 2 @ .tiles[34267], .subsprites[3790]
		Metaprite_1758:
			.byte 2, 18 @ subspriteCount, unk_01
			.2byte 519 @ plttID
			.4byte 34297 << 5, 3794 << 2 @ .tiles[34297], .subsprites[3794]
		Metaprite_1759:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 519 @ plttID
			.4byte 34315 << 5, 3796 << 2 @ .tiles[34315], .subsprites[3796]
		Metaprite_1760:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 519 @ plttID
			.4byte 34335 << 5, 3798 << 2 @ .tiles[34335], .subsprites[3798]
		Metaprite_1761:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 519 @ plttID
			.4byte 34355 << 5, 3800 << 2 @ .tiles[34355], .subsprites[3800]
		Metaprite_1762:
			.byte 2, 18 @ subspriteCount, unk_01
			.2byte 519 @ plttID
			.4byte 34375 << 5, 3802 << 2 @ .tiles[34375], .subsprites[3802]
		Metaprite_1763:
			.byte 3, 24 @ subspriteCount, unk_01
			.2byte 519 @ plttID
			.4byte 34393 << 5, 3804 << 2 @ .tiles[34393], .subsprites[3804]
		Metaprite_1764:
			.byte 4, 36 @ subspriteCount, unk_01
			.2byte 519 @ plttID
			.4byte 34417 << 5, 3807 << 2 @ .tiles[34417], .subsprites[3807]
		Metaprite_1765:
			.byte 2, 18 @ subspriteCount, unk_01
			.2byte 519 @ plttID
			.4byte 34453 << 5, 3811 << 2 @ .tiles[34453], .subsprites[3811]
		Metaprite_1766:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 519 @ plttID
			.4byte 34471 << 5, 3813 << 2 @ .tiles[34471], .subsprites[3813]
		Metaprite_1767:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 519 @ plttID
			.4byte 34491 << 5, 3815 << 2 @ .tiles[34491], .subsprites[3815]
		Metaprite_1768:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 519 @ plttID
			.4byte 34511 << 5, 3817 << 2 @ .tiles[34511], .subsprites[3817]
		Metaprite_1769:
			.byte 2, 18 @ subspriteCount, unk_01
			.2byte 519 @ plttID
			.4byte 34531 << 5, 3819 << 2 @ .tiles[34531], .subsprites[3819]
		Metaprite_1770:
			.byte 3, 24 @ subspriteCount, unk_01
			.2byte 519 @ plttID
			.4byte 34549 << 5, 3821 << 2 @ .tiles[34549], .subsprites[3821]
		Metaprite_1771:
			.byte 4, 36 @ subspriteCount, unk_01
			.2byte 519 @ plttID
			.4byte 34573 << 5, 3824 << 2 @ .tiles[34573], .subsprites[3824]
		Metaprite_1772:
			.byte 3, 22 @ subspriteCount, unk_01
			.2byte 519 @ plttID
			.4byte 34609 << 5, 3828 << 2 @ .tiles[34609], .subsprites[3828]
		Metaprite_1773:
			.byte 3, 20 @ subspriteCount, unk_01
			.2byte 519 @ plttID
			.4byte 34631 << 5, 3831 << 2 @ .tiles[34631], .subsprites[3831]
		Metaprite_1774:
			.byte 4, 30 @ subspriteCount, unk_01
			.2byte 519 @ plttID
			.4byte 34651 << 5, 3834 << 2 @ .tiles[34651], .subsprites[3834]
		Metaprite_1775:
			.byte 3, 19 @ subspriteCount, unk_01
			.2byte 519 @ plttID
			.4byte 34681 << 5, 3838 << 2 @ .tiles[34681], .subsprites[3838]
		Metaprite_1776:
			.byte 3, 22 @ subspriteCount, unk_01
			.2byte 519 @ plttID
			.4byte 34700 << 5, 3841 << 2 @ .tiles[34700], .subsprites[3841]
		Metaprite_1777:
			.byte 4, 30 @ subspriteCount, unk_01
			.2byte 519 @ plttID
			.4byte 34722 << 5, 3844 << 2 @ .tiles[34722], .subsprites[3844]
		Metaprite_1778:
			.byte 4, 36 @ subspriteCount, unk_01
			.2byte 519 @ plttID
			.4byte 34752 << 5, 3848 << 2 @ .tiles[34752], .subsprites[3848]
		Metaprite_1779:
			.byte 2, 18 @ subspriteCount, unk_01
			.2byte 519 @ plttID
			.4byte 34788 << 5, 3852 << 2 @ .tiles[34788], .subsprites[3852]
		Metaprite_1780:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 519 @ plttID
			.4byte 34806 << 5, 3854 << 2 @ .tiles[34806], .subsprites[3854]
		Metaprite_1781:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 519 @ plttID
			.4byte 34826 << 5, 3856 << 2 @ .tiles[34826], .subsprites[3856]
		Metaprite_1782:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 519 @ plttID
			.4byte 34846 << 5, 3858 << 2 @ .tiles[34846], .subsprites[3858]
		Metaprite_1783:
			.byte 2, 18 @ subspriteCount, unk_01
			.2byte 519 @ plttID
			.4byte 34866 << 5, 3860 << 2 @ .tiles[34866], .subsprites[3860]
		Metaprite_1784:
			.byte 3, 24 @ subspriteCount, unk_01
			.2byte 519 @ plttID
			.4byte 34884 << 5, 3862 << 2 @ .tiles[34884], .subsprites[3862]
		Metaprite_1785:
			.byte 4, 36 @ subspriteCount, unk_01
			.2byte 519 @ plttID
			.4byte 34908 << 5, 3865 << 2 @ .tiles[34908], .subsprites[3865]
		Metaprite_1786:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 519 @ plttID
			.4byte 34944 << 5, 3869 << 2 @ .tiles[34944], .subsprites[3869]
		Metaprite_1787:
			.byte 3, 24 @ subspriteCount, unk_01
			.2byte 519 @ plttID
			.4byte 34964 << 5, 3871 << 2 @ .tiles[34964], .subsprites[3871]
		Metaprite_1788:
			.byte 4, 18 @ subspriteCount, unk_01
			.2byte 519 @ plttID
			.4byte 34988 << 5, 3874 << 2 @ .tiles[34988], .subsprites[3874]
		Metaprite_1789:
			.byte 4, 25 @ subspriteCount, unk_01
			.2byte 519 @ plttID
			.4byte 35006 << 5, 3878 << 2 @ .tiles[35006], .subsprites[3878]
		Metaprite_1790:
			.byte 3, 16 @ subspriteCount, unk_01
			.2byte 519 @ plttID
			.4byte 35031 << 5, 3882 << 2 @ .tiles[35031], .subsprites[3882]
		Metaprite_1791:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 519 @ plttID
			.4byte 35047 << 5, 3885 << 2 @ .tiles[35047], .subsprites[3885]
		Metaprite_1792:
			.byte 4, 36 @ subspriteCount, unk_01
			.2byte 519 @ plttID
			.4byte 35067 << 5, 3887 << 2 @ .tiles[35067], .subsprites[3887]
		Metaprite_1793:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 519 @ plttID
			.4byte 35103 << 5, 3891 << 2 @ .tiles[35103], .subsprites[3891]
		Metaprite_1794:
			.byte 3, 20 @ subspriteCount, unk_01
			.2byte 519 @ plttID
			.4byte 35127 << 5, 3893 << 2 @ .tiles[35127], .subsprites[3893]
		Metaprite_1795:
			.byte 4, 30 @ subspriteCount, unk_01
			.2byte 519 @ plttID
			.4byte 35147 << 5, 3896 << 2 @ .tiles[35147], .subsprites[3896]
		Metaprite_1796:
			.byte 3, 19 @ subspriteCount, unk_01
			.2byte 519 @ plttID
			.4byte 35177 << 5, 3900 << 2 @ .tiles[35177], .subsprites[3900]
		Metaprite_1797:
			.byte 3, 22 @ subspriteCount, unk_01
			.2byte 519 @ plttID
			.4byte 35196 << 5, 3903 << 2 @ .tiles[35196], .subsprites[3903]
		Metaprite_1798:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 519 @ plttID
			.4byte 35218 << 5, 3906 << 2 @ .tiles[35218], .subsprites[3906]
		Metaprite_1799:
			.byte 3, 20 @ subspriteCount, unk_01
			.2byte 519 @ plttID
			.4byte 35242 << 5, 3908 << 2 @ .tiles[35242], .subsprites[3908]
		Metaprite_1800:
			.byte 4, 30 @ subspriteCount, unk_01
			.2byte 519 @ plttID
			.4byte 35262 << 5, 3911 << 2 @ .tiles[35262], .subsprites[3911]
		Metaprite_1801:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 519 @ plttID
			.4byte 35292 << 5, 3915 << 2 @ .tiles[35292], .subsprites[3915]
		Metaprite_1802:
			.byte 3, 22 @ subspriteCount, unk_01
			.2byte 519 @ plttID
			.4byte 35316 << 5, 3917 << 2 @ .tiles[35316], .subsprites[3917]
		Metaprite_1803:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 529 @ plttID
			.4byte 35338 << 5, 3920 << 2 @ .tiles[35338], .subsprites[3920]
		Metaprite_1804:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 529 @ plttID
			.4byte 35386 << 5, 3923 << 2 @ .tiles[35386], .subsprites[3923]
		Metaprite_1805:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 283 @ plttID
			.4byte 35434 << 5, 3926 << 2 @ .tiles[35434], .subsprites[3926]
		Metaprite_1806:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 283 @ plttID
			.4byte 35482 << 5, 3929 << 2 @ .tiles[35482], .subsprites[3929]
		Metaprite_1807:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 531 @ plttID
			.4byte 35530 << 5, 3932 << 2 @ .tiles[35530], .subsprites[3932]
		Metaprite_1808:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 531 @ plttID
			.4byte 35546 << 5, 3933 << 2 @ .tiles[35546], .subsprites[3933]
		Metaprite_1809:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 531 @ plttID
			.4byte 35562 << 5, 3934 << 2 @ .tiles[35562], .subsprites[3934]
		Metaprite_1810:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 531 @ plttID
			.4byte 35578 << 5, 3935 << 2 @ .tiles[35578], .subsprites[3935]
		Metaprite_1811:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 531 @ plttID
			.4byte 35594 << 5, 3936 << 2 @ .tiles[35594], .subsprites[3936]
		Metaprite_1812:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 531 @ plttID
			.4byte 35610 << 5, 3937 << 2 @ .tiles[35610], .subsprites[3937]
		Metaprite_1813:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 531 @ plttID
			.4byte 35626 << 5, 3938 << 2 @ .tiles[35626], .subsprites[3938]
		Metaprite_1814:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 531 @ plttID
			.4byte 35642 << 5, 3939 << 2 @ .tiles[35642], .subsprites[3939]
		Metaprite_1815:
			.byte 4, 9 @ subspriteCount, unk_01
			.2byte 275 @ plttID
			.4byte 35658 << 5, 3940 << 2 @ .tiles[35658], .subsprites[3940]
		Metaprite_1816:
			.byte 2, 12 @ subspriteCount, unk_01
			.2byte 275 @ plttID
			.4byte 35667 << 5, 3944 << 2 @ .tiles[35667], .subsprites[3944]
		Metaprite_1817:
			.byte 2, 12 @ subspriteCount, unk_01
			.2byte 275 @ plttID
			.4byte 35679 << 5, 3946 << 2 @ .tiles[35679], .subsprites[3946]
		Metaprite_1818:
			.byte 2, 12 @ subspriteCount, unk_01
			.2byte 275 @ plttID
			.4byte 35691 << 5, 3948 << 2 @ .tiles[35691], .subsprites[3948]
		Metaprite_1819:
			.byte 3, 11 @ subspriteCount, unk_01
			.2byte 275 @ plttID
			.4byte 35703 << 5, 3950 << 2 @ .tiles[35703], .subsprites[3950]
		Metaprite_1820:
			.byte 3, 9 @ subspriteCount, unk_01
			.2byte 275 @ plttID
			.4byte 35714 << 5, 3953 << 2 @ .tiles[35714], .subsprites[3953]
		Metaprite_1821:
			.byte 3, 22 @ subspriteCount, unk_01
			.2byte 275 @ plttID
			.4byte 35723 << 5, 3956 << 2 @ .tiles[35723], .subsprites[3956]
		Metaprite_1822:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 275 @ plttID
			.4byte 35745 << 5, 3959 << 2 @ .tiles[35745], .subsprites[3959]
		Metaprite_1823:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 275 @ plttID
			.4byte 35769 << 5, 3961 << 2 @ .tiles[35769], .subsprites[3961]
		Metaprite_1824:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 275 @ plttID
			.4byte 35793 << 5, 3963 << 2 @ .tiles[35793], .subsprites[3963]
		Metaprite_1825:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 275 @ plttID
			.4byte 35817 << 5, 3965 << 2 @ .tiles[35817], .subsprites[3965]
		Metaprite_1826:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 275 @ plttID
			.4byte 35841 << 5, 3967 << 2 @ .tiles[35841], .subsprites[3967]
		Metaprite_1827:
			.byte 1, 8 @ subspriteCount, unk_01
			.2byte 275 @ plttID
			.4byte 35861 << 5, 3969 << 2 @ .tiles[35861], .subsprites[3969]
		Metaprite_1828:
			.byte 2, 9 @ subspriteCount, unk_01
			.2byte 275 @ plttID
			.4byte 35869 << 5, 3970 << 2 @ .tiles[35869], .subsprites[3970]
		Metaprite_1829:
			.byte 3, 24 @ subspriteCount, unk_01
			.2byte 275 @ plttID
			.4byte 35878 << 5, 3972 << 2 @ .tiles[35878], .subsprites[3972]
		Metaprite_1830:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 275 @ plttID
			.4byte 35902 << 5, 3975 << 2 @ .tiles[35902], .subsprites[3975]
		Metaprite_1831:
			.byte 4, 36 @ subspriteCount, unk_01
			.2byte 275 @ plttID
			.4byte 35926 << 5, 3977 << 2 @ .tiles[35926], .subsprites[3977]
		Metaprite_1832:
			.byte 4, 36 @ subspriteCount, unk_01
			.2byte 275 @ plttID
			.4byte 35962 << 5, 3981 << 2 @ .tiles[35962], .subsprites[3981]
		Metaprite_1833:
			.byte 4, 36 @ subspriteCount, unk_01
			.2byte 275 @ plttID
			.4byte 35998 << 5, 3985 << 2 @ .tiles[35998], .subsprites[3985]
		Metaprite_1834:
			.byte 4, 30 @ subspriteCount, unk_01
			.2byte 275 @ plttID
			.4byte 36034 << 5, 3989 << 2 @ .tiles[36034], .subsprites[3989]
		Metaprite_1835:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 547 @ plttID
			.4byte 36064 << 5, 3993 << 2 @ .tiles[36064], .subsprites[3993]
		Metaprite_1836:
			.byte 3, 7 @ subspriteCount, unk_01
			.2byte 547 @ plttID
			.4byte 36080 << 5, 3994 << 2 @ .tiles[36080], .subsprites[3994]
		Metaprite_1837:
			.byte 3, 6 @ subspriteCount, unk_01
			.2byte 547 @ plttID
			.4byte 36087 << 5, 3997 << 2 @ .tiles[36087], .subsprites[3997]
		Metaprite_1838:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 547 @ plttID
			.4byte 36093 << 5, 4000 << 2 @ .tiles[36093], .subsprites[4000]
		Metaprite_1839:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 547 @ plttID
			.4byte 36109 << 5, 4001 << 2 @ .tiles[36109], .subsprites[4001]
		Metaprite_1840:
			.byte 3, 7 @ subspriteCount, unk_01
			.2byte 547 @ plttID
			.4byte 36125 << 5, 4002 << 2 @ .tiles[36125], .subsprites[4002]
		Metaprite_1841:
			.byte 3, 7 @ subspriteCount, unk_01
			.2byte 547 @ plttID
			.4byte 36132 << 5, 4005 << 2 @ .tiles[36132], .subsprites[4005]
		Metaprite_1842:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 547 @ plttID
			.4byte 36139 << 5, 4008 << 2 @ .tiles[36139], .subsprites[4008]
		Metaprite_1843:
			.byte 2, 12 @ subspriteCount, unk_01
			.2byte 547 @ plttID
			.4byte 36155 << 5, 4009 << 2 @ .tiles[36155], .subsprites[4009]
		Metaprite_1844:
			.byte 2, 12 @ subspriteCount, unk_01
			.2byte 547 @ plttID
			.4byte 36167 << 5, 4011 << 2 @ .tiles[36167], .subsprites[4011]
		Metaprite_1845:
			.byte 3, 7 @ subspriteCount, unk_01
			.2byte 547 @ plttID
			.4byte 36179 << 5, 4013 << 2 @ .tiles[36179], .subsprites[4013]
		Metaprite_1846:
			.byte 2, 12 @ subspriteCount, unk_01
			.2byte 547 @ plttID
			.4byte 36186 << 5, 4016 << 2 @ .tiles[36186], .subsprites[4016]
		Metaprite_1847:
			.byte 2, 12 @ subspriteCount, unk_01
			.2byte 547 @ plttID
			.4byte 36198 << 5, 4018 << 2 @ .tiles[36198], .subsprites[4018]
		Metaprite_1848:
			.byte 2, 12 @ subspriteCount, unk_01
			.2byte 547 @ plttID
			.4byte 36210 << 5, 4020 << 2 @ .tiles[36210], .subsprites[4020]
		Metaprite_1849:
			.byte 4, 9 @ subspriteCount, unk_01
			.2byte 547 @ plttID
			.4byte 36222 << 5, 4022 << 2 @ .tiles[36222], .subsprites[4022]
		Metaprite_1850:
			.byte 4, 9 @ subspriteCount, unk_01
			.2byte 547 @ plttID
			.4byte 36231 << 5, 4026 << 2 @ .tiles[36231], .subsprites[4026]
		Metaprite_1851:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 547 @ plttID
			.4byte 36240 << 5, 4030 << 2 @ .tiles[36240], .subsprites[4030]
		Metaprite_1852:
			.byte 2, 12 @ subspriteCount, unk_01
			.2byte 547 @ plttID
			.4byte 36256 << 5, 4031 << 2 @ .tiles[36256], .subsprites[4031]
		Metaprite_1853:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 547 @ plttID
			.4byte 36268 << 5, 4033 << 2 @ .tiles[36268], .subsprites[4033]
		Metaprite_1854:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 547 @ plttID
			.4byte 36284 << 5, 4034 << 2 @ .tiles[36284], .subsprites[4034]
		Metaprite_1855:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 547 @ plttID
			.4byte 36300 << 5, 4035 << 2 @ .tiles[36300], .subsprites[4035]
		Metaprite_1856:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 547 @ plttID
			.4byte 36316 << 5, 4036 << 2 @ .tiles[36316], .subsprites[4036]
		Metaprite_1857:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 547 @ plttID
			.4byte 36332 << 5, 4037 << 2 @ .tiles[36332], .subsprites[4037]
		Metaprite_1858:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 547 @ plttID
			.4byte 36348 << 5, 4038 << 2 @ .tiles[36348], .subsprites[4038]
		Metaprite_1859:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 547 @ plttID
			.4byte 36364 << 5, 4039 << 2 @ .tiles[36364], .subsprites[4039]
		Metaprite_1860:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 547 @ plttID
			.4byte 36380 << 5, 4040 << 2 @ .tiles[36380], .subsprites[4040]
		Metaprite_1861:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 547 @ plttID
			.4byte 36396 << 5, 4041 << 2 @ .tiles[36396], .subsprites[4041]
		Metaprite_1862:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 547 @ plttID
			.4byte 36412 << 5, 4042 << 2 @ .tiles[36412], .subsprites[4042]
		Metaprite_1863:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 547 @ plttID
			.4byte 36428 << 5, 4043 << 2 @ .tiles[36428], .subsprites[4043]
		Metaprite_1864:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 547 @ plttID
			.4byte 36444 << 5, 4044 << 2 @ .tiles[36444], .subsprites[4044]
		Metaprite_1865:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 547 @ plttID
			.4byte 36460 << 5, 4045 << 2 @ .tiles[36460], .subsprites[4045]
		Metaprite_1866:
			.byte 2, 12 @ subspriteCount, unk_01
			.2byte 547 @ plttID
			.4byte 36476 << 5, 4046 << 2 @ .tiles[36476], .subsprites[4046]
		Metaprite_1867:
			.byte 2, 12 @ subspriteCount, unk_01
			.2byte 547 @ plttID
			.4byte 36488 << 5, 4048 << 2 @ .tiles[36488], .subsprites[4048]
		Metaprite_1868:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 547 @ plttID
			.4byte 36500 << 5, 4050 << 2 @ .tiles[36500], .subsprites[4050]
		Metaprite_1869:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 547 @ plttID
			.4byte 36516 << 5, 4051 << 2 @ .tiles[36516], .subsprites[4051]
		Metaprite_1870:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 547 @ plttID
			.4byte 36532 << 5, 4052 << 2 @ .tiles[36532], .subsprites[4052]
		Metaprite_1871:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 547 @ plttID
			.4byte 36548 << 5, 4053 << 2 @ .tiles[36548], .subsprites[4053]
		Metaprite_1872:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 547 @ plttID
			.4byte 36564 << 5, 4054 << 2 @ .tiles[36564], .subsprites[4054]
		Metaprite_1873:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 547 @ plttID
			.4byte 36580 << 5, 4055 << 2 @ .tiles[36580], .subsprites[4055]
		Metaprite_1874:
			.byte 3, 14 @ subspriteCount, unk_01
			.2byte 547 @ plttID
			.4byte 36596 << 5, 4056 << 2 @ .tiles[36596], .subsprites[4056]
		Metaprite_1875:
			.byte 3, 11 @ subspriteCount, unk_01
			.2byte 547 @ plttID
			.4byte 36610 << 5, 4059 << 2 @ .tiles[36610], .subsprites[4059]
		Metaprite_1876:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 547 @ plttID
			.4byte 36621 << 5, 4062 << 2 @ .tiles[36621], .subsprites[4062]
		Metaprite_1877:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 547 @ plttID
			.4byte 36625 << 5, 4063 << 2 @ .tiles[36625], .subsprites[4063]
		Metaprite_1878:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 547 @ plttID
			.4byte 36637 << 5, 4066 << 2 @ .tiles[36637], .subsprites[4066]
		Metaprite_1879:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 547 @ plttID
			.4byte 36649 << 5, 4069 << 2 @ .tiles[36649], .subsprites[4069]
		Metaprite_1880:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 547 @ plttID
			.4byte 36653 << 5, 4070 << 2 @ .tiles[36653], .subsprites[4070]
		Metaprite_1881:
			.byte 2, 12 @ subspriteCount, unk_01
			.2byte 547 @ plttID
			.4byte 36657 << 5, 4071 << 2 @ .tiles[36657], .subsprites[4071]
		Metaprite_1882:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 547 @ plttID
			.4byte 36669 << 5, 4073 << 2 @ .tiles[36669], .subsprites[4073]
		Metaprite_1883:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 547 @ plttID
			.4byte 36685 << 5, 4074 << 2 @ .tiles[36685], .subsprites[4074]
		Metaprite_1884:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 547 @ plttID
			.4byte 36701 << 5, 4075 << 2 @ .tiles[36701], .subsprites[4075]
		Metaprite_1885:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 547 @ plttID
			.4byte 36717 << 5, 4076 << 2 @ .tiles[36717], .subsprites[4076]
		Metaprite_1886:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 547 @ plttID
			.4byte 36733 << 5, 4077 << 2 @ .tiles[36733], .subsprites[4077]
		Metaprite_1887:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 547 @ plttID
			.4byte 36749 << 5, 4078 << 2 @ .tiles[36749], .subsprites[4078]
		Metaprite_1888:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 547 @ plttID
			.4byte 36765 << 5, 4079 << 2 @ .tiles[36765], .subsprites[4079]
		Metaprite_1889:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 547 @ plttID
			.4byte 36781 << 5, 4080 << 2 @ .tiles[36781], .subsprites[4080]
		Metaprite_1890:
			.byte 1, 8 @ subspriteCount, unk_01
			.2byte 547 @ plttID
			.4byte 36797 << 5, 4081 << 2 @ .tiles[36797], .subsprites[4081]
		Metaprite_1891:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 547 @ plttID
			.4byte 36805 << 5, 4082 << 2 @ .tiles[36805], .subsprites[4082]
		Metaprite_1892:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 547 @ plttID
			.4byte 36821 << 5, 4083 << 2 @ .tiles[36821], .subsprites[4083]
		Metaprite_1893:
			.byte 2, 12 @ subspriteCount, unk_01
			.2byte 558 @ plttID
			.4byte 36833 << 5, 4086 << 2 @ .tiles[36833], .subsprites[4086]
		Metaprite_1894:
			.byte 2, 12 @ subspriteCount, unk_01
			.2byte 558 @ plttID
			.4byte 36845 << 5, 4088 << 2 @ .tiles[36845], .subsprites[4088]
		Metaprite_1895:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 558 @ plttID
			.4byte 36857 << 5, 4090 << 2 @ .tiles[36857], .subsprites[4090]
		Metaprite_1896:
			.byte 3, 11 @ subspriteCount, unk_01
			.2byte 558 @ plttID
			.4byte 36873 << 5, 4091 << 2 @ .tiles[36873], .subsprites[4091]
		Metaprite_1897:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 558 @ plttID
			.4byte 36884 << 5, 4094 << 2 @ .tiles[36884], .subsprites[4094]
		Metaprite_1898:
			.byte 3, 11 @ subspriteCount, unk_01
			.2byte 558 @ plttID
			.4byte 36900 << 5, 4095 << 2 @ .tiles[36900], .subsprites[4095]
		Metaprite_1899:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 558 @ plttID
			.4byte 36911 << 5, 4098 << 2 @ .tiles[36911], .subsprites[4098]
		Metaprite_1900:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 558 @ plttID
			.4byte 36927 << 5, 4099 << 2 @ .tiles[36927], .subsprites[4099]
		Metaprite_1901:
			.byte 2, 12 @ subspriteCount, unk_01
			.2byte 558 @ plttID
			.4byte 36943 << 5, 4100 << 2 @ .tiles[36943], .subsprites[4100]
		Metaprite_1902:
			.byte 2, 12 @ subspriteCount, unk_01
			.2byte 558 @ plttID
			.4byte 36955 << 5, 4102 << 2 @ .tiles[36955], .subsprites[4102]
		Metaprite_1903:
			.byte 2, 12 @ subspriteCount, unk_01
			.2byte 558 @ plttID
			.4byte 36967 << 5, 4104 << 2 @ .tiles[36967], .subsprites[4104]
		Metaprite_1904:
			.byte 1, 32 @ subspriteCount, unk_01
			.2byte 559 @ plttID
			.4byte 36979 << 5, 4106 << 2 @ .tiles[36979], .subsprites[4106]
		Metaprite_1905:
			.byte 3, 40 @ subspriteCount, unk_01
			.2byte 559 @ plttID
			.4byte 37011 << 5, 4107 << 2 @ .tiles[37011], .subsprites[4107]
		Metaprite_1906:
			.byte 1, 32 @ subspriteCount, unk_01
			.2byte 559 @ plttID
			.4byte 37051 << 5, 4110 << 2 @ .tiles[37051], .subsprites[4110]
		Metaprite_1907:
			.byte 1, 32 @ subspriteCount, unk_01
			.2byte 559 @ plttID
			.4byte 37083 << 5, 4111 << 2 @ .tiles[37083], .subsprites[4111]
		Metaprite_1908:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 559 @ plttID
			.4byte 37115 << 5, 4112 << 2 @ .tiles[37115], .subsprites[4112]
		Metaprite_1909:
			.byte 4, 18 @ subspriteCount, unk_01
			.2byte 559 @ plttID
			.4byte 37135 << 5, 4114 << 2 @ .tiles[37135], .subsprites[4114]
		Metaprite_1910:
			.byte 1, 32 @ subspriteCount, unk_01
			.2byte 559 @ plttID
			.4byte 37153 << 5, 4118 << 2 @ .tiles[37153], .subsprites[4118]
		Metaprite_1911:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 559 @ plttID
			.4byte 37185 << 5, 4119 << 2 @ .tiles[37185], .subsprites[4119]
		Metaprite_1912:
			.byte 4, 18 @ subspriteCount, unk_01
			.2byte 559 @ plttID
			.4byte 37205 << 5, 4121 << 2 @ .tiles[37205], .subsprites[4121]
		Metaprite_1913:
			.byte 1, 32 @ subspriteCount, unk_01
			.2byte 559 @ plttID
			.4byte 37223 << 5, 4125 << 2 @ .tiles[37223], .subsprites[4125]
		Metaprite_1914:
			.byte 3, 40 @ subspriteCount, unk_01
			.2byte 559 @ plttID
			.4byte 37255 << 5, 4126 << 2 @ .tiles[37255], .subsprites[4126]
		Metaprite_1915:
			.byte 1, 32 @ subspriteCount, unk_01
			.2byte 559 @ plttID
			.4byte 37295 << 5, 4129 << 2 @ .tiles[37295], .subsprites[4129]
		Metaprite_1916:
			.byte 1, 32 @ subspriteCount, unk_01
			.2byte 559 @ plttID
			.4byte 37327 << 5, 4130 << 2 @ .tiles[37327], .subsprites[4130]
		Metaprite_1917:
			.byte 3, 40 @ subspriteCount, unk_01
			.2byte 559 @ plttID
			.4byte 37359 << 5, 4131 << 2 @ .tiles[37359], .subsprites[4131]
		Metaprite_1918:
			.byte 1, 32 @ subspriteCount, unk_01
			.2byte 559 @ plttID
			.4byte 37399 << 5, 4134 << 2 @ .tiles[37399], .subsprites[4134]
		Metaprite_1919:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 37431 << 5, 4135 << 2 @ .tiles[37431], .subsprites[4135]
		Metaprite_1920:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 37447 << 5, 4136 << 2 @ .tiles[37447], .subsprites[4136]
		Metaprite_1921:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 37463 << 5, 4137 << 2 @ .tiles[37463], .subsprites[4137]
		Metaprite_1922:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 37479 << 5, 4138 << 2 @ .tiles[37479], .subsprites[4138]
		Metaprite_1923:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 37495 << 5, 4139 << 2 @ .tiles[37495], .subsprites[4139]
		Metaprite_1924:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 37511 << 5, 4140 << 2 @ .tiles[37511], .subsprites[4140]
		Metaprite_1925:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 37527 << 5, 4141 << 2 @ .tiles[37527], .subsprites[4141]
		Metaprite_1926:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 37543 << 5, 4142 << 2 @ .tiles[37543], .subsprites[4142]
		Metaprite_1927:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 37559 << 5, 4143 << 2 @ .tiles[37559], .subsprites[4143]
		Metaprite_1928:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 37571 << 5, 4146 << 2 @ .tiles[37571], .subsprites[4146]
		Metaprite_1929:
			.byte 3, 14 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 37587 << 5, 4147 << 2 @ .tiles[37587], .subsprites[4147]
		Metaprite_1930:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 37601 << 5, 4150 << 2 @ .tiles[37601], .subsprites[4150]
		Metaprite_1931:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 37617 << 5, 4151 << 2 @ .tiles[37617], .subsprites[4151]
		Metaprite_1932:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 37633 << 5, 4152 << 2 @ .tiles[37633], .subsprites[4152]
		Metaprite_1933:
			.byte 3, 14 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 37649 << 5, 4153 << 2 @ .tiles[37649], .subsprites[4153]
		Metaprite_1934:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 37663 << 5, 4156 << 2 @ .tiles[37663], .subsprites[4156]
		Metaprite_1935:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 37679 << 5, 4157 << 2 @ .tiles[37679], .subsprites[4157]
		Metaprite_1936:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 37695 << 5, 4158 << 2 @ .tiles[37695], .subsprites[4158]
		Metaprite_1937:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 37711 << 5, 4159 << 2 @ .tiles[37711], .subsprites[4159]
		Metaprite_1938:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 37727 << 5, 4160 << 2 @ .tiles[37727], .subsprites[4160]
		Metaprite_1939:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 37743 << 5, 4161 << 2 @ .tiles[37743], .subsprites[4161]
		Metaprite_1940:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 37759 << 5, 4162 << 2 @ .tiles[37759], .subsprites[4162]
		Metaprite_1941:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 37775 << 5, 4163 << 2 @ .tiles[37775], .subsprites[4163]
		Metaprite_1942:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 37791 << 5, 4164 << 2 @ .tiles[37791], .subsprites[4164]
		Metaprite_1943:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 37807 << 5, 4165 << 2 @ .tiles[37807], .subsprites[4165]
		Metaprite_1944:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 37823 << 5, 4166 << 2 @ .tiles[37823], .subsprites[4166]
		Metaprite_1945:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 37839 << 5, 4167 << 2 @ .tiles[37839], .subsprites[4167]
		Metaprite_1946:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 37855 << 5, 4168 << 2 @ .tiles[37855], .subsprites[4168]
		Metaprite_1947:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 37867 << 5, 4171 << 2 @ .tiles[37867], .subsprites[4171]
		Metaprite_1948:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 37879 << 5, 4174 << 2 @ .tiles[37879], .subsprites[4174]
		Metaprite_1949:
			.byte 3, 11 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 37891 << 5, 4177 << 2 @ .tiles[37891], .subsprites[4177]
		Metaprite_1950:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 37902 << 5, 4180 << 2 @ .tiles[37902], .subsprites[4180]
		Metaprite_1951:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 37914 << 5, 4183 << 2 @ .tiles[37914], .subsprites[4183]
		Metaprite_1952:
			.byte 3, 11 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 37918 << 5, 4184 << 2 @ .tiles[37918], .subsprites[4184]
		Metaprite_1953:
			.byte 3, 11 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 37929 << 5, 4187 << 2 @ .tiles[37929], .subsprites[4187]
		Metaprite_1954:
			.byte 2, 10 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 37940 << 5, 4190 << 2 @ .tiles[37940], .subsprites[4190]
		Metaprite_1955:
			.byte 2, 10 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 37950 << 5, 4192 << 2 @ .tiles[37950], .subsprites[4192]
		Metaprite_1956:
			.byte 3, 6 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 37960 << 5, 4194 << 2 @ .tiles[37960], .subsprites[4194]
		Metaprite_1957:
			.byte 2, 6 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 37966 << 5, 4197 << 2 @ .tiles[37966], .subsprites[4197]
		Metaprite_1958:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 37972 << 5, 4199 << 2 @ .tiles[37972], .subsprites[4199]
		Metaprite_1959:
			.byte 3, 32 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 37992 << 5, 4201 << 2 @ .tiles[37992], .subsprites[4201]
		Metaprite_1960:
			.byte 4, 36 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 38024 << 5, 4204 << 2 @ .tiles[38024], .subsprites[4204]
		Metaprite_1961:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 38060 << 5, 4208 << 2 @ .tiles[38060], .subsprites[4208]
		Metaprite_1962:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 38108 << 5, 4211 << 2 @ .tiles[38108], .subsprites[4211]
		Metaprite_1963:
			.byte 3, 7 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 38156 << 5, 4214 << 2 @ .tiles[38156], .subsprites[4214]
		Metaprite_1964:
			.byte 3, 19 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 38163 << 5, 4217 << 2 @ .tiles[38163], .subsprites[4217]
		Metaprite_1965:
			.byte 3, 28 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 38182 << 5, 4220 << 2 @ .tiles[38182], .subsprites[4220]
		Metaprite_1966:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 38210 << 5, 4223 << 2 @ .tiles[38210], .subsprites[4223]
		Metaprite_1967:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 38258 << 5, 4226 << 2 @ .tiles[38258], .subsprites[4226]
		Metaprite_1968:
			.byte 1, 64 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 38306 << 5, 4229 << 2 @ .tiles[38306], .subsprites[4229]
		Metaprite_1969:
			.byte 3, 13 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 38370 << 5, 4230 << 2 @ .tiles[38370], .subsprites[4230]
		Metaprite_1970:
			.byte 4, 30 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 38383 << 5, 4233 << 2 @ .tiles[38383], .subsprites[4233]
		Metaprite_1971:
			.byte 4, 30 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 38413 << 5, 4237 << 2 @ .tiles[38413], .subsprites[4237]
		Metaprite_1972:
			.byte 4, 36 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 38443 << 5, 4241 << 2 @ .tiles[38443], .subsprites[4241]
		Metaprite_1973:
			.byte 4, 30 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 38479 << 5, 4245 << 2 @ .tiles[38479], .subsprites[4245]
		Metaprite_1974:
			.byte 4, 30 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 38509 << 5, 4249 << 2 @ .tiles[38509], .subsprites[4249]
		Metaprite_1975:
			.byte 4, 36 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 38539 << 5, 4253 << 2 @ .tiles[38539], .subsprites[4253]
		Metaprite_1976:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 38575 << 5, 4257 << 2 @ .tiles[38575], .subsprites[4257]
		Metaprite_1977:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 38579 << 5, 4258 << 2 @ .tiles[38579], .subsprites[4258]
		Metaprite_1978:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 38583 << 5, 4259 << 2 @ .tiles[38583], .subsprites[4259]
		Metaprite_1979:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 38587 << 5, 4260 << 2 @ .tiles[38587], .subsprites[4260]
		Metaprite_1980:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 38591 << 5, 4261 << 2 @ .tiles[38591], .subsprites[4261]
		Metaprite_1981:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 38595 << 5, 4262 << 2 @ .tiles[38595], .subsprites[4262]
		Metaprite_1982:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 38599 << 5, 4263 << 2 @ .tiles[38599], .subsprites[4263]
		Metaprite_1983:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 38603 << 5, 4264 << 2 @ .tiles[38603], .subsprites[4264]
		Metaprite_1984:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 38607 << 5, 4265 << 2 @ .tiles[38607], .subsprites[4265]
		Metaprite_1985:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 38611 << 5, 4266 << 2 @ .tiles[38611], .subsprites[4266]
		Metaprite_1986:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 38615 << 5, 4267 << 2 @ .tiles[38615], .subsprites[4267]
		Metaprite_1987:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 38619 << 5, 4268 << 2 @ .tiles[38619], .subsprites[4268]
		Metaprite_1988:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 38623 << 5, 4269 << 2 @ .tiles[38623], .subsprites[4269]
		Metaprite_1989:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 38627 << 5, 4270 << 2 @ .tiles[38627], .subsprites[4270]
		Metaprite_1990:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 38631 << 5, 4271 << 2 @ .tiles[38631], .subsprites[4271]
		Metaprite_1991:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 38635 << 5, 4272 << 2 @ .tiles[38635], .subsprites[4272]
		Metaprite_1992:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 38639 << 5, 4273 << 2 @ .tiles[38639], .subsprites[4273]
		Metaprite_1993:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 38643 << 5, 4274 << 2 @ .tiles[38643], .subsprites[4274]
		Metaprite_1994:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 38647 << 5, 4275 << 2 @ .tiles[38647], .subsprites[4275]
		Metaprite_1995:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 38651 << 5, 4276 << 2 @ .tiles[38651], .subsprites[4276]
		Metaprite_1996:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 38655 << 5, 4277 << 2 @ .tiles[38655], .subsprites[4277]
		Metaprite_1997:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 38659 << 5, 4278 << 2 @ .tiles[38659], .subsprites[4278]
		Metaprite_1998:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 38660 << 5, 4279 << 2 @ .tiles[38660], .subsprites[4279]
		Metaprite_1999:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 38661 << 5, 4280 << 2 @ .tiles[38661], .subsprites[4280]
		Metaprite_2000:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 38662 << 5, 4281 << 2 @ .tiles[38662], .subsprites[4281]
		Metaprite_2001:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 38663 << 5, 4282 << 2 @ .tiles[38663], .subsprites[4282]
		Metaprite_2002:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 38664 << 5, 4283 << 2 @ .tiles[38664], .subsprites[4283]
		Metaprite_2003:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 38665 << 5, 4284 << 2 @ .tiles[38665], .subsprites[4284]
		Metaprite_2004:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 38666 << 5, 4285 << 2 @ .tiles[38666], .subsprites[4285]
		Metaprite_2005:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 38667 << 5, 4286 << 2 @ .tiles[38667], .subsprites[4286]
		Metaprite_2006:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 38668 << 5, 4287 << 2 @ .tiles[38668], .subsprites[4287]
		Metaprite_2007:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 38669 << 5, 4288 << 2 @ .tiles[38669], .subsprites[4288]
		Metaprite_2008:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 38670 << 5, 4289 << 2 @ .tiles[38670], .subsprites[4289]
		Metaprite_2009:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 38671 << 5, 4290 << 2 @ .tiles[38671], .subsprites[4290]
		Metaprite_2010:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 561 @ plttID
			.4byte 38672 << 5, 4291 << 2 @ .tiles[38672], .subsprites[4291]
		Metaprite_2011:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 573 @ plttID
			.4byte 38673 << 5, 4292 << 2 @ .tiles[38673], .subsprites[4292]
		Metaprite_2012:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 573 @ plttID
			.4byte 38721 << 5, 4295 << 2 @ .tiles[38721], .subsprites[4295]
		Metaprite_2013:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 573 @ plttID
			.4byte 38733 << 5, 4298 << 2 @ .tiles[38733], .subsprites[4298]
		Metaprite_2014:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 38734 << 5, 4299 << 2 @ .tiles[38734], .subsprites[4299]
		Metaprite_2015:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 38782 << 5, 4302 << 2 @ .tiles[38782], .subsprites[4302]
		Metaprite_2016:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 38783 << 5, 4303 << 2 @ .tiles[38783], .subsprites[4303]
		Metaprite_2017:
			.byte 4, 30 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 38831 << 5, 4306 << 2 @ .tiles[38831], .subsprites[4306]
		Metaprite_2018:
			.byte 4, 30 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 38861 << 5, 4310 << 2 @ .tiles[38861], .subsprites[4310]
		Metaprite_2019:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 38891 << 5, 4314 << 2 @ .tiles[38891], .subsprites[4314]
		Metaprite_2020:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 38939 << 5, 4317 << 2 @ .tiles[38939], .subsprites[4317]
		Metaprite_2021:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 38987 << 5, 4320 << 2 @ .tiles[38987], .subsprites[4320]
		Metaprite_2022:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 39035 << 5, 4323 << 2 @ .tiles[39035], .subsprites[4323]
		Metaprite_2023:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 39083 << 5, 4326 << 2 @ .tiles[39083], .subsprites[4326]
		Metaprite_2024:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 39131 << 5, 4329 << 2 @ .tiles[39131], .subsprites[4329]
		Metaprite_2025:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 39179 << 5, 4332 << 2 @ .tiles[39179], .subsprites[4332]
		Metaprite_2026:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 39227 << 5, 4335 << 2 @ .tiles[39227], .subsprites[4335]
		Metaprite_2027:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 39275 << 5, 4338 << 2 @ .tiles[39275], .subsprites[4338]
		Metaprite_2028:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 39323 << 5, 4341 << 2 @ .tiles[39323], .subsprites[4341]
		Metaprite_2029:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 39371 << 5, 4344 << 2 @ .tiles[39371], .subsprites[4344]
		Metaprite_2030:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 577 @ plttID
			.4byte 39419 << 5, 4347 << 2 @ .tiles[39419], .subsprites[4347]
		Metaprite_2031:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 577 @ plttID
			.4byte 39467 << 5, 4350 << 2 @ .tiles[39467], .subsprites[4350]
		Metaprite_2032:
			.byte 4, 36 @ subspriteCount, unk_01
			.2byte 577 @ plttID
			.4byte 39515 << 5, 4353 << 2 @ .tiles[39515], .subsprites[4353]
		Metaprite_2033:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 577 @ plttID
			.4byte 39551 << 5, 4357 << 2 @ .tiles[39551], .subsprites[4357]
		Metaprite_2034:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 593 @ plttID
			.4byte 39563 << 5, 4360 << 2 @ .tiles[39563], .subsprites[4360]
		Metaprite_2035:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 39611 << 5, 4363 << 2 @ .tiles[39611], .subsprites[4363]
		Metaprite_2036:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 39659 << 5, 4366 << 2 @ .tiles[39659], .subsprites[4366]
		Metaprite_2037:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 39707 << 5, 4369 << 2 @ .tiles[39707], .subsprites[4369]
		Metaprite_2038:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 39755 << 5, 4372 << 2 @ .tiles[39755], .subsprites[4372]
		Metaprite_2039:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 39803 << 5, 4375 << 2 @ .tiles[39803], .subsprites[4375]
		Metaprite_2040:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 39851 << 5, 4378 << 2 @ .tiles[39851], .subsprites[4378]
		Metaprite_2041:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 39899 << 5, 4381 << 2 @ .tiles[39899], .subsprites[4381]
		Metaprite_2042:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 39947 << 5, 4384 << 2 @ .tiles[39947], .subsprites[4384]
		Metaprite_2043:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 39995 << 5, 4387 << 2 @ .tiles[39995], .subsprites[4387]
		Metaprite_2044:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 40043 << 5, 4390 << 2 @ .tiles[40043], .subsprites[4390]
		Metaprite_2045:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 40091 << 5, 4393 << 2 @ .tiles[40091], .subsprites[4393]
		Metaprite_2046:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 40139 << 5, 4396 << 2 @ .tiles[40139], .subsprites[4396]
		Metaprite_2047:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 40140 << 5, 4397 << 2 @ .tiles[40140], .subsprites[4397]
		Metaprite_2048:
			.byte 4, 36 @ subspriteCount, unk_01
			.2byte 594 @ plttID
			.4byte 40188 << 5, 4400 << 2 @ .tiles[40188], .subsprites[4400]
		Metaprite_2049:
			.byte 2, 5 @ subspriteCount, unk_01
			.2byte 610 @ plttID
			.4byte 40224 << 5, 4404 << 2 @ .tiles[40224], .subsprites[4404]
		Metaprite_2050:
			.byte 2, 5 @ subspriteCount, unk_01
			.2byte 610 @ plttID
			.4byte 40229 << 5, 4406 << 2 @ .tiles[40229], .subsprites[4406]
		Metaprite_2051:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 610 @ plttID
			.4byte 40234 << 5, 4408 << 2 @ .tiles[40234], .subsprites[4408]
		Metaprite_2052:
			.byte 2, 5 @ subspriteCount, unk_01
			.2byte 610 @ plttID
			.4byte 40238 << 5, 4409 << 2 @ .tiles[40238], .subsprites[4409]
		Metaprite_2053:
			.byte 2, 5 @ subspriteCount, unk_01
			.2byte 610 @ plttID
			.4byte 40243 << 5, 4411 << 2 @ .tiles[40243], .subsprites[4411]
		Metaprite_2054:
			.byte 2, 5 @ subspriteCount, unk_01
			.2byte 610 @ plttID
			.4byte 40248 << 5, 4413 << 2 @ .tiles[40248], .subsprites[4413]
		Metaprite_2055:
			.byte 3, 6 @ subspriteCount, unk_01
			.2byte 610 @ plttID
			.4byte 40253 << 5, 4415 << 2 @ .tiles[40253], .subsprites[4415]
		Metaprite_2056:
			.byte 2, 5 @ subspriteCount, unk_01
			.2byte 610 @ plttID
			.4byte 40259 << 5, 4418 << 2 @ .tiles[40259], .subsprites[4418]
		Metaprite_2057:
			.byte 2, 5 @ subspriteCount, unk_01
			.2byte 610 @ plttID
			.4byte 40264 << 5, 4420 << 2 @ .tiles[40264], .subsprites[4420]
		Metaprite_2058:
			.byte 2, 6 @ subspriteCount, unk_01
			.2byte 610 @ plttID
			.4byte 40269 << 5, 4422 << 2 @ .tiles[40269], .subsprites[4422]
		Metaprite_2059:
			.byte 2, 5 @ subspriteCount, unk_01
			.2byte 610 @ plttID
			.4byte 40275 << 5, 4424 << 2 @ .tiles[40275], .subsprites[4424]
		Metaprite_2060:
			.byte 2, 5 @ subspriteCount, unk_01
			.2byte 610 @ plttID
			.4byte 40280 << 5, 4426 << 2 @ .tiles[40280], .subsprites[4426]
		Metaprite_2061:
			.byte 2, 5 @ subspriteCount, unk_01
			.2byte 610 @ plttID
			.4byte 40285 << 5, 4428 << 2 @ .tiles[40285], .subsprites[4428]
		Metaprite_2062:
			.byte 2, 5 @ subspriteCount, unk_01
			.2byte 610 @ plttID
			.4byte 40290 << 5, 4430 << 2 @ .tiles[40290], .subsprites[4430]
		Metaprite_2063:
			.byte 2, 5 @ subspriteCount, unk_01
			.2byte 610 @ plttID
			.4byte 40295 << 5, 4432 << 2 @ .tiles[40295], .subsprites[4432]
		Metaprite_2064:
			.byte 2, 5 @ subspriteCount, unk_01
			.2byte 610 @ plttID
			.4byte 40300 << 5, 4434 << 2 @ .tiles[40300], .subsprites[4434]
		Metaprite_2065:
			.byte 2, 40 @ subspriteCount, unk_01
			.2byte 626 @ plttID
			.4byte 40305 << 5, 4436 << 2 @ .tiles[40305], .subsprites[4436]
		Metaprite_2066:
			.byte 2, 9 @ subspriteCount, unk_01
			.2byte 626 @ plttID
			.4byte 40345 << 5, 4438 << 2 @ .tiles[40345], .subsprites[4438]
		Metaprite_2067:
			.byte 1, 8 @ subspriteCount, unk_01
			.2byte 44 @ plttID
			.4byte 40354 << 5, 4440 << 2 @ .tiles[40354], .subsprites[4440]
		Metaprite_2068:
			.byte 1, 8 @ subspriteCount, unk_01
			.2byte 44 @ plttID
			.4byte 40362 << 5, 4441 << 2 @ .tiles[40362], .subsprites[4441]
		Metaprite_2069:
			.byte 1, 8 @ subspriteCount, unk_01
			.2byte 44 @ plttID
			.4byte 40370 << 5, 4442 << 2 @ .tiles[40370], .subsprites[4442]
		Metaprite_2070:
			.byte 1, 8 @ subspriteCount, unk_01
			.2byte 44 @ plttID
			.4byte 40378 << 5, 4443 << 2 @ .tiles[40378], .subsprites[4443]
		Metaprite_2071:
			.byte 1, 8 @ subspriteCount, unk_01
			.2byte 44 @ plttID
			.4byte 40386 << 5, 4444 << 2 @ .tiles[40386], .subsprites[4444]
		Metaprite_2072:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 634 @ plttID
			.4byte 40394 << 5, 4445 << 2 @ .tiles[40394], .subsprites[4445]
		Metaprite_2073:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 634 @ plttID
			.4byte 40398 << 5, 4446 << 2 @ .tiles[40398], .subsprites[4446]
		Metaprite_2074:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 634 @ plttID
			.4byte 40402 << 5, 4447 << 2 @ .tiles[40402], .subsprites[4447]
		Metaprite_2075:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 634 @ plttID
			.4byte 40406 << 5, 4448 << 2 @ .tiles[40406], .subsprites[4448]
		Metaprite_2076:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 634 @ plttID
			.4byte 40410 << 5, 4449 << 2 @ .tiles[40410], .subsprites[4449]
		Metaprite_2077:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 634 @ plttID
			.4byte 40414 << 5, 4450 << 2 @ .tiles[40414], .subsprites[4450]
		Metaprite_2078:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 634 @ plttID
			.4byte 40418 << 5, 4451 << 2 @ .tiles[40418], .subsprites[4451]
		Metaprite_2079:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 634 @ plttID
			.4byte 40422 << 5, 4452 << 2 @ .tiles[40422], .subsprites[4452]
		Metaprite_2080:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 634 @ plttID
			.4byte 40426 << 5, 4453 << 2 @ .tiles[40426], .subsprites[4453]
		Metaprite_2081:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 634 @ plttID
			.4byte 40430 << 5, 4454 << 2 @ .tiles[40430], .subsprites[4454]
		Metaprite_2082:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 634 @ plttID
			.4byte 40434 << 5, 4455 << 2 @ .tiles[40434], .subsprites[4455]
		Metaprite_2083:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 634 @ plttID
			.4byte 40438 << 5, 4456 << 2 @ .tiles[40438], .subsprites[4456]
		Metaprite_2084:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 634 @ plttID
			.4byte 40442 << 5, 4457 << 2 @ .tiles[40442], .subsprites[4457]
		Metaprite_2085:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 634 @ plttID
			.4byte 40446 << 5, 4458 << 2 @ .tiles[40446], .subsprites[4458]
		Metaprite_2086:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 634 @ plttID
			.4byte 40450 << 5, 4459 << 2 @ .tiles[40450], .subsprites[4459]
		Metaprite_2087:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 634 @ plttID
			.4byte 40454 << 5, 4460 << 2 @ .tiles[40454], .subsprites[4460]
		Metaprite_2088:
			.byte 4, 36 @ subspriteCount, unk_01
			.2byte 287 @ plttID
			.4byte 40458 << 5, 4461 << 2 @ .tiles[40458], .subsprites[4461]
		Metaprite_2089:
			.byte 4, 36 @ subspriteCount, unk_01
			.2byte 287 @ plttID
			.4byte 40494 << 5, 4465 << 2 @ .tiles[40494], .subsprites[4465]
		Metaprite_2090:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 635 @ plttID
			.4byte 40530 << 5, 4469 << 2 @ .tiles[40530], .subsprites[4469]
		Metaprite_2091:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 635 @ plttID
			.4byte 40546 << 5, 4470 << 2 @ .tiles[40546], .subsprites[4470]
		Metaprite_2092:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 635 @ plttID
			.4byte 40570 << 5, 4472 << 2 @ .tiles[40570], .subsprites[4472]
		Metaprite_2093:
			.byte 4, 36 @ subspriteCount, unk_01
			.2byte 642 @ plttID
			.4byte 40594 << 5, 4474 << 2 @ .tiles[40594], .subsprites[4474]
		Metaprite_2094:
			.byte 4, 36 @ subspriteCount, unk_01
			.2byte 642 @ plttID
			.4byte 40630 << 5, 4478 << 2 @ .tiles[40630], .subsprites[4478]
		Metaprite_2095:
			.byte 4, 36 @ subspriteCount, unk_01
			.2byte 642 @ plttID
			.4byte 40666 << 5, 4482 << 2 @ .tiles[40666], .subsprites[4482]
		Metaprite_2096:
			.byte 4, 36 @ subspriteCount, unk_01
			.2byte 642 @ plttID
			.4byte 40702 << 5, 4486 << 2 @ .tiles[40702], .subsprites[4486]
		Metaprite_2097:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 645 @ plttID
			.4byte 40738 << 5, 4490 << 2 @ .tiles[40738], .subsprites[4490]
		Metaprite_2098:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 645 @ plttID
			.4byte 40750 << 5, 4493 << 2 @ .tiles[40750], .subsprites[4493]
		Metaprite_2099:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 645 @ plttID
			.4byte 40762 << 5, 4496 << 2 @ .tiles[40762], .subsprites[4496]
		Metaprite_2100:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 645 @ plttID
			.4byte 40774 << 5, 4499 << 2 @ .tiles[40774], .subsprites[4499]
		Metaprite_2101:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 645 @ plttID
			.4byte 40786 << 5, 4502 << 2 @ .tiles[40786], .subsprites[4502]
		Metaprite_2102:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 645 @ plttID
			.4byte 40798 << 5, 4505 << 2 @ .tiles[40798], .subsprites[4505]
		Metaprite_2103:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 645 @ plttID
			.4byte 40810 << 5, 4508 << 2 @ .tiles[40810], .subsprites[4508]
		Metaprite_2104:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 645 @ plttID
			.4byte 40822 << 5, 4511 << 2 @ .tiles[40822], .subsprites[4511]
		Metaprite_2105:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 645 @ plttID
			.4byte 40834 << 5, 4514 << 2 @ .tiles[40834], .subsprites[4514]
		Metaprite_2106:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 645 @ plttID
			.4byte 40846 << 5, 4517 << 2 @ .tiles[40846], .subsprites[4517]
		Metaprite_2107:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 645 @ plttID
			.4byte 40858 << 5, 4520 << 2 @ .tiles[40858], .subsprites[4520]
		Metaprite_2108:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 645 @ plttID
			.4byte 40870 << 5, 4523 << 2 @ .tiles[40870], .subsprites[4523]
		Metaprite_2109:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 645 @ plttID
			.4byte 40882 << 5, 4526 << 2 @ .tiles[40882], .subsprites[4526]
		Metaprite_2110:
			.byte 1, 32 @ subspriteCount, unk_01
			.2byte 646 @ plttID
			.4byte 40894 << 5, 4529 << 2 @ .tiles[40894], .subsprites[4529]
		Metaprite_2111:
			.byte 1, 32 @ subspriteCount, unk_01
			.2byte 646 @ plttID
			.4byte 40926 << 5, 4530 << 2 @ .tiles[40926], .subsprites[4530]
		Metaprite_2112:
			.byte 1, 32 @ subspriteCount, unk_01
			.2byte 646 @ plttID
			.4byte 40958 << 5, 4531 << 2 @ .tiles[40958], .subsprites[4531]
		Metaprite_2113:
			.byte 1, 32 @ subspriteCount, unk_01
			.2byte 646 @ plttID
			.4byte 40990 << 5, 4532 << 2 @ .tiles[40990], .subsprites[4532]
		Metaprite_2114:
			.byte 3, 40 @ subspriteCount, unk_01
			.2byte 647 @ plttID
			.4byte 41022 << 5, 4533 << 2 @ .tiles[41022], .subsprites[4533]
		Metaprite_2115:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 647 @ plttID
			.4byte 41062 << 5, 4536 << 2 @ .tiles[41062], .subsprites[4536]
		Metaprite_2116:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 647 @ plttID
			.4byte 41078 << 5, 4537 << 2 @ .tiles[41078], .subsprites[4537]
		Metaprite_2117:
			.byte 3, 14 @ subspriteCount, unk_01
			.2byte 649 @ plttID
			.4byte 41079 << 5, 4538 << 2 @ .tiles[41079], .subsprites[4538]
		Metaprite_2118:
			.byte 3, 14 @ subspriteCount, unk_01
			.2byte 649 @ plttID
			.4byte 41093 << 5, 4541 << 2 @ .tiles[41093], .subsprites[4541]
		Metaprite_2119:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 649 @ plttID
			.4byte 41107 << 5, 4544 << 2 @ .tiles[41107], .subsprites[4544]
		Metaprite_2120:
			.byte 4, 15 @ subspriteCount, unk_01
			.2byte 649 @ plttID
			.4byte 41119 << 5, 4547 << 2 @ .tiles[41119], .subsprites[4547]
		Metaprite_2121:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 649 @ plttID
			.4byte 41134 << 5, 4551 << 2 @ .tiles[41134], .subsprites[4551]
		Metaprite_2122:
			.byte 1, 2 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 41146 << 5, 4554 << 2 @ .tiles[41146], .subsprites[4554]
		Metaprite_2123:
			.byte 1, 4 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 41148 << 5, 4555 << 2 @ .tiles[41148], .subsprites[4555]
		Metaprite_2124:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 41152 << 5, 4556 << 2 @ .tiles[41152], .subsprites[4556]
		Metaprite_2125:
			.byte 2, 12 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 41153 << 5, 4557 << 2 @ .tiles[41153], .subsprites[4557]
		Metaprite_2126:
			.byte 4, 30 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 41165 << 5, 4559 << 2 @ .tiles[41165], .subsprites[4559]
		Metaprite_2127:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 41195 << 5, 4563 << 2 @ .tiles[41195], .subsprites[4563]
		Metaprite_2128:
			.byte 1, 64 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 41243 << 5, 4566 << 2 @ .tiles[41243], .subsprites[4566]
		Metaprite_2129:
			.byte 1, 64 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 41307 << 5, 4567 << 2 @ .tiles[41307], .subsprites[4567]
		Metaprite_2130:
			.byte 1, 64 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 41371 << 5, 4568 << 2 @ .tiles[41371], .subsprites[4568]
		Metaprite_2131:
			.byte 2, 68 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 41435 << 5, 4569 << 2 @ .tiles[41435], .subsprites[4569]
		Metaprite_2132:
			.byte 2, 4 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 41503 << 5, 4571 << 2 @ .tiles[41503], .subsprites[4571]
		Metaprite_2133:
			.byte 1, 2 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 41507 << 5, 4573 << 2 @ .tiles[41507], .subsprites[4573]
		Metaprite_2134:
			.byte 1, 1 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 41509 << 5, 4574 << 2 @ .tiles[41509], .subsprites[4574]
		Metaprite_2135:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 41510 << 5, 4575 << 2 @ .tiles[41510], .subsprites[4575]
		Metaprite_2136:
			.byte 3, 28 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 41526 << 5, 4576 << 2 @ .tiles[41526], .subsprites[4576]
		Metaprite_2137:
			.byte 3, 32 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 41554 << 5, 4579 << 2 @ .tiles[41554], .subsprites[4579]
		Metaprite_2138:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 41586 << 5, 4582 << 2 @ .tiles[41586], .subsprites[4582]
		Metaprite_2139:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 41634 << 5, 4585 << 2 @ .tiles[41634], .subsprites[4585]
		Metaprite_2140:
			.byte 2, 68 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 41682 << 5, 4588 << 2 @ .tiles[41682], .subsprites[4588]
		Metaprite_2141:
			.byte 2, 68 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 41750 << 5, 4590 << 2 @ .tiles[41750], .subsprites[4590]
		Metaprite_2142:
			.byte 2, 12 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 41818 << 5, 4592 << 2 @ .tiles[41818], .subsprites[4592]
		Metaprite_2143:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 41830 << 5, 4594 << 2 @ .tiles[41830], .subsprites[4594]
		Metaprite_2144:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 41846 << 5, 4595 << 2 @ .tiles[41846], .subsprites[4595]
		Metaprite_2145:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 41862 << 5, 4596 << 2 @ .tiles[41862], .subsprites[4596]
		Metaprite_2146:
			.byte 3, 14 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 41878 << 5, 4597 << 2 @ .tiles[41878], .subsprites[4597]
		Metaprite_2147:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 501 @ plttID
			.4byte 41892 << 5, 4600 << 2 @ .tiles[41892], .subsprites[4600]
		Metaprite_2148:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 41908 << 5, 4601 << 2 @ .tiles[41908], .subsprites[4601]
		Metaprite_2149:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 41956 << 5, 4604 << 2 @ .tiles[41956], .subsprites[4604]
		Metaprite_2150:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 42004 << 5, 4607 << 2 @ .tiles[42004], .subsprites[4607]
		Metaprite_2151:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 42052 << 5, 4610 << 2 @ .tiles[42052], .subsprites[4610]
		Metaprite_2152:
			.byte 3, 26 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 42100 << 5, 4613 << 2 @ .tiles[42100], .subsprites[4613]
		Metaprite_2153:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 42126 << 5, 4616 << 2 @ .tiles[42126], .subsprites[4616]
		Metaprite_2154:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 42174 << 5, 4619 << 2 @ .tiles[42174], .subsprites[4619]
		Metaprite_2155:
			.byte 3, 48 @ subspriteCount, unk_01
			.2byte 83 @ plttID
			.4byte 42222 << 5, 4622 << 2 @ .tiles[42222], .subsprites[4622]
		Metaprite_2156:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 650 @ plttID
			.4byte 42270 << 5, 4625 << 2 @ .tiles[42270], .subsprites[4625]
		Metaprite_2157:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 650 @ plttID
			.4byte 42286 << 5, 4626 << 2 @ .tiles[42286], .subsprites[4626]
		Metaprite_2158:
			.byte 2, 24 @ subspriteCount, unk_01
			.2byte 650 @ plttID
			.4byte 42306 << 5, 4628 << 2 @ .tiles[42306], .subsprites[4628]
		Metaprite_2159:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 650 @ plttID
			.4byte 42330 << 5, 4630 << 2 @ .tiles[42330], .subsprites[4630]
		Metaprite_2160:
			.byte 1, 16 @ subspriteCount, unk_01
			.2byte 650 @ plttID
			.4byte 42350 << 5, 4632 << 2 @ .tiles[42350], .subsprites[4632]
		Metaprite_2161:
			.byte 3, 12 @ subspriteCount, unk_01
			.2byte 650 @ plttID
			.4byte 42366 << 5, 4633 << 2 @ .tiles[42366], .subsprites[4633]
		Metaprite_2162:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 650 @ plttID
			.4byte 42378 << 5, 4636 << 2 @ .tiles[42378], .subsprites[4636]
		Metaprite_2163:
			.byte 2, 20 @ subspriteCount, unk_01
			.2byte 650 @ plttID
			.4byte 42398 << 5, 4638 << 2 @ .tiles[42398], .subsprites[4638]
	ActorSpriteFile0_Subsprites:
		Subsprite_0:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -20, -44 @ x, y
		Subsprite_1:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 12, -44 @ x, y
		Subsprite_2:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 12, -12 @ x, y
		Subsprite_3:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -20, -44 @ x, y
		Subsprite_4:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 12, -44 @ x, y
		Subsprite_5:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 12, -12 @ x, y
		Subsprite_6:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -20, -44 @ x, y
		Subsprite_7:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 12, -44 @ x, y
		Subsprite_8:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 12, -12 @ x, y
		Subsprite_9:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -20, -44 @ x, y
		Subsprite_10:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 12, -44 @ x, y
		Subsprite_11:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 12, -12 @ x, y
		Subsprite_12:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -44, -51 @ x, y
		Subsprite_13:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -12, -51 @ x, y
		Subsprite_14:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -12, -19 @ x, y
		Subsprite_15:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -44, -19 @ x, y
		Subsprite_16:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte -12, -19 @ x, y
		Subsprite_17:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_18:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte 0, 0 @ x, y
		Subsprite_19:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte 0, 0 @ x, y
		Subsprite_20:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte 0, 0 @ x, y
		Subsprite_21:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte 0, 0 @ x, y
		Subsprite_22:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_23:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_24:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 8 @ x, y
		Subsprite_25:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_26:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_27:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 8 @ x, y
		Subsprite_28:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_29:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_30:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 8 @ x, y
		Subsprite_31:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -24 @ x, y
		Subsprite_32:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -24, 8 @ x, y
		Subsprite_33:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -24 @ x, y
		Subsprite_34:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 8, 8 @ x, y
		Subsprite_35:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_36:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_37:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_38:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 8 @ x, y
		Subsprite_39:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -24 @ x, y
		Subsprite_40:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -24, 8 @ x, y
		Subsprite_41:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -24 @ x, y
		Subsprite_42:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 8, 8 @ x, y
		Subsprite_43:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -6, -34 @ x, y
		Subsprite_44:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -6, -2 @ x, y
		Subsprite_45:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -6, -42 @ x, y
		Subsprite_46:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -14, -42 @ x, y
		Subsprite_47:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 2, -42 @ x, y
		Subsprite_48:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -14, -10 @ x, y
		Subsprite_49:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 2, -10 @ x, y
		Subsprite_50:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -6, -34 @ x, y
		Subsprite_51:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -6, -2 @ x, y
		Subsprite_52:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -6, -42 @ x, y
		Subsprite_53:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -6, -10 @ x, y
		Subsprite_54:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -6, -42 @ x, y
		Subsprite_55:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -6, -10 @ x, y
		Subsprite_56:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -14, -18 @ x, y
		Subsprite_57:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -14, -34 @ x, y
		Subsprite_58:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 2, -34 @ x, y
		Subsprite_59:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -14, -2 @ x, y
		Subsprite_60:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 2, -2 @ x, y
		Subsprite_61:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -14, -34 @ x, y
		Subsprite_62:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 2, -34 @ x, y
		Subsprite_63:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -14, -2 @ x, y
		Subsprite_64:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 2, -2 @ x, y
		Subsprite_65:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -6, -42 @ x, y
		Subsprite_66:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -6, -10 @ x, y
		Subsprite_67:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte -14, -18 @ x, y
		Subsprite_68:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -6, -42 @ x, y
		Subsprite_69:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -6, -10 @ x, y
		Subsprite_70:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -6, -34 @ x, y
		Subsprite_71:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -6, -2 @ x, y
		Subsprite_72:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -14, -34 @ x, y
		Subsprite_73:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 2, -34 @ x, y
		Subsprite_74:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -14, -2 @ x, y
		Subsprite_75:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 2, -2 @ x, y
		Subsprite_76:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -14, -42 @ x, y
		Subsprite_77:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 2, -42 @ x, y
		Subsprite_78:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -14, -10 @ x, y
		Subsprite_79:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 2, -10 @ x, y
		Subsprite_80:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -6, -42 @ x, y
		Subsprite_81:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -6, -10 @ x, y
		Subsprite_82:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -6, -34 @ x, y
		Subsprite_83:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -6, -2 @ x, y
		Subsprite_84:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -6, -34 @ x, y
		Subsprite_85:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -6, -2 @ x, y
		Subsprite_86:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -6, -42 @ x, y
		Subsprite_87:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -6, -10 @ x, y
		Subsprite_88:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -6, -42 @ x, y
		Subsprite_89:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -6, -10 @ x, y
		Subsprite_90:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte -14, -18 @ x, y
		Subsprite_91:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -14, -34 @ x, y
		Subsprite_92:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 2, -34 @ x, y
		Subsprite_93:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -14, -2 @ x, y
		Subsprite_94:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 2, -2 @ x, y
		Subsprite_95:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -6, -34 @ x, y
		Subsprite_96:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -6, -2 @ x, y
		Subsprite_97:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -6, -42 @ x, y
		Subsprite_98:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -14, -42 @ x, y
		Subsprite_99:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -14, -10 @ x, y
		Subsprite_100:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -6, -34 @ x, y
		Subsprite_101:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -6, -2 @ x, y
		Subsprite_102:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -6, -42 @ x, y
		Subsprite_103:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -6, -34 @ x, y
		Subsprite_104:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -6, -42 @ x, y
		Subsprite_105:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -6, -2 @ x, y
		Subsprite_106:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -14, -42 @ x, y
		Subsprite_107:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 2, -42 @ x, y
		Subsprite_108:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -14, -10 @ x, y
		Subsprite_109:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 2, -10 @ x, y
		Subsprite_110:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -14, -42 @ x, y
		Subsprite_111:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 2, -42 @ x, y
		Subsprite_112:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -14, -10 @ x, y
		Subsprite_113:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 2, -10 @ x, y
		Subsprite_114:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -14, -42 @ x, y
		Subsprite_115:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -14, -10 @ x, y
		Subsprite_116:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -14, -42 @ x, y
		Subsprite_117:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -14, -10 @ x, y
		Subsprite_118:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -6, -42 @ x, y
		Subsprite_119:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -6, -10 @ x, y
		Subsprite_120:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte -14, -26 @ x, y
		Subsprite_121:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -14, -42 @ x, y
		Subsprite_122:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 2, -42 @ x, y
		Subsprite_123:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -14, -10 @ x, y
		Subsprite_124:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 2, -10 @ x, y
		Subsprite_125:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -6, -34 @ x, y
		Subsprite_126:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -6, -2 @ x, y
		Subsprite_127:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte -14, -26 @ x, y
		Subsprite_128:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -6, -26 @ x, y
		Subsprite_129:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte -14, -18 @ x, y
		Subsprite_130:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -14, -26 @ x, y
		Subsprite_131:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 2, -26 @ x, y
		Subsprite_132:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -14, 6 @ x, y
		Subsprite_133:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -14, -42 @ x, y
		Subsprite_134:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -14, -10 @ x, y
		Subsprite_135:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -6, -42 @ x, y
		Subsprite_136:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte -14, -34 @ x, y
		Subsprite_137:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -6, -10 @ x, y
		Subsprite_138:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -6, -42 @ x, y
		Subsprite_139:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte -14, -26 @ x, y
		Subsprite_140:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -6, -10 @ x, y
		Subsprite_141:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -14, -34 @ x, y
		Subsprite_142:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 2, -34 @ x, y
		Subsprite_143:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -14, -2 @ x, y
		Subsprite_144:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 2, -2 @ x, y
		Subsprite_145:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -6, -26 @ x, y
		Subsprite_146:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte -14, -18 @ x, y
		Subsprite_147:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -14, -2 @ x, y
		Subsprite_148:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -6, -26 @ x, y
		Subsprite_149:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte -14, -18 @ x, y
		Subsprite_150:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -14, -2 @ x, y
		Subsprite_151:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -42 @ x, y
		Subsprite_152:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -10 @ x, y
		Subsprite_153:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, -10 @ x, y
		Subsprite_154:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -42 @ x, y
		Subsprite_155:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -10 @ x, y
		Subsprite_156:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte -16, -34 @ x, y
		Subsprite_157:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -42 @ x, y
		Subsprite_158:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -24, -10 @ x, y
		Subsprite_159:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 8, -42 @ x, y
		Subsprite_160:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -34 @ x, y
		Subsprite_161:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, -2 @ x, y
		Subsprite_162:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 16, -34 @ x, y
		Subsprite_163:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -42 @ x, y
		Subsprite_164:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -10 @ x, y
		Subsprite_165:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -16, -42 @ x, y
		Subsprite_166:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 0, -42 @ x, y
		Subsprite_167:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -16, -10 @ x, y
		Subsprite_168:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 0, -10 @ x, y
		Subsprite_169:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -42 @ x, y
		Subsprite_170:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -24, -10 @ x, y
		Subsprite_171:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 8, -42 @ x, y
		Subsprite_172:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -34 @ x, y
		Subsprite_173:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -34 @ x, y
		Subsprite_174:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -24, -2 @ x, y
		Subsprite_175:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -24 @ x, y
		Subsprite_176:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -24, 8 @ x, y
		Subsprite_177:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -24 @ x, y
		Subsprite_178:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 8, 8 @ x, y
		Subsprite_179:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -24 @ x, y
		Subsprite_180:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -24, 8 @ x, y
		Subsprite_181:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 8, -24 @ x, y
		Subsprite_182:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -24 @ x, y
		Subsprite_183:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_184:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 16, -24 @ x, y
		Subsprite_185:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_186:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -24 @ x, y
		Subsprite_187:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_188:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -24, 0 @ x, y
		Subsprite_189:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_190:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte 8, 0 @ x, y
		Subsprite_191:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 0 @ x, y
		Subsprite_192:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_193:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_194:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte 0, 8 @ x, y
		Subsprite_195:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_196:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_197:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_198:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, 8 @ x, y
		Subsprite_199:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte -8, -24 @ x, y
		Subsprite_200:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 0, -8 @ x, y
		Subsprite_201:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte -8, 8 @ x, y
		Subsprite_202:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_203:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 0, -8 @ x, y
		Subsprite_204:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_205:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_206:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_207:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_208:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_209:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_210:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_211:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_212:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -16 @ x, y
		Subsprite_213:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_214:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -24, 16 @ x, y
		Subsprite_215:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte 8, 16 @ x, y
		Subsprite_216:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -40 @ x, y
		Subsprite_217:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -32, -48 @ x, y
		Subsprite_218:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 0, -48 @ x, y
		Subsprite_219:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 0, -16 @ x, y
		Subsprite_220:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -64 @ x, y
		Subsprite_221:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -40 @ x, y
		Subsprite_222:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -40 @ x, y
		Subsprite_223:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -24, -8 @ x, y
		Subsprite_224:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -16, -48 @ x, y
		Subsprite_225:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 0, -48 @ x, y
		Subsprite_226:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_227:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 0, -16 @ x, y
		Subsprite_228:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -40 @ x, y
		Subsprite_229:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -40 @ x, y
		Subsprite_230:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -24, -8 @ x, y
		Subsprite_231:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -16, -48 @ x, y
		Subsprite_232:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 0, -48 @ x, y
		Subsprite_233:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_234:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 0, -16 @ x, y
		Subsprite_235:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -40 @ x, y
		Subsprite_236:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -32, -48 @ x, y
		Subsprite_237:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 0, -48 @ x, y
		Subsprite_238:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 0, -16 @ x, y
		Subsprite_239:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -64 @ x, y
		Subsprite_240:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -40 @ x, y
		Subsprite_241:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -32, -48 @ x, y
		Subsprite_242:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 0, -48 @ x, y
		Subsprite_243:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 0, -16 @ x, y
		Subsprite_244:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -64 @ x, y
		Subsprite_245:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -4, -4 @ x, y
		Subsprite_246:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -4, -4 @ x, y
		Subsprite_247:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -4, -4 @ x, y
		Subsprite_248:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -4, -4 @ x, y
		Subsprite_249:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -40 @ x, y
		Subsprite_250:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 8, -40 @ x, y
		Subsprite_251:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -16, -40 @ x, y
		Subsprite_252:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 16, -40 @ x, y
		Subsprite_253:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 16, -8 @ x, y
		Subsprite_254:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_255:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -24, -16 @ x, y
		Subsprite_256:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_257:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_258:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -13, -25 @ x, y
		Subsprite_259:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -5, -9 @ x, y
		Subsprite_260:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 3, -25 @ x, y
		Subsprite_261:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -13, -25 @ x, y
		Subsprite_262:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -5, -9 @ x, y
		Subsprite_263:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 3, -25 @ x, y
		Subsprite_264:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_265:
			.byte OAM_SIZE_64x64, 0 @ shape, unk_01(always 0)
			.byte -33, -48 @ x, y
		Subsprite_266:
			.byte OAM_SIZE_64x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_267:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_268:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_269:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_270:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 8 @ x, y
		Subsprite_271:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_272:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 8 @ x, y
		Subsprite_273:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, -8 @ x, y
		Subsprite_274:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_275:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 8 @ x, y
		Subsprite_276:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, -8 @ x, y
		Subsprite_277:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_278:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 8 @ x, y
		Subsprite_279:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, -8 @ x, y
		Subsprite_280:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_281:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_282:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 8 @ x, y
		Subsprite_283:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_284:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_285:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 8 @ x, y
		Subsprite_286:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_287:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_288:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 8 @ x, y
		Subsprite_289:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_290:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_291:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_292:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_293:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_294:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_295:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_296:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_297:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_298:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -51 @ x, y
		Subsprite_299:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -51 @ x, y
		Subsprite_300:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -19 @ x, y
		Subsprite_301:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -51 @ x, y
		Subsprite_302:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -51 @ x, y
		Subsprite_303:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -19 @ x, y
		Subsprite_304:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -51 @ x, y
		Subsprite_305:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -51 @ x, y
		Subsprite_306:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -19 @ x, y
		Subsprite_307:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -51 @ x, y
		Subsprite_308:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -51 @ x, y
		Subsprite_309:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -19 @ x, y
		Subsprite_310:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -16 @ x, y
		Subsprite_311:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_312:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -24, 16 @ x, y
		Subsprite_313:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -16 @ x, y
		Subsprite_314:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_315:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -24, 16 @ x, y
		Subsprite_316:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -16 @ x, y
		Subsprite_317:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_318:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -24, 16 @ x, y
		Subsprite_319:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -16 @ x, y
		Subsprite_320:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_321:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -24, 16 @ x, y
		Subsprite_322:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -16 @ x, y
		Subsprite_323:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_324:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -24, 16 @ x, y
		Subsprite_325:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -16 @ x, y
		Subsprite_326:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_327:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -24, 16 @ x, y
		Subsprite_328:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -16 @ x, y
		Subsprite_329:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_330:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -24, 16 @ x, y
		Subsprite_331:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -16 @ x, y
		Subsprite_332:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_333:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -24, 16 @ x, y
		Subsprite_334:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -16 @ x, y
		Subsprite_335:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_336:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -24, 16 @ x, y
		Subsprite_337:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -24 @ x, y
		Subsprite_338:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -24, 8 @ x, y
		Subsprite_339:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -24 @ x, y
		Subsprite_340:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 8, 8 @ x, y
		Subsprite_341:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -24 @ x, y
		Subsprite_342:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -24, 8 @ x, y
		Subsprite_343:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -24 @ x, y
		Subsprite_344:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 8, 8 @ x, y
		Subsprite_345:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -16, -24 @ x, y
		Subsprite_346:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 8, -32 @ x, y
		Subsprite_347:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 0, -32 @ x, y
		Subsprite_348:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, -16 @ x, y
		Subsprite_349:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 8, -32 @ x, y
		Subsprite_350:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 0, -32 @ x, y
		Subsprite_351:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, -16 @ x, y
		Subsprite_352:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 0, -32 @ x, y
		Subsprite_353:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 8, -32 @ x, y
		Subsprite_354:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 0, -24 @ x, y
		Subsprite_355:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, -8 @ x, y
		Subsprite_356:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -32 @ x, y
		Subsprite_357:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -32 @ x, y
		Subsprite_358:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_359:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, -32 @ x, y
		Subsprite_360:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 8, -8 @ x, y
		Subsprite_361:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -8, -32 @ x, y
		Subsprite_362:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -8, -32 @ x, y
		Subsprite_363:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_364:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 16, -32 @ x, y
		Subsprite_365:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_366:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 16, -24 @ x, y
		Subsprite_367:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 24, -24 @ x, y
		Subsprite_368:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 24, -8 @ x, y
		Subsprite_369:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -24 @ x, y
		Subsprite_370:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 24, -16 @ x, y
		Subsprite_371:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 8, -24 @ x, y
		Subsprite_372:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 24, -16 @ x, y
		Subsprite_373:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_374:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_375:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_376:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_377:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 16, 8 @ x, y
		Subsprite_378:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_379:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_380:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 16 @ x, y
		Subsprite_381:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_382:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_383:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 16 @ x, y
		Subsprite_384:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -32 @ x, y
		Subsprite_385:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 8, -32 @ x, y
		Subsprite_386:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, -24 @ x, y
		Subsprite_387:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_388:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 16, -16 @ x, y
		Subsprite_389:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 8, 0 @ x, y
		Subsprite_390:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 8, -8 @ x, y
		Subsprite_391:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, 0 @ x, y
		Subsprite_392:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, 0 @ x, y
		Subsprite_393:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 16 @ x, y
		Subsprite_394:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, -32 @ x, y
		Subsprite_395:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, -32 @ x, y
		Subsprite_396:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 8, -32 @ x, y
		Subsprite_397:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, -32 @ x, y
		Subsprite_398:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 16, -16 @ x, y
		Subsprite_399:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte 16, -16 @ x, y
		Subsprite_400:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 8, 0 @ x, y
		Subsprite_401:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 8, 0 @ x, y
		Subsprite_402:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 0, 8 @ x, y
		Subsprite_403:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 0, 8 @ x, y
		Subsprite_404:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_405:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_406:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_407:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_408:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_409:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -46 @ x, y
		Subsprite_410:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -46 @ x, y
		Subsprite_411:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -14 @ x, y
		Subsprite_412:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -64 @ x, y
		Subsprite_413:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -64 @ x, y
		Subsprite_414:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -32 @ x, y
		Subsprite_415:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -64 @ x, y
		Subsprite_416:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -64 @ x, y
		Subsprite_417:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -32 @ x, y
		Subsprite_418:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_419:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -24, -16 @ x, y
		Subsprite_420:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_421:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_422:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_423:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -24, -16 @ x, y
		Subsprite_424:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_425:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_426:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_427:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -24, -16 @ x, y
		Subsprite_428:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_429:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -7, -14 @ x, y
		Subsprite_430:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -7, -14 @ x, y
		Subsprite_431:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -7, -14 @ x, y
		Subsprite_432:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -7, -14 @ x, y
		Subsprite_433:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -7, -14 @ x, y
		Subsprite_434:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -7, -14 @ x, y
		Subsprite_435:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -7, -14 @ x, y
		Subsprite_436:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -7, -14 @ x, y
		Subsprite_437:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -12, -20 @ x, y
		Subsprite_438:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 4, -20 @ x, y
		Subsprite_439:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -12, -20 @ x, y
		Subsprite_440:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 4, -20 @ x, y
		Subsprite_441:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -12, -20 @ x, y
		Subsprite_442:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 4, -20 @ x, y
		Subsprite_443:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -12, -20 @ x, y
		Subsprite_444:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 4, -20 @ x, y
		Subsprite_445:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -12, -20 @ x, y
		Subsprite_446:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 4, -20 @ x, y
		Subsprite_447:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -12, -20 @ x, y
		Subsprite_448:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 4, -20 @ x, y
		Subsprite_449:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -12, -20 @ x, y
		Subsprite_450:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 4, -20 @ x, y
		Subsprite_451:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -12, -20 @ x, y
		Subsprite_452:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 4, -20 @ x, y
		Subsprite_453:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -12, -20 @ x, y
		Subsprite_454:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 4, -20 @ x, y
		Subsprite_455:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -12, -20 @ x, y
		Subsprite_456:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 4, -20 @ x, y
		Subsprite_457:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -12, -20 @ x, y
		Subsprite_458:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 4, -20 @ x, y
		Subsprite_459:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -12, -20 @ x, y
		Subsprite_460:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 4, -20 @ x, y
		Subsprite_461:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -12, -20 @ x, y
		Subsprite_462:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 4, -20 @ x, y
		Subsprite_463:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -12, -20 @ x, y
		Subsprite_464:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 4, -20 @ x, y
		Subsprite_465:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -12, -20 @ x, y
		Subsprite_466:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 4, -20 @ x, y
		Subsprite_467:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -12, -20 @ x, y
		Subsprite_468:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 4, -20 @ x, y
		Subsprite_469:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_470:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_471:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_472:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_473:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_474:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_475:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_476:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_477:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 0 @ x, y
		Subsprite_478:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, -8 @ x, y
		Subsprite_479:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte 0, 0 @ x, y
		Subsprite_480:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_481:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -16, 0 @ x, y
		Subsprite_482:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 8, 0 @ x, y
		Subsprite_483:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_484:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_485:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_486:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_487:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_488:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_489:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_490:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_491:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 8 @ x, y
		Subsprite_492:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_493:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -4, -4 @ x, y
		Subsprite_494:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -4, -4 @ x, y
		Subsprite_495:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -4, -4 @ x, y
		Subsprite_496:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -4, -4 @ x, y
		Subsprite_497:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -4, -4 @ x, y
		Subsprite_498:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -4, -4 @ x, y
		Subsprite_499:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -4, -4 @ x, y
		Subsprite_500:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -4, -4 @ x, y
		Subsprite_501:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -4, -4 @ x, y
		Subsprite_502:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -4, -4 @ x, y
		Subsprite_503:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -4, -4 @ x, y
		Subsprite_504:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_505:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -24, -16 @ x, y
		Subsprite_506:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_507:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_508:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_509:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -24, -16 @ x, y
		Subsprite_510:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_511:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_512:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -40 @ x, y
		Subsprite_513:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -40 @ x, y
		Subsprite_514:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -24, -8 @ x, y
		Subsprite_515:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte 8, -8 @ x, y
		Subsprite_516:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_517:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -24, -16 @ x, y
		Subsprite_518:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_519:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_520:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_521:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -24, -16 @ x, y
		Subsprite_522:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_523:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_524:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_525:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -24, -16 @ x, y
		Subsprite_526:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_527:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_528:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_529:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -24, -16 @ x, y
		Subsprite_530:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_531:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_532:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_533:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -24, -16 @ x, y
		Subsprite_534:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_535:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_536:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_537:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -24, -16 @ x, y
		Subsprite_538:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_539:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_540:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_541:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_542:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_543:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_544:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_545:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_546:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_547:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_548:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_549:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_550:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_551:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_552:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_553:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_554:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_555:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_556:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_557:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_558:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_559:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_560:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_561:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_562:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_563:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_564:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_565:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_566:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_567:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_568:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_569:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_570:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_571:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_572:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_573:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_574:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_575:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_576:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_577:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_578:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_579:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_580:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_581:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_582:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -13, -12 @ x, y
		Subsprite_583:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -5, 4 @ x, y
		Subsprite_584:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 3, -12 @ x, y
		Subsprite_585:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -21, -12 @ x, y
		Subsprite_586:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 11, -12 @ x, y
		Subsprite_587:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -21, -20 @ x, y
		Subsprite_588:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -21, 12 @ x, y
		Subsprite_589:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 11, -20 @ x, y
		Subsprite_590:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 11, 12 @ x, y
		Subsprite_591:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_592:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_593:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_594:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_595:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_596:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_597:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_598:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_599:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_600:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_601:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_602:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_603:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_604:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_605:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_606:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_607:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_608:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_609:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_610:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_611:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_612:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_613:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_614:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_615:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_616:
			.byte OAM_SIZE_64x64, 0 @ shape, unk_01(always 0)
			.byte -32, -32 @ x, y
		Subsprite_617:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte -4, -8 @ x, y
		Subsprite_618:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte -4, -8 @ x, y
		Subsprite_619:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte -4, -8 @ x, y
		Subsprite_620:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte -4, -8 @ x, y
		Subsprite_621:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -4, 0 @ x, y
		Subsprite_622:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte -4, -8 @ x, y
		Subsprite_623:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -4, 0 @ x, y
		Subsprite_624:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte -4, -8 @ x, y
		Subsprite_625:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte -4, -8 @ x, y
		Subsprite_626:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -4, 0 @ x, y
		Subsprite_627:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_628:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_629:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_630:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_631:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_632:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_633:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_634:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 0, -48 @ x, y
		Subsprite_635:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 0, -16 @ x, y
		Subsprite_636:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 16, -48 @ x, y
		Subsprite_637:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 16, -16 @ x, y
		Subsprite_638:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -32 @ x, y
		Subsprite_639:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 0 @ x, y
		Subsprite_640:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -16, -52 @ x, y
		Subsprite_641:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -16, -52 @ x, y
		Subsprite_642:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -16, -52 @ x, y
		Subsprite_643:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -16, -64 @ x, y
		Subsprite_644:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -20, -44 @ x, y
		Subsprite_645:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 12, -44 @ x, y
		Subsprite_646:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 12, -12 @ x, y
		Subsprite_647:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -20, -28 @ x, y
		Subsprite_648:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -20, 4 @ x, y
		Subsprite_649:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 12, -28 @ x, y
		Subsprite_650:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 12, 4 @ x, y
		Subsprite_651:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_652:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_653:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 8 @ x, y
		Subsprite_654:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, -8 @ x, y
		Subsprite_655:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_656:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_657:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 8 @ x, y
		Subsprite_658:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_659:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_660:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_661:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_662:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_663:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_664:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_665:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, 8 @ x, y
		Subsprite_666:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -4, -4 @ x, y
		Subsprite_667:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -4, -4 @ x, y
		Subsprite_668:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -4, -4 @ x, y
		Subsprite_669:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -4, -4 @ x, y
		Subsprite_670:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -4, -4 @ x, y
		Subsprite_671:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -4, -4 @ x, y
		Subsprite_672:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -16, -40 @ x, y
		Subsprite_673:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 16, -40 @ x, y
		Subsprite_674:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 16, -8 @ x, y
		Subsprite_675:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -16, -32 @ x, y
		Subsprite_676:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -16, 0 @ x, y
		Subsprite_677:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 0, -32 @ x, y
		Subsprite_678:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 0, 0 @ x, y
		Subsprite_679:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_680:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_681:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_682:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_683:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_684:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_685:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_686:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 0 @ x, y
		Subsprite_687:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte 0, 8 @ x, y
		Subsprite_688:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_689:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_690:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_691:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 0 @ x, y
		Subsprite_692:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, 8 @ x, y
		Subsprite_693:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_694:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte 0, -16 @ x, y
		Subsprite_695:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -8, 8 @ x, y
		Subsprite_696:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_697:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_698:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_699:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_700:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_701:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -16, -52 @ x, y
		Subsprite_702:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -16, -52 @ x, y
		Subsprite_703:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -16, -52 @ x, y
		Subsprite_704:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -10 @ x, y
		Subsprite_705:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -18 @ x, y
		Subsprite_706:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 6 @ x, y
		Subsprite_707:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -10 @ x, y
		Subsprite_708:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -18 @ x, y
		Subsprite_709:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 6 @ x, y
		Subsprite_710:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -10 @ x, y
		Subsprite_711:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -18 @ x, y
		Subsprite_712:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 6 @ x, y
		Subsprite_713:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -18 @ x, y
		Subsprite_714:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -18 @ x, y
		Subsprite_715:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -10 @ x, y
		Subsprite_716:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 6 @ x, y
		Subsprite_717:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -18 @ x, y
		Subsprite_718:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -10 @ x, y
		Subsprite_719:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -18 @ x, y
		Subsprite_720:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 6 @ x, y
		Subsprite_721:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -10 @ x, y
		Subsprite_722:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 6 @ x, y
		Subsprite_723:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -18 @ x, y
		Subsprite_724:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -10 @ x, y
		Subsprite_725:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 6 @ x, y
		Subsprite_726:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -18 @ x, y
		Subsprite_727:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -10 @ x, y
		Subsprite_728:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -18 @ x, y
		Subsprite_729:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 6 @ x, y
		Subsprite_730:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -18 @ x, y
		Subsprite_731:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, -2 @ x, y
		Subsprite_732:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -18 @ x, y
		Subsprite_733:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -2 @ x, y
		Subsprite_734:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -18 @ x, y
		Subsprite_735:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -10 @ x, y
		Subsprite_736:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -18 @ x, y
		Subsprite_737:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 6 @ x, y
		Subsprite_738:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -10 @ x, y
		Subsprite_739:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -18 @ x, y
		Subsprite_740:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 6 @ x, y
		Subsprite_741:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -18 @ x, y
		Subsprite_742:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, -2 @ x, y
		Subsprite_743:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 6 @ x, y
		Subsprite_744:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_745:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -4, -4 @ x, y
		Subsprite_746:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -4, -4 @ x, y
		Subsprite_747:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -4, -4 @ x, y
		Subsprite_748:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_749:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_750:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_751:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_752:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_753:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_754:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_755:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_756:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_757:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_758:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_759:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_760:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_761:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_762:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_763:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_764:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_765:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_766:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_767:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_768:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_769:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_770:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_771:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_772:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_773:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_774:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -6, -49 @ x, y
		Subsprite_775:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -6, -17 @ x, y
		Subsprite_776:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 26, -49 @ x, y
		Subsprite_777:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 26, -17 @ x, y
		Subsprite_778:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -6, -49 @ x, y
		Subsprite_779:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 26, -49 @ x, y
		Subsprite_780:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -6, -49 @ x, y
		Subsprite_781:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -6, -17 @ x, y
		Subsprite_782:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 26, -49 @ x, y
		Subsprite_783:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -6, -49 @ x, y
		Subsprite_784:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -6, -17 @ x, y
		Subsprite_785:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -6, -1 @ x, y
		Subsprite_786:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -32 @ x, y
		Subsprite_787:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -24, 0 @ x, y
		Subsprite_788:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -32 @ x, y
		Subsprite_789:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 8, 0 @ x, y
		Subsprite_790:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_791:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_792:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_793:
			.byte OAM_SIZE_64x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_794:
			.byte OAM_SIZE_64x64, 0 @ shape, unk_01(always 0)
			.byte -32, -32 @ x, y
		Subsprite_795:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_796:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_797:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_798:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_799:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_800:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_801:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_802:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_803:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_804:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -32 @ x, y
		Subsprite_805:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -24, 0 @ x, y
		Subsprite_806:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 8, -32 @ x, y
		Subsprite_807:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, 0 @ x, y
		Subsprite_808:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -32 @ x, y
		Subsprite_809:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, 0 @ x, y
		Subsprite_810:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 16, -32 @ x, y
		Subsprite_811:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 16, 0 @ x, y
		Subsprite_812:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_813:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_814:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_815:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_816:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_817:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_818:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_819:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_820:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_821:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_822:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_823:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_824:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_825:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_826:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_827:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_828:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 0 @ x, y
		Subsprite_829:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -32 @ x, y
		Subsprite_830:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, 0 @ x, y
		Subsprite_831:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -16, -48 @ x, y
		Subsprite_832:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -16, -48 @ x, y
		Subsprite_833:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -16, -48 @ x, y
		Subsprite_834:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -16, -48 @ x, y
		Subsprite_835:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -16, -48 @ x, y
		Subsprite_836:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -9, -29 @ x, y
		Subsprite_837:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte 0, 0 @ x, y
		Subsprite_838:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte 0, 0 @ x, y
		Subsprite_839:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -40 @ x, y
		Subsprite_840:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -32, -48 @ x, y
		Subsprite_841:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 0, -48 @ x, y
		Subsprite_842:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 0, -16 @ x, y
		Subsprite_843:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -64 @ x, y
		Subsprite_844:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -40 @ x, y
		Subsprite_845:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -40 @ x, y
		Subsprite_846:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -24, -8 @ x, y
		Subsprite_847:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -16, -48 @ x, y
		Subsprite_848:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 0, -48 @ x, y
		Subsprite_849:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_850:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 0, -16 @ x, y
		Subsprite_851:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -40 @ x, y
		Subsprite_852:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -40 @ x, y
		Subsprite_853:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -24, -8 @ x, y
		Subsprite_854:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -16, -48 @ x, y
		Subsprite_855:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 0, -48 @ x, y
		Subsprite_856:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_857:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 0, -16 @ x, y
		Subsprite_858:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -40 @ x, y
		Subsprite_859:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -32, -48 @ x, y
		Subsprite_860:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 0, -48 @ x, y
		Subsprite_861:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 0, -16 @ x, y
		Subsprite_862:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -64 @ x, y
		Subsprite_863:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -40 @ x, y
		Subsprite_864:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -32, -48 @ x, y
		Subsprite_865:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 0, -48 @ x, y
		Subsprite_866:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 0, -16 @ x, y
		Subsprite_867:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -64 @ x, y
		Subsprite_868:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -40 @ x, y
		Subsprite_869:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -32, -48 @ x, y
		Subsprite_870:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 0, -48 @ x, y
		Subsprite_871:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 0, -16 @ x, y
		Subsprite_872:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -64 @ x, y
		Subsprite_873:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -40 @ x, y
		Subsprite_874:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -40 @ x, y
		Subsprite_875:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -24, -8 @ x, y
		Subsprite_876:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -16, -48 @ x, y
		Subsprite_877:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 0, -48 @ x, y
		Subsprite_878:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_879:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 0, -16 @ x, y
		Subsprite_880:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -40 @ x, y
		Subsprite_881:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -40 @ x, y
		Subsprite_882:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -24, -8 @ x, y
		Subsprite_883:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -16, -48 @ x, y
		Subsprite_884:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 0, -48 @ x, y
		Subsprite_885:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_886:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 0, -16 @ x, y
		Subsprite_887:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -40 @ x, y
		Subsprite_888:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -32, -48 @ x, y
		Subsprite_889:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 0, -48 @ x, y
		Subsprite_890:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 0, -16 @ x, y
		Subsprite_891:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -64 @ x, y
		Subsprite_892:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -40 @ x, y
		Subsprite_893:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -32, -48 @ x, y
		Subsprite_894:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 0, -48 @ x, y
		Subsprite_895:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 0, -16 @ x, y
		Subsprite_896:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -64 @ x, y
		Subsprite_897:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -17, -17 @ x, y
		Subsprite_898:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -9, -1 @ x, y
		Subsprite_899:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -17, -9 @ x, y
		Subsprite_900:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -17, -17 @ x, y
		Subsprite_901:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 7, -17 @ x, y
		Subsprite_902:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -17, -9 @ x, y
		Subsprite_903:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -9, -17 @ x, y
		Subsprite_904:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -9, -1 @ x, y
		Subsprite_905:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 7, -17 @ x, y
		Subsprite_906:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 7, -1 @ x, y
		Subsprite_907:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -9, -9 @ x, y
		Subsprite_908:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 7, -9 @ x, y
		Subsprite_909:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -9, -17 @ x, y
		Subsprite_910:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -9, -9 @ x, y
		Subsprite_911:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 7, -9 @ x, y
		Subsprite_912:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -9, -17 @ x, y
		Subsprite_913:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -9, -1 @ x, y
		Subsprite_914:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 7, -17 @ x, y
		Subsprite_915:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 7, -1 @ x, y
		Subsprite_916:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -9, -9 @ x, y
		Subsprite_917:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 7, -9 @ x, y
		Subsprite_918:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -1, -17 @ x, y
		Subsprite_919:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -9, -9 @ x, y
		Subsprite_920:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -1, 7 @ x, y
		Subsprite_921:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -9, -9 @ x, y
		Subsprite_922:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 7, -9 @ x, y
		Subsprite_923:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -9, -9 @ x, y
		Subsprite_924:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 7, -9 @ x, y
		Subsprite_925:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -9, 7 @ x, y
		Subsprite_926:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -9, -9 @ x, y
		Subsprite_927:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 7, -9 @ x, y
		Subsprite_928:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -9, 7 @ x, y
		Subsprite_929:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -17, -9 @ x, y
		Subsprite_930:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -17, -9 @ x, y
		Subsprite_931:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -17, -9 @ x, y
		Subsprite_932:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -9, 7 @ x, y
		Subsprite_933:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -9, -9 @ x, y
		Subsprite_934:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 7, -17 @ x, y
		Subsprite_935:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -9, -17 @ x, y
		Subsprite_936:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -9, -9 @ x, y
		Subsprite_937:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 7, -9 @ x, y
		Subsprite_938:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -9, -17 @ x, y
		Subsprite_939:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -9, -9 @ x, y
		Subsprite_940:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 7, -9 @ x, y
		Subsprite_941:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -17, -9 @ x, y
		Subsprite_942:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -17, -17 @ x, y
		Subsprite_943:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -9, -1 @ x, y
		Subsprite_944:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -17, -9 @ x, y
		Subsprite_945:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -17, -17 @ x, y
		Subsprite_946:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -9, -1 @ x, y
		Subsprite_947:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -17, -9 @ x, y
		Subsprite_948:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -17, -1 @ x, y
		Subsprite_949:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -1, -1 @ x, y
		Subsprite_950:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -9, -9 @ x, y
		Subsprite_951:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -1, -17 @ x, y
		Subsprite_952:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 7, -9 @ x, y
		Subsprite_953:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -9, -9 @ x, y
		Subsprite_954:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -1, -17 @ x, y
		Subsprite_955:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 7, -9 @ x, y
		Subsprite_956:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -9, -9 @ x, y
		Subsprite_957:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 7, -9 @ x, y
		Subsprite_958:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte -1, -17 @ x, y
		Subsprite_959:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -17, -9 @ x, y
		Subsprite_960:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte -1, -17 @ x, y
		Subsprite_961:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -17, -9 @ x, y
		Subsprite_962:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -17, -9 @ x, y
		Subsprite_963:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte -1, -9 @ x, y
		Subsprite_964:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -1, 7 @ x, y
		Subsprite_965:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -9, -9 @ x, y
		Subsprite_966:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -9, -17 @ x, y
		Subsprite_967:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -9, -9 @ x, y
		Subsprite_968:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_969:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_970:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_971:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_972:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_973:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_974:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_975:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_976:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_977:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_978:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_979:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_980:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_981:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_982:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_983:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_984:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_985:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_986:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_987:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_988:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_989:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_990:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_991:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_992:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_993:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_994:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_995:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -16, -48 @ x, y
		Subsprite_996:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 16, -48 @ x, y
		Subsprite_997:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_998:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_999:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_1000:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_1001:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_1002:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_1003:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1004:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1005:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_1006:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 8 @ x, y
		Subsprite_1007:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, 0 @ x, y
		Subsprite_1008:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_1009:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_1010:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 8, 0 @ x, y
		Subsprite_1011:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_1012:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte 0, 0 @ x, y
		Subsprite_1013:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_1014:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_1015:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_1016:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 0, 0 @ x, y
		Subsprite_1017:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1018:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_1019:
			.byte OAM_SIZE_64x64, 0 @ shape, unk_01(always 0)
			.byte -33, -54 @ x, y
		Subsprite_1020:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -20, -20 @ x, y
		Subsprite_1021:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -20, 12 @ x, y
		Subsprite_1022:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 12, -20 @ x, y
		Subsprite_1023:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -16, -52 @ x, y
		Subsprite_1024:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -16, -52 @ x, y
		Subsprite_1025:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -16, -52 @ x, y
		Subsprite_1026:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -16, -52 @ x, y
		Subsprite_1027:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -16, -52 @ x, y
		Subsprite_1028:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -16, -52 @ x, y
		Subsprite_1029:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -16, -52 @ x, y
		Subsprite_1030:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -16, -52 @ x, y
		Subsprite_1031:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, 0 @ x, y
		Subsprite_1032:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -24, 32 @ x, y
		Subsprite_1033:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 8, 0 @ x, y
		Subsprite_1034:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1035:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1036:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1037:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1038:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1039:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1040:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1041:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1042:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1043:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1044:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1045:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1046:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1047:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1048:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1049:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1050:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1051:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1052:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -8, 0 @ x, y
		Subsprite_1053:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1054:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -8, 0 @ x, y
		Subsprite_1055:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1056:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1057:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1058:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1059:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1060:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1061:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1062:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1063:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1064:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1065:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1066:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte -4, -8 @ x, y
		Subsprite_1067:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte -4, -8 @ x, y
		Subsprite_1068:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte -4, -8 @ x, y
		Subsprite_1069:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte -4, -8 @ x, y
		Subsprite_1070:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte -4, -8 @ x, y
		Subsprite_1071:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte -4, -8 @ x, y
		Subsprite_1072:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte -4, -8 @ x, y
		Subsprite_1073:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte -4, -8 @ x, y
		Subsprite_1074:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte -4, -8 @ x, y
		Subsprite_1075:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte -4, -8 @ x, y
		Subsprite_1076:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte -4, -8 @ x, y
		Subsprite_1077:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -12, -28 @ x, y
		Subsprite_1078:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 4, -28 @ x, y
		Subsprite_1079:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -12, -20 @ x, y
		Subsprite_1080:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -12, -4 @ x, y
		Subsprite_1081:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 4, -20 @ x, y
		Subsprite_1082:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 4, -4 @ x, y
		Subsprite_1083:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -24 @ x, y
		Subsprite_1084:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -24, 8 @ x, y
		Subsprite_1085:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -24 @ x, y
		Subsprite_1086:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 8, 8 @ x, y
		Subsprite_1087:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -20, -44 @ x, y
		Subsprite_1088:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 12, -44 @ x, y
		Subsprite_1089:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 12, -12 @ x, y
		Subsprite_1090:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -20, -44 @ x, y
		Subsprite_1091:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 12, -44 @ x, y
		Subsprite_1092:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 12, -12 @ x, y
		Subsprite_1093:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -20, -44 @ x, y
		Subsprite_1094:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 12, -44 @ x, y
		Subsprite_1095:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 12, -12 @ x, y
		Subsprite_1096:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -20, -44 @ x, y
		Subsprite_1097:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 12, -44 @ x, y
		Subsprite_1098:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 12, -12 @ x, y
		Subsprite_1099:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_1100:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte 0, -8 @ x, y
		Subsprite_1101:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, 0 @ x, y
		Subsprite_1102:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1103:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1104:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 0 @ x, y
		Subsprite_1105:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 8 @ x, y
		Subsprite_1106:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1107:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1108:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1109:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1110:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1111:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 0 @ x, y
		Subsprite_1112:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 8 @ x, y
		Subsprite_1113:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1114:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1115:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1116:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1117:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1118:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1119:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1120:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1121:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1122:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_1123:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_1124:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 8 @ x, y
		Subsprite_1125:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_1126:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_1127:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 8 @ x, y
		Subsprite_1128:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_1129:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, -8 @ x, y
		Subsprite_1130:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -16, 0 @ x, y
		Subsprite_1131:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_1132:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_1133:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 8 @ x, y
		Subsprite_1134:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_1135:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_1136:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 8 @ x, y
		Subsprite_1137:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_1138:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_1139:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 8 @ x, y
		Subsprite_1140:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1141:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_1142:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_1143:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 8 @ x, y
		Subsprite_1144:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_1145:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_1146:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 8 @ x, y
		Subsprite_1147:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1148:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1149:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1150:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1151:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1152:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1153:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1154:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1155:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1156:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1157:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1158:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1159:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1160:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -32 @ x, y
		Subsprite_1161:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -32 @ x, y
		Subsprite_1162:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -24, 0 @ x, y
		Subsprite_1163:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte 8, 0 @ x, y
		Subsprite_1164:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -40 @ x, y
		Subsprite_1165:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_1166:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -40 @ x, y
		Subsprite_1167:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -24, -8 @ x, y
		Subsprite_1168:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -40 @ x, y
		Subsprite_1169:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 8, -8 @ x, y
		Subsprite_1170:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -40 @ x, y
		Subsprite_1171:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -40 @ x, y
		Subsprite_1172:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -8 @ x, y
		Subsprite_1173:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -40 @ x, y
		Subsprite_1174:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -24, -8 @ x, y
		Subsprite_1175:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 8, -40 @ x, y
		Subsprite_1176:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, -8 @ x, y
		Subsprite_1177:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -40 @ x, y
		Subsprite_1178:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -24, -8 @ x, y
		Subsprite_1179:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 8, -40 @ x, y
		Subsprite_1180:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, -8 @ x, y
		Subsprite_1181:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -22, -32 @ x, y
		Subsprite_1182:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -22, 0 @ x, y
		Subsprite_1183:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 10, -32 @ x, y
		Subsprite_1184:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 10, 0 @ x, y
		Subsprite_1185:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -22, -32 @ x, y
		Subsprite_1186:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -22, 0 @ x, y
		Subsprite_1187:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 10, -32 @ x, y
		Subsprite_1188:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 10, 0 @ x, y
		Subsprite_1189:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -22, -32 @ x, y
		Subsprite_1190:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -22, 0 @ x, y
		Subsprite_1191:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 10, -32 @ x, y
		Subsprite_1192:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 10, 0 @ x, y
		Subsprite_1193:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -22, -32 @ x, y
		Subsprite_1194:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -22, 0 @ x, y
		Subsprite_1195:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 10, -32 @ x, y
		Subsprite_1196:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 10, 0 @ x, y
		Subsprite_1197:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -22, -32 @ x, y
		Subsprite_1198:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -22, 0 @ x, y
		Subsprite_1199:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 10, -32 @ x, y
		Subsprite_1200:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 10, 0 @ x, y
		Subsprite_1201:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -22, -32 @ x, y
		Subsprite_1202:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -22, 0 @ x, y
		Subsprite_1203:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 10, -32 @ x, y
		Subsprite_1204:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 10, 0 @ x, y
		Subsprite_1205:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -22, -32 @ x, y
		Subsprite_1206:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -22, 0 @ x, y
		Subsprite_1207:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 10, -32 @ x, y
		Subsprite_1208:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 10, 0 @ x, y
		Subsprite_1209:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -22, -16 @ x, y
		Subsprite_1210:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 10, -16 @ x, y
		Subsprite_1211:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -22, -16 @ x, y
		Subsprite_1212:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 10, -16 @ x, y
		Subsprite_1213:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -22, -32 @ x, y
		Subsprite_1214:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -22, 0 @ x, y
		Subsprite_1215:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 10, -32 @ x, y
		Subsprite_1216:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 10, 0 @ x, y
		Subsprite_1217:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -22, -32 @ x, y
		Subsprite_1218:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -22, 0 @ x, y
		Subsprite_1219:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 10, -32 @ x, y
		Subsprite_1220:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 10, 0 @ x, y
		Subsprite_1221:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -22, -16 @ x, y
		Subsprite_1222:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 10, -16 @ x, y
		Subsprite_1223:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -22, -16 @ x, y
		Subsprite_1224:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 10, -16 @ x, y
		Subsprite_1225:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -22, -40 @ x, y
		Subsprite_1226:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 10, -40 @ x, y
		Subsprite_1227:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 10, -8 @ x, y
		Subsprite_1228:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -22, -24 @ x, y
		Subsprite_1229:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -22, 8 @ x, y
		Subsprite_1230:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 10, -24 @ x, y
		Subsprite_1231:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -22, -24 @ x, y
		Subsprite_1232:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -22, 8 @ x, y
		Subsprite_1233:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 10, -24 @ x, y
		Subsprite_1234:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -22, -32 @ x, y
		Subsprite_1235:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -22, 0 @ x, y
		Subsprite_1236:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 10, -32 @ x, y
		Subsprite_1237:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 10, 0 @ x, y
		Subsprite_1238:
			.byte OAM_SIZE_64x64, 0 @ shape, unk_01(always 0)
			.byte -30, -40 @ x, y
		Subsprite_1239:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -22, -32 @ x, y
		Subsprite_1240:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -22, 0 @ x, y
		Subsprite_1241:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 10, -32 @ x, y
		Subsprite_1242:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 10, 0 @ x, y
		Subsprite_1243:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -22, -40 @ x, y
		Subsprite_1244:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 10, -40 @ x, y
		Subsprite_1245:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 10, -8 @ x, y
		Subsprite_1246:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -22, -32 @ x, y
		Subsprite_1247:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -22, 0 @ x, y
		Subsprite_1248:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 10, -32 @ x, y
		Subsprite_1249:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 10, 0 @ x, y
		Subsprite_1250:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -22, -32 @ x, y
		Subsprite_1251:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -22, 0 @ x, y
		Subsprite_1252:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 10, -32 @ x, y
		Subsprite_1253:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 10, 0 @ x, y
		Subsprite_1254:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -30, -24 @ x, y
		Subsprite_1255:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 2, -24 @ x, y
		Subsprite_1256:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -30, 8 @ x, y
		Subsprite_1257:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte 2, 8 @ x, y
		Subsprite_1258:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -22, -40 @ x, y
		Subsprite_1259:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 10, -40 @ x, y
		Subsprite_1260:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 10, -8 @ x, y
		Subsprite_1261:
			.byte OAM_SIZE_64x32, 0 @ shape, unk_01(always 0)
			.byte -30, -24 @ x, y
		Subsprite_1262:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -30, 8 @ x, y
		Subsprite_1263:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte 2, 8 @ x, y
		Subsprite_1264:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -22, -24 @ x, y
		Subsprite_1265:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 10, -24 @ x, y
		Subsprite_1266:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -22, 8 @ x, y
		Subsprite_1267:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -22, -24 @ x, y
		Subsprite_1268:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 10, -24 @ x, y
		Subsprite_1269:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -22, 8 @ x, y
		Subsprite_1270:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -22, -32 @ x, y
		Subsprite_1271:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -22, 0 @ x, y
		Subsprite_1272:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 10, -32 @ x, y
		Subsprite_1273:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 10, 0 @ x, y
		Subsprite_1274:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -22, -40 @ x, y
		Subsprite_1275:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 10, -40 @ x, y
		Subsprite_1276:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 10, -8 @ x, y
		Subsprite_1277:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -22, -40 @ x, y
		Subsprite_1278:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 10, -40 @ x, y
		Subsprite_1279:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 10, -8 @ x, y
		Subsprite_1280:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -22, -40 @ x, y
		Subsprite_1281:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 10, -40 @ x, y
		Subsprite_1282:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 10, -8 @ x, y
		Subsprite_1283:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -22, -40 @ x, y
		Subsprite_1284:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 10, -40 @ x, y
		Subsprite_1285:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 10, -8 @ x, y
		Subsprite_1286:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -22, -40 @ x, y
		Subsprite_1287:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 10, -40 @ x, y
		Subsprite_1288:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 10, -8 @ x, y
		Subsprite_1289:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -22, -32 @ x, y
		Subsprite_1290:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -22, 0 @ x, y
		Subsprite_1291:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 10, -32 @ x, y
		Subsprite_1292:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 10, 0 @ x, y
		Subsprite_1293:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -22, -16 @ x, y
		Subsprite_1294:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 10, -16 @ x, y
		Subsprite_1295:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -22, -16 @ x, y
		Subsprite_1296:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 10, -16 @ x, y
		Subsprite_1297:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -22, -16 @ x, y
		Subsprite_1298:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 10, -16 @ x, y
		Subsprite_1299:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -3, -13 @ x, y
		Subsprite_1300:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte -3, -29 @ x, y
		Subsprite_1301:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte -11, -5 @ x, y
		Subsprite_1302:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -24 @ x, y
		Subsprite_1303:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -24, 8 @ x, y
		Subsprite_1304:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -24 @ x, y
		Subsprite_1305:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 8, 8 @ x, y
		Subsprite_1306:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -24 @ x, y
		Subsprite_1307:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_1308:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 16, -24 @ x, y
		Subsprite_1309:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1310:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1311:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1312:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1313:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1314:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1315:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1316:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1317:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1318:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1319:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1320:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1321:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1322:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1323:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1324:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1325:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1326:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1327:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1328:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1329:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1330:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1331:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1332:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1333:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1334:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1335:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1336:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1337:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1338:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1339:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1340:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1341:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1342:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1343:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1344:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -21, -21 @ x, y
		Subsprite_1345:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -21, 11 @ x, y
		Subsprite_1346:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 11, -21 @ x, y
		Subsprite_1347:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -24 @ x, y
		Subsprite_1348:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -24, 8 @ x, y
		Subsprite_1349:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -24 @ x, y
		Subsprite_1350:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 8, 8 @ x, y
		Subsprite_1351:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1352:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_1353:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, -8 @ x, y
		Subsprite_1354:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1355:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_1356:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1357:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -8, 8 @ x, y
		Subsprite_1358:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1359:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1360:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, -16 @ x, y
		Subsprite_1361:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -8, 8 @ x, y
		Subsprite_1362:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1363:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1364:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1365:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1366:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1367:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1368:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte -16, 0 @ x, y
		Subsprite_1369:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -16, 0 @ x, y
		Subsprite_1370:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -16, 0 @ x, y
		Subsprite_1371:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 0, -8 @ x, y
		Subsprite_1372:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_1373:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 0 @ x, y
		Subsprite_1374:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 8, 0 @ x, y
		Subsprite_1375:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_1376:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 0 @ x, y
		Subsprite_1377:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_1378:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 8, 0 @ x, y
		Subsprite_1379:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_1380:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_1381:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte 0, -16 @ x, y
		Subsprite_1382:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, -8 @ x, y
		Subsprite_1383:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 8, 0 @ x, y
		Subsprite_1384:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 0 @ x, y
		Subsprite_1385:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1386:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1387:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1388:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1389:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1390:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1391:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_1392:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_1393:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_1394:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1395:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1396:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1397:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1398:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1399:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1400:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1401:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_1402:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_1403:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 8 @ x, y
		Subsprite_1404:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1405:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1406:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1407:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 0 @ x, y
		Subsprite_1408:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 8 @ x, y
		Subsprite_1409:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1410:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 0 @ x, y
		Subsprite_1411:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 8 @ x, y
		Subsprite_1412:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1413:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 0 @ x, y
		Subsprite_1414:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 8 @ x, y
		Subsprite_1415:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1416:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1417:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_1418:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_1419:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 8 @ x, y
		Subsprite_1420:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_1421:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_1422:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 8 @ x, y
		Subsprite_1423:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_1424:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_1425:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 0, -16 @ x, y
		Subsprite_1426:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, 0 @ x, y
		Subsprite_1427:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_1428:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_1429:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1430:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, -16 @ x, y
		Subsprite_1431:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -8, 8 @ x, y
		Subsprite_1432:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1433:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 0, -16 @ x, y
		Subsprite_1434:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1435:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -16, 0 @ x, y
		Subsprite_1436:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -8, 8 @ x, y
		Subsprite_1437:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1438:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_1439:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 8, 0 @ x, y
		Subsprite_1440:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1441:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 0 @ x, y
		Subsprite_1442:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1443:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_1444:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_1445:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_1446:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_1447:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 0, 0 @ x, y
		Subsprite_1448:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, 0 @ x, y
		Subsprite_1449:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1450:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, -8 @ x, y
		Subsprite_1451:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_1452:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_1453:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1454:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1455:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1456:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1457:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 0, -16 @ x, y
		Subsprite_1458:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1459:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1460:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1461:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1462:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, -8 @ x, y
		Subsprite_1463:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 8, 8 @ x, y
		Subsprite_1464:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte 0, -16 @ x, y
		Subsprite_1465:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, -8 @ x, y
		Subsprite_1466:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1467:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1468:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1469:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1470:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1471:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1472:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1473:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1474:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1475:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 0, -16 @ x, y
		Subsprite_1476:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1477:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1478:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1479:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1480:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 0 @ x, y
		Subsprite_1481:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1482:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -16, 0 @ x, y
		Subsprite_1483:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1484:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -8, 8 @ x, y
		Subsprite_1485:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1486:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_1487:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1488:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_1489:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_1490:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_1491:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 8 @ x, y
		Subsprite_1492:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_1493:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 0, -8 @ x, y
		Subsprite_1494:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1495:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1496:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1497:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 0 @ x, y
		Subsprite_1498:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1499:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 0, 0 @ x, y
		Subsprite_1500:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_1501:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 0 @ x, y
		Subsprite_1502:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 24 @ x, y
		Subsprite_1503:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_1504:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 0 @ x, y
		Subsprite_1505:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 24 @ x, y
		Subsprite_1506:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_1507:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 0 @ x, y
		Subsprite_1508:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 24 @ x, y
		Subsprite_1509:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_1510:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 0 @ x, y
		Subsprite_1511:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 24 @ x, y
		Subsprite_1512:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_1513:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 0 @ x, y
		Subsprite_1514:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 24 @ x, y
		Subsprite_1515:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_1516:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 0 @ x, y
		Subsprite_1517:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 24 @ x, y
		Subsprite_1518:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_1519:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 0 @ x, y
		Subsprite_1520:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 24 @ x, y
		Subsprite_1521:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_1522:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 0 @ x, y
		Subsprite_1523:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 24 @ x, y
		Subsprite_1524:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_1525:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 0 @ x, y
		Subsprite_1526:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 24 @ x, y
		Subsprite_1527:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_1528:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 0 @ x, y
		Subsprite_1529:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 24 @ x, y
		Subsprite_1530:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_1531:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 0 @ x, y
		Subsprite_1532:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 24 @ x, y
		Subsprite_1533:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1534:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1535:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1536:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1537:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1538:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1539:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1540:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1541:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1542:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1543:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1544:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1545:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1546:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1547:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1548:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1549:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -19 @ x, y
		Subsprite_1550:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -3 @ x, y
		Subsprite_1551:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -19 @ x, y
		Subsprite_1552:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -3 @ x, y
		Subsprite_1553:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -19 @ x, y
		Subsprite_1554:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -19 @ x, y
		Subsprite_1555:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -8, -3 @ x, y
		Subsprite_1556:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -19 @ x, y
		Subsprite_1557:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -3 @ x, y
		Subsprite_1558:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte -8, -19 @ x, y
		Subsprite_1559:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 0, -19 @ x, y
		Subsprite_1560:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, -3 @ x, y
		Subsprite_1561:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -19 @ x, y
		Subsprite_1562:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -8, -3 @ x, y
		Subsprite_1563:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -19 @ x, y
		Subsprite_1564:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -8, -3 @ x, y
		Subsprite_1565:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -19 @ x, y
		Subsprite_1566:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -8, -3 @ x, y
		Subsprite_1567:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -19 @ x, y
		Subsprite_1568:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -8, -3 @ x, y
		Subsprite_1569:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -19 @ x, y
		Subsprite_1570:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -8, -3 @ x, y
		Subsprite_1571:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -19 @ x, y
		Subsprite_1572:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -8, -3 @ x, y
		Subsprite_1573:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -19 @ x, y
		Subsprite_1574:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -3 @ x, y
		Subsprite_1575:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -19 @ x, y
		Subsprite_1576:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -3 @ x, y
		Subsprite_1577:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -19 @ x, y
		Subsprite_1578:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -3 @ x, y
		Subsprite_1579:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -19 @ x, y
		Subsprite_1580:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -19 @ x, y
		Subsprite_1581:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -19 @ x, y
		Subsprite_1582:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -3 @ x, y
		Subsprite_1583:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -19 @ x, y
		Subsprite_1584:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -3 @ x, y
		Subsprite_1585:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -19 @ x, y
		Subsprite_1586:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -3 @ x, y
		Subsprite_1587:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -19 @ x, y
		Subsprite_1588:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -3 @ x, y
		Subsprite_1589:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -19 @ x, y
		Subsprite_1590:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -3 @ x, y
		Subsprite_1591:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -19 @ x, y
		Subsprite_1592:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -3 @ x, y
		Subsprite_1593:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -19 @ x, y
		Subsprite_1594:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -3 @ x, y
		Subsprite_1595:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -19 @ x, y
		Subsprite_1596:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -3 @ x, y
		Subsprite_1597:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -19 @ x, y
		Subsprite_1598:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -3 @ x, y
		Subsprite_1599:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -19 @ x, y
		Subsprite_1600:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -3 @ x, y
		Subsprite_1601:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -19 @ x, y
		Subsprite_1602:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -3 @ x, y
		Subsprite_1603:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -19 @ x, y
		Subsprite_1604:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -3 @ x, y
		Subsprite_1605:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -19 @ x, y
		Subsprite_1606:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -3 @ x, y
		Subsprite_1607:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -19 @ x, y
		Subsprite_1608:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -3 @ x, y
		Subsprite_1609:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -19 @ x, y
		Subsprite_1610:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -3 @ x, y
		Subsprite_1611:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -19 @ x, y
		Subsprite_1612:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -3 @ x, y
		Subsprite_1613:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -19 @ x, y
		Subsprite_1614:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -3 @ x, y
		Subsprite_1615:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -19 @ x, y
		Subsprite_1616:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -3 @ x, y
		Subsprite_1617:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -19 @ x, y
		Subsprite_1618:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -3 @ x, y
		Subsprite_1619:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -19 @ x, y
		Subsprite_1620:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -3 @ x, y
		Subsprite_1621:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -19 @ x, y
		Subsprite_1622:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -3 @ x, y
		Subsprite_1623:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -19 @ x, y
		Subsprite_1624:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -3 @ x, y
		Subsprite_1625:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, -19 @ x, y
		Subsprite_1626:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, -3 @ x, y
		Subsprite_1627:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -11 @ x, y
		Subsprite_1628:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 8, -11 @ x, y
		Subsprite_1629:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, -3 @ x, y
		Subsprite_1630:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -11 @ x, y
		Subsprite_1631:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 8, -11 @ x, y
		Subsprite_1632:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -19 @ x, y
		Subsprite_1633:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -3 @ x, y
		Subsprite_1634:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -11 @ x, y
		Subsprite_1635:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 5 @ x, y
		Subsprite_1636:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, -11 @ x, y
		Subsprite_1637:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -3 @ x, y
		Subsprite_1638:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -16, -3 @ x, y
		Subsprite_1639:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -16, -11 @ x, y
		Subsprite_1640:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -16, 5 @ x, y
		Subsprite_1641:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 0, -11 @ x, y
		Subsprite_1642:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, 5 @ x, y
		Subsprite_1643:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -19 @ x, y
		Subsprite_1644:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -3 @ x, y
		Subsprite_1645:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -19 @ x, y
		Subsprite_1646:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -3 @ x, y
		Subsprite_1647:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -16, -11 @ x, y
		Subsprite_1648:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte 0, 5 @ x, y
		Subsprite_1649:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 0, -11 @ x, y
		Subsprite_1650:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -16, -19 @ x, y
		Subsprite_1651:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 0, -19 @ x, y
		Subsprite_1652:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -11 @ x, y
		Subsprite_1653:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 5 @ x, y
		Subsprite_1654:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -19 @ x, y
		Subsprite_1655:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -3 @ x, y
		Subsprite_1656:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1657:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -4, -4 @ x, y
		Subsprite_1658:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_1659:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_1660:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_1661:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_1662:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_1663:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_1664:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -24 @ x, y
		Subsprite_1665:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -24, 8 @ x, y
		Subsprite_1666:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -24 @ x, y
		Subsprite_1667:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 8, 8 @ x, y
		Subsprite_1668:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, 0 @ x, y
		Subsprite_1669:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -24, 32 @ x, y
		Subsprite_1670:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 8, 0 @ x, y
		Subsprite_1671:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, 0 @ x, y
		Subsprite_1672:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -24, 32 @ x, y
		Subsprite_1673:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 8, 0 @ x, y
		Subsprite_1674:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1675:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1676:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1677:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1678:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1679:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1680:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, 0 @ x, y
		Subsprite_1681:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_1682:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, -8 @ x, y
		Subsprite_1683:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1684:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 0, -16 @ x, y
		Subsprite_1685:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1686:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 0, -16 @ x, y
		Subsprite_1687:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, 0 @ x, y
		Subsprite_1688:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_1689:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_1690:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_1691:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_1692:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_1693:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_1694:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_1695:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_1696:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_1697:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_1698:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_1699:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_1700:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_1701:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_1702:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_1703:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_1704:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_1705:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_1706:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_1707:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_1708:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_1709:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_1710:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_1711:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_1712:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_1713:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_1714:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_1715:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_1716:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_1717:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_1718:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_1719:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_1720:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_1721:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -24, 0 @ x, y
		Subsprite_1722:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -24, 32 @ x, y
		Subsprite_1723:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte -8, 0 @ x, y
		Subsprite_1724:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte -8, 32 @ x, y
		Subsprite_1725:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -11, -32 @ x, y
		Subsprite_1726:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -11, -32 @ x, y
		Subsprite_1727:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -7, -18 @ x, y
		Subsprite_1728:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte -7, -18 @ x, y
		Subsprite_1729:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 1, -18 @ x, y
		Subsprite_1730:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -7, -18 @ x, y
		Subsprite_1731:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -7, -18 @ x, y
		Subsprite_1732:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -34 @ x, y
		Subsprite_1733:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -2 @ x, y
		Subsprite_1734:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 8, -18 @ x, y
		Subsprite_1735:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -34 @ x, y
		Subsprite_1736:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, -2 @ x, y
		Subsprite_1737:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -34 @ x, y
		Subsprite_1738:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -2 @ x, y
		Subsprite_1739:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 8, -18 @ x, y
		Subsprite_1740:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -34 @ x, y
		Subsprite_1741:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, -2 @ x, y
		Subsprite_1742:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -34 @ x, y
		Subsprite_1743:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -2 @ x, y
		Subsprite_1744:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, -18 @ x, y
		Subsprite_1745:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -34 @ x, y
		Subsprite_1746:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 8, -34 @ x, y
		Subsprite_1747:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -2 @ x, y
		Subsprite_1748:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -34 @ x, y
		Subsprite_1749:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, -2 @ x, y
		Subsprite_1750:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -34 @ x, y
		Subsprite_1751:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -2 @ x, y
		Subsprite_1752:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 8, -18 @ x, y
		Subsprite_1753:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -34 @ x, y
		Subsprite_1754:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -2 @ x, y
		Subsprite_1755:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, -18 @ x, y
		Subsprite_1756:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -34 @ x, y
		Subsprite_1757:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, -2 @ x, y
		Subsprite_1758:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -34 @ x, y
		Subsprite_1759:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, -2 @ x, y
		Subsprite_1760:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -34 @ x, y
		Subsprite_1761:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -2 @ x, y
		Subsprite_1762:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 8, -18 @ x, y
		Subsprite_1763:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -34 @ x, y
		Subsprite_1764:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 8, -34 @ x, y
		Subsprite_1765:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -2 @ x, y
		Subsprite_1766:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -34 @ x, y
		Subsprite_1767:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -2 @ x, y
		Subsprite_1768:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, -18 @ x, y
		Subsprite_1769:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -34 @ x, y
		Subsprite_1770:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -2 @ x, y
		Subsprite_1771:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, -18 @ x, y
		Subsprite_1772:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -26 @ x, y
		Subsprite_1773:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, -26 @ x, y
		Subsprite_1774:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 8, -10 @ x, y
		Subsprite_1775:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -26 @ x, y
		Subsprite_1776:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 8, -26 @ x, y
		Subsprite_1777:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -34 @ x, y
		Subsprite_1778:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, -2 @ x, y
		Subsprite_1779:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -34 @ x, y
		Subsprite_1780:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -2 @ x, y
		Subsprite_1781:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 8, -18 @ x, y
		Subsprite_1782:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -34 @ x, y
		Subsprite_1783:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -2 @ x, y
		Subsprite_1784:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, -18 @ x, y
		Subsprite_1785:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -26 @ x, y
		Subsprite_1786:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 8, -26 @ x, y
		Subsprite_1787:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -26 @ x, y
		Subsprite_1788:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 8, -26 @ x, y
		Subsprite_1789:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -34 @ x, y
		Subsprite_1790:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -2 @ x, y
		Subsprite_1791:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, -18 @ x, y
		Subsprite_1792:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -34 @ x, y
		Subsprite_1793:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -2 @ x, y
		Subsprite_1794:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, -18 @ x, y
		Subsprite_1795:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -34 @ x, y
		Subsprite_1796:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -2 @ x, y
		Subsprite_1797:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, -18 @ x, y
		Subsprite_1798:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -34 @ x, y
		Subsprite_1799:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -2 @ x, y
		Subsprite_1800:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, -18 @ x, y
		Subsprite_1801:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -34 @ x, y
		Subsprite_1802:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -2 @ x, y
		Subsprite_1803:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, -18 @ x, y
		Subsprite_1804:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -34 @ x, y
		Subsprite_1805:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -2 @ x, y
		Subsprite_1806:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, -18 @ x, y
		Subsprite_1807:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -34 @ x, y
		Subsprite_1808:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -2 @ x, y
		Subsprite_1809:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, -18 @ x, y
		Subsprite_1810:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -34 @ x, y
		Subsprite_1811:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -2 @ x, y
		Subsprite_1812:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, -18 @ x, y
		Subsprite_1813:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -34 @ x, y
		Subsprite_1814:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -2 @ x, y
		Subsprite_1815:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, -18 @ x, y
		Subsprite_1816:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -34 @ x, y
		Subsprite_1817:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -2 @ x, y
		Subsprite_1818:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, -18 @ x, y
		Subsprite_1819:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -34 @ x, y
		Subsprite_1820:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -2 @ x, y
		Subsprite_1821:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, -18 @ x, y
		Subsprite_1822:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -34 @ x, y
		Subsprite_1823:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, -18 @ x, y
		Subsprite_1824:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -8, -2 @ x, y
		Subsprite_1825:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -34 @ x, y
		Subsprite_1826:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -2 @ x, y
		Subsprite_1827:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 8, -18 @ x, y
		Subsprite_1828:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -34 @ x, y
		Subsprite_1829:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -2 @ x, y
		Subsprite_1830:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, -18 @ x, y
		Subsprite_1831:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -34 @ x, y
		Subsprite_1832:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -2 @ x, y
		Subsprite_1833:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, -18 @ x, y
		Subsprite_1834:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -34 @ x, y
		Subsprite_1835:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, -18 @ x, y
		Subsprite_1836:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -8, -2 @ x, y
		Subsprite_1837:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -34 @ x, y
		Subsprite_1838:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -2 @ x, y
		Subsprite_1839:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 8, -18 @ x, y
		Subsprite_1840:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -34 @ x, y
		Subsprite_1841:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -2 @ x, y
		Subsprite_1842:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, -18 @ x, y
		Subsprite_1843:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -34 @ x, y
		Subsprite_1844:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 8, -18 @ x, y
		Subsprite_1845:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, -2 @ x, y
		Subsprite_1846:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -34 @ x, y
		Subsprite_1847:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, -2 @ x, y
		Subsprite_1848:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -34 @ x, y
		Subsprite_1849:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -2 @ x, y
		Subsprite_1850:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, -18 @ x, y
		Subsprite_1851:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -34 @ x, y
		Subsprite_1852:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -2 @ x, y
		Subsprite_1853:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -16, -34 @ x, y
		Subsprite_1854:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -34 @ x, y
		Subsprite_1855:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -2 @ x, y
		Subsprite_1856:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 8, -18 @ x, y
		Subsprite_1857:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -34 @ x, y
		Subsprite_1858:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -2 @ x, y
		Subsprite_1859:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, -18 @ x, y
		Subsprite_1860:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -18 @ x, y
		Subsprite_1861:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -34 @ x, y
		Subsprite_1862:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -2 @ x, y
		Subsprite_1863:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_1864:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_1865:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_1866:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_1867:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_1868:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_1869:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_1870:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_1871:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_1872:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -46 @ x, y
		Subsprite_1873:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -46 @ x, y
		Subsprite_1874:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -14 @ x, y
		Subsprite_1875:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -46 @ x, y
		Subsprite_1876:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -46 @ x, y
		Subsprite_1877:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -14 @ x, y
		Subsprite_1878:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -46 @ x, y
		Subsprite_1879:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -46 @ x, y
		Subsprite_1880:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -14 @ x, y
		Subsprite_1881:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -46 @ x, y
		Subsprite_1882:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -46 @ x, y
		Subsprite_1883:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -14 @ x, y
		Subsprite_1884:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -46 @ x, y
		Subsprite_1885:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -46 @ x, y
		Subsprite_1886:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -14 @ x, y
		Subsprite_1887:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -46 @ x, y
		Subsprite_1888:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -46 @ x, y
		Subsprite_1889:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -14 @ x, y
		Subsprite_1890:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -46 @ x, y
		Subsprite_1891:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -46 @ x, y
		Subsprite_1892:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -14 @ x, y
		Subsprite_1893:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -46 @ x, y
		Subsprite_1894:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -46 @ x, y
		Subsprite_1895:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -14 @ x, y
		Subsprite_1896:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -46 @ x, y
		Subsprite_1897:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -46 @ x, y
		Subsprite_1898:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -14 @ x, y
		Subsprite_1899:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -46 @ x, y
		Subsprite_1900:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -46 @ x, y
		Subsprite_1901:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -14 @ x, y
		Subsprite_1902:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -46 @ x, y
		Subsprite_1903:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -46 @ x, y
		Subsprite_1904:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -14 @ x, y
		Subsprite_1905:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -46 @ x, y
		Subsprite_1906:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -46 @ x, y
		Subsprite_1907:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -14 @ x, y
		Subsprite_1908:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, 0 @ x, y
		Subsprite_1909:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 32 @ x, y
		Subsprite_1910:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 16, 0 @ x, y
		Subsprite_1911:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, 0 @ x, y
		Subsprite_1912:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 32 @ x, y
		Subsprite_1913:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 16, 0 @ x, y
		Subsprite_1914:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -16, -48 @ x, y
		Subsprite_1915:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -32 @ x, y
		Subsprite_1916:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -24, 0 @ x, y
		Subsprite_1917:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 8, -32 @ x, y
		Subsprite_1918:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -32 @ x, y
		Subsprite_1919:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -24, 0 @ x, y
		Subsprite_1920:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 8, -32 @ x, y
		Subsprite_1921:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, 0 @ x, y
		Subsprite_1922:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -32 @ x, y
		Subsprite_1923:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -24, 0 @ x, y
		Subsprite_1924:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 8, -32 @ x, y
		Subsprite_1925:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, 0 @ x, y
		Subsprite_1926:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -20, -40 @ x, y
		Subsprite_1927:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 12, -40 @ x, y
		Subsprite_1928:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 12, -8 @ x, y
		Subsprite_1929:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -20, -40 @ x, y
		Subsprite_1930:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 12, -40 @ x, y
		Subsprite_1931:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 12, -8 @ x, y
		Subsprite_1932:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1933:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1934:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1935:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1936:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1937:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1938:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1939:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1940:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1941:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -29 @ x, y
		Subsprite_1942:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 3 @ x, y
		Subsprite_1943:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -37 @ x, y
		Subsprite_1944:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -24 @ x, y
		Subsprite_1945:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -24, 8 @ x, y
		Subsprite_1946:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -24 @ x, y
		Subsprite_1947:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 8, 8 @ x, y
		Subsprite_1948:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -24 @ x, y
		Subsprite_1949:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -24, 8 @ x, y
		Subsprite_1950:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -24 @ x, y
		Subsprite_1951:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 8, 8 @ x, y
		Subsprite_1952:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, 0 @ x, y
		Subsprite_1953:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, 0 @ x, y
		Subsprite_1954:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, 0 @ x, y
		Subsprite_1955:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, 0 @ x, y
		Subsprite_1956:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, 0 @ x, y
		Subsprite_1957:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, 0 @ x, y
		Subsprite_1958:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, 0 @ x, y
		Subsprite_1959:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, 0 @ x, y
		Subsprite_1960:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, 0 @ x, y
		Subsprite_1961:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, 0 @ x, y
		Subsprite_1962:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, 0 @ x, y
		Subsprite_1963:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1964:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_1965:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, 8 @ x, y
		Subsprite_1966:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1967:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, 8 @ x, y
		Subsprite_1968:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1969:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1970:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_1971:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_1972:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_1973:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_1974:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 0, -8 @ x, y
		Subsprite_1975:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1976:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1977:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, -16 @ x, y
		Subsprite_1978:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1979:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_1980:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, 8 @ x, y
		Subsprite_1981:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1982:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, 8 @ x, y
		Subsprite_1983:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1984:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1985:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_1986:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_1987:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_1988:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1989:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -8, 8 @ x, y
		Subsprite_1990:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1991:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_1992:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, -16 @ x, y
		Subsprite_1993:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_1994:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1995:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_1996:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_1997:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_1998:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_1999:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 8 @ x, y
		Subsprite_2000:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 0, -8 @ x, y
		Subsprite_2001:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2002:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -16, 0 @ x, y
		Subsprite_2003:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 0, -16 @ x, y
		Subsprite_2004:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, 0 @ x, y
		Subsprite_2005:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -12 @ x, y
		Subsprite_2006:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -12 @ x, y
		Subsprite_2007:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -8, 4 @ x, y
		Subsprite_2008:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -12 @ x, y
		Subsprite_2009:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 4 @ x, y
		Subsprite_2010:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -16, -12 @ x, y
		Subsprite_2011:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -20 @ x, y
		Subsprite_2012:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte -8, -20 @ x, y
		Subsprite_2013:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 0, -20 @ x, y
		Subsprite_2014:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, -4 @ x, y
		Subsprite_2015:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -12 @ x, y
		Subsprite_2016:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -12 @ x, y
		Subsprite_2017:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -8, -20 @ x, y
		Subsprite_2018:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -12 @ x, y
		Subsprite_2019:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 4 @ x, y
		Subsprite_2020:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -20 @ x, y
		Subsprite_2021:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -12 @ x, y
		Subsprite_2022:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, -20 @ x, y
		Subsprite_2023:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -12 @ x, y
		Subsprite_2024:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -12 @ x, y
		Subsprite_2025:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -12 @ x, y
		Subsprite_2026:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -12 @ x, y
		Subsprite_2027:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -12 @ x, y
		Subsprite_2028:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -12 @ x, y
		Subsprite_2029:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2030:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2031:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2032:
			.byte OAM_SIZE_64x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2033:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -32 @ x, y
		Subsprite_2034:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_2035:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, -24 @ x, y
		Subsprite_2036:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -32 @ x, y
		Subsprite_2037:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_2038:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, -24 @ x, y
		Subsprite_2039:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -32 @ x, y
		Subsprite_2040:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_2041:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, -24 @ x, y
		Subsprite_2042:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -32 @ x, y
		Subsprite_2043:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_2044:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, -24 @ x, y
		Subsprite_2045:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -32 @ x, y
		Subsprite_2046:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_2047:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, -24 @ x, y
		Subsprite_2048:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -32 @ x, y
		Subsprite_2049:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, -24 @ x, y
		Subsprite_2050:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -32 @ x, y
		Subsprite_2051:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, -24 @ x, y
		Subsprite_2052:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -32 @ x, y
		Subsprite_2053:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, -24 @ x, y
		Subsprite_2054:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -32 @ x, y
		Subsprite_2055:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, -24 @ x, y
		Subsprite_2056:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -32 @ x, y
		Subsprite_2057:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, -24 @ x, y
		Subsprite_2058:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -46 @ x, y
		Subsprite_2059:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -46 @ x, y
		Subsprite_2060:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -14 @ x, y
		Subsprite_2061:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -24 @ x, y
		Subsprite_2062:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -24, 8 @ x, y
		Subsprite_2063:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -24 @ x, y
		Subsprite_2064:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 8, 8 @ x, y
		Subsprite_2065:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -24 @ x, y
		Subsprite_2066:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -24, 8 @ x, y
		Subsprite_2067:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -24 @ x, y
		Subsprite_2068:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 8, 8 @ x, y
		Subsprite_2069:
			.byte OAM_SIZE_64x64, 0 @ shape, unk_01(always 0)
			.byte -32, -32 @ x, y
		Subsprite_2070:
			.byte OAM_SIZE_64x64, 0 @ shape, unk_01(always 0)
			.byte -32, -32 @ x, y
		Subsprite_2071:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_2072:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_2073:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 8 @ x, y
		Subsprite_2074:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_2075:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 8 @ x, y
		Subsprite_2076:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -6 @ x, y
		Subsprite_2077:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -6 @ x, y
		Subsprite_2078:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -6 @ x, y
		Subsprite_2079:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -6 @ x, y
		Subsprite_2080:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_2081:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_2082:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_2083:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_2084:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_2085:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_2086:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_2087:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_2088:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_2089:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_2090:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_2091:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_2092:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_2093:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_2094:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_2095:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_2096:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_2097:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_2098:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_2099:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -4, -4 @ x, y
		Subsprite_2100:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -4, -4 @ x, y
		Subsprite_2101:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -4, -4 @ x, y
		Subsprite_2102:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -4, -4 @ x, y
		Subsprite_2103:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -4, -4 @ x, y
		Subsprite_2104:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -4, -4 @ x, y
		Subsprite_2105:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -4, -4 @ x, y
		Subsprite_2106:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2107:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2108:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2109:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2110:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2111:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2112:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2113:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2114:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2115:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -32 @ x, y
		Subsprite_2116:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -24, 0 @ x, y
		Subsprite_2117:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 8, -32 @ x, y
		Subsprite_2118:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, 0 @ x, y
		Subsprite_2119:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -32 @ x, y
		Subsprite_2120:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, 0 @ x, y
		Subsprite_2121:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 16, -32 @ x, y
		Subsprite_2122:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 16, 0 @ x, y
		Subsprite_2123:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2124:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2125:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2126:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2127:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2128:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2129:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2130:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2131:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2132:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2133:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2134:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2135:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -24, 8 @ x, y
		Subsprite_2136:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2137:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2138:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2139:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2140:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2141:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2142:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, -40 @ x, y
		Subsprite_2143:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, -24 @ x, y
		Subsprite_2144:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2145:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2146:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2147:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2148:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2149:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2150:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -32 @ x, y
		Subsprite_2151:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, 0 @ x, y
		Subsprite_2152:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 16, -32 @ x, y
		Subsprite_2153:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 16, 0 @ x, y
		Subsprite_2154:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2155:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2156:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2157:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2158:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2159:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2160:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2161:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2162:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2163:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2164:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2165:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2166:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2167:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2168:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2169:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2170:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2171:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2172:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2173:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2174:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2175:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2176:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2177:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2178:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2179:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2180:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2181:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2182:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2183:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2184:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2185:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2186:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2187:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -31 @ x, y
		Subsprite_2188:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -31 @ x, y
		Subsprite_2189:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -31 @ x, y
		Subsprite_2190:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -31 @ x, y
		Subsprite_2191:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_2192:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 0 @ x, y
		Subsprite_2193:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 16 @ x, y
		Subsprite_2194:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_2195:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 0 @ x, y
		Subsprite_2196:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 16 @ x, y
		Subsprite_2197:
			.byte OAM_SIZE_64x64, 0 @ shape, unk_01(always 0)
			.byte -24, -40 @ x, y
		Subsprite_2198:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -3, -13 @ x, y
		Subsprite_2199:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -3, 3 @ x, y
		Subsprite_2200:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -3, -13 @ x, y
		Subsprite_2201:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -3, 3 @ x, y
		Subsprite_2202:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -3, -13 @ x, y
		Subsprite_2203:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -3, 3 @ x, y
		Subsprite_2204:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_2205:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2206:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2207:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -20 @ x, y
		Subsprite_2208:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 12 @ x, y
		Subsprite_2209:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 8, -28 @ x, y
		Subsprite_2210:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_2211:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -16, 0 @ x, y
		Subsprite_2212:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 8, 0 @ x, y
		Subsprite_2213:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_2214:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -16, 0 @ x, y
		Subsprite_2215:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 8, 0 @ x, y
		Subsprite_2216:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_2217:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -16, 0 @ x, y
		Subsprite_2218:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 8, 0 @ x, y
		Subsprite_2219:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2220:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2221:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2222:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_2223:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2224:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, -8 @ x, y
		Subsprite_2225:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_2226:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2227:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, -8 @ x, y
		Subsprite_2228:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_2229:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2230:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, -8 @ x, y
		Subsprite_2231:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_2232:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_2233:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 8, -8 @ x, y
		Subsprite_2234:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_2235:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2236:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 8, -8 @ x, y
		Subsprite_2237:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_2238:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2239:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 8, -8 @ x, y
		Subsprite_2240:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_2241:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_2242:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 8 @ x, y
		Subsprite_2243:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_2244:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_2245:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 8 @ x, y
		Subsprite_2246:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_2247:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_2248:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 8 @ x, y
		Subsprite_2249:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2250:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2251:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2252:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2253:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 0 @ x, y
		Subsprite_2254:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 8 @ x, y
		Subsprite_2255:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_2256:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_2257:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_2258:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_2259:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_2260:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_2261:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_2262:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 0 @ x, y
		Subsprite_2263:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_2264:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_2265:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_2266:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, 0 @ x, y
		Subsprite_2267:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_2268:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_2269:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_2270:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_2271:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_2272:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_2273:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_2274:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 0 @ x, y
		Subsprite_2275:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_2276:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_2277:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_2278:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -8, 0 @ x, y
		Subsprite_2279:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -4, -4 @ x, y
		Subsprite_2280:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -4, -4 @ x, y
		Subsprite_2281:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -4, -4 @ x, y
		Subsprite_2282:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -4, -4 @ x, y
		Subsprite_2283:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -4, -4 @ x, y
		Subsprite_2284:
			.byte OAM_SIZE_64x32, 0 @ shape, unk_01(always 0)
			.byte -27, -30 @ x, y
		Subsprite_2285:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -27, 2 @ x, y
		Subsprite_2286:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte 5, 2 @ x, y
		Subsprite_2287:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -27, -30 @ x, y
		Subsprite_2288:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -27, 2 @ x, y
		Subsprite_2289:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 5, -30 @ x, y
		Subsprite_2290:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -19, -30 @ x, y
		Subsprite_2291:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -19, 2 @ x, y
		Subsprite_2292:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 13, -30 @ x, y
		Subsprite_2293:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 13, 2 @ x, y
		Subsprite_2294:
			.byte OAM_SIZE_64x64, 0 @ shape, unk_01(always 0)
			.byte -27, -30 @ x, y
		Subsprite_2295:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_2296:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 8, -8 @ x, y
		Subsprite_2297:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -16, 0 @ x, y
		Subsprite_2298:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -29 @ x, y
		Subsprite_2299:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -16, -29 @ x, y
		Subsprite_2300:
			.byte OAM_SIZE_64x64, 0 @ shape, unk_01(always 0)
			.byte -32, -32 @ x, y
		Subsprite_2301:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2302:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2303:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2304:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2305:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2306:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2307:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2308:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2309:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2310:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2311:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2312:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2313:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2314:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2315:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2316:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2317:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2318:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2319:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2320:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2321:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2322:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2323:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2324:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2325:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2326:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2327:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2328:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2329:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2330:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2331:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2332:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2333:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2334:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2335:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2336:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2337:
			.byte OAM_SIZE_64x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2338:
			.byte OAM_SIZE_64x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2339:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2340:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, 16 @ x, y
		Subsprite_2341:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -16 @ x, y
		Subsprite_2342:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -24, 16 @ x, y
		Subsprite_2343:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2344:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, 0 @ x, y
		Subsprite_2345:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -24, 32 @ x, y
		Subsprite_2346:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 8, 0 @ x, y
		Subsprite_2347:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, 0 @ x, y
		Subsprite_2348:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -24, 32 @ x, y
		Subsprite_2349:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 8, 0 @ x, y
		Subsprite_2350:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2351:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2352:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2353:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2354:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2355:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2356:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2357:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2358:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2359:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2360:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2361:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2362:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2363:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2364:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2365:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2366:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2367:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2368:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2369:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2370:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2371:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2372:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2373:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2374:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2375:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2376:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2377:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2378:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2379:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2380:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2381:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2382:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2383:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2384:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2385:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2386:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2387:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2388:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2389:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2390:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2391:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -24, -16 @ x, y
		Subsprite_2392:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2393:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2394:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2395:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2396:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2397:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -32 @ x, y
		Subsprite_2398:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -24, 0 @ x, y
		Subsprite_2399:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -32 @ x, y
		Subsprite_2400:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 8, 0 @ x, y
		Subsprite_2401:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2402:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2403:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2404:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2405:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 16, 8 @ x, y
		Subsprite_2406:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2407:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2408:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2409:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2410:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2411:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2412:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2413:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2414:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2415:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2416:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_2417:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_2418:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_2419:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_2420:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_2421:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_2422:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2423:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2424:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2425:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2426:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2427:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2428:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_2429:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_2430:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_2431:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2432:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2433:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2434:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2435:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 0 @ x, y
		Subsprite_2436:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 8 @ x, y
		Subsprite_2437:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2438:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 0 @ x, y
		Subsprite_2439:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 8 @ x, y
		Subsprite_2440:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2441:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2442:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_2443:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_2444:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 8 @ x, y
		Subsprite_2445:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2446:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_2447:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_2448:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 8 @ x, y
		Subsprite_2449:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2450:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2451:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2452:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_2453:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_2454:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 8 @ x, y
		Subsprite_2455:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2456:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_2457:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 0 @ x, y
		Subsprite_2458:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2459:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 0 @ x, y
		Subsprite_2460:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, -8 @ x, y
		Subsprite_2461:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_2462:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 0, -8 @ x, y
		Subsprite_2463:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_2464:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_2465:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 0, -8 @ x, y
		Subsprite_2466:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_2467:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 8 @ x, y
		Subsprite_2468:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2469:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2470:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2471:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2472:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2473:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2474:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_2475:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_2476:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_2477:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_2478:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_2479:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_2480:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_2481:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_2482:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_2483:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_2484:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 8 @ x, y
		Subsprite_2485:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 0, -8 @ x, y
		Subsprite_2486:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_2487:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 8 @ x, y
		Subsprite_2488:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 0, -8 @ x, y
		Subsprite_2489:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_2490:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 8 @ x, y
		Subsprite_2491:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 0, -8 @ x, y
		Subsprite_2492:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_2493:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_2494:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 8 @ x, y
		Subsprite_2495:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2496:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2497:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 0 @ x, y
		Subsprite_2498:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 8 @ x, y
		Subsprite_2499:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2500:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 16 @ x, y
		Subsprite_2501:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 24 @ x, y
		Subsprite_2502:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2503:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -8, 16 @ x, y
		Subsprite_2504:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 16, 0 @ x, y
		Subsprite_2505:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2506:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 16, -8 @ x, y
		Subsprite_2507:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 16, 8 @ x, y
		Subsprite_2508:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2509:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 16, -16 @ x, y
		Subsprite_2510:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 16, 0 @ x, y
		Subsprite_2511:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2512:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -24 @ x, y
		Subsprite_2513:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -32 @ x, y
		Subsprite_2514:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -32 @ x, y
		Subsprite_2515:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, 0 @ x, y
		Subsprite_2516:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -32 @ x, y
		Subsprite_2517:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -24, 0 @ x, y
		Subsprite_2518:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 8, -32 @ x, y
		Subsprite_2519:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, 0 @ x, y
		Subsprite_2520:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -24 @ x, y
		Subsprite_2521:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -24, 8 @ x, y
		Subsprite_2522:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -24 @ x, y
		Subsprite_2523:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 8, 8 @ x, y
		Subsprite_2524:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2525:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte -24, -16 @ x, y
		Subsprite_2526:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -24, 0 @ x, y
		Subsprite_2527:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -16 @ x, y
		Subsprite_2528:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2529:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -32 @ x, y
		Subsprite_2530:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, 0 @ x, y
		Subsprite_2531:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -24 @ x, y
		Subsprite_2532:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -24, 8 @ x, y
		Subsprite_2533:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 8, -24 @ x, y
		Subsprite_2534:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -32, -16 @ x, y
		Subsprite_2535:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 0, -16 @ x, y
		Subsprite_2536:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -16 @ x, y
		Subsprite_2537:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -24, 16 @ x, y
		Subsprite_2538:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2539:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2540:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, 16 @ x, y
		Subsprite_2541:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2542:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 16 @ x, y
		Subsprite_2543:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 24 @ x, y
		Subsprite_2544:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2545:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 16 @ x, y
		Subsprite_2546:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte 0, 24 @ x, y
		Subsprite_2547:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2548:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -8, 16 @ x, y
		Subsprite_2549:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 16, 0 @ x, y
		Subsprite_2550:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2551:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 16, -8 @ x, y
		Subsprite_2552:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2553:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 16 @ x, y
		Subsprite_2554:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -32 @ x, y
		Subsprite_2555:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -32 @ x, y
		Subsprite_2556:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, 0 @ x, y
		Subsprite_2557:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -32 @ x, y
		Subsprite_2558:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 8, -32 @ x, y
		Subsprite_2559:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 8, 0 @ x, y
		Subsprite_2560:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -24 @ x, y
		Subsprite_2561:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -24, 8 @ x, y
		Subsprite_2562:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -24 @ x, y
		Subsprite_2563:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 8, 8 @ x, y
		Subsprite_2564:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -16 @ x, y
		Subsprite_2565:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2566:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -16 @ x, y
		Subsprite_2567:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2568:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_2569:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_2570:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_2571:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_2572:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_2573:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_2574:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_2575:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_2576:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_2577:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_2578:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_2579:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_2580:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_2581:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2582:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_2583:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2584:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_2585:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_2586:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2587:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2588:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_2589:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_2590:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, 0 @ x, y
		Subsprite_2591:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_2592:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_2593:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 8 @ x, y
		Subsprite_2594:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_2595:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2596:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 8 @ x, y
		Subsprite_2597:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2598:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_2599:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte 0, -16 @ x, y
		Subsprite_2600:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 8 @ x, y
		Subsprite_2601:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2602:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_2603:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 8 @ x, y
		Subsprite_2604:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, -16 @ x, y
		Subsprite_2605:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_2606:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, 0 @ x, y
		Subsprite_2607:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -16, 0 @ x, y
		Subsprite_2608:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_2609:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, 0 @ x, y
		Subsprite_2610:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -16, 0 @ x, y
		Subsprite_2611:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_2612:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -11 @ x, y
		Subsprite_2613:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 5 @ x, y
		Subsprite_2614:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -11 @ x, y
		Subsprite_2615:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, 5 @ x, y
		Subsprite_2616:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -11 @ x, y
		Subsprite_2617:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, 5 @ x, y
		Subsprite_2618:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -11 @ x, y
		Subsprite_2619:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -11 @ x, y
		Subsprite_2620:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -11 @ x, y
		Subsprite_2621:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -11 @ x, y
		Subsprite_2622:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -16, -3 @ x, y
		Subsprite_2623:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -16, -11 @ x, y
		Subsprite_2624:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 0, -11 @ x, y
		Subsprite_2625:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -11 @ x, y
		Subsprite_2626:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -16, -3 @ x, y
		Subsprite_2627:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -11 @ x, y
		Subsprite_2628:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -11 @ x, y
		Subsprite_2629:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -16, -19 @ x, y
		Subsprite_2630:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -11 @ x, y
		Subsprite_2631:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -19 @ x, y
		Subsprite_2632:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -3 @ x, y
		Subsprite_2633:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -19 @ x, y
		Subsprite_2634:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -3 @ x, y
		Subsprite_2635:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -19 @ x, y
		Subsprite_2636:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -3 @ x, y
		Subsprite_2637:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -19 @ x, y
		Subsprite_2638:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -11 @ x, y
		Subsprite_2639:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -8, -19 @ x, y
		Subsprite_2640:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -11 @ x, y
		Subsprite_2641:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, -19 @ x, y
		Subsprite_2642:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -16, -3 @ x, y
		Subsprite_2643:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -11 @ x, y
		Subsprite_2644:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -16, -11 @ x, y
		Subsprite_2645:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -11 @ x, y
		Subsprite_2646:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -11 @ x, y
		Subsprite_2647:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -11 @ x, y
		Subsprite_2648:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -16, -11 @ x, y
		Subsprite_2649:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2650:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2651:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2652:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2653:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2654:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2655:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2656:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2657:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2658:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2659:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2660:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2661:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_2662:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2663:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2664:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2665:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -8, -48 @ x, y
		Subsprite_2666:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2667:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2668:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2669:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2670:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2671:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -24, -16 @ x, y
		Subsprite_2672:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2673:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2674:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2675:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2676:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2677:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2678:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2679:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2680:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2681:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2682:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2683:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2684:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2685:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2686:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2687:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2688:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2689:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2690:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2691:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2692:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -32 @ x, y
		Subsprite_2693:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -24, 0 @ x, y
		Subsprite_2694:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -32 @ x, y
		Subsprite_2695:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 8, 0 @ x, y
		Subsprite_2696:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2697:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2698:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2699:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2700:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2701:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2702:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2703:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2704:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2705:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2706:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2707:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2708:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2709:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2710:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2711:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2712:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2713:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2714:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2715:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2716:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2717:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2718:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2719:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -22, -29 @ x, y
		Subsprite_2720:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 10, -29 @ x, y
		Subsprite_2721:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 10, 3 @ x, y
		Subsprite_2722:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -22, -29 @ x, y
		Subsprite_2723:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 10, -29 @ x, y
		Subsprite_2724:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 10, 3 @ x, y
		Subsprite_2725:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -20, -20 @ x, y
		Subsprite_2726:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 12, -20 @ x, y
		Subsprite_2727:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte 4, -20 @ x, y
		Subsprite_2728:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 36, -20 @ x, y
		Subsprite_2729:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -28, 4 @ x, y
		Subsprite_2730:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -28, 20 @ x, y
		Subsprite_2731:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -12, -4 @ x, y
		Subsprite_2732:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -28, 4 @ x, y
		Subsprite_2733:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -28, 20 @ x, y
		Subsprite_2734:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -20, -4 @ x, y
		Subsprite_2735:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -28, -4 @ x, y
		Subsprite_2736:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -28, -4 @ x, y
		Subsprite_2737:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -28, 4 @ x, y
		Subsprite_2738:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -28, 20 @ x, y
		Subsprite_2739:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -28, -4 @ x, y
		Subsprite_2740:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -28, 4 @ x, y
		Subsprite_2741:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -20, 12 @ x, y
		Subsprite_2742:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -28, 12 @ x, y
		Subsprite_2743:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte 0, 0 @ x, y
		Subsprite_2744:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte 0, 32 @ x, y
		Subsprite_2745:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 32, 0 @ x, y
		Subsprite_2746:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 32, 32 @ x, y
		Subsprite_2747:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte 0, 0 @ x, y
		Subsprite_2748:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 32, 0 @ x, y
		Subsprite_2749:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 32, 32 @ x, y
		Subsprite_2750:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte 0, 0 @ x, y
		Subsprite_2751:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 32, 0 @ x, y
		Subsprite_2752:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 32, 32 @ x, y
		Subsprite_2753:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte 0, 0 @ x, y
		Subsprite_2754:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 32, 0 @ x, y
		Subsprite_2755:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 32, 32 @ x, y
		Subsprite_2756:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte 0, 0 @ x, y
		Subsprite_2757:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte 0, 32 @ x, y
		Subsprite_2758:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 32, 0 @ x, y
		Subsprite_2759:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 32, 32 @ x, y
		Subsprite_2760:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte 0, 0 @ x, y
		Subsprite_2761:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte 0, 32 @ x, y
		Subsprite_2762:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 32, 0 @ x, y
		Subsprite_2763:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 32, 32 @ x, y
		Subsprite_2764:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -14, -32 @ x, y
		Subsprite_2765:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -14, 0 @ x, y
		Subsprite_2766:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -14, -32 @ x, y
		Subsprite_2767:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -14, 0 @ x, y
		Subsprite_2768:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -14, -32 @ x, y
		Subsprite_2769:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -14, 0 @ x, y
		Subsprite_2770:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -14, -32 @ x, y
		Subsprite_2771:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -14, 0 @ x, y
		Subsprite_2772:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -14, -32 @ x, y
		Subsprite_2773:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 2, -24 @ x, y
		Subsprite_2774:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -14, 0 @ x, y
		Subsprite_2775:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -14, -32 @ x, y
		Subsprite_2776:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -14, 0 @ x, y
		Subsprite_2777:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -14, -32 @ x, y
		Subsprite_2778:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -14, 0 @ x, y
		Subsprite_2779:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -6, -8 @ x, y
		Subsprite_2780:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -14, -8 @ x, y
		Subsprite_2781:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -14, -16 @ x, y
		Subsprite_2782:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -14, -24 @ x, y
		Subsprite_2783:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -14, 8 @ x, y
		Subsprite_2784:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -6, -32 @ x, y
		Subsprite_2785:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte -14, -24 @ x, y
		Subsprite_2786:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -6, 0 @ x, y
		Subsprite_2787:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -14, -16 @ x, y
		Subsprite_2788:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -14, 0 @ x, y
		Subsprite_2789:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 2, -16 @ x, y
		Subsprite_2790:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 2, 0 @ x, y
		Subsprite_2791:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -14, -8 @ x, y
		Subsprite_2792:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -14, 0 @ x, y
		Subsprite_2793:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 2, 0 @ x, y
		Subsprite_2794:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -14, -32 @ x, y
		Subsprite_2795:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 2, -32 @ x, y
		Subsprite_2796:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -14, 0 @ x, y
		Subsprite_2797:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 2, 0 @ x, y
		Subsprite_2798:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -14, -24 @ x, y
		Subsprite_2799:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -22, -24 @ x, y
		Subsprite_2800:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -22, 8 @ x, y
		Subsprite_2801:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 10, -24 @ x, y
		Subsprite_2802:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -14, -32 @ x, y
		Subsprite_2803:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -14, 0 @ x, y
		Subsprite_2804:
			.byte OAM_SIZE_64x64, 0 @ shape, unk_01(always 0)
			.byte -30, -40 @ x, y
		Subsprite_2805:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -22, -32 @ x, y
		Subsprite_2806:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 10, -32 @ x, y
		Subsprite_2807:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -22, 0 @ x, y
		Subsprite_2808:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -14, -40 @ x, y
		Subsprite_2809:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -14, -32 @ x, y
		Subsprite_2810:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -14, 0 @ x, y
		Subsprite_2811:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -14, -16 @ x, y
		Subsprite_2812:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -14, 0 @ x, y
		Subsprite_2813:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -14, -32 @ x, y
		Subsprite_2814:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -30, -24 @ x, y
		Subsprite_2815:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 2, -24 @ x, y
		Subsprite_2816:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -22, -40 @ x, y
		Subsprite_2817:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -22, -8 @ x, y
		Subsprite_2818:
			.byte OAM_SIZE_64x32, 0 @ shape, unk_01(always 0)
			.byte -30, -24 @ x, y
		Subsprite_2819:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte 2, 8 @ x, y
		Subsprite_2820:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -22, -24 @ x, y
		Subsprite_2821:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 10, -24 @ x, y
		Subsprite_2822:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -14, -24 @ x, y
		Subsprite_2823:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -14, 8 @ x, y
		Subsprite_2824:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 18, -24 @ x, y
		Subsprite_2825:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -14, -32 @ x, y
		Subsprite_2826:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -14, 0 @ x, y
		Subsprite_2827:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -14, -40 @ x, y
		Subsprite_2828:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -14, -40 @ x, y
		Subsprite_2829:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -14, -40 @ x, y
		Subsprite_2830:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -14, -40 @ x, y
		Subsprite_2831:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -14, -40 @ x, y
		Subsprite_2832:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -14, -32 @ x, y
		Subsprite_2833:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -14, 0 @ x, y
		Subsprite_2834:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -14, -16 @ x, y
		Subsprite_2835:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_2836:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_2837:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_2838:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2839:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2840:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2841:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2842:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2843:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2844:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2845:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2846:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2847:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2848:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2849:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2850:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2851:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2852:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2853:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2854:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2855:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2856:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2857:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2858:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2859:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2860:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2861:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2862:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2863:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2864:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2865:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2866:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2867:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2868:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2869:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2870:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2871:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2872:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2873:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2874:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2875:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2876:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2877:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2878:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2879:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2880:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2881:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2882:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2883:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2884:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2885:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2886:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2887:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2888:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2889:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2890:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2891:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2892:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2893:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2894:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2895:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2896:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2897:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2898:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2899:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2900:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2901:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2902:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2903:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2904:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2905:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2906:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2907:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2908:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2909:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2910:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2911:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2912:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2913:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2914:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2915:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2916:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2917:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2918:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2919:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_2920:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_2921:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_2922:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -17, -17 @ x, y
		Subsprite_2923:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte -25, -9 @ x, y
		Subsprite_2924:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 15, -9 @ x, y
		Subsprite_2925:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -25, -25 @ x, y
		Subsprite_2926:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 7, -25 @ x, y
		Subsprite_2927:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -25, 7 @ x, y
		Subsprite_2928:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte 7, 7 @ x, y
		Subsprite_2929:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -25, -49 @ x, y
		Subsprite_2930:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 7, -49 @ x, y
		Subsprite_2931:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 7, -17 @ x, y
		Subsprite_2932:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -25, -49 @ x, y
		Subsprite_2933:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 7, -49 @ x, y
		Subsprite_2934:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 7, -17 @ x, y
		Subsprite_2935:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -25, -49 @ x, y
		Subsprite_2936:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 7, -49 @ x, y
		Subsprite_2937:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 7, -17 @ x, y
		Subsprite_2938:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -25, -49 @ x, y
		Subsprite_2939:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 7, -49 @ x, y
		Subsprite_2940:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 7, -17 @ x, y
		Subsprite_2941:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -25, -49 @ x, y
		Subsprite_2942:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 7, -49 @ x, y
		Subsprite_2943:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 7, -17 @ x, y
		Subsprite_2944:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -25, -49 @ x, y
		Subsprite_2945:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 7, -49 @ x, y
		Subsprite_2946:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 7, -17 @ x, y
		Subsprite_2947:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -25, -49 @ x, y
		Subsprite_2948:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 7, -49 @ x, y
		Subsprite_2949:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 7, -17 @ x, y
		Subsprite_2950:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -25, -25 @ x, y
		Subsprite_2951:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 7, -25 @ x, y
		Subsprite_2952:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -25, 7 @ x, y
		Subsprite_2953:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte 7, 7 @ x, y
		Subsprite_2954:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -25, -49 @ x, y
		Subsprite_2955:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 7, -49 @ x, y
		Subsprite_2956:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 7, -17 @ x, y
		Subsprite_2957:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -25, -49 @ x, y
		Subsprite_2958:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 7, -49 @ x, y
		Subsprite_2959:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 7, -17 @ x, y
		Subsprite_2960:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -25, -49 @ x, y
		Subsprite_2961:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 7, -49 @ x, y
		Subsprite_2962:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 7, -17 @ x, y
		Subsprite_2963:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -25, -49 @ x, y
		Subsprite_2964:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 7, -49 @ x, y
		Subsprite_2965:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 7, -17 @ x, y
		Subsprite_2966:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -25, -49 @ x, y
		Subsprite_2967:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 7, -49 @ x, y
		Subsprite_2968:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 7, -17 @ x, y
		Subsprite_2969:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -25, -49 @ x, y
		Subsprite_2970:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 7, -49 @ x, y
		Subsprite_2971:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 7, -17 @ x, y
		Subsprite_2972:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -25, -33 @ x, y
		Subsprite_2973:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -25, -1 @ x, y
		Subsprite_2974:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 7, -33 @ x, y
		Subsprite_2975:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 7, -1 @ x, y
		Subsprite_2976:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -24 @ x, y
		Subsprite_2977:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -24, 8 @ x, y
		Subsprite_2978:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -24 @ x, y
		Subsprite_2979:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 8, 8 @ x, y
		Subsprite_2980:
			.byte OAM_SIZE_64x64, 0 @ shape, unk_01(always 0)
			.byte -32, -32 @ x, y
		Subsprite_2981:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -7, -5 @ x, y
		Subsprite_2982:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 9, 3 @ x, y
		Subsprite_2983:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 9, 19 @ x, y
		Subsprite_2984:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -7, -5 @ x, y
		Subsprite_2985:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 9, 3 @ x, y
		Subsprite_2986:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 9, 19 @ x, y
		Subsprite_2987:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -7, -5 @ x, y
		Subsprite_2988:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 9, 3 @ x, y
		Subsprite_2989:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 9, 19 @ x, y
		Subsprite_2990:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -7, -5 @ x, y
		Subsprite_2991:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 9, 3 @ x, y
		Subsprite_2992:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 9, 19 @ x, y
		Subsprite_2993:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, 0 @ x, y
		Subsprite_2994:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, 32 @ x, y
		Subsprite_2995:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 16, 0 @ x, y
		Subsprite_2996:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, 0 @ x, y
		Subsprite_2997:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, 32 @ x, y
		Subsprite_2998:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 16, 0 @ x, y
		Subsprite_2999:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_3000:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_3001:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_3002:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_3003:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_3004:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_3005:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_3006:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_3007:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_3008:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_3009:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_3010:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_3011:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_3012:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_3013:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_3014:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_3015:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_3016:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_3017:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_3018:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_3019:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_3020:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_3021:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_3022:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_3023:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_3024:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_3025:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_3026:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -40 @ x, y
		Subsprite_3027:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -40 @ x, y
		Subsprite_3028:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -24, -8 @ x, y
		Subsprite_3029:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte 8, -8 @ x, y
		Subsprite_3030:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_3031:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_3032:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_3033:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -4, -4 @ x, y
		Subsprite_3034:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -4, -4 @ x, y
		Subsprite_3035:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -4, -4 @ x, y
		Subsprite_3036:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -4, -4 @ x, y
		Subsprite_3037:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -33 @ x, y
		Subsprite_3038:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -33 @ x, y
		Subsprite_3039:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -1 @ x, y
		Subsprite_3040:
			.byte OAM_SIZE_64x64, 0 @ shape, unk_01(always 0)
			.byte -24, -32 @ x, y
		Subsprite_3041:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_3042:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_3043:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_3044:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_3045:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_3046:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_3047:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_3048:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_3049:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_3050:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_3051:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_3052:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_3053:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_3054:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_3055:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_3056:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_3057:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_3058:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_3059:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_3060:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_3061:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_3062:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_3063:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_3064:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_3065:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_3066:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_3067:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_3068:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_3069:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_3070:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_3071:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_3072:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_3073:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_3074:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_3075:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_3076:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_3077:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_3078:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_3079:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_3080:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_3081:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -24, -16 @ x, y
		Subsprite_3082:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_3083:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_3084:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -24 @ x, y
		Subsprite_3085:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_3086:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 16, -24 @ x, y
		Subsprite_3087:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 16, 8 @ x, y
		Subsprite_3088:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_3089:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -8, 0 @ x, y
		Subsprite_3090:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -16, -24 @ x, y
		Subsprite_3091:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -24 @ x, y
		Subsprite_3092:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_3093:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 16, -24 @ x, y
		Subsprite_3094:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 16, 8 @ x, y
		Subsprite_3095:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -24 @ x, y
		Subsprite_3096:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_3097:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 16, -24 @ x, y
		Subsprite_3098:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 16, 8 @ x, y
		Subsprite_3099:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -24 @ x, y
		Subsprite_3100:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_3101:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 16, -24 @ x, y
		Subsprite_3102:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 16, 8 @ x, y
		Subsprite_3103:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -24 @ x, y
		Subsprite_3104:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_3105:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 16, -24 @ x, y
		Subsprite_3106:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 16, 8 @ x, y
		Subsprite_3107:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_3108:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -8, 0 @ x, y
		Subsprite_3109:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -16, -24 @ x, y
		Subsprite_3110:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_3111:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -8, 0 @ x, y
		Subsprite_3112:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -16, -24 @ x, y
		Subsprite_3113:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -8, -24 @ x, y
		Subsprite_3114:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_3115:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_3116:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -24 @ x, y
		Subsprite_3117:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_3118:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 16, -24 @ x, y
		Subsprite_3119:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -24 @ x, y
		Subsprite_3120:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_3121:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 16, -24 @ x, y
		Subsprite_3122:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -24 @ x, y
		Subsprite_3123:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_3124:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 16, -24 @ x, y
		Subsprite_3125:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -24 @ x, y
		Subsprite_3126:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_3127:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 16, -24 @ x, y
		Subsprite_3128:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -24 @ x, y
		Subsprite_3129:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_3130:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 16, -24 @ x, y
		Subsprite_3131:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -24 @ x, y
		Subsprite_3132:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_3133:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 16, -24 @ x, y
		Subsprite_3134:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -24 @ x, y
		Subsprite_3135:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 16, -24 @ x, y
		Subsprite_3136:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_3137:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -16, -32 @ x, y
		Subsprite_3138:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 16, -32 @ x, y
		Subsprite_3139:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 16, 0 @ x, y
		Subsprite_3140:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -16, -32 @ x, y
		Subsprite_3141:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 16, -32 @ x, y
		Subsprite_3142:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 16, 0 @ x, y
		Subsprite_3143:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -16, -32 @ x, y
		Subsprite_3144:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 16, -32 @ x, y
		Subsprite_3145:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 16, 0 @ x, y
		Subsprite_3146:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -24 @ x, y
		Subsprite_3147:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -24 @ x, y
		Subsprite_3148:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -24, 8 @ x, y
		Subsprite_3149:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -24 @ x, y
		Subsprite_3150:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -24 @ x, y
		Subsprite_3151:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -24, 8 @ x, y
		Subsprite_3152:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -24 @ x, y
		Subsprite_3153:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -24 @ x, y
		Subsprite_3154:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -24, 8 @ x, y
		Subsprite_3155:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -24 @ x, y
		Subsprite_3156:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -24 @ x, y
		Subsprite_3157:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -24, 8 @ x, y
		Subsprite_3158:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte 8, 8 @ x, y
		Subsprite_3159:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -24 @ x, y
		Subsprite_3160:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -24 @ x, y
		Subsprite_3161:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -24, 8 @ x, y
		Subsprite_3162:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte 8, 8 @ x, y
		Subsprite_3163:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -24 @ x, y
		Subsprite_3164:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -24 @ x, y
		Subsprite_3165:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -24, 8 @ x, y
		Subsprite_3166:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte 8, 8 @ x, y
		Subsprite_3167:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -24 @ x, y
		Subsprite_3168:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_3169:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 16, -24 @ x, y
		Subsprite_3170:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 16, 8 @ x, y
		Subsprite_3171:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -24 @ x, y
		Subsprite_3172:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_3173:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 16, -24 @ x, y
		Subsprite_3174:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 16, 8 @ x, y
		Subsprite_3175:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -24 @ x, y
		Subsprite_3176:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_3177:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 16, -24 @ x, y
		Subsprite_3178:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 16, 8 @ x, y
		Subsprite_3179:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -24 @ x, y
		Subsprite_3180:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_3181:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 16, -24 @ x, y
		Subsprite_3182:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 16, 8 @ x, y
		Subsprite_3183:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -24 @ x, y
		Subsprite_3184:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_3185:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 16, -24 @ x, y
		Subsprite_3186:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 16, 8 @ x, y
		Subsprite_3187:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -24 @ x, y
		Subsprite_3188:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_3189:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 16, -24 @ x, y
		Subsprite_3190:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -8, -24 @ x, y
		Subsprite_3191:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_3192:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_3193:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -8, -24 @ x, y
		Subsprite_3194:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_3195:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_3196:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -8, -24 @ x, y
		Subsprite_3197:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_3198:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_3199:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -24 @ x, y
		Subsprite_3200:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_3201:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 16, -24 @ x, y
		Subsprite_3202:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -24 @ x, y
		Subsprite_3203:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -24 @ x, y
		Subsprite_3204:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -24, 8 @ x, y
		Subsprite_3205:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -24 @ x, y
		Subsprite_3206:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_3207:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 16, -24 @ x, y
		Subsprite_3208:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -24 @ x, y
		Subsprite_3209:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_3210:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 16, -24 @ x, y
		Subsprite_3211:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -24 @ x, y
		Subsprite_3212:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_3213:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 16, -24 @ x, y
		Subsprite_3214:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 16, 8 @ x, y
		Subsprite_3215:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -24 @ x, y
		Subsprite_3216:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -24, 8 @ x, y
		Subsprite_3217:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -24 @ x, y
		Subsprite_3218:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 8, 8 @ x, y
		Subsprite_3219:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -24 @ x, y
		Subsprite_3220:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -24, 8 @ x, y
		Subsprite_3221:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -24 @ x, y
		Subsprite_3222:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 8, 8 @ x, y
		Subsprite_3223:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -24 @ x, y
		Subsprite_3224:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_3225:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 16, -24 @ x, y
		Subsprite_3226:
			.byte OAM_SIZE_64x32, 0 @ shape, unk_01(always 0)
			.byte -32, -24 @ x, y
		Subsprite_3227:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -32, 8 @ x, y
		Subsprite_3228:
			.byte OAM_SIZE_64x32, 0 @ shape, unk_01(always 0)
			.byte -32, -24 @ x, y
		Subsprite_3229:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -32, 8 @ x, y
		Subsprite_3230:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -16, -32 @ x, y
		Subsprite_3231:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 16, -32 @ x, y
		Subsprite_3232:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 16, 0 @ x, y
		Subsprite_3233:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -16, -32 @ x, y
		Subsprite_3234:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 16, -32 @ x, y
		Subsprite_3235:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 16, 0 @ x, y
		Subsprite_3236:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -32 @ x, y
		Subsprite_3237:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, 0 @ x, y
		Subsprite_3238:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 16, -32 @ x, y
		Subsprite_3239:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -32 @ x, y
		Subsprite_3240:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, 0 @ x, y
		Subsprite_3241:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 16, -32 @ x, y
		Subsprite_3242:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -24 @ x, y
		Subsprite_3243:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_3244:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 16, -24 @ x, y
		Subsprite_3245:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -24 @ x, y
		Subsprite_3246:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_3247:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 16, -24 @ x, y
		Subsprite_3248:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 16, 8 @ x, y
		Subsprite_3249:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -24 @ x, y
		Subsprite_3250:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -24 @ x, y
		Subsprite_3251:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -24, 8 @ x, y
		Subsprite_3252:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte 8, 8 @ x, y
		Subsprite_3253:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -24 @ x, y
		Subsprite_3254:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -24 @ x, y
		Subsprite_3255:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte 8, 8 @ x, y
		Subsprite_3256:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -24 @ x, y
		Subsprite_3257:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_3258:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 16, -24 @ x, y
		Subsprite_3259:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 16, 8 @ x, y
		Subsprite_3260:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -24 @ x, y
		Subsprite_3261:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_3262:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 16, -24 @ x, y
		Subsprite_3263:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 16, 8 @ x, y
		Subsprite_3264:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -24 @ x, y
		Subsprite_3265:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_3266:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 16, -24 @ x, y
		Subsprite_3267:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 16, 8 @ x, y
		Subsprite_3268:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -24 @ x, y
		Subsprite_3269:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_3270:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 16, -24 @ x, y
		Subsprite_3271:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -24 @ x, y
		Subsprite_3272:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -24 @ x, y
		Subsprite_3273:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -24, 8 @ x, y
		Subsprite_3274:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -32 @ x, y
		Subsprite_3275:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -32 @ x, y
		Subsprite_3276:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -24 @ x, y
		Subsprite_3277:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -24 @ x, y
		Subsprite_3278:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -24, 8 @ x, y
		Subsprite_3279:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -24 @ x, y
		Subsprite_3280:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -24 @ x, y
		Subsprite_3281:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -24, 8 @ x, y
		Subsprite_3282:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -24 @ x, y
		Subsprite_3283:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_3284:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 16, -24 @ x, y
		Subsprite_3285:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -8, -24 @ x, y
		Subsprite_3286:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_3287:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -24 @ x, y
		Subsprite_3288:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 16, -24 @ x, y
		Subsprite_3289:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -8, -24 @ x, y
		Subsprite_3290:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_3291:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -24 @ x, y
		Subsprite_3292:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_3293:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -24 @ x, y
		Subsprite_3294:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -24, 8 @ x, y
		Subsprite_3295:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 8, -24 @ x, y
		Subsprite_3296:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -24 @ x, y
		Subsprite_3297:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_3298:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 16, -16 @ x, y
		Subsprite_3299:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte -24, -8 @ x, y
		Subsprite_3300:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -16 @ x, y
		Subsprite_3301:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_3302:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -24 @ x, y
		Subsprite_3303:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -24 @ x, y
		Subsprite_3304:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -24, 8 @ x, y
		Subsprite_3305:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -24 @ x, y
		Subsprite_3306:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 8, -24 @ x, y
		Subsprite_3307:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -24 @ x, y
		Subsprite_3308:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -24 @ x, y
		Subsprite_3309:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -24, 8 @ x, y
		Subsprite_3310:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -16 @ x, y
		Subsprite_3311:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_3312:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -16 @ x, y
		Subsprite_3313:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_3314:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -24, 16 @ x, y
		Subsprite_3315:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -32 @ x, y
		Subsprite_3316:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, 0 @ x, y
		Subsprite_3317:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -32 @ x, y
		Subsprite_3318:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, 0 @ x, y
		Subsprite_3319:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 16, -32 @ x, y
		Subsprite_3320:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_3321:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 16, -16 @ x, y
		Subsprite_3322:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -16 @ x, y
		Subsprite_3323:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_3324:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -24 @ x, y
		Subsprite_3325:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_3326:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -24 @ x, y
		Subsprite_3327:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -24, 8 @ x, y
		Subsprite_3328:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 8, -24 @ x, y
		Subsprite_3329:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -24 @ x, y
		Subsprite_3330:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -24 @ x, y
		Subsprite_3331:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -24, 8 @ x, y
		Subsprite_3332:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -24 @ x, y
		Subsprite_3333:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -24 @ x, y
		Subsprite_3334:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -24, 8 @ x, y
		Subsprite_3335:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -43 @ x, y
		Subsprite_3336:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -11 @ x, y
		Subsprite_3337:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 16, -43 @ x, y
		Subsprite_3338:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 16, -11 @ x, y
		Subsprite_3339:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -27 @ x, y
		Subsprite_3340:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 0, -43 @ x, y
		Subsprite_3341:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 16, -19 @ x, y
		Subsprite_3342:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -27 @ x, y
		Subsprite_3343:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 0, -43 @ x, y
		Subsprite_3344:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -43 @ x, y
		Subsprite_3345:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -11 @ x, y
		Subsprite_3346:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -16, -43 @ x, y
		Subsprite_3347:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -16, -43 @ x, y
		Subsprite_3348:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 16, -43 @ x, y
		Subsprite_3349:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -27 @ x, y
		Subsprite_3350:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 0, -43 @ x, y
		Subsprite_3351:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -16, 5 @ x, y
		Subsprite_3352:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -43 @ x, y
		Subsprite_3353:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -11 @ x, y
		Subsprite_3354:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -35 @ x, y
		Subsprite_3355:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -3 @ x, y
		Subsprite_3356:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 16, -35 @ x, y
		Subsprite_3357:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -16, -43 @ x, y
		Subsprite_3358:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 16, -43 @ x, y
		Subsprite_3359:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 16, -11 @ x, y
		Subsprite_3360:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -35 @ x, y
		Subsprite_3361:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -3 @ x, y
		Subsprite_3362:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -35 @ x, y
		Subsprite_3363:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -3 @ x, y
		Subsprite_3364:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -27 @ x, y
		Subsprite_3365:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 16, -19 @ x, y
		Subsprite_3366:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -16, -35 @ x, y
		Subsprite_3367:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -35 @ x, y
		Subsprite_3368:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -3 @ x, y
		Subsprite_3369:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 16, -35 @ x, y
		Subsprite_3370:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 16, -3 @ x, y
		Subsprite_3371:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -35 @ x, y
		Subsprite_3372:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, -3 @ x, y
		Subsprite_3373:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -35 @ x, y
		Subsprite_3374:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, -3 @ x, y
		Subsprite_3375:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -35 @ x, y
		Subsprite_3376:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -3 @ x, y
		Subsprite_3377:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -27 @ x, y
		Subsprite_3378:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -35 @ x, y
		Subsprite_3379:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 8, -35 @ x, y
		Subsprite_3380:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -35 @ x, y
		Subsprite_3381:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -3 @ x, y
		Subsprite_3382:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 16, -35 @ x, y
		Subsprite_3383:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -19 @ x, y
		Subsprite_3384:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte 8, -27 @ x, y
		Subsprite_3385:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 16, -19 @ x, y
		Subsprite_3386:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -19 @ x, y
		Subsprite_3387:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte 8, -27 @ x, y
		Subsprite_3388:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 16, -19 @ x, y
		Subsprite_3389:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -19 @ x, y
		Subsprite_3390:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte 8, -27 @ x, y
		Subsprite_3391:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 16, -19 @ x, y
		Subsprite_3392:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -19 @ x, y
		Subsprite_3393:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte 8, -27 @ x, y
		Subsprite_3394:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 16, -19 @ x, y
		Subsprite_3395:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -19 @ x, y
		Subsprite_3396:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte 8, -27 @ x, y
		Subsprite_3397:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 16, -19 @ x, y
		Subsprite_3398:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -27 @ x, y
		Subsprite_3399:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -16, -35 @ x, y
		Subsprite_3400:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, -35 @ x, y
		Subsprite_3401:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -35 @ x, y
		Subsprite_3402:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, -3 @ x, y
		Subsprite_3403:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -27 @ x, y
		Subsprite_3404:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte -24, -27 @ x, y
		Subsprite_3405:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -8, 5 @ x, y
		Subsprite_3406:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -19 @ x, y
		Subsprite_3407:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -24, -3 @ x, y
		Subsprite_3408:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -19 @ x, y
		Subsprite_3409:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -19 @ x, y
		Subsprite_3410:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -19 @ x, y
		Subsprite_3411:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -19 @ x, y
		Subsprite_3412:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -35 @ x, y
		Subsprite_3413:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -35 @ x, y
		Subsprite_3414:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -24, -3 @ x, y
		Subsprite_3415:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte 8, -3 @ x, y
		Subsprite_3416:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -35 @ x, y
		Subsprite_3417:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -24, -3 @ x, y
		Subsprite_3418:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -35 @ x, y
		Subsprite_3419:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 8, -3 @ x, y
		Subsprite_3420:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -35 @ x, y
		Subsprite_3421:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -24, -3 @ x, y
		Subsprite_3422:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -35 @ x, y
		Subsprite_3423:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 8, -3 @ x, y
		Subsprite_3424:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -35 @ x, y
		Subsprite_3425:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -24, -3 @ x, y
		Subsprite_3426:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -35 @ x, y
		Subsprite_3427:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 8, -3 @ x, y
		Subsprite_3428:
			.byte OAM_SIZE_64x32, 0 @ shape, unk_01(always 0)
			.byte -32, -35 @ x, y
		Subsprite_3429:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -32, -3 @ x, y
		Subsprite_3430:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte 0, -3 @ x, y
		Subsprite_3431:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -35 @ x, y
		Subsprite_3432:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -3 @ x, y
		Subsprite_3433:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 16, -35 @ x, y
		Subsprite_3434:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 16, -3 @ x, y
		Subsprite_3435:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -35 @ x, y
		Subsprite_3436:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -24, -3 @ x, y
		Subsprite_3437:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -35 @ x, y
		Subsprite_3438:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 8, -3 @ x, y
		Subsprite_3439:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -35 @ x, y
		Subsprite_3440:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -24, -3 @ x, y
		Subsprite_3441:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -35 @ x, y
		Subsprite_3442:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 8, -3 @ x, y
		Subsprite_3443:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -35 @ x, y
		Subsprite_3444:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -3 @ x, y
		Subsprite_3445:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -35 @ x, y
		Subsprite_3446:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -3 @ x, y
		Subsprite_3447:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -19 @ x, y
		Subsprite_3448:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -35 @ x, y
		Subsprite_3449:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 8, -27 @ x, y
		Subsprite_3450:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -35 @ x, y
		Subsprite_3451:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -3 @ x, y
		Subsprite_3452:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -16, -35 @ x, y
		Subsprite_3453:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 0, -35 @ x, y
		Subsprite_3454:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -16, -3 @ x, y
		Subsprite_3455:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, -3 @ x, y
		Subsprite_3456:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -35 @ x, y
		Subsprite_3457:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -24, -3 @ x, y
		Subsprite_3458:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 8, -35 @ x, y
		Subsprite_3459:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -16, -35 @ x, y
		Subsprite_3460:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 0, -35 @ x, y
		Subsprite_3461:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -16, -3 @ x, y
		Subsprite_3462:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 0, -3 @ x, y
		Subsprite_3463:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -27 @ x, y
		Subsprite_3464:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -16, -35 @ x, y
		Subsprite_3465:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, -35 @ x, y
		Subsprite_3466:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -27 @ x, y
		Subsprite_3467:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -43 @ x, y
		Subsprite_3468:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -35 @ x, y
		Subsprite_3469:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -24, -3 @ x, y
		Subsprite_3470:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 8, -35 @ x, y
		Subsprite_3471:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, -3 @ x, y
		Subsprite_3472:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -35 @ x, y
		Subsprite_3473:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -3 @ x, y
		Subsprite_3474:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -35 @ x, y
		Subsprite_3475:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -3 @ x, y
		Subsprite_3476:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -27 @ x, y
		Subsprite_3477:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 5 @ x, y
		Subsprite_3478:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -8, -35 @ x, y
		Subsprite_3479:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -35 @ x, y
		Subsprite_3480:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -3 @ x, y
		Subsprite_3481:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -35 @ x, y
		Subsprite_3482:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -3 @ x, y
		Subsprite_3483:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -35 @ x, y
		Subsprite_3484:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -3 @ x, y
		Subsprite_3485:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -35 @ x, y
		Subsprite_3486:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -3 @ x, y
		Subsprite_3487:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -35 @ x, y
		Subsprite_3488:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -3 @ x, y
		Subsprite_3489:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -35 @ x, y
		Subsprite_3490:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -3 @ x, y
		Subsprite_3491:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -35 @ x, y
		Subsprite_3492:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -3 @ x, y
		Subsprite_3493:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -35 @ x, y
		Subsprite_3494:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -3 @ x, y
		Subsprite_3495:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -35 @ x, y
		Subsprite_3496:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -3 @ x, y
		Subsprite_3497:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -35 @ x, y
		Subsprite_3498:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -3 @ x, y
		Subsprite_3499:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -35 @ x, y
		Subsprite_3500:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -3 @ x, y
		Subsprite_3501:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -35 @ x, y
		Subsprite_3502:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -3 @ x, y
		Subsprite_3503:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -35 @ x, y
		Subsprite_3504:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -3 @ x, y
		Subsprite_3505:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -35 @ x, y
		Subsprite_3506:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -3 @ x, y
		Subsprite_3507:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -35 @ x, y
		Subsprite_3508:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -3 @ x, y
		Subsprite_3509:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -35 @ x, y
		Subsprite_3510:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -3 @ x, y
		Subsprite_3511:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -35 @ x, y
		Subsprite_3512:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -3 @ x, y
		Subsprite_3513:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -35 @ x, y
		Subsprite_3514:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -3 @ x, y
		Subsprite_3515:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -35 @ x, y
		Subsprite_3516:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -3 @ x, y
		Subsprite_3517:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -35 @ x, y
		Subsprite_3518:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -3 @ x, y
		Subsprite_3519:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -35 @ x, y
		Subsprite_3520:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -3 @ x, y
		Subsprite_3521:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -35 @ x, y
		Subsprite_3522:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -3 @ x, y
		Subsprite_3523:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -35 @ x, y
		Subsprite_3524:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, -3 @ x, y
		Subsprite_3525:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 5 @ x, y
		Subsprite_3526:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -35 @ x, y
		Subsprite_3527:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, -3 @ x, y
		Subsprite_3528:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 5 @ x, y
		Subsprite_3529:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -35 @ x, y
		Subsprite_3530:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -3 @ x, y
		Subsprite_3531:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -35 @ x, y
		Subsprite_3532:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, -3 @ x, y
		Subsprite_3533:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 5 @ x, y
		Subsprite_3534:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -35 @ x, y
		Subsprite_3535:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, -3 @ x, y
		Subsprite_3536:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 5 @ x, y
		Subsprite_3537:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -35 @ x, y
		Subsprite_3538:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, -3 @ x, y
		Subsprite_3539:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 5 @ x, y
		Subsprite_3540:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -35 @ x, y
		Subsprite_3541:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, -3 @ x, y
		Subsprite_3542:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 5 @ x, y
		Subsprite_3543:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -35 @ x, y
		Subsprite_3544:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -3 @ x, y
		Subsprite_3545:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -35 @ x, y
		Subsprite_3546:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -3 @ x, y
		Subsprite_3547:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -27 @ x, y
		Subsprite_3548:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -16, -35 @ x, y
		Subsprite_3549:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 5 @ x, y
		Subsprite_3550:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -35 @ x, y
		Subsprite_3551:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -3 @ x, y
		Subsprite_3552:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -35 @ x, y
		Subsprite_3553:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -3 @ x, y
		Subsprite_3554:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -35 @ x, y
		Subsprite_3555:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -3 @ x, y
		Subsprite_3556:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -35 @ x, y
		Subsprite_3557:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -3 @ x, y
		Subsprite_3558:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -27 @ x, y
		Subsprite_3559:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -16, -35 @ x, y
		Subsprite_3560:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 5 @ x, y
		Subsprite_3561:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -27 @ x, y
		Subsprite_3562:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -16, -35 @ x, y
		Subsprite_3563:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 5 @ x, y
		Subsprite_3564:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -27 @ x, y
		Subsprite_3565:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -16, -35 @ x, y
		Subsprite_3566:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 5 @ x, y
		Subsprite_3567:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -27 @ x, y
		Subsprite_3568:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -16, -35 @ x, y
		Subsprite_3569:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 5 @ x, y
		Subsprite_3570:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -27 @ x, y
		Subsprite_3571:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -16, -35 @ x, y
		Subsprite_3572:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 5 @ x, y
		Subsprite_3573:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -27 @ x, y
		Subsprite_3574:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -16, -35 @ x, y
		Subsprite_3575:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 5 @ x, y
		Subsprite_3576:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -27 @ x, y
		Subsprite_3577:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -16, -35 @ x, y
		Subsprite_3578:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 5 @ x, y
		Subsprite_3579:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -27 @ x, y
		Subsprite_3580:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -16, -35 @ x, y
		Subsprite_3581:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 5 @ x, y
		Subsprite_3582:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -46 @ x, y
		Subsprite_3583:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -46 @ x, y
		Subsprite_3584:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -14 @ x, y
		Subsprite_3585:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_3586:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -4, -4 @ x, y
		Subsprite_3587:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -12, -36 @ x, y
		Subsprite_3588:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -12, -4 @ x, y
		Subsprite_3589:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -12, -28 @ x, y
		Subsprite_3590:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -12, 4 @ x, y
		Subsprite_3591:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -20, -28 @ x, y
		Subsprite_3592:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -20, 4 @ x, y
		Subsprite_3593:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 12, -28 @ x, y
		Subsprite_3594:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -20, -28 @ x, y
		Subsprite_3595:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -20, 4 @ x, y
		Subsprite_3596:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 12, -28 @ x, y
		Subsprite_3597:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -20, -28 @ x, y
		Subsprite_3598:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -20, 4 @ x, y
		Subsprite_3599:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 12, -28 @ x, y
		Subsprite_3600:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -20, -28 @ x, y
		Subsprite_3601:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -20, 4 @ x, y
		Subsprite_3602:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 12, -28 @ x, y
		Subsprite_3603:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -12, -28 @ x, y
		Subsprite_3604:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 4, -28 @ x, y
		Subsprite_3605:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -4, 4 @ x, y
		Subsprite_3606:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -12, -28 @ x, y
		Subsprite_3607:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 4, -28 @ x, y
		Subsprite_3608:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -4, 4 @ x, y
		Subsprite_3609:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -12, -28 @ x, y
		Subsprite_3610:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 4, -28 @ x, y
		Subsprite_3611:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -4, 4 @ x, y
		Subsprite_3612:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -20, -28 @ x, y
		Subsprite_3613:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -20, 4 @ x, y
		Subsprite_3614:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 12, -28 @ x, y
		Subsprite_3615:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -12, -28 @ x, y
		Subsprite_3616:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 4, -28 @ x, y
		Subsprite_3617:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -12, 4 @ x, y
		Subsprite_3618:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -12, -28 @ x, y
		Subsprite_3619:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 4, -28 @ x, y
		Subsprite_3620:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -12, 4 @ x, y
		Subsprite_3621:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -12, -28 @ x, y
		Subsprite_3622:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 4, -28 @ x, y
		Subsprite_3623:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -12, 4 @ x, y
		Subsprite_3624:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -20, -28 @ x, y
		Subsprite_3625:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -20, 4 @ x, y
		Subsprite_3626:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 12, -28 @ x, y
		Subsprite_3627:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -20, -28 @ x, y
		Subsprite_3628:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -20, 4 @ x, y
		Subsprite_3629:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 12, -28 @ x, y
		Subsprite_3630:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -20, -28 @ x, y
		Subsprite_3631:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -20, 4 @ x, y
		Subsprite_3632:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 12, -28 @ x, y
		Subsprite_3633:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -20, -28 @ x, y
		Subsprite_3634:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -20, 4 @ x, y
		Subsprite_3635:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 12, -28 @ x, y
		Subsprite_3636:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -20, -28 @ x, y
		Subsprite_3637:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -20, 4 @ x, y
		Subsprite_3638:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 12, -28 @ x, y
		Subsprite_3639:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -20, -36 @ x, y
		Subsprite_3640:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -20, -4 @ x, y
		Subsprite_3641:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 12, -4 @ x, y
		Subsprite_3642:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -20, -28 @ x, y
		Subsprite_3643:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -12, -12 @ x, y
		Subsprite_3644:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -4, 4 @ x, y
		Subsprite_3645:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -20, -20 @ x, y
		Subsprite_3646:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 12, -20 @ x, y
		Subsprite_3647:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -20, -20 @ x, y
		Subsprite_3648:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 12, -20 @ x, y
		Subsprite_3649:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -20, -36 @ x, y
		Subsprite_3650:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -20, -4 @ x, y
		Subsprite_3651:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 12, -36 @ x, y
		Subsprite_3652:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -12, -28 @ x, y
		Subsprite_3653:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -20, -12 @ x, y
		Subsprite_3654:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -12, 4 @ x, y
		Subsprite_3655:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -20, -20 @ x, y
		Subsprite_3656:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 12, -20 @ x, y
		Subsprite_3657:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -20, -20 @ x, y
		Subsprite_3658:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 12, -20 @ x, y
		Subsprite_3659:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -12, -28 @ x, y
		Subsprite_3660:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -12, 4 @ x, y
		Subsprite_3661:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -12, -28 @ x, y
		Subsprite_3662:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -12, 4 @ x, y
		Subsprite_3663:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -12, -20 @ x, y
		Subsprite_3664:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -12, -4 @ x, y
		Subsprite_3665:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 4, -20 @ x, y
		Subsprite_3666:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 4, -4 @ x, y
		Subsprite_3667:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -12, -20 @ x, y
		Subsprite_3668:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -12, -4 @ x, y
		Subsprite_3669:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 4, -20 @ x, y
		Subsprite_3670:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 4, -4 @ x, y
		Subsprite_3671:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -12, -20 @ x, y
		Subsprite_3672:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -12, -4 @ x, y
		Subsprite_3673:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 4, -20 @ x, y
		Subsprite_3674:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 4, -4 @ x, y
		Subsprite_3675:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -12, -20 @ x, y
		Subsprite_3676:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -12, -4 @ x, y
		Subsprite_3677:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 4, -20 @ x, y
		Subsprite_3678:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 4, -4 @ x, y
		Subsprite_3679:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -12, -20 @ x, y
		Subsprite_3680:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -12, -4 @ x, y
		Subsprite_3681:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 4, -20 @ x, y
		Subsprite_3682:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 4, -4 @ x, y
		Subsprite_3683:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -12, -20 @ x, y
		Subsprite_3684:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -12, -4 @ x, y
		Subsprite_3685:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 4, -20 @ x, y
		Subsprite_3686:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 4, -4 @ x, y
		Subsprite_3687:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -12, -20 @ x, y
		Subsprite_3688:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -12, -4 @ x, y
		Subsprite_3689:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 4, -20 @ x, y
		Subsprite_3690:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 4, -4 @ x, y
		Subsprite_3691:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -12, -20 @ x, y
		Subsprite_3692:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -12, -4 @ x, y
		Subsprite_3693:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 4, -20 @ x, y
		Subsprite_3694:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 4, -4 @ x, y
		Subsprite_3695:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -12, -20 @ x, y
		Subsprite_3696:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -12, -4 @ x, y
		Subsprite_3697:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 4, -20 @ x, y
		Subsprite_3698:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 4, -4 @ x, y
		Subsprite_3699:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -12, -20 @ x, y
		Subsprite_3700:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -12, -4 @ x, y
		Subsprite_3701:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 4, -20 @ x, y
		Subsprite_3702:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 4, -4 @ x, y
		Subsprite_3703:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -12, -20 @ x, y
		Subsprite_3704:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -12, -4 @ x, y
		Subsprite_3705:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 4, -20 @ x, y
		Subsprite_3706:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 4, -4 @ x, y
		Subsprite_3707:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -12, -20 @ x, y
		Subsprite_3708:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -12, -4 @ x, y
		Subsprite_3709:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 4, -20 @ x, y
		Subsprite_3710:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 4, -4 @ x, y
		Subsprite_3711:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -20, -28 @ x, y
		Subsprite_3712:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -20, 4 @ x, y
		Subsprite_3713:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 12, -28 @ x, y
		Subsprite_3714:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -20, -28 @ x, y
		Subsprite_3715:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -20, 4 @ x, y
		Subsprite_3716:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 12, -28 @ x, y
		Subsprite_3717:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -20, -36 @ x, y
		Subsprite_3718:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -20, -4 @ x, y
		Subsprite_3719:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -20, -36 @ x, y
		Subsprite_3720:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -20, -4 @ x, y
		Subsprite_3721:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -20, -28 @ x, y
		Subsprite_3722:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -20, 4 @ x, y
		Subsprite_3723:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 12, -28 @ x, y
		Subsprite_3724:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -12, -28 @ x, y
		Subsprite_3725:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -20, -12 @ x, y
		Subsprite_3726:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 12, -12 @ x, y
		Subsprite_3727:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -20, -36 @ x, y
		Subsprite_3728:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -20, -4 @ x, y
		Subsprite_3729:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 12, -36 @ x, y
		Subsprite_3730:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -32 @ x, y
		Subsprite_3731:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -32 @ x, y
		Subsprite_3732:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -32 @ x, y
		Subsprite_3733:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -32 @ x, y
		Subsprite_3734:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -32 @ x, y
		Subsprite_3735:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -32 @ x, y
		Subsprite_3736:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -32 @ x, y
		Subsprite_3737:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -32 @ x, y
		Subsprite_3738:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -32 @ x, y
		Subsprite_3739:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -32 @ x, y
		Subsprite_3740:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -32 @ x, y
		Subsprite_3741:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -32 @ x, y
		Subsprite_3742:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -24 @ x, y
		Subsprite_3743:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -24 @ x, y
		Subsprite_3744:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -24 @ x, y
		Subsprite_3745:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -20 @ x, y
		Subsprite_3746:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 12 @ x, y
		Subsprite_3747:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -20 @ x, y
		Subsprite_3748:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 12 @ x, y
		Subsprite_3749:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -20 @ x, y
		Subsprite_3750:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -20 @ x, y
		Subsprite_3751:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 12 @ x, y
		Subsprite_3752:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -20 @ x, y
		Subsprite_3753:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 12 @ x, y
		Subsprite_3754:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -20 @ x, y
		Subsprite_3755:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 12 @ x, y
		Subsprite_3756:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 8, -20 @ x, y
		Subsprite_3757:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -20 @ x, y
		Subsprite_3758:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -24, 12 @ x, y
		Subsprite_3759:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 8, -20 @ x, y
		Subsprite_3760:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, 12 @ x, y
		Subsprite_3761:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -20 @ x, y
		Subsprite_3762:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 12 @ x, y
		Subsprite_3763:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -20 @ x, y
		Subsprite_3764:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 12 @ x, y
		Subsprite_3765:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -20 @ x, y
		Subsprite_3766:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -20 @ x, y
		Subsprite_3767:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 12 @ x, y
		Subsprite_3768:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -20 @ x, y
		Subsprite_3769:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 12 @ x, y
		Subsprite_3770:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -20 @ x, y
		Subsprite_3771:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 12 @ x, y
		Subsprite_3772:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 8, -20 @ x, y
		Subsprite_3773:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -20 @ x, y
		Subsprite_3774:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -24, 12 @ x, y
		Subsprite_3775:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 8, -20 @ x, y
		Subsprite_3776:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, 12 @ x, y
		Subsprite_3777:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -20 @ x, y
		Subsprite_3778:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 12 @ x, y
		Subsprite_3779:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -20 @ x, y
		Subsprite_3780:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 12 @ x, y
		Subsprite_3781:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -20 @ x, y
		Subsprite_3782:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -20 @ x, y
		Subsprite_3783:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 12 @ x, y
		Subsprite_3784:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -20 @ x, y
		Subsprite_3785:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 12 @ x, y
		Subsprite_3786:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -28 @ x, y
		Subsprite_3787:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -24, 4 @ x, y
		Subsprite_3788:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 8, -28 @ x, y
		Subsprite_3789:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, 4 @ x, y
		Subsprite_3790:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -32, -20 @ x, y
		Subsprite_3791:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 0, -20 @ x, y
		Subsprite_3792:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -32, 12 @ x, y
		Subsprite_3793:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte 0, 12 @ x, y
		Subsprite_3794:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -20 @ x, y
		Subsprite_3795:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 12 @ x, y
		Subsprite_3796:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -20 @ x, y
		Subsprite_3797:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 12 @ x, y
		Subsprite_3798:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -20 @ x, y
		Subsprite_3799:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 12 @ x, y
		Subsprite_3800:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -20 @ x, y
		Subsprite_3801:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 12 @ x, y
		Subsprite_3802:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -12 @ x, y
		Subsprite_3803:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -20 @ x, y
		Subsprite_3804:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -20 @ x, y
		Subsprite_3805:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -24, 12 @ x, y
		Subsprite_3806:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 8, -20 @ x, y
		Subsprite_3807:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -32, -20 @ x, y
		Subsprite_3808:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -32, 12 @ x, y
		Subsprite_3809:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 0, -20 @ x, y
		Subsprite_3810:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 0, 12 @ x, y
		Subsprite_3811:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -20 @ x, y
		Subsprite_3812:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 12 @ x, y
		Subsprite_3813:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -20 @ x, y
		Subsprite_3814:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 12 @ x, y
		Subsprite_3815:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -20 @ x, y
		Subsprite_3816:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 12 @ x, y
		Subsprite_3817:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -20 @ x, y
		Subsprite_3818:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 12 @ x, y
		Subsprite_3819:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -12 @ x, y
		Subsprite_3820:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -20 @ x, y
		Subsprite_3821:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -20 @ x, y
		Subsprite_3822:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -24, 12 @ x, y
		Subsprite_3823:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 8, -20 @ x, y
		Subsprite_3824:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -32, -20 @ x, y
		Subsprite_3825:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -32, 12 @ x, y
		Subsprite_3826:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 0, -20 @ x, y
		Subsprite_3827:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 0, 12 @ x, y
		Subsprite_3828:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -20 @ x, y
		Subsprite_3829:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 12 @ x, y
		Subsprite_3830:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -28 @ x, y
		Subsprite_3831:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -20 @ x, y
		Subsprite_3832:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -28 @ x, y
		Subsprite_3833:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 12 @ x, y
		Subsprite_3834:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -20 @ x, y
		Subsprite_3835:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -20 @ x, y
		Subsprite_3836:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -24, 12 @ x, y
		Subsprite_3837:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte 8, 12 @ x, y
		Subsprite_3838:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -12 @ x, y
		Subsprite_3839:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -16, -20 @ x, y
		Subsprite_3840:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, -20 @ x, y
		Subsprite_3841:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -20 @ x, y
		Subsprite_3842:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 12 @ x, y
		Subsprite_3843:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -28 @ x, y
		Subsprite_3844:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -28 @ x, y
		Subsprite_3845:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -24, 4 @ x, y
		Subsprite_3846:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 8, -28 @ x, y
		Subsprite_3847:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, 4 @ x, y
		Subsprite_3848:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -32, -28 @ x, y
		Subsprite_3849:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -32, 4 @ x, y
		Subsprite_3850:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 0, -28 @ x, y
		Subsprite_3851:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 0, 4 @ x, y
		Subsprite_3852:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -20 @ x, y
		Subsprite_3853:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 12 @ x, y
		Subsprite_3854:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -20 @ x, y
		Subsprite_3855:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 12 @ x, y
		Subsprite_3856:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -20 @ x, y
		Subsprite_3857:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 12 @ x, y
		Subsprite_3858:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -20 @ x, y
		Subsprite_3859:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 12 @ x, y
		Subsprite_3860:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -12 @ x, y
		Subsprite_3861:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -20 @ x, y
		Subsprite_3862:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -20 @ x, y
		Subsprite_3863:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -24, 12 @ x, y
		Subsprite_3864:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 8, -20 @ x, y
		Subsprite_3865:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -32, -20 @ x, y
		Subsprite_3866:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -32, 12 @ x, y
		Subsprite_3867:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 0, -20 @ x, y
		Subsprite_3868:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 0, 12 @ x, y
		Subsprite_3869:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -20 @ x, y
		Subsprite_3870:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 12 @ x, y
		Subsprite_3871:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -20 @ x, y
		Subsprite_3872:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 12 @ x, y
		Subsprite_3873:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 16, -20 @ x, y
		Subsprite_3874:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -24, -12 @ x, y
		Subsprite_3875:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -24, 4 @ x, y
		Subsprite_3876:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 8, -12 @ x, y
		Subsprite_3877:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte 8, 4 @ x, y
		Subsprite_3878:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -20 @ x, y
		Subsprite_3879:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 12 @ x, y
		Subsprite_3880:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 16, -20 @ x, y
		Subsprite_3881:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 16, 12 @ x, y
		Subsprite_3882:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -4 @ x, y
		Subsprite_3883:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -20 @ x, y
		Subsprite_3884:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, 12 @ x, y
		Subsprite_3885:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -12 @ x, y
		Subsprite_3886:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -28 @ x, y
		Subsprite_3887:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -28 @ x, y
		Subsprite_3888:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -24, 4 @ x, y
		Subsprite_3889:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -28 @ x, y
		Subsprite_3890:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 8, 4 @ x, y
		Subsprite_3891:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -28 @ x, y
		Subsprite_3892:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, 4 @ x, y
		Subsprite_3893:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -20 @ x, y
		Subsprite_3894:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -28 @ x, y
		Subsprite_3895:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 12 @ x, y
		Subsprite_3896:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -20 @ x, y
		Subsprite_3897:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -20 @ x, y
		Subsprite_3898:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -24, 12 @ x, y
		Subsprite_3899:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte 8, 12 @ x, y
		Subsprite_3900:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -12 @ x, y
		Subsprite_3901:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -16, -20 @ x, y
		Subsprite_3902:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, -20 @ x, y
		Subsprite_3903:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -20 @ x, y
		Subsprite_3904:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 12 @ x, y
		Subsprite_3905:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -28 @ x, y
		Subsprite_3906:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -28 @ x, y
		Subsprite_3907:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, 4 @ x, y
		Subsprite_3908:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -20 @ x, y
		Subsprite_3909:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -28 @ x, y
		Subsprite_3910:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -16, 12 @ x, y
		Subsprite_3911:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -20 @ x, y
		Subsprite_3912:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -20 @ x, y
		Subsprite_3913:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -24, 12 @ x, y
		Subsprite_3914:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte 8, 12 @ x, y
		Subsprite_3915:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -20 @ x, y
		Subsprite_3916:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, 12 @ x, y
		Subsprite_3917:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -20 @ x, y
		Subsprite_3918:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 12 @ x, y
		Subsprite_3919:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -28 @ x, y
		Subsprite_3920:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_3921:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_3922:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_3923:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_3924:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_3925:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_3926:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -56 @ x, y
		Subsprite_3927:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -56 @ x, y
		Subsprite_3928:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -24 @ x, y
		Subsprite_3929:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -56 @ x, y
		Subsprite_3930:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -56 @ x, y
		Subsprite_3931:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -24 @ x, y
		Subsprite_3932:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_3933:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_3934:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_3935:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_3936:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_3937:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_3938:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_3939:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_3940:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -12, -16 @ x, y
		Subsprite_3941:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -12, 0 @ x, y
		Subsprite_3942:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 4, -16 @ x, y
		Subsprite_3943:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 4, 0 @ x, y
		Subsprite_3944:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -12, -24 @ x, y
		Subsprite_3945:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 4, -24 @ x, y
		Subsprite_3946:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -12, -24 @ x, y
		Subsprite_3947:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 4, -24 @ x, y
		Subsprite_3948:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -12, -24 @ x, y
		Subsprite_3949:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 4, -24 @ x, y
		Subsprite_3950:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -4, -24 @ x, y
		Subsprite_3951:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte -12, -16 @ x, y
		Subsprite_3952:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -12, 0 @ x, y
		Subsprite_3953:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 4, -24 @ x, y
		Subsprite_3954:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -12, -8 @ x, y
		Subsprite_3955:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -12, -24 @ x, y
		Subsprite_3956:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -21 @ x, y
		Subsprite_3957:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -37 @ x, y
		Subsprite_3958:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, -37 @ x, y
		Subsprite_3959:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -37 @ x, y
		Subsprite_3960:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -5 @ x, y
		Subsprite_3961:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -37 @ x, y
		Subsprite_3962:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -5 @ x, y
		Subsprite_3963:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -37 @ x, y
		Subsprite_3964:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -5 @ x, y
		Subsprite_3965:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -37 @ x, y
		Subsprite_3966:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -5 @ x, y
		Subsprite_3967:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -29 @ x, y
		Subsprite_3968:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 3 @ x, y
		Subsprite_3969:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -29 @ x, y
		Subsprite_3970:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -29 @ x, y
		Subsprite_3971:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, -37 @ x, y
		Subsprite_3972:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -29 @ x, y
		Subsprite_3973:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 3 @ x, y
		Subsprite_3974:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 16, -29 @ x, y
		Subsprite_3975:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -37 @ x, y
		Subsprite_3976:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -5 @ x, y
		Subsprite_3977:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -37 @ x, y
		Subsprite_3978:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -24, -5 @ x, y
		Subsprite_3979:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -37 @ x, y
		Subsprite_3980:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 8, -5 @ x, y
		Subsprite_3981:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -37 @ x, y
		Subsprite_3982:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -24, -5 @ x, y
		Subsprite_3983:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -37 @ x, y
		Subsprite_3984:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 8, -5 @ x, y
		Subsprite_3985:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -37 @ x, y
		Subsprite_3986:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -24, -5 @ x, y
		Subsprite_3987:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -37 @ x, y
		Subsprite_3988:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 8, -5 @ x, y
		Subsprite_3989:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -37 @ x, y
		Subsprite_3990:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -24, -5 @ x, y
		Subsprite_3991:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 8, -37 @ x, y
		Subsprite_3992:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, -5 @ x, y
		Subsprite_3993:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_3994:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 0, -16 @ x, y
		Subsprite_3995:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 0 @ x, y
		Subsprite_3996:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_3997:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_3998:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, -16 @ x, y
		Subsprite_3999:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 8, -8 @ x, y
		Subsprite_4000:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4001:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4002:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_4003:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte 0, 8 @ x, y
		Subsprite_4004:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 8, 0 @ x, y
		Subsprite_4005:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_4006:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte 0, 8 @ x, y
		Subsprite_4007:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 8, 0 @ x, y
		Subsprite_4008:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4009:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4010:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 0 @ x, y
		Subsprite_4011:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4012:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 0 @ x, y
		Subsprite_4013:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_4014:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 0 @ x, y
		Subsprite_4015:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 8, -8 @ x, y
		Subsprite_4016:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4017:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 0 @ x, y
		Subsprite_4018:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4019:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 0 @ x, y
		Subsprite_4020:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4021:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 0 @ x, y
		Subsprite_4022:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4023:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -16, 0 @ x, y
		Subsprite_4024:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 0, -16 @ x, y
		Subsprite_4025:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, 0 @ x, y
		Subsprite_4026:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4027:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -16, 0 @ x, y
		Subsprite_4028:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 0, -16 @ x, y
		Subsprite_4029:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, 0 @ x, y
		Subsprite_4030:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4031:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_4032:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_4033:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4034:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4035:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4036:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4037:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4038:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4039:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4040:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4041:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4042:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4043:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4044:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4045:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4046:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4047:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 0, -16 @ x, y
		Subsprite_4048:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4049:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 0, -16 @ x, y
		Subsprite_4050:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4051:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4052:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4053:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4054:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4055:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4056:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_4057:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_4058:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_4059:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_4060:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_4061:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, 8 @ x, y
		Subsprite_4062:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_4063:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_4064:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_4065:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 8 @ x, y
		Subsprite_4066:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_4067:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_4068:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 8 @ x, y
		Subsprite_4069:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_4070:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_4071:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_4072:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_4073:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4074:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4075:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4076:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4077:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4078:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4079:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4080:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4081:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_4082:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4083:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_4084:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_4085:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte 0, 8 @ x, y
		Subsprite_4086:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4087:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 0, -16 @ x, y
		Subsprite_4088:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, 0 @ x, y
		Subsprite_4089:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 0, -16 @ x, y
		Subsprite_4090:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4091:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_4092:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_4093:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 8, 0 @ x, y
		Subsprite_4094:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4095:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_4096:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_4097:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 8, 0 @ x, y
		Subsprite_4098:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4099:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4100:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4101:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 0, -16 @ x, y
		Subsprite_4102:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4103:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 0, -16 @ x, y
		Subsprite_4104:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4105:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 0, -16 @ x, y
		Subsprite_4106:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -40 @ x, y
		Subsprite_4107:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -32, -48 @ x, y
		Subsprite_4108:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 0, -48 @ x, y
		Subsprite_4109:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 0, -16 @ x, y
		Subsprite_4110:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -64 @ x, y
		Subsprite_4111:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -40 @ x, y
		Subsprite_4112:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -40 @ x, y
		Subsprite_4113:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -24, -8 @ x, y
		Subsprite_4114:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -16, -48 @ x, y
		Subsprite_4115:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 0, -48 @ x, y
		Subsprite_4116:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4117:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 0, -16 @ x, y
		Subsprite_4118:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -40 @ x, y
		Subsprite_4119:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -40 @ x, y
		Subsprite_4120:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -24, -8 @ x, y
		Subsprite_4121:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -16, -48 @ x, y
		Subsprite_4122:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 0, -48 @ x, y
		Subsprite_4123:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4124:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 0, -16 @ x, y
		Subsprite_4125:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -40 @ x, y
		Subsprite_4126:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -32, -48 @ x, y
		Subsprite_4127:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 0, -48 @ x, y
		Subsprite_4128:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 0, -16 @ x, y
		Subsprite_4129:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -64 @ x, y
		Subsprite_4130:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -40 @ x, y
		Subsprite_4131:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -32, -48 @ x, y
		Subsprite_4132:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 0, -48 @ x, y
		Subsprite_4133:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 0, -16 @ x, y
		Subsprite_4134:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -64 @ x, y
		Subsprite_4135:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4136:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4137:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4138:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4139:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4140:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4141:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4142:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4143:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_4144:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_4145:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 8 @ x, y
		Subsprite_4146:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4147:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_4148:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_4149:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_4150:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4151:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4152:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4153:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_4154:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_4155:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_4156:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4157:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4158:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4159:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4160:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4161:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4162:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4163:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4164:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4165:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4166:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4167:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4168:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_4169:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_4170:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 8 @ x, y
		Subsprite_4171:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_4172:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_4173:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 8 @ x, y
		Subsprite_4174:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_4175:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_4176:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 8 @ x, y
		Subsprite_4177:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_4178:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_4179:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 8, 0 @ x, y
		Subsprite_4180:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_4181:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_4182:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 8 @ x, y
		Subsprite_4183:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_4184:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, 0 @ x, y
		Subsprite_4185:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_4186:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, -16 @ x, y
		Subsprite_4187:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, 0 @ x, y
		Subsprite_4188:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_4189:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_4190:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, 0 @ x, y
		Subsprite_4191:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_4192:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, 0 @ x, y
		Subsprite_4193:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_4194:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, 0 @ x, y
		Subsprite_4195:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_4196:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 8, 8 @ x, y
		Subsprite_4197:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -12, -12 @ x, y
		Subsprite_4198:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 4, -12 @ x, y
		Subsprite_4199:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -20, -28 @ x, y
		Subsprite_4200:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -20, 4 @ x, y
		Subsprite_4201:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -20, -36 @ x, y
		Subsprite_4202:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -20, -4 @ x, y
		Subsprite_4203:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 12, -36 @ x, y
		Subsprite_4204:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -36, -36 @ x, y
		Subsprite_4205:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -36, -4 @ x, y
		Subsprite_4206:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -4, -36 @ x, y
		Subsprite_4207:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -4, -4 @ x, y
		Subsprite_4208:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -36, -44 @ x, y
		Subsprite_4209:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -4, -44 @ x, y
		Subsprite_4210:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -4, -12 @ x, y
		Subsprite_4211:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -20, -44 @ x, y
		Subsprite_4212:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 12, -44 @ x, y
		Subsprite_4213:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 12, -12 @ x, y
		Subsprite_4214:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -12, -12 @ x, y
		Subsprite_4215:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 4, -12 @ x, y
		Subsprite_4216:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -4, 4 @ x, y
		Subsprite_4217:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -20, -28 @ x, y
		Subsprite_4218:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -12, 4 @ x, y
		Subsprite_4219:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 4, 4 @ x, y
		Subsprite_4220:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -12, -36 @ x, y
		Subsprite_4221:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -12, -4 @ x, y
		Subsprite_4222:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 20, -36 @ x, y
		Subsprite_4223:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -20, -44 @ x, y
		Subsprite_4224:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 12, -44 @ x, y
		Subsprite_4225:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 12, -12 @ x, y
		Subsprite_4226:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -28, -44 @ x, y
		Subsprite_4227:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 4, -44 @ x, y
		Subsprite_4228:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 4, -12 @ x, y
		Subsprite_4229:
			.byte OAM_SIZE_64x64, 0 @ shape, unk_01(always 0)
			.byte -36, -44 @ x, y
		Subsprite_4230:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -28, -4 @ x, y
		Subsprite_4231:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -28, 12 @ x, y
		Subsprite_4232:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 4, 12 @ x, y
		Subsprite_4233:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -24 @ x, y
		Subsprite_4234:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 16, -24 @ x, y
		Subsprite_4235:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_4236:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte 16, 8 @ x, y
		Subsprite_4237:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -24 @ x, y
		Subsprite_4238:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 16, -24 @ x, y
		Subsprite_4239:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_4240:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte 16, 8 @ x, y
		Subsprite_4241:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -24 @ x, y
		Subsprite_4242:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_4243:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 16, -24 @ x, y
		Subsprite_4244:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 16, 8 @ x, y
		Subsprite_4245:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -24 @ x, y
		Subsprite_4246:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 16, -24 @ x, y
		Subsprite_4247:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_4248:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte 16, 8 @ x, y
		Subsprite_4249:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -24 @ x, y
		Subsprite_4250:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 16, -24 @ x, y
		Subsprite_4251:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_4252:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte 16, 8 @ x, y
		Subsprite_4253:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -24 @ x, y
		Subsprite_4254:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_4255:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 16, -24 @ x, y
		Subsprite_4256:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 16, 8 @ x, y
		Subsprite_4257:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_4258:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_4259:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_4260:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_4261:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_4262:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_4263:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_4264:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_4265:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_4266:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_4267:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_4268:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_4269:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_4270:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_4271:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_4272:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_4273:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_4274:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_4275:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_4276:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_4277:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_4278:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -4, -4 @ x, y
		Subsprite_4279:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -4, -4 @ x, y
		Subsprite_4280:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -4, -4 @ x, y
		Subsprite_4281:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -4, -4 @ x, y
		Subsprite_4282:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -4, -4 @ x, y
		Subsprite_4283:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -4, -4 @ x, y
		Subsprite_4284:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -4, -4 @ x, y
		Subsprite_4285:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -4, -4 @ x, y
		Subsprite_4286:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -4, -4 @ x, y
		Subsprite_4287:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -4, -4 @ x, y
		Subsprite_4288:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -4, -4 @ x, y
		Subsprite_4289:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -4, -4 @ x, y
		Subsprite_4290:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -4, -4 @ x, y
		Subsprite_4291:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -4, -4 @ x, y
		Subsprite_4292:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -46 @ x, y
		Subsprite_4293:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -46 @ x, y
		Subsprite_4294:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -14 @ x, y
		Subsprite_4295:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_4296:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_4297:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 8 @ x, y
		Subsprite_4298:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -4, -4 @ x, y
		Subsprite_4299:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_4300:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_4301:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_4302:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -24, -8 @ x, y
		Subsprite_4303:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_4304:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_4305:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_4306:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -32 @ x, y
		Subsprite_4307:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -24, 0 @ x, y
		Subsprite_4308:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 8, -32 @ x, y
		Subsprite_4309:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, 0 @ x, y
		Subsprite_4310:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -32 @ x, y
		Subsprite_4311:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, 0 @ x, y
		Subsprite_4312:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 16, -32 @ x, y
		Subsprite_4313:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 16, 0 @ x, y
		Subsprite_4314:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_4315:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_4316:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_4317:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_4318:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_4319:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_4320:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_4321:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_4322:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_4323:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_4324:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_4325:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_4326:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_4327:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_4328:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_4329:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_4330:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_4331:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_4332:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_4333:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_4334:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_4335:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_4336:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_4337:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_4338:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_4339:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_4340:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_4341:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_4342:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_4343:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_4344:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_4345:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_4346:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_4347:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -46 @ x, y
		Subsprite_4348:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -46 @ x, y
		Subsprite_4349:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -14 @ x, y
		Subsprite_4350:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -46 @ x, y
		Subsprite_4351:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -46 @ x, y
		Subsprite_4352:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -14 @ x, y
		Subsprite_4353:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -38 @ x, y
		Subsprite_4354:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -24, -6 @ x, y
		Subsprite_4355:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -38 @ x, y
		Subsprite_4356:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 8, -6 @ x, y
		Subsprite_4357:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -22 @ x, y
		Subsprite_4358:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -30 @ x, y
		Subsprite_4359:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -6 @ x, y
		Subsprite_4360:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_4361:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_4362:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_4363:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_4364:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_4365:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_4366:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_4367:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_4368:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_4369:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_4370:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_4371:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_4372:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_4373:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_4374:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_4375:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_4376:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_4377:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_4378:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_4379:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_4380:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_4381:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_4382:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_4383:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_4384:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_4385:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_4386:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_4387:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_4388:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_4389:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_4390:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_4391:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_4392:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_4393:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_4394:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_4395:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_4396:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, 8 @ x, y
		Subsprite_4397:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_4398:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_4399:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_4400:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -24 @ x, y
		Subsprite_4401:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -24, 8 @ x, y
		Subsprite_4402:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -24 @ x, y
		Subsprite_4403:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 8, 8 @ x, y
		Subsprite_4404:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_4405:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_4406:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_4407:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, -16 @ x, y
		Subsprite_4408:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_4409:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_4410:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 8, 0 @ x, y
		Subsprite_4411:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_4412:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, -16 @ x, y
		Subsprite_4413:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_4414:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, 8 @ x, y
		Subsprite_4415:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_4416:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 8, 0 @ x, y
		Subsprite_4417:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -8, 8 @ x, y
		Subsprite_4418:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_4419:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 8, -8 @ x, y
		Subsprite_4420:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_4421:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_4422:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_4423:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 0 @ x, y
		Subsprite_4424:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, 0 @ x, y
		Subsprite_4425:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, -8 @ x, y
		Subsprite_4426:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, 0 @ x, y
		Subsprite_4427:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, -8 @ x, y
		Subsprite_4428:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, 0 @ x, y
		Subsprite_4429:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, -8 @ x, y
		Subsprite_4430:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, 0 @ x, y
		Subsprite_4431:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, -8 @ x, y
		Subsprite_4432:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, 0 @ x, y
		Subsprite_4433:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, -8 @ x, y
		Subsprite_4434:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, 0 @ x, y
		Subsprite_4435:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, -8 @ x, y
		Subsprite_4436:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -47, -55 @ x, y
		Subsprite_4437:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -15, -55 @ x, y
		Subsprite_4438:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -16 @ x, y
		Subsprite_4439:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_4440:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_4441:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_4442:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_4443:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_4444:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_4445:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_4446:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_4447:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_4448:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_4449:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_4450:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_4451:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_4452:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_4453:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_4454:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_4455:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_4456:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_4457:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_4458:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_4459:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_4460:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -8 @ x, y
		Subsprite_4461:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, 0 @ x, y
		Subsprite_4462:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -24, 32 @ x, y
		Subsprite_4463:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, 0 @ x, y
		Subsprite_4464:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 8, 32 @ x, y
		Subsprite_4465:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, 0 @ x, y
		Subsprite_4466:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -24, 32 @ x, y
		Subsprite_4467:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, 0 @ x, y
		Subsprite_4468:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 8, 32 @ x, y
		Subsprite_4469:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4470:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -16 @ x, y
		Subsprite_4471:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_4472:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -16 @ x, y
		Subsprite_4473:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_4474:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte 0, 0 @ x, y
		Subsprite_4475:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte 0, 32 @ x, y
		Subsprite_4476:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 32, 0 @ x, y
		Subsprite_4477:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 32, 32 @ x, y
		Subsprite_4478:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte 0, 0 @ x, y
		Subsprite_4479:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte 0, 32 @ x, y
		Subsprite_4480:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 32, 0 @ x, y
		Subsprite_4481:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 32, 32 @ x, y
		Subsprite_4482:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte 0, 0 @ x, y
		Subsprite_4483:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte 0, 32 @ x, y
		Subsprite_4484:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 32, 0 @ x, y
		Subsprite_4485:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 32, 32 @ x, y
		Subsprite_4486:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte 0, 0 @ x, y
		Subsprite_4487:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte 0, 32 @ x, y
		Subsprite_4488:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 32, 0 @ x, y
		Subsprite_4489:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 32, 32 @ x, y
		Subsprite_4490:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_4491:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 0 @ x, y
		Subsprite_4492:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 24 @ x, y
		Subsprite_4493:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_4494:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 0 @ x, y
		Subsprite_4495:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 24 @ x, y
		Subsprite_4496:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_4497:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 0 @ x, y
		Subsprite_4498:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 24 @ x, y
		Subsprite_4499:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_4500:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 0 @ x, y
		Subsprite_4501:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 24 @ x, y
		Subsprite_4502:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_4503:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 0 @ x, y
		Subsprite_4504:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 24 @ x, y
		Subsprite_4505:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_4506:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 0 @ x, y
		Subsprite_4507:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 24 @ x, y
		Subsprite_4508:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_4509:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 0 @ x, y
		Subsprite_4510:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 24 @ x, y
		Subsprite_4511:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_4512:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 0 @ x, y
		Subsprite_4513:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 24 @ x, y
		Subsprite_4514:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_4515:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 0 @ x, y
		Subsprite_4516:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 24 @ x, y
		Subsprite_4517:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_4518:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 0 @ x, y
		Subsprite_4519:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 24 @ x, y
		Subsprite_4520:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_4521:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 0 @ x, y
		Subsprite_4522:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 24 @ x, y
		Subsprite_4523:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_4524:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 0 @ x, y
		Subsprite_4525:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 24 @ x, y
		Subsprite_4526:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_4527:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 0 @ x, y
		Subsprite_4528:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 24 @ x, y
		Subsprite_4529:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -19, -28 @ x, y
		Subsprite_4530:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -19, -28 @ x, y
		Subsprite_4531:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -19, -28 @ x, y
		Subsprite_4532:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -19, -28 @ x, y
		Subsprite_4533:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -32, -40 @ x, y
		Subsprite_4534:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 0, -40 @ x, y
		Subsprite_4535:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 0, -8 @ x, y
		Subsprite_4536:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4537:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte -4, -4 @ x, y
		Subsprite_4538:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -19 @ x, y
		Subsprite_4539:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -35 @ x, y
		Subsprite_4540:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -3 @ x, y
		Subsprite_4541:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -19 @ x, y
		Subsprite_4542:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte -8, -35 @ x, y
		Subsprite_4543:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -3 @ x, y
		Subsprite_4544:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -35 @ x, y
		Subsprite_4545:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -3 @ x, y
		Subsprite_4546:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, -19 @ x, y
		Subsprite_4547:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -16, -35 @ x, y
		Subsprite_4548:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 0, -35 @ x, y
		Subsprite_4549:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -16, -3 @ x, y
		Subsprite_4550:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, -3 @ x, y
		Subsprite_4551:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte -8, -35 @ x, y
		Subsprite_4552:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, -3 @ x, y
		Subsprite_4553:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte -16, -19 @ x, y
		Subsprite_4554:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 16, 0 @ x, y
		Subsprite_4555:
			.byte OAM_SIZE_16x16, 0 @ shape, unk_01(always 0)
			.byte 16, 0 @ x, y
		Subsprite_4556:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 24, 0 @ x, y
		Subsprite_4557:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 24, 8 @ x, y
		Subsprite_4558:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 40, 8 @ x, y
		Subsprite_4559:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte 24, 8 @ x, y
		Subsprite_4560:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte 24, 40 @ x, y
		Subsprite_4561:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 56, 8 @ x, y
		Subsprite_4562:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 56, 40 @ x, y
		Subsprite_4563:
			.byte OAM_SIZE_64x32, 0 @ shape, unk_01(always 0)
			.byte 24, 8 @ x, y
		Subsprite_4564:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte 24, 40 @ x, y
		Subsprite_4565:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte 56, 40 @ x, y
		Subsprite_4566:
			.byte OAM_SIZE_64x64, 0 @ shape, unk_01(always 0)
			.byte 24, 8 @ x, y
		Subsprite_4567:
			.byte OAM_SIZE_64x64, 0 @ shape, unk_01(always 0)
			.byte 24, 0 @ x, y
		Subsprite_4568:
			.byte OAM_SIZE_64x64, 0 @ shape, unk_01(always 0)
			.byte 24, 0 @ x, y
		Subsprite_4569:
			.byte OAM_SIZE_64x64, 0 @ shape, unk_01(always 0)
			.byte 32, -8 @ x, y
		Subsprite_4570:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte 64, 56 @ x, y
		Subsprite_4571:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte 16, -24 @ x, y
		Subsprite_4572:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 24, -40 @ x, y
		Subsprite_4573:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 24, -40 @ x, y
		Subsprite_4574:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 16, -24 @ x, y
		Subsprite_4575:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte 16, -48 @ x, y
		Subsprite_4576:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte 24, -64 @ x, y
		Subsprite_4577:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte 24, -32 @ x, y
		Subsprite_4578:
			.byte OAM_SIZE_8x32, 0 @ shape, unk_01(always 0)
			.byte 56, -64 @ x, y
		Subsprite_4579:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte 24, -72 @ x, y
		Subsprite_4580:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte 24, -40 @ x, y
		Subsprite_4581:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 56, -72 @ x, y
		Subsprite_4582:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte 24, -88 @ x, y
		Subsprite_4583:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 56, -88 @ x, y
		Subsprite_4584:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 56, -56 @ x, y
		Subsprite_4585:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte 24, -88 @ x, y
		Subsprite_4586:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 56, -88 @ x, y
		Subsprite_4587:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 56, -56 @ x, y
		Subsprite_4588:
			.byte OAM_SIZE_64x64, 0 @ shape, unk_01(always 0)
			.byte 24, -96 @ x, y
		Subsprite_4589:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte 24, -32 @ x, y
		Subsprite_4590:
			.byte OAM_SIZE_64x64, 0 @ shape, unk_01(always 0)
			.byte 24, -96 @ x, y
		Subsprite_4591:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte 24, -32 @ x, y
		Subsprite_4592:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -8 @ x, y
		Subsprite_4593:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 8 @ x, y
		Subsprite_4594:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4595:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4596:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4597:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4598:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -16, 0 @ x, y
		Subsprite_4599:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -8, 8 @ x, y
		Subsprite_4600:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -16, -16 @ x, y
		Subsprite_4601:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_4602:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_4603:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_4604:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_4605:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_4606:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_4607:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_4608:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_4609:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_4610:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_4611:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_4612:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_4613:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_4614:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -24, -16 @ x, y
		Subsprite_4615:
			.byte OAM_SIZE_8x16, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_4616:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_4617:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_4618:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_4619:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_4620:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_4621:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_4622:
			.byte OAM_SIZE_32x64, 0 @ shape, unk_01(always 0)
			.byte -24, -48 @ x, y
		Subsprite_4623:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -48 @ x, y
		Subsprite_4624:
			.byte OAM_SIZE_16x32, 0 @ shape, unk_01(always 0)
			.byte 8, -16 @ x, y
		Subsprite_4625:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -17, -19 @ x, y
		Subsprite_4626:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -17, -27 @ x, y
		Subsprite_4627:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -17, 5 @ x, y
		Subsprite_4628:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -17, -35 @ x, y
		Subsprite_4629:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -17, -3 @ x, y
		Subsprite_4630:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -17, -27 @ x, y
		Subsprite_4631:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -17, 5 @ x, y
		Subsprite_4632:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -17, -19 @ x, y
		Subsprite_4633:
			.byte OAM_SIZE_32x16, 0 @ shape, unk_01(always 0)
			.byte -17, -11 @ x, y
		Subsprite_4634:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -9, -19 @ x, y
		Subsprite_4635:
			.byte OAM_SIZE_16x8, 0 @ shape, unk_01(always 0)
			.byte -9, 5 @ x, y
		Subsprite_4636:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -17, -27 @ x, y
		Subsprite_4637:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -17, 5 @ x, y
		Subsprite_4638:
			.byte OAM_SIZE_32x32, 0 @ shape, unk_01(always 0)
			.byte -17, -27 @ x, y
		Subsprite_4639:
			.byte OAM_SIZE_32x8, 0 @ shape, unk_01(always 0)
			.byte -17, 5 @ x, y
		Subsprite_4640:
			.byte OAM_SIZE_8x8, 0 @ shape, unk_01(always 0)
			.byte 0, 0 @ x, y
