	push {r4, r5, r6, r7, lr}
	movs r6, #0
	movs r0, #0xd0
	lsls r0, r0, #8
	adds r7, r0, #0
_0808D272:
	adds r4, r6, #0
	adds r4, #0x10
	movs r0, #0
	movs r1, #0
	adds r2, r4, #0
	bl FUN_0808a420
	adds r5, r0, #0
	movs r0, #0
	movs r1, #0x1a
	adds r2, r4, #0
	bl FUN_0808a420
	adds r4, r6, #1
	movs r1, #3
_0808D290:
	strh r7, [r5]
	adds r5, #2
	strh r7, [r0]
	adds r0, #2
	subs r1, #1
	cmp r1, #0
	bge _0808D290
	adds r6, r4, #0
	cmp r6, #3
	ble _0808D272
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
