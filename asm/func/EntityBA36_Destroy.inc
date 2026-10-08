	push {lr}
	movs r0, #0x49
	bl CheckItemOwn
	cmp r0, #0
	beq _080A10FE
	movs r0, #0x49
	bl RemoveSpecifiedItem
_080A10FE:
	ldr r1, _080A1108 @ =0x03002C40
	movs r0, #0
	str r0, [r1]
	pop {r1}
	bx r1
	.align 2, 0
_080A1108: .4byte 0x03002C40
