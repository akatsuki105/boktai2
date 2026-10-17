	push {r4, r5, r6, lr}
	sub sp, #0x1c
	adds r5, r0, #0
	movs r0, #0xb6
	lsls r0, r0, #1
	adds r6, r5, r0
	ldr r2, _080CF5CC @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x32
	orrs r0, r3
	ldr r1, _080CF5D0 @ =0x0000FFFF
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
	add r4, sp, #0x14
	ldr r0, [r4, #4]
	ands r0, r2
	str r0, [r4, #4]
	ldrh r1, [r5, #0x24]
	ldr r2, _080CF5D4 @ =0x00004001
	ldr r3, [r5, #0x18]
	movs r0, #0x80
	lsls r0, r0, #9
	lsls r0, r3
	lsrs r0, r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r4, [sp, #8]
	adds r0, r6, #0
	movs r3, #0
	bl Hitbox_Init
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080CF5D8
	adds r0, r6, #0
	movs r1, #0x14
	movs r2, #1
	movs r3, #2
	bl Hitbox_SetPowerAndAttributes
	b _080CF5E4
	.align 2, 0
_080CF5CC: .4byte 0xFFFF0000
_080CF5D0: .4byte 0x0000FFFF
_080CF5D4: .4byte 0x00004001
_080CF5D8:
	adds r0, r6, #0
	movs r1, #0x14
	movs r2, #2
	movs r3, #1
	bl Hitbox_SetPowerAndAttributes
_080CF5E4:
	ldr r1, _080CF60C @ =FUN_080d787c
	adds r0, r6, #0
	adds r2, r5, #0
	bl Hitbox_SetHandler
	movs r0, #0x82
	lsls r0, r0, #1
	adds r1, r5, r0
	adds r0, r6, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r6, #0
	bl Hitbox_Register
	add sp, #0x1c
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080CF60C: .4byte FUN_080d787c
