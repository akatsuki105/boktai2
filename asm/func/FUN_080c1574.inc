	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov ip, r0
	adds r0, #0x6e
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #5
	mov sl, r0
	movs r0, #0xff
	mov r8, r0
	ldr r1, _080C15D0 @ =0x085B0A08
	mov sb, r1
	movs r7, #0
	str r7, [sp]
	mov r3, ip
	adds r3, #0x94
	mov r5, ip
	adds r5, #0xa8
	movs r6, #3
_080C15A6:
	ldrb r0, [r3, #0x10]
	cmp r0, #0
	beq _080C1644
	ldrh r0, [r3, #0x14]
	adds r0, #1
	movs r1, #0
	strh r0, [r3, #0x14]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xe
	bls _080C15D4
	strb r1, [r3, #0x10]
	mov r0, ip
	adds r0, #0x7c
	ldr r1, [sp]
	adds r0, r0, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	b _080C1644
	.align 2, 0
_080C15D0: .4byte 0x085B0A08
_080C15D4:
	ldrh r2, [r3, #0x12]
	ldrh r1, [r5]
	movs r0, #0x10
	subs r0, r0, r1
	muls r0, r2, r0
	asrs r4, r0, #3
	movs r0, #0x11
	ldrsb r0, [r3, r0]
	movs r7, #0x80
	lsls r7, r7, #1
	adds r0, r0, r7
	mov r1, sl
	adds r2, r1, r0
	mov r7, r8
	ands r2, r7
	mov r7, ip
	ldr r0, [r7, #0x38]
	ldr r1, [r7, #0x3c]
	str r0, [r3]
	str r1, [r3, #4]
	adds r0, r2, #0
	adds r0, #0x40
	mov r1, r8
	ands r0, r1
	lsls r0, r0, #1
	add r0, sb
	movs r7, #0
	ldrsh r0, [r0, r7]
	muls r0, r4, r0
	cmp r0, #0
	blt _080C1616
	asrs r1, r0, #0xc
	b _080C161C
_080C1616:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080C161C:
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
	blt _080C1638
	asrs r1, r0, #0xc
	b _080C163E
_080C1638:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080C163E:
	ldrh r0, [r3, #4]
	adds r0, r0, r1
	strh r0, [r3, #4]
_080C1644:
	ldr r7, [sp]
	adds r7, #0x30
	str r7, [sp]
	adds r3, #0x30
	adds r5, #0x30
	subs r6, #1
	cmp r6, #0
	bge _080C15A6
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
