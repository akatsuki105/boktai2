	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r6, r0, #0
	adds r7, r6, #0
	adds r1, r6, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803073E
	movs r4, #0
	strb r4, [r1]
	ldr r0, _08030780 @ =0x00000899
	adds r5, r6, r0
	adds r0, r6, #0
	adds r0, #0xc8
	ldrb r1, [r5]
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
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r3, #0xb5
	lsls r3, r3, #2
	adds r2, r6, r3
	movs r0, #2
	str r0, [sp]
	movs r0, #3
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r6, #0
	movs r3, #0x3a
	bl Boss_PlayAnimFacing
	movs r1, #0xaf
	lsls r1, r1, #1
	adds r0, r6, r1
	strh r4, [r0]
	movs r2, #0xae
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r4, [r0]
	ldrb r1, [r5]
	lsls r1, r1, #2
	movs r3, #0x86
	lsls r3, r3, #1
	adds r0, r6, r3
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r4, _08030784 @ =0x00000844
	adds r2, r6, r4
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	adds r0, r6, #0
	bl FUN_08028604
	ldr r0, _08030788 @ =0x0000084C
	adds r1, r6, r0
	adds r0, r6, #0
	movs r2, #0x40
	bl FUN_0802853c
	movs r1, #0xbf
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r1, [r0]
	adds r0, r6, #0
	bl FUN_08029a1c
_0803073E:
	adds r0, r6, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08030752
	b _08030952
_08030752:
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r6, r2
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	beq _0803076A
	b _08030952
_0803076A:
	movs r4, #0xb1
	lsls r4, r4, #1
	adds r1, r6, r4
	ldrh r2, [r1]
	movs r4, #0
	ldrsh r0, [r1, r4]
	cmp r0, #3
	ble _0803078C
	subs r0, r2, #4
	strh r0, [r1]
	b _0803078E
	.align 2, 0
_08030780: .4byte 0x00000899
_08030784: .4byte 0x00000844
_08030788: .4byte 0x0000084C
_0803078C:
	strh r3, [r1]
_0803078E:
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #3
	ble _080307A2
	subs r0, r2, #4
	b _080307A4
_080307A2:
	movs r0, #0
_080307A4:
	strh r0, [r1]
	movs r4, #0xaf
	lsls r4, r4, #1
	adds r5, r6, r4
	ldrh r1, [r5]
	cmp r1, #1
	beq _080308A4
	cmp r1, #1
	bgt _080307BC
	cmp r1, #0
	beq _080307C4
	b _08030926
_080307BC:
	cmp r1, #2
	bne _080307C2
	b _0803090E
_080307C2:
	b _08030926
_080307C4:
	ldr r0, _08030858 @ =0x00000899
	adds r1, r6, r0
	adds r0, r7, #0
	adds r0, #0xc8
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	adds r3, r7, #0
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
	adds r0, r7, #0
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r7, #0
	adds r0, #0xa1
	strb r1, [r0]
	movs r1, #0x84
	lsls r1, r1, #4
	adds r0, r6, r1
	ldr r2, _0803085C @ =0x00000842
	adds r1, r6, r2
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bhs _08030864
	adds r0, r6, #0
	bl FUN_08028648
	adds r0, r6, #0
	bl FUN_080286d8
	movs r3, #0xbd
	lsls r3, r3, #2
	adds r1, r6, r3
	movs r4, #0xb5
	lsls r4, r4, #2
	adds r2, r6, r4
	movs r0, #2
	str r0, [sp]
	movs r0, #3
	str r0, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	adds r0, r7, #0
	movs r3, #0x3a
	bl Boss_PlayAnimFacing
	ldr r1, _08030860 @ =0x000008E4
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #3
	bls _08030926
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08028838
	b _08030926
	.align 2, 0
_08030858: .4byte 0x00000899
_0803085C: .4byte 0x00000842
_08030860: .4byte 0x000008E4
_08030864:
	adds r0, r6, #0
	adds r0, #0x48
	ldrb r0, [r0, #5]
	subs r0, #0x20
	movs r1, #0x40
	rsbs r1, r1, #0
	ands r0, r1
	adds r0, #0x40
	ldr r2, _080308A0 @ =0x000008DA
	adds r1, r6, r2
	strb r0, [r1]
	movs r3, #0xbd
	lsls r3, r3, #2
	adds r1, r6, r3
	movs r4, #0xb5
	lsls r4, r4, #2
	adds r2, r6, r4
	movs r0, #2
	str r0, [sp]
	movs r0, #3
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r7, #0
	movs r3, #0x3b
	bl Boss_PlayAnimFacing
	ldrh r0, [r5]
	adds r0, #1
	b _08030924
	.align 2, 0
_080308A0: .4byte 0x000008DA
_080308A4:
	ldr r1, _080308E4 @ =0x00000311
	adds r0, r6, r1
	ldrb r1, [r0]
	movs r3, #2
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _08030926
	movs r2, #0xae
	lsls r2, r2, #1
	adds r4, r6, r2
	ldrh r0, [r4]
	cmp r0, #0
	beq _080308E8
	movs r4, #0xbd
	lsls r4, r4, #2
	adds r1, r6, r4
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r2, r6, r0
	str r3, [sp]
	movs r0, #3
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r7, #0
	movs r3, #0x3c
	bl Boss_PlayAnimFacing
	ldrh r0, [r5]
	adds r0, #1
	b _08030924
	.align 2, 0
_080308E4: .4byte 0x00000311
_080308E8:
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r2, r6, r0
	str r3, [sp]
	movs r0, #3
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r7, #0
	movs r3, #0x3b
	bl Boss_PlayAnimFacing
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	b _08030926
_0803090E:
	ldr r2, _0803095C @ =0x00000311
	adds r0, r6, r2
	ldrb r0, [r0]
	ands r1, r0
	cmp r1, #0
	beq _08030926
	adds r0, r7, #0
	adds r0, #0xa7
	movs r1, #1
	strb r1, [r0]
	movs r0, #3
_08030924:
	strh r0, [r5]
_08030926:
	movs r3, #0xaf
	lsls r3, r3, #1
	adds r0, r6, r3
	ldrh r0, [r0]
	cmp r0, #1
	bne _08030952
	movs r4, #0xc2
	lsls r4, r4, #2
	adds r0, r6, r4
	ldrh r0, [r0]
	cmp r0, #1
	bne _08030952
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _08030952
	adds r0, r6, #0
	movs r1, #2
	bl FUN_080292c8
_08030952:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803095C: .4byte 0x00000311
