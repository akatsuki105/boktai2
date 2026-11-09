	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	ldr r0, _0817FAF0 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0817FAF4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0817FAF6
	.align 2, 0
_0817FAF0: .4byte 0x0000046D
_0817FAF4:
	movs r0, #0
_0817FAF6:
	cmp r0, #0
	beq _0817FB02
	adds r0, r5, #0
	movs r1, #0x11
	bl Enemy_PlayAnim
_0817FB02:
	ldrh r0, [r4, #0x14]
	cmp r0, #2
	bne _0817FB1E
	ldrh r0, [r4, #0xc]
	cmp r0, #0
	bne _0817FB1E
	movs r0, #0xf4
	lsls r0, r0, #2
	bl PlaySound_082406e0
	movs r0, #0xb4
	lsls r0, r0, #2
	bl PlaySound_082406e0
_0817FB1E:
	ldrh r0, [r4, #0x14]
	subs r0, #3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bhi _0817FBB2
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	str r0, [sp]
	str r1, [sp, #4]
	ldrb r0, [r5, #5]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	cmp r0, #1
	beq _0817FB5E
	cmp r0, #1
	bgt _0817FB4A
	cmp r0, #0
	beq _0817FB54
	b _0817FB9E
_0817FB4A:
	cmp r0, #2
	beq _0817FB68
	cmp r0, #3
	beq _0817FB88
	b _0817FB9E
_0817FB54:
	mov r0, sp
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	b _0817FB6E
_0817FB5E:
	mov r0, sp
	ldrh r1, [r0, #4]
	movs r0, #0x80
	lsls r0, r0, #1
	b _0817FB8E
_0817FB68:
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, _0817FB80 @ =0xFFFFFF00
_0817FB6E:
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0817FB84 @ =0xFFFF0000
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	b _0817FB9E
	.align 2, 0
_0817FB80: .4byte 0xFFFFFF00
_0817FB84: .4byte 0xFFFF0000
_0817FB88:
	mov r0, sp
	ldrh r1, [r0, #4]
	ldr r0, _0817FBCC @ =0xFFFFFF00
_0817FB8E:
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0817FBD0 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
_0817FB9E:
	ldr r1, _0817FBD4 @ =0x000007B4
	adds r4, r6, r1
	adds r0, r4, #0
	mov r1, sp
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	bl Hitbox_Register
_0817FBB2:
	ldr r1, _0817FBD8 @ =0x0000046E
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0817FBC4
	ldr r0, _0817FBDC @ =0x0000046B
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_0817FBC4:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0817FBCC: .4byte 0xFFFFFF00
_0817FBD0: .4byte 0xFFFF0000
_0817FBD4: .4byte 0x000007B4
_0817FBD8: .4byte 0x0000046E
_0817FBDC: .4byte 0x0000046B
