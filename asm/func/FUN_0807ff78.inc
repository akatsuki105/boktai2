	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	ldr r6, _08080064 @ =0x0203B400
	ldr r4, _08080068 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r5, _0808006C @ =0x000003FF
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrb r0, [r0]
	str r0, [sp, #4]
	ldr r0, _08080070 @ =0x00001C1E
	bl GetParticleGroup
	adds r1, r7, #0
	adds r1, #0xf4
	str r0, [r1]
	movs r0, #0
	str r0, [sp]
	mov sb, r1
	mov sl, r6
	mov r8, r4
	adds r6, r5, #0
	movs r1, #0
	str r1, [sp, #8]
	movs r2, #0x84
	lsls r2, r2, #1
	adds r4, r7, r2
	adds r5, r7, #0
	adds r5, #0xf8
_0807FFC2:
	mov r3, sb
	ldr r1, [r3]
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0822d9f0
	movs r2, #4
	rsbs r2, r2, #0
	adds r0, r5, #0
	adds r1, r2, #0
	bl FUN_0822dad4
	adds r0, r5, #0
	movs r1, #1
	bl FUN_0822dadc
	mov r0, r8
	ldr r2, [r0]
	adds r2, #1
	ands r2, r6
	lsls r0, r2, #1
	add r0, sl
	ldrh r1, [r0]
	ldr r3, [sp, #4]
	ldr r0, [sp, #8]
	adds r3, r3, r0
	movs r0, #7
	ands r1, r0
	adds r3, r3, r1
	strb r3, [r4, #0x19]
	adds r2, #1
	ands r2, r6
	lsls r0, r2, #1
	add r0, sl
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	adds r0, #7
	strb r0, [r4, #0x1d]
	adds r2, #1
	ands r2, r6
	lsls r0, r2, #1
	add r0, sl
	ldrh r0, [r0]
	asrs r0, r0, #3
	movs r1, #0x5f
	ands r0, r1
	adds r0, #0x60
	strh r0, [r4, #0x20]
	ldr r0, [sp]
	movs r3, #3
	ands r0, r3
	lsls r0, r0, #1
	adds r0, #1
	strb r0, [r4, #0x1a]
	adds r2, #1
	ands r2, r6
	mov r0, r8
	str r2, [r0]
	lsls r2, r2, #1
	add r2, sl
	ldrh r0, [r2]
	movs r1, #0x1f
	ands r0, r1
	adds r0, #8
	strb r0, [r4, #0x1b]
	ldrh r2, [r4, #0x20]
	ldrb r0, [r4, #0x19]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	ldr r1, _08080074 @ =0x085B0A08
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r2, r0
	cmp r0, #0
	blt _08080078
	asrs r2, r0, #0xc
	b _0808007E
	.align 2, 0
_08080064: .4byte 0x0203B400
_08080068: .4byte 0x030046B8
_0808006C: .4byte 0x000003FF
_08080070: .4byte 0x00001C1E
_08080074: .4byte 0x085B0A08
_08080078:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0808007E:
	ldr r0, [r7, #0x18]
	ldrh r0, [r0, #0x2c]
	adds r0, r0, r2
	strh r0, [r4, #8]
	ldr r0, [r7, #0x18]
	ldrh r0, [r0, #0x2e]
	strh r0, [r4, #0xa]
	ldrh r1, [r4, #0x20]
	ldrb r0, [r4, #0x19]
	lsls r0, r0, #1
	ldr r2, _080800A4 @ =0x085B0A08
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _080800A8
	asrs r1, r0, #0xc
	b _080800AE
	.align 2, 0
_080800A4: .4byte 0x085B0A08
_080800A8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080800AE:
	ldr r0, [r7, #0x18]
	ldrh r0, [r0, #0x30]
	adds r0, r0, r1
	strh r0, [r4, #0xc]
	movs r0, #2
	strb r0, [r5, #0xf]
	movs r0, #0xec
	strb r0, [r4]
	mov r1, r8
	ldr r0, [r1]
	adds r0, #1
	ands r0, r6
	str r0, [r1]
	lsls r0, r0, #1
	ldr r2, _080800E8 @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r0, #7
	ands r1, r0
	strb r1, [r4, #0x1c]
	cmp r1, #3
	bhi _080800EC
	mov r3, sb
	ldr r1, [r3]
	adds r0, r5, #0
	movs r2, #4
	bl FUN_0822dafc
	b _080800F8
	.align 2, 0
_080800E8: .4byte 0x0203B400
_080800EC:
	mov r0, sb
	ldr r1, [r0]
	adds r0, r5, #0
	movs r2, #5
	bl FUN_0822dafc
_080800F8:
	movs r0, #0
	strb r0, [r4, #0x1c]
	strb r0, [r4, #0x1f]
	mov r1, r8
	ldr r0, [r1]
	adds r0, #1
	ands r0, r6
	str r0, [r1]
	lsls r0, r0, #1
	ldr r2, _08080144 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	adds r0, #0x38
	strb r0, [r4, #0x1e]
	movs r0, #1
	strb r0, [r4, #0x18]
	ldr r3, [sp, #8]
	adds r3, #0x10
	str r3, [sp, #8]
	adds r4, #0x3c
	adds r5, #0x3c
	ldr r0, [sp]
	adds r0, #1
	str r0, [sp]
	cmp r0, #0xf
	bgt _08080132
	b _0807FFC2
_08080132:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08080144: .4byte 0x0203B400
