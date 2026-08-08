	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r7, r0, #0
	movs r1, #0
	bl FUN_080ef86c
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r5, [r0]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080F0B80
	cmp r1, #0
	blt _080F0B80
	ldr r0, _080F0B84 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080F0B80
	ldr r0, _080F0B88 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080F0B8C
_080F0B80:
	movs r4, #0
	b _080F0B9A
	.align 2, 0
_080F0B84: .4byte 0x030046A8
_080F0B88: .4byte 0x030046AC
_080F0B8C:
	ldr r0, _080F0BAC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080F0B9A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080F0BB0
	adds r0, #4
	b _080F0BBC
	.align 2, 0
_080F0BAC: .4byte 0x030046A4
_080F0BB0:
	ldr r0, _080F0BD0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080F0BBC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080F0BD4
	cmp r2, #2
	beq _080F0BD8
	b _080F0BDC
	.align 2, 0
_080F0BD0: .4byte 0x030046A4
_080F0BD4:
	ldrb r0, [r5, #4]
	b _080F0BDA
_080F0BD8:
	ldrb r0, [r5]
_080F0BDA:
	subs r1, r1, r0
_080F0BDC:
	strh r1, [r5, #2]
	movs r2, #0x97
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r1, [r0]
	ldr r3, _080F0C0C @ =0x000004A4
	adds r0, r7, r3
	ldr r6, [r0]
	adds r4, r7, #0
	adds r4, #8
	ldr r0, [r1]
	adds r5, r0, #0
	adds r5, #8
	adds r0, r6, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _080F0C10
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r0, r7, r5
	b _080F0C36
	.align 2, 0
_080F0C0C: .4byte 0x000004A4
_080F0C10:
	adds r0, r6, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _080F0C30
	cmp r0, #2
	beq _080F0C2C
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_080F0C2C:
	movs r0, #1
	b _080F0C40
_080F0C30:
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r0, r7, r6
_080F0C36:
	ldr r1, _080F0C80 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_080F0C40:
	cmp r0, #0
	beq _080F0C46
	b _080F0D98
_080F0C46:
	mov r6, sp
	adds r0, r7, #0
	adds r0, #0x9c
	ldr r2, [r0, #8]
	ldrh r1, [r2]
	mov r0, sp
	strh r1, [r0]
	ldrh r1, [r2, #2]
	strh r1, [r6, #4]
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _080F0C7A
	cmp r1, #0
	blt _080F0C7A
	ldr r0, _080F0C84 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080F0C7A
	ldr r0, _080F0C88 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080F0C8C
_080F0C7A:
	movs r5, #0
	b _080F0C9A
	.align 2, 0
_080F0C80: .4byte 0xFFFFFDFF
_080F0C84: .4byte 0x030046A8
_080F0C88: .4byte 0x030046AC
_080F0C8C:
	ldr r0, _080F0CAC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_080F0C9A:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080F0CB0
	adds r0, #4
	b _080F0CBC
	.align 2, 0
_080F0CAC: .4byte 0x030046A4
_080F0CB0:
	ldr r0, _080F0CD0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080F0CBC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080F0CD4
	cmp r2, #2
	beq _080F0CD8
	b _080F0CDC
	.align 2, 0
_080F0CD0: .4byte 0x030046A4
_080F0CD4:
	ldrb r0, [r6, #4]
	b _080F0CDA
_080F0CD8:
	ldrb r0, [r6]
_080F0CDA:
	subs r1, r1, r0
_080F0CDC:
	strh r1, [r6, #2]
	ldr r1, _080F0CFC @ =0x000004A4
	adds r0, r7, r1
	ldr r5, [r0]
	adds r0, r5, #0
	adds r1, r4, #0
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	bne _080F0D00
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
	b _080F0D24
	.align 2, 0
_080F0CFC: .4byte 0x000004A4
_080F0D00:
	adds r0, r5, #0
	adds r1, r4, #0
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _080F0D1E
	cmp r0, #2
	beq _080F0D2C
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
	b _080F0D2C
_080F0D1E:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r7, r3
_080F0D24:
	ldr r1, _080F0D80 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
_080F0D2C:
	movs r4, #0xb4
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r1, [r0]
	movs r3, #1
	ldr r5, _080F0D84 @ =0x0000046D
	adds r0, r7, r5
	movs r2, #0
	strb r3, [r0]
	ldr r6, _080F0D88 @ =0x0000046B
	adds r0, r7, r6
	strb r2, [r0]
	subs r4, #0x4d
	adds r0, r7, r4
	strb r3, [r0]
	movs r5, #0xaf
	lsls r5, r5, #3
	adds r0, r7, r5
	str r1, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r7, r6
	movs r1, #0
	strh r2, [r0]
	movs r4, #2
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r0, r7, r5
	strb r1, [r0]
	ldr r6, _080F0D8C @ =0x00000469
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _080F0D90 @ =0x0000046A
	adds r0, r7, r1
	strb r4, [r0]
	ldr r4, _080F0D94 @ =0x00000484
	adds r0, r7, r4
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r3, [r0]
	b _080F0E4E
	.align 2, 0
_080F0D80: .4byte 0xFFFFFDFF
_080F0D84: .4byte 0x0000046D
_080F0D88: .4byte 0x0000046B
_080F0D8C: .4byte 0x00000469
_080F0D90: .4byte 0x0000046A
_080F0D94: .4byte 0x00000484
_080F0D98:
	ldr r6, _080F0E58 @ =0x000001DF
	adds r0, r7, r6
	ldrb r3, [r0]
	adds r0, r7, #0
	movs r1, #0
	movs r2, #1
	bl FUN_080e5718
	movs r2, #3
	movs r1, #1
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r7, r3
	movs r4, #0
	strb r2, [r0]
	ldr r5, _080F0E5C @ =0x00000469
	adds r0, r7, r5
	strb r1, [r0]
	ldr r6, _080F0E60 @ =0x0000046A
	adds r0, r7, r6
	strb r4, [r0]
	ldr r2, _080F0E64 @ =0x00000484
	adds r0, r7, r2
	str r4, [r0]
	adds r3, #4
	adds r0, r7, r3
	strb r1, [r0]
	ldr r3, _080F0E68 @ =FUN_080e6794
	movs r2, #0xe
	adds r5, #4
	adds r0, r7, r5
	strb r1, [r0]
	adds r6, #1
	adds r0, r7, r6
	strb r4, [r0]
	ldr r1, _080F0E6C @ =0x00000553
	adds r0, r7, r1
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r7, r2
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	movs r5, #0
	strh r4, [r0]
	movs r6, #0xb4
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r3, [r0]
	movs r0, #7
	mov ip, r0
	movs r1, #0x1e
	subs r6, #0x48
	adds r2, r7, r6
	subs r6, #4
	adds r0, r7, r6
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	strb r5, [r0]
	ldr r2, _080F0E70 @ =0x00000551
	adds r0, r7, r2
	strb r5, [r0]
	ldr r3, _080F0E74 @ =0x00000552
	adds r0, r7, r3
	mov r5, ip
	strb r5, [r0]
	movs r2, #0x10
	movs r6, #0xbc
	lsls r6, r6, #1
	adds r1, r7, r6
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #5
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r7, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r2, #0x95
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r0, [r0]
	strh r4, [r0, #6]
_080F0E4E:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080F0E58: .4byte 0x000001DF
_080F0E5C: .4byte 0x00000469
_080F0E60: .4byte 0x0000046A
_080F0E64: .4byte 0x00000484
_080F0E68: .4byte FUN_080e6794
_080F0E6C: .4byte 0x00000553
_080F0E70: .4byte 0x00000551
_080F0E74: .4byte 0x00000552
