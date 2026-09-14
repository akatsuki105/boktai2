	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	adds r4, r2, #0
	ldr r0, _08013880 @ =0x03000050
	ldr r0, [r0]
	cmp r0, #0
	bne _08013884
	movs r0, #0
	movs r1, #0
	bl Entity0801381c_Create
	cmp r0, #0
	bne _08013884
	movs r0, #1
	rsbs r0, r0, #0
	b _080138EE
	.align 2, 0
_08013880: .4byte 0x03000050
_08013884:
	movs r0, #0
	strb r0, [r6]
	str r5, [r6, #8]
	strb r4, [r6, #1]
	strb r0, [r6, #2]
	strh r0, [r6, #4]
	strh r0, [r6, #6]
	lsls r0, r4, #0x18
	cmp r0, #0
	bne _080138A0
	ldr r0, _0801389C @ =FUN_080136cc
	b _080138A2
	.align 2, 0
_0801389C: .4byte FUN_080136cc
_080138A0:
	ldr r0, _080138F4 @ =FUN_080136c8
_080138A2:
	str r0, [r6, #0x34]
	adds r4, r6, #0
	adds r4, #0xc
	ldr r5, _080138F8 @ =0x03000050
	ldr r0, [r5]
	ldr r1, [r0, #0x18]
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r4, #0
	bl FUN_0822d9f0
	movs r2, #8
	rsbs r2, r2, #0
	adds r0, r4, #0
	adds r1, r2, #0
	bl FUN_0822dad4
	ldr r0, [r5]
	ldr r3, [r0, #0x18]
	ldrb r2, [r6, #0x16]
	lsrs r2, r2, #3
	ldrb r1, [r6, #0x17]
	lsrs r1, r1, #3
	muls r2, r1, r2
	lsls r1, r2, #4
	adds r1, r1, r2
	lsls r1, r1, #1
	ldrh r3, [r3, #4]
	adds r1, r1, r3
	strh r1, [r6, #0x14]
	movs r1, #0xfc
	strb r1, [r6, #0x1c]
	movs r1, #2
	strb r1, [r6, #0x1b]
	adds r1, r6, #0
	bl FUN_08013640
	movs r0, #0
_080138EE:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080138F4: .4byte FUN_080136c8
_080138F8: .4byte 0x03000050
