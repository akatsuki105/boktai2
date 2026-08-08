	ldr r0, _0824176C @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _08241770 @ =0x00000942
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_0824176C: .4byte 0x030046A0
_08241770: .4byte 0x00000942
