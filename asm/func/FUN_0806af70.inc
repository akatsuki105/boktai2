	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, _0806AF88 @ =0x0000037D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _0806AFF8
	cmp r0, #1
	bgt _0806AF8C
	cmp r0, #0
	beq _0806AF92
	b _0806B062
	.align 2, 0
_0806AF88: .4byte 0x0000037D
_0806AF8C:
	cmp r0, #2
	beq _0806B03E
	b _0806B062
_0806AF92:
	ldr r1, _0806AFC4 @ =0x0000037E
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _0806AFD2
	movs r0, #0xd6
	lsls r0, r0, #2
	adds r4, r5, r0
	ldrb r0, [r4]
	movs r1, #0x29
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldrb r0, [r4]
	cmp r0, #5
	bne _0806AFCC
	ldr r0, _0806AFC8 @ =0x000002EE
	bl PlaySound_082406e0
	b _0806AFD2
	.align 2, 0
_0806AFC4: .4byte 0x0000037E
_0806AFC8: .4byte 0x000002EE
_0806AFCC:
	ldr r0, _0806AFF0 @ =0x00000301
	bl PlaySound_082406e0
_0806AFD2:
	ldr r0, _0806AFF4 @ =0x0000037E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bls _0806B062
	adds r0, r5, #0
	movs r1, #0x1e
	movs r2, #1
	bl FUN_08060b84
	b _0806B062
	.align 2, 0
_0806AFF0: .4byte 0x00000301
_0806AFF4: .4byte 0x0000037E
_0806AFF8:
	adds r0, r5, #0
	adds r0, #0x9c
	ldrh r1, [r0]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	bne _0806B016
	adds r0, r5, #0
	adds r0, #0x94
	ldrh r0, [r0]
	cmp r0, #0
	bne _0806B016
	movs r0, #0xd1
	bl PlaySound_082406e0
_0806B016:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x2e
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _0806B062
	adds r0, r5, #0
	movs r1, #0x1e
	movs r2, #2
	bl FUN_08060b84
	b _0806B062
_0806B03E:
	ldr r0, _0806B068 @ =0x0000037E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _0806B062
	adds r0, r5, #0
	movs r1, #0x1e
	movs r2, #3
	bl FUN_08060b84
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08060e90
_0806B062:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806B068: .4byte 0x0000037E
