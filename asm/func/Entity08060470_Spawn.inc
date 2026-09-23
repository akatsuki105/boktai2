	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r6, r0, #0
	mov r8, r1
	adds r4, r2, #0
	adds r7, r3, #0
	bl Entity08060470_Create
	mov sb, r0
	mov r1, sp
	bl Entity08060470_FindFreeElem
	adds r3, r0, #0
	cmp r3, #0
	bne _08060518
	movs r0, #1
	rsbs r0, r0, #0
	b _08060622
_08060518:
	adds r5, r3, #0
	adds r5, #8
	movs r0, #1
	movs r1, #0
	strb r0, [r3]
	strb r0, [r3, #1]
	strh r1, [r3, #2]
	strh r4, [r3, #4]
	ldrh r0, [r3, #4]
	adds r4, r3, #0
	adds r4, #0x20
	mov r1, r8
	muls r1, r0, r1
	mov ip, r1
	ldr r2, _08060558 @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r1, ip
	muls r1, r0, r1
	adds r0, r1, #0
	mov sl, r2
	cmp r0, #0
	blt _0806055C
	asrs r1, r0, #0xc
	b _08060562
	.align 2, 0
_08060558: .4byte 0x085B0A08
_0806055C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08060562:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	movs r0, #0xff
	ands r0, r6
	lsls r0, r0, #1
	add r0, sl
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov r1, ip
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _08060582
	asrs r0, r0, #0xc
	b _08060588
_08060582:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08060588:
	strh r0, [r4, #4]
	adds r1, r5, #0
	adds r1, #0x18
	ldrh r0, [r7]
	ldrh r2, [r5, #0x18]
	adds r0, r0, r2
	strh r0, [r5, #0x18]
	ldrh r0, [r7, #2]
	ldrh r2, [r1, #2]
	adds r0, r0, r2
	strh r0, [r1, #2]
	ldrh r0, [r7, #4]
	ldrh r2, [r1, #4]
	adds r0, r0, r2
	strh r0, [r1, #4]
	ldrh r0, [r3, #4]
	subs r0, #3
	strh r0, [r3, #4]
	adds r2, r3, #0
	adds r2, #0x30
	adds r3, r6, #0
	adds r3, #0x80
	adds r0, r6, #0
	adds r0, #0xc0
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	add r0, sl
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _080605D2
	asrs r1, r0, #0xc
	b _080605D8
_080605D2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080605D8:
	movs r0, #0
	strh r1, [r2]
	strh r0, [r2, #2]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	add r0, sl
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _080605F8
	asrs r0, r0, #0xc
	b _080605FE
_080605F8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080605FE:
	strh r0, [r2, #4]
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	adds r0, r5, #0
	movs r1, #0
	bl FUN_0822da50
	ldr r0, [sp]
	movs r1, #1
	lsls r1, r0
	mov r2, sb
	ldr r0, [r2, #0x1c]
	orrs r0, r1
	str r0, [r2, #0x1c]
	movs r0, #0
_08060622:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
