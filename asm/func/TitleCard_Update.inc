	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r3, r5, #0
	adds r3, #0x46
	movs r1, #0
	ldrsh r0, [r3, r1]
	cmp r0, #0
	bne _0800F35C
	ldr r0, _0800F3DC @ =0x0300445C
	ldr r1, _0800F3E0 @ =0x03004040
	ldr r1, [r1]
	str r1, [r0]
_0800F35C:
	adds r0, r5, #0
	adds r0, #0x44
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	beq _0800F3F4
	ldr r0, _0800F3E4 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	beq _0800F3F4
	movs r0, #0xbb
	lsls r0, r0, #2
	adds r1, r5, r0
	ldr r0, [r1, #8]
	movs r2, #1
	orrs r0, r2
	str r0, [r1, #8]
	movs r0, #0xd3
	lsls r0, r0, #2
	adds r1, r5, r0
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
	movs r0, #0xeb
	lsls r0, r0, #2
	adds r1, r5, r0
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
	ldr r0, _0800F3E8 @ =0x0000040C
	adds r1, r5, r0
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
	ldr r0, _0800F3EC @ =0x0000046C
	adds r1, r5, r0
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
	ldr r0, _0800F3F0 @ =0x000004CC
	adds r1, r5, r0
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
	movs r1, #0
	ldrsh r2, [r3, r1]
	cmp r2, #0
	bne _0800F3C8
	ldr r1, _0800F3DC @ =0x0300445C
	ldr r0, _0800F3E0 @ =0x03004040
	str r2, [r0]
	str r2, [r1]
_0800F3C8:
	ldr r0, [r5, #0x40]
	cmp r0, #0
	beq _0800F3D4
	movs r1, #0
	bl Script_ExecById
_0800F3D4:
	adds r0, r5, #0
	bl KillEntity
	b _0800F506
	.align 2, 0
_0800F3DC: .4byte 0x0300445C
_0800F3E0: .4byte 0x03004040
_0800F3E4: .4byte 0x030044E0
_0800F3E8: .4byte 0x0000040C
_0800F3EC: .4byte 0x0000046C
_0800F3F0: .4byte 0x000004CC
_0800F3F4:
	movs r2, #0xb9
	lsls r2, r2, #2
	adds r6, r5, r2
	ldr r1, [r6]
	cmp r1, #0
	beq _0800F406
	adds r0, r5, #0
	bl _call_via_r1
_0800F406:
	movs r3, #0xba
	lsls r3, r3, #2
	adds r7, r5, r3
	ldr r1, [r7]
	cmp r1, #0
	beq _0800F43A
	adds r0, r5, #0
	bl _call_via_r1
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r4, r5, r0
	ldrh r0, [r4]
	lsls r2, r0, #2
	adds r2, r2, r0
	lsls r2, r2, #6
	adds r2, #0x54
	adds r2, r5, r2
	movs r0, #0
	movs r1, #2
	bl Video_SetHBlankEffect
	ldrh r1, [r4]
	movs r0, #1
	subs r0, r0, r1
	strh r0, [r4]
_0800F43A:
	ldrh r2, [r5, #0x38]
	cmp r2, #1
	beq _0800F4A8
	cmp r2, #1
	bgt _0800F44A
	cmp r2, #0
	beq _0800F450
	b _0800F500
_0800F44A:
	cmp r2, #2
	beq _0800F4B4
	b _0800F500
_0800F450:
	ldrh r0, [r5, #0x3a]
	adds r0, #1
	strh r0, [r5, #0x3a]
	ldrh r1, [r5, #0x3a]
	adds r0, r5, #0
	adds r0, #0x4a
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r1, r0
	ble _0800F500
	movs r0, #1
	strh r0, [r5, #0x38]
	strh r2, [r5, #0x3a]
	ldr r0, _0800F498 @ =TitleCard_UpdateOpen
	str r0, [r6]
	ldr r1, _0800F49C @ =0x000002DA
	adds r0, r5, r1
	movs r2, #0xb7
	lsls r2, r2, #2
	adds r1, r5, r2
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	beq _0800F486
	movs r0, #0xe1
	bl PlaySound_082406e0
_0800F486:
	ldr r3, _0800F4A0 @ =0x000002D6
	adds r1, r5, r3
	movs r0, #0x80
	strh r0, [r1]
	movs r0, #0xb6
	lsls r0, r0, #2
	adds r1, r5, r0
	ldr r0, _0800F4A4 @ =0x0000FFFE
	b _0800F4FA
	.align 2, 0
_0800F498: .4byte TitleCard_UpdateOpen
_0800F49C: .4byte 0x000002DA
_0800F4A0: .4byte 0x000002D6
_0800F4A4: .4byte 0x0000FFFE
_0800F4A8:
	ldr r0, [r6]
	cmp r0, #0
	bne _0800F500
	movs r0, #2
	strh r0, [r5, #0x38]
	b _0800F500
_0800F4B4:
	ldrh r0, [r5, #0x3a]
	adds r0, #1
	movs r4, #0
	strh r0, [r5, #0x3a]
	ldrh r1, [r5, #0x3a]
	adds r0, r5, #0
	adds r0, #0x4c
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r1, r0
	ble _0800F500
	movs r0, #3
	strh r0, [r5, #0x38]
	strh r4, [r5, #0x3a]
	ldr r0, _0800F510 @ =TitleCard_UpdateClose
	str r0, [r6]
	ldr r3, _0800F514 @ =0x000002DA
	adds r0, r5, r3
	movs r2, #0xb7
	lsls r2, r2, #2
	adds r1, r5, r2
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	beq _0800F4EC
	movs r0, #0xe3
	bl PlaySound_082406e0
_0800F4EC:
	ldr r3, _0800F518 @ =0x000002D6
	adds r0, r5, r3
	strh r4, [r0]
	movs r0, #0xb6
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r0, #4
_0800F4FA:
	strh r0, [r1]
	ldr r0, _0800F51C @ =TitleCard_BuildHBlankTable
	str r0, [r7]
_0800F500:
	ldr r0, [r5, #0x3c]
	adds r0, #1
	str r0, [r5, #0x3c]
_0800F506:
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800F510: .4byte TitleCard_UpdateClose
_0800F514: .4byte 0x000002DA
_0800F518: .4byte 0x000002D6
_0800F51C: .4byte TitleCard_BuildHBlankTable
