	push {r4, r5, lr}
	sub sp, #0x1c
	adds r5, r0, #0
	ldr r2, _08202E08 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x80
	orrs r0, r3
	ldr r1, _08202E0C @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	adds r4, r5, #0
	adds r4, #0x3c
	ldr r2, _08202E10 @ =0x00004001
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl Hitbox_Init
	adds r1, r5, #0
	adds r1, #0x1c
	adds r0, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	ldr r1, _08202E14 @ =InkBallShot_OnHurt
	adds r0, r4, #0
	adds r2, r5, #0
	bl Hitbox_SetHandler
	adds r0, r4, #0
	movs r1, #0xa
	movs r2, #2
	movs r3, #1
	bl Hitbox_SetPowerAndAttributes
	adds r0, r4, #0
	bl Hitbox_Register
	add sp, #0x1c
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08202E08: .4byte 0xFFFF0000
_08202E0C: .4byte 0x0000FFFF
_08202E10: .4byte 0x00004001
_08202E14: .4byte InkBallShot_OnHurt
