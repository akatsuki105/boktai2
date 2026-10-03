	push {r4, r5, lr}
	adds r4, r0, #0
	cmp r1, #0
	bne _080BA894
	ldr r1, _080BA87C @ =0x00001409
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #8
	bne _080BA880
	adds r1, #0x2f
	adds r0, r4, r1
	movs r1, #0
	movs r2, #4
	bl FUN_080b98c0
	b _080BA976
	.align 2, 0
_080BA87C: .4byte 0x00001409
_080BA880:
	ldr r1, _080BA890 @ =0x00001438
	adds r0, r4, r1
	movs r2, #1
	rsbs r2, r2, #0
	movs r1, #0
	bl FUN_080b98c0
	b _080BA976
	.align 2, 0
_080BA890: .4byte 0x00001438
_080BA894:
	movs r2, #0
	ldr r1, _080BA8C4 @ =0x0000140C
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #3
	bhi _080BA8E4
	ldr r0, _080BA8C8 @ =0x0000140E
	adds r5, r4, r0
	ldrb r0, [r5]
	bl GetNormalItemID
	cmp r0, #0
	blt _080BA8D0
	ldr r1, _080BA8CC @ =0x0000140B
	adds r0, r4, r1
	ldrb r0, [r0]
	ldrb r5, [r5]
	cmp r0, r5
	beq _080BA8C0
	movs r2, #1
	cmp r0, #0x22
	bne _080BA912
_080BA8C0:
	movs r2, #5
	b _080BA912
	.align 2, 0
_080BA8C4: .4byte 0x0000140C
_080BA8C8: .4byte 0x0000140E
_080BA8CC: .4byte 0x0000140B
_080BA8D0:
	ldr r1, _080BA8E0 @ =0x0000140B
	adds r0, r4, r1
	ldrb r0, [r0]
	bl GetNormalItemID
	mvns r0, r0
	lsrs r2, r0, #0x1f
	b _080BA912
	.align 2, 0
_080BA8E0: .4byte 0x0000140B
_080BA8E4:
	ldr r0, _080BA8F8 @ =0x0000140B
	adds r3, r4, r0
	adds r0, #3
	adds r1, r4, r0
	ldrb r0, [r3]
	ldrb r1, [r1]
	cmp r0, r1
	bne _080BA8FC
	movs r2, #4
	b _080BA912
	.align 2, 0
_080BA8F8: .4byte 0x0000140B
_080BA8FC:
	ldr r1, _080BA920 @ =0x00001409
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #3
	bhi _080BA912
	ldrb r0, [r3]
	bl GetNormalItemID
	asrs r2, r0, #0x1f
	movs r0, #4
	ands r2, r0
_080BA912:
	cmp r2, #4
	beq _080BA92A
	cmp r2, #4
	bgt _080BA924
	cmp r2, #1
	beq _080BA954
	b _080BA968
	.align 2, 0
_080BA920: .4byte 0x00001409
_080BA924:
	cmp r2, #5
	beq _080BA940
	b _080BA968
_080BA92A:
	ldr r1, _080BA93C @ =0x00001438
	adds r0, r4, r1
	movs r2, #1
	rsbs r2, r2, #0
	movs r1, #7
	bl FUN_080b98c0
	b _080BA976
	.align 2, 0
_080BA93C: .4byte 0x00001438
_080BA940:
	ldr r1, _080BA950 @ =0x00001438
	adds r0, r4, r1
	movs r2, #1
	rsbs r2, r2, #0
	movs r1, #6
	bl FUN_080b98c0
	b _080BA976
	.align 2, 0
_080BA950: .4byte 0x00001438
_080BA954:
	ldr r1, _080BA964 @ =0x00001438
	adds r0, r4, r1
	movs r2, #1
	rsbs r2, r2, #0
	movs r1, #3
	bl FUN_080b98c0
	b _080BA976
	.align 2, 0
_080BA964: .4byte 0x00001438
_080BA968:
	ldr r1, _080BA97C @ =0x00001438
	adds r0, r4, r1
	movs r2, #1
	rsbs r2, r2, #0
	adds r1, r2, #0
	bl FUN_080b98c0
_080BA976:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BA97C: .4byte 0x00001438
