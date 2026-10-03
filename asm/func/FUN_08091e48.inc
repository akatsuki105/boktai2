	push {lr}
	ldr r2, _08091E60 @ =0x00003F9C
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08091E5A
	adds r0, r1, #0
	bl RemoveItem
_08091E5A:
	pop {r0}
	bx r0
	.align 2, 0
_08091E60: .4byte 0x00003F9C
