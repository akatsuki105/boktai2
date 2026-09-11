	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080B447C @ =0x000092B3
	ldr r1, _080B4480 @ =0x0000EAA8
	bl GetFile
	ldr r1, _080B4484 @ =0x000005CC
	adds r4, r4, r1
	movs r1, #0xda
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [r4]
	ldr r1, _080B4488 @ =0x030043F0
	ldr r2, _080B448C @ =0x04000018
	bl CpuSet
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B447C: .4byte 0x000092B3
_080B4480: .4byte 0x0000EAA8
_080B4484: .4byte 0x000005CC
_080B4488: .4byte 0x030043F0
_080B448C: .4byte 0x04000018
