	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08041190 @ =0x03002B50
	ldr r1, [r0]
	cmp r1, #0
	beq _08041194
	ldrb r0, [r4]
	cmp r0, #0
	beq _08041194
	adds r0, r1, #0
	adds r1, r4, #0
	bl FUN_08040e68
	adds r0, r4, #0
	bl Entity286FNode_RemoveMover
	adds r0, r4, #0
	adds r0, #0x5c
	bl Mover_Unlink
	adds r0, r4, #0
	adds r0, #0xd0
	bl FUN_08055d7c
	adds r0, r4, #0
	bl Entity286FNode_RemoveShadow
	movs r0, #0
	strb r0, [r4]
	adds r0, r4, #0
	bl Free
	movs r0, #0
	b _08041198
	.align 2, 0
_08041190: .4byte 0x03002B50
_08041194:
	movs r0, #1
	rsbs r0, r0, #0
_08041198:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
