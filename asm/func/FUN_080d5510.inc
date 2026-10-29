	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #2
	beq _080D5534
	adds r0, r4, #0
	movs r1, #2
	movs r2, #0
	bl PlayerLink_SetAction
	ldr r0, [r4, #0x18]
	movs r1, #0xd1
	lsls r1, r1, #2
	bl Sound_PlayForPlayer
_080D5534:
	adds r0, r4, #0
	movs r1, #8
	bl FUN_080cc3c4
	ldr r0, _080D555C @ =0x0000037E
	adds r5, r4, r0
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _080D5560
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl PlayerLink_SetAction
	b _080D55C8
	.align 2, 0
_080D555C: .4byte 0x0000037E
_080D5560:
	adds r0, r4, #0
	movs r1, #2
	bl FUN_080cc3c4
	ldrh r0, [r5]
	subs r0, #5
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _080D557C
	adds r0, r4, #0
	movs r1, #1
	bl FUN_080cc3c4
_080D557C:
	adds r0, r4, #0
	movs r1, #4
	bl FUN_080cc3c4
	ldr r0, _080D55D0 @ =0x0000095E
	adds r1, r4, r0
	ldr r0, _080D55D4 @ =0x00000127
	strh r0, [r1]
	movs r0, #0x96
	lsls r0, r0, #4
	adds r1, r4, r0
	movs r0, #0x18
	strh r0, [r1]
	movs r1, #0xe9
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080D55AA
	adds r0, r4, #0
	movs r1, #0x20
	bl FUN_080cc268
_080D55AA:
	adds r0, r4, #0
	bl PlayerLink_SetAnimFacing
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #1
	bl Player_GetAnimIdx
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl PlayerLink_PlayAnim
_080D55C8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D55D0: .4byte 0x0000095E
_080D55D4: .4byte 0x00000127
