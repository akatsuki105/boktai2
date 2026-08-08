	push {r4, r5, lr}
	adds r4, r2, #0
	adds r5, r3, #0
	ldrh r3, [r1]
	ldrh r2, [r0, #8]
	subs r3, r3, r2
	ldrh r1, [r1, #4]
	ldrh r0, [r0, #0xc]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x10
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #0
	bge _080E5EB4
	rsbs r3, r3, #0
_080E5EB4:
	cmp r3, r4
	bhi _080E5ECA
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge _080E5EC2
	rsbs r0, r0, #0
_080E5EC2:
	cmp r0, r5
	bhi _080E5ECA
	movs r0, #1
	b _080E5ECC
_080E5ECA:
	movs r0, #0
_080E5ECC:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
