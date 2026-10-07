	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x48
	mov sl, r0
	str r1, [sp, #0x40]
	str r2, [sp, #0x44]
	movs r0, #0
	mov sb, r0
	movs r6, #0
	movs r1, #0xff
	mov r8, r1
	mov r5, sp
_08081DFE:
	ldr r0, _08081E28 @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r5]
	str r1, [r5, #4]
	lsls r2, r6, #5
	ldr r1, _08081E2C @ =0x085B0A08
	adds r0, r2, #0
	adds r0, #0x40
	mov r3, r8
	ands r0, r3
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #9
	cmp r0, #0
	blt _08081E30
	asrs r1, r0, #0xc
	b _08081E36
	.align 2, 0
_08081E28: .4byte 0x03002BE0
_08081E2C: .4byte 0x085B0A08
_08081E30:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08081E36:
	ldrh r0, [r5]
	adds r0, r0, r1
	strh r0, [r5]
	mov r3, r8
	ands r2, r3
	lsls r0, r2, #1
	ldr r1, _08081E54 @ =0x085B0A08
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #9
	cmp r0, #0
	blt _08081E58
	asrs r0, r0, #0xc
	b _08081E5E
	.align 2, 0
_08081E54: .4byte 0x085B0A08
_08081E58:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08081E5E:
	ldrh r1, [r5, #4]
	adds r1, r1, r0
	strh r1, [r5, #4]
	adds r7, r5, #0
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _08081E88
	cmp r1, #0
	blt _08081E88
	ldr r0, _08081E8C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08081E88
	ldr r0, _08081E90 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08081E94
_08081E88:
	movs r4, #0
	b _08081EA2
	.align 2, 0
_08081E8C: .4byte 0x030046A8
_08081E90: .4byte 0x030046AC
_08081E94:
	ldr r0, _08081EB4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08081EA2:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08081EB8
	adds r0, #4
	b _08081EC4
	.align 2, 0
_08081EB4: .4byte 0x030046A4
_08081EB8:
	ldr r0, _08081ED8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08081EC4:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _08081EDC
	cmp r3, #2
	beq _08081EE0
	b _08081EE8
	.align 2, 0
_08081ED8: .4byte 0x030046A4
_08081EDC:
	ldrh r1, [r7, #4]
	b _08081EE2
_08081EE0:
	ldrh r1, [r7]
_08081EE2:
	mov r0, r8
	ands r0, r1
	subs r2, r2, r0
_08081EE8:
	mov r3, sl
	movs r1, #0x2e
	ldrsh r0, [r3, r1]
	cmp r2, r0
	bne _08081EFA
	movs r0, #1
	strh r0, [r5, #6]
	add sb, r0
	b _08081EFE
_08081EFA:
	movs r0, #0
	strh r0, [r5, #6]
_08081EFE:
	adds r5, #8
	adds r6, #1
	cmp r6, #7
	bgt _08081F08
	b _08081DFE
_08081F08:
	mov r2, sb
	cmp r2, #0
	bne _08081F28
	b _08081F60
_08081F10:
	ldr r0, [r1]
	ldr r1, [r1, #4]
	ldr r3, [sp, #0x40]
	str r0, [r3]
	str r1, [r3, #4]
	adds r0, r6, #7
	movs r1, #7
	ands r0, r1
	ldr r1, [sp, #0x44]
	str r0, [r1]
	movs r0, #1
	b _08081F62
_08081F28:
	ldr r2, _08081F74 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08081F78 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _08081F7C @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	asrs r0, r0, #3
	mov r1, sb
	bl Mod
	adds r2, r0, #0
	movs r6, #0
	mov r1, sp
_08081F4A:
	movs r3, #6
	ldrsh r0, [r1, r3]
	cmp r0, #0
	beq _08081F58
	cmp r2, #0
	beq _08081F10
	subs r2, #1
_08081F58:
	adds r1, #8
	adds r6, #1
	cmp r6, #7
	ble _08081F4A
_08081F60:
	movs r0, #0
_08081F62:
	add sp, #0x48
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08081F74: .4byte 0x030046B8
_08081F78: .4byte 0x000003FF
_08081F7C: .4byte 0x0203B400
