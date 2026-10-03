	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xa3
	lsls r1, r1, #4
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0808CC0E
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl FUN_0808a420
	movs r1, #0xd0
	lsls r1, r1, #8
	adds r2, r1, #0
	movs r1, #8
_0808CBFA:
	strh r2, [r0]
	adds r0, #2
	subs r1, #1
	cmp r1, #0
	bge _0808CBFA
	movs r0, #0xa3
	lsls r0, r0, #4
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
_0808CC0E:
	pop {r4}
	pop {r0}
	bx r0
