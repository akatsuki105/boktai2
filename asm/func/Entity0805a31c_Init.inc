	push {r4, r5, r6, lr}
	adds r6, r0, #0
	strh r1, [r6, #0x1c]
	movs r0, #0xa
	strh r0, [r6, #0x1e]
	adds r5, r6, #0
	adds r5, #0x20
	movs r4, #0
_0805A2FC:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_08059bd0
	adds r4, #1
	movs r0, #0x82
	lsls r0, r0, #1
	adds r5, r5, r0
	cmp r4, #7
	ble _0805A2FC
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
