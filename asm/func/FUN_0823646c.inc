	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov ip, r0
	ldr r0, [sp, #0x18]
	ldr r5, [sp, #0x1c]
	ldr r6, [sp, #0x20]
	movs r4, #0
	mov r8, r4
	movs r4, #0
	mov r7, ip
	strh r2, [r7, #6]
	strh r1, [r7, #4]
	strh r3, [r7, #8]
	strh r0, [r7, #0xa]
	ldr r0, [r5]
	ldr r1, [r5, #4]
	mov r2, ip
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r7, #0x14]
	str r1, [r7, #0x18]
	mov r0, ip
	adds r0, #0x43
	mov r1, r8
	strb r1, [r0]
	strh r4, [r7, #0x3e]
	str r4, [r7, #0x34]
	str r4, [r7, #0x38]
	subs r0, #3
	strh r4, [r0]
	str r4, [r7, #0x48]
	mov r1, ip
	adds r1, #0x47
	movs r0, #1
	strb r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
