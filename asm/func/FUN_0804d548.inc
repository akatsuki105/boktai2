	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r6, r0, #0
	movs r0, #0x9a
	lsls r0, r0, #1
	adds r0, r6, r0
	str r0, [sp]
	movs r0, #0
	bl ClearBGTilemapBuffer
	movs r3, #0
	movs r2, #0xb5
	lsls r2, r2, #1
	adds r1, r6, r2
	ldr r2, _0804D650 @ =0x03005800
	ldr r0, [r2]
	adds r0, #0x94
	ldrh r1, [r1]
	ldrh r0, [r0]
	cmp r1, r0
	beq _0804D596
	adds r4, r2, #0
	movs r0, #0xb5
	lsls r0, r0, #1
	adds r2, r6, r0
_0804D582:
	adds r2, #2
	adds r3, #1
	cmp r3, #3
	bgt _0804D596
	ldr r0, [r4]
	adds r0, #0x94
	ldrh r1, [r2]
	ldrh r0, [r0]
	cmp r1, r0
	bne _0804D582
_0804D596:
	strb r3, [r6, #0x1f]
	movs r1, #0xba
	lsls r1, r1, #1
	adds r0, r6, r1
	bl FUN_0823a76c
	adds r5, r6, #0
	adds r5, #0x90
	adds r0, r5, #0
	movs r1, #4
	bl ClearMemory
	adds r4, r6, #0
	adds r4, #0x94
	adds r0, r4, #0
	movs r1, #0x10
	bl ClearMemory
	adds r0, r6, #0
	bl FUN_0804ce0c
	movs r3, #0
	mov sb, r5
	mov sl, r4
	movs r2, #0x37
	adds r2, r2, r6
	mov ip, r2
	movs r0, #0x21
	adds r0, r0, r6
	mov r8, r0
	adds r1, r6, #0
	adds r1, #0x32
	str r1, [sp, #4]
	adds r7, r6, #0
	adds r7, #0xd0
	movs r1, #0
	adds r5, #0x44
	adds r4, #0x44
	adds r2, r6, #0
	adds r2, #0xdc
_0804D5E6:
	adds r0, r7, r3
	strb r1, [r0]
	adds r0, r5, r3
	strb r1, [r0]
	adds r0, r4, r3
	strb r1, [r0]
	adds r0, r2, r3
	strb r1, [r0]
	adds r3, #1
	cmp r3, #3
	ble _0804D5E6
	ldr r2, [sp]
	ldrb r0, [r2, #2]
	movs r7, #0
	mov r1, ip
	strb r0, [r1]
	mov r2, sb
	strb r7, [r2]
	ldr r0, _0804D654 @ =FUN_0804d214
	bl rfu_LMAN_setLMANCallback
	ldr r0, _0804D658 @ =FUN_0804d36c
	bl rfu_LMAN_setMSCCallback
	mov r0, r8
	ldrb r1, [r0]
	movs r0, #0x10
	mov r2, sl
	movs r3, #0x10
	bl rfu_setRecvBuffer
	movs r4, #1
	adds r0, r4, #0
	mov r1, r8
	ldrb r1, [r1]
	lsls r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r1, sb
	movs r2, #4
	bl rfu_UNI_setSendData
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _0804D65C
	movs r0, #0x1b
	strb r7, [r6, #0x1c]
	strh r0, [r6, #0x38]
	str r7, [r6, #0x44]
	ldr r2, [sp, #4]
	strb r4, [r2]
	b _0804D66E
	.align 2, 0
_0804D650: .4byte 0x03005800
_0804D654: .4byte FUN_0804d214
_0804D658: .4byte FUN_0804d36c
_0804D65C:
	adds r0, r6, #0
	adds r0, #0x34
	strb r4, [r0]
	movs r0, #0x14
	strb r1, [r6, #0x1c]
	strh r0, [r6, #0x38]
	str r1, [r6, #0x44]
	ldr r0, [sp, #4]
	strb r4, [r0]
_0804D66E:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
