	push {r4, lr}
	adds r4, r0, #0
	movs r0, #8
	bl FUN_0823bca8
	ldr r0, _08066D28 @ =0x000003CE
	adds r4, r4, r0
	movs r0, #0
	strh r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08066D28: .4byte 0x000003CE
