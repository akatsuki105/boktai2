	push {lr}
	adds r0, #0x30
	ldrb r0, [r0]
	cmp r0, #0
	bne _0804D68E
	movs r0, #0
	b _0804D694
_0804D68E:
	bl rfu_clearAllSlot
	movs r0, #1
_0804D694:
	pop {r1}
	bx r1
