	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080BC484 @ =0x000092B3
	ldr r1, _080BC488 @ =0x0000A41A
	bl GetFile
	ldr r1, _080BC48C @ =0x000012DC
	adds r4, r4, r1
	movs r1, #0xda
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [r4]
	ldr r1, _080BC490 @ =0x030043F0
	ldr r2, _080BC494 @ =0x04000018
	bl CpuSet
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BC484: .4byte 0x000092B3
_080BC488: .4byte 0x0000A41A
_080BC48C: .4byte 0x000012DC
_080BC490: .4byte 0x030043F0
_080BC494: .4byte 0x04000018
