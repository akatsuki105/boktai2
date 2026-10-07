	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r5, r0, #0
	mov r8, r2
	mov sb, r3
	ldr r6, [sp, #0x20]
	movs r0, #0xac
	lsls r0, r0, #3
	adds r3, r5, r0
	ldr r2, _080AD360 @ =0x00000BE5
	adds r7, r5, r2
	ldrb r2, [r7]
	movs r0, #0x34
	adds r4, r2, #0
	muls r4, r0, r4
	adds r4, #4
	adds r4, r3, r4
	ldr r0, [r4]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r4]
	ldr r0, [r1]
	ldr r1, [r1, #4]
	str r0, [r4, #0x18]
	str r1, [r4, #0x1c]
	movs r0, #0
	mov sl, r0
	strb r6, [r4, #0xf]
	ldr r1, [r3]
	adds r0, r4, #0
	movs r2, #2
	bl Particle_SetFrame
	mov r2, r8
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r4, #0x28]
	str r1, [r4, #0x2c]
	adds r0, r4, #0
	adds r0, #0x31
	mov r1, sl
	strb r1, [r0]
	adds r0, #1
	mov r2, sb
	strb r2, [r0]
	adds r4, #0x30
	movs r0, #1
	strb r0, [r4]
	ldr r1, _080AD364 @ =0x00000BE4
	adds r5, r5, r1
	strb r0, [r5]
	ldrb r0, [r7]
	adds r0, #1
	strb r0, [r7]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1f
	bls _080AD350
	mov r2, sl
	strb r2, [r7]
_080AD350:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AD360: .4byte 0x00000BE5
_080AD364: .4byte 0x00000BE4
