	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _081F4548 @ =0x0000922E
	ldr r1, _081F454C @ =0x00001DC3
	bl GetFile
	str r0, [r4, #0x18]
	movs r0, #0
	str r0, [r4, #0x1c]
	ldr r0, _081F4550 @ =0x030001F4
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081F4548: .4byte 0x0000922E
_081F454C: .4byte 0x00001DC3
_081F4550: .4byte 0x030001F4
