	push {r4, r5, r6, lr}
	adds r4, r0, #0
	bl FUN_081dd9d4
	adds r1, r0, #0
	lsls r1, r1, #0x18
	cmp r1, #0
	beq _081DE280
	bl FUN_08238c24
	movs r3, #0
	adds r5, r4, #0
	adds r5, #0x68
	movs r6, #1
_081DE26C:
	adds r2, r5, r3
	ldrb r1, [r2]
	cmp r1, #0
	beq _081DE276
	strb r6, [r2]
_081DE276:
	adds r3, #1
	cmp r3, #3
	ble _081DE26C
	movs r1, #0
	strh r1, [r4, #0x2e]
_081DE280:
	ldr r1, [r4, #0x34]
	cmp r1, #2
	bls _081DE2D2
	bl FUN_08238bc0
	adds r1, r0, #0
	cmp r1, #0
	blt _081DE2A4
	strb r1, [r4, #0x1d]
	ldr r2, _081DE2A0 @ =FUN_081de2dc
	adds r0, r4, #0
	movs r1, #3
	bl Entity9A9F_SetState
	movs r0, #0
	b _081DE2D2
	.align 2, 0
_081DE2A0: .4byte FUN_081de2dc
_081DE2A4:
	ldrh r1, [r4, #0x2e]
	adds r1, #1
	strh r1, [r4, #0x2e]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r1, #0x1d
	bls _081DE2D2
	ldr r2, _081DE2D8 @ =FUN_081de250
	adds r0, r4, #0
	movs r1, #2
	bl Entity9A9F_SetState
	bl FUN_08238bf4
	adds r2, r4, #0
	adds r2, #0x68
	movs r3, #0
	adds r1, r4, #0
	adds r1, #0x6b
_081DE2CA:
	strb r3, [r1]
	subs r1, #1
	cmp r1, r2
	bge _081DE2CA
_081DE2D2:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_081DE2D8: .4byte FUN_081de250
