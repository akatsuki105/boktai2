	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	ldr r0, _08010DE8 @ =gClock
	cmp r0, #0
	bne _08010DC0
	b _08010F56
_08010DC0:
	ldrb r0, [r0, #0xe]
	cmp r0, #0
	beq _08010DCE
	cmp r0, #4
	beq _08010DCE
	cmp r0, #5
	bne _08010DEC
_08010DCE:
	movs r0, #0
	movs r1, #4
	movs r2, #0xf
	bl SunCountdown_GetTilePtr
	adds r5, r0, #0
	ldr r1, _08010DE8 @ =gClock
	ldrb r1, [r1, #0x12]
	mov r8, r1
	ldr r2, _08010DE8 @ =gClock
	ldrb r2, [r2, #0x13]
	mov sl, r2
	b _08010E04
	.align 2, 0
_08010DE8: .4byte gClock
_08010DEC:
	movs r0, #0
	movs r1, #4
	movs r2, #0xf
	bl SunCountdown_GetTilePtr
	adds r5, r0, #0
	ldr r7, _08010E5C @ =gClock
	ldrb r7, [r7, #0x10]
	mov r8, r7
	ldr r0, _08010E5C @ =gClock
	ldrb r0, [r0, #0x11]
	mov sl, r0
_08010E04:
	movs r4, #0
	ldr r1, _08010E60 @ =0xFFFFD000
	mov ip, r1
	movs r6, #0x6a
	ldr r2, _08010E64 @ =0x03003ED0
	mov sb, r2
_08010E10:
	movs r2, #0
	adds r3, r6, #0
	adds r1, r5, #0
_08010E16:
	adds r0, r3, r2
	mov r7, ip
	orrs r0, r7
	strh r0, [r1]
	adds r1, #2
	adds r2, #1
	cmp r2, #3
	ble _08010E16
	mov r1, sb
	movs r2, #0x18
	ldrsh r0, [r1, r2]
	lsls r0, r0, #2
	adds r5, r5, r0
	adds r6, #0x10
	adds r4, #1
	cmp r4, #1
	ble _08010E10
	movs r0, #0
	movs r1, #8
	movs r2, #0xf
	bl SunCountdown_GetTilePtr
	adds r5, r0, #0
	ldr r7, _08010E5C @ =gClock
	ldrb r0, [r7, #0xe]
	cmp r0, #0
	beq _08010E54
	cmp r0, #4
	beq _08010E54
	cmp r0, #5
	bne _08010E68
_08010E54:
	movs r0, #2
	mov ip, r0
	movs r0, #0x6e
	b _08010E6E
	.align 2, 0
_08010E5C: .4byte gClock
_08010E60: .4byte 0xFFFFD000
_08010E64: .4byte 0x03003ED0
_08010E68:
	movs r1, #2
	mov ip, r1
	movs r0, #0x4e
_08010E6E:
	movs r4, #0
	ldr r2, _08010F68 @ =0x03003ED0
	mov sb, r2
	adds r6, r0, #0
_08010E76:
	movs r2, #0
	cmp r2, ip
	bge _08010E92
	adds r3, r6, #0
	ldr r0, _08010F6C @ =0xFFFFD000
	adds r7, r0, #0
	adds r1, r5, #0
_08010E84:
	adds r0, r3, r2
	orrs r0, r7
	strh r0, [r1]
	adds r1, #2
	adds r2, #1
	cmp r2, ip
	blt _08010E84
_08010E92:
	mov r1, sb
	movs r2, #0x18
	ldrsh r0, [r1, r2]
	lsls r0, r0, #2
	adds r5, r5, r0
	adds r6, #0x10
	adds r4, #1
	cmp r4, #1
	ble _08010E76
	mov r0, r8
	movs r1, #0xa
	bl Div
	str r0, [sp]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	mov r7, r8
	subs r1, r7, r1
	str r1, [sp, #4]
	movs r0, #0
	movs r1, #0x10
	movs r2, #0xf
	bl SunCountdown_GetTilePtr
	adds r5, r0, #0
	movs r4, #0
	mov ip, sp
	ldr r0, _08010F6C @ =0xFFFFD000
	adds r7, r0, #0
	ldr r1, _08010F68 @ =0x03003ED0
	mov r8, r1
_08010ED2:
	lsls r3, r4, #4
	mov r6, ip
	adds r1, r5, #0
	movs r2, #1
_08010EDA:
	ldm r6!, {r0}
	adds r0, #0x60
	adds r0, r3, r0
	orrs r0, r7
	strh r0, [r1]
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bge _08010EDA
	mov r2, r8
	movs r1, #0x18
	ldrsh r0, [r2, r1]
	lsls r0, r0, #2
	adds r5, r5, r0
	adds r4, #1
	cmp r4, #1
	ble _08010ED2
	mov r0, sl
	movs r1, #0xa
	bl Div
	str r0, [sp]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	mov r2, sl
	subs r1, r2, r1
	str r1, [sp, #4]
	movs r0, #0
	movs r1, #0x16
	movs r2, #0xf
	bl SunCountdown_GetTilePtr
	adds r5, r0, #0
	movs r4, #0
	mov ip, sp
	ldr r0, _08010F6C @ =0xFFFFD000
	adds r7, r0, #0
	ldr r1, _08010F68 @ =0x03003ED0
	mov r8, r1
_08010F2A:
	adds r6, r4, #1
	lsls r3, r4, #4
	mov r4, ip
	adds r1, r5, #0
	movs r2, #1
_08010F34:
	ldm r4!, {r0}
	adds r0, #0x60
	adds r0, r3, r0
	orrs r0, r7
	strh r0, [r1]
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bge _08010F34
	mov r2, r8
	movs r1, #0x18
	ldrsh r0, [r2, r1]
	lsls r0, r0, #2
	adds r5, r5, r0
	adds r4, r6, #0
	cmp r4, #1
	ble _08010F2A
_08010F56:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08010F68: .4byte 0x03003ED0
_08010F6C: .4byte 0xFFFFD000
