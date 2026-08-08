	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r4, r0, #0
	ldr r1, _08072DD0 @ =0x0000049C
	adds r0, r4, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r5, #0x2c
	ldrsh r0, [r4, r5]
	subs r6, r1, r0
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r4, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r5, #0x30
	ldrsh r0, [r4, r5]
	subs r5, r1, r0
	adds r1, r6, #0
	muls r1, r6, r1
	adds r0, r5, #0
	muls r0, r5, r0
	adds r1, r1, r0
	mov r8, r1
	movs r0, #0
	mov sl, r0
	mov sb, r0
	cmp r1, #0
	beq _08072D8C
	b _08072E8C
_08072D8C:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x10
	bl FUN_08066ee4
	str r0, [sp]
	ldr r5, _08072DD4 @ =0x000004A9
	adds r2, r4, r5
	ldrb r3, [r2]
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	blt _08072DEE
	movs r6, #0xba
	lsls r6, r6, #2
	adds r1, r4, r6
	strb r3, [r1]
	movs r0, #0xff
	strb r0, [r2]
	ldrb r1, [r1]
	cmp r1, #4
	bls _08072DE0
	movs r0, #8
	subs r0, r0, r1
	ldr r2, _08072DD8 @ =0x000002E6
	adds r1, r4, r2
	strb r0, [r1]
	ldr r5, _08072DDC @ =0x000002E7
	adds r1, r4, r5
	movs r0, #1
	strb r0, [r1]
	b _08072DEE
	.align 2, 0
_08072DD0: .4byte 0x0000049C
_08072DD4: .4byte 0x000004A9
_08072DD8: .4byte 0x000002E6
_08072DDC: .4byte 0x000002E7
_08072DE0:
	ldr r6, _08072E44 @ =0x000002E6
	adds r0, r4, r6
	strb r1, [r0]
	ldr r1, _08072E48 @ =0x000002E7
	adds r0, r4, r1
	mov r2, sb
	strb r2, [r0]
_08072DEE:
	ldr r5, _08072E4C @ =0x000004A6
	adds r6, r4, r5
	ldrb r0, [r6]
	cmp r0, #0
	beq _08072E72
	ldr r0, _08072E50 @ =0x000004A7
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	beq _08072E58
	movs r7, #1
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _08072E54 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	mov r8, r0
	movs r6, #0
	ldrsh r0, [r0, r6]
	mov sl, r0
	ands r3, r1
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	mov sb, r1
	ldrb r1, [r5]
	lsls r0, r1, #3
	subs r0, r0, r1
	asrs r0, r0, #3
	strb r0, [r5]
	b _08073016
	.align 2, 0
_08072E44: .4byte 0x000002E6
_08072E48: .4byte 0x000002E7
_08072E4C: .4byte 0x000004A6
_08072E50: .4byte 0x000004A7
_08072E54: .4byte 0x085B0A08
_08072E58:
	movs r7, #0
	movs r5, #0x96
	lsls r5, r5, #3
	adds r1, r4, r5
	ldr r0, [r1]
	cmp r0, #0
	beq _08072E6E
	str r7, [r1]
	movs r1, #0
	bl FUN_082318ac
_08072E6E:
	strb r7, [r6]
	b _08073016
_08072E72:
	movs r7, #0
	movs r6, #0x96
	lsls r6, r6, #3
	adds r1, r4, r6
	ldr r0, [r1]
	cmp r0, #0
	bne _08072E82
	b _08073016
_08072E82:
	str r7, [r1]
	movs r1, #0
	bl FUN_082318ac
	b _08073016
_08072E8C:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x11
	bl FUN_08066ee4
	str r0, [sp]
	movs r7, #1
	adds r0, r6, #0
	adds r1, r5, #0
	bl FUN_0823785c
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	adds r2, r1, #0
	strb r1, [r0]
	cmp r2, #4
	bls _08072EE0
	movs r0, #8
	subs r0, r0, r2
	ldr r5, _08072ED8 @ =0x000002E6
	adds r1, r4, r5
	strb r0, [r1]
	ldr r6, _08072EDC @ =0x000002E7
	adds r0, r4, r6
	strb r7, [r0]
	b _08072EEE
	.align 2, 0
