	push {r4, r5, r6, lr}
	mov r6, sl
	mov r5, sb
	mov r4, r8
	push {r4, r5, r6}
	adds r6, r0, #0
	adds r4, r1, #0
	mov sb, r2
	mov sl, r3
	ldr r5, _080E05EC @ =0x030046A4
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r6, #0
	bl Div
	mov r8, r0
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r4, #0
	bl Div
	ldr r1, [r5]
	ldr r1, [r1, #4]
	movs r3, #4
	ldrsh r2, [r1, r3]
	mov r1, r8
	muls r1, r2, r1
	subs r6, r6, r1
	adds r1, r0, #0
	muls r1, r2, r1
	subs r4, r4, r1
	subs r4, r4, r6
	mov r1, sb
	str r4, [r1]
	mov r2, r8
	subs r0, r0, r2
	mov r3, sl
	str r0, [r3]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080E05EC: .4byte 0x030046A4
