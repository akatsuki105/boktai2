	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r6, r1, #0
	adds r7, r6, #0
	adds r7, #0x5c
	movs r0, #0xd2
	lsls r0, r0, #1
	adds r0, r0, r6
	mov r8, r0
	movs r1, #0xd0
	adds r1, r1, r6
	mov sb, r1
	ldrb r0, [r6, #9]
	cmp r0, #0
	beq _08042DC4
	movs r5, #0
	strb r5, [r6, #9]
	strb r5, [r6, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r6, #0
	movs r1, #3
	movs r2, #1
	movs r3, #0
	bl FUN_08041480
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r1, r6, r2
	movs r0, #1
	strb r0, [r1]
	adds r4, r6, #0
	adds r4, #0x64
	mov r0, r8
	adds r1, r4, #0
	bl Map_InitNavAgent
	movs r3, #0x8f
	lsls r3, r3, #2
	adds r2, r6, r3
	mov r0, r8
	adds r1, r4, #0
	bl FUN_08235f40
	movs r4, #0x89
	lsls r4, r4, #2
	adds r0, r6, r4
	strb r5, [r0]
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_080415cc
_08042DC4:
	movs r0, #0x80
	lsls r0, r0, #5
	ldrh r1, [r6, #0xe]
	orrs r0, r1
	strh r0, [r6, #0xe]
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _08042DE6
	b _08042F22
_08042DE6:
	adds r3, r6, #0
	adds r3, #0x64
	movs r2, #0xd8
	lsls r2, r2, #1
	adds r1, r6, r2
	mov r4, r8
	movs r0, #0xc
	ldrsh r2, [r4, r0]
	movs r4, #8
	ldrsh r0, [r7, r4]
	subs r2, r2, r0
	movs r4, #4
	ldrsh r0, [r1, r4]
	movs r4, #4
	ldrsh r1, [r3, r4]
	subs r0, r0, r1
	adds r1, r2, #0
	muls r1, r2, r1
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	ldr r0, _08042E2C @ =0x00001103
	mov sl, r3
	cmp r1, r0
	bgt _08042E30
	mov r3, r8
	ldrh r0, [r3, #0x1c]
	strh r0, [r7, #8]
	ldrh r0, [r3, #0x20]
	strh r0, [r7, #0xc]
	movs r0, #1
	strb r0, [r6, #7]
	b _08042F02
	.align 2, 0
_08042E2C: .4byte 0x00001103
_08042E30:
	mov r0, sb
	add r1, sp, #4
	bl FUN_08055d48
	cmp r0, #0
	beq _08042F02
	mov r4, sb
	ldr r0, [r4]
	cmp r0, #2
	bne _08042E54
	ldr r0, [sp, #4]
	movs r1, #1
	ands r0, r1
	movs r5, #0x40
	cmp r0, #0
	beq _08042E56
	movs r5, #0x20
	b _08042E56
_08042E54:
	movs r5, #0x10
_08042E56:
	mov r1, r8
	movs r2, #0x1c
	ldrsh r0, [r1, r2]
	movs r3, #8
	ldrsh r1, [r7, r3]
	subs r0, r0, r1
	mov r4, r8
	movs r2, #0x20
	ldrsh r1, [r4, r2]
	mov r3, sl
	movs r4, #4
	ldrsh r2, [r3, r4]
	subs r1, r1, r2
	bl ArcTan2_8
	adds r1, r6, #0
	adds r1, #0x61
	strb r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r0, #0
	adds r1, #0x10
	movs r3, #0xff
	ands r1, r3
	asrs r1, r1, #5
	adds r1, #3
	movs r2, #7
	ands r2, r1
	strb r2, [r6, #0x1a]
	adds r0, #0x20
	ands r0, r3
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	strb r1, [r6, #0x19]
	add r2, sp, #8
	ldrb r4, [r7, #5]
	ldr r1, _08042EC0 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	ands r0, r3
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	adds r3, r2, #0
	cmp r0, #0
	blt _08042EC4
	asrs r1, r0, #0xc
	b _08042ECA
	.align 2, 0
_08042EC0: .4byte 0x085B0A08
_08042EC4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08042ECA:
	movs r0, #0
	strh r1, [r2]
	strh r0, [r2, #2]
	ldr r1, _08042EE4 @ =0x085B0A08
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r4, #0
	ldrsh r0, [r0, r4]
	muls r0, r5, r0
	cmp r0, #0
	blt _08042EE8
	asrs r0, r0, #0xc
	b _08042EEE
	.align 2, 0
_08042EE4: .4byte 0x085B0A08
_08042EE8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08042EEE:
	strh r0, [r2, #4]
	ldrh r0, [r3]
	ldrh r1, [r7, #8]
	adds r0, r0, r1
	strh r0, [r7, #8]
	add r0, sp, #8
	ldrh r0, [r0, #4]
	ldrh r2, [r7, #0xc]
	adds r0, r0, r2
	strh r0, [r7, #0xc]
_08042F02:
	mov r0, r8
	mov r1, sl
	bl Map_StepNavPath
	adds r0, r6, #0
	movs r1, #3
	bl FUN_080414fc
	movs r0, #1
	str r0, [sp]
	adds r0, r6, #0
	movs r1, #3
	movs r2, #1
	movs r3, #0
	bl FUN_08041480
_08042F22:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
