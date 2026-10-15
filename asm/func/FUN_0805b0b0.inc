	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov r8, r0
	adds r7, r1, #0
	adds r6, r2, #0
	adds r5, r3, #0
	add r1, sp, #4
	bl FUN_0805a43c
	adds r4, r0, #0
	cmp r4, #0
	bne _0805B0D6
	movs r0, #1
	rsbs r0, r0, #0
	b _0805B190
_0805B0D6:
	movs r1, #0
	strb r1, [r4, #1]
	movs r0, #1
	strb r0, [r4]
	movs r2, #0
	strh r1, [r4, #6]
	strb r5, [r4, #0xa]
	strb r5, [r4, #0xb]
	ldr r0, [sp, #0x28]
	strh r0, [r4, #0x10]
	ldr r0, [sp, #0x2c]
	strh r0, [r4, #0x12]
	strh r1, [r4, #8]
	str r6, [r4, #0x44]
	strb r2, [r4, #0xc]
	ldr r0, [r7]
	ldr r1, [r7, #4]
	str r0, [r4, #0x14]
	str r1, [r4, #0x18]
	adds r5, r4, #0
	adds r5, #0xf8
	movs r6, #0
	movs r0, #0x48
	adds r0, r0, r4
	mov sl, r0
	movs r1, #0x14
	adds r1, r1, r4
	mov sb, r1
	adds r7, r4, #0
	adds r7, #0x98
_0805B112:
	lsls r0, r6, #3
	adds r0, r0, r4
	ldr r1, [r4, #0x14]
	ldr r2, [r4, #0x18]
	str r1, [r0, #0x1c]
	str r2, [r0, #0x20]
	ldr r0, [r4, #0x14]
	ldr r1, [r4, #0x18]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	cmp r6, #0
	bne _0805B148
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	mov r2, r8
	ldr r1, [r2, #0x20]
	str r6, [sp]
	adds r0, r4, #0
	adds r0, #0xe8
	movs r2, #1
	movs r3, #0
	bl AuxAnim_SetAnim
	b _0805B150
_0805B148:
	ldr r0, [r5]
	movs r1, #1
	orrs r0, r1
	str r0, [r5]
_0805B150:
	adds r6, #1
	adds r5, #0x2c
	cmp r6, #3
	ble _0805B112
	movs r1, #0xd4
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #0xc8
	bl Video_SetAuxSpritePltt
	mov r0, sl
	mov r1, sb
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r7, #0
	mov r1, sb
	movs r2, #0
	bl Hitbox_SetPos
	ldrh r1, [r7, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r7, #6]
	ldr r0, [sp, #4]
	movs r1, #1
	lsls r1, r0
	mov r2, r8
	ldr r0, [r2, #0x18]
	orrs r0, r1
	str r0, [r2, #0x18]
	movs r0, #0
_0805B190:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
