	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xea
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	cmp r0, #0
	ble _08130ABC
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl EnemyTargetManager_FindOwnerByID
	movs r2, #0xec
	lsls r2, r2, #1
	adds r1, r5, r2
	str r0, [r1]
	movs r2, #0xc
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r1, #0
	strb r1, [r0]
	ldr r6, _08130AA4 @ =0x00000469
	adds r0, r5, r6
	strb r1, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r2, [r0]
	adds r6, #0x1b
	adds r0, r5, r6
	str r1, [r0]
	ldr r2, _08130AA8 @ =0x0000046C
	adds r0, r5, r2
	movs r2, #1
	strb r2, [r0]
	movs r3, #0xb7
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r4, [r0]
	movs r3, #0x1a
	subs r6, #0x17
	adds r0, r5, r6
	strb r2, [r0]
	ldr r2, _08130AAC @ =0x0000046B
	adds r0, r5, r2
	strb r1, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r3, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r5, r2
	str r4, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r1, [r0]
	adds r0, r5, #0
	bl FUN_08130eec
	adds r0, r5, #0
	bl Enemy_StepTowardPathNode
	ldr r6, _08130AB0 @ =0x000001DF
	adds r0, r5, r6
	ldrb r0, [r0]
	cmp r0, #2
	beq _08130A84
	movs r0, #4
	ldr r1, _08130AB4 @ =0x00000222
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_08130A84:
	movs r0, #0x80
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r5, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r6, #0x93
	lsls r6, r6, #2
	adds r0, r5, r6
	ldrh r1, [r0]
	ldr r2, _08130AB8 @ =0x0000024E
	adds r0, r5, r2
	strh r1, [r0]
	movs r0, #1
	b _08130ABE
	.align 2, 0
_08130AA4: .4byte 0x00000469
_08130AA8: .4byte 0x0000046C
_08130AAC: .4byte 0x0000046B
_08130AB0: .4byte 0x000001DF
_08130AB4: .4byte 0x00000222
_08130AB8: .4byte 0x0000024E
_08130ABC:
	movs r0, #0
_08130ABE:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
