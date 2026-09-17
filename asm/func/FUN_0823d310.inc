	push {lr}
	ldr r1, _0823D334 @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0x95
	lsls r1, r1, #4
	adds r2, r0, r1
	ldrh r3, [r2]
	movs r0, #0
	ldrsh r1, [r2, r0]
	ldr r0, _0823D338 @ =0x0000270E
	cmp r1, r0
	bgt _0823D330
	adds r0, r3, #1
	strh r0, [r2]
_0823D330:
	pop {r0}
	bx r0
	.align 2, 0
_0823D334: .4byte 0x030046A0
_0823D338: .4byte 0x0000270E
