	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r0, #0
	bl ClearBGTilemapBuffer
	movs r3, #0
	movs r0, #0xb5
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r2, _0804DC84 @ =0x03005800
	ldr r0, [r2]
	adds r0, #0x94
	ldrh r1, [r1]
	ldrh r0, [r0]
	cmp r1, r0
	beq _0804DC1C
	adds r4, r2, #0
	movs r1, #0xb5
	lsls r1, r1, #1
	adds r2, r6, r1
_0804DC08:
	adds r2, #2
	adds r3, #1
	cmp r3, #3
	bgt _0804DC1C
	ldr r0, [r4]
	adds r0, #0x94
	ldrh r1, [r2]
	ldrh r0, [r0]
	cmp r1, r0
	bne _0804DC08
_0804DC1C:
	movs r5, #0
	strb r3, [r6, #0x1f]
	movs r1, #0xba
	lsls r1, r1, #1
	adds r0, r6, r1
	bl FUN_0823a76c
	adds r0, r6, #0
	adds r0, #0xb8
	movs r1, #0xc
	bl ClearMemory
	adds r4, r6, #0
	adds r4, #0xc4
	adds r0, r4, #0
	movs r1, #0xc
	bl ClearMemory
	ldr r0, _0804DC88 @ =FUN_0804dafc
	bl rfu_LMAN_setLMANCallback
	ldr r0, _0804DC8C @ =FUN_0804dbc8
	bl rfu_LMAN_setMSCCallback
	adds r0, r6, #0
	adds r0, #0x21
	ldrb r1, [r0]
	movs r0, #0x20
	adds r2, r4, #0
	movs r3, #0xc
	bl rfu_setRecvBuffer
	adds r1, r6, #0
	adds r1, #0x34
	movs r0, #2
	strb r0, [r1]
	movs r0, #0x18
	strb r5, [r6, #0x1c]
	strh r0, [r6, #0x38]
	str r5, [r6, #0x44]
	subs r1, #2
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r6, #0x4c]
	cmp r0, #0
	beq _0804DC7E
	movs r1, #0
	bl VM_ExecByID
_0804DC7E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804DC84: .4byte 0x03005800
_0804DC88: .4byte FUN_0804dafc
_0804DC8C: .4byte FUN_0804dbc8
