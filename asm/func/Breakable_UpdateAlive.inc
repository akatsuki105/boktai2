	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x34
	mov sb, r1
	mov r0, sb
	bl Breakable_TakeStateChanged
	mov r1, sb
	movs r2, #4
	ldrsh r0, [r1, r2]
	cmp r0, #0
	ble _08007A60
	b _08007B88
_08007A60:
	ldrh r0, [r1, #0xc]
	cmp r0, #0
	beq _08007A84
	ldrh r0, [r1]
	str r0, [sp, #0x20]
	ldr r1, _08007B7C @ =0xFFFF0000
	ldr r0, [sp, #0x24]
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	str r0, [sp, #0x24]
	add r1, sp, #0x24
	add r0, sp, #0x20
	str r0, [r1, #4]
	mov r2, sb
	ldrh r0, [r2, #0xc]
	bl Script_ExecById
_08007A84:
	mov r0, sb
	ldrb r1, [r0, #0xa]
	adds r0, #0x3c
	strh r1, [r0, #0x10]
	mov r2, sb
	adds r2, #0x6e
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _08007B80 @ =Breakable_UpdateIdle
	mov r0, sb
	bl Breakable_SetUpdate
	mov r0, sb
	adds r0, #0x20
	movs r1, #6
	bl Video_SetAuxSpritePltt
	mov r2, sb
	ldr r0, [r2, #0x10]
	ldr r1, [r2, #0x14]
	str r0, [sp, #0x2c]
	str r1, [sp, #0x30]
	add r5, sp, #0x2c
	ldrh r0, [r5]
	subs r0, #0x80
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, _08007B7C @ =0xFFFF0000
	ldr r1, [sp, #0x2c]
	ands r1, r3
	orrs r1, r0
	lsrs r2, r1, #0x10
	lsls r2, r2, #0x10
	ldr r0, _08007B84 @ =0x0000FFFF
	ands r0, r1
	orrs r0, r2
	str r0, [sp, #0x2c]
	ldrh r0, [r5, #4]
	adds r0, #0x80
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [r5, #4]
	ands r1, r3
	orrs r1, r0
	str r1, [r5, #4]
	movs r0, #0x80
	lsls r0, r0, #6
	mov sl, r0
	movs r1, #0
	str r1, [sp]
	movs r6, #0x80
	lsls r6, r6, #1
	str r6, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	movs r7, #3
	str r7, [sp, #0xc]
	movs r2, #0xc
	mov sb, r2
	str r2, [sp, #0x10]
	movs r0, #6
	str r0, [sp, #0x14]
	str r5, [sp, #0x18]
	movs r0, #4
	movs r1, #1
	mov r2, sl
	movs r3, #0x40
	bl FUN_08015ce0
	movs r1, #0
	str r1, [sp]
	str r6, [sp, #4]
	movs r4, #4
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	movs r2, #0xa
	mov r8, r2
	str r2, [sp, #0x10]
	str r4, [sp, #0x14]
	str r5, [sp, #0x18]
	movs r0, #6
	movs r1, #1
	mov r2, sl
	movs r3, #0x40
	bl FUN_08015ce0
	str r6, [sp]
	movs r0, #0x10
	str r0, [sp, #4]
	str r4, [sp, #8]
	mov r0, sb
	str r0, [sp, #0xc]
	str r7, [sp, #0x10]
	movs r0, #0x1e
	str r0, [sp, #0x14]
	movs r0, #0xf
	str r0, [sp, #0x18]
	movs r0, #4
	movs r1, #3
	adds r2, r5, #0
	movs r3, #0
	bl Entity080146e0_SpawnAtAngle
	movs r0, #0x14
	str r0, [sp]
	str r4, [sp, #4]
	mov r1, r8
	str r1, [sp, #8]
	movs r2, #6
	str r2, [sp, #0xc]
	movs r1, #0
	str r1, [sp, #0x10]
	str r6, [sp, #0x14]
	str r0, [sp, #0x18]
	str r4, [sp, #0x1c]
	movs r0, #4
	movs r1, #6
	adds r2, r5, #0
	movs r3, #0
	bl FUN_08014da0
	b _08007C1E
	.align 2, 0
_08007B7C: .4byte 0xFFFF0000
_08007B80: .4byte Breakable_UpdateIdle
_08007B84: .4byte 0x0000FFFF
_08007B88:
	mov r2, sb
	ldrb r0, [r2, #9]
	cmp r0, #0
	beq _08007BA4
	subs r0, #1
	strb r0, [r2, #9]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08007BA4
	mov r0, sb
	adds r0, #0x20
	movs r1, #6
	bl Video_SetAuxSpritePltt
_08007BA4:
	mov r1, sb
	ldrb r0, [r1, #0xb]
	cmp r0, #0
	beq _08007C1E
	subs r0, #1
	strb r0, [r1, #0xb]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08007BC8
	mov r2, sb
	adds r2, #0x6e
	ldrh r1, [r2]
	ldr r0, _08007BC4 @ =0x0000FFFB
	ands r0, r1
	b _08007BD2
	.align 2, 0
_08007BC4: .4byte 0x0000FFFB
_08007BC8:
	mov r2, sb
	adds r2, #0x6e
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
_08007BD2:
	strh r0, [r2]
	mov r2, sb
	ldr r0, [r2, #0x10]
	ldr r1, [r2, #0x14]
	str r0, [r2, #0x58]
	str r1, [r2, #0x5c]
	ldr r0, _08007C30 @ =0x0203B400
	mov r8, r0
	ldr r4, _08007C34 @ =0x030046B8
	ldr r1, [r4]
	adds r1, #1
	ldr r6, _08007C38 @ =0x000003FF
	ands r1, r6
	str r1, [r4]
	lsls r0, r1, #1
	add r0, r8
	ldrh r2, [r0]
	mov r3, sb
	adds r3, #0x58
	ldrh r0, [r3]
	subs r0, #8
	movs r5, #0xf
	ands r2, r5
	adds r0, r0, r2
	strh r0, [r3]
	adds r1, #1
	ands r1, r6
	str r1, [r4]
	lsls r1, r1, #1
	add r1, r8
	ldrh r1, [r1]
	mov r2, sb
	adds r2, #0x5c
	ldrh r0, [r2]
	subs r0, #8
	ands r1, r5
	adds r0, r0, r1
	strh r0, [r2]
_08007C1E:
	add sp, #0x34
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08007C30: .4byte 0x0203B400
_08007C34: .4byte 0x030046B8
_08007C38: .4byte 0x000003FF
