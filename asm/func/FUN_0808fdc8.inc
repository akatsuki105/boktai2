	push {r4, lr}
	movs r0, #0x73
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0808FDDC
	bl VM_GetValue
	adds r4, r0, #0
	b _0808FDEA
_0808FDDC:
	ldr r0, _0808FE18 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x95
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #0
	ldrsh r4, [r0, r1]
_0808FDEA:
	movs r0, #0x69
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0808FE10
	bl VM_GetValue
	ldr r1, _0808FE18 @ =0x030046A0
	ldr r1, [r1]
	lsls r2, r4, #2
	adds r2, r2, r1
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r2, r2, r1
	movs r1, #1
	lsls r1, r0
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_0808FE10:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808FE18: .4byte 0x030046A0
