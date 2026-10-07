	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _08081684 @ =0x0000094A
	adds r0, r4, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	bl FUN_080815f0
	adds r1, r0, #0
	adds r0, r4, #0
	bl FUN_080813d0
	adds r1, r4, #0
	adds r1, #0xa8
	ldr r2, _08081688 @ =0x00000604
	adds r0, r4, r2
	ldrh r0, [r0]
	ldrh r1, [r1]
	adds r0, r0, r1
	subs r2, #8
	adds r1, r4, r2
	strh r0, [r1]
	adds r1, r4, #0
	adds r1, #0xaa
	adds r2, #0xa
	adds r0, r4, r2
	ldrh r0, [r0]
	ldrh r1, [r1]
	adds r0, r0, r1
	subs r2, #8
	adds r1, r4, r2
	strh r0, [r1]
	adds r1, r4, #0
	adds r1, #0xac
	adds r2, #0xa
	adds r0, r4, r2
	ldrh r0, [r0]
	ldrh r1, [r1]
	adds r0, r0, r1
	movs r1, #0xc0
	lsls r1, r1, #3
	adds r4, r4, r1
	strh r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08081684: .4byte 0x0000094A
_08081688: .4byte 0x00000604
