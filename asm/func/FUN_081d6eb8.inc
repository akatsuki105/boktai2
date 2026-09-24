	push {r4, r5, lr}
	sub sp, #0x1c
	adds r5, r0, #0
	ldr r1, _081D6EDC @ =0x00000109
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _081D6EE8
	ldr r2, _081D6EE0 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x56
	orrs r0, r3
	ldr r1, _081D6EE4 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	b _081D6EFA
	.align 2, 0
_081D6EDC: .4byte 0x00000109
_081D6EE0: .4byte 0xFFFF0000
_081D6EE4: .4byte 0x0000FFFF
_081D6EE8:
	ldr r2, _081D6F50 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x60
	orrs r0, r3
	ldr r1, _081D6F54 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xd
_081D6EFA:
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
	adds r4, #0xa4
	ldr r2, _081D6F58 @ =0x00004003
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
	adds r1, #0x9c
	adds r0, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	ldr r1, _081D6F5C @ =FUN_081d6d28
	adds r0, r4, #0
	adds r2, r5, #0
	bl Hitbox_SetHandler
	adds r0, r4, #0
	bl Hitbox_Register
	add sp, #0x1c
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081D6F50: .4byte 0xFFFF0000
_081D6F54: .4byte 0x0000FFFF
_081D6F58: .4byte 0x00004003
_081D6F5C: .4byte FUN_081d6d28
