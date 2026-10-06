	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	adds r7, r0, #0
	bl FUN_08018a08
	adds r1, r7, #0
	adds r1, #0x25
	strb r0, [r1]
	bl Time_GetHour
	adds r1, r7, #0
	adds r1, #0x20
	strb r0, [r1]
	bl Time_GetMinute
	adds r1, r7, #0
	adds r1, #0x21
	strb r0, [r1]
	ldrb r1, [r7, #0x1f]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r1, r0
	beq _08046DAE
	movs r0, #1
	b _08046DB0
_08046DAE:
	movs r0, #0
_08046DB0:
	strb r0, [r7, #0x1e]
	adds r0, r7, #0
	adds r0, #0x21
	ldrb r0, [r0]
	strb r0, [r7, #0x1f]
	ldr r0, _08046E64 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _08046DCA
	b _08046FA8
_08046DCA:
	movs r0, #0x96
	lsls r0, r0, #1
	adds r6, r7, r0
	movs r1, #0
	str r1, [sp, #0x10]
	movs r2, #0xa9
	lsls r2, r2, #2
	adds r2, r2, r7
	mov sl, r2
	movs r3, #0xa8
	lsls r3, r3, #2
	adds r4, r7, r3
	adds r0, #0x37
	adds r0, r0, r7
	mov sb, r0
	movs r1, #0xc6
	lsls r1, r1, #1
	adds r1, r1, r7
	mov r8, r1
_08046DF0:
	ldrb r0, [r6, #9]
	cmp r0, #0
	bne _08046DF8
	b _08046F76
_08046DF8:
	mov r2, r8
	str r2, [sp, #0x14]
	adds r3, r6, #0
	adds r3, #0xa4
	str r3, [sp, #0x18]
	movs r0, #0
	mov r1, sb
	strb r0, [r1]
	ldr r1, _08046E68 @ =0x085AB434
	ldrb r0, [r6, #4]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r3, [r0]
	adds r0, r7, #0
	adds r1, r6, #0
	ldr r2, [sp, #0x10]
	bl _call_via_r3
	ldrb r0, [r6, #4]
	mov r2, r8
	str r2, [sp, #0x20]
	mov r1, sb
	adds r3, r1, #0
	str r3, [sp, #0x1c]
	cmp r0, #8
	bne _08046E2E
	b _08046F70
_08046E2E:
	mov r0, r8
	bl Mover_ApplyMove
	adds r3, r6, #0
	adds r3, #0x68
	mov r2, r8
	ldrh r0, [r2, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	mov r1, r8
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08046E60
	cmp r1, #0
	blt _08046E60
	ldr r0, _08046E6C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08046E60
	ldr r0, _08046E70 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08046E74
_08046E60:
	movs r5, #0
	b _08046E82
	.align 2, 0
_08046E64: .4byte 0x030047A4
_08046E68: .4byte 0x085AB434
_08046E6C: .4byte 0x030046A8
_08046E70: .4byte 0x030046AC
_08046E74:
	ldr r0, _08046E98 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_08046E82:
	adds r0, r5, #0
	movs r1, #1
	str r3, [sp, #0x24]
	bl Map_FindTileOverride
	ldr r3, [sp, #0x24]
	cmp r0, #0
	beq _08046E9C
	adds r0, #4
	b _08046EA8
	.align 2, 0
_08046E98: .4byte 0x030046A4
_08046E9C:
	ldr r0, _08046EBC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08046EA8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08046EC0
	cmp r2, #2
	beq _08046EC4
	b _08046EC8
	.align 2, 0
_08046EBC: .4byte 0x030046A4
_08046EC0:
	ldrb r0, [r3, #4]
	b _08046EC6
_08046EC4:
	ldrb r0, [r3]
_08046EC6:
	subs r1, r1, r0
_08046EC8:
	ldr r2, [sp, #0x14]
	strh r1, [r2, #0xa]
	ldr r0, [r2, #8]
	ldr r1, [r2, #0xc]
	ldr r3, [sp, #0x18]
	str r0, [r3, #0x20]
	str r1, [r3, #0x24]
	ldrb r1, [r6, #7]
	lsls r1, r1, #5
	ldr r0, _08046F30 @ =0x0000192C
	adds r1, r1, r0
	adds r1, r7, r1
	ldr r0, [sp, #0x18]
	bl MainSprite_AdvanceAnim
	ldr r0, _08046F34 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _08046F70
	ldr r1, [sp, #0x1c]
	ldrb r5, [r1]
	cmp r5, #0
	beq _08046F4A
	ldrh r5, [r4]
	cmp r5, #0
	bne _08046F38
	ldrh r0, [r4, #6]
	strh r0, [r4, #4]
	ldr r0, [r4, #8]
	ldrb r2, [r4, #2]
	ldrb r3, [r4, #3]
	mov ip, r3
	mov r1, sl
	str r1, [sp]
	movs r3, #6
	ldrsh r1, [r4, r3]
	str r1, [sp, #4]
	str r5, [sp, #8]
	movs r1, #0x64
	str r1, [sp, #0xc]
	ldr r1, [sp, #0x20]
	mov r3, ip
	bl FUN_080da9c4
	str r0, [r4, #8]
	movs r0, #1
	strh r0, [r4]
	b _08046F70
	.align 2, 0
_08046F30: .4byte 0x0000192C
_08046F34: .4byte 0x030047A4
_08046F38:
	ldrh r0, [r4, #4]
	subs r0, #1
	strh r0, [r4, #4]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08046F70
	ldrh r0, [r4, #6]
	strh r0, [r4, #4]
	b _08046F70
_08046F4A:
	ldrh r0, [r4]
	cmp r0, #0
	beq _08046F70
	ldr r0, [r4, #8]
	ldrb r2, [r4, #2]
	mov r1, sl
	str r1, [sp]
	movs r3, #6
	ldrsh r1, [r4, r3]
	str r1, [sp, #4]
	str r5, [sp, #8]
	movs r1, #0x64
	str r1, [sp, #0xc]
	ldr r1, [sp, #0x20]
	movs r3, #0x7f
	bl FUN_080da9c4
	str r0, [r4, #8]
	strh r5, [r4]
_08046F70:
	ldr r0, [r6, #0x10]
	adds r0, #1
	str r0, [r6, #0x10]
_08046F76:
	ldr r0, [sp, #0x10]
	adds r0, #1
	str r0, [sp, #0x10]
	movs r1, #0xc0
	lsls r1, r1, #1
	add sl, r1
	adds r4, r4, r1
	add sb, r1
	add r8, r1
	adds r6, r6, r1
	cmp r0, #0xf
	bgt _08046F90
	b _08046DF0
_08046F90:
	ldr r0, _08046FBC @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08046FA2
	adds r0, r7, #0
	bl FUN_08045408
_08046FA2:
	ldr r0, [r7, #0x28]
	adds r0, #1
	str r0, [r7, #0x28]
_08046FA8:
	movs r0, #0
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08046FBC: .4byte 0x030044E0
