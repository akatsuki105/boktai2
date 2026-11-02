	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	bl FUN_0804f820
	cmp r0, #0
	beq _08050D06
	adds r4, r0, #0
	adds r4, #0x3c
	adds r0, r4, r5
	ldrb r0, [r0]
	cmp r0, #4
	bhi _08050D06
	movs r2, #0
	movs r1, #0
_08050CD6:
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r2, r2, r0
	adds r1, #1
	cmp r1, #3
	ble _08050CD6
	cmp r2, #9
	bgt _08050D06
	adds r0, r6, #0
	adds r1, r5, #0
	movs r2, #1
	bl FUN_08051d18
	adds r0, r4, r5
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	movs r0, #2
	movs r1, #1
	bl FUN_08050e50
	ldr r0, _08050D0C @ =0x00000375
	bl PlaySound_082406e0
_08050D06:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08050D0C: .4byte 0x00000375
