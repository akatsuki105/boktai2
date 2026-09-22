	push {lr}
	bl WeatherManager_RemoveParticles
	ldr r1, _08018694 @ =0x03000084
	movs r0, #0
	str r0, [r1]
	pop {r1}
	bx r1
	.align 2, 0
_08018694: .4byte 0x03000084
