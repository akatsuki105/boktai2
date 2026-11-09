	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r7, r0, #0
	str r1, [sp, #0xc]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	mov r8, r0
	ldrb r0, [r7, #5]
	adds r0, #0x20
	asrs r0, r0, #6
	mov sb, r0
	ldr r2, _0815A2F0 @ =0x00000256
	adds r0, r7, r2
	ldrh r5, [r0]
	mov r0, sp
	movs r1, #4
	bl ClearMemory
	ldr r3, _0815A2F4 @ =0x00000472
	adds r0, r7, r3
	ldrh r6, [r0]
	adds r4, r5, #1
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0815A2F8
	adds r0, #4
	b _0815A304
	.align 2, 0
_0815A2F0: .4byte 0x00000256
_0815A2F4: .4byte 0x00000472
_0815A2F8:
	ldr r0, _0815A33C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0815A304:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	cmp r6, r0
	beq _0815A316
	mov r1, sp
	movs r0, #1
	strb r0, [r1]
_0815A316:
	ldr r1, _0815A340 @ =0x00000472
	adds r0, r7, r1
	ldrh r0, [r0]
	mov sl, r0
	ldr r6, _0815A33C @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	adds r4, r5, r0
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0815A344
	adds r0, #4
	b _0815A34E
	.align 2, 0
_0815A33C: .4byte 0x030046A4
_0815A340: .4byte 0x00000472
_0815A344:
	ldr r0, [r6]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0815A34E:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	cmp sl, r0
	beq _0815A360
	mov r1, sp
	movs r0, #1
	strb r0, [r1, #1]
_0815A360:
	ldr r3, _0815A37C @ =0x00000472
	adds r0, r7, r3
	ldrh r6, [r0]
	subs r4, r5, #1
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	mov sl, r4
	cmp r0, #0
	beq _0815A380
	adds r0, #4
	b _0815A38E
	.align 2, 0
_0815A37C: .4byte 0x00000472
_0815A380:
	ldr r2, _0815A3C4 @ =0x030046A4
	ldr r1, [r2]
	mov r3, sl
	lsls r0, r3, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0815A38E:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	cmp r6, r0
	beq _0815A3A0
	mov r1, sp
	movs r0, #1
	strb r0, [r1, #2]
_0815A3A0:
	ldr r1, _0815A3C8 @ =0x00000472
	adds r0, r7, r1
	ldrh r6, [r0]
	ldr r2, _0815A3C4 @ =0x030046A4
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	subs r4, r5, r0
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0815A3CC
	adds r0, #4
	b _0815A3D8
	.align 2, 0
_0815A3C4: .4byte 0x030046A4
_0815A3C8: .4byte 0x00000472
_0815A3CC:
	ldr r1, _0815A414 @ =0x030046A4
	ldr r0, [r1]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0815A3D8:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	cmp r6, r0
	beq _0815A3EA
	mov r1, sp
	movs r0, #1
	strb r0, [r1, #3]
_0815A3EA:
	mov r0, sp
	add r0, sb
	ldrb r0, [r0]
	cmp r0, #1
	bne _0815A430
	movs r0, #0xd5
	lsls r0, r0, #3
	add r0, r8
	movs r1, #0
	strh r1, [r0]
	ldr r0, _0815A418 @ =0x000006AC
	add r0, r8
	strh r1, [r0]
	ldr r2, [sp, #0xc]
	cmp r2, #0
	bne _0815A420
	ldr r1, _0815A41C @ =0x000006AA
	add r1, r8
	movs r0, #0x28
	strh r0, [r1]
	b _0815A426
	.align 2, 0
_0815A414: .4byte 0x030046A4
_0815A418: .4byte 0x000006AC
_0815A41C: .4byte 0x000006AA
_0815A420:
	ldr r0, _0815A42C @ =0x000006AA
	add r0, r8
	strh r1, [r0]
_0815A426:
	movs r0, #0
	b _0815A544
	.align 2, 0
_0815A42C: .4byte 0x000006AA
_0815A430:
	mov r3, sb
	cmp r3, #1
	beq _0815A450
	cmp r3, #1
	bgt _0815A440
	cmp r3, #0
	beq _0815A44C
	b _0815A474
_0815A440:
	mov r0, sb
	cmp r0, #2
	beq _0815A464
	cmp r0, #3
	beq _0815A468
	b _0815A474
_0815A44C:
	adds r5, #1
	b _0815A474
_0815A450:
	ldr r1, _0815A460 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	adds r5, r5, r0
	b _0815A474
	.align 2, 0
_0815A460: .4byte 0x030046A4
_0815A464:
	mov r5, sl
	b _0815A474
_0815A468:
	ldr r1, _0815A4B4 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	subs r5, r5, r0
_0815A474:
	add r6, sp, #4
	ldr r1, _0815A4B4 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r3, _0815A4B4 @ =0x030046A4
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	adds r3, r6, #0
	cmp r0, #0
	beq _0815A4B8
	adds r0, #4
	b _0815A4C4
	.align 2, 0
_0815A4B4: .4byte 0x030046A4
_0815A4B8:
	ldr r1, _0815A530 @ =0x030046A4
	ldr r0, [r1]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0815A4C4:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	movs r5, #0
	strh r0, [r6, #2]
	mov r2, sb
	lsls r0, r2, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	movs r4, #0xd5
	lsls r4, r4, #3
	add r4, r8
	adds r2, r7, #0
	adds r2, #8
	add r0, sp, #4
	ldrh r0, [r0]
	ldrh r1, [r7, #8]
	subs r0, r0, r1
	strh r0, [r4]
	ldrh r0, [r3, #2]
	ldrh r1, [r2, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	movs r3, #0
	ldrsh r0, [r4, r3]
	movs r1, #0x14
	bl Div
	strh r0, [r4]
	ldr r4, _0815A534 @ =0x000006AC
	add r4, r8
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r1, #0x14
	bl Div
	strh r0, [r4]
	ldr r2, [sp, #0xc]
	cmp r2, #0
	bne _0815A53C
	ldr r1, _0815A538 @ =0x000006AA
	add r1, r8
	movs r0, #0x28
	strh r0, [r1]
	movs r3, #0xdf
	lsls r3, r3, #1
	adds r0, r7, r3
	b _0815A540
	.align 2, 0
_0815A530: .4byte 0x030046A4
_0815A534: .4byte 0x000006AC
_0815A538: .4byte 0x000006AA
_0815A53C:
	ldr r0, _0815A554 @ =0x000006AA
	add r0, r8
_0815A540:
	strh r5, [r0]
	movs r0, #1
_0815A544:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0815A554: .4byte 0x000006AA
