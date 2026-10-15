	push {r4, r5, r6, lr}
	adds r3, r0, #0
	adds r6, r2, #0
	ldr r0, _08008980 @ =0x03000038
	ldr r5, [r0]
	cmp r5, #0
	beq _080089B0
	ldrb r4, [r6, #1]
	cmp r4, #0
	bne _08008984
	movs r1, #4
	ldr r0, [r3, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _080089B0
	adds r0, r6, #0
	movs r1, #1
	bl Entity5DA5Elem_SetState
	movs r1, #1
	adds r0, r1, #0
	ldrb r2, [r6]
	lsls r0, r2
	ldrh r2, [r5, #0x34]
	orrs r0, r2
	strh r0, [r5, #0x34]
	ldrb r6, [r6]
	lsls r1, r6
	ldrh r0, [r5, #0x38]
	orrs r1, r0
	strh r1, [r5, #0x38]
	b _080089B0
	.align 2, 0
_08008980: .4byte 0x03000038
_08008984:
	cmp r4, #1
	bne _080089B0
	movs r1, #8
	ldr r0, [r3, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _080089B0
	adds r0, r6, #0
	movs r1, #0
	bl Entity5DA5Elem_SetState
	adds r0, r4, #0
	ldrb r1, [r6]
	lsls r0, r1
	ldrh r1, [r5, #0x36]
	orrs r0, r1
	strh r0, [r5, #0x36]
	ldrb r6, [r6]
	lsls r4, r6
	ldrh r0, [r5, #0x38]
	orrs r4, r0
	strh r4, [r5, #0x38]
_080089B0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
