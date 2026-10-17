	push {lr}
	adds r2, r0, #0
	ldr r0, _080CC3F8 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _080CC3FC
	movs r0, #1
	rsbs r0, r0, #0
	b _080CC400
	.align 2, 0
_080CC3F8: .4byte 0x03002C68
_080CC3FC:
	movs r3, #0x18
	ldrsh r0, [r0, r3]
_080CC400:
	cmp r2, r0
	bne _080CC40A
	adds r0, r1, #0
	bl PlaySound_082406e0
_080CC40A:
	pop {r0}
	bx r0
	.align 2, 0
