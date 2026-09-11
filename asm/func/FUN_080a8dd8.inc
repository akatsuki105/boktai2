	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	ldr r6, _080A8EBC @ =0x0203B400
	ldr r4, _080A8EC0 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r5, _080A8EC4 @ =0x000003FF
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrb r0, [r0]
	str r0, [sp]
	ldr r0, _080A8EC8 @ =0x00001C1E
	bl GetParticleGroup
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r1, r7, r2
	str r0, [r1]
	movs r0, #0
	mov r8, r0
	adds r1, r2, #0
	adds r1, r1, r7
	mov sb, r1
	mov sl, r5
	ldr r6, _080A8ECC @ =0x085B0A08
_080A8E18:
	movs r0, #0x2c
	mov r4, r8
	muls r4, r0, r4
	adds r0, r4, #0
	adds r0, #0x6c
	adds r5, r7, r0
	mov r2, sb
	ldr r1, [r2]
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0822d9f0
	movs r2, #4
	rsbs r2, r2, #0
	adds r0, r5, #0
	adds r1, r2, #0
	bl FUN_0822dad4
	mov r0, sb
	ldr r1, [r0]
	adds r0, r5, #0
	movs r2, #7
	bl FUN_0822dafc
	adds r0, r5, #0
	movs r1, #1
	bl FUN_0822dadc
	ldr r1, _080A8EC0 @ =0x030046B8
	ldr r2, [r1]
	adds r2, #1
	mov r0, sl
	ands r2, r0
	lsls r0, r2, #1
	ldr r1, _080A8EBC @ =0x0203B400
	adds r0, r0, r1
	ldrh r3, [r0]
	adds r4, r7, r4
	mov r1, r8
	lsls r0, r1, #5
	ldr r1, [sp]
	adds r0, r1, r0
	movs r1, #0xf
	ands r3, r1
	adds r0, r0, r3
	movs r1, #0xff
	ands r0, r1
	adds r3, r4, #0
	adds r3, #0x94
	strh r0, [r3]
	adds r2, #1
	mov r0, sl
	ands r2, r0
	ldr r1, _080A8EC0 @ =0x030046B8
	str r2, [r1]
	lsls r2, r2, #1
	ldr r0, _080A8EBC @ =0x0203B400
	adds r2, r2, r0
	ldrh r1, [r2]
	ldr r2, _080A8ED0 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r1, r0
	adds r4, #0x96
	strh r1, [r4]
	ldrh r2, [r4]
	ldrh r0, [r3]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _080A8ED4
	asrs r2, r0, #0xc
	b _080A8EDA
	.align 2, 0
_080A8EBC: .4byte 0x0203B400
_080A8EC0: .4byte 0x030046B8
_080A8EC4: .4byte 0x000003FF
_080A8EC8: .4byte 0x00001C1E
_080A8ECC: .4byte 0x085B0A08
_080A8ED0: .4byte 0x000001FF
_080A8ED4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080A8EDA:
	adds r0, r7, #0
	adds r0, #0x64
	ldrh r0, [r0]
	adds r0, r0, r2
	strh r0, [r5, #0x18]
	adds r1, r7, #0
	adds r1, #0x66
	movs r2, #0x96
	lsls r2, r2, #1
	adds r0, r2, #0
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r5, #0x1a]
	movs r0, #0x2c
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	adds r0, r7, r0
	adds r1, r0, #0
	adds r1, #0x96
	ldrh r1, [r1]
	adds r0, #0x94
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _080A8F1A
	asrs r1, r0, #0xc
	b _080A8F20
_080A8F1A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080A8F20:
	adds r0, r7, #0
	adds r0, #0x68
	ldrh r0, [r0]
	adds r0, r0, r1
	strh r0, [r5, #0x1c]
	movs r0, #2
	strb r0, [r5, #0xf]
	movs r0, #0xec
	strb r0, [r5, #0x10]
	movs r0, #1
	add r8, r0
	mov r1, r8
	cmp r1, #7
	bgt _080A8F3E
	b _080A8E18
_080A8F3E:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
