	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sb, r0
	mov ip, r1
	mov sl, r3
	mov r4, sb
	adds r4, #0x24
	movs r0, #0
	movs r1, #1
	mov r6, sb
	adds r6, #0x88
	movs r7, #0x82
	lsls r7, r7, #1
	add r7, sb
_0805E6E0:
	mov r8, r1
	mov r3, r8
	lsls r3, r0
	mov r8, r3
	mov r3, sb
	ldr r5, [r3, #0x18]
	mov r3, r8
	ands r5, r3
	cmp r5, #0
	bne _0805E778
	movs r0, #3
	strb r0, [r4, #2]
	strb r1, [r4, #3]
	str r5, [r4, #4]
	strb r2, [r4]
	mov r0, sl
	strb r0, [r4, #1]
	mov r2, ip
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r7]
	str r1, [r7, #4]
	adds r0, r4, #0
	adds r0, #0xf0
	ldr r1, _0805E774 @ =0x00000263
	bl Video_SetAuxSpritePltt
	ldr r0, [r6, #0x60]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #0x60]
	mov r0, sb
	adds r1, r4, #0
	movs r2, #0
	bl Entity0805e67c_SetElemAnim
	movs r3, #0x86
	lsls r3, r3, #1
	adds r0, r4, r3
	bl ParticleShadow_Show
	adds r4, #0x14
	adds r0, r4, #0
	adds r1, r7, #0
	movs r2, #0
	bl Hitbox_SetPos
	str r5, [sp]
	ldr r0, [sp, #0x30]
	str r0, [sp, #4]
	adds r0, r4, #0
	ldr r1, [sp, #0x28]
	ldr r2, [sp, #0x2c]
	movs r3, #0x80
	lsls r3, r3, #5
	bl Hitbox_SetAttack
	adds r0, r6, #0
	adds r1, r7, #0
	movs r2, #0
	bl Hitbox_SetPos
	ldrh r1, [r6, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r6, #6]
	mov r1, sb
	ldr r0, [r1, #0x18]
	mov r2, r8
	orrs r0, r2
	str r0, [r1, #0x18]
	b _0805E788
	.align 2, 0
_0805E774: .4byte 0x00000263
_0805E778:
	adds r0, #1
	movs r3, #0xa6
	lsls r3, r3, #1
	adds r6, r6, r3
	adds r7, r7, r3
	adds r4, r4, r3
	cmp r0, #0xf
	ble _0805E6E0
_0805E788:
	movs r0, #0
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
