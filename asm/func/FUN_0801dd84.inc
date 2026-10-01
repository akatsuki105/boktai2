	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x34
	adds r6, r0, #0
	ldr r7, _0801DF18 @ =0x03002BE0
	ldr r4, [r7]
	adds r5, r4, #0
	bl EntityDA0B_TakeFnChanged
	cmp r0, #0
	beq _0801DDC4
	adds r0, r6, #0
	bl FUN_0801bcd8
	ldr r0, [r6, #0x18]
	ldr r1, [r6, #0x1c]
	str r0, [r6, #0x28]
	str r1, [r6, #0x2c]
	ldr r0, [r4, #0x2c]
	ldr r1, [r4, #0x30]
	str r0, [r6, #0x30]
	str r1, [r6, #0x34]
	adds r1, r6, #0
	adds r1, #0x94
	movs r0, #4
	strb r0, [r1]
	ldr r0, [r7]
	movs r1, #4
	bl FUN_0807b910
_0801DDC4:
	adds r0, r6, #0
	bl FUN_0801d540
	ldr r3, [r6, #0x44]
	adds r4, r6, #0
	adds r4, #0x18
	cmp r3, #0x20
	bhi _0801DDE6
	adds r1, r6, #0
	adds r1, #0x28
	adds r2, r6, #0
	adds r2, #0x30
	movs r0, #5
	str r0, [sp]
	adds r0, r4, #0
	bl LerpVec3
_0801DDE6:
	adds r0, r4, #0
	bl FUN_0823b8ac
	ldr r0, [r6, #0x44]
	cmp r0, #0x1e
	bne _0801DE12
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp, #0x1c]
	str r1, [sp, #0x20]
	movs r0, #0
	str r0, [sp]
	add r0, sp, #0x1c
	movs r1, #0x40
	movs r2, #0x3c
	movs r3, #8
	bl FUN_08019814
	movs r0, #0xa7
	lsls r0, r0, #2
	bl PlaySound_082406e0
_0801DE12:
	ldr r0, [r6, #0x44]
	cmp r0, #0x5a
	bne _0801DE68
	movs r0, #0xa8
	lsls r0, r0, #4
	adds r4, r6, r0
	ldr r0, [r7]
	add r2, sp, #0x24
	adds r3, r0, #0
	adds r3, #0x2c
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [sp, #0x24]
	str r1, [sp, #0x28]
	ldrh r0, [r2]
	subs r0, #0x20
	strh r0, [r2]
	ldrh r0, [r2, #4]
	adds r0, #0x20
	strh r0, [r2, #4]
	ldrh r0, [r2, #2]
	adds r0, #0x80
	strh r0, [r2, #2]
	ldrb r1, [r4]
	str r2, [sp]
	str r3, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	movs r0, #1
	movs r2, #0
	movs r3, #0
	bl FUN_080177b4
	ldr r0, [r7]
	movs r1, #0
	movs r2, #0
	bl FUN_0807bbb0
	movs r0, #0x88
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0801DE68:
	ldr r0, [r6, #0x44]
	cmp r0, #0x60
	beq _0801DE70
	b _0801DF72
_0801DE70:
	movs r0, #0xa8
	lsls r0, r0, #4
	adds r5, r6, r0
	ldr r4, [r7]
	cmp r4, #0
	beq _0801DF72
	ldrb r0, [r5, #2]
	cmp r0, #4
	bne _0801DF72
	ldrh r0, [r4, #0x2c]
	ldr r3, _0801DF1C @ =0xFFFF0000
	ldr r2, [sp, #0x2c]
	ands r2, r3
	orrs r2, r0
	str r2, [sp, #0x2c]
	movs r0, #0xbd
	lsls r0, r0, #1
	adds r1, r0, #0
	ldrh r0, [r4, #0x2e]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r0, _0801DF20 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x2c]
	ldrh r2, [r4, #0x30]
	add r1, sp, #0x2c
	ldr r0, [r1, #4]
	ands r0, r3
	orrs r0, r2
	str r0, [r1, #4]
	ldrb r0, [r5]
	mov sb, r1
	cmp r0, #5
	beq _0801DF72
	cmp r0, #0x18
	beq _0801DF72
	cmp r0, #0x2b
	beq _0801DF72
	cmp r0, #0x13
	beq _0801DECA
	cmp r0, #0x26
	beq _0801DECA
	cmp r0, #0x39
	bne _0801DF28
_0801DECA:
	movs r0, #0x1f
	str r0, [sp]
	ldr r0, _0801DF24 @ =0x00000FFF
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r1, #3
	movs r2, #0x1f
	movs r3, #0x1f
	bl FUN_0823ce68
	movs r0, #0x58
	mov r8, r0
	movs r4, #8
	movs r7, #0
	movs r5, #2
_0801DEEA:
	mov r0, r8
	str r0, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	movs r0, #1
	str r0, [sp, #0x10]
	movs r0, #0xc
	str r0, [sp, #0x14]
	str r4, [sp, #0x18]
	movs r0, #4
	movs r1, #0x86
	lsls r1, r1, #2
	mov r2, sb
	adds r3, r7, #0
	bl Entity080146e0_SpawnAtAngle
	adds r7, #0x58
	subs r5, #1
	cmp r5, #0
	bge _0801DEEA
	b _0801DF72
	.align 2, 0
_0801DF18: .4byte 0x03002BE0
_0801DF1C: .4byte 0xFFFF0000
_0801DF20: .4byte 0x0000FFFF
_0801DF24: .4byte 0x00000FFF
_0801DF28:
	movs r0, #7
	str r0, [sp]
	ldr r0, _0801DF90 @ =0x00000FFF
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r1, #3
	movs r2, #0x1f
	movs r3, #0x17
	bl FUN_0823ce68
	movs r0, #0x58
	mov r8, r0
	movs r4, #8
	movs r7, #0
	movs r5, #2
_0801DF48:
	mov r0, r8
	str r0, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	movs r0, #1
	str r0, [sp, #0x10]
	movs r0, #0xc
	str r0, [sp, #0x14]
	str r4, [sp, #0x18]
	movs r0, #4
	movs r1, #0x86
	lsls r1, r1, #2
	mov r2, sb
	adds r3, r7, #0
	bl Entity080146e0_SpawnAtAngle
	adds r7, #0x58
	subs r5, #1
	cmp r5, #0
	bge _0801DF48
_0801DF72:
	ldr r0, [r6, #0x44]
	cmp r0, #0xa3
	bls _0801DF9C
	ldr r1, _0801DF94 @ =FUN_0801dfb0
	adds r0, r6, #0
	bl EntityDA0B_SetFn
	ldr r0, _0801DF98 @ =0x03002BE0
	ldr r0, [r0]
	adds r1, r6, #0
	adds r1, #0x94
	ldrb r1, [r1]
	bl FUN_0807b910
	b _0801DFA0
	.align 2, 0
_0801DF90: .4byte 0x00000FFF
_0801DF94: .4byte FUN_0801dfb0
_0801DF98: .4byte 0x03002BE0
_0801DF9C:
	adds r0, #1
	str r0, [r6, #0x44]
_0801DFA0:
	add sp, #0x34
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
