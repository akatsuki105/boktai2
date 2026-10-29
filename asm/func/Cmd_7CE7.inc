	push {lr}
	movs r0, #0x73
	bl VM_SeekToNamedArg
	cmp r0, #0
	bne _0808FD70
	ldr r0, _0808FD6C @ =0x030046A0
	ldr r1, [r0]
	movs r2, #0x95
	lsls r2, r2, #2
	adds r0, r1, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r0, r1
	b _0808FD82
	.align 2, 0
_0808FD6C: .4byte 0x030046A0
_0808FD70:
	bl VM_GetValue
	ldr r1, _0808FD88 @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r2, #0x9a
	lsls r2, r2, #2
	adds r0, r0, r2
_0808FD82:
	ldr r0, [r0]
	pop {r1}
	bx r1
	.align 2, 0
_0808FD88: .4byte 0x030046A0
