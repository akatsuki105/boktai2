	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r7, r4, #0
	ldrb r0, [r4]
	cmp r0, #0x2f
	bne _08048DB4
	b _080493D0
_08048DB4:
	ldr r1, _08048DC8 @ =0x08251B64
	adds r0, r4, #0
	movs r2, #6
	bl TextBox_StrNCmp
	cmp r0, #0
	bne _08048DCC
	movs r0, #1
	b _0804945A
	.align 2, 0
_08048DC8: .4byte 0x08251B64
_08048DCC:
	ldr r1, _08048DE0 @ =0x08251B6C
	adds r0, r4, #0
	movs r2, #6
	bl TextBox_StrNCmp
	cmp r0, #0
	bne _08048DE4
	movs r0, #2
	b _0804945A
	.align 2, 0
_08048DE0: .4byte 0x08251B6C
_08048DE4:
	ldr r1, _08048DF8 @ =0x08251B74
	adds r0, r4, #0
	movs r2, #6
	bl TextBox_StrNCmp
	cmp r0, #0
	bne _08048DFC
	movs r0, #2
	b _0804945A
	.align 2, 0
_08048DF8: .4byte 0x08251B74
_08048DFC:
	ldr r1, _08048E2C @ =0x08251B7C
	adds r0, r4, #0
	movs r2, #4
	bl TextBox_StrNCmp
	cmp r0, #0
	bne _08048E40
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08048ce0
	adds r7, r0, #0
	ldr r0, [r5, #0x2c]
	cmp r0, #0
	beq _08048E30
	ldr r1, [r5, #0x30]
	cmp r1, #0
	beq _08048E30
	adds r0, r5, #0
	adds r0, #0x34
	bl TextBox_ParseDecimal
	strb r0, [r5, #9]
	b _08049466
	.align 2, 0
_08048E2C: .4byte 0x08251B7C
_08048E30:
	ldr r0, _08048E3C @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x12
	ldrsh r0, [r0, r1]
	strb r0, [r5, #9]
	b _08049466
	.align 2, 0
_08048E3C: .4byte 0x030046A0
_08048E40:
	ldr r1, _08048E70 @ =0x08251B84
	adds r0, r4, #0
	movs r2, #4
	bl TextBox_StrNCmp
	cmp r0, #0
	bne _08048E90
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08048ce0
	adds r7, r0, #0
	ldr r0, [r5, #0x2c]
	cmp r0, #0
	beq _08048E74
	ldr r1, [r5, #0x30]
	cmp r1, #0
	beq _08048E74
	adds r0, r5, #0
	adds r0, #0x34
	bl TextBox_ParseDecimal
	adds r3, r0, #0
	b _08048E76
	.align 2, 0
_08048E70: .4byte 0x08251B84
_08048E74:
	movs r3, #0
_08048E76:
	movs r0, #0xa6
	lsls r0, r0, #1
	adds r2, r5, r0
	movs r1, #0xa8
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r2]
	adds r0, r0, r1
	strb r3, [r0]
	ldr r0, [r2]
	adds r0, #1
	str r0, [r2]
	b _08049466
_08048E90:
	ldr r1, _08048EB0 @ =0x08251B8C
	adds r0, r4, #0
	movs r2, #4
	bl TextBox_StrNCmp
	cmp r0, #0
	bne _08048EB4
	bl FUN_0823cd38
	str r0, [r5, #0x20]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08048934
	adds r0, r4, #0
	b _08049302
	.align 2, 0
_08048EB0: .4byte 0x08251B8C
_08048EB4:
	ldr r1, _08048F14 @ =0x08251B94
	adds r0, r4, #0
	movs r2, #5
	bl TextBox_StrNCmp
	cmp r0, #0
	beq _08048EC4
	b _080491D8
_08048EC4:
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08048ce0
	adds r7, r0, #0
	ldr r0, [r5, #0x2c]
	cmp r0, #0
	bne _08048ED6
	b _080491C4
_08048ED6:
	ldr r0, [r5, #0x30]
	cmp r0, #0
	bne _08048EDE
	b _080491C4
_08048EDE:
	adds r4, r5, #0
	adds r4, #0x34
	ldr r1, _08048F18 @ =0x08251B9C
	adds r0, r4, #0
	movs r2, #4
	bl TextBox_StrNCmp
	cmp r0, #0
	bne _08048EF2
	b _080491C4
_08048EF2:
	ldr r1, _08048F1C @ =0x08251BA4
	adds r0, r4, #0
	movs r2, #8
	bl TextBox_StrNCmp
	cmp r0, #0
	bne _08048F02
	b _080491C6
_08048F02:
	ldr r1, _08048F20 @ =0x08251BB0
	adds r0, r4, #0
	movs r2, #8
	bl TextBox_StrNCmp
	cmp r0, #0
	bne _08048F24
	movs r0, #1
	b _080491C6
	.align 2, 0
_08048F14: .4byte 0x08251B94
_08048F18: .4byte 0x08251B9C
_08048F1C: .4byte 0x08251BA4
_08048F20: .4byte 0x08251BB0
_08048F24:
	ldr r1, _08048F38 @ =0x08251BBC
	adds r0, r4, #0
	movs r2, #6
	bl TextBox_StrNCmp
	cmp r0, #0
	bne _08048F3C
	movs r0, #2
	b _080491C6
	.align 2, 0
_08048F38: .4byte 0x08251BBC
_08048F3C:
	ldr r1, _08048F50 @ =0x08251BC4
	adds r0, r4, #0
	movs r2, #6
	bl TextBox_StrNCmp
	cmp r0, #0
	bne _08048F54
	movs r0, #3
	b _080491C6
	.align 2, 0
_08048F50: .4byte 0x08251BC4
_08048F54:
	ldr r1, _08048F68 @ =0x08251BCC
	adds r0, r4, #0
	movs r2, #5
	bl TextBox_StrNCmp
	cmp r0, #0
	bne _08048F6C
	movs r0, #4
	b _080491C6
	.align 2, 0
_08048F68: .4byte 0x08251BCC
_08048F6C:
	ldr r1, _08048F80 @ =0x08251BD4
	adds r0, r4, #0
	movs r2, #4
	bl TextBox_StrNCmp
	cmp r0, #0
	bne _08048F84
	movs r0, #5
	b _080491C6
	.align 2, 0
_08048F80: .4byte 0x08251BD4
_08048F84:
	ldr r1, _08048F98 @ =0x08251BDC
	adds r0, r4, #0
	movs r2, #4
	bl TextBox_StrNCmp
	cmp r0, #0
	bne _08048F9C
	movs r0, #6
	b _080491C6
	.align 2, 0
_08048F98: .4byte 0x08251BDC
_08048F9C:
	ldr r1, _08048FB0 @ =0x08251BE4
	adds r0, r4, #0
	movs r2, #6
	bl TextBox_StrNCmp
	cmp r0, #0
	bne _08048FB4
	movs r0, #7
	b _080491C6
	.align 2, 0
_08048FB0: .4byte 0x08251BE4
_08048FB4:
	ldr r1, _08048FC8 @ =0x08251BEC
	adds r0, r4, #0
	movs r2, #8
	bl TextBox_StrNCmp
	cmp r0, #0
	bne _08048FCC
	movs r0, #0x1d
	b _080491C6
	.align 2, 0
_08048FC8: .4byte 0x08251BEC
_08048FCC:
	ldr r1, _08048FE0 @ =0x08251BF8
	adds r0, r4, #0
	movs r2, #4
	bl TextBox_StrNCmp
	cmp r0, #0
	bne _08048FE4
	movs r0, #8
	b _080491C6
	.align 2, 0
_08048FE0: .4byte 0x08251BF8
_08048FE4:
	ldr r1, _08048FF8 @ =0x08251C00
	adds r0, r4, #0
	movs r2, #3
	bl TextBox_StrNCmp
	cmp r0, #0
	bne _08048FFC
	movs r0, #9
	b _080491C6
	.align 2, 0
_08048FF8: .4byte 0x08251C00
_08048FFC:
	ldr r1, _08049010 @ =0x08251C04
	adds r0, r4, #0
	movs r2, #6
	bl TextBox_StrNCmp
	cmp r0, #0
	bne _08049014
	movs r0, #0xa
	b _080491C6
	.align 2, 0
_08049010: .4byte 0x08251C04
_08049014:
	ldr r1, _08049028 @ =0x08251C0C
	adds r0, r4, #0
	movs r2, #4
	bl TextBox_StrNCmp
	cmp r0, #0
	bne _0804902C
	movs r0, #0xb
	b _080491C6
	.align 2, 0
_08049028: .4byte 0x08251C0C
_0804902C:
	ldr r1, _08049040 @ =0x08251C14
	adds r0, r4, #0
	movs r2, #6
	bl TextBox_StrNCmp
	cmp r0, #0
	bne _08049044
	movs r0, #0xc
	b _080491C6
	.align 2, 0
_08049040: .4byte 0x08251C14
_08049044:
	ldr r1, _08049058 @ =0x08251C1C
	adds r0, r4, #0
	movs r2, #5
	bl TextBox_StrNCmp
	cmp r0, #0
	bne _0804905C
	movs r0, #0xd
	b _080491C6
	.align 2, 0
_08049058: .4byte 0x08251C1C
_0804905C:
	ldr r1, _08049070 @ =0x08251C24
	adds r0, r4, #0
	movs r2, #7
	bl TextBox_StrNCmp
	cmp r0, #0
	bne _08049074
	movs r0, #0xe
	b _080491C6
	.align 2, 0
_08049070: .4byte 0x08251C24
_08049074:
	ldr r1, _08049088 @ =0x08251C2C
	adds r0, r4, #0
	movs r2, #7
	bl TextBox_StrNCmp
	cmp r0, #0
	bne _0804908C
	movs r0, #0xf
	b _080491C6
	.align 2, 0
_08049088: .4byte 0x08251C2C
_0804908C:
	ldr r1, _080490A0 @ =0x08251C34
	adds r0, r4, #0
	movs r2, #7
	bl TextBox_StrNCmp
	cmp r0, #0
	bne _080490A4
	movs r0, #0x10
	b _080491C6
	.align 2, 0
_080490A0: .4byte 0x08251C34
_080490A4:
	ldr r1, _080490B8 @ =0x08251C3C
	adds r0, r4, #0
	movs r2, #5
	bl TextBox_StrNCmp
	cmp r0, #0
	bne _080490BC
	movs r0, #0x11
	b _080491C6
	.align 2, 0
_080490B8: .4byte 0x08251C3C
_080490BC:
	ldr r1, _080490D0 @ =0x08251C44
	adds r0, r4, #0
	movs r2, #7
	bl TextBox_StrNCmp
	cmp r0, #0
	bne _080490D4
	movs r0, #0x12
	b _080491C6
	.align 2, 0
_080490D0: .4byte 0x08251C44
_080490D4:
	ldr r1, _080490E8 @ =0x08251C4C
	adds r0, r4, #0
	movs r2, #7
	bl TextBox_StrNCmp
	cmp r0, #0
	bne _080490EC
	movs r0, #0x13
	b _080491C6
	.align 2, 0
_080490E8: .4byte 0x08251C4C
_080490EC:
	ldr r1, _08049100 @ =0x08251C54
	adds r0, r4, #0
	movs r2, #9
	bl TextBox_StrNCmp
	cmp r0, #0
	bne _08049104
	movs r0, #0x14
	b _080491C6
	.align 2, 0
_08049100: .4byte 0x08251C54
_08049104:
	ldr r1, _08049118 @ =0x08251C60
	adds r0, r4, #0
	movs r2, #6
	bl TextBox_StrNCmp
	cmp r0, #0
	bne _0804911C
	movs r0, #0x15
	b _080491C6
	.align 2, 0
_08049118: .4byte 0x08251C60
_0804911C:
	ldr r1, _08049130 @ =0x08251C68
	adds r0, r4, #0
	movs r2, #6
	bl TextBox_StrNCmp
	cmp r0, #0
	bne _08049134
	movs r0, #0x16
	b _080491C6
	.align 2, 0
_08049130: .4byte 0x08251C68
_08049134:
	ldr r1, _08049148 @ =0x08251C70
	adds r0, r4, #0
	movs r2, #6
	bl TextBox_StrNCmp
	cmp r0, #0
	bne _0804914C
	movs r0, #0x17
	b _080491C6
	.align 2, 0
_08049148: .4byte 0x08251C70
_0804914C:
	ldr r1, _08049160 @ =0x08251C78
	adds r0, r4, #0
	movs r2, #7
	bl TextBox_StrNCmp
	cmp r0, #0
	bne _08049164
	movs r0, #0x18
	b _080491C6
	.align 2, 0
_08049160: .4byte 0x08251C78
_08049164:
	ldr r1, _08049178 @ =0x08251C80
	adds r0, r4, #0
	movs r2, #8
	bl TextBox_StrNCmp
	cmp r0, #0
	bne _0804917C
	movs r0, #0x19
	b _080491C6
	.align 2, 0
_08049178: .4byte 0x08251C80
_0804917C:
	ldr r1, _08049190 @ =0x08251C8C
	adds r0, r4, #0
	movs r2, #6
	bl TextBox_StrNCmp
	cmp r0, #0
	bne _08049194
	movs r0, #0x1a
	b _080491C6
	.align 2, 0
_08049190: .4byte 0x08251C8C
_08049194:
	ldr r1, _080491A8 @ =0x08251C94
	adds r0, r4, #0
	movs r2, #6
	bl TextBox_StrNCmp
	cmp r0, #0
	bne _080491AC
	bl FUN_08048d78
	b _080491C6
	.align 2, 0
_080491A8: .4byte 0x08251C94
_080491AC:
	ldr r1, _080491C0 @ =0x08251C9C
	adds r0, r4, #0
	movs r2, #6
	bl TextBox_StrNCmp
	cmp r0, #0
	bne _080491C4
	bl FUN_08048d40
	b _080491C6
	.align 2, 0
_080491C0: .4byte 0x08251C9C
_080491C4:
	movs r0, #0xff
_080491C6:
	strb r0, [r5, #0x15]
	movs r0, #0
	movs r1, #1
	strb r1, [r5, #0xb]
	ldrb r1, [r5, #9]
	strb r1, [r5, #0xc]
	strb r0, [r5, #9]
	adds r0, r7, #0
	b _0804945E
_080491D8:
	ldr r1, _080491EC @ =0x08251CA4
	adds r0, r4, #0
	movs r2, #7
	bl TextBox_StrNCmp
	cmp r0, #0
	bne _080491F0
	movs r0, #0xff
	strb r0, [r5, #0x15]
	b _0804945C
	.align 2, 0
_080491EC: .4byte 0x08251CA4
_080491F0:
	ldr r1, _08049220 @ =0x08251CAC
	adds r0, r4, #0
	movs r2, #4
	bl TextBox_StrNCmp
	cmp r0, #0
	bne _0804922A
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08048ce0
	adds r7, r0, #0
	ldr r0, [r5, #0x2c]
	cmp r0, #0
	beq _08049224
	ldr r1, [r5, #0x30]
	cmp r1, #0
	beq _08049224
	adds r0, r5, #0
	adds r0, #0x34
	bl TextBox_ParseDecimal
	b _08049226
	.align 2, 0
_08049220: .4byte 0x08251CAC
_08049224:
	movs r0, #0
_08049226:
	str r0, [r5, #0x18]
	b _08049466
_0804922A:
	ldr r1, _08049258 @ =0x08251CB4
	adds r0, r4, #0
	movs r2, #6
	bl TextBox_StrNCmp
	cmp r0, #0
	bne _08049272
	adds r0, r5, #0
	adds r1, r7, #0
	bl FUN_08048ce0
	adds r7, r0, #0
	ldr r0, [r5, #0x2c]
	cmp r0, #0
	beq _0804925C
	ldr r1, [r5, #0x30]
	cmp r1, #0
	beq _0804925C
	adds r0, r5, #0
	adds r0, #0x34
	bl TextBox_ParseDecimal
	b _0804925E
	.align 2, 0
_08049258: .4byte 0x08251CB4
_0804925C:
	movs r0, #0
_0804925E:
	lsls r1, r0, #2
	movs r2, #0x86
	lsls r2, r2, #1
	adds r0, r5, r2
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [r5, #0x28]
	adds r0, r5, #0
	movs r1, #3
	b _080492FC
_08049272:
	ldr r1, _080492A0 @ =0x08251CBC
	adds r0, r4, #0
	movs r2, #5
	bl TextBox_StrNCmp
	cmp r0, #0
	bne _080492AC
	adds r0, r5, #0
	adds r1, r7, #0
	bl FUN_08048ce0
	adds r7, r0, #0
	ldr r0, [r5, #0x2c]
	cmp r0, #0
	beq _080492A4
	ldr r1, [r5, #0x30]
	cmp r1, #0
	beq _080492A4
	adds r0, r5, #0
	adds r0, #0x34
	bl TextBox_ParseDecimal
	b _080492A6
	.align 2, 0
_080492A0: .4byte 0x08251CBC
_080492A4:
	movs r0, #0xdd
_080492A6:
	bl PlaySound_082406e0
	b _08049466
_080492AC:
	ldr r1, _080492DC @ =0x08251CC4
	adds r0, r4, #0
	movs r2, #3
	bl TextBox_StrNCmp
	cmp r0, #0
	bne _08049310
	adds r0, r5, #0
	adds r1, r7, #0
	bl FUN_08048ce0
	adds r7, r0, #0
	ldr r0, [r5, #0x2c]
	cmp r0, #0
	beq _080492E0
	ldr r1, [r5, #0x30]
	cmp r1, #0
	beq _080492E0
	adds r0, r5, #0
	adds r0, #0x34
	bl TextBox_ParseDecimal
	b _080492E2
	.align 2, 0
_080492DC: .4byte 0x08251CC4
_080492E0:
	movs r0, #0
_080492E2:
	adds r4, r5, #0
	adds r4, #0x78
	lsls r1, r0, #2
	adds r0, r5, #0
	adds r0, #0x84
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl FUN_08048b28
	str r4, [r5, #0x24]
	adds r0, r5, #0
	movs r1, #2
_080492FC:
	bl FUN_08048934
	adds r0, r7, #0
_08049302:
	movs r1, #0x3e
	bl TextBox_FindChar
	adds r7, r0, #0
	movs r0, #1
	strb r0, [r5, #0xe]
	b _08049466
_08049310:
	ldr r1, _08049340 @ =0x08251CC8
	adds r0, r4, #0
	movs r2, #6
	bl TextBox_StrNCmp
	adds r6, r0, #0
	cmp r6, #0
	bne _08049360
	adds r0, r5, #0
	adds r1, r7, #0
	bl FUN_08048ce0
	adds r7, r0, #0
	adds r4, r5, #0
	adds r4, #0x34
	ldr r1, _08049344 @ =0x08251CD0
	adds r0, r4, #0
	movs r2, #0xd
	bl TextBox_StrNCmp
	cmp r0, #0
	bne _08049348
_0804933C:
	strb r6, [r5, #0x11]
	b _08049466
	.align 2, 0
_08049340: .4byte 0x08251CC8
_08049344: .4byte 0x08251CD0
_08049348:
	ldr r1, _0804935C @ =0x08251CE0
	adds r0, r4, #0
	movs r2, #0xb
	bl TextBox_StrNCmp
	cmp r0, #0
	bne _0804933C
	movs r0, #1
	strb r0, [r5, #0x11]
	b _08049466
	.align 2, 0
_0804935C: .4byte 0x08251CE0
_08049360:
	ldr r1, _08049384 @ =0x08251CEC
	adds r0, r4, #0
	movs r2, #3
	bl TextBox_StrNCmp
	cmp r0, #0
	bne _08049388
	bl FUN_0823cd38
	str r0, [r5, #0x20]
	adds r0, r7, #0
	movs r1, #0x3e
	bl TextBox_FindChar
	adds r7, r0, #0
	movs r0, #1
	strb r0, [r5, #0xf]
	b _08049466
	.align 2, 0
_08049384: .4byte 0x08251CEC
_08049388:
	ldr r1, _080493B0 @ =0x08251CF0
	adds r0, r4, #0
	movs r2, #5
	bl TextBox_StrNCmp
	cmp r0, #0
	bne _080493B4
	ldrb r0, [r5, #0x10]
	cmp r0, #0
	beq _080493AC
	adds r0, r5, #0
	movs r1, #0x5b
	bl FUN_080489c4
	adds r0, r5, #0
	movs r1, #0x3b
	bl FUN_08048a20
_080493AC:
	adds r0, r7, #0
	b _0804945E
	.align 2, 0
_080493B0: .4byte 0x08251CF0
_080493B4:
	ldr r1, _080493CC @ =0x08251CF8
	adds r0, r4, #0
	movs r2, #5
	bl TextBox_StrNCmp
	cmp r0, #0
	bne _08049466
	movs r0, #1
	strb r0, [r5, #6]
	adds r0, r7, #0
	b _0804945E
	.align 2, 0
_080493CC: .4byte 0x08251CF8
_080493D0:
	ldr r1, _08049410 @ =0x08251D00
	adds r0, r4, #0
	movs r2, #7
	bl TextBox_StrNCmp
	cmp r0, #0
	beq _0804945A
	ldr r1, _08049414 @ =0x08251D08
	adds r0, r4, #0
	movs r2, #7
	bl TextBox_StrNCmp
	cmp r0, #0
	beq _0804945A
	ldr r1, _08049418 @ =0x08251D10
	adds r0, r4, #0
	movs r2, #7
	bl TextBox_StrNCmp
	cmp r0, #0
	beq _0804945A
	ldr r1, _0804941C @ =0x08251D18
	adds r0, r4, #0
	movs r2, #6
	bl TextBox_StrNCmp
	cmp r0, #0
	bne _08049420
	strb r0, [r5, #0xb]
	ldrb r0, [r5, #0xc]
	strb r0, [r5, #9]
	b _0804945C
	.align 2, 0
_08049410: .4byte 0x08251D00
_08049414: .4byte 0x08251D08
_08049418: .4byte 0x08251D10
_0804941C: .4byte 0x08251D18
_08049420:
	ldr r1, _08049448 @ =0x08251D20
	adds r0, r4, #0
	movs r2, #5
	bl TextBox_StrNCmp
	cmp r0, #0
	bne _0804944C
	ldrb r0, [r5, #0x10]
	cmp r0, #0
	beq _0804945C
	adds r0, r5, #0
	movs r1, #0x5d
	bl FUN_080489c4
	adds r0, r5, #0
	movs r1, #0x3d
	bl FUN_08048a20
	b _0804945C
	.align 2, 0
_08049448: .4byte 0x08251D20
_0804944C:
	ldr r1, _08049484 @ =0x08251D28
	adds r0, r4, #0
	movs r2, #6
	bl TextBox_StrNCmp
	cmp r0, #0
	bne _08049466
_0804945A:
	strb r0, [r5, #6]
_0804945C:
	adds r0, r4, #0
_0804945E:
	movs r1, #0x3e
	bl TextBox_FindChar
	adds r7, r0, #0
_08049466:
	ldrb r0, [r5, #0x14]
	cmp r0, #0
	bne _08049470
	movs r0, #1
	strb r0, [r5, #0xe]
_08049470:
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _08049478
	adds r7, #1
_08049478:
	adds r4, r7, #0
	adds r0, r4, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08049484: .4byte 0x08251D28
