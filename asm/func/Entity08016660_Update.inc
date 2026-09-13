	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r4, [r0, #0x1c]
	cmp r4, #0
	bne _080164E0
	b _08016602
_080164E0:
	movs r0, #1
	mov r8, r0
	movs r1, #2
	mov sb, r1
_080164E8:
	ldr r7, [r4, #0x7c]
	ldrb r0, [r4, #5]
	cmp r0, #0
	beq _080164F8
	adds r0, r4, #0
	bl FUN_080160cc
	b _080165FA
_080164F8:
	adds r6, r4, #0
	adds r6, #0x3c
	adds r3, r4, #0
	adds r3, #0x68
	ldrh r0, [r3, #8]
	lsls r0, r0, #1
	ldr r1, [r4, #0x68]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r3, #4]
	mov r2, r8
	ands r2, r0
	ldrh r1, [r5]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	mov r1, r8
	ands r0, r1
	cmp r2, r0
	beq _0801652C
	ldr r0, [r4, #0x3c]
	movs r1, #4
	orrs r0, r1
	b _08016534
_0801652C:
	ldr r0, [r4, #0x3c]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08016534:
	str r0, [r4, #0x3c]
	ldrb r0, [r3, #4]
	mov r1, sb
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	mov r2, sb
	ands r0, r2
	cmp r1, r0
	beq _08016558
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _08016560
_08016558:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08016560:
	str r0, [r6]
	ldrh r0, [r3, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r3, #0xe]
	ldr r5, _08016598 @ =0x0000FFFF
	adds r2, r5, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r5, [r3, #7]
	cmp r0, r5
	blo _080165DE
	strh r1, [r3, #0xe]
	ldrb r1, [r3, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080165A2
	ldrh r0, [r3, #8]
	cmp r0, #0
	bne _0801659C
	ldrb r0, [r3, #5]
	subs r0, #1
	strh r0, [r3, #8]
	movs r2, #1
	b _080165B8
	.align 2, 0
_08016598: .4byte 0x0000FFFF
_0801659C:
	subs r0, #1
	strh r0, [r3, #8]
	b _080165B6
_080165A2:
	ldrh r0, [r3, #8]
	adds r0, #1
	strh r0, [r3, #8]
	ands r0, r2
	ldrb r2, [r3, #5]
	cmp r0, r2
	blo _080165B6
	strh r1, [r3, #8]
	movs r2, #1
	b _080165B8
_080165B6:
	movs r2, #0
_080165B8:
	ldrh r0, [r3, #8]
	lsls r0, r0, #1
	ldr r1, [r3]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r3, #6]
	ldrb r1, [r3, #6]
	ldrh r0, [r3, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r3, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080165E0
	mov r5, r8
	strb r5, [r3, #7]
	b _080165E0
_080165DE:
	movs r2, #0
_080165E0:
	strb r2, [r4, #4]
	ldr r0, [r4, #0xc]
	ldr r1, [r4, #0x10]
	str r0, [r4, #0x58]
	str r1, [r4, #0x5c]
	ldr r1, _08016610 @ =0x085AA918
	ldrb r0, [r4, #2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_080165FA:
	adds r4, r7, #0
	cmp r4, #0
	beq _08016602
	b _080164E8
_08016602:
	movs r0, #0
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08016610: .4byte 0x085AA918
