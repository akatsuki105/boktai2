	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x38
	adds r0, #0x1c
	ldr r1, _0801AD28 @ =0x00002E7B
	bl Video_GetAuxSprite
	movs r4, #0
_0801AD0E:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl Entity78C9Elem_Init
	adds r4, #1
	adds r5, #0x34
	cmp r4, #0x1f
	ble _0801AD0E
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0801AD28: .4byte 0x00002E7B
