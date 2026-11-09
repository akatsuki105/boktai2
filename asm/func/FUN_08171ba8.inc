	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, _08171BC0 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08171BC4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08171BC6
	.align 2, 0
_08171BC0: .4byte 0x0000046D
_08171BC4:
	movs r0, #0
_08171BC6:
	cmp r0, #0
	beq _08171BDA
	movs r2, #0x80
	lsls r2, r2, #0xd
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r1, r4, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_08171BDA:
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r5, #0
	str r5, [sp]
	mov r0, sp
	ldr r2, _08171C24 @ =0x05000002
	bl CpuSet
	movs r3, #0xdf
	lsls r3, r3, #1
	adds r1, r4, r3
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0xff
	ble _08171C34
	ldr r3, _08171C28 @ =FUN_08171cc8
	movs r2, #0x22
	ldr r0, _08171C2C @ =0x0000046D
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08171C30 @ =0x0000046B
	adds r0, r4, r1
	strb r5, [r0]
	adds r1, #0xe8
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #0x25
	adds r0, r4, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r4, r3
	strh r5, [r0]
	b _08171CC0
	.align 2, 0
_08171C24: .4byte 0x05000002
_08171C28: .4byte FUN_08171cc8
_08171C2C: .4byte 0x0000046D
_08171C30: .4byte 0x0000046B
_08171C34:
	ldr r3, _08171C48 @ =0x00000484
	adds r0, r4, r3
	ldr r0, [r0]
	cmp r0, #0x1d
	bgt _08171C4C
	movs r5, #1
	adds r0, r2, #0
	adds r0, #0xa
	b _08171C52
	.align 2, 0
_08171C48: .4byte 0x00000484
_08171C4C:
	movs r5, #2
	adds r0, r2, #0
	adds r0, #0x28
_08171C52:
	strh r0, [r1]
	ldrb r0, [r4, #5]
	adds r3, r0, #0
	adds r3, #0x80
	movs r1, #0xff
	ands r3, r1
	ldr r2, _08171C78 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _08171C7C
	asrs r1, r0, #0xc
	b _08171C82
	.align 2, 0
_08171C78: .4byte gSineTable
_08171C7C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08171C82:
	ldrh r0, [r4, #0x10]
	adds r0, r0, r1
	strh r0, [r4, #0x10]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r5, r0
	cmp r0, #0
	blt _08171C9A
	asrs r2, r0, #0xc
	b _08171CA0
_08171C9A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08171CA0:
	ldrh r0, [r4, #0x14]
	adds r0, r0, r2
	strh r0, [r4, #0x14]
	movs r3, #0x80
	lsls r3, r3, #5
	adds r0, r4, #0
	movs r1, #0xa
	movs r2, #0xc
	bl FUN_08177d34
	adds r0, r4, #0
	movs r1, #0x14
	movs r2, #0x18
	movs r3, #0
	bl FUN_08177a4c
_08171CC0:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
