	push {r4, r5, lr}
	adds r5, r0, #0
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08200ADC
	cmp r1, #0
	blt _08200ADC
	ldr r0, _08200AE0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08200ADC
	ldr r0, _08200AE4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08200AE8
_08200ADC:
	movs r4, #0
	b _08200AF6
	.align 2, 0
_08200AE0: .4byte 0x030046A8
_08200AE4: .4byte 0x030046AC
_08200AE8:
	ldr r0, _08200B08 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08200AF6:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08200B0C
	adds r0, #4
	b _08200B18
	.align 2, 0
_08200B08: .4byte 0x030046A4
_08200B0C:
	ldr r0, _08200B28 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08200B18:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r5, #2]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08200B28: .4byte 0x030046A4
