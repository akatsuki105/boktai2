	push {r4, lr}
	adds r2, r0, #0
	adds r4, r1, #0
	ldr r0, _0823C3B8 @ =gCamera
	ldr r3, [r0]
	cmp r3, #0
	beq _0823C3B0
	ldrh r0, [r2, #4]
	ldrh r1, [r2]
	subs r0, r0, r1
	adds r1, r3, #0
	adds r1, #0x8e
	strh r0, [r1]
	ldrh r0, [r2]
	ldrh r1, [r2, #4]
	adds r0, r0, r1
	ldrh r1, [r2, #2]
	subs r0, r0, r1
	adds r1, r3, #0
	adds r1, #0x90
	strh r0, [r1]
	ldrh r0, [r4, #4]
	ldrh r1, [r4]
	subs r0, r0, r1
	adds r1, r3, #0
	adds r1, #0x92
	strh r0, [r1]
	ldrh r0, [r4]
	ldrh r1, [r4, #4]
	adds r0, r0, r1
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	adds r1, r3, #0
	adds r1, #0x94
	strh r0, [r1]
	subs r1, #8
	movs r0, #2
	strh r0, [r1]
	ldr r1, _0823C3BC @ =0x03003540
	adds r0, r3, #0
	bl Camera_ApplyBounds
_0823C3B0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0823C3B8: .4byte gCamera
_0823C3BC: .4byte 0x03003540
