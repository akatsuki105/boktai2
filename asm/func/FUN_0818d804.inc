	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	mov sl, r0
	ldr r2, _0818D830 @ =0x0000046C
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0818D834
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0818D836
	.align 2, 0
_0818D830: .4byte 0x0000046C
_0818D834:
	movs r0, #0
_0818D836:
	cmp r0, #0
	beq _0818D8F4
	movs r4, #0xd3
	lsls r4, r4, #4
	add r4, sl
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [r4]
	str r1, [r4, #4]
	ldr r2, _0818D94C @ =0x00000D38
	add r2, sl
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r3, _0818D950 @ =0x0203B400
	mov r8, r3
	ldr r3, _0818D954 @ =0x030046B8
	ldr r1, [r3]
	adds r1, #1
	ldr r5, _0818D958 @ =0x000003FF
	ands r1, r5
	str r1, [r3]
	lsls r0, r1, #1
	add r0, r8
	ldrh r2, [r0]
	ldrh r0, [r4]
	subs r0, #0x40
	movs r5, #0x7f
	ands r2, r5
	adds r0, r0, r2
	movs r2, #0
	mov sb, r2
	movs r2, #0
	mov ip, r2
	strh r0, [r4]
	adds r1, #1
	ldr r0, _0818D958 @ =0x000003FF
	ands r1, r0
	str r1, [r3]
	lsls r1, r1, #1
	add r1, r8
	ldrh r1, [r1]
	ldr r2, _0818D95C @ =0x00000D34
	add r2, sl
	ldrh r0, [r2]
	subs r0, #0x40
	ands r1, r5
	adds r0, r0, r1
	strh r0, [r2]
	ldrb r1, [r7, #5]
	ldr r0, _0818D960 @ =0x00000D42
	add r0, sl
	strb r1, [r0]
	movs r1, #0xd4
	lsls r1, r1, #4
	add r1, sl
	movs r0, #0x3c
	strh r0, [r1]
	ldr r3, _0818D964 @ =FUN_0818a604
	movs r2, #0x27
	ldr r5, _0818D968 @ =0x0000046D
	adds r1, r7, r5
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0818D96C @ =0x0000046B
	adds r0, r7, r1
	mov r5, sb
	strb r5, [r0]
	adds r1, #0xe8
	adds r0, r7, r1
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r7, r2
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	mov r5, ip
	strh r5, [r0]
	ldr r4, _0818D970 @ =0x00000F2C
	add r4, sl
	movs r0, #0x41
	rsbs r0, r0, #0
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
	ldr r0, _0818D974 @ =0x000003E5
	bl sound_08240740
	ldr r0, _0818D978 @ =0xFFFF7FFF
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
_0818D8F4:
	movs r0, #0xd3
	lsls r0, r0, #4
	add r0, sl
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r2, #8
	ldrsh r1, [r7, r2]
	subs r0, r0, r1
	movs r4, #0xd4
	lsls r4, r4, #4
	add r4, sl
	ldrh r1, [r4]
	bl Div
	ldrh r1, [r7, #0x10]
	adds r1, r1, r0
	strh r1, [r7, #0x10]
	ldr r0, _0818D95C @ =0x00000D34
	add r0, sl
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r5, #0xc
	ldrsh r1, [r7, r5]
	subs r0, r0, r1
	ldrh r1, [r4]
	bl Div
	ldrh r1, [r7, #0x14]
	adds r1, r1, r0
	strh r1, [r7, #0x14]
	movs r1, #0x10
	ldrsh r0, [r7, r1]
	movs r2, #0x14
	ldrsh r1, [r7, r2]
	bl ArcTan2_8
	adds r2, r0, #0
	ldrb r0, [r7, #5]
	subs r1, r2, r0
	cmp r1, #0x80
	ble _0818D980
	ldr r3, _0818D97C @ =0xFFFFFF00
	adds r1, r1, r3
	b _0818D98E
	.align 2, 0
_0818D94C: .4byte 0x00000D38
_0818D950: .4byte 0x0203B400
_0818D954: .4byte 0x030046B8
_0818D958: .4byte 0x000003FF
_0818D95C: .4byte 0x00000D34
_0818D960: .4byte 0x00000D42
_0818D964: .4byte FUN_0818a604
_0818D968: .4byte 0x0000046D
_0818D96C: .4byte 0x0000046B
_0818D970: .4byte 0x00000F2C
_0818D974: .4byte 0x000003E5
_0818D978: .4byte 0xFFFF7FFF
_0818D97C: .4byte 0xFFFFFF00
_0818D980:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0818D98E
	movs r5, #0x80
	lsls r5, r5, #1
	adds r1, r1, r5
_0818D98E:
	adds r0, r1, #0
	cmp r1, #0
	bge _0818D996
	rsbs r0, r1, #0
_0818D996:
	cmp r0, #0x1f
	bgt _0818D99E
	strb r2, [r7, #5]
	b _0818D9AE
_0818D99E:
	cmp r1, #0
	bge _0818D9A8
	ldrb r0, [r7, #5]
	subs r0, #4
	b _0818D9AC
_0818D9A8:
	ldrb r0, [r7, #5]
	adds r0, #4
_0818D9AC:
	strb r0, [r7, #5]
_0818D9AE:
	movs r6, #0xd4
	lsls r6, r6, #4
	add r6, sl
	ldrh r0, [r6]
	subs r0, #1
	strh r0, [r6]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0818DA2A
	movs r3, #0xd3
	lsls r3, r3, #4
	add r3, sl
	ldr r0, _0818DAD8 @ =0x00000D38
	add r0, sl
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r3]
	str r1, [r3, #4]
	ldr r0, _0818DADC @ =0x0203B400
	mov sb, r0
	ldr r4, _0818DAE0 @ =0x030046B8
	ldr r1, [r4]
	adds r1, #1
	ldr r2, _0818DAE4 @ =0x000003FF
	ands r1, r2
	str r1, [r4]
	lsls r0, r1, #1
	add r0, sb
	ldrh r2, [r0]
	ldrh r0, [r3]
	subs r0, #0x40
	movs r5, #0x7f
	mov r8, r5
	mov r5, r8
	ands r2, r5
	adds r0, r0, r2
	strh r0, [r3]
	adds r1, #1
	ldr r0, _0818DAE4 @ =0x000003FF
	ands r1, r0
	str r1, [r4]
	lsls r0, r1, #1
	add r0, sb
	ldrh r2, [r0]
	ldr r3, _0818DAE8 @ =0x00000D34
	add r3, sl
	ldrh r0, [r3]
	subs r0, #0x40
	ands r2, r5
	adds r0, r0, r2
	strh r0, [r3]
	adds r1, #1
	ldr r2, _0818DAE4 @ =0x000003FF
	ands r1, r2
	str r1, [r4]
	lsls r1, r1, #1
	add r1, sb
	ldrh r0, [r1]
	movs r1, #0x3f
	ands r0, r1
	adds r0, #0x1e
	strh r0, [r6]
_0818DA2A:
	ldr r3, _0818DAEC @ =0x00000484
	adds r2, r7, r3
	ldr r1, [r2]
	movs r0, #0x96
	lsls r0, r0, #1
	cmp r1, r0
	bgt _0818DA3A
	b _0818DCF8
_0818DA3A:
	ldr r5, _0818DAF0 @ =0x00000546
	adds r0, r7, r5
	ldrh r1, [r0]
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r0, r7, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r1, r0
	bge _0818DA50
	b _0818DBAC
_0818DA50:
	ldr r2, _0818DAE0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0818DAE4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r5, _0818DADC @ =0x0203B400
	adds r0, r0, r5
	ldrb r0, [r0]
	cmp r0, #0x2f
	ble _0818DA6A
	b _0818DB7C
_0818DA6A:
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r7, r0
	ldr r1, _0818DAF4 @ =0xFFEFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	adds r0, r7, #0
	bl FUN_0818e6fc
	mov r2, sp
	adds r4, r7, #0
	adds r4, #8
	ldr r1, _0818DAF8 @ =0x000004A4
	adds r0, r7, r1
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0xc
	ldrh r0, [r0, #0xc]
	ldrh r1, [r7, #8]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r5, #4
	ldrsh r1, [r2, r5]
	bl ArcTan2_8
	movs r2, #0xee
	lsls r2, r2, #1
	adds r1, r7, r2
	strb r0, [r1]
	ldr r0, _0818DAFC @ =0x00000D4F
	add r0, sl
	movs r3, #0
	strb r3, [r0]
	ldrb r1, [r1]
	ldrb r0, [r7, #5]
	subs r1, r1, r0
	cmp r1, #0x80
	ble _0818DB04
	ldr r5, _0818DB00 @ =0xFFFFFF00
	adds r1, r1, r5
	b _0818DB12
	.align 2, 0
_0818DAD8: .4byte 0x00000D38
_0818DADC: .4byte 0x0203B400
_0818DAE0: .4byte 0x030046B8
_0818DAE4: .4byte 0x000003FF
_0818DAE8: .4byte 0x00000D34
_0818DAEC: .4byte 0x00000484
_0818DAF0: .4byte 0x00000546
_0818DAF4: .4byte 0xFFEFFFFF
_0818DAF8: .4byte 0x000004A4
_0818DAFC: .4byte 0x00000D4F
_0818DB00: .4byte 0xFFFFFF00
_0818DB04:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0818DB12
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r1, r0
_0818DB12:
	cmp r1, #0
	bge _0818DB18
	rsbs r1, r1, #0
_0818DB18:
	cmp r1, #0x20
	ble _0818DB4C
	movs r2, #1
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _0818DB44 @ =0x00000469
	adds r0, r7, r3
	strb r1, [r0]
	ldr r5, _0818DB48 @ =0x0000046A
	adds r0, r7, r5
	strb r2, [r0]
	adds r3, #0x1b
	adds r0, r7, r3
	str r1, [r0]
	adds r5, #2
	adds r0, r7, r5
	strb r2, [r0]
	b _0818DCFC
	.align 2, 0
_0818DB44: .4byte 0x00000469
_0818DB48: .4byte 0x0000046A
_0818DB4C:
	movs r2, #2
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _0818DB70 @ =0x00000469
	adds r0, r7, r3
	strb r1, [r0]
	ldr r5, _0818DB74 @ =0x0000046A
	adds r0, r7, r5
	strb r2, [r0]
	ldr r2, _0818DB78 @ =0x00000484
	adds r0, r7, r2
	str r1, [r0]
	adds r3, #3
	adds r1, r7, r3
	b _0818DCE4
	.align 2, 0
_0818DB70: .4byte 0x00000469
_0818DB74: .4byte 0x0000046A
_0818DB78: .4byte 0x00000484
_0818DB7C:
	movs r1, #0x11
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r0, r7, r5
	movs r2, #0
	strb r2, [r0]
	ldr r3, _0818DBA4 @ =0x00000469
	adds r0, r7, r3
	strb r2, [r0]
	adds r5, #2
	adds r0, r7, r5
	strb r1, [r0]
	ldr r1, _0818DBA8 @ =0x00000484
	adds r0, r7, r1
	movs r2, #0
	str r2, [r0]
	adds r3, #3
	adds r1, r7, r3
	b _0818DCE4
	.align 2, 0
_0818DBA4: .4byte 0x00000469
_0818DBA8: .4byte 0x00000484
_0818DBAC:
	ldr r2, _0818DC38 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0818DC3C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r5, _0818DC40 @ =0x0203B400
	adds r0, r0, r5
	ldrb r0, [r0]
	cmp r0, #0xc1
	ble _0818DBC6
	b _0818DCC0
_0818DBC6:
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r7, r0
	ldr r1, _0818DC44 @ =0xFFEFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	adds r0, r7, #0
	bl FUN_0818e6fc
	add r2, sp, #8
	adds r4, r7, #0
	adds r4, #8
	ldr r1, _0818DC48 @ =0x000004A4
	adds r0, r7, r1
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0xc
	ldrh r0, [r0, #0xc]
	ldrh r1, [r7, #8]
	subs r0, r0, r1
	strh r0, [r2]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	movs r3, #0
	ldrsh r0, [r2, r3]
	movs r5, #4
	ldrsh r1, [r2, r5]
	bl ArcTan2_8
	movs r2, #0xee
	lsls r2, r2, #1
	adds r1, r7, r2
	strb r0, [r1]
	ldr r0, _0818DC4C @ =0x00000D4F
	add r0, sl
	movs r3, #0
	strb r3, [r0]
	movs r0, #0xed
	lsls r0, r0, #4
	add r0, sl
	movs r5, #0
	strh r5, [r0]
	ldrb r1, [r1]
	ldrb r0, [r7, #5]
	subs r1, r1, r0
	cmp r1, #0x80
	ble _0818DC54
	ldr r0, _0818DC50 @ =0xFFFFFF00
	adds r1, r1, r0
	b _0818DC62
	.align 2, 0
_0818DC38: .4byte 0x030046B8
_0818DC3C: .4byte 0x000003FF
_0818DC40: .4byte 0x0203B400
_0818DC44: .4byte 0xFFEFFFFF
_0818DC48: .4byte 0x000004A4
_0818DC4C: .4byte 0x00000D4F
_0818DC50: .4byte 0xFFFFFF00
_0818DC54:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0818DC62
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
_0818DC62:
	cmp r1, #0
	bge _0818DC68
	rsbs r1, r1, #0
_0818DC68:
	cmp r1, #0x20
	ble _0818DC9C
	movs r2, #1
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r7, r3
	movs r1, #0
	strb r1, [r0]
	ldr r5, _0818DC94 @ =0x00000469
	adds r0, r7, r5
	strb r1, [r0]
	adds r3, #2
	adds r0, r7, r3
	strb r2, [r0]
	adds r5, #0x1b
	adds r0, r7, r5
	str r1, [r0]
	ldr r1, _0818DC98 @ =0x0000046C
	adds r0, r7, r1
	strb r2, [r0]
	b _0818DCFC
	.align 2, 0
_0818DC94: .4byte 0x00000469
_0818DC98: .4byte 0x0000046C
_0818DC9C:
	movs r2, #2
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r7, r3
	movs r1, #0
	strb r1, [r0]
	ldr r5, _0818DCBC @ =0x00000469
	adds r0, r7, r5
	strb r1, [r0]
	adds r3, #2
	adds r0, r7, r3
	strb r2, [r0]
	adds r5, #0x1b
	adds r0, r7, r5
	str r1, [r0]
	b _0818DCE0
	.align 2, 0
_0818DCBC: .4byte 0x00000469
_0818DCC0:
	movs r1, #0x11
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r7, r2
	movs r3, #0
	strb r3, [r0]
	ldr r5, _0818DCEC @ =0x00000469
	adds r0, r7, r5
	strb r3, [r0]
	adds r2, #2
	adds r0, r7, r2
	strb r1, [r0]
	ldr r3, _0818DCF0 @ =0x00000484
	adds r0, r7, r3
	movs r5, #0
	str r5, [r0]
_0818DCE0:
	ldr r0, _0818DCF4 @ =0x0000046C
	adds r1, r7, r0
_0818DCE4:
	movs r0, #1
	strb r0, [r1]
	b _0818DCFC
	.align 2, 0
_0818DCEC: .4byte 0x00000469
_0818DCF0: .4byte 0x00000484
_0818DCF4: .4byte 0x0000046C
_0818DCF8:
	adds r0, r1, #1
	str r0, [r2]
_0818DCFC:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
