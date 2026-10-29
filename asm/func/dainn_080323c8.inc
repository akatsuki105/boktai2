	push {r4, r5, r6, r7, lr}
	sub sp, #0x18
	adds r6, r0, #0
	adds r7, r1, #0
	adds r5, r6, #0
	ldr r0, _08032438 @ =0x00000899
	adds r1, r6, r0
	adds r0, r6, #0
	adds r0, #0xc8
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	adds r3, r6, #0
	adds r3, #0x4d
	strb r0, [r3]
	ldrb r0, [r3]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	adds r0, r6, #0
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r6, #0
	adds r0, #0xa1
	strb r1, [r0]
	adds r1, r6, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _080324A4
	movs r0, #0
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _08032440
	ldr r1, _0803243C @ =0x00000824
	adds r0, r6, r1
	ldr r0, [r0]
	movs r3, #0x17
	cmp r0, #0
	bne _08032450
	movs r3, #0x13
	b _08032450
	.align 2, 0
_08032438: .4byte 0x00000899
_0803243C: .4byte 0x00000824
_08032440:
	movs r2, #0x82
	lsls r2, r2, #4
	adds r0, r6, r2
	ldr r0, [r0]
	movs r3, #0x13
	cmp r0, #0
	beq _08032450
	movs r3, #0x17
_08032450:
	movs r4, #0xbd
	lsls r4, r4, #2
	adds r1, r5, r4
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r2, r5, r0
	movs r0, #2
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r6, #0
	bl Boss_PlayAnim
	movs r1, #0xaf
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #0
	strh r1, [r0]
	movs r2, #0xae
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
	ldr r1, _080324F0 @ =0x03004494
	ldr r3, _080324F4 @ =0x00001084
	adds r0, r3, #0
	strh r0, [r1]
	ldr r1, _080324F8 @ =0x03004454
	ldr r4, _080324FC @ =0x00001FFF
	adds r0, r4, #0
	strh r0, [r1]
	ldr r0, _08032500 @ =0x00001044
	adds r1, r5, r0
	movs r0, #0xe1
	lsls r0, r0, #2
	str r0, [r1]
	subs r0, #0x33
	bl PlaySound_0824078c
	movs r0, #0xc3
	lsls r0, r0, #2
	bl PlaySound_0824078c
_080324A4:
	adds r0, r6, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	beq _08032530
	ldr r2, _08032504 @ =0x00000878
	adds r1, r5, r2
	movs r0, #0
	strh r0, [r1]
	ldr r3, _08032508 @ =0x0000087C
	adds r1, r5, r3
	movs r0, #0xff
	strb r0, [r1]
	adds r0, r5, #0
	bl Ringo_GetPlttID
	ldr r4, _0803250C @ =0x0000087A
	adds r1, r5, r4
	strh r0, [r1]
	adds r0, r5, #0
	bl Ringo_GetPlttID
	adds r1, r0, #0
	cmp r1, #0
	bne _08032510
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r2, #0x84
	lsls r2, r2, #3
	adds r0, r5, r2
	b _0803251E
	.align 2, 0
_080324F0: .4byte 0x03004494
_080324F4: .4byte 0x00001084
_080324F8: .4byte 0x03004454
_080324FC: .4byte 0x00001FFF
_08032500: .4byte 0x00001044
_08032504: .4byte 0x00000878
_08032508: .4byte 0x0000087C
_0803250C: .4byte 0x0000087A
_08032510:
	ldr r0, _0803252C @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	movs r3, #0xcf
	lsls r3, r3, #2
	adds r1, r5, r3
_0803251E:
	str r0, [r1]
	adds r0, r1, #0
	movs r4, #0xe7
	lsls r4, r4, #2
	adds r1, r5, r4
	b _08032808
	.align 2, 0
_0803252C: .4byte 0x03003584
_08032530:
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080325A4
	ldr r2, _08032578 @ =0x00000878
	adds r0, r5, r2
	strh r4, [r0]
	ldr r3, _0803257C @ =0x0000087C
	adds r1, r5, r3
	movs r0, #0xff
	strb r0, [r1]
	adds r0, r5, #0
	bl Ringo_GetPlttID
	ldr r4, _08032580 @ =0x0000087A
	adds r1, r5, r4
	strh r0, [r1]
	adds r0, r5, #0
	bl Ringo_GetPlttID
	adds r1, r0, #0
	cmp r1, #0
	bne _08032584
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r2, #0x84
	lsls r2, r2, #3
	adds r0, r5, r2
	b _08032592
	.align 2, 0
_08032578: .4byte 0x00000878
_0803257C: .4byte 0x0000087C
_08032580: .4byte 0x0000087A
_08032584:
	ldr r0, _080325A0 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	movs r3, #0xcf
	lsls r3, r3, #2
	adds r1, r5, r3
_08032592:
	str r0, [r1]
	adds r0, r1, #0
	movs r4, #0xe7
	lsls r4, r4, #2
	adds r1, r5, r4
	b _08032808
	.align 2, 0
