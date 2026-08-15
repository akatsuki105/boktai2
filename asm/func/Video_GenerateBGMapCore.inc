	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x4c
	str r1, [sp]
	str r2, [sp, #4]
	ldr r2, [sp, #0x6c]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #4
	ldr r0, _0822C4D0 @ =0x03003ED0
	adds r1, r1, r0
	movs r4, #0x10
	ldrsh r0, [r1, r4]
	ldr r7, [sp]
	subs r0, r7, r0
	str r0, [sp, #8]
	movs r4, #0x12
	ldrsh r0, [r1, r4]
	ldr r7, [sp, #4]
	subs r5, r7, r0
	mov r0, sp
	ldrh r0, [r0]
	strh r0, [r1, #0x10]
	strh r7, [r1, #0x12]
	strh r3, [r1, #0x20]
	strh r2, [r1, #0x22]
	ldr r7, [sp, #8]
	cmp r7, #0
	bne _0822C46C
	cmp r5, #0
	bne _0822C46C
	bl _0822CCB4
_0822C46C:
	ldr r6, [r1, #0x2c]
	ldr r0, [sp, #0x70]
	cmp r0, #0
	bne _0822C478
	ldr r2, [r1, #0x28]
	str r2, [sp, #0x70]
_0822C478:
	ldr r3, [r1, #0x24]
	mov sb, r3
	movs r4, #0x1c
	ldrsh r0, [r1, r4]
	lsls r0, r0, #1
	str r0, [sp, #0xc]
	movs r7, #0x1e
	ldrsh r0, [r1, r7]
	lsls r0, r0, #1
	str r0, [sp, #0x10]
	ldr r2, [sp, #0xc]
	subs r2, #0x20
	adds r3, r0, #0
	subs r3, #0x20
	ldrh r0, [r1, #0x18]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x14
	str r0, [sp, #0x14]
	movs r4, #0
	ldrsh r0, [r1, r4]
	ldrh r1, [r1]
	cmp r0, #1
	bne _0822C4A8
	b _0822CA38
_0822C4A8:
	ldr r7, [sp]
	cmp r7, #0
	blt _0822C4BE
	ldr r0, [sp, #4]
	cmp r0, #0
	blt _0822C4BE
	cmp r7, r2
	bge _0822C4BE
	cmp r0, r3
	bge _0822C4BE
	b _0822C7F2
_0822C4BE:
	cmp r1, #2
	bne _0822C4D4
	ldr r1, [sp, #0x70]
	ldrh r0, [r1]
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	mov ip, r0
	b _0822C4D8
	.align 2, 0
_0822C4D0: .4byte 0x03003ED0
_0822C4D4:
	movs r2, #0
	mov ip, r2
_0822C4D8:
	ldr r0, [sp, #8]
	adds r0, #1
	cmp r0, #2
	bhi _0822C4EC
	cmp r5, #2
	bgt _0822C4EC
	movs r0, #2
	rsbs r0, r0, #0
	cmp r5, r0
	bge _0822C5E8
_0822C4EC:
	movs r3, #0
	mov r8, r3
_0822C4F0:
	ldr r1, [sp, #4]
	add r1, r8
	cmp r1, #0
	blt _0822C4FE
	ldr r4, [sp, #0x10]
	cmp r1, r4
	blt _0822C530
_0822C4FE:
	movs r0, #0x1f
	ands r1, r0
	lsls r5, r1, #5
	adds r0, r1, #1
	lsls r4, r0, #5
	movs r7, #0
	movs r0, #2
	add r8, r0
	movs r1, #0x1f
_0822C510:
	ldr r2, [sp]
	adds r3, r2, r7
	ands r3, r1
	adds r0, r3, r5
	lsls r0, r0, #1
	adds r0, r0, r6
	mov r2, ip
	strh r2, [r0]
	adds r0, r3, r4
	lsls r0, r0, #1
	adds r0, r0, r6
	strh r2, [r0]
	adds r7, #1
	cmp r7, #0x1f
	ble _0822C510
	b _0822C5E0
_0822C530:
	cmp r1, #0
	blt _0822C538
	asrs r0, r1, #5
	b _0822C53E
_0822C538:
	rsbs r0, r1, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_0822C53E:
	ldr r4, [sp, #0x14]
	adds r3, r0, #0
	muls r3, r4, r3
	str r3, [sp, #0x18]
	movs r0, #0x1f
	ands r1, r0
	asrs r0, r1, #1
	lsls r0, r0, #4
	str r0, [sp, #0x1c]
	lsls r5, r1, #5
	adds r0, r1, #1
	lsls r4, r0, #5
	movs r7, #0
	movs r0, #2
	add r8, r0
	movs r1, #0x1f
	mov sl, r1
_0822C560:
	ldr r2, [sp]
	adds r3, r2, r7
	cmp r3, #0
	blt _0822C56E
	ldr r0, [sp, #0xc]
	cmp r3, r0
	blt _0822C586
_0822C56E:
	mov r1, sl
	ands r3, r1
	adds r0, r3, r5
	lsls r0, r0, #1
	adds r0, r0, r6
	mov r2, ip
	strh r2, [r0]
	adds r0, r3, r4
	lsls r0, r0, #1
	adds r0, r0, r6
	strh r2, [r0]
	b _0822C5DA
_0822C586:
	asrs r0, r3, #5
	ldr r1, [sp, #0x18]
	adds r0, r0, r1
	lsls r2, r0, #8
	mov r0, sl
	ands r3, r0
	asrs r0, r3, #1
	adds r0, r2, r0
	ldr r1, [sp, #0x1c]
	adds r0, r0, r1
	lsls r0, r0, #1
	ldr r2, [sp, #0x70]
	adds r0, r0, r2
	ldrh r2, [r0]
	movs r0, #1
	ands r0, r3
	cmp r0, #0
	bne _0822C5C2
	adds r0, r3, r5
	lsls r0, r0, #1
	adds r0, r0, r6
	lsls r2, r2, #3
	add r2, sb
	ldrh r1, [r2]
	strh r1, [r0]
	adds r0, r3, r4
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r1, [r2, #4]
	b _0822C5D8
_0822C5C2:
	adds r0, r3, r5
	lsls r0, r0, #1
	adds r0, r0, r6
	lsls r2, r2, #3
	add r2, sb
	ldrh r1, [r2, #2]
	strh r1, [r0]
	adds r0, r3, r4
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r1, [r2, #6]
_0822C5D8:
	strh r1, [r0]
_0822C5DA:
	adds r7, #1
	cmp r7, #0x1f
	ble _0822C560
_0822C5E0:
	mov r3, r8
	cmp r3, #0x1f
	ble _0822C4F0
	b _0822CCB4
_0822C5E8:
	ldr r4, [sp, #8]
	cmp r4, #0
	bne _0822C5F0
	b _0822C6FA
_0822C5F0:
	movs r7, #0
	cmp r4, #0
	ble _0822C5F8
	movs r7, #0x1f
_0822C5F8:
	ldr r0, [sp]
	adds r4, r0, r7
	cmp r4, #0
	blt _0822C606
	ldr r1, [sp, #0xc]
	cmp r4, r1
	blt _0822C63C
_0822C606:
	movs r0, #0x1f
	ands r4, r0
	movs r2, #0
	mov r8, r2
	movs r1, #0x1f
_0822C610:
	ldr r3, [sp, #4]
	add r3, r8
	ands r3, r1
	lsls r0, r3, #5
	adds r0, r4, r0
	lsls r0, r0, #1
	adds r0, r0, r6
	mov r7, ip
	strh r7, [r0]
	adds r0, r3, #1
	lsls r0, r0, #5
	adds r0, r4, r0
	lsls r0, r0, #1
	adds r0, r0, r6
	mov r2, ip
	strh r2, [r0]
	movs r3, #2
	add r8, r3
	mov r7, r8
	cmp r7, #0x1f
	ble _0822C610
	b _0822C6FA
_0822C63C:
	cmp r4, #0
	blt _0822C644
	asrs r0, r4, #5
	b _0822C64A
_0822C644:
	rsbs r0, r4, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_0822C64A:
	str r0, [sp, #0x20]
	movs r0, #0x1f
	ands r4, r0
	asrs r0, r4, #1
	str r0, [sp, #0x24]
	movs r1, #0
	mov r8, r1
	movs r2, #0x1f
	mov sl, r2
	movs r3, #1
	ands r3, r4
	str r3, [sp, #0x48]
_0822C662:
	ldr r3, [sp, #4]
	add r3, r8
	cmp r3, #0
	blt _0822C670
	ldr r7, [sp, #0x10]
	cmp r3, r7
	blt _0822C68C
_0822C670:
	mov r0, sl
	ands r3, r0
	lsls r0, r3, #5
	adds r0, r4, r0
	lsls r0, r0, #1
	adds r0, r0, r6
	mov r1, ip
	strh r1, [r0]
	adds r0, r3, #1
	lsls r0, r0, #5
	adds r0, r4, r0
	lsls r0, r0, #1
	adds r0, r0, r6
	b _0822C6EE
_0822C68C:
	asrs r0, r3, #5
	ldr r2, [sp, #0x14]
	muls r0, r2, r0
	ldr r7, [sp, #0x20]
	adds r0, r7, r0
	lsls r2, r0, #8
	mov r0, sl
	ands r3, r0
	asrs r1, r3, #1
	lsls r1, r1, #4
	ldr r7, [sp, #0x24]
	adds r0, r2, r7
	adds r0, r0, r1
	lsls r0, r0, #1
	ldr r1, [sp, #0x70]
	adds r0, r0, r1
	ldrh r2, [r0]
	ldr r7, [sp, #0x48]
	cmp r7, #0
	bne _0822C6D2
	lsls r0, r3, #5
	adds r0, r4, r0
	lsls r0, r0, #1
	adds r0, r0, r6
	lsls r2, r2, #3
	add r2, sb
	ldrh r1, [r2]
	strh r1, [r0]
	adds r0, r3, #1
	lsls r0, r0, #5
	adds r0, r4, r0
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r1, [r2, #4]
	b _0822C6EE
_0822C6D2:
	lsls r0, r3, #5
	adds r0, r4, r0
	lsls r0, r0, #1
	adds r0, r0, r6
	lsls r2, r2, #3
	add r2, sb
	ldrh r1, [r2, #2]
	strh r1, [r0]
	adds r0, r3, #1
	lsls r0, r0, #5
	adds r0, r4, r0
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r1, [r2, #6]
_0822C6EE:
	strh r1, [r0]
	movs r0, #2
	add r8, r0
	mov r1, r8
	cmp r1, #0x1f
	ble _0822C662
_0822C6FA:
	cmp r5, #0
	bne _0822C700
	b _0822CCB4
_0822C700:
	movs r2, #0
	mov r8, r2
	cmp r5, #0
	ble _0822C70C
	movs r3, #0x1e
	mov r8, r3
_0822C70C:
	ldr r3, [sp, #4]
	add r3, r8
	cmp r3, #0
	blt _0822C71A
	ldr r4, [sp, #0x10]
	cmp r3, r4
	blt _0822C748
_0822C71A:
	movs r0, #0x1f
	ands r3, r0
	lsls r5, r3, #5
	adds r0, r3, #1
	lsls r3, r0, #5
	movs r7, #0
	movs r1, #0x1f
_0822C728:
	ldr r0, [sp]
	adds r4, r0, r7
	ands r4, r1
	adds r0, r4, r5
	lsls r0, r0, #1
	adds r0, r0, r6
	mov r2, ip
	strh r2, [r0]
	adds r0, r4, r3
	lsls r0, r0, #1
	adds r0, r0, r6
	strh r2, [r0]
	adds r7, #1
	cmp r7, #0x1f
	ble _0822C728
	b _0822CCB4
_0822C748:
	cmp r3, #0
	blt _0822C750
	asrs r0, r3, #5
	b _0822C756
_0822C750:
	rsbs r0, r3, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_0822C756:
	ldr r7, [sp, #0x14]
	adds r4, r0, #0
	muls r4, r7, r4
	str r4, [sp, #0x28]
	movs r0, #0x1f
	ands r3, r0
	asrs r0, r3, #1
	lsls r0, r0, #4
	mov sl, r0
	lsls r5, r3, #5
	adds r0, r3, #1
	lsls r3, r0, #5
	movs r7, #0
	movs r0, #0x1f
	mov r8, r0
_0822C774:
	ldr r1, [sp]
	adds r4, r1, r7
	cmp r4, #0
	blt _0822C782
	ldr r2, [sp, #0xc]
	cmp r4, r2
	blt _0822C798
_0822C782:
	mov r0, r8
	ands r4, r0
	adds r0, r4, r5
	lsls r0, r0, #1
	adds r0, r0, r6
	mov r1, ip
	strh r1, [r0]
	adds r0, r4, r3
	lsls r0, r0, #1
	adds r0, r0, r6
	b _0822C7E8
_0822C798:
	asrs r0, r4, #5
	ldr r2, [sp, #0x28]
	adds r0, r0, r2
	lsls r2, r0, #8
	mov r0, r8
	ands r4, r0
	asrs r0, r4, #1
	adds r0, r2, r0
	add r0, sl
	lsls r0, r0, #1
	ldr r1, [sp, #0x70]
	adds r0, r0, r1
	ldrh r2, [r0]
	movs r0, #1
	ands r0, r4
	cmp r0, #0
	bne _0822C7D2
	adds r1, r4, r5
	lsls r1, r1, #1
	adds r1, r1, r6
	lsls r2, r2, #3
	add r2, sb
	ldrh r0, [r2]
	strh r0, [r1]
	adds r0, r4, r3
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r1, [r2, #4]
	b _0822C7E8
_0822C7D2:
	adds r1, r4, r5
	lsls r1, r1, #1
	adds r1, r1, r6
	lsls r2, r2, #3
	add r2, sb
	ldrh r0, [r2, #2]
	strh r0, [r1]
	adds r0, r4, r3
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r1, [r2, #6]
_0822C7E8:
	strh r1, [r0]
	adds r7, #1
	cmp r7, #0x1f
	ble _0822C774
	b _0822CCB4
_0822C7F2:
	ldr r0, [sp, #8]
	adds r0, #1
	cmp r0, #2
	bhi _0822C806
	cmp r5, #2
	bgt _0822C806
	movs r0, #2
	rsbs r0, r0, #0
	cmp r5, r0
	bge _0822C8A8
_0822C806:
	movs r2, #0
	mov r8, r2
_0822C80A:
	ldr r1, [sp, #4]
	add r1, r8
	cmp r1, #0
	blt _0822C816
	asrs r0, r1, #5
	b _0822C81C
_0822C816:
	rsbs r0, r1, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_0822C81C:
	ldr r4, [sp, #0x14]
	adds r3, r0, #0
	muls r3, r4, r3
	mov ip, r3
	movs r7, #0x1f
	ands r1, r7
	asrs r0, r1, #1
	lsls r0, r0, #4
	mov sl, r0
	lsls r5, r1, #5
	adds r0, r1, #1
	lsls r4, r0, #5
	movs r7, #0
	movs r0, #2
	add r8, r0
_0822C83A:
	ldr r1, [sp]
	adds r3, r1, r7
	cmp r3, #0
	blt _0822C846
	asrs r0, r3, #5
	b _0822C84C
_0822C846:
	rsbs r0, r3, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_0822C84C:
	add r0, ip
	lsls r2, r0, #8
	movs r0, #0x1f
	ands r3, r0
	asrs r0, r3, #1
	adds r0, r2, r0
	add r0, sl
	lsls r0, r0, #1
	ldr r1, [sp, #0x70]
	adds r0, r0, r1
	ldrh r2, [r0]
	movs r0, #1
	ands r0, r3
	cmp r0, #0
	bne _0822C882
	adds r0, r3, r5
	lsls r0, r0, #1
	adds r0, r0, r6
	lsls r2, r2, #3
	add r2, sb
	ldrh r1, [r2]
	strh r1, [r0]
	adds r0, r3, r4
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r1, [r2, #4]
	b _0822C898
_0822C882:
	adds r0, r3, r5
	lsls r0, r0, #1
	adds r0, r0, r6
	lsls r2, r2, #3
	add r2, sb
	ldrh r1, [r2, #2]
	strh r1, [r0]
	adds r0, r3, r4
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r1, [r2, #6]
_0822C898:
	strh r1, [r0]
	adds r7, #1
	cmp r7, #0x1f
	ble _0822C83A
	mov r2, r8
	cmp r2, #0x1f
	ble _0822C80A
	b _0822CCB4
_0822C8A8:
	cmp r5, #0
	beq _0822C964
	cmp r5, #0
	ble _0822C8BA
	movs r0, #0x20
	subs r0, r0, r5
	movs r3, #0x20
	str r3, [sp, #0x2c]
	b _0822C8C0
_0822C8BA:
	movs r0, #0
	rsbs r5, r5, #0
	str r5, [sp, #0x2c]
_0822C8C0:
	mov r8, r0
	ldr r4, [sp, #0x2c]
	cmp r8, r4
	bge _0822C964
_0822C8C8:
	ldr r1, [sp, #4]
	add r1, r8
	cmp r1, #0
	blt _0822C8D4
	asrs r0, r1, #5
	b _0822C8DA
_0822C8D4:
	rsbs r0, r1, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_0822C8DA:
	ldr r2, [sp, #0x14]
	adds r7, r0, #0
	muls r7, r2, r7
	mov ip, r7
	movs r3, #0x1f
	ands r1, r3
	asrs r0, r1, #1
	lsls r0, r0, #4
	mov sl, r0
	lsls r5, r1, #5
	adds r0, r1, #1
	lsls r4, r0, #5
	movs r7, #0
	movs r0, #2
	add r8, r0
_0822C8F8:
	ldr r1, [sp]
	adds r3, r1, r7
	cmp r3, #0
	blt _0822C904
	asrs r0, r3, #5
	b _0822C90A
_0822C904:
	rsbs r0, r3, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_0822C90A:
	add r0, ip
	lsls r2, r0, #8
	movs r0, #0x1f
	ands r3, r0
	asrs r0, r3, #1
	adds r0, r2, r0
	add r0, sl
	lsls r0, r0, #1
	ldr r1, [sp, #0x70]
	adds r0, r0, r1
	ldrh r2, [r0]
	movs r0, #1
	ands r0, r3
	cmp r0, #0
	bne _0822C940
	adds r0, r3, r5
	lsls r0, r0, #1
	adds r0, r0, r6
	lsls r2, r2, #3
	add r2, sb
	ldrh r1, [r2]
	strh r1, [r0]
	adds r0, r3, r4
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r1, [r2, #4]
	b _0822C956
_0822C940:
	adds r0, r3, r5
	lsls r0, r0, #1
	adds r0, r0, r6
	lsls r2, r2, #3
	add r2, sb
	ldrh r1, [r2, #2]
	strh r1, [r0]
	adds r0, r3, r4
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r1, [r2, #6]
_0822C956:
	strh r1, [r0]
	adds r7, #1
	cmp r7, #0x1f
	ble _0822C8F8
	ldr r2, [sp, #0x2c]
	cmp r8, r2
	blt _0822C8C8
_0822C964:
	ldr r3, [sp, #8]
	cmp r3, #0
	bne _0822C96C
	b _0822CCB4
_0822C96C:
	cmp r3, #0
	ble _0822C97A
	movs r0, #0x20
	subs r0, r0, r3
	movs r4, #0x20
	str r4, [sp, #0x30]
	b _0822C982
_0822C97A:
	movs r0, #0
	ldr r7, [sp, #8]
	rsbs r7, r7, #0
	str r7, [sp, #0x30]
_0822C982:
	adds r7, r0, #0
	ldr r0, [sp, #0x30]
	cmp r7, r0
	blt _0822C98C
	b _0822CCB4
_0822C98C:
	ldr r1, [sp]
	adds r4, r1, r7
	cmp r4, #0
	blt _0822C998
	asrs r0, r4, #5
	b _0822C99E
_0822C998:
	rsbs r0, r4, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_0822C99E:
	mov ip, r0
	movs r2, #0x1f
	ands r4, r2
	asrs r3, r4, #1
	mov sl, r3
	movs r0, #0
	mov r8, r0
	adds r1, r7, #1
	str r1, [sp, #0x48]
	movs r5, #1
	ands r5, r4
_0822C9B4:
	ldr r3, [sp, #4]
	add r3, r8
	cmp r3, #0
	blt _0822C9C0
	asrs r0, r3, #5
	b _0822C9C6
_0822C9C0:
	rsbs r0, r3, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_0822C9C6:
	ldr r2, [sp, #0x14]
	muls r0, r2, r0
	add r0, ip
	lsls r2, r0, #8
	movs r7, #0x1f
	ands r3, r7
	asrs r1, r3, #1
	lsls r1, r1, #4
	mov r7, sl
	adds r0, r2, r7
	adds r0, r0, r1
	lsls r0, r0, #1
	ldr r1, [sp, #0x70]
	adds r0, r0, r1
	ldrh r2, [r0]
	cmp r5, #0
	bne _0822CA06
	lsls r0, r3, #5
	adds r0, r4, r0
	lsls r0, r0, #1
	adds r0, r0, r6
	lsls r2, r2, #3
	add r2, sb
	ldrh r1, [r2]
	strh r1, [r0]
	adds r0, r3, #1
	lsls r0, r0, #5
	adds r0, r4, r0
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r1, [r2, #4]
	b _0822CA22
_0822CA06:
	lsls r0, r3, #5
	adds r0, r4, r0
	lsls r0, r0, #1
	adds r0, r0, r6
	lsls r2, r2, #3
	add r2, sb
	ldrh r1, [r2, #2]
	strh r1, [r0]
	adds r0, r3, #1
	lsls r0, r0, #5
	adds r0, r4, r0
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r1, [r2, #6]
_0822CA22:
	strh r1, [r0]
	movs r2, #2
	add r8, r2
	mov r3, r8
	cmp r3, #0x1f
	ble _0822C9B4
	ldr r7, [sp, #0x48]
	ldr r4, [sp, #0x30]
	cmp r7, r4
	blt _0822C98C
	b _0822CCB4
_0822CA38:
	ldr r0, [sp, #8]
	adds r0, #1
	cmp r0, #2
	bhi _0822CA4C
	cmp r5, #2
	bgt _0822CA4C
	movs r0, #2
	rsbs r0, r0, #0
	cmp r5, r0
	bge _0822CB04
_0822CA4C:
	movs r7, #0
	mov r8, r7
_0822CA50:
	ldr r4, [sp, #4]
	add r4, r8
	adds r0, r4, #0
	ldr r1, [sp, #0x10]
	bl Mod
	cmp r0, #0
	blt _0822CA64
	asrs r0, r0, #5
	b _0822CA6A
_0822CA64:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_0822CA6A:
	ldr r2, [sp, #0x14]
	adds r1, r0, #0
	muls r1, r2, r1
	str r1, [sp, #0x34]
	movs r0, #0x1f
	ands r4, r0
	asrs r0, r4, #1
	lsls r0, r0, #4
	mov sl, r0
	lsls r3, r4, #5
	adds r0, r4, #1
	lsls r5, r0, #5
	movs r7, #0
	movs r4, #2
	add r8, r4
_0822CA88:
	ldr r0, [sp]
	adds r4, r0, r7
	adds r0, r4, #0
	ldr r1, [sp, #0xc]
	str r3, [sp, #0x44]
	bl Mod
	ldr r3, [sp, #0x44]
	cmp r0, #0
	blt _0822CAA0
	asrs r0, r0, #5
	b _0822CAA6
_0822CAA0:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_0822CAA6:
	ldr r1, [sp, #0x34]
	adds r0, r0, r1
	lsls r2, r0, #8
	movs r0, #0x1f
	ands r4, r0
	asrs r0, r4, #1
	adds r0, r2, r0
	add r0, sl
	lsls r0, r0, #1
	ldr r2, [sp, #0x70]
	adds r0, r0, r2
	ldrh r2, [r0]
	movs r0, #1
	ands r0, r4
	cmp r0, #0
	bne _0822CADE
	adds r0, r4, r3
	lsls r0, r0, #1
	adds r0, r0, r6
	lsls r2, r2, #3
	add r2, sb
	ldrh r1, [r2]
	strh r1, [r0]
	adds r0, r4, r5
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r1, [r2, #4]
	b _0822CAF4
_0822CADE:
	adds r0, r4, r3
	lsls r0, r0, #1
	adds r0, r0, r6
	lsls r2, r2, #3
	add r2, sb
	ldrh r1, [r2, #2]
	strh r1, [r0]
	adds r0, r4, r5
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r1, [r2, #6]
_0822CAF4:
	strh r1, [r0]
	adds r7, #1
	cmp r7, #0x1f
	ble _0822CA88
	mov r3, r8
	cmp r3, #0x1f
	ble _0822CA50
	b _0822CCB4
_0822CB04:
	cmp r5, #0
	beq _0822CBD6
	cmp r5, #0
	ble _0822CB16
	movs r0, #0x20
	subs r0, r0, r5
	movs r4, #0x20
	str r4, [sp, #0x38]
	b _0822CB1C
_0822CB16:
	movs r0, #0
	rsbs r5, r5, #0
	str r5, [sp, #0x38]
_0822CB1C:
	mov r8, r0
	ldr r7, [sp, #0x38]
	cmp r8, r7
	bge _0822CBD6
_0822CB24:
	ldr r4, [sp, #4]
	add r4, r8
	adds r0, r4, #0
	ldr r1, [sp, #0x10]
	bl Mod
	cmp r0, #0
	blt _0822CB38
	asrs r0, r0, #5
	b _0822CB3E
_0822CB38:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_0822CB3E:
	ldr r2, [sp, #0x14]
	adds r1, r0, #0
	muls r1, r2, r1
	str r1, [sp, #0x3c]
	movs r0, #0x1f
	ands r4, r0
	asrs r0, r4, #1
	lsls r0, r0, #4
	mov sl, r0
	lsls r3, r4, #5
	adds r0, r4, #1
	lsls r5, r0, #5
	movs r7, #0
	movs r4, #2
	add r8, r4
_0822CB5C:
	ldr r0, [sp]
	adds r4, r0, r7
	adds r0, r4, #0
	ldr r1, [sp, #0xc]
	str r3, [sp, #0x44]
	bl Mod
	ldr r3, [sp, #0x44]
	cmp r0, #0
	blt _0822CB74
	asrs r0, r0, #5
	b _0822CB7A
_0822CB74:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_0822CB7A:
	ldr r1, [sp, #0x3c]
	adds r0, r0, r1
	lsls r2, r0, #8
	movs r0, #0x1f
	ands r4, r0
	asrs r0, r4, #1
	adds r0, r2, r0
	add r0, sl
	lsls r0, r0, #1
	ldr r2, [sp, #0x70]
	adds r0, r0, r2
	ldrh r2, [r0]
	movs r0, #1
	ands r0, r4
	cmp r0, #0
	bne _0822CBB2
	adds r0, r4, r3
	lsls r0, r0, #1
	adds r0, r0, r6
	lsls r2, r2, #3
	add r2, sb
	ldrh r1, [r2]
	strh r1, [r0]
	adds r0, r4, r5
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r1, [r2, #4]
	b _0822CBC8
_0822CBB2:
	adds r0, r4, r3
	lsls r0, r0, #1
	adds r0, r0, r6
	lsls r2, r2, #3
	add r2, sb
	ldrh r1, [r2, #2]
	strh r1, [r0]
	adds r0, r4, r5
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r1, [r2, #6]
_0822CBC8:
	strh r1, [r0]
	adds r7, #1
	cmp r7, #0x1f
	ble _0822CB5C
	ldr r3, [sp, #0x38]
	cmp r8, r3
	blt _0822CB24
_0822CBD6:
	ldr r4, [sp, #8]
	cmp r4, #0
	beq _0822CCB4
	cmp r4, #0
	ble _0822CBEA
	movs r0, #0x20
	subs r0, r0, r4
	movs r7, #0x20
	str r7, [sp, #0x40]
	b _0822CBF2
_0822CBEA:
	movs r0, #0
	ldr r1, [sp, #8]
	rsbs r1, r1, #0
	str r1, [sp, #0x40]
_0822CBF2:
	adds r7, r0, #0
	ldr r2, [sp, #0x40]
	cmp r7, r2
	bge _0822CCB4
_0822CBFA:
	ldr r3, [sp]
	adds r5, r3, r7
	adds r0, r5, #0
	ldr r1, [sp, #0xc]
	bl Mod
	cmp r0, #0
	blt _0822CC0E
	asrs r0, r0, #5
	b _0822CC14
_0822CC0E:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_0822CC14:
	mov sl, r0
	movs r0, #0x1f
	ands r5, r0
	asrs r3, r5, #1
	movs r4, #0
	mov r8, r4
	adds r0, r7, #1
	str r0, [sp, #0x48]
_0822CC24:
	ldr r4, [sp, #4]
	add r4, r8
	adds r0, r4, #0
	ldr r1, [sp, #0x10]
	str r3, [sp, #0x44]
	bl Mod
	ldr r3, [sp, #0x44]
	cmp r0, #0
	blt _0822CC3C
	asrs r0, r0, #5
	b _0822CC42
_0822CC3C:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_0822CC42:
	ldr r1, [sp, #0x14]
	muls r0, r1, r0
	add r0, sl
	lsls r2, r0, #8
	movs r0, #0x1f
	ands r4, r0
	asrs r1, r4, #1
	lsls r1, r1, #4
	adds r0, r2, r3
	adds r0, r0, r1
	lsls r0, r0, #1
	ldr r2, [sp, #0x70]
	adds r0, r0, r2
	ldrh r2, [r0]
	movs r0, #1
	ands r0, r5
	cmp r0, #0
	bne _0822CC84
	lsls r0, r4, #5
	adds r0, r5, r0
	lsls r0, r0, #1
	adds r0, r0, r6
	lsls r2, r2, #3
	add r2, sb
	ldrh r1, [r2]
	strh r1, [r0]
	adds r0, r4, #1
	lsls r0, r0, #5
	adds r0, r5, r0
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r1, [r2, #4]
	b _0822CCA0
_0822CC84:
	lsls r0, r4, #5
	adds r0, r5, r0
	lsls r0, r0, #1
	adds r0, r0, r6
	lsls r2, r2, #3
	add r2, sb
	ldrh r1, [r2, #2]
	strh r1, [r0]
	adds r0, r4, #1
	lsls r0, r0, #5
	adds r0, r5, r0
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r1, [r2, #6]
_0822CCA0:
	strh r1, [r0]
	movs r4, #2
	add r8, r4
	mov r7, r8
	cmp r7, #0x1f
	ble _0822CC24
	ldr r7, [sp, #0x48]
	ldr r0, [sp, #0x40]
	cmp r7, r0
	blt _0822CBFA
_0822CCB4:
	add sp, #0x4c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
