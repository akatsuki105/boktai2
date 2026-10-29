	push {r4, r5, lr}
	sub sp, #0x10
	adds r5, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0x1b
	beq _080D502E
	movs r4, #0xba
	lsls r4, r4, #2
	adds r2, r5, r4
	ldrb r0, [r2]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _080D4FE4
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _080D4FE0 @ =0x000002E6
	adds r1, r5, r2
	strb r0, [r1]
	subs r4, #1
	adds r1, r5, r4
	movs r0, #1
	strb r0, [r1]
	b _080D4FF4
	.align 2, 0
_080D4FE0: .4byte 0x000002E6
_080D4FE4:
	lsrs r1, r1, #0x19
	ldr r2, _080D500C @ =0x000002E6
	adds r0, r5, r2
	movs r2, #0
	strb r1, [r0]
	ldr r4, _080D5010 @ =0x000002E7
	adds r0, r5, r4
	strb r2, [r0]
_080D4FF4:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #5
	bne _080D5014
	ldr r0, [r5, #0x18]
	subs r1, #0x6d
	bl Sound_PlayForPlayer
	b _080D501C
	.align 2, 0
_080D500C: .4byte 0x000002E6
_080D5010: .4byte 0x000002E7
_080D5014:
	ldr r0, [r5, #0x18]
	movs r1, #0xe7
	bl Sound_PlayForPlayer
_080D501C:
	ldr r0, [r5, #0x18]
	movs r1, #0xe6
	bl Sound_PlayForPlayer
	adds r0, r5, #0
	movs r1, #0x1b
	movs r2, #0
	bl PlayerLink_SetAction
_080D502E:
	ldr r2, _080D5044 @ =0x0000037D
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #4
	bls _080D503A
	b _080D53D8
_080D503A:
	lsls r0, r0, #2
	ldr r1, _080D5048 @ =_080D504C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D5044: .4byte 0x0000037D
_080D5048: .4byte _080D504C
_080D504C: @ jump table
	.4byte _080D5060 @ case 0
	.4byte _080D50AC @ case 1
	.4byte _080D5244 @ case 2
	.4byte _080D5384 @ case 3
	.4byte _080D53A8 @ case 4
_080D5060:
	movs r4, #0xd6
	lsls r4, r4, #2
	adds r0, r5, r4
	ldrb r0, [r0]
	movs r1, #0x29
	bl Player_GetAnimIdx
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl PlayerLink_PlayAnim
	ldr r0, _080D50A4 @ =0x0000037E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bhi _080D508C
	b _080D53D8
_080D508C:
	adds r0, r5, #0
	movs r1, #0x1b
	movs r2, #1
	bl PlayerLink_SetAction
	ldr r2, _080D50A8 @ =0x000003F6
	adds r1, r5, r2
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r1]
	b _080D53D8
	.align 2, 0
_080D50A4: .4byte 0x0000037E
_080D50A8: .4byte 0x000003F6
_080D50AC:
	movs r4, #0xd6
	lsls r4, r4, #2
	adds r0, r5, r4
	ldrb r0, [r0]
	movs r1, #0x2b
	bl Player_GetAnimIdx
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl PlayerLink_PlayAnim
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _080D50F8 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r4, #0xd6
	lsls r4, r4, #1
	adds r0, r5, r4
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _080D50FC
	asrs r0, r0, #0xc
	b _080D5102
	.align 2, 0
_080D50F8: .4byte gSineTable
_080D50FC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D5102:
	rsbs r0, r0, #0
	strh r0, [r5, #0x34]
	ldr r1, _080D5124 @ =gSineTable
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r4, #0xd6
	lsls r4, r4, #1
	adds r0, r5, r4
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _080D5128
	asrs r0, r0, #0xc
	b _080D512E
	.align 2, 0
_080D5124: .4byte gSineTable
_080D5128:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D512E:
	rsbs r0, r0, #0
	strh r0, [r5, #0x38]
	movs r0, #0xd6
	lsls r0, r0, #1
	adds r2, r5, r0
	ldrh r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	strh r0, [r2]
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp]
	str r1, [sp, #4]
	mov r0, sp
	ldrh r1, [r0]
	ldrh r2, [r5, #0x34]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080D51A0 @ =0xFFFF0000
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	mov r3, sp
	ldrh r0, [r3, #4]
	ldrh r4, [r5, #0x38]
	adds r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #4]
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r3, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080D519A
	cmp r1, #0
	blt _080D519A
	ldr r0, _080D51A4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080D519A
	ldr r0, _080D51A8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080D51AC
_080D519A:
	movs r4, #0
	b _080D51BA
	.align 2, 0
_080D51A0: .4byte 0xFFFF0000
_080D51A4: .4byte 0x030046A8
_080D51A8: .4byte 0x030046AC
_080D51AC:
	ldr r0, _080D51CC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080D51BA:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _080D51D0
	adds r0, #4
	b _080D51DC
	.align 2, 0
_080D51CC: .4byte 0x030046A4
_080D51D0:
	ldr r0, _080D51FC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080D51DC:
	ldrh r0, [r0, #2]
	bl PlayerLink_IsFrozenLava
	cmp r0, #0
	beq _080D51EC
	movs r0, #0
	strh r0, [r5, #0x34]
	strh r0, [r5, #0x38]
_080D51EC:
	ldr r0, _080D5200 @ =0x000003F6
	adds r1, r5, r0
	ldrh r0, [r1]
	cmp r0, #0xe
	bls _080D5204
	subs r0, #0xf
	b _080D5206
	.align 2, 0
_080D51FC: .4byte 0x030046A4
_080D5200: .4byte 0x000003F6
_080D5204:
	movs r0, #0
_080D5206:
	strh r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0x13
	bls _080D5216
	b _080D53D8
_080D5216:
	ldr r2, _080D5240 @ =0x000003F6
	adds r1, r5, r2
	movs r0, #0
	strh r0, [r1]
	ldr r0, [r5, #0x18]
	movs r1, #0xaa
	lsls r1, r1, #2
	bl Sound_PlayForPlayer
	adds r0, r5, #0
	adds r0, #0x2c
	ldr r1, [r5, #0x18]
	bl FUN_081df64c
	adds r0, r5, #0
	movs r1, #0x1b
	movs r2, #2
	bl PlayerLink_SetAction
	b _080D53D8
	.align 2, 0
_080D5240: .4byte 0x000003F6
_080D5244:
	movs r4, #0xba
	lsls r4, r4, #2
	adds r0, r5, r4
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _080D5278 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	movs r4, #0xd6
	lsls r4, r4, #1
	adds r0, r5, r4
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _080D527C
	asrs r0, r0, #0xc
	b _080D5282
	.align 2, 0
_080D5278: .4byte gSineTable
_080D527C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D5282:
	rsbs r0, r0, #0
	strh r0, [r5, #0x34]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r4, #0xd6
	lsls r4, r4, #1
	adds r0, r5, r4
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _080D52A0
	asrs r0, r0, #0xc
	b _080D52A6
_080D52A0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D52A6:
	rsbs r2, r0, #0
	strh r2, [r5, #0x38]
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	add r3, sp, #8
	ldrh r1, [r3]
	ldrh r0, [r5, #0x34]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r4, _080D5300 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #8]
	ldrh r0, [r3, #4]
	adds r2, r2, r0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r0, [r3, #4]
	ands r0, r4
	orrs r0, r2
	str r0, [r3, #4]
	ldrh r0, [r3]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r3, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080D52FC
	cmp r1, #0
	blt _080D52FC
	ldr r0, _080D5304 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080D52FC
	ldr r0, _080D5308 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080D530C
_080D52FC:
	movs r4, #0
	b _080D531A
	.align 2, 0
_080D5300: .4byte 0xFFFF0000
_080D5304: .4byte 0x030046A8
_080D5308: .4byte 0x030046AC
_080D530C:
	ldr r0, _080D532C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080D531A:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _080D5330
	adds r0, #4
	b _080D533C
	.align 2, 0
_080D532C: .4byte 0x030046A4
_080D5330:
	ldr r0, _080D5380 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080D533C:
	ldrh r0, [r0, #2]
	bl PlayerLink_IsFrozenLava
	cmp r0, #0
	beq _080D534C
	movs r0, #0
	strh r0, [r5, #0x34]
	strh r0, [r5, #0x38]
_080D534C:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x2c
	bl Player_GetAnimIdx
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl PlayerLink_PlayAnim
	cmp r0, #0
	beq _080D53D8
	movs r2, #0xd6
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r0, #0
	strh r0, [r1]
	adds r0, r5, #0
	movs r1, #0x1b
	movs r2, #3
	bl PlayerLink_SetAction
	b _080D53D8
	.align 2, 0
_080D5380: .4byte 0x030046A4
_080D5384:
	ldr r4, _080D53A4 @ =0x0000037E
	adds r1, r5, r4
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _080D53D8
	adds r0, r5, #0
	movs r1, #0x1b
	movs r2, #4
	bl PlayerLink_SetAction
	b _080D53D8
	.align 2, 0
_080D53A4: .4byte 0x0000037E
_080D53A8:
	ldr r0, _080D53E0 @ =0x0000037E
	adds r4, r5, r0
	ldrh r0, [r4]
	movs r1, #7
	adds r2, r1, #0
	ands r2, r0
	lsrs r0, r0, #3
	subs r1, r1, r0
	cmp r2, r1
	blt _080D53C4
	adds r0, r5, #0
	movs r1, #5
	bl FUN_080cc3c4
_080D53C4:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x37
	bls _080D53D8
	adds r0, r5, #0
	bl FUN_080d05e8
_080D53D8:
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D53E0: .4byte 0x0000037E
