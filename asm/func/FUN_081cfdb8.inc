	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	adds r1, r0, #0
	ldr r0, _081D0058 @ =0x030047A4
	ldr r7, [r0]
	movs r0, #0x80
	lsls r0, r0, #4
	ands r7, r0
	cmp r7, #0
	beq _081CFDD6
	b _081D0046
_081CFDD6:
	adds r0, r1, #0
	adds r0, #0xb0
	ldrh r0, [r0]
	cmp r0, #1
	ble _081CFDE2
	b _081D0046
_081CFDE2:
	cmp r0, #0
	bge _081CFDE8
	b _081D0046
_081CFDE8:
	adds r6, r1, #0
	adds r6, #0x80
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	ldr r0, _081D005C @ =0x0203B400
	mov sl, r0
	ldr r4, _081D0060 @ =0x030046B8
	ldr r2, [r4]
	adds r2, #1
	ldr r1, _081D0064 @ =0x000003FF
	mov r8, r1
	ands r2, r1
	lsls r0, r2, #1
	add r0, sl
	ldrh r3, [r0]
	add r0, sp, #0x20
	ldrh r1, [r0]
	adds r1, #0x5c
	movs r0, #0x3f
	mov sb, r0
	mov r0, sb
	ands r3, r0
	subs r1, r1, r3
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, _081D0068 @ =0xFFFF0000
	ldr r0, [sp, #0x20]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0x20]
	adds r2, #1
	mov r1, r8
	ands r2, r1
	str r2, [r4]
	lsls r2, r2, #1
	add r2, sl
	ldrh r0, [r2]
	add r5, sp, #0x20
	ldrh r1, [r5, #4]
	adds r1, #0x5c
	mov r2, sb
	ands r0, r2
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #0x24]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0x24]
	movs r3, #4
	str r3, [sp]
	str r7, [sp, #4]
	str r7, [sp, #8]
	movs r0, #0x20
	str r0, [sp, #0xc]
	movs r1, #0x40
	str r1, [sp, #0x10]
	movs r2, #1
	str r2, [sp, #0x14]
	str r2, [sp, #0x18]
	movs r3, #0x80
	lsls r3, r3, #2
	str r3, [sp, #0x1c]
	adds r0, r5, #0
	movs r1, #8
	movs r2, #8
	movs r3, #4
	bl FUN_081ee584
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	ldr r1, [r4]
	adds r1, #1
	mov r0, r8
	ands r1, r0
	lsls r0, r1, #1
	add r0, sl
	ldrh r2, [r0]
	add r0, sp, #0x20
	ldrh r0, [r0]
	subs r0, #0x5c
	mov r3, sb
	ands r2, r3
	subs r0, r0, r2
	add r2, sp, #0x20
	strh r0, [r2]
	adds r1, #1
	mov r0, r8
	ands r1, r0
	str r1, [r4]
	lsls r1, r1, #1
	add r1, sl
	ldrh r1, [r1]
	ldrh r0, [r5, #4]
	subs r0, #0x5c
	ands r1, r3
	subs r0, r0, r1
	strh r0, [r5, #4]
	movs r1, #4
	str r1, [sp]
	str r7, [sp, #4]
	str r7, [sp, #8]
	movs r2, #0x20
	str r2, [sp, #0xc]
	movs r3, #0x40
	str r3, [sp, #0x10]
	movs r0, #1
	str r0, [sp, #0x14]
	str r0, [sp, #0x18]
	movs r1, #0x80
	lsls r1, r1, #2
	str r1, [sp, #0x1c]
	add r0, sp, #0x20
	movs r1, #8
	movs r2, #8
	movs r3, #4
	bl FUN_081ee584
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	ldr r1, [r4]
	adds r1, #1
	mov r2, r8
	ands r1, r2
	lsls r0, r1, #1
	add r0, sl
	ldrh r2, [r0]
	add r0, sp, #0x20
	ldrh r0, [r0]
	subs r0, #0x5c
	mov r3, sb
	ands r2, r3
	subs r0, r0, r2
	add r2, sp, #0x20
	strh r0, [r2]
	adds r1, #1
	mov r0, r8
	ands r1, r0
	str r1, [r4]
	lsls r1, r1, #1
	add r1, sl
	ldrh r1, [r1]
	ldrh r0, [r5, #4]
	adds r0, #0x5c
	ands r1, r3
	subs r0, r0, r1
	strh r0, [r5, #4]
	movs r1, #4
	str r1, [sp]
	str r7, [sp, #4]
	str r7, [sp, #8]
	movs r2, #0x20
	str r2, [sp, #0xc]
	movs r3, #0x40
	str r3, [sp, #0x10]
	movs r0, #1
	str r0, [sp, #0x14]
	str r0, [sp, #0x18]
	movs r1, #0x80
	lsls r1, r1, #2
	str r1, [sp, #0x1c]
	add r0, sp, #0x20
	movs r1, #8
	movs r2, #8
	movs r3, #4
	bl FUN_081ee584
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	ldr r1, [r4]
	adds r1, #1
	mov r2, r8
	ands r1, r2
	lsls r0, r1, #1
	add r0, sl
	ldrh r2, [r0]
	add r0, sp, #0x20
	ldrh r0, [r0]
	adds r0, #0x5c
	mov r3, sb
	ands r2, r3
	subs r0, r0, r2
	add r2, sp, #0x20
	strh r0, [r2]
	adds r1, #1
	mov r0, r8
	ands r1, r0
	str r1, [r4]
	lsls r1, r1, #1
	add r1, sl
	ldrh r1, [r1]
	ldrh r0, [r5, #4]
	subs r0, #0x5c
	ands r1, r3
	subs r0, r0, r1
	strh r0, [r5, #4]
	movs r5, #2
	str r5, [sp]
	str r7, [sp, #4]
	str r7, [sp, #8]
	movs r1, #0x20
	str r1, [sp, #0xc]
	movs r2, #0x40
	str r2, [sp, #0x10]
	movs r3, #1
	str r3, [sp, #0x14]
	str r3, [sp, #0x18]
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp, #0x1c]
	add r0, sp, #0x20
	movs r1, #8
	movs r2, #8
	movs r3, #4
	bl FUN_081ee584
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	ldr r0, [r4]
	adds r0, #1
	mov r1, r8
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	add r0, sl
	ldrh r1, [r0]
	add r0, sp, #0x20
	ldrh r0, [r0]
	subs r0, #0x5c
	mov r2, sb
	ands r1, r2
	subs r0, r0, r1
	add r1, sp, #0x20
	strh r0, [r1]
	str r5, [sp]
	str r7, [sp, #4]
	str r7, [sp, #8]
	movs r3, #0x20
	str r3, [sp, #0xc]
	movs r0, #0x40
	str r0, [sp, #0x10]
	movs r1, #1
	str r1, [sp, #0x14]
	str r1, [sp, #0x18]
	movs r2, #0x80
	lsls r2, r2, #2
	str r2, [sp, #0x1c]
	add r0, sp, #0x20
	movs r1, #8
	movs r2, #8
	movs r3, #4
	bl FUN_081ee584
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	ldr r0, [r4]
	adds r0, #1
	mov r3, r8
	ands r0, r3
	str r0, [r4]
	lsls r0, r0, #1
	add r0, sl
	ldrh r1, [r0]
	add r0, sp, #0x20
	ldrh r0, [r0]
	adds r0, #0x5c
	mov r2, sb
	ands r1, r2
	subs r0, r0, r1
	add r1, sp, #0x20
	strh r0, [r1]
	movs r3, #4
	str r3, [sp]
	str r7, [sp, #4]
	str r7, [sp, #8]
	movs r0, #0x20
	str r0, [sp, #0xc]
	movs r1, #0x40
	str r1, [sp, #0x10]
	movs r2, #1
	str r2, [sp, #0x14]
	str r2, [sp, #0x18]
	movs r3, #0x80
	lsls r3, r3, #2
	str r3, [sp, #0x1c]
	add r0, sp, #0x20
	movs r1, #8
	movs r2, #8
	movs r3, #4
	bl FUN_081ee584
_081D0046:
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D0058: .4byte 0x030047A4
_081D005C: .4byte 0x0203B400
_081D0060: .4byte 0x030046B8
_081D0064: .4byte 0x000003FF
_081D0068: .4byte 0xFFFF0000
