	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r4, r0, #0
	mov sb, r1
	adds r5, r4, #0
	adds r7, r4, #0
	adds r7, #0x48
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _08026A68
	movs r0, #0
	strb r0, [r1]
	movs r2, #0x96
	lsls r2, r2, #2
	adds r1, r4, r2
	movs r3, #0x8e
	lsls r3, r3, #2
	adds r2, r4, r3
	movs r6, #1
	mov r8, r6
	str r6, [sp]
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r3, #0xa
	bl Boss_PlayAnim
	ldr r2, _08026A24 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08026A28 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08026A2C @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #7
	ands r0, r1
	adds r0, #3
	movs r2, #0xb5
	lsls r2, r2, #1
	adds r1, r4, r2
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_08023530
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r3, r3, r4
	mov sl, r3
	ldr r0, [r3]
	cmp r0, #0
	beq _08026A30
	movs r6, #0xc4
	lsls r6, r6, #1
	adds r3, r4, r6
	movs r0, #0xc8
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r6, #0
	ldrsh r2, [r1, r6]
	movs r6, #0
	ldrsh r0, [r3, r6]
	subs r2, r2, r0
	movs r0, #4
	ldrsh r1, [r1, r0]
	movs r6, #4
	ldrsh r0, [r3, r6]
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
	mov r3, sl
	ldr r1, [r3]
	bl Div
	movs r6, #0xc2
	lsls r6, r6, #1
	adds r1, r4, r6
	str r0, [r1]
	b _08026A3A
	.align 2, 0
_08026A24: .4byte 0x030046B8
_08026A28: .4byte 0x000003FF
_08026A2C: .4byte 0x0203B400
_08026A30:
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r4, r1
	mov r2, r8
	str r2, [r0]
_08026A3A:
	ldr r3, _08026AE0 @ =0x0000016F
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08026A5C
	ldr r6, _08026AE4 @ =0x0000079C
	adds r0, r5, r6
	ldr r1, [r0]
	adds r0, r4, #0
	bl Boss_GiveWeaponExp
	movs r0, #0x9e
	lsls r0, r0, #2
	adds r1, r5, r0
	adds r0, r4, #0
	bl FUN_08022fb8
_08026A5C:
	movs r2, #0xba
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r0, #0xbf
	lsls r0, r0, #1
	strh r0, [r1]
_08026A68:
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldr r2, [sp, #8]
	movs r3, #0xba
	lsls r3, r3, #1
	adds r0, r5, r3
	asrs r1, r2, #0x10
	ldrh r0, [r0]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r0, _08026AE8 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #8]
	add r0, sp, #8
	bl Camera_MoveTo
	movs r6, #0xa8
	lsls r6, r6, #3
	adds r1, r5, r6
	movs r0, #0
	strh r0, [r1]
	movs r0, #0xc8
	lsls r0, r0, #1
	adds r2, r5, r0
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r3, #8
	ldrsh r1, [r7, r3]
	subs r0, r0, r1
	movs r6, #4
	ldrsh r1, [r2, r6]
	movs r3, #0xc
	ldrsh r2, [r7, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	adds r6, r0, #0
	adds r3, r7, #0
	adds r3, #0x10
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	ldr r2, _08026AEC @ =gSineTable
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r7, r0
	cmp r0, #0
	blt _08026AF0
	asrs r1, r0, #0xc
	b _08026AF6
	.align 2, 0
_08026AE0: .4byte 0x0000016F
_08026AE4: .4byte 0x0000079C
_08026AE8: .4byte 0x0000FFFF
_08026AEC: .4byte gSineTable
_08026AF0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08026AF6:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	ldr r1, _08026B14 @ =gSineTable
	movs r0, #0xff
	ands r0, r6
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r6, #0
	ldrsh r0, [r0, r6]
	muls r0, r7, r0
	cmp r0, #0
	blt _08026B18
	asrs r0, r0, #0xc
	b _08026B1E
	.align 2, 0
_08026B14: .4byte gSineTable
_08026B18:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08026B1E:
	strh r0, [r3, #4]
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r2, [r0]
	cmp sb, r2
	bge _08026B66
	cmp r2, #0
	beq _08026B56
	movs r3, #0xc9
	lsls r3, r3, #1
	adds r0, r5, r3
	movs r6, #0
	ldrsh r0, [r0, r6]
	adds r1, #6
	adds r6, r5, r1
	movs r3, #0
	ldrsh r1, [r6, r3]
	subs r0, r0, r1
	mov r1, sb
	muls r1, r0, r1
	adds r0, r1, #0
	adds r1, r2, #0
	bl Div
	ldrh r1, [r6]
	adds r1, r1, r0
	b _08026B6E
_08026B56:
	movs r3, #0xc9
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrh r1, [r0]
	movs r6, #0xac
	lsls r6, r6, #1
	adds r0, r5, r6
	b _08026B74
_08026B66:
	movs r1, #0xc9
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r1, [r0]
_08026B6E:
	movs r2, #0xac
	lsls r2, r2, #1
	adds r0, r5, r2
_08026B74:
	strh r1, [r0]
	adds r0, r5, #0
	movs r1, #0
	bl FUN_08023bd8
	movs r2, #0xd
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r3, #0xc2
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r0, [r0]
	cmp sb, r0
	blt _08026C36
	ldr r6, _08026BA8 @ =0x0000016F
	adds r0, r5, r6
	ldrb r0, [r0]
	cmp r0, #0
	bne _08026BB0
	ldr r0, _08026BAC @ =0x000003BB
	bl PlaySound_0824078c
	b _08026BB6
	.align 2, 0
_08026BA8: .4byte 0x0000016F
_08026BAC: .4byte 0x000003BB
_08026BB0:
	ldr r0, _08026C08 @ =0x000003BB
	bl PlaySound_0824078c
_08026BB6:
	ldr r0, _08026C0C @ =0x0000016F
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r0, #1
	movs r3, #0
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _08026C14
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r1, r5, r2
	ldr r0, [r1]
	lsls r0, r0, #5
	asrs r0, r0, #6
	str r0, [r1]
	ldr r1, _08026C10 @ =FUN_08026968
	movs r0, #0xf
	adds r2, r4, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r3, [r0]
	adds r1, r4, #0
	adds r1, #0xa9
	movs r0, #1
	strb r0, [r1]
	movs r4, #7
_08026BF6:
	adds r0, r5, #0
	movs r1, #0
	bl FUN_08023bd8
	subs r4, #1
	cmp r4, #0
	bge _08026BF6
	b _08026C36
	.align 2, 0
_08026C08: .4byte 0x000003BB
_08026C0C: .4byte 0x0000016F
_08026C10: .4byte FUN_08026968
_08026C14:
	ldr r1, _08026C48 @ =FUN_08026c50
	movs r0, #0x10
	adds r2, r4, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r3, [r0]
	adds r1, r4, #0
	adds r1, #0xa9
	movs r0, #1
	strb r0, [r1]
	ldr r0, _08026C4C @ =0x000003BD
	bl PlaySound_0824078c
_08026C36:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08026C48: .4byte FUN_08026c50
_08026C4C: .4byte 0x000003BD
