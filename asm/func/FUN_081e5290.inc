	push {lr}
	ldr r2, _081E52A8 @ =0x00001628
	adds r1, r0, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _081E52A2
	movs r1, #0
	bl VM_ExecByID
_081E52A2:
	pop {r0}
	bx r0
	.align 2, 0
_081E52A8: .4byte 0x00001628
