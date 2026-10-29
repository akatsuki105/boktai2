	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r7, r0, #0
	adds r4, r7, #0
	bl Entity5DA5_AreAllLit
	adds r2, r0, #0
	cmp r2, #0
	bne _08024850
	b _080249C6
_08024850:
	movs r1, #0xac
	lsls r1, r1, #1
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #0xa3
	bls _0802485E
	b _080249B0
_0802485E:
	adds r2, r7, #0
	adds r2, #0x48
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #0xa3
	bhi _0802489E
	movs r3, #8
	ldrsh r0, [r2, r3]
	movs r3, #0xee
	lsls r3, r3, #3
	adds r1, r7, r3
	movs r3, #0
	ldrsh r1, [r1, r3]
	subs r0, r0, r1
	cmp r0, #0
	bge _08024880
	rsbs r0, r0, #0
_08024880:
	cmp r0, #0x3f
	bgt _0802489E
	movs r1, #0xc
	ldrsh r0, [r2, r1]
	ldr r2, _080248CC @ =0x00000774
	adds r1, r7, r2
	movs r3, #0
	ldrsh r1, [r1, r3]
	subs r0, r0, r1
	cmp r0, #0
	bge _08024898
	rsbs r0, r0, #0
_08024898:
	movs r1, #1
	cmp r0, #0x3f
	ble _080248A0
_0802489E:
	movs r1, #0
_080248A0:
	cmp r1, #0
	beq _080248EE
	ldr r1, _080248D0 @ =0x00000553
	adds r0, r7, r1
	ldr r2, _080248D4 @ =0x0000077C
	adds r1, r7, r2
	ldrb r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	blo _080248D8
	movs r0, #7
	adds r2, r4, #0
	adds r2, #0xa6
	movs r1, #0
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0xbc
	str r1, [r0]
	adds r1, r4, #0
	adds r1, #0xa8
	b _08024B5C
	.align 2, 0
_080248CC: .4byte 0x00000774
_080248D0: .4byte 0x00000553
_080248D4: .4byte 0x0000077C
_080248D8:
	movs r0, #6
	adds r2, r4, #0
	adds r2, #0xa6
	movs r1, #0
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0xbc
	str r1, [r0]
	adds r1, r4, #0
	adds r1, #0xa8
	b _08024B5C
_080248EE:
	movs r3, #0xee
	lsls r3, r3, #3
	adds r2, r7, r3
	mov sl, r7
	movs r0, #0
	ldrsh r1, [r2, r0]
	ldr r0, _08024904 @ =0x0000011F
	cmp r1, r0
	bgt _08024908
	adds r0, #1
	b _08024910
	.align 2, 0
_08024904: .4byte 0x0000011F
_08024908:
	movs r0, #0xbe
	lsls r0, r0, #4
	cmp r1, r0
	ble _08024912
_08024910:
	strh r0, [r2]
_08024912:
	movs r3, #4
	ldrsh r1, [r2, r3]
	ldr r0, _08024920 @ =0x0000021F
	cmp r1, r0
	bgt _08024924
	adds r0, #1
	b _0802492C
	.align 2, 0
_08024920: .4byte 0x0000021F
_08024924:
	movs r0, #0xce
	lsls r0, r0, #4
	cmp r1, r0
	ble _0802492E
