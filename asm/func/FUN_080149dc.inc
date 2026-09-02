	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	str r0, [sp]
	str r1, [sp, #4]
	str r2, [sp, #8]
	str r3, [sp, #0xc]
	ldr r0, _08014A0C @ =0x03000058
	ldr r1, [r0]
	cmp r1, #0
	bne _08014A10
	movs r0, #0
	movs r1, #0
	bl Entity080146e0_Create
	adds r1, r0, #0
	cmp r1, #0
	bne _08014A10
	movs r0, #1
	rsbs r0, r0, #0
	b _08014D12
	.align 2, 0
_08014A0C: .4byte 0x03000058
_08014A10:
	ldr r0, [sp, #4]
	asrs r3, r0, #8
	movs r0, #0xff
	ldr r2, [sp, #4]
	ands r2, r0
	str r2, [sp, #4]
	ldr r4, [sp]
	cmp r4, #8
	ble _08014A26
	movs r0, #8
	str r0, [sp]
_08014A26:
	ldr r2, [sp, #4]
	cmp r2, #0x14
	bgt _08014A34
	ldr r4, [r1, #0x1c]
	str r4, [sp, #0x18]
	ldrh r0, [r4, #6]
	b _08014A3C
_08014A34:
	ldr r2, [r1, #0x20]
	str r2, [sp, #0x18]
	ldrh r0, [r2, #6]
	adds r0, #1
_08014A3C:
	str r0, [sp, #0x14]
	ldr r4, [sp, #0x44]
	asrs r4, r4, #1
	str r4, [sp, #0x10]
	movs r2, #0
	ldr r0, [sp, #0xc]
	movs r4, #0xff
	ands r0, r4
	lsls r0, r0, #1
	str r0, [sp, #0x1c]
	adds r1, #0x24
	mov sl, r1
	mov r8, sl
_08014A56:
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, #0
	beq _08014A60
	b _08014D00
_08014A60:
	movs r0, #1
	strb r0, [r1]
	mov r2, sp
	ldrb r2, [r2, #4]
	strb r2, [r1, #2]
	mov r4, sp
	ldrb r4, [r4]
	strb r4, [r1, #1]
	cmp r3, #0
	ble _08014A78
	subs r0, r3, #1
	b _08014A7C
_08014A78:
	movs r0, #2
	mov r1, r8
_08014A7C:
	strb r0, [r1, #3]
	movs r7, #0
	ldr r2, [sp]
	cmp r7, r2
	blt _08014A88
	b _08014CD6
_08014A88:
	ldr r6, _08014AEC @ =0x030046B8
	movs r3, #0xc
	add r3, sl
	mov sb, r3
	mov r4, sl
	adds r4, #4
	mov r0, sl
	adds r0, #0x14
	str r0, [sp, #0x20]
	adds r7, r2, #0
_08014A9C:
	movs r0, #1
	strb r0, [r4]
	strb r0, [r4, #1]
	movs r1, #0
	strb r1, [r4, #2]
	ldr r0, [r6]
	adds r0, #1
	ldr r2, _08014AF0 @ =0x000003FF
	ands r0, r2
	str r0, [r6]
	lsls r0, r0, #1
	ldr r3, _08014AF4 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r1, [sp, #0x5c]
	ands r0, r1
	ldr r2, [sp, #0x58]
	adds r0, r2, r0
	strb r0, [r4, #3]
	ldr r3, [sp, #8]
	ldrh r0, [r3]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r3, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08014AE8
	cmp r1, #0
	blt _08014AE8
	ldr r0, _08014AF8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08014AE8
	ldr r0, _08014AFC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08014B04
_08014AE8:
	ldr r0, _08014B00 @ =0x0000FFFF
	b _08014B12
	.align 2, 0
_08014AEC: .4byte 0x030046B8
_08014AF0: .4byte 0x000003FF
_08014AF4: .4byte 0x0203B400
_08014AF8: .4byte 0x030046A8
_08014AFC: .4byte 0x030046AC
_08014B00: .4byte 0x0000FFFF
_08014B04:
	ldr r0, _08014B40 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_08014B12:
	strh r0, [r4, #4]
	ldr r1, [sp, #8]
	ldrh r0, [r1, #2]
	strh r0, [r4, #6]
	ldr r2, [sp, #0x4c]
	cmp r2, #0
	beq _08014B4C
	ldr r0, [r6]
	adds r0, #1
	ldr r3, _08014B44 @ =0x000003FF
	ands r0, r3
	str r0, [r6]
	lsls r0, r0, #1
	ldr r1, _08014B48 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r1, [sp, #0x4c]
	bl Mod
	ldr r2, [sp, #0x48]
	adds r5, r2, r0
	b _08014B4E
	.align 2, 0
_08014B40: .4byte 0x030046A4
_08014B44: .4byte 0x000003FF
_08014B48: .4byte 0x0203B400
_08014B4C:
	ldr r5, [sp, #0x48]
_08014B4E:
	ldr r3, [sp, #0x44]
	cmp r3, #0
	beq _08014BD2
	ldr r0, [r6]
	adds r0, #1
	ldr r1, _08014B94 @ =0x000003FF
	ands r0, r1
	str r0, [r6]
	lsls r0, r0, #1
	ldr r2, _08014B98 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r1, [sp, #0x44]
	bl Mod
	ldr r3, [sp, #0xc]
	ldr r2, [sp, #0x10]
	subs r1, r3, r2
	mov r2, sb
	adds r1, r1, r0
	adds r0, r1, #0
	adds r0, #0x40
	movs r3, #0xff
	ands r0, r3
	lsls r0, r0, #1
	ldr r3, _08014B9C @ =0x085B0A08
	adds r0, r0, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r5, r0
	cmp r0, #0
	blt _08014BA0
	asrs r0, r0, #0xc
	b _08014BA6
	.align 2, 0
_08014B94: .4byte 0x000003FF
_08014B98: .4byte 0x0203B400
_08014B9C: .4byte 0x085B0A08
_08014BA0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08014BA6:
	strh r0, [r2]
	movs r0, #0
	strh r0, [r2, #2]
	movs r3, #0xff
	ands r1, r3
	lsls r0, r1, #1
	ldr r1, _08014BC4 @ =0x085B0A08
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r5, r0
	cmp r0, #0
	blt _08014BC8
	asrs r0, r0, #0xc
	b _08014BCE
	.align 2, 0
_08014BC4: .4byte 0x085B0A08
_08014BC8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08014BCE:
	strh r0, [r2, #4]
	b _08014C1E
_08014BD2:
	mov r1, sb
	ldr r0, [sp, #0xc]
	adds r0, #0x40
	movs r2, #0xff
	ands r0, r2
	lsls r0, r0, #1
	ldr r3, _08014BF4 @ =0x085B0A08
	adds r0, r0, r3
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	adds r2, r3, #0
	cmp r0, #0
	blt _08014BF8
	asrs r0, r0, #0xc
	b _08014BFE
	.align 2, 0
_08014BF4: .4byte 0x085B0A08
_08014BF8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08014BFE:
	strh r0, [r1]
	movs r3, #0
	strh r3, [r1, #2]
	ldr r3, [sp, #0x1c]
	adds r0, r3, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _08014C16
	asrs r0, r0, #0xc
	b _08014C1C
_08014C16:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08014C1C:
	strh r0, [r1, #4]
_08014C1E:
	ldr r3, [sp, #0x54]
	cmp r3, #0
	beq _08014C4C
	ldr r0, [r6]
	adds r0, #1
	ldr r1, _08014C44 @ =0x000003FF
	ands r0, r1
	str r0, [r6]
	lsls r0, r0, #1
	ldr r2, _08014C48 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r1, [sp, #0x54]
	bl Mod
	ldr r3, [sp, #0x50]
	adds r0, r3, r0
	b _08014C50
	.align 2, 0
_08014C44: .4byte 0x000003FF
_08014C48: .4byte 0x0203B400
_08014C4C:
	add r0, sp, #0x50
	ldrh r0, [r0]
_08014C50:
	strh r0, [r4, #0xa]
	ldr r0, [r6]
	adds r0, #1
	ldr r1, _08014C74 @ =0x000003FF
	ands r0, r1
	str r0, [r6]
	lsls r0, r0, #1
	ldr r2, _08014C78 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	cmp r0, #7
	bgt _08014C7C
	ldr r0, [r4, #0x10]
	movs r1, #4
	orrs r0, r1
	b _08014C84
	.align 2, 0
_08014C74: .4byte 0x000003FF
_08014C78: .4byte 0x0203B400
_08014C7C:
	ldr r0, [r4, #0x10]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08014C84:
	str r0, [r4, #0x10]
	ldr r0, [r4, #0x10]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x10]
	ldr r3, [sp, #8]
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r4, #0x28]
	str r1, [r4, #0x2c]
	mov r0, sp
	ldrb r0, [r0, #0x14]
	strb r0, [r4, #0x1e]
	ldr r1, _08014CFC @ =0x085AA850
	ldr r2, [sp, #4]
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r3, [sp, #0x18]
	ldrh r0, [r3, #4]
	adds r0, r0, r1
	strh r0, [r4, #0x18]
	mov r1, r8
	ldrb r0, [r1, #3]
	strb r0, [r4, #0x1f]
	ldr r0, [sp, #0x20]
	movs r1, #0
	bl FUN_0822da50
	movs r2, #0x38
	add sb, r2
	adds r4, #0x38
	ldr r3, [sp, #0x20]
	adds r3, #0x38
	str r3, [sp, #0x20]
	subs r7, #1
	cmp r7, #0
	beq _08014CD4
	b _08014A9C
_08014CD4:
	ldr r7, [sp]
_08014CD6:
	cmp r7, #7
	bgt _08014D10
	movs r3, #0
	movs r2, #1
	lsls r0, r7, #3
	subs r0, r0, r7
	lsls r0, r0, #3
	adds r0, #4
	mov r4, sl
	adds r1, r0, r4
_08014CEA:
	strb r3, [r1]
	ldr r0, [r1, #0x10]
	orrs r0, r2
	str r0, [r1, #0x10]
	adds r1, #0x38
	adds r7, #1
	cmp r7, #7
	ble _08014CEA
	b _08014D10
	.align 2, 0
_08014CFC: .4byte 0x085AA850
_08014D00:
	movs r0, #0xe2
	lsls r0, r0, #1
	add r8, r0
	add sl, r0
	adds r2, #1
	cmp r2, #5
	bgt _08014D10
	b _08014A56
_08014D10:
	movs r0, #0
_08014D12:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
