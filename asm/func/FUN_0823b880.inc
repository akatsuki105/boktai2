	push {lr}
	adds r2, r0, #0
	ldr r0, _0823B898 @ =gCamera
	ldr r0, [r0]
	cmp r0, #0
	beq _0823B8A8
	cmp r2, #1
	bgt _0823B89C
	adds r1, r0, #0
	adds r1, #0x54
	movs r0, #0
	b _0823B8A6
	.align 2, 0
_0823B898: .4byte gCamera
_0823B89C:
	adds r1, r0, #0
	adds r1, #0x56
	strh r2, [r1]
	subs r1, #2
	movs r0, #3
_0823B8A6:
	strh r0, [r1]
_0823B8A8:
	pop {r0}
	bx r0
