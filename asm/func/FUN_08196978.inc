	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r4, r0, #0
	ldr r1, _08196A4C @ =0x00000CEC
	adds r0, r4, r1
	ldr r0, [r0]
	movs r2, #7
	ands r0, r2
	cmp r0, #0
	bne _081969A8
	movs r0, #0x89
	lsls r0, r0, #3
	adds r1, r4, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #7
	ble _081969A8
	strb r2, [r1]
_081969A8:
	movs r5, #0
	movs r1, #0x89
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r5, r0
	bge _08196A3C
	adds r0, r1, #0
	adds r0, r0, r4
	mov sb, r0
	mov sl, r5
_081969C2:
	ldr r0, _08196A50 @ =0x00000AE6
	adds r1, r4, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x80
	bne _08196A30
	adds r7, r4, #0
	adds r7, #0x4a
	movs r1, #0x4b
	adds r1, r1, r4
	mov r8, r1
	adds r6, r4, #0
	adds r6, #0x45
	cmp r5, #3
	bgt _08196A02
	movs r3, #0x80
	movs r2, #1
	movs r0, #0x2c
	muls r0, r5, r0
	adds r0, #0x60
	adds r1, r0, r4
_081969F2:
	strb r3, [r1, #6]
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r1, #0x2c
	adds r5, #1
	cmp r5, #3
	ble _081969F2
_08196A02:
	mov r1, sl
	mov r0, sb
	strb r1, [r0]
	adds r0, r4, #0
	bl FUN_08196358
	movs r0, #1
	strb r0, [r7]
	mov r0, sl
	mov r1, r8
	strb r0, [r1]
	ldrb r1, [r6]
	movs r0, #1
	orrs r0, r1
	strb r0, [r6]
	ldr r0, _08196A54 @ =0x00000C38
	adds r1, r4, r0
	ldr r0, _08196A58 @ =FUN_081975b8
	str r0, [r1]
	ldr r0, _08196A5C @ =0x00000C48
	adds r1, r4, r0
	ldr r0, _08196A60 @ =FUN_08196580
	str r0, [r1]
_08196A30:
	adds r5, #1
	mov r1, sb
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r5, r0
	blt _081969C2
_08196A3C:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08196A4C: .4byte 0x00000CEC
_08196A50: .4byte 0x00000AE6
_08196A54: .4byte 0x00000C38
_08196A58: .4byte FUN_081975b8
_08196A5C: .4byte 0x00000C48
_08196A60: .4byte FUN_08196580
