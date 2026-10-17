	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r7, r0, #0
	ldr r4, _080BF6E4 @ =0x0000CB05
	ldr r1, _080BF6E8 @ =0x00005D04
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
	movs r6, #0x38
	adds r6, r6, r7
	mov sb, r6
	mov r0, sb
	adds r1, r2, #0
	bl OpenMainSpriteFile
	ldr r1, _080BF6EC @ =0x0000B343
	adds r0, r4, #0
	bl GetFile
	adds r2, r0, #0
	adds r1, r7, #0
	adds r1, #0x18
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5}
	stm r1!, {r3, r5}
	adds r0, r7, #0
	adds r0, #0x18
	adds r1, r2, #0
	bl OpenMainSpriteFile
	ldr r1, _080BF6F0 @ =0x0000414C
	adds r0, r4, #0
	bl GetFile
	adds r2, r0, #0
	adds r1, r7, #0
	adds r1, #0x58
	ldm r0!, {r3, r4, r6}
	stm r1!, {r3, r4, r6}
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r4, r5}
	stm r1!, {r4, r5}
	adds r4, r7, #0
	adds r4, #0x58
	adds r0, r4, #0
	adds r1, r2, #0
	bl OpenMainSpriteFile
	ldr r1, _080BF6F4 @ =0xFFFF0000
	movs r0, #0
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r1
	str r0, [sp, #0x14]
	movs r1, #0
	adds r0, r7, #0
	adds r0, #0x78
	str r1, [sp]
	str r1, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	add r6, sp, #0x10
	str r6, [sp, #0xc]
	adds r1, r4, #0
	movs r2, #0x29
	movs r3, #0x30
	bl MainSprite_Add
	movs r4, #0
	add r6, sp, #0x10
	mov r8, r4
	mov sl, sb
	adds r5, r7, #0
	adds r5, #0xd8
_080BF54A:
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
	mov r0, r8
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	adds r0, r5, #0
	adds r1, r7, #0
	adds r1, #0x38
	movs r2, #0x68
	movs r3, #0x30
	bl MainSprite_Add
	adds r5, #0x60
	adds r4, #1
	cmp r4, #0xf
	ble _080BF54A
	movs r4, #0
	adds r1, r7, #0
	adds r1, #0x18
	str r1, [sp, #0x1c]
	adds r2, r7, #0
	adds r2, #0x58
	str r2, [sp, #0x18]
	add r6, sp, #0x10
	mov sb, r4
	movs r3, #0xdb
	lsls r3, r3, #3
	adds r5, r7, r3
_080BF59E:
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
	mov r0, sb
	str r0, [sp]
	str r0, [sp, #4]
	movs r1, #0x3c
	mov r8, r1
	str r1, [sp, #8]
	str r6, [sp, #0xc]
	adds r0, r5, #0
	mov r1, sl
	movs r2, #0x68
	movs r3, #0x30
	bl MainSprite_Add
	adds r5, #0x60
	adds r4, #1
	cmp r4, #0xb
	ble _080BF59E
	movs r4, #0
	add r0, sp, #0x10
	strh r4, [r0]
	adds r5, r0, #0
	movs r0, #0x80
	strh r0, [r5, #2]
	ldr r2, _080BF6F8 @ =0x00000B58
	adds r0, r7, r2
	str r4, [sp]
	str r4, [sp, #4]
	mov r3, r8
	str r3, [sp, #8]
	str r5, [sp, #0xc]
	mov r1, sl
	movs r2, #0xcf
	movs r3, #0x30
	bl MainSprite_Add
	ldr r6, _080BF6FC @ =0x00000C18
	adds r0, r7, r6
	str r4, [sp]
	str r4, [sp, #4]
	mov r1, r8
	str r1, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	ldr r1, [sp, #0x1c]
	movs r2, #0x3c
	movs r3, #0x31
	bl MainSprite_Add
	movs r1, #0x90
	add r0, sp, #0x10
	strh r1, [r0]
	movs r0, #0x20
	strh r0, [r5, #2]
	ldr r3, _080BF700 @ =0x00000BB8
	adds r5, r7, r3
	str r4, [sp]
	str r4, [sp, #4]
	mov r6, r8
	str r6, [sp, #8]
	add r0, sp, #0x10
	str r0, [sp, #0xc]
	adds r0, r5, #0
	ldr r1, [sp, #0x1c]
	movs r2, #0x39
	movs r3, #0x30
	bl MainSprite_Add
	str r4, [sp]
	adds r0, r5, #0
	ldr r1, [sp, #0x1c]
	movs r2, #0
	movs r3, #1
	bl MainSprite_SetAnim
	ldr r1, _080BF704 @ =0x00000C78
	adds r0, r7, r1
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	ldr r1, [sp, #0x18]
	movs r2, #0x18
	movs r3, #0x30
	bl MainSprite_Add
	add r0, sp, #0x10
	ldrh r0, [r0]
	subs r0, #0xb
	add r1, sp, #0x10
	strh r0, [r1]
	adds r6, r1, #0
	ldr r3, _080BF708 @ =0x00000CD8
	adds r5, r7, r3
	mov r8, r4
	movs r4, #3
_080BF678:
	mov r0, r8
	str r0, [sp]
	str r0, [sp, #4]
	movs r1, #0x3c
	mov sb, r1
	str r1, [sp, #8]
	str r6, [sp, #0xc]
	adds r0, r5, #0
	ldr r1, [sp, #0x18]
	movs r2, #0x19
	movs r3, #0x30
	bl MainSprite_Add
	ldrh r0, [r6]
	adds r0, #6
	strh r0, [r6]
	adds r5, #0x60
	subs r4, #1
	cmp r4, #0
	bge _080BF678
	movs r1, #0
	add r0, sp, #0x10
	strh r1, [r0]
	strh r1, [r0, #2]
	ldr r2, _080BF70C @ =0x00000E58
	adds r0, r7, r2
	str r1, [sp]
	str r1, [sp, #4]
	mov r3, sb
	str r3, [sp, #8]
	add r4, sp, #0x10
	str r4, [sp, #0xc]
	ldr r1, [sp, #0x1c]
	movs r2, #0x94
	movs r3, #0x11
	bl MainSprite_Add
	ldr r5, _080BF710 @ =0x00000EDC
	adds r0, r7, r5
	bl FUN_080b99a0
	movs r6, #0x80
	lsls r6, r6, #5
	adds r0, r7, r6
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
_080BF6E4: .4byte 0x0000CB05
_080BF6E8: .4byte 0x00005D04
_080BF6EC: .4byte 0x0000B343
_080BF6F0: .4byte 0x0000414C
_080BF6F4: .4byte 0xFFFF0000
_080BF6F8: .4byte 0x00000B58
_080BF6FC: .4byte 0x00000C18
_080BF700: .4byte 0x00000BB8
_080BF704: .4byte 0x00000C78
_080BF708: .4byte 0x00000CD8
_080BF70C: .4byte 0x00000E58
_080BF710: .4byte 0x00000EDC
