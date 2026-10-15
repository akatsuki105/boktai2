	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r6, r0, #0
	ldr r0, _080A2290 @ =0x00001C1E
	bl GetParticleGroup
	adds r1, r6, #0
	adds r1, #0xb8
	str r0, [r1]
	movs r7, #0
	mov r8, r1
	movs r0, #4
	rsbs r0, r0, #0
	mov sl, r0
	movs r1, #1
	mov sb, r1
_080A2222:
	movs r0, #0x34
	adds r5, r7, #0
	muls r5, r0, r5
	adds r4, r5, #0
	adds r4, #0xc0
	adds r4, r6, r4
	mov r0, r8
	ldr r1, [r0]
	adds r0, r4, #0
	movs r2, #0
	bl Particle_Add
	adds r0, r4, #0
	mov r1, sl
	mov r2, sl
	bl Particle_SetOffset
	mov r0, r8
	ldr r1, [r0]
	adds r0, r4, #0
	movs r2, #2
	bl Particle_SetFrame
	adds r0, r4, #0
	movs r1, #1
	bl Particle_SetPltt
	mov r1, sb
	strb r1, [r4, #0xf]
	movs r0, #0x14
	strb r0, [r4, #0x10]
	ldr r0, [r4]
	mov r1, sb
	orrs r0, r1
	str r0, [r4]
	adds r5, r6, r5
	adds r5, #0xf0
	movs r0, #0
	strh r0, [r5]
	adds r7, #1
	cmp r7, #7
	ble _080A2222
	adds r0, r6, #0
	adds r0, #0xbd
	movs r1, #0
	strb r1, [r0]
	adds r0, #1
	strh r1, [r0]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A2290: .4byte 0x00001C1E
