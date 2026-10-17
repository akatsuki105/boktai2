	push {lr}
	adds r2, r0, #0
	ldr r0, _080CC424 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _080CC428
	movs r0, #1
	rsbs r0, r0, #0
	b _080CC42C
	.align 2, 0
_080CC424: .4byte 0x03002C68
_080CC428:
	movs r3, #0x18
	ldrsh r0, [r0, r3]
_080CC42C:
	cmp r2, r0
	bne _080CC436
	adds r0, r1, #0
	bl sound_08240740
_080CC436:
	pop {r0}
	bx r0
	.align 2, 0
