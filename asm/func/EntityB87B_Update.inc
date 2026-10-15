	push {r4, r5, r6, lr}
	sub sp, #0x18
	adds r5, r0, #0
	movs r2, #0x8d
	lsls r2, r2, #2
	adds r1, r5, r2
	ldr r1, [r1]
	cmp r1, #0
	beq _080C1D86
	bl _call_via_r1
_080C1D86:
	ldr r3, _080C1DD8 @ =0x0000022E
	adds r6, r5, r3
	ldrh r1, [r6]
	adds r4, r1, #0
	cmp r4, #0
	beq _080C1DE0
	adds r1, #1
	strh r1, [r6]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r1, #0x10
	bhi _080C1DA0
	b _080C1F2C
_080C1DA0:
	movs r1, #0x8c
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r2, [r0]
	cmp r2, #0
	beq _080C1DCE
	ldr r1, _080C1DDC @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	str r0, [sp, #0x10]
	add r1, sp, #0x10
	add r3, sp, #0xc
	str r3, [r1, #4]
	movs r3, #0x8b
	lsls r3, r3, #2
	adds r0, r5, r3
	ldrh r0, [r0]
	str r0, [sp, #0xc]
	adds r0, r2, #0
	bl VM_ExecByID
_080C1DCE:
	adds r0, r5, #0
	bl KillEntity
	b _080C1F2C
	.align 2, 0
_080C1DD8: .4byte 0x0000022E
_080C1DDC: .4byte 0xFFFF0000
_080C1DE0:
	movs r2, #0x89
	lsls r2, r2, #2
	adds r1, r5, r2
	ldr r3, _080C1E2C @ =0x00000226
	adds r2, r5, r3
	ldrh r1, [r1]
	ldrh r2, [r2]
	cmp r1, r2
	bne _080C1E34
	movs r2, #0x8a
	lsls r2, r2, #2
	adds r1, r5, r2
	ldrh r2, [r1]
	adds r3, #4
	adds r1, r5, r3
	ldrh r1, [r1]
	subs r1, #0x10
	cmp r2, r1
	bne _080C1E34
	movs r0, #4
	str r0, [sp]
	ldr r0, _080C1E30 @ =0x0000FFFF
	str r0, [sp, #4]
	str r4, [sp, #8]
	movs r0, #1
	movs r1, #4
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	movs r2, #0x8b
	lsls r2, r2, #2
	adds r1, r5, r2
	strh r4, [r1]
	movs r1, #1
	strh r1, [r6]
	b _080C1F14
	.align 2, 0
_080C1E2C: .4byte 0x00000226
_080C1E30: .4byte 0x0000FFFF
_080C1E34:
	movs r3, #0x88
	lsls r3, r3, #2
	adds r1, r5, r3
	ldrh r1, [r1]
	cmp r1, #0x10
	bls _080C1E84
	ldr r1, _080C1E78 @ =0x030044E0
	ldrh r2, [r1, #2]
	movs r1, #9
	ands r1, r2
	cmp r1, #0
	beq _080C1E84
	movs r0, #4
	str r0, [sp]
	ldr r0, _080C1E7C @ =0x0000FFFF
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #1
	movs r1, #4
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	movs r2, #0x8b
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r2, #1
	strh r2, [r1]
	ldr r3, _080C1E80 @ =0x0000022E
	adds r1, r5, r3
	strh r2, [r1]
	b _080C1F14
	.align 2, 0
_080C1E78: .4byte 0x030044E0
_080C1E7C: .4byte 0x0000FFFF
_080C1E80: .4byte 0x0000022E
_080C1E84:
	movs r2, #0x8a
	lsls r2, r2, #2
	adds r1, r5, r2
	ldr r3, _080C1EE0 @ =0x0000022A
	adds r2, r5, r3
	ldrh r1, [r1]
	ldrh r2, [r2]
	cmp r1, r2
	blo _080C1F14
	movs r1, #0x89
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r1, #1
	movs r2, #0
	strh r1, [r0]
	subs r3, #0xe
	adds r0, r5, r3
	ldrh r6, [r0]
	cmp r6, #1
	bne _080C1EE4
	adds r0, r5, #0
	adds r0, #0xf8
	adds r4, r5, #0
	adds r4, #0x18
	str r2, [sp]
	adds r1, r4, #0
	movs r2, #4
	movs r3, #1
	bl MainSprite_SetAnim
	movs r1, #0xac
	lsls r1, r1, #1
	adds r0, r5, r1
	adds r1, r4, #0
	movs r2, #1
	movs r3, #1
	bl MainSprite_SetPose
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r1, r5, r2
	ldr r0, [r1]
	orrs r0, r6
	str r0, [r1]
	b _080C1EF8
	.align 2, 0
_080C1EE0: .4byte 0x0000022A
_080C1EE4:
	cmp r6, #3
	bne _080C1EF8
	movs r3, #0x8d
	lsls r3, r3, #2
	adds r0, r5, r3
	ldr r1, _080C1F34 @ =FUN_080c1b44
	str r1, [r0]
	ldr r1, _080C1F38 @ =0x0000021E
	adds r0, r5, r1
	strh r2, [r0]
_080C1EF8:
	movs r2, #0x8a
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r0, #0
	strh r0, [r1]
	movs r0, #1
	bl MessageWindow_SetInstant
	movs r3, #0x89
	lsls r3, r3, #2
	adds r0, r5, r3
	ldrh r0, [r0]
	bl MessageWindow_ShowLine
_080C1F14:
	movs r1, #0x88
	lsls r1, r1, #2
	adds r2, r5, r1
	ldrh r1, [r2]
	adds r1, #1
	strh r1, [r2]
	movs r3, #0x8a
	lsls r3, r3, #2
	adds r2, r5, r3
	ldrh r1, [r2]
	adds r1, #1
	strh r1, [r2]
_080C1F2C:
	add sp, #0x18
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080C1F34: .4byte FUN_080c1b44
_080C1F38: .4byte 0x0000021E
