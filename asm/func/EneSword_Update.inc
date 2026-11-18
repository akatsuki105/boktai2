	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x18]
	ldr r6, [r0, #0x1c]
	movs r0, #4
	ands r6, r0
	cmp r6, #0
	beq _08199FB4
	movs r0, #1
	b _08199FE8
_08199FB4:
	adds r0, r4, #0
	bl FUN_081982b0
	adds r0, r4, #0
	bl FUN_08199f44
	ldr r0, _08199FF0 @ =0x00000CE6
	adds r5, r4, r0
	ldrh r0, [r5]
	cmp r0, #0
	beq _08199FDC
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0819742c
	strh r6, [r5]
	ldr r1, _08199FF4 @ =0x00000CE4
	adds r0, r4, r1
	strh r6, [r0]
_08199FDC:
	ldr r0, _08199FF8 @ =0x00000CEC
	adds r1, r4, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	movs r0, #0
_08199FE8:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08199FF0: .4byte 0x00000CE6
_08199FF4: .4byte 0x00000CE4
_08199FF8: .4byte 0x00000CEC
