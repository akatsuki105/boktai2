	push {lr}
	adds r2, r0, #0
	ldr r0, _08048890 @ =0x030000C4
	ldr r1, [r0]
	cmp r1, #0
	beq _08048894
	ldrb r0, [r1, #0x1a]
	str r0, [r2]
	ldrb r0, [r1, #0x1b]
	str r0, [r2, #4]
	ldrb r0, [r1, #0x1c]
	str r0, [r2, #8]
	ldrb r0, [r1, #0x1d]
	str r0, [r2, #0xc]
	movs r0, #0
	b _08048898
	.align 2, 0
_08048890: .4byte 0x030000C4
_08048894:
	movs r0, #1
	rsbs r0, r0, #0
_08048898:
	pop {r1}
	bx r1
