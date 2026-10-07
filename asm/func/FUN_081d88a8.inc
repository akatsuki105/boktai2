	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	adds r7, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	adds r4, r7, #0
	adds r4, #0x3c
	ldr r2, _081D8934 @ =0xFFFF0000
	ldr r1, _081D8938 @ =0x0000FFFF
	movs r0, #0xc8
	lsls r0, r0, #0xe
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r2
	movs r3, #0x54
	orrs r0, r3
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	orrs r0, r3
	str r0, [r1, #4]
	adds r0, r7, #0
	adds r0, #0xcc
	ldrh r0, [r0]
	strh r0, [r4, #4]
	ldr r2, _081D893C @ =0x00002001
	movs r0, #0x20
	str r0, [sp]
	str r1, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl Hitbox_Init
	movs r3, #0x80
	lsls r3, r3, #6
	ldr r0, _081D8940 @ =0x00440008
	str r0, [sp]
	movs r0, #0x3c
	str r0, [sp, #4]
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl Hitbox_SetAttack
	adds r1, r7, #0
	adds r1, #0x1c
	adds r0, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	ldr r1, _081D8944 @ =nop_081d88a4
	adds r0, r4, #0
	adds r2, r7, #0
	bl Hitbox_SetHandler
	add sp, #0x1c
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D8934: .4byte 0xFFFF0000
_081D8938: .4byte 0x0000FFFF
_081D893C: .4byte 0x00002001
_081D8940: .4byte 0x00440008
_081D8944: .4byte nop_081d88a4
