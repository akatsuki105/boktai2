	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0808f9a0
	adds r1, r0, #0
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0808FB82
	adds r0, r4, #0
	bl FUN_0808f9e8
	b _0808FBB4
_0808FB82:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0808FB92
	adds r0, r4, #0
	bl FUN_0808fa48
	b _0808FBB4
_0808FB92:
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0808FBA2
	adds r0, r4, #0
	bl FUN_0808faa8
	b _0808FBB4
_0808FBA2:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0808FBAE
	movs r0, #0
	b _0808FBB4
_0808FBAE:
	adds r0, r4, #0
	bl FUN_0808fb08
_0808FBB4:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
