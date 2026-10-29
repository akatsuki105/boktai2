	push {r4, r5, r6, lr}
	ldr r0, _08207114 @ =0x03002B50
	ldr r4, [r0]
	cmp r4, #0
	beq _0820710C
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r1, r0, #0
	adds r0, r4, #0
	bl Entity286F_FindNodeByMoverID
	adds r5, r0, #0
	cmp r5, #0
	beq _0820710C
	adds r4, r5, #0
	adds r4, #0x20
	ldr r1, _08207118 @ =0x00000217
	adds r0, r5, r1
	movs r1, #0
	movs r2, #1
	strb r2, [r0]
	movs r0, #0x16
	strb r1, [r5, #2]
	strb r1, [r5, #3]
	strb r0, [r5, #4]
	str r1, [r5, #0x14]
	strb r2, [r5, #8]
	ldr r3, _0820711C @ =FUN_08042868
	movs r0, #7
	strb r0, [r5, #6]
	movs r6, #0xb3
	lsls r6, r6, #2
	adds r0, r5, r6
	str r3, [r0]
	str r1, [r5, #0x10]
	strb r2, [r5, #9]
	strb r1, [r5, #0x18]
	strb r2, [r4, #4]
_0820710C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08207114: .4byte 0x03002B50
_08207118: .4byte 0x00000217
_0820711C: .4byte FUN_08042868
