	push {r4, lr}
	adds r4, r1, #0
	ldrb r0, [r4, #8]
	cmp r0, #0
	beq _08204DB4
	movs r0, #0
	strb r0, [r4, #8]
	strb r0, [r4, #7]
	movs r0, #0x10
	strb r0, [r4, #5]
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #1
	bl MsgQueue_EndWait
_08204DB4:
	ldrb r0, [r4, #4]
	ldr r2, _08204DD4 @ =0x00000227
	adds r1, r4, r2
	strb r0, [r1]
	ldrb r0, [r4, #7]
	cmp r0, #0
	beq _08204DCE
	movs r0, #0xa
	strb r0, [r4, #4]
	movs r0, #0
	str r0, [r4, #0x14]
	movs r0, #1
	strb r0, [r4, #8]
_08204DCE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08204DD4: .4byte 0x00000227
