	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x48
	ldr r0, _0812F418 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0812F41C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0812F41E
	.align 2, 0
_0812F418: .4byte 0x0000046D
_0812F41C:
	movs r0, #0
_0812F41E:
	cmp r0, #0
	beq _0812F458
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	movs r3, #0xcc
	lsls r3, r3, #3
	adds r1, r1, r3
	movs r0, #7
	rsbs r0, r0, #0
	ldrh r2, [r1]
	ands r0, r2
	strh r0, [r1]
	adds r0, r5, #0
	movs r1, #3
	bl Enemy_PlayAnim
	movs r0, #0x20
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r0, #0x89
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0812F458:
	movs r2, #0x80
	lsls r2, r2, #9
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r1, r5, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #6
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r7, r1, #0
	cmp r6, #0x11
	bgt _0812F488
	ldrh r0, [r4, #8]
	cmp r0, #1
	bne _0812F488
	movs r0, #0
	strh r0, [r4, #0xe]
_0812F488:
	movs r1, #0x83
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r3, #0
	ldrsh r2, [r0, r3]
	movs r4, #0x85
	lsls r4, r4, #2
	adds r1, r5, r4
	movs r6, #0
	ldrsh r0, [r1, r6]
	subs r0, r2, r0
	adds r4, r1, #0
	cmp r0, #0
	blt _0812F4A8
	asrs r0, r0, #2
	b _0812F4AE
_0812F4A8:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_0812F4AE:
	adds r3, r0, #0
	movs r1, #0x84
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r6, #0
	ldrsh r2, [r0, r6]
	movs r0, #0x86
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r6, #0
	ldrsh r0, [r1, r6]
	subs r0, r2, r0
	cmp r0, #0
	blt _0812F4CE
	asrs r0, r0, #2
	b _0812F4D4
_0812F4CE:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_0812F4D4:
	adds r2, r0, #0
	cmp r3, #0xc8
	ble _0812F4DE
	movs r3, #0xc8
	b _0812F4E8
_0812F4DE:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r3, r0
	bge _0812F4E8
	adds r3, r0, #0
_0812F4E8:
	cmp r2, #0xc8
	ble _0812F4F0
	movs r2, #0xc8
	b _0812F4FA
_0812F4F0:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r2, r0
	bge _0812F4FA
	adds r2, r0, #0
_0812F4FA:
	ldrh r0, [r5, #0x10]
	adds r0, r0, r3
	strh r0, [r5, #0x10]
	ldrh r0, [r5, #0x14]
	adds r0, r0, r2
	strh r0, [r5, #0x14]
	ldrh r0, [r4]
	adds r0, r0, r3
	strh r0, [r4]
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	cmp r3, #0
	bne _0812F51E
	cmp r2, #0
	bne _0812F51E
	movs r0, #1
	b _0812F520
_0812F51E:
	movs r0, #0
_0812F520:
	cmp r0, #0
	beq _0812F5D6
	ldr r1, _0812F5DC @ =0x0000046B
	adds r0, r5, r1
	movs r2, #0
	movs r1, #1
	strb r1, [r0]
	movs r3, #0xc
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r5, r4
	strb r2, [r0]
	ldr r6, _0812F5E0 @ =0x00000469
	adds r0, r5, r6
	strb r2, [r0]
	adds r4, #2
	adds r0, r5, r4
	strb r3, [r0]
	adds r6, #0x1b
	adds r0, r5, r6
	str r2, [r0]
	ldr r3, _0812F5E4 @ =0x0000046C
	adds r0, r5, r3
	strb r1, [r0]
	movs r4, #0xb7
	lsls r4, r4, #3
	adds r0, r5, r4
	ldr r4, [r0]
	movs r3, #0x1a
	subs r6, #0x17
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _0812F5DC @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r3, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r4, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r2, [r0]
	adds r0, r5, #0
	bl FUN_08130eec
	adds r0, r5, #0
	bl Enemy_StepTowardPathNode
	ldr r4, _0812F5E8 @ =0x000001DF
	adds r0, r5, r4
	ldrb r0, [r0]
	cmp r0, #2
	beq _0812F59E
	movs r0, #4
	ldr r6, _0812F5EC @ =0x00000222
	adds r2, r5, r6
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_0812F59E:
	movs r0, #0x80
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r3, #0x93
	lsls r3, r3, #2
	adds r0, r5, r3
	ldrh r1, [r0]
	ldr r4, _0812F5F0 @ =0x0000024E
	adds r0, r5, r4
	strh r1, [r0]
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r6, #0xfe
	lsls r6, r6, #1
	adds r0, r5, r6
	ldrb r0, [r0]
	strb r0, [r5, #5]
	movs r1, #0x10
	ldr r0, [r7]
	orrs r0, r1
	str r0, [r7]
_0812F5D6:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0812F5DC: .4byte 0x0000046B
_0812F5E0: .4byte 0x00000469
_0812F5E4: .4byte 0x0000046C
_0812F5E8: .4byte 0x000001DF
_0812F5EC: .4byte 0x00000222
_0812F5F0: .4byte 0x0000024E
