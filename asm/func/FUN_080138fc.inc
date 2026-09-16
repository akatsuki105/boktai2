	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0xc
	bl FUN_0822dabc
	ldr r0, _0801391C @ =0x03000050
	ldr r0, [r0]
	cmp r0, #0
	beq _08013914
	adds r1, r4, #0
	bl FUN_08013668
_08013914:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0801391C: .4byte 0x03000050
