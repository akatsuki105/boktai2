	push {lr}
	movs r2, #0xaa
	lsls r2, r2, #1
	adds r1, r0, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _081F0304
	movs r1, #0
	bl VM_ExecByID
_081F0304:
	pop {r0}
	bx r0
