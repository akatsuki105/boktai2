	push {r4, lr}
	sub sp, #8
	ldr r4, [sp, #0x10]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r4, [sp]
	movs r4, #0
	str r4, [sp, #4]
	bl FUN_08240d20
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	add sp, #8
	pop {r4}
	pop {r1}
	bx r1
