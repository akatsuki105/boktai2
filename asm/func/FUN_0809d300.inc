	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r0, #0xf7
	lsls r0, r0, #4
	adds r3, r6, r0
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #0
	bge _0809D338
	movs r2, #0xd6
	lsls r2, r2, #3
	adds r1, r6, r2
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	movs r0, #0x83
	lsls r0, r0, #4
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xfa
	lsls r0, r0, #3
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r2
	b _0809D3C2
_0809D338:
	movs r1, #0xd6
	lsls r1, r1, #3
	adds r2, r6, r1
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r0, [r6, #0x18]
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #2
	bne _0809D366
	movs r2, #0xd5
	lsls r2, r2, #3
	adds r0, r6, r2
	adds r1, r6, #0
	adds r1, #0x48
	movs r2, #0x3c
	movs r3, #1
	bl MainSprite_SetPose
	b _0809D388
_0809D366:
	movs r0, #0xd5
	lsls r0, r0, #3
	adds r4, r6, r0
	adds r5, r6, #0
	adds r5, #0x48
	movs r0, #0
	ldrsb r0, [r3, r0]
	bl GetWeaponID
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	adds r1, r5, #0
	movs r3, #1
	bl MainSprite_SetPose
_0809D388:
	movs r2, #0x83
	lsls r2, r2, #4
	adds r1, r6, r2
	ldr r0, [r1]
	movs r4, #2
	rsbs r4, r4, #0
	ands r0, r4
	str r0, [r1]
	ldr r1, _0809D3CC @ =0x00000848
	adds r0, r6, r1
	movs r2, #0xf7
	lsls r2, r2, #4
	adds r1, r6, r2
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	bl FUN_0809d240
	movs r0, #0xfa
	lsls r0, r0, #3
	adds r1, r6, r0
	ldr r0, [r1]
	ands r0, r4
	str r0, [r1]
	movs r2, #0xdd
	lsls r2, r2, #4
	adds r1, r6, r2
	ldr r0, [r1]
	ands r0, r4
_0809D3C2:
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809D3CC: .4byte 0x00000848
