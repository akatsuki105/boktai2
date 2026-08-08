	push {r4, lr}
	sub sp, #0x1c
	adds r4, r0, #0
	adds r0, #0xaf
	ldrb r0, [r0]
	cmp r0, #0
	bne _0821DBA8
	ldr r3, _0821DBA4 @ =0xFFFF0000
	ldr r1, [sp, #0x14]
	ands r1, r3
	movs r2, #0x20
	b _0821DBB0
	.align 2, 0
_0821DBA4: .4byte 0xFFFF0000
_0821DBA8:
	ldr r3, _0821DC00 @ =0xFFFF0000
	ldr r1, [sp, #0x14]
	ands r1, r3
	ldr r2, _0821DC04 @ =0x0000FFE0
_0821DBB0:
	orrs r1, r2
	ldr r0, [sp, #0x18]
	ands r0, r3
	orrs r0, r2
	str r0, [sp, #0x18]
	ldr r0, _0821DC08 @ =0x0000FFFF
	ands r1, r0
	movs r0, #0xa0
	lsls r0, r0, #0x10
	orrs r1, r0
	str r1, [sp, #0x14]
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	ldr r1, _0821DC0C @ =0x00000BB4
	adds r2, r4, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r0, _0821DC10 @ =0x03002BE0
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
_0821DC00: .4byte 0xFFFF0000
_0821DC04: .4byte 0x0000FFE0
_0821DC08: .4byte 0x0000FFFF
_0821DC0C: .4byte 0x00000BB4
_0821DC10: .4byte 0x03002BE0
