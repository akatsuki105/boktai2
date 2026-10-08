	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, _08095DE4 @ =0x00001444
	adds r5, r4, r0
	adds r6, r4, #0
	adds r6, #0x60
	adds r0, r5, #0
	adds r1, r6, #0
	bl MainSprite_AdvanceAnim
	adds r0, r4, #0
	bl FUN_0808c548
	ldr r0, _08095DE8 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08095D7E
	b _08095EC4
_08095D7E:
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08095E00
	ldr r1, _08095DEC @ =0x00003AE8
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08095E00
	ldr r7, _08095DF0 @ =0x00001C2C
	adds r2, r4, r7
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _08095DF4 @ =0x00001464
	adds r0, r4, r1
	movs r1, #0x14
	bl FUN_080921e8
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #0x38
	movs r3, #1
	bl MainSprite_SetPose
	ldr r6, _08095DF8 @ =0x0000204C
	adds r2, r4, r6
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
	ldr r1, _08095DFC @ =FUN_080962b0
	adds r0, r4, #0
	b _08095FAA
	.align 2, 0
_08095DE4: .4byte 0x00001444
_08095DE8: .4byte 0x030044E0
_08095DEC: .4byte 0x00003AE8
_08095DF0: .4byte 0x00001C2C
_08095DF4: .4byte 0x00001464
_08095DF8: .4byte 0x0000204C
_08095DFC: .4byte FUN_080962b0
_08095E00:
	ldr r0, _08095E2C @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08095E0E
	b _08095FDA
_08095E0E:
	adds r0, r4, #0
	bl FUN_0808c700
	adds r0, r4, #0
	bl FUN_0809596c
	cmp r0, #4
	bls _08095E20
	b _08095FD0
_08095E20:
	lsls r0, r0, #2
	ldr r1, _08095E30 @ =_08095E34
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08095E2C: .4byte 0x030044E0
_08095E30: .4byte _08095E34
_08095E34: @ jump table
	.4byte _08095FD0 @ case 0
	.4byte _08095E80 @ case 1
	.4byte _08095E48 @ case 2
	.4byte _08095ED8 @ case 3
	.4byte _08095EB8 @ case 4
