	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r4, [r0]
	ldr r0, _0814DED0 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0814DED4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0814DED6
	.align 2, 0
_0814DED0: .4byte 0x0000046D
_0814DED4:
	movs r0, #0
_0814DED6:
	cmp r0, #0
	beq _0814DEF8
	adds r0, r5, #0
	movs r1, #0xf
	bl Enemy_PlayAnim
	movs r1, #0xe1
	lsls r1, r1, #3
	adds r2, r4, r1
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	ldr r1, [r0, #0xc]
	ldr r0, [r0, #8]
	str r0, [r2]
	str r1, [r2, #4]
_0814DEF8:
	ldr r1, _0814DF30 @ =0x0000046E
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0814DF2A
	ldr r4, _0814DF34 @ =FUN_0814df40
	movs r3, #0x22
	ldr r0, _0814DF38 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0814DF3C @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	adds r1, #0x25
	adds r0, r5, r1
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
_0814DF2A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0814DF30: .4byte 0x0000046E
_0814DF34: .4byte FUN_0814df40
_0814DF38: .4byte 0x0000046D
_0814DF3C: .4byte 0x0000046B
