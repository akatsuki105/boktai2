	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r7, r0, #0
	adds r6, r1, #0
	ldrb r0, [r6, #2]
	cmp r0, #0
	beq _08019BA2
	movs r0, #0
	strb r0, [r6, #2]
_08019BA2:
	mov r5, sp
	movs r0, #0x30
	adds r0, r0, r6
	mov ip, r0
	ldrh r0, [r6, #0x30]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	mov r1, ip
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08019BC8
	asrs r0, r0, #8
	b _08019BCE
_08019BC8:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08019BCE:
	strh r0, [r5]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08019BE0
	asrs r0, r0, #8
	b _08019BE6
_08019BE0:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08019BE6:
	adds r4, r0, #0
	mov r2, ip
	movs r3, #2
	ldrsh r1, [r2, r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _08019BFC
	asrs r0, r0, #8
	b _08019C02
_08019BFC:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08019C02:
	subs r2, r4, r0
	adds r4, r4, r0
	ldr r3, _08019C80 @ =0x030047C8
	ldrh r0, [r5]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r5]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r5, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r5, #4]
	adds r5, r7, #0
	adds r5, #0x18
	mov r4, sp
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r2, #0x18
	ldrsh r1, [r7, r2]
	subs r0, r0, r1
	movs r3, #4
	ldrsh r1, [r4, r3]
	movs r3, #4
	ldrsh r2, [r5, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	strb r0, [r6, #1]
	mov r0, sp
	movs r1, #0
	ldrsh r2, [r0, r1]
	movs r3, #0x18
	ldrsh r0, [r7, r3]
	subs r2, r2, r0
	movs r1, #4
	ldrsh r0, [r4, r1]
	movs r3, #4
	ldrsh r1, [r5, r3]
	subs r0, r0, r1
	adds r1, r2, #0
	muls r1, r2, r1
	adds r4, r0, #0
	muls r4, r0, r4
	adds r0, r4, #0
	adds r1, r1, r0
	ldr r0, _08019C84 @ =0x00000FFF
	cmp r1, r0
	bls _08019C74
	ldr r0, [r6, #4]
	movs r1, #0x1f
	ands r0, r1
	cmp r0, #0x10
	bls _08019C88
_08019C74:
	ldr r0, [r6, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r6, #8]
	b _08019CEC
	.align 2, 0
_08019C80: .4byte 0x030047C8
_08019C84: .4byte 0x00000FFF
_08019C88:
	ldr r0, [r6, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #8]
	ldr r2, _08019CB4 @ =gSineTable
	ldrb r3, [r6, #1]
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	movs r0, #0x32
	muls r0, r1, r0
	cmp r0, #0
	blt _08019CB8
	asrs r0, r0, #0xc
	b _08019CBE
	.align 2, 0
_08019CB4: .4byte gSineTable
_08019CB8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08019CBE:
	adds r0, #0x78
	strh r0, [r6, #0x20]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x32
	muls r0, r1, r0
	cmp r0, #0
	blt _08019CD6
	asrs r0, r0, #0xc
	b _08019CDC
_08019CD6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08019CDC:
	adds r0, #0x50
	movs r1, #0
	strh r0, [r6, #0x22]
	strh r1, [r6, #0x24]
	ldrb r1, [r6, #1]
	movs r0, #0xa0
	subs r0, r0, r1
	strb r0, [r6, #0xf]
_08019CEC:
	ldr r0, [r6, #4]
	cmp r0, #0xb3
	bls _08019CFC
	movs r0, #0
	strb r0, [r6]
	str r0, [r6, #4]
	movs r0, #1
	strb r0, [r6, #2]
_08019CFC:
	ldr r0, [r6, #4]
	adds r0, #1
	str r0, [r6, #4]
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
