	push {r4, r5, r6, lr}
	sub sp, #0x14
	adds r5, r0, #0
	movs r0, #1
	movs r1, #0xe3
	lsls r1, r1, #2
	adds r6, r5, r1
	ldr r1, [r6]
	ands r0, r1
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r6]
	cmp r0, #0
	beq _0821FF7A
	movs r2, #0xed
	lsls r2, r2, #2
	adds r1, r5, r2
	adds r0, r5, #0
	adds r0, #0x4d
	ldrb r0, [r0]
	str r0, [r1]
	movs r4, #0
	str r4, [sp]
	str r4, [sp, #4]
	adds r0, r5, #0
	movs r1, #0xe
	movs r2, #1
	movs r3, #1
	bl FUN_0821c400
	movs r3, #0xf6
	lsls r3, r3, #2
	adds r0, r5, r3
	strb r4, [r0]
_0821FF7A:
	movs r4, #0xe8
	lsls r4, r4, #2
	adds r0, r5, r4
	ldr r0, [r0]
	cmp r0, #1
	bne _0821FF88
	b _08220174
_0821FF88:
	cmp r0, #1
	bgt _0821FF92
	cmp r0, #0
	beq _0821FF9A
	b _082201E0
_0821FF92:
	cmp r0, #0x63
	bne _0821FF98
	b _082201A4
_0821FF98:
	b _082201E0
_0821FF9A:
	ldr r0, [r6]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	movs r1, #0xb4
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #7
	bne _0821FFC2
	movs r2, #0xb2
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #1
	bne _0821FFC2
	ldr r0, _0821FFFC @ =0x0000035E
	bl PlaySound_082406e0
_0821FFC2:
	movs r3, #0xe9
	lsls r3, r3, #2
	adds r0, r5, r3
	ldr r1, [r0]
	adds r0, r1, #0
	subs r0, #0x1f
	cmp r0, #0x12
	bls _0821FFDA
	subs r0, #0x1e
	cmp r0, #0x12
	bls _0821FFDA
	b _0822012A
_0821FFDA:
	cmp r1, #0x1f
	bne _0822001A
	movs r0, #0x20
	movs r4, #0xe3
	lsls r4, r4, #2
	adds r2, r5, r4
	ldr r1, [r2]
	ands r0, r1
	cmp r0, #0
	bne _08220004
	ldr r0, _08220000 @ =0x00000809
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _0822000C
	.align 2, 0
_0821FFFC: .4byte 0x0000035E
_08220000: .4byte 0x00000809
_08220004:
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r2]
_0822000C:
	ldr r2, _08220074 @ =0x000003DB
	adds r1, r5, r2
	movs r0, #0
	strb r0, [r1]
	movs r0, #0xea
	bl PlaySound_082406e0
_0822001A:
	movs r3, #0xe9
	lsls r3, r3, #2
	adds r0, r5, r3
	ldr r0, [r0]
	movs r1, #6
	bl Mod
	cmp r0, #0
	beq _0822002E
	b _0822012A
_0822002E:
	add r2, sp, #0xc
	ldr r0, [r5, #0x50]
	ldr r1, [r5, #0x54]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	ldrh r0, [r2, #2]
	adds r0, #0xf0
	strh r0, [r2, #2]
	movs r4, #0xf6
	lsls r4, r4, #2
	adds r0, r5, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bgt _08220084
	ldr r2, _08220078 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0822007C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08220080 @ =0x0203B400
	adds r0, r0, r1
	ldrh r2, [r0]
	adds r0, r5, #0
	adds r0, #0x4d
	ldrb r0, [r0]
	subs r0, #2
	movs r1, #4
	ands r2, r1
	subs r2, r0, r2
	b _082200A6
	.align 2, 0
_08220074: .4byte 0x000003DB
_08220078: .4byte 0x030046B8
_0822007C: .4byte 0x000003FF
_08220080: .4byte 0x0203B400
_08220084:
	ldr r2, _082200D0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _082200D4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _082200D8 @ =0x0203B400
	adds r0, r0, r2
	ldrh r2, [r0]
	adds r0, r5, #0
	adds r0, #0x4d
	ldrb r0, [r0]
	adds r0, #2
	movs r1, #4
	ands r2, r1
	adds r2, r0, r2
_082200A6:
	movs r3, #0xe2
	lsls r3, r3, #2
	adds r0, r5, r3
	ldrb r0, [r0]
	movs r3, #0x1e
	cmp r0, #0
	bne _082200B6
	movs r3, #0x14
_082200B6:
	movs r4, #0xf6
	lsls r4, r4, #2
	adds r0, r5, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #5
	bhi _08220100
	lsls r0, r0, #2
	ldr r1, _082200DC @ =_082200E0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_082200D0: .4byte 0x030046B8
_082200D4: .4byte 0x000003FF
_082200D8: .4byte 0x0203B400
_082200DC: .4byte _082200E0
_082200E0: @ jump table
	.4byte _08220100 @ case 0
	.4byte _082200F8 @ case 1
	.4byte _082200FC @ case 2
	.4byte _08220100 @ case 3
	.4byte _082200F8 @ case 4
	.4byte _082200FC @ case 5
_082200F8:
	subs r2, #0xd
	b _082200FE
_082200FC:
	adds r2, #0xd
_082200FE:
	adds r3, #4
_08220100:
	ldr r1, _08220168 @ =0x00000BF8
	adds r0, r5, r1
	ldr r0, [r0]
	ldr r4, _0822016C @ =0x000003D2
	adds r1, r5, r4
	movs r4, #0
	ldrsh r1, [r1, r4]
	str r1, [sp]
	movs r1, #0x1e
	str r1, [sp, #4]
	movs r1, #8
	str r1, [sp, #8]
	add r1, sp, #0xc
	bl FUN_0805e6bc
	movs r0, #0xf6
	lsls r0, r0, #2
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0822012A:
	movs r1, #0xe9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	cmp r0, #0x78
	ble _082201E0
	ldr r2, _08220170 @ =0x000002D9
	adds r0, r5, r2
	ldrb r1, [r0]
	movs r2, #2
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _082201E0
	movs r1, #1
	movs r3, #0xe8
	lsls r3, r3, #2
	adds r0, r5, r3
	str r1, [r0]
	movs r4, #0xe9
	lsls r4, r4, #2
	adds r1, r5, r4
	movs r0, #0
	str r0, [r1]
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _082201E0
	.align 2, 0
_08220168: .4byte 0x00000BF8
_0822016C: .4byte 0x000003D2
_08220170: .4byte 0x000002D9
_08220174:
	ldr r0, [r6]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	movs r1, #0xe9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	cmp r0, #0x1f
	ble _082201E0
	movs r1, #0x63
	movs r2, #0xe8
	lsls r2, r2, #2
	adds r0, r5, r2
	str r1, [r0]
	movs r3, #0xe9
	lsls r3, r3, #2
	adds r1, r5, r3
	movs r0, #0
	str r0, [r1]
	ldr r0, [r6]
	movs r1, #2
	b _082201DC
_082201A4:
	movs r4, #2
	ldr r0, [r6]
	adds r2, r0, #0
	ands r2, r4
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	cmp r2, #0
	beq _082201CA
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	adds r0, r5, #0
	movs r1, #0x17
	movs r2, #1
	movs r3, #1
	bl FUN_0821c400
_082201CA:
	ldr r1, _082201E8 @ =0x000002D9
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _082201E0
	movs r1, #0x10
	ldr r0, [r6]
_082201DC:
	orrs r0, r1
	str r0, [r6]
_082201E0:
	add sp, #0x14
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_082201E8: .4byte 0x000002D9
