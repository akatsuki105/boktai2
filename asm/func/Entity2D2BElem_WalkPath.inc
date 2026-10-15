	push {r4, r5, r6, r7, lr}
	sub sp, #0x18
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x28
	ldrh r0, [r4, #0xa]
	cmp r0, #0
	beq _08008342
	subs r0, #1
	strh r0, [r4, #0xa]
	b _08008388
_08008342:
	adds r6, r4, #0
	adds r6, #0x54
	add r7, sp, #0x10
	ldrh r0, [r4, #0x26]
	str r0, [sp]
	str r0, [sp, #4]
	ldrh r0, [r4, #0x24]
	str r0, [sp, #8]
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r7, #0
	add r3, sp, #0xc
	bl Map_GetStepToPathNode
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08008374
	adds r0, r5, #0
	bl Map_AdvancePathWalker
	ldr r0, [r5, #8]
	ldrh r1, [r0, #4]
	ldr r0, _08008390 @ =0x00000FFF
	ands r0, r1
	strh r0, [r4, #0xa]
_08008374:
	ldrh r0, [r7]
	ldrh r1, [r6]
	adds r0, r0, r1
	strh r0, [r6]
	adds r1, r4, #0
	adds r1, #0x58
	ldrh r0, [r7, #4]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
_08008388:
	add sp, #0x18
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08008390: .4byte 0x00000FFF
