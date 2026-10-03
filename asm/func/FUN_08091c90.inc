	push {lr}
	ldr r0, _08091CB4 @ =0x030046A0
	ldr r1, [r0]
	adds r0, r1, #0
	adds r0, #0x58
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	adds r0, #0x60
	movs r1, #0
	ldrsh r0, [r0, r1]
	bl GetWeapon
	movs r1, #0
	strh r1, [r0, #2]
	pop {r0}
	bx r0
	.align 2, 0
_08091CB4: .4byte 0x030046A0
