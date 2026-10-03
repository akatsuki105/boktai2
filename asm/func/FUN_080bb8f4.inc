	push {r4, r5, lr}
	adds r3, r0, #0
	cmp r1, #0
	bne _080BB930
	ldr r1, _080BB914 @ =0x00001409
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, #8
	bne _080BB91C
	ldr r2, _080BB918 @ =0x00001438
	adds r0, r3, r2
	movs r1, #0
	movs r2, #4
	bl FUN_080b98c0
	b _080BBA7E
	.align 2, 0
_080BB914: .4byte 0x00001409
_080BB918: .4byte 0x00001438
_080BB91C:
	ldr r4, _080BB92C @ =0x00001438
	adds r0, r3, r4
	movs r2, #1
	rsbs r2, r2, #0
	movs r1, #0
	bl FUN_080b98c0
	b _080BBA7E
	.align 2, 0
_080BB92C: .4byte 0x00001438
_080BB930:
	movs r4, #0
	ldr r5, _080BB97C @ =0x0000140C
	adds r0, r3, r5
	ldrb r0, [r0]
	cmp r0, #3
	bhi _080BB9D4
	ldr r1, _080BB980 @ =0x0000140E
	adds r0, r3, r1
	ldrb r2, [r0]
	ldr r0, _080BB984 @ =0x030046A0
	ldr r1, [r0]
	lsls r0, r2, #1
	adds r0, r0, r1
	movs r5, #0xa8
	lsls r5, r5, #1
	adds r0, r0, r5
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r0, #0
	blt _080BB9B4
	ldr r5, _080BB988 @ =0x00001409
	adds r0, r3, r5
	ldrb r0, [r0]
	cmp r0, #8
	bne _080BB990
	adds r0, r1, #0
	adds r0, #0x5c
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, r2
	beq _080BBA14
	ldr r2, _080BB98C @ =0x0000140B
	adds r0, r3, r2
	ldrb r0, [r0]
	cmp r0, #0x22
	bne _080BBA14
	movs r4, #5
	b _080BBA14
	.align 2, 0
_080BB97C: .4byte 0x0000140C
_080BB980: .4byte 0x0000140E
_080BB984: .4byte 0x030046A0
_080BB988: .4byte 0x00001409
_080BB98C: .4byte 0x0000140B
_080BB990:
	ldr r4, _080BB9AC @ =0x0000140B
	adds r0, r3, r4
	ldrb r0, [r0]
	cmp r0, r2
	bne _080BB9B0
	adds r0, r1, #0
	adds r0, #0x5c
	movs r5, #0
	ldrsh r0, [r0, r5]
	movs r4, #5
	cmp r0, r2
	bne _080BBA14
	movs r4, #0
	b _080BBA14
	.align 2, 0
_080BB9AC: .4byte 0x0000140B
_080BB9B0:
	movs r4, #1
	b _080BBA14
_080BB9B4:
	ldr r2, _080BB9D0 @ =0x0000140B
	adds r0, r3, r2
	ldrb r2, [r0]
	lsls r0, r2, #1
	adds r0, r0, r1
	movs r4, #0xa8
	lsls r4, r4, #1
	adds r0, r0, r4
	movs r5, #0
	ldrsh r0, [r0, r5]
	mvns r0, r0
	lsrs r4, r0, #0x1f
	b _080BBA14
	.align 2, 0
_080BB9D0: .4byte 0x0000140B
_080BB9D4:
	ldr r0, _080BB9E8 @ =0x0000140B
	adds r2, r3, r0
	ldr r5, _080BB9EC @ =0x0000140E
	adds r1, r3, r5
	ldrb r0, [r2]
	ldrb r1, [r1]
	cmp r0, r1
	bne _080BB9F0
	movs r4, #4
	b _080BBA14
	.align 2, 0
_080BB9E8: .4byte 0x0000140B
_080BB9EC: .4byte 0x0000140E
_080BB9F0:
	ldr r1, _080BBA24 @ =0x00001409
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, #3
	bhi _080BBA14
	ldrb r2, [r2]
	ldr r0, _080BBA28 @ =0x030046A0
	ldr r1, [r0]
	lsls r0, r2, #1
	adds r0, r0, r1
	movs r2, #0xa8
	lsls r2, r2, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r0, [r0, r4]
	asrs r4, r0, #0x1f
	movs r0, #4
	ands r4, r0
_080BBA14:
	cmp r4, #4
	beq _080BBA32
	cmp r4, #4
	bgt _080BBA2C
	cmp r4, #1
	beq _080BBA5C
	b _080BBA70
	.align 2, 0
_080BBA24: .4byte 0x00001409
_080BBA28: .4byte 0x030046A0
_080BBA2C:
	cmp r4, #5
	beq _080BBA48
	b _080BBA70
_080BBA32:
	ldr r5, _080BBA44 @ =0x00001438
	adds r0, r3, r5
	movs r2, #1
	rsbs r2, r2, #0
	movs r1, #7
	bl FUN_080b98c0
	b _080BBA7E
	.align 2, 0
_080BBA44: .4byte 0x00001438
_080BBA48:
	ldr r1, _080BBA58 @ =0x00001438
	adds r0, r3, r1
	movs r2, #1
	rsbs r2, r2, #0
	movs r1, #6
	bl FUN_080b98c0
	b _080BBA7E
	.align 2, 0
_080BBA58: .4byte 0x00001438
_080BBA5C:
	ldr r2, _080BBA6C @ =0x00001438
	adds r0, r3, r2
	movs r2, #1
	rsbs r2, r2, #0
	movs r1, #3
	bl FUN_080b98c0
	b _080BBA7E
	.align 2, 0
_080BBA6C: .4byte 0x00001438
_080BBA70:
	ldr r4, _080BBA84 @ =0x00001438
	adds r0, r3, r4
	movs r2, #1
	rsbs r2, r2, #0
	adds r1, r2, #0
	bl FUN_080b98c0
_080BBA7E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BBA84: .4byte 0x00001438
