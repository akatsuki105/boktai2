	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r3, [r5, #0x58]
	cmp r3, #0
	bne _080D8678
	b _080D877E
_080D8678:
	movs r0, #0x92
	lsls r0, r0, #3
	adds r1, r3, r0
	ldr r0, _080D8694 @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0x92
	lsls r2, r2, #2
	adds r0, r0, r2
	ldr r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _080D8698
	movs r0, #1
	b _080D869A
	.align 2, 0
_080D8694: .4byte 0x030046A0
_080D8698:
	movs r0, #0
_080D869A:
	cmp r0, #0
	beq _080D877E
	adds r2, r5, #0
	adds r2, #0x2e
	ldrb r1, [r2]
	movs r0, #1
	ands r0, r1
	adds r4, r2, #0
	cmp r0, #0
	bne _080D877E
	ldr r1, _080D86D0 @ =0x00000553
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, #0x15
	beq _080D877E
	ldr r2, _080D86D4 @ =0x000001DF
	adds r0, r3, r2
	ldrb r0, [r0]
	subs r0, #1
	cmp r0, #0x1d
	bhi _080D877E
	lsls r0, r0, #2
	ldr r1, _080D86D8 @ =_080D86DC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D86D0: .4byte 0x00000553
_080D86D4: .4byte 0x000001DF
_080D86D8: .4byte _080D86DC
_080D86DC: @ jump table
	.4byte _080D8758 @ case 0
	.4byte _080D877E @ case 1
	.4byte _080D8766 @ case 2
	.4byte _080D8754 @ case 3
	.4byte _080D877E @ case 4
	.4byte _080D877E @ case 5
	.4byte _080D877E @ case 6
	.4byte _080D877E @ case 7
	.4byte _080D877E @ case 8
	.4byte _080D8770 @ case 9
	.4byte _080D877E @ case 10
	.4byte _080D877E @ case 11
	.4byte _080D877E @ case 12
	.4byte _080D877E @ case 13
	.4byte _080D877E @ case 14
	.4byte _080D877E @ case 15
	.4byte _080D877E @ case 16
	.4byte _080D877E @ case 17
	.4byte _080D877E @ case 18
	.4byte _080D877E @ case 19
	.4byte _080D877E @ case 20
	.4byte _080D877E @ case 21
	.4byte _080D877E @ case 22
	.4byte _080D877E @ case 23
	.4byte _080D877E @ case 24
	.4byte _080D877E @ case 25
	.4byte _080D877E @ case 26
	.4byte _080D8754 @ case 27
	.4byte _080D877E @ case 28
	.4byte _080D8766 @ case 29
_080D8754:
	movs r0, #0xee
	b _080D8772
_080D8758:
	adds r0, r5, #0
	adds r0, #0x3b
	ldrb r0, [r0]
	cmp r0, #3
	beq _080D877E
	movs r0, #0xff
	b _080D8772
_080D8766:
	adds r0, r3, #0
	movs r1, #3
	bl FUN_080e81dc
	b _080D8776
_080D8770:
	ldr r0, _080D8784 @ =0x000001CF
_080D8772:
	bl PlaySound_082406e0
_080D8776:
	ldrb r1, [r4]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4]
_080D877E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D8784: .4byte 0x000001CF
