	push {lr}
	ldr r0, _08049F74 @ =0x030000C8
	ldr r0, [r0]
	cmp r0, #0
	beq _08049F7C
	ldr r2, _08049F78 @ =0x00000179
	adds r1, r0, r2
	movs r0, #1
	strb r0, [r1]
	movs r0, #0
	b _08049F80
	.align 2, 0
_08049F74: .4byte 0x030000C8
_08049F78: .4byte 0x00000179
_08049F7C:
	movs r0, #1
	rsbs r0, r0, #0
_08049F80:
	pop {r1}
	bx r1
