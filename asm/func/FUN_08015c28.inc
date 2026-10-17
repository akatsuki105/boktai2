	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x28
	mov r8, r0
	adds r0, r3, #0
	ldr r5, [sp, #0x40]
	ldr r6, [sp, #0x44]
	ldr r7, [sp, #0x48]
	mov r3, sp
	movs r4, #0
	strh r5, [r3]
	strh r6, [r3, #2]
	strh r7, [r3, #6]
	strh r4, [r3, #8]
	strh r4, [r3, #0xa]
	add r5, sp, #0x4c
	ldrh r5, [r5]
	strh r5, [r3, #0xc]
	strh r4, [r3, #0xe]
	strh r4, [r3, #0x10]
	strh r4, [r3, #0x12]
	strh r1, [r3, #0x14]
	mov r1, sp
	strh r2, [r1, #0x16]
	add r6, sp, #0x50
	ldrh r6, [r6]
	strh r6, [r1, #0x18]
	strh r4, [r1, #0x1a]
	add r2, sp, #0x54
	ldrh r2, [r2]
	strh r2, [r1, #0x1c]
	strh r4, [r1, #0x1e]
	add r3, sp, #0x50
	ldrh r3, [r3]
	strh r3, [r1, #0x20]
	strh r4, [r1, #0x22]
	add r5, sp, #0x54
	ldrh r5, [r5]
	strh r5, [r1, #0x24]
	strh r4, [r1, #0x26]
	mov r1, r8
	mov r2, sp
	bl FUN_080155e4
	add sp, #0x28
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
