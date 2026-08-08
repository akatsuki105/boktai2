	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	mov r8, r0
	movs r5, #0xd8
	lsls r5, r5, #3
	add r5, r8
	mov r1, r8
	adds r1, #0x18
	ldr r4, _08215250 @ =0x00000DB4
	add r4, r8
	ldrh r2, [r4]
	adds r2, #0x29
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r5, #0
	movs r3, #1
	bl FUN_0822f3cc
	ldr r0, [r5, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5, #8]
	movs r0, #0
	ldrsh r1, [r4, r0]
	movs r0, #0x34
	muls r0, r1, r0
	adds r0, #0xf4
	adds r7, r5, r0
	movs r0, #0
	bl FUN_0822b644
	movs r0, #0
	str r0, [sp]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822c40c
	ldr r6, _08215254 @ =0x00000D98
	add r6, r8
	movs r4, #4
_08215230:
	ldm r6!, {r0}
	bl FUN_0804a210
	subs r4, #1
	cmp r4, #0
	bge _08215230
	movs r0, #4
	movs r1, #7
	movs r2, #0x10
	movs r3, #0xa
	bl FUN_0821b28c
	movs r6, #7
	movs r4, #0
	b _08215280
	.align 2, 0
_08215250: .4byte 0x00000DB4
_08215254: .4byte 0x00000D98
_08215258:
	ldr r1, _082152B8 @ =0x000006EC
	adds r0, r5, r1
	ldr r0, [r0]
	bl FUN_08231660
	lsls r2, r4, #1
	adds r1, r7, #2
	adds r1, r1, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
	adds r0, r0, r1
	bl FUN_08231978
	adds r2, r0, #0
	movs r0, #4
	adds r1, r6, #0
	bl FUN_0821b2b4
	adds r6, #2
	adds r4, #1
_08215280:
	movs r0, #1
	ldrsb r0, [r7, r0]
	cmp r4, r0
	blt _08215258
	movs r1, #1
	ldrsb r1, [r7, r1]
	movs r3, #0xdf
	lsls r3, r3, #3
	adds r0, r5, r3
	strh r1, [r0]
	ldr r0, _082152BC @ =0x000006FA
	adds r2, r5, r0
	movs r3, #0
	ldrsh r0, [r2, r3]
	cmp r0, r1
	blt _082152AA
	subs r0, r1, #1
	strh r0, [r2]
	mov r0, r8
	bl FUN_082152ec
_082152AA:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_082152B8: .4byte 0x000006EC
_082152BC: .4byte 0x000006FA
