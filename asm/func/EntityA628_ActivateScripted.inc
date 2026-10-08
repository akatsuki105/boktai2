	push {r4, lr}
	ldr r0, _080A07EC @ =0x03002C3C
	ldr r4, [r0]
	cmp r4, #0
	beq _080A07E6
	ldrb r0, [r4, #0x1f]
	cmp r0, #0
	bne _080A07E6
	adds r0, r4, #0
	bl EntityA628_ResetOrbit
	movs r0, #1
	strb r0, [r4, #0x1f]
_080A07E6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A07EC: .4byte 0x03002C3C
