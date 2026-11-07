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
	beq _08140336
	b _081404B0
_08140336:
	movs r2, #2
	movs r3, #0xcb
	lsls r3, r3, #3
	adds r1, r5, r3
	ldr r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _0814034C
	movs r0, #1
	b _0814034E
_0814034C:
	movs r0, #0
_0814034E:
	cmp r0, #0
	beq _0814036C
	ldr r6, _08140368 @ =0x00000662
	adds r1, r5, r6
	movs r2, #0xdf
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r4, #0xa]
	b _081404B0
	.align 2, 0
_08140368: .4byte 0x00000662
_0814036C:
	movs r3, #0xdf
	lsls r3, r3, #1
	adds r0, r4, r3
	movs r6, #0
	ldrsh r1, [r0, r6]
	ldr r0, _0814038C @ =0x00000103
	cmp r1, r0
	bgt _081403E4
	movs r1, #1
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08140390
	movs r0, #1
	b _08140392
	.align 2, 0
_0814038C: .4byte 0x00000103
_08140390:
	movs r0, #0
_08140392:
	cmp r0, #0
	beq _081403A4
	ldr r1, _081403A0 @ =0x00000472
	adds r0, r4, r1
	ldrh r0, [r0]
	strh r0, [r4, #0xa]
	b _081404B0
	.align 2, 0
_081403A0: .4byte 0x00000472
_081403A4:
	ldr r1, _081403BC @ =gSineTable
	ldr r2, _081403C0 @ =0x00000666
	adds r0, r5, r2
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	blt _081403C4
	asrs r2, r0, #9
	b _081403CA
	.align 2, 0
_081403BC: .4byte gSineTable
_081403C0: .4byte 0x00000666
_081403C4:
	rsbs r0, r0, #0
	asrs r0, r0, #9
	rsbs r2, r0, #0
_081403CA:
	movs r6, #0xdf
	lsls r6, r6, #1
	adds r1, r4, r6
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldr r0, _08140410 @ =0x00000666
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0x3f
	bhi _081403E4
	adds r0, #1
	strb r0, [r1]
_081403E4:
	ldr r1, _08140414 @ =0x00000472
	adds r0, r4, r1
	ldrh r1, [r0]
	movs r2, #0xa
	ldrsh r0, [r4, r2]
	ldr r3, _08140418 @ =0xFFFFFEFC
	adds r0, r0, r3
	subs r1, r1, r0
	adds r0, r1, #0
	cmp r1, #0
	bge _081403FC
	rsbs r0, r1, #0
_081403FC:
	cmp r0, #0x10
	ble _08140428
	cmp r1, #0
	bge _0814041C
	movs r6, #0xdf
	lsls r6, r6, #1
	adds r1, r4, r6
	ldrh r0, [r1]
	subs r0, #2
	b _08140426
	.align 2, 0
_08140410: .4byte 0x00000666
_08140414: .4byte 0x00000472
_08140418: .4byte 0xFFFFFEFC
_0814041C:
	movs r0, #0xdf
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #2
_08140426:
	strh r0, [r1]
_08140428:
	ldr r1, _08140470 @ =0x00000472
	adds r3, r4, r1
	ldr r2, _08140474 @ =0x0000066E
	adds r0, r5, r2
	ldrh r1, [r3]
	ldrh r0, [r0]
	cmp r1, r0
	beq _08140446
	movs r6, #0xdf
	lsls r6, r6, #1
	adds r2, r4, r6
	subs r1, r1, r0
	ldrh r0, [r2]
	subs r0, r0, r1
	strh r0, [r2]
_08140446:
	movs r1, #0xdf
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r0, [r0]
	ldrh r3, [r3]
	adds r0, r0, r3
	strh r0, [r4, #0xa]
	ldr r2, [r4, #0x44]
	ldr r1, _08140478 @ =gSineTable
	ldr r3, _0814047C @ =0x00000666
	adds r0, r5, r3
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r6, #0
	ldrsh r0, [r0, r6]
	cmp r0, #0
	blt _08140480
	asrs r1, r0, #5
	b _08140486
	.align 2, 0
_08140470: .4byte 0x00000472
_08140474: .4byte 0x0000066E
_08140478: .4byte gSineTable
_0814047C: .4byte 0x00000666
_08140480:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r1, r0, #0
_08140486:
	ldrh r0, [r2, #0x1e]
	subs r0, r0, r1
	strh r0, [r2, #0x1e]
	ldr r0, _0814049C @ =0x00000666
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0x40
	bls _081404A0
	movs r0, #0
	b _081404A2
	.align 2, 0
_0814049C: .4byte 0x00000666
_081404A0:
	adds r0, #8
_081404A2:
	strb r0, [r1]
	ldr r1, _081404B8 @ =0x00000472
	adds r0, r4, r1
	ldrh r1, [r0]
	ldr r2, _081404BC @ =0x0000066E
	adds r0, r5, r2
	strh r1, [r0]
_081404B0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081404B8: .4byte 0x00000472
_081404BC: .4byte 0x0000066E
