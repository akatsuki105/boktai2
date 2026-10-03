	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r0, _0808B750 @ =0x0000150C
	adds r3, r5, r0
	ldr r0, [r3]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r3]
	ldr r2, _0808B754 @ =0x00001524
	adds r0, r5, r2
	movs r3, #0
	strh r3, [r0]
	adds r2, #2
	adds r0, r5, r2
	strh r3, [r0]
	ldr r2, _0808B758 @ =0x00003B25
	adds r0, r5, r2
	strb r1, [r0]
	lsls r1, r1, #0x18
	movs r2, #5
	cmp r1, #0
	beq _0808B72E
	movs r2, #4
_0808B72E:
	ldr r0, _0808B75C @ =0x00001504
	adds r4, r5, r0
	adds r5, #0x60
	str r3, [sp]
	adds r0, r4, #0
	adds r1, r5, #0
	movs r3, #1
	bl MainSprite_SetAnim
	adds r0, r4, #0
	adds r1, r5, #0
	bl MainSprite_AdvanceAnim
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808B750: .4byte 0x0000150C
_0808B754: .4byte 0x00001524
_0808B758: .4byte 0x00003B25
_0808B75C: .4byte 0x00001504
