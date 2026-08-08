	push {lr}
	ldr r1, _08223994 @ =0x00000F26
	adds r0, r0, r1
	ldrb r0, [r0]
	bl FUN_080a6e88
	pop {r0}
	bx r0
	.align 2, 0
_08223994: .4byte 0x00000F26
