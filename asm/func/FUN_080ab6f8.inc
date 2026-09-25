	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	movs r0, #0x9c
	lsls r0, r0, #1
	adds r6, r5, r0
	ldr r0, _080AB778 @ =0x00001C1E
	bl GetParticleGroup
	str r0, [r6, #4]
	movs r0, #0
	strb r0, [r6]
	strb r0, [r6, #1]
	ldrb r0, [r5, #0x18]
	movs r1, #4
	mov sb, r1
	cmp r0, #0
	bne _080AB724
	movs r0, #2
	mov sb, r0
_080AB724:
	movs r1, #4
	rsbs r1, r1, #0
	mov r8, r1
	ldr r0, _080AB77C @ =0x0000014F
	adds r4, r5, r0
	movs r1, #0xa0
	lsls r1, r1, #1
	adds r5, r5, r1
	movs r7, #0xb
_080AB736:
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
	adds r4, #0x44
	adds r5, #0x44
	subs r7, #1
	cmp r7, #0
	bge _080AB736
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AB778: .4byte 0x00001C1E
_080AB77C: .4byte 0x0000014F
