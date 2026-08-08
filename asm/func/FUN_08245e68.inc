	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	adds r6, r1, #0
	mov r8, r2
	movs r0, #0x92
	lsls r0, r0, #1
	adds r4, r6, r0
	movs r5, #8
_08245E7C:
	adds r0, r4, #0
	bl FUN_0822a4e0
	subs r5, #1
	adds r4, #0x2c
	cmp r5, #0
	bge _08245E7C
	adds r3, r6, #0
	adds r3, #0xd4
	ldrh r2, [r3, #6]
	movs r1, #4
	orrs r1, r2
	strh r1, [r3, #6]
	movs r2, #1
	mov r1, r8
	lsls r2, r1
	ldr r1, [r7, #0x18]
	bics r1, r2
	str r1, [r7, #0x18]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
