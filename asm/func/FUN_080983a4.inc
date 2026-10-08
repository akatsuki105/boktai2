	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #1
	movs r2, #5
	movs r3, #3
	bl EntityCC28_DrawHP
	adds r0, r5, #0
	movs r1, #1
	movs r2, #5
	movs r3, #4
	bl EntityCC28_DrawEne
	ldr r6, _0809841C @ =0x030044E0
	ldrh r1, [r6]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08098484
	ldr r1, _08098420 @ =0x00001444
	adds r0, r5, r1
	adds r4, r5, #0
	adds r4, #0x60
	adds r1, r4, #0
	movs r2, #0x38
	movs r3, #1
	bl MainSprite_SetPose
	ldr r2, _08098424 @ =0x00001E64
	adds r0, r5, r2
	adds r1, r4, #0
	bl MainSprite_AdvanceAnim
	ldrh r1, [r6, #2]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08098496
	movs r0, #0xc0
	lsls r0, r0, #4
	adds r6, r5, r0
	ldrb r0, [r6]
	cmp r0, #1
	bls _08098496
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r0, [r0]
	ldr r2, _08098428 @ =0x00000285
	adds r0, r0, r2
	ldrb r4, [r0]
	cmp r4, #0
	beq _0809842C
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _08098496
	.align 2, 0
_0809841C: .4byte 0x030044E0
_08098420: .4byte 0x00001444
_08098424: .4byte 0x00001E64
_08098428: .4byte 0x00000285
_0809842C:
	ldr r0, _08098474 @ =0x0000010B
	bl PlaySound_082406e0
	ldr r0, _08098478 @ =0x00000C02
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrb r6, [r6]
	cmp r0, r6
	blt _08098448
	strb r4, [r1]
_08098448:
	ldr r2, _0809847C @ =0x00000C04
	adds r0, r5, r2
	ldr r2, [r0]
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	movs r0, #0x64
	muls r0, r1, r0
	adds r0, r5, r0
	ldr r1, _08098480 @ =0x00000C08
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r2]
	adds r0, r5, #0
	bl FUN_08097e3c
	adds r0, r5, #0
	bl FUN_0808de50
	b _08098496
	.align 2, 0
_08098474: .4byte 0x0000010B
_08098478: .4byte 0x00000C02
_0809847C: .4byte 0x00000C04
_08098480: .4byte 0x00000C08
_08098484:
	adds r0, r5, #0
	movs r1, #0
	bl FUN_08097fb4
	ldr r1, _0809849C @ =FUN_08098290
	adds r0, r5, #0
	movs r2, #0
	bl EntityCC28_SetState
_08098496:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809849C: .4byte FUN_08098290
