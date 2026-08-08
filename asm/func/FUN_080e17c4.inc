	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x24]
	cmp r0, #0
	bne _080E17D6
	adds r0, r4, #0
	bl FUN_080e173c
	b _080E17E8
_080E17D6:
	ldrh r0, [r4, #0x26]
	ldrh r1, [r4, #0x24]
	bl Mod
	cmp r0, #0
	bne _080E17E8
	adds r0, r4, #0
	bl FUN_080e173c
_080E17E8:
	ldrh r0, [r4, #0x26]
	adds r0, #1
	strh r0, [r4, #0x26]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
