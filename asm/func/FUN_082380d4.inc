	push {lr}
	ldr r0, _082380E4 @ =0x030046D0
	ldrh r1, [r0]
	ldr r0, _082380E8 @ =0x0000FFFF
	cmp r1, r0
	bne _082380EC
	movs r0, #0
	b _082380EE
	.align 2, 0
_082380E4: .4byte 0x030046D0
_082380E8: .4byte 0x0000FFFF
_082380EC:
	movs r0, #1
_082380EE:
	pop {r1}
	bx r1
	.align 2, 0
