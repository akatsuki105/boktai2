	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	ldr r0, _0822DEC0 @ =0x03002CF0
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	ldr r1, _0822DEC4 @ =0x00000401
	str r1, [sp]
	cmp r0, #0
	beq _0822DE84
	ldr r2, _0822DEC8 @ =0x00000201
	str r2, [sp]
_0822DE84:
	ldr r1, _0822DECC @ =0x03003570
	ldr r0, _0822DED0 @ =0x03003530
	ldr r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r4, [r0]
	cmp r4, #0
	bne _0822DE96
	b _0822E0F2
_0822DE96:
	ldr r3, _0822DED4 @ =0x03003E40
	mov sl, r3
_0822DE9A:
	ldr r1, [r4]
	adds r0, r1, #0
	ldr r5, [sp]
	ands r0, r5
	adds r7, r1, #0
	cmp r0, #0
	beq _0822DEAA
	b _0822E0EA
_0822DEAA:
	movs r6, #0x18
	ldrsh r1, [r4, r6]
	ldr r2, _0822DED8 @ =0x03003540
	movs r3, #0
	ldrsh r0, [r2, r3]
	subs r0, r1, r0
	adds r5, r2, #0
	cmp r0, #0
	blt _0822DEDC
	asrs r0, r0, #3
	b _0822DEE2
	.align 2, 0
_0822DEC0: .4byte 0x03002CF0
_0822DEC4: .4byte 0x00000401
_0822DEC8: .4byte 0x00000201
_0822DECC: .4byte 0x03003570
_0822DED0: .4byte 0x03003530
_0822DED4: .4byte 0x03003E40
_0822DED8: .4byte 0x03003540
_0822DEDC:
	rsbs r0, r0, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_0822DEE2:
	adds r3, r0, #0
	adds r3, #0x78
	movs r6, #0x1a
	ldrsh r1, [r4, r6]
	movs r2, #2
	ldrsh r0, [r5, r2]
	subs r0, r1, r0
	cmp r0, #0
	blt _0822DEF8
	asrs r0, r0, #3
	b _0822DEFE
