	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	adds r5, r0, #0
	ldr r0, _080D2F00 @ =0x000009C8
	adds r6, r5, r0
	ldr r1, _080D2F04 @ =0x00000A8A
	adds r3, r5, r1
	ldrh r0, [r3]
	adds r0, #1
	strh r0, [r3]
	ldr r2, _080D2F08 @ =0x00000A88
	adds r1, r5, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r4, [r1]
	cmp r0, r4
	bhi _080D2F0C
_080D2EFA:
	movs r0, #0
	b _080D317A
	.align 2, 0
_080D2F00: .4byte 0x000009C8
_080D2F04: .4byte 0x00000A8A
_080D2F08: .4byte 0x00000A88
_080D2F0C:
	ldrh r2, [r3]
	ldrh r0, [r1]
	ldr r7, _080D2F38 @ =0x00000A84
	adds r1, r5, r7
	ldrh r1, [r1]
	adds r1, r0, r1
	cmp r2, r1
	ble _080D2F1E
	b _080D313C
_080D2F1E:
	cmp r2, r1
	bne _080D2F44
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080D2F3C
	ldr r0, [r5, #0x18]
	adds r1, #0x38
	bl Sound_PlayForPlayer
	b _080D2F44
	.align 2, 0
_080D2F38: .4byte 0x00000A84
_080D2F3C:
	ldr r0, [r5, #0x18]
	ldr r1, _080D2F8C @ =0x0000038E
	bl Sound_PlayForPlayer
_080D2F44:
	adds r4, r6, #0
	adds r4, #0xc2
	ldrh r1, [r4]
	adds r3, r6, #0
	adds r3, #0xc0
	ldrh r0, [r3]
	subs r1, r1, r0
	adds r0, r6, #0
	adds r0, #0xb8
	ldrh r0, [r0]
	muls r1, r0, r1
	movs r0, #0xa8
	lsls r0, r0, #1
	subs r7, r0, r1
	movs r1, #0xff
	ands r7, r1
	ldr r2, _080D2F90 @ =gSineTable
	adds r0, r7, #0
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r8, r0
	movs r0, #0xfa
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	mov sb, r4
	mov r8, r3
	mov ip, r2
	cmp r0, #0
	blt _080D2F94
	asrs r1, r0, #0xc
	b _080D2F9A
	.align 2, 0
_080D2F8C: .4byte 0x0000038E
_080D2F90: .4byte gSineTable
_080D2F94:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080D2F9A:
	adds r2, r6, #0
	adds r2, #0xa2
	ldrh r0, [r2]
	adds r0, r0, r1
	adds r3, r6, #0
	adds r3, #0x9a
	strh r0, [r3]
	adds r0, r7, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	add r0, ip
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0xfa
	muls r0, r1, r0
	str r2, [sp, #0xc]
	cmp r0, #0
	blt _080D2FC6
	asrs r0, r0, #0xc
	b _080D2FCC
_080D2FC6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D2FCC:
	mov sl, r0
	adds r2, r6, #0
	adds r2, #0xc4
	ldrb r0, [r2]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	add r0, ip
	movs r4, #0
	ldrsh r0, [r0, r4]
	mov r1, sl
	muls r1, r0, r1
	adds r0, r1, #0
	adds r4, r2, #0
	cmp r0, #0
	blt _080D2FF2
	asrs r1, r0, #0xc
	b _080D2FF8
_080D2FF2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080D2FF8:
	adds r2, r6, #0
	adds r2, #0xa0
	ldrh r0, [r2]
	adds r0, r0, r1
	adds r1, r6, #0
	adds r1, #0x98
	strh r0, [r1]
	ldrb r0, [r4]
	lsls r0, r0, #1
	add r0, ip
	movs r3, #0
	ldrsh r0, [r0, r3]
	mov r3, sl
	muls r3, r0, r3
	adds r0, r3, #0
	mov sl, r2
	mov ip, r1
	cmp r0, #0
	blt _080D3022
	asrs r1, r0, #0xc
	b _080D3028
_080D3022:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080D3028:
	adds r2, r6, #0
	adds r2, #0xa4
	ldrh r0, [r2]
	adds r0, r0, r1
	adds r1, r6, #0
	adds r1, #0x9c
	strh r0, [r1]
	mov r0, sb
	ldrh r1, [r0]
	mov r3, r8
	ldrh r0, [r3]
	adds r0, #2
	str r2, [sp, #0x10]
	cmp r1, r0
	ble _080D3060
	adds r1, r6, #0
	adds r1, #0xc5
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	blt _080D3060
	ldrb r3, [r4]
	str r0, [sp]
	adds r0, r5, #0
	mov r1, ip
	adds r2, r7, #0
	bl FUN_080d2d48
_080D3060:
	mov r7, sb
	ldrh r3, [r7]
	mov r1, r8
	ldrh r0, [r1]
	adds r2, r6, #0
	adds r2, #0xbc
	ldrh r1, [r2]
	adds r0, r0, r1
	subs r0, #2
	adds r7, r2, #0
	cmp r3, r0
	bgt _080D307A
	b _080D2EFA
_080D307A:
	movs r3, #0xaa
	ldr r2, _080D309C @ =gSineTable
	ldrb r0, [r4]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	mov ip, r2
	cmp r0, #0
	blt _080D30A0
	asrs r0, r0, #0xc
	b _080D30A6
	.align 2, 0
_080D309C: .4byte gSineTable
_080D30A0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D30A6:
	mov r1, sl
	ldrh r2, [r1]
	adds r2, r2, r0
	lsls r2, r2, #0x10
	mov r1, r8
	ldrh r0, [r1]
	ldrh r1, [r7]
	adds r0, r0, r1
	mov r7, sb
	ldrh r1, [r7]
	subs r0, r0, r1
	adds r0, #1
	movs r1, #0x5a
	muls r0, r1, r0
	ldr r1, [sp, #0xc]
	ldrh r1, [r1]
	adds r0, r0, r1
	ldr r7, _080D30E8 @ =0xFFFFFEFC
	adds r0, r0, r7
	lsls r0, r0, #0x10
	lsrs r2, r2, #0x10
	orrs r2, r0
	str r2, [sp, #4]
	ldrb r0, [r4]
	lsls r0, r0, #1
	add r0, ip
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _080D30EC
	asrs r0, r0, #0xc
	b _080D30F2
	.align 2, 0
_080D30E8: .4byte 0xFFFFFEFC
_080D30EC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D30F2:
	ldr r2, [sp, #0x10]
	ldrh r1, [r2]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080D3138 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #8]
	adds r0, r6, #0
	adds r0, #0xc5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _080D311E
	movs r1, #0x80
	lsls r1, r1, #0xc
	ldr r0, [r5, #0x20]
	orrs r0, r1
	str r0, [r5, #0x20]
_080D311E:
	movs r3, #0xa1
	lsls r3, r3, #4
	adds r0, r5, r3
	add r1, sp, #4
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r6, #0
	adds r0, #0x48
	bl Hitbox_Register
	b _080D2EFA
	.align 2, 0
_080D3138: .4byte 0xFFFF0000
_080D313C:
	ldr r4, _080D316C @ =0x00000A86
	adds r0, r5, r4
	ldrh r0, [r0]
	adds r0, r1, r0
	cmp r2, r0
	bgt _080D3174
	ldr r7, _080D3170 @ =0x00000A8D
	adds r0, r5, r7
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _080D3160
	movs r1, #0x80
	lsls r1, r1, #0xc
	ldr r0, [r5, #0x20]
	orrs r0, r1
	str r0, [r5, #0x20]
_080D3160:
	movs r1, #0xa1
	lsls r1, r1, #4
	adds r0, r5, r1
	bl Hitbox_Register
	b _080D2EFA
	.align 2, 0
_080D316C: .4byte 0x00000A86
_080D3170: .4byte 0x00000A8D
_080D3174:
	movs r0, #0
	strh r0, [r3]
	movs r0, #1
_080D317A:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
