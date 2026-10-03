	push {r4, r5, r6, lr}
	adds r3, r0, #0
	adds r0, #0x48
	ldrh r0, [r0]
	ldrh r1, [r3, #0x1c]
	adds r0, r0, r1
	strh r0, [r3, #0x1c]
	adds r0, r3, #0
	adds r0, #0x4a
	ldrh r0, [r0]
	ldrh r1, [r3, #0x1e]
	adds r0, r0, r1
	strh r0, [r3, #0x1e]
	adds r0, r3, #0
	adds r0, #0x4c
	ldrh r0, [r0]
	ldrh r1, [r3, #0x20]
	adds r0, r0, r1
	strh r0, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x54
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x12
	movs r1, #3
	ands r0, r1
	strh r0, [r3, #0x10]
	adds r1, r3, #0
	adds r1, #0x56
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080AC864
	ldr r2, _080AC7B0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080AC7B4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080AC7B8 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	asrs r0, r0, #3
	movs r1, #0x1f
	ands r0, r1
	adds r4, r0, #0
	subs r4, #0xf
	adds r6, r2, #0
	cmp r4, #0
	ble _080AC7BC
	ldr r0, [r3]
	movs r1, #4
	orrs r0, r1
	b _080AC7C4
	.align 2, 0
_080AC7B0: .4byte 0x030046B8
_080AC7B4: .4byte 0x000003FF
_080AC7B8: .4byte 0x0203B400
_080AC7BC:
	ldr r0, [r3]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080AC7C4:
	str r0, [r3]
	adds r0, r3, #0
	adds r0, #0x58
	ldrh r0, [r0]
	adds r4, r4, r0
	ldr r0, [r6]
	adds r0, #1
	ldr r1, _080AC80C @ =0x000003FF
	ands r0, r1
	str r0, [r6]
	lsls r0, r0, #1
	ldr r1, _080AC810 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r2, r3, #0
	adds r2, #0x5a
	asrs r0, r0, #3
	movs r1, #3
	ands r0, r1
	ldrh r2, [r2]
	adds r0, r0, r2
	subs r5, r0, #1
	ldr r2, _080AC814 @ =0x085B0A08
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
	blt _080AC818
	asrs r1, r0, #0xc
	b _080AC81E
	.align 2, 0
_080AC80C: .4byte 0x000003FF
_080AC810: .4byte 0x0203B400
_080AC814: .4byte 0x085B0A08
_080AC818:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080AC81E:
	adds r0, r3, #0
	adds r0, #0x48
	strh r1, [r0]
	movs r0, #0xff
	ands r4, r0
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _080AC83A
	asrs r2, r0, #0xc
	b _080AC840
_080AC83A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080AC840:
	adds r0, r3, #0
	adds r0, #0x4c
	strh r2, [r0]
	ldr r0, [r6]
	adds r0, #1
	ldr r1, _080AC86C @ =0x000003FF
	ands r0, r1
	str r0, [r6]
	lsls r0, r0, #1
	ldr r1, _080AC870 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	adds r0, #0xf
	adds r1, r3, #0
	adds r1, #0x56
	strh r0, [r1]
_080AC864:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080AC86C: .4byte 0x000003FF
_080AC870: .4byte 0x0203B400
