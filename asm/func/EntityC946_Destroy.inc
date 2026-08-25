	push {r4, r5, lr}
	adds r5, r0, #0
	movs r4, #0
_0820FD66:
	movs r0, #0x94
	adds r1, r4, #0
	muls r1, r0, r1
	adds r0, r5, #0
	adds r0, #0x28
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0820FD82
	adds r0, r1, #0
	adds r0, #0x28
	adds r0, r5, r0
	bl FUN_08055d7c
_0820FD82:
	adds r4, #1
	cmp r4, #4
	ble _0820FD66
	movs r1, #0xc3
	lsls r1, r1, #2
	adds r0, r5, r1
	bl FUN_0822a4e0
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
