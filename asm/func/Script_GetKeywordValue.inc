	push {r4, lr}
	adds r4, r1, #0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl prepare_08231510
	cmp r0, #0
	bne _08231760
	adds r0, r4, #0
	b _08231768
_08231760:
	bl VM_GetPC
	bl VM_GetValueAt
_08231768:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
