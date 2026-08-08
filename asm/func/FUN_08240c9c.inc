	push {r4, lr}
	sub sp, #8
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	movs r4, #1
	str r4, [sp]
	movs r4, #0
	str r4, [sp, #4]
	bl FUN_08240bcc
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
