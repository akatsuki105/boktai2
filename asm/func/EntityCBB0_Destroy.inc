	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x1a]
	cmp r0, #0
	bne _080B26F4
	movs r1, #0xaf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _080B270E
	subs r1, #0x68
	adds r0, r4, r1
	bl FUN_0822a4e0
	b _080B270E
_080B26F4:
	ldr r1, _080B2728 @ =0x00000C6C
	adds r0, r4, r1
	bl FUN_080b0ab4
	movs r1, #0xa3
	lsls r1, r1, #3
	adds r0, r4, r1
	bl FUN_0822a4e0
	movs r0, #1
	movs r1, #1
	bl SetBGPrioDirect
_080B270E:
	adds r0, r4, #0
	bl FUN_080ad368
	adds r0, r4, #0
	bl FUN_080b23fc
	ldr r1, _080B272C @ =0x03002C58
	movs r0, #0
	str r0, [r1]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080B2728: .4byte 0x00000C6C
_080B272C: .4byte 0x03002C58
