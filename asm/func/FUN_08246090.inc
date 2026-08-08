	push {r4, r5, r6, lr}
	sub sp, #8
	adds r6, r1, #0
	ldrb r0, [r6]
	cmp r0, #0
	beq _082460B6
	movs r0, #0
	strb r0, [r6]
	adds r2, r6, #0
	adds r2, #0xd4
	subs r0, #5
	ldrh r1, [r2, #6]
	ands r0, r1
	strh r0, [r2, #6]
	ldrb r0, [r6, #9]
	lsls r0, r0, #8
	strh r0, [r6, #0xc]
	movs r0, #0x40
	strh r0, [r6, #0xe]
_082460B6:
	ldrh r0, [r6, #0xe]
	cmp r0, #0
	beq _082460C0
	subs r0, #1
	strh r0, [r6, #0xe]
_082460C0:
	adds r0, r6, #0
	bl FUN_08246038
	mov r3, sp
	ldrb r4, [r6, #9]
	ldrh r5, [r6, #0x10]
	ldr r2, _082460E8 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _082460EC
	asrs r1, r0, #0xc
	b _082460F2
	.align 2, 0
_082460E8: .4byte 0x085B0A08
_082460EC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_082460F2:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	ldr r1, _0824610C @ =0x085B0A08
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _08246110
	asrs r0, r0, #0xc
	b _08246116
	.align 2, 0
_0824610C: .4byte 0x085B0A08
_08246110:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08246116:
	strh r0, [r3, #4]
	adds r4, r6, #0
	adds r4, #0x14
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r2, [r6, #0x14]
	adds r0, r0, r2
	strh r0, [r6, #0x14]
	ldrh r0, [r1, #2]
	ldrh r2, [r4, #2]
	adds r0, r0, r2
	strh r0, [r4, #2]
	ldrh r0, [r1, #4]
	ldrh r1, [r4, #4]
	adds r0, r0, r1
	strh r0, [r4, #4]
	adds r5, r6, #0
	adds r5, #0x84
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r6, #0
	adds r0, #0xd4
	adds r1, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r5, #0
	bl FUN_08236400
	adds r0, r6, #0
	bl FUN_08245eac
	ldrh r0, [r6, #6]
	cmp r0, #0x95
	bls _08246170
	movs r0, #3
	strb r0, [r6, #1]
	movs r0, #1
	strb r0, [r6]
	movs r0, #0
	b _08246172
_08246170:
	adds r0, #1
_08246172:
	strh r0, [r6, #6]
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
