	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	movs r0, #0xbd
	adds r0, r0, r7
	mov sl, r0
	ldrb r2, [r0]
	movs r0, #0x34
	adds r4, r2, #0
	muls r4, r0, r4
	adds r4, #0xc0
	adds r4, r7, r4
	adds r0, r4, #0
	movs r2, #2
	bl Particle_SetFrame
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	ldr r5, _080A1F50 @ =0x0203B400
	ldr r1, _080A1F54 @ =0x030046B8
	mov sb, r1
	ldr r1, [r1]
	adds r1, #1
	ldr r3, _080A1F58 @ =0x000003FF
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	adds r2, r7, #0
	adds r2, #0xac
	asrs r0, r0, #4
	movs r6, #0xff
	mov r8, r6
	mov r6, r8
	ands r0, r6
	ldrh r2, [r2]
	adds r0, r0, r2
	subs r0, #0x7f
	strh r0, [r4, #0x18]
	adds r1, #1
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r2, #0xae
	adds r2, r2, r7
	mov ip, r2
	movs r2, #0x3f
	ands r0, r2
	mov r6, ip
	ldrh r6, [r6]
	adds r0, r0, r6
	strh r0, [r4, #0x1a]
	adds r1, #1
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	adds r2, r7, #0
	adds r2, #0xb0
	asrs r0, r0, #4
	mov r6, r8
	ands r0, r6
	ldrh r2, [r2]
	adds r0, r0, r2
	subs r0, #0x7f
	strh r0, [r4, #0x1c]
	movs r0, #0
	strh r0, [r4, #0x28]
	adds r1, #1
	ands r1, r3
	mov r2, sb
	str r1, [r2]
	lsls r1, r1, #1
	adds r1, r1, r5
	ldrh r0, [r1]
	movs r1, #0xf
	ands r0, r1
	adds r0, #0x10
	strh r0, [r4, #0x2a]
	movs r6, #0
	strh r6, [r4, #0x2c]
	strh r6, [r4, #0x32]
	movs r0, #1
	strh r0, [r4, #0x30]
	mov r1, sl
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #7
	bls _080A1F42
	movs r0, #0
	strb r0, [r1]
_080A1F42:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A1F50: .4byte 0x0203B400
_080A1F54: .4byte 0x030046B8
_080A1F58: .4byte 0x000003FF
