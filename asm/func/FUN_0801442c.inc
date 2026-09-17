	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov r8, r0
	adds r6, r1, #0
	ldrb r0, [r6, #2]
	cmp r0, #8
	bhi _0801444C
	ldr r0, _08014448 @ =0x085AA850
	adds r0, #0x9c
	b _08014454
	.align 2, 0
_08014448: .4byte 0x085AA850
_0801444C:
	ldr r1, _0801446C @ =0x085AA850
	ldrb r0, [r6, #2]
	lsls r0, r0, #2
	adds r0, r0, r1
_08014454:
	ldr r0, [r0]
	mov sb, r0
	adds r5, r6, #4
	movs r0, #7
	mov sl, r0
_0801445E:
	ldrb r0, [r6, #2]
	adds r3, r0, #0
	cmp r3, #0x14
	bhi _08014470
	mov r1, r8
	ldr r7, [r1, #0x1c]
	b _08014474
	.align 2, 0
_0801446C: .4byte 0x085AA850
_08014470:
	mov r0, r8
	ldr r7, [r0, #0x20]
_08014474:
	ldr r0, [r5, #0x10]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08014480
	b _08014570
_08014480:
	ldrh r0, [r5, #0x28]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080144A4
	cmp r1, #0
	blt _080144A4
	ldr r0, _080144A8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080144A4
	ldr r0, _080144AC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080144B4
_080144A4:
	ldr r0, _080144B0 @ =0x0000FFFF
	b _080144C2
	.align 2, 0
_080144A8: .4byte 0x030046A8
_080144AC: .4byte 0x030046AC
_080144B0: .4byte 0x0000FFFF
_080144B4:
	ldr r0, _080144DC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_080144C2:
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	ldr r0, _080144E0 @ =0x0000FFFF
	cmp r4, r0
	beq _08014534
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080144E4
	adds r0, #4
	b _080144F0
	.align 2, 0
_080144DC: .4byte 0x030046A4
_080144E0: .4byte 0x0000FFFF
_080144E4:
	ldr r0, _08014500 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080144F0:
	ldrh r0, [r0, #2]
	movs r1, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08014508
	ldr r2, _08014504 @ =0x0000FFFF
	ldrb r3, [r6, #2]
	b _08014536
	.align 2, 0
_08014500: .4byte 0x030046A4
_08014504: .4byte 0x0000FFFF
_08014508:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08014518
	adds r0, #4
	b _08014524
_08014518:
	ldr r0, _08014530 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08014524:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	ldrb r3, [r6, #2]
	b _08014536
	.align 2, 0
_08014530: .4byte 0x030046A4
_08014534:
	adds r2, r4, #0
_08014536:
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #8
	bhi _0801455C
	mov r1, r8
	ldr r0, [r1, #0x18]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0801455C
	ldr r0, _08014558 @ =0x0000FFFF
	cmp r2, r0
	beq _0801455C
	strh r2, [r5, #0x2a]
	ldrh r0, [r7, #4]
	add r0, sb
	b _0801456E
	.align 2, 0
_08014558: .4byte 0x0000FFFF
_0801455C:
	ldrh r0, [r5, #6]
	strh r0, [r5, #0x2a]
	ldrb r0, [r6, #2]
	lsls r0, r0, #2
	ldr r1, _08014590 @ =0x085AA850
	adds r0, r0, r1
	ldr r1, [r0]
	ldrh r0, [r7, #4]
	adds r0, r0, r1
_0801456E:
	strh r0, [r5, #0x18]
_08014570:
	adds r5, #0x38
	movs r0, #1
	rsbs r0, r0, #0
	add sl, r0
	mov r1, sl
	cmp r1, #0
	blt _08014580
	b _0801445E
_08014580:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08014590: .4byte 0x085AA850
