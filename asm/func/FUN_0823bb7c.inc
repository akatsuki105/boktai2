	push {r4, r5, lr}
	adds r4, r0, #0
	adds r3, r1, #0
	ldr r0, _0823BBB4 @ =gCamera
	ldr r2, [r0]
	adds r5, r0, #0
	cmp r2, #0
	beq _0823BBCC
	ldrh r1, [r3]
	adds r0, r2, #0
	adds r0, #0x6c
	strh r1, [r0]
	ldrh r0, [r3, #2]
	adds r1, r2, #0
	adds r1, #0x6e
	strh r0, [r1]
	ldrh r1, [r3, #4]
	adds r0, r2, #0
	adds r0, #0x70
	strh r1, [r0]
	movs r1, #1
	strh r1, [r2, #0x1c]
	cmp r4, #1
	bgt _0823BBB8
	subs r0, #8
	strh r1, [r0]
	b _0823BBC6
	.align 2, 0
_0823BBB4: .4byte gCamera
_0823BBB8:
	adds r0, r2, #0
	adds r0, #0x6a
	strh r4, [r0]
	adds r1, r2, #0
	adds r1, #0x68
	movs r0, #2
	strh r0, [r1]
_0823BBC6:
	ldr r1, [r5]
	movs r0, #0
	strh r0, [r1, #0x1e]
_0823BBCC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
