	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	movs r1, #0xe9
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r1, #0
	strh r1, [r0]
	ldr r2, _08084C28 @ =0x000003A6
	adds r0, r4, r2
	strh r1, [r0]
	ldr r0, _08084C2C @ =0x00001C1E
	bl GetParticleGroup
	adds r1, r4, #0
	adds r1, #0xd0
	str r0, [r1]
	adds r5, r1, #0
	movs r0, #0
	mov r8, r0
	adds r4, #0xd4
	movs r7, #4
	rsbs r7, r7, #0
	movs r6, #0xb
_08084BE2:
	ldr r1, [r5]
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0822d9f0
	adds r0, r4, #0
	adds r1, r7, #0
	adds r2, r7, #0
	bl Particle_SetOffset
	ldr r1, [r5]
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0822dafc
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0822dadc
	movs r0, #1
	strb r0, [r4, #0xf]
	movs r0, #0x14
	strb r0, [r4, #0x10]
	mov r1, r8
	strh r1, [r4, #0x2c]
	strh r1, [r4, #0x2e]
	adds r4, #0x3c
	subs r6, #1
	cmp r6, #0
	bge _08084BE2
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08084C28: .4byte 0x000003A6
_08084C2C: .4byte 0x00001C1E
