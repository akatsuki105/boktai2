	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	str r3, [sp]
	str r0, [sp, #4]
	ldr r3, _081930F4 @ =0x00000D58
	adds r7, r0, r3
	ldr r0, _081930F8 @ =0x03003584
	lsls r3, r1, #5
	ldr r0, [r0]
	lsls r2, r2, #5
	adds r2, r0, r2
	str r2, [sp, #8]
	strh r1, [r7, #0x22]
	movs r1, #0
	str r1, [sp, #0xc]
	adds r0, r0, r3
	mov sl, r0
_0819300E:
	ldr r3, [sp, #0xc]
	lsls r2, r3, #1
	ldr r1, [sp, #8]
	adds r0, r2, r1
	ldrh r4, [r0]
	movs r3, #0x84
	adds r3, r3, r7
	mov r8, r3
	add r8, r2
	mov r0, sl
	ldrh r1, [r0]
	movs r0, #0x1f
	ands r0, r1
	mov sb, r4
	mov r1, sb
	movs r3, #0x1f
	ands r1, r3
	mov sb, r1
	subs r0, r0, r1
	lsls r0, r0, #5
	mov r1, r8
	strh r0, [r1]
	adds r6, r7, #0
	adds r6, #0xa4
	adds r6, r6, r2
	mov r3, sl
	ldrh r0, [r3]
	lsrs r0, r0, #5
	movs r1, #0x1f
	ands r0, r1
	asrs r3, r4, #5
	ands r3, r1
	subs r0, r0, r3
	lsls r0, r0, #5
	strh r0, [r6]
	adds r5, r7, #0
	adds r5, #0xc4
	adds r5, r5, r2
	mov r1, sl
	ldrh r0, [r1]
	lsrs r0, r0, #0xa
	movs r1, #0x1f
	ands r0, r1
	asrs r4, r4, #0xa
	ands r4, r1
	subs r0, r0, r4
	lsls r0, r0, #5
	strh r0, [r5]
	mov r0, r8
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov ip, r0
	ldr r1, [sp]
	str r2, [sp, #0x10]
	str r3, [sp, #0x14]
	bl Div
	mov r1, r8
	strh r0, [r1]
	movs r1, #0
	ldrsh r0, [r6, r1]
	ldr r1, [sp]
	bl Div
	strh r0, [r6]
	movs r1, #0
	ldrsh r0, [r5, r1]
	ldr r1, [sp]
	bl Div
	strh r0, [r5]
	adds r0, r7, #0
	adds r0, #0x24
	ldr r2, [sp, #0x10]
	adds r0, r0, r2
	mov r1, sb
	lsls r1, r1, #5
	strh r1, [r0]
	adds r0, r7, #0
	adds r0, #0x44
	adds r0, r0, r2
	ldr r3, [sp, #0x14]
	lsls r3, r3, #5
	strh r3, [r0]
	adds r0, r7, #0
	adds r0, #0x64
	adds r0, r0, r2
	lsls r4, r4, #5
	strh r4, [r0]
	movs r3, #2
	add sl, r3
	ldr r0, [sp, #0xc]
	adds r0, #1
	str r0, [sp, #0xc]
	cmp r0, #0xf
	ble _0819300E
	mov r1, sp
	ldrh r1, [r1]
	strh r1, [r7, #0x20]
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r3, [sp, #4]
	ldr r1, _081930FC @ =0x00000F2C
	adds r2, r3, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081930F4: .4byte 0x00000D58
_081930F8: .4byte 0x03003584
_081930FC: .4byte 0x00000F2C
