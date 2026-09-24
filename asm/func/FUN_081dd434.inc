	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	ldr r0, _081DD518 @ =0x00000855
	adds r7, r6, r0
	ldrb r0, [r7]
	cmp r0, #0
	beq _081DD4E0
	adds r0, r6, #0
	bl FUN_081dc880
	adds r0, r6, #0
	bl FUN_081dcb54
	movs r0, #0
	bl ClearBGTilemapBuffer
	movs r0, #1
	bl ClearBGTilemapBuffer
	movs r0, #2
	bl ClearBGTilemapBuffer
	movs r0, #3
	bl ClearBGTilemapBuffer
	movs r5, #0
	str r5, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r1, _081DD51C @ =0x00000844
	adds r4, r6, r1
	ldr r0, [r4]
	movs r1, #6
	str r1, [sp]
	movs r1, #1
	movs r2, #7
	movs r3, #0x1c
	bl TextPanel_SetRect
	ldr r0, [r4]
	ldr r2, _081DD520 @ =0x0000083C
	adds r1, r6, r2
	ldr r1, [r1]
	bl TextPanel_SetScript
	ldr r0, [r4]
	movs r1, #4
	bl TextPanel_SetMessage
	ldr r0, [r4]
	bl TextPanel_Start
	movs r3, #0xc4
	lsls r3, r3, #3
	adds r2, r6, r3
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r0, _081DD524 @ =0x0000085A
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081DD528 @ =0x00000856
	adds r0, r6, r1
	movs r1, #0
	strh r5, [r0]
	strb r1, [r7]
	movs r2, #0xc3
	lsls r2, r2, #3
	adds r0, r6, r2
	adds r3, #0x78
	adds r1, r6, r3
	adds r3, #0x48
	adds r2, r6, r3
	ldrh r2, [r2]
	str r5, [sp]
	movs r3, #1
	bl MainSprite_SetAnim
_081DD4E0:
	ldr r0, _081DD52C @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0x20
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	beq _081DD530
	ldr r0, _081DD524 @ =0x0000085A
	adds r1, r6, r0
	ldrb r5, [r1]
	cmp r5, #0
	beq _081DD4FC
	b _081DD610
_081DD4FC:
	movs r2, #0xdc
	lsls r2, r2, #3
	adds r4, r6, r2
	movs r0, #4
	strh r0, [r4]
	movs r0, #1
	strb r0, [r1]
	movs r0, #0xdc
	bl PlaySound_082406e0
	movs r3, #0xc3
	lsls r3, r3, #3
	adds r0, r6, r3
	b _081DD55C
	.align 2, 0
_081DD518: .4byte 0x00000855
_081DD51C: .4byte 0x00000844
_081DD520: .4byte 0x0000083C
_081DD524: .4byte 0x0000085A
_081DD528: .4byte 0x00000856
_081DD52C: .4byte 0x030044E0
_081DD530:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _081DD574
	ldr r3, _081DD570 @ =0x0000085A
	adds r2, r6, r3
	ldrb r0, [r2]
	cmp r0, #0
	beq _081DD610
	movs r0, #0xdc
	lsls r0, r0, #3
	adds r4, r6, r0
	movs r1, #0
	movs r0, #5
	strh r0, [r4]
	strb r1, [r2]
	movs r0, #0xdc
	bl PlaySound_082406e0
	movs r1, #0xc3
	lsls r1, r1, #3
	adds r0, r6, r1
_081DD55C:
	movs r2, #0xd3
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r2, [r4]
	str r5, [sp]
	movs r3, #1
	bl MainSprite_SetAnim
	b _081DD610
	.align 2, 0
_081DD570: .4byte 0x0000085A
_081DD574:
	movs r5, #1
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _081DD5CC
	movs r3, #0xc4
	lsls r3, r3, #3
	adds r1, r6, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _081DD5BC @ =0x0000085A
	adds r4, r6, r0
	ldrb r0, [r4]
	bl FUN_081df8a0
	ldr r1, _081DD5C0 @ =FUN_081dd3c8
	movs r2, #4
	ldr r3, _081DD5C4 @ =0x00000838
	adds r0, r6, r3
	str r1, [r0]
	ldr r1, _081DD5C8 @ =0x00000855
	adds r0, r6, r1
	strb r5, [r0]
	adds r3, #0x1c
	adds r0, r6, r3
	strb r2, [r0]
	ldrb r0, [r4]
	cmp r0, #0
	beq _081DD5FC
	movs r0, #0xdd
	bl PlaySound_082406e0
	b _081DD620
	.align 2, 0
_081DD5BC: .4byte 0x0000085A
_081DD5C0: .4byte FUN_081dd3c8
_081DD5C4: .4byte 0x00000838
_081DD5C8: .4byte 0x00000855
_081DD5CC:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _081DD610
	movs r0, #0xc4
	lsls r0, r0, #3
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0
	bl FUN_081df8a0
	ldr r1, _081DD604 @ =FUN_081dd3c8
	movs r2, #4
	ldr r3, _081DD608 @ =0x00000838
	adds r0, r6, r3
	str r1, [r0]
	ldr r1, _081DD60C @ =0x00000855
	adds r0, r6, r1
	strb r5, [r0]
	adds r3, #0x1c
	adds r0, r6, r3
	strb r2, [r0]
_081DD5FC:
	movs r0, #0xde
	bl PlaySound_082406e0
	b _081DD620
	.align 2, 0
_081DD604: .4byte FUN_081dd3c8
_081DD608: .4byte 0x00000838
_081DD60C: .4byte 0x00000855
_081DD610:
	movs r1, #0xc3
	lsls r1, r1, #3
	adds r0, r6, r1
	movs r2, #0xd3
	lsls r2, r2, #3
	adds r1, r6, r2
	bl MainSprite_AdvanceAnim
_081DD620:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
