	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x20
	adds r6, r0, #0
	ldr r0, [r6, #0x44]
	adds r7, r0, #0
	adds r7, #0x48
	ldr r0, _081A33E4 @ =0x0000046D
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A33E8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081A33EA
	.align 2, 0
_081A33E4: .4byte 0x0000046D
_081A33E8:
	movs r0, #0
_081A33EA:
	cmp r0, #0
	beq _081A33F6
	adds r0, r6, #0
	movs r1, #5
	bl Enemy_PlayAnim
_081A33F6:
	ldrh r0, [r7, #8]
	cmp r0, #3
	bne _081A3408
	ldrh r0, [r7, #0xe]
	cmp r0, #0
	bne _081A3408
	ldr r0, _081A3550 @ =0x000001DD
	bl PlaySound_082406e0
_081A3408:
	ldrh r0, [r7, #8]
	adds r1, r0, #0
	cmp r1, #3
	beq _081A3412
	b _081A35D8
_081A3412:
	ldrh r0, [r7, #0xe]
	cmp r0, #6
	bgt _081A341A
	b _081A35D8
_081A341A:
	adds r5, r6, #0
	adds r5, #0xde
	ldrh r1, [r5]
	movs r0, #4
	movs r2, #0
	mov r8, r2
	movs r3, #0
	mov sb, r3
	orrs r0, r1
	ldr r1, _081A3554 @ =0x0000FFF7
	ands r0, r1
	strh r0, [r5]
	movs r0, #0x80
	lsls r0, r0, #4
	ldr r1, _081A3558 @ =0x00000474
	adds r4, r6, r1
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	adds r0, r6, #0
	movs r1, #0
	bl DarkRoot_FindAdjacentTarget
	adds r3, r5, #0
	adds r2, r4, #0
	cmp r0, #0
	bne _081A3452
	b _081A3626
_081A3452:
	ldr r3, _081A355C @ =DarkRoot_StateHold
	movs r1, #0x24
	ldr r2, _081A3560 @ =0x0000046D
	adds r0, r6, r2
	movs r2, #1
	strb r2, [r0]
	ldr r4, _081A3564 @ =0x0000046B
	adds r0, r6, r4
	mov r4, r8
	strb r4, [r0]
	ldr r4, _081A3568 @ =0x00000553
	adds r0, r6, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r6, r3
	mov r4, sb
	strh r4, [r0]
	movs r1, #2
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r6, r3
	mov r4, r8
	strb r4, [r0]
	adds r3, #1
	adds r0, r6, r3
	strb r1, [r0]
	ldr r4, _081A356C @ =0x0000046A
	adds r0, r6, r4
	strb r2, [r0]
	ldr r1, _081A3570 @ =0x00000484
	adds r0, r6, r1
	mov r3, sb
	str r3, [r0]
	adds r4, #2
	adds r0, r6, r4
	strb r2, [r0]
	movs r0, #0x15
	add r0, sp
	mov r8, r0
	adds r0, r6, #0
	add r1, sp, #0x14
	mov r2, r8
	bl Enemy_SetAnimFacing
	ldr r3, _081A3574 @ =0x085ADE10
	mov r2, r8
	ldrb r1, [r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	ldrh r4, [r7, #8]
	adds r0, r0, r4
	lsls r0, r0, #3
	adds r0, r0, r3
	ldrh r0, [r0]
	ldrh r1, [r6, #8]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _081A3578 @ =0xFFFF0000
	ldr r2, [sp, #0x18]
	ands r2, r4
	orrs r2, r0
	str r2, [sp, #0x18]
	mov r0, r8
	ldrb r1, [r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	ldrh r1, [r7, #8]
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r3
	ldrh r1, [r0, #2]
	ldrh r0, [r6, #0xa]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r0, _081A357C @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x18]
	mov r2, r8
	ldrb r1, [r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	ldrh r7, [r7, #8]
	adds r0, r0, r7
	lsls r0, r0, #3
	adds r0, r0, r3
	ldrh r1, [r0, #4]
	ldrh r3, [r6, #0xc]
	adds r1, r1, r3
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	add r5, sp, #0x18
	ldr r0, [r5, #4]
	ands r0, r4
	orrs r0, r1
	str r0, [r5, #4]
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r0, [r0]
	ldrb r1, [r0, #4]
	cmp r1, #3
	bhi _081A3584
	ldr r1, _081A3580 @ =0x03002BE0
	ldrb r0, [r0, #4]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldrb r1, [r2]
	str r1, [sp]
	mov r7, sb
	str r7, [sp, #4]
	str r7, [sp, #8]
	str r7, [sp, #0xc]
	str r7, [sp, #0x10]
	adds r1, r5, #0
	movs r2, #0
	movs r3, #0
	bl Player_HoldGrabbed
	b _081A35C0
	.align 2, 0
_081A3550: .4byte 0x000001DD
_081A3554: .4byte 0x0000FFF7
_081A3558: .4byte 0x00000474
_081A355C: .4byte DarkRoot_StateHold
_081A3560: .4byte 0x0000046D
_081A3564: .4byte 0x0000046B
_081A3568: .4byte 0x00000553
_081A356C: .4byte 0x0000046A
_081A3570: .4byte 0x00000484
_081A3574: .4byte 0x085ADE10
_081A3578: .4byte 0xFFFF0000
_081A357C: .4byte 0x0000FFFF
_081A3580: .4byte 0x03002BE0
_081A3584:
	cmp r1, #4
	bne _081A35C0
	ldr r4, [r0, #0x38]
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r4, r1
	mov r2, sb
	strh r2, [r0]
	adds r0, r4, #0
	bl Enemy_ClearDamage
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r4, r3
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	mov r7, r8
	ldrb r0, [r7]
	str r0, [sp]
	mov r0, sb
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r1, #0
	adds r2, r5, #0
	movs r3, #0
	bl FUN_080e6978
_081A35C0:
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r1, [r0]
	movs r2, #2
	movs r3, #0xcc
	lsls r3, r3, #3
	adds r1, r1, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _081A3692
_081A35D8:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _081A3608
	adds r3, r6, #0
	adds r3, #0xde
	ldrh r1, [r3]
	ldr r0, _081A35FC @ =0x0000FFFB
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	strh r0, [r3]
	ldr r4, _081A3600 @ =0x00000474
	adds r2, r6, r4
	ldr r0, _081A3604 @ =0xFFFFF7FF
	ldrh r1, [r2]
	ands r0, r1
	b _081A3624
	.align 2, 0
_081A35FC: .4byte 0x0000FFFB
_081A3600: .4byte 0x00000474
_081A3604: .4byte 0xFFFFF7FF
_081A3608:
	adds r3, r6, #0
	adds r3, #0xde
	ldrh r1, [r3]
	movs r0, #4
	orrs r0, r1
	ldr r1, _081A36A0 @ =0x0000FFF7
	ands r0, r1
	strh r0, [r3]
	movs r0, #0x80
	lsls r0, r0, #4
	ldr r7, _081A36A4 @ =0x00000474
	adds r2, r6, r7
	ldrh r1, [r2]
	orrs r0, r1
_081A3624:
	strh r0, [r2]
_081A3626:
	ldr r1, _081A36A8 @ =0x0000046E
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081A3692
	ldrh r1, [r3]
	ldr r0, _081A36AC @ =0x0000FFFB
	ands r0, r1
	movs r4, #0
	movs r5, #0
	movs r1, #8
	orrs r0, r1
	strh r0, [r3]
	ldr r0, _081A36B0 @ =0xFFFFF7FF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r2, _081A36B4 @ =DarkRoot_StateRetract
	movs r1, #0x26
	ldr r3, _081A36B8 @ =0x0000046D
	adds r0, r6, r3
	movs r3, #1
	strb r3, [r0]
	ldr r7, _081A36BC @ =0x0000046B
	adds r0, r6, r7
	strb r4, [r0]
	adds r7, #0xe8
	adds r0, r6, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r5, [r0]
	movs r1, #2
	movs r2, #3
	subs r7, #0xeb
	adds r0, r6, r7
	strb r4, [r0]
	ldr r4, _081A36C0 @ =0x00000469
	adds r0, r6, r4
	strb r1, [r0]
	adds r7, #2
	adds r0, r6, r7
	strb r2, [r0]
	ldr r1, _081A36C4 @ =0x00000484
	adds r0, r6, r1
	str r5, [r0]
	ldr r2, _081A36C8 @ =0x0000046C
	adds r0, r6, r2
	strb r3, [r0]
_081A3692:
	add sp, #0x20
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081A36A0: .4byte 0x0000FFF7
_081A36A4: .4byte 0x00000474
_081A36A8: .4byte 0x0000046E
_081A36AC: .4byte 0x0000FFFB
_081A36B0: .4byte 0xFFFFF7FF
_081A36B4: .4byte DarkRoot_StateRetract
_081A36B8: .4byte 0x0000046D
_081A36BC: .4byte 0x0000046B
_081A36C0: .4byte 0x00000469
_081A36C4: .4byte 0x00000484
_081A36C8: .4byte 0x0000046C
