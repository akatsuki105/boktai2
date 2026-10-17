	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _0808947C @ =0x00000402
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0x1e
	bne _08089488
	adds r0, r4, #0
	adds r0, #0x48
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #0xef
	lsls r3, r3, #2
	adds r0, r4, r3
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r2, r1, r0
	adds r0, r4, #0
	adds r0, #0x4c
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r3, #0xf0
	lsls r3, r3, #2
	adds r0, r4, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	subs r1, r1, r0
	cmp r2, #0
	bne _0808944E
	cmp r1, #0
	beq _08089470
_0808944E:
	adds r0, r2, #0
	bl ArcTan2_8
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r0, r1
	ldr r2, _08089480 @ =0x00000404
	adds r1, r4, r2
	strh r0, [r1]
	movs r3, #0x80
	lsls r3, r3, #2
	adds r1, r4, r3
	strb r0, [r1]
_08089470:
	ldr r0, _08089484 @ =0x0000033A
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	b _08089502
	.align 2, 0
_0808947C: .4byte 0x00000402
_08089480: .4byte 0x00000404
_08089484: .4byte 0x0000033A
_08089488:
	cmp r0, #0x1d
	bhi _08089502
	ldr r1, _080894B8 @ =0x00000404
	adds r0, r4, r1
	ldrh r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r5, r0, #5
	ldr r2, _080894BC @ =gSineTable
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #2
	adds r0, r0, r1
	cmp r0, #0
	blt _080894C0
	asrs r3, r0, #0xc
	b _080894C6
	.align 2, 0
_080894B8: .4byte 0x00000404
_080894BC: .4byte gSineTable
_080894C0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_080894C6:
	adds r1, r4, #0
	adds r1, #0x48
	ldrh r0, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	cmp r0, #0
	blt _080894E4
	asrs r2, r0, #0xc
	b _080894EA
_080894E4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080894EA:
	adds r1, r4, #0
	adds r1, #0x4c
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldr r3, _08089534 @ =0x00000404
	adds r0, r4, r3
	ldrh r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r4, r2
	strb r1, [r0]
_08089502:
	ldr r0, _08089538 @ =0x00000402
	adds r3, r4, r0
	ldrh r0, [r3]
	subs r0, #1
	strh r0, [r3]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0808952E
	ldr r2, _0808953C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08089540 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08089544 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	adds r0, #0x2d
	strh r0, [r3]
_0808952E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08089534: .4byte 0x00000404
_08089538: .4byte 0x00000402
_0808953C: .4byte 0x030046B8
_08089540: .4byte 0x000003FF
_08089544: .4byte 0x0203B400
