	push {r4, lr}
	adds r3, r0, #0
	adds r4, r1, #0
	ldr r0, _0823C2C4 @ =gCamera
	ldr r2, [r0]
	cmp r2, #0
	beq _0823C2BE
	ldrh r0, [r3, #2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	ldrh r1, [r3]
	subs r1, r1, r0
	adds r0, r2, #0
	adds r0, #0x8e
	strh r1, [r0]
	ldrh r0, [r3, #2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	ldrh r1, [r3, #4]
	subs r1, r1, r0
	adds r0, r2, #0
	adds r0, #0x90
	strh r1, [r0]
	ldrh r0, [r4, #2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	ldrh r1, [r4]
	subs r1, r1, r0
	adds r0, r2, #0
	adds r0, #0x92
	strh r1, [r0]
	ldrh r0, [r4, #2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	ldrh r1, [r4, #4]
	subs r1, r1, r0
	adds r0, r2, #0
	adds r0, #0x94
	strh r1, [r0]
	adds r1, r2, #0
	adds r1, #0x8c
	movs r0, #1
	strh r0, [r1]
	ldr r1, _0823C2C8 @ =0x03003540
	adds r0, r2, #0
	bl Camera_ApplyBounds
_0823C2BE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0823C2C4: .4byte gCamera
_0823C2C8: .4byte 0x03003540
