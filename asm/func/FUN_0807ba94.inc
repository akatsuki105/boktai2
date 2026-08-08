	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r3, #0
	ldr r0, _0807BAD8 @ =0x0000049C
	adds r3, r4, r0
	ldr r0, [r1]
	ldr r1, [r1, #4]
	str r0, [r3]
	str r1, [r3, #4]
	movs r1, #0x96
	lsls r1, r1, #3
	adds r0, r4, r1
	str r2, [r0]
	ldr r2, _0807BADC @ =0x000004A9
	adds r1, r4, r2
	strb r5, [r1]
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #2
	bne _0807BAE4
	lsls r0, r5, #0x18
	cmp r0, #0
	blt _0807BACE
	asrs r0, r0, #0x19
	lsls r0, r0, #1
	adds r0, #1
	strb r0, [r1]
_0807BACE:
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _0807BAE0 @ =FUN_08074e98
	b _0807BB20
	.align 2, 0
_0807BAD8: .4byte 0x0000049C
_0807BADC: .4byte 0x000004A9
_0807BAE0: .4byte FUN_08074e98
_0807BAE4:
	cmp r0, #3
	bne _0807BAF8
	movs r2, #0x93
	lsls r2, r2, #3
	adds r1, r4, r2
	ldr r0, _0807BAF4 @ =FUN_08075f00
	b _0807BB20
	.align 2, 0
_0807BAF4: .4byte FUN_08075f00
_0807BAF8:
	cmp r0, #4
	bne _0807BB18
	movs r1, #0xe0
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r1, #1
	strb r1, [r0]
	ldr r2, _0807BB14 @ =0x00000381
	adds r0, r4, r2
	strb r1, [r0]
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r4, r0
	b _0807BB1E
	.align 2, 0
_0807BB14: .4byte 0x00000381
_0807BB18:
	movs r2, #0x93
	lsls r2, r2, #3
	adds r1, r4, r2
_0807BB1E:
	ldr r0, _0807BB38 @ =FUN_08072a38
_0807BB20:
	str r0, [r1]
	adds r0, r4, #0
	bl FUN_0807b7a4
	adds r0, r4, #0
	movs r1, #1
	movs r2, #0
	bl FUN_08060b84
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807BB38: .4byte FUN_08072a38
