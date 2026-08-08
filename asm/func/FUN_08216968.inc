	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	movs r1, #0
_08216970:
	lsls r0, r1, #8
	adds r3, r5, r0
	movs r0, #0
	ldrb r2, [r3]
	adds r1, #1
	cmp r2, #0
	beq _08216990
_0821697E:
	strb r2, [r4]
	adds r3, #1
	adds r4, #1
	adds r0, #1
	cmp r0, #0xff
	bgt _08216990
	ldrb r2, [r3]
	cmp r2, #0
	bne _0821697E
_08216990:
	cmp r1, #3
	ble _08216970
	movs r0, #0
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
