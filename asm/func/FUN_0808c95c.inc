	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	str r2, [sp]
	str r3, [sp, #4]
	lsls r2, r1, #6
	adds r2, r2, r1
	lsls r2, r2, #3
	ldr r1, _0808C9C4 @ =0x00003B8C
	adds r2, r2, r1
	adds r0, r0, r2
	mov sb, r0
	ldr r0, _0808C9C8 @ =0x00001C1C
	bl GetParticleGroup
	mov r2, sb
	str r0, [r2]
	movs r0, #1
	strb r0, [r2, #4]
	movs r3, #0
	mov r8, r3
	mov r6, sb
	adds r6, #0x40
	mov r5, sb
	adds r5, #8
	adds r4, r5, #0
	mov sl, r0
_0808C998:
	ldr r1, [r4]
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r4]
	ldr r7, _0808C9CC @ =0x030046B8
	ldr r0, [r7]
	adds r0, #1
	ldr r2, _0808C9D0 @ =0x000003FF
	ands r0, r2
	str r0, [r7]
	lsls r0, r0, #1
	ldr r3, _0808C9D4 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	mov r7, sl
	ands r0, r7
	cmp r0, #0
	beq _0808C9D8
	movs r0, #4
	orrs r1, r0
	b _0808C9DE
	.align 2, 0
_0808C9C4: .4byte 0x00003B8C
_0808C9C8: .4byte 0x00001C1C
_0808C9CC: .4byte 0x030046B8
_0808C9D0: .4byte 0x000003FF
_0808C9D4: .4byte 0x0203B400
_0808C9D8:
	movs r0, #5
	rsbs r0, r0, #0
	ands r1, r0
_0808C9DE:
	str r1, [r4]
	mov r0, sb
	ldr r1, [r0]
	adds r0, r5, #0
	movs r2, #0x15
	bl Particle_SetFrame
	adds r0, r5, #0
	movs r1, #0
	bl Particle_SetPltt
	ldr r2, _0808CA4C @ =0x030046B8
	ldr r1, [r2]
	adds r1, #1
	ldr r3, _0808CA50 @ =0x000003FF
	ands r1, r3
	lsls r0, r1, #1
	ldr r7, _0808CA54 @ =0x0203B400
	adds r0, r0, r7
	ldrh r2, [r0]
	mov r0, r8
	lsls r3, r0, #5
	asrs r2, r2, #3
	movs r0, #0xf
	ands r2, r0
	adds r3, r3, r2
	adds r2, r3, #0
	subs r2, #8
	adds r1, #1
	ldr r7, _0808CA50 @ =0x000003FF
	ands r1, r7
	ldr r0, _0808CA4C @ =0x030046B8
	str r1, [r0]
	lsls r1, r1, #1
	ldr r7, _0808CA54 @ =0x0203B400
	adds r1, r1, r7
	ldrh r0, [r1]
	asrs r0, r0, #3
	mov r1, sl
	ands r0, r1
	adds r1, r0, #3
	adds r3, #0x38
	movs r0, #0xff
	ands r3, r0
	lsls r3, r3, #1
	ldr r7, _0808CA58 @ =0x085B0A08
	adds r3, r3, r7
	movs r7, #0
	ldrsh r0, [r3, r7]
	muls r0, r1, r0
	cmp r0, #0
	blt _0808CA5C
	asrs r0, r0, #0xc
	b _0808CA62
	.align 2, 0
_0808CA4C: .4byte 0x030046B8
_0808CA50: .4byte 0x000003FF
_0808CA54: .4byte 0x0203B400
_0808CA58: .4byte 0x085B0A08
_0808CA5C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0808CA62:
	strh r0, [r4, #0x30]
	movs r0, #0xff
	ands r2, r0
	lsls r0, r2, #1
	ldr r2, _0808CA7C @ =0x085B0A08
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _0808CA80
	asrs r0, r0, #0xc
	b _0808CA86
	.align 2, 0
_0808CA7C: .4byte 0x085B0A08
_0808CA80:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0808CA86:
	subs r1, r0, #2
	movs r2, #0
	strh r1, [r4, #0x32]
	ldrh r0, [r4, #0x30]
	ldr r7, [sp]
	adds r0, r0, r7
	strh r0, [r4, #0x18]
	ldr r0, [sp, #4]
	adds r1, r1, r0
	strh r1, [r4, #0x1a]
	mov r1, sl
	strb r1, [r6]
	strb r2, [r6, #1]
	ldr r0, _0808CAC8 @ =FUN_0808c770
	str r0, [r4, #0x3c]
	adds r6, #0x40
	adds r4, #0x40
	adds r5, #0x40
	movs r2, #1
	add r8, r2
	mov r3, r8
	cmp r3, #7
	bgt _0808CAB6
	b _0808C998
_0808CAB6:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808CAC8: .4byte FUN_0808c770
