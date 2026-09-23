	push {lr}
	ldr r0, _08049F9C @ =0x030000C8
	ldr r0, [r0]
	cmp r0, #0
	beq _08049FA0
	movs r2, #0xbd
	lsls r2, r2, #1
	adds r1, r0, r2
	movs r0, #1
	strb r0, [r1]
	movs r0, #0
	b _08049FA4
	.align 2, 0
_08049F9C: .4byte 0x030000C8
_08049FA0:
	movs r0, #1
	rsbs r0, r0, #0
_08049FA4:
	pop {r1}
	bx r1
