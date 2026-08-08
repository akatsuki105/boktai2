	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r1
	ldr r1, _08216D20 @ =0x0000166C
	adds r6, r0, r1
	ldr r1, _08216D24 @ =0x000017A4
	adds r4, r0, r1
	movs r5, #0
_08216D06:
	ldr r1, _08216D28 @ =0x00000958
	adds r0, r6, r1
	adds r0, r0, r5
	movs r7, #0
	ldrsb r7, [r0, r7]
	cmp r5, #6
	beq _08216D3E
	cmp r5, #6
	bgt _08216D2C
	cmp r5, #0
	beq _08216D36
	b _08216D52
	.align 2, 0
_08216D20: .4byte 0x0000166C
_08216D24: .4byte 0x000017A4
_08216D28: .4byte 0x00000958
_08216D2C:
	cmp r5, #0xc
	beq _08216D44
	cmp r5, #0x12
	beq _08216D4C
	b _08216D52
_08216D36:
	movs r0, #0x9c
	lsls r0, r0, #1
	adds r4, r6, r0
	b _08216D52
_08216D3E:
	movs r1, #0x8e
	lsls r1, r1, #2
	b _08216D50
_08216D44:
	movs r0, #0xce
	lsls r0, r0, #2
	adds r4, r6, r0
	b _08216D52
_08216D4C:
	movs r1, #0x87
	lsls r1, r1, #3
_08216D50:
	adds r4, r6, r1
_08216D52:
	movs r1, #0x92
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	bl FUN_08231660
	adds r0, r0, r7
	bl FUN_08231978
	ldrb r1, [r0]
	adds r2, r5, #1
	cmp r1, #0
	beq _08216D78
_08216D6C:
	strb r1, [r4]
	adds r4, #1
	adds r0, #1
	ldrb r1, [r0]
	cmp r1, #0
	bne _08216D6C
_08216D78:
	movs r0, #0
	strb r0, [r4]
	adds r5, r2, #0
	cmp r5, #0x17
	ble _08216D06
	mov r0, r8
	cmp r0, #0
	beq _08216DCC
	movs r0, #2
	movs r1, #3
	movs r2, #0x1a
	movs r3, #4
	bl FUN_0821b28c
	movs r1, #0x9c
	lsls r1, r1, #1
	adds r2, r6, r1
	movs r0, #2
	movs r1, #3
	bl FUN_0821b2b4
	movs r0, #0x8e
	lsls r0, r0, #2
	adds r2, r6, r0
	movs r0, #0x10
	movs r1, #3
	bl FUN_0821b2b4
	movs r1, #0xce
	lsls r1, r1, #2
	adds r2, r6, r1
	movs r0, #2
	movs r1, #5
	bl FUN_0821b2b4
	movs r0, #0x87
	lsls r0, r0, #3
	adds r2, r6, r0
	movs r0, #0x10
	movs r1, #5
	bl FUN_0821b2b4
_08216DCC:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
