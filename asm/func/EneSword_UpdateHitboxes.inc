	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r6, r0, #0
	ldr r1, _08195EF0 @ =0x00000AE6
	adds r0, r6, r1
	ldrb r1, [r0]
	movs r0, #0x1c
	subs r0, r0, r1
	ldr r2, _08195EF4 @ =0x0000044A
	adds r4, r6, r2
	strb r0, [r4]
	ldr r3, _08195EF8 @ =0x00000CEC
	adds r0, r6, r3
	ldr r0, [r0]
	movs r1, #3
	bl Mod
	ldr r1, _08195EFC @ =gSineTable
	mov r8, r1
	ldrb r1, [r4]
	adds r1, #0x40
	movs r2, #0xff
	ands r1, r2
	lsls r1, r1, #1
	add r1, r8
	movs r3, #0
	ldrsh r2, [r1, r3]
	ldr r1, _08195F00 @ =0x085ADD9C
	lsls r0, r0, #2
	adds r7, r0, r1
	ldr r0, [r7]
	muls r0, r2, r0
	movs r1, #0x80
	lsls r1, r1, #5
	bl Div
	ldr r2, _08195F04 @ =0x00000AFC
	adds r1, r6, r2
	ldrh r1, [r1]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r5, _08195F08 @ =0xFFFF0000
	ldr r2, [sp]
	ands r2, r5
	orrs r2, r1
	str r2, [sp]
	ldr r0, [r6, #0x18]
	ldrh r1, [r0, #0x2e]
	adds r1, #0xdc
	lsls r1, r1, #0x10
	ldr r0, _08195F0C @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	ldrb r0, [r4]
	lsls r0, r0, #1
	add r0, r8
	movs r3, #0
	ldrsh r1, [r0, r3]
	ldr r0, [r7]
	muls r0, r1, r0
	movs r1, #0x80
	lsls r1, r1, #5
	bl Div
	movs r2, #0xb0
	lsls r2, r2, #4
	adds r1, r6, r2
	ldrh r1, [r1]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #4]
	ands r0, r5
	orrs r0, r1
	str r0, [sp, #4]
	ldr r3, _08195F10 @ =0x00000B94
	adds r4, r6, r3
	adds r0, r4, #0
	mov r1, sp
	movs r2, #0
	bl Hitbox_SetPos
	ldr r1, _08195F14 @ =0x00000BE4
	adds r0, r6, r1
	mov r1, sp
	movs r2, #0
	bl Hitbox_SetPos
	ldr r2, _08195F18 @ =0x00000B9A
	adds r0, r6, r2
	ldrh r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	bne _08195E2C
	adds r0, r4, #0
	bl Hitbox_Register
_08195E2C:
	movs r3, #0
	mov sb, r3
	ldr r0, _08195EF4 @ =0x0000044A
	adds r0, r6, r0
	str r0, [sp, #8]
	mov sl, r7
	mov r8, sp
	movs r1, #0xb0
	lsls r1, r1, #2
	adds r7, r6, r1
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r5, r6, r2
_08195E46:
	ldr r3, [sp, #8]
	ldrb r0, [r3]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	ldr r1, _08195EFC @ =gSineTable
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	mov r3, sl
	ldr r0, [r3]
	muls r0, r1, r0
	movs r1, #0x80
	lsls r1, r1, #5
	bl Div
	movs r1, #0x2c
	mov r4, sb
	muls r4, r1, r4
	adds r4, r6, r4
	adds r1, r4, #0
	adds r1, #0x7c
	ldrh r1, [r1]
	adds r1, r1, r0
	mov r0, r8
	strh r1, [r0]
	ldr r0, [r6, #0x18]
	ldrh r0, [r0, #0x2e]
	adds r0, #0xdc
	mov r1, r8
	strh r0, [r1, #2]
	ldr r2, [sp, #8]
	ldrb r0, [r2]
	lsls r0, r0, #1
	ldr r3, _08195EFC @ =gSineTable
	adds r0, r0, r3
	movs r2, #0
	ldrsh r1, [r0, r2]
	mov r3, sl
	ldr r0, [r3]
	muls r0, r1, r0
	movs r1, #0x80
	lsls r1, r1, #5
	bl Div
	adds r4, #0x80
	ldrh r1, [r4]
	adds r1, r1, r0
	mov r0, r8
	strh r1, [r0, #4]
	ldrh r1, [r5, #6]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	bne _08195EBC
	adds r0, r5, #0
	bl Hitbox_Register
_08195EBC:
	adds r0, r5, #0
	mov r1, sp
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r7, #0
	mov r1, sp
	movs r2, #0
	bl Hitbox_SetPos
	adds r7, #0x50
	adds r5, #0x50
	movs r1, #1
	add sb, r1
	mov r2, sb
	cmp r2, #3
	ble _08195E46
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08195EF0: .4byte 0x00000AE6
_08195EF4: .4byte 0x0000044A
_08195EF8: .4byte 0x00000CEC
_08195EFC: .4byte gSineTable
_08195F00: .4byte 0x085ADD9C
_08195F04: .4byte 0x00000AFC
_08195F08: .4byte 0xFFFF0000
_08195F0C: .4byte 0x0000FFFF
_08195F10: .4byte 0x00000B94
_08195F14: .4byte 0x00000BE4
_08195F18: .4byte 0x00000B9A
