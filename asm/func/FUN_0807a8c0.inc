	push {lr}
	ldr r1, _0807A8DC @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #1
	adds r0, r0, r1
	adds r0, #0x46
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0x64
	bl Div
	pop {r1}
	bx r1
	.align 2, 0
_0807A8DC: .4byte 0x030046A0
