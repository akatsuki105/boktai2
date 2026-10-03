	push {lr}
	ldr r0, _0804E380 @ =0x03002B58
	ldr r0, [r0]
	cmp r0, #0
	beq _0804E37A
	bl FUN_0804e164
_0804E37A:
	pop {r0}
	bx r0
	.align 2, 0
_0804E380: .4byte 0x03002B58
