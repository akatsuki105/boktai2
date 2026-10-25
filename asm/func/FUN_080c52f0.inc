	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	ldrh r0, [r5, #4]
	cmp r0, #0
	bne _080C5308
	movs r0, #0x8b
	lsls r0, r0, #2
	bl PlaySound_082406e0
_080C5308:
	ldrh r0, [r5, #4]
	adds r0, #1
	strh r0, [r5, #4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _080C53B0
	movs r0, #0xff
	mov r8, r0
	movs r1, #0x97
	lsls r1, r1, #3
	adds r6, r5, r1
	ldr r2, _080C5358 @ =gSineTable
	mov sb, r2
	adds r4, r5, #0
	adds r4, #0x50
	movs r0, #0
	mov ip, r0
	adds r3, r5, #0
	adds r3, #8
	movs r7, #0xd
_080C5332:
	ldrh r0, [r5, #4]
	lsls r0, r0, #4
	mov r1, ip
	adds r2, r0, r1
	mov r0, r8
	ands r2, r0
	ldr r0, [r3]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3]
	ldrb r0, [r5, #2]
	cmp r0, #0
	bne _080C535C
	ldr r1, [r6]
	ldrh r0, [r4]
	ldrh r1, [r1]
	adds r0, r0, r1
	b _080C5364
	.align 2, 0
_080C5358: .4byte gSineTable
_080C535C:
	ldr r0, [r6]
	ldrh r0, [r0]
	ldrh r1, [r4]
	subs r0, r0, r1
_080C5364:
	strh r0, [r3, #0x1c]
	ldrb r0, [r4, #4]
	mov r1, r8
	ands r2, r1
	lsls r1, r2, #1
	add r1, sb
	movs r2, #0
	ldrsh r1, [r1, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _080C537E
	asrs r1, r0, #0xc
	b _080C5384
_080C537E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080C5384:
	ldr r0, [r6]
	ldrh r0, [r0, #4]
	adds r0, r0, r1
	strh r0, [r3, #0x20]
	adds r4, #0x50
	movs r0, #0xc
	add ip, r0
	adds r3, #0x50
	subs r7, #1
	cmp r7, #0
	bge _080C5332
	ldrh r0, [r5, #4]
	cmp r0, #0x27
	bls _080C544C
	ldr r1, _080C53AC @ =FUN_080c5458
	adds r0, r5, #0
	bl FUN_080c52e0
	b _080C544C
	.align 2, 0
_080C53AC: .4byte FUN_080c5458
_080C53B0:
	ldrh r0, [r5, #4]
	movs r1, #0x16
	muls r0, r1, r0
	adds r0, #0x60
	mov r8, r0
	movs r1, #0x97
	lsls r1, r1, #3
	adds r6, r5, r1
	ldr r2, _080C53F8 @ =gSineTable
	mov sb, r2
	movs r0, #0
	mov ip, r0
	adds r4, r5, #0
	adds r4, #0x50
	adds r3, r5, #0
	adds r3, #8
	movs r7, #0xd
_080C53D2:
	ldrh r0, [r4]
	ldr r1, _080C53FC @ =0xFFFFFD44
	adds r0, r0, r1
	mov r1, r8
	adds r2, r1, r0
	cmp r2, #0x5f
	ble _080C5436
	ldr r0, [r3]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3]
	ldrb r0, [r5, #2]
	cmp r0, #0
	bne _080C5400
	ldr r0, [r6]
	ldrh r0, [r0]
	adds r0, r0, r2
	b _080C5406
	.align 2, 0
_080C53F8: .4byte gSineTable
_080C53FC: .4byte 0xFFFFFD44
_080C5400:
	ldr r0, [r6]
	ldrh r0, [r0]
	subs r0, r0, r2
_080C5406:
	strh r0, [r3, #0x1c]
	ldrh r0, [r5, #4]
	lsls r0, r0, #4
	add r0, ip
	ldrb r2, [r4, #4]
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _080C5426
	asrs r2, r0, #0xc
	b _080C542C
_080C5426:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080C542C:
	ldr r0, [r6]
	ldrh r0, [r0, #4]
	adds r0, r0, r2
	strh r0, [r3, #0x20]
	b _080C543E
_080C5436:
	ldr r0, [r3]
	movs r1, #1
	orrs r0, r1
	str r0, [r3]
_080C543E:
	movs r2, #0xc
	add ip, r2
	adds r4, #0x50
	adds r3, #0x50
	subs r7, #1
	cmp r7, #0
	bge _080C53D2
_080C544C:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
