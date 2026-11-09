	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	ldr r2, [r1, #4]
	ldr r1, [r1]
	str r1, [r0, #0x18]
	str r2, [r0, #0x1c]
	ldr r6, _080A2710 @ =0x0203B400
	ldr r1, _080A2714 @ =0x030046B8
	mov sb, r1
	ldr r3, [r1]
	adds r3, #1
	ldr r4, _080A2718 @ =0x000003FF
	ands r3, r4
	lsls r1, r3, #1
	adds r1, r1, r6
	ldrh r2, [r1]
	ldrh r1, [r0, #0x18]
	subs r1, #0xf
	movs r5, #0x1f
	ands r2, r5
	adds r1, r1, r2
	movs r2, #0
	mov r8, r2
	strh r1, [r0, #0x18]
	adds r3, #1
	ands r3, r4
	lsls r2, r3, #1
	adds r2, r2, r6
	ldrh r1, [r0, #0x1a]
	ldrb r2, [r2]
	adds r1, r1, r2
	strh r1, [r0, #0x1a]
	adds r3, #1
	ands r3, r4
	lsls r1, r3, #1
	adds r1, r1, r6
	ldrh r2, [r1]
	ldrh r1, [r0, #0x1c]
	subs r1, #0xf
	ands r2, r5
	adds r1, r1, r2
	strh r1, [r0, #0x1c]
	adds r2, r0, #0
	adds r2, #0x29
	movs r1, #0x18
	strb r1, [r2]
	mov r1, r8
	strh r1, [r0, #0x2c]
	adds r3, #1
	ands r3, r4
	mov r2, sb
	str r3, [r2]
	lsls r3, r3, #1
	adds r3, r3, r6
	ldrh r1, [r3]
	ands r1, r5
	adds r1, #0x18
	strh r1, [r0, #0x2e]
	mov r1, r8
	strh r1, [r0, #0x30]
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
	adds r0, #0x28
	movs r1, #1
	strb r1, [r0]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A2710: .4byte 0x0203B400
_080A2714: .4byte 0x030046B8
_080A2718: .4byte 0x000003FF
