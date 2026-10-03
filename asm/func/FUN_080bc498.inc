	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r7, r0, #0
	ldr r4, _080BC598 @ =0x0000CB05
	ldr r1, _080BC59C @ =0x00005D04
	adds r0, r4, #0
	bl GetFile
	adds r2, r0, #0
	adds r1, r7, #0
	adds r1, #0x38
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5}
	stm r1!, {r3, r5}
	adds r0, r7, #0
	adds r0, #0x38
	adds r1, r2, #0
	bl OpenMainSpriteFile
	ldr r1, _080BC5A0 @ =0x0000B343
	adds r0, r4, #0
	bl GetFile
	adds r2, r0, #0
	adds r1, r7, #0
	adds r1, #0x18
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r6}
	stm r1!, {r3, r6}
	adds r0, r7, #0
	adds r0, #0x18
	adds r1, r2, #0
	bl OpenMainSpriteFile
	ldr r1, _080BC5A4 @ =0x0000414C
	adds r0, r4, #0
	bl GetFile
	adds r2, r0, #0
	adds r1, r7, #0
	adds r1, #0x58
	ldm r0!, {r4, r5, r6}
	stm r1!, {r4, r5, r6}
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r6}
	stm r1!, {r3, r6}
	adds r5, r7, #0
	adds r5, #0x58
	adds r0, r5, #0
	adds r1, r2, #0
	bl OpenMainSpriteFile
	ldr r1, _080BC5A8 @ =0xFFFF0000
	movs r6, #0
	str r6, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r1
	str r0, [sp, #0x14]
	movs r1, #0
	ldr r4, _080BC5AC @ =0x000012EC
	adds r0, r7, r4
	ldrb r0, [r0]
	cmp r0, #1
	bne _080BC5B4
	ldr r0, _080BC5B0 @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0x94
	lsls r2, r2, #2
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r4, #0x31
	mov r8, r4
	cmp r0, #5
	beq _080BC548
	movs r0, #0x30
	mov r8, r0
_080BC548:
	adds r0, r7, #0
	adds r0, #0x78
	str r1, [sp]
	str r1, [sp, #4]
	movs r4, #0x3c
	str r4, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	adds r1, r5, #0
	movs r2, #0x25
	movs r3, #0x30
	bl MainSprite_Add
	adds r0, r7, #0
	adds r0, #0xd8
	str r6, [sp]
	str r6, [sp, #4]
	str r4, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	adds r1, r5, #0
	movs r2, #0x23
	mov r3, r8
	bl MainSprite_Add
	movs r3, #0x9c
	lsls r3, r3, #1
	adds r0, r7, r3
	str r6, [sp]
	str r6, [sp, #4]
	str r4, [sp, #8]
	add r4, sp, #0x10
	str r4, [sp, #0xc]
	adds r1, r5, #0
	movs r2, #0x24
	mov r3, r8
	bl MainSprite_Add
	b _080BC600
	.align 2, 0
_080BC598: .4byte 0x0000CB05
_080BC59C: .4byte 0x00005D04
_080BC5A0: .4byte 0x0000B343
_080BC5A4: .4byte 0x0000414C
_080BC5A8: .4byte 0xFFFF0000
_080BC5AC: .4byte 0x000012EC
_080BC5B0: .4byte 0x030046A0
_080BC5B4:
	adds r0, r7, #0
	adds r0, #0x78
	str r1, [sp]
	str r1, [sp, #4]
	movs r4, #0x3c
	str r4, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	adds r1, r5, #0
	movs r2, #0x26
	movs r3, #0x30
	bl MainSprite_Add
	adds r0, r7, #0
	adds r0, #0xd8
	str r6, [sp]
	str r6, [sp, #4]
	str r4, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	adds r1, r5, #0
	movs r2, #0x23
	movs r3, #0x31
	bl MainSprite_Add
	movs r3, #0x9c
	lsls r3, r3, #1
	adds r0, r7, r3
	str r6, [sp]
	str r6, [sp, #4]
	str r4, [sp, #8]
	add r4, sp, #0x10
	str r4, [sp, #0xc]
	adds r1, r5, #0
	movs r2, #0x24
	movs r3, #0x31
	bl MainSprite_Add
_080BC600:
	movs r4, #0
	movs r5, #0x38
	adds r5, r5, r7
	mov sb, r5
	adds r6, r7, #0
	adds r6, #0x18
	str r6, [sp, #0x18]
	adds r0, r7, #0
	adds r0, #0x58
	str r0, [sp, #0x1c]
	add r6, sp, #0x10
	mov r8, r4
	movs r1, #0xcc
	lsls r1, r1, #1
	adds r5, r7, r1
_080BC61E:
	asrs r1, r4, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	strh r0, [r6, #2]
	movs r1, #3
	ands r1, r4
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x90
	strh r0, [r6]
	mov r2, r8
	str r2, [sp]
	str r2, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	adds r0, r5, #0
	mov r1, sb
	movs r2, #0x68
	movs r3, #0x30
	bl MainSprite_Add
	adds r5, #0x60
	adds r4, #1
	cmp r4, #0xf
	ble _080BC61E
	movs r4, #0
	add r6, sp, #0x10
	mov r8, r4
	movs r3, #0xf3
	lsls r3, r3, #3
	adds r5, r7, r3
_080BC664:
	asrs r1, r4, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	strh r0, [r6, #2]
	movs r1, #3
	ands r1, r4
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #8
	strh r0, [r6]
	mov r0, r8
	str r0, [sp]
	str r0, [sp, #4]
	movs r1, #0x3c
	mov sl, r1
	str r1, [sp, #8]
	str r6, [sp, #0xc]
	adds r0, r5, #0
	mov r1, sb
	movs r2, #0x68
	movs r3, #0x30
	bl MainSprite_Add
	adds r5, #0x60
	adds r4, #1
	cmp r4, #0xb
	ble _080BC664
	ldr r2, _080BC894 @ =0x00000D38
	adds r0, r7, r2
	movs r4, #0
	str r4, [sp]
	str r4, [sp, #4]
	mov r3, sl
	str r3, [sp, #8]
	add r6, sp, #0x10
	str r6, [sp, #0xc]
	ldr r1, [sp, #0x18]
	movs r2, #0x41
	movs r3, #0x30
	bl MainSprite_Add
	add r0, sp, #0x10
	strh r4, [r0]
	movs r0, #0x80
	strh r0, [r6, #2]
	ldr r5, _080BC898 @ =0x00000CD8
	adds r0, r7, r5
	str r4, [sp]
	str r4, [sp, #4]
	mov r1, sl
	str r1, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	mov r1, sb
	movs r2, #0xd0
	movs r3, #0x30
	bl MainSprite_Add
	movs r1, #0x78
	add r0, sp, #0x10
	strh r1, [r0]
	movs r5, #0x68
	strh r5, [r6, #2]
	ldr r3, _080BC89C @ =0x00000C78
	adds r0, r7, r3
	str r4, [sp]
	str r4, [sp, #4]
	mov r1, sl
	str r1, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	mov r1, sb
	movs r2, #0xcb
	movs r3, #0x30
	bl MainSprite_Add
	add r0, sp, #0x10
	strh r5, [r0]
	movs r3, #0x20
	mov r8, r3
	mov r5, r8
	strh r5, [r6, #2]
	ldr r0, _080BC8A0 @ =0x00000C18
	adds r5, r7, r0
	str r4, [sp]
	str r4, [sp, #4]
	mov r1, sl
	str r1, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	adds r0, r5, #0
	mov r1, sb
	movs r2, #0xcc
	movs r3, #0x30
	bl MainSprite_Add
	movs r1, #0xb8
	lsls r1, r1, #2
	adds r0, r5, #0
	bl FUN_080b95bc
	ldr r3, _080BC8A4 @ =0x00000DF8
	adds r0, r7, r3
	str r4, [sp]
	str r4, [sp, #4]
	mov r5, sl
	str r5, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	ldr r1, [sp, #0x18]
	movs r2, #0x3c
	movs r3, #0x31
	bl MainSprite_Add
	movs r1, #0x90
	add r0, sp, #0x10
	strh r1, [r0]
	mov r2, r8
	strh r2, [r6, #2]
	ldr r3, _080BC8A8 @ =0x00000D98
	adds r5, r7, r3
	str r4, [sp]
	str r4, [sp, #4]
	mov r6, sl
	str r6, [sp, #8]
	str r0, [sp, #0xc]
	adds r0, r5, #0
	ldr r1, [sp, #0x18]
	movs r2, #0x39
	movs r3, #0x30
	bl MainSprite_Add
	str r4, [sp]
	adds r0, r5, #0
	ldr r1, [sp, #0x18]
	movs r2, #0
	movs r3, #1
	bl MainSprite_SetAnim
	ldr r1, _080BC8AC @ =0x00000E58
	adds r0, r7, r1
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	ldr r1, [sp, #0x1c]
	movs r2, #0x18
	movs r3, #0x30
	bl MainSprite_Add
	add r0, sp, #0x10
	ldrh r0, [r0]
	subs r0, #0xb
	add r1, sp, #0x10
	strh r0, [r1]
	adds r6, r1, #0
	ldr r3, _080BC8B0 @ =0x00000EB8
	adds r5, r7, r3
	mov r8, r4
	movs r4, #3
_080BC7AC:
	mov r0, r8
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	adds r0, r5, #0
	ldr r1, [sp, #0x1c]
	movs r2, #0x19
	movs r3, #0x30
	bl MainSprite_Add
	ldrh r0, [r6]
	adds r0, #6
	strh r0, [r6]
	adds r5, #0x60
	subs r4, #1
	cmp r4, #0
	bge _080BC7AC
	movs r1, #0x30
	add r0, sp, #0x10
	strh r1, [r0]
	adds r1, r0, #0
	movs r0, #0x68
	strh r0, [r1, #2]
	adds r6, r1, #0
	ldr r1, _080BC8B4 @ =0x00001038
	adds r5, r7, r1
	movs r2, #0
	mov r8, r2
	movs r4, #2
_080BC7EA:
	mov r3, r8
	str r3, [sp]
	str r3, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	adds r0, r5, #0
	ldr r1, [sp, #0x18]
	movs r2, #0
	movs r3, #0x30
	bl MainSprite_Add
	ldrh r0, [r6]
	adds r0, #8
	strh r0, [r6]
	adds r5, #0x60
	subs r4, #1
	cmp r4, #0
	bge _080BC7EA
	movs r1, #0x30
	add r0, sp, #0x10
	strh r1, [r0]
	adds r1, r0, #0
	movs r0, #0x70
	strh r0, [r1, #2]
	adds r6, r1, #0
	ldr r4, _080BC8B8 @ =0x00001158
	adds r5, r7, r4
	movs r0, #0
	mov r8, r0
	movs r4, #2
_080BC828:
	mov r1, r8
	str r1, [sp]
	str r1, [sp, #4]
	movs r2, #0x3c
	mov sb, r2
	str r2, [sp, #8]
	str r6, [sp, #0xc]
	adds r0, r5, #0
	ldr r1, [sp, #0x18]
	movs r2, #0
	movs r3, #0x30
	bl MainSprite_Add
	ldrh r0, [r6]
	adds r0, #8
	strh r0, [r6]
	adds r5, #0x60
	subs r4, #1
	cmp r4, #0
	bge _080BC828
	movs r1, #0
	add r0, sp, #0x10
	strh r1, [r0]
	strh r1, [r0, #2]
	ldr r3, _080BC8BC @ =0x00001278
	adds r0, r7, r3
	str r1, [sp]
	str r1, [sp, #4]
	mov r4, sb
	str r4, [sp, #8]
	add r5, sp, #0x10
	str r5, [sp, #0xc]
	ldr r1, [sp, #0x18]
	movs r2, #0x94
	movs r3, #0x11
	bl MainSprite_Add
	ldr r6, _080BC8C0 @ =0x00001314
	adds r0, r7, r6
	bl FUN_080b99a0
	ldr r1, _080BC8C4 @ =0x00001438
	adds r0, r7, r1
	bl FUN_080b9814
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BC894: .4byte 0x00000D38
_080BC898: .4byte 0x00000CD8
_080BC89C: .4byte 0x00000C78
_080BC8A0: .4byte 0x00000C18
_080BC8A4: .4byte 0x00000DF8
_080BC8A8: .4byte 0x00000D98
_080BC8AC: .4byte 0x00000E58
_080BC8B0: .4byte 0x00000EB8
_080BC8B4: .4byte 0x00001038
_080BC8B8: .4byte 0x00001158
_080BC8BC: .4byte 0x00001278
_080BC8C0: .4byte 0x00001314
_080BC8C4: .4byte 0x00001438
