	push {r4, r5, r6, lr}
	mov ip, r0
	ldr r3, [r0, #0x18]
	ldr r0, [r3, #0x2c]
	ldr r1, [r3, #0x30]
	mov r2, ip
	str r0, [r2, #0x38]
	str r1, [r2, #0x3c]
	ldrh r0, [r2, #0x3a]
	adds r0, #0xc8
	strh r0, [r2, #0x3a]
	movs r6, #0xba
	lsls r6, r6, #2
	adds r0, r3, r6
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r5, r0, #5
	ldr r1, _080C1454 @ =gSineTable
	adds r0, r5, #0
	adds r0, #0x40
	movs r2, #0xff
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r6, #0
	ldrsh r4, [r0, r6]
	adds r0, r5, #0
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r6, #0
	ldrsh r2, [r0, r6]
	ldr r0, _080C1458 @ =0x000002E7
	adds r3, r3, r0
	ldrb r0, [r3]
	adds r6, r1, #0
	cmp r0, #0
	beq _080C14B2
	movs r0, #0xaa
	muls r0, r4, r0
	cmp r0, #0
	blt _080C145C
	asrs r0, r0, #0xc
	b _080C1462
	.align 2, 0
_080C1454: .4byte gSineTable
_080C1458: .4byte 0x000002E7
_080C145C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080C1462:
	adds r1, r0, #0
	lsls r0, r2, #3
	cmp r0, #0
	blt _080C146E
	asrs r0, r0, #0xc
	b _080C1474
_080C146E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080C1474:
	adds r0, r1, r0
	mov r1, ip
	ldrh r1, [r1, #0x38]
	adds r0, r0, r1
	mov r3, ip
	strh r0, [r3, #0x38]
	movs r0, #0xaa
	muls r0, r2, r0
	cmp r0, #0
	blt _080C148C
	asrs r0, r0, #0xc
	b _080C1492
_080C148C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080C1492:
	adds r1, r0, #0
	lsls r0, r4, #3
	cmp r0, #0
	blt _080C149E
	asrs r0, r0, #0xc
	b _080C14A4
_080C149E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080C14A4:
	subs r0, r1, r0
	mov r1, ip
	ldrh r1, [r1, #0x3c]
	adds r0, r0, r1
	mov r2, ip
	strh r0, [r2, #0x3c]
	b _080C1512
_080C14B2:
	movs r0, #0xaa
	muls r0, r4, r0
	cmp r0, #0
	blt _080C14BE
	asrs r0, r0, #0xc
	b _080C14C4
_080C14BE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080C14C4:
	adds r1, r0, #0
	lsls r0, r2, #3
	cmp r0, #0
	blt _080C14D0
	asrs r0, r0, #0xc
	b _080C14D6
_080C14D0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080C14D6:
	subs r0, r1, r0
	mov r3, ip
	ldrh r3, [r3, #0x38]
	adds r0, r0, r3
	mov r1, ip
	strh r0, [r1, #0x38]
	movs r0, #0xaa
	muls r0, r2, r0
	cmp r0, #0
	blt _080C14EE
	asrs r0, r0, #0xc
	b _080C14F4
_080C14EE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080C14F4:
	adds r1, r0, #0
	lsls r0, r4, #3
	cmp r0, #0
	blt _080C1500
	asrs r0, r0, #0xc
	b _080C1506
_080C1500:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080C1506:
	adds r0, r1, r0
	mov r2, ip
	ldrh r2, [r2, #0x3c]
	adds r0, r0, r2
	mov r3, ip
	strh r0, [r3, #0x3c]
_080C1512:
	movs r2, #0xff
	lsrs r0, r5, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	mov r0, ip
	adds r0, #0x6e
	strb r1, [r0]
	adds r0, r5, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r1, #0
	ldrsh r2, [r0, r1]
	mov r1, ip
	adds r1, #0x6c
	ldrh r0, [r1]
	muls r0, r2, r0
	adds r3, r1, #0
	cmp r0, #0
	blt _080C1542
	asrs r2, r0, #0xc
	b _080C1548
_080C1542:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080C1548:
	mov r0, ip
	adds r0, #0x64
	strh r2, [r0]
	lsls r0, r5, #1
	adds r0, r0, r6
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldrh r0, [r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _080C1562
	asrs r1, r0, #0xc
	b _080C1568
_080C1562:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080C1568:
	mov r0, ip
	adds r0, #0x68
	strh r1, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
