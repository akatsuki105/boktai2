	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x82
	movs r0, #0
	ldrsh r6, [r4, r0]
	cmp r6, #0
	beq _08020D2E
	adds r0, r6, #0
	bl FUN_0823b9cc
	ldrh r0, [r4]
	subs r0, #1
	strh r0, [r4]
	b _08020D3C
_08020D2E:
	ldr r0, [r5, #0x64]
	cmp r0, #0
	beq _08020D3C
	movs r1, #0
	bl Script_ExecById
	str r6, [r5, #0x64]
_08020D3C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
