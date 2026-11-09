	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _08182EB8 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08182EBC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08182EBE
	.align 2, 0
_08182EB8: .4byte 0x0000046C
_08182EBC:
	movs r0, #0
_08182EBE:
	cmp r0, #0
	beq _08182EEC
	ldr r4, _08182F2C @ =FUN_08180314
	movs r3, #0x29
	ldr r0, _08182F30 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08182F34 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
_08182EEC:
	ldr r2, _08182F34 @ =0x0000046B
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _08182FD8
	ldr r3, _08182F38 @ =0x00000898
	adds r2, r6, r3
	ldr r1, _08182F3C @ =0xFFFFDFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r1, _08182F40 @ =0x03002BE0
	ldr r6, _08182F44 @ =0x000004A4
	adds r0, r5, r6
	ldr r6, [r0]
	adds r7, r5, #0
	adds r7, #8
	ldr r0, [r1]
	adds r4, r0, #0
	adds r4, #0x2c
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _08182F48
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r5, r1
	b _08182F6C
	.align 2, 0
_08182F2C: .4byte FUN_08180314
_08182F30: .4byte 0x0000046D
_08182F34: .4byte 0x0000046B
_08182F38: .4byte 0x00000898
_08182F3C: .4byte 0xFFFFDFFF
_08182F40: .4byte 0x03002BE0
_08182F44: .4byte 0x000004A4
_08182F48:
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _08182F66
	cmp r0, #2
	beq _08182F74
	adds r0, r5, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
	b _08182F74
_08182F66:
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
_08182F6C:
	ldr r1, _08182FC4 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
_08182F74:
	movs r1, #2
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r2, #0
	strb r2, [r0]
	ldr r6, _08182FC8 @ =0x00000469
	adds r0, r5, r6
	strb r2, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r1, [r0]
	adds r6, #0x1b
	adds r0, r5, r6
	str r2, [r0]
	ldr r1, _08182FCC @ =0x0000046C
	adds r0, r5, r1
	movs r1, #1
	strb r1, [r0]
	ldr r4, _08182FD0 @ =Enemy_ClearStateBegun
	movs r3, #0x10
	subs r6, #0x17
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _08182FD4 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r3, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r4, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r2, [r0]
	b _08182FE2
	.align 2, 0
_08182FC4: .4byte 0xFFFFFDFF
_08182FC8: .4byte 0x00000469
_08182FCC: .4byte 0x0000046C
_08182FD0: .4byte Enemy_ClearStateBegun
_08182FD4: .4byte 0x0000046B
_08182FD8:
	ldr r6, _08182FE8 @ =0x00000484
	adds r1, r5, r6
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08182FE2:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08182FE8: .4byte 0x00000484
