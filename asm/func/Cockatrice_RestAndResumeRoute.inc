	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldr r1, _0815EA48 @ =Enemy_WaitPendingState
	movs r2, #0
	ldr r3, _0815EA4C @ =0x0000046D
	adds r0, r4, r3
	movs r5, #1
	strb r5, [r0]
	ldr r7, _0815EA50 @ =0x0000046B
	adds r0, r4, r7
	strb r2, [r0]
	adds r3, #0xe6
	adds r0, r4, r3
	strb r2, [r0]
	movs r7, #0xaf
	lsls r7, r7, #3
	adds r0, r4, r7
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r6, #0
	strh r2, [r0]
	movs r1, #3
	subs r3, #0xeb
	adds r0, r4, r3
	strb r1, [r0]
	ldr r7, _0815EA54 @ =0x00000469
	adds r0, r4, r7
	strb r5, [r0]
	ldr r1, _0815EA58 @ =0x0000046A
	adds r0, r4, r1
	strb r6, [r0]
	adds r3, #0x1c
	adds r0, r4, r3
	str r2, [r0]
	adds r7, #3
	adds r0, r4, r7
	strb r5, [r0]
	adds r0, r4, #0
	bl Enemy_StepTowardPathNode
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r0, [r0]
	strh r5, [r0, #6]
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r4, r3
	ldr r3, [r0]
	movs r5, #7
	movs r1, #0x3c
	adds r7, #0xec
	adds r2, r4, r7
	subs r7, #4
	adds r0, r4, r7
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r4, r1
	strb r6, [r0]
	ldr r3, _0815EA5C @ =0x00000551
	adds r0, r4, r3
	strb r6, [r0]
	subs r7, #2
	adds r0, r4, r7
	strb r5, [r0]
	movs r1, #0x10
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r4, r4, r0
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0815EA48: .4byte Enemy_WaitPendingState
_0815EA4C: .4byte 0x0000046D
_0815EA50: .4byte 0x0000046B
_0815EA54: .4byte 0x00000469
_0815EA58: .4byte 0x0000046A
_0815EA5C: .4byte 0x00000551
