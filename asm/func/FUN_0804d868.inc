	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r0, #0x9a
	lsls r0, r0, #1
	adds r7, r5, r0
	movs r0, #0
	bl ClearBGTilemapBuffer
	movs r1, #0xba
	lsls r1, r1, #1
	adds r0, r5, r1
	bl FUN_0823a76c
	adds r0, r5, #0
	adds r0, #0xb8
	movs r1, #0xc
	bl ClearMemory
	adds r0, r5, #0
	adds r0, #0xc4
	movs r1, #0xc
	bl ClearMemory
	adds r0, r5, #0
	adds r0, #0x20
	ldrb r1, [r0]
	movs r0, #8
	bl rfu_clearSlot
	ldr r0, _0804D904 @ =FUN_0804d708
	bl rfu_LMAN_setLMANCallback
	ldr r0, _0804D908 @ =FUN_0804d85c
	bl rfu_LMAN_setMSCCallback
	movs r4, #0
_0804D8B0:
	ldrb r1, [r7, #2]
	movs r6, #2
	adds r0, r6, #0
	lsls r0, r4
	ands r1, r0
	cmp r1, #0
	beq _0804D8CE
	lsls r1, r4, #0x18
	lsrs r1, r1, #0x18
	movs r0, #0x20
	adds r2, r5, #0
	adds r2, #0xc4
	movs r3, #0xc
	bl rfu_setRecvBuffer
_0804D8CE:
	adds r4, #1
	cmp r4, #3
	ble _0804D8B0
	adds r0, r5, #0
	adds r0, #0x34
	movs r1, #0
	strb r6, [r0]
	movs r0, #0x17
	strb r1, [r5, #0x1c]
	strh r0, [r5, #0x38]
	str r1, [r5, #0x44]
	adds r1, r5, #0
	adds r1, #0x32
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r5, #0x4c]
	cmp r0, #0
	beq _0804D8F8
	movs r1, #0
	bl VM_ExecByID
_0804D8F8:
	movs r0, #4
	bl Sound_FadeOutBGM
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804D904: .4byte FUN_0804d708
_0804D908: .4byte FUN_0804d85c
