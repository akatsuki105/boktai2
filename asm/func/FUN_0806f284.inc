	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #2
	beq _0806F2CE
	movs r0, #0xda
	lsls r0, r0, #2
	adds r5, r4, r0
	ldrh r0, [r5]
	cmp r0, #0
	beq _0806F2BC
	ldr r0, _0806F2B8 @ =0x00000392
	bl PlaySound_082406e0
	ldrh r0, [r5]
	subs r0, #1
	strh r0, [r5]
	adds r0, r4, #0
	movs r1, #2
	movs r2, #0
	bl FUN_08060b84
	b _0806F2CE
	.align 2, 0
_0806F2B8: .4byte 0x00000392
_0806F2BC:
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	adds r0, r4, #0
	movs r1, #2
	movs r2, #1
	bl FUN_08060b84
_0806F2CE:
	ldr r1, _0806F2E0 @ =0x0000037D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0806F2E4
	cmp r0, #1
	beq _0806F360
	b _0806F394
	.align 2, 0
_0806F2E0: .4byte 0x0000037D
_0806F2E4:
	ldr r0, _0806F304 @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r2, r0, #1
	strh r2, [r1]
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _0806F308
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
	b _0806F394
	.align 2, 0
_0806F304: .4byte 0x0000037E
_0806F308:
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _0806F322
	ldr r0, _0806F358 @ =0x0000095E
	adds r1, r4, r0
	ldr r0, _0806F35C @ =0x00000125
	strh r0, [r1]
	movs r0, #0x96
	lsls r0, r0, #4
	adds r1, r4, r0
	movs r0, #0x20
	strh r0, [r1]
_0806F322:
	movs r1, #0xe9
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0806F336
	adds r0, r4, #0
	movs r1, #0x20
	bl FUN_08060aa4
_0806F336:
	adds r0, r4, #0
	bl FUN_080609dc
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #1
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	b _0806F394
	.align 2, 0
_0806F358: .4byte 0x0000095E
_0806F35C: .4byte 0x00000125
_0806F360:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r0, _0806F39C @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bls _0806F394
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_0806F394:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806F39C: .4byte 0x0000037E
