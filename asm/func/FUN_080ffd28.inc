	push {lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	movs r2, #0xce
	lsls r2, r2, #3
	adds r1, r0, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _080FFD42
	subs r0, #1
	strh r0, [r1]
_080FFD42:
	pop {r0}
	bx r0
	.align 2, 0
