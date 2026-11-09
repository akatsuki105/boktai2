	push {r4, r5, r6, r7, lr}
	sub sp, #0x2c
	adds r5, r0, #0
	adds r7, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _0810B8D0 @ =0x0000046D
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0810B892
	movs r0, #0
	strb r0, [r1]
_0810B892:
	adds r0, r5, #0
	movs r1, #0x14
	bl Enemy_PlayAnim
	adds r0, r7, #0
	movs r1, #0xf
	bl Mod
	cmp r0, #0
	bne _0810B994
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	str r0, [sp, #0x24]
	str r1, [sp, #0x28]
	ldr r2, [sp, #0x24]
	asrs r1, r2, #0x10
	adds r1, #0xdc
	lsls r1, r1, #0x10
	ldr r0, _0810B8D4 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x24]
	ldrb r0, [r5, #5]
	adds r1, r0, #0
	adds r1, #0x20
	movs r0, #0xff
	ands r1, r0
	cmp r1, #0
	blt _0810B8D8
	asrs r0, r1, #6
	b _0810B8DE
	.align 2, 0
_0810B8D0: .4byte 0x0000046D
_0810B8D4: .4byte 0x0000FFFF
_0810B8D8:
	rsbs r0, r1, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_0810B8DE:
	add r4, sp, #0x1c
	lsls r3, r0, #6
	ldr r2, _0810B900 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #7
	cmp r0, #0
	blt _0810B904
	asrs r1, r0, #0xc
	b _0810B90A
	.align 2, 0
_0810B900: .4byte gSineTable
_0810B904:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0810B90A:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x80
	muls r0, r1, r0
	cmp r0, #0
	blt _0810B928
	asrs r0, r0, #0xc
	b _0810B92E
_0810B928:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0810B92E:
	strh r0, [r4, #4]
	add r0, sp, #0x24
	add r3, sp, #0x1c
	adds r2, r3, #0
	ldrh r1, [r0]
	ldrh r2, [r2]
	adds r1, r1, r2
	strh r1, [r0]
	ldrh r1, [r3, #2]
	ldrh r2, [r0, #2]
	adds r1, r1, r2
	strh r1, [r0, #2]
	ldrh r1, [r0, #4]
	ldrh r3, [r3, #4]
	adds r1, r1, r3
	strh r1, [r0, #4]
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r5, r3
	ldr r1, [r1]
	adds r1, #8
	adds r3, #0x50
	adds r2, r5, r3
	ldrh r2, [r2]
	str r2, [sp]
	adds r3, #8
	adds r2, r5, r3
	ldrh r2, [r2]
	str r2, [sp, #4]
	adds r3, #0x14
	adds r2, r5, r3
	ldr r2, [r2]
	str r2, [sp, #8]
	subs r3, #0xc
	adds r2, r5, r3
	ldrh r2, [r2]
	str r2, [sp, #0xc]
	movs r2, #0x14
	str r2, [sp, #0x10]
	ldr r3, _0810B9CC @ =0x0000071C
	adds r2, r6, r3
	ldrh r2, [r2]
	str r2, [sp, #0x14]
	adds r3, #2
	adds r2, r6, r3
	ldrh r2, [r2]
	str r2, [sp, #0x18]
	movs r2, #6
	movs r3, #6
	bl Entity081f4554_Spawn
_0810B994:
	cmp r7, #0x28
	ble _0810B9C2
	ldr r4, _0810B9D0 @ =Skeleton_StateCurveShotEnd
	movs r3, #0x33
	ldr r0, _0810B9D4 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0810B9D8 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
_0810B9C2:
	add sp, #0x2c
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0810B9CC: .4byte 0x0000071C
_0810B9D0: .4byte Skeleton_StateCurveShotEnd
_0810B9D4: .4byte 0x0000046D
_0810B9D8: .4byte 0x0000046B
