	push {lr}
	ldr r3, _08241754 @ =gUnkSolarEntity
	ldr r2, [r3]
	cmp r2, #0
	beq _08241750
	ldrb r0, [r2, #0x19]
	cmp r0, #0
	beq _0824174A
	movs r0, #0
	movs r1, #1
	strb r1, [r2, #0x19]
	ldr r1, [r3]
	strh r0, [r1, #0x20]
	bl Sensor_Enable
_0824174A:
	ldr r1, _08241758 @ =0x0300486C
	movs r0, #0
	strh r0, [r1]
_08241750:
	pop {r0}
	bx r0
	.align 2, 0
_08241754: .4byte gUnkSolarEntity
_08241758: .4byte 0x0300486C
