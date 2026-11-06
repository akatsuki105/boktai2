	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	mov r8, r0
	str r1, [sp, #0x10]
	str r3, [sp, #0x14]
	adds r0, r2, #0
	subs r0, #0x60
	str r0, [sp, #8]
	adds r2, #0x60
	str r2, [sp, #0xc]
	mov r6, r8
	adds r6, #0x24
	movs r0, #0
	str r0, [sp, #0x18]
	movs r1, #0xe8
	add r1, r8
	mov sb, r1
_0805E7C6:
	movs r2, #1
	mov sl, r2
	mov r0, sl
	ldr r1, [sp, #0x18]
	lsls r0, r1
	mov sl, r0
	mov r2, r8
	ldr r7, [r2, #0x18]
	ands r7, r0
	cmp r7, #0
	bne _0805E8BA
	movs r0, #1
	strb r0, [r6, #2]
	strb r0, [r6, #3]
	str r7, [r6, #4]
	ldr r2, _0805E918 @ =0x030046B8
	ldr r1, [r2]
	adds r1, #1
	ldr r0, _0805E91C @ =0x000003FF
	ands r1, r0
	lsls r0, r1, #1
	ldr r2, _0805E920 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #0x1f
	ands r0, r2
	adds r0, #4
	strb r0, [r6, #8]
	movs r0, #0x14
	strb r0, [r6, #9]
	ldr r2, [sp, #0x18]
	lsls r0, r2, #3
	adds r0, #0xf
	strb r0, [r6, #0xa]
	adds r1, #1
	ldr r0, _0805E91C @ =0x000003FF
	ands r1, r0
	ldr r2, _0805E918 @ =0x030046B8
	str r1, [r2]
	lsls r1, r1, #1
	ldr r0, _0805E920 @ =0x0203B400
	adds r1, r1, r0
	ldrh r2, [r1]
	ldr r0, [sp, #0x18]
	movs r1, #1
	ands r0, r1
	lsls r0, r0, #2
	add r0, sp
	adds r0, #8
	ldr r1, [r0]
	movs r0, #0x3f
	ands r2, r0
	adds r1, r1, r2
	subs r1, #0x20
	strb r1, [r6]
	mov r2, sp
	ldrb r2, [r2, #0x14]
	strb r2, [r6, #1]
	adds r5, r6, #0
	adds r5, #0xe0
	ldr r2, [sp, #0x10]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	mov r2, sb
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	mov r0, r8
	adds r1, r6, #0
	movs r2, #0
	bl Entity0805e67c_SetElemAnim
	adds r0, r6, #0
	adds r0, #0xf0
	ldr r1, _0805E924 @ =0x00000267
	bl Video_SetAuxSpritePltt
	ldr r0, _0805E928 @ =0x000014E8
	add r0, r8
	mov r1, sb
	str r0, [r1, #0x38]
	movs r2, #0x86
	lsls r2, r2, #1
	adds r0, r6, r2
	bl ParticleShadow_Show
	adds r4, r6, #0
	adds r4, #0x14
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl Hitbox_SetPos
	str r7, [sp]
	ldr r0, [sp, #0x44]
	str r0, [sp, #4]
	adds r0, r4, #0
	ldr r1, [sp, #0x3c]
	ldr r2, [sp, #0x40]
	movs r3, #0x80
	lsls r3, r3, #5
	bl Hitbox_SetAttack
	adds r4, #0x50
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl Hitbox_SetPos
	ldrh r1, [r4, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r4, #6]
	mov r1, r8
	ldr r0, [r1, #0x18]
	mov r2, sl
	orrs r0, r2
	str r0, [r1, #0x18]
_0805E8BA:
	ldr r0, [sp, #0x18]
	adds r0, #1
	str r0, [sp, #0x18]
	movs r1, #0xa6
	lsls r1, r1, #1
	add sb, r1
	adds r6, r6, r1
	cmp r0, #0xf
	bgt _0805E8CE
	b _0805E7C6
_0805E8CE:
	ldr r1, _0805E92C @ =0x000014E4
	add r1, r8
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r3, _0805E930 @ =0x000014E5
	add r3, r8
	movs r0, #0x14
	strb r0, [r3]
	ldr r0, _0805E934 @ =0x000014E6
	add r0, r8
	strb r2, [r0]
	ldr r0, _0805E938 @ =0x03003584
	ldr r2, [r0]
	ldr r0, _0805E93C @ =0x00004C60
	adds r1, r2, r0
	adds r0, #0x80
	adds r2, r2, r0
	ldr r0, _0805E928 @ =0x000014E8
	add r0, r8
	ldrb r3, [r3]
	lsls r3, r3, #0x18
	asrs r3, r3, #0x18
	movs r4, #5
	str r4, [sp]
	bl BlendPltt
	movs r0, #0
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805E918: .4byte 0x030046B8
_0805E91C: .4byte 0x000003FF
_0805E920: .4byte 0x0203B400
_0805E924: .4byte 0x00000267
_0805E928: .4byte 0x000014E8
_0805E92C: .4byte 0x000014E4
_0805E930: .4byte 0x000014E5
_0805E934: .4byte 0x000014E6
_0805E938: .4byte 0x03003584
_0805E93C: .4byte 0x00004C60
