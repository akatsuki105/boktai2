	push {lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0x60
	adds r0, #0x6e
	ldrh r0, [r0]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	adds r1, #4
	adds r0, r2, #0
	adds r0, #0x70
	ldrh r0, [r0]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	ldr r0, [r2, #0x60]
	ldr r1, [r2, #0x64]
	str r0, [r2, #0x34]
	str r1, [r2, #0x38]
	adds r1, r2, #0
	adds r1, #0x76
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	subs r1, #2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r1]
	cmp r0, r1
	blo _080C0E3A
	ldr r1, _080C0E40 @ =Entity080c0fa0_AdvanceAnim
	adds r0, r2, #0
	bl Entity080c0fa0_SetUpdateCallback
_080C0E3A:
	pop {r0}
	bx r0
	.align 2, 0
_080C0E40: .4byte Entity080c0fa0_AdvanceAnim
