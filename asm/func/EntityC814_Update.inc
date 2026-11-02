	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	movs r0, #0x24
	ldrsh r1, [r4, r0]
	adds r0, r4, #0
	adds r0, #0xd4
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r2, r1, r0
	movs r3, #0x28
	ldrsh r1, [r4, r3]
	adds r0, r4, #0
	adds r0, #0xd8
	movs r3, #0
	ldrsh r0, [r0, r3]
	subs r1, r1, r0
	cmp r2, #0
	bne _080CB502
	cmp r1, #0
	beq _080CB562
_080CB502:
	adds r0, r2, #0
	bl ArcTan2_8
	adds r3, r0, #0
	ldr r2, _080CB528 @ =gSineTable
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _080CB52C
	asrs r0, r0, #0xc
	b _080CB532
	.align 2, 0
_080CB528: .4byte gSineTable
_080CB52C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080CB532:
	rsbs r0, r0, #0
	strh r0, [r4, #0x2c]
	ldr r1, _080CB554 @ =gSineTable
	movs r0, #0xff
	ands r0, r3
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _080CB558
	asrs r0, r0, #0xc
	b _080CB55E
	.align 2, 0
_080CB554: .4byte gSineTable
_080CB558:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080CB55E:
	rsbs r0, r0, #0
	strh r0, [r4, #0x30]
_080CB562:
	adds r0, r4, #0
	adds r0, #0x1c
	bl Mover_ApplyMove
	adds r5, r4, #0
	adds r5, #0xb8
	adds r4, #0x24
	adds r0, r5, #0
	adds r1, r4, #0
	bl Map_StepNavPath
	ldr r0, _080CB5AC @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080CB5A2
	ldr r0, _080CB5B0 @ =0x030046A0
	ldr r1, [r0]
	ldr r2, _080CB5B4 @ =0xFFFF0000
	ldrh r0, [r1, #0x30]
	str r0, [sp]
	ldrh r1, [r1, #0x34]
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
	adds r0, r5, #0
	adds r1, r4, #0
	mov r2, sp
	bl Map_TryFindNavRoute
_080CB5A2:
	movs r0, #0
	add sp, #8
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080CB5AC: .4byte 0x030044E0
_080CB5B0: .4byte 0x030046A0
_080CB5B4: .4byte 0xFFFF0000
