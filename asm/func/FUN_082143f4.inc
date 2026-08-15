	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r7, r0, #0
	movs r0, #0xec
	lsls r0, r0, #1
	adds r0, r0, r7
	mov sl, r0
	movs r6, #0
	movs r1, #0xd7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r0, [r0]
	str r0, [sp, #0xc]
	adds r1, #4
	adds r0, r7, r1
	ldrb r0, [r0]
	str r0, [sp, #0x10]
	adds r1, #1
	adds r0, r7, r1
	ldrb r0, [r0]
	str r0, [sp, #0x14]
	adds r1, #1
	adds r0, r7, r1
	ldrb r0, [r0]
	str r0, [sp, #0x18]
	adds r1, #1
	adds r0, r7, r1
	ldrb r0, [r0]
	str r0, [sp, #0x1c]
	movs r2, #1
	ldr r1, [r7, #0x44]
	ands r2, r1
	cmp r2, #0
	beq _08214442
	movs r2, #1
_08214442:
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r7, #0x44]
	cmp r2, #0
	beq _082144AE
	movs r0, #0
	bl FUN_0822b644
	str r6, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	movs r0, #2
	bl FUN_0822b644
	str r6, [sp]
	movs r0, #2
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	movs r0, #3
	bl FUN_0822b644
	str r6, [sp]
	movs r0, #3
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	movs r4, #2
	ldr r1, [r7, #0x38]
	movs r0, #2
	movs r2, #2
	bl FUN_0822c398
	str r6, [sp]
	movs r0, #2
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	str r4, [r7, #0x64]
	adds r0, r7, #0
	bl FUN_08214274
	str r6, [r7, #0x68]
_082144AE:
	ldr r1, [r7, #0x5c]
	cmp r1, #4
	bgt _08214570
	ldr r0, _082144C8 @ =0x030044E0
	ldrh r2, [r0, #2]
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _082144E2
	cmp r1, #0
	bgt _082144CC
	movs r0, #4
	b _082144CE
	.align 2, 0
_082144C8: .4byte 0x030044E0
_082144CC:
	subs r0, r1, #1
_082144CE:
	str r0, [r7, #0x5c]
	str r6, [r7, #0x60]
	movs r1, #2
	ldr r0, [r7, #0x44]
	orrs r0, r1
	str r0, [r7, #0x44]
	movs r0, #0xdc
	bl PlaySound_082406e0
	b _08214506
_082144E2:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _08214506
	cmp r1, #3
	ble _082144F2
	str r6, [r7, #0x5c]
	b _082144F6
_082144F2:
	adds r0, r1, #1
	str r0, [r7, #0x5c]
_082144F6:
	str r6, [r7, #0x60]
	movs r1, #2
	ldr r0, [r7, #0x44]
	orrs r0, r1
	str r0, [r7, #0x44]
	movs r0, #0xdc
	bl PlaySound_082406e0
_08214506:
	ldr r4, _0821453C @ =0x030044E0
	ldrh r1, [r4, #2]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _08214522
	movs r0, #5
	str r0, [r7, #0x5c]
	movs r0, #0
	str r0, [r7, #0x60]
	movs r1, #2
	ldr r0, [r7, #0x44]
	orrs r0, r1
	str r0, [r7, #0x44]
_08214522:
	ldrh r1, [r4, #2]
	movs r5, #0x40
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	bne _0821456A
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08214540
	movs r6, #2
	b _08214570
	.align 2, 0
_0821453C: .4byte 0x030044E0
_08214540:
	ldrh r0, [r4]
	movs r1, #0xc0
	ands r1, r0
	cmp r1, #0
	beq _0821456E
	ldr r0, [r7, #0x68]
	adds r0, #1
	str r0, [r7, #0x68]
	cmp r0, #0xe
	ble _08214570
	movs r1, #5
	bl Mod
	cmp r0, #0
	bne _08214570
	ldrh r1, [r4]
	adds r0, r5, #0
	ands r0, r1
	movs r6, #2
	cmp r0, #0
	beq _08214570
_0821456A:
	movs r6, #1
	b _08214570
_0821456E:
	str r1, [r7, #0x68]
_08214570:
	ldr r4, [r7, #0x5c]
	cmp r4, #3
	bne _08214578
	b _082146C4
_08214578:
	cmp r4, #3
	bgt _0821458A
	cmp r4, #1
	beq _082145FE
	cmp r4, #1
	bgt _08214658
	cmp r4, #0
	beq _0821459E
	b _08214826
_0821458A:
	cmp r4, #5
	bne _08214590
	b _08214782
_08214590:
	cmp r4, #5
	bge _08214596
	b _0821471C
_08214596:
	cmp r4, #0x63
	bne _0821459C
	b _08214810
_0821459C:
	b _08214826
_0821459E:
	movs r2, #2
	ldr r1, [r7, #0x44]
	ands r2, r1
	cmp r2, #0
	beq _082145AA
	movs r2, #1
_082145AA:
	movs r0, #3
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r7, #0x44]
	cmp r2, #0
	beq _082145C0
	adds r0, r7, #0
	bl FUN_08214334
	str r4, [r7, #0x68]
	movs r6, #0
_082145C0:
	cmp r6, #1
	bne _082145E0
	movs r2, #0x9c
	lsls r2, r2, #3
	add r2, sl
	ldr r1, [r2]
	ldr r0, _082145DC @ =0x00000832
	cmp r1, r0
	ble _082145D4
	b _08214826
_082145D4:
	adds r0, r1, #1
	str r0, [r2]
	b _08214778
	.align 2, 0
_082145DC: .4byte 0x00000832
_082145E0:
	cmp r6, #2
	beq _082145E6
	b _08214826
_082145E6:
	movs r2, #0x9c
	lsls r2, r2, #3
	add r2, sl
	ldr r1, [r2]
	movs r0, #0xfa
	lsls r0, r0, #3
	cmp r1, r0
	bgt _082145F8
	b _08214826
_082145F8:
	subs r0, r1, #1
	str r0, [r2]
	b _08214778
_082145FE:
	movs r2, #2
	ldr r1, [r7, #0x44]
	ands r2, r1
	cmp r2, #0
	beq _0821460A
	movs r2, #1
_0821460A:
	movs r0, #3
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r7, #0x44]
	cmp r2, #0
	beq _08214622
	adds r0, r7, #0
	bl FUN_08214334
	movs r0, #0
	str r0, [r7, #0x68]
	movs r6, #0
_08214622:
	cmp r6, #1
	bne _0821463C
	ldr r1, _08214634 @ =0x000004E4
	add r1, sl
	ldrb r0, [r1]
	cmp r0, #0xb
	bls _08214638
_08214630:
	strb r6, [r1]
	b _08214778
	.align 2, 0
_08214634: .4byte 0x000004E4
_08214638:
	adds r0, #1
	b _08214776
_0821463C:
	cmp r6, #2
	beq _08214642
	b _08214826
_08214642:
	ldr r1, _08214654 @ =0x000004E4
	add r1, sl
	ldrb r0, [r1]
	cmp r0, #1
	bls _0821464E
	b _08214774
_0821464E:
	movs r0, #0xc
	b _08214776
	.align 2, 0
_08214654: .4byte 0x000004E4
_08214658:
	movs r2, #2
	ldr r1, [r7, #0x44]
	ands r2, r1
	cmp r2, #0
	beq _08214664
	movs r2, #1
_08214664:
	movs r0, #3
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r7, #0x44]
	cmp r2, #0
	beq _0821467C
	adds r0, r7, #0
	bl FUN_08214334
	movs r0, #0
	str r0, [r7, #0x68]
	movs r6, #0
_0821467C:
	movs r0, #0x9c
	lsls r0, r0, #3
	add r0, sl
	ldr r0, [r0]
	ldr r1, _082146A4 @ =0x000004E4
	add r1, sl
	ldrb r1, [r1]
	bl GetDaysInMonth
	adds r5, r0, #0
	cmp r6, #1
	bne _082146AC
	ldr r1, _082146A8 @ =0x000004E5
	add r1, sl
	ldrb r0, [r1]
	cmp r0, r5
	bge _08214630
	adds r0, #1
	b _08214776
	.align 2, 0
_082146A4: .4byte 0x000004E4
_082146A8: .4byte 0x000004E5
_082146AC:
	cmp r6, #2
	beq _082146B2
	b _08214826
_082146B2:
	ldr r1, _082146C0 @ =0x000004E5
	add r1, sl
	ldrb r0, [r1]
	cmp r0, #1
	bhi _08214774
	strb r5, [r1]
	b _08214778
	.align 2, 0
_082146C0: .4byte 0x000004E5
_082146C4:
	movs r2, #2
	ldr r1, [r7, #0x44]
	ands r2, r1
	cmp r2, #0
	beq _082146D0
	movs r2, #1
_082146D0:
	movs r0, #3
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r7, #0x44]
	cmp r2, #0
	beq _082146E8
	adds r0, r7, #0
	bl FUN_08214334
	movs r0, #0
	str r0, [r7, #0x68]
	movs r6, #0
_082146E8:
	cmp r6, #1
	bne _08214704
	ldr r1, _082146FC @ =0x000004E6
	add r1, sl
	ldrb r0, [r1]
	cmp r0, #0x16
	bls _08214700
	movs r0, #0
	b _08214776
	.align 2, 0
_082146FC: .4byte 0x000004E6
_08214700:
	adds r0, #1
	b _08214776
_08214704:
	cmp r6, #2
	beq _0821470A
	b _08214826
_0821470A:
	ldr r1, _08214718 @ =0x000004E6
	add r1, sl
	ldrb r0, [r1]
	cmp r0, #0
	bne _08214774
	movs r0, #0x17
	b _08214776
	.align 2, 0
_08214718: .4byte 0x000004E6
_0821471C:
	movs r2, #2
	ldr r1, [r7, #0x44]
	ands r2, r1
	cmp r2, #0
	beq _08214728
	movs r2, #1
_08214728:
	movs r0, #3
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r7, #0x44]
	cmp r2, #0
	beq _08214740
	adds r0, r7, #0
	bl FUN_08214334
	movs r0, #0
	str r0, [r7, #0x68]
	movs r6, #0
_08214740:
	cmp r6, #1
	bne _0821475C
	ldr r1, _08214754 @ =0x000004E7
	add r1, sl
	ldrb r0, [r1]
	cmp r0, #0x3a
	bls _08214758
	movs r0, #0
	b _08214776
	.align 2, 0
_08214754: .4byte 0x000004E7
_08214758:
	adds r0, #1
	b _08214776
_0821475C:
	cmp r6, #2
	bne _08214826
	ldr r1, _08214770 @ =0x000004E7
	add r1, sl
	ldrb r0, [r1]
	cmp r0, #0
	bne _08214774
	movs r0, #0x3b
	b _08214776
	.align 2, 0
_08214770: .4byte 0x000004E7
_08214774:
	subs r0, #1
_08214776:
	strb r0, [r1]
_08214778:
	movs r0, #0xcd
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _08214826
_08214782:
	movs r6, #2
	ldr r2, [r7, #0x44]
	adds r1, r2, #0
	ands r1, r6
	cmp r1, #0
	beq _08214790
	movs r1, #1
_08214790:
	movs r0, #3
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r7, #0x44]
	cmp r1, #0
	beq _082147DE
	movs r0, #0xdd
	bl PlaySound_082406e0
	movs r0, #0x9c
	lsls r0, r0, #3
	add r0, sl
	ldr r0, [r0]
	ldr r1, _082147F4 @ =0x000004E4
	add r1, sl
	ldrb r1, [r1]
	ldr r2, _082147F8 @ =0x000004E5
	add r2, sl
	ldrb r2, [r2]
	ldr r3, _082147FC @ =0x000004E6
	add r3, sl
	ldrb r3, [r3]
	ldr r4, _08214800 @ =0x000004E7
	add r4, sl
	ldrb r4, [r4]
	str r4, [sp]
	movs r5, #0
	str r5, [sp, #4]
	movs r4, #1
	str r4, [sp, #8]
	bl SetGameDateTime
	ldr r0, _08214804 @ =0x0023A666
	ldr r1, _08214808 @ =0x008BC000
	movs r2, #0
	bl FUN_082401e8
	ldr r0, _0821480C @ =0x030047E0
	strb r5, [r0, #9]
_082147DE:
	ldr r0, [r7, #0x60]
	cmp r0, #0x3b
	ble _08214826
	movs r0, #0x63
	str r0, [r7, #0x5c]
	movs r0, #0
	str r0, [r7, #0x60]
	ldr r0, [r7, #0x44]
	orrs r0, r6
	str r0, [r7, #0x44]
	b _08214826
	.align 2, 0
_082147F4: .4byte 0x000004E4
_082147F8: .4byte 0x000004E5
_082147FC: .4byte 0x000004E6
_08214800: .4byte 0x000004E7
_08214804: .4byte 0x0023A666
_08214808: .4byte 0x008BC000
_0821480C: .4byte 0x030047E0
_08214810:
	movs r0, #2
	ldr r1, [r7, #0x44]
	ands r0, r1
	movs r0, #3
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r7, #0x44]
	adds r0, r7, #0
	movs r1, #3
	bl FUN_08219f34
_08214826:
	movs r0, #0x9c
	lsls r0, r0, #3
	add r0, sl
	ldr r0, [r0]
	ldr r1, [sp, #0xc]
	cmp r0, r1
	beq _08214874
	mov sb, sl
	adds r5, r0, #0
	movs r6, #0
	movs r0, #0x18
	adds r0, r0, r7
	mov r8, r0
_08214840:
	movs r0, #3
	subs r0, r0, r6
	lsls r4, r0, #1
	adds r4, r4, r0
	lsls r4, r4, #5
	add r4, sb
	adds r0, r5, #0
	movs r1, #0xa
	bl Mod
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	mov r1, r8
	movs r3, #1
	bl Sprite_SetSprite
	adds r0, r5, #0
	movs r1, #0xa
	bl Div
	adds r5, r0, #0
	adds r6, #1
	cmp r6, #3
	ble _08214840
_08214874:
	ldr r0, _08214A14 @ =0x000004E4
	add r0, sl
	ldrb r0, [r0]
	ldr r1, [sp, #0x10]
	cmp r0, r1
	beq _082148C6
	movs r1, #0xc0
	lsls r1, r1, #1
	add r1, sl
	mov sb, r1
	adds r5, r0, #0
	movs r6, #0
	movs r0, #0x18
	adds r0, r0, r7
	mov r8, r0
_08214892:
	movs r0, #1
	subs r0, r0, r6
	lsls r4, r0, #1
	adds r4, r4, r0
	lsls r4, r4, #5
	add r4, sb
	adds r0, r5, #0
	movs r1, #0xa
	bl Mod
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	mov r1, r8
	movs r3, #1
	bl Sprite_SetSprite
	adds r0, r5, #0
	movs r1, #0xa
	bl Div
	adds r5, r0, #0
	adds r6, #1
	cmp r6, #1
	ble _08214892
_082148C6:
	movs r0, #0x9c
	lsls r0, r0, #3
	add r0, sl
	ldr r2, [r0]
	ldr r1, [sp, #0xc]
	cmp r2, r1
	bne _082148E0
	ldr r0, _08214A14 @ =0x000004E4
	add r0, sl
	ldrb r0, [r0]
	ldr r1, [sp, #0x10]
	cmp r0, r1
	beq _082148FA
_082148E0:
	ldr r0, _08214A14 @ =0x000004E4
	add r0, sl
	ldrb r1, [r0]
	adds r0, r2, #0
	bl GetDaysInMonth
	adds r5, r0, #0
	ldr r1, _08214A18 @ =0x000004E5
	add r1, sl
	ldrb r0, [r1]
	cmp r0, r5
	ble _082148FA
	strb r5, [r1]
_082148FA:
	ldr r0, _08214A18 @ =0x000004E5
	add r0, sl
	ldrb r0, [r0]
	ldr r1, [sp, #0x14]
	cmp r0, r1
	beq _0821494C
	movs r1, #0x90
	lsls r1, r1, #2
	add r1, sl
	mov sb, r1
	adds r5, r0, #0
	movs r6, #0
	movs r0, #0x18
	adds r0, r0, r7
	mov r8, r0
_08214918:
	movs r0, #1
	subs r0, r0, r6
	lsls r4, r0, #1
	adds r4, r4, r0
	lsls r4, r4, #5
	add r4, sb
	adds r0, r5, #0
	movs r1, #0xa
	bl Mod
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	mov r1, r8
	movs r3, #1
	bl Sprite_SetSprite
	adds r0, r5, #0
	movs r1, #0xa
	bl Div
	adds r5, r0, #0
	adds r6, #1
	cmp r6, #1
	ble _08214918
_0821494C:
	ldr r0, _08214A1C @ =0x000004E6
	add r0, sl
	ldrb r0, [r0]
	ldr r1, [sp, #0x18]
	cmp r0, r1
	beq _0821499E
	movs r1, #0xc0
	lsls r1, r1, #2
	add r1, sl
	mov sb, r1
	adds r5, r0, #0
	movs r6, #0
	movs r0, #0x18
	adds r0, r0, r7
	mov r8, r0
_0821496A:
	movs r0, #1
	subs r0, r0, r6
	lsls r4, r0, #1
	adds r4, r4, r0
	lsls r4, r4, #5
	add r4, sb
	adds r0, r5, #0
	movs r1, #0xa
	bl Mod
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	mov r1, r8
	movs r3, #1
	bl Sprite_SetSprite
	adds r0, r5, #0
	movs r1, #0xa
	bl Div
	adds r5, r0, #0
	adds r6, #1
	cmp r6, #1
	ble _0821496A
_0821499E:
	ldr r0, _08214A20 @ =0x000004E7
	add r0, sl
	ldrb r0, [r0]
	ldr r1, [sp, #0x1c]
	cmp r0, r1
	beq _082149F0
	movs r1, #0xf0
	lsls r1, r1, #2
	add r1, sl
	mov sb, r1
	adds r5, r0, #0
	movs r6, #0
	movs r0, #0x18
	adds r0, r0, r7
	mov r8, r0
_082149BC:
	movs r0, #1
	subs r0, r0, r6
	lsls r4, r0, #1
	adds r4, r4, r0
	lsls r4, r4, #5
	add r4, sb
	adds r0, r5, #0
	movs r1, #0xa
	bl Mod
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	mov r1, r8
	movs r3, #1
	bl Sprite_SetSprite
	adds r0, r5, #0
	movs r1, #0xa
	bl Div
	adds r5, r0, #0
	adds r6, #1
	cmp r6, #1
	ble _082149BC
_082149F0:
	ldr r0, [r7, #0x5c]
	cmp r0, #4
	bgt _08214A04
	movs r0, #0x90
	lsls r0, r0, #3
	add r0, sl
	adds r1, r7, #0
	adds r1, #0x18
	bl FUN_082372cc
_08214A04:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08214A14: .4byte 0x000004E4
_08214A18: .4byte 0x000004E5
_08214A1C: .4byte 0x000004E6
_08214A20: .4byte 0x000004E7
