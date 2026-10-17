	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _08087624 @ =0x0000040C
	adds r2, r4, r0
	ldr r0, [r4, #0x48]
	ldr r1, [r4, #0x4c]
	str r0, [r2]
	str r1, [r2, #4]
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	lsls r5, r0, #5
	ldr r2, _08087628 @ =gSineTable
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #7
	cmp r0, #0
	blt _0808762C
	asrs r3, r0, #0xc
	b _08087632
	.align 2, 0
_08087624: .4byte 0x0000040C
_08087628: .4byte gSineTable
_0808762C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_08087632:
	ldr r0, _08087650 @ =0x0000040C
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #7
	cmp r0, #0
	blt _08087654
	asrs r2, r0, #0xc
	b _0808765A
	.align 2, 0
_08087650: .4byte 0x0000040C
_08087654:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0808765A:
	movs r0, #0x82
	lsls r0, r0, #3
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
