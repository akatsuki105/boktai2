	push {r4, lr}
	bl Entity8AF6_FindEntry
	adds r4, r0, #0
	cmp r4, #0
	beq _080A5A8C
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A5A8C
	bl VM_GetValue
	adds r1, r4, #0
	adds r1, #0x52
	strb r0, [r1]
_080A5A8C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
