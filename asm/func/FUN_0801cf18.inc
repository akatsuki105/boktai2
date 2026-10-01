	push {r4, r5, r6, lr}
	adds r5, r0, #0
	bl EntityDA0B_TakeFnChanged
	cmp r0, #0
	beq _0801CFB2
	ldr r0, _0801CFCC @ =0x00000AA4
	adds r6, r5, r0
	movs r1, #0xa8
	lsls r1, r1, #4
	adds r4, r5, r1
	ldr r2, _0801CFD0 @ =0x00000B04
	adds r0, r5, r2
	adds r1, r5, #0
	adds r1, #0xf8
	movs r2, #0x39
	movs r3, #0
	bl MainSprite_SetPose
	movs r0, #0
	movs r1, #0x10
	movs r2, #0x1e
	movs r3, #2
	bl TextBox_SetRect
	ldr r1, _0801CFD4 @ =0x0000130C
	adds r0, r5, r1
	ldr r0, [r0]
	bl TextBox_Start
	movs r0, #3
	bl TextBox_ShowLine
	bl FUN_08049e5c
	ldr r0, _0801CFD8 @ =0x00000DA4
	adds r2, r5, r0
	ldr r0, [r2, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #8]
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0801b688
	ldr r1, _0801CFDC @ =0x00000978
	adds r0, r5, r1
	ldr r2, _0801CFE0 @ =0x000009FC
	adds r1, r5, r2
	ldrb r0, [r0, #1]
	ldrb r1, [r1, #1]
	cmp r0, r1
	beq _0801CF92
	movs r0, #0x8c
	lsls r0, r0, #1
	adds r1, r5, r0
	adds r0, r6, #0
	movs r2, #0x42
	movs r3, #0
	bl MainSprite_SetPose
_0801CF92:
	ldr r0, [r6, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #8]
	movs r0, #0x68
	strh r0, [r6, #0x20]
	movs r0, #0x28
	strh r0, [r6, #0x22]
	movs r0, #0xb8
	lsls r0, r0, #2
	strh r0, [r6, #0x3a]
	movs r0, #1
	bl FUN_0801b670
	str r0, [r6, #0x48]
_0801CFB2:
	ldr r0, _0801CFE4 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _0801CFE8
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _0801D014
	.align 2, 0
_0801CFCC: .4byte 0x00000AA4
_0801CFD0: .4byte 0x00000B04
_0801CFD4: .4byte 0x0000130C
_0801CFD8: .4byte 0x00000DA4
_0801CFDC: .4byte 0x00000978
_0801CFE0: .4byte 0x000009FC
_0801CFE4: .4byte 0x030044E0
_0801CFE8:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0801D008
	ldr r0, _0801D004 @ =0x00000AA4
	adds r1, r5, r0
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
	adds r0, r5, #0
	bl FUN_0801c614
	b _0801D014
	.align 2, 0
_0801D004: .4byte 0x00000AA4
_0801D008:
	adds r0, r5, #0
	bl FUN_0801c7dc
	ldr r0, [r5, #0x44]
	adds r0, #1
	str r0, [r5, #0x44]
_0801D014:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
