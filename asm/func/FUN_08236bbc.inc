	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r7, r0, #0
	mov r8, r1
	adds r4, r3, #0
	adds r5, r2, #0
	adds r5, #0x24
	adds r6, r2, #0
	adds r6, #0x1c
	str r4, [sp]
	adds r2, r5, #0
	adds r3, r6, #0
	bl FUN_082368d4
	cmp r0, #0
	bne _08236C08
	str r4, [sp]
	adds r0, r7, #0
	mov r1, r8
	adds r2, r5, #0
	adds r3, r6, #0
	bl FUN_082369cc
	cmp r0, #0
	bne _08236C08
	str r4, [sp]
	adds r0, r7, #0
	mov r1, r8
	adds r2, r5, #0
	adds r3, r6, #0
	bl FUN_08236ac4
	cmp r0, #0
	bne _08236C08
	movs r0, #0
	b _08236C0A
_08236C08:
	movs r0, #1
_08236C0A:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
