	push {r4, r5, r6, r7, lr}
	adds r1, r0, #0
	movs r0, #0xd8
	lsls r0, r0, #3
	adds r5, r1, r0
	ldr r0, _08215770 @ =gSystemSaveData
	ldr r0, [r0]
	ldr r0, [r0, #0x20]
	subs r3, r0, #1
	movs r2, #0
	ldr r4, _08215774 @ =0x00000DB6
	adds r0, r1, r4
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp r2, r0
	bge _0821578E
	ldr r0, _08215778 @ =0x00000DB4
	adds r6, r1, r0
	adds r4, #4
	adds r4, r4, r1
	mov ip, r4
	ldr r7, _08215774 @ =0x00000DB6
	adds r4, r1, r7
	ldr r0, _0821577C @ =0x000007B4
	adds r1, r1, r0
_0821575E:
	movs r0, #1
	ldrsb r0, [r1, r0]
	subs r0, r3, r0
	cmp r0, #0
	bge _08215780
	strh r2, [r6]
	mov r1, ip
	strh r3, [r1]
	b _0821578E
	.align 2, 0
_08215770: .4byte gSystemSaveData
_08215774: .4byte 0x00000DB6
_08215778: .4byte 0x00000DB4
_0821577C: .4byte 0x000007B4
_08215780:
	adds r3, r0, #0
	adds r1, #0x34
	adds r2, #1
	movs r7, #0
	ldrsh r0, [r4, r7]
	cmp r2, r0
	blt _0821575E
_0821578E:
	ldr r1, _082157C8 @ =0x000006F4
	adds r0, r5, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x34
	muls r1, r0, r1
	adds r1, #0xf4
	adds r1, r5, r1
	ldr r3, _082157CC @ =0x000006FA
	adds r0, r5, r3
	movs r4, #0
	ldrsh r2, [r0, r4]
	lsls r2, r2, #2
	adds r0, r1, #0
	adds r0, #0x20
	adds r0, r0, r2
	ldr r0, [r0]
	adds r1, #0xc
	adds r1, r1, r2
	ldr r1, [r1]
	movs r2, #0
	bl FUN_082401e8
	ldr r1, _082157D0 @ =0x030047E0
	movs r0, #0
	strb r0, [r1, #9]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_082157C8: .4byte 0x000006F4
_082157CC: .4byte 0x000006FA
_082157D0: .4byte 0x030047E0
