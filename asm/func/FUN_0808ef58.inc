	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r1, _0808EF88 @ =0x000034E4
	adds r0, r5, r1
	adds r1, r5, #0
	adds r1, #0xc0
	bl MainSprite_AdvanceAnim
	ldr r0, _0808EF8C @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0808EFF8
	ldr r2, _0808EF90 @ =0x00004022
	adds r6, r5, r2
	ldrh r1, [r6]
	cmp r1, #0
	bne _0808EF94
	movs r0, #0xde
	bl PlaySound_082406e0
	b _0808EFE2
	.align 2, 0
_0808EF88: .4byte 0x000034E4
_0808EF8C: .4byte 0x030044E0
_0808EF90: .4byte 0x00004022
_0808EF94:
	movs r2, #0x9e
	lsls r2, r2, #4
	adds r0, r5, r2
	ldr r0, [r0]
	movs r2, #0xda
	lsls r2, r2, #2
	adds r0, r0, r2
	ldrh r2, [r0]
	adds r1, r1, r2
	strh r1, [r0]
	ldr r4, _0808EFEC @ =0x030046A0
	ldr r1, [r4]
	movs r0, #0xe2
	lsls r0, r0, #1
	adds r1, r1, r0
	ldrh r2, [r6]
	ldr r0, _0808EFF0 @ =0x0000401E
	adds r3, r5, r0
	ldrb r0, [r3]
	muls r2, r0, r2
	ldr r0, [r1]
	adds r0, r0, r2
	str r0, [r1]
	ldr r0, [r4]
	movs r1, #0xea
	lsls r1, r1, #1
	adds r2, r0, r1
	ldrh r1, [r6]
	ldrb r0, [r3]
	muls r1, r0, r1
	ldr r0, [r2]
	adds r0, r0, r1
	cmp r0, #0
	bge _0808EFDA
	ldr r0, _0808EFF4 @ =0x7FFFFFFF
_0808EFDA:
	str r0, [r2]
	movs r0, #0xdd
	bl PlaySound_082406e0
_0808EFE2:
	adds r0, r5, #0
	bl FUN_0808ed74
	b _0808F014
	.align 2, 0
_0808EFEC: .4byte 0x030046A0
_0808EFF0: .4byte 0x0000401E
_0808EFF4: .4byte 0x7FFFFFFF
_0808EFF8:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0808F00E
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r5, #0
	bl FUN_0808eb4c
	b _0808F014
_0808F00E:
	adds r0, r5, #0
	bl FUN_0808e8dc
_0808F014:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
