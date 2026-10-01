	push {lr}
	adds r2, r0, #0
	ldr r1, [r2, #0x18]
	movs r0, #0x20
	ldr r1, [r1, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _0809E748
	movs r1, #2
	b _0809E750
_0809E748:
	movs r0, #0x10
	ands r1, r0
	rsbs r0, r1, #0
	lsrs r1, r0, #0x1f
_0809E750:
	adds r0, r2, #0
	bl FUN_0809e630
	pop {r0}
	bx r0
	.align 2, 0
