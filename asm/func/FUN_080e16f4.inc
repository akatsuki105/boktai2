	push {r4, lr}
	ldr r0, _080E1738 @ =0x03000180
	ldr r4, [r0]
	cmp r4, #0
	beq _080E1732
	movs r1, #1
	rsbs r1, r1, #0
	movs r0, #0x6e
	bl VM_GetKeywordValue
	cmp r0, #0
	blt _080E1732
	bl FUN_080e1334
	adds r3, r0, #0
	cmp r3, #0
	beq _080E1732
	movs r1, #0x1a
	ldrsh r0, [r3, r1]
	movs r1, #0xcc
	lsls r1, r1, #1
	adds r2, r4, r1
	movs r1, #1
	lsls r1, r0
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
	adds r0, r3, #0
	movs r1, #0x20
	bl ClearMemory
_080E1732:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080E1738: .4byte 0x03000180
