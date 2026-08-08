	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	mov r8, r1
	str r2, [sp]
	mov sb, r3
	ldr r0, [sp, #0x24]
	mov sl, r0
	adds r0, r7, #0
	movs r1, #4
	bl Div
	adds r5, r0, #0
	adds r0, r7, #0
	movs r1, #0x64
	bl Div
	adds r4, r0, #0
	movs r1, #0xc8
	lsls r1, r1, #1
	adds r0, r7, #0
	bl Div
	ldr r1, _0823DAA0 @ =0x0000016D
	muls r1, r7, r1
	adds r1, r1, r5
	subs r1, r1, r4
	adds r6, r1, r0
	movs r4, #1
	cmp r4, r8
	bge _0823DA42
_0823DA32:
	adds r0, r7, #0
	adds r1, r4, #0
	bl FUN_0823d970
	adds r6, r6, r0
	adds r4, #1
	cmp r4, r8
	blt _0823DA32
_0823DA42:
	ldr r2, [sp]
	adds r6, r6, r2
	mov r0, sb
	movs r1, #4
	bl Div
	adds r5, r0, #0
	mov r0, sb
	movs r1, #0x64
	bl Div
	adds r4, r0, #0
	movs r1, #0xc8
	lsls r1, r1, #1
	mov r0, sb
	bl Div
	ldr r1, _0823DAA0 @ =0x0000016D
	mov r2, sb
	muls r2, r1, r2
	adds r1, r2, #0
	adds r1, r1, r5
	subs r1, r1, r4
	adds r5, r1, r0
	movs r4, #1
	cmp r4, sl
	bge _0823DA88
_0823DA78:
	mov r0, sb
	adds r1, r4, #0
	bl FUN_0823d970
	adds r5, r5, r0
	adds r4, #1
	cmp r4, sl
	blt _0823DA78
_0823DA88:
	ldr r0, [sp, #0x28]
	adds r5, r5, r0
	subs r0, r6, r5
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0823DAA0: .4byte 0x0000016D
