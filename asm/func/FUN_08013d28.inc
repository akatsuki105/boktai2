	push {lr}
	ldr r2, [r0, #0x18]
	cmp r2, #0
	beq _08013D40
_08013D30:
	ldrh r0, [r2]
	cmp r0, r1
	bne _08013D3A
	adds r0, r2, #0
	b _08013D42
_08013D3A:
	ldr r2, [r2, #0x50]
	cmp r2, #0
	bne _08013D30
_08013D40:
	movs r0, #0
_08013D42:
	pop {r1}
	bx r1
	.align 2, 0
