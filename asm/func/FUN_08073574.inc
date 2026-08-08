	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, _08073590 @ =0x0000037D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #5
	bls _08073584
	b _080736B0
_08073584:
	lsls r0, r0, #2
	ldr r1, _08073594 @ =_08073598
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08073590: .4byte 0x0000037D
_08073594: .4byte _08073598
_08073598: @ jump table
	.4byte _080735B0 @ case 0
	.4byte _08073600 @ case 1
	.4byte _0807362A @ case 2
	.4byte _0807360C @ case 3
	.4byte _0807366E @ case 4
	.4byte _080736A8 @ case 5
_080735B0:
	ldr r0, _080735FC @ =0x0000037E
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _080735C0
	movs r0, #0xd0
	bl PlaySound_082406e0
_080735C0:
	ldrh r0, [r4]
	cmp r0, #8
	bne _080735CC
	movs r0, #0xdb
	bl PlaySound_082406e0
_080735CC:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x30
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _080736B0
	adds r0, r5, #0
	movs r1, #0x12
	movs r2, #1
	bl FUN_08060b84
	b _08073666
	.align 2, 0
_080735FC: .4byte 0x0000037E
_08073600:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x31
	b _08073634
_0807360C:
	ldr r0, _08073644 @ =0x0000037E
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _0807361C
	movs r0, #0xd0
	bl PlaySound_082406e0
_0807361C:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bhi _08073648
_0807362A:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x32
_08073634:
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	b _080736B0
	.align 2, 0
_08073644: .4byte 0x0000037E
_08073648:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	adds r0, r5, #0
	bl FUN_08072620
_08073666:
	adds r0, r5, #0
	bl FUN_080726b4
	b _080736B0
_0807366E:
	ldr r0, _080736A4 @ =0x0000037E
	adds r4, r5, r0
	ldrh r0, [r4]
	movs r1, #7
	adds r2, r1, #0
	ands r2, r0
	lsrs r0, r0, #3
	subs r1, r1, r0
	cmp r2, r1
	blt _0807368A
	adds r0, r5, #0
	movs r1, #5
	bl FUN_08060c40
_0807368A:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x37
	bls _080736B0
	adds r0, r5, #0
	movs r1, #0x12
	movs r2, #5
	bl FUN_08060b84
	b _080736B0
	.align 2, 0
_080736A4: .4byte 0x0000037E
_080736A8:
	adds r0, r5, #0
	movs r1, #5
	bl FUN_08060c40
_080736B0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
