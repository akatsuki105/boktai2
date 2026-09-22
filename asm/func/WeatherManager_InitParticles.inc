	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r4, r0, #0
	ldr r0, _08017DBC @ =0x00001C1C
	bl GetParticleGroup
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r1, r4, r2
	str r0, [r1]
	adds r0, r4, #0
	adds r0, #0x60
	movs r1, #0
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	movs r0, #0xb4
	lsls r0, r0, #1
	adds r5, r4, r0
	mov r8, r1
	adds r6, r4, r2
	movs r7, #0x1f
	movs r2, #4
	rsbs r2, r2, #0
	mov sb, r2
_08017D7A:
	adds r4, r5, #0
	adds r4, #0x14
	mov r0, r8
	strb r0, [r5]
	strb r0, [r5, #1]
	strb r0, [r5, #2]
	ldr r1, [r6]
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0822da70
	adds r0, r4, #0
	mov r1, sb
	mov r2, sb
	bl Particle_SetOffset
	ldr r1, [r6]
	adds r0, r4, #0
	movs r2, #0x1e
	bl FUN_0822dafc
	subs r7, #1
	adds r5, #0x3c
	cmp r7, #0
	bge _08017D7A
	movs r0, #0
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08017DBC: .4byte 0x00001C1C
