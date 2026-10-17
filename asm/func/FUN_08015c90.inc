	push {r4, r5, r6, lr}
	sub sp, #0x28
	ldr r6, [sp, #0x38]
	mov r4, sp
	movs r5, #0
	strh r1, [r4]
	mov r1, sp
	strh r2, [r1, #2]
	strh r3, [r1, #6]
	movs r2, #0xc
	strh r2, [r1, #8]
	strh r2, [r1, #0xa]
	movs r2, #4
	strh r2, [r1, #0xc]
	strh r2, [r1, #0xe]
	mov r2, sp
	movs r1, #0x3c
	strh r1, [r2, #0x10]
	movs r1, #8
	strh r1, [r2, #0x12]
	mov r1, sp
	strh r5, [r1, #0x14]
	movs r2, #0xff
	strh r2, [r1, #0x16]
	strh r2, [r1, #0x18]
	strh r5, [r1, #0x1a]
	strh r2, [r1, #0x1c]
	strh r5, [r1, #0x1e]
	strh r2, [r1, #0x20]
	strh r5, [r1, #0x22]
	strh r2, [r1, #0x24]
	strh r5, [r1, #0x26]
	adds r1, r6, #0
	mov r2, sp
	bl FUN_080155e4
	add sp, #0x28
	pop {r4, r5, r6}
	pop {r0}
	bx r0
