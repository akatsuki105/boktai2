	push {lr}
	ldr r0, _08049FBC @ =0x030000C8
	ldr r0, [r0]
	cmp r0, #0
	beq _08049FC0
	bl FUN_08049c78
	movs r0, #0
	b _08049FC4
	.align 2, 0
_08049FBC: .4byte 0x030000C8
_08049FC0:
	movs r0, #1
	rsbs r0, r0, #0
_08049FC4:
	pop {r1}
	bx r1
