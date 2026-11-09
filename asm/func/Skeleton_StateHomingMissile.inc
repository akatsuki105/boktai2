	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x3c
	adds r5, r0, #0
	mov r8, r1
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _0810B18C @ =0x0000046D
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0810B190
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0810B192
	.align 2, 0
_0810B18C: .4byte 0x0000046D
_0810B190:
	movs r0, #0
_0810B192:
	cmp r0, #0
	beq _0810B1EE
	ldr r3, _0810B1C8 @ =0x0000070C
	adds r1, r6, r3
	movs r0, #0
	strb r0, [r1]
	movs r4, #0xc2
	lsls r4, r4, #1
	adds r0, r5, r4
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r3, _0810B1CC @ =0x00000546
	adds r0, r5, r3
	ldrh r0, [r0]
	cmp r1, r0
	bgt _0810B1D8
	ldr r4, _0810B1D0 @ =0x0000070D
	adds r1, r6, r4
	movs r0, #3
	strb r0, [r1]
	movs r0, #0x3c
	movs r1, #4
	bl Div
	ldr r2, _0810B1D4 @ =0x00000712
	adds r1, r6, r2
	b _0810B1EC
	.align 2, 0
_0810B1C8: .4byte 0x0000070C
_0810B1CC: .4byte 0x00000546
_0810B1D0: .4byte 0x0000070D
_0810B1D4: .4byte 0x00000712
_0810B1D8:
	ldr r3, _0810B248 @ =0x0000070D
	adds r1, r6, r3
	movs r0, #2
	strb r0, [r1]
	movs r0, #0x50
	movs r1, #3
	bl Div
	ldr r4, _0810B24C @ =0x00000712
	adds r1, r6, r4
_0810B1EC:
	strh r0, [r1]
_0810B1EE:
	adds r0, r5, #0
	movs r1, #0x14
	bl Enemy_PlayAnim
	ldr r1, _0810B250 @ =0x0000070C
	adds r0, r6, r1
	ldr r2, _0810B248 @ =0x0000070D
	adds r1, r6, r2
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	blo _0810B208
	b _0810B338
_0810B208:
	ldr r3, _0810B24C @ =0x00000712
	adds r0, r6, r3
	ldrh r1, [r0]
	mov r0, r8
	bl Mod
	cmp r0, #0
	beq _0810B21A
	b _0810B338
_0810B21A:
	ldrb r3, [r5, #5]
	adds r0, r3, #0
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	lsls r7, r0, #6
	add r4, sp, #0x24
	ldr r2, _0810B254 @ =gSineTable
	adds r0, r7, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #8
	mov ip, r3
	cmp r0, #0
	blt _0810B258
	asrs r1, r0, #0xc
	b _0810B25E
	.align 2, 0
_0810B248: .4byte 0x0000070D
_0810B24C: .4byte 0x00000712
_0810B250: .4byte 0x0000070C
_0810B254: .4byte gSineTable
_0810B258:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0810B25E:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	lsls r0, r7, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x80
	lsls r0, r0, #1
	muls r0, r1, r0
	cmp r0, #0
	blt _0810B27A
	asrs r0, r0, #0xc
	b _0810B280
_0810B27A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0810B280:
	strh r0, [r4, #4]
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	str r0, [sp, #0x2c]
	str r1, [sp, #0x30]
	add r1, sp, #0x24
	add r3, sp, #0x2c
	ldrh r0, [r3]
	ldrh r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0810B374 @ =0xFFFF0000
	ldr r2, [sp, #0x2c]
	ands r2, r4
	orrs r2, r0
	asrs r1, r2, #0x10
	movs r0, #0x96
	lsls r0, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r0, _0810B378 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x2c]
	add r1, sp, #0x24
	ldrh r0, [r3, #4]
	ldrh r1, [r1, #4]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [r3, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [r3, #4]
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r0, [r0]
	mov r2, ip
	subs r1, r0, r2
	adds r2, r3, #0
	cmp r1, #0x80
	bgt _0810B2DC
	movs r0, #0x80
	rsbs r0, r0, #0
_0810B2DC:
	ldr r0, _0810B37C @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [sp, #0x34]
	str r1, [sp, #0x38]
	add r1, sp, #0x34
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrb r3, [r0]
	movs r0, #0x5a
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	movs r0, #0x14
	str r0, [sp, #8]
	movs r0, #3
	str r0, [sp, #0xc]
	movs r0, #0x19
	str r0, [sp, #0x10]
	ldr r4, _0810B380 @ =0x00000226
	adds r0, r5, r4
	ldrh r0, [r0]
	str r0, [sp, #0x14]
	adds r4, #8
	adds r0, r5, r4
	ldrh r0, [r0]
	str r0, [sp, #0x18]
	adds r4, #0x12
	adds r0, r5, r4
	ldr r0, [r0]
	str r0, [sp, #0x1c]
	subs r4, #0xa
	adds r0, r5, r4
	ldrh r0, [r0]
	str r0, [sp, #0x20]
	adds r0, r2, #0
	movs r2, #2
	bl Entity081f8a28_Spawn
	ldr r0, _0810B384 @ =0x0000070C
	adds r1, r6, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0810B338:
	mov r1, r8
	cmp r1, #0x50
	ble _0810B368
	ldr r4, _0810B388 @ =Skeleton_StateHomingMissileEnd
	movs r3, #0x40
	ldr r2, _0810B38C @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0810B390 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r5, r4
	strh r2, [r0]
_0810B368:
	add sp, #0x3c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0810B374: .4byte 0xFFFF0000
_0810B378: .4byte 0x0000FFFF
_0810B37C: .4byte 0x03002BE0
_0810B380: .4byte 0x00000226
_0810B384: .4byte 0x0000070C
_0810B388: .4byte Skeleton_StateHomingMissileEnd
_0810B38C: .4byte 0x0000046D
_0810B390: .4byte 0x0000046B
