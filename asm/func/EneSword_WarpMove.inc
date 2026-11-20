	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	movs r6, #0
_08196E64:
	ldrh r2, [r7, #0x1c]
	rsbs r2, r2, #0
	strh r2, [r7, #0x1c]
	ldrh r0, [r7, #0x20]
	rsbs r0, r0, #0
	strh r0, [r7, #0x20]
	movs r0, #0x2c
	muls r0, r6, r0
	adds r3, r7, r0
	adds r1, r3, #0
	adds r1, #0x7c
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	adds r2, r3, #0
	adds r2, #0x80
	ldrh r0, [r2]
	ldrh r1, [r7, #0x20]
	subs r0, r0, r1
	strh r0, [r2]
	adds r1, r3, #0
	adds r1, #0x68
	ldrb r0, [r1]
	subs r0, #2
	strb r0, [r1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bgt _08196EA2
	movs r0, #1
	strb r0, [r1]
_08196EA2:
	adds r6, #1
	cmp r6, #3
	ble _08196E64
	ldr r1, _08197014 @ =0x00000CEC
	adds r0, r7, r1
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08196EB8
	b _08197004
_08196EB8:
	ldrh r0, [r7, #0x24]
	adds r0, #1
	strh r0, [r7, #0x24]
	ldrh r1, [r7, #0x28]
	adds r1, #1
	strh r1, [r7, #0x28]
	strh r0, [r7, #0x1c]
	strh r1, [r7, #0x20]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xf
	bgt _08196ED2
	b _08197004
_08196ED2:
	adds r0, r7, #0
	adds r0, #0x7c
	ldr r2, _08197018 @ =0x00000AFC
	adds r2, r7, r2
	str r2, [sp]
	ldrh r0, [r0]
	ldrh r1, [r2]
	subs r0, r0, r1
	strh r0, [r7, #0x1c]
	adds r0, r7, #0
	adds r0, #0x80
	movs r3, #0xb0
	lsls r3, r3, #4
	adds r5, r7, r3
	ldrh r0, [r0]
	ldrh r1, [r5]
	subs r0, r0, r1
	strh r0, [r7, #0x20]
	ldr r2, _0819701C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08197020 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08197024 @ =0x0203B400
	adds r0, r0, r1
	movs r2, #0xff
	mov sl, r2
	ldrb r4, [r0]
	adds r0, r4, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	ldr r3, _08197028 @ =gSineTable
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r6, #0xc8
	muls r0, r6, r0
	movs r2, #0x80
	lsls r2, r2, #5
	mov r8, r2
	mov r1, r8
	bl Div
	ldr r1, [r7, #0x18]
	ldrh r1, [r1, #0x2c]
	adds r1, r1, r0
	ldr r3, [sp]
	strh r1, [r3]
	ldr r1, [r7, #0x18]
	movs r2, #0xaf
	lsls r2, r2, #1
	adds r0, r2, #0
	ldrh r1, [r1, #0x2e]
	adds r0, r0, r1
	ldr r3, _0819702C @ =0x00000AFE
	adds r3, r3, r7
	mov sb, r3
	strh r0, [r3]
	mov r0, sl
	ands r4, r0
	lsls r4, r4, #1
	ldr r1, _08197028 @ =gSineTable
	adds r4, r4, r1
	movs r2, #0
	ldrsh r0, [r4, r2]
	muls r0, r6, r0
	mov r1, r8
	bl Div
	ldr r1, [r7, #0x18]
	ldrh r1, [r1, #0x30]
	adds r1, r1, r0
	strh r1, [r5]
	movs r6, #0
	adds r3, r7, #0
	adds r3, #0x60
	str r3, [sp, #8]
	ldr r0, [sp]
	mov r8, r0
	movs r1, #0x84
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #4]
	adds r4, r7, #0
	mov ip, sb
	ldr r2, _08197030 @ =0x00000422
	adds r2, r2, r7
	mov sl, r2
	ldr r3, _08197034 @ =0x00000424
	adds r3, r3, r7
	mov sb, r3
_08196F8E:
	movs r0, #0x2c
	adds r2, r6, #0
	muls r2, r0, r2
	ldr r0, [sp, #8]
	adds r3, r0, r2
	ldr r0, [r3]
	movs r1, #1
	orrs r0, r1
	str r0, [r3]
	adds r2, r7, r2
	ldrh r1, [r7, #0x1c]
	mov r3, r8
	ldrh r3, [r3]
	adds r1, r1, r3
	movs r3, #0x80
	lsls r3, r3, #3
	adds r0, r4, r3
	strh r1, [r0]
	adds r0, r2, #0
	adds r0, #0x7c
	strh r1, [r0]
	ldrh r1, [r7, #0x20]
	ldrh r0, [r5]
	adds r1, r1, r0
	adds r3, #4
	adds r0, r4, r3
	strh r1, [r0]
	adds r2, #0x80
	strh r1, [r2]
	mov r1, r8
	ldrh r0, [r1]
	ldr r2, [sp, #4]
	strh r0, [r2]
	mov r3, ip
	ldrh r0, [r3]
	mov r1, sl
	strh r0, [r1]
	ldrh r0, [r5]
	mov r2, sb
	strh r0, [r2]
	ldrh r0, [r7, #0x1c]
	rsbs r0, r0, #0
	strh r0, [r7, #0x1c]
	ldrh r0, [r7, #0x20]
	rsbs r0, r0, #0
	strh r0, [r7, #0x20]
	adds r4, #8
	adds r6, #1
	cmp r6, #3
	ble _08196F8E
	ldr r3, _08197038 @ =0x00000C64
	adds r1, r7, r3
	movs r0, #0x1e
	str r0, [r1]
	movs r0, #0xc5
	lsls r0, r0, #4
	adds r1, r7, r0
	ldr r0, _0819703C @ =EneSword_WarpAppear
	str r0, [r1]
_08197004:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08197014: .4byte 0x00000CEC
_08197018: .4byte 0x00000AFC
_0819701C: .4byte 0x030046B8
_08197020: .4byte 0x000003FF
_08197024: .4byte 0x0203B400
_08197028: .4byte gSineTable
_0819702C: .4byte 0x00000AFE
_08197030: .4byte 0x00000422
_08197034: .4byte 0x00000424
_08197038: .4byte 0x00000C64
_0819703C: .4byte EneSword_WarpAppear
