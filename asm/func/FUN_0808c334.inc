	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sl, r0
	adds r6, r1, #0
	mov r8, r2
	mov sb, r3
	ldr r3, [sp, #0x20]
	ldr r2, [sp, #0x24]
	ldr r4, [sp, #0x28]
	lsls r0, r6, #5
	ldr r1, _0808C3A4 @ =0x00003B28
	adds r0, r0, r1
	mov r7, sl
	adds r5, r7, r0
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r5]
	str r1, [r5, #4]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r5, #8]
	str r1, [r5, #0xc]
	cmp r4, #0
	beq _0808C3DA
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r7, #0
	ldrsh r1, [r3, r7]
	subs r0, r0, r1
	movs r7, #2
	ldrsh r1, [r2, r7]
	movs r2, #2
	ldrsh r3, [r3, r2]
	subs r1, r1, r3
	bl ArcTan2_8
	adds r3, r0, #0
	adds r3, #0x40
	movs r1, #0xff
	ands r3, r1
	ldr r2, _0808C3A8 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r7, #0
	ldrsh r0, [r0, r7]
	muls r0, r4, r0
	cmp r0, #0
	blt _0808C3AC
	asrs r0, r0, #0xc
	b _0808C3B2
	.align 2, 0
_0808C3A4: .4byte 0x00003B28
_0808C3A8: .4byte 0x085B0A08
_0808C3AC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0808C3B2:
	strh r0, [r5, #0x10]
	ldr r0, _0808C3CC @ =0x085B0A08
	movs r1, #0xff
	ands r1, r3
	lsls r1, r1, #1
	adds r1, r1, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _0808C3D0
	asrs r0, r0, #0xc
	b _0808C3D6
	.align 2, 0
_0808C3CC: .4byte 0x085B0A08
_0808C3D0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0808C3D6:
	strh r0, [r5, #0x12]
	b _0808C3DE
_0808C3DA:
	strh r4, [r5, #0x10]
	strh r4, [r5, #0x12]
_0808C3DE:
	lsls r4, r6, #1
	adds r4, r4, r6
	lsls r4, r4, #5
	ldr r7, _0808C430 @ =0x000020A4
	adds r4, r4, r7
	add r4, sl
	mov r1, sl
	adds r1, #0xa0
	mov r0, r8
	lsls r2, r0, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	movs r3, #1
	bl MainSprite_SetPose
	adds r0, r4, #0
	mov r1, sb
	bl FUN_0808ba0c
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r4, #0x20]
	str r1, [r4, #0x24]
	ldr r0, [r4, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
	movs r0, #0
	strh r0, [r5, #0x18]
	ldr r0, [sp, #0x2c]
	strh r0, [r5, #0x1a]
	movs r0, #1
	strb r0, [r5, #0x1c]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808C430: .4byte 0x000020A4
