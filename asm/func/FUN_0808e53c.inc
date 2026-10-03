	push {r4, r5, lr}
	adds r5, r0, #0
	movs r3, #2
	rsbs r3, r3, #0
	ldr r0, _0808E594 @ =0x0000366C
	adds r1, r5, r0
	movs r2, #2
_0808E54A:
	ldr r0, [r1]
	ands r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _0808E54A
	ldr r1, _0808E598 @ =0x00003664
	adds r0, r5, r1
	adds r4, r5, #0
	adds r4, #0xc0
	ldr r2, _0808E59C @ =0x0000401E
	adds r1, r5, r2
	ldrb r2, [r1]
	adds r2, #7
	adds r1, r4, #0
	movs r3, #1
	bl MainSprite_SetPose
	ldr r1, _0808E5A0 @ =0x000036C4
	adds r0, r5, r1
	adds r1, r4, #0
	movs r2, #8
	movs r3, #1
	bl MainSprite_SetPose
	ldr r2, _0808E5A4 @ =0x00003724
	adds r0, r5, r2
	adds r1, r4, #0
	movs r2, #8
	movs r3, #1
	bl MainSprite_SetPose
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808E594: .4byte 0x0000366C
_0808E598: .4byte 0x00003664
_0808E59C: .4byte 0x0000401E
_0808E5A0: .4byte 0x000036C4
_0808E5A4: .4byte 0x00003724
