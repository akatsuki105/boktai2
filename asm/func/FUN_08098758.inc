	push {r4, r5, lr}
	movs r5, #0
	ldr r1, _08098778 @ =0x00001D04
	adds r4, r0, r1
_08098760:
	adds r1, r5, #0
	adds r1, #0x10
	adds r0, r4, #0
	bl FUN_08097ca0
	adds r4, #0x60
	adds r5, #1
	cmp r5, #3
	ble _08098760
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08098778: .4byte 0x00001D04
