	push {r4, r5, lr}
	adds r5, r0, #0
	adds r0, #0x58
	adds r1, r5, #0
	adds r1, #0x18
	bl MainSprite_AdvanceAnim
	ldr r0, _080B4F44 @ =0x00000844
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0x20
	bne _080B4F28
	movs r0, #0xb0
	lsls r0, r0, #2
	bl PlaySound_082406e0
_080B4F28:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x68
	bls _080B4F3C
	adds r0, r5, #0
	bl FUN_080b4ba4
_080B4F3C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B4F44: .4byte 0x00000844
