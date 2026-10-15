	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	movs r0, #8
	adds r0, r0, r1
	mov sb, r0
	ldr r0, [r1, #8]
	movs r3, #2
	rsbs r3, r3, #0
	ands r0, r3
	str r0, [r1, #8]
	movs r0, #0
	mov r8, r0
	movs r6, #1
	movs r0, #1
	strb r0, [r1]
	ldr r5, _0801ABA4 @ =0x0203B400
	ldr r3, _0801ABA8 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r4, _0801ABAC @ =0x000003FF
	ands r0, r4
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	ands r2, r6
	adds r2, #3
	ands r0, r6
	adds r2, r2, r0
	strb r2, [r1, #1]
	ldr r0, [r3]
	adds r0, #1
	ands r0, r4
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r2, #3
	ands r0, r2
	adds r0, #5
	ldrb r2, [r1, #1]
	subs r0, r0, r2
	asrs r0, r0, #2
	strb r0, [r1, #2]
	ldr r0, [r3]
	adds r0, #1
	ands r0, r4
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r2, #7
	ands r0, r2
	adds r0, #1
	strb r0, [r1, #3]
	mov r2, r8
	strb r2, [r1, #4]
	mov r0, r8
	strh r0, [r1, #6]
	ldr r0, [r3]
	adds r0, #1
	ands r0, r4
	str r0, [r3]
	lsls r1, r0, #1
	adds r1, r1, r5
	ldrb r1, [r1]
	subs r1, #0x10
	mov r2, sb
	strh r1, [r2, #0x1c]
	adds r0, #1
	ands r0, r4
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r1, #0x7f
	ands r0, r1
	adds r0, #0xa0
	strh r0, [r2, #0x1e]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801ABA4: .4byte 0x0203B400
_0801ABA8: .4byte 0x030046B8
_0801ABAC: .4byte 0x000003FF
