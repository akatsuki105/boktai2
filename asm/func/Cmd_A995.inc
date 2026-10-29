	push {lr}
	movs r0, #0x73
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0808FDA0
	bl VM_GetValue
	adds r2, r0, #0
	b _0808FDAE
_0808FDA0:
	ldr r0, _0808FDC4 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x95
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #0
	ldrsh r2, [r0, r1]
_0808FDAE:
	ldr r0, _0808FDC4 @ =0x030046A0
	ldr r1, [r0]
	lsls r0, r2, #2
	adds r0, r0, r1
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #0
	str r1, [r0]
	pop {r0}
	bx r0
	.align 2, 0
_0808FDC4: .4byte 0x030046A0
