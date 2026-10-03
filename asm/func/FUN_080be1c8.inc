	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080BE1F0 @ =0x000092B3
	ldr r1, _080BE1F4 @ =0x0000A41A
	bl GetFile
	ldr r1, _080BE1F8 @ =0x0000163C
	adds r4, r4, r1
	movs r1, #0xda
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [r4]
	ldr r1, _080BE1FC @ =0x030043F0
	ldr r2, _080BE200 @ =0x04000018
	bl CpuSet
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BE1F0: .4byte 0x000092B3
_080BE1F4: .4byte 0x0000A41A
_080BE1F8: .4byte 0x0000163C
_080BE1FC: .4byte 0x030043F0
_080BE200: .4byte 0x04000018
