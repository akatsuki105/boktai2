	push {r4, lr}
	sub sp, #0x10
	adds r4, r0, #0
	str r1, [sp, #0xc]
	ldr r0, _0804EE1C @ =0x0000C091
	ldr r1, _0804EE20 @ =0x0000CD91
	bl GetFile
	adds r2, r0, #0
	str r2, [r4, #0x24]
	movs r4, #0
	str r4, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #1
	movs r1, #0
	movs r3, #0
	bl FUN_0822c0b8
	str r4, [sp]
	movs r0, #2
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r0, _0804EE24 @ =0x000092B3
	ldr r1, _0804EE28 @ =0x000026BB
	bl GetFile
	adds r0, #0x14
	ldr r1, _0804EE2C @ =0x03004250
	movs r2, #0x80
	lsls r2, r2, #1
	bl CpuSet
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804EE1C: .4byte 0x0000C091
_0804EE20: .4byte 0x0000CD91
_0804EE24: .4byte 0x000092B3
_0804EE28: .4byte 0x000026BB
_0804EE2C: .4byte 0x03004250
