	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r0, #0xd6
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #3
	bne _080D044A
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	movs r3, #0xac
	lsls r3, r3, #4
	adds r1, r4, r3
	ldr r0, _080D0478 @ =FUN_080d6b24
	str r0, [r1]
	ldr r1, _080D047C @ =0x00000359
	adds r0, r4, r1
	strb r2, [r0]
	adds r0, r4, #0
	adds r0, #0x88
	str r0, [r4, #0x50]
	str r2, [r4, #0x4c]
	ldr r2, _080D0480 @ =0x000004CC
	adds r1, r4, r2
	adds r0, #0x20
	str r0, [r1]
	ldr r3, _080D0484 @ =0x0000094C
	adds r1, r4, r3
	ldr r0, _080D0488 @ =0x0000FFFF
	strh r0, [r1]
_080D044A:
	movs r0, #0xba
	lsls r0, r0, #2
	adds r2, r4, r0
	ldrb r0, [r2]
	movs r1, #1
	orrs r1, r0
	strb r1, [r2]
	lsls r1, r1, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _080D0494
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _080D048C @ =0x000002E6
	adds r1, r4, r2
	strb r0, [r1]
	ldr r3, _080D0490 @ =0x000002E7
	adds r1, r4, r3
	movs r0, #1
	b _080D04A2
	.align 2, 0
_080D0478: .4byte FUN_080d6b24
_080D047C: .4byte 0x00000359
_080D0480: .4byte 0x000004CC
_080D0484: .4byte 0x0000094C
_080D0488: .4byte 0x0000FFFF
_080D048C: .4byte 0x000002E6
_080D0490: .4byte 0x000002E7
_080D0494:
	lsrs r1, r1, #0x19
	ldr r2, _080D0570 @ =0x000002E6
	adds r0, r4, r2
	strb r1, [r0]
	ldr r3, _080D0574 @ =0x000002E7
	adds r1, r4, r3
	movs r0, #0
_080D04A2:
	strb r0, [r1]
	movs r0, #8
	str r0, [r4, #0x1c]
	ldr r1, _080D0578 @ =0x0000037D
	adds r0, r4, r1
	movs r5, #0
	strb r5, [r0]
	ldr r2, _080D057C @ =0x0000037E
	adds r0, r4, r2
	movs r6, #0
	strh r5, [r0]
	movs r3, #0xd8
	lsls r3, r3, #1
	adds r0, r4, r3
	strh r5, [r0]
	subs r1, #0xfa
	adds r0, r4, r1
	strb r6, [r0]
	adds r0, r4, #0
	bl FUN_080cdda8
	adds r0, r4, #0
	bl FUN_080cc43c
	ldr r2, _080D0580 @ =0x000003CE
	adds r0, r4, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	beq _080D04E4
	adds r0, r4, #0
	bl FUN_080cfa24
_080D04E4:
	ldr r1, _080D0584 @ =0x00000442
	adds r0, r4, r1
	strh r5, [r0]
	ldr r2, _080D0588 @ =0x00000444
	adds r0, r4, r2
	strh r5, [r0]
	ldr r3, _080D058C @ =0x00000446
	adds r0, r4, r3
	strh r5, [r0]
	subs r1, #0x51
	adds r0, r4, r1
	strb r6, [r0]
	subs r2, #0xa0
	adds r0, r4, r2
	strb r6, [r0]
	movs r2, #0
	movs r1, #2
	subs r3, #6
	adds r0, r4, r3
_080D050A:
	strh r2, [r0]
	subs r0, #2
	subs r1, #1
	cmp r1, #0
	bge _080D050A
	movs r1, #0xa2
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0, #0x14]
	ldr r2, _080D0590 @ =0x00000456
	adds r0, r4, r2
	strb r1, [r0]
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #5
	beq _080D054C
	ldr r0, _080D0594 @ =0x00000455
	adds r5, r4, r0
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #0
	blt _080D0548
	adds r0, r4, #0
	adds r0, #0x2c
	movs r1, #0
	ldrsb r1, [r5, r1]
	bl FUN_081df9ac
_080D0548:
	movs r0, #0xff
	strb r0, [r5]
_080D054C:
	ldr r0, [r4, #0x18]
	bl FUN_081df7e8
	ldr r1, _080D0598 @ =0x0000045A
	adds r0, r4, r1
	ldrh r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _080D05DC
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080D059C
	movs r0, #0
	bl FUN_081df7bc
	b _080D05CA
	.align 2, 0
_080D0570: .4byte 0x000002E6
_080D0574: .4byte 0x000002E7
_080D0578: .4byte 0x0000037D
_080D057C: .4byte 0x0000037E
_080D0580: .4byte 0x000003CE
_080D0584: .4byte 0x00000442
_080D0588: .4byte 0x00000444
_080D058C: .4byte 0x00000446
_080D0590: .4byte 0x00000456
_080D0594: .4byte 0x00000455
_080D0598: .4byte 0x0000045A
_080D059C:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D05AC
	movs r0, #1
	bl FUN_081df7bc
	b _080D05CA
_080D05AC:
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080D05BC
	movs r0, #2
	bl FUN_081df7bc
	b _080D05CA
_080D05BC:
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080D05CA
	movs r0, #3
	bl FUN_081df7bc
_080D05CA:
	ldr r2, _080D05E4 @ =0x0000045A
	adds r0, r4, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	adds r2, #2
	adds r1, r4, r2
	ldr r1, [r1]
	bl FUN_080ce544
_080D05DC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D05E4: .4byte 0x0000045A
