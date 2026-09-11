	push {r4, lr}
	adds r4, r0, #0
	ldr r3, [r2, #4]
	ldr r2, [r2]
	str r2, [r4, #0x1c]
	str r3, [r4, #0x20]
	str r1, [r4, #0x18]
	bl FUN_080a91dc
	adds r0, r4, #0
	bl FUN_080a939c
	movs r0, #0xfd
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r0, #0xb4
	strh r0, [r1]
	movs r1, #3
	bl Div
	movs r2, #0xfc
	lsls r2, r2, #1
	adds r1, r4, r2
	strh r0, [r1]
	movs r0, #0xfe
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r0, #0xe1
	lsls r0, r0, #2
	strh r0, [r1]
	adds r0, #0x13
	bl PlaySound_082406e0
	ldr r1, _080A9474 @ =FUN_080a9058
	adds r0, r4, #0
	bl FUN_080a9044
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080A9474: .4byte FUN_080a9058
