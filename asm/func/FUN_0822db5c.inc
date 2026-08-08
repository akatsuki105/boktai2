	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	ldr r0, _0822DBCC @ =0x03002CF0
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	ldr r1, _0822DBD0 @ =0x00000401
	str r1, [sp, #8]
	cmp r0, #0
	beq _0822DB7C
	ldr r2, _0822DBD4 @ =0x00000201
	str r2, [sp, #8]
_0822DB7C:
	ldr r1, _0822DBD8 @ =0x03003570
	ldr r0, _0822DBDC @ =0x03003530
	ldr r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r4, [r0]
	cmp r4, #0
	bne _0822DB8E
	b _0822DE46
_0822DB8E:
	ldr r3, _0822DBE0 @ =0x03003E40
	mov sl, r3
_0822DB92:
	ldr r1, [r4]
	adds r0, r1, #0
	ldr r5, [sp, #8]
	ands r0, r5
	cmp r0, #0
	beq _0822DBA0
	b _0822DE3E
_0822DBA0:
	movs r0, #0x10
	ands r1, r0
	cmp r1, #0
	bne _0822DC50
	mov r5, sp
	adds r6, r4, #0
	adds r6, #0x18
	ldrh r0, [r4, #0x18]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0822DBE4
	asrs r0, r0, #8
	b _0822DBEA
	.align 2, 0
_0822DBCC: .4byte 0x03002CF0
_0822DBD0: .4byte 0x00000401
_0822DBD4: .4byte 0x00000201
_0822DBD8: .4byte 0x03003570
_0822DBDC: .4byte 0x03003530
_0822DBE0: .4byte 0x03003E40
_0822DBE4:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0822DBEA:
	strh r0, [r5]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0822DBFC
	asrs r0, r0, #8
	b _0822DC02
_0822DBFC:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0822DC02:
	adds r3, r0, #0
	movs r7, #2
	ldrsh r1, [r6, r7]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0822DC16
	asrs r0, r0, #8
	b _0822DC1C
_0822DC16:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0822DC1C:
	subs r2, r3, r0
	adds r3, r3, r0
	ldrh r0, [r5]
	ldr r6, _0822DC4C @ =0x030047C8
	ldrh r1, [r6]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r5]
	ldrh r0, [r6, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r5, #2]
	ldrh r0, [r6, #4]
	subs r3, r3, r0
	strh r3, [r5, #4]
	mov r0, sp
	movs r7, #0
	ldrsh r2, [r0, r7]
	movs r1, #2
	ldrsh r3, [r0, r1]
	movs r6, #4
	ldrsh r5, [r0, r6]
	mov sb, r5
	b _0822DC5E
	.align 2, 0
_0822DC4C: .4byte 0x030047C8
_0822DC50:
	movs r7, #0x18
	ldrsh r2, [r4, r7]
	movs r0, #0x1a
	ldrsh r3, [r4, r0]
	movs r5, #0x1c
	ldrsh r1, [r4, r5]
	mov sb, r1
_0822DC5E:
	ldr r1, [r4]
	movs r0, #0x40
	ands r0, r1
	adds r6, r1, #0
	movs r7, #0xc
	ldrsb r7, [r4, r7]
	mov ip, r7
	movs r1, #0xd
	ldrsb r1, [r4, r1]
	mov r8, r1
	cmp r0, #0
	bne _0822DCA2
	ldrb r5, [r4, #0xa]
	ldrb r7, [r4, #0xb]
	str r7, [sp, #0xc]
	mov r1, ip
	adds r0, r2, r1
	mov r7, r8
	adds r1, r3, r7
	cmp r0, #0xf0
	ble _0822DC8A
	b _0822DE3E
_0822DC8A:
	cmp r1, #0xb4
	ble _0822DC90
	b _0822DE3E
_0822DC90:
	adds r0, r0, r5
	cmp r0, #0
	bge _0822DC98
	b _0822DE3E
_0822DC98:
	ldr r5, [sp, #0xc]
	adds r0, r1, r5
	cmp r0, #0
	bge _0822DCA2
	b _0822DE3E
_0822DCA2:
	add r2, ip
	add r3, r8
	mov r7, sb
	ldr r0, _0822DCD8 @ =0x000001FF
	ands r2, r0
	lsls r0, r2, #0x10
	ldr r5, [r4, #0x14]
	orrs r5, r0
	movs r0, #0xff
	ands r3, r0
	orrs r5, r3
	movs r0, #2
	ands r0, r6
	cmp r0, #0
	beq _0822DD22
	ldrb r0, [r4, #5]
	cmp r0, #0x3c
	bgt _0822DCD2
	ldrb r0, [r4, #6]
	cmp r0, #0x3c
	bgt _0822DCD2
	ldrb r0, [r4, #7]
	cmp r0, #0
	beq _0822DCDC
_0822DCD2:
	movs r0, #0xc0
	lsls r0, r0, #2
	b _0822DCE0
	.align 2, 0
_0822DCD8: .4byte 0x000001FF
_0822DCDC:
	movs r0, #0x80
	lsls r0, r0, #1
_0822DCE0:
	orrs r5, r0
	ldrb r1, [r4, #7]
	movs r2, #5
	ldrsb r2, [r4, r2]
	movs r3, #6
	ldrsb r3, [r4, r3]
	mov r6, sl
	ldr r0, [r6]
	cmp r0, #0x1f
	ble _0822DCF8
	movs r1, #0
	b _0822DD1C
_0822DCF8:
	lsls r0, r0, #2
	ldr r6, _0822DDC4 @ =0x030035B0
	adds r0, r0, r6
	strb r1, [r0]
	mov r1, sl
	ldr r0, [r1]
	lsls r0, r0, #2
	adds r0, r0, r6
	strb r2, [r0, #1]
	ldr r0, [r1]
	lsls r0, r0, #2
	adds r0, r0, r6
	strb r3, [r0, #2]
	ldr r0, [r1]
	adds r1, r0, #0
	adds r0, #1
	mov r2, sl
	str r0, [r2]
_0822DD1C:
	lsls r0, r1, #0x19
	orrs r5, r0
	ldr r6, [r4]
_0822DD22:
	movs r0, #4
	ands r0, r6
	cmp r0, #0
	beq _0822DD30
	movs r0, #0x80
	lsls r0, r0, #0x15
	orrs r5, r0
_0822DD30:
	movs r0, #8
	ands r0, r6
	cmp r0, #0
	beq _0822DD3E
	movs r0, #0x80
	lsls r0, r0, #0x16
	orrs r5, r0
_0822DD3E:
	ldr r3, _0822DDC8 @ =0x030044AC
	ldr r0, [r3]
	cmp r0, #0
	beq _0822DD56
	movs r0, #0x80
	lsls r0, r0, #7
	ands r0, r6
	cmp r0, #0
	beq _0822DD56
	movs r0, #0x80
	lsls r0, r0, #3
	orrs r5, r0
_0822DD56:
	ldr r0, _0822DDCC @ =0x030044B0
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0822DD72
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	beq _0822DD72
	movs r0, #0x80
	lsls r0, r0, #9
	ands r0, r6
	cmp r0, #0
	beq _0822DD7C
_0822DD72:
	movs r0, #0x80
	lsls r0, r0, #4
	ands r0, r6
	cmp r0, #0
	beq _0822DD82
_0822DD7C:
	movs r0, #0x80
	lsls r0, r0, #5
	orrs r5, r0
_0822DD82:
	movs r0, #0x10
	ldrsb r0, [r4, r0]
	adds r7, r7, r0
	movs r0, #0x20
	ands r0, r6
	cmp r0, #0
	beq _0822DDDC
	movs r1, #8
	ldrsh r2, [r4, r1]
	ldrb r0, [r4, #0xf]
	lsls r0, r0, #0xa
	orrs r2, r0
	ldrb r0, [r4, #0xe]
	lsls r0, r0, #0xc
	orrs r2, r0
	ldr r3, _0822DDD0 @ =0x03003A38
	ldr r1, [r3]
	cmp r1, #0x7f
	bgt _0822DE3E
	lsls r0, r1, #3
	ldr r6, _0822DDD4 @ =0x03003630
	adds r0, r0, r6
	str r5, [r0]
	strh r2, [r0, #4]
	adds r0, r1, #1
	str r0, [r3]
	ldr r7, _0822DDD8 @ =0x03002CA4
	ldr r0, [r7]
	movs r1, #1
	orrs r0, r1
	str r0, [r7]
	b _0822DE3E
	.align 2, 0
_0822DDC4: .4byte 0x030035B0
_0822DDC8: .4byte 0x030044AC
_0822DDCC: .4byte 0x030044B0
_0822DDD0: .4byte 0x03003A38
_0822DDD4: .4byte 0x03003630
_0822DDD8: .4byte 0x03002CA4
_0822DDDC:
	cmp r7, #0
	blt _0822DDE4
	asrs r0, r7, #1
	b _0822DDEA
_0822DDE4:
	rsbs r0, r7, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_0822DDEA:
	adds r7, r0, #0
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r7, r0
	bge _0822DDF8
	adds r7, r0, #0
	b _0822DDFE
_0822DDF8:
	cmp r7, #0x7f
	ble _0822DDFE
	movs r7, #0x7f
_0822DDFE:
	movs r0, #8
	ldrsh r1, [r4, r0]
	ldrb r6, [r4, #0xf]
	lsls r0, r6, #0xa
	orrs r1, r0
	ldrb r0, [r4, #0xe]
	lsls r0, r0, #0xc
	orrs r1, r0
	ldr r2, _0822DE58 @ =0x03003A3C
	ldr r3, [r2]
	cmp r3, #0x7f
	bgt _0822DE3E
	lsls r2, r3, #3
	ldr r0, _0822DE5C @ =0x03003A40
	adds r2, r2, r0
	str r5, [r2]
	strh r1, [r2, #4]
	adds r0, r7, #0
	adds r0, #0x80
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r2, #6]
	adds r0, r3, #1
	ldr r1, _0822DE58 @ =0x03003A3C
	str r0, [r1]
	lsls r1, r6, #1
	ldr r2, _0822DE60 @ =0x03003A30
	adds r1, r1, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_0822DE3E:
	ldr r4, [r4, #0x24]
	cmp r4, #0
	beq _0822DE46
	b _0822DB92
_0822DE46:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0822DE58: .4byte 0x03003A3C
_0822DE5C: .4byte 0x03003A40
_0822DE60: .4byte 0x03003A30
