	push {r4, r5, r6, lr}
	adds r3, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	ldr r6, _0823BC4C @ =gCamera
	ldr r0, [r6]
	cmp r0, #0
	beq _0823BC66
	adds r0, #0x7c
	strh r3, [r0]
	ldrh r0, [r0]
	bl FUN_0823b2d0
	cmp r0, #0
	beq _0823BC66
	ldr r2, [r6]
	movs r0, #1
	strh r0, [r2, #0x1c]
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r2, #0x74]
	str r1, [r2, #0x78]
	cmp r4, #1
	bgt _0823BC50
	adds r1, r2, #0
	adds r1, #0x68
	movs r0, #3
	b _0823BC5C
	.align 2, 0
_0823BC4C: .4byte gCamera
_0823BC50:
	adds r0, r2, #0
	adds r0, #0x6a
	strh r4, [r0]
	adds r1, r2, #0
	adds r1, #0x68
	movs r0, #4
_0823BC5C:
	strh r0, [r1]
	ldr r0, _0823BC6C @ =gCamera
	ldr r1, [r0]
	movs r0, #0
	strh r0, [r1, #0x1e]
_0823BC66:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0823BC6C: .4byte gCamera
