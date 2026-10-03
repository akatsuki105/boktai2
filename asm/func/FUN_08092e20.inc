	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov r8, r0
	ldr r0, _08092E88 @ =0x00003B28
	add r0, r8
	mov sb, r0
	ldr r7, _08092E8C @ =0x00003B30
	add r7, r8
	ldr r1, _08092E90 @ =0x00003B42
	add r1, r8
	str r1, [sp]
	movs r2, #0xed
	lsls r2, r2, #6
	add r2, r8
	mov sl, r2
	ldrh r0, [r7]
	mov r1, sb
	ldrh r1, [r1]
	adds r0, r0, r1
	mov r2, sb
	strh r0, [r2]
	ldrh r0, [r7, #2]
	ldrh r1, [r2, #2]
	adds r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r7, #2]
	adds r0, #1
	strh r0, [r7, #2]
	ldr r1, _08092E94 @ =0x000009EE
	add r1, r8
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r2, _08092E98 @ =0x0000FFFF
	adds r1, r2, #0
	ands r0, r1
	movs r1, #0xf
	ands r0, r1
	cmp r0, #0
	bne _08092EA4
	ldrh r0, [r7]
	movs r2, #0
	ldrsh r1, [r7, r2]
	cmp r1, #0
	ble _08092E9C
	subs r0, #1
	b _08092EA2
	.align 2, 0
_08092E88: .4byte 0x00003B28
_08092E8C: .4byte 0x00003B30
_08092E90: .4byte 0x00003B42
_08092E94: .4byte 0x000009EE
_08092E98: .4byte 0x0000FFFF
_08092E9C:
	cmp r1, #0
	bge _08092EA4
	adds r0, #1
_08092EA2:
	strh r0, [r7]
_08092EA4:
	mov r1, sb
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #7
	bgt _08092F10
	movs r0, #8
	strh r0, [r1]
	movs r0, #0
	ldrsh r1, [r7, r0]
	rsbs r0, r1, #0
	cmp r0, #0
	blt _08092EC0
	asrs r0, r0, #1
	b _08092EC4
_08092EC0:
	asrs r0, r1, #1
	rsbs r0, r0, #0
_08092EC4:
	strh r0, [r7]
	ldr r6, _08092F04 @ =0x0203B400
	ldr r4, _08092F08 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r5, _08092F0C @ =0x000003FF
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r1, #0xa
	bl Mod
	adds r2, r0, #5
	mov r1, sl
	strh r2, [r1]
	ldr r0, [r4]
	adds r0, #1
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08092F6A
	rsbs r0, r2, #0
	mov r2, sl
	strh r0, [r2]
	b _08092F6A
	.align 2, 0
_08092F04: .4byte 0x0203B400
_08092F08: .4byte 0x030046B8
_08092F0C: .4byte 0x000003FF
_08092F10:
	cmp r0, #0xe8
	ble _08092F6A
	movs r0, #0xe8
	mov r1, sb
	strh r0, [r1]
	movs r2, #0
	ldrsh r1, [r7, r2]
	rsbs r0, r1, #0
	cmp r0, #0
	blt _08092F28
	asrs r0, r0, #1
	b _08092F2C
_08092F28:
	asrs r0, r1, #1
	rsbs r0, r0, #0
_08092F2C:
	strh r0, [r7]
	ldr r6, _08092F88 @ =0x0203B400
	ldr r4, _08092F8C @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r5, _08092F90 @ =0x000003FF
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r1, #0xa
	bl Mod
	adds r2, r0, #5
	mov r0, sl
	strh r2, [r0]
	ldr r0, [r4]
	adds r0, #1
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08092F6A
	rsbs r0, r2, #0
	mov r1, sl
	strh r0, [r1]
_08092F6A:
	mov r2, sb
	movs r1, #2
	ldrsh r0, [r2, r1]
	cmp r0, #0x77
	ble _08093002
	movs r0, #0x78
	strh r0, [r2, #2]
	movs r2, #2
	ldrsh r1, [r7, r2]
	rsbs r0, r1, #0
	cmp r0, #0
	blt _08092F94
	asrs r1, r0, #1
	b _08092F98
	.align 2, 0
_08092F88: .4byte 0x0203B400
_08092F8C: .4byte 0x030046B8
_08092F90: .4byte 0x000003FF
_08092F94:
	asrs r0, r1, #1
	rsbs r1, r0, #0
_08092F98:
	movs r2, #0
	strh r1, [r7, #2]
	movs r0, #2
	rsbs r0, r0, #0
	cmp r1, r0
	ble _08092FC6
	strh r2, [r7]
	strh r2, [r7, #2]
	mov r0, sl
	strh r2, [r0]
	ldr r1, [sp]
	ldrh r0, [r1]
	subs r0, #0x40
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x7f
	bhi _08092FC0
	movs r0, #0x80
	strh r0, [r1]
	b _08093008
_08092FC0:
	ldr r0, [sp]
	strh r2, [r0]
	b _08093008
_08092FC6:
	ldr r6, _08093044 @ =0x0203B400
	ldr r4, _08093048 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r5, _0809304C @ =0x000003FF
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r1, #0xa
	bl Mod
	adds r2, r0, #5
	mov r1, sl
	strh r2, [r1]
	ldr r0, [r4]
	adds r0, #1
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08093002
	rsbs r0, r2, #0
	mov r2, sl
	strh r0, [r2]
_08093002:
	movs r0, #0
	cmp r0, #0
	beq _08093078
_08093008:
	ldr r2, _08093050 @ =0x000020AC
	add r2, r8
	ldr r0, [r2]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	mov r1, sb
	ldrh r0, [r1]
	subs r0, #8
	ldr r1, _08093054 @ =0x000020C4
	add r1, r8
	strh r0, [r1]
	mov r2, sb
	ldrh r0, [r2, #2]
	subs r0, #8
	ldr r1, _08093058 @ =0x000020C6
	add r1, r8
	strh r0, [r1]
	ldr r1, [sp]
	ldrh r0, [r1]
	ldr r1, _0809305C @ =0x000020DA
	add r1, r8
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08093060
	movs r0, #0
	b _0809310C
	.align 2, 0
_08093044: .4byte 0x0203B400
_08093048: .4byte 0x030046B8
_0809304C: .4byte 0x000003FF
_08093050: .4byte 0x000020AC
_08093054: .4byte 0x000020C4
_08093058: .4byte 0x000020C6
_0809305C: .4byte 0x000020DA
_08093060:
	ldr r0, _08093074 @ =0x000020A4
	add r0, r8
	mov r1, r8
	adds r1, #0xa0
	movs r2, #0xce
	movs r3, #1
	bl MainSprite_SetPose
	movs r0, #1
	b _0809310C
	.align 2, 0
_08093074: .4byte 0x000020A4
_08093078:
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r2, #0
	ldr r0, [sp]
	ldrh r0, [r0]
	adds r1, r1, r0
	mov r2, sl
	ldrh r0, [r2]
	adds r0, r0, r1
	movs r1, #0xff
	ands r0, r1
	ldr r1, [sp]
	strh r0, [r1]
	ldr r2, _080930B0 @ =0x085B0A08
	ldrh r0, [r1]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r1, r0, #3
	rsbs r0, r1, #0
	cmp r0, #0
	blt _080930B4
	asrs r0, r0, #0xc
	b _080930B8
	.align 2, 0
_080930B0: .4byte 0x085B0A08
_080930B4:
	asrs r0, r1, #0xc
	rsbs r0, r0, #0
_080930B8:
	adds r4, r0, #0
	ldr r1, [sp]
	ldrb r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r2, r0, #3
	rsbs r0, r2, #0
	cmp r0, #0
	blt _080930D2
	asrs r3, r0, #0xc
	b _080930D6
_080930D2:
	asrs r0, r2, #0xc
	rsbs r3, r0, #0
_080930D6:
	ldr r2, _0809311C @ =0x000020AC
	add r2, r8
	ldr r0, [r2]
	movs r1, #2
	orrs r0, r1
	str r0, [r2]
	mov r1, sb
	ldrh r0, [r1]
	adds r0, r0, r3
	adds r0, r0, r4
	ldr r1, _08093120 @ =0x000020C4
	add r1, r8
	strh r0, [r1]
	mov r2, sb
	ldrh r0, [r2, #2]
	adds r0, r0, r4
	subs r0, r0, r3
	ldr r1, _08093124 @ =0x000020C6
	add r1, r8
	strh r0, [r1]
	ldr r0, [sp]
	ldrh r1, [r0]
	ldr r0, _08093128 @ =0x000020DA
	add r0, r8
	strh r1, [r0]
	movs r0, #1
	rsbs r0, r0, #0
_0809310C:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0809311C: .4byte 0x000020AC
_08093120: .4byte 0x000020C4
_08093124: .4byte 0x000020C6
_08093128: .4byte 0x000020DA
