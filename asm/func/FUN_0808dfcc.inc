	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0808E000 @ =0x030044BC
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0808DFF8
	ldr r1, _0808E004 @ =0x000009FE
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #2
	bhi _0808DFF8
	adds r0, r4, #0
	movs r1, #0
	movs r2, #3
	movs r3, #1
	bl FUN_0808a610
	adds r0, r4, #0
	bl FUN_0808daa8
_0808DFF8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808E000: .4byte 0x030044BC
_0808E004: .4byte 0x000009FE
