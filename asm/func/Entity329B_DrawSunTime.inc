	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	ldr r0, _0800FEB0 @ =gClock
	cmp r0, #0
	bne _0800FE88
	b _0801001E
_0800FE88:
	ldrb r0, [r0, #0xe]
	cmp r0, #0
	beq _0800FE96
	cmp r0, #4
	beq _0800FE96
	cmp r0, #5
	bne _0800FEB4
_0800FE96:
	movs r0, #0
	movs r1, #4
	movs r2, #0xf
	bl Entity329B_GetTilePtr
	adds r5, r0, #0
	ldr r1, _0800FEB0 @ =gClock
	ldrb r1, [r1, #0x12]
	mov r8, r1
	ldr r2, _0800FEB0 @ =gClock
	ldrb r2, [r2, #0x13]
	mov sl, r2
	b _0800FECC
	.align 2, 0
_0800FEB0: .4byte gClock
_0800FEB4:
	movs r0, #0
	movs r1, #4
	movs r2, #0xf
	bl Entity329B_GetTilePtr
	adds r5, r0, #0
	ldr r7, _0800FF24 @ =gClock
	ldrb r7, [r7, #0x10]
	mov r8, r7
	ldr r0, _0800FF24 @ =gClock
	ldrb r0, [r0, #0x11]
	mov sl, r0
_0800FECC:
	movs r4, #0
	ldr r1, _0800FF28 @ =0xFFFFD000
	mov ip, r1
	movs r6, #0x6a
	ldr r2, _0800FF2C @ =0x03003ED0
	mov sb, r2
_0800FED8:
	movs r2, #0
	adds r3, r6, #0
	adds r1, r5, #0
_0800FEDE:
	adds r0, r3, r2
	mov r7, ip
	orrs r0, r7
	strh r0, [r1]
	adds r1, #2
	adds r2, #1
	cmp r2, #3
	ble _0800FEDE
	mov r1, sb
	movs r2, #0x18
	ldrsh r0, [r1, r2]
	lsls r0, r0, #2
	adds r5, r5, r0
	adds r6, #0x10
	adds r4, #1
	cmp r4, #1
	ble _0800FED8
	movs r0, #0
	movs r1, #8
	movs r2, #0xf
	bl Entity329B_GetTilePtr
	adds r5, r0, #0
	ldr r7, _0800FF24 @ =gClock
	ldrb r0, [r7, #0xe]
	cmp r0, #0
	beq _0800FF1C
	cmp r0, #4
	beq _0800FF1C
	cmp r0, #5
	bne _0800FF30
_0800FF1C:
	movs r0, #2
	mov ip, r0
	movs r0, #0x6e
	b _0800FF36
	.align 2, 0
_0800FF24: .4byte gClock
_0800FF28: .4byte 0xFFFFD000
_0800FF2C: .4byte 0x03003ED0
_0800FF30:
	movs r1, #2
	mov ip, r1
	movs r0, #0x4e
_0800FF36:
	movs r4, #0
	ldr r2, _08010030 @ =0x03003ED0
	mov sb, r2
	adds r6, r0, #0
_0800FF3E:
	movs r2, #0
	cmp r2, ip
	bge _0800FF5A
	adds r3, r6, #0
	ldr r0, _08010034 @ =0xFFFFD000
	adds r7, r0, #0
	adds r1, r5, #0
_0800FF4C:
	adds r0, r3, r2
	orrs r0, r7
	strh r0, [r1]
	adds r1, #2
	adds r2, #1
	cmp r2, ip
	blt _0800FF4C
_0800FF5A:
	mov r1, sb
	movs r2, #0x18
	ldrsh r0, [r1, r2]
	lsls r0, r0, #2
	adds r5, r5, r0
	adds r6, #0x10
	adds r4, #1
	cmp r4, #1
	ble _0800FF3E
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
	bl Entity329B_GetTilePtr
	adds r5, r0, #0
	movs r4, #0
	mov ip, sp
	ldr r0, _08010034 @ =0xFFFFD000
	adds r7, r0, #0
	ldr r1, _08010030 @ =0x03003ED0
	mov r8, r1
_0800FF9A:
	lsls r3, r4, #4
	mov r6, ip
	adds r1, r5, #0
	movs r2, #1
_0800FFA2:
	ldm r6!, {r0}
	adds r0, #0x60
	adds r0, r3, r0
	orrs r0, r7
	strh r0, [r1]
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bge _0800FFA2
	mov r2, r8
	movs r1, #0x18
	ldrsh r0, [r2, r1]
	lsls r0, r0, #2
	adds r5, r5, r0
	adds r4, #1
	cmp r4, #1
	ble _0800FF9A
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
	bl Entity329B_GetTilePtr
	adds r5, r0, #0
	movs r4, #0
	mov ip, sp
	ldr r0, _08010034 @ =0xFFFFD000
	adds r7, r0, #0
	ldr r1, _08010030 @ =0x03003ED0
	mov r8, r1
_0800FFF2:
	adds r6, r4, #1
	lsls r3, r4, #4
	mov r4, ip
	adds r1, r5, #0
	movs r2, #1
_0800FFFC:
	ldm r4!, {r0}
	adds r0, #0x60
	adds r0, r3, r0
	orrs r0, r7
	strh r0, [r1]
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bge _0800FFFC
	mov r2, r8
	movs r1, #0x18
	ldrsh r0, [r2, r1]
	lsls r0, r0, #2
	adds r5, r5, r0
	adds r4, r6, #0
	cmp r4, #1
	ble _0800FFF2
_0801001E:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08010030: .4byte 0x03003ED0
_08010034: .4byte 0xFFFFD000
