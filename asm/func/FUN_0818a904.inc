	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r6, r0, #0
	str r1, [sp]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _0818A930 @ =0x0000046D
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0818A934
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0818A936
	.align 2, 0
_0818A930: .4byte 0x0000046D
_0818A934:
	movs r0, #0
_0818A936:
	cmp r0, #0
	beq _0818A942
	ldr r1, _0818A958 @ =0x00000ECD
	add r1, r8
	movs r0, #0
	strb r0, [r1]
_0818A942:
	ldr r0, _0818A958 @ =0x00000ECD
	add r0, r8
	ldrb r1, [r0]
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _0818A95C
	ldrb r3, [r6, #5]
	b _0818A966
	.align 2, 0
_0818A958: .4byte 0x00000ECD
_0818A95C:
	ldrb r0, [r6, #5]
	adds r3, r0, #0
	adds r3, #0x80
	movs r0, #0xff
	ands r3, r0
_0818A966:
	movs r0, #0x7f
	ands r0, r1
	lsrs r4, r0, #4
	ldr r2, _0818A988 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _0818A98C
	asrs r1, r0, #0xc
	b _0818A992
	.align 2, 0
_0818A988: .4byte gSineTable
_0818A98C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0818A992:
	ldrh r0, [r6, #0x10]
	adds r0, r0, r1
	strh r0, [r6, #0x10]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _0818A9AA
	asrs r2, r0, #0xc
	b _0818A9B0
_0818A9AA:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0818A9B0:
	ldrh r0, [r6, #0x14]
	adds r0, r0, r2
	strh r0, [r6, #0x14]
	ldr r1, _0818A9C8 @ =0x00000ECD
	add r1, r8
	ldrb r0, [r1]
	adds r0, #0xc
	strb r0, [r1]
	movs r3, #0
	str r3, [sp, #4]
	movs r7, #0
	b _0818AB66
	.align 2, 0
_0818A9C8: .4byte 0x00000ECD
_0818A9CC:
	lsls r2, r7, #3
	adds r0, r2, r7
	lsls r0, r0, #3
	adds r0, r0, r7
	lsls r0, r0, #2
	add r0, r8
	movs r1, #2
	ldr r3, _0818A9EC @ =0x0000077A
	adds r0, r0, r3
	ldrh r0, [r0]
	ands r0, r1
	mov sb, r2
	cmp r0, #0
	beq _0818A9F0
	movs r0, #1
	b _0818A9F2
	.align 2, 0
_0818A9EC: .4byte 0x0000077A
_0818A9F0:
	movs r0, #0
_0818A9F2:
	adds r1, r7, #1
	mov sl, r1
	cmp r0, #0
	bne _0818A9FC
	b _0818AB64
_0818A9FC:
	mov r2, sb
	adds r0, r2, r7
	lsls r0, r0, #3
	adds r0, r0, r7
	lsls r0, r0, #2
	add r0, r8
	movs r1, #5
	ldr r3, _0818AA1C @ =0x0000077A
	adds r0, r0, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0818AA20
	movs r0, #1
	b _0818AA22
	.align 2, 0
_0818AA1C: .4byte 0x0000077A
_0818AA20:
	movs r0, #0
_0818AA22:
	adds r5, r0, #0
	adds r0, r7, #1
	mov sl, r0
	cmp r5, #0
	beq _0818AA2E
	b _0818AB64
_0818AA2E:
	movs r1, #0x10
	ldrsh r0, [r6, r1]
	mov r1, sl
	bl Div
	mov r2, sb
	adds r1, r2, r7
	lsls r1, r1, #3
	adds r1, r1, r7
	lsls r1, r1, #2
	mov r3, r8
	adds r4, r3, r1
	ldr r2, _0818AA80 @ =0x0000076C
	adds r1, r4, r2
	strh r0, [r1]
	ldr r3, _0818AA84 @ =0x0000076E
	adds r0, r4, r3
	strh r5, [r0]
	movs r1, #0x14
	ldrsh r0, [r6, r1]
	mov r1, sl
	bl Div
	movs r2, #0xee
	lsls r2, r2, #3
	adds r1, r4, r2
	strh r0, [r1]
	ldr r3, [sp, #4]
	cmp r3, #0
	beq _0818AA88
	cmp r3, #1
	beq _0818AAE0
	ldrh r1, [r6, #8]
	subs r2, #0xfc
	adds r0, r4, r2
	strh r1, [r0]
	ldrh r1, [r6, #0xc]
	movs r3, #0xcf
	lsls r3, r3, #3
	adds r0, r4, r3
	b _0818AB5C
	.align 2, 0
_0818AA80: .4byte 0x0000076C
_0818AA84: .4byte 0x0000076E
_0818AA88:
	ldrb r0, [r6, #5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	ldr r1, _0818AAA8 @ =gSineTable
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x36
	muls r0, r1, r0
	ldr r2, _0818AAA8 @ =gSineTable
	cmp r0, #0
	blt _0818AAAC
	asrs r3, r0, #0xc
	b _0818AAB2
	.align 2, 0
_0818AAA8: .4byte gSineTable
_0818AAAC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_0818AAB2:
	mov r1, sb
	adds r0, r1, r7
	lsls r0, r0, #3
	adds r0, r0, r7
	lsls r0, r0, #2
	add r0, r8
	ldrh r1, [r6, #8]
	subs r1, r1, r3
	ldr r3, _0818AADC @ =0x00000674
	adds r0, r0, r3
	strh r1, [r0]
	ldrb r0, [r6, #5]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x36
	muls r0, r1, r0
	cmp r0, #0
	bge _0818AB38
	b _0818AB40
	.align 2, 0
_0818AADC: .4byte 0x00000674
_0818AAE0:
	ldrb r0, [r6, #5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	ldr r3, _0818AB04 @ =gSineTable
	adds r0, r0, r3
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r2, r3, #0
	cmp r0, #0
	blt _0818AB08
	asrs r3, r0, #0xc
	b _0818AB0E
	.align 2, 0
_0818AB04: .4byte gSineTable
_0818AB08:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_0818AB0E:
	mov r1, sb
	adds r0, r1, r7
	lsls r0, r0, #3
	adds r0, r0, r7
	lsls r0, r0, #2
	add r0, r8
	ldrh r1, [r6, #8]
	subs r1, r1, r3
	ldr r3, _0818AB3C @ =0x00000674
	adds r0, r0, r3
	strh r1, [r0]
	ldrb r0, [r6, #5]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	cmp r0, #0
	blt _0818AB40
_0818AB38:
	asrs r2, r0, #0xc
	b _0818AB46
	.align 2, 0
_0818AB3C: .4byte 0x00000674
_0818AB40:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0818AB46:
	mov r3, sb
	adds r0, r3, r7
	lsls r0, r0, #3
	adds r0, r0, r7
	lsls r0, r0, #2
	add r0, r8
	ldrh r1, [r6, #0xc]
	subs r1, r1, r2
	movs r2, #0xcf
	lsls r2, r2, #3
	adds r0, r0, r2
_0818AB5C:
	strh r1, [r0]
	ldr r3, [sp, #4]
	adds r3, #1
	str r3, [sp, #4]
_0818AB64:
	mov r7, sl
_0818AB66:
	ldr r0, _0818ABC0 @ =0x00000F36
	add r0, r8
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r7, r0
	bge _0818AB74
	b _0818A9CC
_0818AB74:
	ldr r3, _0818ABC4 @ =0x0000FFFF
	adds r0, r6, #0
	movs r1, #0x40
	movs r2, #0xc
	bl FUN_0818fdd8
	ldr r2, [sp]
	cmp r2, #0x3c
	ble _0818ABB0
	ldr r4, _0818ABC8 @ =FUN_0818abd4
	movs r3, #0x23
	ldr r0, _0818ABCC @ =0x0000046D
	adds r1, r6, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0818ABD0 @ =0x0000046B
	adds r0, r6, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r6, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r6, r3
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r6, r1
	strh r2, [r0]
_0818ABB0:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0818ABC0: .4byte 0x00000F36
_0818ABC4: .4byte 0x0000FFFF
_0818ABC8: .4byte FUN_0818abd4
_0818ABCC: .4byte 0x0000046D
_0818ABD0: .4byte 0x0000046B
