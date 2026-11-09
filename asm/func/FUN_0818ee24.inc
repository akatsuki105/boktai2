	push {r4, r5, r6, lr}
	adds r6, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r5, [r0]
	ldr r0, _0818EE40 @ =0x00000F2F
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0818EE44
	subs r0, #1
	strb r0, [r1]
	b _0818EE88
	.align 2, 0
_0818EE40: .4byte 0x00000F2F
_0818EE44:
	movs r0, #0xc
	strb r0, [r1]
	ldr r1, _0818EE90 @ =0x00000F36
	adds r4, r5, r1
	movs r0, #0
	ldrsh r1, [r4, r0]
	subs r1, #1
	ldrh r0, [r4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	lsls r2, r0, #3
	adds r2, r2, r0
	lsls r2, r2, #3
	adds r2, r2, r0
	lsls r2, r2, #2
	adds r2, r2, r5
	ldr r0, _0818EE94 @ =0x00000674
	adds r2, r2, r0
	adds r0, r5, #0
	bl FUN_0818f844
	ldrh r1, [r4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x11
	ldr r0, _0818EE94 @ =0x00000674
	adds r2, r5, r0
	adds r0, r5, #0
	bl FUN_0818f844
	adds r0, r5, #0
	movs r1, #0
	adds r2, r6, #0
	bl FUN_0818f844
_0818EE88:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0818EE90: .4byte 0x00000F36
_0818EE94: .4byte 0x00000674
