	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x44
	movs r4, #0
_08060132:
	movs r1, #1
	lsls r1, r4
	ldr r0, [r6, #0x1c]
	ands r0, r1
	cmp r0, #0
	beq _08060148
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0805ff34
_08060148:
	adds r4, #1
	adds r5, #0x3c
	cmp r4, #0x1f
	ble _08060132
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
