	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _0806F204 @ =0x0000037D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _0806F27C
	cmp r0, #1
	bgt _0806F208
	cmp r0, #0
	beq _0806F212
	b _0806F27C
	.align 2, 0
_0806F204: .4byte 0x0000037D
_0806F208:
	cmp r0, #2
	beq _0806F238
	cmp r0, #3
	beq _0806F274
	b _0806F27C
_0806F212:
	ldr r0, _0806F230 @ =0x0000039E
	bl PlaySound_082406e0
	ldr r1, _0806F234 @ =0x00000193
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	adds r0, r4, #0
	movs r1, #0x1f
	movs r2, #1
	bl FUN_08060b84
	b _0806F27C
	.align 2, 0
_0806F230: .4byte 0x0000039E
_0806F234: .4byte 0x00000193
_0806F238:
	ldr r0, _0806F270 @ =0x0000037E
	adds r5, r4, r0
	ldrh r0, [r5]
	movs r1, #7
	adds r2, r1, #0
	ands r2, r0
	lsrs r0, r0, #3
	subs r1, r1, r0
	cmp r2, r1
	blt _0806F254
	adds r0, r4, #0
	movs r1, #5
	bl FUN_08060c40
_0806F254:
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x37
	bls _0806F27C
	adds r0, r4, #0
	movs r1, #0x1f
	movs r2, #3
	bl FUN_08060b84
	b _0806F27C
	.align 2, 0
_0806F270: .4byte 0x0000037E
_0806F274:
	adds r0, r4, #0
	movs r1, #5
	bl FUN_08060c40
_0806F27C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
