	push {r4, r5, lr}
	adds r4, r0, #0
	bl FUN_0808d39c
	ldr r0, _0808DFC0 @ =0x00000D98
	adds r5, r4, r0
	movs r0, #0
	ldrsb r0, [r5, r0]
	movs r3, #0x68
	muls r0, r3, r0
	ldr r2, _0808DFC4 @ =0x00000DAC
	adds r1, r4, r2
	adds r1, r1, r0
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1]
	movs r0, #0
	ldrsb r0, [r5, r0]
	muls r0, r3, r0
	adds r0, r0, r4
	ldr r1, _0808DFC8 @ =0x00000DA4
	adds r0, r0, r1
	adds r4, #0xa0
	adds r1, r4, #0
	movs r2, #0
	movs r3, #1
	bl MainSprite_SetPose
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808DFC0: .4byte 0x00000D98
_0808DFC4: .4byte 0x00000DAC
_0808DFC8: .4byte 0x00000DA4
