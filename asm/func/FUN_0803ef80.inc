	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x20
	adds r6, r0, #0
	adds r7, r1, #0
	adds r5, r6, #0
	movs r0, #0xd3
	lsls r0, r0, #2
	adds r0, r0, r6
	mov r8, r0
	adds r1, r6, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803F070
	movs r4, #0
	strb r4, [r1]
	adds r3, r6, #0
	adds r3, #0xa0
	ldrb r0, [r3]
	cmp r0, #1
	bls _0803EFBC
	movs r0, #0x40
	adds r2, r6, #0
	adds r2, #0x4d
	strb r0, [r2]
	movs r1, #0xff
	movs r0, #2
	b _0803EFC6
_0803EFBC:
	adds r2, r6, #0
	adds r2, #0x4d
	strb r4, [r2]
	movs r1, #0xff
	movs r0, #1
_0803EFC6:
	strb r0, [r3]
	ldrb r0, [r2]
	adds r0, #0x10
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r6, #0
	adds r0, #0xa1
	strb r1, [r0]
	movs r1, #0xcb
	lsls r1, r1, #2
	adds r2, r5, r1
	movs r0, #2
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r6, #0
	mov r1, r8
	movs r3, #0x10
	bl Boss_PlayAnimFlip
	movs r2, #0xaf
	lsls r2, r2, #1
	adds r0, r5, r2
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	movs r3, #0xae
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r1, [r0]
	movs r4, #0xae
	lsls r4, r4, #2
	adds r0, r5, r4
	strb r2, [r0]
	ldr r0, _0803F048 @ =0x000002B9
	adds r1, r5, r0
	movs r0, #5
	strb r0, [r1]
	ldr r2, _0803F04C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0803F050 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0803F054 @ =0x0203B400
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0x7f
	bgt _0803F05C
	movs r1, #1
	movs r2, #2
	ldr r3, _0803F058 @ =0x000002BD
	adds r0, r5, r3
_0803F038:
	strb r2, [r0]
	subs r2, #2
	subs r0, #1
	subs r1, #1
	cmp r1, #0
	bge _0803F038
	b _0803F070
	.align 2, 0
_0803F048: .4byte 0x000002B9
_0803F04C: .4byte 0x030046B8
_0803F050: .4byte 0x000003FF
_0803F054: .4byte 0x0203B400
_0803F058: .4byte 0x000002BD
_0803F05C:
	movs r1, #1
	movs r2, #3
	ldr r4, _0803F0D0 @ =0x000002BD
	adds r0, r5, r4
_0803F064:
	strb r2, [r0]
	subs r2, #2
	subs r0, #1
	subs r1, #1
	cmp r1, #0
	bge _0803F064
_0803F070:
	adds r0, r6, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803F084
	b _0803F2E6
_0803F084:
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803F09A
	b _0803F2E6
_0803F09A:
	movs r2, #0xb1
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r2, [r0]
	movs r3, #0
	ldrsh r1, [r0, r3]
	adds r3, r0, #0
	cmp r1, #0x3d
	bgt _0803F0B0
	adds r0, r2, #2
	strh r0, [r3]
_0803F0B0:
	ldr r2, _0803F0D4 @ =gSineTable
	lsls r0, r7, #1
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0803F0D8
	asrs r1, r0, #0xc
	b _0803F0DE
	.align 2, 0
_0803F0D0: .4byte 0x000002BD
_0803F0D4: .4byte gSineTable
_0803F0D8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0803F0DE:
	ldrh r0, [r3]
	adds r0, r0, r1
	movs r7, #0xb0
	lsls r7, r7, #1
	adds r1, r5, r7
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _0803F0F4
	movs r0, #0
	strh r0, [r1]
_0803F0F4:
	movs r1, #0xaf
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r2, [r0]
	cmp r2, #0
	beq _0803F108
	cmp r2, #1
	bne _0803F106
	b _0803F2D4
_0803F106:
	b _0803F2E6
