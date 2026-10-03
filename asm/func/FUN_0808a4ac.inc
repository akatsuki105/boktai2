	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	mov r8, r1
	adds r4, r2, #0
	adds r6, r3, #0
	adds r0, r4, #0
	movs r1, #0x64
	bl Div
	str r0, [sp]
	movs r5, #0x64
	muls r0, r5, r0
	subs r7, r4, r0
	adds r0, r7, #0
	movs r1, #0xa
	bl Div
	str r0, [sp, #4]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	subs r1, r7, r1
	str r1, [sp, #8]
	adds r0, r6, #0
	movs r1, #0x64
	bl Div
	add r4, sp, #0xc
	str r0, [sp, #0xc]
	muls r0, r5, r0
	subs r7, r6, r0
	adds r0, r7, #0
	movs r1, #0xa
	bl Div
	str r0, [r4, #4]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	subs r1, r7, r1
	str r1, [r4, #8]
	mov r0, r8
	cmp r0, #0
	bne _0808A522
	movs r6, #0
	movs r1, #0x1c
	mov r8, r1
	mov sb, r6
	movs r0, #3
	mov sl, r0
	movs r7, #0xd0
	lsls r7, r7, #8
	movs r0, #0
	ldr r1, [sp, #0x3c]
	b _0808A538
_0808A522:
	movs r6, #1
	movs r1, #0x9b
	mov r8, r1
	mov sb, r6
	movs r0, #4
	mov sl, r0
	movs r7, #0xf0
	lsls r7, r7, #8
	ldr r1, [sp, #0x3c]
	subs r1, #1
	movs r0, #0
_0808A538:
	ldr r2, [sp, #0x40]
	bl FUN_0808a420
	adds r5, r0, #0
	adds r0, r7, #0
	orrs r0, r6
	strh r0, [r5]
	adds r5, #2
	str r0, [sp, #0x18]
	adds r4, r7, #0
	mov r1, r8
	orrs r4, r1
	mov r8, sp
	movs r6, #2
_0808A554:
	mov r1, r8
	adds r1, #4
	mov r8, r1
	subs r1, #4
	ldm r1!, {r0}
	mov r1, sb
	bl FUN_0808a440
	orrs r0, r7
	strh r0, [r5]
	adds r5, #2
	subs r6, #1
	cmp r6, #0
	bge _0808A554
	strh r4, [r5]
	adds r5, #2
	add r4, sp, #0xc
	movs r6, #2
_0808A578:
	ldm r4!, {r0}
	mov r1, sb
	bl FUN_0808a440
	orrs r0, r7
	strh r0, [r5]
	adds r5, #2
	subs r6, #1
	cmp r6, #0
	bge _0808A578
	mov r0, sl
	cmp r0, #0
	beq _0808A5A0
	ldr r0, [sp, #0x18]
	mov r6, sl
_0808A596:
	strh r0, [r5]
	adds r5, #2
	subs r6, #1
	cmp r6, #0
	bne _0808A596
_0808A5A0:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
