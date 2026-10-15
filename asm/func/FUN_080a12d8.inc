	push {r4, lr}
	ldr r0, _080A12FC @ =0x03000148
	ldr r0, [r0]
	cmp r0, #0
	beq _080A12F4
	movs r0, #0x48
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A12F4
	ldr r4, _080A1300 @ =0x03002B84
	bl VM_GetValue
	strh r0, [r4]
_080A12F4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A12FC: .4byte 0x03000148
_080A1300: .4byte 0x03002B84
