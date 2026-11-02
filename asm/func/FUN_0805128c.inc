	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	mov sb, r0
	adds r5, r1, #0
	mov r8, r2
	adds r6, r5, #0
	adds r6, #0x50
	adds r7, r5, #0
	adds r7, #0x24
	ldrb r0, [r5, #1]
	cmp r0, #0
	beq _080512FA
	movs r3, #0
	strb r3, [r5, #1]
	ldrb r0, [r5, #3]
	strh r0, [r7, #0x10]
	ldrb r0, [r5, #2]
	strh r0, [r6, #0x10]
	ldr r0, [r5, #0x24]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5, #0x24]
	ldr r0, [r5, #0x50]
	ands r0, r1
	str r0, [r5, #0x50]
	adds r2, r5, #0
	adds r2, #0xc
	movs r0, #3
	mov r1, r8
	ands r0, r1
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	movs r4, #0x88
	lsls r4, r4, #1
	adds r0, r1, r4
	strh r0, [r5, #0xc]
	movs r0, #0x20
	strh r0, [r2, #2]
	strh r3, [r2, #4]
	adds r2, #8
	adds r1, #0x50
	strh r1, [r5, #0x14]
	movs r0, #0x90
	strh r0, [r2, #2]
	strh r3, [r2, #4]
	adds r0, r5, #0
	movs r1, #0x20
	movs r2, #0xf
	bl Entity08051b70Elem_SetRandomWobble
_080512FA:
	adds r4, r5, #0
	adds r4, #0x6c
	adds r1, r5, #0
	adds r1, #0xc
	adds r2, r5, #0
	adds r2, #0x14
	ldr r3, [r5, #8]
	movs r0, #5
	str r0, [sp]
	adds r0, r4, #0
	bl LerpVec3
	ldr r1, [r5, #8]
	movs r0, #6
	ldrsh r2, [r5, r0]
	adds r0, r4, #0
	bl FUN_08050f44
	ldr r0, [r6, #0x1c]
	ldr r1, [r6, #0x20]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	ldr r0, [r5, #8]
	cmp r0, #0x1f
	bls _08051358
	movs r2, #0
	strb r2, [r5]
	movs r0, #1
	strb r0, [r5, #1]
	str r2, [r5, #8]
	movs r0, #3
	mov r1, r8
	ands r0, r1
	lsls r1, r0, #5
	subs r1, r1, r0
	lsls r1, r1, #2
	add r1, sb
	adds r3, r1, #0
	adds r3, #0xef
	ldrb r0, [r5, #3]
	ldrb r4, [r3]
	adds r0, r0, r4
	strb r0, [r3]
	adds r1, #0xf0
	movs r0, #8
	strb r0, [r1]
	strb r2, [r5, #3]
_08051358:
	ldr r0, [r5, #8]
	adds r0, #1
	str r0, [r5, #8]
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
