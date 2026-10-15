	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	movs r1, #0
	mov r8, r1
	adds r4, r0, #0
	adds r4, #0x18
	adds r6, r0, #0
	adds r6, #0x44
	adds r5, r4, #0
	movs r0, #8
	rsbs r0, r0, #0
	mov sb, r0
	movs r7, #7
_080ACCCE:
	mov r1, r8
	strb r1, [r6]
	strb r1, [r6, #1]
	mov r0, r8
	strh r0, [r4, #0x2e]
	ldr r0, _080ACD24 @ =0x00001C1A
	bl GetParticleGroup
	adds r1, r0, #0
	str r1, [r4, #0x28]
	adds r0, r5, #0
	movs r2, #0
	bl Particle_Add
	adds r0, r5, #0
	mov r1, sb
	mov r2, sb
	bl Particle_SetOffset
	ldr r1, [r4, #0x28]
	adds r0, r5, #0
	movs r2, #0xc
	bl Particle_SetFrame
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	movs r0, #2
	strb r0, [r4, #0xf]
	adds r4, #0x30
	adds r6, #0x30
	adds r5, #0x30
	subs r7, #1
	cmp r7, #0
	bge _080ACCCE
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080ACD24: .4byte 0x00001C1A
