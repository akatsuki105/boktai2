	push {lr}
	ldr r0, _080A1068 @ =0x03002C40
	ldr r0, [r0]
	cmp r0, #0
	beq _080A106C
	ldrh r0, [r0, #0x18]
	b _080A106E
	.align 2, 0
_080A1068: .4byte 0x03002C40
_080A106C:
	movs r0, #0
_080A106E:
	pop {r1}
	bx r1
	.align 2, 0
