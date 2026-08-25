	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x1c]
	lsls r0, r0, #5
	ldr r1, _0820FB94 @ =0x085AF0EC
	adds r6, r0, r1
	movs r1, #0xdc
	lsls r1, r1, #2
	adds r0, r4, r1
	str r6, [r0]
	movs r5, #0
_0820FB36:
	movs r0, #0x94
	adds r1, r5, #0
	muls r1, r0, r1
	adds r0, r4, #0
	adds r0, #0x28
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0820FB52
	adds r0, r1, #0
	adds r0, #0x28
	adds r0, r4, r0
	bl FUN_08055d7c
_0820FB52:
	adds r5, #1
	cmp r5, #4
	ble _0820FB36
	ldrh r1, [r6, #6]
	movs r2, #0xd9
	lsls r2, r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	ldrh r3, [r4, #0x26]
	cmp r3, #0
	bne _0820FB82
	movs r0, #0x14
	ldrsb r0, [r6, r0]
	movs r2, #0x15
	ldrsb r2, [r6, r2]
	movs r5, #0xd5
	lsls r5, r5, #2
	adds r1, r4, r5
	adds r0, #0x40
	adds r2, #0x54
	strh r0, [r1]
	strh r2, [r1, #2]
	strh r3, [r1, #4]
	strh r3, [r1, #6]
_0820FB82:
	ldr r1, [r6, #0xc]
	cmp r1, #0
	bne _0820FB98
	ldr r1, [r4, #0x1c]
	adds r0, r4, #0
	bl FUN_0820f9dc
	b _0820FB9E
	.align 2, 0
_0820FB94: .4byte 0x085AF0EC
_0820FB98:
	adds r0, r4, #0
	bl _call_via_r1
_0820FB9E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
