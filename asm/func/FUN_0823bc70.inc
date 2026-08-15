	push {lr}
	adds r2, r0, #0
	ldr r0, _0823BC8C @ =gCamera
	ldr r1, [r0]
	adds r3, r0, #0
	cmp r1, #0
	beq _0823BCA2
	movs r0, #1
	strh r0, [r1, #0x1c]
	cmp r2, #1
	bgt _0823BC90
	adds r1, #0x68
	movs r0, #0
	b _0823BC9A
	.align 2, 0
_0823BC8C: .4byte gCamera
_0823BC90:
	adds r0, r1, #0
	adds r0, #0x6a
	strh r2, [r0]
	adds r1, #0x68
	movs r0, #5
_0823BC9A:
	strh r0, [r1]
	ldr r1, [r3]
	movs r0, #0
	strh r0, [r1, #0x1e]
_0823BCA2:
	pop {r0}
	bx r0
	.align 2, 0
