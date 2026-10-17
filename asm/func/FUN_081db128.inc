	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xc5
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	bl TextPanel_Hide
	movs r1, #0xc7
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	bl TextPanel_Hide
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
