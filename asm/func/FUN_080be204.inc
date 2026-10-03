	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r7, r0, #0
	ldr r4, _080BE5E0 @ =0x0000CB05
	ldr r1, _080BE5E4 @ =0x00005D04
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
	mov r8, r6
	mov r0, r8
	adds r1, r2, #0
	bl OpenMainSpriteFile
	ldr r1, _080BE5E8 @ =0x0000B343
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
	ldr r1, _080BE5EC @ =0x0000414C
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
	adds r6, r7, #0
	adds r6, #0x58
	adds r0, r6, #0
	adds r1, r2, #0
	bl OpenMainSpriteFile
	ldr r1, _080BE5F0 @ =0xFFFF0000
	movs r4, #0
	str r4, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r1
	str r0, [sp, #0x14]
	movs r1, #0
	adds r0, r7, #0
	adds r0, #0x78
	str r1, [sp]
	str r1, [sp, #4]
	movs r5, #0x3c
	str r5, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #0x27
	movs r3, #0x30
	bl MainSprite_Add
	adds r0, r7, #0
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
	movs r3, #0x9c
	lsls r3, r3, #1
	adds r0, r7, r3
	str r4, [sp]
	str r4, [sp, #4]
	str r5, [sp, #8]
	add r4, sp, #0x10
	str r4, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #0x24
	movs r3, #0x30
	bl MainSprite_Add
	movs r4, #0
	add r6, sp, #0x10
	mov sb, r4
	mov r5, r8
	str r5, [sp, #0x18]
	movs r0, #0xcc
	lsls r0, r0, #1
	adds r5, r7, r0
_080BE2F0:
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
	mov r1, sb
	str r1, [sp]
	str r1, [sp, #4]
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
	ble _080BE2F0
	movs r4, #0
	movs r2, #0x18
	adds r2, r2, r7
	mov sl, r2
	adds r3, r7, #0
	adds r3, #0x58
	str r3, [sp, #0x1c]
	add r6, sp, #0x10
	mov r8, r4
	movs r0, #0xf3
	lsls r0, r0, #3
	adds r5, r7, r0
_080BE344:
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
	mov r1, r8
	str r1, [sp]
	str r1, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	adds r0, r5, #0
	ldr r1, [sp, #0x18]
	movs r2, #0x68
	movs r3, #0x30
	bl MainSprite_Add
	adds r5, #0x60
	adds r4, #1
	cmp r4, #0xb
	ble _080BE344
	movs r6, #0
	ldr r2, _080BE5F4 @ =0x00000D38
	adds r5, r7, r2
	movs r4, #3
_080BE386:
	str r6, [sp]
	str r6, [sp, #4]
	movs r3, #0x3c
	mov sb, r3
	str r3, [sp, #8]
	add r0, sp, #0x10
	str r0, [sp, #0xc]
	adds r0, r5, #0
	mov r1, sl
	movs r2, #0x41
	movs r3, #0x30
	bl MainSprite_Add
	adds r5, #0x60
	subs r4, #1
	cmp r4, #0
	bge _080BE386
	movs r4, #0
	add r0, sp, #0x10
	strh r4, [r0]
	adds r6, r0, #0
	movs r0, #0x80
	strh r0, [r6, #2]
	ldr r1, _080BE5F8 @ =0x00000CD8
	adds r0, r7, r1
	str r4, [sp]
	str r4, [sp, #4]
	mov r2, sb
	str r2, [sp, #8]
	str r6, [sp, #0xc]
	ldr r1, [sp, #0x18]
	movs r2, #0xd0
	movs r3, #0x30
	bl MainSprite_Add
	movs r1, #0x78
	add r0, sp, #0x10
	strh r1, [r0]
	movs r5, #0x68
	strh r5, [r6, #2]
	ldr r3, _080BE5FC @ =0x00000C78
	adds r0, r7, r3
	str r4, [sp]
	str r4, [sp, #4]
	mov r1, sb
	str r1, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	ldr r1, [sp, #0x18]
	movs r2, #0xcb
	movs r3, #0x30
	bl MainSprite_Add
	add r0, sp, #0x10
	strh r5, [r0]
	movs r3, #0x20
	mov r8, r3
	mov r5, r8
	strh r5, [r6, #2]
	ldr r0, _080BE600 @ =0x00000C18
	adds r5, r7, r0
	str r4, [sp]
	str r4, [sp, #4]
	mov r1, sb
	str r1, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	adds r0, r5, #0
	ldr r1, [sp, #0x18]
	movs r2, #0xcc
	movs r3, #0x30
	bl MainSprite_Add
	movs r1, #0xb8
	lsls r1, r1, #2
	adds r0, r5, #0
	bl FUN_080b95bc
	ldr r3, _080BE604 @ =0x00000F18
	adds r0, r7, r3
	str r4, [sp]
	str r4, [sp, #4]
	mov r5, sb
	str r5, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	mov r1, sl
	movs r2, #0x3c
	movs r3, #0x31
	bl MainSprite_Add
	movs r1, #0x90
	add r0, sp, #0x10
	strh r1, [r0]
	mov r2, r8
	strh r2, [r6, #2]
	ldr r3, _080BE608 @ =0x00000EB8
	adds r5, r7, r3
	str r4, [sp]
	str r4, [sp, #4]
	mov r6, sb
	str r6, [sp, #8]
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
	ldr r1, _080BE60C @ =0x000013F8
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
	ldr r3, _080BE610 @ =0x00001458
	adds r5, r7, r3
	mov r8, r4
	movs r4, #3
_080BE49A:
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
	bge _080BE49A
	movs r1, #0x28
	add r0, sp, #0x10
	strh r1, [r0]
	adds r1, r0, #0
	movs r0, #0x68
	strh r0, [r1, #2]
	adds r6, r1, #0
	ldr r1, _080BE614 @ =0x00000F78
	adds r5, r7, r1
	movs r2, #0
	mov r8, r2
	movs r4, #2
_080BE4D8:
	mov r3, r8
	str r3, [sp]
	str r3, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	adds r0, r5, #0
	mov r1, sl
	movs r2, #0
	movs r3, #0x30
	bl MainSprite_Add
	ldrh r0, [r6]
	adds r0, #8
	strh r0, [r6]
	adds r5, #0x60
	subs r4, #1
	cmp r4, #0
	bge _080BE4D8
	movs r1, #0x58
	add r0, sp, #0x10
	strh r1, [r0]
	adds r1, r0, #0
	movs r0, #0x68
	strh r0, [r1, #2]
	adds r6, r1, #0
	ldr r4, _080BE618 @ =0x00001098
	adds r5, r7, r4
	movs r0, #0
	mov r8, r0
	movs r4, #2
_080BE516:
	mov r1, r8
	str r1, [sp]
	str r1, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	adds r0, r5, #0
	mov r1, sl
	movs r2, #0
	movs r3, #0x30
	bl MainSprite_Add
	ldrh r0, [r6]
	adds r0, #8
	strh r0, [r6]
	adds r5, #0x60
	subs r4, #1
	cmp r4, #0
	bge _080BE516
	movs r1, #0x28
	add r0, sp, #0x10
	strh r1, [r0]
	adds r1, r0, #0
	movs r0, #0x70
	strh r0, [r1, #2]
	adds r6, r1, #0
	ldr r2, _080BE61C @ =0x000011B8
	adds r5, r7, r2
	movs r3, #0
	mov r8, r3
	movs r4, #2
_080BE554:
	mov r0, r8
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	adds r0, r5, #0
	mov r1, sl
	movs r2, #0
	movs r3, #0x30
	bl MainSprite_Add
	ldrh r0, [r6]
	adds r0, #8
	strh r0, [r6]
	adds r5, #0x60
	subs r4, #1
	cmp r4, #0
	bge _080BE554
	movs r1, #0x58
	add r0, sp, #0x10
	strh r1, [r0]
	adds r1, r0, #0
	movs r0, #0x70
	strh r0, [r1, #2]
	adds r6, r1, #0
	ldr r1, _080BE620 @ =0x000012D8
	adds r5, r7, r1
	movs r2, #0
	mov r8, r2
	movs r4, #2
_080BE592:
	mov r3, r8
	str r3, [sp]
	str r3, [sp, #4]
	movs r0, #0x3c
	mov sb, r0
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	adds r0, r5, #0
	mov r1, sl
	movs r2, #0
	movs r3, #0x30
	bl MainSprite_Add
	ldrh r0, [r6]
	adds r0, #8
	strh r0, [r6]
	adds r5, #0x60
	subs r4, #1
	cmp r4, #0
	bge _080BE592
	movs r1, #0
	add r0, sp, #0x10
	strh r1, [r0]
	strh r1, [r0, #2]
	ldr r2, _080BE624 @ =0x000015D8
	adds r0, r7, r2
	str r1, [sp]
	str r1, [sp, #4]
	mov r3, sb
	str r3, [sp, #8]
	add r4, sp, #0x10
	str r4, [sp, #0xc]
	mov r1, sl
	movs r2, #0x94
	movs r3, #0x11
	bl MainSprite_Add
	b _080BE628
	.align 2, 0
_080BE5E0: .4byte 0x0000CB05
_080BE5E4: .4byte 0x00005D04
_080BE5E8: .4byte 0x0000B343
_080BE5EC: .4byte 0x0000414C
_080BE5F0: .4byte 0xFFFF0000
_080BE5F4: .4byte 0x00000D38
_080BE5F8: .4byte 0x00000CD8
_080BE5FC: .4byte 0x00000C78
_080BE600: .4byte 0x00000C18
_080BE604: .4byte 0x00000F18
_080BE608: .4byte 0x00000EB8
_080BE60C: .4byte 0x000013F8
_080BE610: .4byte 0x00001458
_080BE614: .4byte 0x00000F78
_080BE618: .4byte 0x00001098
_080BE61C: .4byte 0x000011B8
_080BE620: .4byte 0x000012D8
_080BE624: .4byte 0x000015D8
_080BE628:
	ldr r5, _080BE648 @ =0x00001690
	adds r0, r7, r5
	bl FUN_080b99a0
	ldr r6, _080BE64C @ =0x000017B4
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
_080BE648: .4byte 0x00001690
_080BE64C: .4byte 0x000017B4
