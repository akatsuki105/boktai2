	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #2]
	cmp r0, #0
	beq _08004DBE
	adds r0, r4, #0
	adds r0, #0xc
	bl FUN_082342a8
	movs r0, #0
	strb r0, [r4, #2]
_08004DBE:
	ldr r0, _08004DDC @ =0x03000024
	ldr r0, [r0]
	cmp r0, #0
	beq _08004DCC
	adds r0, r4, #0
	bl Entity08004fac_UnlinkNode
_08004DCC:
	adds r0, r4, #0
	bl Free
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08004DDC: .4byte 0x03000024
