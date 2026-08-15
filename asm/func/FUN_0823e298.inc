	push {r4, r5, lr}
	sub sp, #0x14
	add r1, sp, #4
	add r2, sp, #8
	ldr r5, _0823E314 @ =gClock
	ldr r3, [r5]
	mov r0, sp
	bl ParseBCDDate
	add r4, sp, #0xc
	adds r0, r4, #0
	bl FUN_0823167c
	ldr r2, [sp]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0823206c
	adds r0, r4, #0
	bl FUN_0823167c
	ldr r2, [sp, #4]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0823206c
	adds r0, r4, #0
	bl FUN_0823167c
	ldr r2, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0823206c
	adds r0, r4, #0
	bl FUN_0823167c
	ldrb r2, [r5, #4]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0823206c
	adds r0, r4, #0
	bl FUN_0823167c
	ldrb r2, [r5, #5]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0823206c
	adds r0, r4, #0
	bl FUN_0823167c
	ldrb r2, [r5, #6]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0823206c
	add sp, #0x14
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0823E314: .4byte gClock
