	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x84
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r4, [r0]
	ldr r2, _0812521C @ =0x0000046D
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08125220
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08125222
	.align 2, 0
_0812521C: .4byte 0x0000046D
_08125220:
	movs r0, #0
_08125222:
	cmp r0, #0
	beq _0812523C
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_PlayAnim
	movs r2, #4
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r1, r7, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_0812523C:
	adds r0, r7, #0
	bl Mummy_AvoidNearbyBomb
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0812526E
	movs r2, #0x10
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r0, r7, r5
	movs r1, #0
	strb r1, [r0]
	ldr r6, _08125284 @ =0x00000469
	adds r0, r7, r6
	strb r1, [r0]
	ldr r3, _08125288 @ =0x0000046A
	adds r0, r7, r3
	strb r2, [r0]
	adds r5, #0x1c
	adds r0, r7, r5
	str r1, [r0]
	adds r6, #3
	adds r1, r7, r6
	movs r0, #1
	strb r0, [r1]
_0812526E:
	ldr r1, _08125288 @ =0x0000046A
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0x10
	bne _0812528C
	adds r0, r7, #0
	movs r1, #1
	bl Enemy_PlayAnim
	b _08125298
	.align 2, 0
_08125284: .4byte 0x00000469
_08125288: .4byte 0x0000046A
_0812528C:
	cmp r0, #0x12
	bne _08125298
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_PlayAnim
_08125298:
	ldr r2, _08125324 @ =0x00000482
	adds r1, r7, r2
	movs r0, #2
	strh r0, [r1]
	ldr r3, _08125328 @ =0x00000702
	adds r0, r4, r3
	ldrh r0, [r0]
	cmp r0, #0
	beq _081252AC
	b _08125988
