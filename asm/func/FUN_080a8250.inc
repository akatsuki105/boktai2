	push {r4, r5, r6, lr}
	mov r6, sl
	mov r5, sb
	mov r4, r8
	push {r4, r5, r6}
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
	ldr r1, _080A8304 @ =0x0203B400
	mov sb, r1
	ldr r1, _080A8308 @ =0x030046B8
	mov ip, r1
	ldr r2, [r1]
	adds r2, #1
	ldr r1, _080A830C @ =0x000003FF
	mov r8, r1
	ands r2, r1
	lsls r1, r2, #1
	add r1, sb
	ldrh r6, [r1]
	asrs r6, r6, #3
	movs r5, #0x7f
	ands r6, r5
	subs r6, #0x3f
	movs r1, #0
	mov sl, r1
	strh r6, [r0, #0x28]
	adds r2, #1
	mov r1, r8
	ands r2, r1
	lsls r1, r2, #1
	add r1, sb
	ldrh r4, [r1]
	asrs r4, r4, #3
	movs r1, #0x3f
	ands r4, r1
	adds r4, #0x40
	strh r4, [r0, #0x2a]
	adds r2, #1
	mov r1, r8
	ands r2, r1
	mov r1, ip
	str r2, [r1]
	lsls r1, r2, #1
	add r1, sb
	ldrh r3, [r1]
	asrs r3, r3, #3
	ands r3, r5
	subs r3, #0x3f
	strh r3, [r0, #0x2c]
	ldr r1, _080A8310 @ =0x03002BE0
	ldr r5, [r1]
	ldrh r1, [r5, #0x2c]
	adds r1, r1, r6
	strh r1, [r0, #0x18]
	ldrh r1, [r5, #0x2e]
	adds r1, r1, r4
	strh r1, [r0, #0x1a]
	ldrh r1, [r5, #0x30]
	adds r1, r1, r3
	strh r1, [r0, #0x1c]
	mov r1, sl
	strh r1, [r0, #0x30]
	adds r2, #1
	mov r1, r8
	ands r2, r1
	mov r1, ip
	str r2, [r1]
	lsls r2, r2, #1
	add r2, sb
	ldrh r1, [r2]
	movs r2, #7
	ands r1, r2
	adds r1, #0xc
	strh r1, [r0, #0x32]
	mov r1, sl
	strh r1, [r0, #0x34]
	strh r1, [r0, #0x3a]
	movs r1, #1
	strh r1, [r0, #0x38]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A8304: .4byte 0x0203B400
_080A8308: .4byte 0x030046B8
_080A830C: .4byte 0x000003FF
_080A8310: .4byte 0x03002BE0
