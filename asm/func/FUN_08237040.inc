	push {r4, r5, lr}
	sub sp, #4
	ldr r5, [sp, #0x10]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	movs r4, #0
	strb r4, [r0, #5]
	str r5, [sp]
	bl FUN_08236fac
	add sp, #4
	pop {r4, r5}
	pop {r1}
	bx r1
