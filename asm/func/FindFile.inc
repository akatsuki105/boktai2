	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r1, [sp, #0xc]
_08231008:
	cmp r3, r1
	bge _08231022
	adds r0, r3, r1
	asrs r2, r0, #1
	lsls r0, r2, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, r5
	bhs _0823101E
	adds r3, r2, #1
	b _08231008
_0823101E:
	adds r1, r2, #0
	b _08231008
_08231022:
	lsls r0, r3, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, r5
	beq _08231032
	movs r0, #1
	rsbs r0, r0, #0
	b _08231034
_08231032:
	adds r0, r3, #0
_08231034:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