_0802492C:
	strh r0, [r2, #4]
_0802492E:
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r3, #2
	ldrsh r1, [r2, r3]
	movs r3, #4
	ldrsh r4, [r2, r3]
	adds r3, r7, #0
	adds r3, #0xcc
	movs r6, #0
	strh r0, [r3]
	adds r0, r7, #0
	adds r0, #0xce
	strh r1, [r0]
	adds r2, r7, #0
	adds r2, #0xd0
	strh r4, [r2]
	movs r0, #0xdc
	adds r0, r0, r7
	mov r8, r0
	strb r6, [r0]
	adds r1, r7, #0
	adds r1, #0x48
	movs r0, #0
	ldrsh r5, [r3, r0]
	movs r3, #8
	ldrsh r0, [r1, r3]
	subs r5, r5, r0
	movs r0, #0
	ldrsh r4, [r2, r0]
	movs r2, #0xc
	ldrsh r0, [r1, r2]
	subs r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl ArcTan2_8
	adds r1, r7, #0
	adds r1, #0xd8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [r1]
	adds r2, r7, #0
	adds r2, #0xd4
	adds r0, r5, #0
	muls r0, r5, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r0, r1
	str r0, [r2]
	movs r1, #1
	mov r3, r8
	strb r1, [r3]
	mov r0, sl
	adds r0, #0xa4
	strb r6, [r0]
	adds r0, #1
	strb r6, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #0x16
	movs r2, #0
	str r2, [r0]
	subs r0, #0x14
	strb r1, [r0]
	b _08024B60
_080249B0:
	movs r0, #5
	adds r2, r7, #0
	adds r2, #0xa6
	movs r1, #0
	strb r0, [r2]
	adds r0, r7, #0
	adds r0, #0xbc
	str r1, [r0]
	adds r1, r7, #0
	adds r1, #0xa8
	b _08024B5C
_080249C6:
	ldr r3, _080249DC @ =0x0000054C
	adds r0, r7, r3
	ldrb r3, [r0]
	cmp r3, #0
	beq _080249E0
	movs r0, #2
	adds r1, r7, #0
	adds r1, #0xa6
	strb r0, [r1]
	adds r0, r7, #0
	b _08024B56
	.align 2, 0
_080249DC: .4byte 0x0000054C
_080249E0:
	movs r1, #0xac
	lsls r1, r1, #1
	adds r0, r7, r1
	ldrh r1, [r0]
	ldr r0, _08024A24 @ =0x000002FF
	cmp r1, r0
	bls _080249F0
	b _08024B08
_080249F0:
	ldr r2, _08024A28 @ =0x00000165
	adds r0, r7, r2
	ldrb r1, [r0]
	adds r1, #2
	movs r0, #3
	ands r1, r0
	movs r2, #0xc0
	lsls r2, r2, #2
	mov r0, sp
	bl Duneyrr_GetQuadrantPos
	mov r3, sp
	mov sb, r7
	mov sl, r7
	mov r0, sp
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, _08024A2C @ =0x0000011F
	cmp r1, r0
	bgt _08024A30
	movs r1, #0x90
	lsls r1, r1, #1
	mov r0, sp
	strh r1, [r0]
	b _08024A3C
	.align 2, 0
_08024A24: .4byte 0x000002FF
_08024A28: .4byte 0x00000165
_08024A2C: .4byte 0x0000011F
_08024A30:
	movs r2, #0xbe
	lsls r2, r2, #4
	cmp r1, r2
	ble _08024A3C
	mov r0, sp
	strh r2, [r0]
_08024A3C:
	movs r0, #4
	ldrsh r1, [r3, r0]
	ldr r0, _08024A4C @ =0x0000021F
	cmp r1, r0
	bgt _08024A50
	adds r0, #1
	b _08024A58
	.align 2, 0
_08024A4C: .4byte 0x0000021F
_08024A50:
	movs r0, #0xce
	lsls r0, r0, #4
	cmp r1, r0
	ble _08024A5A
_08024A58:
	strh r0, [r3, #4]
_08024A5A:
	movs r1, #0
	ldrsh r0, [r3, r1]
	movs r2, #2
	ldrsh r1, [r3, r2]
	movs r2, #4
	ldrsh r4, [r3, r2]
	mov r3, sl
	adds r3, #0xcc
	movs r6, #0
	strh r0, [r3]
	mov r0, sl
	adds r0, #0xce
	strh r1, [r0]
	mov r2, sl
	adds r2, #0xd0
	strh r4, [r2]
	movs r0, #0xdc
	add r0, sl
	mov r8, r0
	strb r6, [r0]
	mov r1, sl
	adds r1, #0x48
	movs r0, #0
	ldrsh r5, [r3, r0]
	movs r3, #8
	ldrsh r0, [r1, r3]
	subs r5, r5, r0
	movs r0, #0
	ldrsh r4, [r2, r0]
	movs r2, #0xc
	ldrsh r0, [r1, r2]
	subs r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl ArcTan2_8
	mov r1, sl
	adds r1, #0xd8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [r1]
	mov r2, sl
	adds r2, #0xd4
	adds r0, r5, #0
	muls r0, r5, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r0, r1
	str r0, [r2]
	movs r1, #1
	mov r3, r8
	strb r1, [r3]
	mov r0, sb
	adds r0, #0xa4
	strb r6, [r0]
	adds r0, #1
	strb r6, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #0x16
	movs r2, #0
	str r2, [r0]
	subs r0, #0x14
	strb r1, [r0]
	adds r0, r7, #0
	adds r0, #0xdd
	ldrb r0, [r0]
	cmp r0, #0x5f
	bgt _08024B60
	bl Entity08058ffc_GetActiveCount
	movs r1, #0
	cmp r0, #5
	bgt _08024AFA
	bl FUN_08059210
	movs r1, #4
	cmp r0, #0
	bne _08024AFA
	movs r1, #6
_08024AFA:
	ldr r3, _08024B04 @ =0x00000551
	adds r0, r7, r3
	strb r1, [r0]
	b _08024B60
	.align 2, 0
_08024B04: .4byte 0x00000551
_08024B08:
	adds r0, r7, #0
	adds r0, #0x9c
	ldrb r2, [r0]
	cmp r2, #0
	beq _08024B4C
	ldr r1, _08024B24 @ =0x00000554
	adds r0, r7, r1
	ldrb r1, [r0]
	movs r0, #7
	ands r0, r1
	cmp r0, #0
	bne _08024B28
	movs r0, #8
	b _08024B2A
	.align 2, 0
_08024B24: .4byte 0x00000554
_08024B28:
	movs r0, #2
_08024B2A:
	adds r1, r7, #0
	adds r1, #0xa6
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0xbc
	str r3, [r0]
	adds r1, #2
	movs r0, #1
	strb r0, [r1]
	ldr r2, _08024B48 @ =0x00000554
	adds r1, r7, r2
	ldrb r0, [r1]
	adds r0, #1
	b _08024B5E
	.align 2, 0
_08024B48: .4byte 0x00000554
_08024B4C:
	movs r0, #2
	adds r1, r4, #0
	adds r1, #0xa6
	strb r0, [r1]
	adds r0, r4, #0
_08024B56:
	adds r0, #0xbc
	str r2, [r0]
	adds r1, #2
_08024B5C:
	movs r0, #1
_08024B5E:
	strb r0, [r1]
_08024B60:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
