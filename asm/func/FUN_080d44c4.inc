	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x11
	beq _080D4528
	movs r2, #0xe4
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _080D44F0
	ldr r0, _080D44EC @ =0x000003FA
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	b _080D451E
	.align 2, 0
_080D44EC: .4byte 0x000003FA
_080D44F0:
	adds r0, r4, #0
	movs r1, #3
	bl FUN_080ced68
	adds r1, r0, #0
	cmp r1, #0
	beq _080D4518
	ldr r1, _080D4514 @ =0x000003FA
	adds r0, r4, r1
	movs r1, #1
	strb r1, [r0]
	adds r1, r4, #0
	adds r1, #0x2c
	adds r0, r4, #0
	movs r2, #0
	bl Entity080a8ff8_Create
	b _080D451E
	.align 2, 0
_080D4514: .4byte 0x000003FA
_080D4518:
	ldr r2, _080D453C @ =0x000003FA
	adds r0, r4, r2
	strb r1, [r0]
_080D451E:
	adds r0, r4, #0
	movs r1, #0x11
	movs r2, #0
	bl PlayerLink_SetAction
_080D4528:
	ldr r1, _080D4540 @ =0x0000037D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _080D45A4
	cmp r0, #1
	bgt _080D4544
	cmp r0, #0
	beq _080D454E
	b _080D4630
	.align 2, 0
_080D453C: .4byte 0x000003FA
_080D4540: .4byte 0x0000037D
_080D4544:
	cmp r0, #2
	beq _080D45DC
	cmp r0, #3
	beq _080D4618
	b _080D4630
_080D454E:
	ldr r2, _080D458C @ =0x000003FA
	adds r5, r4, r2
	ldrb r0, [r5]
	cmp r0, #0
	beq _080D456A
	ldr r0, _080D4590 @ =0x0000095E
	adds r1, r4, r0
	ldr r0, _080D4594 @ =0x00000123
	strh r0, [r1]
	movs r2, #0x96
	lsls r2, r2, #4
	adds r1, r4, r2
	movs r0, #0x20
	strh r0, [r1]
_080D456A:
	adds r0, r4, #0
	movs r1, #0xb8
	movs r2, #0x40
	bl PlayerLink_PlayAnim
	cmp r0, #0
	beq _080D4630
	ldrb r0, [r5]
	cmp r0, #0
	beq _080D4598
	adds r0, r4, #0
	movs r1, #0x11
	movs r2, #1
	bl PlayerLink_SetAction
	b _080D4630
	.align 2, 0
_080D458C: .4byte 0x000003FA
_080D4590: .4byte 0x0000095E
_080D4594: .4byte 0x00000123
_080D4598:
	adds r0, r4, #0
	movs r1, #0x11
	movs r2, #2
	bl PlayerLink_SetAction
	b _080D4630
_080D45A4:
	ldr r1, _080D45CC @ =0x000003FA
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080D45C0
	ldr r2, _080D45D0 @ =0x0000095E
	adds r1, r4, r2
	ldr r0, _080D45D4 @ =0x00000123
	strh r0, [r1]
	movs r0, #0x96
	lsls r0, r0, #4
	adds r1, r4, r0
	movs r0, #0x20
	strh r0, [r1]
_080D45C0:
	ldr r2, _080D45D8 @ =0x0000037E
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _080D4600
	.align 2, 0
_080D45CC: .4byte 0x000003FA
_080D45D0: .4byte 0x0000095E
_080D45D4: .4byte 0x00000123
_080D45D8: .4byte 0x0000037E
_080D45DC:
	ldr r0, _080D4614 @ =0x0000037E
	adds r5, r4, r0
	ldrh r0, [r5]
	cmp r0, #0
	bne _080D45F0
	ldr r0, [r4, #0x18]
	movs r1, #0xc9
	lsls r1, r1, #1
	bl Sound_PlayForPlayer
_080D45F0:
	adds r0, r4, #0
	movs r1, #0xc2
	movs r2, #0x40
	bl PlayerLink_PlayAnim
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
_080D4600:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb
	bls _080D4630
	adds r0, r4, #0
	movs r1, #0x11
	movs r2, #3
	bl PlayerLink_SetAction
	b _080D4630
	.align 2, 0
_080D4614: .4byte 0x0000037E
_080D4618:
	adds r0, r4, #0
	movs r1, #0xbd
	movs r2, #0x40
	bl PlayerLink_PlayAnim
	cmp r0, #0
	beq _080D4630
	adds r0, r4, #0
	movs r1, #0
	movs r2, #1
	bl PlayerLink_SetAction
_080D4630:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
