	push {r4, lr}
	adds r4, r0, #0
	bl Entity730A_Update_Helper_08022864
	ldr r0, [r4, #0x50]
	cmp r0, #0
	beq _080229A4
	cmp r0, #0
	ble _0802299E
	subs r0, #1
	str r0, [r4, #0x50]
_0802299E:
	ldr r0, [r4, #0x54]
	bl FUN_0823b9cc
_080229A4:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
