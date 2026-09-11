	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x44
	bl FUN_0822a4e0
	ldr r0, _0800E590 @ =0x03002B3C
	ldr r0, [r0]
	cmp r0, #0
	beq _0800E564
	adds r1, r4, #0
	bl FUN_0800e504
_0800E564:
	adds r0, r4, #0
	bl FUN_0800e530
	ldr r0, [r4, #0x20]
	cmp r0, #0
	beq _0800E57A
	bl FUN_08236424
	ldr r0, [r4, #0x20]
	bl Free
_0800E57A:
	ldr r0, [r4, #0x24]
	cmp r0, #0
	beq _0800E584
	bl Free
_0800E584:
	adds r0, r4, #0
	bl Free
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0800E590: .4byte 0x03002B3C
