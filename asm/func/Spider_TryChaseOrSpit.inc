	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r5, r0, #0
	mov sl, r5
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #2
	movs r2, #0xcc
	lsls r2, r2, #3
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08130AF0
	movs r0, #1
	b _08130AF2
_08130AF0:
	movs r0, #0
_08130AF2:
	cmp r0, #0
	bne _08130B1C
	adds r0, r5, #0
	bl FUN_081309f0
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08130B04
	b _08130D10
_08130B04:
	ldr r0, _08130B18 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _08130B2A
_08130B14:
	movs r0, #0
	b _08130D12
	.align 2, 0
_08130B18: .4byte 0x03002BE0
_08130B1C:
	adds r0, r5, #0
	bl FUN_081309f0
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08130B2A
	b _08130D10
_08130B2A:
	ldr r0, _08130BC8 @ =0x03002BE0
	ldr r0, [r0]
	cmp r0, #0
	beq _08130B14
	mov r8, r0
	mov r6, sp
	adds r7, r5, #0
	adds r7, #8
	mov r4, r8
	adds r4, #0x2c
	mov r3, r8
	ldrh r0, [r3, #0x2c]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r4, #2]
	ldrh r1, [r7, #2]
	subs r0, r0, r1
	strh r0, [r6, #2]
	ldrh r0, [r4, #4]
	ldrh r1, [r7, #4]
	subs r0, r0, r1
	strh r0, [r6, #4]
	movs r1, #2
	ldrsh r0, [r6, r1]
	cmp r0, #0
	bge _08130B64
	rsbs r0, r0, #0
_08130B64:
	cmp r0, #0xff
	bgt _08130B14
	mov r0, sp
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r3, r0, #0
	muls r3, r0, r3
	movs r2, #4
	ldrsh r1, [r6, r2]
	adds r2, r1, #0
	muls r2, r1, r2
	adds r3, r3, r2
	mov sb, r3
	bl ArcTan2_8
	movs r3, #0xf6
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r0, [r0]
	lsls r0, r0, #1
	cmp sb, r0
	bhs _08130B14
	mov r1, r8
	ldrh r0, [r1, #0x2c]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r4, #2]
	ldrh r1, [r7, #2]
	subs r0, r0, r1
	strh r0, [r6, #2]
	ldrh r0, [r4, #4]
	ldrh r1, [r7, #4]
	subs r0, r0, r1
	strh r0, [r6, #4]
	ldrb r4, [r5, #5]
	mov r0, sp
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r3, #4
	ldrsh r1, [r6, r3]
	bl ArcTan2_8
	subs r1, r0, r4
	cmp r1, #0x80
	ble _08130BD0
	ldr r6, _08130BCC @ =0xFFFFFF00
	adds r1, r1, r6
	b _08130BDE
	.align 2, 0
_08130BC8: .4byte 0x03002BE0
_08130BCC: .4byte 0xFFFFFF00
_08130BD0:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _08130BDE
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r1, r0
_08130BDE:
	adds r0, r1, #0
	cmp r0, #0
	bge _08130BE6
	rsbs r0, r0, #0
_08130BE6:
	cmp r0, #0x20
	bgt _08130B14
	mov r0, sl
	adds r0, #8
	mov r1, r8
	adds r1, #0x2c
	movs r3, #0x80
	lsls r3, r3, #1
	movs r2, #5
	bl Map_HasLineOfSight
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08130B14
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r5, r1
	mov r1, r8
	adds r1, #0x24
	str r1, [r0]
	ldr r0, _08130CA8 @ =0x00003FFF
	cmp sb, r0
	bgt _08130CC4
	movs r2, #0xc
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r1, #0
	strb r1, [r0]
	ldr r6, _08130CAC @ =0x00000469
	adds r0, r5, r6
	strb r1, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r2, [r0]
	adds r6, #0x1b
	adds r0, r5, r6
	str r1, [r0]
	ldr r2, _08130CB0 @ =0x0000046C
	adds r0, r5, r2
	movs r2, #1
	strb r2, [r0]
	movs r3, #0xb7
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r4, [r0]
	movs r3, #0x1a
	subs r6, #0x17
	adds r0, r5, r6
	strb r2, [r0]
	ldr r2, _08130CB4 @ =0x0000046B
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
	ldr r6, _08130CB8 @ =0x000001DF
	adds r0, r5, r6
	ldrb r0, [r0]
	cmp r0, #2
	beq _08130C88
	movs r0, #4
	ldr r1, _08130CBC @ =0x00000222
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_08130C88:
	movs r0, #0x80
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r5, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r6, #0x93
	lsls r6, r6, #2
	adds r0, r5, r6
	ldrh r1, [r0]
	ldr r2, _08130CC0 @ =0x0000024E
	adds r0, r5, r2
	strh r1, [r0]
	b _08130D10
	.align 2, 0
_08130CA8: .4byte 0x00003FFF
_08130CAC: .4byte 0x00000469
_08130CB0: .4byte 0x0000046C
_08130CB4: .4byte 0x0000046B
_08130CB8: .4byte 0x000001DF
_08130CBC: .4byte 0x00000222
_08130CC0: .4byte 0x0000024E
_08130CC4:
	movs r1, #0x10
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r2, #0
	strb r2, [r0]
	ldr r6, _08130D24 @ =0x00000469
	adds r0, r5, r6
	strb r2, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r1, [r0]
	adds r6, #0x1b
	adds r0, r5, r6
	str r2, [r0]
	ldr r1, _08130D28 @ =0x0000046C
	adds r0, r5, r1
	movs r1, #1
	strb r1, [r0]
	ldr r4, _08130D2C @ =Spider_SpitVenom
	movs r3, #3
	subs r6, #0x17
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _08130D30 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r3, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r4, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r2, [r0]
_08130D10:
	movs r0, #1
_08130D12:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08130D24: .4byte 0x00000469
_08130D28: .4byte 0x0000046C
_08130D2C: .4byte Spider_SpitVenom
_08130D30: .4byte 0x0000046B
