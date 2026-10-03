	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r7, r1, #0
	movs r1, #0xc3
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	ldrh r0, [r5, #0x1c]
	adds r4, r0, #0
	adds r4, #0x2c
	strh r4, [r5, #0x1c]
	ldrh r0, [r5, #0x1e]
	adds r0, #0x40
	strh r0, [r5, #0x1e]
	ldrh r0, [r5, #0x20]
	adds r3, r0, #0
	adds r3, #0x2c
	strh r3, [r5, #0x20]
	movs r2, #0xcf
	lsls r2, r2, #3
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #8
	bne _080B08D4
	ldr r2, _080B0904 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080B0908 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080B090C @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	subs r0, #8
	adds r1, r4, r0
	strh r1, [r5, #0x1c]
	subs r0, r3, r0
	strh r0, [r5, #0x20]
_080B08D4:
	adds r4, r5, #0
	adds r4, #0x48
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x48]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080B0910
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _080B0918
	.align 2, 0
_080B0904: .4byte 0x030046B8
_080B0908: .4byte 0x000003FF
_080B090C: .4byte 0x0203B400
_080B0910:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080B0918:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080B093C
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _080B0944
_080B093C:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080B0944:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080B097C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080B09B4
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080B0980
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080B0974
	ldrb r0, [r4, #5]
_080B0974:
	subs r0, #1
	strh r0, [r4, #8]
	b _080B0990
	.align 2, 0
_080B097C: .4byte 0x0000FFFF
_080B0980:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080B0990
	strh r1, [r4, #8]
_080B0990:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080B09B4
	movs r0, #1
	strb r0, [r4, #7]
_080B09B4:
	adds r0, r5, #0
	adds r0, #0x2c
	adds r1, r7, #0
	bl Video_SetAuxSpritePltt
	adds r0, r5, #0
	adds r1, r7, #0
	bl FUN_080b0398
	adds r0, r5, #0
	adds r1, r7, #0
	bl FUN_080b05b0
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
