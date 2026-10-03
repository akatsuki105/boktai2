	push {r4, lr}
	adds r3, r0, #0
	adds r2, r1, #0
	ldr r0, _0808B89C @ =0x00000F6C
	adds r4, r3, r0
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	ldr r1, _0808B8A0 @ =0x00000F64
	adds r0, r3, r1
	adds r3, #0x60
	adds r2, #0x29
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r1, r3, #0
	movs r3, #1
	bl MainSprite_SetPose
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808B89C: .4byte 0x00000F6C
_0808B8A0: .4byte 0x00000F64
