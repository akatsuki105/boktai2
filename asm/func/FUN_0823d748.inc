	push {lr}
	bl Script_GetValue
	ldr r1, _0823D760 @ =0x030046A0
	ldr r1, [r1]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r1, r1, r2
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0823D760: .4byte 0x030046A0
