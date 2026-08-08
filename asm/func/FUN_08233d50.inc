	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	str r0, [sp]
	adds r6, r1, #0
	mov sb, r2
	movs r1, #0
	ldrsh r0, [r2, r1]
	mov ip, r0
	movs r2, #0
	ldrsh r3, [r6, r2]
	subs r0, r0, r3
	str r0, [sp, #0x10]
	mov r7, sb
	movs r0, #4
	ldrsh r7, [r7, r0]
	mov r8, r7
	movs r1, #4
	ldrsh r2, [r6, r1]
	subs r7, r7, r2
	mov sl, r7
	ldrh r1, [r6, #2]
	lsls r1, r1, #0x10
	ldr r0, _08233DD8 @ =0x0000FFFF
	ands r0, r4
	adds r4, r0, #0
	orrs r4, r1
	ldrb r0, [r6]
	str r0, [sp, #0x14]
	ldrb r1, [r6, #4]
	str r1, [sp, #0x18]
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r7, [sp, #0x14]
	subs r7, r0, r7
	str r7, [sp, #0x1c]
	subs r1, r0, r1
	str r1, [sp, #0x20]
	movs r1, #0xff
	lsls r1, r1, #8
	adds r7, r1, #0
	ands r7, r3
	ands r1, r2
	str r1, [sp, #4]
	adds r2, r7, r0
	str r2, [sp, #8]
	adds r0, r1, r0
	str r0, [sp, #0xc]
	cmp ip, r7
	blt _08233DDC
	cmp ip, r2
	bgt _08233DDC
	cmp r8, r1
	blt _08233DDC
	cmp r8, r0
	bgt _08233DDC
	mov r7, sb
	ldr r0, [r7]
	ldr r1, [r7, #4]
	ldr r2, [sp]
	str r0, [r2]
	str r1, [r2, #4]
	movs r0, #1
	b _082340B6
	.align 2, 0
_08233DD8: .4byte 0x0000FFFF
_08233DDC:
	ldr r0, [sp, #0x10]
	cmp r0, #0
	bne _08233E40
	mov r1, sl
	cmp r1, #0
	bne _08233DF8
	mov r2, sb
	ldr r0, [r2]
	ldr r1, [r2, #4]
	ldr r7, [sp]
	str r0, [r7]
	str r1, [r7, #4]
	movs r0, #1
	b _082340B6
_08233DF8:
	mov r0, sl
	cmp r0, #0
	ble _08233E14
	ldr r2, [sp, #0xc]
	lsls r1, r2, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _08233E10 @ =0xFFFF0000
	ands r0, r5
	adds r5, r0, #0
	orrs r5, r1
	b _08233E1C
	.align 2, 0
_08233E10: .4byte 0xFFFF0000
_08233E14:
	ldr r0, _08233E3C @ =0xFFFF0000
	ands r0, r5
	ldr r5, [sp, #4]
	orrs r5, r0
_08233E1C:
	ldrh r1, [r6]
	ldr r0, _08233E3C @ =0xFFFF0000
	ands r0, r4
	adds r4, r0, #0
	orrs r4, r1
	ldr r7, [sp]
	str r4, [r7]
	str r5, [r7, #4]
	movs r0, #3
	mov r1, sl
	cmp r1, #0
	bgt _08233E36
	b _082340B6
_08233E36:
	movs r0, #2
	b _082340B6
	.align 2, 0
_08233E3C: .4byte 0xFFFF0000
_08233E40:
	mov r2, sl
	cmp r2, #0
	bne _08233E8C
	ldr r0, [sp, #0x10]
	cmp r0, #0
	ble _08233E60
	ldr r2, [sp, #8]
	lsls r1, r2, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _08233E5C @ =0xFFFF0000
	ands r0, r4
	adds r4, r0, #0
	orrs r4, r1
	b _08233E68
	.align 2, 0
_08233E5C: .4byte 0xFFFF0000
_08233E60:
	ldr r0, _08233E88 @ =0xFFFF0000
	ands r0, r4
	adds r4, r0, #0
	orrs r4, r7
_08233E68:
	ldrh r1, [r6, #4]
	ldr r0, _08233E88 @ =0xFFFF0000
	ands r0, r5
	adds r5, r0, #0
	orrs r5, r1
	ldr r7, [sp]
	str r4, [r7]
	str r5, [r7, #4]
	movs r0, #4
	ldr r1, [sp, #0x10]
	cmp r1, #0
	bgt _08233E82
	b _082340B6
_08233E82:
	movs r0, #5
	b _082340B6
	.align 2, 0
_08233E88: .4byte 0xFFFF0000
_08233E8C:
	movs r2, #0x80
	lsls r2, r2, #1
	mov r8, r2
	ldr r0, [sp, #0x10]
	cmp r0, #0
	ble _08233E9E
	movs r1, #0x80
	lsls r1, r1, #5
	mov r8, r1
_08233E9E:
	mov r2, sl
	cmp r2, #0
	ble _08233EAE
	movs r0, #0x10
	mov r1, r8
	orrs r1, r0
	mov r8, r1
	b _08233EB6
_08233EAE:
	movs r0, #1
	mov r2, r8
	orrs r2, r0
	mov r8, r2
_08233EB6:
	movs r0, #0x10
	mov r1, r8
	ands r0, r1
	cmp r0, #0
	beq _08233F34
	ldr r2, [sp, #0x20]
	ldr r1, [sp, #0x10]
	adds r0, r2, #0
	muls r0, r1, r0
	mov r1, sl
	cmp r1, #0
	bge _08233ED0
	rsbs r1, r1, #0
_08233ED0:
	bl Div
	ldrh r2, [r6]
	mov ip, r2
	add r0, ip
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _08233F30 @ =0xFFFF0000
	mov sb, r1
	mov r3, sb
	ands r3, r4
	orrs r3, r0
	adds r4, r3, #0
	ldr r2, [sp, #0xc]
	lsls r1, r2, #0x10
	lsrs r1, r1, #0x10
	mov r0, sb
	ands r0, r5
	adds r5, r0, #0
	orrs r5, r1
	lsls r0, r4, #0x10
	asrs r1, r0, #0x10
	cmp r1, r7
	blt _08233F34
	ldr r0, [sp, #8]
	cmp r1, r0
	bgt _08233F34
	movs r2, #0xff
	lsls r2, r2, #8
	ands r1, r2
	movs r7, #0
	ldrsh r0, [r6, r7]
	ands r0, r2
	cmp r1, r0
	ble _08233F24
	movs r0, #0xff
	mov r1, ip
	orrs r0, r1
	mov r2, sb
	ands r3, r2
	adds r4, r3, #0
	orrs r4, r0
_08233F24:
	ldr r7, [sp]
	str r4, [r7]
	str r5, [r7, #4]
	movs r0, #3
	b _082340B6
	.align 2, 0
_08233F30: .4byte 0xFFFF0000
_08233F34:
	movs r0, #1
	mov r1, r8
	ands r0, r1
	cmp r0, #0
	beq _08233FB4
	ldr r2, [sp, #0x18]
	ldr r1, [sp, #0x10]
	adds r0, r2, #0
	muls r0, r1, r0
	mov r1, sl
	cmp r1, #0
	bge _08233F4E
	rsbs r1, r1, #0
_08233F4E:
	bl Div
	ldrh r2, [r6]
	mov ip, r2
	add r0, ip
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _08233FB0 @ =0xFFFF0000
	mov sb, r1
	mov r3, sb
	ands r3, r4
	orrs r3, r0
	adds r4, r3, #0
	ldr r1, [sp, #4]
	subs r1, #1
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r0, sb
	ands r0, r5
	adds r5, r0, #0
	orrs r5, r1
	lsls r0, r4, #0x10
	asrs r1, r0, #0x10
	cmp r1, r7
	blt _08233FB4
	ldr r2, [sp, #8]
	cmp r1, r2
	bgt _08233FB4
	movs r2, #0xff
	lsls r2, r2, #8
	ands r1, r2
	movs r7, #0
	ldrsh r0, [r6, r7]
	ands r0, r2
	cmp r1, r0
	ble _08233FA4
	movs r0, #0xff
	mov r1, ip
	orrs r0, r1
	mov r2, sb
	ands r3, r2
	adds r4, r3, #0
	orrs r4, r0
_08233FA4:
	ldr r7, [sp]
	str r4, [r7]
	str r5, [r7, #4]
	movs r0, #2
	b _082340B6
	.align 2, 0
_08233FB0: .4byte 0xFFFF0000
_08233FB4:
	movs r0, #0x80
	lsls r0, r0, #1
	mov r1, r8
	ands r0, r1
	cmp r0, #0
	beq _08234034
	subs r1, r7, #1
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08234030 @ =0xFFFF0000
	mov sb, r2
	mov r0, sb
	ands r0, r4
	adds r4, r0, #0
	orrs r4, r1
	ldr r7, [sp, #0x14]
	mov r0, sl
	muls r0, r7, r0
	ldr r1, [sp, #0x10]
	cmp r1, #0
	bge _08233FE0
	rsbs r1, r1, #0
_08233FE0:
	bl Div
	ldrh r1, [r6, #4]
	mov ip, r1
	add r0, ip
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r3, sb
	ands r3, r5
	orrs r3, r0
	adds r5, r3, #0
	lsls r0, r5, #0x10
	asrs r1, r0, #0x10
	ldr r2, [sp, #4]
	cmp r1, r2
	blt _08234034
	ldr r7, [sp, #0xc]
	cmp r1, r7
	bgt _08234034
	movs r2, #0xff
	lsls r2, r2, #8
	ands r1, r2
	movs r7, #4
	ldrsh r0, [r6, r7]
	ands r0, r2
	cmp r1, r0
	ble _08234024
	movs r0, #0xff
	mov r1, ip
	orrs r0, r1
	mov r2, sb
	ands r3, r2
	adds r5, r3, #0
	orrs r5, r0
_08234024:
	ldr r7, [sp]
	str r4, [r7]
	str r5, [r7, #4]
	movs r0, #4
	b _082340B6
	.align 2, 0
_08234030: .4byte 0xFFFF0000
_08234034:
	movs r0, #0x80
	lsls r0, r0, #5
	mov r1, r8
	ands r1, r0
	cmp r1, #0
	beq _082340B4
	ldr r2, [sp, #8]
	lsls r1, r2, #0x10
	lsrs r1, r1, #0x10
	ldr r7, _082340B0 @ =0xFFFF0000
	mov r8, r7
	mov r0, r8
	ands r0, r4
	adds r4, r0, #0
	orrs r4, r1
	ldr r1, [sp, #0x1c]
	mov r0, sl
	muls r0, r1, r0
	ldr r1, [sp, #0x10]
	cmp r1, #0
	bge _08234060
	rsbs r1, r1, #0
_08234060:
	bl Div
	ldrh r2, [r6, #4]
	mov sb, r2
	add r0, sb
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r3, r8
	ands r3, r5
	orrs r3, r0
	adds r5, r3, #0
	lsls r0, r5, #0x10
	asrs r1, r0, #0x10
	ldr r7, [sp, #4]
	cmp r1, r7
	blt _082340B4
	ldr r0, [sp, #0xc]
	cmp r1, r0
	bgt _082340B4
	movs r2, #0xff
	lsls r2, r2, #8
	ands r1, r2
	movs r7, #4
	ldrsh r0, [r6, r7]
	ands r0, r2
	cmp r1, r0
	ble _082340A4
	movs r0, #0xff
	mov r1, sb
	orrs r0, r1
	mov r2, r8
	ands r3, r2
	adds r5, r3, #0
	orrs r5, r0
_082340A4:
	ldr r7, [sp]
	str r4, [r7]
	str r5, [r7, #4]
	movs r0, #5
	b _082340B6
	.align 2, 0
_082340B0: .4byte 0xFFFF0000
_082340B4:
	movs r0, #0
_082340B6:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
