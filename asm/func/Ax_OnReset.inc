	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r4, [r0]
	ldr r2, _0819E288 @ =0x00000EA4
	adds r0, r4, r2
	movs r1, #0
	movs r5, #0
	strh r5, [r0]
	adds r2, #2
	adds r0, r4, r2
	strb r1, [r0]
	ldr r0, _0819E28C @ =0x00000EA7
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0819E290 @ =0x00000EA8
	adds r0, r4, r1
	strh r5, [r0]
	subs r2, #0x5e
	adds r1, r4, r2
	ldr r2, _0819E294 @ =0x00000574
	adds r0, r6, r2
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, _0819E298 @ =0x00000F14
	adds r2, r4, r0
	ldr r0, _0819E29C @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _0819E2A0 @ =0x00000EFC
	adds r1, r4, r2
	str r5, [sp]
	mov r0, sp
	ldr r2, _0819E2A4 @ =0x05000002
	bl CpuSet
	ldr r0, _0819E2A8 @ =0x00000F04
	adds r1, r4, r0
	str r5, [sp]
	mov r0, sp
	ldr r2, _0819E2A4 @ =0x05000002
	bl CpuSet
	ldr r1, _0819E2AC @ =0x00000F0C
	adds r4, r4, r1
	str r5, [sp]
	mov r0, sp
	adds r1, r4, #0
	ldr r2, _0819E2A4 @ =0x05000002
	bl CpuSet
	movs r2, #0x95
	lsls r2, r2, #3
	adds r0, r6, r2
	ldr r0, [r0]
	movs r1, #8
	bl ClearMemory
	ldr r1, _0819E2B0 @ =0x0825221C
	adds r0, r6, #0
	movs r2, #0xd2
	bl Enemy_ClearPendingState
	adds r0, r6, #0
	movs r1, #0
	bl Enemy_PlayAnim
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0819E288: .4byte 0x00000EA4
_0819E28C: .4byte 0x00000EA7
_0819E290: .4byte 0x00000EA8
_0819E294: .4byte 0x00000574
_0819E298: .4byte 0x00000F14
_0819E29C: .4byte 0x03002BE0
_0819E2A0: .4byte 0x00000EFC
_0819E2A4: .4byte 0x05000002
_0819E2A8: .4byte 0x00000F04
_0819E2AC: .4byte 0x00000F0C
_0819E2B0: .4byte 0x0825221C
