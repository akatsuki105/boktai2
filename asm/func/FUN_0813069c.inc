	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	adds r0, r4, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081307A6
	movs r2, #0x10
	movs r3, #0xcc
	lsls r3, r3, #3
	adds r1, r5, r3
	ldrh r0, [r1]
	ands r0, r2
	adds r6, r1, #0
	cmp r0, #0
	beq _081306CA
	movs r0, #1
	b _081306CC
_081306CA:
	movs r0, #0
_081306CC:
	cmp r0, #0
	beq _081307A6
	movs r1, #0x20
	ldr r0, _081306E8 @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _081306EC @ =0x00000934
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081306F0
	movs r0, #1
	b _081306F2
	.align 2, 0
_081306E8: .4byte 0x030046A0
_081306EC: .4byte 0x00000934
_081306F0:
	movs r0, #0
_081306F2:
	cmp r0, #0
	beq _08130780
	movs r1, #8
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _08130704
	movs r0, #1
	b _08130706
_08130704:
	movs r0, #0
_08130706:
	adds r5, r0, #0
	cmp r5, #0
	bne _08130768
	adds r0, r4, #0
	bl Enemy_StepTowardPathNode
	movs r1, #7
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r4, r3
	strb r5, [r0]
	ldr r2, _08130770 @ =0x00000469
	adds r0, r4, r2
	strb r5, [r0]
	adds r3, #2
	adds r0, r4, r3
	strb r1, [r0]
	ldr r1, _08130774 @ =0x00000484
	adds r0, r4, r1
	str r5, [r0]
	adds r2, #3
	adds r0, r4, r2
	movs r1, #1
	strb r1, [r0]
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r4, r3
	ldr r2, [r0]
	ldr r3, _08130778 @ =0x0000046D
	adds r0, r4, r3
	strb r1, [r0]
	subs r3, #2
	adds r0, r4, r3
	strb r5, [r0]
	adds r3, #0xe8
	adds r0, r4, r3
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r4, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r4, r2
	strh r5, [r0]
	ldrh r1, [r6]
	movs r0, #8
	orrs r0, r1
	strh r0, [r6]
_08130768:
	ldr r3, _0813077C @ =0x00000482
	adds r1, r4, r3
	movs r0, #5
	b _081307A4
	.align 2, 0
_08130770: .4byte 0x00000469
_08130774: .4byte 0x00000484
_08130778: .4byte 0x0000046D
_0813077C: .4byte 0x00000482
_08130780:
	movs r1, #8
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _0813078E
	movs r0, #1
	b _08130790
_0813078E:
	movs r0, #0
_08130790:
	cmp r0, #0
	beq _081307A6
	movs r0, #9
	rsbs r0, r0, #0
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	ldr r0, _081307AC @ =0x00000482
	adds r1, r4, r0
	movs r0, #1
_081307A4:
	strh r0, [r1]
_081307A6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081307AC: .4byte 0x00000482
