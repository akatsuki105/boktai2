	push {lr}
	sub sp, #0x10
	ldr r2, _081F9DF4 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r2
	movs r1, #0x98
	lsls r1, r1, #4
	orrs r0, r1
	ldr r1, _081F9DF8 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x12
	orrs r0, r1
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r1, #0x88
	lsls r1, r1, #4
	orrs r0, r1
	str r0, [sp, #0xc]
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	add r0, sp, #8
	movs r1, #0x78
	movs r2, #0
	movs r3, #0
	bl Entity081f9cb8_Spawn
	add sp, #0x10
	pop {r0}
	bx r0
	.align 2, 0
_081F9DF4: .4byte 0xFFFF0000
_081F9DF8: .4byte 0x0000FFFF
