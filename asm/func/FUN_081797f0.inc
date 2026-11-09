	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov sb, r0
	adds r0, r5, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0817983E
	movs r1, #0x30
	ldr r0, _08179828 @ =0x00001008
	add r0, sb
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0817982C
	movs r0, #1
	b _0817982E
	.align 2, 0
_08179828: .4byte 0x00001008
_0817982C:
	movs r0, #0
_0817982E:
	cmp r0, #0
	bne _0817983E
	ldr r0, [r5, #0x44]
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08179868
_0817983E:
	movs r2, #0x94
	lsls r2, r2, #1
	adds r1, r5, r2
	ldrh r0, [r1, #6]
	movs r2, #4
	orrs r0, r2
	strh r0, [r1, #6]
	adds r1, r5, #0
	adds r1, #0xd8
	ldrh r0, [r1, #6]
	orrs r0, r2
	strh r0, [r1, #6]
	movs r0, #0x80
	lsls r0, r0, #4
	ldr r3, _08179864 @ =0x00000474
	adds r2, r5, r3
	ldrh r1, [r2]
	orrs r0, r1
	b _0817988E
	.align 2, 0
_08179864: .4byte 0x00000474
_08179868:
	movs r0, #0x94
	lsls r0, r0, #1
	adds r3, r5, r0
	movs r1, #5
	rsbs r1, r1, #0
	ldrh r2, [r3, #6]
	adds r0, r1, #0
	ands r0, r2
	strh r0, [r3, #6]
	adds r2, r5, #0
	adds r2, #0xd8
	ldrh r0, [r2, #6]
	ands r1, r0
	strh r1, [r2, #6]
	ldr r1, _081798D8 @ =0x00000474
	adds r2, r5, r1
	ldr r0, _081798DC @ =0xFFFFF7FF
	ldrh r1, [r2]
	ands r0, r1
_0817988E:
	strh r0, [r2]
	movs r2, #0
	str r2, [sp, #0x10]
	ldr r0, _081798E0 @ =0x00001012
	add r0, sb
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r2, r0
	blt _081798A2
	b _08179A80
_081798A2:
	add r0, sp, #8
	mov r8, r0
	movs r4, #0xd4
	lsls r4, r4, #3
	add r4, sb
	movs r1, #0
	str r1, [sp, #0x18]
	movs r7, #0xcb
	lsls r7, r7, #3
	add r7, sb
	ldr r2, _081798E4 @ =0x00000674
	add r2, sb
	str r2, [sp, #0x1c]
	movs r6, #0xde
	lsls r6, r6, #3
	add r6, sb
	ldr r3, _081798E8 @ =0x00000755
	add r3, sb
	mov sl, r3
_081798C8:
	movs r1, #1
	mov r2, sl
	ldrb r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081798EC
	movs r0, #1
	b _081798EE
	.align 2, 0
_081798D8: .4byte 0x00000474
_081798DC: .4byte 0xFFFFF7FF
_081798E0: .4byte 0x00001012
_081798E4: .4byte 0x00000674
_081798E8: .4byte 0x00000755
_081798EC:
	movs r0, #0
_081798EE:
	cmp r0, #0
	beq _081798F4
	b _08179A54
_081798F4:
	movs r1, #0x80
	mov r3, sl
	ldrb r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _08179904
	movs r0, #1
	b _08179906
_08179904:
	movs r0, #0
_08179906:
	cmp r0, #0
	beq _0817993E
	movs r0, #0xcb
	lsls r0, r0, #3
	add r0, sb
	ldr r1, [sp, #0x18]
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0817993E
	movs r2, #0x20
	ldr r1, _08179934 @ =0x00001008
	add r1, sb
	ldrh r0, [r1]
	ands r0, r2
	str r1, [sp, #0x14]
	cmp r0, #0
	beq _08179938
	movs r0, #1
	b _0817993A
	.align 2, 0
_08179934: .4byte 0x00001008
_08179938:
	movs r0, #0
_0817993A:
	cmp r0, #0
	beq _0817994E
_0817993E:
	ldrh r0, [r4, #6]
	movs r2, #4
	orrs r0, r2
	strh r0, [r4, #6]
	ldrh r0, [r6, #6]
	orrs r0, r2
	strh r0, [r6, #6]
	b _08179A54
_0817994E:
	adds r0, r6, #0
	ldr r1, [sp, #0x1c]
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r6, #0
	bl Hitbox_Register
	movs r0, #4
	mvns r3, r0
	ldrh r1, [r6, #6]
	adds r0, r3, #0
	ands r0, r1
	strh r0, [r6, #6]
	ldr r0, _081799D8 @ =0x03002BE0
	ldr r0, [r0]
	adds r2, r0, #0
	adds r2, #0x2c
	ldrh r0, [r0, #0x2c]
	ldrh r1, [r7, #0x1c]
	subs r0, r0, r1
	mov r1, r8
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r7, #0x1e]
	subs r0, r0, r1
	mov r1, r8
	strh r0, [r1, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r7, #0x20]
	subs r0, r0, r1
	mov r2, r8
	strh r0, [r2, #4]
	movs r1, #0
	ldrsh r0, [r2, r1]
	adds r2, r0, #0
	muls r2, r0, r2
	mov ip, r2
	mov r1, r8
	movs r2, #4
	ldrsh r0, [r1, r2]
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	mov r2, ip
	adds r1, r2, r0
	ldr r0, _081799DC @ =0x0000FFFF
	cmp r1, r0
	bgt _08179A54
	ldrh r0, [r4, #6]
	adds r1, r3, #0
	ands r1, r0
	strh r1, [r4, #6]
	adds r0, r4, #0
	ldr r1, [sp, #0x1c]
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	bl Hitbox_Register
	ldr r3, [sp, #0x14]
	ldrh r0, [r3]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _081799E0
	movs r0, #1
	b _081799E2
	.align 2, 0
_081799D8: .4byte 0x03002BE0
_081799DC: .4byte 0x0000FFFF
_081799E0:
	movs r0, #0
_081799E2:
	cmp r0, #0
	beq _08179A20
	ldrh r1, [r4, #6]
	ldr r0, _08179A14 @ =0xFFFFFEFF
	ands r0, r1
	strh r0, [r4, #6]
	ldr r2, _08179A18 @ =0x00000226
	adds r0, r5, r2
	ldrh r1, [r0]
	ldr r3, _08179A1C @ =0x0000022E
	adds r0, r5, r3
	ldrh r2, [r0]
	adds r3, #0x12
	adds r0, r5, r3
	ldr r0, [r0]
	str r0, [sp]
	subs r3, #0xa
	adds r0, r5, r3
	ldrh r0, [r0]
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r3, #0
	bl Hitbox_SetAttack
	b _08179A54
	.align 2, 0
_08179A14: .4byte 0xFFFFFEFF
_08179A18: .4byte 0x00000226
_08179A1C: .4byte 0x0000022E
_08179A20:
	ldrh r1, [r4, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	orrs r0, r1
	strh r0, [r4, #6]
	movs r1, #0x89
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r1, [r0]
	movs r2, #0x8b
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrh r2, [r0]
	movs r3, #0x8f
	lsls r3, r3, #2
	adds r0, r5, r3
	ldr r0, [r0]
	str r0, [sp]
	subs r3, #8
	adds r0, r5, r3
	ldrh r0, [r0]
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r3, #0
	bl Hitbox_SetAttack
_08179A54:
	movs r0, #0x92
	lsls r0, r0, #1
	adds r4, r4, r0
	ldr r1, [sp, #0x18]
	adds r1, r1, r0
	str r1, [sp, #0x18]
	adds r7, r7, r0
	ldr r2, [sp, #0x1c]
	adds r2, r2, r0
	str r2, [sp, #0x1c]
	adds r6, r6, r0
	add sl, r0
	ldr r3, [sp, #0x10]
	adds r3, #1
	str r3, [sp, #0x10]
	ldr r0, _08179A90 @ =0x00001012
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r3, r0
	bge _08179A80
	b _081798C8
_08179A80:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08179A90: .4byte 0x00001012
