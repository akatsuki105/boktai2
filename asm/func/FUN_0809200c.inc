	push {lr}
	ldr r3, _08092024 @ =0x00003F9C
	adds r0, r0, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08092028
	adds r0, r1, #0
	adds r1, r2, #0
	bl SwapNormalItem
	b _08092030
	.align 2, 0
_08092024: .4byte 0x00003F9C
_08092028:
	adds r0, r1, #0
	adds r1, r2, #0
	bl SwapValuable
_08092030:
	pop {r0}
	bx r0
