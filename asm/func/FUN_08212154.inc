	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r5, r0, #0
	movs r0, #0x88
	adds r0, r0, r5
	mov r8, r0
	adds r7, r5, #0
	adds r7, #0x90
	movs r6, #1
	ldr r2, [r5, #0x44]
	adds r1, r2, #0
	ands r1, r6
	cmp r1, #0
	beq _08212176
	movs r1, #1
_08212176:
	movs r0, #2
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r5, #0x44]
	cmp r1, #0
	beq _082121DA
	movs r0, #0
	bl FUN_0822b644
	movs r4, #0
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822c40c
	movs r0, #2
	bl FUN_0822b644
	str r4, [sp]
	movs r0, #2
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822c40c
	movs r0, #3
	bl FUN_0822b644
	str r4, [sp]
	movs r0, #3
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822c40c
	ldr r1, [r5, #0x38]
	movs r0, #2
	movs r2, #1
	bl FUN_0822c398
	str r4, [sp]
	movs r0, #2
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822c40c
	str r6, [r5, #0x6c]
_082121DA:
	ldr r0, [r5, #0x60]
	ldrh r7, [r7, #2]
	cmp r0, r7
	blt _0821220A
	ldr r0, _0821221C @ =0x030044E0
	ldrh r1, [r0, #2]
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _0821220A
	bl FUN_0823d4c8
	cmp r0, #0
	beq _0821220A
	ldr r0, [r5, #0x64]
	cmp r0, #1
	bgt _0821220A
	movs r1, #2
	str r1, [r5, #0x64]
	movs r0, #0
	str r0, [r5, #0x68]
	ldr r0, [r5, #0x44]
	orrs r0, r1
	str r0, [r5, #0x44]
_0821220A:
	ldr r4, [r5, #0x64]
	cmp r4, #1
	beq _08212264
	cmp r4, #1
	bgt _08212220
	cmp r4, #0
	beq _08212226
	b _082122F6
	.align 2, 0
_0821221C: .4byte 0x030044E0
_08212220:
	cmp r4, #2
	beq _08212294
	b _082122F6
_08212226:
	movs r6, #2
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	ands r0, r6
	movs r0, #3
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r5, #0x44]
	adds r0, r5, #0
	adds r0, #0x88
	ldr r1, [r5, #0x5c]
	lsls r2, r1, #1
	adds r2, r2, r1
	lsls r2, r2, #1
	adds r1, r5, #0
	adds r1, #0x70
	adds r1, r1, r2
	ldrh r2, [r1]
	movs r1, #0
	movs r3, #7
	bl FUN_0821b21c
	cmp r0, #0
	beq _082122F6
	movs r0, #1
	str r0, [r5, #0x64]
	str r4, [r5, #0x68]
	ldr r0, [r5, #0x44]
	orrs r0, r6
	str r0, [r5, #0x44]
	b _082122F6
_08212264:
	movs r3, #2
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	ands r0, r3
	movs r2, #3
	rsbs r2, r2, #0
	ands r2, r1
	str r2, [r5, #0x44]
	ldr r0, [r5, #0x5c]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #1
	adds r1, r5, r1
	adds r1, #0x72
	ldr r0, [r5, #0x68]
	ldrh r1, [r1]
	cmp r0, r1
	blt _082122F6
	str r3, [r5, #0x64]
	movs r0, #0
	str r0, [r5, #0x68]
	orrs r2, r3
	str r2, [r5, #0x44]
	b _082122F6
_08212294:
	ldr r2, [r5, #0x44]
	adds r1, r2, #0
	ands r1, r4
	cmp r1, #0
	beq _082122A0
	movs r1, #1
_082122A0:
	movs r0, #3
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r5, #0x44]
	adds r4, r5, #0
	adds r4, #0x70
	cmp r1, #0
	beq _082122CE
	ldr r1, [r5, #0x5c]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, #4
	adds r0, r4, r0
	ldrh r1, [r0]
	ldr r0, _08212304 @ =0x03004040
	ldr r0, [r0]
	muls r0, r1, r0
	movs r1, #0x40
	bl Div
	mov r1, r8
	str r0, [r1, #4]
_082122CE:
	adds r0, r5, #0
	adds r0, #0x88
	ldr r3, [r5, #0x64]
	ldr r2, [r5, #0x5c]
	lsls r1, r2, #1
	adds r1, r1, r2
	adds r1, r1, r3
	lsls r1, r1, #1
	adds r1, r4, r1
	ldrh r2, [r1]
	movs r1, #1
	movs r3, #7
	bl FUN_0821b21c
	cmp r0, #0
	beq _082122F6
	adds r0, r5, #0
	movs r1, #2
	bl FUN_08213630
_082122F6:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08212304: .4byte 0x03004040
