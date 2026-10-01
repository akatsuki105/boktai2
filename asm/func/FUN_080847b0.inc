	push {r4, r5, r6, lr}
	adds r3, r0, #0
	ldrh r0, [r3, #0x2e]
	adds r0, #1
	movs r5, #0
	strh r0, [r3, #0x2e]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bhi _0808485E
	movs r0, #0x18
	ldrsh r2, [r3, r0]
	ldr r1, [r3, #0x28]
	movs r4, #0
	ldrsh r0, [r1, r4]
	subs r2, r2, r0
	adds r4, r1, #0
	cmp r2, #0
	bge _080847D8
	rsbs r2, r2, #0
_080847D8:
	movs r6, #0x1c
	ldrsh r1, [r3, r6]
	movs r6, #4
	ldrsh r0, [r4, r6]
	subs r1, r1, r0
	cmp r1, #0
	bge _080847E8
	rsbs r1, r1, #0
_080847E8:
	cmp r2, #0x7f
	bgt _080847F0
	cmp r1, #0x7f
	ble _0808485E
_080847F0:
	movs r0, #0x32
	ldrsh r2, [r3, r0]
	ldrh r1, [r3, #0x2e]
	movs r0, #0x10
	subs r0, r0, r1
	muls r0, r2, r0
	asrs r5, r0, #4
	ldrh r0, [r3, #0x30]
	adds r0, #1
	movs r1, #0xff
	ands r0, r1
	strh r0, [r3, #0x30]
	ldr r2, _08084828 @ =0x085B0A08
	movs r1, #0x30
	ldrsh r0, [r3, r1]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r6, #0
	ldrsh r0, [r0, r6]
	muls r0, r5, r0
	cmp r0, #0
	blt _0808482C
	asrs r1, r0, #0xc
	b _08084832
	.align 2, 0
_08084828: .4byte 0x085B0A08
_0808482C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08084832:
	ldrh r0, [r4]
	adds r0, r0, r1
	strh r0, [r3, #0x18]
	ldrh r1, [r3, #0x30]
	movs r0, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _08084850
	asrs r1, r0, #0xc
	b _08084856
_08084850:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08084856:
	ldrh r0, [r4, #4]
	adds r0, r0, r1
	strh r0, [r3, #0x1c]
	b _08084868
_0808485E:
	strh r5, [r3, #0x2c]
	ldr r0, [r3]
	movs r1, #1
	orrs r0, r1
	str r0, [r3]
_08084868:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
