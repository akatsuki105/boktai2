	push {r4, lr}
	bl Entity8AF6_FindEntry
	adds r4, r0, #0
	cmp r4, #0
	beq _080A5A10
	movs r0, #0x66
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A5A10
	bl VM_GetValue
	cmp r0, #0
	beq _080A5A06
	ldr r0, [r4, #0x40]
	movs r1, #4
	orrs r0, r1
	b _080A5A0E
_080A5A06:
	ldr r0, [r4, #0x40]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080A5A0E:
	str r0, [r4, #0x40]
_080A5A10:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
