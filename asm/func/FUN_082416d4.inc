	push {lr}
	ldr r0, _082416F4 @ =gUnkSolarEntity
	ldr r0, [r0]
	ldrb r0, [r0, #0x19]
	cmp r0, #2
	bne _082416FC
	bl Sensor_GetRawLevel
	cmp r0, #0
	blt _082416FC
	subs r0, #2
	ldr r1, _082416F8 @ =gSystemSaveData
	ldr r1, [r1]
	str r0, [r1, #4]
	movs r0, #1
	b _082416FE
	.align 2, 0
_082416F4: .4byte gUnkSolarEntity
_082416F8: .4byte gSystemSaveData
_082416FC:
	movs r0, #0
_082416FE:
	pop {r1}
	bx r1
	.align 2, 0
