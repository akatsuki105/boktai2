	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x34
	adds r6, r0, #0
	str r1, [sp, #0x2c]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	str r0, [sp, #0x30]
	ldr r0, [r6, #0x44]
	adds r0, #0x48
	mov r8, r0
	ldr r2, _081A37C0 @ =0x0000046D
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A37C4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081A37C6
	.align 2, 0
_081A37C0: .4byte 0x0000046D
_081A37C4:
	movs r0, #0
_081A37C6:
	cmp r0, #0
	beq _081A37FE
	ldr r0, _081A383C @ =0x03002BE0
	ldr r0, [r0]
	movs r3, #0x80
	lsls r3, r3, #3
	adds r0, r0, r3
	ldrb r1, [r0]
	ldr r4, [sp, #0x30]
	movs r7, #0xce
	lsls r7, r7, #3
	adds r0, r4, r7
	strb r1, [r0]
	adds r2, r6, #0
	adds r2, #0xde
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	ldr r1, _081A3840 @ =0x0000FFF7
	ands r0, r1
	strh r0, [r2]
	movs r0, #0x80
	lsls r0, r0, #4
	ldr r1, _081A3844 @ =0x00000474
	adds r2, r6, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081A37FE:
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r6, r2
	ldr r0, [r0]
	mov sb, r0
	mov r4, sp
	adds r4, #0x15
	adds r0, r6, #0
	add r1, sp, #0x14
	adds r2, r4, #0
	bl Enemy_SetAnimFacing
	mov r3, sb
	ldrb r0, [r3, #4]
	mov sl, r4
	cmp r0, #3
	bhi _081A384E
	mov r4, r8
	ldrh r0, [r4, #0xe]
	adds r0, #1
	ldrb r7, [r4, #7]
	cmp r0, r7
	blt _081A3848
	ldrh r0, [r4, #8]
	adds r0, #1
	ldrb r1, [r4, #5]
	cmp r0, r1
	blt _081A3852
	movs r0, #0
	b _081A3852
	.align 2, 0
_081A383C: .4byte 0x03002BE0
_081A3840: .4byte 0x0000FFF7
_081A3844: .4byte 0x00000474
_081A3848:
	mov r2, r8
	ldrh r0, [r2, #8]
	b _081A3852
_081A384E:
	mov r3, r8
	ldrh r0, [r3, #8]
_081A3852:
	ldr r4, _081A3918 @ =0x085ADE10
	lsls r3, r0, #3
	mov r7, sl
	ldrb r1, [r7]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r3, r0
	adds r0, r0, r4
	ldrh r0, [r0]
	ldrh r1, [r6, #8]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r5, _081A391C @ =0xFFFF0000
	ldr r2, [sp, #0x1c]
	ands r2, r5
	orrs r2, r0
	str r2, [sp, #0x1c]
	ldrb r1, [r7]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r3, r0
	adds r0, r0, r4
	ldrh r1, [r0, #2]
	ldrh r0, [r6, #0xa]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r0, _081A3920 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x1c]
	ldrb r1, [r7]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r3, r3, r0
	adds r3, r3, r4
	ldrh r1, [r3, #4]
	ldrh r2, [r6, #0xc]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	add r4, sp, #0x1c
	ldr r0, [r4, #4]
	ands r0, r5
	orrs r0, r1
	str r0, [r4, #4]
	mov r3, sb
	ldrb r0, [r3, #4]
	cmp r0, #4
	beq _081A38BE
	b _081A3A94
_081A38BE:
	ldr r0, [r6, #0x44]
	movs r1, #0
	mov sl, r1
	movs r1, #2
	strb r1, [r0, #7]
	ldr r5, [r3, #0x38]
	ldrb r0, [r7]
	str r0, [sp]
	mov r2, sl
	str r2, [sp, #4]
	adds r0, r5, #0
	movs r1, #0
	adds r2, r4, #0
	movs r3, #0
	bl Enemy_OnCrushed
	ldr r3, [sp, #0x2c]
	cmp r3, #0x8c
	bgt _081A38E6
	b _081A3C84
_081A38E6:
	movs r4, #0xc2
	lsls r4, r4, #1
	adds r2, r5, r4
	ldrh r1, [r2]
	movs r7, #0x8b
	lsls r7, r7, #1
	adds r0, r5, r7
	strh r1, [r0]
	ldr r3, _081A3924 @ =0x0000048A
	adds r0, r5, r3
	strh r1, [r0]
	mov r4, sl
	strh r4, [r2]
	add r7, sp, #0x18
	mov r8, r7
	ldr r0, _081A3928 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081A392C
	movs r0, #1
	b _081A392E
	.align 2, 0
_081A3918: .4byte 0x085ADE10
_081A391C: .4byte 0xFFFF0000
_081A3920: .4byte 0x0000FFFF
_081A3924: .4byte 0x0000048A
_081A3928: .4byte 0x030047A4
_081A392C:
	movs r0, #0
_081A392E:
	cmp r0, #0
	beq _081A399C
	movs r0, #0x94
	lsls r0, r0, #3
	adds r1, r5, r0
	ldr r2, [r1]
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	bne _081A399C
	cmp r2, #0
	beq _081A399C
	ldr r0, _081A3954 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _081A3958
	movs r0, #1
	rsbs r0, r0, #0
	b _081A395C
	.align 2, 0
_081A3954: .4byte 0x03002C68
_081A3958:
	movs r2, #0x18
	ldrsh r0, [r0, r2]
_081A395C:
	cmp r0, #1
	beq _081A397E
	cmp r0, #1
	bgt _081A396A
	cmp r0, #0
	beq _081A3974
	b _081A399C
_081A396A:
	cmp r0, #2
	beq _081A3988
	cmp r0, #3
	beq _081A3992
	b _081A399C
_081A3974:
	ldr r0, [r1]
	cmp r0, #1
	beq _081A399C
	movs r0, #0
	b _081A399E
_081A397E:
	ldr r0, [r1]
	cmp r0, #2
	beq _081A399C
	movs r0, #0
	b _081A399E
_081A3988:
	ldr r0, [r1]
	cmp r0, #4
	beq _081A399C
	movs r0, #0
	b _081A399E
_081A3992:
	ldr r0, [r1]
	cmp r0, #8
	beq _081A399C
	movs r0, #0
	b _081A399E
_081A399C:
	movs r0, #1
_081A399E:
	cmp r0, #0
	beq _081A3A06
	ldrh r0, [r5]
	movs r3, #0xc2
	lsls r3, r3, #1
	adds r1, r5, r3
	movs r4, #0
	ldrsh r1, [r1, r4]
	movs r7, #0x95
	lsls r7, r7, #2
	adds r2, r5, r7
	ldrh r2, [r2]
	ldr r4, _081A3A70 @ =0x0000025A
	adds r3, r5, r4
	ldrh r3, [r3]
	movs r4, #0
	str r4, [sp]
	bl HUD_ShowEnemyGauge
	add r7, sp, #0x24
	mov r0, r8
	str r4, [r0]
	add r0, sp, #0x18
	adds r1, r7, #0
	ldr r2, _081A3A74 @ =0x05000002
	bl CpuSet
	ldr r1, _081A3A78 @ =0x0000048A
	adds r2, r5, r1
	ldrh r0, [r2]
	cmp r0, #0
	bne _081A39F0
	movs r3, #0x93
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	bne _081A3A06
_081A39F0:
	adds r0, r5, #0
	adds r0, #0xd8
	ldrh r1, [r2]
	adds r3, r5, #0
	adds r3, #8
	str r7, [sp]
	movs r2, #1
	str r2, [sp, #4]
	movs r2, #0
	bl CreateDamageNumber
_081A3A06:
	movs r1, #3
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r5, r4
	movs r2, #0
	strb r1, [r0]
	ldr r7, _081A3A7C @ =0x00000469
	adds r0, r5, r7
	strb r2, [r0]
	ldr r1, _081A3A80 @ =0x0000046A
	adds r0, r5, r1
	strb r2, [r0]
	ldr r3, _081A3A84 @ =0x00000484
	adds r0, r5, r3
	str r2, [r0]
	adds r4, #4
	adds r0, r5, r4
	movs r3, #1
	strb r3, [r0]
	ldr r7, _081A3A88 @ =0x000005DC
	adds r0, r6, r7
	ldr r4, [r0]
	movs r1, #0x1e
	ldr r7, _081A3A8C @ =0x0000046D
	adds r0, r5, r7
	strb r3, [r0]
	subs r7, #2
	adds r0, r5, r7
	strb r2, [r0]
	adds r7, #0xe8
	adds r0, r5, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r5, r4
	strh r2, [r0]
	ldr r7, [sp, #0x30]
	movs r0, #0xcc
	lsls r0, r0, #3
	adds r2, r7, r0
	movs r1, #3
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r1, _081A3A90 @ =0x0000046B
	adds r0, r6, r1
	strb r3, [r0]
	b _081A3CB0
	.align 2, 0
_081A3A70: .4byte 0x0000025A
_081A3A74: .4byte 0x05000002
_081A3A78: .4byte 0x0000048A
_081A3A7C: .4byte 0x00000469
_081A3A80: .4byte 0x0000046A
_081A3A84: .4byte 0x00000484
_081A3A88: .4byte 0x000005DC
_081A3A8C: .4byte 0x0000046D
_081A3A90: .4byte 0x0000046B
_081A3A94:
	cmp r0, #3
	bls _081A3A9A
	b _081A3C84
_081A3A9A:
	ldr r1, [r6, #0x44]
	movs r5, #0
	movs r0, #1
	strb r0, [r1, #7]
	mov r2, sb
	ldr r2, [r2, #0x38]
	mov sb, r2
	ldr r3, [sp, #0x30]
	ldr r7, _081A3ACC @ =0x00000672
	adds r0, r3, r7
	ldrb r1, [r0]
	ldr r0, [sp, #0x2c]
	bl Mod
	cmp r0, #0
	beq _081A3ABC
	b _081A3C64
_081A3ABC:
	movs r0, #0xd9
	lsls r0, r0, #2
	add r0, sb
	ldrh r0, [r0]
	cmp r0, #0
	bne _081A3AD0
	movs r0, #1
	b _081A3AD2
	.align 2, 0
_081A3ACC: .4byte 0x00000672
_081A3AD0:
	movs r0, #0
_081A3AD2:
	cmp r0, #0
	bne _081A3B10
	ldr r1, [sp, #0x30]
	movs r2, #0xce
	lsls r2, r2, #3
	adds r0, r1, r2
	ldrb r2, [r0]
	ldr r0, _081A3AF8 @ =0x03002BE0
	ldr r0, [r0]
	movs r3, #0x80
	lsls r3, r3, #3
	adds r0, r0, r3
	ldrb r1, [r0]
	cmp r1, r2
	bge _081A3B00
	ldr r4, _081A3AFC @ =0xFFFFFF00
	adds r0, r2, r4
	subs r1, r1, r0
	b _081A3B02
	.align 2, 0
_081A3AF8: .4byte 0x03002BE0
_081A3AFC: .4byte 0xFFFFFF00
_081A3B00:
	subs r1, r1, r2
_081A3B02:
	ldr r7, [sp, #0x30]
	ldr r2, _081A3B24 @ =0x00000671
	adds r0, r7, r2
	ldrb r0, [r0]
	cmp r1, r0
	bgt _081A3B10
	b _081A3C2C
_081A3B10:
	add r2, sp, #0x14
	ldrb r0, [r6, #5]
	adds r1, r0, #0
	adds r1, #0x20
	movs r0, #0xff
	ands r1, r0
	cmp r1, #0
	blt _081A3B28
	asrs r0, r1, #6
	b _081A3B2E
	.align 2, 0
_081A3B24: .4byte 0x00000671
_081A3B28:
	rsbs r0, r1, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_081A3B2E:
	lsls r0, r0, #6
	strb r0, [r2]
	ldr r3, _081A3B78 @ =0x00000256
	adds r0, r6, r3
	ldrh r5, [r0]
	add r4, sp, #0x1c
	mov sl, r4
	ldr r7, _081A3B7C @ =0x030046A4
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	add r0, sp, #0x1c
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081A3B80
	adds r0, #4
	b _081A3B8A
	.align 2, 0
_081A3B78: .4byte 0x00000256
_081A3B7C: .4byte 0x030046A4
_081A3B80:
	ldr r0, [r7]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081A3B8A:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	movs r5, #0
	movs r4, #0
	mov r7, sl
	strh r0, [r7, #2]
	mov r1, r8
	lsls r0, r1, #8
	adds r0, #0x80
	strh r0, [r7, #4]
	add r0, sp, #0x14
	ldrb r3, [r0]
	movs r0, #0x3c
	str r0, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	mov r0, sb
	add r1, sp, #0x1c
	movs r2, #0x40
	bl Player_ReleaseGrabbed
	ldr r3, [sp, #0x30]
	movs r7, #0xcc
	lsls r7, r7, #3
	adds r2, r3, r7
	movs r1, #3
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r1, #2
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r6, r2
	strb r5, [r0]
	ldr r3, _081A3C18 @ =0x00000469
	adds r0, r6, r3
	strb r5, [r0]
	ldr r7, _081A3C1C @ =0x0000046A
	adds r0, r6, r7
	strb r1, [r0]
	ldr r1, _081A3C20 @ =0x00000484
	adds r0, r6, r1
	str r4, [r0]
	adds r2, #4
	adds r0, r6, r2
	movs r1, #1
	strb r1, [r0]
	ldr r3, _081A3C24 @ =DarkRoot_StateWait
	movs r2, #0x21
	adds r7, #3
	adds r0, r6, r7
	strb r1, [r0]
	ldr r1, _081A3C28 @ =0x0000046B
	adds r0, r6, r1
	strb r5, [r0]
	adds r7, #0xe6
	adds r0, r6, r7
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r4, [r0]
	b _081A3CB0
	.align 2, 0
_081A3C18: .4byte 0x00000469
_081A3C1C: .4byte 0x0000046A
_081A3C20: .4byte 0x00000484
_081A3C24: .4byte DarkRoot_StateWait
_081A3C28: .4byte 0x0000046B
_081A3C2C:
	adds r0, r6, #0
	bl DarkRoot_GetGrabbedAnimOffset
	adds r3, r0, #0
	mov r4, sl
	ldrb r0, [r4]
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	str r0, [sp, #8]
	ldr r7, _081A3C60 @ =0x00000226
	adds r0, r6, r7
	ldrh r0, [r0]
	str r0, [sp, #0xc]
	movs r1, #0x90
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r0, [r0]
	str r0, [sp, #0x10]
	mov r0, sb
	add r1, sp, #0x1c
	movs r2, #0
	bl Player_HoldGrabbed
	b _081A3C84
	.align 2, 0
_081A3C60: .4byte 0x00000226
_081A3C64:
	adds r0, r6, #0
	bl DarkRoot_GetGrabbedAnimOffset
	adds r3, r0, #0
	mov r2, sl
	ldrb r0, [r2]
	str r0, [sp]
	str r5, [sp, #4]
	str r5, [sp, #8]
	str r5, [sp, #0xc]
	str r5, [sp, #0x10]
	mov r0, sb
	adds r1, r4, #0
	movs r2, #0
	bl Player_HoldGrabbed
_081A3C84:
	adds r0, r6, #0
	movs r1, #0x12
	bl Enemy_PlayAnimFlipOnly
	mov r3, r8
	ldrh r0, [r3, #8]
	cmp r0, #0
	bne _081A3CA2
	ldrh r0, [r3, #0xe]
	cmp r0, #0
	bne _081A3CA2
	movs r0, #0xef
	lsls r0, r0, #1
	bl PlaySound_082406e0
_081A3CA2:
	ldr r4, [sp, #0x2c]
	cmp r4, #0xb4
	ble _081A3CB0
	ldr r7, _081A3CC0 @ =0x0000046B
	adds r1, r6, r7
	movs r0, #1
	strb r0, [r1]
_081A3CB0:
	add sp, #0x34
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081A3CC0: .4byte 0x0000046B