_080325A0: .4byte 0x03003584
_080325A4:
	movs r1, #0xb1
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r2, [r0]
	movs r3, #0
	ldrsh r1, [r0, r3]
	adds r3, r0, #0
	cmp r1, #0x3d
	bgt _080325BA
	adds r0, r2, #2
	strh r0, [r3]
_080325BA:
	ldr r2, _080325DC @ =gSineTable
	lsls r0, r7, #1
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	mov ip, r2
	cmp r0, #0
	blt _080325E0
	asrs r1, r0, #0xc
	b _080325E6
	.align 2, 0
_080325DC: .4byte gSineTable
_080325E0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080325E6:
	ldrh r0, [r3]
	adds r0, r0, r1
	movs r2, #0xb0
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r3, #0
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _080325FC
	strh r3, [r1]
_080325FC:
	movs r4, #0xaf
	lsls r4, r4, #1
	adds r2, r5, r4
	ldrh r0, [r2]
	cmp r0, #1
	beq _080326AC
	cmp r0, #1
	bgt _08032612
	cmp r0, #0
	beq _08032620
	b _0803292C
_08032612:
	cmp r0, #2
	bne _08032618
	b _08032722
_08032618:
	cmp r0, #3
	bne _0803261E
	b _08032908
_0803261E:
	b _0803292C
_08032620:
	movs r0, #0xae
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _08032636
	b _0803292C
_08032636:
	adds r0, r5, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _08032654
	ldr r1, _08032650 @ =0x00000824
	adds r0, r5, r1
	ldr r0, [r0]
	movs r3, #0x18
	cmp r0, #0
	bne _08032664
	movs r3, #0x14
	b _08032664
	.align 2, 0
_08032650: .4byte 0x00000824
_08032654:
	movs r2, #0x82
	lsls r2, r2, #4
	adds r0, r5, r2
	ldr r0, [r0]
	movs r3, #0x14
	cmp r0, #0
	beq _08032664
	movs r3, #0x18
_08032664:
	movs r4, #0xbd
	lsls r4, r4, #2
	adds r1, r5, r4
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r2, r5, r0
	movs r4, #2
	str r4, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r6, #0
	bl Boss_PlayAnim
	movs r1, #0xaf
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r0, [r2]
	adds r0, #1
	movs r1, #0
	strh r0, [r2]
	movs r2, #0xae
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
	ldr r3, _080326A4 @ =0x0000087C
	adds r0, r5, r3
	strb r4, [r0]
	ldr r4, _080326A8 @ =0x00000878
	adds r1, r5, r4
	movs r0, #0x20
	strh r0, [r1]
	b _0803292C
	.align 2, 0
_080326A4: .4byte 0x0000087C
_080326A8: .4byte 0x00000878
_080326AC:
	movs r0, #0xae
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x17
	bhi _080326C2
	b _0803292C
_080326C2:
	adds r0, r5, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _080326E0
	ldr r1, _080326DC @ =0x00000824
	adds r0, r5, r1
	ldr r0, [r0]
	movs r3, #0x19
	cmp r0, #0
	bne _080326F0
	movs r3, #0x15
	b _080326F0
	.align 2, 0
_080326DC: .4byte 0x00000824
_080326E0:
	movs r2, #0x82
	lsls r2, r2, #4
	adds r0, r5, r2
	ldr r0, [r0]
	movs r3, #0x15
	cmp r0, #0
	beq _080326F0
	movs r3, #0x19
_080326F0:
	movs r4, #0xbd
	lsls r4, r4, #2
	adds r1, r5, r4
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r2, r5, r0
	movs r0, #1
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r6, #0
	bl Boss_PlayAnim
	movs r1, #0xaf
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r0, [r2]
	adds r0, #1
	movs r1, #0
	strh r0, [r2]
	movs r2, #0xae
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
	b _0803292C
_08032722:
	cmp r7, #0x7f
	ble _08032814
	movs r0, #0x20
	adds r3, r6, #0
	adds r3, #0x4d
	strb r0, [r3]
	movs r2, #0xff
	movs r1, #2
	adds r0, r6, #0
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r6, #0
	adds r0, #0xa1
	strb r1, [r0]
	adds r0, r5, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803276C
	ldr r3, _08032768 @ =0x00000824
	adds r0, r5, r3
	ldr r0, [r0]
	movs r3, #5
	cmp r0, #0
	bne _0803277C
	movs r3, #0
	b _0803277C
	.align 2, 0
_08032768: .4byte 0x00000824
_0803276C:
	movs r4, #0x82
	lsls r4, r4, #4
	adds r0, r5, r4
	ldr r0, [r0]
	movs r3, #0
	cmp r0, #0
	beq _0803277C
	movs r3, #5
