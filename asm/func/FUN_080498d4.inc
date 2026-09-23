	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r4, #0x18
	movs r0, #0
	movs r1, #0x12
	movs r2, #0x20
	movs r3, #2
	bl FUN_0822ea60
	movs r0, #0
	movs r1, #0x12
	movs r2, #0x20
	movs r3, #2
	bl FUN_0822eadc
	movs r0, #2
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0x12
	movs r3, #0x20
	bl TextRenderer_SetRect
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
