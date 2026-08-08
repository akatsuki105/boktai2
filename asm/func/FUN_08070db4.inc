	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	adds r6, r0, #0
	ldr r0, _08070DE4 @ =0x000009C8
	adds r5, r6, r0
	ldr r1, _08070DE8 @ =0x00000A8A
	adds r3, r6, r1
	ldrh r0, [r3]
	adds r0, #1
	strh r0, [r3]
	ldr r2, _08070DEC @ =0x00000A88
	adds r1, r6, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r4, [r1]
	cmp r0, r4
	bhi _08070DF0
_08070DDE:
	movs r0, #0
	b _0807105A
	.align 2, 0
_08070DE4: .4byte 0x000009C8
_08070DE8: .4byte 0x00000A8A
_08070DEC: .4byte 0x00000A88
_08070DF0:
	ldrh r2, [r3]
	ldrh r0, [r1]
	ldr r7, _08070E1C @ =0x00000A84
	adds r1, r6, r7
	ldrh r1, [r1]
	adds r1, r0, r1
	cmp r2, r1
	ble _08070E02
	b _0807101C
_08070E02:
	cmp r2, r1
	bne _08070E26
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08070E20
	movs r0, #0xe4
	lsls r0, r0, #2
	bl PlaySound_082406e0
	b _08070E26
	.align 2, 0
_08070E1C: .4byte 0x00000A84
_08070E20:
	ldr r0, _08070E6C @ =0x0000038E
	bl PlaySound_082406e0
_08070E26:
	adds r4, r5, #0
	adds r4, #0xc2
	ldrh r1, [r4]
	adds r3, r5, #0
	adds r3, #0xc0
	ldrh r0, [r3]
	subs r1, r1, r0
	adds r0, r5, #0
	adds r0, #0xb8
	ldrh r0, [r0]
	muls r1, r0, r1
	movs r0, #0xa8
	lsls r0, r0, #1
	subs r7, r0, r1
	movs r1, #0xff
	ands r7, r1
	ldr r2, _08070E70 @ =0x085B0A08
	adds r0, r7, #0
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r8, r0
	movs r0, #0xfa
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	mov sb, r4
	mov r8, r3
	mov ip, r2
	cmp r0, #0
	blt _08070E74
	asrs r1, r0, #0xc
	b _08070E7A
	.align 2, 0
