	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x34
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	mov r8, r0
	mov sl, r6
	ldr r2, _081BB038 @ =0x0000046D
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081BB03C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081BB03E
	.align 2, 0
_081BB038: .4byte 0x0000046D
_081BB03C:
	movs r0, #0
_081BB03E:
	cmp r0, #0
	beq _081BB086
	ldr r3, _081BB0E8 @ =0x0000046B
	adds r0, r6, r3
	movs r1, #0
	strb r1, [r0]
	ldr r7, _081BB0EC @ =0x0000046E
	adds r0, r6, r7
	strb r1, [r0]
	ldr r0, _081BB0F0 @ =0x000006C1
	add r0, r8
	strb r1, [r0]
	ldr r0, _081BB0F4 @ =0x000006C4
	add r0, r8
	ldrb r0, [r0]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	movs r0, #0xd8
	lsls r0, r0, #3
	add r0, r8
	strb r1, [r0]
	movs r0, #0xda
	lsls r0, r0, #3
	add r0, r8
	mov r3, sl
	ldr r1, [r3, #8]
	ldr r2, [r3, #0xc]
	str r1, [r0]
	str r2, [r0, #4]
	bl GolemLink_SnapToTileCenter
_081BB086:
	movs r0, #0x80
	lsls r0, r0, #1
	movs r7, #0xc0
	lsls r7, r7, #1
	adds r5, r6, r7
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
	mov r4, sp
	adds r4, #5
	adds r0, r6, #0
	add r1, sp, #4
	adds r2, r4, #0
	bl Enemy_SetAnimFacing
	add r0, sp, #4
	ldrb r3, [r0]
	ldrb r2, [r4]
	ldr r1, _081BB0F8 @ =0x085ADFA8
	lsls r0, r2, #1
	adds r0, r0, r1
	ldrh r4, [r0]
	movs r0, #8
	mov sb, r0
	orrs r4, r2
	ldr r1, _081BB0FC @ =0x0000025D
	adds r0, r6, r1
	ldrb r1, [r0]
	str r5, [sp, #0x2c]
	str r0, [sp, #0x30]
	cmp r1, #0
	bne _081BB104
	ldr r2, _081BB100 @ =0x000004B7
	adds r0, r6, r2
	mov r7, sb
	strb r7, [r0]
	ldr r1, [r6, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r2, r4, #0x18
	lsrs r2, r2, #0x18
	str r2, [sp]
	movs r2, #8
	bl AuxAnim_SetAnim
	ldr r0, _081BB0EC @ =0x0000046E
	adds r7, r6, r0
	b _081BB186
	.align 2, 0
_081BB0E8: .4byte 0x0000046B
_081BB0EC: .4byte 0x0000046E
_081BB0F0: .4byte 0x000006C1
_081BB0F4: .4byte 0x000006C4
_081BB0F8: .4byte 0x085ADFA8
_081BB0FC: .4byte 0x0000025D
_081BB100: .4byte 0x000004B7
_081BB104:
	ldr r0, [r6, #0x44]
	adds r5, r0, #0
	adds r5, #0x20
	adds r3, #8
	mov sb, r3
	ldr r1, _081BB174 @ =0x000004B7
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r2, r0, #0
	ldr r3, _081BB178 @ =0x0000046E
	adds r7, r6, r3
	cmp r1, sb
	bne _081BB140
	ldrb r0, [r7]
	cmp r0, #0
	bne _081BB140
	cmp r4, #1
	bne _081BB132
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _081BB18A
_081BB132:
	cmp r4, #0
	bne _081BB140
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _081BB18A
_081BB140:
	mov r0, sb
	strb r0, [r2]
	adds r0, r4, #0
	movs r1, #4
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _081BB152
	movs r3, #6
_081BB152:
	ldr r1, [r6, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	mov r2, sb
	str r3, [sp]
	movs r3, #2
	bl MainSprite_SetAnim
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _081BB17C
	ldr r0, [r5, #8]
	movs r2, #4
	orrs r0, r2
	b _081BB184
	.align 2, 0
_081BB174: .4byte 0x000004B7
_081BB178: .4byte 0x0000046E
_081BB17C:
	ldr r0, [r5, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081BB184:
	str r0, [r5, #8]
_081BB186:
	movs r0, #0
	strb r0, [r7]
_081BB18A:
	ldr r3, _081BB1B0 @ =0x000006C1
	add r3, r8
	ldrb r2, [r3]
	cmp r2, #0
	beq _081BB196
	b _081BB2BC
_081BB196:
	ldr r1, _081BB1B4 @ =0x000006B6
	add r1, r8
	ldrh r0, [r1]
	subs r0, #0x28
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _081BB1B8
	movs r0, #1
	strb r0, [r3]
	strh r2, [r1]
	b _081BB4D4
	.align 2, 0
_081BB1B0: .4byte 0x000006C1
_081BB1B4: .4byte 0x000006B6
_081BB1B8:
	movs r3, #0
	ldrsh r5, [r1, r3]
	ldr r4, _081BB258 @ =gSineTable
	ldr r0, _081BB25C @ =0x000006C5
	add r0, r8
	ldrb r2, [r0]
	adds r0, r2, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r7, #0
	ldrsh r0, [r0, r7]
	adds r1, r5, #0
	muls r1, r0, r1
	lsrs r1, r1, #0x10
	ldr r3, _081BB260 @ =0xFFFF0000
	adds r0, r3, #0
	ldr r7, [sp, #0x20]
	ands r0, r7
	orrs r0, r1
	str r0, [sp, #0x20]
	lsls r2, r2, #1
	adds r2, r2, r4
	movs r1, #0
	ldrsh r0, [r2, r1]
	adds r1, r5, #0
	muls r1, r0, r1
	lsrs r1, r1, #0x10
	adds r0, r3, #0
	ldr r2, [sp, #0x24]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x24]
	ldr r0, [r6, #8]
	ldr r1, [r6, #0xc]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	add r2, sp, #8
	mov r7, sp
	ldrh r0, [r7, #0x20]
	ldrh r1, [r2]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #8]
	ands r1, r3
	orrs r1, r0
	str r1, [sp, #8]
	ldrh r0, [r7, #0x24]
	ldrh r7, [r2, #4]
	adds r0, r0, r7
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [r2, #4]
	ands r1, r3
	orrs r1, r0
	str r1, [r2, #4]
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r3, #0
	blt _081BB252
	cmp r1, #0
	blt _081BB252
	ldr r0, _081BB264 @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _081BB252
	ldr r0, _081BB268 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081BB26C
_081BB252:
	movs r1, #0
	b _081BB27A
	.align 2, 0
_081BB258: .4byte gSineTable
_081BB25C: .4byte 0x000006C5
_081BB260: .4byte 0xFFFF0000
_081BB264: .4byte 0x030046A8
_081BB268: .4byte 0x030046AC
_081BB26C:
	ldr r0, _081BB298 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r3
_081BB27A:
	ldr r2, _081BB29C @ =0x00000256
	adds r0, r6, r2
	ldrh r0, [r0]
	cmp r0, r1
	beq _081BB2A8
	ldr r1, _081BB2A0 @ =0x000006B6
	add r1, r8
	movs r0, #0
	strh r0, [r1]
	ldr r1, _081BB2A4 @ =0x000006C1
	add r1, r8
	movs r0, #1
	strb r0, [r1]
	b _081BB454
	.align 2, 0
_081BB298: .4byte 0x030046A4
_081BB29C: .4byte 0x00000256
_081BB2A0: .4byte 0x000006B6
_081BB2A4: .4byte 0x000006C1
_081BB2A8:
	mov r3, sp
	ldrh r0, [r3, #0x20]
	ldrh r7, [r6, #0x10]
	adds r0, r0, r7
	strh r0, [r6, #0x10]
	ldrh r0, [r3, #0x24]
	ldrh r1, [r6, #0x14]
	adds r0, r0, r1
	strh r0, [r6, #0x14]
	b _081BB454
_081BB2BC:
	cmp r2, #1
	beq _081BB2C2
	b _081BB3F0
_081BB2C2:
	ldr r2, _081BB308 @ =0x00000256
	adds r0, r6, r2
	ldrh r5, [r0]
	add r7, sp, #0x10
	ldr r3, _081BB30C @ =0x030046A4
	mov sb, r3
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	mov r3, sb
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	str r0, [sp, #0x28]
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r7]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	adds r4, r7, #0
	cmp r0, #0
	beq _081BB310
	adds r0, #4
	b _081BB31C
	.align 2, 0
_081BB308: .4byte 0x00000256
_081BB30C: .4byte 0x030046A4
_081BB310:
	mov r3, sb
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081BB31C:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r7, #2]
	ldr r1, [sp, #0x28]
	lsls r0, r1, #8
	adds r0, #0x80
	strh r0, [r7, #4]
	add r2, sp, #0x18
	adds r3, r6, #0
	adds r3, #8
	add r0, sp, #0x10
	ldrh r0, [r0]
	ldrh r1, [r6, #8]
	subs r0, r0, r1
	strh r0, [r2]
	ldrh r0, [r4, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r4, #4]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	ldr r0, _081BB364 @ =0x000006C5
	add r0, r8
	ldrb r0, [r0]
	lsrs r0, r0, #6
	cmp r0, #1
	beq _081BB39E
	cmp r0, #1
	bgt _081BB368
	cmp r0, #0
	beq _081BB372
	b _081BB3C8
	.align 2, 0
_081BB364: .4byte 0x000006C5
_081BB368:
	cmp r0, #2
	beq _081BB372
	cmp r0, #3
	beq _081BB39E
	b _081BB3C8
_081BB372:
	movs r0, #0
	strh r0, [r2, #4]
	add r0, sp, #0x18
	ldrh r3, [r0]
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp r0, #8
	ble _081BB38A
	movs r0, #8
	mov r1, sl
	strh r0, [r1, #0x10]
	b _081BB3C8
_081BB38A:
	movs r1, #8
	rsbs r1, r1, #0
	cmp r0, r1
	bge _081BB398
	mov r3, sl
	strh r1, [r3, #0x10]
	b _081BB3C8
_081BB398:
	mov r7, sl
	strh r3, [r7, #0x10]
	b _081BB3C8
_081BB39E:
	movs r0, #0
	strh r0, [r2]
	add r0, sp, #0x18
	ldrh r3, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	cmp r0, #8
	ble _081BB3B6
	movs r0, #8
	mov r3, sl
	strh r0, [r3, #0x14]
	b _081BB3C8
_081BB3B6:
	movs r1, #8
	rsbs r1, r1, #0
	cmp r0, r1
	bge _081BB3C4
	mov r7, sl
	strh r1, [r7, #0x14]
	b _081BB3C8
_081BB3C4:
	mov r0, sl
	strh r3, [r0, #0x14]
_081BB3C8:
	movs r1, #0
	ldrsh r0, [r2, r1]
	add r1, sp, #0x18
	movs r2, #4
	ldrsh r1, [r1, r2]
	adds r2, r0, r1
	cmp r2, #0
	bne _081BB454
	ldr r0, _081BB3E8 @ =0x000006C1
	add r0, r8
	movs r1, #2
	strb r1, [r0]
	ldr r0, _081BB3EC @ =0x000006C3
	add r0, r8
	strb r2, [r0]
	b _081BB4D4
	.align 2, 0
_081BB3E8: .4byte 0x000006C1
_081BB3EC: .4byte 0x000006C3
_081BB3F0:
	ldr r4, _081BB440 @ =0x000006C3
	add r4, r8
	ldrb r0, [r4]
	adds r0, #1
	movs r5, #0
	strb r0, [r4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xf
	bls _081BB454
	movs r2, #0xda
	lsls r2, r2, #3
	add r2, r8
	movs r0, #0xd9
	lsls r0, r0, #3
	add r0, r8
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	mov r0, r8
	bl GolemLink_RouteTo
	ldr r2, _081BB444 @ =0x000006C2
	add r2, r8
	ldrb r1, [r2]
	ldr r0, _081BB448 @ =0x000006C4
	add r0, r8
	strb r1, [r0]
	ldrb r0, [r2]
	strb r0, [r6, #5]
	ldr r3, _081BB44C @ =0x0000046B
	adds r1, r6, r3
	movs r0, #1
	strb r0, [r1]
	strb r5, [r4]
	ldr r0, _081BB450 @ =0x000006B6
	add r0, r8
	strh r5, [r0]
	b _081BB4D4
	.align 2, 0
_081BB440: .4byte 0x000006C3
_081BB444: .4byte 0x000006C2
_081BB448: .4byte 0x000006C4
_081BB44C: .4byte 0x0000046B
_081BB450: .4byte 0x000006B6
_081BB454:
	movs r0, #0xd7
	lsls r0, r0, #3
	add r0, r8
	ldrh r0, [r0]
	lsrs r0, r0, #7
	ldr r7, _081BB47C @ =0x00000482
	adds r1, r6, r7
	strh r0, [r1]
	ldr r1, _081BB480 @ =0x0000A02F
	ldr r2, [sp, #0x2c]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081BB484
	adds r3, r7, #0
	adds r1, r6, r3
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _081BB494
	.align 2, 0
_081BB47C: .4byte 0x00000482
_081BB480: .4byte 0x0000A02F
_081BB484:
	ldr r7, _081BB4B8 @ =0x00000482
	adds r0, r6, r7
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _081BB494
	movs r0, #1
	strh r0, [r2]
_081BB494:
	ldr r1, [sp, #0x30]
	ldrb r0, [r1]
	cmp r0, #0
	bne _081BB4BC
	ldr r4, [r6, #0x44]
	adds r4, #0x48
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl AuxAnim_SetAnimSpeed
	b _081BB4D4
	.align 2, 0
_081BB4B8: .4byte 0x00000482
_081BB4BC:
	ldr r4, [r6, #0x44]
	adds r4, #0x20
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl MainSprite_SetAnimSpeed
_081BB4D4:
	add sp, #0x34
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
