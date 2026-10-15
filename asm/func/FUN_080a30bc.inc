	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #6
	bhi _080A30D8
	adds r0, #1
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_080a2804
	b _080A30F8
_080A30D8:
	ldr r0, _080A3100 @ =0x00000382
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _080A30F8
	ldr r0, _080A3104 @ =0x0000015F
	bl PlaySound_082406e0
	ldr r1, _080A3108 @ =FUN_080a310c
	adds r0, r4, #0
	bl FUN_080a2a14
_080A30F8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A3100: .4byte 0x00000382
_080A3104: .4byte 0x0000015F
_080A3108: .4byte FUN_080a310c
