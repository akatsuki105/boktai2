	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r7, r0, #0
	adds r5, r7, #0
	bl FUN_08022ec0
	adds r0, r7, #0
	bl FUN_08038878
	movs r0, #0xad
	lsls r0, r0, #1
	adds r3, r7, r0
	ldrh r0, [r3]
	cmp r0, #0
	beq _080392B0
	movs r2, #4
	adds r1, r7, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldrh r0, [r3]
	subs r0, #1
	strh r0, [r3]
_080392B0:
	movs r1, #0x84
	lsls r1, r1, #2
	adds r4, r7, r1
	movs r2, #4
	adds r1, r7, #0
	adds r1, #0x98
	ldr r0, [r1]
	ands r0, r2
	adds r6, r1, #0
	cmp r0, #0
	beq _080392D0
	ldrh r1, [r4, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r4, #6]
	b _080392E8
_080392D0:
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r4, #6]
	ands r0, r1
	strh r0, [r4, #6]
	movs r2, #0xa8
	lsls r2, r2, #2
	adds r1, r7, r2
	adds r0, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
_080392E8:
	movs r3, #0xe0
	lsls r3, r3, #1
	adds r4, r5, r3
	movs r1, #8
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _08039302
	ldrh r1, [r4, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r4, #6]
	b _08039320
_08039302:
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r4, #6]
	ands r0, r1
	strh r0, [r4, #6]
	movs r0, #0xa8
	lsls r0, r0, #2
	adds r1, r5, r0
	adds r0, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	bl Hitbox_Register
_08039320:
	movs r1, #0x10
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _08039344
	movs r1, #0xa0
	lsls r1, r1, #2
	adds r2, r5, r1
	ldr r0, [r2, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #8]
	movs r2, #0xd7
	lsls r2, r2, #4
	adds r0, r5, r2
	bl AuxShadow_Hide
	b _08039376
_08039344:
	movs r3, #0xa0
	lsls r3, r3, #2
	adds r2, r5, r3
	ldr r0, [r2, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2, #8]
	movs r1, #0x80
	lsls r1, r1, #9
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _0803936C
	movs r4, #0xd7
	lsls r4, r4, #4
	adds r0, r5, r4
	bl AuxShadow_Hide
	b _08039376
_0803936C:
	movs r1, #0xd7
	lsls r1, r1, #4
	adds r0, r5, r1
	bl AuxShadow_Show
_08039376:
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	bne _08039384
	b _080394A6
_08039384:
	ldr r0, _080393B8 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _080393CC
	ldr r0, _080393BC @ =0x03002BE0
	ldr r1, [r0]
	cmp r1, #0
	beq _080393C8
	ldr r2, _080393C0 @ =0x00000446
	adds r0, r1, r2
	ldrh r0, [r0]
	movs r2, #0
	cmp r0, #0
	beq _080393B2
	ldr r3, _080393C4 @ =0x00000442
	adds r0, r1, r3
	ldrh r0, [r0]
	cmp r0, #4
	bne _080393B2
	movs r2, #1
_080393B2:
	adds r0, r2, #0
	b _080393FC
	.align 2, 0
_080393B8: .4byte 0x030047A4
_080393BC: .4byte 0x03002BE0
_080393C0: .4byte 0x00000446
_080393C4: .4byte 0x00000442
_080393C8:
	movs r0, #0
	b _080393FC
_080393CC:
	ldr r0, _08039454 @ =0x03002B48
	ldr r0, [r0]
	cmp r0, #0
	bgt _08039400
	ldr r0, _08039458 @ =0x030046A0
	ldr r0, [r0]
	movs r4, #0x94
	lsls r4, r4, #2
	adds r0, r0, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #2
	beq _08039400
	ldr r0, _0803945C @ =0x03002B8C
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _080393FA
	ldr r0, _08039460 @ =0x03002B60
	ldrh r0, [r0]
	cmp r0, #4
	bne _080393FA
	movs r1, #1
_080393FA:
	adds r0, r1, #0
_080393FC:
	cmp r0, #0
	beq _0803949E
_08039400:
	movs r3, #0x9d
	lsls r3, r3, #3
	adds r2, r5, r3
	ldr r0, [r2, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2, #8]
	movs r4, #0x86
	lsls r4, r4, #1
	adds r0, r7, r4
	ldr r2, [r0]
	movs r0, #0xa1
	lsls r0, r0, #3
	adds r3, r5, r0
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r4, #0
	ldrsh r1, [r3, r4]
	subs r0, r0, r1
	movs r4, #4
	ldrsh r1, [r2, r4]
	movs r4, #4
	ldrsh r2, [r3, r4]
	subs r1, r1, r2
	bl ArcTan2_8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	adds r1, r0, #1
	movs r0, #3
	ands r1, r0
	cmp r1, #0
	beq _08039450
	cmp r1, #3
	bne _08039464
_08039450:
	movs r3, #0x46
	b _08039466
	.align 2, 0
_08039454: .4byte 0x03002B48
_08039458: .4byte 0x030046A0
_0803945C: .4byte 0x03002B8C
_08039460: .4byte 0x03002B60
_08039464:
	movs r3, #0x42
_08039466:
	cmp r1, #1
	ble _08039478
	movs r1, #0x9d
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0, #8]
	movs r2, #4
	orrs r1, r2
	b _08039486
_08039478:
	movs r2, #0x9d
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r1, [r0, #8]
	movs r2, #5
	rsbs r2, r2, #0
	ands r1, r2
_08039486:
	str r1, [r0, #8]
	movs r4, #0x9d
	lsls r4, r4, #3
	adds r0, r5, r4
	movs r2, #0x98
	lsls r2, r2, #2
	adds r1, r5, r2
	adds r2, r3, #0
	movs r3, #0
	bl MainSprite_SetPose
	b _080394B4
_0803949E:
	movs r3, #0x9d
	lsls r3, r3, #3
	adds r0, r5, r3
	b _080394AC
_080394A6:
	movs r4, #0x9d
	lsls r4, r4, #3
	adds r0, r5, r4
_080394AC:
	ldr r1, [r0, #8]
	movs r2, #1
	orrs r1, r2
	str r1, [r0, #8]
_080394B4:
	movs r1, #0x80
	lsls r1, r1, #0xb
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _080394D4
	ldr r0, _080394D0 @ =0x00000E14
	adds r2, r5, r0
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r2, #4]
	ands r0, r1
	b _080394DE
	.align 2, 0
_080394D0: .4byte 0x00000E14
_080394D4:
	ldr r1, _08039558 @ =0x00000E14
	adds r2, r5, r1
	movs r1, #1
	ldr r0, [r2, #4]
	orrs r0, r1
_080394DE:
	str r0, [r2, #4]
	movs r2, #0xaf
	lsls r2, r2, #1
	adds r1, r5, r2
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	ble _08039510
	subs r0, r2, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08039510
	ldr r4, _0803955C @ =0x000002BA
	adds r1, r5, r4
	ldr r0, _08039560 @ =0x00006543
	strh r0, [r1]
	movs r0, #0xb2
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r2, #0xb8
	lsls r2, r2, #2
	adds r0, r5, r2
	str r0, [r1]
_08039510:
	movs r3, #0xc8
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r1, [r0]
	adds r1, #1
	str r1, [r0]
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r4, r5, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _08039586
	ldr r0, _08039564 @ =0x03003584
	ldr r0, [r0]
	ldr r1, _08039568 @ =0x00005EC0
	adds r6, r0, r1
	ldr r3, _0803956C @ =0x00005EE0
	adds r2, r0, r3
	movs r0, #0xc8
	lsls r0, r0, #2
	adds r1, r5, r0
	ldr r0, _08039570 @ =0x00000161
	adds r3, r5, r0
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	lsls r0, r0, #0x18
	cmp r0, #0
	bge _08039578
	movs r0, #0
	strb r0, [r4]
	adds r0, r2, #0
	ldr r2, _08039574 @ =0x04000008
	bl CpuSet
	b _08039586
	.align 2, 0
_08039558: .4byte 0x00000E14
_0803955C: .4byte 0x000002BA
_08039560: .4byte 0x00006543
_08039564: .4byte 0x03003584
_08039568: .4byte 0x00005EC0
_0803956C: .4byte 0x00005EE0
_08039570: .4byte 0x00000161
_08039574: .4byte 0x04000008
_08039578:
	ldrb r3, [r3]
	movs r0, #7
	str r0, [sp]
	adds r0, r1, #0
	adds r1, r6, #0
	bl BlendPltt
_08039586:
	adds r0, r7, #0
	adds r0, #0xb4
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r1, r7, #0
	adds r1, #0xe0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
