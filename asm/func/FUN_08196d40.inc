	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r4, r0, #0
	ldr r1, _08196DE4 @ =0x00000CEC
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _08196DD8
	movs r0, #0x8a
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	cmp r0, #0
	bne _08196DD8
	movs r0, #0x89
	lsls r0, r0, #3
	adds r1, r4, r0
	ldrb r0, [r1]
	rsbs r0, r0, #0
	strb r0, [r1]
	movs r0, #1
	movs r1, #2
	adds r2, r4, #0
	adds r2, #0x4a
	strb r0, [r2]
	adds r2, #1
	strb r1, [r2]
	subs r2, #6
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	ldr r0, _08196DE8 @ =0x00000C38
	adds r1, r4, r0
	ldr r0, _08196DEC @ =FUN_081976f4
	str r0, [r1]
	movs r6, #0
	movs r1, #0x60
	adds r1, r1, r4
	mov ip, r1
	ldr r0, _08196DF0 @ =FUN_08196c2c
	mov r8, r0
	movs r7, #4
	adds r3, r4, #0
	movs r5, #0
_08196DA4:
	mov r0, ip
	adds r2, r0, r5
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #0xc3
	lsls r0, r0, #1
	adds r1, r3, r0
	ldrh r0, [r1]
	orrs r0, r7
	strh r0, [r1]
	ldr r0, _08196DF4 @ =0x000002C6
	adds r1, r3, r0
	ldrh r0, [r1]
	orrs r0, r7
	strh r0, [r1]
	adds r3, #0x50
	adds r5, #0x2c
	adds r6, #1
	cmp r6, #3
	ble _08196DA4
	ldr r1, _08196DF8 @ =0x00000C4C
	adds r0, r4, r1
	mov r1, r8
	str r1, [r0]
_08196DD8:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08196DE4: .4byte 0x00000CEC
_08196DE8: .4byte 0x00000C38
_08196DEC: .4byte FUN_081976f4
_08196DF0: .4byte FUN_08196c2c
_08196DF4: .4byte 0x000002C6
_08196DF8: .4byte 0x00000C4C