_0803277C:
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r4, #0xb5
	lsls r4, r4, #2
	adds r2, r5, r4
	movs r0, #2
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r6, #0
	bl Boss_PlayAnimDir8
	movs r0, #0xaf
	lsls r0, r0, #1
	adds r2, r5, r0
	ldrh r0, [r2]
	adds r0, #1
	movs r1, #0
	strh r0, [r2]
	movs r2, #0xae
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
	ldr r3, _080327E4 @ =0x00000878
	adds r0, r5, r3
	strh r1, [r0]
	ldr r4, _080327E8 @ =0x0000087C
	adds r1, r5, r4
	movs r0, #0xff
	strb r0, [r1]
	adds r0, r5, #0
	bl Ringo_GetPlttID
	ldr r2, _080327EC @ =0x0000087A
	adds r1, r5, r2
	strh r0, [r1]
	adds r0, r5, #0
	bl Ringo_GetPlttID
	adds r1, r0, #0
	cmp r1, #0
	bne _080327F0
	movs r3, #0xcf
	lsls r3, r3, #2
	adds r1, r5, r3
	movs r4, #0x84
	lsls r4, r4, #3
	adds r0, r5, r4
	b _080327FE
	.align 2, 0
_080327E4: .4byte 0x00000878
_080327E8: .4byte 0x0000087C
_080327EC: .4byte 0x0000087A
_080327F0:
	ldr r0, _08032810 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	movs r2, #0xcf
	lsls r2, r2, #2
	adds r1, r5, r2
_080327FE:
	str r0, [r1]
	adds r0, r1, #0
	movs r3, #0xe7
	lsls r3, r3, #2
	adds r1, r5, r3
_08032808:
	ldr r0, [r0]
	str r0, [r1]
	b _0803292C
	.align 2, 0
_08032810: .4byte 0x03003584
_08032814:
	movs r0, #3
	ands r0, r7
	cmp r0, #0

_0803281A:
	beq _0803281E
	b _0803292C
_0803281E:
	ldr r4, _08032864 @ =0x00000899
	adds r1, r5, r4
	adds r0, r6, #0
	adds r0, #0xc8
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r2, [r0]
	ldr r3, _08032868 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r1, _0803286C @ =0x000003FF
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	ldr r1, _08032870 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	adds r2, r2, r0
	adds r4, r2, #0
	subs r4, #0x10
	add r3, sp, #0x10
	adds r2, #0x30
	movs r0, #0xff
	ands r2, r0
	lsls r2, r2, #1
	add r2, ip
	movs r1, #0
	ldrsh r0, [r2, r1]
	lsls r0, r0, #8
	cmp r0, #0
	blt _08032874
	asrs r1, r0, #0xc
	b _0803287A
	.align 2, 0
_08032864: .4byte 0x00000899
_08032868: .4byte 0x030046B8
_0803286C: .4byte 0x000003FF
_08032870: .4byte 0x0203B400
_08032874:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0803287A:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	movs r0, #0xff
	ands r0, r4
	lsls r0, r0, #1
	add r0, ip
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x80
	lsls r0, r0, #1
	muls r0, r1, r0
	cmp r0, #0
	blt _0803289A
	asrs r0, r0, #0xc
	b _080328A0
_0803289A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080328A0:
	strh r0, [r3, #4]
	add r3, sp, #0x10
	adds r2, r6, #0
	adds r2, #0x50
	adds r1, r3, #0
	ldrh r0, [r2]
	ldrh r1, [r1]
	adds r0, r0, r1
	adds r1, r3, #0
	strh r0, [r1]
	ldrh r1, [r3, #2]
	ldrh r0, [r2, #2]
	adds r1, r1, r0
	ldrh r0, [r2, #4]
	ldrh r2, [r3, #4]
	adds r0, r0, r2
	strh r0, [r3, #4]
	adds r1, #0xa4
	strh r1, [r3, #2]
	ldr r3, _080328FC @ =0x00000899
	adds r0, r5, r3
	ldrb r1, [r0]
	lsls r1, r1, #2
	movs r2, #0x86
	lsls r2, r2, #1
	adds r0, r6, r2
	adds r0, r0, r1
	ldr r2, [r0]
	ldr r3, _08032900 @ =0x00001054
	adds r0, r5, r3
	ldr r0, [r0]
	str r4, [sp]
	movs r1, #0x14
	str r1, [sp, #4]
	ldr r4, _08032904 @ =0x000008CA
	adds r1, r5, r4
	ldrh r1, [r1]
	str r1, [sp, #8]
	movs r1, #0x32
	str r1, [sp, #0xc]
	add r1, sp, #0x10
	movs r3, #0
	bl FUN_0805b7d4
	b _0803292C
	.align 2, 0
_080328FC: .4byte 0x00000899
_08032900: .4byte 0x00001054
_08032904: .4byte 0x000008CA
_08032908:
	movs r0, #0xae
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #9
	bls _0803292C
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	strh r3, [r1]
	adds r1, r6, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_0803292C:
	add sp, #0x18
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
