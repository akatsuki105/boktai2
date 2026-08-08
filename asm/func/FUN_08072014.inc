	push {r4, r5, r6, lr}
	sub sp, #0x38
	adds r5, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #3
	beq _08072030
	adds r0, r5, #0
	movs r1, #3
	movs r2, #0
	bl FUN_08060b84
_08072030:
	ldr r2, _08072048 @ =0x0000037D
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #8
	bls _0807203C
	b _080725EE
_0807203C:
	lsls r0, r0, #2
	ldr r1, _0807204C @ =_08072050
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08072048: .4byte 0x0000037D
_0807204C: .4byte _08072050
_08072050: @ jump table
	.4byte _08072074 @ case 0
	.4byte _080720A8 @ case 1
	.4byte _08072168 @ case 2
	.4byte _08072214 @ case 3
	.4byte _080722A0 @ case 4
	.4byte _0807232C @ case 5
	.4byte _08072388 @ case 6
	.4byte _08072404 @ case 7
	.4byte _08072440 @ case 8
_08072074:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x23
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	bne _08072092
	b _080725EE
_08072092:
	movs r2, #0xa9
	lsls r2, r2, #4
	adds r1, r5, r2
	movs r0, #0x1e
	strh r0, [r1]
	adds r0, r5, #0
	movs r1, #3
	movs r2, #1
	bl FUN_08060b84
	b _080725EE
_080720A8:
	ldr r0, _08072100 @ =0x0000037E
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _080720B8
	ldr r0, _08072104 @ =0x000001F7
	bl PlaySound_082406e0
_080720B8:
	adds r0, r5, #0
	bl FUN_0806f738
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x24
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #6
	bhi _080720E6
	b _080725EE
_080720E6:
	ldr r2, _08072108 @ =0x00000A8F
	adds r1, r5, r2
	movs r0, #0
	strb r0, [r1]
	movs r1, #0xda
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #4
	bhi _0807210C
	movs r0, #0xd5
	b _080721AC
	.align 2, 0
_08072100: .4byte 0x0000037E
_08072104: .4byte 0x000001F7
_08072108: .4byte 0x00000A8F
_0807210C:
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _08072134
	ldr r0, _08072130 @ =0x00000203
	bl PlaySound_082406e0
	adds r0, r5, #0
	movs r1, #3
	movs r2, #5
	bl FUN_08060b84
	b _0807213E
	.align 2, 0
_08072130: .4byte 0x00000203
_08072134:
	adds r0, r5, #0
	movs r1, #3
	movs r2, #2
	bl FUN_08060b84
