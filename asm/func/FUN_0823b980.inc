	push {r4, lr}
	adds r4, r0, #0
	adds r3, r1, #0
	ldr r0, _0823B9B4 @ =gCamera
	ldr r2, [r0]
	cmp r2, #0
	beq _0823B9C6
	ldrh r1, [r3]
	adds r0, r2, #0
	adds r0, #0x60
	strh r1, [r0]
	ldrh r0, [r3, #2]
	adds r1, r2, #0
	adds r1, #0x62
	strh r0, [r1]
	ldrh r1, [r3, #4]
	adds r0, r2, #0
	adds r0, #0x64
	strh r1, [r0]
	cmp r4, #1
	bgt _0823B9B8
	adds r1, r2, #0
	adds r1, #0x54
	movs r0, #1
	b _0823B9C4
	.align 2, 0
_0823B9B4: .4byte gCamera
_0823B9B8:
	adds r0, r2, #0
	adds r0, #0x56
	strh r4, [r0]
	adds r1, r2, #0
	adds r1, #0x54
	movs r0, #2
_0823B9C4:
	strh r0, [r1]
_0823B9C6:
	pop {r4}
	pop {r0}
	bx r0