_08072ED8: .4byte 0x000002E6
_08072EDC: .4byte 0x000002E7
_08072EE0:
	ldr r2, _08072F48 @ =0x000002E6
	adds r0, r4, r2
	strb r1, [r0]
	ldr r5, _08072F4C @ =0x000002E7
	adds r0, r4, r5
	mov r6, sb
	strb r6, [r0]
_08072EEE:
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _08072F50 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r6, #0
	ldrsh r5, [r0, r6]
	mov sl, r5
	ands r3, r1
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	mov sb, r1
	adds r0, r4, #0
	adds r0, #0x9c
	ldrh r1, [r0]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	beq _08073016
	mov r5, r8
	cmp r5, #0x40
	bgt _08072F58
	ldr r6, _08072F54 @ =0x0000049C
	adds r0, r4, r6
	ldrh r0, [r0]
	strh r0, [r4, #0x2c]
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrh r0, [r0]
	strh r0, [r4, #0x30]
	b _08072FF8
	.align 2, 0
_08072F48: .4byte 0x000002E6
_08072F4C: .4byte 0x000002E7
_08072F50: .4byte 0x085B0A08
_08072F54: .4byte 0x0000049C
_08072F58:
	mov r2, sl
	lsls r0, r2, #3
	cmp r0, #0
	blt _08072F64
	asrs r0, r0, #0xc
	b _08072F6A
_08072F64:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08072F6A:
	rsbs r0, r0, #0
	strh r0, [r4, #0x34]
	movs r0, #8
	mov r5, sb
	muls r5, r0, r5
	adds r0, r5, #0
	cmp r0, #0
	blt _08072F7E
	asrs r0, r0, #0xc
	b _08072F84
_08072F7E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08072F84:
	rsbs r0, r0, #0
	strh r0, [r4, #0x38]
	ldr r6, _08072FA8 @ =0x000001C7
	adds r1, r4, r6
	ldrb r1, [r1]
	cmp r1, #1
	bne _08072FC6
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _08072FAC
	movs r0, #0x38
	ldrsh r1, [r4, r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	bge _08072FB8
	b _08072FBC
	.align 2, 0
_08072FA8: .4byte 0x000001C7
_08072FAC:
	movs r2, #0x38
	ldrsh r1, [r4, r2]
	movs r0, #0x34
	muls r0, r1, r0
	cmp r0, #0
	blt _08072FBC
_08072FB8:
	asrs r0, r0, #6
	b _08072FC2
_08072FBC:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_08072FC2:
	strh r0, [r4, #0x38]
	b _08072FF8
_08072FC6:
	cmp r1, #2
	bne _08072FF8
	movs r5, #0x34
	ldrsh r0, [r4, r5]
	cmp r0, #0
	bge _08072FE0
	adds r1, r0, #0
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	bge _08072FEC
	b _08072FF0
_08072FE0:
	movs r0, #0x34
	ldrsh r1, [r4, r0]
	movs r0, #0x34
	muls r0, r1, r0
	cmp r0, #0
	blt _08072FF0
_08072FEC:
	asrs r0, r0, #6
	b _08072FF6
_08072FF0:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_08072FF6:
	strh r0, [r4, #0x34]
_08072FF8:
	ldr r1, _08073044 @ =0x000004A6
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08073016
	ldr r5, _08073048 @ =0x000004A7
	adds r2, r4, r5
	ldrb r0, [r2]
	cmp r0, #0x95
	bhi _08073016
	adds r1, r0, #0
	lsls r0, r1, #4
	subs r0, r0, r1
	asrs r0, r0, #4
	strb r0, [r2]
_08073016:
	adds r0, r4, #0
	ldr r1, [sp]
	movs r2, #0x40
	bl FUN_08060a24
	cmp r7, #0
	beq _08073034
	ldr r6, _08073048 @ =0x000004A7
	adds r0, r4, r6
	ldrb r3, [r0]
	adds r0, r4, #0
	mov r1, sl
	mov r2, sb
	bl FUN_08068e94
_08073034:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08073044: .4byte 0x000004A6
_08073048: .4byte 0x000004A7
