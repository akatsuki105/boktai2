	push {lr}
	adds r2, r0, #0
	ldr r0, _080A0608 @ =0x03002BE0
	ldr r0, [r0]
	ldr r0, [r0, #0x1c]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _080A0602
	ldr r1, [r2, #0x38]
	adds r0, r2, #0
	bl _call_via_r1
_080A0602:
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_080A0608: .4byte 0x03002BE0
