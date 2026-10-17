	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, _080D1C88 @ =0x000009C8
	adds r6, r4, r0
	ldr r1, _080D1C8C @ =0x00000A68
	adds r2, r4, r1
	ldr r0, [r4, #0x2c]
	ldr r1, [r4, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _080D1C90 @ =0x00000A6A
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
	mov r8, r0
	adds r0, r4, #0
	bl FUN_080d1b38
	adds r5, r0, #0
	ldr r1, _080D1C94 @ =0x00000A7E
	adds r0, r4, r1
	ldrh r7, [r0]
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #1
	bne _080D1CA0
	movs r0, #0xa8
	lsls r0, r0, #4
	adds r1, r4, r0
	movs r0, #0xc
	strh r0, [r1]
	ldr r2, _080D1C98 @ =0x00000A84
	adds r1, r4, r2
	movs r0, #5
	strh r0, [r1]
	ldr r0, _080D1C9C @ =0x00000A88
	adds r1, r4, r0
	movs r0, #3
	strh r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #0xb
	orrs r5, r0
	b _080D1CEC
	.align 2, 0
_080D1C88: .4byte 0x000009C8
_080D1C8C: .4byte 0x00000A68
_080D1C90: .4byte 0x00000A6A
_080D1C94: .4byte 0x00000A7E
_080D1C98: .4byte 0x00000A84
_080D1C9C: .4byte 0x00000A88
_080D1CA0:
	movs r1, #0x80
	lsls r1, r1, #0xf
	movs r2, #0xde
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080D1CD4
	movs r0, #0xa8
	lsls r0, r0, #4
	adds r1, r4, r0
	movs r0, #0xc
	strh r0, [r1]
	ldr r2, _080D1CCC @ =0x00000A84
	adds r1, r4, r2
	movs r0, #5
	strh r0, [r1]
	ldr r0, _080D1CD0 @ =0x00000A88
	adds r1, r4, r0
	movs r0, #3
	b _080D1CEA
	.align 2, 0
_080D1CCC: .4byte 0x00000A84
_080D1CD0: .4byte 0x00000A88
_080D1CD4:
	movs r1, #0xa8
	lsls r1, r1, #4
	adds r0, r4, r1
	movs r1, #8
	strh r1, [r0]
	ldr r2, _080D1D3C @ =0x00000A84
	adds r0, r4, r2
	strh r1, [r0]
	ldr r0, _080D1D40 @ =0x00000A88
	adds r1, r4, r0
	movs r0, #4
_080D1CEA:
	strh r0, [r1]
_080D1CEC:
	adds r1, r6, #0
	adds r1, #0xc5
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	blt _080D1D06
	adds r1, r0, #0
	movs r0, #1
	lsls r0, r1
	orrs r5, r0
	adds r0, r4, #0
	bl FUN_080cec18
_080D1D06:
	adds r0, r6, #0
	adds r0, #0x48
	adds r1, r6, #0
	adds r1, #0xb4
	ldrh r2, [r1]
	str r5, [sp]
	str r7, [sp, #4]
	mov r1, r8
	movs r3, #1
	bl Hitbox_SetAttack
	adds r0, r6, #0
	adds r0, #0xc4
	ldrb r0, [r0]
	adds r2, r6, #0
	adds r2, #0x8a
	movs r1, #0
	strb r0, [r2]
	adds r0, r6, #0
	adds r0, #0xc2
	strh r1, [r0]
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D1D3C: .4byte 0x00000A84
_080D1D40: .4byte 0x00000A88
