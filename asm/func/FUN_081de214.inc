	push {r4, r5, lr}
	adds r4, r0, #0
	bl FUN_081dd9d4
	adds r1, r0, #0
	lsls r1, r1, #0x18
	cmp r1, #0
	beq _081DE22C
	adds r2, r4, #0
	adds r2, #0x23
	movs r1, #0
	strb r1, [r2]
_081DE22C:
	adds r5, r4, #0
	adds r5, #0x23
	ldrb r1, [r5]
	cmp r1, #3
	bne _081DE244
	ldr r2, _081DE24C @ =FUN_081de250
	adds r0, r4, #0
	movs r1, #2
	bl Entity9A9F_SetState
	movs r0, #0
	strb r0, [r5]
_081DE244:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_081DE24C: .4byte FUN_081de250
