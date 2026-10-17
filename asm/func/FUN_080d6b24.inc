	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r0, #0x80
	lsls r0, r0, #7
	ldr r1, [r5, #0x20]
	orrs r1, r0
	str r1, [r5, #0x20]
	ldr r0, [r5, #0x1c]
	cmp r0, #2
	bne _080D6B3C
	b _080D6E7C
_080D6B3C:
	cmp r0, #2
	bhi _080D6B46
	cmp r0, #1
	beq _080D6B4E
	b _080D6E98
_080D6B46:
	cmp r0, #8
	bne _080D6B4C
	b _080D6E38
_080D6B4C:
	b _080D6E98
_080D6B4E:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #1
	bne _080D6B82
	movs r0, #0x10
	ands r1, r0
	cmp r1, #0
	beq _080D6B82
	ldr r1, [r5, #0x18]
	ldr r0, _080D6B70 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _080D6B74
	movs r0, #0
	b _080D6B7A
	.align 2, 0
_080D6B70: .4byte 0x03002C68
_080D6B74:
	adds r0, #0x60
	adds r0, r0, r1
	ldrb r0, [r0]
_080D6B7A:
	adds r1, r0, #0
	adds r0, r5, #0
	bl FUN_080d0394
_080D6B82:
	adds r0, r5, #0
	bl FUN_080d6600
	adds r0, r5, #0
	bl FUN_080d6804
	adds r4, r0, #0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_080cfaa4
	ldr r1, _080D6C94 @ =0x085AD184
	lsls r0, r4, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	movs r4, #0xe9
	lsls r4, r4, #2
	adds r0, r5, r4
	ldrb r0, [r0]
	cmp r0, #0
	beq _080D6BC0
	movs r1, #0xea
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r5, #0x34]
	str r1, [r5, #0x38]
_080D6BC0:
	adds r0, r5, #0
	bl FUN_080d69dc
	ldr r2, _080D6C98 @ =0x000003CE
	adds r0, r5, r2
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r0, #0
	beq _080D6BD8
	adds r0, r5, #0
	bl FUN_080cfb20
_080D6BD8:
	adds r0, r5, #0
	bl FUN_080cfcb0
	adds r0, r5, #0
	bl FUN_080d01c8
	ldr r1, _080D6C9C @ =0x00000446
	adds r0, r5, r1
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _080D6BFC
	ldr r2, _080D6CA0 @ =0x00000442
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #5
	bne _080D6BFC
	movs r1, #1
_080D6BFC:
	cmp r1, #0
	beq _080D6C02
	b _080D6E98
_080D6C02:
	movs r4, #0
	movs r1, #0xe5
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	bl FUN_080cfc78
	cmp r0, #0
	bne _080D6C40
	movs r2, #0xdf
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r2, [r0]
	cmp r2, #1
	bne _080D6C40
	movs r1, #0xde
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _080D6C40
	movs r4, #0xba
	lsls r4, r4, #2
	adds r0, r5, r4
	ldrb r1, [r0]
	ands r1, r2
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r4, r0, #0x1f
_080D6C40:
	cmp r4, #0
	bne _080D6C46
	b _080D6E2C
_080D6C46:
	ldr r0, _080D6CA4 @ =0x000003BE
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	beq _080D6C5A
	b _080D6E98
_080D6C5A:
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp]
	str r1, [sp, #4]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _080D6CA8 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	movs r0, #0x32
	muls r0, r1, r0
	adds r4, r2, #0
	cmp r0, #0
	blt _080D6CAC
	asrs r2, r0, #0xc
	b _080D6CB2
	.align 2, 0
_080D6C94: .4byte 0x085AD184
_080D6C98: .4byte 0x000003CE
_080D6C9C: .4byte 0x00000446
_080D6CA0: .4byte 0x00000442
_080D6CA4: .4byte 0x000003BE
_080D6CA8: .4byte gSineTable
_080D6CAC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080D6CB2:
	mov r0, sp
	ldrh r1, [r0]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080D6CDC @ =0xFFFF0000
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	lsls r0, r3, #1
	adds r0, r0, r4
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x32
	muls r0, r1, r0
	cmp r0, #0
	blt _080D6CE0
	asrs r2, r0, #0xc
	b _080D6CE6
	.align 2, 0
_080D6CDC: .4byte 0xFFFF0000
_080D6CE0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080D6CE6:
	mov r0, sp
	ldrh r1, [r0, #4]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080D6D28 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
	mov r6, sp
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080D6D22
	cmp r1, #0
	blt _080D6D22
	ldr r0, _080D6D2C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080D6D22
	ldr r0, _080D6D30 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080D6D34
_080D6D22:
	movs r4, #0
	b _080D6D42
	.align 2, 0
_080D6D28: .4byte 0xFFFF0000
_080D6D2C: .4byte 0x030046A8
_080D6D30: .4byte 0x030046AC
_080D6D34:
	ldr r0, _080D6D54 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080D6D42:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _080D6D58
	adds r0, #4
	b _080D6D64
	.align 2, 0
_080D6D54: .4byte 0x030046A4
_080D6D58:
	ldr r0, _080D6D78 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080D6D64:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080D6D7C
	cmp r2, #2
	beq _080D6D80
	b _080D6D84
	.align 2, 0
_080D6D78: .4byte 0x030046A4
_080D6D7C:
	ldrb r0, [r6, #4]
	b _080D6D82
_080D6D80:
	ldrb r0, [r6]
_080D6D82:
	subs r1, r1, r0
_080D6D84:
	movs r4, #0x2e
	ldrsh r0, [r5, r4]
	adds r0, #0xc8
	cmp r1, r0
	bhs _080D6D90
	b _080D6E98
_080D6D90:
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080D6DB8
	cmp r1, #0
	blt _080D6DB8
	ldr r0, _080D6DBC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080D6DB8
	ldr r0, _080D6DC0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080D6DC4
_080D6DB8:
	movs r4, #0
	b _080D6DD2
	.align 2, 0
_080D6DBC: .4byte 0x030046A8
_080D6DC0: .4byte 0x030046AC
_080D6DC4:
	ldr r0, _080D6DE4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080D6DD2:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _080D6DE8
	adds r0, #4
	b _080D6DF4
	.align 2, 0
_080D6DE4: .4byte 0x030046A4
_080D6DE8:
	ldr r0, _080D6E24 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080D6DF4:
	ldrh r2, [r0, #2]
	movs r3, #4
	ands r2, r3
	cmp r2, #0
	bne _080D6E98
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r1, [r0]
	ldr r4, _080D6E28 @ =0x000003BD
	adds r0, r5, r4
	strb r1, [r0]
	movs r1, #0xef
	lsls r1, r1, #2
	adds r0, r5, r1
	strb r2, [r0]
	subs r4, #0x41
	adds r0, r5, r4
	strb r3, [r0]
	subs r1, #0x3f
	adds r0, r5, r1
	strb r2, [r0]
	b _080D6E98
	.align 2, 0
_080D6E24: .4byte 0x030046A4
_080D6E28: .4byte 0x000003BD
_080D6E2C:
	ldr r2, _080D6E34 @ =0x000003BE
	adds r0, r5, r2
	strh r4, [r0]
	b _080D6E98
	.align 2, 0
_080D6E34: .4byte 0x000003BE
_080D6E38:
	adds r0, r5, #0
	movs r1, #8
	bl FUN_080cc3c4
	movs r4, #0xdf
	lsls r4, r4, #2
	adds r1, r5, r4
	ldrb r0, [r1]
	cmp r0, #0x1c
	bne _080D6E50
	adds r4, r0, #0
	b _080D6E5E
_080D6E50:
	ldr r1, _080D6E74 @ =0x000003D2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r4, #0x1a
	cmp r0, #0
	beq _080D6E5E
	movs r4, #0x1b
_080D6E5E:
	ldr r0, _080D6E78 @ =0x085AD184
	lsls r1, r4, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r5, #0
	bl _call_via_r1
	adds r0, r5, #0
	bl FUN_080d69dc
	b _080D6E98
	.align 2, 0
_080D6E74: .4byte 0x000003D2
_080D6E78: .4byte 0x085AD184
_080D6E7C:
	adds r0, r5, #0
	movs r1, #8
	bl FUN_080cc3c4
	movs r2, #0x93
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r0, r5, #0
	bl FUN_080d69dc
_080D6E98:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
