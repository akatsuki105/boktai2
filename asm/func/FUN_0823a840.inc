	push {lr}
	adds r3, r1, #0
	ldr r1, _0823A864 @ =0x08DBD564
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _0823A868
	lsls r0, r3, #2
	adds r0, r0, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _0823A868
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	b _0823A86A
	.align 2, 0
_0823A864: .4byte 0x08DBD564
_0823A868:
	movs r0, #0
_0823A86A:
	pop {r1}
	bx r1
	.align 2, 0
