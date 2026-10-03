	push {r4, r5, r6, lr}
	sub sp, #8
	adds r4, r2, #0
	adds r5, r3, #0
	movs r3, #0x9e
	lsls r3, r3, #4
	adds r2, r0, r3
	ldr r3, [r2]
	movs r6, #0xda
	lsls r6, r6, #2
	adds r2, r3, r6
	ldrh r2, [r2]
	adds r6, #2
	adds r3, r3, r6
	ldrh r3, [r3]
	str r4, [sp]
	str r5, [sp, #4]
	bl FUN_0808a4ac
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
