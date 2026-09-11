	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080a7b80
	adds r0, r4, #0
	bl FUN_080a7c64
	ldr r0, _080A7DB8 @ =0x00000206
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _080A7DB0
	ldr r0, [r4, #0x70]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x70]
	ldr r0, _080A7DBC @ =0x00000133
	bl PlaySound_082406e0
	ldr r1, _080A7DC0 @ =FUN_080a7dc4
	adds r0, r4, #0
	bl FUN_080a7b68
_080A7DB0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A7DB8: .4byte 0x00000206
_080A7DBC: .4byte 0x00000133
_080A7DC0: .4byte FUN_080a7dc4
