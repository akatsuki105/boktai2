	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _08089638 @ =0x00000402
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0x1e
	bne _08089640
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
	bne _0808960E
	cmp r1, #0
	beq _080896D4
_0808960E:
	adds r0, r2, #0
	bl ArcTan2_8
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r0, r1
	ldr r2, _0808963C @ =0x00000404
	adds r1, r4, r2
	strh r0, [r1]
	adds r0, #4
	movs r1, #7
	ands r0, r1
	movs r3, #0x80
	lsls r3, r3, #2
	adds r1, r4, r3
	b _080896D2
	.align 2, 0
_08089638: .4byte 0x00000402
_0808963C: .4byte 0x00000404
_08089640:
	cmp r0, #0x1d
	bhi _080896D4
	ldr r1, _08089674 @ =0x00000404
	adds r0, r4, r1
	ldrh r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r5, r0, #5
	ldr r2, _08089678 @ =gSineTable
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _0808967C
	asrs r3, r0, #0xc
	b _08089682
	.align 2, 0
_08089674: .4byte 0x00000404
_08089678: .4byte gSineTable
_0808967C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_08089682:
	adds r1, r4, #0
	adds r1, #0x48
	ldrh r0, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _080896A2
	asrs r2, r0, #0xc
	b _080896A8
_080896A2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080896A8:
	adds r1, r4, #0
	adds r1, #0x4c
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldr r3, _08089708 @ =0x00000404
	adds r0, r4, r3
	ldrb r0, [r0]
	adds r0, #4
	movs r1, #7
	ands r0, r1
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r4, r2
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_08087f7c
	ldr r3, _0808970C @ =0x0000033A
	adds r1, r4, r3
	movs r0, #1
_080896D2:
	strb r0, [r1]
_080896D4:
	ldr r0, _08089710 @ =0x00000402
	adds r3, r4, r0
	ldrh r0, [r3]
	subs r0, #1
	strh r0, [r3]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08089700
	ldr r2, _08089714 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08089718 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0808971C @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	adds r0, #0x2d
	strh r0, [r3]
_08089700:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08089708: .4byte 0x00000404
_0808970C: .4byte 0x0000033A
_08089710: .4byte 0x00000402
_08089714: .4byte 0x030046B8
_08089718: .4byte 0x000003FF
_0808971C: .4byte 0x0203B400
