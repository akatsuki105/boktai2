	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
_0823CDC6:
	cmp r2, r3
	bge _0823CDE0
	adds r0, r2, r3
	asrs r1, r0, #1
	lsls r0, r1, #2
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, r5
	bhs _0823CDDC
	adds r2, r1, #1
	b _0823CDC6
_0823CDDC:
	adds r3, r1, #0
	b _0823CDC6
_0823CDE0:
	lsls r0, r2, #2
	adds r1, r0, r4
	ldrh r0, [r1]
	cmp r0, r5
	beq _0823CDEE
	movs r0, #0
	b _0823CDF0
_0823CDEE:
	ldrh r0, [r1, #2]
_0823CDF0:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
