	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r0, #0x9e
	lsls r0, r0, #4
	adds r6, r4, r0
	ldr r0, [r6]
	cmp r0, #0
	bne _0808E236
	b _0808E3F0
_0808E236:
	ldr r1, _0808E2C8 @ =0x000009FE
	adds r5, r4, r1
	ldrb r0, [r5]
	cmp r0, #2
	bls _0808E242
	b _0808E3F0
_0808E242:
	adds r0, r4, #0
	movs r1, #0
	movs r2, #3
	movs r3, #1
	bl FUN_0808a610
	adds r0, r4, #0
	movs r1, #0
	movs r2, #3
	movs r3, #2
	bl FUN_0808a768
	adds r0, r4, #0
	bl FUN_0808e1f4
	adds r0, r4, #0
	bl FUN_0808afac
	ldrb r1, [r5]
	adds r0, r4, #0
	bl FUN_0808abec
	adds r0, r4, #0
	bl FUN_0808b1bc
	adds r0, r4, #0
	bl FUN_0808e17c
	adds r0, r4, #0
	bl FUN_0808e1b8
	ldr r1, [r6]
	movs r2, #0xa0
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bge _0808E294
	b _0808E3F0
_0808E294:
	ldr r3, _0808E2CC @ =0x00000282
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0808E334
	ldr r1, _0808E2D0 @ =0x00000C03
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0808E2DC
	ldr r2, _0808E2D4 @ =0x00000C02
	adds r0, r4, r2
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #0x64
	muls r0, r1, r0
	adds r0, r0, r4
	ldr r3, _0808E2D8 @ =0x00000C0C
	adds r0, r0, r3
	adds r1, r4, #0
	adds r1, #0xa0
	movs r2, #0xc8
	movs r3, #1
	bl MainSprite_SetPose
	b _0808E310
	.align 2, 0
_0808E2C8: .4byte 0x000009FE
_0808E2CC: .4byte 0x00000282
_0808E2D0: .4byte 0x00000C03
_0808E2D4: .4byte 0x00000C02
_0808E2D8: .4byte 0x00000C0C
_0808E2DC:
	cmp r0, #0x1e
	bne _0808E310
	ldr r1, _0808E328 @ =0x00000C02
	adds r0, r4, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #0x64
	adds r2, r1, #0
	muls r2, r0, r2
	adds r0, r2, r4
	ldr r3, _0808E32C @ =0x00000C0C
	adds r0, r0, r3
	adds r1, r4, #0
	adds r1, #0xa0
	adds r2, r4, r2
	subs r3, #3
	adds r2, r2, r3
	ldrb r2, [r2]
	lsls r2, r2, #0x18
	asrs r2, r2, #0x18
	adds r2, #0xb6
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r3, #1
	bl MainSprite_SetPose
_0808E310:
	ldr r0, _0808E330 @ =0x00000C03
	adds r1, r4, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x3b
	bls _0808E3F0
	movs r0, #0
	strb r0, [r1]
	b _0808E3F0
	.align 2, 0
_0808E328: .4byte 0x00000C02
_0808E32C: .4byte 0x00000C0C
_0808E330: .4byte 0x00000C03
_0808E334:
	ldr r2, _0808E384 @ =0x00000283
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0808E3C0
	ldr r3, _0808E388 @ =0x000009EE
	adds r1, r4, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r2, _0808E38C @ =0x0000FFFF
	adds r1, r2, #0
	ands r0, r1
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0808E398
	ldr r3, _0808E390 @ =0x00000C02
	adds r0, r4, r3
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #0x64
	adds r2, r1, #0
	muls r2, r0, r2
	adds r0, r2, r4
	ldr r1, _0808E394 @ =0x00000C0C
	adds r0, r0, r1
	adds r1, r4, #0
	adds r1, #0xa0
	adds r2, r4, r2
	adds r3, #7
	adds r2, r2, r3
	ldrb r2, [r2]
	lsls r2, r2, #0x18
	asrs r2, r2, #0x18
	adds r2, #0xb6
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	b _0808E3B0
	.align 2, 0
_0808E384: .4byte 0x00000283
_0808E388: .4byte 0x000009EE
_0808E38C: .4byte 0x0000FFFF
_0808E390: .4byte 0x00000C02
_0808E394: .4byte 0x00000C0C
_0808E398:
	ldr r1, _0808E3B8 @ =0x00000C02
	adds r0, r4, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #0x64
	muls r0, r1, r0
	adds r0, r0, r4
	ldr r2, _0808E3BC @ =0x00000C0C
	adds r0, r0, r2
	adds r1, r4, #0
	adds r1, #0xa0
	movs r2, #0xc9
_0808E3B0:
	movs r3, #1
	bl MainSprite_SetPose
	b _0808E3F0
	.align 2, 0
_0808E3B8: .4byte 0x00000C02
_0808E3BC: .4byte 0x00000C0C
_0808E3C0:
	ldr r3, _0808E3F8 @ =0x00000C02
	adds r0, r4, r3
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #0x64
	adds r2, r1, #0
	muls r2, r0, r2
	adds r0, r2, r4
	ldr r1, _0808E3FC @ =0x00000C0C
	adds r0, r0, r1
	adds r1, r4, #0
	adds r1, #0xa0
	adds r2, r4, r2
	adds r3, #7
	adds r2, r2, r3
	ldrb r2, [r2]
	lsls r2, r2, #0x18
	asrs r2, r2, #0x18
	adds r2, #0xb6
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r3, #1
	bl MainSprite_SetPose
_0808E3F0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808E3F8: .4byte 0x00000C02
_0808E3FC: .4byte 0x00000C0C
