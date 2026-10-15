	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r6, r0, #0
	movs r7, #0
	ldr r0, _080A35F8 @ =0x00001C1E
	mov sb, r0
	movs r0, #0
	mov sl, r0
	subs r0, #4
	mov r8, r0
_080A3582:
	movs r0, #0x34
	adds r5, r7, #0
	muls r5, r0, r5
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r4, r5, r0
	adds r4, r6, r4
	mov r0, sb
	bl GetParticleGroup
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #1
	bl Particle_Add
	adds r0, r4, #0
	mov r1, r8
	mov r2, r8
	bl Particle_SetOffset
	adds r0, r4, #0
	movs r1, #1
	bl Particle_SetPltt
	mov r0, sb
	bl GetParticleGroup
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #2
	bl Particle_SetFrame
	movs r0, #1
	strb r0, [r4, #0xf]
	movs r0, #0x14
	strb r0, [r4, #0x10]
	adds r0, r6, #0
	adds r0, #0x98
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r4, #0x18]
	str r1, [r4, #0x1c]
	adds r5, r6, r5
	movs r0, #0xf8
	lsls r0, r0, #1
	adds r5, r5, r0
	mov r0, sl
	strb r0, [r5]
	adds r7, #1
	cmp r7, #7
	ble _080A3582
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A35F8: .4byte 0x00001C1E
