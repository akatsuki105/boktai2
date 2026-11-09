	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r4, [r0]
	ldr r0, _08165248 @ =0x000003BF
	bl PlaySound_082406e0
	movs r2, #0x90
	lsls r2, r2, #3
	adds r0, r6, r2
	ldrh r0, [r0]
	cmp r0, #3
	bne _08165200
	adds r0, r6, #0
	bl Slime_ShootDroplets
_08165200:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r6, r3
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r5, #0xcb
	lsls r5, r5, #3
	adds r1, r4, r5
	ldrh r0, [r1]
	adds r0, #0x50
	strh r0, [r1]
	movs r7, #0xd1
	lsls r7, r7, #3
	adds r0, r4, r7
	ldrh r0, [r0]
	adds r5, r2, #0
	cmp r0, #0
	beq _0816526E
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r3, _0816524C @ =0x00000546
	adds r0, r6, r3
	ldrh r0, [r0]
	cmp r1, r0
	bge _08165250
	adds r0, r6, #0
	bl Slime_Split
	b _0816526E
	.align 2, 0
_08165248: .4byte 0x000003BF
_0816524C: .4byte 0x00000546
_08165250:
	ldr r2, _081652E0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081652E4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r7, _081652E8 @ =0x0203B400
	adds r0, r0, r7
	ldrb r0, [r0]
	cmp r0, #0x18
	bgt _0816526E
	adds r0, r6, #0
	bl Slime_Split
_0816526E:
	ldr r1, _081652EC @ =0x0000049C
	adds r0, r6, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xb
	ands r0, r1
	cmp r0, #0
	beq _08165308
	movs r2, #0xc1
	lsls r2, r2, #1
	adds r3, r6, r2
	ldr r1, _081652F0 @ =0xFFFFF67F
	ldrh r0, [r3]
	ands r1, r0
	movs r2, #0
	movs r5, #0
	strh r1, [r3]
	ldr r3, _081652F4 @ =0x000005CC
	adds r0, r6, r3
	ldr r3, [r0]
	movs r1, #0x12
	ldr r4, _081652F8 @ =0x0000046D
	adds r0, r6, r4
	movs r4, #1
	strb r4, [r0]
	ldr r7, _081652FC @ =0x0000046B
	adds r0, r6, r7
	strb r2, [r0]
	adds r7, #0xe8
	adds r0, r6, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r6, r3
	strh r5, [r0]
	movs r1, #3
	subs r7, #0xeb
	adds r0, r6, r7
	strb r1, [r0]
	ldr r1, _08165300 @ =0x00000469
	adds r0, r6, r1
	strb r2, [r0]
	ldr r3, _08165304 @ =0x0000046A
	adds r0, r6, r3
	strb r2, [r0]
	adds r7, #0x1c
	adds r0, r6, r7
	str r5, [r0]
	adds r1, #3
	adds r0, r6, r1
	strb r4, [r0]
	b _08165436
	.align 2, 0
_081652E0: .4byte 0x030046B8
_081652E4: .4byte 0x000003FF
_081652E8: .4byte 0x0203B400
_081652EC: .4byte 0x0000049C
_081652F0: .4byte 0xFFFFF67F
_081652F4: .4byte 0x000005CC
_081652F8: .4byte 0x0000046D
_081652FC: .4byte 0x0000046B
_08165300: .4byte 0x00000469
_08165304: .4byte 0x0000046A
_08165308:
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r0, [r5]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _0816531C
	movs r0, #0
	b _08165438
_0816531C:
	ldr r3, _08165358 @ =0x00000544
	adds r1, r6, r3
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r1]
	movs r5, #0x95
	lsls r5, r5, #3
	adds r0, r6, r5
	ldr r0, [r0]
	strh r2, [r0, #6]
	movs r7, #0xc2
	lsls r7, r7, #1
	adds r0, r6, r7
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r3, #2
	adds r0, r6, r3
	ldrh r0, [r0]
	cmp r1, r0
	blt _08165368
	movs r1, #8
	ldr r5, _0816535C @ =0x0000068E
	adds r0, r4, r5
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08165360
	movs r0, #1
	b _08165362
	.align 2, 0
_08165358: .4byte 0x00000544
_0816535C: .4byte 0x0000068E
_08165360:
	movs r0, #0
_08165362:
	adds r3, r0, #0
	cmp r3, #0
	beq _081653DC
_08165368:
	ldr r3, _081653C4 @ =Enemy_ClearStateBegun
	movs r1, #0x10
	ldr r7, _081653C8 @ =0x0000046D
	adds r0, r6, r7
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r5, _081653CC @ =0x0000046B
	adds r0, r6, r5
	strb r2, [r0]
	adds r7, #0xe6
	adds r0, r6, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r6, r3
	movs r1, #0
	strh r2, [r0]
	movs r3, #2
	subs r5, #3
	adds r0, r6, r5
	strb r1, [r0]
	subs r7, #0xea
	adds r0, r6, r7
	strb r1, [r0]
	ldr r1, _081653D0 @ =0x0000046A
	adds r0, r6, r1
	strb r3, [r0]
	ldr r3, _081653D4 @ =0x00000484
	adds r0, r6, r3
	str r2, [r0]
	adds r5, #4
	adds r0, r6, r5
	strb r4, [r0]
	movs r7, #0xc1
	lsls r7, r7, #1
	adds r2, r6, r7
	ldr r0, _081653D8 @ =0xFFFFF67F
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _08165436
	.align 2, 0
_081653C4: .4byte Enemy_ClearStateBegun
_081653C8: .4byte 0x0000046D
_081653CC: .4byte 0x0000046B
_081653D0: .4byte 0x0000046A
_081653D4: .4byte 0x00000484
_081653D8: .4byte 0xFFFFF67F
_081653DC:
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r0, [r0]
	ldr r1, _08165440 @ =0x00FFFFFF
	ands r0, r1
	cmp r0, #0
	beq _08165436
	ldr r2, _08165444 @ =0x000005A4
	adds r0, r6, r2
	ldr r1, [r0]
	ldr r4, _08165448 @ =0x0000046D
	adds r0, r6, r4
	movs r2, #1
	strb r2, [r0]
	ldr r5, _0816544C @ =0x0000046B
	adds r0, r6, r5
	strb r3, [r0]
	ldr r7, _08165450 @ =0x00000553
	adds r0, r6, r7
	strb r3, [r0]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r0, r6, r4
	str r1, [r0]
	movs r5, #0xe4
	lsls r5, r5, #1
	adds r0, r6, r5
	movs r1, #0
	strh r3, [r0]
	subs r7, #0xeb
	adds r0, r6, r7
	strb r1, [r0]
	ldr r4, _08165454 @ =0x00000469
	adds r0, r6, r4
	strb r1, [r0]
	ldr r5, _08165458 @ =0x0000046A
	adds r0, r6, r5
	strb r1, [r0]
	adds r7, #0x1c
	adds r0, r6, r7
	str r3, [r0]
	ldr r1, _0816545C @ =0x0000046C
	adds r0, r6, r1
	strb r2, [r0]
_08165436:
	movs r0, #1
_08165438:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08165440: .4byte 0x00FFFFFF
_08165444: .4byte 0x000005A4
_08165448: .4byte 0x0000046D
_0816544C: .4byte 0x0000046B
_08165450: .4byte 0x00000553
_08165454: .4byte 0x00000469
_08165458: .4byte 0x0000046A
_0816545C: .4byte 0x0000046C
