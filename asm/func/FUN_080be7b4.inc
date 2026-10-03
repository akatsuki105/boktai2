	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x65
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080BE7D4
	bl VM_GetValue
	ldr r2, _080BE7D0 @ =0x00001894
	adds r1, r4, r2
	str r0, [r1]
	b _080BE7DA
	.align 2, 0
_080BE7D0: .4byte 0x00001894
_080BE7D4:
	ldr r2, _080BE7E0 @ =0x00001894
	adds r0, r4, r2
	str r1, [r0]
_080BE7DA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BE7E0: .4byte 0x00001894
