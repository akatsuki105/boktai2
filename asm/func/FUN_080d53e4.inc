	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #4
	bl FUN_080cc3c4
	ldr r1, _080D5404 @ =0x0000037D
	adds r0, r5, r1
	ldrb r4, [r0]
	cmp r4, #1
	beq _080D5458
	cmp r4, #1
	bgt _080D5408
	cmp r4, #0
	beq _080D5412
	b _080D5504
	.align 2, 0
_080D5404: .4byte 0x0000037D
_080D5408:
	cmp r4, #2
	beq _080D5494
	cmp r4, #3
	beq _080D54E4
	b _080D5504
_080D5412:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x29
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl PlayerLink_PlayAnim
	ldr r1, _080D5450 @ =0x000003F6
	adds r0, r5, r1
	strh r4, [r0]
	str r4, [r5, #0x3c]
	adds r0, r5, #0
	adds r0, #0x2c
	ldr r1, [r5, #0x18]
	bl FUN_081df64c
	ldr r0, [r5, #0x18]
	ldr r1, _080D5454 @ =0x000001AD
	bl Sound_PlayForPlayer
	adds r0, r5, #0
	movs r1, #0x1c
	movs r2, #1
	bl PlayerLink_SetAction
	b _080D5504
	.align 2, 0
_080D5450: .4byte 0x000003F6
_080D5454: .4byte 0x000001AD
_080D5458:
	ldr r0, _080D5488 @ =0x0000037E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bls _080D5504
	ldr r0, _080D548C @ =0x000003F6
	adds r1, r5, r0
	movs r0, #0
	strh r0, [r1]
	ldr r0, [r5, #0x18]
	ldr r1, _080D5490 @ =0x000001AF
	bl Sound_PlayForPlayer
	adds r0, r5, #0
	movs r1, #0x1c
	movs r2, #2
	bl PlayerLink_SetAction
	b _080D5504
	.align 2, 0
_080D5488: .4byte 0x0000037E
_080D548C: .4byte 0x000003F6
_080D5490: .4byte 0x000001AF
_080D5494:
	adds r0, r5, #0
	movs r1, #0x2c
	movs r2, #0x40
	bl PlayerLink_PlayAnim
	ldr r1, _080D54DC @ =0x000003F6
	adds r2, r5, r1
	ldrh r0, [r2]
	subs r0, #0x1e
	movs r3, #0
	strh r0, [r2]
	ldr r0, _080D54E0 @ =0x0000037E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #8
	bls _080D5504
	movs r1, #0xd9
	lsls r1, r1, #2
	adds r0, r5, r1
	strh r3, [r0]
	strh r3, [r2]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080cc3c4
	adds r0, r5, #0
	movs r1, #0x1c
	movs r2, #3
	bl PlayerLink_SetAction
	b _080D5504
	.align 2, 0
_080D54DC: .4byte 0x000003F6
_080D54E0: .4byte 0x0000037E
_080D54E4:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080cc3c4
	ldr r0, _080D550C @ =0x0000037E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3b
	bls _080D5504
	adds r0, r5, #0
	bl FUN_080d05e8
_080D5504:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D550C: .4byte 0x0000037E
