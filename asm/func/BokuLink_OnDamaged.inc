	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x104
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r5, [r0]
	movs r2, #0x93
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	bne _081B3FFE
	ldr r3, _081B3FF0 @ =0x0000048A
	adds r0, r7, r3
	ldrh r0, [r0]
	cmp r0, #0
	bne _081B3FF8
	ldr r0, _081B3FF4 @ =0x00000211
	bl PlaySound_082406e0
	b _081B3FFE
	.align 2, 0
_081B3FF0: .4byte 0x0000048A
_081B3FF4: .4byte 0x00000211
_081B3FF8:
	movs r0, #0xd4
	bl PlaySound_082406e0
_081B3FFE:
	adds r0, r7, #0
	bl BokuLink_UpdateDelayedScript
	movs r0, #0x80
	lsls r0, r0, #6
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r1, r7, r4
	ldrh r3, [r1]
	adds r2, r3, #0
	ands r0, r2
	str r1, [sp, #0xf4]
	cmp r0, #0
	bne _081B401C
	b _081B4714
_081B401C:
	ldr r5, _081B40AC @ =0x000001DD
	adds r0, r7, r5
	ldrb r0, [r0]
	adds r0, #0x80
	movs r4, #0
	strb r0, [r7, #5]
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_PlayAnim
	ldr r0, _081B40B0 @ =0xFFFFDFDF
	ldr r6, [sp, #0xf4]
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	ldr r0, _081B40B4 @ =0x00000544
	adds r1, r7, r0
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r1]
	movs r2, #0x10
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r7, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r5, #0x95
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r0, [r0]
	strh r4, [r0, #6]
	adds r0, r7, #0
	bl Enemy_TargetNearestLinkPlayer
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081B406A
	b _081B4726
_081B406A:
	movs r6, #0x95
	lsls r6, r6, #3
	adds r3, r7, r6
	ldr r5, [r3]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r4, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r3, [sp, #0xd4]
	str r2, [sp, #0xe0]
	cmp r4, #0
	blt _081B40A6
	cmp r1, #0
	blt _081B40A6
	ldr r0, _081B40B8 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _081B40A6
	ldr r0, _081B40BC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B40C0
_081B40A6:
	movs r4, #0
	b _081B40CE
	.align 2, 0
_081B40AC: .4byte 0x000001DD
_081B40B0: .4byte 0xFFFFDFDF
_081B40B4: .4byte 0x00000544
_081B40B8: .4byte 0x030046A8
_081B40BC: .4byte 0x030046AC
_081B40C0:
	ldr r0, _081B40E0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_081B40CE:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081B40E4
	adds r0, #4
	b _081B40F0
	.align 2, 0
_081B40E0: .4byte 0x030046A4
_081B40E4:
	ldr r0, _081B4104 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B40F0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081B4108
	cmp r2, #2
	beq _081B410C
	b _081B4110
	.align 2, 0
_081B4104: .4byte 0x030046A4
_081B4108:
	ldrb r0, [r5, #4]
	b _081B410E
_081B410C:
	ldrb r0, [r5]
_081B410E:
	subs r1, r1, r0
_081B4110:
	strh r1, [r5, #2]
	ldr r0, _081B4124 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081B4128
	movs r0, #1
	b _081B412A
	.align 2, 0
_081B4124: .4byte 0x030047A4
_081B4128:
	movs r0, #0
_081B412A:
	cmp r0, #0
	beq _081B4168
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _081B414A
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081B4146
	adds r2, r0, #0
_081B4146:
	cmp r2, #0
	bge _081B4154
_081B414A:
	ldr r2, _081B4150 @ =0x000005C4
	adds r0, r7, r2
	b _081B4680
	.align 2, 0
_081B4150: .4byte 0x000005C4
_081B4154:
	ldr r1, _081B4164 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _081B41B0
	.align 2, 0
_081B4164: .4byte 0x03002BE0
_081B4168:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081B4194
	cmp r1, #0
	blt _081B4194
	ldr r0, _081B4198 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081B4194
	ldr r0, _081B419C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B41A0
_081B4194:
	movs r5, #0
	b _081B41AE
	.align 2, 0
_081B4198: .4byte 0x030046A8
_081B419C: .4byte 0x030046AC
_081B41A0:
	ldr r0, _081B41E8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081B41AE:
	movs r2, #0
_081B41B0:
	ldr r4, _081B41EC @ =0x00000256
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _081B41D0
	ldr r1, _081B41F0 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081B41D0
	b _081B45C0
_081B41D0:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r5, [sp, #0xf4]
	ldrh r0, [r5]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x18]
	cmp r0, #0
	beq _081B41F4
	movs r0, #0
	b _081B4696
	.align 2, 0
_081B41E8: .4byte 0x030046A4
_081B41EC: .4byte 0x00000256
_081B41F0: .4byte 0x03002BE0
_081B41F4:
	ldr r6, _081B4298 @ =0x00000222
	adds r2, r7, r6
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r3, [sp, #0xf4]
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	str r2, [sp, #0xfc]
	cmp r6, #0
	beq _081B42AC
	movs r4, #0xb7
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r5, _081B429C @ =0x0000046D
	adds r5, r7, r5
	str r5, [sp, #0x1c]
	movs r6, #1
	strb r6, [r5]
	ldr r2, _081B42A0 @ =0x0000046B
	adds r2, r7, r2
	str r2, [sp, #0x20]
	movs r3, #0
	strb r3, [r2]
	subs r4, #0x65
	adds r4, r7, r4
	str r4, [sp, #0x24]
	strb r0, [r4]
	movs r5, #0xaf
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x28]
	str r1, [r5]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r5, r7, r6
	mov r0, sp
	ldrh r0, [r0, #0x18]
	strh r0, [r5]
	movs r0, #0xc
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r4, r7, r1
	strb r3, [r4]
	ldr r2, _081B42A4 @ =0x00000469
	adds r3, r7, r2
	movs r6, #0
	strb r6, [r3]
	adds r1, #2
	adds r2, r7, r1
	strb r0, [r2]
	ldr r6, _081B42A8 @ =0x00000484
	adds r1, r7, r6
	ldr r0, [sp, #0x18]
	str r0, [r1]
	subs r6, #0x18
	adds r0, r7, r6
	movs r6, #1
	strb r6, [r0]
	ldr r6, [sp, #0x1c]
	str r6, [sp, #0xcc]
	ldr r6, [sp, #0x20]
	str r6, [sp, #0xc4]
	ldr r6, [sp, #0x24]
	str r6, [sp, #0xe8]
	ldr r6, [sp, #0x28]
	str r6, [sp, #0xec]
	str r5, [sp, #0xf8]
	str r4, [sp, #0xb8]
	str r3, [sp, #0xbc]
	str r2, [sp, #0xc0]
	str r1, [sp, #0xd0]
	str r0, [sp, #0xc8]
	b _081B447E
	.align 2, 0
_081B4298: .4byte 0x00000222
_081B429C: .4byte 0x0000046D
_081B42A0: .4byte 0x0000046B
_081B42A4: .4byte 0x00000469
_081B42A8: .4byte 0x00000484
_081B42AC:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, _081B4370 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x2c]
	strb r0, [r2]
	ldr r3, _081B4374 @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x30]
	movs r4, #0
	strb r4, [r3]
	ldr r5, _081B4378 @ =0x00000553
	adds r5, r7, r5
	str r5, [sp, #0x34]
	strb r0, [r5]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x38]
	str r1, [r2]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x3c]
	strh r6, [r3]
	movs r1, #5
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x40]
	movs r5, #0
	strb r5, [r4]
	ldr r2, _081B437C @ =0x00000469
	adds r5, r7, r2
	movs r3, #0
	strb r3, [r5]
	adds r2, #1
	adds r4, r7, r2
	strb r1, [r4]
	ldr r1, _081B4380 @ =0x00000484
	adds r3, r7, r1
	str r6, [r3]
	ldr r6, _081B4384 @ =0x0000046C
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0xd4]
	ldr r0, [r0]
	str r0, [sp, #0x44]
	ldr r1, [sp, #0xe0]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x44]
	strh r1, [r6]
	ldr r6, [sp, #0xe0]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x44]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov sb, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x2c]
	str r0, [sp, #0xcc]
	ldr r6, [sp, #0x30]
	str r6, [sp, #0xc4]
	ldr r0, [sp, #0x34]
	str r0, [sp, #0xe8]
	ldr r6, [sp, #0x38]
	str r6, [sp, #0xec]
	ldr r0, [sp, #0x3c]
	str r0, [sp, #0xf8]
	ldr r6, [sp, #0x40]
	str r6, [sp, #0xb8]
	str r5, [sp, #0xbc]
	str r4, [sp, #0xc0]
	str r3, [sp, #0xd0]
	str r2, [sp, #0xc8]
	mov r0, sb
	cmp r0, #0
	blt _081B436A
	cmp r1, #0
	blt _081B436A
	ldr r0, _081B4388 @ =0x030046A8
	ldr r0, [r0]
	cmp sb, r0
	bhs _081B436A
	ldr r0, _081B438C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B4390
_081B436A:
	movs r4, #0
	b _081B43A0
	.align 2, 0
_081B4370: .4byte 0x0000046D
_081B4374: .4byte 0x0000046B
_081B4378: .4byte 0x00000553
_081B437C: .4byte 0x00000469
_081B4380: .4byte 0x00000484
_081B4384: .4byte 0x0000046C
_081B4388: .4byte 0x030046A8
_081B438C: .4byte 0x030046AC
_081B4390:
	ldr r0, _081B43B0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, sb
	adds r4, r0, r1
_081B43A0:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081B43B4
	adds r0, #4
	b _081B43C0
	.align 2, 0
_081B43B0: .4byte 0x030046A4
_081B43B4:
	ldr r0, _081B43D4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B43C0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081B43D8
	cmp r2, #2
	beq _081B43DE
	b _081B43E4
	.align 2, 0
_081B43D4: .4byte 0x030046A4
_081B43D8:
	ldr r2, [sp, #0x44]
	ldrb r0, [r2, #4]
	b _081B43E2
_081B43DE:
	ldr r3, [sp, #0x44]
	ldrb r0, [r3]
_081B43E2:
	subs r1, r1, r0
_081B43E4:
	ldr r4, [sp, #0x44]
	strh r1, [r4, #2]
	ldr r5, [sp, #0xd4]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081B4410
	cmp r1, #0
	blt _081B4410
	ldr r0, _081B4414 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081B4410
	ldr r0, _081B4418 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B441C
_081B4410:
	movs r4, #0
	b _081B442A
	.align 2, 0
_081B4414: .4byte 0x030046A8
_081B4418: .4byte 0x030046AC
_081B441C:
	ldr r0, _081B4440 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081B442A:
	ldr r6, [sp, #0xd4]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081B4444
	adds r0, #4
	b _081B4450
	.align 2, 0
_081B4440: .4byte 0x030046A4
_081B4444:
	ldr r0, _081B4464 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B4450:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081B4468
	cmp r3, #2
	beq _081B446C
	b _081B4470
	.align 2, 0
_081B4464: .4byte 0x030046A4
_081B4468:
	ldrb r0, [r5, #4]
	b _081B446E
_081B446C:
	ldrb r0, [r5]
_081B446E:
	subs r2, r2, r0
_081B4470:
	ldr r1, [sp, #0xd4]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0xd4]
	ldr r0, [r2]
	strh r1, [r0, #6]
_081B447E:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x48]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0xf4]
	ldrh r0, [r4]
	ands r0, r1
	adds r4, r3, #0
	ldr r6, _081B44A8 @ =0x00000482
	adds r5, r7, r6
	cmp r0, #0
	bne _081B4588
	movs r1, #4
	ldr r2, [sp, #0xfc]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081B44AC
	movs r0, #1
	b _081B44AE
	.align 2, 0
_081B44A8: .4byte 0x00000482
_081B44AC:
	movs r0, #0
_081B44AE:
	ldr r3, _081B4598 @ =0x00000482
	adds r5, r7, r3
	cmp r0, #0
	bne _081B4588
	movs r3, #0
	movs r0, #0xa8
	lsls r0, r0, #3
	adds r6, r7, r0
	movs r1, #0xa9
	lsls r1, r1, #3
	adds r1, r1, r7
	mov r8, r1
	ldr r2, _081B459C @ =0x0000054F
	adds r2, r2, r7
	mov sb, r2
	adds r0, #0xc
	adds r0, r0, r7
	mov sl, r0
	ldr r1, _081B45A0 @ =0x0000054D
	adds r1, r1, r7
	mov ip, r1
	ldr r2, _081B45A4 @ =0x0000054E
	adds r2, r7, r2
	str r2, [sp, #0xe4]
	ldr r0, _081B45A8 @ =0x00000541
	adds r0, r7, r0
	str r0, [sp, #0xd8]
	ldr r1, _081B45AC @ =0x000005BC
	adds r1, r7, r1
	str r1, [sp, #0xf0]
	ldr r2, _081B45B0 @ =0x00000542
	adds r2, r7, r2
	str r2, [sp, #0xdc]
	ldr r1, _081B45B4 @ =0x030046B8
	str r4, [sp, #0x100]
_081B44F4:
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _081B45B8 @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r2, _081B45BC @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #3
	ands r0, r2
	lsls r0, r0, #6
	ldr r2, [sp, #0x100]
	cmp r0, r2
	bne _081B451A
	adds r3, #1
	cmp r3, #3
	ble _081B44F4
	adds r0, r4, #0
_081B451A:
	movs r3, #0
	strb r0, [r6]
	ldr r4, [sp, #0xec]
	ldr r0, [r4]
	mov r6, r8
	str r0, [r6]
	ldr r1, [sp, #0xe8]
	ldrb r0, [r1]
	mov r2, sb
	strb r0, [r2]
	ldr r4, [sp, #0xb8]
	ldrb r0, [r4]
	mov r6, sl
	strb r0, [r6]
	ldr r1, [sp, #0xbc]
	ldrb r0, [r1]
	mov r2, ip
	strb r0, [r2]
	ldr r4, [sp, #0xc0]
	ldrb r0, [r4]
	ldr r6, [sp, #0xe4]
	strb r0, [r6]
	add r0, sp, #0x48
	ldrb r1, [r0]
	ldr r0, [sp, #0xd8]
	strb r1, [r0]
	ldr r1, [sp, #0xf0]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0xcc]
	strb r1, [r4]
	ldr r6, [sp, #0xc4]
	strb r3, [r6]
	ldr r4, [sp, #0xe8]
	strb r0, [r4]
	ldr r6, [sp, #0xec]
	str r2, [r6]
	movs r2, #0
	ldr r0, [sp, #0xf8]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0xb8]
	strb r0, [r4]
	ldr r6, [sp, #0xbc]
	strb r1, [r6]
	ldr r0, [sp, #0xc0]
	strb r2, [r0]
	ldr r2, [sp, #0xd0]
	str r3, [r2]
	ldr r3, [sp, #0xc8]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0xdc]
	strb r0, [r4]
_081B4588:
	adds r0, r7, #0
	bl Enemy_StepToFloorEdge
	movs r0, #2
	strh r0, [r5]
	movs r0, #0
	b _081B4696
	.align 2, 0
_081B4598: .4byte 0x00000482
_081B459C: .4byte 0x0000054F
_081B45A0: .4byte 0x0000054D
_081B45A4: .4byte 0x0000054E
_081B45A8: .4byte 0x00000541
_081B45AC: .4byte 0x000005BC
_081B45B0: .4byte 0x00000542
_081B45B4: .4byte 0x030046B8
_081B45B8: .4byte 0x000003FF
_081B45BC: .4byte 0x0203B400
_081B45C0:
	mov sb, sp
	ldr r6, _081B45FC @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081B4600
	adds r0, #4
	b _081B460A
	.align 2, 0
_081B45FC: .4byte 0x030046A4
_081B4600:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081B460A:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r4, sb
	strh r0, [r4, #2]
	mov r5, r8
	lsls r0, r5, #8
	adds r0, #0x80
	strh r0, [r4, #4]
	ldr r6, _081B4644 @ =0x000004A4
	adds r0, r7, r6
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081B464C
	ldr r0, _081B4648 @ =0xFFFFFDFF
	ldr r2, [sp, #0xf4]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081B4676
	.align 2, 0
_081B4644: .4byte 0x000004A4
_081B4648: .4byte 0xFFFFFDFF
_081B464C:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081B466C
	cmp r0, #2
	beq _081B4668
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081B4668:
	movs r0, #1
	b _081B4678
_081B466C:
	ldr r0, _081B468C @ =0xFFFFFDFF
	ldr r3, [sp, #0xf4]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081B4676:
	movs r0, #0
_081B4678:
	cmp r0, #0
	bne _081B4694
	ldr r4, _081B4690 @ =0x000005C4
	adds r0, r7, r4
_081B4680:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _081B4696
	.align 2, 0
_081B468C: .4byte 0xFFFFFDFF
_081B4690: .4byte 0x000005C4
_081B4694:
	movs r0, #1
_081B4696:
	cmp r0, #0
	beq _081B469E
	bl _081B568C
_081B469E:
	ldr r5, _081B46D0 @ =0x000004A4
	adds r0, r7, r5
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081B46D8
	ldr r0, _081B46D4 @ =0xFFFFFDFF
	ldr r2, [sp, #0xf4]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081B4702
	.align 2, 0
_081B46D0: .4byte 0x000004A4
_081B46D4: .4byte 0xFFFFFDFF
_081B46D8:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081B46F8
	cmp r0, #2
	beq _081B46F4
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081B46F4:
	movs r0, #1
	b _081B4704
_081B46F8:
	ldr r0, _081B4710 @ =0xFFFFFDFF
	ldr r3, [sp, #0xf4]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081B4702:
	movs r0, #0
_081B4704:
	cmp r0, #0
	bne _081B470C
	bl _081B5674
_081B470C:
	bl _081B568C
	.align 2, 0
_081B4710: .4byte 0xFFFFFDFF
_081B4714:
	ldr r4, _081B472C @ =0x00008002
	ands r4, r2
	cmp r4, #0
	beq _081B4730
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r3
	ldr r1, [sp, #0xf4]
	strh r0, [r1]
_081B4726:
	movs r0, #0
	bl _081B56E6
	.align 2, 0
_081B472C: .4byte 0x00008002
_081B4730:
	ldr r2, _081B47A0 @ =0x0000049C
	adds r0, r7, r2
	ldr r0, [r0]
	movs r1, #0xc0
	lsls r1, r1, #0xc
	ands r0, r1
	cmp r0, #0
	beq _081B47C4
	ldr r3, _081B47A4 @ =0x000005CC
	adds r0, r7, r3
	ldr r2, [r0]
	movs r1, #0x12
	ldr r5, _081B47A8 @ =0x0000046D
	adds r0, r7, r5
	movs r3, #1
	strb r3, [r0]
	ldr r6, _081B47AC @ =0x0000046B
	adds r0, r7, r6
	strb r4, [r0]
	adds r5, #0xe6
	adds r0, r7, r5
	strb r1, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r7, r6
	str r2, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r2, #0
	strh r4, [r0]
	movs r1, #3
	subs r5, #0xeb
	adds r0, r7, r5
	strb r1, [r0]
	ldr r6, _081B47B0 @ =0x00000469
	adds r0, r7, r6
	strb r2, [r0]
	ldr r1, _081B47B4 @ =0x0000046A
	adds r0, r7, r1
	strb r2, [r0]
	ldr r2, _081B47B8 @ =0x00000484
	adds r0, r7, r2
	str r4, [r0]
	ldr r4, _081B47BC @ =0x0000046C
	adds r0, r7, r4
	strb r3, [r0]
	movs r5, #0xbe
	lsls r5, r5, #1
	adds r2, r7, r5
	ldr r1, _081B47C0 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	bl _081B56E4
	.align 2, 0
_081B47A0: .4byte 0x0000049C
_081B47A4: .4byte 0x000005CC
_081B47A8: .4byte 0x0000046D
_081B47AC: .4byte 0x0000046B
_081B47B0: .4byte 0x00000469
_081B47B4: .4byte 0x0000046A
_081B47B8: .4byte 0x00000484
_081B47BC: .4byte 0x0000046C
_081B47C0: .4byte 0xFEFFFFFF
_081B47C4:
	movs r1, #0x21
	rsbs r1, r1, #0
	ands r1, r3
	ldr r6, [sp, #0xf4]
	strh r1, [r6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	bne _081B4726
	ldr r1, _081B4878 @ =0x000004BE
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _081B4726
	ldr r3, _081B487C @ =0x0000065C
	adds r2, r5, r3
	movs r0, #2
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r4, [sp, #0xf4]
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	bne _081B47FE
	b _081B4F6C
_081B47FE:
	ldr r5, _081B4880 @ =0x0000048D
	adds r2, r7, r5
	ldrb r0, [r2]
	cmp r0, #0
	bne _081B482A
	ldr r6, _081B4884 @ =0x0000048C
	adds r0, r7, r6
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _081B482A
	ldr r1, _081B4878 @ =0x000004BE
	adds r0, r7, r1
	movs r1, #0x2d
	strh r1, [r0]
	movs r0, #0x41
	strb r0, [r2]
	adds r0, r7, #0
	movs r1, #3
	bl Enemy_PlayAnim
_081B482A:
	adds r0, r7, #0
	bl Enemy_TargetNearestLinkPlayer
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081B4838
	b _081B4726
_081B4838:
	movs r2, #0x95
	lsls r2, r2, #3
	adds r3, r7, r2
	ldr r5, [r3]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r4, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r3, [sp, #0xd4]
	str r2, [sp, #0xe0]
	cmp r4, #0
	blt _081B4874
	cmp r1, #0
	blt _081B4874
	ldr r0, _081B4888 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _081B4874
	ldr r0, _081B488C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B4890
_081B4874:
	movs r4, #0
	b _081B489E
	.align 2, 0
_081B4878: .4byte 0x000004BE
_081B487C: .4byte 0x0000065C
_081B4880: .4byte 0x0000048D
_081B4884: .4byte 0x0000048C
_081B4888: .4byte 0x030046A8
_081B488C: .4byte 0x030046AC
_081B4890:
	ldr r0, _081B48B0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_081B489E:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081B48B4
	adds r0, #4
	b _081B48C0
	.align 2, 0
_081B48B0: .4byte 0x030046A4
_081B48B4:
	ldr r0, _081B48D4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B48C0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081B48D8
	cmp r2, #2
	beq _081B48DC
	b _081B48E0
	.align 2, 0
_081B48D4: .4byte 0x030046A4
_081B48D8:
	ldrb r0, [r5, #4]
	b _081B48DE
_081B48DC:
	ldrb r0, [r5]
_081B48DE:
	subs r1, r1, r0
_081B48E0:
	strh r1, [r5, #2]
	ldr r0, _081B48F4 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081B48F8
	movs r0, #1
	b _081B48FA
	.align 2, 0
_081B48F4: .4byte 0x030047A4
_081B48F8:
	movs r0, #0
_081B48FA:
	cmp r0, #0
	beq _081B4938
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r1, [r0]
	cmp r1, #0
	beq _081B491A
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081B4916
	adds r2, r0, #0
_081B4916:
	cmp r2, #0
	bge _081B4924
_081B491A:
	ldr r4, _081B4920 @ =0x000005C4
	adds r0, r7, r4
	b _081B4E5C
	.align 2, 0
_081B4920: .4byte 0x000005C4
_081B4924:
	ldr r1, _081B4934 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _081B4980
	.align 2, 0
_081B4934: .4byte 0x03002BE0
_081B4938:
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r7, r5
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081B4964
	cmp r1, #0
	blt _081B4964
	ldr r0, _081B4968 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081B4964
	ldr r0, _081B496C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B4970
_081B4964:
	movs r5, #0
	b _081B497E
	.align 2, 0
_081B4968: .4byte 0x030046A8
_081B496C: .4byte 0x030046AC
_081B4970:
	ldr r0, _081B49B8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081B497E:
	movs r2, #0
_081B4980:
	ldr r6, _081B49BC @ =0x00000256
	adds r0, r7, r6
	ldrh r0, [r0]
	cmp r5, r0
	beq _081B49A0
	ldr r1, _081B49C0 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081B49A0
	b _081B4D98
_081B49A0:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r2, [sp, #0xf4]
	ldrh r0, [r2]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x4c]
	cmp r0, #0
	beq _081B49C4
	movs r0, #0
	b _081B4E72
	.align 2, 0
_081B49B8: .4byte 0x030046A4
_081B49BC: .4byte 0x00000256
_081B49C0: .4byte 0x03002BE0
_081B49C4:
	ldr r3, _081B4A6C @ =0x00000222
	adds r2, r7, r3
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r4, [sp, #0xf4]
	ldrh r0, [r4]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov ip, r0
	str r2, [sp, #0xfc]
	cmp r0, #0
	beq _081B4A84
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r6, _081B4A70 @ =0x0000046D
	adds r6, r7, r6
	str r6, [sp, #0x50]
	movs r2, #1
	strb r2, [r6]
	ldr r3, _081B4A74 @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x54]
	movs r4, #0
	strb r4, [r3]
	subs r5, #0x65
	adds r5, r7, r5
	str r5, [sp, #0x58]
	strb r0, [r5]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x5c]
	str r1, [r6]
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r5, r7, r0
	add r1, sp, #0x4c
	ldrh r1, [r1]
	strh r1, [r5]
	movs r0, #0xc
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r4, r7, r2
	movs r3, #0
	strb r3, [r4]
	ldr r6, _081B4A78 @ =0x00000469
	adds r3, r7, r6
	movs r1, #0
	strb r1, [r3]
	adds r6, #1
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, _081B4A7C @ =0x00000484
	adds r1, r7, r0
	ldr r6, [sp, #0x4c]
	str r6, [r1]
	ldr r6, _081B4A80 @ =0x0000046C
	adds r0, r7, r6
	movs r6, #1
	strb r6, [r0]
	ldr r6, [sp, #0x50]
	str r6, [sp, #0xcc]
	ldr r6, [sp, #0x54]
	str r6, [sp, #0xc4]
	ldr r6, [sp, #0x58]
	str r6, [sp, #0xe8]
	ldr r6, [sp, #0x5c]
	str r6, [sp, #0xec]
	str r5, [sp, #0xf8]
	str r4, [sp, #0xb8]
	str r3, [sp, #0xbc]
	str r2, [sp, #0xc0]
	str r1, [sp, #0xd0]
	str r0, [sp, #0xc8]
	b _081B4C56
	.align 2, 0
_081B4A6C: .4byte 0x00000222
_081B4A70: .4byte 0x0000046D
_081B4A74: .4byte 0x0000046B
_081B4A78: .4byte 0x00000469
_081B4A7C: .4byte 0x00000484
_081B4A80: .4byte 0x0000046C
_081B4A84:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, _081B4B48 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x60]
	strb r0, [r2]
	ldr r3, _081B4B4C @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x64]
	movs r4, #0
	strb r4, [r3]
	ldr r5, _081B4B50 @ =0x00000553
	adds r5, r7, r5
	str r5, [sp, #0x68]
	strb r0, [r5]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x6c]
	str r1, [r6]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x70]
	mov r2, ip
	strh r2, [r1]
	movs r1, #5
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x74]
	strb r4, [r3]
	ldr r4, _081B4B54 @ =0x00000469
	adds r5, r7, r4
	movs r6, #0
	strb r6, [r5]
	ldr r2, _081B4B58 @ =0x0000046A
	adds r4, r7, r2
	strb r1, [r4]
	ldr r6, _081B4B5C @ =0x00000484
	adds r3, r7, r6
	mov r1, ip
	str r1, [r3]
	subs r6, #0x18
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0xd4]
	ldr r0, [r0]
	str r0, [sp, #0x78]
	ldr r1, [sp, #0xe0]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x78]
	strh r1, [r6]
	ldr r6, [sp, #0xe0]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x78]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov r8, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x60]
	str r0, [sp, #0xcc]
	ldr r6, [sp, #0x64]
	str r6, [sp, #0xc4]
	ldr r0, [sp, #0x68]
	str r0, [sp, #0xe8]
	ldr r6, [sp, #0x6c]
	str r6, [sp, #0xec]
	ldr r0, [sp, #0x70]
	str r0, [sp, #0xf8]
	ldr r6, [sp, #0x74]
	str r6, [sp, #0xb8]
	str r5, [sp, #0xbc]
	str r4, [sp, #0xc0]
	str r3, [sp, #0xd0]
	str r2, [sp, #0xc8]
	mov r0, r8
	cmp r0, #0
	blt _081B4B44
	cmp r1, #0
	blt _081B4B44
	ldr r0, _081B4B60 @ =0x030046A8
	ldr r0, [r0]
	cmp r8, r0
	bhs _081B4B44
	ldr r0, _081B4B64 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B4B68
_081B4B44:
	movs r4, #0
	b _081B4B78
	.align 2, 0
_081B4B48: .4byte 0x0000046D
_081B4B4C: .4byte 0x0000046B
_081B4B50: .4byte 0x00000553
_081B4B54: .4byte 0x00000469
_081B4B58: .4byte 0x0000046A
_081B4B5C: .4byte 0x00000484
_081B4B60: .4byte 0x030046A8
_081B4B64: .4byte 0x030046AC
_081B4B68:
	ldr r0, _081B4B88 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, r8
	adds r4, r0, r1
_081B4B78:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081B4B8C
	adds r0, #4
	b _081B4B98
	.align 2, 0
_081B4B88: .4byte 0x030046A4
_081B4B8C:
	ldr r0, _081B4BAC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B4B98:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081B4BB0
	cmp r2, #2
	beq _081B4BB6
	b _081B4BBC
	.align 2, 0
_081B4BAC: .4byte 0x030046A4
_081B4BB0:
	ldr r2, [sp, #0x78]
	ldrb r0, [r2, #4]
	b _081B4BBA
_081B4BB6:
	ldr r3, [sp, #0x78]
	ldrb r0, [r3]
_081B4BBA:
	subs r1, r1, r0
_081B4BBC:
	ldr r4, [sp, #0x78]
	strh r1, [r4, #2]
	ldr r5, [sp, #0xd4]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081B4BE8
	cmp r1, #0
	blt _081B4BE8
	ldr r0, _081B4BEC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081B4BE8
	ldr r0, _081B4BF0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B4BF4
_081B4BE8:
	movs r4, #0
	b _081B4C02
	.align 2, 0
_081B4BEC: .4byte 0x030046A8
_081B4BF0: .4byte 0x030046AC
_081B4BF4:
	ldr r0, _081B4C18 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081B4C02:
	ldr r6, [sp, #0xd4]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081B4C1C
	adds r0, #4
	b _081B4C28
	.align 2, 0
_081B4C18: .4byte 0x030046A4
_081B4C1C:
	ldr r0, _081B4C3C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B4C28:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081B4C40
	cmp r3, #2
	beq _081B4C44
	b _081B4C48
	.align 2, 0
_081B4C3C: .4byte 0x030046A4
_081B4C40:
	ldrb r0, [r5, #4]
	b _081B4C46
_081B4C44:
	ldrb r0, [r5]
_081B4C46:
	subs r2, r2, r0
_081B4C48:
	ldr r1, [sp, #0xd4]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0xd4]
	ldr r0, [r2]
	strh r1, [r0, #6]
_081B4C56:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x7c]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0xf4]
	ldrh r0, [r4]
	ands r0, r1
	adds r4, r3, #0
	ldr r6, _081B4C80 @ =0x00000482
	adds r5, r7, r6
	cmp r0, #0
	bne _081B4D60
	movs r1, #4
	ldr r2, [sp, #0xfc]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081B4C84
	movs r0, #1
	b _081B4C86
	.align 2, 0
_081B4C80: .4byte 0x00000482
_081B4C84:
	movs r0, #0
_081B4C86:
	ldr r3, _081B4D70 @ =0x00000482
	adds r5, r7, r3
	cmp r0, #0
	bne _081B4D60
	movs r3, #0
	movs r0, #0xa8
	lsls r0, r0, #3
	adds r6, r7, r0
	movs r1, #0xa9
	lsls r1, r1, #3
	adds r1, r1, r7
	mov r8, r1
	ldr r2, _081B4D74 @ =0x0000054F
	adds r2, r2, r7
	mov sb, r2
	adds r0, #0xc
	adds r0, r0, r7
	mov sl, r0
	ldr r1, _081B4D78 @ =0x0000054D
	adds r1, r1, r7
	mov ip, r1
	ldr r2, _081B4D7C @ =0x0000054E
	adds r2, r7, r2
	str r2, [sp, #0xe4]
	ldr r0, _081B4D80 @ =0x00000541
	adds r0, r7, r0
	str r0, [sp, #0xd8]
	ldr r1, _081B4D84 @ =0x000005BC
	adds r1, r7, r1
	str r1, [sp, #0xf0]
	ldr r2, _081B4D88 @ =0x00000542
	adds r2, r7, r2
	str r2, [sp, #0xdc]
	ldr r1, _081B4D8C @ =0x030046B8
	str r4, [sp, #0x100]
_081B4CCC:
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _081B4D90 @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r2, _081B4D94 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #3
	ands r0, r2
	lsls r0, r0, #6
	ldr r2, [sp, #0x100]
	cmp r0, r2
	bne _081B4CF2
	adds r3, #1
	cmp r3, #3
	ble _081B4CCC
	adds r0, r4, #0
_081B4CF2:
	movs r3, #0
	strb r0, [r6]
	ldr r4, [sp, #0xec]
	ldr r0, [r4]
	mov r6, r8
	str r0, [r6]
	ldr r1, [sp, #0xe8]
	ldrb r0, [r1]
	mov r2, sb
	strb r0, [r2]
	ldr r4, [sp, #0xb8]
	ldrb r0, [r4]
	mov r6, sl
	strb r0, [r6]
	ldr r1, [sp, #0xbc]
	ldrb r0, [r1]
	mov r2, ip
	strb r0, [r2]
	ldr r4, [sp, #0xc0]
	ldrb r0, [r4]
	ldr r6, [sp, #0xe4]
	strb r0, [r6]
	add r0, sp, #0x7c
	ldrb r1, [r0]
	ldr r0, [sp, #0xd8]
	strb r1, [r0]
	ldr r1, [sp, #0xf0]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0xcc]
	strb r1, [r4]
	ldr r6, [sp, #0xc4]
	strb r3, [r6]
	ldr r4, [sp, #0xe8]
	strb r0, [r4]
	ldr r6, [sp, #0xec]
	str r2, [r6]
	movs r2, #0
	ldr r0, [sp, #0xf8]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0xb8]
	strb r0, [r4]
	ldr r6, [sp, #0xbc]
	strb r1, [r6]
	ldr r0, [sp, #0xc0]
	strb r2, [r0]
	ldr r2, [sp, #0xd0]
	str r3, [r2]
	ldr r3, [sp, #0xc8]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0xdc]
	strb r0, [r4]
_081B4D60:
	adds r0, r7, #0
	bl Enemy_StepToFloorEdge
	movs r0, #2
	strh r0, [r5]
	movs r0, #0
	b _081B4E72
	.align 2, 0
_081B4D70: .4byte 0x00000482
_081B4D74: .4byte 0x0000054F
_081B4D78: .4byte 0x0000054D
_081B4D7C: .4byte 0x0000054E
_081B4D80: .4byte 0x00000541
_081B4D84: .4byte 0x000005BC
_081B4D88: .4byte 0x00000542
_081B4D8C: .4byte 0x030046B8
_081B4D90: .4byte 0x000003FF
_081B4D94: .4byte 0x0203B400
_081B4D98:
	add r6, sp, #8
	ldr r0, _081B4DD8 @ =0x030046A4
	mov r8, r0
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	mov sl, r6
	cmp r0, #0
	beq _081B4DDC
	adds r0, #4
	b _081B4DE8
	.align 2, 0
_081B4DD8: .4byte 0x030046A4
_081B4DDC:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081B4DE8:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r5, _081B4E20 @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081B4E28
	ldr r0, _081B4E24 @ =0xFFFFFDFF
	ldr r6, [sp, #0xf4]
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	b _081B4E52
	.align 2, 0
_081B4E20: .4byte 0x000004A4
_081B4E24: .4byte 0xFFFFFDFF
_081B4E28:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081B4E48
	cmp r0, #2
	beq _081B4E44
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081B4E44:
	movs r0, #1
	b _081B4E54
_081B4E48:
	ldr r0, _081B4E68 @ =0xFFFFFDFF
	ldr r2, [sp, #0xf4]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_081B4E52:
	movs r0, #0
_081B4E54:
	cmp r0, #0
	bne _081B4E70
	ldr r3, _081B4E6C @ =0x000005C4
	adds r0, r7, r3
_081B4E5C:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _081B4E72
	.align 2, 0
_081B4E68: .4byte 0xFFFFFDFF
_081B4E6C: .4byte 0x000005C4
_081B4E70:
	movs r0, #1
_081B4E72:
	cmp r0, #0
	bne _081B4EE2
	ldr r4, _081B4EA8 @ =0x000004A4
	adds r0, r7, r4
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081B4EB0
	ldr r0, _081B4EAC @ =0xFFFFFDFF
	ldr r2, [sp, #0xf4]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081B4EDA
	.align 2, 0
_081B4EA8: .4byte 0x000004A4
_081B4EAC: .4byte 0xFFFFFDFF
_081B4EB0:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081B4ED0
	cmp r0, #2
	beq _081B4ECC
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081B4ECC:
	movs r0, #1
	b _081B4EDC
_081B4ED0:
	ldr r0, _081B4F50 @ =0xFFFFFDFF
	ldr r3, [sp, #0xf4]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081B4EDA:
	movs r0, #0
_081B4EDC:
	cmp r0, #0
	bne _081B4EE2
	b _081B5674
_081B4EE2:
	movs r2, #0x80
	movs r5, #0xbc
	lsls r5, r5, #1
	adds r1, r7, r5
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #4
	ldr r6, _081B4F54 @ =0x00000222
	adds r2, r7, r6
	ldrh r1, [r2]
	movs r3, #0
	movs r5, #0
	orrs r0, r1
	strh r0, [r2]
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r2, [r0]
	movs r1, #0x1a
	ldr r4, _081B4F58 @ =0x0000046D
	adds r0, r7, r4
	movs r4, #1
	strb r4, [r0]
	ldr r6, _081B4F5C @ =0x0000046B
	adds r0, r7, r6
	strb r3, [r0]
	adds r6, #0xe8
	adds r0, r7, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r5, [r0]
	movs r1, #0xc
	subs r6, #0xeb
	adds r0, r7, r6
	strb r3, [r0]
	ldr r2, _081B4F60 @ =0x00000469
	adds r0, r7, r2
	strb r3, [r0]
	ldr r3, _081B4F64 @ =0x0000046A
	adds r0, r7, r3
	strb r1, [r0]
	adds r6, #0x1c
	adds r0, r7, r6
	str r5, [r0]
	ldr r1, _081B4F68 @ =0x0000046C
	adds r0, r7, r1
	strb r4, [r0]
	b _081B56E4
	.align 2, 0
_081B4F50: .4byte 0xFFFFFDFF
_081B4F54: .4byte 0x00000222
_081B4F58: .4byte 0x0000046D
_081B4F5C: .4byte 0x0000046B
_081B4F60: .4byte 0x00000469
_081B4F64: .4byte 0x0000046A
_081B4F68: .4byte 0x0000046C
_081B4F6C:
	ldr r2, _081B500C @ =0x00000544
	adds r0, r7, r2
	movs r1, #0x96
	lsls r1, r1, #1
	strh r1, [r0]
	ldr r3, _081B5010 @ =0x0000048D
	adds r2, r7, r3
	ldrb r0, [r2]
	cmp r0, #0
	bne _081B4FA2
	ldr r4, _081B5014 @ =0x0000048C
	adds r0, r7, r4
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _081B4FA2
	ldr r5, _081B5018 @ =0x000004BE
	adds r0, r7, r5
	movs r1, #0x2d
	strh r1, [r0]
	movs r0, #0x41
	strb r0, [r2]
	adds r0, r7, #0
	movs r1, #3
	bl Enemy_PlayAnim
_081B4FA2:
	adds r0, r7, #0
	bl Enemy_TargetNearestLinkPlayer
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081B4FB2
	bl _081B4726
_081B4FB2:
	movs r2, #0x10
	movs r6, #0xbc
	lsls r6, r6, #1
	adds r1, r7, r6
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #0
	strh r0, [r1, #6]
	movs r2, #0x95
	lsls r2, r2, #3
	adds r3, r7, r2
	ldr r5, [r3]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r4, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r3, [sp, #0xd4]
	str r2, [sp, #0xe0]
	cmp r4, #0
	blt _081B5008
	cmp r1, #0
	blt _081B5008
	ldr r0, _081B501C @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _081B5008
	ldr r0, _081B5020 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B5024
_081B5008:
	movs r4, #0
	b _081B5032
	.align 2, 0
_081B500C: .4byte 0x00000544
_081B5010: .4byte 0x0000048D
_081B5014: .4byte 0x0000048C
_081B5018: .4byte 0x000004BE
_081B501C: .4byte 0x030046A8
_081B5020: .4byte 0x030046AC
_081B5024:
	ldr r0, _081B5044 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_081B5032:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081B5048
	adds r0, #4
	b _081B5054
	.align 2, 0
_081B5044: .4byte 0x030046A4
_081B5048:
	ldr r0, _081B5068 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B5054:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081B506C
	cmp r2, #2
	beq _081B5070
	b _081B5074
	.align 2, 0
_081B5068: .4byte 0x030046A4
_081B506C:
	ldrb r0, [r5, #4]
	b _081B5072
_081B5070:
	ldrb r0, [r5]
_081B5072:
	subs r1, r1, r0
_081B5074:
	strh r1, [r5, #2]
	ldr r0, _081B5088 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081B508C
	movs r0, #1
	b _081B508E
	.align 2, 0
_081B5088: .4byte 0x030047A4
_081B508C:
	movs r0, #0
_081B508E:
	cmp r0, #0
	beq _081B50CC
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r1, [r0]
	cmp r1, #0
	beq _081B50AE
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081B50AA
	adds r2, r0, #0
_081B50AA:
	cmp r2, #0
	bge _081B50B8
_081B50AE:
	ldr r4, _081B50B4 @ =0x000005C4
	adds r0, r7, r4
	b _081B55F0
	.align 2, 0
_081B50B4: .4byte 0x000005C4
_081B50B8:
	ldr r1, _081B50C8 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _081B5114
	.align 2, 0
_081B50C8: .4byte 0x03002BE0
_081B50CC:
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r7, r5
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081B50F8
	cmp r1, #0
	blt _081B50F8
	ldr r0, _081B50FC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081B50F8
	ldr r0, _081B5100 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B5104
_081B50F8:
	movs r5, #0
	b _081B5112
	.align 2, 0
_081B50FC: .4byte 0x030046A8
_081B5100: .4byte 0x030046AC
_081B5104:
	ldr r0, _081B514C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081B5112:
	movs r2, #0
_081B5114:
	ldr r6, _081B5150 @ =0x00000256
	adds r0, r7, r6
	ldrh r0, [r0]
	cmp r5, r0
	beq _081B5134
	ldr r1, _081B5154 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081B5134
	b _081B552C
_081B5134:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r2, [sp, #0xf4]
	ldrh r0, [r2]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x80]
	cmp r0, #0
	beq _081B5158
	movs r0, #0
	b _081B5606
	.align 2, 0
_081B514C: .4byte 0x030046A4
_081B5150: .4byte 0x00000256
_081B5154: .4byte 0x03002BE0
_081B5158:
	ldr r3, _081B5200 @ =0x00000222
	adds r2, r7, r3
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r4, [sp, #0xf4]
	ldrh r0, [r4]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sl, r0
	str r2, [sp, #0xfc]
	cmp r0, #0
	beq _081B5218
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r6, _081B5204 @ =0x0000046D
	adds r6, r7, r6
	str r6, [sp, #0x84]
	movs r2, #1
	strb r2, [r6]
	ldr r3, _081B5208 @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x88]
	movs r4, #0
	strb r4, [r3]
	subs r5, #0x65
	adds r5, r7, r5
	str r5, [sp, #0x8c]
	strb r0, [r5]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x90]
	str r1, [r6]
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r5, r7, r0
	add r1, sp, #0x80
	ldrh r1, [r1]
	strh r1, [r5]
	movs r0, #0xc
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r4, r7, r2
	movs r3, #0
	strb r3, [r4]
	ldr r6, _081B520C @ =0x00000469
	adds r3, r7, r6
	movs r1, #0
	strb r1, [r3]
	adds r6, #1
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, _081B5210 @ =0x00000484
	adds r1, r7, r0
	ldr r6, [sp, #0x80]
	str r6, [r1]
	ldr r6, _081B5214 @ =0x0000046C
	adds r0, r7, r6
	movs r6, #1
	strb r6, [r0]
	ldr r6, [sp, #0x84]
	str r6, [sp, #0xcc]
	ldr r6, [sp, #0x88]
	str r6, [sp, #0xc4]
	ldr r6, [sp, #0x8c]
	str r6, [sp, #0xe8]
	ldr r6, [sp, #0x90]
	str r6, [sp, #0xec]
	str r5, [sp, #0xf8]
	str r4, [sp, #0xb8]
	str r3, [sp, #0xbc]
	str r2, [sp, #0xc0]
	str r1, [sp, #0xd0]
	str r0, [sp, #0xc8]
	b _081B53EC
	.align 2, 0
_081B5200: .4byte 0x00000222
_081B5204: .4byte 0x0000046D
_081B5208: .4byte 0x0000046B
_081B520C: .4byte 0x00000469
_081B5210: .4byte 0x00000484
_081B5214: .4byte 0x0000046C
_081B5218:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, _081B52E0 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x94]
	strb r0, [r2]
	ldr r3, _081B52E4 @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x98]
	movs r4, #0
	strb r4, [r3]
	ldr r5, _081B52E8 @ =0x00000553
	adds r5, r7, r5
	str r5, [sp, #0x9c]
	strb r0, [r5]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xa0]
	str r1, [r6]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0xa4]
	mov r2, sl
	strh r2, [r1]
	movs r1, #5
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0xa8]
	strb r4, [r3]
	ldr r4, _081B52EC @ =0x00000469
	adds r5, r7, r4
	movs r6, #0
	strb r6, [r5]
	ldr r2, _081B52F0 @ =0x0000046A
	adds r4, r7, r2
	strb r1, [r4]
	ldr r6, _081B52F4 @ =0x00000484
	adds r3, r7, r6
	mov r1, sl
	str r1, [r3]
	subs r6, #0x18
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0xd4]
	ldr r0, [r0]
	str r0, [sp, #0xac]
	ldr r1, [sp, #0xe0]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0xac]
	strh r1, [r6]
	ldr r6, [sp, #0xe0]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0xac]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	str r1, [sp, #0xb0]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x94]
	str r0, [sp, #0xcc]
	ldr r6, [sp, #0x98]
	str r6, [sp, #0xc4]
	ldr r0, [sp, #0x9c]
	str r0, [sp, #0xe8]
	ldr r6, [sp, #0xa0]
	str r6, [sp, #0xec]
	ldr r0, [sp, #0xa4]
	str r0, [sp, #0xf8]
	ldr r6, [sp, #0xa8]
	str r6, [sp, #0xb8]
	str r5, [sp, #0xbc]
	str r4, [sp, #0xc0]
	str r3, [sp, #0xd0]
	str r2, [sp, #0xc8]
	ldr r0, [sp, #0xb0]
	cmp r0, #0
	blt _081B52DA
	cmp r1, #0
	blt _081B52DA
	ldr r0, _081B52F8 @ =0x030046A8
	ldr r0, [r0]
	ldr r2, [sp, #0xb0]
	cmp r2, r0
	bhs _081B52DA
	ldr r0, _081B52FC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B5300
_081B52DA:
	movs r4, #0
	b _081B5310
	.align 2, 0
_081B52E0: .4byte 0x0000046D
_081B52E4: .4byte 0x0000046B
_081B52E8: .4byte 0x00000553
_081B52EC: .4byte 0x00000469
_081B52F0: .4byte 0x0000046A
_081B52F4: .4byte 0x00000484
_081B52F8: .4byte 0x030046A8
_081B52FC: .4byte 0x030046AC
_081B5300:
	ldr r0, _081B5320 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r3, [sp, #0xb0]
	adds r4, r0, r3
_081B5310:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081B5324
	adds r0, #4
	b _081B5330
	.align 2, 0
_081B5320: .4byte 0x030046A4
_081B5324:
	ldr r0, _081B5344 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B5330:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081B5348
	cmp r2, #2
	beq _081B534E
	b _081B5354
	.align 2, 0
_081B5344: .4byte 0x030046A4
_081B5348:
	ldr r4, [sp, #0xac]
	ldrb r0, [r4, #4]
	b _081B5352
_081B534E:
	ldr r5, [sp, #0xac]
	ldrb r0, [r5]
_081B5352:
	subs r1, r1, r0
_081B5354:
	ldr r6, [sp, #0xac]
	strh r1, [r6, #2]
	ldr r1, [sp, #0xd4]
	ldr r0, [r1]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081B5380
	cmp r1, #0
	blt _081B5380
	ldr r0, _081B5384 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081B5380
	ldr r0, _081B5388 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B538C
_081B5380:
	movs r4, #0
	b _081B539A
	.align 2, 0
_081B5384: .4byte 0x030046A8
_081B5388: .4byte 0x030046AC
_081B538C:
	ldr r0, _081B53B0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081B539A:
	ldr r2, [sp, #0xd4]
	ldr r5, [r2]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081B53B4
	adds r0, #4
	b _081B53C0
	.align 2, 0
_081B53B0: .4byte 0x030046A4
_081B53B4:
	ldr r0, _081B53D4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B53C0:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081B53D8
	cmp r3, #2
	beq _081B53DC
	b _081B53E0
	.align 2, 0
_081B53D4: .4byte 0x030046A4
_081B53D8:
	ldrb r0, [r5, #4]
	b _081B53DE
_081B53DC:
	ldrb r0, [r5]
_081B53DE:
	subs r2, r2, r0
_081B53E0:
	ldr r3, [sp, #0xd4]
	ldr r0, [r3]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r3]
	strh r1, [r0, #6]
_081B53EC:
	ldrb r4, [r7, #5]
	str r4, [sp, #0xb4]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r5, [sp, #0xf4]
	ldrh r0, [r5]
	ands r0, r1
	ldr r6, _081B5414 @ =0x00000482
	adds r5, r7, r6
	cmp r0, #0
	bne _081B54F4
	movs r1, #4
	ldr r2, [sp, #0xfc]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081B5418
	movs r0, #1
	b _081B541A
	.align 2, 0
_081B5414: .4byte 0x00000482
_081B5418:
	movs r0, #0
_081B541A:
	ldr r3, _081B5504 @ =0x00000482
	adds r5, r7, r3
	cmp r0, #0
	bne _081B54F4
	movs r3, #0
	movs r0, #0xa8
	lsls r0, r0, #3
	adds r6, r7, r0
	movs r1, #0xa9
	lsls r1, r1, #3
	adds r1, r1, r7
	mov r8, r1
	ldr r2, _081B5508 @ =0x0000054F
	adds r2, r2, r7
	mov sb, r2
	adds r0, #0xc
	adds r0, r0, r7
	mov sl, r0
	ldr r1, _081B550C @ =0x0000054D
	adds r1, r1, r7
	mov ip, r1
	ldr r2, _081B5510 @ =0x0000054E
	adds r2, r7, r2
	str r2, [sp, #0xe4]
	ldr r0, _081B5514 @ =0x00000541
	adds r0, r7, r0
	str r0, [sp, #0xd8]
	ldr r1, _081B5518 @ =0x000005BC
	adds r1, r7, r1
	str r1, [sp, #0xf0]
	ldr r2, _081B551C @ =0x00000542
	adds r2, r7, r2
	str r2, [sp, #0xdc]
	ldr r1, _081B5520 @ =0x030046B8
	str r4, [sp, #0x100]
_081B5460:
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _081B5524 @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r2, _081B5528 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #3
	ands r0, r2
	lsls r0, r0, #6
	ldr r2, [sp, #0x100]
	cmp r0, r2
	bne _081B5486
	adds r3, #1
	cmp r3, #3
	ble _081B5460
	adds r0, r4, #0
_081B5486:
	movs r3, #0
	strb r0, [r6]
	ldr r4, [sp, #0xec]
	ldr r0, [r4]
	mov r6, r8
	str r0, [r6]
	ldr r1, [sp, #0xe8]
	ldrb r0, [r1]
	mov r2, sb
	strb r0, [r2]
	ldr r4, [sp, #0xb8]
	ldrb r0, [r4]
	mov r6, sl
	strb r0, [r6]
	ldr r1, [sp, #0xbc]
	ldrb r0, [r1]
	mov r2, ip
	strb r0, [r2]
	ldr r4, [sp, #0xc0]
	ldrb r0, [r4]
	ldr r6, [sp, #0xe4]
	strb r0, [r6]
	add r0, sp, #0xb4
	ldrb r1, [r0]
	ldr r0, [sp, #0xd8]
	strb r1, [r0]
	ldr r1, [sp, #0xf0]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0xcc]
	strb r1, [r4]
	ldr r6, [sp, #0xc4]
	strb r3, [r6]
	ldr r4, [sp, #0xe8]
	strb r0, [r4]
	ldr r6, [sp, #0xec]
	str r2, [r6]
	movs r2, #0
	ldr r0, [sp, #0xf8]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0xb8]
	strb r0, [r4]
	ldr r6, [sp, #0xbc]
	strb r1, [r6]
	ldr r0, [sp, #0xc0]
	strb r2, [r0]
	ldr r2, [sp, #0xd0]
	str r3, [r2]
	ldr r3, [sp, #0xc8]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0xdc]
	strb r0, [r4]
_081B54F4:
	adds r0, r7, #0
	bl Enemy_StepToFloorEdge
	movs r0, #2
	strh r0, [r5]
	movs r0, #0
	b _081B5606
	.align 2, 0
_081B5504: .4byte 0x00000482
_081B5508: .4byte 0x0000054F
_081B550C: .4byte 0x0000054D
_081B5510: .4byte 0x0000054E
_081B5514: .4byte 0x00000541
_081B5518: .4byte 0x000005BC
_081B551C: .4byte 0x00000542
_081B5520: .4byte 0x030046B8
_081B5524: .4byte 0x000003FF
_081B5528: .4byte 0x0203B400
_081B552C:
	add r6, sp, #0x10
	ldr r0, _081B556C @ =0x030046A4
	mov r8, r0
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	mov sl, r6
	cmp r0, #0
	beq _081B5570
	adds r0, #4
	b _081B557C
	.align 2, 0
_081B556C: .4byte 0x030046A4
_081B5570:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081B557C:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r5, _081B55B4 @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081B55BC
	ldr r0, _081B55B8 @ =0xFFFFFDFF
	ldr r6, [sp, #0xf4]
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	b _081B55E6
	.align 2, 0
_081B55B4: .4byte 0x000004A4
_081B55B8: .4byte 0xFFFFFDFF
_081B55BC:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081B55DC
	cmp r0, #2
	beq _081B55D8
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081B55D8:
	movs r0, #1
	b _081B55E8
_081B55DC:
	ldr r0, _081B55FC @ =0xFFFFFDFF
	ldr r2, [sp, #0xf4]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_081B55E6:
	movs r0, #0
_081B55E8:
	cmp r0, #0
	bne _081B5604
	ldr r3, _081B5600 @ =0x000005C4
	adds r0, r7, r3
_081B55F0:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _081B5606
	.align 2, 0
_081B55FC: .4byte 0xFFFFFDFF
_081B5600: .4byte 0x000005C4
_081B5604:
	movs r0, #1
_081B5606:
	cmp r0, #0
	bne _081B568C
	ldr r4, _081B563C @ =0x000004A4
	adds r0, r7, r4
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081B5644
	ldr r0, _081B5640 @ =0xFFFFFDFF
	ldr r2, [sp, #0xf4]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081B566E
	.align 2, 0
_081B563C: .4byte 0x000004A4
_081B5640: .4byte 0xFFFFFDFF
_081B5644:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081B5664
	cmp r0, #2
	beq _081B5660
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081B5660:
	movs r0, #1
	b _081B5670
_081B5664:
	ldr r0, _081B5684 @ =0xFFFFFDFF
	ldr r3, [sp, #0xf4]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081B566E:
	movs r0, #0
_081B5670:
	cmp r0, #0
	bne _081B568C
_081B5674:
	ldr r4, _081B5688 @ =0x000005C4
	adds r0, r7, r4
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	bl _081B4726
	.align 2, 0
_081B5684: .4byte 0xFFFFFDFF
_081B5688: .4byte 0x000005C4
_081B568C:
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r3, #1
	ldr r6, _081B56F8 @ =0x0000046D
	adds r0, r7, r6
	movs r2, #0
	strb r3, [r0]
	ldr r4, _081B56FC @ =0x0000046B
	adds r0, r7, r4
	strb r2, [r0]
	subs r5, #0x4d
	adds r0, r7, r5
	strb r3, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r7, r6
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r1, #0
	strh r2, [r0]
	movs r4, #7
	subs r5, #0xeb
	adds r0, r7, r5
	strb r1, [r0]
	ldr r6, _081B5700 @ =0x00000469
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _081B5704 @ =0x0000046A
	adds r0, r7, r1
	strb r4, [r0]
	ldr r4, _081B5708 @ =0x00000484
	adds r0, r7, r4
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r3, [r0]
	adds r6, #0x19
	adds r1, r7, r6
	movs r0, #2
	strh r0, [r1]
_081B56E4:
	movs r0, #1
_081B56E6:
	add sp, #0x104
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081B56F8: .4byte 0x0000046D
_081B56FC: .4byte 0x0000046B
_081B5700: .4byte 0x00000469
_081B5704: .4byte 0x0000046A
_081B5708: .4byte 0x00000484
