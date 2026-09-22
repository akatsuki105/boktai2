	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x18
	ldr r1, [r5, #0x18]
	cmp r1, #0
	beq _0804844A
	movs r2, #0xc4
	lsls r2, r2, #1
	adds r0, r4, r2
	str r1, [r0]
	movs r0, #0
	str r0, [r5, #0x18]
_0804844A:
	adds r0, r5, #0
	bl FUN_08049884
	movs r0, #0xc9
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	blt _08048462
	bl TextBox_ShowLine
_08048462:
	movs r1, #0xbb
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _08048474
	adds r0, r4, #0
	bl _call_via_r1
_08048474:
	ldr r2, _0804849C @ =0x00000179
	adds r0, r4, r2
	ldrb r0, [r0]
	adds r2, #2
	adds r1, r4, r2
	ldrb r1, [r1]
	adds r0, r0, r1
	cmp r0, #9
	bgt _080484A4
	movs r0, #0x8b
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r2, #0
	movs r0, #0xdf
	strh r0, [r1]
	ldr r0, _080484A0 @ =0x0000022E
	adds r1, r4, r0
	movs r0, #0x29
	b _080484B6
	.align 2, 0
_0804849C: .4byte 0x00000179
_080484A0: .4byte 0x0000022E
_080484A4:
	movs r2, #0x8b
	lsls r2, r2, #2
	adds r1, r4, r2
	movs r2, #0
	movs r0, #0xdf
	strh r0, [r1]
	ldr r0, _080484F0 @ =0x0000022E
	adds r1, r4, r0
	movs r0, #0x8f
_080484B6:
	strh r0, [r1]
	movs r1, #0x8c
	lsls r1, r1, #2
	adds r0, r4, r1
	strh r2, [r0]
	movs r2, #0xbb
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r1, [r0]
	ldr r0, _080484F4 @ =TextBox_StateIdle
	cmp r1, r0
	beq _080484F8
	adds r0, r4, #0
	bl TextBox_UploadBgPltt
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #0x15
	ldrsb r0, [r5, r0]
	cmp r1, r0
	beq _0804851C
	adds r0, r4, #0
	bl TextBox_RefreshFace
	b _0804851C
	.align 2, 0
_080484F0: .4byte 0x0000022E
_080484F4: .4byte TextBox_StateIdle
_080484F8:
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r3, r4, r2
	movs r1, #0
	ldrsb r1, [r3, r1]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _0804851C
	movs r0, #0xa3
	lsls r0, r0, #2
	adds r2, r4, r0
	ldr r0, [r2, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #8]
	movs r0, #0xff
	strb r0, [r3]
_0804851C:
	adds r0, r5, #0
	bl FUN_08049890
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
