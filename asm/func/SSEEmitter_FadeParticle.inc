	push {r4, r5, r6, lr}
	adds r3, r0, #0
	movs r2, #0
	movs r6, #0
	movs r5, #2
	adds r1, r3, #0
	adds r1, #0xc
	movs r4, #0xa
_082466FC:
	ldrb r0, [r1]
	cmp r0, #1
	bne _0824670A
	strb r5, [r1]
	strb r4, [r1, #1]
	strh r6, [r1, #2]
	b _08246718
_0824670A:
	adds r1, #0x48
	adds r2, #1
	cmp r2, #3
	ble _082466FC
	movs r0, #0
	cmp r0, #0
	beq _0824671E
_08246718:
	ldrb r0, [r3, #3]
	subs r0, #1
	strb r0, [r3, #3]
_0824671E:
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
