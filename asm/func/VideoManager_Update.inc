	push {lr}
	bl StageBGRegs
	bl WaitForVBlank
	bl FUN_0822eef4
	ldr r3, _0822A208 @ =0x03002CA4
	ldr r2, [r3]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _0822A1C4
	ldr r1, _0822A20C @ =0x040000D4
	ldr r0, _0822A210 @ =0x03003630
	str r0, [r1]
	movs r0, #0xe0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, _0822A214 @ =0x84000100
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r0, #2
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r3]
_0822A1C4:
	bl CommitPalette
	bl FUN_0822b308
	bl FUN_0822e73c
	bl CopyBGTileDataAndTilemapToVram
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r1, [r2]
	ldr r0, _0822A218 @ =0x0000E0FF
	ands r0, r1
	strh r0, [r2]
	ldr r0, _0822A21C @ =0x03002CA8
	ldr r0, [r0]
	cmp r0, #0
	bne _0822A1FA
	ldr r0, _0822A220 @ =0x03003E78
	ldrh r0, [r0]
	movs r3, #0x80
	lsls r3, r3, #5
	adds r1, r3, #0
	orrs r0, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_0822A1FA:
	bl FUN_0822ed38
	ldr r1, _0822A224 @ =0x03003500
	movs r0, #0
	str r0, [r1]
	pop {r1}
	bx r1
	.align 2, 0
_0822A208: .4byte 0x03002CA4
_0822A20C: .4byte 0x040000D4
_0822A210: .4byte 0x03003630
_0822A214: .4byte 0x84000100
_0822A218: .4byte 0x0000E0FF
_0822A21C: .4byte 0x03002CA8
_0822A220: .4byte 0x03003E78
_0822A224: .4byte 0x03003500
