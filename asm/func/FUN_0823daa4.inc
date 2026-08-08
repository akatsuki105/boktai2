	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	adds r6, r1, #0
	mov sb, r2
	cmp r6, #2
	bgt _0823DABA
	subs r7, #1
	adds r6, #0xc
_0823DABA:
	adds r0, r7, #0
	movs r1, #4
	bl Div
	adds r4, r0, #0
	adds r0, r7, #0
	movs r1, #0x64
	bl Div
	mov r8, r0
	movs r1, #0xc8
	lsls r1, r1, #1
	adds r0, r7, #0
	bl Div
	adds r5, r0, #0
	movs r0, #0xd
	muls r0, r6, r0
	adds r0, #8
	movs r1, #5
	bl Div
	adds r4, r7, r4
	mov r1, r8
	subs r4, r4, r1
	adds r4, r4, r5
	adds r4, r4, r0
	add r4, sb
	adds r0, r4, #0
	movs r1, #7
	bl Mod
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
