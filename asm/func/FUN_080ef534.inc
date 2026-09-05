	push {r4, lr}
	ldr r0, _080EF558 @ =0x03002C5C
	ldr r4, [r0]
	cmp r4, #0
	beq _080EF550
	movs r0, #0x73
	movs r1, #0
	bl VM_GetKeywordValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [r4, #0x2c]
	orrs r1, r0
	str r1, [r4, #0x2c]
_080EF550:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080EF558: .4byte 0x03002C5C
