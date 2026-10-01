	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	ldr r0, _0801D58C @ =0x00000FE4
	adds r2, r7, r0
	adds r1, r7, #0
	adds r1, #0x62
	ldrh r0, [r1]
	subs r0, #0xb0
	movs r3, #0
	strh r0, [r2, #0x20]
	adds r0, r7, #0
	adds r0, #0x5c
	movs r2, #0
	ldrsh r1, [r1, r2]
	movs r4, #0
	ldrsh r0, [r0, r4]
	ldr r4, _0801D590 @ =0x000010A4
	adds r2, r7, r4
	cmp r1, r0
	bge _0801D594
	adds r1, r7, #0
	adds r1, #0x64
	ldrb r0, [r1]
	adds r6, r7, #0
	adds r6, #0xd8
	cmp r0, #1
	beq _0801D5E2
	movs r0, #1
	strb r0, [r1]
	str r3, [sp]
	adds r0, r2, #0
	adds r1, r6, #0
	movs r2, #0
	b _0801D5BA
	.align 2, 0
_0801D58C: .4byte 0x00000FE4
_0801D590: .4byte 0x000010A4
_0801D594:
	adds r0, r7, #0
	adds r0, #0x5e
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r1, r0
	bge _0801D5C2
	adds r1, r7, #0
	adds r1, #0x64
	ldrb r0, [r1]
	adds r6, r7, #0
	adds r6, #0xd8
	cmp r0, #2
	beq _0801D5E2
	movs r0, #2
	strb r0, [r1]
	str r3, [sp]
	adds r0, r2, #0
	adds r1, r6, #0
	movs r2, #1
_0801D5BA:
	movs r3, #1
	bl MainSprite_SetAnim
	b _0801D5E2
_0801D5C2:
	adds r1, r7, #0
	adds r1, #0x64
	ldrb r0, [r1]
	adds r6, r7, #0
	adds r6, #0xd8
	cmp r0, #3
	beq _0801D5E2
	movs r0, #3
	strb r0, [r1]
	str r3, [sp]
	adds r0, r2, #0
	adds r1, r6, #0
	movs r2, #2
	movs r3, #1
	bl MainSprite_SetAnim
_0801D5E2:
	movs r0, #0xb4
	adds r0, r0, r7
	mov sb, r0
	ldr r1, _0801D604 @ =0x00000E04
	adds r4, r7, r1
	movs r5, #0xc
_0801D5EE:
	adds r0, r4, #0
	adds r1, r6, #0
	bl MainSprite_AdvanceAnim
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0801D5EE
	movs r5, #0
	b _0801D61E
	.align 2, 0
_0801D604: .4byte 0x00000E04
_0801D608:
	adds r1, r5, #6
	movs r0, #0
	str r0, [sp]
	movs r0, #0xd
	str r0, [sp, #4]
	movs r0, #0
	movs r2, #0x10
	movs r3, #5
	bl FUN_0822bcf4
	adds r5, #1
_0801D61E:
	ldr r0, [r7, #0x6c]
	cmp r5, r0
	blo _0801D608
	cmp r5, #9
	bgt _0801D642
	movs r6, #0
	movs r4, #0xd
_0801D62C:
	adds r1, r5, #6
	str r6, [sp]
	str r4, [sp, #4]
	movs r0, #0
	movs r2, #0x10
	movs r3, #6
	bl FUN_0822bcf4
	adds r5, #1
	cmp r5, #9
	ble _0801D62C
_0801D642:
	mov r2, sb
	ldr r0, [r2]
	movs r1, #0x3c
	bl Mod
	movs r1, #0x64
	muls r0, r1, r0
	movs r1, #0x3c
	bl Div
	mov r8, r0
	mov r4, sb
	ldr r0, [r4]
	movs r1, #0x3c
	bl Div
	adds r3, r0, #0
	movs r6, #0x11
	str r6, [sp]
	movs r5, #2
	str r5, [sp, #4]
	movs r4, #0xd
	str r4, [sp, #8]
	movs r0, #0
	movs r1, #0x15
	movs r2, #0x10
	bl FUN_0822be3c
	str r6, [sp]
	str r5, [sp, #4]
	str r4, [sp, #8]
	movs r0, #0
	movs r1, #0x18
	movs r2, #0x10
	mov r3, r8
	bl FUN_0822be3c
	adds r0, r7, #0
	bl FUN_0801d394
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
