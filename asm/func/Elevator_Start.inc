	push {r4, r5, r6, lr}
	movs r0, #0x6d
	movs r1, #1
	bl VM_GetNamedArgValue
	adds r4, r0, #0
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r1, r0, #0
	ldr r0, _081D5238 @ =0x03000194
	ldr r0, [r0]
	cmp r0, #0
	beq _081D5260
	cmp r1, #0
	beq _081D5260
	adds r0, r1, #0
	bl Elevator_FindByID
	adds r3, r0, #0
	cmp r3, #0
	beq _081D5260
	adds r0, #0xd6
	ldrh r1, [r0]
	movs r6, #2
	movs r2, #2
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _081D5260
	adds r0, r3, #0
	adds r0, #0xb2
	movs r5, #0
	strh r2, [r0]
	cmp r4, #4
	bne _081D523C
	adds r0, #2
	mvns r1, r6
	ldrh r2, [r0]
	ands r1, r2
	orrs r1, r4
	strh r1, [r0]
	b _081D5260
	.align 2, 0
_081D5238: .4byte 0x03000194
_081D523C:
	adds r1, r3, #0
	adds r1, #0xb4
	movs r2, #5
	rsbs r2, r2, #0
	ldrh r0, [r1]
	ands r2, r0
	strh r2, [r1]
	cmp r4, #2
	bne _081D5254
	orrs r4, r2
	strh r4, [r1]
	b _081D525A
_081D5254:
	mvns r0, r6
	ands r0, r2
	strh r0, [r1]
_081D525A:
	adds r0, r3, #0
	bl FUN_081d21d8
_081D5260:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
