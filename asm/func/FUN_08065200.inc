	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x69
	bl prepare_08231510
	cmp r0, #0
	beq _08065212
	bl Script_GetValue
_08065212:
	str r0, [r4, #0x18]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
