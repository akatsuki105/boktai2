	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r5, r0, #0
	adds r6, r1, #0
	adds r4, r2, #0
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r0, [r5, #6]
	ands r0, r1
	cmp r0, #0
	beq _0805B8B6
	adds r0, r5, #0
	adds r0, #0x42
	ldrb r0, [r0]
	b _0805B8CE
_0805B8B6:
	movs r1, #0x24
	ldrsh r0, [r6, r1]
	movs r2, #0x24
	ldrsh r1, [r5, r2]
	subs r0, r0, r1
	movs r3, #0x28
	ldrsh r1, [r6, r3]
	movs r3, #0x28
	ldrsh r2, [r5, r3]
	subs r1, r1, r2
	bl ArcTan2_8
_0805B8CE:
	strb r0, [r4, #6]
	movs r0, #0
	mov r8, r0
	movs r0, #8
	ldrsb r0, [r4, r0]
	cmp r0, #0
	blt _0805B8E4
	movs r0, #0xfa
	strb r0, [r4, #9]
	mov r1, r8
	strb r1, [r4, #8]
_0805B8E4:
	adds r0, r5, #0
	adds r1, r6, #0
	bl Hitbox_ApplyDamage
	ldr r3, _0805B93C @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r3
	movs r2, #0x10
	orrs r0, r2
	ldr r1, _0805B940 @ =0x0000FFFF
	ands r0, r1
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r3
	orrs r0, r2
	str r0, [sp, #0xc]
	ldrh r1, [r6, #0x3e]
	adds r3, r4, #0
	adds r3, #0x14
	add r2, sp, #8
	str r2, [sp]
	movs r7, #1
	str r7, [sp, #4]
	adds r0, r6, #0
	movs r2, #0
	bl CreateDamageNumber
	ldrh r0, [r5, #0x3e]
	adds r0, #2
	strh r0, [r5, #0x3e]
	ldrh r0, [r6, #0x3e]
	bl FUN_08029864
	bl FUN_08084710
	adds r1, r0, #0
	cmp r1, #0
	beq _0805B944
	movs r0, #6
	strb r0, [r4, #1]
	strb r7, [r4]
	mov r3, r8
	strh r3, [r4, #4]
	b _0805B94C
	.align 2, 0
_0805B93C: .4byte 0xFFFF0000
_0805B940: .4byte 0x0000FFFF
_0805B944:
	movs r0, #8
	strb r0, [r4, #1]
	strb r7, [r4]
	strh r1, [r4, #4]
_0805B94C:
	movs r0, #0x84
	lsls r0, r0, #1
	bl PlaySound_082406e0
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
