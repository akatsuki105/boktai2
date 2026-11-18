	push {lr}
	adds r2, r0, #0
	ldr r0, _081963B8 @ =0x00000C68
	adds r3, r2, r0
	ldr r0, [r3]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _08196392
	ldrh r0, [r2, #0x26]
	ldrh r1, [r2, #0x1e]
	adds r0, r0, r1
	strh r0, [r2, #0x1e]
_08196392:
	ldr r0, [r3]
	subs r0, #1
	str r0, [r3]
	cmp r0, #0
	bne _081963A6
	ldrh r0, [r2, #0x26]
	rsbs r0, r0, #0
	strh r0, [r2, #0x26]
	movs r0, #0x28
	str r0, [r3]
_081963A6:
	ldr r0, _081963BC @ =0x00000AFE
	adds r1, r2, r0
	ldrh r0, [r2, #0x1e]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_081963B8: .4byte 0x00000C68
_081963BC: .4byte 0x00000AFE
