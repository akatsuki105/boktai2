	push {r4, lr}
	sub sp, #0x1c
	adds r4, r0, #0
	ldr r0, _0821DC44 @ =0x00000B54
	adds r2, r4, r0
	ldr r0, [r2, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2, #8]
	adds r0, r4, #0
	bl FUN_0821d9fc
	adds r0, r4, #0
	adds r0, #0xaf
	ldrb r0, [r0]
	cmp r0, #0
	bne _0821DC4C
	ldr r3, _0821DC48 @ =0xFFFF0000
	ldr r1, [sp, #0x14]
	ands r1, r3
	movs r2, #0x20
	b _0821DC54
	.align 2, 0
_0821DC44: .4byte 0x00000B54
_0821DC48: .4byte 0xFFFF0000
_0821DC4C:
	ldr r3, _0821DC90 @ =0xFFFF0000
	ldr r1, [sp, #0x14]
	ands r1, r3
	ldr r2, _0821DC94 @ =0x0000FFE0
_0821DC54:
	orrs r1, r2
	ldr r0, [sp, #0x18]
	ands r0, r3
	orrs r0, r2
	str r0, [sp, #0x18]
	ldr r0, _0821DC98 @ =0x0000FFFF
	ands r1, r0
	movs r0, #0xa0
	lsls r0, r0, #0x10
	orrs r1, r0
	str r1, [sp, #0x14]
	ldr r0, _0821DC9C @ =0x03002BE0
	ldr r0, [r0]
	adds r1, r4, #0
	adds r1, #0x50
	movs r3, #0
	str r3, [sp]
	str r3, [sp, #4]
	movs r2, #1
	str r2, [sp, #8]
	str r3, [sp, #0xc]
	str r3, [sp, #0x10]
	add r2, sp, #0x14
	bl FUN_0807ab64
	add sp, #0x1c
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0821DC90: .4byte 0xFFFF0000
_0821DC94: .4byte 0x0000FFE0
_0821DC98: .4byte 0x0000FFFF
_0821DC9C: .4byte 0x03002BE0
