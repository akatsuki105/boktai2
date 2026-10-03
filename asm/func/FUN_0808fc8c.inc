	push {lr}
	movs r0, #0x66
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0808FCA6
	bl VM_GetValue
	ldr r1, _0808FCAC @ =0x030046A0
	ldr r1, [r1]
	ldr r2, _0808FCB0 @ =0x00000256
	adds r1, r1, r2
	strh r0, [r1]
_0808FCA6:
	pop {r0}
	bx r0
	.align 2, 0
_0808FCAC: .4byte 0x030046A0
_0808FCB0: .4byte 0x00000256
