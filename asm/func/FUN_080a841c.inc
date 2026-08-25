	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	adds r5, r7, #0
	adds r5, #0x62
	ldrh r0, [r5]
	cmp r0, #0
	bne _080A8430
	b _080A85E6
_080A8430:
	adds r4, r7, #0
	adds r4, #0x60
	ldrh r3, [r4]
	mov r8, r4
	cmp r3, #1
	bne _080A84F8
	adds r6, r7, #0
	adds r6, #0x64
	adds r4, #0x20
	movs r5, #7
_080A8444:
	ldrh r0, [r4, #0x38]
	cmp r0, #0
	beq _080A8452
	ldr r1, [r7, #0x7c]
	adds r0, r4, #0
	bl FUN_080a8314
_080A8452:
	adds r4, #0x3c
	subs r5, #1
	cmp r5, #0
	bge _080A8444
	ldrh r2, [r6]
	lsls r1, r2, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0x3f
	bhi _080A8480
	movs r0, #3
	ands r0, r2
	cmp r0, #0
	bne _080A8480
	lsrs r1, r1, #0x12
	movs r0, #7
	ands r1, r0
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, #0x80
	adds r0, r7, r0
	bl FUN_080a8250
_080A8480:
	ldrh r0, [r6]
	adds r0, #1
	movs r2, #0
	strh r0, [r6]
	ldr r0, _080A84B4 @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r7, #0x34]
	str r1, [r7, #0x38]
	ldrh r0, [r6]
	cmp r0, #0x77
	bhi _080A84B8
	adds r0, r7, #0
	adds r0, #0x18
	strh r2, [r0, #0x10]
	ldrh r0, [r6]
	cmp r0, #4
	bhi _080A8538
	ldrh r0, [r7, #0x36]
	adds r0, #0xfa
	ldrh r2, [r6]
	lsls r1, r2, #4
	subs r1, r1, r2
	lsls r1, r1, #1
	b _080A858C
	.align 2, 0
_080A84B4: .4byte 0x03002BE0
_080A84B8:
	cmp r0, #0x7a
	bhi _080A84CE
	movs r1, #0xc8
	lsls r1, r1, #1
	adds r0, r1, #0
	ldrh r1, [r7, #0x36]
	adds r0, r0, r1
	strh r0, [r7, #0x36]
	movs r0, #1
	strh r0, [r7, #0x28]
	b _080A85E6
_080A84CE:
	cmp r0, #0x7d
	bhi _080A84E4
	movs r1, #0xc8
	lsls r1, r1, #1
	adds r0, r1, #0
	ldrh r1, [r7, #0x36]
	adds r0, r0, r1
	strh r0, [r7, #0x36]
	movs r0, #2
	strh r0, [r7, #0x28]
	b _080A85E6
_080A84E4:
	ldr r0, [r7, #0x18]
	movs r1, #1
	orrs r0, r1
	str r0, [r7, #0x18]
	adds r0, r7, #0
	adds r0, #0x62
	strh r2, [r0]
	mov r0, r8
	strh r2, [r0]
	b _080A85E6
_080A84F8:
	cmp r3, #2
	bne _080A85D8
	adds r2, r7, #0
	adds r2, #0x64
	ldrh r0, [r2]
	adds r0, #1
	movs r6, #0
	strh r0, [r2]
	ldr r0, _080A8534 @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r7, #0x34]
	str r1, [r7, #0x38]
	ldrh r0, [r2]
	cmp r0, #0x77
	bhi _080A85A0
	movs r0, #3
	strh r0, [r7, #0x28]
	ldrh r0, [r2]
	cmp r0, #4
	bhi _080A8538
	ldrh r0, [r7, #0x36]
	adds r0, #0xfa
	ldrh r2, [r2]
	lsls r1, r2, #4
	subs r1, r1, r2
	lsls r1, r1, #1
	b _080A858C
	.align 2, 0
_080A8534: .4byte 0x03002BE0
_080A8538:
	cmp r0, #0x13
	bhi _080A8584
	ldr r5, _080A8594 @ =0x0203B400
	ldr r6, _080A8598 @ =0x030046B8
	ldr r1, [r6]
	adds r1, #1
	ldr r3, _080A859C @ =0x000003FF
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r5
	ldrh r2, [r0]
	ldrh r0, [r7, #0x34]
	subs r0, #0xf
	movs r4, #0x1f
	ands r2, r4
	adds r0, r0, r2
	strh r0, [r7, #0x34]
	adds r1, #1
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r5
	ldrh r2, [r0]
	ldrh r0, [r7, #0x36]
	subs r0, #0xf
	ands r2, r4
	adds r0, r0, r2
	strh r0, [r7, #0x36]
	adds r1, #1
	ands r1, r3
	str r1, [r6]
	lsls r1, r1, #1
	adds r1, r1, r5
	ldrh r1, [r1]
	ldrh r0, [r7, #0x38]
	subs r0, #0xf
	ands r1, r4
	adds r0, r0, r1
	strh r0, [r7, #0x38]
_080A8584:
	movs r1, #0xc8
	lsls r1, r1, #1
	adds r0, r1, #0
	ldrh r1, [r7, #0x36]
_080A858C:
	adds r0, r0, r1
	strh r0, [r7, #0x36]
	b _080A85E6
	.align 2, 0
_080A8594: .4byte 0x0203B400
_080A8598: .4byte 0x030046B8
_080A859C: .4byte 0x000003FF
_080A85A0:
	cmp r0, #0x7a
	bhi _080A85B6
	movs r1, #0xc8
	lsls r1, r1, #1
	adds r0, r1, #0
	ldrh r1, [r7, #0x36]
	adds r0, r0, r1
	strh r0, [r7, #0x36]
	movs r0, #4
	strh r0, [r7, #0x28]
	b _080A85E6
_080A85B6:
	cmp r0, #0x7d
	bhi _080A85CA
	movs r1, #0xc8
	lsls r1, r1, #1
	adds r0, r1, #0
	ldrh r1, [r7, #0x36]
	adds r0, r0, r1
	strh r0, [r7, #0x36]
	strh r3, [r7, #0x28]
	b _080A85E6
_080A85CA:
	ldr r0, [r7, #0x18]
	movs r1, #1
	orrs r0, r1
	str r0, [r7, #0x18]
	strh r6, [r5]
	strh r6, [r4]
	b _080A85E6
_080A85D8:
	ldr r0, [r7, #0x18]
	movs r1, #1
	orrs r0, r1
	str r0, [r7, #0x18]
	movs r0, #0
	strh r0, [r5]
	strh r0, [r4]
_080A85E6:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
