	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x28
	mov r8, r0
	ldr r5, [sp, #0x40]
	ldr r6, [sp, #0x44]
	ldr r7, [sp, #0x48]
	mov r0, sp
	movs r4, #0
	strh r1, [r0]
	strh r2, [r0, #2]
	strh r3, [r0, #6]
	strh r5, [r0, #8]
	strh r6, [r0, #0xa]
	strh r7, [r0, #0xc]
	add r1, sp, #0x4c
	ldrh r1, [r1]
	strh r1, [r0, #0xe]
	mov r1, sp
	movs r0, #0x3c
	strh r0, [r1, #0x10]
	movs r0, #8
	strh r0, [r1, #0x12]
	mov r0, sp
	strh r4, [r0, #0x14]
	movs r1, #0xff
	strh r1, [r0, #0x16]
	strh r1, [r0, #0x18]
	strh r4, [r0, #0x1a]
	strh r1, [r0, #0x1c]
	strh r4, [r0, #0x1e]
	strh r1, [r0, #0x20]
	strh r4, [r0, #0x22]
	strh r1, [r0, #0x24]
	strh r4, [r0, #0x26]
	movs r0, #1
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
