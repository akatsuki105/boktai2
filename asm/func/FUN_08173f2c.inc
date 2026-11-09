	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov sb, r0
	ldr r2, _08173F58 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08173F5C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08173F5E
	.align 2, 0
_08173F58: .4byte 0x0000046C
_08173F5C:
	movs r0, #0
_08173F5E:
	ldr r3, _08173FD4 @ =0x00001008
	add r3, sb
	mov r8, r3
	movs r6, #0xbe
	lsls r6, r6, #1
	adds r6, r5, r6
	str r6, [sp, #0x10]
	cmp r0, #0
	beq _08173FBC
	movs r3, #0x20
	ldr r0, _08173FD8 @ =0x00000474
	adds r2, r5, r0
	ldrh r1, [r2]
	movs r4, #0
	adds r0, r3, #0
	orrs r0, r1
	strh r0, [r2]
	movs r0, #5
	rsbs r0, r0, #0
	mov r6, r8
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	movs r1, #0xe1
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r3, [r0]
	movs r3, #0xde
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r4, [r0]
	ldr r1, _08173FDC @ =0xFFEFFFFF
	ldr r6, [sp, #0x10]
	ldr r0, [r6]
	ands r0, r1
	str r0, [r6]
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r0, #9
	rsbs r0, r0, #0
	mov r2, r8
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_08173FBC:
	ldr r3, _08173FE0 @ =0x00000484
	adds r0, r5, r3
	ldr r0, [r0]
	cmp r0, #0x50
	ble _08173FE4
	adds r0, r5, #0
	movs r1, #0xc
	movs r2, #4
	movs r3, #0
	bl FUN_08177d34
	b _08173FF0
	.align 2, 0
_08173FD4: .4byte 0x00001008
_08173FD8: .4byte 0x00000474
_08173FDC: .4byte 0xFFEFFFFF
_08173FE0: .4byte 0x00000484
_08173FE4:
	ldr r3, _081740C0 @ =0x0000FFFF
	adds r0, r5, #0
	movs r1, #0xc
	movs r2, #4
	bl FUN_08177d34
_08173FF0:
	movs r6, #0
	ldr r1, _081740C4 @ =0x00001012
	add r1, sb
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r6, r0
	bge _0817406C
	mov r3, sp
	adds r7, r5, #0
	adds r7, #8
	ldr r0, _081740C8 @ =0x00000472
	adds r0, r5, r0
	str r0, [sp, #0xc]
	str r1, [sp, #8]
	mov r4, sb
	mov ip, r6
	movs r1, #0x92
	lsls r1, r1, #1
	mov sl, r1
_08174016:
	mov r2, ip
	add r2, sb
	ldr r0, _081740CC @ =0x00000674
	adds r2, r2, r0
	ldrh r0, [r2]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	strh r0, [r3]
	ldrh r0, [r2, #2]
	ldrh r1, [r7, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r7, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	movs r1, #0
	ldrsh r0, [r3, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #4
	ldrsh r0, [r3, r2]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	movs r0, #0xfa
	lsls r0, r0, #7
	cmp r1, r0
	ble _0817405C
	ldr r0, [sp, #0xc]
	ldrh r1, [r0]
	ldr r2, _081740D0 @ =0x00000676
	adds r0, r4, r2
	strh r1, [r0]
_0817405C:
	add r4, sl
	add ip, sl
	adds r6, #1
	ldr r1, [sp, #8]
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r6, r0
	blt _08174016
_0817406C:
	mov r0, sb
	bl FUN_08176c60
	movs r1, #0x10
	ldr r3, [sp, #0x10]
	ldr r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _081740B0
	adds r0, r5, #0
	adds r0, #8
	movs r1, #3
	bl FUN_08176530
	ldr r2, [r5, #0x44]
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #8
	mov r6, r8
	ldrh r1, [r6]
	orrs r0, r1
	strh r0, [r6]
	movs r0, #0x20
	ldr r1, _081740D4 @ =0x00000474
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r0, #0xf7
	lsls r0, r0, #2
	bl PlaySound_082406e0
_081740B0:
	movs r1, #8
	mov r2, r8
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081740D8
	movs r0, #1
	b _081740DA
	.align 2, 0
_081740C0: .4byte 0x0000FFFF
_081740C4: .4byte 0x00001012
_081740C8: .4byte 0x00000472
_081740CC: .4byte 0x00000674
_081740D0: .4byte 0x00000676
_081740D4: .4byte 0x00000474
_081740D8:
	movs r0, #0
_081740DA:
	cmp r0, #0
	beq _081741D0
	ldrh r0, [r5, #0xa]
	subs r0, #0x10
	movs r6, #0
	movs r7, #0
	strh r0, [r5, #0xa]
	mov r0, sb
	bl FUN_08176c60
	cmp r0, #0
	bge _081741D0
	ldr r2, _0817412C @ =0x00000F96
	add r2, sb
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	ble _08174138
	movs r1, #0xe
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r6, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r6, [r0]
	ldr r6, _08174130 @ =0x0000046A
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _08174134 @ =0x00000484
	adds r0, r5, r1
	str r7, [r0]
	adds r3, #3
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	ldrb r0, [r2]
	subs r0, #1
	strb r0, [r2]
	b _081741DA
	.align 2, 0
_0817412C: .4byte 0x00000F96
_08174130: .4byte 0x0000046A
_08174134: .4byte 0x00000484
_08174138:
	ldr r4, _0817416C @ =0x00000F97
	add r4, sb
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #4
	ble _0817417C
	movs r1, #0xe
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r6, [r0]
	ldr r3, _08174170 @ =0x00000469
	adds r0, r5, r3
	strb r6, [r0]
	ldr r6, _08174174 @ =0x0000046A
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _08174178 @ =0x00000484
	adds r0, r5, r1
	str r7, [r0]
	adds r2, #4
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
	b _081741DA
	.align 2, 0
_0817416C: .4byte 0x00000F97
_08174170: .4byte 0x00000469
_08174174: .4byte 0x0000046A
_08174178: .4byte 0x00000484
_0817417C:
	movs r1, #0xc
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r6, [r0]
	ldr r2, _081741C0 @ =0x00000469
	adds r0, r5, r2
	strb r6, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r1, [r0]
	ldr r6, _081741C4 @ =0x00000484
	adds r0, r5, r6
	str r7, [r0]
	ldr r0, _081741C8 @ =0x0000046C
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081741CC @ =0x00000474
	adds r2, r5, r1
	subs r0, #0x22
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	adds r0, r5, #0
	adds r0, #8
	movs r1, #3
	bl FUN_08176530
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	b _081741DA
	.align 2, 0
_081741C0: .4byte 0x00000469
_081741C4: .4byte 0x00000484
_081741C8: .4byte 0x0000046C
_081741CC: .4byte 0x00000474
_081741D0:
	ldr r2, _081741EC @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081741DA:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081741EC: .4byte 0x00000484
