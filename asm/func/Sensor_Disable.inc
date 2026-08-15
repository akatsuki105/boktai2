	push {lr}
	ldr r0, _082477D4 @ =0x030026C4
	ldr r0, [r0]
	cmp r0, #1
	bne _082477C2
	bl Sensor_DisableIO
_082477C2:
	ldr r1, _082477D8 @ =0x030057B8
	movs r0, #0
	str r0, [r1]
	ldr r1, _082477DC @ =0x030057C8
	subs r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_082477D4: .4byte 0x030026C4
_082477D8: .4byte 0x030057B8
_082477DC: .4byte 0x030057C8
