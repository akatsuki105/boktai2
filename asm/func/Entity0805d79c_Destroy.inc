	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x38
	movs r4, #0
_0805D736:
	movs r1, #1
	lsls r1, r4
	ldr r0, [r6, #0x18]
	ands r0, r1
	cmp r0, #0
	beq _0805D74C
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl Entity0805d79c_ReleaseElem
_0805D74C:
	adds r4, #1
	adds r5, #0x88
	cmp r4, #0x1f
	ble _0805D736
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
