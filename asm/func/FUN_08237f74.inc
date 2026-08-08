	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	ldr r0, _08237FB4 @ =0x030046D4
	mov r8, r0
	ldr r0, [r0]
	cmp r0, #0
	blt _0823800A
	bl FUN_082379ec
	ldr r0, _08237FB8 @ =0x0300078C
	ldr r4, [r0]
	ldr r0, _08237FBC @ =0x03000790
	ldr r7, [r0]
	bl FUN_082379f8
	cmp r7, #0
	ble _08238008
	ldr r1, _08237FC0 @ =0x030007A0
	adds r0, r4, r1
	ldrb r5, [r0]
	adds r4, #1
	movs r0, #0x3f
	ands r4, r0
	cmp r5, #0x3f
	ble _08237FC4
	subs r0, #0x45
	mov r1, r8
	str r0, [r1]
	b _0823800A
	.align 2, 0
_08237FB4: .4byte 0x030046D4
_08237FB8: .4byte 0x0300078C
_08237FBC: .4byte 0x03000790
_08237FC0: .4byte 0x030007A0
_08237FC4:
	adds r0, r5, #1
	cmp r0, r7
	bgt _08238008
	cmp r5, #0
	beq _08237FE6
	adds r3, r1, #0
	movs r2, #0x3f
	adds r1, r5, #0
_08237FD4:
	adds r0, r4, r3
	ldrb r0, [r0]
	strb r0, [r6]
	adds r6, #1
	adds r4, #1
	ands r4, r2
	subs r1, #1
	cmp r1, #0
	bne _08237FD4
_08237FE6:
	bl FUN_082379ec
	ldr r0, _08238000 @ =0x03000790
	ldr r1, [r0]
	subs r1, #1
	subs r1, r1, r5
	str r1, [r0]
	ldr r0, _08238004 @ =0x0300078C
	str r4, [r0]
	bl FUN_082379f8
	adds r0, r5, #0
	b _0823800A
	.align 2, 0
_08238000: .4byte 0x03000790
_08238004: .4byte 0x0300078C
_08238008:
	movs r0, #0
_0823800A:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
