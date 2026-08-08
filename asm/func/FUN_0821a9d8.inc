	push {r4, r5, lr}
	movs r1, #1
	rsbs r1, r1, #0
	movs r0, #0x6b
	bl FUN_0823174c
	ldr r1, _0821AA38 @ =0x03002C98
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r4, [r0]
	movs r0, #0x73
	bl prepare_08231510
	cmp r0, #0
	beq _0821AA0C
	movs r0, #0x99
	lsls r0, r0, #1
	adds r5, r4, r0
	ldrh r0, [r5]
	movs r2, #0x98
	lsls r2, r2, #1
	adds r1, r4, r2
	strh r0, [r1]
	bl fetch_082316e4
	strh r0, [r5]
_0821AA0C:
	movs r0, #0x74
	bl prepare_08231510
	cmp r0, #0
	beq _0821AA22
	bl fetch_082316e4
	movs r2, #0x9a
	lsls r2, r2, #1
	adds r1, r4, r2
	strh r0, [r1]
_0821AA22:
	movs r1, #0x9a
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r0, [r0]
	movs r2, #0x9b
	lsls r2, r2, #1
	adds r1, r4, r2
	strh r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0821AA38: .4byte 0x03002C98
