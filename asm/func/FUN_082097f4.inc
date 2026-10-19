	push {r4, lr}
	ldr r0, _08209830 @ =0x03002B50
	ldr r4, [r0]
	cmp r4, #0
	beq _0820982A
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r1, r0, #0
	adds r0, r4, #0
	bl Entity286F_FindNodeByMoverID
	adds r3, r0, #0
	cmp r3, #0
	beq _0820982A
	ldr r0, _08209834 @ =0x00000217
	adds r1, r3, r0
	movs r0, #0
	movs r2, #1
	strb r2, [r1]
	movs r1, #0x19
	strb r0, [r3, #2]
	strb r0, [r3, #3]
	strb r1, [r3, #4]
	str r0, [r3, #0x14]
	strb r2, [r3, #8]
_0820982A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08209830: .4byte 0x03002B50
_08209834: .4byte 0x00000217
