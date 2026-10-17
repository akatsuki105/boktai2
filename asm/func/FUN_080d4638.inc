	push {r4, r5, lr}
	sub sp, #0x14
	adds r4, r0, #0
	movs r1, #4
	bl FUN_080cc3c4
	ldr r1, _080D465C @ =0x0000037D
	adds r0, r4, r1
	ldrb r5, [r0]
	cmp r5, #1
	bne _080D4650
	b _080D475C
_080D4650:
	cmp r5, #1
	bgt _080D4660
	cmp r5, #0
	beq _080D466E
	b _080D4820
	.align 2, 0
_080D465C: .4byte 0x0000037D
_080D4660:
	cmp r5, #2
	bne _080D4666
	b _080D479C
_080D4666:
	cmp r5, #3
	bne _080D466C
	b _080D4810
_080D466C:
	b _080D4820
_080D466E:
	ldr r0, [r4, #0x2c]
	ldr r1, [r4, #0x30]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	ldr r2, [sp, #0xc]
	asrs r1, r2, #0x10
	adds r1, #0x96
	lsls r1, r1, #0x10
	ldr r0, _080D46B4 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0xc]
	add r0, sp, #0xc
	bl FUN_0823bac8
	movs r2, #0xfc
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _080D46BC
	movs r0, #4
	str r0, [sp]
	ldr r0, _080D46B8 @ =0x00001FFF
	str r0, [sp, #4]
	movs r0, #0x10
	str r0, [sp, #8]
	movs r0, #3
	movs r1, #3
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	b _080D46D4
	.align 2, 0
_080D46B4: .4byte 0x0000FFFF
_080D46B8: .4byte 0x00001FFF
_080D46BC:
	movs r0, #4
	str r0, [sp]
	ldr r0, _080D4704 @ =0x00001FFF
	str r0, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	movs r0, #3
	movs r1, #3
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
_080D46D4:
	ldr r0, [r4, #0x18]
	ldr r1, _080D4708 @ =0x000001AD
	bl Sound_PlayForPlayer
	movs r0, #0xba
	lsls r0, r0, #2
	adds r2, r4, r0
	ldrb r0, [r2]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _080D4714
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _080D470C @ =0x000002E6
	adds r1, r4, r2
	strb r0, [r1]
	ldr r0, _080D4710 @ =0x000002E7
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	b _080D4724
	.align 2, 0
_080D4704: .4byte 0x00001FFF
_080D4708: .4byte 0x000001AD
_080D470C: .4byte 0x000002E6
_080D4710: .4byte 0x000002E7
_080D4714:
	lsrs r1, r1, #0x19
	ldr r2, _080D4750 @ =0x000002E6
	adds r0, r4, r2
	movs r2, #0
	strb r1, [r0]
	ldr r1, _080D4754 @ =0x000002E7
	adds r0, r4, r1
	strb r2, [r0]
_080D4724:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	movs r1, #0x29
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl PlayerLink_PlayAnim
	adds r0, r4, #0
	movs r1, #0x16
	movs r2, #1
	bl PlayerLink_SetAction
	ldr r0, _080D4758 @ =0x000003F6
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	b _080D4820
	.align 2, 0
_080D4750: .4byte 0x000002E6
_080D4754: .4byte 0x000002E7
_080D4758: .4byte 0x000003F6
_080D475C:
	ldr r2, _080D4794 @ =0x0000037E
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bls _080D4820
	adds r0, r4, #0
	movs r1, #0x16
	movs r2, #2
	bl PlayerLink_SetAction
	ldr r0, _080D4798 @ =0x000003F6
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xef
	strb r5, [r0]
	ldr r0, [r4, #0x18]
	movs r1, #0xd7
	lsls r1, r1, #1
	bl Sound_PlayForPlayer
	b _080D4820
	.align 2, 0
_080D4794: .4byte 0x0000037E
_080D4798: .4byte 0x000003F6
_080D479C:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r5, r4, r1
	ldrb r0, [r5]
	movs r1, #0x12
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl PlayerLink_PlayAnim
	ldr r2, _080D47D8 @ =0x000003F6
	adds r1, r4, r2
	ldrh r0, [r1]
	subs r0, #0x3c
	strh r0, [r1]
	ldr r1, _080D47DC @ =0x0000037E
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #4
	bne _080D47E8
	ldrb r0, [r5]
	cmp r0, #5
	bne _080D47E0
	ldr r0, [r4, #0x18]
	subs r1, #0x91
	bl Sound_PlayForPlayer
	b _080D47E8
	.align 2, 0
_080D47D8: .4byte 0x000003F6
_080D47DC: .4byte 0x0000037E
_080D47E0:
	ldr r0, [r4, #0x18]
	ldr r1, _080D4808 @ =0x00000305
	bl Sound_PlayForPlayer
_080D47E8:
	ldr r2, _080D480C @ =0x0000037E
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1d
	bls _080D4820
	adds r0, r4, #0
	movs r1, #0x16
	movs r2, #3
	bl PlayerLink_SetAction
	b _080D4820
	.align 2, 0
_080D4808: .4byte 0x00000305
_080D480C: .4byte 0x0000037E
_080D4810:
	ldr r0, _080D4828 @ =0x000003F6
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_080cc3c4
_080D4820:
	add sp, #0x14
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D4828: .4byte 0x000003F6
