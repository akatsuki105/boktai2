	push {r4, r5, r6, r7, lr}
	sub sp, #0x28
	ldr r6, [sp, #0x4c]
	ldr r7, [sp, #0x50]
	mov r4, sp
	movs r5, #0
	strh r1, [r4]
	mov r1, sp
	strh r2, [r1, #2]
	strh r3, [r1, #6]
	strh r6, [r1, #8]
	strh r7, [r1, #0xa]
	add r2, sp, #0x44
	ldrh r2, [r2]
	strh r2, [r1, #0xc]
	add r3, sp, #0x48
	ldrh r3, [r3]
	strh r3, [r1, #0xe]
	mov r2, sp
	movs r1, #0x3c
	strh r1, [r2, #0x10]
	movs r1, #8
	strh r1, [r2, #0x12]
	mov r1, sp
	ldrh r4, [r1, #0x3c]
	strh r4, [r1, #0x14]
	add r2, sp, #0x40
	ldrh r2, [r2]
	strh r2, [r1, #0x16]
	movs r2, #0xff
	strh r2, [r1, #0x18]
	strh r5, [r1, #0x1a]
	strh r2, [r1, #0x1c]
	strh r5, [r1, #0x1e]
	strh r2, [r1, #0x20]
	strh r5, [r1, #0x22]
	strh r2, [r1, #0x24]
	strh r5, [r1, #0x26]
	ldr r1, [sp, #0x54]
	mov r2, sp
	bl FUN_080155e4
	add sp, #0x28
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
