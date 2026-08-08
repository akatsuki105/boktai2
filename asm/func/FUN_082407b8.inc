	push {r4, r5, lr}
	ldr r4, _082407DC @ =0x03004820
	movs r5, #0x1f
_082407BE:
	ldrh r0, [r4]
	cmp r0, #0
	beq _082407CC
	bl m4aSongNumStop
	movs r0, #0
	strh r0, [r4]
_082407CC:
	adds r4, #2
	subs r5, #1
	cmp r5, #0
	bge _082407BE
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_082407DC: .4byte 0x03004820
