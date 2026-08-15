	push {lr}
	ldr r1, _08247770 @ =0x030026C4
	ldr r0, [r1]
	cmp r0, #0
	beq _0824776A
	movs r0, #0
	str r0, [r1]
	bl Sensor_DoDisableIO
_0824776A:
	pop {r0}
	bx r0
	.align 2, 0
_08247770: .4byte 0x030026C4
