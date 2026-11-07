	push {lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r2, _0814AECC @ =0x000006C6
	adds r1, r0, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _0814AEC8
	subs r0, #1
	strh r0, [r1]
_0814AEC8:
	pop {r0}
	bx r0
	.align 2, 0
_0814AECC: .4byte 0x000006C6
