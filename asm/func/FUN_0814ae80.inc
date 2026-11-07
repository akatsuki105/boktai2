	push {lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r2, [r0]
	movs r0, #0xd9
	lsls r0, r0, #3
	adds r1, r2, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _0814AE9A
	subs r0, #1
	strh r0, [r1]
_0814AE9A:
	ldr r0, _0814AEAC @ =0x000006CA
	adds r1, r2, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _0814AEA8
	subs r0, #1
	strh r0, [r1]
_0814AEA8:
	pop {r0}
	bx r0
	.align 2, 0
_0814AEAC: .4byte 0x000006CA
