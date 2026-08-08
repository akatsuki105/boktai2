	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x38
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	mov sb, r2
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r3, #0
	blt _080E3F86
	cmp r1, #0
	blt _080E3F86
	ldr r0, _080E3F8C @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _080E3F86
	ldr r0, _080E3F90 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080E3F94
_080E3F86:
	movs r0, #0
	b _080E3FA2
	.align 2, 0
_080E3F8C: .4byte 0x030046A8
_080E3F90: .4byte 0x030046AC
_080E3F94:
	ldr r0, _080E3FBC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r3
_080E3FA2:
	str r0, [sp, #0x34]
	ldr r1, [sp, #0x20]
	ldr r2, _080E3FC0 @ =0x00000256
	adds r0, r1, r2
	ldrh r4, [r0]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080E3FC4
	adds r0, #4
	b _080E3FD0
	.align 2, 0
_080E3FBC: .4byte 0x030046A4
_080E3FC0: .4byte 0x00000256
_080E3FC4:
	ldr r0, _080E3FE4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080E3FD0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080E3FE8
	cmp r2, #2
	beq _080E3FEE
	b _080E3FF4
	.align 2, 0
_080E3FE4: .4byte 0x030046A4
_080E3FE8:
	ldr r3, [sp, #0x24]
	ldrb r0, [r3, #4]
	b _080E3FF2
_080E3FEE:
	ldr r2, [sp, #0x24]
	ldrb r0, [r2]
_080E3FF2:
	subs r1, r1, r0
_080E3FF4:
	str r1, [sp, #0x28]
	ldr r0, [sp, #0x34]
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080E4006
	adds r0, #4
	b _080E4014
_080E4006:
	ldr r0, _080E4028 @ =0x030046A4
	ldr r1, [r0]
	ldr r3, [sp, #0x34]
	lsls r0, r3, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080E4014:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080E402C
	cmp r2, #2
	beq _080E4032
	b _080E4038
	.align 2, 0
_080E4028: .4byte 0x030046A4
_080E402C:
	mov r2, sb
	ldrb r0, [r2, #4]
	b _080E4036
_080E4032:
	mov r3, sb
	ldrb r0, [r3]
_080E4036:
	subs r1, r1, r0
_080E4038:
	str r1, [sp, #0x2c]
	movs r0, #0
	str r0, [sp, #0x30]
	ldr r2, [sp, #0x28]
	cmp r2, r1
	bne _080E4046
	b _080E4370
_080E4046:
	cmp r2, r1
	bgt _080E404C
	b _080E4204
_080E404C:
	mov r2, sp
	mov r3, sb
	ldrh r0, [r3]
	ldr r3, [sp, #0x24]
	ldrh r1, [r3]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	mov r1, sb
	ldrh r0, [r1, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	mov r3, sb
	ldrh r0, [r3, #4]
	ldr r3, [sp, #0x24]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x2c]
	subs r7, r0, r1
	cmp r7, #0xff
	ble _080E4088
	asrs r7, r7, #8
	cmp r7, #1
	ble _080E4084
	b _080E41F8
_080E4084:
	movs r2, #1
	str r2, [sp, #0x30]
_080E4088:
	ldr r3, [sp, #0x20]
	ldr r1, _080E40CC @ =0x00000256
	adds r0, r3, r1
	ldrh r5, [r0]
	add r6, sp, #8
	ldr r7, _080E40D0 @ =0x030046A4
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080E40D4
	adds r0, #4
	b _080E40DE
	.align 2, 0
_080E40CC: .4byte 0x00000256
_080E40D0: .4byte 0x030046A4
_080E40D4:
	ldr r0, [r7]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_080E40DE:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r1, r8
	lsls r0, r1, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	add r5, sp, #0x10
	ldr r6, _080E412C @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	ldr r0, [sp, #0x34]
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	ldr r0, [sp, #0x34]
	bl Div
	adds r7, r0, #0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r5]
	ldr r0, [sp, #0x34]
	movs r1, #1
	bl FUN_08234224
	mov sl, r5
	cmp r0, #0
	beq _080E4130
	adds r0, #4
	b _080E413C
	.align 2, 0
_080E412C: .4byte 0x030046A4
_080E4130:
	ldr r0, [r6]
	ldr r2, [sp, #0x34]
	lsls r1, r2, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_080E413C:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r5, #2]
	lsls r0, r7, #8
	adds r0, #0x80
	strh r0, [r5, #4]
	mov r3, sp
	ldrh r0, [r3, #0x28]
	strh r0, [r3, #0xa]
	ldrh r2, [r3, #0x2c]
	mov r1, sl
	strh r2, [r1, #2]
	add r4, sp, #0x18
	add r0, sp, #8
	ldrh r0, [r0]
	add r1, sp, #0x10
	ldrh r1, [r1]
	subs r0, r0, r1
	strh r0, [r4]
	ldrh r0, [r3, #0xa]
	mov r3, sl
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	mov r1, sp
	ldrh r0, [r1, #0xc]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	movs r2, #0
	ldrsh r0, [r4, r2]
	movs r3, #4
	ldrsh r1, [r4, r3]
	bl FUN_0823785c
	adds r0, #0x20
	asrs r0, r0, #6
	movs r5, #3
	ands r0, r5
	ldr r1, [sp, #0x34]
	mov r2, sl
	bl FUN_080e3afc
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080E41F8
	mov r1, sl
	ldrh r0, [r1]
	mov r2, sp
	ldrh r1, [r2, #8]
	subs r0, r0, r1
	strh r0, [r4]
	mov r3, sl
	ldrh r0, [r3, #2]
	ldrh r1, [r2, #0xa]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r2, #0xc]
	subs r0, r0, r1
	strh r0, [r4, #4]
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r2, #4
	ldrsh r1, [r4, r2]
	bl FUN_0823785c
	adds r0, #0x20
	asrs r4, r0, #6
	ands r4, r5
	ldr r3, [sp, #0x20]
	ldr r1, _080E4200 @ =0x00000256
	adds r0, r3, r1
	ldrh r1, [r0]
	adds r2, r3, #0
	adds r2, #8
	adds r0, r4, #0
	bl FUN_080e3afc
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080E41F8
	add r0, sp, #8
	mov r1, sl
	adds r2, r4, #0
	ldr r3, [sp, #0x34]
	bl FUN_080e3ed8
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080E41F8
	b _080E4370
_080E41F8:
	movs r0, #1
	rsbs r0, r0, #0
	b _080E4372
	.align 2, 0
_080E4200: .4byte 0x00000256
_080E4204:
	ldr r2, [sp, #0x2c]
	ldr r3, [sp, #0x28]
	subs r7, r2, r3
	ldr r0, _080E4258 @ =0x0000017F
	cmp r7, r0
	bgt _080E41F8
	ldr r1, [sp, #0x20]
	ldr r2, _080E425C @ =0x00000256
	adds r0, r1, r2
	ldrh r5, [r0]
	add r6, sp, #8
	ldr r3, _080E4260 @ =0x030046A4
	mov r8, r3
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov sl, r0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080E4264
	adds r0, #4
	b _080E4270
	.align 2, 0
_080E4258: .4byte 0x0000017F
_080E425C: .4byte 0x00000256
_080E4260: .4byte 0x030046A4
_080E4264:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_080E4270:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r1, sl
	lsls r0, r1, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	add r5, sp, #0x10
	ldr r6, _080E42C0 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	ldr r0, [sp, #0x34]
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	ldr r0, [sp, #0x34]
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r5]
	ldr r0, [sp, #0x34]
	movs r1, #1
	bl FUN_08234224
	mov sl, r5
	cmp r0, #0
	beq _080E42C4
	adds r0, #4
	b _080E42D0
	.align 2, 0
_080E42C0: .4byte 0x030046A4
_080E42C4:
	ldr r0, [r6]
	ldr r2, [sp, #0x34]
	lsls r1, r2, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_080E42D0:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r5, #2]
	mov r3, r8
	lsls r0, r3, #8
	adds r0, #0x80
	strh r0, [r5, #4]
	mov r0, sp
	ldrh r1, [r0, #0x28]
	strh r1, [r0, #0xa]
	ldrh r3, [r0, #0x2c]
	mov r2, sl
	strh r3, [r2, #2]
	add r2, sp, #0x18
	add r0, sp, #0x10
	ldrh r0, [r0]
	add r1, sp, #8
	ldrh r1, [r1]
	subs r0, r0, r1
	strh r0, [r2]
	mov r1, sl
	ldrh r0, [r1, #2]
	mov r3, sp
	ldrh r1, [r3, #0xa]
	subs r0, r0, r1
	strh r0, [r2, #2]
	mov r1, sl
	ldrh r0, [r1, #4]
	ldrh r1, [r3, #0xc]
	subs r0, r0, r1
	strh r0, [r2, #4]
	movs r3, #0
	ldrsh r0, [r2, r3]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl FUN_0823785c
	adds r0, #0x20
	asrs r4, r0, #6
	movs r6, #3
	ands r4, r6
	ldr r0, [sp, #0x20]
	ldr r1, _080E4360 @ =0x00000256
	adds r5, r0, r1
	ldrh r1, [r5]
	adds r2, r0, #0
	adds r2, #8
	adds r0, r4, #0
	bl FUN_080e3afc
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080E4340
	b _080E41F8
_080E4340:
	adds r2, r4, #2
	ands r2, r6
	ldrh r3, [r5]
	mov r0, sl
	add r1, sp, #8
	bl FUN_080e3ed8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080E4356
	b _080E41F8
_080E4356:
	cmp r7, #0xff
	ble _080E4364
	movs r2, #2
	b _080E436E
	.align 2, 0
_080E4360: .4byte 0x00000256
_080E4364:
	mov r3, sb
	ldrh r0, [r3, #2]
	ldr r1, [sp, #0x24]
	strh r0, [r1, #2]
	movs r2, #0
_080E436E:
	str r2, [sp, #0x30]
_080E4370:
	ldr r0, [sp, #0x30]
_080E4372:
	add sp, #0x38
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
