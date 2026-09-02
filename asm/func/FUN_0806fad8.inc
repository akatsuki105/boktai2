	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, _0806FB58 @ =0x000009C8
	adds r6, r4, r0
	ldr r1, _0806FB5C @ =0x00000A68
	adds r2, r4, r1
	ldr r0, [r4, #0x2c]
	ldr r1, [r4, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _0806FB60 @ =0x00000A6A
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
	bl FUN_0806f900
	mov r8, r0
	adds r0, r4, #0
	bl FUN_0806f960
	adds r5, r0, #0
	ldr r1, _0806FB64 @ =0x00000A7E
	adds r0, r4, r1
	ldrh r7, [r0]
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #1
	bne _0806FB70
	movs r0, #0xa8
	lsls r0, r0, #4
	adds r1, r4, r0
	movs r0, #0xc
	strh r0, [r1]
	ldr r2, _0806FB68 @ =0x00000A84
	adds r1, r4, r2
	movs r0, #5
	strh r0, [r1]
	ldr r0, _0806FB6C @ =0x00000A88
	adds r1, r4, r0
	movs r0, #3
	strh r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #0xb
	orrs r5, r0
	b _0806FBBC
	.align 2, 0
_0806FB58: .4byte 0x000009C8
_0806FB5C: .4byte 0x00000A68
_0806FB60: .4byte 0x00000A6A
_0806FB64: .4byte 0x00000A7E
_0806FB68: .4byte 0x00000A84
_0806FB6C: .4byte 0x00000A88
_0806FB70:
	movs r1, #0x80
	lsls r1, r1, #0xf
	movs r2, #0xde
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0806FBA4
	movs r0, #0xa8
	lsls r0, r0, #4
	adds r1, r4, r0
	movs r0, #0xc
	strh r0, [r1]
	ldr r2, _0806FB9C @ =0x00000A84
	adds r1, r4, r2
	movs r0, #5
	strh r0, [r1]
	ldr r0, _0806FBA0 @ =0x00000A88
	adds r1, r4, r0
	movs r0, #3
	b _0806FBBA
	.align 2, 0
_0806FB9C: .4byte 0x00000A84
_0806FBA0: .4byte 0x00000A88
_0806FBA4:
	movs r1, #0xa8
	lsls r1, r1, #4
	adds r0, r4, r1
	movs r1, #8
	strh r1, [r0]
	ldr r2, _0806FC18 @ =0x00000A84
	adds r0, r4, r2
	strh r1, [r0]
	ldr r0, _0806FC1C @ =0x00000A88
	adds r1, r4, r0
	movs r0, #4
_0806FBBA:
	strh r0, [r1]
_0806FBBC:
	adds r1, r6, #0
	adds r1, #0xc5
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	blt _0806FBD6
	adds r1, r0, #0
	movs r0, #1
	lsls r0, r1
	orrs r5, r0
	adds r0, r4, #0
	bl Player_PayMagicCost
_0806FBD6:
	adds r0, r6, #0
	adds r0, #0x48
	adds r1, r6, #0
	adds r1, #0xb4
	ldrh r2, [r1]
	str r5, [sp]
	str r7, [sp, #4]
	mov r1, r8
	movs r3, #1
	bl FUN_082364f8
	adds r0, r6, #0
	adds r0, #0xc4
	ldrb r0, [r0]
	adds r1, r6, #0
	adds r1, #0x8a
	movs r2, #0
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0xc2
	movs r1, #0
	strh r2, [r0]
	movs r2, #0x89
	lsls r2, r2, #3
	adds r0, r4, r2
	strb r1, [r0]
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806FC18: .4byte 0x00000A84
_0806FC1C: .4byte 0x00000A88
