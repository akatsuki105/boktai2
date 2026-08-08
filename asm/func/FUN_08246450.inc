	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0x24
	movs r5, #0
_0824645A:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r6, #0x18]
	ands r0, r1
	cmp r0, #0
	beq _08246470
	adds r0, r6, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_08245e68
_08246470:
	adds r0, r4, #0
	adds r0, #0xd4
	bl FUN_08236424
	adds r5, #1
	movs r0, #0xb3
	lsls r0, r0, #2
	adds r4, r4, r0
	cmp r5, #7
	ble _0824645A
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