_0822DEF8:
	rsbs r0, r0, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_0822DEFE:
	adds r2, r0, #0
	adds r2, #0x5a
	movs r6, #0x1c
	ldrsh r0, [r4, r6]
	movs r6, #4
	ldrsh r1, [r5, r6]
	subs r0, r0, r1
	mov sb, r0
	movs r0, #0x40
	ands r0, r7
	movs r1, #0xc
	ldrsb r1, [r4, r1]
	mov ip, r1
	movs r5, #0xd
	ldrsb r5, [r4, r5]
	mov r8, r5
	cmp r0, #0
	bne _0822DF4C
	ldrb r5, [r4, #0xa]
	ldrb r6, [r4, #0xb]
	str r6, [sp, #4]
	adds r0, r3, r1
	mov r6, r8
	adds r1, r2, r6
	cmp r0, #0xf0
	ble _0822DF34
	b _0822E0EA
_0822DF34:
	cmp r1, #0xb4
	ble _0822DF3A
	b _0822E0EA
_0822DF3A:
	adds r0, r0, r5
	cmp r0, #0
	bge _0822DF42
	b _0822E0EA
_0822DF42:
	ldr r5, [sp, #4]
	adds r0, r1, r5
	cmp r0, #0
	bge _0822DF4C
	b _0822E0EA
_0822DF4C:
	add r3, ip
	add r2, r8
	mov r6, sb
	ldr r0, _0822DF84 @ =0x000001FF
	ands r3, r0
	lsls r0, r3, #0x10
	ldr r5, [r4, #0x14]
	orrs r5, r0
	movs r0, #0xff
	ands r2, r0
	orrs r5, r2
	movs r0, #2
	ands r0, r7
	cmp r0, #0
	beq _0822DFCE
	ldrb r0, [r4, #5]
	cmp r0, #0x3c
	bgt _0822DF7C
	ldrb r0, [r4, #6]
	cmp r0, #0x3c
	bgt _0822DF7C
	ldrb r0, [r4, #7]
	cmp r0, #0
	beq _0822DF88
_0822DF7C:
	movs r0, #0xc0
	lsls r0, r0, #2
	b _0822DF8C
	.align 2, 0
_0822DF84: .4byte 0x000001FF
_0822DF88:
	movs r0, #0x80
	lsls r0, r0, #1
_0822DF8C:
	orrs r5, r0
	ldrb r1, [r4, #7]
	movs r2, #5
	ldrsb r2, [r4, r2]
	movs r3, #6
	ldrsb r3, [r4, r3]
	mov r7, sl
	ldr r0, [r7]
	cmp r0, #0x1f
	ble _0822DFA4
	movs r1, #0
	b _0822DFC8
_0822DFA4:
	lsls r0, r0, #2
	ldr r7, _0822E070 @ =0x030035B0
	adds r0, r0, r7
	strb r1, [r0]
	mov r1, sl
	ldr r0, [r1]
	lsls r0, r0, #2
	adds r0, r0, r7
	strb r2, [r0, #1]
	ldr r0, [r1]
	lsls r0, r0, #2
	adds r0, r0, r7
	strb r3, [r0, #2]
	ldr r0, [r1]
	adds r1, r0, #0
	adds r0, #1
	mov r2, sl
	str r0, [r2]
_0822DFC8:
	lsls r0, r1, #0x19
	orrs r5, r0
	ldr r7, [r4]
_0822DFCE:
	movs r0, #4
	ands r0, r7
	cmp r0, #0
	beq _0822DFDC
	movs r0, #0x80
	lsls r0, r0, #0x15
	orrs r5, r0
_0822DFDC:
	movs r0, #8
	ands r0, r7
	cmp r0, #0
	beq _0822DFEA
	movs r0, #0x80
	lsls r0, r0, #0x16
	orrs r5, r0
_0822DFEA:
	ldr r3, _0822E074 @ =0x030044AC
	ldr r0, [r3]
	cmp r0, #0
	beq _0822E002
	movs r0, #0x80
	lsls r0, r0, #7
	ands r0, r7
	cmp r0, #0
	beq _0822E002
	movs r0, #0x80
	lsls r0, r0, #3
	orrs r5, r0
_0822E002:
	ldr r0, _0822E078 @ =0x030044B0
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0822E01E
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	beq _0822E01E
	movs r0, #0x80
	lsls r0, r0, #9
	ands r0, r7
	cmp r0, #0
	beq _0822E028
_0822E01E:
	movs r0, #0x80
	lsls r0, r0, #4
	ands r0, r7
	cmp r0, #0
	beq _0822E02E
_0822E028:
	movs r0, #0x80
	lsls r0, r0, #5
	orrs r5, r0
_0822E02E:
	movs r0, #0x10
	ldrsb r0, [r4, r0]
	adds r6, r6, r0
	movs r0, #0x20
	ands r0, r7
	cmp r0, #0
	beq _0822E088
	movs r1, #8
	ldrsh r2, [r4, r1]
	ldrb r0, [r4, #0xf]
	lsls r0, r0, #0xa
	orrs r2, r0
	ldrb r0, [r4, #0xe]
	lsls r0, r0, #0xc
	orrs r2, r0
	ldr r3, _0822E07C @ =0x03003A38
	ldr r1, [r3]
	cmp r1, #0x7f
	bgt _0822E0EA
	lsls r0, r1, #3
	ldr r6, _0822E080 @ =0x03003630
	adds r0, r0, r6
	str r5, [r0]
	strh r2, [r0, #4]
	adds r0, r1, #1
	str r0, [r3]
	ldr r7, _0822E084 @ =0x03002CA4
	ldr r0, [r7]
	movs r1, #1
	orrs r0, r1
	str r0, [r7]
	b _0822E0EA
	.align 2, 0
_0822E070: .4byte 0x030035B0
_0822E074: .4byte 0x030044AC
_0822E078: .4byte 0x030044B0
_0822E07C: .4byte 0x03003A38
_0822E080: .4byte 0x03003630
_0822E084: .4byte 0x03002CA4
_0822E088:
	cmp r6, #0
	blt _0822E090
	asrs r0, r6, #1
	b _0822E096
_0822E090:
	rsbs r0, r6, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_0822E096:
	adds r6, r0, #0
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r6, r0
	bge _0822E0A4
	adds r6, r0, #0
	b _0822E0AA
_0822E0A4:
	cmp r6, #0x7f
	ble _0822E0AA
	movs r6, #0x7f
_0822E0AA:
	movs r0, #8
	ldrsh r1, [r4, r0]
	ldrb r7, [r4, #0xf]
	lsls r0, r7, #0xa
	orrs r1, r0
	ldrb r0, [r4, #0xe]
	lsls r0, r0, #0xc
	orrs r1, r0
	ldr r2, _0822E104 @ =0x03003A3C
	ldr r3, [r2]
	cmp r3, #0x7f
	bgt _0822E0EA
	lsls r2, r3, #3
	ldr r0, _0822E108 @ =0x03003A40
	adds r2, r2, r0
	str r5, [r2]
	strh r1, [r2, #4]
	adds r0, r6, #0
	adds r0, #0x80
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r2, #6]
	adds r0, r3, #1
	ldr r1, _0822E104 @ =0x03003A3C
	str r0, [r1]
	lsls r1, r7, #1
	ldr r2, _0822E10C @ =0x03003A30
	adds r1, r1, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_0822E0EA:
	ldr r4, [r4, #0x24]
	cmp r4, #0
	beq _0822E0F2
	b _0822DE9A
_0822E0F2:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0822E104: .4byte 0x03003A3C
_0822E108: .4byte 0x03003A40
_0822E10C: .4byte 0x03003A30
