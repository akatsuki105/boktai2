	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	adds r6, r0, #0
	adds r5, r1, #0
	adds r7, r3, #0
	cmp r5, #0
	bne _081EAC30
	cmp r2, #1
	beq _081EABFC
	cmp r2, #1
	bgt _081EABEC
	cmp r2, #0
	beq _081EABF2
	b _081EAC0E
_081EABEC:
	cmp r2, #2
	beq _081EAC04
	b _081EAC0E
_081EABF2:
	ldr r0, _081EABF8 @ =0x085AE498
	b _081EAC06
	.align 2, 0
_081EABF8: .4byte 0x085AE498
_081EABFC:
	ldr r0, _081EAC00 @ =0x085AE4A0
	b _081EAC06
	.align 2, 0
_081EAC00: .4byte 0x085AE4A0
_081EAC04:
	ldr r0, _081EAC28 @ =0x085AE4A8
_081EAC06:
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
_081EAC0E:
	ldr r3, _081EAC2C @ =0xFFFF0000
	movs r0, #0
	str r0, [sp, #0x14]
	add r0, sp, #0xc
	ldrh r2, [r0, #4]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r3
	orrs r0, r2
	str r0, [r1, #4]
	movs r5, #0x40
	b _081EAC7E
	.align 2, 0
_081EAC28: .4byte 0x085AE4A8
_081EAC2C: .4byte 0xFFFF0000
_081EAC30:
	cmp r2, #1
	beq _081EAC4C
	cmp r2, #1
	bgt _081EAC3E
	cmp r2, #0
	beq _081EAC44
	b _081EAC6C
_081EAC3E:
	cmp r2, #2
	beq _081EAC54
	b _081EAC6C
_081EAC44:
	ldr r2, _081EAC48 @ =0x085AE498
	b _081EAC56
	.align 2, 0
_081EAC48: .4byte 0x085AE498
_081EAC4C:
	ldr r2, _081EAC50 @ =0x085AE4A0
	b _081EAC56
	.align 2, 0
_081EAC50: .4byte 0x085AE4A0
_081EAC54:
	ldr r2, _081EACD4 @ =0x085AE4A8
_081EAC56:
	ldr r3, _081EACD8 @ =0xFFFF0000
	ldrh r1, [r2, #2]
	lsls r1, r1, #0x10
	ldrh r0, [r2, #4]
	orrs r0, r1
	str r0, [sp, #0xc]
	ldrh r1, [r2]
	ldr r0, [sp, #0x10]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0x10]
_081EAC6C:
	add r0, sp, #0xc
	ldr r2, _081EACD8 @ =0xFFFF0000
	ldrh r0, [r0]
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	movs r5, #0
_081EAC7E:
	adds r4, r6, #0
	adds r4, #0xd8
	ldr r2, _081EACDC @ =0x00002101
	movs r0, #0x20
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl Hitbox_Init
	ldr r0, _081EACE0 @ =0x00200004
	str r0, [sp]
	ldr r0, [sp, #0x34]
	str r0, [sp, #4]
	adds r0, r4, #0
	adds r1, r7, #0
	ldr r2, [sp, #0x30]
	movs r3, #0x40
	bl Hitbox_SetAttack
	adds r1, r6, #0
	adds r1, #0xd0
	adds r0, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	ldr r1, _081EACE4 @ =FUN_081eabcc
	adds r0, r4, #0
	adds r2, r6, #0
	bl Hitbox_SetHandler
	movs r1, #0x8d
	lsls r1, r1, #1
	adds r0, r6, r1
	strb r5, [r0]
	add sp, #0x1c
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081EACD4: .4byte 0x085AE4A8
_081EACD8: .4byte 0xFFFF0000
_081EACDC: .4byte 0x00002101
_081EACE0: .4byte 0x00200004
_081EACE4: .4byte FUN_081eabcc
