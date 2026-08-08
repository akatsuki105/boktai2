	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r6, r1, #0
	adds r0, r6, #0
	adds r0, #0xac
	ldrb r1, [r0]
	ldr r2, _082234A4 @ =0x00000F45
	adds r0, r5, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	beq _08223490
	b _08223720
_08223490:
	adds r0, r6, #0
	adds r0, #0xae
	ldrb r1, [r0]
	mov r8, r0
	cmp r1, #0
	bne _082234A8
	movs r3, #0
	movs r4, #0x80
	b _082234AC
	.align 2, 0
_082234A4: .4byte 0x00000F45
_082234A8:
	movs r3, #0x80
	movs r4, #0
_082234AC:
	ldr r2, [r5, #0x18]
	movs r7, #0x2c
	ldrsh r0, [r2, r7]
	adds r1, r6, #0
	adds r1, #0x48
	movs r7, #0
	ldrsh r1, [r1, r7]
	subs r0, r0, r1
	subs r3, r0, r3
	movs r1, #0x30
	ldrsh r0, [r2, r1]
	adds r1, r6, #0
	adds r1, #0x4c
	movs r2, #0
	ldrsh r1, [r1, r2]
	subs r0, r0, r1
	subs r2, r0, r4
	adds r1, r3, #0
	muls r1, r3, r1
	adds r0, r2, #0
	muls r0, r2, r0
	adds r1, r1, r0
	ldr r4, _082234FC @ =0x00000F1A
	adds r0, r5, r4
	ldrh r0, [r0]
	adds r7, r0, #0
	muls r7, r0, r7
	adds r0, r7, #0
	cmp r1, r0
	blt _082234EA
	b _08223720
_082234EA:
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, #0
	bne _08223500
	movs r4, #0
	mov r8, r4
	movs r4, #6
	movs r7, #7
	b _08223508
	.align 2, 0
_082234FC: .4byte 0x00000F1A
_08223500:
	movs r7, #0
	mov r8, r7
	movs r4, #1
	movs r7, #2
_08223508:
	adds r0, r3, #0
	adds r1, r2, #0
	bl FUN_0823785c
	subs r0, #0x10
	lsls r0, r0, #0x18
	mov r2, r8
	lsls r1, r2, #0x18
	asrs r1, r1, #0x18
	lsrs r2, r0, #0x1d
	cmp r1, r2
	beq _08223536
	lsls r0, r4, #0x18
	asrs r0, r0, #0x18
	cmp r0, r2
	beq _08223536
	lsls r0, r7, #0x18
	asrs r0, r0, #0x18
	cmp r0, r2
	beq _08223536
	movs r7, #0xff
	movs r4, #0xff
	mov r8, r4
_08223536:
	mov r3, r8
	lsls r1, r3, #0x18
	ldr r0, _08223668 @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _0822366C @ =0x00000932
	adds r0, r0, r2
	asrs r1, r1, #0x18
	movs r3, #0
	ldrsh r2, [r0, r3]
	cmp r1, r2
	beq _0822355E
	lsls r0, r4, #0x18
	asrs r0, r0, #0x18
	cmp r0, r2
	beq _0822355E
	lsls r0, r7, #0x18
	asrs r0, r0, #0x18
	cmp r0, r2
	beq _0822355E
	b _08223720
_0822355E:
	adds r0, r6, #0
	adds r0, #0x4a
	movs r4, #0
	ldrsh r1, [r0, r4]
	ldr r2, [r5, #0x18]
	movs r7, #0x2e
	ldrsh r0, [r2, r7]
	subs r1, r1, r0
	cmp r1, #0
	bge _08223574
	rsbs r1, r1, #0
_08223574:
	cmp r1, #0x77
	ble _0822357A
	b _08223720
_0822357A:
	ldr r0, _08223670 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08223588
	b _08223720
_08223588:
	ldr r0, _08223674 @ =0x030044BC
	ldr r0, [r0]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08223596
	b _08223720
_08223596:
	ldr r0, [r2, #0x1c]
	cmp r0, #4
	bne _0822359E
	b _08223720
_0822359E:
	adds r0, r6, #0
	adds r0, #0xa4
	ldr r0, [r0]
	cmp r0, #0
	beq _082235AE
	movs r1, #0
	bl FUN_082318ac
_082235AE:
	ldrh r1, [r6, #0x1c]
	ldr r2, _08223678 @ =0x00000DB8
	adds r0, r5, r2
	strh r1, [r0]
	ldrh r1, [r6, #0x1e]
	ldr r3, _0822367C @ =0x00000DBA
	adds r0, r5, r3
	strh r1, [r0]
	ldrh r1, [r6, #0x20]
	ldr r4, _08223680 @ =0x00000DBC
	adds r0, r5, r4
	strh r1, [r0]
	ldr r7, _08223684 @ =0x00000F0C
	adds r1, r5, r7
	adds r0, r6, #0
	adds r0, #0xa0
	ldr r0, [r0]
	str r0, [r1]
	adds r0, r6, #0
	adds r0, #0xaf
	ldrb r1, [r0]
	ldr r2, _08223688 @ =0x00000F26
	adds r0, r5, r2
	strb r1, [r0]
	adds r2, r6, #0
	adds r2, #0xad
	ldrb r1, [r2]
	movs r0, #0x10
	ands r0, r1
	adds r7, r2, #0
	cmp r0, #0
	beq _082236A8
	ldr r3, _0822368C @ =0x00000F16
	adds r4, r5, r3
	ldrb r0, [r4]
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1c
	ldr r1, _08223690 @ =0x00000F18
	adds r3, r5, r1
	strh r0, [r3]
	movs r2, #1
	ldrb r1, [r4]
	movs r0, #0x10
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r4]
	ldrh r1, [r4]
	movs r2, #0xf
	adds r0, r2, #0
	ands r0, r1
	movs r1, #0x30
	orrs r0, r1
	strh r0, [r4]
	ldrh r0, [r3]
	cmp r0, #3
	bne _08223642
	ldrb r1, [r4]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #3
	bne _08223642
	ldr r2, _08223694 @ =0x00000DEC
	adds r0, r5, r2
	ldrh r1, [r0]
	ldr r3, _08223698 @ =0x00000F42
	adds r0, r5, r3
	strb r1, [r0]
	ldr r4, _0822369C @ =0x00000DF2
	adds r0, r5, r4
	ldrh r1, [r0]
	ldr r2, _082236A0 @ =0x00000F43
	adds r0, r5, r2
	strb r1, [r0]
_08223642:
	movs r1, #1
	movs r4, #0xf2
	lsls r4, r4, #4
	adds r3, r5, r4
	ldrb r2, [r3]
	adds r0, r1, #0
	orrs r0, r2
	strb r0, [r3]
	ldr r2, _082236A4 @ =FUN_08224f14
	adds r0, r6, #0
	adds r0, #0xa8
	str r2, [r0]
	ldrb r0, [r7]
	orrs r1, r0
	strb r1, [r7]
	adds r0, r5, #0
	bl FUN_08223984
	b _08223720
	.align 2, 0
_08223668: .4byte 0x030046A0
_0822366C: .4byte 0x00000932
_08223670: .4byte 0x030044E0
_08223674: .4byte 0x030044BC
_08223678: .4byte 0x00000DB8
_0822367C: .4byte 0x00000DBA
_08223680: .4byte 0x00000DBC
_08223684: .4byte 0x00000F0C
_08223688: .4byte 0x00000F26
_0822368C: .4byte 0x00000F16
_08223690: .4byte 0x00000F18
_08223694: .4byte 0x00000DEC
_08223698: .4byte 0x00000F42
_0822369C: .4byte 0x00000DF2
_082236A0: .4byte 0x00000F43
_082236A4: .4byte FUN_08224f14
_082236A8:
	ldr r0, _0822372C @ =0x00000F16
	adds r4, r5, r0
	ldrb r0, [r4]
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1c
	ldr r1, _08223730 @ =0x00000F18
	adds r3, r5, r1
	strh r0, [r3]
	movs r2, #1
	ldrb r1, [r4]
	movs r0, #0x10
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r4]
	ldrh r1, [r4]
	movs r2, #0xf
	adds r0, r2, #0
	ands r0, r1
	movs r1, #0x20
	orrs r0, r1
	strh r0, [r4]
	ldrh r0, [r3]
	cmp r0, #3
	bne _082236FC
	ldrb r1, [r4]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #3
	bne _082236FC
	ldr r2, _08223734 @ =0x00000DEC
	adds r0, r5, r2
	ldrh r1, [r0]
	ldr r3, _08223738 @ =0x00000F42
	adds r0, r5, r3
	strb r1, [r0]
	ldr r4, _0822373C @ =0x00000DF2
	adds r0, r5, r4
	ldrh r1, [r0]
	ldr r2, _08223740 @ =0x00000F43
	adds r0, r5, r2
	strb r1, [r0]
_082236FC:
	movs r1, #1
	movs r4, #0xf2
	lsls r4, r4, #4
	adds r3, r5, r4
	ldrb r2, [r3]
	adds r0, r1, #0
	orrs r0, r2
	strb r0, [r3]
	ldr r2, _08223744 @ =FUN_08224e10
	adds r0, r6, #0
	adds r0, #0xa8
	str r2, [r0]
	ldrb r0, [r7]
	orrs r1, r0
	strb r1, [r7]
	adds r0, r5, #0
	bl FUN_08223cdc
_08223720:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0822372C: .4byte 0x00000F16
_08223730: .4byte 0x00000F18
_08223734: .4byte 0x00000DEC
_08223738: .4byte 0x00000F42
_0822373C: .4byte 0x00000DF2
_08223740: .4byte 0x00000F43
_08223744: .4byte FUN_08224e10
