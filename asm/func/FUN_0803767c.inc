	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	str r0, [sp, #0x14]
	movs r0, #0
	str r0, [sp, #0x18]
	ldr r7, _080376E4 @ =0x0203B400
	ldr r2, _080376E8 @ =0x030046B8
	mov sl, r2
	ldr r6, _080376EC @ =0x000003FF
	movs r3, #0xff
	mov sb, r3
	add r5, sp, #0xc
	adds r1, #0x44
	mov r8, r1
_080376A0:
	mov r4, sl
	ldr r0, [r4]
	adds r0, #1
	ands r0, r6
	lsls r1, r0, #1
	adds r1, r1, r7
	ldrh r2, [r1]
	adds r0, #1
	ands r0, r6
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r7
	ldrh r1, [r0]
	movs r0, #0x1f
	ands r1, r0
	mov r0, sb
	ands r2, r0
	adds r3, r1, #0
	adds r3, #0x20
	ldr r1, _080376F0 @ =gSineTable
	adds r0, r2, #0
	adds r0, #0x40
	mov r4, sb
	ands r0, r4
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _080376F4
	asrs r1, r0, #0xc
	b _080376FA
	.align 2, 0
_080376E4: .4byte 0x0203B400
_080376E8: .4byte 0x030046B8
_080376EC: .4byte 0x000003FF
_080376F0: .4byte gSineTable
_080376F4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080376FA:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	mov r4, sb
	ands r2, r4
	lsls r0, r2, #1
	ldr r1, _08037718 @ =gSineTable
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r3, r0
	cmp r0, #0
	blt _0803771C
	asrs r2, r0, #0xc
	b _08037722
	.align 2, 0
_08037718: .4byte gSineTable
_0803771C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08037722:
	mov r3, r8
	ldrh r0, [r3]
	ldrh r4, [r5]
	adds r0, r0, r4
	strh r0, [r5]
	ldrh r1, [r5, #2]
	ldrh r0, [r3, #2]
	adds r1, r1, r0
	ldrh r0, [r3, #4]
	adds r0, r2, r0
	strh r0, [r5, #4]
	adds r1, #0x80
	strh r1, [r5, #2]
	mov r0, sl
	ldr r3, [r0]
	adds r3, #1
	ands r3, r6
	lsls r0, r3, #1
	adds r0, r0, r7
	ldrh r1, [r0]
	mov r2, sb
	ands r1, r2
	adds r3, #1
	ands r3, r6
	lsls r0, r3, #1
	adds r0, r0, r7
	ldrh r2, [r0]
	movs r4, #3
	ands r2, r4
	adds r2, #8
	mov ip, r2
	adds r3, #1
	ands r3, r6
	mov r0, sl
	str r3, [r0]
	lsls r3, r3, #1
	adds r3, r3, r7
	ldrh r3, [r3]
	ands r3, r4
	ldr r2, [sp, #0x14]
	ldr r4, _080377B4 @ =0x00000DE8
	adds r0, r2, r4
	ldr r0, [r0]
	ldr r2, [sp, #0x18]
	lsls r2, r2, #3
	str r2, [sp, #0x1c]
	adds r4, r2, #0
	adds r4, #0x1e
	str r4, [sp]
	movs r2, #0xb1
	lsls r2, r2, #1
	ldr r4, [sp, #0x14]
	adds r2, r4, r2
	ldrb r4, [r2]
	str r4, [sp, #4]
	str r5, [sp, #8]
	mov r2, ip
	bl FUN_08060220
	ldr r3, [sp, #0x18]
	adds r3, #1
	str r3, [sp, #0x18]
	cmp r3, #3
	bgt _080377A4
	b _080376A0
_080377A4:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080377B4: .4byte 0x00000DE8
