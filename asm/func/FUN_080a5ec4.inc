	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r0, #0x9a
	ldrh r0, [r0]
	cmp r0, #0
	bne _080A5ED6
	ldr r0, _080A5F38 @ =0x000002C2
	bl PlaySound_082406e0
_080A5ED6:
	adds r0, r4, #0
	adds r0, #0x4c
	ldrh r0, [r0]
	subs r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bhi _080A5EF8
	adds r0, r4, #0
	adds r0, #0x44
	ldrh r0, [r0]
	cmp r0, #0
	bne _080A5EF8
	movs r0, #0x87
	lsls r0, r0, #2
	bl PlaySound_082406e0
_080A5EF8:
	adds r1, r4, #0
	adds r1, #0x9a
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	adds r5, r4, #0
	adds r5, #0x38
	adds r6, r4, #0
	adds r6, #0x18
	adds r0, r5, #0
	adds r1, r6, #0
	bl MainSprite_AdvanceAnim
	cmp r0, #0
	beq _080A5F30
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #0x24
	movs r3, #1
	bl MainSprite_SetPose
	ldr r1, _080A5F3C @ =FUN_080a5f40
	adds r0, r4, #0
	bl EntityCF58_SetUpdateCallback
	adds r0, r4, #0
	bl FUN_080a5ea4
_080A5F30:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A5F38: .4byte 0x000002C2
_080A5F3C: .4byte FUN_080a5f40
