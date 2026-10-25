	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0x24
	adds r6, r0, #0
	movs r0, #0x58
	adds r0, r0, r6
	mov r8, r0
	ldr r5, _080C35DC @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r5
	ldr r2, _080C35E0 @ =0x000005AA
	orrs r0, r2
	ldr r4, _080C35E4 @ =0x0000FFFF
	ands r0, r4
	movs r2, #0x80
	lsls r2, r2, #0x11
	orrs r0, r2
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r5
	ldr r2, _080C35E8 @ =0x000003A5
	orrs r0, r2
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r5
	movs r3, #0x80
	orrs r0, r3
	ands r0, r4
	movs r2, #0x80
	lsls r2, r2, #0xf
	orrs r0, r2
	str r0, [sp, #0x14]
	add r4, sp, #0x14
	ldr r0, [r4, #4]
	ands r0, r5
	orrs r0, r3
	str r0, [r4, #4]
	movs r0, #0
	str r0, [sp, #0x1c]
	add r3, sp, #0x1c
	ldr r0, [r3, #4]
	ands r0, r5
	str r0, [r3, #4]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080C35EC @ =0x00002101
	movs r0, #0x10
	str r0, [sp]
	str r4, [sp, #4]
	str r3, [sp, #8]
	mov r0, r8
	movs r3, #0
	bl Hitbox_Init
	ldrh r1, [r6, #0xa]
	ldrh r2, [r6, #0xc]
	movs r0, #0xc0
	lsls r0, r0, #0xb
	str r0, [sp]
	ldrh r0, [r6, #0xe]
	str r0, [sp, #4]
	mov r0, r8
	movs r3, #0
	bl Hitbox_SetAttack
	movs r0, #0x40
	adds r1, r6, #0
	adds r1, #0x9a
	strb r0, [r1]
	mov r0, r8
	movs r1, #0
	adds r2, r6, #0
	bl Hitbox_SetHandler
	mov r0, r8
	add r1, sp, #0xc
	movs r2, #0
	bl Hitbox_SetPos
	mov r0, r8
	bl Hitbox_Register
	add sp, #0x24
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080C35DC: .4byte 0xFFFF0000
_080C35E0: .4byte 0x000005AA
_080C35E4: .4byte 0x0000FFFF
_080C35E8: .4byte 0x000003A5
_080C35EC: .4byte 0x00002101
