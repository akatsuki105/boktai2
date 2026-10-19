	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r0, _080B4850 @ =0x030046A0
	ldr r1, [r0]
	movs r0, #0xe2
	lsls r0, r0, #1
	adds r1, r1, r0
	ldr r2, _080B4854 @ =0x0000082E
	adds r0, r5, r2
	ldrh r2, [r0]
	ldr r3, _080B4858 @ =0x0000082C
	adds r0, r5, r3
	ldrh r0, [r0]
	muls r2, r0, r2
	ldr r0, [r1]
	adds r4, r0, r2
	cmp r4, #0
	bne _080B485C
	adds r6, r5, #0
	adds r6, #0x38
	movs r1, #0
	add r0, sp, #0xc
_080B4846:
	str r1, [r0]
	subs r0, #4
	cmp r0, sp
	bge _080B4846
	b _080B489C
	.align 2, 0
_080B4850: .4byte 0x030046A0
_080B4854: .4byte 0x0000082E
_080B4858: .4byte 0x0000082C
_080B485C:
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
	adds r6, r5, #0
	adds r6, #0x38
_080B489C:
	mov r7, sp
	movs r0, #0xa6
	lsls r0, r0, #2
	adds r4, r5, r0
	movs r5, #3
_080B48A6:
	ldm r7!, {r2}
	adds r2, #0x14
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	adds r1, r6, #0
	movs r3, #1
	bl MainSprite_SetPose
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _080B48A6
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
