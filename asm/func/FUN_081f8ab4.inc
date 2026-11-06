	push {r4, r5, r6, lr}
	sub sp, #0x34
	ldr r2, _081F8B40 @ =0xFFFF0000
	ldr r0, [sp, #0x24]
	ands r0, r2
	movs r1, #0x98
	lsls r1, r1, #4
	orrs r0, r1
	ldr r1, _081F8B44 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xb7
	lsls r1, r1, #0x12
	orrs r0, r1
	str r0, [sp, #0x24]
	add r5, sp, #0x24
	ldr r0, [sp, #0x28]
	ands r0, r2
	movs r1, #0x88
	lsls r1, r1, #4
	orrs r0, r1
	str r0, [sp, #0x28]
	ldr r6, _081F8B48 @ =0x03002BE0
	add r2, sp, #0x2c
	ldr r0, [r6]
	adds r3, r0, #0
	adds r3, #0x2c
	ldrh r1, [r0, #0x2c]
	adds r0, r5, #0
	ldrh r0, [r0]
	subs r1, r1, r0
	movs r4, #0
	strh r1, [r2]
	ldrh r0, [r3, #2]
	ldrh r1, [r5, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r5, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl ArcTan2_8
	adds r3, r0, #0
	ldr r1, [r6]
	adds r1, #0x2c
	movs r0, #0x3c
	str r0, [sp]
	movs r2, #4
	str r2, [sp, #4]
	movs r0, #0xc
	str r0, [sp, #8]
	str r2, [sp, #0xc]
	movs r0, #0x18
	str r0, [sp, #0x10]
	str r4, [sp, #0x14]
	str r4, [sp, #0x18]
	str r4, [sp, #0x1c]
	str r4, [sp, #0x20]
	add r0, sp, #0x24
	movs r2, #0x14
	bl Entity081f8a28_Spawn
	add sp, #0x34
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081F8B40: .4byte 0xFFFF0000
_081F8B44: .4byte 0x0000FFFF
_081F8B48: .4byte 0x03002BE0
