	push {r4, r5, r6, r7, lr}
	ldr r7, _0804E2D0 @ =0x03002B58
	ldr r6, [r7]
	cmp r6, #0
	beq _0804E2D4
	adds r0, r6, #0
	b _0804E364
	.align 2, 0
_0804E2D0: .4byte 0x03002B58
_0804E2D4:
	bl SuspendSunlight
	movs r4, #0xe3
	lsls r4, r4, #2
	adds r0, r4, #0
	bl Malloc
	adds r5, r0, #0
	cmp r5, #0
	beq _0804E362
	adds r0, r5, #0
	adds r1, r4, #0
	bl ClearMemory
	bl Time_GetSecond
	ldr r3, _0804E348 @ =0x030046B8
	ldr r1, [r3]
	adds r1, #1
	ldr r2, _0804E34C @ =0x000003FF
	ands r1, r2
	str r1, [r3]
	lsls r1, r1, #1
	ldr r2, _0804E350 @ =0x0203B400
	adds r1, r1, r2
	ldrh r3, [r1]
	ldr r1, _0804E354 @ =0x03002CF0
	movs r2, #0xff
	ldrb r1, [r1]
	adds r0, r0, r3
	ands r0, r2
	lsls r0, r0, #8
	orrs r1, r0
	adds r0, r5, #0
	adds r0, #0x6c
	strh r1, [r0]
	adds r0, r5, #0
	bl FUN_0804e25c
	cmp r0, #0
	blt _0804E35C
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl SetEntityRoutine
	movs r4, #1
	strb r4, [r5, #0x14]
	strb r4, [r5, #0x16]
	strh r6, [r5, #0x10]
	adds r0, r5, #0
	bl AddEntity
	ldr r0, _0804E358 @ =0x0300481C
	str r4, [r0]
	str r5, [r7]
	adds r0, r5, #0
	b _0804E364
	.align 2, 0
_0804E348: .4byte 0x030046B8
_0804E34C: .4byte 0x000003FF
_0804E350: .4byte 0x0203B400
_0804E354: .4byte 0x03002CF0
_0804E358: .4byte 0x0300481C
_0804E35C:
	adds r0, r5, #0
	bl Free
_0804E362:
	movs r0, #0
_0804E364:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
