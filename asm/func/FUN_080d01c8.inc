	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r0, #0xe9
	lsls r0, r0, #2
	adds r6, r5, r0
	ldrb r0, [r6]
	cmp r0, #0
	bne _080D01DA
	b _080D02E2
_080D01DA:
	movs r1, #0xe5
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	bl FUN_080cfc78
	adds r1, r0, #0
	cmp r1, #0
	bne _080D0200
	ldr r2, _080D01F8 @ =0x000003A5
	adds r0, r5, r2
	strb r1, [r0]
	ldr r4, _080D01FC @ =0x000003A6
	adds r0, r5, r4
	b _080D022C
	.align 2, 0
_080D01F8: .4byte 0x000003A5
_080D01FC: .4byte 0x000003A6
_080D0200:
	movs r1, #0xde
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r1, [r0]
	movs r7, #1
	adds r0, r7, #0
	ands r0, r1
	cmp r0, #0
	beq _080D02B0
	ldr r2, _080D0234 @ =0x000003A7
	adds r4, r5, r2
	ldrb r1, [r4]
	adds r0, r7, #0
	ands r0, r1
	cmp r0, #0
	beq _080D023C
	ldr r4, _080D0238 @ =0x000003A5
	adds r0, r5, r4
	movs r1, #0
	strb r1, [r0]
	subs r2, #1
	adds r0, r5, r2
_080D022C:
	strb r1, [r0]
	strb r1, [r6]
	b _080D038E
	.align 2, 0
_080D0234: .4byte 0x000003A7
_080D0238: .4byte 0x000003A5
_080D023C:
	adds r0, r5, #0
	bl FUN_080cffcc
	strb r0, [r4]
	ldrb r0, [r4]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _080D0270 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _080D0274
	asrs r1, r0, #0xc
	b _080D027A
	.align 2, 0
_080D0270: .4byte gSineTable
_080D0274:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080D027A:
	movs r2, #0xea
	lsls r2, r2, #2
	adds r0, r5, r2
	strh r1, [r0]
	ldr r1, _080D029C @ =gSineTable
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _080D02A0
	asrs r1, r0, #0xc
	b _080D02A6
	.align 2, 0
_080D029C: .4byte gSineTable
_080D02A0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080D02A6:
	movs r2, #0xeb
	lsls r2, r2, #2
	adds r0, r5, r2
	strh r1, [r0]
	b _080D038E
_080D02B0:
	ldr r0, _080D02D0 @ =0x000003A5
	adds r4, r5, r0
	ldrb r0, [r4]
	cmp r0, #0
	bne _080D038E
	ldr r2, _080D02D4 @ =0x000003A6
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _080D02DC
	ldr r0, [r5, #0x18]
	ldr r1, _080D02D8 @ =0x00000335
	bl Sound_PlayForPlayer
	strb r7, [r4]
	b _080D038E
	.align 2, 0
_080D02D0: .4byte 0x000003A5
_080D02D4: .4byte 0x000003A6
_080D02D8: .4byte 0x00000335
_080D02DC:
	adds r0, #1
	strb r0, [r1]
	b _080D038E
_080D02E2:
	movs r4, #0xe5
	lsls r4, r4, #1
	adds r0, r5, r4
	ldrh r0, [r0]
	bl FUN_080cfc78
	cmp r0, #0
	beq _080D038E
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r1, [r0]
	subs r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _080D0316
	cmp r1, #6
	bne _080D038E
	movs r2, #0xa4
	lsls r2, r2, #2
	adds r0, r5, r2
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r0, #0
	blt _080D038E
_080D0316:
	movs r0, #1
	strb r0, [r6]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r1, [r0]
	ldr r2, _080D0354 @ =0x000003A7
	adds r0, r5, r2
	strb r1, [r0]
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _080D0358 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _080D035C
	asrs r1, r0, #0xc
	b _080D0362
	.align 2, 0
_080D0354: .4byte 0x000003A7
_080D0358: .4byte gSineTable
_080D035C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080D0362:
	movs r4, #0xea
	lsls r4, r4, #2
	adds r0, r5, r4
	strh r1, [r0]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _080D0380
	asrs r2, r0, #0xc
	b _080D0386
_080D0380:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080D0386:
	movs r4, #0xeb
	lsls r4, r4, #2
	adds r0, r5, r4
	strh r2, [r0]
_080D038E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
