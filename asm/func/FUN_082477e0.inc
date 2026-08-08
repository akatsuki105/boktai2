	push {lr}
	ldr r0, _082477F0 @ =0x030057B8
	ldr r0, [r0]
	cmp r0, #0
	beq _082477F8
	ldr r0, _082477F4 @ =0x030057C8
	ldr r0, [r0]
	b _082477FC
	.align 2, 0
_082477F0: .4byte 0x030057B8
_082477F4: .4byte 0x030057C8
_082477F8:
	movs r0, #1
	rsbs r0, r0, #0
_082477FC:
	pop {r1}
	bx r1
  .align 2, 0
