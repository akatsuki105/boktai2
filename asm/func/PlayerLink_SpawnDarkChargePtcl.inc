	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov r8, r0
	mov sb, r1
	ldr r1, _080CD460 @ =0x0000085E
	add r1, r8
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	movs r1, #0xff
	ands r0, r1
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	beq _080CD3E4
	b _080CD506
_080CD3E4:
	ldr r0, _080CD464 @ =0x0000085D
	add r0, r8
	ldrb r1, [r0]
	movs r0, #0x34
	muls r0, r1, r0
	movs r1, #0x86
	lsls r1, r1, #4
	adds r0, r0, r1
	mov r2, r8
	adds r6, r2, r0
	adds r7, r6, #0
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	adds r1, r6, #0
	adds r1, #0x2b
	movs r0, #4
	strb r0, [r1]
	ldr r0, _080CD468 @ =0x00000858
	add r0, r8
	ldr r1, [r0]
	adds r0, r6, #0
	movs r2, #4
	bl Particle_SetPose
	ldr r3, _080CD46C @ =0x0203B400
	mov ip, r3
	ldr r3, _080CD470 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _080CD474 @ =0x000003FF
	ands r0, r2
	lsls r1, r0, #1
	add r1, ip
	movs r5, #0xff
	ldrb r4, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	movs r1, #0x7f
	ands r0, r1
	adds r1, #0x81
	adds r2, r0, r1
	ldr r1, _080CD478 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _080CD47C
	asrs r0, r0, #0xc
	b _080CD482
	.align 2, 0
_080CD460: .4byte 0x0000085E
_080CD464: .4byte 0x0000085D
_080CD468: .4byte 0x00000858
_080CD46C: .4byte 0x0203B400
_080CD470: .4byte 0x030046B8
_080CD474: .4byte 0x000003FF
_080CD478: .4byte gSineTable
_080CD47C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080CD482:
	strh r0, [r6, #0x2c]
	ldr r0, _080CD498 @ =gSineTable
	lsls r1, r4, #1
	adds r1, r1, r0
	movs r3, #0
	ldrsh r0, [r1, r3]
	muls r0, r2, r0
	cmp r0, #0
	blt _080CD49C
	asrs r0, r0, #0xc
	b _080CD4A2
	.align 2, 0
_080CD498: .4byte gSineTable
_080CD49C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080CD4A2:
	movs r3, #0
	strh r0, [r6, #0x30]
	mov r2, sb
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r7, #0x18]
	str r1, [r7, #0x1c]
	ldrh r0, [r6, #0x2c]
	ldrh r1, [r7, #0x18]
	adds r0, r0, r1
	strh r0, [r7, #0x18]
	ldrh r0, [r6, #0x30]
	ldrh r2, [r7, #0x1c]
	adds r0, r0, r2
	strh r0, [r7, #0x1c]
	ldr r2, _080CD514 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080CD518 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080CD51C @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #7
	ands r0, r1
	adds r0, #0x1c
	adds r1, r6, #0
	adds r1, #0x2a
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0x29
	strb r3, [r0]
	subs r0, #1
	movs r1, #1
	strb r1, [r0]
	ldr r0, _080CD520 @ =0x0000085C
	add r0, r8
	strb r1, [r0]
	ldr r1, _080CD524 @ =0x0000085D
	add r1, r8
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bls _080CD506
	strb r3, [r1]
_080CD506:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080CD514: .4byte 0x030046B8
_080CD518: .4byte 0x000003FF
_080CD51C: .4byte 0x0203B400
_080CD520: .4byte 0x0000085C
_080CD524: .4byte 0x0000085D
