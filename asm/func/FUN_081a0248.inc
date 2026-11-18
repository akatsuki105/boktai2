	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	mov ip, r0
	movs r0, #0xe6
	lsls r0, r0, #1
	add r0, ip
	ldr r7, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r2, _081A0270 @ =0x00000E48
	adds r0, r7, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081A0274
	movs r0, #1
	b _081A0276
	.align 2, 0
_081A0270: .4byte 0x00000E48
_081A0274:
	movs r0, #0
_081A0276:
	cmp r0, #0
	beq _081A02A2
	movs r0, #0x94
	lsls r0, r0, #1
	add r0, ip
	movs r1, #0x8a
	lsls r1, r1, #2
	add r1, ip
	mov r8, r1
	ldrh r1, [r1]
	movs r6, #0x8c
	lsls r6, r6, #2
	add r6, ip
	ldrh r2, [r6]
	movs r5, #0x91
	lsls r5, r5, #2
	add r5, ip
	ldr r3, [r5]
	str r3, [sp]
	movs r4, #0x8e
	lsls r4, r4, #2
	b _081A03B0
_081A02A2:
	movs r2, #0x80
	lsls r2, r2, #4
	ldr r0, _081A02B8 @ =0x00000E48
	adds r1, r7, r0
	ldr r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _081A02BC
	movs r0, #1
	b _081A02BE
	.align 2, 0
_081A02B8: .4byte 0x00000E48
_081A02BC:
	movs r0, #0
_081A02BE:
	cmp r0, #0
	beq _081A0330
	movs r0, #0x8a
	lsls r0, r0, #2
	add r0, ip
	ldrh r6, [r0]
	lsls r6, r6, #1
	movs r0, #0x8c
	lsls r0, r0, #2
	add r0, ip
	ldrh r4, [r0]
	lsls r4, r4, #1
	movs r0, #0x94
	lsls r0, r0, #1
	add r0, ip
	movs r1, #0x91
	lsls r1, r1, #2
	add r1, ip
	mov r8, r1
	ldr r1, [r1]
	str r1, [sp]
	movs r5, #0x8e
	lsls r5, r5, #2
	add r5, ip
	ldrh r1, [r5]
	str r1, [sp, #4]
	adds r1, r6, #0
	adds r2, r4, #0
	movs r3, #0
	bl Hitbox_SetAttack
	ldr r2, _081A0328 @ =0x00000CFC
	adds r0, r7, r2
	mov r2, r8
	ldr r1, [r2]
	str r1, [sp]
	ldrh r1, [r5]
	str r1, [sp, #4]
	adds r1, r6, #0
	adds r2, r4, #0
	movs r3, #0
	bl Hitbox_SetAttack
	ldr r1, _081A032C @ =0x00000D4C
	adds r0, r7, r1
	mov r2, r8
	ldr r1, [r2]
	str r1, [sp]
	ldrh r1, [r5]
	str r1, [sp, #4]
	adds r1, r6, #0
	adds r2, r4, #0
	b _081A03E6
	.align 2, 0
_081A0328: .4byte 0x00000CFC
_081A032C: .4byte 0x00000D4C
_081A0330:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081A0340
	movs r0, #1
	b _081A0342
_081A0340:
	movs r0, #0
_081A0342:
	cmp r0, #0
	beq _081A0374
	movs r0, #0x94
	lsls r0, r0, #1
	add r0, ip
	ldr r1, _081A0368 @ =0x00000226
	add r1, ip
	mov r8, r1
	ldrh r1, [r1]
	ldr r6, _081A036C @ =0x0000022E
	add r6, ip
	ldrh r2, [r6]
	movs r5, #0x90
	lsls r5, r5, #2
	add r5, ip
	ldr r3, [r5]
	str r3, [sp]
	ldr r4, _081A0370 @ =0x00000236
	b _081A03B0
	.align 2, 0
_081A0368: .4byte 0x00000226
_081A036C: .4byte 0x0000022E
_081A0370: .4byte 0x00000236
_081A0374:
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081A0384
	movs r0, #1
	b _081A0386
_081A0384:
	movs r0, #0
_081A0386:
	cmp r0, #0
	beq _081A03F8
	movs r0, #0x94
	lsls r0, r0, #1
	add r0, ip
	movs r1, #0x89
	lsls r1, r1, #2
	add r1, ip
	mov r8, r1
	ldrh r1, [r1]
	movs r6, #0x8b
	lsls r6, r6, #2
	add r6, ip
	ldrh r2, [r6]
	movs r5, #0x8f
	lsls r5, r5, #2
	add r5, ip
	ldr r3, [r5]
	str r3, [sp]
	movs r4, #0x8d
	lsls r4, r4, #2
_081A03B0:
	add r4, ip
	ldrh r3, [r4]
	str r3, [sp, #4]
	movs r3, #0
	bl Hitbox_SetAttack
	ldr r2, _081A03F0 @ =0x00000CFC
	adds r0, r7, r2
	mov r2, r8
	ldrh r1, [r2]
	ldrh r2, [r6]
	ldr r3, [r5]
	str r3, [sp]
	ldrh r3, [r4]
	str r3, [sp, #4]
	movs r3, #0
	bl Hitbox_SetAttack
	ldr r1, _081A03F4 @ =0x00000D4C
	adds r0, r7, r1
	mov r2, r8
	ldrh r1, [r2]
	ldrh r2, [r6]
	ldr r3, [r5]
	str r3, [sp]
	ldrh r3, [r4]
	str r3, [sp, #4]
_081A03E6:
	movs r3, #0
	bl Hitbox_SetAttack
	b _081A045A
	.align 2, 0
_081A03F0: .4byte 0x00000CFC
_081A03F4: .4byte 0x00000D4C
_081A03F8:
	movs r0, #0x94
	lsls r0, r0, #1
	add r0, ip
	movs r1, #0x89
	lsls r1, r1, #2
	add r1, ip
	mov r8, r1
	ldrh r1, [r1]
	movs r6, #0x8b
	lsls r6, r6, #2
	add r6, ip
	ldrh r2, [r6]
	movs r5, #0x8f
	lsls r5, r5, #2
	add r5, ip
	ldr r3, [r5]
	str r3, [sp]
	movs r4, #0x8d
	lsls r4, r4, #2
	add r4, ip
	ldrh r3, [r4]
	str r3, [sp, #4]
	movs r3, #0
	bl Hitbox_SetAttack
	ldr r2, _081A0468 @ =0x00000CFC
	adds r0, r7, r2
	mov r2, r8
	ldrh r1, [r2]
	ldrh r2, [r6]
	ldr r3, [r5]
	str r3, [sp]
	ldrh r3, [r4]
	str r3, [sp, #4]
	movs r3, #0
	bl Hitbox_SetAttack
	ldr r1, _081A046C @ =0x00000D4C
	adds r0, r7, r1
	mov r2, r8
	ldrh r1, [r2]
	ldrh r2, [r6]
	ldr r3, [r5]
	str r3, [sp]
	ldrh r3, [r4]
	str r3, [sp, #4]
	movs r3, #0
	bl Hitbox_SetAttack
_081A045A:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081A0468: .4byte 0x00000CFC
_081A046C: .4byte 0x00000D4C
