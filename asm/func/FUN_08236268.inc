	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	ldr r0, _08236298 @ =0x030046A4
	ldr r0, [r0]
	ldr r5, [r0, #0x14]
	adds r0, r5, #0
	adds r1, r4, #0
	adds r2, r6, #0
	bl FUN_08235ffc
	ldrh r1, [r4]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08236292
	adds r0, r5, #0
	adds r1, r4, #0
	adds r2, r6, #0
	bl FUN_08236130
_08236292:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08236298: .4byte 0x030046A4
