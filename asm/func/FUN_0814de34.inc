	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r6, [r0]
	ldr r0, _0814DE54 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0814DE58
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0814DE5A
	.align 2, 0
_0814DE54: .4byte 0x0000046D
_0814DE58:
	movs r0, #0
_0814DE5A:
	cmp r0, #0
	beq _0814DE78
	adds r0, r4, #0
	movs r1, #0x11
	bl Enemy_PlayAnim
	adds r0, r4, #0
	adds r0, #8
	ldrb r1, [r4, #5]
	movs r2, #0
	bl Entity081f1770_Spawn
	ldr r0, _0814DEA4 @ =0x000003A5
	bl PlaySound_082406e0
_0814DE78:
	adds r0, r5, #0
	subs r0, #0xd
	cmp r0, #0xa
	bhi _0814DE8A
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r0, r6, r1
	bl Hitbox_Register
_0814DE8A:
	ldr r1, _0814DEA8 @ =0x0000046E
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0814DE9C
	ldr r0, _0814DEAC @ =0x0000046B
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_0814DE9C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0814DEA4: .4byte 0x000003A5
_0814DEA8: .4byte 0x0000046E
_0814DEAC: .4byte 0x0000046B
