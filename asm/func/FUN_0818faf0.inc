	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r1, #0
	str r2, [sp]
	mov sl, r3
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r5, [r0]
	movs r0, #0
	mov ip, r0
	ldr r1, _0818FB44 @ =0x00000F36
	adds r0, r5, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp ip, r0
	blt _0818FB1C
	b _0818FC18
_0818FB1C:
	ldr r0, _0818FB48 @ =gSineTable
	mov sb, r0
	adds r4, r5, #0
	movs r6, #0
	ldr r1, _0818FB4C @ =0x0000075A
	adds r3, r5, r1
	movs r0, #0x92
	lsls r0, r0, #1
	mov r8, r0
_0818FB2E:
	adds r0, r6, r5
	ldr r1, _0818FB50 @ =0x0000077A
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0818FB54
	movs r0, #1
	b _0818FB56
	.align 2, 0
_0818FB44: .4byte 0x00000F36
_0818FB48: .4byte gSineTable
_0818FB4C: .4byte 0x0000075A
_0818FB50: .4byte 0x0000077A
_0818FB54:
	movs r0, #0
_0818FB56:
	cmp r0, #0
	beq _0818FC02
	adds r0, r6, r5
	ldr r1, _0818FB70 @ =0x0000077A
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0818FB74
	movs r0, #1
	b _0818FB76
	.align 2, 0
_0818FB70: .4byte 0x0000077A
_0818FB74:
	movs r0, #0
_0818FB76:
	cmp r0, #0
	bne _0818FC02
	mov r0, sl
	cmp r0, #0
	bne _0818FBA4
	ldrb r0, [r3]
	lsls r0, r0, #1
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _0818FB94
	asrs r2, r0, #0xc
	b _0818FB9A
_0818FB94:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0818FB9A:
	ldr r0, _0818FBA0 @ =0x0000076E
	b _0818FBF2
	.align 2, 0
_0818FBA0: .4byte 0x0000076E
_0818FBA4:
	ldrb r0, [r3]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _0818FBBE
	asrs r2, r0, #0xc
	b _0818FBC4
_0818FBBE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0818FBC4:
	ldr r0, _0818FBE4 @ =0x0000076C
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldrb r0, [r3]
	lsls r0, r0, #1
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _0818FBE8
	asrs r2, r0, #0xc
	b _0818FBEE
	.align 2, 0
_0818FBE4: .4byte 0x0000076C
_0818FBE8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0818FBEE:
	movs r0, #0xee
	lsls r0, r0, #3
_0818FBF2:
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldrb r0, [r3]
	ldr r1, [sp]
	adds r0, r0, r1
	strb r0, [r3]
_0818FC02:
	add r4, r8
	add r6, r8
	add r3, r8
	movs r0, #1
	add ip, r0
	ldr r1, _0818FC28 @ =0x00000F36
	adds r0, r5, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp ip, r0
	blt _0818FB2E
_0818FC18:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0818FC28: .4byte 0x00000F36