_081252AC:
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r7, r5
	ldr r0, _0812532C @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	movs r0, #4
	ldr r6, _08125330 @ =0x00000222
	adds r3, r7, r6
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r7, r0
	movs r1, #5
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r1, _08125334 @ =0x0000071E
	adds r2, r4, r1
	ldr r0, _08125338 @ =0xFFFFEBFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r2, #0x95
	lsls r2, r2, #3
	adds r4, r7, r2
	ldr r6, [r4]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r6]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r5, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r3, [sp, #0x64]
	str r4, [sp, #0x58]
	str r2, [sp, #0x60]
	cmp r5, #0
	blt _08125320
	cmp r1, #0
	blt _08125320
	ldr r0, _0812533C @ =0x030046A8
	ldr r0, [r0]
	cmp r5, r0
	bhs _08125320
	ldr r0, _08125340 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08125344
_08125320:
	movs r4, #0
	b _08125352
	.align 2, 0
_08125324: .4byte 0x00000482
_08125328: .4byte 0x00000702
_0812532C: .4byte 0x03002BE0
_08125330: .4byte 0x00000222
_08125334: .4byte 0x0000071E
_08125338: .4byte 0xFFFFEBFF
_0812533C: .4byte 0x030046A8
_08125340: .4byte 0x030046AC
_08125344:
	ldr r0, _08125364 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r5
_08125352:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08125368
	adds r0, #4
	b _08125374
	.align 2, 0
_08125364: .4byte 0x030046A4
_08125368:
	ldr r0, _08125388 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08125374:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0812538C
	cmp r2, #2
	beq _08125390
	b _08125394
	.align 2, 0
_08125388: .4byte 0x030046A4
_0812538C:
	ldrb r0, [r6, #4]
	b _08125392
_08125390:
	ldrb r0, [r6]
_08125392:
	subs r1, r1, r0
_08125394:
	strh r1, [r6, #2]
	ldr r0, _081253A8 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081253AC
	movs r0, #1
	b _081253AE
	.align 2, 0
_081253A8: .4byte 0x030047A4
_081253AC:
	movs r0, #0
_081253AE:
	cmp r0, #0
	beq _081253EC
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r1, [r0]
	cmp r1, #0
	beq _081253CE
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081253CA
	adds r2, r0, #0
_081253CA:
	cmp r2, #0
	bge _081253D8
_081253CE:
	ldr r4, _081253D4 @ =0x000005C4
	adds r0, r7, r4
	b _08125904
	.align 2, 0
_081253D4: .4byte 0x000005C4
_081253D8:
	ldr r1, _081253E8 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _08125434
	.align 2, 0
_081253E8: .4byte 0x03002BE0
_081253EC:
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r7, r5
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08125418
	cmp r1, #0
	blt _08125418
	ldr r0, _0812541C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08125418
	ldr r0, _08125420 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08125424
_08125418:
	movs r5, #0
	b _08125432
	.align 2, 0
_0812541C: .4byte 0x030046A8
_08125420: .4byte 0x030046AC
_08125424:
	ldr r0, _08125474 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_08125432:
	movs r2, #0
_08125434:
	ldr r6, _08125478 @ =0x00000256
	adds r0, r7, r6
	ldrh r0, [r0]
	cmp r5, r0
	beq _08125454
	ldr r1, _0812547C @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _08125454
	b _08125848
_08125454:
	movs r0, #0x80
	lsls r0, r0, #3
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r7, r1
	ldrh r1, [r2]
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov sl, r1
	str r2, [sp, #0x4c]
	cmp r1, #0
	beq _08125480
	movs r0, #0
	b _0812591A
	.align 2, 0
_08125474: .4byte 0x030046A4
_08125478: .4byte 0x00000256
_0812547C: .4byte 0x03002BE0
_08125480:
	movs r0, #5
	rsbs r0, r0, #0
	ldr r2, [sp, #0x64]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r3, [sp, #0x4c]
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _08125534
	movs r4, #0xb7
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r5, _08125520 @ =0x0000046D
	adds r5, r7, r5
	str r5, [sp, #0x80]
	movs r5, #1
	ldr r6, [sp, #0x80]
	strb r5, [r6]
	ldr r2, _08125524 @ =0x0000046B
	adds r2, r2, r7
	mov r8, r2
	movs r3, #0
	strb r3, [r2]
	subs r4, #0x65
	adds r4, r4, r7
	mov sb, r4
	strb r0, [r4]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #8]
	str r1, [r6]
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r0, r7, r0
	str r0, [sp, #0xc]
	mov r1, sl
	strh r1, [r0]
	movs r0, #0xc
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r4, r7, r2
	strb r3, [r4]
	ldr r6, _08125528 @ =0x00000469
	adds r3, r7, r6
	movs r1, #0
	strb r1, [r3]
	adds r6, #1
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, _0812552C @ =0x00000484
	adds r1, r7, r0
	mov r6, sl
	str r6, [r1]
	ldr r6, _08125530 @ =0x0000046C
	adds r0, r7, r6
	strb r5, [r0]
	ldr r5, [sp, #0x80]
	str r5, [sp, #0x48]
	str r4, [sp, #0x34]
	str r3, [sp, #0x38]
	str r2, [sp, #0x3c]
	str r1, [sp, #0x54]
	str r0, [sp, #0x44]
	mov r6, r8
	str r6, [sp, #0x40]
	mov r0, sb
	str r0, [sp, #0x7c]
	ldr r1, [sp, #8]
	str r1, [sp, #0x2c]
	ldr r2, [sp, #0xc]
	str r2, [sp, #0x5c]
	b _081256FE
	.align 2, 0
_08125520: .4byte 0x0000046D
_08125524: .4byte 0x0000046B
_08125528: .4byte 0x00000469
_0812552C: .4byte 0x00000484
_08125530: .4byte 0x0000046C
_08125534:
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r1, [r0]
	movs r0, #1
	ldr r4, _081255F4 @ =0x0000046D
	adds r4, r7, r4
	str r4, [sp, #0x10]
	strb r0, [r4]
	ldr r5, _081255F8 @ =0x0000046B
	adds r5, r7, r5
	str r5, [sp, #0x14]
	movs r6, #0
	strb r6, [r5]
	subs r3, #0x4d
	adds r3, r7, r3
	str r3, [sp, #0x18]
	strb r0, [r3]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x1c]
	str r1, [r4]
	movs r5, #0xe4
	lsls r5, r5, #1
	adds r5, r7, r5
	str r5, [sp, #0x20]
	strh r2, [r5]
	movs r1, #5
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x80]
	movs r3, #0
	strb r3, [r6]
	ldr r4, _081255FC @ =0x00000469
	adds r5, r7, r4
	strb r3, [r5]
	ldr r6, _08125600 @ =0x0000046A
	adds r4, r7, r6
	strb r1, [r4]
	ldr r1, _08125604 @ =0x00000484
	adds r3, r7, r1
	str r2, [r3]
	adds r6, #2
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0x58]
	ldr r0, [r0]
	str r0, [sp, #0x24]
	ldr r1, [sp, #0x60]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x24]
	strh r1, [r6]
	ldr r6, [sp, #0x60]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x24]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov ip, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x10]
	str r0, [sp, #0x48]
	ldr r6, [sp, #0x80]
	str r6, [sp, #0x34]
	str r5, [sp, #0x38]
	str r4, [sp, #0x3c]
	str r3, [sp, #0x54]
	str r2, [sp, #0x44]
	ldr r0, [sp, #0x14]
	str r0, [sp, #0x40]
	ldr r2, [sp, #0x18]
	str r2, [sp, #0x7c]
	ldr r3, [sp, #0x1c]
	str r3, [sp, #0x2c]
	ldr r4, [sp, #0x20]
	str r4, [sp, #0x5c]
	mov r5, ip
	cmp r5, #0
	blt _081255F0
	cmp r1, #0
	blt _081255F0
	ldr r0, _08125608 @ =0x030046A8
	ldr r0, [r0]
	cmp ip, r0
	bhs _081255F0
	ldr r0, _0812560C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08125610
_081255F0:
	movs r4, #0
	b _08125620
	.align 2, 0
_081255F4: .4byte 0x0000046D
_081255F8: .4byte 0x0000046B
_081255FC: .4byte 0x00000469
_08125600: .4byte 0x0000046A
_08125604: .4byte 0x00000484
_08125608: .4byte 0x030046A8
_0812560C: .4byte 0x030046AC
_08125610:
	ldr r0, _08125630 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r6, ip
	adds r4, r0, r6
_08125620:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08125634
	adds r0, #4
	b _08125640
	.align 2, 0
_08125630: .4byte 0x030046A4
_08125634:
	ldr r0, _08125654 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08125640:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08125658
	cmp r2, #2
	beq _0812565E
	b _08125664
	.align 2, 0
_08125654: .4byte 0x030046A4
_08125658:
	ldr r2, [sp, #0x24]
	ldrb r0, [r2, #4]
	b _08125662
_0812565E:
	ldr r3, [sp, #0x24]
	ldrb r0, [r3]
_08125662:
	subs r1, r1, r0
_08125664:
	ldr r4, [sp, #0x24]
	strh r1, [r4, #2]
	ldr r5, [sp, #0x58]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08125690
	cmp r1, #0
	blt _08125690
	ldr r0, _08125694 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08125690
	ldr r0, _08125698 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0812569C
_08125690:
	movs r4, #0
	b _081256AA
	.align 2, 0
_08125694: .4byte 0x030046A8
_08125698: .4byte 0x030046AC
_0812569C:
	ldr r0, _081256C0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081256AA:
	ldr r6, [sp, #0x58]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081256C4
	adds r0, #4
	b _081256D0
	.align 2, 0
_081256C0: .4byte 0x030046A4
_081256C4:
	ldr r0, _081256E4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081256D0:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081256E8
	cmp r3, #2
	beq _081256EC
	b _081256F0
	.align 2, 0
_081256E4: .4byte 0x030046A4
_081256E8:
	ldrb r0, [r5, #4]
	b _081256EE
_081256EC:
	ldrb r0, [r5]
_081256EE:
	subs r2, r2, r0
_081256F0:
	ldr r1, [sp, #0x58]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0x58]
	ldr r0, [r2]
	strh r1, [r0, #6]
_081256FE:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x28]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x4c]
	ldrh r0, [r4]
	ands r0, r1
	mov r8, r3
	ldr r5, _08125728 @ =0x00000482
	adds r5, r7, r5
	str r5, [sp, #0x50]
	cmp r0, #0
	bne _0812580C
	movs r1, #4
	ldr r6, [sp, #0x64]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _0812572C
	movs r0, #1
	b _0812572E
	.align 2, 0
_08125728: .4byte 0x00000482
_0812572C:
	movs r0, #0
_0812572E:
	ldr r1, _0812581C @ =0x00000482
	adds r1, r7, r1
	str r1, [sp, #0x50]
	cmp r0, #0
	bne _0812580C
	movs r3, #0
	movs r2, #0xa8
	lsls r2, r2, #3
	adds r2, r2, r7
	mov sb, r2
	movs r4, #0xa9
	lsls r4, r4, #3
	adds r4, r4, r7
	mov sl, r4
	ldr r5, _08125820 @ =0x0000054F
	adds r5, r5, r7
	mov ip, r5
	ldr r6, _08125824 @ =0x0000054C
	adds r6, r7, r6
	str r6, [sp, #0x70]
	ldr r0, _08125828 @ =0x0000054D
	adds r0, r7, r0
	str r0, [sp, #0x74]
	ldr r1, _0812582C @ =0x0000054E
	adds r1, r7, r1
	str r1, [sp, #0x78]
	ldr r2, _08125830 @ =0x00000541
	adds r2, r7, r2
	str r2, [sp, #0x68]
	ldr r4, _08125834 @ =0x000005BC
	adds r4, r7, r4
	str r4, [sp, #0x30]
	ldr r5, _08125838 @ =0x00000542
	adds r5, r7, r5
	str r5, [sp, #0x6c]
	ldr r6, _0812583C @ =0x0203B400
	ldr r1, _08125840 @ =0x030046B8
	ldr r5, _08125844 @ =0x000003FF
	movs r4, #3
	mov r2, r8
_0812577E:
	ldr r0, [r1]
	adds r0, #1
	ands r0, r5
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ands r0, r4
	lsls r0, r0, #6
	cmp r0, r2
	bne _0812579C
	adds r3, #1
	cmp r3, #3
	ble _0812577E
	mov r0, r8
_0812579C:
	movs r3, #0
	mov r6, sb
	strb r0, [r6]
	ldr r1, [sp, #0x2c]
	ldr r0, [r1]
	mov r2, sl
	str r0, [r2]
	ldr r4, [sp, #0x7c]
	ldrb r0, [r4]
	mov r5, ip
	strb r0, [r5]
	ldr r6, [sp, #0x34]
	ldrb r0, [r6]
	ldr r1, [sp, #0x70]
	strb r0, [r1]
	ldr r2, [sp, #0x38]
	ldrb r0, [r2]
	ldr r4, [sp, #0x74]
	strb r0, [r4]
	ldr r5, [sp, #0x3c]
	ldrb r0, [r5]
	ldr r6, [sp, #0x78]
	strb r0, [r6]
	add r0, sp, #0x28
	ldrb r1, [r0]
	ldr r0, [sp, #0x68]
	strb r1, [r0]
	ldr r1, [sp, #0x30]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x48]
	strb r1, [r4]
	ldr r5, [sp, #0x40]
	strb r3, [r5]
	ldr r6, [sp, #0x7c]
	strb r0, [r6]
	ldr r0, [sp, #0x2c]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0x5c]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x34]
	strb r0, [r5]
	ldr r6, [sp, #0x38]
	strb r1, [r6]
	ldr r0, [sp, #0x3c]
	strb r2, [r0]
	ldr r2, [sp, #0x54]
	str r3, [r2]
	ldr r3, [sp, #0x44]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0x6c]
	strb r0, [r4]
_0812580C:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r5, [sp, #0x50]
	strh r0, [r5]
	movs r0, #0
	b _0812591A
	.align 2, 0
_0812581C: .4byte 0x00000482
_08125820: .4byte 0x0000054F
_08125824: .4byte 0x0000054C
_08125828: .4byte 0x0000054D
_0812582C: .4byte 0x0000054E
_08125830: .4byte 0x00000541
_08125834: .4byte 0x000005BC
_08125838: .4byte 0x00000542
_0812583C: .4byte 0x0203B400
_08125840: .4byte 0x030046B8
_08125844: .4byte 0x000003FF
_08125848:
	mov sb, sp
	ldr r6, _08125884 @ =0x030046A4
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
	beq _08125888
	adds r0, #4
	b _08125892
	.align 2, 0
_08125884: .4byte 0x030046A4
_08125888:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08125892:
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
	ldr r6, _081258C8 @ =0x000004A4
	adds r0, r7, r6
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081258CC
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r7, r1
	b _081258F2
	.align 2, 0
_081258C8: .4byte 0x000004A4
_081258CC:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081258EC
	cmp r0, #2
	beq _081258E8
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081258E8:
	movs r0, #1
	b _081258FC
_081258EC:
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
_081258F2:
	ldr r1, _08125910 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_081258FC:
	cmp r0, #0
	bne _08125918
	ldr r3, _08125914 @ =0x000005C4
	adds r0, r7, r3
_08125904:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _0812591A
	.align 2, 0
_08125910: .4byte 0xFFFFFDFF
_08125914: .4byte 0x000005C4
_08125918:
	movs r0, #1
_0812591A:
	cmp r0, #0
	beq _08125992
	movs r4, #0xb7
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r3, [r0]
	movs r1, #0x24
	ldr r5, _08125974 @ =0x0000046D
	adds r0, r7, r5
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r6, _08125978 @ =0x0000046B
	adds r0, r7, r6
	strb r2, [r0]
	adds r5, #0xe6
	adds r0, r7, r5
	strb r1, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r7, r6
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r1, #0
	strh r2, [r0]
	movs r3, #0xc
	subs r5, #0xeb
	adds r0, r7, r5
	strb r1, [r0]
	ldr r6, _0812597C @ =0x00000469
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _08125980 @ =0x0000046A
	adds r0, r7, r1
	strb r3, [r0]
	ldr r3, _08125984 @ =0x00000484
	adds r0, r7, r3
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r4, [r0]
	b _08125992
	.align 2, 0
_08125974: .4byte 0x0000046D
_08125978: .4byte 0x0000046B
_0812597C: .4byte 0x00000469
_08125980: .4byte 0x0000046A
_08125984: .4byte 0x00000484
_08125988:
	ldr r6, _081259A4 @ =0x00000484
	adds r1, r7, r6
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08125992:
	add sp, #0x84
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081259A4: .4byte 0x00000484
