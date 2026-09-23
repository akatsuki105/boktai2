	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r7, r0, #0
	adds r6, r1, #0
	adds r0, r6, #0
	adds r0, #0x68
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080203DA
	cmp r1, #0
	blt _080203DA
	ldr r0, _080203E0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080203DA
	ldr r0, _080203E4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080203E8
_080203DA:
	movs r1, #0
	b _080203F6
	.align 2, 0
_080203E0: .4byte 0x030046A8
_080203E4: .4byte 0x030046AC
_080203E8:
	ldr r0, _0802040C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_080203F6:
	adds r0, r6, #0
	adds r0, #0x38
	ldrb r2, [r0]
	mov sb, r0
	cmp r2, #1
	beq _08020426
	cmp r2, #1
	bgt _08020410
	cmp r2, #0
	beq _0802041A
	b _08020460
	.align 2, 0
_0802040C: .4byte 0x030046A4
_08020410:
	cmp r2, #2
	beq _0802043C
	cmp r2, #3
	beq _08020448
	b _08020460
_0802041A:
	subs r0, r1, #1
	strh r0, [r6, #0x3c]
	strh r1, [r6, #0x3e]
	adds r1, r6, #0
	adds r1, #0x6c
	b _0802045A
_08020426:
	ldr r0, _08020438 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	ldrh r0, [r0, #4]
	subs r0, r1, r0
	strh r0, [r6, #0x3c]
	strh r1, [r6, #0x3e]
	b _08020456
	.align 2, 0
_08020438: .4byte 0x030046A4
_0802043C:
	strh r1, [r6, #0x3c]
	subs r0, r1, #1
	strh r0, [r6, #0x3e]
	adds r1, r6, #0
	adds r1, #0x6c
	b _0802045A
_08020448:
	strh r1, [r6, #0x3c]
	ldr r0, _08020474 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	ldrh r0, [r0, #4]
	subs r0, r1, r0
	strh r0, [r6, #0x3e]
_08020456:
	adds r1, r6, #0
	adds r1, #0x68
_0802045A:
	ldrh r0, [r1]
	adds r0, #0x80
	strh r0, [r1]
_08020460:
	ldrh r4, [r6, #0x3c]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08020478
	adds r0, #4
	b _08020484
	.align 2, 0
_08020474: .4byte 0x030046A4
_08020478:
	ldr r0, _080204BC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08020484:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	adds r4, r6, #0
	adds r4, #0x3b
	movs r5, #0
	strb r0, [r4]
	ldr r0, [r6, #0x2c]
	ldrh r1, [r6, #0x3c]
	ldrb r3, [r4]
	movs r2, #0xff
	str r2, [sp]
	str r5, [sp, #4]
	movs r2, #0
	bl FUN_08234270
	adds r5, r6, #0
	adds r0, r6, #0
	adds r0, #0x40
	ldrb r0, [r0]
	mov r8, r4
	cmp r0, #0xf
	bhi _0802057E
	lsls r0, r0, #2
	ldr r1, _080204C0 @ =_080204C4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080204BC: .4byte 0x030046A4
_080204C0: .4byte _080204C4
_080204C4: @ jump table
	.4byte _08020504 @ case 0
	.4byte _0802057E @ case 1
	.4byte _0802057E @ case 2
	.4byte _08020504 @ case 3
	.4byte _08020510 @ case 4
	.4byte _08020520 @ case 5
	.4byte _0802054C @ case 6
	.4byte _0802054C @ case 7
	.4byte _0802057E @ case 8
	.4byte _0802057E @ case 9
	.4byte _0802057E @ case 10
	.4byte _0802057E @ case 11
	.4byte _0802057E @ case 12
	.4byte _0802057E @ case 13
	.4byte _0802057E @ case 14
	.4byte _08020566 @ case 15
_08020504:
	ldr r0, [r6, #0x4c]
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r1, #0x3c
	b _0802055A
_08020510:
	ldr r0, [r6, #0x4c]
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #2
	movs r0, #0xf0
	lsls r0, r0, #1
	adds r1, r1, r0
	b _0802055A
_08020520:
	ldr r0, [r6, #0x4c]
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #2
	movs r4, #0x9b
	lsls r4, r4, #2
	adds r1, r1, r4
	adds r1, r7, r1
	adds r0, r5, #0
	movs r2, #0
	bl AuxSprite_Add
	ldr r1, [r6, #0x4c]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	adds r0, r7, r0
	movs r1, #0x2b
	bl Video_SetAuxSpritePltt
	b _0802057E
_0802054C:
	ldr r0, [r6, #0x4c]
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #2
	movs r3, #0xbe
	lsls r3, r3, #2
	adds r1, r1, r3
_0802055A:
	adds r1, r7, r1
	adds r0, r5, #0
	movs r2, #0
	bl AuxSprite_Add
	b _0802057E
_08020566:
	ldr r0, [r6, #0x4c]
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #2
	movs r0, #0xe1
	lsls r0, r0, #2
	adds r1, r1, r0
	adds r1, r7, r1
	adds r0, r5, #0
	movs r2, #0
	bl AuxSprite_Add
_0802057E:
	ldr r0, [r6, #0x78]
	ldr r1, [r6, #0x7c]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	mov r3, sb
	ldrb r1, [r3]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080205A0
	ldrh r0, [r5, #0x1c]
	subs r0, #0x20
	strh r0, [r5, #0x1c]
	ldrh r0, [r5, #0x20]
	adds r0, #0x20
	strh r0, [r5, #0x20]
	b _080205B4
_080205A0:
	ldrh r0, [r5, #0x1c]
	adds r0, #0x20
	strh r0, [r5, #0x1c]
	ldrh r0, [r5, #0x20]
	subs r0, #0x20
	strh r0, [r5, #0x20]
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	str r0, [r5]
_080205B4:
	ldr r0, [r5, #0x1c]
	ldr r1, [r5, #0x20]
	str r0, [r6, #0x70]
	str r1, [r6, #0x74]
	adds r0, r6, #0
	adds r0, #0x37
	ldrb r1, [r0]
	adds r3, r0, #0
	cmp r1, #0
	bne _080205DC
	ldr r0, _080205D8 @ =FUN_080206b0
	str r0, [r6, #0x30]
	adds r0, r6, #0
	adds r0, #0x39
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	b _0802060C
	.align 2, 0
_080205D8: .4byte FUN_080206b0
_080205DC:
	cmp r1, #1
	bne _080205FC
	ldr r0, _080205F8 @ =FUN_080206b4
	str r0, [r6, #0x30]
	movs r0, #2
	adds r2, r6, #0
	adds r2, #0x39
	movs r1, #0
	strb r0, [r2]
	adds r0, r6, #0
	adds r0, #0x3a
	strb r1, [r0]
	b _0802060C
	.align 2, 0
_080205F8: .4byte FUN_080206b4
_080205FC:
	ldr r0, _0802063C @ =FUN_080206b0
	str r0, [r6, #0x30]
	adds r1, r6, #0
	adds r1, #0x39
	movs r0, #0
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
_0802060C:
	ldrb r0, [r3]
	cmp r0, #0
	bne _08020644
	ldr r2, [r6, #0x2c]
	ldrh r1, [r2, #6]
	ldr r0, _08020640 @ =0x0000FFFD
	ands r0, r1
	strh r0, [r2, #6]
	ldr r2, [r6, #0x2c]
	ldrh r1, [r2, #6]
	movs r0, #3
	orrs r0, r1
	strh r0, [r2, #6]
	ldr r2, [r6, #0x2c]
	ldrb r0, [r2, #4]
	movs r1, #0xf0
	ands r1, r0
	mov r3, r8
	ldrb r0, [r3]
	adds r0, #1
	orrs r1, r0
	strb r1, [r2, #4]
	b _0802066C
	.align 2, 0
_0802063C: .4byte FUN_080206b0
_08020640: .4byte 0x0000FFFD
_08020644:
	cmp r0, #1
	bne _0802066C
	ldr r2, [r6, #0x2c]
	ldrh r1, [r2, #6]
	ldr r0, _0802067C @ =0x0000FFFC
	ands r0, r1
	strh r0, [r2, #6]
	ldr r2, [r6, #0x2c]
	ldrh r1, [r2, #6]
	movs r0, #2
	orrs r0, r1
	strh r0, [r2, #6]
	ldr r2, [r6, #0x2c]
	ldrb r1, [r2, #4]
	movs r0, #0xf0
	ands r0, r1
	mov r3, r8
	ldrb r1, [r3]
	orrs r0, r1
	strb r0, [r2, #4]
_0802066C:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802067C: .4byte 0x0000FFFC
