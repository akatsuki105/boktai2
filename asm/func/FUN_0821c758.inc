	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r7, r0, #0
	mov sb, r1
	mov r8, r2
	ldr r0, _0821C81C @ =0x0000CB05
	mov sl, r0
	ldr r1, _0821C820 @ =0x00005D36
	bl GetFile
	adds r3, r0, #0
	movs r1, #0xa7
	lsls r1, r1, #2
	adds r4, r7, r1
	adds r1, r4, #0
	ldm r0!, {r2, r5, r6}
	stm r1!, {r2, r5, r6}
	ldm r0!, {r2, r5, r6}
	stm r1!, {r2, r5, r6}
	ldm r0!, {r2, r5}
	stm r1!, {r2, r5}
	adds r0, r4, #0
	adds r1, r3, #0
	bl OpenSpriteSetFile
	movs r6, #0xaf
	lsls r6, r6, #2
	adds r0, r7, r6
	movs r1, #2
	str r1, [sp]
	movs r5, #0
	str r5, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	mov r1, sb
	str r1, [sp, #0xc]
	adds r1, r4, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822f3fc
	movs r2, #0xed
	lsls r2, r2, #2
	adds r0, r7, r2
	mov r4, r8
	str r4, [r0]
	movs r0, #1
	str r0, [sp]
	str r5, [sp, #4]
	adds r0, r7, #0
	movs r1, #0
	movs r2, #2
	movs r3, #1
	bl FUN_0821c400
	movs r6, #0xef
	lsls r6, r6, #2
	adds r0, r7, r6
	strh r5, [r0]
	ldr r1, _0821C824 @ =0x0000DE23
	mov r0, sl
	bl GetFile
	adds r3, r0, #0
	ldr r1, _0821C828 @ =0x00000B34
	adds r0, r7, r1
	adds r2, r0, #0
	adds r1, r3, #0
	ldm r1!, {r4, r5, r6}
	stm r2!, {r4, r5, r6}
	ldm r1!, {r4, r5, r6}
	stm r2!, {r4, r5, r6}
	ldm r1!, {r4, r5}
	stm r2!, {r4, r5}
	adds r1, r3, #0
	bl OpenSpriteSetFile
	add r6, sp, #0x10
	mov r1, sb
	ldrh r0, [r1]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0821C82C
	asrs r0, r0, #8
	b _0821C832
	.align 2, 0
_0821C81C: .4byte 0x0000CB05
_0821C820: .4byte 0x00005D36
_0821C824: .4byte 0x0000DE23
_0821C828: .4byte 0x00000B34
_0821C82C:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0821C832:
	strh r0, [r6]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0821C844
	asrs r0, r0, #8
	b _0821C84A
_0821C844:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0821C84A:
	adds r4, r0, #0
	mov r2, sb
	movs r5, #2
	ldrsh r1, [r2, r5]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0821C860
	asrs r0, r0, #8
	b _0821C866
_0821C860:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0821C866:
	subs r2, r4, r0
	movs r5, #0
	adds r4, r4, r0
	ldr r3, _0821C8E8 @ =0x030047C8
	ldrh r0, [r6]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r6]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r6, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r6, #4]
	ldr r6, _0821C8EC @ =0x00000B54
	adds r0, r7, r6
	ldr r2, _0821C8F0 @ =0x00000B34
	adds r1, r7, r2
	movs r2, #2
	str r2, [sp]
	str r5, [sp, #4]
	movs r2, #0x3c
	str r2, [sp, #8]
	add r4, sp, #0x10
	str r4, [sp, #0xc]
	movs r2, #0
	movs r3, #0x11
	bl FUN_0822f3fc
	movs r6, #0
_0821C8A6:
	movs r0, #0x64
	muls r0, r5, r0
	ldr r1, _0821C8F4 @ =0x00000814
	adds r0, r0, r1
	adds r4, r7, r0
	adds r0, r4, #0
	adds r0, #0x60
	strb r6, [r0]
	adds r0, #1
	strb r6, [r0]
	movs r0, #2
	str r0, [sp]
	str r6, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	mov r2, sb
	str r2, [sp, #0xc]
	adds r0, r4, #0
	movs r2, #0xa7
	lsls r2, r2, #2
	adds r1, r7, r2
	movs r2, #0
	movs r3, #1
	bl FUN_0822f3fc
	ldr r1, [r4, #8]
	movs r0, #1
	ands r0, r5
	cmp r0, #0
	beq _0821C8F8
	movs r0, #0x80
	lsls r0, r0, #2
	b _0821C8FC
	.align 2, 0
_0821C8E8: .4byte 0x030047C8
_0821C8EC: .4byte 0x00000B54
_0821C8F0: .4byte 0x00000B34
_0821C8F4: .4byte 0x00000814
_0821C8F8:
	movs r0, #0x80
	lsls r0, r0, #3
_0821C8FC:
	orrs r1, r0
	str r1, [r4, #8]
	adds r5, #1
	cmp r5, #7
	ble _0821C8A6
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
