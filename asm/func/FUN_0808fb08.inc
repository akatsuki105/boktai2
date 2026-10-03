	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r3, [r4, #1]
	lsls r1, r3, #2
	ldrb r0, [r4, #2]
	adds r1, r1, r0
	adds r0, r4, #0
	adds r0, #8
	adds r0, r0, r1
	movs r5, #0
	ldrsb r5, [r0, r5]
	adds r2, r3, #1
	cmp r3, #8
	bne _0808FB5C
_0808FB24:
	movs r2, #0
	b _0808FB5C
_0808FB28:
	lsls r1, r2, #2
	ldrb r0, [r4, #2]
	adds r1, r1, r0
	adds r0, r4, #0
	adds r0, #8
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _0808FB56
	cmp r0, r5
	beq _0808FB56
	strb r2, [r4, #1]
	adds r0, r4, #0
	bl FUN_0808f98c
	strb r0, [r4, #3]
	movs r0, #0xdc
	bl PlaySound_082406e0
	movs r0, #1
	b _0808FB62
_0808FB56:
	cmp r2, #8
	beq _0808FB24
	adds r2, #1
_0808FB5C:
	cmp r2, r3
	bne _0808FB28
	movs r0, #0
_0808FB62:
	pop {r4, r5}
	pop {r1}
	bx r1
