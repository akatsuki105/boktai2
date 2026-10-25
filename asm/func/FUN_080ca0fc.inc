	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	adds r6, r0, #0
	ldr r1, _080CA198 @ =0x000025C8
	adds r0, r6, r1
	ldrb r3, [r0]
	cmp r3, #1
	bne _080CA140
	ldr r2, _080CA19C @ =0x0000191A
	adds r0, r6, r2
	movs r2, #0
	strh r2, [r0]
	ldr r4, _080CA1A0 @ =0x00001918
	adds r0, r6, r4
	strh r2, [r0]
	adds r1, r6, #0
	adds r1, #0xa3
	ldrb r0, [r1]
	subs r0, #0x1f
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r7, r1, #0
	cmp r0, #8
	bhi _080CA140
	ldr r1, _080CA1A4 @ =FUN_080c6c8c
	movs r0, #0
	strb r0, [r7]
	adds r0, r6, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r2, [r0]
	adds r0, #0x1d
	strb r3, [r0]
_080CA140:
	movs r1, #4
	ldr r0, _080CA1A8 @ =0x03002BC0
	ldr r3, [r0]
	ands r3, r1
	cmp r3, #0
	beq _080CA14E
	b _080CA420
_080CA14E:
	adds r0, r6, #0
	adds r0, #0x90
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bgt _080CA15C
	b _080CA420
_080CA15C:
	ldr r2, _080CA19C @ =0x0000191A
	adds r0, r6, r2
	ldrh r0, [r0]
	cmp r0, #0x77
	bls _080CA1D8
	ldr r4, _080CA1A0 @ =0x00001918
	adds r0, r6, r4
	ldrh r0, [r0]
	cmp r0, #0x77
	bls _080CA1BC
	adds r0, r6, #0
	adds r0, #0xa3
	ldrb r2, [r0]
	adds r7, r0, #0
	cmp r2, #0x21
	beq _080CA20A
	cmp r2, #0x24
	beq _080CA20A
	cmp r2, #0x25
	beq _080CA20A
	cmp r2, #0x26
	beq _080CA20A
	cmp r2, #0x27
	beq _080CA20A
	cmp r2, #0x20
	bne _080CA1B0
	ldr r1, _080CA1AC @ =FUN_080c95cc
	movs r0, #0x21
	b _080CA1F6
	.align 2, 0
_080CA198: .4byte 0x000025C8
_080CA19C: .4byte 0x0000191A
_080CA1A0: .4byte 0x00001918
_080CA1A4: .4byte FUN_080c6c8c
_080CA1A8: .4byte 0x03002BC0
_080CA1AC: .4byte FUN_080c95cc
_080CA1B0:
	ldr r1, _080CA1B8 @ =FUN_080c9648
	movs r0, #0x24
	b _080CA1F6
	.align 2, 0
_080CA1B8: .4byte FUN_080c9648
_080CA1BC:
	adds r1, r6, #0
	adds r1, #0xa3
	ldrb r0, [r1]
	subs r0, #0x22
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r7, r1, #0
	cmp r0, #1
	bls _080CA20A
	ldr r1, _080CA1D4 @ =FUN_080c9278
	movs r0, #0x22
	b _080CA1F6
	.align 2, 0
_080CA1D4: .4byte FUN_080c9278
_080CA1D8:
	ldr r1, _080CA228 @ =0x00001918
	adds r0, r6, r1
	ldrh r0, [r0]
	adds r7, r6, #0
	adds r7, #0xa3
	cmp r0, #0x77
	bls _080CA20A
	ldrb r0, [r7]
	subs r0, #0x1f
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _080CA20A
	ldr r1, _080CA22C @ =FUN_080c8f20
	movs r0, #0x1f
_080CA1F6:
	strb r0, [r7]
	adds r0, r6, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r3, [r0]
	adds r1, r6, #0
	adds r1, #0xa9
	movs r0, #1
	strb r0, [r1]
