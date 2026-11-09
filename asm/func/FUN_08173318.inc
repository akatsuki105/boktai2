	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov sl, r0
	ldr r2, _08173344 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08173348
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0817334A
	.align 2, 0
_08173344: .4byte 0x0000046C
_08173348:
	movs r0, #0
_0817334A:
	cmp r0, #0
	beq _081733CA
	ldr r3, _0817339C @ =0x00000256
	adds r0, r5, r3
	ldrh r1, [r0]
	ldr r0, _081733A0 @ =0x00000FB6
	add r0, sl
	strh r1, [r0]
	ldrh r6, [r0]
	ldr r7, _081733A4 @ =0x00001058
	add r7, sl
	ldr r0, _081733A8 @ =0x030046A4
	mov r8, r0
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r6, #0
	bl Mod
	adds r4, r0, #0
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r6, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r7]
	adds r0, r6, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081733AC
	adds r0, #4
	b _081733B8
	.align 2, 0
_0817339C: .4byte 0x00000256
_081733A0: .4byte 0x00000FB6
_081733A4: .4byte 0x00001058
_081733A8: .4byte 0x030046A4
_081733AC:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r6, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081733B8:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #8
	strh r1, [r7, #2]
	mov r1, sb
	lsls r0, r1, #8
	adds r0, #0x80
	strh r0, [r7, #4]
_081733CA:
	movs r2, #0xb1
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r7, r0, #0
	ldr r1, _081733F8 @ =0x0000A02F
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08173400
	ldr r0, _081733FC @ =0x00000482
	adds r1, r5, r0
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _08173410
	.align 2, 0
_081733F8: .4byte 0x0000A02F
_081733FC: .4byte 0x00000482
_08173400:
	ldr r1, _08173434 @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _08173410
	movs r0, #1
	strh r0, [r2]
_08173410:
	ldr r3, _08173438 @ =0x0000025D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0817343C
	ldr r4, [r5, #0x44]
	adds r4, #0x48
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl AuxAnim_SetAnimSpeed
	b _08173454
	.align 2, 0
_08173434: .4byte 0x00000482
_08173438: .4byte 0x0000025D
_0817343C:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl MainSprite_SetAnimSpeed
_08173454:
	movs r2, #0x10
	ldr r1, _08173468 @ =0x00001008
	add r1, sl
	ldrh r0, [r1]
	ands r0, r2
	mov sb, r1
	cmp r0, #0
	beq _0817346C
	movs r0, #1
	b _0817346E
	.align 2, 0
_08173468: .4byte 0x00001008
_0817346C:
	movs r0, #0
_0817346E:
	cmp r0, #0
	beq _08173480
	ldr r0, _08173498 @ =0x00000472
	adds r1, r5, r0
	ldr r2, _0817349C @ =0xFFFFFC00
	adds r0, r2, #0
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r5, #0xa]
_08173480:
	movs r3, #0xee
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrb r1, [r0]
	ldrb r0, [r5, #5]
	subs r1, r1, r0
	adds r3, r0, #0
	cmp r1, #0x80
	ble _081734A4
	ldr r0, _081734A0 @ =0xFFFFFF00
	adds r1, r1, r0
	b _081734B2
	.align 2, 0
_08173498: .4byte 0x00000472
_0817349C: .4byte 0xFFFFFC00
_081734A0: .4byte 0xFFFFFF00
_081734A4:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _081734B2
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
_081734B2:
	adds r6, r1, #0
	adds r0, r6, #0
	cmp r6, #0
	bge _081734BC
	rsbs r0, r6, #0
_081734BC:
	cmp r0, #8
	ble _0817350C
	ldr r2, _081734DC @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _081734E0
	asrs r0, r0, #0xc
	b _081734E6
	.align 2, 0
_081734DC: .4byte gSineTable
_081734E0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081734E6:
	adds r1, r0, #0
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r7, r0
	cmp r0, #0
	blt _081734FA
	asrs r2, r0, #0xc
	b _08173500
_081734FA:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08173500:
	ldrh r0, [r5, #0x10]
	adds r0, r0, r1
	strh r0, [r5, #0x10]
	ldrh r0, [r5, #0x14]
	adds r0, r0, r2
	strh r0, [r5, #0x14]
_0817350C:
	mov r4, sp
	adds r3, r5, #0
	adds r3, #8
	adds r2, r5, #0
	adds r2, #0x10
	ldrh r0, [r5, #0x10]
	ldrh r1, [r5, #8]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	adds r0, r0, r1
	strh r0, [r4, #2]
	ldrh r1, [r2, #4]
	ldrh r3, [r3, #4]
	adds r1, r1, r3
	strh r1, [r4, #4]
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _08173554
	cmp r1, #0
	blt _08173554
	ldr r0, _08173558 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08173554
	ldr r0, _0817355C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08173560
_08173554:
	movs r7, #0
	b _0817356E
	.align 2, 0
_08173558: .4byte 0x030046A8
_0817355C: .4byte 0x030046AC
_08173560:
	ldr r0, _081735F4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r7, r0, r2
_0817356E:
	ldr r2, _081735F8 @ =0x00000FB6
	add r2, sl
	mov r8, r2
	ldrh r0, [r2]
	cmp r0, r7
	beq _081735BE
	mov r4, sp
	ldr r2, _081735FC @ =0x00001058
	add r2, sl
	ldrh r1, [r2]
	mov r0, sp
	ldrh r0, [r0]
	subs r1, r1, r0
	mov r0, sp
	strh r1, [r0]
	ldrh r0, [r2, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	mov r0, sp
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r1, #0xa
	bl Div
	ldrh r1, [r5, #0x10]
	adds r1, r1, r0
	strh r1, [r5, #0x10]
	movs r1, #4
	ldrsh r0, [r4, r1]
	movs r1, #0xa
	bl Div
	ldrh r1, [r5, #0x14]
	adds r1, r1, r0
	strh r1, [r5, #0x14]
_081735BE:
	adds r0, r5, #0
	bl FUN_081765f8
	ldr r3, _08173600 @ =0x0000A410
	adds r0, r5, #0
	movs r1, #0xc
	movs r2, #0xc
	bl FUN_08177d34
	adds r0, r6, #0
	cmp r6, #0
	bge _081735D8
	rsbs r0, r6, #0
_081735D8:
	cmp r0, #7
	bgt _08173668
	mov r2, r8
	ldrh r0, [r2]
	cmp r0, r7
	bne _0817368E
	movs r1, #0x10
	mov r3, sb
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _08173604
	movs r0, #1
	b _08173606
	.align 2, 0
_081735F4: .4byte 0x030046A4
_081735F8: .4byte 0x00000FB6
_081735FC: .4byte 0x00001058
_08173600: .4byte 0x0000A410
_08173604:
	movs r0, #0
_08173606:
	adds r2, r0, #0
	cmp r2, #0
	beq _08173638
	movs r2, #0xe
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _08173630 @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r2, [r0]
	ldr r2, _08173634 @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r5, r3
	b _08173658
	.align 2, 0
_08173630: .4byte 0x00000469
_08173634: .4byte 0x00000484
_08173638:
	movs r1, #2
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r2, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r2, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r1, [r0]
	ldr r1, _08173660 @ =0x00000484
	adds r0, r5, r1
	str r2, [r0]
	ldr r2, _08173664 @ =0x0000046C
	adds r1, r5, r2
_08173658:
	movs r0, #1
	strb r0, [r1]
	b _0817368E
	.align 2, 0
_08173660: .4byte 0x00000484
_08173664: .4byte 0x0000046C
_08173668:
	cmp r6, #0
	ble _08173680
	ldr r3, _0817367C @ =0x00000482
	adds r0, r5, r3
	ldrh r0, [r0]
	lsls r0, r0, #1
	ldrb r1, [r5, #5]
	adds r0, r0, r1
	b _0817368C
	.align 2, 0
_0817367C: .4byte 0x00000482
_08173680:
	ldr r2, _081736A8 @ =0x00000482
	adds r0, r5, r2
	ldrh r1, [r0]
	lsls r1, r1, #1
	ldrb r0, [r5, #5]
	subs r0, r0, r1
_0817368C:
	strb r0, [r5, #5]
_0817368E:
	ldr r3, _081736AC @ =0x00000484
	adds r1, r5, r3
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081736A8: .4byte 0x00000482
_081736AC: .4byte 0x00000484
