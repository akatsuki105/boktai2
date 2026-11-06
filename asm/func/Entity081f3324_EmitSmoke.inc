	push {r4, lr}
	sub sp, #0x18
	ldr r4, _081F2814 @ =0xFFFF0000
	ldr r1, [sp, #0x10]
	ands r1, r4
	movs r3, #0xa0
	orrs r1, r3
	ldr r2, _081F2818 @ =0x0000FFFF
	ands r1, r2
	str r1, [sp, #0x10]
	ldr r1, [sp, #0x14]
	ands r1, r4
	orrs r1, r3
	str r1, [sp, #0x14]
	adds r0, #0x90
	movs r1, #0
	str r1, [sp]
	movs r1, #0x14
	str r1, [sp, #4]
	movs r1, #1
	str r1, [sp, #8]
	movs r1, #2
	str r1, [sp, #0xc]
	movs r1, #1
	add r2, sp, #0x10
	movs r3, #0
	bl EmitSmoke
	add sp, #0x18
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081F2814: .4byte 0xFFFF0000
_081F2818: .4byte 0x0000FFFF