_080CA20A:
	adds r3, r7, #0
	ldrb r0, [r3]
	cmp r0, #3
	bne _080CA234
	adds r1, r6, #0
	adds r1, #0xa7
	ldrb r0, [r1]
	cmp r0, #0
	bne _080CA21E
	b _080CA420
_080CA21E:
	movs r2, #0
	strb r2, [r1]
	ldr r1, _080CA230 @ =FUN_080c74b4
	movs r0, #4
	b _080CA3D8
	.align 2, 0
_080CA228: .4byte 0x00001918
_080CA22C: .4byte FUN_080c8f20
_080CA230: .4byte FUN_080c74b4
_080CA234:
	cmp r0, #4
	beq _080CA23A
	b _080CA334
_080CA23A:
	movs r5, #0
	ldr r2, _080CA2F8 @ =0x03002BE0
	ldr r4, [r2]
	movs r1, #0x80
	lsls r1, r1, #0xb
	ldr r0, [r4, #0x20]
	ands r0, r1
	mov ip, r2
	cmp r0, #0
	bne _080CA286
	movs r2, #0x2c
	ldrsh r3, [r4, r2]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r6, r1
	movs r1, #0
	ldrsh r2, [r0, r1]
	movs r0, #0x30
	ldrsh r1, [r4, r0]
	movs r4, #0xbb
	lsls r4, r4, #2
	adds r0, r6, r4
	movs r4, #0
	ldrsh r0, [r0, r4]
	subs r1, r1, r0
	subs r3, r3, r2
	cmp r3, #0
	bge _080CA274
	rsbs r3, r3, #0
_080CA274:
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r3, r0
	bgt _080CA286
	ldr r2, _080CA2FC @ =0xFFFFFF00
	adds r0, r1, r2
	cmp r0, #0x80
	bhi _080CA286
	movs r5, #1
_080CA286:
	cmp r5, #0
	beq _080CA310
	movs r4, #0xba
	lsls r4, r4, #2
	adds r2, r6, r4
	ldr r3, _080CA300 @ =0xFFFF0000
	ldr r1, _080CA304 @ =0x000002EA
	adds r0, r6, r1
	ldrh r1, [r0]
	subs r1, #0x80
	lsls r1, r1, #0x10
	ldrh r0, [r2]
	orrs r0, r1
	str r0, [sp, #0x14]
	movs r2, #0xbb
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r4, #0xd5
	lsls r4, r4, #1
	adds r0, r4, #0
	ldrh r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x18]
	ands r1, r3
	orrs r1, r0
	str r1, [sp, #0x18]
	mov r1, ip
	ldr r0, [r1]
	movs r5, #1
	str r5, [sp]
	movs r4, #0
	str r4, [sp, #4]
	str r4, [sp, #8]
	ldr r2, _080CA308 @ =0x00001928
	adds r1, r6, r2
	ldrh r1, [r1]
	str r1, [sp, #0xc]
	str r4, [sp, #0x10]
	add r1, sp, #0x14
	movs r2, #0
	movs r3, #2
	bl FUN_0807ab64
	ldr r1, _080CA30C @ =FUN_080c789c
	movs r0, #7
	strb r0, [r7]
	adds r0, r6, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r4, [r0]
	adds r0, #0x1d
	strb r5, [r0]
	b _080CA420
	.align 2, 0
_080CA2F8: .4byte 0x03002BE0
_080CA2FC: .4byte 0xFFFFFF00
_080CA300: .4byte 0xFFFF0000
_080CA304: .4byte 0x000002EA
_080CA308: .4byte 0x00001928
_080CA30C: .4byte FUN_080c789c
_080CA310:
	adds r1, r6, #0
	adds r1, #0xa7
	ldrb r0, [r1]
	cmp r0, #0
	bne _080CA31C
	b _080CA420
_080CA31C:
	strb r5, [r1]
	ldr r1, _080CA330 @ =FUN_080c7518
	movs r0, #5
	strb r0, [r7]
	adds r0, r6, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r5, [r0]
	b _080CA3E4
	.align 2, 0
_080CA330: .4byte FUN_080c7518
_080CA334:
	cmp r0, #9
	bne _080CA358
	adds r0, r6, #0
	adds r0, #0xa7
	ldrb r0, [r0]
	cmp r0, #0
	beq _080CA420
	ldr r2, _080CA354 @ =FUN_080c6c8c
	movs r1, #0
	strb r1, [r3]
	adds r0, r6, #0
	adds r0, #0xf8
	str r2, [r0]
	subs r0, #0x6c
	str r1, [r0]
	b _080CA3E4
	.align 2, 0
_080CA354: .4byte FUN_080c6c8c
_080CA358:
	cmp r0, #0xa
	bne _080CA370
	adds r0, r6, #0
	adds r0, #0xa7
	ldrb r0, [r0]
	cmp r0, #0
	beq _080CA420
	ldr r1, _080CA36C @ =FUN_080c7b84
	movs r0, #9
	b _080CA3D6
	.align 2, 0
_080CA36C: .4byte FUN_080c7b84
_080CA370:
	cmp r0, #0xe
	bne _080CA394
	adds r0, r6, #0
	adds r0, #0xa7
	ldrb r0, [r0]
	cmp r0, #0
	beq _080CA420
	ldr r2, _080CA390 @ =FUN_080c6c8c
	movs r1, #0
	strb r1, [r3]
	adds r0, r6, #0
	adds r0, #0xf8
	str r2, [r0]
	subs r0, #0x6c
	str r1, [r0]
	b _080CA3E4
	.align 2, 0
_080CA390: .4byte FUN_080c6c8c
_080CA394:
	cmp r0, #0x1b
	bne _080CA3AC
	adds r0, r6, #0
	adds r0, #0xa7
	ldrb r0, [r0]
	cmp r0, #0
	beq _080CA420
	ldr r1, _080CA3A8 @ =FUN_080c8dac
	movs r0, #0x1c
	b _080CA3D6
	.align 2, 0
_080CA3A8: .4byte FUN_080c8dac
_080CA3AC:
	cmp r0, #0x1c
	bne _080CA3C4
	adds r0, r6, #0
	adds r0, #0xa7
	ldrb r0, [r0]
	cmp r0, #0
	beq _080CA420
	ldr r1, _080CA3C0 @ =FUN_080c8e14
	movs r0, #0x1d
	b _080CA3D6
	.align 2, 0
_080CA3C0: .4byte FUN_080c8e14
_080CA3C4:
	cmp r0, #0x1d
	bne _080CA3F4
	adds r0, r6, #0
	adds r0, #0xa7
	ldrb r0, [r0]
	cmp r0, #0
	beq _080CA420
	ldr r1, _080CA3F0 @ =FUN_080c8eb8
	movs r0, #0x1e
_080CA3D6:
	movs r2, #0
_080CA3D8:
	strb r0, [r3]
	adds r0, r6, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r2, [r0]
_080CA3E4:
	adds r1, r6, #0
	adds r1, #0xa9
	movs r0, #1
	strb r0, [r1]
	b _080CA420
	.align 2, 0
_080CA3F0: .4byte FUN_080c8eb8
_080CA3F4:
	cmp r0, #0x1e
	bne _080CA420
	adds r0, r6, #0
	adds r0, #0xa7
	ldrb r0, [r0]
	cmp r0, #0
	beq _080CA420
	ldr r4, _080CA428 @ =0x00001908
	adds r0, r6, r4
	movs r3, #0
	movs r2, #1
	strb r2, [r0]
	ldr r1, _080CA42C @ =FUN_080c73c0
	movs r0, #3
	strb r0, [r7]
	adds r0, r6, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r3, [r0]
	adds r0, #0x1d
	strb r2, [r0]
_080CA420:
	add sp, #0x1c
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080CA428: .4byte 0x00001908
_080CA42C: .4byte FUN_080c73c0
