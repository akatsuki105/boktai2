	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0xc
	bl FUN_0822a4e0
	ldr r0, _08013C90 @ =0x03000054
	ldr r0, [r0]
	cmp r0, #0
	beq _08013C88
	adds r1, r4, #0
	bl FUN_08013954
_08013C88:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08013C90: .4byte 0x03000054
