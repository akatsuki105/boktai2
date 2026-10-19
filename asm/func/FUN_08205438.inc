	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r4, r1, #0
	adds r5, r2, #0
	adds r7, r4, #0
	adds r7, #0x20
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _08205460
	movs r0, #0
	strb r0, [r4, #9]
	strb r0, [r4, #7]
	movs r0, #1
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #7
	movs r2, #1
	movs r3, #0
	bl FUN_08041480
_08205460:
	ldrh r1, [r4, #0xe]
	movs r0, #1
	movs r6, #0
	orrs r0, r1
	strh r0, [r4, #0xe]
	cmp r5, #0x1e
	bne _08205488
	add r2, sp, #4
	ldr r0, [r4, #0x64]
	ldr r1, [r4, #0x68]
	str r0, [sp, #4]
	str r1, [sp, #8]
	ldrh r0, [r2, #2]
	ldr r1, _082054E4 @ =0x00000109
	adds r0, r0, r1
	strh r0, [r2, #2]
	adds r0, r2, #0
	bl Entity0821b7fc_Create
	str r0, [r4, #0x20]
_08205488:
	cmp r5, #0x1e
	ble _082054B2
	movs r0, #7
	adds r1, r5, #0
	ands r1, r0
	asrs r2, r5, #3
	subs r0, r0, r2
	cmp r1, r0
	blt _082054A4
	movs r0, #0xc0
	lsls r0, r0, #2
	ldrh r1, [r4, #0xe]
	orrs r0, r1
	strh r0, [r4, #0xe]
_082054A4:
	cmp r5, #0x55
	ble _082054B2
	movs r0, #0xc0
	lsls r0, r0, #2
	ldrh r1, [r4, #0xe]
	orrs r0, r1
	strh r0, [r4, #0xe]
_082054B2:
	movs r2, #0xb9
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _08205558
	cmp r5, #0
	bne _082054F0
	ldr r0, _082054E8 @ =0x03003584
	ldr r0, [r0]
	movs r3, #0x8c
	lsls r3, r3, #6
	adds r0, r0, r3
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r1, r4, r2
	ldr r2, _082054EC @ =0x04000008
	bl CpuSet
	b _08205538
	.align 2, 0
_082054E4: .4byte 0x00000109
_082054E8: .4byte 0x03003584
_082054EC: .4byte 0x04000008
_082054F0:
	adds r6, r5, #0
	subs r6, #0x50
	cmp r6, #0x1f
	bhi _08205520
	ldr r0, _08205518 @ =0x03003584
	ldr r2, [r0]
	movs r3, #0x8c
	lsls r3, r3, #6
	adds r1, r2, r3
	ldr r0, _0820551C @ =0x000022E0
	adds r2, r2, r0
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r4, r3
	movs r3, #5
	str r3, [sp]
	adds r3, r6, #0
	bl BlendPltt
	b _08205538
	.align 2, 0
_08205518: .4byte 0x03003584
_0820551C: .4byte 0x000022E0
_08205520:
	cmp r5, #0x70
	bne _08205538
	ldr r0, _08205560 @ =0x03003584
	ldr r0, [r0]
	ldr r1, _08205564 @ =0x000022E0
	adds r0, r0, r1
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r1, r4, r2
	ldr r2, _08205568 @ =0x04000008
	bl CpuSet
_08205538:
	adds r1, r4, #0
	adds r1, #0xdc
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r4, r3
	str r0, [r1, #0xc]
	ldr r0, [r7]
	bl FUN_0821b84c
	cmp r0, #0
	beq _08205558
	ldr r0, [r7]
	bl FUN_0821b840
	movs r0, #1
	strb r0, [r4, #7]
_08205558:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08205560: .4byte 0x03003584
_08205564: .4byte 0x000022E0
_08205568: .4byte 0x04000008
