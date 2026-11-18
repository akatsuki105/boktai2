	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r4, r0, #0
	ldr r1, _08196BA0 @ =0x00000CEC
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _08196BCA
	movs r3, #0x8a
	lsls r3, r3, #3
	adds r1, r4, r3
	ldr r2, [r1]
	cmp r2, #0
	bgt _08196BB8
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
	ldr r3, _08196BA4 @ =0x00000C38
	adds r1, r4, r3
	ldr r0, _08196BA8 @ =FUN_081976f4
	str r0, [r1]
	movs r6, #0
	movs r0, #0x60
	adds r0, r0, r4
	mov ip, r0
	ldr r1, _08196BAC @ =FUN_08196ab4
	mov r8, r1
	movs r7, #4
	adds r3, r4, #0
	movs r5, #0
_08196B68:
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
	ldr r0, _08196BB0 @ =0x000002C6
	adds r1, r3, r0
	ldrh r0, [r1]
	orrs r0, r7
	strh r0, [r1]
	adds r3, #0x50
	adds r5, #0x2c
	adds r6, #1
	cmp r6, #3
	ble _08196B68
	ldr r1, _08196BB4 @ =0x00000C4C
	adds r0, r4, r1
	mov r3, r8
	str r3, [r0]
	b _08196BCA
	.align 2, 0
_08196BA0: .4byte 0x00000CEC
_08196BA4: .4byte 0x00000C38
_08196BA8: .4byte FUN_081976f4
_08196BAC: .4byte FUN_08196ab4
_08196BB0: .4byte 0x000002C6
_08196BB4: .4byte 0x00000C4C
_08196BB8:
	ldr r3, _08196BD8 @ =0x00000ACC
	adds r0, r4, r3
	ldrh r0, [r0]
	subs r0, r2, r0
	str r0, [r1]
	cmp r0, #0
	bge _08196BC8
	movs r0, #0
_08196BC8:
	str r0, [r1]
_08196BCA:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08196BD8: .4byte 0x00000ACC
