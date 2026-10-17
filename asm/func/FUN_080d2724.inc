	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r6, r0, #0
	ldr r0, _080D2758 @ =0x000009C8
	adds r5, r6, r0
	ldr r1, _080D275C @ =0x00000A8A
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _080D276C
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _080D2764
	ldr r0, [r6, #0x18]
	ldr r1, _080D2760 @ =0x0000038F
	bl Sound_PlayForPlayer
	b _080D276C
	.align 2, 0
_080D2758: .4byte 0x000009C8
_080D275C: .4byte 0x00000A8A
_080D2760: .4byte 0x0000038F
_080D2764:
	ldr r0, [r6, #0x18]
	ldr r1, _080D27B0 @ =0x0000038D
	bl Sound_PlayForPlayer
_080D276C:
	adds r0, r5, #0
	adds r0, #0xc2
	adds r1, r5, #0
	adds r1, #0xbc
	ldrh r2, [r0]
	mov sb, r0
	mov sl, r1
	ldrh r3, [r1]
	cmp r2, r3
	bhs _080D284A
	subs r0, #0xa
	ldrh r1, [r0]
	mov r2, sb
	ldrh r0, [r2]
	muls r0, r1, r0
	adds r4, r0, #0
	adds r4, #0xcc
	ldr r2, _080D27B4 @ =gSineTable
	adds r3, r5, #0
	adds r3, #0xc4
	ldrb r0, [r3]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	mov r8, r3
	cmp r0, #0
	blt _080D27B8
	asrs r1, r0, #0xc
	b _080D27BE
	.align 2, 0
_080D27B0: .4byte 0x0000038D
_080D27B4: .4byte gSineTable
_080D27B8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080D27BE:
	adds r0, r5, #0
	adds r0, #0xa0
	ldrh r0, [r0]
	adds r0, r0, r1
	adds r1, r5, #0
	adds r1, #0x98
	strh r0, [r1]
	adds r0, r5, #0
	adds r0, #0xa2
	ldrh r0, [r0]
	adds r3, r5, #0
	adds r3, #0x9a
	strh r0, [r3]
	mov r3, r8
	ldrb r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	adds r7, r1, #0
	cmp r0, #0
	blt _080D27F0
	asrs r2, r0, #0xc
	b _080D27F6
_080D27F0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080D27F6:
	adds r0, r5, #0
	adds r0, #0xa4
	ldrh r0, [r0]
	adds r0, r0, r2
	adds r1, r5, #0
	adds r1, #0x9c
	strh r0, [r1]
	adds r4, r5, #0
	adds r4, #0x48
	adds r0, r4, #0
	adds r1, r7, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	bl Hitbox_Register
	adds r3, r5, #0
	adds r3, #0xc5
	movs r0, #0
	ldrsb r0, [r3, r0]
	adds r1, r5, #0
	adds r1, #0xbe
	str r1, [sp]
	cmp r0, #0
	bge _080D282C
	b _080D2928
_080D282C:
	movs r1, #0x80
	lsls r1, r1, #0xc
	ldr r0, [r6, #0x20]
	orrs r0, r1
	str r0, [r6, #0x20]
	mov r0, r8
	ldrb r2, [r0]
	ldrb r3, [r3]
	lsls r3, r3, #0x18
	asrs r3, r3, #0x18
	adds r0, r6, #0
	adds r1, r7, #0
	bl FUN_080d25f8
	b _080D2928
_080D284A:
	mov r1, sb
	ldrh r2, [r1]
	mov r0, sl
	ldrh r3, [r0]
	adds r1, r5, #0
	adds r1, #0xbe
	ldrh r0, [r1]
	adds r0, r3, r0
	str r1, [sp]
	cmp r2, r0
	bge _080D2928
	adds r0, r5, #0
	adds r0, #0xb8
	ldrh r0, [r0]
	muls r0, r3, r0
	adds r4, r0, #0
	adds r4, #0xcc
	ldr r2, _080D2890 @ =gSineTable
	adds r3, r5, #0
	adds r3, #0xc4
	ldrb r0, [r3]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	mov r8, r3
	cmp r0, #0
	blt _080D2894
	asrs r1, r0, #0xc
	b _080D289A
	.align 2, 0
_080D2890: .4byte gSineTable
_080D2894:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080D289A:
	adds r0, r5, #0
	adds r0, #0xa0
	ldrh r0, [r0]
	adds r0, r0, r1
	adds r1, r5, #0
	adds r1, #0x98
	strh r0, [r1]
	adds r0, r5, #0
	adds r0, #0xa2
	ldrh r0, [r0]
	adds r3, r5, #0
	adds r3, #0x9a
	strh r0, [r3]
	mov r3, r8
	ldrb r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	adds r7, r1, #0
	cmp r0, #0
	blt _080D28CC
	asrs r2, r0, #0xc
	b _080D28D2
_080D28CC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080D28D2:
	adds r0, r5, #0
	adds r0, #0xa4
	ldrh r0, [r0]
	adds r0, r0, r2
	adds r1, r5, #0
	adds r1, #0x9c
	strh r0, [r1]
	adds r4, r5, #0
	adds r4, #0x48
	adds r0, r4, #0
	adds r1, r7, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	bl Hitbox_Register
	adds r3, r5, #0
	adds r3, #0xc5
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #0
	blt _080D2928
	movs r1, #0x80
	lsls r1, r1, #0xc
	ldr r0, [r6, #0x20]
	orrs r0, r1
	str r0, [r6, #0x20]
	mov r0, sb
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080D2928
	mov r1, r8
	ldrb r2, [r1]
	ldrb r3, [r3]
	lsls r3, r3, #0x18
	asrs r3, r3, #0x18
	adds r0, r6, #0
	adds r1, r7, #0
	bl FUN_080d25f8
_080D2928:
	mov r2, sb
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r3, sl
	ldrh r1, [r3]
	ldr r3, [sp]
	ldrh r2, [r3]
	adds r3, r5, #0
	adds r3, #0xc0
	adds r1, r1, r2
	ldrh r3, [r3]
	adds r1, r1, r3
	cmp r0, r1
	bge _080D294E
	movs r0, #0
	b _080D2956
_080D294E:
	movs r0, #0
	mov r1, sb
	strh r0, [r1]
	movs r0, #1
_080D2956:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
