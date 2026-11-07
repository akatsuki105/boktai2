	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x38
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r6, [r0]
	movs r2, #0xd1
	lsls r2, r2, #3
	adds r0, r6, r2
	ldrh r0, [r0]
	cmp r0, #0
	bne _0816461C
	b _08164758
_0816461C:
	movs r3, #8
	ldrsh r0, [r7, r3]
	str r0, [sp]
	movs r4, #0xa
	ldrsh r0, [r7, r4]
	str r0, [sp, #4]
	movs r1, #0xc
	ldrsh r0, [r7, r1]
	str r0, [sp, #8]
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r0, r7, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	str r0, [sp, #0xc]
	ldr r4, _08164664 @ =0x000001DD
	adds r0, r7, r4
	add r3, sp, #0x28
	ldrb r4, [r0]
	movs r5, #0xc
	ldr r2, _08164668 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	mov ip, r3
	cmp r0, #0
	blt _0816466C
	asrs r1, r0, #0xc
	b _08164672
	.align 2, 0
_08164664: .4byte 0x000001DD
_08164668: .4byte gSineTable
_0816466C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08164672:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _0816468A
	asrs r0, r0, #0xc
	b _08164690
_0816468A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08164690:
	movs r5, #0
	movs r4, #0
	mov r8, r4
	strh r0, [r3, #4]
	mov r1, ip
	movs r2, #0
	ldrsh r0, [r1, r2]
	str r0, [sp, #0x10]
	movs r0, #0x18
	str r0, [sp, #0x14]
	add r0, sp, #0x28
	movs r3, #4
	ldrsh r0, [r0, r3]
	str r0, [sp, #0x18]
	movs r4, #0x90
	lsls r4, r4, #3
	adds r0, r7, r4
	ldrh r0, [r0]
	str r0, [sp, #0x1c]
	ldr r1, _08164764 @ =0x0000068A
	adds r0, r6, r1
	ldrh r0, [r0]
	str r0, [sp, #0x20]
	movs r2, #0x95
	lsls r2, r2, #2
	adds r0, r7, r2
	ldrh r0, [r0]
	str r0, [sp, #0x24]
	ldr r1, _08164768 @ =0xFFFF0000
	ldr r0, [sp, #0x30]
	ands r0, r1
	movs r1, #0xa
	orrs r0, r1
	str r0, [sp, #0x30]
	add r1, sp, #0x30
	mov r3, sp
	str r3, [r1, #4]
	movs r0, #0xd1
	lsls r0, r0, #3
	adds r4, r6, r0
	ldrh r0, [r4]
	bl VM_ExecByID
	adds r0, r7, #0
	bl FUN_081647c8
	mov r1, r8
	strh r1, [r4]
	movs r0, #8
	ldr r3, _0816476C @ =0x0000068E
	adds r2, r6, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r2, _08164770 @ =Enemy_ClearStateBegun
	movs r1, #0x10
	ldr r4, _08164774 @ =0x0000046D
	adds r0, r7, r4
	movs r3, #1
	strb r3, [r0]
	subs r4, #2
	adds r0, r7, r4
	strb r5, [r0]
	adds r4, #0xe8
	adds r0, r7, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	mov r4, r8
	strh r4, [r0]
	movs r1, #2
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r7, r2
	strb r5, [r0]
	ldr r4, _08164778 @ =0x00000469
	adds r0, r7, r4
	strb r5, [r0]
	adds r2, #2
	adds r0, r7, r2
	strb r1, [r0]
	adds r4, #0x1b
	adds r0, r7, r4
	mov r1, r8
	str r1, [r0]
	adds r2, #2
	adds r0, r7, r2
	strb r3, [r0]
	movs r3, #0xc1
	lsls r3, r3, #1
	adds r2, r7, r3
	ldr r0, _0816477C @ =0xFFFFF67F
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_08164758:
	add sp, #0x38
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08164764: .4byte 0x0000068A
_08164768: .4byte 0xFFFF0000
_0816476C: .4byte 0x0000068E
_08164770: .4byte Enemy_ClearStateBegun
_08164774: .4byte 0x0000046D
_08164778: .4byte 0x00000469
_0816477C: .4byte 0xFFFFF67F
