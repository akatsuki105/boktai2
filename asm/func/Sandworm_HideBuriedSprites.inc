	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r3, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r3, r1
	ldr r7, [r0]
	ldr r2, _08179D88 @ =0x00000553
	adds r0, r3, r2
	ldrb r0, [r0]
	cmp r0, #0x11
	bne _08179D6A
	b _08179ED6
_08179D6A:
	movs r0, #0xa
	ldrsh r1, [r3, r0]
	subs r2, #0xe1
	adds r0, r3, r2
	ldrh r0, [r0]
	cmp r1, r0
	blt _08179D7C
	cmp r0, #0
	bne _08179D8C
_08179D7C:
	ldr r0, [r3, #0x44]
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	b _08179DA2
	.align 2, 0
_08179D88: .4byte 0x00000553
_08179D8C:
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r3, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _08179DA4
	ldr r0, [r3, #0x44]
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
_08179DA2:
	str r1, [r0]
_08179DA4:
	movs r2, #0
	str r2, [sp]
	ldr r1, _08179DD8 @ =0x00001012
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	ldr r1, [sp]
	cmp r1, r0
	blt _08179DB8
	b _08179ED6
_08179DB8:
	mov sb, r7
	movs r2, #0
	mov sl, r2
	ldr r0, _08179DDC @ =0x00000674
	adds r6, r7, r0
	ldr r1, _08179DE0 @ =0x00000755
	adds r1, r1, r7
	mov r8, r1
_08179DC8:
	movs r1, #1
	mov r2, r8
	ldrb r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08179DE4
	movs r0, #1
	b _08179DE6
	.align 2, 0
_08179DD8: .4byte 0x00001012
_08179DDC: .4byte 0x00000674
_08179DE0: .4byte 0x00000755
_08179DE4:
	movs r0, #0
_08179DE6:
	cmp r0, #0
	bne _08179EB4
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08179E0E
	cmp r1, #0
	blt _08179E0E
	ldr r0, _08179E14 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08179E0E
	ldr r0, _08179E18 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08179E1C
_08179E0E:
	movs r4, #0
	b _08179E2A
	.align 2, 0
_08179E14: .4byte 0x030046A8
_08179E18: .4byte 0x030046AC
_08179E1C:
	ldr r0, _08179E40 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08179E2A:
	adds r5, r6, #0
	adds r0, r4, #0
	movs r1, #1
	str r3, [sp, #4]
	bl Map_FindTileOverride
	ldr r3, [sp, #4]
	cmp r0, #0
	beq _08179E44
	adds r0, #4
	b _08179E50
	.align 2, 0
_08179E40: .4byte 0x030046A4
_08179E44:
	ldr r0, _08179E64 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08179E50:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08179E68
	cmp r2, #2
	beq _08179E6C
	b _08179E70
	.align 2, 0
_08179E64: .4byte 0x030046A4
_08179E68:
	ldrb r0, [r5, #4]
	b _08179E6E
_08179E6C:
	ldrb r0, [r5]
_08179E6E:
	subs r1, r1, r0
_08179E70:
	movs r2, #2
	ldrsh r0, [r6, r2]
	cmp r0, r1
	blt _08179E82
	ldr r1, _08179E94 @ =0x00000472
	adds r0, r3, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _08179E98
_08179E82:
	movs r2, #0xcb
	lsls r2, r2, #3
	adds r0, r7, r2
	add r0, sl
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	b _08179EB2
	.align 2, 0
_08179E94: .4byte 0x00000472
_08179E98:
	ldr r0, _08179EE8 @ =0x00000734
	add r0, sb
	ldrh r0, [r0]
	cmp r0, #0
	bne _08179EB4
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r0, r7, r1
	add r0, sl
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
_08179EB2:
	str r1, [r0]
_08179EB4:
	movs r2, #0x92
	lsls r2, r2, #1
	add sb, r2
	add sl, r2
	adds r6, r6, r2
	add r8, r2
	ldr r0, [sp]
	adds r0, #1
	str r0, [sp]
	ldr r1, _08179EEC @ =0x00001012
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	ldr r1, [sp]
	cmp r1, r0
	bge _08179ED6
	b _08179DC8
_08179ED6:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08179EE8: .4byte 0x00000734
_08179EEC: .4byte 0x00001012