_08070E6C: .4byte 0x0000038E
_08070E70: .4byte 0x085B0A08
_08070E74:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08070E7A:
	adds r2, r5, #0
	adds r2, #0xa2
	ldrh r0, [r2]
	adds r0, r0, r1
	adds r3, r5, #0
	adds r3, #0x9a
	strh r0, [r3]
	adds r0, r7, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	add r0, ip
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0xfa
	muls r0, r1, r0
	str r2, [sp, #0xc]
	cmp r0, #0
	blt _08070EA6
	asrs r0, r0, #0xc
	b _08070EAC
_08070EA6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08070EAC:
	mov sl, r0
	adds r2, r5, #0
	adds r2, #0xc4
	ldrb r0, [r2]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	add r0, ip
	movs r4, #0
	ldrsh r0, [r0, r4]
	mov r1, sl
	muls r1, r0, r1
	adds r0, r1, #0
	adds r4, r2, #0
	cmp r0, #0
	blt _08070ED2
	asrs r1, r0, #0xc
	b _08070ED8
_08070ED2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08070ED8:
	adds r2, r5, #0
	adds r2, #0xa0
	ldrh r0, [r2]
	adds r0, r0, r1
	adds r1, r5, #0
	adds r1, #0x98
	strh r0, [r1]
	ldrb r0, [r4]
	lsls r0, r0, #1
	add r0, ip
	movs r3, #0
	ldrsh r0, [r0, r3]
	mov r3, sl
	muls r3, r0, r3
	adds r0, r3, #0
	mov sl, r2
	mov ip, r1
	cmp r0, #0
	blt _08070F02
	asrs r1, r0, #0xc
	b _08070F08
_08070F02:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08070F08:
	adds r2, r5, #0
	adds r2, #0xa4
	ldrh r0, [r2]
	adds r0, r0, r1
	adds r1, r5, #0
	adds r1, #0x9c
	strh r0, [r1]
	mov r0, sb
	ldrh r1, [r0]
	mov r3, r8
	ldrh r0, [r3]
	adds r0, #2
	str r2, [sp, #0x10]
	cmp r1, r0
	ble _08070F40
	adds r1, r5, #0
	adds r1, #0xc5
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	blt _08070F40
	ldrb r3, [r4]
	str r0, [sp]
	adds r0, r6, #0
	mov r1, ip
	adds r2, r7, #0
	bl FUN_08070c2c
_08070F40:
	mov r7, sb
	ldrh r3, [r7]
	mov r1, r8
	ldrh r0, [r1]
	adds r2, r5, #0
	adds r2, #0xbc
	ldrh r1, [r2]
	adds r0, r0, r1
	subs r0, #2
	adds r7, r2, #0
	cmp r3, r0
	bgt _08070F5A
	b _08070DDE
_08070F5A:
	movs r3, #0xaa
	ldr r2, _08070F7C @ =0x085B0A08
	ldrb r0, [r4]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	mov ip, r2
	cmp r0, #0
	blt _08070F80
	asrs r0, r0, #0xc
	b _08070F86
	.align 2, 0
_08070F7C: .4byte 0x085B0A08
_08070F80:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08070F86:
	mov r1, sl
	ldrh r2, [r1]
	adds r2, r2, r0
	lsls r2, r2, #0x10
	mov r1, r8
	ldrh r0, [r1]
	ldrh r1, [r7]
	adds r0, r0, r1
	mov r7, sb
	ldrh r1, [r7]
	subs r0, r0, r1
	adds r0, #1
	movs r1, #0x5a
	muls r0, r1, r0
	ldr r1, [sp, #0xc]
	ldrh r1, [r1]
	adds r0, r0, r1
	ldr r7, _08070FC8 @ =0xFFFFFEFC
	adds r0, r0, r7
	lsls r0, r0, #0x10
	lsrs r2, r2, #0x10
	orrs r2, r0
	str r2, [sp, #4]
	ldrb r0, [r4]
	lsls r0, r0, #1
	add r0, ip
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _08070FCC
	asrs r0, r0, #0xc
	b _08070FD2
	.align 2, 0
_08070FC8: .4byte 0xFFFFFEFC
_08070FCC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08070FD2:
	ldr r2, [sp, #0x10]
	ldrh r1, [r2]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08071018 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #8]
	adds r0, r5, #0
	adds r0, #0xc5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _08070FFE
	movs r1, #0x80
	lsls r1, r1, #0xc
	ldr r0, [r6, #0x20]
	orrs r0, r1
	str r0, [r6, #0x20]
_08070FFE:
	movs r3, #0xa1
	lsls r3, r3, #4
	adds r0, r6, r3
	add r1, sp, #4
	movs r2, #0
	bl FUN_082364c4
	adds r0, r5, #0
	adds r0, #0x48
	bl FUN_08236400
	b _08070DDE
	.align 2, 0
_08071018: .4byte 0xFFFF0000
_0807101C:
	ldr r4, _0807104C @ =0x00000A86
	adds r0, r6, r4
	ldrh r0, [r0]
	adds r0, r1, r0
	cmp r2, r0
	bgt _08071054
	ldr r7, _08071050 @ =0x00000A8D
	adds r0, r6, r7
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _08071040
	movs r1, #0x80
	lsls r1, r1, #0xc
	ldr r0, [r6, #0x20]
	orrs r0, r1
	str r0, [r6, #0x20]
_08071040:
	movs r1, #0xa1
	lsls r1, r1, #4
	adds r0, r6, r1
	bl FUN_08236400
	b _08070DDE
	.align 2, 0
_0807104C: .4byte 0x00000A86
_08071050: .4byte 0x00000A8D
_08071054:
	movs r0, #0
	strh r0, [r3]
	movs r0, #1
_0807105A:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
