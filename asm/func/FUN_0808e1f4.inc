	push {r4, r5, lr}
	movs r4, #0
	movs r0, #0xd0
	lsls r0, r0, #8
	adds r5, r0, #0
_0808E1FE:
	adds r2, r4, #0
	adds r2, #0x11
	movs r0, #0
	movs r1, #9
	bl FUN_0808a420
	adds r2, r4, #1
	movs r1, #0xb
_0808E20E:
	strh r5, [r0]
	adds r0, #2
	subs r1, #1
	cmp r1, #0
	bge _0808E20E
	adds r4, r2, #0
	cmp r4, #1
	ble _0808E1FE
	pop {r4, r5}
	pop {r0}
	bx r0
