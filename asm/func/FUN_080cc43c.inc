	push {lr}
	adds r2, r0, #0
	ldr r0, _080CC450 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _080CC454
	movs r1, #1
	rsbs r1, r1, #0
	b _080CC458
	.align 2, 0
_080CC450: .4byte 0x03002C68
_080CC454:
	movs r3, #0x18
	ldrsh r1, [r0, r3]
_080CC458:
	ldr r0, [r2, #0x18]
	cmp r0, r1
	bne _080CC484
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #5
	beq _080CC472
	movs r0, #0xd8
	bl sound_08240740
	b _080CC484
_080CC472:
	ldr r0, _080CC488 @ =0x00000239
	bl sound_08240740
	ldr r0, _080CC48C @ =0x00000202
	bl sound_08240740
	ldr r0, _080CC490 @ =0x00000366
	bl sound_08240740
_080CC484:
	pop {r0}
	bx r0
	.align 2, 0
_080CC488: .4byte 0x00000239
_080CC48C: .4byte 0x00000202
_080CC490: .4byte 0x00000366
