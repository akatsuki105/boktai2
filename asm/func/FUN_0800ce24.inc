	push {r4, r5, r6, r7, lr}
	adds r6, r1, #0
	ldrb r0, [r6, #3]
	cmp r0, #0
	bne _0800CF14
	movs r0, #0x8e
	lsls r0, r0, #1
	adds r3, r6, r0
	ldr r0, _0800CE60 @ =0x03002BE0
	ldr r1, [r0]
	ldrh r0, [r1, #0x2c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0x30]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0800CE5C
	cmp r1, #0
	blt _0800CE5C
	ldr r0, _0800CE64 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0800CE5C
	ldr r0, _0800CE68 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0800CE6C
_0800CE5C:
	movs r0, #0
	b _0800CE7A
	.align 2, 0
_0800CE60: .4byte 0x03002BE0
_0800CE64: .4byte 0x030046A8
_0800CE68: .4byte 0x030046AC
_0800CE6C:
	ldr r0, _0800CEA0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_0800CE7A:
	ldrh r1, [r3, #2]
	movs r2, #2
	bl Map_FindDirToTile
	cmp r0, #0
	blt _0800CF04
	adds r1, r6, #0
	adds r1, #0x31
	strb r0, [r1]
	ldr r0, [r6, #0x20]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0800CEA4
	adds r0, r6, #0
	adds r0, #0x30
	strb r1, [r0]
	adds r7, r0, #0
	b _0800CEAE
	.align 2, 0
_0800CEA0: .4byte 0x030046A4
_0800CEA4:
	adds r1, r6, #0
	adds r1, #0x30
	movs r0, #1
	strb r0, [r1]
	adds r7, r1, #0
_0800CEAE:
	adds r0, r6, #0
	bl FUN_0800cc08
	cmp r0, #0
	beq _0800CF04
	movs r5, #4
	ldrb r1, [r6, #2]
	movs r0, #4
	movs r4, #0
	orrs r0, r1
	strb r0, [r6, #2]
	adds r1, r6, #0
	adds r1, #0x41
	movs r0, #0xa
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0x8c
	movs r1, #0x99
	lsls r1, r1, #1
	bl Video_SetAuxSpritePltt
	strb r5, [r6, #3]
	str r4, [r6, #4]
	movs r0, #1
	strb r0, [r6, #1]
	movs r0, #0
	ldrsb r0, [r7, r0]
	cmp r0, #2
	bne _0800CEF4
	ldr r0, _0800CEF0 @ =0x00000216
	bl PlaySound_082406e0
	b _0800CEFA
	.align 2, 0
_0800CEF0: .4byte 0x00000216
_0800CEF4:
	ldr r0, _0800CF00 @ =0x00000215
	bl PlaySound_082406e0
_0800CEFA:
	movs r0, #1
	b _0800CF24
	.align 2, 0
_0800CF00: .4byte 0x00000215
_0800CF04:
	movs r0, #0xa
	strh r0, [r6, #0x3a]
	ldr r0, _0800CF10 @ =0x00000217
	bl PlaySound_082406e0
	b _0800CF22
	.align 2, 0
_0800CF10: .4byte 0x00000217
_0800CF14:
	cmp r0, #1
	bne _0800CF22
	movs r0, #0xa
	strh r0, [r6, #0x3a]
	ldr r0, _0800CF2C @ =0x00000217
	bl PlaySound_082406e0
_0800CF22:
	movs r0, #0
_0800CF24:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800CF2C: .4byte 0x00000217
