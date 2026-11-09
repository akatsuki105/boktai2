	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	adds r5, r0, #0
	adds r6, r1, #0
	adds r7, r2, #0
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r4, [r0]
	adds r0, r4, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08190D44
	b _08190F0E
_08190D44:
	movs r2, #0x20
	ldr r0, _08190D58 @ =0x00000F2C
	adds r1, r4, r0
	ldrh r0, [r1]
	ands r0, r2
	mov r8, r1
	cmp r0, #0
	beq _08190D5C
	movs r0, #1
	b _08190D5E
	.align 2, 0
_08190D58: .4byte 0x00000F2C
_08190D5C:
	movs r0, #0
_08190D5E:
	cmp r0, #0
	beq _08190D64
	b _08190F0E
_08190D64:
	adds r0, r7, #0
	adds r0, #0xdc
	ldrh r0, [r0]
	cmp r0, #0
	beq _08190D70
	b _08190F0E
_08190D70:
	adds r0, r5, #0
	adds r1, r6, #0
	bl Hitbox_ApplyDamage
	adds r0, r5, #0
	adds r0, #0x44
	ldrh r1, [r0]
	adds r0, r6, #0
	adds r0, #0x44
	strh r1, [r0]
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r7, #0
	bl FUN_08190c94
	movs r2, #0xc4
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r0, [r5, #0x3e]
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r5, #0x3e]
	adds r0, r7, #0
	bl FUN_08192744
	movs r0, #0x40
	mov r2, r8
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r1, #4
	movs r2, #0x91
	lsls r2, r2, #1
	adds r0, r7, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08190DC0
	movs r0, #1
	b _08190DC2
_08190DC0:
	movs r0, #0
_08190DC2:
	cmp r0, #0
	beq _08190DD4
	ldr r0, _08190DD0 @ =0x000003E1
	bl PlaySound_082406e0
	b _08190DDC
	.align 2, 0
_08190DD0: .4byte 0x000003E1
_08190DD4:
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_082406e0
_08190DDC:
	adds r0, r6, #0
	adds r0, #0x43
	ldrb r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	bne _08190DEC
	b _08190F0E
_08190DEC:
	ldrh r1, [r5, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08190E00
	adds r0, r5, #0
	adds r0, #0x42
	ldrb r3, [r0]
	b _08190E6C
_08190E00:
	add r4, sp, #0x10
	adds r3, r6, #0
	adds r3, #0xc
	adds r2, r5, #0
	adds r2, #0xc
	ldrh r0, [r5, #0xc]
	ldrh r1, [r6, #0xc]
	subs r0, r0, r1
	adds r1, r4, #0
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r1, [r2, #4]
	ldrh r0, [r3, #4]
	subs r1, r1, r0
	strh r1, [r4, #4]
	adds r0, r4, #0
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bne _08190E58
	lsls r0, r1, #0x10
	cmp r0, #0
	bne _08190E58
	ldr r0, _08190E4C @ =0x030046B8
	ldr r1, [r0]
	adds r1, #1
	ldr r2, _08190E50 @ =0x000003FF
	ands r1, r2
	str r1, [r0]
	lsls r1, r1, #1
	ldr r0, _08190E54 @ =0x0203B400
	adds r1, r1, r0
	ldrb r3, [r1]
	b _08190E6C
	.align 2, 0
_08190E4C: .4byte 0x030046B8
_08190E50: .4byte 0x000003FF
_08190E54: .4byte 0x0203B400
_08190E58:
	add r0, sp, #0x10
	movs r1, #0
	ldrsh r0, [r0, r1]
	add r1, sp, #0x10
	movs r2, #4
	ldrsh r1, [r1, r2]
	bl ArcTan2_8
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
_08190E6C:
	ldr r0, [r7, #0x1c]
	ldr r1, [r7, #0x20]
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	ldr r0, _08190F20 @ =0x0203B400
	mov r8, r0
	ldr r1, _08190F24 @ =0x030046B8
	mov sl, r1
	ldr r4, [r1]
	adds r4, #1
	ldr r6, _08190F28 @ =0x000003FF
	ands r4, r6
	lsls r0, r4, #1
	add r0, r8
	ldr r2, [sp, #0x20]
	asrs r1, r2, #0x10
	ldrb r0, [r0]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r0, _08190F2C @ =0x0000FFFF
	mov sb, r0
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x20]
	adds r4, #1
	ands r4, r6
	lsls r0, r4, #1
	add r0, r8
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	subs r0, #0x10
	lsls r3, r3, #0x18
	asrs r3, r3, #0x18
	adds r3, r3, r0
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldr r5, _08190F30 @ =0xFFFF0000
	ldr r0, [sp, #0x18]
	ands r0, r5
	movs r1, #0x3c
	orrs r0, r1
	mov r1, sb
	ands r0, r1
	movs r1, #0xf0
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0x18]
	add r2, sp, #0x18
	ldr r0, [r2, #4]
	ands r0, r5
	movs r1, #0x28
	orrs r0, r1
	str r0, [r2, #4]
	adds r4, #1
	ands r4, r6
	lsls r0, r4, #1
	add r0, r8
	ldrh r5, [r0]
	movs r0, #7
	ands r5, r0
	adds r5, #4
	adds r4, #1
	ands r4, r6
	mov r1, sl
	str r4, [r1]
	lsls r4, r4, #1
	add r4, r8
	ldrh r1, [r4]
	ands r1, r0
	adds r1, #8
	add r0, sp, #0x20
	str r5, [sp]
	str r1, [sp, #4]
	movs r1, #2
	str r1, [sp, #8]
	movs r1, #1
	str r1, [sp, #0xc]
	movs r1, #2
	bl EmitSmoke
_08190F0E:
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08190F20: .4byte 0x0203B400
_08190F24: .4byte 0x030046B8
_08190F28: .4byte 0x000003FF
_08190F2C: .4byte 0x0000FFFF
_08190F30: .4byte 0xFFFF0000
