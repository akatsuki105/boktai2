	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov sb, r0
	movs r0, #4
	rsbs r0, r0, #0
	mov r8, r0
	movs r7, #0
	mov r5, sb
	adds r5, #0x18
	adds r4, r5, #0
	movs r6, #3
_080AC512:
	ldr r0, _080AC56C @ =0x00001C1E
	bl GetParticleGroup
	adds r1, r0, #0
	str r1, [r4, #0x30]
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0822d9f0
	adds r0, r5, #0
	movs r1, #1
	bl FUN_0822dadc
	adds r0, r5, #0
	mov r1, r8
	mov r2, r8
	bl Particle_SetOffset
	movs r0, #2
	strb r0, [r4, #0xf]
	movs r0, #0xec
	strb r0, [r4, #0x10]
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	strh r7, [r4, #0x34]
	strh r7, [r4, #0x36]
	adds r4, #0x40
	adds r5, #0x40
	subs r6, #1
	cmp r6, #0
	bge _080AC512
	ldr r0, _080AC570 @ =0x0000A854
	mov r1, sb
	movs r2, #0
	bl FUN_08230e30
	movs r0, #0
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080AC56C: .4byte 0x00001C1E
_080AC570: .4byte 0x0000A854
