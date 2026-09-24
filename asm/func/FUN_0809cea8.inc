	push {r4, r5, r6, lr}
	sub sp, #0x24
	adds r6, r0, #0
	ldr r0, [r6, #0x18]
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #2
	bne _0809CEFC
	ldr r1, _0809CEF4 @ =0x00000E2B
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809CF0A
	movs r0, #1
	bl TextBox_SetInstant
	ldr r0, [r6, #0x24]
	bl TextBox_Start
	movs r0, #2
	movs r1, #0x10
	movs r2, #0x1c
	movs r3, #2
	bl TextBox_SetRect
	ldr r0, _0809CEF8 @ =0x00000F4C
	adds r4, r6, r0
	adds r0, #0x2c
	adds r1, r6, r0
	adds r0, r4, #0
	bl FUN_08094d1c
	ldr r1, [r6, #0x24]
	adds r0, r4, #0
	bl FUN_08094d48
	b _0809CF8A
	.align 2, 0
_0809CEF4: .4byte 0x00000E2B
_0809CEF8: .4byte 0x00000F4C
_0809CEFC:
	ldr r0, _0809CF24 @ =0x00000E2B
	adds r4, r6, r0
	ldrb r0, [r4]
	bl GetWeaponID
	cmp r0, #0
	bne _0809CF28
_0809CF0A:
	movs r1, #0xe2
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	bl TextBox_Close
	bl FUN_08049e5c
	b _0809CF8A
	.align 2, 0
_0809CF24: .4byte 0x00000E2B
_0809CF28:
	ldrb r0, [r4]
	mov r1, sp
	bl FUN_08242b14
	movs r0, #0xe2
	lsls r0, r0, #3
	adds r2, r6, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r1, #0xe1
	lsls r1, r1, #3
	adds r4, r6, r1
	adds r5, r6, #0
	adds r5, #0x48
	mov r0, sp
	bl FUN_08094e70
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	adds r1, r5, #0
	movs r3, #1
	bl MainSprite_SetPose
	movs r0, #1
	bl TextBox_SetInstant
	ldr r0, [r6, #0x24]
	bl TextBox_Start
	movs r0, #2
	movs r1, #0x10
	movs r2, #0x1c
	movs r3, #2
	bl TextBox_SetRect
	ldr r0, _0809CF94 @ =0x00000F78
	adds r1, r6, r0
	mov r0, sp
	bl FUN_08094d1c
	ldr r1, [r6, #0x24]
	mov r0, sp
	bl FUN_08094d48
_0809CF8A:
	add sp, #0x24
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809CF94: .4byte 0x00000F78
