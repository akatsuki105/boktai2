	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r6, r0, #0
	ldr r0, _080A897C @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _080A898E
	ldr r0, [r6, #0x18]
	ldr r1, [r0, #0x18]
	ldr r0, _080A8980 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _080A8984
	movs r0, #0
	b _080A898A
	.align 2, 0
_080A897C: .4byte 0x030047A4
_080A8980: .4byte 0x03002C68
_080A8984:
	adds r0, #0x60
	adds r0, r0, r1
	ldrb r0, [r0]
_080A898A:
	adds r7, r0, #0
	b _080A899A
_080A898E:
	ldr r0, _080A89B8 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _080A89BC @ =0x00000942
	adds r0, r0, r1
	movs r2, #0
	ldrsh r7, [r0, r2]
_080A899A:
	movs r3, #0xea
	lsls r3, r3, #1
	adds r2, r6, r3
	ldrh r1, [r2]
	cmp r1, #0
	beq _080A89D8
	subs r3, #4
	adds r0, r6, r3
	ldrh r0, [r0]
	cmp r0, #0
	beq _080A89C0
	subs r0, r1, #1
	strh r0, [r2]
	b _080A89D8
	.align 2, 0
_080A89B8: .4byte 0x030046A0
_080A89BC: .4byte 0x00000942
_080A89C0:
	cmp r7, #0
	ble _080A89C8
	subs r0, r1, #1
	strh r0, [r2]
_080A89C8:
	movs r0, #0xeb
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _080A89D8
	subs r0, #1
	strh r0, [r1]
_080A89D8:
	adds r0, r6, #0
	adds r0, #0x64
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r1, [r0, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov sb, r0
	cmp r2, #0
	blt _080A8A02
	cmp r1, #0
	blt _080A8A02
	ldr r0, _080A8A08 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080A8A02
	ldr r0, _080A8A0C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A8A10
_080A8A02:
	movs r4, #0
	b _080A8A1E
	.align 2, 0
_080A8A08: .4byte 0x030046A8
_080A8A0C: .4byte 0x030046AC
_080A8A10:
	ldr r0, _080A8A30 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080A8A1E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080A8A34
	adds r0, #4
	b _080A8A40
	.align 2, 0
_080A8A30: .4byte 0x030046A4
_080A8A34:
	ldr r0, _080A8A54 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080A8A40:
	ldrh r0, [r0, #2]
	movs r1, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080A8A5C
	ldr r1, _080A8A58 @ =FUN_080a8cfc
	adds r0, r6, #0
	bl Entity080a8ff8_SetState
	b _080A8B14
	.align 2, 0
_080A8A54: .4byte 0x030046A4
_080A8A58: .4byte FUN_080a8cfc
_080A8A5C:
	mov r5, sb
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080A8A82
	cmp r1, #0
	blt _080A8A82
	ldr r0, _080A8A88 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080A8A82
	ldr r0, _080A8A8C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A8A90
_080A8A82:
	movs r4, #0
	b _080A8A9E
	.align 2, 0
_080A8A88: .4byte 0x030046A8
_080A8A8C: .4byte 0x030046AC
_080A8A90:
	ldr r0, _080A8AB0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080A8A9E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080A8AB4
	adds r0, #4
	b _080A8AC0
	.align 2, 0
_080A8AB0: .4byte 0x030046A4
_080A8AB4:
	ldr r0, _080A8AD4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080A8AC0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080A8AD8
	cmp r2, #2
	beq _080A8ADC
	b _080A8AE0
	.align 2, 0
_080A8AD4: .4byte 0x030046A4
_080A8AD8:
	ldrb r0, [r5, #4]
	b _080A8ADE
_080A8ADC:
	ldrb r0, [r5]
_080A8ADE:
	subs r1, r1, r0
_080A8AE0:
	adds r2, r6, #0
	adds r2, #0x66
	movs r3, #0
	ldrsh r0, [r2, r3]
	cmp r1, r0
	ble _080A8AF8
	movs r0, #0xea
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r0, #0
	strh r0, [r1]
	b _080A8B14
_080A8AF8:
	cmp r1, r0
	bge _080A8B14
	ldrh r0, [r2]
	subs r0, #0x1e
	strh r0, [r2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r1
	bge _080A8B0C
	strh r1, [r2]
_080A8B0C:
	ldr r0, [r6, #0x64]
	ldr r1, [r6, #0x68]
	str r0, [r6, #0x38]
	str r1, [r6, #0x3c]
_080A8B14:
	movs r2, #0xea
	lsls r2, r2, #1
	adds r1, r6, r2
	movs r3, #0xe9
	lsls r3, r3, #1
	adds r2, r6, r3
	ldrh r0, [r1]
	ldrh r3, [r2]
	cmp r0, r3
	bhs _080A8B38
	movs r1, #0xed
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r1, [r0]
	movs r0, #3
	ands r0, r1
	adds r0, #0x14
	b _080A8B60
_080A8B38:
	ldrh r1, [r1]
	ldrh r0, [r2]
	lsls r0, r0, #1
	cmp r1, r0
	bge _080A8B52
	movs r2, #0xed
	lsls r2, r2, #1
	adds r0, r6, r2
	ldrh r1, [r0]
	movs r0, #3
	ands r0, r1
	adds r0, #0x10
	b _080A8B60
_080A8B52:
	movs r3, #0xed
	lsls r3, r3, #1
	adds r0, r6, r3
	ldrh r1, [r0]
	movs r0, #3
	ands r0, r1
	adds r0, #0xc
_080A8B60:
	strh r0, [r6, #0x2c]
	movs r0, #0xed
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r1, #0xea
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _080A8B7C
	b _080A8CC8
_080A8B7C:
	movs r2, #0xe8
	lsls r2, r2, #1
	adds r0, r6, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _080A8B8C
	movs r3, #0x7d
	b _080A8BCE
_080A8B8C:
	ldr r0, _080A8BB4 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _080A8BBC
	ldr r0, [r6, #0x18]
	ldr r1, _080A8BB8 @ =0x0000035E
	adds r0, r0, r1
	ldrh r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r0, r7, #2
	adds r0, r0, r7
	lsls r0, r0, #1
	adds r1, r1, r0
	mov r8, r1
	b _080A8BD0
	.align 2, 0
_080A8BB4: .4byte 0x030047A4
_080A8BB8: .4byte 0x0000035E
_080A8BBC:
	ldr r0, [r6, #0x18]
	ldr r2, _080A8C24 @ =0x0000035E
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0xa
	bl Div
	adds r3, r0, #0
	muls r3, r7, r3
_080A8BCE:
	mov r8, r3
_080A8BD0:
	movs r5, #0
	movs r0, #0x68
	adds r0, r0, r6
	mov sl, r0
	add r4, sp, #0x10
	ldr r7, _080A8C28 @ =0xFFFF0000
_080A8BDC:
	ldr r0, [r6, #0x64]
	ldr r1, [r6, #0x68]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	ldr r1, [sp, #0x10]
	asrs r0, r1, #0x10
	adds r0, #0x80
	lsls r0, r0, #0x10
	ldr r2, _080A8C2C @ =0x0000FFFF
	ands r2, r1
	orrs r2, r0
	str r2, [sp, #0x10]
	ldrh r1, [r4]
	adds r1, #0x40
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r7, #0
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x10]
	ldrh r0, [r4, #4]
	adds r0, #0x40
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, [r4, #4]
	ands r2, r7
	orrs r2, r0
	str r2, [r4, #4]
	cmp r5, #2
	beq _080A8C40
	cmp r5, #2
	bgt _080A8C30
	cmp r5, #1
	beq _080A8C3A
	b _080A8C68
	.align 2, 0
_080A8C24: .4byte 0x0000035E
_080A8C28: .4byte 0xFFFF0000
_080A8C2C: .4byte 0x0000FFFF
_080A8C30:
	cmp r5, #3
	beq _080A8C46
	cmp r5, #4
	beq _080A8C58
	b _080A8C68
_080A8C3A:
	ldrh r1, [r4]
	adds r1, #0x60
	b _080A8C5C
_080A8C40:
	ldrh r1, [r4, #4]
	adds r1, #0x60
	b _080A8C4A
_080A8C46:
	ldrh r1, [r4, #4]
	subs r1, #0x60
_080A8C4A:
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r7, #0
	ands r0, r2
	orrs r0, r1
	str r0, [r4, #4]
	b _080A8C68
_080A8C58:
	ldrh r1, [r4]
	subs r1, #0x60
_080A8C5C:
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #0x10]
	ands r0, r7
	orrs r0, r1
	str r0, [sp, #0x10]
_080A8C68:
	ldr r0, _080A8CBC @ =0x00241004
	str r0, [sp]
	movs r0, #0x1e
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	lsls r0, r5, #2
	str r0, [sp, #0xc]
	add r0, sp, #0x10
	movs r1, #0
	mov r2, r8
	movs r3, #0x32
	bl FUN_080d85d8
	adds r5, #1
	cmp r5, #4
	ble _080A8BDC
	mov r1, sb
	movs r2, #0
	ldrsh r0, [r1, r2]
	mov r3, sl
	movs r2, #0
	ldrsh r1, [r3, r2]
	movs r2, #0x80
	lsls r2, r2, #3
	movs r3, #1
	str r3, [sp]
	ldr r3, _080A8CC0 @ =0x0000B546
	str r3, [sp, #4]
	movs r3, #0
	bl FUN_08240cf0
	ldr r1, [r6, #0x18]
	ldr r3, _080A8CC4 @ =0x000003FB
	adds r1, r1, r3
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	adds r0, r6, #0
	bl KillEntity
	b _080A8CE6
	.align 2, 0
_080A8CBC: .4byte 0x00241004
_080A8CC0: .4byte 0x0000B546
_080A8CC4: .4byte 0x000003FB
_080A8CC8:
	movs r1, #0xeb
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _080A8CE6
	ldr r1, [r6, #0x18]
	ldr r2, _080A8CF8 @ =0x000003FB
	adds r1, r1, r2
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	adds r0, r6, #0
	bl KillEntity
_080A8CE6:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A8CF8: .4byte 0x000003FB
