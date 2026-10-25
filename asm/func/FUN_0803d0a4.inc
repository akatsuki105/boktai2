	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r7, r0, #0
	adds r5, r7, #0
	adds r6, r7, #0
	adds r6, #0x48
	bl FUN_08022ec0
	adds r0, r7, #0
	bl FUN_0803c8b4
	movs r0, #0xb9
	lsls r0, r0, #1
	adds r3, r7, r0
	ldrh r0, [r3]
	cmp r0, #0
	beq _0803D0E0
	movs r2, #4
	adds r1, r7, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldrh r0, [r3]
	subs r0, #1
	strh r0, [r3]
_0803D0E0:
	movs r1, #0xe8
	lsls r1, r1, #1
	adds r4, r7, r1
	movs r2, #4
	adds r1, r7, #0
	adds r1, #0x98
	ldr r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _0803D100
	ldrh r1, [r4, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r4, #6]
	b _0803D120
_0803D100:
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r4, #6]
	ands r0, r1
	strh r0, [r4, #6]
	movs r2, #0xdb
	lsls r2, r2, #2
	adds r1, r7, r2
	adds r0, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	ldrb r1, [r6, #5]
	ldr r3, _0803D180 @ =0x00000212
	adds r0, r7, r3
	strb r1, [r0]
_0803D120:
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r4, r5, r0
	movs r0, #8
	mov r2, sl
	ldr r1, [r2]
	ands r0, r1
	cmp r0, #0
	bne _0803D1EC
	movs r3, #0x80
	lsls r3, r3, #0xf
	ands r3, r1
	cmp r3, #0
	beq _0803D18C
	movs r3, #0xb5
	lsls r3, r3, #2
	adds r0, r5, r3
	movs r2, #0
	ldrsh r1, [r0, r2]
	subs r3, #0x1e
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803D15C
	ldr r2, _0803D184 @ =0x000002C6
	adds r0, r5, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r1, r0
	asrs r1, r0, #6
_0803D15C:
	ldr r2, _0803D188 @ =0x000002D6
	adds r0, r5, r2
	movs r3, #0
	ldrsh r2, [r0, r3]
	movs r0, #0x80
	lsls r0, r0, #0xa
	str r0, [sp]
	movs r3, #0xb7
	lsls r3, r3, #2
	adds r0, r5, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r3, #0
	bl Hitbox_SetAttack
	b _0803D1D0
	.align 2, 0
_0803D180: .4byte 0x00000212
_0803D184: .4byte 0x000002C6
_0803D188: .4byte 0x000002D6
_0803D18C:
	movs r1, #0xb2
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r2, _0803D298 @ =0x000002B6
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803D1AC
	adds r2, #0x10
	adds r0, r5, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r1, r0
	asrs r1, r0, #6
_0803D1AC:
	ldr r0, _0803D29C @ =0x000002CA
	adds r0, r0, r5
	mov r8, r0
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov r8, r0
	str r3, [sp]
	movs r3, #0xb3
	lsls r3, r3, #2
	adds r0, r5, r3
	movs r2, #0
	ldrsh r0, [r0, r2]
	str r0, [sp, #4]
	adds r0, r4, #0
	mov r2, r8
	movs r3, #0
	bl Hitbox_SetAttack
_0803D1D0:
	movs r3, #0xdb
	lsls r3, r3, #2
	adds r1, r5, r3
	adds r0, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	ldrb r0, [r6, #5]
	adds r1, r4, #0
	adds r1, #0x42
	strb r0, [r1]
	adds r0, r4, #0
	bl Hitbox_Register
_0803D1EC:
	movs r0, #0x88
	lsls r0, r0, #2
	adds r4, r5, r0
	movs r1, #0x80
	lsls r1, r1, #0xd
	mov r2, sl
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0803D26A
	ldr r3, _0803D2A0 @ =0x000002CE
	adds r0, r5, r3
	movs r2, #0
	ldrsh r1, [r0, r2]
	subs r3, #0x18
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803D21E
	ldr r2, _0803D2A4 @ =0x000002C6
	adds r0, r5, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r1, r0
	asrs r1, r0, #6
_0803D21E:
	movs r2, #0xb4
	lsls r2, r2, #2
	adds r0, r5, r2
	movs r3, #0
	ldrsh r2, [r0, r3]
	movs r0, #0xc0
	lsls r0, r0, #0xb
	str r0, [sp]
	ldr r3, _0803D2A8 @ =0x000002D2
	adds r0, r5, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r3, #0
	bl Hitbox_SetAttack
	adds r0, r5, #0
	add r1, sp, #8
	bl FUN_0803c274
	adds r0, r4, #0
	add r1, sp, #8
	movs r2, #0
	bl Hitbox_SetPos
	ldrb r0, [r6, #5]
	subs r0, #0x20
	movs r1, #0x40
	rsbs r1, r1, #0
	ands r0, r1
	adds r0, #0x40
	ldr r2, _0803D2AC @ =0x00000262
	adds r1, r5, r2
	strb r0, [r1]
	adds r0, r4, #0
	bl Hitbox_Register
_0803D26A:
	movs r1, #0x10
	mov r3, sl
	ldr r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _0803D2B4
	movs r0, #0xd3
	lsls r0, r0, #2
	adds r2, r5, r0
	ldr r0, [r2, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #8]
	movs r1, #0xeb
	lsls r1, r1, #2
	adds r0, r5, r1
	bl AuxShadow_Hide
	ldr r1, _0803D2B0 @ =0xFFDFFFFF
	mov r2, sl
	ldr r0, [r2]
	ands r0, r1
	b _0803D2F0
	.align 2, 0
_0803D298: .4byte 0x000002B6
_0803D29C: .4byte 0x000002CA
_0803D2A0: .4byte 0x000002CE
_0803D2A4: .4byte 0x000002C6
_0803D2A8: .4byte 0x000002D2
_0803D2AC: .4byte 0x00000262
_0803D2B0: .4byte 0xFFDFFFFF
_0803D2B4:
	movs r3, #0xd3
	lsls r3, r3, #2
	adds r2, r5, r3
	ldr r0, [r2, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2, #8]
	movs r1, #0x80
	lsls r1, r1, #9
	mov r2, sl
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0803D2DC
	adds r3, #0x60
	adds r0, r5, r3
	bl AuxShadow_Hide
	b _0803D2E6
_0803D2DC:
	movs r1, #0xeb
	lsls r1, r1, #2
	adds r0, r5, r1
	bl AuxShadow_Show
_0803D2E6:
	movs r1, #0x80
	lsls r1, r1, #0xe
	mov r2, sl
	ldr r0, [r2]
	orrs r0, r1
_0803D2F0:
	str r0, [r2]
	movs r3, #0xb8
	lsls r3, r3, #1
	adds r1, r5, r3
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	ble _0803D330
	subs r0, r2, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0803D30E
	b _0803D566
_0803D30E:
	adds r0, r5, #0
	bl FUN_0803c1bc
	adds r1, r0, #0
	cmp r1, #0
	beq _0803D408
	ldr r0, _0803D32C @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	movs r3, #0xe5
	lsls r3, r3, #2
	adds r1, r5, r3
	str r0, [r1]
	b _0803D566
	.align 2, 0
_0803D32C: .4byte 0x03003584
_0803D330:
	ldr r0, _0803D390 @ =0x00000818
	adds r0, r0, r5
	mov sb, r0
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _0803D39C
	adds r0, r5, #0
	bl FUN_0803c1bc
	adds r1, r0, #0
	ldr r0, _0803D394 @ =0x03003584
	lsls r1, r1, #5
	ldr r2, [r0]
	adds r1, r2, r1
	ldr r3, _0803D398 @ =0x0000081A
	adds r0, r5, r3
	ldrh r0, [r0]
	lsls r0, r0, #5
	adds r2, r2, r0
	movs r0, #0xc3
	lsls r0, r0, #3
	adds r4, r5, r0
	subs r3, #1
	adds r6, r5, r3
	movs r3, #0
	ldrsb r3, [r6, r3]
	movs r0, #5
	str r0, [sp]
	adds r0, r4, #0
	bl BlendPltt
	movs r1, #0xe5
	lsls r1, r1, #2
	adds r0, r5, r1
	str r4, [r0]
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x1e
	bgt _0803D38A
	b _0803D566
_0803D38A:
	movs r0, #0x1f
	strb r0, [r6]
	b _0803D566
	.align 2, 0
_0803D390: .4byte 0x00000818
_0803D394: .4byte 0x03003584
_0803D398: .4byte 0x0000081A
_0803D39C:
	cmp r0, #1
	bne _0803D43C
	adds r0, r5, #0
	bl FUN_0803c1bc
	adds r1, r0, #0
	lsls r1, r1, #5
	ldr r3, _0803D418 @ =0x03003584
	ldr r2, [r3]
	adds r1, r2, r1
	ldr r0, _0803D41C @ =0x0000081A
	adds r0, r0, r5
	mov r8, r0
	ldrh r0, [r0]
	lsls r0, r0, #5
	adds r2, r2, r0
	movs r3, #0xc3
	lsls r3, r3, #3
	adds r4, r5, r3
	ldr r0, _0803D420 @ =0x00000819
	adds r6, r5, r0
	movs r3, #0
	ldrsb r3, [r6, r3]
	movs r0, #5
	str r0, [sp]
	adds r0, r4, #0
	bl BlendPltt
	movs r1, #0xe5
	lsls r1, r1, #2
	adds r0, r5, r1
	str r4, [r0]
	ldrb r0, [r6]
	subs r0, #1
	strb r0, [r6]
	lsls r0, r0, #0x18
	cmp r0, #0
	ble _0803D3EA
	b _0803D566
_0803D3EA:
	movs r0, #0
	strb r0, [r6]
	movs r0, #0xff
	mov r2, sb
	strb r0, [r2]
	adds r0, r5, #0
	bl FUN_0803c1bc
	mov r3, r8
	strh r0, [r3]
	adds r0, r5, #0
	bl FUN_0803c1bc
	cmp r0, #0
	bne _0803D424
_0803D408:
	movs r0, #0xe5
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r2, #0x83
	lsls r2, r2, #3
	adds r0, r5, r2
	str r0, [r1]
	b _0803D566
	.align 2, 0
_0803D418: .4byte 0x03003584
_0803D41C: .4byte 0x0000081A
_0803D420: .4byte 0x00000819
_0803D424:
	lsls r0, r0, #5
	ldr r3, _0803D438 @ =0x03003584
	ldr r1, [r3]
	adds r1, r1, r0
	movs r2, #0xe5
	lsls r2, r2, #2
	adds r0, r5, r2
	str r1, [r0]
	b _0803D566
	.align 2, 0
_0803D438: .4byte 0x03003584
_0803D43C:
	cmp r0, #2
	bne _0803D4E8
	adds r0, r5, #0
	bl FUN_0803c1bc
	adds r1, r0, #0
	lsls r1, r1, #5
	ldr r3, _0803D4C0 @ =0x03003584
	ldr r2, [r3]
	adds r1, r2, r1
	ldr r0, _0803D4C4 @ =0x0000081A
	adds r0, r0, r5
	mov r8, r0
	ldrh r0, [r0]
	lsls r0, r0, #5
	adds r2, r2, r0
	movs r3, #0xc3
	lsls r3, r3, #3
	adds r4, r5, r3
	ldr r0, _0803D4C8 @ =0x00000819
	adds r6, r5, r0
	movs r3, #0
	ldrsb r3, [r6, r3]
	movs r0, #5
	str r0, [sp]
	adds r0, r4, #0
	bl BlendPltt
	movs r1, #0xe5
	lsls r1, r1, #2
	adds r0, r5, r1
	str r4, [r0]
	ldr r2, _0803D4CC @ =0x0000081E
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803D530
	ldrb r0, [r6]
	subs r0, #1
	strb r0, [r6]
	lsls r0, r0, #0x18
	cmp r0, #0
	bgt _0803D566
	movs r0, #0
	strb r0, [r6]
	movs r0, #0xff
	mov r3, sb
	strb r0, [r3]
	adds r0, r5, #0
	bl FUN_0803c1bc
	mov r1, r8
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_0803c1bc
	cmp r0, #0
	bne _0803D4D0
	movs r2, #0xe5
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r3, #0x83
	lsls r3, r3, #3
	adds r0, r5, r3
	str r0, [r1]
	b _0803D566
	.align 2, 0
_0803D4C0: .4byte 0x03003584
_0803D4C4: .4byte 0x0000081A
_0803D4C8: .4byte 0x00000819
_0803D4CC: .4byte 0x0000081E
_0803D4D0:
	lsls r0, r0, #5
	ldr r2, _0803D4E4 @ =0x03003584
	ldr r1, [r2]
	adds r1, r1, r0
	movs r3, #0xe5
	lsls r3, r3, #2
	adds r0, r5, r3
	str r1, [r0]
	b _0803D566
	.align 2, 0
_0803D4E4: .4byte 0x03003584
_0803D4E8:
	cmp r0, #3
	bne _0803D566
	adds r0, r5, #0
	bl FUN_0803c1bc
	adds r1, r0, #0
	ldr r0, _0803D548 @ =0x03003584
	lsls r1, r1, #5
	ldr r2, [r0]
	adds r1, r2, r1
	ldr r3, _0803D54C @ =0x0000081A
	adds r0, r5, r3
	ldrh r0, [r0]
	lsls r0, r0, #5
	adds r2, r2, r0
	movs r0, #0xc3
	lsls r0, r0, #3
	adds r4, r5, r0
	subs r3, #1
	adds r6, r5, r3
	movs r3, #0
	ldrsb r3, [r6, r3]
	movs r0, #5
	str r0, [sp]
	adds r0, r4, #0
	bl BlendPltt
	movs r1, #0xe5
	lsls r1, r1, #2
	adds r0, r5, r1
	str r4, [r0]
	ldr r2, _0803D550 @ =0x0000081E
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	bne _0803D554
_0803D530:
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x1e
	ble _0803D566
	movs r0, #0x1f
	strb r0, [r6]
	movs r0, #1
	strb r0, [r1]
	b _0803D566
	.align 2, 0
_0803D548: .4byte 0x03003584
_0803D54C: .4byte 0x0000081A
_0803D550: .4byte 0x0000081E
_0803D554:
	ldrb r0, [r6]
	subs r0, #1
	movs r2, #0
	strb r0, [r6]
	lsls r0, r0, #0x18
	cmp r0, #0
	bgt _0803D566
	strb r2, [r6]
	strb r2, [r1]
_0803D566:
	adds r0, r7, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	bne _0803D5EE
	movs r1, #0x80
	lsls r1, r1, #0xe
	mov r3, sl
	ldr r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _0803D5E0
	movs r1, #4
	ldr r0, _0803D5D4 @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0803D5E0
	ldr r0, _0803D5D8 @ =0x0000081F
	adds r1, r5, r0
	ldrb r4, [r1]
	cmp r4, #0
	bne _0803D5B4
	movs r0, #1
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0xc0
	ldr r0, [r0]
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x15
	movs r2, #0x82
	lsls r2, r2, #4
	adds r1, r5, r2
	strh r0, [r1]
	ldr r3, _0803D5DC @ =0x00000822
	adds r0, r5, r3
	strh r4, [r0]
_0803D5B4:
	adds r0, r5, #0
	bl FUN_0803c328
	ldr r0, _0803D5DC @ =0x00000822
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #2
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x80
	bls _0803D5EE
	movs r0, #0x80
	strh r0, [r1]
	b _0803D5EE
	.align 2, 0
_0803D5D4: .4byte 0x03002BC0
_0803D5D8: .4byte 0x0000081F
_0803D5DC: .4byte 0x00000822
_0803D5E0:
	ldr r2, _0803D614 @ =0x0000081F
	adds r1, r5, r2
	movs r0, #0
	strb r0, [r1]
	movs r0, #8
	bl FUN_0823b880
_0803D5EE:
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
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803D614: .4byte 0x0000081F
