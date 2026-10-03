	push {r4, r5, r6, r7, lr}
	lsls r2, r1, #1
	adds r2, r2, r1
	lsls r2, r2, #5
	ldr r3, _0808C454 @ =0x000020A4
	adds r2, r2, r3
	adds r6, r0, r2
	lsls r1, r1, #5
	ldr r7, _0808C458 @ =0x00003B28
	adds r1, r1, r7
	adds r5, r0, r1
	ldrb r0, [r5, #0x1c]
	cmp r0, #0
	bne _0808C45C
	movs r0, #1
	b _0808C508
	.align 2, 0
_0808C454: .4byte 0x000020A4
_0808C458: .4byte 0x00003B28
_0808C45C:
	ldrh r0, [r5, #0x18]
	adds r0, #1
	strh r0, [r5, #0x18]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r5, #0x1a]
	cmp r0, r1
	blo _0808C47C
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	str r0, [r6, #0x20]
	str r1, [r6, #0x24]
	movs r0, #0
	strb r0, [r5, #0x1c]
	movs r0, #1
	b _0808C508
_0808C47C:
	ldrh r1, [r5, #0x1a]
	ldrh r3, [r5, #0x18]
	subs r4, r1, r3
	movs r2, #0
	ldrsh r0, [r5, r2]
	muls r0, r4, r0
	movs r7, #8
	ldrsh r2, [r5, r7]
	muls r2, r3, r2
	adds r0, r0, r2
	bl Div
	strh r0, [r6, #0x20]
	movs r1, #2
	ldrsh r0, [r5, r1]
	muls r0, r4, r0
	movs r3, #0xa
	ldrsh r2, [r5, r3]
	ldrh r1, [r5, #0x18]
	muls r1, r2, r1
	adds r0, r0, r1
	ldrh r1, [r5, #0x1a]
	bl Div
	strh r0, [r6, #0x22]
	ldr r0, [r5, #0x10]
	cmp r0, #0
	beq _0808C506
	ldr r4, _0808C4DC @ =0x085B0A08
	ldrh r0, [r5, #0x18]
	lsls r0, r0, #7
	ldrh r1, [r5, #0x1a]
	bl Div
	movs r1, #0xff
	ands r1, r0
	lsls r1, r1, #1
	adds r1, r1, r4
	movs r7, #0
	ldrsh r2, [r1, r7]
	movs r1, #0x10
	ldrsh r0, [r5, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _0808C4E0
	asrs r1, r0, #0xc
	b _0808C4E6
	.align 2, 0
_0808C4DC: .4byte 0x085B0A08
_0808C4E0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0808C4E6:
	ldrh r0, [r6, #0x20]
	adds r0, r0, r1
	strh r0, [r6, #0x20]
	movs r3, #0x12
	ldrsh r0, [r5, r3]
	muls r0, r2, r0
	cmp r0, #0
	blt _0808C4FA
	asrs r1, r0, #0xc
	b _0808C500
_0808C4FA:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0808C500:
	ldrh r0, [r6, #0x22]
	adds r0, r0, r1
	strh r0, [r6, #0x22]
_0808C506:
	movs r0, #0
_0808C508:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
