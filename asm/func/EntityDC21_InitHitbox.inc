	push {r4, r5, lr}
	sub sp, #0x1c
	adds r4, r0, #0
	movs r0, #0x80
	lsls r0, r0, #2
	adds r5, r4, r0
	ldr r2, _0809F570 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x64
	orrs r0, r3
	ldr r1, _0809F574 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x96
	lsls r1, r1, #0x10
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
	movs r1, #0x97
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r1, [r0]
	ldr r2, _0809F578 @ =0x00004001
	movs r0, #0
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r3, [sp, #8]
	adds r0, r5, #0
	movs r3, #0
	bl Hitbox_Init
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Hitbox_SetPowerAndAttributes
	adds r0, r5, #0
	movs r1, #0
	adds r2, r4, #0
	bl Hitbox_SetHandler
	adds r4, #0x34
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r5, #0
	bl Hitbox_Register
	add sp, #0x1c
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0809F570: .4byte 0xFFFF0000
_0809F574: .4byte 0x0000FFFF
_0809F578: .4byte 0x00004001
