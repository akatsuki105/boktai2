	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0807A6F4 @ =0x030046A0
	ldr r0, [r0]
	adds r1, r0, #0
	adds r1, #0x5c
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	blt _0807A6FC
	bl GetInventoryArmor
	adds r1, r0, #0
	lsls r1, r1, #3
	ldr r0, _0807A6F8 @ =0x08DAA7B0
	adds r1, r1, r0
	adds r0, r4, #0
	bl FUN_0807a5d8
	b _0807A704
	.align 2, 0
_0807A6F4: .4byte 0x030046A0
_0807A6F8: .4byte 0x08DAA7B0
_0807A6FC:
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0807a5d8
_0807A704:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
