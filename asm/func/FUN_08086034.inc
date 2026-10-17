	push {r4, lr}
	sub sp, #0x10
	adds r1, r0, #0
	movs r0, #0xc9
	lsls r0, r0, #2
	adds r3, r1, r0
	ldrh r0, [r3]
	cmp r0, #0
	beq _0808606E
	movs r2, #0
	strh r2, [r3]
	ldr r3, _08086078 @ =0x00000326
	adds r0, r1, r3
	strh r2, [r0]
	ldr r0, _0808607C @ =0x00000414
	adds r4, r1, r0
	ldr r0, [r4]
	adds r1, #0x40
	str r2, [sp]
	str r2, [sp, #4]
	movs r2, #0xfa
	str r2, [sp, #8]
	adds r2, #0x28
	str r2, [sp, #0xc]
	movs r2, #0x7f
	movs r3, #0
	bl FUN_080da9c4
	str r0, [r4]
_0808606E:
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08086078: .4byte 0x00000326
_0808607C: .4byte 0x00000414
