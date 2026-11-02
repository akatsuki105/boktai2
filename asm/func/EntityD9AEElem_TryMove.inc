	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r5, r0, #0
	adds r4, r1, #0
	mov r8, r2
	movs r0, #0xbc
	adds r0, r0, r5
	mov sl, r0
	movs r1, #0
	movs r2, #0
	str r2, [sp]
	movs r0, #0
	str r0, [sp, #4]
	ldr r0, _08003BB4 @ =0x03002B8C
	ldrh r0, [r0]
	cmp r0, #0
	beq _08003BA4
	ldr r0, _08003BB8 @ =0x03002B60
	ldrh r0, [r0]
	cmp r0, #2
	bne _08003BA4
	movs r2, #1
_08003BA4:
	cmp r2, #0
	bne _08003BAE
	ldrb r0, [r5]
	cmp r0, #1
	bne _08003BBC
_08003BAE:
	movs r0, #0x10
	movs r2, #0x10
	b _08003BC0
	.align 2, 0
_08003BB4: .4byte 0x03002B8C
_08003BB8: .4byte 0x03002B60
_08003BBC:
	movs r0, #4
	movs r2, #0x40
_08003BC0:
	str r2, [sp, #8]
	mov r2, r8
	cmp r2, #1
	beq _08003BF4
	cmp r2, #1
	bgt _08003BD2
	cmp r2, #0
	beq _08003BDE
	b _08003C14
_08003BD2:
	mov r2, r8
	cmp r2, #2
	beq _08003BFA
	cmp r2, #3
	beq _08003C0C
	b _08003C14
_08003BDE:
	rsbs r0, r0, #0
	str r0, [sp, #4]
	ldr r0, _08003BF0 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	rsbs r1, r0, #0
	b _08003C14
	.align 2, 0
_08003BF0: .4byte 0x030046A4
_08003BF4:
	str r0, [sp]
	movs r1, #1
	b _08003C14
_08003BFA:
	str r0, [sp, #4]
	ldr r0, _08003C08 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	b _08003C14
	.align 2, 0
_08003C08: .4byte 0x030046A4
_08003C0C:
	rsbs r0, r0, #0
	str r0, [sp]
	movs r1, #1
	rsbs r1, r1, #0
_08003C14:
	adds r4, r4, r1
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	mov sb, r4
	cmp r0, #0
	beq _08003C28
	adds r6, r0, #4
	b _08003C36
_08003C28:
	ldr r0, _08003CA4 @ =0x030046A4
	ldr r1, [r0]
	mov r2, sb
	lsls r0, r2, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r6, r1, r0
_08003C36:
	cmp r6, #0
	beq _08003D06
	ldrb r1, [r6]
	movs r4, #0xf0
	lsrs r7, r1, #4
	cmp r7, #0
	bne _08003D04
	movs r0, #0xf
	mov ip, r0
	mov r2, sl
	ldrb r0, [r2]
	mov r3, ip
	ands r3, r1
	mov r2, ip
	ands r2, r0
	cmp r3, r2
	bhs _08003D06
	ldrh r1, [r6, #2]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _08003D06
	subs r0, r2, r3
	cmp r0, #1
	ble _08003CAC
	lsls r0, r3, #8
	strh r0, [r5, #0x12]
	mov r0, r8
	strb r0, [r5, #0x10]
	ldr r1, _08003CA8 @ =EntityD9AEElem_UpdateMove
	movs r2, #0xcc
	lsls r2, r2, #1
	adds r0, r5, r2
	str r1, [r0]
	strh r7, [r5, #2]
	movs r0, #1
	strb r0, [r5, #0x11]
	mov r0, sp
	ldrh r0, [r0]
	strh r0, [r5, #0xc]
	mov r1, sp
	ldrh r1, [r1, #4]
	strh r1, [r5, #0xe]
	movs r0, #2
	strh r0, [r5, #4]
	adds r0, r5, #0
	adds r0, #0xba
	mov r2, sb
	strh r2, [r0]
	mov r0, sp
	ldrh r0, [r0, #8]
	strh r0, [r5, #0x14]
	movs r0, #3
	b _08003D08
	.align 2, 0
_08003CA4: .4byte 0x030046A4
_08003CA8: .4byte EntityD9AEElem_UpdateMove
_08003CAC:
	lsls r0, r3, #8
	strh r0, [r5, #0x12]
	mov r2, sl
	ldrb r1, [r2]
	mov r0, ip
	ands r0, r1
	cmp r0, #0
	ble _08003CBE
	subs r0, #1
_08003CBE:
	ands r4, r1
	orrs r4, r0
	mov r0, sl
	strb r4, [r0]
	ldrb r0, [r6, #1]
	mov r1, sl
	strb r0, [r1, #1]
	mov r2, r8
	strb r2, [r5, #0x10]
	ldr r1, _08003D00 @ =EntityD9AEElem_UpdateMove
	movs r2, #0xcc
	lsls r2, r2, #1
	adds r0, r5, r2
	str r1, [r0]
	strh r7, [r5, #2]
	movs r0, #1
	strb r0, [r5, #0x11]
	mov r1, sp
	ldrh r1, [r1]
	strh r1, [r5, #0xc]
	mov r2, sp
	ldrh r2, [r2, #4]
	strh r2, [r5, #0xe]
	strh r0, [r5, #4]
	adds r0, r5, #0
	adds r0, #0xba
	mov r1, sb
	strh r1, [r0]
	mov r2, sp
	ldrh r2, [r2, #8]
	strh r2, [r5, #0x14]
	movs r0, #1
	b _08003D08
	.align 2, 0
_08003D00: .4byte EntityD9AEElem_UpdateMove
_08003D04:
	subs r0, r7, #1
_08003D06:
	movs r0, #0
_08003D08:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
