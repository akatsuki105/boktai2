	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x44
	mov r8, r0
	movs r0, #0
	mov r1, sp
	adds r1, #0x24
	str r1, [sp, #0x40]
	movs r2, #0x28
	add r2, r8
	mov sb, r2
_0809D028:
	lsls r1, r0, #1
	lsls r2, r0, #2
	adds r7, r0, #1
	adds r0, #0x16
	adds r1, r1, r0
	ldr r0, [sp, #0x40]
	adds r6, r0, r2
	movs r5, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r0, #0xa8
	mov r1, r8
	adds r4, r0, r1
_0809D044:
	adds r0, r4, #0
	mov r1, sb
	movs r2, #0
	movs r3, #1
	bl MainSprite_SetPose
	movs r0, #0
	str r0, [r6]
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0809D044
	adds r0, r7, #0
	cmp r0, #3
	ble _0809D028
	mov r2, r8
	ldr r0, [r2, #0x18]
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #2
	bne _0809D0CC
	ldr r1, _0809D0C4 @ =0x00000F4C
	add r1, r8
	mov r0, r8
	bl FUN_0809cfc0
	ldr r1, [sp, #0x40]
	str r0, [r1, #0xc]
	movs r1, #0x64
	bl Div
	add r4, sp, #0x34
	str r0, [sp, #0x34]
	movs r1, #0x64
	muls r1, r0, r1
	ldr r2, [sp, #0x40]
	ldr r0, [r2, #0xc]
	subs r6, r0, r1
	adds r0, r6, #0
	movs r1, #0xa
	bl Div
	str r0, [r4, #4]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	subs r1, r6, r1
	str r1, [r4, #8]
	ldr r6, _0809D0C8 @ =0x00000C48
	add r6, r8
	movs r5, #2
_0809D0AA:
	ldm r4!, {r2}
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	mov r1, sb
	movs r3, #1
	bl MainSprite_SetPose
	adds r6, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0809D0AA
	b _0809D21E
	.align 2, 0
_0809D0C4: .4byte 0x00000F4C
_0809D0C8: .4byte 0x00000C48
_0809D0CC:
	movs r7, #1
	rsbs r7, r7, #0
	movs r1, #0xf7
	lsls r1, r1, #4
	add r1, r8
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	blt _0809D162
	mov r1, sp
	bl FUN_08242b14
	mov r0, sp
	ldrb r0, [r0, #1]
	movs r7, #0
	cmp r0, #0
	beq _0809D0FC
	movs r7, #1
	cmp r0, #1
	beq _0809D0FC
	movs r7, #3
	cmp r0, #2
	bne _0809D0FC
	movs r7, #2
_0809D0FC:
	mov r0, r8
	mov r1, sp
	bl FUN_0809cfc0
	lsls r4, r7, #2
	ldr r1, [sp, #0x40]
	adds r4, r1, r4
	str r0, [r4]
	movs r1, #0x64
	bl Div
	add r5, sp, #0x34
	str r0, [sp, #0x34]
	movs r1, #0x64
	muls r1, r0, r1
	ldr r0, [r4]
	subs r6, r0, r1
	adds r0, r6, #0
	movs r1, #0xa
	bl Div
	str r0, [r5, #4]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	subs r1, r6, r1
	str r1, [r5, #8]
	lsls r1, r7, #1
	adds r6, r5, #0
	adds r0, r7, #0
	adds r0, #0x16
	adds r1, r1, r0
	movs r5, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r0, #0xa8
	mov r2, r8
	adds r4, r0, r2
_0809D14A:
	ldm r6!, {r2}
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	mov r1, sb
	movs r3, #1
	bl MainSprite_SetPose
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0809D14A
_0809D162:
	ldr r4, _0809D1AC @ =0x00000E2B
	add r4, r8
	ldrb r0, [r4]
	bl FUN_0809cf98
	cmp r0, #0
	beq _0809D21E
	ldrb r0, [r4]
	mov r1, sp
	bl FUN_08242b14
	mov r0, sp
	ldrb r0, [r0, #1]
	movs r1, #0
	mov sl, r1
	cmp r0, #0
	beq _0809D198
	movs r2, #1
	mov sl, r2
	cmp r0, #1
	beq _0809D198
	movs r1, #3
	mov sl, r1
	cmp r0, #2
	bne _0809D198
	movs r2, #2
	mov sl, r2
_0809D198:
	mov r0, r8
	mov r1, sp
	bl FUN_0809cfc0
	adds r5, r0, #0
	cmp r7, #0
	bge _0809D1B0
	movs r7, #0xa
	b _0809D1C6
	.align 2, 0
_0809D1AC: .4byte 0x00000E2B
_0809D1B0:
	lsls r0, r7, #2
	ldr r1, [sp, #0x40]
	adds r0, r1, r0
	ldr r0, [r0]
	movs r7, #0xa
	cmp r5, r0
	bgt _0809D1C6
	movs r7, #0
	cmp r5, r0
	bge _0809D1C6
	movs r7, #0x14
_0809D1C6:
	adds r0, r5, #0
	movs r1, #0x64
	bl Div
	add r4, sp, #0x34
	str r0, [sp, #0x34]
	movs r1, #0x64
	muls r0, r1, r0
	subs r6, r5, r0
	adds r0, r6, #0
	movs r1, #0xa
	bl Div
	str r0, [r4, #4]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	subs r1, r6, r1
	str r1, [r4, #8]
	mov r2, sl
	lsls r1, r2, #1
	mov r0, sl
	adds r0, #0x16
	adds r1, r1, r0
	movs r5, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r0, #0xa8
	mov r1, r8
	adds r6, r0, r1
_0809D204:
	ldm r4!, {r2}
	adds r2, r2, r7
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	mov r1, sb
	movs r3, #1
	bl MainSprite_SetPose
	adds r6, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0809D204
_0809D21E:
	add sp, #0x44
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
