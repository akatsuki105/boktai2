	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x40
	movs r4, #0
_0805B72A:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl Entity0805b790_DestroyElem
	adds r4, #1
	adds r5, #0x8c
	cmp r4, #0xf
	ble _0805B72A
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
