	push {lr}
	ldr r0, _082477A0 @ =0x030026C4
	ldr r0, [r0]
	cmp r0, #0
	bne _08247782
	bl FUN_08247738
_08247782:
	ldr r1, _082477A4 @ =0x030057B8
	movs r0, #1
	str r0, [r1]
	ldr r0, _082477A8 @ =0x030026B4
	movs r1, #0
	str r1, [r0]
	ldr r0, _082477AC @ =0x030026B8
	str r1, [r0]
	ldr r1, _082477B0 @ =0x030057C8
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_082477A0: .4byte 0x030026C4
_082477A4: .4byte 0x030057B8
_082477A8: .4byte 0x030026B4
_082477AC: .4byte 0x030026B8
_082477B0: .4byte 0x030057C8