_0807213E:
	movs r1, #0x20
	str r1, [sp]
	movs r0, #0x32
	str r0, [sp, #4]
	str r1, [sp, #8]
	movs r0, #2
	str r0, [sp, #0xc]
	movs r0, #0x14
	str r0, [sp, #0x10]
	movs r0, #5
	str r0, [sp, #0x14]
	str r0, [sp, #0x18]
	movs r0, #0
	str r0, [sp, #0x1c]
	adds r0, r5, #0
	movs r1, #0xe6
	movs r2, #0xaa
	movs r3, #0
	bl FUN_08080be8
	b _080725EE
_08072168:
	adds r0, r5, #0
	bl FUN_0806f738
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x24
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r2, _080721BC @ =0x0000037E
	adds r4, r5, r2
	ldrh r0, [r4]
	cmp r0, #6
	bne _08072198
	movs r0, #0xfc
	lsls r0, r0, #1
	bl PlaySound_082406e0
_08072198:
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080721C4
	ldr r0, _080721C0 @ =0x00000203
_080721AC:
	bl PlaySound_082406e0
	adds r0, r5, #0
	movs r1, #3
	movs r2, #5
	bl FUN_08060b84
	b _080725EE
	.align 2, 0
_080721BC: .4byte 0x0000037E
_080721C0: .4byte 0x00000203
_080721C4:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	movs r2, #0xa9
	lsls r2, r2, #4
	adds r1, r5, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r1]
	cmp r0, r1
	bhs _080721DC
	b _080725EE
_080721DC:
	ldr r0, _0807220C @ =0x00000A8F
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldr r2, _08072210 @ =0x0000095E
	adds r1, r5, r2
	movs r0, #0x91
	lsls r0, r0, #1
	strh r0, [r1]
	movs r0, #0x96
	lsls r0, r0, #4
	adds r1, r5, r0
	movs r0, #0x24
	strh r0, [r1]
	movs r0, #0xfc
	lsls r0, r0, #1
	bl PlaySound_082406e0
	adds r0, r5, #0
	movs r1, #3
	movs r2, #3
	bl FUN_08060b84
	b _080725EE
	.align 2, 0
_0807220C: .4byte 0x00000A8F
_08072210: .4byte 0x0000095E
_08072214:
	adds r0, r5, #0
	bl FUN_0806f738
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x24
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r4, #2
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _080722D4
	ldr r1, _08072290 @ =0x0000037E
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	movs r2, #0xa9
	lsls r2, r2, #4
	adds r0, r5, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldrh r0, [r0]
	cmp r1, r0
	bhs _08072262
	b _080725EE
_08072262:
	ldr r0, _08072294 @ =0x00000A8F
	adds r1, r5, r0
	movs r0, #2
	strb r0, [r1]
	ldr r2, _08072298 @ =0x0000095E
	adds r1, r5, r2
	movs r0, #0x91
	lsls r0, r0, #1
	strh r0, [r1]
	movs r0, #0x96
	lsls r0, r0, #4
	adds r1, r5, r0
	movs r0, #0x24
	strh r0, [r1]
	ldr r0, _0807229C @ =0x000001F9
	bl PlaySound_082406e0
	adds r0, r5, #0
	movs r1, #3
	movs r2, #4
	bl FUN_08060b84
	b _080725EE
	.align 2, 0
_08072290: .4byte 0x0000037E
_08072294: .4byte 0x00000A8F
_08072298: .4byte 0x0000095E
_0807229C: .4byte 0x000001F9
_080722A0:
	adds r0, r5, #0
	bl FUN_0806f738
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x24
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r4, #2
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _080722D4
	b _080725EE
_080722D4:
	ldr r0, _08072320 @ =0x000002E9
	bl PlaySound_082406e0
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r1, [r0]
	movs r0, #8
	subs r0, r0, r1
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #5
	ldr r2, _08072324 @ =0x00000A8A
	adds r1, r5, r2
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_0806f900
	adds r1, r0, #0
	movs r2, #0xa1
	lsls r2, r2, #4
	adds r0, r5, r2
	str r4, [sp]
	movs r2, #0x14
	str r2, [sp, #4]
	movs r2, #0x20
	movs r3, #0x10
	bl FUN_082364f8
	ldr r0, _08072328 @ =0x00000202
	bl PlaySound_082406e0
	adds r0, r5, #0
	movs r1, #3
	movs r2, #8
	bl FUN_08060b84
	b _080725EE
	.align 2, 0
_08072320: .4byte 0x000002E9
_08072324: .4byte 0x00000A8A
_08072328: .4byte 0x00000202
_0807232C:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x25
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0807235E
	ldr r0, _08072380 @ =0x00000A76
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_0807235E:
	ldr r2, _08072384 @ =0x0000037E
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bhi _08072372
	b _080725EE
_08072372:
	adds r0, r5, #0
	movs r1, #3
	movs r2, #6
	bl FUN_08060b84
	b _080725EE
	.align 2, 0
_08072380: .4byte 0x00000A76
_08072384: .4byte 0x0000037E
_08072388:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x24
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080723BA
	ldr r0, _080723D4 @ =0x00000A76
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_080723BA:
	ldr r1, _080723D4 @ =0x00000A76
	adds r2, r5, r1
	ldrb r0, [r2]
	cmp r0, #0
	beq _080723DC
	movs r0, #0
	strb r0, [r2]
	ldr r2, _080723D8 @ =0x0000037D
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
	b _080725EE
	.align 2, 0
_080723D4: .4byte 0x00000A76
_080723D8: .4byte 0x0000037D
_080723DC:
	ldr r0, _08072400 @ =0x0000037E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xe
	bhi _080723F0
	b _080725EE
_080723F0:
	movs r0, #0
	strb r0, [r2]
	adds r0, r5, #0
	movs r1, #3
	movs r2, #7
	bl FUN_08060b84
	b _080725EE
	.align 2, 0
_08072400: .4byte 0x0000037E
_08072404:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x23
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r2, _0807243C @ =0x0000037E
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bhi _08072430
	b _080725EE
_08072430:
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
	b _080725EE
	.align 2, 0
_0807243C: .4byte 0x0000037E
_08072440:
	ldr r1, _080724E8 @ =0x000003D1
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	adds r0, r5, #0
	bl FUN_0806f738
	cmp r0, #0
	beq _0807245A
	adds r0, r5, #0
	movs r1, #6
	bl FUN_08060aa4
_0807245A:
	ldr r2, _080724EC @ =0x0000037E
	adds r0, r5, r2
	ldrh r0, [r0]
	movs r3, #3
	ands r3, r0
	adds r6, r5, #0
	adds r6, #0x2c
	cmp r3, #0
	bne _080724A0
	ldr r1, _080724F0 @ =0xFFFF0000
	ldr r2, _080724F4 @ =0x0000FFFF
	str r3, [sp, #0x20]
	ldr r0, [sp, #0x24]
	ands r0, r1
	str r0, [sp, #0x24]
	ldr r0, [sp, #0x28]
	ands r0, r1
	movs r3, #0x20
	orrs r0, r3
	ands r0, r2
	str r0, [sp, #0x28]
	add r2, sp, #0x28
	ldr r0, [r2, #4]
	ands r0, r1
	orrs r0, r3
	str r0, [r2, #4]
	movs r0, #2
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r6, #0
	add r1, sp, #0x20
	movs r3, #1
	bl FUN_080dbcec
_080724A0:
	ldr r0, _080724F8 @ =0x00000A8A
	adds r4, r5, r0
	ldrh r0, [r4]
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	strh r0, [r4]
	ldrh r1, [r4]
	adds r0, r5, #0
	adds r2, r6, #0
	bl FUN_08061b48
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp, #0x30]
	str r1, [sp, #0x34]
	ldrh r1, [r4]
	movs r0, #0xd0
	lsls r0, r0, #1
	subs r6, r0, r1
	movs r1, #0xff
	ands r6, r1
	ldr r2, _080724FC @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0xaa
	muls r0, r1, r0
	cmp r0, #0
	blt _08072500
	asrs r1, r0, #0xc
	b _08072506
	.align 2, 0
_080724E8: .4byte 0x000003D1
_080724EC: .4byte 0x0000037E
_080724F0: .4byte 0xFFFF0000
_080724F4: .4byte 0x0000FFFF
_080724F8: .4byte 0x00000A8A
_080724FC: .4byte 0x085B0A08
_08072500:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08072506:
	add r3, sp, #0x30
	ldrh r0, [r3]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _0807253C @ =0xFFFF0000
	ldr r2, [sp, #0x30]
	ands r2, r1
	orrs r2, r0
	asrs r1, r2, #0x10
	adds r1, #0xe6
	lsls r1, r1, #0x10
	ldr r0, _08072540 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x30]
	ldr r1, _08072544 @ =0x085B0A08
	lsls r0, r6, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0xaa
	muls r0, r1, r0
	cmp r0, #0
	blt _08072548
	asrs r0, r0, #0xc
	b _0807254E
	.align 2, 0
_0807253C: .4byte 0xFFFF0000
_08072540: .4byte 0x0000FFFF
_08072544: .4byte 0x085B0A08
_08072548:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0807254E:
	ldrh r1, [r3, #4]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08072600 @ =0xFFFF0000
	ldr r0, [r3, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [r3, #4]
	movs r0, #0xa1
	lsls r0, r0, #4
	adds r4, r5, r0
	adds r0, r4, #0
	adds r1, r3, #0
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _08072604 @ =0x00000A52
	adds r0, r5, r1
	strb r6, [r0]
	adds r0, r4, #0
	bl FUN_08236400
	ldr r2, _08072608 @ =0x00000A8A
	adds r0, r5, r2
	ldrh r1, [r0]
	ldr r0, _0807260C @ =0x0000010F
	subs r0, r0, r1
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r5, r2
	strb r0, [r1]
	adds r0, r5, #0
	bl FUN_080609dc
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x25
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r2, _08072610 @ =0x0000037E
	adds r4, r5, r2
	ldrh r1, [r4]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	bne _080725C8
	movs r0, #0x81
	lsls r0, r0, #2
	bl PlaySound_082406e0
_080725C8:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, _08072614 @ =0x00000A8F
	adds r1, r5, r2
	ldrb r1, [r1]
	lsls r1, r1, #5
	cmp r0, r1
	blt _080725EE
	ldr r0, _08072618 @ =0x00000202
	bl sound_08240740
	adds r0, r5, #0
	movs r1, #3
	movs r2, #6
	bl FUN_08060b84
_080725EE:
	ldr r0, _0807261C @ =0x00000951
	adds r1, r5, r0
	movs r0, #9
	strb r0, [r1]
	add sp, #0x38
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08072600: .4byte 0xFFFF0000
_08072604: .4byte 0x00000A52
_08072608: .4byte 0x00000A8A
_0807260C: .4byte 0x0000010F
_08072610: .4byte 0x0000037E
_08072614: .4byte 0x00000A8F
_08072618: .4byte 0x00000202
_0807261C: .4byte 0x00000951
