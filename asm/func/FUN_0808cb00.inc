	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	str r0, [sp]
	movs r4, #0
_0808CB10:
	lsls r0, r4, #6
	adds r0, r0, r4
	lsls r0, r0, #3
	ldr r1, _0808CB88 @ =0x00003B8C
	adds r0, r0, r1
	ldr r1, [sp]
	adds r6, r1, r0
	movs r0, #0x91
	str r0, [sp, #4]
	cmp r4, #0
	bne _0808CB2A
	movs r1, #0x11
	str r1, [sp, #4]
_0808CB2A:
	ldr r0, _0808CB8C @ =0x00001C1E
	bl GetParticleGroup
	str r0, [r6]
	movs r0, #0
	strb r0, [r6, #4]
	strb r0, [r6, #5]
	adds r4, #1
	mov sl, r4
	subs r0, #4
	mov sb, r0
	movs r1, #0
	mov r8, r1
	adds r5, r6, #0
	adds r5, #0x40
	adds r4, r6, #0
	adds r4, #8
	movs r7, #7
_0808CB4E:
	ldr r1, [r6]
	adds r0, r4, #0
	ldr r2, [sp, #4]
	bl Particle_Add
	adds r0, r4, #0
	mov r1, sb
	mov r2, sb
	bl Particle_SetOffset
	mov r0, r8
	strb r0, [r4, #0xf]
	strb r0, [r5]
	adds r5, #0x40
	adds r4, #0x40
	subs r7, #1
	cmp r7, #0
	bge _0808CB4E
	mov r4, sl
	cmp r4, #1
	ble _0808CB10
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808CB88: .4byte 0x00003B8C
_0808CB8C: .4byte 0x00001C1E
