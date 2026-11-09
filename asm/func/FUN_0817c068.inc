	push {lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r2, _0817C090 @ =0x0000087C
	adds r1, r0, r2
	movs r2, #5
_0817C078:
	ldrh r0, [r1]
	cmp r0, #0
	beq _0817C082
	subs r0, #1
	strh r0, [r1]
_0817C082:
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bge _0817C078
	pop {r0}
	bx r0
	.align 2, 0
_0817C090: .4byte 0x0000087C
