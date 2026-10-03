	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0808CF40 @ =0x030044BC
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0808CF4A
	adds r0, r4, #0
	bl FUN_0808ce98
	adds r0, r4, #0
	bl FUN_0808da88
	cmp r0, #0
	beq _0808CF44
	movs r0, #0x86
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _0808CF4A
	.align 2, 0
_0808CF40: .4byte 0x030044BC
_0808CF44:
	adds r0, r4, #0
	bl FUN_0809b3b0
_0808CF4A:
	pop {r4}
	pop {r0}
	bx r0
