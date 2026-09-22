	push {r4, lr}
	ldr r1, _0801896C @ =0x03000084
	ldr r4, [r1]
	cmp r4, #0
	bne _08018970
	movs r0, #1
	rsbs r0, r0, #0
	b _0801898A
	.align 2, 0
_0801896C: .4byte 0x03000084
_08018970:
	ldrb r1, [r4, #0x19]
	cmp r1, #3
	bgt _08018982
	cmp r1, #1
	blt _08018982
	adds r0, r4, #0
	movs r1, #4
	bl WeatherManager_SetState
_08018982:
	adds r2, r4, #0
	adds r2, #0x22
	movs r1, #0
	strb r1, [r2]
_0801898A:
	pop {r4}
	pop {r1}
	bx r1
