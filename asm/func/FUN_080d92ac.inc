	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	ldr r0, _080D92DC @ =0x0300015C
	ldr r0, [r0]
	cmp r0, #0
	bne _080D92BE
	b _080D94AA
_080D92BE:
	mov ip, r0
	adds r7, r6, #0
	adds r7, #0x88
	movs r0, #0x80
	lsls r0, r0, #1
	adds r4, r6, r0
	adds r0, r6, #0
	adds r0, #0x3a
	ldrb r0, [r0]
	cmp r0, #2
	beq _080D92E0
	cmp r0, #3
	beq _080D92E6
	movs r3, #0
	b _080D92EA
	.align 2, 0
_080D92DC: .4byte 0x0300015C
_080D92E0:
	mov r1, ip
	ldr r3, [r1, #0x58]
	b _080D92EA
_080D92E6:
	mov r2, ip
	ldr r3, [r2, #0x58]
_080D92EA:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r2, [r5]
	lsrs r2, r2, #6
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #3
	ldrb r0, [r7, #0xb]
	lsrs r0, r0, #3
	muls r0, r1, r0
	muls r0, r2, r0
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r7, #8]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080D9326
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	b _080D932E
_080D9326:
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080D932E:
	str r0, [r7]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080D9352
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _080D935A
_080D9352:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080D935A:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080D9390 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080D93BA
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080D9394
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080D938A
	ldrb r0, [r4, #5]
_080D938A:
	subs r0, #1
	strh r0, [r4, #8]
	b _080D93A4
	.align 2, 0
_080D9390: .4byte 0x0000FFFF
_080D9394:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080D93A4
	strh r1, [r4, #8]
_080D93A4:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	ldrh r1, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
_080D93BA:
	ldr r1, [r6, #0x4c]
	asrs r1, r1, #1
	ldr r2, _080D9434 @ =0x085B0A08
	adds r3, r6, #0
	adds r3, #0x35
	ldrb r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r1, r0
	asrs r0, r0, #0xc
	strh r0, [r6, #4]
	ldrh r0, [r6, #6]
	adds r0, #2
	strh r0, [r6, #6]
	ldr r2, _080D9438 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080D943C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080D9440 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	asrs r0, r0, #4
	movs r1, #7
	ands r0, r1
	ldrb r2, [r3]
	adds r0, r0, r2
	strb r0, [r3]
	ldr r1, [r6]
	ldrh r0, [r6, #4]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r7, #0x18]
	ldr r0, [r6]
	ldrh r1, [r6, #6]
	ldrh r0, [r0, #2]
	adds r1, r1, r0
	ldrh r0, [r6, #0x28]
	adds r0, r0, r1
	strh r0, [r7, #0x1a]
	ldr r0, [r6]
	ldrh r0, [r0, #4]
	ldrh r1, [r6, #4]
	subs r0, r0, r1
	strh r0, [r7, #0x1c]
	ldr r0, [r7]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7]
	movs r1, #6
	ldrsh r0, [r6, r1]
	cmp r0, #0x3c
	bgt _080D9444
	movs r0, #0
	b _080D944E
	.align 2, 0
_080D9434: .4byte 0x085B0A08
_080D9438: .4byte 0x030046B8
_080D943C: .4byte 0x000003FF
_080D9440: .4byte 0x0203B400
_080D9444:
	cmp r0, #0x78
	bgt _080D944C
	movs r0, #1
	b _080D944E
_080D944C:
	movs r0, #2
_080D944E:
	strh r0, [r4, #8]
	movs r2, #6
	ldrsh r0, [r6, r2]
	cmp r0, #0xd2
	ble _080D94A4
	adds r0, r6, #0
	adds r0, #0x2d
	movs r5, #0
	strb r5, [r0]
	movs r0, #0x39
	adds r0, r0, r6
	mov r8, r0
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldr r2, _080D94A0 @ =0x000009FC
	add r2, ip
	movs r3, #1
	adds r1, r3, #0
	lsls r1, r0
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
	ldr r0, [r7]
	orrs r0, r3
	str r0, [r7]
	adds r0, r6, #0
	bl FUN_080d8644
	movs r4, #0
	strh r5, [r6, #0x24]
	adds r0, r7, #0
	bl Particle_Remove
	adds r0, r6, #0
	adds r0, #0x38
	strb r4, [r0]
	movs r0, #0xff
	mov r1, r8
	strb r0, [r1]
	b _080D94AA
	.align 2, 0
_080D94A0: .4byte 0x000009FC
_080D94A4:
	ldr r0, [r6, #0x4c]
	adds r0, #1
	str r0, [r6, #0x4c]
_080D94AA:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
