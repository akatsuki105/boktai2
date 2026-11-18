	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	str r3, [sp]
	str r0, [sp, #4]
	movs r3, #0xcb
	lsls r3, r3, #3
	adds r7, r0, r3
	ldr r0, _0819EB70 @ =0x03003584
	lsls r3, r1, #5
	ldr r0, [r0]
	lsls r2, r2, #5
	adds r2, r0, r2
	str r2, [sp, #8]
	strh r1, [r7, #0x22]
	adds r0, r0, r3
	mov sl, r0
	movs r0, #0
	mov sb, r0
	movs r1, #0xf
	str r1, [sp, #0xc]
_0819EB60:
	ldrh r0, [r7, #0x20]
	movs r2, #0x80
	lsls r2, r2, #1
	cmp r0, r2
	beq _0819EB74
	mov r3, sb
	adds r0, r7, r3
	b _0819EB78
	.align 2, 0
_0819EB70: .4byte 0x03003584
_0819EB74:
	ldr r0, [sp, #8]
	add r0, sb
_0819EB78:
	ldrh r5, [r0]
	adds r3, r7, #0
	adds r3, #0x84
	add r3, sb
	mov r0, sl
	ldrh r1, [r0]
	movs r0, #0x1f
	ands r0, r1
	mov r8, r5
	mov r1, r8
	movs r2, #0x1f
	ands r1, r2
	mov r8, r1
	subs r0, r0, r1
	lsls r0, r0, #8
	strh r0, [r3]
	adds r6, r7, #0
	adds r6, #0xa4
	add r6, sb
	mov r1, sl
	ldrh r0, [r1]
	lsrs r0, r0, #5
	ands r0, r2
	asrs r2, r5, #5
	movs r1, #0x1f
	ands r2, r1
	subs r0, r0, r2
	lsls r0, r0, #8
	strh r0, [r6]
	adds r4, r7, #0
	adds r4, #0xc4
	add r4, sb
	mov r1, sl
	ldrh r0, [r1]
	lsrs r0, r0, #0xa
	movs r1, #0x1f
	ands r0, r1
	asrs r5, r5, #0xa
	ands r5, r1
	subs r0, r0, r5
	lsls r0, r0, #8
	strh r0, [r4]
	movs r1, #0
	ldrsh r0, [r3, r1]
	ldr r1, [sp]
	str r2, [sp, #0x10]
	str r3, [sp, #0x14]
	bl Div
	ldr r3, [sp, #0x14]
	strh r0, [r3]
	movs r3, #0
	ldrsh r0, [r6, r3]
	ldr r1, [sp]
	bl Div
	strh r0, [r6]
	movs r1, #0
	ldrsh r0, [r4, r1]
	ldr r1, [sp]
	bl Div
	strh r0, [r4]
	adds r0, r7, #0
	adds r0, #0x24
	add r0, sb
	mov r3, r8
	lsls r3, r3, #8
	strh r3, [r0]
	adds r0, r7, #0
	adds r0, #0x44
	add r0, sb
	ldr r2, [sp, #0x10]
	lsls r2, r2, #8
	strh r2, [r0]
	adds r0, r7, #0
	adds r0, #0x64
	add r0, sb
	lsls r5, r5, #8
	strh r5, [r0]
	movs r0, #2
	add sl, r0
	add sb, r0
	ldr r1, [sp, #0xc]
	subs r1, #1
	str r1, [sp, #0xc]
	cmp r1, #0
	bge _0819EB60
	mov r2, sp
	ldrh r2, [r2]
	strh r2, [r7, #0x20]
	movs r2, #2
	ldr r3, [sp, #4]
	ldr r0, _0819EC4C @ =0x00000E48
	adds r1, r3, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0819EC4C: .4byte 0x00000E48
