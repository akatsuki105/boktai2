	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	adds r5, r0, #0
	movs r0, #0x9c
	adds r0, r0, r5
	mov r8, r0
	movs r1, #0
	mov sb, r1
	mov sl, r1
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r2, [r0]
	movs r3, #8
	ldrsh r0, [r2, r3]
	movs r6, #8
	ldrsh r1, [r5, r6]
	subs r0, r0, r1
	movs r7, #0xc
	ldrsh r1, [r2, r7]
	movs r3, #0xc
	ldrsh r2, [r5, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r3, _081B365C @ =gSineTable
	adds r1, r0, #0
	adds r1, #0x40
	movs r2, #0xff
	ands r1, r2
	lsls r1, r1, #1
	adds r1, r1, r3
	movs r6, #0
	ldrsh r1, [r1, r6]
	lsls r2, r1, #2
	adds r2, r2, r1
	lsls r2, r2, #5
	lsrs r2, r2, #0x10
	ldr r7, _081B3660 @ =0xFFFF0000
	ldr r1, [sp]
	ands r1, r7
	orrs r1, r2
	str r1, [sp]
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #5
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	ands r1, r7
	orrs r1, r0
	str r1, [sp, #4]
	mov r3, r8
	ldr r0, [r3, #4]
	bl Map_GetPathNodes
	adds r4, r0, #0
	movs r6, #0
	mov r1, r8
	ldr r0, [r1, #4]
	ldrb r0, [r0]
	cmp sb, r0
	bge _081B3672
	mov ip, r7
	add r3, sp, #8
	mov r2, sp
	str r2, [sp, #0x10]
_081B3600:
	ldrh r1, [r4]
	ldrh r0, [r5, #8]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #8]
	mov r7, ip
	ands r0, r7
	orrs r0, r1
	str r0, [sp, #8]
	ldrh r1, [r4, #2]
	ldrh r0, [r5, #0xc]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [r3, #4]
	ands r0, r7
	orrs r0, r1
	str r0, [r3, #4]
	ldr r0, [sp, #0x10]
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r7, #0
	ldrsh r0, [r3, r7]
	muls r1, r0, r1
	ldr r0, [sp, #0x10]
	movs r7, #4
	ldrsh r2, [r0, r7]
	movs r7, #4
	ldrsh r0, [r3, r7]
	muls r0, r2, r0
	adds r1, r1, r0
	cmp r1, #0
	bge _081B3664
	ldr r1, [r4]
	adds r0, r5, #0
	adds r0, #0xa4
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r1, r0
	beq _081B3666
	lsls r0, r6, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	b _081B36D4
	.align 2, 0
_081B365C: .4byte gSineTable
_081B3660: .4byte 0xFFFF0000
_081B3664:
	adds r4, #8
_081B3666:
	adds r6, #1
	mov r1, r8
	ldr r0, [r1, #4]
	ldrb r0, [r0]
	cmp r6, r0
	blt _081B3600
_081B3672:
	mov r2, sl
	cmp r2, #0
	bne _081B36D4
	adds r4, r5, #0
	adds r4, #0x9c
	ldr r2, _081B36C8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081B36CC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _081B36D0 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r1, [r4, #4]
	ldrb r1, [r1]
	bl Mod
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r6, [r4, #2]
	cmp r0, r6
	bne _081B36B0
	adds r0, #1
	ldr r1, [r4, #4]
	ldrb r1, [r1]
	bl Mod
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
_081B36B0:
	strb r0, [r4, #2]
	mov r7, sl
	strb r7, [r4, #3]
	ldr r0, [r4, #4]
	bl Map_GetPathNodes
	ldrb r1, [r4, #2]
	lsls r1, r1, #3
	adds r0, r0, r1
	str r0, [r4, #8]
	b _081B36E4
	.align 2, 0
_081B36C8: .4byte 0x030046B8
_081B36CC: .4byte 0x000003FF
_081B36D0: .4byte 0x0203B400
_081B36D4:
	movs r0, #0
	mov r2, sb
	mov r1, r8
	strb r2, [r1, #2]
	strb r0, [r1, #3]
	str r4, [r1, #8]
	adds r4, r5, #0
	adds r4, #0x9c
_081B36E4:
	movs r3, #0x95
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r6, [r0]
	ldr r0, [r4, #8]
	ldrh r1, [r0]
	strh r1, [r6]
	ldr r0, [r4, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r4, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r4, #0
	blt _081B3718
	cmp r1, #0
	blt _081B3718
	ldr r0, _081B371C @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _081B3718
	ldr r0, _081B3720 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B3724
_081B3718:
	movs r4, #0
	b _081B3732
	.align 2, 0
_081B371C: .4byte 0x030046A8
_081B3720: .4byte 0x030046AC
_081B3724:
	ldr r0, _081B3744 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_081B3732:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081B3748
	adds r0, #4
	b _081B3754
	.align 2, 0
_081B3744: .4byte 0x030046A4
_081B3748:
	ldr r0, _081B3768 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B3754:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081B376C
	cmp r2, #2
	beq _081B3770
	b _081B3774
	.align 2, 0
_081B3768: .4byte 0x030046A4
_081B376C:
	ldrb r0, [r6, #4]
	b _081B3772
_081B3770:
	ldrb r0, [r6]
_081B3772:
	subs r1, r1, r0
_081B3774:
	strh r1, [r6, #2]
	ldr r6, _081B37A0 @ =0x000004A4
	adds r0, r5, r6
	ldr r6, [r0]
	adds r7, r5, #0
	adds r7, #8
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r4, [r0]
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081B37A4
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	b _081B37CA
	.align 2, 0
_081B37A0: .4byte 0x000004A4
_081B37A4:
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081B37C4
	cmp r0, #2
	beq _081B37C0
	adds r0, r5, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081B37C0:
	movs r0, #1
	b _081B37D4
_081B37C4:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r5, r3
_081B37CA:
	ldr r1, _081B3828 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_081B37D4:
	adds r4, r0, #0
	cmp r4, #0
	bne _081B3848
	ldr r1, _081B382C @ =Enemy_ClearStateBegun
	ldr r6, _081B3830 @ =0x0000046D
	adds r0, r5, r6
	movs r3, #1
	strb r3, [r0]
	ldr r7, _081B3834 @ =0x0000046B
	adds r0, r5, r7
	strb r4, [r0]
	ldr r2, _081B3838 @ =0x00000553
	adds r0, r5, r2
	strb r4, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r5, r6
	str r1, [r0]
	movs r7, #0xe4
	lsls r7, r7, #1
	adds r0, r5, r7
	movs r2, #0
	strh r4, [r0]
	movs r1, #3
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	ldr r7, _081B383C @ =0x00000469
	adds r0, r5, r7
	strb r2, [r0]
	ldr r1, _081B3840 @ =0x0000046A
	adds r0, r5, r1
	strb r2, [r0]
	ldr r2, _081B3844 @ =0x00000484
	adds r0, r5, r2
	str r4, [r0]
	adds r6, #4
	adds r0, r5, r6
	strb r3, [r0]
	b _081B3854
	.align 2, 0
_081B3828: .4byte 0xFFFFFDFF
_081B382C: .4byte Enemy_ClearStateBegun
_081B3830: .4byte 0x0000046D
_081B3834: .4byte 0x0000046B
_081B3838: .4byte 0x00000553
_081B383C: .4byte 0x00000469
_081B3840: .4byte 0x0000046A
_081B3844: .4byte 0x00000484
_081B3848:
	movs r7, #0x95
	lsls r7, r7, #3
	adds r0, r5, r7
	ldr r1, [r0]
	movs r0, #1
	strh r0, [r1, #6]
_081B3854:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
