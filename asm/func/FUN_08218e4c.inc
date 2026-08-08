	push {lr}
	adds r2, r0, #0
	ldr r0, _08218E68 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _08218E6C @ =0x0000093A
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq _08218E74
	ldr r0, _08218E70 @ =0x0000165C
	adds r1, r2, r0
	movs r0, #0
	b _08218E7A
	.align 2, 0
_08218E68: .4byte 0x030046A0
_08218E6C: .4byte 0x0000093A
_08218E70: .4byte 0x0000165C
_08218E74:
	ldr r0, _08218E88 @ =0x0000165C
	adds r1, r2, r0
	movs r0, #1
_08218E7A:
	strh r0, [r1]
	ldr r0, _08218E8C @ =0x0000165E
	adds r1, r2, r0
	movs r0, #0
	strh r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08218E88: .4byte 0x0000165C
_08218E8C: .4byte 0x0000165E
