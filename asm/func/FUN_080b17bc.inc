	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080B17E8 @ =0x03002C00
	ldr r0, [r0]
	ldr r1, _080B17EC @ =0x000001F5
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0xc
	bne _080B17E0
	ldr r1, _080B17F0 @ =0x00000C6C
	adds r0, r4, r1
	movs r1, #1
	bl FUN_080af374
	adds r0, r4, #0
	movs r1, #0xa
	bl FUN_080ad1ec
_080B17E0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B17E8: .4byte 0x03002C00
_080B17EC: .4byte 0x000001F5
_080B17F0: .4byte 0x00000C6C
