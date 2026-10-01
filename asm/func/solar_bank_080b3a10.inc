	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	mov r8, r0
	ldr r0, _080B3A38 @ =0x000005D4
	add r0, r8
	ldr r4, [r0]
	cmp r4, #0
	bne _080B3A3C
	mov r7, r8
	adds r7, #0x38
	movs r1, #0
	add r0, sp, #0xc
_080B3A2C:
	str r1, [r0]
	subs r0, #4
	cmp r0, sp
	bge _080B3A2C
	b _080B3A7C
	.align 2, 0
_080B3A38: .4byte 0x000005D4
_080B3A3C:
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
	mov r7, r8
	adds r7, #0x38
_080B3A7C:
	mov r6, sp
	movs r4, #0xee
	lsls r4, r4, #2
	add r4, r8
	movs r5, #3
_080B3A86:
	ldm r6!, {r2}
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	adds r1, r7, #0
	movs r3, #1
	bl MainSprite_SetPose
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _080B3A86
	movs r0, #0xbb
	lsls r0, r0, #3
	add r0, r8
	ldr r4, [r0]
	cmp r4, #0
	bne _080B3AB8
	movs r1, #0
	add r0, sp, #0xc
_080B3AAE:
	str r1, [r0]
	subs r0, #4
	cmp r0, sp
	bge _080B3AAE
	b _080B3AF4
_080B3AB8:
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
_080B3AF4:
	mov r6, sp
	movs r4, #0x8e
	lsls r4, r4, #2
	add r4, r8
	movs r5, #3
_080B3AFE:
	ldm r6!, {r2}
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	adds r1, r7, #0
	movs r3, #1
	bl MainSprite_SetPose
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _080B3AFE
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
