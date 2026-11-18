	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x24
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r6, [r0]
	ldr r2, _081A8CAC @ =0x0000046C
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A8CB0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081A8CB2
	.align 2, 0
_081A8CAC: .4byte 0x0000046C
_081A8CB0:
	movs r0, #0
_081A8CB2:
	cmp r0, #0
	bne _081A8CB8
	b _081A8DEA
_081A8CB8:
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r3, [r0]
	movs r1, #1
	ldr r4, _081A8D38 @ =0x0000046D
	adds r0, r7, r4
	movs r2, #0
	strb r1, [r0]
	subs r4, #2
	adds r0, r7, r4
	strb r2, [r0]
	adds r4, #0xe8
	adds r0, r7, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r2, [r0]
	ldr r0, _081A8D3C @ =0x00000472
	adds r4, r7, r0
	ldr r1, _081A8D40 @ =0xFFFFFE00
	adds r0, r1, #0
	ldrh r2, [r4]
	adds r0, r0, r2
	strh r0, [r7, #0xa]
	ldr r2, [r7, #0x44]
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	adds r1, r7, #0
	adds r1, #8
	adds r0, r6, #0
	bl Salamander_SetAllSegmentsPos
	ldrh r0, [r4]
	strh r0, [r7, #0xa]
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r0, r7, r3
	movs r4, #0xe0
	lsls r4, r4, #1
	adds r3, r7, r4
	ldrb r4, [r0]
	movs r5, #0x18
	ldr r2, _081A8D44 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _081A8D48
	asrs r1, r0, #0xc
	b _081A8D4E
	.align 2, 0
_081A8D38: .4byte 0x0000046D
_081A8D3C: .4byte 0x00000472
_081A8D40: .4byte 0xFFFFFE00
_081A8D44: .4byte gSineTable
_081A8D48:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081A8D4E:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	ldr r1, _081A8D68 @ =gSineTable
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _081A8D6C
	asrs r0, r0, #0xc
	b _081A8D72
	.align 2, 0
_081A8D68: .4byte gSineTable
_081A8D6C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081A8D72:
	movs r1, #0
	strh r0, [r3, #4]
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r0, r7, r3
	ldrb r0, [r0]
	strb r0, [r7, #5]
	movs r4, #0xe1
	lsls r4, r4, #1
	adds r2, r7, r4
	movs r0, #0x28
	strh r0, [r2]
	movs r2, #0xde
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	movs r0, #4
	movs r3, #0xca
	lsls r3, r3, #4
	adds r4, r6, r3
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	ldr r0, _081A8DC0 @ =0x0000019D
	bl PlaySound_082406e0
	movs r1, #0xaa
	lsls r1, r1, #2
	adds r0, r7, r1
	bl AuxShadow_Show
	movs r1, #0x80
	lsls r1, r1, #2
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081A8DC4
	movs r0, #1
	b _081A8DC6
	.align 2, 0
_081A8DC0: .4byte 0x0000019D
_081A8DC4:
	movs r0, #0
_081A8DC6:
	cmp r0, #0
	beq _081A8DD8
	ldr r0, _081A8DD4 @ =0xFFFFFDFF
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
	b _081A8DDE
	.align 2, 0
_081A8DD4: .4byte 0xFFFFFDFF
_081A8DD8:
	adds r0, r7, #0
	bl Salamander_ExplodeAtFeet
_081A8DDE:
	ldr r0, [r7, #0x44]
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
_081A8DEA:
	ldr r2, _081A8E24 @ =0x00000484
	adds r0, r7, r2
	ldr r0, [r0]
	cmp r0, #9
	bgt _081A8E2C
	add r4, sp, #4
	movs r0, #0
	str r0, [sp]
	mov r0, sp
	adds r1, r4, #0
	ldr r2, _081A8E28 @ =0x05000002
	bl CpuSet
	movs r0, #0x10
	strh r0, [r4, #2]
	movs r5, #0
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r3, r3, r7
	mov r8, r3
_081A8E12:
	adds r0, r7, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl Salamander_SetSegmentVelocity
	adds r5, #1
	cmp r5, #2
	ble _081A8E12
	b _081A8EB0
	.align 2, 0
_081A8E24: .4byte 0x00000484
_081A8E28: .4byte 0x05000002
_081A8E2C:
	cmp r0, #0x13
	bgt _081A8E64
	add r4, sp, #0xc
	movs r0, #0
	str r0, [sp]
	mov r0, sp
	adds r1, r4, #0
	ldr r2, _081A8E60 @ =0x05000002
	bl CpuSet
	movs r0, #0x18
	strh r0, [r4, #2]
	movs r5, #0
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r0, r0, r7
	mov r8, r0
_081A8E4E:
	adds r0, r7, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl Salamander_SetSegmentVelocity
	adds r5, #1
	cmp r5, #5
	ble _081A8E4E
	b _081A8EB0
	.align 2, 0
_081A8E60: .4byte 0x05000002
_081A8E64:
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r1, r1, r7
	mov r8, r1
	cmp r0, #0x3b
	bgt _081A8EB0
	add r4, sp, #0x14
	movs r0, #0
	str r0, [sp]
	mov r0, sp
	adds r1, r4, #0
	ldr r2, _081A8E98 @ =0x05000002
	bl CpuSet
	movs r5, #0
_081A8E82:
	cmp r5, #2
	bgt _081A8E9C
	movs r0, #0x2c
	strh r0, [r4, #2]
	adds r0, r7, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl Salamander_SetSegmentVelocity
	b _081A8EAA
	.align 2, 0
_081A8E98: .4byte 0x05000002
_081A8E9C:
	movs r0, #0x3e
	strh r0, [r4, #2]
	adds r0, r7, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl Salamander_SetSegmentVelocity
_081A8EAA:
	adds r5, #1
	cmp r5, #5
	ble _081A8E82
_081A8EB0:
	ldr r2, _081A8ED8 @ =0x00000484
	adds r4, r7, r2
	ldr r0, [r4]
	movs r1, #0xc
	bl Mod
	cmp r0, #0
	bne _081A8EC8
	adds r0, r7, #0
	adds r0, #8
	bl Salamander_SpawnFireDebris2
_081A8EC8:
	ldr r0, [r4]
	movs r1, #0x10
	bl Mod
	cmp r0, #0
	bne _081A8F00
	movs r4, #0
	b _081A8EF4
	.align 2, 0
_081A8ED8: .4byte 0x00000484
_081A8EDC:
	movs r0, #1
	ands r0, r4
	cmp r0, #0
	bne _081A8EF2
	movs r0, #0xd0
	muls r0, r4, r0
	adds r0, r0, r6
	ldr r2, _081A8FB0 @ =0x00000674
	adds r0, r0, r2
	bl Salamander_SpawnSpark
_081A8EF2:
	adds r4, #1
_081A8EF4:
	ldr r3, _081A8FB4 @ =0x00000CAA
	adds r0, r6, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r4, r0
	blt _081A8EDC
_081A8F00:
	movs r3, #0x80
	lsls r3, r3, #5
	adds r0, r7, #0
	movs r1, #4
	movs r2, #4
	bl Salamander_PullSegments
	adds r0, r6, #0
	bl Salamander_UpdateSegmentsBuried
	movs r0, #0x10
	mov r2, r8
	ldr r1, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081A8FCC
	ldr r0, _081A8FB8 @ =0xFFEFFFFF
	ands r1, r0
	str r1, [r2]
	adds r0, r7, #0
	bl Salamander_PickNextTile
	add r2, sp, #0x1c
	adds r4, r7, #0
	adds r4, #8
	ldr r3, _081A8FBC @ =0x000004A4
	adds r0, r7, r3
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0xc
	ldrh r1, [r0, #0xc]
	ldrh r0, [r7, #8]
	subs r1, r1, r0
	movs r5, #0
	movs r6, #0
	strh r1, [r2]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	movs r4, #0
	ldrsh r0, [r2, r4]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl ArcTan2_8
	movs r4, #0xee
	lsls r4, r4, #1
	adds r1, r7, r4
	strb r0, [r1]
	ldr r1, [r7, #0x44]
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	movs r1, #7
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r7, r3
	strb r5, [r0]
	ldr r4, _081A8FC0 @ =0x00000469
	adds r0, r7, r4
	strb r5, [r0]
	adds r3, #2
	adds r0, r7, r3
	strb r1, [r0]
	adds r4, #0x1b
	adds r0, r7, r4
	str r6, [r0]
	ldr r1, _081A8FC4 @ =0x0000046C
	adds r0, r7, r1
	strb r2, [r0]
	ldr r0, _081A8FC8 @ =0x00000145
	bl PlaySound_082406e0
	movs r2, #0xaa
	lsls r2, r2, #2
	adds r0, r7, r2
	bl AuxShadow_Hide
	adds r0, r7, #0
	bl Salamander_ExplodeAtFeet
	b _081A8FD6
	.align 2, 0
_081A8FB0: .4byte 0x00000674
_081A8FB4: .4byte 0x00000CAA
_081A8FB8: .4byte 0xFFEFFFFF
_081A8FBC: .4byte 0x000004A4
_081A8FC0: .4byte 0x00000469
_081A8FC4: .4byte 0x0000046C
_081A8FC8: .4byte 0x00000145
_081A8FCC:
	ldr r3, _081A8FE4 @ =0x00000484
	adds r1, r7, r3
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081A8FD6:
	add sp, #0x24
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081A8FE4: .4byte 0x00000484
