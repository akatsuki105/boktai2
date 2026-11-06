	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, _0808B788 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _0808B794
	ldr r0, _0808B78C @ =0x0000150C
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, _0808B790 @ =0x00003B25
	adds r0, r4, r1
	ldrb r0, [r0]
	b _0808B81C
	.align 2, 0
_0808B788: .4byte 0x030044E0
_0808B78C: .4byte 0x0000150C
_0808B790: .4byte 0x00003B25
_0808B794:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0808B7B0
	ldr r3, _0808B7AC @ =0x0000150C
	adds r1, r4, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0
	b _0808B81C
	.align 2, 0
_0808B7AC: .4byte 0x0000150C
_0808B7B0:
	movs r2, #0
	ldr r3, _0808B7CC @ =0x00003B25
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _0808B7D0
	movs r0, #0x10
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	rsbs r0, r0, #0
	lsrs r2, r0, #0x1f
	b _0808B7DA
	.align 2, 0
_0808B7CC: .4byte 0x00003B25
_0808B7D0:
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0808B7DA
	movs r2, #1
_0808B7DA:
	adds r5, r4, #0
	adds r5, #0x60
	cmp r2, #0
	beq _0808B80E
	movs r0, #0xdc
	bl PlaySound_082406e0
	ldr r0, _0808B824 @ =0x00003B25
	adds r1, r4, r0
	ldrb r2, [r1]
	movs r0, #1
	subs r0, r0, r2
	movs r3, #0
	strb r0, [r1]
	ldr r2, _0808B828 @ =0x00001504
	adds r0, r4, r2
	ldrb r1, [r1]
	movs r2, #5
	subs r2, r2, r1
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	adds r1, r5, #0
	movs r3, #1
	bl MainSprite_SetAnim
_0808B80E:
	ldr r3, _0808B828 @ =0x00001504
	adds r0, r4, r3
	adds r1, r5, #0
	bl MainSprite_AdvanceAnim
	movs r0, #1
	rsbs r0, r0, #0
_0808B81C:
	add sp, #4
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0808B824: .4byte 0x00003B25
_0808B828: .4byte 0x00001504
