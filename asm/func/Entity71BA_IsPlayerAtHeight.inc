	push {lr}
	ldr r1, _080A00F8 @ =0x03002BE0
	ldr r1, [r1]
	movs r2, #0x2e
	ldrsh r1, [r1, r2]
	ldrh r0, [r0, #0x20]
	lsls r0, r0, #8
	cmp r1, r0
	beq _080A00FC
	movs r0, #0
	b _080A00FE
	.align 2, 0
_080A00F8: .4byte 0x03002BE0
_080A00FC:
	movs r0, #1
_080A00FE:
	pop {r1}
	bx r1
	.align 2, 0
