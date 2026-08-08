	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r2, #0
	cmp r1, #0
	blt _0807BDDA
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	strb r1, [r0]
_0807BDDA:
	movs r0, #0xba
	lsls r0, r0, #2
	adds r2, r4, r0
	ldrb r1, [r2]
	movs r0, #1
	orrs r0, r1
	strb r0, [r2]
	movs r1, #0x96
	lsls r1, r1, #3
	adds r0, r4, r1
	str r3, [r0]
	ldr r2, _0807BE24 @ =0x000004A6
	adds r0, r4, r2
	strb r5, [r0]
	subs r1, #0xc0
	adds r0, r4, r1
	strb r5, [r0]
	adds r0, r4, #0
	bl FUN_0807b7a4
	adds r0, r4, #0
	movs r1, #0x16
	movs r2, #0
	bl FUN_08060b84
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #3
	bne _0807BE2C
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _0807BE28 @ =FUN_080762fc
	b _0807BE48
	.align 2, 0
_0807BE24: .4byte 0x000004A6
_0807BE28: .4byte FUN_080762fc
_0807BE2C:
	cmp r0, #4
	bne _0807BE40
	movs r1, #0xe0
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r1, #1
	strb r1, [r0]
	ldr r2, _0807BE50 @ =0x00000381
	adds r0, r4, r2
	strb r1, [r0]
_0807BE40:
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _0807BE54 @ =FUN_080736b8
_0807BE48:
	str r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807BE50: .4byte 0x00000381
_0807BE54: .4byte FUN_080736b8
