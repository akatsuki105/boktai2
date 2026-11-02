	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r0, #0x18
	ldr r1, _08052FF8 @ =0x000018A8
	bl Video_GetAuxSprite
	adds r5, r6, #0
	adds r5, #0x34
	movs r4, #0
_08052FDE:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl Entity08052ffcElem_Init
	adds r4, #1
	adds r5, #0x40
	cmp r4, #3
	ble _08052FDE
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08052FF8: .4byte 0x000018A8
