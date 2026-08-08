	push {lr}
	ldr r0, _08238DA4 @ =0x030046D4
	ldr r1, [r0]
	cmp r1, #0
	bge _08238D96
	movs r0, #3
	rsbs r0, r0, #0
	cmp r1, r0
	bgt _08238D9E
_08238D96:
	cmp r1, #0
	bne _08238D9E
	bl FUN_08238624
_08238D9E:
	pop {r0}
	bx r0
	.align 2, 0
_08238DA4: .4byte 0x030046D4
