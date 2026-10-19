	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	adds r7, r0, #0
	ldr r1, _080B48FC @ =0x0000082E
	adds r0, r7, r1
	ldrh r4, [r0]
	cmp r4, #0
	bne _080B4900
	adds r2, r7, #0
	adds r2, #0x60
	str r2, [sp, #0x10]
	movs r0, #0x18
	adds r0, r0, r7
	mov sl, r0
	movs r1, #0
	add r0, sp, #0xc
_080B48F0:
	str r1, [r0]
	subs r0, #4
	cmp r0, sp
	bge _080B48F0
	b _080B4948
	.align 2, 0
_080B48FC: .4byte 0x0000082E
_080B4900:
	movs r1, #0xfa
	lsls r1, r1, #2
	adds r0, r4, #0
	bl Div
	str r0, [sp]
	lsls r1, r0, #5
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	subs r4, r4, r1
	adds r0, r4, #0
	movs r1, #0x64
	bl Div
	str r0, [sp, #4]
	movs r1, #0x64
	muls r0, r1, r0
	subs r4, r4, r0
	adds r0, r4, #0
	movs r1, #0xa
	bl Div
	str r0, [sp, #8]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	subs r1, r4, r1
	str r1, [sp, #0xc]
	adds r1, r7, #0
	adds r1, #0x60
	str r1, [sp, #0x10]
	movs r2, #0x18
	adds r2, r2, r7
	mov sl, r2
_080B4948:
	mov sb, sp
	movs r0, #0x83
	lsls r0, r0, #3
	adds r5, r7, r0
	ldr r1, [sp, #0x10]
	movs r2, #0xf0
	lsls r2, r2, #2
	adds r4, r1, r2
	movs r6, #3
_080B495A:
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	mov r8, r1
	ands r0, r1
	str r0, [r4]
	mov r0, sb
	adds r0, #4
	mov sb, r0
	subs r0, #4
	ldm r0!, {r2}
	adds r2, #8
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r5, #0
	mov r1, sl
	movs r3, #1
	bl MainSprite_SetPose
	adds r5, #0x60
	adds r4, #0x60
	subs r6, #1
	cmp r6, #0
	bge _080B495A
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r1, r7, r2
	ldr r0, [r1]
	mov r2, r8
	ands r0, r2
	str r0, [r1]
	ldr r1, _080B49BC @ =0x0000082E
	adds r0, r7, r1
	ldrh r1, [r0]
	ldr r2, _080B49C0 @ =0x0000082C
	adds r0, r7, r2
	ldrh r0, [r0]
	adds r4, r1, #0
	muls r4, r0, r4
	cmp r4, #0
	bne _080B49C4
	movs r1, #0
	add r0, sp, #0xc
_080B49B0:
	str r1, [r0]
	subs r0, #4
	cmp r0, sp
	bge _080B49B0
	b _080B4A00
	.align 2, 0
_080B49BC: .4byte 0x0000082E
_080B49C0: .4byte 0x0000082C
_080B49C4:
	movs r1, #0xfa
	lsls r1, r1, #2
	adds r0, r4, #0
	bl Div
	str r0, [sp]
	lsls r1, r0, #5
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	subs r4, r4, r1
	adds r0, r4, #0
	movs r1, #0x64
	bl Div
	str r0, [sp, #4]
	movs r1, #0x64
	muls r0, r1, r0
	subs r4, r4, r0
	adds r0, r4, #0
	movs r1, #0xa
	bl Div
	str r0, [sp, #8]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	subs r1, r4, r1
	str r1, [sp, #0xc]
_080B4A00:
	mov r8, sp
	movs r0, #0xbf
	lsls r0, r0, #3
	adds r5, r7, r0
	ldr r1, [sp, #0x10]
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r4, r1, r2
	movs r6, #3
_080B4A12:
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	mov r0, r8
	adds r0, #4
	mov r8, r0
	subs r0, #4
	ldm r0!, {r2}
	adds r2, #8
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r5, #0
	mov r1, sl
	movs r3, #1
	bl MainSprite_SetPose
	adds r5, #0x60
	adds r4, #0x60
	subs r6, #1
	cmp r6, #0
	bge _080B4A12
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
