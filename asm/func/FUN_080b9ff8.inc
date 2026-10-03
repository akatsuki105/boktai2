	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r4, r0, #0
	adds r0, r1, #0
	adds r5, r2, #0
	adds r6, r3, #0
	ldr r1, [sp, #0x14]
	movs r2, #0
	mov r8, r2
	strb r0, [r4]
	adds r0, r4, #0
	bl FUN_080b9d94
	strb r5, [r4, #1]
	strb r6, [r4, #2]
	adds r0, r4, #0
	bl MenuCursor_GetSlot
	strb r0, [r4, #3]
	mov r0, r8
	strb r0, [r4, #8]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
