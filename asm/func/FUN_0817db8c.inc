	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0x1c
	adds r5, r0, #0
	mov r8, r1
	ldr r3, _0817DBE4 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r3
	movs r2, #0x20
	orrs r0, r2
	ldr r1, _0817DBE8 @ =0x0000FFFF
	ands r0, r1
	str r0, [sp, #0xc]
	add r4, sp, #0xc
	ldr r0, [r4, #4]
	ands r0, r3
	orrs r0, r2
	str r0, [r4, #4]
	add r6, sp, #0x14
	movs r0, #0
	str r0, [sp, #8]
	add r0, sp, #8
	adds r1, r6, #0
	ldr r2, _0817DBEC @ =0x05000002
	bl CpuSet
	adds r5, #8
	movs r0, #2
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	mov r3, r8
	bl DustManager_Spawn
	add sp, #0x1c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0817DBE4: .4byte 0xFFFF0000
_0817DBE8: .4byte 0x0000FFFF
_0817DBEC: .4byte 0x05000002
