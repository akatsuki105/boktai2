	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r5, [r0]
	ldr r2, _0818B000 @ =0x0000046D
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0818B004
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0818B006
	.align 2, 0
_0818B000: .4byte 0x0000046D
_0818B004:
	movs r0, #0
_0818B006:
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r3, r3, r6
	mov sb, r3
	movs r4, #0xbe
	lsls r4, r4, #1
	adds r4, r4, r6
	mov sl, r4
	movs r7, #0x83
	lsls r7, r7, #2
	adds r7, r6, r7
	str r7, [sp]
	movs r1, #0x85
	lsls r1, r1, #2
	adds r7, r6, r1
	movs r2, #0x84
	lsls r2, r2, #2
	adds r2, r6, r2
	str r2, [sp, #4]
	movs r3, #0x86
	lsls r3, r3, #2
	adds r3, r3, r6
	mov r8, r3
	cmp r0, #0
	beq _0818B084
	movs r0, #0x20
	subs r1, #0x94
	adds r4, r6, r1
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	movs r0, #0xd4
	bl PlaySound_082406e0
	movs r0, #2
	rsbs r0, r0, #0
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r0, r6, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	ldr r4, _0818B0B0 @ =0x00000F47
	adds r1, r5, r4
	ldrb r1, [r1]
	bl Div
	adds r4, r0, #0
	ldr r1, _0818B0B4 @ =0x00000F46
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r4, r0
	bge _0818B084
	adds r5, r5, r1
_0818B076:
	adds r0, r6, #0
	bl FUN_08190634
	adds r4, #1
	ldrb r2, [r5]
	cmp r4, r2
	blt _0818B076
_0818B084:
	movs r1, #0x80
	lsls r1, r1, #6
	mov r3, sb
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	movs r1, #0x80
	lsls r1, r1, #9
	mov r4, sl
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	ldr r0, [sp]
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #0
	ldrsh r0, [r7, r3]
	subs r0, r1, r0
	cmp r0, #0
	blt _0818B0B8
	asrs r0, r0, #2
	b _0818B0BE
	.align 2, 0
_0818B0B0: .4byte 0x00000F47
_0818B0B4: .4byte 0x00000F46
_0818B0B8:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_0818B0BE:
	adds r2, r0, #0
	ldr r4, [sp, #4]
	movs r0, #0
	ldrsh r1, [r4, r0]
	mov r3, r8
	movs r4, #0
	ldrsh r0, [r3, r4]
	subs r0, r1, r0
	cmp r0, #0
	blt _0818B0D6
	asrs r0, r0, #2
	b _0818B0DC
_0818B0D6:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_0818B0DC:
	adds r1, r0, #0
	cmp r2, #0xc8
	ble _0818B0E6
	movs r2, #0xc8
	b _0818B0F0
_0818B0E6:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r2, r0
	bge _0818B0F0
	adds r2, r0, #0
_0818B0F0:
	cmp r1, #0xc8
	ble _0818B0F8
	movs r1, #0xc8
	b _0818B102
_0818B0F8:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0818B102
	adds r1, r0, #0
_0818B102:
	ldrh r0, [r6, #0x10]
	adds r0, r0, r2
	strh r0, [r6, #0x10]
	ldrh r0, [r6, #0x14]
	adds r0, r0, r1
	strh r0, [r6, #0x14]
	ldrh r0, [r7]
	adds r0, r0, r2
	strh r0, [r7]
	mov r7, r8
	ldrh r0, [r7]
	adds r0, r0, r1
	strh r0, [r7]
	cmp r2, #0
	bne _0818B128
	cmp r1, #0
	bne _0818B128
	movs r0, #1
	b _0818B12A
_0818B128:
	movs r0, #0
_0818B12A:
	cmp r0, #0
	beq _0818B1A0
	ldr r1, _0818B1B0 @ =0x0000046B
	adds r0, r6, r1
	movs r5, #0
	movs r3, #1
	strb r3, [r0]
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r2, r6, r4
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	movs r1, #0
	strh r0, [r2]
	ldr r4, _0818B1B4 @ =Enemy_ClearStateBegun
	movs r2, #0x10
	ldr r7, _0818B1B8 @ =0x0000046D
	adds r0, r6, r7
	strb r3, [r0]
	subs r7, #2
	adds r0, r6, r7
	strb r1, [r0]
	adds r7, #0xe8
	adds r0, r6, r7
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r6, r2
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r6, r4
	strh r5, [r0]
	movs r2, #5
	subs r7, #0xeb
	adds r0, r6, r7
	strb r1, [r0]
	ldr r4, _0818B1BC @ =0x00000469
	adds r0, r6, r4
	strb r1, [r0]
	adds r7, #2
	adds r0, r6, r7
	strb r2, [r0]
	ldr r1, _0818B1C0 @ =0x00000484
	adds r0, r6, r1
	str r5, [r0]
	ldr r2, _0818B1C4 @ =0x0000046C
	adds r0, r6, r2
	strb r3, [r0]
	movs r4, #0xfe
	lsls r4, r4, #1
	adds r0, r6, r4
	ldrb r0, [r0]
	strb r0, [r6, #5]
	adds r7, #0x18
	adds r0, r6, r7
	strh r3, [r0]
_0818B1A0:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0818B1B0: .4byte 0x0000046B
_0818B1B4: .4byte Enemy_ClearStateBegun
_0818B1B8: .4byte 0x0000046D
_0818B1BC: .4byte 0x00000469
_0818B1C0: .4byte 0x00000484
_0818B1C4: .4byte 0x0000046C
