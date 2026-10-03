	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x32
	ldrb r0, [r5]
	cmp r0, #0
	beq _0804C3F6
	movs r0, #0
	strb r0, [r5]
_0804C3F6:
	ldr r0, _0804C418 @ =FUN_0804bf90
	ldr r1, _0804C41C @ =FUN_0804c3a8
	bl rfu_LMAN_initializeManager
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0804C420
	movs r1, #0x1b
	movs r0, #0
	strb r0, [r4, #0x1c]
	strh r1, [r4, #0x38]
	str r0, [r4, #0x44]
	movs r0, #1
	strb r0, [r5]
	b _0804C42E
	.align 2, 0
_0804C418: .4byte FUN_0804bf90
_0804C41C: .4byte FUN_0804c3a8
_0804C420:
	movs r0, #2
	strb r1, [r4, #0x1c]
	strh r0, [r4, #0x38]
	str r1, [r4, #0x44]
	movs r0, #1
	strb r0, [r5]
	strb r0, [r4, #0x18]
_0804C42E:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
