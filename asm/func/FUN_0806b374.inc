	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #2
	beq _0806B396
	adds r0, r4, #0
	movs r1, #2
	movs r2, #0
	bl FUN_08060b84
	movs r0, #0xd1
	lsls r0, r0, #2
	bl PlaySound_082406e0
_0806B396:
	adds r0, r4, #0
	movs r1, #8
	bl FUN_08060c40
	ldr r0, _0806B3BC @ =0x0000037E
	adds r5, r4, r0
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _0806B3C0
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
	b _0806B428
	.align 2, 0
_0806B3BC: .4byte 0x0000037E
_0806B3C0:
	adds r0, r4, #0
	movs r1, #2
	bl FUN_08060c40
	ldrh r0, [r5]
	subs r0, #5
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _0806B3DC
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08060c40
_0806B3DC:
	adds r0, r4, #0
	movs r1, #4
	bl FUN_08060c40
	ldr r0, _0806B430 @ =0x0000095E
	adds r1, r4, r0
	ldr r0, _0806B434 @ =0x00000127
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
	bne _0806B40A
	adds r0, r4, #0
	movs r1, #0x20
	bl FUN_08060aa4
_0806B40A:
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
_0806B428:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806B430: .4byte 0x0000095E
_0806B434: .4byte 0x00000127
