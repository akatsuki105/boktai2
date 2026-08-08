	push {lr}
	ldr r1, _0823A9EC @ =0x030044AC
	movs r0, #0
	str r0, [r1]
	bl vram_0822b778
	bl FUN_0823cd04
	bl FUN_082326d8
	bl FUN_08236ed0
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r2, _0823A9F0 @ =0x03003E78
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	pop {r0}
	bx r0
	.align 2, 0
_0823A9EC: .4byte 0x030044AC
_0823A9F0: .4byte 0x03003E78
