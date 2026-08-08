	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0x81
	lsls r0, r0, #2
	adds r4, r5, r0
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r0, r4, #0
	bl FUN_08240b98
	ldr r2, _080E8F54 @ =0x0000021E
	adds r1, r5, r2
	strh r0, [r1]
	lsls r0, r0, #0x10
	ldr r1, _080E8F58 @ =0xB5460000
	cmp r0, r1
	bne _080E8F4C
	adds r0, r5, #0
	adds r1, r4, #0
	adds r2, r4, #0
	bl FUN_080e8ae4
_080E8F4C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080E8F54: .4byte 0x0000021E
_080E8F58: .4byte 0xB5460000
