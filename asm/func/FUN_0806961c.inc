	push {lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x20]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2, #0x20]
	ldr r1, _08069644 @ =0x000004C7
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0806963E
	adds r0, r2, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_0806963E:
	pop {r0}
	bx r0
	.align 2, 0
_08069644: .4byte 0x000004C7
