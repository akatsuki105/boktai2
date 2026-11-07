	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov r8, r5
	movs r1, #4
	movs r2, #0xcc
	lsls r2, r2, #3
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08130D5C
	movs r0, #1
	b _08130D5E
_08130D5C:
	movs r0, #0
_08130D5E:
	cmp r0, #0
	bne _08130E24
	adds r0, r5, #0
	bl FUN_081309f0
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08130D70
	b _08130EC2
_08130D70:
	ldr r0, _08130DE8 @ =0x03002BE0
	ldr r6, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r6, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _08130E24
	movs r2, #0x80
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r1, r5, r3
	ldrh r0, [r1]
	ands r0, r2
	adds r7, r1, #0
	cmp r0, #0
	bne _08130E24
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r1, r5, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhi _08130E24
	mov r2, sp
	adds r4, r5, #0
	adds r4, #8
	adds r3, r6, #0
	adds r3, #0x2c
	ldrh r0, [r6, #0x2c]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	ldrb r4, [r5, #5]
	mov r0, sp
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r6, #4
	ldrsh r1, [r2, r6]
	bl ArcTan2_8
	subs r1, r0, r4
	cmp r1, #0x80
	ble _08130DF0
	ldr r0, _08130DEC @ =0xFFFFFF00
	adds r1, r1, r0
	b _08130DFE
	.align 2, 0
_08130DE8: .4byte 0x03002BE0
_08130DEC: .4byte 0xFFFFFF00
_08130DF0:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _08130DFE
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
_08130DFE:
	adds r0, r1, #0
	cmp r0, #0
	bge _08130E06
	rsbs r0, r0, #0
_08130E06:
	cmp r0, #0x20
	bgt _08130E24
	mov r0, r8
	adds r0, #8
	ldr r4, _08130E28 @ =0x03002BE0
	ldr r1, [r4]
	adds r1, #0x2c
	movs r3, #0x80
	lsls r3, r3, #1
	movs r2, #5
	bl Map_HasLineOfSight
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08130E2C
_08130E24:
	movs r0, #0
	b _08130EC4
	.align 2, 0
_08130E28: .4byte 0x03002BE0
_08130E2C:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r5, r3
	ldr r0, [r4]
	adds r0, #0x24
	str r0, [r1]
	movs r2, #0xc
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	movs r1, #0
	strb r1, [r0]
	ldr r3, _08130ED0 @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	adds r6, #2
	adds r0, r5, r6
	strb r2, [r0]
	ldr r2, _08130ED4 @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #3
	adds r0, r5, r3
	movs r2, #1
	strb r2, [r0]
	movs r6, #0xb7
	lsls r6, r6, #3
	adds r0, r5, r6
	ldr r4, [r0]
	movs r3, #0x1a
	ldr r6, _08130ED8 @ =0x0000046D
	adds r0, r5, r6
	strb r2, [r0]
	ldr r2, _08130EDC @ =0x0000046B
	adds r0, r5, r2
	strb r1, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r3, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r5, r2
	str r4, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r1, [r0]
	adds r0, r5, #0
	bl Spider_PickPathNodeAwayFromPlayer
	adds r0, r5, #0
	bl Enemy_StepTowardPathNode
	ldr r6, _08130EE0 @ =0x000001DF
	adds r0, r5, r6
	ldrb r0, [r0]
	cmp r0, #2
	beq _08130EAC
	movs r0, #4
	ldr r1, _08130EE4 @ =0x00000222
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_08130EAC:
	movs r0, #0x80
	ldrh r1, [r7]
	orrs r0, r1
	strh r0, [r7]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrh r1, [r0]
	ldr r3, _08130EE8 @ =0x0000024E
	adds r0, r5, r3
	strh r1, [r0]
_08130EC2:
	movs r0, #1
_08130EC4:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08130ED0: .4byte 0x00000469
_08130ED4: .4byte 0x00000484
_08130ED8: .4byte 0x0000046D
_08130EDC: .4byte 0x0000046B
_08130EE0: .4byte 0x000001DF
_08130EE4: .4byte 0x00000222
_08130EE8: .4byte 0x0000024E
