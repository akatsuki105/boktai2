	push {r4, r5, r6, lr}
	sub sp, #0x38
	adds r4, r0, #0
	ldr r0, _08003960 @ =0x00000135
	bl PlaySound_082406e0
	adds r2, r4, #0
	adds r2, #0x34
	movs r5, #0x1e
	str r5, [sp]
	movs r0, #0x14
	str r0, [sp, #4]
	movs r0, #8
	str r0, [sp, #8]
	str r0, [sp, #0xc]
	movs r0, #0
	str r0, [sp, #0x10]
	movs r0, #0x80
	lsls r0, r0, #1
	str r0, [sp, #0x14]
	movs r0, #0x18
	str r0, [sp, #0x18]
	movs r0, #0x10
	str r0, [sp, #0x1c]
	movs r0, #4
	movs r1, #0
	movs r3, #0x3c
	bl FUN_08014da0
	ldr r2, _08003964 @ =0xFFFF0000
	ldrh r1, [r4, #0x36]
	adds r1, #0x80
	lsls r1, r1, #0x10
	ldr r6, _08003968 @ =0x0000FFFF
	ldrh r0, [r4, #0x34]
	orrs r0, r1
	str r0, [sp, #0x20]
	ldrh r1, [r4, #0x38]
	ldr r0, [sp, #0x24]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x24]
	ldr r0, [sp, #0x28]
	ands r0, r2
	ldr r4, _0800396C @ =0x0000FFF1
	orrs r0, r4
	ands r0, r6
	movs r1, #0x80
	lsls r1, r1, #0xc
	orrs r0, r1
	str r0, [sp, #0x28]
	add r3, sp, #0x28
	ldr r0, [r3, #4]
	ands r0, r2
	orrs r0, r4
	str r0, [r3, #4]
	ldr r0, [sp, #0x30]
	ands r0, r2
	orrs r0, r5
	ands r0, r6
	movs r1, #0xb0
	lsls r1, r1, #0xd
	orrs r0, r1
	str r0, [sp, #0x30]
	add r1, sp, #0x30
	ldr r0, [r1, #4]
	ands r0, r2
	orrs r0, r5
	str r0, [r1, #4]
	str r1, [sp]
	movs r0, #0x3c
	str r0, [sp, #4]
	str r0, [sp, #8]
	movs r0, #8
	movs r1, #2
	add r2, sp, #0x20
	bl FUN_08014730
	add sp, #0x38
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08003960: .4byte 0x00000135
_08003964: .4byte 0xFFFF0000
_08003968: .4byte 0x0000FFFF
_0800396C: .4byte 0x0000FFF1
