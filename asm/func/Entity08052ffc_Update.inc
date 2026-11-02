	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0x34
	movs r5, #0
_08052F86:
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _08052F96
	adds r0, r6, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl Entity08052ffcElem_Update
_08052F96:
	adds r5, #1
	adds r4, #0x40
	cmp r5, #3
	ble _08052F86
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
