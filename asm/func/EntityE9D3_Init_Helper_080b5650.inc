	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r7, r0, #0
	ldr r4, _080B5900 @ =0x0000CB05
	ldr r1, _080B5904 @ =0x000092F0
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
	adds r6, r7, #0
	adds r6, #0x18
	adds r0, r6, #0
	adds r1, r2, #0
	bl OpenSpriteSetFile
	ldr r1, _080B5908 @ =0x0000B343
	adds r0, r4, #0
	bl GetFile
	adds r2, r0, #0
	adds r1, r7, #0
	adds r1, #0x38
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r4}
	stm r1!, {r3, r4}
	movs r5, #0x38
	adds r5, r5, r7
	mov sb, r5
	mov r0, sb
	adds r1, r2, #0
	bl OpenSpriteSetFile
	ldr r1, _080B590C @ =0xFFFF0000
	movs r4, #0
	str r4, [sp, #0x10]
	add r0, sp, #0x10
	mov r8, r0
	ldr r0, [sp, #0x14]
	ands r0, r1
	str r0, [sp, #0x14]
	movs r1, #0
	adds r0, r7, #0
	adds r0, #0x58
	str r1, [sp]
	str r1, [sp, #4]
	movs r5, #0x3c
	str r5, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #4
	movs r3, #0x30
	bl FUN_0822f3fc
	movs r2, #0x8c
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r3, _080B5910 @ =0x0000082C
	adds r1, r7, r3
	ldrh r2, [r1]
	adds r2, #7
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r4, [sp]
	str r4, [sp, #4]
	str r5, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	adds r1, r6, #0
	movs r3, #0x30
	bl FUN_0822f3fc
	add r0, sp, #0x10
	ldrh r0, [r0]
	adds r0, #8
	add r1, sp, #0x10
	strh r0, [r1]
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r0, r7, r2
	str r4, [sp]
	str r4, [sp, #4]
	str r5, [sp, #8]
	str r1, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #8
	movs r3, #0x30
	bl FUN_0822f3fc
	add r0, sp, #0x10
	ldrh r0, [r0]
	adds r0, #8
	add r1, sp, #0x10
	strh r0, [r1]
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r7, r3
	str r4, [sp]
	str r4, [sp, #4]
	str r5, [sp, #8]
	str r1, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #8
	movs r3, #0x30
	bl FUN_0822f3fc
	ldr r1, _080B5914 @ =0x0000FFF8
	add r0, sp, #0x10
	strh r1, [r0]
	mov r0, r8
	strh r1, [r0, #2]
	adds r0, r7, #0
	adds r0, #0xb8
	str r4, [sp]
	str r4, [sp, #4]
	str r5, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	mov r1, sb
	movs r2, #0x94
	movs r3, #0x10
	bl FUN_0822f3fc
	movs r1, #0x10
	add r0, sp, #0x10
	strh r1, [r0]
	ldr r0, _080B5918 @ =0x0000FFFC
	mov r2, r8
	strh r0, [r2, #2]
	movs r3, #0x8e
	lsls r3, r3, #2
	adds r0, r7, r3
	str r4, [sp]
	str r4, [sp, #4]
	str r5, [sp, #8]
	add r4, sp, #0x10
	str r4, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #0x12
	movs r3, #0x30
	bl FUN_0822f3fc
	movs r1, #0x90
	add r0, sp, #0x10
	strh r1, [r0]
	movs r0, #0x28
	mov r5, r8
	strh r0, [r5, #2]
	add r6, sp, #0x10
	mov sl, sb
	movs r0, #0xa6
	lsls r0, r0, #2
	adds r5, r7, r0
	movs r1, #0
	mov r8, r1
	movs r4, #3
_080B57A6:
	mov r2, r8
	str r2, [sp]
	str r2, [sp, #4]
	movs r3, #0x3c
	mov sb, r3
	str r3, [sp, #8]
	str r6, [sp, #0xc]
	adds r0, r5, #0
	adds r1, r7, #0
	adds r1, #0x38
	movs r2, #0x14
	movs r3, #0x30
	bl FUN_0822f3fc
	ldrh r0, [r6]
	adds r0, #8
	strh r0, [r6]
	adds r5, #0x60
	subs r4, #1
	cmp r4, #0
	bge _080B57A6
	movs r4, #0xef
	lsls r4, r4, #3
	adds r0, r7, r4
	movs r1, #1
	str r1, [sp]
	movs r1, #0
	str r1, [sp, #4]
	mov r5, sb
	str r5, [sp, #8]
	add r4, sp, #0x10
	str r4, [sp, #0xc]
	mov r1, sl
	movs r2, #0x47
	movs r3, #0x30
	bl FUN_0822f3fc
	ldr r1, _080B591C @ =0x0000FFC8
	add r0, sp, #0x10
	strh r1, [r0]
	movs r0, #0x38
	strh r0, [r4, #2]
	movs r6, #0x18
	adds r6, r6, r7
	mov sb, r6
	add r6, sp, #0x10
	movs r0, #0x83
	lsls r0, r0, #3
	adds r5, r7, r0
	movs r1, #0
	mov r8, r1
	movs r4, #3
_080B580E:
	mov r2, r8
	str r2, [sp]
	str r2, [sp, #4]
	movs r3, #0x3c
	mov sl, r3
	str r3, [sp, #8]
	str r6, [sp, #0xc]
	adds r0, r5, #0
	mov r1, sb
	movs r2, #8
	movs r3, #0x30
	bl FUN_0822f3fc
	ldrh r0, [r6]
	adds r0, #8
	strh r0, [r6]
	adds r5, #0x60
	subs r4, #1
	cmp r4, #0
	bge _080B580E
	movs r3, #0
	movs r1, #0x58
	add r0, sp, #0x10
	strh r1, [r0]
	adds r4, r0, #0
	movs r0, #0x38
	strh r0, [r4, #2]
	movs r5, #0xb3
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r6, _080B5910 @ =0x0000082C
	adds r1, r7, r6
	ldrh r2, [r1]
	adds r2, #7
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	str r3, [sp, #4]
	mov r1, sl
	str r1, [sp, #8]
	str r4, [sp, #0xc]
	mov r1, sb
	movs r3, #0x30
	bl FUN_0822f3fc
	ldr r1, _080B5920 @ =0x0000FFD0
	add r0, sp, #0x10
	strh r1, [r0]
	movs r0, #0x48
	strh r0, [r4, #2]
	add r6, sp, #0x10
	movs r2, #0xbf
	lsls r2, r2, #3
	adds r5, r7, r2
	movs r3, #0
	mov r8, r3
	movs r4, #3
_080B5880:
	mov r0, r8
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	adds r0, r5, #0
	mov r1, sb
	movs r2, #8
	movs r3, #0x30
	bl FUN_0822f3fc
	ldrh r0, [r6]
	adds r0, #8
	strh r0, [r6]
	adds r5, #0x60
	subs r4, #1
	cmp r4, #0
	bge _080B5880
	movs r6, #0
	ldr r1, _080B5924 @ =0x00000804
	adds r4, r7, r1
	ldr r1, _080B5928 @ =0x0000A47C
	adds r0, r4, #0
	bl FUN_0822b16c
	movs r2, #0xfb
	lsls r2, r2, #3
	adds r5, r7, r2
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	ldr r3, _080B592C @ =0x000007DF
	adds r0, r7, r3
	strb r6, [r0]
	movs r0, #0x30
	str r0, [r5]
	ldr r1, _080B5930 @ =0x00000143
	adds r0, r4, #0
	bl FUN_0822b20c
	ldr r4, _080B5934 @ =0x000007F4
	adds r1, r7, r4
	movs r0, #0xa0
	strh r0, [r1]
	ldr r5, _080B5938 @ =0x000007F6
	adds r1, r7, r5
	movs r0, #0x58
	strh r0, [r1]
	movs r1, #0xff
	lsls r1, r1, #3
	adds r0, r7, r1
	strh r6, [r0]
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B5900: .4byte 0x0000CB05
_080B5904: .4byte 0x000092F0
_080B5908: .4byte 0x0000B343
_080B590C: .4byte 0xFFFF0000
_080B5910: .4byte 0x0000082C
_080B5914: .4byte 0x0000FFF8
_080B5918: .4byte 0x0000FFFC
_080B591C: .4byte 0x0000FFC8
_080B5920: .4byte 0x0000FFD0
_080B5924: .4byte 0x00000804
_080B5928: .4byte 0x0000A47C
_080B592C: .4byte 0x000007DF
_080B5930: .4byte 0x00000143
_080B5934: .4byte 0x000007F4
_080B5938: .4byte 0x000007F6
