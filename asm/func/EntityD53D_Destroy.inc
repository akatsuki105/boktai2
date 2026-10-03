	push {lr}
	ldr r0, [r0, #0x20]
	bl TextPanel_Destroy
	ldr r1, _0804ED2C @ =0x030000E8
	movs r0, #0
	str r0, [r1]
	pop {r1}
	bx r1
	.align 2, 0
_0804ED2C: .4byte 0x030000E8
