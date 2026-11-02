	push {r4, r5, r6, r7, lr}
	sub sp, #0x38
	ldr r4, [sp, #0x4c]
	ldr r5, [sp, #0x50]
	ldr r6, [sp, #0x54]
	ldr r7, [sp, #0x58]
	str r7, [sp, #0xc]
	ldr r7, [sp, #0x5c]
	str r7, [sp, #0x10]
	ldr r7, [sp, #0x60]
	str r7, [sp, #0x14]
	ldr r7, [sp, #0x64]
	str r7, [sp, #0x18]
	ldr r7, [sp, #0x68]
	str r7, [sp, #0x1c]
	ldr r7, [sp, #0x6c]
	str r7, [sp, #0x20]
	ldr r7, [sp, #0x70]
	str r7, [sp, #0x24]
	ldr r7, [sp, #0x74]
	str r7, [sp, #0x28]
	ldr r7, [sp, #0x78]
	str r7, [sp, #0x2c]
	ldr r7, [sp, #0x7c]
	str r7, [sp, #0x30]
	ldr r7, [sp, #0x80]
	str r7, [sp, #0x34]
	str r4, [sp]
	str r5, [sp, #4]
	str r6, [sp, #8]
	bl Entity081ee7a8_Spawn
	add sp, #0x38
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
