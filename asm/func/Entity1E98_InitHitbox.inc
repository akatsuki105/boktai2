	push {r4, r5, lr}
	sub sp, #0x1c
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x48
	ldr r2, _080A4B3C @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x80
	orrs r0, r3
	ldr r1, _080A4B40 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xc8
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	movs r0, #0
	str r0, [sp, #0x14]
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r2
	str r0, [r3, #4]
	adds r0, r4, #0
	adds r0, #0xe6
	ldrh r1, [r0]
	ldr r2, _080A4B44 @ =0x00004002
	movs r0, #0x20
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r3, [sp, #8]
	adds r0, r5, #0
	movs r3, #0
	bl Hitbox_Init
	ldr r1, _080A4B48 @ =0x080A4621
	adds r0, r5, #0
	adds r2, r4, #0
	bl Hitbox_SetHandler
	adds r4, #0xdc
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
_080A4B3C: .4byte 0xFFFF0000
_080A4B40: .4byte 0x0000FFFF
_080A4B44: .4byte 0x00004002
_080A4B48: .4byte 0x080A4621
