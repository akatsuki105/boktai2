	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov r8, r0
	adds r7, r1, #0
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	ldrh r0, [r7]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08232B36
	cmp r1, #0
	blt _08232B36
	ldr r0, _08232B3C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08232B36
	ldr r0, _08232B40 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08232B44
_08232B36:
	movs r0, #0
	b _08232B52
	.align 2, 0
_08232B3C: .4byte 0x030046A8
_08232B40: .4byte 0x030046AC
_08232B44:
	ldr r0, _08232B68 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_08232B52:
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08232B6C
	adds r0, #4
	mov sb, r0
	b _08232B7A
	.align 2, 0
_08232B68: .4byte 0x030046A4
_08232B6C:
	ldr r0, _08232B8C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r1, r1, r0
	mov sb, r1
_08232B7A:
	mov r0, sb
	ldrh r5, [r0, #2]
	cmp r4, #4
	bne _08232B90
	movs r1, #2
	mov sl, r1
	movs r4, #0x80
	b _08232B96
	.align 2, 0
_08232B8C: .4byte 0x030046A4
_08232B90:
	movs r2, #1
	mov sl, r2
	movs r4, #0x64
_08232B96:
	adds r0, r5, #0
	mov r1, sl
	ands r0, r1
	cmp r0, #0
	beq _08232BA2
	b _08232DDE
_08232BA2:
	mov r0, r8
	adds r1, r7, #0
	bl FUN_082329e0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r4
	ble _08232BB4
	b _08232DDE
_08232BB4:
	mov r2, r8
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	mov r4, r8
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08232BDC
	cmp r1, #0
	blt _08232BDC
	ldr r0, _08232BE0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08232BDC
	ldr r0, _08232BE4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08232BE8
_08232BDC:
	movs r0, #0
	b _08232BF6
	.align 2, 0
_08232BE0: .4byte 0x030046A8
_08232BE4: .4byte 0x030046AC
_08232BE8:
	ldr r0, _08232C0C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_08232BF6:
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08232C10
	adds r0, #4
	mov r8, r0
	b _08232C1E
	.align 2, 0
_08232C0C: .4byte 0x030046A4
_08232C10:
	ldr r0, _08232C7C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r1, r1, r0
	mov r8, r1
_08232C1E:
	mov r1, r8
	ldrb r0, [r1]
	lsrs r1, r0, #4
	mov r2, sb
	ldrb r0, [r2]
	lsrs r3, r0, #4
	subs r2, r6, r4
	cmp r1, #1
	bne _08232CCC
	cmp r2, #1
	beq _08232C3E
	movs r0, #1
	rsbs r0, r0, #0
	cmp r2, r0
	beq _08232C3E
	b _08232DE8
_08232C3E:
	ldr r0, _08232C80 @ =0x030046A0
	ldr r0, [r0]
	ldr r4, _08232C84 @ =0x00000934
	adds r0, r0, r4
	ldrh r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08232C5A
	movs r0, #0x80
	ands r5, r0
	cmp r5, #0
	beq _08232C5A
	b _08232DDE
_08232C5A:
	cmp r3, #0
	beq _08232C60
	b _08232DE8
_08232C60:
	ldrb r0, [r7, #4]
	cmp r0, #0x7f
	bgt _08232C8C
	ldr r0, _08232C88 @ =0x030046A8
	ldr r0, [r0]
	subs r4, r6, r0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	bne _08232C9E
	b _08232CA8
	.align 2, 0
_08232C7C: .4byte 0x030046A4
_08232C80: .4byte 0x030046A0
_08232C84: .4byte 0x00000934
_08232C88: .4byte 0x030046A8
_08232C8C:
	ldr r0, _08232CA4 @ =0x030046A8
	ldr r0, [r0]
	adds r4, r6, r0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08232CA8
_08232C9E:
	adds r3, r0, #4
	b _08232CB4
	.align 2, 0
_08232CA4: .4byte 0x030046A8
_08232CA8:
	ldr r0, _08232CC8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r3, r1, r0
_08232CB4:
	ldrb r2, [r3]
	lsrs r0, r2, #4
	cmp r0, #0
	beq _08232CBE
	b _08232DDE
_08232CBE:
	movs r0, #0xf
	adds r1, r0, #0
	ands r1, r2
	mov r4, sb
	b _08232DCC
	.align 2, 0
_08232CC8: .4byte 0x030046A4
_08232CCC:
	cmp r1, #2
	bne _08232D54
	ldr r0, _08232D14 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	beq _08232CDE
	cmn r2, r0
	beq _08232CDE
	b _08232DE8
_08232CDE:
	ldr r0, _08232D18 @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _08232D1C @ =0x00000934
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08232CF8
	movs r0, #0x80
	ands r5, r0
	cmp r5, #0
	bne _08232DDE
_08232CF8:
	cmp r3, #0
	bne _08232DE8
	ldrb r0, [r7]
	cmp r0, #0x7f
	bgt _08232D20
	subs r4, r6, #1
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	bne _08232D2E
	b _08232D32
	.align 2, 0
_08232D14: .4byte 0x030046A8
_08232D18: .4byte 0x030046A0
_08232D1C: .4byte 0x00000934
_08232D20:
	adds r4, r6, #1
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08232D32
_08232D2E:
	adds r3, r0, #4
	b _08232D3E
_08232D32:
	ldr r0, _08232D50 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r3, r1, r0
_08232D3E:
	ldrb r2, [r3]
	lsrs r0, r2, #4
	cmp r0, #0
	bne _08232DDE
	movs r0, #0xf
	adds r1, r0, #0
	ands r1, r2
	mov r4, sb
	b _08232DCC
	.align 2, 0
_08232D50: .4byte 0x030046A4
_08232D54:
	ldr r0, _08232D70 @ =0x030046A8
	ldr r1, [r0]
	cmp r2, r1
	beq _08232D60
	cmn r2, r1
	bne _08232D78
_08232D60:
	cmp r3, #2
	bne _08232DE8
	ldrb r0, [r7]
	cmp r0, #0x7f
	bgt _08232D74
	subs r4, #1
	b _08232D90
	.align 2, 0
_08232D70: .4byte 0x030046A8
_08232D74:
	adds r4, #1
	b _08232D90
_08232D78:
	cmp r2, #1
	beq _08232D84
	movs r0, #1
	rsbs r0, r0, #0
	cmp r2, r0
	bne _08232DE8
_08232D84:
	cmp r3, #1
	bne _08232DE8
	ldrb r0, [r7, #4]
	cmp r0, #0x7f
	bgt _08232D9E
	subs r4, r4, r1
_08232D90:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	bne _08232DAC
	b _08232DB0
_08232D9E:
	adds r4, r4, r1
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08232DB0
_08232DAC:
	adds r3, r0, #4
	b _08232DBC
_08232DB0:
	ldr r0, _08232DE4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r3, r1, r0
_08232DBC:
	ldrb r2, [r3]
	lsrs r0, r2, #4
	cmp r0, #0
	bne _08232DDE
	movs r0, #0xf
	adds r1, r0, #0
	ands r1, r2
	mov r4, r8
_08232DCC:
	ldrb r2, [r4]
	ands r0, r2
	cmp r1, r0
	bne _08232DDE
	ldrh r0, [r3, #2]
	mov r1, sl
	ands r0, r1
	cmp r0, #0
	beq _08232DE8
_08232DDE:
	movs r0, #0
	b _08232DEA
	.align 2, 0
_08232DE4: .4byte 0x030046A4
_08232DE8:
	movs r0, #1
_08232DEA:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
