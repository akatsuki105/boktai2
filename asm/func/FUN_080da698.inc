	push {r4, r5, r6, r7, lr}
	sub sp, #0x18
	ldr r4, [sp, #0x2c]
	ldr r5, [sp, #0x30]
	ldr r6, [sp, #0x34]
	ldr r7, [sp, #0x38]
	str r7, [sp, #0x10]
	ldr r7, [sp, #0x3c]
	str r7, [sp, #0x14]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r4, [sp]
	str r5, [sp, #4]
	str r6, [sp, #8]
	movs r4, #3
	str r4, [sp, #0xc]
	bl FUN_080da110
	add sp, #0x18
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
