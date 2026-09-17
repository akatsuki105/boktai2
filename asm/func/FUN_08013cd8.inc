	push {r4, r5, r6, r7, lr}
	mov ip, r0
	ldr r4, [sp, #0x14]
	ldr r5, [sp, #0x18]
	ldr r6, [sp, #0x1c]
	ldr r7, [sp, #0x20]
	adds r0, #0x54
	strb r1, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #1
	strb r3, [r0]
	adds r0, #1
	strb r4, [r0]
	adds r0, #1
	strh r5, [r0]
	adds r0, #2
	strh r6, [r0]
	adds r0, #2
	strh r7, [r0]
	adds r0, #2
	mov r1, sp
	ldrh r1, [r1, #0x24]
	strh r1, [r0]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
