	push {r4, r5, lr}
	sub sp, #0xc
	add r4, sp, #4
	add r5, sp, #8
	bl GetDate
	adds r3, r0, #0
	mov r0, sp
	adds r1, r4, #0
	adds r2, r5, #0
	bl ParseBCDDate
	ldr r0, [sp, #4]
	add sp, #0xc
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
