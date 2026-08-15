	push {r4, r5, r6, lr}
	ldr r5, _0822B9AC @ =0x03003E78
	ldrh r1, [r5]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0822B914
	ldr r4, _0822B9B0 @ =0x040000D4
	movs r0, #0
	bl GetTilemapBuffer
	str r0, [r4]
	ldr r0, _0822B9B4 @ =0x0600F800
	str r0, [r4, #4]
	ldr r0, _0822B9B8 @ =0x84000200
	str r0, [r4, #8]
	ldr r0, [r4, #8]
_0822B914:
	ldrh r1, [r5]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0822B934
	ldr r4, _0822B9B0 @ =0x040000D4
	movs r0, #1
	bl GetTilemapBuffer
	str r0, [r4]
	ldr r0, _0822B9BC @ =0x0600F000
	str r0, [r4, #4]
	ldr r0, _0822B9B8 @ =0x84000200
	str r0, [r4, #8]
	ldr r0, [r4, #8]
_0822B934:
	ldrh r1, [r5]
	movs r0, #0x80
	lsls r0, r0, #3
	ands r0, r1
	cmp r0, #0
	beq _0822B954
	ldr r4, _0822B9B0 @ =0x040000D4
	movs r0, #2
	bl GetTilemapBuffer
	str r0, [r4]
	ldr r0, _0822B9C0 @ =0x0600E800
	str r0, [r4, #4]
	ldr r0, _0822B9B8 @ =0x84000200
	str r0, [r4, #8]
	ldr r0, [r4, #8]
_0822B954:
	ldrh r1, [r5]
	movs r0, #0x80
	lsls r0, r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0822B974
	ldr r4, _0822B9B0 @ =0x040000D4
	movs r0, #3
	bl GetTilemapBuffer
	str r0, [r4]
	ldr r0, _0822B9C4 @ =0x0600E000
	str r0, [r4, #4]
	ldr r0, _0822B9B8 @ =0x84000200
	str r0, [r4, #8]
	ldr r0, [r4, #8]
_0822B974:
	movs r5, #0
	ldr r4, _0822B9C8 @ =0x03003E60
	ldr r6, _0822B9CC @ =0x03003EA8
_0822B97A:
	ldr r3, [r4]
	cmp r3, #0
	beq _0822B99C
	lsls r2, r5, #1
	ldrh r1, [r6]
	movs r0, #0xc0
	lsls r0, r0, #0x13
	adds r1, r1, r0
	ldr r0, _0822B9D0 @ =0x03003E80
	adds r2, r2, r0
	ldrh r2, [r2]
	lsls r2, r2, #5
	adds r0, r3, #0
	bl FUN_08230af8
	movs r0, #0
	str r0, [r4]
_0822B99C:
	adds r4, #4
	adds r6, #2
	adds r5, #1
	cmp r5, #3
	ble _0822B97A
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0822B9AC: .4byte 0x03003E78
_0822B9B0: .4byte 0x040000D4
_0822B9B4: .4byte 0x0600F800
_0822B9B8: .4byte 0x84000200
_0822B9BC: .4byte 0x0600F000
_0822B9C0: .4byte 0x0600E800
_0822B9C4: .4byte 0x0600E000
_0822B9C8: .4byte 0x03003E60
_0822B9CC: .4byte 0x03003EA8
_0822B9D0: .4byte 0x03003E80
