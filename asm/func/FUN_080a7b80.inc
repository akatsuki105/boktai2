	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov sb, r0
	movs r0, #0
	str r0, [sp]
_080A7B92:
	movs r0, #0x2c
	ldr r2, [sp]
	adds r1, r2, #0
	muls r1, r0, r1
	mov sl, r1
	mov r7, sb
	add r7, sl
	adds r3, r7, #0
	adds r3, #0xc8
	ldrb r0, [r3]
	cmp r0, #0
	beq _080A7C48
	movs r0, #0xc9
	adds r0, r0, r7
	mov r8, r0
	ldrb r0, [r0]
	adds r0, #1
	movs r4, #0
	mov r1, r8
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #5
	bls _080A7BD4
	mov r0, sb
	adds r0, #0xa0
	add r0, sl
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	strb r4, [r3]
	b _080A7C48
_080A7BD4:
	mov r2, r8
	ldrb r0, [r2]
	movs r4, #8
	subs r4, r4, r0
	adds r6, r4, #1
	adds r5, r7, #0
	adds r5, #0xb8
	movs r1, #0
	ldrsh r0, [r5, r1]
	muls r0, r4, r0
	mov r1, sb
	adds r1, #0x88
	movs r2, #0
	ldrsh r1, [r1, r2]
	adds r0, r0, r1
	adds r1, r6, #0
	bl Div
	strh r0, [r5]
	adds r5, #2
	movs r1, #0
	ldrsh r0, [r5, r1]
	muls r0, r4, r0
	mov r1, sb
	adds r1, #0x8a
	movs r2, #0
	ldrsh r1, [r1, r2]
	adds r0, r0, r1
	adds r1, r6, #0
	bl Div
	strh r0, [r5]
	adds r5, #2
	movs r1, #0
	ldrsh r0, [r5, r1]
	muls r0, r4, r0
	mov r1, sb
	adds r1, #0x8c
	movs r2, #0
	ldrsh r1, [r1, r2]
	adds r0, r0, r1
	adds r1, r6, #0
	bl Div
	strh r0, [r5]
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, #4
	bne _080A7C48
	mov r0, sl
	adds r0, #0xa0
	add r0, sb
	mov r1, sb
	adds r1, #0x9c
	ldr r1, [r1]
	movs r2, #9
	bl FUN_0822dafc
_080A7C48:
	ldr r2, [sp]
	adds r2, #1
	str r2, [sp]
	cmp r2, #7
	ble _080A7B92
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
