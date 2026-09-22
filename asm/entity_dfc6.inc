	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08048934
FUN_08048934: @ 0x08048934
	push {r4, lr}
	adds r3, r0, #0
	adds r4, r1, #0
	movs r0, #0x82
	lsls r0, r0, #1
	adds r2, r3, r0
	ldrb r0, [r2]
	cmp r0, #6
	bhi _0804895A
	ldr r1, _08048960 @ =0x00000105
	adds r0, r3, r1
	ldrb r1, [r2]
	adds r0, r0, r1
	ldrb r1, [r3, #7]
	strb r1, [r0]
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	strb r4, [r3, #7]
_0804895A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08048960: .4byte 0x00000105

	thumb_func_start FUN_08048964
FUN_08048964: @ 0x08048964
	push {lr}
	adds r2, r0, #0
	movs r0, #0x82
	lsls r0, r0, #1
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08048984
	subs r0, #1
	strb r0, [r1]
	ldr r3, _08048988 @ =0x00000105
	adds r0, r2, r3
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r2, #7]
_08048984:
	pop {r0}
	bx r0
	.align 2, 0
_08048988: .4byte 0x00000105

	thumb_func_start FUN_0804898c
FUN_0804898c: @ 0x0804898C
	ldrb r1, [r0, #2]
	strb r1, [r0]
	ldrb r1, [r0, #1]
	adds r1, #2
	strb r1, [r0, #1]
	bx lr

	thumb_func_start FUN_08048998
FUN_08048998: @ 0x08048998
	push {r4, lr}
	adds r3, r0, #0
	cmp r1, #0
	bne _080489A6
	ldrb r1, [r3]
	adds r1, #1
	b _080489AA
_080489A6:
	ldrb r1, [r3]
	adds r1, #2
_080489AA:
	strb r1, [r3]
	ldrb r4, [r3]
	ldrb r2, [r3, #2]
	ldrb r1, [r3, #4]
	adds r1, r2, r1
	cmp r4, r1
	blt _080489BC
	subs r1, r4, r1
	strb r1, [r3]
_080489BC:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080489c4
FUN_080489c4: @ 0x080489C4
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xa]
	cmp r0, #0
	bne _08048A18
	ldrb r0, [r4, #0xb]
	cmp r0, #0
	bne _08048A18
	ldrb r0, [r4, #9]
	cmp r0, #1
	bls _080489E0
	ldrb r0, [r4, #0x16]
	cmp r0, #0
	beq _080489E6
_080489E0:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _08048A08
_080489E6:
	cmp r1, #0
	beq _08048A02
	ldr r0, _08048A0C @ =0x030047D8
	ldrh r0, [r0]
	cmp r1, r0
	beq _08048A02
	ldr r0, _08048A10 @ =0x085AB458
	ldrb r1, [r4, #0x11]
	lsls r1, r1, #1
	adds r1, r1, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	bl PlaySound_082406e0
_08048A02:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08048A14
_08048A08:
	movs r0, #0
	b _08048A16
	.align 2, 0
_08048A0C: .4byte 0x030047D8
_08048A10: .4byte 0x085AB458
_08048A14:
	adds r0, #1
_08048A16:
	strb r0, [r4, #0x12]
_08048A18:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08048a20
FUN_08048a20: @ 0x08048A20
	push {r4, r5, lr}
	adds r5, r0, #0
	lsls r4, r1, #0x10
	lsrs r4, r4, #0x10
	adds r1, r4, #0
	bl FUN_080489c4
	ldrb r1, [r5]
	ldrb r2, [r5, #1]
	ldrb r3, [r5, #6]
	adds r0, r4, #0
	bl Video_DrawCharNarrow
	adds r0, r5, #0
	movs r1, #0
	bl FUN_08048998
	movs r1, #0
	strb r1, [r5, #0x13]
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_08048a4c
FUN_08048a4c: @ 0x08048A4C
	push {r4, r5, lr}
	adds r5, r0, #0
	lsls r4, r1, #0x10
	lsrs r4, r4, #0x10
	adds r1, r4, #0
	bl FUN_080489c4
	ldrb r1, [r5]
	ldrb r2, [r5, #1]
	ldrb r3, [r5, #6]
	adds r0, r4, #0
	bl Video_DrawCharWide
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08048998
	movs r1, #1
	strb r1, [r5, #0x13]
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_08048a78
FUN_08048a78: @ 0x08048A78
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0
	ldr r3, [r4]
	cmp r3, r1
	blt _08048A90
_08048A84:
	adds r0, #1
	subs r2, r3, r1
	adds r3, r2, #0
	cmp r2, r1
	bge _08048A84
	str r2, [r4]
_08048A90:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08048a98
FUN_08048a98: @ 0x08048A98
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r0, r1, #0
	adds r6, r2, #0
	adds r4, r3, #0
	bl VM_ParseStringRef
	adds r1, r0, #0
	adds r4, r1, r4
	adds r0, r4, #0
	bl Textbox_LookupString
	adds r1, r0, #0
	cmp r1, #0
	beq _08048ADC
	b _08048AC0
_08048AB8:
	ldrb r0, [r1]
	strb r0, [r5]
	adds r1, #1
	adds r5, #1
_08048AC0:
	ldrb r0, [r1]
	cmp r0, #0
	bne _08048AB8
	adds r0, r6, #0
	bl VM_ParseStringRef
	adds r1, r0, #0
	ldr r0, [sp, #0x10]
	adds r0, r1, r0
	bl Textbox_LookupString
	adds r1, r0, #0
	cmp r1, #0
	bne _08048AEC
_08048ADC:
	strb r1, [r5]
	movs r0, #1
	rsbs r0, r0, #0
	b _08048AF6
_08048AE4:
	ldrb r0, [r1]
	strb r0, [r5]
	adds r1, #1
	adds r5, #1
_08048AEC:
	ldrb r0, [r1]
	cmp r0, #0
	bne _08048AE4
	strb r0, [r5]
	movs r0, #0
_08048AF6:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_08048afc
FUN_08048afc: @ 0x08048AFC
	push {lr}
	ldr r2, _08048B10 @ =0x085AB45C
	ldrh r1, [r2]
	cmp r1, #0
	beq _08048B1C
	ldrb r0, [r0, #1]
_08048B08:
	cmp r1, r0
	bne _08048B14
	ldrh r0, [r2, #2]
	b _08048B1E
	.align 2, 0
_08048B10: .4byte 0x085AB45C
_08048B14:
	adds r2, #4
	ldrh r1, [r2]
	cmp r1, #0
	bne _08048B08
_08048B1C:
	ldr r0, _08048B24 @ =0x0000FFFF
_08048B1E:
	pop {r1}
	bx r1
	.align 2, 0
_08048B24: .4byte 0x0000FFFF

	thumb_func_start FUN_08048b28
FUN_08048b28: @ 0x08048B28
	push {r4, r5, lr}
	sub sp, #4
	str r1, [sp]
	movs r5, #0
	adds r4, r0, #0
	movs r2, #0
	adds r1, r4, #0
	adds r1, #0xb
_08048B38:
	strb r2, [r1]
	subs r1, #1
	cmp r1, r0
	bge _08048B38
	ldr r0, [sp]
	cmp r0, #0
	bge _08048B52
	movs r0, #0x2d
	strb r0, [r4]
	adds r4, #1
	ldr r0, [sp]
	rsbs r0, r0, #0
	str r0, [sp]
_08048B52:
	ldr r1, _08048BEC @ =0x000186A0
	mov r0, sp
	bl FUN_08048a78
	cmp r0, #0
	beq _08048B66
	adds r0, #0x30
	strb r0, [r4]
	movs r5, #1
	adds r4, #1
_08048B66:
	ldr r1, _08048BF0 @ =0x00002710
	mov r0, sp
	bl FUN_08048a78
	cmp r0, #0
	bne _08048B76
	cmp r5, #0
	beq _08048B7E
_08048B76:
	adds r0, #0x30
	strb r0, [r4]
	movs r5, #1
	adds r4, #1
_08048B7E:
	movs r1, #0xfa
	lsls r1, r1, #2
	mov r0, sp
	bl FUN_08048a78
	cmp r0, #0
	bne _08048B90
	cmp r5, #0
	beq _08048B98
_08048B90:
	adds r0, #0x30
	strb r0, [r4]
	movs r5, #1
	adds r4, #1
_08048B98:
	mov r0, sp
	movs r1, #0x64
	bl FUN_08048a78
	cmp r0, #0
	bne _08048BA8
	cmp r5, #0
	beq _08048BB0
_08048BA8:
	adds r0, #0x30
	strb r0, [r4]
	movs r5, #1
	adds r4, #1
_08048BB0:
	mov r0, sp
	movs r1, #0xa
	bl FUN_08048a78
	cmp r0, #0
	bne _08048BC0
	cmp r5, #0
	beq _08048BC6
_08048BC0:
	adds r0, #0x30
	strb r0, [r4]
	adds r4, #1
_08048BC6:
	movs r0, #0
	ldr r2, [sp]
	adds r3, r4, #1
	cmp r2, #0
	ble _08048BDC
_08048BD0:
	adds r0, #1
	subs r1, r2, #1
	adds r2, r1, #0
	cmp r1, #0
	bgt _08048BD0
	str r1, [sp]
_08048BDC:
	adds r0, #0x30
	strb r0, [r4]
	movs r0, #0
	strb r0, [r3]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08048BEC: .4byte 0x000186A0
_08048BF0: .4byte 0x00002710

	thumb_func_start TextBox_StrNCmp
TextBox_StrNCmp: @ 0x08048BF4
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r3, #0
	cmp r3, r2
	bge _08048C24
_08048BFE:
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08048C12
	ldrb r0, [r1]
	cmp r0, #0
	beq _08048C24
	movs r0, #1
	rsbs r0, r0, #0
	b _08048C26
_08048C12:
	ldrb r5, [r1]
	cmp r0, r5
	beq _08048C1C
	movs r0, #1
	b _08048C26
_08048C1C:
	adds r1, #1
	adds r3, #1
	cmp r3, r2
	blt _08048BFE
_08048C24:
	movs r0, #0
_08048C26:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start TextBox_ParseDecimal
TextBox_ParseDecimal: @ 0x08048C2C
	push {r4, lr}
	movs r4, #0
	movs r3, #1
	cmp r4, r1
	bge _08048C50
	subs r0, #1
	adds r2, r1, r0
_08048C3A:
	ldrb r0, [r2]
	subs r0, #0x30
	muls r0, r3, r0
	adds r4, r4, r0
	lsls r0, r3, #2
	adds r0, r0, r3
	lsls r3, r0, #1
	subs r2, #1
	subs r1, #1
	cmp r1, #0
	bne _08048C3A
_08048C50:
	adds r0, r4, #0
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08048c58
FUN_08048c58: @ 0x08048C58
	push {r4, r5, lr}
	ldr r4, [r0, #0x1c]
	movs r5, #0
	b _08048CBA
_08048C60:
	lsls r0, r0, #0x18
	cmp r0, #0
	blt _08048CAE
	lsrs r0, r0, #0x18
	cmp r0, #0x3c
	bne _08048C7E
_08048C6C:
	adds r4, #1
	ldrb r0, [r4]
	cmp r0, #0x3e
	beq _08048CAA
	cmp r0, #0
	beq _08048CAA
	cmp r0, #0xa
	bne _08048C6C
	b _08048CAA
_08048C7E:
	cmp r0, #0x1f
	bne _08048CA8
	adds r0, r4, #0
	bl FUN_08048afc
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	ldr r0, _08048CA4 @ =0x0000FFFF
	cmp r2, r0
	beq _08048CA8
	movs r0, #0xff
	lsls r0, r0, #8
	adds r1, r0, #0
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	bne _08048CAE
	adds r5, #1
	b _08048CB0
	.align 2, 0
_08048CA4: .4byte 0x0000FFFF
_08048CA8:
	adds r5, #1
_08048CAA:
	adds r4, #1
	b _08048CB2
_08048CAE:
	adds r5, #2
_08048CB0:
	adds r4, #2
_08048CB2:
	cmp r5, #0xfe
	ble _08048CBA
	movs r5, #0xff
	b _08048CC0
_08048CBA:
	ldrb r0, [r4]
	cmp r0, #0
	bne _08048C60
_08048CC0:
	adds r0, r5, #0
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start TextBox_FindChar
TextBox_FindChar: @ 0x08048CC8
	push {lr}
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	b _08048CD2
_08048CD0:
	adds r0, #1
_08048CD2:
	ldrb r2, [r0]
	cmp r2, r1
	beq _08048CDC
	cmp r2, #0
	bne _08048CD0
_08048CDC:
	pop {r1}
	bx r1

	thumb_func_start FUN_08048ce0
FUN_08048ce0: @ 0x08048CE0
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	adds r4, r1, #0
	movs r0, #0
	str r0, [r3, #0x2c]
	str r0, [r3, #0x30]
	movs r5, #0
	ldrb r0, [r4]
	cmp r0, #0x3e
	beq _08048D2A
	adds r6, r3, #0
	adds r6, #0x34
	cmp r0, #0
	beq _08048D2A
_08048CFC:
	ldrb r2, [r4]
	cmp r2, #0x3d
	bne _08048D08
	movs r0, #1
	str r0, [r3, #0x2c]
	b _08048D18
_08048D08:
	ldr r0, [r3, #0x2c]
	cmp r0, #0
	beq _08048D18
	ldr r1, [r3, #0x30]
	adds r0, r6, r1
	strb r2, [r0]
	adds r1, #1
	str r1, [r3, #0x30]
_08048D18:
	adds r5, #1
	adds r4, #1
	cmp r5, #0x3f
	bgt _08048D2A
	ldrb r0, [r4]
	cmp r0, #0x3e
	beq _08048D2A
	cmp r0, #0
	bne _08048CFC
_08048D2A:
	adds r0, r3, #0
	adds r0, #0x34
	ldr r1, [r3, #0x30]
	adds r0, r0, r1
	movs r1, #0
	strb r1, [r0]
	adds r0, r4, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08048d40
FUN_08048d40: @ 0x08048D40
	push {lr}
	ldr r0, _08048D60 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x94
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #1
	beq _08048D72
	cmp r0, #1
	bgt _08048D64
	cmp r0, #0
	beq _08048D6A
	b _08048D72
	.align 2, 0
_08048D60: .4byte 0x030046A0
_08048D64:
	cmp r0, #5
	beq _08048D6E
	b _08048D72
_08048D6A:
	movs r0, #0
	b _08048D74
_08048D6E:
	movs r0, #3
	b _08048D74
_08048D72:
	movs r0, #1
_08048D74:
	pop {r1}
	bx r1

	thumb_func_start FUN_08048d78
FUN_08048d78: @ 0x08048D78
	push {lr}
	ldr r0, _08048D98 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x94
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #1
	beq _08048D9C
	cmp r0, #1
	bgt _08048D9C
	cmp r0, #0
	bne _08048D9C
	movs r0, #0x1b
	b _08048D9E
	.align 2, 0
_08048D98: .4byte 0x030046A0
_08048D9C:
	movs r0, #0x1c
_08048D9E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08048da4
FUN_08048da4: @ 0x08048DA4
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

	thumb_func_start FUN_08049488
FUN_08049488: @ 0x08049488
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	b _08049546
_08049490:
	adds r0, r6, #0
	adds r1, r5, #0
	bl FUN_08048da4
	adds r5, r0, #0
	ldrb r0, [r6, #0xe]
	cmp r0, #0
	bne _08049560
	ldrb r0, [r5]
	cmp r0, #0
	bne _08049544
	b _08049560
_080494A8:
	ldrb r0, [r5]
	cmp r0, #0xa
	bne _080494B6
	adds r0, r6, #0
	bl FUN_0804898c
	b _08049544
_080494B6:
	cmp r0, #0x1f
	bne _08049506
	adds r0, r5, #0
	bl FUN_08048afc
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldr r0, _080494DC @ =0x0000FFFF
	cmp r1, r0
	bne _080494E0
	ldrb r0, [r5]
	subs r0, #0x20
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_08048a20
	b _08049502
	.align 2, 0
_080494DC: .4byte 0x0000FFFF
_080494E0:
	movs r0, #0xff
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080494FC
	ldr r0, _080494F8 @ =0x00007FFF
	ands r1, r0
	adds r0, r6, #0
	bl FUN_08048a20
	b _08049502
	.align 2, 0
_080494F8: .4byte 0x00007FFF
_080494FC:
	adds r0, r6, #0
	bl FUN_08048a20
_08049502:
	adds r5, #2
	b _08049560
_08049506:
	ldrb r0, [r5]
	subs r0, #0x20
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_08048a20
_08049516:
	adds r5, #1
	b _08049560
_0804951A:
	ldrb r1, [r5]
	movs r0, #0x7f
	ands r0, r1
	adds r5, #1
	ldrb r1, [r5]
	lsls r4, r0, #8
	orrs r4, r1
	bl Video_GetZenkakuCharCount
	cmp r4, r0
	blo _0804953A
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08048998
	b _08049516
_0804953A:
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_08048a4c
	b _08049516
_08049544:
	adds r5, #1
_08049546:
	ldrb r0, [r5]
	lsls r0, r0, #0x18
	cmp r0, #0
	blt _0804951A
	lsrs r0, r0, #0x18
	cmp r0, #0
	beq _08049560
	cmp r0, #0x3c
	bne _080494A8
	adds r5, #1
	ldrb r0, [r5]
	cmp r0, #0
	bne _08049490
_08049560:
	adds r0, r5, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_08049568
FUN_08049568: @ 0x08049568
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0
	strb r0, [r4, #0xe]
	ldrb r0, [r4, #7]
	cmp r0, #1
	beq _080495A6
	cmp r0, #1
	bgt _08049580
	cmp r0, #0
	beq _0804958A
	b _08049604
_08049580:
	cmp r0, #2
	beq _080495BA
	cmp r0, #3
	beq _080495CE
	b _08049604
_0804958A:
	ldr r1, [r4, #0x1c]
	adds r0, r4, #0
	bl FUN_08049488
	adds r1, r0, #0
	str r1, [r4, #0x1c]
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	bne _08049600
	ldrb r0, [r4, #7]
	cmp r0, #0
	bne _08049604
	ldrb r0, [r1]
	b _080495FC
_080495A6:
	ldr r1, [r4, #0x20]
	adds r0, r4, #0
	bl FUN_08049488
	adds r1, r0, #0
	str r1, [r4, #0x20]
	ldrb r0, [r4, #7]
	cmp r0, #1
	bne _08049604
	b _080495E0
_080495BA:
	ldr r1, [r4, #0x24]
	adds r0, r4, #0
	bl FUN_08049488
	adds r1, r0, #0
	str r1, [r4, #0x24]
	ldrb r0, [r4, #7]
	cmp r0, #2
	bne _08049604
	b _080495E0
_080495CE:
	ldr r1, [r4, #0x28]
	adds r0, r4, #0
	bl FUN_08049488
	adds r1, r0, #0
	str r1, [r4, #0x28]
	ldrb r0, [r4, #7]
	cmp r0, #3
	bne _08049604
_080495E0:
	ldrb r0, [r1]
	cmp r0, #0
	bne _08049604
	adds r0, r4, #0
	bl FUN_08048964
	ldrb r0, [r4, #7]
	cmp r0, #0
	bne _08049604
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	bne _08049600
	ldr r0, [r4, #0x1c]
	ldrb r0, [r0]
_080495FC:
	cmp r0, #0
	bne _08049604
_08049600:
	movs r0, #1
	b _08049606
_08049604:
	movs r0, #0
_08049606:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0804960c
FUN_0804960c: @ 0x0804960C
	push {lr}
	ldrb r1, [r0, #7]
	cmp r1, #1
	beq _0804962C
	cmp r1, #1
	bgt _0804961E
	cmp r1, #0
	beq _08049628
	b _08049638
_0804961E:
	cmp r1, #2
	beq _08049630
	cmp r1, #3
	beq _08049634
	b _08049638
_08049628:
	ldr r0, [r0, #0x1c]
	b _0804963A
_0804962C:
	ldr r0, [r0, #0x20]
	b _0804963A
_08049630:
	ldr r0, [r0, #0x24]
	b _0804963A
_08049634:
	ldr r0, [r0, #0x28]
	b _0804963A
_08049638:
	movs r0, #0
_0804963A:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08049640
FUN_08049640: @ 0x08049640
	movs r1, #0
	strb r1, [r0, #6]
	movs r3, #0x82
	lsls r3, r3, #1
	adds r2, r0, r3
	strb r1, [r2]
	strb r1, [r0, #7]
	bx lr

	thumb_func_start FUN_08049650
FUN_08049650: @ 0x08049650
	push {r4, lr}
	ldr r4, [sp, #8]
	strb r1, [r0, #2]
	strb r2, [r0, #3]
	strb r3, [r0, #4]
	strb r4, [r0, #5]
	strb r1, [r0]
	strb r2, [r0, #1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08049668
FUN_08049668: @ 0x08049668
	movs r1, #0
	strb r1, [r0, #8]
	ldr r1, _08049678 @ =0x030046A0
	ldr r1, [r1]
	movs r2, #0x12
	ldrsh r1, [r1, r2]
	strb r1, [r0, #9]
	bx lr
	.align 2, 0
_08049678: .4byte 0x030046A0

	thumb_func_start FUN_0804967c
FUN_0804967c: @ 0x0804967C
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, [sp, #0xc]
	str r0, [sp]
	adds r0, r4, #0
	bl FUN_08049650
	adds r0, r4, #0
	bl FUN_08049640
	adds r0, r4, #0
	bl FUN_08049668
	movs r0, #0
	strb r0, [r4, #0xa]
	strb r0, [r4, #0xb]
	ldrb r1, [r4, #9]
	strb r1, [r4, #0xc]
	strb r0, [r4, #0x13]
	strb r0, [r4, #0xd]
	str r0, [r4, #0x1c]
	str r0, [r4, #0x20]
	str r0, [r4, #0x24]
	str r0, [r4, #0x28]
	movs r1, #0xff
	strb r1, [r4, #0x15]
	movs r1, #1
	strb r1, [r4, #0x14]
	str r0, [r4, #0x18]
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_080496c0
FUN_080496c0: @ 0x080496C0
	adds r3, r0, #0
	lsls r1, r1, #2
	adds r3, #0x84
	adds r3, r3, r1
	str r2, [r3]
	bx lr

	thumb_func_start FUN_080496cc
FUN_080496cc: @ 0x080496CC
	push {r4, lr}
	adds r3, r0, #0
	lsls r1, r1, #2
	movs r4, #0x86
	lsls r4, r4, #1
	adds r3, r3, r4
	adds r3, r3, r1
	str r2, [r3]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080496e4
FUN_080496e4: @ 0x080496E4
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	cmp r4, #0
	ble _08049700
	adds r5, r2, #0
	adds r2, r6, #0
	adds r2, #0xc4
	adds r3, r4, #0
_080496F6:
	ldm r5!, {r1}
	stm r2!, {r1}
	subs r3, #1
	cmp r3, #0
	bne _080496F6
_08049700:
	strb r4, [r6, #0xd]
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_08049708
FUN_08049708: @ 0x08049708
	push {lr}
	lsls r1, r1, #2
	adds r0, #0x84
	adds r0, r0, r1
	ldr r1, [r0]
	lsrs r2, r1, #0x1f
	adds r0, r1, #0
	cmp r1, #0
	bge _0804971C
	rsbs r0, r1, #0
_0804971C:
	adds r1, r0, #0
	ldr r0, _08049728 @ =0x0098967F
	cmp r1, r0
	ble _0804972C
	adds r2, #8
	b _0804977E
	.align 2, 0
_08049728: .4byte 0x0098967F
_0804972C:
	ldr r0, _08049738 @ =0x000F423F
	cmp r1, r0
	ble _0804973C
	adds r2, #7
	b _0804977E
	.align 2, 0
_08049738: .4byte 0x000F423F
_0804973C:
	ldr r0, _08049748 @ =0x0001869F
	cmp r1, r0
	ble _0804974C
	adds r2, #6
	b _0804977E
	.align 2, 0
_08049748: .4byte 0x0001869F
_0804974C:
	ldr r0, _08049758 @ =0x0000270F
	cmp r1, r0
	ble _0804975C
	adds r2, #5
	b _0804977E
	.align 2, 0
_08049758: .4byte 0x0000270F
_0804975C:
	ldr r0, _08049768 @ =0x000003E7
	cmp r1, r0
	ble _0804976C
	adds r2, #4
	b _0804977E
	.align 2, 0
_08049768: .4byte 0x000003E7
_0804976C:
	cmp r1, #0x63
	ble _08049774
	adds r2, #3
	b _0804977E
_08049774:
	cmp r1, #9
	ble _0804977C
	adds r2, #2
	b _0804977E
_0804977C:
	adds r2, #1
_0804977E:
	adds r0, r2, #0
	pop {r1}
	bx r1

	thumb_func_start FUN_08049784
FUN_08049784: @ 0x08049784
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	lsls r1, r1, #2
	movs r0, #0x86
	lsls r0, r0, #1
	add r0, r8
	adds r0, r0, r1
	ldr r5, [r0]
	movs r7, #0
	b _08049866
_0804979C:
	ldrb r0, [r5]
	cmp r0, #0x3c
	bne _08049834
	adds r5, #1
	ldrb r0, [r5]
	cmp r0, #0
	beq _08049878
	adds r4, r5, #0
	ldr r1, _080497D0 @ =0x08251CC4
	adds r0, r5, #0
	movs r2, #3
	bl TextBox_StrNCmp
	cmp r0, #0
	bne _08049824
	movs r6, #0
	movs r2, #0
	ldrb r0, [r5]
	mov r3, r8
	adds r3, #0x34
	cmp r0, #0x3e
	beq _080497F6
	cmp r0, #0
	bne _080497D4
	adds r4, r5, #1
	b _080497F6
	.align 2, 0
_080497D0: .4byte 0x08251CC4
_080497D4:
	ldrb r1, [r4]
	cmp r1, #0x3d
	bne _080497DE
	movs r6, #1
	b _080497E8
_080497DE:
	cmp r6, #0
	beq _080497E8
	adds r0, r3, r2
	strb r1, [r0]
	adds r2, #1
_080497E8:
	adds r4, #1
	ldrb r0, [r4]
	cmp r0, #0x3e
	beq _080497F6
	cmp r0, #0
	bne _080497D4
	adds r4, #1
_080497F6:
	adds r1, r3, r2
	movs r0, #0
	strb r0, [r1]
	cmp r6, #0
	beq _08049810
	cmp r2, #0
	beq _08049810
	adds r0, r3, #0
	adds r1, r2, #0
	bl TextBox_ParseDecimal
	adds r1, r0, #0
	b _08049812
_08049810:
	movs r1, #0
_08049812:
	mov r0, r8
	bl FUN_08049708
	adds r7, r7, r0
	adds r0, r4, #0
	movs r1, #0x3e
	bl TextBox_FindChar
	b _0804982C
_08049824:
	adds r0, r5, #0
	movs r1, #0x3e
	bl TextBox_FindChar
_0804982C:
	ldrb r0, [r5]
	cmp r0, #0
	beq _08049878
	b _08049866
_08049834:
	cmp r0, #0x1f
	bne _0804985C
	adds r0, r5, #0
	bl FUN_08048afc
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldr r0, _08049858 @ =0x0000FFFF
	cmp r1, r0
	beq _08049862
	movs r0, #0xff
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	bne _08049862
	adds r7, #1
	b _08049864
	.align 2, 0
_08049858: .4byte 0x0000FFFF
_0804985C:
	adds r7, #1
	adds r5, #1
	b _08049866
_08049862:
	adds r7, #2
_08049864:
	adds r5, #2
_08049866:
	ldrb r0, [r5]
	lsls r0, r0, #0x18
	cmp r0, #0
	blt _08049862
	lsrs r0, r0, #0x18
	cmp r0, #0
	beq _08049878
	cmp r0, #0xa
	bne _0804979C
_08049878:
	adds r0, r7, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08049884
FUN_08049884: @ 0x08049884
	movs r1, #0xa6
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r1, #0
	str r1, [r0]
	bx lr

	thumb_func_start FUN_08049890
FUN_08049890: @ 0x08049890
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r5, #0
	b _080498B4
_08049898:
	movs r1, #0xa8
	lsls r1, r1, #1
	adds r0, r4, r1
	adds r0, r0, r5
	ldrb r1, [r0]
	lsls r1, r1, #2
	adds r0, r4, #0
	adds r0, #0xc4
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0
	bl Script_ExecById
	adds r5, #1
_080498B4:
	movs r1, #0xa6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r5, r0
	blo _08049898
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080498c8
FUN_080498c8: @ 0x080498C8
	ldr r1, _080498D0 @ =0x030000C8
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_080498D0: .4byte 0x030000C8

	thumb_func_start FUN_080498d4
FUN_080498d4: @ 0x080498D4
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r4, #0x18
	movs r0, #0
	movs r1, #0x12
	movs r2, #0x20
	movs r3, #2
	bl FUN_0822ea60
	movs r0, #0
	movs r1, #0x12
	movs r2, #0x20
	movs r3, #2
	bl FUN_0822eadc
	movs r0, #2
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0x12
	movs r3, #0x20
	bl FUN_08049650
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0804990c
FUN_0804990c: @ 0x0804990C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x18
	cmp r1, #0
	beq _0804991C
	bl FUN_080498d4
_0804991C:
	movs r1, #0xc6
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #0
	str r1, [r0]
	movs r2, #0xc4
	lsls r2, r2, #1
	adds r0, r4, r2
	str r1, [r0]
	subs r2, #4
	adds r0, r4, r2
	str r1, [r0]
	subs r2, #9
	adds r0, r4, r2
	strb r1, [r0]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r4, r0
	movs r0, #0x1e
	strb r0, [r2]
	ldr r2, _08049968 @ =0x0000017D
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #0x13
	adds r0, r4, r2
	str r1, [r0]
	adds r2, #4
	adds r0, r4, r2
	ldr r0, [r0]
	str r0, [r5, #0x1c]
	strb r1, [r5, #7]
	adds r0, r5, #0
	bl FUN_08049640
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08049968: .4byte 0x0000017D

	thumb_func_start FUN_0804996c
FUN_0804996c: @ 0x0804996C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r5, r0, #0
	adds r7, r5, #0
	adds r7, #0x18
	movs r0, #0
	mov r8, r0
	ldr r1, _080499B4 @ =0x0000017B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080499D4
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	bne _080499CE
	ldr r0, _080499B8 @ =0x030044E0
	ldrh r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080499BC
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #4
	rsbs r2, r2, #0
	ands r1, r2
	adds r1, #4
	str r1, [r0]
	b _080499C8
	.align 2, 0
_080499B4: .4byte 0x0000017B
_080499B8: .4byte 0x030044E0
_080499BC:
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_080499C8:
	movs r0, #1
	mov r8, r0
	b _080499EA
_080499CE:
	subs r0, #1
	strb r0, [r1]
	b _080499EA
_080499D4:
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #8
	rsbs r2, r2, #0
	ands r1, r2
	adds r1, #8
	str r1, [r0]
	movs r2, #1
	mov r8, r2
_080499EA:
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #7
	ands r0, r1
	cmp r0, #0
	beq _080499FC
	b _08049C1A
_080499FC:
	ldr r2, _08049AE8 @ =0x0000017B
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _08049A1E
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r2, [r0]
	cmp r2, #0
	bne _08049A1E
	ldr r0, _08049AEC @ =0x0000017D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08049A1E
	strb r2, [r1]
_08049A1E:
	movs r1, #0xc8
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	cmp r0, #0
	bne _08049A70
	ldr r2, _08049AE8 @ =0x0000017B
	adds r6, r5, r2
	ldrb r0, [r6]
	cmp r0, #0
	bne _08049A70
	subs r1, #8
	adds r0, r5, r1
	ldr r0, [r0]
	cmp r0, #0x1f
	bne _08049A70
	adds r2, #9
	adds r4, r5, r2
	ldr r0, [r4]
	movs r1, #0xf
	ands r0, r1
	cmp r0, #8
	bne _08049A70
	adds r0, r7, #0
	bl FUN_0804960c
	cmp r0, #0
	beq _08049A70
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bge _08049A70
	ldr r0, [r4]
	subs r0, #8
	str r0, [r4]
	movs r0, #1
	strb r0, [r6]
	ldr r2, _08049AEC @ =0x0000017D
	adds r1, r5, r2
	strb r0, [r1]
_08049A70:
	ldr r1, _08049AEC @ =0x0000017D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08049A7C
	b _08049C1A
_08049A7C:
	mov r2, r8
	cmp r2, #0
	bne _08049A84
	b _08049C1A
_08049A84:
	movs r0, #0xc6
	lsls r0, r0, #1
	adds r4, r5, r0
	ldr r0, [r4]
	movs r1, #0x12
	movs r2, #1
	movs r3, #2
	bl FUN_0822ea60
	ldr r0, [r4]
	movs r1, #0x12
	movs r2, #1
	movs r3, #2
	bl FUN_0822eadc
	ldr r0, [r4]
	adds r0, #1
	str r0, [r4]
	adds r0, r7, #0
	bl FUN_0804960c
	adds r4, r0, #0
	cmp r4, #0
	bne _08049AB6
	b _08049BEA
_08049AB6:
	ldrb r0, [r4]
	cmp r0, #0x3c
	bne _08049AF0
	adds r0, r7, #0
	bl FUN_08049568
	ldrb r0, [r7, #0xe]
	cmp r0, #0
	beq _08049AF0
	adds r0, r7, #0
	bl FUN_0804960c
	adds r4, r0, #0
	ldrb r0, [r7, #7]
	cmp r0, #0
	bne _08049AB6
	ldrb r0, [r4]
	cmp r0, #0
	bne _08049AB6
	movs r2, #0xc8
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r0, #8
	str r0, [r1]
	b _08049AB6
	.align 2, 0
_08049AE8: .4byte 0x0000017B
_08049AEC: .4byte 0x0000017D
_08049AF0:
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0
	blt _08049B54
	adds r0, r5, #0
	adds r0, #0x18
	movs r1, #0xc4
	lsls r1, r1, #1
	adds r4, r5, r1
	ldr r1, [r4]
	movs r2, #2
	str r2, [sp]
	movs r2, #0x12
	movs r3, #1
	bl FUN_08049650
	ldr r0, [r4]
	adds r0, #1
	str r0, [r4]
	movs r2, #0xc8
	lsls r2, r2, #1
	adds r4, r5, r2
	ldr r0, [r4]
	cmp r0, #0
	ble _08049B44
	adds r0, r7, #0
	movs r1, #0
	bl FUN_08048a20
	ldr r0, [r4]
	subs r0, #1
	str r0, [r4]
	cmp r0, #0
	bgt _08049BEA
	movs r1, #0xca
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	str r0, [r7, #0x1c]
	movs r0, #0
	str r0, [r4]
	b _08049BEA
_08049B44:
	adds r0, r7, #0
	bl FUN_08049568
	cmp r0, #0
	beq _08049BEA
	movs r0, #8
	str r0, [r4]
	b _08049BEA
_08049B54:
	movs r2, #0xc4
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08049B76
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #0xf
	ands r0, r1
	cmp r0, #0
	beq _08049B86
	b _08049BEA
_08049B76:
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r0, [r0]
	movs r1, #0xf
	ands r0, r1
	cmp r0, #8
	bne _08049BEA
_08049B86:
	movs r0, #0xc8
	lsls r0, r0, #1
	adds r6, r5, r0
	ldr r0, [r6]
	cmp r0, #0
	ble _08049BBE
	adds r0, r7, #0
	movs r1, #0
	bl FUN_08048a20
	movs r1, #0xc4
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	adds r1, #1
	str r1, [r0]
	ldr r0, [r6]
	subs r0, #1
	str r0, [r6]
	cmp r0, #0
	bgt _08049BEA
	movs r2, #0xca
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r0, [r0]
	str r0, [r7, #0x1c]
	movs r0, #0
	b _08049BE8
_08049BBE:
	adds r0, r5, #0
	adds r0, #0x18
	movs r1, #0xc4
	lsls r1, r1, #1
	adds r4, r5, r1
	ldr r1, [r4]
	movs r2, #2
	str r2, [sp]
	movs r2, #0x12
	movs r3, #2
	bl FUN_08049650
	ldr r0, [r4]
	adds r0, #2
	str r0, [r4]
	adds r0, r7, #0
	bl FUN_08049568
	cmp r0, #0
	beq _08049BEA
	movs r0, #8
_08049BE8:
	str r0, [r6]
_08049BEA:
	movs r2, #0xc4
	lsls r2, r2, #1
	adds r1, r5, r2
	ldr r0, [r1]
	cmp r0, #0x1f
	ble _08049C0A
	ldr r0, _08049C38 @ =0x0000017B
	adds r2, r5, r0
	ldrb r0, [r2]
	cmp r0, #0
	bne _08049C04
	movs r0, #1
	strb r0, [r2]
_08049C04:
	ldr r0, [r1]
	subs r0, #0x20
	str r0, [r1]
_08049C0A:
	movs r2, #0xc6
	lsls r2, r2, #1
	adds r1, r5, r2
	ldr r0, [r1]
	cmp r0, #0x1f
	ble _08049C1A
	subs r0, #0x20
	str r0, [r1]
_08049C1A:
	ldr r1, _08049C38 @ =0x0000017B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08049C2A
	adds r0, r5, #0
	bl FUN_0804996c
_08049C2A:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08049C38: .4byte 0x0000017B

	thumb_func_start FUN_08049c3c
FUN_08049c3c: @ 0x08049C3C
	push {r4, lr}
	adds r1, r0, #0
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r4, r1, r0
	ldrb r2, [r4]
	cmp r2, #0
	bne _08049C6C
	movs r3, #0xc2
	lsls r3, r3, #1
	adds r0, r1, r3
	str r2, [r0]
	adds r0, r1, #0
	movs r1, #1
	bl FUN_0804990c
	ldr r1, _08049C68 @ =0x03003520
	movs r0, #1
	str r0, [r1]
	strb r0, [r4]
	movs r0, #0
	b _08049C70
	.align 2, 0
_08049C68: .4byte 0x03003520
_08049C6C:
	movs r0, #1
	rsbs r0, r0, #0
_08049C70:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08049c78
FUN_08049c78: @ 0x08049C78
	push {r4, lr}
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r4, r0, r1
	ldrb r0, [r4]
	cmp r0, #0
	beq _08049C98
	bl FUN_08049e5c
	ldr r1, _08049C94 @ =0x03003520
	movs r0, #0
	str r0, [r1]
	strb r0, [r4]
	b _08049C9C
	.align 2, 0
_08049C94: .4byte 0x03003520
_08049C98:
	movs r0, #1
	rsbs r0, r0, #0
_08049C9C:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start EntityDFC6_Update
EntityDFC6_Update: @ 0x08049CA4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _08049D04 @ =0x00000179
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	beq _08049CBC
	adds r0, r4, #0
	bl FUN_08049c3c
	movs r0, #0
	strb r0, [r5]
_08049CBC:
	movs r1, #0xbd
	lsls r1, r1, #1
	adds r5, r4, r1
	ldrb r0, [r5]
	cmp r0, #0
	beq _08049CD2
	adds r0, r4, #0
	bl FUN_08049c78
	movs r0, #0
	strb r0, [r5]
_08049CD2:
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _08049D26
	adds r5, r4, #0
	adds r5, #0x18
	adds r0, r5, #0
	bl FUN_08049884
	adds r0, r4, #0
	bl FUN_0804996c
	ldr r1, _08049D08 @ =0x0000017B
	adds r0, r4, r1
	ldrb r1, [r0]
	cmp r1, #0
	beq _08049D10
	ldr r0, _08049D0C @ =0x03002CE8
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r1, r4, r2
	ldr r1, [r1]
	b _08049D12
	.align 2, 0
_08049D04: .4byte 0x00000179
_08049D08: .4byte 0x0000017B
_08049D0C: .4byte 0x03002CE8
_08049D10:
	ldr r0, _08049D30 @ =0x03002CE8
_08049D12:
	str r1, [r0]
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	adds r0, r5, #0
	bl FUN_08049890
_08049D26:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08049D30: .4byte 0x03002CE8

	thumb_func_start EntityDFC6_Destroy
EntityDFC6_Destroy: @ 0x08049D34
	push {lr}
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08049D46
	movs r0, #0
	strb r0, [r1]
_08049D46:
	ldr r0, _08049D58 @ =0x03002CE8
	movs r1, #0
	str r1, [r0]
	ldr r0, _08049D5C @ =0x030000C8
	str r1, [r0]
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_08049D58: .4byte 0x03002CE8
_08049D5C: .4byte 0x030000C8

	thumb_func_start EntityDFC6_Init
EntityDFC6_Init: @ 0x08049D60
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	ldr r0, _08049DD8 @ =0x030000C8
	str r6, [r0]
	adds r5, r6, #0
	adds r5, #0x18
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r4, #0
	strb r4, [r0]
	adds r1, #1
	adds r0, r6, r1
	strb r4, [r0]
	adds r1, #1
	adds r0, r6, r1
	strb r4, [r0]
	adds r1, #6
	adds r0, r6, r1
	str r4, [r0]
	adds r1, #0xc
	adds r0, r6, r1
	str r4, [r0]
	subs r1, #4
	adds r0, r6, r1
	str r4, [r0]
	movs r0, #2
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0x12
	movs r3, #2
	bl FUN_0804967c
	strb r4, [r5, #0x14]
	movs r0, #0xca
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _08049DDC @ =0x085AB548
	str r0, [r1]
	str r0, [r5, #0x1c]
	adds r0, r6, #0
	movs r1, #0
	bl FUN_0804990c
	strb r4, [r5, #0x11]
	movs r0, #1
	strb r0, [r5, #0xa]
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r6, r1
	str r4, [r0]
	ldr r0, _08049DE0 @ =0x03002CE8
	str r4, [r0]
	movs r0, #0
	add sp, #4
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08049DD8: .4byte 0x030000C8
_08049DDC: .4byte 0x085AB548
_08049DE0: .4byte 0x03002CE8

	thumb_func_start EntityDFC6_Create
EntityDFC6_Create: @ 0x08049DE4
	push {r4, lr}
	ldr r0, _08049E1C @ =0x030000C8
	ldr r0, [r0]
	cmp r0, #0
	bne _08049E2A
	movs r1, #0xcc
	lsls r1, r1, #1
	movs r0, #3
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08049E28
	ldr r1, _08049E20 @ =EntityDFC6_Update
	ldr r2, _08049E24 @ =EntityDFC6_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl EntityDFC6_Init
	cmp r0, #0
	bge _08049E28
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08049E2A
	.align 2, 0
_08049E1C: .4byte 0x030000C8
_08049E20: .4byte EntityDFC6_Update
_08049E24: .4byte EntityDFC6_Destroy
_08049E28:
	adds r0, r4, #0
_08049E2A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08049e30
FUN_08049e30: @ 0x08049E30
	push {lr}
	adds r2, r0, #0
	ldr r0, _08049E50 @ =0x030000C8
	ldr r1, [r0]
	cmp r1, #0
	beq _08049E54
	movs r3, #0xca
	lsls r3, r3, #1
	adds r0, r1, r3
	str r2, [r0]
	adds r0, r1, #0
	movs r1, #1
	bl FUN_0804990c
	movs r0, #0
	b _08049E58
	.align 2, 0
_08049E50: .4byte 0x030000C8
_08049E54:
	movs r0, #1
	rsbs r0, r0, #0
_08049E58:
	pop {r1}
	bx r1

	thumb_func_start FUN_08049e5c
FUN_08049e5c: @ 0x08049E5C
	push {lr}
	ldr r0, _08049E68 @ =0x085AB548
	bl FUN_08049e30
	pop {r1}
	bx r1
	.align 2, 0
_08049E68: .4byte 0x085AB548

	thumb_func_start FUN_08049e6c
FUN_08049e6c: @ 0x08049E6C
	push {lr}
	adds r3, r0, #0
	adds r2, r1, #0
	ldr r0, _08049E88 @ =0x030000C8
	ldr r0, [r0]
	cmp r0, #0
	beq _08049E8C
	adds r0, #0x18
	adds r1, r3, #0
	bl FUN_080496c0
	movs r0, #0
	b _08049E90
	.align 2, 0
_08049E88: .4byte 0x030000C8
_08049E8C:
	movs r0, #1
	rsbs r0, r0, #0
_08049E90:
	pop {r1}
	bx r1

	thumb_func_start FUN_08049e94
FUN_08049e94: @ 0x08049E94
	push {r4, lr}
	bl Script_GetValue
	adds r4, r0, #0
	bl Script_GetValue
	adds r1, r0, #0
	adds r0, r4, #0
	bl FUN_08049e6c
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08049eb0
FUN_08049eb0: @ 0x08049EB0
	push {lr}
	adds r3, r0, #0
	adds r2, r1, #0
	ldr r0, _08049EC4 @ =0x030000C8
	ldr r0, [r0]
	cmp r0, #0
	bne _08049EC8
	movs r0, #1
	rsbs r0, r0, #0
	b _08049ED0
	.align 2, 0
_08049EC4: .4byte 0x030000C8
_08049EC8:
	adds r0, #0x18
	adds r1, r3, #0
	bl FUN_080496cc
_08049ED0:
	pop {r1}
	bx r1

	thumb_func_start FUN_08049ed4
FUN_08049ed4: @ 0x08049ED4
	push {r4, lr}
	bl Script_GetValue
	adds r4, r0, #0
	bl FUN_0823d340
	adds r1, r0, #0
	adds r0, r4, #0
	bl FUN_08049eb0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08049ef0
FUN_08049ef0: @ 0x08049EF0
	push {r4, lr}
	bl Script_GetValue
	adds r4, r0, #0
	bl FUN_0823d34c
	adds r1, r0, #0
	adds r0, r4, #0
	bl FUN_08049eb0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08049f0c
FUN_08049f0c: @ 0x08049F0C
	push {r4, lr}
	ldr r0, _08049F2C @ =0x030000C8
	ldr r0, [r0]
	cmp r0, #0
	beq _08049F52
	adds r4, r0, #0
	adds r4, #0x18
	movs r0, #0
	strb r0, [r4, #0xd]
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08049F52
	b _08049F46
	.align 2, 0
_08049F2C: .4byte 0x030000C8
_08049F30:
	bl Script_GetValue
	ldrb r2, [r4, #0xd]
	lsls r2, r2, #2
	adds r1, r4, #0
	adds r1, #0xc4
	adds r1, r1, r2
	str r0, [r1]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_08049F46:
	bl VM_GetPC
	cmp r0, #0
	bne _08049F30
	movs r0, #0
	b _08049F56
_08049F52:
	movs r0, #1
	rsbs r0, r0, #0
_08049F56:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08049f5c
FUN_08049f5c: @ 0x08049F5C
	push {lr}
	ldr r0, _08049F74 @ =0x030000C8
	ldr r0, [r0]
	cmp r0, #0
	beq _08049F7C
	ldr r2, _08049F78 @ =0x00000179
	adds r1, r0, r2
	movs r0, #1
	strb r0, [r1]
	movs r0, #0
	b _08049F80
	.align 2, 0
_08049F74: .4byte 0x030000C8
_08049F78: .4byte 0x00000179
_08049F7C:
	movs r0, #1
	rsbs r0, r0, #0
_08049F80:
	pop {r1}
	bx r1

	thumb_func_start FUN_08049f84
FUN_08049f84: @ 0x08049F84
	push {lr}
	ldr r0, _08049F9C @ =0x030000C8
	ldr r0, [r0]
	cmp r0, #0
	beq _08049FA0
	movs r2, #0xbd
	lsls r2, r2, #1
	adds r1, r0, r2
	movs r0, #1
	strb r0, [r1]
	movs r0, #0
	b _08049FA4
	.align 2, 0
_08049F9C: .4byte 0x030000C8
_08049FA0:
	movs r0, #1
	rsbs r0, r0, #0
_08049FA4:
	pop {r1}
	bx r1

	thumb_func_start FUN_08049fa8
FUN_08049fa8: @ 0x08049FA8
	push {lr}
	ldr r0, _08049FBC @ =0x030000C8
	ldr r0, [r0]
	cmp r0, #0
	beq _08049FC0
	bl FUN_08049c78
	movs r0, #0
	b _08049FC4
	.align 2, 0
_08049FBC: .4byte 0x030000C8
_08049FC0:
	movs r0, #1
	rsbs r0, r0, #0
_08049FC4:
	pop {r1}
	bx r1
