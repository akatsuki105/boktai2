	push {r4, r5, lr}
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	adds r1, r0, #0
	ldr r5, _081D52D4 @ =0x03000194
	ldr r0, [r5]
	cmp r0, #0
	beq _081D5332
	cmp r1, #0
	beq _081D5332
	adds r0, r1, #0
	bl Elevator_FindByID
	adds r4, r0, #0
	ldr r5, [r5]
	movs r1, #1
	adds r0, #0xb4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081D52D8
	movs r0, #1
	b _081D52DA
	.align 2, 0
_081D52D4: .4byte 0x03000194
_081D52D8:
	movs r0, #0
_081D52DA:
	cmp r0, #0
	beq _081D52F6
	movs r1, #0x9c
	lsls r1, r1, #1
	adds r0, r4, r1
	bl FUN_082342a8
	adds r2, r4, #0
	adds r2, #0xb4
	movs r0, #2
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_081D52F6:
	adds r0, r4, #0
	bl Elevator_RemoveTileOverrides
	adds r0, r4, #0
	adds r0, #0xf4
	bl FUN_0823b284
	adds r1, r4, #0
	adds r1, #0xd4
	movs r0, #0
	strh r0, [r1]
	subs r1, #0x22
	movs r0, #6
	strh r0, [r1]
	adds r0, r4, #0
	bl AuxSprite_Remove
	adds r3, r4, #0
	adds r3, #0xb0
	movs r1, #0
	ldrsh r0, [r3, r1]
	ldr r1, _081D5338 @ =0x000012AC
	adds r2, r5, r1
	movs r1, #1
	lsls r1, r0
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
	ldr r0, _081D533C @ =0x0000FFFF
	strh r0, [r3]
_081D5332:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081D5338: .4byte 0x000012AC
_081D533C: .4byte 0x0000FFFF
