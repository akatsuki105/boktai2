	push {r4, r5, lr}
	adds r2, r0, #0
	adds r4, r1, #0
	ldr r5, _0823BC10 @ =gCamera
	ldr r0, [r5]
	cmp r0, #0
	beq _0823BC0A
	adds r0, #0x7c
	strh r2, [r0]
	ldrh r0, [r0]
	bl FUN_0823b2d0
	cmp r0, #0
	beq _0823BC0A
	ldr r2, [r5]
	movs r0, #1
	strh r0, [r2, #0x1c]
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r2, #0x74]
	str r1, [r2, #0x78]
	adds r1, r2, #0
	adds r1, #0x68
	movs r0, #3
	strh r0, [r1]
	movs r0, #0
	strh r0, [r2, #0x1e]
_0823BC0A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0823BC10: .4byte gCamera
