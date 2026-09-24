	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x4c
	mov ip, r0
	ldr r0, _08200EB0 @ =0x000006DA
	add r0, ip
	ldrb r0, [r0]
	cmp r0, #0
	beq _08200E6E
	b _08201042
_08200E6E:
	movs r7, #0
	mov r0, ip
	adds r0, #0x28
	str r0, [sp, #0x48]
	ldr r1, _08200EB4 @ =0x030047C8
	mov sb, r1
	add r2, sp, #0x40
	mov sl, r2
	movs r3, #0x42
	add r3, sp
	mov r8, r3
	mov r6, sb
	mov r4, sp
_08200E88:
	movs r0, #0x2c
	adds r2, r7, #0
	muls r2, r0, r2
	add r2, ip
	adds r2, #0x44
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r5, r0, #0x11
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	subs r1, r5, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08200EB8
	asrs r0, r0, #8
	b _08200EBE
	.align 2, 0
_08200EB0: .4byte 0x000006DA
_08200EB4: .4byte 0x030047C8
_08200EB8:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08200EBE:
	strh r0, [r4]
	adds r1, r5, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08200ED0
	asrs r0, r0, #8
	b _08200ED6
_08200ED0:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08200ED6:
	adds r3, r0, #0
	movs r5, #2
	ldrsh r1, [r2, r5]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _08200EEA
	asrs r0, r0, #8
	b _08200EF0
_08200EEA:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08200EF0:
	subs r2, r3, r0
	adds r3, r3, r0
	ldrh r0, [r4]
	ldrh r1, [r6]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r4]
	ldrh r0, [r6, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r4, #2]
	ldrh r0, [r6, #4]
	subs r3, r3, r0
	strh r3, [r4, #4]
	adds r4, #8
	adds r7, #1
	cmp r7, #7
	ble _08200E88
	movs r0, #0xbc
	lsls r0, r0, #1
	add r0, ip
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0x40]
	str r1, [sp, #0x44]
	mov r1, r8
	ldrh r0, [r1]
	subs r0, #0x40
	strh r0, [r1]
	mov r4, sl
	adds r5, r4, #0
	ldrh r0, [r4]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08200F4A
	asrs r0, r0, #8
	b _08200F50
_08200F4A:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08200F50:
	strh r0, [r4]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08200F62
	asrs r0, r0, #8
	b _08200F68
_08200F62:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08200F68:
	adds r3, r0, #0
	movs r2, #2
	ldrsh r1, [r5, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _08200F7C
	asrs r0, r0, #8
	b _08200F82
_08200F7C:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08200F82:
	subs r2, r3, r0
	adds r3, r3, r0
	ldrh r0, [r4]
	mov r5, sb
	ldrh r1, [r5]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r4]
	ldrh r0, [r5, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r4, #2]
	ldrh r0, [r5, #4]
	subs r3, r3, r0
	strh r3, [r4, #4]
	ldr r6, [sp, #0x48]
	mov r2, sp
	movs r7, #0
	movs r0, #0xc4
	lsls r0, r0, #1
	add r0, ip
	mov r8, r0
	movs r5, #0xc4
	lsls r5, r5, #1
	add r5, ip
_08200FB4:
	cmp r7, #0
	bne _08200FEE
	adds r4, r2, #0
	adds r4, #8
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r3, #8
	ldrsh r1, [r2, r3]
	subs r0, r0, r1
	movs r3, #2
	ldrsh r1, [r2, r3]
	movs r3, #2
	ldrsh r2, [r4, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	subs r0, #0x1f
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	mov r0, r8
	strb r1, [r0]
	b _08201024
_08200FEE:
	adds r4, r2, #0
	adds r4, #8
	adds r3, r2, #0
	subs r3, #8
	movs r1, #0
	ldrsh r0, [r3, r1]
	movs r1, #8
	ldrsh r2, [r2, r1]
	subs r0, r0, r2
	movs r2, #2
	ldrsh r1, [r3, r2]
	movs r3, #2
	ldrsh r2, [r4, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	subs r0, #0x1f
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	strb r1, [r5]
_08201024:
	cmp r7, #2
	ble _08201032
	cmp r7, #4
	bgt _08201032
	ldrb r0, [r5]
	adds r0, #8
	b _08201034
_08201032:
	ldrb r0, [r5]
_08201034:
	strh r0, [r6, #0x10]
	adds r6, #0x2c
	adds r2, r4, #0
	adds r5, #1
	adds r7, #1
	cmp r7, #7
	ble _08200FB4
_08201042:
	add sp, #0x4c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
