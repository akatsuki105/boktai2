	push {lr}
	adds r1, r0, #0
	ldr r0, _0804E574 @ =0x03002B58
	ldr r0, [r0]
	cmp r0, #0
	beq _0804E57C
	adds r0, #0xc4
	ldr r2, _0804E578 @ =0x04000003
	bl CpuSet
	movs r0, #0
	b _0804E580
	.align 2, 0
_0804E574: .4byte 0x03002B58
_0804E578: .4byte 0x04000003
_0804E57C:
	movs r0, #1
	rsbs r0, r0, #0
_0804E580:
	pop {r1}
	bx r1
