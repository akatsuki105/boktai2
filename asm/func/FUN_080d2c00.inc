	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, _080D2C7C @ =0x000009C8
	adds r5, r4, r0
	ldr r1, _080D2C80 @ =0x00000A68
	adds r2, r4, r1
	ldr r0, [r4, #0x2c]
	ldr r1, [r4, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _080D2C84 @ =0x00000A6A
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #0xe6
	strh r0, [r1]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #5
	adds r2, #0x22
	adds r1, r4, r2
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_080d1b04
	adds r7, r0, #0
	adds r0, r4, #0
	bl FUN_080d1b38
	adds r6, r0, #0
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _080D2C90
	movs r2, #0xa8
	lsls r2, r2, #4
	adds r1, r4, r2
	movs r0, #0x1d
	strh r0, [r1]
	ldr r0, _080D2C88 @ =0x00000A88
	adds r1, r4, r0
	movs r0, #7
	strh r0, [r1]
	adds r2, #4
	adds r1, r4, r2
	movs r0, #4
	strh r0, [r1]
	ldr r0, _080D2C8C @ =0x00000A86
	adds r1, r4, r0
	movs r0, #6
	strh r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #0xb
	orrs r6, r0
	b _080D2CEE
	.align 2, 0
_080D2C7C: .4byte 0x000009C8
_080D2C80: .4byte 0x00000A68
_080D2C84: .4byte 0x00000A6A
_080D2C88: .4byte 0x00000A88
_080D2C8C: .4byte 0x00000A86
_080D2C90:
	movs r1, #0x80
	lsls r1, r1, #0xf
	movs r2, #0xde
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080D2CCC
	movs r0, #0xa8
	lsls r0, r0, #4
	adds r1, r4, r0
	movs r0, #0x1d
	strh r0, [r1]
	ldr r2, _080D2CC4 @ =0x00000A88
	adds r1, r4, r2
	movs r0, #7
	strh r0, [r1]
	ldr r0, _080D2CC8 @ =0x00000A84
	adds r1, r4, r0
	movs r0, #4
	strh r0, [r1]
	subs r2, #2
	adds r1, r4, r2
	movs r0, #6
	b _080D2CEC
	.align 2, 0
_080D2CC4: .4byte 0x00000A88
_080D2CC8: .4byte 0x00000A84
_080D2CCC:
	movs r0, #0xa8
	lsls r0, r0, #4
	adds r1, r4, r0
	movs r0, #0x13
	strh r0, [r1]
	ldr r2, _080D2D40 @ =0x00000A88
	adds r1, r4, r2
	movs r0, #0xb
	strh r0, [r1]
	ldr r0, _080D2D44 @ =0x00000A84
	adds r1, r4, r0
	movs r0, #6
	strh r0, [r1]
	subs r2, #2
	adds r1, r4, r2
	movs r0, #9
_080D2CEC:
	strh r0, [r1]
_080D2CEE:
	adds r1, r5, #0
	adds r1, #0xc5
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	blt _080D2D08
	adds r1, r0, #0
	movs r0, #1
	lsls r0, r1
	orrs r6, r0
	adds r0, r4, #0
	bl FUN_080cec18
_080D2D08:
	adds r0, r5, #0
	adds r0, #0x48
	adds r1, r5, #0
	adds r1, #0xb4
	ldrh r2, [r1]
	str r6, [sp]
	adds r1, #2
	ldrh r1, [r1]
	str r1, [sp, #4]
	adds r1, r7, #0
	movs r3, #4
	bl Hitbox_SetAttack
	adds r0, r5, #0
	adds r0, #0xc4
	ldrb r0, [r0]
	adds r2, r5, #0
	adds r2, #0x8a
	movs r1, #0
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0xc2
	strh r1, [r0]
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D2D40: .4byte 0x00000A88
_080D2D44: .4byte 0x00000A84
