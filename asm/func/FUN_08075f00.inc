	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r6, r0, #0
	ldr r0, _08075F6C @ =0x0000049C
	adds r0, r0, r6
	mov r8, r0
	movs r1, #0
	ldrsh r5, [r0, r1]
	movs r2, #0x2c
	ldrsh r0, [r6, r2]
	subs r5, r5, r0
	movs r3, #0x94
	lsls r3, r3, #3
	adds r7, r6, r3
	movs r0, #0
	ldrsh r4, [r7, r0]
	movs r1, #0x30
	ldrsh r0, [r6, r1]
	subs r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0823785c
	adds r3, r0, #0
	adds r0, r5, #0
	muls r0, r5, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r0, r1
	cmp r0, #0x90
	ble _08075F44
	b _080760E8
_08075F44:
	mov r2, r8
	ldrh r0, [r2]
	strh r0, [r6, #0x2c]
	ldrh r0, [r7]
	strh r0, [r6, #0x30]
	ldr r4, _08075F70 @ =0x000004A9
	adds r1, r6, r4
	ldrb r2, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	blt _08075F74
	movs r3, #0xba
	lsls r3, r3, #2
	adds r0, r6, r3
	strb r2, [r0]
	movs r0, #0xff
	strb r0, [r1]
	b _08075F8E
	.align 2, 0
_08075F6C: .4byte 0x0000049C
_08075F70: .4byte 0x000004A9
_08075F74:
	lsls r0, r3, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	movs r4, #0xba
	lsls r4, r4, #2
	adds r0, r6, r4
	strb r1, [r0]
_08075F8E:
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r2, [r0]
	cmp r2, #4
	bls _08075FB8
	movs r0, #8
	subs r0, r0, r2
	ldr r2, _08075FB0 @ =0x000002E6
	adds r1, r6, r2
	strb r0, [r1]
	ldr r3, _08075FB4 @ =0x000002E7
	adds r1, r6, r3
	movs r0, #1
	strb r0, [r1]
	b _08075FC6
	.align 2, 0
_08075FB0: .4byte 0x000002E6
_08075FB4: .4byte 0x000002E7
_08075FB8:
	ldr r4, _0807601C @ =0x000002E6
	adds r0, r6, r4
	movs r1, #0
	strb r2, [r0]
	ldr r2, _08076020 @ =0x000002E7
	adds r0, r6, r2
	strb r1, [r0]
_08075FC6:
	movs r3, #0xcf
	lsls r3, r3, #2
	adds r4, r6, r3
	movs r1, #0xd4
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r1, [r0]
	ldr r2, _0807601C @ =0x000002E6
	adds r0, r6, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r6, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_08236fac
	adds r5, r6, #0
	adds r5, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08076024
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0807602C
	.align 2, 0
_0807601C: .4byte 0x000002E6
_08076020: .4byte 0x000002E7
_08076024:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0807602C:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08076050
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08076058
_08076050:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08076058:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _08076090 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080760C8
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08076094
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08076088
	ldrb r0, [r4, #5]
_08076088:
	subs r0, #1
	strh r0, [r4, #8]
	b _080760A4
	.align 2, 0
_08076090: .4byte 0x0000FFFF
_08076094:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080760A4
	strh r1, [r4, #8]
_080760A4:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080760C8
	movs r0, #1
	strb r0, [r4, #7]
_080760C8:
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
	movs r3, #0x93
	lsls r3, r3, #3
	adds r1, r6, r3
	ldr r0, _080760E4 @ =FUN_08075df8
	str r0, [r1]
	adds r0, r6, #0
	bl FUN_080726b4
	b _080762F0
	.align 2, 0
_080760E4: .4byte FUN_08075df8
_080760E8:
	ldr r2, _08076108 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	cmp r0, #0
	blt _0807610C
	asrs r0, r0, #0xc
	b _08076112
	.align 2, 0
_08076108: .4byte 0x085B0A08
_0807610C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08076112:
	strh r0, [r6, #0x34]
	movs r0, #0xff
	ands r0, r3
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	cmp r0, #0
	blt _0807612E
	asrs r0, r0, #0xc
	b _08076134
_0807612E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08076134:
	strh r0, [r6, #0x38]
	ldr r4, _08076154 @ =0x000001C7
	adds r1, r6, r4
	ldrb r1, [r1]
	cmp r1, #1
	bne _08076172
	cmp r0, #0
	bge _08076158
	movs r0, #0x38
	ldrsh r1, [r6, r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	bge _08076164
	b _08076168
	.align 2, 0
_08076154: .4byte 0x000001C7
_08076158:
	movs r2, #0x38
	ldrsh r1, [r6, r2]
	movs r0, #0x34
	muls r0, r1, r0
	cmp r0, #0
	blt _08076168
_08076164:
	asrs r0, r0, #6
	b _0807616E
_08076168:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_0807616E:
	strh r0, [r6, #0x38]
	b _080761A4
_08076172:
	cmp r1, #2
	bne _080761A4
	movs r4, #0x34
	ldrsh r0, [r6, r4]
	cmp r0, #0
	bge _0807618C
	adds r1, r0, #0
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	bge _08076198
	b _0807619C
_0807618C:
	movs r2, #0x34
	ldrsh r1, [r6, r2]
	movs r0, #0x34
	muls r0, r1, r0
	cmp r0, #0
	blt _0807619C
_08076198:
	asrs r0, r0, #6
	b _080761A2
_0807619C:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_080761A2:
	strh r0, [r6, #0x34]
_080761A4:
	lsls r0, r3, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	movs r3, #0xba
	lsls r3, r3, #2
	adds r0, r6, r3
	adds r2, r1, #0
	strb r1, [r0]
	cmp r2, #4
	bls _080761E0
	movs r0, #8
	subs r0, r0, r2
	ldr r4, _080761D8 @ =0x000002E6
	adds r1, r6, r4
	strb r0, [r1]
	ldr r0, _080761DC @ =0x000002E7
	adds r1, r6, r0
	movs r0, #1
	b _080761EC
	.align 2, 0
_080761D8: .4byte 0x000002E6
_080761DC: .4byte 0x000002E7
_080761E0:
	ldr r2, _08076244 @ =0x000002E6
	adds r0, r6, r2
	strb r1, [r0]
	ldr r3, _08076248 @ =0x000002E7
	adds r1, r6, r3
	movs r0, #0
_080761EC:
	strb r0, [r1]
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r4, r6, r0
	movs r1, #0xd4
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r1, [r0]
	ldr r2, _08076244 @ =0x000002E6
	adds r0, r6, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r6, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #1
	bl FUN_08236fac
	adds r5, r6, #0
	adds r5, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0807624C
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08076254
	.align 2, 0
_08076244: .4byte 0x000002E6
_08076248: .4byte 0x000002E7
_0807624C:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08076254:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08076278
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08076280
_08076278:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08076280:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _080762B8 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080762F0
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080762BC
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080762B0
	ldrb r0, [r4, #5]
_080762B0:
	subs r0, #1
	strh r0, [r4, #8]
	b _080762CC
	.align 2, 0
_080762B8: .4byte 0x0000FFFF
_080762BC:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080762CC
	strh r1, [r4, #8]
_080762CC:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080762F0
	movs r0, #1
	strb r0, [r4, #7]
_080762F0:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
