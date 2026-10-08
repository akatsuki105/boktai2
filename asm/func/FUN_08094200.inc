	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldr r0, _08094234 @ =0x00001444
	adds r5, r4, r0
	adds r6, r4, #0
	adds r6, #0x60
	adds r0, r5, #0
	adds r1, r6, #0
	bl MainSprite_AdvanceAnim
	adds r0, r4, #0
	bl FUN_0808c548
	ldr r0, _08094238 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0809423C
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_08092744
	b _0809442E
	.align 2, 0
_08094234: .4byte 0x00001444
_08094238: .4byte 0x030044E0
_0809423C:
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080942B4
	ldr r1, _080942A0 @ =0x00003AE8
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080942B4
	ldr r0, _080942A4 @ =0x00001C2C
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _080942A8 @ =0x00001464
	adds r0, r4, r1
	movs r1, #0x14
	bl FUN_080921e8
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #0x38
	movs r3, #1
	bl MainSprite_SetPose
	ldr r0, _080942AC @ =0x0000204C
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r0, [r4, #0x58]
	movs r1, #2
	movs r2, #1
	bl EntityCC28_ShowBottomLine
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0808b6fc
	adds r0, r4, #0
	bl FUN_0808c700
	ldr r1, _080942B0 @ =FUN_0809458c
	b _080943D6
	.align 2, 0
_080942A0: .4byte 0x00003AE8
_080942A4: .4byte 0x00001C2C
_080942A8: .4byte 0x00001464
_080942AC: .4byte 0x0000204C
_080942B0: .4byte FUN_0809458c
_080942B4:
	ldr r0, _080942E4 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r7, #1
	adds r0, r7, #0
	ands r0, r1
	cmp r0, #0
	bne _080942C4
	b _08094406
_080942C4:
	adds r0, r4, #0
	bl FUN_0808c700
	adds r0, r4, #0
	bl FUN_080926c4
	cmp r0, #1
	beq _08094320
	cmp r0, #1
	bgt _080942DA
	b _080943FC
_080942DA:
	cmp r0, #2
	beq _080942E8
	cmp r0, #3
	beq _0809435C
	b _080943FC
	.align 2, 0
_080942E4: .4byte 0x030044E0
_080942E8:
	ldr r2, _08094314 @ =0x0000144C
	adds r1, r4, r2
	ldr r0, [r1]
	orrs r0, r7
	str r0, [r1]
	ldr r0, _08094318 @ =0x0000204C
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r7
	str r0, [r1]
	ldr r0, [r4, #0x58]
	movs r1, #2
	movs r2, #1
	bl EntityCC28_ShowBottomLine
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0808b6fc
	ldr r1, _0809431C @ =FUN_0809458c
	b _080943D6
	.align 2, 0
_08094314: .4byte 0x0000144C
_08094318: .4byte 0x0000204C
_0809431C: .4byte FUN_0809458c
_08094320:
	ldr r2, _08094350 @ =0x0000144C
	adds r1, r4, r2
	ldr r0, [r1]
	orrs r0, r7
	str r0, [r1]
	ldr r0, _08094354 @ =0x0000204C
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r7
	str r0, [r1]
	ldr r0, [r4, #0x58]
	movs r1, #3
	movs r2, #1
	bl EntityCC28_ShowBottomLine
	adds r0, r4, #0
	bl FUN_080921a8
	adds r1, r0, #0
	adds r0, r4, #0
	bl FUN_0808b6fc
	ldr r1, _08094358 @ =FUN_0809455c
	b _080943D6
	.align 2, 0
_08094350: .4byte 0x0000144C
_08094354: .4byte 0x0000204C
_08094358: .4byte FUN_0809455c
_0809435C:
	ldr r2, _080943E0 @ =0x0000144C
	adds r1, r4, r2
	ldr r0, [r1]
	orrs r0, r7
	str r0, [r1]
	ldr r0, _080943E4 @ =0x0000038A
	bl PlaySound_082406e0
	ldr r0, _080943E8 @ =0x00003F9C
	adds r5, r4, r0
	ldrb r0, [r5]
	ldr r1, _080943EC @ =0x00003AEE
	adds r6, r4, r1
	ldrb r1, [r6]
	bl GetItemID
	cmp r0, #0
	blt _08094390
	ldrb r2, [r6]
	ldr r1, _080943F0 @ =0x00003AEB
	adds r0, r4, r1
	ldrb r3, [r0]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08092300
_08094390:
	ldrb r0, [r5]
	ldr r2, _080943F0 @ =0x00003AEB
	adds r5, r4, r2
	ldrb r1, [r5]
	bl GetItemID
	cmp r0, #0
	blt _080943AC
	ldrb r2, [r5]
	ldrb r3, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08092300
_080943AC:
	ldrb r0, [r6]
	adds r0, #0x11
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #5
	ldr r0, _080943F4 @ =0x00000F6C
	adds r2, r4, r0
	adds r1, r2, r1
	ldr r0, [r1]
	orrs r0, r7
	str r0, [r1]
	ldrb r1, [r5]
	adds r1, #0x11
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r2, r2, r0
	ldr r0, [r2]
	orrs r0, r7
	str r0, [r2]
	ldr r1, _080943F8 @ =FUN_080946dc
_080943D6:
	adds r0, r4, #0
	movs r2, #1
	bl EntityCC28_SetState
	b _0809442E
	.align 2, 0
_080943E0: .4byte 0x0000144C
_080943E4: .4byte 0x0000038A
_080943E8: .4byte 0x00003F9C
_080943EC: .4byte 0x00003AEE
_080943F0: .4byte 0x00003AEB
_080943F4: .4byte 0x00000F6C
_080943F8: .4byte FUN_080946dc
_080943FC:
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _0809442E
_08094406:
	ldr r1, _08094434 @ =0x00003AE8
	adds r0, r4, r1
	bl FUN_0808fb68
	cmp r0, #0
	beq _0809442E
	ldr r2, _08094438 @ =0x00001464
	adds r0, r4, r2
	ldr r2, _0809443C @ =0x00003AEB
	adds r1, r4, r2
	ldrb r1, [r1]
	bl FUN_080921e8
	adds r0, r4, #0
	bl FUN_08092070
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08092608
_0809442E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08094434: .4byte 0x00003AE8
_08094438: .4byte 0x00001464
_0809443C: .4byte 0x00003AEB
