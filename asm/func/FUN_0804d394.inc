	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r6, r0, #0
	movs r0, #0x9a
	lsls r0, r0, #1
	adds r7, r6, r0
	movs r0, #0
	bl ClearBGTilemapBuffer
	movs r4, #0
	strb r4, [r6, #0x1f]
	movs r1, #0xba
	lsls r1, r1, #1
	adds r0, r6, r1
	bl FUN_0823a76c
	adds r5, r6, #0
	adds r5, #0x70
	adds r0, r5, #0
	movs r1, #0x10
	bl ClearMemory
	adds r0, r6, #0
	adds r0, #0x80
	movs r1, #0x10
	bl ClearMemory
	adds r0, r6, #0
	bl FUN_0804ce0c
	adds r0, r6, #0
	adds r0, #0xe8
	strb r4, [r0]
	adds r0, #1
	strb r4, [r0]
	subs r0, #2
	movs r2, #1
	movs r1, #1
	strb r1, [r0]
	subs r0, #1
	strb r1, [r0]
	ldrb r0, [r7, #2]
	adds r3, r6, #0
	adds r3, #0x37
	strb r0, [r3]
	ldr r0, _0804D51C @ =0x03005800
	ldr r0, [r0]
	ldrb r0, [r0, #2]
	lsls r0, r0, #1
	orrs r0, r2
	strb r0, [r7, #2]
	adds r2, r6, #0
	adds r2, #0x72
	strb r0, [r2]
	strb r1, [r5]
	adds r0, r6, #0
	adds r0, #0x71
	strb r1, [r0]
	movs r5, #0
	movs r3, #2
	adds r2, r0, #0
_0804D416:
	ldrb r1, [r7, #2]
	adds r0, r3, #0
	lsls r0, r5
	ands r1, r0
	cmp r1, #0
	beq _0804D428
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
_0804D428:
	adds r5, #1
	cmp r5, #3
	ble _0804D416
	adds r1, r6, #0
	adds r1, #0x36
	movs r0, #1
	strb r0, [r1]
	movs r5, #0
	adds r2, r6, #0
	adds r2, #0x70
	str r2, [sp]
	movs r4, #0xe0
	adds r4, r4, r6
	mov r8, r4
	movs r0, #0xe4
	adds r0, r0, r6
	mov sb, r0
	movs r1, #0xe5
	adds r1, r1, r6
	mov sl, r1
	subs r2, #0x3e
	str r2, [sp, #4]
	movs r4, #0xd0
	adds r4, r4, r6
	mov ip, r4
	movs r1, #0
	adds r0, r6, #0
	adds r0, #0xd4
	str r0, [sp, #8]
	adds r3, r6, #0
	adds r3, #0xd8
	adds r2, #0xaa
_0804D468:
	mov r4, ip
	adds r0, r4, r5
	strb r1, [r0]
	ldr r4, [sp, #8]
	adds r0, r4, r5
	strb r1, [r0]
	adds r0, r3, r5
	strb r1, [r0]
	adds r0, r2, r5
	strb r1, [r0]
	adds r5, #1
	cmp r5, #3
	ble _0804D468
	movs r0, #0
	mov r1, r8
	str r0, [r1]
	mov r2, sb
	strb r0, [r2]
	mov r4, sl
	strb r0, [r4]
	ldr r0, _0804D520 @ =FUN_0804d0ac
	bl rfu_LMAN_setLMANCallback
	ldr r0, _0804D524 @ =FUN_0804d308
	bl rfu_LMAN_setMSCCallback
	movs r5, #0
	adds r4, r6, #0
	adds r4, #0x80
_0804D4A2:
	ldrb r1, [r7, #2]
	movs r0, #2
	mov r8, r0
	lsls r0, r5
	ands r1, r0
	cmp r1, #0
	beq _0804D4BE
	lsls r1, r5, #0x18
	lsrs r1, r1, #0x18
	movs r0, #0x10
	adds r2, r4, #0
	movs r3, #4
	bl rfu_setRecvBuffer
_0804D4BE:
	adds r4, #4
	adds r5, #1
	cmp r5, #3
	ble _0804D4A2
	ldrb r0, [r7, #2]
	lsrs r0, r0, #1
	ldr r1, [sp]
	movs r2, #0x10
	bl rfu_UNI_setSendData
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0804D528
	movs r5, #0
	ldrb r1, [r7, #2]
	adds r0, r1, #0
	mov r2, r8
	ands r0, r2
	adds r2, r6, #0
	adds r2, #0x20
	adds r7, r6, #0
	adds r7, #0x34
	cmp r0, #0
	bne _0804D500
	movs r3, #2
_0804D4F0:
	adds r5, #1
	cmp r5, #3
	bgt _0804D500
	adds r0, r3, #0
	lsls r0, r5
	ands r0, r1
	cmp r0, #0
	beq _0804D4F0
_0804D500:
	movs r4, #0
	strb r5, [r2]
	ldrb r0, [r2]
	bl rfu_UNI_readySendData
	movs r1, #1
	strb r1, [r7]
	movs r0, #0x13
	strb r4, [r6, #0x1c]
	strh r0, [r6, #0x38]
	str r4, [r6, #0x44]
	ldr r4, [sp, #4]
	strb r1, [r4]
	b _0804D538
	.align 2, 0
_0804D51C: .4byte 0x03005800
_0804D520: .4byte FUN_0804d0ac
_0804D524: .4byte FUN_0804d308
_0804D528:
	movs r1, #0x1b
	movs r0, #0
	strb r0, [r6, #0x1c]
	strh r1, [r6, #0x38]
	str r0, [r6, #0x44]
	movs r0, #1
	ldr r1, [sp, #4]
	strb r0, [r1]
_0804D538:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
