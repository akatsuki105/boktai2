	push {lr}
	adds r3, r0, #0
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r2, r3, r0
	movs r1, #4
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r1, _080E4A94 @ =0x0000025D
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080E4A98
	ldr r2, [r3, #0x44]
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _080E4AA6
	.align 2, 0
_080E4A94: .4byte 0x0000025D
_080E4A98:
	ldr r0, [r3, #0x44]
	adds r0, #0x20
	movs r2, #2
	rsbs r2, r2, #0
	ldr r1, [r0, #8]
	ands r1, r2
	str r1, [r0, #8]
_080E4AA6:
	pop {r0}
	bx r0
	.align 2, 0
