	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	adds r6, r0, #0
	ldr r0, _0810A5BC @ =0x0000046D
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0810A5C0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0810A5C2
	.align 2, 0
_0810A5BC: .4byte 0x0000046D
_0810A5C0:
	movs r0, #0
_0810A5C2:
	cmp r0, #0
	beq _0810A5D4
	adds r0, r6, #0
	movs r1, #0x14
	bl Enemy_PlayAnim
	ldr r0, _0810A5F8 @ =0x000003AB
	bl PlaySound_082406e0
_0810A5D4:
	add r3, sp, #0xc
	ldrb r4, [r6, #5]
	ldr r2, _0810A5FC @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #5
	adds r5, r3, #0
	cmp r0, #0
	blt _0810A600
	asrs r1, r0, #0xc
	b _0810A606
	.align 2, 0
_0810A5F8: .4byte 0x000003AB
_0810A5FC: .4byte gSineTable
_0810A600:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0810A606:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x20
	muls r0, r1, r0
	cmp r0, #0
	blt _0810A620
	asrs r0, r0, #0xc
	b _0810A626
_0810A620:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0810A626:
	movs r7, #0
	strh r0, [r3, #4]
	ldrh r0, [r5]
	ldrh r1, [r6, #0x10]
	adds r0, r0, r1
	strh r0, [r6, #0x10]
	add r5, sp, #0xc
	ldrh r0, [r5, #4]
	ldrh r2, [r6, #0x14]
	adds r0, r0, r2
	strh r0, [r6, #0x14]
	movs r2, #0x80
	lsls r2, r2, #6
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	str r7, [sp, #8]
	add r0, sp, #8
	adds r1, r5, #0
	ldr r2, _0810A6C4 @ =0x05000002
	bl CpuSet
	ldr r4, _0810A6C8 @ =0xFFFF0000
	ldr r0, [sp, #0x14]
	ands r0, r4
	movs r3, #0x52
	orrs r0, r3
	ldr r1, _0810A6CC @ =0x0000FFFF
	ands r0, r1
	str r0, [sp, #0x14]
	add r2, sp, #0x14
	ldr r0, [r2, #4]
	ands r0, r4
	orrs r0, r3
	str r0, [r2, #4]
	adds r0, r6, #0
	adds r0, #8
	movs r1, #2
	str r1, [sp]
	movs r1, #4
	str r1, [sp, #4]
	adds r1, r5, #0
	movs r3, #1
	bl DustManager_Spawn
	ldr r1, _0810A6D0 @ =0x0000046E
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0810A6BA
	ldr r3, _0810A6D4 @ =Skeleton_StateDashSlide
	movs r2, #0x28
	ldr r0, _0810A6D8 @ =0x0000046D
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r0, _0810A6DC @ =0x0000046B
	adds r1, r6, r0
	movs r0, #0
	strb r0, [r1]
	ldr r1, _0810A6E0 @ =0x00000553
	adds r0, r6, r1
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r6, r2
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r6, r1
	strh r7, [r0]
_0810A6BA:
	add sp, #0x1c
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0810A6C4: .4byte 0x05000002
_0810A6C8: .4byte 0xFFFF0000
_0810A6CC: .4byte 0x0000FFFF
_0810A6D0: .4byte 0x0000046E
_0810A6D4: .4byte Skeleton_StateDashSlide
_0810A6D8: .4byte 0x0000046D
_0810A6DC: .4byte 0x0000046B
_0810A6E0: .4byte 0x00000553
