	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r3, [r0]
	ldr r0, [r4, #0x44]
	adds r6, r0, #0
	adds r6, #0x48
	ldr r2, _08156308 @ =0x00000482
	adds r1, r4, r2
	movs r0, #4
	strh r0, [r1]
	ldr r0, _0815630C @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08156310
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08156312
	.align 2, 0
_08156308: .4byte 0x00000482
_0815630C: .4byte 0x0000046D
_08156310:
	movs r0, #0
_08156312:
	cmp r0, #0
	beq _0815631E
	adds r0, r4, #0
	bl Cockatrice_TryFire
	b _0815643A
_0815631E:
	movs r2, #0x40
	movs r0, #0xe0
	lsls r0, r0, #3
	adds r1, r3, r0
	ldr r0, [r1]
	ands r0, r2
	adds r5, r1, #0
	cmp r0, #0
	beq _08156334
	movs r0, #1
	b _08156336
_08156334:
	movs r0, #0
_08156336:
	cmp r0, #0
	beq _0815637E
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	ldr r0, _0815638C @ =0x0000FFFF
	cmp r1, r0
	bhi _0815637E
	adds r0, r4, #0
	bl Cockatrice_FleeToPathNode
	movs r1, #0x41
	rsbs r1, r1, #0
	ldr r0, [r5]
	ands r0, r1
	str r0, [r5]
	movs r2, #0x13
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r4, r3
	movs r1, #0
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r2, [r0]
	ldr r2, _08156390 @ =0x00000484
	adds r0, r4, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
_0815637E:
	movs r1, #2
	ldr r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _08156394
	movs r0, #1
	b _08156396
	.align 2, 0
_0815638C: .4byte 0x0000FFFF
_08156390: .4byte 0x00000484
_08156394:
	movs r0, #0
_08156396:
	cmp r0, #0
	beq _081563D0
	movs r1, #4
	ldr r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _081563A8
	movs r0, #1
	b _081563AA
_081563A8:
	movs r0, #0
_081563AA:
	cmp r0, #0
	beq _08156434
	adds r0, r4, #0
	movs r1, #0x11
	bl Enemy_PlayAnim
	ldrh r0, [r6, #8]
	cmp r0, #0
	bne _08156434
	ldrh r0, [r6, #0xe]
	cmp r0, #0
	bne _08156434
	ldr r0, _081563CC @ =0x000001D1
	bl PlaySound_082406e0
	b _08156434
	.align 2, 0
_081563CC: .4byte 0x000001D1
_081563D0:
	movs r1, #0x40
	ldr r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _081563DE
	movs r0, #1
	b _081563E0
_081563DE:
	movs r0, #0
_081563E0:
	cmp r0, #0
	beq _0815642C
	adds r0, r4, #0
	movs r1, #0
	bl Enemy_PlayAnim
	adds r0, r4, #0
	bl Cockatrice_FleeToPathNode
	movs r1, #0x41
	rsbs r1, r1, #0
	ldr r0, [r5]
	ands r0, r1
	str r0, [r5]
	movs r2, #0x13
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _08156424 @ =0x00000469
	adds r0, r4, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r2, [r0]
	ldr r2, _08156428 @ =0x00000484
	adds r0, r4, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
	b _08156434
	.align 2, 0
_08156424: .4byte 0x00000469
_08156428: .4byte 0x00000484
_0815642C:
	adds r0, r4, #0
	movs r1, #1
	bl Enemy_PlayAnim
_08156434:
	adds r0, r4, #0
	bl Cockatrice_TryEndFlee
_0815643A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
