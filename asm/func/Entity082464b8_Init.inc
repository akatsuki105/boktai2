	push {r4, r5, r6, lr}
	adds r6, r0, #0
	strh r1, [r6, #0x1c]
	adds r5, r6, #0
	adds r5, #0x24
	movs r4, #0
_08246498:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_08245cfc
	adds r4, #1
	movs r0, #0xb3
	lsls r0, r0, #2
	adds r5, r5, r0
	cmp r4, #7
	ble _08246498
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
