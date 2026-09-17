	push {r4, r5, lr}
	adds r4, r0, #0
	bl FUN_08013d10
	adds r5, r0, #0
	cmp r5, #0
	beq _08013F64
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08013d28
	adds r4, r0, #0
	cmp r4, #0
	beq _08013F64
	adds r0, #0xc
	bl FUN_080138fc
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08013d70
	adds r0, r4, #0
	bl Free
	movs r0, #0
	b _08013F68
_08013F64:
	movs r0, #1
	rsbs r0, r0, #0
_08013F68:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
