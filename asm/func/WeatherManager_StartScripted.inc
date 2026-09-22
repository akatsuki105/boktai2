	push {r4, lr}
	ldr r0, _08018940 @ =0x03000084
	ldr r4, [r0]
	cmp r4, #0
	bne _08018944
	movs r0, #1
	rsbs r0, r0, #0
	b _08018954
	.align 2, 0
_08018940: .4byte 0x03000084
_08018944:
	adds r0, r4, #0
	movs r1, #1
	bl WeatherManager_SetState
	adds r2, r4, #0
	adds r2, #0x22
	movs r1, #1
	strb r1, [r2]
_08018954:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
