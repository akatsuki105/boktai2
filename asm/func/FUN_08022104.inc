	push {lr}
	adds r3, r0, #0
	ldr r2, [r1, #0x2c]
	cmp r2, #0
	beq _08022114
	ldr r0, [r1, #0x30]
	str r0, [r2, #0x30]
	b _08022118
_08022114:
	ldr r0, [r1, #0x30]
	str r0, [r3, #0x74]
_08022118:
	ldr r2, [r1, #0x30]
	cmp r2, #0
	beq _08022122
	ldr r0, [r1, #0x2c]
	str r0, [r2, #0x2c]
_08022122:
	movs r0, #0
	pop {r1}
	bx r1
