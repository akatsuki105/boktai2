	push {r4, r5, lr}
	sub sp, #0x1c
	adds r4, r0, #0
	movs r0, #0xb6
	lsls r0, r0, #1
	adds r5, r4, r0
	ldr r2, _080817DC @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x32
	orrs r0, r3
	ldr r1, _080817E0 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xfe
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r2
	str r0, [r3, #4]
	ldrh r1, [r4, #0x24]
	ldr r2, _080817E4 @ =0x00004001
	movs r0, #1
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r3, [sp, #8]
	adds r0, r5, #0
	movs r3, #0
	bl Hitbox_Init
	adds r0, r5, #0
	movs r1, #0x14
	movs r2, #2
	movs r3, #1
	bl Hitbox_SetPowerAndAttributes
	ldr r1, _080817E8 @ =FUN_080843ac
	adds r0, r5, #0
	adds r2, r4, #0
	bl Hitbox_SetHandler
	movs r0, #0x82
	lsls r0, r0, #1
	adds r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r5, #0
	bl Hitbox_Register
	add sp, #0x1c
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080817DC: .4byte 0xFFFF0000
_080817E0: .4byte 0x0000FFFF
_080817E4: .4byte 0x00004001
_080817E8: .4byte FUN_080843ac