_08095E48:
	ldr r7, _08095E74 @ =0x0000144C
	adds r1, r4, r7
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r0, _08095E78 @ =0x0000204C
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, [r4, #0x58]
	movs r1, #2
	bl EntityCC28_ShowBottomLine
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0808b6fc
	ldr r1, _08095E7C @ =FUN_080962b0
	adds r0, r4, #0
	b _08095FAA
	.align 2, 0
_08095E74: .4byte 0x0000144C
_08095E78: .4byte 0x0000204C
_08095E7C: .4byte FUN_080962b0
_08095E80:
	ldr r1, _08095EA8 @ =0x0000144C
	adds r2, r4, r1
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r2, _08095EAC @ =0x00003AEE
	adds r0, r4, r2
	ldrb r2, [r0]
	ldr r6, _08095EB0 @ =0x00003AEB
	adds r0, r4, r6
	ldrb r3, [r0]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080956c4
	ldr r1, _08095EB4 @ =FUN_0809611c
	adds r0, r4, #0
	b _08095FAA
	.align 2, 0
_08095EA8: .4byte 0x0000144C
_08095EAC: .4byte 0x00003AEE
_08095EB0: .4byte 0x00003AEB
_08095EB4: .4byte FUN_0809611c
_08095EB8:
	ldr r7, _08095ED4 @ =0x00003AEB
	adds r0, r4, r7
	ldrb r0, [r0]
	subs r0, #0x10
	bl FUN_08242f84
_08095EC4:
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_08095a5c
	b _08096008
	.align 2, 0
_08095ED4: .4byte 0x00003AEB
_08095ED8:
	ldr r0, _08095FB4 @ =0x0000144C
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r1, _08095FB8 @ =0x00003AEE
	adds r7, r4, r1
	ldrb r0, [r7]
	bl GetWeaponID
	cmp r0, #0
	ble _08095F02
	ldrb r2, [r7]
	ldr r6, _08095FBC @ =0x00003AEB
	adds r0, r4, r6
	ldrb r3, [r0]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080956c4
_08095F02:
	ldr r0, _08095FBC @ =0x00003AEB
	adds r6, r4, r0
	ldrb r0, [r6]
	bl GetWeaponID
	cmp r0, #0
	ble _08095F1C
	ldrb r2, [r6]
	ldrb r3, [r7]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_080956c4
_08095F1C:
	movs r5, #0
	ldr r1, _08095FC0 @ =FUN_0809620c
	mov sb, r1
	ldr r2, _08095FC4 @ =0x030046A0
	mov ip, r2
	ldr r0, [r2]
	mov r8, r7
	ldr r7, _08095FC8 @ =0x00001ECC
	adds r1, r4, r7
	adds r3, r0, #0
	adds r3, #0x60
	movs r0, #1
	mov sl, r0
	str r6, [sp]
_08095F38:
	lsls r2, r5, #1
	movs r6, #0
	ldrsh r0, [r3, r6]
	mov r7, r8
	ldrb r7, [r7]
	cmp r0, r7
	bne _08095F4E
	ldr r0, [r1]
	mov r6, sl
	orrs r0, r6
	str r0, [r1]
_08095F4E:
	mov r7, ip
	ldr r0, [r7]
	adds r0, r2, r0
	adds r0, #0x60
	movs r2, #0
	ldrsh r0, [r0, r2]
	ldr r6, [sp]
	ldrb r6, [r6]
	cmp r0, r6
	bne _08095F6A
	ldr r0, [r1]
	mov r7, sl
	orrs r0, r7
	str r0, [r1]
_08095F6A:
	adds r1, #0x60
	adds r3, #2
	adds r5, #1
	cmp r5, #3
	ble _08095F38
	ldr r1, _08095FB8 @ =0x00003AEE
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r1, #0x11
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	ldr r6, _08095FCC @ =0x00000F6C
	adds r2, r4, r6
	adds r0, r2, r0
	ldr r1, [r0]
	movs r3, #1
	orrs r1, r3
	str r1, [r0]
	ldr r7, _08095FBC @ =0x00003AEB
	adds r0, r4, r7
	ldrb r1, [r0]
	adds r1, #0x11
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r2, r2, r0
	ldr r0, [r2]
	orrs r0, r3
	str r0, [r2]
	adds r0, r4, #0
	mov r1, sb
_08095FAA:
	movs r2, #1
	bl EntityCC28_SetState
	b _08096008
	.align 2, 0
_08095FB4: .4byte 0x0000144C
_08095FB8: .4byte 0x00003AEE
_08095FBC: .4byte 0x00003AEB
_08095FC0: .4byte FUN_0809620c
_08095FC4: .4byte 0x030046A0
_08095FC8: .4byte 0x00001ECC
_08095FCC: .4byte 0x00000F6C
_08095FD0:
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _08096008
_08095FDA:
	ldr r1, _08096018 @ =0x00003AE8
	adds r0, r4, r1
	bl FUN_0808fb68
	cmp r0, #0
	beq _08096008
	ldr r2, _0809601C @ =0x00001464
	adds r0, r4, r2
	ldr r6, _08096020 @ =0x00003AEB
	adds r1, r4, r6
	ldrb r1, [r1]
	bl FUN_080952f4
	adds r0, r4, #0
	bl FUN_08094eb0
	adds r0, r4, #0
	bl weapon_08094f88
	adds r0, r4, #0
	movs r1, #1
	bl weapon_08095820
_08096008:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08096018: .4byte 0x00003AE8
_0809601C: .4byte 0x00001464
_08096020: .4byte 0x00003AEB
