	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
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
	beq _081389BE
	b _08138B1E
_081389BE:
	movs r2, #0
	str r2, [sp, #0x10]
	ldr r0, _08138A00 @ =0x00000B3A
	add r0, sb
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r2, r0
	blt _081389D0
	b _08138B1E
_081389D0:
	add r7, sp, #8
	movs r6, #0xd4
	lsls r6, r6, #3
	add r6, sb
	ldr r4, _08138A04 @ =0x00000674
	add r4, sb
	movs r0, #0xde
	lsls r0, r0, #3
	add r0, sb
	mov r8, r0
	movs r1, #0
	str r1, [sp, #0x14]
	ldr r2, _08138A08 @ =0x00000755
	add r2, sb
	mov sl, r2
_081389EE:
	movs r1, #1
	mov r3, sl
	ldrb r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _08138A0C
	movs r0, #1
	b _08138A0E
	.align 2, 0
_08138A00: .4byte 0x00000B3A
_08138A04: .4byte 0x00000674
_08138A08: .4byte 0x00000755
_08138A0C:
	movs r0, #0
_08138A0E:
	cmp r0, #0
	bne _08138AF8
	mov r0, r8
	adds r1, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	mov r0, r8
	bl Hitbox_Register
	ldr r0, _08138AAC @ =0x03002BE0
	ldr r0, [r0]
	adds r2, r0, #0
	adds r2, #0x2c
	ldrh r1, [r0, #0x2c]
	ldrh r0, [r4]
	subs r1, r1, r0
	strh r1, [r7]
	ldrh r0, [r2, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r7, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r7, #4]
	movs r1, #0
	ldrsh r0, [r7, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #4
	ldrsh r0, [r7, r2]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	ldr r0, _08138AB0 @ =0x0000FFFF
	cmp r1, r0
	bgt _08138AF8
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r6, #0
	bl Hitbox_Register
	movs r3, #0x80
	lsls r3, r3, #1
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	ands r0, r3
	cmp r0, #0
	beq _08138ABC
	ldrh r0, [r4, #0x32]
	bics r0, r3
	strh r0, [r4, #0x32]
	ldr r2, _08138AB4 @ =0x00000226
	adds r0, r5, r2
	ldrh r1, [r0]
	ldr r3, _08138AB8 @ =0x0000022E
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
	adds r0, r6, #0
	movs r3, #0
	bl Hitbox_SetAttack
	b _08138AF8
	.align 2, 0
_08138AAC: .4byte 0x03002BE0
_08138AB0: .4byte 0x0000FFFF
_08138AB4: .4byte 0x00000226
_08138AB8: .4byte 0x0000022E
_08138ABC:
	ldr r1, [sp, #0x14]
	add r1, sb
	movs r0, #0xd4
	lsls r0, r0, #3
	adds r1, r1, r0
	ldrh r2, [r1, #6]
	adds r0, r3, #0
	orrs r0, r2
	strh r0, [r1, #6]
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
	adds r0, r6, #0
	movs r3, #0
	bl Hitbox_SetAttack
_08138AF8:
	movs r0, #0x90
	lsls r0, r0, #1
	adds r6, r6, r0
	adds r4, r4, r0
	add r8, r0
	ldr r1, [sp, #0x14]
	adds r1, r1, r0
	str r1, [sp, #0x14]
	add sl, r0
	ldr r2, [sp, #0x10]
	adds r2, #1
	str r2, [sp, #0x10]
	ldr r0, _08138B30 @ =0x00000B3A
	add r0, sb
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r2, r0
	bge _08138B1E
	b _081389EE
_08138B1E:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08138B30: .4byte 0x00000B3A
