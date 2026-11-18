	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r5, r0, #0
	mov r8, r5
	ldr r0, _081C801C @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081C8020
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081C8022
	.align 2, 0
_081C801C: .4byte 0x0000046D
_081C8020:
	movs r0, #0
_081C8022:
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r1, r1, r5
	mov sb, r1
	cmp r0, #0
	bne _081C8030
	b _081C84B6
_081C8030:
	ldrb r0, [r5, #5]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r0, r1
	lsls r0, r0, #6
	subs r0, #0x40
	strb r0, [r5, #5]
	ldrb r0, [r5, #5]
	adds r0, #0x20
	ands r0, r2
	asrs r0, r0, #6
	adds r2, r0, #1
	ands r2, r1
	ldr r3, _081C8080 @ =0x0000046A
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #6
	beq _081C8084
	movs r1, #0x90
	lsls r1, r1, #3
	mov r3, sb
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	bne _081C8084
	mov r1, r8
	ldr r0, [r1, #0x24]
	ldr r0, [r0, #8]
	ldrh r0, [r0, #4]
	lsrs r1, r0, #0xc
	movs r3, #0xee
	lsls r3, r3, #1
	adds r0, r5, r3
	strb r1, [r0]
	b _081C808C
	.align 2, 0
_081C8080: .4byte 0x0000046A
_081C8084:
	movs r1, #0xee
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r1, [r0]
_081C808C:
	cmp r1, #0
	blt _081C8094
	asrs r0, r1, #1
	b _081C809A
_081C8094:
	rsbs r0, r1, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_081C809A:
	cmp r2, r0
	bne _081C8126
	ldr r2, _081C810C @ =0x0000046B
	adds r0, r5, r2
	movs r6, #0
	movs r4, #1
	strb r4, [r0]
	movs r1, #0x80
	lsls r1, r1, #3
	mov r3, sb
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _081C811C
	adds r0, r5, #0
	movs r1, #0
	bl Enemy_PlayAnim
	movs r1, #3
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r1, [r0]
	ldr r3, _081C8110 @ =0x00000469
	adds r0, r5, r3
	strb r4, [r0]
	ldr r1, _081C8114 @ =0x0000046A
	adds r0, r5, r1
	strb r6, [r0]
	adds r2, #0x1c
	adds r0, r5, r2
	str r6, [r0]
	adds r3, #3
	adds r0, r5, r3
	strb r4, [r0]
	ldr r1, _081C8118 @ =0x000005BC
	adds r0, r5, r1
	ldr r2, [r0]
	movs r1, #0x1b
	adds r3, #1
	adds r0, r5, r3
	strb r4, [r0]
	subs r3, #2
	adds r0, r5, r3
	strb r6, [r0]
	adds r3, #0xe8
	adds r0, r5, r3
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r6, [r0]
	b _081C8680
	.align 2, 0
_081C810C: .4byte 0x0000046B
_081C8110: .4byte 0x00000469
_081C8114: .4byte 0x0000046A
_081C8118: .4byte 0x000005BC
_081C811C:
	adds r0, r5, #0
	movs r1, #0
	bl Enemy_PlayAnim
	b _081C8680
_081C8126:
	cmp r2, #1
	beq _081C81E4
	cmp r2, #1
	bgt _081C8134
	cmp r2, #0
	beq _081C8142
	b _081C84AE
_081C8134:
	cmp r2, #2
	bne _081C813A
	b _081C82BC
_081C813A:
	cmp r2, #3
	bne _081C8140
	b _081C838C
_081C8140:
	b _081C84AE
_081C8142:
	subs r0, r1, #2
	cmp r0, #3
	bhi _081C8194
	movs r2, #0xd
	ldr r3, _081C8168 @ =0x0000025D
	adds r0, r5, r3
	ldrb r3, [r0]
	cmp r3, #0
	bne _081C8170
	ldr r1, _081C816C @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r3, [sp]
	movs r3, #1
	b _081C83AE
	.align 2, 0
_081C8168: .4byte 0x0000025D
_081C816C: .4byte 0x000004B7
_081C8170:
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	movs r2, #0xe
	ldr r3, _081C818C @ =0x000004B7
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _081C8190 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #0xe
	beq _081C818A
	b _081C83EA
_081C818A:
	b _081C83DA
	.align 2, 0
_081C818C: .4byte 0x000004B7
_081C8190: .4byte 0x0000046E
_081C8194:
	movs r2, #0xd
	ldr r1, _081C81B8 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081C81C0
	ldr r3, _081C81BC @ =0x000004B7
	adds r0, r5, r3
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r2, #1
	str r2, [sp]
	movs r2, #0xd
	movs r3, #0
	b _081C8446
	.align 2, 0
_081C81B8: .4byte 0x0000025D
_081C81BC: .4byte 0x000004B7
_081C81C0:
	ldr r0, [r5, #0x44]
	adds r7, r0, #0
	adds r7, #0x20
	ldr r1, _081C81DC @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _081C81E0 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #0xd
	beq _081C81D8
	b _081C8484
_081C81D8:
	b _081C8474
	.align 2, 0
_081C81DC: .4byte 0x000004B7
_081C81E0: .4byte 0x0000046E
_081C81E4:
	subs r0, r1, #4
	cmp r0, #3
	bhi _081C8238
	movs r2, #0xd
	ldr r3, _081C820C @ =0x0000025D
	adds r0, r5, r3
	ldrb r3, [r0]
	cmp r3, #0
	bne _081C8214
	ldr r1, _081C8210 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r3, [sp]
	movs r3, #2
	b _081C83AE
	.align 2, 0
_081C820C: .4byte 0x0000025D
_081C8210: .4byte 0x000004B7
_081C8214:
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	movs r2, #0xf
	ldr r3, _081C8230 @ =0x000004B7
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _081C8234 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #0xf
	beq _081C822E
	b _081C83EA
_081C822E:
	b _081C83DA
	.align 2, 0
_081C8230: .4byte 0x000004B7
_081C8234: .4byte 0x0000046E
_081C8238:
	movs r2, #0xd
	ldr r1, _081C8260 @ =0x0000025D
	adds r0, r5, r1
	ldrb r3, [r0]
	cmp r3, #0
	bne _081C826C
	ldr r1, _081C8264 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r3, [sp]
	movs r3, #3
	bl AuxAnim_SetAnim
	ldr r2, _081C8268 @ =0x0000046E
	adds r6, r5, r2
	b _081C849C
	.align 2, 0
_081C8260: .4byte 0x0000025D
_081C8264: .4byte 0x000004B7
_081C8268: .4byte 0x0000046E
_081C826C:
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	movs r2, #0x10
	ldr r3, _081C82B4 @ =0x000004B7
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _081C82B8 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #0x10
	bne _081C8296
	ldrb r0, [r6]
	cmp r0, #0
	bne _081C8296
	ldr r0, [r4, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _081C8296
	b _081C84A0
_081C8296:
	strb r2, [r3]
	movs r3, #4
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r3, [sp]
	movs r3, #2
	bl MainSprite_SetAnim
	ldr r0, [r4, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
	b _081C849C
	.align 2, 0
_081C82B4: .4byte 0x000004B7
_081C82B8: .4byte 0x0000046E
_081C82BC:
	subs r0, r1, #1
	cmp r0, #4
	bls _081C833C
	movs r2, #0xd
	ldr r3, _081C82E8 @ =0x0000025D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _081C82F0
	ldr r1, _081C82EC @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r2, #1
	str r2, [sp]
	movs r2, #0xd
	movs r3, #3
	b _081C83AE
	.align 2, 0
_081C82E8: .4byte 0x0000025D
_081C82EC: .4byte 0x000004B7
_081C82F0:
	ldr r0, [r5, #0x44]
	adds r7, r0, #0
	adds r7, #0x20
	movs r2, #0x10
	ldr r3, _081C8334 @ =0x000004B7
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _081C8338 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #0x10
	bne _081C831A
	ldrb r0, [r6]
	cmp r0, #0
	bne _081C831A
	ldr r0, [r7, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _081C831A
	b _081C840A
_081C831A:
	strb r2, [r3]
	movs r4, #4
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r4, [sp]
	movs r3, #2
	bl MainSprite_SetAnim
	ldr r0, [r7, #8]
	orrs r0, r4
	str r0, [r7, #8]
	b _081C8406
	.align 2, 0
_081C8334: .4byte 0x000004B7
_081C8338: .4byte 0x0000046E
_081C833C:
	movs r2, #0xd
	ldr r1, _081C8360 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081C8368
	ldr r3, _081C8364 @ =0x000004B7
	adds r0, r5, r3
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r2, #1
	str r2, [sp]
	movs r2, #0xd
	movs r3, #2
	b _081C8446
	.align 2, 0
_081C8360: .4byte 0x0000025D
_081C8364: .4byte 0x000004B7
_081C8368:
	ldr r0, [r5, #0x44]
	adds r7, r0, #0
	adds r7, #0x20
	movs r2, #0xf
	ldr r1, _081C8384 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _081C8388 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #0xf
	beq _081C8382
	b _081C8484
_081C8382:
	b _081C8474
	.align 2, 0
_081C8384: .4byte 0x000004B7
_081C8388: .4byte 0x0000046E
_081C838C:
	cmp r1, #3
	bhi _081C8424
	movs r2, #0xd
	ldr r3, _081C83B8 @ =0x0000025D
	adds r0, r5, r3
	ldrb r3, [r0]
	cmp r3, #0
	bne _081C83C4
	ldr r1, _081C83BC @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r3, [sp]
	movs r3, #0
_081C83AE:
	bl AuxAnim_SetAnim
	ldr r2, _081C83C0 @ =0x0000046E
	adds r6, r5, r2
	b _081C8406
	.align 2, 0
_081C83B8: .4byte 0x0000025D
_081C83BC: .4byte 0x000004B7
_081C83C0: .4byte 0x0000046E
_081C83C4:
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	ldr r3, _081C841C @ =0x000004B7
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _081C8420 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #0xd
	bne _081C83EA
_081C83DA:
	ldrb r0, [r6]
	cmp r0, #0
	bne _081C83EA
	ldr r0, [r4, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _081C840A
_081C83EA:
	strb r2, [r3]
	movs r3, #4
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r3, [sp]
	movs r3, #2
	bl MainSprite_SetAnim
	ldr r0, [r4, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
_081C8406:
	movs r0, #0
	strb r0, [r6]
_081C840A:
	movs r2, #0x80
	lsls r2, r2, #9
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r5, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _081C84AE
	.align 2, 0
_081C841C: .4byte 0x000004B7
_081C8420: .4byte 0x0000046E
_081C8424:
	movs r2, #0xd
	ldr r1, _081C8450 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081C845C
	ldr r3, _081C8454 @ =0x000004B7
	adds r0, r5, r3
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r2, #1
	str r2, [sp]
	movs r2, #0xd
	movs r3, #1
_081C8446:
	bl AuxAnim_SetAnim
	ldr r0, _081C8458 @ =0x0000046E
	adds r6, r5, r0
	b _081C849C
	.align 2, 0
_081C8450: .4byte 0x0000025D
_081C8454: .4byte 0x000004B7
_081C8458: .4byte 0x0000046E
_081C845C:
	ldr r0, [r5, #0x44]
	adds r7, r0, #0
	adds r7, #0x20
	movs r2, #0xe
	ldr r1, _081C84DC @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _081C84E0 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #0xe
	bne _081C8484
_081C8474:
	ldrb r0, [r6]
	cmp r0, #0
	bne _081C8484
	ldr r0, [r7, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _081C84A0
_081C8484:
	strb r2, [r3]
	movs r4, #4
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r4, [sp]
	movs r3, #2
	bl MainSprite_SetAnim
	ldr r0, [r7, #8]
	orrs r0, r4
	str r0, [r7, #8]
_081C849C:
	movs r0, #0
	strb r0, [r6]
_081C84A0:
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r2, r5, r1
	ldr r1, _081C84E4 @ =0xFFFEFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_081C84AE:
	ldr r2, _081C84E0 @ =0x0000046E
	adds r1, r5, r2
	movs r0, #0
	strb r0, [r1]
_081C84B6:
	ldr r0, [r5, #0x44]
	adds r0, #0x48
	ldrh r0, [r0, #0xe]
	cmp r0, #1
	bne _081C84F0
	movs r1, #0x80
	lsls r1, r1, #9
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081C84E8
	mov r1, r8
	ldrb r0, [r1, #5]
	adds r0, #0x20
	strb r0, [r1, #5]
	b _081C84F0
	.align 2, 0
_081C84DC: .4byte 0x000004B7
_081C84E0: .4byte 0x0000046E
_081C84E4: .4byte 0xFFFEFFFF
_081C84E8:
	mov r2, r8
	ldrb r0, [r2, #5]
	subs r0, #0x20
	strb r0, [r2, #5]
_081C84F0:
	ldr r3, _081C8520 @ =0x00000482
	adds r2, r5, r3
	ldrh r6, [r2]
	movs r1, #0x80
	mov r3, sb
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _081C8506
	movs r0, #3
	strh r0, [r2]
_081C8506:
	ldr r1, _081C8524 @ =0x0000A02F
	mov r2, sb
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081C8528
	ldr r3, _081C8520 @ =0x00000482
	adds r1, r5, r3
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _081C8538
	.align 2, 0
_081C8520: .4byte 0x00000482
_081C8524: .4byte 0x0000A02F
_081C8528:
	ldr r1, _081C855C @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _081C8538
	movs r0, #1
	strh r0, [r2]
_081C8538:
	ldr r3, _081C8560 @ =0x0000025D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _081C8564
	ldr r4, [r5, #0x44]
	adds r4, #0x48
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl AuxAnim_SetAnimSpeed
	b _081C857C
	.align 2, 0
_081C855C: .4byte 0x00000482
_081C8560: .4byte 0x0000025D
_081C8564:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl MainSprite_SetAnimSpeed
_081C857C:
	ldr r1, _081C8638 @ =0x00000482
	adds r0, r5, r1
	movs r7, #0
	movs r2, #0
	mov r8, r2
	strh r6, [r0]
	ldr r3, _081C863C @ =0x0000046E
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _081C8680
	ldrb r0, [r5, #5]
	adds r0, #0x10
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r0, r1
	movs r3, #0xee
	lsls r3, r3, #1
	adds r1, r5, r3
	ldrb r1, [r1]
	subs r1, r1, r0
	cmp r1, #0
	bge _081C85B2
	rsbs r1, r1, #0
_081C85B2:
	cmp r1, #0
	bgt _081C8650
	ldr r1, _081C8640 @ =0x0000046B
	adds r0, r5, r1
	movs r4, #1
	strb r4, [r0]
	ldrb r0, [r5, #5]
	adds r0, #0x20
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r6, #3
	ands r0, r6
	lsls r0, r0, #6
	subs r0, #0x40
	strb r0, [r5, #5]
	adds r0, r5, #0
	movs r1, #0
	bl Enemy_PlayAnim
	movs r1, #0x80
	lsls r1, r1, #3
	mov r2, sb
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081C8680
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r6, [r0]
	adds r1, #0x69
	adds r0, r5, r1
	strb r4, [r0]
	ldr r2, _081C8644 @ =0x0000046A
	adds r0, r5, r2
	strb r7, [r0]
	adds r3, #0x1c
	adds r0, r5, r3
	mov r1, r8
	str r1, [r0]
	adds r2, #2
	adds r0, r5, r2
	strb r4, [r0]
	ldr r3, _081C8648 @ =0x000005BC
	adds r0, r5, r3
	ldr r2, [r0]
	movs r1, #0x1b
	ldr r3, _081C864C @ =0x0000046D
	adds r0, r5, r3
	strb r4, [r0]
	subs r3, #2
	adds r0, r5, r3
	strb r7, [r0]
	adds r3, #0xe8
	adds r0, r5, r3
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	mov r3, r8
	strh r3, [r0]
	b _081C8680
	.align 2, 0
_081C8638: .4byte 0x00000482
_081C863C: .4byte 0x0000046E
_081C8640: .4byte 0x0000046B
_081C8644: .4byte 0x0000046A
_081C8648: .4byte 0x000005BC
_081C864C: .4byte 0x0000046D
_081C8650:
	movs r1, #0xb2
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r3, [r0]
	movs r2, #2
	ldr r0, _081C8690 @ =0x0000046D
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081C8694 @ =0x0000046B
	adds r0, r5, r1
	strb r7, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r5, r2
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	mov r1, r8
	strh r1, [r0]
_081C8680:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081C8690: .4byte 0x0000046D
_081C8694: .4byte 0x0000046B
