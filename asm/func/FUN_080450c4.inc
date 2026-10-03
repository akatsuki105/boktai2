	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	ldr r0, _08045130 @ =0x03002B50
	ldr r0, [r0]
	mov sl, r0
	cmp r0, #0
	bne _080450DC
	b _080452BC
_080450DC:
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r7, r0, #0
	movs r0, #0x6b
	movs r1, #0
	bl VM_GetNamedArgValue
	mov r8, r0
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0804513C
	bl VM_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _08045134 @ =0xFFFF0000
	ldr r1, [sp, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #4]
	bl VM_GetValue
	lsls r0, r0, #0x10
	ldr r2, _08045138 @ =0x0000FFFF
	ldr r1, [sp, #4]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #4]
	bl VM_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #8]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #8]
	b _08045146
	.align 2, 0
_08045130: .4byte 0x03002B50
_08045134: .4byte 0xFFFF0000
_08045138: .4byte 0x0000FFFF
_0804513C:
	ldr r1, _08045278 @ =0xFFFF0000
	str r0, [sp, #4]
	ldr r0, [sp, #8]
	ands r0, r1
	str r0, [sp, #8]
_08045146:
	movs r0, #0x64
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r5, r0, #0
	ldr r0, _0804527C @ =0x0000DFCE
	mov sb, r0
	movs r6, #0
	adds r0, r7, #0
	mov r1, r8
	bl FUN_08040ed8
	adds r4, r0, #0
	cmp r4, #0
	bne _08045166
	b _080452BC
_08045166:
	adds r1, r7, #0
	add r2, sp, #4
	adds r3, r5, #0
	bl FUN_08040f0c
	cmp r0, #0
	bge _08045176
	b _080452BC
_08045176:
	str r6, [sp]
	adds r0, r4, #0
	movs r1, #2
	mov r2, sb
	movs r3, #0
	bl FUN_08040f48
	cmp r0, #0
	bge _0804518A
	b _080452BC
_0804518A:
	movs r1, #0xae
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	movs r0, #0x20
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #2
	movs r3, #7
	bl FUN_08040fc0
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r4, r2
	adds r1, r7, #0
	movs r2, #5
	bl EntityMsgBus_Register
	adds r0, r4, #0
	adds r0, #0x61
	strb r5, [r0]
	lsls r2, r5, #0x10
	lsrs r2, r2, #0x10
	adds r0, r2, #0
	adds r0, #0x10
	movs r3, #0xff
	ands r0, r3
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	strb r1, [r4, #0x1a]
	adds r2, #0x20
	ands r2, r3
	asrs r2, r2, #6
	adds r2, #1
	movs r0, #3
	ands r0, r2
	strb r0, [r4, #0x19]
	ldr r1, _08045280 @ =FUN_08044ee0
	movs r2, #0xb9
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _08045284 @ =FUN_08045088
	subs r2, #0x14
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _08045288 @ =FUN_08044730
	adds r2, #4
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _0804528C @ =FUN_08044f1c
	adds r2, #4
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _08045290 @ =FUN_080450a8
	adds r2, #4
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _08045294 @ =FUN_080450b4
	adds r2, #4
	adds r0, r4, r2
	str r1, [r0]
	strb r6, [r4, #2]
	strb r6, [r4, #3]
	strb r6, [r4, #4]
	str r6, [r4, #0x14]
	movs r5, #1
	strb r5, [r4, #8]
	ldr r1, _08045298 @ =FUN_0804473c
	strb r5, [r4, #6]
	subs r2, #0x14
	adds r0, r4, r2
	str r1, [r0]
	str r6, [r4, #0x10]
	strb r5, [r4, #9]
	strb r6, [r4, #0x18]
	mov r0, sb
	movs r1, #0
	bl FUN_08040d94
	movs r2, #0xae
	lsls r2, r2, #2
	adds r1, r4, r2
	str r0, [r1]
	mov r0, sb
	movs r1, #0
	bl FUN_08040dc0
	movs r2, #0xaf
	lsls r2, r2, #2
	adds r1, r4, r2
	str r0, [r1]
	movs r0, #0x62
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080452A0
	bl VM_GetValue
	movs r2, #0xf4
	lsls r2, r2, #1
	adds r1, r4, r2
	strb r0, [r1]
	bl VM_GetValue
	ldr r2, _0804529C @ =0x000001E9
	adds r1, r4, r2
	strb r0, [r1]
	bl VM_GetValue
	movs r2, #0xf5
	lsls r2, r2, #1
	adds r1, r4, r2
	strh r0, [r1]
	b _080452B4
	.align 2, 0
_08045278: .4byte 0xFFFF0000
_0804527C: .4byte 0x0000DFCE
_08045280: .4byte FUN_08044ee0
_08045284: .4byte FUN_08045088
_08045288: .4byte FUN_08044730
_0804528C: .4byte FUN_08044f1c
_08045290: .4byte FUN_080450a8
_08045294: .4byte FUN_080450b4
_08045298: .4byte FUN_0804473c
_0804529C: .4byte 0x000001E9
_080452A0:
	movs r2, #0xf4
	lsls r2, r2, #1
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r5, [r0]
	adds r2, #1
	adds r0, r4, r2
	strh r1, [r0]
_080452B4:
	mov r0, sl
	adds r1, r4, #0
	bl FUN_08040e34
_080452BC:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
