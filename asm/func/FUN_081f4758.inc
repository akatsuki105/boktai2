	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r5, r0, #0
	adds r7, r1, #0
	mov sb, r2
	mov r8, r3
	ldr r2, _081F4840 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x40
	orrs r0, r3
	ldr r1, _081F4844 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0xc]
	add r0, sp, #0xc
	mov sl, r0
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	movs r0, #0
	str r0, [sp, #0x14]
	add r6, sp, #0x14
	ldr r0, [r6, #4]
	ands r0, r2
	str r0, [r6, #4]
	adds r4, r5, #0
	adds r4, #0x58
	ldr r2, _081F4848 @ =0x00002001
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r6, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl Hitbox_Init
	mov r2, r8
	str r2, [sp]
	ldr r0, [sp, #0x3c]
	str r0, [sp, #4]
	adds r0, r4, #0
	adds r1, r7, #0
	mov r2, sb
	movs r3, #0
	bl Hitbox_SetAttack
	ldr r1, _081F484C @ =FUN_081f4650
	adds r0, r4, #0
	adds r2, r5, #0
	bl Hitbox_SetHandler
	movs r2, #0x1c
	adds r2, r2, r5
	mov r8, r2
	adds r0, r4, #0
	mov r1, r8
	movs r2, #0
	bl Hitbox_SetPos
	movs r1, #0x5c
	add r0, sp, #0xc
	strh r1, [r0]
	movs r0, #0x80
	mov r2, sl
	strh r0, [r2, #2]
	strh r1, [r2, #4]
	adds r4, #0x50
	ldr r2, _081F4850 @ =0x00004005
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r6, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl Hitbox_Init
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Hitbox_SetPowerAndAttributes
	ldr r1, _081F4854 @ =FUN_081f4704
	adds r0, r4, #0
	adds r2, r5, #0
	bl Hitbox_SetHandler
	adds r0, r4, #0
	mov r1, r8
	movs r2, #0
	bl Hitbox_SetPos
	adds r5, #0xec
	movs r0, #0x3c
	strh r0, [r5]
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081F4840: .4byte 0xFFFF0000
_081F4844: .4byte 0x0000FFFF
_081F4848: .4byte 0x00002001
_081F484C: .4byte FUN_081f4650
_081F4850: .4byte 0x00004005
_081F4854: .4byte FUN_081f4704
