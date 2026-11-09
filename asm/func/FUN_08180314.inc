	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r4, [r0]
	ldr r0, _08180384 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08180330
	movs r0, #0
	strb r0, [r1]
_08180330:
	adds r0, r5, #0
	movs r1, #0x13
	bl Enemy_PlayAnimNoFacing
	ldr r1, _08180388 @ =0x000008A8
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r6, r0
	ble _0818037E
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	ldr r0, _0818038C @ =0x00000898
	adds r1, r1, r0
	ldr r2, _08180390 @ =0xFFFFEFFF
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	ldr r4, _08180394 @ =FUN_0818039c
	movs r3, #0x2a
	ldr r0, _08180384 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08180398 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	adds r1, #0x25
	adds r0, r5, r1
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
_0818037E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08180384: .4byte 0x0000046D
_08180388: .4byte 0x000008A8
_0818038C: .4byte 0x00000898
_08180390: .4byte 0xFFFFEFFF
_08180394: .4byte FUN_0818039c
_08180398: .4byte 0x0000046B
