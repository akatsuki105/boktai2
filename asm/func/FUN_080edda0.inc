	push {lr}
	adds r3, r0, #0
	ldr r0, _080EDDAC @ =0x03002C60
	ldr r2, [r0]
	b _080EDDBC
	.align 2, 0
_080EDDAC: .4byte 0x03002C60
_080EDDB0:
	ldrh r0, [r1]
	cmp r0, r3
	bne _080EDDBA
	adds r0, r1, #0
	b _080EDDC4
_080EDDBA:
	ldr r2, [r2]
_080EDDBC:
	ldr r1, [r2, #4]
	cmp r1, #0
	bne _080EDDB0
	movs r0, #0
_080EDDC4:
	pop {r1}
	bx r1
