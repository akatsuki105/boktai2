	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x4c
	mov sb, r0
	str r1, [sp, #0x40]
	movs r0, #0
	str r0, [sp, #0x48]
	cmp r1, #0
	bne _08201F94
	movs r0, #0xcf
	lsls r0, r0, #1
	bl PlaySound_082406e0
_08201F94:
	movs r1, #0
	str r1, [sp, #0x44]
	ldr r2, _08201FC0 @ =0x00000694
	add r2, sb
	mov sl, r2
	add r4, sp, #0x38
	mov r8, r4
_08201FA2:
	movs r0, #0x2c
	ldr r1, [sp, #0x44]
	muls r0, r1, r0
	mov r2, sb
	adds r3, r0, r2
	ldr r2, [r3, #0x28]
	adds r0, r2, #0
	movs r4, #1
	ands r0, r4
	cmp r0, #0
	beq _08201FC4
	ldr r0, [sp, #0x48]
	adds r0, #1
	str r0, [sp, #0x48]
	b _08202078
	.align 2, 0
_08201FC0: .4byte 0x00000694
_08201FC4:
	add r5, sp, #0x38
	adds r6, r3, #0
	adds r6, #0x44
	mov r1, sl
	ldrh r0, [r1]
	ldrh r1, [r6]
	subs r0, r0, r1
	mov r4, r8
	strh r0, [r4]
	mov r1, sl
	ldrh r0, [r1, #2]
	ldrh r1, [r6, #2]
	subs r0, r0, r1
	strh r0, [r5, #2]
	mov r4, sl
	ldrh r0, [r4, #4]
	ldrh r1, [r6, #4]
	subs r0, r0, r1
	strh r0, [r5, #4]
	mov r1, r8
	movs r4, #0
	ldrsh r0, [r1, r4]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r4, #2
	ldrsh r0, [r5, r4]
	adds r4, r0, #0
	muls r4, r0, r4
	adds r0, r4, #0
	adds r1, r1, r0
	movs r4, #4
	ldrsh r0, [r5, r4]
	adds r4, r0, #0
	muls r4, r0, r4
	adds r0, r4, #0
	adds r1, r1, r0
	ldr r0, _0820201C @ =0x0000018F
	cmp r1, r0
	bgt _08202020
	movs r0, #1
	orrs r2, r0
	str r2, [r3, #0x28]
	b _08202078
	.align 2, 0
_0820201C: .4byte 0x0000018F
_08202020:
	movs r7, #0x14
	adds r0, r1, #0
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _0820205E
	mov r1, r8
	movs r2, #0
	ldrsh r0, [r1, r2]
	muls r0, r7, r0
	adds r1, r4, #0
	bl Div
	mov r1, r8
	strh r0, [r1]
	movs r2, #2
	ldrsh r0, [r5, r2]
	muls r0, r7, r0
	adds r1, r4, #0
	bl Div
	strh r0, [r5, #2]
	movs r1, #4
	ldrsh r0, [r5, r1]
	muls r0, r7, r0
	adds r1, r4, #0
	bl Div
	strh r0, [r5, #4]
_0820205E:
	mov r2, r8
	ldrh r0, [r2]
	ldrh r4, [r6]
	adds r0, r0, r4
	strh r0, [r6]
	ldrh r0, [r5, #2]
	ldrh r1, [r6, #2]
	adds r0, r0, r1
	strh r0, [r6, #2]
	ldrh r0, [r5, #4]
	ldrh r2, [r6, #4]
	adds r0, r0, r2
	strh r0, [r6, #4]
_08202078:
	ldr r4, [sp, #0x44]
	adds r4, #1
	str r4, [sp, #0x44]
	cmp r4, #7
	ble _08201FA2
	ldr r0, [sp, #0x48]
	cmp r0, #7
	ble _082020AC
	ldr r0, _082020A0 @ =0x000006D9
	add r0, sb
	movs r1, #1
	strb r1, [r0]
	ldr r0, _082020A4 @ =0x000006DA
	add r0, sb
	strb r1, [r0]
	ldr r1, _082020A8 @ =0x000006DB
	add r1, sb
	movs r0, #7
	strb r0, [r1]
	b _08202112
	.align 2, 0
_082020A0: .4byte 0x000006D9
_082020A4: .4byte 0x000006DA
_082020A8: .4byte 0x000006DB
_082020AC:
	ldr r0, [sp, #0x40]
	movs r1, #8
	bl Mod
	adds r3, r0, #0
	cmp r3, #0
	bne _08202112
	ldr r2, _08202124 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08202128 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0820212C @ =0x0203B400
	adds r0, r0, r1
	ldrh r2, [r0]
	movs r0, #0x7f
	ands r2, r0
	ldr r0, _08202130 @ =0x00000694
	add r0, sb
	movs r1, #0xc
	str r1, [sp]
	movs r1, #4
	str r1, [sp, #4]
	str r2, [sp, #8]
	movs r1, #8
	str r1, [sp, #0xc]
	movs r1, #0x20
	str r1, [sp, #0x10]
	movs r1, #1
	str r1, [sp, #0x14]
	movs r1, #2
	str r1, [sp, #0x18]
	movs r1, #0x80
	lsls r1, r1, #2
	str r1, [sp, #0x1c]
	str r3, [sp, #0x20]
	ldr r1, _08202134 @ =0x0000F422
	str r1, [sp, #0x24]
	ldr r1, _08202138 @ =0x0000121B
	str r1, [sp, #0x28]
	str r3, [sp, #0x2c]
	str r3, [sp, #0x30]
	ldr r1, _0820213C @ =0x00000237
	str r1, [sp, #0x34]
	movs r1, #0xc
	movs r2, #8
	movs r3, #6
	bl FUN_081ee53c
_08202112:
	add sp, #0x4c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08202124: .4byte 0x030046B8
_08202128: .4byte 0x000003FF
_0820212C: .4byte 0x0203B400
_08202130: .4byte 0x00000694
_08202134: .4byte 0x0000F422
_08202138: .4byte 0x0000121B
_0820213C: .4byte 0x00000237
