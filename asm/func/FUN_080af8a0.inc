	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _080AF900 @ =0x000006AC
	adds r0, r4, r1
	ldr r5, [r0]
	ldr r2, _080AF904 @ =0x0000068A
	adds r1, r4, r2
	movs r0, #0x10
	strh r0, [r1]
	movs r0, #0xc3
	lsls r0, r0, #3
	adds r2, r4, r0
	movs r1, #0xce
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _080AF908 @ =0x0000067A
	adds r3, r4, r2
	ldrh r0, [r3]
	adds r1, r0, #1
	strh r1, [r3]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _080AF938
	ldr r0, _080AF90C @ =0x0000061A
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #0x80
	strh r0, [r1]
	movs r1, #0xc1
	lsls r1, r1, #4
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080AF910
	ldrb r0, [r5, #0x1f]
	cmp r0, #0
	beq _080AF910
	adds r0, r4, #0
	movs r1, #2
	bl FUN_080af374
	b _080AF970
	.align 2, 0
_080AF900: .4byte 0x000006AC
_080AF904: .4byte 0x0000068A
_080AF908: .4byte 0x0000067A
_080AF90C: .4byte 0x0000061A
_080AF910:
	adds r0, r4, #0
	bl FUN_080af5b8
	ldr r2, _080AF934 @ =0x00000686
	adds r1, r4, r2
	movs r0, #0xe0
	lsls r0, r0, #1
	strh r0, [r1]
	movs r0, #0xd1
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r0, #0x60
	strh r0, [r1]
	adds r0, r4, #0
	movs r1, #3
	bl FUN_080af374
	b _080AF970
	.align 2, 0
_080AF934: .4byte 0x00000686
_080AF938:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bls _080AF960
	ldr r1, _080AF95C @ =0x0000061A
	adds r2, r4, r1
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r0, #0
	ldrh r0, [r2]
	adds r1, r1, r0
	ldrh r0, [r3]
	subs r0, #8
	lsls r0, r0, #4
	subs r1, r1, r0
	strh r1, [r2]
	b _080AF970
	.align 2, 0
_080AF95C: .4byte 0x0000061A
_080AF960:
	ldr r2, _080AF978 @ =0x0000061A
	adds r1, r4, r2
	ldrh r0, [r3]
	adds r0, #1
	lsls r0, r0, #5
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
_080AF970:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080AF978: .4byte 0x0000061A
