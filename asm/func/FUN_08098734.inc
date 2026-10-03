	push {r4, r5, lr}
	movs r5, #0
	ldr r1, _08098754 @ =0x000015E4
	adds r4, r0, r1
_0809873C:
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_08097ca0
	adds r4, #0x60
	adds r5, #1
	cmp r5, #0xf
	ble _0809873C
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08098754: .4byte 0x000015E4
