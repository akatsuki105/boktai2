	push {r4, lr}
	sub sp, #0x14
	adds r4, r0, #0
	movs r1, #0xa2
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	adds r0, #0x41
	ldrb r0, [r0]
	add r2, sp, #8
	add r3, sp, #0xc
	add r1, sp, #0x10
	str r1, [sp]
	add r1, sp, #4
	bl FUN_081dfa20
	ldr r1, [sp, #8]
	movs r2, #0xd7
	lsls r2, r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	ldr r1, [sp, #0xc]
	adds r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	ldr r1, [sp, #4]
	adds r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	ldr r0, [sp, #0x10]
	ldr r1, _080CF018 @ =0x00000362
	adds r4, r4, r1
	strh r0, [r4]
	add sp, #0x14
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080CF018: .4byte 0x00000362
