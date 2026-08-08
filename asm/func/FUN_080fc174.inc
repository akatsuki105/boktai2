	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, _080FC18C @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080FC190
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _080FC192
	.align 2, 0
_080FC18C: .4byte 0x0000046D
_080FC190:
	movs r0, #0
_080FC192:
	cmp r0, #0
	beq _080FC1AE
	adds r0, r4, #0
	movs r1, #7
	bl FUN_080ef86c
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #2
	rsbs r1, r1, #0
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
_080FC1AE:
	cmp r5, #0x28
	bne _080FC1C0
	movs r0, #0x10
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r4, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_080FC1C0:
	ldr r1, _080FC1DC @ =0x0000046E
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080FC1D6
	cmp r5, #0x78
	ble _080FC1D6
	ldr r0, _080FC1E0 @ =0x0000046B
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_080FC1D6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080FC1DC: .4byte 0x0000046E
_080FC1E0: .4byte 0x0000046B
