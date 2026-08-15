	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	ldr r1, _0823AAC8 @ =0x030047B8
	ldr r0, [r1]
	cmp r0, #0
	bne _0823AAD0
	ldr r0, _0823AACC @ =0x030044E0
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0823AAD4
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0823AAD4
	movs r0, #0xc
	ands r0, r1
	cmp r0, #0xc
	bne _0823AAD4
	bl SoftReset_0823a928
	b _0823AC94
	.align 2, 0
_0823AAC8: .4byte 0x030047B8
_0823AACC: .4byte 0x030044E0
_0823AAD0:
	movs r0, #0
	str r0, [r1]
_0823AAD4:
	ldr r5, [r6, #0x18]
	cmp r5, #0
	beq _0823AAE0
	cmp r5, #1
	beq _0823AB34
	b _0823AC4C
_0823AAE0:
	ldr r0, _0823AB20 @ =0x03004860
	str r5, [r0]
	ldr r7, _0823AB24 @ =0x03002CA8
	movs r0, #1
	mov r8, r0
	str r0, [r7]
	ldr r0, _0823AB28 @ =0x03004798
	str r5, [r0]
	str r5, [r6, #0x1c]
	bl FUN_0823a9c4
	bl FUN_08231c1c
	ldr r0, _0823AB2C @ =0x03002B28
	ldrh r4, [r0]
	cmp r4, #0
	beq _0823AB0E
	adds r0, r4, #0
	movs r1, #0
	bl Script_ExecById
	cmp r4, #0
	bne _0823AB12
_0823AB0E:
	bl FUN_08231ba8
_0823AB12:
	str r5, [r7]
	mov r1, r8
	str r1, [r6, #0x18]
	ldr r0, _0823AB30 @ =0x030047AC
	str r5, [r0]
	b _0823AC4C
	.align 2, 0
_0823AB20: .4byte 0x03004860
_0823AB24: .4byte 0x03002CA8
_0823AB28: .4byte 0x03004798
_0823AB2C: .4byte 0x03002B28
_0823AB30: .4byte 0x030047AC
_0823AB34:
	ldr r0, [r6, #0x1c]
	cmp r0, #0
	bgt _0823ABCC
	ldr r0, _0823AB8C @ =0x03004798
	ldr r0, [r0]
	cmp r0, #0
	beq _0823ABAC
	ldr r4, _0823AB90 @ =0x030044BC
	ldr r0, [r4]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0823AB50
	b _0823AC4C
_0823AB50:
	bl FUN_0823a8b0
	adds r1, r0, #0
	cmp r1, #0
	bne _0823ABAC
	ldr r0, _0823AB94 @ =0x0300478C
	str r1, [r0]
	ldr r0, _0823AB98 @ =0x030047C4
	str r1, [r0]
	ldr r0, _0823AB9C @ =0x030047AC
	str r5, [r0]
	movs r1, #0xf
	rsbs r1, r1, #0
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
	movs r0, #1
	bl entity_08230ca4
	movs r0, #3
	str r0, [r6, #0x1c]
	ldr r2, _0823ABA0 @ =0x03003E78
	ldr r0, _0823ABA4 @ =0xFFFFF1FF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r1, _0823ABA8 @ =0x03004460
	movs r0, #0x40
	str r0, [r1]
	b _0823AC4C
	.align 2, 0
_0823AB8C: .4byte 0x03004798
_0823AB90: .4byte 0x030044BC
_0823AB94: .4byte 0x0300478C
_0823AB98: .4byte 0x030047C4
_0823AB9C: .4byte 0x030047AC
_0823ABA0: .4byte 0x03003E78
_0823ABA4: .4byte 0xFFFFF1FF
_0823ABA8: .4byte 0x03004460
_0823ABAC:
	ldr r0, _0823ABC4 @ =0x030044BC
	ldr r0, [r0]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	bne _0823AC4C
	ldr r1, _0823ABC8 @ =0x030047BC
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	b _0823AC4C
	.align 2, 0
_0823ABC4: .4byte 0x030044BC
_0823ABC8: .4byte 0x030047BC
_0823ABCC:
	subs r0, #1
	str r0, [r6, #0x1c]
	cmp r0, #0
	bgt _0823AC4C
	bl FUN_0823aa70
	bl FUN_0823aa74
	ldr r2, _0823AC18 @ =0x030047A4
	ldr r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0823AC04
	ldr r0, _0823AC1C @ =0xFFFFFDFF
	ands r1, r0
	str r1, [r2]
	ldr r2, _0823AC20 @ =0x030044BC
	ldr r1, [r2]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0823AC04
	movs r0, #9
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r2]
_0823AC04:
	ldr r0, _0823AC24 @ =0x03004798
	ldr r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0823AC28
	bl Save_BackupStatAndWorld
	b _0823AC48
	.align 2, 0
_0823AC18: .4byte 0x030047A4
_0823AC1C: .4byte 0xFFFFFDFF
_0823AC20: .4byte 0x030044BC
_0823AC24: .4byte 0x03004798
_0823AC28:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r1, r0
	cmp r1, #0
	beq _0823AC48
	bl RestoreGameState
	ldr r0, _0823ACA0 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x93
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	bl FUN_08231be0
_0823AC48:
	movs r0, #0
	str r0, [r6, #0x18]
_0823AC4C:
	ldr r4, _0823ACA4 @ =0x030047B4
	ldr r0, [r4]
	cmp r0, #0
	beq _0823AC5C
	bl FUN_0823dd50
	movs r0, #0
	str r0, [r4]
_0823AC5C:
	ldr r0, _0823ACA8 @ =gSystemSaveData
	ldr r2, [r0]
	ldr r1, [r2]
	movs r0, #2
	rsbs r0, r0, #0
	cmp r1, r0
	bhi _0823AC6E
	adds r0, r1, #1
	str r0, [r2]
_0823AC6E:
	ldr r1, _0823ACAC @ =0x03004794
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, _0823ACB0 @ =0x03004788
	ldr r0, [r0]
	cmp r0, #0
	beq _0823AC94
	ldr r0, _0823ACA0 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0xad
	lsls r1, r1, #2
	adds r2, r0, r1
	ldr r1, [r2]
	ldr r0, _0823ACB4 @ =0x7FFFFFFE
	cmp r1, r0
	bgt _0823AC94
	adds r0, r1, #1
	str r0, [r2]
_0823AC94:
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0823ACA0: .4byte 0x030046A0
_0823ACA4: .4byte 0x030047B4
_0823ACA8: .4byte gSystemSaveData
_0823ACAC: .4byte 0x03004794
_0823ACB0: .4byte 0x03004788
_0823ACB4: .4byte 0x7FFFFFFE
