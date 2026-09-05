	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r5, [r6, #0x18]
	cmp r5, #0
	beq _08013DCC
_08013DAE:
	ldr r4, [r5, #0x50]
	adds r0, r5, #0
	adds r0, #0xc
	bl FUN_080138fc
	adds r0, r6, #0
	adds r1, r5, #0
	bl FUN_08013d70
	adds r0, r5, #0
	bl Free
	adds r5, r4, #0
	cmp r5, #0
	bne _08013DAE
_08013DCC:
	movs r1, #0
	str r1, [r6, #0x18]
	ldr r0, _08013DDC @ =0x03002B40
	str r1, [r0]
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08013DDC: .4byte 0x03002B40
