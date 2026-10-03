	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0808dcdc
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0808DE2A
	adds r0, r4, #0
	bl FUN_0808d5cc
	adds r0, r4, #0
	bl FUN_0808d774
	adds r0, r4, #0
	bl FUN_0808d4dc
	adds r0, r4, #0
	bl FUN_0808d564
	ldr r0, _0808DE20 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #5
	ands r0, r1
	cmp r0, #0
	beq _0808DE24
	adds r0, r4, #0
	bl FUN_0808d39c
	b _0808DE2A
	.align 2, 0
_0808DE20: .4byte 0x030047A4
_0808DE24:
	adds r0, r4, #0
	bl FUN_0808d3d4
_0808DE2A:
	pop {r4}
	pop {r0}
	bx r0
