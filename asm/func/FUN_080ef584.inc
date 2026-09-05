	push {r4, lr}
	ldr r0, _080EF5A4 @ =0x03002C5C
	ldr r4, [r0]
	cmp r4, #0
	beq _080EF59C
	movs r0, #0x6c
	movs r1, #3
	bl VM_GetKeywordValue
	adds r1, r4, #0
	adds r1, #0x30
	strb r0, [r1]
_080EF59C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080EF5A4: .4byte 0x03002C5C
