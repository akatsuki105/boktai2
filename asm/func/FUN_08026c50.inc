	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	mov r8, r0
	mov sl, r1
	mov r7, r8
	movs r0, #0x48
	add r0, r8
	mov sb, r0
	mov r1, r8
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _08026D08
	movs r5, #0
	strb r5, [r1]
	movs r4, #0xc4
	lsls r4, r4, #1
	add r4, r8
	mov r2, sb
	ldr r0, [r2, #8]
	ldr r1, [r2, #0xc]
	str r0, [r4]
	str r1, [r4, #4]
	movs r3, #0xc8
	lsls r3, r3, #1
	add r3, r8
	movs r0, #0xd0
	lsls r0, r0, #3
	strh r0, [r3]
	movs r0, #0xc9
	lsls r0, r0, #1
	add r0, r8
	strh r5, [r0]
	movs r1, #0xca
	lsls r1, r1, #1
	add r1, r8
	movs r0, #0xa0
	lsls r0, r0, #3
	strh r0, [r1]
	movs r0, #0xb1
	lsls r0, r0, #1
	add r0, r8
	strh r5, [r0]
	movs r6, #0xc0
	lsls r6, r6, #1
	add r6, r8
	movs r0, #8
	str r0, [r6]
	movs r0, #0
	ldrsh r2, [r3, r0]
	movs r1, #0
	ldrsh r0, [r4, r1]
	subs r2, r2, r0
	movs r0, #4
	ldrsh r1, [r3, r0]
	movs r3, #4
	ldrsh r0, [r4, r3]
	subs r1, r1, r0
	adds r0, r2, #0
	muls r0, r2, r0
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [r6]
	bl Div
	movs r1, #0xc2
	lsls r1, r1, #1
	add r1, r8
	str r0, [r1]
	movs r1, #0x96
	lsls r1, r1, #2
	add r1, r8
	movs r2, #0x8e
	lsls r2, r2, #2
	add r2, r8
	movs r0, #2
	str r0, [sp]
	str r5, [sp, #4]
	mov r0, r8
	movs r3, #0xb
	bl Boss_PlayAnim
_08026D08:
	mov r3, sb
	ldr r0, [r3, #8]
	ldr r1, [r3, #0xc]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldr r2, [sp, #8]
	movs r0, #0xba
	lsls r0, r0, #1
	add r0, r8
	asrs r1, r2, #0x10
	ldrh r0, [r0]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r0, _08026DB0 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #8]
	add r0, sp, #8
	bl Camera_MoveTo
	movs r1, #0xa8
	lsls r1, r1, #3
	add r1, r8
	movs r0, #0
	strh r0, [r1]
	movs r1, #0xd
	mov r3, r8
	adds r3, #0x98
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	mov r4, r8
	adds r4, #0x50
	movs r2, #0xc8
	lsls r2, r2, #1
	add r2, r8
	movs r5, #0
	ldrsh r1, [r2, r5]
	mov r6, sb
	movs r5, #8
	ldrsh r0, [r6, r5]
	subs r5, r1, r0
	movs r6, #4
	ldrsh r1, [r2, r6]
	movs r2, #4
	ldrsh r0, [r4, r2]
	subs r2, r1, r0
	adds r1, r5, #0
	muls r1, r5, r1
	adds r0, r2, #0
	muls r0, r2, r0
	adds r1, r1, r0
	movs r4, #0xc0
	lsls r4, r4, #1
	add r4, r8
	ldr r0, [r4]
	adds r6, r0, #0
	muls r6, r0, r6
	adds r0, r6, #0
	adds r6, r3, #0
	cmp r1, r0
	blt _08026DE8
	adds r0, r5, #0
	adds r1, r2, #0
	bl ArcTan2_8
	adds r5, r0, #0
	mov r3, r8
	adds r3, #0x58
	ldr r4, [r4]
	ldr r2, _08026DB4 @ =gSineTable
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _08026DB8
	asrs r1, r0, #0xc
	b _08026DBE
	.align 2, 0
_08026DB0: .4byte 0x0000FFFF
_08026DB4: .4byte gSineTable
_08026DB8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08026DBE:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	ldr r1, _08026DDC @ =gSineTable
	movs r0, #0xff
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _08026DE0
	asrs r0, r0, #0xc
	b _08026DE6
	.align 2, 0
_08026DDC: .4byte gSineTable
_08026DE0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08026DE6:
	strh r0, [r3, #4]
_08026DE8:
	movs r3, #0xc2
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r2, [r0]
	cmp sl, r2
	bge _08026E2E
	cmp r2, #0
	beq _08026E1E
	movs r5, #0xc9
	lsls r5, r5, #1
	adds r0, r7, r5
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r3, #6
	adds r4, r7, r3
	movs r5, #0
	ldrsh r1, [r4, r5]
	subs r0, r0, r1
	mov r1, sl
	muls r1, r0, r1
	adds r0, r1, #0
	adds r1, r2, #0
	bl Div
	ldrh r1, [r4]
	adds r1, r1, r0
	b _08026E36
_08026E1E:
	movs r3, #0xc9
	lsls r3, r3, #1
	adds r0, r7, r3
	ldrh r1, [r0]
	movs r5, #0xac
	lsls r5, r5, #1
	adds r0, r7, r5
	b _08026E3C
_08026E2E:
	movs r1, #0xc9
	lsls r1, r1, #1
	adds r0, r7, r1
	ldrh r1, [r0]
_08026E36:
	movs r2, #0xac
	lsls r2, r2, #1
	adds r0, r7, r2
_08026E3C:
	strh r1, [r0]
	movs r3, #0xc2
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r1, [r0]
	cmp r1, #0
	ble _08026E82
	mov r5, sl
	lsls r0, r5, #7
	bl Div
	ldr r2, _08026E6C @ =gSineTable
	movs r1, #0xff
	ands r1, r0
	lsls r1, r1, #1
	adds r1, r1, r2
	movs r2, #0
	ldrsh r0, [r1, r2]
	lsls r0, r0, #8
	cmp r0, #0
	blt _08026E70
	asrs r2, r0, #0xc
	b _08026E76
	.align 2, 0
_08026E6C: .4byte gSineTable
_08026E70:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08026E76:
	movs r3, #0xac
	lsls r3, r3, #1
	adds r1, r7, r3
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
_08026E82:
	movs r5, #0xac
	lsls r5, r5, #1
	adds r4, r7, r5
	ldrh r1, [r4]
	ldr r0, _08026F50 @ =0x000001FF
	cmp r1, r0
	bls _08026E98
	adds r0, r7, #0
	movs r1, #1
	bl FUN_08023bd8
_08026E98:
	movs r1, #0xb1
	lsls r1, r1, #1
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #1
	bne _08026F60
	ldrh r1, [r4]
	ldr r0, _08026F54 @ =0x0000041A
	cmp r1, r0
	bhi _08026EC0
	movs r2, #0xc9
	lsls r2, r2, #2
	adds r1, r7, r2
	ldrh r0, [r1]
	cmp r0, #0
	bne _08026EC0
	adds r0, r1, #0
	movs r1, #1
	bl DuneyrrElem_SetState
_08026EC0:
	movs r3, #0xac
	lsls r3, r3, #1
	adds r0, r7, r3
	ldrh r1, [r0]
	ldr r0, _08026F58 @ =0x0000047E
	cmp r1, r0
	bhi _08026EE2
	movs r5, #0xae
	lsls r5, r5, #2
	adds r1, r7, r5
	ldrh r0, [r1]
	cmp r0, #0
	bne _08026EE2
	adds r0, r1, #0
	movs r1, #1
	bl DuneyrrElem_SetState
_08026EE2:
	movs r1, #0xac
	lsls r1, r1, #1
	adds r0, r7, r1
	ldrh r1, [r0]
	movs r0, #0xaf
	lsls r0, r0, #3
	cmp r1, r0
	bhi _08026F06
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r1, r7, r2
	ldrh r0, [r1]
	cmp r0, #0
	bne _08026F06
	adds r0, r1, #0
	movs r1, #1
	bl DuneyrrElem_SetState
_08026F06:
	movs r3, #0xac
	lsls r3, r3, #1
	adds r0, r7, r3
	ldrh r1, [r0]
	movs r0, #0xc0
	lsls r0, r0, #2
	cmp r1, r0
	bhi _08026F60
	movs r5, #0xe4
	lsls r5, r5, #2
	adds r1, r7, r5
	ldrh r0, [r1]
	cmp r0, #0
	bne _08026F2A
	adds r0, r1, #0
	movs r1, #2
	bl DuneyrrElem_SetState
_08026F2A:
	movs r0, #0xff
	lsls r0, r0, #2
	adds r1, r7, r0
	ldrh r0, [r1]
	cmp r0, #0
	bne _08026F3E
	adds r0, r1, #0
	movs r1, #2
	bl DuneyrrElem_SetState
_08026F3E:
	movs r2, #0xba
	lsls r2, r2, #1
	adds r1, r7, r2
	ldrh r0, [r1]
	cmp r0, #4
	bls _08026F5C
	subs r0, #4
	b _08026F5E
	.align 2, 0
_08026F50: .4byte 0x000001FF
_08026F54: .4byte 0x0000041A
_08026F58: .4byte 0x0000047E
_08026F5C:
	movs r0, #0
_08026F5E:
	strh r0, [r1]
_08026F60:
	movs r3, #0xb1
	lsls r3, r3, #1
	adds r0, r7, r3
	ldrh r0, [r0]
	cmp r0, #0
	beq _08026FD8
	movs r5, #0xe4
	lsls r5, r5, #2
	adds r1, r7, r5
	ldrh r0, [r1]
	cmp r0, #3
	bne _08026F8C
	movs r1, #0x11
	rsbs r1, r1, #0
	ldr r0, [r6]
	ands r0, r1
	str r0, [r6]
	ldr r6, _08026F88 @ =0x0000054B
	adds r1, r7, r6
	b _08026FAE
	.align 2, 0
_08026F88: .4byte 0x0000054B
_08026F8C:
	cmp r0, #2
	bne _08026FC0
	ldr r0, [r1, #0x14]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08026FA2
	subs r1, #0x12
	ldr r0, [r6]
	ands r0, r1
	b _08026FA8
_08026FA2:
	movs r1, #0x10
	ldr r0, [r6]
	orrs r0, r1
_08026FA8:
	str r0, [r6]
	ldr r0, _08026FBC @ =0x0000054B
	adds r1, r7, r0
_08026FAE:
	ldrb r0, [r1]
	cmp r0, #4
	bls _08026FC8
	subs r0, #4
	strb r0, [r1]
	b _08026FC8
	.align 2, 0
_08026FBC: .4byte 0x0000054B
_08026FC0:
	movs r1, #0x10
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
_08026FC8:
	ldr r1, _08027080 @ =0x0000027A
	adds r2, r7, r1
	ldr r3, _08027084 @ =0x0000054B
	adds r1, r7, r3
	ldrh r0, [r2]
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r2]
_08026FD8:
	mov r0, r8
	adds r0, #0xaa
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802701A
	movs r6, #0xb1
	lsls r6, r6, #1
	adds r5, r7, r6
	ldrh r4, [r5]
	cmp r4, #0
	bne _0802701A
	adds r0, r7, #0
	bl FUN_08023818
	ldr r0, _08027084 @ =0x0000054B
	adds r1, r7, r0
	movs r0, #0xc8
	strb r0, [r1]
	movs r2, #0x96
	lsls r2, r2, #2
	adds r1, r7, r2
	movs r3, #0x8e
	lsls r3, r3, #2
	adds r2, r7, r3
	movs r0, #2
	str r0, [sp]
	str r4, [sp, #4]
	mov r0, r8
	movs r3, #0x13
	bl Boss_PlayAnim
	movs r0, #1
	strh r0, [r5]
_0802701A:
	movs r5, #0xc2
	lsls r5, r5, #1
	adds r0, r7, r5
	ldr r0, [r0]
	cmp sl, r0
	blt _0802706E
	ldr r0, _08027088 @ =0x00000383
	bl PlaySound_0824078c
	bl FUN_080592a4
	bl Entity5DA5_AreAllLit
	movs r6, #0xa9
	add r6, r8
	mov sb, r6
	mov r6, r8
	adds r6, #0xa3
	mov r7, r8
	adds r7, #0xf8
	mov r4, r8
	adds r4, #0x8c
	cmp r0, #0
	beq _0802705C
	movs r5, #0
_0802704C:
	adds r0, r5, #0
	movs r1, #0
	movs r2, #1
	bl Entity5DA5_SetState
	adds r5, #1
	cmp r5, #3
	ble _0802704C
_0802705C:
	ldr r2, _0802708C @ =FUN_08027090
	movs r0, #0x11
	movs r1, #0
	strb r0, [r6]
	str r2, [r7]
	str r1, [r4]
	movs r0, #1
	mov r1, sb
	strb r0, [r1]
_0802706E:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08027080: .4byte 0x0000027A
_08027084: .4byte 0x0000054B
_08027088: .4byte 0x00000383
_0802708C: .4byte FUN_08027090
