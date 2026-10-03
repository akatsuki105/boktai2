	push {lr}
	ldr r0, _0809C5F0 @ =0x0300013C
	ldr r0, [r0]
	cmp r0, #0
	beq _0809C5EC
	movs r1, #2
	bl FUN_0808abec
_0809C5EC:
	pop {r0}
	bx r0
	.align 2, 0
_0809C5F0: .4byte 0x0300013C
