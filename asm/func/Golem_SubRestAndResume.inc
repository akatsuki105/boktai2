	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x58
	adds r7, r0, #0
	ldr r0, _081201BC @ =0x0000046C
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081201C0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081201C2
	.align 2, 0
_081201BC: .4byte 0x0000046C
_081201C0:
	movs r0, #0
_081201C2:
	cmp r0, #0
	beq _081201F6
	ldr r4, _08120284 @ =Golem_StateCurledIdle
	movs r3, #0x2b
	ldr r2, _08120288 @ =0x0000046D
	adds r1, r7, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r5, _0812028C @ =0x0000046B
	adds r0, r7, r5
	strb r2, [r0]
	ldr r6, _08120290 @ =0x00000553
	adds r0, r7, r6
	strb r3, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r4, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	movs r1, #0
	strh r2, [r0]
	adds r0, r7, r5
	strb r1, [r0]
_081201F6:
	ldr r4, _0812028C @ =0x0000046B
	adds r0, r7, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _08120202
	b _0812088C
_08120202:
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_PlayAnim
	ldr r3, _08120294 @ =Enemy_WaitPendingState
	movs r2, #0xe
	ldr r5, _08120288 @ =0x0000046D
	adds r5, r5, r7
	mov r8, r5
	movs r1, #0
	movs r0, #1
	strb r0, [r5]
	adds r6, r7, r4
	strb r1, [r6]
	ldr r0, _08120290 @ =0x00000553
	adds r5, r7, r0
	strb r2, [r5]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r4, r7, r2
	str r3, [r4]
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r3, r7, r0
	movs r2, #0
	mov sb, r2
	strh r1, [r3]
	movs r1, #0x80
	subs r0, #0x48
	adds r2, r7, r0
	ldrh r0, [r2]
	ands r0, r1
	mov r1, r8
	str r1, [sp, #0x24]
	str r6, [sp, #0x1c]
	str r5, [sp, #0x48]
	str r4, [sp, #0x4c]
	str r3, [sp, #0x30]
	str r2, [sp, #0x14]
	cmp r0, #0
	beq _081202A0
	movs r2, #0xb7
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r3, [r0]
	movs r4, #0xc
	movs r1, #0x78
	movs r5, #0xab
	lsls r5, r5, #3
	adds r2, r7, r5
	ldr r6, _08120298 @ =0x00000554
	adds r0, r7, r6
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	mov r2, sb
	strb r2, [r0]
	ldr r3, _0812029C @ =0x00000551
	adds r0, r7, r3
	strb r2, [r0]
	subs r5, #6
	adds r0, r7, r5
	b _081202CC
	.align 2, 0
_08120284: .4byte Golem_StateCurledIdle
_08120288: .4byte 0x0000046D
_0812028C: .4byte 0x0000046B
_08120290: .4byte 0x00000553
_08120294: .4byte Enemy_WaitPendingState
_08120298: .4byte 0x00000554
_0812029C: .4byte 0x00000551
_081202A0:
	movs r6, #0xb4
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r3, [r0]
	movs r4, #7
	movs r1, #0x78
	movs r0, #0xab
	lsls r0, r0, #3
	adds r2, r7, r0
	ldr r5, _0812036C @ =0x00000554
	adds r0, r7, r5
	str r1, [r0]
	str r3, [r2]
	subs r6, #0x50
	adds r0, r7, r6
	mov r1, sb
	strb r1, [r0]
	ldr r2, _08120370 @ =0x00000551
	adds r0, r7, r2
	strb r1, [r0]
	ldr r3, _08120374 @ =0x00000552
	adds r0, r7, r3
_081202CC:
	strb r4, [r0]
	movs r2, #0x10
	movs r4, #0xbc
	lsls r4, r4, #1
	adds r1, r7, r4
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r5, _08120378 @ =0x00000482
	adds r1, r7, r5
	movs r2, #0
	movs r3, #0
	movs r0, #2
	strh r0, [r1]
	movs r0, #3
	movs r1, #1
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r6, r6, r7
	mov sb, r6
	strb r0, [r6]
	ldr r0, _0812037C @ =0x00000469
	adds r0, r0, r7
	mov r8, r0
	strb r1, [r0]
	ldr r4, _08120380 @ =0x0000046A
	adds r4, r7, r4
	str r4, [sp, #0x54]
	strb r2, [r4]
	ldr r6, _08120384 @ =0x00000484
	adds r5, r7, r6
	str r3, [r5]
	ldr r0, _08120388 @ =0x0000046C
	adds r3, r7, r0
	strb r1, [r3]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r4, r7, r1
	ldr r2, [r4]
	mov sl, r2
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	mov r6, sl
	strh r1, [r6]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov ip, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r3, [sp, #0x20]
	mov r0, sb
	str r0, [sp, #0xc]
	mov r3, r8
	str r3, [sp, #0x10]
	ldr r6, [sp, #0x54]
	str r6, [sp, #0x18]
	str r5, [sp, #0x2c]
	adds r6, r4, #0
	mov r8, r2
	mov r0, ip
	cmp r0, #0
	blt _08120366
	cmp r1, #0
	blt _08120366
	ldr r0, _0812038C @ =0x030046A8
	ldr r0, [r0]
	cmp ip, r0
	bhs _08120366
	ldr r0, _08120390 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08120394
_08120366:
	movs r4, #0
	b _081203A4
	.align 2, 0
_0812036C: .4byte 0x00000554
_08120370: .4byte 0x00000551
_08120374: .4byte 0x00000552
_08120378: .4byte 0x00000482
_0812037C: .4byte 0x00000469
_08120380: .4byte 0x0000046A
_08120384: .4byte 0x00000484
_08120388: .4byte 0x0000046C
_0812038C: .4byte 0x030046A8
_08120390: .4byte 0x030046AC
_08120394:
	ldr r0, _081203B4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, ip
	adds r4, r0, r1
_081203A4:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081203B8
	adds r0, #4
	b _081203C4
	.align 2, 0
_081203B4: .4byte 0x030046A4
_081203B8:
	ldr r0, _081203D8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081203C4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081203DC
	cmp r2, #2
	beq _081203E2
	b _081203E8
	.align 2, 0
_081203D8: .4byte 0x030046A4
_081203DC:
	mov r2, sl
	ldrb r0, [r2, #4]
	b _081203E6
_081203E2:
	mov r3, sl
	ldrb r0, [r3]
_081203E6:
	subs r1, r1, r0
_081203E8:
	mov r4, sl
	strh r1, [r4, #2]
	ldr r0, _08120400 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08120404
	movs r0, #1
	b _08120406
	.align 2, 0
_08120400: .4byte 0x030047A4
_08120404:
	movs r0, #0
_08120406:
	cmp r0, #0
	beq _08120444
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r7, r5
	ldr r1, [r0]
	cmp r1, #0
	beq _08120426
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _08120422
	adds r2, r0, #0
_08120422:
	cmp r2, #0
	bge _08120430
_08120426:
	ldr r6, _0812042C @ =0x000005C4
	adds r0, r7, r6
	b _08120884
	.align 2, 0
_0812042C: .4byte 0x000005C4
_08120430:
	ldr r1, _08120440 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _0812048C
	.align 2, 0
_08120440: .4byte 0x03002BE0
_08120444:
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08120470
	cmp r1, #0
	blt _08120470
	ldr r0, _08120474 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08120470
	ldr r0, _08120478 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0812047C
_08120470:
	movs r5, #0
	b _0812048A
	.align 2, 0
_08120474: .4byte 0x030046A8
_08120478: .4byte 0x030046AC
_0812047C:
	ldr r0, _0812051C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0812048A:
	movs r2, #0
_0812048C:
	ldr r3, _08120520 @ =0x00000256
	adds r0, r7, r3
	ldrh r0, [r0]
	cmp r5, r0
	beq _081204AC
	ldr r1, _08120524 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081204AC
	b _081207C4
_081204AC:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x14]
	ldrh r0, [r4]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _081204C0
	b _0812088C
_081204C0:
	ldr r5, _08120528 @ =0x00000222
	adds r2, r7, r5
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	movs r5, #0
	strh r0, [r2]
	movs r1, #0x80
	ldr r3, [sp, #0x14]
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	mov sb, r2
	cmp r3, #0
	beq _0812052C
	movs r6, #0xb7
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r1, [r0]
	movs r0, #0x1a
	movs r2, #1
	ldr r3, [sp, #0x24]
	strb r2, [r3]
	ldr r6, [sp, #0x1c]
	strb r5, [r6]
	ldr r3, [sp, #0x48]
	strb r0, [r3]
	ldr r6, [sp, #0x4c]
	str r1, [r6]
	ldr r0, [sp, #0x30]
	strh r4, [r0]
	movs r0, #0xc
	ldr r1, [sp, #0xc]
	strb r5, [r1]
	ldr r3, [sp, #0x10]
	strb r5, [r3]
	ldr r5, [sp, #0x18]
	strb r0, [r5]
	ldr r6, [sp, #0x2c]
	str r4, [r6]
	ldr r0, [sp, #0x20]
	strb r2, [r0]
	b _0812067A
	.align 2, 0
_0812051C: .4byte 0x030046A4
_08120520: .4byte 0x00000256
_08120524: .4byte 0x03002BE0
_08120528: .4byte 0x00000222
_0812052C:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, [sp, #0x24]
	strb r0, [r2]
	ldr r4, [sp, #0x1c]
	strb r5, [r4]
	ldr r2, [sp, #0x48]
	strb r0, [r2]
	ldr r4, [sp, #0x4c]
	str r1, [r4]
	ldr r1, [sp, #0x30]
	strh r3, [r1]
	movs r1, #5
	ldr r2, [sp, #0xc]
	strb r5, [r2]
	ldr r4, [sp, #0x10]
	strb r5, [r4]
	ldr r5, [sp, #0x18]
	strb r1, [r5]
	ldr r1, [sp, #0x2c]
	str r3, [r1]
	ldr r2, [sp, #0x20]
	strb r0, [r2]
	ldr r5, [r6]
	mov r3, r8
	ldr r0, [r3, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r3, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08120590
	cmp r1, #0
	blt _08120590
	ldr r0, _08120594 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08120590
	ldr r0, _08120598 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0812059C
_08120590:
	movs r4, #0
	b _081205AA
	.align 2, 0
_08120594: .4byte 0x030046A8
_08120598: .4byte 0x030046AC
_0812059C:
	ldr r0, _081205BC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081205AA:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081205C0
	adds r0, #4
	b _081205CC
	.align 2, 0
_081205BC: .4byte 0x030046A4
_081205C0:
	ldr r0, _081205E0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081205CC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081205E4
	cmp r2, #2
	beq _081205E8
	b _081205EC
	.align 2, 0
_081205E0: .4byte 0x030046A4
_081205E4:
	ldrb r0, [r5, #4]
	b _081205EA
_081205E8:
	ldrb r0, [r5]
_081205EA:
	subs r1, r1, r0
_081205EC:
	strh r1, [r5, #2]
	ldr r0, [r6]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08120614
	cmp r1, #0
	blt _08120614
	ldr r0, _08120618 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08120614
	ldr r0, _0812061C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08120620
_08120614:
	movs r4, #0
	b _0812062E
	.align 2, 0
_08120618: .4byte 0x030046A8
_0812061C: .4byte 0x030046AC
_08120620:
	ldr r0, _08120640 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0812062E:
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08120644
	adds r0, #4
	b _08120650
	.align 2, 0
_08120640: .4byte 0x030046A4
_08120644:
	ldr r0, _08120664 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08120650:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _08120668
	cmp r3, #2
	beq _0812066C
	b _08120670
	.align 2, 0
_08120664: .4byte 0x030046A4
_08120668:
	ldrb r0, [r5, #4]
	b _0812066E
_0812066C:
	ldrb r0, [r5]
_0812066E:
	subs r2, r2, r0
_08120670:
	ldr r0, [r6]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r6]
	strh r1, [r0, #6]
_0812067A:
	ldrb r4, [r7, #5]
	str r4, [sp, #8]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r5, [sp, #0x14]
	ldrh r0, [r5]
	ands r0, r1
	mov r8, r4
	ldr r6, _081206A4 @ =0x00000482
	adds r6, r7, r6
	str r6, [sp, #0x28]
	cmp r0, #0
	bne _08120788
	movs r1, #4
	mov r2, sb
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081206A8
	movs r0, #1
	b _081206AA
	.align 2, 0
_081206A4: .4byte 0x00000482
_081206A8:
	movs r0, #0
_081206AA:
	ldr r3, _08120798 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x28]
	cmp r0, #0
	bne _08120788
	movs r3, #0
	movs r4, #0xa8
	lsls r4, r4, #3
	adds r4, r4, r7
	mov sb, r4
	movs r5, #0xa9
	lsls r5, r5, #3
	adds r5, r5, r7
	mov sl, r5
	ldr r6, _0812079C @ =0x0000054F
	adds r6, r6, r7
	mov ip, r6
	ldr r0, _081207A0 @ =0x0000054C
	adds r0, r7, r0
	str r0, [sp, #0x3c]
	ldr r1, _081207A4 @ =0x0000054D
	adds r1, r7, r1
	str r1, [sp, #0x40]
	ldr r2, _081207A8 @ =0x0000054E
	adds r2, r7, r2
	str r2, [sp, #0x44]
	ldr r4, _081207AC @ =0x00000541
	adds r4, r7, r4
	str r4, [sp, #0x34]
	ldr r5, _081207B0 @ =0x000005BC
	adds r5, r7, r5
	str r5, [sp, #0x50]
	ldr r6, _081207B4 @ =0x00000542
	adds r6, r7, r6
	str r6, [sp, #0x38]
	ldr r6, _081207B8 @ =0x0203B400
	ldr r1, _081207BC @ =0x030046B8
	ldr r5, _081207C0 @ =0x000003FF
	movs r2, #3
	mov r4, r8
_081206FA:
	ldr r0, [r1]
	adds r0, #1
	ands r0, r5
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ands r0, r2
	lsls r0, r0, #6
	cmp r0, r4
	bne _08120718
	adds r3, #1
	cmp r3, #3
	ble _081206FA
	mov r0, r8
_08120718:
	movs r3, #0
	mov r1, sb
	strb r0, [r1]
	ldr r2, [sp, #0x4c]
	ldr r0, [r2]
	mov r4, sl
	str r0, [r4]
	ldr r5, [sp, #0x48]
	ldrb r0, [r5]
	mov r6, ip
	strb r0, [r6]
	ldr r1, [sp, #0xc]
	ldrb r0, [r1]
	ldr r2, [sp, #0x3c]
	strb r0, [r2]
	ldr r4, [sp, #0x10]
	ldrb r0, [r4]
	ldr r5, [sp, #0x40]
	strb r0, [r5]
	ldr r6, [sp, #0x18]
	ldrb r0, [r6]
	ldr r1, [sp, #0x44]
	strb r0, [r1]
	mov r2, sp
	ldrb r4, [r2, #8]
	ldr r2, [sp, #0x34]
	strb r4, [r2]
	ldr r5, [sp, #0x50]
	ldr r2, [r5]
	movs r0, #0x1b
	movs r1, #1
	ldr r6, [sp, #0x24]
	strb r1, [r6]
	ldr r4, [sp, #0x1c]
	strb r3, [r4]
	ldr r5, [sp, #0x48]
	strb r0, [r5]
	ldr r6, [sp, #0x4c]
	str r2, [r6]
	movs r2, #0
	ldr r0, [sp, #0x30]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0xc]
	strb r0, [r4]
	ldr r5, [sp, #0x10]
	strb r1, [r5]
	ldr r6, [sp, #0x18]
	strb r2, [r6]
	ldr r0, [sp, #0x2c]
	str r3, [r0]
	ldr r2, [sp, #0x20]
	strb r1, [r2]
	movs r0, #6
	ldr r3, [sp, #0x38]
	strb r0, [r3]
_08120788:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r4, [sp, #0x28]
	strh r0, [r4]
	b _0812088C
	.align 2, 0
_08120798: .4byte 0x00000482
_0812079C: .4byte 0x0000054F
_081207A0: .4byte 0x0000054C
_081207A4: .4byte 0x0000054D
_081207A8: .4byte 0x0000054E
_081207AC: .4byte 0x00000541
_081207B0: .4byte 0x000005BC
_081207B4: .4byte 0x00000542
_081207B8: .4byte 0x0203B400
_081207BC: .4byte 0x030046B8
_081207C0: .4byte 0x000003FF
_081207C4:
	mov sb, sp
	ldr r6, _08120800 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08120804
	adds r0, #4
	b _0812080E
	.align 2, 0
_08120800: .4byte 0x030046A4
_08120804:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0812080E:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r4, sb
	strh r0, [r4, #2]
	mov r5, r8
	lsls r0, r5, #8
	adds r0, #0x80
	strh r0, [r4, #4]
	ldr r6, _08120848 @ =0x000004A4
	adds r0, r7, r6
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _08120850
	ldr r0, _0812084C @ =0xFFFFFDFF
	ldr r2, [sp, #0x14]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _0812087A
	.align 2, 0
_08120848: .4byte 0x000004A4
_0812084C: .4byte 0xFFFFFDFF
_08120850:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _08120870
	cmp r0, #2
	beq _0812086C
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0812086C:
	movs r0, #1
	b _0812087C
_08120870:
	ldr r0, _0812089C @ =0xFFFFFDFF
	ldr r3, [sp, #0x14]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_0812087A:
	movs r0, #0
_0812087C:
	cmp r0, #0
	bne _0812088C
	ldr r4, _081208A0 @ =0x000005C4
	adds r0, r7, r4
_08120884:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
_0812088C:
	add sp, #0x58
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0812089C: .4byte 0xFFFFFDFF
_081208A0: .4byte 0x000005C4
