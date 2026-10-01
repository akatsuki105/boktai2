	push {r4, r5, lr}
	adds r5, r0, #0
	adds r1, r5, #0
	adds r1, #0x29
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804AF16
	movs r0, #0
	strb r0, [r1]
	adds r1, #3
	movs r0, #3
	strb r0, [r1]
	adds r0, r5, #0
	movs r1, #0
	bl FUN_0804aa30
	adds r0, r5, #0
	adds r0, #0x2a
	movs r4, #0
	ldrsb r4, [r0, r4]
	movs r1, #0xa0
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	adds r4, #1
	bl VM_ParseStringRef
	adds r0, r0, r4
	bl Textbox_LookupString
	bl FUN_08049e30
	bl FUN_08049f5c
	adds r0, r5, #0
	bl FUN_0804ab00
_0804AF16:
	ldr r0, [r5, #0x34]
	cmp r0, #0x1e
	bls _0804AF26
	adds r0, r5, #0
	bl EntityB88C_ConfirmOrCancel
	cmp r0, #0
	bne _0804AF32
_0804AF26:
	adds r0, r5, #0
	bl EntityB88C_MoveCursor
	ldr r0, [r5, #0x34]
	adds r0, #1
	str r0, [r5, #0x34]
_0804AF32:
	pop {r4, r5}
	pop {r0}
	bx r0
