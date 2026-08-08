	push {lr}
	ldr r0, _08237F64 @ =0x030046CC
	ldr r0, [r0]
	cmp r0, #0
	bne _08237F68
	bl FUN_08237a5c
	b _08237F6C
	.align 2, 0
_08237F64: .4byte 0x030046CC
_08237F68:
	bl FUN_08237c34
_08237F6C:
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
