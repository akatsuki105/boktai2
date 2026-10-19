	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r6, [sp, #0x14]
	cmp r4, #9
	bgt _0820847A
	ldrh r0, [r5, #0x20]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	adds r1, r4, r1
	str r6, [sp]
	adds r0, r5, #0
	bl FUN_08041480
	b _08208484
_0820847A:
	str r6, [sp]
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08041480
_08208484:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
