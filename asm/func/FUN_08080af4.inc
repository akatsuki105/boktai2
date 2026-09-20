	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r4, r0, #0
	mov sb, r1
	adds r1, r4, #0
	adds r1, #0xcc
	movs r0, #0
	strb r0, [r1]
	ldr r0, _08080B64 @ =0x00001C1E
	bl GetParticleGroup
	adds r1, r4, #0
	adds r1, #0xd0
	str r0, [r1]
	adds r6, r1, #0
	adds r5, r4, #0
	adds r5, #0xfc
	adds r4, #0xd4
	movs r0, #4
	rsbs r0, r0, #0
	mov r8, r0
	movs r7, #3
_08080B24:
	ldr r1, [r6]
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0822d9f0
	adds r0, r4, #0
	mov r1, r8
	mov r2, r8
	bl Particle_SetOffset
	ldr r1, [r6]
	adds r0, r4, #0
	mov r2, sb
	bl FUN_0822dafc
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0822dadc
	movs r0, #0
	strb r0, [r5]
	adds r5, #0x30
	adds r4, #0x30
	subs r7, #1
	cmp r7, #0
	bge _08080B24
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08080B64: .4byte 0x00001C1E
