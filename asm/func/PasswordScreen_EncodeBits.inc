	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r0, #0
	strh r0, [r6, #0x1e]
	movs r0, #1
	strh r0, [r6, #0x1c]
	ldr r2, _08012FA8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08012FAC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08012FB0 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #7
	ands r0, r1
	adds r4, r6, #0
	adds r4, #0x20
	strb r0, [r4]
	movs r0, #0x10
	str r0, [sp]
	adds r0, r6, #0
	movs r1, #0
	mov r2, sp
	movs r3, #2
	bl FUN_08012d00
	ldrh r1, [r6, #0x1c]
	adds r0, r6, #0
	mov r2, sp
	movs r3, #3
	bl FUN_08012d00
	ldrb r1, [r4]
	adds r0, r6, #0
	mov r2, sp
	movs r3, #3
	bl FUN_08012d00
	ldr r0, _08012FB4 @ =gSystemSaveData
	ldr r0, [r0]
	ldr r1, [r0, #0x20]
	adds r0, r6, #0
	mov r2, sp
	movs r3, #6
	bl FUN_08012d00
	ldr r4, _08012FB8 @ =0x030046A0
	ldr r0, [r4]
	movs r2, #0xbe
	lsls r2, r2, #2
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r0, r6, #0
	mov r2, sp
	movs r3, #3
	bl FUN_08012d00
	ldr r0, [r4]
	ldr r1, _08012FBC @ =0x000002FA
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r0, r6, #0
	mov r2, sp
	movs r3, #4
	bl FUN_08012d00
	ldr r0, [r4]
	movs r1, #0xf8
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x13
	adds r0, r6, #0
	mov r2, sp
	movs r3, #8
	bl FUN_08012d00
	ldr r0, [r4]
	movs r2, #0xbf
	lsls r2, r2, #2
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r0, r6, #0
	mov r2, sp
	movs r3, #7
	bl FUN_08012d00
	ldr r0, [r4]
	ldr r1, _08012FC0 @ =0x00000914
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r0, r6, #0
	mov r2, sp
	movs r3, #6
	bl FUN_08012d00
	ldr r0, [r4]
	ldr r2, _08012FC4 @ =0x00000918
	adds r1, r0, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
	ldr r2, _08012FC8 @ =0x0000091A
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r1, r1, r0
	adds r0, r6, #0
	mov r2, sp
	movs r3, #6
	bl FUN_08012d00
	ldr r0, [r4]
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r1, [r0]
	asrs r1, r1, #0xc
	adds r0, r6, #0
	mov r2, sp
	movs r3, #0xa
	bl FUN_08012d00
	ldr r0, [r4]
	movs r2, #0xea
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r1, [r0]
	asrs r1, r1, #8
	adds r0, r6, #0
	mov r2, sp
	movs r3, #8
	bl FUN_08012d00
	ldr r0, [r4]
	movs r1, #0xad
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, _08012FCC @ =0x00034BC0
	bl Div
	adds r1, r0, #0
	adds r0, r6, #0
	mov r2, sp
	movs r3, #6
	bl FUN_08012d00
	ldr r0, [r4]
	movs r2, #0xf7
	lsls r2, r2, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r0, r6, #0
	mov r2, sp
	movs r3, #0x10
	bl FUN_08012d00
	ldr r1, [r4]
	movs r0, #0xf0
	lsls r0, r0, #2
	adds r4, r1, r0
	movs r5, #0
	ldrb r0, [r4]
	cmp r0, #0
	beq _08012F4E
	ldr r2, _08012FD0 @ =0x000003C1
	adds r4, r1, r2
	ldrb r0, [r4]
	adds r7, r6, #0
	adds r7, #0x2a
	cmp r0, #0
	beq _08012F4E
_08012F2C:
	ldrb r1, [r4]
	adds r0, r6, #0
	mov r2, sp
	movs r3, #8
	bl FUN_08012d00
	adds r4, #1
	adds r5, #1
	cmp r5, #4
	bgt _08012F68
	ldrb r0, [r4]
	cmp r0, #0
	beq _08012F4E
	adds r4, #1
	ldrb r0, [r4]
	cmp r0, #0
	bne _08012F2C
_08012F4E:
	adds r7, r6, #0
	adds r7, #0x2a
	cmp r5, #4
	bgt _08012F68
_08012F56:
	adds r0, r6, #0
	movs r1, #0
	mov r2, sp
	movs r3, #8
	bl FUN_08012d00
	adds r5, #1
	cmp r5, #4
	ble _08012F56
_08012F68:
	ldr r0, [sp]
	movs r3, #0x90
	subs r3, r3, r0
	adds r0, r6, #0
	movs r1, #0
	mov r2, sp
	bl FUN_08012d00
	adds r0, r6, #0
	bl FUN_08012d68
	ldr r2, _08012FD4 @ =0x0000FFFF
	movs r5, #3
	mov ip, r7
	movs r7, #0x80
	lsls r7, r7, #8
	ldr r4, _08012FD8 @ =0x00001021
_08012F8A:
	mov r1, ip
	adds r0, r1, r5
	ldrb r0, [r0]
	lsls r0, r0, #8
	eors r2, r0
	movs r1, #0
	adds r3, r5, #1
_08012F98:
	adds r0, r2, #0
	ands r0, r7
	cmp r0, #0
	beq _08012FDC
	lsls r2, r2, #1
	eors r2, r4
	b _08012FDE
	.align 2, 0
_08012FA8: .4byte 0x030046B8
_08012FAC: .4byte 0x000003FF
_08012FB0: .4byte 0x0203B400
_08012FB4: .4byte gSystemSaveData
_08012FB8: .4byte 0x030046A0
_08012FBC: .4byte 0x000002FA
_08012FC0: .4byte 0x00000914
_08012FC4: .4byte 0x00000918
_08012FC8: .4byte 0x0000091A
_08012FCC: .4byte 0x00034BC0
_08012FD0: .4byte 0x000003C1
_08012FD4: .4byte 0x0000FFFF
_08012FD8: .4byte 0x00001021
_08012FDC:
	lsls r2, r2, #1
_08012FDE:
	adds r1, #1
	cmp r1, #7
	bls _08012F98
	adds r5, r3, #0
	cmp r5, #0x17
	ble _08012F8A
	ldr r1, _08013004 @ =0x0000FFFF
	bics r1, r2
	movs r0, #0
	str r0, [sp]
	adds r0, r6, #0
	mov r2, sp
	movs r3, #0x10
	bl FUN_08012d00
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08013004: .4byte 0x0000FFFF
