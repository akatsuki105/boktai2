	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	ldr r2, _081034B8 @ =0x00000724
	adds r0, r1, r2
	movs r6, #0
	strb r6, [r0]
	adds r2, #0x34
	adds r0, r1, r2
	movs r5, #0
	strh r6, [r0]
	ldr r2, _081034BC @ =0x00000574
	adds r0, r4, r2
	ldr r0, [r0]
	movs r2, #0xe6
	lsls r2, r2, #3
	adds r1, r1, r2
	strh r0, [r1]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, #8
	bl ClearMemory
	ldr r1, _081034C0 @ =0x08251FE4
	adds r0, r4, #0
	ldr r2, _081034C4 @ =0x0000010B
	bl Enemy_ClearPendingState
	adds r0, r4, #0
	bl Enemy_StepTowardPathNode
	adds r0, r4, #0
	movs r1, #0
	bl Enemy_PlayAnim
	adds r0, r4, #0
	adds r0, #0x9c
	adds r1, r4, #0
	adds r1, #8
	movs r2, #0x20
	movs r3, #0x20
	bl Map_IsPosOutsidePathNode
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081034CC
	movs r1, #2
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r4, r2
	strb r5, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r5, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r1, [r0]
	ldr r1, _081034C8 @ =0x00000484
	adds r0, r4, r1
	str r6, [r0]
	adds r2, #2
	adds r1, r4, r2
	b _081034EA
	.align 2, 0
_081034B8: .4byte 0x00000724
_081034BC: .4byte 0x00000574
_081034C0: .4byte 0x08251FE4
_081034C4: .4byte 0x0000010B
_081034C8: .4byte 0x00000484
_081034CC:
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r4, r2
	strb r5, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r5, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r5, [r0]
	adds r2, #0x1a
	adds r0, r4, r2
	str r1, [r0]
	ldr r0, _08103500 @ =0x0000046C
	adds r1, r4, r0
_081034EA:
	movs r0, #1
	strb r0, [r1]
	ldr r1, [r4, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	bl MainSprite_AdvanceAnim
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08103500: .4byte 0x0000046C
