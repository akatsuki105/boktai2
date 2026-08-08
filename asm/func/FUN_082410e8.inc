	push {r4, lr}
	movs r0, #0x28
	bl FUN_08243648
	adds r2, r0, #0
	ldr r4, _08241104 @ =gUnkPtr_030047a8
	ldr r1, [r4]
	movs r0, #0
	bl FUN_082439f0
	cmp r0, #0
	blt _08241108
	movs r0, #1
	b _08241112
	.align 2, 0
_08241104: .4byte gUnkPtr_030047a8
_08241108:
	ldr r0, [r4]
	movs r1, #0x28
	bl ClearMemory
	movs r0, #0
_08241112:
	pop {r4}
	pop {r1}
	bx r1
