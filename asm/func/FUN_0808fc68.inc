	push {lr}
	movs r0, #0x73
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0808FC84
	bl VM_GetValue
	ldr r1, _0808FC88 @ =0x030046A0
	ldr r1, [r1]
	movs r2, #0x95
	lsls r2, r2, #2
	adds r1, r1, r2
	strh r0, [r1]
_0808FC84:
	pop {r0}
	bx r0
	.align 2, 0
_0808FC88: .4byte 0x030046A0
