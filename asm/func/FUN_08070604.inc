	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	ldr r0, _08070634 @ =0x000009C8
	adds r5, r7, r0
	ldr r1, _08070638 @ =0x00000A8A
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _08070646
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r7, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08070640
	ldr r0, _0807063C @ =0x0000038F
	bl PlaySound_082406e0
	b _08070646
	.align 2, 0
_08070634: .4byte 0x000009C8
_08070638: .4byte 0x00000A8A
_0807063C: .4byte 0x0000038F
_08070640:
	ldr r0, _0807068C @ =0x0000038D
	bl PlaySound_082406e0
_08070646:
	adds r0, r5, #0
	adds r0, #0xc2
	adds r1, r5, #0
	adds r1, #0xbc
	ldrh r2, [r0]
	mov sb, r0
	mov sl, r1
	ldrh r3, [r1]
	cmp r2, r3
	bhs _08070726
	subs r0, #0xa
	ldrh r1, [r0]
	mov r2, sb
	ldrh r0, [r2]
	muls r0, r1, r0
	adds r4, r0, #0
	adds r4, #0xcc
	ldr r2, _08070690 @ =0x085B0A08
	adds r3, r5, #0
	adds r3, #0xc4
	ldrb r0, [r3]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	mov r8, r3
	cmp r0, #0
	blt _08070694
	asrs r1, r0, #0xc
	b _0807069A
	.align 2, 0
_0807068C: .4byte 0x0000038D
_08070690: .4byte 0x085B0A08
_08070694:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0807069A:
	adds r0, r5, #0
	adds r0, #0xa0
	ldrh r0, [r0]
	adds r0, r0, r1
	adds r1, r5, #0
	adds r1, #0x98
	strh r0, [r1]
	adds r0, r5, #0
	adds r0, #0xa2
	ldrh r0, [r0]
	adds r3, r5, #0
	adds r3, #0x9a
	strh r0, [r3]
	mov r3, r8
	ldrb r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	adds r6, r1, #0
	cmp r0, #0
	blt _080706CC
	asrs r2, r0, #0xc
	b _080706D2
_080706CC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080706D2:
	adds r0, r5, #0
	adds r0, #0xa4
	ldrh r0, [r0]
	adds r0, r0, r2
	adds r1, r5, #0
	adds r1, #0x9c
	strh r0, [r1]
	adds r4, r5, #0
	adds r4, #0x48
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
	adds r3, r5, #0
	adds r3, #0xc5
	movs r0, #0
	ldrsb r0, [r3, r0]
	adds r1, r5, #0
	adds r1, #0xbe
	str r1, [sp]
	cmp r0, #0
	bge _08070708
	b _08070804
_08070708:
	movs r1, #0x80
	lsls r1, r1, #0xc
	ldr r0, [r7, #0x20]
	orrs r0, r1
	str r0, [r7, #0x20]
	mov r0, r8
	ldrb r2, [r0]
	ldrb r3, [r3]
	lsls r3, r3, #0x18
	asrs r3, r3, #0x18
	adds r0, r7, #0
	adds r1, r6, #0
	bl FUN_080704d8
	b _08070804
_08070726:
	mov r1, sb
	ldrh r2, [r1]
	mov r0, sl
	ldrh r3, [r0]
	adds r1, r5, #0
	adds r1, #0xbe
	ldrh r0, [r1]
	adds r0, r3, r0
	str r1, [sp]
	cmp r2, r0
	bge _08070804
	adds r0, r5, #0
	adds r0, #0xb8
	ldrh r0, [r0]
	muls r0, r3, r0
	adds r4, r0, #0
	adds r4, #0xcc
	ldr r2, _0807076C @ =0x085B0A08
	adds r3, r5, #0
	adds r3, #0xc4
	ldrb r0, [r3]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	mov r8, r3
	cmp r0, #0
	blt _08070770
	asrs r1, r0, #0xc
	b _08070776
	.align 2, 0
_0807076C: .4byte 0x085B0A08
_08070770:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08070776:
	adds r0, r5, #0
	adds r0, #0xa0
	ldrh r0, [r0]
	adds r0, r0, r1
	adds r1, r5, #0
	adds r1, #0x98
	strh r0, [r1]
	adds r0, r5, #0
	adds r0, #0xa2
	ldrh r0, [r0]
	adds r3, r5, #0
	adds r3, #0x9a
	strh r0, [r3]
	mov r3, r8
	ldrb r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	adds r6, r1, #0
	cmp r0, #0
	blt _080707A8
	asrs r2, r0, #0xc
	b _080707AE
_080707A8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080707AE:
	adds r0, r5, #0
	adds r0, #0xa4
	ldrh r0, [r0]
	adds r0, r0, r2
	adds r1, r5, #0
	adds r1, #0x9c
	strh r0, [r1]
	adds r4, r5, #0
	adds r4, #0x48
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
	adds r3, r5, #0
	adds r3, #0xc5
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #0
	blt _08070804
	movs r1, #0x80
	lsls r1, r1, #0xc
	ldr r0, [r7, #0x20]
	orrs r0, r1
	str r0, [r7, #0x20]
	mov r0, sb
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08070804
	mov r1, r8
	ldrb r2, [r1]
	ldrb r3, [r3]
	lsls r3, r3, #0x18
	asrs r3, r3, #0x18
	adds r0, r7, #0
	adds r1, r6, #0
	bl FUN_080704d8
_08070804:
	mov r2, sb
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r3, sl
	ldrh r1, [r3]
	ldr r3, [sp]
	ldrh r2, [r3]
	adds r3, r5, #0
	adds r3, #0xc0
	adds r1, r1, r2
	ldrh r3, [r3]
	adds r1, r1, r3
	cmp r0, r1
	bge _0807082A
	movs r0, #0
	b _08070832
_0807082A:
	movs r0, #0
	mov r1, sb
	strh r0, [r1]
	movs r0, #1
_08070832:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
