	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x34
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	mov r8, r0
	mov sl, r6
	ldr r2, _08117F24 @ =0x0000046D
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08117F28
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08117F2A
	.align 2, 0
_08117F24: .4byte 0x0000046D
_08117F28:
	movs r0, #0
_08117F2A:
	cmp r0, #0
	beq _08117F72
	ldr r3, _08117FD4 @ =0x0000046B
	adds r0, r6, r3
	movs r1, #0
	strb r1, [r0]
	ldr r7, _08117FD8 @ =0x0000046E
	adds r0, r6, r7
	strb r1, [r0]
	ldr r0, _08117FDC @ =0x000006C1
	add r0, r8
	strb r1, [r0]
	ldr r0, _08117FE0 @ =0x000006C4
	add r0, r8
	ldrb r0, [r0]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	movs r0, #0xd8
	lsls r0, r0, #3
	add r0, r8
	strb r1, [r0]
	movs r0, #0xda
	lsls r0, r0, #3
	add r0, r8
	mov r3, sl
	ldr r1, [r3, #8]
	ldr r2, [r3, #0xc]
	str r1, [r0]
	str r2, [r0, #4]
	bl Golem_SnapToTileCenter
_08117F72:
	movs r0, #0x80
	lsls r0, r0, #1
	movs r7, #0xc0
	lsls r7, r7, #1
	adds r5, r6, r7
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
	mov r4, sp
	adds r4, #5
	adds r0, r6, #0
	add r1, sp, #4
	adds r2, r4, #0
	bl Enemy_SetAnimFacing
	add r0, sp, #4
	ldrb r3, [r0]
	ldrb r2, [r4]
	ldr r1, _08117FE4 @ =0x085AD608
	lsls r0, r2, #1
	adds r0, r0, r1
	ldrh r4, [r0]
	movs r0, #8
	mov sb, r0
	orrs r4, r2
	ldr r1, _08117FE8 @ =0x0000025D
	adds r0, r6, r1
	ldrb r1, [r0]
	str r5, [sp, #0x2c]
	str r0, [sp, #0x30]
	cmp r1, #0
	bne _08117FF0
	ldr r2, _08117FEC @ =0x000004B7
	adds r0, r6, r2
	mov r7, sb
	strb r7, [r0]
	ldr r1, [r6, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r2, r4, #0x18
	lsrs r2, r2, #0x18
	str r2, [sp]
	movs r2, #8
	bl AuxAnim_SetAnim
	ldr r0, _08117FD8 @ =0x0000046E
	adds r7, r6, r0
	b _08118072
	.align 2, 0
_08117FD4: .4byte 0x0000046B
_08117FD8: .4byte 0x0000046E
_08117FDC: .4byte 0x000006C1
_08117FE0: .4byte 0x000006C4
_08117FE4: .4byte 0x085AD608
_08117FE8: .4byte 0x0000025D
_08117FEC: .4byte 0x000004B7
_08117FF0:
	ldr r0, [r6, #0x44]
	adds r5, r0, #0
	adds r5, #0x20
	adds r3, #8
	mov sb, r3
	ldr r1, _08118060 @ =0x000004B7
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r2, r0, #0
	ldr r3, _08118064 @ =0x0000046E
	adds r7, r6, r3
	cmp r1, sb
	bne _0811802C
	ldrb r0, [r7]
	cmp r0, #0
	bne _0811802C
	cmp r4, #1
	bne _0811801E
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _08118076
_0811801E:
	cmp r4, #0
	bne _0811802C
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08118076
_0811802C:
	mov r0, sb
	strb r0, [r2]
	adds r0, r4, #0
	movs r1, #4
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _0811803E
	movs r3, #6
_0811803E:
	ldr r1, [r6, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	mov r2, sb
	str r3, [sp]
	movs r3, #2
	bl MainSprite_SetAnim
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _08118068
	ldr r0, [r5, #8]
	movs r2, #4
	orrs r0, r2
	b _08118070
	.align 2, 0
_08118060: .4byte 0x000004B7
_08118064: .4byte 0x0000046E
_08118068:
	ldr r0, [r5, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08118070:
	str r0, [r5, #8]
_08118072:
	movs r0, #0
	strb r0, [r7]
_08118076:
	ldr r3, _0811809C @ =0x000006C1
	add r3, r8
	ldrb r2, [r3]
	cmp r2, #0
	beq _08118082
	b _081181A8
_08118082:
	ldr r1, _081180A0 @ =0x000006B6
	add r1, r8
	ldrh r0, [r1]
	subs r0, #0x28
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _081180A4
	movs r0, #1
	strb r0, [r3]
	strh r2, [r1]
	b _081183C0
	.align 2, 0
_0811809C: .4byte 0x000006C1
_081180A0: .4byte 0x000006B6
_081180A4:
	movs r3, #0
	ldrsh r5, [r1, r3]
	ldr r4, _08118144 @ =gSineTable
	ldr r0, _08118148 @ =0x000006C5
	add r0, r8
	ldrb r2, [r0]
	adds r0, r2, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r7, #0
	ldrsh r0, [r0, r7]
	adds r1, r5, #0
	muls r1, r0, r1
	lsrs r1, r1, #0x10
	ldr r3, _0811814C @ =0xFFFF0000
	adds r0, r3, #0
	ldr r7, [sp, #0x20]
	ands r0, r7
	orrs r0, r1
	str r0, [sp, #0x20]
	lsls r2, r2, #1
	adds r2, r2, r4
	movs r1, #0
	ldrsh r0, [r2, r1]
	adds r1, r5, #0
	muls r1, r0, r1
	lsrs r1, r1, #0x10
	adds r0, r3, #0
	ldr r2, [sp, #0x24]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x24]
	ldr r0, [r6, #8]
	ldr r1, [r6, #0xc]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	add r2, sp, #8
	mov r7, sp
	ldrh r0, [r7, #0x20]
	ldrh r1, [r2]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #8]
	ands r1, r3
	orrs r1, r0
	str r1, [sp, #8]
	ldrh r0, [r7, #0x24]
	ldrh r7, [r2, #4]
	adds r0, r0, r7
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [r2, #4]
	ands r1, r3
	orrs r1, r0
	str r1, [r2, #4]
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r3, #0
	blt _0811813E
	cmp r1, #0
	blt _0811813E
	ldr r0, _08118150 @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _0811813E
	ldr r0, _08118154 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08118158
_0811813E:
	movs r1, #0
	b _08118166
	.align 2, 0
_08118144: .4byte gSineTable
_08118148: .4byte 0x000006C5
_0811814C: .4byte 0xFFFF0000
_08118150: .4byte 0x030046A8
_08118154: .4byte 0x030046AC
_08118158:
	ldr r0, _08118184 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r3
_08118166:
	ldr r2, _08118188 @ =0x00000256
	adds r0, r6, r2
	ldrh r0, [r0]
	cmp r0, r1
	beq _08118194
	ldr r1, _0811818C @ =0x000006B6
	add r1, r8
	movs r0, #0
	strh r0, [r1]
	ldr r1, _08118190 @ =0x000006C1
	add r1, r8
	movs r0, #1
	strb r0, [r1]
	b _08118340
	.align 2, 0
_08118184: .4byte 0x030046A4
_08118188: .4byte 0x00000256
_0811818C: .4byte 0x000006B6
_08118190: .4byte 0x000006C1
_08118194:
	mov r3, sp
	ldrh r0, [r3, #0x20]
	ldrh r7, [r6, #0x10]
	adds r0, r0, r7
	strh r0, [r6, #0x10]
	ldrh r0, [r3, #0x24]
	ldrh r1, [r6, #0x14]
	adds r0, r0, r1
	strh r0, [r6, #0x14]
	b _08118340
_081181A8:
	cmp r2, #1
	beq _081181AE
	b _081182DC
_081181AE:
	ldr r2, _081181F4 @ =0x00000256
	adds r0, r6, r2
	ldrh r5, [r0]
	add r7, sp, #0x10
	ldr r3, _081181F8 @ =0x030046A4
	mov sb, r3
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	mov r3, sb
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	str r0, [sp, #0x28]
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r7]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	adds r4, r7, #0
	cmp r0, #0
	beq _081181FC
	adds r0, #4
	b _08118208
	.align 2, 0
_081181F4: .4byte 0x00000256
_081181F8: .4byte 0x030046A4
_081181FC:
	mov r3, sb
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08118208:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r7, #2]
	ldr r1, [sp, #0x28]
	lsls r0, r1, #8
	adds r0, #0x80
	strh r0, [r7, #4]
	add r2, sp, #0x18
	adds r3, r6, #0
	adds r3, #8
	add r0, sp, #0x10
	ldrh r0, [r0]
	ldrh r1, [r6, #8]
	subs r0, r0, r1
	strh r0, [r2]
	ldrh r0, [r4, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r4, #4]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	ldr r0, _08118250 @ =0x000006C5
	add r0, r8
	ldrb r0, [r0]
	lsrs r0, r0, #6
	cmp r0, #1
	beq _0811828A
	cmp r0, #1
	bgt _08118254
	cmp r0, #0
	beq _0811825E
	b _081182B4
	.align 2, 0
_08118250: .4byte 0x000006C5
_08118254:
	cmp r0, #2
	beq _0811825E
	cmp r0, #3
	beq _0811828A
	b _081182B4
_0811825E:
	movs r0, #0
	strh r0, [r2, #4]
	add r0, sp, #0x18
	ldrh r3, [r0]
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp r0, #8
	ble _08118276
	movs r0, #8
	mov r1, sl
	strh r0, [r1, #0x10]
	b _081182B4
_08118276:
	movs r1, #8
	rsbs r1, r1, #0
	cmp r0, r1
	bge _08118284
	mov r3, sl
	strh r1, [r3, #0x10]
	b _081182B4
_08118284:
	mov r7, sl
	strh r3, [r7, #0x10]
	b _081182B4
_0811828A:
	movs r0, #0
	strh r0, [r2]
	add r0, sp, #0x18
	ldrh r3, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	cmp r0, #8
	ble _081182A2
	movs r0, #8
	mov r3, sl
	strh r0, [r3, #0x14]
	b _081182B4
_081182A2:
	movs r1, #8
	rsbs r1, r1, #0
	cmp r0, r1
	bge _081182B0
	mov r7, sl
	strh r1, [r7, #0x14]
	b _081182B4
_081182B0:
	mov r0, sl
	strh r3, [r0, #0x14]
_081182B4:
	movs r1, #0
	ldrsh r0, [r2, r1]
	add r1, sp, #0x18
	movs r2, #4
	ldrsh r1, [r1, r2]
	adds r2, r0, r1
	cmp r2, #0
	bne _08118340
	ldr r0, _081182D4 @ =0x000006C1
	add r0, r8
	movs r1, #2
	strb r1, [r0]
	ldr r0, _081182D8 @ =0x000006C3
	add r0, r8
	strb r2, [r0]
	b _081183C0
	.align 2, 0
_081182D4: .4byte 0x000006C1
_081182D8: .4byte 0x000006C3
_081182DC:
	ldr r4, _0811832C @ =0x000006C3
	add r4, r8
	ldrb r0, [r4]
	adds r0, #1
	movs r5, #0
	strb r0, [r4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xf
	bls _08118340
	movs r2, #0xda
	lsls r2, r2, #3
	add r2, r8
	movs r0, #0xd9
	lsls r0, r0, #3
	add r0, r8
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	mov r0, r8
	bl Golem_RouteTo
	ldr r2, _08118330 @ =0x000006C2
	add r2, r8
	ldrb r1, [r2]
	ldr r0, _08118334 @ =0x000006C4
	add r0, r8
	strb r1, [r0]
	ldrb r0, [r2]
	strb r0, [r6, #5]
	ldr r3, _08118338 @ =0x0000046B
	adds r1, r6, r3
	movs r0, #1
	strb r0, [r1]
	strb r5, [r4]
	ldr r0, _0811833C @ =0x000006B6
	add r0, r8
	strh r5, [r0]
	b _081183C0
	.align 2, 0
_0811832C: .4byte 0x000006C3
_08118330: .4byte 0x000006C2
_08118334: .4byte 0x000006C4
_08118338: .4byte 0x0000046B
_0811833C: .4byte 0x000006B6
_08118340:
	movs r0, #0xd7
	lsls r0, r0, #3
	add r0, r8
	ldrh r0, [r0]
	lsrs r0, r0, #7
	ldr r7, _08118368 @ =0x00000482
	adds r1, r6, r7
	strh r0, [r1]
	ldr r1, _0811836C @ =0x0000A02F
	ldr r2, [sp, #0x2c]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08118370
	adds r3, r7, #0
	adds r1, r6, r3
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _08118380
	.align 2, 0
_08118368: .4byte 0x00000482
_0811836C: .4byte 0x0000A02F
_08118370:
	ldr r7, _081183A4 @ =0x00000482
	adds r0, r6, r7
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _08118380
	movs r0, #1
	strh r0, [r2]
_08118380:
	ldr r1, [sp, #0x30]
	ldrb r0, [r1]
	cmp r0, #0
	bne _081183A8
	ldr r4, [r6, #0x44]
	adds r4, #0x48
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl AuxAnim_SetAnimSpeed
	b _081183C0
	.align 2, 0
_081183A4: .4byte 0x00000482
_081183A8:
	ldr r4, [r6, #0x44]
	adds r4, #0x20
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl MainSprite_SetAnimSpeed
_081183C0:
	add sp, #0x34
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
