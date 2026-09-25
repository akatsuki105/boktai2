	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r4, r0, #0
	adds r6, r4, #0
	adds r6, #0x9c
	ldr r0, _080AC030 @ =0x00001C1E
	bl GetParticleGroup
	str r0, [r6, #4]
	movs r0, #0
	strb r0, [r6]
	strb r0, [r6, #1]
	adds r4, #0x24
	ldrb r0, [r4]
	cmp r0, #7
	bne _080AC034
	movs r0, #0xe
	b _080AC03A
	.align 2, 0
_080AC030: .4byte 0x00001C1E
_080AC034:
	ldrb r0, [r4]
	adds r0, #1
	lsls r0, r0, #1
_080AC03A:
	mov sb, r0
	movs r0, #4
	rsbs r0, r0, #0
	mov r8, r0
	adds r4, r6, #0
	adds r4, #0x17
	adds r5, r6, #0
	adds r5, #8
	movs r7, #7
_080AC04C:
	movs r0, #0
	strb r0, [r4, #0x19]
	mov r0, sb
	strb r0, [r4, #0x1a]
	ldr r1, [r6, #4]
	adds r0, r5, #0
	movs r2, #1
	bl FUN_0822d9f0
	adds r0, r5, #0
	mov r1, r8
	mov r2, r8
	bl Particle_SetOffset
	adds r0, r5, #0
	movs r1, #1
	bl FUN_0822dadc
	movs r0, #0xf8
	strb r0, [r4, #1]
	movs r0, #2
	strb r0, [r4]
	adds r4, #0x3c
	adds r5, #0x3c
	subs r7, #1
	cmp r7, #0
	bge _080AC04C
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
