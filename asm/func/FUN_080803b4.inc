	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r5, r0, #0
	adds r0, #0xc8
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #5
	mov sl, r0
	movs r0, #0xff
	mov r8, r0
	ldr r1, _08080410 @ =0x085B0A08
	mov sb, r1
	mov ip, r5
	movs r7, #0
	mov r3, ip
	adds r3, #0xec
	movs r6, #3
_080803E0:
	ldrb r0, [r3, #0x10]
	cmp r0, #0
	beq _08080482
	movs r1, #0x80
	lsls r1, r1, #1
	add r1, ip
	ldrh r0, [r1]
	adds r0, #1
	movs r2, #0
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xe
	bls _08080414
	strb r2, [r3, #0x10]
	adds r0, r5, #0
	adds r0, #0xd4
	adds r0, r0, r7
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	b _08080482
	.align 2, 0
_08080410: .4byte 0x085B0A08
_08080414:
	ldrh r2, [r3, #0x12]
	ldrh r1, [r1]
	movs r0, #0x10
	subs r0, r0, r1
	muls r0, r2, r0
	asrs r4, r0, #3
	movs r0, #0x11
	ldrsb r0, [r3, r0]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r0, r1
	mov r1, sl
	adds r2, r1, r0
	mov r0, r8
	ands r2, r0
	ldr r0, [r5, #0x38]
	ldr r1, [r5, #0x3c]
	str r0, [r3]
	str r1, [r3, #4]
	adds r0, r2, #0
	adds r0, #0x40
	mov r1, r8
	ands r0, r1
	lsls r0, r0, #1
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _08080454
	asrs r1, r0, #0xc
	b _0808045A
_08080454:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0808045A:
	ldrh r0, [r3]
	adds r0, r0, r1
	strh r0, [r3]
	mov r0, r8
	ands r2, r0
	lsls r0, r2, #1
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _08080476
	asrs r1, r0, #0xc
	b _0808047C
_08080476:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0808047C:
	ldrh r0, [r3, #4]
	adds r0, r0, r1
	strh r0, [r3, #4]
_08080482:
	movs r0, #0x30
	add ip, r0
	adds r7, #0x30
	adds r3, #0x30
	subs r6, #1
	cmp r6, #0
	bge _080803E0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
