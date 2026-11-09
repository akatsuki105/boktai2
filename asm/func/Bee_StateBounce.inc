	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r0, _081678D4 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081678D8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081678DA
	.align 2, 0
_081678D4: .4byte 0x0000046C
_081678D8:
	movs r0, #0
_081678DA:
	cmp r0, #0
	beq _0816799E
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r4, [r0]
	movs r3, #1
	ldr r6, _08167948 @ =0x0000046D
	adds r0, r5, r6
	movs r2, #0
	strb r3, [r0]
	subs r6, #2
	adds r0, r5, r6
	strb r2, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	strh r2, [r0]
	ldr r0, _0816794C @ =0x00000704
	adds r1, r1, r0
	str r2, [sp]
	mov r0, sp
	ldr r2, _08167950 @ =0x05000002
	bl CpuSet
	ldr r2, _08167954 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08167958 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0816795C @ =0x0203B400
	adds r0, r0, r1
	ldrb r3, [r0]
	ldr r1, _08167960 @ =gSineTable
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	blt _08167964
	asrs r1, r0, #6
	b _0816796A
	.align 2, 0
_08167948: .4byte 0x0000046D
_0816794C: .4byte 0x00000704
_08167950: .4byte 0x05000002
_08167954: .4byte 0x030046B8
_08167958: .4byte 0x000003FF
_0816795C: .4byte 0x0203B400
_08167960: .4byte gSineTable
_08167964:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r1, r0, #0
_0816796A:
	movs r6, #0xe0
	lsls r6, r6, #1
	adds r0, r5, r6
	strh r1, [r0]
	ldr r2, _0816798C @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	blt _08167990
	asrs r1, r0, #6
	b _08167996
	.align 2, 0
_0816798C: .4byte gSineTable
_08167990:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r1, r0, #0
_08167996:
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
_0816799E:
	movs r3, #0xe0
	lsls r3, r3, #1
	adds r4, r5, r3
	movs r6, #0
	ldrsh r0, [r4, r6]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #4
	ldrsh r0, [r4, r2]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r6, r1, r0
	cmp r6, #0
	bne _081679FE
	adds r0, r5, #0
	bl Bee_ResumeHover
	str r6, [sp]
	mov r0, sp
	adds r1, r4, #0
	ldr r2, _08167A10 @ =0x05000002
	bl CpuSet
	ldr r0, _08167A14 @ =0x03002BE0
	ldr r1, [r0]
	adds r1, #0x2c
	adds r0, r5, #0
	bl Bee_BeginCurveTo
	movs r1, #2
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r6, [r0]
	ldr r3, _08167A18 @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	ldr r1, _08167A1C @ =0x0000046A
	adds r0, r5, r1
	strb r6, [r0]
	adds r2, #0x1c
	adds r0, r5, r2
	str r6, [r0]
	adds r3, #3
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
_081679FE:
	ldr r6, _08167A20 @ =0x00000484
	adds r1, r5, r6
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08167A10: .4byte 0x05000002
_08167A14: .4byte 0x03002BE0
_08167A18: .4byte 0x00000469
_08167A1C: .4byte 0x0000046A
_08167A20: .4byte 0x00000484
