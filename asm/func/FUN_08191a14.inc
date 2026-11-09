	push {r4, r5, r6, lr}
	sub sp, #0x4c
	ldr r2, [r0]
	ldr r3, [r0, #4]
	str r2, [sp, #0x3c]
	str r3, [sp, #0x40]
	lsls r1, r1, #0x10
	ldr r2, _08191A88 @ =0x0000FFFF
	ldr r0, [sp, #0x3c]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x3c]
	add r5, sp, #0x3c
	ldrh r1, [r5, #4]
	adds r1, #0xc
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08191A8C @ =0xFFFF0000
	ldr r0, [r5, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [r5, #4]
	add r6, sp, #0x44
	movs r4, #0
	str r4, [sp, #0x38]
	add r0, sp, #0x38
	adds r1, r6, #0
	ldr r2, _08191A90 @ =0x05000002
	bl CpuSet
	ldr r2, _08191A94 @ =0x0000F422
	ldr r3, _08191A98 @ =0x0000121B
	movs r0, #6
	str r0, [sp]
	str r4, [sp, #4]
	movs r0, #9
	str r0, [sp, #8]
	movs r0, #0xda
	str r0, [sp, #0xc]
	movs r0, #2
	str r0, [sp, #0x10]
	str r4, [sp, #0x14]
	str r4, [sp, #0x18]
	str r4, [sp, #0x1c]
	str r4, [sp, #0x20]
	str r4, [sp, #0x24]
	str r4, [sp, #0x28]
	str r4, [sp, #0x2c]
	str r4, [sp, #0x30]
	str r4, [sp, #0x34]
	adds r0, r5, #0
	adds r1, r6, #0
	bl Entity081f26bc_Spawn
	add sp, #0x4c
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08191A88: .4byte 0x0000FFFF
_08191A8C: .4byte 0xFFFF0000
_08191A90: .4byte 0x05000002
_08191A94: .4byte 0x0000F422
_08191A98: .4byte 0x0000121B
