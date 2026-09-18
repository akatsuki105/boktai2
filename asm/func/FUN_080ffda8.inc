	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	adds r5, r0, #0
	movs r0, #0x9c
	adds r0, r0, r5
	mov r8, r0
	movs r1, #0
	mov sb, r1
	mov sl, r1
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r2, [r0]
	movs r3, #8
	ldrsh r0, [r2, r3]
	movs r6, #8
	ldrsh r1, [r5, r6]
	subs r0, r0, r1
	movs r7, #0xc
	ldrsh r1, [r2, r7]
	movs r3, #0xc
	ldrsh r2, [r5, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r3, _080FFE9C @ =0x085B0A08
	adds r1, r0, #0
	adds r1, #0x40
	movs r2, #0xff
	ands r1, r2
	lsls r1, r1, #1
	adds r1, r1, r3
	movs r6, #0
	ldrsh r1, [r1, r6]
	lsls r2, r1, #2
	adds r2, r2, r1
	lsls r2, r2, #5
	lsrs r2, r2, #0x10
	ldr r7, _080FFEA0 @ =0xFFFF0000
	ldr r1, [sp]
	ands r1, r7
	orrs r1, r2
	str r1, [sp]
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #5
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	ands r1, r7
	orrs r1, r0
	str r1, [sp, #4]
	mov r3, r8
	ldr r0, [r3, #4]
	bl FUN_08234f6c
	adds r4, r0, #0
	movs r6, #0
	mov r1, r8
	ldr r0, [r1, #4]
	ldrb r0, [r0]
	cmp sb, r0
	bge _080FFEB2
	mov ip, r7
	add r3, sp, #8
	mov r2, sp
	str r2, [sp, #0x10]
_080FFE40:
	ldrh r1, [r4]
	ldrh r0, [r5, #8]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #8]
	mov r7, ip
	ands r0, r7
	orrs r0, r1
	str r0, [sp, #8]
	ldrh r1, [r4, #2]
	ldrh r0, [r5, #0xc]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [r3, #4]
	ands r0, r7
	orrs r0, r1
	str r0, [r3, #4]
	ldr r0, [sp, #0x10]
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r7, #0
	ldrsh r0, [r3, r7]
	muls r1, r0, r1
	ldr r0, [sp, #0x10]
	movs r7, #4
	ldrsh r2, [r0, r7]
	movs r7, #4
	ldrsh r0, [r3, r7]
	muls r0, r2, r0
	adds r1, r1, r0
	cmp r1, #0
	bge _080FFEA4
	ldr r1, [r4]
	adds r0, r5, #0
	adds r0, #0xa4
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r1, r0
	beq _080FFEA6
	lsls r0, r6, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	b _080FFF14
	.align 2, 0
_080FFE9C: .4byte 0x085B0A08
_080FFEA0: .4byte 0xFFFF0000
_080FFEA4:
	adds r4, #8
_080FFEA6:
	adds r6, #1
	mov r1, r8
	ldr r0, [r1, #4]
	ldrb r0, [r0]
	cmp r6, r0
	blt _080FFE40
_080FFEB2:
	mov r2, sl
	cmp r2, #0
	bne _080FFF14
	adds r4, r5, #0
	adds r4, #0x9c
	ldr r2, _080FFF08 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080FFF0C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _080FFF10 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r1, [r4, #4]
	ldrb r1, [r1]
	bl Mod
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r6, [r4, #2]
	cmp r0, r6
	bne _080FFEF0
	adds r0, #1
	ldr r1, [r4, #4]
	ldrb r1, [r1]
	bl Mod
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
_080FFEF0:
	strb r0, [r4, #2]
	mov r7, sl
	strb r7, [r4, #3]
	ldr r0, [r4, #4]
	bl FUN_08234f6c
	ldrb r1, [r4, #2]
	lsls r1, r1, #3
	adds r0, r0, r1
	str r0, [r4, #8]
	b _080FFF24
	.align 2, 0
_080FFF08: .4byte 0x030046B8
_080FFF0C: .4byte 0x000003FF
_080FFF10: .4byte 0x0203B400
_080FFF14:
	movs r0, #0
	mov r2, sb
	mov r1, r8
	strb r2, [r1, #2]
	strb r0, [r1, #3]
	str r4, [r1, #8]
	adds r4, r5, #0
	adds r4, #0x9c
_080FFF24:
	movs r3, #0x95
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r6, [r0]
	ldr r0, [r4, #8]
	ldrh r1, [r0]
	strh r1, [r6]
	ldr r0, [r4, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r4, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r4, #0
	blt _080FFF58
	cmp r1, #0
	blt _080FFF58
	ldr r0, _080FFF5C @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _080FFF58
	ldr r0, _080FFF60 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080FFF64
_080FFF58:
	movs r4, #0
	b _080FFF72
	.align 2, 0
_080FFF5C: .4byte 0x030046A8
_080FFF60: .4byte 0x030046AC
_080FFF64:
	ldr r0, _080FFF84 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_080FFF72:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080FFF88
	adds r0, #4
	b _080FFF94
	.align 2, 0
_080FFF84: .4byte 0x030046A4
_080FFF88:
	ldr r0, _080FFFA8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080FFF94:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080FFFAC
	cmp r2, #2
	beq _080FFFB0
	b _080FFFB4
	.align 2, 0
_080FFFA8: .4byte 0x030046A4
_080FFFAC:
	ldrb r0, [r6, #4]
	b _080FFFB2
_080FFFB0:
	ldrb r0, [r6]
_080FFFB2:
	subs r1, r1, r0
_080FFFB4:
	strh r1, [r6, #2]
	ldr r6, _080FFFE0 @ =0x000004A4
	adds r0, r5, r6
	ldr r6, [r0]
	adds r7, r5, #0
	adds r7, #8
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r4, [r0]
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _080FFFE4
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	b _0810000A
	.align 2, 0
_080FFFE0: .4byte 0x000004A4
_080FFFE4:
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _08100004
	cmp r0, #2
	beq _08100000
	adds r0, r5, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08100000:
	movs r0, #1
	b _08100014
_08100004:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r5, r3
_0810000A:
	ldr r1, _08100068 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_08100014:
	adds r4, r0, #0
	cmp r4, #0
	bne _08100088
	ldr r1, _0810006C @ =FUN_080e48d0
	ldr r6, _08100070 @ =0x0000046D
	adds r0, r5, r6
	movs r3, #1
	strb r3, [r0]
	ldr r7, _08100074 @ =0x0000046B
	adds r0, r5, r7
	strb r4, [r0]
	ldr r2, _08100078 @ =0x00000553
	adds r0, r5, r2
	strb r4, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r5, r6
	str r1, [r0]
	movs r7, #0xe4
	lsls r7, r7, #1
	adds r0, r5, r7
	movs r2, #0
	strh r4, [r0]
	movs r1, #3
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	ldr r7, _0810007C @ =0x00000469
	adds r0, r5, r7
	strb r2, [r0]
	ldr r1, _08100080 @ =0x0000046A
	adds r0, r5, r1
	strb r2, [r0]
	ldr r2, _08100084 @ =0x00000484
	adds r0, r5, r2
	str r4, [r0]
	adds r6, #4
	adds r0, r5, r6
	strb r3, [r0]
	b _08100094
	.align 2, 0
_08100068: .4byte 0xFFFFFDFF
_0810006C: .4byte FUN_080e48d0
_08100070: .4byte 0x0000046D
_08100074: .4byte 0x0000046B
_08100078: .4byte 0x00000553
_0810007C: .4byte 0x00000469
_08100080: .4byte 0x0000046A
_08100084: .4byte 0x00000484
_08100088:
	movs r7, #0x95
	lsls r7, r7, #3
	adds r0, r5, r7
	ldr r1, [r0]
	movs r0, #1
	strh r0, [r1, #6]
_08100094:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
