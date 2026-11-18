	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x80
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [sp, #0x60]
	ldr r0, _08192CE4 @ =0x03003584
	ldr r0, [r0]
	ldr r2, _08192CE8 @ =0x00003460
	adds r2, r0, r2
	str r2, [sp, #0x68]
	movs r3, #0xd4
	lsls r3, r3, #6
	adds r3, r0, r3
	str r3, [sp, #0x64]
	mov r0, sp
	adds r0, #0x20
	str r0, [sp, #0x70]
	mov r1, sp
	adds r1, #0x40
	str r1, [sp, #0x78]
	movs r2, #0x1f
	mov sl, r2
	mov sb, r1
	mov r8, r0
	mov r6, sp
	ldr r5, [sp, #0x68]
	adds r4, r3, #0
	movs r7, #0xf
_08192C38:
	ldrh r2, [r4]
	movs r1, #0x1f
	adds r0, r1, #0
	ands r0, r2
	ldrh r2, [r5]
	ands r1, r2
	subs r0, r0, r1
	lsls r0, r0, #5
	strh r0, [r6]
	ldrh r1, [r4]
	lsrs r1, r1, #5
	mov r3, sl
	ands r1, r3
	ldrh r0, [r5]
	lsrs r0, r0, #5
	ands r0, r3
	subs r1, r1, r0
	lsls r1, r1, #5
	mov r0, r8
	strh r1, [r0]
	ldrh r1, [r4]
	lsrs r1, r1, #0xa
	ands r1, r3
	ldrh r0, [r5]
	lsrs r0, r0, #0xa
	ands r0, r3
	subs r1, r1, r0
	lsls r1, r1, #5
	mov r2, sb
	strh r1, [r2]
	movs r3, #0
	ldrsh r0, [r6, r3]
	movs r1, #0xa
	bl Div
	strh r0, [r6]
	mov r1, r8
	movs r2, #0
	ldrsh r0, [r1, r2]
	movs r1, #0xa
	bl Div
	mov r3, r8
	strh r0, [r3]
	mov r1, sb
	movs r2, #0
	ldrsh r0, [r1, r2]
	movs r1, #0xa
	bl Div
	mov r3, sb
	strh r0, [r3]
	movs r0, #2
	add sb, r0
	add r8, r0
	adds r6, #2
	adds r5, #2
	adds r4, #2
	subs r7, #1
	cmp r7, #0
	bge _08192C38
	movs r7, #0
	ldr r2, _08192CEC @ =0x00000E48
	ldr r1, [sp, #0x60]
	adds r2, r1, r2
	str r2, [sp, #0x6c]
_08192CBC:
	adds r3, r7, #1
	mov sl, r3
	lsls r0, r7, #5
	str r0, [sp, #0x74]
	lsls r0, r3, #1
	add r0, sl
	mov r8, r0
	ldr r5, [sp, #0x68]
	movs r6, #0
	mov r7, sp
_08192CD0:
	movs r1, #0
	ldrsh r0, [r7, r1]
	mov r2, r8
	muls r2, r0, r2
	adds r0, r2, #0
	cmp r0, #0
	blt _08192CF0
	asrs r0, r0, #5
	b _08192CF6
	.align 2, 0
_08192CE4: .4byte 0x03003584
_08192CE8: .4byte 0x00003460
_08192CEC: .4byte 0x00000E48
_08192CF0:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_08192CF6:
	mov sb, r0
	ldr r3, [sp, #0x70]
	adds r0, r3, r6
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r2, r8
	muls r2, r0, r2
	adds r0, r2, #0
	cmp r0, #0
	blt _08192D0E
	asrs r0, r0, #5
	b _08192D14
_08192D0E:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_08192D14:
	mov ip, r0
	ldr r3, [sp, #0x78]
	adds r0, r3, r6
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r2, r8
	muls r2, r0, r2
	adds r0, r2, #0
	cmp r0, #0
	blt _08192D2C
	asrs r4, r0, #5
	b _08192D32
_08192D2C:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r4, r0, #0
_08192D32:
	ldr r0, [sp, #0x74]
	adds r3, r6, r0
	ldr r1, [sp, #0x6c]
	adds r3, r1, r3
	str r3, [sp, #0x7c]
	ldrh r1, [r5]
	movs r2, #0x1f
	ands r2, r1
	add r2, sb
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x15
	movs r3, #0x1f
	ands r0, r3
	add r0, ip
	lsls r0, r0, #5
	orrs r2, r0
	lsrs r1, r1, #0x1a
	ands r1, r3
	adds r1, r1, r4
	lsls r1, r1, #0xa
	orrs r2, r1
	ldr r0, [sp, #0x7c]
	strh r2, [r0]
	adds r5, #2
	adds r6, #2
	adds r7, #2
	ldr r0, [sp, #0x68]
	adds r0, #0x1e
	cmp r5, r0
	ble _08192CD0
	mov r7, sl
	cmp r7, #1
	ble _08192CBC
	ldr r2, [sp, #0x64]
	ldr r3, [sp, #0x60]
	ldr r0, _08192DA8 @ =0x00000E88
	adds r1, r3, r0
	movs r3, #0xf
_08192D7E:
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, #2
	adds r1, #2
	subs r3, #1
	cmp r3, #0
	bge _08192D7E
	ldr r1, [sp, #0x60]
	ldr r2, _08192DAC @ =0x00000EA8
	adds r0, r1, r2
	movs r1, #0x20
	bl ClearMemory
	add sp, #0x80
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08192DA8: .4byte 0x00000E88
_08192DAC: .4byte 0x00000EA8
