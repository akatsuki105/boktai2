	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r6, r2, #0
	ldr r0, _0801560C @ =0x03000060
	ldr r0, [r0]
	cmp r0, #0
	bne _08015614
	movs r0, #0
	movs r1, #0
	bl Entity08015584_Create
	cmp r0, #0
	bne _08015614
	b _08015A7A
	.align 2, 0
_0801560C: .4byte 0x03000060
_08015610:
	movs r0, #0
	b _08015A7E
_08015614:
	movs r0, #0
	str r0, [sp, #0x10]
	movs r1, #0
	str r1, [sp, #0xc]
	ldr r2, _0801565C @ =0x03000060
	mov sl, r2
	ldr r3, _08015660 @ =0x030046B8
	mov sb, r3
_08015624:
	ldr r1, [sp, #0xc]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x24
	mov r2, sl
	ldr r1, [r2]
	adds r5, r1, r0
	movs r3, #0x3c
	adds r3, r3, r5
	mov r8, r3
	ldrb r1, [r5]
	cmp r1, #0
	beq _08015642
	b _08015A6E
_08015642:
	movs r0, #1
	strb r0, [r5]
	ldrh r0, [r6]
	strb r0, [r5, #1]
	strh r1, [r5, #2]
	movs r1, #0xa
	ldrsh r0, [r6, r1]
	cmp r0, #0
	bne _08015664
	ldrh r0, [r6, #8]
	strh r0, [r5, #4]
	b _08015686
	.align 2, 0
_0801565C: .4byte 0x03000060
_08015660: .4byte 0x030046B8
_08015664:
	mov r2, sb
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08015694 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _08015698 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r2, #0xa
	ldrsh r1, [r6, r2]
	bl Mod
	ldrh r1, [r6, #8]
	adds r1, r1, r0
	strh r1, [r5, #4]
_08015686:
	movs r3, #0xe
	ldrsh r0, [r6, r3]
	cmp r0, #0
	bne _0801569C
	ldrh r0, [r6, #0xc]
	strh r0, [r5, #6]
	b _080156C0
	.align 2, 0
_08015694: .4byte 0x000003FF
_08015698: .4byte 0x0203B400
_0801569C:
	mov r1, sb
	ldr r0, [r1]
	adds r0, #1
	ldr r1, _080156CC @ =0x000003FF
	ands r0, r1
	mov r2, sb
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _080156D0 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r2, #0xe
	ldrsh r1, [r6, r2]
	bl Mod
	ldrh r1, [r6, #0xc]
	adds r1, r1, r0
	strh r1, [r5, #6]
_080156C0:
	ldrh r0, [r6, #0x12]
	cmp r0, #0
	bne _080156D4
	ldrh r7, [r6, #0x10]
	b _080156F2
	.align 2, 0
_080156CC: .4byte 0x000003FF
_080156D0: .4byte 0x0203B400
_080156D4:
	mov r3, sb
	ldr r0, [r3]
	adds r0, #1
	ldr r1, _080156FC @ =0x000003FF
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	ldr r1, _08015700 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ldrh r1, [r6, #0x12]
	bl Mod
	ldrh r1, [r6, #0x10]
	adds r7, r1, r0
_080156F2:
	ldrh r0, [r6, #0x16]
	cmp r0, #0
	bne _08015704
	ldrh r4, [r6, #0x14]
	b _08015722
	.align 2, 0
_080156FC: .4byte 0x000003FF
_08015700: .4byte 0x0203B400
_08015704:
	mov r2, sb
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08015730 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _08015734 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldrh r1, [r6, #0x16]
	bl Mod
	ldrh r1, [r6, #0x14]
	adds r4, r1, r0
_08015722:
	ldrh r0, [r6, #0x1a]
	cmp r0, #0
	bne _08015738
	ldrh r0, [r6, #0x18]
	strh r0, [r5, #8]
	b _0801575A
	.align 2, 0
_08015730: .4byte 0x000003FF
_08015734: .4byte 0x0203B400
_08015738:
	mov r1, sb
	ldr r0, [r1]
	adds r0, #1
	ldr r1, _08015768 @ =0x000003FF
	ands r0, r1
	mov r2, sb
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _0801576C @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldrh r1, [r6, #0x1a]
	bl Mod
	ldrh r1, [r6, #0x18]
	adds r1, r1, r0
	strh r1, [r5, #8]
_0801575A:
	ldrh r0, [r6, #0x22]
	cmp r0, #0
	bne _08015770
	ldrh r0, [r6, #0x20]
	strh r0, [r5, #0xc]
	b _08015792
	.align 2, 0
_08015768: .4byte 0x000003FF
_0801576C: .4byte 0x0203B400
_08015770:
	mov r1, sb
	ldr r0, [r1]
	adds r0, #1
	ldr r1, _080157AC @ =0x000003FF
	ands r0, r1
	mov r2, sb
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _080157B0 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldrh r1, [r6, #0x22]
	bl Mod
	ldrh r1, [r6, #0x20]
	adds r1, r1, r0
	strh r1, [r5, #0xc]
_08015792:
	ldrh r1, [r6, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080157B4
	mov r1, r8
	ldr r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #2
	orrs r0, r1
	mov r2, r8
	str r0, [r2]
	b _080157C2
	.align 2, 0
_080157AC: .4byte 0x000003FF
_080157B0: .4byte 0x0203B400
_080157B4:
	mov r3, r8
	ldr r0, [r3]
	ldr r1, _080157DC @ =0xFFFFFDFF
	ands r0, r1
	ldr r1, _080157E0 @ =0xFFFFFBFF
	ands r0, r1
	str r0, [r3]
_080157C2:
	ldrh r1, [r6, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080157E4
	mov r1, r8
	ldr r0, [r1]
	movs r1, #0x10
	orrs r0, r1
	mov r2, r8
	str r0, [r2]
	b _080157F0
	.align 2, 0
_080157DC: .4byte 0xFFFFFDFF
_080157E0: .4byte 0xFFFFFBFF
_080157E4:
	mov r3, r8
	ldr r0, [r3]
	movs r1, #0x11
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3]
_080157F0:
	ldr r2, _08015828 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r5, #0x10]
	ands r7, r1
	lsls r0, r7, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r5, #0x12]
	ands r4, r1
	lsls r0, r4, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r5, #0x14]
	movs r0, #0x10
	ldrsh r1, [r5, r0]
	movs r2, #6
	ldrsh r0, [r5, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _0801582C
	asrs r0, r0, #0xc
	b _08015832
	.align 2, 0
_08015828: .4byte gSineTable
_0801582C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08015832:
	strh r0, [r5, #0x18]
	movs r3, #0x12
	ldrsh r1, [r5, r3]
	movs r2, #4
	ldrsh r0, [r5, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _08015846
	asrs r0, r0, #0xc
	b _0801584C
_08015846:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0801584C:
	strh r0, [r5, #0x1a]
	movs r3, #0x14
	ldrsh r1, [r5, r3]
	movs r2, #6
	ldrsh r0, [r5, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _08015860
	asrs r0, r0, #0xc
	b _08015866
_08015860:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08015866:
	movs r7, #0
	strh r0, [r5, #0x1c]
	ldrb r0, [r5, #1]
	cmp r0, #5
	bne _080158A8
	adds r4, r5, #0
	adds r4, #0x20
	adds r0, r4, #0
	ldr r1, _080158A4 @ =0x000061F9
	bl Video_GetAuxSprite
	adds r0, r4, #0
	movs r1, #0x89
	lsls r1, r1, #2
	bl Video_SetAuxSpritePltt
	adds r1, r5, #0
	adds r1, #0x3c
	movs r0, #0x20
	strh r0, [r1, #0x10]
	adds r4, #0x48
	mov r3, sl
	ldr r0, [r3]
	ldr r1, [r0, #0x1c]
	str r7, [sp]
	adds r0, r4, #0
	movs r2, #6
	movs r3, #0
	bl AuxAnim_SetAnim
	b _0801594E
	.align 2, 0
_080158A4: .4byte 0x000061F9
_080158A8:
	cmp r0, #6
	bne _080158E4
	adds r4, r5, #0
	adds r4, #0x20
	adds r0, r4, #0
	ldr r1, _080158E0 @ =0x000061F9
	bl Video_GetAuxSprite
	adds r0, r4, #0
	movs r1, #0x8b
	lsls r1, r1, #2
	bl Video_SetAuxSpritePltt
	adds r1, r5, #0
	adds r1, #0x3c
	movs r0, #0x20
	strh r0, [r1, #0x10]
	adds r4, #0x48
	mov r1, sl
	ldr r0, [r1]
	ldr r1, [r0, #0x1c]
	str r7, [sp]
	adds r0, r4, #0
	movs r2, #6
	movs r3, #0
	bl AuxAnim_SetAnim
	b _0801594E
	.align 2, 0
_080158E0: .4byte 0x000061F9
_080158E4:
	cmp r0, #7
	bne _08015924
	adds r4, r5, #0
	adds r4, #0x20
	adds r0, r4, #0
	ldr r1, _0801591C @ =0x000061F9
	bl Video_GetAuxSprite
	adds r0, r4, #0
	ldr r1, _08015920 @ =0x0000022B
	bl Video_SetAuxSpritePltt
	adds r1, r5, #0
	adds r1, #0x3c
	movs r0, #0x2d
	strh r0, [r1, #0x10]
	adds r4, #0x48
	mov r2, sl
	ldr r0, [r2]
	ldr r1, [r0, #0x1c]
	str r7, [sp]
	adds r0, r4, #0
	movs r2, #8
	movs r3, #0
	bl AuxAnim_SetAnim
	b _0801594E
	.align 2, 0
_0801591C: .4byte 0x000061F9
_08015920: .4byte 0x0000022B
_08015924:
	adds r4, r5, #0
	adds r4, #0x20
	adds r0, r4, #0
	ldr r1, _08015988 @ =0x00004384
	bl Video_GetAuxSprite
	ldrb r1, [r5, #1]
	adds r1, #0x7d
	adds r0, r4, #0
	bl Video_SetAuxSpritePltt
	adds r4, #0x48
	mov r3, sl
	ldr r0, [r3]
	ldr r1, [r0, #0x18]
	str r7, [sp]
	adds r0, r4, #0
	movs r2, #0
	movs r3, #0
	bl AuxAnim_SetAnim
_0801594E:
	adds r7, r4, #0
	adds r4, r7, #0
	ldrh r0, [r7, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x68]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	mov r1, r8
	strh r0, [r1, #0x10]
	ldrb r0, [r7, #4]
	movs r2, #1
	ands r2, r0
	ldrh r1, [r5]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	movs r3, #1
	ands r0, r3
	cmp r2, r0
	beq _0801598C
	mov r1, r8
	ldr r0, [r1]
	movs r1, #4
	orrs r0, r1
	mov r2, r8
	str r0, [r2]
	b _08015998
	.align 2, 0
_08015988: .4byte 0x00004384
_0801598C:
	mov r3, r8
	ldr r0, [r3]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3]
_08015998:
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080159C0
	mov r1, r8
	ldr r0, [r1]
	movs r1, #8
	orrs r0, r1
	mov r2, r8
	str r0, [r2]
	b _080159CC
_080159C0:
	mov r3, r8
	ldr r0, [r3]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3]
_080159CC:
	ldrh r0, [r4, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r4, #0xe]
	ldr r3, _08015A00 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _08015A38
	strh r1, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08015A04
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080159FA
	ldrb r0, [r4, #5]
_080159FA:
	subs r0, #1
	strh r0, [r4, #8]
	b _08015A14
	.align 2, 0
_08015A00: .4byte 0x0000FFFF
_08015A04:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08015A14
	strh r1, [r4, #8]
_08015A14:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08015A38
	movs r3, #1
	strb r3, [r4, #7]
_08015A38:
	ldr r2, [sp, #8]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	mov r3, r8
	str r0, [r3, #0x1c]
	str r1, [r3, #0x20]
	ldrh r0, [r6, #2]
	bl FUN_080155c8
	mov r1, r8
	strb r0, [r1, #7]
	ldrh r1, [r6, #6]
	adds r0, r7, #0
	bl AuxAnim_SetAnimSpeed
	mov r0, r8
	movs r1, #0
	bl Video_AddAuxSpriteIntoDrawList
	ldr r0, [sp, #0x10]
	adds r2, r0, #0
	adds r2, #1
	str r2, [sp, #0x10]
	ldr r3, [sp, #4]
	cmp r0, r3
	blt _08015A6E
	b _08015610
_08015A6E:
	ldr r0, [sp, #0xc]
	adds r0, #1
	str r0, [sp, #0xc]
	cmp r0, #0x1f
	bgt _08015A7A
	b _08015624
_08015A7A:
	movs r0, #1
	rsbs r0, r0, #0
_08015A7E:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
