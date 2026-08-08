	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r0, #0xe9
	lsls r0, r0, #2
	adds r7, r5, r0
	ldrb r0, [r7]
	cmp r0, #0
	bne _0806624E
	b _08066356
_0806624E:
	movs r1, #0xe5
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	bl FUN_08065b44
	adds r1, r0, #0
	cmp r1, #0
	bne _08066274
	ldr r2, _0806626C @ =0x000003A5
	adds r0, r5, r2
	strb r1, [r0]
	ldr r4, _08066270 @ =0x000003A6
	adds r0, r5, r4
	b _080662A0
	.align 2, 0
_0806626C: .4byte 0x000003A5
_08066270: .4byte 0x000003A6
_08066274:
	movs r1, #0xde
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r1, [r0]
	movs r6, #1
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _08066324
	ldr r2, _080662A8 @ =0x000003A7
	adds r4, r5, r2
	ldrb r1, [r4]
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _080662B0
	ldr r4, _080662AC @ =0x000003A5
	adds r0, r5, r4
	movs r1, #0
	strb r1, [r0]
	subs r2, #1
	adds r0, r5, r2
_080662A0:
	strb r1, [r0]
	strb r1, [r7]
	b _08066402
	.align 2, 0
_080662A8: .4byte 0x000003A7
_080662AC: .4byte 0x000003A5
_080662B0:
	adds r0, r5, #0
	bl FUN_08066040
	strb r0, [r4]
	ldrb r0, [r4]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _080662E4 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _080662E8
	asrs r1, r0, #0xc
	b _080662EE
	.align 2, 0
_080662E4: .4byte 0x085B0A08
_080662E8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080662EE:
	movs r2, #0xea
	lsls r2, r2, #2
	adds r0, r5, r2
	strh r1, [r0]
	ldr r1, _08066310 @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _08066314
	asrs r1, r0, #0xc
	b _0806631A
	.align 2, 0
_08066310: .4byte 0x085B0A08
_08066314:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0806631A:
	movs r2, #0xeb
	lsls r2, r2, #2
	adds r0, r5, r2
	strh r1, [r0]
	b _08066402
_08066324:
	ldr r0, _08066344 @ =0x000003A5
	adds r4, r5, r0
	ldrb r0, [r4]
	cmp r0, #0
	bne _08066402
	ldr r2, _08066348 @ =0x000003A6
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08066350
	ldr r0, _0806634C @ =0x00000335
	bl PlaySound_082406e0
	strb r6, [r4]
	b _08066402
	.align 2, 0
_08066344: .4byte 0x000003A5
_08066348: .4byte 0x000003A6
_0806634C: .4byte 0x00000335
_08066350:
	adds r0, #1
	strb r0, [r1]
	b _08066402
_08066356:
	movs r4, #0xe5
	lsls r4, r4, #1
	adds r0, r5, r4
	ldrh r0, [r0]
	bl FUN_08065b44
	cmp r0, #0
	beq _08066402
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r1, [r0]
	subs r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _0806638A
	cmp r1, #6
	bne _08066402
	movs r2, #0xa4
	lsls r2, r2, #2
	adds r0, r5, r2
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r0, #0
	blt _08066402
_0806638A:
	movs r0, #1
	strb r0, [r7]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r1, [r0]
	ldr r2, _080663C8 @ =0x000003A7
	adds r0, r5, r2
	strb r1, [r0]
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _080663CC @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _080663D0
	asrs r1, r0, #0xc
	b _080663D6
	.align 2, 0
_080663C8: .4byte 0x000003A7
_080663CC: .4byte 0x085B0A08
_080663D0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080663D6:
	movs r4, #0xea
	lsls r4, r4, #2
	adds r0, r5, r4
	strh r1, [r0]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _080663F4
	asrs r2, r0, #0xc
	b _080663FA
_080663F4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080663FA:
	movs r4, #0xeb
	lsls r4, r4, #2
	adds r0, r5, r4
	strh r2, [r0]
_08066402:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
