	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r0, _080E72CC @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080E72D0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _080E72D2
	.align 2, 0
_080E72CC: .4byte 0x0000046D
_080E72D0:
	movs r0, #0
_080E72D2:
	cmp r0, #0
	beq _080E72DE
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080ef86c
_080E72DE:
	movs r1, #0x97
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r0, [r0]
	mov r2, sp
	adds r4, r5, #0
	adds r4, #8
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #8
	ldrh r0, [r0, #8]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r3, #4
	ldrsh r1, [r2, r3]
	ldrb r4, [r5, #5]
	bl FUN_0823785c
	subs r1, r0, r4
	cmp r1, #0x80
	bgt _080E7326
	movs r0, #0x80
	rsbs r0, r0, #0
_080E7326:
	cmp r6, #0x3b
	ble _080E73BC
	cmp r6, #0x77
	bgt _080E739A
	adds r0, r5, #0
	movs r1, #3
	bl FUN_080ef86c
	cmp r6, #0x3c
	bne _080E734E
	ldr r1, _080E738C @ =0x000001DF
	adds r0, r5, r1
	ldrb r1, [r0]
	movs r2, #0x90
	lsls r2, r2, #3
	adds r0, r5, r2
	ldrb r2, [r0]
	movs r0, #0
	bl FUN_080e510c
_080E734E:
	cmp r6, #0x64
	bne _080E7362
	bl FUN_080867a0
	movs r3, #0x97
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r0, [r0]
	bl FUN_080f8e3c
_080E7362:
	asrs r0, r6, #2
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080E737A
	movs r0, #0x20
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_080E737A:
	ldr r2, _080E7390 @ =0x0000025D
	adds r0, r5, r2
	ldrb r1, [r0]
	cmp r1, #0
	bne _080E7394
	ldr r0, [r5, #0x44]
	adds r0, #0x48
	strh r1, [r0, #0xe]
	b _080E739A
	.align 2, 0
_080E738C: .4byte 0x000001DF
_080E7390: .4byte 0x0000025D
_080E7394:
	ldr r1, [r5, #0x44]
	movs r0, #0
	strh r0, [r1, #0x2c]
_080E739A:
	ldr r3, _080E73C4 @ =0x0000046E
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _080E73BC
	movs r1, #0xbe
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	movs r2, #0x97
	lsls r2, r2, #3
	adds r1, r5, r2
	movs r0, #0
	str r0, [r1]
_080E73BC:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080E73C4: .4byte 0x0000046E
