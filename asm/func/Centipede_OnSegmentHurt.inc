	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r4, r0, #0
	adds r5, r1, #0
	mov r8, r2
	mov sl, r8
	movs r0, #0x8e
	lsls r0, r0, #1
	add r0, r8
	ldr r7, [r0]
	adds r0, r7, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08138042
	mov r6, sp
	adds r3, r5, #0
	adds r3, #0x24
	adds r2, r4, #0
	adds r2, #0x24
	ldrh r0, [r4, #0x24]
	ldrh r1, [r5, #0x24]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r6, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r6, #4]
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #4
	ldrsh r0, [r6, r2]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	mov sb, r1
	ldr r1, _08137FD4 @ =0x00000B4C
	adds r0, r7, r1
	ldr r0, [r0]
	cmp sb, r0
	bhs _0813803C
	adds r0, r4, #0
	adds r1, r5, #0
	bl Hitbox_ApplyDamage
	adds r0, r4, #0
	adds r0, #0x44
	ldrh r1, [r0]
	adds r0, r5, #0
	adds r0, #0x44
	strh r1, [r0]
	adds r0, r4, #0
	adds r0, #0x40
	ldrh r1, [r0]
	adds r0, r5, #0
	adds r0, #0x40
	strh r1, [r0]
	ldrh r1, [r4, #6]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _08137FD8
	adds r0, r4, #0
	adds r0, #0x42
	ldrb r1, [r0]
	b _08137FFE
	.align 2, 0
_08137FD4: .4byte 0x00000B4C
_08137FD8:
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _08138014
	movs r2, #4
	ldrsh r0, [r6, r2]
	cmp r0, #0
	bne _08138014
	ldr r2, _08138008 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0813800C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08138010 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
_08137FFE:
	mov r2, r8
	adds r0, r2, r3
	strb r1, [r0]
	b _0813802C
	.align 2, 0
_08138008: .4byte 0x030046B8
_0813800C: .4byte 0x000003FF
_08138010: .4byte 0x0203B400
_08138014:
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r1, sp
	movs r2, #4
	ldrsh r1, [r1, r2]
	bl ArcTan2_8
	movs r1, #0x80
	lsls r1, r1, #1
	add r1, sl
	strb r0, [r1]
_0813802C:
	ldr r1, _08138054 @ =0x00000B4C
	adds r0, r7, r1
	mov r2, sb
	str r2, [r0]
	adds r1, #4
	adds r0, r7, r1
	mov r2, r8
	str r2, [r0]
_0813803C:
	adds r0, r7, #0
	bl FUN_08137e98
_08138042:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08138054: .4byte 0x00000B4C
