	push {r4, r5, lr}
	ldr r4, _08205E9C @ =0x03002C90
	ldr r0, [r4]
	cmp r0, #0
	beq _08205ED0
	movs r0, #0x6e
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08205EA4
	ldr r0, _08205EA0 @ =0x03002B50
	ldr r4, [r0]
	cmp r4, #0
	beq _08205ED0
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r1, r0, #0
	adds r0, r4, #0
	bl Entity286F_FindNodeByMoverID
	adds r4, r0, #0
	cmp r4, #0
	beq _08205ED0
	b _08205EA6
	.align 2, 0
_08205E9C: .4byte 0x03002C90
_08205EA0: .4byte 0x03002B50
_08205EA4:
	ldr r4, [r4]
_08205EA6:
	ldr r1, _08205ED8 @ =0x00000217
	adds r0, r4, r1
	movs r1, #0
	movs r2, #1
	strb r2, [r0]
	movs r0, #0x12
	strb r1, [r4, #2]
	strb r1, [r4, #3]
	strb r0, [r4, #4]
	str r1, [r4, #0x14]
	strb r2, [r4, #8]
	ldr r3, _08205EDC @ =FUN_08205178
	movs r0, #0x10
	strb r0, [r4, #6]
	movs r5, #0xb3
	lsls r5, r5, #2
	adds r0, r4, r5
	str r3, [r0]
	str r1, [r4, #0x10]
	strb r2, [r4, #9]
	strb r1, [r4, #0x18]
_08205ED0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08205ED8: .4byte 0x00000217
_08205EDC: .4byte FUN_08205178
