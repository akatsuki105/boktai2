	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r1, _081E6F54 @ =0x00001614
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081E6F3E
	b _081E7090
_081E6F3E:
	movs r2, #0x80
	lsls r2, r2, #1
	ldr r3, _081E6F58 @ =0x00001610
	adds r1, r5, r3
	ldr r0, [r1]
	ands r0, r2
	adds r7, r1, #0
	cmp r0, #0
	beq _081E6F5C
	movs r0, #1
	b _081E6F5E
	.align 2, 0
_081E6F54: .4byte 0x00001614
_081E6F58: .4byte 0x00001610
_081E6F5C:
	movs r0, #0
_081E6F5E:
	adds r4, r0, #0
	cmp r4, #0
	bne _081E7056
	adds r0, r5, #0
	bl FUN_081e2b08
	movs r0, #0x14
	str r0, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0x1e
	bl Video_FillBGRect
	ldr r1, [r5, #0x1c]
	movs r0, #3
	movs r2, #3
	bl Video_SetBGLayer
	str r4, [sp]
	movs r0, #3
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	movs r0, #0x81
	lsls r0, r0, #4
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	adds r0, r5, #0
	bl FUN_081e3fac
	adds r0, r5, #0
	bl FUN_081e4354
	ldr r1, _081E70CC @ =0x0000161A
	adds r0, r5, r1
	strb r4, [r0]
	ldr r2, _081E70D0 @ =0x00001608
	adds r4, r5, r2
	ldr r0, [r4]
	ldr r3, _081E70D4 @ =0x00001590
	adds r1, r5, r3
	ldr r1, [r1]
	bl TextPanel_SetScript
	ldr r0, [r4]
	bl TextPanel_Start
	adds r0, r5, #0
	bl FUN_081e4544
	ldr r0, _081E70D8 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x91
	lsls r1, r1, #4
	adds r2, r0, r1
	movs r3, #0
	ldrsh r0, [r2, r3]
	ldr r1, _081E70DC @ =0x0000270F
	cmp r0, r1
	ble _081E6FEC
	adds r0, r1, #0
_081E6FEC:
	movs r1, #0xfa
	lsls r1, r1, #2
	movs r6, #0
	str r6, [sp]
	movs r2, #0x16
	movs r3, #1
	bl FUN_081e4604
	ldr r0, _081E70D8 @ =0x030046A0
	ldr r0, [r0]
	adds r1, r0, #0
	adds r1, #0x40
	movs r2, #0
	ldrsh r0, [r1, r2]
	movs r2, #0x63
	cmp r0, #0x63
	bgt _081E7010
	adds r2, r0, #0
_081E7010:
	str r6, [sp]
	adds r0, r2, #0
	movs r1, #0xa
	movs r2, #0x15
	movs r3, #0
	bl FUN_081e4604
	movs r0, #0xb0
	lsls r0, r0, #5
	adds r4, r5, r0
	ldr r0, [r4]
	ldr r2, _081E70E0 @ =0x000015F0
	adds r1, r5, r2
	ldr r1, [r1]
	bl TextPanel_SetScript
	ldr r0, [r4]
	movs r1, #0
	bl TextPanel_SetMessage
	ldr r0, [r4]
	bl TextPanel_Start
	ldr r3, _081E70E4 @ =0x00001599
	adds r1, r5, r3
	movs r0, #0xff
	strb r0, [r1]
	ldr r1, _081E70E8 @ =0x00001619
	adds r0, r5, r1
	strb r6, [r0]
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r0, [r7]
	orrs r0, r1
	str r0, [r7]
_081E7056:
	ldr r2, _081E70E4 @ =0x00001599
	adds r0, r5, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _081E7074
	movs r3, #0xf6
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
_081E7074:
	ldr r1, _081E70EC @ =0x00001617
	adds r0, r5, r1
	movs r4, #0
	strb r4, [r0]
	adds r0, r5, #0
	bl FUN_081e2ee8
	ldr r2, _081E70F0 @ =0x0000162A
	adds r0, r5, r2
	movs r1, #0
	strh r4, [r0]
	ldr r3, _081E70F4 @ =0x00001614
	adds r0, r5, r3
	strb r1, [r0]
_081E7090:
	movs r1, #0xb1
	lsls r1, r1, #5
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0xa
	bne _081E7108
	movs r3, #0x81
	lsls r3, r3, #4
	adds r1, r5, r3
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r0, _081E70F8 @ =0x00001514
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, _081E70FC @ =0x00001624
	adds r0, r5, r1
	strb r2, [r0]
	ldr r3, _081E7100 @ =0x000014B4
	adds r1, r5, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _081E7104 @ =FUN_081e653c
	movs r1, #0x11
	b _081E7378
	.align 2, 0
_081E70CC: .4byte 0x0000161A
_081E70D0: .4byte 0x00001608
_081E70D4: .4byte 0x00001590
_081E70D8: .4byte 0x030046A0
_081E70DC: .4byte 0x0000270F
_081E70E0: .4byte 0x000015F0
_081E70E4: .4byte 0x00001599
_081E70E8: .4byte 0x00001619
_081E70EC: .4byte 0x00001617
_081E70F0: .4byte 0x0000162A
_081E70F4: .4byte 0x00001614
_081E70F8: .4byte 0x00001514
_081E70FC: .4byte 0x00001624
_081E7100: .4byte 0x000014B4
_081E7104: .4byte FUN_081e653c
_081E7108:
	movs r2, #0x80
	lsls r2, r2, #6
	ldr r3, _081E7120 @ =0x00001610
	adds r1, r5, r3
	ldr r0, [r1]
	ands r0, r2
	adds r7, r1, #0
	cmp r0, #0
	beq _081E7124
	movs r0, #1
	b _081E7126
	.align 2, 0
_081E7120: .4byte 0x00001610
_081E7124:
	movs r0, #0
_081E7126:
	cmp r0, #0
	beq _081E7158
	ldr r0, _081E7148 @ =FUN_081e6a2c
	movs r2, #8
	str r0, [r5, #0x18]
	ldr r0, _081E714C @ =0x00001614
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E7150 @ =0x00001616
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, _081E7154 @ =0xFFFFCFFF
	ldr r0, [r7]
	ands r0, r1
	str r0, [r7]
	b _081E7400
	.align 2, 0
_081E7148: .4byte FUN_081e6a2c
_081E714C: .4byte 0x00001614
_081E7150: .4byte 0x00001616
_081E7154: .4byte 0xFFFFCFFF
_081E7158:
	adds r0, r5, #0
	bl FUN_081e2ee8
	ldr r2, _081E717C @ =0x00000808
	adds r0, r5, r2
	ldr r3, _081E7180 @ =0x00000AC8
	adds r1, r5, r3
	bl MainSprite_AdvanceAnim
	ldr r0, _081E7184 @ =0x0000162A
	adds r1, r5, r0
	ldrh r0, [r1]
	cmp r0, #0x1e
	bls _081E7188
	adds r0, #1
	strh r0, [r1]
	b _081E7400
	.align 2, 0
_081E717C: .4byte 0x00000808
_081E7180: .4byte 0x00000AC8
_081E7184: .4byte 0x0000162A
_081E7188:
	ldr r1, _081E71B0 @ =0x0000161A
	adds r0, r5, r1
	ldrb r4, [r0]
	adds r0, r5, #0
	bl FUN_081e4ab8
	adds r1, r0, #0
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _081E71B8
	asrs r0, r4, #2
	cmp r0, #0
	bne _081E71B4
	movs r0, #3
	ands r0, r4
	adds r4, r0, #0
	adds r4, #0xc
	b _081E7214
	.align 2, 0
_081E71B0: .4byte 0x0000161A
_081E71B4:
	subs r4, #4
	b _081E7214
_081E71B8:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _081E71D8
	asrs r0, r4, #2
	cmp r0, #3
	bne _081E71CA
	ands r4, r0
	b _081E71CC
_081E71CA:
	adds r4, #4
_081E71CC:
	ldr r3, _081E71D4 @ =0x00001619
	adds r1, r5, r3
	b _081E7218
	.align 2, 0
_081E71D4: .4byte 0x00001619
_081E71D8:
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _081E71FC
	movs r0, #3
	ands r0, r4
	cmp r0, #0
	bne _081E71F0
	movs r0, #0xfc
	ands r0, r4
	adds r4, r0, #3
	b _081E71F2
_081E71F0:
	subs r4, #1
_081E71F2:
	ldr r0, _081E71F8 @ =0x00001619
	adds r1, r5, r0
	b _081E7218
	.align 2, 0
_081E71F8: .4byte 0x00001619
_081E71FC:
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _081E721C
	movs r0, #3
	ands r0, r4
	cmp r0, #3
	bne _081E7212
	movs r0, #0xfc
	ands r4, r0
	b _081E7214
_081E7212:
	adds r4, #1
_081E7214:
	ldr r2, _081E7254 @ =0x00001619
	adds r1, r5, r2
_081E7218:
	movs r0, #0
	strb r0, [r1]
_081E721C:
	ldr r3, _081E7258 @ =0x0000161A
	adds r7, r5, r3
	ldrb r0, [r7]
	cmp r4, r0
	beq _081E7264
	movs r1, #3
	ands r1, r4
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x90
	ldr r2, _081E725C @ =0x00000828
	adds r1, r5, r2
	strh r0, [r1]
	asrs r1, r4, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	ldr r3, _081E7260 @ =0x0000082A
	adds r1, r5, r3
	strh r0, [r1]
	strb r4, [r7]
	movs r0, #0xdc
	bl PlaySound_082406e0
	b _081E7400
	.align 2, 0
_081E7254: .4byte 0x00001619
_081E7258: .4byte 0x0000161A
_081E725C: .4byte 0x00000828
_081E7260: .4byte 0x0000082A
_081E7264:
	ldr r0, _081E7310 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	mov r8, r0
	movs r6, #1
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _081E7334
	adds r0, r5, #0
	bl FUN_081e3e78
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E7284
	b _081E73BA
_081E7284:
	ldr r1, _081E7314 @ =0x00001599
	adds r2, r5, r1
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	blt _081E72BC
	adds r1, r0, #0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r0, r5, r0
	ldr r3, _081E7318 @ =0x00000E86
	adds r0, r0, r3
	ldr r1, _081E731C @ =0x000002DF
	strh r1, [r0]
	movs r1, #0
	ldrsb r1, [r2, r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r3, #0xe
	adds r1, r5, r3
	adds r1, r1, r0
	ldr r0, _081E7320 @ =0x03003584
	ldr r0, [r0]
	ldr r3, _081E7324 @ =0x00005BE0
	adds r0, r0, r3
	str r0, [r1]
_081E72BC:
	ldrb r0, [r7]
	strb r0, [r2]
	movs r0, #0xf6
	lsls r0, r0, #3
	adds r1, r5, r0
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1]
	movs r1, #3
	ands r1, r4
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x90
	ldr r3, _081E7328 @ =0x00000A68
	adds r1, r5, r3
	strh r0, [r1]
	asrs r1, r4, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	adds r3, #2
	adds r1, r5, r3
	strh r0, [r1]
	movs r0, #0xa5
	lsls r0, r0, #4
	adds r1, r5, r0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	ldr r0, _081E732C @ =FUN_081e52ac
	movs r1, #6
	str r0, [r5, #0x18]
	ldr r2, _081E7330 @ =0x00001614
	adds r0, r5, r2
	mov r3, r8
	strb r3, [r0]
	adds r2, #2
	b _081E7382
	.align 2, 0
_081E7310: .4byte 0x030044E0
_081E7314: .4byte 0x00001599
_081E7318: .4byte 0x00000E86
_081E731C: .4byte 0x000002DF
_081E7320: .4byte 0x03003584
_081E7324: .4byte 0x00005BE0
_081E7328: .4byte 0x00000A68
_081E732C: .4byte FUN_081e52ac
_081E7330: .4byte 0x00001614
_081E7334:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _081E73A4
	adds r0, r5, #0
	movs r1, #0xa
	bl FUN_081e4c64
	ldr r3, _081E7388 @ =0x00001618
	adds r1, r5, r3
	movs r0, #0xa
	strb r0, [r1]
	movs r0, #0x81
	lsls r0, r0, #4
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r6
	str r0, [r1]
	ldr r2, _081E738C @ =0x00001514
	adds r1, r5, r2
	ldr r0, [r1]
	orrs r0, r6
	str r0, [r1]
	ldr r3, _081E7390 @ =0x000014B4
	adds r1, r5, r3
	ldr r0, [r1]
	orrs r0, r6
	str r0, [r1]
	ldr r1, _081E7394 @ =0x00001624
	adds r0, r5, r1
	mov r2, r8
	strb r2, [r0]
	ldr r0, _081E7398 @ =FUN_081e5d14
	movs r1, #0x10
_081E7378:
	str r0, [r5, #0x18]
	ldr r3, _081E739C @ =0x00001614
	adds r0, r5, r3
	strb r2, [r0]
	ldr r2, _081E73A0 @ =0x00001616
_081E7382:
	adds r0, r5, r2
	strb r1, [r0]
	b _081E7400
	.align 2, 0
_081E7388: .4byte 0x00001618
_081E738C: .4byte 0x00001514
_081E7390: .4byte 0x000014B4
_081E7394: .4byte 0x00001624
_081E7398: .4byte FUN_081e5d14
_081E739C: .4byte 0x00001614
_081E73A0: .4byte 0x00001616
_081E73A4:
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _081E7400
	ldr r3, _081E73C4 @ =0x00001599
	adds r0, r5, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bge _081E73C8
_081E73BA:
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _081E7400
	.align 2, 0
_081E73C4: .4byte 0x00001599
_081E73C8:
	movs r0, #0xf6
	lsls r0, r0, #3
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r6
	str r0, [r1]
	str r6, [sp]
	movs r0, #3
	str r0, [sp, #4]
	movs r0, #0x19
	movs r1, #0x10
	movs r2, #5
	movs r3, #1
	bl FUN_081e4644
	ldr r0, _081E740C @ =FUN_081e53e8
	movs r1, #9
	str r0, [r5, #0x18]
	ldr r2, _081E7410 @ =0x00001614
	adds r0, r5, r2
	mov r3, r8
	strb r3, [r0]
	adds r2, #2
	adds r0, r5, r2
	strb r1, [r0]
	movs r0, #0xdd
	bl PlaySound_082406e0
_081E7400:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E740C: .4byte FUN_081e53e8
_081E7410: .4byte 0x00001614
