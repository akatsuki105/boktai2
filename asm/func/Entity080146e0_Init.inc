	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	ldr r0, _080146D4 @ =0x03000058
	str r6, [r0]
	ldr r0, _080146D8 @ =0x00001C1C
	bl GetParticleGroup
	str r0, [r6, #0x1c]
	ldr r0, _080146DC @ =0x00001C1E
	bl GetParticleGroup
	str r0, [r6, #0x20]
	movs r3, #0
	movs r0, #4
	rsbs r0, r0, #0
	mov r8, r0
_08014688:
	lsls r0, r3, #3
	subs r0, r0, r3
	lsls r0, r0, #4
	adds r0, r0, r3
	lsls r0, r0, #2
	adds r1, r6, r0
	adds r1, #0x24
	movs r2, #0
	strb r2, [r1]
	adds r7, r3, #1
	adds r0, #0x38
	adds r4, r6, r0
	movs r5, #7
_080146A2:
	ldr r1, [r6, #0x1c]
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0822da70
	adds r0, r4, #0
	mov r1, r8
	mov r2, r8
	bl Particle_SetOffset
	adds r4, #0x38
	subs r5, #1
	cmp r5, #0
	bge _080146A2
	adds r3, r7, #0
	cmp r3, #5
	ble _08014688
	movs r0, #0
	str r0, [r6, #0x18]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080146D4: .4byte 0x03000058
_080146D8: .4byte 0x00001C1C
_080146DC: .4byte 0x00001C1E