_0803F108:
	mov r3, r8
	ldrh r0, [r3, #0x14]
	cmp r0, #4
	bne _0803F112
	strh r2, [r3, #0xc]
_0803F112:
	movs r7, #0xae
	lsls r7, r7, #1
	adds r4, r5, r7
	ldrh r0, [r4]
	cmp r0, #0x12
	bne _0803F124
	ldr r0, _0803F17C @ =0x0000035E
	bl PlaySound_0824078c
_0803F124:
	ldrh r0, [r4]
	cmp r0, #0x1e
	beq _0803F130
	cmp r0, #0x32
	beq _0803F130
	b _0803F27E
_0803F130:
	ldr r1, _0803F180 @ =0x000002B9
	adds r0, r5, r1
	ldrb r1, [r0]
	movs r3, #0xae
	lsls r3, r3, #2
	adds r2, r5, r3
	movs r4, #0xaf
	lsls r4, r4, #2
	adds r0, r5, r4
	ldrb r2, [r2]
	adds r0, r0, r2
	ldrb r2, [r0]
	add r0, sp, #0x18
	bl Map_GetPathNodePos
	add r7, sp, #0x18
	adds r0, r7, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0803F176
	cmp r1, #0
	blt _0803F176
	ldr r0, _0803F184 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0803F176
	ldr r0, _0803F188 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0803F18C
_0803F176:
	movs r4, #0
	b _0803F19A
	.align 2, 0
_0803F17C: .4byte 0x0000035E
_0803F180: .4byte 0x000002B9
_0803F184: .4byte 0x030046A8
_0803F188: .4byte 0x030046AC
_0803F18C:
	ldr r0, _0803F1AC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0803F19A:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0803F1B0
	adds r0, #4
	b _0803F1BC
	.align 2, 0
_0803F1AC: .4byte 0x030046A4
_0803F1B0:
	ldr r0, _0803F1D0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0803F1BC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0803F1D4
	cmp r2, #2
	beq _0803F1D8
	b _0803F1DC
	.align 2, 0
_0803F1D0: .4byte 0x030046A4
_0803F1D4:
	ldrb r0, [r7, #4]
	b _0803F1DA
_0803F1D8:
	ldrb r0, [r7]
_0803F1DA:
	subs r1, r1, r0
_0803F1DC:
	add r3, sp, #0x18
	strh r1, [r3, #2]
	movs r7, #0x86
	lsls r7, r7, #1
	adds r0, r6, r7
	ldr r2, [r0]
	movs r1, #0
	ldrsh r0, [r2, r1]
	adds r1, r3, #0
	movs r4, #0
	ldrsh r1, [r1, r4]
	subs r0, r0, r1
	movs r7, #4
	ldrsh r1, [r2, r7]
	movs r4, #4
	ldrsh r2, [r3, r4]
	subs r1, r1, r2
	bl ArcTan2_8
	adds r4, r0, #0
	ldr r7, _0803F2BC @ =0x000002DE
	adds r0, r5, r7
	movs r1, #0
	ldrsh r3, [r0, r1]
	ldr r2, _0803F2C0 @ =0x000002B6
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803F222
	subs r7, #0x18
	adds r0, r5, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	asrs r3, r0, #6
_0803F222:
	ldr r2, _0803F2C4 @ =0x00000958
	adds r0, r5, r2
	ldr r0, [r0]
	movs r7, #0xb9
	lsls r7, r7, #2
	adds r1, r5, r7
	movs r7, #0
	ldrsh r2, [r1, r7]
	movs r7, #0xb8
	lsls r7, r7, #2
	adds r1, r5, r7
	movs r7, #0
	ldrsh r1, [r1, r7]
	str r1, [sp]
	ldr r7, _0803F2C8 @ =0x000002E2
	adds r1, r5, r7
	movs r7, #0
	ldrsh r1, [r1, r7]
	str r1, [sp, #4]
	ldr r7, _0803F2CC @ =0x000002E6
	adds r1, r5, r7
	movs r7, #0
	ldrsh r1, [r1, r7]
	str r1, [sp, #8]
	movs r7, #0xba
	lsls r7, r7, #2
	adds r1, r5, r7
	movs r7, #0
	ldrsh r1, [r1, r7]
	str r1, [sp, #0xc]
	ldr r7, _0803F2D0 @ =0x000002EA
	adds r1, r5, r7
	movs r7, #0
	ldrsh r1, [r1, r7]
	str r1, [sp, #0x10]
	add r1, sp, #0x18
	str r1, [sp, #0x14]
	adds r1, r4, #0
	bl FUN_0805eee4
	movs r2, #0xae
	lsls r2, r2, #2
	adds r1, r5, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0803F27E:
	movs r3, #0xae
	lsls r3, r3, #1
	adds r4, r5, r3
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x4f
	bls _0803F2E6
	movs r7, #0xcb
	lsls r7, r7, #2
	adds r2, r5, r7
	movs r0, #2
	str r0, [sp]
	movs r0, #3
	str r0, [sp, #4]
	adds r0, r6, #0
	mov r1, r8
	movs r3, #0x10
	bl Boss_PlayAnimFlip
	movs r0, #0xaf
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r0, #0
	strh r0, [r4]
	b _0803F2E6
	.align 2, 0
_0803F2BC: .4byte 0x000002DE
_0803F2C0: .4byte 0x000002B6
_0803F2C4: .4byte 0x00000958
_0803F2C8: .4byte 0x000002E2
_0803F2CC: .4byte 0x000002E6
_0803F2D0: .4byte 0x000002EA
_0803F2D4:
	mov r3, r8
	ldrb r1, [r3, #0x1d]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803F2E6
	adds r0, r6, #0
	adds r0, #0xa7
	strb r2, [r0]
_0803F2E6:
	add sp, #0x20
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
