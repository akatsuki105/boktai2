	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r7, r1, #0
	ldr r0, _082384E4 @ =0x03000820
	ldr r5, [r0]
	cmp r5, #0
	beq _082384E8
	adds r0, r5, #0
	adds r0, #0xc0
	bl FUN_082381b4
	adds r4, r0, #0
	cmp r4, #0
	beq _082384E8
	adds r0, r5, #0
	adds r1, r4, #0
	adds r2, r6, #0
	adds r3, r7, #0
	bl FUN_08238250
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08238178
	ldrb r0, [r4, #8]
	b _082384EC
	.align 2, 0
_082384E4: .4byte 0x03000820
_082384E8:
	movs r0, #1
	rsbs r0, r0, #0
_082384EC:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
