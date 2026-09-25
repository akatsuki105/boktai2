	push {r4, r5, r6, lr}
	sub sp, #0x1c
	adds r6, r0, #0
	ldr r2, _080DAD3C @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r1, #0x40
	orrs r0, r1
	ldr r5, _080DAD40 @ =0x0000FFFF
	ands r0, r5
	movs r4, #0x80
	lsls r4, r4, #0x10
	orrs r0, r4
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r2
	movs r3, #0x10
	orrs r0, r3
	ands r0, r5
	orrs r0, r4
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	orrs r0, r3
	str r0, [r1, #4]
	adds r4, r6, #0
	adds r4, #0x4c
	ldr r2, _080DAD44 @ =0x00004001
	str r3, [sp]
	str r1, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl Hitbox_Init
	adds r1, r6, #0
	adds r1, #0x9c
	adds r0, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	ldr r1, _080DAD48 @ =FUN_080dacac
	adds r0, r4, #0
	adds r2, r6, #0
	bl Hitbox_SetHandler
	adds r0, r4, #0
	bl Hitbox_Register
	add sp, #0x1c
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080DAD3C: .4byte 0xFFFF0000
_080DAD40: .4byte 0x0000FFFF
_080DAD44: .4byte 0x00004001
_080DAD48: .4byte FUN_080dacac
