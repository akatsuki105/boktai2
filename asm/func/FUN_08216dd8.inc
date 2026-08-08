	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #8
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r1, _08216E54 @ =0x082527FC
	mov r0, sp
	movs r2, #8
	bl memcpy
	adds r0, r6, #0
	movs r1, #6
	bl Div
	adds r4, r0, #0
	lsls r1, r4, #1
	adds r4, r1, r4
	lsls r4, r4, #1
	subs r4, r6, r4
	mov r2, sp
	adds r0, r2, r1
	lsls r4, r4, #1
	ldrb r0, [r0]
	adds r4, r4, r0
	mov r0, sp
	adds r0, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	mov r8, r0
	ldr r1, _08216E58 @ =0x00001790
	adds r0, r5, r1
	ldr r0, [r0]
	bl FUN_08231660
	ldr r2, _08216E5C @ =0x00001FC4
	adds r5, r5, r2
	adds r5, r5, r6
	movs r1, #0
	ldrsb r1, [r5, r1]
	adds r0, r0, r1
	bl FUN_08231978
	adds r5, r0, #0
	adds r0, r4, #0
	mov r1, r8
	movs r2, #2
	movs r3, #2
	bl FUN_0821b28c
	adds r0, r4, #0
	mov r1, r8
	adds r2, r5, #0
	bl FUN_0821b2b4
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08216E54: .4byte 0x082527FC
_08216E58: .4byte 0x00001790
_08216E5C: .4byte 0x00001FC4
