	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r7, r0, #0
	ldr r0, _0804703C @ =0x030000C0
	str r7, [r0]
	movs r0, #0x64
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08047054
	movs r0, #0x23
	adds r0, r0, r7
	mov sb, r0
	movs r1, #0x24
	adds r1, r1, r7
	mov sl, r1
	adds r2, r7, #0
	adds r2, #0x20
	str r2, [sp, #0x10]
	adds r3, r7, #0
	adds r3, #0x21
	str r3, [sp, #0x14]
	mov r4, sp
_0804702E:
	bl VM_GetPC
	cmp r0, #0
	beq _08047040
	bl VM_GetValue
	b _08047042
	.align 2, 0
_0804703C: .4byte 0x030000C0
_08047040:
	ldr r0, _08047050 @ =0x0000FFFF
_08047042:
	strh r0, [r4]
	adds r4, #2
	mov r0, sp
	adds r0, #0xe
	cmp r4, r0
	ble _0804702E
	b _08047082
	.align 2, 0
_08047050: .4byte 0x0000FFFF
_08047054:
	movs r4, #0x23
	adds r4, r4, r7
	mov sb, r4
	movs r5, #0x24
	adds r5, r5, r7
	mov sl, r5
	adds r0, r7, #0
	adds r0, #0x20
	str r0, [sp, #0x10]
	adds r1, r7, #0
	adds r1, #0x21
	str r1, [sp, #0x14]
	ldr r3, _080470D8 @ =0x0000FFFF
	adds r2, r3, #0
	mov r1, sp
	movs r6, #7
_08047074:
	ldrh r0, [r1]
	orrs r0, r2
	strh r0, [r1]
	adds r1, #2
	subs r6, #1
	cmp r6, #0
	bge _08047074
_08047082:
	movs r0, #0
	mov r4, sb
	strb r0, [r4]
	movs r0, #0x68
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08047158
	adds r5, r7, #0
	movs r0, #0x2c
	adds r0, r0, r7
	mov r8, r0
	movs r6, #0xf
_0804709C:
	bl VM_GetPC
	cmp r0, #0
	beq _08047144
	bl VM_GetValue
	strh r0, [r5, #0x2c]
	bl VM_GetValue
	strh r0, [r5, #0x30]
	mov r3, r8
	ldrh r1, [r5, #0x2c]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080470D4
	cmp r1, #0
	blt _080470D4
	ldr r0, _080470DC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080470D4
	ldr r0, _080470E0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080470E4
_080470D4:
	movs r4, #0
	b _080470F2
	.align 2, 0
_080470D8: .4byte 0x0000FFFF
_080470DC: .4byte 0x030046A8
_080470E0: .4byte 0x030046AC
_080470E4:
	ldr r0, _08047108 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080470F2:
	adds r0, r4, #0
	movs r1, #1
	str r3, [sp, #0x18]
	bl FUN_08234224
	ldr r3, [sp, #0x18]
	cmp r0, #0
	beq _0804710C
	adds r0, #4
	b _08047118
	.align 2, 0
_08047108: .4byte 0x030046A4
_0804710C:
	ldr r0, _0804712C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08047118:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08047130
	cmp r2, #2
	beq _08047134
	b _08047138
	.align 2, 0
_0804712C: .4byte 0x030046A4
_08047130:
	ldrb r0, [r3, #4]
	b _08047136
_08047134:
	ldrb r0, [r3]
_08047136:
	subs r1, r1, r0
_08047138:
	strh r1, [r5, #0x2e]
	mov r1, sb
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _0804714A
_08047144:
	strh r0, [r5, #0x2c]
	strh r0, [r5, #0x2e]
	strh r0, [r5, #0x30]
_0804714A:
	adds r5, #8
	movs r2, #8
	add r8, r2
	subs r6, #1
	cmp r6, #0
	bge _0804709C
	b _0804716E
_08047158:
	movs r1, #0
	adds r0, r7, #0
	adds r0, #0x2c
	movs r6, #0xf
_08047160:
	strh r1, [r0]
	strh r1, [r0, #2]
	strh r1, [r0, #4]
	adds r0, #8
	subs r6, #1
	cmp r6, #0
	bge _08047160
_0804716E:
	movs r0, #0
	mov r3, sl
	strb r0, [r3]
	movs r0, #0x73
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0804723E
	adds r5, r7, #0
	adds r5, #0xac
	movs r6, #0xf
_08047184:
	bl VM_GetPC
	cmp r0, #0
	beq _08047228
	bl VM_GetValue
	strh r0, [r5]
	bl VM_GetValue
	strh r0, [r5, #4]
	adds r3, r5, #0
	ldrh r1, [r5]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080471BC
	cmp r1, #0
	blt _080471BC
	ldr r0, _080471C0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080471BC
	ldr r0, _080471C4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080471C8
_080471BC:
	movs r4, #0
	b _080471D6
	.align 2, 0
_080471C0: .4byte 0x030046A8
_080471C4: .4byte 0x030046AC
_080471C8:
	ldr r0, _080471EC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080471D6:
	adds r0, r4, #0
	movs r1, #1
	str r3, [sp, #0x18]
	bl FUN_08234224
	ldr r3, [sp, #0x18]
	cmp r0, #0
	beq _080471F0
	adds r0, #4
	b _080471FC
	.align 2, 0
_080471EC: .4byte 0x030046A4
_080471F0:
	ldr r0, _08047210 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080471FC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08047214
	cmp r2, #2
	beq _08047218
	b _0804721C
	.align 2, 0
_08047210: .4byte 0x030046A4
_08047214:
	ldrb r0, [r3, #4]
	b _0804721A
_08047218:
	ldrb r0, [r3]
_0804721A:
	subs r1, r1, r0
_0804721C:
	strh r1, [r5, #2]
	mov r4, sl
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	b _0804722E
_08047228:
	strh r0, [r5]
	strh r0, [r5, #2]
	strh r0, [r5, #4]
_0804722E:
	adds r5, #8
	subs r6, #1
	cmp r6, #0
	bge _08047184
	b _08047254
_08047238:
	movs r0, #1
	rsbs r0, r0, #0
	b _080472BE
_0804723E:
	movs r1, #0
	adds r0, r7, #0
	adds r0, #0xac
	movs r6, #0xf
_08047246:
	strh r1, [r0]
	strh r1, [r0, #2]
	strh r1, [r0, #4]
	adds r0, #8
	subs r6, #1
	cmp r6, #0
	bge _08047246
_08047254:
	movs r4, #0
	strb r4, [r7, #0x1e]
	bl Time_GetHour
	ldr r5, [sp, #0x10]
	strb r0, [r5]
	bl Time_GetMinute
	ldr r1, [sp, #0x14]
	strb r0, [r1]
	strb r0, [r7, #0x1f]
	movs r0, #0x74
	movs r1, #0
	bl VM_GetNamedArgValue
	strh r0, [r7, #0x1c]
	str r4, [r7, #0x28]
	movs r6, #0
	ldr r2, _080472D0 @ =0x0000192C
	adds r2, r2, r7
	mov r8, r2
_0804727E:
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, _080472D4 @ =0x0000CB05
	bl GetFile
	adds r2, r0, #0
	cmp r2, #0
	beq _08047238
	mov r1, r8
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r4}
	stm r1!, {r3, r4}
	mov r0, r8
	adds r1, r2, #0
	bl OpenMainSpriteFile
	movs r5, #0x20
	add r8, r5
	adds r6, #1
	cmp r6, #7
	ble _0804727E
	ldr r0, _080472D8 @ =0x03002BE0
	ldr r0, [r0]
	ldr r2, _080472DC @ =0x00001A2C
	adds r1, r7, r2
	str r0, [r1]
	adds r0, #0x2c
	str r0, [r7, #0x18]
	movs r0, #0
_080472BE:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080472D0: .4byte 0x0000192C
_080472D4: .4byte 0x0000CB05
_080472D8: .4byte 0x03002BE0
_080472DC: .4byte 0x00001A2C
