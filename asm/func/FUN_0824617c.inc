	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r5, r1, #0
	ldrb r0, [r5]
	cmp r0, #0
	beq _08246206
	movs r0, #0
	strb r0, [r5]
	adds r2, r5, #0
	adds r2, #0xd4
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
	adds r4, r5, #0
	adds r4, #0x14
	ldr r0, [r5, #0x14]
	ldr r1, [r5, #0x18]
	str r0, [r5, #0x64]
	str r1, [r5, #0x68]
	bl FUN_080230c4
	str r0, [r5, #0x6c]
	movs r1, #0
	ldrsh r2, [r0, r1]
	movs r3, #0x14
	ldrsh r1, [r5, r3]
	subs r2, r2, r1
	movs r6, #4
	ldrsh r1, [r0, r6]
	movs r3, #4
	ldrsh r0, [r4, r3]
	subs r1, r1, r0
	adds r0, r2, #0
	bl FUN_0823785c
	adds r3, r0, #0
	ldr r2, _082461E8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _082461EC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r6, _082461F0 @ =0x0203B400
	adds r0, r0, r6
	ldrb r0, [r0]
	cmp r0, #0x7f
	bgt _082461F4
	adds r0, r3, #0
	subs r0, #0x40
	b _082461F8
	.align 2, 0
_082461E8: .4byte 0x030046B8
_082461EC: .4byte 0x000003FF
_082461F0: .4byte 0x0203B400
_082461F4:
	adds r0, r3, #0
	adds r0, #0x40
_082461F8:
	strb r0, [r5, #9]
	adds r0, r5, #0
	adds r0, #0x84
	movs r1, #1
	strh r1, [r0, #0xa]
	adds r0, #0x50
	strh r1, [r0, #0xa]
_08246206:
	adds r4, r5, #0
	adds r4, #0x14
	adds r1, r5, #0
	adds r1, #0x64
	ldr r2, [r5, #0x6c]
	ldrh r3, [r5, #6]
	movs r0, #5
	str r0, [sp]
	adds r0, r4, #0
	bl FUN_08237970
	ldr r3, _08246258 @ =0x085B0A08
	ldrh r0, [r5, #6]
	lsls r0, r0, #2
	movs r2, #0xff
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r6, #0
	ldrsh r1, [r0, r6]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #5
	mov r8, r0
	add r7, sp, #4
	ldrb r0, [r5, #9]
	mov ip, r0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r2, r8
	muls r2, r0, r2
	adds r0, r2, #0
	adds r6, r4, #0
	cmp r0, #0
	blt _0824625C
	asrs r1, r0, #0xc
	b _08246262
	.align 2, 0
_08246258: .4byte 0x085B0A08
_0824625C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08246262:
	movs r0, #0
	strh r1, [r7]
	strh r0, [r7, #2]
	ldr r1, _08246284 @ =0x085B0A08
	mov r3, ip
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r2, r8
	muls r2, r0, r2
	adds r0, r2, #0
	cmp r0, #0
	blt _08246288
	asrs r0, r0, #0xc
	b _0824628E
	.align 2, 0
_08246284: .4byte 0x085B0A08
_08246288:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0824628E:
	strh r0, [r7, #4]
	add r1, sp, #4
	adds r0, r1, #0
	ldrh r0, [r0]
	ldrh r3, [r5, #0x14]
	adds r0, r0, r3
	strh r0, [r5, #0x14]
	ldrh r0, [r1, #2]
	ldrh r2, [r6, #2]
	adds r0, r0, r2
	strh r0, [r6, #2]
	ldrh r0, [r1, #4]
	ldrh r3, [r6, #4]
	adds r0, r0, r3
	strh r0, [r6, #4]
	adds r4, r5, #0
	adds r4, #0x84
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r5, #0
	adds r0, #0xd4
	adds r1, r6, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
	adds r0, r5, #0
	bl FUN_08245eac
	ldrh r0, [r5, #6]
	cmp r0, #0x1f
	bls _082462E4
	movs r0, #2
	strb r0, [r5, #1]
	movs r0, #1
	strb r0, [r5]
	movs r0, #0
	b _082462E6
_082462E4:
	adds r0, #1
_082462E6:
	strh r0, [r5, #6]
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
