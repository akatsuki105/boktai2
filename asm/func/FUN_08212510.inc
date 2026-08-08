	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r6, r0, #0
	ldr r0, _08212568 @ =0x0000C091
	ldr r1, _0821256C @ =0x0000C423
	bl FUN_082310cc
	adds r2, r0, #0
	str r2, [r6, #0x38]
	movs r5, #0
	str r5, [sp, #0xc]
	str r5, [sp]
	movs r4, #1
	str r4, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #1
	movs r1, #0
	movs r3, #0
	bl FUN_0822c0b8
	movs r0, #2
	movs r1, #2
	bl FUN_0822ba00
	str r4, [sp, #0xc]
	ldr r2, [r6, #0x38]
	str r5, [sp]
	str r4, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #2
	movs r1, #0
	movs r3, #0
	bl FUN_0822c0b8
	movs r0, #3
	movs r1, #3
	bl FUN_0822ba00
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08212568: .4byte 0x0000C091
_0821256C: .4byte 0x0000C423
