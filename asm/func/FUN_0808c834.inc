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
	ldr r1, _0808C8F0 @ =0x00003B8C
	adds r2, r2, r1
	adds r0, r0, r2
	mov r8, r0
	ldr r0, _0808C8F4 @ =0x00001C1E
	bl GetParticleGroup
	mov r2, r8
	str r0, [r2]
	movs r0, #1
	strb r0, [r2, #4]
	movs r7, #0
	ldr r3, _0808C8F8 @ =0x000003FF
	mov sl, r3
	mov r6, r8
	adds r6, #0x40
	mov r5, r8
	adds r5, #8
	adds r4, r5, #0
	ldr r0, _0808C8FC @ =0x085B0A08
	mov sb, r0
_0808C874:
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	mov r1, sp
	ldrh r1, [r1]
	strh r1, [r4, #0x18]
	mov r2, sp
	ldrh r2, [r2, #4]
	strh r2, [r4, #0x1a]
	mov r3, r8
	ldr r1, [r3]
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0822dafc
	adds r0, r5, #0
	movs r1, #1
	bl FUN_0822dadc
	ldr r0, _0808C900 @ =0x030046B8
	ldr r1, [r0]
	adds r1, #1
	mov r2, sl
	ands r1, r2
	lsls r0, r1, #1
	ldr r3, _0808C904 @ =0x0203B400
	adds r0, r0, r3
	ldrh r2, [r0]
	lsls r3, r7, #5
	asrs r2, r2, #3
	movs r0, #0xf
	ands r2, r0
	adds r3, r3, r2
	adds r2, r3, #0
	subs r2, #8
	adds r1, #1
	mov r0, sl
	ands r1, r0
	ldr r0, _0808C900 @ =0x030046B8
	str r1, [r0]
	lsls r1, r1, #1
	ldr r0, _0808C904 @ =0x0203B400
	adds r1, r1, r0
	ldrh r0, [r1]
	asrs r0, r0, #3
	movs r1, #3
	ands r0, r1
	adds r1, r0, #4
	adds r3, #0x38
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	add r0, sb
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _0808C908
	asrs r0, r0, #0xc
	b _0808C90E
	.align 2, 0
_0808C8F0: .4byte 0x00003B8C
_0808C8F4: .4byte 0x00001C1E
_0808C8F8: .4byte 0x000003FF
_0808C8FC: .4byte 0x085B0A08
_0808C900: .4byte 0x030046B8
_0808C904: .4byte 0x0203B400
_0808C908:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0808C90E:
	strh r0, [r4, #0x30]
	movs r0, #0xff
	ands r2, r0
	lsls r0, r2, #1
	add r0, sb
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _0808C926
	asrs r3, r0, #0xc
	b _0808C92C
_0808C926:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_0808C92C:
	movs r0, #0
	strh r3, [r4, #0x32]
	movs r1, #1
	strb r1, [r6]
	strb r0, [r6, #1]
	ldr r0, _0808C958 @ =FUN_0808c710
	str r0, [r4, #0x3c]
	adds r6, #0x40
	adds r4, #0x40
	adds r5, #0x40
	adds r7, #1
	cmp r7, #7
	ble _0808C874
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808C958: .4byte FUN_0808c710
