	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r6, r0, #0
	adds r7, r1, #0
	mov r8, r2
	ldr r1, _08009080 @ =0x03000038
	ldr r4, [r1]
	cmp r4, #0
	bne _08009084
	movs r0, #1
	rsbs r0, r0, #0
	b _08009116
	.align 2, 0
_08009080: .4byte 0x03000038
_08009084:
	cmp r6, #0
	bge _080090D6
	adds r5, r4, #0
	adds r5, #0xcc
	movs r6, #0
	movs r3, #1
_08009090:
	ldrb r1, [r5, #1]
	cmp r1, r7
	beq _080090CC
	adds r0, r5, #0
	adds r1, r7, #0
	str r3, [sp]
	bl Entity5DA5Elem_SetState
	ldr r3, [sp]
	cmp r7, #0
	bne _080090B2
	adds r1, r3, #0
	lsls r1, r6
	ldrh r2, [r4, #0x36]
	orrs r1, r2
	strh r1, [r4, #0x36]
	b _080090BC
_080090B2:
	adds r1, r3, #0
	lsls r1, r6
	ldrh r2, [r4, #0x34]
	orrs r1, r2
	strh r1, [r4, #0x34]
_080090BC:
	mov r1, r8
	cmp r1, #0
	beq _080090CC
	adds r1, r3, #0
	lsls r1, r6
	ldrh r2, [r4, #0x38]
	orrs r1, r2
	strh r1, [r4, #0x38]
_080090CC:
	adds r6, #1
	adds r5, #0xb8
	cmp r6, #3
	ble _08009090
	b _08009116
_080090D6:
	movs r1, #0xb8
	muls r1, r6, r1
	adds r1, #0xcc
	adds r5, r4, r1
	ldrb r1, [r5, #1]
	cmp r1, r7
	beq _08009116
	adds r0, r5, #0
	adds r1, r7, #0
	bl Entity5DA5Elem_SetState
	cmp r7, #0
	bne _080090FC
	movs r1, #1
	lsls r1, r6
	ldrh r2, [r4, #0x36]
	orrs r1, r2
	strh r1, [r4, #0x36]
	b _08009106
_080090FC:
	movs r1, #1
	lsls r1, r6
	ldrh r2, [r4, #0x34]
	orrs r1, r2
	strh r1, [r4, #0x34]
_08009106:
	mov r1, r8
	cmp r1, #0
	beq _08009116
	movs r1, #1
	lsls r1, r6
	ldrh r2, [r4, #0x38]
	orrs r1, r2
	strh r1, [r4, #0x38]
_08009116:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
