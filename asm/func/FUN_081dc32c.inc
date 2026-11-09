	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0xf6
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _081DC348
	movs r1, #0
	bl VM_ExecByID
	adds r0, r4, #0
	bl KillEntity
_081DC348:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
