	push {lr}
	movs r0, #0x69
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0808FD24
	bl VM_GetValue
	ldr r1, _0808FD28 @ =0x030046A0
	ldr r2, [r1]
	movs r1, #0x98
	lsls r1, r1, #2
	adds r2, r2, r1
	movs r1, #1
	lsls r1, r0
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_0808FD24:
	pop {r0}
	bx r0
	.align 2, 0
_0808FD28: .4byte 0x030046A0
