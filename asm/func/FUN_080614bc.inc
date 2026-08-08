	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r0, #0xd5
	lsls r0, r0, #3
	adds r6, r5, r0
	ldrb r0, [r6]
	cmp r0, #0
	beq _080615AC
	ldr r0, [r5, #0x1c]
	cmp r0, #1
	bne _080614DE
	movs r1, #0x88
	lsls r1, r1, #3
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _080614F2
_080614DE:
	movs r4, #0xd0
	lsls r4, r4, #3
	adds r2, r5, r4
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #0
	strb r0, [r6]
	b _08061608
_080614F2:
	ldr r1, _08061520 @ =0x000006A9
	adds r0, r5, r1
	ldrb r1, [r0]
	lsls r0, r1, #2
	adds r3, r0, r1
	movs r1, #0xff
	ands r3, r1
	ldr r2, _08061524 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _08061528
	asrs r1, r0, #0xc
	b _0806152E
	.align 2, 0
_08061520: .4byte 0x000006A9
_08061524: .4byte 0x085B0A08
_08061528:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0806152E:
	ldrh r0, [r5, #0x2c]
	adds r0, r0, r1
	movs r4, #0xd3
	lsls r4, r4, #3
	adds r1, r5, r4
	strh r0, [r1]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	movs r0, #0x46
	muls r0, r1, r0
	cmp r0, #0
	blt _0806154E
	asrs r0, r0, #0xc
	b _08061554
_0806154E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08061554:
	movs r1, #0xaf
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrh r4, [r5, #0x2e]
	adds r0, r0, r4
	ldr r4, _08061584 @ =0x0000069A
	adds r1, r5, r4
	strh r0, [r1]
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _08061588
	asrs r2, r0, #0xc
	b _0806158E
	.align 2, 0
_08061584: .4byte 0x0000069A
_08061588:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0806158E:
	ldrh r0, [r5, #0x30]
	subs r0, r0, r2
	ldr r4, _080615A4 @ =0x0000069C
	adds r1, r5, r4
	strh r0, [r1]
	ldr r0, _080615A8 @ =0x000006A9
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _08061608
	.align 2, 0
_080615A4: .4byte 0x0000069C
_080615A8: .4byte 0x000006A9
_080615AC:
	ldr r7, [r5, #0x1c]
	cmp r7, #1
	bne _08061608
	movs r1, #0x88
	lsls r1, r1, #3
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _08061608
	movs r4, #0xd3
	lsls r4, r4, #3
	adds r2, r5, r4
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	ldrh r0, [r2]
	adds r0, #0x38
	movs r4, #0
	strh r0, [r2]
	ldr r0, _08061610 @ =0x0000069A
	adds r1, r5, r0
	movs r2, #0xaf
	lsls r2, r2, #1
	adds r0, r2, #0
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	movs r1, #0xd0
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
	ldr r2, _08061614 @ =0x0000067C
	adds r1, r5, r2
	ldr r1, [r1]
	movs r2, #0x10
	bl FUN_0822dafc
	ldr r1, _08061618 @ =0x000006A9
	adds r0, r5, r1
	strb r4, [r0]
	strb r7, [r6]
_08061608:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08061610: .4byte 0x0000069A
_08061614: .4byte 0x0000067C
_08061618: .4byte 0x000006A9
