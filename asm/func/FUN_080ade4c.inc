	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _080ADE78 @ =0x000092B3
	ldr r1, _080ADE7C @ =0x0000313A
	bl GetFile
	adds r4, r0, #0
	adds r4, #0x14
	adds r0, r5, #0
	bl FUN_080adde4
	lsls r0, r0, #5
	adds r4, r4, r0
	ldr r1, _080ADE80 @ =0x03004250
	ldr r2, _080ADE84 @ =0x04000010
	adds r0, r4, #0
	bl CpuSet
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080ADE78: .4byte 0x000092B3
_080ADE7C: .4byte 0x0000313A
_080ADE80: .4byte 0x03004250
_080ADE84: .4byte 0x04000010
