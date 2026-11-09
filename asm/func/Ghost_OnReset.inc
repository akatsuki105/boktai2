	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #4
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r4, [r0]
	ldr r2, _0816D2E4 @ =0x00000838
	adds r0, r4, r2
	movs r1, #0
	movs r5, #0
	strh r5, [r0]
	adds r2, #2
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	movs r2, #1
	mov r8, r2
	mov r2, r8
	strb r2, [r0]
	ldr r2, _0816D2E8 @ =0x0000083C
	adds r0, r4, r2
	strh r5, [r0]
	adds r2, #5
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r1, [r0]
	ldr r0, _0816D2EC @ =0x000007DC
	adds r1, r4, r0
	ldr r2, _0816D2F0 @ =0x00000574
	adds r0, r6, r2
	ldr r0, [r0]
	str r0, [r1]
	movs r0, #0x89
	lsls r0, r0, #4
	adds r2, r4, r0
	ldr r0, _0816D2F4 @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _0816D2F8 @ =0x00000878
	adds r1, r4, r2
	str r5, [sp]
	mov r0, sp
	ldr r2, _0816D2FC @ =0x05000002
	bl CpuSet
	movs r0, #0x88
	lsls r0, r0, #4
	adds r1, r4, r0
	str r5, [sp]
	mov r0, sp
	ldr r2, _0816D2FC @ =0x05000002
	bl CpuSet
	ldr r1, _0816D300 @ =0x00000888
	adds r4, r4, r1
	str r5, [sp]
	mov r0, sp
	adds r1, r4, #0
	ldr r2, _0816D2FC @ =0x05000002
	bl CpuSet
	movs r2, #0x95
	lsls r2, r2, #3
	adds r0, r6, r2
	ldr r0, [r0]
	movs r1, #8
	bl ClearMemory
	ldr r1, _0816D304 @ =0x0825215C
	adds r0, r6, #0
	movs r2, #0x96
	lsls r2, r2, #1
	bl Enemy_ClearPendingState
	adds r0, r6, #0
	movs r1, #0
	bl Enemy_PlayAnim
	ldr r0, [r6, #0x44]
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x48
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x48]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	mov r1, r8
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	mov r2, r8
	ands r0, r2
	cmp r1, r0
	beq _0816D308
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0816D310
	.align 2, 0
_0816D2E4: .4byte 0x00000838
_0816D2E8: .4byte 0x0000083C
_0816D2EC: .4byte 0x000007DC
_0816D2F0: .4byte 0x00000574
_0816D2F4: .4byte 0x03002BE0
_0816D2F8: .4byte 0x00000878
_0816D2FC: .4byte 0x05000002
_0816D300: .4byte 0x00000888
_0816D304: .4byte 0x0825215C
_0816D308:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0816D310:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0816D334
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0816D33C
_0816D334:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0816D33C:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _0816D374 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0816D3AC
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0816D378
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0816D36C
	ldrb r0, [r4, #5]
_0816D36C:
	subs r0, #1
	strh r0, [r4, #8]
	b _0816D388
	.align 2, 0
_0816D374: .4byte 0x0000FFFF
_0816D378:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0816D388
	strh r1, [r4, #8]
_0816D388:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0816D3AC
	movs r0, #1
	strb r0, [r4, #7]
_0816D3AC:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
