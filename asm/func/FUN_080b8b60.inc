	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	mov sb, r0
	ldr r4, _080B8E40 @ =0x0000CB05
	ldr r1, _080B8E44 @ =0x00005D04
	adds r0, r4, #0
	bl GetFile
	adds r2, r0, #0
	mov r1, sb
	adds r1, #0x38
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5}
	stm r1!, {r3, r5}
	movs r6, #0x38
	add r6, sb
	mov r8, r6
	mov r0, r8
	adds r1, r2, #0
	bl OpenMainSpriteFile
	ldr r1, _080B8E48 @ =0x0000B343
	adds r0, r4, #0
	bl GetFile
	adds r2, r0, #0
	mov r1, sb
	adds r1, #0x18
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5}
	stm r1!, {r3, r5}
	mov r0, sb
	adds r0, #0x18
	adds r1, r2, #0
	bl OpenMainSpriteFile
	ldr r1, _080B8E4C @ =0x0000414C
	adds r0, r4, #0
	bl GetFile
	adds r2, r0, #0
	mov r1, sb
	adds r1, #0x58
	ldm r0!, {r3, r4, r6}
	stm r1!, {r3, r4, r6}
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r4, r5}
	stm r1!, {r4, r5}
	mov r6, sb
	adds r6, #0x58
	adds r0, r6, #0
	adds r1, r2, #0
	bl OpenMainSpriteFile
	ldr r1, _080B8E50 @ =0xFFFF0000
	movs r4, #0
	str r4, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r1
	str r0, [sp, #0x14]
	movs r1, #0
	mov r0, sb
	adds r0, #0x78
	str r1, [sp]
	str r1, [sp, #4]
	movs r5, #0x3c
	str r5, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #0x28
	movs r3, #0x30
	bl MainSprite_Add
	mov r0, sb
	adds r0, #0xd8
	str r4, [sp]
	str r4, [sp, #4]
	str r5, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #0x23
	movs r3, #0x30
	bl MainSprite_Add
	movs r0, #0x9c
	lsls r0, r0, #1
	add r0, sb
	str r4, [sp]
	str r4, [sp, #4]
	str r5, [sp, #8]
	add r3, sp, #0x10
	str r3, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #0x24
	movs r3, #0x30
	bl MainSprite_Add
	movs r6, #0
	add r5, sp, #0x10
	mov sl, r6
	mov r4, r8
	str r4, [sp, #0x18]
	movs r0, #0xf3
	lsls r0, r0, #3
	add r0, sb
	mov r8, r0
	movs r7, #0xcc
	lsls r7, r7, #1
	add r7, sb
	str r4, [sp, #0x1c]
_080B8C56:
	asrs r1, r6, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	strh r0, [r5, #2]
	movs r0, #3
	ands r0, r6
	lsls r4, r0, #1
	adds r4, r4, r0
	lsls r4, r4, #3
	adds r0, r4, #0
	adds r0, #0x90
	strh r0, [r5]
	mov r1, sl
	str r1, [sp]
	str r1, [sp, #4]
	movs r2, #0x3c
	str r2, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r7, #0
	ldr r1, [sp, #0x18]
	movs r2, #0x68
	movs r3, #0x30
	bl MainSprite_Add
	adds r4, #8
	strh r4, [r5]
	mov r3, sl
	str r3, [sp]
	str r3, [sp, #4]
	movs r4, #0x3c
	str r4, [sp, #8]
	str r5, [sp, #0xc]
	mov r0, r8
	ldr r1, [sp, #0x18]
	movs r2, #0x68
	movs r3, #0x30
	bl MainSprite_Add
	movs r0, #0x60
	add r8, r0
	adds r7, #0x60
	adds r6, #1
	cmp r6, #0xf
	ble _080B8C56
	movs r4, #0
	add r0, sp, #0x10
	strh r4, [r0]
	add r1, sp, #0x10
	mov r8, r1
	movs r0, #0x80
	strh r0, [r1, #2]
	ldr r0, _080B8E54 @ =0x00000F18
	add r0, sb
	str r4, [sp]
	str r4, [sp, #4]
	movs r6, #0x3c
	str r6, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	ldr r1, [sp, #0x1c]
	movs r2, #0xcf
	movs r3, #0x30
	bl MainSprite_Add
	movs r1, #0x70
	add r0, sp, #0x10
	strh r1, [r0]
	movs r0, #0x40
	mov r3, r8
	strh r0, [r3, #2]
	ldr r5, _080B8E58 @ =0x00000D98
	add r5, sb
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	add r0, sp, #0x10
	str r0, [sp, #0xc]
	adds r0, r5, #0
	ldr r1, [sp, #0x1c]
	movs r2, #0xca
	movs r3, #0x30
	bl MainSprite_Add
	movs r1, #0xb8
	lsls r1, r1, #2
	adds r0, r5, #0
	bl FUN_080b95bc
	add r0, sp, #0x10
	strh r4, [r0]
	mov r1, r8
	strh r4, [r1, #2]
	ldr r0, _080B8E5C @ =0x00000DF8
	add r0, sb
	mov r1, sb
	adds r1, #0x58
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	movs r2, #0x2a
	movs r3, #0x31
	bl MainSprite_Add
	movs r1, #0x78
	add r0, sp, #0x10
	strh r1, [r0]
	movs r5, #0x68
	mov r3, r8
	strh r5, [r3, #2]
	ldr r0, _080B8E60 @ =0x00000E58
	add r0, sb
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	ldr r1, [sp, #0x1c]
	movs r2, #0xcb
	movs r3, #0x30
	bl MainSprite_Add
	add r0, sp, #0x10
	strh r5, [r0]
	movs r0, #0x20
	mov r2, r8
	strh r0, [r2, #2]
	ldr r0, _080B8E64 @ =0x00000EB8
	add r0, sb
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	add r3, sp, #0x10
	str r3, [sp, #0xc]
	ldr r1, [sp, #0x1c]
	movs r2, #0xcb
	movs r3, #0x30
	bl MainSprite_Add
	movs r1, #0x90
	add r0, sp, #0x10
	strh r1, [r0]
	mov r5, r8
	strh r4, [r5, #2]
	movs r6, #0x18
	add r6, sb
	mov sl, r6
	adds r5, r0, #0
	mov r8, r4
	ldr r4, _080B8E68 @ =0x00000F78
	add r4, sb
	movs r7, #0x20
	movs r6, #3
_080B8D8E:
	strh r7, [r5, #2]
	mov r0, r8
	str r0, [sp]
	str r0, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r4, #0
	mov r1, sl
	movs r2, #0x41
	movs r3, #0x30
	bl MainSprite_Add
	adds r4, #0x60
	adds r7, #0x18
	subs r6, #1
	cmp r6, #0
	bge _080B8D8E
	movs r4, #0
	ldr r0, _080B8E6C @ =0x00001158
	add r0, sb
	str r4, [sp]
	str r4, [sp, #4]
	movs r2, #0x3c
	str r2, [sp, #8]
	add r6, sp, #0x10
	str r6, [sp, #0xc]
	mov r1, sl
	movs r3, #0x31
	bl MainSprite_Add
	movs r1, #0x90
	add r0, sp, #0x10
	strh r1, [r0]
	movs r0, #0x20
	strh r0, [r6, #2]
	ldr r5, _080B8E70 @ =0x000010F8
	add r5, sb
	str r4, [sp]
	str r4, [sp, #4]
	movs r3, #0x3c
	str r3, [sp, #8]
	add r0, sp, #0x10
	str r0, [sp, #0xc]
	adds r0, r5, #0
	mov r1, sl
	movs r2, #0x39
	movs r3, #0x30
	bl MainSprite_Add
	str r4, [sp]
	adds r0, r5, #0
	mov r1, sl
	movs r2, #0
	movs r3, #1
	bl MainSprite_SetAnim
	add r0, sp, #0x10
	strh r4, [r0]
	strh r4, [r6, #2]
	ldr r0, _080B8E74 @ =0x000011B8
	add r0, sb
	str r4, [sp]
	str r4, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	mov r1, sl
	movs r2, #0x94
	movs r3, #0x11
	bl MainSprite_Add
	ldr r0, _080B8E78 @ =0x00001218
	add r0, sb
	bl FUN_080b99a0
	ldr r0, _080B8E7C @ =0x0000130C
	add r0, sb
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
_080B8E40: .4byte 0x0000CB05
_080B8E44: .4byte 0x00005D04
_080B8E48: .4byte 0x0000B343
_080B8E4C: .4byte 0x0000414C
_080B8E50: .4byte 0xFFFF0000
_080B8E54: .4byte 0x00000F18
_080B8E58: .4byte 0x00000D98
_080B8E5C: .4byte 0x00000DF8
_080B8E60: .4byte 0x00000E58
_080B8E64: .4byte 0x00000EB8
_080B8E68: .4byte 0x00000F78
_080B8E6C: .4byte 0x00001158
_080B8E70: .4byte 0x000010F8
_080B8E74: .4byte 0x000011B8
_080B8E78: .4byte 0x00001218
_080B8E7C: .4byte 0x0000130C
