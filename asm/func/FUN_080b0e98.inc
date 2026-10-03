	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	ldr r0, _080B0F1C @ =0x00000C6C
	adds r6, r7, r0
	ldr r1, _080B0F20 @ =0x000012DC
	adds r3, r7, r1
	movs r2, #0xa2
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r3]
	str r1, [r3, #4]
	ldrh r0, [r3]
	subs r0, #0x20
	strh r0, [r3]
	movs r0, #0x97
	lsls r0, r0, #5
	adds r1, r7, r0
	ldrh r0, [r1]
	subs r0, #0x20
	strh r0, [r1]
	ldr r1, _080B0F24 @ =0x00001284
	adds r2, r7, r1
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _080B0F28 @ =0x00001286
	adds r1, r7, r2
	ldrh r0, [r1]
	adds r0, #0x80
	strh r0, [r1]
	ldr r4, _080B0F2C @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r5, _080B0F30 @ =0x000003FF
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	ldr r1, _080B0F34 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x96
	lsls r1, r1, #2
	bl Mod
	ldr r0, [r4]
	adds r0, #1
	ands r0, r5
	str r0, [r4]
	adds r0, r6, #0
	bl FUN_080b0e3c
	movs r0, #0x4c
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080B0F38
	bl VM_GetValue
	adds r1, r0, #0
	b _080B0F3A
	.align 2, 0
_080B0F1C: .4byte 0x00000C6C
_080B0F20: .4byte 0x000012DC
_080B0F24: .4byte 0x00001284
_080B0F28: .4byte 0x00001286
_080B0F2C: .4byte 0x030046B8
_080B0F30: .4byte 0x000003FF
_080B0F34: .4byte 0x0203B400
_080B0F38:
	movs r1, #5
_080B0F3A:
	adds r0, r6, #0
	bl FUN_080b0aec
	adds r0, r6, #0
	movs r1, #0
	bl FUN_080af374
	ldr r2, _080B1010 @ =0x0000067C
	adds r1, r6, r2
	movs r0, #0
	mov r8, r0
	movs r0, #0xa0
	strh r0, [r1]
	ldr r1, _080B1014 @ =0x0000067E
	adds r0, r6, r1
	mov r2, r8
	strh r2, [r0]
	ldr r5, _080B1018 @ =0x0203B400
	ldr r0, _080B101C @ =0x030046B8
	mov ip, r0
	ldr r1, [r0]
	adds r1, #1
	ldr r4, _080B1020 @ =0x000003FF
	ands r1, r4
	lsls r0, r1, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r2, #0xf
	ands r0, r2
	adds r3, r0, #0
	adds r3, #8
	movs r0, #0xd0
	lsls r0, r0, #3
	adds r2, r6, r0
	strh r3, [r2]
	adds r1, #1
	ands r1, r4
	mov r0, ip
	str r1, [r0]
	lsls r1, r1, #1
	adds r1, r1, r5
	ldrh r0, [r1]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080B0F9A
	rsbs r0, r3, #0
	strh r0, [r2]
_080B0F9A:
	mov r2, ip
	ldr r1, [r2]
	adds r1, #1
	ands r1, r4
	lsls r0, r1, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r3, #0x3f
	ands r0, r3
	adds r0, #0xc0
	ldr r2, _080B1024 @ =0x00000682
	strh r0, [r2, r6]
	ldr r0, _080B1028 @ =0x0000068C
	adds r2, r6, r0
	movs r0, #0
	strb r0, [r2]
	ldr r2, _080B102C @ =0x00000684
	adds r0, r6, r2
	mov r2, r8
	strh r2, [r0]
	adds r1, #1
	ands r1, r4
	lsls r0, r1, #1
	adds r0, r0, r5
	ldrb r0, [r0]
	adds r0, #0xc0
	ldr r2, _080B1030 @ =0x00000686
	strh r0, [r2, r6]
	adds r1, #1
	ands r1, r4
	mov r0, ip
	str r1, [r0]
	lsls r1, r1, #1
	adds r1, r1, r5
	ldrh r0, [r1]
	ands r0, r3
	adds r0, #0x40
	adds r2, #2
	adds r1, r6, r2
	strh r0, [r1]
	movs r0, #0xd3
	lsls r0, r0, #3
	adds r1, r6, r0
	movs r0, #0x96
	lsls r0, r0, #2
	strh r0, [r1]
	adds r0, r6, #0
	bl FUN_080b0e58
	ldr r1, _080B1034 @ =0x000006AC
	adds r0, r6, r1
	str r7, [r0]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B1010: .4byte 0x0000067C
_080B1014: .4byte 0x0000067E
_080B1018: .4byte 0x0203B400
_080B101C: .4byte 0x030046B8
_080B1020: .4byte 0x000003FF
_080B1024: .4byte 0x00000682
_080B1028: .4byte 0x0000068C
_080B102C: .4byte 0x00000684
_080B1030: .4byte 0x00000686
_080B1034: .4byte 0x000006AC
