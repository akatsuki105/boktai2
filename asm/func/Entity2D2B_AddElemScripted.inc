	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	ldr r0, _080086C8 @ =0x03000034
	ldr r7, [r0]
	cmp r7, #0
	beq _080086C2
	adds r0, r7, #0
	bl Entity2D2B_FindFreeElem
	adds r6, r0, #0
	cmp r6, #0
	beq _080086C2
	movs r0, #0
	strb r0, [r6, #1]
	movs r4, #0
	movs r0, #0x72
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0800866A
	bl VM_GetValue
	adds r5, r0, #0
	bl VM_GetValue
	adds r4, r0, #0
	bl VM_GetValue
	adds r3, r0, #0
	adds r0, r6, #0
	adds r0, #0x28
	adds r1, r5, #0
	adds r2, r4, #0
	bl Map_InitPathWalker
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080086C2
	movs r0, #1
	strb r0, [r6, #1]
	ldr r0, [r6, #0x30]
	ldrh r1, [r0, #4]
	ldr r0, _080086CC @ =0x00000FFF
	ands r0, r1
	strh r0, [r6, #0xa]
	bl VM_GetValue
	strh r0, [r6, #0x24]
	bl VM_GetValue
	strh r0, [r6, #0x26]
	ldr r1, [r6, #0x30]
	add r0, sp, #4
	movs r2, #0
	bl Map_ReadPathNodePos
	movs r4, #1
_0800866A:
	movs r0, #0x74
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0800869C
	bl VM_GetValue
	adds r4, r0, #0
	bl VM_GetValue
	strh r0, [r6, #6]
	adds r0, r4, #0
	bl Elevator_GetPosByID
	adds r1, r0, #0
	str r1, [r6, #0x20]
	cmp r1, #0
	beq _080086C2
	movs r0, #2
	strb r0, [r6, #1]
	ldr r0, [r1]
	ldr r1, [r1, #4]
	str r0, [sp, #4]
	str r1, [sp, #8]
	movs r4, #1
_0800869C:
	movs r0, #0x50
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080086BE
	bl VM_GetValue
	add r1, sp, #4
	strh r0, [r1]
	bl VM_GetValue
	add r4, sp, #4
	strh r0, [r4, #2]
	bl VM_GetValue
	strh r0, [r4, #4]
	movs r4, #1
_080086BE:
	cmp r4, #0
	bne _080086D0
_080086C2:
	movs r0, #1
	rsbs r0, r0, #0
	b _08008860
	.align 2, 0
_080086C8: .4byte 0x03000034
_080086CC: .4byte 0x00000FFF
_080086D0:
	movs r0, #0x6d
	movs r1, #1
	bl VM_GetNamedArgValue
	adds r1, r0, #0
	adds r0, r6, #0
	bl Entity2D2BElem_SetState
	movs r0, #0x66
	movs r1, #0
	bl VM_GetNamedArgValue
	strb r0, [r6, #3]
	movs r0, #0x64
	movs r1, #0x78
	bl VM_GetNamedArgValue
	strh r0, [r6, #8]
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetNamedArgValue
	strh r0, [r6, #0x10]
	movs r0, #0x44
	movs r1, #0
	bl VM_GetNamedArgValue
	str r0, [r6, #0x18]
	adds r4, r6, #0
	adds r4, #0xe4
	lsls r0, r0, #5
	adds r0, #0x20
	adds r0, r7, r0
	str r0, [r4]
	movs r0, #0x70
	movs r1, #0
	bl VM_GetNamedArgValue
	strh r0, [r6, #0x12]
	movs r0, #0x61
	movs r1, #0
	bl VM_GetNamedArgValue
	str r0, [r6, #0x1c]
	ldrb r0, [r6, #1]
	adds r7, r4, #0
	cmp r0, #2
	beq _080087B8
	add r5, sp, #4
	adds r0, r5, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08008758
	cmp r1, #0
	blt _08008758
	ldr r0, _0800875C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08008758
	ldr r0, _08008760 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08008764
_08008758:
	movs r4, #0
	b _08008772
	.align 2, 0
_0800875C: .4byte 0x030046A8
_08008760: .4byte 0x030046AC
_08008764:
	ldr r0, _08008784 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08008772:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08008788
	adds r0, #4
	b _08008794
	.align 2, 0
_08008784: .4byte 0x030046A4
_08008788:
	ldr r0, _080087A8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08008794:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080087AC
	cmp r2, #2
	beq _080087B0
	b _080087B4
	.align 2, 0
_080087A8: .4byte 0x030046A4
_080087AC:
	ldrb r0, [r5, #4]
	b _080087B2
_080087B0:
	ldrb r0, [r5]
_080087B2:
	subs r1, r1, r0
_080087B4:
	add r0, sp, #4
	strh r1, [r0, #2]
_080087B8:
	movs r0, #0x4d
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _080087CC
	add r0, sp, #4
	bl GetMapAreaAt
	b _080087D0
_080087CC:
	movs r0, #1
	rsbs r0, r0, #0
_080087D0:
	str r0, [r6, #0x14]
	ldr r0, [sp, #4]
	ldr r1, [sp, #8]
	str r0, [r6, #0x54]
	str r1, [r6, #0x58]
	ldr r0, [r6, #0x3c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #0x3c]
	ldrb r0, [r6, #2]
	cmp r0, #1
	bne _08008824
	adds r4, r6, #0
	adds r4, #0x34
	ldr r1, [r7]
	ldr r2, _0800881C @ =0x085AA670
	ldr r0, [r6, #0x18]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r2, [r0]
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	movs r3, #1
	bl MainSprite_SetAnim
	ldr r1, _08008820 @ =0x085AA678
	ldr r0, [r6, #0x18]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r1, #1
	adds r0, r4, #0
	bl MainSprite_SetPlttID
	b _08008852
	.align 2, 0
_0800881C: .4byte 0x085AA670
_08008820: .4byte 0x085AA678
_08008824:
	adds r4, r6, #0
	adds r4, #0x34
	ldr r1, [r7]
	ldr r2, _08008868 @ =0x085AA670
	ldr r0, [r6, #0x18]
	lsls r0, r0, #2
	adds r2, #2
	adds r0, r0, r2
	ldrh r2, [r0]
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	movs r3, #1
	bl MainSprite_SetAnim
	ldr r1, _0800886C @ =0x085AA678
	ldr r0, [r6, #0x18]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	bl MainSprite_SetPlttID
_08008852:
	adds r0, r4, #0
	movs r1, #0
	bl Video_AddMainSpriteIntoDrawList
	movs r0, #1
	strb r0, [r6]
	movs r0, #0
_08008860:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08008868: .4byte 0x085AA670
_0800886C: .4byte 0x085AA678
