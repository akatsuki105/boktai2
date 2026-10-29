	push {r4, r5, lr}
	ldr r4, _08205E20 @ =0x03002C90
	ldr r0, [r4]
	cmp r0, #0
	beq _08205E5E
	movs r0, #0x6e
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08205E28
	ldr r0, _08205E24 @ =0x03002B50
	ldr r4, [r0]
	cmp r4, #0
	beq _08205E5E
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r1, r0, #0
	adds r0, r4, #0
	bl Entity286F_FindNodeByMoverID
	adds r4, r0, #0
	cmp r4, #0
	beq _08205E5E
	b _08205E2A
	.align 2, 0
_08205E20: .4byte 0x03002C90
_08205E24: .4byte 0x03002B50
_08205E28:
	ldr r4, [r4]
_08205E2A:
	movs r0, #0x11
	movs r1, #0
	strb r1, [r4, #2]
	strb r1, [r4, #3]
	strb r0, [r4, #4]
	str r1, [r4, #0x14]
	movs r3, #1
	strb r3, [r4, #8]
	ldr r2, _08205E64 @ =FUN_082050fc
	movs r0, #0xf
	strb r0, [r4, #6]
	movs r5, #0xb3
	lsls r5, r5, #2
	adds r0, r4, r5
	str r2, [r0]
	str r1, [r4, #0x10]
	strb r3, [r4, #9]
	strb r1, [r4, #0x18]
	adds r0, r4, #0
	adds r0, #0xd0
	movs r1, #1
	bl SpriteHolder_SetFlags
	adds r0, r4, #0
	bl Entity286FNode_HideShadow
_08205E5E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08205E64: .4byte FUN_082050fc
