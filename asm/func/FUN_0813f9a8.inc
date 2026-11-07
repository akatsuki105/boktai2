	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	ldr r2, _0813F9C8 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0813F9CC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0813F9CE
	.align 2, 0
_0813F9C8: .4byte 0x0000046C
_0813F9CC:
	movs r0, #0
_0813F9CE:
	cmp r0, #0
	beq _0813FA14
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r1, [r0]
	movs r4, #1
	ldr r2, _0813FA64 @ =0x0000046D
	adds r0, r5, r2
	movs r2, #0
	strb r4, [r0]
	ldr r3, _0813FA68 @ =0x0000046B
	adds r0, r5, r3
	strb r2, [r0]
	adds r3, #0xe8
	adds r0, r5, r3
	strb r4, [r0]
	adds r3, #0x25
	adds r0, r5, r3
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
	movs r3, #0xd6
	lsls r3, r3, #3
	adds r1, r7, r3
	str r2, [sp]
	mov r0, sp
	ldr r2, _0813FA6C @ =0x05000002
	bl CpuSet
	ldr r1, _0813FA70 @ =0x00000667
	adds r0, r7, r1
	strb r4, [r0]
_0813FA14:
	movs r2, #0xb1
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r6, r0, #0
	adds r0, r5, #0
	bl EnemyBat_UpdateCurveBend
	ldr r3, _0813FA74 @ =0x000004A4
	adds r0, r5, r3
	ldr r1, [r0]
	ldrh r2, [r1, #0xc]
	ldrh r0, [r5, #8]
	subs r2, r2, r0
	lsls r2, r2, #0x10
	ldrh r0, [r1, #0x10]
	ldrh r1, [r5, #0xc]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsrs r3, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, #0
	bge _0813FA4C
	rsbs r2, r2, #0
_0813FA4C:
	lsls r1, r0, #0x10
	cmp r2, #0x20
	bgt _0813FA78
	asrs r2, r1, #0x10
	cmp r2, #0
	bge _0813FA5A
	rsbs r2, r2, #0
_0813FA5A:
	cmp r2, #0x20
	bgt _0813FA78
	movs r0, #1
	b _0813FAE2
	.align 2, 0
_0813FA64: .4byte 0x0000046D
_0813FA68: .4byte 0x0000046B
_0813FA6C: .4byte 0x05000002
_0813FA70: .4byte 0x00000667
_0813FA74: .4byte 0x000004A4
_0813FA78:
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bne _0813FA84
	cmp r1, #0
	beq _0813FAE0
_0813FA84:
	asrs r1, r1, #0x10
	bl ArcTan2_8
	strb r0, [r5, #5]
	ldr r2, _0813FAA8 @ =gSineTable
	ldrb r0, [r5, #5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0813FAAC
	asrs r1, r0, #0xc
	b _0813FAB2
	.align 2, 0
_0813FAA8: .4byte gSineTable
_0813FAAC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0813FAB2:
	ldrh r0, [r5, #0x10]
	adds r0, r0, r1
	strh r0, [r5, #0x10]
	ldr r1, _0813FAD0 @ =gSineTable
	ldrb r0, [r5, #5]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _0813FAD4
	asrs r1, r0, #0xc
	b _0813FADA
	.align 2, 0
_0813FAD0: .4byte gSineTable
_0813FAD4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0813FADA:
	ldrh r0, [r5, #0x14]
	adds r0, r0, r1
	strh r0, [r5, #0x14]
_0813FAE0:
	movs r0, #0
_0813FAE2:
	cmp r0, #0
	bne _0813FAE8
	b _0813FBE2
_0813FAE8:
	adds r0, r5, #0
	bl FUN_081406b8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0813FBE2
	movs r0, #0xd6
	lsls r0, r0, #3
	adds r3, r7, r0
	ldrb r4, [r5, #5]
	ldr r2, _0813FB18 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0813FB1C
	asrs r1, r0, #0xc
	b _0813FB22
	.align 2, 0
_0813FB18: .4byte gSineTable
_0813FB1C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0813FB22:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _0813FB3A
	asrs r0, r0, #0xc
	b _0813FB40
_0813FB3A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0813FB40:
	strh r0, [r3, #4]
	adds r0, r5, #0
	bl EnemyBat_PickRandomPathNode
	add r6, sp, #4
	adds r0, r5, #0
	adds r0, #0x9c
	ldr r1, [r0, #8]
	ldrh r0, [r1]
	strh r0, [r6]
	ldrh r1, [r1, #2]
	strh r1, [r6, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	adds r7, r6, #0
	cmp r2, #0
	blt _0813FB7A
	cmp r1, #0
	blt _0813FB7A
	ldr r0, _0813FB80 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0813FB7A
	ldr r0, _0813FB84 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0813FB88
_0813FB7A:
	movs r4, #0
	b _0813FB96
	.align 2, 0
_0813FB80: .4byte 0x030046A8
_0813FB84: .4byte 0x030046AC
_0813FB88:
	ldr r0, _0813FBA8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0813FB96:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0813FBAC
	adds r0, #4
	b _0813FBB8
	.align 2, 0
_0813FBA8: .4byte 0x030046A4
_0813FBAC:
	ldr r0, _0813FBCC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0813FBB8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0813FBD0
	cmp r2, #2
	beq _0813FBD4
	b _0813FBD8
	.align 2, 0
_0813FBCC: .4byte 0x030046A4
_0813FBD0:
	ldrb r0, [r6, #4]
	b _0813FBD6
_0813FBD4:
	ldrb r0, [r6]
_0813FBD6:
	subs r1, r1, r0
_0813FBD8:
	strh r1, [r6, #2]
	adds r0, r5, #0
	adds r1, r7, #0
	bl FUN_08140970
_0813FBE2:
	ldr r3, _0813FBF4 @ =0x00000484
	adds r1, r5, r3
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0813FBF4: .4byte 0x00000484
