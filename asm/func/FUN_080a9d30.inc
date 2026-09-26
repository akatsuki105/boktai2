	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sl, r0
	ldr r0, _080A9DA4 @ =0x00001C1E
	bl GetParticleGroup
	adds r6, r0, #0
	movs r0, #0
	mov sb, r0
	mov r5, sl
	adds r5, #0x8c
	mov r8, r0
	movs r7, #7
_080A9D50:
	mov r4, sl
	adds r4, #0xc0
	add r4, r8
	str r6, [r4]
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #0x11
	bl FUN_0822d9f0
	adds r0, r5, #0
	movs r1, #4
	rsbs r1, r1, #0
	adds r2, r1, #0
	bl Particle_SetOffset
	ldr r1, [r4]
	adds r0, r5, #0
	movs r2, #2
	bl FUN_0822dafc
	adds r0, r5, #0
	movs r1, #1
	bl FUN_0822dadc
	mov r0, sb
	strb r0, [r5, #0xf]
	mov r0, sb
	strh r0, [r5, #0x28]
	strh r0, [r5, #0x2a]
	adds r5, #0x3c
	movs r0, #0x3c
	add r8, r0
	subs r7, #1
	cmp r7, #0
	bge _080A9D50
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A9DA4: .4byte 0x00001C1E
