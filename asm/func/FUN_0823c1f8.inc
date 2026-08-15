	push {lr}
	adds r1, r0, #0
	adds r1, #0x98
	ldr r2, [r1]
	cmp r2, #0
	beq _0823C224
	adds r0, #0x96
	ldrh r0, [r0]
	cmp r0, #0
	bne _0823C218
	str r0, [r1]
	adds r0, r2, #0
	movs r1, #0
	bl Script_ExecByPointer
	b _0823C224
_0823C218:
	movs r0, #0
	str r0, [r1]
	adds r0, r2, #0
	movs r1, #0
	bl Script_ExecById
_0823C224:
	pop {r0}
	bx r0
