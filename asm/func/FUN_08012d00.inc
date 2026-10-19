	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sl, r0
	mov sb, r1
	adds r6, r2, #0
	mov r8, r3
	movs r1, #1
	lsls r1, r3
	subs r1, #1
	cmp sb, r1
	bls _08012D1E
	mov sb, r1
_08012D1E:
	movs r7, #0
	cmp r7, r8
	bge _08012D5A
_08012D24:
	ldr r0, [r6]
	movs r1, #6
	bl Div
	adds r5, r0, #0
	ldr r0, [r6]
	movs r1, #6
	bl Mod
	adds r4, r0, #0
	mov r1, sb
	lsrs r1, r7
	movs r2, #1
	ands r1, r2
	mov r3, sl
	adds r3, #0x2a
	adds r3, r3, r5
	lsls r1, r4
	ldrb r2, [r3]
	orrs r1, r2
	strb r1, [r3]
	ldr r1, [r6]
	adds r1, #1
	str r1, [r6]
	adds r7, #1
	cmp r7, r8
	blt _08012D24
_08012D5A:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
