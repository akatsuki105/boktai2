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
	subs r2, r3, #1
	cmp r3, #0
	bne _0808FAFC
_0808FAC4:
	movs r2, #8
	b _0808FAFC
_0808FAC8:
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
	blt _0808FAF6
	cmp r0, r5
	beq _0808FAF6
	strb r2, [r4, #1]
	adds r0, r4, #0
	bl FUN_0808f98c
	strb r0, [r4, #3]
	movs r0, #0xdc
	bl PlaySound_082406e0
	movs r0, #1
	b _0808FB02
_0808FAF6:
	cmp r2, #0
	beq _0808FAC4
	subs r2, #1
_0808FAFC:
	cmp r2, r3
	bne _0808FAC8
	movs r0, #0
_0808FB02:
	pop {r4, r5}
	pop {r1}
	bx r1
