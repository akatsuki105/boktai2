	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0
	bl FUN_0808a420
	adds r1, r0, #0
	cmp r4, #0
	ble _0808B380
	ldr r0, _0808B388 @ =0x0000F090
	adds r2, r0, #0
	adds r0, r4, #0
_0808B376:
	strh r2, [r1]
	adds r1, #2
	subs r0, #1
	cmp r0, #0
	bne _0808B376
_0808B380:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808B388: .4byte 0x0000F090
